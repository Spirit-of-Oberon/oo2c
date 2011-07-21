MODULE HOTLoop12;

IMPORT Out:=Out0;

TYPE
  Integer = POINTER TO IntegerDesc;
  IntegerDesc = ARRAY OF INTEGER;
  
CONST
  B  = 8000H;      (* base (32768) for calculations *)

PROCEDURE Copy (VAR s: ARRAY OF INTEGER; n: LONGINT) : Integer;
  (* n is number of occupied elements in s, including the sign *)
  VAR d: Integer; i, j: LONGINT;
  BEGIN
    IF n=0 THEN n:=LEN(s) END;
    
    (* reduce the size of the number -- if needed *)
    i:=1; WHILE (s[i]=0) & (i<n-1) DO INC(i) END; 
    DEC(i); DEC(n, i);  
    
    (* create a new number and copy contents *)
    NEW(d, n); FOR j:=1 TO n-1 DO d[j]:=s[i+j] END;
    d[0]:=s[0];  (* copy the sign *)
    RETURN d
  END Copy;
  
PROCEDURE Sub (x: ARRAY OF INTEGER; VAR y: ARRAY OF INTEGER) : Integer;
  (* Pre: x>0, y>0, LEN(x)>=LEN(y); Post: z=x-y *)
  VAR xt, yt, i, j, len, borrow: LONGINT;
  BEGIN
    Out.String ("LEN(x): "); Out.Int (LEN(x), 0); Out.Ln;
    Out.String ("LEN(y): "); Out.Int (LEN(y), 0); Out.Ln;
    len:=LEN(x)-1; j:=LEN(y)-1; borrow:=0;
    FOR i:= len TO 1 BY -1 DO
      xt:=x[i]; 
      IF j<1 THEN yt:=0 ELSE yt:=y[j] END;
      IF xt<yt THEN x[i]:=SHORT(B+xt-yt+borrow); borrow:=-1
      ELSE x[i]:=SHORT(xt-yt+borrow); borrow:=0
      END;
      DEC(j)
    END;
    ASSERT(borrow=0, 100);
    Out.Int (len+1, 0); Out.Ln;
    RETURN Copy(x, len+1)
  END Sub;
   
PROCEDURE Test* ();
  VAR
    left: ARRAY 3 OF INTEGER;
    right: ARRAY 2 OF INTEGER;
    i: Integer;
    j: LONGINT;
  BEGIN
    left[0] := -1; left[1] := 1; left[2] := 0;
    right[0] := 1; right[1] := 1;
    i := Sub (left, right);
    
    Out.Int (LEN (i^), 0);
    Out.String (": ");
    FOR j := 0 TO LEN (i^)-1 DO
      Out.Int (i[j], 6);
    END;
    Out.Ln;
  END Test;

END HOTLoop12.
