MODULE H2O:Parser [OOC_EXTENSIONS];

IMPORT
  SYSTEM, Err, Log,
  Object, ADT:StringBuffer, ADT:ArrayList, ADT:Dictionary,
  H2O:Emitter, H2O:Option,
  H2O:Error, H2O:Scanner, H2O:Process, H2O:Value, 
  T := H2O:Type, H2O:Variant, StringSearch, StringSearch:RegexpDFA;

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

  configH2O = 10000;
  configModule = 10001;
  configOption = 10002;
  configVariant = 10003;
  configSet = 10004;
  configVar = 10005;
  configArray = 10006;
  configPointer = 10007;
  configDefault = 10008;
  configCstring = 10009;

CONST
  varargs = 0;
  debugExpr = FALSE;
  L = 0;
  R = 1;

  typeInvalid = 0;
  typeInteger = 1;
  typeReal = 2;

TYPE
  Parser* = POINTER TO ParserDesc;
  ParserDesc* = RECORD (Scanner.InterpreterDesc)
    (*state : SET;*)
  END;

TYPE
  Operator = POINTER TO OperatorDesc;
  OperatorDesc = RECORD
    sym, sym2 : INTEGER;
    priority : INTEGER;
    args : INTEGER;
	assoc : INTEGER;
    next : Operator;
  END;

CONST
  (* Expr options *)
  allowUndefined* = 0;

VAR
  operators : Operator;

  keyWords : Scanner.KeyWord;
  configKeyWords : Scanner.KeyWord;
  process : Process.Process;
  err : Error.Error;
  token : Scanner.Token;
  options : SET;
  parser : Parser;
  depend : ArrayList.ArrayList(T.Module);
  autoNameSeq : LONGINT;

  configOptions : Option.Options;
  parserOptions- : Option.Options;

  parserOutputDeclarations : Option.Boolean;
  parserOutputDependencies : Option.Boolean;

PROCEDURE FindType(types : INTEGER; name : STRING) : T.Type;
VAR obj : T.Object;
BEGIN
  IF T.FindObject({types}, name, obj) THEN
    RETURN obj.type;
  ELSE
    RETURN NIL;
  END;
END FindType;

PROCEDURE ShowDepend* (name : STRING; depend : ArrayList.ArrayList(T.Module));
VAR b : StringBuffer.StringBuffer; i : LONGINT; module : T.Module;
BEGIN
  b := StringBuffer.New("");
  b.Append(name);
  b.Append(" depends on [");
  FOR i := 0 TO depend.size-1 DO
    IF i # 0 THEN b.AppendLatin1Char(",") END;
    module := depend.Get(i);
    b.Append(module.name);
  END;
  b.Append("]");
  Err.Object(b); Err.Ln;
END ShowDepend;

PROCEDURE Install* (scope : INTEGER; mod : T.Module; tag : STRING; name : STRING; new : T.Type; tail : BOOLEAN);
VAR 
  obj : T.Object;
BEGIN
  IF T.FindObjectModule(mod, {scope}, name, obj) THEN
    IF T.AllowedRedefinition(new, obj.type) THEN
      obj.type := new;
    ELSE
      err.ErrorParam("$0 `$1' already defined as $2", tag, name, obj.type.Base());
    END
  ELSE
    T.Bind(scope, name, 0, new, mod, tail);
  END;
  new.Depend(depend);
  IF parserOutputDependencies.value THEN
    IF depend.size > 0 THEN ShowDepend(name, depend) END;
  END;
  mod.AddImports(depend);
  mod.AddDefinition();
END Install;

PROCEDURE InstallType* (scope : INTEGER; mod : T.Module; name : STRING; new : T.Type);
BEGIN
  Install(scope, mod, "Type", name, new, TRUE);
END InstallType;

PROCEDURE GetModule() : T.Module;
BEGIN
  RETURN process.in.GetModule();
END GetModule;

PROCEDURE AnonName*(prefix : STRING) : STRING;
VAR
  b : StringBuffer.StringBuffer;
BEGIN
  b := StringBuffer.New(prefix);
  b.AppendInt(autoNameSeq);
  INC(autoNameSeq);
  RETURN b.ToString();
END AnonName;

PROCEDURE MakeName(name : STRING; t : T.Type; mod : T.Module) : T.Type;
VAR 
  n : T.Type;
BEGIN
  n := T.NewType(T.tName, t, t.size, {}); 
  n.name := name;
  n.module := mod;
  RETURN n;
END MakeName;

PROCEDURE NewNamedType* (class : SHORTINT; name : STRING) : T.Type;
VAR 
  new : T.Type;
  mod : T.Module;
BEGIN
  mod := GetModule();
  new := T.NewType(class, NIL, 0, {});
  new.name := name;
  new.module := mod;

  IF name # NIL THEN
    InstallType(T.types, mod, name, new);
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
    RETURN FindType(T.typedefs, token.name) # NIL;
  ELSE
    RETURN FALSE;
  END;
END StartsTypeSpecifier;

