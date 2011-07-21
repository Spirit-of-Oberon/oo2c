#include <XML/UnicodeCodec/UTF16.d>
#include <__oo2c.h>
#include <setjmp.h>

static void XML_UnicodeCodec_UTF16__InitBE(XML_UnicodeCodec_UTF16__Codec codec, OOC_INT8 bom) {
  register OOC_INT32 i0,i1;

  i0 = bom;
  i1 = (OOC_INT32)codec;
  XML_UnicodeCodec__Init((XML_UnicodeCodec__Codec)i1, i0);
  *(OOC_UINT8*)((_check_pointer(i1, 1002))+8) = 1u;
  return;
  ;
}

static XML_UnicodeCodec_UTF16__Codec XML_UnicodeCodec_UTF16__NewBE(OOC_INT8 bom) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)RT0__NewObject(_td_XML_UnicodeCodec_UTF16__Codec.baseTypes[0]);
  i1 = bom;
  XML_UnicodeCodec_UTF16__InitBE((XML_UnicodeCodec_UTF16__Codec)i0, i1);
  return (XML_UnicodeCodec_UTF16__Codec)i0;
  ;
}

static void XML_UnicodeCodec_UTF16__InitLE(XML_UnicodeCodec_UTF16__Codec codec, OOC_INT8 bom) {
  register OOC_INT32 i0,i1;

  i0 = bom;
  i1 = (OOC_INT32)codec;
  XML_UnicodeCodec__Init((XML_UnicodeCodec__Codec)i1, i0);
  *(OOC_UINT8*)((_check_pointer(i1, 1257))+8) = 0u;
  return;
  ;
}

static XML_UnicodeCodec_UTF16__Codec XML_UnicodeCodec_UTF16__NewLE(OOC_INT8 bom) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)RT0__NewObject(_td_XML_UnicodeCodec_UTF16__Codec.baseTypes[0]);
  i1 = bom;
  XML_UnicodeCodec_UTF16__InitLE((XML_UnicodeCodec_UTF16__Codec)i0, i1);
  return (XML_UnicodeCodec_UTF16__Codec)i0;
  ;
}

void XML_UnicodeCodec_UTF16__CodecDesc_Decode(XML_UnicodeCodec_UTF16__Codec codec, OOC_CHAR8 source[], OOC_LEN source_0d, OOC_INT32 sourceStart, OOC_INT32 sourceEnd, OOC_CHAR16 dest[], OOC_LEN dest_0d, OOC_INT32 destStart, OOC_INT32 destEnd, OOC_INT32 *sourceDone, OOC_INT32 *destDone) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11,i12;
  OOC_INT32 low;
  OOC_INT32 high;
  OOC_INT32 testSourceEnd;
  OOC_INT32 testDestEnd;
  OOC_INT32 i;
  OOC_INT32 j;
  OOC_INT32 cval;
  auto OOC_INT32 XML_UnicodeCodec_UTF16__CodecDesc_Decode_BytesPerEncoding(OOC_CHAR8 highChar);
    
    OOC_INT32 XML_UnicodeCodec_UTF16__CodecDesc_Decode_BytesPerEncoding(OOC_CHAR8 highChar) {
      register OOC_INT32 i0,i1;

      i0 = highChar;
      i1 = (OOC_UINT8)216u<=(OOC_UINT8)i0;
      if (i1) goto l3;
      i0=0u;
      goto l5;
l3:
      i0 = (OOC_UINT8)i0<(OOC_UINT8)220u;
      
l5:
      if (i0) goto l7;
      return 2;
      goto l8;
l7:
      return 4;
l8:
      _failed_function(1937); return 0;
      ;
    }


  i0 = (OOC_INT32)codec;
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 2148))+8);
  if (i1) goto l3;
  low = 0;
  high = 1;
  i1=1;i2=0;
  goto l4;
l3:
  low = 1;
  high = 0;
  i1=0;i2=1;
