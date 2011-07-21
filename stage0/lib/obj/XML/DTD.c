#include <XML/DTD.d>
#include <__oo2c.h>
#include <setjmp.h>

void XML_DTD__InitDeclaration(XML_DTD__Declaration decl, XML_UnicodeBuffer__CharArray name) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)decl;
  *(OOC_INT32*)(_check_pointer(i0, 15157)) = 0;
  i1 = (OOC_INT32)name;
  *(OOC_INT32*)((_check_pointer(i0, 15180))+4) = i1;
  return;
  ;
}

static void XML_DTD__InitNamespace(XML_DTD__Namespace ns) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)ns;
  *(OOC_INT32*)(_check_pointer(i0, 15275)) = 0;
  return;
  ;
}

XML_DTD__Namespace XML_DTD__NewNamespace(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)RT0__NewObject(_td_XML_DTD__Namespace.baseTypes[0]);
  XML_DTD__InitNamespace((XML_DTD__Namespace)i0);
  return (XML_DTD__Namespace)i0;
  ;
}

OOC_CHAR8 XML_DTD__NamespaceDesc_Add(XML_DTD__Namespace ns, XML_DTD__Declaration decl) {
  register OOC_INT32 i0;
  auto OOC_CHAR8 XML_DTD__NamespaceDesc_Add_RecAdd(XML_DTD__Declaration *list);
    
    OOC_CHAR8 XML_DTD__NamespaceDesc_Add_RecAdd(XML_DTD__Declaration *list) {
      register OOC_INT32 i0,i1,i2;

      i0 = (OOC_INT32)*list;
      i1 = i0==(OOC_INT32)0;
      if (i1) goto l7;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15968))+4);
      i2 = (OOC_INT32)decl;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 15982))+4);
      i1 = (
      _cmp16((const void*)(_check_pointer(i1, 15974)),(const void*)(_check_pointer(i2, 15988))))!=0;
      if (i1) goto l5;
      return 0u;
      goto l8;
l5:
      i0 = XML_DTD__NamespaceDesc_Add_RecAdd((void*)(_check_pointer(i0, 16023)));
      return i0;
      goto l8;
l7:
      i0 = (OOC_INT32)decl;
      *list = (XML_DTD__Declaration)i0;
      return 1u;
l8:
      _failed_function(15831); return 0;
      ;
    }


  i0 = (OOC_INT32)decl;
  *(OOC_INT32*)(_check_pointer(i0, 16108)) = 0;
  i0 = (OOC_INT32)ns;
  i0 = XML_DTD__NamespaceDesc_Add_RecAdd((void*)(_check_pointer(i0, 16144)));
  return i0;
  ;
}

XML_DTD__Declaration XML_DTD__NamespaceDesc_Get(XML_DTD__Namespace ns, XML_UnicodeBuffer__CharArray name) {
  register OOC_INT32 i0,i1,i2;
  XML_DTD__Declaration ptr;

  i0 = (OOC_INT32)ns;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 16277));
  ptr = (XML_DTD__Declaration)i0;
  i1 = i0!=0;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16317))+4);
  i2 = (OOC_INT32)name;
  i1 = (
  _cmp16((const void*)(_check_pointer(i1, 16323)),(const void*)(_check_pointer(i2, 16331))))!=0;
  
l5:
  if (!i1) goto l17;
  i1 = (OOC_INT32)name;
  
l8_loop:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 16353));
  ptr = (XML_DTD__Declaration)i0;
  i2 = i0!=0;
  if (i2) goto l11;
  i2=0u;
  goto l13;
l11:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16317))+4);
  i2 = (
  _cmp16((const void*)(_check_pointer(i2, 16323)),(const void*)(_check_pointer(i1, 16331))))!=0;
  
l13:
  if (i2) goto l8_loop;
l17:
  return (XML_DTD__Declaration)i0;
  ;
}

void XML_DTD__InitFragment(XML_DTD__Fragment f) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)f;
  *(OOC_INT32*)(_check_pointer(i0, 16548)) = 0;
  return;
  ;
}

void XML_DTD__InitCharacters(XML_DTD__Characters chars, XML_UnicodeBuffer__CharArray source, OOC_INT32 start, OOC_INT32 end) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)chars;
  XML_DTD__InitFragment((XML_DTD__Fragment)i0);
  i1 = (OOC_INT32)source;
  *(OOC_INT32*)((_check_pointer(i0, 16739))+4) = i1;
  i1 = start;
  *(OOC_INT32*)((_check_pointer(i0, 16768))+8) = i1;
  i1 = end;
  *(OOC_INT32*)((_check_pointer(i0, 16801))+12) = i1;
  return;
  ;
}

XML_DTD__Characters XML_DTD__BuilderDesc_NewCharacters(XML_DTD__Builder b, XML_UnicodeBuffer__CharArray source, OOC_INT32 start, OOC_INT32 end, OOC_CHAR8 createCopy) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9;
  XML_DTD__Characters chars;
  OOC_INT32 len;
  XML_UnicodeBuffer__CharArray copy;
  OOC_INT32 i;

  i0 = (OOC_INT32)RT0__NewObject(_td_XML_DTD__Characters.baseTypes[0]);
  chars = (XML_DTD__Characters)i0;
  i1 = createCopy;
  if (i1) goto l3;
  i1 = end;
  i2 = start;
  i3 = (OOC_INT32)source;
  XML_DTD__InitCharacters((XML_DTD__Characters)i0, (XML_UnicodeBuffer__CharArray)i3, i2, i1);
  goto l12;
l3:
  i1 = start;
  i2 = end;
  i2 = i2-i1;
  len = i2;
  i3 = (OOC_INT32)RT0__NewObject(_td_XML_UnicodeBuffer__CharArray.baseTypes[0], i2);
  copy = (XML_UnicodeBuffer__CharArray)i3;
  i = 0;
  i4 = 0<i2;
  if (!i4) goto l11;
  i4 = (OOC_INT32)source;
  i5=i1;i1=0;
l6_loop:
  i6 = _check_pointer(i3, 17196);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i8 = _check_pointer(i4, 17209);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i8 = *(OOC_UINT16*)(i8+(_check_index(i5, i9, OOC_UINT32, 17209))*2);
  *(OOC_UINT16*)(i6+(_check_index(i1, i7, OOC_UINT32, 17196))*2) = i8;
  i1 = i1+1;
  i = i1;
  i5 = i5+1;
  i6 = i1<i2;
  if (i6) goto l6_loop;
l11:
  XML_DTD__InitCharacters((XML_DTD__Characters)i0, (XML_UnicodeBuffer__CharArray)i3, 0, i2);
l12:
  return (XML_DTD__Characters)i0;
  ;
}

void XML_DTD__InitEntityRef(XML_DTD__EntityRef entRef, XML_UnicodeBuffer__CharArray name, XML_DTD__Entity entity) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)entRef;
  XML_DTD__InitFragment((XML_DTD__Fragment)i0);
  i1 = (OOC_INT32)name;
  *(OOC_INT32*)((_check_pointer(i0, 17501))+4) = i1;
  i1 = (OOC_INT32)entity;
  *(OOC_INT32*)((_check_pointer(i0, 17527))+8) = i1;
  return;
  ;
}

XML_DTD__EntityRef XML_DTD__BuilderDesc_NewEntityRef(XML_DTD__Builder b, XML_UnicodeBuffer__CharArray name, XML_DTD__Entity entity) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_XML_DTD__EntityRef.baseTypes[0]);
  i1 = (OOC_INT32)entity;
  i2 = (OOC_INT32)name;
  XML_DTD__InitEntityRef((XML_DTD__EntityRef)i0, (XML_UnicodeBuffer__CharArray)i2, (XML_DTD__Entity)i1);
  return (XML_DTD__EntityRef)i0;
  ;
}

