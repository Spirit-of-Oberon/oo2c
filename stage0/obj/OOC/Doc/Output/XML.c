#include <OOC/Doc/Output/XML.d>
#include <__oo2c.h>
#include <setjmp.h>

void OOC_Doc_Output_XML__WriteOberonDoc(XML_Writer__Writer w, OOC_Doc__Document document, OOC_SymbolTable__Module localModule, ADT_Dictionary__Dictionary rewriteMap, OOC_Config_Repositories__Section repositories, ADT_Dictionary__Dictionary moduleDict) {
  register OOC_INT32 i0,i1,i2;
  auto void OOC_Doc_Output_XML__WriteOberonDoc_AttrExternalHref(OOC_Scanner_InputBuffer__CharArray module, OOC_Scanner_InputBuffer__CharArray id);
  auto void OOC_Doc_Output_XML__WriteOberonDoc_AttrHref(OOC_SymbolTable__Declaration target);
  auto void OOC_Doc_Output_XML__WriteOberonDoc_InlineList(OOC_Doc__InlineElement inlineList);
  auto void OOC_Doc_Output_XML__WriteOberonDoc_BlockList(OOC_Doc__BlockElement blockList);
    
    void OOC_Doc_Output_XML__WriteOberonDoc_AttrExternalHref(OOC_Scanner_InputBuffer__CharArray module, OOC_Scanner_InputBuffer__CharArray id) {
      register OOC_INT32 i0,i1,i2;
      OOC_CHAR8 str[2048];
      OOC_Repository__Module repModule;

      i0 = (OOC_INT32)localModule;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l3;
      i0=0u;
      goto l5;
l3:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1739))+20);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1745))+12);
      i1 = (OOC_INT32)module;
      i0 = (
      _cmp8((const void*)(_check_pointer(i0, 1750)),(const void*)(_check_pointer(i1, 1760))))==0;
      
l5:
      if (i0) goto l17;
      i0 = (OOC_INT32)moduleDict;
      i1 = (OOC_INT32)module;
      i0 = i0!=(OOC_INT32)0;
      if (i0) goto l9;
      i0=0u;
      goto l11;
l9:
      i0 = (OOC_INT32)repositories;
      i0 = i0!=(OOC_INT32)0;
      
l11:
      if (!i0) goto l16;
      i0 = OOC_ARRAY_LENGTH((_check_pointer(i1, 1914)), 0);
      i2 = (OOC_INT32)repositories;
      i0 = (OOC_INT32)OOC_Config_Repositories__SectionDesc_GetModule((OOC_Config_Repositories__Section)i2, (void*)(_check_pointer(i1, 1914)), i0);
      repModule = (OOC_Repository__Module)i0;
      i2 = i0!=(OOC_INT32)0;
      if (!i2) goto l16;
      i2 = (OOC_INT32)moduleDict;
      ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i2, (Object__Object)i0, (Object__Object)(OOC_INT32)0);
l16:
      _copy_8((const void*)(_check_pointer(i1, 2046)),(void*)(OOC_INT32)str,2048);
      goto l18;
l17:
      _copy_8((const void*)"",(void*)(OOC_INT32)str,2048);
