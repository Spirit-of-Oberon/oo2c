#include <OOC/Config/Repositories.d>
#include <__oo2c.h>
#include <setjmp.h>

void OOC_Config_Repositories__ErrorContextDesc_GetTemplate(OOC_Config_Repositories__ErrorContext context, Msg__Msg msg, Msg__LString templ, OOC_LEN templ_0d) {
  register OOC_INT32 i0,i1;
  OOC_CHAR16 t[128];

  i0 = (OOC_INT32)msg;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 1971))+8);
  switch (i1) {
  case 1:
    _copy_16((const void*)((OOC_CHAR16[]){73,110,118,97,108,105,100,32,99,111,110,116,101,110,116,32,102,111,114,32,101,108,101,109,101,110,116,32,96,36,123,110,97,109,101,125,39,0}),(void*)(OOC_INT32)t,128);
    goto l6;
  case 2:
    _copy_16((const void*)((OOC_CHAR16[]){65,116,116,114,105,98,117,116,101,32,96,36,123,110,97,109,101,125,39,32,105,115,32,110,111,116,32,100,101,102,105,110,101,100,32,102,111,114,32,116,104,105,115,32,101,108,101,109,101,110,116,0}),(void*)(OOC_INT32)t,128);
    goto l6;
  case 3:
    _copy_16((const void*)((OOC_CHAR16[]){84,104,105,115,32,101,108,101,109,101,110,116,32,109,117,115,116,32,98,101,32,101,109,112,116,121,0}),(void*)(OOC_INT32)t,128);
    goto l6;
  default:
    _failed_case(i1, 1963);
    goto l6;
  }
l6:
  i1 = (OOC_INT32)context;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2223)))), XML_Error__ContextDesc_WriteTemplate)),XML_Error__ContextDesc_WriteTemplate)((XML_Error__Context)i1, (Msg__Msg)i0, (void*)(OOC_INT32)t, 128, (void*)(OOC_INT32)templ, templ_0d);
  return;
  ;
}

static void OOC_Config_Repositories__Init(OOC_Config_Repositories__Section s, const Config_Parser__String id__ref, OOC_LEN id_0d) {
  register OOC_INT32 i0;
  OOC_ALLOCATE_VPAR(id,OOC_CHAR16 ,id_0d)

  OOC_INITIALIZE_VPAR(id__ref,id,OOC_CHAR16 ,(id_0d*2))
  i0 = (OOC_INT32)s;
  Config_Section__Init((Config_Section__Section)i0, (void*)(OOC_INT32)id, id_0d);
  *(OOC_INT32*)((_check_pointer(i0, 2359))+4) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i0, 2391))+8) = ((OOC_INT32)RT0__NewObject(_td_OOC_Config_Repositories__ModuleList.baseTypes[0], 64));
  *(OOC_INT32*)((_check_pointer(i0, 2410))+12) = 0;
  return;
  ;
}

OOC_Config_Repositories__Section OOC_Config_Repositories__New(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Config_Repositories__Section.baseTypes[0]);
  OOC_Config_Repositories__Init((OOC_Config_Repositories__Section)i0, ((OOC_CHAR16[]){114,101,112,111,115,105,116,111,114,105,101,115,0}), 13);
  return (OOC_Config_Repositories__Section)i0;
  ;
}

void OOC_Config_Repositories__InitRepositoryEntry(OOC_Config_Repositories__RepositoryEntry re, const OOC_CHAR8 name__ref[], OOC_LEN name_0d) {
  register OOC_INT32 i0;
  OOC_ALLOCATE_VPAR(name,OOC_CHAR8 ,name_0d)

  OOC_INITIALIZE_VPAR(name__ref,name,OOC_CHAR8 ,name_0d)
  i0 = (OOC_INT32)re;
  *(OOC_INT32*)(_check_pointer(i0, 2694)) = 0;
  _copy_8to16((const void*)(OOC_INT32)name,(void*)((_check_pointer(i0, 2727))+4),32);
  return;
  ;
}

OOC_Repository__Repository OOC_Config_Repositories__RepositoryEntryDesc_ProcessElement(OOC_Config_Repositories__RepositoryEntry re, Config_Parser__Element node, XML_Locator__ErrorListener errorListener, OOC_Repository__Repository baseRep) {

  _failed_function(2807); return 0;
  ;
}

