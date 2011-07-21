static void* _c0;
static void* _c1;
static void* _c2;
static void* _c3;
static void* _c4;
static void* _c5;
static void* _c6;
static void* _c7;
#include <URI/Scheme/File.oh>
#include <OS/ProcessParameters.oh>
#include <OS/HostPath.oh>
#include <Exception.oh>
#include <ADT/StringBuffer.oh>
#include <IO/FileChannel.oh>
#include <URI/CharClass.oh>
#include <URI/String.oh>
#include <URI/Parser.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_URI_Scheme_File__URI = { (RT0__Struct[]){&_td_URI_Scheme_File__URIDesc}, NULL, NULL, &_mid, "URI", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_URI_Scheme_File__URIDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_URI__URIDesc,&_td_URI__HierarchicalURIDesc,&_td_URI_Scheme_Hierarchical__GenericDesc,&_td_URI_Scheme_File__URIDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)URI_Scheme_Hierarchical__GenericDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)URI_Scheme_File__URIDesc_Clone,(void*)URI_Scheme_Hierarchical__GenericDesc_Copy,(void*)URI__URIDesc_SetSchemeId,(void*)URI_Scheme_Hierarchical__GenericDesc_WriteXML,(void*)URI__URIDesc_AppendScheme,(void*)URI_Scheme_Hierarchical__GenericDesc_MakeRelative,(void*)URI_Scheme_File__URIDesc_GetChannel,(void*)URI_Scheme_File__URIDesc_AuthorityMandatory,(void*)URI_Scheme_File__URIDesc_NewAuthority,(void*)URI__HierarchicalURIDesc_SetAuthority,(void*)URI_Scheme_File__URIDesc_NewQuery,(void*)URI__HierarchicalURIDesc_SetQuery,(void*)URI_Scheme_Hierarchical__GenericDesc_ResolveRelative,(void*)URI_Scheme_Hierarchical__GenericDesc_ClearPath,(void*)URI_Scheme_Hierarchical__GenericDesc_ParsePath,(void*)URI_Scheme_Hierarchical__GenericDesc_AppendPath,(void*)URI_Scheme_Hierarchical__GenericDesc_AppendSegment,(void*)URI_Scheme_Hierarchical__GenericDesc_RemoveSegment,(void*)URI_Scheme_Hierarchical__GenericDesc_StripSegments,(void*)URI_Scheme_File__URIDesc_GetPath}, NULL, &_mid, "URIDesc", 20, 5, 0, RT0__strRecord };
RT0__StructDesc _td_URI_Scheme_File__4610 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"URI:Scheme:File", (RT0__Struct[]) { &_td_URI_Scheme_File__URI, &_td_URI_Scheme_File__URIDesc, NULL }, 0 };

extern void OOC_URI_Scheme_File_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_OS_ProcessParameters_open(&_mid);
    OOC_OS_HostPath_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);
    OOC_ADT_StringBuffer_open(&_mid);
    OOC_IO_open(&_mid);
    OOC_IO_FileChannel_open(&_mid);
    OOC_URI_open(&_mid);
    OOC_URI_CharClass_open(&_mid);
    OOC_URI_String_open(&_mid);
    OOC_URI_Scheme_Hierarchical_open(&_mid);
    OOC_URI_Authority_ServerBased_open(&_mid);
    OOC_URI_Parser_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_URI_Scheme_File_init();
  }
  _mid.openCount++;
}
extern void OOC_URI_Scheme_File_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_URI_Scheme_File_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_OS_ProcessParameters_close(&_mid);
    OOC_OS_HostPath_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
    OOC_ADT_StringBuffer_close(&_mid);
    OOC_IO_close(&_mid);
    OOC_IO_FileChannel_close(&_mid);
    OOC_URI_close(&_mid);
    OOC_URI_CharClass_close(&_mid);
    OOC_URI_String_close(&_mid);
    OOC_URI_Scheme_Hierarchical_close(&_mid);
    OOC_URI_Authority_ServerBased_close(&_mid);
    OOC_URI_Parser_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
