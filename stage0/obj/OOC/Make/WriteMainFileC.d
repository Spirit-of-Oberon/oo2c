#include <OOC/Make/WriteMainFileC.oh>
#include <IO/TextRider.oh>
#include <OOC/Config.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_Make_WriteMainFileC__1061 = { (RT0__Struct[]){&_td_OOC_Repository__Module}, NULL, NULL, &_mid, NULL, 4, 1, 0, RT0__strOpenArray };
RT0__StructDesc _td_OOC_Make_WriteMainFileC__1252 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_Make_WriteMainFileC__1360 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_Make_WriteMainFileC__1395 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1024, 1024, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_Make_WriteMainFileC__1795 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:Make:WriteMainFileC", (RT0__Struct[]) { NULL } };

extern void OOC_OOC_Make_WriteMainFileC_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_Make_WriteMainFileC_init();
}

/* --- */