l4:
  i3 = sourceEnd;
  i4 = i3-5;
  i5 = destEnd;
  testSourceEnd = i4;
  i6 = i5-1;
  testDestEnd = i6;
  i7 = sourceStart;
  i = i7;
  i8 = destStart;
  j = i8;
  i9 = i7<i4;
  if (i9) goto l7;
  i9=0u;
  goto l9;
l7:
  i9 = i8<i6;
  
l9:
  if (i9) goto l11;
  i2=i7;i4=i8;
  goto l45;
l11:
  i9=i7;i10=i8;
l12_loop:
  i11 = *(OOC_UINT8*)((OOC_INT32)source+(_check_index((i9+i1), source_0d, OOC_UINT32, 2614)));
  i12 = *(OOC_UINT8*)((OOC_INT32)source+(_check_index((i9+i2), source_0d, OOC_UINT32, 2642)));
  i11 = (i11*256)+i12;
  cval = i11;
  i12 = i11<55296;
  if (i12) goto l19;
  i12 = i11>=57344;
  if (i12) goto l17;
  i12=0u;
  goto l21;
l17:
  i12 = i11<65534;
  
  goto l21;
l19:
  i12=1u;
l21:
  if (i12) goto l35;
  i12 = i11<56320;
  if (i12) goto l25;
  i12=0u;
  goto l27;
l25:
  i12 = *(OOC_UINT8*)((OOC_INT32)source+(_check_index(((i9+2)+i1), source_0d, OOC_UINT32, 2885)));
  i12 = (OOC_UINT8)220u<=(OOC_UINT8)i12;
  
l27:
  if (i12) goto l29;
  i12=0u;
  goto l31;
l29:
  i12 = *(OOC_UINT8*)((OOC_INT32)source+(_check_index(((i9+2)+i1), source_0d, OOC_UINT32, 2906)));
  i12 = (OOC_UINT8)i12<(OOC_UINT8)224u;
  
l31:
  if (i12) goto l33;
  i11 = *(OOC_INT32*)(_check_pointer(i0, 3299));
  *(OOC_INT32*)(_check_pointer(i0, 3299)) = (i11+1);
  *(OOC_UINT16*)((OOC_INT32)dest+(_check_index(i10, dest_0d, OOC_UINT32, 3328))*2) = 65533u;
  i9 = i9+2;
  i = i9;
  i10 = i10+1;
  j = i10;
  
  goto l36;
l33:
  *(OOC_UINT16*)((OOC_INT32)dest+(_check_index(i10, dest_0d, OOC_UINT32, 3016))*2) = i11;
  i11 = i9+2;
  i12 = *(OOC_UINT8*)((OOC_INT32)source+(_check_index((i11+i1), source_0d, OOC_UINT32, 3086)));
  i11 = *(OOC_UINT8*)((OOC_INT32)source+(_check_index((i11+i2), source_0d, OOC_UINT32, 3146)));
  *(OOC_UINT16*)((OOC_INT32)dest+(_check_index((i10+1), dest_0d, OOC_UINT32, 3051))*2) = ((i12*256)+i11);
  i9 = i9+4;
  i = i9;
  i10 = i10+2;
  j = i10;
  
  goto l36;
l35:
  *(OOC_UINT16*)((OOC_INT32)dest+(_check_index(i10, dest_0d, OOC_UINT32, 2785))*2) = i11;
  i9 = i9+2;
  i = i9;
  i10 = i10+1;
  j = i10;
  
l36:
  i11 = i9<i4;
  if (i11) goto l39;
  i11=0u;
  goto l41;
l39:
  i11 = i10<i6;
  
l41:
  if (i11) goto l12_loop;
l44:
  i2=i9;i4=i10;
l45:
  i6 = i2==i7;
  if (i6) goto l48;
  *sourceDone = i2;
  *destDone = i4;
  goto l81;
l48:
  i6 = (i2+1)<i3;
  if (i6) goto l51;
  i6=0u;
  goto l53;
