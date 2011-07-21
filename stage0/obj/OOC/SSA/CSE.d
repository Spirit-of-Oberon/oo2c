#include <OOC/SSA/CSE.oh>
#include <OOC/SSA/Blocker.oh>
#include <OOC/SSA/Opcode.oh>
static void OOC_SSA_CSE__InitPartition(OOC_SSA_CSE__Partition p);
static OOC_SSA_CSE__Partition OOC_SSA_CSE__NewPartition(void);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_SSA_CSE__997 = { (RT0__Struct[]){&_td_OOC_SSA__Result}, NULL, NULL, &_mid, NULL, 4, 1, 0, RT0__strOpenArray };
RT0__StructDesc _td_OOC_SSA_CSE__ResultList = { (RT0__Struct[]){&_td_OOC_SSA_CSE__997}, NULL, NULL, &_mid, "ResultList", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_CSE__Partition = { (RT0__Struct[]){&_td_OOC_SSA_CSE__PartitionDesc}, NULL, NULL, &_mid, "Partition", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_CSE__1086 = { (RT0__Struct[]){&_td_OOC_SSA_CSE__Partition}, NULL, NULL, &_mid, NULL, 4, 1, 0, RT0__strOpenArray };
RT0__StructDesc _td_OOC_SSA_CSE__ChildrenList = { (RT0__Struct[]){&_td_OOC_SSA_CSE__1086}, NULL, NULL, &_mid, "ChildrenList", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_CSE__PartitionDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_OOC_SSA__NodeDesc,&_td_OOC_SSA_CSE__PartitionDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)OOC_SSA_CSE__PartitionDesc_Add}, NULL, &_mid, "PartitionDesc", 40, 3, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_SSA_CSE__4206 = { (RT0__Struct[]){&_td_OOC_SSA_CSE__Partition}, NULL, NULL, &_mid, NULL, 48, 12, 0, RT0__strArray };
RT0__StructDesc _td_OOC_SSA_CSE__4190 = { (RT0__Struct[]){&_td_OOC_SSA_CSE__4206}, NULL, NULL, &_mid, NULL, 4272, 89, 0, RT0__strArray };
RT0__StructDesc _td_OOC_SSA_CSE__6330 = { (RT0__Struct[]){&_td_OOC_SSA__Result}, NULL, NULL, &_mid, NULL, 4, 1, 0, RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:SSA:CSE", (RT0__Struct[]) { &_td_OOC_SSA_CSE__ResultList, &_td_OOC_SSA_CSE__Partition, &_td_OOC_SSA_CSE__ChildrenList, &_td_OOC_SSA_CSE__PartitionDesc, NULL } };

extern void OOC_OOC_SSA_CSE_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_SSA_CSE_init();
}

/* --- */
