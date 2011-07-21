#include <Cse3.d>
#include <__oo2c.h>
#include <setjmp.h>

static OOC_INT16 Cse3__F(OOC_INT16 x) {
  register OOC_INT32 i0;

  i0 = x;
  i0 = i0+i0;
  return (i0+i0);
  ;
}

void Cse3__Test(void) {
  register OOC_INT32 i0;

  i0 = Cse3__F(3);
  Out0__Int(i0, 0);
  Out0__Ln();
  return;
  ;
}

void OOC_Cse3_init(void) {

  return;
  ;
}

/* --- */
