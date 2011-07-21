#include <OOC/SSA/Opnd.d>
#include <__oo2c.h>
#include <setjmp.h>

void OOC_SSA_Opnd__GetName(OOC_INT8 _class, OOC_CHAR8 name[], OOC_LEN name_0d) {
  register OOC_INT32 i0;

  i0 = _class;
  switch (i0) {
  case 1:
    _copy_8((const void*)(OOC_CHAR8*)"arg",(void*)(OOC_INT32)name,name_0d);
    goto l23;
  case 2:
    _copy_8((const void*)(OOC_CHAR8*)"store",(void*)(OOC_INT32)name,name_0d);
    goto l23;
  case 3:
    _copy_8((const void*)(OOC_CHAR8*)"proc-adr",(void*)(OOC_INT32)name,name_0d);
    goto l23;
  case 4:
    _copy_8((const void*)(OOC_CHAR8*)"read-adr",(void*)(OOC_INT32)name,name_0d);
    goto l23;
  case 5:
    _copy_8((const void*)(OOC_CHAR8*)"read-design",(void*)(OOC_INT32)name,name_0d);
    goto l23;
  case 6:
    _copy_8((const void*)(OOC_CHAR8*)"write-adr",(void*)(OOC_INT32)name,name_0d);
    goto l23;
  case 7:
    _copy_8((const void*)(OOC_CHAR8*)"write-design",(void*)(OOC_INT32)name,name_0d);
    goto l23;
  case 8:
    _copy_8((const void*)(OOC_CHAR8*)"source-value",(void*)(OOC_INT32)name,name_0d);
    goto l23;
  case 9:
    _copy_8((const void*)(OOC_CHAR8*)"function-result",(void*)(OOC_INT32)name,name_0d);
    goto l23;
  case 10:
    _copy_8((const void*)(OOC_CHAR8*)"store-enter",(void*)(OOC_INT32)name,name_0d);
    goto l23;
  case 11:
    _copy_8((const void*)(OOC_CHAR8*)"store-exit",(void*)(OOC_INT32)name,name_0d);
    goto l23;
  case 12:
    _copy_8((const void*)(OOC_CHAR8*)"type",(void*)(OOC_INT32)name,name_0d);
    goto l23;
  case 13:
    _copy_8((const void*)(OOC_CHAR8*)"backward-feed",(void*)(OOC_INT32)name,name_0d);
    goto l23;
  case 15:
    _copy_8((const void*)(OOC_CHAR8*)"dimension",(void*)(OOC_INT32)name,name_0d);
    goto l23;
  case 16:
    _copy_8((const void*)(OOC_CHAR8*)"labels",(void*)(OOC_INT32)name,name_0d);
    goto l23;
  case 17:
    _copy_8((const void*)(OOC_CHAR8*)"loop-external-def",(void*)(OOC_INT32)name,name_0d);
    goto l23;
  case 18:
    _copy_8((const void*)(OOC_CHAR8*)"anti-dependency",(void*)(OOC_INT32)name,name_0d);
    goto l23;
  case 20:
    _copy_8((const void*)(OOC_CHAR8*)"region-dependency",(void*)(OOC_INT32)name,name_0d);
    goto l23;
  case 21:
    _copy_8((const void*)(OOC_CHAR8*)"dgate-base",(void*)(OOC_INT32)name,name_0d);
    goto l23;
  case 22:
    _copy_8((const void*)(OOC_CHAR8*)"dgate-ref",(void*)(OOC_INT32)name,name_0d);
    goto l23;
  default:
    _failed_case(i0, 5923);
    goto l23;
  }
l23:
  return;
  ;
}

void OOC_OOC_SSA_Opnd_init(void) {

  return;
  ;
}

void OOC_OOC_SSA_Opnd_destroy(void) {
}

/* --- */
