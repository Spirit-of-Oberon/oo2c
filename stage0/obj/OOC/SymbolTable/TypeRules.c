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
  i0 = OOC_SymbolTable_TypeRules__ExtendsLibType((OOC_SymbolTable__Type)i0, "Object", 7, "ObjectDesc", 11);
  return i0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsObjectType(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)type;
  i0 = OOC_SymbolTable_TypeRules__IsPointerType((OOC_SymbolTable__Type)i0, "Object", 7, "ObjectDesc", 11);
  return i0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsException(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)type;
  i0 = OOC_SymbolTable_TypeRules__ExtendsLibType((OOC_SymbolTable__Type)i0, "Exception", 10, "ExceptionDesc", 14);
  return i0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsSTRING(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)type;
  i0 = OOC_SymbolTable_TypeRules__ExtendsLibType((OOC_SymbolTable__Type)i0, "Object", 7, "StringDesc", 11);
  return i0;
  ;
}

OOC_SymbolTable__PredefType OOC_SymbolTable_TypeRules__BaseCharType(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5805)))), &_td_OOC_SymbolTable__PredefTypeDesc);
  if (i1) goto l11;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6179)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (i1) goto l5;
  return (OOC_SymbolTable__PredefType)(OOC_INT32)0;
  goto l18;
l5:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6208))+44);
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6222)))), &_td_OOC_SymbolTable__PredefTypeDesc);
  if (i1) goto l8;
  return (OOC_SymbolTable__PredefType)(OOC_INT32)0;
  goto l18;
l8:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6279))+44);
  i0 = (OOC_INT32)OOC_SymbolTable_TypeRules__BaseCharType((OOC_SymbolTable__Type)i0);
  return (OOC_SymbolTable__PredefType)i0;
  goto l18;
l11:
  i0 = *(OOC_INT16*)((_check_pointer(i0, 5840))+40);
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
  _failed_function(5346); return 0;
  ;
}

OOC_SymbolTable__Type OOC_SymbolTable_TypeRules__StringBase(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6513)))), &_td_OOC_SymbolTable__PredefTypeDesc);
  if (i1) goto l3;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6503)))), 6503);
  goto l10;
l3:
  i0 = *(OOC_INT16*)((_check_pointer(i0, 6546))+40);
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
    _failed_case(i0, 6537);
    goto l10;
  }
l10:
  _failed_function(6404); return 0;
  ;
}

OOC_SymbolTable__Type OOC_SymbolTable_TypeRules__MatchingStringConst(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0;
  OOC_INT16 id;

  i0 = (OOC_INT32)type;
  i0 = *(OOC_INT16*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6908)))), &_td_OOC_SymbolTable__PredefTypeDesc, 6908)), 6919))+40);
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
    _failed_case(i0, 6894);
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
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7271)))), &_td_OOC_SymbolTable__PredefTypeDesc);
  if (i1) goto l3;
  return 0u;
  goto l4;
l3:
  i0 = *(OOC_INT16*)((_check_pointer(i0, 7309))+40);
  return (_in(i0,262384u));
l4:
  _failed_function(7141); return 0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsRealType(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7604)))), &_td_OOC_SymbolTable__PredefTypeDesc);
  if (i1) goto l3;
  return 0u;
  goto l4;
l3:
  i0 = *(OOC_INT16*)((_check_pointer(i0, 7642))+40);
  return (_in(i0,768u));
l4:
  _failed_function(7471); return 0;
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
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8068)))), &_td_OOC_SymbolTable__PredefTypeDesc);
  if (i1) goto l3;
  return 0u;
  goto l4;
l3:
  i0 = *(OOC_INT16*)((_check_pointer(i0, 8106))+40);
  return (_in(i0,1024u));
l4:
  _failed_function(7947); return 0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IncludesType(OOC_SymbolTable__Type large, OOC_SymbolTable__Type small) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT16 largeId;

  i0 = (OOC_INT32)large;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8592)))), &_td_OOC_SymbolTable__PredefTypeDesc);
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)small;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8620)))), &_td_OOC_SymbolTable__PredefTypeDesc);
  
l5:
  if (!i1) goto l30;
  i1 = *(OOC_INT16*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8671)))), &_td_OOC_SymbolTable__PredefTypeDesc, 8671)), 8682))+40);
  largeId = i1;
  i2 = (OOC_INT32)small;
  i3 = *(OOC_INT16*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 8714)))), &_td_OOC_SymbolTable__PredefTypeDesc, 8714)), 8725))+40);
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
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9268)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  type = (OOC_SymbolTable__Type)i0;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9297)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (i1) goto l3;
  i0=0u;
  goto l4;
l3:
  i0 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9322)))), &_td_OOC_SymbolTable__ArrayDesc, 9322)), 9328))+40);
  
l4:
  return i0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsArrayOfChar(OOC_SymbolTable__Type type, OOC_CHAR8 includeFixed) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9688)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (i1) goto l3;
  i1=0u;
  goto l9;
l3:
  i1 = includeFixed;
  if (i1) goto l6;
  i1 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9738)))), &_td_OOC_SymbolTable__ArrayDesc, 9738)), 9744))+40);
  
  goto l9;
l6:
  i1=1u;
l9:
  if (i1) goto l11;
  i0=0u;
  goto l12;
l11:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9790)))), &_td_OOC_SymbolTable__ArrayDesc, 9790)), 9796))+44);
  i0 = OOC_SymbolTable_TypeRules__IsCharType((OOC_SymbolTable__Type)i0);
  
