static void* _c0;
static void* _c1;
static void* _c2;
static void* _c3;
static void* _c4;
static void* _c5;
static void* _c6;
static void* _c7;
static void* _c8;
#include <OOC/Config.oh>
#include <RT0.oh>
#include <Config/Source/CmdLine.oh>
#include <Config/Source/Environment.oh>
#include <Config/Simple.oh>
#include <Object.oh>
#include <OOC/Config/StdPragmas.oh>
#include <OOC/Config/Autoconf.oh>
#include <OOC/Config/FileSystem.oh>
Config_Section_Options__Section OOC_Config__options;
static Config_Source_CmdLine__CmdLine OOC_Config__cmdLine;
Config_Section_Arguments__Section OOC_Config__arguments;
OOC_Config_Pragmas__Section OOC_Config__pragmas;
OOC_Config_Repositories__Section OOC_Config__repositories;
#define OOC_Config__configEnvVar "OO2CRC"
#define OOC_Config__repositoryListEnvVar "OOC_REPS"
static Config_Simple__Config OOC_Config__config;
Config_Section_Options__Option OOC_Config__xsltproc;
static void OOC_Config__InitConfig(Object__String8 defaultConfigFile);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_Config__1054 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:Config", (RT0__Struct[]) { NULL }, 0 };

extern void OOC_OOC_Config_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_RT0_open(&_mid);
    OOC_Msg_open(&_mid);
    OOC_IO_open(&_mid);
    OOC_Config_open(&_mid);
    OOC_Config_Source_CmdLine_open(&_mid);
    OOC_Config_Source_Environment_open(&_mid);
    OOC_Config_Section_Options_open(&_mid);
    OOC_Config_Section_Arguments_open(&_mid);
    OOC_Config_Simple_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_OOC_Config_Pragmas_open(&_mid);
    OOC_OOC_Config_StdPragmas_open(&_mid);
    OOC_OOC_Config_Autoconf_open(&_mid);
    OOC_OOC_Config_Repositories_open(&_mid);
    OOC_OOC_Config_FileSystem_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OOC_Config_init();
  }
  _mid.openCount++;
}
extern void OOC_OOC_Config_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OOC_Config_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_RT0_close(&_mid);
    OOC_Msg_close(&_mid);
    OOC_IO_close(&_mid);
    OOC_Config_close(&_mid);
    OOC_Config_Source_CmdLine_close(&_mid);
    OOC_Config_Source_Environment_close(&_mid);
    OOC_Config_Section_Options_close(&_mid);
    OOC_Config_Section_Arguments_close(&_mid);
    OOC_Config_Simple_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_OOC_Config_Pragmas_close(&_mid);
    OOC_OOC_Config_StdPragmas_close(&_mid);
    OOC_OOC_Config_Autoconf_close(&_mid);
    OOC_OOC_Config_Repositories_close(&_mid);
    OOC_OOC_Config_FileSystem_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
