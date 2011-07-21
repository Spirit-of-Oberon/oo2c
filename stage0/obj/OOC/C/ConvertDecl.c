#include <OOC/C/ConvertDecl.d>
#include <__oo2c.h>
#include <setjmp.h>

OOC_C_DeclWriter__Type OOC_C_ConvertDecl__ConvertType(OOC_C_DeclWriter__Writer w, OOC_SymbolTable__Type resolvedType, OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT8 trefClass;
  OOC_SymbolTable__Type baseType;
  OOC_SymbolTable__Type srcCodeBaseType;
  OOC_C_DeclWriter__Function fct;
  OOC_SymbolTable__Item ptr;
  Object__String name;
  OOC_C_DeclWriter__Struct _struct;
  auto void OOC_C_ConvertDecl__ConvertType_ConvertParam(OOC_C_DeclWriter__Function fct, OOC_SymbolTable__VarDecl param);
  auto OOC_INT32 OOC_C_ConvertDecl__ConvertType_AddFields(OOC_C_DeclWriter__Struct _struct, OOC_SymbolTable__Type type);
    
    void OOC_C_ConvertDecl__ConvertType_ConvertParam(OOC_C_DeclWriter__Function fct, OOC_SymbolTable__VarDecl param) {
      register OOC_INT32 i0,i1,i2;
      OOC_C_DeclWriter__Declaration decl;
      auto void OOC_C_ConvertDecl__ConvertType_ConvertParam_AddArrayLength(OOC_SymbolTable__Type type, OOC_INT32 dim);
      auto void OOC_C_ConvertDecl__ConvertType_ConvertParam_AddTypeTag(OOC_SymbolTable__VarDecl param);
        
        void OOC_C_ConvertDecl__ConvertType_ConvertParam_AddArrayLength(OOC_SymbolTable__Type type, OOC_INT32 dim) {
          register OOC_INT32 i0,i1,i2,i3,i4;
          OOC_C_DeclWriter__Declaration length;

          i0 = (OOC_INT32)type;
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2688)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
          type = (OOC_SymbolTable__Type)i0;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2717)))), &_td_OOC_SymbolTable__ArrayDesc);
          if (i1) goto l3;
          i1=0u;
          goto l5;
l3:
          i1 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2742)))), &_td_OOC_SymbolTable__ArrayDesc, 2742)), 2748))+40);
          
l5:
          if (!i1) goto l7;
          i1 = (OOC_INT32)w;
          i1 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i1, 3001))+24)+(_check_index(15, 17, OOC_UINT8, 3012))*4);
          i2 = dim;
          i3 = (OOC_INT32)param;
          i3 = (OOC_INT32)OOC_C_Naming__NameOfLengthParam((OOC_SymbolTable__VarDecl)i3, i2);
          i4 = (OOC_INT32)w;
          i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 2788)))), OOC_C_DeclWriter__WriterDesc_NewDeclaration)),OOC_C_DeclWriter__WriterDesc_NewDeclaration)((OOC_C_DeclWriter__Writer)i4, (Object__String)i3, 0, 4, (OOC_C_DeclWriter__Type)i1);
          length = (OOC_C_DeclWriter__Declaration)i1;
          i3 = (OOC_INT32)fct;
          OOC_C_DeclWriter__FunctionDesc_AddParameter((OOC_C_DeclWriter__Function)i3, (OOC_C_DeclWriter__Declaration)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3112)))), &_td_OOC_SymbolTable__ArrayDesc, 3112)), 3118))+44);
          OOC_C_ConvertDecl__ConvertType_ConvertParam_AddArrayLength((OOC_SymbolTable__Type)i0, (i2+1));
l7:
          return;
          ;
        }

        
        void OOC_C_ConvertDecl__ConvertType_ConvertParam_AddTypeTag(OOC_SymbolTable__VarDecl param) {
          register OOC_INT32 i0,i1,i2;

          i0 = (OOC_INT32)type;
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3306)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
          type = (OOC_SymbolTable__Type)i0;
          i0 = (OOC_INT32)param;
          i1 = *(OOC_UINT8*)((_check_pointer(i0, 3334))+59);
          if (i1) goto l3;
          i1=0u;
          goto l5;
l3:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3355))+48);
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3362)))), &_td_OOC_SymbolTable__RecordDesc);
          
l5:
          if (!i1) goto l7;
          i1 = (OOC_INT32)w;
          i1 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i1, 3600))+24)+(_check_index(16, 17, OOC_UINT8, 3611))*4);
          i0 = (OOC_INT32)OOC_C_Naming__NameOfTypeTagParam((OOC_SymbolTable__VarDecl)i0);
          i2 = (OOC_INT32)w;
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 3400)))), OOC_C_DeclWriter__WriterDesc_NewDeclaration)),OOC_C_DeclWriter__WriterDesc_NewDeclaration)((OOC_C_DeclWriter__Writer)i2, (Object__String)i0, 0, 4, (OOC_C_DeclWriter__Type)i1);
          i1 = (OOC_INT32)fct;
          OOC_C_DeclWriter__FunctionDesc_AddParameter((OOC_C_DeclWriter__Function)i1, (OOC_C_DeclWriter__Declaration)i0);
l7:
          return;
          ;
        }


      i0 = (OOC_INT32)param;
      i1 = (OOC_INT32)w;
      i1 = (OOC_INT32)OOC_C_ConvertDecl__ConvertDecl((OOC_C_DeclWriter__Writer)i1, (OOC_SymbolTable__Declaration)i0, 3);
      decl = (OOC_C_DeclWriter__Declaration)i1;
      i2 = (OOC_INT32)fct;
      OOC_C_DeclWriter__FunctionDesc_AddParameter((OOC_C_DeclWriter__Function)i2, (OOC_C_DeclWriter__Declaration)i1);
      i1 = *(OOC_UINT8*)((_check_pointer(i0, 3828))+64);
      if (!i1) goto l4;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3879))+48);
      OOC_C_ConvertDecl__ConvertType_ConvertParam_AddArrayLength((OOC_SymbolTable__Type)i0, 0);
      i0 = (OOC_INT32)param;
      OOC_C_ConvertDecl__ConvertType_ConvertParam_AddTypeTag((OOC_SymbolTable__VarDecl)i0);
