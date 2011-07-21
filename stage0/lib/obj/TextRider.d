#include <TextRider.oh>
#include <Ascii.oh>
#include <Strings.oh>
#include <RealStr.oh>
#include <IntStr.oh>
#include <LRealConv.oh>
#include <ConvTypes.oh>
#define TextRider__maxLookahead 2
static TextRider__ErrorContext TextRider__errorContext;
static Msg__Msg TextRider__GetError(OOC_INT32 code);
static void TextRider__EolDetect(TextRider__Reader r, OOC_CHAR8 ch);
static OOC_CHAR8 TextRider__Lookahead(TextRider__Reader r, OOC_INT16 len);
static OOC_CHAR8 TextRider__Consume(TextRider__Reader r);
static void TextRider__SkipBlanks(TextRider__Reader r);
static void TextRider__SkipEol(TextRider__Reader r);
static OOC_CHAR8 TextRider__HexDigit(OOC_CHAR8 ch);
static OOC_CHAR8 TextRider__HexToInt(const OOC_CHAR8 str__ref[], OOC_LEN str_0d, OOC_INT32 *lint);
static void TextRider__SkipSpaces(TextRider__Scanner s);
static void TextRider__WritePad(TextRider__Writer w, OOC_INT32 n);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_TextRider__Reader = { (RT0__Struct[]){&_td_TextRider__ReaderDesc}, NULL, NULL, &_mid, "Reader", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_TextRider__ReaderDesc = { (RT0__Struct[]){&_td_TextRider__ReaderDesc}, (void*[]){(void*)TextRider__ReaderDesc_Pos,(void*)TextRider__ReaderDesc_ClearError,(void*)TextRider__ReaderDesc_Available,(void*)TextRider__ReaderDesc_SetPos,(void*)TextRider__ReaderDesc_SetOpts,(void*)TextRider__ReaderDesc_SetEol,(void*)TextRider__ReaderDesc_ReadChar,(void*)TextRider__ReaderDesc_Eol,(void*)TextRider__ReaderDesc_ReadLn,(void*)TextRider__ReaderDesc_ReadString,(void*)TextRider__ReaderDesc_ReadLine,(void*)TextRider__ReaderDesc_ReadIdentifier,(void*)TextRider__ReaderDesc_ReadBool,(void*)TextRider__ReaderDesc_ReadLInt,(void*)TextRider__ReaderDesc_ReadHex,(void*)TextRider__ReaderDesc_ReadInt,(void*)TextRider__ReaderDesc_ReadSInt,(void*)TextRider__ReaderDesc_ReadLReal,(void*)TextRider__ReaderDesc_ReadReal,(void*)TextRider__ReaderDesc_ReadSet}, NULL, &_mid, "ReaderDesc", 36, 0, 0, RT0__strRecord };
RT0__StructDesc _td_TextRider__3522 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 2, 2, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_TextRider__4478 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 2, 2, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_TextRider__4517 = { (RT0__Struct[]){&_td_Msg__Msg}, NULL, NULL, &_mid, NULL, 8, 2, 0, RT0__strArray };
RT0__StructDesc _td_TextRider__Writer = { (RT0__Struct[]){&_td_TextRider__WriterDesc}, NULL, NULL, &_mid, "Writer", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_TextRider__WriterDesc = { (RT0__Struct[]){&_td_TextRider__WriterDesc}, (void*[]){(void*)TextRider__WriterDesc_Pos,(void*)TextRider__WriterDesc_SetPos,(void*)TextRider__WriterDesc_ClearError,(void*)TextRider__WriterDesc_SetOpts,(void*)TextRider__WriterDesc_SetEol,(void*)TextRider__WriterDesc_WriteString,(void*)TextRider__WriterDesc_WriteObject,(void*)TextRider__WriterDesc_WriteBool,(void*)TextRider__WriterDesc_WriteChar,(void*)TextRider__WriterDesc_WriteLInt,(void*)TextRider__WriterDesc_WriteSInt,(void*)TextRider__WriterDesc_WriteInt,(void*)TextRider__WriterDesc_WriteHex,(void*)TextRider__WriterDesc_WriteLReal,(void*)TextRider__WriterDesc_WriteReal,(void*)TextRider__WriterDesc_WriteLRealFix,(void*)TextRider__WriterDesc_WriteRealFix,(void*)TextRider__WriterDesc_WriteLRealEng,(void*)TextRider__WriterDesc_WriteRealEng,(void*)TextRider__WriterDesc_WriteSet,(void*)TextRider__WriterDesc_WriteLn}, NULL, &_mid, "WriterDesc", 20, 0, 0, RT0__strRecord };
RT0__StructDesc _td_TextRider__4980 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 2, 2, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_TextRider__String = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, "String", 256, 256, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_TextRider__Scanner = { (RT0__Struct[]){&_td_TextRider__ScannerDesc}, NULL, NULL, &_mid, "Scanner", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_TextRider__ScannerDesc = { (RT0__Struct[]){&_td_TextRider__ScannerDesc}, (void*[]){(void*)TextRider__ScannerDesc_Pos,(void*)TextRider__ScannerDesc_ClearError,(void*)TextRider__ScannerDesc_Available,(void*)TextRider__ScannerDesc_SetPos,(void*)TextRider__ScannerDesc_Scan,(void*)TextRider__ScannerDesc_SetOpts,(void*)TextRider__ScannerDesc_SetEol}, NULL, &_mid, "ScannerDesc", 312, 0, 0, RT0__strRecord };
RT0__StructDesc _td_TextRider__ErrorContext = { (RT0__Struct[]){&_td_TextRider__ErrorContextDesc}, NULL, NULL, &_mid, "ErrorContext", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_TextRider__ErrorContextDesc = { (RT0__Struct[]){&_td_Msg__ContextDesc,&_td_TextRider__ErrorContextDesc}, (void*[]){(void*)TextRider__ErrorContextDesc_GetTemplate}, NULL, &_mid, "ErrorContextDesc", 4, 1, 0, RT0__strRecord };
RT0__StructDesc _td_TextRider__7810 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 128, 128, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_TextRider__12119 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_TextRider__16581 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_TextRider__17774 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_TextRider__18723 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_TextRider__19932 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 8, 8, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_TextRider__20367 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_TextRider__22560 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 14, 14, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_TextRider__24900 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 11, 11, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_TextRider__27208 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1024, 1024, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_TextRider__33072 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1024, 1024, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_TextRider__38078 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_TextRider__38942 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_TextRider__39784 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_TextRider__41984 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 16, 16, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_TextRider__43462 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 128, 128, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_TextRider__43835 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 128, 128, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_TextRider__44278 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 128, 128, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_TextRider__44663 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 128, 128, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_TextRider__45111 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 128, 128, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_TextRider__45494 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 128, 128, (1<<RT0__flagAtomic), RT0__strArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"TextRider", (RT0__Struct[]) { &_td_TextRider__Reader, &_td_TextRider__ReaderDesc, &_td_TextRider__Writer, &_td_TextRider__WriterDesc, &_td_TextRider__String, &_td_TextRider__Scanner, &_td_TextRider__ScannerDesc, &_td_TextRider__ErrorContext, &_td_TextRider__ErrorContextDesc, NULL } };

extern void OOC_TextRider_init0() {
  RT0__RegisterModule(&_mid);
  OOC_TextRider_init();
}

/* --- */
