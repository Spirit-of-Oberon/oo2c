#include <StdChannels.oh>
#include <PosixFileDescr.oh>
#include <Termination.oh>
#include <Msg.oh>
Channel__Channel StdChannels__stdin;
Channel__Channel StdChannels__stdout;
Channel__Channel StdChannels__stderr;
StdChannels__NullChannel StdChannels__null;
static PosixFileDescr__Channel StdChannels__fd;
typedef struct StdChannels__ErrorContextDesc *StdChannels__ErrorContext;
typedef struct StdChannels__ErrorContextDesc {
  Msg__StringPtr id;
} StdChannels__ErrorContextDesc;
static StdChannels__ErrorContext StdChannels__errorContext;
static Msg__Msg StdChannels__GetError(OOC_INT32 code);
static void StdChannels__Flush(void);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_StdChannels__NullChannel = { (RT0__Struct[]){&_td_StdChannels__NullChannelDesc}, NULL, NULL, &_mid, "NullChannel", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_StdChannels__Writer = { (RT0__Struct[]){&_td_StdChannels__WriterDesc}, NULL, NULL, &_mid, "Writer", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_StdChannels__NullChannelDesc = { (RT0__Struct[]){&_td_Channel__ChannelDesc,&_td_StdChannels__NullChannelDesc}, (void*[]){(void*)StdChannels__NullChannelDesc_Length,(void*)StdChannels__NullChannelDesc_GetModTime,(void*)StdChannels__NullChannelDesc_NewReader,(void*)StdChannels__NullChannelDesc_NewWriter,(void*)StdChannels__NullChannelDesc_Flush,(void*)StdChannels__NullChannelDesc_Close,(void*)Channel__ChannelDesc_ClearError}, NULL, &_mid, "NullChannelDesc", 12, 1, 0, RT0__strRecord };
RT0__StructDesc _td_StdChannels__WriterDesc = { (RT0__Struct[]){&_td_Channel__WriterDesc,&_td_StdChannels__WriterDesc}, (void*[]){(void*)StdChannels__WriterDesc_Pos,(void*)StdChannels__WriterDesc_SetPos,(void*)StdChannels__WriterDesc_WriteByte,(void*)StdChannels__WriterDesc_WriteBytes,(void*)Channel__WriterDesc_ClearError}, NULL, &_mid, "WriterDesc", 16, 1, 0, RT0__strRecord };
RT0__StructDesc _td_StdChannels__ErrorContext = { (RT0__Struct[]){&_td_StdChannels__ErrorContextDesc}, NULL, NULL, &_mid, "ErrorContext", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_StdChannels__ErrorContextDesc = { (RT0__Struct[]){&_td_Msg__ContextDesc,&_td_Channel__ErrorContextDesc,&_td_StdChannels__ErrorContextDesc}, (void*[]){(void*)Channel__ErrorContextDesc_GetTemplate}, NULL, &_mid, "ErrorContextDesc", 4, 2, 0, RT0__strRecord };
RT0__StructDesc _td_StdChannels__2863 = { (RT0__Struct[]){&RT0__byte}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"StdChannels", (RT0__Struct[]) { &_td_StdChannels__NullChannel, &_td_StdChannels__Writer, &_td_StdChannels__NullChannelDesc, &_td_StdChannels__WriterDesc, &_td_StdChannels__ErrorContext, &_td_StdChannels__ErrorContextDesc, NULL } };

extern void OOC_StdChannels_init0() {
  RT0__RegisterModule(&_mid);
  OOC_StdChannels_init();
}

/* --- */
