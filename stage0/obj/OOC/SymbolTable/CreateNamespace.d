static void* _c0;
static void* _c1;
#include <OOC/SymbolTable/CreateNamespace.oh>
#include <Msg.oh>
#include <ADT/ArrayList.oh>
#include <ADT/Dictionary.oh>
#include <OOC/SymbolTable/Namespace.oh>
#include <OOC/SymbolTable/Builder.oh>
#include <OOC/SymbolTable/Predef.oh>
#include <OOC/SymbolTable/ImportModules.oh>
#include <OOC/Doc/ResolveRef.oh>
#define OOC_SymbolTable_CreateNamespace__undeclaredIdent 1
#define OOC_SymbolTable_CreateNamespace__notTypeName 2
#define OOC_SymbolTable_CreateNamespace__illegalRecordBase 3
#define OOC_SymbolTable_CreateNamespace__invalidParameterType 4
#define OOC_SymbolTable_CreateNamespace__invalidReceiverType 5
#define OOC_SymbolTable_CreateNamespace__invalidResultType 6
#define OOC_SymbolTable_CreateNamespace__invalidPointerBaseType 7
#define OOC_SymbolTable_CreateNamespace__invalidArrayElementType 8
#define OOC_SymbolTable_CreateNamespace__invalidOpenArray 9
#define OOC_SymbolTable_CreateNamespace__invalidReceiverModeRecord 10
#define OOC_SymbolTable_CreateNamespace__invalidReceiverModePointer 11
#define OOC_SymbolTable_CreateNamespace__unresolvedForwardDecl 12
#define OOC_SymbolTable_CreateNamespace__forwardNameClash 13
#define OOC_SymbolTable_CreateNamespace__multipleForwardDecl 14
#define OOC_SymbolTable_CreateNamespace__forwardAfterDefinition 15
#define OOC_SymbolTable_CreateNamespace__forwardMismatchFPars 16
#define OOC_SymbolTable_CreateNamespace__undeclaredModule 17
#define OOC_SymbolTable_CreateNamespace__notModule 18
#define OOC_SymbolTable_CreateNamespace__invalidModifierFlag 19
#define OOC_SymbolTable_CreateNamespace__modifierFlagWithoutEffect 20
#define OOC_SymbolTable_CreateNamespace__cannotCreateInstance 21
#define OOC_SymbolTable_CreateNamespace__abstractProcForConcreteRecord 22
#define OOC_SymbolTable_CreateNamespace__abstractProcNotExported 23
#define OOC_SymbolTable_CreateNamespace__procedureStillAbstract 24
#define OOC_SymbolTable_CreateNamespace__atMostOneLinkFile 25
#define OOC_SymbolTable_CreateNamespace__notException 26
#define OOC_SymbolTable_CreateNamespace__invalidTypeBound 27
#define OOC_SymbolTable_CreateNamespace__notParametricType 28
#define OOC_SymbolTable_CreateNamespace__tooFewTypeArgs 29
#define OOC_SymbolTable_CreateNamespace__tooManyTypeArgs 30
#define OOC_SymbolTable_CreateNamespace__notExtensionOfBound 31
#define OOC_SymbolTable_CreateNamespace__tooFewTypeAliases 32
#define OOC_SymbolTable_CreateNamespace__cannotDefineTypeAliases 33
#define OOC_SymbolTable_CreateNamespace__inconsistentVtable 34
#define OOC_SymbolTable_CreateNamespace__tbProcForImportedRecord 35
static OOC_SymbolTable_CreateNamespace__ErrorContext OOC_SymbolTable_CreateNamespace__createNamespaceContext;
static OOC_SymbolTable__Module OOC_SymbolTable_CreateNamespace__predefModule;
OOC_SymbolTable__VarDecl OOC_SymbolTable_CreateNamespace__exception;
OOC_SymbolTable__Module OOC_SymbolTable_CreateNamespace__systemModule;

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_SymbolTable_CreateNamespace__ErrorContext = { (RT0__Struct[]){&_td_OOC_SymbolTable_CreateNamespace__ErrorContextDesc}, NULL, NULL, &_mid, "ErrorContext", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SymbolTable_CreateNamespace__ErrorContextDesc = { (RT0__Struct[]){&_td_Msg__ContextDesc,&_td_OOC_Error__ContextDesc,&_td_OOC_SymbolTable_CreateNamespace__ErrorContextDesc}, (void*[]){(void*)OOC_SymbolTable_CreateNamespace__ErrorContextDesc_GetTemplate,(void*)OOC_Error__ContextDesc_BaseTemplate}, NULL, &_mid, "ErrorContextDesc", 4, 2, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_SymbolTable_CreateNamespace__2715 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 256, 128, (1<<RT0__flagAtomic), RT0__strArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:SymbolTable:CreateNamespace", (RT0__Struct[]) { &_td_OOC_SymbolTable_CreateNamespace__ErrorContext, &_td_OOC_SymbolTable_CreateNamespace__ErrorContextDesc, NULL } };

extern void OOC_OOC_SymbolTable_CreateNamespace_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_SymbolTable_CreateNamespace_init();
}

/* --- */
