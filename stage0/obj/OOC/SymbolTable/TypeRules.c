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

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsObject(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)type;
  i0 = OOC_SymbolTable_TypeRules__ExtendsLibType((OOC_SymbolTable__Type)i0, "Object", 7, "ObjectDesc", 11);
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
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5007)))), &_td_OOC_SymbolTable__PredefTypeDesc);
  if (i1) goto l11;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5381)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (i1) goto l5;
  return (OOC_SymbolTable__PredefType)(OOC_INT32)0;
  goto l18;
l5:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5410))+44);
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5424)))), &_td_OOC_SymbolTable__PredefTypeDesc);
  if (i1) goto l8;
  return (OOC_SymbolTable__PredefType)(OOC_INT32)0;
  goto l18;
l8:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5481))+44);
  i0 = (OOC_INT32)OOC_SymbolTable_TypeRules__BaseCharType((OOC_SymbolTable__Type)i0);
  return (OOC_SymbolTable__PredefType)i0;
  goto l18;
l11:
  i0 = *(OOC_INT16*)((_check_pointer(i0, 5042))+40);
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
  _failed_function(4548); return 0;
  ;
}

OOC_SymbolTable__Type OOC_SymbolTable_TypeRules__StringBase(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5715)))), &_td_OOC_SymbolTable__PredefTypeDesc);
  if (i1) goto l3;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5705)))), 5705);
  goto l10;
l3:
  i0 = *(OOC_INT16*)((_check_pointer(i0, 5748))+40);
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
    _failed_case(i0, 5739);
    goto l10;
  }
l10:
  _failed_function(5606); return 0;
  ;
}

OOC_SymbolTable__Type OOC_SymbolTable_TypeRules__MatchingStringConst(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0;
  OOC_INT16 id;

  i0 = (OOC_INT32)type;
  i0 = *(OOC_INT16*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6110)))), &_td_OOC_SymbolTable__PredefTypeDesc, 6110)), 6121))+40);
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
    _failed_case(i0, 6096);
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
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6473)))), &_td_OOC_SymbolTable__PredefTypeDesc);
  if (i1) goto l3;
  return 0u;
  goto l4;
l3:
  i0 = *(OOC_INT16*)((_check_pointer(i0, 6511))+40);
  return (_in(i0,262384u));
l4:
  _failed_function(6343); return 0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsRealType(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6806)))), &_td_OOC_SymbolTable__PredefTypeDesc);
  if (i1) goto l3;
  return 0u;
  goto l4;
l3:
  i0 = *(OOC_INT16*)((_check_pointer(i0, 6844))+40);
  return (_in(i0,768u));
l4:
  _failed_function(6673); return 0;
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
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7270)))), &_td_OOC_SymbolTable__PredefTypeDesc);
  if (i1) goto l3;
  return 0u;
  goto l4;
l3:
  i0 = *(OOC_INT16*)((_check_pointer(i0, 7308))+40);
  return (_in(i0,1024u));
l4:
  _failed_function(7149); return 0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IncludesType(OOC_SymbolTable__Type large, OOC_SymbolTable__Type small) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT16 largeId;

  i0 = (OOC_INT32)large;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7794)))), &_td_OOC_SymbolTable__PredefTypeDesc);
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)small;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7822)))), &_td_OOC_SymbolTable__PredefTypeDesc);
  
l5:
  if (!i1) goto l30;
  i1 = *(OOC_INT16*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7873)))), &_td_OOC_SymbolTable__PredefTypeDesc, 7873)), 7884))+40);
  largeId = i1;
  i2 = (OOC_INT32)small;
  i3 = *(OOC_INT16*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 7916)))), &_td_OOC_SymbolTable__PredefTypeDesc, 7916)), 7927))+40);
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
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8470)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  type = (OOC_SymbolTable__Type)i0;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8499)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (i1) goto l3;
  i0=0u;
  goto l4;
l3:
  i0 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8524)))), &_td_OOC_SymbolTable__ArrayDesc, 8524)), 8530))+40);
  
l4:
  return i0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsArrayOfChar(OOC_SymbolTable__Type type, OOC_CHAR8 includeFixed) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8890)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (i1) goto l3;
  i1=0u;
  goto l9;
l3:
  i1 = includeFixed;
  if (i1) goto l6;
  i1 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8940)))), &_td_OOC_SymbolTable__ArrayDesc, 8940)), 8946))+40);
  
  goto l9;
l6:
  i1=1u;
l9:
  if (i1) goto l11;
  i0=0u;
  goto l12;
l11:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8992)))), &_td_OOC_SymbolTable__ArrayDesc, 8992)), 8998))+44);
  i0 = OOC_SymbolTable_TypeRules__IsCharType((OOC_SymbolTable__Type)i0);
  
l12:
  return i0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsValidRecordBaseType(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9230)))), &_td_OOC_SymbolTable__QualTypeDesc);
  if (i1) goto l7;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9327)))), &_td_OOC_SymbolTable__RecordDesc);
  if (i1) goto l5;
  i0=0u;
  goto l6;
l5:
  i0 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9353)))), &_td_OOC_SymbolTable__RecordDesc, 9353)), 9360))+58);
  
l6:
  return i0;
  goto l8;
l7:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9287))+40);
  i0 = OOC_SymbolTable_TypeRules__IsValidRecordBaseType((OOC_SymbolTable__Type)i0);
  return i0;
l8:
  _failed_function(9047); return 0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsValidParameterType(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9614)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  type = (OOC_SymbolTable__Type)i0;
  i1 = OOC_SymbolTable_TypeRules__IsNamedType((OOC_SymbolTable__Type)i0);
  if (i1) goto l3;
  i1 = OOC_SymbolTable_TypeRules__IsOpenArrayType((OOC_SymbolTable__Type)i0);
  
  goto l5;
