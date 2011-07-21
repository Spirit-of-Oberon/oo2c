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
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4977));
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4983)))), &_td_OOC_SSA__TypeRefDesc);
      if (!i1) goto l4;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5024))+8);
      opnd = (OOC_SSA__Opnd)i0;
      
l4:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5099))+8);
      i1 = i1==0;
      if (i1) goto l7;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5125))+8);
      i1 = *(OOC_INT8*)((_check_pointer(i1, 5135))+4);
      i2 = *(OOC_INT8*)((_check_pointer(i0, 5149))+4);
      i1 = i1!=i2;
      
      goto l9;
l7:
      i1=1u;
l9:
      if (i1) goto l11;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5212))+8);
      return (OOC_SSA__Opnd)i0;
      goto l12;
l11:
      return (OOC_SSA__Opnd)0;
l12:
      _failed_function(4916); return 0;
      ;
    }

    
    OOC_CHAR8 OOC_SSA_Aliasing__DesignatorAlias_IsVariable(OOC_SSA__Opnd opnd) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)opnd;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5421));
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5427)))), &_td_OOC_SSA__DeclRefDesc);
      if (i1) goto l3;
      i1=0u;
      goto l5;
l3:
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5460));
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5470)))), &_td_OOC_SSA__DeclRefDesc, 5470)), 5478))+44);
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5485)))), &_td_OOC_SymbolTable__VarDeclDesc);
      
l5:
      if (i1) goto l7;
      i0=0u;
      goto l8;
l7:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5518));
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5528)))), &_td_OOC_SSA__DeclRefDesc, 5528)), 5536))+44);
      i0 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5547)))), &_td_OOC_SymbolTable__VarDeclDesc, 5547)), 5555))+59);
      i0 = !i0;
      
l8:
      return i0;
      ;
    }

    
    OOC_CHAR8 OOC_SSA_Aliasing__DesignatorAlias_IsVarParam(OOC_SSA__Opnd opnd) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)opnd;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5727));
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5733)))), &_td_OOC_SSA__DeclRefDesc);
      if (i1) goto l3;
      i1=0u;
      goto l5;
l3:
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5766));
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5776)))), &_td_OOC_SSA__DeclRefDesc, 5776)), 5784))+44);
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5791)))), &_td_OOC_SymbolTable__VarDeclDesc);
      
l5:
      if (i1) goto l7;
      i0=0u;
      goto l8;
l7:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5823));
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5833)))), &_td_OOC_SSA__DeclRefDesc, 5833)), 5841))+44);
      i0 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5852)))), &_td_OOC_SymbolTable__VarDeclDesc, 5852)), 5860))+59);
      
l8:
      return i0;
      ;
    }

    
    OOC_CHAR8 OOC_SSA_Aliasing__DesignatorAlias_IsHeapObject(OOC_SSA__Opnd opnd) {
      register OOC_INT32 i0;

      i0 = (OOC_INT32)opnd;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6024));
      return (OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6030)))), &_td_OOC_SSA__TypeRefDesc));
      ;
    }

    
    OOC_CHAR8 OOC_SSA_Aliasing__DesignatorAlias_CompatiblePointers(OOC_SymbolTable__Type a, OOC_SymbolTable__Type b) {
      register OOC_INT32 i0,i1,i2;

      i0 = (OOC_INT32)a;
      i1 = (OOC_INT32)b;
      i2 = OOC_SymbolTable_TypeRules__SameType((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
      if (i2) goto l15;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6215)))), OOC_SymbolTable__TypeDesc_Bound)),OOC_SymbolTable__TypeDesc_Bound)((OOC_SymbolTable__Type)i0);
      a = (OOC_SymbolTable__Type)i0;
      i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6231)))), OOC_SymbolTable__TypeDesc_Bound)),OOC_SymbolTable__TypeDesc_Bound)((OOC_SymbolTable__Type)i1);
      i2 = OOC_SymbolTable_TypeRules__IsPointer((OOC_SymbolTable__Type)i0);
      if (i2) goto l5;
      i2=0u;
      goto l7;
