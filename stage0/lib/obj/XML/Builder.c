#include <XML/Builder.d>
#include <__oo2c.h>
#include <setjmp.h>

void XML_Builder__BuilderDesc_SetLocator(XML_Builder__Builder b, XML_Locator__Locator locator) {

  return;
  ;
}

void XML_Builder__BuilderDesc_SetErrorListener(XML_Builder__Builder b, XML_Locator__ErrorListener el) {

  return;
  ;
}

void XML_Builder__BuilderDesc_StartDocument(XML_Builder__Builder b, XML_DTD__ExternalEntity documentEntity) {

  return;
  ;
}

void XML_Builder__BuilderDesc_EndDocument(XML_Builder__Builder b) {

  return;
  ;
}

void XML_Builder__BuilderDesc_StartDTD(XML_Builder__Builder b, XML_DTD__Builder dtdBuilder) {

  return;
  ;
}

void XML_Builder__BuilderDesc_EndDTD(XML_Builder__Builder b, XML_DTD__ExternalEntity externalDTD, OOC_CHAR8 allDeclarationsProcessed) {

  return;
  ;
}

void XML_Builder__BuilderDesc_StartElement(XML_Builder__Builder b, XML_DTD__NamespaceDeclaration namespaceDecl, XML_UnicodeBuffer__CharArray localName) {

  return;
  ;
}

void XML_Builder__BuilderDesc_EndElement(XML_Builder__Builder b, XML_DTD__NamespaceDeclaration namespaceDecl, XML_UnicodeBuffer__CharArray localName) {

  return;
  ;
}

void XML_Builder__BuilderDesc_Attribute(XML_Builder__Builder b, XML_DTD__NamespaceDeclaration namespaceDecl, XML_UnicodeBuffer__CharArray localName, XML_DTD__AttrDecl attrDecl, XML_DTD__AttValue value, OOC_CHAR8 specified) {

  return;
  ;
}

void XML_Builder__BuilderDesc_NamespaceDeclaration(XML_Builder__Builder b, XML_DTD__NamespaceDeclaration namespaceDecl) {

  return;
  ;
}

void XML_Builder__BuilderDesc_AttributesDone(XML_Builder__Builder b) {

  return;
  ;
}

void XML_Builder__BuilderDesc_SkippedEntity(XML_Builder__Builder b, XML_UnicodeBuffer__CharArray name, XML_DTD__Entity entity) {

  return;
  ;
}

void XML_Builder__BuilderDesc_Characters(XML_Builder__Builder b, XML_DTD__StringVar chars, OOC_LEN chars_0d, OOC_INT32 charsStart, OOC_INT32 charsEnd, OOC_INT8 elementWhitespace) {

  return;
  ;
}

void XML_Builder__BuilderDesc_StartCDATA(XML_Builder__Builder b) {

  return;
  ;
}

void XML_Builder__BuilderDesc_EndCDATA(XML_Builder__Builder b) {

  return;
  ;
}

void XML_Builder__BuilderDesc_StartEntity(XML_Builder__Builder b, XML_DTD__Entity entity) {

  return;
  ;
}

void XML_Builder__BuilderDesc_EndEntity(XML_Builder__Builder b, XML_DTD__Entity entity) {

  return;
  ;
}

void XML_Builder__BuilderDesc_EntityDecl(XML_Builder__Builder b, XML_DTD__Entity entity) {

  return;
  ;
}

void XML_Builder__BuilderDesc_Notation(XML_Builder__Builder b, XML_DTD__Notation notation) {

  return;
  ;
}

void XML_Builder__BuilderDesc_ProcessingInstruction(XML_Builder__Builder b, XML_UnicodeBuffer__CharArray target, XML_DTD__StringVar content, OOC_LEN content_0d, OOC_INT32 contentStart, OOC_INT32 contentEnd, URI__URI baseURI) {

  return;
  ;
}

void XML_Builder__BuilderDesc_Comment(XML_Builder__Builder b, XML_DTD__StringVar chars, OOC_LEN chars_0d, OOC_INT32 charsStart, OOC_INT32 charsEnd) {

  return;
  ;
}

void XML_Builder__Init(XML_Builder__Builder b) {

  return;
  ;
}

XML_Builder__Builder XML_Builder__New(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)RT0__NewObject(_td_XML_Builder__Builder.baseTypes[0]);
  XML_Builder__Init((XML_Builder__Builder)i0);
  return (XML_Builder__Builder)i0;
  ;
}