void XML_DTD__InitAttValue(XML_DTD__AttValue attValue) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)attValue;
  *(OOC_INT32*)(_check_pointer(i0, 17889)) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 17924))+4) = 0;
  return;
  ;
}

XML_DTD__AttValue XML_DTD__BuilderDesc_NewAttValue(XML_DTD__Builder b) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)RT0__NewObject(_td_XML_DTD__AttValue.baseTypes[0]);
  XML_DTD__InitAttValue((XML_DTD__AttValue)i0);
  return (XML_DTD__AttValue)i0;
  ;
}

void XML_DTD__AttValueDesc_Clear(XML_DTD__AttValue attValue) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)attValue;
  *(OOC_INT32*)(_check_pointer(i0, 18204)) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 18239))+4) = 0;
  return;
  ;
}

void XML_DTD__AttValueDesc_Append(XML_DTD__AttValue attValue, XML_DTD__Fragment fragment) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)fragment;
  *(OOC_INT32*)(_check_pointer(i0, 18356)) = 0;
  i1 = (OOC_INT32)attValue;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 18387));
  i2 = i2==0;
  if (i2) goto l3;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 18478))+4);
  *(OOC_INT32*)(_check_pointer(i2, 18492)) = i0;
  goto l4;
l3:
  *(OOC_INT32*)(_check_pointer(i1, 18428)) = i0;
l4:
  *(OOC_INT32*)((_check_pointer(i1, 18532))+4) = i0;
  return;
  ;
}

OOC_INT32 XML_DTD__AttValueDesc_Length(XML_DTD__AttValue attValue) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_INT32 len;
  XML_DTD__Fragment fragment;

  len = 0;
  i0 = (OOC_INT32)attValue;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 18805));
  fragment = (XML_DTD__Fragment)i0;
  i1 = i0!=0;
  if (i1) goto l3;
  i0=0;
  goto l21;
l3:
  i1=0;
l4_loop:
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18870)))), &_td_XML_DTD__EntityRefDesc);
  if (i2) goto l11;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19085)))), &_td_XML_DTD__CharactersDesc);
  if (i2) goto l9;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19075)))), 19075);
  
  goto l16;
l9:
  i2 = *(OOC_INT32*)((_check_pointer(i0, 19127))+12);
  i3 = *(OOC_INT32*)((_check_pointer(i0, 19147))+8);
  i1 = i1+(i2-i3);
  len = i1;
  
  goto l16;
l11:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18905))+8);
  i2 = i2!=0;
  if (i2) goto l14;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19045))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19045))+4);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 19051)), 0);
  i2 = LongStrings__Length((void*)(_check_pointer(i3, 19051)), i2);
  i1 = i1+(i2+2);
  len = i1;
  
  goto l16;
l14:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18954))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 18962))+20);
  i2 = XML_DTD__AttValueDesc_Length((XML_DTD__AttValue)i2);
  i1 = i1+i2;
  len = i1;
  
l16:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 19199));
  fragment = (XML_DTD__Fragment)i0;
  i2 = i0!=0;
  if (i2) goto l4_loop;
l20:
  i0=i1;
l21:
  return i0;
  ;
}

XML_UnicodeBuffer__CharArray XML_DTD__AttValueDesc_FlattenValue(XML_DTD__AttValue attValue, OOC_CHAR8 normalizeWhitespace, OOC_CHAR8 *didNormalization) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_INT32 len;
  XML_UnicodeBuffer__CharArray str;
  OOC_INT32 pos;
  OOC_CHAR8 skipSpace;
  auto void XML_DTD__AttValueDesc_FlattenValue_Append(XML_DTD__AttValue attValue);
    
    void XML_DTD__AttValueDesc_FlattenValue_Append(XML_DTD__AttValue attValue) {
      register OOC_INT32 i0,i1,i2,i3;
      XML_DTD__Fragment f;
      auto void XML_DTD__AttValueDesc_FlattenValue_Append_Copy(const XML_DTD__StringVar source, OOC_LEN source_0d, OOC_INT32 start, OOC_INT32 end);
        
        void XML_DTD__AttValueDesc_FlattenValue_Append_Copy(const XML_DTD__StringVar source, OOC_LEN source_0d, OOC_INT32 start, OOC_INT32 end) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
          OOC_INT32 i;

          i0 = start;
          i = i0;
          i1 = end;
          i2 = i0!=i1;
          if (!i2) goto l16;
          i2 = (OOC_INT32)str;
          i3 = normalizeWhitespace;
          
l3_loop:
          i4 = *(OOC_UINT16*)((OOC_INT32)source+(_check_index(i0, source_0d, OOC_UINT32, 20124))*2);
          i4 = i4==32u;
          if (i4) goto l6;
          skipSpace = 0u;
          i4 = _check_pointer(i2, 20409);
          i5 = OOC_ARRAY_LENGTH(i4, 0);
          i6 = pos;
          i7 = *(OOC_UINT16*)((OOC_INT32)source+(_check_index(i0, source_0d, OOC_UINT32, 20424))*2);
          *(OOC_UINT16*)(i4+(_check_index(i6, i5, OOC_UINT32, 20409))*2) = i7;
          pos = (i6+1);
          goto l11;
l6:
          i4 = skipSpace;
          i4 = !i4;
          if (i4) goto l9;
          *didNormalization = 1u;
          goto l11;
l9:
          i4 = _check_pointer(i2, 20188);
          i5 = OOC_ARRAY_LENGTH(i4, 0);
          i6 = pos;
          *(OOC_UINT16*)(i4+(_check_index(i6, i5, OOC_UINT32, 20188))*2) = 32u;
          pos = (i6+1);
          skipSpace = i3;
l11:
          i0 = i0+1;
          i = i0;
          i4 = i0!=i1;
          if (i4) goto l3_loop;
l16:
          return;
          ;
        }


      i0 = (OOC_INT32)attValue;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 20546));
      f = (XML_DTD__Fragment)i0;
      i1 = i0!=0;
      if (!i1) goto l20;
l3_loop:
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20601)))), &_td_XML_DTD__EntityRefDesc);
      if (i1) goto l10;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20855)))), &_td_XML_DTD__CharactersDesc);
      if (i1) goto l8;
      _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20852)))), 20852);
      goto l15;
l8:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20888))+4);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20888))+4);
      i3 = *(OOC_INT32*)((_check_pointer(i0, 20916))+12);
      i0 = *(OOC_INT32*)((_check_pointer(i0, 20900))+8);
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 20896)), 0);
      XML_DTD__AttValueDesc_FlattenValue_Append_Copy((void*)(_check_pointer(i2, 20896)), i1, i0, i3);
      goto l15;
l10:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20631))+8);
      i1 = i1!=0;
      if (i1) goto l13;
      XML_DTD__AttValueDesc_FlattenValue_Append_Copy(((OOC_CHAR16[]){38,0}), 2, 0, 1);
      i0 = (OOC_INT32)f;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20790))+4);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20790))+4);
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 20796)), 0);
      i1 = LongStrings__Length((void*)(_check_pointer(i2, 20796)), i1);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20757))+4);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20757))+4);
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 20763)), 0);
      XML_DTD__AttValueDesc_FlattenValue_Append_Copy((void*)(_check_pointer(i0, 20763)), i2, 0, i1);
      XML_DTD__AttValueDesc_FlattenValue_Append_Copy(((OOC_CHAR16[]){59,0}), 2, 0, 1);
      goto l15;
l13:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20673))+8);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20681))+20);
      XML_DTD__AttValueDesc_FlattenValue_Append((XML_DTD__AttValue)i0);