l12:
  return i0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsValidRecordBaseType(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10028)))), &_td_OOC_SymbolTable__QualTypeDesc);
  if (i1) goto l7;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10125)))), &_td_OOC_SymbolTable__RecordDesc);
  if (i1) goto l5;
  i0=0u;
  goto l6;
l5:
  i0 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10151)))), &_td_OOC_SymbolTable__RecordDesc, 10151)), 10158))+58);
  
l6:
  return i0;
  goto l8;
l7:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10085))+40);
  i0 = OOC_SymbolTable_TypeRules__IsValidRecordBaseType((OOC_SymbolTable__Type)i0);
  return i0;
l8:
  _failed_function(9845); return 0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsValidParameterType(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10412)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  type = (OOC_SymbolTable__Type)i0;
  i1 = OOC_SymbolTable_TypeRules__IsNamedType((OOC_SymbolTable__Type)i0);
  if (i1) goto l3;
  i1 = OOC_SymbolTable_TypeRules__IsOpenArrayType((OOC_SymbolTable__Type)i0);
  
  goto l5;
l3:
  i1=1u;
l5:
  if (i1) goto l7;
  i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10511)))), &_td_OOC_SymbolTable__FormalParsDesc);
  
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
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10751)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  type = (OOC_SymbolTable__Type)i0;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10788)))), &_td_OOC_SymbolTable__RecordDesc);
  if (i1) goto l7;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10821)))), &_td_OOC_SymbolTable__PointerDesc);
  if (i1) goto l5;
  i0=0u;
  goto l8;
l5:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10858)))), &_td_OOC_SymbolTable__PointerDesc, 10858)), 10866))+40);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10858)))), &_td_OOC_SymbolTable__PointerDesc, 10858)), 10866))+40);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10875)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10886)))), &_td_OOC_SymbolTable__RecordDesc);
  
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
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11239)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
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
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11477)))), &_td_OOC_SymbolTable__QualTypeDesc);
  if (i1) goto l7;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11575)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (i1) goto l5;
  i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11598)))), &_td_OOC_SymbolTable__RecordDesc);
  
  goto l6;
l5:
  i0=1u;
l6:
  return i0;
  goto l8;
l7:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11535))+40);
  i0 = OOC_SymbolTable_TypeRules__IsValidPointerBaseType((OOC_SymbolTable__Type)i0);
  return i0;
l8:
  _failed_function(11288); return 0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsValidArrayElementType(OOC_SymbolTable__Type type, OOC_CHAR8 isOpenArray) {
  register OOC_INT32 i0,i1;

  i0 = isOpenArray;
  if (i0) goto l7;
  i0 = (OOC_INT32)type;
  i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12001)))), &_td_OOC_SymbolTable__ArrayDesc));
  if (i1) goto l5;
  i0 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12028)))), &_td_OOC_SymbolTable__ArrayDesc, 12028)), 12034))+40);
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
  _failed_function(11663); return 0;
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
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12563)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  type = (OOC_SymbolTable__Type)i0;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12588)))), &_td_OOC_SymbolTable__PointerDesc);
  if (i1) goto l3;
  return 0u;
  goto l4;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12632)))), &_td_OOC_SymbolTable__PointerDesc, 12632)), 12640))+40);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12632)))), &_td_OOC_SymbolTable__PointerDesc, 12632)), 12640))+40);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 12649)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  type = (OOC_SymbolTable__Type)i0;
  return (OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12680)))), &_td_OOC_SymbolTable__RecordDesc));
l4:
  _failed_function(12369); return 0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__VariableInstance(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13013)))), &_td_OOC_SymbolTable__RecordDesc));
  if (i1) goto l3;
  i0 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13041)))), &_td_OOC_SymbolTable__RecordDesc, 13041)), 13048))+57);
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
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13860)))), &_td_OOC_SymbolTable__TypeClosureDesc);
  if (i2) goto l9;
  i2=0u;
  goto l11;
l9:
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 13885)))), &_td_OOC_SymbolTable__TypeClosureDesc);
  
l11:
  if (!i2) goto l29;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13931)))), &_td_OOC_SymbolTable__TypeClosureDesc, 13931)), 13943))+40);
  baseA = (OOC_SymbolTable__Type)i2;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 13975)))), &_td_OOC_SymbolTable__TypeClosureDesc, 13975)), 13987))+40);
  baseB = (OOC_SymbolTable__Type)i3;
  i4 = OOC_SymbolTable_TypeRules__SameType((OOC_SymbolTable__Type)i2, (OOC_SymbolTable__Type)i3);
  if (!i4) goto l29;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14055))+28);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 14072))+28);
  _assert((i4==i3), 127, 14043);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14115))+28);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 14124))+20);
  i = 0;
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 14131)), 0);
  i4 = 0<i3;
  if (!i4) goto l25;
  i4=0;