l51:
  i6 = *(OOC_UINT8*)((OOC_INT32)source+(_check_index((i2+i1), source_0d, OOC_UINT32, 3748)));
  i6 = XML_UnicodeCodec_UTF16__CodecDesc_Decode_BytesPerEncoding(i6);
  i6 = (i2+i6)<=i3;
  
l53:
  if (i6) goto l56_loop;
  i1=i2;
  goto l65;
l56_loop:
  i6 = *(OOC_UINT8*)((OOC_INT32)source+(_check_index((i2+i1), source_0d, OOC_UINT32, 3815)));
  i6 = XML_UnicodeCodec_UTF16__CodecDesc_Decode_BytesPerEncoding(i6);
  i2 = i2+i6;
  i = i2;
  i6 = (i2+1)<i3;
  if (i6) goto l59;
  i6=0u;
  goto l61;
l59:
  i6 = *(OOC_UINT8*)((OOC_INT32)source+(_check_index((i2+i1), source_0d, OOC_UINT32, 3748)));
  i6 = XML_UnicodeCodec_UTF16__CodecDesc_Decode_BytesPerEncoding(i6);
  i6 = (i2+i6)<=i3;
  
l61:
  if (i6) goto l56_loop;
l64:
  i1=i2;
l65:
  i2 = i1!=i7;
  if (i2) goto l68;
  *sourceDone = i1;
  *destDone = i8;
  goto l69;
l68:
  XML_UnicodeCodec_UTF16__CodecDesc_Decode((XML_UnicodeCodec_UTF16__Codec)i0, (void*)(OOC_INT32)source, source_0d, i7, (i1+5), (void*)(OOC_INT32)dest, dest_0d, i4, (i5+1), (void*)(OOC_INT32)sourceDone, (void*)(OOC_INT32)destDone);
l69:
  i2 = *sourceDone;
  i1 = i2==i1;
  if (i1) goto l72;
  i1=0u;
  goto l74;
l72:
  i1 = i2!=i3;
  
l74:
  if (i1) goto l76;
  i1=0u;
  goto l78;
l76:
  i1 = *destDone;
  i1 = i1!=i5;
  
l78:
  if (!i1) goto l81;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 4393));
  *(OOC_INT32*)(_check_pointer(i0, 4393)) = (i1+1);
  i0 = *destDone;
  *(OOC_UINT16*)((OOC_INT32)dest+(_check_index(i0, dest_0d, OOC_UINT32, 4422))*2) = 65533u;
  *destDone = (i0+1);
  *sourceDone = i3;
l81:
  return;
  ;
}

void XML_UnicodeCodec_UTF16__CodecDesc_Encode(XML_UnicodeCodec_UTF16__Codec codec, OOC_CHAR16 source[], OOC_LEN source_0d, OOC_INT32 sourceStart, OOC_INT32 sourceEnd, OOC_CHAR8 dest[], OOC_LEN dest_0d, OOC_INT32 destStart, OOC_INT32 destEnd, OOC_INT32 *sourceDone, OOC_INT32 *destDone) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11,i12,i13;
  OOC_INT32 low;
  OOC_INT32 high;
  OOC_INT32 testSourceEnd;
  OOC_INT32 testDestEnd;
  OOC_INT32 i;
  OOC_INT32 j;
  auto OOC_INT32 XML_UnicodeCodec_UTF16__CodecDesc_Encode_WordsPerEncoding(OOC_CHAR16 ch);
    
    OOC_INT32 XML_UnicodeCodec_UTF16__CodecDesc_Encode_WordsPerEncoding(OOC_CHAR16 ch) {
      register OOC_INT32 i0,i1;

      i0 = ch;
      i1 = (OOC_UINT16)55296u<=(OOC_UINT16)i0;
      if (i1) goto l3;
      i0=0u;
      goto l5;
l3:
      i0 = (OOC_UINT16)i0<(OOC_UINT16)56320u;
      
l5:
      if (i0) goto l7;
      return 1;
      goto l8;
l7:
      return 2;
l8:
      _failed_function(5105); return 0;
      ;
    }


  i0 = (OOC_INT32)codec;
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 5306))+8);
  if (i1) goto l3;
  low = 0;
  high = 1;
  i1=1;i2=0;
  goto l4;
