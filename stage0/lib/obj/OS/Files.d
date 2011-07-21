#include <OS/Files.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OS_Files__1348 = { (RT0__Struct[]){&_td_Object__String}, NULL, NULL, &_mid, NULL, 4, 1, 0, RT0__strOpenArray };
RT0__StructDesc _td_OS_Files__NameArray = { (RT0__Struct[]){&_td_OS_Files__1348}, NULL, NULL, &_mid, "NameArray", 4, -1, 0, RT0__strPointer };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OS:Files", (RT0__Struct[]) { &_td_OS_Files__NameArray, NULL } };

extern void OOC_OS_Files_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OS_Files_init();
}

/* --- */
