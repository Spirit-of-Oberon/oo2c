MODULE Config:Section:Options;

IMPORT
  Msg, Channel, TextRider, LongStrings,
  XMLBuilder := XML:Builder, XML:DTD, XML:Locator,
  Config:Value, Config:Parser, CS := Config:Section;


TYPE
  Section* = POINTER TO SectionDesc;
  Option* = POINTER TO OptionDesc;

TYPE
  SectionDesc* = RECORD
    (CS.SectionDesc)
    optionList: Option;
    typeList-: Value.PrototypeList;
  END;
  
  OptionDesc = RECORD
    next: Option;
    name-: Value.StringPtr;
    value-: Value.Value;
  END;


CONST
  invalidContent = 1;
  invalidAttribute = 2;
  requireNameAttribute = 3;
  requireTypeAttribute = 4;
  requireCharDataContent = 5;
  optionAlreadyDefined = 6;
  optionNotDefined = 7;
  unknownType = 8;
  invalidValue = 9;
  
TYPE
  ErrorContext = POINTER TO ErrorContextDesc;
  ErrorContextDesc = RECORD  (* stateless *)
    (CS.ErrorContextDesc)
  END;

VAR
  optionsContext: ErrorContext;


PROCEDURE (context: ErrorContext) GetTemplate* (msg: Msg.Msg; VAR templ: Msg.LString);
  VAR
    t: ARRAY 128 OF Msg.LChar;
  BEGIN
    CASE msg. code OF
    | invalidContent:
      t := "Invalid content for element `${name}'"
    | invalidAttribute:
      t := "Attribute `${name}' is not defined for this element"
    | requireNameAttribute:
      t := "This element requires an attribute `name'"
    | requireTypeAttribute:
      t := "This element requires an attribute `type'"
    | requireCharDataContent:
      t := "This element must contain character data only"
    | optionAlreadyDefined:
      t := "Option `${name}' is already defined"
    | optionNotDefined:
      t := "Option `${name}' is not defined"
    | unknownType:
      t := "Type `${type}' is not supported for option variables"
    | invalidValue:
      t := "Invalid value: ${reason}"
    END;
    context. WriteTemplate (msg, t, templ)
  END GetTemplate;


PROCEDURE Init* (s: Section; id: Parser.String; typeList: Value.PrototypeList);
  BEGIN
    CS.Init (s, id);
    s. optionList := NIL;
    s. typeList := typeList
  END Init;

PROCEDURE New* (sectionName: Parser.String; typeList: Value.PrototypeList): Section;
  VAR
    s: Section;
  BEGIN
    NEW (s);
    Init (s, sectionName, typeList);
    RETURN s
  END New;

PROCEDURE InitOption (opt: Option; VAR name: Value.String; value: Value.Value);
  BEGIN
    opt. next := NIL;
    opt. name := Value.GetStringPtr (name);
    opt. value := value;
  END InitOption;

PROCEDURE NewOption (VAR name: Value.String; value: Value.Value): Option;
  VAR
    opt: Option;
  BEGIN
    NEW (opt);
    InitOption (opt, name, value);
    RETURN opt
  END NewOption;


PROCEDURE Insert (VAR list: Option; opt: Option);
  BEGIN  (* pre: opt.name^ is not used in s.optionList *)
    IF (list = NIL) THEN
      opt. next := NIL;
      list := opt
    ELSIF (list. name^ < opt. name^) THEN
      Insert (list. next, opt)
    ELSE
      opt. next := list;
      list := opt
    END
  END Insert;


PROCEDURE (opt: Option) Set* (value: Value.Value);
  BEGIN
    opt. value := value
  END Set;

