#include "./Var9.d"
#include "__oo2c.h"

static void Var9__Zero(OOC_CHAR8 str[], OOC_LEN str_0d) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;

  i0 = str_0d;
  i1 = str_0d;
  i2=0;
l1_loop:
  i3 = i2!=i0;
  if (i3) goto l5;
  goto l7;
l5:
  i4 = i2+1;
  i2 = _check_index(i2, i1, OOC_UINT16);
  i5 = i2*1;
  i5 = (OOC_INT32)str+i5;
  *(OOC_UINT8*)i5 = (OOC_CHAR8)'\000';
  i2=i4;
l6:
  
  goto l1_loop;
l7:
  return;
}

void Var9__Test() {
  OOC_CHAR8 Var9__Test_s4[4];

  Var9__Zero((void*)(OOC_INT32)Var9__Test_s4, 4);
  return;
}

void Var9_init(void) {

  return;
}

/* --- */