l3:
  i1=1u;
l5:
  if (i1) goto l7;
  i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9713)))), &_td_OOC_SymbolTable__FormalParsDesc);
  
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
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9953)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  type = (OOC_SymbolTable__Type)i0;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9990)))), &_td_OOC_SymbolTable__RecordDesc);
  if (i1) goto l7;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10023)))), &_td_OOC_SymbolTable__PointerDesc);
  if (i1) goto l5;
  i0=0u;
  goto l8;
l5:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10060)))), &_td_OOC_SymbolTable__PointerDesc, 10060)), 10068))+40);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10060)))), &_td_OOC_SymbolTable__PointerDesc, 10060)), 10068))+40);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10077)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10088)))), &_td_OOC_SymbolTable__RecordDesc);
  
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
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10441)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
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
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10679)))), &_td_OOC_SymbolTable__QualTypeDesc);
  if (i1) goto l7;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10777)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (i1) goto l5;
  i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10800)))), &_td_OOC_SymbolTable__RecordDesc);
  
  goto l6;
l5:
  i0=1u;
l6:
  return i0;
  goto l8;
l7:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10737))+40);
  i0 = OOC_SymbolTable_TypeRules__IsValidPointerBaseType((OOC_SymbolTable__Type)i0);
  return i0;
l8:
  _failed_function(10490); return 0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsValidArrayElementType(OOC_SymbolTable__Type type, OOC_CHAR8 isOpenArray) {
  register OOC_INT32 i0,i1;

  i0 = isOpenArray;
  if (i0) goto l7;
  i0 = (OOC_INT32)type;
  i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11203)))), &_td_OOC_SymbolTable__ArrayDesc));
  if (i1) goto l5;
  i0 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11230)))), &_td_OOC_SymbolTable__ArrayDesc, 11230)), 11236))+40);
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
  _failed_function(10865); return 0;
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
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11765)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  type = (OOC_SymbolTable__Type)i0;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11790)))), &_td_OOC_SymbolTable__PointerDesc);
  if (i1) goto l3;
  return 0u;
  goto l4;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11834)))), &_td_OOC_SymbolTable__PointerDesc, 11834)), 11842))+40);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11834)))), &_td_OOC_SymbolTable__PointerDesc, 11834)), 11842))+40);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11851)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  type = (OOC_SymbolTable__Type)i0;
  return (OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11882)))), &_td_OOC_SymbolTable__RecordDesc));
l4:
  _failed_function(11571); return 0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__VariableInstance(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12215)))), &_td_OOC_SymbolTable__RecordDesc));
  if (i1) goto l3;
  i0 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12243)))), &_td_OOC_SymbolTable__RecordDesc, 12243)), 12250))+57);
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
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13062)))), &_td_OOC_SymbolTable__TypeClosureDesc);
  if (i2) goto l9;
  i2=0u;
  goto l11;
l9:
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 13087)))), &_td_OOC_SymbolTable__TypeClosureDesc);
  
l11:
  if (!i2) goto l29;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13133)))), &_td_OOC_SymbolTable__TypeClosureDesc, 13133)), 13145))+40);
  baseA = (OOC_SymbolTable__Type)i2;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 13177)))), &_td_OOC_SymbolTable__TypeClosureDesc, 13177)), 13189))+40);
  baseB = (OOC_SymbolTable__Type)i3;
  i4 = OOC_SymbolTable_TypeRules__SameType((OOC_SymbolTable__Type)i2, (OOC_SymbolTable__Type)i3);
  if (!i4) goto l29;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 13257))+28);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 13274))+28);
  _assert((i4==i3), 127, 13245);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 13317))+28);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 13326))+20);
  i = 0;
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 13333)), 0);
  i4 = 0<i3;
  if (!i4) goto l25;
  i4=0;
l17_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 13362))+28);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 13371))+20);
  i5 = _check_pointer(i5, 13378);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 13378))*4);
  tv = (OOC_SymbolTable__TypeVar)i5;
  i6 = (OOC_INT32)OOC_SymbolTable__TypeClosureDesc_Lookup((OOC_SymbolTable__TypeClosure)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13412)))), &_td_OOC_SymbolTable__TypeClosureDesc, 13412)), (OOC_SymbolTable__TypeVar)i5, (OOC_SymbolTable__TypeVar)i5);
  i5 = (OOC_INT32)OOC_SymbolTable__TypeClosureDesc_Lookup((OOC_SymbolTable__TypeClosure)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 13470)))), &_td_OOC_SymbolTable__TypeClosureDesc, 13470)), (OOC_SymbolTable__TypeVar)i5, (OOC_SymbolTable__TypeVar)i5);
  i5 = OOC_SymbolTable_TypeRules__SameType((OOC_SymbolTable__Type)i6, (OOC_SymbolTable__Type)i5);
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

  i0 = (OOC_INT32)a;
  i1 = (OOC_INT32)b;
  i2 = OOC_SymbolTable_TypeRules__SameType((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
  if (i2) goto l11;
  i2 = OOC_SymbolTable_TypeRules__IsOpenArrayType((OOC_SymbolTable__Type)i0);
  if (i2) goto l5;
  i2=0u;
  goto l7;
l5:
  i2 = OOC_SymbolTable_TypeRules__IsOpenArrayType((OOC_SymbolTable__Type)i1);
  
l7:
  if (i2) goto l9;
  i2=0u;
  goto l13;
l9:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13928)))), &_td_OOC_SymbolTable__ArrayDesc, 13928)), 13934))+44);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 13985)))), &_td_OOC_SymbolTable__ArrayDesc, 13985)), 13991))+44);
  i2 = OOC_SymbolTable_TypeRules__EqualTypes((OOC_SymbolTable__Type)i2, (OOC_SymbolTable__Type)i3);
  
  goto l13;
