#include <OOC/Make/TranslateToX86.oh>
#include <IO/StdChannels.oh>
#include <OOC/Config/Pragmas.oh>
#include <OOC/Auxiliary/ParseModule.oh>
#include <OOC/Auxiliary/WriteSymbolFile.oh>
#include <OOC/AST.oh>
#include <OOC/AST/CreateIR.oh>
#include <OOC/AST/XML.oh>
#include <OOC/IR.oh>
#include <OOC/IR/XML.oh>
#include <OOC/IR/ConstFold.oh>
#include <OOC/IR/CheckUses.oh>
#include <OOC/SymbolTable.oh>
#include <OOC/SymbolTable/Exports.oh>
#include <OOC/X86/Translate.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:Make:TranslateToX86", (RT0__Struct[]) { NULL } };

extern void OOC_OOC_Make_TranslateToX86_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_Make_TranslateToX86_init();
}

/* --- */
