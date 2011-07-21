#include <OOC/SSA/Blocker.oh>
#include <Object.oh>
#include <Object/BigInt.oh>
#include <ADT/Dictionary/IntValue.oh>
#include <IO/TextRider.oh>
#include <IO/StdChannels.oh>
#include <OOC/SSA/DeadCodeElimination.oh>
#include <OOC/SSA/Destore.oh>
static void OOC_SSA_Blocker__InitProxy(OOC_SSA_Blocker__Proxy p, OOC_SSA__Instr instr);
static OOC_SSA_Blocker__Proxy OOC_SSA_Blocker__NewProxy(OOC_SSA__Instr instr);
static void OOC_SSA_Blocker__ClearMarkers(OOC_SSA_Blocker__Region r);
static void OOC_SSA_Blocker__InitRegion(OOC_SSA_Blocker__Region r, OOC_SSA__Instr instr);
static OOC_SSA_Blocker__Region OOC_SSA_Blocker__NewRegion(OOC_SSA__Instr instr);
static void OOC_SSA_Blocker__InitSelect(OOC_SSA_Blocker__Select r, OOC_SSA__Instr instr);
static OOC_SSA_Blocker__Select OOC_SSA_Blocker__NewSelect(OOC_SSA__Instr instr);
static void OOC_SSA_Blocker__InitLoop(OOC_SSA_Blocker__Loop r, OOC_SSA__Instr instr);
static OOC_SSA_Blocker__Loop OOC_SSA_Blocker__NewLoop(OOC_SSA__Instr instr);
static OOC_SSA_Blocker__Proxy OOC_SSA_Blocker__GetProxy(OOC_SSA__Instr instr);
static OOC_CHAR8 OOC_SSA_Blocker__Dominates(OOC_SSA_Blocker__Region dom, OOC_SSA_Blocker__Region child);
static void OOC_SSA_Blocker__WriteBlocks(IO__ByteChannel c, OOC_SSA__ProcBlock pb, OOC_SSA_Blocker__Region root, ADT_Dictionary__Dictionary marker);
static OOC_CHAR8 OOC_SSA_Blocker__AntiDepViolation(OOC_SSA__ProcBlock pb, OOC_SSA_Blocker__Region root);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_SSA_Blocker__Proxy = { (RT0__Struct[]){&_td_OOC_SSA_Blocker__ProxyDesc}, NULL, NULL, &_mid, "Proxy", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_Blocker__Region = { (RT0__Struct[]){&_td_OOC_SSA_Blocker__RegionDesc}, NULL, NULL, &_mid, "Region", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_Blocker__Select = { (RT0__Struct[]){&_td_OOC_SSA_Blocker__SelectDesc}, NULL, NULL, &_mid, "Select", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_Blocker__Loop = { (RT0__Struct[]){&_td_OOC_SSA_Blocker__LoopDesc}, NULL, NULL, &_mid, "Loop", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_Blocker__ProxyDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_OOC_SSA__NodeDesc,&_td_OOC_SSA_Blocker__ProxyDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode}, NULL, &_mid, "ProxyDesc", 48, 3, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_SSA_Blocker__RegionDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_OOC_SSA__NodeDesc,&_td_OOC_SSA_Blocker__ProxyDesc,&_td_OOC_SSA_Blocker__RegionDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)OOC_SSA_Blocker__RegionDesc_Append,(void*)OOC_SSA_Blocker__RegionDesc_Insert,(void*)OOC_SSA_Blocker__RegionDesc_Remove}, NULL, &_mid, "RegionDesc", 60, 4, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_SSA_Blocker__SelectDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_OOC_SSA__NodeDesc,&_td_OOC_SSA_Blocker__ProxyDesc,&_td_OOC_SSA_Blocker__RegionDesc,&_td_OOC_SSA_Blocker__SelectDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)OOC_SSA_Blocker__RegionDesc_Append,(void*)OOC_SSA_Blocker__RegionDesc_Insert,(void*)OOC_SSA_Blocker__RegionDesc_Remove}, NULL, &_mid, "SelectDesc", 64, 5, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_SSA_Blocker__5567 = { (RT0__Struct[]){&_td_OOC_SSA_Blocker__Region}, NULL, NULL, &_mid, NULL, 4, 1, 0, RT0__strOpenArray };
RT0__StructDesc _td_OOC_SSA_Blocker__5556 = { (RT0__Struct[]){&_td_OOC_SSA_Blocker__5567}, NULL, NULL, &_mid, NULL, 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_Blocker__Preceeds = { (RT0__Struct[]){&_td_OOC_SSA_Blocker__PreceedsDesc}, NULL, NULL, &_mid, "Preceeds", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_Blocker__PreceedsDesc = { (RT0__Struct[]){&_td_OOC_SSA_Blocker__PreceedsDesc}, (void*[]){}, NULL, &_mid, "PreceedsDesc", 8, 0, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_SSA_Blocker__LoopDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_OOC_SSA__NodeDesc,&_td_OOC_SSA_Blocker__ProxyDesc,&_td_OOC_SSA_Blocker__RegionDesc,&_td_OOC_SSA_Blocker__LoopDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)OOC_SSA_Blocker__RegionDesc_Append,(void*)OOC_SSA_Blocker__RegionDesc_Insert,(void*)OOC_SSA_Blocker__RegionDesc_Remove,(void*)OOC_SSA_Blocker__LoopDesc_AppendLoop}, NULL, &_mid, "LoopDesc", 80, 5, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_SSA_Blocker__DependenceData = { (RT0__Struct[]){&_td_OOC_SSA_Blocker__DependenceDataDesc}, NULL, NULL, &_mid, "DependenceData", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_Blocker__DependenceDataDesc = { (RT0__Struct[]){&_td_OOC_SSA_Blocker__DependenceDataDesc}, (void*[]){(void*)OOC_SSA_Blocker__DependenceDataDesc_SameRegion,(void*)OOC_SSA_Blocker__DependenceDataDesc_Dominates,(void*)OOC_SSA_Blocker__DependenceDataDesc_Conflict,(void*)OOC_SSA_Blocker__DependenceDataDesc_DependsOn,(void*)OOC_SSA_Blocker__DependenceDataDesc_AvailableTo,(void*)OOC_SSA_Blocker__DependenceDataDesc_GetSameInstr,(void*)OOC_SSA_Blocker__DependenceDataDesc_SetRegion}, NULL, &_mid, "DependenceDataDesc", 8, 0, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_SSA_Blocker__15943 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 64, 64, (1<<RT0__flagAtomic), RT0__strArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:SSA:Blocker", (RT0__Struct[]) { &_td_OOC_SSA_Blocker__Proxy, &_td_OOC_SSA_Blocker__Region, &_td_OOC_SSA_Blocker__Select, &_td_OOC_SSA_Blocker__Loop, &_td_OOC_SSA_Blocker__ProxyDesc, &_td_OOC_SSA_Blocker__RegionDesc, &_td_OOC_SSA_Blocker__SelectDesc, &_td_OOC_SSA_Blocker__Preceeds, &_td_OOC_SSA_Blocker__PreceedsDesc, &_td_OOC_SSA_Blocker__LoopDesc, &_td_OOC_SSA_Blocker__DependenceData, &_td_OOC_SSA_Blocker__DependenceDataDesc, NULL }, 0 };

extern void OOC_OOC_SSA_Blocker_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_Object_open(&_mid);
    OOC_Object_BigInt_open(&_mid);
    OOC_ADT_Dictionary_open(&_mid);
    OOC_ADT_Dictionary_IntValue_open(&_mid);
    OOC_IO_open(&_mid);
    OOC_IO_TextRider_open(&_mid);
    OOC_IO_StdChannels_open(&_mid);
    OOC_OOC_SSA_open(&_mid);
    OOC_OOC_SSA_Opcode_open(&_mid);
    OOC_OOC_SSA_Opnd_open(&_mid);
    OOC_OOC_SSA_DeadCodeElimination_open(&_mid);
    OOC_OOC_SSA_Destore_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OOC_SSA_Blocker_init();
  }
  _mid.openCount++;
}
extern void OOC_OOC_SSA_Blocker_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OOC_SSA_Blocker_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_Object_close(&_mid);
    OOC_Object_BigInt_close(&_mid);
    OOC_ADT_Dictionary_close(&_mid);
    OOC_ADT_Dictionary_IntValue_close(&_mid);
    OOC_IO_close(&_mid);
    OOC_IO_TextRider_close(&_mid);
    OOC_IO_StdChannels_close(&_mid);
    OOC_OOC_SSA_close(&_mid);
    OOC_OOC_SSA_Opcode_close(&_mid);
    OOC_OOC_SSA_Opnd_close(&_mid);
    OOC_OOC_SSA_DeadCodeElimination_close(&_mid);
    OOC_OOC_SSA_Destore_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
