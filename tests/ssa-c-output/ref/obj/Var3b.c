#include "Var3b.d"
#include "__oo2c.h"

static OOC_INT16 Var3b__F(OOC_CHAR8 a, OOC_CHAR8 b) {
  register OOC_INT32 i0;

  i0 = a;
  if (i0) goto l7;
  i0 = b;
  if (i0) goto l5;
  i0=0;
  goto l8;
l5:
  i0=1;
  goto l8;
l7:
  i0=2;
l8:
  return i0;
  ;
}

void Var3b__Test() {
  register OOC_INT32 i0;

  i0 = Var3b__F(OOC_FALSE, OOC_FALSE);
  Out0__Int(i0, 0);
  Out0__Ln();
  i0 = Var3b__F(OOC_FALSE, OOC_TRUE);
  Out0__Int(i0, 0);
  Out0__Ln();
  i0 = Var3b__F(OOC_TRUE, OOC_FALSE);
  Out0__Int(i0, 0);
  Out0__Ln();
  i0 = Var3b__F(OOC_TRUE, OOC_TRUE);
  Out0__Int(i0, 0);
  Out0__Ln();
  return;
  ;
}

void OOC_Var3b_init(void) {

  return;
  ;
}

/* --- */
