#include "./Var9.d"
#include "__oo2c.h"

static void Var9__Zero(OOC_CHAR8 str[], OOC_LEN str_0d) {
  register OOC_INT32 i0,i1,i2,i3;

  i0=0;
l1_loop:
  i1 = i0!=str_0d;
  if (!i1) goto l7;
  i2 = _check_index(i0, str_0d, OOC_UINT16, 169);
  i3 = (OOC_INT32)str+i2;
  *(OOC_UINT8*)i3 = (OOC_CHAR8)'\000';
  i0 = i0+1;
  
  goto l1_loop;
l7:
  return;
}

void Var9__Test() {
  OOC_CHAR8 s4[4];

  Var9__Zero((void*)(OOC_INT32)s4, 4);
  return;
}

void Var9_init(void) {

  return;
}

/* --- */
