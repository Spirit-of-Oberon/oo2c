#include <LoopRewrite3.d>
#include <__oo2c.h>
#include <setjmp.h>

static OOC_INT32 LoopRewrite3__Len1(OOC_CHAR8 a[], OOC_LEN a_0d) {
  register OOC_INT32 i0,i1;

  i0 = *(OOC_UINT8*)(OOC_INT32)a;
  i0 = i0!=0u;
  if (i0) goto l3;
  i0=0;
  goto l9;
l3:
  i0=(OOC_INT32)a;
l4_loop:
  i0 = i0+1;
  i1 = *(OOC_UINT8*)i0;
  i1 = i1!=0u;
  if (i1) goto l4_loop;
l8:
  i0 = i0-(OOC_INT32)a;
  
l9:
  return i0;
  ;
}

static OOC_INT32 LoopRewrite3__Len2(OOC_CHAR16 a[], OOC_LEN a_0d) {
  register OOC_INT32 i0,i1;

  i0 = *(OOC_UINT16*)(OOC_INT32)a;
  i0 = i0!=0u;
  if (i0) goto l3;
  i0=0;
  goto l9;
l3:
  i0=(OOC_INT32)a;
l4_loop:
  i0 = i0+2;
  i1 = *(OOC_UINT16*)i0;
  i1 = i1!=0u;
  if (i1) goto l4_loop;
l8:
  i0 = (i0-(OOC_INT32)a)>>1;
  
l9:
  return i0;
  ;
}

static OOC_INT32 LoopRewrite3__Len2R(OOC_CHAR16 a[], OOC_LEN a_0d) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)a+(-2);
  
l1_loop:
  i0 = i0+2;
  i1 = *(OOC_UINT16*)i0;
  i1 = i1==0u;
  if (!i1) goto l1_loop;
l5:
  return ((i0-(OOC_INT32)a)>>1);
  ;
}

void OOC_LoopRewrite3_init(void) {

  return;
  ;
}

/* --- */
