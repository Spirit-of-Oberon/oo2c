#include <XML/UnicodeCodec/Latin1.d>
#include <__oo2c.h>
#include <setjmp.h>

static void XML_UnicodeCodec_Latin1__Init(XML_UnicodeCodec_Latin1__Codec codec, OOC_INT8 bom) {
  register OOC_INT32 i0,i1;

  i0 = bom;
  i1 = (OOC_INT32)codec;
  XML_UnicodeCodec__Init((XML_UnicodeCodec__Codec)i1, i0);
  return;
  ;
}

static XML_UnicodeCodec_Latin1__Codec XML_UnicodeCodec_Latin1__New(OOC_INT8 bom) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)RT0__NewObject(_td_XML_UnicodeCodec_Latin1__Codec.baseTypes[0]);
  i1 = bom;
  XML_UnicodeCodec_Latin1__Init((XML_UnicodeCodec_Latin1__Codec)i0, i1);
  return (XML_UnicodeCodec_Latin1__Codec)i0;
  ;
}

void XML_UnicodeCodec_Latin1__CodecDesc_Decode(XML_UnicodeCodec_Latin1__Codec codec, OOC_CHAR8 source[], OOC_LEN source_0d, OOC_INT32 sourceStart, OOC_INT32 sourceEnd, OOC_CHAR16 dest[], OOC_LEN dest_0d, OOC_INT32 destStart, OOC_INT32 destEnd, OOC_INT32 *sourceDone, OOC_INT32 *destDone) {
  register OOC_INT32 i0,i1,i2,i3,i4;

  i0 = sourceEnd;
  i1 = sourceStart;
  i2 = destEnd;
  i3 = destStart;
  i2 = i2-i3;
  i4 = (i0-i1)>i2;
  if (!i4) goto l4;
  i0 = i2+i1;
  
l4:
  i2 = i1!=i0;
  if (i2) goto l7;
  i0=i1;i1=i3;
  goto l13;
l7:
  i2=i1;i1=i3;
l8_loop:
  i3 = *(OOC_UINT8*)((OOC_INT32)source+(_check_index(i2, source_0d, OOC_UINT32, 1323)));
  *(OOC_UINT16*)((OOC_INT32)dest+(_check_index(i1, dest_0d, OOC_UINT32, 1302))*2) = i3;
  i2 = i2+1;
  i1 = i1+1;
  i3 = i2!=i0;
  if (i3) goto l8_loop;
l12:
  i0=i2;
l13:
  *sourceDone = i0;
  *destDone = i1;
  return;
  ;
}

void XML_UnicodeCodec_Latin1__CodecDesc_Encode(XML_UnicodeCodec_Latin1__Codec codec, OOC_CHAR16 source[], OOC_LEN source_0d, OOC_INT32 sourceStart, OOC_INT32 sourceEnd, OOC_CHAR8 dest[], OOC_LEN dest_0d, OOC_INT32 destStart, OOC_INT32 destEnd, OOC_INT32 *sourceDone, OOC_INT32 *destDone) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_INT32 testSourceEnd;
  OOC_INT32 i;
  OOC_INT32 j;

  i0 = sourceEnd;
  i0 = i0-1;
  testSourceEnd = i0;
  i1 = sourceStart;
  i = i1;
  i2 = destStart;
  j = i2;
  i3 = i1<i0;
  if (i3) goto l3;
  i3=0u;
  goto l5;
l3:
  i3 = destEnd;
  i3 = i2!=i3;
  
l5:
  if (i3) goto l7;
  i0=i1;
  goto l37;
l7:
  i3 = destEnd;
  i4 = (OOC_INT32)codec;
  i5=i2;i2=i1;
