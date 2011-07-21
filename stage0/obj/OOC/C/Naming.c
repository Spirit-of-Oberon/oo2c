#include <OOC/C/Naming.d>
#include <__oo2c.h>
#include <setjmp.h>

void OOC_C_Naming__QualTypeDescrDesc_INIT(OOC_C_Naming__QualTypeDescr qtd, OOC_INT32 id, OOC_SymbolTable__TypeClosure type) {
  register OOC_INT32 i0,i1;
  OOC_CHAR8 str[16];

  i0 = id;
  IntStr__IntToStr(i0, (void*)(OOC_INT32)str, 16);
  i0 = (OOC_INT32)qtd;
  i1 = (OOC_INT32)Object__NewLatin1((void*)(OOC_INT32)str, 16);
  *(OOC_INT32*)(_check_pointer(i0, 1668)) = ((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c0),(void*)i1));
  i1 = (OOC_INT32)type;
  *(OOC_INT32*)((_check_pointer(i0, 1718))+4) = i1;
  return;
  ;
}

void OOC_C_Naming__QualTypeDataDesc_INIT(OOC_C_Naming__QualTypeData qtdData) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)qtdData;
  i1 = (OOC_INT32)RT0__NewObject(_td__qtd1.baseTypes[0]);
  ADT_ArrayList__ArrayListDesc_INIT((ADT_ArrayList__ArrayList)i1, 8);
  *(OOC_INT32*)(_check_pointer(i0, 1808)) = i1;
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

      i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT8, 2320)));
      i0 = i0==105u;
      if (i0) goto l3;
      i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT8, 2338)));
      i0 = i0==119u;
      
      goto l5;
l3:
      i0=1u;
l5:
      if (i0) goto l7;
      i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT8, 2356)));
      i0 = i0==108u;
      
      goto l9;
l7:
      i0=1u;
l9:
      if (i0) goto l11;
      i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT8, 2383)));
      i0 = i0==102u;
      
      goto l13;
l11:
      i0=1u;
l13:
      if (i0) goto l15;
      i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT8, 2401)));
      i0 = i0==100u;
      
      goto l17;
l15:
      i0=1u;
l17:
      if (i0) goto l19;
      return 0u;
      goto l41;
l19:
      i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(1, str_0d, OOC_UINT32, 2458)));
      i0 = (OOC_UINT8)48u<=(OOC_UINT8)i0;
      if (i0) goto l22;
      i0=0u;
      goto l24;
l22:
      i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(1, str_0d, OOC_UINT32, 2469)));
      i0 = (OOC_UINT8)i0<=(OOC_UINT8)57u;
      
l24:
      if (i0) goto l26;
      i0=1;
      goto l36;
l26:
      i0=1;
l27_loop:
      i0 = i0+1;
      i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 2458)));
      i1 = (OOC_UINT8)48u<=(OOC_UINT8)i1;
      if (i1) goto l30;
      i1=0u;
      goto l32;
l30:
      i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 2469)));
      i1 = (OOC_UINT8)i1<=(OOC_UINT8)57u;
      
l32:
      if (i1) goto l27_loop;
l36:
      i1 = i0>1;
      if (i1) goto l39;
      i0=0u;
      goto l40;
l39:
      i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 2544)));
      i0 = i0==0u;
      
l40:
      return i0;
l41:
      _failed_function(2126); return 0;
      ;
    }

    
    OOC_CHAR8 OOC_C_Naming__NameOfDeclaration_IsInterfaceModule(OOC_SymbolTable__Module module) {
      register OOC_INT32 i0;

      i0 = (OOC_INT32)module;
      i0 = *(OOC_INT8*)((_check_pointer(i0, 2715))+52);
      return (i0==3);
      ;
    }


  relativeName = 0u;
  i0 = (OOC_INT32)decl;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2826)))), &_td_OOC_SymbolTable__VarDeclDesc);
  if (i1) goto l3;
  i1=0u;
  goto l13;
