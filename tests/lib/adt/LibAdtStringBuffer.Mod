MODULE LibAdtStringBuffer;

IMPORT 
  O := ADT:Object,
  S := ADT:String,
  B := ADT:StringBuffer,
  Out := Out0;

TYPE
  MyObject = POINTER TO MyObjectDesc;
  MyObjectDesc = RECORD (O.ObjectDesc)
  END;

VAR
  a : S.String;
  b : B.StringBuffer;
  m : MyObject;

PROCEDURE OutString(s : S.String);
BEGIN
  Out.String(s.array^);
END OutString;

PROCEDURE Test* ();
  BEGIN
    (* Append various primitive types *)
    a := S.New("");
    b := B.New("");
    Out.Bool(a.Equals(b)); Out.Ln;
    b.AppendString("Text String,");
    b.Append(S.New("String Object,"));
    b.AppendSet({1, 3, 5, 7});
    b.AppendLongInt(1234567);
    b.AppendBool(TRUE);
    b.AppendObject(b.ToString());
    b.AppendLongInt(b.Size());
    OutString(b.ToString()); Out.Ln;
    
    (* Delete *)
    b.Delete(1, 5);
    OutString(b.ToString()); Out.Ln;
    
    (* AppendObject *)
    NEW(m);
    b := B.New("");
    b.AppendObject(NIL);
    b.AppendString(",");
    b.AppendObject(b);
    b.AppendString(",");
    (*b.AppendObject(m); omitted, because the memory address is not constant *)
    OutString(b.ToString()); Out.Ln;
  END Test;

END LibAdtStringBuffer.
