#include <OOC/SymbolTable/Exports.d>
#include <__oo2c.h>
#include <setjmp.h>

ADT_Dictionary_AddressKey__Dictionary OOC_SymbolTable_Exports__GetExports(OOC_SymbolTable__Module module, OOC_CHAR8 forSymbolFile) {
  register OOC_INT32 i0;
  ADT_Dictionary_AddressKey__Dictionary dict;
  auto void OOC_SymbolTable_Exports__GetExports_MarkReferencedImports(OOC_Doc__Document doc);
  auto void OOC_SymbolTable_Exports__GetExports_MarkList(OOC_SymbolTable__Item root);
    
    void OOC_SymbolTable_Exports__GetExports_MarkReferencedImports(OOC_Doc__Document doc) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      OOC_INT32 i;

      i0 = (OOC_INT32)doc;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l3;
      i1=0u;
      goto l5;
l3:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1618))+16);
      i1 = i1!=(OOC_INT32)0;
      
l5:
      if (!i1) goto l15;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1765))+16);
      i = 0;
      i1 = *(OOC_INT32*)((_check_pointer(i1, 1782))+4);
      i2 = 0<i1;
      if (!i2) goto l15;
      i2=0;
l9_loop:
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1818))+16);
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 1835));
      i3 = _check_pointer(i3, 1842);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 1842))*4);
      i4 = (OOC_INT32)dict;
      ADT_Dictionary_AddressKey__DictionaryDesc_Set((ADT_Dictionary_AddressKey__Dictionary)i4, (Object__Object)(_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 1850)))), &_td_OOC_SymbolTable__ImportDesc, 1850)), (Object__Object)(OOC_INT32)0);
      i2 = i2+1;
      i = i2;
      i3 = i2<i1;
      if (i3) goto l9_loop;
l15:
      return;
      ;
    }

    
    void OOC_SymbolTable_Exports__GetExports_MarkList(OOC_SymbolTable__Item root) {
      register OOC_INT32 i0,i1,i2;
      OOC_SymbolTable__Item ptr;
      auto void OOC_SymbolTable_Exports__GetExports_MarkList_MarkDecl(OOC_SymbolTable__Declaration item);
        
        void OOC_SymbolTable_Exports__GetExports_MarkList_MarkDecl(OOC_SymbolTable__Declaration item) {
          register OOC_INT32 i0,i1;
          auto void OOC_SymbolTable_Exports__GetExports_MarkList_MarkDecl_MarkType(OOC_SymbolTable__Type type);
            
            void OOC_SymbolTable_Exports__GetExports_MarkList_MarkDecl_MarkType(OOC_SymbolTable__Type type) {
              register OOC_INT32 i0,i1,i2,i3,i4;
              OOC_SymbolTable__Declaration decl;
              OOC_INT32 i;

              i0 = (OOC_INT32)type;
              i1 = (OOC_INT32)dict;
              i1 = ADT_Dictionary_AddressKey__DictionaryDesc_HasKey((ADT_Dictionary_AddressKey__Dictionary)i1, (Object__Object)i0);
              i1 = !i1;
              if (!i1) goto l72;
              i1 = (OOC_INT32)dict;
              ADT_Dictionary_AddressKey__DictionaryDesc_Set((ADT_Dictionary_AddressKey__Dictionary)i1, (Object__Object)i0, (Object__Object)(OOC_INT32)0);
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2261))+24);
              i1 = i1!=(OOC_INT32)0;
              if (!i1) goto l5;
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2314))+24);
              OOC_SymbolTable_Exports__GetExports_MarkList_MarkDecl((OOC_SymbolTable__Declaration)i1);
