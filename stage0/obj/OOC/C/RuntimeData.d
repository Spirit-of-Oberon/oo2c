static void* _c0;
static void* _c1;
static void* _c2;
static void* _c3;
static void* _c4;
#include <OOC/C/RuntimeData.oh>
#include <IO/TextRider.oh>
#include <ADT/ArrayList.oh>
#include <ADT/StringBuffer.oh>
#include <OOC/Config.oh>
#include <OOC/SymbolTable/Predef.oh>
#include <OOC/SymbolTable/Namespace.oh>
#include <OOC/SymbolTable/TypeRules.oh>
#define OOC_C_RuntimeData__structTypeDesc "RT0__StructDesc"

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_C_RuntimeData__2012 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_C_RuntimeData__2889 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:C:RuntimeData", (RT0__Struct[]) { NULL }, 0 };

extern void OOC_OOC_C_RuntimeData_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_IO_TextRider_open(&_mid);
    OOC_ADT_ArrayList_open(&_mid);
    OOC_ADT_StringBuffer_open(&_mid);
    OOC_OOC_Config_open(&_mid);
    OOC_OOC_SymbolTable_open(&_mid);
    OOC_OOC_SymbolTable_Predef_open(&_mid);
    OOC_OOC_SymbolTable_Namespace_open(&_mid);
    OOC_OOC_SymbolTable_TypeRules_open(&_mid);
    OOC_OOC_C_Naming_open(&_mid);
    OOC_OOC_C_DeclWriter_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OOC_C_RuntimeData_init();
  }
  _mid.openCount++;
}
extern void OOC_OOC_C_RuntimeData_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OOC_C_RuntimeData_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_IO_TextRider_close(&_mid);
    OOC_ADT_ArrayList_close(&_mid);
    OOC_ADT_StringBuffer_close(&_mid);
    OOC_OOC_Config_close(&_mid);
    OOC_OOC_SymbolTable_close(&_mid);
    OOC_OOC_SymbolTable_Predef_close(&_mid);
    OOC_OOC_SymbolTable_Namespace_close(&_mid);
    OOC_OOC_SymbolTable_TypeRules_close(&_mid);
    OOC_OOC_C_Naming_close(&_mid);
    OOC_OOC_C_DeclWriter_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