l17_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14160))+28);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 14169))+20);
  i5 = _check_pointer(i5, 14176);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 14176))*4);
  tv = (OOC_SymbolTable__TypeVar)i5;
  i6 = (OOC_INT32)OOC_SymbolTable__TypeClosureDesc_Lookup((OOC_SymbolTable__TypeClosure)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14268)))), &_td_OOC_SymbolTable__TypeClosureDesc, 14268)), (OOC_SymbolTable__TypeVar)i5, (OOC_SymbolTable__TypeVar)i5);
  i5 = (OOC_INT32)OOC_SymbolTable__TypeClosureDesc_Lookup((OOC_SymbolTable__TypeClosure)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14210)))), &_td_OOC_SymbolTable__TypeClosureDesc, 14210)), (OOC_SymbolTable__TypeVar)i5, (OOC_SymbolTable__TypeVar)i5);
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
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14783)))), &_td_OOC_SymbolTable__ArrayDesc, 14783)), 14789))+44);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14726)))), &_td_OOC_SymbolTable__ArrayDesc, 14726)), 14732))+44);
  i2 = OOC_SymbolTable_TypeRules__EqualTypes((OOC_SymbolTable__Type)i3, (OOC_SymbolTable__Type)i2);
  
  goto l13;
l11:
  i2=1u;
l13:
  if (i2) goto l23;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14821)))), &_td_OOC_SymbolTable__FormalParsDesc);
  if (i2) goto l17;
  i2=0u;
  goto l19;
l17:
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14845)))), &_td_OOC_SymbolTable__FormalParsDesc);
  
l19:
  if (i2) goto l21;
  i0=0u;
  goto l24;
l21:
  i0 = OOC_SymbolTable_TypeRules__FormalParamsMatch((OOC_SymbolTable__Type)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14904)))), &_td_OOC_SymbolTable__FormalParsDesc, 14904)), (OOC_SymbolTable__FormalPars)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14923)))), &_td_OOC_SymbolTable__FormalParsDesc, 14923)), 0u);
  
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
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15220)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15231)))), &_td_OOC_SymbolTable__PointerDesc);
  if (i1) goto l3;
  i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15256)))), &_td_OOC_SymbolTable__TypeVarDesc);
  
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
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15457)))), &_td_OOC_SymbolTable__PointerDesc);
  if (i1) goto l3;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15534)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  ptr = (OOC_SymbolTable__Type)i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15583)))), &_td_OOC_SymbolTable__PointerDesc, 15583)), 15591))+40);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15566)))), OOC_SymbolTable__TypeDesc_Closure)),OOC_SymbolTable__TypeDesc_Closure)((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
  return (OOC_SymbolTable__Type)i0;
  goto l4;
l3:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15494))+40);
  return (OOC_SymbolTable__Type)i0;
l4:
  _failed_function(15301); return 0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsRecord(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)type;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15826)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  return (OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15837)))), &_td_OOC_SymbolTable__RecordDesc));
  ;
}

OOC_SymbolTable__Type OOC_SymbolTable_TypeRules__RecordBaseType(OOC_SymbolTable__Type record) {
  register OOC_INT32 i0,i1;
  OOC_SymbolTable__Type ptr;

  i0 = (OOC_INT32)record;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16032)))), &_td_OOC_SymbolTable__RecordDesc);
  if (i1) goto l3;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16106)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  ptr = (OOC_SymbolTable__Type)i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16154)))), &_td_OOC_SymbolTable__RecordDesc, 16154)), 16161))+40);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16137)))), OOC_SymbolTable__TypeDesc_Closure)),OOC_SymbolTable__TypeDesc_Closure)((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
  return (OOC_SymbolTable__Type)i0;
  goto l4;
l3:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16067))+40);
  return (OOC_SymbolTable__Type)i0;
l4:
  _failed_function(15880); return 0;
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
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16616)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  return (OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16627)))), &_td_OOC_SymbolTable__ArrayDesc));
  ;
}

OOC_SymbolTable__Type OOC_SymbolTable_TypeRules__ArrayElementType(OOC_SymbolTable__Type array) {
  register OOC_INT32 i0,i1;
  OOC_SymbolTable__Type ptr;

  i0 = (OOC_INT32)array;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16819)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (i1) goto l3;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16893)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  ptr = (OOC_SymbolTable__Type)i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16940)))), &_td_OOC_SymbolTable__ArrayDesc, 16940)), 16946))+44);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16923)))), OOC_SymbolTable__TypeDesc_Closure)),OOC_SymbolTable__TypeDesc_Closure)((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
  return (OOC_SymbolTable__Type)i0;
  goto l4;
l3:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16852))+44);
  return (OOC_SymbolTable__Type)i0;
l4:
  _failed_function(16668); return 0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsInducedExtensionOf(OOC_SymbolTable__Type type, OOC_SymbolTable__Type base, OOC_CHAR8 ensureInduction) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_SymbolTable__Type ptr;
  OOC_SymbolTable__Type qualBase;

  i0 = (OOC_INT32)type;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17225)))), &_td_OOC_SymbolTable__TypeVarDesc);
  if (!i1) goto l4;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17269)))), &_td_OOC_SymbolTable__TypeVarDesc, 17269)), 17277))+40);
  type = (OOC_SymbolTable__Type)i0;
  
l4:
  i1 = (OOC_INT32)base;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17307)))), &_td_OOC_SymbolTable__TypeVarDesc);
  if (!i2) goto l7;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17351)))), &_td_OOC_SymbolTable__TypeVarDesc, 17351)), 17359))+40);
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
  i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17876)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  ptr = (OOC_SymbolTable__Type)i3;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 17918)))), &_td_OOC_SymbolTable__RecordDesc, 17918)), 17925))+40);
  qualBase = (OOC_SymbolTable__Type)i3;
  if (i2) goto l33;
  i4=0u;
  goto l35;
l33:
  i4 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17984)))), &_td_OOC_SymbolTable__TypeClosureDesc);
  
