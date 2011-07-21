#include <OOC/SSA/Aliasing.d>
#include <__oo2c.h>
#include <setjmp.h>

OOC_INT8 OOC_SSA_Aliasing__DesignatorAlias(OOC_SSA__Opnd instr, OOC_SSA__Opnd reference) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_SymbolTable__Type typeInstr;
  OOC_SymbolTable__Type typeRef;
  auto OOC_SSA__Opnd OOC_SSA_Aliasing__DesignatorAlias_NextPart(OOC_SSA__Opnd opnd);
  auto OOC_CHAR8 OOC_SSA_Aliasing__DesignatorAlias_IsVariable(OOC_SSA__Opnd opnd);
  auto OOC_CHAR8 OOC_SSA_Aliasing__DesignatorAlias_IsVarParam(OOC_SSA__Opnd opnd);
  auto OOC_CHAR8 OOC_SSA_Aliasing__DesignatorAlias_IsHeapObject(OOC_SSA__Opnd opnd);
  auto OOC_CHAR8 OOC_SSA_Aliasing__DesignatorAlias_CompatiblePointers(OOC_SymbolTable__Type a, OOC_SymbolTable__Type b);
  auto OOC_INT8 OOC_SSA_Aliasing__DesignatorAlias_CheckSelectors(OOC_SSA__Opnd selInstr, OOC_SSA__Opnd selReference, OOC_INT8 prefixClass);
  auto OOC_CHAR8 OOC_SSA_Aliasing__DesignatorAlias_NotHigherLevel(OOC_SymbolTable__Declaration varParam, OOC_SymbolTable__Declaration variable);
    
    OOC_SSA__Opnd OOC_SSA_Aliasing__DesignatorAlias_NextPart(OOC_SSA__Opnd opnd) {
      register OOC_INT32 i0,i1,i2;

      i0 = (OOC_INT32)opnd;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4978));
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4984)))), &_td_OOC_SSA__TypeRefDesc);
      if (!i1) goto l4;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5025))+8);
      opnd = (OOC_SSA__Opnd)i0;
      
l4:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5100))+8);
      i1 = i1==0;
      if (i1) goto l7;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5126))+8);
      i1 = *(OOC_INT8*)((_check_pointer(i1, 5136))+4);
      i2 = *(OOC_INT8*)((_check_pointer(i0, 5150))+4);
      i1 = i1!=i2;
      
      goto l9;
l7:
      i1=1u;
l9:
      if (i1) goto l11;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5213))+8);
      return (OOC_SSA__Opnd)i0;
      goto l12;
l11:
      return (OOC_SSA__Opnd)0;
l12:
      _failed_function(4917); return 0;
      ;
    }

    
    OOC_CHAR8 OOC_SSA_Aliasing__DesignatorAlias_IsVariable(OOC_SSA__Opnd opnd) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)opnd;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5422));
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5428)))), &_td_OOC_SSA__DeclRefDesc);
      if (i1) goto l3;
      i1=0u;
      goto l5;
l3:
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5461));
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5471)))), &_td_OOC_SSA__DeclRefDesc, 5471)), 5479))+44);
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5486)))), &_td_OOC_SymbolTable__VarDeclDesc);
      
l5:
      if (i1) goto l7;
      i0=0u;
      goto l8;
l7:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5519));
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5529)))), &_td_OOC_SSA__DeclRefDesc, 5529)), 5537))+44);
      i0 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5548)))), &_td_OOC_SymbolTable__VarDeclDesc, 5548)), 5556))+59);
      i0 = !i0;
      
l8:
      return i0;
      ;
    }

    
    OOC_CHAR8 OOC_SSA_Aliasing__DesignatorAlias_IsVarParam(OOC_SSA__Opnd opnd) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)opnd;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5728));
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5734)))), &_td_OOC_SSA__DeclRefDesc);
      if (i1) goto l3;
      i1=0u;
      goto l5;
l3:
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5767));
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5777)))), &_td_OOC_SSA__DeclRefDesc, 5777)), 5785))+44);
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5792)))), &_td_OOC_SymbolTable__VarDeclDesc);
      
l5:
      if (i1) goto l7;
      i0=0u;
      goto l8;
l7:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5824));
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5834)))), &_td_OOC_SSA__DeclRefDesc, 5834)), 5842))+44);
      i0 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5853)))), &_td_OOC_SymbolTable__VarDeclDesc, 5853)), 5861))+59);
      