void OOC_Config_Repositories__AddRepositoryEntry(OOC_Config_Repositories__RepositoryEntry re) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)re;
  i1 = (OOC_INT32)OOC_Config_Repositories__repositoryEntries;
  *(OOC_INT32*)(_check_pointer(i0, 3103)) = i1;
  OOC_Config_Repositories__repositoryEntries = (OOC_Config_Repositories__RepositoryEntry)i0;
  return;
  ;
}

void OOC_Config_Repositories__SectionDesc_ProcessElements(OOC_Config_Repositories__Section s, Config_Parser__Element sectionRoot, XML_Locator__ErrorListener errorListener) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  Config_Parser__Node node;
  OOC_Config_Repositories__RepositoryEntry re;
  OOC_Repository__Repository rep;
  Msg__Msg lastError;
  auto void OOC_Config_Repositories__SectionDesc_ProcessElements_Err(OOC_INT32 code, Config_Parser__Node xmlNode);
    
    void OOC_Config_Repositories__SectionDesc_ProcessElements_Err(OOC_INT32 code, Config_Parser__Node xmlNode) {
      register OOC_INT32 i0,i1,i2,i3;

      i0 = (OOC_INT32)xmlNode;
      i1 = (OOC_INT32)errorListener;
      i2 = (OOC_INT32)OOC_Config_Repositories__repositoriesContext;
      i3 = code;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3552)))), XML_Locator__ErrorListenerDesc_Error)),XML_Locator__ErrorListenerDesc_Error)((XML_Locator__ErrorListener)i1, (XML_Error__Context)i2, i3, 0u, (void*)((_check_pointer(i0, 3602))+4));
      lastError = (Msg__Msg)i0;
      return;
      ;
    }


  i0 = (OOC_INT32)sectionRoot;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3656))+36);
  node = (Config_Parser__Node)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l43;
l3_loop:
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3708)))), &_td_Config_Parser__ElementDesc);
  if (i1) goto l13;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4204)))), &_td_Config_Parser__CharDataDesc);
  if (i1) goto l8;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4198)))), 4198);
  goto l38;
l8:
  i1 = Config_Parser__NodeDesc_IsWhitespace((Config_Parser__Node)i0);
  i1 = !i1;
  if (!i1) goto l38;
  OOC_Config_Repositories__SectionDesc_ProcessElements_Err(1, (Config_Parser__Node)i0);
  goto l38;
l13:
  i1 = (OOC_INT32)OOC_Config_Repositories__repositoryEntries;
  re = (OOC_Config_Repositories__RepositoryEntry)i1;
  i2 = i1!=(OOC_INT32)0;
  if (i2) goto l16;
  i2=0u;
  goto l18;
l16:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3804))+28);
  i2 = (
  _cmp16((const void*)((_check_pointer(i1, 3791))+4),(const void*)(_check_pointer(i2, 3810))))!=0;
  
l18:
  if (!i2) goto l30;
l21_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 3834));
  re = (OOC_Config_Repositories__RepositoryEntry)i1;
  i2 = i1!=(OOC_INT32)0;
  if (i2) goto l24;
  i2=0u;
  goto l26;
l24:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3804))+28);
  i2 = (
  _cmp16((const void*)((_check_pointer(i1, 3791))+4),(const void*)(_check_pointer(i2, 3810))))!=0;
  
l26:
  if (i2) goto l21_loop;
l30:
  i2 = i1!=(OOC_INT32)0;
  if (i2) goto l33;
  OOC_Config_Repositories__SectionDesc_ProcessElements_Err(1, (Config_Parser__Node)i0);
  i0 = (OOC_INT32)s;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4161));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4161));
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 4167)), 0);
  i0 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i0, 4167)), i1);
  i1 = (OOC_INT32)lastError;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4113)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i1, "name", 5, (Msg__LStringPtr)i0);
  goto l38;
l33:
  i2 = (OOC_INT32)s;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 3949))+4);
  i4 = (OOC_INT32)errorListener;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3909)))), OOC_Config_Repositories__RepositoryEntryDesc_ProcessElement)),OOC_Config_Repositories__RepositoryEntryDesc_ProcessElement)((OOC_Config_Repositories__RepositoryEntry)i1, (Config_Parser__Element)i0, (XML_Locator__ErrorListener)i4, (OOC_Repository__Repository)i3);
  rep = (OOC_Repository__Repository)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l38;
  *(OOC_INT32*)((_check_pointer(i2, 4008))+4) = i0;