PROCEDURE ^Declarator(VAR name : STRING; base : T.Type) : T.Type;
PROCEDURE ^EvalExpr (VAR result : Value.Object);
PROCEDURE ^EvalIntExpr (VAR result : LONGINT);

PROCEDURE EvalPositiveIntExpr(VAR result : LONGINT);
BEGIN
  EvalIntExpr(result);
  IF result < 0 THEN
    err.Error("Expression must be positive");
  END;
END EvalPositiveIntExpr;


PROCEDURE StorageClass (VAR class : INTEGER);
(* 
> StorageClass ::= [ "extern" | "static" | "typedef" ].
*)
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
(* 
> TypeQualifier ::= { "const" | "volatile" | "__cdecl" | "__stdcall" }.
*)
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

(*
> TypeSpecifier ::= 
>   { Qualifier }
>   (EnumDecl | StructDecl | IntDecl | FloatDecl | TypedefName | VoidDecl).
> Qualifier ::= "const" | "volatile".
> SignedIntDecl ::= 
>   "char" | "int" | "short" [ "int" ] | "long" [ "long" ] [ "int" ].
> IntDecl ::=  SignedIntDecl | "unsigned" [ SignedIntDecl ].
> FloatDecl ::= "float" | "long" "float " | "double" | 
> TypedefName ::= ident.
> VoidDecl ::= "void".
*)

PROCEDURE TypeSpecifier() : T.Type;
VAR
  sym, sign, size, type : INTEGER;
  qualifiers : SET;
  s, t : T.Type; mod : T.Module;

  PROCEDURE EnumDecl() : T.Type;
(*
> Element ::= ident [ "=" Expr].
> EnumDecl ::= "enum" [ ident ] [ "{" Element { "," Element } "}" ].
*)
  VAR 
    tag, name : STRING;
    t : T.Type; id : LONGINT;

    PROCEDURE Element;
    VAR name : STRING; assignToken : Scanner.Token;
    BEGIN
      name := token.name;
      Expect(Scanner.ident);
      IF token.sym = Scanner.assign THEN
        assignToken := token;
        GetSym;
        EvalIntExpr(id);
      ELSE
        INC(id);
      END;
      T.BindLocal(t.link, name, id, NIL, NIL, TRUE);
     END Element;

  BEGIN
    GetSym;
    tag := NIL; id := -1;
    IF token.sym = Scanner.ident THEN
      tag := token.name;
      GetSym;
    ELSE
      tag := AnonName("AutoEnum");
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
      t := FindType(T.types, tag);
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

(*
> StructDecl ::= StructureDefinition | StructureRefecence.
> StructUnion ::= "struct" | "union".
> StructureDefinition ::= StructUnion [ ident ] "{" FieldList "}".
> StructureReference ::= StructUnion ident.
> FieldList ::= { TypeSpecifier FieldDeclaratorList ";" }.
> FieldDeclaratorList ::= FieldDeclarator { "," FieldDeclarator }.
> FieldDeclarator ::= Declarator [ ":" FieldWidth ].
> FieldWidth ::= Expr.
*)

  PROCEDURE StructDecl(class : SHORTINT) : T.Type;
  VAR 
    t : T.Type;
    tag : STRING;
    id : LONGINT;

    PROCEDURE FieldList(t : T.Type);
    VAR 
      t1, t2 : T.Type; 
      name : STRING;
      width : LONGINT;
    BEGIN
      WHILE StartsTypeSpecifier() DO
        t1 := TypeSpecifier();
        LOOP
          name := NIL;
          t2 := Declarator(name, t1);
          T.BindLocal(t.link, name, id, t2, NIL, TRUE);
          IF token.sym = Scanner.colon THEN
            GetSym;
            EvalPositiveIntExpr(width);
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
      t := FindType(T.types, tag);
      IF t = NIL THEN
        t := NewNamedType(class, tag);
      ELSIF t.class # class THEN
        err.ErrorParam("Tag `$0' already defined with different type: $1", tag, t, NIL);
      END;
    ELSE
      err.Error("Missing tag in struct/union declaration");
      t := NewNamedType(class, "error");
    END;
    RETURN t;
  END StructDecl;

  PROCEDURE CondType(cond : BOOLEAN; true, false : T.Type) : T.Type;
  BEGIN
    IF cond THEN RETURN true ELSE RETURN false END;
  END CondType;