l3:
  low = 1;
  high = 0;
  i1=0;i2=1;
l4:
  i3 = sourceEnd;
  i4 = i3-1;
  i5 = destEnd;
  testSourceEnd = i4;
  i6 = i5-5;
  testDestEnd = i6;
  i7 = sourceStart;
  i = i7;
  i8 = destStart;
  j = i8;
  i9 = i7<i4;
  if (i9) goto l7;
  i9=0u;
  goto l9;
l7:
  i9 = i8<i6;
  
l9:
  if (i9) goto l11;
  i4=i7;i6=i8;
  goto l45;
l11:
  i9=i8;i10=i7;
l12_loop:
  i11 = i9+i1;
  i12 = *(OOC_UINT16*)((OOC_INT32)source+(_check_index(i10, source_0d, OOC_UINT32, 5779))*2);
  *(OOC_UINT8*)((OOC_INT32)dest+(_check_index(i11, dest_0d, OOC_UINT32, 5751))) = (i12>>8);
  i12 = i9+i2;
  i13 = *(OOC_UINT16*)((OOC_INT32)source+(_check_index(i10, source_0d, OOC_UINT32, 5831))*2);
  *(OOC_UINT8*)((OOC_INT32)dest+(_check_index(i12, dest_0d, OOC_UINT32, 5804))) = (_mod(i13,256));
  i13 = *(OOC_UINT16*)((OOC_INT32)source+(_check_index(i10, source_0d, OOC_UINT32, 5862))*2);
  i13 = (OOC_UINT16)i13<(OOC_UINT16)55296u;
  if (i13) goto l19;
  i13 = *(OOC_UINT16*)((OOC_INT32)source+(_check_index(i10, source_0d, OOC_UINT32, 5895))*2);
  i13 = (OOC_UINT16)i13>=(OOC_UINT16)57344u;
  if (i13) goto l17;
  i13=0u;
  goto l21;
l17:
  i13 = *(OOC_UINT16*)((OOC_INT32)source+(_check_index(i10, source_0d, OOC_UINT32, 5919))*2);
  i13 = (OOC_UINT16)i13<(OOC_UINT16)65534u;
  
  goto l21;
l19:
  i13=1u;
l21:
  if (i13) goto l35;
  i13 = *(OOC_UINT16*)((OOC_INT32)source+(_check_index(i10, source_0d, OOC_UINT32, 5985))*2);
  i13 = (OOC_UINT16)i13<(OOC_UINT16)56320u;
  if (i13) goto l25;
  i13=0u;
  goto l27;
l25:
  i13 = *(OOC_UINT16*)((OOC_INT32)source+(_check_index((i10+1), source_0d, OOC_UINT32, 6030))*2);
  i13 = (OOC_UINT16)56320u<=(OOC_UINT16)i13;
  
l27:
  if (i13) goto l29;
  i13=0u;
  goto l31;
l29:
  i13 = *(OOC_UINT16*)((OOC_INT32)source+(_check_index((i10+1), source_0d, OOC_UINT32, 6046))*2);
  i13 = (OOC_UINT16)i13<(OOC_UINT16)57344u;
  
l31:
  if (i13) goto l33;
  i13 = *(OOC_INT32*)(_check_pointer(i0, 6244));
  *(OOC_INT32*)(_check_pointer(i0, 6244)) = (i13+1);
  *(OOC_UINT8*)((OOC_INT32)dest+(_check_index(i11, dest_0d, OOC_UINT32, 6273))) = 0u;
  *(OOC_UINT8*)((OOC_INT32)dest+(_check_index(i12, dest_0d, OOC_UINT32, 6333))) = 63u;
  i10 = i10+1;
  i = i10;
  i9 = i9+2;
  j = i9;
  
  goto l36;
