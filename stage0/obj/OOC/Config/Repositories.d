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
RT0__StructDesc _td_OOC_Config_Repositories__Section = { (RT0__Struct[]){&_td_OOC_Config_Repositories__SectionDesc}, NULL, NULL, &_mid, "Section", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Config_Repositories__1204 = { (RT0__Struct[]){&_td_OOC_Repository__Module}, NULL, NULL, &_mid, NULL, 4, 1, 0, RT0__strOpenArray };
RT0__StructDesc _td_OOC_Config_Repositories__ModuleList = { (RT0__Struct[]){&_td_OOC_Config_Repositories__1204}, NULL, NULL, &_mid, "ModuleList", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Config_Repositories__SectionDesc = { (RT0__Struct[]){&_td_Config_Section__SectionDesc,&_td_OOC_Config_Repositories__SectionDesc}, (void*[]){(void*)OOC_Config_Repositories__SectionDesc_ProcessElements,(void*)OOC_Config_Repositories__SectionDesc_DumpContent,(void*)OOC_Config_Repositories__SectionDesc_GetModule,(void*)OOC_Config_Repositories__SectionDesc_GetResource,(void*)OOC_Config_Repositories__SectionDesc_GetIncludePaths}, NULL, &_mid, "SectionDesc", 16, 1, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_Config_Repositories__RepositoryEntry = { (RT0__Struct[]){&_td_OOC_Config_Repositories__RepositoryEntryDesc}, NULL, NULL, &_mid, "RepositoryEntry", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Config_Repositories__RepositoryEntryDesc = { (RT0__Struct[]){&_td_OOC_Config_Repositories__RepositoryEntryDesc}, (void*[]){(void*)OOC_Config_Repositories__RepositoryEntryDesc_ProcessElement}, NULL, &_mid, "RepositoryEntryDesc", 68, 0, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_Config_Repositories__1511 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 64, 32, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_Config_Repositories__ErrorContext = { (RT0__Struct[]){&_td_OOC_Config_Repositories__ErrorContextDesc}, NULL, NULL, &_mid, "ErrorContext", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Config_Repositories__ErrorContextDesc = { (RT0__Struct[]){&_td_Msg__ContextDesc,&_td_XML_Error__ContextDesc,&_td_Config_Section__ErrorContextDesc,&_td_OOC_Config_Repositories__ErrorContextDesc}, (void*[]){(void*)OOC_Config_Repositories__ErrorContextDesc_GetTemplate,(void*)XML_Error__ContextDesc_WriteTemplate,(void*)XML_Error__ContextDesc_SetString}, NULL, &_mid, "ErrorContextDesc", 8, 3, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_Config_Repositories__1927 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 256, 128, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_Config_Repositories__2664 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_Config_Repositories__4484 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 2048, 2048, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_Config_Repositories__5091 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_Config_Repositories__8863 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:Config:Repositories", (RT0__Struct[]) { &_td_OOC_Config_Repositories__Section, &_td_OOC_Config_Repositories__ModuleList, &_td_OOC_Config_Repositories__SectionDesc, &_td_OOC_Config_Repositories__RepositoryEntry, &_td_OOC_Config_Repositories__RepositoryEntryDesc, &_td_OOC_Config_Repositories__ErrorContext, &_td_OOC_Config_Repositories__ErrorContextDesc, NULL } };

extern void OOC_OOC_Config_Repositories_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_Config_Repositories_init();
}

/* --- */
