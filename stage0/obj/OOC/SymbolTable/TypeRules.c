#include <OOC/SymbolTable/TypeRules.d>
#include <__oo2c.h>
#include <setjmp.h>

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsNamedType(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)type;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1796))+24);
  return (i0!=(OOC_INT32)0);
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsPredefType(OOC_SymbolTable__Type type, OOC_INT16 id) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2024)))), &_td_OOC_SymbolTable__PredefTypeDesc);
  if (i1) goto l3;
  i0=0u;
  goto l4;
l3:
  i0 = *(OOC_INT16*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2055)))), &_td_OOC_SymbolTable__PredefTypeDesc, 2055)), 2066))+40);
  i1 = id;
  i0 = i0==i1;
  
l4:
  return i0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsScalarType(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2376)))), &_td_OOC_SymbolTable__TypeVarDesc);
  if (i1) goto l11;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2470)))), &_td_OOC_SymbolTable__PredefTypeDesc);
  if (i1) goto l5;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2508)))), &_td_OOC_SymbolTable__PointerDesc);
  
  goto l7;
l5:
  i1=1u;
l7:
  if (i1) goto l9;
  i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2543)))), &_td_OOC_SymbolTable__FormalParsDesc);
  
  goto l10;
l9:
  i0=1u;
l10:
  return i0;
  goto l12;
l11:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2423))+40);
  i0 = OOC_SymbolTable_TypeRules__IsScalarType((OOC_SymbolTable__Type)i0);
  return i0;
l12:
  _failed_function(2109); return 0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsCharType(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2731)))), &_td_OOC_SymbolTable__PredefTypeDesc);
  if (i1) goto l3;
  return 0u;
  goto l4;
l3:
  i0 = *(OOC_INT16*)((_check_pointer(i0, 2769))+40);
  return (_in(i0,14u));
l4:
  _failed_function(2603); return 0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsStringConst(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3024)))), &_td_OOC_SymbolTable__PredefTypeDesc);
  if (i1) goto l3;
  return 0u;
  goto l4;
l3:
  i0 = *(OOC_INT16*)((_check_pointer(i0, 3062))+40);
  return (_in(i0,57344u));
l4:
  _failed_function(2892); return 0;
  ;
}

static OOC_CHAR8 OOC_SymbolTable_TypeRules__ExtendsLibType(OOC_SymbolTable__Type type, const OOC_CHAR8 module__ref[], OOC_LEN module_0d, const OOC_CHAR8 recordName__ref[], OOC_LEN recordName_0d) {
  register OOC_INT32 i0,i1;
  OOC_ALLOCATE_VPAR(module,OOC_CHAR8 ,module_0d)
  OOC_ALLOCATE_VPAR(recordName,OOC_CHAR8 ,recordName_0d)
  OOC_SymbolTable__Type r;

  OOC_INITIALIZE_VPAR(module__ref,module,OOC_CHAR8 ,module_0d)
  OOC_INITIALIZE_VPAR(recordName__ref,recordName,OOC_CHAR8 ,recordName_0d)
  i0 = (OOC_INT32)type;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3326)))), &_td_OOC_SymbolTable__PointerDesc);
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3361)))), &_td_OOC_SymbolTable__PointerDesc, 3361)), 3369))+40);
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3379)))), &_td_OOC_SymbolTable__RecordDesc);
  
l5:
  if (i1) goto l7;
  return 0u;
  goto l49;
l7:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3419)))), &_td_OOC_SymbolTable__PointerDesc, 3419)), 3427))+40);
  r = (OOC_SymbolTable__Type)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l10;
  i1=0u;
  goto l24;
l10:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3478))+24);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l13;
  i1=0u;
  goto l15;
l13:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3516))+24);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3527))+20);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3532))+12);
  i1 = (
  _cmp8((const void*)(_check_pointer(i1, 3536)),(const void*)(OOC_INT32)recordName))==0;
  
l15:
  if (i1) goto l17;
  i1=0u;
  goto l19;
l17:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3571))+24);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3582))+4);
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3590)))), &_td_OOC_SymbolTable__ModuleDesc);
  
l19:
  if (i1) goto l21;
  i1=0u;
  goto l22;
l21:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3624))+24);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3635))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3647)))), &_td_OOC_SymbolTable__ModuleDesc, 3647)), 3654))+20);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3659))+12);
  i1 = (
  _cmp8((const void*)(_check_pointer(i1, 3663)),(const void*)(OOC_INT32)module))==0;
  
l22:
  i1 = !i1;
  
l24:
  if (!i1) goto l48;
l27_loop:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3698)))), &_td_OOC_SymbolTable__RecordDesc, 3698)), 3705))+40);
  r = (OOC_SymbolTable__Type)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l30;
  i1=0u;
  goto l44;
l30:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3478))+24);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l33;
  i1=0u;
  goto l35;
l33:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3516))+24);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3527))+20);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3532))+12);
  i1 = (
  _cmp8((const void*)(_check_pointer(i1, 3536)),(const void*)(OOC_INT32)recordName))==0;
  
l35:
  if (i1) goto l37;
  i1=0u;
  goto l39;
l37:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3571))+24);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3582))+4);
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3590)))), &_td_OOC_SymbolTable__ModuleDesc);
  
l39:
  if (i1) goto l41;
  i1=0u;
  goto l42;
l41:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3624))+24);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3635))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3647)))), &_td_OOC_SymbolTable__ModuleDesc, 3647)), 3654))+20);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3659))+12);
  i1 = (
  _cmp8((const void*)(_check_pointer(i1, 3663)),(const void*)(OOC_INT32)module))==0;
  
l42:
  i1 = !i1;
  
l44:
  if (i1) goto l27_loop;
l48:
  return (i0!=(OOC_INT32)0);
l49:
  _failed_function(3206); return 0;
  ;
}

static OOC_CHAR8 OOC_SymbolTable_TypeRules__IsPointerType(OOC_SymbolTable__Type type, const OOC_CHAR8 module__ref[], OOC_LEN module_0d, const OOC_CHAR8 recordName__ref[], OOC_LEN recordName_0d) {
  register OOC_INT32 i0,i1;
  OOC_ALLOCATE_VPAR(module,OOC_CHAR8 ,module_0d)
  OOC_ALLOCATE_VPAR(recordName,OOC_CHAR8 ,recordName_0d)
  OOC_SymbolTable__Type r;

  OOC_INITIALIZE_VPAR(module__ref,module,OOC_CHAR8 ,module_0d)
  OOC_INITIALIZE_VPAR(recordName__ref,recordName,OOC_CHAR8 ,recordName_0d)
  i0 = (OOC_INT32)type;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3941)))), &_td_OOC_SymbolTable__PointerDesc);
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3976)))), &_td_OOC_SymbolTable__PointerDesc, 3976)), 3984))+40);
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3994)))), &_td_OOC_SymbolTable__RecordDesc);
  
l5:
  if (i1) goto l7;
  return 0u;
  goto l24;
l7:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4034)))), &_td_OOC_SymbolTable__PointerDesc, 4034)), 4042))+40);
  r = (OOC_SymbolTable__Type)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l10;
  i1=0u;
  goto l12;
l10:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4093))+24);
  i1 = i1!=(OOC_INT32)0;
  
l12:
  if (i1) goto l14;
  i1=0u;
  goto l16;
l14:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4130))+24);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4141))+20);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4146))+12);
  i1 = (
  _cmp8((const void*)(_check_pointer(i1, 4150)),(const void*)(OOC_INT32)recordName))==0;
  
l16:
  if (i1) goto l18;
  i1=0u;
  goto l20;
l18:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4184))+24);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4195))+4);
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4203)))), &_td_OOC_SymbolTable__ModuleDesc);
  
l20:
  if (i1) goto l22;
  i0=0u;
  goto l23;
l22:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4236))+24);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4247))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4259)))), &_td_OOC_SymbolTable__ModuleDesc, 4259)), 4266))+20);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4271))+12);
  i0 = (
  _cmp8((const void*)(_check_pointer(i0, 4275)),(const void*)(OOC_INT32)module))==0;
  
l23:
  return i0;
l24:
  _failed_function(3822); return 0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsObject(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)type;
  i0 = OOC_SymbolTable_TypeRules__ExtendsLibType((OOC_SymbolTable__Type)i0, (OOC_CHAR8*)"Object", 7, (OOC_CHAR8*)"ObjectDesc", 11);
  return i0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsObjectType(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)type;
  i0 = OOC_SymbolTable_TypeRules__IsPointerType((OOC_SymbolTable__Type)i0, (OOC_CHAR8*)"Object", 7, (OOC_CHAR8*)"ObjectDesc", 11);
  return i0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsException(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)type;
  i0 = OOC_SymbolTable_TypeRules__ExtendsLibType((OOC_SymbolTable__Type)i0, (OOC_CHAR8*)"Exception", 10, (OOC_CHAR8*)"ExceptionDesc", 14);
  return i0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsSTRING(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)type;
  i0 = OOC_SymbolTable_TypeRules__ExtendsLibType((OOC_SymbolTable__Type)i0, (OOC_CHAR8*)"Object", 7, (OOC_CHAR8*)"StringDesc", 11);
  return i0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsTypeVar(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT32 i;

  i0 = (OOC_INT32)type;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5552)))), &_td_OOC_SymbolTable__TypeVarDesc);
  if (i1) goto l33;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5598)))), &_td_OOC_SymbolTable__TypeClosureDesc);
  if (i1) goto l20;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5792)))), &_td_OOC_SymbolTable__QualTypeDesc);
  if (i1) goto l7;
  return 0u;
  goto l34;
