#include <Var8.d>
#include <__oo2c.h>
#include <setjmp.h>

static void Var8__Zero(OOC_CHAR8 str[], OOC_LEN str_0d) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = str_0d-1;
  i1 = 0<=i0;
  if (!i1) goto l8;
  i1=0;
l3_loop:
  i2 = i1+1;
  i3 = i2<=i0;
  *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i1, str_0d, OOC_UINT32, 148))) = (OOC_CHAR8)'\000';
  if (!i3) goto l8;
  i1=i2;
  goto l3_loop;
l8:
  return;
  ;
}

void Var8__Test() {
  OOC_CHAR8 s4[4];

  Var8__Zero((void*)(OOC_INT32)s4, 4);
  return;
  ;
}

void OOC_Var8_init(void) {

  return;
  ;
}

/* --- */
