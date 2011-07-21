#include <OOC/C/Naming.d>
#include <__oo2c.h>
#include <setjmp.h>

void OOC_C_Naming__QualTypeDescrDesc_INIT(OOC_C_Naming__QualTypeDescr qtd, OOC_INT32 id, OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1,i2;
  OOC_CHAR8 str[16];

  i0 = (OOC_INT32)type;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1693)))), &_td_OOC_SymbolTable__TypeClosureDesc);
  if (i1) goto l3;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1722)))), &_td_OOC_SymbolTable__TypeVarDesc);
  
  goto l4;
l3:
  i1=1u;
l4:
  _assert(i1, 127, 1680);
  i1 = id;
  IntStr__IntToStr(i1, (void*)(OOC_INT32)str, 16);
  i1 = (OOC_INT32)qtd;
  i2 = (OOC_INT32)Object__NewLatin1((void*)(OOC_INT32)str, 16);
  *(OOC_INT32*)(_check_pointer(i1, 1777)) = ((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c0),(void*)i2));
  *(OOC_INT32*)((_check_pointer(i1, 1827))+4) = i0;
  return;
  ;
}

void OOC_C_Naming__QualTypeDataDesc_INIT(OOC_C_Naming__QualTypeData qtdData) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)qtdData;
  i1 = (OOC_INT32)RT0__NewObject(_td__qtd1.baseTypes[0]);
  ADT_ArrayList__ArrayListDesc_INIT((ADT_ArrayList__ArrayList)i1, 8);
  *(OOC_INT32*)(_check_pointer(i0, 1917)) = i1;
  return;
  ;
}

Object__String OOC_C_Naming__NameOfDeclaration(OOC_SymbolTable__Declaration decl) {
  register OOC_INT32 i0,i1,i2;
  OOC_CHAR8 relativeName;
  OOC_C_Naming__Buffer str;
  OOC_SymbolTable__Item m;
  OOC_INT32 i;
  OOC_Scanner_InputBuffer__CharArray relativeId;
  Object__String name;
  Object__Object obj;
  auto OOC_CHAR8 OOC_C_Naming__NameOfDeclaration_IsReservedName(OOC_CHAR8 str[], OOC_LEN str_0d);
  auto OOC_CHAR8 OOC_C_Naming__NameOfDeclaration_IsInterfaceModule(OOC_SymbolTable__Module module);
    
    OOC_CHAR8 OOC_C_Naming__NameOfDeclaration_IsReservedName(OOC_CHAR8 str[], OOC_LEN str_0d) {
      register OOC_INT32 i0,i1;

      i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT8, 2429)));
      i0 = i0==105u;
      if (i0) goto l3;
      i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT8, 2447)));
      i0 = i0==119u;
      
      goto l5;
l3:
      i0=1u;
l5:
      if (i0) goto l7;
      i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT8, 2465)));
      i0 = i0==108u;
      
      goto l9;
l7:
      i0=1u;
l9:
      if (i0) goto l11;
      i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT8, 2492)));
      i0 = i0==102u;
      
      goto l13;
l11:
      i0=1u;
l13:
      if (i0) goto l15;
      i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT8, 2510)));
      i0 = i0==100u;
      
      goto l17;
l15:
      i0=1u;
l17:
      if (i0) goto l19;
      return 0u;
      goto l41;
l19:
      i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(1, str_0d, OOC_UINT32, 2567)));
      i0 = (OOC_UINT8)48u<=(OOC_UINT8)i0;
      if (i0) goto l22;
      i0=0u;
      goto l24;
l22:
      i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(1, str_0d, OOC_UINT32, 2578)));
      i0 = (OOC_UINT8)i0<=(OOC_UINT8)57u;
      
l24:
      if (i0) goto l26;
      i0=1;
      goto l36;
l26:
      i0=1;
l27_loop:
      i0 = i0+1;
      i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 2567)));
      i1 = (OOC_UINT8)48u<=(OOC_UINT8)i1;
      if (i1) goto l30;
      i1=0u;
      goto l32;
l30:
      i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 2578)));
      i1 = (OOC_UINT8)i1<=(OOC_UINT8)57u;
      
l32:
      if (i1) goto l27_loop;
l36:
      i1 = i0>1;
      if (i1) goto l39;
      i0=0u;
      goto l40;