l35:
  if (i4) goto l37;
  i4=0u;
  goto l39;
l37:
  i4 = OOC_SymbolTable__TypeClosureDesc_ArgumentsInduced((OOC_SymbolTable__TypeClosure)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18029)))), &_td_OOC_SymbolTable__TypeClosureDesc, 18029)), (OOC_SymbolTable__Type)i3);
  i4 = !i4;
  
l39:
  if (!i4) goto l41;
  return 0u;
l41:
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18148)))), OOC_SymbolTable__TypeDesc_Closure)),OOC_SymbolTable__TypeDesc_Closure)((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i3);
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
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18828)))), &_td_OOC_SymbolTable__TypeVarDesc);
  if (!i1) goto l4;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18872)))), &_td_OOC_SymbolTable__TypeVarDesc, 18872)), 18880))+40);
  type = (OOC_SymbolTable__Type)i0;
  
l4:
  i1 = (OOC_INT32)base;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 18910)))), &_td_OOC_SymbolTable__TypeVarDesc);
  if (!i2) goto l7;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 18954)))), &_td_OOC_SymbolTable__TypeVarDesc, 18954)), 18962))+40);
  base = (OOC_SymbolTable__Type)i1;
l7:
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18995)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  type = (OOC_SymbolTable__Type)i0;
  i1 = (OOC_INT32)base;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 19023)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i1);
  base = (OOC_SymbolTable__Type)i1;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19125)))), &_td_OOC_SymbolTable__PointerDesc);
  if (i2) goto l10;
  i2=0u;
  goto l12;
l10:
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 19149)))), &_td_OOC_SymbolTable__PointerDesc);
  
l12:
  if (!i2) goto l15;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19193)))), &_td_OOC_SymbolTable__PointerDesc, 19193)), 19201))+40);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19193)))), &_td_OOC_SymbolTable__PointerDesc, 19193)), 19201))+40);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 19210)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  type = (OOC_SymbolTable__Type)i0;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 19245)))), &_td_OOC_SymbolTable__PointerDesc, 19245)), 19253))+40);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 19245)))), &_td_OOC_SymbolTable__PointerDesc, 19245)), 19253))+40);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 19262)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i1);
  base = (OOC_SymbolTable__Type)i1;
  
l15:
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19296)))), &_td_OOC_SymbolTable__RecordDesc);
  if (i2) goto l18;
  i2=0u;
  goto l20;
l18:
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 19319)))), &_td_OOC_SymbolTable__RecordDesc);
  
l20:
  if (!i2) goto l46;
  i2 = i0!=(OOC_INT32)0;
  if (i2) goto l24;
  i2=0u;
  goto l26;
l24:
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19482)))), &_td_OOC_SymbolTable__RecordDesc);
  
l26:
  if (!i2) goto l46;
l28_loop:
  i2 = OOC_SymbolTable_TypeRules__SameType((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
  if (i2) goto l35;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19600)))), &_td_OOC_SymbolTable__RecordDesc, 19600)), 19607))+40);
  type = (OOC_SymbolTable__Type)i0;
  i2 = i0!=(OOC_INT32)0;
  if (!i2) goto l36;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19673)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
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
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19482)))), &_td_OOC_SymbolTable__RecordDesc);
  
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
  _failed_function(19790); return 0;
  ;
}

OOC_SymbolTable__Type OOC_SymbolTable_TypeRules__FunctionResultType(OOC_SymbolTable__Type formalPars) {
  register OOC_INT32 i0,i1;
  OOC_SymbolTable__Type ptr;

  i0 = (OOC_INT32)formalPars;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20298)))), &_td_OOC_SymbolTable__FormalParsDesc);
  if (i1) goto l3;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20386)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  ptr = (OOC_SymbolTable__Type)i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 20438)))), &_td_OOC_SymbolTable__FormalParsDesc, 20438)), 20449))+44);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20421)))), OOC_SymbolTable__TypeDesc_Closure)),OOC_SymbolTable__TypeDesc_Closure)((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
  return (OOC_SymbolTable__Type)i0;
  goto l4;
l3:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20341))+44);
  return (OOC_SymbolTable__Type)i0;
l4:
  _failed_function(20128); return 0;
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
  _failed_function(20509); return 0;
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
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22482)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  ptr = (OOC_SymbolTable__Type)i1;
  i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 22519)))), &_td_OOC_SymbolTable__FormalParsDesc, 22519);
  baseFPars = (OOC_SymbolTable__FormalPars)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 22549))+44);
  i2 = i2==(OOC_INT32)0;
  if (i2) goto l3;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 22661))+44);
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22643)))), OOC_SymbolTable__TypeDesc_Closure)),OOC_SymbolTable__TypeDesc_Closure)((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i2);
  baseResult = (OOC_SymbolTable__Type)i2;
  
  goto l4;
l3:
  baseResult = (OOC_SymbolTable__Type)(OOC_INT32)0;
  i2=(OOC_INT32)0;
l4:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 22711))+52);
  i4 = (OOC_INT32)procFPars;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 22738))+52);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 22719)), 0);
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 22746)), 0);
  i3 = i3!=i5;
  if (i3) goto l149;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 22816))+44);
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
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 22981))+44);
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
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 23136))+44);
  i3 = (OOC_INT32)OOC_SymbolTable__Expand((OOC_SymbolTable__Type)i3);
  i3 = OOC_SymbolTable_TypeRules__SameType((OOC_SymbolTable__Type)i2, (OOC_SymbolTable__Type)i3);
  if (i3) goto l28;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 23199))+44);
  i3 = (OOC_INT32)OOC_SymbolTable__Expand((OOC_SymbolTable__Type)i3);
  i2 = OOC_SymbolTable_TypeRules__IsExtensionOf((OOC_SymbolTable__Type)i3, (OOC_SymbolTable__Type)i2);
  
  goto l29;
