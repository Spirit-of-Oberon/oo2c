#include <OOC/SSA/IGraph.oh>
#define OOC_SSA_IGraph__bitsPerSet 32
#define OOC_SSA_IGraph__emptySet 0
static void OOC_SSA_IGraph__InitGraph(OOC_SSA_IGraph__Graph g, OOC_INT32 size);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_SSA_IGraph__976 = { (RT0__Struct[]){&RT0__set32}, NULL, NULL, &_mid, NULL, 4, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_SSA_IGraph__967 = { (RT0__Struct[]){&RT0__set32}, NULL, NULL, &_mid, NULL, 4, 2, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_SSA_IGraph__BitMatrix = { (RT0__Struct[]){&_td_OOC_SSA_IGraph__967}, NULL, NULL, &_mid, "BitMatrix", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_IGraph__1088 = { (RT0__Struct[]){&RT0__longint}, NULL, NULL, &_mid, NULL, 4, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_SSA_IGraph__ColorArray = { (RT0__Struct[]){&_td_OOC_SSA_IGraph__1088}, NULL, NULL, &_mid, "ColorArray", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_IGraph__1127 = { (RT0__Struct[]){&RT0__set32}, NULL, NULL, &_mid, NULL, 4, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_SSA_IGraph__Vector = { (RT0__Struct[]){&_td_OOC_SSA_IGraph__1127}, NULL, NULL, &_mid, "Vector", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_IGraph__Graph = { (RT0__Struct[]){&_td_OOC_SSA_IGraph__GraphDesc}, NULL, NULL, &_mid, "Graph", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_IGraph__GraphDesc = { (RT0__Struct[]){&_td_OOC_SSA_IGraph__GraphDesc}, (void*[]){(void*)OOC_SSA_IGraph__GraphDesc_Clear,(void*)OOC_SSA_IGraph__GraphDesc_NewVector,(void*)OOC_SSA_IGraph__GraphDesc_CopyVector,(void*)OOC_SSA_IGraph__GraphDesc_Interfere,(void*)OOC_SSA_IGraph__GraphDesc_MergeRowColumn,(void*)OOC_SSA_IGraph__GraphDesc_AddToLive,(void*)OOC_SSA_IGraph__GraphDesc_RemoveFromLive,(void*)OOC_SSA_IGraph__GraphDesc_In,(void*)OOC_SSA_IGraph__GraphDesc_Conflicts,(void*)OOC_SSA_IGraph__GraphDesc_MergeVector,(void*)OOC_SSA_IGraph__GraphDesc_SymmetricMatrix,(void*)OOC_SSA_IGraph__GraphDesc_ColorGraphTrivial,(void*)OOC_SSA_IGraph__GraphDesc_ColorGraphSimple}, NULL, &_mid, "GraphDesc", 8, 0, 0, RT0__strRecord };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:SSA:IGraph", (RT0__Struct[]) { &_td_OOC_SSA_IGraph__BitMatrix, &_td_OOC_SSA_IGraph__ColorArray, &_td_OOC_SSA_IGraph__Vector, &_td_OOC_SSA_IGraph__Graph, &_td_OOC_SSA_IGraph__GraphDesc, NULL } };

extern void OOC_OOC_SSA_IGraph_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_SSA_IGraph_init();
}

/* --- */
