static void* _c0;
static void* _c1;
static void* _c2;
static void* _c3;
static void* _c4;
static void* _c5;
static void* _c6;
static void* _c7;
static void* _c8;
static void* _c9;
static void* _c10;
static void* _c11;
static void* _c12;
static void* _c13;
static void* _c14;
#include <URI/Scheme/Hierarchical.oh>
#include <CharClass.oh>
#include <URI/String.oh>
#include <URI/CharClass.oh>
#include <URI/Authority/Unparsed.oh>
#include <URI/Query/Unparsed.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_URI_Scheme_Hierarchical__Parameter = { (RT0__Struct[]){&_td_URI_Scheme_Hierarchical__ParameterDesc}, NULL, NULL, &_mid, "Parameter", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_URI_Scheme_Hierarchical__ParameterDesc = { (RT0__Struct[]){&_td_URI_Scheme_Hierarchical__ParameterDesc}, (void*[]){(void*)URI_Scheme_Hierarchical__ParameterDesc_Copy,(void*)URI_Scheme_Hierarchical__ParameterDesc_Clone,(void*)URI_Scheme_Hierarchical__ParameterDesc_WriteXML,(void*)URI_Scheme_Hierarchical__ParameterDesc_Append}, NULL, &_mid, "ParameterDesc", 8, 0, 0, RT0__strRecord };
RT0__StructDesc _td_URI_Scheme_Hierarchical__Segment = { (RT0__Struct[]){&_td_URI_Scheme_Hierarchical__SegmentDesc}, NULL, NULL, &_mid, "Segment", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_URI_Scheme_Hierarchical__SegmentDesc = { (RT0__Struct[]){&_td_URI_Scheme_Hierarchical__SegmentDesc}, (void*[]){(void*)URI_Scheme_Hierarchical__SegmentDesc_AppendParameter,(void*)URI_Scheme_Hierarchical__SegmentDesc_Copy,(void*)URI_Scheme_Hierarchical__SegmentDesc_Clone,(void*)URI_Scheme_Hierarchical__SegmentDesc_WriteXML,(void*)URI_Scheme_Hierarchical__SegmentDesc_Append}, NULL, &_mid, "SegmentDesc", 16, 0, 0, RT0__strRecord };
RT0__StructDesc _td_URI_Scheme_Hierarchical__Generic = { (RT0__Struct[]){&_td_URI_Scheme_Hierarchical__GenericDesc}, NULL, NULL, &_mid, "Generic", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_URI_Scheme_Hierarchical__GenericDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_URI__URIDesc,&_td_URI__HierarchicalURIDesc,&_td_URI_Scheme_Hierarchical__GenericDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)URI_Scheme_Hierarchical__GenericDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)URI_Scheme_Hierarchical__GenericDesc_Clone,(void*)URI_Scheme_Hierarchical__GenericDesc_Copy,(void*)URI__URIDesc_SetSchemeId,(void*)URI_Scheme_Hierarchical__GenericDesc_WriteXML,(void*)URI__URIDesc_AppendScheme,(void*)URI_Scheme_Hierarchical__GenericDesc_MakeRelative,(void*)URI__URIDesc_GetChannel,(void*)URI__HierarchicalURIDesc_AuthorityMandatory,(void*)URI_Scheme_Hierarchical__GenericDesc_NewAuthority,(void*)URI__HierarchicalURIDesc_SetAuthority,(void*)URI_Scheme_Hierarchical__GenericDesc_NewQuery,(void*)URI__HierarchicalURIDesc_SetQuery,(void*)URI_Scheme_Hierarchical__GenericDesc_ResolveRelative,(void*)URI_Scheme_Hierarchical__GenericDesc_ClearPath,(void*)URI_Scheme_Hierarchical__GenericDesc_ParsePath,(void*)URI_Scheme_Hierarchical__GenericDesc_AppendPath,(void*)URI_Scheme_Hierarchical__GenericDesc_AppendSegment,(void*)URI_Scheme_Hierarchical__GenericDesc_RemoveSegment,(void*)URI_Scheme_Hierarchical__GenericDesc_StripSegments}, NULL, &_mid, "GenericDesc", 20, 4, 0, RT0__strRecord };
RT0__StructDesc _td_URI_Scheme_Hierarchical__14013 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 32, 32, (1<<RT0__flagAtomic), RT0__strArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"URI:Scheme:Hierarchical", (RT0__Struct[]) { &_td_URI_Scheme_Hierarchical__Parameter, &_td_URI_Scheme_Hierarchical__ParameterDesc, &_td_URI_Scheme_Hierarchical__Segment, &_td_URI_Scheme_Hierarchical__SegmentDesc, &_td_URI_Scheme_Hierarchical__Generic, &_td_URI_Scheme_Hierarchical__GenericDesc, NULL } };

extern void OOC_URI_Scheme_Hierarchical_init0() {
  RT0__RegisterModule(&_mid);
  OOC_URI_Scheme_Hierarchical_init();
}

/* --- */