l11:
  i2=1u;
l13:
  if (i2) goto l23;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14023)))), &_td_OOC_SymbolTable__FormalParsDesc);
  if (i2) goto l17;
  i2=0u;
  goto l19;
l17:
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14047)))), &_td_OOC_SymbolTable__FormalParsDesc);
  
l19:
  if (i2) goto l21;
  i0=0u;
  goto l24;
l21:
  i0 = OOC_SymbolTable_TypeRules__FormalParamsMatch((OOC_SymbolTable__Type)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14106)))), &_td_OOC_SymbolTable__FormalParsDesc, 14106)), (OOC_SymbolTable__FormalPars)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14125)))), &_td_OOC_SymbolTable__FormalParsDesc, 14125)), 0u);
  
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
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14422)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14433)))), &_td_OOC_SymbolTable__PointerDesc);
  if (i1) goto l3;
  i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14458)))), &_td_OOC_SymbolTable__TypeVarDesc);
  
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
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14659)))), &_td_OOC_SymbolTable__PointerDesc);
  if (i1) goto l3;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14736)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  ptr = (OOC_SymbolTable__Type)i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14785)))), &_td_OOC_SymbolTable__PointerDesc, 14785)), 14793))+40);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14768)))), OOC_SymbolTable__TypeDesc_Closure)),OOC_SymbolTable__TypeDesc_Closure)((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
  return (OOC_SymbolTable__Type)i0;
  goto l4;
l3:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14696))+40);
  return (OOC_SymbolTable__Type)i0;
l4:
  _failed_function(14503); return 0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsRecord(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)type;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15028)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  return (OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15039)))), &_td_OOC_SymbolTable__RecordDesc));
  ;
}

OOC_SymbolTable__Type OOC_SymbolTable_TypeRules__RecordBaseType(OOC_SymbolTable__Type record) {
  register OOC_INT32 i0,i1;
  OOC_SymbolTable__Type ptr;

  i0 = (OOC_INT32)record;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15234)))), &_td_OOC_SymbolTable__RecordDesc);
  if (i1) goto l3;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15308)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  ptr = (OOC_SymbolTable__Type)i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15356)))), &_td_OOC_SymbolTable__RecordDesc, 15356)), 15363))+40);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15339)))), OOC_SymbolTable__TypeDesc_Closure)),OOC_SymbolTable__TypeDesc_Closure)((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
  return (OOC_SymbolTable__Type)i0;
  goto l4;
l3:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15269))+40);
  return (OOC_SymbolTable__Type)i0;
l4:
  _failed_function(15082); return 0;
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
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15818)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  return (OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15829)))), &_td_OOC_SymbolTable__ArrayDesc));
  ;
}

OOC_SymbolTable__Type OOC_SymbolTable_TypeRules__ArrayElementType(OOC_SymbolTable__Type array) {
  register OOC_INT32 i0,i1;
  OOC_SymbolTable__Type ptr;

  i0 = (OOC_INT32)array;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16021)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (i1) goto l3;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16095)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  ptr = (OOC_SymbolTable__Type)i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16142)))), &_td_OOC_SymbolTable__ArrayDesc, 16142)), 16148))+44);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16125)))), OOC_SymbolTable__TypeDesc_Closure)),OOC_SymbolTable__TypeDesc_Closure)((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
  return (OOC_SymbolTable__Type)i0;
  goto l4;
l3:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16054))+44);
  return (OOC_SymbolTable__Type)i0;
l4:
  _failed_function(15870); return 0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsInducedExtensionOf(OOC_SymbolTable__Type type, OOC_SymbolTable__Type base, OOC_CHAR8 ensureInduction) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_SymbolTable__Type ptr;
  OOC_SymbolTable__Type qualBase;

  i0 = (OOC_INT32)type;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16427)))), &_td_OOC_SymbolTable__TypeVarDesc);
  if (!i1) goto l4;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16471)))), &_td_OOC_SymbolTable__TypeVarDesc, 16471)), 16479))+40);
  type = (OOC_SymbolTable__Type)i0;
  
l4:
  i1 = (OOC_INT32)base;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16509)))), &_td_OOC_SymbolTable__TypeVarDesc);
  if (!i2) goto l7;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16553)))), &_td_OOC_SymbolTable__TypeVarDesc, 16553)), 16561))+40);
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
  i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17078)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  ptr = (OOC_SymbolTable__Type)i3;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 17120)))), &_td_OOC_SymbolTable__RecordDesc, 17120)), 17127))+40);
  qualBase = (OOC_SymbolTable__Type)i3;
  if (i2) goto l33;
  i4=0u;
  goto l35;
l33:
  i4 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17186)))), &_td_OOC_SymbolTable__TypeClosureDesc);
  
l35:
  if (i4) goto l37;
  i4=0u;
  goto l39;
l37:
  i4 = OOC_SymbolTable__TypeClosureDesc_ArgumentsInduced((OOC_SymbolTable__TypeClosure)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17231)))), &_td_OOC_SymbolTable__TypeClosureDesc, 17231)), (OOC_SymbolTable__Type)i3);
  i4 = !i4;
  
l39:
  if (!i4) goto l41;
  return 0u;
l41:
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17350)))), OOC_SymbolTable__TypeDesc_Closure)),OOC_SymbolTable__TypeDesc_Closure)((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i3);
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

  i0 = (OOC_INT32)type;
  i1 = (OOC_INT32)base;
  i0 = OOC_SymbolTable_TypeRules__IsInducedExtensionOf((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1, 0u);
  return i0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsExtensionOfNoParams(OOC_SymbolTable__Type type, OOC_SymbolTable__Type base) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)type;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18030)))), &_td_OOC_SymbolTable__TypeVarDesc);
  if (!i1) goto l4;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18074)))), &_td_OOC_SymbolTable__TypeVarDesc, 18074)), 18082))+40);
  type = (OOC_SymbolTable__Type)i0;
  