l39:
      i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 2653)));
      i0 = i0==0u;
      
l40:
      return i0;
l41:
      _failed_function(2235); return 0;
      ;
    }

    
    OOC_CHAR8 OOC_C_Naming__NameOfDeclaration_IsInterfaceModule(OOC_SymbolTable__Module module) {
      register OOC_INT32 i0;

      i0 = (OOC_INT32)module;
      i0 = *(OOC_INT8*)((_check_pointer(i0, 2824))+52);
      return (i0==3);
      ;
    }


  relativeName = 0u;
  i0 = (OOC_INT32)decl;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2935)))), &_td_OOC_SymbolTable__VarDeclDesc);
  if (i1) goto l3;
  i1=0u;
  goto l13;
l3:
  i1 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2970)))), &_td_OOC_SymbolTable__VarDeclDesc, 2970)), 2978))+56);
  if (i1) goto l6;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3009))+4);
  i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3018)))), &_td_OOC_SymbolTable__ModuleDesc));
  
  goto l8;
l6:
  i1=1u;
l8:
  if (i1) goto l10;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3067)))), OOC_SymbolTable__ItemDesc_Module)),OOC_SymbolTable__ItemDesc_Module)((OOC_SymbolTable__Item)i0);
  i1 = OOC_C_Naming__NameOfDeclaration_IsInterfaceModule((OOC_SymbolTable__Module)i1);
  
  goto l13;
l10:
  i1=1u;
l13:
  if (i1) goto l35;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3278)))), &_td_OOC_SymbolTable__FieldDeclDesc);
  if (i1) goto l33;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3541)))), &_td_OOC_SymbolTable__ProcDeclDesc);
  if (i1) goto l19;
  i1=0u;
  goto l21;
l19:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3570)))), &_td_OOC_SymbolTable__ProcDeclDesc, 3570)), 3579))+68);
  i1 = i1!=(OOC_INT32)0;
  
l21:
  if (i1) goto l31;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3815)))), &_td_OOC_SymbolTable__ProcDeclDesc);
  if (i1) goto l25;
  i1=0u;
  goto l27;
l25:
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3857)))), OOC_SymbolTable__ItemDesc_Module)),OOC_SymbolTable__ItemDesc_Module)((OOC_SymbolTable__Item)i0);
  i1 = OOC_C_Naming__NameOfDeclaration_IsInterfaceModule((OOC_SymbolTable__Module)i1);
  
l27:
  if (i1) goto l29;
  i1=0u;
  goto l37;
l29:
  relativeName = 1u;
  i1=1u;
  goto l37;
l31:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3771)))), &_td_OOC_SymbolTable__ProcDeclDesc, 3771)), 3780))+68);
  return (Object__String)i1;
  i1=0u;
  goto l37;
l33:
  i1 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3493)))), &_td_OOC_SymbolTable__FieldDeclDesc, 3493)), 3503))+60);
  i1 = !i1;
  relativeName = i1;
  
  goto l37;
l35:
  relativeName = 1u;
  i1=1u;
l37:
  if (i1) goto l71;
  m = (OOC_SymbolTable__Item)i0;
  i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4164)))), &_td_OOC_SymbolTable__ModuleDesc));
  if (i1) goto l41;
  i1=i0;
  goto l47;
l41:
  i1=i0;
l42_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4196))+4);
  m = (OOC_SymbolTable__Item)i1;
  i2 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4164)))), &_td_OOC_SymbolTable__ModuleDesc));
  if (i2) goto l42_loop;
l47:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4234)))), &_td_OOC_SymbolTable__ModuleDesc, 4234)), 4241))+20);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4247))+12);
  _copy_8((const void*)(_check_pointer(i1, 4252)),(void*)(OOC_INT32)str,2048);
  i = 0;
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, 2048, OOC_UINT32, 4291)));
  i1 = i1!=0u;
  if (i1) goto l50;
  i1=0;
  goto l59;
l50:
  i1=0;
l51_loop:
  i2 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i1, 2048, OOC_UINT32, 4319)));
  i2 = i2==58u;
  if (!i2) goto l54;
  *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i1, 2048, OOC_UINT32, 4338))) = 95u;
