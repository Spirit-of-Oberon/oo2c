MODULE tst;

CONST A={0};
VAR i:INTEGER;

BEGIN
   i:=0;
   IF TRUE & i THEN END;
   
   IF TRUE & i = i THEN END;
(*
#----------------^
# 9: 233 Operand incompatible to left hand side `BOOLEAN'
(looks as if we know the second i is not 'BOOLEAN', while
 the first one seems to be AND'ed without type-checking)).
*)
   IF i = i & TRUE THEN END;
(*
#---------^
# 10: 233 Operand incompatible to left hand side `INTEGER'
(looks ok (though again type-checking seems a bit late))
*)
   IF TRUE & i IN A THEN END;
(*
#-----^
# 11: 234 Integer expression expected (instead of `BOOLEAN')
(but why should it be?)
*)
   IF i IN TRUE THEN END;
   
   IF i IN A & TRUE THEN END;
(*
#-----------------------^
# 12: 999 Unexpected compiler termination
(that's the main reason of my letter)
*)
END tst .