l8_loop:
  i6 = *(OOC_UINT16*)((OOC_INT32)source+(_check_index(i2, source_0d, OOC_UINT32, 2214))*2);
  i6 = (OOC_UINT16)i6>(OOC_UINT16)255u;
  if (i6) goto l11;
  i6 = *(OOC_UINT16*)((OOC_INT32)source+(_check_index(i2, source_0d, OOC_UINT32, 2582))*2);
  *(OOC_UINT8*)((OOC_INT32)dest+(_check_index(i5, dest_0d, OOC_UINT32, 2562))) = i6;
  i2 = i2+1;
  i = i2;
  
  goto l28;
l11:
  i6 = *(OOC_INT32*)(_check_pointer(i4, 2249));
  *(OOC_INT32*)(_check_pointer(i4, 2249)) = (i6+1);
  *(OOC_UINT8*)((OOC_INT32)dest+(_check_index(i5, dest_0d, OOC_UINT32, 2278))) = 63u;
  i6 = *(OOC_UINT16*)((OOC_INT32)source+(_check_index(i2, source_0d, OOC_UINT32, 2329))*2);
  i6 = (OOC_UINT16)55296u<=(OOC_UINT16)i6;
  if (i6) goto l14;
  i6=0u;
  goto l16;
l14:
  i6 = *(OOC_UINT16*)((OOC_INT32)source+(_check_index(i2, source_0d, OOC_UINT32, 2343))*2);
  i6 = (OOC_UINT16)i6<(OOC_UINT16)56320u;
  
l16:
  if (i6) goto l18;
  i6=0u;
  goto l20;
l18:
  i6 = *(OOC_UINT16*)((OOC_INT32)source+(_check_index((i2+1), source_0d, OOC_UINT32, 2387))*2);
  i6 = (OOC_UINT16)56320u<=(OOC_UINT16)i6;
  
l20:
  if (i6) goto l22;
  i6=0u;
  goto l24;
l22:
  i6 = *(OOC_UINT16*)((OOC_INT32)source+(_check_index((i2+1), source_0d, OOC_UINT32, 2403))*2);
  i6 = (OOC_UINT16)i6<(OOC_UINT16)57344u;
  
l24:
  if (i6) goto l26;
  i2 = i2+1;
  i = i2;
  
  goto l28;
l26:
  i2 = i2+2;
  i = i2;
  
l28:
  i5 = i5+1;
  j = i5;
  i6 = i2<i0;
  if (i6) goto l31;
  i6=0u;
  goto l33;
l31:
  i6 = i5!=i3;
  
l33:
  if (i6) goto l8_loop;
l36:
  i0=i2;i2=i5;
l37:
  i1 = i0==i1;
  if (i1) goto l40;
  i1=i2;
  goto l45;
l40:
  i1 = *(OOC_UINT16*)((OOC_INT32)source+(_check_index(i0, source_0d, OOC_UINT32, 2941))*2);
  i1 = (OOC_UINT16)i1<(OOC_UINT16)256u;
  if (i1) goto l43;
  i1 = (OOC_INT32)codec;
  i3 = *(OOC_INT32*)(_check_pointer(i1, 3092));
  *(OOC_INT32*)(_check_pointer(i1, 3092)) = (i3+1);
  *(OOC_UINT8*)((OOC_INT32)dest+(_check_index(i2, dest_0d, OOC_UINT32, 3121))) = 63u;
  goto l44;
l43:
  i1 = *(OOC_UINT16*)((OOC_INT32)source+(_check_index(i0, source_0d, OOC_UINT32, 2990))*2);
  *(OOC_UINT8*)((OOC_INT32)dest+(_check_index(i2, dest_0d, OOC_UINT32, 2970))) = i1;
l44:
  i1 = i2+1;
  i0 = i0+1;
  
l45:
  *sourceDone = i0;
  *destDone = i1;
  return;
  ;
}

static void XML_UnicodeCodec_Latin1__InitFactory(XML_UnicodeCodec_Latin1__Factory f) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)f;
  XML_UnicodeCodec__InitFactory((XML_UnicodeCodec__Factory)i0, 0);
  return;
  ;
}