l4:
  i1 = (OOC_INT32)base;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 18112)))), &_td_OOC_SymbolTable__TypeVarDesc);
  if (!i2) goto l7;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 18156)))), &_td_OOC_SymbolTable__TypeVarDesc, 18156)), 18164))+40);
  base = (OOC_SymbolTable__Type)i1;
l7:
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18197)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  type = (OOC_SymbolTable__Type)i0;
  i1 = (OOC_INT32)base;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 18225)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i1);
  base = (OOC_SymbolTable__Type)i1;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18327)))), &_td_OOC_SymbolTable__PointerDesc);
  if (i2) goto l10;
  i2=0u;
  goto l12;
l10:
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 18351)))), &_td_OOC_SymbolTable__PointerDesc);
  
l12:
  if (!i2) goto l15;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18395)))), &_td_OOC_SymbolTable__PointerDesc, 18395)), 18403))+40);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18395)))), &_td_OOC_SymbolTable__PointerDesc, 18395)), 18403))+40);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 18412)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  type = (OOC_SymbolTable__Type)i0;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 18447)))), &_td_OOC_SymbolTable__PointerDesc, 18447)), 18455))+40);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 18447)))), &_td_OOC_SymbolTable__PointerDesc, 18447)), 18455))+40);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 18464)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i1);
  base = (OOC_SymbolTable__Type)i1;
  
l15:
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18498)))), &_td_OOC_SymbolTable__RecordDesc);
  if (i2) goto l18;
  i2=0u;
  goto l20;
l18:
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 18521)))), &_td_OOC_SymbolTable__RecordDesc);
  
l20:
  if (!i2) goto l46;
  i2 = i0!=(OOC_INT32)0;
  if (i2) goto l24;
  i2=0u;
  goto l26;
l24:
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18684)))), &_td_OOC_SymbolTable__RecordDesc);
  
l26:
  if (!i2) goto l46;
l28_loop:
  i2 = OOC_SymbolTable_TypeRules__SameType((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
  if (i2) goto l35;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18802)))), &_td_OOC_SymbolTable__RecordDesc, 18802)), 18809))+40);
  type = (OOC_SymbolTable__Type)i0;
  i2 = i0!=(OOC_INT32)0;
  if (!i2) goto l36;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18875)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
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
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18684)))), &_td_OOC_SymbolTable__RecordDesc);
  
l41:
  if (i2) goto l28_loop;
l46:
  return 0u;
  ;
}

OOC_SymbolTable__Type OOC_SymbolTable_TypeRules__FunctionResultType(OOC_SymbolTable__Type formalPars) {
  register OOC_INT32 i0,i1;
  OOC_SymbolTable__Type ptr;

  i0 = (OOC_INT32)formalPars;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19162)))), &_td_OOC_SymbolTable__FormalParsDesc);
  if (i1) goto l3;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19250)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  ptr = (OOC_SymbolTable__Type)i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 19302)))), &_td_OOC_SymbolTable__FormalParsDesc, 19302)), 19313))+44);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19285)))), OOC_SymbolTable__TypeDesc_Closure)),OOC_SymbolTable__TypeDesc_Closure)((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
  return (OOC_SymbolTable__Type)i0;
  goto l4;
l3:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19205))+44);
  return (OOC_SymbolTable__Type)i0;
l4:
  _failed_function(18992); return 0;
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
  _failed_function(19373); return 0;
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
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21346)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  ptr = (OOC_SymbolTable__Type)i1;
  i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 21383)))), &_td_OOC_SymbolTable__FormalParsDesc, 21383);
  baseFPars = (OOC_SymbolTable__FormalPars)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 21413))+44);
  i2 = i2==(OOC_INT32)0;
  if (i2) goto l3;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 21525))+44);
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21507)))), OOC_SymbolTable__TypeDesc_Closure)),OOC_SymbolTable__TypeDesc_Closure)((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i2);
  baseResult = (OOC_SymbolTable__Type)i2;
  
  goto l4;
l3:
  baseResult = (OOC_SymbolTable__Type)(OOC_INT32)0;
  i2=(OOC_INT32)0;
l4:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 21575))+52);
  i4 = (OOC_INT32)procFPars;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 21602))+52);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 21583)), 0);
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 21610)), 0);
  i3 = i3!=i5;
  if (i3) goto l149;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 21680))+44);
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
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 21845))+44);
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
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 22000))+44);
  i3 = (OOC_INT32)OOC_SymbolTable__Expand((OOC_SymbolTable__Type)i3);
  i3 = OOC_SymbolTable_TypeRules__SameType((OOC_SymbolTable__Type)i2, (OOC_SymbolTable__Type)i3);
  if (i3) goto l28;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 22063))+44);
  i3 = (OOC_INT32)OOC_SymbolTable__Expand((OOC_SymbolTable__Type)i3);
  i2 = OOC_SymbolTable_TypeRules__IsExtensionOf((OOC_SymbolTable__Type)i3, (OOC_SymbolTable__Type)i2);
  
  goto l29;
l28:
  i2=1u;
l29:
  i2 = !i2;
  
l31:
  if (i2) goto l143;
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 22134))+56);
  i3 = *(OOC_UINT8*)((_check_pointer(i4, 22165))+56);
  i2 = i2!=i3;
  if (i2) goto l141;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 22253))+52);
  i = 0;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 22261)), 0);
  i3 = 0<i2;
  if (!i3) goto l49;
  i3=0;
