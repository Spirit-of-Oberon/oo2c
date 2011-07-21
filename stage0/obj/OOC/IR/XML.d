#include <OOC/IR/XML.oh>
#include <Object.oh>
#include <XML/UnicodeCodec/Latin1.oh>
#include <OOC/SymbolTable.oh>
static void OOC_IR_XML__InitVisitor(OOC_IR_XML__Visitor v, XML_Writer__Writer w);
static OOC_IR_XML__Visitor OOC_IR_XML__NewVisitor(XML_Writer__Writer w);
static void OOC_IR_XML__TypeAttr(XML_Writer__Writer w, OOC_SymbolTable__Type type);
static void OOC_IR_XML__VisitDyadicOp(OOC_IR_XML__Visitor v, OOC_IR__Operator op, OOC_INT8 variant, OOC_IR__Expression left, OOC_IR__Expression right, const OOC_CHAR8 name__ref[], OOC_LEN name_0d);
static void OOC_IR_XML__VisitStatementSeq(OOC_IR_XML__Visitor v, OOC_IR__StatementSeq statmSeq);
static void OOC_IR_XML__VisitProcedureList(OOC_IR_XML__Visitor v, OOC_IR__ProcedureList procList);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_IR_XML__Visitor = { (RT0__Struct[]){&_td_OOC_IR_XML__VisitorDesc}, NULL, NULL, &_mid, "Visitor", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_IR_XML__VisitorDesc = { (RT0__Struct[]){&_td_OOC_IR__VisitorDesc,&_td_OOC_IR_XML__VisitorDesc}, (void*[]){(void*)OOC_IR_XML__VisitorDesc_VisitConst,(void*)OOC_IR_XML__VisitorDesc_VisitAbs,(void*)OOC_IR_XML__VisitorDesc_VisitAdr,(void*)OOC_IR_XML__VisitorDesc_VisitAsh,(void*)OOC_IR_XML__VisitorDesc_VisitBinaryArith,(void*)OOC_IR_XML__VisitorDesc_VisitBooleanOp,(void*)OOC_IR_XML__VisitorDesc_VisitCap,(void*)OOC_IR_XML__VisitorDesc_VisitChangeElement,(void*)OOC_IR_XML__VisitorDesc_VisitCompare,(void*)OOC_IR_XML__VisitorDesc_VisitConcat,(void*)OOC_IR_XML__VisitorDesc_VisitConstructor,(void*)OOC_IR_XML__VisitorDesc_VisitCurrentException,(void*)OOC_IR_XML__VisitorDesc_VisitDeref,(void*)OOC_IR_XML__VisitorDesc_VisitEntier,(void*)OOC_IR_XML__VisitorDesc_VisitIndex,(void*)OOC_IR_XML__VisitorDesc_VisitLen,(void*)OOC_IR_XML__VisitorDesc_VisitNegate,(void*)OOC_IR_XML__VisitorDesc_VisitNewBlock,(void*)OOC_IR_XML__VisitorDesc_VisitNewObject,(void*)OOC_IR_XML__VisitorDesc_VisitNot,(void*)OOC_IR_XML__VisitorDesc_VisitOdd,(void*)OOC_IR_XML__VisitorDesc_VisitSelectField,(void*)OOC_IR_XML__VisitorDesc_VisitSelectProc,(void*)OOC_IR_XML__VisitorDesc_VisitSetMember,(void*)OOC_IR_XML__VisitorDesc_VisitSetOp,(void*)OOC_IR_XML__VisitorDesc_VisitSetRange,(void*)OOC_IR_XML__VisitorDesc_VisitShift,(void*)OOC_IR_XML__VisitorDesc_VisitTypeCast,(void*)OOC_IR_XML__VisitorDesc_VisitTypeConv,(void*)OOC_IR_XML__VisitorDesc_VisitTypeTag,(void*)OOC_IR_XML__VisitorDesc_VisitTypeTest,(void*)OOC_IR_XML__VisitorDesc_VisitTypeGuard,(void*)OOC_IR_XML__VisitorDesc_VisitModuleRef,(void*)OOC_IR_XML__VisitorDesc_VisitPredefProc,(void*)OOC_IR_XML__VisitorDesc_VisitProcedureRef,(void*)OOC_IR_XML__VisitorDesc_VisitTypeRef,(void*)OOC_IR_XML__VisitorDesc_VisitVar,(void*)OOC_IR_XML__VisitorDesc_VisitAssert,(void*)OOC_IR_XML__VisitorDesc_VisitAssignment,(void*)OOC_IR_XML__VisitorDesc_VisitAssignOp,(void*)OOC_IR_XML__VisitorDesc_VisitCall,(void*)OOC_IR_XML__VisitorDesc_VisitCopy,(void*)OOC_IR_XML__VisitorDesc_VisitCopyParameter,(void*)OOC_IR_XML__VisitorDesc_VisitCopyString,(void*)OOC_IR_XML__VisitorDesc_VisitExit,(void*)OOC_IR_XML__VisitorDesc_VisitForStatm,(void*)OOC_IR_XML__VisitorDesc_VisitIterateArrayStatm,(void*)OOC_IR_XML__VisitorDesc_VisitIterateObjectStatm,(void*)OOC_IR_XML__VisitorDesc_VisitIfStatm,(void*)OOC_IR_XML__VisitorDesc_VisitCase,(void*)OOC_IR_XML__VisitorDesc_VisitCaseStatm,(void*)OOC_IR_XML__VisitorDesc_VisitLoopStatm,(void*)OOC_IR_XML__VisitorDesc_VisitMoveBlock,(void*)OOC_IR_XML__VisitorDesc_VisitRaise,(void*)OOC_IR_XML__VisitorDesc_VisitRepeatStatm,(void*)OOC_IR_XML__VisitorDesc_VisitReturn,(void*)OOC_IR_XML__VisitorDesc_VisitCatchClause,(void*)OOC_IR_XML__VisitorDesc_VisitTryStatm,(void*)OOC_IR_XML__VisitorDesc_VisitWhileStatm,(void*)OOC_IR_XML__VisitorDesc_VisitWithStatm,(void*)OOC_IR_XML__VisitorDesc_VisitProcedure,(void*)OOC_IR_XML__VisitorDesc_VisitModule}, NULL, &_mid, "VisitorDesc", 4, 1, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_IR_XML__3484 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 32, 32, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_IR_XML__7877 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:IR:XML", (RT0__Struct[]) { &_td_OOC_IR_XML__Visitor, &_td_OOC_IR_XML__VisitorDesc, NULL } };

extern void OOC_OOC_IR_XML_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_IR_XML_init();
}

/* --- */