l18:
      Strings__Append("#", 2, (void*)(OOC_INT32)str, 2048);
      i0 = (OOC_INT32)id;
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 2122)), 0);
      Strings__Append((void*)(_check_pointer(i0, 2122)), i1, (void*)(OOC_INT32)str, 2048);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2138)))), XML_Writer__WriterDesc_AttrStringLatin1)),XML_Writer__WriterDesc_AttrStringLatin1)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){104,114,101,102,0}), 5, (void*)(OOC_INT32)str, 2048);
      return;
      ;
    }

    
    void OOC_Doc_Output_XML__WriteOberonDoc_AttrHref(OOC_SymbolTable__Declaration target) {
      register OOC_INT32 i0,i1;
      OOC_SymbolTable__Module module;

      i0 = (OOC_INT32)target;
      i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2314)))), OOC_SymbolTable__ItemDesc_Module)),OOC_SymbolTable__ItemDesc_Module)((OOC_SymbolTable__Item)i0);
      module = (OOC_SymbolTable__Module)i1;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2356))+20);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2362))+12);
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2375)))), OOC_SymbolTable__DeclarationDesc_GetId)),OOC_SymbolTable__DeclarationDesc_GetId)((OOC_SymbolTable__Declaration)i0);
      OOC_Doc_Output_XML__WriteOberonDoc_AttrExternalHref((OOC_Scanner_InputBuffer__CharArray)i1, (OOC_Scanner_InputBuffer__CharArray)i0);
      return;
      ;
    }

    
    void OOC_Doc_Output_XML__WriteOberonDoc_InlineList(OOC_Doc__InlineElement inlineList) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
      OOC_Doc__InlineElement _inline;
      OOC_CHAR8 name[32];
      Object__Object rewrittenTo;
      auto OOC_INT32 OOC_Doc_Output_XML__WriteOberonDoc_InlineList_AsteriskPrefix(OOC_CHAR8 str[], OOC_LEN str_0d);
        
        OOC_INT32 OOC_Doc_Output_XML__WriteOberonDoc_InlineList_AsteriskPrefix(OOC_CHAR8 str[], OOC_LEN str_0d) {
          register OOC_INT32 i0,i1;

          i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT32, 2713)));
          i0 = i0!=0u;
          if (i0) goto l3;
          i0=0u;
          goto l5;
l3:
          i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT32, 2729)));
          i0 = (OOC_UINT8)i0<=(OOC_UINT8)32u;
          
l5:
          if (i0) goto l7;
          i0=0;
          goto l17;
l7:
          i0=0;
l8_loop:
          i0 = i0+1;
          i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 2713)));
          i1 = i1!=0u;
          if (i1) goto l11;
          i1=0u;
          goto l13;
l11:
          i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 2729)));
          i1 = (OOC_UINT8)i1<=(OOC_UINT8)32u;
          
l13:
          if (i1) goto l8_loop;
l17:
          i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 2790)));
          i1 = i1==42u;
          if (i1) goto l20;
          return (-1);
          goto l21;
l20:
          return (i0+1);
l21:
          _failed_function(2587); return 0;
          ;
        }


      i0 = (OOC_INT32)inlineList;
      _inline = (OOC_Doc__InlineElement)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l77;
      
l3_loop:
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2985)))), OOC_Doc__ElementDesc_NodeName)),OOC_Doc__ElementDesc_NodeName)((OOC_Doc__Element)i0, (void*)(OOC_INT32)name, 32);
      i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3024)))), &_td_OOC_Doc__TextDesc));
      if (!i1) goto l6;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3053)))), XML_Writer__WriterDesc_StartTagLatin1)),XML_Writer__WriterDesc_StartTagLatin1)((XML_Writer__Writer)i1, (void*)(OOC_INT32)name, 32, 1u);
l6:
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3115)))), &_td_OOC_Doc__GlyphDesc);
      if (i1) goto l69;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3185)))), &_td_OOC_Doc__OberonRefDesc);
      if (i1) goto l36;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4454)))), &_td_OOC_Doc__MarkedInlineDesc);
      if (i1) goto l34;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4535)))), &_td_OOC_Doc__TextDesc);
      if (i1) goto l32;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4609)))), &_td_OOC_Doc__UrefDesc);
      if (i1) goto l24;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5089)))), &_td_OOC_Doc__EmailDesc);
      if (i1) goto l19;
      _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5081)))), 5081);
      goto l69;
l19:
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5115)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i1, ((OOC_CHAR16[]){101,109,97,105,108,45,97,100,100,114,101,115,115,0}), 14, 1u);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5179))+16);
      OOC_Doc_Output_XML__WriteOberonDoc_InlineList((OOC_Doc__InlineElement)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5202)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i1);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5232))+20);
      i1 = i1!=(OOC_INT32)0;
      if (!i1) goto l69;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5269)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i1, ((OOC_CHAR16[]){101,109,97,105,108,45,100,105,115,112,108,97,121,101,100,45,116,101,120,116,0}), 21, 1u);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5342))+20);
      OOC_Doc_Output_XML__WriteOberonDoc_InlineList((OOC_Doc__InlineElement)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5369)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i1);
      goto l69;