l37_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 22290))+52);
  i5 = _check_pointer(i5, 22298);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 22298))*4);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 22338))+52);
  i6 = _check_pointer(i6, 22346);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i3, i7, OOC_UINT32, 22346))*4);
  i5 = *(OOC_UINT8*)((_check_pointer(i5, 22301))+59);
  i6 = *(OOC_UINT8*)((_check_pointer(i6, 22349))+59);
  i5 = i5!=i6;
  if (i5) goto l40;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 22424))+52);
  i5 = _check_pointer(i5, 22431);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 22431))*4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 22434))+48);
  i5 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22406)))), OOC_SymbolTable__TypeDesc_Closure)),OOC_SymbolTable__TypeDesc_Closure)((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i5);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 22487))+52);
  i6 = _check_pointer(i6, 22494);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i3, i7, OOC_UINT32, 22494))*4);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 22497))+48);
  i6 = (OOC_INT32)OOC_SymbolTable__Expand((OOC_SymbolTable__Type)i6);
  i5 = OOC_SymbolTable_TypeRules__EqualTypes((OOC_SymbolTable__Type)i5, (OOC_SymbolTable__Type)i6);
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
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 23250))+60);
  i = 0;
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 23257)), 0);
  i2 = 0<i0;
  if (!i2) goto l79;
  i2=0;
l54_loop:
  j = 0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23317))+60);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 23324)), 0);
  i3 = 0!=i3;
  if (i3) goto l57;
  i3=0u;
  goto l59;
l57:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23365))+60);
  i3 = _check_pointer(i3, 23372);
  i5 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(0, i5, OOC_UINT32, 23372))*4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 23417))+60);
  i5 = _check_pointer(i5, 23424);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i2, i6, OOC_UINT32, 23424))*4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 23375))+20);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 23427))+20);
  i3 = OOC_SymbolTable_TypeRules__SameType((OOC_SymbolTable__Type)i3, (OOC_SymbolTable__Type)i5);
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
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23317))+60);
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 23324)), 0);
  i5 = i3!=i5;
  if (i5) goto l65;
  i5=0u;
  goto l67;
l65:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23365))+60);
  i5 = _check_pointer(i5, 23372);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 23372))*4);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 23417))+60);
  i6 = _check_pointer(i6, 23424);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i2, i7, OOC_UINT32, 23424))*4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 23375))+20);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 23427))+20);
  i5 = OOC_SymbolTable_TypeRules__SameType((OOC_SymbolTable__Type)i5, (OOC_SymbolTable__Type)i6);
  i5 = !i5;
  
l67:
  if (i5) goto l62_loop;
l71:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23503))+60);
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 23510)), 0);
  i3 = i3==i5;
  if (!i3) goto l74;
  return 0u;
l74:
  i2 = i2+1;
  i = i2;
  i3 = i2<i0;
  if (i3) goto l54_loop;
l79:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23623))+60);
  i = 0;
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 23630)), 0);
  i2 = 0<i0;
  if (!i2) goto l137;
  i2=0;
l82_loop:
  j = 0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 23690))+60);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 23697)), 0);
  i3 = 0!=i3;
  if (i3) goto l85;
  i3=0u;
  goto l87;
l85:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 23738))+60);
  i3 = _check_pointer(i3, 23745);
  i5 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(0, i5, OOC_UINT32, 23745))*4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23790))+60);
  i5 = _check_pointer(i5, 23797);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i2, i6, OOC_UINT32, 23797))*4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 23748))+20);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 23800))+20);
  i3 = OOC_SymbolTable_TypeRules__SameType((OOC_SymbolTable__Type)i3, (OOC_SymbolTable__Type)i5);
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
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 23690))+60);
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 23697)), 0);
  i5 = i3!=i5;
  if (i5) goto l93;
  i5=0u;
  goto l95;
l93:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 23738))+60);
  i5 = _check_pointer(i5, 23745);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 23745))*4);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23790))+60);
  i6 = _check_pointer(i6, 23797);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i2, i7, OOC_UINT32, 23797))*4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 23748))+20);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 23800))+20);
  i5 = OOC_SymbolTable_TypeRules__SameType((OOC_SymbolTable__Type)i5, (OOC_SymbolTable__Type)i6);
  i5 = !i5;
  
l95:
  if (i5) goto l90_loop;
l99:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 23876))+60);
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 23883)), 0);
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
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 22626))+60);
  i = 0;
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 22633)), 0);
  i2 = 0<i0;
  if (!i2) goto l137;
  i2=0;
l111_loop:
  j = 0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 22693))+60);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 22700)), 0);
  i3 = 0!=i3;
  if (i3) goto l114;
  i3=0u;
  goto l116;
l114:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 22746))+60);
  i3 = _check_pointer(i3, 22753);
  i5 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(0, i5, OOC_UINT32, 22753))*4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 22803))+60);
  i5 = _check_pointer(i5, 22810);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i2, i6, OOC_UINT32, 22810))*4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 22756))+20);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 22813))+20);
  i3 = OOC_SymbolTable_TypeRules__IsExtensionOf((OOC_SymbolTable__Type)i3, (OOC_SymbolTable__Type)i5);
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
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 22693))+60);
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 22700)), 0);
  i5 = i3!=i5;
  if (i5) goto l122;
  i5=0u;
  goto l124;
l122:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 22746))+60);
  i5 = _check_pointer(i5, 22753);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 22753))*4);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 22803))+60);
  i6 = _check_pointer(i6, 22810);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i2, i7, OOC_UINT32, 22810))*4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 22756))+20);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 22813))+20);
  i5 = OOC_SymbolTable_TypeRules__IsExtensionOf((OOC_SymbolTable__Type)i5, (OOC_SymbolTable__Type)i6);
  i5 = !i5;
  
l124:
  if (i5) goto l119_loop;
l128:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 22889))+60);
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 22896)), 0);
  i3 = i3==i5;
  if (!i3) goto l131;
  return 0u;
l131:
  i2 = i2+1;
  i = i2;
  i3 = i2<i0;
  if (i3) goto l111_loop;
