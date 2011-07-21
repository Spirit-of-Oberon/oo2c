#include <OOC/AST/CreateIR.oh>
#include <Log.oh>
#include <Object/BigInt.oh>
#include <OOC/Scanner/Symbol.oh>
#include <OOC/Scanner/SymList.oh>
#include <OOC/SymbolTable/TypeRules.oh>
#include <OOC/SymbolTable/Predef.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:AST:CreateIR", (RT0__Struct[]) { NULL } };

extern void OOC_OOC_AST_CreateIR_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_AST_CreateIR_init();
}

/* --- */
