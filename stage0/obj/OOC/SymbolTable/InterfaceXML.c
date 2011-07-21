#include <OOC/SymbolTable/InterfaceXML.d>
#include <__oo2c.h>
#include <setjmp.h>

static URI__URI OOC_SymbolTable_InterfaceXML__GetSystemId(OOC_Config_Repositories__Section repositories) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)OOC_SymbolTable_InterfaceXML__dtdSystemId;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l3;
  return (URI__URI)i0;
  goto l4;
l3:
  i0 = (OOC_INT32)repositories;
  i0 = (OOC_INT32)OOC_Config_Repositories__SectionDesc_GetResource((OOC_Config_Repositories__Section)i0, "OOC", 4, "xml/module-interface.dtd", 25);
  OOC_SymbolTable_InterfaceXML__dtdSystemId = (URI__URI)i0;
  _assert((i0!=(OOC_INT32)0), 127, 1476);
  return (URI__URI)i0;
l4:
  _failed_function(1289); return 0;
  ;
}

void OOC_SymbolTable_InterfaceXML__Write(IO__ByteChannel cw, URI__HierarchicalURI baseURI, OOC_SymbolTable__Module module, OOC_Config_Repositories__Section repositories) {
  register OOC_INT32 i0,i1;
  XML_Writer__Writer w;
  auto void OOC_SymbolTable_InterfaceXML__Write_WriteItem(OOC_SymbolTable__Item item);
    
    void OOC_SymbolTable_InterfaceXML__Write_WriteItem(OOC_SymbolTable__Item item) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_Repository__Module moduleRepository;
      OOC_SymbolTable__Item i;
      OOC_CHAR8 element[32];
      auto void OOC_SymbolTable_InterfaceXML__Write_WriteItem_StartDecl(const OOC_CHAR8 tag__ref[], OOC_LEN tag_0d, OOC_SymbolTable__Declaration decl);
      auto void OOC_SymbolTable_InterfaceXML__Write_WriteItem_DeclDocString(OOC_SymbolTable__Declaration decl);
      auto void OOC_SymbolTable_InterfaceXML__Write_WriteItem_WriteType(const OOC_CHAR8 tag__ref[], OOC_LEN tag_0d, OOC_SymbolTable__Type type, OOC_SymbolTable__Type resolvedType);
      auto void OOC_SymbolTable_InterfaceXML__Write_WriteItem_ClassAttr(OOC_SymbolTable__Item item);
      auto void OOC_SymbolTable_InterfaceXML__Write_WriteItem_WriteTypeComponent(OOC_SymbolTable__Type type, OOC_SymbolTable__Type resolvedType);
      auto void OOC_SymbolTable_InterfaceXML__Write_WriteItem_WriteType(const OOC_CHAR8 tag__ref[], OOC_LEN tag_0d, OOC_SymbolTable__Type type, OOC_SymbolTable__Type resolvedType);
        
        void OOC_SymbolTable_InterfaceXML__Write_WriteItem_StartDecl(const OOC_CHAR8 tag__ref[], OOC_LEN tag_0d, OOC_SymbolTable__Declaration decl) {
          register OOC_INT32 i0,i1,i2,i3;
          OOC_ALLOCATE_VPAR(tag,OOC_CHAR8 ,tag_0d)

          OOC_INITIALIZE_VPAR(tag__ref,tag,OOC_CHAR8 ,tag_0d)
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2339)))), XML_Writer__WriterDesc_StartTagLatin1)),XML_Writer__WriterDesc_StartTagLatin1)((XML_Writer__Writer)i0, (void*)(OOC_INT32)tag, tag_0d, 0u);
          i0 = (OOC_INT32)decl;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2411))+20);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2417))+12);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2411))+20);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 2417))+12);
          i3 = (OOC_INT32)w;
          i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 2422)), 0);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 2379)))), XML_Writer__WriterDesc_AttrStringLatin1)),XML_Writer__WriterDesc_AttrStringLatin1)((XML_Writer__Writer)i3, ((OOC_CHAR16[]){110,97,109,101,0}), 5, (void*)(_check_pointer(i2, 2422)), i1);
          i0 = *(OOC_INT8*)((_check_pointer(i0, 2443))+28);
          switch (i0) {
          case 0:
            i0 = (OOC_INT32)w;
            OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2501)))), XML_Writer__WriterDesc_AttrString)),XML_Writer__WriterDesc_AttrString)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){101,120,112,111,114,116,0}), 7, ((OOC_CHAR16[]){110,111,0}), 3);
            goto l6;
          case 1:
            i0 = (OOC_INT32)w;
            OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2570)))), XML_Writer__WriterDesc_AttrString)),XML_Writer__WriterDesc_AttrString)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){101,120,112,111,114,116,0}), 7, ((OOC_CHAR16[]){121,101,115,0}), 4);
            goto l6;
          case 2:
            i0 = (OOC_INT32)w;
            OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2642)))), XML_Writer__WriterDesc_AttrString)),XML_Writer__WriterDesc_AttrString)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){101,120,112,111,114,116,0}), 7, ((OOC_CHAR16[]){114,101,97,100,45,111,110,108,121,0}), 10);
            goto l6;
          default:
            _failed_case(i0, 2434);
            goto l6;
          }
