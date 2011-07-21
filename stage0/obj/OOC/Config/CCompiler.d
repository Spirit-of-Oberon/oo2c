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
static void* _c28;
static void* _c29;
static void* _c30;
static void* _c31;
static void* _c32;
static void* _c33;
static void* _c34;
static void* _c35;
static void* _c36;
static void* _c37;
static void* _c38;
static void* _c39;
static void* _c40;
static void* _c41;
static void* _c42;
static void* _c43;
static void* _c44;
static void* _c45;
static void* _c46;
static void* _c47;
static void* _c48;
static void* _c49;
static void* _c50;
static void* _c51;
#include <OOC/Config/CCompiler.oh>
#include <Object.oh>
#include <ADT/StringBuffer.oh>
#include <URI/Scheme/File.oh>
#include <OS/Path.oh>
#include <Config.oh>
#include <OOC/Logger.oh>
#include <OOC/Config.oh>
#include <OOC/Repository.oh>
static Config_Section_Options__Option OOC_Config_CCompiler__cc;
static Config_Section_Options__Option OOC_Config_CCompiler__cppflags;
static Config_Section_Options__Option OOC_Config_CCompiler__cflags;
static Config_Section_Options__Option OOC_Config_CCompiler__ldflags;
Config_Section_Options__Option OOC_Config_CCompiler__libs;
static Config_Section_Options__Option OOC_Config_CCompiler__libtool;
Config_Section_Options__Option OOC_Config_CCompiler__libdir;
Config_Section_Options__Option OOC_Config_CCompiler__install;
static Config_Section_Options__Option OOC_Config_CCompiler__installProgram;
Config_Section_Options__Option OOC_Config_CCompiler__installData;
Config_Section_Options__Option OOC_Config_CCompiler__uninstall;
Config_Section_Options__Option OOC_Config_CCompiler__bindir;
Config_Section_Options__Option OOC_Config_CCompiler__oocdir;
static ADT_StringBuffer__StringBuffer OOC_Config_CCompiler__SetCommand(Object__String mode);

/* run-time meta data */
static RT0__ModuleDesc _mid;
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:Config:CCompiler", (RT0__Struct[]) { NULL }, 0 };

extern void OOC_OOC_Config_CCompiler_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_Object_open(&_mid);
    OOC_ADT_StringBuffer_open(&_mid);
    OOC_URI_open(&_mid);
    OOC_URI_Scheme_File_open(&_mid);
    OOC_OS_Path_open(&_mid);
    OOC_Config_open(&_mid);
    OOC_Config_Section_Options_open(&_mid);
    OOC_OOC_Logger_open(&_mid);
    OOC_OOC_Config_open(&_mid);
    OOC_OOC_Package_open(&_mid);
    OOC_OOC_Repository_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OOC_Config_CCompiler_init();
  }
  _mid.openCount++;
}
extern void OOC_OOC_Config_CCompiler_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OOC_Config_CCompiler_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_Object_close(&_mid);
    OOC_ADT_StringBuffer_close(&_mid);
    OOC_URI_close(&_mid);
    OOC_URI_Scheme_File_close(&_mid);
    OOC_OS_Path_close(&_mid);
    OOC_Config_close(&_mid);
    OOC_Config_Section_Options_close(&_mid);
    OOC_OOC_Logger_close(&_mid);
    OOC_OOC_Config_close(&_mid);
    OOC_OOC_Package_close(&_mid);
    OOC_OOC_Repository_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
