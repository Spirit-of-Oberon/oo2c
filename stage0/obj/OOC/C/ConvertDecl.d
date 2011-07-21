static void* _c0;
static void* _c1;
#include <OOC/C/ConvertDecl.oh>
#include <Object.oh>
#include <Object/BigInt.oh>
#include <OOC/SymbolTable/Predef.oh>
#include <OOC/SymbolTable/TypeRules.oh>
#include <OOC/C/Naming.oh>
#define OOC_C_ConvertDecl__modeWriteExported 0
#define OOC_C_ConvertDecl__modeWritePrivate 1
#define OOC_C_ConvertDecl__modeWriteFctDef 2
#define OOC_C_ConvertDecl__modeFormalParameter 3
static OOC_C_DeclWriter__Declaration OOC_C_ConvertDecl__ConvertDecl(OOC_C_DeclWriter__Writer w, OOC_SymbolTable__Declaration item, OOC_INT8 mode);

/* run-time meta data */
static RT0__ModuleDesc _mid;
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:C:ConvertDecl", (RT0__Struct[]) { NULL }, 0 };

extern void OOC_OOC_C_ConvertDecl_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_Object_open(&_mid);
    OOC_Object_BigInt_open(&_mid);
    OOC_OOC_Repository_open(&_mid);
    OOC_OOC_SymbolTable_open(&_mid);
    OOC_OOC_SymbolTable_Predef_open(&_mid);
    OOC_OOC_SymbolTable_TypeRules_open(&_mid);
    OOC_OOC_C_Naming_open(&_mid);
    OOC_OOC_C_DeclWriter_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OOC_C_ConvertDecl_init();
  }
  _mid.openCount++;
}
extern void OOC_OOC_C_ConvertDecl_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OOC_C_ConvertDecl_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_Object_close(&_mid);
    OOC_Object_BigInt_close(&_mid);
    OOC_OOC_Repository_close(&_mid);
    OOC_OOC_SymbolTable_close(&_mid);
    OOC_OOC_SymbolTable_Predef_close(&_mid);
    OOC_OOC_SymbolTable_TypeRules_close(&_mid);
    OOC_OOC_C_Naming_close(&_mid);
    OOC_OOC_C_DeclWriter_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