l6:
          return;
          ;
        }

        
        void OOC_SymbolTable_InterfaceXML__Write_WriteItem_DeclDocString(OOC_SymbolTable__Declaration decl) {
          register OOC_INT32 i0,i1,i2;

          i0 = (OOC_INT32)decl;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2798))+32);
          i1 = i1!=(OOC_INT32)0;
          if (!i1) goto l4;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2862))+32);
          i1 = (OOC_INT32)w;
          i2 = (OOC_INT32)module;
          OOC_Doc_Output_XML__WriteOberonDoc((XML_Writer__Writer)i1, (OOC_Doc__Document)i0, (OOC_SymbolTable__Module)i2, (ADT_Dictionary__Dictionary)(OOC_INT32)0, (OOC_Config_Repositories__Section)(OOC_INT32)0, (ADT_Dictionary__Dictionary)(OOC_INT32)0);
l4:
          return;
          ;
        }

        
        void OOC_SymbolTable_InterfaceXML__Write_WriteItem_ClassAttr(OOC_SymbolTable__Item item) {
          register OOC_INT32 i0,i1,i2;
          OOC_SymbolTable__Name _class;

          i0 = (OOC_INT32)item;
          i0 = (OOC_INT32)OOC_SymbolTable_GetClass__GetClass((OOC_SymbolTable__Item)i0);
          _class = (OOC_SymbolTable__Name)i0;
          i1 = i0!=(OOC_INT32)0;
          if (!i1) goto l4;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3230))+12);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3230))+12);
          i2 = (OOC_INT32)w;
          i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 3235)), 0);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 3196)))), XML_Writer__WriterDesc_AttrStringLatin1)),XML_Writer__WriterDesc_AttrStringLatin1)((XML_Writer__Writer)i2, ((OOC_CHAR16[]){99,108,97,115,115,0}), 6, (void*)(_check_pointer(i0, 3235)), i1);
