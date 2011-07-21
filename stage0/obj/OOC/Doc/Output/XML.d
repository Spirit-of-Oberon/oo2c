#include <OOC/Doc/Output/XML.oh>
#include <Strings.oh>
#include <Object.oh>
#include <XML/UnicodeCodec/Latin1.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_Doc_Output_XML__1628 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 2048, 2048, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_Doc_Output_XML__2550 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 32, 32, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_Doc_Output_XML__2612 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_Doc_Output_XML__5649 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 32, 32, (1<<RT0__flagAtomic), RT0__strArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:Doc:Output:XML", (RT0__Struct[]) { NULL }, 0 };

extern void OOC_OOC_Doc_Output_XML_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_Strings_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_ADT_Dictionary_open(&_mid);
    OOC_IO_open(&_mid);
    OOC_XML_Writer_open(&_mid);
    OOC_XML_UnicodeCodec_Latin1_open(&_mid);
    OOC_OOC_Config_Repositories_open(&_mid);
    OOC_OOC_Repository_open(&_mid);
    OOC_OOC_Doc_open(&_mid);
    OOC_OOC_SymbolTable_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OOC_Doc_Output_XML_init();
  }
  _mid.openCount++;
}
extern void OOC_OOC_Doc_Output_XML_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OOC_Doc_Output_XML_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_Strings_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_ADT_Dictionary_close(&_mid);
    OOC_IO_close(&_mid);
    OOC_XML_Writer_close(&_mid);
    OOC_XML_UnicodeCodec_Latin1_close(&_mid);
    OOC_OOC_Config_Repositories_close(&_mid);
    OOC_OOC_Repository_close(&_mid);
    OOC_OOC_Doc_close(&_mid);
    OOC_OOC_SymbolTable_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
