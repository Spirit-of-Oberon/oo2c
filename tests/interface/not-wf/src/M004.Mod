MODULE M002;

PROCEDURE Length* (stringVal: ARRAY OF CHAR): INTEGER;
(**Invalid reference @oparam{@strong{abc}}.  This error is actually discovered twice,
   one for the main text and once for the summary extract.  *)
  END Length;
  
END M002.
