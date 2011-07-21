static void* _c0;
static void* _c1;
#include <OOC/Make/TranslateToIA32.oh>
#include <Ascii.oh>
#include <IO/StdChannels.oh>
#include <OOC/Config/Pragmas.oh>
#include <OOC/Auxiliary/ParseModule.oh>
#include <OOC/Auxiliary/WriteSymbolFile.oh>
#include <OOC/AST.oh>
#include <OOC/AST/CreateIR.oh>
#include <OOC/AST/XML.oh>
#include <OOC/IR/XML.oh>
#include <OOC/IR/ConstFold.oh>
#include <OOC/SymbolTable/Exports.oh>
#include <OOC/IA32/RuntimeData.oh>
static void OOC_Make_TranslateToIA32__WriteCodeFile(OOC_IA32_Writer__Writer w, OOC_Repository__Module m, OOC_SymbolTable__Module symTab, OOC_IR__Module moduleIR, OOC_Make_TranslateToIA32__Translator translator);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_Make_TranslateToIA32__Translator = { (RT0__Struct[]){&_td_OOC_Make_TranslateToIA32__TranslatorDesc}, NULL, NULL, &_mid, "Translator", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Make_TranslateToIA32__TranslatorDesc = { (RT0__Struct[]){&_td_OOC_Make_TranslateToIA32__TranslatorDesc}, (void*[]){(void*)OOC_Make_TranslateToIA32__TranslatorDesc_SetWriter,(void*)OOC_Make_TranslateToIA32__TranslatorDesc_SetProcedureList,(void*)OOC_Make_TranslateToIA32__TranslatorDesc_WriteProcBody,(void*)OOC_Make_TranslateToIA32__TranslatorDesc_WriteProcedure,(void*)OOC_Make_TranslateToIA32__TranslatorDesc_WriteNestedProcedures}, NULL, &_mid, "TranslatorDesc", 20, 0, 0, RT0__strRecord };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:Make:TranslateToIA32", (RT0__Struct[]) { &_td_OOC_Make_TranslateToIA32__Translator, &_td_OOC_Make_TranslateToIA32__TranslatorDesc, NULL } };

extern void OOC_OOC_Make_TranslateToIA32_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_Make_TranslateToIA32_init();
}

/* --- */
