static void* _c0;
static void* _c1;
static void* _c2;
static void* _c3;
static void* _c4;
static void* _c5;
static void* _c6;
#include <OOC/Config.oh>
#include <RT0.oh>
#include <Config/Source/CmdLine.oh>
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
static Config_Simple__Config OOC_Config__config;
Config_Section_Options__Option OOC_Config__xsltproc;
static void OOC_Config__InitConfig(Object__String8 defaultConfigFile);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_Config__990 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:Config", (RT0__Struct[]) { NULL } };

extern void OOC_OOC_Config_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_Config_init();
}

/* --- */
