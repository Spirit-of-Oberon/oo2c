#include <CharClass.oh>
#include <Ascii.oh>
OOC_CHAR8 CharClass__systemEol[3];

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_CharClass__1077 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 3, 3, (1<<RT0__flagAtomic), RT0__strArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"CharClass", (RT0__Struct[]) { NULL } };

extern void OOC_CharClass_init0() {
  RT0__RegisterModule(&_mid);
  OOC_CharClass_init();
}

/* --- */
