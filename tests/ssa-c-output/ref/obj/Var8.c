#include "./Var8.d"
#include "__oo2c.h"

static void Var8__Zero(OOC_CHAR8 str[], OOC_LEN str_0d) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;

  i0 = str_0d-1;
  i1 = 0<=i0;
  if (!i1) goto l10;
  i2=0;
l4_loop:
  i3 = _check_index(i2, str_0d, OOC_UINT32, 148);
  i4 = (OOC_INT32)str+i3;
  i2 = i2+1;
  i5 = i2<=i0;
  *(OOC_UINT8*)i4 = (OOC_CHAR8)'\000';
  if (i5) goto l4_loop;
l10:
  return;
}

void Var8__Test() {
  OOC_CHAR8 s4[4];

  Var8__Zero((void*)(OOC_INT32)s4, 4);
  return;
}

void Var8_init(void) {

  return;
}

/* --- */
