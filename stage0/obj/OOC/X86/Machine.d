#include <OOC/X86/Machine.oh>
static OOC_X86_SSA__Opnd OOC_X86_Machine__ImmediateOpnd(OOC_X86_SSA__Instr instr);
static OOC_X86_SSA__Opnd OOC_X86_Machine__MemOpnd(OOC_X86_SSA__Instr instr);

/* run-time meta data */
static RT0__ModuleDesc _mid;
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:X86:Machine", (RT0__Struct[]) { NULL } };

extern void OOC_OOC_X86_Machine_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_X86_Machine_init();
}

/* --- */
