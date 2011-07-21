#include <OOC/Error.oh>
#include <IO/TextRider.oh>
#include <LongStrings.oh>
#include <CharClass.oh>
#include <Object.oh>
#include <OS/Path.oh>
OOC_INT8 OOC_Error__style;
OOC_INT32 OOC_Error__minErrorDistance;
#define OOC_Error__posAttr "pos"
#define OOC_Error__columnAttr "column"
#define OOC_Error__lineAttr "line"
static OOC_CHAR8 OOC_Error__IsWarning(Msg__Msg msg);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_Error__Context = { (RT0__Struct[]){&_td_OOC_Error__ContextDesc}, NULL, NULL, &_mid, "Context", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Error__ContextDesc = { (RT0__Struct[]){&_td_Msg__ContextDesc,&_td_OOC_Error__ContextDesc}, (void*[]){(void*)Msg__ContextDesc_GetTemplate,(void*)OOC_Error__ContextDesc_BaseTemplate}, NULL, &_mid, "ContextDesc", 4, 1, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_Error__List = { (RT0__Struct[]){&_td_OOC_Error__ListDesc}, NULL, NULL, &_mid, "List", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Error__ListDesc = { (RT0__Struct[]){&_td_Msg__MsgListDesc,&_td_OOC_Error__ListDesc}, (void*[]){(void*)OOC_Error__ListDesc_Append,(void*)Msg__MsgListDesc_AppendList,(void*)OOC_Error__ListDesc_AppendWarning,(void*)OOC_Error__ListDesc_NoErrors,(void*)OOC_Error__ListDesc_SetAdjustCharPos,(void*)OOC_Error__ListDesc_Write}, NULL, &_mid, "ListDesc", 272, 1, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_Error__1375 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 256, 256, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_Error__3350 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 256, 128, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_Error__4991 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 16384, 8192, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_Error__6576 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 8192, 8192, (1<<RT0__flagAtomic), RT0__strArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:Error", (RT0__Struct[]) { &_td_OOC_Error__Context, &_td_OOC_Error__ContextDesc, &_td_OOC_Error__List, &_td_OOC_Error__ListDesc, NULL }, 0 };

extern void OOC_OOC_Error_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_IO_open(&_mid);
    OOC_IO_TextRider_open(&_mid);
    OOC_LongStrings_open(&_mid);
    OOC_CharClass_open(&_mid);
    OOC_Msg_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_OS_Path_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OOC_Error_init();
  }
  _mid.openCount++;
}
extern void OOC_OOC_Error_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OOC_Error_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_IO_close(&_mid);
    OOC_IO_TextRider_close(&_mid);
    OOC_LongStrings_close(&_mid);
    OOC_CharClass_close(&_mid);
    OOC_Msg_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_OS_Path_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
