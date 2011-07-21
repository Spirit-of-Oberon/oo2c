#include <HashCode.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_HashCode__1534 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_HashCode__1609 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 2, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_HashCode__1688 = { (RT0__Struct[]){&RT0__ucs4char}, NULL, NULL, &_mid, NULL, 4, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"HashCode", (RT0__Struct[]) { NULL } };

extern void OOC_HashCode_init0() {
  RT0__RegisterModule(&_mid);
  OOC_HashCode_init();
}

/* --- */
