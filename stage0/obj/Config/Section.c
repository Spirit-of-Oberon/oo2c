#include <Config/Section.d>
#include <__oo2c.h>
#include <setjmp.h>

void Config_Section__ErrorContextDesc_GetTemplate(Config_Section__ErrorContext context, Msg__Msg msg, Msg__LString templ, OOC_LEN templ_0d) {
  register OOC_INT32 i0,i1;
  OOC_CHAR16 t[128];

  i0 = (OOC_INT32)msg;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 838))+8);
  switch (i1) {
  case 1:
    _copy_16((const void*)((OOC_CHAR16[]){78,97,109,101,32,111,102,32,114,111,111,116,32,101,108,101,109,101,110,116,32,109,117,115,116,32,98,101,32,96,36,123,110,97,109,101,125,39,0}),(void*)(OOC_INT32)t,128);
    goto l6;
  case 2:
    _copy_16((const void*)((OOC_CHAR16[]){73,110,118,97,108,105,100,32,99,104,97,114,97,99,116,101,114,32,100,97,116,97,32,105,110,32,114,111,111,116,32,101,108,101,109,101,110,116,0}),(void*)(OOC_INT32)t,128);
    goto l6;
  case 3:
    _copy_16((const void*)((OOC_CHAR16[]){85,110,107,110,111,119,110,32,99,111,110,102,105,103,117,114,97,116,105,111,110,32,115,101,99,116,105,111,110,32,96,36,123,110,97,109,101,125,39,0}),(void*)(OOC_INT32)t,128);
    goto l6;
  default:
    _failed_case(i1, 830);
    goto l6;
  }
l6:
  i1 = (OOC_INT32)context;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 1097)))), XML_Error__ContextDesc_WriteTemplate)),XML_Error__ContextDesc_WriteTemplate)((XML_Error__Context)i1, (Msg__Msg)i0, (void*)(OOC_INT32)t, 128, (void*)(OOC_INT32)templ, templ_0d);
  return;
  ;
}

void Config_Section__Init(Config_Section__Section s, const Config_Parser__String id__ref, OOC_LEN id_0d) {
  register OOC_INT32 i0,i1;
  OOC_ALLOCATE_VPAR(id,OOC_CHAR16 ,id_0d)

  OOC_INITIALIZE_VPAR(id__ref,id,OOC_CHAR16 ,(id_0d*2))
  i0 = (OOC_INT32)s;
  i1 = LongStrings__Length((void*)(OOC_INT32)id, id_0d);
  *(OOC_INT32*)(_check_pointer(i0, 1217)) = ((OOC_INT32)RT0__NewObject(_td_XML_UnicodeBuffer__CharArray.baseTypes[0], (i1+1)));
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 1268));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 1268));
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 1274)), 0);
  _copy_16((const void*)(OOC_INT32)id,(void*)(_check_pointer(i1, 1274)),i0);
  return;
  ;
}

void Config_Section__SectionDesc_ProcessElements(Config_Section__Section s, Config_Parser__Element sectionRoot, XML_Locator__ErrorListener errorListener) {

  return;
  ;
}

void Config_Section__SectionDesc_DumpContent(Config_Section__Section s, Channel__Channel ch) {

  return;
  ;
}

Config_Section__SectionList Config_Section__NewSectionList(void) {
  register OOC_INT32 i0;
  Config_Section__SectionList sl;

  i0 = (OOC_INT32)RT0__NewObject(_td_Config_Section__SectionList.baseTypes[0]);
  sl = (Config_Section__SectionList)i0;
  *(OOC_INT32*)(_check_pointer(i0, 1934)) = 0;
  return (Config_Section__SectionList)i0;
  ;
}

