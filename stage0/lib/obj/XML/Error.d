static void* _c0;
static void* _c1;
#include <XML/Error.oh>
#include <Ascii.oh>
#include <Strings.oh>
#include <TextRider.oh>
#include <LongStrings.oh>
#include <Object.oh>
#include <IO.oh>
#include <OS/ProcessParameters.oh>
#include <URI/Scheme/File.oh>
OOC_INT32 XML_Error__errMsgLineBase;
OOC_INT32 XML_Error__errMsgColumnBase;
OOC_INT32 XML_Error__errMsgCharPosBase;

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_XML_Error__Mapping = { (RT0__Struct[]){&_td_XML_Error__MappingDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"Mapping", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_XML_Error__MappingDesc = { (RT0__Struct[]){&_td_XML_Error__MappingDesc}, (void*[]){}, NULL, &_mid, (OOC_CHAR8*)"MappingDesc", 12, 0, 0, RT0__strRecord };
RT0__StructDesc _td_XML_Error__Context = { (RT0__Struct[]){&_td_XML_Error__ContextDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"Context", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_XML_Error__ContextDesc = { (RT0__Struct[]){&_td_Msg__ContextDesc,&_td_XML_Error__ContextDesc}, (void*[]){(void*)XML_Error__ContextDesc_GetTemplate,(void*)XML_Error__ContextDesc_WriteTemplate,(void*)XML_Error__ContextDesc_SetString}, NULL, &_mid, (OOC_CHAR8*)"ContextDesc", 8, 1, 0, RT0__strRecord };
RT0__StructDesc _td_XML_Error__List = { (RT0__Struct[]){&_td_XML_Error__ListDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"List", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_XML_Error__ListDesc = { (RT0__Struct[]){&_td_Msg__MsgListDesc,&_td_XML_Error__ListDesc}, (void*[]){(void*)Msg__MsgListDesc_Append,(void*)Msg__MsgListDesc_AppendList,(void*)XML_Error__ListDesc_Write}, NULL, &_mid, (OOC_CHAR8*)"ListDesc", 16, 1, 0, RT0__strRecord };
RT0__StructDesc _td_XML_Error__3911 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 2048, 1024, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_XML_Error__5115 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 8192, 8192, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_XML_Error__5212 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1024, 1024, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_XML_Error__5299 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_XML_Error__5329 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_XML_Error__6273 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"XML:Error", (RT0__Struct[]) { &_td_XML_Error__Mapping, &_td_XML_Error__MappingDesc, &_td_XML_Error__Context, &_td_XML_Error__ContextDesc, &_td_XML_Error__List, &_td_XML_Error__ListDesc, NULL }, 0 };

extern void OOC_XML_Error_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_Ascii_open(&_mid);
    OOC_Strings_open(&_mid);
    OOC_Channel_open(&_mid);
    OOC_TextRider_open(&_mid);
    OOC_LongStrings_open(&_mid);
    OOC_Msg_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_IO_open(&_mid);
    OOC_OS_ProcessParameters_open(&_mid);
    OOC_URI_open(&_mid);
    OOC_URI_Scheme_File_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_XML_Error_init();
  }
  _mid.openCount++;
}
extern void OOC_XML_Error_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_XML_Error_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_Ascii_close(&_mid);
    OOC_Strings_close(&_mid);
    OOC_Channel_close(&_mid);
    OOC_TextRider_close(&_mid);
    OOC_LongStrings_close(&_mid);
    OOC_Msg_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_IO_close(&_mid);
    OOC_OS_ProcessParameters_close(&_mid);
    OOC_URI_close(&_mid);
    OOC_URI_Scheme_File_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