l4:
      return;
      ;
    }

    
    OOC_INT32 OOC_C_ConvertDecl__ConvertType_AddFields(OOC_C_DeclWriter__Struct _struct, OOC_SymbolTable__Type type) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_INT32 offset;
      OOC_INT32 i;

      i0 = (OOC_INT32)type;
      i1 = i0==(OOC_INT32)0;
      if (i1) goto l24;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4149)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
      type = (OOC_SymbolTable__Type)i0;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4207)))), &_td_OOC_SymbolTable__RecordDesc, 4207)), 4214))+40);
      i2 = (OOC_INT32)_struct;
      i1 = OOC_C_ConvertDecl__ConvertType_AddFields((OOC_C_DeclWriter__Struct)i2, (OOC_SymbolTable__Type)i1);
      offset = i1;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4251)))), &_td_OOC_SymbolTable__RecordDesc, 4251)), 4258))+8);
      ptr = (OOC_SymbolTable__Item)i0;
      i3 = i0!=(OOC_INT32)0;
      if (i3) goto l6_loop;
      i0=i1;
      goto l23;
l6_loop:
      i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4320)))), &_td_OOC_SymbolTable__FieldDeclDesc);
      if (i3) goto l9;
      {register OOC_INT32 h0=i0;i0=i1;i1=h0;}
      goto l18;
l9:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4370))+48);
      OOC_SymbolTable_TypeRules__AllocateType((OOC_SymbolTable__Type)i0);
      i0 = (OOC_INT32)ptr;
      i = i1;
      i0 = *(OOC_INT32*)((_check_pointer(i0, 4412))+56);
      i3 = i1<i0;
      if (!i3) goto l17;
l12_loop:
      i3 = (OOC_INT32)w;
      OOC_C_DeclWriter__StructDesc_AddPadding((OOC_C_DeclWriter__Struct)i2, (OOC_C_DeclWriter__Writer)i3, i1);
      i1 = i1+1;
      i = i1;
      i3 = i1<i0;
      if (i3) goto l12_loop;
l17:
      i0 = (OOC_INT32)ptr;
      i1 = (OOC_INT32)w;
      i0 = (OOC_INT32)OOC_C_ConvertDecl__ConvertDecl((OOC_C_DeclWriter__Writer)i1, (OOC_SymbolTable__Declaration)i0, 3);
      OOC_C_DeclWriter__StructDesc_AddMember((OOC_C_DeclWriter__Struct)i2, (OOC_C_DeclWriter__Declaration)i0);
      i0 = (OOC_INT32)ptr;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4596))+48);
      i3 = *(OOC_INT32*)((_check_pointer(i0, 4584))+56);
      i1 = *(OOC_INT32*)((_check_pointer(i1, 4602))+32);
      i1 = i3+i1;
      offset = i1;
      {register OOC_INT32 h0=i0;i0=i1;i1=h0;}
l18:
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 4710));
      ptr = (OOC_SymbolTable__Item)i1;
      i3 = i1!=(OOC_INT32)0;
      if (!i3) goto l23;
      {register OOC_INT32 h0=i0;i0=i1;i1=h0;}
      goto l6_loop;
l23:
      return i0;
      goto l25;
l24:
      return 0;
l25:
      _failed_function(3965); return 0;
      ;
    }


  i0 = (OOC_INT32)type;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l95;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5202)))), &_td_OOC_SymbolTable__PredefTypeDesc);
  if (i1) goto l77;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6224)))), &_td_OOC_SymbolTable__TypeNameDesc);
  if (i1) goto l59;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7103)))), &_td_OOC_SymbolTable__PointerDesc);
  if (i1) goto l48;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7531)))), &_td_OOC_SymbolTable__FormalParsDesc);
  if (i1) goto l35;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8443)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (i1) goto l29;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8743)))), &_td_OOC_SymbolTable__RecordDesc);
  if (i1) goto l23;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9045)))), &_td_OOC_SymbolTable__TypeVarDesc);
  if (i1) goto l21;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9124)))), &_td_OOC_SymbolTable__QualTypeDesc);
  if (i1) goto l19;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9118)))), 9118);
  goto l96;
l19:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9191))+44);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9176))+40);
  i2 = (OOC_INT32)w;
  i0 = (OOC_INT32)OOC_C_ConvertDecl__ConvertType((OOC_C_DeclWriter__Writer)i2, (OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
  return (OOC_C_DeclWriter__Type)i0;
  goto l96;
l21:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9096))+40);
  i2 = (OOC_INT32)w;
  i0 = (OOC_INT32)OOC_C_ConvertDecl__ConvertType((OOC_C_DeclWriter__Writer)i2, (OOC_SymbolTable__Type)i1, (OOC_SymbolTable__Type)i0);
  return (OOC_C_DeclWriter__Type)i0;
  goto l96;
l23:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8775))+24);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l26;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8884))+24);
  i1 = (OOC_INT32)OOC_C_Naming__NameOfDeclaration((OOC_SymbolTable__Declaration)i1);
  name = (Object__String)i1;
  
  goto l27;
l26:
  name = (Object__String)(OOC_INT32)0;
  i1=(OOC_INT32)0;
l27:
  i2 = (OOC_INT32)w;
  i3 = *(OOC_UINT8*)((_check_pointer(i0, 8948))+56);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 8931)))), OOC_C_DeclWriter__WriterDesc_NewStruct)),OOC_C_DeclWriter__WriterDesc_NewStruct)((OOC_C_DeclWriter__Writer)i2, i3, (Object__String)i1);
  _struct = (OOC_C_DeclWriter__Struct)i1;
  i0 = OOC_C_ConvertDecl__ConvertType_AddFields((OOC_C_DeclWriter__Struct)i1, (OOC_SymbolTable__Type)i0);
  i0 = (OOC_INT32)_struct;
  return (OOC_C_DeclWriter__Type)i0;
  goto l96;
l29:
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 8473))+40);
  if (i1) goto l32;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 8697))+52);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8670))+48);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8651))+44);
  i3 = (OOC_INT32)w;
  i0 = (OOC_INT32)OOC_C_ConvertDecl__ConvertType((OOC_C_DeclWriter__Writer)i3, (OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i2);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 8619)))), OOC_C_DeclWriter__WriterDesc_NewArray)),OOC_C_DeclWriter__WriterDesc_NewArray)((OOC_C_DeclWriter__Writer)i3, (OOC_C_DeclWriter__Type)i0, i1);
  return (OOC_C_DeclWriter__Type)i0;
  goto l96;
