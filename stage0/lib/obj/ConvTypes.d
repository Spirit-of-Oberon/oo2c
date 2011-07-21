#include <ConvTypes.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_ConvTypes__ScanState = { (RT0__Struct[]){&_td_ConvTypes__ScanDesc}, NULL, NULL, &_mid, "ScanState", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_ConvTypes__ScanDesc = { (RT0__Struct[]){&_td_ConvTypes__ScanDesc}, (void*[]){}, NULL, &_mid, "ScanDesc", 4, 0, (1<<RT0__flagAtomic), RT0__strRecord };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"ConvTypes", (RT0__Struct[]) { &_td_ConvTypes__ScanState, &_td_ConvTypes__ScanDesc, NULL } };

extern void OOC_ConvTypes_init0() {
  RT0__RegisterModule(&_mid);
  OOC_ConvTypes_init();
}

/* --- */