l28:
  i2=1u;
l29:
  i2 = !i2;
  
l31:
  if (i2) goto l143;
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 23270))+56);
  i3 = *(OOC_UINT8*)((_check_pointer(i4, 23301))+56);
  i2 = i2!=i3;
  if (i2) goto l141;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23389))+52);
  i = 0;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 23397)), 0);
  i3 = 0<i2;
  if (!i3) goto l49;
  i3=0;
l37_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23426))+52);
  i5 = _check_pointer(i5, 23434);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 23434))*4);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 23474))+52);
  i6 = _check_pointer(i6, 23482);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i3, i7, OOC_UINT32, 23482))*4);
  i5 = *(OOC_UINT8*)((_check_pointer(i5, 23437))+59);
  i6 = *(OOC_UINT8*)((_check_pointer(i6, 23485))+59);
  i5 = i5!=i6;
  if (i5) goto l40;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 23623))+52);
  i5 = _check_pointer(i5, 23630);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 23630))*4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 23633))+48);
  i5 = (OOC_INT32)OOC_SymbolTable__Expand((OOC_SymbolTable__Type)i5);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23560))+52);
  i6 = _check_pointer(i6, 23567);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i3, i7, OOC_UINT32, 23567))*4);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 23570))+48);
  i6 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23542)))), OOC_SymbolTable__TypeDesc_Closure)),OOC_SymbolTable__TypeDesc_Closure)((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i6);
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
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 24386))+60);
  i = 0;
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 24393)), 0);
  i2 = 0<i0;
  if (!i2) goto l79;
  i2=0;
l54_loop:
  j = 0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 24453))+60);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 24460)), 0);
  i3 = 0!=i3;
  if (i3) goto l57;
  i3=0u;
  goto l59;
l57:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 24553))+60);
  i3 = _check_pointer(i3, 24560);
  i5 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i5, OOC_UINT32, 24560))*4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 24501))+60);
  i5 = _check_pointer(i5, 24508);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(0, i6, OOC_UINT32, 24508))*4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 24563))+20);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 24511))+20);
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
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 24453))+60);
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 24460)), 0);
  i5 = i3!=i5;
  if (i5) goto l65;
  i5=0u;
  goto l67;
l65:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 24553))+60);
  i5 = _check_pointer(i5, 24560);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i2, i6, OOC_UINT32, 24560))*4);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 24501))+60);
  i6 = _check_pointer(i6, 24508);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i3, i7, OOC_UINT32, 24508))*4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 24563))+20);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 24511))+20);
  i5 = OOC_SymbolTable_TypeRules__SameType((OOC_SymbolTable__Type)i6, (OOC_SymbolTable__Type)i5);
  i5 = !i5;
  
l67:
  if (i5) goto l62_loop;
l71:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 24639))+60);
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 24646)), 0);
  i3 = i3==i5;
  if (!i3) goto l74;
  return 0u;
l74:
  i2 = i2+1;
  i = i2;
  i3 = i2<i0;
  if (i3) goto l54_loop;
l79:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 24759))+60);
  i = 0;
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 24766)), 0);
  i2 = 0<i0;
  if (!i2) goto l137;
  i2=0;
l82_loop:
  j = 0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 24826))+60);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 24833)), 0);
  i3 = 0!=i3;
  if (i3) goto l85;
  i3=0u;
  goto l87;
l85:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 24926))+60);
  i3 = _check_pointer(i3, 24933);
  i5 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i5, OOC_UINT32, 24933))*4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 24874))+60);
  i5 = _check_pointer(i5, 24881);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(0, i6, OOC_UINT32, 24881))*4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 24936))+20);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 24884))+20);
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
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 24826))+60);
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 24833)), 0);
  i5 = i3!=i5;
  if (i5) goto l93;
  i5=0u;
  goto l95;
l93:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 24926))+60);
  i5 = _check_pointer(i5, 24933);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i2, i6, OOC_UINT32, 24933))*4);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 24874))+60);
  i6 = _check_pointer(i6, 24881);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i3, i7, OOC_UINT32, 24881))*4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 24936))+20);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 24884))+20);
  i5 = OOC_SymbolTable_TypeRules__SameType((OOC_SymbolTable__Type)i6, (OOC_SymbolTable__Type)i5);
  i5 = !i5;
  
l95:
  if (i5) goto l90_loop;
l99:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 25012))+60);
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 25019)), 0);
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
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 23762))+60);
  i = 0;
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 23769)), 0);
  i2 = 0<i0;
  if (!i2) goto l137;
  i2=0;
l111_loop:
  j = 0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23829))+60);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 23836)), 0);
  i3 = 0!=i3;
  if (i3) goto l114;
  i3=0u;
  goto l116;
l114:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23939))+60);
  i3 = _check_pointer(i3, 23946);
  i5 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i5, OOC_UINT32, 23946))*4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 23882))+60);
  i5 = _check_pointer(i5, 23889);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(0, i6, OOC_UINT32, 23889))*4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 23949))+20);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 23892))+20);
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
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23829))+60);
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 23836)), 0);
  i5 = i3!=i5;
  if (i5) goto l122;
  i5=0u;
  goto l124;