l5:
      i2 = OOC_SymbolTable_TypeRules__IsPointer((OOC_SymbolTable__Type)i1);
      
l7:
      if (i2) goto l9;
      return 0u;
      goto l16;
l9:
      i2 = OOC_SymbolTable_TypeRules__IsExtensionOf((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
      if (i2) goto l12;
      i0 = OOC_SymbolTable_TypeRules__IsExtensionOf((OOC_SymbolTable__Type)i1, (OOC_SymbolTable__Type)i0);
      
      goto l13;
l12:
      i0=1u;
l13:
      return i0;
      goto l16;
l15:
      return 1u;
l16:
      _failed_function(6081); return 0;
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
          _assert((i0==1), 127, 6822);
          return 2;
          goto l4;
l3:
          return 3;
l4:
          _failed_function(6698); return 0;
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
      _assert(i1, 127, 6951);
      i1 = (OOC_INT32)selInstr;
      i2 = i1==(OOC_INT32)0;
      if (i2) goto l15;
      i2 = (OOC_INT32)selReference;
      i3 = i2==(OOC_INT32)0;
      if (i3) goto l13;
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 7783));
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 7803));
      i3 = i3==i4;
      if (i3) goto l11;
      i0 = (OOC_INT32)OOC_SSA_Aliasing__DesignatorAlias_NextPart((OOC_SSA__Opnd)i1);
      i1 = (OOC_INT32)OOC_SSA_Aliasing__DesignatorAlias_NextPart((OOC_SSA__Opnd)i2);
      i0 = OOC_SSA_Aliasing__DesignatorAlias_CheckSelectors((OOC_SSA__Opnd)i0, (OOC_SSA__Opnd)i1, 3);
      return i0;
      goto l20;
l11:
      i1 = (OOC_INT32)OOC_SSA_Aliasing__DesignatorAlias_NextPart((OOC_SSA__Opnd)i1);
      i2 = (OOC_INT32)OOC_SSA_Aliasing__DesignatorAlias_NextPart((OOC_SSA__Opnd)i2);
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
      _failed_function(6464); return 0;
      ;
    }

    
    OOC_CHAR8 OOC_SSA_Aliasing__DesignatorAlias_NotHigherLevel(OOC_SymbolTable__Declaration varParam, OOC_SymbolTable__Declaration variable) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_SymbolTable__Item pVariable;
      OOC_SymbolTable__Item pVarParam;

      i0 = (OOC_INT32)variable;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8496)))), OOC_SymbolTable__ItemDesc_Procedure)),OOC_SymbolTable__ItemDesc_Procedure)((OOC_SymbolTable__Item)i0);
      pVariable = (OOC_SymbolTable__Item)i0;
      i1 = i0==(OOC_INT32)0;
      if (i1) goto l12;
      i1 = (OOC_INT32)varParam;
      i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8737)))), OOC_SymbolTable__ItemDesc_Procedure)),OOC_SymbolTable__ItemDesc_Procedure)((OOC_SymbolTable__Item)i1);
      pVarParam = (OOC_SymbolTable__Item)i1;
      
l3_loop:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8799))+4);
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
      _failed_function(8208); return 0;
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
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10856));
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 10890));
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 10865)))), &_td_OOC_SSA__DeclRefDesc, 10865)), 10873))+44);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 10899)))), &_td_OOC_SSA__DeclRefDesc, 10899)), 10907))+44);
  i2 = i2==i3;
  
l31:
  if (i2) goto l61;
  i2 = OOC_SSA_Aliasing__DesignatorAlias_IsVariable((OOC_SSA__Opnd)i1);
  if (i2) goto l35;
  i0=0u;
  goto l37;
l35:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 11216));
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 11276));
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11226)))), &_td_OOC_SSA__DeclRefDesc, 11226)), 11234))+44);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11286)))), &_td_OOC_SSA__DeclRefDesc, 11286)), 11294))+44);
  i0 = OOC_SSA_Aliasing__DesignatorAlias_NotHigherLevel((OOC_SymbolTable__Declaration)i0, (OOC_SymbolTable__Declaration)i1);
  
