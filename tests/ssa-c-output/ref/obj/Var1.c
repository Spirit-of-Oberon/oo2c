#include "./Var1.d"
#include "__oo2c.h"

static OOC_INT16 Var1__F(OOC_INT16 x) {
  register OOC_INT32 i0;

  i0 = x;
  return i0;
}

void Var1__Test() {
  register OOC_INT32 i0;

  i0 = Var1__F(0);
  Out__Int(i0, 0);
  Out__Ln();
  i0 = Var1__F(1);
  Out__Int(i0, 0);
  Out__Ln();
}

void Var1_init(void) {

}
