MODULE H2O:Variant;

IMPORT 
  H2O:Type, ADT:ArrayList, Object, ADT:StringBuffer, StringSearch, Log;

CONST
  array* = 0;
  var* = 1;
  pointer* = 2;
  set* = 3;
  default* = 4;
  emitted* = 5;
  cstring* = 6;
  defined* = 7;

  debugMatch = FALSE;
VAR 
  rules- : ArrayList.ArrayList(Op);

TYPE
  Op* = POINTER TO OpDesc;
  OpDesc* = RECORD [ABSTRACT] (Object.ObjectDesc)
    variant* : SET;
    next* : Op;
  END;

  FieldOp* = POINTER TO FieldOpDesc;
  FieldOpDesc = RECORD (OpDesc)
    name* : STRING;
    matcher* : StringSearch.Matcher;
  END;

  IndexOp* = POINTER TO IndexOpDesc;
  IndexOpDesc = RECORD (OpDesc)
    index* : LONGINT;
  END;

  RefOp* = POINTER TO RefOpDesc;
  RefOpDesc* = RECORD (OpDesc) 
  END;

PROCEDURE (o : Op) [ABSTRACT] Match* (type : Type.Type);
END Match;

PROCEDURE (o : Op) MatchedOp(t : Type.Type; obj : Type.Object; par : BOOLEAN);
VAR 
  apply : BOOLEAN;
  variant : SET;
BEGIN
  IF o.next # NIL THEN
    o.next.Match(t);
  ELSE
    variant := o.variant;
    CASE t.class OF
    | Type.tPointer, Type.tArray:
      IF par THEN 
        apply := variant = variant * { array, var, pointer, cstring, default };
      ELSE
        apply := variant = variant * { array, pointer, cstring, default };
      END;
    | Type.tInteger, Type.tUnsigned:
        apply := variant = variant * { set, default };
    | Type.tQualifier, Type.tName:
        o.MatchedOp(t.base, obj, par);
        apply := FALSE;
    ELSE
      apply := FALSE
    END;
  
    IF apply THEN
  IF debugMatch THEN Log.Object("MatchedOpApply", t);
  Log.Set("MatchedOpApply", variant); END;
      IF (obj # NIL) THEN
        obj .variant := obj .variant + variant * { var } + {defined};
      END;
      t.variant := t.variant + variant * { array, pointer, cstring, default } + { defined};
    END
  END;
END MatchedOp;

PROCEDURE (o : Op) INIT*;
BEGIN
  o.next := NIL;
  o.variant := {};
END INIT;

PROCEDURE (o : FieldOp) MatchElement* (obj : Type.Object; var : BOOLEAN);
VAR match : BOOLEAN;
BEGIN
  WHILE obj # NIL DO
    IF debugMatch THEN Log.Object("Element", obj.name); END;
    IF (o.matcher # NIL) THEN
      match := o.matcher.Match(obj.name(Object.String8), 0, -1) # NIL;
    ELSE 
      match := o.name.Equals(obj.name);
    END;
    IF match THEN
      o.MatchedOp(obj.type, obj, var);
    END;
    obj := obj.next;
  END;
END MatchElement; 

PROCEDURE (o : FieldOp) Match* (type : Type.Type);
BEGIN
  CASE type.class OF
  | Type.tStruct, Type.tUnion, Type.tFunction:
    o.MatchElement(type.link, type.class = Type.tFunction);
  ELSE
  END;
END Match;

PROCEDURE (o : FieldOp) INIT*(name : STRING; matcher : StringSearch.Matcher);
BEGIN
  o.INIT^();
  o.name := name;
  o.matcher := matcher;
END INIT;

PROCEDURE (o : IndexOp) Match* (type : Type.Type);
VAR obj : Type.Object;
BEGIN
  CASE type.class OF
  | Type.tArray:
    IF o.index < 0 THEN 
      o.MatchedOp(type.base, NIL, FALSE);
    END;
  | Type.tFunction:
    IF (o.index >= 0) & Type.FindObjectIndex(type.link, o.index, obj) THEN
      o.MatchedOp(obj.type, obj, TRUE);
    END;
  ELSE
  END;
END Match;

PROCEDURE (o : IndexOp) INIT*(index : LONGINT);
BEGIN 
  o.INIT^();
  o.index := index;
END INIT;
 
PROCEDURE (o : RefOp) Match* (type : Type.Type);
BEGIN
  CASE type.class OF
  | Type.tPointer:
    o.MatchedOp(type.base, NIL, FALSE);
  ELSE
  END;
END Match;

PROCEDURE (o : RefOp) INIT*;
BEGIN
  o.INIT^;
END INIT;

PROCEDURE ToString* (op : Op) : STRING;
VAR 
  buf : StringBuffer.StringBuffer;
  last : Op;
BEGIN
  last := NIL;
  buf := StringBuffer.New("");
  WHILE op # NIL DO
    WITH op : RefOp DO
      buf.AppendLatin1Char("^");
    | op : FieldOp DO
      buf.AppendLatin1Char(".");
      buf.Append(op.name);
    | op : IndexOp DO
      buf.AppendLatin1Char("[");
      IF op.index >= 0 THEN
        buf.AppendInt(op.index);
      END;
      buf.AppendLatin1Char("]");
    END;
    last := op;
    op := op.next;
  END;
  IF last # NIL THEN
    buf.AppendLatin1(" : ");
    buf.AppendSet(last.variant);
  END;
  RETURN buf.ToString();
END ToString;

PROCEDURE AddRule* (op : Op);
BEGIN
  IF debugMatch THEN Log.Object("AddRule", ToString(op)); END;
  rules.Append(op);
END AddRule;

PROCEDURE ApplyRules* (obj : Type.Object);
VAR 
  i : LONGINT;
  rule : Op;
  name : STRING;
BEGIN
  IF debugMatch THEN Log.Object("Name", obj.name); END;
  FOR i := 0 TO rules.Size() - 1 DO
    rule := rules.Get(i);
    IF debugMatch THEN Log.Object("Rule", ToString(rule)); END;
    WITH rule : FieldOp DO
      rule.MatchElement(obj, FALSE);
    END;
  END;
END ApplyRules;

BEGIN
  rules := NEW(ArrayList.ArrayList(Op),10);
END H2O:Variant.
