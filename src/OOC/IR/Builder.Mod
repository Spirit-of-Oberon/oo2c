MODULE OOC:IR:Builder;

IMPORT
  OOC:IR;

TYPE
  Builder* = POINTER TO BuilderDesc;
  BuilderDesc = RECORD
    
  END;


PROCEDURE (b: Builder) NewModule* (name: IR.Name): IR.Module;
  VAR
    m: IR.Module;
  BEGIN
    NEW (m);
    IR.InitModule (m, name);
    RETURN m
  END NewModule;

END OOC:IR:Builder.
