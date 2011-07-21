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
RT0__StructDesc _td_OOC_Scanner_Pragma__ConditionStack = { (RT0__Struct[]){&_td_OOC_Scanner_Pragma__ConditionStackDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"ConditionStack", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Scanner_Pragma__ConditionStackDesc = { (RT0__Struct[]){&_td_OOC_Scanner_Pragma__ConditionStackDesc}, (void*[]){}, NULL, &_mid, (OOC_CHAR8*)"ConditionStackDesc", 12, 0, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_Scanner_Pragma__State = { (RT0__Struct[]){&_td_OOC_Scanner_Pragma__State}, (void*[]){}, NULL, &_mid, (OOC_CHAR8*)"State", 40, 0, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_Scanner_Pragma__ErrorContext = { (RT0__Struct[]){&_td_OOC_Scanner_Pragma__ErrorContextDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"ErrorContext", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Scanner_Pragma__ErrorContextDesc = { (RT0__Struct[]){&_td_Msg__ContextDesc,&_td_OOC_Error__ContextDesc,&_td_OOC_Scanner_Pragma__ErrorContextDesc}, (void*[]){(void*)OOC_Scanner_Pragma__ErrorContextDesc_GetTemplate,(void*)OOC_Error__ContextDesc_BaseTemplate}, NULL, &_mid, (OOC_CHAR8*)"ErrorContextDesc", 4, 2, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_Scanner_Pragma__3675 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 256, 128, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_Scanner_Pragma__ParsePragma_Value = { (RT0__Struct[]){&_td_OOC_Scanner_Pragma__ParsePragma_Value}, (void*[]){}, NULL, &_mid, (OOC_CHAR8*)"Value", 8, 0, 0, RT0__strRecord };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:Scanner:Pragma", (RT0__Struct[]) { &_td_OOC_Scanner_Pragma__ConditionStack, &_td_OOC_Scanner_Pragma__ConditionStackDesc, &_td_OOC_Scanner_Pragma__State, &_td_OOC_Scanner_Pragma__ErrorContext, &_td_OOC_Scanner_Pragma__ErrorContextDesc, NULL }, 0 };

extern void OOC_OOC_Scanner_Pragma_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_Object_open(&_mid);
    OOC_Object_BigInt_open(&_mid);
    OOC_Msg_open(&_mid);
    OOC_Strings_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Config_open(&_mid);
    OOC_OOC_Error_open(&_mid);
    OOC_OOC_Scanner_InputBuffer_open(&_mid);
    OOC_OOC_Scanner_Symbol_open(&_mid);
    OOC_OOC_Scanner_SymList_open(&_mid);
    OOC_OOC_Config_Pragmas_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OOC_Scanner_Pragma_init();
  }
  _mid.openCount++;
}
extern void OOC_OOC_Scanner_Pragma_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OOC_Scanner_Pragma_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_Object_close(&_mid);
    OOC_Object_BigInt_close(&_mid);
    OOC_Msg_close(&_mid);
    OOC_Strings_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Config_close(&_mid);
    OOC_OOC_Error_close(&_mid);
    OOC_OOC_Scanner_InputBuffer_close(&_mid);
    OOC_OOC_Scanner_Symbol_close(&_mid);
    OOC_OOC_Scanner_SymList_close(&_mid);
    OOC_OOC_Config_Pragmas_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