l32:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8561))+48);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8542))+44);
  i2 = (OOC_INT32)w;
  i0 = (OOC_INT32)OOC_C_ConvertDecl__ConvertType((OOC_C_DeclWriter__Writer)i2, (OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 8510)))), OOC_C_DeclWriter__WriterDesc_NewArray)),OOC_C_DeclWriter__WriterDesc_NewArray)((OOC_C_DeclWriter__Writer)i2, (OOC_C_DeclWriter__Type)i0, (-1));
  return (OOC_C_DeclWriter__Type)i0;
  goto l96;
l35:
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 7671))+56);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7632))+48);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7614))+44);
  i4 = (OOC_INT32)w;
  i2 = (OOC_INT32)OOC_C_ConvertDecl__ConvertType((OOC_C_DeclWriter__Writer)i4, (OOC_SymbolTable__Type)i3, (OOC_SymbolTable__Type)i2);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 7567)))), OOC_C_DeclWriter__WriterDesc_NewFunction)),OOC_C_DeclWriter__WriterDesc_NewFunction)((OOC_C_DeclWriter__Writer)i4, (OOC_C_DeclWriter__Type)i2, i1);
  fct = (OOC_C_DeclWriter__Function)i1;
  i2 = *(OOC_UINT8*)((_check_pointer(i0, 7721))+57);
  OOC_C_DeclWriter__FunctionDesc_SetNoReturn((OOC_C_DeclWriter__Function)i1, i2);
  i2 = *(OOC_INT8*)((_check_pointer(i0, 7761))+58);
  OOC_C_DeclWriter__FunctionDesc_SetCallConv((OOC_C_DeclWriter__Function)i1, i2);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7792))+8);
  ptr = (OOC_SymbolTable__Item)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l46;
l38_loop:
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7854)))), &_td_OOC_SymbolTable__VarDeclDesc);
  if (!i1) goto l41;
  i1 = (OOC_INT32)fct;
  OOC_C_ConvertDecl__ConvertType_ConvertParam((OOC_C_DeclWriter__Function)i1, (OOC_SymbolTable__VarDecl)i0);
l41:
  i0 = (OOC_INT32)ptr;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 8048));
  ptr = (OOC_SymbolTable__Item)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l38_loop;
l46:
  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)fct;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8383)))), OOC_C_DeclWriter__WriterDesc_NewPointer)),OOC_C_DeclWriter__WriterDesc_NewPointer)((OOC_C_DeclWriter__Writer)i0, 0, (OOC_C_DeclWriter__Type)i1);
  return (OOC_C_DeclWriter__Type)i0;
  goto l96;
l48:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7144))+40);
  baseType = (OOC_SymbolTable__Type)i1;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7187))+44);
  srcCodeBaseType = (OOC_SymbolTable__Type)i0;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7230)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (!i2) goto l57;
  i0=i1;
l52_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7289)))), &_td_OOC_SymbolTable__ArrayDesc, 7289)), 7295))+48);
  srcCodeBaseType = (OOC_SymbolTable__Type)i1;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7352)))), &_td_OOC_SymbolTable__ArrayDesc, 7352)), 7358))+44);
  baseType = (OOC_SymbolTable__Type)i0;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7230)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (i2) goto l52_loop;
l56:
  {register OOC_INT32 h0=i0;i0=i1;i1=h0;}
l57:
  i2 = (OOC_INT32)w;
  i0 = (OOC_INT32)OOC_C_ConvertDecl__ConvertType((OOC_C_DeclWriter__Writer)i2, (OOC_SymbolTable__Type)i1, (OOC_SymbolTable__Type)i0);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 7402)))), OOC_C_DeclWriter__WriterDesc_NewPointer)),OOC_C_DeclWriter__WriterDesc_NewPointer)((OOC_C_DeclWriter__Writer)i2, 0, (OOC_C_DeclWriter__Type)i0);
  return (OOC_C_DeclWriter__Type)i0;
  goto l96;
l59:
  i0 = (OOC_INT32)resolvedType;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6267)))), &_td_OOC_SymbolTable__QualTypeDesc);
  if (!i1) goto l63;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6507)))), &_td_OOC_SymbolTable__QualTypeDesc, 6507)), 6516))+40);
  resolvedType = (OOC_SymbolTable__Type)i0;
  
l63:
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6574)))), &_td_OOC_SymbolTable__PredefTypeDesc);
  if (i1) goto l74;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6678)))), &_td_OOC_SymbolTable__RecordDesc);
  if (i1) goto l68;
  i0 = (OOC_INT32)OOC_C_Naming__NameOfType((OOC_SymbolTable__Type)i0);
  i1 = (OOC_INT32)w;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6965)))), OOC_C_DeclWriter__WriterDesc_NewTypeRef)),OOC_C_DeclWriter__WriterDesc_NewTypeRef)((OOC_C_DeclWriter__Writer)i1, 0, (Object__String)i0);
  return (OOC_C_DeclWriter__Type)i0;
  goto l96;
l68:
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 6719))+56);
  if (i1) goto l71;
  trefClass = 1;
  i1=1;
  goto l72;
l71:
  trefClass = 2;
  i1=2;
l72:
  i0 = (OOC_INT32)OOC_C_Naming__NameOfType((OOC_SymbolTable__Type)i0);
  i2 = (OOC_INT32)w;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 6874)))), OOC_C_DeclWriter__WriterDesc_NewTypeRef)),OOC_C_DeclWriter__WriterDesc_NewTypeRef)((OOC_C_DeclWriter__Writer)i2, i1, (Object__String)i0);
  return (OOC_C_DeclWriter__Type)i0;
  goto l96;
