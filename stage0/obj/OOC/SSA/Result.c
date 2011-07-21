#include <OOC/SSA/Result.d>
#include <__oo2c.h>
#include <setjmp.h>

void OOC_SSA_Result__GetName(OOC_INT8 _class, OOC_CHAR8 name[], OOC_LEN name_0d) {
  register OOC_INT32 i0;

  i0 = _class;
  switch (i0) {
  case 0:
    _copy_8((const void*)(OOC_CHAR8*)"result",(void*)(OOC_INT32)name,name_0d);
    goto l10;
  case (-2):
    _copy_8((const void*)(OOC_CHAR8*)"void",(void*)(OOC_INT32)name,name_0d);
    goto l10;
  case (-1):
    _copy_8((const void*)(OOC_CHAR8*)"primary",(void*)(OOC_INT32)name,name_0d);
    goto l10;
  case 2:
    _copy_8((const void*)(OOC_CHAR8*)"store",(void*)(OOC_INT32)name,name_0d);
    goto l10;
  case 14:
    _copy_8((const void*)(OOC_CHAR8*)"select-value",(void*)(OOC_INT32)name,name_0d);
    goto l10;
  case 19:
    _copy_8((const void*)(OOC_CHAR8*)"exception",(void*)(OOC_INT32)name,name_0d);
    goto l10;
  case 23:
    _copy_8((const void*)(OOC_CHAR8*)"dgate-placeholder",(void*)(OOC_INT32)name,name_0d);
    goto l10;
  default:
    _failed_case(i0, 3385);
    goto l10;
  }
l10:
  return;
  ;
}

void OOC_OOC_SSA_Result_init(void) {

  return;
  ;
}

void OOC_OOC_SSA_Result_destroy(void) {
}

/* --- */
