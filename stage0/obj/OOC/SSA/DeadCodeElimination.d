#include <OOC/SSA/DeadCodeElimination.oh>
#include <OOC/SSA/Opnd.oh>
#define OOC_SSA_DeadCodeElimination__dead 0
#define OOC_SSA_DeadCodeElimination__live 1
static void OOC_SSA_DeadCodeElimination__MarkLive(OOC_SSA__Result res);
static void OOC_SSA_DeadCodeElimination__DeleteDeadCode(OOC_SSA__ProcBlock pb);

/* run-time meta data */
static RT0__ModuleDesc _mid;
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:SSA:DeadCodeElimination", (RT0__Struct[]) { NULL }, 0 };

extern void OOC_OOC_SSA_DeadCodeElimination_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_OOC_SSA_open(&_mid);
    OOC_OOC_SSA_Opcode_open(&_mid);
    OOC_OOC_SSA_Opnd_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OOC_SSA_DeadCodeElimination_init();
  }
  _mid.openCount++;
}
extern void OOC_OOC_SSA_DeadCodeElimination_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OOC_SSA_DeadCodeElimination_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_OOC_SSA_close(&_mid);
    OOC_OOC_SSA_Opcode_close(&_mid);
    OOC_OOC_SSA_Opnd_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
