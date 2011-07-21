#include <OOC/Doc/Input/Texinfo.oh>
#include <Ascii.oh>
#include <CharClass.oh>
#include <IntStr.oh>
#include <Out.oh>
#include <Msg.oh>
#include <Channel.oh>
#include <TextRider.oh>
#include <StdChannels.oh>
#include <Strings.oh>
#include <OOC/Scanner/InputBuffer.oh>
#include <OOC/Scanner.oh>
#include <OOC/Doc/Decoration.oh>
#include <OOC/Doc/TextBuffer.oh>
typedef OOC_INT8 OOC_Doc_Input_Texinfo__Id;
#define OOC_Doc_Input_Texinfo__class1Low 0
#define OOC_Doc_Input_Texinfo__cmdAtGlyph 0
#define OOC_Doc_Input_Texinfo__cmdLeftBrace 1
#define OOC_Doc_Input_Texinfo__cmdRightBrace 2
#define OOC_Doc_Input_Texinfo__class1High 2
#define OOC_Doc_Input_Texinfo__class2Low 3
#define OOC_Doc_Input_Texinfo__cmdBullet 3
#define OOC_Doc_Input_Texinfo__cmdDots 4
#define OOC_Doc_Input_Texinfo__cmdMinus 5
#define OOC_Doc_Input_Texinfo__cmdResult 6
#define OOC_Doc_Input_Texinfo__class2High 6
#define OOC_Doc_Input_Texinfo__class3Low 7
#define OOC_Doc_Input_Texinfo__cmdAsIs 7
#define OOC_Doc_Input_Texinfo__cmdCite 8
#define OOC_Doc_Input_Texinfo__cmdCode 9
#define OOC_Doc_Input_Texinfo__cmdCommand 10
#define OOC_Doc_Input_Texinfo__cmdDfn 11
#define OOC_Doc_Input_Texinfo__cmdEmph 12
#define OOC_Doc_Input_Texinfo__cmdFile 13
#define OOC_Doc_Input_Texinfo__cmdKbd 14
#define OOC_Doc_Input_Texinfo__cmdSamp 15
#define OOC_Doc_Input_Texinfo__cmdStrong 16
#define OOC_Doc_Input_Texinfo__cmdUrl 17
#define OOC_Doc_Input_Texinfo__cmdVar 18
#define OOC_Doc_Input_Texinfo__cmdOberonModule 19
#define OOC_Doc_Input_Texinfo__cmdOberonConst 20
#define OOC_Doc_Input_Texinfo__cmdOberonField 21
#define OOC_Doc_Input_Texinfo__cmdOberonParam 22
#define OOC_Doc_Input_Texinfo__cmdOberonProc 23
#define OOC_Doc_Input_Texinfo__cmdOberonType 24
#define OOC_Doc_Input_Texinfo__cmdOberonVar 25
#define OOC_Doc_Input_Texinfo__cmdEmail 26
#define OOC_Doc_Input_Texinfo__cmdUref 27
#define OOC_Doc_Input_Texinfo__class3High 27
#define OOC_Doc_Input_Texinfo__class3Args 26
#define OOC_Doc_Input_Texinfo__class4Low 28
#define OOC_Doc_Input_Texinfo__cmdExample 28
#define OOC_Doc_Input_Texinfo__cmdItemize 29
#define OOC_Doc_Input_Texinfo__cmdEnumerate 30
#define OOC_Doc_Input_Texinfo__cmdNoIndent 31
#define OOC_Doc_Input_Texinfo__cmdPreCond 32
#define OOC_Doc_Input_Texinfo__cmdPostCond 33
#define OOC_Doc_Input_Texinfo__cmdTable 34
#define OOC_Doc_Input_Texinfo__cmdEnd 35
#define OOC_Doc_Input_Texinfo__cmdItem 36
#define OOC_Doc_Input_Texinfo__cmdItemX 37
#define OOC_Doc_Input_Texinfo__class4High 37
#define OOC_Doc_Input_Texinfo__cmdUnknown 38
#define OOC_Doc_Input_Texinfo__cmdEmDash 39
#define OOC_Doc_Input_Texinfo__cmdLeftQuot 40
#define OOC_Doc_Input_Texinfo__cmdRightQuot 41
#define OOC_Doc_Input_Texinfo__cmdText 42
#define OOC_Doc_Input_Texinfo__cmdOpeningBrace 43
#define OOC_Doc_Input_Texinfo__cmdClosingBrace 44
#define OOC_Doc_Input_Texinfo__cmdArgSeparator 45
#define OOC_Doc_Input_Texinfo__cmdEndOfText 46
typedef struct OOC_Doc_Input_Texinfo__CommandDesc *OOC_Doc_Input_Texinfo__Command;
typedef struct OOC_Doc_Input_Texinfo__CommandDesc {
  OOC_INT8 id;
  OOC_INT8 _class;
  OOC_CHAR8 name[16];
  OOC_INT8 argLow;
  OOC_INT8 argHigh;
} OOC_Doc_Input_Texinfo__CommandDesc;
typedef struct OOC_Doc_Input_Texinfo__TokenDesc *OOC_Doc_Input_Texinfo__Token;
typedef struct OOC_Doc_Input_Texinfo__TokenDesc {
  OOC_Doc_Input_Texinfo__Token next;
  OOC_CHAR8 bol;
  OOC_INT8 id;
  OOC_CHAR8 __pad6;
  OOC_CHAR8 __pad7;
  OOC_INT32 pos;
  OOC_INT32 line;
  OOC_INT32 column;
  OOC_Scanner_InputBuffer__CharArray str;
} OOC_Doc_Input_Texinfo__TokenDesc;
static OOC_INT8 OOC_Doc_Input_Texinfo__class1[256];
static OOC_Doc_Input_Texinfo__Command OOC_Doc_Input_Texinfo__cmdList[38];
static OOC_Scanner_InputBuffer__CharArray OOC_Doc_Input_Texinfo__emptyString;
#define OOC_Doc_Input_Texinfo__unknownCommand 1
#define OOC_Doc_Input_Texinfo__expectedLeftBrace 2
#define OOC_Doc_Input_Texinfo__expectedRightBrace 3
#define OOC_Doc_Input_Texinfo__junkAfterText 4
#define OOC_Doc_Input_Texinfo__junkAtEndOfLine 5
#define OOC_Doc_Input_Texinfo__invalidItemMark 6
#define OOC_Doc_Input_Texinfo__notAtBeginningOfLine 7
#define OOC_Doc_Input_Texinfo__expectedEnd 8
#define OOC_Doc_Input_Texinfo__lonelyLeftBrace 9
#define OOC_Doc_Input_Texinfo__lonelyRightBrace 10
#define OOC_Doc_Input_Texinfo__wrongNumberOfArgs 11
#define OOC_Doc_Input_Texinfo__expectedMarkupCommand 12
#define OOC_Doc_Input_Texinfo__invalidEnumStart 13
static OOC_Doc_Input_Texinfo__ErrorContext OOC_Doc_Input_Texinfo__texinfoContext;
static OOC_Doc_Input_Texinfo__Token OOC_Doc_Input_Texinfo__Tokenize(OOC_Scanner_SymList__Symbol sym, OOC_Scanner_InputBuffer__CharArray str, OOC_Error__List errList);
static void OOC_Doc_Input_Texinfo__WriteTokens(Channel__Channel ch, OOC_Doc_Input_Texinfo__Token t);
static void OOC_Doc_Input_Texinfo__Init(void);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_Doc_Input_Texinfo__Command = { (RT0__Struct[]){&_td_OOC_Doc_Input_Texinfo__CommandDesc}, NULL, NULL, &_mid, "Command", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Doc_Input_Texinfo__CommandDesc = { (RT0__Struct[]){&_td_OOC_Doc_Input_Texinfo__CommandDesc}, (void*[]){}, NULL, &_mid, "CommandDesc", 20, 0, (1<<RT0__flagAtomic), RT0__strRecord };
RT0__StructDesc _td_OOC_Doc_Input_Texinfo__3263 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 16, 16, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_Doc_Input_Texinfo__Token = { (RT0__Struct[]){&_td_OOC_Doc_Input_Texinfo__TokenDesc}, NULL, NULL, &_mid, "Token", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Doc_Input_Texinfo__TokenDesc = { (RT0__Struct[]){&_td_OOC_Doc_Input_Texinfo__TokenDesc}, (void*[]){}, NULL, &_mid, "TokenDesc", 24, 0, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_Doc_Input_Texinfo__3625 = { (RT0__Struct[]){&RT0__shortint}, NULL, NULL, &_mid, NULL, 256, 256, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_Doc_Input_Texinfo__3659 = { (RT0__Struct[]){&_td_OOC_Doc_Input_Texinfo__Command}, NULL, NULL, &_mid, NULL, 152, 38, 0, RT0__strArray };
RT0__StructDesc _td_OOC_Doc_Input_Texinfo__ErrorContext = { (RT0__Struct[]){&_td_OOC_Doc_Input_Texinfo__ErrorContextDesc}, NULL, NULL, &_mid, "ErrorContext", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Doc_Input_Texinfo__ErrorContextDesc = { (RT0__Struct[]){&_td_Msg__ContextDesc,&_td_OOC_Error__ContextDesc,&_td_OOC_Doc_Input_Texinfo__ErrorContextDesc}, (void*[]){(void*)OOC_Doc_Input_Texinfo__ErrorContextDesc_GetTemplate,(void*)OOC_Error__ContextDesc_BaseTemplate}, NULL, &_mid, "ErrorContextDesc", 4, 2, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_Doc_Input_Texinfo__4315 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 256, 128, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_Doc_Input_Texinfo__5703 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 16, 16, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_Doc_Input_Texinfo__7232 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_Doc_Input_Texinfo__11964 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_Doc_Input_Texinfo__15626 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_Doc_Input_Texinfo__17817 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 2, 2, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_Doc_Input_Texinfo__17960 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_Doc_Input_Texinfo__24039 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_Doc_Input_Texinfo__25525 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 2, 2, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_Doc_Input_Texinfo__27314 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 2, 2, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_Doc_Input_Texinfo__30651 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 2, 2, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_Doc_Input_Texinfo__34261 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:Doc:Input:Texinfo", (RT0__Struct[]) { &_td_OOC_Doc_Input_Texinfo__Command, &_td_OOC_Doc_Input_Texinfo__CommandDesc, &_td_OOC_Doc_Input_Texinfo__Token, &_td_OOC_Doc_Input_Texinfo__TokenDesc, &_td_OOC_Doc_Input_Texinfo__ErrorContext, &_td_OOC_Doc_Input_Texinfo__ErrorContextDesc, NULL }, 0 };

extern void OOC_OOC_Doc_Input_Texinfo_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_Ascii_open(&_mid);
    OOC_CharClass_open(&_mid);
    OOC_IntStr_open(&_mid);
    OOC_Out_open(&_mid);
    OOC_Msg_open(&_mid);
    OOC_Channel_open(&_mid);
    OOC_TextRider_open(&_mid);
    OOC_StdChannels_open(&_mid);
    OOC_Strings_open(&_mid);
    OOC_OOC_Error_open(&_mid);
    OOC_OOC_Scanner_InputBuffer_open(&_mid);
    OOC_OOC_Scanner_open(&_mid);
    OOC_OOC_Scanner_SymList_open(&_mid);
    OOC_OOC_Doc_open(&_mid);
    OOC_OOC_Doc_Decoration_open(&_mid);
    OOC_OOC_Doc_TextBuffer_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OOC_Doc_Input_Texinfo_init();
  }
  _mid.openCount++;
}
extern void OOC_OOC_Doc_Input_Texinfo_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OOC_Doc_Input_Texinfo_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_Ascii_close(&_mid);
    OOC_CharClass_close(&_mid);
    OOC_IntStr_close(&_mid);
    OOC_Out_close(&_mid);
    OOC_Msg_close(&_mid);
    OOC_Channel_close(&_mid);
    OOC_TextRider_close(&_mid);
    OOC_StdChannels_close(&_mid);
    OOC_Strings_close(&_mid);
    OOC_OOC_Error_close(&_mid);
    OOC_OOC_Scanner_InputBuffer_close(&_mid);
    OOC_OOC_Scanner_close(&_mid);
    OOC_OOC_Scanner_SymList_close(&_mid);
    OOC_OOC_Doc_close(&_mid);
    OOC_OOC_Doc_Decoration_close(&_mid);
    OOC_OOC_Doc_TextBuffer_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