l54:
  i1 = i1+1;
  i = i1;
  i2 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i1, 2048, OOC_UINT32, 4291)));
  i2 = i2!=0u;
  if (i2) goto l51_loop;
l59:
  Strings__Append((OOC_CHAR8*)"__", 3, (void*)(OOC_INT32)str, 2048);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4561)))), OOC_SymbolTable__DeclarationDesc_GetId)),OOC_SymbolTable__DeclarationDesc_GetId)((OOC_SymbolTable__Declaration)i0);
  relativeId = (OOC_Scanner_InputBuffer__CharArray)i0;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i0, 4604)), 0);
  Strings__Append((void*)(_check_pointer(i0, 4604)), i2, (void*)(OOC_INT32)str, 2048);
  i0 = i1+2;
  i = i0;
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, 2048, OOC_UINT32, 4647)));
  i1 = i1!=0u;
  if (!i1) goto l72;
l62_loop:
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, 2048, OOC_UINT32, 4675)));
  i1 = i1==46u;
  if (!i1) goto l65;
  *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, 2048, OOC_UINT32, 4694))) = 95u;
l65:
  i0 = i0+1;
  i = i0;
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, 2048, OOC_UINT32, 4647)));
  i1 = i1!=0u;
  if (i1) goto l62_loop;
  goto l72;
l71:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4055))+20);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4061))+12);
  _copy_8((const void*)(_check_pointer(i0, 4066)),(void*)(OOC_INT32)str,2048);
l72:
  i0 = (OOC_INT32)Object__NewLatin1((void*)(OOC_INT32)str, 2048);
  name = (Object__String)i0;
  i1 = (OOC_INT32)OOC_C_Naming__keywords;
  i1 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i1, (Object__Object)i0);
  if (i1) goto l79;
  i1 = OOC_C_Naming__NameOfDeclaration_IsReservedName((void*)(OOC_INT32)str, 2048);
  if (i1) goto l77;
  return (Object__String)i0;
  goto l80;
l77:
  i1 = (OOC_INT32)OOC_C_Naming__rwPrefix;
  i0 = (OOC_INT32)Object__StringDesc_Concat((Object__String)i1, (Object__String)i0);
  return (Object__String)i0;
  goto l80;
l79:
  i1 = (OOC_INT32)OOC_C_Naming__keywords;
  i0 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i1, (Object__Object)i0);
  obj = (Object__Object)i0;
  return (Object__String)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4869)))), &_td_Object__StringDesc, 4869));
l80:
  _failed_function(1993); return 0;
  ;
}

Object__String OOC_C_Naming__NameOfModuleInit(OOC_SymbolTable__Module m, OOC_CHAR8 initFunction, OOC_CHAR8 rtWrapper) {
  register OOC_INT32 i0,i1;
  OOC_C_Naming__Buffer str;

  i0 = (OOC_INT32)m;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5222))+20);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5228))+12);
  _copy_8((const void*)(_check_pointer(i0, 5233)),(void*)(OOC_INT32)str,2048);
  i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, 2048, OOC_UINT32, 5268)));
  i0 = i0!=0u;
  if (!i0) goto l11;
  i0=0;
l3_loop:
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, 2048, OOC_UINT32, 5294)));
  i1 = i1==58u;
  if (!i1) goto l6;
  *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, 2048, OOC_UINT32, 5313))) = 95u;
l6:
  i0 = i0+1;
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, 2048, OOC_UINT32, 5268)));
  i1 = i1!=0u;
  if (i1) goto l3_loop;
l11:
  Strings__Insert((OOC_CHAR8*)"OOC_", 5, 0, (void*)(OOC_INT32)str, 2048);
  i0 = initFunction;
  if (i0) goto l18;
  i0 = rtWrapper;
  if (i0) goto l16;
  Strings__Append((OOC_CHAR8*)"_destroy", 9, (void*)(OOC_INT32)str, 2048);
  goto l23;
l16:
  Strings__Append((OOC_CHAR8*)"_close", 7, (void*)(OOC_INT32)str, 2048);
  goto l23;
l18:
  i0 = rtWrapper;
  if (i0) goto l21;
  Strings__Append((OOC_CHAR8*)"_init", 6, (void*)(OOC_INT32)str, 2048);
  goto l23;