l74:
  i1 = (OOC_INT32)w;
  i0 = (OOC_INT32)OOC_C_ConvertDecl__ConvertType((OOC_C_DeclWriter__Writer)i1, (OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i0);
  return (OOC_C_DeclWriter__Type)i0;
  goto l96;
l77:
  i0 = *(OOC_INT16*)((_check_pointer(i0, 5239))+40);
  switch (i0) {
  case 0:
    i0 = (OOC_INT32)w;
    i0 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i0, 5291))+24)+(_check_index(10, 17, OOC_UINT8, 5302))*4);
    return (OOC_C_DeclWriter__Type)i0;
    goto l96;
  case 1:
    i0 = (OOC_INT32)w;
    i0 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i0, 5362))+24)+(_check_index(10, 17, OOC_UINT8, 5373))*4);
    return (OOC_C_DeclWriter__Type)i0;
    goto l96;
  case 2:
    i0 = (OOC_INT32)w;
    i0 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i0, 5437))+24)+(_check_index(11, 17, OOC_UINT8, 5448))*4);
    return (OOC_C_DeclWriter__Type)i0;
    goto l96;
  case 3:
    i0 = (OOC_INT32)w;
    i0 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i0, 5513))+24)+(_check_index(12, 17, OOC_UINT8, 5524))*4);
    return (OOC_C_DeclWriter__Type)i0;
    goto l96;
  case 4:
    i0 = (OOC_INT32)w;
    i0 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i0, 5589))+24)+(_check_index(2, 17, OOC_UINT8, 5600))*4);
    return (OOC_C_DeclWriter__Type)i0;
    goto l96;
  case 5:
    i0 = (OOC_INT32)w;
    i0 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i0, 5662))+24)+(_check_index(3, 17, OOC_UINT8, 5673))*4);
    return (OOC_C_DeclWriter__Type)i0;
    goto l96;
  case 6:
    i0 = (OOC_INT32)w;
    i0 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i0, 5736))+24)+(_check_index(4, 17, OOC_UINT8, 5747))*4);
    return (OOC_C_DeclWriter__Type)i0;
    goto l96;
  case 7:
    i0 = (OOC_INT32)w;
    i0 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i0, 5810))+24)+(_check_index(5, 17, OOC_UINT8, 5821))*4);
    return (OOC_C_DeclWriter__Type)i0;
    goto l96;
  case 8:
    i0 = (OOC_INT32)w;
    i0 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i0, 5881))+24)+(_check_index(13, 17, OOC_UINT8, 5892))*4);
    return (OOC_C_DeclWriter__Type)i0;
    goto l96;
  case 9:
    i0 = (OOC_INT32)w;
    i0 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i0, 5957))+24)+(_check_index(14, 17, OOC_UINT8, 5968))*4);
    return (OOC_C_DeclWriter__Type)i0;
    goto l96;
  case 10:
    i0 = (OOC_INT32)w;
    i0 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i0, 6028))+24)+(_check_index(8, 17, OOC_UINT8, 6039))*4);
    return (OOC_C_DeclWriter__Type)i0;
    goto l96;
  case 11:
    i0 = (OOC_INT32)w;
    i0 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i0, 6101))+24)+(_check_index(10, 17, OOC_UINT8, 6112))*4);
    return (OOC_C_DeclWriter__Type)i0;
    goto l96;
  case 12:
    i0 = (OOC_INT32)w;
    i0 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i0, 6171))+24)+(_check_index(1, 17, OOC_UINT8, 6182))*4);
    return (OOC_C_DeclWriter__Type)i0;
    goto l96;
  default:
    _failed_case(i0, 5230);
    goto l96;
  }
l95:
  i0 = (OOC_INT32)w;
  i0 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i0, 5149))+24)+(_check_index(0, 17, OOC_UINT8, 5160))*4);
  return (OOC_C_DeclWriter__Type)i0;
l96:
  _failed_function(1373); return 0;
  ;
}

static OOC_C_DeclWriter__Declaration OOC_C_ConvertDecl__ConvertDecl(OOC_C_DeclWriter__Writer w, OOC_SymbolTable__Declaration item, OOC_INT8 mode) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  OOC_INT8 sc;
  OOC_C_DeclWriter__Type fpars;
  OOC_INT8 tq;
  Object__String name;
  OOC_C_DeclWriter__Type ctype;

  i0 = (OOC_INT32)item;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9571)))), &_td_OOC_SymbolTable__ProcDeclDesc);
  if (i1) goto l87;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10717)))), &_td_OOC_SymbolTable__ConstDeclDesc);
  if (i1) goto l85;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10866)))), &_td_OOC_SymbolTable__VarDeclDesc);
  if (i1) goto l15;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12981)))), &_td_OOC_SymbolTable__FieldDeclDesc);
  if (i1) goto l13;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13214)))), &_td_OOC_SymbolTable__TypeDeclDesc);
  if (i1) goto l11;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13208)))), 13208);
  goto l116;
l11:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13466))+52);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13454))+48);
  i3 = (OOC_INT32)w;
  i1 = (OOC_INT32)OOC_C_ConvertDecl__ConvertType((OOC_C_DeclWriter__Writer)i3, (OOC_SymbolTable__Type)i2, (OOC_SymbolTable__Type)i1);
  i0 = (OOC_INT32)OOC_C_Naming__NameOfDeclaration((OOC_SymbolTable__Declaration)i0);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 13246)))), OOC_C_DeclWriter__WriterDesc_NewDeclaration)),OOC_C_DeclWriter__WriterDesc_NewDeclaration)((OOC_C_DeclWriter__Writer)i3, (Object__String)i0, 0, 1, (OOC_C_DeclWriter__Type)i1);
  return (OOC_C_DeclWriter__Declaration)i0;
  goto l116;
l13:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13180))+52);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13168))+48);
  i3 = (OOC_INT32)w;
  i1 = (OOC_INT32)OOC_C_ConvertDecl__ConvertType((OOC_C_DeclWriter__Writer)i3, (OOC_SymbolTable__Type)i2, (OOC_SymbolTable__Type)i1);
  i0 = (OOC_INT32)OOC_C_Naming__NameOfDeclaration((OOC_SymbolTable__Declaration)i0);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 13014)))), OOC_C_DeclWriter__WriterDesc_NewDeclaration)),OOC_C_DeclWriter__WriterDesc_NewDeclaration)((OOC_C_DeclWriter__Writer)i3, (Object__String)i0, 0, 0, (OOC_C_DeclWriter__Type)i1);
  return (OOC_C_DeclWriter__Declaration)i0;
  goto l116;
l15:
  tq = 0;
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 10927))+56);
  if (i1) goto l30;
  i1 = mode;
  i1 = i1==0;
  if (i1) goto l28;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 11344))+28);
  i1 = i1==0;
  if (i1) goto l22;
  i1=0u;
  goto l24;
l22:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11401))+4);
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11410)))), &_td_OOC_SymbolTable__ModuleDesc);
  
l24:
  if (i1) goto l26;
  sc = 4;
  i1=4;
  goto l29;
l26:
  sc = 3;
  i1=3;
  goto l29;
l28:
  sc = 2;
  i1=2;
l29:
  i2=0;
  goto l39;
