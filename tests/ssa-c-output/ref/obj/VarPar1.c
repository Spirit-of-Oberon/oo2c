#include "./VarPar1.d"
#include "__oo2c.h"

static OOC_INT16 VarPar1__F(OOC_INT16 *p) {
  register OOC_INT32 i0;

  i0 = 1+2;
  *p = 2;
  return i0;
}

void VarPar1__Test() {
  register OOC_INT32 i0;

  i0 = VarPar1__F((void*)(OOC_INT32)&VarPar1__a);
  Out0__Int(i0, 0);
  Out0__Ln();
  return;
}

void VarPar1_init(void) {

  return;
}

/* --- */
