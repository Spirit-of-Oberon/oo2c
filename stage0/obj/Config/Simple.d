static void* _c0;
static void* _c1;
static void* _c2;
static void* _c3;
#include <Config/Simple.oh>
#include <ProgramArgs.oh>
#include <IO/Memory.oh>
#include <Config/Source.oh>
#define Config_Simple__rootName "configuration"

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_Config_Simple__Config = { (RT0__Struct[]){&_td_Config_Simple__ConfigDesc}, NULL, NULL, &_mid, "Config", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Config_Simple__ConfigDesc = { (RT0__Struct[]){&_td_Config__ConfigDesc,&_td_Config_Simple__ConfigDesc}, (void*[]){(void*)Config_Simple__ConfigDesc_ConfigFileEnvVar,(void*)Config_Simple__ConfigDesc_ConfigFileCmdLineOption,(void*)Config_Simple__ConfigDesc_Read}, NULL, &_mid, "ConfigDesc", 40, 1, 0, RT0__strRecord };
static RT0__StructDesc _td__qtd0 = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_ADT_Storable__ObjectDesc,&_td__qtd0}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)ADT_Dictionary__DictionaryDesc_Equals,(void*)ADT_Dictionary__DictionaryDesc_HashCode,(void*)ADT_Dictionary__DictionaryDesc_Store,(void*)ADT_Dictionary__DictionaryDesc_Load,(void*)ADT_Dictionary__DictionaryDesc_INIT,(void*)ADT_Dictionary__DictionaryDesc_Destroy,(void*)ADT_Dictionary__DictionaryDesc_Lookup,(void*)ADT_Dictionary__DictionaryDesc_Insert,(void*)ADT_Dictionary__DictionaryDesc_Resize,(void*)ADT_Dictionary__DictionaryDesc_HasKey,(void*)ADT_Dictionary__DictionaryDesc_Size,(void*)ADT_Dictionary__DictionaryDesc_Get,(void*)ADT_Dictionary__DictionaryDesc_Set,(void*)ADT_Dictionary__DictionaryDesc_Copy,(void*)ADT_Dictionary__DictionaryDesc_Delete,(void*)ADT_Dictionary__DictionaryDesc_Clear,(void*)ADT_Dictionary__DictionaryDesc_Keys,(void*)ADT_Dictionary__DictionaryDesc_Values,(void*)ADT_Dictionary__DictionaryDesc_Items,(void*)ADT_Dictionary__DictionaryDesc_IterKeys,(void*)ADT_Dictionary__DictionaryDesc_IterValues}, (RT0__Struct[]){&_td_ADT_Dictionary__DictionaryDesc, &_td_Object__String, &_td_Config__Variable, NULL}, &_mid, "ADT:Dictionary.DictionaryDesc(Object.String,Config.Variable)", 20, 3, 0, RT0__strQualType };
static RT0__StructDesc _td__qtd1 = { (RT0__Struct[]){&_td__qtd0}, NULL, (RT0__Struct[]){&_td_ADT_Dictionary__Dictionary, &_td_Object__String, &_td_Config__Variable, NULL}, &_mid, "ADT:Dictionary.Dictionary(Object.String,Config.Variable)", 4, 0, 0, RT0__strQualType };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"Config:Simple", (RT0__Struct[]) { &_td_Config_Simple__Config, &_td_Config_Simple__ConfigDesc, &_td__qtd0, &_td__qtd1, NULL }, 0 };

extern void OOC_Config_Simple_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_Msg_open(&_mid);
    OOC_ProgramArgs_open(&_mid);
    OOC_IO_open(&_mid);
    OOC_IO_Memory_open(&_mid);
    OOC_Config_open(&_mid);
    OOC_Config_Parser_open(&_mid);
    OOC_Config_Source_open(&_mid);
    OOC_Config_Source_Environment_open(&_mid);
    OOC_Config_Source_CmdLine_open(&_mid);
    OOC_Config_Section_open(&_mid);
    OOC_Config_Section_Options_open(&_mid);
    OOC_Config_Section_Arguments_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_Config_Simple_init();
  }
  _mid.openCount++;
}
extern void OOC_Config_Simple_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_Config_Simple_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_Msg_close(&_mid);
    OOC_ProgramArgs_close(&_mid);
    OOC_IO_close(&_mid);
    OOC_IO_Memory_close(&_mid);
    OOC_Config_close(&_mid);
    OOC_Config_Parser_close(&_mid);
    OOC_Config_Source_close(&_mid);
    OOC_Config_Source_Environment_close(&_mid);
    OOC_Config_Source_CmdLine_close(&_mid);
    OOC_Config_Section_close(&_mid);
    OOC_Config_Section_Options_close(&_mid);
    OOC_Config_Section_Arguments_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
