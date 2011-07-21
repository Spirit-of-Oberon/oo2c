static void* _c0;
static void* _c1;
static void* _c2;
static void* _c3;
static void* _c4;
static void* _c5;
static void* _c6;
static void* _c7;
static void* _c8;
static void* _c9;
static void* _c10;
#include <URI/Parser.oh>
#include <Strings.oh>
#include <URI/CharClass.oh>
#include <URI/String.oh>
#include <URI/Scheme/Hierarchical.oh>
#include <URI/Scheme/Opaque.oh>
#include <URI/Scheme/CurrentDoc.oh>
static URI__HierarchicalURI URI_Parser__defaultHierarchical;
static URI__OpaqueURI URI_Parser__defaultOpaque;

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_URI_Parser__1147 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_URI_Parser__7521 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"URI:Parser", (RT0__Struct[]) { NULL }, 0 };

extern void OOC_URI_Parser_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_Strings_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);
    OOC_URI_open(&_mid);
    OOC_URI_CharClass_open(&_mid);
    OOC_URI_String_open(&_mid);
    OOC_URI_Scheme_Hierarchical_open(&_mid);
    OOC_URI_Scheme_Opaque_open(&_mid);
    OOC_URI_Scheme_CurrentDoc_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_URI_Parser_init();
  }
  _mid.openCount++;
}
extern void OOC_URI_Parser_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_URI_Parser_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_Strings_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
    OOC_URI_close(&_mid);
    OOC_URI_CharClass_close(&_mid);
    OOC_URI_String_close(&_mid);
    OOC_URI_Scheme_Hierarchical_close(&_mid);
    OOC_URI_Scheme_Opaque_close(&_mid);
    OOC_URI_Scheme_CurrentDoc_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
