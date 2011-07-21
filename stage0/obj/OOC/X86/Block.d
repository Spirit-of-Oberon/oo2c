#include <OOC/X86/Block.oh>
#include <Log.oh>
#include <OOC/X86/Debug.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:X86:Block", (RT0__Struct[]) { NULL }, 0 };

extern void OOC_OOC_X86_Block_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_OOC_X86_SSA_open(&_mid);
    OOC_Log_open(&_mid);
    OOC_OOC_X86_Debug_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OOC_X86_Block_init();
  }
  _mid.openCount++;
}
extern void OOC_OOC_X86_Block_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OOC_X86_Block_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_OOC_X86_SSA_close(&_mid);
    OOC_Log_close(&_mid);
    OOC_OOC_X86_Debug_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
