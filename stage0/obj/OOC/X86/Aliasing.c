#include <OOC/X86/Aliasing.d>
#include <__oo2c.h>
#include <setjmp.h>

OOC_INT8 OOC_X86_Aliasing__DesignatorAlias(OOC_X86_SSA__Designator instr, OOC_X86_SSA__Designator reference) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  OOC_SymbolTable__Type typeInstr;
  OOC_SymbolTable__Type typeRef;
  auto OOC_CHAR8 OOC_X86_Aliasing__DesignatorAlias_IsVariable(OOC_X86_SSA__Selector sel);
  auto OOC_CHAR8 OOC_X86_Aliasing__DesignatorAlias_IsVarParam(OOC_X86_SSA__Selector sel);
  auto OOC_CHAR8 OOC_X86_Aliasing__DesignatorAlias_IsHeapObject(OOC_X86_SSA__Selector sel);
  auto OOC_CHAR8 OOC_X86_Aliasing__DesignatorAlias_CompatiblePointers(OOC_SymbolTable__Type a, OOC_SymbolTable__Type b);
  auto OOC_INT8 OOC_X86_Aliasing__DesignatorAlias_CheckSelectors(OOC_X86_SSA__Designator instr, OOC_INT32 indexInstr, OOC_X86_SSA__Designator reference, OOC_INT32 indexReference, OOC_INT8 prefixClass);
  auto OOC_CHAR8 OOC_X86_Aliasing__DesignatorAlias_NotHigherLevel(OOC_SymbolTable__Declaration varParam, OOC_SymbolTable__Declaration variable);
    
    OOC_CHAR8 OOC_X86_Aliasing__DesignatorAlias_IsVariable(OOC_X86_SSA__Selector sel) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)sel;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4680)))), &_td_OOC_X86_SSA__VarDesc);
      if (i1) goto l3;
      i0=0u;
      goto l4;
l3:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4699)))), &_td_OOC_X86_SSA__VarDesc, 4699)), 4703));
      i0 = *(OOC_UINT8*)((_check_pointer(i0, 4708))+59);
      i0 = !i0;
      
l4:
      return i0;
      ;
    }

    
    OOC_CHAR8 OOC_X86_Aliasing__DesignatorAlias_IsVarParam(OOC_X86_SSA__Selector sel) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)sel;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4870)))), &_td_OOC_X86_SSA__VarDesc);
      if (i1) goto l3;
      i0=0u;
      goto l4;
l3:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4888)))), &_td_OOC_X86_SSA__VarDesc, 4888)), 4892));
      i0 = *(OOC_UINT8*)((_check_pointer(i0, 4897))+59);
      
