#include <OOC/SymbolTable/Namespace.oh>
#include <OOC/SymbolTable/TypeRules.oh>
#include <OOC/SymbolTable/Predef.oh>
#define OOC_SymbolTable_Namespace__multipleDeclForName 1
#define OOC_SymbolTable_Namespace__multipleMemberForName 2
#define OOC_SymbolTable_Namespace__definedForBaseType 3
#define OOC_SymbolTable_Namespace__fieldExistsInBaseType 4
#define OOC_SymbolTable_Namespace__invalidTBProcExport 5
#define OOC_SymbolTable_Namespace__invalidRedefintion 6
#define OOC_SymbolTable_Namespace__redefinitionBeforeBase 7
#define OOC_SymbolTable_Namespace__staticMethodNotExported 8
#define OOC_SymbolTable_Namespace__notProcedure 9
static OOC_SymbolTable_Namespace__ErrorContext OOC_SymbolTable_Namespace__namespaceContext;
static void OOC_SymbolTable_Namespace__InitNamespace(OOC_SymbolTable_Namespace__Namespace ns, OOC_SymbolTable__DeclarationArray da, OOC_INT32 len);
static void OOC_SymbolTable_Namespace__ErrDecl(OOC_INT32 code, OOC_SymbolTable__Declaration decl, OOC_Error__List errList);
static void OOC_SymbolTable_Namespace__InitNested(OOC_SymbolTable_Namespace__Nested ns, OOC_SymbolTable__DeclarationArray da, OOC_INT32 len);
static void OOC_SymbolTable_Namespace__InitExtended(OOC_SymbolTable_Namespace__Extended ns, OOC_SymbolTable__DeclarationArray da, OOC_INT32 len);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_SymbolTable_Namespace__Namespace = { (RT0__Struct[]){&_td_OOC_SymbolTable_Namespace__NamespaceDesc}, NULL, NULL, &_mid, "Namespace", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SymbolTable_Namespace__NamespaceDesc = { (RT0__Struct[]){&_td_OOC_SymbolTable__NamespaceDesc,&_td_OOC_SymbolTable_Namespace__NamespaceDesc}, (void*[]){(void*)OOC_SymbolTable_Namespace__NamespaceDesc_IdentifyLocal2,(void*)OOC_SymbolTable__NamespaceDesc_IdentifyLocal,(void*)OOC_SymbolTable_Namespace__NamespaceDesc_Identify2,(void*)OOC_SymbolTable__NamespaceDesc_Identify,(void*)OOC_SymbolTable__NamespaceDesc_GetSuperProcByIndex,(void*)OOC_SymbolTable_Namespace__NamespaceDesc_CheckLocalUniqueness}, NULL, &_mid, "NamespaceDesc", 8, 1, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_SymbolTable_Namespace__Nested = { (RT0__Struct[]){&_td_OOC_SymbolTable_Namespace__NestedDesc}, NULL, NULL, &_mid, "Nested", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SymbolTable_Namespace__NestedDesc = { (RT0__Struct[]){&_td_OOC_SymbolTable__NamespaceDesc,&_td_OOC_SymbolTable_Namespace__NamespaceDesc,&_td_OOC_SymbolTable_Namespace__NestedDesc}, (void*[]){(void*)OOC_SymbolTable_Namespace__NestedDesc_IdentifyLocal2,(void*)OOC_SymbolTable__NamespaceDesc_IdentifyLocal,(void*)OOC_SymbolTable_Namespace__NestedDesc_Identify2,(void*)OOC_SymbolTable__NamespaceDesc_Identify,(void*)OOC_SymbolTable__NamespaceDesc_GetSuperProcByIndex,(void*)OOC_SymbolTable_Namespace__NamespaceDesc_CheckLocalUniqueness,(void*)OOC_SymbolTable_Namespace__NestedDesc_SetEnclosingNamespace}, NULL, &_mid, "NestedDesc", 12, 2, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_SymbolTable_Namespace__Extended = { (RT0__Struct[]){&_td_OOC_SymbolTable_Namespace__ExtendedDesc}, NULL, NULL, &_mid, "Extended", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SymbolTable_Namespace__ExtendedDesc = { (RT0__Struct[]){&_td_OOC_SymbolTable__NamespaceDesc,&_td_OOC_SymbolTable_Namespace__NamespaceDesc,&_td_OOC_SymbolTable_Namespace__ExtendedDesc}, (void*[]){(void*)OOC_SymbolTable_Namespace__ExtendedDesc_IdentifyLocal2,(void*)OOC_SymbolTable__NamespaceDesc_IdentifyLocal,(void*)OOC_SymbolTable_Namespace__ExtendedDesc_Identify2,(void*)OOC_SymbolTable__NamespaceDesc_Identify,(void*)OOC_SymbolTable_Namespace__ExtendedDesc_GetSuperProcByIndex,(void*)OOC_SymbolTable_Namespace__NamespaceDesc_CheckLocalUniqueness,(void*)OOC_SymbolTable_Namespace__ExtendedDesc_SetBaseNamespace,(void*)OOC_SymbolTable_Namespace__ExtendedDesc_InsertTBProc,(void*)OOC_SymbolTable_Namespace__ExtendedDesc_GetTBProcByIndex,(void*)OOC_SymbolTable_Namespace__ExtendedDesc_CheckRestrictions}, NULL, &_mid, "ExtendedDesc", 12, 2, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_SymbolTable_Namespace__ErrorContext = { (RT0__Struct[]){&_td_OOC_SymbolTable_Namespace__ErrorContextDesc}, NULL, NULL, &_mid, "ErrorContext", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SymbolTable_Namespace__ErrorContextDesc = { (RT0__Struct[]){&_td_Msg__ContextDesc,&_td_OOC_Error__ContextDesc,&_td_OOC_SymbolTable_Namespace__ErrorContextDesc}, (void*[]){(void*)OOC_SymbolTable_Namespace__ErrorContextDesc_GetTemplate,(void*)OOC_Error__ContextDesc_BaseTemplate}, NULL, &_mid, "ErrorContextDesc", 4, 2, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_SymbolTable_Namespace__3125 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 256, 128, (1<<RT0__flagAtomic), RT0__strArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:SymbolTable:Namespace", (RT0__Struct[]) { &_td_OOC_SymbolTable_Namespace__Namespace, &_td_OOC_SymbolTable_Namespace__NamespaceDesc, &_td_OOC_SymbolTable_Namespace__Nested, &_td_OOC_SymbolTable_Namespace__NestedDesc, &_td_OOC_SymbolTable_Namespace__Extended, &_td_OOC_SymbolTable_Namespace__ExtendedDesc, &_td_OOC_SymbolTable_Namespace__ErrorContext, &_td_OOC_SymbolTable_Namespace__ErrorContextDesc, NULL } };

extern void OOC_OOC_SymbolTable_Namespace_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_SymbolTable_Namespace_init();
}

/* --- */
