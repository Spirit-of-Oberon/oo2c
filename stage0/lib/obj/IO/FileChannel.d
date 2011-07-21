#include <IO/FileChannel.oh>
typedef IO_FileChannel__Channel IO_FileChannel__ChannelList[];

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_IO_FileChannel__Channel = { (RT0__Struct[]){&_td_IO_FileChannel__ChannelDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"Channel", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_IO_FileChannel__ChannelList = { (RT0__Struct[]){&_td_IO_FileChannel__Channel}, NULL, NULL, &_mid, (OOC_CHAR8*)"ChannelList", 4, 1, 0, RT0__strOpenArray };
RT0__StructDesc _td_IO_FileChannel__ChannelDesc = { (RT0__Struct[]){&_td_IO__ChannelDesc,&_td_IO__ByteChannelDesc,&_td_IO_FileChannel__ChannelDesc}, (void*[]){(void*)IO__ByteChannelDesc_INIT,(void*)IO_FileChannel__ChannelDesc_FileDescriptor,(void*)IO__ChannelDesc_RegisterWithSelector,(void*)IO__ChannelDesc_KeyForSelector,(void*)IO_FileChannel__ChannelDesc_SetBlocking,(void*)IO_FileChannel__ChannelDesc_Close,(void*)IO_FileChannel__ChannelDesc_CloseAndRegister,(void*)IO_FileChannel__ChannelDesc_SetPos,(void*)IO_FileChannel__ChannelDesc_Read,(void*)IO_FileChannel__ChannelDesc_Write,(void*)IO__ByteChannelDesc_Flush,(void*)IO__ByteChannelDesc_TransferTo,(void*)IO_FileChannel__ChannelDesc_Length}, NULL, &_mid, (OOC_CHAR8*)"ChannelDesc", 24, 2, 0, RT0__strRecord };
RT0__StructDesc _td_IO_FileChannel__3254 = { (RT0__Struct[]){&RT0__byte}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_IO_FileChannel__3409 = { (RT0__Struct[]){&RT0__byte}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"IO:FileChannel", (RT0__Struct[]) { &_td_IO_FileChannel__Channel, &_td_IO_FileChannel__ChannelList, &_td_IO_FileChannel__ChannelDesc, NULL }, 0 };

extern void OOC_IO_FileChannel_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Termination_open(&_mid);
    OOC_OS_Path_open(&_mid);
    OOC_IO_open(&_mid);
    OOC_IO_StdChannels_open(&_mid);
    OOC_IO_Buffer_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_IO_FileChannel_init();
  }
  _mid.openCount++;
}
extern void OOC_IO_FileChannel_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_IO_FileChannel_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Termination_close(&_mid);
    OOC_OS_Path_close(&_mid);
    OOC_IO_close(&_mid);
    OOC_IO_StdChannels_close(&_mid);
    OOC_IO_Buffer_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
