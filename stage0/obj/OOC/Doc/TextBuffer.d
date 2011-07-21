#include <OOC/Doc/TextBuffer.oh>
#include <CharClass.oh>
#include <Strings.oh>
#define OOC_Doc_TextBuffer__minTextWidth 32
static void OOC_Doc_TextBuffer__Extend(OOC_Doc_TextBuffer__Buffer b, OOC_INT32 to);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_Doc_TextBuffer__Buffer = { (RT0__Struct[]){&_td_OOC_Doc_TextBuffer__BufferDesc}, NULL, NULL, &_mid, "Buffer", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Doc_TextBuffer__BufferDesc = { (RT0__Struct[]){&_td_OOC_Doc_TextBuffer__BufferDesc}, (void*[]){(void*)OOC_Doc_TextBuffer__BufferDesc_Clear,(void*)OOC_Doc_TextBuffer__BufferDesc_Append,(void*)OOC_Doc_TextBuffer__BufferDesc_AppendEOL,(void*)OOC_Doc_TextBuffer__BufferDesc_AppendSpaces,(void*)OOC_Doc_TextBuffer__BufferDesc_AppendSubstring,(void*)OOC_Doc_TextBuffer__BufferDesc_AppendNoLB,(void*)OOC_Doc_TextBuffer__BufferDesc_Capitalize}, NULL, &_mid, "BufferDesc", 8, 0, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_Doc_TextBuffer__1653 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_Doc_TextBuffer__2464 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_Doc_TextBuffer__2882 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:Doc:TextBuffer", (RT0__Struct[]) { &_td_OOC_Doc_TextBuffer__Buffer, &_td_OOC_Doc_TextBuffer__BufferDesc, NULL }, 0 };

extern void OOC_OOC_Doc_TextBuffer_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_CharClass_open(&_mid);
    OOC_Strings_open(&_mid);
    OOC_OOC_Doc_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OOC_Doc_TextBuffer_init();
  }
  _mid.openCount++;
}
extern void OOC_OOC_Doc_TextBuffer_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OOC_Doc_TextBuffer_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_CharClass_close(&_mid);
    OOC_Strings_close(&_mid);
    OOC_OOC_Doc_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
