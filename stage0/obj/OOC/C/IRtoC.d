#include <OOC/C/IRtoC.oh>
#include <Log.oh>
#include <Object/Boxed.oh>
#include <OOC/SymbolTable.oh>
#include <OOC/SymbolTable/Predef.oh>
#include <OOC/C/Naming.oh>
static void OOC_C_IRtoC__Call(OOC_C_DeclWriter__Writer w, OOC_IR__Call statm);
static void OOC_C_IRtoC__WriteExpr(OOC_C_DeclWriter__Writer w, OOC_IR__Expression expr);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_C_IRtoC__Translator = { (RT0__Struct[]){&_td_OOC_C_IRtoC__TranslatorDesc}, NULL, NULL, &_mid, "Translator", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_C_IRtoC__TranslatorDesc = { (RT0__Struct[]){&_td_OOC_Make_TranslateToC__TranslatorDesc,&_td_OOC_C_IRtoC__TranslatorDesc}, (void*[]){(void*)OOC_Make_TranslateToC__TranslatorDesc_SetWriter,(void*)OOC_Make_TranslateToC__TranslatorDesc_SetProcedureList,(void*)OOC_Make_TranslateToC__TranslatorDesc_SetDataWriter,(void*)OOC_C_IRtoC__TranslatorDesc_WriteProcBody,(void*)OOC_Make_TranslateToC__TranslatorDesc_WriteProcedure,(void*)OOC_Make_TranslateToC__TranslatorDesc_WriteNestedProcedures}, NULL, &_mid, "TranslatorDesc", 20, 1, 0, RT0__strRecord };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:C:IRtoC", (RT0__Struct[]) { &_td_OOC_C_IRtoC__Translator, &_td_OOC_C_IRtoC__TranslatorDesc, NULL } };

extern void OOC_OOC_C_IRtoC_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_C_IRtoC_init();
}

/* --- */