l8:
      return i0;
      ;
    }

    
    OOC_CHAR8 OOC_SSA_Aliasing__DesignatorAlias_IsHeapObject(OOC_SSA__Opnd opnd) {
      register OOC_INT32 i0;

      i0 = (OOC_INT32)opnd;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6025));
      return (OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6031)))), &_td_OOC_SSA__TypeRefDesc));
      ;
    }

    
    OOC_CHAR8 OOC_SSA_Aliasing__DesignatorAlias_CompatiblePointers(OOC_SymbolTable__Type a, OOC_SymbolTable__Type b) {
      register OOC_INT32 i0,i1,i2;

      i0 = (OOC_INT32)b;
      i1 = (OOC_INT32)a;
      i2 = OOC_SymbolTable_TypeRules__SameType((OOC_SymbolTable__Type)i1, (OOC_SymbolTable__Type)i0);
      if (i2) goto l15;
      i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6216)))), OOC_SymbolTable__TypeDesc_Bound)),OOC_SymbolTable__TypeDesc_Bound)((OOC_SymbolTable__Type)i1);
      a = (OOC_SymbolTable__Type)i1;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6232)))), OOC_SymbolTable__TypeDesc_Bound)),OOC_SymbolTable__TypeDesc_Bound)((OOC_SymbolTable__Type)i0);
      i2 = OOC_SymbolTable_TypeRules__IsPointer((OOC_SymbolTable__Type)i1);
      if (i2) goto l5;
      i2=0u;
      goto l7;
l5:
      i2 = OOC_SymbolTable_TypeRules__IsPointer((OOC_SymbolTable__Type)i0);
      
l7:
      if (i2) goto l9;
      return 0u;
      goto l16;
l9:
      i2 = OOC_SymbolTable_TypeRules__IsExtensionOf((OOC_SymbolTable__Type)i1, (OOC_SymbolTable__Type)i0);
      if (i2) goto l12;
      i0 = OOC_SymbolTable_TypeRules__IsExtensionOf((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
      
      goto l13;
l12:
      i0=1u;
l13:
      return i0;
      goto l16;
l15:
      return 1u;
l16:
      _failed_function(6082); return 0;
      ;
    }

    
    OOC_INT8 OOC_SSA_Aliasing__DesignatorAlias_CheckSelectors(OOC_SSA__Opnd selInstr, OOC_SSA__Opnd selReference, OOC_INT8 prefixClass) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      auto OOC_INT8 OOC_SSA_Aliasing__DesignatorAlias_CheckSelectors_PartiallyCovered(OOC_INT8 id);
        
        OOC_INT8 OOC_SSA_Aliasing__DesignatorAlias_CheckSelectors_PartiallyCovered(OOC_INT8 id) {
          register OOC_INT32 i0,i1;

          i0 = id;
          i1 = i0==3;
          if (i1) goto l3;
          _assert((i0==1), 127, 6823);
          return 2;
          goto l4;
l3:
          return 3;
l4:
          _failed_function(6699); return 0;
          ;
        }


      i0 = prefixClass;
      i1 = i0==1;
      if (i1) goto l3;
      i1 = i0==3;
      
      goto l4;
l3:
      i1=1u;
l4:
      _assert(i1, 127, 6952);
      i1 = (OOC_INT32)selInstr;
      i2 = i1==(OOC_INT32)0;
      if (i2) goto l15;
      i2 = (OOC_INT32)selReference;
      i3 = i2==(OOC_INT32)0;
      if (i3) goto l13;
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 7784));
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 7804));
      i3 = i3==i4;
      if (i3) goto l11;
      i0 = (OOC_INT32)OOC_SSA_Aliasing__DesignatorAlias_NextPart((OOC_SSA__Opnd)i2);
      i1 = (OOC_INT32)OOC_SSA_Aliasing__DesignatorAlias_NextPart((OOC_SSA__Opnd)i1);
      i0 = OOC_SSA_Aliasing__DesignatorAlias_CheckSelectors((OOC_SSA__Opnd)i1, (OOC_SSA__Opnd)i0, 3);
      return i0;
      goto l20;
l11:
      i2 = (OOC_INT32)OOC_SSA_Aliasing__DesignatorAlias_NextPart((OOC_SSA__Opnd)i2);
      i1 = (OOC_INT32)OOC_SSA_Aliasing__DesignatorAlias_NextPart((OOC_SSA__Opnd)i1);
      i0 = OOC_SSA_Aliasing__DesignatorAlias_CheckSelectors((OOC_SSA__Opnd)i1, (OOC_SSA__Opnd)i2, i0);
      return i0;
      goto l20;
l13:
      return i0;
      goto l20;
l15:
      i1 = (OOC_INT32)selReference;
      i1 = i1==(OOC_INT32)0;
      if (i1) goto l18;
      i0 = OOC_SSA_Aliasing__DesignatorAlias_CheckSelectors_PartiallyCovered(i0);
      return i0;
      goto l20;
l18:
      return i0;
