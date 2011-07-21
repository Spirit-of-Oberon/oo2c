#include <IO/Buffer.oh>
#include <ADT/StringBuffer.oh>
#define IO_Buffer__sizeBuffer 8192
#define IO_Buffer__sizeDirect 4096

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_IO_Buffer__Channel = { (RT0__Struct[]){&_td_IO_Buffer__ChannelDesc}, NULL, NULL, &_mid, "Channel", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_IO_Buffer__ChannelDesc = { (RT0__Struct[]){&_td_IO__ChannelDesc,&_td_IO__ByteChannelDesc,&_td_IO_Buffer__ChannelDesc}, (void*[]){(void*)IO_Buffer__ChannelDesc_INIT,(void*)IO_Buffer__ChannelDesc_FileDescriptor,(void*)IO__ChannelDesc_RegisterWithSelector,(void*)IO__ChannelDesc_KeyForSelector,(void*)IO_Buffer__ChannelDesc_SetBlocking,(void*)IO_Buffer__ChannelDesc_Close,(void*)IO_Buffer__ChannelDesc_CloseAndRegister,(void*)IO_Buffer__ChannelDesc_SetPos,(void*)IO_Buffer__ChannelDesc_Read,(void*)IO_Buffer__ChannelDesc_Write,(void*)IO_Buffer__ChannelDesc_Flush,(void*)IO__ByteChannelDesc_TransferTo,(void*)IO_Buffer__ChannelDesc_ReadLineLF}, NULL, &_mid, "ChannelDesc", 8216, 2, 0, RT0__strRecord };
RT0__StructDesc _td_IO_Buffer__1367 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 8192, 8192, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_IO_Buffer__2259 = { (RT0__Struct[]){&RT0__byte}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_IO_Buffer__6200 = { (RT0__Struct[]){&RT0__byte}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"IO:Buffer", (RT0__Struct[]) { &_td_IO_Buffer__Channel, &_td_IO_Buffer__ChannelDesc, NULL } };

extern void OOC_IO_Buffer_init0() {
  RT0__RegisterModule(&_mid);
  OOC_IO_Buffer_init();
}

/* --- */
