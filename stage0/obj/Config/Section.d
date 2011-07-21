#include <Config/Section.oh>
#include <LongStrings.oh>
#include <TextRider.oh>
#define Config_Section__invalidRootName 1
#define Config_Section__invalidRootCharData 2
#define Config_Section__unknownSection 3
static Config_Section__ErrorContext Config_Section__sectionContext;

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_Config_Section__Section = { (RT0__Struct[]){&_td_Config_Section__SectionDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"Section", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Config_Section__SectionDesc = { (RT0__Struct[]){&_td_Config_Section__SectionDesc}, (void*[]){(void*)Config_Section__SectionDesc_ProcessElements,(void*)Config_Section__SectionDesc_DumpContent}, NULL, &_mid, (OOC_CHAR8*)"SectionDesc", 4, 0, 0, RT0__strRecord };
RT0__StructDesc _td_Config_Section__Node = { (RT0__Struct[]){&_td_Config_Section__NodeDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"Node", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Config_Section__NodeDesc = { (RT0__Struct[]){&_td_Config_Section__NodeDesc}, (void*[]){}, NULL, &_mid, (OOC_CHAR8*)"NodeDesc", 8, 0, 0, RT0__strRecord };
RT0__StructDesc _td_Config_Section__SectionList = { (RT0__Struct[]){&_td_Config_Section__SectionListDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"SectionList", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Config_Section__SectionListDesc = { (RT0__Struct[]){&_td_Config_Section__SectionListDesc}, (void*[]){(void*)Config_Section__SectionListDesc_Add,(void*)Config_Section__SectionListDesc_Get,(void*)Config_Section__SectionListDesc_ProcessElements,(void*)Config_Section__SectionListDesc_DumpContent}, NULL, &_mid, (OOC_CHAR8*)"SectionListDesc", 4, 0, 0, RT0__strRecord };
RT0__StructDesc _td_Config_Section__ErrorContext = { (RT0__Struct[]){&_td_Config_Section__ErrorContextDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"ErrorContext", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Config_Section__ErrorContextDesc = { (RT0__Struct[]){&_td_Msg__ContextDesc,&_td_XML_Error__ContextDesc,&_td_Config_Section__ErrorContextDesc}, (void*[]){(void*)Config_Section__ErrorContextDesc_GetTemplate,(void*)XML_Error__ContextDesc_WriteTemplate,(void*)XML_Error__ContextDesc_SetString}, NULL, &_mid, (OOC_CHAR8*)"ErrorContextDesc", 8, 2, 0, RT0__strRecord };
RT0__StructDesc _td_Config_Section__794 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 256, 128, (1<<RT0__flagAtomic), RT0__strArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"Config:Section", (RT0__Struct[]) { &_td_Config_Section__Section, &_td_Config_Section__SectionDesc, &_td_Config_Section__Node, &_td_Config_Section__NodeDesc, &_td_Config_Section__SectionList, &_td_Config_Section__SectionListDesc, &_td_Config_Section__ErrorContext, &_td_Config_Section__ErrorContextDesc, NULL }, 0 };

extern void OOC_Config_Section_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_Msg_open(&_mid);
    OOC_Channel_open(&_mid);
    OOC_LongStrings_open(&_mid);
    OOC_TextRider_open(&_mid);
    OOC_XML_Error_open(&_mid);
    OOC_XML_Locator_open(&_mid);
    OOC_Config_Parser_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_Config_Section_init();
  }
  _mid.openCount++;
}
extern void OOC_Config_Section_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_Config_Section_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_Msg_close(&_mid);
    OOC_Channel_close(&_mid);
    OOC_LongStrings_close(&_mid);
    OOC_TextRider_close(&_mid);
    OOC_XML_Error_close(&_mid);
    OOC_XML_Locator_close(&_mid);
    OOC_Config_Parser_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
