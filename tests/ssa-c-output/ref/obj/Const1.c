#include <Const1.d>
#include <__oo2c.h>
#include <setjmp.h>

static OOC_INT16 Const1__F(void) {

  return 12;
  ;
}

void Const1__Test(void) {
  register OOC_INT32 i0;

  i0 = Const1__F();
  Out0__Int(i0, 0);
  Out0__Ln();
  return;
  ;
}

void OOC_Const1_init(void) {

  return;
  ;
}

void OOC_Const1_destroy(void) {
}

/* --- */
