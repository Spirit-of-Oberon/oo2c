MODULE Config:Parser;

IMPORT
  Channel, Msg, LongStrings,
  XML:EntityResolver, XMLBuilder := XML:Builder, XML:DTD, XML:Error,
  Locator := XML:Locator, XMLParser := XML:Parser,
  <*PUSH; Warnings:=FALSE*>XML:UnicodeCodec:Latin1<*POP*>;
  (*note: the `Latin1' module is imported to add the codec to the program *)


TYPE
  Char* = DTD.Char;
  String* = ARRAY OF DTD.Char;
  StringPtr* = DTD.String;
  Element* = POINTER TO ElementDesc;

TYPE
  Node* = POINTER TO NodeDesc;
  NodeDesc = RECORD
    nextNode-: Node;
    pos-: Locator.Position;
    parent: Element;
  END;

TYPE
  CharData* = POINTER TO CharDataDesc;
  CharDataDesc = RECORD
    (NodeDesc)
    string-: StringPtr;
  END;

TYPE
  ElementDesc = RECORD
    (NodeDesc)
    name-: StringPtr;
    attrList-: XMLBuilder.AttributeList;
    content-: Node;
    contentTail: Node;
  END;

TYPE
  Builder = POINTER TO BuilderDesc;
  BuilderDesc = RECORD
    (XMLBuilder.BuilderDesc)
    l: Locator.Locator;
    errorListener: Locator.ErrorListener;
    root: Element;
    stack: Element;
    
    currElement: DTD.String;             (* name of current start tag *)
    currPos: Locator.Position;
    currAttrList: XMLBuilder.AttributeList;
  END;

TYPE
  Parser* = POINTER TO ParserDesc;
  ParserDesc = RECORD
    xmlParser: XMLParser.Parser;
    builder: Builder;
    errList-: Error.List;
    root-: Element;
    errorListener-: Locator.ErrorListener;
  END;

TYPE
  Resolver* = POINTER TO ResolverDesc;
  ResolverDesc = RECORD
    (EntityResolver.ResolverDesc)
  END;


PROCEDURE InitBuilder (b: Builder);
  BEGIN
    b. l := NIL;
    b. stack := NIL;
    b. root := NIL;
    
    b. currElement := NIL;
    b. currAttrList := NIL;
  END InitBuilder;

PROCEDURE NewBuilder (): Builder;
  VAR
    b: Builder;
  BEGIN
    NEW (b);
    InitBuilder (b);
    RETURN b
  END NewBuilder;

PROCEDURE InitNode (node: Node; parent: Element;
                    l: Locator.Locator; VAR pos: Locator.Position);
  BEGIN
    node. parent := parent;
    node. nextNode := NIL;
    IF (l = NIL) THEN
      node. pos := pos
    ELSE
      node. pos := l^
    END
  END InitNode;

PROCEDURE InitElement (e: Element; parent: Element; VAR pos: Locator.Position;
                       name: StringPtr;
                       attrList: XMLBuilder.AttributeList);
  BEGIN
    InitNode (e, parent, NIL, pos);
    e. name := name;
    e. attrList := attrList;
    e. content := NIL;
    e. contentTail := NIL;
  END InitElement;

PROCEDURE NewElement (parent: Element; VAR pos: Locator.Position;
                      name: StringPtr;
                      attrList: XMLBuilder.AttributeList): Element;
  VAR
    e: Element;
  BEGIN
    NEW (e);
    InitElement (e, parent, pos, name, attrList);
    RETURN e
  END NewElement;

PROCEDURE InitCharData (charData: CharData; parent: Element;
                        l: Locator.Locator; str: DTD.String);
  VAR
    pos: Locator.Position;
  BEGIN
    InitNode (charData, parent, l, pos);
    charData. string := str
  END InitCharData;

PROCEDURE NewCharData (parent: Element; l: Locator.Locator;
                       str: DTD.String): CharData;
  VAR
    charData: CharData;
  BEGIN
    NEW (charData);
    InitCharData (charData, parent, l, str);
    RETURN charData
  END NewCharData;


PROCEDURE (b: Builder) SetLocator* (l: Locator.Locator);
  BEGIN
    b. l := l
  END SetLocator;

PROCEDURE (b: Builder) SetErrorListener* (errorListener: Locator.ErrorListener);
  BEGIN
    b. errorListener := errorListener
  END SetErrorListener;


PROCEDURE (b: Builder) StartElement* (namespaceURI: DTD.NamespaceDeclaration;
                                      localName: DTD.String);
  BEGIN
    b. currElement := localName;
    b. currPos := b. l^;
    b. currAttrList := XMLBuilder.NewAttributeList();
  END StartElement;

PROCEDURE (b: Builder) Attribute* (namespaceURI: DTD.NamespaceDeclaration;
                                   localName: DTD.String;
                                   attrDecl: DTD.AttrDecl;
                                   value: DTD.AttValue;
                                   specified: BOOLEAN);
  BEGIN
    b. currAttrList. Append (
      XMLBuilder.NewAttribute (namespaceURI, localName, attrDecl,
                               value, specified, b. l))
  END Attribute;

PROCEDURE (b: Builder) AttributesDone*;
  VAR
    element: Element;
  BEGIN
    element := NewElement (b. stack, b. currPos, b. currElement,
                           b. currAttrList);
    IF (b. stack = NIL) THEN
      b. root := element;
      b. stack := element
    ELSE  (* append to content of current element *)
      IF (b. stack. content = NIL) THEN
        b. stack. content := element
      ELSE
        b. stack. contentTail. nextNode := element
      END;
      b. stack. contentTail := element
    END;
    b. stack := element
  END AttributesDone;

PROCEDURE (b: Builder) EndElement* (namespaceURI: DTD.NamespaceDeclaration; 
                                    localName: DTD.String);

  BEGIN
    IF (b. stack # NIL) & (b. stack. name^ = localName^) THEN
      b. stack := b. stack. parent
    END
  END EndElement;

PROCEDURE (b: Builder) Characters* (VAR chars: DTD.StringVar;
                                    charsStart, charsEnd: DTD.CharPos;
                                    elementWhitespace: DTD.ElementWhitespaceType);
  VAR
    charData: CharData;
    ptr: DTD.String;
    len, i: LONGINT;
  BEGIN
    IF (b. stack # NIL) THEN
      len := charsEnd-charsStart;
      NEW (ptr, len+1);
      FOR i := 0 TO len-1 DO
        ptr[i] := chars[i+charsStart]
      END;
      ptr[len] := 0X;
      
      charData := NewCharData (b. stack, b. l, ptr);
      IF (b. stack. content = NIL) THEN
        b. stack. content := charData
      ELSE
        b. stack. contentTail. nextNode := charData
      END;
      b. stack. contentTail := charData
    END
 END Characters;



PROCEDURE NewFile* (filePath: ARRAY OF CHAR; VAR res: Msg.Msg): Parser;
  VAR
    p: Parser;
  BEGIN
    NEW (p);
    p. builder := NewBuilder();
    p. xmlParser := XMLParser.NewFile (filePath, NIL, NIL, NIL,
                                       p. builder, res);
    RETURN p
  END NewFile;

PROCEDURE NewChannel* (ch: Channel.Channel): Parser;
  VAR
    p: Parser;
  BEGIN
    NEW (p);
    p. builder := NewBuilder();
    p. xmlParser := XMLParser.NewChannel (ch, NIL, NIL, NIL, p. builder);
    RETURN p
  END NewChannel;

PROCEDURE (p: Parser) ParseDocument*;
  BEGIN
    p. xmlParser. ParseDocument();
    p. root := p. builder. root;
    p. errorListener := p. builder. errorListener;
    p. errList := p. xmlParser. errList;
  END ParseDocument;


PROCEDURE (node: Node) IsWhitespace*(): BOOLEAN;
  VAR
    i: LONGINT;
    str: StringPtr;
  BEGIN
    WITH node: Element DO
      RETURN FALSE
    | node: CharData DO
      str := node. string;
      i := 0;
      WHILE (str[i] # 0X) & (str[i] <= " ") DO
        INC (i)
      END;
      RETURN (str[i] = 0X)
    END
  END IsWhitespace;
  
PROCEDURE (node: Node) HasNoElementContent* (): BOOLEAN;
  VAR
    ptr: Node;
  BEGIN
    WITH node: Element DO
      ptr := node. content;
      WHILE (ptr # NIL) DO
        IF (ptr IS Element) THEN
          RETURN FALSE
        END;
        ptr := ptr. nextNode
      END;
      RETURN TRUE
    | node: CharData DO
      RETURN TRUE
    END
  END HasNoElementContent;

PROCEDURE (node: Node) IsEmpty* (): BOOLEAN;
  BEGIN
    WITH node: Element DO
      RETURN (node. content = NIL)
    | node: CharData DO
      RETURN (node. string^ = "")
    END
  END IsEmpty;


PROCEDURE (node: Node) GetCharDataContent* (): StringPtr;
  VAR
    ptr: Node;
    str: StringPtr;
    len: LONGINT;
  BEGIN
    WITH node: Element DO
      len := 0;
      ptr := node. content;
      WHILE (ptr # NIL) DO
        WITH ptr: CharData DO
          INC (len, LongStrings.Length (ptr. string^))
        ELSE
          RETURN NIL
        END;
        ptr := ptr. nextNode
      END;
      
      NEW (str, len+1);
      COPY ("", str^);
      ptr := node. content;
      WHILE (ptr # NIL) DO
        LongStrings.Append (ptr(CharData). string^, str^);
        ptr := ptr. nextNode
      END;
      
      RETURN str
    | node: CharData DO
      RETURN node. string
    END
  END GetCharDataContent;

END Config:Parser.
