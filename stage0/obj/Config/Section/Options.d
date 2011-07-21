#include <Config/Section/Options.oh>
#include <Exception.oh>
#include <Object.oh>
#include <TextRider.oh>
#include <LongStrings.oh>
#include <XML/Builder.oh>
#include <XML/DTD.oh>
#define Config_Section_Options__invalidContent 1
#define Config_Section_Options__invalidAttribute 2
#define Config_Section_Options__requireNameAttribute 3
#define Config_Section_Options__requireTypeAttribute 4
#define Config_Section_Options__requireCharDataContent 5
#define Config_Section_Options__optionAlreadyDefined 6
#define Config_Section_Options__optionNotDefined 7
#define Config_Section_Options__unknownType 8
#define Config_Section_Options__invalidValue 9
static Config_Section_Options__ErrorContext Config_Section_Options__optionsContext;
static void Config_Section_Options__InitOption(Config_Section_Options__Option opt, Object__String name, Config__Variable value);
static Config_Section_Options__Option Config_Section_Options__NewOption(Object__String name, Config__Variable value);
static void Config_Section_Options__Insert(Config_Section_Options__Option *list, Config_Section_Options__Option opt);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_Config_Section_Options__Section = { (RT0__Struct[]){&_td_Config_Section_Options__SectionDesc}, NULL, NULL, &_mid, "Section", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Config_Section_Options__Option = { (RT0__Struct[]){&_td_Config_Section_Options__OptionDesc}, NULL, NULL, &_mid, "Option", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Config_Section_Options__SectionDesc = { (RT0__Struct[]){&_td_Config_Section__SectionDesc,&_td_Config_Section_Options__SectionDesc}, (void*[]){(void*)Config_Section_Options__SectionDesc_ProcessElements,(void*)Config_Section_Options__SectionDesc_DumpContent,(void*)Config_Section_Options__SectionDesc_Get,(void*)Config_Section_Options__SectionDesc_Set,(void*)Config_Section_Options__SectionDesc_GetValue,(void*)Config_Section_Options__SectionDesc_Copy,(void*)Config_Section_Options__SectionDesc_Clone}, NULL, &_mid, "SectionDesc", 12, 1, 0, RT0__strRecord };
RT0__StructDesc _td_Config_Section_Options__OptionDesc = { (RT0__Struct[]){&_td_Config_Section_Options__OptionDesc}, (void*[]){(void*)Config_Section_Options__OptionDesc_Set}, NULL, &_mid, "OptionDesc", 12, 0, 0, RT0__strRecord };
RT0__StructDesc _td_Config_Section_Options__ErrorContext = { (RT0__Struct[]){&_td_Config_Section_Options__ErrorContextDesc}, NULL, NULL, &_mid, "ErrorContext", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Config_Section_Options__ErrorContextDesc = { (RT0__Struct[]){&_td_Msg__ContextDesc,&_td_XML_Error__ContextDesc,&_td_Config_Section__ErrorContextDesc,&_td_Config_Section_Options__ErrorContextDesc}, (void*[]){(void*)Config_Section_Options__ErrorContextDesc_GetTemplate,(void*)XML_Error__ContextDesc_WriteTemplate,(void*)XML_Error__ContextDesc_SetString}, NULL, &_mid, "ErrorContextDesc", 8, 3, 0, RT0__strRecord };
RT0__StructDesc _td_Config_Section_Options__992 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 256, 128, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_Config_Section_Options__8494 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 2048, 2048, (1<<RT0__flagAtomic), RT0__strArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"Config:Section:Options", (RT0__Struct[]) { &_td_Config_Section_Options__Section, &_td_Config_Section_Options__Option, &_td_Config_Section_Options__SectionDesc, &_td_Config_Section_Options__OptionDesc, &_td_Config_Section_Options__ErrorContext, &_td_Config_Section_Options__ErrorContextDesc, NULL } };

extern void OOC_Config_Section_Options_init0() {
  RT0__RegisterModule(&_mid);
  OOC_Config_Section_Options_init();
}

/* --- */
