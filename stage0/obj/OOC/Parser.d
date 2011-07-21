#include <OOC/Parser.oh>
#include <Msg.oh>
#include <Strings.oh>
#include <OOC/Scanner/Symbol.oh>
#include <OOC/Doc.oh>
#include <OOC/Doc/Input/Texinfo.oh>
#define OOC_Parser__trailingJunk 1
#define OOC_Parser__expectKeyword 2
#define OOC_Parser__expectSymbol 3
#define OOC_Parser__expectIdent 4
#define OOC_Parser__nameMismatch 5
#define OOC_Parser__expectDataType 6
#define OOC_Parser__unexpectedSymbol 7
#define OOC_Parser__noFlags 8
#define OOC_Parser__noRestParameter 9
#define OOC_Parser__noMultiPartIdent 10
#define OOC_Parser__importingThisModule 11
#define OOC_Parser__exportMarkInProc 12
#define OOC_Parser__noReadOnlyExport 13
#define OOC_Parser__tbProcInsideProc 14
#define OOC_Parser__illegalFactor 15
#define OOC_Parser__invalidFlag 16
#define OOC_Parser__expectExternalKW 17
#define OOC_Parser__fileNameMismatch 19
static OOC_Parser__ErrorContext OOC_Parser__parserContext;

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_Parser__ErrorContext = { (RT0__Struct[]){&_td_OOC_Parser__ErrorContextDesc}, NULL, NULL, &_mid, "ErrorContext", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Parser__ErrorContextDesc = { (RT0__Struct[]){&_td_Msg__ContextDesc,&_td_OOC_Error__ContextDesc,&_td_OOC_Parser__ErrorContextDesc}, (void*[]){(void*)OOC_Parser__ErrorContextDesc_GetTemplate,(void*)OOC_Error__ContextDesc_BaseTemplate}, NULL, &_mid, "ErrorContextDesc", 4, 2, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_Parser__3176 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 256, 128, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_Parser__7704 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_Parser__7728 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_Parser__12376 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:Parser", (RT0__Struct[]) { &_td_OOC_Parser__ErrorContext, &_td_OOC_Parser__ErrorContextDesc, NULL } };

extern void OOC_OOC_Parser_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_Parser_init();
}

/* --- */