l5:
              i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2379)))), &_td_OOC_SymbolTable__PredefTypeDesc);
              if (i1) goto l68;
              i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2445)))), &_td_OOC_SymbolTable__TypeNameDesc);
              if (i1) goto l59;
              i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3117)))), &_td_OOC_SymbolTable__PointerDesc);
              if (i1) goto l57;
              i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3199)))), &_td_OOC_SymbolTable__FormalParsDesc);
              if (i1) goto l41;
              i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3621)))), &_td_OOC_SymbolTable__ArrayDesc);
              if (i1) goto l39;
              i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3704)))), &_td_OOC_SymbolTable__RecordDesc);
              if (i1) goto l34;
              i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3888)))), &_td_OOC_SymbolTable__TypeVarDesc);
              if (i1) goto l32;
              i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3967)))), &_td_OOC_SymbolTable__QualTypeDesc);
              if (i1) goto l22;
              _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3961)))), 3961);
              goto l68;
l22:
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4013))+44);
              OOC_SymbolTable_Exports__GetExports_MarkList_MarkDecl_MarkType((OOC_SymbolTable__Type)i1);
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4069))+48);
              i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 4079)), 0);
              i = 0;
              i2 = 0<i1;
              if (!i2) goto l68;
              i2=0;
l25_loop:
              i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4117))+48);
              i3 = _check_pointer(i3, 4127);
              i4 = OOC_ARRAY_LENGTH(i3, 0);
              i3 = (OOC_INT32)*(OOC_INT32*)((i3+(_check_index(i2, i4, OOC_UINT32, 4127))*8)+4);
              OOC_SymbolTable_Exports__GetExports_MarkList_MarkDecl_MarkType((OOC_SymbolTable__Type)i3);
              i2 = i2+1;
              i = i2;
              i3 = i2<i1;
              if (i3) goto l25_loop;
              goto l68;
l32:
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3933))+44);
              OOC_SymbolTable_Exports__GetExports_MarkList_MarkDecl_MarkType((OOC_SymbolTable__Type)i1);
              goto l68;
l34:
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3742))+44);
              i1 = i1!=(OOC_INT32)0;
              if (!i1) goto l37;
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3802))+44);
              OOC_SymbolTable_Exports__GetExports_MarkList_MarkDecl_MarkType((OOC_SymbolTable__Type)i1);
l37:
              OOC_SymbolTable_Exports__GetExports_MarkList((OOC_SymbolTable__Item)i0);
              goto l68;
l39:
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3664))+48);
              OOC_SymbolTable_Exports__GetExports_MarkList_MarkDecl_MarkType((OOC_SymbolTable__Type)i1);
              goto l68;
l41:
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3241))+48);
              i1 = i1!=(OOC_INT32)0;
              if (!i1) goto l44;
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3303))+48);
              OOC_SymbolTable_Exports__GetExports_MarkList_MarkDecl_MarkType((OOC_SymbolTable__Type)i1);
l44:
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3365))+40);
              i1 = i1!=(OOC_INT32)0;
              if (!i1) goto l47;
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3418))+40);
              OOC_SymbolTable_Exports__GetExports_MarkList_MarkDecl((OOC_SymbolTable__Declaration)i1);
l47:
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3485))+60);
              i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 3492)), 0);
              i = 0;
              i2 = 0<i1;
              if (!i2) goto l55;
              i2=0;
l50_loop:
              i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3529))+60);
              i3 = _check_pointer(i3, 3536);
              i4 = OOC_ARRAY_LENGTH(i3, 0);
              i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 3536))*4);
              i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 3539))+24);
              OOC_SymbolTable_Exports__GetExports_MarkList_MarkDecl_MarkType((OOC_SymbolTable__Type)i3);
              i2 = i2+1;
              i = i2;
              i3 = i2<i1;
              if (i3) goto l50_loop;
l55:
              OOC_SymbolTable_Exports__GetExports_MarkList((OOC_SymbolTable__Item)i0);
              goto l68;
l57:
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3162))+44);
              OOC_SymbolTable_Exports__GetExports_MarkList_MarkDecl_MarkType((OOC_SymbolTable__Type)i1);
              goto l68;
l59:
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2485))+40);
              i1 = i1==(OOC_INT32)0;
              if (i1) goto l62;
              i1 = (OOC_INT32)module;
              i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2766))+48);
              i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2797))+40);
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2766))+48);
              i4 = (OOC_INT32)root;
              i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 2770)))), OOC_SymbolTable__NamespaceDesc_IdentifyLocal)),OOC_SymbolTable__NamespaceDesc_IdentifyLocal)((OOC_SymbolTable__Namespace)i1, (OOC_SymbolTable__Item)i4, (OOC_SymbolTable__Name)i3, 1u);
              decl = (OOC_SymbolTable__Declaration)i1;
              
              goto l63;
