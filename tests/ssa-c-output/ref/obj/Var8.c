#include <Var8.d>
#include <__oo2c.h>
#include <setjmp.h>

static void Var8__Zero(OOC_CHAR8 str[], OOC_LEN str_0d) {
  register OOC_INT32 i0,i1,i2;

  i0 = 0<str_0d;
  if (!i0) goto l8;
  i0=0;
l3_loop:
  i1 = i0+1;
  i2 = i1<str_0d;
  *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 148))) = 0u;
  if (!i2) goto l8;
  i0=i1;
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
