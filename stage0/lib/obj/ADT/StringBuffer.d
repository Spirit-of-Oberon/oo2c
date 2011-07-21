static void* _c0;
static void* _c1;
#include <ADT/StringBuffer.oh>
#include <IntStr.oh>
#include <RealStr.oh>
static OOC_INT32 ADT_StringBuffer__Length(const OOC_CHAR8 data[], OOC_LEN data_0d);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_ADT_StringBuffer__1012 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_ADT_StringBuffer__CharsLatin1 = { (RT0__Struct[]){&_td_ADT_StringBuffer__1012}, NULL, NULL, &_mid, "CharsLatin1", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_ADT_StringBuffer__1065 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 2, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_ADT_StringBuffer__CharsUTF16 = { (RT0__Struct[]){&_td_ADT_StringBuffer__1065}, NULL, NULL, &_mid, "CharsUTF16", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_ADT_StringBuffer__StringBuffer = { (RT0__Struct[]){&_td_ADT_StringBuffer__StringBufferDesc}, NULL, NULL, &_mid, "StringBuffer", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_ADT_StringBuffer__StringBufferDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_ADT_StringBuffer__StringBufferDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)ADT_StringBuffer__StringBufferDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)ADT_StringBuffer__StringBufferDesc_INIT,(void*)ADT_StringBuffer__StringBufferDesc_CharAt,(void*)ADT_StringBuffer__StringBufferDesc_Clear,(void*)ADT_StringBuffer__StringBufferDesc_EnsureCapacity,(void*)ADT_StringBuffer__StringBufferDesc_CharsLatin1,(void*)ADT_StringBuffer__StringBufferDesc_ConvertTo16,(void*)ADT_StringBuffer__StringBufferDesc_CharsUTF16,(void*)ADT_StringBuffer__StringBufferDesc_AppendLatin1Region,(void*)ADT_StringBuffer__StringBufferDesc_AppendLatin1,(void*)ADT_StringBuffer__StringBufferDesc_AppendLatin1Char,(void*)ADT_StringBuffer__StringBufferDesc_AppendLn,(void*)ADT_StringBuffer__StringBufferDesc_AppendUTF16Region,(void*)ADT_StringBuffer__StringBufferDesc_AppendChar,(void*)ADT_StringBuffer__StringBufferDesc_Append,(void*)ADT_StringBuffer__StringBufferDesc_AppendInt,(void*)ADT_StringBuffer__StringBufferDesc_AppendReal,(void*)ADT_StringBuffer__StringBufferDesc_AppendSet,(void*)ADT_StringBuffer__StringBufferDesc_AppendBool,(void*)ADT_StringBuffer__StringBufferDesc_Insert,(void*)ADT_StringBuffer__StringBufferDesc_Delete}, NULL, &_mid, "StringBufferDesc", 16, 2, 0, RT0__strRecord };
RT0__StructDesc _td_ADT_StringBuffer__5722 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_ADT_StringBuffer__6351 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_ADT_StringBuffer__6555 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_ADT_StringBuffer__7130 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 2, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_ADT_StringBuffer__8918 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_ADT_StringBuffer__9124 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_ADT_StringBuffer__9518 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 32, 32, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_ADT_StringBuffer__9768 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 32, 32, (1<<RT0__flagAtomic), RT0__strArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"ADT:StringBuffer", (RT0__Struct[]) { &_td_ADT_StringBuffer__CharsLatin1, &_td_ADT_StringBuffer__CharsUTF16, &_td_ADT_StringBuffer__StringBuffer, &_td_ADT_StringBuffer__StringBufferDesc, NULL } };

extern void OOC_ADT_StringBuffer_init0() {
  RT0__RegisterModule(&_mid);
  OOC_ADT_StringBuffer_init();
}

/* --- */
