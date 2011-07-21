#include <XML/DTD.oh>
#include <LongStrings.oh>
XML_DTD__AttrDecl XML_DTD__undefAttr;
static void XML_DTD__InitNamespace(XML_DTD__Namespace ns);
static void XML_DTD__InitEntity(XML_DTD__Entity ent, XML_UnicodeBuffer__CharArray name, OOC_INT8 type, XML_UnicodeBuffer__CharArray entityValue, OOC_CHAR8 externalMarkupDecl);
static void XML_DTD__InitInternalEntity(XML_DTD__InternalEntity ent, XML_UnicodeBuffer__CharArray name, OOC_INT8 type, XML_UnicodeBuffer__CharArray entityValue, OOC_CHAR8 externalMarkupDecl);
static void XML_DTD__InitExternalEntity(XML_DTD__ExternalEntity ent, XML_UnicodeBuffer__CharArray name, OOC_INT8 type, XML_UnicodeBuffer__CharArray _public, XML_UnicodeBuffer__CharArray system, XML_UnicodeBuffer__CharArray ndata, URI__URI baseURI, OOC_CHAR8 externalMarkupDecl);
static void XML_DTD__InitNotation(XML_DTD__Notation notation, XML_UnicodeBuffer__CharArray name, XML_UnicodeBuffer__CharArray _public, XML_UnicodeBuffer__CharArray system, URI__URI baseURI);
static void XML_DTD__InitCP(XML_DTD__CP cp, OOC_INT8 cpMode);
static void XML_DTD__InitNamespaceDeclaration(XML_DTD__NamespaceDeclaration namespaceDecl, XML_UnicodeBuffer__CharArray prefix, XML_DTD__StringURI uri);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_XML_DTD__StringVar = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, "StringVar", 2, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_XML_DTD__Namespace = { (RT0__Struct[]){&_td_XML_DTD__NamespaceDesc}, NULL, NULL, &_mid, "Namespace", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_XML_DTD__Declaration = { (RT0__Struct[]){&_td_XML_DTD__DeclarationDesc}, NULL, NULL, &_mid, "Declaration", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_XML_DTD__Builder = { (RT0__Struct[]){&_td_XML_DTD__BuilderDesc}, NULL, NULL, &_mid, "Builder", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_XML_DTD__BuilderDesc = { (RT0__Struct[]){&_td_XML_DTD__BuilderDesc}, (void*[]){(void*)XML_DTD__BuilderDesc_NewCharacters,(void*)XML_DTD__BuilderDesc_NewEntityRef,(void*)XML_DTD__BuilderDesc_NewAttValue,(void*)XML_DTD__BuilderDesc_NewEnumeration,(void*)XML_DTD__BuilderDesc_NewAttrDecl,(void*)XML_DTD__BuilderDesc_AddAttribute,(void*)XML_DTD__BuilderDesc_AttachAttributes,(void*)XML_DTD__BuilderDesc_NewInternalEntity,(void*)XML_DTD__BuilderDesc_IsValidEntityDecl,(void*)XML_DTD__BuilderDesc_NewExternalEntity,(void*)XML_DTD__BuilderDesc_NewExternalDTD,(void*)XML_DTD__BuilderDesc_NewDocumentEntity,(void*)XML_DTD__BuilderDesc_NewNotation,(void*)XML_DTD__BuilderDesc_NewChoiceCP,(void*)XML_DTD__BuilderDesc_NewSeqCP,(void*)XML_DTD__BuilderDesc_NewNameCP,(void*)XML_DTD__BuilderDesc_NewElementDecl,(void*)XML_DTD__BuilderDesc_SetRootName}, NULL, &_mid, "BuilderDesc", 24, 0, 0, RT0__strRecord };
RT0__StructDesc _td_XML_DTD__DeclarationDesc = { (RT0__Struct[]){&_td_XML_DTD__DeclarationDesc}, (void*[]){}, NULL, &_mid, "DeclarationDesc", 8, 0, 0, RT0__strRecord };
RT0__StructDesc _td_XML_DTD__NamespaceDesc = { (RT0__Struct[]){&_td_XML_DTD__NamespaceDesc}, (void*[]){(void*)XML_DTD__NamespaceDesc_Add,(void*)XML_DTD__NamespaceDesc_Get}, NULL, &_mid, "NamespaceDesc", 4, 0, 0, RT0__strRecord };
RT0__StructDesc _td_XML_DTD__Fragment = { (RT0__Struct[]){&_td_XML_DTD__FragmentDesc}, NULL, NULL, &_mid, "Fragment", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_XML_DTD__FragmentDesc = { (RT0__Struct[]){&_td_XML_DTD__FragmentDesc}, (void*[]){}, NULL, &_mid, "FragmentDesc", 4, 0, 0, RT0__strRecord };
RT0__StructDesc _td_XML_DTD__Characters = { (RT0__Struct[]){&_td_XML_DTD__CharactersDesc}, NULL, NULL, &_mid, "Characters", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_XML_DTD__CharactersDesc = { (RT0__Struct[]){&_td_XML_DTD__FragmentDesc,&_td_XML_DTD__CharactersDesc}, (void*[]){}, NULL, &_mid, "CharactersDesc", 16, 1, 0, RT0__strRecord };
RT0__StructDesc _td_XML_DTD__EntityRef = { (RT0__Struct[]){&_td_XML_DTD__EntityRefDesc}, NULL, NULL, &_mid, "EntityRef", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_XML_DTD__Entity = { (RT0__Struct[]){&_td_XML_DTD__EntityDesc}, NULL, NULL, &_mid, "Entity", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_XML_DTD__EntityRefDesc = { (RT0__Struct[]){&_td_XML_DTD__FragmentDesc,&_td_XML_DTD__EntityRefDesc}, (void*[]){}, NULL, &_mid, "EntityRefDesc", 12, 1, 0, RT0__strRecord };
RT0__StructDesc _td_XML_DTD__AttValue = { (RT0__Struct[]){&_td_XML_DTD__AttValueDesc}, NULL, NULL, &_mid, "AttValue", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_XML_DTD__AttValueDesc = { (RT0__Struct[]){&_td_XML_DTD__AttValueDesc}, (void*[]){(void*)XML_DTD__AttValueDesc_Clear,(void*)XML_DTD__AttValueDesc_Append,(void*)XML_DTD__AttValueDesc_Length,(void*)XML_DTD__AttValueDesc_FlattenValue,(void*)XML_DTD__AttValueDesc_Flatten,(void*)XML_DTD__AttValueDesc_FlattenNorm}, NULL, &_mid, "AttValueDesc", 8, 0, 0, RT0__strRecord };
RT0__StructDesc _td_XML_DTD__NameNode = { (RT0__Struct[]){&_td_XML_DTD__NameNodeDesc}, NULL, NULL, &_mid, "NameNode", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_XML_DTD__NameNodeDesc = { (RT0__Struct[]){&_td_XML_DTD__NameNodeDesc}, (void*[]){}, NULL, &_mid, "NameNodeDesc", 8, 0, 0, RT0__strRecord };
RT0__StructDesc _td_XML_DTD__Enumeration = { (RT0__Struct[]){&_td_XML_DTD__EnumerationDesc}, NULL, NULL, &_mid, "Enumeration", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_XML_DTD__EnumerationDesc = { (RT0__Struct[]){&_td_XML_DTD__EnumerationDesc}, (void*[]){(void*)XML_DTD__EnumerationDesc_Append,(void*)XML_DTD__EnumerationDesc_Matches}, NULL, &_mid, "EnumerationDesc", 8, 0, 0, RT0__strRecord };
RT0__StructDesc _td_XML_DTD__AttrDecl = { (RT0__Struct[]){&_td_XML_DTD__AttrDeclDesc}, NULL, NULL, &_mid, "AttrDecl", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_XML_DTD__AttrDeclDesc = { (RT0__Struct[]){&_td_XML_DTD__DeclarationDesc,&_td_XML_DTD__AttrDeclDesc}, (void*[]){}, NULL, &_mid, "AttrDeclDesc", 28, 1, 0, RT0__strRecord };
RT0__StructDesc _td_XML_DTD__EntityDesc = { (RT0__Struct[]){&_td_XML_DTD__DeclarationDesc,&_td_XML_DTD__EntityDesc}, (void*[]){(void*)XML_DTD__EntityDesc_SetEntityValue,(void*)XML_DTD__EntityDesc_LengthValue,(void*)XML_DTD__EntityDesc_IsDocumentEntity}, NULL, &_mid, "EntityDesc", 24, 1, 0, RT0__strRecord };
RT0__StructDesc _td_XML_DTD__InternalEntity = { (RT0__Struct[]){&_td_XML_DTD__InternalEntityDesc}, NULL, NULL, &_mid, "InternalEntity", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_XML_DTD__InternalEntityDesc = { (RT0__Struct[]){&_td_XML_DTD__DeclarationDesc,&_td_XML_DTD__EntityDesc,&_td_XML_DTD__InternalEntityDesc}, (void*[]){(void*)XML_DTD__EntityDesc_SetEntityValue,(void*)XML_DTD__EntityDesc_LengthValue,(void*)XML_DTD__EntityDesc_IsDocumentEntity}, NULL, &_mid, "InternalEntityDesc", 24, 2, 0, RT0__strRecord };
RT0__StructDesc _td_XML_DTD__ExternalEntity = { (RT0__Struct[]){&_td_XML_DTD__ExternalEntityDesc}, NULL, NULL, &_mid, "ExternalEntity", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_XML_DTD__ExternalEntityDesc = { (RT0__Struct[]){&_td_XML_DTD__DeclarationDesc,&_td_XML_DTD__EntityDesc,&_td_XML_DTD__ExternalEntityDesc}, (void*[]){(void*)XML_DTD__EntityDesc_SetEntityValue,(void*)XML_DTD__EntityDesc_LengthValue,(void*)XML_DTD__ExternalEntityDesc_IsDocumentEntity,(void*)XML_DTD__ExternalEntityDesc_SetCodecFactory,(void*)XML_DTD__ExternalEntityDesc_SetVersion,(void*)XML_DTD__ExternalEntityDesc_SetEncoding,(void*)XML_DTD__ExternalEntityDesc_SetStandalone}, NULL, &_mid, "ExternalEntityDesc", 56, 2, 0, RT0__strRecord };
RT0__StructDesc _td_XML_DTD__Notation = { (RT0__Struct[]){&_td_XML_DTD__NotationDesc}, NULL, NULL, &_mid, "Notation", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_XML_DTD__NotationDesc = { (RT0__Struct[]){&_td_XML_DTD__DeclarationDesc,&_td_XML_DTD__NotationDesc}, (void*[]){}, NULL, &_mid, "NotationDesc", 20, 1, 0, RT0__strRecord };
RT0__StructDesc _td_XML_DTD__CP = { (RT0__Struct[]){&_td_XML_DTD__CPDesc}, NULL, NULL, &_mid, "CP", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_XML_DTD__CPDesc = { (RT0__Struct[]){&_td_XML_DTD__CPDesc}, (void*[]){(void*)XML_DTD__CPDesc_SetNext,(void*)XML_DTD__CPDesc_SetMode}, NULL, &_mid, "CPDesc", 8, 0, 0, RT0__strRecord };
RT0__StructDesc _td_XML_DTD__ChoiceCP = { (RT0__Struct[]){&_td_XML_DTD__ChoiceCPDesc}, NULL, NULL, &_mid, "ChoiceCP", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_XML_DTD__ChoiceCPDesc = { (RT0__Struct[]){&_td_XML_DTD__CPDesc,&_td_XML_DTD__ChoiceCPDesc}, (void*[]){(void*)XML_DTD__CPDesc_SetNext,(void*)XML_DTD__CPDesc_SetMode}, NULL, &_mid, "ChoiceCPDesc", 12, 1, 0, RT0__strRecord };
RT0__StructDesc _td_XML_DTD__SeqCP = { (RT0__Struct[]){&_td_XML_DTD__SeqCPDesc}, NULL, NULL, &_mid, "SeqCP", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_XML_DTD__SeqCPDesc = { (RT0__Struct[]){&_td_XML_DTD__CPDesc,&_td_XML_DTD__SeqCPDesc}, (void*[]){(void*)XML_DTD__CPDesc_SetNext,(void*)XML_DTD__CPDesc_SetMode}, NULL, &_mid, "SeqCPDesc", 12, 1, 0, RT0__strRecord };
RT0__StructDesc _td_XML_DTD__NameCP = { (RT0__Struct[]){&_td_XML_DTD__NameCPDesc}, NULL, NULL, &_mid, "NameCP", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_XML_DTD__NameCPDesc = { (RT0__Struct[]){&_td_XML_DTD__CPDesc,&_td_XML_DTD__NameCPDesc}, (void*[]){(void*)XML_DTD__CPDesc_SetNext,(void*)XML_DTD__CPDesc_SetMode}, NULL, &_mid, "NameCPDesc", 12, 1, 0, RT0__strRecord };
RT0__StructDesc _td_XML_DTD__RegexpInfo = { (RT0__Struct[]){&_td_XML_DTD__RegexpInfoDesc}, NULL, NULL, &_mid, "RegexpInfo", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_XML_DTD__RegexpInfoDesc = { (RT0__Struct[]){&_td_XML_DTD__RegexpInfoDesc}, (void*[]){}, NULL, &_mid, "RegexpInfoDesc", 0, 0, (1<<RT0__flagAtomic), RT0__strRecord };
RT0__StructDesc _td_XML_DTD__ElementDecl = { (RT0__Struct[]){&_td_XML_DTD__ElementDeclDesc}, NULL, NULL, &_mid, "ElementDecl", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_XML_DTD__ElementDeclDesc = { (RT0__Struct[]){&_td_XML_DTD__DeclarationDesc,&_td_XML_DTD__ElementDeclDesc}, (void*[]){(void*)XML_DTD__ElementDeclDesc_SetRegexp,(void*)XML_DTD__ElementDeclDesc_SetMultipleDecl,(void*)XML_DTD__ElementDeclDesc_IsEmpty,(void*)XML_DTD__ElementDeclDesc_IsElementContent}, NULL, &_mid, "ElementDeclDesc", 32, 1, 0, RT0__strRecord };
RT0__StructDesc _td_XML_DTD__NamespaceDeclaration = { (RT0__Struct[]){&_td_XML_DTD__NamespaceDeclarationDesc}, NULL, NULL, &_mid, "NamespaceDeclaration", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_XML_DTD__14383 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_XML_DTD__StringURI = { (RT0__Struct[]){&_td_XML_DTD__14383}, NULL, NULL, &_mid, "StringURI", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_XML_DTD__NamespaceDeclarationDesc = { (RT0__Struct[]){&_td_XML_DTD__NamespaceDeclarationDesc}, (void*[]){}, NULL, &_mid, "NamespaceDeclarationDesc", 8, 0, 0, RT0__strRecord };
RT0__StructDesc _td_XML_DTD__36176 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 2, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_XML_DTD__36454 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 2, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_XML_DTD__36608 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_XML_DTD__37086 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 2, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"XML:DTD", (RT0__Struct[]) { &_td_XML_DTD__StringVar, &_td_XML_DTD__Namespace, &_td_XML_DTD__Declaration, &_td_XML_DTD__Builder, &_td_XML_DTD__BuilderDesc, &_td_XML_DTD__DeclarationDesc, &_td_XML_DTD__NamespaceDesc, &_td_XML_DTD__Fragment, &_td_XML_DTD__FragmentDesc, &_td_XML_DTD__Characters, &_td_XML_DTD__CharactersDesc, &_td_XML_DTD__EntityRef, &_td_XML_DTD__Entity, &_td_XML_DTD__EntityRefDesc, &_td_XML_DTD__AttValue, &_td_XML_DTD__AttValueDesc, &_td_XML_DTD__NameNode, &_td_XML_DTD__NameNodeDesc, &_td_XML_DTD__Enumeration, &_td_XML_DTD__EnumerationDesc, &_td_XML_DTD__AttrDecl, &_td_XML_DTD__AttrDeclDesc, &_td_XML_DTD__EntityDesc, &_td_XML_DTD__InternalEntity, &_td_XML_DTD__InternalEntityDesc, &_td_XML_DTD__ExternalEntity, &_td_XML_DTD__ExternalEntityDesc, &_td_XML_DTD__Notation, &_td_XML_DTD__NotationDesc, &_td_XML_DTD__CP, &_td_XML_DTD__CPDesc, &_td_XML_DTD__ChoiceCP, &_td_XML_DTD__ChoiceCPDesc, &_td_XML_DTD__SeqCP, &_td_XML_DTD__SeqCPDesc, &_td_XML_DTD__NameCP, &_td_XML_DTD__NameCPDesc, &_td_XML_DTD__RegexpInfo, &_td_XML_DTD__RegexpInfoDesc, &_td_XML_DTD__ElementDecl, &_td_XML_DTD__ElementDeclDesc, &_td_XML_DTD__NamespaceDeclaration, &_td_XML_DTD__StringURI, &_td_XML_DTD__NamespaceDeclarationDesc, NULL } };

extern void OOC_XML_DTD_init0() {
  RT0__RegisterModule(&_mid);
  OOC_XML_DTD_init();
}

/* --- */
