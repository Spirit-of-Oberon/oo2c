#include <LoopRewrite8.d>
#include <__oo2c.h>
#include <setjmp.h>

void LoopRewrite8__FindNext(const OOC_CHAR8 pattern[], OOC_LEN pattern_0d, const OOC_CHAR8 stringToSearch[], OOC_LEN stringToSearch_0d, OOC_INT16 startPos, OOC_CHAR8 *patternFound, OOC_INT16 *posOfPattern) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;

  i0 = startPos;
  i1 = (OOC_INT32)stringToSearch+i0;
  i3=i1;i1=i0;i4=i0;i0=0;i2=(OOC_INT32)pattern;
l1_loop:
  i5 = *(OOC_UINT8*)i2;
  i6 = i5==0u;
  if (i6) goto l13;
  i6 = *(OOC_UINT8*)i3;
  i7 = i6==0u;
  if (i7) goto l11;
  i5 = i6==i5;
  if (i5) goto l8;
  i0 = (i3-i0)+1;
  i1 = i4+1;
  i3=i0;i0=0;i2=(OOC_INT32)pattern;
  goto l10;
l8:
  i3 = i3+1;
  i2 = i2+1;
  i1 = i1+1;
  i0 = i0+1;
  
l10:
  i4 = i1-i0;
  
  goto l1_loop;
l11:
  *patternFound = 0u;
  goto l14;
l13:
  *patternFound = 1u;
  *posOfPattern = i4;
l14:
  return;
  ;
}

void OOC_LoopRewrite8_init(void) {

  return;
  ;
}

void OOC_LoopRewrite8_destroy(void) {
}

/* --- */