l122:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23939))+60);
  i5 = _check_pointer(i5, 23946);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i2, i6, OOC_UINT32, 23946))*4);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 23882))+60);
  i6 = _check_pointer(i6, 23889);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i3, i7, OOC_UINT32, 23889))*4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 23949))+20);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 23892))+20);
  i5 = OOC_SymbolTable_TypeRules__IsExtensionOf((OOC_SymbolTable__Type)i6, (OOC_SymbolTable__Type)i5);
  i5 = !i5;
  
l124:
  if (i5) goto l119_loop;
l128:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 24025))+60);
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 24032)), 0);
  i3 = i3==i5;
  if (!i3) goto l131;
  return 0u;
l131:
  i2 = i2+1;
  i = i2;
  i3 = i2<i0;
  if (i3) goto l111_loop;
l137:
  i0 = *(OOC_INT8*)((_check_pointer(i4, 25172))+58);
  i1 = *(OOC_INT8*)((_check_pointer(i1, 25152))+58);
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
  _failed_function(21084); return 0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsValidRedefinition(OOC_SymbolTable__Type baseFParsClosure, OOC_SymbolTable__FormalPars procFPars) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_SymbolTable__Type baseFPars;

  i0 = (OOC_INT32)baseFParsClosure;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25607)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  baseFPars = (OOC_SymbolTable__Type)i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 25651)))), &_td_OOC_SymbolTable__FormalParsDesc, 25651)), 25662))+40);
  i2 = (OOC_INT32)procFPars;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 25701))+40);
  i1 = *(OOC_UINT8*)((_check_pointer(i1, 25671))+59);
  i3 = *(OOC_UINT8*)((_check_pointer(i3, 25710))+59);
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
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26023))+40);
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
  _failed_function(25823); return 0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsArrayType(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)type;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26367)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  return (OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26378)))), &_td_OOC_SymbolTable__ArrayDesc));
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
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 27984)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i1);
  superType = (OOC_SymbolTable__Type)i1;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 28022))+8);
  field = (OOC_SymbolTable__Item)i3;
  i4 = i3!=(OOC_INT32)0;
  if (!i4) goto l34;
l23_loop:
  i4 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 28088)))), &_td_OOC_SymbolTable__FieldDeclDesc);
  if (!i4) goto l29;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 28151))+48);
  i4 = OOC_SymbolTable_TypeRules__IsComponentOf((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i4, i2);
  if (!i4) goto l29;
  return 1u;
l29:
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 28321));
  field = (OOC_SymbolTable__Item)i3;
  i4 = i3!=(OOC_INT32)0;
  if (i4) goto l23_loop;
l34:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 28382)))), &_td_OOC_SymbolTable__RecordDesc, 28382)), 28389))+40);
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
  _failed_function(27115); return 0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsByteCompatible(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 28665)))), &_td_OOC_SymbolTable__PredefTypeDesc);
  if (i1) goto l3;
  return 0u;
  goto l8;
l3:
  i1 = *(OOC_INT16*)((_check_pointer(i0, 28703))+40);
  i1 = i1==1;
  if (i1) goto l6;
  i0 = *(OOC_INT16*)((_check_pointer(i0, 28731))+40);
  i0 = i0==4;
  
  goto l7;
l6:
  i0=1u;
l7:
  return i0;
l8:
  _failed_function(28498); return 0;
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
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 29274)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  type = (OOC_SymbolTable__Type)i0;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 29299)))), &_td_OOC_SymbolTable__PredefTypeDesc);
  if (i1) goto l15;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 29393)))), &_td_OOC_SymbolTable__PointerDesc);
  if (i1) goto l13;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 29439)))), &_td_OOC_SymbolTable__FormalParsDesc);
  if (i1) goto l11;
  i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 29488)))), &_td_OOC_SymbolTable__TypeVarDesc);
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
  i1 = *(OOC_INT16*)((_check_pointer(i0, 29337))+40);
  i1 = i1==12;
  if (i1) goto l18;
  i0 = *(OOC_INT16*)((_check_pointer(i0, 29364))+40);
  i0 = i0==16;
  
  goto l19;
l18:
  i0=1u;
l19:
  return i0;
l20:
  _failed_function(29043); return 0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsReadOnly(OOC_SymbolTable__Module usingModule, OOC_SymbolTable__Declaration decl) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)decl;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 29810))+28);
  i1 = i1==2;
  if (i1) goto l3;
  i0=0u;
  goto l4;
l3:
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 29860)))), OOC_SymbolTable__ItemDesc_Module)),OOC_SymbolTable__ItemDesc_Module)((OOC_SymbolTable__Item)i0);
  i1 = (OOC_INT32)usingModule;
  i0 = i0!=i1;
  
l4:
  return i0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsReadOnlyType(OOC_SymbolTable__Module usingModule, OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 30121)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 30154)))), &_td_OOC_SymbolTable__ArrayDesc, 30154)), 30160))+42);
  
l5:
  if (i1) goto l7;
  i0=0u;
  goto l8;
