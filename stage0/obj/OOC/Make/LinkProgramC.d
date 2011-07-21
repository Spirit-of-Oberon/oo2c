static void* _c0;
static void* _c1;
static void* _c2;
static void* _c3;
static void* _c4;
static void* _c5;
static void* _c6;
static void* _c7;
#include <OOC/Make/LinkProgramC.oh>
#include <URI.oh>
#include <URI/Scheme/File.oh>
#include <Object.oh>
#include <ADT/Dictionary.oh>
#include <ADT/ArrayList.oh>
#include <ADT/StringBuffer.oh>
#include <Config.oh>
#include <OS/ProcessManagement.oh>
#include <OS/Path.oh>
#include <OOC/Logger.oh>
#include <OOC/Config.oh>
#include <OOC/Config/CCompiler.oh>
#include <OOC/SymbolTable.oh>
static Object__String OOC_Make_LinkProgramC__empty;
static Object__String OOC_Make_LinkProgramC__space;
static Object__StringArrayPtr OOC_Make_LinkProgramC__GetExternalLibs(const OOC_Repository__Module moduleList__ref[], OOC_LEN moduleList_0d, Object__String thisLibrary);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_Make_LinkProgramC__1265 = { (RT0__Struct[]){&_td_OOC_Repository__Module}, NULL, NULL, &_mid, NULL, 4, 1, 0, RT0__strOpenArray };
RT0__StructDesc _td_OOC_Make_LinkProgramC__5932 = { (RT0__Struct[]){&_td_OOC_Repository__Module}, NULL, NULL, &_mid, NULL, 4, 1, 0, RT0__strOpenArray };
static RT0__StructDesc _td__qtd0 = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_ADT_Storable__ObjectDesc,&_td__qtd0}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)ADT_Dictionary__DictionaryDesc_Equals,(void*)ADT_Dictionary__DictionaryDesc_HashCode,(void*)ADT_Dictionary__DictionaryDesc_Store,(void*)ADT_Dictionary__DictionaryDesc_Load,(void*)ADT_Dictionary__DictionaryDesc_INIT,(void*)ADT_Dictionary__DictionaryDesc_Destroy,(void*)ADT_Dictionary__DictionaryDesc_Lookup,(void*)ADT_Dictionary__DictionaryDesc_Insert,(void*)ADT_Dictionary__DictionaryDesc_Resize,(void*)ADT_Dictionary__DictionaryDesc_HasKey,(void*)ADT_Dictionary__DictionaryDesc_Size,(void*)ADT_Dictionary__DictionaryDesc_Get,(void*)ADT_Dictionary__DictionaryDesc_Set,(void*)ADT_Dictionary__DictionaryDesc_Copy,(void*)ADT_Dictionary__DictionaryDesc_Delete,(void*)ADT_Dictionary__DictionaryDesc_Clear,(void*)ADT_Dictionary__DictionaryDesc_Keys,(void*)ADT_Dictionary__DictionaryDesc_Values,(void*)ADT_Dictionary__DictionaryDesc_Items,(void*)ADT_Dictionary__DictionaryDesc_IterKeys,(void*)ADT_Dictionary__DictionaryDesc_IterValues}, (RT0__Struct[]){&_td_ADT_Dictionary__DictionaryDesc, &_td_Object__String, &_td_ADT_ArrayList__ArrayList, NULL}, &_mid, "ADT:Dictionary.DictionaryDesc(Object.String,ADT:ArrayList.ArrayList(Object.Object))", 20, 3, 0, RT0__strQualType };
static RT0__StructDesc _td__qtd1 = { (RT0__Struct[]){&_td__qtd0}, NULL, (RT0__Struct[]){&_td_ADT_Dictionary__Dictionary, &_td_Object__String, &_td_ADT_ArrayList__ArrayList, NULL}, &_mid, "ADT:Dictionary.Dictionary(Object.String,ADT:ArrayList.ArrayList(Object.Object))", 4, 0, 0, RT0__strQualType };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:Make:LinkProgramC", (RT0__Struct[]) { &_td__qtd0, &_td__qtd1, NULL }, 0 };

extern void OOC_OOC_Make_LinkProgramC_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_IO_open(&_mid);
    OOC_URI_open(&_mid);
    OOC_URI_Scheme_File_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_ADT_Dictionary_open(&_mid);
    OOC_ADT_ArrayList_open(&_mid);
    OOC_ADT_StringBuffer_open(&_mid);
    OOC_Config_open(&_mid);
    OOC_OS_ProcessManagement_open(&_mid);
    OOC_OS_Path_open(&_mid);
    OOC_OOC_Package_open(&_mid);
    OOC_OOC_Repository_open(&_mid);
    OOC_OOC_Logger_open(&_mid);
    OOC_OOC_Config_open(&_mid);
    OOC_OOC_Config_CCompiler_open(&_mid);
    OOC_OOC_SymbolTable_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OOC_Make_LinkProgramC_init();
  }
  _mid.openCount++;
}
extern void OOC_OOC_Make_LinkProgramC_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OOC_Make_LinkProgramC_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_IO_close(&_mid);
    OOC_URI_close(&_mid);
    OOC_URI_Scheme_File_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_ADT_Dictionary_close(&_mid);
    OOC_ADT_ArrayList_close(&_mid);
    OOC_ADT_StringBuffer_close(&_mid);
    OOC_Config_close(&_mid);
    OOC_OS_ProcessManagement_close(&_mid);
    OOC_OS_Path_close(&_mid);
    OOC_OOC_Package_close(&_mid);
    OOC_OOC_Repository_close(&_mid);
    OOC_OOC_Logger_close(&_mid);
    OOC_OOC_Config_close(&_mid);
    OOC_OOC_Config_CCompiler_close(&_mid);
    OOC_OOC_SymbolTable_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
