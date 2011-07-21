#include <Swap2.d>
#include <__oo2c.h>
#include <setjmp.h>

static void Swap2__Swap(OOC_CHAR8 swap) {
  register OOC_INT32 i0,i1,i2;

  i0 = Swap2__x;
  i1 = Swap2__y;
  i2 = swap;
  if (!i2) goto l4;
  {register OOC_INT32 h0=i0;i0=i1;i1=h0;}
l4:
  Swap2__x = i0;
  Swap2__y = i1;
  return;
  ;
}

void Swap2__Test(void) {
  register OOC_INT32 i0;

  Swap2__x = 1;
  Swap2__y = 2;
  Swap2__Swap(0u);
  i0 = Swap2__x;
  Out0__Int(i0, 2);
  i0 = Swap2__y;
  Out0__Int(i0, 2);
  Out0__Ln();
  Swap2__Swap(1u);
  i0 = Swap2__x;
  Out0__Int(i0, 2);
  i0 = Swap2__y;
  Out0__Int(i0, 2);
  Out0__Ln();
  Swap2__Swap(1u);
  i0 = Swap2__x;
  Out0__Int(i0, 2);
  i0 = Swap2__y;
  Out0__Int(i0, 2);
  Out0__Ln();
  return;
  ;
}

void OOC_Swap2_init(void) {

  return;
  ;
}

/* --- */
