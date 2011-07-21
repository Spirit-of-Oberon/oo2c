(* 	$Id: Testcases.Mod,v 1.17 2003/05/20 20:10:29 mva Exp $	 *)
MODULE OOC:TestFramework:Testcases;
(*  Parser for XML testsuite and testcases elements.
    Copyright (C) 2001, 2003  Michael van Acken

    This file is part of OOC.

    OOC is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.  

    OOC is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
    License for more details. 

    You should have received a copy of the GNU General Public License
    along with OOC. If not, write to the Free Software Foundation, 59
    Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*)


IMPORT
  LongStrings, Strings, IO, OS:Path,
  URI, XMLError := XML:Error, XML:Locator, XML:Basic:Element,
  XML:Basic:Parser, XML:Basic:DataType, XML:Writer,
  OOC:TestFramework:TestSetup;


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

CONST
  relevanceStandard* = 0;
  relevanceInformal* = 1;
  sizeId = 64;
  
TYPE
  Test* = POINTER TO TestDesc;
  TestDesc = RECORD
    (InlineTextDesc)
    baseURI-: URI.URI;
    id-: ARRAY sizeId OF CHAR;
    type-: SHORTINT;
    relevance-: SHORTINT;
    file-: URI.URI;
    lang-: Element.String;
    output-: URI.URI;
    moduleName: STRING;
  END;

TYPE
  Testcases* = POINTER TO TestcasesDesc;
  TestcasesDesc = RECORD
    (Element.ElementDesc)
    profile-: Element.String;            (* may be NIL *)
    defaultLang-: Element.String;
    tests-: Element.List;                (* may be empty *)
  END;

TYPE
  RejectInfo* = POINTER TO RejectInfoDesc;
  RejectInfoDesc = RECORD
    (Element.ElementDesc)
    id-: ARRAY sizeId OF CHAR;
    pos-: Element.String;
    msg-: Element.String;
  END;

TYPE
  WarningInfo* = POINTER TO WarningInfoDesc;
  WarningInfoDesc = RECORD
    (RejectInfoDesc)
  END;

TYPE
  ProcessorInfo* = POINTER TO ProcessorInfoDesc;
  ProcessorInfoDesc = RECORD
    (Element.ElementDesc)
    processorName-: TestSetup.String8;
    rejectInfoList-: Element.List;       (* may be empty *)
    warningInfoList-: Element.List;      (* may be empty *)
  END;
  
TYPE
  TestSuite* = POINTER TO TestSuiteDesc;
  TestSuiteDesc = RECORD
    (Element.ElementDesc)
    profile-: Element.String;            (* may be NIL *)
    select-: Element.String;             (* may be NIL *)
    testcasesList-: Element.List;        (* at least one element *)
    processorInfoList-: Element.List;    (* may be empty *)
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
    test. relevance := relevanceStandard;
    test. file := NIL;
    test. lang := NIL;
    test. output := NIL;
    test. moduleName := NIL;
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
           (localName^ = "relevance") OR
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
    ELSIF (localName^ = "relevance") THEN
      v := value. Flatten (NIL);
      IF (v^ = "standard") THEN
        test. relevance := relevanceStandard
      ELSIF (v^ = "informal") THEN
        test. relevance := relevanceInformal
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
  
