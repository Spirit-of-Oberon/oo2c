#include <XML/Locator.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_XML_Locator__Locator = { (RT0__Struct[]){&_td_XML_Locator__Position}, NULL, NULL, &_mid, (OOC_CHAR8*)"Locator", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_XML_Locator__Position = { (RT0__Struct[]){&_td_XML_Locator__Position}, (void*[]){}, NULL, &_mid, (OOC_CHAR8*)"Position", 20, 0, 0, RT0__strRecord };
RT0__StructDesc _td_XML_Locator__ErrorListener = { (RT0__Struct[]){&_td_XML_Locator__ErrorListenerDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"ErrorListener", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_XML_Locator__ErrorListenerDesc = { (RT0__Struct[]){&_td_XML_Locator__ErrorListenerDesc}, (void*[]){(void*)XML_Locator__ErrorListenerDesc_Error}, NULL, &_mid, (OOC_CHAR8*)"ErrorListenerDesc", 0, 0, (1<<RT0__flagAtomic), RT0__strRecord };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"XML:Locator", (RT0__Struct[]) { &_td_XML_Locator__Locator, &_td_XML_Locator__Position, &_td_XML_Locator__ErrorListener, &_td_XML_Locator__ErrorListenerDesc, NULL }, 0 };

extern void OOC_XML_Locator_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_XML_UnicodeBuffer_open(&_mid);
    OOC_XML_Error_open(&_mid);
    OOC_XML_DTD_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_XML_Locator_init();
  }
  _mid.openCount++;
}
extern void OOC_XML_Locator_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_XML_Locator_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_XML_UnicodeBuffer_close(&_mid);
    OOC_XML_Error_close(&_mid);
    OOC_XML_DTD_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
