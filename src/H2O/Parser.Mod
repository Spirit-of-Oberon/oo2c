MODULE H2O:Parser [OOC_EXTENSIONS];

IMPORT
  SYSTEM, Out,
  Object, ADT:StringBuffer, ADT:ArrayList,
  H2O:Error, H2O:Scanner, H2O:Process, H2O:Module, T := H2O:Type;

CONST
  (* 800: C keywords *)

  extern* = 800;
  typedef* = 801;
  static* = 802;
  
  float* = 810;
  double* = 811;
  
  int* = 820;
  char* = 821;
  wchar* = 823;
  
  long* = 830;
  short* = 831;
  longlong* = 832;
  unsigned* = 833;
  signed* = 834;
  
  struct* = 840;
  union* = 841;
  void* = 842;
  enum* = 843;

  cdecl* = 850;
  stdcall* = 851;
  const* = 852;
  volatile* = 853;

  defined* = 860;
  sizeof* = 861;

CONST
  varargs = 0;

TYPE
  Parser* = POINTER TO ParserDesc;
  ParserDesc* = RECORD (Scanner.InterpreterDesc)
    (*state : SET;*)
  END;

CONST
  (* Expr options *)
  resultKnown* = 0;
  testValid* = 1;

VAR
  keyWords : Scanner.KeyWord;
  process : Process.Process;
  err : Error.Error;
  token : Scanner.Token;
  options : SET;
  exprState : SET;
  parser : Parser;
  scope, types : T.Object;
  depend : ArrayList.ArrayList;

PROCEDURE BoolInt (val : BOOLEAN) : LONGINT;
BEGIN
  IF val THEN RETURN 1 ELSE RETURN 0 END
END BoolInt;

PROCEDURE FindType(name : Object.String8) : T.Type;
VAR obj : T.Object;
BEGIN
  IF T.FindObject(types, name, obj) THEN
    RETURN obj.type;
  ELSE
    RETURN NIL;
  END;
END FindType;

PROCEDURE ShowDepend(name : Object.String8; depend : ArrayList.ArrayList);
VAR b : StringBuffer.StringBuffer; i : LONGINT;
BEGIN
  b := StringBuffer.New("");
  b.Append(name);
  b.Append(" depends on [");
  FOR i := 0 TO depend.size-1 DO
    IF i # 0 THEN b.AppendLatin1Char(",") END;
    b.Append(depend.array[i](Module.Module).name);
  END;
  b.Append("]");
  Out.Str(b.ToString()); Out.Ln;
END ShowDepend;

PROCEDURE Install* (VAR scope : T.Object; tag [NO_COPY] : ARRAY OF CHAR; name : Object.String8; new : T.Type);
VAR 
  obj : T.Object;
BEGIN
  IF T.FindObject(scope, name, obj) THEN
    err.ErrorParam("$0 `$1' already defined as $2", Object.NewLatin1(tag), name, obj.type);
  ELSE
    new.Depend(depend);
    IF depend.size > 0 THEN ShowDepend(name, depend) END;
    process.in.module.AddImports(depend);
    T.Bind(scope, name, 0, new);
  END;
END Install;

PROCEDURE InstallType(name : Object.String8; new : T.Type);
BEGIN
  Install(types, "Type", name, new);
  new.module := process.in.module;
END InstallType;

PROCEDURE NewNamedType* (class : SHORTINT; name : Object.String8) : T.Type;
VAR 
  new : T.Type;
BEGIN
  new := T.NewType(class, NIL, 0, {});
  new.name := name;

  IF name # NIL THEN
    InstallType(name, new);
  END;
  RETURN new;
END NewNamedType;

PROCEDURE GetSym;
BEGIN
  process.GetToken(token, options);
  Scanner.CheckKeyWord(keyWords, token);
END GetSym;

PROCEDURE Expect(sym : INTEGER);
BEGIN
  IF token.sym = sym THEN
    GetSym
  ELSE
    err.ExpectedToken(Scanner.NewToken(sym),token)
  END;
