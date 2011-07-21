#include <OOC/SSA/Allocator.oh>
#include <Log.oh>
#include <IntStr.oh>
#include <Strings.oh>
#include <Object.oh>
#include <ADT/ArrayList.oh>
#include <OOC/SSA/Opnd.oh>
#include <OOC/SSA/Result.oh>
#include <OOC/SSA/IGraph.oh>
#include <OOC/SymbolTable/Predef.oh>
typedef OOC_SSA_Schedule__Block *OOC_SSA_Allocator__BlockList;
typedef Object__String *OOC_SSA_Allocator__NameArray;
typedef struct OOC_SSA_Allocator__RegisterFileDesc *OOC_SSA_Allocator__RegisterFile;
typedef OOC_SSA_Allocator__RegisterFile *OOC_SSA_Allocator__RegisterFiles;
typedef struct OOC_SSA_Allocator__RegisterFileDesc {
  OOC_INT8 registerType;
  OOC_CHAR8 __pad1;
  OOC_CHAR8 __pad2;
  OOC_CHAR8 __pad3;
  ADT_ArrayList__ArrayList resultList;
  ADT_ArrayList__ArrayList blockList;
  OOC_SSA_IGraph__Graph iGraph;
  OOC_INT32 maxColor;
  OOC_SSA_Allocator__NameArray names;
} OOC_SSA_Allocator__RegisterFileDesc;
typedef struct OOC_SSA_Allocator__LiveDataDesc *OOC_SSA_Allocator__LiveData;
typedef struct OOC_SSA_Allocator__LiveDataDesc {
  OOC_INT32 outgoingJumps;
  OOC_INT32 knownJumps;
  OOC_SSA_IGraph__Vector live;
} OOC_SSA_Allocator__LiveDataDesc;
OOC_SSA__Result OOC_SSA_Allocator__markInPlace;
static OOC_SSA_Allocator__RegisterFile OOC_SSA_Allocator__NewRegisterFile(OOC_INT8 registerType);
static OOC_SSA_Allocator__LiveData OOC_SSA_Allocator__NewLiveData(OOC_SSA_IGraph__Graph g, OOC_INT32 outgoingJumps);
static OOC_SSA_Allocator__BlockList OOC_SSA_Allocator__GetBlockList(OOC_SSA_Schedule__Block enterBlock, OOC_SSA_Schedule__Block exitBlock);
static OOC_SSA_Allocator__RegisterFiles OOC_SSA_Allocator__GetRegisterFiles(void);
static OOC_SSA_Allocator__RegisterFiles OOC_SSA_Allocator__IdentifyResults(OOC_SSA_Allocator__BlockList blockList, ADT_Dictionary__Dictionary inPlaceEval);
static void OOC_SSA_Allocator__AddToCollect(OOC_SSA_Schedule__Block loopHead, OOC_SSA__Result res);
static OOC_SSA_Schedule__Block OOC_SSA_Allocator__SweepLiveSet(OOC_SSA_Allocator__RegisterFile rf, OOC_SSA_Schedule__Block b, OOC_SSA_IGraph__Vector live);
static void OOC_SSA_Allocator__AssignRegisterFile(OOC_SSA_Allocator__RegisterFile rf, OOC_SSA_Schedule__Block enterBlock, OOC_SSA_Schedule__Block exitBlock, ADT_Dictionary__Dictionary registerMap);
static void OOC_SSA_Allocator__CollectCrossLoopResults(OOC_SSA_Allocator__RegisterFile rf, OOC_SSA_Schedule__Block b, OOC_SSA_Schedule__Block closestLoop);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_SSA_Allocator__1233 = { (RT0__Struct[]){&_td_OOC_SSA_Schedule__Block}, NULL, NULL, &_mid, NULL, 4, 1, 0, RT0__strOpenArray };
RT0__StructDesc _td_OOC_SSA_Allocator__BlockList = { (RT0__Struct[]){&_td_OOC_SSA_Allocator__1233}, NULL, NULL, &_mid, (OOC_CHAR8*)"BlockList", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_Allocator__1283 = { (RT0__Struct[]){&_td_Object__String}, NULL, NULL, &_mid, NULL, 4, 1, 0, RT0__strOpenArray };
RT0__StructDesc _td_OOC_SSA_Allocator__NameArray = { (RT0__Struct[]){&_td_OOC_SSA_Allocator__1283}, NULL, NULL, &_mid, (OOC_CHAR8*)"NameArray", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_Allocator__RegisterFile = { (RT0__Struct[]){&_td_OOC_SSA_Allocator__RegisterFileDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"RegisterFile", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_Allocator__1383 = { (RT0__Struct[]){&_td_OOC_SSA_Allocator__RegisterFile}, NULL, NULL, &_mid, NULL, 4, 1, 0, RT0__strOpenArray };
RT0__StructDesc _td_OOC_SSA_Allocator__RegisterFiles = { (RT0__Struct[]){&_td_OOC_SSA_Allocator__1383}, NULL, NULL, &_mid, (OOC_CHAR8*)"RegisterFiles", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_Allocator__RegisterFileDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_OOC_SSA__NodeDesc,&_td_OOC_SSA_Allocator__RegisterFileDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode}, NULL, &_mid, (OOC_CHAR8*)"RegisterFileDesc", 24, 3, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_SSA_Allocator__LiveData = { (RT0__Struct[]){&_td_OOC_SSA_Allocator__LiveDataDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"LiveData", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_Allocator__LiveDataDesc = { (RT0__Struct[]){&_td_OOC_SSA_Schedule__InfoDesc,&_td_OOC_SSA_Allocator__LiveDataDesc}, (void*[]){}, NULL, &_mid, (OOC_CHAR8*)"LiveDataDesc", 12, 1, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_SSA_Allocator__BlockInfo = { (RT0__Struct[]){&_td_OOC_SSA_Allocator__BlockInfoDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"BlockInfo", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_Allocator__BlockInfoDesc = { (RT0__Struct[]){&_td_OOC_SSA_Schedule__InfoDesc,&_td_OOC_SSA_Allocator__BlockInfoDesc}, (void*[]){}, NULL, &_mid, (OOC_CHAR8*)"BlockInfoDesc", 28, 1, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_SSA_Allocator__3161 = { (RT0__Struct[]){&_td_OOC_SSA__Instr}, NULL, NULL, &_mid, NULL, 4, 1, 0, RT0__strOpenArray };
RT0__StructDesc _td_OOC_SSA_Allocator__3150 = { (RT0__Struct[]){&_td_OOC_SSA_Allocator__3161}, NULL, NULL, &_mid, NULL, 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_Allocator__3205 = { (RT0__Struct[]){&_td_ADT_Dictionary__Dictionary}, NULL, NULL, &_mid, NULL, 4, 1, 0, RT0__strOpenArray };
RT0__StructDesc _td_OOC_SSA_Allocator__3194 = { (RT0__Struct[]){&_td_OOC_SSA_Allocator__3205}, NULL, NULL, &_mid, NULL, 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_Allocator__17736 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 16, 16, (1<<RT0__flagAtomic), RT0__strArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:SSA:Allocator", (RT0__Struct[]) { &_td_OOC_SSA_Allocator__BlockList, &_td_OOC_SSA_Allocator__NameArray, &_td_OOC_SSA_Allocator__RegisterFile, &_td_OOC_SSA_Allocator__RegisterFiles, &_td_OOC_SSA_Allocator__RegisterFileDesc, &_td_OOC_SSA_Allocator__LiveData, &_td_OOC_SSA_Allocator__LiveDataDesc, &_td_OOC_SSA_Allocator__BlockInfo, &_td_OOC_SSA_Allocator__BlockInfoDesc, NULL }, 0 };

extern void OOC_OOC_SSA_Allocator_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_Log_open(&_mid);
    OOC_IntStr_open(&_mid);
    OOC_Strings_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_ADT_ArrayList_open(&_mid);
    OOC_ADT_Dictionary_open(&_mid);
    OOC_OOC_SSA_open(&_mid);
    OOC_OOC_SSA_Opcode_open(&_mid);
    OOC_OOC_SSA_Opnd_open(&_mid);
    OOC_OOC_SSA_Result_open(&_mid);
    OOC_OOC_SSA_Schedule_open(&_mid);
    OOC_OOC_SSA_IGraph_open(&_mid);
    OOC_OOC_C_DeclWriter_open(&_mid);
    OOC_OOC_SymbolTable_Predef_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OOC_SSA_Allocator_init();
  }
  _mid.openCount++;
}
extern void OOC_OOC_SSA_Allocator_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OOC_SSA_Allocator_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_Log_close(&_mid);
    OOC_IntStr_close(&_mid);
    OOC_Strings_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_ADT_ArrayList_close(&_mid);
    OOC_ADT_Dictionary_close(&_mid);
    OOC_OOC_SSA_close(&_mid);
    OOC_OOC_SSA_Opcode_close(&_mid);
    OOC_OOC_SSA_Opnd_close(&_mid);
    OOC_OOC_SSA_Result_close(&_mid);
    OOC_OOC_SSA_Schedule_close(&_mid);
    OOC_OOC_SSA_IGraph_close(&_mid);
    OOC_OOC_C_DeclWriter_close(&_mid);
    OOC_OOC_SymbolTable_Predef_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
