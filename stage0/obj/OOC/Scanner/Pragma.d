#include <OOC/Scanner/Pragma.oh>
#include <Object.oh>
#include <Object/BigInt.oh>
#include <Msg.oh>
#include <Strings.oh>
#include <RT0.oh>
#include <Config.oh>
#define OOC_Scanner_Pragma__alreadyInPragma 1
#define OOC_Scanner_Pragma__pragmaNotClosed 2
#define OOC_Scanner_Pragma__expectKeyword 3
#define OOC_Scanner_Pragma__expectSymbol 4
#define OOC_Scanner_Pragma__expectIdent 5
#define OOC_Scanner_Pragma__illegalVarName 6
#define OOC_Scanner_Pragma__undefinedPragmaVar 7
#define OOC_Scanner_Pragma__invalidOperands 8
#define OOC_Scanner_Pragma__illegalFactor 9
#define OOC_Scanner_Pragma__expectBooleanExpr 10
#define OOC_Scanner_Pragma__noOpenIf 11
#define OOC_Scanner_Pragma__ifWithoutEnd 12
#define OOC_Scanner_Pragma__elseAlreadyPresent 13
#define OOC_Scanner_Pragma__pragmaVarAlreadyDefined 14
#define OOC_Scanner_Pragma__notAssignmentCompatible 15
#define OOC_Scanner_Pragma__unbalancedPop 16
#define OOC_Scanner_Pragma__withWithoutEnd 17
#define OOC_Scanner_Pragma__outOfRange 18
static Object_BigInt__BigInt OOC_Scanner_Pragma__intMin;
static Object_BigInt__BigInt OOC_Scanner_Pragma__intMax;
static OOC_Scanner_Pragma__ErrorContext OOC_Scanner_Pragma__pragmaContext;
static OOC_INT8 OOC_Scanner_Pragma__ParsePragma(struct OOC_Scanner_Pragma__State *state, RT0__Struct state__tag);
typedef struct OOC_Scanner_Pragma__ParsePragma_Value {
  Config__Variable value;
  OOC_Scanner_SymList__Symbol sym;
} OOC_Scanner_Pragma__ParsePragma_Value;

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_Scanner_Pragma__ConditionStack = { (RT0__Struct[]){&_td_OOC_Scanner_Pragma__ConditionStackDesc}, NULL, NULL, &_mid, "ConditionStack", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Scanner_Pragma__ConditionStackDesc = { (RT0__Struct[]){&_td_OOC_Scanner_Pragma__ConditionStackDesc}, (void*[]){}, NULL, &_mid, "ConditionStackDesc", 12, 0, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_Scanner_Pragma__State = { (RT0__Struct[]){&_td_OOC_Scanner_Pragma__State}, (void*[]){}, NULL, &_mid, "State", 40, 0, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_Scanner_Pragma__ErrorContext = { (RT0__Struct[]){&_td_OOC_Scanner_Pragma__ErrorContextDesc}, NULL, NULL, &_mid, "ErrorContext", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Scanner_Pragma__ErrorContextDesc = { (RT0__Struct[]){&_td_Msg__ContextDesc,&_td_OOC_Error__ContextDesc,&_td_OOC_Scanner_Pragma__ErrorContextDesc}, (void*[]){(void*)OOC_Scanner_Pragma__ErrorContextDesc_GetTemplate,(void*)OOC_Error__ContextDesc_BaseTemplate}, NULL, &_mid, "ErrorContextDesc", 4, 2, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_Scanner_Pragma__3675 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 256, 128, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_Scanner_Pragma__ParsePragma_Value = { (RT0__Struct[]){&_td_OOC_Scanner_Pragma__ParsePragma_Value}, (void*[]){}, NULL, &_mid, "Value", 8, 0, 0, RT0__strRecord };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:Scanner:Pragma", (RT0__Struct[]) { &_td_OOC_Scanner_Pragma__ConditionStack, &_td_OOC_Scanner_Pragma__ConditionStackDesc, &_td_OOC_Scanner_Pragma__State, &_td_OOC_Scanner_Pragma__ErrorContext, &_td_OOC_Scanner_Pragma__ErrorContextDesc, NULL } };

extern void OOC_OOC_Scanner_Pragma_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_Scanner_Pragma_init();
}

/* --- */
