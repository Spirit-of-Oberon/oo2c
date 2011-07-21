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
RT0__StructDesc _td_Config_Parser__String = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, "String", 2, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_Config_Parser__Element = { (RT0__Struct[]){&_td_Config_Parser__ElementDesc}, NULL, NULL, &_mid, "Element", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Config_Parser__Node = { (RT0__Struct[]){&_td_Config_Parser__NodeDesc}, NULL, NULL, &_mid, "Node", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Config_Parser__NodeDesc = { (RT0__Struct[]){&_td_Config_Parser__NodeDesc}, (void*[]){(void*)Config_Parser__NodeDesc_IsWhitespace,(void*)Config_Parser__NodeDesc_HasNoElementContent,(void*)Config_Parser__NodeDesc_IsEmpty,(void*)Config_Parser__NodeDesc_GetCharDataContent}, NULL, &_mid, "NodeDesc", 28, 0, 0, RT0__strRecord };
RT0__StructDesc _td_Config_Parser__CharData = { (RT0__Struct[]){&_td_Config_Parser__CharDataDesc}, NULL, NULL, &_mid, "CharData", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Config_Parser__CharDataDesc = { (RT0__Struct[]){&_td_Config_Parser__NodeDesc,&_td_Config_Parser__CharDataDesc}, (void*[]){(void*)Config_Parser__NodeDesc_IsWhitespace,(void*)Config_Parser__NodeDesc_HasNoElementContent,(void*)Config_Parser__NodeDesc_IsEmpty,(void*)Config_Parser__NodeDesc_GetCharDataContent}, NULL, &_mid, "CharDataDesc", 32, 1, 0, RT0__strRecord };
RT0__StructDesc _td_Config_Parser__ElementDesc = { (RT0__Struct[]){&_td_Config_Parser__NodeDesc,&_td_Config_Parser__ElementDesc}, (void*[]){(void*)Config_Parser__NodeDesc_IsWhitespace,(void*)Config_Parser__NodeDesc_HasNoElementContent,(void*)Config_Parser__NodeDesc_IsEmpty,(void*)Config_Parser__NodeDesc_GetCharDataContent}, NULL, &_mid, "ElementDesc", 44, 1, 0, RT0__strRecord };
RT0__StructDesc _td_Config_Parser__Builder = { (RT0__Struct[]){&_td_Config_Parser__BuilderDesc}, NULL, NULL, &_mid, "Builder", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Config_Parser__BuilderDesc = { (RT0__Struct[]){&_td_XML_Builder__BuilderDesc,&_td_Config_Parser__BuilderDesc}, (void*[]){(void*)Config_Parser__BuilderDesc_SetLocator,(void*)Config_Parser__BuilderDesc_SetErrorListener,(void*)XML_Builder__BuilderDesc_StartDocument,(void*)XML_Builder__BuilderDesc_EndDocument,(void*)XML_Builder__BuilderDesc_StartDTD,(void*)XML_Builder__BuilderDesc_EndDTD,(void*)Config_Parser__BuilderDesc_StartElement,(void*)Config_Parser__BuilderDesc_EndElement,(void*)Config_Parser__BuilderDesc_Attribute,(void*)XML_Builder__BuilderDesc_NamespaceDeclaration,(void*)Config_Parser__BuilderDesc_AttributesDone,(void*)XML_Builder__BuilderDesc_SkippedEntity,(void*)Config_Parser__BuilderDesc_Characters,(void*)XML_Builder__BuilderDesc_StartCDATA,(void*)XML_Builder__BuilderDesc_EndCDATA,(void*)XML_Builder__BuilderDesc_StartEntity,(void*)XML_Builder__BuilderDesc_EndEntity,(void*)XML_Builder__BuilderDesc_EntityDecl,(void*)XML_Builder__BuilderDesc_Notation,(void*)XML_Builder__BuilderDesc_ProcessingInstruction,(void*)XML_Builder__BuilderDesc_Comment}, NULL, &_mid, "BuilderDesc", 44, 1, 0, RT0__strRecord };
RT0__StructDesc _td_Config_Parser__Parser = { (RT0__Struct[]){&_td_Config_Parser__ParserDesc}, NULL, NULL, &_mid, "Parser", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Config_Parser__ParserDesc = { (RT0__Struct[]){&_td_Config_Parser__ParserDesc}, (void*[]){(void*)Config_Parser__ParserDesc_ParseDocument}, NULL, &_mid, "ParserDesc", 20, 0, 0, RT0__strRecord };
RT0__StructDesc _td_Config_Parser__Resolver = { (RT0__Struct[]){&_td_Config_Parser__ResolverDesc}, NULL, NULL, &_mid, "Resolver", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Config_Parser__ResolverDesc = { (RT0__Struct[]){&_td_XML_EntityResolver__ResolverDesc,&_td_Config_Parser__ResolverDesc}, (void*[]){(void*)XML_EntityResolver__ResolverDesc_GetURI}, NULL, &_mid, "ResolverDesc", 0, 1, (1<<RT0__flagAtomic), RT0__strRecord };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"Config:Parser", (RT0__Struct[]) { &_td_Config_Parser__String, &_td_Config_Parser__Element, &_td_Config_Parser__Node, &_td_Config_Parser__NodeDesc, &_td_Config_Parser__CharData, &_td_Config_Parser__CharDataDesc, &_td_Config_Parser__ElementDesc, &_td_Config_Parser__Builder, &_td_Config_Parser__BuilderDesc, &_td_Config_Parser__Parser, &_td_Config_Parser__ParserDesc, &_td_Config_Parser__Resolver, &_td_Config_Parser__ResolverDesc, NULL } };

extern void OOC_Config_Parser_init0() {
  RT0__RegisterModule(&_mid);
  OOC_Config_Parser_init();
}

/* --- */
