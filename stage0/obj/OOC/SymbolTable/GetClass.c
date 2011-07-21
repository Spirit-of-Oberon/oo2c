#include <OOC/SymbolTable/GetClass.d>
#include <__oo2c.h>
#include <setjmp.h>

OOC_SymbolTable__Name OOC_SymbolTable_GetClass__GetClass(OOC_SymbolTable__Item item) {
  register OOC_INT32 i0,i1;
  auto OOC_CHAR8 OOC_SymbolTable_GetClass__GetClass_SameModule(OOC_SymbolTable__Item a, OOC_SymbolTable__Item b);
  auto OOC_SymbolTable__Name OOC_SymbolTable_GetClass__GetClass_InitProcClass(OOC_SymbolTable__ProcDecl procDecl);
    
    OOC_CHAR8 OOC_SymbolTable_GetClass__GetClass_SameModule(OOC_SymbolTable__Item a, OOC_SymbolTable__Item b) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)a;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1455)))), OOC_SymbolTable__ItemDesc_Module)),OOC_SymbolTable__ItemDesc_Module)((OOC_SymbolTable__Item)i0);
      i1 = (OOC_INT32)b;
      i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 1469)))), OOC_SymbolTable__ItemDesc_Module)),OOC_SymbolTable__ItemDesc_Module)((OOC_SymbolTable__Item)i1);
      return (i0==i1);
      ;
    }

    
    OOC_SymbolTable__Name OOC_SymbolTable_GetClass__GetClass_InitProcClass(OOC_SymbolTable__ProcDecl procDecl) {
      register OOC_INT32 i0,i1,i2;
      OOC_INT16 pos;
      OOC_CHAR8 found;

      i0 = (OOC_INT32)procDecl;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1666))+20);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 1672))+12);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1666))+20);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 1672))+12);
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 1677)), 0);
      Strings__FindNext((OOC_CHAR8*)"Init", 5, (void*)(_check_pointer(i2, 1677)), i1, 0, (void*)(OOC_INT32)&found, (void*)(OOC_INT32)&pos);
      i1 = found;
      if (i1) goto l3;
      i1=0u;
      goto l5;
l3:
      i1 = pos;
      i1 = i1==0;
      
l5:
      if (i1) goto l7;
      i1=0u;
      goto l9;
l7:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1743))+64);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 1755))+52);
      i1 = i1!=(OOC_INT32)0;
      
l9:
      if (i1) goto l11;
      i1=0u;
      goto l13;
l11:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1797))+64);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 1809))+52);
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 1817)), 0);
      i1 = i1>=1;
      
l13:
      if (i1) goto l15;
      i1=0u;
      goto l17;
l15:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1846))+64);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 1858))+44);
      i1 = i1==(OOC_INT32)0;
      
l17:
      if (i1) goto l19;
      i1=0u;
      goto l21;
l19:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1919))+64);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 1931))+52);
      i1 = _check_pointer(i1, 1939);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 1939))*4);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 1942))+48);
      i1 = OOC_SymbolTable_GetClass__GetClass_SameModule((OOC_SymbolTable__Item)i0, (OOC_SymbolTable__Item)i1);
      
l21:
      if (i1) goto l23;
      return (OOC_SymbolTable__Name)(OOC_INT32)0;
      goto l24;
l23:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1988))+64);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2000))+52);
      i0 = _check_pointer(i0, 2008);
      i1 = OOC_ARRAY_LENGTH(i0, 0);
      i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 2008))*4);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2011))+48);
      i0 = (OOC_INT32)OOC_SymbolTable_GetClass__GetClass((OOC_SymbolTable__Item)i0);
      return (OOC_SymbolTable__Name)i0;
l24:
      _failed_function(1516); return 0;
      ;
    }


  i0 = (OOC_INT32)item;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2106)))), &_td_OOC_SymbolTable__RecordDesc);
  if (i1) goto l43;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2168)))), &_td_OOC_SymbolTable__PointerDesc);
  if (i1) goto l33;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2383)))), &_td_OOC_SymbolTable__TypeDeclDesc);
  if (i1) goto l27;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2583)))), &_td_OOC_SymbolTable__FieldDeclDesc);
  if (i1) goto l25;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2668)))), &_td_OOC_SymbolTable__ProcDeclDesc);
  if (i1) goto l11;
  return (OOC_SymbolTable__Name)(OOC_INT32)0;
  goto l44;
l11:
  i1 = OOC_SymbolTable__ProcDeclDesc_IsTypeBound((OOC_SymbolTable__ProcDecl)i0);
  if (i1) goto l22;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2795))+64);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2807))+44);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l16;
  i0=0u;
  goto l18;
l16:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2863))+64);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2875))+44);
  i0 = OOC_SymbolTable_GetClass__GetClass_SameModule((OOC_SymbolTable__Item)i0, (OOC_SymbolTable__Item)i1);
  
l18:
  if (i0) goto l20;
  i0 = (OOC_INT32)item;
  i0 = (OOC_INT32)OOC_SymbolTable_GetClass__GetClass_InitProcClass((OOC_SymbolTable__ProcDecl)i0);
  return (OOC_SymbolTable__Name)i0;
  goto l44;
l20:
  i0 = (OOC_INT32)item;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2923))+64);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2935))+44);
  i0 = (OOC_INT32)OOC_SymbolTable_GetClass__GetClass((OOC_SymbolTable__Item)i0);
  return (OOC_SymbolTable__Name)i0;
  goto l44;
l22:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2748))+64);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2760))+40);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2770))+48);
  i0 = (OOC_INT32)OOC_SymbolTable_GetClass__GetClass((OOC_SymbolTable__Item)i0);
  return (OOC_SymbolTable__Name)i0;
  goto l44;
l25:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2619))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2632)))), &_td_OOC_SymbolTable__RecordDesc, 2632)), 2639))+64);
  return (OOC_SymbolTable__Name)i0;
  goto l44;
l27:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2432))+48);
  i0 = OOC_SymbolTable_GetClass__GetClass_SameModule((OOC_SymbolTable__Item)i0, (OOC_SymbolTable__Item)i1);
  if (i0) goto l30;
  return (OOC_SymbolTable__Name)(OOC_INT32)0;
  goto l44;
l30:
  i0 = (OOC_INT32)item;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2474))+48);
  i0 = (OOC_INT32)OOC_SymbolTable_GetClass__GetClass((OOC_SymbolTable__Item)i0);
  return (OOC_SymbolTable__Name)i0;
  goto l44;
l33:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2199))+40);
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2210)))), &_td_OOC_SymbolTable__RecordDesc);
  if (i1) goto l36;
  i0=0u;
  goto l38;
l36:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2258))+40);
  i0 = OOC_SymbolTable_GetClass__GetClass_SameModule((OOC_SymbolTable__Item)i0, (OOC_SymbolTable__Item)i1);
  
l38:
  if (i0) goto l40;
  return (OOC_SymbolTable__Name)(OOC_INT32)0;
  goto l44;
l40:
  i0 = (OOC_INT32)item;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2294))+40);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2309)))), &_td_OOC_SymbolTable__RecordDesc, 2309)), 2316))+64);
  return (OOC_SymbolTable__Name)i0;
  goto l44;
l43:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2139))+64);
  return (OOC_SymbolTable__Name)i0;
l44:
  _failed_function(89); return 0;
  ;
}

void OOC_OOC_SymbolTable_GetClass_init(void) {

  return;
  ;
}

void OOC_OOC_SymbolTable_GetClass_destroy(void) {
}

/* --- */
