#include <OOC/Config/FileSystem.d>
#include <__oo2c.h>
#include <setjmp.h>

void OOC_Config_FileSystem__ErrorContextDesc_GetTemplate(OOC_Config_FileSystem__ErrorContext context, Msg__Msg msg, Msg__LString templ, OOC_LEN templ_0d) {
  register OOC_INT32 i0,i1;
  OOC_CHAR16 t[128];

  i0 = (OOC_INT32)msg;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 1733))+8);
  switch (i1) {
  case 1:
    _copy_16((const void*)((OOC_CHAR16[]){65,116,116,114,105,98,117,116,101,32,96,36,123,110,97,109,101,125,39,32,105,115,32,110,111,116,32,100,101,102,105,110,101,100,32,102,111,114,32,116,104,105,115,32,101,108,101,109,101,110,116,0}),(void*)(OOC_INT32)t,128);
    goto l6;
  case 2:
    _copy_16((const void*)((OOC_CHAR16[]){84,104,105,115,32,101,108,101,109,101,110,116,32,109,117,115,116,32,99,111,110,116,97,105,110,32,99,104,97,114,97,99,116,101,114,32,100,97,116,97,32,111,110,108,121,0}),(void*)(OOC_INT32)t,128);
    goto l6;
  case 3:
    _copy_16((const void*)((OOC_CHAR16[]){73,110,118,97,108,105,100,32,85,82,73,46,32,32,82,101,97,115,111,110,58,32,36,123,117,114,105,95,109,115,103,125,0}),(void*)(OOC_INT32)t,128);
    goto l6;
  default:
    _failed_case(i1, 1725);
    goto l6;
  }
l6:
  i1 = (OOC_INT32)context;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2005)))), XML_Error__ContextDesc_WriteTemplate)),XML_Error__ContextDesc_WriteTemplate)((XML_Error__Context)i1, (Msg__Msg)i0, (void*)(OOC_INT32)t, 128, (void*)(OOC_INT32)templ, templ_0d);
  return;
  ;
}

static OOC_Config_FileSystem__RepositoryEntry OOC_Config_FileSystem__NewRepositoryEntry(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Config_FileSystem__RepositoryEntry.baseTypes[0]);
  OOC_Config_Repositories__InitRepositoryEntry((OOC_Config_Repositories__RepositoryEntry)i0, "file-system", 12);
  return (OOC_Config_FileSystem__RepositoryEntry)i0;
  ;
}

OOC_Repository__Repository OOC_Config_FileSystem__RepositoryEntryDesc_ProcessElement(volatile OOC_Config_FileSystem__RepositoryEntry re, volatile Config_Parser__Element node, volatile XML_Locator__ErrorListener errorListener, volatile OOC_Repository__Repository baseRep) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  volatile OOC_INT32 i;
  volatile XML_Builder__Attribute att;
  volatile Msg__Msg lastError;
  volatile XML_UnicodeBuffer__CharArray parserString;
  volatile OOC_CHAR8 str8[4096];
  volatile URI__URI uri;
  auto void OOC_Config_FileSystem__RepositoryEntryDesc_ProcessElement_Err(OOC_INT32 code, Config_Parser__Node xmlNode);
  jmp_buf _target0;
  Exception__Context _context0;
    
    void OOC_Config_FileSystem__RepositoryEntryDesc_ProcessElement_Err(OOC_INT32 code, Config_Parser__Node xmlNode) {
      register OOC_INT32 i0,i1,i2,i3;

      i0 = (OOC_INT32)xmlNode;
      i1 = (OOC_INT32)errorListener;
      i2 = (OOC_INT32)OOC_Config_FileSystem__repositoriesContext;
      i3 = code;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2758)))), XML_Locator__ErrorListenerDesc_Error)),XML_Locator__ErrorListenerDesc_Error)((XML_Locator__ErrorListener)i1, (XML_Error__Context)i2, i3, 0u, (void*)((_check_pointer(i0, 2808))+4));
      lastError = (Msg__Msg)i0;
      return;
      ;
    }


  i0 = (OOC_INT32)node;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2861))+32);
  i = 0;
  i0 = *(OOC_INT32*)(_check_pointer(i0, 2871));
  i1 = 0<i0;
  if (!i1) goto l8;
  i1=0;
