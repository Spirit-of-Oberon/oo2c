#include <LoopRewrite7.d>
#include <__oo2c.h>
#include <setjmp.h>

void LoopRewrite7__CopyArray1(LoopRewrite7__RealArray a, LoopRewrite7__RealArray b, OOC_INT32 len) {
  register OOC_INT32 i0,i1,i2,i3;
  register OOC_REAL32 f0;

  i0 = len;
  i1 = 0<i0;
  if (!i1) goto l8;
  i1 = (OOC_INT32)a;
  i0 = i1+i0*4;
  i2 = (OOC_INT32)b;
  {register OOC_INT32 h0=i1;i1=i2;i2=h0;}
l3_loop:
  f0 = *(OOC_REAL32*)i2;
  *(OOC_REAL32*)i1 = f0;
  i2 = i2+4;
  i1 = i1+4;
  i3 = (OOC_UINT32)i2<(OOC_UINT32)i0;
  if (i3) goto l3_loop;
l8:
  return;
  ;
}

void OOC_LoopRewrite7_init(void) {

  return;
  ;
}

void OOC_LoopRewrite7_destroy(void) {
}

/* --- */
