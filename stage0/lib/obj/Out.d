#include <Out.oh>
TextRider__Writer Out__writer;

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_Out__2255 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"Out", (RT0__Struct[]) { NULL }, 0 };

extern void OOC_Out_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_StdChannels_open(&_mid);
    OOC_TextRider_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_Out_init();
  }
  _mid.openCount++;
}
extern void OOC_Out_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_Out_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_StdChannels_close(&_mid);
    OOC_TextRider_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
