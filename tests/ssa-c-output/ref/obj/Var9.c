#include "./Var9.d"
#include "__oo2c.h"

static void Var9__Zero(OOC_CHAR8 str[], OOC_LEN str_0d) {
  register OOC_INT32 i0,i1,i2,i3,i4;

  i0 = str_0d;
  i1=0;
l1_loop:
  i2 = i1!=i0;
  i3 = i1+1;
  if (i2) goto l5;
  goto l7;
l5:
  i4 = i1*1;
  i4 = (OOC_INT32)str+i4;
  *(OOC_UINT8*)i4 = '\000';
l6:
  i1=i3;
  goto l1_loop;
l7:
}

void Var9__Test() {
  OOC_CHAR8 Var9__Test_s4[4];

  Var9__Zero((void*)(OOC_INT32)Var9__Test_s4, 4);
}

void Var9_init(void) {

}
