MODULE LibXml;

IMPORT
  StdChannels, Out, IO, Std:=IO:StdChannels,
  
  XML:Builder:Canonical,
  XML:Builder:ParserProtocol,
  XML:Builder:Namespaces,
  XML:Builder:Validation,
  XML:Builder,
  XML:Error,
  XML:InputBuffer,
  XML:Parser,
  XML:UnicodeBuffer,
  XML:UnicodeCodec,
  XML:Writer,
  XML:UnicodeCodec:ASCII,
  XML:UnicodeCodec:ImportAll,
  XML:UnicodeCodec:Latin1,
  XML:UnicodeCodec:UTF16,
  XML:UnicodeCodec:UTF8,
  XML:DTD,
  XML:Locator,
  XML:EntityResolver,
  
  BasicElement := XML:Basic:Element,
  BasicParser := XML:Basic:Parser,
  BasicDataType := XML:Basic:DataType;

PROCEDURE CreateParser(file: ARRAY OF CHAR): Parser.Parser RAISES IO.Error;
  VAR
    namespaceSupport, validating, dontFollowEntityRefs: BOOLEAN;
    format: SHORTINT;
    builder, outputBuilder: Builder.Builder;
    p: Parser.Parser;
    namespaceBuilder, validatingBuilder: Builder.Builder;
  BEGIN
    namespaceSupport := FALSE;
    validating := TRUE;
    dontFollowEntityRefs := FALSE;
    format := Canonical.firstCanonicalForm;
    
    builder := Canonical.New (Std.stdout, UTF8.factory, format);
    outputBuilder := builder;
    IF validating THEN
      dontFollowEntityRefs := FALSE;
      validatingBuilder := Validation.New (builder);
      builder := validatingBuilder
    END;
    IF namespaceSupport THEN
      namespaceBuilder := Namespaces.New (builder);
      builder := namespaceBuilder
    END;
    
    p := Parser.NewFile (file, NIL, NIL, NIL, builder);
    p. followExternalRef := ~dontFollowEntityRefs;
    p. enforceQNames := namespaceSupport; (* enable QName and NCName checks *)
    p. validating := validating;          (* enable parser-level validation *)
    RETURN p
  END CreateParser;

PROCEDURE Parse* (file: ARRAY OF CHAR) RAISES IO.Error;
  VAR
    canon: Parser.Parser;
  BEGIN
    canon := CreateParser(file);
    canon. ParseDocument;
    Out.Ln;
    
    IF (canon. errList. msgCount # 0) THEN
      canon. errList. Write (StdChannels.stdout);
    END
  END Parse;

PROCEDURE Test*;
  BEGIN
  END Test;

END LibXml.
