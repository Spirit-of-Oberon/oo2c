#include <LoopRewrite2.d>
#include <__oo2c.h>
#include <setjmp.h>

static void LoopRewrite2__Zero1(OOC_CHAR8 a[], OOC_LEN a_0d) {
  register OOC_INT32 i0,i1,i2;

  i0 = 0!=a_0d;
  if (!i0) goto l8;
  i0 = (OOC_INT32)a+a_0d;
  i1=(OOC_INT32)a;
l3_loop:
  *(OOC_UINT8*)i1 = 0u;
  i1 = i1+1;
  i2 = i1!=i0;
  if (i2) goto l3_loop;
l8:
  return;
  ;
}

static void LoopRewrite2__Zero2(OOC_INT16 a[], OOC_LEN a_0d) {
  register OOC_INT32 i0,i1,i2;

  i0 = 0!=a_0d;
  if (!i0) goto l8;
  i0 = (OOC_INT32)a+a_0d*2;
  i1=(OOC_INT32)a;
l3_loop:
  *(OOC_INT16*)i1 = 0;
  i1 = i1+2;
  i2 = i1!=i0;
  if (i2) goto l3_loop;
l8:
  return;
  ;
}

void OOC_LoopRewrite2_init(void) {

  return;
  ;
}

void OOC_LoopRewrite2_destroy(void) {
}

/* --- */