l62:
              i1 = (OOC_INT32)module;
              i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2536))+48);
              i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2567))+44);
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2536))+48);
              i4 = (OOC_INT32)root;
              i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 2540)))), OOC_SymbolTable__NamespaceDesc_IdentifyLocal)),OOC_SymbolTable__NamespaceDesc_IdentifyLocal)((OOC_SymbolTable__Namespace)i1, (OOC_SymbolTable__Item)i4, (OOC_SymbolTable__Name)i3, 1u);
              decl = (OOC_SymbolTable__Declaration)i1;
              
l63:
              i2 = i1!=(OOC_INT32)0;
              if (!i2) goto l68;
              OOC_SymbolTable_Exports__GetExports_MarkList_MarkDecl((OOC_SymbolTable__Declaration)i1);
l68:
              i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4201)))), OOC_SymbolTable__TypeDesc_PreciousTypePars)),OOC_SymbolTable__TypeDesc_PreciousTypePars)((OOC_SymbolTable__Type)i0);
              if (!i1) goto l72;
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4253))+28);
              i2 = (OOC_INT32)dict;
              ADT_Dictionary_AddressKey__DictionaryDesc_Set((ADT_Dictionary_AddressKey__Dictionary)i2, (Object__Object)i1, (Object__Object)(OOC_INT32)0);
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4297))+28);
              OOC_SymbolTable_Exports__GetExports_MarkList((OOC_SymbolTable__Item)i0);
l72:
              return;
              ;
            }


          i0 = (OOC_INT32)item;
          i1 = (OOC_INT32)dict;
          i1 = ADT_Dictionary_AddressKey__DictionaryDesc_HasKey((ADT_Dictionary_AddressKey__Dictionary)i1, (Object__Object)i0);
          i1 = !i1;
          if (!i1) goto l31;
          i1 = (OOC_INT32)dict;
          ADT_Dictionary_AddressKey__DictionaryDesc_Set((ADT_Dictionary_AddressKey__Dictionary)i1, (Object__Object)i0, (Object__Object)(OOC_INT32)0);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4493))+32);
          OOC_SymbolTable_Exports__GetExports_MarkReferencedImports((OOC_Doc__Document)i1);
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4537)))), &_td_OOC_SymbolTable__ImportDesc);
          if (i1) goto l31;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4595)))), &_td_OOC_SymbolTable__ProcDeclDesc);
          if (i1) goto l28;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4669)))), &_td_OOC_SymbolTable__PredefProcDesc);
          if (i1) goto l31;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4731)))), &_td_OOC_SymbolTable__ConstDeclDesc);
          if (i1) goto l31;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4792)))), &_td_OOC_SymbolTable__VarDeclDesc);
          if (i1) goto l24;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4866)))), &_td_OOC_SymbolTable__FieldDeclDesc);
          if (i1) goto l22;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4942)))), &_td_OOC_SymbolTable__TypeDeclDesc);
          if (i1) goto l20;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5017)))), &_td_OOC_SymbolTable__RedirectDesc);
          if (i1) goto l31;
          Log__Type((OOC_CHAR8*)"-- [OOC:SymbolTable:Exports]: Unknown type of `item\047", 53, (void*)i0);
          _assert(0u, 127, 5206);
          goto l31;
l20:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4986))+52);
          OOC_SymbolTable_Exports__GetExports_MarkList_MarkDecl_MarkType((OOC_SymbolTable__Type)i0);
          goto l31;
l22:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4911))+52);
          OOC_SymbolTable_Exports__GetExports_MarkList_MarkDecl_MarkType((OOC_SymbolTable__Type)i0);
          goto l31;
l24:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4835))+52);
          OOC_SymbolTable_Exports__GetExports_MarkList_MarkDecl_MarkType((OOC_SymbolTable__Type)i0);
          goto l31;
