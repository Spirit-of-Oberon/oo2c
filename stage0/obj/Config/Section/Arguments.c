#include <Config/Section/Arguments.d>
#include <__oo2c.h>
#include <setjmp.h>

void Config_Section_Arguments__ErrorContextDesc_GetTemplate(Config_Section_Arguments__ErrorContext context, Msg__Msg msg, Msg__LString templ, OOC_LEN templ_0d) {
  register OOC_INT32 i0,i1;
  OOC_CHAR16 t[128];

  i0 = (OOC_INT32)msg;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 764))+8);
  switch (i1) {
  case 1:
    _copy_16((const void*)((OOC_CHAR16[]){73,110,118,97,108,105,100,32,99,111,110,116,101,110,116,32,102,111,114,32,101,108,101,109,101,110,116,32,96,36,123,110,97,109,101,125,39,0}),(void*)(OOC_INT32)t,128);
    goto l6;
  case 2:
    _copy_16((const void*)((OOC_CHAR16[]){65,116,116,114,105,98,117,116,101,32,96,36,123,110,97,109,101,125,39,32,105,115,32,110,111,116,32,100,101,102,105,110,101,100,32,102,111,114,32,116,104,105,115,32,101,108,101,109,101,110,116,0}),(void*)(OOC_INT32)t,128);
    goto l6;
  case 5:
    _copy_16((const void*)((OOC_CHAR16[]){84,104,105,115,32,101,108,101,109,101,110,116,32,109,117,115,116,32,99,111,110,116,97,105,110,32,99,104,97,114,97,99,116,101,114,32,100,97,116,97,32,111,110,108,121,0}),(void*)(OOC_INT32)t,128);
    goto l6;
  default:
    _failed_case(i1, 756);
    goto l6;
  }
l6:
  i1 = (OOC_INT32)context;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 1045)))), XML_Error__ContextDesc_WriteTemplate)),XML_Error__ContextDesc_WriteTemplate)((XML_Error__Context)i1, (Msg__Msg)i0, (void*)(OOC_INT32)t, 128, (void*)(OOC_INT32)templ, templ_0d);
  return;
  ;
}

static void Config_Section_Arguments__Init(Config_Section_Arguments__Section s, const Config_Parser__String id__ref, OOC_LEN id_0d) {
  register OOC_INT32 i0;
  OOC_ALLOCATE_VPAR(id,OOC_CHAR16 ,id_0d)

  OOC_INITIALIZE_VPAR(id__ref,id,OOC_CHAR16 ,(id_0d*2))
  i0 = (OOC_INT32)s;
  Config_Section__Init((Config_Section__Section)i0, (void*)(OOC_INT32)id, id_0d);
  *(OOC_INT32*)((_check_pointer(i0, 1181))+8) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 1209))+4) = ((OOC_INT32)RT0__NewObject(_td_Config_Section_Arguments__ArgumentArray.baseTypes[0], 4));
  return;
  ;
}

Config_Section_Arguments__Section Config_Section_Arguments__New(const Config_Parser__String sectionName__ref, OOC_LEN sectionName_0d) {
  register OOC_INT32 i0;
  OOC_ALLOCATE_VPAR(sectionName,OOC_CHAR16 ,sectionName_0d)

  OOC_INITIALIZE_VPAR(sectionName__ref,sectionName,OOC_CHAR16 ,(sectionName_0d*2))
  i0 = (OOC_INT32)RT0__NewObject(_td_Config_Section_Arguments__Section.baseTypes[0]);
  Config_Section_Arguments__Init((Config_Section_Arguments__Section)i0, (void*)(OOC_INT32)sectionName, sectionName_0d);
  return (Config_Section_Arguments__Section)i0;
  ;
}

OOC_INT32 Config_Section_Arguments__SectionDesc_ArgNumber(Config_Section_Arguments__Section s) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)s;
  i0 = *(OOC_INT32*)((_check_pointer(i0, 1454))+8);
  return i0;
  ;
}

Object__String Config_Section_Arguments__SectionDesc_Get(Config_Section_Arguments__Section s, OOC_INT32 position) {
  register OOC_INT32 i0,i1,i2;

  i0 = position;
  i1 = 0<=i0;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)s;
  i1 = *(OOC_INT32*)((_check_pointer(i1, 1587))+8);
  i1 = i0<i1;
  
l5:
  if (i1) goto l7;
  return (Object__String)(OOC_INT32)0;
  goto l8;
