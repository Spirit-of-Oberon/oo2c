MODULE LibXml1;

IMPORT LibXml, IO;

PROCEDURE Test*() RAISES IO.Error;
  BEGIN
    LibXml.Parse("xml/046.xml");
  END Test;

END LibXml1.
