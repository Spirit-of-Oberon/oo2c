#include <LoopRewrite4.d>
#include <__oo2c.h>
#include <setjmp.h>

static void LoopRewrite4__Zero1(OOC_CHAR8 a[][], OOC_LEN a_0d, OOC_LEN a_1d) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;

  i0 = 0!=a_0d;
  if (!i0) goto l16;
  i0 = (OOC_INT32)a+a_1d;
  i1 = i0+(a_0d*a_1d);
  i2 = 0!=a_1d;
  i3=i0;i0=(OOC_INT32)a;
l3_loop:
  if (!i2) goto l11;
  i4=i0;
l6_loop:
  *(OOC_UINT8*)i4 = 0u;
  i4 = i4+1;
  i5 = i4!=i3;
  if (i5) goto l6_loop;
l11:
  i3 = i3+a_1d;
  i0 = i0+a_1d;
  i4 = i3!=i1;
  if (i4) goto l3_loop;
l16:
  return;
  ;
}

static void LoopRewrite4__Zero2(OOC_INT16 a[][], OOC_LEN a_0d, OOC_LEN a_1d) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;

  i0 = 0!=a_0d;
  if (!i0) goto l16;
  i0 = 2*a_1d;
  i1 = (OOC_INT32)a+a_1d*2;
  i2 = i1+(a_0d*i0);
  i3 = 0!=a_1d;
  i4=i1;i1=(OOC_INT32)a;
l3_loop:
  if (!i3) goto l11;
  i5=i1;
l6_loop:
  *(OOC_INT16*)i5 = 0;
  i5 = i5+2;
  i6 = i5!=i4;
  if (i6) goto l6_loop;
l11:
  i4 = i4+i0;
  i1 = i1+i0;
  i5 = i4!=i2;
  if (i5) goto l3_loop;
l16:
  return;
  ;
}

void OOC_LoopRewrite4_init(void) {

  return;
  ;
}

void OOC_LoopRewrite4_destroy(void) {
}

/* --- */
