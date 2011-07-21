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
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:Doc:Output:XML", (RT0__Struct[]) { NULL } };

extern void OOC_OOC_Doc_Output_XML_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_Doc_Output_XML_init();
}

/* --- */