l4:
          return;
          ;
        }

        
        void OOC_SymbolTable_InterfaceXML__Write_WriteItem_WriteTypeComponent(OOC_SymbolTable__Type type, OOC_SymbolTable__Type resolvedType) {
          register OOC_INT32 i0,i1,i2,i3,i4;
          OOC_SymbolTable__Module module;
          OOC_SymbolTable__Item i;
          OOC_INT32 j;
          auto void OOC_SymbolTable_InterfaceXML__Write_WriteItem_WriteTypeComponent_WriteBaseClass(OOC_SymbolTable__Record baseType);
            
            void OOC_SymbolTable_InterfaceXML__Write_WriteItem_WriteTypeComponent_WriteBaseClass(OOC_SymbolTable__Record baseType) {
              register OOC_INT32 i0,i1,i2,i3,i4;
              OOC_SymbolTable__Module module;
              OOC_Repository__Module moduleRepository;

              i0 = (OOC_INT32)w;
              OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3596)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){98,97,115,101,45,99,108,97,115,115,0}), 11, 0u);
              i0 = (OOC_INT32)baseType;
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3902))+64);
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3913))+12);
              i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3902))+64);
              i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 3913))+12);
              i3 = (OOC_INT32)w;
              i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 3918)), 0);
              OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 3865)))), XML_Writer__WriterDesc_AttrStringLatin1)),XML_Writer__WriterDesc_AttrStringLatin1)((XML_Writer__Writer)i3, ((OOC_CHAR16[]){99,108,97,115,115,0}), 6, (void*)(_check_pointer(i2, 3918)), i1);
              i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3961)))), OOC_SymbolTable__ItemDesc_Module)),OOC_SymbolTable__ItemDesc_Module)((OOC_SymbolTable__Item)i0);
              module = (OOC_SymbolTable__Module)i1;
              i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4020))+20);
              i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 4026))+12);
              i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4020))+20);
              i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 4026))+12);
              i4 = (OOC_INT32)w;
              i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 4031)), 0);
              OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 3984)))), XML_Writer__WriterDesc_AttrStringLatin1)),XML_Writer__WriterDesc_AttrStringLatin1)((XML_Writer__Writer)i4, ((OOC_CHAR16[]){109,111,100,117,108,101,0}), 7, (void*)(_check_pointer(i3, 4031)), i2);
              i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4107))+20);
              i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 4113))+12);
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4107))+20);
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4113))+12);
              i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 4118)), 0);
              i3 = (OOC_INT32)repositories;
              i1 = (OOC_INT32)OOC_Config_Repositories__SectionDesc_GetModule((OOC_Config_Repositories__Section)i3, (void*)(_check_pointer(i1, 4118)), i2);
              moduleRepository = (OOC_Repository__Module)i1;
              i2 = i1!=(OOC_INT32)0;
              if (!i2) goto l3;
              i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 4255));
              i2 = (OOC_INT32)w;
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4263))+4);
              OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 4209)))), XML_Writer__WriterDesc_AttrURI)),XML_Writer__WriterDesc_AttrURI)((XML_Writer__Writer)i2, ((OOC_CHAR16[]){114,101,112,111,115,105,116,111,114,121,45,98,97,115,101,0}), 16, (URI__URI)i1, 0u);
l3:
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4329))+40);
              i1 = i1!=(OOC_INT32)0;
              if (!i1) goto l6;
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4388))+40);
              OOC_SymbolTable_InterfaceXML__Write_WriteItem_WriteTypeComponent_WriteBaseClass((OOC_SymbolTable__Record)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4403)))), &_td_OOC_SymbolTable__RecordDesc, 4403)));
l6:
              i0 = (OOC_INT32)w;
              OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4438)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i0);
              return;
              ;
            }


          i0 = (OOC_INT32)type;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4511)))), &_td_OOC_SymbolTable__TypeNameDesc);
          if (i1) goto l61;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4970)))), &_td_OOC_SymbolTable__PointerDesc);
          if (i1) goto l59;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5169)))), &_td_OOC_SymbolTable__ArrayDesc);
          if (i1) goto l54;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5459)))), &_td_OOC_SymbolTable__RecordDesc);
          if (i1) goto l38;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5969)))), &_td_OOC_SymbolTable__FormalParsDesc);
          if (i1) goto l11;
          _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5963)))), 5963);
          goto l73;
l11:
          i1 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6000)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i1, ((OOC_CHAR16[]){102,111,114,109,97,108,45,112,97,114,97,109,101,116,101,114,115,0}), 18, 0u);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6059))+40);
          i1 = i1!=(OOC_INT32)0;
          if (!i1) goto l14;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6109))+40);
          OOC_SymbolTable_InterfaceXML__Write_WriteItem((OOC_SymbolTable__Item)i1);
