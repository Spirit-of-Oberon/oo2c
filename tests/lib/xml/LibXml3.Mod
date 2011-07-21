MODULE LibXml3;

IMPORT LibXml, IO;

PROCEDURE Test*() RAISES IO.Error;
  BEGIN
    LibXml.Parse("xml/003b.xml");
  END Test;

END LibXml3.
