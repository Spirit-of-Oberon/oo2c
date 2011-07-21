#include <OOC/Scanner/Symbol.oh>
#define OOC_Scanner_Symbol__addOnSymbols 81
typeof(OOC_Scanner_Symbol__name) OOC_Scanner_Symbol__name;
typeof(OOC_Scanner_Symbol__representation) OOC_Scanner_Symbol__representation;
static OOC_INT16 OOC_Scanner_Symbol__i;

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_Scanner_Symbol__2526 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 13, 13, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_Scanner_Symbol__2508 = { (RT0__Struct[]){&_td_OOC_Scanner_Symbol__2526}, NULL, NULL, &_mid, NULL, 1053, 81, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_Scanner_Symbol__2634 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 10, 10, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_Scanner_Symbol__2616 = { (RT0__Struct[]){&_td_OOC_Scanner_Symbol__2634}, NULL, NULL, &_mid, NULL, 810, 81, (1<<RT0__flagAtomic), RT0__strArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:Scanner:Symbol", (RT0__Struct[]) { NULL }, 0 };

extern void OOC_OOC_Scanner_Symbol_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OOC_Scanner_Symbol_init();
  }
  _mid.openCount++;
}
extern void OOC_OOC_Scanner_Symbol_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OOC_Scanner_Symbol_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