l21:
  Strings__Append((OOC_CHAR8*)"_open", 6, (void*)(OOC_INT32)str, 2048);
l23:
  i0 = (OOC_INT32)Object__NewLatin1((void*)(OOC_INT32)str, 2048);
  return (Object__String)i0;
  ;
}

Object__String OOC_C_Naming__NameOfLengthParam(OOC_SymbolTable__VarDecl param, OOC_INT32 dim) {
  register OOC_INT32 i0,i1;
  OOC_CHAR8 str[16];

  i0 = dim;
  IntStr__IntToStr(i0, (void*)(OOC_INT32)str, 16);
  i0 = (OOC_INT32)param;
  i0 = (OOC_INT32)OOC_C_Naming__NameOfDeclaration((OOC_SymbolTable__Declaration)i0);
  i1 = (OOC_INT32)Object__NewLatin1((void*)(OOC_INT32)str, 16);
  return (Object__String)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)i0,(void*)((OOC_INT32)_c1))),(void*)i1)),(void*)((OOC_INT32)_c2)));
  ;
}

Object__String OOC_C_Naming__NameOfTypeTagParam(OOC_SymbolTable__VarDecl param) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)param;
  i0 = (OOC_INT32)OOC_C_Naming__NameOfDeclaration((OOC_SymbolTable__Declaration)i0);
  return (Object__String)((OOC_INT32)Object__Concat2((void*)i0,(void*)((OOC_INT32)_c3)));
  ;
}

Object__String OOC_C_Naming__NameOfType(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6265)))), &_td_OOC_SymbolTable__TypeVarDesc);
  if (i1) goto l20;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6345))+24);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l5;
  i1=0u;
  goto l7;
l5:
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6372)))), &_td_OOC_SymbolTable__QualTypeDesc);
  
l7:
  if (!i1) goto l19;
l10_loop:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6469)))), &_td_OOC_SymbolTable__QualTypeDesc, 6469)), 6478))+40);
  type = (OOC_SymbolTable__Type)i0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6345))+24);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l13;
  i1=0u;
  goto l15;
l13:
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6372)))), &_td_OOC_SymbolTable__QualTypeDesc);
  
l15:
  if (i1) goto l10_loop;
l19:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6518))+24);
  _assert((i1!=(OOC_INT32)0), 127, 6506);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6575))+24);
  i0 = (OOC_INT32)OOC_C_Naming__NameOfDeclaration((OOC_SymbolTable__Declaration)i0);
  return (Object__String)i0;
  goto l21;
l20:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6310))+40);
  i0 = (OOC_INT32)OOC_C_Naming__NameOfType((OOC_SymbolTable__Type)i0);
  return (Object__String)i0;
l21:
  _failed_function(6142); return 0;
  ;
}

Object__String OOC_C_Naming__NameOfTypeDescriptor(OOC_SymbolTable__Type type, OOC_C_Naming__QualTypeData qtdData) {
  register OOC_INT32 i0,i1,i2;
  OOC_SymbolTable__Type base;
  Object__String dummy;
  OOC_CHAR8 str[32];
  OOC_CHAR8 str2[32];
  Object__String string;
  auto Object__String OOC_C_Naming__NameOfTypeDescriptor_AddToQtd(OOC_SymbolTable__Type type);
    
    Object__String OOC_C_Naming__NameOfTypeDescriptor_AddToQtd(OOC_SymbolTable__Type type) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      OOC_INT32 i;
      OOC_C_Naming__QualTypeDescr qtd;

      i0 = (OOC_INT32)qtdData;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7186));
      i = 0;
      i0 = *(OOC_INT32*)((_check_pointer(i0, 7191))+4);
      i1 = (OOC_INT32)type;
      i2 = 0<i0;
      if (!i2) goto l11;
      i2=0;
l3_loop:
      i3 = (OOC_INT32)qtdData;
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 7238));
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 7243));
      i3 = _check_pointer(i3, 7249);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 7249))*4);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 7252))+4);
      i3 = OOC_SymbolTable_TypeRules__SameType((OOC_SymbolTable__Type)i1, (OOC_SymbolTable__Type)i3);
      if (!i3) goto l6;
      i3 = (OOC_INT32)qtdData;
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 7288));
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 7293));
      i3 = _check_pointer(i3, 7299);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 7299))*4);
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 7302));
      return (Object__String)i3;
