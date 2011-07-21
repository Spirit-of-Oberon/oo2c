#include <Real0.oh>
#include <CharClass.oh>
#include <Strings.oh>
#define Real0__strAllRight 0
#define Real0__strOutOfRange 1
#define Real0__strWrongFormat 2
#define Real0__strEmpty 3
#define Real0__padding 0
#define Real0__valid 1
#define Real0__invalid 2
#define Real0__terminator 3
ConvTypes__ScanState Real0__RS;
ConvTypes__ScanState Real0__P;
ConvTypes__ScanState Real0__F;
ConvTypes__ScanState Real0__E;
ConvTypes__ScanState Real0__SE;
ConvTypes__ScanState Real0__WE;
ConvTypes__ScanState Real0__SR;
static OOC_CHAR8 Real0__IsSign(OOC_CHAR8 ch);
static void Real0__RSState(OOC_CHAR8 inputCh, OOC_INT8 *chClass, ConvTypes__ScanState *nextState);
static void Real0__PState(OOC_CHAR8 inputCh, OOC_INT8 *chClass, ConvTypes__ScanState *nextState);
static void Real0__FState(OOC_CHAR8 inputCh, OOC_INT8 *chClass, ConvTypes__ScanState *nextState);
static void Real0__EState(OOC_CHAR8 inputCh, OOC_INT8 *chClass, ConvTypes__ScanState *nextState);
static void Real0__SEState(OOC_CHAR8 inputCh, OOC_INT8 *chClass, ConvTypes__ScanState *nextState);
static void Real0__WEState(OOC_CHAR8 inputCh, OOC_INT8 *chClass, ConvTypes__ScanState *nextState);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_Real0__3861 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_Real0__3926 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_Real0__4546 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_Real0__8322 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_Real0__9168 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_Real0__10611 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_Real0__10722 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"Real0", (RT0__Struct[]) { NULL }, 0 };

extern void OOC_Real0_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_CharClass_open(&_mid);
    OOC_ConvTypes_open(&_mid);
    OOC_Strings_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_Real0_init();
  }
  _mid.openCount++;
}
extern void OOC_Real0_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_Real0_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_CharClass_close(&_mid);
    OOC_ConvTypes_close(&_mid);
    OOC_Strings_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
