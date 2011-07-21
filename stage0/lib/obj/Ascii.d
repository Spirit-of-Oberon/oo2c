#include <Ascii.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"Ascii", (RT0__Struct[]) { NULL } };

extern void OOC_Ascii_init0() {
  RT0__RegisterModule(&_mid);
  OOC_Ascii_init();
}

/* --- */
