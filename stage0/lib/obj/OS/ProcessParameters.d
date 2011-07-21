#include <OS/ProcessParameters.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OS:ProcessParameters", (RT0__Struct[]) { NULL } };

extern void OOC_OS_ProcessParameters_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OS_ProcessParameters_init();
}

/* --- */