l33:
  i11 = i9+2;
  i12 = i10+1;
  i13 = *(OOC_UINT16*)((OOC_INT32)source+(_check_index(i12, source_0d, OOC_UINT32, 6109))*2);
  *(OOC_UINT8*)((OOC_INT32)dest+(_check_index((i11+i1), dest_0d, OOC_UINT32, 6079))) = (i13>>8);
  i12 = *(OOC_UINT16*)((OOC_INT32)source+(_check_index(i12, source_0d, OOC_UINT32, 6167))*2);
  *(OOC_UINT8*)((OOC_INT32)dest+(_check_index((i11+i2), dest_0d, OOC_UINT32, 6138))) = (_mod(i12,256));
  i10 = i10+2;
  i = i10;
  i9 = i9+4;
  j = i9;
  
  goto l36;
l35:
  i10 = i10+1;
  i = i10;
  i9 = i9+2;
  j = i9;
  
l36:
  i11 = i10<i4;
  if (i11) goto l39;
  i11=0u;
  goto l41;
l39:
  i11 = i9<i6;
  
l41:
  if (i11) goto l12_loop;
l44:
  i4=i10;i6=i9;
l45:
  i9 = i4==i7;
  if (i9) goto l48;
  *sourceDone = i4;
  *destDone = i6;
  goto l81;
l48:
  i6 = i4!=i3;
  if (i6) goto l51;
  i6=0u;
  goto l53;
l51:
  i6 = *(OOC_UINT16*)((OOC_INT32)source+(_check_index(i4, source_0d, OOC_UINT32, 6771))*2);
  i6 = XML_UnicodeCodec_UTF16__CodecDesc_Encode_WordsPerEncoding(i6);
  i6 = (i4+i6)<=i3;
  
l53:
  if (!i6) goto l65;
l56_loop:
  i6 = *(OOC_UINT16*)((OOC_INT32)source+(_check_index(i4, source_0d, OOC_UINT32, 6833))*2);
  i6 = XML_UnicodeCodec_UTF16__CodecDesc_Encode_WordsPerEncoding(i6);
  i4 = i4+i6;
  i = i4;
  i6 = i4!=i3;
  if (i6) goto l59;
  i6=0u;
  goto l61;
l59:
  i6 = *(OOC_UINT16*)((OOC_INT32)source+(_check_index(i4, source_0d, OOC_UINT32, 6771))*2);
  i6 = XML_UnicodeCodec_UTF16__CodecDesc_Encode_WordsPerEncoding(i6);
  i6 = (i4+i6)<=i3;
  
l61:
  if (i6) goto l56_loop;
l65:
  i6 = i4!=i7;
  if (i6) goto l68;
  *sourceDone = i4;
  *destDone = i8;
  goto l69;
l68:
  XML_UnicodeCodec_UTF16__CodecDesc_Encode((XML_UnicodeCodec_UTF16__Codec)i0, (void*)(OOC_INT32)source, source_0d, i7, (i4+1), (void*)(OOC_INT32)dest, dest_0d, i8, (i5+5), (void*)(OOC_INT32)sourceDone, (void*)(OOC_INT32)destDone);
l69:
  i6 = *sourceDone;
  i4 = i6==i4;
  if (i4) goto l72;
  i4=0u;
  goto l74;
l72:
  i4 = i6!=i3;
  
l74:
  if (i4) goto l76;
  i4=0u;
  goto l78;
l76:
  i4 = *destDone;
  i4 = i4!=i5;
  
l78:
  if (!i4) goto l81;
  i4 = *(OOC_INT32*)(_check_pointer(i0, 7412));
  i5 = *destDone;
  *(OOC_INT32*)(_check_pointer(i0, 7412)) = (i4+1);
  *(OOC_UINT8*)((OOC_INT32)dest+(_check_index((i5+i1), dest_0d, OOC_UINT32, 7441))) = 0u;
  *(OOC_UINT8*)((OOC_INT32)dest+(_check_index((i5+i2), dest_0d, OOC_UINT32, 7508))) = 63u;
  *destDone = (i5+2);
  *sourceDone = i3;
