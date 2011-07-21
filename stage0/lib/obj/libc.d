#include <libc.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"libc", (RT0__Struct[]) { NULL } };

extern void OOC_libc_init0() {
  RT0__RegisterModule(&_mid);
  OOC_libc_init();
}

/* --- */
