#include <PRE1.d>
#include <__oo2c.h>
#include <setjmp.h>

static OOC_INT16 PRE1__P(OOC_INT16 i, OOC_INT16 a[], OOC_LEN a_0d) {
  register OOC_INT32 i0,i1;

  i0 = i;
  i1 = i0<0;
  if (i1) goto l3;
  i1 = (OOC_INT32)a+i0*2;
  *(OOC_INT16*)i1 = i0;
  i0=i1;
  goto l4;
l3:
  i0=(OOC_INT32)a;
l4:
  i0 = *(OOC_INT16*)i0;
  return i0;
  ;
}

void OOC_PRE1_init(void) {

  return;
  ;
}

void OOC_PRE1_destroy(void) {
}

/* --- */
