#include "./Var10.d"
#include "__oo2c.h"

static OOC_INT16 Var10__F(OOC_CHAR8 b) {
  register OOC_INT32 i0;

  i0 = b;
l2:
  if (!i0) goto l2;
l7:
  return 1;
}

void Var10__Test() {
  register OOC_INT32 i0;

  i0 = Var10__F(OOC_TRUE);
  Out0__Int(i0, 0);
  Out0__Ln();
  return;
}

void Var10_init(void) {

  return;
}

/* --- */
