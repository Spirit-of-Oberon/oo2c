MODULE M004;

PROCEDURE Length* (stringVal: ARRAY OF CHAR): INTEGER;
(**Returns the length of @oparam{stringVal}.  This is equal to the number of 
   characters in @oparam{stringVal} up to and excluding the first @code{0X}. *)
  END Length;
  
PROCEDURE Assign* (source: ARRAY OF CHAR; VAR destination: ARRAY OF CHAR);
(**Copies @oparam{source} to @oparam{destination}.  Equivalent to the
   predefined procedure @code{COPY}.  Unlike @code{COPY}, this procedure can
   be assigned to a procedure variable.  *)
  END Assign;
  
PROCEDURE Extract* (source: ARRAY OF CHAR; startPos, numberToExtract: INTEGER;
                    VAR destination: ARRAY OF CHAR);
(**Copies at most @oparam{numberToExtract} characters from @oparam{source} to
   @oparam{destination}, starting at position @oparam{startPos} in 
   @oparam{source}.  An empty string value will be extracted if 
   @oparam{startPos} is greater than or equal to
   @samp{Length(@oparam{source})}.  
   
   @precond
   @oparam{startPos} and @oparam{numberToExtract} are not negative.
   
   @oparam{source} is terminated with a @code{0X}.
   @end precond *)
  END Extract;

END M004.
