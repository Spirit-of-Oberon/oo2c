#include <Alloc1.d>
#include <__oo2c.h>
#include <setjmp.h>

static void Alloc1__F(OOC_INT16 a) {
  register OOC_INT32 i0,i1;

  i0 = a;
  i1 = i0<0;
  if (i1) goto l3;
  Out0__Int((i0-1), 0);
  goto l4;
l3:
  Out0__Int((i0+1), 0);
l4:
  Out0__Ln();
  return;
  ;
}

void Alloc1__Test() {

  Alloc1__F(-1);
  Alloc1__F(1);
  return;
  ;
}

void OOC_Alloc1_init(void) {

  return;
  ;
}

/* --- */
