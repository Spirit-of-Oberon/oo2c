#include <Cse2.d>
#include <__oo2c.h>
#include <setjmp.h>

static void Cse2__F(Cse2__P p) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)p;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3;
  i1=OOC_FALSE;
  goto l5;
l3:
  i1 = *(OOC_INT16*)i0;
  i1 = i1!=(OOC_INT32)0;
  
l5:
  if (!i1) goto l7;
  i0 = *(OOC_INT16*)i0;
  Out0__Int(i0, 0);
  Out0__Ln();
l7:
  return;
  ;
}

void Cse2__Test() {

  Cse2__F((Cse2__P)(OOC_INT32)0);
  return;
  ;
}

void OOC_Cse2_init(void) {

  return;
  ;
}

/* --- */
