#include <IntStr.oh>
#include <IntConv.oh>
static void IntStr__Reverse(OOC_CHAR8 str[], OOC_LEN str_0d, OOC_INT16 start, OOC_INT16 end);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_IntStr__1626 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_IntStr__2138 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_IntStr__2435 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_IntStr__2663 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 12, 12, (1<<RT0__flagAtomic), RT0__strArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"IntStr", (RT0__Struct[]) { NULL } };

extern void OOC_IntStr_init0() {
  RT0__RegisterModule(&_mid);
  OOC_IntStr_init();
}

/* --- */
