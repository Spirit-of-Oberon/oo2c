#include <OOC/SSA/Result.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_SSA_Result__3303 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:SSA:Result", (RT0__Struct[]) { NULL } };

extern void OOC_OOC_SSA_Result_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_SSA_Result_init();
}

/* --- */