l24:
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4634)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i1, ((OOC_CHAR16[]){117,114,101,102,45,117,114,108,0}), 9, 1u);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4693))+16);
      OOC_Doc_Output_XML__WriteOberonDoc_InlineList((OOC_Doc__InlineElement)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4712)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i1);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4742))+20);
      i1 = i1!=(OOC_INT32)0;
      if (!i1) goto l27;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4774)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i1, ((OOC_CHAR16[]){117,114,101,102,45,116,101,120,116,0}), 10, 1u);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4836))+20);
      OOC_Doc_Output_XML__WriteOberonDoc_InlineList((OOC_Doc__InlineElement)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4858)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i1);
l27:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4902))+24);
      i1 = i1!=(OOC_INT32)0;
      if (!i1) goto l69;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4941)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i1, ((OOC_CHAR16[]){117,114,101,102,45,114,101,112,108,97,99,101,109,101,110,116,0}), 17, 1u);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5010))+24);
      OOC_Doc_Output_XML__WriteOberonDoc_InlineList((OOC_Doc__InlineElement)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5039)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i1);
      goto l69;
l32:
      i1 = (OOC_INT32)w;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4581))+16);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4581))+16);
      i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 4589)), 0);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4560)))), XML_Writer__WriterDesc_WriteLatin1)),XML_Writer__WriterDesc_WriteLatin1)((XML_Writer__Writer)i1, (void*)(_check_pointer(i2, 4589)), i3);
      goto l69;
l34:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4504))+20);
      OOC_Doc_Output_XML__WriteOberonDoc_InlineList((OOC_Doc__InlineElement)i1);
      goto l69;
l36:
      rewrittenTo = (Object__Object)(OOC_INT32)0;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3254))+24);
      i1 = i1!=(OOC_INT32)0;
      if (i1) goto l42;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3643))+28);
      i1 = i1!=(OOC_INT32)0;
      if (!i1) goto l41;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3708))+28);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3732))+32);
      OOC_Doc_Output_XML__WriteOberonDoc_AttrExternalHref((OOC_Scanner_InputBuffer__CharArray)i1, (OOC_Scanner_InputBuffer__CharArray)i2);
l41:
      i1=(OOC_INT32)0;
      goto l51;
l42:
      i1 = (OOC_INT32)rewriteMap;
      i2 = i1!=(OOC_INT32)0;
      if (i2) goto l45;
      i1=0u;
      goto l47;
l45:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3337))+24);
      i1 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i1, (Object__Object)i2);
      
l47:
      if (i1) goto l49;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3577))+24);
      OOC_Doc_Output_XML__WriteOberonDoc_AttrHref((OOC_SymbolTable__Declaration)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3590)))), &_td_OOC_SymbolTable__DeclarationDesc, 3590)));
      i1=(OOC_INT32)0;
      goto l51;
l49:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3465))+24);
      i2 = (OOC_INT32)rewriteMap;
      i1 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i2, (Object__Object)i1);
      rewrittenTo = (Object__Object)i1;
      OOC_Doc_Output_XML__WriteOberonDoc_AttrHref((OOC_SymbolTable__Declaration)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3516)))), &_td_OOC_SymbolTable__DeclarationDesc, 3516)));
      
l51:
      i2 = i1!=(OOC_INT32)0;
      if (i2) goto l66;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3903))+20);
      i1 = i1!=(OOC_INT32)0;
      if (i1) goto l56;
      i1=0u;
      goto l58;
l56:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3946))+20);
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3959)))), &_td_OOC_Doc__TextDesc);
      
l58:
      if (i1) goto l60;
      i1=0u;
      goto l62;
l60:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4010))+20);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4027)))), &_td_OOC_Doc__TextDesc, 4027)), 4032))+16);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4010))+20);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 4027)))), &_td_OOC_Doc__TextDesc, 4027)), 4032))+16);
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 4040)), 0);
      i1 = OOC_Doc_Output_XML__WriteOberonDoc_InlineList_AsteriskPrefix((void*)(_check_pointer(i1, 4040)), i2);
      i1 = i1>=0;
      
l62:
      if (i1) goto l64;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4401))+20);
      OOC_Doc_Output_XML__WriteOberonDoc_InlineList((OOC_Doc__InlineElement)i1);
      goto l69;
