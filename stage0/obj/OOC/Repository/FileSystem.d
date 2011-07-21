static void* _c0;
static void* _c1;
static void* _c2;
static void* _c3;
static void* _c4;
static void* _c5;
#include <OOC/Repository/FileSystem.oh>
#include <Msg.oh>
#include <Files.oh>
#include <OS/Files.oh>
#include <OS/Path.oh>
#include <Exception.oh>
#include <ADT/StringBuffer.oh>
#include <URI/Parser.oh>
#include <URI/Scheme/File.oh>
#include <OOC/Logger.oh>
#include <OOC/Error.oh>
URI__HierarchicalURI OOC_Repository_FileSystem__baseURI;
static void OOC_Repository_FileSystem__InitModule(OOC_Repository_FileSystem__Module m, OOC_Repository_FileSystem__Repository origin, const Msg__String name__ref, OOC_LEN name_0d, URI__HierarchicalURI srcFileOverride);
static OOC_Repository_FileSystem__Module OOC_Repository_FileSystem__NewModule(OOC_Repository_FileSystem__Repository origin, const Msg__String name__ref, OOC_LEN name_0d, URI__HierarchicalURI srcFileOverride);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_Repository_FileSystem__Repository = { (RT0__Struct[]){&_td_OOC_Repository_FileSystem__RepositoryDesc}, NULL, NULL, &_mid, "Repository", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Repository_FileSystem__RepositoryDesc = { (RT0__Struct[]){&_td_OOC_Repository__RepositoryDesc,&_td_OOC_Repository_FileSystem__RepositoryDesc}, (void*[]){(void*)OOC_Repository__RepositoryDesc_SetPackageInfo,(void*)OOC_Repository_FileSystem__RepositoryDesc_GetModule,(void*)OOC_Repository_FileSystem__RepositoryDesc_GetResource,(void*)OOC_Repository_FileSystem__RepositoryDesc_DumpContent,(void*)OOC_Repository_FileSystem__RepositoryDesc_GetLocalPath,(void*)OOC_Repository__RepositoryDesc_GetDefaultSubdir,(void*)OOC_Repository__RepositoryDesc_GetDefaultSuffix,(void*)OOC_Repository__RepositoryDesc_GetModuleByURI}, NULL, &_mid, "RepositoryDesc", 16, 1, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_Repository_FileSystem__Module = { (RT0__Struct[]){&_td_OOC_Repository_FileSystem__ModuleDesc}, NULL, NULL, &_mid, "Module", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Repository_FileSystem__ModuleDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_OOC_Repository__ModuleDesc,&_td_OOC_Repository_FileSystem__ModuleDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)OOC_Repository__ModuleDesc_SetInterfaceData,(void*)OOC_Repository__ModuleDesc_SetFingerprint,(void*)OOC_Repository__ModuleDesc_GetImportedModule,(void*)OOC_Repository_FileSystem__ModuleDesc_GetInputBuffer,(void*)OOC_Repository_FileSystem__ModuleDesc_GetURI,(void*)OOC_Repository__ModuleDesc_MatchesURI,(void*)OOC_Repository_FileSystem__ModuleDesc_GetTimeStamp,(void*)OOC_Repository_FileSystem__ModuleDesc_FileExists,(void*)OOC_Repository_FileSystem__ModuleDesc_CreateOutputDir,(void*)OOC_Repository_FileSystem__ModuleDesc_GetOutputChannel,(void*)OOC_Repository__ModuleDesc_ReadSymbolFile}, NULL, &_mid, "ModuleDesc", 36, 3, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_Repository_FileSystem__2660 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_Repository_FileSystem__2961 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_Repository_FileSystem__4661 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:Repository:FileSystem", (RT0__Struct[]) { &_td_OOC_Repository_FileSystem__Repository, &_td_OOC_Repository_FileSystem__RepositoryDesc, &_td_OOC_Repository_FileSystem__Module, &_td_OOC_Repository_FileSystem__ModuleDesc, NULL } };

extern void OOC_OOC_Repository_FileSystem_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_Repository_FileSystem_init();
}

/* --- */
