#include <Ascii.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"Ascii", (RT0__Struct[]) { NULL }, 0 };

extern void OOC_Ascii_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_Ascii_init();
  }
  _mid.openCount++;
}
extern void OOC_Ascii_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_Ascii_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