l30:
  sc = 4;
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 10996))+59);
  i1 = !i1;
  if (i1) goto l33;
  i1=0u;
  goto l35;
l33:
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 11015))+60);
  
l35:
  if (i1) goto l37;
  i1=0;
  goto l38;
l37:
  tq = 1;
  i1=1;
l38:
  i2=i1;i1=4;
l39:
  i3 = (OOC_INT32)OOC_C_Naming__NameOfDeclaration((OOC_SymbolTable__Declaration)i0);
  name = (Object__String)i3;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11631))+52);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11619))+48);
  i6 = (OOC_INT32)w;
  i4 = (OOC_INT32)OOC_C_ConvertDecl__ConvertType((OOC_C_DeclWriter__Writer)i6, (OOC_SymbolTable__Type)i5, (OOC_SymbolTable__Type)i4);
  ctype = (OOC_C_DeclWriter__Type)i4;
  i5 = mode;
  i7 = i5==3;
  if (i7) goto l42;
  i7=0u;
  goto l44;
l42:
  i7 = *(OOC_UINT8*)((_check_pointer(i0, 11691))+56);
  
l44:
  if (i7) goto l62;
  i5 = i5!=0;
  if (i5) goto l48;
  i5=0u;
  goto l50;
l48:
  i5 = *(OOC_INT8*)((_check_pointer(i0, 12520))+28);
  i5 = i5!=0;
  
l50:
  if (i5) goto l52;
  i5=0u;
  goto l54;
l52:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12585))+48);
  i5 = OOC_SymbolTable_TypeRules__IsRecord((OOC_SymbolTable__Type)i5);
  
l54:
  if (i5) goto l56;
  i0=0u;
  goto l58;
l56:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12611))+48);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12616))+24);
  i0 = i0==(OOC_INT32)0;
  
l58:
  if (i0) goto l60;
  i0=i4;
  goto l83;
l60:
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 12881)))), OOC_C_DeclWriter__WriterDesc_NewTypeOf)),OOC_C_DeclWriter__WriterDesc_NewTypeOf)((OOC_C_DeclWriter__Writer)i6, (Object__String)i3);
  ctype = (OOC_C_DeclWriter__Type)i0;
  
  goto l83;
l62:
  i5 = *(OOC_UINT8*)((_check_pointer(i0, 11726))+59);
  i5 = !i5;
  if (i5) goto l65;
  i5=0u;
  goto l67;
l65:
  i5 = *(OOC_UINT8*)((_check_pointer(i0, 11744))+60);
  
l67:
  if (i5) goto l69;
  i5=0u;
  goto l71;
l69:
  i5 = *(OOC_UINT8*)((_check_pointer(i0, 11770))+61);
  
l71:
  if (!i5) goto l74;
  i5 = (OOC_INT32)Object__NewLatin1("__ref", 6);
  i3 = (OOC_INT32)Object__StringDesc_Concat((Object__String)i3, (Object__String)i5);
  name = (Object__String)i3;
  
l74:
  i5 = *(OOC_UINT8*)((_check_pointer(i0, 12157))+60);
  if (i5) goto l77;
  i0=0u;
  goto l79;
l77:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12186))+48);
  i0 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12193)))), &_td_OOC_SymbolTable__ArrayDesc));
  
l79:
  if (i0) goto l81;
  i0=i4;
  goto l83;
l81:
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 12408)))), OOC_C_DeclWriter__WriterDesc_NewPointer)),OOC_C_DeclWriter__WriterDesc_NewPointer)((OOC_C_DeclWriter__Writer)i6, 0, (OOC_C_DeclWriter__Type)i4);
  ctype = (OOC_C_DeclWriter__Type)i0;
  
l83:
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 12931)))), OOC_C_DeclWriter__WriterDesc_NewDeclaration)),OOC_C_DeclWriter__WriterDesc_NewDeclaration)((OOC_C_DeclWriter__Writer)i6, (Object__String)i3, i2, i1, (OOC_C_DeclWriter__Type)i0);
  return (OOC_C_DeclWriter__Declaration)i0;
  goto l116;
l85:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10840))+52);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10827))+48);
  i0 = (OOC_INT32)OOC_C_Naming__NameOfDeclaration((OOC_SymbolTable__Declaration)i0);
  i3 = (OOC_INT32)w;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 10750)))), OOC_C_DeclWriter__WriterDesc_NewDefine)),OOC_C_DeclWriter__WriterDesc_NewDefine)((OOC_C_DeclWriter__Writer)i3, (Object__String)i0, (Object_Boxed__Object)i2, (OOC_SymbolTable__Type)i1);
  return (OOC_C_DeclWriter__Declaration)i0;
  goto l116;
l87:
  i1 = mode;
  switch (i1) {
  case 0:
    sc = 2;
    goto l109;
  case 1:
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9711))+4);
    i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 9720)))), &_td_OOC_SymbolTable__ProcDeclDesc);
    if (i2) goto l93;
    sc = 3;
    
    goto l109;
l93:
    sc = 6;
    
    goto l109;
  case 2:
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9922))+4);
    i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 9931)))), &_td_OOC_SymbolTable__ProcDeclDesc);
    if (i2) goto l106;
    i2 = *(OOC_INT8*)((_check_pointer(i0, 10043))+28);
    i2 = i2==0;
    if (i2) goto l100;
    i2=0u;
    goto l102;
l100:
    i2 = OOC_SymbolTable__ProcDeclDesc_IsTypeBound((OOC_SymbolTable__ProcDecl)i0);
    i2 = !i2;
    
l102:
    if (i2) goto l104;
    sc = 4;
    
    goto l109;
l104:
    sc = 3;
    
    goto l109;
l106:
    sc = 4;
    
    goto l109;
  default:
    _failed_case(i1, 9595);
    goto l109;
  }
l109:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10262))+64);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10244))+64);
  i4 = (OOC_INT32)w;
  i2 = (OOC_INT32)OOC_C_ConvertDecl__ConvertType((OOC_C_DeclWriter__Writer)i4, (OOC_SymbolTable__Type)i3, (OOC_SymbolTable__Type)i2);
  fpars = (OOC_C_DeclWriter__Type)i2;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 10309)))), &_td_OOC_C_DeclWriter__PointerDesc, 10309)), 10317))+4);
  fpars = (OOC_C_DeclWriter__Type)i2;
  i3 = *(OOC_UINT8*)((_check_pointer(i0, 10345))+76);
  if (!i3) goto l112;
  OOC_C_DeclWriter__FunctionDesc_MakeParametersVolatile((OOC_C_DeclWriter__Function)(_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 10388)))), &_td_OOC_C_DeclWriter__FunctionDesc, 10388)));