l7:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5838))+48);
  i = 0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 5848)), 0);
  i2 = 0<i1;
  if (!i2) goto l18;
  i2=0;
l10_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5881))+48);
  i3 = _check_pointer(i3, 5891);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 5891))*8);
  i3 = OOC_SymbolTable_TypeRules__IsTypeVar((OOC_SymbolTable__Type)i3);
  if (!i3) goto l13;
  return 1u;
l13:
  i2 = i2+1;
  i = i2;
  i3 = i2<i1;
  if (i3) goto l10_loop;
l18:
  return 0u;
  goto l34;
l20:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5647))+48);
  i = 0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 5657)), 0);
  i2 = 0<i1;
  if (!i2) goto l31;
  i2=0;
l23_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5690))+48);
  i3 = _check_pointer(i3, 5700);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 5700))*8);
  i3 = OOC_SymbolTable_TypeRules__IsTypeVar((OOC_SymbolTable__Type)i3);
  if (!i3) goto l26;
  return 1u;
l26:
  i2 = i2+1;
  i = i2;
  i3 = i2<i1;
  if (i3) goto l23_loop;
l31:
  return 0u;
  goto l34;
l33:
  return 1u;
l34:
  _failed_function(5346); return 0;
  ;
}

OOC_SymbolTable__PredefType OOC_SymbolTable_TypeRules__BaseCharType(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6500)))), &_td_OOC_SymbolTable__PredefTypeDesc);
  if (i1) goto l11;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6874)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (i1) goto l5;
  return (OOC_SymbolTable__PredefType)(OOC_INT32)0;
  goto l18;
l5:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6903))+44);
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6917)))), &_td_OOC_SymbolTable__PredefTypeDesc);
  if (i1) goto l8;
  return (OOC_SymbolTable__PredefType)(OOC_INT32)0;
  goto l18;
l8:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6974))+44);
  i0 = (OOC_INT32)OOC_SymbolTable_TypeRules__BaseCharType((OOC_SymbolTable__Type)i0);
  return (OOC_SymbolTable__PredefType)i0;
  goto l18;
l11:
  i0 = *(OOC_INT16*)((_check_pointer(i0, 6535))+40);
  switch (i0) {
  case 1:
  case 13:
    i0 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(1);
    return (OOC_SymbolTable__PredefType)i0;
    goto l18;
  case 2:
  case 14:
    i0 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(2);
    return (OOC_SymbolTable__PredefType)i0;
    goto l18;
  case 3:
  case 15:
    i0 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(3);
    return (OOC_SymbolTable__PredefType)i0;
    goto l18;
  default:
    return (OOC_SymbolTable__PredefType)(OOC_INT32)0;
    goto l18;
  }
l18:
  _failed_function(6041); return 0;
  ;
}

OOC_SymbolTable__Type OOC_SymbolTable_TypeRules__StringBase(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7208)))), &_td_OOC_SymbolTable__PredefTypeDesc);
  if (i1) goto l3;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7198)))), 7198);
  goto l10;
l3:
  i0 = *(OOC_INT16*)((_check_pointer(i0, 7241))+40);
  switch (i0) {
  case 13:
    i0 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(1);
    return (OOC_SymbolTable__Type)i0;
    goto l10;
  case 14:
    i0 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(2);
    return (OOC_SymbolTable__Type)i0;
    goto l10;
  case 15:
    i0 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(3);
    return (OOC_SymbolTable__Type)i0;
    goto l10;
  default:
    _failed_case(i0, 7232);
    goto l10;
  }
l10:
  _failed_function(7099); return 0;
  ;
}

OOC_SymbolTable__Type OOC_SymbolTable_TypeRules__MatchingStringConst(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0;
  OOC_INT16 id;

  i0 = (OOC_INT32)type;
  i0 = *(OOC_INT16*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7603)))), &_td_OOC_SymbolTable__PredefTypeDesc, 7603)), 7614))+40);
  switch (i0) {
  case 1:
    id = 13;
    goto l6;
  case 2:
    id = 14;
    goto l6;
  case 3:
    id = 15;
    goto l6;
  default:
    _failed_case(i0, 7589);
    goto l6;
  }
l6:
  i0 = id;
  i0 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(i0);
  return (OOC_SymbolTable__Type)i0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsIntegerType(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7966)))), &_td_OOC_SymbolTable__PredefTypeDesc);
  if (i1) goto l3;
  return 0u;
  goto l4;
l3:
  i0 = *(OOC_INT16*)((_check_pointer(i0, 8004))+40);
  return (_in(i0,262384u));
l4:
  _failed_function(7836); return 0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsRealType(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8299)))), &_td_OOC_SymbolTable__PredefTypeDesc);
  if (i1) goto l3;
  return 0u;
  goto l4;
l3:
  i0 = *(OOC_INT16*)((_check_pointer(i0, 8337))+40);
  return (_in(i0,768u));
l4:
  _failed_function(8166); return 0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsNumericType(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i1 = OOC_SymbolTable_TypeRules__IsIntegerType((OOC_SymbolTable__Type)i0);
  if (i1) goto l3;
  i0 = OOC_SymbolTable_TypeRules__IsRealType((OOC_SymbolTable__Type)i0);
  
  goto l4;
l3:
  i0=1u;
l4:
  return i0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsSetType(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8763)))), &_td_OOC_SymbolTable__PredefTypeDesc);
  if (i1) goto l3;
  return 0u;
  goto l4;
l3:
  i0 = *(OOC_INT16*)((_check_pointer(i0, 8801))+40);
  return (_in(i0,1024u));
l4:
  _failed_function(8642); return 0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IncludesType(OOC_SymbolTable__Type large, OOC_SymbolTable__Type small) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT16 largeId;

  i0 = (OOC_INT32)large;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9287)))), &_td_OOC_SymbolTable__PredefTypeDesc);
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)small;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9315)))), &_td_OOC_SymbolTable__PredefTypeDesc);
  
l5:
  if (!i1) goto l30;
  i1 = *(OOC_INT16*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9366)))), &_td_OOC_SymbolTable__PredefTypeDesc, 9366)), 9377))+40);
  largeId = i1;
  i2 = (OOC_INT32)small;
  i3 = *(OOC_INT16*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 9409)))), &_td_OOC_SymbolTable__PredefTypeDesc, 9409)), 9420))+40);
  i4 = OOC_SymbolTable_TypeRules__IsNumericType((OOC_SymbolTable__Type)i0);
  if (i4) goto l24;
  i4 = OOC_SymbolTable_TypeRules__IsCharType((OOC_SymbolTable__Type)i0);
  if (i4) goto l18;
  i0 = OOC_SymbolTable_TypeRules__IsStringConst((OOC_SymbolTable__Type)i0);
  if (!i0) goto l30;
  i0 = OOC_SymbolTable_TypeRules__IsStringConst((OOC_SymbolTable__Type)i2);
  if (i0) goto l15;
  i0=0u;
  goto l16;
l15:
  i0 = i3<=i1;
  
l16:
  return i0;
  goto l30;
l18:
  i0 = OOC_SymbolTable_TypeRules__IsCharType((OOC_SymbolTable__Type)i2);
  if (i0) goto l21;
  i0=0u;
  goto l22;
l21:
  i0 = i3<=i1;
  
l22:
  return i0;
  goto l30;
l24:
  i0 = OOC_SymbolTable_TypeRules__IsNumericType((OOC_SymbolTable__Type)i2);
  if (i0) goto l27;
  i0=0u;
  goto l28;
l27:
  i0 = i3<=i1;
  
l28:
  return i0;
l30:
  return 0u;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsOpenArrayType(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9963)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  type = (OOC_SymbolTable__Type)i0;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9992)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (i1) goto l3;
  i0=0u;
  goto l4;
l3:
  i0 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10017)))), &_td_OOC_SymbolTable__ArrayDesc, 10017)), 10023))+40);
  
l4:
  return i0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsArrayOfChar(OOC_SymbolTable__Type type, OOC_CHAR8 includeFixed) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10383)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (i1) goto l3;
  i1=0u;
  goto l9;
l3:
  i1 = includeFixed;
  if (i1) goto l6;
  i1 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10433)))), &_td_OOC_SymbolTable__ArrayDesc, 10433)), 10439))+40);
  
  goto l9;
l6:
  i1=1u;
l9:
  if (i1) goto l11;
  i0=0u;
  goto l12;
l11:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10485)))), &_td_OOC_SymbolTable__ArrayDesc, 10485)), 10491))+44);
  i0 = OOC_SymbolTable_TypeRules__IsCharType((OOC_SymbolTable__Type)i0);
  