l64:
      i1 = (OOC_INT32)w;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4163))+20);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 4180)))), &_td_OOC_Doc__TextDesc, 4180)), 4185))+16);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4163))+20);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 4180)))), &_td_OOC_Doc__TextDesc, 4180)), 4185))+16);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4242))+20);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 4259)))), &_td_OOC_Doc__TextDesc, 4259)), 4264))+16);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4242))+20);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i5, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 4259)))), &_td_OOC_Doc__TextDesc, 4259)), 4264))+16);
      i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 4272)), 0);
      i4 = OOC_Doc_Output_XML__WriteOberonDoc_InlineList_AsteriskPrefix((void*)(_check_pointer(i4, 4272)), i5);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4322))+20);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i5, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 4339)))), &_td_OOC_Doc__TextDesc, 4339)), 4344))+16);
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4322))+20);
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i6, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 4339)))), &_td_OOC_Doc__TextDesc, 4339)), 4344))+16);
      i6 = OOC_ARRAY_LENGTH((_check_pointer(i6, 4352)), 0);
      i5 = Strings__Length((void*)(_check_pointer(i5, 4352)), i6);
      i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 4193)), 0);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4141)))), XML_Writer__WriterDesc_WriteLatin1I)),XML_Writer__WriterDesc_WriteLatin1I)((XML_Writer__Writer)i1, (void*)(_check_pointer(i2, 4193)), i3, i4, i5);
      goto l69;
l66:
      i2 = (OOC_INT32)w;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3854)))), &_td_OOC_SymbolTable__DeclarationDesc, 3854)), 3866))+20);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 3872))+12);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3854)))), &_td_OOC_SymbolTable__DeclarationDesc, 3854)), 3866))+20);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3872))+12);
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 3877)), 0);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 3823)))), XML_Writer__WriterDesc_WriteLatin1)),XML_Writer__WriterDesc_WriteLatin1)((XML_Writer__Writer)i2, (void*)(_check_pointer(i3, 3877)), i1);
l69:
      i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5426)))), &_td_OOC_Doc__TextDesc));
      if (!i1) goto l72;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5455)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i1);
l72:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5501))+12);
      _inline = (OOC_Doc__InlineElement)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l3_loop;
l77:
      return;
      ;
    }

    
    void OOC_Doc_Output_XML__WriteOberonDoc_BlockList(OOC_Doc__BlockElement blockList) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_Doc__BlockElement block;
      OOC_CHAR8 name[32];

      i0 = (OOC_INT32)blockList;
      block = (OOC_Doc__BlockElement)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l68;
      
l3_loop:
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5745)))), OOC_Doc__ElementDesc_NodeName)),OOC_Doc__ElementDesc_NodeName)((OOC_Doc__Element)i0, (void*)(OOC_INT32)name, 32);
      i1 = (OOC_INT32)w;
      i2 = _check_pointer(i1, 5773);
      i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5804)))), &_td_OOC_Doc__ParagraphDesc);
      if (i3) goto l6;
      i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5865)))), &_td_OOC_Doc__ExampleDesc);
      
      goto l8;
l6:
      i3=1u;
l8:
      if (i3) goto l10;
      i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5924)))), &_td_OOC_Doc__FirstColumnDesc);
      
      goto l11;
l10:
      i3=1u;
l11:
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i2)), XML_Writer__WriterDesc_StartTagLatin1)),XML_Writer__WriterDesc_StartTagLatin1)((XML_Writer__Writer)i1, (void*)(OOC_INT32)name, 32, i3);
      i1 = (OOC_INT32)w;
      i2 = *(OOC_UINT8*)((_check_pointer(i0, 5985))+16);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5955)))), XML_Writer__WriterDesc_AttrBool)),XML_Writer__WriterDesc_AttrBool)((XML_Writer__Writer)i1, ((OOC_CHAR16[]){112,97,100,45,97,102,116,101,114,0}), 10, i2);
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6016)))), &_td_OOC_Doc__ParagraphDesc);
      if (i1) goto l62;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6146)))), &_td_OOC_Doc__ExampleDesc);
      if (i1) goto l60;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6220)))), &_td_OOC_Doc__PreCondDesc);
      if (i1) goto l58;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6292)))), &_td_OOC_Doc__PostCondDesc);
      if (i1) goto l56;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6365)))), &_td_OOC_Doc__ItemDesc);
      if (i1) goto l54;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6434)))), &_td_OOC_Doc__ItemizeDesc);
      if (i1) goto l49;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6780)))), &_td_OOC_Doc__EnumerateDesc);
      if (i1) goto l38;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7312)))), &_td_OOC_Doc__FirstColumnDesc);
      if (i1) goto l36;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7390)))), &_td_OOC_Doc__TableRowDesc);
      if (i1) goto l34;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7504)))), &_td_OOC_Doc__TableDesc);
      if (i1) goto l32;
      _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7497)))), 7497);
      goto l63;
