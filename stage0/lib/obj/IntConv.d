#include <IntConv.oh>
#include <CharClass.oh>
static ConvTypes__ScanState IntConv__W;
static ConvTypes__ScanState IntConv__S;
static ConvTypes__ScanState IntConv__SI;
static OOC_CHAR8 IntConv__minInt[11];
static OOC_CHAR8 IntConv__maxInt[11];
#define IntConv__maxDigits 10
static void IntConv__WState(OOC_CHAR8 inputCh, OOC_INT8 *chClass, ConvTypes__ScanState *nextState);
static void IntConv__SState(OOC_CHAR8 inputCh, OOC_INT8 *chClass, ConvTypes__ScanState *nextState);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_IntConv__1617 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 11, 11, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_IntConv__5030 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_IntConv__5284 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_IntConv__6744 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"IntConv", (RT0__Struct[]) { NULL }, 0 };

extern void OOC_IntConv_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_CharClass_open(&_mid);
    OOC_ConvTypes_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_IntConv_init();
  }
  _mid.openCount++;
}
extern void OOC_IntConv_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_IntConv_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_CharClass_close(&_mid);
    OOC_ConvTypes_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
