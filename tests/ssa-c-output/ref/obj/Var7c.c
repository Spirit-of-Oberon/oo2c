#include "./Var7c.d"
#include "__oo2c.h"

static OOC_INT16 Var7c__Len(const OOC_CHAR8 str__ref[], OOC_LEN str_0d) {
  register OOC_INT32 i0,i1,i2;
  OOC_CHAR8 *str;
  OOC_PUSH_VPAR_STACK

  i0 = str_0d*1;
  OOC_ALLOCATE_VPAR(str,OOC_CHAR8 ,i0)
  OOC_INITIALIZE_VPAR(str__ref,str,OOC_CHAR8 ,i0)
  i0=-1;
l1_loop:
  i0 = i0+1;
  i1 = _check_index(i0, str_0d, OOC_UINT16, 181);
  i2 = i1*1;
  i2 = (OOC_INT32)str+i2;
  i1 = *(OOC_UINT8*)i2;
  i1 = i1==(OOC_CHAR8)'\000';
  if (i1) goto l4;
  
  goto l1_loop;
l4:
  i0 = i0+0;
  OOC_POP_VPAR_STACK
  return i0;
}

void Var7c__Test() {
  register OOC_INT32 i0;

  i0 = Var7c__Len("", 1);
  Out0__Int(i0, 0);
  Out0__Ln();
  i0 = Var7c__Len("abc", 4);
  Out0__Int(i0, 0);
  Out0__Ln();
  return;
}

void Var7c_init(void) {

  return;
}

/* --- */