l137:
  i0 = *(OOC_INT8*)((_check_pointer(i1, 24016))+58);
  i1 = *(OOC_INT8*)((_check_pointer(i4, 24036))+58);
  i0 = OOC_SymbolTable_TypeRules__CallingConventionsMatch(i0, i1);
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
  _failed_function(19948); return 0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsValidRedefinition(OOC_SymbolTable__Type baseFParsClosure, OOC_SymbolTable__FormalPars procFPars) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_SymbolTable__Type baseFPars;

  i0 = (OOC_INT32)baseFParsClosure;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 24471)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  baseFPars = (OOC_SymbolTable__Type)i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 24515)))), &_td_OOC_SymbolTable__FormalParsDesc, 24515)), 24526))+40);
  i2 = (OOC_INT32)procFPars;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 24565))+40);
  i1 = *(OOC_UINT8*)((_check_pointer(i1, 24535))+59);
  i3 = *(OOC_UINT8*)((_check_pointer(i3, 24574))+59);
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
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24887))+40);
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
  _failed_function(24687); return 0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsArrayType(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)type;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25231)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  return (OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25242)))), &_td_OOC_SymbolTable__ArrayDesc));
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

  i0 = (OOC_INT32)superType;
  i1 = (OOC_INT32)subType;
  i2 = OOC_SymbolTable_TypeRules__EqualTypes((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
  if (i2) goto l3;
  i2 = OOC_SymbolTable_TypeRules__IsExtensionOf((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
  
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
  i3 = OOC_SymbolTable_TypeRules__IsArrayCompatible((OOC_SymbolTable__Type)i1, (OOC_SymbolTable__Type)i0);
  
l11:
  if (i3) goto l43;
  i3 = OOC_SymbolTable_TypeRules__IsArray((OOC_SymbolTable__Type)i0);
  if (i3) goto l41;
  i3 = OOC_SymbolTable_TypeRules__IsRecord((OOC_SymbolTable__Type)i0);
  if (i3) goto l17;
  return 0u;
  goto l46;
l17:
  i3 = i0!=(OOC_INT32)0;
  if (!i3) goto l39;
  
l20_loop:
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26848)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  superType = (OOC_SymbolTable__Type)i0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26886))+8);
  field = (OOC_SymbolTable__Item)i3;
  i4 = i3!=(OOC_INT32)0;
  if (!i4) goto l34;
l23_loop:
  i4 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 26952)))), &_td_OOC_SymbolTable__FieldDeclDesc);
  if (!i4) goto l29;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 27015))+48);
  i4 = OOC_SymbolTable_TypeRules__IsComponentOf((OOC_SymbolTable__Type)i1, (OOC_SymbolTable__Type)i4, i2);
  if (!i4) goto l29;
  return 1u;
l29:
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 27185));
  field = (OOC_SymbolTable__Item)i3;
  i4 = i3!=(OOC_INT32)0;
  if (i4) goto l23_loop;
l34:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 27246)))), &_td_OOC_SymbolTable__RecordDesc, 27246)), 27253))+40);
  superType = (OOC_SymbolTable__Type)i0;
  i3 = i0!=(OOC_INT32)0;
  if (i3) goto l20_loop;
l39:
  return 0u;
  goto l46;
l41:
  i0 = (OOC_INT32)OOC_SymbolTable_TypeRules__ArrayElementType((OOC_SymbolTable__Type)i0);
  i0 = OOC_SymbolTable_TypeRules__IsComponentOf((OOC_SymbolTable__Type)i1, (OOC_SymbolTable__Type)i0, i2);
  return i0;
  goto l46;
l43:
  return 1u;
  goto l46;
l45:
  return 1u;
l46:
  _failed_function(25979); return 0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsByteCompatible(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 27529)))), &_td_OOC_SymbolTable__PredefTypeDesc);
  if (i1) goto l3;
  return 0u;
  goto l8;
l3:
  i1 = *(OOC_INT16*)((_check_pointer(i0, 27567))+40);
  i1 = i1==1;
  if (i1) goto l6;
  i0 = *(OOC_INT16*)((_check_pointer(i0, 27595))+40);
  i0 = i0==4;
  
  goto l7;
l6:
  i0=1u;
l7:
  return i0;
l8:
  _failed_function(27362); return 0;
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
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 28138)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  type = (OOC_SymbolTable__Type)i0;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 28163)))), &_td_OOC_SymbolTable__PredefTypeDesc);
  if (i1) goto l15;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 28257)))), &_td_OOC_SymbolTable__PointerDesc);
  if (i1) goto l13;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 28303)))), &_td_OOC_SymbolTable__FormalParsDesc);
  if (i1) goto l11;
  i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 28352)))), &_td_OOC_SymbolTable__TypeVarDesc);
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
  i1 = *(OOC_INT16*)((_check_pointer(i0, 28201))+40);
  i1 = i1==12;
  if (i1) goto l18;
  i0 = *(OOC_INT16*)((_check_pointer(i0, 28228))+40);
  i0 = i0==16;
  
  goto l19;
l18:
  i0=1u;
l19:
  return i0;
l20:
  _failed_function(27907); return 0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsReadOnly(OOC_SymbolTable__Module usingModule, OOC_SymbolTable__Declaration decl) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)decl;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 28674))+28);
  i1 = i1==2;
  if (i1) goto l3;
  i0=0u;
  goto l4;
l3:
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 28724)))), OOC_SymbolTable__ItemDesc_Module)),OOC_SymbolTable__ItemDesc_Module)((OOC_SymbolTable__Item)i0);
  i1 = (OOC_INT32)usingModule;
  i0 = i0!=i1;
  
l4:
  return i0;
  ;
}

