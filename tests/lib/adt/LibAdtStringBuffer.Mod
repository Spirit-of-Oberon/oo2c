MODULE LibAdtStringBuffer;

IMPORT 
  Object,
  B := ADT:StringBuffer,
  Out := Out0;

TYPE
  MyObject = POINTER TO MyObjectDesc;
  MyObjectDesc = RECORD (Object.ObjectDesc)
  END;

VAR
  a : Object.String8;
  b : B.StringBuffer;
  m : MyObject;

PROCEDURE OutString(s : Object.String);
  VAR
    chars: Object.CharsLatin1;
  BEGIN
    chars := s(Object.String8).CharsLatin1();
    Out.String(chars^);
  END OutString;

PROCEDURE Test* ();
  BEGIN
    (* Append various primitive types *)
    a := Object.NewLatin1("");
    b := B.New("");
    Out.Bool(a.Equals(b)); Out.Ln;
    b.Append("Text String,");
    b.Append(Object.NewLatin1("String Object,"));
    b.AppendSet({1, 3, 5, 7});
    b.AppendInt(1234567);
    b.AppendBool(TRUE);
    b.Append(b.ToString());
    b.AppendInt(b.length);
    OutString(b.ToString()); Out.Ln;
    
    (* Delete *)
    b.Delete(1, 1+5);
    OutString(b.ToString()); Out.Ln;
    
    (* AppendObject *)
    NEW(m);
    b := B.New("");
    b.Append(NIL);
    b.Append(",");
    b.Append(b);
    b.Append(",");
    (*b.Append(m); omitted, because the memory address is not constant *)
    OutString(b.ToString()); Out.Ln;
  END Test;

END LibAdtStringBuffer.
