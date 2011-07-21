static void* _c0;
#include <OOC/SSA/Stats.oh>
#include <Out.oh>
#include <Strings.oh>
#include <Object.oh>
#include <ADT/ArrayList.oh>
#include <ADT/Dictionary.oh>
#include <OOC/SSA/Opcode.oh>
#define OOC_SSA_Stats__maxOpcode 88
#define OOC_SSA_Stats__subclassCount 12
#define OOC_SSA_Stats__variantCount 1068
typedef struct OOC_SSA_Stats__StatsDesc *OOC_SSA_Stats__Stats;
typedef struct OOC_SSA_Stats__StatsDesc {
  OOC_INT32 count[1068];
} OOC_SSA_Stats__StatsDesc;
static ADT_Dictionary__Dictionary OOC_SSA_Stats__stage;
static ADT_ArrayList__ArrayList OOC_SSA_Stats__labels;
static OOC_SSA_Stats__Stats OOC_SSA_Stats__NewStats(void);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_SSA_Stats__Stats = { (RT0__Struct[]){&_td_OOC_SSA_Stats__StatsDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"Stats", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_Stats__StatsDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_OOC_SSA_Stats__StatsDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode}, NULL, &_mid, (OOC_CHAR8*)"StatsDesc", 4272, 2, (1<<RT0__flagAtomic), RT0__strRecord };
RT0__StructDesc _td_OOC_SSA_Stats__329 = { (RT0__Struct[]){&RT0__longint}, NULL, NULL, &_mid, NULL, 4272, 1068, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_SSA_Stats__1297 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 64, 64, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_SSA_Stats__1338 = { (RT0__Struct[]){&_td_OOC_SSA_Stats__Stats}, NULL, NULL, &_mid, NULL, 4, 1, 0, RT0__strOpenArray };
RT0__StructDesc _td_OOC_SSA_Stats__1327 = { (RT0__Struct[]){&_td_OOC_SSA_Stats__1338}, NULL, NULL, &_mid, NULL, 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_Stats__1376 = { (RT0__Struct[]){&RT0__longint}, NULL, NULL, &_mid, NULL, 4, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_SSA_Stats__1365 = { (RT0__Struct[]){&_td_OOC_SSA_Stats__1376}, NULL, NULL, &_mid, NULL, 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_Stats__1401 = { (RT0__Struct[]){&RT0__longint}, NULL, NULL, &_mid, NULL, 4272, 1068, (1<<RT0__flagAtomic), RT0__strArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:SSA:Stats", (RT0__Struct[]) { &_td_OOC_SSA_Stats__Stats, &_td_OOC_SSA_Stats__StatsDesc, NULL }, 0 };

extern void OOC_OOC_SSA_Stats_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_Out_open(&_mid);
    OOC_Strings_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_ADT_ArrayList_open(&_mid);
    OOC_ADT_Dictionary_open(&_mid);
    OOC_OOC_SSA_open(&_mid);
    OOC_OOC_SSA_Opcode_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OOC_SSA_Stats_init();
  }
  _mid.openCount++;
}
extern void OOC_OOC_SSA_Stats_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OOC_SSA_Stats_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_Out_close(&_mid);
    OOC_Strings_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_ADT_ArrayList_close(&_mid);
    OOC_ADT_Dictionary_close(&_mid);
    OOC_OOC_SSA_close(&_mid);
    OOC_OOC_SSA_Opcode_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
