MODULE OOC:TestFramework:Testcases;

IMPORT
  Ch := Channel, URI, XMLError := XML:Error, XML:Locator, XML:Basic:Element,
  XML:Basic:Parser, XML:Basic:DataType, XML:Writer;


CONST
  styleAsIs* = 0;
  styleEmphasis* = 1;
  styleBold* = 2;
  styleCode* = 3;
  
TYPE
  InlineText = POINTER TO InlineTextDesc;
  InlineTextDesc = RECORD
    (Element.ElementDesc)
    style: SHORTINT;
    textList: Element.List;              (* may be empty *)
  END;

CONST
  testReject* = 0;
  testAccept* = 1;
  testError* = 2;
  testRun* = 3;
  testOutput* = 4;
  
TYPE
  Test = POINTER TO TestDesc;
  TestDesc = RECORD
    (InlineTextDesc)
    baseURI: URI.URI;
    id: ARRAY 64 OF CHAR;
    type: SHORTINT;
    file: URI.URI;
    lang: Element.String;
    output: URI.URI;
  END;

TYPE
  Testcases = POINTER TO TestcasesDesc;
  TestcasesDesc = RECORD
    (Element.ElementDesc)
    profile: Element.String;             (* may be NIL *)
    defaultLang: Element.String;
    tests: Element.List;                 (* may be empty *)
  END;

TYPE
  TestSuite* = POINTER TO TestSuiteDesc;
  TestSuiteDesc = RECORD
    (Element.ElementDesc)
    profile: Element.String;             (* may be NIL *)
    testcasesList: Element.List;         (* at least one element *)
  END;


VAR
  suiteRoot: Element.RootFactory;
  


PROCEDURE InitInlineText (inlineText: InlineText);
  BEGIN
    Element.InitElement (inlineText);
    inlineText. style := styleAsIs;
    inlineText. textList := Element.NewList();
  END InitInlineText;

PROCEDURE NewInlineText(): Element.Element;
  VAR
    inlineText: InlineText;
  BEGIN
    NEW (inlineText);
    InitInlineText (inlineText);
    RETURN inlineText
  END NewInlineText;

PROCEDURE (inlineText: InlineText) IsChildName* (localName: Element.String): BOOLEAN;
  BEGIN
    RETURN (localName^ = "em") OR
           (localName^ = "b") OR
           (localName^ = "code")
  END IsChildName;

PROCEDURE (inlineText: InlineText) NewChild* (localName: Element.String): Element.Element;
  VAR
    elem: Element.Element;
    inline: InlineText;
  BEGIN
    elem := NewInlineText();
    inline := elem(InlineText);
    IF (localName^ = "em") THEN
      inline. style := styleEmphasis
    ELSIF (localName^ = "b") THEN
      inline. style := styleBold
    ELSIF (localName^ = "code") THEN
      inline. style := styleCode
    END;
    RETURN inline
  END NewChild;
  
PROCEDURE (inlineText: InlineText) AddChild* (child: Element.Element);
  BEGIN
    inlineText. textList. Append (child)
  END AddChild;

