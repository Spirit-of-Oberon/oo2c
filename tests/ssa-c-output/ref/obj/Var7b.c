#include "./Var7b.d"
#include "__oo2c.h"

static OOC_INT16 Var7b__Len(const OOC_CHAR8 str__ref[], OOC_LEN str_0d) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_CHAR8 *str;
  OOC_PUSH_VPAR_STACK

  i0 = str_0d;
  i0 = i0*1;
  OOC_ALLOCATE_VPAR(str,OOC_CHAR8 ,i0)
  OOC_INITIALIZE_VPAR(str__ref,str,OOC_CHAR8 ,i0)
  i0 = str_0d;
  i1=-1;
l1_loop:
  i1 = i1+1;
  Var7b__i = i1;
  i2 = _check_index(i1, i0, OOC_UINT16);
  i3 = i2*1;
  i3 = (OOC_INT32)str+i3;
  i2 = *(OOC_UINT8*)i3;
  i2 = i2==(OOC_CHAR8)'\000';
  if (i2) goto l4;
  
  goto l1_loop;
l4:
  OOC_POP_VPAR_STACK
  return i1;
}

void Var7b__Test() {
  register OOC_INT32 i0;

  i0 = Var7b__Len((void*)"", 1);
  Out0__Int(i0, 0);
  Out0__Ln();
  i0 = Var7b__Len((void*)"abc", 4);
  Out0__Int(i0, 0);
  Out0__Ln();
  return;
}

void Var7b_init(void) {

  return;
}

/* --- */
