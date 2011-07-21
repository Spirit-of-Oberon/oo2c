#include <OOC/Scanner/Symbol.oh>
#define OOC_Scanner_Symbol__addOnSymbols 81
OOC_CHAR8 OOC_Scanner_Symbol__name[81][13];
OOC_CHAR8 OOC_Scanner_Symbol__representation[81][10];
static OOC_INT16 OOC_Scanner_Symbol__i;

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_Scanner_Symbol__2526 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 13, 13, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_Scanner_Symbol__2508 = { (RT0__Struct[]){&_td_OOC_Scanner_Symbol__2526}, NULL, NULL, &_mid, NULL, 1053, 81, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_Scanner_Symbol__2634 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 10, 10, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_Scanner_Symbol__2616 = { (RT0__Struct[]){&_td_OOC_Scanner_Symbol__2634}, NULL, NULL, &_mid, NULL, 810, 81, (1<<RT0__flagAtomic), RT0__strArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:Scanner:Symbol", (RT0__Struct[]) { NULL } };

extern void OOC_OOC_Scanner_Symbol_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_Scanner_Symbol_init();
}

/* --- */