l81:
  return;
  ;
}

static void XML_UnicodeCodec_UTF16__InitFactory(XML_UnicodeCodec_UTF16__Factory f) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)f;
  XML_UnicodeCodec__InitFactory((XML_UnicodeCodec__Factory)i0, 1);
  return;
  ;
}

XML_UnicodeCodec__Codec XML_UnicodeCodec_UTF16__FactoryDesc_NewCodec(XML_UnicodeCodec_UTF16__Factory f) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)f;
  i0 = *(OOC_INT8*)(_check_pointer(i0, 7879));
  i0 = (OOC_INT32)XML_UnicodeCodec_UTF16__NewBE(i0);
  return (XML_UnicodeCodec__Codec)i0;
  ;
}

XML_UnicodeCodec__Codec XML_UnicodeCodec_UTF16__FactoryDesc_NewCodecBOM(XML_UnicodeCodec_UTF16__Factory f, OOC_CHAR8 source[], OOC_LEN source_0d, OOC_INT32 sourceStart, OOC_INT32 sourceEnd, OOC_INT32 *sourceDone) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = sourceStart;
  i1 = i0+1;
  i2 = sourceEnd;
  i3 = (OOC_INT32)f;
  i2 = i1<i2;
  if (!i2) goto l18;
  i2 = *(OOC_UINT8*)((OOC_INT32)source+(_check_index(i0, source_0d, OOC_UINT32, 8174)));
  i2 = i2==255u;
  if (i2) goto l5;
  i2=0u;
  goto l7;
l5:
  i2 = *(OOC_UINT8*)((OOC_INT32)source+(_check_index(i1, source_0d, OOC_UINT32, 8214)));
  i2 = i2==254u;
  
l7:
  if (i2) goto l16;
  i2 = *(OOC_UINT8*)((OOC_INT32)source+(_check_index(i0, source_0d, OOC_UINT32, 8329)));
  i2 = i2==254u;
  if (i2) goto l11;
  i1=0u;
  goto l13;
l11:
  i1 = *(OOC_UINT8*)((OOC_INT32)source+(_check_index(i1, source_0d, OOC_UINT32, 8372)));
  i1 = i1==255u;
  
l13:
  if (!i1) goto l18;
  *sourceDone = (i0+2);
  i1 = *(OOC_INT8*)(_check_pointer(i3, 8461));
  i1 = (OOC_INT32)XML_UnicodeCodec_UTF16__NewBE(i1);
  return (XML_UnicodeCodec__Codec)i1;
  goto l18;
l16:
  *sourceDone = (i0+2);
  i1 = *(OOC_INT8*)(_check_pointer(i3, 8303));
  i1 = (OOC_INT32)XML_UnicodeCodec_UTF16__NewLE(i1);
  return (XML_UnicodeCodec__Codec)i1;
l18:
  *sourceDone = i0;
  i0 = *(OOC_INT8*)(_check_pointer(i3, 8594));
  i0 = (OOC_INT32)XML_UnicodeCodec_UTF16__NewBE(i0);
  return (XML_UnicodeCodec__Codec)i0;
  ;
}

void XML_UnicodeCodec_UTF16__FactoryDesc_GetEncodingName(XML_UnicodeCodec_UTF16__Factory f, OOC_CHAR8 name[], OOC_LEN name_0d) {

  _copy_8((const void*)"UTF-16",(void*)(OOC_INT32)name,name_0d);
  return;
  ;
}

static void XML_UnicodeCodec_UTF16__InitFactoryLE(XML_UnicodeCodec_UTF16__FactoryLE f) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)f;
  XML_UnicodeCodec__InitFactory((XML_UnicodeCodec__Factory)i0, 0);
  return;
  ;
}

XML_UnicodeCodec__Codec XML_UnicodeCodec_UTF16__FactoryLEDesc_NewCodec(XML_UnicodeCodec_UTF16__FactoryLE f) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)f;
  i0 = *(OOC_INT8*)(_check_pointer(i0, 8937));
  i0 = (OOC_INT32)XML_UnicodeCodec_UTF16__NewLE(i0);
  return (XML_UnicodeCodec__Codec)i0;
  ;
}

