#include <Config/Source/Environment.oh>
#include <LongStrings.oh>
#include <OS/ProcessParameters.oh>
#include <IO/TextRider.oh>
static void Config_Source_Environment__Init(Config_Source_Environment__Environment env);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_Config_Source_Environment__VariableTemplate = { (RT0__Struct[]){&_td_Config_Source_Environment__VariableTemplateDesc}, NULL, NULL, &_mid, "VariableTemplate", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Config_Source_Environment__VariableTemplateDesc = { (RT0__Struct[]){&_td_Config_Source_Environment__VariableTemplateDesc}, (void*[]){}, NULL, &_mid, "VariableTemplateDesc", 12, 0, 0, RT0__strRecord };
RT0__StructDesc _td_Config_Source_Environment__Command = { (RT0__Struct[]){&_td_Config_Source_Environment__CommandDesc}, NULL, NULL, &_mid, "Command", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Config_Source_Environment__CommandDesc = { (RT0__Struct[]){&_td_Config_Source_Environment__CommandDesc}, (void*[]){(void*)Config_Source_Environment__CommandDesc_DoNotWrite}, NULL, &_mid, "CommandDesc", 16, 0, 0, RT0__strRecord };
RT0__StructDesc _td_Config_Source_Environment__Environment = { (RT0__Struct[]){&_td_Config_Source_Environment__EnvironmentDesc}, NULL, NULL, &_mid, "Environment", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Config_Source_Environment__EnvironmentDesc = { (RT0__Struct[]){&_td_Config_Source__SourceDesc,&_td_Config_Source_Environment__EnvironmentDesc}, (void*[]){(void*)Config_Source_Environment__EnvironmentDesc_Write,(void*)Config_Source_Environment__EnvironmentDesc_AddVariableTemplate,(void*)Config_Source_Environment__EnvironmentDesc_Parse}, NULL, &_mid, "EnvironmentDesc", 8, 1, 0, RT0__strRecord };
RT0__StructDesc _td_Config_Source_Environment__3605 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1024, 1024, (1<<RT0__flagAtomic), RT0__strArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"Config:Source:Environment", (RT0__Struct[]) { &_td_Config_Source_Environment__VariableTemplate, &_td_Config_Source_Environment__VariableTemplateDesc, &_td_Config_Source_Environment__Command, &_td_Config_Source_Environment__CommandDesc, &_td_Config_Source_Environment__Environment, &_td_Config_Source_Environment__EnvironmentDesc, NULL } };

extern void OOC_Config_Source_Environment_init0() {
  RT0__RegisterModule(&_mid);
  OOC_Config_Source_Environment_init();
}

/* --- */
