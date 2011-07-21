#include <OOC/X86/Machine.oh>
static OOC_X86_SSA__Opnd OOC_X86_Machine__ImmediateOpnd(OOC_X86_SSA__Instr instr);
static OOC_X86_SSA__Opnd OOC_X86_Machine__MemOpnd(OOC_X86_SSA__Instr instr);

/* run-time meta data */
static RT0__ModuleDesc _mid;
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:X86:Machine", (RT0__Struct[]) { NULL }, 0 };

extern void OOC_OOC_X86_Machine_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_OOC_X86_SSA_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OOC_X86_Machine_init();
  }
  _mid.openCount++;
}
extern void OOC_OOC_X86_Machine_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OOC_X86_Machine_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_OOC_X86_SSA_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