OOC_CHAR8 OOC_SymbolTable_TypeRules__IsReadOnlyType(OOC_SymbolTable__Module usingModule, OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 28985)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 29018)))), &_td_OOC_SymbolTable__ArrayDesc, 29018)), 29024))+42);
  
l5:
  if (i1) goto l7;
  i0=0u;
  goto l8;
l7:
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 29055)))), OOC_SymbolTable__ItemDesc_Module)),OOC_SymbolTable__ItemDesc_Module)((OOC_SymbolTable__Item)i0);
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
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 29540)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  type = (OOC_SymbolTable__Type)i0;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 29564)))), &_td_OOC_SymbolTable__PointerDesc);
  if (i1) goto l48;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 29610)))), &_td_OOC_SymbolTable__TypeVarDesc);
  if (i1) goto l46;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 29654)))), &_td_OOC_SymbolTable__PredefTypeDesc);
  if (i1) goto l44;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 29717)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (i1) goto l42;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 29787)))), &_td_OOC_SymbolTable__RecordDesc);
  if (i1) goto l11;
  result = 1u;
  
  goto l49;
l11:
  result = 1u;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29834))+40);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l14;
  i1=1u;
  goto l15;
l14:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29888))+40);
  i1 = OOC_SymbolTable_TypeRules__IsAtomicType((OOC_SymbolTable__Type)i1);
  result = i1;
  
l15:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29927))+8);
  nested = (OOC_SymbolTable__Item)i0;
  if (i1) goto l18;
  i2=0u;
  goto l20;
l18:
  i2 = i0!=(OOC_INT32)0;
  
l20:
  if (!i2) goto l49;
l23_loop:
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 29996)))), &_td_OOC_SymbolTable__FieldDeclDesc);
  if (!i2) goto l31;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30046))+48);
  i2 = OOC_SymbolTable_TypeRules__IsAtomicType((OOC_SymbolTable__Type)i2);
  i2 = !i2;
  if (!i2) goto l31;
  result = 0u;
  i1=0u;
l31:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 30156));
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
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29763))+44);
  i0 = OOC_SymbolTable_TypeRules__IsAtomicType((OOC_SymbolTable__Type)i0);
  result = i0;
  
  goto l49;
l44:
  i0 = *(OOC_INT16*)((_check_pointer(i0, 29689))+40);
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
  i1 = *(OOC_INT32*)((_check_pointer(i0, 31238))+32);
  i1 = i1==(-2);
  if (!i1) goto l97;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31394)))), &_td_OOC_SymbolTable__PointerDesc);
  if (i1) goto l95;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31772)))), &_td_OOC_SymbolTable__FormalParsDesc);
  if (i1) goto l82;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32179)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (i1) goto l73;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32755)))), &_td_OOC_SymbolTable__RecordDesc);
  if (i1) goto l19;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 35367)))), &_td_OOC_SymbolTable__TypeVarDesc);
  if (i1) goto l17;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 35488)))), &_td_OOC_SymbolTable__QualTypeDesc);
  if (i1) goto l15;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 35482)))), 35482);
  goto l97;
l15:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35531))+40);
  OOC_SymbolTable_TypeRules__AllocateType((OOC_SymbolTable__Type)i1);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35568))+40);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35588))+40);
  i1 = *(OOC_INT32*)((_check_pointer(i1, 35577))+32);
  i2 = *(OOC_INT16*)((_check_pointer(i2, 35597))+36);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 35555)))), OOC_SymbolTable__TypeDesc_SetSize)),OOC_SymbolTable__TypeDesc_SetSize)((OOC_SymbolTable__Type)i0, i1, i2);
  goto l97;
l17:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35409))+40);
  OOC_SymbolTable_TypeRules__AllocateType((OOC_SymbolTable__Type)i1);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35443))+40);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35460))+40);
  i1 = *(OOC_INT32*)((_check_pointer(i1, 35449))+32);
  i2 = *(OOC_INT16*)((_check_pointer(i2, 35466))+36);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 35430)))), OOC_SymbolTable__TypeDesc_SetSize)),OOC_SymbolTable__TypeDesc_SetSize)((OOC_SymbolTable__Type)i0, i1, i2);
  goto l97;
l19:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32860))+40);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l22;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33205))+40);
  OOC_SymbolTable_TypeRules__AllocateType((OOC_SymbolTable__Type)i1);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33241))+40);
  i1 = *(OOC_INT16*)((_check_pointer(i1, 33251))+36);
  align = i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33282))+40);
  i2 = *(OOC_INT32*)((_check_pointer(i2, 33292))+32);
  size = i2;
  
  goto l27;
l22:
  align = 1;
  size = 0;
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 33002))+60);
  if (i1) goto l25;
  i1=0;
  goto l26;
l25:
  i1 = (OOC_INT32)OOC_SymbolTable__predefIdToType;
  i1 = _check_pointer(i1, 33130);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(12, i2, OOC_UINT8, 33130))*4);
  i1 = *(OOC_INT32*)((_check_pointer(i1, 33142))+32);
  size = i1;
  
l26:
  i2=i1;i1=1;
l27:
  i3 = *(OOC_INT16*)((_check_pointer(i0, 33410))+62);
  i3 = i3==0;
  if (i3) goto l30;
  i3 = *(OOC_INT16*)((_check_pointer(i0, 33506))+62);
  maxAlign = i3;
  
  goto l31;
l30:
  maxAlign = 32767;
  i3=32767;
l31:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33555))+8);
  nested = (OOC_SymbolTable__Item)i4;
  i5 = i4!=(OOC_INT32)0;
  if (i5) goto l34;
  {register OOC_INT32 h0=i1;i1=i2;i2=h0;}
  goto l64;
l34:
  {register OOC_INT32 h0=i1;i1=i4;i4=i2;i2=h0;}