l12:
  return i0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsValidRecordBaseType(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10723)))), &_td_OOC_SymbolTable__QualTypeDesc);
  if (i1) goto l7;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10820)))), &_td_OOC_SymbolTable__RecordDesc);
  if (i1) goto l5;
  i0=0u;
  goto l6;
l5:
  i0 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10846)))), &_td_OOC_SymbolTable__RecordDesc, 10846)), 10853))+58);
  
l6:
  return i0;
  goto l8;
l7:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10780))+40);
  i0 = OOC_SymbolTable_TypeRules__IsValidRecordBaseType((OOC_SymbolTable__Type)i0);
  return i0;
l8:
  _failed_function(10540); return 0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsValidParameterType(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11107)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  type = (OOC_SymbolTable__Type)i0;
  i1 = OOC_SymbolTable_TypeRules__IsNamedType((OOC_SymbolTable__Type)i0);
  if (i1) goto l3;
  i1 = OOC_SymbolTable_TypeRules__IsOpenArrayType((OOC_SymbolTable__Type)i0);
  
  goto l5;
l3:
  i1=1u;
l5:
  if (i1) goto l7;
  i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11206)))), &_td_OOC_SymbolTable__FormalParsDesc);
  
  goto l8;
l7:
  i0=1u;
l8:
  return i0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsValidReceiverType(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11446)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  type = (OOC_SymbolTable__Type)i0;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11483)))), &_td_OOC_SymbolTable__RecordDesc);
  if (i1) goto l7;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11516)))), &_td_OOC_SymbolTable__PointerDesc);
  if (i1) goto l5;
  i0=0u;
  goto l8;
l5:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11553)))), &_td_OOC_SymbolTable__PointerDesc, 11553)), 11561))+40);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11553)))), &_td_OOC_SymbolTable__PointerDesc, 11553)), 11561))+40);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11570)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11581)))), &_td_OOC_SymbolTable__RecordDesc);
  
  goto l8;
l7:
  i0=1u;
l8:
  return i0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsValidResultType(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l3;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11934)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  i0 = OOC_SymbolTable_TypeRules__IsScalarType((OOC_SymbolTable__Type)i0);
  
  goto l4;
l3:
  i0=1u;
l4:
  return i0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsValidPointerBaseType(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12172)))), &_td_OOC_SymbolTable__QualTypeDesc);
  if (i1) goto l7;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12270)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (i1) goto l5;
  i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12293)))), &_td_OOC_SymbolTable__RecordDesc);
  
  goto l6;
l5:
  i0=1u;
l6:
  return i0;
  goto l8;
l7:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12230))+40);
  i0 = OOC_SymbolTable_TypeRules__IsValidPointerBaseType((OOC_SymbolTable__Type)i0);
  return i0;
l8:
  _failed_function(11983); return 0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsValidArrayElementType(OOC_SymbolTable__Type type, OOC_CHAR8 isOpenArray) {
  register OOC_INT32 i0,i1;

  i0 = isOpenArray;
  if (i0) goto l7;
  i0 = (OOC_INT32)type;
  i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12696)))), &_td_OOC_SymbolTable__ArrayDesc));
  if (i1) goto l5;
  i0 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12723)))), &_td_OOC_SymbolTable__ArrayDesc, 12723)), 12729))+40);
  i0 = !i0;
  
  goto l6;
l5:
  i0=1u;
l6:
  return i0;
  goto l8;
l7:
  return 1u;
l8:
  _failed_function(12358); return 0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsValidCaseSelector(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i1 = OOC_SymbolTable_TypeRules__IsIntegerType((OOC_SymbolTable__Type)i0);
  if (i1) goto l3;
  i0 = OOC_SymbolTable_TypeRules__IsCharType((OOC_SymbolTable__Type)i0);
  
  goto l4;
l3:
  i0=1u;
l4:
  return i0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsValidTypeBound(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13258)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  type = (OOC_SymbolTable__Type)i0;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13283)))), &_td_OOC_SymbolTable__PointerDesc);
  if (i1) goto l3;
  return 0u;
  goto l4;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13327)))), &_td_OOC_SymbolTable__PointerDesc, 13327)), 13335))+40);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13327)))), &_td_OOC_SymbolTable__PointerDesc, 13327)), 13335))+40);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 13344)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  type = (OOC_SymbolTable__Type)i0;
  return (OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13375)))), &_td_OOC_SymbolTable__RecordDesc));
l4:
  _failed_function(13064); return 0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__VariableInstance(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13708)))), &_td_OOC_SymbolTable__RecordDesc));
  if (i1) goto l3;
  i0 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13736)))), &_td_OOC_SymbolTable__RecordDesc, 13736)), 13743))+57);
  i0 = !i0;
  
  goto l4;
l3:
  i0=1u;
l4:
  return i0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__SameType(OOC_SymbolTable__Type a, OOC_SymbolTable__Type b) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_SymbolTable__Type baseA;
  OOC_SymbolTable__Type baseB;
  OOC_INT32 i;
  OOC_SymbolTable__TypeVar tv;

  i0 = (OOC_INT32)a;
  i1 = (OOC_INT32)b;
  i2 = i0==i1;
  if (i2) goto l3;
  i2=0u;
  goto l5;
l3:
  i2 = OOC_SymbolTable_TypeRules__IsOpenArrayType((OOC_SymbolTable__Type)i0);
  i2 = !i2;
  
l5:
  if (i2) goto l28;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14555)))), &_td_OOC_SymbolTable__TypeClosureDesc);
  if (i2) goto l9;
  i2=0u;
  goto l11;
l9:
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14580)))), &_td_OOC_SymbolTable__TypeClosureDesc);
  
l11:
  if (!i2) goto l29;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14626)))), &_td_OOC_SymbolTable__TypeClosureDesc, 14626)), 14638))+40);
  baseA = (OOC_SymbolTable__Type)i2;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14670)))), &_td_OOC_SymbolTable__TypeClosureDesc, 14670)), 14682))+40);
  baseB = (OOC_SymbolTable__Type)i3;
  i4 = OOC_SymbolTable_TypeRules__SameType((OOC_SymbolTable__Type)i2, (OOC_SymbolTable__Type)i3);
  if (!i4) goto l29;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14750))+28);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 14767))+28);
  _assert((i4==i3), 127, 14738);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14810))+28);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 14819))+20);
  i = 0;
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 14826)), 0);
  i4 = 0<i3;
  if (!i4) goto l25;
  i4=0;
l17_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14855))+28);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 14864))+20);
  i5 = _check_pointer(i5, 14871);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 14871))*4);
  tv = (OOC_SymbolTable__TypeVar)i5;
  i6 = (OOC_INT32)OOC_SymbolTable__TypeClosureDesc_Lookup((OOC_SymbolTable__TypeClosure)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14963)))), &_td_OOC_SymbolTable__TypeClosureDesc, 14963)), (OOC_SymbolTable__TypeVar)i5, (OOC_SymbolTable__TypeVar)i5);
  i5 = (OOC_INT32)OOC_SymbolTable__TypeClosureDesc_Lookup((OOC_SymbolTable__TypeClosure)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14905)))), &_td_OOC_SymbolTable__TypeClosureDesc, 14905)), (OOC_SymbolTable__TypeVar)i5, (OOC_SymbolTable__TypeVar)i5);
  i5 = OOC_SymbolTable_TypeRules__SameType((OOC_SymbolTable__Type)i5, (OOC_SymbolTable__Type)i6);
  i5 = !i5;
  if (!i5) goto l20;
  return 0u;
l20:
  i4 = i4+1;
  i = i4;
  i5 = i4<i3;
  if (i5) goto l17_loop;
l25:
  return 1u;
  goto l29;
l28:
  return 1u;
l29:
  return 0u;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__EqualTypes(OOC_SymbolTable__Type a, OOC_SymbolTable__Type b) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)a;
  i2 = OOC_SymbolTable_TypeRules__SameType((OOC_SymbolTable__Type)i1, (OOC_SymbolTable__Type)i0);
  if (i2) goto l11;
  i2 = OOC_SymbolTable_TypeRules__IsOpenArrayType((OOC_SymbolTable__Type)i1);
  if (i2) goto l5;
  i2=0u;
  goto l7;
l5:
  i2 = OOC_SymbolTable_TypeRules__IsOpenArrayType((OOC_SymbolTable__Type)i0);
  
l7:
  if (i2) goto l9;
  i2=0u;
  goto l13;
l9:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15478)))), &_td_OOC_SymbolTable__ArrayDesc, 15478)), 15484))+44);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15421)))), &_td_OOC_SymbolTable__ArrayDesc, 15421)), 15427))+44);
  i2 = OOC_SymbolTable_TypeRules__EqualTypes((OOC_SymbolTable__Type)i3, (OOC_SymbolTable__Type)i2);
  
  goto l13;
l11:
  i2=1u;
l13:
  if (i2) goto l23;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15516)))), &_td_OOC_SymbolTable__FormalParsDesc);
  if (i2) goto l17;
  i2=0u;
  goto l19;
l17:
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15540)))), &_td_OOC_SymbolTable__FormalParsDesc);
  
l19:
  if (i2) goto l21;
  i0=0u;
  goto l24;
