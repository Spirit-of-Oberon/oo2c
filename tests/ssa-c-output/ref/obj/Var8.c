#include "./Var8.d"
#include "__oo2c.h"

static void Var8__Zero(OOC_CHAR8 str[], OOC_LEN str_0d) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;

  i0 = str_0d;
  i0 = i0-1;
  i1 = 0<=i0;
  if (i1) goto l3;
  goto l8;
l3:
  i2 = str_0d;
  i3=0;
l4_loop:
  i4 = _check_index(i3, i2, OOC_UINT16, 126);
  i5 = i4*1;
  i5 = (OOC_INT32)str+i5;
  *(OOC_UINT8*)i5 = (OOC_CHAR8)'\000';
  i3 = i3+1;
  i4 = i3<=i0;
  if (!i4) goto l7;
  
  goto l4_loop;
l7:
l8:
  return;
}

void Var8__Test() {
  OOC_CHAR8 Var8__Test_s4[4];

  Var8__Zero((void*)(OOC_INT32)Var8__Test_s4, 4);
  return;
}

void Var8_init(void) {

  return;
}

/* --- */
