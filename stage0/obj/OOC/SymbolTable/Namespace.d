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
#define OOC_SymbolTable_Namespace__staticMethodAbstract 9
#define OOC_SymbolTable_Namespace__notProcedure 10
static OOC_SymbolTable_Namespace__ErrorContext OOC_SymbolTable_Namespace__namespaceContext;
static void OOC_SymbolTable_Namespace__InitNamespace(OOC_SymbolTable_Namespace__Namespace ns, OOC_SymbolTable__DeclarationArray da, OOC_INT32 len);
static void OOC_SymbolTable_Namespace__ErrDecl(OOC_INT32 code, OOC_SymbolTable__Declaration decl, OOC_Error__List errList);
static void OOC_SymbolTable_Namespace__InitNested(OOC_SymbolTable_Namespace__Nested ns, OOC_SymbolTable__DeclarationArray da, OOC_INT32 len);
static void OOC_SymbolTable_Namespace__InitExtended(OOC_SymbolTable_Namespace__Extended ns, OOC_SymbolTable__DeclarationArray da, OOC_INT32 len);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_SymbolTable_Namespace__Namespace = { (RT0__Struct[]){&_td_OOC_SymbolTable_Namespace__NamespaceDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"Namespace", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SymbolTable_Namespace__NamespaceDesc = { (RT0__Struct[]){&_td_OOC_SymbolTable__NamespaceDesc,&_td_OOC_SymbolTable_Namespace__NamespaceDesc}, (void*[]){(void*)OOC_SymbolTable_Namespace__NamespaceDesc_IdentifyLocal2,(void*)OOC_SymbolTable__NamespaceDesc_IdentifyLocal,(void*)OOC_SymbolTable_Namespace__NamespaceDesc_Identify2,(void*)OOC_SymbolTable__NamespaceDesc_Identify,(void*)OOC_SymbolTable__NamespaceDesc_GetSuperProcByIndex,(void*)OOC_SymbolTable_Namespace__NamespaceDesc_CheckLocalUniqueness}, NULL, &_mid, (OOC_CHAR8*)"NamespaceDesc", 8, 1, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_SymbolTable_Namespace__Nested = { (RT0__Struct[]){&_td_OOC_SymbolTable_Namespace__NestedDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"Nested", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SymbolTable_Namespace__NestedDesc = { (RT0__Struct[]){&_td_OOC_SymbolTable__NamespaceDesc,&_td_OOC_SymbolTable_Namespace__NamespaceDesc,&_td_OOC_SymbolTable_Namespace__NestedDesc}, (void*[]){(void*)OOC_SymbolTable_Namespace__NestedDesc_IdentifyLocal2,(void*)OOC_SymbolTable__NamespaceDesc_IdentifyLocal,(void*)OOC_SymbolTable_Namespace__NestedDesc_Identify2,(void*)OOC_SymbolTable__NamespaceDesc_Identify,(void*)OOC_SymbolTable__NamespaceDesc_GetSuperProcByIndex,(void*)OOC_SymbolTable_Namespace__NamespaceDesc_CheckLocalUniqueness,(void*)OOC_SymbolTable_Namespace__NestedDesc_SetEnclosingNamespace}, NULL, &_mid, (OOC_CHAR8*)"NestedDesc", 12, 2, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_SymbolTable_Namespace__Extended = { (RT0__Struct[]){&_td_OOC_SymbolTable_Namespace__ExtendedDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"Extended", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SymbolTable_Namespace__ExtendedDesc = { (RT0__Struct[]){&_td_OOC_SymbolTable__NamespaceDesc,&_td_OOC_SymbolTable_Namespace__NamespaceDesc,&_td_OOC_SymbolTable_Namespace__ExtendedDesc}, (void*[]){(void*)OOC_SymbolTable_Namespace__ExtendedDesc_IdentifyLocal2,(void*)OOC_SymbolTable__NamespaceDesc_IdentifyLocal,(void*)OOC_SymbolTable_Namespace__ExtendedDesc_Identify2,(void*)OOC_SymbolTable__NamespaceDesc_Identify,(void*)OOC_SymbolTable_Namespace__ExtendedDesc_GetSuperProcByIndex,(void*)OOC_SymbolTable_Namespace__NamespaceDesc_CheckLocalUniqueness,(void*)OOC_SymbolTable_Namespace__ExtendedDesc_SetBaseNamespace,(void*)OOC_SymbolTable_Namespace__ExtendedDesc_InsertTBProc,(void*)OOC_SymbolTable_Namespace__ExtendedDesc_GetTBProcByIndex,(void*)OOC_SymbolTable_Namespace__ExtendedDesc_CheckRestrictions}, NULL, &_mid, (OOC_CHAR8*)"ExtendedDesc", 12, 2, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_SymbolTable_Namespace__ErrorContext = { (RT0__Struct[]){&_td_OOC_SymbolTable_Namespace__ErrorContextDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"ErrorContext", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_SymbolTable_Namespace__ErrorContextDesc = { (RT0__Struct[]){&_td_Msg__ContextDesc,&_td_OOC_Error__ContextDesc,&_td_OOC_SymbolTable_Namespace__ErrorContextDesc}, (void*[]){(void*)OOC_SymbolTable_Namespace__ErrorContextDesc_GetTemplate,(void*)OOC_Error__ContextDesc_BaseTemplate}, NULL, &_mid, (OOC_CHAR8*)"ErrorContextDesc", 4, 2, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_SymbolTable_Namespace__3154 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 256, 128, (1<<RT0__flagAtomic), RT0__strArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:SymbolTable:Namespace", (RT0__Struct[]) { &_td_OOC_SymbolTable_Namespace__Namespace, &_td_OOC_SymbolTable_Namespace__NamespaceDesc, &_td_OOC_SymbolTable_Namespace__Nested, &_td_OOC_SymbolTable_Namespace__NestedDesc, &_td_OOC_SymbolTable_Namespace__Extended, &_td_OOC_SymbolTable_Namespace__ExtendedDesc, &_td_OOC_SymbolTable_Namespace__ErrorContext, &_td_OOC_SymbolTable_Namespace__ErrorContextDesc, NULL }, 0 };

extern void OOC_OOC_SymbolTable_Namespace_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_OOC_Error_open(&_mid);
    OOC_OOC_SymbolTable_open(&_mid);
    OOC_OOC_SymbolTable_TypeRules_open(&_mid);
    OOC_OOC_SymbolTable_Predef_open(&_mid);
    OOC_OOC_SymbolTable_Uses_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OOC_SymbolTable_Namespace_init();
  }
  _mid.openCount++;
}
extern void OOC_OOC_SymbolTable_Namespace_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OOC_SymbolTable_Namespace_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_OOC_Error_close(&_mid);
    OOC_OOC_SymbolTable_close(&_mid);
    OOC_OOC_SymbolTable_TypeRules_close(&_mid);
    OOC_OOC_SymbolTable_Predef_close(&_mid);
    OOC_OOC_SymbolTable_Uses_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
