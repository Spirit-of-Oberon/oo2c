#include "./Swap2.d"
#include "__oo2c.h"

static void Swap2__Swap(OOC_CHAR8 swap) {
  register OOC_INT32 i0,i1,i2;

  i0 = Swap2__x;
  i1 = swap;
  i2 = Swap2__y;
  if (i1) goto l3;
  i1=i2;
  goto l4;
l3:
  i1=i0;i0=i2;
l4:
  Swap2__x = i0;
  Swap2__y = i1;
}

void Swap2__Test() {
  register OOC_INT32 i0;

  Swap2__x = 1;
  Swap2__y = 2;
  Swap2__Swap(OOC_FALSE);
  i0 = Swap2__x;
  Out__Int(i0, 2);
  i0 = Swap2__y;
  Out__Int(i0, 2);
  Out__Ln();
  Swap2__Swap(OOC_TRUE);
  i0 = Swap2__x;
  Out__Int(i0, 2);
  i0 = Swap2__y;
  Out__Int(i0, 2);
  Out__Ln();
  Swap2__Swap(OOC_TRUE);
  i0 = Swap2__x;
  Out__Int(i0, 2);
  i0 = Swap2__y;
  Out__Int(i0, 2);
  Out__Ln();
}

void Swap2_init(void) {

}