l112:
  i1 = i1!=0;
  if (!i1) goto l115;
  OOC_C_DeclWriter__FunctionDesc_SetNoReturn((OOC_C_DeclWriter__Function)(_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 10548)))), &_td_OOC_C_DeclWriter__FunctionDesc, 10548)), 0u);
l115:
  i0 = (OOC_INT32)OOC_C_Naming__NameOfDeclaration((OOC_SymbolTable__Declaration)i0);
  i1 = sc;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 10610)))), OOC_C_DeclWriter__WriterDesc_NewDeclaration)),OOC_C_DeclWriter__WriterDesc_NewDeclaration)((OOC_C_DeclWriter__Writer)i4, (Object__String)i0, 0, i1, (OOC_C_DeclWriter__Type)i2);
  return (OOC_C_DeclWriter__Declaration)i0;
l116:
  _failed_function(9258); return 0;
  ;
}

void OOC_C_ConvertDecl__ConvertSymTab(OOC_C_DeclWriter__Writer w, OOC_Repository__Module m, OOC_SymbolTable__Module symTab, ADT_Dictionary_AddressKey__Dictionary exports, OOC_CHAR8 writeExported) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_INT8 mode;
  auto void OOC_C_ConvertDecl__ConvertSymTab_ConvertTopLevel(OOC_SymbolTable__Item root, OOC_Repository__Module m, OOC_INT8 mode);
  auto void OOC_C_ConvertDecl__ConvertSymTab_ConvertNestedTypes(OOC_SymbolTable__Item topLevel, OOC_SymbolTable__Item root);
    
    void OOC_C_ConvertDecl__ConvertSymTab_ConvertTopLevel(OOC_SymbolTable__Item root, OOC_Repository__Module m, OOC_INT8 mode) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_SymbolTable__Item ptr;
      OOC_C_DeclWriter__Declaration decl;
      auto OOC_CHAR8 OOC_C_ConvertDecl__ConvertSymTab_ConvertTopLevel_ExportedVarDecl(OOC_SymbolTable__Item ptr);
      auto void OOC_C_ConvertDecl__ConvertSymTab_ConvertTopLevel_AddTypeBoundHelpers(OOC_C_DeclWriter__Writer w, OOC_SymbolTable__ProcDecl proc);
        
        OOC_CHAR8 OOC_C_ConvertDecl__ConvertSymTab_ConvertTopLevel_ExportedVarDecl(OOC_SymbolTable__Item ptr) {
          register OOC_INT32 i0,i1;

          i0 = (OOC_INT32)ptr;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14605)))), &_td_OOC_SymbolTable__VarDeclDesc);
          if (i1) goto l3;
          return 0u;
          goto l4;
l3:
          i0 = *(OOC_INT8*)((_check_pointer(i0, 14843))+28);
          return (i0!=0);
l4:
          _failed_function(14535); return 0;
          ;
        }

        
        void OOC_C_ConvertDecl__ConvertSymTab_ConvertTopLevel_AddTypeBoundHelpers(OOC_C_DeclWriter__Writer w, OOC_SymbolTable__ProcDecl proc) {
          register OOC_INT32 i0,i1,i2,i3;
          OOC_C_DeclWriter__Declaration d;

          i0 = (OOC_INT32)proc;
          i1 = *(OOC_INT32*)((_check_pointer(i0, 15201))+56);
          i1 = (OOC_INT32)Object_BigInt__NewInt(i1);
          i2 = (OOC_INT32)OOC_C_Naming__NameOfTypeBoundIndex((OOC_SymbolTable__ProcDecl)i0);
          i3 = (OOC_INT32)w;
          i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 15107)))), OOC_C_DeclWriter__WriterDesc_NewDefine)),OOC_C_DeclWriter__WriterDesc_NewDefine)((OOC_C_DeclWriter__Writer)i3, (Object__String)i2, (Object_Boxed__Object)i1, (OOC_SymbolTable__Type)(OOC_INT32)0);
          d = (OOC_C_DeclWriter__Declaration)i1;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 15232)))), OOC_C_DeclWriter__WriterDesc_AddDeclaration)),OOC_C_DeclWriter__WriterDesc_AddDeclaration)((OOC_C_DeclWriter__Writer)i3, (OOC_C_DeclWriter__Declaration)i1);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15547))+64);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15484))+64);
          i1 = (OOC_INT32)OOC_C_ConvertDecl__ConvertType((OOC_C_DeclWriter__Writer)i3, (OOC_SymbolTable__Type)i2, (OOC_SymbolTable__Type)i1);
          i0 = (OOC_INT32)OOC_C_Naming__NameOfTypeBoundSignature((OOC_SymbolTable__ProcDecl)i0);
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 15269)))), OOC_C_DeclWriter__WriterDesc_NewDeclaration)),OOC_C_DeclWriter__WriterDesc_NewDeclaration)((OOC_C_DeclWriter__Writer)i3, (Object__String)i0, 0, 1, (OOC_C_DeclWriter__Type)i1);
          d = (OOC_C_DeclWriter__Declaration)i0;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 15572)))), OOC_C_DeclWriter__WriterDesc_AddDeclaration)),OOC_C_DeclWriter__WriterDesc_AddDeclaration)((OOC_C_DeclWriter__Writer)i3, (OOC_C_DeclWriter__Declaration)i0);
          return;
          ;
        }


      i0 = (OOC_INT32)root;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15657))+8);
      ptr = (OOC_SymbolTable__Item)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l42;
l3_loop:
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15715)))), &_td_OOC_SymbolTable__DeclarationDesc);
      if (!i1) goto l37;
      i1 = (OOC_INT32)exports;
      i1 = ADT_Dictionary_AddressKey__DictionaryDesc_HasKey((ADT_Dictionary_AddressKey__Dictionary)i1, (Object__Object)i0);
      i2 = mode;
      i1 = i1==(i2==0);
      if (i1) goto l8;
      i1 = OOC_C_ConvertDecl__ConvertSymTab_ConvertTopLevel_ExportedVarDecl((OOC_SymbolTable__Item)i0);
      
      goto l10;
l8:
      i1=1u;
