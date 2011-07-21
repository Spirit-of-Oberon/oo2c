static void* _c0;
#include <Config/Source/CmdLine.oh>
#include <CharClass.oh>
#include <Strings.oh>
#include <LongStrings.oh>
#include <TextRider.oh>
#include <IO/TextRider.oh>
#define Config_Source_CmdLine__maxLenArgument 2048
#define Config_Source_CmdLine__connectFailed 1
#define Config_Source_CmdLine__junkAfterEnd 2
#define Config_Source_CmdLine__readError 3
#define Config_Source_CmdLine__unknownOption 4
#define Config_Source_CmdLine__singleCharWithArgs 5
#define Config_Source_CmdLine__expectArguments 6
static Config_Source_CmdLine__ErrorContext Config_Source_CmdLine__cmdLineContext;
static Msg__Msg Config_Source_CmdLine__Error(OOC_INT32 code);
static Msg__Msg Config_Source_CmdLine__ErrorReason(OOC_INT32 code, Msg__Msg reason);
static Msg__Msg Config_Source_CmdLine__ErrorString(OOC_INT32 code, Object__String8 string);
static Msg__Msg Config_Source_CmdLine__ErrorStringNum(OOC_INT32 code, Object__String8 string, OOC_INT32 number);
static void Config_Source_CmdLine__Init(Config_Source_CmdLine__CmdLine cmdLine);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_Config_Source_CmdLine__OptionTemplate = { (RT0__Struct[]){&_td_Config_Source_CmdLine__OptionTemplateDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"OptionTemplate", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Config_Source_CmdLine__1178 = { (RT0__Struct[]){&_td_Object__String8}, NULL, NULL, &_mid, NULL, 4, 1, 0, RT0__strOpenArray };
RT0__StructDesc _td_Config_Source_CmdLine__NameArray = { (RT0__Struct[]){&_td_Config_Source_CmdLine__1178}, NULL, NULL, &_mid, (OOC_CHAR8*)"NameArray", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Config_Source_CmdLine__OptionTemplateDesc = { (RT0__Struct[]){&_td_Config_Source_CmdLine__OptionTemplateDesc}, (void*[]){}, NULL, &_mid, (OOC_CHAR8*)"OptionTemplateDesc", 16, 0, 0, RT0__strRecord };
RT0__StructDesc _td_Config_Source_CmdLine__Command = { (RT0__Struct[]){&_td_Config_Source_CmdLine__CommandDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"Command", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Config_Source_CmdLine__1406 = { (RT0__Struct[]){&_td_Object__String8}, NULL, NULL, &_mid, NULL, 4, 1, 0, RT0__strOpenArray };
RT0__StructDesc _td_Config_Source_CmdLine__ArgList = { (RT0__Struct[]){&_td_Config_Source_CmdLine__1406}, NULL, NULL, &_mid, (OOC_CHAR8*)"ArgList", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Config_Source_CmdLine__CommandDesc = { (RT0__Struct[]){&_td_Config_Source_CmdLine__CommandDesc}, (void*[]){(void*)Config_Source_CmdLine__CommandDesc_DoNotWrite}, NULL, &_mid, (OOC_CHAR8*)"CommandDesc", 16, 0, 0, RT0__strRecord };
RT0__StructDesc _td_Config_Source_CmdLine__CmdLine = { (RT0__Struct[]){&_td_Config_Source_CmdLine__CmdLineDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"CmdLine", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Config_Source_CmdLine__CmdLineDesc = { (RT0__Struct[]){&_td_Config_Source__SourceDesc,&_td_Config_Source_CmdLine__CmdLineDesc}, (void*[]){(void*)Config_Source_CmdLine__CmdLineDesc_Write,(void*)Config_Source_CmdLine__CmdLineDesc_AddOptionTemplate,(void*)Config_Source_CmdLine__CmdLineDesc_EnableDashDash,(void*)Config_Source_CmdLine__CmdLineDesc_EnableExpandToSingleChar,(void*)Config_Source_CmdLine__CmdLineDesc_OptionsStartWithDash,(void*)Config_Source_CmdLine__CmdLineDesc_Parse}, NULL, &_mid, (OOC_CHAR8*)"CmdLineDesc", 16, 1, 0, RT0__strRecord };
RT0__StructDesc _td_Config_Source_CmdLine__ErrorContext = { (RT0__Struct[]){&_td_Config_Source_CmdLine__ErrorContextDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"ErrorContext", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Config_Source_CmdLine__ErrorContextDesc = { (RT0__Struct[]){&_td_Msg__ContextDesc,&_td_Config_Source_CmdLine__ErrorContextDesc}, (void*[]){(void*)Config_Source_CmdLine__ErrorContextDesc_GetTemplate}, NULL, &_mid, (OOC_CHAR8*)"ErrorContextDesc", 4, 1, 0, RT0__strRecord };
RT0__StructDesc _td_Config_Source_CmdLine__4195 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 256, 128, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_Config_Source_CmdLine__6746 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_Config_Source_CmdLine__6809 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_Config_Source_CmdLine__13487 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 2048, 2048, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_Config_Source_CmdLine__13690 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 3, 3, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_Config_Source_CmdLine__13739 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_Config_Source_CmdLine__19908 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1024, 1024, (1<<RT0__flagAtomic), RT0__strArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"Config:Source:CmdLine", (RT0__Struct[]) { &_td_Config_Source_CmdLine__OptionTemplate, &_td_Config_Source_CmdLine__NameArray, &_td_Config_Source_CmdLine__OptionTemplateDesc, &_td_Config_Source_CmdLine__Command, &_td_Config_Source_CmdLine__ArgList, &_td_Config_Source_CmdLine__CommandDesc, &_td_Config_Source_CmdLine__CmdLine, &_td_Config_Source_CmdLine__CmdLineDesc, &_td_Config_Source_CmdLine__ErrorContext, &_td_Config_Source_CmdLine__ErrorContextDesc, NULL }, 0 };

extern void OOC_Config_Source_CmdLine_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_Object_open(&_mid);
    OOC_CharClass_open(&_mid);
    OOC_Strings_open(&_mid);
    OOC_LongStrings_open(&_mid);
    OOC_Msg_open(&_mid);
    OOC_Channel_open(&_mid);
    OOC_TextRider_open(&_mid);
    OOC_IO_open(&_mid);
    OOC_IO_TextRider_open(&_mid);
    OOC_Config_Source_open(&_mid);
    OOC_Config_Parser_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_Config_Source_CmdLine_init();
  }
  _mid.openCount++;
}
extern void OOC_Config_Source_CmdLine_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_Config_Source_CmdLine_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_Object_close(&_mid);
    OOC_CharClass_close(&_mid);
    OOC_Strings_close(&_mid);
    OOC_LongStrings_close(&_mid);
    OOC_Msg_close(&_mid);
    OOC_Channel_close(&_mid);
    OOC_TextRider_close(&_mid);
    OOC_IO_close(&_mid);
    OOC_IO_TextRider_close(&_mid);
    OOC_Config_Source_close(&_mid);
    OOC_Config_Parser_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