l38:
  i0 = (OOC_INT32)node;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4341));
  node = (Config_Parser__Node)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3_loop;
l43:
  return;
  ;
}

void OOC_Config_Repositories__SectionDesc_DumpContent(OOC_Config_Repositories__Section s, Channel__Channel ch) {
  register OOC_INT32 i0,i1,i2,i3;
  TextRider__Writer w;
  OOC_CHAR8 str8[2048];
  auto void OOC_Config_Repositories__SectionDesc_DumpContent_Write(OOC_Repository__Repository rep);
    
    void OOC_Config_Repositories__SectionDesc_DumpContent_Write(OOC_Repository__Repository rep) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)rep;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l4;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4609));
      OOC_Config_Repositories__SectionDesc_DumpContent_Write((OOC_Repository__Repository)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4632)))), OOC_Repository__RepositoryDesc_DumpContent)),OOC_Repository__RepositoryDesc_DumpContent)((OOC_Repository__Repository)i0, (TextRider__Writer)i1);
l4:
      return;
      ;
    }


  i0 = (OOC_INT32)ch;
  i0 = (OOC_INT32)TextRider__ConnectWriter((Channel__Channel)i0);
  w = (TextRider__Writer)i0;
  i1 = (OOC_INT32)s;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 4749));
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 4749));
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 4755)), 0);
  LongStrings__Short((void*)(_check_pointer(i3, 4755)), i2, 63u, (void*)(OOC_INT32)str8, 2048);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4775)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, "<", 2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4801)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (void*)(OOC_INT32)str8, 2048);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4828)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, ">", 2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4850)))), TextRider__WriterDesc_WriteLn)),TextRider__WriterDesc_WriteLn)((TextRider__Writer)i0);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4873))+4);
  OOC_Config_Repositories__SectionDesc_DumpContent_Write((OOC_Repository__Repository)i0);
  i0 = (OOC_INT32)s;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4913));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4913));
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 4919)), 0);
  LongStrings__Short((void*)(_check_pointer(i0, 4919)), i1, 63u, (void*)(OOC_INT32)str8, 2048);
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4939)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, "</", 3);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4966)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (void*)(OOC_INT32)str8, 2048);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4993)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, ">", 2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5015)))), TextRider__WriterDesc_WriteLn)),TextRider__WriterDesc_WriteLn)((TextRider__Writer)i0);
  return;
  ;
}

OOC_Repository__Module OOC_Config_Repositories__SectionDesc_GetModule(OOC_Config_Repositories__Section s, const OOC_CHAR8 moduleRef__ref[], OOC_LEN moduleRef_0d) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_ALLOCATE_VPAR(moduleRef,OOC_CHAR8 ,moduleRef_0d)
  OOC_INT32 i;
  OOC_Repository__Repository topLevelRep;
  OOC_Repository__Module m;
  URI_Scheme_File__URI file;
  auto void OOC_Config_Repositories__SectionDesc_GetModule_AddToCache(OOC_Repository__Module m);
    
    void OOC_Config_Repositories__SectionDesc_GetModule_AddToCache(OOC_Repository__Module m) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
      OOC_Config_Repositories__ModuleList _new;
      OOC_INT32 i;

      i0 = (OOC_INT32)m;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l14;
      i1 = (OOC_INT32)s;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6797))+8);
      i3 = *(OOC_INT32*)((_check_pointer(i1, 6778))+12);
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 6804)), 0);
      i2 = i3==i2;
      if (!i2) goto l13;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6839))+8);
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 6846)), 0);
      i2 = (OOC_INT32)RT0__NewObject(_td_OOC_Config_Repositories__ModuleList.baseTypes[0], (i2*2));
      _new = (OOC_Config_Repositories__ModuleList)i2;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6883))+8);
      i = 0;
      i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 6890)), 0);
      i4 = 0<i3;
      if (!i4) goto l12;
      i4=0;
l7_loop:
      i5 = _check_pointer(i2, 6913);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6921))+8);
      i7 = _check_pointer(i7, 6928);
      i8 = OOC_ARRAY_LENGTH(i7, 0);
      i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i4, i8, OOC_UINT32, 6928))*4);
      *(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 6913))*4) = i7;
      i4 = i4+1;
      i = i4;
      i5 = i4<i3;
      if (i5) goto l7_loop;