l14:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6170))+52);
          j = 0;
          i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 6178)), 0);
          i2 = 0<i1;
          if (!i2) goto l22;
          i2=0;
l17_loop:
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6213))+52);
          i3 = _check_pointer(i3, 6221);
          i4 = OOC_ARRAY_LENGTH(i3, 0);
          i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 6221))*4);
          OOC_SymbolTable_InterfaceXML__Write_WriteItem((OOC_SymbolTable__Item)i3);
          i2 = i2+1;
          j = i2;
          i3 = i2<i1;
          if (i3) goto l17_loop;
l22:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6259))+48);
          i1 = i1!=(OOC_INT32)0;
          if (!i1) goto l25;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6358))+44);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6333))+48);
          OOC_SymbolTable_InterfaceXML__Write_WriteItem_WriteType("result-type", 12, (OOC_SymbolTable__Type)i2, (OOC_SymbolTable__Type)i1);
l25:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6409))+60);
          i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 6416)), 0);
          i1 = i1!=0;
          if (!i1) goto l36;
          i1 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6442)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i1, ((OOC_CHAR16[]){114,97,105,115,101,115,0}), 7, 0u);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6504))+60);
          j = 0;
          i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 6511)), 0);
          i2 = 0<i1;
          if (!i2) goto l35;
          i2=0;
l30_loop:
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6547))+60);
          i3 = _check_pointer(i3, 6554);
          i4 = OOC_ARRAY_LENGTH(i3, 0);
          i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 6554))*4);
          OOC_SymbolTable_InterfaceXML__Write_WriteItem((OOC_SymbolTable__Item)i3);
          i2 = i2+1;
          j = i2;
          i3 = i2<i1;
          if (i3) goto l30_loop;
l35:
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6590)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i0);
l36:
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6625)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i0);
          goto l73;
l38:
          i1 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5486)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i1, ((OOC_CHAR16[]){114,101,99,111,114,100,0}), 7, 0u);
          OOC_SymbolTable_InterfaceXML__Write_WriteItem_ClassAttr((OOC_SymbolTable__Item)i0);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5562))+44);
          i1 = i1!=(OOC_INT32)0;
          if (!i1) goto l41;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5655))+40);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5632))+44);
          OOC_SymbolTable_InterfaceXML__Write_WriteItem_WriteType("base-type", 10, (OOC_SymbolTable__Type)i2, (OOC_SymbolTable__Type)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5700))+40);
          OOC_SymbolTable_InterfaceXML__Write_WriteItem_WriteTypeComponent_WriteBaseClass((OOC_SymbolTable__Record)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5715)))), &_td_OOC_SymbolTable__RecordDesc, 5715)));
l41:
          i0 = (OOC_INT32)type;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5758))+8);
          i = (OOC_SymbolTable__Item)i0;
          i1 = i0!=(OOC_INT32)0;
          if (!i1) goto l52;
l44_loop:
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5820)))), &_td_OOC_SymbolTable__FieldDeclDesc);
          if (!i1) goto l47;
          OOC_SymbolTable_InterfaceXML__Write_WriteItem((OOC_SymbolTable__Item)i0);
l47:
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5906));
          i = (OOC_SymbolTable__Item)i0;
          i1 = i0!=(OOC_INT32)0;
          if (i1) goto l44_loop;
l52:
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5945)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i0);
          goto l73;
l54:
          i1 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5195)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i1, ((OOC_CHAR16[]){97,114,114,97,121,0}), 6, 0u);
          i1 = *(OOC_UINT8*)((_check_pointer(i0, 5242))+40);
          i1 = !i1;
          if (!i1) goto l57;
          i1 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5274)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i1, ((OOC_CHAR16[]){108,101,110,103,116,104,0}), 7, 0u);
          i1 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5317)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i1);
