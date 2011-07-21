#include <XML/UnicodeCodec.d>
#include <__oo2c.h>
#include <setjmp.h>

void XML_UnicodeCodec__Init(XML_UnicodeCodec__Codec codec, OOC_INT8 bom) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)codec;
  *(OOC_INT32*)(_check_pointer(i0, 3290)) = 0;
  i1 = bom;
  *(OOC_INT8*)((_check_pointer(i0, 3320))+4) = i1;
  return;
  ;
}

void XML_UnicodeCodec__CodecDesc_Decode(XML_UnicodeCodec__Codec codec, OOC_CHAR8 source[], OOC_LEN source_0d, OOC_INT32 sourceStart, OOC_INT32 sourceEnd, OOC_CHAR16 dest[], OOC_LEN dest_0d, OOC_INT32 destStart, OOC_INT32 destEnd, OOC_INT32 *sourceDone, OOC_INT32 *destDone) {

  return;
  ;
}

void XML_UnicodeCodec__CodecDesc_Encode(XML_UnicodeCodec__Codec codec, OOC_CHAR16 source[], OOC_LEN source_0d, OOC_INT32 sourceStart, OOC_INT32 sourceEnd, OOC_CHAR8 dest[], OOC_LEN dest_0d, OOC_INT32 destStart, OOC_INT32 destEnd, OOC_INT32 *sourceDone, OOC_INT32 *destDone) {

  return;
  ;
}

void XML_UnicodeCodec__CodecDesc_EncodeBOM(XML_UnicodeCodec__Codec codec, OOC_CHAR8 dest[], OOC_LEN dest_0d, OOC_INT32 destStart, OOC_INT32 destEnd, OOC_INT32 *destDone) {
  register OOC_INT32 i0,i1,i2;
  OOC_CHAR16 source[2];
  OOC_INT32 sourceDone;

  i0 = (OOC_INT32)codec;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 11753))+4);
  i1 = i1==0;
  if (i1) goto l3;
  _copy_16((const void*)((OOC_CHAR16[]){65279,0}),(void*)(OOC_INT32)source,2);
  i1 = destEnd;
  i2 = destStart;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11863)))), XML_UnicodeCodec__CodecDesc_Encode)),XML_UnicodeCodec__CodecDesc_Encode)((XML_UnicodeCodec__Codec)i0, (void*)(OOC_INT32)source, 2, 0, 1, (void*)(OOC_INT32)dest, dest_0d, i2, i1, (void*)(OOC_INT32)&sourceDone, (void*)(OOC_INT32)destDone);
  i0 = sourceDone;
  _assert((i0==1), 127, 11963);
  goto l4;
l3:
  i0 = destStart;
  *destDone = i0;
l4:
  return;
  ;
}

void XML_UnicodeCodec__InitFactory(XML_UnicodeCodec__Factory f, OOC_INT8 bom) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)f;
  i1 = bom;
  *(OOC_INT8*)(_check_pointer(i0, 12170)) = i1;
  return;
  ;
}

XML_UnicodeCodec__Codec XML_UnicodeCodec__FactoryDesc_NewCodec(XML_UnicodeCodec__Factory f) {

  _failed_function(12237); return 0;
  ;
}

XML_UnicodeCodec__Codec XML_UnicodeCodec__FactoryDesc_NewCodecBOM(XML_UnicodeCodec__Factory f, OOC_CHAR8 source[], OOC_LEN source_0d, OOC_INT32 sourceStart, OOC_INT32 sourceEnd, OOC_INT32 *sourceDone) {

  _failed_function(12486); return 0;
  ;
}

void XML_UnicodeCodec__FactoryDesc_GetEncodingName(XML_UnicodeCodec__Factory f, OOC_CHAR8 name[], OOC_LEN name_0d) {

  return;
  ;
}

void XML_UnicodeCodec__Register(const OOC_CHAR8 name__ref[], OOC_LEN name_0d, XML_UnicodeCodec__Factory factory) {
  OOC_ALLOCATE_VPAR(name,OOC_CHAR8 ,name_0d)
  auto void XML_UnicodeCodec__Register_ScanList(XML_UnicodeCodec__Node *l);
    
    void XML_UnicodeCodec__Register_ScanList(XML_UnicodeCodec__Node *l) {
      register OOC_INT32 i0,i1,i2;

      i0 = (OOC_INT32)*l;
      i1 = i0==(OOC_INT32)0;
      if (i1) goto l7;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14721))+4);
      i1 = (
      _cmp8((const void*)(_check_pointer(i1, 14727)),(const void*)(OOC_INT32)name))==0;
      if (i1) goto l5;
      XML_UnicodeCodec__Register_ScanList((void*)(_check_pointer(i0, 14802)));
      goto l8;
