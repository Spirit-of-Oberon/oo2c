#include <LoopRewrite6.d>
#include <__oo2c.h>
#include <setjmp.h>

static void LoopRewrite6__ZeroArray2(LoopRewrite6__RealArray a, OOC_INT32 len) {
  register OOC_INT32 i0,i1,i2;

  i0 = len;
  i1 = 0<i0;
  if (!i1) goto l8;
  i1 = (OOC_INT32)a;
  i0 = i1+i0*4;
  
l3_loop:
  *(OOC_REAL32*)i1 = 0.0000000000000000f;
  *(OOC_REAL32*)(i1+4) = 0.0000000000000000f;
  i1 = i1+8;
  i2 = (OOC_UINT32)i1<(OOC_UINT32)i0;
  if (i2) goto l3_loop;
l8:
  return;
  ;
}

void OOC_LoopRewrite6_init(void) {

  return;
  ;
}

/* --- */