l32:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7545))+20);
      OOC_Doc_Output_XML__WriteOberonDoc_BlockList((OOC_Doc__BlockElement)i1);
      goto l63;
l34:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7434))+20);
      OOC_Doc_Output_XML__WriteOberonDoc_BlockList((OOC_Doc__BlockElement)i1);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7480))+24);
      OOC_Doc_Output_XML__WriteOberonDoc_BlockList((OOC_Doc__BlockElement)i1);
      goto l63;
l36:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7360))+20);
      OOC_Doc_Output_XML__WriteOberonDoc_InlineList((OOC_Doc__InlineElement)i1);
      goto l63;
l38:
      i1 = *(OOC_INT8*)((_check_pointer(i0, 6819))+20);
      switch (i1) {
      case 0:
        i1 = (OOC_INT32)w;
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6860)))), XML_Writer__WriterDesc_AttrString)),XML_Writer__WriterDesc_AttrString)((XML_Writer__Writer)i1, ((OOC_CHAR16[]){109,111,100,101,0}), 5, ((OOC_CHAR16[]){110,117,109,98,101,114,0}), 7);
        goto l44;
      case 1:
        i1 = (OOC_INT32)w;
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6923)))), XML_Writer__WriterDesc_AttrString)),XML_Writer__WriterDesc_AttrString)((XML_Writer__Writer)i1, ((OOC_CHAR16[]){109,111,100,101,0}), 5, ((OOC_CHAR16[]){108,111,119,101,114,99,97,115,101,0}), 10);
        goto l44;
      case 2:
        i1 = (OOC_INT32)w;
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6989)))), XML_Writer__WriterDesc_AttrString)),XML_Writer__WriterDesc_AttrString)((XML_Writer__Writer)i1, ((OOC_CHAR16[]){109,111,100,101,0}), 5, ((OOC_CHAR16[]){117,112,112,101,114,99,97,115,101,0}), 10);
        goto l44;
      default:
        _failed_case(i1, 6809);
        goto l44;
      }
l44:
      i1 = (OOC_INT32)w;
      i2 = *(OOC_INT32*)((_check_pointer(i0, 7074))+24);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7049)))), XML_Writer__WriterDesc_AttrInt)),XML_Writer__WriterDesc_AttrInt)((XML_Writer__Writer)i1, ((OOC_CHAR16[]){115,116,97,114,116,0}), 6, i2);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7103))+28);
      i1 = i1!=(OOC_INT32)0;
      if (!i1) goto l47;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7135)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i1, ((OOC_CHAR16[]){101,110,117,109,101,114,97,116,101,45,116,101,120,116,0}), 15, 0u);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7201))+28);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 7207))+20);
      OOC_Doc_Output_XML__WriteOberonDoc_BlockList((OOC_Doc__BlockElement)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7234)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i1);
l47:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7284))+32);
      OOC_Doc_Output_XML__WriteOberonDoc_BlockList((OOC_Doc__BlockElement)i1);
      goto l63;
l49:
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6462)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i1, ((OOC_CHAR16[]){105,116,101,109,105,122,101,45,109,97,114,107,0}), 13, 1u);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6524))+20);
      OOC_Doc_Output_XML__WriteOberonDoc_InlineList((OOC_Doc__InlineElement)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6544)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i1);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6573))+24);
      i1 = i1!=(OOC_INT32)0;
      if (!i1) goto l52;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6605)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i1, ((OOC_CHAR16[]){105,116,101,109,105,122,101,45,116,101,120,116,0}), 13, 0u);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6669))+24);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6675))+20);
      OOC_Doc_Output_XML__WriteOberonDoc_BlockList((OOC_Doc__BlockElement)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6702)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i1);