l57:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5382))+48);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5408))+44);
          OOC_SymbolTable_InterfaceXML__Write_WriteItem_WriteType("element-type", 13, (OOC_SymbolTable__Type)i1, (OOC_SymbolTable__Type)i0);
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5435)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i0);
          goto l73;
l59:
          i1 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4998)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i1, ((OOC_CHAR16[]){112,111,105,110,116,101,114,0}), 8, 0u);
          OOC_SymbolTable_InterfaceXML__Write_WriteItem_ClassAttr((OOC_SymbolTable__Item)i0);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5121))+40);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5098))+44);
          OOC_SymbolTable_InterfaceXML__Write_WriteItem_WriteType("pointer-base", 13, (OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5145)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i0);
          goto l73;
l61:
          i1 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4540)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i1, ((OOC_CHAR16[]){116,121,112,101,45,110,97,109,101,0}), 10, 0u);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4591))+40);
          i1 = i1!=(OOC_INT32)0;
          if (i1) goto l71;
          i1 = (OOC_INT32)resolvedType;
          i2 = i1!=(OOC_INT32)0;
          if (i2) goto l66;
          i2=0u;
          goto l68;
l66:
          i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4728)))), &_td_OOC_SymbolTable__PredefTypeDesc);
          
l68:
          if (!i2) goto l72;
          i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4786)))), OOC_SymbolTable__ItemDesc_Module)),OOC_SymbolTable__ItemDesc_Module)((OOC_SymbolTable__Item)i1);
          module = (OOC_SymbolTable__Module)i1;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4847))+20);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 4853))+12);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4847))+20);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4853))+12);
          i3 = (OOC_INT32)w;
          i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 4858)), 0);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 4811)))), XML_Writer__WriterDesc_AttrStringLatin1)),XML_Writer__WriterDesc_AttrStringLatin1)((XML_Writer__Writer)i3, ((OOC_CHAR16[]){109,111,100,117,108,101,0}), 7, (void*)(_check_pointer(i1, 4858)), i2);
          goto l72;
l71:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4659))+40);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4667))+12);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4659))+40);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 4667))+12);
          i3 = (OOC_INT32)w;
          i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 4672)), 0);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 4625)))), XML_Writer__WriterDesc_AttrStringLatin1)),XML_Writer__WriterDesc_AttrStringLatin1)((XML_Writer__Writer)i3, ((OOC_CHAR16[]){109,111,100,117,108,101,0}), 7, (void*)(_check_pointer(i2, 4672)), i1);
