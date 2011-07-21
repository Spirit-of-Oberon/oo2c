#include <OOC/SymbolTable/InterfaceXML.oh>
#include <XML/Writer.oh>
#include <XML/UnicodeCodec/Latin1.oh>
#include <OOC/Repository.oh>
#include <OOC/SymbolTable/GetClass.oh>
#include <OOC/SymbolTable/Exports.oh>
#include <OOC/Doc/Output/XML.oh>
#define OOC_SymbolTable_InterfaceXML__dtdPackageName "OOC"
#define OOC_SymbolTable_InterfaceXML__dtdResourcePath "xml/module-interface.dtd"
static URI__URI OOC_SymbolTable_InterfaceXML__dtdSystemId;
static URI__URI OOC_SymbolTable_InterfaceXML__GetSystemId(OOC_Config_Repositories__Section repositories);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_SymbolTable_InterfaceXML__2183 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 32, 32, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_SymbolTable_InterfaceXML__2279 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_SymbolTable_InterfaceXML__2972 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_SymbolTable_InterfaceXML__6707 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:SymbolTable:InterfaceXML", (RT0__Struct[]) { NULL } };

extern void OOC_OOC_SymbolTable_InterfaceXML_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_SymbolTable_InterfaceXML_init();
}

/* --- */
