#include <VarPar1b.d>
#include <__oo2c.h>
#include <setjmp.h>

static OOC_INT16 VarPar1b__F(OOC_INT16 *p) {
  register OOC_INT32 i0;

  VarPar1b__x = 1;
  *p = 2;
  i0 = VarPar1b__x;
  return (i0+2);
  ;
}

void VarPar1b__Test() {
  register OOC_INT32 i0;

  i0 = VarPar1b__F((void*)(OOC_INT32)&VarPar1b__a);
  Out0__Int(i0, 0);
  Out0__Ln();
  i0 = VarPar1b__F((void*)(OOC_INT32)&VarPar1b__x);
  Out0__Int(i0, 0);
  Out0__Ln();
  return;
  ;
}

void OOC_VarPar1b_init(void) {

  return;
  ;
}

/* --- */
