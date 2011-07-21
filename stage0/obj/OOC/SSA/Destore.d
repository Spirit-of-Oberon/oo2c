#include <OOC/SSA/Destore.oh>
#include <ADT/ArrayList.oh>
#include <OOC/SymbolTable.oh>
#include <OOC/SSA/Opnd.oh>
#include <OOC/SSA/Result.oh>
#include <OOC/SSA/Aliasing.oh>
typedef struct OOC_SSA_Destore__CacheEntryDesc *OOC_SSA_Destore__CacheEntry;
typedef struct OOC_SSA_Destore__CacheEntryDesc {
  OOC_SSA_Destore__CacheEntry next;
  OOC_SSA__Opnd design;
  OOC_SSA__Result value;
} OOC_SSA_Destore__CacheEntryDesc;
typedef struct OOC_SSA_Destore__WorklistDesc *OOC_SSA_Destore__Worklist;
typedef struct OOC_SSA_Destore__WorklistDesc {
  OOC_SSA_Destore__Worklist next;
  OOC_SSA__Instr instr;
} OOC_SSA_Destore__WorklistDesc;
#define OOC_SSA_Destore__read 0
#define OOC_SSA_Destore__write 1
static OOC_CHAR8 OOC_SSA_Destore__IsLocalVariable(OOC_SSA__ProcBlock pb, OOC_SymbolTable__Declaration decl);
static void OOC_SSA_Destore__InitState(OOC_SSA_Destore__State *s, OOC_SSA__ProcBlock pb);
static OOC_CHAR8 OOC_SSA_Destore__AccessedByCall(OOC_SSA_Destore__State s, OOC_SSA__Result calledAdr, OOC_SSA__Opnd design, OOC_INT8 mode);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_SSA_Destore__State = { (RT0__Struct[]){&_td_OOC_SSA_Destore__StateDesc}, NULL, NULL, &_mid, "State", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_Destore__StateDesc = { (RT0__Struct[]){&_td_OOC_SSA_Destore__StateDesc}, (void*[]){(void*)OOC_SSA_Destore__StateDesc_ClobberedBy,(void*)OOC_SSA_Destore__StateDesc_Transform}, NULL, &_mid, "StateDesc", 8, 0, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_SSA_Destore__CacheEntry = { (RT0__Struct[]){&_td_OOC_SSA_Destore__CacheEntryDesc}, NULL, NULL, &_mid, "CacheEntry", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_Destore__CacheEntryDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_OOC_SSA__NodeDesc,&_td_OOC_SSA_Destore__CacheEntryDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode}, NULL, &_mid, "CacheEntryDesc", 12, 3, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_SSA_Destore__Worklist = { (RT0__Struct[]){&_td_OOC_SSA_Destore__WorklistDesc}, NULL, NULL, &_mid, "Worklist", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_Destore__WorklistDesc = { (RT0__Struct[]){&_td_OOC_SSA_Destore__WorklistDesc}, (void*[]){}, NULL, &_mid, "WorklistDesc", 8, 0, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_SSA_Destore__8825 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:SSA:Destore", (RT0__Struct[]) { &_td_OOC_SSA_Destore__State, &_td_OOC_SSA_Destore__StateDesc, &_td_OOC_SSA_Destore__CacheEntry, &_td_OOC_SSA_Destore__CacheEntryDesc, &_td_OOC_SSA_Destore__Worklist, &_td_OOC_SSA_Destore__WorklistDesc, NULL }, 0 };

extern void OOC_OOC_SSA_Destore_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_ADT_Dictionary_open(&_mid);
    OOC_ADT_ArrayList_open(&_mid);
    OOC_OOC_SymbolTable_open(&_mid);
    OOC_OOC_SSA_open(&_mid);
    OOC_OOC_SSA_Opcode_open(&_mid);
    OOC_OOC_SSA_Opnd_open(&_mid);
    OOC_OOC_SSA_Result_open(&_mid);
    OOC_OOC_SSA_Aliasing_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OOC_SSA_Destore_init();
  }
  _mid.openCount++;
}
extern void OOC_OOC_SSA_Destore_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OOC_SSA_Destore_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_ADT_Dictionary_close(&_mid);
    OOC_ADT_ArrayList_close(&_mid);
    OOC_OOC_SymbolTable_close(&_mid);
    OOC_OOC_SSA_close(&_mid);
    OOC_OOC_SSA_Opcode_close(&_mid);
    OOC_OOC_SSA_Opnd_close(&_mid);
    OOC_OOC_SSA_Result_close(&_mid);
    OOC_OOC_SSA_Aliasing_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
