#include "Swap1.d"
#include "__oo2c.h"

static void Swap1__Swap() {
  register OOC_INT32 i0,i1;

  i0 = Swap1__x;
  i1 = Swap1__y;
  Swap1__x = i1;
  Swap1__y = i0;
  return;
  ;
}

void Swap1__Test() {
  register OOC_INT32 i0;

  Swap1__x = 1;
  Swap1__y = 2;
  Swap1__Swap();
  i0 = Swap1__x;
  Out0__Int(i0, 2);
  i0 = Swap1__y;
  Out0__Int(i0, 2);
  Out0__Ln();
  Swap1__Swap();
  i0 = Swap1__x;
  Out0__Int(i0, 2);
  i0 = Swap1__y;
  Out0__Int(i0, 2);
  Out0__Ln();
  return;
  ;
}

void OOC_Swap1_init(void) {

  return;
  ;
}

/* --- */
