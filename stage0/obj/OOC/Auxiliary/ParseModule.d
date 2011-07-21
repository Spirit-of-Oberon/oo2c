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
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:Auxiliary:ParseModule", (RT0__Struct[]) { NULL }, 0 };

extern void OOC_OOC_Auxiliary_ParseModule_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_IO_open(&_mid);
    OOC_URI_open(&_mid);
    OOC_OOC_Config_open(&_mid);
    OOC_OOC_Config_Pragmas_open(&_mid);
    OOC_OOC_Repository_open(&_mid);
    OOC_OOC_Error_open(&_mid);
    OOC_OOC_Scanner_InputBuffer_open(&_mid);
    OOC_OOC_Scanner_open(&_mid);
    OOC_OOC_Scanner_SymList_open(&_mid);
    OOC_OOC_Parser_open(&_mid);
    OOC_OOC_AST_open(&_mid);
    OOC_OOC_SymbolTable_open(&_mid);
    OOC_OOC_SymbolTable_Builder_open(&_mid);
    OOC_OOC_SymbolTable_Uses_open(&_mid);
    OOC_OOC_AST_CreateSymTab_open(&_mid);
    OOC_OOC_SymbolTable_CreateNamespace_open(&_mid);
    OOC_OOC_Auxiliary_WriteSymbolFile_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OOC_Auxiliary_ParseModule_init();
  }
  _mid.openCount++;
}
extern void OOC_OOC_Auxiliary_ParseModule_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OOC_Auxiliary_ParseModule_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_IO_close(&_mid);
    OOC_URI_close(&_mid);
    OOC_OOC_Config_close(&_mid);
    OOC_OOC_Config_Pragmas_close(&_mid);
    OOC_OOC_Repository_close(&_mid);
    OOC_OOC_Error_close(&_mid);
    OOC_OOC_Scanner_InputBuffer_close(&_mid);
    OOC_OOC_Scanner_close(&_mid);
    OOC_OOC_Scanner_SymList_close(&_mid);
    OOC_OOC_Parser_close(&_mid);
    OOC_OOC_AST_close(&_mid);
    OOC_OOC_SymbolTable_close(&_mid);
    OOC_OOC_SymbolTable_Builder_close(&_mid);
    OOC_OOC_SymbolTable_Uses_close(&_mid);
    OOC_OOC_AST_CreateSymTab_close(&_mid);
    OOC_OOC_SymbolTable_CreateNamespace_close(&_mid);
    OOC_OOC_Auxiliary_WriteSymbolFile_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
