#include <IO/Memory.oh>
#define IO_Memory__offset 16

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_IO_Memory__933 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_IO_Memory__Data = { (RT0__Struct[]){&_td_IO_Memory__933}, NULL, NULL, &_mid, "Data", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_IO_Memory__Channel = { (RT0__Struct[]){&_td_IO_Memory__ChannelDesc}, NULL, NULL, &_mid, "Channel", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_IO_Memory__ChannelDesc = { (RT0__Struct[]){&_td_IO__ChannelDesc,&_td_IO__ByteChannelDesc,&_td_IO_Memory__ChannelDesc}, (void*[]){(void*)IO_Memory__ChannelDesc_INIT,(void*)IO_Memory__ChannelDesc_FileDescriptor,(void*)IO__ChannelDesc_RegisterWithSelector,(void*)IO__ChannelDesc_KeyForSelector,(void*)IO_Memory__ChannelDesc_SetBlocking,(void*)IO__ChannelDesc_Close,(void*)IO__ChannelDesc_CloseAndRegister,(void*)IO_Memory__ChannelDesc_SetPos,(void*)IO_Memory__ChannelDesc_Read,(void*)IO_Memory__ChannelDesc_Write,(void*)IO__ByteChannelDesc_Flush,(void*)IO__ByteChannelDesc_TransferTo,(void*)IO_Memory__ChannelDesc_Truncate,(void*)IO_Memory__ChannelDesc_Fingerprint}, NULL, &_mid, "ChannelDesc", 20, 2, 0, RT0__strRecord };
RT0__StructDesc _td_IO_Memory__1732 = { (RT0__Struct[]){&RT0__byte}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_IO_Memory__2475 = { (RT0__Struct[]){&RT0__byte}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_IO_Memory__3333 = { (RT0__Struct[]){&RT0__byte}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"IO:Memory", (RT0__Struct[]) { &_td_IO_Memory__Data, &_td_IO_Memory__Channel, &_td_IO_Memory__ChannelDesc, NULL } };

extern void OOC_IO_Memory_init0() {
  RT0__RegisterModule(&_mid);
  OOC_IO_Memory_init();
}

/* --- */