l6:
      i2 = i2+1;
      i = i2;
      i3 = i2<i0;
      if (i3) goto l3_loop;
l11:
      i0 = (OOC_INT32)RT0__NewObject(_td_OOC_C_Naming__QualTypeDescr.baseTypes[0]);
      i2 = (OOC_INT32)qtdData;
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 7379));
      i2 = *(OOC_INT32*)((_check_pointer(i2, 7384))+4);
      OOC_C_Naming__QualTypeDescrDesc_INIT((OOC_C_Naming__QualTypeDescr)i0, i2, (OOC_SymbolTable__Type)i1);
      qtd = (OOC_C_Naming__QualTypeDescr)i0;
      i1 = (OOC_INT32)qtdData;
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 7411));
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 7411));
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 7416)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i1, (Object__Object)i0);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7446));
      return (Object__String)i0;
      ;
    }


  i0 = (OOC_INT32)type;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7495)))), &_td_OOC_SymbolTable__QualTypeDesc);
  if (i1) goto l58;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7586)))), &_td_OOC_SymbolTable__TypeVarDesc);
  if (i1) goto l56;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7649)))), &_td_OOC_SymbolTable__TypeClosureDesc);
  if (i1) goto l34;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8543)))), &_td_OOC_SymbolTable__FormalParsDesc);
  if (i1) goto l32;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8623)))), &_td_OOC_SymbolTable__PredefTypeDesc);
  if (i1) goto l15;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9335))+24);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l13;
  i0 = (OOC_INT32)OOC_C_Naming__NameOfType((OOC_SymbolTable__Type)i0);
  i1 = (OOC_INT32)OOC_C_Naming__tdPrefix;
  i0 = (OOC_INT32)Object__StringDesc_Concat((Object__String)i1, (Object__String)i0);
  return (Object__String)i0;
  goto l59;
l13:
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9419)))), OOC_SymbolTable__ItemDesc_Module)),OOC_SymbolTable__ItemDesc_Module)((OOC_SymbolTable__Item)i0);
  i1 = (OOC_INT32)OOC_C_Naming__NameOfDeclaration((OOC_SymbolTable__Declaration)i1);
  i2 = (OOC_INT32)OOC_C_Naming__tdPrefix;
  i1 = (OOC_INT32)Object__StringDesc_Concat((Object__String)i2, (Object__String)i1);
  string = (Object__String)i1;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9462))+20);
  i0 = *(OOC_INT32*)(_check_pointer(i0, 9472));
  IntStr__IntToStr(i0, (void*)(OOC_INT32)str, 32);
  i0 = (OOC_INT32)Object__NewLatin1((void*)(OOC_INT32)str, 32);
  i0 = (OOC_INT32)Object__StringDesc_Concat((Object__String)i1, (Object__String)i0);
  return (Object__String)i0;
  goto l59;
l15:
  i0 = *(OOC_INT16*)((_check_pointer(i0, 8658))+40);
  switch (i0) {
  case 0:
    _copy_8((const void*)(OOC_CHAR8*)"boolean",(void*)(OOC_INT32)str,32);
    goto l30;
  case 1:
    _copy_8((const void*)(OOC_CHAR8*)"char",(void*)(OOC_INT32)str,32);
    goto l30;
  case 2:
    _copy_8((const void*)(OOC_CHAR8*)"longchar",(void*)(OOC_INT32)str,32);
    goto l30;
  case 3:
    _copy_8((const void*)(OOC_CHAR8*)"ucs4char",(void*)(OOC_INT32)str,32);
    goto l30;
  case 4:
    _copy_8((const void*)(OOC_CHAR8*)"shortint",(void*)(OOC_INT32)str,32);
    goto l30;
  case 5:
    _copy_8((const void*)(OOC_CHAR8*)"integer",(void*)(OOC_INT32)str,32);
    goto l30;
  case 6:
    _copy_8((const void*)(OOC_CHAR8*)"longint",(void*)(OOC_INT32)str,32);
    goto l30;
  case 8:
    _copy_8((const void*)(OOC_CHAR8*)"real",(void*)(OOC_INT32)str,32);
    goto l30;
  case 9:
    _copy_8((const void*)(OOC_CHAR8*)"longreal",(void*)(OOC_INT32)str,32);
    goto l30;
  case 10:
    _copy_8((const void*)(OOC_CHAR8*)"set32",(void*)(OOC_INT32)str,32);
    goto l30;
  case 11:
    _copy_8((const void*)(OOC_CHAR8*)"byte",(void*)(OOC_INT32)str,32);
    goto l30;
  case 12:
    _copy_8((const void*)(OOC_CHAR8*)"ptr",(void*)(OOC_INT32)str,32);
    goto l30;
  default:
    _failed_case(i0, 8649);
    goto l30;
  }