l3:
  i1 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2861)))), &_td_OOC_SymbolTable__VarDeclDesc, 2861)), 2869))+56);
  if (i1) goto l6;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2900))+4);
  i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2909)))), &_td_OOC_SymbolTable__ModuleDesc));
  
  goto l8;
l6:
  i1=1u;
l8:
  if (i1) goto l10;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2958)))), OOC_SymbolTable__ItemDesc_Module)),OOC_SymbolTable__ItemDesc_Module)((OOC_SymbolTable__Item)i0);
  i1 = OOC_C_Naming__NameOfDeclaration_IsInterfaceModule((OOC_SymbolTable__Module)i1);
  
  goto l13;
l10:
  i1=1u;
l13:
  if (i1) goto l35;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3169)))), &_td_OOC_SymbolTable__FieldDeclDesc);
  if (i1) goto l33;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3432)))), &_td_OOC_SymbolTable__ProcDeclDesc);
  if (i1) goto l19;
  i1=0u;
  goto l21;
l19:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3461)))), &_td_OOC_SymbolTable__ProcDeclDesc, 3461)), 3470))+68);
  i1 = i1!=(OOC_INT32)0;
  
l21:
  if (i1) goto l31;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3706)))), &_td_OOC_SymbolTable__ProcDeclDesc);
  if (i1) goto l25;
  i1=0u;
  goto l27;
l25:
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3748)))), OOC_SymbolTable__ItemDesc_Module)),OOC_SymbolTable__ItemDesc_Module)((OOC_SymbolTable__Item)i0);
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
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3662)))), &_td_OOC_SymbolTable__ProcDeclDesc, 3662)), 3671))+68);
  return (Object__String)i1;
  i1=0u;
  goto l37;
l33:
  i1 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3384)))), &_td_OOC_SymbolTable__FieldDeclDesc, 3384)), 3394))+60);
  i1 = !i1;
  relativeName = i1;
  
  goto l37;
l35:
  relativeName = 1u;
  i1=1u;
l37:
  if (i1) goto l71;
  m = (OOC_SymbolTable__Item)i0;
  i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4055)))), &_td_OOC_SymbolTable__ModuleDesc));
  if (i1) goto l41;
  i1=i0;
  goto l47;
l41:
  i1=i0;
l42_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4087))+4);
  m = (OOC_SymbolTable__Item)i1;
  i2 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4055)))), &_td_OOC_SymbolTable__ModuleDesc));
  if (i2) goto l42_loop;
l47:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4125)))), &_td_OOC_SymbolTable__ModuleDesc, 4125)), 4132))+20);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4138))+12);
  _copy_8((const void*)(_check_pointer(i1, 4143)),(void*)(OOC_INT32)str,2048);
  i = 0;
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, 2048, OOC_UINT32, 4182)));
  i1 = i1!=0u;
  if (i1) goto l50;
  i1=0;
  goto l59;
l50:
  i1=0;
l51_loop:
  i2 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i1, 2048, OOC_UINT32, 4210)));
  i2 = i2==58u;
  if (!i2) goto l54;
  *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i1, 2048, OOC_UINT32, 4229))) = 95u;
l54:
  i1 = i1+1;
  i = i1;
  i2 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i1, 2048, OOC_UINT32, 4182)));
  i2 = i2!=0u;
  if (i2) goto l51_loop;
l59:
  Strings__Append("__", 3, (void*)(OOC_INT32)str, 2048);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4452)))), OOC_SymbolTable__DeclarationDesc_GetId)),OOC_SymbolTable__DeclarationDesc_GetId)((OOC_SymbolTable__Declaration)i0);
  relativeId = (OOC_Scanner_InputBuffer__CharArray)i0;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i0, 4495)), 0);
  Strings__Append((void*)(_check_pointer(i0, 4495)), i2, (void*)(OOC_INT32)str, 2048);
  i0 = i1+2;
  i = i0;
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, 2048, OOC_UINT32, 4538)));
  i1 = i1!=0u;
  if (!i1) goto l72;
