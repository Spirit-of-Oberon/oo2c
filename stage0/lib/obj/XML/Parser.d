#include <XML/Parser.oh>
#include <Out.oh>
#include <Ascii.oh>
#include <LongStrings.oh>
#include <Object.oh>
#include <URI/Scheme/File.oh>
#include <XML/UnicodeCodec/UTF16.oh>
#define XML_Parser__tabWidth 8
#define XML_Parser__initNameList 8
#define XML_Parser__incrNameList 8
#define XML_Parser__initPEStack 4
#define XML_Parser__incrPEStack 4
#define XML_Parser__stringSystemLiteral 1
#define XML_Parser__stringPubidLiteral 2
#define XML_Parser__stringVersion 3
#define XML_Parser__stringEncoding 4
#define XML_Parser__stringStandalone 5
static OOC_CHAR16 XML_Parser__suplPubidChar[32];
static XML_UnicodeBuffer__CharArray XML_Parser__noName;
#define XML_Parser__invalidChar 1
#define XML_Parser__junkAfterDocument 2
#define XML_Parser__invalidCloseCDATA 3
#define XML_Parser__invalidCommentDashDash 4
#define XML_Parser__commentNotClosed 5
#define XML_Parser__stringNotClosed 6
#define XML_Parser__piNotClosed 7
#define XML_Parser__cdataNotClosed 8
#define XML_Parser__expectedWhitespace 9
#define XML_Parser__expectedName 10
#define XML_Parser__expectedNmtoken 11
#define XML_Parser__expectedChar 12
#define XML_Parser__lAngleInAttValue 13
#define XML_Parser__expectedDigit10 14
#define XML_Parser__expectedDigit16 15
#define XML_Parser__expectedString 16
#define XML_Parser__invalidCharRef 17
#define XML_Parser__expectedEOS 18
#define XML_Parser__ignoreNotClosed 19
#define XML_Parser__invalidPubidChar 20
#define XML_Parser__invalidEncNameChar 21
#define XML_Parser__invalidVersionNumChar 22
#define XML_Parser__expectedNonEmptyString 23
#define XML_Parser__expectedYesNo 24
#define XML_Parser__xmlDeclNotAtBeginning 25
#define XML_Parser__reservedPITarget 26
#define XML_Parser__invalidCharacterEncodings 27
#define XML_Parser__junkAfterExtSubset 28
#define XML_Parser__unknownCharacterEncoding 29
#define XML_Parser__invalidNCName 30
#define XML_Parser__invalidQName 31
#define XML_Parser__expectedMarkupDecl 105
#define XML_Parser__expectedContentSpec 106
#define XML_Parser__expectedAttType 107
#define XML_Parser__expectedAttValue 108
#define XML_Parser__expectedEntityValue 109
#define XML_Parser__expectedCP 110
#define XML_Parser__expectedVersion 111
#define XML_Parser__expectedExternalID 112
#define XML_Parser__expectedConditional 113
#define XML_Parser__expectedPIEnd 114
#define XML_Parser__nonMarkupDeclPERef 115
#define XML_Parser__expectedEncodingDecl 116
#define XML_Parser__malformedURI 117
#define XML_Parser__invalidPredefEntityDecl 118
#define XML_Parser__expectedElement 208
#define XML_Parser__expectedEndTag 209
#define XML_Parser__noSuchGeneralEntity 210
#define XML_Parser__noSuchParameterEntity 211
#define XML_Parser__multipleAttrName 212
#define XML_Parser__recursiveGeneralEntity 213
#define XML_Parser__requiredAttrMissing 214
#define XML_Parser__unbalancedPERef 300
#define XML_Parser__unbalancedGERef 301
#define XML_Parser__invalidGEReplacement 302
#define XML_Parser__accessError 303
#define XML_Parser__referenceToUnparsed 304
#define XML_Parser__externalRefInAtttribute 305
#define XML_Parser__nestingViolation 306
static XML_Error__Context XML_Parser__parserContext;
static OOC_CHAR8 XML_Parser__IsCharUCS4(OOC_INT32 ch);
static OOC_CHAR8 XML_Parser__IsDigit(OOC_CHAR16 ch);
static OOC_CHAR8 XML_Parser__IsBaseChar(OOC_CHAR16 ch);
static OOC_CHAR8 XML_Parser__IsIdeographic(OOC_CHAR16 ch);
static OOC_CHAR8 XML_Parser__IsCombiningChar(OOC_CHAR16 ch);
static OOC_CHAR8 XML_Parser__IsExtender(OOC_CHAR16 ch);
static OOC_CHAR8 XML_Parser__IsLetter(OOC_CHAR16 ch);
static OOC_CHAR8 XML_Parser__IsPubidChar(OOC_CHAR16 ch);
static OOC_CHAR8 XML_Parser__IsVersionNumChar(OOC_CHAR16 ch);
static OOC_CHAR8 XML_Parser__IsEncNameChar(OOC_CHAR16 ch, OOC_CHAR8 first);
static void XML_Parser__SetBaseURI(Msg__Msg err, const OOC_CHAR8 name__ref[], OOC_LEN name_0d, URI__URI uri);
static void XML_Parser__Init(XML_Parser__Parser p, OOC_CHAR8 _new, IO__ByteChannel reader, URI__URI baseURI, XML_UnicodeCodec__Factory codecFactory, XML_EntityResolver__Resolver entityResolver, XML_Builder__Builder builder);
static void XML_Parser__SetErrorMessages(void);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_XML_Parser__PEInfo = { (RT0__Struct[]){&_td_XML_Parser__PEInfo}, (void*[]){}, NULL, &_mid, "PEInfo", 28, 0, 0, RT0__strRecord };
RT0__StructDesc _td_XML_Parser__1571 = { (RT0__Struct[]){&_td_XML_UnicodeBuffer__CharArray}, NULL, NULL, &_mid, NULL, 4, 1, 0, RT0__strOpenArray };
RT0__StructDesc _td_XML_Parser__NameList = { (RT0__Struct[]){&_td_XML_Parser__1571}, NULL, NULL, &_mid, "NameList", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_XML_Parser__1618 = { (RT0__Struct[]){&_td_XML_Parser__PEInfo}, NULL, NULL, &_mid, NULL, 28, 1, 0, RT0__strOpenArray };
RT0__StructDesc _td_XML_Parser__PEInfoList = { (RT0__Struct[]){&_td_XML_Parser__1618}, NULL, NULL, &_mid, "PEInfoList", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_XML_Parser__ErrorListener = { (RT0__Struct[]){&_td_XML_Parser__ErrorListenerDesc}, NULL, NULL, &_mid, "ErrorListener", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_XML_Parser__Parser = { (RT0__Struct[]){&_td_XML_Parser__ParserDesc}, NULL, NULL, &_mid, "Parser", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_XML_Parser__ParserDesc = { (RT0__Struct[]){&_td_XML_Parser__ParserDesc}, (void*[]){(void*)XML_Parser__ParserDesc_ParseDocument}, NULL, &_mid, "ParserDesc", 108, 0, 0, RT0__strRecord };
RT0__StructDesc _td_XML_Parser__7045 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 64, 32, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_XML_Parser__ErrorListenerDesc = { (RT0__Struct[]){&_td_XML_Locator__ErrorListenerDesc,&_td_XML_Parser__ErrorListenerDesc}, (void*[]){(void*)XML_Parser__ErrorListenerDesc_Error}, NULL, &_mid, "ErrorListenerDesc", 4, 1, 0, RT0__strRecord };
RT0__StructDesc _td_XML_Parser__17958 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_XML_Parser__23844 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_XML_Parser__35276 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_XML_Parser__38816 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 2, 2, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_XML_Parser__49172 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_XML_Parser__49161 = { (RT0__Struct[]){&_td_XML_Parser__49172}, NULL, NULL, &_mid, NULL, 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_XML_Parser__52142 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 2, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_XML_Parser__107406 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_XML_Parser__107858 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 2, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_XML_Parser__108369 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 2, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_XML_Parser__108950 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 128, 128, (1<<RT0__flagAtomic), RT0__strArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"XML:Parser", (RT0__Struct[]) { &_td_XML_Parser__PEInfo, &_td_XML_Parser__NameList, &_td_XML_Parser__PEInfoList, &_td_XML_Parser__ErrorListener, &_td_XML_Parser__Parser, &_td_XML_Parser__ParserDesc, &_td_XML_Parser__ErrorListenerDesc, NULL }, 0 };

extern void OOC_XML_Parser_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_Out_open(&_mid);
    OOC_Ascii_open(&_mid);
    OOC_Msg_open(&_mid);
    OOC_LongStrings_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_IO_open(&_mid);
    OOC_URI_open(&_mid);
    OOC_URI_Scheme_File_open(&_mid);
    OOC_XML_UnicodeCodec_open(&_mid);
    OOC_XML_Locator_open(&_mid);
    OOC_XML_EntityResolver_open(&_mid);
    OOC_XML_UnicodeCodec_UTF8_open(&_mid);
    OOC_XML_UnicodeCodec_UTF16_open(&_mid);
    OOC_XML_UnicodeBuffer_open(&_mid);
    OOC_XML_Error_open(&_mid);
    OOC_XML_DTD_open(&_mid);
    OOC_XML_Builder_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_XML_Parser_init();
  }
  _mid.openCount++;
}
extern void OOC_XML_Parser_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_XML_Parser_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_Out_close(&_mid);
    OOC_Ascii_close(&_mid);
    OOC_Msg_close(&_mid);
    OOC_LongStrings_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_IO_close(&_mid);
    OOC_URI_close(&_mid);
    OOC_URI_Scheme_File_close(&_mid);
    OOC_XML_UnicodeCodec_close(&_mid);
    OOC_XML_Locator_close(&_mid);
    OOC_XML_EntityResolver_close(&_mid);
    OOC_XML_UnicodeCodec_UTF8_close(&_mid);
    OOC_XML_UnicodeCodec_UTF16_close(&_mid);
    OOC_XML_UnicodeBuffer_close(&_mid);
    OOC_XML_Error_close(&_mid);
    OOC_XML_DTD_close(&_mid);
    OOC_XML_Builder_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
