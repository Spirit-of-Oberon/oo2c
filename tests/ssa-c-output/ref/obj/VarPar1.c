#include <VarPar1.d>
#include <__oo2c.h>
#include <setjmp.h>

static OOC_INT16 VarPar1__F(OOC_INT16 *p) {

  *p = 2;
  return 3;
  ;
}

void VarPar1__Test(void) {
  register OOC_INT32 i0;

  i0 = VarPar1__F((void*)(OOC_INT32)&VarPar1__a);
  Out0__Int(i0, 0);
  Out0__Ln();
  return;
  ;
}

void OOC_VarPar1_init(void) {

  return;
  ;
}

/* --- */