END Expect;

PROCEDURE StartsTypeSpecifier* () : BOOLEAN;
(* Determine if the current symbol starts a type specifier. Ie. it is a
   built-in type, a type constructor or a typedef name *)
BEGIN
  CASE token.sym OF
  | const, volatile, cdecl, stdcall,
    unsigned, short, long, longlong,
    int, char, float, double, wchar,
    enum, void, struct, union:
    RETURN TRUE;
  | Scanner.ident:
    RETURN FindType(token.name) # NIL;
  ELSE
    RETURN FALSE;
  END;
END StartsTypeSpecifier;

PROCEDURE ^Declarator(VAR name : Object.String8; base : T.Type) : T.Type;
PROCEDURE ^EvalExpr (VAR result : LONGINT);

PROCEDURE StorageClass (VAR class : INTEGER);
(* StorageClass ::= [ "extern" | "static" | "typedef" ] *)
BEGIN
  CASE token.sym OF
  | extern:
    class := T.scExtern; GetSym;
  | static:
    class := T.scStatic; GetSym;
  | typedef:
    class := T.scTypedef; GetSym;
  ELSE
    class := T.scNone;
  END;
END StorageClass;

PROCEDURE TypeQualifiers (VAR qualifiers : SET);
(* TypeQualifier ::= { "const" | "volatile" | "__cdecl" | "__stdcall" } *)
BEGIN
  LOOP
    CASE token.sym OF
    | const:    GetSym; INCL(qualifiers, T.tqConst);
    | volatile: GetSym; INCL(qualifiers, T.tqVolatile);
    | stdcall:  GetSym; INCL(qualifiers, T.tqStdcall);
    | cdecl:    GetSym; INCL(qualifiers, T.tqCdecl);
    ELSE
      RETURN;
    END;
  END;
END TypeQualifiers;