l4:
      return i0;
      ;
    }

    
    OOC_CHAR8 OOC_X86_Aliasing__DesignatorAlias_IsHeapObject(OOC_X86_SSA__Selector sel) {
      register OOC_INT32 i0;

      i0 = (OOC_INT32)sel;
      return (OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5061)))), &_td_OOC_X86_SSA__HeapObjDesc));
      ;
    }

    
    OOC_CHAR8 OOC_X86_Aliasing__DesignatorAlias_CompatiblePointers(OOC_SymbolTable__Type a, OOC_SymbolTable__Type b) {
      register OOC_INT32 i0,i1,i2;

      i0 = (OOC_INT32)b;
      i1 = (OOC_INT32)a;
      i2 = OOC_SymbolTable_TypeRules__SameType((OOC_SymbolTable__Type)i1, (OOC_SymbolTable__Type)i0);
      if (i2) goto l15;
      i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5244)))), OOC_SymbolTable__TypeDesc_Bound)),OOC_SymbolTable__TypeDesc_Bound)((OOC_SymbolTable__Type)i1);
      a = (OOC_SymbolTable__Type)i1;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5260)))), OOC_SymbolTable__TypeDesc_Bound)),OOC_SymbolTable__TypeDesc_Bound)((OOC_SymbolTable__Type)i0);
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
      _failed_function(5110); return 0;
      ;
    }

    
    OOC_INT8 OOC_X86_Aliasing__DesignatorAlias_CheckSelectors(OOC_X86_SSA__Designator instr, OOC_INT32 indexInstr, OOC_X86_SSA__Designator reference, OOC_INT32 indexReference, OOC_INT8 prefixClass) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10;
      auto OOC_INT8 OOC_X86_Aliasing__DesignatorAlias_CheckSelectors_PartiallyCovered(OOC_INT8 id);
        
        OOC_INT8 OOC_X86_Aliasing__DesignatorAlias_CheckSelectors_PartiallyCovered(OOC_INT8 id) {
          register OOC_INT32 i0,i1;

          i0 = id;
          i1 = i0==3;
          if (i1) goto l3;
          _assert((i0==1), 127, 5937);
          return 2;
          goto l4;
l3:
          return 3;
l4:
          _failed_function(5813); return 0;
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
      _assert(i1, 127, 6066);
      i1 = (OOC_INT32)instr;
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i1, 6182)), 0);
      i3 = indexInstr;
      i2 = i3==i2;
      if (i2) goto l15;
      i2 = (OOC_INT32)reference;
      i4 = OOC_ARRAY_LENGTH((_check_pointer(i2, 6623)), 0);
      i5 = indexReference;
      i4 = i5==i4;
      if (i4) goto l13;
      i4 = _check_pointer(i2, 6966);
      i6 = OOC_ARRAY_LENGTH(i4, 0);
      i7 = _check_pointer(i1, 6931);
      i8 = OOC_ARRAY_LENGTH(i7, 0);
      i9 = _check_pointer(i1, 6931);
      i10 = OOC_ARRAY_LENGTH(i9, 0);
      i9 = (OOC_INT32)*(OOC_INT32*)(i9+(_check_index(i3, i10, OOC_UINT32, 6931))*4);
      i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i3, i8, OOC_UINT32, 6931))*4);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i5, i6, OOC_UINT32, 6966))*4);
      i4 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i9, 6943)))), OOC_X86_SSA__SelectorDesc_SameSelector)),OOC_X86_SSA__SelectorDesc_SameSelector)((OOC_X86_SSA__Selector)i7, (OOC_X86_SSA__Selector)i4);
      if (i4) goto l11;
      i0 = OOC_X86_Aliasing__DesignatorAlias_CheckSelectors((OOC_X86_SSA__Designator)i1, (i3+1), (OOC_X86_SSA__Designator)i2, (i5+1), 3);
      return i0;
      goto l20;
l11:
      i0 = OOC_X86_Aliasing__DesignatorAlias_CheckSelectors((OOC_X86_SSA__Designator)i1, (i3+1), (OOC_X86_SSA__Designator)i2, (i5+1), i0);
      return i0;
      goto l20;
l13:
      return i0;
      goto l20;
l15:
      i1 = (OOC_INT32)reference;
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 6287)), 0);
      i2 = indexReference;
      i1 = i2==i1;
      if (i1) goto l18;
      i0 = OOC_X86_Aliasing__DesignatorAlias_CheckSelectors_PartiallyCovered(i0);
      return i0;
      goto l20;
l18:
      return i0;
l20:
      _failed_function(5493); return 0;
      ;
    }

    
    OOC_CHAR8 OOC_X86_Aliasing__DesignatorAlias_NotHigherLevel(OOC_SymbolTable__Declaration varParam, OOC_SymbolTable__Declaration variable) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_SymbolTable__Item pVariable;
      OOC_SymbolTable__Item pVarParam;

      i0 = (OOC_INT32)variable;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7738)))), OOC_SymbolTable__ItemDesc_Procedure)),OOC_SymbolTable__ItemDesc_Procedure)((OOC_SymbolTable__Item)i0);
      pVariable = (OOC_SymbolTable__Item)i0;
      i1 = i0==(OOC_INT32)0;
      if (i1) goto l12;
      i1 = (OOC_INT32)varParam;
      i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7979)))), OOC_SymbolTable__ItemDesc_Procedure)),OOC_SymbolTable__ItemDesc_Procedure)((OOC_SymbolTable__Item)i1);
      pVarParam = (OOC_SymbolTable__Item)i1;
      
l3_loop:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8040))+4);
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
      _failed_function(7450); return 0;
      ;
    }


  i0 = (OOC_INT32)instr;
  i1 = _check_pointer(i0, 8210);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 8210))*4);
  i1 = OOC_X86_Aliasing__DesignatorAlias_IsVariable((OOC_X86_SSA__Selector)i1);
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)reference;
  i1 = _check_pointer(i1, 8237);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 8237))*4);
  i1 = OOC_X86_Aliasing__DesignatorAlias_IsVariable((OOC_X86_SSA__Selector)i1);
  
