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
#include <OOC/Config/StdPragmas.oh>
#include <Config.oh>
#include <OOC/Config/Autoconf.oh>
#define OOC_Config_StdPragmas__defaultWarnings OOC_TRUE
#define OOC_Config_StdPragmas__defaultAssertions OOC_TRUE
#define OOC_Config_StdPragmas__defaultStackCheck OOC_FALSE
#define OOC_Config_StdPragmas__defaultConformantMode OOC_FALSE
#define OOC_Config_StdPragmas__defaultIndexCheck OOC_TRUE
#define OOC_Config_StdPragmas__defaultDerefCheck OOC_TRUE
#define OOC_Config_StdPragmas__defaultOverflowCheck OOC_FALSE
#define OOC_Config_StdPragmas__defaultCaseSelectCheck OOC_TRUE
#define OOC_Config_StdPragmas__defaultFunctionResultCheck OOC_TRUE
#define OOC_Config_StdPragmas__defaultTypeGuard OOC_TRUE
#define OOC_Config_StdPragmas__defaultRangeCheck OOC_FALSE
#define OOC_Config_StdPragmas__defaultCompiler "OOC"
#define OOC_Config_StdPragmas__defaultCompilerMajor 2
#define OOC_Config_StdPragmas__defaultCompilerMinor 1
#define OOC_Config_StdPragmas__defaultTargetOS "Unix"
#define OOC_Config_StdPragmas__defaultTargetInteger 64
#define OOC_Config_StdPragmas__defaultTargetAddress 32
#define OOC_Config_StdPragmas__defaultTargetArchMinor ""
Config_Section_Options__Option OOC_Config_StdPragmas__warnings;
Config_Section_Options__Option OOC_Config_StdPragmas__assertions;
Config_Section_Options__Option OOC_Config_StdPragmas__stackCheck;
Config_Section_Options__Option OOC_Config_StdPragmas__conformantMode;
Config_Section_Options__Option OOC_Config_StdPragmas__indexCheck;
Config_Section_Options__Option OOC_Config_StdPragmas__derefCheck;
Config_Section_Options__Option OOC_Config_StdPragmas__overflowCheck;
Config_Section_Options__Option OOC_Config_StdPragmas__caseSelectCheck;
Config_Section_Options__Option OOC_Config_StdPragmas__functionResultCheck;
Config_Section_Options__Option OOC_Config_StdPragmas__typeGuard;
Config_Section_Options__Option OOC_Config_StdPragmas__rangeCheck;
Config_Section_Options__Option OOC_Config_StdPragmas__compiler;
Config_Section_Options__Option OOC_Config_StdPragmas__compilerVersion;
Config_Section_Options__Option OOC_Config_StdPragmas__compilerMajor;
Config_Section_Options__Option OOC_Config_StdPragmas__compilerMinor;
Config_Section_Options__Option OOC_Config_StdPragmas__targetOS;
Config_Section_Options__Option OOC_Config_StdPragmas__targetArch;
Config_Section_Options__Option OOC_Config_StdPragmas__targetArchMinor;
Config_Section_Options__Option OOC_Config_StdPragmas__targetInteger;
Config_Section_Options__Option OOC_Config_StdPragmas__targetAddress;
Config_Section_Options__Option OOC_Config_StdPragmas__targetByteOrder;

/* run-time meta data */
static RT0__ModuleDesc _mid;
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:Config:StdPragmas", (RT0__Struct[]) { NULL }, 0 };

extern void OOC_OOC_Config_StdPragmas_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_Config_open(&_mid);
    OOC_OOC_Config_Autoconf_open(&_mid);
    OOC_OOC_Config_Pragmas_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OOC_Config_StdPragmas_init();
  }
  _mid.openCount++;
}
extern void OOC_OOC_Config_StdPragmas_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OOC_Config_StdPragmas_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_Config_close(&_mid);
    OOC_OOC_Config_Autoconf_close(&_mid);
    OOC_OOC_Config_Pragmas_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