BEGIN
(* Note: This implementation is a little wierd and probably needs some
further thought. I've modelled it on the implementation in the "lcc"
compiler, but it doesn't strictly follow the language definition. *)
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
    | void, char, int, float, double: 
      type := sym; GetSym;
    | enum:
      type := enum; t := EnumDecl();
    | struct:
      type := struct; t := StructDecl(T.tStruct); EXIT;
    | union:
      type := union; t := StructDecl(T.tUnion); EXIT;
    | Scanner.ident:
      s := FindType(T.typedefs, token.name);
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

(*
> Declarator ::= 
>   SimpleDeclarator 
> | "(" Declarator ")" | 
> | FunctionDeclarator
> | ArrayDeclarator
> | PointerDeclarator.
> SimpleDeclarator ::= ident.
> FunctionDeclarator ::= Declarator "(" [ ParameterList ] ")".
> ArrayDeclarator ::= Declarator "[" [ Expr ] "]".
> PointerDeclarator ::= "*" { Qualifiers } Declarator.
*)

PROCEDURE Declarator(VAR name : STRING; base : T.Type) : T.Type;
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
      name : STRING;
  
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
            T.BindLocal(func.link, name, id, t, NIL, TRUE);
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
          EvalPositiveIntExpr(size);
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

(* Miscellaneous type conversion *)

PROCEDURE IntSet(i : LONGINT) : SET;
BEGIN
  RETURN SYSTEM.VAL(SET, i);
END IntSet;

PROCEDURE SetInt(s : SET) : LONGINT;
BEGIN
  RETURN SYSTEM.VAL(LONGINT, s);
END SetInt;

PROCEDURE BoolInt(b : BOOLEAN) : LONGINT;
BEGIN
  IF b THEN RETURN 1 ELSE RETURN 0 END
END BoolInt;

PROCEDURE TypeOf(arg : Value.Object; VAR i : LONGINT; VAR r : LONGREAL) : INTEGER;
BEGIN
  WITH arg: Value.LongInt DO
    i := arg.value; r := i; 
    RETURN typeInteger;
  | arg: Value.LongReal DO
    r := arg.value;
    RETURN typeReal;
  ELSE
    RETURN typeInvalid;
  END;
END TypeOf;

PROCEDURE Max(a, b : INTEGER) : INTEGER;
BEGIN
  IF a > b THEN RETURN a ELSE RETURN b END;
END Max;

PROCEDURE TypeError(op : Scanner.Token) : Value.Object;
BEGIN
  err.ErrorParam("Invalid types for operator `$0'", op.name, NIL, NIL);
  RETURN Value.zeroLongInt;
END TypeError;

PROCEDURE AdjustSize(arg : Value.Object; VAR radix, size : INTEGER);
BEGIN
  WITH arg : Value.LongInt DO
    radix := Max(radix, arg.radix);
    size := Max(size, arg.size);
  END;
END AdjustSize;

(* Ternary operators *)
PROCEDURE Operate3(op : Scanner.Token; arg1, arg2, arg3 : Value.Object) : Value.Object;
VAR 
  ai, bi, ci : LONGINT;
  ar, br, cr : LONGREAL;
  opType : INTEGER;
  radix, size : INTEGER;
BEGIN
  ai := 0; bi := 0; ci := 0;
  ar := 0; br := 0; cr := 0;
  opType := TypeOf(arg1, ai, ar);
  opType := Max(opType, TypeOf(arg2, bi, br));
  opType := Max(opType, TypeOf(arg3, ci, cr));
  
  CASE opType OF
  | typeInteger:
    radix := -1; size := -1; 
    AdjustSize(arg1, radix, size); 
    AdjustSize(arg2, radix, size); 
    AdjustSize(arg3, radix, size); 
    CASE op.sym OF
    | Scanner.condIf:
      IF ai # 0 THEN ai := bi ELSE ai := ci END;
    ELSE
      RETURN TypeError(op);
    END;
    RETURN Value.NewLongIntSize(ai, radix, size);
  ELSE
    RETURN TypeError(op);
  END;
END Operate3;

(* Binary operators *)
PROCEDURE Operate2(op : Scanner.Token; arg1, arg2 : Value.Object) : Value.Object;
VAR 
  ai, bi : LONGINT;
  ar, br : LONGREAL;
  opType : INTEGER;
  radix, size : INTEGER;
BEGIN
  ai := 0; bi := 0;
  ar := 0; br := 0;
  opType := TypeOf(arg1, ai, ar);
  opType := Max(opType, TypeOf(arg2, bi, br));
  CASE opType OF
  | typeInteger:
    radix := -1; size := -1;
    AdjustSize(arg1, radix, size); AdjustSize(arg2, radix, size);
    CASE op.sym OF
    | Scanner.add:    ai := ai + bi;
    | Scanner.sub:    ai := ai - bi;
    | Scanner.div:    ai := ai DIV bi;
    | Scanner.mul:    ai := ai * bi;
    | Scanner.mod:    ai := ai MOD bi;

    | Scanner.lt:     ai := BoolInt(ai < bi);
    | Scanner.leq:    ai := BoolInt(ai <= bi);
    | Scanner.gt:     ai := BoolInt(ai > bi);
    | Scanner.geq:    ai := BoolInt(ai >= bi);
    | Scanner.eq:     ai := BoolInt(ai = bi);
    | Scanner.notEq:  ai := BoolInt(ai # bi);

    | Scanner.bitAnd: ai := SetInt(IntSet(ai) * IntSet(bi));
    | Scanner.bitOr:  ai := SetInt(IntSet(ai) + IntSet(bi));
    | Scanner.xor:    ai := SetInt(IntSet(ai) / IntSet(bi));
 
    | Scanner.lsh:    ai := SYSTEM.LSH(ai, bi);
    | Scanner.rsh:    ai := SYSTEM.LSH(ai, -bi); 

    | Scanner.and:    ai := BoolInt((bi # 0) & (ai # 0));
    | Scanner.or:     ai := BoolInt((bi # 0) OR (ai # 0));
    ELSE
      RETURN TypeError(op);
    END;
    RETURN Value.NewLongIntSize(ai, radix, size);

  | typeReal:
    CASE op.sym OF
    | Scanner.add:    ar := ar + br;
    | Scanner.sub:    ar := ar - br;
    | Scanner.div:    ar := ar / br;
    | Scanner.mul:    ar := ar * br;
  
    | Scanner.lt:     ar := BoolInt(ar < br);
    | Scanner.leq:    ar := BoolInt(ar <= br);
    | Scanner.gt:     ar := BoolInt(ar > br);
    | Scanner.geq:    ar := BoolInt(ar >= br);
    | Scanner.eq:     ar := BoolInt(ar = br);
    | Scanner.notEq:  ar := BoolInt(ar # br);
    ELSE
      RETURN TypeError(op);
    END;
    RETURN Value.NewLongReal(ar);

  ELSE
    RETURN TypeError(op);
  END
END Operate2;

(* Unary operators *)
PROCEDURE Operate1(op : Scanner.Token; arg1 : Value.Object) : Value.Object;
VAR 
  ai : LONGINT;
  ar : LONGREAL;
  opType : INTEGER;
  radix, size : INTEGER;
BEGIN
  ai := 0; ar := 0;
  opType := TypeOf(arg1, ai, ar);
  CASE opType OF
  | typeInteger:
    radix := -1; size := -1;
    AdjustSize(arg1, radix, size);
    CASE op.sym OF
    | Scanner.add:
    | Scanner.sub:    ai := -ai;
    | Scanner.bitNot: ai := SetInt(-IntSet(ai));
    | Scanner.not:    IF ai = 0 THEN ai := 1 ELSE ai := 0 END;
    ELSE
      RETURN TypeError(op);
    END;
    RETURN Value.NewLongIntSize(ai, radix, size);

  | typeReal:
    CASE op.sym OF
    | Scanner.add:
    | Scanner.sub:    ar := -ar;
    ELSE
      RETURN TypeError(op);
    END;
    RETURN Value.NewLongReal(ar);

  ELSE
    RETURN TypeError(op);
  END
END Operate1;

PROCEDURE FindOperator(sym : INTEGER; args : INTEGER) : Operator;
VAR op : Operator;
BEGIN
  op := operators;
  WHILE op # NIL DO
    IF (sym = op.sym) & (args = op.args) THEN
      RETURN op;
    END;
    op := op.next
  END;
  RETURN NIL
END FindOperator;


(* Expression parsing.

This implementation is based on a technique described as "precedence
climbing". Its more flexible that straight recursive descent and simpler than
the classic "shunting" algorithm. The algorithm is succinctly explained by
Theodore S. Norvell here:
  http://www.engr.mun.ca/~theo/Misc/exp_parsing.htm
He in turn attributes the approach to Keith Clarke who describes it in a 
posting to comp.compilers.

Advantages of this approach: 
- any number of operators can be defined without changing the parser code
- operators have configurable precedence and associativity
This is particularly important for "C", which defines 15 (!!!) operator
precedence levels.
*)

(*
> Expr ::= 
>   ConditionalExpr | BinaryExpr | UnaryExpr | PrimaryExpr.
> ConditionalExpr ::= Expr "?" Expr ":" Expr.
> BinaryExpr ::= Expr BinaryOperator Expr.
> BinaryOperator ::= 
>   BitwiseOperator | RelationalOperator | ShiftOperator 
> | ArithmeticOperator | LocigalOperator.
> BitwiseOperator ::= "&" | "|" | "^".
> RelationalOperator ::= "<" | "<=" | ">" | ">=" | "==" | "!=".
> ShiftOperator ::= "<<" | ">>".
> ArithmeticOperator ::= "+" | "-" | "*" | "/" | "%".
> LogicalOperator ::= "&&" | "||".
> UnaryExpr ::= 
>   CastExpr | SizeofExpr | UnaryOperator Expr.
> SizeofExpr ::= "sizeof" "(" TypeName ")".
> CastExpr ::= "(" TypeName ")" Expr.
> UnaryOperator ::= "-" | "~" | "!".
> PrimaryExpr ::=
>   number | reaNumber | string | ParenthesisedExpr | DefinedExpr.
> ParenthesisedExpr ::= "(" Expr ")".
> DefinedExpr ::=
>   "defined" "(" ident ")"
> | "defined" ident.
> TypeName ::=
>   TypeSpecifier AbstractDeclarator.
> (* FIXME! Implement abstract declarator. *)
> AbstractDeclarator ::= Declarator.
*)
 
PROCEDURE Expr(priority : INTEGER) : Value.Object;
VAR 
  result, arg2, arg3 : Value.Object;
  q : INTEGER;
  op : Operator;
  t2 : Scanner.Token;

  PROCEDURE Term() : Value.Object;
  VAR
    result : Value.Object;
    q : INTEGER;
    op : Operator;
    t2 : Scanner.Token;
     
 
    PROCEDURE Factor() : Value.Object;
    CONST
      optPreprocessor = {Scanner.optDontExpand, Scanner.optReturnEndLine};
    VAR 
      t : T.Type; name : STRING;
      result : Value.Object; mod : T.Module;
      size : LONGINT;
      needClose : BOOLEAN;
      t2 : Scanner.Token;
      op : Operator;

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

    BEGIN
      op := FindOperator(token.sym, 1);
      IF op # NIL THEN
        (* unary operator *)
        t2 := token.Copy();
        GetSym();
        result := Expr(op.priority);
		result := Operate1(t2, result);

      ELSIF token.sym = Scanner.number THEN
        (* constant integer *)
        result := Value.NewLongIntSize(token.value, token.base, token.len); GetSym;

      ELSIF token.sym = Scanner.realNumber THEN
        (* constant real *)
        result := Value.NewLongReal(token.rvalue); GetSym;

      ELSIF (token.sym = Scanner.string) THEN
        IF (token.name.length = 3) THEN
          (* constant character *)
          result := Value.NewLongInt(ORD(token.name.CharAt(1)));
        ELSE
          (* string *)
          result := Value.NewString(Scanner.Unquote(token.name));
        END;
        GetSym;

      ELSIF token.sym = Scanner.lbracket THEN
        (* bracket indicates either a nested expression OR a type cast *)
        IF StartsTypeSpecifier() THEN
          (* type cast *)
          GetSym;
          name := NIL;
          t := Declarator(name, TypeSpecifier());
          Expect(Scanner.rbracket);
          result := Factor();
        ELSE
          (* nested expression *)
          GetSym;
          result := Expr(0);
          Expect(Scanner.rbracket);
        END

      ELSIF token.sym = defined THEN
        (* defined: allow both "defined (symbol)" and "defined symbol" forms *)
        GetSym0;
        IF token.sym = Scanner.lbracket THEN
          GetSym0; needClose := TRUE;
        ELSE
          needClose := FALSE
        END;
        IF token.sym = Scanner.ident THEN
          result := Value.NewLongInt(BoolInt(process.IsDefined(token.name)));
        ELSE 
          err.MsgParam("Warning: defined() applied to non-identifier '$0'. Returning 0", token.name, NIL, NIL, FALSE);
          result := Value.zeroLongInt
        END;
        GetSym0;
        IF needClose THEN Expect0(Scanner.rbracket); END;

      ELSIF token.sym = sizeof THEN
        (* sizeof: *)
        GetSym;
        Expect(Scanner.lbracket);
        IF StartsTypeSpecifier() THEN
          name := NIL;
          t := Declarator(name, TypeSpecifier());
          size := t.Size();
          IF size <= 0 THEN
            size := 0;
            err.ErrorParam("Size of type `$0' is unknown", t, NIL, NIL);
          END;
          result := Value.NewLongInt(size)
        ELSE
          err.ErrorParam("Token `$0' is not a type specifier", token.name, NIL, NIL);
          result := Value.zeroLongInt
        END;
        Expect(Scanner.rbracket); 

      ELSIF (token.sym = Scanner.ident) THEN 
		(* identifier is usually a defined symbol. However, if this expression
           is a clause in a preprocesor directive (eg. #if) undefined symbols
           are treated as false (ie. 0) constants. *)
        IF T.FindConstant(token.name, result, mod) THEN
          (* TODO: track module dependencies for expressions *)
        ELSIF allowUndefined IN options THEN
          result := Value.zeroLongInt;
          err.MsgParam("Treating undefined symbol '$0' as constant 0", token.name, NIL, NIL, FALSE);
        ELSE
          err.ErrorParam("Identifier `$0' is undefined", token.name, NIL, NIL);
        END;
        GetSym
      ELSE 
        err.UnexpectedToken(token);
        result := Value.zeroLongInt
      END;
      RETURN result
    END Factor;
  
  BEGIN
    result := Factor();
    (* handle binary operators *)
    op := FindOperator(token.sym, 2);

    WHILE (op # NIL) & (op.priority >= priority) DO
      t2 := token.Copy(); GetSym;
      q := op.priority;
      IF op.assoc = L THEN INC(q) END;
      result := Operate2(t2, result, Expr(q));
      op := FindOperator(token.sym, 2);
    END;
    RETURN result;
  END Term;
  
BEGIN
  result := Term();
  (* handle ternary operators *)
  op := FindOperator(token.sym, 3);

  WHILE (op # NIL) & (op.priority >= priority) DO
    t2 := token.Copy(); GetSym;
    q := op.priority;
    IF op.assoc = L THEN INC(q) END;
    arg2 := Expr(q);
    IF op.sym2 # 0 THEN Expect(op.sym2) END;
    arg3 := Expr(q);
    result := Operate3(t2, result, arg2, arg3);
    op := FindOperator(token.sym, 2);
  END;
  RETURN result;
END Expr;

PROCEDURE EvalExpr* (VAR result : Value.Object);
BEGIN
  result := Expr(0);
END EvalExpr;

PROCEDURE EvalIntExpr(VAR result : LONGINT);
VAR 
  obj : Value.Object;
BEGIN
  EvalExpr(obj);
  WITH obj : Value.LongInt DO
    result := obj.value
  ELSE
    result := 0;
    err.Error("Expression must have integer type");
  END;
END EvalIntExpr;

PROCEDURE (p : Parser) Evaluate* (inToken : Scanner.Token; inOptions : SET; VAR result : LONGINT);
VAR
  oldOptions : SET;
  oldToken : Scanner.Token;
BEGIN
  (* If Evaluate is called by the preprocessor, the current token may not have
  been checked against defined keywords. *)

  oldToken := token; oldOptions := options;
  token := inToken; options := inOptions + {allowUndefined};

  Scanner.CheckKeyWord(keyWords, token);
  EvalIntExpr(result);

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

(*
> OuterDeclaration ::= Declaration FunctionDefinition.
> Declaration ::=
>   StorageClass TypeSpecifier DeclarationList.
> DeclarationList ::= Declarator { "," Declarator }.
> FunctionDefinition ::=
>   StorageClass TypeSpecifier Declarator [ FunctionBody ].
> FunctionBody ::= "{" FunctionBody | ANY "}"
*)

PROCEDURE Declaration;
VAR 
  name : STRING;
  class : INTEGER;
  spec, type, t : T.Type;
  mod : T.Module;

  PROCEDURE ShowBinding(name : STRING; type : T.Type);
  VAR
     b : StringBuffer.StringBuffer;
  BEGIN
    b := StringBuffer.New("Name: `");
    b.Append(name);
    b.Append("', Type: ");
    b.Append(type);
    Err.Object(b); Err.Ln;
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
    mod := GetModule();
    type := Declarator(name, spec);
    IF name = NIL THEN
      IF T.TypeNeedsName(type) THEN
        err.MsgString("Declaration should specify a name", FALSE);
      END
    ELSE
      IF class = T.scTypedef THEN
        t := MakeName(name, type, mod);
        InstallType(T.typedefs, mod, name, t);
      ELSE
        Install(T.vars, mod, "Object", name, type, TRUE);
      END;
      IF parserOutputDeclarations.value THEN
        IF class = T.scTypedef THEN
          Err.String("TYPE ")
        ELSE
          Err.String("VAR ")
        END;
        ShowBinding(name, type)
      END;
    END;
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

(*
> H2OConfig ::= "H2O" "{" { Config } "}".
> Config ::= ModuleConfig | OptionsConfig | VariantConfig.
> OptionsConfig ::= "OPTIONS" Options.
> Options ::= "{" { Option } "}".
> Option ::= ident "=" OptionValue { "," OptionValue } ";".
> OptionValue ::= Expr.
*)

PROCEDURE OptionValue(opt : Option.Option);
VAR 
  value : Value.Object;
BEGIN
  EvalExpr(value);
  IF ~opt.Set(value) THEN
    err.ErrorParam("Illegal value for option '$0': $1", opt.name, value, NIL);
  END
END OptionValue;

PROCEDURE OptionClause(set : Option.Options);
VAR 
  opt : Option.Option;
  value : Value.Object;
  name : STRING;
BEGIN
  name := token.name;
  Expect(Scanner.ident);
  Expect(Scanner.assign);
  opt := set.Find(name);
  IF opt = NIL THEN
    err.ErrorParam("Option '$0' is not defined", name, NIL, NIL)
  ELSE
    OptionValue(opt);
    IF Option.IsList(opt) THEN
      WHILE token.sym = Scanner.comma DO
        GetSym;
        OptionValue(opt)
      END
    END
  END;
  Expect(Scanner.semicolon);
END OptionClause;

PROCEDURE Options(set : Option.Options);
BEGIN
  Expect(Scanner.lbrace);
  WHILE token.sym # Scanner.rbrace DO
    OptionClause(set);
  END;
  Expect(Scanner.rbrace);
  set.Write(Err.writer);
END Options;

PROCEDURE OptionsConfig;
BEGIN
  GetSym; Options(configOptions);
END OptionsConfig;

(*
> ModuleConfig ::= "MODULE" ident Options.
*)

PROCEDURE ModuleConfig;
VAR 
  name : STRING;
  module : T.Module;
BEGIN
  GetSym;
  name := token.name;
  Expect(Scanner.string);
  name := Scanner.Unquote(name);
  module := T.FindModule(name);
  IF module = NIL THEN
    module := T.NewModule(name);
  END;

  Options(module.options);
END ModuleConfig;

(*
> VariantConfig ::= "VARIANT" "{" Variant "}".
> Variant ::= VariantDesignator ":" VariantType.
> VariantType ::= "SET" | "VAR" | "ARRAY" | "VAR" "ARRAY".
> VariantDesignator ::= VariantPattern { VariantOperator }.
> VariantPattern ::= ident.
> VariantOperator ::=
>   "." VariantPattern
> | "[" [ Expr ] "]"
> | "^".
*)

PROCEDURE VariantPattern(VAR result : STRING; VAR matcher : StringSearch.Matcher);
BEGIN
  CASE token.sym OF
  | Scanner.ident:  
    result := token.name;
    matcher := NIL;
  | Scanner.string: 
    result := Scanner.Unquote(token.name);
    matcher := RegexpDFA.factory.Compile(result(Object.String8), {});
    IF matcher = NIL THEN
      err.ErrorParam("Illegal pattern '$0'", result, NIL, NIL)
    END;
  ELSE
    err.ExpectedIdentifier(token);
  END;
  GetSym;
END VariantPattern;

PROCEDURE VariantConfig;

  PROCEDURE ParseVariant() : Variant.Op;
  VAR
    pattern : STRING; 
    matcher : StringSearch.Matcher;
    head : Variant.Op;
    tail : Variant.Op;
    next : Variant.Op;
    variant : SET;
    element : INTEGER;
  
    PROCEDURE FieldOperator() : Variant.FieldOp;
    VAR pattern : STRING; matcher : StringSearch.Matcher;
    BEGIN
      Expect(Scanner.period);
      VariantPattern(pattern, matcher);
      RETURN NEW(Variant.FieldOp,pattern, matcher);
    END FieldOperator;
  
    PROCEDURE IndexOperator() : Variant.IndexOp;
    VAR index : LONGINT;
    BEGIN
      index := -1;
      Expect(Scanner.lsqbracket);
      IF token.sym # Scanner.rsqbracket THEN
        EvalPositiveIntExpr(index);
      END;
      Expect(Scanner.rsqbracket);
      RETURN NEW(Variant.IndexOp,index);
    END IndexOperator;
  
    PROCEDURE RefOperator() : Variant.RefOp;
    BEGIN
      Expect(Scanner.xor);
      RETURN NEW(Variant.RefOp);
    END RefOperator;
  
    PROCEDURE VariantType() : INTEGER;
    BEGIN
      IF token.sym = Scanner.ident THEN
        Scanner.CheckKeyWord(configKeyWords, token);
        CASE token.sym OF
        | configArray:    GetSym; RETURN Variant.array;
        | configPointer:    GetSym; RETURN Variant.pointer;
        | configCstring:    GetSym; RETURN Variant.cstring;
        | configDefault:    GetSym; RETURN Variant.default;
        | configVar:      GetSym; RETURN Variant.var;
        | configSet:      GetSym; RETURN Variant.set;
        ELSE
        END;
      END;
      RETURN -1;
    END VariantType;
  
  BEGIN
    VariantPattern(pattern, matcher);
    head := NEW(Variant.FieldOp,pattern, matcher);
    tail := head;
  
    (* consume optional list of operators *)
    LOOP
      CASE token.sym OF
      | Scanner.period:      next := FieldOperator();
      | Scanner.lsqbracket:  next := IndexOperator();
      | Scanner.xor:         next := RefOperator();
      ELSE
        EXIT
      END;
      tail.next := next;
      tail := next;
    END;
 
    Expect(Scanner.colon); 
    variant := {};
    element := VariantType();
    WHILE element >= 0 DO
      INCL(variant, element);
      element := VariantType();
    END;
  
    IF variant = {} THEN
      err.Error("Variant type expected");
    ELSE
      tail.variant := variant;
    END;
  
    RETURN head;
  END ParseVariant;
 

BEGIN
  GetSym;
  Expect(Scanner.lbrace);
  WHILE token.sym # Scanner.rbrace DO
    Variant.AddRule(ParseVariant());
    Expect(Scanner.semicolon);
  END;
  Expect(Scanner.rbrace);
END VariantConfig;

PROCEDURE ConfigClause;
BEGIN
  Scanner.CheckKeyWord(configKeyWords, token);
  CASE token.sym OF
  | configModule: ModuleConfig;
  | configOption: OptionsConfig;
  | configVariant: VariantConfig
  ELSE
    err.ErrorParam("Unexpected symbol $0", token, NIL, NIL);
  END;
END ConfigClause;

PROCEDURE H2OConfig;
BEGIN
  Expect(Scanner.lbrace);
  WHILE token.sym # Scanner.rbrace DO
    ConfigClause();
  END;
  Expect(Scanner.rbrace);
END H2OConfig;

(*
> Body ::= { (Declaration | H2OConfig) ";" }.
*)

PROCEDURE Body*;
BEGIN
  GetSym;
  WHILE token.sym # Scanner.endFile DO
    IF (token.sym = Scanner.ident) & (token.name.Equals("H2O")) THEN
      GetSym;
      H2OConfig();
    ELSE
      Declaration();
      Expect(Scanner.semicolon);
    END;
  END;
END Body;

PROCEDURE Evaluate*;
VAR result : Value.Object;
BEGIN
  GetSym;
  WHILE token.sym # Scanner.endFile DO
    EvalExpr(result);
    Expect(Scanner.semicolon);
    Log.Object("", result);
  END;
END Evaluate;

PROCEDURE ParseMacro(e : Emitter.Emitter; m : Process.Macro);
VAR 
  result : Value.Object;
  options : SET;
BEGIN
  ASSERT(token.sym = Scanner.endFile);
  IF m.function THEN RETURN END;

  options := err.options;
  err.options := {};
  err.count := 0;

  process.PushMacro(m); GetSym;
  EvalExpr(result);
  IF err.count = 0 THEN
    e.DeclType(Emitter.dtConst);
    e.Indent(1);
    e.WriteObject(m.module.MapName(m.name));
    e.WriteString("* = ");
    e.WriteObject(result);
    e.WriteString(";");
    e.WriteLn;
  END;

  WHILE token.sym # Scanner.endFile DO
    GetSym;
  END;
  err.options := options;
END ParseMacro;

PROCEDURE ParseMacros* (e : Emitter.Emitter; mod : T.Module);
VAR 
  items : ArrayList.ArrayList(Process.Macro);
  i : LONGINT;
  macro : Process.Macro;
BEGIN
  Log.Msg("Parsing macros");
  items := process.macroDecl;
  Log.Int("Macro count", items.Size());
  FOR i := 0 TO items.Size()-1 DO
    macro := items.Get(i);
    IF macro.module = mod THEN
      ParseMacro(e, items.Get(i));
    END;
  END;
END ParseMacros;

PROCEDURE Init* (proc: Process.Process; opt : Option.Options);
BEGIN
  process := proc;
  err := process.err;
  configOptions := opt;
END Init;

PROCEDURE New* () : Parser;
VAR p : Parser;
BEGIN
  NEW(p);
  RETURN p;
END New;

PROCEDURE AddConfigKeyWords;
BEGIN
  Scanner.AddKeyWord(configKeyWords, "H2O", configH2O);
  Scanner.AddKeyWord(configKeyWords, "MODULE", configModule);
  Scanner.AddKeyWord(configKeyWords, "OPTIONS", configOption);
  Scanner.AddKeyWord(configKeyWords, "VARIANT", configVariant);
  Scanner.AddKeyWord(configKeyWords, "SET", configSet);
  Scanner.AddKeyWord(configKeyWords, "VAR", configVar);
  Scanner.AddKeyWord(configKeyWords, "ARRAY", configArray);
  Scanner.AddKeyWord(configKeyWords, "POINTER", configPointer);
  Scanner.AddKeyWord(configKeyWords, "DEFAULT", configDefault);
  Scanner.AddKeyWord(configKeyWords, "CSTRING", configCstring);
END AddConfigKeyWords;

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

PROCEDURE AddOp3(sym, sym2, priority, assoc, args : INTEGER);
VAR o : Operator;
BEGIN
  NEW(o);
  o.sym := sym;
  o.sym2 := sym2;
  o.priority := priority;
  o.assoc := assoc;
  o.args := args;
  o.next := operators;
  operators := o;
END AddOp3;

PROCEDURE AddOp(sym, priority, assoc, args : INTEGER);
BEGIN
  AddOp3(sym, 0, priority, assoc, args);
END AddOp;

PROCEDURE AddOperators;
BEGIN
  operators := NIL;
  AddOp(Scanner.bitNot, 14, L, 1);
  AddOp(Scanner.not, 14, L, 1);
  AddOp(Scanner.sub, 14, L, 1);
  AddOp(Scanner.mul, 13, L, 2);
  AddOp(Scanner.div, 13, L, 2);
  AddOp(Scanner.mod, 13, L, 2);
  AddOp(Scanner.add, 12, L, 2);
  AddOp(Scanner.sub, 12, L, 2);
  AddOp(Scanner.lsh, 11, L, 2);
  AddOp(Scanner.rsh, 11, L, 2);
  AddOp(Scanner.lt, 10, L, 2);
  AddOp(Scanner.gt, 10, L, 2);
  AddOp(Scanner.leq, 10, L, 2);
  AddOp(Scanner.geq, 10, L, 2);
  AddOp(Scanner.eq, 9, L, 2);
  AddOp(Scanner.notEq, 9, L, 2);
  AddOp(Scanner.bitAnd, 8, L, 2);
  AddOp(Scanner.xor, 7, L, 2);
  AddOp(Scanner.bitOr, 6, L, 2);
  AddOp(Scanner.and, 5, L, 2);
  AddOp(Scanner.or, 4, L, 2);
  AddOp3(Scanner.condIf, Scanner.colon, 1, R, 3);
END AddOperators;

PROCEDURE InitOptions;
BEGIN
  parserOptions := NEW(Option.Options);
  parserOutputDeclarations := parserOptions.Boolean("ParserOutputDeclarations", FALSE);
  parserOutputDependencies := parserOptions.Boolean("ParserOutputDependencies", FALSE);
END InitOptions;

BEGIN 
  InitOptions;
  NEW(parser);
  keyWords := NIL;
  autoNameSeq := 0;
  AddKeyWords;
  AddConfigKeyWords;
  AddOperators;
  options := {}; token := Scanner.NewToken(Scanner.endFile);
  depend := NEW(ArrayList.ArrayList(T.Module), 10);
END H2O:Parser.