l15:
      i0 = (OOC_INT32)f;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 20956));
      f = (XML_DTD__Fragment)i0;
      i1 = i0!=0;
      if (i1) goto l3_loop;
l20:
      return;
      ;
    }


  i0 = (OOC_INT32)attValue;
  i1 = XML_DTD__AttValueDesc_Length((XML_DTD__AttValue)i0);
  len = i1;
  str = (XML_UnicodeBuffer__CharArray)((OOC_INT32)RT0__NewObject(_td_XML_UnicodeBuffer__CharArray.baseTypes[0], (i1+2)));
  pos = 0;
  i1 = normalizeWhitespace;
  skipSpace = i1;
  *didNormalization = 0u;
  XML_DTD__AttValueDesc_FlattenValue_Append((XML_DTD__AttValue)i0);
  i0 = (OOC_INT32)str;
  i1 = normalizeWhitespace;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = pos;
  i1 = i1!=0;
  
l5:
  if (i1) goto l7;
  i1=0u;
  goto l9;
l7:
  i1 = _check_pointer(i0, 21304);
  i2 = pos;
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_UINT16*)(i1+(_check_index((i2-1), i3, OOC_UINT32, 21304))*2);
  i1 = i1==32u;
  
l9:
  if (!i1) goto l11;
  i1 = pos;
  pos = (i1-1);
  *didNormalization = 1u;
l11:
  i1 = _check_pointer(i0, 21382);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i3 = pos;
  *(OOC_UINT16*)(i1+(_check_index(i3, i2, OOC_UINT32, 21382))*2) = 0u;
  return (XML_UnicodeBuffer__CharArray)i0;
  ;
}

XML_UnicodeBuffer__CharArray XML_DTD__AttValueDesc_Flatten(XML_DTD__AttValue attValue, XML_DTD__AttrDecl attrDecl) {
  register OOC_INT32 i0,i1;
  OOC_CHAR8 didNormalization;

  i0 = (OOC_INT32)attrDecl;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3;
  i0=0u;
  goto l4;
l3:
  i0 = *(OOC_INT8*)((_check_pointer(i0, 21952))+12);
  i0 = i0!=9;
  
l4:
  i1 = (OOC_INT32)attValue;
  i0 = (OOC_INT32)XML_DTD__AttValueDesc_FlattenValue((XML_DTD__AttValue)i1, i0, (void*)(OOC_INT32)&didNormalization);
  return (XML_UnicodeBuffer__CharArray)i0;
  ;
}

XML_UnicodeBuffer__CharArray XML_DTD__AttValueDesc_FlattenNorm(XML_DTD__AttValue attValue, XML_DTD__AttrDecl attrDecl, OOC_CHAR8 *didNormalization) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)attrDecl;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3;
  i0=0u;
  goto l4;
l3:
  i0 = *(OOC_INT8*)((_check_pointer(i0, 22505))+12);
  i0 = i0!=9;
  
l4:
  i1 = (OOC_INT32)attValue;
  i0 = (OOC_INT32)XML_DTD__AttValueDesc_FlattenValue((XML_DTD__AttValue)i1, i0, (void*)(OOC_INT32)didNormalization);
  return (XML_UnicodeBuffer__CharArray)i0;
  ;
}

XML_DTD__Enumeration XML_DTD__BuilderDesc_NewEnumeration(XML_DTD__Builder b) {
  register OOC_INT32 i0;
  XML_DTD__Enumeration _enum;

  i0 = (OOC_INT32)RT0__NewObject(_td_XML_DTD__Enumeration.baseTypes[0]);
  _enum = (XML_DTD__Enumeration)i0;
  *(OOC_INT32*)(_check_pointer(i0, 22822)) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 22849))+4) = 0;
  return (XML_DTD__Enumeration)i0;
  ;
}

void XML_DTD__EnumerationDesc_Append(XML_DTD__Enumeration _enum, XML_UnicodeBuffer__CharArray name) {
  register OOC_INT32 i0,i1,i2;
  XML_DTD__NameNode node;

  i0 = (OOC_INT32)RT0__NewObject(_td_XML_DTD__NameNode.baseTypes[0]);
  node = (XML_DTD__NameNode)i0;
  *(OOC_INT32*)(_check_pointer(i0, 23019)) = 0;
  i1 = (OOC_INT32)name;
  *(OOC_INT32*)((_check_pointer(i0, 23042))+4) = i1;
  i1 = (OOC_INT32)_enum;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 23075));
  i2 = i2==0;
  if (i2) goto l3;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23146))+4);
  *(OOC_INT32*)(_check_pointer(i2, 23156)) = i0;
  goto l4;
l3:
  *(OOC_INT32*)(_check_pointer(i1, 23108)) = i0;
l4:
  *(OOC_INT32*)((_check_pointer(i1, 23188))+4) = i0;
  return;
  ;
}

OOC_CHAR8 XML_DTD__EnumerationDesc_Matches(XML_DTD__Enumeration _enum, XML_DTD__StringVar name, OOC_LEN name_0d) {
  register OOC_INT32 i0,i1;
  XML_DTD__NameNode ptr;

  i0 = (OOC_INT32)_enum;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 23452));
  ptr = (XML_DTD__NameNode)i0;
  i1 = i0!=0;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23492))+4);
  i1 = (
  _cmp16((const void*)(_check_pointer(i1, 23498)),(const void*)(OOC_INT32)name))!=0;
  
l5:
  if (!i1) goto l17;
l8_loop:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 23527));
  ptr = (XML_DTD__NameNode)i0;
  i1 = i0!=0;
  if (i1) goto l11;
  i1=0u;
  goto l13;
l11:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23492))+4);
  i1 = (
  _cmp16((const void*)(_check_pointer(i1, 23498)),(const void*)(OOC_INT32)name))!=0;
  
l13:
  if (i1) goto l8_loop;
l17:
  return (i0!=0);
  ;
}

void XML_DTD__InitAttrDecl(XML_DTD__AttrDecl attrDecl, XML_UnicodeBuffer__CharArray elementName, XML_UnicodeBuffer__CharArray name, OOC_INT8 type, XML_DTD__Enumeration _enum, OOC_INT8 _default, XML_DTD__AttValue defaultValue, OOC_CHAR8 externalMarkupDecl) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)name;
  i1 = (OOC_INT32)attrDecl;
  XML_DTD__InitDeclaration((XML_DTD__Declaration)i1, (XML_UnicodeBuffer__CharArray)i0);
  i0 = (OOC_INT32)elementName;
  *(OOC_INT32*)((_check_pointer(i1, 23904))+8) = i0;
  i0 = type;
  *(OOC_INT8*)((_check_pointer(i1, 23946))+12) = i0;
  i0 = externalMarkupDecl;
  *(OOC_UINT8*)((_check_pointer(i1, 23974))+13) = i0;
  i0 = (OOC_INT32)_enum;
  *(OOC_INT32*)((_check_pointer(i1, 24030))+16) = i0;
  i0 = _default;
  *(OOC_INT8*)((_check_pointer(i1, 24065))+20) = i0;
  i0 = (OOC_INT32)defaultValue;
  *(OOC_INT32*)((_check_pointer(i1, 24099))+24) = i0;
  return;
  ;
}

