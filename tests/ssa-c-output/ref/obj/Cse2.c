#include "./Cse2.d"
#include "__oo2c.h"

static void Cse2__F(Cse2__P p) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)p;
  i1 = i0!=0;
  if (i1) goto l3;
  i1=OOC_FALSE;
  goto l5;
l3:
  i2 = *(OOC_INT16*)i0;
  i2 = i2!=0;
  i1=i2;
l5:
  if (!i1) goto l8;
  i0 = *(OOC_INT16*)i0;
  Out0__Int(i0, 0);
  Out0__Ln();
l8:
  return;
}

void Cse2__Test() {

  Cse2__F((Cse2__P)0);
  return;
}

void Cse2_init(void) {

  return;
}

/* --- */
