MODULE Len1;

IMPORT Out := Out0;

TYPE
  A3 = ARRAY 3 OF INTEGER;
  A = ARRAY 2 OF A3;
  
VAR
  a: A;

PROCEDURE TestParam1 (a: ARRAY OF ARRAY OF INTEGER);
  BEGIN
    Out.String ("LEN(a,0):"); Out.Ln;
    Out.Int (LEN (a   ), 2); Out.Ln;
    Out.Int (LEN (a, 0), 2); Out.Ln;
    
    Out.String ("LEN(a,1):"); Out.Ln;
    Out.Int (LEN (a   , 1), 2); Out.Ln;
    Out.Int (LEN (a[0]   ), 2); Out.Ln;
    Out.Int (LEN (a[0], 0), 2); Out.Ln;
  END TestParam1;

PROCEDURE TestParam2 (a: ARRAY OF A3);
  BEGIN
    Out.String ("LEN(a,0):"); Out.Ln;
    Out.Int (LEN (a   ), 2); Out.Ln;
    Out.Int (LEN (a, 0), 2); Out.Ln;
    
    Out.String ("LEN(a,1):"); Out.Ln;
    Out.Int (LEN (a   , 1), 2); Out.Ln;
    Out.Int (LEN (a[0]   ), 2); Out.Ln;
    Out.Int (LEN (a[0], 0), 2); Out.Ln;
  END TestParam2;

PROCEDURE Test* ();
  BEGIN
    Out.String ("LEN(a,0):"); Out.Ln;
    Out.Int (LEN (a   ), 2); Out.Ln;
    Out.Int (LEN (a, 0), 2); Out.Ln;
    
    Out.String ("LEN(a,1):"); Out.Ln;
    Out.Int (LEN (a   , 1), 2); Out.Ln;
    Out.Int (LEN (a[0]   ), 2); Out.Ln;
    Out.Int (LEN (a[0], 0), 2); Out.Ln;

    Out.Ln;
    TestParam1 (a);
    
    Out.Ln;
    TestParam2 (a);
  END Test;

END Len1.
