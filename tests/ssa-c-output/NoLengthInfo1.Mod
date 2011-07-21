MODULE NoLengthInfo1;

<*DerefCheck:=FALSE*>

VAR
  a*: POINTER TO ARRAY [NO_LENGTH_INFO] OF CHAR;

BEGIN  <*IndexCheck:=TRUE*>
  a[0] := 0X;
END NoLengthInfo1.
