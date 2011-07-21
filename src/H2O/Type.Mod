MODULE H2O:Type;

IMPORT
  Obj := Object, ADT:StringBuffer, ADT:ArrayList,
  H2O:Module;

CONST 
  (* Object classes *)
  scNone* = 0;
  scStatic* = 1;
  scTypedef* = 2;
  scExtern* = 3;

  (* Type qualifiers *)
  tqVolatile* = 0;
  tqConst* = 1;
  tqCdecl* = 2;
  tqStdcall* = 3;
  tqClass* = 4;

  (* types *)

  tInteger * = 1;
  tUnsigned * = 2;
  tReal * = 3;
  tPointer * = 4;
  tArray * = 5;
  tVoid * = 6;
  tEnum * = 7;
  tFunction * = 8;
  tStruct * = 9;
  tUnion * = 10;
  tQualifier * = 11;
  tName * = 12;
  
 TYPE
  Type* = POINTER TO TypeDesc;
  Object* = POINTER TO ObjectDesc;

  TypeDesc* = RECORD (Obj.ObjectDesc)
    class* : SHORTINT;		(* see tXXX above *)
    size* : LONGINT;
    base* : Type;
    link* : Object;
    name* : STRING;
    qualifiers* : SET;
    module* : Module.Module;
  END;

  ObjectDesc* = RECORD 
    name* : STRING;
    addr* : LONGINT;
    type* : Type;
    qualifiers* : SET;
    next* : Object;
  END;

VAR
  intType-, unsignedIntType-,
  shortType-, unsignedShortType-,
  longType-, unsignedLongType-,
  longLongType-, unsignedLongLongType-,
  floatType-, doubleType-, longDoubleType-,
  charType-, unsignedCharType-, voidType- : Type;

CONST
  pointerSize* = 4;

PROCEDURE (t : Type) IsConstructor() : BOOLEAN;
BEGIN
  CASE t.class OF
  tFunction,
  tEnum, 
  tStruct, tUnion,
  tArray,
  tPointer:
    RETURN TRUE;
  ELSE
    RETURN FALSE;
  END;
END IsConstructor;

PROCEDURE (t : Type) Depend* (list : ArrayList.ArrayList);

  PROCEDURE Accumulate(module : Module.Module);
  BEGIN
    IF (module # NIL) & ~list.Contains(module) THEN
      list.Append(module);
    END;
  END Accumulate;

  PROCEDURE Visit(t : Type);
  VAR o : Object;
  BEGIN
    IF t.module # NIL THEN
      Accumulate(t.module);
    ELSE
      CASE t.class OF
      | tFunction, tArray, tPointer, tName:
        Visit(t.base);
      ELSE
      END;

      CASE t.class OF
      | tStruct, tUnion, tFunction:
        o := t.link;
        WHILE o # NIL DO
          Visit(o.type); 
          o := o.next
        END
      ELSE
      END
    END
  END Visit;

BEGIN
  list.Clear;
  Visit(t);
END Depend;

PROCEDURE (t : Type) ToString* () : STRING;
VAR
  b : StringBuffer.StringBuffer;
  o : Object;
BEGIN
  b := StringBuffer.New("");
  CASE t.class OF
  | tArray:
    b.Append(t.base); b.AppendLatin1Char("[");
    IF t.size >= 0 THEN b.AppendInt(t.size) END;
    b.AppendLatin1Char("]");
  | tPointer:
    b.Append(t.base); b.AppendLatin1Char("*");
  | tFunction:
    b.Append(t.base);
    b.AppendLatin1Char("(");
    o := t.link;
    WHILE o # NIL DO
      b.Append(o.type);
      o := o.next;
      IF o # NIL THEN b.AppendLatin1Char(",") END;
    END;
    b.AppendLatin1Char(")");
  | tStruct:
    b.Append("struct ");
    IF t.name # NIL THEN b.Append(t.name) END;
  | tUnion:
    b.Append("union ");
    IF t.name # NIL THEN b.Append(t.name) END;
  | tEnum:
    b.Append("enum ");
    IF t.name # NIL THEN b.Append(t.name) END;
  | tQualifier:
    IF tqVolatile IN t.qualifiers THEN
      b.Append("volatile ");
    END;
    IF tqConst IN t.qualifiers THEN
      b.Append("const ");
    END;
    b.Append(t.base);
  | tName:
    b.Append(t.name);
  ELSE
    IF t.name # NIL THEN b.Append(t.name) ELSE b.Append("?TYPE?") END;
  END;
  RETURN b.ToString();
END ToString;

PROCEDURE FindObject* (s : Object; name : STRING; VAR result : Object) : BOOLEAN;
BEGIN
  WHILE s # NIL DO
    IF name.Equals(s.name) THEN
      result := s;
      RETURN TRUE;
    END;
    s := s.next;
  END;
  RETURN FALSE;
END FindObject;

PROCEDURE AppendObject* (VAR s : Object; elem : Object);
VAR e : Object;
BEGIN
  elem.next := NIL;
  IF s = NIL THEN
    s := elem;
  ELSE
    e := s;
    WHILE e.next # NIL DO e := e.next END;
    e.next := elem;
  END;
END AppendObject;

PROCEDURE NewObject* (name : STRING; addr : LONGINT; type : Type) : Object;
VAR o : Object;
BEGIN
  NEW(o);
  o.name := name;
  o.addr := addr;
  o.type := type;
  o.qualifiers := {};
  o.next := NIL;
  RETURN o;
END NewObject;

PROCEDURE Bind* (VAR s : Object; name : STRING; addr : LONGINT; type : Type);
BEGIN
  AppendObject(s, NewObject(name, addr, type));
END Bind;

PROCEDURE NewType* (class : SHORTINT; base : Type; size : LONGINT; qual : SET) : Type;
VAR t : Type;
BEGIN
  NEW(t);
  t.class := class;
  t.base := base;
  t.size := size;
  t.link := NIL;
  t.name := NIL;
  t.qualifiers := qual;
  t.module := NIL;

  RETURN t;
END NewType;

PROCEDURE BaseType* (class : SHORTINT; size : LONGINT; name : ARRAY OF CHAR) : Type;
VAR t : Type;
BEGIN
  t := NewType(class, NIL, size, {});
  t.name := Obj.NewLatin1(name);
  RETURN t;
END BaseType;

BEGIN
  charType := BaseType(tInteger, 1, "char");  
  unsignedCharType := BaseType(tUnsigned, 1, "unsigned char");
  shortType := BaseType(tInteger, 2, "short");
  unsignedShortType := BaseType(tUnsigned, 2, "unsigned short");
  longType := BaseType(tInteger, 4, "long");
  unsignedLongType := BaseType(tUnsigned, 4, "unsigned long");
  longLongType := BaseType(tInteger, 8, "long long");
  unsignedLongLongType := BaseType(tUnsigned, 8, "unsigned long long");
  intType := longType; unsignedIntType := unsignedLongType;
  floatType := BaseType(tReal, 4, "float");
  doubleType := BaseType(tReal, 8, "double");
  longDoubleType := BaseType(tReal, 8, "long double");
  voidType := BaseType(tVoid, 0, "void");
END H2O:Type.