PROCEDURE (test: Test) MissingAttribute* (): Element.String;
  BEGIN
    IF (test. type = testRun) & (test. output # NIL) THEN
      test. type := testOutput
    END;
    RETURN NIL
  END MissingAttribute;

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

PROCEDURE (test: Test) ModuleName* (): STRING;
  VAR
    path, ext: STRING;
  BEGIN
    IF (test. moduleName = NIL) THEN
      path := Path.BaseName(test.file.ToString());
      Path.SplitExt(path, test.moduleName, ext);
    END;
    RETURN test. moduleName
  END ModuleName;

PROCEDURE (test: Test) Write* (writer: Writer.Writer);
  VAR
    value: ARRAY 16 OF CHAR;
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
    CASE test. relevance OF
    | relevanceStandard: value := "standard"
    | relevanceInformal: value := "informal"
    END;
    writer. AttrStringLatin1 ("relevance", value);
    writer. AttrURI ("file", test. file, TRUE);
    IF (test. lang # NIL) THEN
      writer. AttrString ("lang", test. lang^)
    END;
    IF (test. output # NIL) THEN
      writer. AttrURI ("output", test. output, TRUE)
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



PROCEDURE InitRejectInfo (rejInfo: RejectInfo);
  BEGIN
    Element.InitElement (rejInfo);
    rejInfo. id := "";
    rejInfo. pos := NIL;
    rejInfo. msg := NIL;
  END InitRejectInfo;

PROCEDURE NewRejectInfo(): Element.Element;
  VAR
    rejInfo: RejectInfo;
  BEGIN
    NEW (rejInfo);
    InitRejectInfo (rejInfo);
    RETURN rejInfo
  END NewRejectInfo;

PROCEDURE (rejInfo: RejectInfo) IsAttributeName* (localName: Element.String): BOOLEAN;
  BEGIN
    RETURN (localName^ = "id") OR
           (localName^ = "pos") OR
           (localName^ = "msg")
  END IsAttributeName;

PROCEDURE (rejInfo: RejectInfo) AddAttribute* (localName: Element.String;
                                      value: Element.AttValue): BOOLEAN;
  BEGIN
    IF (localName^ = "id") THEN
      RETURN DataType.GetStringLatin1Attr (value, rejInfo. id)
    ELSIF (localName^ = "pos") THEN
      rejInfo. pos := value. Flatten (NIL);
      RETURN TRUE
    ELSIF (localName^ = "msg") THEN
      rejInfo. msg := value. Flatten (NIL);
      RETURN TRUE
    ELSE
      RETURN FALSE
    END
  END AddAttribute;
  
PROCEDURE (rejInfo: RejectInfo) MissingAttribute* (): Element.String;
  BEGIN
    RETURN NIL
  END MissingAttribute;

PROCEDURE (rejInfo: RejectInfo) MissingChild* (): Element.String;
  BEGIN
    RETURN NIL
  END MissingChild;

PROCEDURE (rejInfo: RejectInfo) Write* (writer: Writer.Writer);
  BEGIN
    writer. StartTag ("reject-info", FALSE);
    writer. AttrStringLatin1 ("id", rejInfo. id);
    writer. AttrString ("pos", rejInfo. pos^);
    writer. AttrString ("msg", rejInfo. msg^);
    writer. EndTag
  END Write;



PROCEDURE InitWarningInfo (warnInfo: WarningInfo);
  BEGIN
    InitRejectInfo(warnInfo);
  END InitWarningInfo;

PROCEDURE NewWarningInfo(): Element.Element;
  VAR
    warnInfo: WarningInfo;
  BEGIN
    NEW (warnInfo);
    InitWarningInfo (warnInfo);
    RETURN warnInfo
  END NewWarningInfo;

PROCEDURE (warnInfo: WarningInfo) Write* (writer: Writer.Writer);
  BEGIN
    writer. StartTag ("warning-info", FALSE);
    writer. AttrStringLatin1 ("id", warnInfo. id);
    writer. AttrString ("pos", warnInfo. pos^);
    writer. AttrString ("msg", warnInfo. msg^);
    writer. EndTag
  END Write;



PROCEDURE InitProcessorInfo (processorInfo: ProcessorInfo);
  BEGIN
    Element.InitElement (processorInfo);
    processorInfo. processorName := "";
    processorInfo. rejectInfoList := Element.NewList();
    processorInfo. warningInfoList := Element.NewList();
  END InitProcessorInfo;

PROCEDURE NewProcessorInfo(): Element.Element;
  VAR
    processorInfo: ProcessorInfo;
  BEGIN
    NEW (processorInfo);
    InitProcessorInfo (processorInfo);
    RETURN processorInfo
  END NewProcessorInfo;

PROCEDURE (processorInfo: ProcessorInfo) IsAttributeName* (localName: Element.String): BOOLEAN;
  BEGIN
    RETURN (localName^ = "processor-name")
  END IsAttributeName;

PROCEDURE (processorInfo: ProcessorInfo) AddAttribute* (localName: Element.String;
                                            value: Element.AttValue): BOOLEAN;
  BEGIN
    IF (localName^ = "processor-name") THEN
      RETURN DataType.GetStringLatin1Attr (value, processorInfo. processorName)
    ELSE
      RETURN FALSE
    END
  END AddAttribute;
  
PROCEDURE (processorInfo: ProcessorInfo) MissingAttribute* (): Element.String;
  BEGIN
    IF (processorInfo. processorName = "") THEN
      RETURN Element.NewString ("processor-name")
    ELSE
      RETURN NIL
    END
  END MissingAttribute;

PROCEDURE (processorInfo: ProcessorInfo) IsChildName* (localName: Element.String): BOOLEAN;
  BEGIN
    RETURN (localName^ = "reject-info") OR (localName^ = "warning-info");
  END IsChildName;

PROCEDURE (processorInfo: ProcessorInfo) NewChild* (localName: Element.String): Element.Element;
  BEGIN
    IF (localName^ = "reject-info") THEN
      RETURN NewRejectInfo()
    ELSIF (localName^ = "warning-info") THEN
      RETURN NewWarningInfo()
    ELSE
      RETURN NIL
    END
  END NewChild;
  
PROCEDURE (processorInfo: ProcessorInfo) AddChild* (child: Element.Element);
  BEGIN
    WITH child: WarningInfo DO
      processorInfo. warningInfoList. Append (child)
    | child: RejectInfo DO
      processorInfo. rejectInfoList. Append (child)
    END;
  END AddChild;

PROCEDURE (processorInfo: ProcessorInfo) Write* (writer: Writer.Writer);
  BEGIN
    writer. StartTag ("processorInfo", FALSE);
    writer. AttrStringLatin1 ("processor-name", processorInfo. processorName);
    processorInfo. rejectInfoList. Write (writer);
    processorInfo. warningInfoList. Write (writer);
    writer. EndTag
  END Write;



PROCEDURE InitTestSuite (testSuite: TestSuite);
  BEGIN
    Element.InitElement (testSuite);
    testSuite. profile := NIL;
    testSuite. select := NIL;
    testSuite. testcasesList := Element.NewList();
    testSuite. processorInfoList := Element.NewList();
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
    RETURN (localName^ = "profile") OR (localName^ = "select")
  END IsAttributeName;

PROCEDURE (testSuite: TestSuite) AddAttribute* (localName: Element.String;
                                            value: Element.AttValue): BOOLEAN;
  BEGIN
    IF (localName^ = "profile") THEN
      testSuite. profile := value. Flatten (NIL);
      RETURN TRUE
    ELSIF (localName^ = "select") THEN
      testSuite. select := value. Flatten (NIL);
      RETURN TRUE
    ELSE
      RETURN FALSE
    END
  END AddAttribute;
  
PROCEDURE (testSuite: TestSuite) IsChildName* (localName: Element.String): BOOLEAN;
  BEGIN
    RETURN (localName^ = "testcases") OR (localName^ = "processor-info")
  END IsChildName;

PROCEDURE (testSuite: TestSuite) NewChild* (localName: Element.String): Element.Element;
  BEGIN
    IF (localName^ = "testcases") THEN
      RETURN NewTestcases()
    ELSIF (localName^ = "processor-info") THEN
      RETURN NewProcessorInfo()
    ELSE
      RETURN NIL
    END
  END NewChild;
  
PROCEDURE (testSuite: TestSuite) AddChild* (child: Element.Element);
  BEGIN
    WITH child: Testcases DO
      testSuite. testcasesList. Append (child)
    | child: ProcessorInfo DO
      testSuite. processorInfoList. Append (child)
    END;
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
    testSuite. processorInfoList. Write (writer);
    writer. EndTag
  END Write;

PROCEDURE (testSuite: TestSuite) SelectedTest* (test: Test): BOOLEAN;
  VAR
    pos, len, i: INTEGER;
    id: ARRAY sizeId OF LONGCHAR;
    found: BOOLEAN;
  BEGIN
    IF (testSuite. select = NIL) THEN    (* no explicit select: do all *)
      RETURN TRUE
    ELSE
      COPY (test. id, id);
      pos := 0;
      len := Strings.Length (test. id);
      LOOP
        LongStrings.FindNext (id, testSuite. select^, pos, found, i);
        IF found THEN
          IF ((i = 0) OR (testSuite. select[i-1] = " ")) &
             ((testSuite. select[i+len] = 0X) OR
              (testSuite. select[i+len] = " ")) THEN
            RETURN TRUE
          ELSE
            pos := i+len
          END;
        ELSE
          RETURN FALSE
        END;
      END;
    END;
  END SelectedTest;
  

PROCEDURE Read* (byteReader: IO.ByteChannel; baseURI: URI.URI; VAR errList: XMLError.List): TestSuite
RAISES IO.Error;
  VAR
    elem: Element.Element;
  BEGIN
    elem := Parser.Parse (byteReader, baseURI, NIL, suiteRoot, 3, {Parser.validate}, errList);
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
  suiteRoot. AddFactory ("testsuite", NewTestSuite);
  suiteRoot. AddFactory ("testsuite-ext", NewTestSuite);
END OOC:TestFramework:Testcases.
