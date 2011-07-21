#include <OOC/Make/TranslateToC.oh>
#include <IO/StdChannels.oh>
#include <OOC/Config.oh>
#include <OOC/Config/Pragmas.oh>
#include <OOC/Auxiliary/ParseModule.oh>
#include <OOC/Auxiliary/WriteSymbolFile.oh>
#include <OOC/AST.oh>
#include <OOC/AST/CreateIR.oh>
#include <OOC/AST/XML.oh>
#include <OOC/IR/XML.oh>
#include <OOC/IR/ConstFold.oh>
#include <OOC/IR/CheckUses.oh>
#include <OOC/SymbolTable.oh>
#include <OOC/SymbolTable/Exports.oh>
#include <OOC/C/ConvertDecl.oh>
#include <OOC/C/RuntimeData.oh>
static void OOC_Make_TranslateToC__WriteModuleName(OOC_C_DeclWriter__Writer w, const OOC_CHAR8 prefix__ref[], OOC_LEN prefix_0d, OOC_Repository__Module module, const OOC_CHAR8 suffix__ref[], OOC_LEN suffix_0d, OOC_CHAR8 newline);
static void OOC_Make_TranslateToC__WriteHeaderFile(OOC_C_DeclWriter__Writer w, OOC_Repository__Module m, OOC_SymbolTable__Module symTab, ADT_Dictionary_AddressKey__Dictionary exports, OOC_C_Naming__QualTypeData qtdData);
static void OOC_Make_TranslateToC__WriteDeclFile(OOC_C_DeclWriter__Writer w, OOC_Repository__Module m, OOC_SymbolTable__Module symTab, ADT_Dictionary_AddressKey__Dictionary exports, OOC_C_Naming__QualTypeData qtdData);
static void OOC_Make_TranslateToC__WriteCodeFile(OOC_C_DeclWriter__Writer w, OOC_C_DeclWriter__Writer wd, OOC_Repository__Module m, OOC_IR__Module moduleIR, OOC_Make_TranslateToC__Translator translator);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_Make_TranslateToC__Translator = { (RT0__Struct[]){&_td_OOC_Make_TranslateToC__TranslatorDesc}, NULL, NULL, &_mid, "Translator", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Make_TranslateToC__TranslatorDesc = { (RT0__Struct[]){&_td_OOC_Make_TranslateToC__TranslatorDesc}, (void*[]){(void*)OOC_Make_TranslateToC__TranslatorDesc_SetWriter,(void*)OOC_Make_TranslateToC__TranslatorDesc_SetProcedureList,(void*)OOC_Make_TranslateToC__TranslatorDesc_SetDataWriter,(void*)OOC_Make_TranslateToC__TranslatorDesc_WriteProcBody,(void*)OOC_Make_TranslateToC__TranslatorDesc_WriteProcedure,(void*)OOC_Make_TranslateToC__TranslatorDesc_WriteNestedProcedures}, NULL, &_mid, "TranslatorDesc", 20, 0, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_Make_TranslateToC__4457 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_Make_TranslateToC__4534 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_Make_TranslateToC__4583 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1024, 1024, (1<<RT0__flagAtomic), RT0__strArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:Make:TranslateToC", (RT0__Struct[]) { &_td_OOC_Make_TranslateToC__Translator, &_td_OOC_Make_TranslateToC__TranslatorDesc, NULL }, 0 };

extern void OOC_OOC_Make_TranslateToC_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_IO_open(&_mid);
    OOC_IO_StdChannels_open(&_mid);
    OOC_OOC_Config_open(&_mid);
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
    OOC_OOC_C_DeclWriter_open(&_mid);
    OOC_OOC_C_ConvertDecl_open(&_mid);
    OOC_OOC_C_RuntimeData_open(&_mid);
    OOC_OOC_C_Naming_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OOC_Make_TranslateToC_init();
  }
  _mid.openCount++;
}
extern void OOC_OOC_Make_TranslateToC_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OOC_Make_TranslateToC_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_IO_close(&_mid);
    OOC_IO_StdChannels_close(&_mid);
    OOC_OOC_Config_close(&_mid);
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
    OOC_OOC_C_DeclWriter_close(&_mid);
    OOC_OOC_C_ConvertDecl_close(&_mid);
    OOC_OOC_C_RuntimeData_close(&_mid);
    OOC_OOC_C_Naming_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
