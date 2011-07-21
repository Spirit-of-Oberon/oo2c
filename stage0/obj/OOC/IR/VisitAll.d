#include <OOC/IR/VisitAll.oh>
static void OOC_IR_VisitAll__VisitStatementSeq(OOC_IR_VisitAll__Visitor v, OOC_IR__StatementSeq statmSeq);
static void OOC_IR_VisitAll__VisitProcedureList(OOC_IR_VisitAll__Visitor v, OOC_IR__ProcedureList procList);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_IR_VisitAll__Visitor = { (RT0__Struct[]){&_td_OOC_IR_VisitAll__VisitorDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"Visitor", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_IR_VisitAll__VisitorDesc = { (RT0__Struct[]){&_td_OOC_IR__VisitorDesc,&_td_OOC_IR_VisitAll__VisitorDesc}, (void*[]){(void*)OOC_IR_VisitAll__VisitorDesc_VisitConst,(void*)OOC_IR_VisitAll__VisitorDesc_VisitAbs,(void*)OOC_IR_VisitAll__VisitorDesc_VisitAdr,(void*)OOC_IR_VisitAll__VisitorDesc_VisitAsh,(void*)OOC_IR_VisitAll__VisitorDesc_VisitBinaryArith,(void*)OOC_IR_VisitAll__VisitorDesc_VisitBooleanOp,(void*)OOC_IR_VisitAll__VisitorDesc_VisitCap,(void*)OOC_IR_VisitAll__VisitorDesc_VisitChangeElement,(void*)OOC_IR_VisitAll__VisitorDesc_VisitCompare,(void*)OOC_IR_VisitAll__VisitorDesc_VisitConcat,(void*)OOC_IR_VisitAll__VisitorDesc_VisitConstructor,(void*)OOC_IR_VisitAll__VisitorDesc_VisitCurrentException,(void*)OOC_IR_VisitAll__VisitorDesc_VisitDeref,(void*)OOC_IR_VisitAll__VisitorDesc_VisitEntier,(void*)OOC_IR_VisitAll__VisitorDesc_VisitIndex,(void*)OOC_IR_VisitAll__VisitorDesc_VisitLen,(void*)OOC_IR_VisitAll__VisitorDesc_VisitNegate,(void*)OOC_IR_VisitAll__VisitorDesc_VisitNewBlock,(void*)OOC_IR_VisitAll__VisitorDesc_VisitNewObject,(void*)OOC_IR_VisitAll__VisitorDesc_VisitNot,(void*)OOC_IR_VisitAll__VisitorDesc_VisitOdd,(void*)OOC_IR_VisitAll__VisitorDesc_VisitSelectField,(void*)OOC_IR_VisitAll__VisitorDesc_VisitSelectProc,(void*)OOC_IR_VisitAll__VisitorDesc_VisitSetMember,(void*)OOC_IR_VisitAll__VisitorDesc_VisitSetOp,(void*)OOC_IR_VisitAll__VisitorDesc_VisitSetRange,(void*)OOC_IR_VisitAll__VisitorDesc_VisitShift,(void*)OOC_IR_VisitAll__VisitorDesc_VisitTypeCast,(void*)OOC_IR_VisitAll__VisitorDesc_VisitTypeConv,(void*)OOC_IR_VisitAll__VisitorDesc_VisitTypeTag,(void*)OOC_IR_VisitAll__VisitorDesc_VisitTypeTest,(void*)OOC_IR_VisitAll__VisitorDesc_VisitTypeGuard,(void*)OOC_IR_VisitAll__VisitorDesc_VisitModuleRef,(void*)OOC_IR_VisitAll__VisitorDesc_VisitPredefProc,(void*)OOC_IR_VisitAll__VisitorDesc_VisitProcedureRef,(void*)OOC_IR_VisitAll__VisitorDesc_VisitTypeRef,(void*)OOC_IR_VisitAll__VisitorDesc_VisitVar,(void*)OOC_IR_VisitAll__VisitorDesc_VisitAssert,(void*)OOC_IR_VisitAll__VisitorDesc_VisitAssignment,(void*)OOC_IR_VisitAll__VisitorDesc_VisitAssignOp,(void*)OOC_IR_VisitAll__VisitorDesc_VisitCall,(void*)OOC_IR_VisitAll__VisitorDesc_VisitCopy,(void*)OOC_IR_VisitAll__VisitorDesc_VisitCopyParameter,(void*)OOC_IR_VisitAll__VisitorDesc_VisitCopyString,(void*)OOC_IR_VisitAll__VisitorDesc_VisitExit,(void*)OOC_IR_VisitAll__VisitorDesc_VisitForStatm,(void*)OOC_IR_VisitAll__VisitorDesc_VisitIterateArrayStatm,(void*)OOC_IR_VisitAll__VisitorDesc_VisitIterateObjectStatm,(void*)OOC_IR_VisitAll__VisitorDesc_VisitIfStatm,(void*)OOC_IR_VisitAll__VisitorDesc_VisitCase,(void*)OOC_IR_VisitAll__VisitorDesc_VisitCaseStatm,(void*)OOC_IR_VisitAll__VisitorDesc_VisitLoopStatm,(void*)OOC_IR_VisitAll__VisitorDesc_VisitMoveBlock,(void*)OOC_IR_VisitAll__VisitorDesc_VisitRaise,(void*)OOC_IR_VisitAll__VisitorDesc_VisitRepeatStatm,(void*)OOC_IR_VisitAll__VisitorDesc_VisitReturn,(void*)OOC_IR_VisitAll__VisitorDesc_VisitCatchClause,(void*)OOC_IR_VisitAll__VisitorDesc_VisitTryStatm,(void*)OOC_IR_VisitAll__VisitorDesc_VisitWhileStatm,(void*)OOC_IR_VisitAll__VisitorDesc_VisitWithStatm,(void*)OOC_IR_VisitAll__VisitorDesc_VisitProcedure,(void*)OOC_IR_VisitAll__VisitorDesc_VisitModule}, NULL, &_mid, (OOC_CHAR8*)"VisitorDesc", 0, 1, (1<<RT0__flagAtomic), RT0__strRecord };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:IR:VisitAll", (RT0__Struct[]) { &_td_OOC_IR_VisitAll__Visitor, &_td_OOC_IR_VisitAll__VisitorDesc, NULL }, 0 };

extern void OOC_OOC_IR_VisitAll_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_OOC_IR_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OOC_IR_VisitAll_init();
  }
  _mid.openCount++;
}
extern void OOC_OOC_IR_VisitAll_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OOC_IR_VisitAll_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_OOC_IR_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
