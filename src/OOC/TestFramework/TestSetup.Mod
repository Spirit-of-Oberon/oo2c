(* 	$Id: TestSetup.Mod,v 1.8 2003/01/30 23:38:18 mva Exp $	 *)
MODULE OOC:TestFramework:TestSetup;
(*  Parser for XML test-setup elements.
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
  IO, URI, XMLError := XML:Error, XML:Locator, XML:Basic:Element,
  XML:Basic:Parser, XML:Basic:DataType, XML:Writer;


TYPE
  String8* = ARRAY 256 OF CHAR;

CONST
  unknownString8 = "unknown";

TYPE
  Machine* = POINTER TO MachineDesc;
  MachineDesc = RECORD
    (Element.ElementDesc)
    model-: String8;
    cpu-: String8;
    ram-: String8;
  END;

TYPE
  Component* = POINTER TO ComponentDesc;
  ComponentDesc = RECORD
    (Element.ElementDesc)
    name-: String8;
    value-: Element.StringBuffer;
  END;

TYPE
  OperatingSystem* = POINTER TO OperatingSystemDesc;
  OperatingSystemDesc = RECORD
    (Element.ElementDesc)
    name-: String8;
    version-: String8;
    components-: Element.List;
  END;

TYPE
  Processor* = POINTER TO ProcessorDesc;
  ProcessorDesc = RECORD
    (Element.ElementDesc)
    baseURI: URI.URI;
    name-: String8;
    version-: String8;
    command-: String8;
    configFile-: URI.URI;
    flags-: String8;
    workingDir-: URI.URI;
    filterCommand-: String8;
    diffCommand-: String8;
    checkRejectCommand-: String8;
  END;

TYPE
  TestSuite* = POINTER TO TestSuiteDesc;
  TestSuiteDesc = RECORD
    (Element.ElementDesc)
    baseURI: URI.URI;
    uri-: URI.URI;
  END;

TYPE
  TestSetup* = POINTER TO TestSetupDesc;
  TestSetupDesc = RECORD
    (Element.ElementDesc)
    lang-: Element.String;
    machine-: Machine;
    operatingSystem-: OperatingSystem;
    processor-: Processor;
    testSuite-: TestSuite;
  END;

VAR
  setupRoot: Element.RootFactory;
  


PROCEDURE InitMachine (machine: Machine);
  BEGIN
    Element.InitElement (machine);
    machine. model := unknownString8;
    machine. cpu := unknownString8;
    machine. ram := unknownString8;
  END InitMachine;

PROCEDURE NewMachine(): Element.Element;
  VAR
    machine: Machine;
  BEGIN
    NEW (machine);
    InitMachine (machine);
    RETURN machine
  END NewMachine;

PROCEDURE (machine: Machine) IsAttributeName* (localName: Element.String): BOOLEAN;
  BEGIN
    RETURN (localName^ = "model") OR
           (localName^ = "cpu") OR
           (localName^ = "ram")
  END IsAttributeName;

PROCEDURE (machine: Machine) AddAttribute* (localName: Element.String;
                                            value: Element.AttValue): BOOLEAN;
  BEGIN
    IF (localName^ = "model") THEN
      RETURN DataType.GetStringLatin1Attr (value, machine. model)
    ELSIF (localName^ = "cpu") THEN
      RETURN DataType.GetStringLatin1Attr (value, machine. cpu)
    ELSIF (localName^ = "ram") THEN
      RETURN DataType.GetStringLatin1Attr (value, machine. ram)
    ELSE
      RETURN FALSE
    END
  END AddAttribute;
  
PROCEDURE (machine: Machine) Write* (writer: Writer.Writer);
  BEGIN
    writer. StartTag ("machine", FALSE);
    writer. AttrStringLatin1 ("model", machine. model);
    writer. AttrStringLatin1 ("cpu", machine. cpu);
    writer. AttrStringLatin1 ("ram", machine. ram);
    writer. EndTag
  END Write;


PROCEDURE InitComponent (component: Component);
  BEGIN
    Element.InitElement (component);
    component. name := unknownString8;
    component. value := Element.NewStringBuffer("");
  END InitComponent;

PROCEDURE NewComponent(): Element.Element;
  VAR
    component: Component;
  BEGIN
    NEW (component);
    InitComponent (component);
    RETURN component
  END NewComponent;

PROCEDURE (component: Component) IsAttributeName* (localName: Element.String): BOOLEAN;
  BEGIN
    RETURN (localName^ = "name")
  END IsAttributeName;

PROCEDURE (component: Component) AddAttribute* (localName: Element.String;
                                                value: Element.AttValue): BOOLEAN;
  BEGIN
    IF (localName^ = "name") THEN
      RETURN DataType.GetStringLatin1Attr (value, component. name)
    ELSE
      RETURN FALSE
    END
  END AddAttribute;
  
PROCEDURE (component: Component) HasMixedContent*(): BOOLEAN;
  BEGIN
    RETURN TRUE
  END HasMixedContent;

PROCEDURE (component: Component) AddCharacters* (VAR chars: Element.StringVar;
                                          charsStart, charsEnd: Element.CharPos);
  BEGIN
    component. value. AddCharacters (chars, charsStart, charsEnd)
  END AddCharacters;
  
PROCEDURE (component: Component) Write* (writer: Writer.Writer);
  BEGIN
    writer. StartTag ("os-component", TRUE);
    writer. AttrStringLatin1 ("name", component. name);
    writer. Write (component. value. array^);
    writer. EndTag
  END Write;


PROCEDURE InitOperatingSystem (operatingSystem: OperatingSystem);
  BEGIN
    Element.InitElement (operatingSystem);
    operatingSystem. name := unknownString8;
    operatingSystem. version := unknownString8;
    operatingSystem. components := Element.NewList();
  END InitOperatingSystem;

PROCEDURE NewOperatingSystem(): Element.Element;
  VAR
    operatingSystem: OperatingSystem;
  BEGIN
    NEW (operatingSystem);
    InitOperatingSystem (operatingSystem);
    RETURN operatingSystem
  END NewOperatingSystem;

PROCEDURE (operatingSystem: OperatingSystem) IsAttributeName* (localName: Element.String): BOOLEAN;
  BEGIN
    RETURN (localName^ = "name") OR
           (localName^ = "version")
  END IsAttributeName;

PROCEDURE (operatingSystem: OperatingSystem) AddAttribute* (localName: Element.String;
                                            value: Element.AttValue): BOOLEAN;
  BEGIN
    IF (localName^ = "name") THEN
      RETURN DataType.GetStringLatin1Attr (value, operatingSystem. name)
    ELSIF (localName^ = "version") THEN
      RETURN DataType.GetStringLatin1Attr (value, operatingSystem. version)
    ELSE
      RETURN FALSE
    END
  END AddAttribute;
  
PROCEDURE (operatingSystem: OperatingSystem) IsChildName* (localName: Element.String): BOOLEAN;
  BEGIN
    RETURN (localName^ = "os-component")
  END IsChildName;

PROCEDURE (operatingSystem: OperatingSystem) NewChild* (localName: Element.String): Element.Element;
  BEGIN
    IF (localName^ = "os-component") THEN
      RETURN NewComponent()
    ELSE
      RETURN NIL
    END
  END NewChild;
  
PROCEDURE (operatingSystem: OperatingSystem) AddChild* (child: Element.Element);
  BEGIN
    operatingSystem. components. Append (child)
  END AddChild;

PROCEDURE (operatingSystem: OperatingSystem) Write* (writer: Writer.Writer);
  BEGIN
    writer. StartTag ("operating-system", FALSE);
    writer. AttrStringLatin1 ("name", operatingSystem. name);
    writer. AttrStringLatin1 ("version", operatingSystem. version);
    operatingSystem. components. Write (writer);
    writer. EndTag
  END Write;


PROCEDURE InitProcessor (processor: Processor);
  BEGIN
    Element.InitElement (processor);
    processor. baseURI := NIL;
    processor. name := unknownString8;
    processor. version := unknownString8;
    processor. command := unknownString8;
    processor. configFile := NIL;
    processor. flags := unknownString8;
    processor. workingDir := NIL;
    processor. filterCommand := "";
    processor. diffCommand := "";
    processor. checkRejectCommand := "";
  END InitProcessor;

PROCEDURE NewProcessor(): Element.Element;
  VAR
    processor: Processor;
  BEGIN
    NEW (processor);
    InitProcessor (processor);
    RETURN processor
  END NewProcessor;

PROCEDURE (processor: Processor) SetLocator* (l: Locator.Locator);
  BEGIN
    processor. baseURI := l. entity. baseURI
  END SetLocator;

PROCEDURE (processor: Processor) IsAttributeName* (localName: Element.String): BOOLEAN;
  BEGIN
    RETURN (localName^ = "name") OR
           (localName^ = "version") OR
           (localName^ = "command") OR
           (localName^ = "config-file") OR
           (localName^ = "flags") OR
           (localName^ = "working-dir") OR
           (localName^ = "filter-command") OR
           (localName^ = "diff-command") OR
           (localName^ = "check-reject-command")
  END IsAttributeName;

PROCEDURE (processor: Processor) AddAttribute* (localName: Element.String;
                                            value: Element.AttValue): BOOLEAN;
  BEGIN
    IF (localName^ = "name") THEN
      RETURN DataType.GetStringLatin1Attr (value, processor. name)
    ELSIF (localName^ = "version") THEN
      RETURN DataType.GetStringLatin1Attr (value, processor. version)
    ELSIF (localName^ = "command") THEN
      RETURN DataType.GetStringLatin1Attr (value, processor. command)
    ELSIF (localName^ = "config-file") THEN
      RETURN DataType.GetURIAttr (value, processor. baseURI, processor. configFile)
    ELSIF (localName^ = "flags") THEN
      RETURN DataType.GetStringLatin1Attr (value, processor. flags)
    ELSIF (localName^ = "working-dir") THEN
      RETURN DataType.GetURIAttr (value, processor. baseURI, processor. workingDir)
    ELSIF (localName^ = "filter-command") THEN
      RETURN DataType.GetStringLatin1Attr (value, processor. filterCommand)
    ELSIF (localName^ = "diff-command") THEN
      RETURN DataType.GetStringLatin1Attr (value, processor. diffCommand)
    ELSIF (localName^ = "check-reject-command") THEN
      RETURN DataType.GetStringLatin1Attr (value, processor. checkRejectCommand)
    ELSE
      RETURN FALSE
    END
  END AddAttribute;
  
PROCEDURE (processor: Processor) Write* (writer: Writer.Writer);
  BEGIN
    writer. StartTag ("processor", FALSE);
    writer. AttrStringLatin1 ("name", processor. name);
    writer. AttrStringLatin1 ("version", processor. version);
    writer. AttrStringLatin1 ("command", processor. command);
    IF (processor. configFile # NIL) THEN
      writer. AttrURI ("config-file", processor. configFile, FALSE)
    END;
    writer. AttrStringLatin1 ("flags", processor. flags);
    writer. AttrURI ("working-dir", processor. workingDir, FALSE);
    IF (processor. filterCommand # "") THEN
      writer. AttrStringLatin1 ("filter-command", processor. filterCommand)
    END;
    IF (processor. diffCommand # "") THEN
      writer. AttrStringLatin1 ("diff-command", processor. diffCommand)
    END;
    IF (processor. checkRejectCommand # "") THEN
      writer. AttrStringLatin1 ("check-reject-command", processor. checkRejectCommand)
    END;
    writer. EndTag
  END Write;


PROCEDURE InitTestSuite (testSuite: TestSuite);
  BEGIN
    Element.InitElement (testSuite);
    testSuite. baseURI := NIL;
    testSuite. uri := NIL;
  END InitTestSuite;

PROCEDURE NewTestSuite(): Element.Element;
  VAR
    testSuite: TestSuite;
  BEGIN
    NEW (testSuite);
    InitTestSuite (testSuite);
    RETURN testSuite
  END NewTestSuite;

PROCEDURE (testSuite: TestSuite) SetLocator* (l: Locator.Locator);
  BEGIN
    testSuite. baseURI := l. entity. baseURI
  END SetLocator;

PROCEDURE (testSuite: TestSuite) IsAttributeName* (localName: Element.String): BOOLEAN;
  BEGIN
    RETURN (localName^ = "uri")
  END IsAttributeName;

PROCEDURE (testSuite: TestSuite) AddAttribute* (localName: Element.String;
                                            value: Element.AttValue): BOOLEAN;
  BEGIN
    IF (localName^ = "uri") THEN
      RETURN DataType.GetURIAttr (value, testSuite. baseURI, testSuite. uri)
    ELSE
      RETURN FALSE
    END
  END AddAttribute;
  
PROCEDURE (testSuite: TestSuite) Write* (writer: Writer.Writer);
  BEGIN
    writer. StartTag ("test-suite", FALSE);
    writer. AttrURI ("uri", testSuite. uri, FALSE);
    writer. EndTag
  END Write;


PROCEDURE InitTestSetup (testSetup: TestSetup);
  BEGIN
    Element.InitElement (testSetup);
    testSetup. lang := NIL;
    testSetup. machine := NIL;
    testSetup. operatingSystem := NIL;
    testSetup. processor := NIL;
    testSetup. testSuite := NIL;
  END InitTestSetup;

PROCEDURE NewTestSetup(): Element.Element;
  VAR
    testSetup: TestSetup;
  BEGIN
    NEW (testSetup);
    InitTestSetup (testSetup);
    RETURN testSetup
  END NewTestSetup;

PROCEDURE (testSetup: TestSetup) IsAttributeName* (localName: Element.String): BOOLEAN;
  BEGIN
    RETURN (localName^ = "lang")
  END IsAttributeName;

PROCEDURE (testSetup: TestSetup) AddAttribute* (localName: Element.String;
                                            value: Element.AttValue): BOOLEAN;
  BEGIN
    IF (localName^ = "lang") THEN
      testSetup. lang := value. Flatten (NIL);
      RETURN TRUE
    ELSE
      RETURN FALSE
    END
  END AddAttribute;
  
PROCEDURE (testSetup: TestSetup) IsChildName* (localName: Element.String): BOOLEAN;
  BEGIN
    RETURN (localName^ = "machine") OR
           (localName^ = "operating-system") OR
           (localName^ = "processor") OR
           (localName^ = "test-suite")
  END IsChildName;

PROCEDURE (testSetup: TestSetup) NewChild* (localName: Element.String): Element.Element;
  BEGIN
    IF (localName^ = "machine") & (testSetup. machine = NIL) THEN
      RETURN NewMachine()
    ELSIF (localName^ = "operating-system") & 
          (testSetup. operatingSystem = NIL) &
          (testSetup. machine # NIL) THEN
      RETURN NewOperatingSystem()
    ELSIF (localName^ = "processor") &
          (testSetup. processor = NIL) &
          (testSetup. machine # NIL) THEN
      RETURN NewProcessor()
    ELSIF (localName^ = "test-suite") &
          (testSetup. testSuite = NIL) &
          (testSetup. processor # NIL) THEN
      RETURN NewTestSuite()
    ELSE
      RETURN NIL
    END
  END NewChild;
  
PROCEDURE (testSetup: TestSetup) AddChild* (child: Element.Element);
  BEGIN
    WITH child: Machine DO
      testSetup. machine := child
    | child: OperatingSystem DO
      testSetup. operatingSystem := child
    | child: Processor DO
      testSetup. processor := child
    | child: TestSuite DO
      testSetup. testSuite := child
    END
  END AddChild;

PROCEDURE (testSetup: TestSetup) MissingChild* (): Element.String;
  BEGIN
    IF (testSetup. machine = NIL) THEN
      RETURN Element.NewString ("machine")
    ELSIF (testSetup. operatingSystem = NIL) THEN
      RETURN Element.NewString ("operating-system")
    ELSIF (testSetup. processor = NIL) THEN
      RETURN Element.NewString ("processor")
    ELSIF (testSetup. testSuite = NIL) THEN
      RETURN Element.NewString ("test-suite")
    ELSE
      RETURN NIL
    END
  END MissingChild;

PROCEDURE (testSetup: TestSetup) Write* (writer: Writer.Writer);
  BEGIN
    writer. StartTag ("test-setup", FALSE);
    writer. AttrString ("lang", testSetup. lang^);
    testSetup. machine. Write (writer);
    testSetup. operatingSystem. Write (writer);
    testSetup. processor. Write (writer);
    testSetup. testSuite. Write (writer);
    writer. EndTag
  END Write;



PROCEDURE Read* (byteReader: IO.ByteChannel; baseURI: URI.URI; VAR errList: XMLError.List): TestSetup
RAISES IO.Error;
  VAR
    elem: Element.Element;
  BEGIN
    elem := Parser.Parse (byteReader, baseURI, NIL, setupRoot, 3, {Parser.validate}, errList);
    IF (elem # NIL) THEN
      RETURN elem(TestSetup)
    ELSE
      RETURN NIL
    END
  END Read;

PROCEDURE Write* (writer: Writer.Writer; testSetup: TestSetup);
  BEGIN
    testSetup. Write (writer)
  END Write;

BEGIN
  setupRoot := Element.NewRootFactory();
  setupRoot. AddFactory ("test-setup", NewTestSetup)
END OOC:TestFramework:TestSetup.
