#include <ProgramArgs.oh>
#include <RT0.oh>
#include <CharClass.oh>
#include <Msg.oh>
ProgramArgs__Channel ProgramArgs__args;
typedef struct ProgramArgs__ErrorContextDesc *ProgramArgs__ErrorContext;
static ProgramArgs__ErrorContext ProgramArgs__errorContext;
static Msg__Msg ProgramArgs__GetError(OOC_INT32 code);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_ProgramArgs__Channel = { (RT0__Struct[]){&_td_ProgramArgs__ChannelDesc}, NULL, NULL, &_mid, "Channel", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_ProgramArgs__ChannelDesc = { (RT0__Struct[]){&_td_Channel__ChannelDesc,&_td_ProgramArgs__ChannelDesc}, (void*[]){(void*)ProgramArgs__ChannelDesc_Length,(void*)ProgramArgs__ChannelDesc_GetModTime,(void*)ProgramArgs__ChannelDesc_NewReader,(void*)Channel__ChannelDesc_NewWriter,(void*)ProgramArgs__ChannelDesc_Flush,(void*)ProgramArgs__ChannelDesc_Close,(void*)Channel__ChannelDesc_ClearError,(void*)ProgramArgs__ChannelDesc_ArgNumber}, NULL, &_mid, "ChannelDesc", 8, 1, 0, RT0__strRecord };
RT0__StructDesc _td_ProgramArgs__Reader = { (RT0__Struct[]){&_td_ProgramArgs__ReaderDesc}, NULL, NULL, &_mid, "Reader", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_ProgramArgs__ReaderDesc = { (RT0__Struct[]){&_td_Channel__ReaderDesc,&_td_ProgramArgs__ReaderDesc}, (void*[]){(void*)ProgramArgs__ReaderDesc_Pos,(void*)ProgramArgs__ReaderDesc_Available,(void*)ProgramArgs__ReaderDesc_SetPos,(void*)ProgramArgs__ReaderDesc_ReadByte,(void*)ProgramArgs__ReaderDesc_ReadBytes,(void*)Channel__ReaderDesc_ClearError}, NULL, &_mid, "ReaderDesc", 24, 1, 0, RT0__strRecord };
RT0__StructDesc _td_ProgramArgs__ErrorContext = { (RT0__Struct[]){&_td_ProgramArgs__ErrorContextDesc}, NULL, NULL, &_mid, "ErrorContext", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_ProgramArgs__ErrorContextDesc = { (RT0__Struct[]){&_td_Msg__ContextDesc,&_td_Channel__ErrorContextDesc,&_td_ProgramArgs__ErrorContextDesc}, (void*[]){(void*)Channel__ErrorContextDesc_GetTemplate}, NULL, &_mid, "ErrorContextDesc", 4, 2, 0, RT0__strRecord };
RT0__StructDesc _td_ProgramArgs__5299 = { (RT0__Struct[]){&RT0__byte}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"ProgramArgs", (RT0__Struct[]) { &_td_ProgramArgs__Channel, &_td_ProgramArgs__ChannelDesc, &_td_ProgramArgs__Reader, &_td_ProgramArgs__ReaderDesc, &_td_ProgramArgs__ErrorContext, &_td_ProgramArgs__ErrorContextDesc, NULL } };

extern void OOC_ProgramArgs_init0() {
  RT0__RegisterModule(&_mid);
  OOC_ProgramArgs_init();
}

/* --- */
