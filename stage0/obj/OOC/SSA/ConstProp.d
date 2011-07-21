#include <OOC/SSA/ConstProp.oh>
#include <Object/Boxed.oh>
#include <Object/BigInt.oh>
#include <OOC/SSA/Opcode.oh>
#include <OOC/SSA/Opnd.oh>
#include <OOC/SSA/Result.oh>
#include <OOC/SSA/DeadCodeElimination.oh>
typedef struct OOC_SSA_ConstProp__WorklistDesc *OOC_SSA_ConstProp__Worklist;
typedef struct OOC_SSA_ConstProp__WorklistDesc {
  OOC_SSA_ConstProp__Worklist next;
  OOC_SSA__Instr instr;
} OOC_SSA_ConstProp__WorklistDesc;
#define OOC_SSA_ConstProp__unclassified  0
static OOC_SSA__Result OOC_SSA_ConstProp__notConstant;
static OOC_SSA__Const OOC_SSA_ConstProp__ComputeConst(OOC_SSA__ProcBlock pb, OOC_SSA__Instr instr);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_SSA_ConstProp__Worklist = { (RT0__Struct[]){&_td_OOC_SSA_ConstProp__WorklistDesc}, NULL, NULL, &_mid, "Worklist", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_ConstProp__WorklistDesc = { (RT0__Struct[]){&_td_OOC_SSA_ConstProp__WorklistDesc}, (void*[]){}, NULL, &_mid, "WorklistDesc", 8, 0, 0, RT0__strRecord };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:SSA:ConstProp", (RT0__Struct[]) { &_td_OOC_SSA_ConstProp__Worklist, &_td_OOC_SSA_ConstProp__WorklistDesc, NULL }, 0 };

extern void OOC_OOC_SSA_ConstProp_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_Object_Boxed_open(&_mid);
    OOC_Object_BigInt_open(&_mid);
    OOC_OOC_SSA_open(&_mid);
    OOC_OOC_SSA_Opcode_open(&_mid);
    OOC_OOC_SSA_Opnd_open(&_mid);
    OOC_OOC_SSA_Result_open(&_mid);
    OOC_OOC_SSA_DeadCodeElimination_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OOC_SSA_ConstProp_init();
  }
  _mid.openCount++;
}
extern void OOC_OOC_SSA_ConstProp_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OOC_SSA_ConstProp_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_Object_Boxed_close(&_mid);
    OOC_Object_BigInt_close(&_mid);
    OOC_OOC_SSA_close(&_mid);
    OOC_OOC_SSA_Opcode_close(&_mid);
    OOC_OOC_SSA_Opnd_close(&_mid);
    OOC_OOC_SSA_Result_close(&_mid);
    OOC_OOC_SSA_DeadCodeElimination_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
