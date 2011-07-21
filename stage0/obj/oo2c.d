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
#include <oo2c.oh>
#include <IO/StdChannels.oh>
#include <Out.oh>
#include <Err.oh>
#include <Object.oh>
#include <URI.oh>
#include <URI/Scheme/File.oh>
#include <Config.oh>
#include <ADT/StringBuffer.oh>
#include <IO.oh>
#include <OS/ProcessManagement.oh>
#include <OS/Path.oh>
#include <OS/Files.oh>
#include <Config/Section/Options.oh>
#include <OOC/Logger.oh>
#include <OOC/Config.oh>
#include <OOC/Config/CCompiler.oh>
#include <OOC/Package.oh>
#include <OOC/SymbolTable/Builder.oh>
#include <OOC/Config/StdPragmas.oh>
#include <OOC/Error.oh>
#include <OOC/Repository.oh>
#include <OOC/Repository/FileSystem.oh>
#include <OOC/Make.oh>
#include <OOC/SSA/Stats.oh>
#define oo2c__buildPackage (-1)
#define oo2c__installPackage (-2)
#define oo2c__uninstallPackage (-3)
#define oo2c__updateRepository (-4)
#define oo2c__getOption (-5)
#define oo2c__buildPackageDoc (-6)
#define oo2c__packageInstalled (-7)
#define oo2c__listPackages (-8)
static OOC_Error__List oo2c__cfgErrList;
static OOC_Error__List oo2c__errList;
static OOC_INT32 oo2c__i;
static Object__String oo2c__arg;
static OOC_INT8 oo2c__mode;
static Config_Section_Options__Option oo2c__command;
static Config_Section_Options__Option oo2c__forceUpdate;
static Config_Section_Options__Option oo2c__listUses;
static Config_Section_Options__Option oo2c__useStderr;
static Config_Section_Options__Option oo2c__writeStats;
static Config_Section_Options__Option oo2c__verbose;
static Config_Section_Options__Option oo2c__errorStyle;
static Config_Section_Options__Option oo2c__showHelp;
static Config_Section_Options__Option oo2c__showVersion;
static OOC_Make__Rules oo2c__makeRules;
static OOC_Repository__Repository oo2c__rep;
static OOC_Package__Repository oo2c__r;
static OOC_Package__Package oo2c__pkg;
static OOC_Package__Package oo2c__pkgInfo;
static OOC_CHAR8 oo2c__ok;
static OOC_CHAR8 oo2c__forceUpdateRepository;
static OOC_CHAR8 oo2c__doInstall;
static Config_Section_Options__Option oo2c__option;
static OOC_Repository__Module oo2c__module;
static void oo2c__NewConfig(void);
static OOC_Repository__Module oo2c__GetModule(Object__String moduleName);
static OOC_CHAR8 oo2c__BuildPackage(OOC_Package__Package pkg, OOC_Repository__Repository rep, OOC_CHAR8 install);
static void oo2c__UninstallPackage(OOC_Package__Package pkg);
static OOC_CHAR8 oo2c__BuildPackageDoc(OOC_Package__Package pkg);
static void oo2c__WriteHelp(void);

/* run-time meta data */
static RT0__ModuleDesc _mid;
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"oo2c", (RT0__Struct[]) { NULL }, 0 };

extern void OOC_oo2c_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_IO_StdChannels_open(&_mid);
    OOC_Out_open(&_mid);
    OOC_Err_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_URI_open(&_mid);
    OOC_URI_Scheme_File_open(&_mid);
    OOC_Config_open(&_mid);
    OOC_ADT_StringBuffer_open(&_mid);
    OOC_IO_open(&_mid);
    OOC_OS_ProcessManagement_open(&_mid);
    OOC_OS_Path_open(&_mid);
    OOC_OS_Files_open(&_mid);
    OOC_Config_Section_Options_open(&_mid);
    OOC_OOC_Logger_open(&_mid);
    OOC_OOC_Config_open(&_mid);
    OOC_OOC_Config_CCompiler_open(&_mid);
    OOC_OOC_Package_open(&_mid);
    OOC_OOC_SymbolTable_Builder_open(&_mid);
    OOC_OOC_Config_StdPragmas_open(&_mid);
    OOC_OOC_Error_open(&_mid);
    OOC_OOC_Repository_open(&_mid);
    OOC_OOC_Repository_FileSystem_open(&_mid);
    OOC_OOC_Make_open(&_mid);
    OOC_OOC_SSA_Stats_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_oo2c_init();
  }
  _mid.openCount++;
}
extern void OOC_oo2c_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_oo2c_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_IO_StdChannels_close(&_mid);
    OOC_Out_close(&_mid);
    OOC_Err_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_URI_close(&_mid);
    OOC_URI_Scheme_File_close(&_mid);
    OOC_Config_close(&_mid);
    OOC_ADT_StringBuffer_close(&_mid);
    OOC_IO_close(&_mid);
    OOC_OS_ProcessManagement_close(&_mid);
    OOC_OS_Path_close(&_mid);
    OOC_OS_Files_close(&_mid);
    OOC_Config_Section_Options_close(&_mid);
    OOC_OOC_Logger_close(&_mid);
    OOC_OOC_Config_close(&_mid);
    OOC_OOC_Config_CCompiler_close(&_mid);
    OOC_OOC_Package_close(&_mid);
    OOC_OOC_SymbolTable_Builder_close(&_mid);
    OOC_OOC_Config_StdPragmas_close(&_mid);
    OOC_OOC_Error_close(&_mid);
    OOC_OOC_Repository_close(&_mid);
    OOC_OOC_Repository_FileSystem_close(&_mid);
    OOC_OOC_Make_close(&_mid);
    OOC_OOC_SSA_Stats_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
