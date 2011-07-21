static void* _c0;
static void* _c1;
static void* _c2;
static void* _c3;
#include <OS/Path.oh>
#include <ADT/StringBuffer.oh>
#define OS_Path__sep (OOC_CHAR8)'/'

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OS_Path__3472 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OS:Path", (RT0__Struct[]) { NULL }, 0 };

extern void OOC_OS_Path_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_Object_open(&_mid);
    OOC_ADT_StringBuffer_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OS_Path_init();
  }
  _mid.openCount++;
}
extern void OOC_OS_Path_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OS_Path_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_Object_close(&_mid);
    OOC_ADT_StringBuffer_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
