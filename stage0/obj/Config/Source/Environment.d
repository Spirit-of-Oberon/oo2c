#include <Config/Source/Environment.oh>
#include <LongStrings.oh>
#include <OS/ProcessParameters.oh>
#include <IO/TextRider.oh>
static void Config_Source_Environment__Init(Config_Source_Environment__Environment env);
static void Config_Source_Environment__Append(Config_Source_Environment__VariableTemplate *list, Config_Source_Environment__VariableTemplate t);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_Config_Source_Environment__VariableTemplate = { (RT0__Struct[]){&_td_Config_Source_Environment__VariableTemplateDesc}, NULL, NULL, &_mid, "VariableTemplate", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Config_Source_Environment__VariableTemplateDesc = { (RT0__Struct[]){&_td_Config_Source_Environment__VariableTemplateDesc}, (void*[]){(void*)Config_Source_Environment__VariableTemplateDesc_INIT}, NULL, &_mid, "VariableTemplateDesc", 16, 0, 0, RT0__strRecord };
RT0__StructDesc _td_Config_Source_Environment__Command = { (RT0__Struct[]){&_td_Config_Source_Environment__CommandDesc}, NULL, NULL, &_mid, "Command", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Config_Source_Environment__CommandDesc = { (RT0__Struct[]){&_td_Config_Source_Environment__CommandDesc}, (void*[]){(void*)Config_Source_Environment__CommandDesc_DoNotWrite}, NULL, &_mid, "CommandDesc", 16, 0, 0, RT0__strRecord };
RT0__StructDesc _td_Config_Source_Environment__Environment = { (RT0__Struct[]){&_td_Config_Source_Environment__EnvironmentDesc}, NULL, NULL, &_mid, "Environment", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Config_Source_Environment__EnvironmentDesc = { (RT0__Struct[]){&_td_Config_Source__SourceDesc,&_td_Config_Source_Environment__EnvironmentDesc}, (void*[]){(void*)Config_Source_Environment__EnvironmentDesc_Write,(void*)Config_Source_Environment__EnvironmentDesc_AddVariableTemplate,(void*)Config_Source_Environment__EnvironmentDesc_AddListTemplate,(void*)Config_Source_Environment__EnvironmentDesc_Parse}, NULL, &_mid, "EnvironmentDesc", 8, 1, 0, RT0__strRecord };
RT0__StructDesc _td_Config_Source_Environment__5003 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1024, 1024, (1<<RT0__flagAtomic), RT0__strArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"Config:Source:Environment", (RT0__Struct[]) { &_td_Config_Source_Environment__VariableTemplate, &_td_Config_Source_Environment__VariableTemplateDesc, &_td_Config_Source_Environment__Command, &_td_Config_Source_Environment__CommandDesc, &_td_Config_Source_Environment__Environment, &_td_Config_Source_Environment__EnvironmentDesc, NULL }, 0 };

extern void OOC_Config_Source_Environment_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_Object_open(&_mid);
    OOC_Msg_open(&_mid);
    OOC_LongStrings_open(&_mid);
    OOC_OS_ProcessParameters_open(&_mid);
    OOC_IO_open(&_mid);
    OOC_IO_TextRider_open(&_mid);
    OOC_Config_Source_open(&_mid);
    OOC_Config_Parser_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_Config_Source_Environment_init();
  }
  _mid.openCount++;
}
extern void OOC_Config_Source_Environment_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_Config_Source_Environment_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_Object_close(&_mid);
    OOC_Msg_close(&_mid);
    OOC_LongStrings_close(&_mid);
    OOC_OS_ProcessParameters_close(&_mid);
    OOC_IO_close(&_mid);
    OOC_IO_TextRider_close(&_mid);
    OOC_Config_Source_close(&_mid);
    OOC_Config_Parser_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