l21:
  i0 = OOC_SymbolTable_TypeRules__FormalParamsMatch((OOC_SymbolTable__Type)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15599)))), &_td_OOC_SymbolTable__FormalParsDesc, 15599)), (OOC_SymbolTable__FormalPars)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15618)))), &_td_OOC_SymbolTable__FormalParsDesc, 15618)), 0u);
  
  goto l24;
l23:
  i0=1u;
l24:
  return i0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsPointer(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15915)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15926)))), &_td_OOC_SymbolTable__PointerDesc);
  if (i1) goto l3;
  i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15951)))), &_td_OOC_SymbolTable__TypeVarDesc);
  
  goto l4;
l3:
  i0=1u;
l4:
  return i0;
  ;
}

OOC_SymbolTable__Type OOC_SymbolTable_TypeRules__PointerBaseType(OOC_SymbolTable__Type pointer) {
  register OOC_INT32 i0,i1;
  OOC_SymbolTable__Type ptr;

  i0 = (OOC_INT32)pointer;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16152)))), &_td_OOC_SymbolTable__PointerDesc);
  if (i1) goto l3;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16229)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  ptr = (OOC_SymbolTable__Type)i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16278)))), &_td_OOC_SymbolTable__PointerDesc, 16278)), 16286))+40);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16261)))), OOC_SymbolTable__TypeDesc_Closure)),OOC_SymbolTable__TypeDesc_Closure)((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
  return (OOC_SymbolTable__Type)i0;
  goto l4;
l3:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16189))+40);
  return (OOC_SymbolTable__Type)i0;
l4:
  _failed_function(15996); return 0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsRecord(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)type;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16521)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  return (OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16532)))), &_td_OOC_SymbolTable__RecordDesc));
  ;
}

OOC_SymbolTable__Type OOC_SymbolTable_TypeRules__RecordBaseType(OOC_SymbolTable__Type record) {
  register OOC_INT32 i0,i1;
  OOC_SymbolTable__Type ptr;

  i0 = (OOC_INT32)record;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16727)))), &_td_OOC_SymbolTable__RecordDesc);
  if (i1) goto l3;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16801)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  ptr = (OOC_SymbolTable__Type)i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16849)))), &_td_OOC_SymbolTable__RecordDesc, 16849)), 16856))+40);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16832)))), OOC_SymbolTable__TypeDesc_Closure)),OOC_SymbolTable__TypeDesc_Closure)((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
  return (OOC_SymbolTable__Type)i0;
  goto l4;
l3:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16762))+40);
  return (OOC_SymbolTable__Type)i0;
l4:
  _failed_function(16575); return 0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsRecordPointer(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i1 = OOC_SymbolTable_TypeRules__IsPointer((OOC_SymbolTable__Type)i0);
  if (i1) goto l3;
  i0=0u;
  goto l4;
l3:
  i0 = (OOC_INT32)OOC_SymbolTable_TypeRules__PointerBaseType((OOC_SymbolTable__Type)i0);
  i0 = OOC_SymbolTable_TypeRules__IsRecord((OOC_SymbolTable__Type)i0);
  
l4:
  return i0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsArray(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)type;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17311)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  return (OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17322)))), &_td_OOC_SymbolTable__ArrayDesc));
  ;
}

OOC_SymbolTable__Type OOC_SymbolTable_TypeRules__ArrayElementType(OOC_SymbolTable__Type array) {
  register OOC_INT32 i0,i1;
  OOC_SymbolTable__Type ptr;

  i0 = (OOC_INT32)array;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17514)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (i1) goto l3;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17588)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  ptr = (OOC_SymbolTable__Type)i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17635)))), &_td_OOC_SymbolTable__ArrayDesc, 17635)), 17641))+44);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17618)))), OOC_SymbolTable__TypeDesc_Closure)),OOC_SymbolTable__TypeDesc_Closure)((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
  return (OOC_SymbolTable__Type)i0;
  goto l4;
l3:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17547))+44);
  return (OOC_SymbolTable__Type)i0;
l4:
  _failed_function(17363); return 0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsInducedExtensionOf(OOC_SymbolTable__Type type, OOC_SymbolTable__Type base, OOC_CHAR8 ensureInduction) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_SymbolTable__Type ptr;
  OOC_SymbolTable__Type qualBase;

  i0 = (OOC_INT32)type;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17920)))), &_td_OOC_SymbolTable__TypeVarDesc);
  if (!i1) goto l4;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17964)))), &_td_OOC_SymbolTable__TypeVarDesc, 17964)), 17972))+40);
  type = (OOC_SymbolTable__Type)i0;
  
l4:
  i1 = (OOC_INT32)base;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 18002)))), &_td_OOC_SymbolTable__TypeVarDesc);
  if (!i2) goto l7;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 18046)))), &_td_OOC_SymbolTable__TypeVarDesc, 18046)), 18054))+40);
  base = (OOC_SymbolTable__Type)i1;
l7:
  i1 = OOC_SymbolTable_TypeRules__IsPointer((OOC_SymbolTable__Type)i0);
  if (i1) goto l10;
  i1=0u;
  goto l12;
l10:
  i1 = (OOC_INT32)base;
  i1 = OOC_SymbolTable_TypeRules__IsPointer((OOC_SymbolTable__Type)i1);
  
l12:
  if (!i1) goto l15;
  i0 = (OOC_INT32)OOC_SymbolTable_TypeRules__PointerBaseType((OOC_SymbolTable__Type)i0);
  type = (OOC_SymbolTable__Type)i0;
  i1 = (OOC_INT32)base;
  i1 = (OOC_INT32)OOC_SymbolTable_TypeRules__PointerBaseType((OOC_SymbolTable__Type)i1);
  base = (OOC_SymbolTable__Type)i1;
  
l15:
  i1 = OOC_SymbolTable_TypeRules__IsRecord((OOC_SymbolTable__Type)i0);
  if (i1) goto l18;
  i1=0u;
  goto l20;
l18:
  i1 = (OOC_INT32)base;
  i1 = OOC_SymbolTable_TypeRules__IsRecord((OOC_SymbolTable__Type)i1);
  
l20:
  if (!i1) goto l53;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l24;
  i1=0u;
  goto l26;
l24:
  i1 = OOC_SymbolTable_TypeRules__IsRecord((OOC_SymbolTable__Type)i0);
  
l26:
  if (!i1) goto l53;
  i1 = (OOC_INT32)base;
  i2 = ensureInduction;
  
l28_loop:
  i3 = OOC_SymbolTable_TypeRules__SameType((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
  if (i3) goto l42;
  i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18571)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  ptr = (OOC_SymbolTable__Type)i3;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 18613)))), &_td_OOC_SymbolTable__RecordDesc, 18613)), 18620))+40);
  qualBase = (OOC_SymbolTable__Type)i3;
  if (i2) goto l33;
  i4=0u;
  goto l35;
l33:
  i4 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18679)))), &_td_OOC_SymbolTable__TypeClosureDesc);
  
l35:
  if (i4) goto l37;
  i4=0u;
  goto l39;
l37:
  i4 = OOC_SymbolTable__TypeClosureDesc_ArgumentsInduced((OOC_SymbolTable__TypeClosure)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18724)))), &_td_OOC_SymbolTable__TypeClosureDesc, 18724)), (OOC_SymbolTable__Type)i3);
  i4 = !i4;
  
l39:
  if (!i4) goto l41;
  return 0u;
l41:
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18843)))), OOC_SymbolTable__TypeDesc_Closure)),OOC_SymbolTable__TypeDesc_Closure)((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i3);
  type = (OOC_SymbolTable__Type)i0;
  
  goto l43;
l42:
  return 1u;
  
l43:
  i3 = i0!=(OOC_INT32)0;
  if (i3) goto l46;
  i3=0u;
  goto l48;
l46:
  i3 = OOC_SymbolTable_TypeRules__IsRecord((OOC_SymbolTable__Type)i0);
  
l48:
  if (i3) goto l28_loop;
l53:
  return 0u;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsExtensionOf(OOC_SymbolTable__Type type, OOC_SymbolTable__Type base) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)base;
  i1 = (OOC_INT32)type;
  i0 = OOC_SymbolTable_TypeRules__IsInducedExtensionOf((OOC_SymbolTable__Type)i1, (OOC_SymbolTable__Type)i0, 0u);
  return i0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsExtensionOfNoParams(OOC_SymbolTable__Type type, OOC_SymbolTable__Type base) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)type;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19523)))), &_td_OOC_SymbolTable__TypeVarDesc);
  if (!i1) goto l4;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19567)))), &_td_OOC_SymbolTable__TypeVarDesc, 19567)), 19575))+40);
  type = (OOC_SymbolTable__Type)i0;
  
l4:
  i1 = (OOC_INT32)base;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 19605)))), &_td_OOC_SymbolTable__TypeVarDesc);
  if (!i2) goto l7;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 19649)))), &_td_OOC_SymbolTable__TypeVarDesc, 19649)), 19657))+40);
  base = (OOC_SymbolTable__Type)i1;
