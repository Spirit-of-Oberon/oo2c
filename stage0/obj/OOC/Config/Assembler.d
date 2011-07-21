static void* _c0;
static void* _c1;
#include <OOC/Config/Assembler.oh>
#include <ADT/StringBuffer.oh>
#include <URI/Scheme/File.oh>
#include <OS/Path.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:Config:Assembler", (RT0__Struct[]) { NULL } };

extern void OOC_OOC_Config_Assembler_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_Config_Assembler_init();
}

/* --- */
