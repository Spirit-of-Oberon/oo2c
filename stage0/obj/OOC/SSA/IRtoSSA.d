#include <OOC/SSA/IRtoSSA.oh>
#include <Log.oh>
#include <Object.oh>
#include <Object/Boxed.oh>
#include <Object/BigInt.oh>
#include <OOC/SymbolTable.oh>
#include <OOC/SymbolTable/Predef.oh>
#include <OOC/SymbolTable/Builder.oh>
#include <OOC/SymbolTable/TypeRules.oh>
#include <OOC/SSA/Opcode.oh>
#include <OOC/SSA/Opnd.oh>
#include <OOC/SSA/Result.oh>
static void OOC_SSA_IRtoSSA__AddStoreBackwardFeed(OOC_SSA__ProcBlock pb, OOC_SSA__Instr loopEnd, OOC_SSA__Result storeArg);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_SSA_IRtoSSA__39289 = { (RT0__Struct[]){&_td_OOC_SSA__Result}, NULL, NULL, &_mid, NULL, 4, 1, 0, RT0__strOpenArray };
RT0__StructDesc _td_OOC_SSA_IRtoSSA__39278 = { (RT0__Struct[]){&_td_OOC_SSA_IRtoSSA__39289}, NULL, NULL, &_mid, NULL, 4, -1, 0, RT0__strPointer };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:SSA:IRtoSSA", (RT0__Struct[]) { NULL }, 0 };

extern void OOC_OOC_SSA_IRtoSSA_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_Log_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Object_Boxed_open(&_mid);
    OOC_Object_BigInt_open(&_mid);
    OOC_OOC_SymbolTable_open(&_mid);
    OOC_OOC_SymbolTable_Predef_open(&_mid);
    OOC_OOC_SymbolTable_Builder_open(&_mid);
    OOC_OOC_SymbolTable_TypeRules_open(&_mid);
    OOC_OOC_IR_open(&_mid);
    OOC_OOC_SSA_open(&_mid);
    OOC_OOC_SSA_Opcode_open(&_mid);
    OOC_OOC_SSA_Opnd_open(&_mid);
    OOC_OOC_SSA_Result_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OOC_SSA_IRtoSSA_init();
  }
  _mid.openCount++;
}
extern void OOC_OOC_SSA_IRtoSSA_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OOC_SSA_IRtoSSA_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_Log_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Object_Boxed_close(&_mid);
    OOC_Object_BigInt_close(&_mid);
    OOC_OOC_SymbolTable_close(&_mid);
    OOC_OOC_SymbolTable_Predef_close(&_mid);
    OOC_OOC_SymbolTable_Builder_close(&_mid);
    OOC_OOC_SymbolTable_TypeRules_close(&_mid);
    OOC_OOC_IR_close(&_mid);
    OOC_OOC_SSA_close(&_mid);
    OOC_OOC_SSA_Opcode_close(&_mid);
    OOC_OOC_SSA_Opnd_close(&_mid);
    OOC_OOC_SSA_Result_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