l12:
      *(OOC_INT32*)((_check_pointer(i1, 6958))+8) = i2;
l13:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6995))+8);
      i2 = _check_pointer(i2, 7002);
      i3 = *(OOC_INT32*)((_check_pointer(i1, 7004))+12);
      i4 = OOC_ARRAY_LENGTH(i2, 0);
      *(OOC_INT32*)(i2+(_check_index(i3, i4, OOC_UINT32, 7002))*4) = i0;
      i0 = *(OOC_INT32*)((_check_pointer(i1, 7036))+12);
      *(OOC_INT32*)((_check_pointer(i1, 7036))+12) = (i0+1);
l14:
      return;
      ;
    }


  OOC_INITIALIZE_VPAR(moduleRef__ref,moduleRef,OOC_CHAR8 ,moduleRef_0d)
  i0 = OOC_Repository__ValidModuleName((void*)(OOC_INT32)moduleRef, moduleRef_0d);
  if (i0) goto l3;
  i0 = *(OOC_UINT8*)((OOC_INT32)moduleRef+(_check_index(0, moduleRef_0d, OOC_UINT8, 7149)));
  i0 = i0==35u;
  
  goto l5;
l3:
  i0=1u;
l5:
  if (i0) goto l40;
  i0 = (OOC_INT32)URI_Scheme_File__ToURI((void*)(OOC_INT32)moduleRef, moduleRef_0d);
  file = (URI_Scheme_File__URI)i0;
  i = 0;
  i1 = (OOC_INT32)s;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 8182))+12);
  i2 = 0!=i2;
  if (i2) goto l9;
  i2=0u;
  goto l11;
l9:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8198))+8);
  i2 = _check_pointer(i2, 8205);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8198))+8);
  i4 = _check_pointer(i4, 8205);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(0, i5, OOC_UINT32, 8205))*4);
  i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(0, i3, OOC_UINT32, 8205))*4);
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 8208)))), OOC_Repository__ModuleDesc_MatchesURI)),OOC_Repository__ModuleDesc_MatchesURI)((OOC_Repository__Module)i2, 0, (URI__URI)i0);
  
l11:
  if (i2) goto l13;
  i2=0;
  goto l23;
l13:
  i2=0;
l14_loop:
  i2 = i2+1;
  i = i2;
  i3 = *(OOC_INT32*)((_check_pointer(i1, 8182))+12);
  i3 = i2!=i3;
  if (i3) goto l17;
  i3=0u;
  goto l19;
l17:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8198))+8);
  i3 = _check_pointer(i3, 8205);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8198))+8);
  i5 = _check_pointer(i5, 8205);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i2, i6, OOC_UINT32, 8205))*4);
  i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 8205))*4);
  i3 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 8208)))), OOC_Repository__ModuleDesc_MatchesURI)),OOC_Repository__ModuleDesc_MatchesURI)((OOC_Repository__Module)i3, 0, (URI__URI)i0);
  
l19:
  if (i3) goto l14_loop;
l23:
  i3 = *(OOC_INT32*)((_check_pointer(i1, 8302))+12);
  i3 = i2!=i3;
  if (!i3) goto l26;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8359))+8);
  i3 = _check_pointer(i3, 8366);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 8366))*4);
  return (OOC_Repository__Module)i2;
l26:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8468))+4);
  topLevelRep = (OOC_Repository__Repository)i2;
  
l27_loop:
  i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 8520)))), OOC_Repository__RepositoryDesc_GetModuleByURI)),OOC_Repository__RepositoryDesc_GetModuleByURI)((OOC_Repository__Repository)i2, (URI__HierarchicalURI)i0, 0u);
  m = (OOC_Repository__Module)i3;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 8586));
  topLevelRep = (OOC_Repository__Repository)i2;
  i4 = i3!=(OOC_INT32)0;
  if (i4) goto l30;
  i4 = i2==(OOC_INT32)0;
  
  goto l32;
l30:
  i4=1u;
l32:
  if (!i4) goto l27_loop;
l35:
  i2 = i3==(OOC_INT32)0;
  if (i2) goto l38;
  i0=i3;
  goto l39;