XML_DTD__AttrDecl XML_DTD__BuilderDesc_NewAttrDecl(XML_DTD__Builder b, XML_UnicodeBuffer__CharArray elementName, XML_UnicodeBuffer__CharArray name, OOC_INT8 type, XML_DTD__Enumeration _enum, OOC_INT8 _default, XML_DTD__AttValue defaultValue, OOC_CHAR8 externalMarkupDecl) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;

  i0 = (OOC_INT32)RT0__NewObject(_td_XML_DTD__AttrDecl.baseTypes[0]);
  i1 = externalMarkupDecl;
  i2 = (OOC_INT32)defaultValue;
  i3 = _default;
  i4 = (OOC_INT32)_enum;
  i5 = type;
  i6 = (OOC_INT32)name;
  i7 = (OOC_INT32)elementName;
  XML_DTD__InitAttrDecl((XML_DTD__AttrDecl)i0, (XML_UnicodeBuffer__CharArray)i7, (XML_UnicodeBuffer__CharArray)i6, i5, (XML_DTD__Enumeration)i4, i3, (XML_DTD__AttValue)i2, i1);
  return (XML_DTD__AttrDecl)i0;
  ;
}

void XML_DTD__BuilderDesc_AddAttribute(XML_DTD__Builder b, XML_DTD__AttrDecl attrDecl) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24709))+16);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l3;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24788))+20);
  i2 = (OOC_INT32)attrDecl;
  *(OOC_INT32*)(_check_pointer(i1, 24803)) = i2;
  i1=i2;
  goto l4;
l3:
  i1 = (OOC_INT32)attrDecl;
  *(OOC_INT32*)((_check_pointer(i0, 24744))+16) = i1;
  
l4:
  *(OOC_INT32*)((_check_pointer(i0, 24836))+20) = i1;
  return;
  ;
}

void XML_DTD__BuilderDesc_AttachAttributes(XML_DTD__Builder b) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  XML_DTD__Declaration ptr;
  XML_DTD__AttrDecl attrDecl;
  XML_DTD__Declaration decl;
  XML_DTD__ElementDecl elemDecl;
  OOC_CHAR8 dummy;

  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25147))+16);
  ptr = (XML_DTD__Declaration)i1;
  *(OOC_INT32*)((_check_pointer(i0, 25169))+16) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i0, 25198))+20) = (OOC_INT32)0;
  i2 = i1!=(OOC_INT32)0;
  if (!i2) goto l27;
l3_loop:
  i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 25274)))), &_td_XML_DTD__AttrDeclDesc, 25274);
  attrDecl = (XML_DTD__AttrDecl)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 25306));
  ptr = (XML_DTD__Declaration)i2;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 25369))+8);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25336))+12);
  i3 = (OOC_INT32)XML_DTD__NamespaceDesc_Get((XML_DTD__Namespace)i4, (XML_UnicodeBuffer__CharArray)i3);
  decl = (XML_DTD__Declaration)i3;
  i4 = i3==(OOC_INT32)0;
  if (i4) goto l21;
  i3 = _type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 25525)))), &_td_XML_DTD__ElementDeclDesc, 25525);
  elemDecl = (XML_DTD__ElementDecl)i3;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 25564))+20);
  i4 = XML_DTD__NamespaceDesc_Add((XML_DTD__Namespace)i4, (XML_DTD__Declaration)i1);
  dummy = i4;
  i4 = *(OOC_INT8*)((_check_pointer(i1, 25617))+12);
  i4 = i4==0;
  if (i4) goto l15;
  i4 = *(OOC_INT8*)((_check_pointer(i1, 25817))+12);
  i4 = i4==7;
  if (!i4) goto l22;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 25867))+28);
  i4 = i4==(OOC_INT32)0;
  if (i4) goto l12;
  i1 = (OOC_INT32)XML_DTD__undefAttr;
  *(OOC_INT32*)((_check_pointer(i3, 25976))+28) = i1;
  goto l22;
l12:
  *(OOC_INT32*)((_check_pointer(i3, 25914))+28) = i1;
  goto l22;
l15:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 25661))+24);
  i4 = i4==(OOC_INT32)0;
  if (i4) goto l18;
  i1 = (OOC_INT32)XML_DTD__undefAttr;
  *(OOC_INT32*)((_check_pointer(i3, 25758))+24) = i1;
  goto l22;
l18:
  *(OOC_INT32*)((_check_pointer(i3, 25702))+24) = i1;
  goto l22;
l21:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25463)))), XML_DTD__BuilderDesc_AddAttribute)),XML_DTD__BuilderDesc_AddAttribute)((XML_DTD__Builder)i0, (XML_DTD__AttrDecl)i1);
l22:
  i1 = i2!=(OOC_INT32)0;
  if (!i1) goto l27;
  i1=i2;
  goto l3_loop;
l27:
  *(OOC_INT32*)((_check_pointer(i0, 26054))+20) = (OOC_INT32)0;
  return;
  ;
}

static void XML_DTD__InitEntity(XML_DTD__Entity ent, XML_UnicodeBuffer__CharArray name, OOC_INT8 type, XML_UnicodeBuffer__CharArray entityValue, OOC_CHAR8 externalMarkupDecl) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)name;
  i1 = (OOC_INT32)ent;
  XML_DTD__InitDeclaration((XML_DTD__Declaration)i1, (XML_UnicodeBuffer__CharArray)i0);
  i0 = type;
  *(OOC_INT8*)((_check_pointer(i1, 26383))+8) = i0;
  i0 = externalMarkupDecl;
  *(OOC_UINT8*)((_check_pointer(i1, 26406))+16) = i0;
  i0 = (OOC_INT32)entityValue;
  *(OOC_INT32*)((_check_pointer(i1, 26457))+12) = i0;
  *(OOC_UINT8*)((_check_pointer(i1, 26494))+17) = 0u;
  *(OOC_INT32*)((_check_pointer(i1, 26523))+20) = (OOC_INT32)0;
  return;
  ;
}

void XML_DTD__EntityDesc_SetEntityValue(XML_DTD__Entity entity, XML_UnicodeBuffer__CharArray entityValue) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)entity;
  i1 = (OOC_INT32)entityValue;
  *(OOC_INT32*)((_check_pointer(i0, 26644))+12) = i1;
  return;
  ;
}

OOC_INT32 XML_DTD__EntityDesc_LengthValue(XML_DTD__Entity entity) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)entity;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26827))+12);
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 26840)), 0);
  return (i0-2);
  ;
}

OOC_CHAR8 XML_DTD__EntityDesc_IsDocumentEntity(XML_DTD__Entity entity) {

  return 0u;
  ;
}

static void XML_DTD__InitInternalEntity(XML_DTD__InternalEntity ent, XML_UnicodeBuffer__CharArray name, OOC_INT8 type, XML_UnicodeBuffer__CharArray entityValue, OOC_CHAR8 externalMarkupDecl) {
  register OOC_INT32 i0,i1,i2,i3,i4;

  i0 = externalMarkupDecl;
  i1 = (OOC_INT32)entityValue;
  i2 = type;
  i3 = (OOC_INT32)name;
  i4 = (OOC_INT32)ent;
  XML_DTD__InitEntity((XML_DTD__Entity)i4, (XML_UnicodeBuffer__CharArray)i3, i2, (XML_UnicodeBuffer__CharArray)i1, i0);
  return;
  ;
}

XML_DTD__InternalEntity XML_DTD__BuilderDesc_NewInternalEntity(XML_DTD__Builder b, XML_UnicodeBuffer__CharArray name, OOC_INT8 type, XML_UnicodeBuffer__CharArray entityValue, OOC_CHAR8 externalMarkupDecl) {
  register OOC_INT32 i0,i1,i2,i3,i4;

  i0 = (OOC_INT32)RT0__NewObject(_td_XML_DTD__InternalEntity.baseTypes[0]);
  i1 = externalMarkupDecl;
  i2 = (OOC_INT32)entityValue;
  i3 = type;
  i4 = (OOC_INT32)name;
  XML_DTD__InitInternalEntity((XML_DTD__InternalEntity)i0, (XML_UnicodeBuffer__CharArray)i4, i3, (XML_UnicodeBuffer__CharArray)i2, i1);
  return (XML_DTD__InternalEntity)i0;
  ;
}