l7:
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19690)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  type = (OOC_SymbolTable__Type)i0;
  i1 = (OOC_INT32)base;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 19718)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i1);
  base = (OOC_SymbolTable__Type)i1;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19820)))), &_td_OOC_SymbolTable__PointerDesc);
  if (i2) goto l10;
  i2=0u;
  goto l12;
l10:
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 19844)))), &_td_OOC_SymbolTable__PointerDesc);
  
l12:
  if (!i2) goto l15;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19888)))), &_td_OOC_SymbolTable__PointerDesc, 19888)), 19896))+40);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19888)))), &_td_OOC_SymbolTable__PointerDesc, 19888)), 19896))+40);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 19905)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  type = (OOC_SymbolTable__Type)i0;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 19940)))), &_td_OOC_SymbolTable__PointerDesc, 19940)), 19948))+40);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 19940)))), &_td_OOC_SymbolTable__PointerDesc, 19940)), 19948))+40);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 19957)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i1);
  base = (OOC_SymbolTable__Type)i1;
  
l15:
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19991)))), &_td_OOC_SymbolTable__RecordDesc);
  if (i2) goto l18;
  i2=0u;
  goto l20;
l18:
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 20014)))), &_td_OOC_SymbolTable__RecordDesc);
  
l20:
  if (!i2) goto l46;
  i2 = i0!=(OOC_INT32)0;
  if (i2) goto l24;
  i2=0u;
  goto l26;
l24:
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20177)))), &_td_OOC_SymbolTable__RecordDesc);
  
l26:
  if (!i2) goto l46;
l28_loop:
  i2 = OOC_SymbolTable_TypeRules__SameType((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
  if (i2) goto l35;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20295)))), &_td_OOC_SymbolTable__RecordDesc, 20295)), 20302))+40);
  type = (OOC_SymbolTable__Type)i0;
  i2 = i0!=(OOC_INT32)0;
  if (!i2) goto l36;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20368)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  type = (OOC_SymbolTable__Type)i0;
  
  goto l36;
l35:
  return 1u;
  
l36:
  i2 = i0!=(OOC_INT32)0;
  if (i2) goto l39;
  i2=0u;
  goto l41;
l39:
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20177)))), &_td_OOC_SymbolTable__RecordDesc);
  
l41:
  if (i2) goto l28_loop;
l46:
  return 0u;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsValidArrayIteratorRange(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i1 = OOC_SymbolTable_TypeRules__IsArray((OOC_SymbolTable__Type)i0);
  if (i1) goto l3;
  return 0u;
  goto l4;
l3:
  i0 = (OOC_INT32)OOC_SymbolTable_TypeRules__ArrayElementType((OOC_SymbolTable__Type)i0);
  i0 = OOC_SymbolTable_TypeRules__IsValidResultType((OOC_SymbolTable__Type)i0);
  return i0;
l4:
  _failed_function(20485); return 0;
  ;
}

OOC_SymbolTable__Type OOC_SymbolTable_TypeRules__FunctionResultType(OOC_SymbolTable__Type formalPars) {
  register OOC_INT32 i0,i1;
  OOC_SymbolTable__Type ptr;

  i0 = (OOC_INT32)formalPars;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20993)))), &_td_OOC_SymbolTable__FormalParsDesc);
  if (i1) goto l3;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21081)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  ptr = (OOC_SymbolTable__Type)i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 21133)))), &_td_OOC_SymbolTable__FormalParsDesc, 21133)), 21144))+44);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21116)))), OOC_SymbolTable__TypeDesc_Closure)),OOC_SymbolTable__TypeDesc_Closure)((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
  return (OOC_SymbolTable__Type)i0;
  goto l4;
l3:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21036))+44);
  return (OOC_SymbolTable__Type)i0;
l4:
  _failed_function(20823); return 0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__CallingConventionsMatch(OOC_INT8 a, OOC_INT8 b) {
  register OOC_INT32 i0,i1;

  i0 = a;
  i1 = i0==(-1);
  if (i1) goto l3;
  i1 = b;
  i1 = i1==(-1);
  
  goto l5;
l3:
  i1=1u;
l5:
  if (i1) goto l11;
  i1 = _in(i0,5u);
  if (i1) goto l9;
  i1 = b;
  return (i0==i1);
  goto l12;
l9:
  i0 = b;
  return (_in(i0,5u));
  goto l12;
l11:
  return 0u;
l12:
  _failed_function(21204); return 0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__FormalParamsMatch(OOC_SymbolTable__Type baseFParsClosure, OOC_SymbolTable__FormalPars procFPars, OOC_CHAR8 allowSpecialization) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  OOC_SymbolTable__Type ptr;
  OOC_SymbolTable__FormalPars baseFPars;
  OOC_SymbolTable__Type baseResult;
  OOC_INT32 i;
  OOC_INT32 j;

  i0 = (OOC_INT32)baseFParsClosure;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23177)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  ptr = (OOC_SymbolTable__Type)i1;
  i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 23214)))), &_td_OOC_SymbolTable__FormalParsDesc, 23214);
  baseFPars = (OOC_SymbolTable__FormalPars)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23244))+44);
  i2 = i2==(OOC_INT32)0;
  if (i2) goto l3;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23356))+44);
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23338)))), OOC_SymbolTable__TypeDesc_Closure)),OOC_SymbolTable__TypeDesc_Closure)((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i2);
  baseResult = (OOC_SymbolTable__Type)i2;
  
  goto l4;
l3:
  baseResult = (OOC_SymbolTable__Type)(OOC_INT32)0;
  i2=(OOC_INT32)0;
l4:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23406))+52);
  i4 = (OOC_INT32)procFPars;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 23433))+52);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 23414)), 0);
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 23441)), 0);
  i3 = i3!=i5;
  if (i3) goto l149;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 23511))+44);
  i3 = (i2==(OOC_INT32)0)!=(i3==(OOC_INT32)0);
  if (i3) goto l147;
  i3 = i2!=(OOC_INT32)0;
  if (i3) goto l11;
  i5=0u;
  goto l13;
l11:
  i5 = allowSpecialization;
  i5 = !i5;
  
l13:
  if (i5) goto l15;
  i5=0u;
  goto l17;
l15:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 23676))+44);
  i5 = (OOC_INT32)OOC_SymbolTable__Expand((OOC_SymbolTable__Type)i5);
  i5 = OOC_SymbolTable_TypeRules__SameType((OOC_SymbolTable__Type)i2, (OOC_SymbolTable__Type)i5);
  i5 = !i5;
  
l17:
  if (i5) goto l145;
l19:
  if (i3) goto l21;
  i3=0u;
  goto l23;
l21:
  i3 = allowSpecialization;
  
l23:
  if (i3) goto l25;
  i2=0u;
  goto l31;
l25:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 23831))+44);
  i3 = (OOC_INT32)OOC_SymbolTable__Expand((OOC_SymbolTable__Type)i3);
  i3 = OOC_SymbolTable_TypeRules__SameType((OOC_SymbolTable__Type)i2, (OOC_SymbolTable__Type)i3);
  if (i3) goto l28;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 23894))+44);
  i3 = (OOC_INT32)OOC_SymbolTable__Expand((OOC_SymbolTable__Type)i3);
  i2 = OOC_SymbolTable_TypeRules__IsExtensionOf((OOC_SymbolTable__Type)i3, (OOC_SymbolTable__Type)i2);
  
  goto l29;
l28:
  i2=1u;
l29:
  i2 = !i2;
  
l31:
  if (i2) goto l143;
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 23965))+56);
  i3 = *(OOC_UINT8*)((_check_pointer(i4, 23996))+56);
  i2 = i2!=i3;
  if (i2) goto l141;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 24084))+52);
  i = 0;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 24092)), 0);
  i3 = 0<i2;
  if (!i3) goto l49;
  i3=0;
l37_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 24121))+52);
  i5 = _check_pointer(i5, 24129);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 24129))*4);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 24169))+52);
  i6 = _check_pointer(i6, 24177);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i3, i7, OOC_UINT32, 24177))*4);
  i5 = *(OOC_UINT8*)((_check_pointer(i5, 24132))+59);
  i6 = *(OOC_UINT8*)((_check_pointer(i6, 24180))+59);
  i5 = i5!=i6;
  if (i5) goto l40;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 24318))+52);
  i5 = _check_pointer(i5, 24325);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 24325))*4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 24328))+48);
  i5 = (OOC_INT32)OOC_SymbolTable__Expand((OOC_SymbolTable__Type)i5);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 24255))+52);
  i6 = _check_pointer(i6, 24262);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i3, i7, OOC_UINT32, 24262))*4);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 24265))+48);
  i6 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 24237)))), OOC_SymbolTable__TypeDesc_Closure)),OOC_SymbolTable__TypeDesc_Closure)((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i6);
  i5 = OOC_SymbolTable_TypeRules__EqualTypes((OOC_SymbolTable__Type)i6, (OOC_SymbolTable__Type)i5);
  i5 = !i5;
  
  goto l42;
l40:
  i5=1u;
l42:
  if (!i5) goto l44;
  return 0u;
l44:
  i3 = i3+1;
  i = i3;
  i5 = i3<i2;
  if (i5) goto l37_loop;
l49:
  i0 = allowSpecialization;
  if (i0) goto l108;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 25081))+60);
  i = 0;
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 25088)), 0);
  i2 = 0<i0;
  if (!i2) goto l79;
  i2=0;
