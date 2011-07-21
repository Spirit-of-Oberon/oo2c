#include <OOC/Doc/Decoration.oh>
#include <Ascii.oh>
#include <CharClass.oh>
#include <Strings.oh>
#include <OOC/Scanner.oh>
typedef struct OOC_Doc_Decoration__DotLineIndentDesc *OOC_Doc_Decoration__DotLineIndent;
typedef struct OOC_Doc_Decoration__DotLineIndentDesc {
  OOC_INT32 indent;
  OOC_INT32 scrWidth;
  OOC_INT32 startOffset;
} OOC_Doc_Decoration__DotLineIndentDesc;

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_Doc_Decoration__Decoration = { (RT0__Struct[]){&_td_OOC_Doc_Decoration__DecorationDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"Decoration", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Doc_Decoration__DecorationDesc = { (RT0__Struct[]){&_td_OOC_Doc_Decoration__DecorationDesc}, (void*[]){(void*)OOC_Doc_Decoration__DecorationDesc_Decorate}, NULL, &_mid, (OOC_CHAR8*)"DecorationDesc", 8, 0, (1<<RT0__flagAtomic), RT0__strRecord };
RT0__StructDesc _td_OOC_Doc_Decoration__PlainIndent = { (RT0__Struct[]){&_td_OOC_Doc_Decoration__PlainIndentDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"PlainIndent", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Doc_Decoration__PlainIndentDesc = { (RT0__Struct[]){&_td_OOC_Doc_Decoration__DecorationDesc,&_td_OOC_Doc_Decoration__PlainIndentDesc}, (void*[]){(void*)OOC_Doc_Decoration__PlainIndentDesc_Decorate}, NULL, &_mid, (OOC_CHAR8*)"PlainIndentDesc", 12, 1, (1<<RT0__flagAtomic), RT0__strRecord };
RT0__StructDesc _td_OOC_Doc_Decoration__DotLineIndent = { (RT0__Struct[]){&_td_OOC_Doc_Decoration__DotLineIndentDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"DotLineIndent", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_Doc_Decoration__DotLineIndentDesc = { (RT0__Struct[]){&_td_OOC_Doc_Decoration__DecorationDesc,&_td_OOC_Doc_Decoration__PlainIndentDesc,&_td_OOC_Doc_Decoration__DotLineIndentDesc}, (void*[]){(void*)OOC_Doc_Decoration__PlainIndentDesc_Decorate}, NULL, &_mid, (OOC_CHAR8*)"DotLineIndentDesc", 12, 2, (1<<RT0__flagAtomic), RT0__strRecord };
RT0__StructDesc _td_OOC_Doc_Decoration__1937 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_Doc_Decoration__7687 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 4, 4, (1<<RT0__flagAtomic), RT0__strArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:Doc:Decoration", (RT0__Struct[]) { &_td_OOC_Doc_Decoration__Decoration, &_td_OOC_Doc_Decoration__DecorationDesc, &_td_OOC_Doc_Decoration__PlainIndent, &_td_OOC_Doc_Decoration__PlainIndentDesc, &_td_OOC_Doc_Decoration__DotLineIndent, &_td_OOC_Doc_Decoration__DotLineIndentDesc, NULL }, 0 };

extern void OOC_OOC_Doc_Decoration_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_Ascii_open(&_mid);
    OOC_CharClass_open(&_mid);
    OOC_Strings_open(&_mid);
    OOC_OOC_Scanner_InputBuffer_open(&_mid);
    OOC_OOC_Scanner_open(&_mid);
    OOC_OOC_Scanner_SymList_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OOC_Doc_Decoration_init();
  }
  _mid.openCount++;
}
extern void OOC_OOC_Doc_Decoration_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OOC_Doc_Decoration_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_Ascii_close(&_mid);
    OOC_CharClass_close(&_mid);
    OOC_Strings_close(&_mid);
    OOC_OOC_Scanner_InputBuffer_close(&_mid);
    OOC_OOC_Scanner_close(&_mid);
    OOC_OOC_Scanner_SymList_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
