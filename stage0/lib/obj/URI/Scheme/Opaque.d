static void* _c0;
static void* _c1;
#include <URI/Scheme/Opaque.oh>
#include <CharClass.oh>
#include <ADT/StringBuffer.oh>
#include <URI/CharClass.oh>
#include <URI/String.oh>
static OOC_INT16 URI_Scheme_Opaque__IsValidOpaqueStr(const OOC_CHAR8 str[], OOC_LEN str_0d);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_URI_Scheme_Opaque__Generic = { (RT0__Struct[]){&_td_URI_Scheme_Opaque__GenericDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"Generic", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_URI_Scheme_Opaque__GenericDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_URI__URIDesc,&_td_URI__OpaqueURIDesc,&_td_URI_Scheme_Opaque__GenericDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)URI_Scheme_Opaque__GenericDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)URI_Scheme_Opaque__GenericDesc_Clone,(void*)URI_Scheme_Opaque__GenericDesc_Copy,(void*)URI__URIDesc_SetSchemeId,(void*)URI_Scheme_Opaque__GenericDesc_WriteXML,(void*)URI__URIDesc_AppendScheme,(void*)URI__URIDesc_MakeRelative,(void*)URI__URIDesc_GetChannel,(void*)URI_Scheme_Opaque__GenericDesc_ParseOpaquePart}, NULL, &_mid, (OOC_CHAR8*)"GenericDesc", 8, 4, 0, RT0__strRecord };
RT0__StructDesc _td_URI_Scheme_Opaque__1870 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"URI:Scheme:Opaque", (RT0__Struct[]) { &_td_URI_Scheme_Opaque__Generic, &_td_URI_Scheme_Opaque__GenericDesc, NULL }, 0 };

extern void OOC_URI_Scheme_Opaque_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_TextRider_open(&_mid);
    OOC_CharClass_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);
    OOC_ADT_StringBuffer_open(&_mid);
    OOC_URI_open(&_mid);
    OOC_URI_CharClass_open(&_mid);
    OOC_URI_String_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_URI_Scheme_Opaque_init();
  }
  _mid.openCount++;
}
extern void OOC_URI_Scheme_Opaque_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_URI_Scheme_Opaque_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_TextRider_close(&_mid);
    OOC_CharClass_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
    OOC_ADT_StringBuffer_close(&_mid);
    OOC_URI_close(&_mid);
    OOC_URI_CharClass_close(&_mid);
    OOC_URI_String_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