void Config_Section__SectionListDesc_Add(Config_Section__SectionList sl, Config_Section__Section section) {
  register OOC_INT32 i0,i1;
  Config_Section__Node _new;
  auto void Config_Section__SectionListDesc_Add_Insert(Config_Section__Node *list);
    
    void Config_Section__SectionListDesc_Add_Insert(Config_Section__Node *list) {
      register OOC_INT32 i0,i1,i2,i3;

      i0 = (OOC_INT32)*list;
      i1 = i0==(OOC_INT32)0;
      if (i1) goto l11;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2211))+4);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 2220));
      i2 = (OOC_INT32)section;
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 2237));
      i1 = (
      _cmp16((const void*)(_check_pointer(i1, 2226)),(const void*)(_check_pointer(i3, 2243))))==0;
      if (i1) goto l9;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2345))+4);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 2354));
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 2371));
      i1 = (
      _cmp16((const void*)(_check_pointer(i1, 2360)),(const void*)(_check_pointer(i2, 2377))))>0;
      if (i1) goto l7;
      Config_Section__SectionListDesc_Add_Insert((void*)(_check_pointer(i0, 2506)));
      goto l12;
l7:
      i1 = (OOC_INT32)_new;
      *(OOC_INT32*)(_check_pointer(i1, 2439)) = i0;
      *list = (Config_Section__Node)i1;
      goto l12;
l9:
      i1 = (OOC_INT32)_new;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2318))+4);
      *(OOC_INT32*)((_check_pointer(i0, 2302))+4) = i1;
      goto l12;
l11:
      i0 = (OOC_INT32)_new;
      *list = (Config_Section__Node)i0;
l12:
      return;
      ;
    }


  i0 = (OOC_INT32)RT0__NewObject(_td_Config_Section__Node.baseTypes[0]);
  _new = (Config_Section__Node)i0;
  *(OOC_INT32*)(_check_pointer(i0, 2573)) = 0;
  i1 = (OOC_INT32)section;
  *(OOC_INT32*)((_check_pointer(i0, 2595))+4) = i1;
  i0 = (OOC_INT32)sl;
  Config_Section__SectionListDesc_Add_Insert((void*)(_check_pointer(i0, 2631)));
  return;
  ;
}

Config_Section__Section Config_Section__SectionListDesc_Get(Config_Section__SectionList sl, XML_UnicodeBuffer__CharArray name) {
  register OOC_INT32 i0,i1,i2;
  Config_Section__Node sn;

  i0 = (OOC_INT32)sl;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2759));
  sn = (Config_Section__Node)i0;
  i1 = i0!=0;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2793))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 2802));
  i2 = (OOC_INT32)name;
  i1 = (
  _cmp16((const void*)(_check_pointer(i1, 2808)),(const void*)(_check_pointer(i2, 2816))))!=0;
  
l5:
  if (!i1) goto l17;
  i1 = (OOC_INT32)name;
  
l8_loop:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2836));
  sn = (Config_Section__Node)i0;
  i2 = i0!=0;
  if (i2) goto l11;
  i2=0u;
  goto l13;
l11:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2793))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 2802));
  i2 = (
  _cmp16((const void*)(_check_pointer(i2, 2808)),(const void*)(_check_pointer(i1, 2816))))!=0;
  
l13:
  if (i2) goto l8_loop;
l17:
  i1 = i0==0;
  if (i1) goto l20;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2916))+4);
  return (Config_Section__Section)i0;
  goto l21;
l20:
  return (Config_Section__Section)0;
l21:
  _failed_function(2679); return 0;
  ;
}

void Config_Section__SectionListDesc_ProcessElements(Config_Section__SectionList sl, Config_Parser__Element root, const Config_Parser__String rootElementName__ref, OOC_LEN rootElementName_0d, Config_Parser__Parser p) {
  register OOC_INT32 i0,i1,i2;
  OOC_ALLOCATE_VPAR(rootElementName,OOC_CHAR16 ,rootElementName_0d)
  Msg__Msg lastError;
  Config_Parser__Node node;
  Config_Section__Section s;
  auto void Config_Section__SectionListDesc_ProcessElements_Err(OOC_INT32 code, Config_Parser__Node xmlNode);
    
    void Config_Section__SectionListDesc_ProcessElements_Err(OOC_INT32 code, Config_Parser__Node xmlNode) {
      register OOC_INT32 i0,i1,i2,i3,i4;

      i0 = (OOC_INT32)xmlNode;
      i1 = (OOC_INT32)p;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3251))+16);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3251))+16);
      i3 = (OOC_INT32)Config_Section__sectionContext;
      i4 = code;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 3266)))), XML_Locator__ErrorListenerDesc_Error)),XML_Locator__ErrorListenerDesc_Error)((XML_Locator__ErrorListener)i1, (XML_Error__Context)i3, i4, 0u, (void*)((_check_pointer(i0, 3311))+4));
      lastError = (Msg__Msg)i0;
      return;
      ;
    }


  OOC_INITIALIZE_VPAR(rootElementName__ref,rootElementName,OOC_CHAR16 ,(rootElementName_0d*2))
  i0 = (OOC_INT32)root;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3354))+28);
  i1 = (
  _cmp16((const void*)(_check_pointer(i1, 3360)),(const void*)(OOC_INT32)rootElementName))!=0;
  if (!i1) goto l3;
  Config_Section__SectionListDesc_ProcessElements_Err(1, (Config_Parser__Node)i0);
  i0 = (OOC_INT32)Msg__GetLStringPtr((void*)(OOC_INT32)rootElementName, rootElementName_0d);
  i1 = (OOC_INT32)lastError;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3436)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i1, "name", 5, (Msg__LStringPtr)i0);
