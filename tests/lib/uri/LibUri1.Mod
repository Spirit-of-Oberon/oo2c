MODULE LibUri1;

IMPORT
  LibUri;
  
PROCEDURE Test* ();
  BEGIN
    LibUri.Write ("http://user@host.com:8080/furbie;test?foo=bar");
  END Test;

END LibUri1.