l3_loop:
  i2 = (OOC_INT32)node;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 2899))+32);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 2909))+4);
  i3 = _check_pointer(i3, 2915);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i1, i4, OOC_UINT32, 2915))*4);
  att = (XML_Builder__Attribute)i1;
  OOC_Config_FileSystem__RepositoryEntryDesc_ProcessElement_Err(1, (Config_Parser__Node)i2);
  i1 = (OOC_INT32)att;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3021))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3021))+4);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 3032)), 0);
  i1 = (OOC_INT32)Msg__GetLStringPtr((void*)(_check_pointer(i1, 3032)), i2);
  i2 = (OOC_INT32)lastError;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 2971)))), Msg__MsgDesc_SetLStringAttrib)),Msg__MsgDesc_SetLStringAttrib)((Msg__Msg)i2, "name", 5, (Msg__LStringPtr)i1);
  i1 = i;
  i1 = i1+1;
  i = i1;
  i2 = i1<i0;
  if (i2) goto l3_loop;
l8:
  i0 = (OOC_INT32)node;
  i1 = Config_Parser__NodeDesc_HasNoElementContent((Config_Parser__Node)i0);
  i1 = !i1;
  if (i1) goto l26;
  i0 = (OOC_INT32)Config_Parser__NodeDesc_GetCharDataContent((Config_Parser__Node)i0);
  parserString = (XML_UnicodeBuffer__CharArray)i0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 3224)), 0);
  LongStrings__Short((void*)(_check_pointer(i0, 3224)), i1, 63u, (void*)(OOC_INT32)str8, 4096);
  i0 = (
  _cmp8((const void*)(OOC_INT32)str8,(const void*)""))==0;
  if (i0) goto l13;
  i0 = Strings__Length((void*)(OOC_INT32)str8, 4096);
  i0 = *(OOC_UINT8*)((OOC_INT32)str8+(_check_index((i0-1), 4096, OOC_UINT16, 3268)));
  i0 = i0!=47u;
  
  goto l15;
l13:
  i0=1u;
l15:
  if (!i0) goto l17;
  Strings__Append("/", 2, (void*)(OOC_INT32)str8, 4096);
l17:
  {
    Exception__PushContext(&_context0, &_target0);
    if (!setjmp(_target0)) goto l24;
    Exception__PopContext(1);
    i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG(((OOC_INT32)Exception__Current()))), &_td_Exception__ParseErrorDesc);
    if (i0) goto l22;
    Exception__ActivateContext();
    goto l23;
l22:
    i0 = (OOC_INT32)node;
    OOC_Config_FileSystem__RepositoryEntryDesc_ProcessElement_Err(3, (Config_Parser__Node)i0);
l23:
    Exception__Clear();
    goto l25;
l24:
    i0 = (OOC_INT32)OOC_Repository_FileSystem__baseURI;
    i0 = (OOC_INT32)URI_Parser__NewURILatin1((void*)(OOC_INT32)str8, 4096, (URI__HierarchicalURI)i0);
    uri = (URI__URI)i0;
    i1 = (OOC_INT32)baseRep;
    i0 = (OOC_INT32)OOC_Repository_FileSystem__New((OOC_Repository__Repository)i1, (URI__HierarchicalURI)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3495)))), &_td_URI__HierarchicalURIDesc, 3495)));
    Exception__PopContext(1);
    return (OOC_Repository__Repository)i0;
    Exception__PopContext(1);
l25:;
  }
  goto l27;
l26:
  OOC_Config_FileSystem__RepositoryEntryDesc_ProcessElement_Err(2, (Config_Parser__Node)i0);
l27:
  return (OOC_Repository__Repository)0;
  ;
}

void OOC_OOC_Config_FileSystem_init(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Config_FileSystem__ErrorContext.baseTypes[0]);
  OOC_Config_FileSystem__repositoriesContext = (OOC_Config_FileSystem__ErrorContext)i0;
  Msg__InitContext((Msg__Context)i0, "OOC:Config:FileSystem", 22);
  i0 = (OOC_INT32)OOC_Config_FileSystem__NewRepositoryEntry();
  OOC_Config_Repositories__AddRepositoryEntry((OOC_Config_Repositories__RepositoryEntry)i0);
  return;
  ;
}

/* --- */