l20:
      _failed_function(6465); return 0;
      ;
    }

    
    OOC_CHAR8 OOC_SSA_Aliasing__DesignatorAlias_NotHigherLevel(OOC_SymbolTable__Declaration varParam, OOC_SymbolTable__Declaration variable) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_SymbolTable__Item pVariable;
      OOC_SymbolTable__Item pVarParam;

      i0 = (OOC_INT32)variable;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8497)))), OOC_SymbolTable__ItemDesc_Procedure)),OOC_SymbolTable__ItemDesc_Procedure)((OOC_SymbolTable__Item)i0);
      pVariable = (OOC_SymbolTable__Item)i0;
      i1 = i0==(OOC_INT32)0;
      if (i1) goto l12;
      i1 = (OOC_INT32)varParam;
      i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8738)))), OOC_SymbolTable__ItemDesc_Procedure)),OOC_SymbolTable__ItemDesc_Procedure)((OOC_SymbolTable__Item)i1);
      pVarParam = (OOC_SymbolTable__Item)i1;
      
l3_loop:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8800))+4);
      pVarParam = (OOC_SymbolTable__Item)i1;
      i2 = i1==(OOC_INT32)0;
      if (i2) goto l6;
      i3 = i1==i0;
      
      goto l8;
l6:
      i3=1u;
l8:
      if (!i3) goto l3_loop;
l11:
      return i2;
      goto l13;
l12:
      return 0u;
l13:
      _failed_function(8209); return 0;
      ;
    }


  i0 = (OOC_INT32)instr;
  i1 = OOC_SSA_Aliasing__DesignatorAlias_IsVariable((OOC_SSA__Opnd)i0);
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)reference;
  i1 = OOC_SSA_Aliasing__DesignatorAlias_IsVariable((OOC_SSA__Opnd)i1);
  
l5:
  if (i1) goto l74;
  i1 = OOC_SSA_Aliasing__DesignatorAlias_IsHeapObject((OOC_SSA__Opnd)i0);
  if (i1) goto l9;
  i1=0u;
  goto l11;
l9:
  i1 = (OOC_INT32)reference;
  i1 = OOC_SSA_Aliasing__DesignatorAlias_IsHeapObject((OOC_SSA__Opnd)i1);
  
l11:
  if (i1) goto l64;
  i1 = OOC_SSA_Aliasing__DesignatorAlias_IsVarParam((OOC_SSA__Opnd)i0);
  if (i1) goto l26;
  i1 = (OOC_INT32)reference;
  i2 = OOC_SSA_Aliasing__DesignatorAlias_IsVarParam((OOC_SSA__Opnd)i1);
  if (i2) goto l24;
  i0 = OOC_SSA_Aliasing__DesignatorAlias_IsHeapObject((OOC_SSA__Opnd)i0);
  if (i0) goto l22;
  i0 = OOC_SSA_Aliasing__DesignatorAlias_IsHeapObject((OOC_SSA__Opnd)i1);
  if (!i0) goto l79;
  return 0;
  goto l79;
l22:
  return 0;
  goto l79;
l24:
  i0 = OOC_SSA_Aliasing__DesignatorAlias((OOC_SSA__Opnd)i1, (OOC_SSA__Opnd)i0);
  return i0;
  goto l79;
l26:
  i1 = (OOC_INT32)reference;
  i2 = OOC_SSA_Aliasing__DesignatorAlias_IsVarParam((OOC_SSA__Opnd)i1);
  if (i2) goto l29;
  i2=0u;
  goto l31;
l29:
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10857));
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 10891));
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 10866)))), &_td_OOC_SSA__DeclRefDesc, 10866)), 10874))+44);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 10900)))), &_td_OOC_SSA__DeclRefDesc, 10900)), 10908))+44);
  i2 = i2==i3;
  
l31:
  if (i2) goto l61;
  i2 = OOC_SSA_Aliasing__DesignatorAlias_IsVariable((OOC_SSA__Opnd)i1);
  if (i2) goto l35;
  i0=0u;
  goto l37;
l35:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 11277));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 11217));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11287)))), &_td_OOC_SSA__DeclRefDesc, 11287)), 11295))+44);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11227)))), &_td_OOC_SSA__DeclRefDesc, 11227)), 11235))+44);
  i0 = OOC_SSA_Aliasing__DesignatorAlias_NotHigherLevel((OOC_SymbolTable__Declaration)i0, (OOC_SymbolTable__Declaration)i1);
  
l37:
  if (i0) goto l59;
  i0 = (OOC_INT32)instr;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 11845));
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11855)))), &_td_OOC_SSA__DeclRefDesc, 11855)), 11863))+44);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11874)))), &_td_OOC_SymbolTable__VarDeclDesc, 11874)), 11882))+48);
  typeInstr = (OOC_SymbolTable__Type)i0;
  i1 = (OOC_INT32)reference;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 11911));
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 11917)))), &_td_OOC_SSA__DeclRefDesc);
  if (i2) goto l45;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 12037));
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 12043)))), &_td_OOC_SSA__TypeRefDesc);
  if (i2) goto l43;
  _assert(0u, 127, 12143);
  goto l46;
