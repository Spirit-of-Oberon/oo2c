MODULE LibUri2;

IMPORT
  LibUri;
  
PROCEDURE Test* ();
  BEGIN
    LibUri.Write ("http://user@:8080/");
  END Test;

END LibUri2.
