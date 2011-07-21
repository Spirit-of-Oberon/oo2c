#include <OOC/SSA/DeadCodeElimination.oh>
#include <OOC/SSA/Opnd.oh>
#define OOC_SSA_DeadCodeElimination__dead 0
#define OOC_SSA_DeadCodeElimination__live 1
static void OOC_SSA_DeadCodeElimination__MarkLive(OOC_SSA__Result res);
static void OOC_SSA_DeadCodeElimination__DeleteDeadCode(OOC_SSA__ProcBlock pb);

/* run-time meta data */
static RT0__ModuleDesc _mid;
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:SSA:DeadCodeElimination", (RT0__Struct[]) { NULL } };

extern void OOC_OOC_SSA_DeadCodeElimination_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_SSA_DeadCodeElimination_init();
}

/* --- */
