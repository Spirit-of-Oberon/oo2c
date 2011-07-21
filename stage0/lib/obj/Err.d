#include <Err.oh>
TextRider__Writer Err__writer;

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_Err__2209 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"Err", (RT0__Struct[]) { NULL } };

extern void OOC_Err_init0() {
  RT0__RegisterModule(&_mid);
  OOC_Err_init();
}

/* --- */