l5:
  if (i1) goto l66;
  i1 = _check_pointer(i0, 8938);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 8938))*4);
  i1 = OOC_X86_Aliasing__DesignatorAlias_IsHeapObject((OOC_X86_SSA__Selector)i1);
  if (i1) goto l9;
  i1=0u;
  goto l11;
l9:
  i1 = (OOC_INT32)reference;
  i1 = _check_pointer(i1, 8967);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 8967))*4);
  i1 = OOC_X86_Aliasing__DesignatorAlias_IsHeapObject((OOC_X86_SSA__Selector)i1);
  
l11:
  if (i1) goto l56;
  i1 = _check_pointer(i0, 9837);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 9837))*4);
  i1 = OOC_X86_Aliasing__DesignatorAlias_IsVarParam((OOC_X86_SSA__Selector)i1);
  if (i1) goto l26;
  i1 = (OOC_INT32)reference;
  i2 = _check_pointer(i1, 11138);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(0, i3, OOC_UINT8, 11138))*4);
  i2 = OOC_X86_Aliasing__DesignatorAlias_IsVarParam((OOC_X86_SSA__Selector)i2);
  if (i2) goto l24;
  i0 = _check_pointer(i0, 11675);
  i2 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i2, OOC_UINT8, 11675))*4);
  i0 = OOC_X86_Aliasing__DesignatorAlias_IsHeapObject((OOC_X86_SSA__Selector)i0);
  if (i0) goto l22;
  i0 = _check_pointer(i1, 11889);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 11889))*4);
  i0 = OOC_X86_Aliasing__DesignatorAlias_IsHeapObject((OOC_X86_SSA__Selector)i0);
  if (!i0) goto l71;
  return 0;
  goto l71;
l22:
  return 0;
  goto l71;
l24:
  i0 = OOC_X86_Aliasing__DesignatorAlias((OOC_X86_SSA__Designator)i1, (OOC_X86_SSA__Designator)i0);
  return i0;
  goto l71;
l26:
  i1 = (OOC_INT32)reference;
  i2 = _check_pointer(i1, 9876);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(0, i3, OOC_UINT8, 9876))*4);
  i2 = OOC_X86_Aliasing__DesignatorAlias_IsVarParam((OOC_X86_SSA__Selector)i2);
  if (i2) goto l29;
  i2=0u;
  goto l31;
l29:
  i2 = _check_pointer(i1, 9923);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = _check_pointer(i0, 9897);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = _check_pointer(i0, 9897);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(0, i7, OOC_UINT8, 9897))*4);
  i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(0, i3, OOC_UINT8, 9923))*4);
  i3 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(0, i5, OOC_UINT8, 9897))*4);
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 9900)))), OOC_X86_SSA__SelectorDesc_SameSelector)),OOC_X86_SSA__SelectorDesc_SameSelector)((OOC_X86_SSA__Selector)i3, (OOC_X86_SSA__Selector)i2);
  
l31:
  if (i2) goto l53;
  i2 = _check_pointer(i1, 10147);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(0, i3, OOC_UINT8, 10147))*4);
  i2 = OOC_X86_Aliasing__DesignatorAlias_IsVariable((OOC_X86_SSA__Selector)i2);
  if (i2) goto l35;
  i0=0u;
  goto l37;
l35:
  i1 = _check_pointer(i1, 10239);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 10239))*4);
  i0 = _check_pointer(i0, 10186);
  i2 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i2, OOC_UINT8, 10186))*4);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10245)))), &_td_OOC_X86_SSA__VarDesc, 10245)), 10249));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10192)))), &_td_OOC_X86_SSA__VarDesc, 10192)), 10196));
  i0 = OOC_X86_Aliasing__DesignatorAlias_NotHigherLevel((OOC_SymbolTable__Declaration)i0, (OOC_SymbolTable__Declaration)i1);
  
