#include <Var4.d>
#include <__oo2c.h>
#include <setjmp.h>

static OOC_INT16 Var4__F(OOC_CHAR8 b) {
  register OOC_INT32 i0;

  i0 = b;
  if (i0) goto l3;
  Var4__x = 0;
  i0=0;
  goto l4;
l3:
  Var4__x = 1;
  i0=1;
l4:
  return i0;
  ;
}

void Var4__Test() {
  register OOC_INT32 i0;

  Var4__x = -1;
  i0 = Var4__F(OOC_FALSE);
  Out0__Int(i0, 0);
  Out0__Ln();
  i0 = Var4__x;
  Out0__Int(i0, 0);
  Out0__Ln();
  i0 = Var4__F(OOC_TRUE);
  Out0__Int(i0, 0);
  Out0__Ln();
  i0 = Var4__x;
  Out0__Int(i0, 0);
  Out0__Ln();
  return;
  ;
}

void OOC_Var4_init(void) {

  return;
  ;
}

/* --- */
