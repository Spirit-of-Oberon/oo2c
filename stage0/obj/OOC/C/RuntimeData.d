static void* _c0;
static void* _c1;
static void* _c2;
static void* _c3;
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
RT0__StructDesc _td_OOC_C_RuntimeData__2006 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_C_RuntimeData__2883 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:C:RuntimeData", (RT0__Struct[]) { NULL } };

extern void OOC_OOC_C_RuntimeData_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_C_RuntimeData_init();
}

/* --- */