PROCEDURE (inlineText: InlineText) MissingChild* (): Element.String;
  VAR
    elem: Element.Element;
  BEGIN
    elem := inlineText. textList. head;
    WHILE (elem # NIL) DO
      WITH elem: Element.PCData DO
        elem. Normalize (FALSE, FALSE)
      ELSE                               (* already normalized *)
      END;
      elem := elem. next
    END;
    RETURN NIL
  END MissingChild;

PROCEDURE (inlineText: InlineText) HasMixedContent*(): BOOLEAN;
  BEGIN
    RETURN TRUE
  END HasMixedContent;
  
PROCEDURE (inlineText: InlineText) AddCharacters* (VAR chars: Element.StringVar;
                                          charsStart, charsEnd: Element.CharPos);
  VAR
    pcdata: Element.PCData;
  BEGIN
    IF (inlineText. textList. tail = NIL) OR
       ~(inlineText. textList. tail IS Element.PCData) THEN
      pcdata := Element.NewPCData();
      inlineText. textList. Append (pcdata)
    ELSE
      pcdata := inlineText. textList. tail(Element.PCData)
    END;
    pcdata. AddCharacters (chars, charsStart, charsEnd)
  END AddCharacters;
  
PROCEDURE (inlineText: InlineText) Write* (writer: Writer.Writer);
  VAR
    name: ARRAY 8 OF CHAR;
  BEGIN
    CASE inlineText. style OF
    | styleEmphasis: name := "em"
    | styleBold: name := "b"
    | styleCode: name := "code"
    END;
    writer. StartTagLatin1 (name, TRUE);
    inlineText. textList. Write (writer);
    writer. EndTag
  END Write;



PROCEDURE InitTest (test: Test);
  BEGIN
    InitInlineText (test);
    test. baseURI := NIL;
    test. id := "";
    test. type := testReject;
    test. file := NIL;
    test. lang := NIL;
    test. output := NIL;
  END InitTest;

PROCEDURE NewTest(): Element.Element;
  VAR
    test: Test;
  BEGIN
    NEW (test);
    InitTest (test);
    RETURN test
  END NewTest;

PROCEDURE (test: Test) SetLocator* (l: Locator.Locator);
  BEGIN
    test. baseURI := l. entity. baseURI
  END SetLocator;

PROCEDURE (test: Test) IsAttributeName* (localName: Element.String): BOOLEAN;
  BEGIN
    RETURN (localName^ = "id") OR
           (localName^ = "type") OR
           (localName^ = "file") OR
           (localName^ = "lang") OR
           (localName^ = "output")
  END IsAttributeName;

PROCEDURE (test: Test) AddAttribute* (localName: Element.String;
                                      value: Element.AttValue): BOOLEAN;
  VAR
    v: Element.String;
  BEGIN
    IF (localName^ = "id") THEN
      RETURN DataType.GetStringLatin1Attr (value, test. id)
    ELSIF (localName^ = "type") THEN
      v := value. Flatten (NIL);
      IF (v^ = "reject") THEN
        test. type := testReject
      ELSIF (v^ = "accept") THEN
        test. type := testAccept
      ELSIF (v^ = "error") THEN
        test. type := testError
      ELSIF (v^ = "run") THEN
        test. type := testRun
      ELSE
        RETURN FALSE
      END;
      RETURN TRUE
    ELSIF (localName^ = "file") THEN
      RETURN DataType.GetURIAttr (value, test. baseURI, test. file)
    ELSIF (localName^ = "lang") THEN
      test. lang := value. Flatten (NIL);
      RETURN TRUE
    ELSIF (localName^ = "output") THEN
      RETURN DataType.GetURIAttr (value, test. baseURI, test. output)
    ELSE
      RETURN FALSE
    END
  END AddAttribute;
  
PROCEDURE (test: Test) MissingChild* (): Element.String;
  VAR
    elem: Element.Element;
  BEGIN
    elem := test. textList. head;
    WHILE (elem # NIL) DO
      WITH elem: Element.PCData DO
        elem. Normalize (elem = test. textList. head, 
                         elem = test. textList. tail)
      ELSE                               (* already normalized *)
      END;
      elem := elem. next
    END;
    RETURN NIL
  END MissingChild;

PROCEDURE (test: Test) Write* (writer: Writer.Writer);
  VAR
    value: ARRAY 8 OF CHAR;
  BEGIN
    writer. StartTag ("test", TRUE);
    writer. AttrStringLatin1 ("id", test. id);
    CASE test. type OF
    | testAccept: value := "accept"
    | testReject: value := "reject"
    | testError: value := "error"
    | testRun, testOutput: value := "run"
    END;
    writer. AttrStringLatin1 ("type", value);
    writer. AttrURI ("file", test. file, FALSE);
    IF (test. lang # NIL) THEN
      writer. AttrString ("lang", test. lang^)
    END;
    IF (test. output # NIL) THEN
      writer. AttrURI ("output", test. output, FALSE)
    END;
    test. textList. Write (writer);
    writer. EndTag
  END Write;



PROCEDURE InitTestcases (testcases: Testcases);
  BEGIN
    Element.InitElement (testcases);
    testcases. profile := NIL;
    testcases. defaultLang := NIL;
    testcases. tests := Element.NewList();
  END InitTestcases;

PROCEDURE NewTestcases(): Element.Element;
  VAR
    testcases: Testcases;
  BEGIN
    NEW (testcases);
    InitTestcases (testcases);
    RETURN testcases
  END NewTestcases;

PROCEDURE (testcases: Testcases) IsAttributeName* (localName: Element.String): BOOLEAN;
  BEGIN
    RETURN (localName^ = "profile") OR
           (localName^ = "default-lang")
  END IsAttributeName;

PROCEDURE (testcases: Testcases) AddAttribute* (localName: Element.String;
                                            value: Element.AttValue): BOOLEAN;
  BEGIN
    IF (localName^ = "profile") THEN
      testcases. profile := value. Flatten (NIL);
      RETURN TRUE
    ELSIF (localName^ = "default-lang") THEN
      testcases. defaultLang := value. Flatten (NIL);
      RETURN TRUE
    ELSE
      RETURN FALSE
    END
  END AddAttribute;
  
PROCEDURE (testcases: Testcases) MissingAttribute* (): Element.String;
  BEGIN
    IF (testcases. defaultLang = NIL) THEN
      RETURN Element.NewString ("default-lang")
    ELSE
      RETURN NIL
    END
  END MissingAttribute;

PROCEDURE (testcases: Testcases) IsChildName* (localName: Element.String): BOOLEAN;
  BEGIN
    RETURN (localName^ = "test")
  END IsChildName;

PROCEDURE (testcases: Testcases) NewChild* (localName: Element.String): Element.Element;
  BEGIN
    IF (localName^ = "test") THEN
      RETURN NewTest()
    ELSE
      RETURN NIL
    END
  END NewChild;
  
PROCEDURE (testcases: Testcases) AddChild* (child: Element.Element);
  BEGIN
    WITH child: Test DO
      IF (child. lang = NIL) THEN
        child. lang := testcases. defaultLang
      END
    END;
    testcases. tests. Append (child)
  END AddChild;

PROCEDURE (testcases: Testcases) Write* (writer: Writer.Writer);
  BEGIN
    writer. StartTag ("testcases", FALSE);
    IF (testcases. profile # NIL) THEN
      writer. AttrString ("profile", testcases. profile^)
    END;
    writer. AttrString ("default-lang", testcases. defaultLang^);
    testcases. tests. Write (writer);
    writer. EndTag
  END Write;



PROCEDURE InitTestSuite (testSuite: TestSuite);
  BEGIN
    Element.InitElement (testSuite);
    testSuite. profile := NIL;
    testSuite. testcasesList := Element.NewList();
  END InitTestSuite;

PROCEDURE NewTestSuite(): Element.Element;
  VAR
    testSuite: TestSuite;
  BEGIN
    NEW (testSuite);
    InitTestSuite (testSuite);
    RETURN testSuite
  END NewTestSuite;

PROCEDURE (testSuite: TestSuite) IsAttributeName* (localName: Element.String): BOOLEAN;
  BEGIN
    RETURN (localName^ = "profile")
  END IsAttributeName;

PROCEDURE (testSuite: TestSuite) AddAttribute* (localName: Element.String;
                                            value: Element.AttValue): BOOLEAN;
  BEGIN
    IF (localName^ = "profile") THEN
      testSuite. profile := value. Flatten (NIL);
      RETURN TRUE
    ELSE
      RETURN FALSE
    END
  END AddAttribute;
  
PROCEDURE (testSuite: TestSuite) IsChildName* (localName: Element.String): BOOLEAN;
  BEGIN
    RETURN (localName^ = "testcases")
  END IsChildName;

PROCEDURE (testSuite: TestSuite) NewChild* (localName: Element.String): Element.Element;
  BEGIN
    IF (localName^ = "testcases") THEN
      RETURN NewTestcases()
    ELSE
      RETURN NIL
    END
  END NewChild;
  
PROCEDURE (testSuite: TestSuite) AddChild* (child: Element.Element);
  BEGIN
    testSuite. testcasesList. Append (child)
  END AddChild;

PROCEDURE (testSuite: TestSuite) MissingChild* (): Element.String;
  BEGIN
    IF (testSuite. testcasesList. head = NIL) THEN
      RETURN Element.NewString ("testcases")
    ELSE
      RETURN NIL
    END
  END MissingChild;

PROCEDURE (testSuite: TestSuite) Write* (writer: Writer.Writer);
  BEGIN
    writer. StartTag ("testsuite", FALSE);
    IF (testSuite. profile # NIL) THEN
      writer. AttrString ("profile", testSuite. profile^)
    END;
    testSuite. testcasesList. Write (writer);
    writer. EndTag
  END Write;


PROCEDURE Read* (byteReader: Ch.Reader; baseURI: URI.URI; VAR errList: XMLError.List): TestSuite;
  VAR
    elem: Element.Element;
  BEGIN
    elem := Parser.Parse (byteReader, baseURI, NIL, TRUE, suiteRoot, 3, {}, errList);
    IF (elem # NIL) THEN
      RETURN elem(TestSuite)
    ELSE
      RETURN NIL
    END
  END Read;

PROCEDURE Write* (writer: Writer.Writer; testSuite: TestSuite);
  BEGIN
    testSuite. Write (writer)
  END Write;

BEGIN
  suiteRoot := Element.NewRootFactory();
  suiteRoot. AddFactory ("testsuite", NewTestSuite)
END OOC:TestFramework:Testcases.