OOC_CHAR8 XML_DTD__BuilderDesc_IsValidEntityDecl(XML_DTD__Builder b, XML_UnicodeBuffer__CharArray name, XML_UnicodeBuffer__CharArray entityValue) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)name;
  i1 = (
  _cmp16((const void*)(_check_pointer(i0, 28068)),(const void*)((OOC_CHAR16[]){108,116,0})))==0;
  if (i1) goto l31;
  i1 = (
  _cmp16((const void*)(_check_pointer(i0, 28136)),(const void*)((OOC_CHAR16[]){97,109,112,0})))==0;
  if (i1) goto l29;
  i1 = (
  _cmp16((const void*)(_check_pointer(i0, 28205)),(const void*)((OOC_CHAR16[]){103,116,0})))==0;
  if (i1) goto l23;
  i1 = (
  _cmp16((const void*)(_check_pointer(i0, 28297)),(const void*)((OOC_CHAR16[]){97,112,111,115,0})))==0;
  if (i1) goto l17;
  i0 = (
  _cmp16((const void*)(_check_pointer(i0, 28391)),(const void*)((OOC_CHAR16[]){113,117,111,116,0})))==0;
  if (i0) goto l11;
  return 1u;
  goto l32;
l11:
  i0 = (OOC_INT32)entityValue;
  i1 = (
  _cmp16((const void*)(_check_pointer(i0, 28433)),(const void*)((OOC_CHAR16[]){34,0})))==0;
  if (i1) goto l14;
  i0 = (
  _cmp16((const void*)(_check_pointer(i0, 28457)),(const void*)((OOC_CHAR16[]){38,35,51,52,59,0})))==0;
  
  goto l15;
l14:
  i0=1u;
l15:
  return i0;
  goto l32;
l17:
  i0 = (OOC_INT32)entityValue;
  i1 = (
  _cmp16((const void*)(_check_pointer(i0, 28339)),(const void*)((OOC_CHAR16[]){39,0})))==0;
  if (i1) goto l20;
  i0 = (
  _cmp16((const void*)(_check_pointer(i0, 28363)),(const void*)((OOC_CHAR16[]){38,35,51,57,59,0})))==0;
  
  goto l21;
l20:
  i0=1u;
l21:
  return i0;
  goto l32;
l23:
  i0 = (OOC_INT32)entityValue;
  i1 = (
  _cmp16((const void*)(_check_pointer(i0, 28245)),(const void*)((OOC_CHAR16[]){62,0})))==0;
  if (i1) goto l26;
  i0 = (
  _cmp16((const void*)(_check_pointer(i0, 28269)),(const void*)((OOC_CHAR16[]){38,35,54,50,59,0})))==0;
  
  goto l27;
l26:
  i0=1u;
l27:
  return i0;
  goto l32;
l29:
  i0 = (OOC_INT32)entityValue;
  return ((
  _cmp16((const void*)(_check_pointer(i0, 28177)),(const void*)((OOC_CHAR16[]){38,35,51,56,59,0})))==0);
  goto l32;
l31:
  i0 = (OOC_INT32)entityValue;
  return ((
  _cmp16((const void*)(_check_pointer(i0, 28108)),(const void*)((OOC_CHAR16[]){38,35,54,48,59,0})))==0);
l32:
  _failed_function(27719); return 0;
  ;
}

static void XML_DTD__InitExternalEntity(XML_DTD__ExternalEntity ent, XML_UnicodeBuffer__CharArray name, OOC_INT8 type, XML_UnicodeBuffer__CharArray _public, XML_UnicodeBuffer__CharArray system, XML_UnicodeBuffer__CharArray ndata, URI__URI baseURI, OOC_CHAR8 externalMarkupDecl) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = externalMarkupDecl;
  i1 = type;
  i2 = (OOC_INT32)name;
  i3 = (OOC_INT32)ent;
  XML_DTD__InitEntity((XML_DTD__Entity)i3, (XML_UnicodeBuffer__CharArray)i2, i1, (XML_UnicodeBuffer__CharArray)(OOC_INT32)0, i0);
  i0 = (OOC_INT32)_public;
  *(OOC_INT32*)((_check_pointer(i3, 28887))+24) = i0;
  i0 = (OOC_INT32)system;
  *(OOC_INT32*)((_check_pointer(i3, 28914))+28) = i0;
  i0 = (OOC_INT32)baseURI;
  *(OOC_INT32*)((_check_pointer(i3, 28941))+36) = i0;
  i0 = (OOC_INT32)ndata;
  *(OOC_INT32*)((_check_pointer(i3, 28970))+32) = i0;
  *(OOC_INT32*)((_check_pointer(i3, 28995))+40) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i3, 29020))+44) = (OOC_INT32)0;
  *(OOC_INT8*)((_check_pointer(i3, 29046))+48) = 3;
  return;
  ;
}

XML_DTD__ExternalEntity XML_DTD__BuilderDesc_NewExternalEntity(XML_DTD__Builder b, XML_UnicodeBuffer__CharArray name, OOC_INT8 type, XML_UnicodeBuffer__CharArray _public, XML_UnicodeBuffer__CharArray system, XML_UnicodeBuffer__CharArray ndata, URI__URI baseURI, OOC_CHAR8 externalMarkupDecl) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;

  i0 = (OOC_INT32)RT0__NewObject(_td_XML_DTD__ExternalEntity.baseTypes[0]);
  i1 = externalMarkupDecl;
  i2 = (OOC_INT32)baseURI;
  i3 = (OOC_INT32)ndata;
  i4 = (OOC_INT32)system;
  i5 = (OOC_INT32)_public;
  i6 = type;
  i7 = (OOC_INT32)name;
  XML_DTD__InitExternalEntity((XML_DTD__ExternalEntity)i0, (XML_UnicodeBuffer__CharArray)i7, i6, (XML_UnicodeBuffer__CharArray)i5, (XML_UnicodeBuffer__CharArray)i4, (XML_UnicodeBuffer__CharArray)i3, (URI__URI)i2, i1);
  return (XML_DTD__ExternalEntity)i0;
  ;
}

void XML_DTD__ExternalEntityDesc_SetCodecFactory(XML_DTD__ExternalEntity entity, XML_UnicodeCodec__Factory codecFactory) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)entity;
  i1 = (OOC_INT32)codecFactory;
  *(OOC_INT32*)((_check_pointer(i0, 29709))+52) = i1;
  return;
  ;
}

void XML_DTD__ExternalEntityDesc_SetVersion(XML_DTD__ExternalEntity entity, XML_UnicodeBuffer__CharArray version) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)entity;
  i1 = (OOC_INT32)version;
  *(OOC_INT32*)((_check_pointer(i0, 29849))+40) = i1;
  return;
  ;
}

void XML_DTD__ExternalEntityDesc_SetEncoding(XML_DTD__ExternalEntity entity, XML_UnicodeBuffer__CharArray encoding) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)entity;
  i1 = (OOC_INT32)encoding;
  *(OOC_INT32*)((_check_pointer(i0, 29975))+44) = i1;
  return;
  ;
}

void XML_DTD__ExternalEntityDesc_SetStandalone(XML_DTD__ExternalEntity entity, OOC_INT8 standalone) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)entity;
  i1 = standalone;
  *(OOC_INT8*)((_check_pointer(i0, 30116))+48) = i1;
  return;
  ;
}

OOC_CHAR8 XML_DTD__ExternalEntityDesc_IsDocumentEntity(XML_DTD__ExternalEntity entity) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)entity;
  i0 = *(OOC_INT8*)((_check_pointer(i0, 30257))+8);
  return (i0==5);
  ;
}

