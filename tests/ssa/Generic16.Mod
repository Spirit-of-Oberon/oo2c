MODULE Generic16;

IMPORT G:=Generic1;

TYPE
  P*(Base: G.Object) = POINTER TO R(Base);
  R*(Base: G.Object) = RECORD
    f-: Base;
  END;

PROCEDURE (p: P(Base)) Proc1*(a, b: Base);
  VAR
    v, w: Base;
    x: G.Object;
    y: G.A1;
    i: LONGINT;
    e: BOOLEAN;
    
  PROCEDURE NestedProc(p1: Base; VAR p2: Base);
    BEGIN
    END NestedProc;

  PROCEDURE NestedFct(p1: Base): Base;
    BEGIN
      RETURN p1;
    END NestedFct;
  
  BEGIN
    v := NIL;

    v := a;

    NestedProc(a, b);

    w := NestedFct(v);

    x := v;
    y := v(G.A1);

    i := v.Id();
    i := v.f;
    v.f := i;

    e := (v=w);
    e := (x=v);
    e := (v=NIL);
  END Proc1;

END Generic16.
