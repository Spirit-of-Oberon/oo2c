MODULE NilCompat5;

IMPORT NilCompat3;

PROCEDURE P();
  BEGIN
    NilCompat3.P2(NIL);
  END P;

END NilCompat5.