XML_UnicodeCodec_Latin1__Codec XML_UnicodeCodec_Latin1__FactoryDesc_NewCodec(XML_UnicodeCodec_Latin1__Factory f) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)f;
  i0 = *(OOC_INT8*)(_check_pointer(i0, 3414));
  i0 = (OOC_INT32)XML_UnicodeCodec_Latin1__New(i0);
  return (XML_UnicodeCodec_Latin1__Codec)i0;
  ;
}

XML_UnicodeCodec_Latin1__Codec XML_UnicodeCodec_Latin1__FactoryDesc_NewCodecBOM(XML_UnicodeCodec_Latin1__Factory f, OOC_CHAR8 source[], OOC_LEN source_0d, OOC_INT32 sourceStart, OOC_INT32 sourceEnd, OOC_INT32 *sourceDone) {
  register OOC_INT32 i0;

  i0 = sourceStart;
  *sourceDone = i0;
  i0 = (OOC_INT32)f;
  i0 = *(OOC_INT8*)(_check_pointer(i0, 3692));
  i0 = (OOC_INT32)XML_UnicodeCodec_Latin1__New(i0);
  return (XML_UnicodeCodec_Latin1__Codec)i0;
  ;
}

void XML_UnicodeCodec_Latin1__FactoryDesc_GetEncodingName(XML_UnicodeCodec_Latin1__Factory f, OOC_CHAR8 name[], OOC_LEN name_0d) {

  _copy_8((const void*)"ISO-8859-1",(void*)(OOC_INT32)name,name_0d);
  return;
  ;
}

void OOC_XML_UnicodeCodec_Latin1_init(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)RT0__NewObject(_td_XML_UnicodeCodec_Latin1__Factory.baseTypes[0]);
  XML_UnicodeCodec_Latin1__factory = (XML_UnicodeCodec_Latin1__Factory)i0;
  XML_UnicodeCodec_Latin1__InitFactory((XML_UnicodeCodec_Latin1__Factory)i0);
  i0 = (OOC_INT32)XML_UnicodeCodec_Latin1__factory;
  XML_UnicodeCodec__Register("ISO_8859-1:1987", 16, (XML_UnicodeCodec__Factory)i0);
  i0 = (OOC_INT32)XML_UnicodeCodec_Latin1__factory;
  XML_UnicodeCodec__Register("iso-ir-100", 11, (XML_UnicodeCodec__Factory)i0);
  i0 = (OOC_INT32)XML_UnicodeCodec_Latin1__factory;
  XML_UnicodeCodec__Register("ISO_8859-1", 11, (XML_UnicodeCodec__Factory)i0);
  i0 = (OOC_INT32)XML_UnicodeCodec_Latin1__factory;
  XML_UnicodeCodec__Register("ISO-8859-1", 11, (XML_UnicodeCodec__Factory)i0);
  i0 = (OOC_INT32)XML_UnicodeCodec_Latin1__factory;
  XML_UnicodeCodec__Register("latin1", 7, (XML_UnicodeCodec__Factory)i0);
  i0 = (OOC_INT32)XML_UnicodeCodec_Latin1__factory;
  XML_UnicodeCodec__Register("l1", 3, (XML_UnicodeCodec__Factory)i0);
  i0 = (OOC_INT32)XML_UnicodeCodec_Latin1__factory;
  XML_UnicodeCodec__Register("IBM819", 7, (XML_UnicodeCodec__Factory)i0);
  i0 = (OOC_INT32)XML_UnicodeCodec_Latin1__factory;
  XML_UnicodeCodec__Register("CP819", 6, (XML_UnicodeCodec__Factory)i0);
  i0 = (OOC_INT32)XML_UnicodeCodec_Latin1__factory;
  XML_UnicodeCodec__Register("csISOLatin1", 12, (XML_UnicodeCodec__Factory)i0);
  return;
  ;
}

/* --- */