l7:
  i1 = (OOC_INT32)s;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 1619))+4);
  i1 = _check_pointer(i1, 1624);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(i0, i2, OOC_UINT32, 1624))*4);
  return (Object__String)i0;
l8:
  _failed_function(1507); return 0;
  ;
}

void Config_Section_Arguments__SectionDesc_ProcessElements(Config_Section_Arguments__Section s, Config_Parser__Element sectionRoot, XML_Locator__ErrorListener errorListener) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
  Config_Parser__Node node;
  OOC_INT32 i;
  XML_Builder__Attribute att;
  Msg__Msg lastError;
  Config_Section_Arguments__ArgumentArray newArgs;
  XML_UnicodeBuffer__CharArray parserString;
  auto void Config_Section_Arguments__SectionDesc_ProcessElements_Err(OOC_INT32 code, Config_Parser__Node xmlNode);
    
    void Config_Section_Arguments__SectionDesc_ProcessElements_Err(OOC_INT32 code, Config_Parser__Node xmlNode) {
      register OOC_INT32 i0,i1,i2,i3;

      i0 = (OOC_INT32)xmlNode;
      i1 = (OOC_INT32)errorListener;
      i2 = (OOC_INT32)Config_Section_Arguments__argumentsContext;
      i3 = code;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2100)))), XML_Locator__ErrorListenerDesc_Error)),XML_Locator__ErrorListenerDesc_Error)((XML_Locator__ErrorListener)i1, (XML_Error__Context)i2, i3, 0u, (void*)((_check_pointer(i0, 2147))+4));
      lastError = (Msg__Msg)i0;
      return;
      ;
    }


  i0 = (OOC_INT32)sectionRoot;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2201))+36);
  node = (Config_Parser__Node)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l46;
l3_loop:
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2253)))), &_td_Config_Parser__ElementDesc);
  if (i1) goto l13;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3263)))), &_td_Config_Parser__CharDataDesc);
  if (i1) goto l8;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3257)))), 3257);
  goto l41;
l8:
  i1 = Config_Parser__NodeDesc_IsWhitespace((Config_Parser__Node)i0);
  i1 = !i1;
  if (!i1) goto l41;
  Config_Section_Arguments__SectionDesc_ProcessElements_Err(1, (Config_Parser__Node)i0);
  goto l41;
l13:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2289))+28);
  i1 = (
  _cmp16((const void*)(_check_pointer(i1, 2295)),(const void*)((OOC_CHAR16[]){97,114,103,0})))==0;
  if (i1) goto l16;
  Config_Section_Arguments__SectionDesc_ProcessElements_Err(1, (Config_Parser__Node)i0);
  i0 = (OOC_INT32)s;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3220));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3220));
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 3226)), 0);
  i0 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i0, 3226)), i1);
  i1 = (OOC_INT32)lastError;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3172)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i1, (OOC_CHAR8*)"name", 5, (Msg__LStringPtr)i0);
  goto l41;
l16:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2339))+32);
  i = 0;
  i0 = *(OOC_INT32*)(_check_pointer(i0, 2349));
  i1 = 0<i0;
  if (!i1) goto l24;
  i1=0;
l19_loop:
  i2 = (OOC_INT32)node;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 2383))+32);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 2393))+4);
  i3 = _check_pointer(i3, 2399);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i1, i4, OOC_UINT32, 2399))*4);
  att = (XML_Builder__Attribute)i1;
  Config_Section_Arguments__SectionDesc_ProcessElements_Err(2, (Config_Parser__Node)i2);
  i1 = (OOC_INT32)att;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2517))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2517))+4);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 2528)), 0);
  i1 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i1, 2528)), i2);
  i2 = (OOC_INT32)lastError;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 2467)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i2, (OOC_CHAR8*)"name", 5, (Msg__LStringPtr)i1);
  i1 = i;
  i1 = i1+1;
  i = i1;
  i2 = i1<i0;
  if (i2) goto l19_loop;
l24:
  i0 = (OOC_INT32)node;
  i1 = Config_Parser__NodeDesc_HasNoElementContent((Config_Parser__Node)i0);
  i1 = !i1;
  if (i1) goto l38;
  i1 = (OOC_INT32)s;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2704))+4);
  i3 = *(OOC_INT32*)((_check_pointer(i1, 2684))+8);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 2710)), 0);
  i2 = i3==i2;
  if (!i2) goto l37;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2753))+4);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 2759)), 0);
  i2 = (OOC_INT32)RT0__NewObject(_td_Config_Section_Arguments__ArgumentArray.baseTypes[0], (i2*2));
  newArgs = (Config_Section_Arguments__ArgumentArray)i2;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2800))+4);
  i = 0;
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 2806)), 0);
  i4 = 0<i3;
  if (!i4) goto l36;
  i4=0;
