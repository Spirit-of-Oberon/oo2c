#include <CharClass.oh>
#include <Ascii.oh>
OOC_CHAR8 CharClass__systemEol[3];

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_CharClass__1077 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 3, 3, (1<<RT0__flagAtomic), RT0__strArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"CharClass", (RT0__Struct[]) { NULL }, 0 };

extern void OOC_CharClass_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_Ascii_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_CharClass_init();
  }
  _mid.openCount++;
}
extern void OOC_CharClass_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_CharClass_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_Ascii_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
