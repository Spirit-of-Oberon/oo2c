MODULE OpString2;

CONST
  str = 'X';

PROCEDURE Test*;
VAR 
  c : CHAR;
  l : LONGCHAR;
  u : UCS4CHAR;
  ca : ARRAY 8 OF CHAR;
  la : ARRAY 8 OF LONGCHAR;
  ua : ARRAY 8 OF UCS4CHAR;
BEGIN
  c := str;
  l := str;
  u := str;
  ca := str;
  la := str;
  ua := str;
END Test;

END OpString2.
