#include <OOC/Config/Repositories.oh>
#include <TextRider.oh>
#include <LongStrings.oh>
#include <URI/Scheme/File.oh>
#include <OOC/Repository/FileSystem.oh>
#define OOC_Config_Repositories__invalidContent 1
#define OOC_Config_Repositories__invalidAttribute 2
#define OOC_Config_Repositories__requireEmpty 3
static OOC_Config_Repositories__ErrorContext OOC_Config_Repositories__repositoriesContext;
static OOC_Config_Repositories__RepositoryEntry OOC_Config_Repositories__repositoryEntries;
static void OOC_Config_Repositories__Init(OOC_Config_Repositories__Section s, const Config_Parser__String id__ref, OOC_LEN id_0d);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_Config_Repositories__Section = { (RT0__Struct[]){&_td_OOC_Config_Repositories__SectionDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"Section", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Config_Repositories__1204 = { (RT0__Struct[]){&_td_OOC_Repository__Module}, NULL, NULL, &_mid, NULL, 4, 1, 0, RT0__strOpenArray };
RT0__StructDesc _td_OOC_Config_Repositories__ModuleList = { (RT0__Struct[]){&_td_OOC_Config_Repositories__1204}, NULL, NULL, &_mid, (OOC_CHAR8*)"ModuleList", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Config_Repositories__SectionDesc = { (RT0__Struct[]){&_td_Config_Section__SectionDesc,&_td_OOC_Config_Repositories__SectionDesc}, (void*[]){(void*)OOC_Config_Repositories__SectionDesc_ProcessElements,(void*)OOC_Config_Repositories__SectionDesc_DumpContent,(void*)OOC_Config_Repositories__SectionDesc_GetModule,(void*)OOC_Config_Repositories__SectionDesc_GetResource,(void*)OOC_Config_Repositories__SectionDesc_GetIncludePaths}, NULL, &_mid, (OOC_CHAR8*)"SectionDesc", 16, 1, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_Config_Repositories__RepositoryEntry = { (RT0__Struct[]){&_td_OOC_Config_Repositories__RepositoryEntryDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"RepositoryEntry", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Config_Repositories__RepositoryEntryDesc = { (RT0__Struct[]){&_td_OOC_Config_Repositories__RepositoryEntryDesc}, (void*[]){(void*)OOC_Config_Repositories__RepositoryEntryDesc_ProcessElement}, NULL, &_mid, (OOC_CHAR8*)"RepositoryEntryDesc", 68, 0, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_Config_Repositories__1511 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 64, 32, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_Config_Repositories__ErrorContext = { (RT0__Struct[]){&_td_OOC_Config_Repositories__ErrorContextDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"ErrorContext", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Config_Repositories__ErrorContextDesc = { (RT0__Struct[]){&_td_Msg__ContextDesc,&_td_XML_Error__ContextDesc,&_td_Config_Section__ErrorContextDesc,&_td_OOC_Config_Repositories__ErrorContextDesc}, (void*[]){(void*)OOC_Config_Repositories__ErrorContextDesc_GetTemplate,(void*)XML_Error__ContextDesc_WriteTemplate,(void*)XML_Error__ContextDesc_SetString}, NULL, &_mid, (OOC_CHAR8*)"ErrorContextDesc", 8, 3, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_Config_Repositories__1927 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 256, 128, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_Config_Repositories__2664 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_Config_Repositories__4484 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 2048, 2048, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_Config_Repositories__5091 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_Config_Repositories__8863 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:Config:Repositories", (RT0__Struct[]) { &_td_OOC_Config_Repositories__Section, &_td_OOC_Config_Repositories__ModuleList, &_td_OOC_Config_Repositories__SectionDesc, &_td_OOC_Config_Repositories__RepositoryEntry, &_td_OOC_Config_Repositories__RepositoryEntryDesc, &_td_OOC_Config_Repositories__ErrorContext, &_td_OOC_Config_Repositories__ErrorContextDesc, NULL }, 0 };

extern void OOC_OOC_Config_Repositories_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_Msg_open(&_mid);
    OOC_Channel_open(&_mid);
    OOC_TextRider_open(&_mid);
    OOC_LongStrings_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_URI_open(&_mid);
    OOC_URI_Scheme_File_open(&_mid);
    OOC_XML_DTD_open(&_mid);
    OOC_XML_Locator_open(&_mid);
    OOC_Config_Parser_open(&_mid);
    OOC_Config_Section_open(&_mid);
    OOC_OOC_Repository_open(&_mid);
    OOC_OOC_Repository_FileSystem_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OOC_Config_Repositories_init();
  }
  _mid.openCount++;
}
extern void OOC_OOC_Config_Repositories_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OOC_Config_Repositories_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_Msg_close(&_mid);
    OOC_Channel_close(&_mid);
    OOC_TextRider_close(&_mid);
    OOC_LongStrings_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_URI_close(&_mid);
    OOC_URI_Scheme_File_close(&_mid);
    OOC_XML_DTD_close(&_mid);
    OOC_XML_Locator_close(&_mid);
    OOC_Config_Parser_close(&_mid);
    OOC_Config_Section_close(&_mid);
    OOC_OOC_Repository_close(&_mid);
    OOC_OOC_Repository_FileSystem_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
