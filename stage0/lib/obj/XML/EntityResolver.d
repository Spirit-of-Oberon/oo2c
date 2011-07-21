#include <XML/EntityResolver.oh>
#include <LongStrings.oh>
#include <Strings.oh>
#include <Object.oh>
#include <Exception.oh>
#include <URI/Parser.oh>
#include <URI/CharClass.oh>
#include <XML/Error.oh>
#include <XML/UnicodeCodec.oh>
#include <XML/UnicodeCodec/UTF8.oh>
#define XML_EntityResolver__invalidURI 1
static XML_Error__Context XML_EntityResolver__resolverContext;

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_XML_EntityResolver__Resolver = { (RT0__Struct[]){&_td_XML_EntityResolver__ResolverDesc}, NULL, NULL, &_mid, "Resolver", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_XML_EntityResolver__ResolverDesc = { (RT0__Struct[]){&_td_XML_EntityResolver__ResolverDesc}, (void*[]){(void*)XML_EntityResolver__ResolverDesc_GetURI}, NULL, &_mid, "ResolverDesc", 0, 0, (1<<RT0__flagAtomic), RT0__strRecord };
RT0__StructDesc _td_XML_EntityResolver__1709 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 8192, 8192, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_XML_EntityResolver__1741 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 4, 4, (1<<RT0__flagAtomic), RT0__strArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"XML:EntityResolver", (RT0__Struct[]) { &_td_XML_EntityResolver__Resolver, &_td_XML_EntityResolver__ResolverDesc, NULL } };

extern void OOC_XML_EntityResolver_init0() {
  RT0__RegisterModule(&_mid);
  OOC_XML_EntityResolver_init();
}

/* --- */
