#include <RealStr.oh>
#include <libc.oh>
#include <RealConv.oh>
#include <Real0.oh>
#include <Strings.oh>
#define RealStr__prec 9

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_RealStr__1563 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_RealStr__1888 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_RealStr__2755 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 32, 32, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_RealStr__3050 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_RealStr__3625 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 32, 32, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_RealStr__3916 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_RealStr__4775 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 70, 70, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_RealStr__5081 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_RealStr__5670 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 70, 70, (1<<RT0__flagAtomic), RT0__strArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"RealStr", (RT0__Struct[]) { NULL }, 0 };

extern void OOC_RealStr_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_ConvTypes_open(&_mid);
    OOC_RealConv_open(&_mid);
    OOC_Real0_open(&_mid);
    OOC_Strings_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_RealStr_init();
  }
  _mid.openCount++;
}
extern void OOC_RealStr_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_RealStr_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_ConvTypes_close(&_mid);
    OOC_RealConv_close(&_mid);
    OOC_Real0_close(&_mid);
    OOC_Strings_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
