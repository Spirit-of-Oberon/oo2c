#include <Config/Section/Arguments.oh>
#include <Object.oh>
#include <TextRider.oh>
#include <LongStrings.oh>
#include <XML/Builder.oh>
#define Config_Section_Arguments__invalidContent 1
#define Config_Section_Arguments__invalidAttribute 2
#define Config_Section_Arguments__requireCharDataContent 5
static Config_Section_Arguments__ErrorContext Config_Section_Arguments__argumentsContext;
static void Config_Section_Arguments__Init(Config_Section_Arguments__Section s, const Config_Parser__String id__ref, OOC_LEN id_0d);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_Config_Section_Arguments__Section = { (RT0__Struct[]){&_td_Config_Section_Arguments__SectionDesc}, NULL, NULL, &_mid, "Section", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Config_Section_Arguments__243 = { (RT0__Struct[]){&_td_Object__String}, NULL, NULL, &_mid, NULL, 4, 1, 0, RT0__strOpenArray };
RT0__StructDesc _td_Config_Section_Arguments__ArgumentArray = { (RT0__Struct[]){&_td_Config_Section_Arguments__243}, NULL, NULL, &_mid, "ArgumentArray", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Config_Section_Arguments__SectionDesc = { (RT0__Struct[]){&_td_Config_Section__SectionDesc,&_td_Config_Section_Arguments__SectionDesc}, (void*[]){(void*)Config_Section_Arguments__SectionDesc_ProcessElements,(void*)Config_Section_Arguments__SectionDesc_DumpContent,(void*)Config_Section_Arguments__SectionDesc_ArgNumber,(void*)Config_Section_Arguments__SectionDesc_Get}, NULL, &_mid, "SectionDesc", 12, 1, 0, RT0__strRecord };
RT0__StructDesc _td_Config_Section_Arguments__ErrorContext = { (RT0__Struct[]){&_td_Config_Section_Arguments__ErrorContextDesc}, NULL, NULL, &_mid, "ErrorContext", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Config_Section_Arguments__ErrorContextDesc = { (RT0__Struct[]){&_td_Msg__ContextDesc,&_td_XML_Error__ContextDesc,&_td_Config_Section__ErrorContextDesc,&_td_Config_Section_Arguments__ErrorContextDesc}, (void*[]){(void*)Config_Section_Arguments__ErrorContextDesc_GetTemplate,(void*)XML_Error__ContextDesc_WriteTemplate,(void*)XML_Error__ContextDesc_SetString}, NULL, &_mid, "ErrorContextDesc", 8, 3, 0, RT0__strRecord };
RT0__StructDesc _td_Config_Section_Arguments__720 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 256, 128, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_Config_Section_Arguments__3559 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 2048, 2048, (1<<RT0__flagAtomic), RT0__strArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"Config:Section:Arguments", (RT0__Struct[]) { &_td_Config_Section_Arguments__Section, &_td_Config_Section_Arguments__ArgumentArray, &_td_Config_Section_Arguments__SectionDesc, &_td_Config_Section_Arguments__ErrorContext, &_td_Config_Section_Arguments__ErrorContextDesc, NULL } };

extern void OOC_Config_Section_Arguments_init0() {
  RT0__RegisterModule(&_mid);
  OOC_Config_Section_Arguments_init();
}

/* --- */
