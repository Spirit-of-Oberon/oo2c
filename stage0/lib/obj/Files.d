#include <Files.oh>
static Files__ErrorContext Files__errorContext;

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_Files__File = { (RT0__Struct[]){&_td_Files__FileDesc}, NULL, NULL, &_mid, "File", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Files__FileDesc = { (RT0__Struct[]){&_td_Channel__ChannelDesc,&_td_PosixFileDescr__ChannelDesc,&_td_Files__FileDesc}, (void*[]){(void*)PosixFileDescr__ChannelDesc_Length,(void*)PosixFileDescr__ChannelDesc_GetModTime,(void*)Files__FileDesc_NewReader,(void*)Files__FileDesc_NewWriter,(void*)PosixFileDescr__ChannelDesc_Flush,(void*)Files__FileDesc_Close,(void*)Channel__ChannelDesc_ClearError,(void*)Files__FileDesc_Register}, NULL, &_mid, "FileDesc", 60, 2, 0, RT0__strRecord };
RT0__StructDesc _td_Files__6498 = { (RT0__Struct[]){NULL}, NULL, NULL, &_mid, NULL, 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Files__Reader = { (RT0__Struct[]){&_td_Files__ReaderDesc}, NULL, NULL, &_mid, "Reader", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Files__ReaderDesc = { (RT0__Struct[]){&_td_Channel__ReaderDesc,&_td_PosixFileDescr__ReaderDesc,&_td_Files__ReaderDesc}, (void*[]){(void*)PosixFileDescr__ReaderDesc_Pos,(void*)PosixFileDescr__ReaderDesc_Available,(void*)PosixFileDescr__ReaderDesc_SetPos,(void*)PosixFileDescr__ReaderDesc_ReadByte,(void*)PosixFileDescr__ReaderDesc_ReadBytes,(void*)Channel__ReaderDesc_ClearError}, NULL, &_mid, "ReaderDesc", 20, 2, 0, RT0__strRecord };
RT0__StructDesc _td_Files__Writer = { (RT0__Struct[]){&_td_Files__WriterDesc}, NULL, NULL, &_mid, "Writer", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Files__WriterDesc = { (RT0__Struct[]){&_td_Channel__WriterDesc,&_td_PosixFileDescr__WriterDesc,&_td_Files__WriterDesc}, (void*[]){(void*)PosixFileDescr__WriterDesc_Pos,(void*)PosixFileDescr__WriterDesc_SetPos,(void*)PosixFileDescr__WriterDesc_WriteByte,(void*)PosixFileDescr__WriterDesc_WriteBytes,(void*)Channel__WriterDesc_ClearError,(void*)Files__WriterDesc_Truncate}, NULL, &_mid, "WriterDesc", 20, 2, 0, RT0__strRecord };
RT0__StructDesc _td_Files__ErrorContext = { (RT0__Struct[]){&_td_Files__ErrorContextDesc}, NULL, NULL, &_mid, "ErrorContext", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Files__ErrorContextDesc = { (RT0__Struct[]){&_td_Msg__ContextDesc,&_td_Channel__ErrorContextDesc,&_td_PosixFileDescr__ErrorContextDesc,&_td_Files__ErrorContextDesc}, (void*[]){(void*)Files__ErrorContextDesc_GetTemplate}, NULL, &_mid, "ErrorContextDesc", 4, 3, 0, RT0__strRecord };
RT0__StructDesc _td_Files__10472 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_Files__10886 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_Files__11161 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_Files__12585 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_Files__12958 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_Files__13222 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"Files", (RT0__Struct[]) { &_td_Files__File, &_td_Files__FileDesc, &_td_Files__Reader, &_td_Files__ReaderDesc, &_td_Files__Writer, &_td_Files__WriterDesc, &_td_Files__ErrorContext, &_td_Files__ErrorContextDesc, NULL } };

extern void OOC_Files_init0() {
  RT0__RegisterModule(&_mid);
  OOC_Files_init();
}

/* --- */
