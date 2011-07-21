#include <XML/Builder.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_XML_Builder__Builder = { (RT0__Struct[]){&_td_XML_Builder__BuilderDesc}, NULL, NULL, &_mid, "Builder", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_XML_Builder__BuilderDesc = { (RT0__Struct[]){&_td_XML_Builder__BuilderDesc}, (void*[]){(void*)XML_Builder__BuilderDesc_SetLocator,(void*)XML_Builder__BuilderDesc_SetErrorListener,(void*)XML_Builder__BuilderDesc_StartDocument,(void*)XML_Builder__BuilderDesc_EndDocument,(void*)XML_Builder__BuilderDesc_StartDTD,(void*)XML_Builder__BuilderDesc_EndDTD,(void*)XML_Builder__BuilderDesc_StartElement,(void*)XML_Builder__BuilderDesc_EndElement,(void*)XML_Builder__BuilderDesc_Attribute,(void*)XML_Builder__BuilderDesc_NamespaceDeclaration,(void*)XML_Builder__BuilderDesc_AttributesDone,(void*)XML_Builder__BuilderDesc_SkippedEntity,(void*)XML_Builder__BuilderDesc_Characters,(void*)XML_Builder__BuilderDesc_StartCDATA,(void*)XML_Builder__BuilderDesc_EndCDATA,(void*)XML_Builder__BuilderDesc_StartEntity,(void*)XML_Builder__BuilderDesc_EndEntity,(void*)XML_Builder__BuilderDesc_EntityDecl,(void*)XML_Builder__BuilderDesc_Notation,(void*)XML_Builder__BuilderDesc_ProcessingInstruction,(void*)XML_Builder__BuilderDesc_Comment}, NULL, &_mid, "BuilderDesc", 0, 0, (1<<RT0__flagAtomic), RT0__strRecord };
RT0__StructDesc _td_XML_Builder__Attribute = { (RT0__Struct[]){&_td_XML_Builder__AttributeDesc}, NULL, NULL, &_mid, "Attribute", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_XML_Builder__AttributeDesc = { (RT0__Struct[]){&_td_XML_Builder__AttributeDesc}, (void*[]){}, NULL, &_mid, "AttributeDesc", 40, 0, 0, RT0__strRecord };
RT0__StructDesc _td_XML_Builder__AttributeList = { (RT0__Struct[]){&_td_XML_Builder__AttributeListDesc}, NULL, NULL, &_mid, "AttributeList", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_XML_Builder__3787 = { (RT0__Struct[]){&_td_XML_Builder__Attribute}, NULL, NULL, &_mid, NULL, 4, 1, 0, RT0__strOpenArray };
RT0__StructDesc _td_XML_Builder__AttributeArray = { (RT0__Struct[]){&_td_XML_Builder__3787}, NULL, NULL, &_mid, "AttributeArray", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_XML_Builder__AttributeListDesc = { (RT0__Struct[]){&_td_XML_Builder__AttributeListDesc}, (void*[]){(void*)XML_Builder__AttributeListDesc_Clear,(void*)XML_Builder__AttributeListDesc_Append}, NULL, &_mid, "AttributeListDesc", 8, 0, 0, RT0__strRecord };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"XML:Builder", (RT0__Struct[]) { &_td_XML_Builder__Builder, &_td_XML_Builder__BuilderDesc, &_td_XML_Builder__Attribute, &_td_XML_Builder__AttributeDesc, &_td_XML_Builder__AttributeList, &_td_XML_Builder__AttributeArray, &_td_XML_Builder__AttributeListDesc, NULL } };

extern void OOC_XML_Builder_init0() {
  RT0__RegisterModule(&_mid);
  OOC_XML_Builder_init();
}

/* --- */