l7:
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 30191)))), OOC_SymbolTable__ItemDesc_Module)),OOC_SymbolTable__ItemDesc_Module)((OOC_SymbolTable__Item)i0);
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
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 30676)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  type = (OOC_SymbolTable__Type)i0;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 30700)))), &_td_OOC_SymbolTable__PointerDesc);
  if (i1) goto l48;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 30746)))), &_td_OOC_SymbolTable__TypeVarDesc);
  if (i1) goto l46;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 30790)))), &_td_OOC_SymbolTable__PredefTypeDesc);
  if (i1) goto l44;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 30853)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (i1) goto l42;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 30923)))), &_td_OOC_SymbolTable__RecordDesc);
  if (i1) goto l11;
  result = 1u;
  
  goto l49;
l11:
  result = 1u;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30970))+40);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l14;
  i1=1u;
  goto l15;
l14:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31024))+40);
  i1 = OOC_SymbolTable_TypeRules__IsAtomicType((OOC_SymbolTable__Type)i1);
  result = i1;
  
l15:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31063))+8);
  nested = (OOC_SymbolTable__Item)i0;
  if (i1) goto l18;
  i2=0u;
  goto l20;
l18:
  i2 = i0!=(OOC_INT32)0;
  
l20:
  if (!i2) goto l49;
l23_loop:
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31132)))), &_td_OOC_SymbolTable__FieldDeclDesc);
  if (!i2) goto l31;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31182))+48);
  i2 = OOC_SymbolTable_TypeRules__IsAtomicType((OOC_SymbolTable__Type)i2);
  i2 = !i2;
  if (!i2) goto l31;
  result = 0u;
  i1=0u;
l31:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 31292));
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
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30899))+44);
  i0 = OOC_SymbolTable_TypeRules__IsAtomicType((OOC_SymbolTable__Type)i0);
  result = i0;
  
  goto l49;
l44:
  i0 = *(OOC_INT16*)((_check_pointer(i0, 30825))+40);
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
  i1 = *(OOC_INT32*)((_check_pointer(i0, 32374))+32);
  i1 = i1==(-2);
  if (!i1) goto l97;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32530)))), &_td_OOC_SymbolTable__PointerDesc);
  if (i1) goto l95;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32908)))), &_td_OOC_SymbolTable__FormalParsDesc);
  if (i1) goto l82;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33315)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (i1) goto l73;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33891)))), &_td_OOC_SymbolTable__RecordDesc);
  if (i1) goto l19;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36503)))), &_td_OOC_SymbolTable__TypeVarDesc);
  if (i1) goto l17;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36624)))), &_td_OOC_SymbolTable__QualTypeDesc);
  if (i1) goto l15;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36618)))), 36618);
  goto l97;
l15:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36667))+40);
  OOC_SymbolTable_TypeRules__AllocateType((OOC_SymbolTable__Type)i1);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36724))+40);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36704))+40);
  i1 = *(OOC_INT16*)((_check_pointer(i1, 36733))+36);
  i2 = *(OOC_INT32*)((_check_pointer(i2, 36713))+32);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36691)))), OOC_SymbolTable__TypeDesc_SetSize)),OOC_SymbolTable__TypeDesc_SetSize)((OOC_SymbolTable__Type)i0, i2, i1);
  goto l97;
l17:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36545))+40);
  OOC_SymbolTable_TypeRules__AllocateType((OOC_SymbolTable__Type)i1);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36596))+40);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36579))+40);
  i1 = *(OOC_INT16*)((_check_pointer(i1, 36602))+36);
  i2 = *(OOC_INT32*)((_check_pointer(i2, 36585))+32);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36566)))), OOC_SymbolTable__TypeDesc_SetSize)),OOC_SymbolTable__TypeDesc_SetSize)((OOC_SymbolTable__Type)i0, i2, i1);
  goto l97;
l19:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33996))+40);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l22;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34341))+40);
  OOC_SymbolTable_TypeRules__AllocateType((OOC_SymbolTable__Type)i1);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34377))+40);
  i1 = *(OOC_INT16*)((_check_pointer(i1, 34387))+36);
  align = i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34418))+40);
  i2 = *(OOC_INT32*)((_check_pointer(i2, 34428))+32);
  size = i2;
  
  goto l27;
l22:
  align = 1;
  size = 0;
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 34138))+60);
  if (i1) goto l25;
  i1=0;
  goto l26;
l25:
  i1 = (OOC_INT32)OOC_SymbolTable__predefIdToType;
  i1 = _check_pointer(i1, 34266);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(12, i2, OOC_UINT8, 34266))*4);
  i1 = *(OOC_INT32*)((_check_pointer(i1, 34278))+32);
  size = i1;
  
l26:
  i2=i1;i1=1;
l27:
  i3 = *(OOC_INT16*)((_check_pointer(i0, 34546))+62);
  i3 = i3==0;
  if (i3) goto l30;
  i3 = *(OOC_INT16*)((_check_pointer(i0, 34642))+62);
  maxAlign = i3;
  
  goto l31;
l30:
  maxAlign = 32767;
  i3=32767;
l31:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34691))+8);
  nested = (OOC_SymbolTable__Item)i4;
  i5 = i4!=(OOC_INT32)0;
  if (i5) goto l34;
  {register OOC_INT32 h0=i1;i1=i2;i2=h0;}
  goto l64;
l34:
  {register OOC_INT32 h0=i1;i1=i4;i4=i2;i2=h0;}