l62_loop:
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, 2048, OOC_UINT32, 4566)));
  i1 = i1==46u;
  if (!i1) goto l65;
  *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, 2048, OOC_UINT32, 4585))) = 95u;
l65:
  i0 = i0+1;
  i = i0;
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, 2048, OOC_UINT32, 4538)));
  i1 = i1!=0u;
  if (i1) goto l62_loop;
  goto l72;
l71:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3946))+20);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3952))+12);
  _copy_8((const void*)(_check_pointer(i0, 3957)),(void*)(OOC_INT32)str,2048);
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
  return (Object__String)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4760)))), &_td_Object__StringDesc, 4760));
l80:
  _failed_function(1884); return 0;
  ;
}

Object__String OOC_C_Naming__NameOfModuleInit(OOC_SymbolTable__Module m, OOC_CHAR8 rtWrapper) {
  register OOC_INT32 i0,i1;
  OOC_C_Naming__Buffer str;

  i0 = (OOC_INT32)m;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5061))+20);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5067))+12);
  _copy_8((const void*)(_check_pointer(i0, 5072)),(void*)(OOC_INT32)str,2048);
  i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, 2048, OOC_UINT32, 5107)));
  i0 = i0!=0u;
  if (!i0) goto l11;
  i0=0;
l3_loop:
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, 2048, OOC_UINT32, 5133)));
  i1 = i1==58u;
  if (!i1) goto l6;
  *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, 2048, OOC_UINT32, 5152))) = 95u;
l6:
  i0 = i0+1;
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, 2048, OOC_UINT32, 5107)));
  i1 = i1!=0u;
  if (i1) goto l3_loop;
l11:
  Strings__Insert("OOC_", 5, 0, (void*)(OOC_INT32)str, 2048);
  i0 = rtWrapper;
  if (i0) goto l14;
  Strings__Append("_init", 6, (void*)(OOC_INT32)str, 2048);
  goto l15;
l14:
  Strings__Append("_init0", 7, (void*)(OOC_INT32)str, 2048);
l15:
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
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5918)))), &_td_OOC_SymbolTable__TypeVarDesc);
  if (i1) goto l20;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5998))+24);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l5;
  i1=0u;
  goto l7;
l5:
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6025)))), &_td_OOC_SymbolTable__QualTypeDesc);
  
l7:
  if (!i1) goto l19;
l10_loop:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6122)))), &_td_OOC_SymbolTable__QualTypeDesc, 6122)), 6131))+40);
  type = (OOC_SymbolTable__Type)i0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5998))+24);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l13;
  i1=0u;
  goto l15;
l13:
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6025)))), &_td_OOC_SymbolTable__QualTypeDesc);
  
l15:
  if (i1) goto l10_loop;
l19:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6171))+24);
  _assert((i1!=(OOC_INT32)0), 127, 6159);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6228))+24);
  i0 = (OOC_INT32)OOC_C_Naming__NameOfDeclaration((OOC_SymbolTable__Declaration)i0);
  return (Object__String)i0;
  goto l21;
l20:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5963))+40);
  i0 = (OOC_INT32)OOC_C_Naming__NameOfType((OOC_SymbolTable__Type)i0);
  return (Object__String)i0;
l21:
  _failed_function(5795); return 0;
  ;
}

