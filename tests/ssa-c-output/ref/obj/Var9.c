#include <Var9.d>
#include <__oo2c.h>
#include <setjmp.h>

static void Var9__Zero(OOC_CHAR8 str[], OOC_LEN str_0d) {
  register OOC_INT32 i0,i1;

  i0=0;
l1_loop:
  i1 = i0!=str_0d;
  if (!i1) goto l6;
  *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT16, 169))) = 0u;
  i0 = i0+1;
  
  goto l1_loop;
l6:
  return;
  ;
}

void Var9__Test() {
  OOC_CHAR8 s4[4];

  Var9__Zero((void*)(OOC_INT32)s4, 4);
  return;
  ;
}

void OOC_Var9_init(void) {

  return;
  ;
}

/* --- */