l10:
      if (!i1) goto l37;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15865)))), &_td_OOC_SymbolTable__ImportDesc);
      if (i1) goto l31;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16118)))), &_td_OOC_SymbolTable__ProcDeclDesc);
      if (i1) goto l16;
      i1=0u;
      goto l18;
l16:
      i1 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16145)))), &_td_OOC_SymbolTable__ProcDeclDesc, 16145)), 16154))+49);
      
l18:
      if (i1) goto l37;
      i1 = (OOC_INT32)w;
      i1 = (OOC_INT32)OOC_C_ConvertDecl__ConvertDecl((OOC_C_DeclWriter__Writer)i1, (OOC_SymbolTable__Declaration)i0, i2);
      decl = (OOC_C_DeclWriter__Declaration)i1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 16341))+8);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 16341))+8);
      i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 16347)))), Object__StringDesc_CharAt)),Object__StringDesc_CharAt)((Object__String)i3, 0);
      i2 = i2!=40u;
      if (!i2) goto l37;
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 16807)))), OOC_C_DeclWriter__WriterDesc_AddDeclaration)),OOC_C_DeclWriter__WriterDesc_AddDeclaration)((OOC_C_DeclWriter__Writer)i2, (OOC_C_DeclWriter__Declaration)i1);
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16858)))), &_td_OOC_SymbolTable__ProcDeclDesc);
      if (i1) goto l24;
      i1=0u;
      goto l26;
l24:
      i1 = OOC_SymbolTable__ProcDeclDesc_IsTypeBound((OOC_SymbolTable__ProcDecl)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16906)))), &_td_OOC_SymbolTable__ProcDeclDesc, 16906)));
      
l26:
      if (!i1) goto l37;
      i1 = (OOC_INT32)w;
      OOC_C_ConvertDecl__ConvertSymTab_ConvertTopLevel_AddTypeBoundHelpers((OOC_C_DeclWriter__Writer)i1, (OOC_SymbolTable__ProcDecl)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16987)))), &_td_OOC_SymbolTable__ProcDeclDesc, 16987)));
      goto l37;
l31:
      i1 = OOC_SymbolTable__ImportDesc_IsInternalImport((OOC_SymbolTable__Import)i0);
      i1 = !i1;
      if (!i1) goto l37;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16039))+48);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 16050))+12);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16039))+48);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16050))+12);
      i2 = (OOC_INT32)m;
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 16054)), 0);
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 16017)))), OOC_Repository__ModuleDesc_GetImportedModule)),OOC_Repository__ModuleDesc_GetImportedModule)((OOC_Repository__Module)i2, (void*)(_check_pointer(i0, 16054)), i1);
      i1 = (OOC_INT32)w;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15963)))), OOC_C_DeclWriter__WriterDesc_NewIncludeModule)),OOC_C_DeclWriter__WriterDesc_NewIncludeModule)((OOC_C_DeclWriter__Writer)i1, (OOC_Repository__Module)i0);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15945)))), OOC_C_DeclWriter__WriterDesc_AddDeclaration)),OOC_C_DeclWriter__WriterDesc_AddDeclaration)((OOC_C_DeclWriter__Writer)i1, (OOC_C_DeclWriter__Declaration)i0);
l37:
      i0 = (OOC_INT32)ptr;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 17197));
      ptr = (OOC_SymbolTable__Item)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l3_loop;
l42:
      return;
      ;
    }

    
    void OOC_C_ConvertDecl__ConvertSymTab_ConvertNestedTypes(OOC_SymbolTable__Item topLevel, OOC_SymbolTable__Item root) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      OOC_SymbolTable__Item ptr;
      OOC_C_DeclWriter__Declaration decl;

      i0 = (OOC_INT32)root;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17592))+8);
      ptr = (OOC_SymbolTable__Item)i1;
      i2 = i1!=(OOC_INT32)0;
      if (!i2) goto l17;
      i2 = (OOC_INT32)topLevel;
      i0 = i0!=i2;
      
l3_loop:
      i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17650)))), &_td_OOC_SymbolTable__ProcDeclDesc);
      if (i3) goto l11;
      i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17727)))), &_td_OOC_SymbolTable__TypeDeclDesc);
      if (!i3) goto l12;
      if (!i0) goto l12;
      i3 = mode;
      i4 = (OOC_INT32)w;
      i3 = (OOC_INT32)OOC_C_ConvertDecl__ConvertDecl((OOC_C_DeclWriter__Writer)i4, (OOC_SymbolTable__Declaration)i1, i3);
      decl = (OOC_C_DeclWriter__Declaration)i3;
      i4 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 17842)))), OOC_C_DeclWriter__WriterDesc_AddDeclaration)),OOC_C_DeclWriter__WriterDesc_AddDeclaration)((OOC_C_DeclWriter__Writer)i4, (OOC_C_DeclWriter__Declaration)i3);
      goto l12;
l11:
      OOC_C_ConvertDecl__ConvertSymTab_ConvertNestedTypes((OOC_SymbolTable__Item)i2, (OOC_SymbolTable__Item)i1);
l12:
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 17983));
      ptr = (OOC_SymbolTable__Item)i1;
      i3 = i1!=(OOC_INT32)0;
      if (i3) goto l3_loop;
l17:
      return;
      ;
    }


  i0 = writeExported;
  if (i0) goto l3;
  mode = 1;
  i0=1;
  goto l4;
l3:
  mode = 0;
  i0=0;
l4:
  i1 = (OOC_INT32)symTab;
  i2 = (OOC_INT32)m;
  OOC_C_ConvertDecl__ConvertSymTab_ConvertTopLevel((OOC_SymbolTable__Item)i1, (OOC_Repository__Module)i2, i0);
  i0 = writeExported;
  if (i0) goto l7;
  i0 = (OOC_INT32)symTab;
  OOC_C_ConvertDecl__ConvertSymTab_ConvertNestedTypes((OOC_SymbolTable__Item)i0, (OOC_SymbolTable__Item)i0);
  goto l8;