void XML_Builder__InitAttribute(XML_Builder__Attribute attr, XML_DTD__NamespaceDeclaration namespaceDecl, XML_UnicodeBuffer__CharArray localName, XML_DTD__AttrDecl attrDecl, XML_DTD__AttValue value, OOC_CHAR8 specified, XML_Locator__Locator locator) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)attr;
  i1 = (OOC_INT32)namespaceDecl;
  *(OOC_INT32*)(_check_pointer(i0, 15812)) = i1;
  i1 = (OOC_INT32)localName;
  *(OOC_INT32*)((_check_pointer(i0, 15854))+4) = i1;
  i1 = (OOC_INT32)attrDecl;
  *(OOC_INT32*)((_check_pointer(i0, 15888))+8) = i1;
  i1 = (OOC_INT32)value;
  *(OOC_INT32*)((_check_pointer(i0, 15920))+12) = i1;
  i1 = specified;
  *(OOC_UINT8*)((_check_pointer(i0, 15946))+16) = i1;
  i1 = (OOC_INT32)locator;
  _copy_block((_check_pointer(i1, 15996)),((_check_pointer(i0, 15980))+20),20);
  return;
  ;
}

XML_Builder__Attribute XML_Builder__NewAttribute(XML_DTD__NamespaceDeclaration namespaceDecl, XML_UnicodeBuffer__CharArray localName, XML_DTD__AttrDecl attrDecl, XML_DTD__AttValue value, OOC_CHAR8 specified, XML_Locator__Locator locator) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;

  i0 = (OOC_INT32)RT0__NewObject(_td_XML_Builder__Attribute.baseTypes[0]);
  i1 = specified;
  i2 = !i1;
  if (!i2) goto l4;
  locator = (XML_Locator__Locator)(OOC_INT32)0;
l4:
  i2 = (OOC_INT32)namespaceDecl;
  i3 = (OOC_INT32)localName;
  i4 = (OOC_INT32)attrDecl;
  i5 = (OOC_INT32)value;
  i6 = (OOC_INT32)locator;
  XML_Builder__InitAttribute((XML_Builder__Attribute)i0, (XML_DTD__NamespaceDeclaration)i2, (XML_UnicodeBuffer__CharArray)i3, (XML_DTD__AttrDecl)i4, (XML_DTD__AttValue)i5, i1, (XML_Locator__Locator)i6);
  return (XML_Builder__Attribute)i0;
  ;
}

void XML_Builder__InitAttributeList(XML_Builder__AttributeList attrList) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)attrList;
  *(OOC_INT32*)((_check_pointer(i0, 16859))+4) = ((OOC_INT32)RT0__NewObject(_td_XML_Builder__AttributeArray.baseTypes[0], 4));
  *(OOC_INT32*)(_check_pointer(i0, 16883)) = 0;
  return;
  ;
}

XML_Builder__AttributeList XML_Builder__NewAttributeList(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)RT0__NewObject(_td_XML_Builder__AttributeList.baseTypes[0]);
  XML_Builder__InitAttributeList((XML_Builder__AttributeList)i0);
  return (XML_Builder__AttributeList)i0;
  ;
}

void XML_Builder__AttributeListDesc_Clear(XML_Builder__AttributeList attrList) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT32 i;

  i0 = (OOC_INT32)attrList;
  i = 0;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 17304));
  i2 = 0<i1;
  if (!i2) goto l8;
  i2=0;
l3_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17329))+4);
  i3 = _check_pointer(i3, 17335);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 17335))*4) = 0;
  i2 = i2+1;
  i = i2;
  i3 = i2<i1;
  if (i3) goto l3_loop;
l8:
  *(OOC_INT32*)(_check_pointer(i0, 17367)) = 0;
  return;
  ;
}

void XML_Builder__AttributeListDesc_Append(XML_Builder__AttributeList attrList, XML_Builder__Attribute attr) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  XML_Builder__AttributeArray _new;
  OOC_INT32 i;

  i0 = (OOC_INT32)attrList;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17603))+4);
  i2 = *(OOC_INT32*)(_check_pointer(i0, 17582));
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 17609)), 0);
  i1 = i2==i1;
  if (!i1) goto l11;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 17642));
  i1 = (OOC_INT32)RT0__NewObject(_td_XML_Builder__AttributeArray.baseTypes[0], (i1*2));
  _new = (XML_Builder__AttributeArray)i1;
  i = 0;
  i2 = *(OOC_INT32*)(_check_pointer(i0, 17680));
  i3 = 0<i2;
  if (!i3) goto l10;
  i3=0;
l5_loop:
  i4 = _check_pointer(i1, 17702);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17717))+4);
  i6 = _check_pointer(i6, 17723);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i3, i7, OOC_UINT32, 17723))*4);
  *(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 17702))*4) = i6;
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l5_loop;
l10:
  *(OOC_INT32*)((_check_pointer(i0, 17752))+4) = i1;
l11:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17787))+4);
  i1 = _check_pointer(i1, 17793);
  i2 = *(OOC_INT32*)(_check_pointer(i0, 17802));
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i4 = (OOC_INT32)attr;
  *(OOC_INT32*)(i1+(_check_index(i2, i3, OOC_UINT32, 17793))*4) = i4;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 17835));
  *(OOC_INT32*)(_check_pointer(i0, 17835)) = (i1+1);
  return;
  ;
}

void OOC_XML_Builder_init(void) {

  return;
  ;
}

void OOC_XML_Builder_destroy(void) {
}

/* --- */