l54_loop:
  j = 0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 25148))+60);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 25155)), 0);
  i3 = 0!=i3;
  if (i3) goto l57;
  i3=0u;
  goto l59;
l57:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 25248))+60);
  i3 = _check_pointer(i3, 25255);
  i5 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i5, OOC_UINT32, 25255))*4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 25196))+60);
  i5 = _check_pointer(i5, 25203);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(0, i6, OOC_UINT32, 25203))*4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 25258))+20);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 25206))+20);
  i3 = OOC_SymbolTable_TypeRules__SameType((OOC_SymbolTable__Type)i5, (OOC_SymbolTable__Type)i3);
  i3 = !i3;
  
l59:
  if (i3) goto l61;
  i3=0;
  goto l71;
l61:
  i3=0;
l62_loop:
  i3 = i3+1;
  j = i3;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 25148))+60);
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 25155)), 0);
  i5 = i3!=i5;
  if (i5) goto l65;
  i5=0u;
  goto l67;
l65:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 25248))+60);
  i5 = _check_pointer(i5, 25255);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i2, i6, OOC_UINT32, 25255))*4);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 25196))+60);
  i6 = _check_pointer(i6, 25203);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i3, i7, OOC_UINT32, 25203))*4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 25258))+20);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 25206))+20);
  i5 = OOC_SymbolTable_TypeRules__SameType((OOC_SymbolTable__Type)i6, (OOC_SymbolTable__Type)i5);
  i5 = !i5;
  
l67:
  if (i5) goto l62_loop;
l71:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 25334))+60);
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 25341)), 0);
  i3 = i3==i5;
  if (!i3) goto l74;
  return 0u;
l74:
  i2 = i2+1;
  i = i2;
  i3 = i2<i0;
  if (i3) goto l54_loop;
l79:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 25454))+60);
  i = 0;
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 25461)), 0);
  i2 = 0<i0;
  if (!i2) goto l137;
  i2=0;
l82_loop:
  j = 0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 25521))+60);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 25528)), 0);
  i3 = 0!=i3;
  if (i3) goto l85;
  i3=0u;
  goto l87;
l85:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 25621))+60);
  i3 = _check_pointer(i3, 25628);
  i5 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i5, OOC_UINT32, 25628))*4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 25569))+60);
  i5 = _check_pointer(i5, 25576);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(0, i6, OOC_UINT32, 25576))*4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 25631))+20);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 25579))+20);
  i3 = OOC_SymbolTable_TypeRules__SameType((OOC_SymbolTable__Type)i5, (OOC_SymbolTable__Type)i3);
  i3 = !i3;
  
l87:
  if (i3) goto l89;
  i3=0;
  goto l99;
l89:
  i3=0;
l90_loop:
  i3 = i3+1;
  j = i3;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 25521))+60);
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 25528)), 0);
  i5 = i3!=i5;
  if (i5) goto l93;
  i5=0u;
  goto l95;
l93:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 25621))+60);
  i5 = _check_pointer(i5, 25628);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i2, i6, OOC_UINT32, 25628))*4);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 25569))+60);
  i6 = _check_pointer(i6, 25576);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i3, i7, OOC_UINT32, 25576))*4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 25631))+20);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 25579))+20);
  i5 = OOC_SymbolTable_TypeRules__SameType((OOC_SymbolTable__Type)i6, (OOC_SymbolTable__Type)i5);
  i5 = !i5;
  
l95:
  if (i5) goto l90_loop;
l99:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 25707))+60);
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 25714)), 0);
  i3 = i3==i5;
  if (!i3) goto l102;
  return 0u;
l102:
  i2 = i2+1;
  i = i2;
  i3 = i2<i0;
  if (i3) goto l82_loop;
  goto l137;
l108:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 24457))+60);
  i = 0;
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 24464)), 0);
  i2 = 0<i0;
  if (!i2) goto l137;
  i2=0;
l111_loop:
  j = 0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 24524))+60);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 24531)), 0);
  i3 = 0!=i3;
  if (i3) goto l114;
  i3=0u;
  goto l116;
l114:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 24634))+60);
  i3 = _check_pointer(i3, 24641);
  i5 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i5, OOC_UINT32, 24641))*4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 24577))+60);
  i5 = _check_pointer(i5, 24584);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(0, i6, OOC_UINT32, 24584))*4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 24644))+20);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 24587))+20);
  i3 = OOC_SymbolTable_TypeRules__IsExtensionOf((OOC_SymbolTable__Type)i5, (OOC_SymbolTable__Type)i3);
  i3 = !i3;
  
l116:
  if (i3) goto l118;
  i3=0;
  goto l128;
l118:
  i3=0;
l119_loop:
  i3 = i3+1;
  j = i3;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 24524))+60);
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 24531)), 0);
  i5 = i3!=i5;
  if (i5) goto l122;
  i5=0u;
  goto l124;
l122:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 24634))+60);
  i5 = _check_pointer(i5, 24641);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i2, i6, OOC_UINT32, 24641))*4);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 24577))+60);
  i6 = _check_pointer(i6, 24584);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i3, i7, OOC_UINT32, 24584))*4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 24644))+20);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 24587))+20);
  i5 = OOC_SymbolTable_TypeRules__IsExtensionOf((OOC_SymbolTable__Type)i6, (OOC_SymbolTable__Type)i5);
  i5 = !i5;
  
l124:
  if (i5) goto l119_loop;
l128:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 24720))+60);
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 24727)), 0);
  i3 = i3==i5;
  if (!i3) goto l131;
  return 0u;
l131:
  i2 = i2+1;
  i = i2;
  i3 = i2<i0;
  if (i3) goto l111_loop;
l137:
  i0 = *(OOC_INT8*)((_check_pointer(i4, 25867))+58);
  i1 = *(OOC_INT8*)((_check_pointer(i1, 25847))+58);
  i0 = OOC_SymbolTable_TypeRules__CallingConventionsMatch(i1, i0);
  i0 = !i0;
  if (!i0) goto l140;
  return 0u;
l140:
  return 1u;
  goto l150;
l141:
  return 0u;
  goto l150;
l143:
  return 0u;
  goto l150;
l145:
  return 0u;
  goto l150;
l147:
  return 0u;
  goto l150;
l149:
  return 0u;
l150:
  _failed_function(21779); return 0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsValidRedefinition(OOC_SymbolTable__Type baseFParsClosure, OOC_SymbolTable__FormalPars procFPars) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_SymbolTable__Type baseFPars;

  i0 = (OOC_INT32)baseFParsClosure;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26302)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  baseFPars = (OOC_SymbolTable__Type)i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 26346)))), &_td_OOC_SymbolTable__FormalParsDesc, 26346)), 26357))+40);
  i2 = (OOC_INT32)procFPars;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 26396))+40);
  i1 = *(OOC_UINT8*)((_check_pointer(i1, 26366))+59);
  i3 = *(OOC_UINT8*)((_check_pointer(i3, 26405))+59);
  i1 = i1==i3;
  if (i1) goto l3;
  i0=0u;
  goto l4;
l3:
  i0 = OOC_SymbolTable_TypeRules__FormalParamsMatch((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__FormalPars)i2, 1u);
  
l4:
  return i0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsValidForwardDecl(OOC_SymbolTable__FormalPars forward, OOC_SymbolTable__FormalPars proc) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)forward;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26718))+40);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l3;
  i1 = (OOC_INT32)proc;
  i0 = OOC_SymbolTable_TypeRules__FormalParamsMatch((OOC_SymbolTable__Type)i1, (OOC_SymbolTable__FormalPars)i0, 0u);
  return i0;
  goto l4;
l3:
  i1 = (OOC_INT32)proc;
  i0 = OOC_SymbolTable_TypeRules__IsValidRedefinition((OOC_SymbolTable__Type)i1, (OOC_SymbolTable__FormalPars)i0);
  return i0;
l4:
  _failed_function(26518); return 0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsArrayType(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)type;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 27062)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  return (OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 27073)))), &_td_OOC_SymbolTable__ArrayDesc));
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsArrayCompatible(OOC_SymbolTable__Type argType, OOC_SymbolTable__Type fparType) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)fparType;
  i1 = OOC_SymbolTable_TypeRules__IsOpenArrayType((OOC_SymbolTable__Type)i0);
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)argType;
  i1 = OOC_SymbolTable_TypeRules__IsArrayType((OOC_SymbolTable__Type)i1);
  
l5:
  if (!i1) goto l17;
l8_loop:
  i1 = (OOC_INT32)argType;
  i1 = (OOC_INT32)OOC_SymbolTable_TypeRules__ArrayElementType((OOC_SymbolTable__Type)i1);
  argType = (OOC_SymbolTable__Type)i1;
  i0 = (OOC_INT32)OOC_SymbolTable_TypeRules__ArrayElementType((OOC_SymbolTable__Type)i0);
  i2 = OOC_SymbolTable_TypeRules__IsOpenArrayType((OOC_SymbolTable__Type)i0);
  if (i2) goto l11;
  i1=0u;
  goto l13;
