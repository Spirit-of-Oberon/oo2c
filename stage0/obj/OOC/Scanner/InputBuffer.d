#include <OOC/Scanner/InputBuffer.oh>
#define OOC_Scanner_InputBuffer__bytesPerRead 4096

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_Scanner_InputBuffer__1296 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_Scanner_InputBuffer__CharArray = { (RT0__Struct[]){&_td_OOC_Scanner_InputBuffer__1296}, NULL, NULL, &_mid, (OOC_CHAR8*)"CharArray", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Scanner_InputBuffer__Buffer = { (RT0__Struct[]){&_td_OOC_Scanner_InputBuffer__BufferDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"Buffer", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Scanner_InputBuffer__BufferDesc = { (RT0__Struct[]){&_td_OOC_Scanner_InputBuffer__BufferDesc}, (void*[]){(void*)OOC_Scanner_InputBuffer__BufferDesc_NextBlock,(void*)OOC_Scanner_InputBuffer__BufferDesc_EndOfBuffer,(void*)OOC_Scanner_InputBuffer__BufferDesc_Close}, NULL, &_mid, (OOC_CHAR8*)"BufferDesc", 24, 0, 0, RT0__strRecord };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:Scanner:InputBuffer", (RT0__Struct[]) { &_td_OOC_Scanner_InputBuffer__CharArray, &_td_OOC_Scanner_InputBuffer__Buffer, &_td_OOC_Scanner_InputBuffer__BufferDesc, NULL }, 0 };

extern void OOC_OOC_Scanner_InputBuffer_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_IO_open(&_mid);
    OOC_OOC_Error_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OOC_Scanner_InputBuffer_init();
  }
  _mid.openCount++;
}
extern void OOC_OOC_Scanner_InputBuffer_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OOC_Scanner_InputBuffer_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_IO_close(&_mid);
    OOC_OOC_Error_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
