MODULE Config:Section:Arguments;

IMPORT
  Object, Msg, Channel, TextRider, LongStrings,
  XMLBuilder := XML:Builder, XML:Locator,
  Config:Parser, CS := Config:Section;


TYPE
  Section* = POINTER TO SectionDesc;
  ArgumentArray = POINTER TO ARRAY OF STRING;
  SectionDesc = RECORD
    (CS.SectionDesc)
    args: ArgumentArray;
    argNumber: LONGINT;
  END;
  


CONST
  invalidContent = 1;
  invalidAttribute = 2;
  requireCharDataContent = 5;
  
TYPE
  ErrorContext = POINTER TO ErrorContextDesc;
  ErrorContextDesc = RECORD  (* stateless *)
    (CS.ErrorContextDesc)
  END;

VAR
  argumentsContext: ErrorContext;


PROCEDURE (context: ErrorContext) GetTemplate* (msg: Msg.Msg; VAR templ: Msg.LString);
  VAR
    t: ARRAY 128 OF Msg.LChar;
  BEGIN
    CASE msg. code OF
    | invalidContent:
      t := "Invalid content for element `${name}'"
    | invalidAttribute:
      t := "Attribute `${name}' is not defined for this element"
    | requireCharDataContent:
      t := "This element must contain character data only"
    END;
    context. WriteTemplate (msg, t, templ)
  END GetTemplate;



PROCEDURE Init (s: Section; id: Parser.String);
  BEGIN
    CS.Init (s, id);
    s. argNumber := 0;
    NEW (s. args, 4)    
  END Init;

PROCEDURE New* (sectionName: Parser.String): Section;
  VAR
    s: Section;
  BEGIN
    NEW (s);
    Init (s, sectionName);
    RETURN s
  END New;


PROCEDURE (s: Section) ArgNumber* (): LONGINT;
  BEGIN
    RETURN s. argNumber
  END ArgNumber;

PROCEDURE (s: Section) Get* (position: LONGINT): STRING;
  BEGIN
    IF (0 <= position) & (position < s. argNumber) THEN
      RETURN s.args[position];
    ELSE
      RETURN NIL
    END
  END Get;


PROCEDURE (s: Section) ProcessElements* (sectionRoot: Parser.Element;
                                         errorListener: Locator.ErrorListener);
  VAR
    node: Parser.Node;
    parserString: Parser.StringPtr;
    newArgs: ArgumentArray;
    i: LONGINT;
    att: XMLBuilder.Attribute;
    lastError: Msg.Msg;
    
  PROCEDURE Err (code: Msg.Code; xmlNode: Parser.Node);
    BEGIN
      lastError := errorListener. Error (argumentsContext, code, FALSE, xmlNode. pos)
    END Err;
  
  BEGIN
    node := sectionRoot. content;
    WHILE (node # NIL) DO
      WITH node: Parser.Element DO
        IF (node. name^ = "arg") THEN
          FOR i := 0 TO node. attrList. len-1 DO
            att := node. attrList. attr[i];
            Err (invalidAttribute, node);
            lastError. SetLStringAttrib ("name", Msg.GetLStringPtr (att. localName^))
          END;
          
          IF ~node. HasNoElementContent() THEN
            Err (requireCharDataContent, node)
          ELSE
            IF (s. argNumber = LEN (s. args^)) THEN
              NEW (newArgs, LEN (s. args^)*2);
              FOR i := 0 TO LEN (s. args^)-1 DO
                newArgs[i] := s. args[i]
              END;
              s. args := newArgs
            END;
            parserString := node. GetCharDataContent();
            s.args[s.argNumber] := Object.NewUTF16(parserString^);
            INC (s.argNumber)
          END
          
        ELSE
          Err (invalidContent, node);
          lastError. SetLStringAttrib ("name", Msg.GetLStringPtr (s. name^))
        END
        
      | node: Parser.CharData DO
        IF ~node. IsWhitespace() THEN
          Err (invalidContent, node)
        END
      END;
      node := node. nextNode
    END
  END ProcessElements;

PROCEDURE (s: Section) DumpContent* (ch: Channel.Channel);
  VAR
    w: TextRider.Writer;
    i: LONGINT;
    str8: ARRAY 2048 OF CHAR;
  BEGIN
    w := TextRider.ConnectWriter (ch);
    LongStrings.Short (s. name^, "?", str8);
    w. WriteString ("<");
    w. WriteString (str8);
    w. WriteString (">"); w. WriteLn;
    FOR i := 0 TO s. argNumber-1 DO
      w. WriteString ("  <arg>");
      w. WriteObject (s. args[i]);
      w. WriteString ("</arg>");
      w. WriteLn
    END;
    LongStrings.Short (s. name^, "?", str8);
    w. WriteString ("</");
    w. WriteString (str8);
    w. WriteString (">"); w. WriteLn
  END DumpContent;

BEGIN
  NEW (argumentsContext);
  Msg.InitContext (argumentsContext, "Config:Section:Arguments");
END Config:Section:Arguments.