Object__String OOC_C_Naming__NameOfTypeDescriptor(OOC_SymbolTable__Type type, OOC_C_Naming__QualTypeData qtdData) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_SymbolTable__Type base;
  OOC_INT32 i;
  Object__String dummy;
  OOC_C_Naming__QualTypeDescr qtd;
  OOC_CHAR8 str[32];
  OOC_CHAR8 str2[32];
  Object__String string;

  i0 = (OOC_INT32)type;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6608)))), &_td_OOC_SymbolTable__QualTypeDesc);
  if (i1) goto l65;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6705)))), &_td_OOC_SymbolTable__TypeClosureDesc);
  if (i1) goto l32;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7877)))), &_td_OOC_SymbolTable__FormalParsDesc);
  if (i1) goto l30;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7957)))), &_td_OOC_SymbolTable__PredefTypeDesc);
  if (i1) goto l13;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8669))+24);
  i1 = i1==0;
  if (i1) goto l11;
  i0 = (OOC_INT32)OOC_C_Naming__NameOfType((OOC_SymbolTable__Type)i0);
  i1 = (OOC_INT32)OOC_C_Naming__tdPrefix;
  i0 = (OOC_INT32)Object__StringDesc_Concat((Object__String)i1, (Object__String)i0);
  return (Object__String)i0;
  goto l66;
l11:
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8753)))), OOC_SymbolTable__ItemDesc_Module)),OOC_SymbolTable__ItemDesc_Module)((OOC_SymbolTable__Item)i0);
  i1 = (OOC_INT32)OOC_C_Naming__NameOfDeclaration((OOC_SymbolTable__Declaration)i1);
  i2 = (OOC_INT32)OOC_C_Naming__tdPrefix;
  i1 = (OOC_INT32)Object__StringDesc_Concat((Object__String)i2, (Object__String)i1);
  string = (Object__String)i1;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8796))+20);
  i0 = *(OOC_INT32*)(_check_pointer(i0, 8806));
  IntStr__IntToStr(i0, (void*)(OOC_INT32)str, 32);
  i0 = (OOC_INT32)Object__NewLatin1((void*)(OOC_INT32)str, 32);
  i0 = (OOC_INT32)Object__StringDesc_Concat((Object__String)i1, (Object__String)i0);
  return (Object__String)i0;
  goto l66;
l13:
  i0 = *(OOC_INT16*)((_check_pointer(i0, 7992))+40);
  switch (i0) {
  case 0:
    _copy_8((const void*)"boolean",(void*)(OOC_INT32)str,32);
    goto l28;
  case 1:
    _copy_8((const void*)"char",(void*)(OOC_INT32)str,32);
    goto l28;
  case 2:
    _copy_8((const void*)"longchar",(void*)(OOC_INT32)str,32);
    goto l28;
  case 3:
    _copy_8((const void*)"ucs4char",(void*)(OOC_INT32)str,32);
    goto l28;
  case 4:
    _copy_8((const void*)"shortint",(void*)(OOC_INT32)str,32);
    goto l28;
  case 5:
    _copy_8((const void*)"integer",(void*)(OOC_INT32)str,32);
    goto l28;
  case 6:
    _copy_8((const void*)"longint",(void*)(OOC_INT32)str,32);
    goto l28;
  case 8:
    _copy_8((const void*)"real",(void*)(OOC_INT32)str,32);
    goto l28;
  case 9:
    _copy_8((const void*)"longreal",(void*)(OOC_INT32)str,32);
    goto l28;
  case 10:
    _copy_8((const void*)"set32",(void*)(OOC_INT32)str,32);
    goto l28;
  case 11:
    _copy_8((const void*)"byte",(void*)(OOC_INT32)str,32);
    goto l28;
  case 12:
    _copy_8((const void*)"ptr",(void*)(OOC_INT32)str,32);
    goto l28;
  default:
    _failed_case(i0, 7983);
    goto l28;
  }
l28:
  _copy_8((const void*)"RT0",(void*)(OOC_INT32)str2,32);
  Strings__Append("__", 3, (void*)(OOC_INT32)str2, 32);
  Strings__Append((void*)(OOC_INT32)str, 32, (void*)(OOC_INT32)str2, 32);
  i0 = (OOC_INT32)Object__NewLatin1((void*)(OOC_INT32)str2, 32);
  return (Object__String)i0;
  goto l66;
l30:
  return (Object__String)((OOC_INT32)_c4);
  goto l66;
