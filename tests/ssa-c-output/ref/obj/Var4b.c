#include "./Var4b.d"
#include "__oo2c.h"

static OOC_INT16 Var4b__F(OOC_CHAR8 a, OOC_CHAR8 b) {
  register OOC_INT32 i0,i1;

  i0 = a;
  if (i0) goto l5;
  i1 = b;
  if (i1) goto l3;
  Var4b__x = 0;
  i1=0;
  goto l4;
l3:
  Var4b__x = 1;
  i1=1;
l4:
  i0=i1;
  goto l6;
l5:
  Var4b__x = 2;
  i0=2;
l6:
  return i0;
}

void Var4b__Test() {
  register OOC_INT32 i0;

  Var4b__x = -1;
  i0 = Var4b__F(OOC_FALSE, OOC_FALSE);
  Out__Int(i0, 0);
  Out__Ln();
  i0 = Var4b__x;
  Out__Int(i0, 0);
  Out__Ln();
  i0 = Var4b__F(OOC_FALSE, OOC_TRUE);
  Out__Int(i0, 0);
  Out__Ln();
  i0 = Var4b__x;
  Out__Int(i0, 0);
  Out__Ln();
  i0 = Var4b__F(OOC_TRUE, OOC_FALSE);
  Out__Int(i0, 0);
  Out__Ln();
  i0 = Var4b__x;
  Out__Int(i0, 0);
  Out__Ln();
  i0 = Var4b__F(OOC_TRUE, OOC_TRUE);
  Out__Int(i0, 0);
  Out__Ln();
  i0 = Var4b__x;
  Out__Int(i0, 0);
  Out__Ln();
  return;
}

void Var4b_init(void) {
}