l38:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8687))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8687))+4);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 8700)))), OOC_Repository__RepositoryDesc_GetModuleByURI)),OOC_Repository__RepositoryDesc_GetModuleByURI)((OOC_Repository__Repository)i1, (URI__HierarchicalURI)i0, 1u);
  m = (OOC_Repository__Module)i0;
  
l39:
  OOC_Config_Repositories__SectionDesc_GetModule_AddToCache((OOC_Repository__Module)i0);
  i0 = (OOC_INT32)m;
  return (OOC_Repository__Module)i0;
  goto l70;
l40:
  i = 0;
  i0 = (OOC_INT32)s;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 7413))+12);
  i1 = 0!=i1;
  if (i1) goto l43;
  i1=0u;
  goto l45;
l43:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7429))+8);
  i1 = _check_pointer(i1, 7436);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT32, 7436))*4);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 7439))+4);
  i1 = (
  _cmp8((const void*)(_check_pointer(i1, 7445)),(const void*)(OOC_INT32)moduleRef))!=0;
  
l45:
  if (i1) goto l47;
  i1=0;
  goto l57;
l47:
  i1=0;
l48_loop:
  i1 = i1+1;
  i = i1;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 7413))+12);
  i2 = i1!=i2;
  if (i2) goto l51;
  i2=0u;
  goto l53;
l51:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7429))+8);
  i2 = _check_pointer(i2, 7436);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i1, i3, OOC_UINT32, 7436))*4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7439))+4);
  i2 = (
  _cmp8((const void*)(_check_pointer(i2, 7445)),(const void*)(OOC_INT32)moduleRef))!=0;
  
l53:
  if (i2) goto l48_loop;
l57:
  i2 = *(OOC_INT32*)((_check_pointer(i0, 7505))+12);
  i2 = i1!=i2;
  if (!i2) goto l60;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7562))+8);
  i2 = _check_pointer(i2, 7569);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i1, i3, OOC_UINT32, 7569))*4);
  return (OOC_Repository__Module)i1;
l60:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7668))+4);
  topLevelRep = (OOC_Repository__Repository)i0;
  
l61_loop:
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7720)))), OOC_Repository__RepositoryDesc_GetModule)),OOC_Repository__RepositoryDesc_GetModule)((OOC_Repository__Repository)i0, (void*)(OOC_INT32)moduleRef, moduleRef_0d, (URI__HierarchicalURI)(OOC_INT32)0);
  m = (OOC_Repository__Module)i1;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7784));
  topLevelRep = (OOC_Repository__Repository)i0;
  i2 = i1!=(OOC_INT32)0;
  if (i2) goto l64;
  i2 = i0==(OOC_INT32)0;
  
  goto l66;
l64:
  i2=1u;
l66:
  if (!i2) goto l61_loop;
l69:
  OOC_Config_Repositories__SectionDesc_GetModule_AddToCache((OOC_Repository__Module)i1);
  i0 = (OOC_INT32)m;
  return (OOC_Repository__Module)i0;
l70:
  _failed_function(5068); return 0;
  ;
}

URI__URI OOC_Config_Repositories__SectionDesc_GetResource(OOC_Config_Repositories__Section s, const OOC_CHAR8 package__ref[], OOC_LEN package_0d, const OOC_CHAR8 path__ref[], OOC_LEN path_0d) {
  register OOC_INT32 i0,i1,i2;
  OOC_ALLOCATE_VPAR(package,OOC_CHAR8 ,package_0d)
  OOC_ALLOCATE_VPAR(path,OOC_CHAR8 ,path_0d)
  OOC_Repository__Repository topLevelRep;
  URI__URI uri;

  OOC_INITIALIZE_VPAR(package__ref,package,OOC_CHAR8 ,package_0d)
  OOC_INITIALIZE_VPAR(path__ref,path,OOC_CHAR8 ,path_0d)
  i0 = (OOC_INT32)s;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9198))+4);
  topLevelRep = (OOC_Repository__Repository)i0;
  
l1_loop:
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9248)))), OOC_Repository__RepositoryDesc_GetResource)),OOC_Repository__RepositoryDesc_GetResource)((OOC_Repository__Repository)i0, (void*)(OOC_INT32)package, package_0d, (void*)(OOC_INT32)path, path_0d);
  uri = (URI__URI)i1;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9311));
  topLevelRep = (OOC_Repository__Repository)i0;
  i2 = i1!=0;
  if (i2) goto l4;
  i2 = i0==0;
  
  goto l6;