l35_loop:
  i5 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 33623)))), &_td_OOC_SymbolTable__FieldDeclDesc);
  if (!i5) goto l59;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 33674))+48);
  OOC_SymbolTable_TypeRules__AllocateType((OOC_SymbolTable__Type)i5);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 33715))+48);
  i5 = *(OOC_INT16*)((_check_pointer(i5, 33721))+36);
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
  i6 = *(OOC_UINT8*)((_check_pointer(i0, 34043))+56);
  if (i6) goto l53;
  i6 = _mod(i4,i5);
  i7 = i6!=0;
  if (!i7) goto l52;
  i4 = i4+(i5-i6);
  size = i4;
  
l52:
  OOC_SymbolTable__FieldDeclDesc_SetOffset((OOC_SymbolTable__FieldDecl)i1, i4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34726))+48);
  i5 = *(OOC_INT32*)((_check_pointer(i5, 34732))+32);
  i4 = i4+i5;
  size = i4;
  
  goto l59;
l53:
  OOC_SymbolTable__FieldDeclDesc_SetOffset((OOC_SymbolTable__FieldDecl)i1, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34273))+48);
  i5 = *(OOC_INT32*)((_check_pointer(i5, 34279))+32);
  i5 = i5>i4;
  if (!i5) goto l59;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34329))+48);
  i4 = *(OOC_INT32*)((_check_pointer(i4, 34335))+32);
  size = i4;
  
l59:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 34826));
  nested = (OOC_SymbolTable__Item)i1;
  i5 = i1!=(OOC_INT32)0;
  if (i5) goto l35_loop;
l63:
  i1=i4;
l64:
  i3 = _mod(i1,i2);
  i4 = i3!=0;
  if (i4) goto l67;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 35055)))), OOC_SymbolTable__TypeDesc_SetSize)),OOC_SymbolTable__TypeDesc_SetSize)((OOC_SymbolTable__Type)i0, i1, i2);
  goto l68;
l67:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34979)))), OOC_SymbolTable__TypeDesc_SetSize)),OOC_SymbolTable__TypeDesc_SetSize)((OOC_SymbolTable__Type)i0, ((i1+i2)-i3), i2);
l68:
  i1 = OOC_SymbolTable_TypeRules__IsAtomicType((OOC_SymbolTable__Type)i0);
  if (!i1) goto l97;
  *(OOC_UINT8*)((_check_pointer(i0, 35323))+61) = 1u;
  goto l97;
l73:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32220))+44);
  OOC_SymbolTable_TypeRules__AllocateType((OOC_SymbolTable__Type)i1);
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 32251))+40);
  if (i1) goto l76;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32394))+44);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32444))+44);
  i3 = *(OOC_INT32*)((_check_pointer(i0, 32381))+52);
  i1 = *(OOC_INT32*)((_check_pointer(i1, 32407))+32);
  i2 = *(OOC_INT16*)((_check_pointer(i2, 32457))+36);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32366)))), OOC_SymbolTable__TypeDesc_SetSize)),OOC_SymbolTable__TypeDesc_SetSize)((OOC_SymbolTable__Type)i0, (i3*i1), i2);
  goto l77;
l76:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32316))+44);
  i1 = *(OOC_INT16*)((_check_pointer(i1, 32329))+36);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32284)))), OOC_SymbolTable__TypeDesc_SetSize)),OOC_SymbolTable__TypeDesc_SetSize)((OOC_SymbolTable__Type)i0, (-1), i1);
l77:
  i1 = OOC_SymbolTable_TypeRules__IsAtomicType((OOC_SymbolTable__Type)i0);
  if (!i1) goto l97;
  *(OOC_UINT8*)((_check_pointer(i0, 32711))+60) = 1u;
  goto l97;
l82:
  i1 = (OOC_INT32)OOC_SymbolTable__predefIdToType;
  i2 = _check_pointer(i1, 31833);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(12, i3, OOC_UINT8, 31833))*4);
  i1 = _check_pointer(i1, 31893);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(12, i3, OOC_UINT8, 31893))*4);
  i2 = *(OOC_INT32*)((_check_pointer(i2, 31845))+32);
  i1 = *(OOC_INT16*)((_check_pointer(i1, 31905))+36);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31804)))), OOC_SymbolTable__TypeDesc_SetSize)),OOC_SymbolTable__TypeDesc_SetSize)((OOC_SymbolTable__Type)i0, i2, i1);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31967))+40);
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l85;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32018))+40);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 32028))+48);
  OOC_SymbolTable_TypeRules__AllocateType((OOC_SymbolTable__Type)i1);
l85:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32081))+52);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 32089)), 0);
  i = 0;
  i2 = 0<i1;
  if (!i2) goto l97;
  i2=0;
l88_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32125))+52);
  i3 = _check_pointer(i3, 32133);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 32133))*4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 32136))+48);
  OOC_SymbolTable_TypeRules__AllocateType((OOC_SymbolTable__Type)i3);
  i2 = i2+1;
  i = i2;
  i3 = i2<i1;
  if (i3) goto l88_loop;
  goto l97;
l95:
  i1 = (OOC_INT32)OOC_SymbolTable__predefIdToType;
  i2 = _check_pointer(i1, 31452);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(12, i3, OOC_UINT8, 31452))*4);
  i1 = _check_pointer(i1, 31512);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(12, i3, OOC_UINT8, 31512))*4);
  i2 = *(OOC_INT32*)((_check_pointer(i2, 31464))+32);
  i1 = *(OOC_INT16*)((_check_pointer(i1, 31524))+36);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31423)))), OOC_SymbolTable__TypeDesc_SetSize)),OOC_SymbolTable__TypeDesc_SetSize)((OOC_SymbolTable__Type)i0, i2, i1);
l97:
  return;
  ;
}

void OOC_OOC_SymbolTable_TypeRules_init(void) {

  return;
  ;
}

/* --- */