XML_DTD__ExternalEntity XML_DTD__BuilderDesc_NewExternalDTD(XML_DTD__Builder b, XML_UnicodeBuffer__CharArray _public, XML_UnicodeBuffer__CharArray system, URI__URI baseURI) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)RT0__NewObject(_td_XML_DTD__ExternalEntity.baseTypes[0]);
  i1 = (OOC_INT32)baseURI;
  i2 = (OOC_INT32)system;
  i3 = (OOC_INT32)_public;
  XML_DTD__InitExternalEntity((XML_DTD__ExternalEntity)i0, (XML_UnicodeBuffer__CharArray)(OOC_INT32)0, 6, (XML_UnicodeBuffer__CharArray)i3, (XML_UnicodeBuffer__CharArray)i2, (XML_UnicodeBuffer__CharArray)(OOC_INT32)0, (URI__URI)i1, 0u);
  return (XML_DTD__ExternalEntity)i0;
  ;
}

XML_DTD__ExternalEntity XML_DTD__BuilderDesc_NewDocumentEntity(XML_DTD__Builder b, URI__URI baseURI) {
  register OOC_INT32 i0,i1;
  XML_DTD__ExternalEntity entity;

  i0 = (OOC_INT32)RT0__NewObject(_td_XML_DTD__ExternalEntity.baseTypes[0]);
  entity = (XML_DTD__ExternalEntity)i0;
  i1 = (OOC_INT32)baseURI;
  XML_DTD__InitExternalEntity((XML_DTD__ExternalEntity)i0, (XML_UnicodeBuffer__CharArray)(OOC_INT32)0, 5, (XML_UnicodeBuffer__CharArray)(OOC_INT32)0, (XML_UnicodeBuffer__CharArray)(OOC_INT32)0, (XML_UnicodeBuffer__CharArray)(OOC_INT32)0, (URI__URI)i1, 0u);
  *(OOC_INT8*)((_check_pointer(i0, 30928))+48) = 2;
  return (XML_DTD__ExternalEntity)i0;
  ;
}

static void XML_DTD__InitNotation(XML_DTD__Notation notation, XML_UnicodeBuffer__CharArray name, XML_UnicodeBuffer__CharArray _public, XML_UnicodeBuffer__CharArray system, URI__URI baseURI) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)name;
  i1 = (OOC_INT32)notation;
  XML_DTD__InitDeclaration((XML_DTD__Declaration)i1, (XML_UnicodeBuffer__CharArray)i0);
  i0 = (OOC_INT32)_public;
  *(OOC_INT32*)((_check_pointer(i1, 31255))+8) = i0;
  i0 = (OOC_INT32)system;
  *(OOC_INT32*)((_check_pointer(i1, 31287))+12) = i0;
  i0 = (OOC_INT32)baseURI;
  *(OOC_INT32*)((_check_pointer(i1, 31319))+16) = i0;
  return;
  ;
}

XML_DTD__Notation XML_DTD__BuilderDesc_NewNotation(XML_DTD__Builder b, XML_UnicodeBuffer__CharArray name, XML_UnicodeBuffer__CharArray _public, XML_UnicodeBuffer__CharArray system, URI__URI baseURI) {
  register OOC_INT32 i0,i1,i2,i3,i4;

  i0 = (OOC_INT32)RT0__NewObject(_td_XML_DTD__Notation.baseTypes[0]);
  i1 = (OOC_INT32)baseURI;
  i2 = (OOC_INT32)system;
  i3 = (OOC_INT32)_public;
  i4 = (OOC_INT32)name;
  XML_DTD__InitNotation((XML_DTD__Notation)i0, (XML_UnicodeBuffer__CharArray)i4, (XML_UnicodeBuffer__CharArray)i3, (XML_UnicodeBuffer__CharArray)i2, (URI__URI)i1);
  return (XML_DTD__Notation)i0;
  ;
}

static void XML_DTD__InitCP(XML_DTD__CP cp, OOC_INT8 cpMode) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)cp;
  i1 = cpMode;
  *(OOC_INT8*)(_check_pointer(i0, 31800)) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 31826))+4) = 0;
  return;
  ;
}

void XML_DTD__CPDesc_SetNext(XML_DTD__CP cp, XML_DTD__CP next) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)cp;
  i1 = (OOC_INT32)next;
  *(OOC_INT32*)((_check_pointer(i0, 31909))+4) = i1;
  return;
  ;
}

void XML_DTD__CPDesc_SetMode(XML_DTD__CP cp, OOC_INT8 cpMode) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)cp;
  i1 = cpMode;
  *(OOC_INT8*)(_check_pointer(i0, 32002)) = i1;
  return;
  ;
}

void XML_DTD__InitChoiceCP(XML_DTD__ChoiceCP choiceCP, OOC_INT8 cpMode, XML_DTD__CP list) {
  register OOC_INT32 i0,i1;

  i0 = cpMode;
  i1 = (OOC_INT32)choiceCP;
  XML_DTD__InitCP((XML_DTD__CP)i1, i0);
  i0 = (OOC_INT32)list;
  *(OOC_INT32*)((_check_pointer(i1, 32165))+8) = i0;
  return;
  ;
}

XML_DTD__ChoiceCP XML_DTD__BuilderDesc_NewChoiceCP(XML_DTD__Builder b, OOC_INT8 cpMode, XML_DTD__CP list) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_XML_DTD__ChoiceCP.baseTypes[0]);
  i1 = (OOC_INT32)list;
  i2 = cpMode;
  XML_DTD__InitChoiceCP((XML_DTD__ChoiceCP)i0, i2, (XML_DTD__CP)i1);
  return (XML_DTD__ChoiceCP)i0;
  ;
}

void XML_DTD__InitSeqCP(XML_DTD__SeqCP seqCP, OOC_INT8 cpMode, XML_DTD__CP list) {
  register OOC_INT32 i0,i1;

  i0 = cpMode;
  i1 = (OOC_INT32)seqCP;
  XML_DTD__InitCP((XML_DTD__CP)i1, i0);
  i0 = (OOC_INT32)list;
  *(OOC_INT32*)((_check_pointer(i1, 32532))+8) = i0;
  return;
  ;
}

XML_DTD__SeqCP XML_DTD__BuilderDesc_NewSeqCP(XML_DTD__Builder b, OOC_INT8 cpMode, XML_DTD__CP list) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_XML_DTD__SeqCP.baseTypes[0]);
  i1 = (OOC_INT32)list;
  i2 = cpMode;
  XML_DTD__InitSeqCP((XML_DTD__SeqCP)i0, i2, (XML_DTD__CP)i1);
  return (XML_DTD__SeqCP)i0;
  ;
}

void XML_DTD__InitNameCP(XML_DTD__NameCP nameCP, OOC_INT8 cpMode, XML_UnicodeBuffer__CharArray name) {
  register OOC_INT32 i0,i1;

  i0 = cpMode;
  i1 = (OOC_INT32)nameCP;
  XML_DTD__InitCP((XML_DTD__CP)i1, i0);
  i0 = (OOC_INT32)name;
  *(OOC_INT32*)((_check_pointer(i1, 32878))+8) = i0;
  return;
  ;
}

XML_DTD__NameCP XML_DTD__BuilderDesc_NewNameCP(XML_DTD__Builder b, OOC_INT8 cpMode, XML_UnicodeBuffer__CharArray name) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_XML_DTD__NameCP.baseTypes[0]);
  i1 = (OOC_INT32)name;
  i2 = cpMode;
  XML_DTD__InitNameCP((XML_DTD__NameCP)i0, i2, (XML_UnicodeBuffer__CharArray)i1);
  return (XML_DTD__NameCP)i0;
  ;
}

