#include "./Var5b.d"
#include "__oo2c.h"

static void Var5b__Set(OOC_INT16 y) {
  register OOC_INT32 i0;

  i0 = y;
  Var5b__x = i0;
}

static OOC_INT16 Var5b__F(OOC_CHAR8 b) {
  register OOC_INT32 i0;

  Var5b__z = 0;
  i0 = b;
  if (i0) goto l3;
  Var5b__Set(0);
  goto l4;
l3:
  Var5b__Set(1);
l4:
  i0 = Var5b__x;
  return i0;
}

void Var5b__Test() {
  register OOC_INT32 i0;

  Var5b__x = -1;
  i0 = Var5b__F(OOC_FALSE);
  Out__Int(i0, 0);
  Out__Ln();
  i0 = Var5b__x;
  Out__Int(i0, 0);
  Out__Ln();
  i0 = Var5b__F(OOC_TRUE);
  Out__Int(i0, 0);
  Out__Ln();
  i0 = Var5b__x;
  Out__Int(i0, 0);
  Out__Ln();
}

void Var5b_init(void) {
}
