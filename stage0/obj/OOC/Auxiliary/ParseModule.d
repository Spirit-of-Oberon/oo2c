#include <OOC/Auxiliary/ParseModule.oh>
#include <URI.oh>
#include <OOC/Config.oh>
#include <OOC/Scanner/InputBuffer.oh>
#include <OOC/Scanner.oh>
#include <OOC/Scanner/SymList.oh>
#include <OOC/Parser.oh>
#include <OOC/SymbolTable/Builder.oh>
#include <OOC/AST/CreateSymTab.oh>
#include <OOC/SymbolTable/CreateNamespace.oh>
#include <OOC/Auxiliary/WriteSymbolFile.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:Auxiliary:ParseModule", (RT0__Struct[]) { NULL } };

extern void OOC_OOC_Auxiliary_ParseModule_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_Auxiliary_ParseModule_init();
}

/* --- */