l52:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6752))+28);
      OOC_Doc_Output_XML__WriteOberonDoc_BlockList((OOC_Doc__BlockElement)i1);
      goto l63;
l54:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6405))+20);
      OOC_Doc_Output_XML__WriteOberonDoc_BlockList((OOC_Doc__BlockElement)i1);
      goto l63;
l56:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6336))+20);
      OOC_Doc_Output_XML__WriteOberonDoc_BlockList((OOC_Doc__BlockElement)i1);
      goto l63;
l58:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6263))+20);
      OOC_Doc_Output_XML__WriteOberonDoc_BlockList((OOC_Doc__BlockElement)i1);
      goto l63;
l60:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6190))+20);
      OOC_Doc_Output_XML__WriteOberonDoc_InlineList((OOC_Doc__InlineElement)i1);
      goto l63;
l62:
      i1 = (OOC_INT32)w;
      i2 = *(OOC_UINT8*)((_check_pointer(i0, 6076))+24);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6046)))), XML_Writer__WriterDesc_AttrBool)),XML_Writer__WriterDesc_AttrBool)((XML_Writer__Writer)i1, ((OOC_CHAR16[]){110,111,45,105,110,100,101,110,116,0}), 10, i2);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6116))+20);
      OOC_Doc_Output_XML__WriteOberonDoc_InlineList((OOC_Doc__InlineElement)i1);
l63:
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7578)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i1);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7610))+12);
      block = (OOC_Doc__BlockElement)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l3_loop;
l68:
      return;
      ;
    }


  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7665)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){111,98,101,114,111,110,45,100,111,99,0}), 11, 0u);
  i1 = (OOC_INT32)document;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 7715))+4);
  i2 = i2!=(OOC_INT32)0;
  if (!i2) goto l3;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7744)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){115,117,109,109,97,114,121,0}), 8, 1u);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 7800))+4);
  OOC_Doc_Output_XML__WriteOberonDoc_InlineList((OOC_Doc__InlineElement)i0);
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7819)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i0);
l3:
  i0 = (OOC_INT32)document;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7860));
  OOC_Doc_Output_XML__WriteOberonDoc_BlockList((OOC_Doc__BlockElement)i0);
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7879)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i0);
  return;
  ;
}

void OOC_Doc_Output_XML__Write(IO__ByteChannel cw, OOC_Doc__Document document, OOC_SymbolTable__Module localModule, ADT_Dictionary__Dictionary rewriteMap, OOC_Config_Repositories__Section repositories, ADT_Dictionary__Dictionary moduleDict) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  XML_Writer__Writer w;

  i0 = (OOC_INT32)cw;
  i1 = (OOC_INT32)XML_UnicodeCodec_Latin1__factory;
  i0 = (OOC_INT32)XML_Writer__New((IO__ByteChannel)i0, (XML_UnicodeCodec__Factory)i1, 1u, 2);
  w = (XML_Writer__Writer)i0;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8285)))), XML_Writer__WriterDesc_WriteTextDecl)),XML_Writer__WriterDesc_WriteTextDecl)((XML_Writer__Writer)i0, "1.0", 4, "yes", 4);
  i1 = (OOC_INT32)document;
  i2 = (OOC_INT32)localModule;
  i3 = (OOC_INT32)rewriteMap;
  i4 = (OOC_INT32)repositories;
  i5 = (OOC_INT32)moduleDict;
  OOC_Doc_Output_XML__WriteOberonDoc((XML_Writer__Writer)i0, (OOC_Doc__Document)i1, (OOC_SymbolTable__Module)i2, (ADT_Dictionary__Dictionary)i3, (OOC_Config_Repositories__Section)i4, (ADT_Dictionary__Dictionary)i5);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8427)))), XML_Writer__WriterDesc_EndOfText)),XML_Writer__WriterDesc_EndOfText)((XML_Writer__Writer)i0);
  return;
  ;
}

void OOC_OOC_Doc_Output_XML_init(void) {

  return;
  ;
}

/* --- */
