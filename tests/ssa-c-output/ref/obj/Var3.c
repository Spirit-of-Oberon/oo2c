#include "./Var3.d"
#include "__oo2c.h"

static OOC_INT16 Var3__F(OOC_CHAR8 b) {
  register OOC_INT32 i0;

  i0 = b;
  if (i0) goto l3;
  i0=0;
  goto l4;
l3:
  i0=1;
l4:
  return i0;
}

void Var3__Test() {
  register OOC_INT32 i0;

  i0 = Var3__F(OOC_FALSE);
  Out__Int(i0, 0);
  Out__Ln();
  i0 = Var3__F(OOC_TRUE);
  Out__Int(i0, 0);
  Out__Ln();
}

void Var3_init(void) {
}
