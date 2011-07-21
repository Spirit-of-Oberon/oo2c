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
static void* _c15;
static void* _c16;
static void* _c17;
static void* _c18;
static void* _c19;
static void* _c20;
static void* _c21;
static void* _c22;
static void* _c23;
static void* _c24;
static void* _c25;
static void* _c26;
static void* _c27;
#include <OOC/Repository.oh>
#include <Strings.oh>
#include <OS/Path.oh>
#include <OOC/Logger.oh>
#include <OOC/SymbolTable/Builder.oh>
OOC_CHAR8 OOC_Repository__readDocStrings;

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_Repository__URIBuffer = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, "URIBuffer", 1024, 1024, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_Repository__PkgInfo = { (RT0__Struct[]){&_td_OOC_Repository__PkgInfoDesc}, NULL, NULL, &_mid, "PkgInfo", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Repository__PkgInfoDesc = { (RT0__Struct[]){&_td_OOC_Repository__PkgInfoDesc}, (void*[]){}, NULL, &_mid, "PkgInfoDesc", 8, 0, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_Repository__Repository = { (RT0__Struct[]){&_td_OOC_Repository__RepositoryDesc}, NULL, NULL, &_mid, "Repository", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Repository__RepositoryDesc = { (RT0__Struct[]){&_td_OOC_Repository__RepositoryDesc}, (void*[]){(void*)OOC_Repository__RepositoryDesc_SetPackageInfo,(void*)OOC_Repository__RepositoryDesc_GetModule,(void*)OOC_Repository__RepositoryDesc_GetResource,(void*)OOC_Repository__RepositoryDesc_DumpContent,(void*)OOC_Repository__RepositoryDesc_GetLocalPath,(void*)OOC_Repository__RepositoryDesc_GetDefaultSubdir,(void*)OOC_Repository__RepositoryDesc_GetDefaultSuffix,(void*)OOC_Repository__RepositoryDesc_GetModuleByURI}, NULL, &_mid, "RepositoryDesc", 12, 0, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_Repository__Module = { (RT0__Struct[]){&_td_OOC_Repository__ModuleDesc}, NULL, NULL, &_mid, "Module", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Repository__Import = { (RT0__Struct[]){&_td_OOC_Repository__ImportDesc}, NULL, NULL, &_mid, "Import", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Repository__ImportDesc = { (RT0__Struct[]){&_td_OOC_Repository__ImportDesc}, (void*[]){}, NULL, &_mid, "ImportDesc", 8, 0, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_Repository__ModuleRef = { (RT0__Struct[]){&_td_OOC_Repository__ModuleRef}, (void*[]){}, NULL, &_mid, "ModuleRef", 16, 0, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_Repository__ModuleDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_OOC_Repository__ModuleDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)OOC_Repository__ModuleDesc_SetInterfaceData,(void*)OOC_Repository__ModuleDesc_SetFingerprint,(void*)OOC_Repository__ModuleDesc_GetImportedModule,(void*)OOC_Repository__ModuleDesc_GetInputBuffer,(void*)OOC_Repository__ModuleDesc_GetURI,(void*)OOC_Repository__ModuleDesc_MatchesURI,(void*)OOC_Repository__ModuleDesc_GetTimeStamp,(void*)OOC_Repository__ModuleDesc_FileExists,(void*)OOC_Repository__ModuleDesc_CreateOutputDir,(void*)OOC_Repository__ModuleDesc_GetOutputChannel,(void*)OOC_Repository__ModuleDesc_ReadSymbolFile}, NULL, &_mid, "ModuleDesc", 36, 2, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_Repository__3267 = { (RT0__Struct[]){&_td_OOC_Repository__ModuleRef}, NULL, NULL, &_mid, NULL, 16, 1, 0, RT0__strOpenArray };
RT0__StructDesc _td_OOC_Repository__3256 = { (RT0__Struct[]){&_td_OOC_Repository__3267}, NULL, NULL, &_mid, NULL, 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Repository__12075 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_Repository__12960 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_Repository__15512 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_Repository__19752 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:Repository", (RT0__Struct[]) { &_td_OOC_Repository__URIBuffer, &_td_OOC_Repository__PkgInfo, &_td_OOC_Repository__PkgInfoDesc, &_td_OOC_Repository__Repository, &_td_OOC_Repository__RepositoryDesc, &_td_OOC_Repository__Module, &_td_OOC_Repository__Import, &_td_OOC_Repository__ImportDesc, &_td_OOC_Repository__ModuleRef, &_td_OOC_Repository__ModuleDesc, NULL }, 0 };

extern void OOC_OOC_Repository_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_Msg_open(&_mid);
    OOC_TextRider_open(&_mid);
    OOC_Strings_open(&_mid);
    OOC_Time_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_ADT_ArrayList_open(&_mid);
    OOC_URI_open(&_mid);
    OOC_IO_open(&_mid);
    OOC_OS_Path_open(&_mid);
    OOC_OOC_Logger_open(&_mid);
    OOC_OOC_Scanner_InputBuffer_open(&_mid);
    OOC_OOC_SymbolTable_open(&_mid);
    OOC_OOC_SymbolTable_Builder_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OOC_Repository_init();
  }
  _mid.openCount++;
}
extern void OOC_OOC_Repository_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OOC_Repository_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_Msg_close(&_mid);
    OOC_TextRider_close(&_mid);
    OOC_Strings_close(&_mid);
    OOC_Time_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_ADT_ArrayList_close(&_mid);
    OOC_URI_close(&_mid);
    OOC_IO_close(&_mid);
    OOC_OS_Path_close(&_mid);
    OOC_OOC_Logger_close(&_mid);
    OOC_OOC_Scanner_InputBuffer_close(&_mid);
    OOC_OOC_SymbolTable_close(&_mid);
    OOC_OOC_SymbolTable_Builder_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
