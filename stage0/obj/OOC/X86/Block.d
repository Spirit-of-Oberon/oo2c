#include <OOC/X86/Block.oh>
#include <Log.oh>
#include <OOC/X86/Debug.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:X86:Block", (RT0__Struct[]) { NULL } };

extern void OOC_OOC_X86_Block_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_X86_Block_init();
}

/* --- */