l72:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4919))+44);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4926))+12);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4919))+44);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4926))+12);
          i2 = (OOC_INT32)w;
          i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 4931)), 0);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 4887)))), XML_Writer__WriterDesc_AttrStringLatin1)),XML_Writer__WriterDesc_AttrStringLatin1)((XML_Writer__Writer)i2, ((OOC_CHAR16[]){110,97,109,101,0}), 5, (void*)(_check_pointer(i0, 4931)), i1);
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4946)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i0);
l73:
          return;
          ;
        }

        
        void OOC_SymbolTable_InterfaceXML__Write_WriteItem_WriteType(const OOC_CHAR8 tag__ref[], OOC_LEN tag_0d, OOC_SymbolTable__Type type, OOC_SymbolTable__Type resolvedType) {
          register OOC_INT32 i0,i1;
          OOC_ALLOCATE_VPAR(tag,OOC_CHAR8 ,tag_0d)

          OOC_INITIALIZE_VPAR(tag__ref,tag,OOC_CHAR8 ,tag_0d)
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6774)))), XML_Writer__WriterDesc_StartTagLatin1)),XML_Writer__WriterDesc_StartTagLatin1)((XML_Writer__Writer)i0, (void*)(OOC_INT32)tag, tag_0d, 0u);
          i0 = (OOC_INT32)type;
          i1 = (OOC_INT32)resolvedType;
          OOC_SymbolTable_InterfaceXML__Write_WriteItem_WriteTypeComponent((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6863)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i0);
          return;
          ;
        }


      i0 = (OOC_INT32)item;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l65;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6952)))), &_td_OOC_SymbolTable__ModuleDesc);
      if (i1) goto l49;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7547)))), &_td_OOC_SymbolTable__ImportDesc);
      if (i1) goto l44;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8001)))), &_td_OOC_SymbolTable__ConstDeclDesc);
      if (i1) goto l42;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8183)))), &_td_OOC_SymbolTable__TypeDeclDesc);
      if (i1) goto l40;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8380)))), &_td_OOC_SymbolTable__VarDeclDesc);
      if (i1) goto l27;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8905)))), &_td_OOC_SymbolTable__FieldDeclDesc);
      if (i1) goto l25;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9102)))), &_td_OOC_SymbolTable__ProcDeclDesc);
      if (i1) goto l20;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9387)))), &_td_OOC_SymbolTable__ExceptionNameDesc);
      if (!i1) goto l65;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9465))+20);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9447))+24);
      OOC_SymbolTable_InterfaceXML__Write_WriteItem_WriteType("exception", 10, (OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
      goto l65;
l20:
      i1 = *(OOC_UINT8*)((_check_pointer(i0, 9138))+49);
      i1 = !i1;
      if (!i1) goto l65;
      OOC_SymbolTable_InterfaceXML__Write_WriteItem_StartDecl("procedure", 10, (OOC_SymbolTable__Declaration)i0);
      i0 = (OOC_INT32)item;
      OOC_SymbolTable_InterfaceXML__Write_WriteItem_ClassAttr((OOC_SymbolTable__Item)i0);
      i0 = (OOC_INT32)item;
      OOC_SymbolTable_InterfaceXML__Write_WriteItem_DeclDocString((OOC_SymbolTable__Declaration)i0);
      i0 = (OOC_INT32)item;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9320))+64);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9302))+64);
      OOC_SymbolTable_InterfaceXML__Write_WriteItem_WriteTypeComponent((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9348)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i0);
      goto l65;
l25:
      OOC_SymbolTable_InterfaceXML__Write_WriteItem_StartDecl("field-decl", 11, (OOC_SymbolTable__Declaration)i0);
      i0 = (OOC_INT32)item;
      OOC_SymbolTable_InterfaceXML__Write_WriteItem_DeclDocString((OOC_SymbolTable__Declaration)i0);
      i0 = (OOC_INT32)item;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9050))+48);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9031))+52);
      OOC_SymbolTable_InterfaceXML__Write_WriteItem_WriteType("type", 5, (OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9070)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i0);
      goto l65;
l27:
      i1 = *(OOC_UINT8*)((_check_pointer(i0, 8414))+57);
      if (i1) goto l34;
      i1 = *(OOC_UINT8*)((_check_pointer(i0, 8491))+56);
      if (i1) goto l32;
      _copy_8((const void*)"var-decl",(void*)(OOC_INT32)element,32);
      goto l35;
l32:
      _copy_8((const void*)"parameter-decl",(void*)(OOC_INT32)element,32);
      goto l35;
l34:
      _copy_8((const void*)"receiver-decl",(void*)(OOC_INT32)element,32);
l35:
      OOC_SymbolTable_InterfaceXML__Write_WriteItem_StartDecl((void*)(OOC_INT32)element, 32, (OOC_SymbolTable__Declaration)i0);
      i0 = (OOC_INT32)item;
      i1 = *(OOC_UINT8*)((_check_pointer(i0, 8668))+56);
      if (!i1) goto l38;
      i1 = (OOC_INT32)w;
      i2 = *(OOC_UINT8*)((_check_pointer(i0, 8738))+59);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8700)))), XML_Writer__WriterDesc_AttrBool)),XML_Writer__WriterDesc_AttrBool)((XML_Writer__Writer)i1, ((OOC_CHAR16[]){118,97,114,105,97,98,108,101,45,112,97,114,97,109,101,116,101,114,0}), 19, i2);