l32:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6744))+40);
  base = (OOC_SymbolTable__Type)i1;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6922)))), &_td_OOC_SymbolTable__PointerDesc);
  if (i2) goto l38;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7062)))), &_td_OOC_SymbolTable__RecordDesc);
  if (i2) goto l42;
  i2 = (OOC_INT32)qtdData;
  i2 = (OOC_INT32)OOC_C_Naming__NameOfTypeDescriptor((OOC_SymbolTable__Type)i1, (OOC_C_Naming__QualTypeData)i2);
  return (Object__String)i2;
  goto l42;
l38:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6967))+40);
  i2 = OOC_SymbolTable_TypeRules__IsRecord((OOC_SymbolTable__Type)i2);
  i2 = !i2;
  if (!i2) goto l42;
  i2 = (OOC_INT32)qtdData;
  i2 = (OOC_INT32)OOC_C_Naming__NameOfTypeDescriptor((OOC_SymbolTable__Type)i1, (OOC_C_Naming__QualTypeData)i2);
  return (Object__String)i2;
l42:
  i2 = (OOC_INT32)qtdData;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 7213));
  i = 0;
  i3 = *(OOC_INT32*)((_check_pointer(i3, 7218))+4);
  i4 = 0<i3;
  if (!i4) goto l53;
  i4=0;
l45_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 7265));
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 7270));
  i5 = _check_pointer(i5, 7276);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 7276))*4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 7279))+4);
  i5 = OOC_SymbolTable_TypeRules__SameType((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i5);
  if (!i5) goto l48;
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 7315));
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 7320));
  i5 = _check_pointer(i5, 7326);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 7326))*4);
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 7329));
  return (Object__String)i5;
l48:
  i4 = i4+1;
  i = i4;
  i5 = i4<i3;
  if (i5) goto l45_loop;
l53:
  i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7385)))), &_td_OOC_SymbolTable__PointerDesc);
  if (i3) goto l62;
  i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7488)))), &_td_OOC_SymbolTable__RecordDesc);
  if (!i3) goto l63;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 7520))+40);
  i1 = i1!=0;
  if (!i1) goto l63;
  i1 = (OOC_INT32)OOC_SymbolTable_TypeRules__RecordBaseType((OOC_SymbolTable__Type)i0);
  i1 = (OOC_INT32)OOC_C_Naming__NameOfTypeDescriptor((OOC_SymbolTable__Type)i1, (OOC_C_Naming__QualTypeData)i2);
  dummy = (Object__String)i1;
  goto l63;
l62:
  i1 = (OOC_INT32)OOC_SymbolTable_TypeRules__PointerBaseType((OOC_SymbolTable__Type)i0);
  i1 = (OOC_INT32)OOC_C_Naming__NameOfTypeDescriptor((OOC_SymbolTable__Type)i1, (OOC_C_Naming__QualTypeData)i2);
  dummy = (Object__String)i1;
l63:
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_C_Naming__QualTypeDescr.baseTypes[0]);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 7792));
  i3 = *(OOC_INT32*)((_check_pointer(i3, 7797))+4);
  OOC_C_Naming__QualTypeDescrDesc_INIT((OOC_C_Naming__QualTypeDescr)i1, i3, (OOC_SymbolTable__TypeClosure)i0);
  qtd = (OOC_C_Naming__QualTypeDescr)i1;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 7824));
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 7824));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7829)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i2, (Object__Object)i1);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 7859));
  return (Object__String)i0;
  goto l66;
l65:
  i0 = (OOC_INT32)OOC_SymbolTable__Expand((OOC_SymbolTable__Type)i0);
  i1 = (OOC_INT32)qtdData;
  i0 = (OOC_INT32)OOC_C_Naming__NameOfTypeDescriptor((OOC_SymbolTable__Type)i0, (OOC_C_Naming__QualTypeData)i1);
  return (Object__String)i0;
