#include "./Var6b.d"
#include "__oo2c.h"

static void Var6b__Set(OOC_INT16 y) {
  register OOC_INT32 i0;

  i0 = y;
  Var6b__x = i0;
}

static OOC_INT16 Var6b__F(OOC_CHAR8 b) {
  register OOC_INT32 i0,i1;

  i0 = b;
  if (i0) goto l3;
  Var6b__x = 0;
  i0=0;
  goto l4;
l3:
  Var6b__Set(1);
  i1 = Var6b__x;
  i0=i1;
l4:
  return i0;
}

void Var6b__Test() {
  register OOC_INT32 i0;

  Var6b__x = -1;
  i0 = Var6b__F(OOC_FALSE);
  Out__Int(i0, 0);
  Out__Ln();
  i0 = Var6b__x;
  Out__Int(i0, 0);
  Out__Ln();
  i0 = Var6b__F(OOC_TRUE);
  Out__Int(i0, 0);
  Out__Ln();
  i0 = Var6b__x;
  Out__Int(i0, 0);
  Out__Ln();
}

void Var6b_init(void) {

}