l38:
      OOC_SymbolTable_InterfaceXML__Write_WriteItem_DeclDocString((OOC_SymbolTable__Declaration)i0);
      i0 = (OOC_INT32)item;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8832))+52);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8851))+48);
      OOC_SymbolTable_InterfaceXML__Write_WriteItem_WriteType("type", 5, (OOC_SymbolTable__Type)i1, (OOC_SymbolTable__Type)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8871)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i0);
      goto l65;
l40:
      OOC_SymbolTable_InterfaceXML__Write_WriteItem_StartDecl("type-decl", 10, (OOC_SymbolTable__Declaration)i0);
      i0 = (OOC_INT32)item;
      OOC_SymbolTable_InterfaceXML__Write_WriteItem_DeclDocString((OOC_SymbolTable__Declaration)i0);
      i0 = (OOC_INT32)item;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8326))+48);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8307))+52);
      OOC_SymbolTable_InterfaceXML__Write_WriteItem_WriteType("type", 5, (OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8346)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i0);
      goto l65;
l42:
      OOC_SymbolTable_InterfaceXML__Write_WriteItem_StartDecl("const-decl", 11, (OOC_SymbolTable__Declaration)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8073)))), XML_Writer__WriterDesc_AttrString)),XML_Writer__WriterDesc_AttrString)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){118,97,108,117,101,0}), 6, ((OOC_CHAR16[]){117,110,107,110,111,119,110,0}), 8);
      i0 = (OOC_INT32)item;
      OOC_SymbolTable_InterfaceXML__Write_WriteItem_DeclDocString((OOC_SymbolTable__Declaration)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8151)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i0);
      goto l65;
l44:
      OOC_SymbolTable_InterfaceXML__Write_WriteItem_StartDecl("import-decl", 12, (OOC_SymbolTable__Declaration)i0);
      i0 = (OOC_INT32)item;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7651))+48);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 7663))+12);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7651))+48);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7663))+12);
      i3 = (OOC_INT32)w;
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 7668)), 0);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 7617)))), XML_Writer__WriterDesc_AttrStringLatin1)),XML_Writer__WriterDesc_AttrStringLatin1)((XML_Writer__Writer)i3, ((OOC_CHAR16[]){109,111,100,117,108,101,0}), 7, (void*)(_check_pointer(i2, 7668)), i1);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7731))+48);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 7743))+12);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7731))+48);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7743))+12);
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 7748)), 0);
      i3 = (OOC_INT32)repositories;
      i1 = (OOC_INT32)OOC_Config_Repositories__SectionDesc_GetModule((OOC_Config_Repositories__Section)i3, (void*)(_check_pointer(i2, 7748)), i1);
      moduleRepository = (OOC_Repository__Module)i1;
      i2 = i1!=(OOC_INT32)0;
      if (!i2) goto l47;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 7885));
      i2 = (OOC_INT32)w;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 7893))+4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 7839)))), XML_Writer__WriterDesc_AttrURI)),XML_Writer__WriterDesc_AttrURI)((XML_Writer__Writer)i2, ((OOC_CHAR16[]){114,101,112,111,115,105,116,111,114,121,45,98,97,115,101,0}), 16, (URI__URI)i1, 0u);
l47:
      OOC_SymbolTable_InterfaceXML__Write_WriteItem_DeclDocString((OOC_SymbolTable__Declaration)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7969)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i0);
      goto l65;
l49:
      OOC_SymbolTable_InterfaceXML__Write_WriteItem_StartDecl("module-interface", 17, (OOC_SymbolTable__Declaration)i0);
      i0 = (OOC_INT32)item;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7075))+20);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 7081))+12);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7075))+20);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7081))+12);
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 7086)), 0);
      i3 = (OOC_INT32)repositories;
      i1 = (OOC_INT32)OOC_Config_Repositories__SectionDesc_GetModule((OOC_Config_Repositories__Section)i3, (void*)(_check_pointer(i2, 7086)), i1);
      moduleRepository = (OOC_Repository__Module)i1;
      i2 = i1!=(OOC_INT32)0;
      if (!i2) goto l52;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 7223));
      i2 = (OOC_INT32)w;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 7231))+4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 7177)))), XML_Writer__WriterDesc_AttrURI)),XML_Writer__WriterDesc_AttrURI)((XML_Writer__Writer)i2, ((OOC_CHAR16[]){114,101,112,111,115,105,116,111,114,121,45,98,97,115,101,0}), 16, (URI__URI)i1, 0u);
