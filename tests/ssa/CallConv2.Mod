MODULE CallConv2;

IMPORT C := CallConv1;

VAR
  proc : C.Proc;
  cproc : C.CProc;
  pproc : C.PascalProc;

BEGIN
  proc := C.Example;
  cproc := C.CExample;
  pproc := C.PascalExample;
END CallConv2.
