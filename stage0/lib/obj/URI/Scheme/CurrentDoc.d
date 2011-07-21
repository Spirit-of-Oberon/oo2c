static void* _c0;
#include <URI/Scheme/CurrentDoc.oh>
#include <CharClass.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_URI_Scheme_CurrentDoc__CurrentDoc = { (RT0__Struct[]){&_td_URI_Scheme_CurrentDoc__CurrentDocDesc}, NULL, NULL, &_mid, "CurrentDoc", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_URI_Scheme_CurrentDoc__CurrentDocDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_URI__URIDesc,&_td_URI_Scheme_CurrentDoc__CurrentDocDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)URI_Scheme_CurrentDoc__CurrentDocDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)URI_Scheme_CurrentDoc__CurrentDocDesc_Clone,(void*)URI_Scheme_CurrentDoc__CurrentDocDesc_Copy,(void*)URI__URIDesc_SetSchemeId,(void*)URI_Scheme_CurrentDoc__CurrentDocDesc_WriteXML,(void*)URI__URIDesc_AppendScheme,(void*)URI__URIDesc_MakeRelative,(void*)URI__URIDesc_GetChannel}, NULL, &_mid, "CurrentDocDesc", 4, 3, 0, RT0__strRecord };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"URI:Scheme:CurrentDoc", (RT0__Struct[]) { &_td_URI_Scheme_CurrentDoc__CurrentDoc, &_td_URI_Scheme_CurrentDoc__CurrentDocDesc, NULL } };

extern void OOC_URI_Scheme_CurrentDoc_init0() {
  RT0__RegisterModule(&_mid);
  OOC_URI_Scheme_CurrentDoc_init();
}

/* --- */
