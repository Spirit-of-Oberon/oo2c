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
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:SSA:PRE", (RT0__Struct[]) { NULL }, 0 };

extern void OOC_OOC_SSA_PRE_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_Object_open(&_mid);
    OOC_ADT_ArrayList_open(&_mid);
    OOC_ADT_Dictionary_open(&_mid);
    OOC_OOC_SSA_open(&_mid);
    OOC_OOC_SSA_Opcode_open(&_mid);
    OOC_OOC_SSA_Opnd_open(&_mid);
    OOC_OOC_SSA_Result_open(&_mid);
    OOC_OOC_SSA_Blocker_open(&_mid);
    OOC_OOC_SSA_CSE_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OOC_SSA_PRE_init();
  }
  _mid.openCount++;
}
extern void OOC_OOC_SSA_PRE_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OOC_SSA_PRE_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_Object_close(&_mid);
    OOC_ADT_ArrayList_close(&_mid);
    OOC_ADT_Dictionary_close(&_mid);
    OOC_OOC_SSA_close(&_mid);
    OOC_OOC_SSA_Opcode_close(&_mid);
    OOC_OOC_SSA_Opnd_close(&_mid);
    OOC_OOC_SSA_Result_close(&_mid);
    OOC_OOC_SSA_Blocker_close(&_mid);
    OOC_OOC_SSA_CSE_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
