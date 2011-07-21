#include <SysClock.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_SysClock__DateTime = { (RT0__Struct[]){&_td_SysClock__DateTime}, (void*[]){}, NULL, &_mid, (OOC_CHAR8*)"DateTime", 12, 0, (1<<RT0__flagAtomic), RT0__strRecord };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"SysClock", (RT0__Struct[]) { &_td_SysClock__DateTime, NULL }, 0 };

extern void OOC_SysClock_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_SysClock_init();
  }
  _mid.openCount++;
}
extern void OOC_SysClock_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_SysClock_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
