MODULE Config:Section:Options;

IMPORT
  Exception, Object, Msg, Channel, TextRider, LongStrings,
  XMLBuilder := XML:Builder, XML:DTD, XML:Locator,
  Config:Value, Config:Parser, CS := Config:Section;


TYPE
  Section* = POINTER TO SectionDesc;
  Option* = POINTER TO OptionDesc;

TYPE
  SectionDesc* = RECORD
    (CS.SectionDesc)
    optionList: Option;
    typeMap-: Value.PrototypeMap;
  END;
  
  OptionDesc = RECORD
    next: Option;
    name-: STRING;
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


PROCEDURE Init* (s: Section; id: Parser.String; typeMap: Value.PrototypeMap);
  BEGIN
    CS.Init (s, id);
    s. optionList := NIL;
    s. typeMap := typeMap
  END Init;

PROCEDURE New* (sectionName: Parser.String; typeMap: Value.PrototypeMap): Section;
  VAR
    s: Section;
  BEGIN
    NEW (s);
    Init (s, sectionName, typeMap);
    RETURN s
  END New;

PROCEDURE InitOption (opt: Option; name: STRING; value: Value.Value);
  BEGIN
    opt. next := NIL;
    opt. name := name;
    opt. value := value;
  END InitOption;

PROCEDURE NewOption (name: STRING; value: Value.Value): Option;
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
    ELSIF (list.name.Compare(opt.name) < 0) THEN
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

PROCEDURE (s: Section) Get* (name: STRING): Option;
  VAR
    opt: Option;
  BEGIN
    opt := s. optionList;
    WHILE (opt # NIL) & ~opt.name.Equals(name) DO
      opt := opt. next
    END;
    RETURN opt
  END Get;

PROCEDURE (s: Section) Set* (name: STRING; value: Value.Value): Option;
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

PROCEDURE (s: Section) GetValue* (name: STRING): Value.Value;
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
    Init (dest, s. name^, s. typeMap);
    opt := s. optionList;
    WHILE (opt # NIL) DO
      newOpt := dest. Set (opt. name, opt. value. Clone());
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
    lastError: Msg.Msg;
    name8: STRING;
    newValue: Value.Value;
    option: Option;
    i: LONGINT;
    
  PROCEDURE Err (code: Msg.Code; xmlNode: Parser.Node);
    BEGIN
      lastError := errorListener. Error (optionsContext, code, FALSE, xmlNode. pos)
    END Err;

  PROCEDURE SetReason(e: Exception.Exception);
    VAR
      chars: Object.CharsLatin1;
      msg: STRING;
    BEGIN
      msg := e.GetMessage();
      chars := msg(Object.String8).CharsLatin1();
      lastError.SetStringAttrib("reason", Msg.GetStringPtr(chars^));
    END SetReason;
  
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
            option := s. Get (Object.NewUCS2(name^));
            IF (option = NIL) THEN
              Err (optionNotDefined, node);
              lastError. SetLStringAttrib ("name", Msg.GetLStringPtr (name^))
            ELSE
              parserString := node. GetCharDataContent();
              TRY
                option.value.StringToValue(Object.NewUCS2(parserString^));
              CATCH Exception.ParseError:
                Err (invalidValue, node);
                SetReason(Exception.Current());
              END;
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
            name8 := Object.NewUCS2(name^);
            IF (s. Get (name8) # NIL) THEN
              Err (optionAlreadyDefined, node);
              lastError. SetLStringAttrib ("name", Msg.GetLStringPtr (name^))
            ELSE
              newValue := Value.GetClone(s.typeMap, Object.NewUCS2(type^));
              IF (newValue = NIL) THEN
                Err (unknownType, node);
                lastError. SetLStringAttrib ("type", Msg.GetLStringPtr (type^))
              ELSE
                parserString := node. GetCharDataContent();
                TRY
                  newValue.StringToValue(Object.NewUCS2(parserString^));
                  option := s. Set (name8, newValue);
                CATCH Exception.ParseError:
                  Err (invalidValue, node);
                  SetReason(Exception.Current());
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
      w. WriteObject (opt. name);
      w. WriteString ("'>");
      
      w. WriteObject(opt.value.ValueToString());
      
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