XML_UnicodeCodec__Codec XML_UnicodeCodec_UTF16__FactoryLEDesc_NewCodecBOM(XML_UnicodeCodec_UTF16__FactoryLE f, OOC_CHAR8 source[], OOC_LEN source_0d, OOC_INT32 sourceStart, OOC_INT32 sourceEnd, OOC_INT32 *sourceDone) {
  register OOC_INT32 i0,i1,i2,i3;
  XML_UnicodeCodec__Codec codec;

  i0 = sourceStart;
  *sourceDone = i0;
  i1 = (OOC_INT32)f;
  i1 = *(OOC_INT8*)(_check_pointer(i1, 9261));
  i1 = (OOC_INT32)XML_UnicodeCodec_UTF16__NewLE(i1);
  codec = (XML_UnicodeCodec__Codec)i1;
  i2 = i0+1;
  i3 = sourceEnd;
  i3 = i2<i3;
  if (!i3) goto l18;
  i3 = *(OOC_UINT8*)((OOC_INT32)source+(_check_index(i0, source_0d, OOC_UINT32, 9325)));
  i3 = i3==254u;
  if (i3) goto l5;
  i3=0u;
  goto l7;
l5:
  i3 = *(OOC_UINT8*)((OOC_INT32)source+(_check_index(i2, source_0d, OOC_UINT32, 9365)));
  i3 = i3==255u;
  
l7:
  if (i3) goto l16;
  i3 = *(OOC_UINT8*)((OOC_INT32)source+(_check_index(i0, source_0d, OOC_UINT32, 9466)));
  i3 = i3==255u;
  if (i3) goto l11;
  i2=0u;
  goto l13;
l11:
  i2 = *(OOC_UINT8*)((OOC_INT32)source+(_check_index(i2, source_0d, OOC_UINT32, 9509)));
  i2 = i2==254u;
  
l13:
  if (!i2) goto l18;
  *sourceDone = (i0+2);
  goto l18;
l16:
  i0 = *(OOC_INT32*)(_check_pointer(i1, 9431));
  *(OOC_INT32*)(_check_pointer(i1, 9431)) = (i0+1);
l18:
  return (XML_UnicodeCodec__Codec)i1;
  ;
}

void XML_UnicodeCodec_UTF16__FactoryLEDesc_GetEncodingName(XML_UnicodeCodec_UTF16__FactoryLE f, OOC_CHAR8 name[], OOC_LEN name_0d) {

  _copy_8((const void*)"UTF-16LE",(void*)(OOC_INT32)name,name_0d);
  return;
  ;
}

static void XML_UnicodeCodec_UTF16__InitFactoryBE(XML_UnicodeCodec_UTF16__FactoryBE f) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)f;
  XML_UnicodeCodec__InitFactory((XML_UnicodeCodec__Factory)i0, 0);
  return;
  ;
}

XML_UnicodeCodec__Codec XML_UnicodeCodec_UTF16__FactoryBEDesc_NewCodec(XML_UnicodeCodec_UTF16__FactoryBE f) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)f;
  i0 = *(OOC_INT8*)(_check_pointer(i0, 9942));
  i0 = (OOC_INT32)XML_UnicodeCodec_UTF16__NewBE(i0);
  return (XML_UnicodeCodec__Codec)i0;
  ;
}