PROCEDURE (s: Section) Get* (name: Value.String): Option;
  VAR
    opt: Option;
  BEGIN
    opt := s. optionList;
    WHILE (opt # NIL) & (opt. name^ # name) DO
      opt := opt. next
    END;
    RETURN opt
  END Get;

PROCEDURE (s: Section) Set* (name: Value.String; value: Value.Value): Option;
  VAR
    opt: Option;
  BEGIN
    opt := s. Get (name);
    IF (opt = NIL) THEN
      opt := NewOption (name, value);
      Insert (s. optionList, opt)
    ELSE
      opt. Set (value)
    END;
    RETURN opt
  END Set;

PROCEDURE (s: Section) GetValue* (name: Value.String): Value.Value;
  VAR
    opt: Option;
  BEGIN
    opt := s. Get (name);
    IF (opt = NIL) THEN
      RETURN NIL
    ELSE
      RETURN opt. value
    END
  END GetValue;

PROCEDURE (s: Section) Copy* (dest: Section);
  VAR
    opt, newOpt: Option;
  BEGIN
    Init (dest, s. name^, s. typeList);
    opt := s. optionList;
    WHILE (opt # NIL) DO
      newOpt := dest. Set (opt. name^, opt. value. Clone());
      opt := opt. next
    END
  END Copy;

PROCEDURE (s: Section) Clone* (): Section;
  VAR
    new: Section;
  BEGIN
    NEW (new);
    s. Copy (new);
    RETURN new
  END Clone;


PROCEDURE (s: Section) ProcessElements* (sectionRoot: Parser.Element;
                                         errorListener: Locator.ErrorListener);
  VAR
    node: Parser.Node;
    parserString: Parser.StringPtr;
    att: XMLBuilder.Attribute;
    name, type: DTD.String;
    lastError, errMsg: Msg.Msg;
    name8, type8, valueString: ARRAY 1024 OF CHAR;
    newValue: Value.Value;
    option: Option;
    i: LONGINT;
    
  PROCEDURE Err (code: Msg.Code; xmlNode: Parser.Node);
    BEGIN
      lastError := errorListener. Error (optionsContext, code, FALSE, xmlNode. pos)
    END Err;
  
  BEGIN
    node := sectionRoot. content;
    WHILE (node # NIL) DO
      WITH node: Parser.Element DO
        IF (node. name^ = "set") THEN
          name := NIL;
          FOR i := 0 TO node. attrList. len-1 DO
            att := node. attrList. attr[i];
            IF (att. localName^ = "name") THEN
              name := att. value. Flatten (att. attrDecl)
            ELSE
              Err (invalidAttribute, node);
              lastError. SetLStringAttrib ("name", Msg.GetLStringPtr (att. localName^))
            END
          END;
          
          IF (name = NIL) THEN
            Err (requireNameAttribute, node)
          ELSIF ~node. HasNoElementContent() THEN
            Err (requireCharDataContent, node)
          ELSE
            LongStrings.Short (name^, "?", name8);
            option := s. Get (name8);
            IF (option = NIL) THEN
              Err (optionNotDefined, node);
              lastError. SetLStringAttrib ("name", Msg.GetLStringPtr (name^))
            ELSE
              parserString := node. GetCharDataContent();
              (* ... get rid of this Short() once Value.String and
                 XML.String are the same *)
              LongStrings.Short (parserString^, "?", valueString);
              option. value. StringToValue (valueString, errMsg);
              IF (errMsg = NIL) THEN
                (*s. Set (name8, option. value)  this is a noop *)
              ELSE
                Err (invalidValue, node);
                lastError. SetMsgAttrib ("reason", errMsg)
              END
            END
          END
          
        ELSIF (node. name^ = "define") THEN
          name := NIL; type := NIL;
          FOR i := 0 TO node. attrList. len-1 DO
            att := node. attrList. attr[i];
            IF (att. localName^ = "name") THEN
              name := att. value. Flatten (att. attrDecl)
            ELSIF (att. localName^ = "type") THEN
              type := att. value. Flatten (att. attrDecl)
            ELSE
              Err (invalidAttribute, node);
              lastError. SetLStringAttrib ("name", Msg.GetLStringPtr (att. localName^))
            END
          END;
          
          IF (name = NIL) THEN
            Err (requireNameAttribute, node)
          ELSIF (type = NIL) THEN
            Err (requireTypeAttribute, node)
          ELSIF ~node. HasNoElementContent() THEN
            Err (requireCharDataContent, node)
          ELSE
            LongStrings.Short (name^, "?", name8);
            IF (s. Get (name8) # NIL) THEN
              Err (optionAlreadyDefined, node);
              lastError. SetLStringAttrib ("name", Msg.GetLStringPtr (name^))
            ELSE
              LongStrings.Short (type^, "?", type8);
              newValue := s. typeList. GetClone (type8);
              IF (newValue = NIL) THEN
                Err (unknownType, node);
                lastError. SetLStringAttrib ("type", Msg.GetLStringPtr (type^))
              ELSE
                parserString := node. GetCharDataContent();
                (* ... get rid of this Short() once Value.String and
                   XML.String are the same *)
                LongStrings.Short (parserString^, "?", valueString);
                newValue. StringToValue (valueString, errMsg);
                IF (errMsg = NIL) THEN
                  option := s. Set (name8, newValue)
                ELSE
                  Err (invalidValue, node);
                  lastError. SetMsgAttrib ("reason", errMsg)
                END
              END
            END
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
    opt: Option;
    str8: ARRAY 2048 OF CHAR;
  BEGIN
    w := TextRider.ConnectWriter (ch);
    LongStrings.Short (s. name^, "?", str8);
    w. WriteString ("<");
    w. WriteString (str8);
    w. WriteString (">"); w. WriteLn;
    opt := s. optionList;
    WHILE (opt # NIL) DO
      w. WriteString ("  <value name='");
      w. WriteString (opt. name^);
      w. WriteString ("' defining_module='");
      opt. value. DefiningModule (str8);
      w. WriteString (str8);
      w. WriteString ("'>");
      
      opt. value. ValueToString (str8);
      w. WriteString (str8);
      
      w. WriteString ("</value>");
      w. WriteLn;
      opt := opt. next
    END;
    LongStrings.Short (s. name^, "?", str8);
    w. WriteString ("</");
    w. WriteString (str8);
    w. WriteString (">"); w. WriteLn
  END DumpContent;

BEGIN
  NEW (optionsContext);
  Msg.InitContext (optionsContext, "Config:Section:Options");
END Config:Section:Options.
