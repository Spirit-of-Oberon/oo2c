#include <OOC/SSA/PRE.oh>
#include <Object.oh>
#include <ADT/ArrayList.oh>
#include <ADT/Dictionary.oh>
#include <OOC/SSA/Opnd.oh>
#include <OOC/SSA/Result.oh>
#include <OOC/SSA/Blocker.oh>
#include <OOC/SSA/CSE.oh>
static OOC_SSA__Instr OOC_SSA_PRE__GetSelect(OOC_SSA__Instr collect);
static OOC_SSA__Instr OOC_SSA_PRE__GetNoop(OOC_SSA__ProcBlock pb, OOC_SSA__Result storeOut);

/* run-time meta data */
static RT0__ModuleDesc _mid;
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:SSA:PRE", (RT0__Struct[]) { NULL } };

extern void OOC_OOC_SSA_PRE_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_SSA_PRE_init();
}

/* --- */
