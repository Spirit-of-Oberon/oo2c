#include <LoopRewrite5.d>
#include <__oo2c.h>
#include <setjmp.h>

static void LoopRewrite5__Trim1(OOC_CHAR8 src[], OOC_LEN src_0d, OOC_CHAR8 dest[], OOC_LEN dest_0d) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = *(OOC_UINT8*)(OOC_INT32)src;
  i0 = i0!=0u;
  if (i0) goto l3;
  i0=(OOC_INT32)dest;
  goto l13;
l3:
  i0=(OOC_INT32)src;i1=(OOC_INT32)dest;
l4_loop:
  i2 = *(OOC_UINT8*)i0;
  i3 = (OOC_UINT8)i2>(OOC_UINT8)32u;
  if (!i3) goto l8;
  *(OOC_UINT8*)i1 = i2;
  i1 = i1+1;
  
l8:
  i0 = i0+1;
  i2 = *(OOC_UINT8*)i0;
  i2 = i2!=0u;
  if (i2) goto l4_loop;
l12:
  i0=i1;
l13:
  *(OOC_UINT8*)i0 = 0u;
  return;
  ;
}

static void LoopRewrite5__Trim2(OOC_CHAR16 src[], OOC_LEN src_0d, OOC_CHAR16 dest[], OOC_LEN dest_0d) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = *(OOC_UINT16*)(OOC_INT32)src;
  i0 = i0!=0u;
  if (i0) goto l3;
  i0=(OOC_INT32)dest;
  goto l13;
l3:
  i0=(OOC_INT32)src;i1=(OOC_INT32)dest;
l4_loop:
  i2 = *(OOC_UINT16*)i0;
  i3 = (OOC_UINT16)i2>(OOC_UINT16)32u;
  if (!i3) goto l8;
  *(OOC_UINT16*)i1 = i2;
  i1 = i1+2;
  
l8:
  i0 = i0+2;
  i2 = *(OOC_UINT16*)i0;
  i2 = i2!=0u;
  if (i2) goto l4_loop;
l12:
  i0=i1;
l13:
  *(OOC_UINT16*)i0 = 0u;
  return;
  ;
}

void OOC_LoopRewrite5_init(void) {

  return;
  ;
}

/* --- */