l28:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4639))+64);
          OOC_SymbolTable_Exports__GetExports_MarkList_MarkDecl_MarkType((OOC_SymbolTable__Type)i0);
l31:
          return;
          ;
        }


      i0 = (OOC_INT32)root;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5296))+8);
      ptr = (OOC_SymbolTable__Item)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l62;
l3_loop:
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5354)))), &_td_OOC_SymbolTable__DeclarationDesc);
      if (!i1) goto l57;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 5392))+28);
      i1 = i1!=0;
      if (i1) goto l12;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5450)))), &_td_OOC_SymbolTable__VarDeclDesc);
      if (i1) goto l10;
      i1=0u;
      goto l14;
l10:
      i1 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5476)))), &_td_OOC_SymbolTable__VarDeclDesc, 5476)), 5484))+56);
      
      goto l14;
l12:
      i1=1u;
l14:
      if (i1) goto l24;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5519)))), &_td_OOC_SymbolTable__TypeDeclDesc);
      if (i1) goto l18;
      i1=0u;
      goto l26;
l18:
      i1 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5562)))), &_td_OOC_SymbolTable__TypeDeclDesc, 5562)), 5571))+56);
      if (i1) goto l21;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5611))+4);
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5619)))), &_td_OOC_SymbolTable__FormalParsDesc);
      
      goto l26;
l21:
      i1=1u;
      goto l26;
l24:
      i1=1u;
l26:
      if (i1) goto l36;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5660)))), &_td_OOC_SymbolTable__ImportDesc);
      if (i1) goto l30;
      i1=0u;
      goto l38;
l30:
      i1 = (OOC_INT32)module;
      i1 = *(OOC_INT8*)((_check_pointer(i1, 5700))+52);
      i1 = i1!=0;
      if (i1) goto l33;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5748))+20);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5753))+12);
      i1 = _check_pointer(i1, 5757);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i1 = *(OOC_UINT8*)(i1+(_check_index(0, i2, OOC_UINT8, 5757)));
      i1 = i1==45u;
      
      goto l38;
l33:
      i1=1u;
      goto l38;
l36:
      i1=1u;
l38:
      if (i1) goto l52;
      i1 = forSymbolFile;
      if (i1) goto l42;
      i1=0u;
      goto l54;
l42:
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5841)))), &_td_OOC_SymbolTable__FieldDeclDesc);
      if (i1) goto l49;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5881)))), &_td_OOC_SymbolTable__ProcDeclDesc);
      if (i1) goto l47;
      i1=0u;
      goto l54;
l47:
      i1 = OOC_SymbolTable__ProcDeclDesc_IsTypeBound((OOC_SymbolTable__ProcDecl)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5908)))), &_td_OOC_SymbolTable__ProcDeclDesc, 5908)));
      
      goto l54;
l49:
      i1=1u;
      goto l54;
l52:
      i1=1u;
l54:
      if (!i1) goto l57;
      OOC_SymbolTable_Exports__GetExports_MarkList_MarkDecl((OOC_SymbolTable__Declaration)i0);
l57:
      i0 = (OOC_INT32)ptr;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6083));
      ptr = (OOC_SymbolTable__Item)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l3_loop;
l62:
      return;
      ;
    }


  i0 = (OOC_INT32)ADT_Dictionary_AddressKey__New();
  dict = (ADT_Dictionary_AddressKey__Dictionary)i0;
  i0 = (OOC_INT32)module;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6197))+32);
  OOC_SymbolTable_Exports__GetExports_MarkReferencedImports((OOC_Doc__Document)i0);
  i0 = (OOC_INT32)module;
  OOC_SymbolTable_Exports__GetExports_MarkList((OOC_SymbolTable__Item)i0);
  i0 = (OOC_INT32)dict;
  return (ADT_Dictionary_AddressKey__Dictionary)i0;
  ;
}

void OOC_OOC_SymbolTable_Exports_init(void) {

  return;
  ;
}

void OOC_OOC_SymbolTable_Exports_destroy(void) {
}

/* --- */