l30:
  _copy_8((const void*)(OOC_CHAR8*)"RT0",(void*)(OOC_INT32)str2,32);
  Strings__Append((OOC_CHAR8*)"__", 3, (void*)(OOC_INT32)str2, 32);
  Strings__Append((void*)(OOC_INT32)str, 32, (void*)(OOC_INT32)str2, 32);
  i0 = (OOC_INT32)Object__NewLatin1((void*)(OOC_INT32)str2, 32);
  return (Object__String)i0;
  goto l59;
l32:
  return (Object__String)((OOC_INT32)_c4);
  goto l59;
l34:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7688))+40);
  base = (OOC_SymbolTable__Type)i1;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7866)))), &_td_OOC_SymbolTable__PointerDesc);
  if (i2) goto l40;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8006)))), &_td_OOC_SymbolTable__RecordDesc);
  if (i2) goto l44;
  i2 = (OOC_INT32)qtdData;
  i2 = (OOC_INT32)OOC_C_Naming__NameOfTypeDescriptor((OOC_SymbolTable__Type)i1, (OOC_C_Naming__QualTypeData)i2);
  return (Object__String)i2;
  goto l44;
l40:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 7911))+40);
  i2 = OOC_SymbolTable_TypeRules__IsRecord((OOC_SymbolTable__Type)i2);
  i2 = !i2;
  if (!i2) goto l44;
  i2 = (OOC_INT32)qtdData;
  i2 = (OOC_INT32)OOC_C_Naming__NameOfTypeDescriptor((OOC_SymbolTable__Type)i1, (OOC_C_Naming__QualTypeData)i2);
  return (Object__String)i2;
l44:
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8145)))), &_td_OOC_SymbolTable__PointerDesc);
  if (i2) goto l53;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8248)))), &_td_OOC_SymbolTable__RecordDesc);
  if (!i2) goto l54;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8280))+40);
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l54;
  i1 = (OOC_INT32)OOC_SymbolTable_TypeRules__RecordBaseType((OOC_SymbolTable__Type)i0);
  i2 = (OOC_INT32)qtdData;
  i1 = (OOC_INT32)OOC_C_Naming__NameOfTypeDescriptor((OOC_SymbolTable__Type)i1, (OOC_C_Naming__QualTypeData)i2);
  dummy = (Object__String)i1;
  goto l54;
l53:
  i1 = (OOC_INT32)OOC_SymbolTable_TypeRules__PointerBaseType((OOC_SymbolTable__Type)i0);
  i2 = (OOC_INT32)qtdData;
  i1 = (OOC_INT32)OOC_C_Naming__NameOfTypeDescriptor((OOC_SymbolTable__Type)i1, (OOC_C_Naming__QualTypeData)i2);
  dummy = (Object__String)i1;
l54:
  i0 = (OOC_INT32)OOC_C_Naming__NameOfTypeDescriptor_AddToQtd((OOC_SymbolTable__Type)i0);
  return (Object__String)i0;
  goto l59;
l56:
  i0 = (OOC_INT32)OOC_C_Naming__NameOfTypeDescriptor_AddToQtd((OOC_SymbolTable__Type)i0);
  return (Object__String)i0;
  goto l59;
l58:
  i0 = (OOC_INT32)OOC_SymbolTable__Expand((OOC_SymbolTable__Type)i0);
  i1 = (OOC_INT32)qtdData;
  i0 = (OOC_INT32)OOC_C_Naming__NameOfTypeDescriptor((OOC_SymbolTable__Type)i0, (OOC_C_Naming__QualTypeData)i1);
  return (Object__String)i0;
l59:
  _failed_function(6628); return 0;
  ;
}