l52:
      OOC_SymbolTable_InterfaceXML__Write_WriteItem_DeclDocString((OOC_SymbolTable__Declaration)i0);
      i0 = (OOC_INT32)item;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7326))+8);
      i = (OOC_SymbolTable__Item)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l63;
l55_loop:
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7388)))), &_td_OOC_SymbolTable__DeclarationDesc);
      if (!i1) goto l58;
      OOC_SymbolTable_InterfaceXML__Write_WriteItem((OOC_SymbolTable__Item)i0);
l58:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7476));
      i = (OOC_SymbolTable__Item)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l55_loop;
l63:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7515)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i0);
l65:
      return;
      ;
    }


  i0 = (OOC_INT32)XML_UnicodeCodec_Latin1__factory;
  i1 = (OOC_INT32)cw;
  i0 = (OOC_INT32)XML_Writer__New((IO__ByteChannel)i1, (XML_UnicodeCodec__Factory)i0, 1u, 2);
  w = (XML_Writer__Writer)i0;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9598)))), XML_Writer__WriterDesc_WriteTextDecl)),XML_Writer__WriterDesc_WriteTextDecl)((XML_Writer__Writer)i0, "1.0", 4, "yes", 4);
  i1 = (OOC_INT32)baseURI;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9635)))), XML_Writer__WriterDesc_SetBaseURI)),XML_Writer__WriterDesc_SetBaseURI)((XML_Writer__Writer)i0, (URI__HierarchicalURI)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9664)))), XML_Writer__WriterDesc_NewLine)),XML_Writer__WriterDesc_NewLine)((XML_Writer__Writer)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9680)))), XML_UnicodeBuffer__OutputDesc_Write8)),XML_UnicodeBuffer__OutputDesc_Write8)((XML_UnicodeBuffer__Output)i0, "<!DOCTYPE module-interface SYSTEM \047", 36);
  i1 = (OOC_INT32)repositories;
  i1 = (OOC_INT32)OOC_SymbolTable_InterfaceXML__GetSystemId((OOC_Config_Repositories__Section)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9735)))), XML_Writer__WriterDesc_WriteURI)),XML_Writer__WriterDesc_WriteURI)((XML_Writer__Writer)i0, (URI__URI)i1, 0u);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9788)))), XML_UnicodeBuffer__OutputDesc_Write8)),XML_UnicodeBuffer__OutputDesc_Write8)((XML_UnicodeBuffer__Output)i0, "\047>", 3);
  i0 = (OOC_INT32)module;
  i1 = (OOC_INT32)OOC_SymbolTable_Exports__GetExports((OOC_SymbolTable__Module)i0, 0u);
  OOC_SymbolTable__Prune((OOC_SymbolTable__Module)i0, (ADT_Dictionary_AddressKey__Dictionary)i1);
  OOC_SymbolTable_InterfaceXML__Write_WriteItem((OOC_SymbolTable__Item)i0);
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9894)))), XML_Writer__WriterDesc_EndOfText)),XML_Writer__WriterDesc_EndOfText)((XML_Writer__Writer)i0);
  return;
  ;
}

void OOC_OOC_SymbolTable_InterfaceXML_init(void) {

  OOC_SymbolTable_InterfaceXML__dtdSystemId = (URI__URI)(OOC_INT32)0;
  return;
  ;
}

void OOC_OOC_SymbolTable_InterfaceXML_destroy(void) {
}

/* --- */
