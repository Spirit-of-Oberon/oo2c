#include "./Record1.d"
#include "__oo2c.h"

static void Record1__Set(OOC_INT16 a, OOC_INT16 b) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)&Record1__r+0;
  i1 = (OOC_INT32)&Record1__r+2;
  i2 = a;
  *(OOC_INT16*)i0 = i2;
  i0 = b;
  *(OOC_INT16*)i1 = i0;
  return;
}

void Record1__Test() {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)&Record1__r+0;
  i1 = (OOC_INT32)&Record1__r+2;
  i2 = (OOC_INT32)&Record1__r+0;
  i3 = (OOC_INT32)&Record1__r+2;
  Record1__Set(1, 2);
  i0 = *(OOC_INT16*)i0;
  Out__Int(i0, 2);
  i0 = *(OOC_INT16*)i1;
  Out__Int(i0, 2);
  Out__Ln();
  Record1__Set(3, 4);
  i0 = *(OOC_INT16*)i2;
  Out__Int(i0, 2);
  i0 = *(OOC_INT16*)i3;
  Out__Int(i0, 2);
  Out__Ln();
  return;
}

void Record1_init(void) {
}