PROCEDURE TypeSpecifier() : T.Type;
VAR
  sym, sign, size, type : INTEGER;
  qualifiers : SET;
  s, t : T.Type;

  PROCEDURE EnumDecl() : T.Type;
  (* element ::= ident [ "=" Expr].
     enum ::= "enum" [ ident ] [ "{" Element { "," Element } "}" ].
  *)
  VAR 
    tag : Object.String8; 
    t : T.Type; id : LONGINT;

    PROCEDURE Element;
    VAR name : Object.String8;
    BEGIN
      name := token.name;
      Expect(Scanner.ident);
      IF token.sym = Scanner.assign THEN
        GetSym;
        EvalExpr(id);
      ELSE
        INC(id);
      END;
      T.Bind(t.link, name, id, NIL);
     END Element;

  BEGIN
    GetSym;
    tag := NIL; id := -1;
    IF token.sym = Scanner.ident THEN
      tag := token.name;
      GetSym;
    END;
    IF token.sym = Scanner.lbrace THEN
      t := NewNamedType(T.tEnum, tag);
      GetSym;
      IF token.sym = Scanner.ident THEN
        Element;
        WHILE token.sym = Scanner.comma DO
          GetSym;
          Element;
        END
      END;
      Expect(Scanner.rbrace);
    ELSIF tag # NIL THEN
      t := FindType(tag);
      IF t = NIL THEN
        (* probably didn't mean to omit the declaration *)
        err.ErrorParam("Unknown enumeration `$0'", tag, NIL, NIL);
        t := NewNamedType(T.tEnum, tag);
      ELSIF t.class # T.tEnum THEN
        err.ErrorParam("Tag `$0' already defined with different type: $1", tag, t, NIL);
      END;
    ELSE
      err.UnexpectedToken(token);
      t := NewNamedType(T.tEnum, tag);
    END;
    RETURN t;
  END EnumDecl;

  PROCEDURE StructDecl(class : SHORTINT) : T.Type;
  VAR 
    t : T.Type;
    tag : Object.String8;
    id : LONGINT;

    PROCEDURE FieldList(t : T.Type);
    VAR 
      t1, t2 : T.Type; 
      name : Object.String8;
      width : LONGINT;
    BEGIN
      WHILE StartsTypeSpecifier() DO
        t1 := TypeSpecifier();
        LOOP
          name := NIL;
          t2 := Declarator(name, t1);
          T.Bind(t.link, name, id, t2);
          IF token.sym = Scanner.colon THEN
            GetSym;
            EvalExpr(width);
          END;
          IF token.sym = Scanner.comma THEN
            GetSym
          ELSE
            EXIT
          END
        END;
        Expect(Scanner.semicolon)
      END
    END FieldList;

  BEGIN
    GetSym;
    tag := NIL; id := -1;
    IF token.sym = Scanner.ident THEN
      tag := token.name;
      GetSym;
    END;
    IF token.sym = Scanner.lbrace THEN
      t := NewNamedType(class, tag);
      GetSym;
      FieldList(t);
      Expect(Scanner.rbrace);
    ELSIF tag # NIL THEN
      t := FindType(tag);
      IF t = NIL THEN
        t := NewNamedType(class, tag);
      ELSIF t.class # class THEN
        err.ErrorParam("Tag `$0' already defined with different type: $1", tag, t, NIL);
      END;
    ELSE
      err.Error("Missing tag in struct/union declaration");
      t := NewNamedType(class, tag);
    END;
    RETURN t;
  END StructDecl;

  PROCEDURE CondType(cond : BOOLEAN; true, false : T.Type) : T.Type;
  BEGIN
    IF cond THEN RETURN true ELSE RETURN false END;
  END CondType;

BEGIN
  sign := 0; size := 0; type := 0; qualifiers := {}; 
  t := NIL;
  LOOP
    sym := token.sym;
    CASE sym OF
    | const:
      INCL(qualifiers, T.tqConst); GetSym;
    | volatile:
      INCL(qualifiers, T.tqVolatile); GetSym;
    | signed, unsigned:
      sign := sym; GetSym;
    | short, longlong:
      size := sym; GetSym;
    | long:
      IF size = long THEN size := longlong ELSE size := long END;
      GetSym;
    | void, char, int, float: 
      type := sym; GetSym;
    | enum:
      type := enum; t := EnumDecl();
    | struct:
      type := struct; t := StructDecl(T.tStruct);
    | union:
      type := union; t := StructDecl(T.tUnion);
    | Scanner.ident:
      s := FindType(token.name);
      IF s # NIL THEN 
        t := s; GetSym; type := typedef;
      END;
      EXIT 
    ELSE
      EXIT;
    END; 
  END;
  IF type = 0 THEN
    type := int; t := T.intType;
  END;
  IF (size = short) & (type # int) OR 
     (size = long) & (type # int) & (type # double) OR
     (size = longlong) & (type # int) OR
     (sign # 0) & (type # int) & (type # char) THEN
    err.Error("Invalid type specification");
  END;

  CASE type OF
  | float:
    t := T.floatType;
  | double:
    t := CondType(size = long, T.longDoubleType, T.doubleType);
  | int:
    CASE size OF
    | 0:
      t := CondType(sign = unsigned, T.unsignedIntType, T.intType);
    | short:
      t := CondType(sign = unsigned, T.unsignedShortType, T.shortType);
    | long:
      t := CondType(sign = unsigned, T.unsignedLongType, T.longType);
    | longlong:
      t := CondType(sign = unsigned, T.unsignedLongLongType, T.longLongType);
    END;
  | char:
    t := CondType(sign = unsigned, T.unsignedCharType, T.charType);
  | void:
    t := T.voidType;
  ELSE
  END;
  IF qualifiers # {} THEN
    t := T.NewType(T.tQualifier, t, t.size, qualifiers);
  END;
  RETURN t;
END TypeSpecifier;

PROCEDURE Declarator(VAR name : Object.String8; base : T.Type) : T.Type;
VAR
  t : T.Type;

  PROCEDURE DeclaratorInner() : T.Type;
  VAR 
    qualifiers : SET;
    t : T.Type;
    size : LONGINT;
  
    PROCEDURE FuncDecl (func : T.Type);
    VAR
      t : T.Type; void : BOOLEAN; id : LONGINT;
      name : Object.String8;
  
      PROCEDURE CheckEnd;
      BEGIN
        IF varargs IN func.qualifiers THEN
          err.Error("Parameters declared after ellipsis");
        ELSIF void THEN
          err.Error("Parameters declared after void");
        END;
      END CheckEnd;
  
    BEGIN
      ASSERT(token.sym = Scanner.lbracket);
      void := FALSE; id := 0;
      GetSym;
      LOOP
        IF token.sym = Scanner.dotdotdot THEN
          GetSym;
          CheckEnd;
          INCL(func.qualifiers, varargs);
        ELSIF StartsTypeSpecifier() THEN
          CheckEnd;
          name := NIL;
          t := Declarator(name, TypeSpecifier());
          IF t.class = T.tVoid THEN
            IF id # 0 THEN
              err.Error("Void must occur as single declaration type");
            END;
            void := TRUE;
          ELSE
            T.Bind(func.link, name, id, t);
            INC(id);
          END;
          IF token.sym = Scanner.comma THEN 
            GetSym
          END
        ELSE
          EXIT
        END;
      END;
      Expect(Scanner.rbracket);
    END FuncDecl;
    
  BEGIN
    t := NIL;
    CASE token.sym OF
    | Scanner.ident:
      IF name = NIL THEN
        name := token.name
      ELSE
        err.ErrorParam("Identifier `$0' is extraneous. Previous identifier: `$1'", token.name, name, NIL);
      END;
      GetSym;
    | Scanner.mul:
      GetSym;
      qualifiers := {};
      TypeQualifiers(qualifiers);
      t := DeclaratorInner();
      IF qualifiers # {} THEN
        t := T.NewType(T.tQualifier, t, 0, qualifiers);
      END;
      t := T.NewType(T.tPointer, t, 0, {});
    | Scanner.lbracket:
      GetSym;
      t := DeclaratorInner();
      Expect(Scanner.rbracket);
    | Scanner.lsqbracket:
    ELSE
      RETURN t;
    END;
  
    WHILE (token.sym = Scanner.lbracket) OR (token.sym = Scanner.lsqbracket) DO
      CASE token.sym OF
      | Scanner.lbracket:
        t := T.NewType(T.tFunction, t, 0, {});
        FuncDecl(t);
      | Scanner.lsqbracket:
        GetSym;
        IF token.sym = Scanner.rsqbracket THEN
          size := -1;
        ELSE
          EvalExpr(size);
          IF size < 0 THEN
            err.Error("Array size may not be negative");
            size := 0;
          END;
        END;
        t := T.NewType(T.tArray, t, size, {});
        Expect(Scanner.rsqbracket);
      END;
    END;
    RETURN t;
  END DeclaratorInner;

BEGIN
  t := DeclaratorInner();

  WHILE t # NIL DO
    CASE t.class OF
    | T.tPointer:
      base := T.NewType(T.tPointer, base, T.pointerSize, {});
    | T.tFunction:
      base := T.NewType(T.tFunction, base, 0, t.qualifiers);
      base.link := t.link;
    | T.tArray:
      base := T.NewType(T.tArray, base, t.size, t.qualifiers);
    | T.tQualifier:
      base := T.NewType(T.tQualifier, base, 0, t.qualifiers);
    END;
    t := t.base;
  END;
  RETURN base;
END Declarator;

PROCEDURE Expr (VAR result : LONGINT);
VAR a, b, c : LONGINT;

CONST
 optPreprocessor = {Scanner.optDontExpand, Scanner.optReturnEndLine};

 PROCEDURE GetSym0;
 BEGIN
   process.GetToken(token, optPreprocessor);
 END GetSym0;

 PROCEDURE Expect0(sym : INTEGER);
 BEGIN
   IF token.sym = sym THEN
     GetSym0;
   ELSE
     err.ExpectedToken(Scanner.NewToken(sym),token);
   END;
 END Expect0;

 PROCEDURE OrExpr (VAR result : LONGINT);
 VAR a, b : LONGINT;

  PROCEDURE AndExpr (VAR result : LONGINT);
  VAR a, b : LONGINT;

   PROCEDURE BitOrExpr (VAR result : LONGINT);
   VAR a, b : SET; i : LONGINT;

    PROCEDURE BitXorExpr (VAR result : LONGINT);
    VAR a, b : SET; i : LONGINT;

     PROCEDURE BitAndExpr (VAR result : LONGINT);
     VAR a, b : SET; i : LONGINT;

      PROCEDURE EquExpr (VAR result : LONGINT);
      VAR a, b : LONGINT; op : INTEGER;

       PROCEDURE RelExpr (VAR result : LONGINT);
       VAR a, b : LONGINT; op : INTEGER;

        PROCEDURE ShiftExpr (VAR result : LONGINT);
        VAR a, b : LONGINT; op : INTEGER;

         PROCEDURE AddExpr (VAR result : LONGINT);
         VAR a, b : LONGINT; op : INTEGER;

          PROCEDURE MultExpr (VAR result : LONGINT);
          VAR a, b : LONGINT; op : INTEGER;

           PROCEDURE UnaryExpr (VAR result : LONGINT);
           VAR 
             t : T.Type; name : Object.String8;
             op : INTEGER; 
             result2 : LONGINT; 
             needClose : BOOLEAN;
           BEGIN
             IF (token.sym = Scanner.not) OR (token.sym = Scanner.sub) OR (token.sym = Scanner.add) OR (token.sym = Scanner.bitNot) THEN
               op := token.sym; GetSym;
               UnaryExpr(result2);
               CASE op OF
               | Scanner.not: IF result2 = 0 THEN result := 1 ELSE result := 0 END
               | Scanner.sub: result := - result2;
               | Scanner.add:
               | Scanner.bitNot: result := SYSTEM.VAL(LONGINT, - SYSTEM.VAL(SET, result2))
               END
             ELSIF token.sym = Scanner.number THEN
               result := token.value; GetSym
             ELSIF (token.sym = Scanner.string) & (token.name.length = 3) THEN
               (* allow character constants in expressions *)
               result := ORD(token.name.CharAt(1)); GetSym;
             ELSIF token.sym = Scanner.lbracket THEN
               (* bracket indicates either a nested expression OR a type cast *)
               GetSym;
               IF StartsTypeSpecifier() THEN
                 name := NIL;
                 t := Declarator(name, TypeSpecifier());
                 Expect(Scanner.rbracket);
                 Expr(result); 
               ELSE
                 Expr(result);
                 Expect(Scanner.rbracket)
               END;
             ELSIF token.sym = defined THEN
               (* allow both "defined (symbol)" and "defined symbol" forms *)
               GetSym0;
               IF token.sym = Scanner.lbracket THEN
                 GetSym0; needClose := TRUE;
               ELSE
                 needClose := FALSE
               END;
               IF token.sym = Scanner.ident THEN
                 result := BoolInt(process.IsDefined(token.name));
               ELSE 
               END;
               GetSym0;
               IF needClose THEN Expect0(Scanner.rbracket); END;
             ELSIF token.sym = sizeof THEN
               GetSym;
               Expect(Scanner.lbracket);
               err.MsgParam("In sizeof, token=$0", token, NIL, NIL, FALSE);
               IF StartsTypeSpecifier() THEN
                 name := NIL;
                 t := Declarator(name, TypeSpecifier());
                 result := t.size;
                 IF result <= 0 THEN
                   result := 0;
                   err.ErrorParam("Size of type `$0' is unknown", t, NIL, NIL);
                 END;
               ELSE
                 err.ErrorParam("Token $0 is not a type specifier", token, NIL, NIL);
               END;
               Expect(Scanner.rbracket); 
             ELSIF (token.sym = Scanner.ident) THEN (* P.EnumConst(Scanner.identName, result) THEN
                 GetSym;
               ELSIF *) IF (resultKnown IN exprState) THEN
                 err.MsgParam("Treating undefined symbol '$0' as constant since result is unaffected", token.name, NIL, NIL, FALSE);
               ELSE
                 err.ErrorParam("Identifier `$0' is undefined", token.name, NIL, NIL);
               END;
               result := 0;
               GetSym;
             ELSE err.UnexpectedToken(token);
             END
           END UnaryExpr;
           
          BEGIN
            UnaryExpr(a);
            WHILE (token.sym = Scanner.mul) OR (token.sym = Scanner.div) OR (token.sym = Scanner.mod) DO
              op := token.sym;
              GetSym;
              MultExpr(b);
              CASE op OF
              | Scanner.mul: a := a * b 
              | Scanner.div: a := a DIV b
              | Scanner.mod: a := a MOD b
              END
            END;
            result := a;
          END MultExpr;

         BEGIN
           MultExpr(a);
           WHILE (token.sym = Scanner.add) OR (token.sym = Scanner.sub) DO
             op := token.sym;
             GetSym;
             MultExpr(b);
             CASE op OF
             | Scanner.add: a := a + b 
             | Scanner.sub: a := a - b
             END
           END;
           result := a;
         END AddExpr;

        BEGIN
          AddExpr(a);
          WHILE (token.sym = Scanner.lsh) OR (token.sym = Scanner.rsh) DO
            op := token.sym;
            GetSym;
            AddExpr(b);
            CASE op OF
            | Scanner.lsh: a := SYSTEM.LSH(a, b)
            | Scanner.rsh: a := SYSTEM.LSH(a, -b)
            END
          END;
          result := a;
        END ShiftExpr;
        
       BEGIN
         ShiftExpr(a);
         WHILE (token.sym = Scanner.lt) OR (token.sym = Scanner.leq) OR (token.sym = Scanner.gt) OR (token.sym = Scanner.geq) DO
           op := token.sym;
           GetSym;
           ShiftExpr(b);
           CASE op OF
           | Scanner.lt:  a := BoolInt(a < b)
           | Scanner.leq: a := BoolInt(a <= b)
           | Scanner.gt:  a := BoolInt(a > b)
           | Scanner.geq: a := BoolInt(a >= b)
           END
         END;
         result := a;
       END RelExpr;

      BEGIN
        RelExpr(a);
        WHILE (token.sym = Scanner.eq) OR (token.sym = Scanner.notEq) DO
          op := token.sym;
          GetSym;
          RelExpr(b);
          CASE op OF
          | Scanner.eq:    a := BoolInt(a = b)
          | Scanner.notEq: a := BoolInt(a # b)
          END
        END;
        result := a;
      END EquExpr;

     BEGIN
       EquExpr(i); a := SYSTEM.VAL(SET, i);
       WHILE token.sym = Scanner.bitAnd DO
         GetSym;
         EquExpr(i); b := SYSTEM.VAL(SET, i);
         a := a * b;
       END;
       result := SYSTEM.VAL(LONGINT, a);
     END BitAndExpr;
     
    BEGIN
      BitAndExpr(i); a := SYSTEM.VAL(SET, i);
      WHILE token.sym = Scanner.xor DO
        GetSym;
        BitAndExpr(i); b := SYSTEM.VAL(SET, i);
        a := a / b;
      END;
      result := SYSTEM.VAL(LONGINT, a);
    END BitXorExpr;

   BEGIN
     BitXorExpr(i); a := SYSTEM.VAL(SET, i);
     WHILE token.sym = Scanner.bitOr DO
       GetSym;
       BitXorExpr(i); b := SYSTEM.VAL(SET, i);
       a := a + b
     END;
     result := SYSTEM.VAL(LONGINT, a);
   END BitOrExpr;
    
  BEGIN
    BitOrExpr(a);
    WHILE token.sym = Scanner.and DO
      GetSym;
      IF a = 0 THEN INCL(exprState, resultKnown) END;
      BitOrExpr(b);
      a := BoolInt((a # 0) & (b # 0))
    END;
    result := a
  END AndExpr;

 BEGIN
   AndExpr(a);
   WHILE token.sym = Scanner.or DO
     GetSym;
     IF a # 0 THEN INCL(exprState, resultKnown) END;
     AndExpr(b);
     a := BoolInt((a # 0) OR (b # 0))
   END;
   result := a
 END OrExpr;
  
BEGIN
  OrExpr(a);
  IF token.sym = Scanner.condIf THEN
    GetSym;
    OrExpr(b);
    Expect(Scanner.colon);
    OrExpr(c);
    IF a # 0 THEN result := b ELSE result := c END
  ELSE
    result := a;
  END
END Expr;

PROCEDURE EvalExpr (VAR result : LONGINT);
BEGIN
  exprState := {};
  Expr(result);
END EvalExpr;
 
PROCEDURE (p : Parser) Evaluate* (inToken : Scanner.Token; inOptions : SET; VAR result : LONGINT);
VAR
  oldOptions : SET;
  oldToken : Scanner.Token;
BEGIN
  (* If Evaluate is called by the preprocessor, the current token may not have
  been checked against defined keywords. *)

  oldToken := token; oldOptions := options;
  token := inToken; options := inOptions;

  Scanner.CheckKeyWord(keyWords, token);
  EvalExpr(result);

  token := oldToken; options := oldOptions;
END Evaluate;

(*
PROCEDURE SameTypes* (t1, t2 : Type) : BOOLEAN;

  PROCEDURE SameTypesList (o1, o2 : Object) : BOOLEAN;
  VAR
    p1, p2 : Object;
  BEGIN
    (* are both lists empty ? *)
    IF (o1 = NIL) & (o2 = NIL) THEN RETURN TRUE END;
    (* is one list empty ? *)
    IF (o1 = NIL) OR (o2 = NIL) THEN RETURN FALSE END;
    p1 := o1;
    p2 := o2;
    LOOP
      p1 := p1.next;
      p2 := p2.next;

      (* at end of both lists ? *)
      IF (p1 = o1) & (p2 = o2) THEN RETURN TRUE END;
      (* at end of one list ? *)
      IF (p1 = o1) OR (p2 = o2) THEN RETURN FALSE END;
      IF ~SameTypes(p1.type, p2.type) THEN RETURN FALSE END;
    END;
  END SameTypesList;

BEGIN
  IF (t1 = NIL) & (t2 = NIL) THEN RETURN TRUE END;
  IF (t1 = NIL) OR (t2 = NIL) THEN RETURN FALSE END;

  IF (t1.class # t2.class) THEN RETURN FALSE END;
  CASE t1.class OF
  | T.tPointer:
    RETURN SameTypes(t1.base, t2.base)
  | T.tArray:
    RETURN SameTypes(t1.base, t2.base) & (t1.size = t2.size)
  | T.tStruct, T.tUnion:
    RETURN t1 = t2;
  | T.tTypedef:
    RETURN t1 = t2;
  | T.tFunction:
    RETURN SameTypes(t1.base, t2.base) & SameTypesList(t1.link, t2.link);
  ELSE
    RETURN TRUE;
  END;
END SameTypes;
*)

PROCEDURE Declaration;
VAR 
  name : Object.String8;
  class : INTEGER;
  spec, type, t : T.Type;

  PROCEDURE ShowBinding(name : Object.String8; type : T.Type);
  VAR
     b : StringBuffer.StringBuffer;
  BEGIN
    b := StringBuffer.New("Name: `");
    b.Append(name);
    b.Append("', Type: ");
    b.Append(type);
    Out.Str(b.ToString()); Out.Ln;
  END ShowBinding;
  
  PROCEDURE SkipBody;
  VAR level : INTEGER;
  BEGIN
    level := 0;
    LOOP
      GetSym;
      IF (token.sym = Scanner.rbrace) THEN
        IF level = 0 THEN EXIT END;
        DEC(level);
      ELSIF (token.sym = Scanner.lbrace) THEN
        INC(level);
      END;
    END;
    GetSym;
  END SkipBody;
  
BEGIN
  StorageClass(class);
  spec := TypeSpecifier();

  LOOP
    name := NIL;
    type := Declarator(name, spec);
    IF name = NIL THEN
      err.Error("Declaration must specify a name");
      name := Object.NewLatin1("error");
    END;
    IF class = T.scTypedef THEN
      t := T.NewType(T.tName, type, type.size, {}); t.name := name;
      InstallType(name, t);
    ELSE
      Install(scope, "Object", name, type);
    END;
    ShowBinding(name, type);
    IF type.class = T.tFunction THEN
      IF token.sym = Scanner.lbrace THEN
        SkipBody;
        RETURN;
      END;
    END;
    IF token.sym = Scanner.comma THEN
      GetSym;
    ELSIF token.sym = Scanner.semicolon THEN
      RETURN;
    END;
  END;
END Declaration;

PROCEDURE Body*;
BEGIN
  GetSym;
  WHILE token.sym # Scanner.endFile DO
    Declaration();
    Expect(Scanner.semicolon);
  END;
END Body;

PROCEDURE Init* (proc: Process.Process);
BEGIN
  process := proc;
  err := process.err;
END Init;

PROCEDURE New* () : Parser;
VAR p : Parser;
BEGIN
  NEW(p);
  RETURN p;
END New;

PROCEDURE AddKeyWords;
BEGIN
  Scanner.AddKeyWord(keyWords, "extern", extern);
  Scanner.AddKeyWord(keyWords,"typedef", typedef); 
  Scanner.AddKeyWord(keyWords,"static", static);

  Scanner.AddKeyWord(keyWords,"float", float); 
  Scanner.AddKeyWord(keyWords,"double", double);
  Scanner.AddKeyWord(keyWords,"char", char); 
  Scanner.AddKeyWord(keyWords,"int", int); 
  Scanner.AddKeyWord(keyWords,"__int64", longlong); 
  Scanner.AddKeyWord(keyWords,"wchar_t", wchar);
  Scanner.AddKeyWord(keyWords,"long", long); 
  Scanner.AddKeyWord(keyWords,"short", short);
  Scanner.AddKeyWord(keyWords,"unsigned", unsigned); 
  Scanner.AddKeyWord(keyWords,"signed", signed);

  Scanner.AddKeyWord(keyWords,"struct", struct); 
  Scanner.AddKeyWord(keyWords,"union", union); 
  Scanner.AddKeyWord(keyWords,"void", void); 
  Scanner.AddKeyWord(keyWords,"enum", enum); 

  Scanner.AddKeyWord(keyWords,"__cdecl", cdecl); 
  Scanner.AddKeyWord(keyWords,"__stdcall", stdcall);
  Scanner.AddKeyWord(keyWords,"const", const); 
  Scanner.AddKeyWord(keyWords,"volatile", volatile);

  Scanner.AddKeyWord(keyWords,"sizeof", sizeof);
  Scanner.AddKeyWord(keyWords,"defined", defined);
END AddKeyWords;

BEGIN 
  NEW(parser);
  keyWords := NIL;
  AddKeyWords;
  options := {}; token := Scanner.NewToken(Scanner.endFile);
  types := NIL; scope := NIL;
  depend := ArrayList.New(10);
END H2O:Parser.