l11:
  i1 = OOC_SymbolTable_TypeRules__IsArrayType((OOC_SymbolTable__Type)i1);
  
l13:
  if (i1) goto l8_loop;
l17:
  i1 = (OOC_INT32)argType;
  i0 = OOC_SymbolTable_TypeRules__SameType((OOC_SymbolTable__Type)i1, (OOC_SymbolTable__Type)i0);
  return i0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsComponentOf(OOC_SymbolTable__Type subType, OOC_SymbolTable__Type superType, OOC_CHAR8 arrayCompat) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_SymbolTable__Item field;

  i0 = (OOC_INT32)subType;
  i1 = (OOC_INT32)superType;
  i2 = OOC_SymbolTable_TypeRules__EqualTypes((OOC_SymbolTable__Type)i1, (OOC_SymbolTable__Type)i0);
  if (i2) goto l3;
  i2 = OOC_SymbolTable_TypeRules__IsExtensionOf((OOC_SymbolTable__Type)i1, (OOC_SymbolTable__Type)i0);
  
  goto l5;
l3:
  i2=1u;
l5:
  if (i2) goto l45;
  i2 = arrayCompat;
  if (i2) goto l9;
  i3=0u;
  goto l11;
l9:
  i3 = OOC_SymbolTable_TypeRules__IsArrayCompatible((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
  
l11:
  if (i3) goto l43;
  i3 = OOC_SymbolTable_TypeRules__IsArray((OOC_SymbolTable__Type)i1);
  if (i3) goto l41;
  i3 = OOC_SymbolTable_TypeRules__IsRecord((OOC_SymbolTable__Type)i1);
  if (i3) goto l17;
  return 0u;
  goto l46;
l17:
  i3 = i1!=(OOC_INT32)0;
  if (!i3) goto l39;
  
l20_loop:
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 28679)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i1);
  superType = (OOC_SymbolTable__Type)i1;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 28717))+8);
  field = (OOC_SymbolTable__Item)i3;
  i4 = i3!=(OOC_INT32)0;
  if (!i4) goto l34;
l23_loop:
  i4 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 28783)))), &_td_OOC_SymbolTable__FieldDeclDesc);
  if (!i4) goto l29;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 28846))+48);
  i4 = OOC_SymbolTable_TypeRules__IsComponentOf((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i4, i2);
  if (!i4) goto l29;
  return 1u;
l29:
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 29016));
  field = (OOC_SymbolTable__Item)i3;
  i4 = i3!=(OOC_INT32)0;
  if (i4) goto l23_loop;
l34:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 29077)))), &_td_OOC_SymbolTable__RecordDesc, 29077)), 29084))+40);
  superType = (OOC_SymbolTable__Type)i1;
  i3 = i1!=(OOC_INT32)0;
  if (i3) goto l20_loop;
l39:
  return 0u;
  goto l46;
l41:
  i1 = (OOC_INT32)OOC_SymbolTable_TypeRules__ArrayElementType((OOC_SymbolTable__Type)i1);
  i0 = OOC_SymbolTable_TypeRules__IsComponentOf((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1, i2);
  return i0;
  goto l46;
l43:
  return 1u;
  goto l46;
l45:
  return 1u;
l46:
  _failed_function(27810); return 0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsByteCompatible(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 29360)))), &_td_OOC_SymbolTable__PredefTypeDesc);
  if (i1) goto l3;
  return 0u;
  goto l8;
l3:
  i1 = *(OOC_INT16*)((_check_pointer(i0, 29398))+40);
  i1 = i1==1;
  if (i1) goto l6;
  i0 = *(OOC_INT16*)((_check_pointer(i0, 29426))+40);
  i0 = i0==4;
  
  goto l7;
l6:
  i0=1u;
l7:
  return i0;
l8:
  _failed_function(29193); return 0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsPtrCompatible(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)type;
  i0 = OOC_SymbolTable_TypeRules__IsPointer((OOC_SymbolTable__Type)i0);
  return i0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsNilCompatible(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 29969)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  type = (OOC_SymbolTable__Type)i0;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 29994)))), &_td_OOC_SymbolTable__PredefTypeDesc);
  if (i1) goto l15;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 30088)))), &_td_OOC_SymbolTable__PointerDesc);
  if (i1) goto l13;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 30134)))), &_td_OOC_SymbolTable__FormalParsDesc);
  if (i1) goto l11;
  i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 30183)))), &_td_OOC_SymbolTable__TypeVarDesc);
  if (i0) goto l9;
  return 0u;
  goto l20;
l9:
  return 1u;
  goto l20;
l11:
  return 1u;
  goto l20;
l13:
  return 1u;
  goto l20;
l15:
  i1 = *(OOC_INT16*)((_check_pointer(i0, 30032))+40);
  i1 = i1==12;
  if (i1) goto l18;
  i0 = *(OOC_INT16*)((_check_pointer(i0, 30059))+40);
  i0 = i0==16;
  
  goto l19;
l18:
  i0=1u;
l19:
  return i0;
l20:
  _failed_function(29738); return 0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsReadOnly(OOC_SymbolTable__Module usingModule, OOC_SymbolTable__Declaration decl) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)decl;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 30505))+28);
  i1 = i1==2;
  if (i1) goto l3;
  i0=0u;
  goto l4;
l3:
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 30555)))), OOC_SymbolTable__ItemDesc_Module)),OOC_SymbolTable__ItemDesc_Module)((OOC_SymbolTable__Item)i0);
  i1 = (OOC_INT32)usingModule;
  i0 = i0!=i1;
  
l4:
  return i0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsReadOnlyType(OOC_SymbolTable__Module usingModule, OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 30816)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 30849)))), &_td_OOC_SymbolTable__ArrayDesc, 30849)), 30855))+42);
  
l5:
  if (i1) goto l7;
  i0=0u;
  goto l8;
l7:
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 30886)))), OOC_SymbolTable__ItemDesc_Module)),OOC_SymbolTable__ItemDesc_Module)((OOC_SymbolTable__Item)i0);
  i1 = (OOC_INT32)usingModule;
  i0 = i0!=i1;
  
l8:
  return i0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsAtomicType(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1,i2;
  OOC_CHAR8 result;
  OOC_SymbolTable__Item nested;

  i0 = (OOC_INT32)type;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31371)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  type = (OOC_SymbolTable__Type)i0;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31395)))), &_td_OOC_SymbolTable__PointerDesc);
  if (i1) goto l48;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31441)))), &_td_OOC_SymbolTable__TypeVarDesc);
  if (i1) goto l46;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31485)))), &_td_OOC_SymbolTable__PredefTypeDesc);
  if (i1) goto l44;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31548)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (i1) goto l42;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31618)))), &_td_OOC_SymbolTable__RecordDesc);
  if (i1) goto l11;
  result = 1u;
  
  goto l49;
l11:
  result = 1u;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31665))+40);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l14;
  i1=1u;
  goto l15;
l14:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31719))+40);
  i1 = OOC_SymbolTable_TypeRules__IsAtomicType((OOC_SymbolTable__Type)i1);
  result = i1;
  
l15:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31758))+8);
  nested = (OOC_SymbolTable__Item)i0;
  if (i1) goto l18;
  i2=0u;
  goto l20;
l18:
  i2 = i0!=(OOC_INT32)0;
  
l20:
  if (!i2) goto l49;
l23_loop:
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31827)))), &_td_OOC_SymbolTable__FieldDeclDesc);
  if (!i2) goto l31;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31877))+48);
  i2 = OOC_SymbolTable_TypeRules__IsAtomicType((OOC_SymbolTable__Type)i2);
  i2 = !i2;
  if (!i2) goto l31;
  result = 0u;
  i1=0u;
l31:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 31987));
  nested = (OOC_SymbolTable__Item)i0;
  if (i1) goto l34;
  i2=0u;
  goto l36;
l34:
  i2 = i0!=(OOC_INT32)0;
  
l36:
  if (i2) goto l23_loop;
  goto l49;
l42:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31594))+44);
  i0 = OOC_SymbolTable_TypeRules__IsAtomicType((OOC_SymbolTable__Type)i0);
  result = i0;
  
  goto l49;
l44:
  i0 = *(OOC_INT16*)((_check_pointer(i0, 31520))+40);
  return (i0!=12);
  goto l49;
l46:
  return 0u;
  goto l49;
l48:
  result = 0u;
l49:
  i0 = result;
  return i0;
  ;
}

void OOC_SymbolTable_TypeRules__AllocateType(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  OOC_INT32 i;
  OOC_INT16 align;
  OOC_INT32 size;
  OOC_INT16 maxAlign;
  OOC_SymbolTable__Item nested;
  OOC_INT16 fieldAlign;

  i0 = (OOC_INT32)type;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 33069))+32);
  i1 = i1==(-2);
  if (!i1) goto l97;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33225)))), &_td_OOC_SymbolTable__PointerDesc);
  if (i1) goto l95;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33603)))), &_td_OOC_SymbolTable__FormalParsDesc);
  if (i1) goto l82;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34010)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (i1) goto l73;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34586)))), &_td_OOC_SymbolTable__RecordDesc);
  if (i1) goto l19;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37198)))), &_td_OOC_SymbolTable__TypeVarDesc);
  if (i1) goto l17;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37319)))), &_td_OOC_SymbolTable__QualTypeDesc);
  if (i1) goto l15;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37313)))), 37313);
  goto l97;
