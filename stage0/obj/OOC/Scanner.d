#include <OOC/Scanner.oh>
#include <Ascii.oh>
#include <OOC/Scanner/InputBuffer.oh>
#include <OOC/Scanner/Pragma.oh>
#define OOC_Scanner__sizeKWTable 256
static OOC_Scanner_InputBuffer__CharArray OOC_Scanner__kwStr[256][2];
static OOC_INT8 OOC_Scanner__kwSym[256][2];
#define OOC_Scanner__commentNotClosed 1
#define OOC_Scanner__illegalStringChar 2
#define OOC_Scanner__stringNotEnded 3
#define OOC_Scanner__notWithinComment 4
#define OOC_Scanner__illegalSymbol 5
#define OOC_Scanner__illegalExponent 6
#define OOC_Scanner__illegalHexDigit 7
#define OOC_Scanner__notWithinPragma 8
static OOC_Scanner__ErrorContext OOC_Scanner__scannerContext;
static void OOC_Scanner__InitKeywords(void);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_Scanner__2940 = { (RT0__Struct[]){&_td_OOC_Scanner_InputBuffer__CharArray}, NULL, NULL, &_mid, NULL, 8, 2, 0, RT0__strArray };
RT0__StructDesc _td_OOC_Scanner__2923 = { (RT0__Struct[]){&_td_OOC_Scanner__2940}, NULL, NULL, &_mid, NULL, 2048, 256, 0, RT0__strArray };
RT0__StructDesc _td_OOC_Scanner__3046 = { (RT0__Struct[]){&RT0__shortint}, NULL, NULL, &_mid, NULL, 2, 2, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_Scanner__3029 = { (RT0__Struct[]){&_td_OOC_Scanner__3046}, NULL, NULL, &_mid, NULL, 512, 256, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_Scanner__ErrorContext = { (RT0__Struct[]){&_td_OOC_Scanner__ErrorContextDesc}, NULL, NULL, &_mid, "ErrorContext", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Scanner__ErrorContextDesc = { (RT0__Struct[]){&_td_Msg__ContextDesc,&_td_OOC_Error__ContextDesc,&_td_OOC_Scanner__ErrorContextDesc}, (void*[]){(void*)OOC_Scanner__ErrorContextDesc_GetTemplate,(void*)OOC_Error__ContextDesc_BaseTemplate}, NULL, &_mid, "ErrorContextDesc", 4, 2, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_Scanner__3718 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 256, 128, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_Scanner__7823 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_Scanner__22013 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:Scanner", (RT0__Struct[]) { &_td_OOC_Scanner__ErrorContext, &_td_OOC_Scanner__ErrorContextDesc, NULL } };

extern void OOC_OOC_Scanner_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_Scanner_init();
}

/* --- */
