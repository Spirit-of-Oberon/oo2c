static void* _c0;
static void* _c1;
#include <OOC/Config/Assembler.oh>
#include <ADT/StringBuffer.oh>
#include <URI/Scheme/File.oh>
#include <OS/Path.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:Config:Assembler", (RT0__Struct[]) { NULL }, 0 };

extern void OOC_OOC_Config_Assembler_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_ADT_StringBuffer_open(&_mid);
    OOC_URI_open(&_mid);
    OOC_URI_Scheme_File_open(&_mid);
    OOC_OS_Path_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OOC_Config_Assembler_init();
  }
  _mid.openCount++;
}
extern void OOC_OOC_Config_Assembler_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OOC_Config_Assembler_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_ADT_StringBuffer_close(&_mid);
    OOC_URI_close(&_mid);
    OOC_URI_Scheme_File_close(&_mid);
    OOC_OS_Path_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