l15:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37362))+40);
  OOC_SymbolTable_TypeRules__AllocateType((OOC_SymbolTable__Type)i1);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37419))+40);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37399))+40);
  i1 = *(OOC_INT16*)((_check_pointer(i1, 37428))+36);
  i2 = *(OOC_INT32*)((_check_pointer(i2, 37408))+32);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37386)))), OOC_SymbolTable__TypeDesc_SetSize)),OOC_SymbolTable__TypeDesc_SetSize)((OOC_SymbolTable__Type)i0, i2, i1);
  goto l97;
l17:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37240))+40);
  OOC_SymbolTable_TypeRules__AllocateType((OOC_SymbolTable__Type)i1);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37291))+40);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37274))+40);
  i1 = *(OOC_INT16*)((_check_pointer(i1, 37297))+36);
  i2 = *(OOC_INT32*)((_check_pointer(i2, 37280))+32);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37261)))), OOC_SymbolTable__TypeDesc_SetSize)),OOC_SymbolTable__TypeDesc_SetSize)((OOC_SymbolTable__Type)i0, i2, i1);
  goto l97;
l19:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34691))+40);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l22;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35036))+40);
  OOC_SymbolTable_TypeRules__AllocateType((OOC_SymbolTable__Type)i1);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35072))+40);
  i1 = *(OOC_INT16*)((_check_pointer(i1, 35082))+36);
  align = i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35113))+40);
  i2 = *(OOC_INT32*)((_check_pointer(i2, 35123))+32);
  size = i2;
  
  goto l27;
l22:
  align = 1;
  size = 0;
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 34833))+60);
  if (i1) goto l25;
  i1=0;
  goto l26;
l25:
  i1 = (OOC_INT32)OOC_SymbolTable__predefIdToType;
  i1 = _check_pointer(i1, 34961);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(12, i2, OOC_UINT8, 34961))*4);
  i1 = *(OOC_INT32*)((_check_pointer(i1, 34973))+32);
  size = i1;
  
l26:
  i2=i1;i1=1;
l27:
  i3 = *(OOC_INT16*)((_check_pointer(i0, 35241))+62);
  i3 = i3==0;
  if (i3) goto l30;
  i3 = *(OOC_INT16*)((_check_pointer(i0, 35337))+62);
  maxAlign = i3;
  
  goto l31;
l30:
  maxAlign = 32767;
  i3=32767;
l31:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35386))+8);
  nested = (OOC_SymbolTable__Item)i4;
  i5 = i4!=(OOC_INT32)0;
  if (i5) goto l34;
  {register OOC_INT32 h0=i1;i1=i2;i2=h0;}
  goto l64;
l34:
  {register OOC_INT32 h0=i1;i1=i4;i4=i2;i2=h0;}
l35_loop:
  i5 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 35454)))), &_td_OOC_SymbolTable__FieldDeclDesc);
  if (!i5) goto l59;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 35505))+48);
  OOC_SymbolTable_TypeRules__AllocateType((OOC_SymbolTable__Type)i5);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 35546))+48);
  i5 = *(OOC_INT16*)((_check_pointer(i5, 35552))+36);
  fieldAlign = i5;
  i6 = i5>i3;
  if (!i6) goto l42;
  fieldAlign = i3;
  i5=i3;
l42:
  i6 = i5>i2;
  if (!i6) goto l46;
  align = i5;
  i2=i5;
l46:
  i6 = *(OOC_UINT8*)((_check_pointer(i0, 35874))+56);
  if (i6) goto l53;
  i6 = _mod(i4,i5);
  i7 = i6!=0;
  if (!i7) goto l52;
  i4 = i4+(i5-i6);
  size = i4;
  
l52:
  OOC_SymbolTable__FieldDeclDesc_SetOffset((OOC_SymbolTable__FieldDecl)i1, i4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 36557))+48);
  i5 = *(OOC_INT32*)((_check_pointer(i5, 36563))+32);
  i4 = i4+i5;
  size = i4;
  
  goto l59;
l53:
  OOC_SymbolTable__FieldDeclDesc_SetOffset((OOC_SymbolTable__FieldDecl)i1, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 36104))+48);
  i5 = *(OOC_INT32*)((_check_pointer(i5, 36110))+32);
  i5 = i5>i4;
  if (!i5) goto l59;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 36160))+48);
  i4 = *(OOC_INT32*)((_check_pointer(i4, 36166))+32);
  size = i4;
  
l59:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 36657));
  nested = (OOC_SymbolTable__Item)i1;
  i5 = i1!=(OOC_INT32)0;
  if (i5) goto l35_loop;
l63:
  i1=i4;
l64:
  i3 = _mod(i1,i2);
  i4 = i3!=0;
  if (i4) goto l67;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36886)))), OOC_SymbolTable__TypeDesc_SetSize)),OOC_SymbolTable__TypeDesc_SetSize)((OOC_SymbolTable__Type)i0, i1, i2);
  goto l68;
l67:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36810)))), OOC_SymbolTable__TypeDesc_SetSize)),OOC_SymbolTable__TypeDesc_SetSize)((OOC_SymbolTable__Type)i0, ((i1+i2)-i3), i2);
l68:
  i1 = OOC_SymbolTable_TypeRules__IsAtomicType((OOC_SymbolTable__Type)i0);
  if (!i1) goto l97;
  *(OOC_UINT8*)((_check_pointer(i0, 37154))+61) = 1u;
  goto l97;
l73:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34051))+44);
  OOC_SymbolTable_TypeRules__AllocateType((OOC_SymbolTable__Type)i1);
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 34082))+40);
  if (i1) goto l76;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34275))+44);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34225))+44);
  i3 = *(OOC_INT32*)((_check_pointer(i0, 34212))+52);
  i2 = *(OOC_INT32*)((_check_pointer(i2, 34238))+32);
  i1 = *(OOC_INT16*)((_check_pointer(i1, 34288))+36);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34197)))), OOC_SymbolTable__TypeDesc_SetSize)),OOC_SymbolTable__TypeDesc_SetSize)((OOC_SymbolTable__Type)i0, (i3*i2), i1);
  goto l77;
l76:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34147))+44);
  i1 = *(OOC_INT16*)((_check_pointer(i1, 34160))+36);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34115)))), OOC_SymbolTable__TypeDesc_SetSize)),OOC_SymbolTable__TypeDesc_SetSize)((OOC_SymbolTable__Type)i0, (-1), i1);
l77:
  i1 = OOC_SymbolTable_TypeRules__IsAtomicType((OOC_SymbolTable__Type)i0);
  if (!i1) goto l97;
  *(OOC_UINT8*)((_check_pointer(i0, 34542))+60) = 1u;
  goto l97;
l82:
  i1 = (OOC_INT32)OOC_SymbolTable__predefIdToType;
  i2 = _check_pointer(i1, 33724);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(12, i3, OOC_UINT8, 33724))*4);
  i1 = _check_pointer(i1, 33664);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(12, i3, OOC_UINT8, 33664))*4);
  i2 = *(OOC_INT16*)((_check_pointer(i2, 33736))+36);
  i1 = *(OOC_INT32*)((_check_pointer(i1, 33676))+32);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33635)))), OOC_SymbolTable__TypeDesc_SetSize)),OOC_SymbolTable__TypeDesc_SetSize)((OOC_SymbolTable__Type)i0, i1, i2);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33798))+40);
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l85;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33849))+40);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 33859))+48);
  OOC_SymbolTable_TypeRules__AllocateType((OOC_SymbolTable__Type)i1);
l85:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33912))+52);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 33920)), 0);
  i = 0;
  i2 = 0<i1;
  if (!i2) goto l97;
  i2=0;
l88_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33956))+52);
  i3 = _check_pointer(i3, 33964);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 33964))*4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 33967))+48);
  OOC_SymbolTable_TypeRules__AllocateType((OOC_SymbolTable__Type)i3);
  i2 = i2+1;
  i = i2;
  i3 = i2<i1;
  if (i3) goto l88_loop;
  goto l97;
l95:
  i1 = (OOC_INT32)OOC_SymbolTable__predefIdToType;
  i2 = _check_pointer(i1, 33343);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(12, i3, OOC_UINT8, 33343))*4);
  i1 = _check_pointer(i1, 33283);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(12, i3, OOC_UINT8, 33283))*4);
  i2 = *(OOC_INT16*)((_check_pointer(i2, 33355))+36);
  i1 = *(OOC_INT32*)((_check_pointer(i1, 33295))+32);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33254)))), OOC_SymbolTable__TypeDesc_SetSize)),OOC_SymbolTable__TypeDesc_SetSize)((OOC_SymbolTable__Type)i0, i1, i2);
l97:
  return;
  ;
}

void OOC_OOC_SymbolTable_TypeRules_init(void) {

  return;
  ;
}

void OOC_OOC_SymbolTable_TypeRules_destroy(void) {
}

/* --- */
