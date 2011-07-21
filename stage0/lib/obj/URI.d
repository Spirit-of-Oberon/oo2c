static void* _c0;
static void* _c1;
static void* _c2;
static void* _c3;
#include <URI.oh>
#include <CharClass.oh>
typedef struct URI__ListDesc *URI__List;
typedef struct URI__ListDesc {
  URI__List next;
  URI__URI scheme;
} URI__ListDesc;
static URI__List URI__schemeList;

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_URI__URI = { (RT0__Struct[]){&_td_URI__URIDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"URI", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_URI__URIDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_URI__URIDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)URI__URIDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)URI__URIDesc_Clone,(void*)URI__URIDesc_Copy,(void*)URI__URIDesc_SetSchemeId,(void*)URI__URIDesc_WriteXML,(void*)URI__URIDesc_AppendScheme,(void*)URI__URIDesc_MakeRelative,(void*)URI__URIDesc_GetChannel}, NULL, &_mid, (OOC_CHAR8*)"URIDesc", 4, 2, 0, RT0__strRecord };
RT0__StructDesc _td_URI__Authority = { (RT0__Struct[]){&_td_URI__AuthorityDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"Authority", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_URI__AuthorityDesc = { (RT0__Struct[]){&_td_URI__AuthorityDesc}, (void*[]){(void*)URI__AuthorityDesc_Clone,(void*)URI__AuthorityDesc_Copy,(void*)URI__AuthorityDesc_ParseAuthority,(void*)URI__AuthorityDesc_WriteXML,(void*)URI__AuthorityDesc_Append}, NULL, &_mid, (OOC_CHAR8*)"AuthorityDesc", 0, 0, (1<<RT0__flagAtomic), RT0__strRecord };
RT0__StructDesc _td_URI__Query = { (RT0__Struct[]){&_td_URI__QueryDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"Query", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_URI__QueryDesc = { (RT0__Struct[]){&_td_URI__QueryDesc}, (void*[]){(void*)URI__QueryDesc_Clone,(void*)URI__QueryDesc_Copy,(void*)URI__QueryDesc_ParseQuery,(void*)URI__QueryDesc_WriteXML,(void*)URI__QueryDesc_Append}, NULL, &_mid, (OOC_CHAR8*)"QueryDesc", 0, 0, (1<<RT0__flagAtomic), RT0__strRecord };
RT0__StructDesc _td_URI__Fragment = { (RT0__Struct[]){&_td_URI__FragmentDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"Fragment", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_URI__FragmentDesc = { (RT0__Struct[]){&_td_URI__FragmentDesc}, (void*[]){(void*)URI__FragmentDesc_Clone,(void*)URI__FragmentDesc_Copy,(void*)URI__FragmentDesc_ParseFragment,(void*)URI__FragmentDesc_WriteXML,(void*)URI__FragmentDesc_Append}, NULL, &_mid, (OOC_CHAR8*)"FragmentDesc", 0, 0, (1<<RT0__flagAtomic), RT0__strRecord };
RT0__StructDesc _td_URI__HierarchicalURI = { (RT0__Struct[]){&_td_URI__HierarchicalURIDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"HierarchicalURI", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_URI__HierarchicalURIDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_URI__URIDesc,&_td_URI__HierarchicalURIDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)URI__URIDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)URI__URIDesc_Clone,(void*)URI__HierarchicalURIDesc_Copy,(void*)URI__URIDesc_SetSchemeId,(void*)URI__URIDesc_WriteXML,(void*)URI__URIDesc_AppendScheme,(void*)URI__HierarchicalURIDesc_MakeRelative,(void*)URI__URIDesc_GetChannel,(void*)URI__HierarchicalURIDesc_AuthorityMandatory,(void*)URI__HierarchicalURIDesc_NewAuthority,(void*)URI__HierarchicalURIDesc_SetAuthority,(void*)URI__HierarchicalURIDesc_NewQuery,(void*)URI__HierarchicalURIDesc_SetQuery,(void*)URI__HierarchicalURIDesc_ResolveRelative,(void*)URI__HierarchicalURIDesc_ClearPath,(void*)URI__HierarchicalURIDesc_ParsePath,(void*)URI__HierarchicalURIDesc_AppendPath}, NULL, &_mid, (OOC_CHAR8*)"HierarchicalURIDesc", 12, 3, 0, RT0__strRecord };
RT0__StructDesc _td_URI__OpaqueURI = { (RT0__Struct[]){&_td_URI__OpaqueURIDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"OpaqueURI", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_URI__OpaqueURIDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_URI__URIDesc,&_td_URI__OpaqueURIDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)URI__URIDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)URI__URIDesc_Clone,(void*)URI__URIDesc_Copy,(void*)URI__URIDesc_SetSchemeId,(void*)URI__URIDesc_WriteXML,(void*)URI__URIDesc_AppendScheme,(void*)URI__URIDesc_MakeRelative,(void*)URI__URIDesc_GetChannel,(void*)URI__OpaqueURIDesc_ParseOpaquePart}, NULL, &_mid, (OOC_CHAR8*)"OpaqueURIDesc", 4, 3, 0, RT0__strRecord };
RT0__StructDesc _td_URI__Reference = { (RT0__Struct[]){&_td_URI__ReferenceDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"Reference", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_URI__ReferenceDesc = { (RT0__Struct[]){&_td_URI__ReferenceDesc}, (void*[]){(void*)URI__ReferenceDesc_WriteXML,(void*)URI__ReferenceDesc_ToString}, NULL, &_mid, (OOC_CHAR8*)"ReferenceDesc", 8, 0, 0, RT0__strRecord };
RT0__StructDesc _td_URI__List = { (RT0__Struct[]){&_td_URI__ListDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"List", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_URI__ListDesc = { (RT0__Struct[]){&_td_URI__ListDesc}, (void*[]){}, NULL, &_mid, (OOC_CHAR8*)"ListDesc", 8, 0, 0, RT0__strRecord };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"URI", (RT0__Struct[]) { &_td_URI__URI, &_td_URI__URIDesc, &_td_URI__Authority, &_td_URI__AuthorityDesc, &_td_URI__Query, &_td_URI__QueryDesc, &_td_URI__Fragment, &_td_URI__FragmentDesc, &_td_URI__HierarchicalURI, &_td_URI__HierarchicalURIDesc, &_td_URI__OpaqueURI, &_td_URI__OpaqueURIDesc, &_td_URI__Reference, &_td_URI__ReferenceDesc, &_td_URI__List, &_td_URI__ListDesc, NULL }, 0 };

extern void OOC_URI_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_CharClass_open(&_mid);
    OOC_TextRider_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);
    OOC_IO_open(&_mid);
    OOC_ADT_StringBuffer_open(&_mid);
    OOC_URI_String_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_URI_init();
  }
  _mid.openCount++;
}
extern void OOC_URI_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_URI_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_CharClass_close(&_mid);
    OOC_TextRider_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
    OOC_IO_close(&_mid);
    OOC_ADT_StringBuffer_close(&_mid);
    OOC_URI_String_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
