MODULE Config:Section [OOC_EXTENSIONS];

IMPORT
  Msg, Channel, LongStrings, TextRider, XML:Error, XML:Locator, Config:Parser;


TYPE
  Section* = POINTER TO SectionDesc;
  SectionDesc* = RECORD [ABSTRACT]
    name-: Parser.StringPtr;
  END;

TYPE
  Node = POINTER TO NodeDesc;
  NodeDesc = RECORD
    next: Node;
    section: Section;
  END;

TYPE
  SectionList* = POINTER TO SectionListDesc;
  SectionListDesc = RECORD
    head: Node;
  END;


CONST
  invalidRootName = 1;
  invalidRootCharData = 2;
  unknownSection = 3;
  
TYPE
  ErrorContext* = POINTER TO ErrorContextDesc;
  ErrorContextDesc* = RECORD  (* stateless *)
    (Error.ContextDesc)
  END;

VAR
  sectionContext: ErrorContext;

PROCEDURE (context: ErrorContext) GetTemplate* (msg: Msg.Msg; VAR templ: Msg.LString);
  VAR
    t: ARRAY 128 OF Msg.LChar;
  BEGIN
    CASE msg. code OF
    | invalidRootName:
      t := "Name of root element must be `${name}'"
    | invalidRootCharData:
      t := "Invalid character data in root element"
    | unknownSection:
      t := "Unknown configuration section `${name}'"
    END;
    context. WriteTemplate (msg, t, templ)
  END GetTemplate;


PROCEDURE Init* (s: Section; id: Parser.String);
  BEGIN
    NEW (s. name, LongStrings.Length (id)+1);
    COPY (id, s. name^)
  END Init;

PROCEDURE (s: Section) [ABSTRACT] ProcessElements*
                                        (sectionRoot: Parser.Element;
                                         errorListener: Locator.ErrorListener);
  END ProcessElements;

PROCEDURE (s: Section) [ABSTRACT] DumpContent* (ch: Channel.Channel);
(**Writes the content of the section to the output channel `ch'.  This is
   used for testing and debugging.  The output format is arbitrary, although
   it is suggested, that it is an XML fragment using ISO-Latin-1 encoding.  *)
  END DumpContent;


PROCEDURE NewSectionList* (): SectionList;
  VAR
    sl: SectionList;
  BEGIN
    NEW (sl);
    sl. head := NIL;
    RETURN sl
  END NewSectionList;

PROCEDURE (sl: SectionList) Add* (section: Section);
  VAR
    new: Node;
    
  PROCEDURE Insert (VAR list: Node);
    BEGIN
      IF (list = NIL) THEN               (* append to list *)
        list := new
      ELSIF (list. section. name^ = section. name^) THEN
        (* replace existing element *)
        list. section := new. section
      ELSIF (list. section. name^ > section. name^) THEN
        (* insert before element `list' *)
        new. next := list;
        list := new
      ELSE
        Insert (list. next)
      END
    END Insert;
  
  BEGIN
    NEW (new);
    new. next := NIL;
    new. section := section;
    Insert (sl. head)
  END Add;

PROCEDURE (sl: SectionList) Get* (name: Parser.StringPtr): Section;
  VAR
    sn: Node;
  BEGIN
    sn := sl. head;
    WHILE (sn # NIL) & (sn. section. name^ # name^) DO
      sn := sn. next
    END;
    IF (sn = NIL) THEN
      RETURN NIL
    ELSE
      RETURN sn. section
    END
  END Get;


PROCEDURE (sl: SectionList) ProcessElements* (root: Parser.Element;
                         rootElementName: Parser.String; p: Parser.Parser);
  VAR
    node: Parser.Node;
    s: Section;
    lastError: Msg.Msg;
    
  PROCEDURE Err (code: Msg.Code; xmlNode: Parser.Node);
    BEGIN
      lastError := p. errorListener. Error (sectionContext, code, FALSE, xmlNode. pos)
    END Err;
  
  BEGIN
    IF (root. name^ # rootElementName) THEN
      Err (invalidRootName, root);
      lastError. SetLStringAttrib ("name", Msg.GetLStringPtr (rootElementName))
    END;
    
    node := root. content;
    WHILE (node # NIL) DO
      WITH node: Parser.CharData DO
        IF ~node. IsWhitespace() THEN
          Err (invalidRootCharData, node)
        END
      | node: Parser.Element DO
        s := sl. Get (node. name);
        IF (s = NIL) THEN
          Err (unknownSection, node);
          lastError. SetLStringAttrib ("name", Msg.GetLStringPtr (node. name^))
        ELSE
          s. ProcessElements (node, p. errorListener)
        END
      END;
      node := node. nextNode
    END
  END ProcessElements;

PROCEDURE (sl: SectionList) DumpContent* (ch: Channel.Channel);
  VAR
    n: Node;
    w: TextRider.Writer;
  BEGIN
    w := TextRider.ConnectWriter (ch);
    n := sl. head;
    WHILE (n # NIL) DO
      n. section. DumpContent (ch);
      n := n. next
    END
  END DumpContent;
  
BEGIN
  NEW (sectionContext);
  Msg.InitContext (sectionContext, "Config:Section");
END Config:Section.
