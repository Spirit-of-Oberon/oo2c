static void* _c0;
static void* _c1;
static void* _c2;
static void* _c3;
static void* _c4;
static void* _c5;
static void* _c6;
static void* _c7;
static void* _c8;
#include <IO/BinaryRider.oh>
#include <Strings.oh>
static OOC_INT8 IO_BinaryRider__systemByteOrder;
static void IO_BinaryRider__SetDefaultByteOrder(OOC_CHAR8 x[], OOC_LEN x_0d);
static void IO_BinaryRider__Init(void);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_IO_BinaryRider__Reader = { (RT0__Struct[]){&_td_IO_BinaryRider__ReaderDesc}, NULL, NULL, &_mid, "Reader", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_IO_BinaryRider__ReaderDesc = { (RT0__Struct[]){&_td_IO_BinaryRider__ReaderDesc}, (void*[]){(void*)IO_BinaryRider__ReaderDesc_SetPos,(void*)IO_BinaryRider__ReaderDesc_ReadBytes,(void*)IO_BinaryRider__ReaderDesc_ReadBytesOrdered,(void*)IO_BinaryRider__ReaderDesc_ReadBool,(void*)IO_BinaryRider__ReaderDesc_ReadChar,(void*)IO_BinaryRider__ReaderDesc_ReadLChar,(void*)IO_BinaryRider__ReaderDesc_ReadString,(void*)IO_BinaryRider__ReaderDesc_ReadLString,(void*)IO_BinaryRider__ReaderDesc_ReadSInt,(void*)IO_BinaryRider__ReaderDesc_ReadInt,(void*)IO_BinaryRider__ReaderDesc_ReadLInt,(void*)IO_BinaryRider__ReaderDesc_ReadNum,(void*)IO_BinaryRider__ReaderDesc_ReadReal,(void*)IO_BinaryRider__ReaderDesc_ReadLReal,(void*)IO_BinaryRider__ReaderDesc_ReadSet,(void*)IO_BinaryRider__ReaderDesc_ReadStr,(void*)IO_BinaryRider__ReaderDesc_SetByteOrder}, NULL, &_mid, "ReaderDesc", 8, 0, 0, RT0__strRecord };
RT0__StructDesc _td_IO_BinaryRider__Writer = { (RT0__Struct[]){&_td_IO_BinaryRider__WriterDesc}, NULL, NULL, &_mid, "Writer", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_IO_BinaryRider__WriterDesc = { (RT0__Struct[]){&_td_IO_BinaryRider__WriterDesc}, (void*[]){(void*)IO_BinaryRider__WriterDesc_SetPos,(void*)IO_BinaryRider__WriterDesc_WriteBytes,(void*)IO_BinaryRider__WriterDesc_WriteOrdered,(void*)IO_BinaryRider__WriterDesc_WriteChar,(void*)IO_BinaryRider__WriterDesc_WriteBool,(void*)IO_BinaryRider__WriterDesc_WriteLChar,(void*)IO_BinaryRider__WriterDesc_WriteString,(void*)IO_BinaryRider__WriterDesc_WriteLString,(void*)IO_BinaryRider__WriterDesc_WriteSInt,(void*)IO_BinaryRider__WriterDesc_WriteInt,(void*)IO_BinaryRider__WriterDesc_WriteLInt,(void*)IO_BinaryRider__WriterDesc_WriteNum,(void*)IO_BinaryRider__WriterDesc_WriteReal,(void*)IO_BinaryRider__WriterDesc_WriteLReal,(void*)IO_BinaryRider__WriterDesc_WriteSet,(void*)IO_BinaryRider__WriterDesc_WriteStr,(void*)IO_BinaryRider__WriterDesc_SetByteOrder}, NULL, &_mid, "WriterDesc", 8, 0, 0, RT0__strRecord };
RT0__StructDesc _td_IO_BinaryRider__2186 = { (RT0__Struct[]){&RT0__byte}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_IO_BinaryRider__2514 = { (RT0__Struct[]){&RT0__byte}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_IO_BinaryRider__3744 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_IO_BinaryRider__4276 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 2, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_IO_BinaryRider__6356 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1024, 1024, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_IO_BinaryRider__6410 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_IO_BinaryRider__6399 = { (RT0__Struct[]){&_td_IO_BinaryRider__6410}, NULL, NULL, &_mid, NULL, 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_IO_BinaryRider__6439 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 1024, 512, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_IO_BinaryRider__6499 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 2, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_IO_BinaryRider__6488 = { (RT0__Struct[]){&_td_IO_BinaryRider__6499}, NULL, NULL, &_mid, NULL, 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_IO_BinaryRider__8111 = { (RT0__Struct[]){&RT0__byte}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_IO_BinaryRider__8402 = { (RT0__Struct[]){&RT0__byte}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_IO_BinaryRider__9257 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_IO_BinaryRider__9498 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 2, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_IO_BinaryRider__13156 = { (RT0__Struct[]){&RT0__byte}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"IO:BinaryRider", (RT0__Struct[]) { &_td_IO_BinaryRider__Reader, &_td_IO_BinaryRider__ReaderDesc, &_td_IO_BinaryRider__Writer, &_td_IO_BinaryRider__WriterDesc, NULL } };

extern void OOC_IO_BinaryRider_init0() {
  RT0__RegisterModule(&_mid);
  OOC_IO_BinaryRider_init();
}

/* --- */
