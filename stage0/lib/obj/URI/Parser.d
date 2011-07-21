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
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"URI:Parser", (RT0__Struct[]) { NULL } };

extern void OOC_URI_Parser_init0() {
  RT0__RegisterModule(&_mid);
  OOC_URI_Parser_init();
}

/* --- */