Object__String OOC_C_Naming__NameOfTypeBoundIndex(OOC_SymbolTable__ProcDecl proc) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)proc;
  i0 = (OOC_INT32)OOC_C_Naming__NameOfDeclaration((OOC_SymbolTable__Declaration)i0);
  return (Object__String)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c5),(void*)i0));
  ;
}

Object__String OOC_C_Naming__NameOfTypeBoundSignature(OOC_SymbolTable__ProcDecl proc) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)proc;
  i0 = (OOC_INT32)OOC_C_Naming__NameOfDeclaration((OOC_SymbolTable__Declaration)i0);
  return (Object__String)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c6),(void*)i0));
  ;
}

static void OOC_C_Naming__Init(void) {
  register OOC_INT32 i0;
  auto void OOC_C_Naming__Init_RW(const OOC_CHAR8 str__ref[], OOC_LEN str_0d);
    
    void OOC_C_Naming__Init_RW(const OOC_CHAR8 str__ref[], OOC_LEN str_0d) {
      register OOC_INT32 i0,i1,i2;
      OOC_ALLOCATE_VPAR(str,OOC_CHAR8 ,str_0d)

      OOC_INITIALIZE_VPAR(str__ref,str,OOC_CHAR8 ,str_0d)
      i0 = (OOC_INT32)Object__NewLatin1((void*)(OOC_INT32)str, str_0d);
      i1 = (OOC_INT32)OOC_C_Naming__rwPrefix;
      i1 = (OOC_INT32)Object__StringDesc_Concat((Object__String)i1, (Object__String)i0);
      i2 = (OOC_INT32)OOC_C_Naming__keywords;
      ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i2, (Object__Object)i0, (Object__Object)i1);
      return;
      ;
    }


  i0 = (OOC_INT32)ADT_Dictionary__New();
  OOC_C_Naming__keywords = (ADT_Dictionary__Dictionary)i0;
  OOC_C_Naming__rwPrefix = (Object__String)((OOC_INT32)_c7);
  OOC_C_Naming__tdPrefix = (Object__String)((OOC_INT32)_c8);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"auto", 5);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"break", 6);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"case", 5);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"char", 5);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"const", 6);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"continue", 9);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"default", 8);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"do", 3);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"double", 7);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"else", 5);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"enum", 5);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"extern", 7);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"float", 6);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"for", 4);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"goto", 5);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"if", 3);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"int", 4);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"long", 5);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"register", 9);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"return", 7);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"short", 6);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"signed", 7);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"sizeof", 7);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"static", 7);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"struct", 7);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"switch", 7);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"typedef", 8);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"union", 6);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"unsigned", 9);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"void", 5);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"volatile", 9);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"while", 6);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"fortran", 8);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"asm", 4);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"bool", 5);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"catch", 6);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"class", 6);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"delete", 7);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"false", 6);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"friend", 7);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"inline", 7);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"new", 4);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"operator", 9);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"private", 8);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"protected", 10);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"public", 7);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"template", 9);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"true", 5);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"try", 4);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"this", 5);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"virtual", 8);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"throw", 6);
  OOC_C_Naming__Init_RW((OOC_CHAR8*)"NULL", 5);
  return;
  ;
}

void OOC_OOC_C_Naming_init(void) {
  _c0 = Object__NewLatin1Region((OOC_CHAR8*)"_td__qtd", 9, 0, 8);
  _c1 = Object__NewLatin1Char(95u);
  _c2 = Object__NewLatin1Char(100u);
  _c3 = Object__NewLatin1Region((OOC_CHAR8*)"__tag", 6, 0, 5);
  _c4 = Object__NewLatin1Region((OOC_CHAR8*)"RT0__procedure", 15, 0, 14);
  _c5 = Object__NewLatin1Region((OOC_CHAR8*)"_TBN_", 6, 0, 5);
  _c6 = Object__NewLatin1Region((OOC_CHAR8*)"_TBP_", 6, 0, 5);
  _c7 = Object__NewLatin1Char(95u);
  _c8 = Object__NewLatin1Region((OOC_CHAR8*)"_td_", 5, 0, 4);

  OOC_C_Naming__Init();
  return;
  ;
}

void OOC_OOC_C_Naming_destroy(void) {
}

/* --- */
