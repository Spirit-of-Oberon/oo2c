MODULE LibIntConvLengthInt1;

IMPORT
  Out := Out0, IntConv;

PROCEDURE Length (i: LONGINT);
  BEGIN
    Out.Int (IntConv.LengthInt (i), 0); Out.Ln;
  END Length;

PROCEDURE Test* ();
  BEGIN
    Length (-2147483647-1);
    Length (-1000000000);
    Length ( -999999999);
    Length ( -100000000);
    Length (  -99999999);
    Length (  -10000000);
    Length (   -9999999);
    Length (   -1000000);
    Length (    -999999);
    Length (    -100000);
    Length (     -99999);
    Length (     -10000);
    Length (      -9999);
    Length (      -1000);
    Length (       -999);
    Length (       -100);
    Length (        -99);
    Length (        -10);
    Length (         -9);
    Length (          0);
    Length (          9);
    Length (         10);
    Length (         99);
    Length (        100);
    Length (        999);
    Length (       1000);
    Length (       9999);
    Length (      10000);
    Length (      99999);
    Length (     100000);
    Length (     999999);
    Length (    9999999);
    Length (    1000000);
    Length (   10000000);
    Length (   99999999);
    Length (  100000000);
    Length (  999999999);
    Length ( 1000000000);
    Length ( 2147483647);
  END Test;

END LibIntConvLengthInt1.