l37:
  if (i0) goto l59;
  i0 = (OOC_INT32)instr;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 11844));
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11854)))), &_td_OOC_SSA__DeclRefDesc, 11854)), 11862))+44);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11873)))), &_td_OOC_SymbolTable__VarDeclDesc, 11873)), 11881))+48);
  typeInstr = (OOC_SymbolTable__Type)i0;
  i1 = (OOC_INT32)reference;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 11910));
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 11916)))), &_td_OOC_SSA__DeclRefDesc);
  if (i2) goto l45;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 12036));
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 12042)))), &_td_OOC_SSA__TypeRefDesc);
  if (i2) goto l43;
  _assert(0u, 127, 12142);
  goto l46;
l43:
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 12093));
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 12103)))), &_td_OOC_SSA__TypeRefDesc, 12103)), 12111))+44);
  typeRef = (OOC_SymbolTable__Type)i2;
  goto l46;
l45:
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 11967));
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 11977)))), &_td_OOC_SSA__DeclRefDesc, 11977)), 11985))+44);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 11996)))), &_td_OOC_SymbolTable__VarDeclDesc, 11996)), 12004))+48);
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
  i0 = (OOC_INT32)OOC_SSA_Aliasing__DesignatorAlias_NextPart((OOC_SSA__Opnd)i0);
  i1 = (OOC_INT32)OOC_SSA_Aliasing__DesignatorAlias_NextPart((OOC_SSA__Opnd)i1);
  i0 = OOC_SSA_Aliasing__DesignatorAlias_CheckSelectors((OOC_SSA__Opnd)i0, (OOC_SSA__Opnd)i1, 1);
  return i0;
  goto l79;
l64:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9910));
  i1 = (OOC_INT32)reference;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 9974));
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9920)))), &_td_OOC_SSA__TypeRefDesc, 9920)), 9928))+44);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9984)))), &_td_OOC_SSA__TypeRefDesc, 9984)), 9992))+44);
  i0 = OOC_SSA_Aliasing__DesignatorAlias_CompatiblePointers((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
  if (i0) goto l67;
  return 0;
  goto l79;
l67:
  i0 = (OOC_INT32)instr;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10022))+8);
  i2 = (OOC_INT32)reference;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 10049))+8);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 10059));
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 10032));
  i1 = i1==i3;
  if (i1) goto l70;
  i0 = (OOC_INT32)OOC_SSA_Aliasing__DesignatorAlias_NextPart((OOC_SSA__Opnd)i0);
  i1 = (OOC_INT32)OOC_SSA_Aliasing__DesignatorAlias_NextPart((OOC_SSA__Opnd)i2);
  i0 = OOC_SSA_Aliasing__DesignatorAlias_CheckSelectors((OOC_SSA__Opnd)i0, (OOC_SSA__Opnd)i1, 3);
  return i0;
  goto l79;
l70:
  i0 = (OOC_INT32)OOC_SSA_Aliasing__DesignatorAlias_NextPart((OOC_SSA__Opnd)i0);
  i1 = (OOC_INT32)OOC_SSA_Aliasing__DesignatorAlias_NextPart((OOC_SSA__Opnd)i2);
  i0 = OOC_SSA_Aliasing__DesignatorAlias_CheckSelectors((OOC_SSA__Opnd)i0, (OOC_SSA__Opnd)i1, 1);
  return i0;
  goto l79;
l74:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9229));
  i2 = (OOC_INT32)reference;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 9275));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9239)))), &_td_OOC_SSA__DeclRefDesc, 9239)), 9247))+44);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 9285)))), &_td_OOC_SSA__DeclRefDesc, 9285)), 9293))+44);
  i1 = i1==i3;
  if (i1) goto l77;
  return 0;
  goto l79;
l77:
  i0 = (OOC_INT32)OOC_SSA_Aliasing__DesignatorAlias_NextPart((OOC_SSA__Opnd)i0);
  i1 = (OOC_INT32)OOC_SSA_Aliasing__DesignatorAlias_NextPart((OOC_SSA__Opnd)i2);
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

/* --- */