l4:
  i2=1u;
l6:
  if (!i2) goto l1_loop;
l9:
  return (URI__URI)i1;
  ;
}

Object__StringArrayPtr OOC_Config_Repositories__SectionDesc_GetIncludePaths(OOC_Config_Repositories__Section s) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_INT32 c;
  OOC_Repository__Repository rep;
  Object__StringArrayPtr result;
  auto OOC_CHAR8 OOC_Config_Repositories__SectionDesc_GetIncludePaths_Select(OOC_Repository__Repository rep);
    
    OOC_CHAR8 OOC_Config_Repositories__SectionDesc_GetIncludePaths_Select(OOC_Repository__Repository rep) {
      register OOC_INT32 i0;

      i0 = (OOC_INT32)rep;
      return (OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9648)))), &_td_OOC_Repository_FileSystem__RepositoryDesc));
      ;
    }


  c = 0;
  i0 = (OOC_INT32)s;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9725))+4);
  rep = (OOC_Repository__Repository)i1;
  i2 = i1!=(OOC_INT32)0;
  if (i2) goto l3;
  i2=0u;
  goto l5;
l3:
  i2 = OOC_Config_Repositories__SectionDesc_GetIncludePaths_Select((OOC_Repository__Repository)i1);
  
l5:
  if (i2) goto l7;
  i1=0;
  goto l17;
l7:
  i2=i1;i1=0;
l8_loop:
  i1 = i1+1;
  c = i1;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 9811));
  rep = (OOC_Repository__Repository)i2;
  i3 = i2!=(OOC_INT32)0;
  if (i3) goto l11;
  i3=0u;
  goto l13;
l11:
  i3 = OOC_Config_Repositories__SectionDesc_GetIncludePaths_Select((OOC_Repository__Repository)i2);
  
l13:
  if (i3) goto l8_loop;
l17:
  i1 = (OOC_INT32)RT0__NewObject(_td_Object__StringArrayPtr.baseTypes[0], i1);
  result = (Object__StringArrayPtr)i1;
  c = 0;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9880))+4);
  rep = (OOC_Repository__Repository)i0;
  i2 = i0!=(OOC_INT32)0;
  if (!i2) goto l29;
  i2=0;
l20_loop:
  i3 = OOC_Config_Repositories__SectionDesc_GetIncludePaths_Select((OOC_Repository__Repository)i0);
  if (!i3) goto l24;
  i3 = _check_pointer(i1, 9961);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9996)))), &_td_OOC_Repository_FileSystem__RepositoryDesc, 9996)), 10007))+12);
  i5 = (OOC_INT32)URI_Scheme_File__URIDesc_GetPath((URI_Scheme_File__URI)(_type_guard(i5, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 10029)))), &_td_URI_Scheme_File__URIDesc, 10029)));
  i6 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10060)))), OOC_Repository__RepositoryDesc_GetDefaultSubdir)),OOC_Repository__RepositoryDesc_GetDefaultSubdir)((OOC_Repository__Repository)i0, 13);
  *(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 9961))*4) = ((OOC_INT32)Object__Concat2((void*)i5,(void*)i6));
  i2 = i2+1;
  c = i2;
  
l24:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10150));
  rep = (OOC_Repository__Repository)i0;
  i3 = i0!=(OOC_INT32)0;
  if (i3) goto l20_loop;
l29:
  return (Object__StringArrayPtr)i1;
  ;
}

void OOC_OOC_Config_Repositories_init(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)URI_Scheme_File__NewPrototype();
  URI__RegisterScheme((URI__URI)i0);
  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Config_Repositories__ErrorContext.baseTypes[0]);
  OOC_Config_Repositories__repositoriesContext = (OOC_Config_Repositories__ErrorContext)i0;
  Msg__InitContext((Msg__Context)i0, "OOC:Config:Repositories", 24);
  OOC_Config_Repositories__repositoryEntries = (OOC_Config_Repositories__RepositoryEntry)(OOC_INT32)0;
  return;
  ;
}

void OOC_OOC_Config_Repositories_destroy(void) {
}

/* --- */