l35_loop:
  i5 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 34759)))), &_td_OOC_SymbolTable__FieldDeclDesc);
  if (!i5) goto l59;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34810))+48);
  OOC_SymbolTable_TypeRules__AllocateType((OOC_SymbolTable__Type)i5);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34851))+48);
  i5 = *(OOC_INT16*)((_check_pointer(i5, 34857))+36);
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
  i6 = *(OOC_UINT8*)((_check_pointer(i0, 35179))+56);
  if (i6) goto l53;
  i6 = _mod(i4,i5);
  i7 = i6!=0;
  if (!i7) goto l52;
  i4 = i4+(i5-i6);
  size = i4;
  
l52:
  OOC_SymbolTable__FieldDeclDesc_SetOffset((OOC_SymbolTable__FieldDecl)i1, i4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 35862))+48);
  i5 = *(OOC_INT32*)((_check_pointer(i5, 35868))+32);
  i4 = i4+i5;
  size = i4;
  
  goto l59;
l53:
  OOC_SymbolTable__FieldDeclDesc_SetOffset((OOC_SymbolTable__FieldDecl)i1, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 35409))+48);
  i5 = *(OOC_INT32*)((_check_pointer(i5, 35415))+32);
  i5 = i5>i4;
  if (!i5) goto l59;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 35465))+48);
  i4 = *(OOC_INT32*)((_check_pointer(i4, 35471))+32);
  size = i4;
  
l59:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 35962));
  nested = (OOC_SymbolTable__Item)i1;
  i5 = i1!=(OOC_INT32)0;
  if (i5) goto l35_loop;
l63:
  i1=i4;
l64:
  i3 = _mod(i1,i2);
  i4 = i3!=0;
  if (i4) goto l67;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36191)))), OOC_SymbolTable__TypeDesc_SetSize)),OOC_SymbolTable__TypeDesc_SetSize)((OOC_SymbolTable__Type)i0, i1, i2);
  goto l68;
l67:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36115)))), OOC_SymbolTable__TypeDesc_SetSize)),OOC_SymbolTable__TypeDesc_SetSize)((OOC_SymbolTable__Type)i0, ((i1+i2)-i3), i2);
l68:
  i1 = OOC_SymbolTable_TypeRules__IsAtomicType((OOC_SymbolTable__Type)i0);
  if (!i1) goto l97;
  *(OOC_UINT8*)((_check_pointer(i0, 36459))+61) = 1u;
  goto l97;
l73:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33356))+44);
  OOC_SymbolTable_TypeRules__AllocateType((OOC_SymbolTable__Type)i1);
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 33387))+40);
  if (i1) goto l76;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33580))+44);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33530))+44);
  i3 = *(OOC_INT32*)((_check_pointer(i0, 33517))+52);
  i2 = *(OOC_INT32*)((_check_pointer(i2, 33543))+32);
  i1 = *(OOC_INT16*)((_check_pointer(i1, 33593))+36);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33502)))), OOC_SymbolTable__TypeDesc_SetSize)),OOC_SymbolTable__TypeDesc_SetSize)((OOC_SymbolTable__Type)i0, (i3*i2), i1);
  goto l77;
l76:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33452))+44);
  i1 = *(OOC_INT16*)((_check_pointer(i1, 33465))+36);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33420)))), OOC_SymbolTable__TypeDesc_SetSize)),OOC_SymbolTable__TypeDesc_SetSize)((OOC_SymbolTable__Type)i0, (-1), i1);
l77:
  i1 = OOC_SymbolTable_TypeRules__IsAtomicType((OOC_SymbolTable__Type)i0);
  if (!i1) goto l97;
  *(OOC_UINT8*)((_check_pointer(i0, 33847))+60) = 1u;
  goto l97;
l82:
  i1 = (OOC_INT32)OOC_SymbolTable__predefIdToType;
  i2 = _check_pointer(i1, 33029);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(12, i3, OOC_UINT8, 33029))*4);
  i1 = _check_pointer(i1, 32969);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(12, i3, OOC_UINT8, 32969))*4);
  i2 = *(OOC_INT16*)((_check_pointer(i2, 33041))+36);
  i1 = *(OOC_INT32*)((_check_pointer(i1, 32981))+32);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32940)))), OOC_SymbolTable__TypeDesc_SetSize)),OOC_SymbolTable__TypeDesc_SetSize)((OOC_SymbolTable__Type)i0, i1, i2);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33103))+40);
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l85;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33154))+40);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 33164))+48);
  OOC_SymbolTable_TypeRules__AllocateType((OOC_SymbolTable__Type)i1);
l85:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33217))+52);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 33225)), 0);
  i = 0;
  i2 = 0<i1;
  if (!i2) goto l97;
  i2=0;
l88_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33261))+52);
  i3 = _check_pointer(i3, 33269);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 33269))*4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 33272))+48);
  OOC_SymbolTable_TypeRules__AllocateType((OOC_SymbolTable__Type)i3);
  i2 = i2+1;
  i = i2;
  i3 = i2<i1;
  if (i3) goto l88_loop;
  goto l97;
l95:
  i1 = (OOC_INT32)OOC_SymbolTable__predefIdToType;
  i2 = _check_pointer(i1, 32648);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(12, i3, OOC_UINT8, 32648))*4);
  i1 = _check_pointer(i1, 32588);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(12, i3, OOC_UINT8, 32588))*4);
  i2 = *(OOC_INT16*)((_check_pointer(i2, 32660))+36);
  i1 = *(OOC_INT32*)((_check_pointer(i1, 32600))+32);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32559)))), OOC_SymbolTable__TypeDesc_SetSize)),OOC_SymbolTable__TypeDesc_SetSize)((OOC_SymbolTable__Type)i0, i1, i2);
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
