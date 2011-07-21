MODULE LibXml2;

IMPORT LibXml, IO;

PROCEDURE Test*() RAISES IO.Error;
  BEGIN
    LibXml.Parse("xml/003.xml");
  END Test;

END LibXml2.
