#include <SysClock.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_SysClock__DateTime = { (RT0__Struct[]){&_td_SysClock__DateTime}, (void*[]){}, NULL, &_mid, "DateTime", 12, 0, (1<<RT0__flagAtomic), RT0__strRecord };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"SysClock", (RT0__Struct[]) { &_td_SysClock__DateTime, NULL } };

extern void OOC_SysClock_init0() {
  RT0__RegisterModule(&_mid);
  OOC_SysClock_init();
}

/* --- */
