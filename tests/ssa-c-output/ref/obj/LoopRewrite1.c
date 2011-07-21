#include <LoopRewrite1.d>
#include <__oo2c.h>
#include <setjmp.h>

static void LoopRewrite1__Zero1(OOC_CHAR8 a[], OOC_LEN a_0d) {
  register OOC_INT32 i0,i1;

  i0 = *(OOC_UINT8*)(OOC_INT32)a;
  i0 = i0!=0u;
  if (!i0) goto l8;
  i0=(OOC_INT32)a;
l3_loop:
  *(OOC_UINT8*)i0 = 0u;
  i0 = i0+1;
  i1 = *(OOC_UINT8*)i0;
  i1 = i1!=0u;
  if (i1) goto l3_loop;
l8:
  return;
  ;
}

static void LoopRewrite1__Zero2(OOC_INT16 a[], OOC_LEN a_0d) {
  register OOC_INT32 i0,i1;

  i0 = *(OOC_INT16*)(OOC_INT32)a;
  i0 = i0!=0;
  if (!i0) goto l8;
  i0=(OOC_INT32)a;
l3_loop:
  *(OOC_INT16*)i0 = 0;
  i0 = i0+2;
  i1 = *(OOC_INT16*)i0;
  i1 = i1!=0;
  if (i1) goto l3_loop;
l8:
  return;
  ;
}

void OOC_LoopRewrite1_init(void) {

  return;
  ;
}

/* --- */
