MODULE LibXml;

IMPORT
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

PROCEDURE Test*;
  BEGIN
  END Test;

END LibXml.