l37:
  if (i0) goto l51;
  i0 = (OOC_INT32)instr;
  i1 = _check_pointer(i0, 10798);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i0 = _check_pointer(i0, 10798);
  i3 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i3, OOC_UINT8, 10798))*4);
  i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 10798))*4);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10801)))), OOC_X86_SSA__SelectorDesc_Type)),OOC_X86_SSA__SelectorDesc_Type)((OOC_X86_SSA__Selector)i1);
  typeInstr = (OOC_SymbolTable__Type)i0;
  i1 = (OOC_INT32)reference;
  i2 = _check_pointer(i1, 10838);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = _check_pointer(i1, 10838);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(0, i5, OOC_UINT8, 10838))*4);
  i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(0, i3, OOC_UINT8, 10838))*4);
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 10841)))), OOC_X86_SSA__SelectorDesc_Type)),OOC_X86_SSA__SelectorDesc_Type)((OOC_X86_SSA__Selector)i2);
  typeRef = (OOC_SymbolTable__Type)i2;
  i3 = OOC_SymbolTable_TypeRules__IsComponentOf((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i2, 1u);
  if (i3) goto l45;
  i1 = _check_pointer(i1, 10940);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i3, OOC_UINT8, 10940))*4);
  i1 = OOC_X86_Aliasing__DesignatorAlias_IsVarParam((OOC_X86_SSA__Selector)i1);
  if (i1) goto l43;
  i0=0u;
  goto l47;
l43:
  i0 = OOC_SymbolTable_TypeRules__IsComponentOf((OOC_SymbolTable__Type)i2, (OOC_SymbolTable__Type)i0, 1u);
  
  goto l47;
l45:
  i0=1u;
l47:
  if (i0) goto l49;
  return 0;
  goto l71;
l49:
  return 3;
  goto l71;
l51:
  return 0;
  goto l71;
l53:
  i0 = OOC_X86_Aliasing__DesignatorAlias_CheckSelectors((OOC_X86_SSA__Designator)i0, 1, (OOC_X86_SSA__Designator)i1, 1, 1);
  return i0;
  goto l71;
l56:
  i1 = (OOC_INT32)reference;
  i1 = _check_pointer(i1, 9128);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 9128))*4);
  i0 = _check_pointer(i0, 9070);
  i2 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i2, OOC_UINT8, 9070))*4);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9134)))), &_td_OOC_X86_SSA__HeapObjDesc, 9134)), 9142));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9076)))), &_td_OOC_X86_SSA__HeapObjDesc, 9076)), 9084));
  i0 = OOC_X86_Aliasing__DesignatorAlias_CompatiblePointers((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
  if (i0) goto l59;
  return 0;
  goto l71;
l59:
  i0 = (OOC_INT32)reference;
  i1 = _check_pointer(i0, 9196);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i3 = (OOC_INT32)instr;
  i4 = _check_pointer(i3, 9170);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = _check_pointer(i3, 9170);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(0, i7, OOC_UINT8, 9170))*4);
  i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 9196))*4);
  i2 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(0, i5, OOC_UINT8, 9170))*4);
  i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 9173)))), OOC_X86_SSA__SelectorDesc_SameSelector)),OOC_X86_SSA__SelectorDesc_SameSelector)((OOC_X86_SSA__Selector)i2, (OOC_X86_SSA__Selector)i1);
  if (i1) goto l62;
  i0 = OOC_X86_Aliasing__DesignatorAlias_CheckSelectors((OOC_X86_SSA__Designator)i3, 1, (OOC_X86_SSA__Designator)i0, 1, 3);
  return i0;
  goto l71;
l62:
  i0 = OOC_X86_Aliasing__DesignatorAlias_CheckSelectors((OOC_X86_SSA__Designator)i3, 1, (OOC_X86_SSA__Designator)i0, 1, 1);
  return i0;
  goto l71;
l66:
  i1 = (OOC_INT32)reference;
  i2 = _check_pointer(i1, 8498);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = _check_pointer(i0, 8472);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = _check_pointer(i0, 8472);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(0, i7, OOC_UINT8, 8472))*4);
  i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(0, i3, OOC_UINT8, 8498))*4);
  i3 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(0, i5, OOC_UINT8, 8472))*4);
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 8475)))), OOC_X86_SSA__SelectorDesc_SameSelector)),OOC_X86_SSA__SelectorDesc_SameSelector)((OOC_X86_SSA__Selector)i3, (OOC_X86_SSA__Selector)i2);
  if (i2) goto l69;
  return 0;
  goto l71;
l69:
  i0 = OOC_X86_Aliasing__DesignatorAlias_CheckSelectors((OOC_X86_SSA__Designator)i0, 1, (OOC_X86_SSA__Designator)i1, 1, 1);
  return i0;
l71:
  return 3;
  ;
}

void OOC_OOC_X86_Aliasing_init(void) {

  return;
  ;
}

/* --- */
