#include "./Var2.d"
#include "__oo2c.h"

static OOC_INT16 Var2__F() {

  Var2__x = 2;
  return 2;
}

void Var2__Test() {
  register OOC_INT32 i0;

  Var2__x = 0;
  i0 = Var2__F();
  Out__Int(i0, 0);
  Out__Ln();
  i0 = Var2__x;
  Out__Int(i0, 0);
  Out__Ln();
  return;
}

void Var2_init(void) {

  return;
}

/* --- */
