#include <OOC/SSA/WriteC.oh>
#include <IntStr.oh>
#include <Err.oh>
#include <Out.oh>
#include <Strings.oh>
#include <IO.oh>
#include <IO/StdChannels.oh>
#include <Object.oh>
#include <Object/Boxed.oh>
#include <OOC/SymbolTable/TypeRules.oh>
#include <OOC/SymbolTable/Predef.oh>
#include <OOC/SymbolTable/Builder.oh>
#include <OOC/SSA/Opcode.oh>
#include <OOC/SSA/Opnd.oh>
#include <OOC/SSA/IRtoSSA.oh>
#include <OOC/SSA/XML.oh>
#include <OOC/SSA/DeadCodeElimination.oh>
#include <OOC/SSA/Destore.oh>
#include <OOC/SSA/CSE.oh>
#include <OOC/SSA/Algebraic.oh>
#include <OOC/SSA/ConstProp.oh>
#include <OOC/SSA/LoopRewrite.oh>
#include <OOC/SSA/PRE.oh>
#include <OOC/SSA/Stats.oh>
#include <OOC/SSA/Allocator.oh>
#include <OOC/C/ConvertDecl.oh>
#include <OOC/C/Naming.oh>
#include <OOC/SSA/Blocker.oh>
#define OOC_SSA_WriteC__enableLoopRewriting OOC_TRUE
#define OOC_SSA_WriteC__enableDebugOutput OOC_FALSE
#define OOC_SSA_WriteC__prefixPreloadVar (OOC_CHAR8[])"_c"
static OOC_SSA_WriteC__Visitor OOC_SSA_WriteC__NewVisitor(void);
static OOC_INT8 OOC_SSA_WriteC__SubclassToBasicType(OOC_SSA__Result res);
static OOC_SSA_WriteC__Writer OOC_SSA_WriteC__NewWriter(OOC_SSA_WriteC__Translator translator, OOC_C_DeclWriter__Writer cWriter, OOC_SSA__ProcBlock procBlock, ADT_Dictionary__Dictionary registerMap, ADT_Dictionary__Dictionary jmpbufMap);
static void OOC_SSA_WriteC__Fixup(OOC_SSA__ProcBlock pb, ADT_Dictionary__Dictionary *jmpbufMap);
static void OOC_SSA_WriteC__WriteTypeCast(OOC_C_DeclWriter__Writer w, OOC_INT8 ctype);
static void OOC_SSA_WriteC__WriteTypeAndLength(OOC_SSA_WriteC__Writer w, OOC_SSA__Instr instr, OOC_SymbolTable__VarDecl varDecl, OOC_CHAR8 inBytes);
static void OOC_SSA_WriteC__WriteLocalDecl(OOC_SSA_WriteC__Translator t, OOC_SSA_WriteC__Writer w, OOC_SSA__ProcBlock pb, OOC_CHAR8 _volatile);
static void OOC_SSA_WriteC__CastToPtr(OOC_SSA_WriteC__Writer w, OOC_SSA__Result var, OOC_SymbolTable__Type type, OOC_CHAR8 passByReference);
static OOC_INT32 OOC_SSA_WriteC__GetPreloadId(ADT_Dictionary_IntValue__Dictionary preloadedVars, OOC_SSA__Instr instr);
static Object__Object OOC_SSA_WriteC__WriteExceptionContext(OOC_SSA_WriteC__Writer w, OOC_SSA__Instr instr);
static void OOC_SSA_WriteC__WriteExpr(OOC_SSA_WriteC__Writer w, OOC_SSA__Instr instr);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_SSA_WriteC__RegisterSwap = { (RT0__Struct[]){&_td_OOC_SSA_WriteC__RegisterSwap}, (void*[]){}, NULL, &_mid, (OOC_CHAR8*)"RegisterSwap", 16, 0, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_SSA_WriteC__1847 = { (RT0__Struct[]){&_td_OOC_SSA_WriteC__RegisterSwap}, NULL, NULL, &_mid, NULL, 16, 1, 0, RT0__strOpenArray };
RT0__StructDesc _td_OOC_SSA_WriteC__SwapArray = { (RT0__Struct[]){&_td_OOC_SSA_WriteC__1847}, NULL, NULL, &_mid, (OOC_CHAR8*)"SwapArray", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_WriteC__Translator = { (RT0__Struct[]){&_td_OOC_SSA_WriteC__TranslatorDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"Translator", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_WriteC__TranslatorDesc = { (RT0__Struct[]){&_td_OOC_Make_TranslateToC__TranslatorDesc,&_td_OOC_SSA_WriteC__TranslatorDesc}, (void*[]){(void*)OOC_Make_TranslateToC__TranslatorDesc_SetWriter,(void*)OOC_SSA_WriteC__TranslatorDesc_SetProcedureList,(void*)OOC_Make_TranslateToC__TranslatorDesc_SetDataWriter,(void*)OOC_SSA_WriteC__TranslatorDesc_WriteProcBody,(void*)OOC_Make_TranslateToC__TranslatorDesc_WriteProcedure,(void*)OOC_Make_TranslateToC__TranslatorDesc_WriteNestedProcedures}, NULL, &_mid, (OOC_CHAR8*)"TranslatorDesc", 40, 1, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_SSA_WriteC__Writer = { (RT0__Struct[]){&_td_OOC_SSA_WriteC__WriterDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"Writer", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_WriteC__WriterDesc = { (RT0__Struct[]){&_td_OOC_C_DeclWriter__WriterDesc,&_td_OOC_SSA_WriteC__WriterDesc}, (void*[]){(void*)OOC_C_DeclWriter__WriterDesc_CopyTo,(void*)OOC_C_DeclWriter__WriterDesc_WriteString,(void*)OOC_C_DeclWriter__WriterDesc_WriteObject,(void*)OOC_C_DeclWriter__WriterDesc_WriteChar,(void*)OOC_C_DeclWriter__WriterDesc_WriteLn,(void*)OOC_C_DeclWriter__WriterDesc_WriteLInt,(void*)OOC_C_DeclWriter__WriterDesc_Indent,(void*)OOC_C_DeclWriter__WriterDesc_Newline,(void*)OOC_C_DeclWriter__WriterDesc_WriteInclude,(void*)OOC_C_DeclWriter__WriterDesc_Close,(void*)OOC_C_DeclWriter__WriterDesc_WriteConst,(void*)OOC_C_DeclWriter__WriterDesc_WriteBasicConst,(void*)OOC_C_DeclWriter__WriterDesc_WriteStringConst,(void*)OOC_C_DeclWriter__WriterDesc_WriteDeclaration,(void*)OOC_C_DeclWriter__WriterDesc_AddDeclaration,(void*)OOC_C_DeclWriter__WriterDesc_WriteDeclarationList,(void*)OOC_C_DeclWriter__WriterDesc_NewPointer,(void*)OOC_C_DeclWriter__WriterDesc_NewArray,(void*)OOC_C_DeclWriter__WriterDesc_NewFunction,(void*)OOC_C_DeclWriter__WriterDesc_NewStruct,(void*)OOC_C_DeclWriter__WriterDesc_NewTypeRef,(void*)OOC_C_DeclWriter__WriterDesc_NewTypeOf,(void*)OOC_C_DeclWriter__WriterDesc_WriteType,(void*)OOC_C_DeclWriter__WriterDesc_NewDeclaration,(void*)OOC_C_DeclWriter__WriterDesc_NewIncludeModule,(void*)OOC_C_DeclWriter__WriterDesc_WriteModuleInclude,(void*)OOC_C_DeclWriter__WriterDesc_NewDefine,(void*)OOC_C_DeclWriter__WriterDesc_WriteTypeCast,(void*)OOC_SSA_WriteC__WriterDesc_ClearSwapData,(void*)OOC_SSA_WriteC__WriterDesc_AddSwapData,(void*)OOC_SSA_WriteC__WriterDesc_CountReadsSwapData,(void*)OOC_SSA_WriteC__WriterDesc_RemoveSwapData,(void*)OOC_SSA_WriteC__WriterDesc_IntroduceHelperVar,(void*)OOC_SSA_WriteC__WriterDesc_FixupHelperVars,(void*)OOC_SSA_WriteC__WriterDesc_LengthExprHeap,(void*)OOC_SSA_WriteC__WriterDesc_LengthExprParam,(void*)OOC_SSA_WriteC__WriterDesc_Ref,(void*)OOC_SSA_WriteC__WriterDesc_TypeRef,(void*)OOC_SSA_WriteC__WriterDesc_Noop,(void*)OOC_SSA_WriteC__WriterDesc_EmptyBlock,(void*)OOC_SSA_WriteC__WriterDesc_WriteInstrList,(void*)OOC_SSA_WriteC__WriterDesc_WriteBlocks}, NULL, &_mid, (OOC_CHAR8*)"WriterDesc", 120, 1, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_SSA_WriteC__Visitor = { (RT0__Struct[]){&_td_OOC_SSA_WriteC__VisitorDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"Visitor", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_WriteC__VisitorDesc = { (RT0__Struct[]){&_td_OOC_IR__VisitorDesc,&_td_OOC_IR_VisitAll__VisitorDesc,&_td_OOC_SSA_WriteC__VisitorDesc}, (void*[]){(void*)OOC_IR_VisitAll__VisitorDesc_VisitConst,(void*)OOC_IR_VisitAll__VisitorDesc_VisitAbs,(void*)OOC_IR_VisitAll__VisitorDesc_VisitAdr,(void*)OOC_IR_VisitAll__VisitorDesc_VisitAsh,(void*)OOC_IR_VisitAll__VisitorDesc_VisitBinaryArith,(void*)OOC_IR_VisitAll__VisitorDesc_VisitBooleanOp,(void*)OOC_IR_VisitAll__VisitorDesc_VisitCap,(void*)OOC_IR_VisitAll__VisitorDesc_VisitChangeElement,(void*)OOC_IR_VisitAll__VisitorDesc_VisitCompare,(void*)OOC_IR_VisitAll__VisitorDesc_VisitConcat,(void*)OOC_IR_VisitAll__VisitorDesc_VisitConstructor,(void*)OOC_IR_VisitAll__VisitorDesc_VisitCurrentException,(void*)OOC_IR_VisitAll__VisitorDesc_VisitDeref,(void*)OOC_IR_VisitAll__VisitorDesc_VisitEntier,(void*)OOC_IR_VisitAll__VisitorDesc_VisitIndex,(void*)OOC_IR_VisitAll__VisitorDesc_VisitLen,(void*)OOC_IR_VisitAll__VisitorDesc_VisitNegate,(void*)OOC_IR_VisitAll__VisitorDesc_VisitNewBlock,(void*)OOC_IR_VisitAll__VisitorDesc_VisitNewObject,(void*)OOC_IR_VisitAll__VisitorDesc_VisitNot,(void*)OOC_IR_VisitAll__VisitorDesc_VisitOdd,(void*)OOC_IR_VisitAll__VisitorDesc_VisitSelectField,(void*)OOC_IR_VisitAll__VisitorDesc_VisitSelectProc,(void*)OOC_IR_VisitAll__VisitorDesc_VisitSetMember,(void*)OOC_IR_VisitAll__VisitorDesc_VisitSetOp,(void*)OOC_IR_VisitAll__VisitorDesc_VisitSetRange,(void*)OOC_IR_VisitAll__VisitorDesc_VisitShift,(void*)OOC_IR_VisitAll__VisitorDesc_VisitTypeCast,(void*)OOC_IR_VisitAll__VisitorDesc_VisitTypeConv,(void*)OOC_IR_VisitAll__VisitorDesc_VisitTypeTag,(void*)OOC_IR_VisitAll__VisitorDesc_VisitTypeTest,(void*)OOC_IR_VisitAll__VisitorDesc_VisitTypeGuard,(void*)OOC_IR_VisitAll__VisitorDesc_VisitModuleRef,(void*)OOC_IR_VisitAll__VisitorDesc_VisitPredefProc,(void*)OOC_IR_VisitAll__VisitorDesc_VisitProcedureRef,(void*)OOC_IR_VisitAll__VisitorDesc_VisitTypeRef,(void*)OOC_SSA_WriteC__VisitorDesc_VisitVar,(void*)OOC_IR_VisitAll__VisitorDesc_VisitAssert,(void*)OOC_IR_VisitAll__VisitorDesc_VisitAssignment,(void*)OOC_IR_VisitAll__VisitorDesc_VisitAssignOp,(void*)OOC_IR_VisitAll__VisitorDesc_VisitCall,(void*)OOC_IR_VisitAll__VisitorDesc_VisitCopy,(void*)OOC_IR_VisitAll__VisitorDesc_VisitCopyParameter,(void*)OOC_IR_VisitAll__VisitorDesc_VisitCopyString,(void*)OOC_IR_VisitAll__VisitorDesc_VisitExit,(void*)OOC_IR_VisitAll__VisitorDesc_VisitForStatm,(void*)OOC_IR_VisitAll__VisitorDesc_VisitIterateArrayStatm,(void*)OOC_IR_VisitAll__VisitorDesc_VisitIterateObjectStatm,(void*)OOC_IR_VisitAll__VisitorDesc_VisitIfStatm,(void*)OOC_IR_VisitAll__VisitorDesc_VisitCase,(void*)OOC_IR_VisitAll__VisitorDesc_VisitCaseStatm,(void*)OOC_IR_VisitAll__VisitorDesc_VisitLoopStatm,(void*)OOC_IR_VisitAll__VisitorDesc_VisitMoveBlock,(void*)OOC_IR_VisitAll__VisitorDesc_VisitRaise,(void*)OOC_IR_VisitAll__VisitorDesc_VisitRepeatStatm,(void*)OOC_IR_VisitAll__VisitorDesc_VisitReturn,(void*)OOC_IR_VisitAll__VisitorDesc_VisitCatchClause,(void*)OOC_IR_VisitAll__VisitorDesc_VisitTryStatm,(void*)OOC_IR_VisitAll__VisitorDesc_VisitWhileStatm,(void*)OOC_IR_VisitAll__VisitorDesc_VisitWithStatm,(void*)OOC_SSA_WriteC__VisitorDesc_VisitProcedure,(void*)OOC_IR_VisitAll__VisitorDesc_VisitModule}, NULL, &_mid, (OOC_CHAR8*)"VisitorDesc", 8, 2, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_SSA_WriteC__6084 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 16, 16, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_SSA_WriteC__7124 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 16, 16, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_SSA_WriteC__23188 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_SSA_WriteC__24786 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_SSA_WriteC__24989 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_SSA_WriteC__26000 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_SSA_WriteC__26293 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_SSA_WriteC__41455 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 32, 32, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_SSA_WriteC__54173 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:SSA:WriteC", (RT0__Struct[]) { &_td_OOC_SSA_WriteC__RegisterSwap, &_td_OOC_SSA_WriteC__SwapArray, &_td_OOC_SSA_WriteC__Translator, &_td_OOC_SSA_WriteC__TranslatorDesc, &_td_OOC_SSA_WriteC__Writer, &_td_OOC_SSA_WriteC__WriterDesc, &_td_OOC_SSA_WriteC__Visitor, &_td_OOC_SSA_WriteC__VisitorDesc, NULL }, 0 };

extern void OOC_OOC_SSA_WriteC_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_IntStr_open(&_mid);
    OOC_Err_open(&_mid);
    OOC_Out_open(&_mid);
    OOC_Strings_open(&_mid);
    OOC_StringSearch_open(&_mid);
    OOC_IO_open(&_mid);
    OOC_IO_StdChannels_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Object_Boxed_open(&_mid);
    OOC_ADT_Dictionary_open(&_mid);
    OOC_ADT_Dictionary_IntValue_open(&_mid);
    OOC_OOC_SymbolTable_open(&_mid);
    OOC_OOC_SymbolTable_TypeRules_open(&_mid);
    OOC_OOC_SymbolTable_Predef_open(&_mid);
    OOC_OOC_SymbolTable_Builder_open(&_mid);
    OOC_OOC_IR_open(&_mid);
    OOC_OOC_IR_VisitAll_open(&_mid);
    OOC_OOC_SSA_Opcode_open(&_mid);
    OOC_OOC_SSA_Opnd_open(&_mid);
    OOC_OOC_SSA_open(&_mid);
    OOC_OOC_SSA_IRtoSSA_open(&_mid);
    OOC_OOC_SSA_Schedule_open(&_mid);
    OOC_OOC_SSA_XML_open(&_mid);
    OOC_OOC_SSA_DeadCodeElimination_open(&_mid);
    OOC_OOC_SSA_Destore_open(&_mid);
    OOC_OOC_SSA_CSE_open(&_mid);
    OOC_OOC_SSA_Algebraic_open(&_mid);
    OOC_OOC_SSA_ConstProp_open(&_mid);
    OOC_OOC_SSA_LoopRewrite_open(&_mid);
    OOC_OOC_SSA_PRE_open(&_mid);
    OOC_OOC_SSA_Stats_open(&_mid);
    OOC_OOC_SSA_Allocator_open(&_mid);
    OOC_OOC_C_ConvertDecl_open(&_mid);
    OOC_OOC_C_Naming_open(&_mid);
    OOC_OOC_C_DeclWriter_open(&_mid);
    OOC_OOC_Make_TranslateToC_open(&_mid);
    OOC_OOC_SSA_Blocker_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OOC_SSA_WriteC_init();
  }
  _mid.openCount++;
}
extern void OOC_OOC_SSA_WriteC_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OOC_SSA_WriteC_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_IntStr_close(&_mid);
    OOC_Err_close(&_mid);
    OOC_Out_close(&_mid);
    OOC_Strings_close(&_mid);
    OOC_StringSearch_close(&_mid);
    OOC_IO_close(&_mid);
    OOC_IO_StdChannels_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Object_Boxed_close(&_mid);
    OOC_ADT_Dictionary_close(&_mid);
    OOC_ADT_Dictionary_IntValue_close(&_mid);
    OOC_OOC_SymbolTable_close(&_mid);
    OOC_OOC_SymbolTable_TypeRules_close(&_mid);
    OOC_OOC_SymbolTable_Predef_close(&_mid);
    OOC_OOC_SymbolTable_Builder_close(&_mid);
    OOC_OOC_IR_close(&_mid);
    OOC_OOC_IR_VisitAll_close(&_mid);
    OOC_OOC_SSA_Opcode_close(&_mid);
    OOC_OOC_SSA_Opnd_close(&_mid);
    OOC_OOC_SSA_close(&_mid);
    OOC_OOC_SSA_IRtoSSA_close(&_mid);
    OOC_OOC_SSA_Schedule_close(&_mid);
    OOC_OOC_SSA_XML_close(&_mid);
    OOC_OOC_SSA_DeadCodeElimination_close(&_mid);
    OOC_OOC_SSA_Destore_close(&_mid);
    OOC_OOC_SSA_CSE_close(&_mid);
    OOC_OOC_SSA_Algebraic_close(&_mid);
    OOC_OOC_SSA_ConstProp_close(&_mid);
    OOC_OOC_SSA_LoopRewrite_close(&_mid);
    OOC_OOC_SSA_PRE_close(&_mid);
    OOC_OOC_SSA_Stats_close(&_mid);
    OOC_OOC_SSA_Allocator_close(&_mid);
    OOC_OOC_C_ConvertDecl_close(&_mid);
    OOC_OOC_C_Naming_close(&_mid);
    OOC_OOC_C_DeclWriter_close(&_mid);
    OOC_OOC_Make_TranslateToC_close(&_mid);
    OOC_OOC_SSA_Blocker_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