void XML_DTD__InitElementDecl(XML_DTD__ElementDecl elemDecl, XML_UnicodeBuffer__CharArray name, XML_DTD__CP contentModel, XML_DTD__Namespace attrNamespace, OOC_CHAR8 externalMarkupDecl) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)name;
  i1 = (OOC_INT32)elemDecl;
  XML_DTD__InitDeclaration((XML_DTD__Declaration)i1, (XML_UnicodeBuffer__CharArray)i0);
  i0 = (OOC_INT32)contentModel;
  *(OOC_INT32*)((_check_pointer(i1, 33315))+8) = i0;
  *(OOC_INT8*)((_check_pointer(i1, 33359))+16) = 1;
  *(OOC_INT32*)((_check_pointer(i1, 33400))+12) = (OOC_INT32)0;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 33438))+8);
  i2 = i2!=(OOC_INT32)0;
  if (!i2) goto l27;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33488)))), &_td_XML_DTD__NameCPDesc);
  if (i2) goto l17;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33841)))), &_td_XML_DTD__ChoiceCPDesc);
  if (i2) goto l7;
  *(OOC_INT8*)((_check_pointer(i1, 34114))+16) = 3;
  goto l27;
l7:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33879))+8);
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 33886)))), &_td_XML_DTD__NameCPDesc);
  if (i2) goto l10;
  i0=0u;
  goto l12;
l10:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33923))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33930)))), &_td_XML_DTD__NameCPDesc, 33930)), 33937))+8);
  i0 = (
  _cmp16((const void*)(_check_pointer(i0, 33943)),(const void*)((OOC_CHAR16[]){35,80,67,68,65,84,65,0})))==0;
  
l12:
  if (i0) goto l14;
  *(OOC_INT8*)((_check_pointer(i1, 34042))+16) = 3;
  goto l27;
l14:
  *(OOC_INT8*)((_check_pointer(i1, 33981))+16) = 2;
  goto l27;
l17:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33524))+8);
  i2 = (
  _cmp16((const void*)(_check_pointer(i2, 33530)),(const void*)((OOC_CHAR16[]){69,77,80,84,89,0})))==0;
  if (i2) goto l24;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33623))+8);
  i0 = (
  _cmp16((const void*)(_check_pointer(i0, 33629)),(const void*)((OOC_CHAR16[]){65,78,89,0})))==0;
  if (i0) goto l22;
  *(OOC_INT8*)((_check_pointer(i1, 33722))+16) = 1;
  goto l27;
l22:
  *(OOC_INT8*)((_check_pointer(i1, 33663))+16) = 1;
  goto l27;
l24:
  *(OOC_INT8*)((_check_pointer(i1, 33566))+16) = 0;
l27:
  i0 = externalMarkupDecl;
  *(OOC_UINT8*)((_check_pointer(i1, 34178))+17) = i0;
  *(OOC_UINT8*)((_check_pointer(i1, 34234))+18) = 0u;
  i0 = (OOC_INT32)attrNamespace;
  *(OOC_INT32*)((_check_pointer(i1, 34271))+20) = i0;
  *(OOC_INT32*)((_check_pointer(i1, 34317))+24) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i1, 34346))+28) = (OOC_INT32)0;
  return;
  ;
}

XML_DTD__ElementDecl XML_DTD__BuilderDesc_NewElementDecl(XML_DTD__Builder b, XML_UnicodeBuffer__CharArray name, XML_DTD__CP contentModel, OOC_CHAR8 externalMarkupDecl) {
  register OOC_INT32 i0,i1,i2,i3,i4;

  i0 = (OOC_INT32)RT0__NewObject(_td_XML_DTD__ElementDecl.baseTypes[0]);
  i1 = (OOC_INT32)XML_DTD__NewNamespace();
  i2 = (OOC_INT32)name;
  i3 = (OOC_INT32)contentModel;
  i4 = externalMarkupDecl;
  XML_DTD__InitElementDecl((XML_DTD__ElementDecl)i0, (XML_UnicodeBuffer__CharArray)i2, (XML_DTD__CP)i3, (XML_DTD__Namespace)i1, i4);
  return (XML_DTD__ElementDecl)i0;
  ;
}

void XML_DTD__ElementDeclDesc_SetRegexp(XML_DTD__ElementDecl elemDecl, XML_DTD__RegexpInfo regexp) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)elemDecl;
  i1 = (OOC_INT32)regexp;
  *(OOC_INT32*)((_check_pointer(i0, 34787))+12) = i1;
  return;
  ;
}

void XML_DTD__ElementDeclDesc_SetMultipleDecl(XML_DTD__ElementDecl elemDecl) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)elemDecl;
  *(OOC_UINT8*)((_check_pointer(i0, 34896))+18) = 1u;
  return;
  ;
}

OOC_CHAR8 XML_DTD__ElementDeclDesc_IsEmpty(XML_DTD__ElementDecl elemDecl) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)elemDecl;
  i0 = *(OOC_INT8*)((_check_pointer(i0, 35027))+16);
  return (i0==0);
  ;
}

OOC_CHAR8 XML_DTD__ElementDeclDesc_IsElementContent(XML_DTD__ElementDecl elemDecl) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)elemDecl;
  i0 = *(OOC_INT8*)((_check_pointer(i0, 35166))+16);
  return (i0==3);
  ;
}

void XML_DTD__BuilderDesc_SetRootName(XML_DTD__Builder b, XML_UnicodeBuffer__CharArray name) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)name;
  *(OOC_INT32*)(_check_pointer(i0, 35379)) = i1;
  return;
  ;
}

static void XML_DTD__InitNamespaceDeclaration(XML_DTD__NamespaceDeclaration namespaceDecl, XML_UnicodeBuffer__CharArray prefix, XML_DTD__StringURI uri) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)namespaceDecl;
  i1 = (OOC_INT32)prefix;
  *(OOC_INT32*)(_check_pointer(i0, 35691)) = i1;
  i1 = (OOC_INT32)uri;
  *(OOC_INT32*)((_check_pointer(i0, 35728))+4) = i1;
  return;
  ;
}

XML_DTD__NamespaceDeclaration XML_DTD__NewNamespaceDeclaration(XML_UnicodeBuffer__CharArray prefix, XML_DTD__StringURI uri) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_XML_DTD__NamespaceDeclaration.baseTypes[0]);
  i1 = (OOC_INT32)uri;
  i2 = (OOC_INT32)prefix;
  XML_DTD__InitNamespaceDeclaration((XML_DTD__NamespaceDeclaration)i0, (XML_UnicodeBuffer__CharArray)i2, (XML_DTD__StringURI)i1);
  return (XML_DTD__NamespaceDeclaration)i0;
  ;
}

XML_UnicodeBuffer__CharArray XML_DTD__GetString(OOC_CHAR16 string[], OOC_LEN string_0d, OOC_INT32 start, OOC_INT32 end) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  XML_UnicodeBuffer__CharArray s;
  OOC_INT32 i;

  i0 = end;
  i1 = start;
  i0 = i0-i1;
  i2 = (OOC_INT32)RT0__NewObject(_td_XML_UnicodeBuffer__CharArray.baseTypes[0], (i0+1));
  s = (XML_UnicodeBuffer__CharArray)i2;
  i = 0;
  i3 = 0<i0;
  if (!i3) goto l8;
  i3=i1;i1=0;
l3_loop:
  i4 = _check_pointer(i2, 36332);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = *(OOC_UINT16*)((OOC_INT32)string+(_check_index(i3, string_0d, OOC_UINT32, 36345))*2);
  *(OOC_UINT16*)(i4+(_check_index(i1, i5, OOC_UINT32, 36332))*2) = i6;
  i1 = i1+1;
  i = i1;
  i3 = i3+1;
  i4 = i1<i0;
  if (i4) goto l3_loop;
