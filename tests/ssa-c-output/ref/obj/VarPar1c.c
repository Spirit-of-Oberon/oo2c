#include <VarPar1c.d>
#include <__oo2c.h>
#include <setjmp.h>

static OOC_INT32 VarPar1c__F(OOC_INT16 *p) {

  VarPar1c__x = 1;
  *p = 2;
  return 3;
  ;
}

void VarPar1c__Test() {
  register OOC_INT32 i0;

  i0 = VarPar1c__F((void*)(OOC_INT32)&VarPar1c__a);
  Out0__Int(i0, 0);
  Out0__Ln();
  return;
  ;
}

void OOC_VarPar1c_init(void) {

  return;
  ;
}

/* --- */
