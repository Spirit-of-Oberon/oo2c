#include <OOC/Scanner/InputBuffer.oh>
#define OOC_Scanner_InputBuffer__bytesPerRead 4096

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_Scanner_InputBuffer__1296 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_Scanner_InputBuffer__CharArray = { (RT0__Struct[]){&_td_OOC_Scanner_InputBuffer__1296}, NULL, NULL, &_mid, "CharArray", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Scanner_InputBuffer__Buffer = { (RT0__Struct[]){&_td_OOC_Scanner_InputBuffer__BufferDesc}, NULL, NULL, &_mid, "Buffer", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Scanner_InputBuffer__BufferDesc = { (RT0__Struct[]){&_td_OOC_Scanner_InputBuffer__BufferDesc}, (void*[]){(void*)OOC_Scanner_InputBuffer__BufferDesc_NextBlock,(void*)OOC_Scanner_InputBuffer__BufferDesc_EndOfBuffer,(void*)OOC_Scanner_InputBuffer__BufferDesc_Close}, NULL, &_mid, "BufferDesc", 24, 0, 0, RT0__strRecord };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:Scanner:InputBuffer", (RT0__Struct[]) { &_td_OOC_Scanner_InputBuffer__CharArray, &_td_OOC_Scanner_InputBuffer__Buffer, &_td_OOC_Scanner_InputBuffer__BufferDesc, NULL } };

extern void OOC_OOC_Scanner_InputBuffer_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_Scanner_InputBuffer_init();
}

/* --- */
