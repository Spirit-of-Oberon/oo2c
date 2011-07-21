MODULE Generic65;

IMPORT
  Out := Out0, G := Generic1;

TYPE
  QualType = G.B(G.A2);
  
PROCEDURE TypeTest(obj: G.Object);
  BEGIN
    Out.Bool(obj IS G.A1); Out.Ln;
    Out.Bool(obj IS G.B(G.A1)); Out.Ln;
    Out.Bool(obj IS G.B(G.A2)); Out.Ln;
  END TypeTest;

PROCEDURE Test*();
  VAR
    a, b: QualType;
  BEGIN
    NEW(a);
    TypeTest(a);
    
    b := NEW(QualType);
    TypeTest(b);
  END Test;

END Generic65.