XML_UnicodeCodec__Codec XML_UnicodeCodec_UTF16__FactoryBEDesc_NewCodecBOM(XML_UnicodeCodec_UTF16__FactoryBE f, OOC_CHAR8 source[], OOC_LEN source_0d, OOC_INT32 sourceStart, OOC_INT32 sourceEnd, OOC_INT32 *sourceDone) {
  register OOC_INT32 i0,i1,i2,i3;
  XML_UnicodeCodec__Codec codec;

  i0 = sourceStart;
  *sourceDone = i0;
  i1 = (OOC_INT32)f;
  i1 = *(OOC_INT8*)(_check_pointer(i1, 10266));
  i1 = (OOC_INT32)XML_UnicodeCodec_UTF16__NewBE(i1);
  codec = (XML_UnicodeCodec__Codec)i1;
  i2 = i0+1;
  i3 = sourceEnd;
  i3 = i2<i3;
  if (!i3) goto l18;
  i3 = *(OOC_UINT8*)((OOC_INT32)source+(_check_index(i0, source_0d, OOC_UINT32, 10330)));
  i3 = i3==255u;
  if (i3) goto l5;
  i3=0u;
  goto l7;
l5:
  i3 = *(OOC_UINT8*)((OOC_INT32)source+(_check_index(i2, source_0d, OOC_UINT32, 10370)));
  i3 = i3==254u;
  
l7:
  if (i3) goto l16;
  i3 = *(OOC_UINT8*)((OOC_INT32)source+(_check_index(i0, source_0d, OOC_UINT32, 10471)));
  i3 = i3==254u;
  if (i3) goto l11;
  i2=0u;
  goto l13;
l11:
  i2 = *(OOC_UINT8*)((OOC_INT32)source+(_check_index(i2, source_0d, OOC_UINT32, 10514)));
  i2 = i2==255u;
  
l13:
  if (!i2) goto l18;
  *sourceDone = (i0+2);
  goto l18;
l16:
  i0 = *(OOC_INT32*)(_check_pointer(i1, 10436));
  *(OOC_INT32*)(_check_pointer(i1, 10436)) = (i0+1);
l18:
  return (XML_UnicodeCodec__Codec)i1;
  ;
}

void XML_UnicodeCodec_UTF16__FactoryBEDesc_GetEncodingName(XML_UnicodeCodec_UTF16__FactoryBE f, OOC_CHAR8 name[], OOC_LEN name_0d) {

  _copy_8((const void*)"UTF-16BE",(void*)(OOC_INT32)name,name_0d);
  return;
  ;
}

void OOC_XML_UnicodeCodec_UTF16_init(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)RT0__NewObject(_td_XML_UnicodeCodec_UTF16__Factory.baseTypes[0]);
  XML_UnicodeCodec_UTF16__factory = (XML_UnicodeCodec_UTF16__Factory)i0;
  XML_UnicodeCodec_UTF16__InitFactory((XML_UnicodeCodec_UTF16__Factory)i0);
  i0 = (OOC_INT32)XML_UnicodeCodec_UTF16__factory;
  XML_UnicodeCodec__Register("UTF-16", 7, (XML_UnicodeCodec__Factory)i0);
  i0 = (OOC_INT32)RT0__NewObject(_td_XML_UnicodeCodec_UTF16__FactoryLE.baseTypes[0]);
  XML_UnicodeCodec_UTF16__factoryLE = (XML_UnicodeCodec_UTF16__FactoryLE)i0;
  XML_UnicodeCodec_UTF16__InitFactoryLE((XML_UnicodeCodec_UTF16__FactoryLE)i0);
  i0 = (OOC_INT32)XML_UnicodeCodec_UTF16__factoryLE;
  XML_UnicodeCodec__Register("UTF-16LE", 9, (XML_UnicodeCodec__Factory)i0);
  i0 = (OOC_INT32)RT0__NewObject(_td_XML_UnicodeCodec_UTF16__FactoryBE.baseTypes[0]);
  XML_UnicodeCodec_UTF16__factoryBE = (XML_UnicodeCodec_UTF16__FactoryBE)i0;
  XML_UnicodeCodec_UTF16__InitFactoryBE((XML_UnicodeCodec_UTF16__FactoryBE)i0);
  i0 = (OOC_INT32)XML_UnicodeCodec_UTF16__factoryBE;
  XML_UnicodeCodec__Register("UTF-16BE", 9, (XML_UnicodeCodec__Factory)i0);
  return;
  ;
}

/* --- */
