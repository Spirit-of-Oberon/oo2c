MODULE M017;

IMPORT
  E, F;

TYPE
  ExtClass* = POINTER TO ExtClassDesc;
  ExtClassDesc = RECORD
    (E.ClassDesc)
  END;

PROCEDURE (ext: ExtClass) Method*;
  END Method;

END M017.