l3:
  i0 = (OOC_INT32)root;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3531))+36);
  node = (Config_Parser__Node)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l26;
l6_loop:
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3583)))), &_td_Config_Parser__CharDataDesc);
  if (i1) goto l17;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3708)))), &_td_Config_Parser__ElementDesc);
  if (i1) goto l11;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3702)))), 3702);
  
  goto l21;
l11:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3754))+28);
  i2 = (OOC_INT32)sl;
  i1 = (OOC_INT32)Config_Section__SectionListDesc_Get((Config_Section__SectionList)i2, (XML_UnicodeBuffer__CharArray)i1);
  s = (Config_Section__Section)i1;
  i2 = i1==(OOC_INT32)0;
  if (i2) goto l14;
  i2 = (OOC_INT32)p;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 3957))+16);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3931)))), Config_Section__SectionDesc_ProcessElements)),Config_Section__SectionDesc_ProcessElements)((Config_Section__Section)i1, (Config_Parser__Element)i0, (XML_Locator__ErrorListener)i2);
  
  goto l21;
l14:
  Config_Section__SectionListDesc_ProcessElements_Err(3, (Config_Parser__Node)i0);
  i0 = (OOC_INT32)node;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3897))+28);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3897))+28);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 3903)), 0);
  i0 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i0, 3903)), i1);
  i1 = (OOC_INT32)lastError;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3846)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i1, "name", 5, (Msg__LStringPtr)i0);
  
  goto l21;
l17:
  i1 = Config_Parser__NodeDesc_IsWhitespace((Config_Parser__Node)i0);
  i1 = !i1;
  if (!i1) goto l21;
  Config_Section__SectionListDesc_ProcessElements_Err(2, (Config_Parser__Node)i0);
l21:
  i0 = (OOC_INT32)node;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4015));
  node = (Config_Parser__Node)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l6_loop;
l26:
  return;
  ;
}

void Config_Section__SectionListDesc_DumpContent(Config_Section__SectionList sl, Channel__Channel ch) {
  register OOC_INT32 i0,i1,i2,i3;
  TextRider__Writer w;
  Config_Section__Node n;

  i0 = (OOC_INT32)ch;
  i1 = (OOC_INT32)TextRider__ConnectWriter((Channel__Channel)i0);
  w = (TextRider__Writer)i1;
  i1 = (OOC_INT32)sl;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 4224));
  n = (Config_Section__Node)i1;
  i2 = i1!=0;
  if (!i2) goto l8;
l3_loop:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4262))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4262))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 4271)))), Config_Section__SectionDesc_DumpContent)),Config_Section__SectionDesc_DumpContent)((Config_Section__Section)i3, (Channel__Channel)i0);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 4303));
  n = (Config_Section__Node)i1;
  i2 = i1!=0;
  if (i2) goto l3_loop;
l8:
  return;
  ;
}

void OOC_Config_Section_init(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)RT0__NewObject(_td_Config_Section__ErrorContext.baseTypes[0]);
  Config_Section__sectionContext = (Config_Section__ErrorContext)i0;
  Msg__InitContext((Msg__Context)i0, "Config:Section", 15);
  return;
  ;
}

/* --- */
