#include "./Swap1.d"
#include "__oo2c.h"

static void Swap1__Swap() {
  register OOC_INT32 i0,i1;

  i0 = Swap1__x;
  i1 = Swap1__y;
  Swap1__x = i1;
  Swap1__y = i0;
}

void Swap1__Test() {
  register OOC_INT32 i0;

  Swap1__x = 1;
  Swap1__y = 2;
  Swap1__Swap();
  i0 = Swap1__x;
  Out__Int(i0, 2);
  i0 = Swap1__y;
  Out__Int(i0, 2);
  Out__Ln();
  Swap1__Swap();
  i0 = Swap1__x;
  Out__Int(i0, 2);
  i0 = Swap1__y;
  Out__Int(i0, 2);
  Out__Ln();
}

void Swap1_init(void) {

}
