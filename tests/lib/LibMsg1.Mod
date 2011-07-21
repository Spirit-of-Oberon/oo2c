MODULE LibMsg1;

IMPORT
  Out := Out0, Msg;

TYPE
  Context* = POINTER TO ContextDesc;
  ContextDesc = RECORD
    (Msg.ContextDesc) 
  END;

CONST
  someId = 0;
  otherId = 1;
  
VAR
  context: Context;

PROCEDURE (context: Context) GetTemplate* (msg: Msg.Msg; VAR templ: Msg.LString);
  BEGIN
    IF (msg. code = someId) THEN
      COPY ("Sample template, int=${int}, string=${string}, lstring=${lstring}", templ);
    ELSE
      context. GetTemplate^ (msg, templ);
    END;
  END GetTemplate;

PROCEDURE Test* ();
  VAR
    msg: Msg.Msg;
    str: ARRAY 1024 OF CHAR;

  PROCEDURE SetAttr (msg: Msg.Msg);
    BEGIN
      msg. SetIntAttrib ("int", 123);
      msg. SetStringAttrib ("string", Msg.GetStringPtr ("my_string8"));
      msg. SetLStringAttrib ("lstring", Msg.GetLStringPtr ("my_string16"));
    END SetAttr;
  
  BEGIN
    msg := Msg.New (context, someId);
    SetAttr (msg);
    msg. GetText (str);
    Out.String ("msg1:"); Out.Ln;
    Out.String (str); Out.Ln; Out.Ln;
    
    msg := Msg.New (context, otherId);
    SetAttr (msg);
    msg. GetText (str);
    Out.String ("msg2:"); Out.Ln;
    Out.String (str); Out.Ln;
  END Test;

BEGIN
  NEW (context);
  Msg.InitContext (context, "LibMsg1");
END LibMsg1.
