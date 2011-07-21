#include <OOC/Auxiliary/WriteSymbolFile.oh>
#include <Strings.oh>
#include <IO/BinaryRider.oh>
#include <IO/Memory.oh>
#include <OOC/SymbolTable/Builder.oh>
#include <OOC/SymbolTable/Exports.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:Auxiliary:WriteSymbolFile", (RT0__Struct[]) { NULL }, 0 };

extern void OOC_OOC_Auxiliary_WriteSymbolFile_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_Strings_open(&_mid);
    OOC_IO_open(&_mid);
    OOC_IO_BinaryRider_open(&_mid);
    OOC_IO_Memory_open(&_mid);
    OOC_OOC_Repository_open(&_mid);
    OOC_OOC_Error_open(&_mid);
    OOC_OOC_SymbolTable_open(&_mid);
    OOC_OOC_SymbolTable_Builder_open(&_mid);
    OOC_OOC_SymbolTable_Exports_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OOC_Auxiliary_WriteSymbolFile_init();
  }
  _mid.openCount++;
}
extern void OOC_OOC_Auxiliary_WriteSymbolFile_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OOC_Auxiliary_WriteSymbolFile_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_Strings_close(&_mid);
    OOC_IO_close(&_mid);
    OOC_IO_BinaryRider_close(&_mid);
    OOC_IO_Memory_close(&_mid);
    OOC_OOC_Repository_close(&_mid);
    OOC_OOC_Error_close(&_mid);
    OOC_OOC_SymbolTable_close(&_mid);
    OOC_OOC_SymbolTable_Builder_close(&_mid);
    OOC_OOC_SymbolTable_Exports_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