l7:
  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i0, 18418))+24)+(_check_index(0, 17, OOC_UINT8, 18429))*4);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18402)))), OOC_C_DeclWriter__WriterDesc_NewFunction)),OOC_C_DeclWriter__WriterDesc_NewFunction)((OOC_C_DeclWriter__Writer)i0, (OOC_C_DeclWriter__Type)i1, 0u);
  i2 = (OOC_INT32)symTab;
  i3 = (OOC_INT32)OOC_C_Naming__NameOfModuleInit((OOC_SymbolTable__Module)i2, 0u);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18254)))), OOC_C_DeclWriter__WriterDesc_NewDeclaration)),OOC_C_DeclWriter__WriterDesc_NewDeclaration)((OOC_C_DeclWriter__Writer)i0, (Object__String)i3, 0, 2, (OOC_C_DeclWriter__Type)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18225)))), OOC_C_DeclWriter__WriterDesc_AddDeclaration)),OOC_C_DeclWriter__WriterDesc_AddDeclaration)((OOC_C_DeclWriter__Writer)i0, (OOC_C_DeclWriter__Declaration)i1);
  i1 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i0, 18657))+24)+(_check_index(0, 17, OOC_UINT8, 18668))*4);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18641)))), OOC_C_DeclWriter__WriterDesc_NewFunction)),OOC_C_DeclWriter__WriterDesc_NewFunction)((OOC_C_DeclWriter__Writer)i0, (OOC_C_DeclWriter__Type)i1, 0u);
  i2 = (OOC_INT32)OOC_C_Naming__NameOfModuleInit((OOC_SymbolTable__Module)i2, 1u);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18494)))), OOC_C_DeclWriter__WriterDesc_NewDeclaration)),OOC_C_DeclWriter__WriterDesc_NewDeclaration)((OOC_C_DeclWriter__Writer)i0, (Object__String)i2, 0, 2, (OOC_C_DeclWriter__Type)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18465)))), OOC_C_DeclWriter__WriterDesc_AddDeclaration)),OOC_C_DeclWriter__WriterDesc_AddDeclaration)((OOC_C_DeclWriter__Writer)i0, (OOC_C_DeclWriter__Declaration)i1);
l8:
  return;
  ;
}

OOC_C_DeclWriter__Declaration OOC_C_ConvertDecl__GetProc(OOC_C_DeclWriter__Writer w, OOC_SymbolTable__ProcDecl procDecl, OOC_CHAR8 nestedPrototype) {
  register OOC_INT32 i0,i1;

  i0 = nestedPrototype;
  if (i0) goto l3;
  i0 = (OOC_INT32)procDecl;
  i1 = (OOC_INT32)w;
  i0 = (OOC_INT32)OOC_C_ConvertDecl__ConvertDecl((OOC_C_DeclWriter__Writer)i1, (OOC_SymbolTable__Declaration)i0, 2);
  return (OOC_C_DeclWriter__Declaration)i0;
  goto l4;
l3:
  i0 = (OOC_INT32)procDecl;
  i1 = (OOC_INT32)w;
  i0 = (OOC_INT32)OOC_C_ConvertDecl__ConvertDecl((OOC_C_DeclWriter__Writer)i1, (OOC_SymbolTable__Declaration)i0, 1);
  return (OOC_C_DeclWriter__Declaration)i0;
l4:
  _failed_function(18790); return 0;
  ;
}

OOC_C_DeclWriter__Declaration OOC_C_ConvertDecl__GetDecl(OOC_C_DeclWriter__Writer w, OOC_SymbolTable__Declaration decl) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)decl;
  i1 = (OOC_INT32)w;
  i0 = (OOC_INT32)OOC_C_ConvertDecl__ConvertDecl((OOC_C_DeclWriter__Writer)i1, (OOC_SymbolTable__Declaration)i0, 2);
  return (OOC_C_DeclWriter__Declaration)i0;
  ;
}

OOC_C_DeclWriter__Type OOC_C_ConvertDecl__GetTypeRef(OOC_C_DeclWriter__Writer w, OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19725))+24);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19754)))), &_td_OOC_SymbolTable__PredefTypeDesc));
  
l5:
  if (i1) goto l7;
  i1 = (OOC_INT32)w;
  i0 = (OOC_INT32)OOC_C_ConvertDecl__ConvertType((OOC_C_DeclWriter__Writer)i1, (OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i0);
  return (OOC_C_DeclWriter__Type)i0;
  goto l8;
l7:
  i0 = (OOC_INT32)OOC_C_Naming__NameOfType((OOC_SymbolTable__Type)i0);
  i1 = (OOC_INT32)w;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 19792)))), OOC_C_DeclWriter__WriterDesc_NewTypeRef)),OOC_C_DeclWriter__WriterDesc_NewTypeRef)((OOC_C_DeclWriter__Writer)i1, 0, (Object__String)i0);
  return (OOC_C_DeclWriter__Type)i0;
l8:
  _failed_function(19548); return 0;
  ;
}

OOC_C_DeclWriter__Declaration OOC_C_ConvertDecl__GetPointerDecl(OOC_C_DeclWriter__Writer w, OOC_SymbolTable__VarDecl paramDecl) {
  register OOC_INT32 i0,i1,i2;
  OOC_SymbolTable__Type elemType;

  i0 = (OOC_INT32)paramDecl;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20332))+48);
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 20339)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (i1) goto l3;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20465))+48);
  elemType = (OOC_SymbolTable__Type)i1;
  
  goto l4;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20385))+48);
  i1 = (OOC_INT32)OOC_SymbolTable__ArrayDesc_GetNonOpenElementType((OOC_SymbolTable__Array)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 20396)))), &_td_OOC_SymbolTable__ArrayDesc, 20396)));
  elemType = (OOC_SymbolTable__Type)i1;
  
l4:
  i2 = (OOC_INT32)w;
  i1 = (OOC_INT32)OOC_C_ConvertDecl__GetTypeRef((OOC_C_DeclWriter__Writer)i2, (OOC_SymbolTable__Type)i1);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 20629)))), OOC_C_DeclWriter__WriterDesc_NewPointer)),OOC_C_DeclWriter__WriterDesc_NewPointer)((OOC_C_DeclWriter__Writer)i2, 0, (OOC_C_DeclWriter__Type)i1);
  i0 = (OOC_INT32)OOC_C_Naming__NameOfDeclaration((OOC_SymbolTable__Declaration)i0);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 20499)))), OOC_C_DeclWriter__WriterDesc_NewDeclaration)),OOC_C_DeclWriter__WriterDesc_NewDeclaration)((OOC_C_DeclWriter__Writer)i2, (Object__String)i0, 0, 4, (OOC_C_DeclWriter__Type)i1);
  return (OOC_C_DeclWriter__Declaration)i0;
  ;
}

void OOC_OOC_C_ConvertDecl_init(void) {

  return;
  ;
}

/* --- */
