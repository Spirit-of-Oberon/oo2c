#include <OOC/AST/CreateSymTab.oh>
#include <Object.oh>
#include <Exception.oh>
#include <URI/Parser.oh>
#include <OOC/Scanner/Symbol.oh>
#include <OOC/Scanner/SymList.oh>
#include <OOC/SymbolTable/Predef.oh>
static OOC_SymbolTable__Position OOC_AST_CreateSymTab__GetPosition(OOC_AST__Node node);
static OOC_INT8 OOC_AST_CreateSymTab__ExportMark(OOC_AST__Node id);
static OOC_INT32 OOC_AST_CreateSymTab__EndOfType(OOC_AST__Node t);
static void OOC_AST_CreateSymTab__Accept(OOC_AST_CreateSymTab__Visitor v, OOC_AST__Node node);
static void OOC_AST_CreateSymTab__AcceptParent(OOC_AST_CreateSymTab__Visitor v, OOC_AST__Node node, OOC_SymbolTable__Item newParent);
static OOC_SymbolTable__Type OOC_AST_CreateSymTab__GetType(OOC_AST_CreateSymTab__Visitor v, OOC_AST__Node node);
static OOC_SymbolTable__Type OOC_AST_CreateSymTab__GetTypeParent(OOC_AST_CreateSymTab__Visitor v, OOC_AST__Node node, OOC_SymbolTable__Item newParent);
static void OOC_AST_CreateSymTab__AddFlags(OOC_SymbolTable__Item item, OOC_AST__Flags flags);
static void OOC_AST_CreateSymTab__ParseFormalParsFlags(OOC_SymbolTable__FormalPars fpars, OOC_AST__NodeList flags);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_AST_CreateSymTab__Visitor = { (RT0__Struct[]){&_td_OOC_AST_CreateSymTab__VisitorDesc}, NULL, NULL, &_mid, "Visitor", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_AST_CreateSymTab__VisitorDesc = { (RT0__Struct[]){&_td_OOC_AST__VisitorDesc,&_td_OOC_AST_CreateSymTab__VisitorDesc}, (void*[]){(void*)OOC_AST_CreateSymTab__VisitorDesc_VisitNodeList,(void*)OOC_AST_CreateSymTab__VisitorDesc_VisitTerminal,(void*)OOC_AST__VisitorDesc_VisitIdentDef,(void*)OOC_AST__VisitorDesc_VisitModuleIdent,(void*)OOC_AST_CreateSymTab__VisitorDesc_VisitArrayType,(void*)OOC_AST_CreateSymTab__VisitorDesc_VisitFieldList,(void*)OOC_AST_CreateSymTab__VisitorDesc_VisitRecordType,(void*)OOC_AST_CreateSymTab__VisitorDesc_VisitPointerType,(void*)OOC_AST_CreateSymTab__VisitorDesc_VisitFPSection,(void*)OOC_AST__VisitorDesc_VisitFormalPars,(void*)OOC_AST_CreateSymTab__VisitorDesc_VisitProcType,(void*)OOC_AST_CreateSymTab__VisitorDesc_VisitTPSection,(void*)OOC_AST__VisitorDesc_VisitTypePars,(void*)OOC_AST_CreateSymTab__VisitorDesc_VisitQualType,(void*)OOC_AST_CreateSymTab__VisitorDesc_VisitImportDecl,(void*)OOC_AST_CreateSymTab__VisitorDesc_VisitConstDecl,(void*)OOC_AST_CreateSymTab__VisitorDesc_VisitTypeDecl,(void*)OOC_AST_CreateSymTab__VisitorDesc_VisitVarDecl,(void*)OOC_AST_CreateSymTab__VisitorDesc_VisitReceiver,(void*)OOC_AST_CreateSymTab__VisitorDesc_VisitProcDecl,(void*)OOC_AST_CreateSymTab__VisitorDesc_VisitImportList,(void*)OOC_AST_CreateSymTab__VisitorDesc_VisitBody,(void*)OOC_AST_CreateSymTab__VisitorDesc_VisitModule,(void*)OOC_AST_CreateSymTab__VisitorDesc_VisitOperator,(void*)OOC_AST__VisitorDesc_VisitFactor,(void*)OOC_AST__VisitorDesc_VisitSet,(void*)OOC_AST__VisitorDesc_VisitArrayIndex,(void*)OOC_AST__VisitorDesc_VisitFunctionCall,(void*)OOC_AST__VisitorDesc_VisitAssignment,(void*)OOC_AST__VisitorDesc_VisitProcedureCall,(void*)OOC_AST__VisitorDesc_VisitIfStatm,(void*)OOC_AST__VisitorDesc_VisitCaseStatm,(void*)OOC_AST__VisitorDesc_VisitWhileStatm,(void*)OOC_AST__VisitorDesc_VisitRepeatStatm,(void*)OOC_AST__VisitorDesc_VisitForStatm,(void*)OOC_AST__VisitorDesc_VisitIterateStatm,(void*)OOC_AST__VisitorDesc_VisitLoopStatm,(void*)OOC_AST__VisitorDesc_VisitWithStatm,(void*)OOC_AST__VisitorDesc_VisitExitStatm,(void*)OOC_AST__VisitorDesc_VisitReturnStatm,(void*)OOC_AST__VisitorDesc_VisitCatch,(void*)OOC_AST__VisitorDesc_VisitTryStatm,(void*)OOC_AST__VisitorDesc_VisitFlags,(void*)OOC_AST__VisitorDesc_VisitProcIdFlag,(void*)OOC_AST__VisitorDesc_VisitModuleFlags,(void*)OOC_AST__VisitorDesc_VisitLinkFileFlag,(void*)OOC_AST__VisitorDesc_VisitLinkObjFlag,(void*)OOC_AST__VisitorDesc_VisitLinkLibFlag}, NULL, &_mid, "VisitorDesc", 24, 1, 0, RT0__strRecord };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:AST:CreateSymTab", (RT0__Struct[]) { &_td_OOC_AST_CreateSymTab__Visitor, &_td_OOC_AST_CreateSymTab__VisitorDesc, NULL } };

extern void OOC_OOC_AST_CreateSymTab_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_AST_CreateSymTab_init();
}

/* --- */
