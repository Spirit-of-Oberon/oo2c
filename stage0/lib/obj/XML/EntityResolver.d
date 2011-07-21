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
RT0__StructDesc _td_XML_EntityResolver__Resolver = { (RT0__Struct[]){&_td_XML_EntityResolver__ResolverDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"Resolver", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_XML_EntityResolver__ResolverDesc = { (RT0__Struct[]){&_td_XML_EntityResolver__ResolverDesc}, (void*[]){(void*)XML_EntityResolver__ResolverDesc_GetURI}, NULL, &_mid, (OOC_CHAR8*)"ResolverDesc", 0, 0, (1<<RT0__flagAtomic), RT0__strRecord };
RT0__StructDesc _td_XML_EntityResolver__1709 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 8192, 8192, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_XML_EntityResolver__1741 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 4, 4, (1<<RT0__flagAtomic), RT0__strArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"XML:EntityResolver", (RT0__Struct[]) { &_td_XML_EntityResolver__Resolver, &_td_XML_EntityResolver__ResolverDesc, NULL }, 0 };

extern void OOC_XML_EntityResolver_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_LongStrings_open(&_mid);
    OOC_Msg_open(&_mid);
    OOC_Strings_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);
    OOC_URI_open(&_mid);
    OOC_URI_Parser_open(&_mid);
    OOC_URI_CharClass_open(&_mid);
    OOC_XML_Error_open(&_mid);
    OOC_XML_DTD_open(&_mid);
    OOC_XML_UnicodeCodec_open(&_mid);
    OOC_XML_UnicodeCodec_UTF8_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_XML_EntityResolver_init();
  }
  _mid.openCount++;
}
extern void OOC_XML_EntityResolver_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_XML_EntityResolver_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_LongStrings_close(&_mid);
    OOC_Msg_close(&_mid);
    OOC_Strings_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
    OOC_URI_close(&_mid);
    OOC_URI_Parser_close(&_mid);
    OOC_URI_CharClass_close(&_mid);
    OOC_XML_Error_close(&_mid);
    OOC_XML_DTD_close(&_mid);
    OOC_XML_UnicodeCodec_close(&_mid);
    OOC_XML_UnicodeCodec_UTF8_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
