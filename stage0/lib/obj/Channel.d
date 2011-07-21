#include <Channel.oh>
#include <Strings.oh>
static Channel__ErrorContext Channel__errorContext;
static Msg__Msg Channel__GetError(OOC_INT32 code);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_Channel__Channel = { (RT0__Struct[]){&_td_Channel__ChannelDesc}, NULL, NULL, &_mid, "Channel", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Channel__ChannelDesc = { (RT0__Struct[]){&_td_Channel__ChannelDesc}, (void*[]){(void*)Channel__ChannelDesc_Length,(void*)Channel__ChannelDesc_GetModTime,(void*)Channel__ChannelDesc_NewReader,(void*)Channel__ChannelDesc_NewWriter,(void*)Channel__ChannelDesc_Flush,(void*)Channel__ChannelDesc_Close,(void*)Channel__ChannelDesc_ClearError}, NULL, &_mid, "ChannelDesc", 8, 0, 0, RT0__strRecord };
RT0__StructDesc _td_Channel__Reader = { (RT0__Struct[]){&_td_Channel__ReaderDesc}, NULL, NULL, &_mid, "Reader", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Channel__ReaderDesc = { (RT0__Struct[]){&_td_Channel__ReaderDesc}, (void*[]){(void*)Channel__ReaderDesc_Pos,(void*)Channel__ReaderDesc_Available,(void*)Channel__ReaderDesc_SetPos,(void*)Channel__ReaderDesc_ReadByte,(void*)Channel__ReaderDesc_ReadBytes,(void*)Channel__ReaderDesc_ClearError}, NULL, &_mid, "ReaderDesc", 16, 0, 0, RT0__strRecord };
RT0__StructDesc _td_Channel__Writer = { (RT0__Struct[]){&_td_Channel__WriterDesc}, NULL, NULL, &_mid, "Writer", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Channel__WriterDesc = { (RT0__Struct[]){&_td_Channel__WriterDesc}, (void*[]){(void*)Channel__WriterDesc_Pos,(void*)Channel__WriterDesc_SetPos,(void*)Channel__WriterDesc_WriteByte,(void*)Channel__WriterDesc_WriteBytes,(void*)Channel__WriterDesc_ClearError}, NULL, &_mid, "WriterDesc", 16, 0, 0, RT0__strRecord };
RT0__StructDesc _td_Channel__ErrorContext = { (RT0__Struct[]){&_td_Channel__ErrorContextDesc}, NULL, NULL, &_mid, "ErrorContext", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Channel__ErrorContextDesc = { (RT0__Struct[]){&_td_Msg__ContextDesc,&_td_Channel__ErrorContextDesc}, (void*[]){(void*)Channel__ErrorContextDesc_GetTemplate}, NULL, &_mid, "ErrorContextDesc", 4, 1, 0, RT0__strRecord };
RT0__StructDesc _td_Channel__12140 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 128, 128, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_Channel__16681 = { (RT0__Struct[]){&RT0__byte}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_Channel__20326 = { (RT0__Struct[]){&RT0__byte}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"Channel", (RT0__Struct[]) { &_td_Channel__Channel, &_td_Channel__ChannelDesc, &_td_Channel__Reader, &_td_Channel__ReaderDesc, &_td_Channel__Writer, &_td_Channel__WriterDesc, &_td_Channel__ErrorContext, &_td_Channel__ErrorContextDesc, NULL } };

extern void OOC_Channel_init0() {
  RT0__RegisterModule(&_mid);
  OOC_Channel_init();
}

/* --- */
