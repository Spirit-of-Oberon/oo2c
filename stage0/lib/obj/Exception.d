#include <Exception.oh>
#define Exception__maxBacktraceSize 21
typeof(Exception__GetThreadState) Exception__GetThreadState;

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_Exception__Exception = { (RT0__Struct[]){&_td_Exception__ExceptionDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"Exception", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Exception__ExceptionDesc = { (RT0__Struct[]){&_td_Exception__ExceptionDesc}, (void*[]){(void*)Exception__ExceptionDesc_INIT,(void*)Exception__ExceptionDesc_GetMessage,(void*)Exception__ExceptionDesc_WriteBacktrace,(void*)Exception__ExceptionDesc_Name}, NULL, &_mid, (OOC_CHAR8*)"ExceptionDesc", 92, 0, 0, RT0__strRecord };
RT0__StructDesc _td_Exception__4465 = { (RT0__Struct[]){&RT0__ptr}, NULL, NULL, &_mid, NULL, 84, 21, 0, RT0__strArray };
RT0__StructDesc _td_Exception__Checked = { (RT0__Struct[]){&_td_Exception__CheckedDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"Checked", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Exception__CheckedDesc = { (RT0__Struct[]){&_td_Exception__ExceptionDesc,&_td_Exception__CheckedDesc}, (void*[]){(void*)Exception__ExceptionDesc_INIT,(void*)Exception__ExceptionDesc_GetMessage,(void*)Exception__ExceptionDesc_WriteBacktrace,(void*)Exception__ExceptionDesc_Name}, NULL, &_mid, (OOC_CHAR8*)"CheckedDesc", 92, 1, 0, RT0__strRecord };
RT0__StructDesc _td_Exception__Unchecked = { (RT0__Struct[]){&_td_Exception__UncheckedDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"Unchecked", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Exception__UncheckedDesc = { (RT0__Struct[]){&_td_Exception__ExceptionDesc,&_td_Exception__UncheckedDesc}, (void*[]){(void*)Exception__ExceptionDesc_INIT,(void*)Exception__ExceptionDesc_GetMessage,(void*)Exception__ExceptionDesc_WriteBacktrace,(void*)Exception__ExceptionDesc_Name}, NULL, &_mid, (OOC_CHAR8*)"UncheckedDesc", 92, 1, 0, RT0__strRecord };
RT0__StructDesc _td_Exception__ContextPtr = { (RT0__Struct[]){NULL}, NULL, NULL, &_mid, (OOC_CHAR8*)"ContextPtr", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Exception__ParseError = { (RT0__Struct[]){&_td_Exception__ParseErrorDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"ParseError", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Exception__ParseErrorDesc = { (RT0__Struct[]){&_td_Exception__ExceptionDesc,&_td_Exception__ParseErrorDesc}, (void*[]){(void*)Exception__ParseErrorDesc_INIT,(void*)Exception__ExceptionDesc_GetMessage,(void*)Exception__ExceptionDesc_WriteBacktrace,(void*)Exception__ExceptionDesc_Name}, NULL, &_mid, (OOC_CHAR8*)"ParseErrorDesc", 96, 1, 0, RT0__strRecord };
RT0__StructDesc _td_Exception__ThreadStatePtr = { (RT0__Struct[]){NULL}, NULL, NULL, &_mid, (OOC_CHAR8*)"ThreadStatePtr", 4, -1, 0, RT0__strPointer };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"Exception", (RT0__Struct[]) { &_td_Exception__Exception, &_td_Exception__ExceptionDesc, &_td_Exception__Checked, &_td_Exception__CheckedDesc, &_td_Exception__Unchecked, &_td_Exception__UncheckedDesc, &_td_Exception__ContextPtr, &_td_Exception__ParseError, &_td_Exception__ParseErrorDesc, &_td_Exception__ThreadStatePtr, NULL }, 0 };

extern void OOC_Exception_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_Exception_init();
  }
  _mid.openCount++;
}
extern void OOC_Exception_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_Exception_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
  }
}

/* --- */
