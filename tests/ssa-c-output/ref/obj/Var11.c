#include <Var11.d>
#include <__oo2c.h>
#include <setjmp.h>

static OOC_INT16 Var11__P(OOC_INT16 i, OOC_INT16 a[], OOC_LEN a_0d) {
  register OOC_INT32 i0,i1;

  i0 = i;
  i1 = i0<0;
  if (i1) goto l3;
  *(OOC_INT16*)((OOC_INT32)a+i0*2) = i0;
  
  goto l4;
l3:
  i0=0;
l4:
  return i0;
  ;
}

void OOC_Var11_init(void) {

  return;
  ;
}

/* --- */
