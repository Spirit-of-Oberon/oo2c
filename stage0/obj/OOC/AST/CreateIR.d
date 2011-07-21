#include <OOC/AST/CreateIR.oh>
#include <Log.oh>
#include <Object/BigInt.oh>
#include <OOC/Scanner/Symbol.oh>
#include <OOC/Scanner/SymList.oh>
#include <OOC/SymbolTable/TypeRules.oh>
#include <OOC/SymbolTable/Predef.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:AST:CreateIR", (RT0__Struct[]) { NULL }, 0 };

extern void OOC_OOC_AST_CreateIR_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_Log_open(&_mid);
    OOC_Object_BigInt_open(&_mid);
    OOC_OOC_Scanner_Symbol_open(&_mid);
    OOC_OOC_Scanner_SymList_open(&_mid);
    OOC_OOC_AST_open(&_mid);
    OOC_OOC_SymbolTable_open(&_mid);
    OOC_OOC_SymbolTable_TypeRules_open(&_mid);
    OOC_OOC_SymbolTable_Predef_open(&_mid);
    OOC_OOC_IR_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OOC_AST_CreateIR_init();
  }
  _mid.openCount++;
}
extern void OOC_OOC_AST_CreateIR_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OOC_AST_CreateIR_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_Log_close(&_mid);
    OOC_Object_BigInt_close(&_mid);
    OOC_OOC_Scanner_Symbol_close(&_mid);
    OOC_OOC_Scanner_SymList_close(&_mid);
    OOC_OOC_AST_close(&_mid);
    OOC_OOC_SymbolTable_close(&_mid);
    OOC_OOC_SymbolTable_TypeRules_close(&_mid);
    OOC_OOC_SymbolTable_Predef_close(&_mid);
    OOC_OOC_IR_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