l31_loop:
  i5 = _check_pointer(i2, 2837);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2845))+4);
  i7 = _check_pointer(i7, 2851);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i4, i8, OOC_UINT32, 2851))*4);
  *(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 2837))*4) = i7;
  i4 = i4+1;
  i = i4;
  i5 = i4<i3;
  if (i5) goto l31_loop;
l36:
  *(OOC_INT32*)((_check_pointer(i1, 2889))+4) = i2;
l37:
  i0 = (OOC_INT32)Config_Parser__NodeDesc_GetCharDataContent((Config_Parser__Node)i0);
  parserString = (XML_UnicodeBuffer__CharArray)i0;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2993))+4);
  i2 = _check_pointer(i2, 2998);
  i3 = *(OOC_INT32*)((_check_pointer(i1, 3000))+8);
  i4 = OOC_ARRAY_LENGTH(i2, 0);
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i0, 3043)), 0);
  i0 = (OOC_INT32)Object__NewUTF16((void*)(_check_pointer(i0, 3043)), i5);
  *(OOC_INT32*)(i2+(_check_index(i3, i4, OOC_UINT32, 2998))*4) = i0;
  i0 = *(OOC_INT32*)((_check_pointer(i1, 3065))+8);
  *(OOC_INT32*)((_check_pointer(i1, 3065))+8) = (i0+1);
  goto l41;
l38:
  Config_Section_Arguments__SectionDesc_ProcessElements_Err(5, (Config_Parser__Node)i0);
l41:
  i0 = (OOC_INT32)node;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3400));
  node = (Config_Parser__Node)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3_loop;
l46:
  return;
  ;
}

void Config_Section_Arguments__SectionDesc_DumpContent(Config_Section_Arguments__Section s, Channel__Channel ch) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  TextRider__Writer w;
  OOC_CHAR8 str8[2048];
  OOC_INT32 i;

  i0 = (OOC_INT32)ch;
  i0 = (OOC_INT32)TextRider__ConnectWriter((Channel__Channel)i0);
  w = (TextRider__Writer)i0;
  i1 = (OOC_INT32)s;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 3650));
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 3650));
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 3656)), 0);
  LongStrings__Short((void*)(_check_pointer(i3, 3656)), i2, 63u, (void*)(OOC_INT32)str8, 2048);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3676)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (OOC_CHAR8*)"<", 2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3702)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (void*)(OOC_INT32)str8, 2048);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3729)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (OOC_CHAR8*)">", 2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3751)))), TextRider__WriterDesc_WriteLn)),TextRider__WriterDesc_WriteLn)((TextRider__Writer)i0);
  i = 0;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 3781))+8);
  i3 = 0<i2;
  if (!i3) goto l8;
  i3=0;
l3_loop:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3805)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (OOC_CHAR8*)"  <arg>", 8);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3855))+4);
  i4 = _check_pointer(i4, 3861);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 3861))*4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3839)))), TextRider__WriterDesc_WriteObject)),TextRider__WriterDesc_WriteObject)((TextRider__Writer)i0, (Object__Object)i4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3874)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (OOC_CHAR8*)"</arg>", 7);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3907)))), TextRider__WriterDesc_WriteLn)),TextRider__WriterDesc_WriteLn)((TextRider__Writer)i0);
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l3_loop;
l8:
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 3950));
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 3950));
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 3956)), 0);
  LongStrings__Short((void*)(_check_pointer(i1, 3956)), i2, 63u, (void*)(OOC_INT32)str8, 2048);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3976)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (OOC_CHAR8*)"</", 3);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4003)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (void*)(OOC_INT32)str8, 2048);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4030)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (OOC_CHAR8*)">", 2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4052)))), TextRider__WriterDesc_WriteLn)),TextRider__WriterDesc_WriteLn)((TextRider__Writer)i0);
  return;
  ;
}

void OOC_Config_Section_Arguments_init(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)RT0__NewObject(_td_Config_Section_Arguments__ErrorContext.baseTypes[0]);
  Config_Section_Arguments__argumentsContext = (Config_Section_Arguments__ErrorContext)i0;
  Msg__InitContext((Msg__Context)i0, (OOC_CHAR8*)"Config:Section:Arguments", 25);
  return;
  ;
}

void OOC_Config_Section_Arguments_destroy(void) {
}

/* --- */
