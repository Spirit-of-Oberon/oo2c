#include <OOC/Auxiliary/WriteSymbolFile.oh>
#include <Strings.oh>
#include <IO/BinaryRider.oh>
#include <IO/Memory.oh>
#include <OOC/SymbolTable/Builder.oh>
#include <OOC/SymbolTable/Exports.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:Auxiliary:WriteSymbolFile", (RT0__Struct[]) { NULL } };

extern void OOC_OOC_Auxiliary_WriteSymbolFile_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_Auxiliary_WriteSymbolFile_init();
}

/* --- */
