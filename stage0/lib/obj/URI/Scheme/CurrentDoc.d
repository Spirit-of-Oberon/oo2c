static void* _c0;
#include <URI/Scheme/CurrentDoc.oh>
#include <CharClass.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_URI_Scheme_CurrentDoc__CurrentDoc = { (RT0__Struct[]){&_td_URI_Scheme_CurrentDoc__CurrentDocDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"CurrentDoc", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_URI_Scheme_CurrentDoc__CurrentDocDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_URI__URIDesc,&_td_URI_Scheme_CurrentDoc__CurrentDocDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)URI_Scheme_CurrentDoc__CurrentDocDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)URI_Scheme_CurrentDoc__CurrentDocDesc_Clone,(void*)URI_Scheme_CurrentDoc__CurrentDocDesc_Copy,(void*)URI__URIDesc_SetSchemeId,(void*)URI_Scheme_CurrentDoc__CurrentDocDesc_WriteXML,(void*)URI__URIDesc_AppendScheme,(void*)URI__URIDesc_MakeRelative,(void*)URI__URIDesc_GetChannel}, NULL, &_mid, (OOC_CHAR8*)"CurrentDocDesc", 4, 3, 0, RT0__strRecord };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"URI:Scheme:CurrentDoc", (RT0__Struct[]) { &_td_URI_Scheme_CurrentDoc__CurrentDoc, &_td_URI_Scheme_CurrentDoc__CurrentDocDesc, NULL }, 0 };

extern void OOC_URI_Scheme_CurrentDoc_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_TextRider_open(&_mid);
    OOC_CharClass_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_URI_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_URI_Scheme_CurrentDoc_init();
  }
  _mid.openCount++;
}
extern void OOC_URI_Scheme_CurrentDoc_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_URI_Scheme_CurrentDoc_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_TextRider_close(&_mid);
    OOC_CharClass_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_URI_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
