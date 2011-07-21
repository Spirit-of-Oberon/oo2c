#include <OOC/SSA/Opnd.d>
#include <__oo2c.h>
#include <setjmp.h>

void OOC_SSA_Opnd__GetName(OOC_INT8 _class, OOC_CHAR8 name[], OOC_LEN name_0d) {
  register OOC_INT32 i0;

  i0 = _class;
  switch (i0) {
  case 1:
    _copy_8((const void*)"arg",(void*)(OOC_INT32)name,name_0d);
    goto l23;
  case 2:
    _copy_8((const void*)"store",(void*)(OOC_INT32)name,name_0d);
    goto l23;
  case 3:
    _copy_8((const void*)"proc-adr",(void*)(OOC_INT32)name,name_0d);
    goto l23;
  case 4:
    _copy_8((const void*)"read-adr",(void*)(OOC_INT32)name,name_0d);
    goto l23;
  case 5:
    _copy_8((const void*)"read-design",(void*)(OOC_INT32)name,name_0d);
    goto l23;
  case 6:
    _copy_8((const void*)"write-adr",(void*)(OOC_INT32)name,name_0d);
    goto l23;
  case 7:
    _copy_8((const void*)"write-design",(void*)(OOC_INT32)name,name_0d);
    goto l23;
  case 8:
    _copy_8((const void*)"source-value",(void*)(OOC_INT32)name,name_0d);
    goto l23;
  case 9:
    _copy_8((const void*)"function-result",(void*)(OOC_INT32)name,name_0d);
    goto l23;
  case 10:
    _copy_8((const void*)"store-enter",(void*)(OOC_INT32)name,name_0d);
    goto l23;
  case 11:
    _copy_8((const void*)"store-exit",(void*)(OOC_INT32)name,name_0d);
    goto l23;
  case 12:
    _copy_8((const void*)"type",(void*)(OOC_INT32)name,name_0d);
    goto l23;
  case 13:
    _copy_8((const void*)"backward-feed",(void*)(OOC_INT32)name,name_0d);
    goto l23;
  case 15:
    _copy_8((const void*)"dimension",(void*)(OOC_INT32)name,name_0d);
    goto l23;
  case 16:
    _copy_8((const void*)"labels",(void*)(OOC_INT32)name,name_0d);
    goto l23;
  case 17:
    _copy_8((const void*)"loop-external-def",(void*)(OOC_INT32)name,name_0d);
    goto l23;
  case 18:
    _copy_8((const void*)"anti-dependency",(void*)(OOC_INT32)name,name_0d);
    goto l23;
  case 20:
    _copy_8((const void*)"region-dependency",(void*)(OOC_INT32)name,name_0d);
    goto l23;
  case 21:
    _copy_8((const void*)"dgate-base",(void*)(OOC_INT32)name,name_0d);
    goto l23;
  case 22:
    _copy_8((const void*)"dgate-ref",(void*)(OOC_INT32)name,name_0d);
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

/* --- */