l5:
      i1 = (OOC_INT32)factory;
      *(OOC_INT32*)((_check_pointer(i0, 14751))+8) = i1;
      goto l8;
l7:
      i0 = (OOC_INT32)RT0__NewObject(_td_XML_UnicodeCodec__Node.baseTypes[0]);
      *l = (XML_UnicodeCodec__Node)i0;
      i1 = Strings__Length((void*)(OOC_INT32)name, name_0d);
      *(OOC_INT32*)((_check_pointer(i0, 14588))+4) = ((OOC_INT32)RT0__NewObject(_td_XML_UnicodeCodec__3139.baseTypes[0], (i1+1)));
      i0 = (OOC_INT32)*l;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14643))+4);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14643))+4);
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 14649)), 0);
      _copy_8((const void*)(OOC_INT32)name,(void*)(_check_pointer(i1, 14649)),i2);
      i1 = (OOC_INT32)factory;
      *(OOC_INT32*)((_check_pointer(i0, 14662))+8) = i1;
      i0 = (OOC_INT32)*l;
      *(OOC_INT32*)(_check_pointer(i0, 14693)) = (OOC_INT32)0;
l8:
      return;
      ;
    }


  OOC_INITIALIZE_VPAR(name__ref,name,OOC_CHAR8 ,name_0d)
  Strings__Capitalize((void*)(OOC_INT32)name, name_0d);
  XML_UnicodeCodec__Register_ScanList((void*)(OOC_INT32)&XML_UnicodeCodec__factoryList);
  return;
  ;
}

void XML_UnicodeCodec__Unregister(const OOC_CHAR8 name__ref[], OOC_LEN name_0d) {
  OOC_ALLOCATE_VPAR(name,OOC_CHAR8 ,name_0d)
  auto void XML_UnicodeCodec__Unregister_ScanList(XML_UnicodeCodec__Node *l);
    
    void XML_UnicodeCodec__Unregister_ScanList(XML_UnicodeCodec__Node *l) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)*l;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l7;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15234))+4);
      i1 = (
      _cmp8((const void*)(_check_pointer(i1, 15240)),(const void*)(OOC_INT32)name))==0;
      if (i1) goto l5;
      XML_UnicodeCodec__Unregister_ScanList((void*)(_check_pointer(i0, 15312)));
      goto l7;
l5:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 15271));
      *l = (XML_UnicodeCodec__Node)i0;
l7:
      return;
      ;
    }


  OOC_INITIALIZE_VPAR(name__ref,name,OOC_CHAR8 ,name_0d)
  Strings__Capitalize((void*)(OOC_INT32)name, name_0d);
  XML_UnicodeCodec__Unregister_ScanList((void*)(OOC_INT32)&XML_UnicodeCodec__factoryList);
  return;
  ;
}

XML_UnicodeCodec__Factory XML_UnicodeCodec__GetFactory(const OOC_CHAR8 name__ref[], OOC_LEN name_0d) {
  register OOC_INT32 i0,i1;
  OOC_ALLOCATE_VPAR(name,OOC_CHAR8 ,name_0d)
  XML_UnicodeCodec__Node n;

  OOC_INITIALIZE_VPAR(name__ref,name,OOC_CHAR8 ,name_0d)
  Strings__Capitalize((void*)(OOC_INT32)name, name_0d);
  i0 = (OOC_INT32)XML_UnicodeCodec__factoryList;
  n = (XML_UnicodeCodec__Node)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15745))+4);
  i1 = (
  _cmp8((const void*)(_check_pointer(i1, 15751)),(const void*)(OOC_INT32)name))!=0;
  
l5:
  if (!i1) goto l17;
l8_loop:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 15776));
  n = (XML_UnicodeCodec__Node)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l11;
  i1=0u;
  goto l13;
l11:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15745))+4);
  i1 = (
  _cmp8((const void*)(_check_pointer(i1, 15751)),(const void*)(OOC_INT32)name))!=0;
  
l13:
  if (i1) goto l8_loop;
l17:
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l20;
  return (XML_UnicodeCodec__Factory)(OOC_INT32)0;
  goto l21;
l20:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15828))+8);
  return (XML_UnicodeCodec__Factory)i0;
l21:
  _failed_function(15458); return 0;
  ;
}

void OOC_XML_UnicodeCodec_init(void) {

  XML_UnicodeCodec__factoryList = (XML_UnicodeCodec__Node)(OOC_INT32)0;
  return;
  ;
}

void OOC_XML_UnicodeCodec_destroy(void) {
}

/* --- */