l43:
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 12094));
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 12104)))), &_td_OOC_SSA__TypeRefDesc, 12104)), 12112))+44);
  typeRef = (OOC_SymbolTable__Type)i2;
  goto l46;
l45:
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 11968));
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 11978)))), &_td_OOC_SSA__DeclRefDesc, 11978)), 11986))+44);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 11997)))), &_td_OOC_SymbolTable__VarDeclDesc, 11997)), 12005))+48);
  typeRef = (OOC_SymbolTable__Type)i2;
l46:
  i2 = (OOC_INT32)typeRef;
  i3 = OOC_SymbolTable_TypeRules__IsComponentOf((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i2, 1u);
  if (i3) goto l53;
  i1 = OOC_SSA_Aliasing__DesignatorAlias_IsVarParam((OOC_SSA__Opnd)i1);
  if (i1) goto l51;
  i0=0u;
  goto l55;
l51:
  i0 = OOC_SymbolTable_TypeRules__IsComponentOf((OOC_SymbolTable__Type)i2, (OOC_SymbolTable__Type)i0, 1u);
  
  goto l55;
l53:
  i0=1u;
l55:
  if (i0) goto l57;
  return 0;
  goto l79;
l57:
  return 3;
  goto l79;
l59:
  return 0;
  goto l79;
l61:
  i1 = (OOC_INT32)OOC_SSA_Aliasing__DesignatorAlias_NextPart((OOC_SSA__Opnd)i1);
  i0 = (OOC_INT32)OOC_SSA_Aliasing__DesignatorAlias_NextPart((OOC_SSA__Opnd)i0);
  i0 = OOC_SSA_Aliasing__DesignatorAlias_CheckSelectors((OOC_SSA__Opnd)i0, (OOC_SSA__Opnd)i1, 1);
  return i0;
  goto l79;
l64:
  i1 = (OOC_INT32)reference;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 9975));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9911));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9985)))), &_td_OOC_SSA__TypeRefDesc, 9985)), 9993))+44);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9921)))), &_td_OOC_SSA__TypeRefDesc, 9921)), 9929))+44);
  i0 = OOC_SSA_Aliasing__DesignatorAlias_CompatiblePointers((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
  if (i0) goto l67;
  return 0;
  goto l79;
l67:
  i0 = (OOC_INT32)instr;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10023))+8);
  i2 = (OOC_INT32)reference;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 10050))+8);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 10060));
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 10033));
  i1 = i1==i3;
  if (i1) goto l70;
  i1 = (OOC_INT32)OOC_SSA_Aliasing__DesignatorAlias_NextPart((OOC_SSA__Opnd)i2);
  i0 = (OOC_INT32)OOC_SSA_Aliasing__DesignatorAlias_NextPart((OOC_SSA__Opnd)i0);
  i0 = OOC_SSA_Aliasing__DesignatorAlias_CheckSelectors((OOC_SSA__Opnd)i0, (OOC_SSA__Opnd)i1, 3);
  return i0;
  goto l79;
l70:
  i1 = (OOC_INT32)OOC_SSA_Aliasing__DesignatorAlias_NextPart((OOC_SSA__Opnd)i2);
  i0 = (OOC_INT32)OOC_SSA_Aliasing__DesignatorAlias_NextPart((OOC_SSA__Opnd)i0);
  i0 = OOC_SSA_Aliasing__DesignatorAlias_CheckSelectors((OOC_SSA__Opnd)i0, (OOC_SSA__Opnd)i1, 1);
  return i0;
  goto l79;
l74:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9230));
  i2 = (OOC_INT32)reference;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 9276));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9240)))), &_td_OOC_SSA__DeclRefDesc, 9240)), 9248))+44);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 9286)))), &_td_OOC_SSA__DeclRefDesc, 9286)), 9294))+44);
  i1 = i1==i3;
  if (i1) goto l77;
  return 0;
  goto l79;
l77:
  i1 = (OOC_INT32)OOC_SSA_Aliasing__DesignatorAlias_NextPart((OOC_SSA__Opnd)i2);
  i0 = (OOC_INT32)OOC_SSA_Aliasing__DesignatorAlias_NextPart((OOC_SSA__Opnd)i0);
  i0 = OOC_SSA_Aliasing__DesignatorAlias_CheckSelectors((OOC_SSA__Opnd)i0, (OOC_SSA__Opnd)i1, 1);
  return i0;
l79:
  return 3;
  ;
}

void OOC_OOC_SSA_Aliasing_init(void) {

  return;
  ;
}

void OOC_OOC_SSA_Aliasing_destroy(void) {
}

/* --- */