l66:
  _failed_function(6281); return 0;
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
  OOC_C_Naming__Init_RW("auto", 5);
  OOC_C_Naming__Init_RW("break", 6);
  OOC_C_Naming__Init_RW("case", 5);
  OOC_C_Naming__Init_RW("char", 5);
  OOC_C_Naming__Init_RW("const", 6);
  OOC_C_Naming__Init_RW("continue", 9);
  OOC_C_Naming__Init_RW("default", 8);
  OOC_C_Naming__Init_RW("do", 3);
  OOC_C_Naming__Init_RW("double", 7);
  OOC_C_Naming__Init_RW("else", 5);
  OOC_C_Naming__Init_RW("enum", 5);
  OOC_C_Naming__Init_RW("extern", 7);
  OOC_C_Naming__Init_RW("float", 6);
  OOC_C_Naming__Init_RW("for", 4);
  OOC_C_Naming__Init_RW("goto", 5);
  OOC_C_Naming__Init_RW("if", 3);
  OOC_C_Naming__Init_RW("int", 4);
  OOC_C_Naming__Init_RW("long", 5);
  OOC_C_Naming__Init_RW("register", 9);
  OOC_C_Naming__Init_RW("return", 7);
  OOC_C_Naming__Init_RW("short", 6);
  OOC_C_Naming__Init_RW("signed", 7);
  OOC_C_Naming__Init_RW("sizeof", 7);
  OOC_C_Naming__Init_RW("static", 7);
  OOC_C_Naming__Init_RW("struct", 7);
  OOC_C_Naming__Init_RW("switch", 7);
  OOC_C_Naming__Init_RW("typedef", 8);
  OOC_C_Naming__Init_RW("union", 6);
  OOC_C_Naming__Init_RW("unsigned", 9);
  OOC_C_Naming__Init_RW("void", 5);
  OOC_C_Naming__Init_RW("volatile", 9);
  OOC_C_Naming__Init_RW("while", 6);
  OOC_C_Naming__Init_RW("fortran", 8);
  OOC_C_Naming__Init_RW("asm", 4);
  OOC_C_Naming__Init_RW("bool", 5);
  OOC_C_Naming__Init_RW("catch", 6);
  OOC_C_Naming__Init_RW("class", 6);
  OOC_C_Naming__Init_RW("delete", 7);
  OOC_C_Naming__Init_RW("false", 6);
  OOC_C_Naming__Init_RW("friend", 7);
  OOC_C_Naming__Init_RW("inline", 7);
  OOC_C_Naming__Init_RW("new", 4);
  OOC_C_Naming__Init_RW("operator", 9);
  OOC_C_Naming__Init_RW("private", 8);
  OOC_C_Naming__Init_RW("protected", 10);
  OOC_C_Naming__Init_RW("public", 7);
  OOC_C_Naming__Init_RW("template", 9);
  OOC_C_Naming__Init_RW("true", 5);
  OOC_C_Naming__Init_RW("try", 4);
  OOC_C_Naming__Init_RW("this", 5);
  OOC_C_Naming__Init_RW("virtual", 8);
  OOC_C_Naming__Init_RW("throw", 6);
  OOC_C_Naming__Init_RW("NULL", 5);
  return;
  ;
}

void OOC_OOC_C_Naming_init(void) {
  _c0 = Object__NewLatin1Region("_td__qtd", 9, 0, 8);
  _c1 = Object__NewLatin1Char(95u);
  _c2 = Object__NewLatin1Char(100u);
  _c3 = Object__NewLatin1Region("__tag", 6, 0, 5);
  _c4 = Object__NewLatin1Region("RT0__procedure", 15, 0, 14);
  _c5 = Object__NewLatin1Region("_TBN_", 6, 0, 5);
  _c6 = Object__NewLatin1Region("_TBP_", 6, 0, 5);
  _c7 = Object__NewLatin1Char(95u);
  _c8 = Object__NewLatin1Region("_td_", 5, 0, 4);

  OOC_C_Naming__Init();
  return;
  ;
}

/* --- */
