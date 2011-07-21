#include <OOC/Config/FileSystem.oh>
#include <LongStrings.oh>
#include <Strings.oh>
#include <Exception.oh>
#include <URI.oh>
#include <URI/Parser.oh>
#include <URI/Scheme/File.oh>
#include <XML/DTD.oh>
#include <XML/Builder.oh>
#include <OOC/Repository/FileSystem.oh>
#define OOC_Config_FileSystem__invalidAttribute 1
#define OOC_Config_FileSystem__requireCharDataContent 2
#define OOC_Config_FileSystem__invalidURI 3
static OOC_Config_FileSystem__ErrorContext OOC_Config_FileSystem__repositoriesContext;
static OOC_Config_FileSystem__RepositoryEntry OOC_Config_FileSystem__NewRepositoryEntry(void);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_Config_FileSystem__RepositoryEntry = { (RT0__Struct[]){&_td_OOC_Config_FileSystem__RepositoryEntryDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"RepositoryEntry", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Config_FileSystem__RepositoryEntryDesc = { (RT0__Struct[]){&_td_OOC_Config_Repositories__RepositoryEntryDesc,&_td_OOC_Config_FileSystem__RepositoryEntryDesc}, (void*[]){(void*)OOC_Config_FileSystem__RepositoryEntryDesc_ProcessElement}, NULL, &_mid, (OOC_CHAR8*)"RepositoryEntryDesc", 68, 1, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_Config_FileSystem__ErrorContext = { (RT0__Struct[]){&_td_OOC_Config_FileSystem__ErrorContextDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"ErrorContext", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Config_FileSystem__ErrorContextDesc = { (RT0__Struct[]){&_td_Msg__ContextDesc,&_td_XML_Error__ContextDesc,&_td_Config_Section__ErrorContextDesc,&_td_OOC_Config_FileSystem__ErrorContextDesc}, (void*[]){(void*)OOC_Config_FileSystem__ErrorContextDesc_GetTemplate,(void*)XML_Error__ContextDesc_WriteTemplate,(void*)XML_Error__ContextDesc_SetString}, NULL, &_mid, (OOC_CHAR8*)"ErrorContextDesc", 8, 3, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_Config_FileSystem__1708 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 256, 128, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_Config_FileSystem__2649 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 4096, 4096, (1<<RT0__flagAtomic), RT0__strArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:Config:FileSystem", (RT0__Struct[]) { &_td_OOC_Config_FileSystem__RepositoryEntry, &_td_OOC_Config_FileSystem__RepositoryEntryDesc, &_td_OOC_Config_FileSystem__ErrorContext, &_td_OOC_Config_FileSystem__ErrorContextDesc, NULL }, 0 };

extern void OOC_OOC_Config_FileSystem_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_Msg_open(&_mid);
    OOC_LongStrings_open(&_mid);
    OOC_Strings_open(&_mid);
    OOC_Exception_open(&_mid);
    OOC_URI_open(&_mid);
    OOC_URI_Parser_open(&_mid);
    OOC_URI_Scheme_File_open(&_mid);
    OOC_XML_DTD_open(&_mid);
    OOC_XML_Builder_open(&_mid);
    OOC_XML_Locator_open(&_mid);
    OOC_Config_Parser_open(&_mid);
    OOC_Config_Section_open(&_mid);
    OOC_OOC_Config_Repositories_open(&_mid);
    OOC_OOC_Repository_open(&_mid);
    OOC_OOC_Repository_FileSystem_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OOC_Config_FileSystem_init();
  }
  _mid.openCount++;
}
extern void OOC_OOC_Config_FileSystem_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OOC_Config_FileSystem_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_Msg_close(&_mid);
    OOC_LongStrings_close(&_mid);
    OOC_Strings_close(&_mid);
    OOC_Exception_close(&_mid);
    OOC_URI_close(&_mid);
    OOC_URI_Parser_close(&_mid);
    OOC_URI_Scheme_File_close(&_mid);
    OOC_XML_DTD_close(&_mid);
    OOC_XML_Builder_close(&_mid);
    OOC_XML_Locator_close(&_mid);
    OOC_Config_Parser_close(&_mid);
    OOC_Config_Section_close(&_mid);
    OOC_OOC_Config_Repositories_close(&_mid);
    OOC_OOC_Repository_close(&_mid);
    OOC_OOC_Repository_FileSystem_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
