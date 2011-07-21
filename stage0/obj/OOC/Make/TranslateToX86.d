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
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:Make:TranslateToX86", (RT0__Struct[]) { NULL }, 0 };

extern void OOC_OOC_Make_TranslateToX86_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_IO_open(&_mid);
    OOC_IO_StdChannels_open(&_mid);
    OOC_OOC_Config_Pragmas_open(&_mid);
    OOC_OOC_Auxiliary_ParseModule_open(&_mid);
    OOC_OOC_Auxiliary_WriteSymbolFile_open(&_mid);
    OOC_OOC_Error_open(&_mid);
    OOC_OOC_Repository_open(&_mid);
    OOC_OOC_AST_open(&_mid);
    OOC_OOC_AST_CreateIR_open(&_mid);
    OOC_OOC_AST_XML_open(&_mid);
    OOC_OOC_IR_open(&_mid);
    OOC_OOC_IR_XML_open(&_mid);
    OOC_OOC_IR_ConstFold_open(&_mid);
    OOC_OOC_IR_CheckUses_open(&_mid);
    OOC_OOC_SymbolTable_open(&_mid);
    OOC_OOC_SymbolTable_Exports_open(&_mid);
    OOC_OOC_SymbolTable_Uses_open(&_mid);
    OOC_OOC_X86_Translate_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OOC_Make_TranslateToX86_init();
  }
  _mid.openCount++;
}
extern void OOC_OOC_Make_TranslateToX86_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OOC_Make_TranslateToX86_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_IO_close(&_mid);
    OOC_IO_StdChannels_close(&_mid);
    OOC_OOC_Config_Pragmas_close(&_mid);
    OOC_OOC_Auxiliary_ParseModule_close(&_mid);
    OOC_OOC_Auxiliary_WriteSymbolFile_close(&_mid);
    OOC_OOC_Error_close(&_mid);
    OOC_OOC_Repository_close(&_mid);
    OOC_OOC_AST_close(&_mid);
    OOC_OOC_AST_CreateIR_close(&_mid);
    OOC_OOC_AST_XML_close(&_mid);
    OOC_OOC_IR_close(&_mid);
    OOC_OOC_IR_XML_close(&_mid);
    OOC_OOC_IR_ConstFold_close(&_mid);
    OOC_OOC_IR_CheckUses_close(&_mid);
    OOC_OOC_SymbolTable_close(&_mid);
    OOC_OOC_SymbolTable_Exports_close(&_mid);
    OOC_OOC_SymbolTable_Uses_close(&_mid);
    OOC_OOC_X86_Translate_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
