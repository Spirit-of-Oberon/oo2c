#include "Var2.d"
#include "__oo2c.h"

static OOC_INT16 Var2__F() {

  Var2__x = 2;
  return 2;
  ;
}

void Var2__Test() {
  register OOC_INT32 i0;

  Var2__x = 0;
  i0 = Var2__F();
  Out0__Int(i0, 0);
  Out0__Ln();
  i0 = Var2__x;
  Out0__Int(i0, 0);
  Out0__Ln();
  return;
  ;
}

void OOC_Var2_init(void) {

  return;
  ;
}

/* --- */
