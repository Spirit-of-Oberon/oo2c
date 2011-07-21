#include <Termination.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"Termination", (RT0__Struct[]) { NULL } };

extern void OOC_Termination_init0() {
  RT0__RegisterModule(&_mid);
  OOC_Termination_init();
}

/* --- */
