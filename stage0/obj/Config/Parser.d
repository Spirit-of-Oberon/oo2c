#include <Config/Parser.oh>
#include <Object.oh>
#include <LongStrings.oh>
#include <OS/Path.oh>
#include <XML/UnicodeCodec/Latin1.oh>
static void Config_Parser__InitBuilder(Config_Parser__Builder b);
static Config_Parser__Builder Config_Parser__NewBuilder(void);
static void Config_Parser__InitNode(Config_Parser__Node node, Config_Parser__Element parent, XML_Locator__Locator l, struct XML_Locator__Position *pos, RT0__Struct pos__tag);
static void Config_Parser__InitElement(Config_Parser__Element e, Config_Parser__Element parent, struct XML_Locator__Position *pos, RT0__Struct pos__tag, XML_UnicodeBuffer__CharArray name, XML_Builder__AttributeList attrList);
static Config_Parser__Element Config_Parser__NewElement(Config_Parser__Element parent, struct XML_Locator__Position *pos, RT0__Struct pos__tag, XML_UnicodeBuffer__CharArray name, XML_Builder__AttributeList attrList);
static void Config_Parser__InitCharData(Config_Parser__CharData charData, Config_Parser__Element parent, XML_Locator__Locator l, XML_UnicodeBuffer__CharArray str);
static Config_Parser__CharData Config_Parser__NewCharData(Config_Parser__Element parent, XML_Locator__Locator l, XML_UnicodeBuffer__CharArray str);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_Config_Parser__String = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, (OOC_CHAR8*)"String", 2, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_Config_Parser__Element = { (RT0__Struct[]){&_td_Config_Parser__ElementDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"Element", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Config_Parser__Node = { (RT0__Struct[]){&_td_Config_Parser__NodeDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"Node", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Config_Parser__NodeDesc = { (RT0__Struct[]){&_td_Config_Parser__NodeDesc}, (void*[]){(void*)Config_Parser__NodeDesc_IsWhitespace,(void*)Config_Parser__NodeDesc_HasNoElementContent,(void*)Config_Parser__NodeDesc_IsEmpty,(void*)Config_Parser__NodeDesc_GetCharDataContent}, NULL, &_mid, (OOC_CHAR8*)"NodeDesc", 28, 0, 0, RT0__strRecord };
RT0__StructDesc _td_Config_Parser__CharData = { (RT0__Struct[]){&_td_Config_Parser__CharDataDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"CharData", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Config_Parser__CharDataDesc = { (RT0__Struct[]){&_td_Config_Parser__NodeDesc,&_td_Config_Parser__CharDataDesc}, (void*[]){(void*)Config_Parser__NodeDesc_IsWhitespace,(void*)Config_Parser__NodeDesc_HasNoElementContent,(void*)Config_Parser__NodeDesc_IsEmpty,(void*)Config_Parser__NodeDesc_GetCharDataContent}, NULL, &_mid, (OOC_CHAR8*)"CharDataDesc", 32, 1, 0, RT0__strRecord };
RT0__StructDesc _td_Config_Parser__ElementDesc = { (RT0__Struct[]){&_td_Config_Parser__NodeDesc,&_td_Config_Parser__ElementDesc}, (void*[]){(void*)Config_Parser__NodeDesc_IsWhitespace,(void*)Config_Parser__NodeDesc_HasNoElementContent,(void*)Config_Parser__NodeDesc_IsEmpty,(void*)Config_Parser__NodeDesc_GetCharDataContent}, NULL, &_mid, (OOC_CHAR8*)"ElementDesc", 44, 1, 0, RT0__strRecord };
RT0__StructDesc _td_Config_Parser__Builder = { (RT0__Struct[]){&_td_Config_Parser__BuilderDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"Builder", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Config_Parser__BuilderDesc = { (RT0__Struct[]){&_td_XML_Builder__BuilderDesc,&_td_Config_Parser__BuilderDesc}, (void*[]){(void*)Config_Parser__BuilderDesc_SetLocator,(void*)Config_Parser__BuilderDesc_SetErrorListener,(void*)XML_Builder__BuilderDesc_StartDocument,(void*)XML_Builder__BuilderDesc_EndDocument,(void*)XML_Builder__BuilderDesc_StartDTD,(void*)XML_Builder__BuilderDesc_EndDTD,(void*)Config_Parser__BuilderDesc_StartElement,(void*)Config_Parser__BuilderDesc_EndElement,(void*)Config_Parser__BuilderDesc_Attribute,(void*)XML_Builder__BuilderDesc_NamespaceDeclaration,(void*)Config_Parser__BuilderDesc_AttributesDone,(void*)XML_Builder__BuilderDesc_SkippedEntity,(void*)Config_Parser__BuilderDesc_Characters,(void*)XML_Builder__BuilderDesc_StartCDATA,(void*)XML_Builder__BuilderDesc_EndCDATA,(void*)XML_Builder__BuilderDesc_StartEntity,(void*)XML_Builder__BuilderDesc_EndEntity,(void*)XML_Builder__BuilderDesc_EntityDecl,(void*)XML_Builder__BuilderDesc_Notation,(void*)XML_Builder__BuilderDesc_ProcessingInstruction,(void*)XML_Builder__BuilderDesc_Comment}, NULL, &_mid, (OOC_CHAR8*)"BuilderDesc", 44, 1, 0, RT0__strRecord };
RT0__StructDesc _td_Config_Parser__Parser = { (RT0__Struct[]){&_td_Config_Parser__ParserDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"Parser", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Config_Parser__ParserDesc = { (RT0__Struct[]){&_td_Config_Parser__ParserDesc}, (void*[]){(void*)Config_Parser__ParserDesc_ParseDocument}, NULL, &_mid, (OOC_CHAR8*)"ParserDesc", 20, 0, 0, RT0__strRecord };
RT0__StructDesc _td_Config_Parser__Resolver = { (RT0__Struct[]){&_td_Config_Parser__ResolverDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"Resolver", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Config_Parser__ResolverDesc = { (RT0__Struct[]){&_td_XML_EntityResolver__ResolverDesc,&_td_Config_Parser__ResolverDesc}, (void*[]){(void*)XML_EntityResolver__ResolverDesc_GetURI}, NULL, &_mid, (OOC_CHAR8*)"ResolverDesc", 0, 1, (1<<RT0__flagAtomic), RT0__strRecord };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"Config:Parser", (RT0__Struct[]) { &_td_Config_Parser__String, &_td_Config_Parser__Element, &_td_Config_Parser__Node, &_td_Config_Parser__NodeDesc, &_td_Config_Parser__CharData, &_td_Config_Parser__CharDataDesc, &_td_Config_Parser__ElementDesc, &_td_Config_Parser__Builder, &_td_Config_Parser__BuilderDesc, &_td_Config_Parser__Parser, &_td_Config_Parser__ParserDesc, &_td_Config_Parser__Resolver, &_td_Config_Parser__ResolverDesc, NULL }, 0 };

extern void OOC_Config_Parser_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_Object_open(&_mid);
    OOC_IO_open(&_mid);
    OOC_LongStrings_open(&_mid);
    OOC_OS_Path_open(&_mid);
    OOC_XML_EntityResolver_open(&_mid);
    OOC_XML_Builder_open(&_mid);
    OOC_XML_DTD_open(&_mid);
    OOC_XML_Error_open(&_mid);
    OOC_XML_Locator_open(&_mid);
    OOC_XML_Parser_open(&_mid);
    OOC_XML_UnicodeCodec_Latin1_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_Config_Parser_init();
  }
  _mid.openCount++;
}
extern void OOC_Config_Parser_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_Config_Parser_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_Object_close(&_mid);
    OOC_IO_close(&_mid);
    OOC_LongStrings_close(&_mid);
    OOC_OS_Path_close(&_mid);
    OOC_XML_EntityResolver_close(&_mid);
    OOC_XML_Builder_close(&_mid);
    OOC_XML_DTD_close(&_mid);
    OOC_XML_Error_close(&_mid);
    OOC_XML_Locator_close(&_mid);
    OOC_XML_Parser_close(&_mid);
    OOC_XML_UnicodeCodec_Latin1_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
