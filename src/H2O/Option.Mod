MODULE H2O:Option;

IMPORT Object, ADT:ArrayList, H2O:Value, Log, TextRider;

TYPE
  Option* = POINTER TO OptionDesc;
  OptionDesc = RECORD [ABSTRACT] (Object.ObjectDesc)
    name- : STRING;
  END;

  String* = POINTER TO StringDesc;
  StringDesc = RECORD (OptionDesc)
    value* : STRING;
  END;

  StringList* = POINTER TO StringListDesc;
  StringListDesc = RECORD (OptionDesc)
    value* : ArrayList.ArrayList(STRING);
  END;

  Boolean* = POINTER TO BooleanDesc;
  BooleanDesc = RECORD (OptionDesc) 
    value* : BOOLEAN;
  END;

  Options* = POINTER TO OptionsDesc;
  OptionsDesc = RECORD
    options- : ArrayList.ArrayList(Option);
  END;

PROCEDURE IsList* (o : Option) : BOOLEAN;
BEGIN
  RETURN o IS StringList;
END IsList;

PROCEDURE (o : Option) [ABSTRACT] Set* (value : Value.Object) : BOOLEAN;
END Set;

PROCEDURE (o : Option) [ABSTRACT] Write* (wr : TextRider.Writer);
END Write;

PROCEDURE (b : Boolean) INIT* (name : STRING; default : BOOLEAN);
BEGIN
  b.name := name;
  b.value := default;
END INIT;

PROCEDURE (b : Boolean) Set* (value : Value.Object) : BOOLEAN;
BEGIN
  WITH value : Value.Boolean DO
    b.value := value.value;
    RETURN TRUE;
  ELSE
    RETURN FALSE;
  END;
END Set;

PROCEDURE (b : Boolean) Write* (wr : TextRider.Writer);
BEGIN
  wr.WriteBool(b.value);
END Write;

PROCEDURE (b : String) INIT* (name : STRING; default : STRING);
BEGIN
  b.name := name;
  b.value := default;
END INIT;

PROCEDURE (b : String) Set* (value : Value.Object) : BOOLEAN;
BEGIN
  WITH value : Value.String DO
    b.value := value.value;
    RETURN TRUE;
  ELSE
    RETURN FALSE;
  END;
END Set;

PROCEDURE (s : String) Write* (wr : TextRider.Writer);
BEGIN
  wr.WriteString('"');
  wr.WriteObject(s.value);
  wr.WriteString('"');
END Write;

PROCEDURE (l : StringList) INIT* (name : STRING);
BEGIN
  l.name := name;
  l.value := NEW(ArrayList.ArrayList(STRING), 10);
END INIT;

PROCEDURE (l : StringList) Set* (value : Value.Object) : BOOLEAN;
BEGIN
  WITH value : Value.String DO
    l.value.Append(value.value);
    RETURN TRUE
  ELSE
    RETURN FALSE
  END
END Set;

PROCEDURE (l : StringList) Write* (wr : TextRider.Writer);
VAR i : LONGINT;
BEGIN
  FOR i := 0 TO l.value.Size()-1 DO
    IF i # 0 THEN wr.WriteString(", ") END;
    wr.WriteString('"'); wr.WriteObject(l.value.Get(i)); wr.WriteString('"');
  END;
END Write;

PROCEDURE (l : StringList) Contains* (value : STRING) : BOOLEAN;
VAR 
  i : LONGINT;
  string : STRING;
BEGIN
  FOR i := 0 TO l.value.Size() - 1 DO
    string := l.value.Get(i);
    IF string.Equals(value) THEN RETURN TRUE END;
  END;
  RETURN FALSE;
END Contains;

PROCEDURE (l : StringList) IsPrefix* (value : STRING; VAR base : STRING) : BOOLEAN;
VAR 
  i : LONGINT;
  prefix : STRING;
BEGIN
  FOR i := 0 TO l.value.Size() -1 DO
    prefix := l.value.Get(i);
    IF value.StartsWith(prefix) THEN
      base := value.Substring(prefix.length, value.length);
      RETURN TRUE;
    END;
  END;
  RETURN FALSE;
END IsPrefix;

PROCEDURE (o : Options) Append* (op : Option);
BEGIN
  o.options.Append(op);
END Append;

PROCEDURE (o : Options) Boolean* (name : STRING; default : BOOLEAN) : Boolean;
VAR b : Boolean;
BEGIN
  b := NEW(Boolean, name, default);
  o.Append(b);
  RETURN b;
END Boolean;

PROCEDURE (o : Options) String* (name : STRING; default : STRING) : String;
VAR s : String;
BEGIN
  s := NEW(String, name, default);
  o.Append(s);
  RETURN s;
END String;

PROCEDURE (o : Options) StringList* (name : STRING) : StringList;
VAR s : StringList;
BEGIN
  s := NEW(StringList, name);
  o.Append(s);
  RETURN s;
END StringList;

PROCEDURE (o : Options) Find* (name : STRING) : Option;
VAR 
  i : LONGINT;
  op : Option;
BEGIN
  FOR i := 0 TO o.options.Size()-1 DO
    op := o.options.Get(i);
    IF op.name.Equals(name) THEN RETURN op END;
  END;
  RETURN NIL;
END Find;

PROCEDURE (o : Options) Merge* (set : Options);
VAR 
  i : LONGINT;
  op : Option;
BEGIN
  FOR i := 0 TO set.options.Size()-1 DO
    op := set.options.Get(i);
    IF o.Find(op.name) # NIL THEN
      Log.Object("Options:Merge duplicate name", op.name);
    ELSE
      o.Append(op);
    END;
  END;
END Merge;

PROCEDURE (o : Options) INIT* ;
BEGIN
  o.options := NEW(ArrayList.ArrayList(Option), 10);
END INIT;

PROCEDURE (o : Options) Write* (wr : TextRider.Writer);
VAR i : LONGINT; opt : Option;
BEGIN
  FOR i := 0 TO o.options.Size()-1 DO
    opt := o.options.Get(i);
    wr.WriteString("  ");
    wr.WriteObject(opt.name);
    wr.WriteString(" = ");
    opt.Write(wr);
    wr.WriteString(";");
    wr.WriteLn;
  END;
END Write;

END H2O:Option.
