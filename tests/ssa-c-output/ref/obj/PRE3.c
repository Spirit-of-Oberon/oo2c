#include <PRE3.d>
#include <__oo2c.h>
#include <setjmp.h>

void PRE3__T(PRE3__Flags flags) {
  register OOC_INT32 i0,i1;
  PRE3__ModuleFlags mf;

  i0 = (OOC_INT32)flags;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)i0;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG(i1)), &_td_PRE3__ModuleFlagsDesc);
  
l5:
  if (i1) goto l7;
  i0=(OOC_INT32)0;
  goto l8;
l7:
  i0 = (OOC_INT32)*(OOC_INT32*)i0;
  mf = (PRE3__ModuleFlags)i0;
  i1 = (OOC_INT32)*(OOC_INT32*)i0;
  _assert(((
  _cmp8((const void*)i1,(const void*)"FOREIGN"))==0), 127, 530);
  
l8:
  _assert((i0!=(OOC_INT32)0), 127, 573);
  return;
  ;
}

void OOC_PRE3_init(void) {

  return;
  ;
}

/* --- */