l8:
  i1 = _check_pointer(i2, 36369);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  *(OOC_UINT16*)(i1+(_check_index(i0, i3, OOC_UINT32, 36369))*2) = 0u;
  return (XML_UnicodeBuffer__CharArray)i2;
  ;
}

XML_UnicodeBuffer__CharArray XML_DTD__GetStringValue(const OOC_CHAR16 string__ref[], OOC_LEN string_0d) {
  register OOC_INT32 i0;
  OOC_ALLOCATE_VPAR(string,OOC_CHAR16 ,string_0d)

  OOC_INITIALIZE_VPAR(string__ref,string,OOC_CHAR16 ,(string_0d*2))
  i0 = LongStrings__Length((void*)(OOC_INT32)string, string_0d);
  i0 = (OOC_INT32)XML_DTD__GetString((void*)(OOC_INT32)string, string_0d, 0, i0);
  return (XML_UnicodeBuffer__CharArray)i0;
  ;
}

XML_DTD__StringURI XML_DTD__GetStringURI(OOC_CHAR8 string[], OOC_LEN string_0d, OOC_INT32 start, OOC_INT32 end) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  XML_DTD__StringURI s;
  OOC_INT32 i;

  i0 = end;
  i1 = start;
  i0 = i0-i1;
  i2 = (OOC_INT32)RT0__NewObject(_td_XML_DTD__StringURI.baseTypes[0], (i0+1));
  s = (XML_DTD__StringURI)i2;
  i = 0;
  i3 = 0<i0;
  if (!i3) goto l8;
  i3=i1;i1=0;
l3_loop:
  i4 = _check_pointer(i2, 36770);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = *(OOC_UINT8*)((OOC_INT32)string+(_check_index(i3, string_0d, OOC_UINT32, 36783)));
  *(OOC_UINT8*)(i4+(_check_index(i1, i5, OOC_UINT32, 36770))) = i6;
  i1 = i1+1;
  i = i1;
  i3 = i3+1;
  i4 = i1<i0;
  if (i4) goto l3_loop;
l8:
  i1 = _check_pointer(i2, 36807);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  *(OOC_UINT8*)(i1+(_check_index(i0, i3, OOC_UINT32, 36807))) = 0u;
  return (XML_DTD__StringURI)i2;
  ;
}

void XML_DTD__Init(XML_DTD__Builder b) {
  register OOC_INT32 i0,i1;
  auto void XML_DTD__Init_PredefEntity(const OOC_CHAR16 name__ref[], OOC_LEN name_0d, const OOC_CHAR16 replacement__ref[], OOC_LEN replacement_0d);
    
    void XML_DTD__Init_PredefEntity(const OOC_CHAR16 name__ref[], OOC_LEN name_0d, const OOC_CHAR16 replacement__ref[], OOC_LEN replacement_0d) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      OOC_ALLOCATE_VPAR(name,OOC_CHAR16 ,name_0d)
      OOC_ALLOCATE_VPAR(replacement,OOC_CHAR16 ,replacement_0d)
      XML_UnicodeBuffer__CharArray nameString;
      XML_UnicodeBuffer__CharArray replString;
      XML_DTD__Entity entity;

      OOC_INITIALIZE_VPAR(name__ref,name,OOC_CHAR16 ,(name_0d*2))
      OOC_INITIALIZE_VPAR(replacement__ref,replacement,OOC_CHAR16 ,(replacement_0d*2))
      i0 = LongStrings__Length((void*)(OOC_INT32)name, name_0d);
      i0 = (OOC_INT32)RT0__NewObject(_td_XML_UnicodeBuffer__CharArray.baseTypes[0], (i0+1));
      nameString = (XML_UnicodeBuffer__CharArray)i0;
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 37287)), 0);
      _copy_16((const void*)(OOC_INT32)name,(void*)(_check_pointer(i0, 37287)),i1);
      i1 = LongStrings__Length((void*)(OOC_INT32)replacement, replacement_0d);
      i1 = (OOC_INT32)RT0__NewObject(_td_XML_UnicodeBuffer__CharArray.baseTypes[0], (i1+2));
      replString = (XML_UnicodeBuffer__CharArray)i1;
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i1, 37386)), 0);
      _copy_16((const void*)(OOC_INT32)replacement,(void*)(_check_pointer(i1, 37386)),i2);
      i2 = _check_pointer(i1, 37406);
      i3 = OOC_ARRAY_LENGTH((_check_pointer(i1, 37422)), 0);
      i4 = OOC_ARRAY_LENGTH(i2, 0);
      *(OOC_UINT16*)(i2+(_check_index((i3-2), i4, OOC_UINT32, 37406))*2) = 65535u;
      i2 = (OOC_INT32)b;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 37480)))), XML_DTD__BuilderDesc_NewInternalEntity)),XML_DTD__BuilderDesc_NewInternalEntity)((XML_DTD__Builder)i2, (XML_UnicodeBuffer__CharArray)i0, 0, (XML_UnicodeBuffer__CharArray)i1, 0u);
      entity = (XML_DTD__Entity)i0;
      i1 = (OOC_INT32)b;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 37611))+4);
      i0 = XML_DTD__NamespaceDesc_Add((XML_DTD__Namespace)i1, (XML_DTD__Declaration)i0);
      return;
      ;
    }


  i0 = (OOC_INT32)b;
  *(OOC_INT32*)(_check_pointer(i0, 37677)) = 0;
  i1 = (OOC_INT32)XML_DTD__NewNamespace();
  *(OOC_INT32*)((_check_pointer(i0, 37701))+4) = i1;
  i1 = (OOC_INT32)XML_DTD__NewNamespace();
  *(OOC_INT32*)((_check_pointer(i0, 37739))+8) = i1;
  i1 = (OOC_INT32)XML_DTD__NewNamespace();
  *(OOC_INT32*)((_check_pointer(i0, 37777))+12) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 37825))+16) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 37854))+20) = 0;
  XML_DTD__Init_PredefEntity(((OOC_CHAR16[]){108,116,0}), 3, ((OOC_CHAR16[]){38,35,54,48,59,0}), 6);
  XML_DTD__Init_PredefEntity(((OOC_CHAR16[]){103,116,0}), 3, ((OOC_CHAR16[]){62,0}), 2);
  XML_DTD__Init_PredefEntity(((OOC_CHAR16[]){97,109,112,0}), 4, ((OOC_CHAR16[]){38,35,51,56,59,0}), 6);
  XML_DTD__Init_PredefEntity(((OOC_CHAR16[]){97,112,111,115,0}), 5, ((OOC_CHAR16[]){39,0}), 2);
  XML_DTD__Init_PredefEntity(((OOC_CHAR16[]){113,117,111,116,0}), 5, ((OOC_CHAR16[]){34,0}), 2);
  return;
  ;
}

XML_DTD__Builder XML_DTD__New(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)RT0__NewObject(_td_XML_DTD__Builder.baseTypes[0]);
  XML_DTD__Init((XML_DTD__Builder)i0);
  return (XML_DTD__Builder)i0;
  ;
}

void OOC_XML_DTD_init(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)RT0__NewObject(_td_XML_DTD__AttrDecl.baseTypes[0]);
  XML_DTD__undefAttr = (XML_DTD__AttrDecl)i0;
  XML_DTD__InitAttrDecl((XML_DTD__AttrDecl)i0, (XML_UnicodeBuffer__CharArray)(OOC_INT32)0, (XML_UnicodeBuffer__CharArray)(OOC_INT32)0, (-1), (XML_DTD__Enumeration)(OOC_INT32)0, (-1), (XML_DTD__AttValue)(OOC_INT32)0, 0u);
  return;
  ;
}

/* --- */
