#include <ADT/StringBuffer.d>
#include <__oo2c.h>
#include <setjmp.h>

void ADT_StringBuffer__StringBufferDesc_INIT(ADT_StringBuffer__StringBuffer b, OOC_INT32 initialCapacity) {
  register OOC_INT32 i0,i1;

  i0 = initialCapacity;
  i1 = i0<8;
  if (!i1) goto l4;
  initialCapacity = 8;
  i0=8;
l4:
  i1 = (OOC_INT32)b;
  *(OOC_INT32*)(_check_pointer(i1, 1975)) = i0;
  *(OOC_INT32*)((_check_pointer(i1, 2010))+4) = 0;
  *(OOC_INT32*)((_check_pointer(i1, 2033))+8) = ((OOC_INT32)RT0__NewObject(_td_ADT_StringBuffer__CharsLatin1.baseTypes[0], i0));
  *(OOC_INT32*)((_check_pointer(i1, 2064))+12) = 0;
  return;
  ;
}

Object__String ADT_StringBuffer__StringBufferDesc_ToString(ADT_StringBuffer__StringBuffer b) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2158))+8);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l3;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2282))+12);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2282))+12);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 2289)), 0);
  i0 = *(OOC_INT32*)((_check_pointer(i0, 2296))+4);
  i0 = (OOC_INT32)Object__NewUTF16Region((void*)(_check_pointer(i2, 2289)), i1, 0, i0);
  return (Object__String)i0;
  goto l4;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2214))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2214))+8);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 2220)), 0);
  i0 = *(OOC_INT32*)((_check_pointer(i0, 2227))+4);
  i0 = (OOC_INT32)Object__NewLatin1Region((void*)(_check_pointer(i2, 2220)), i1, 0, i0);
  return (Object__String)i0;
l4:
  _failed_function(2121); return 0;
  ;
}

OOC_CHAR32 ADT_StringBuffer__StringBufferDesc_CharAt(ADT_StringBuffer__StringBuffer b, OOC_INT32 index) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_CHAR16 _w1;

  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2440))+8);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l27;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2510))+12);
  i1 = _check_pointer(i1, 2517);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i3 = index;
  i1 = *(OOC_UINT16*)(i1+(_check_index(i3, i2, OOC_UINT32, 2517))*2);
  _w1 = i1;
  i2 = (OOC_UINT16)i1<(OOC_UINT16)55296u;
  if (i2) goto l5;
  i2 = (OOC_UINT16)i1>=(OOC_UINT16)57344u;
  
  goto l7;
l5:
  i2=1u;
l7:
  if (i2) goto l9;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 2626))+4);
  i2 = (i3+1)==i2;
  
  goto l11;
l9:
  i2=1u;
l11:
  if (i2) goto l25;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2751))+12);
  i0 = _check_pointer(i0, 2758);
  i2 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = *(OOC_UINT16*)(i0+(_check_index((i3+1), i2, OOC_UINT32, 2758))*2);
  i2 = (OOC_UINT16)i1<(OOC_UINT16)56320u;
  if (i2) goto l15;
  i2=0u;
  goto l17;
l15:
  i2 = (OOC_UINT16)56320u<=(OOC_UINT16)i0;
  
l17:
  if (i2) goto l19;
  i2=0u;
  goto l21;
l19:
  i2 = (OOC_UINT16)i0<(OOC_UINT16)57344u;
  
l21:
  if (i2) goto l23;
  return i1;
  goto l28;
l23:
  return (((_mod(i1,1024))*1024)+(_mod(i0,1024)));
  goto l28;
l25:
  return i1;
  goto l28;
l27:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2473))+8);
  i0 = _check_pointer(i0, 2479);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i2 = index;
  i0 = *(OOC_UINT8*)(i0+(_check_index(i2, i1, OOC_UINT32, 2479)));
  return i0;
l28:
  _failed_function(2360); return 0;
  ;
}

void ADT_StringBuffer__StringBufferDesc_Clear(ADT_StringBuffer__StringBuffer b) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)b;
  *(OOC_INT32*)((_check_pointer(i0, 3115))+4) = 0;
  return;
  ;
}

void ADT_StringBuffer__StringBufferDesc_EnsureCapacity(ADT_StringBuffer__StringBuffer b, OOC_INT32 cap) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_INT32 newCap;
  ADT_StringBuffer__CharsLatin1 new8;
  ADT_StringBuffer__CharsUTF16 new16;

  i0 = (OOC_INT32)b;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 3292));
  i2 = cap;
  i1 = i1<i2;
  if (!i1) goto l16;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 3331));
  newCap = i1;
  i3 = i1<i2;
  if (!i3) goto l11;
l6_loop:
  i1 = i1*2;
  newCap = i1;
  i3 = i1<i2;
  if (i3) goto l6_loop;
l11:
  *(OOC_INT32*)(_check_pointer(i0, 3418)) = i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3457))+8);
  i2 = i2!=0;
  if (i2) goto l14;
  i1 = (OOC_INT32)RT0__NewObject(_td_ADT_StringBuffer__CharsUTF16.baseTypes[0], i1);
  new16 = (ADT_StringBuffer__CharsUTF16)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3657))+12);
  i0 = *(OOC_INT32*)((_check_pointer(i0, 3684))+4);
  _move_block((_check_pointer(i2, 3664)),(_check_pointer(i1, 3679)),(i0*2));
  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)new16;
  *(OOC_INT32*)((_check_pointer(i0, 3718))+12) = i1;
  goto l16;
l14:
  i1 = (OOC_INT32)RT0__NewObject(_td_ADT_StringBuffer__CharsLatin1.baseTypes[0], i1);
  new8 = (ADT_StringBuffer__CharsLatin1)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3525))+8);
  i0 = *(OOC_INT32*)((_check_pointer(i0, 3550))+4);
  _move_block((_check_pointer(i2, 3531)),(_check_pointer(i1, 3545)),i0);
  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)new8;
  *(OOC_INT32*)((_check_pointer(i0, 3580))+8) = i1;
l16:
  return;
  ;
}

ADT_StringBuffer__CharsLatin1 ADT_StringBuffer__StringBufferDesc_CharsLatin1(ADT_StringBuffer__StringBuffer b) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4469))+8);
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l3;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 4512))+4);
  ADT_StringBuffer__StringBufferDesc_EnsureCapacity((ADT_StringBuffer__StringBuffer)i0, (i1+1));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4531))+8);
  i1 = _check_pointer(i1, 4537);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i3 = *(OOC_INT32*)((_check_pointer(i0, 4539))+4);
  *(OOC_UINT8*)(i1+(_check_index(i3, i2, OOC_UINT32, 4537))) = 0u;
l3:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4576))+8);
  return (ADT_StringBuffer__CharsLatin1)i0;
  ;
}

void ADT_StringBuffer__StringBufferDesc_ConvertTo16(ADT_StringBuffer__StringBuffer b) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_INT32 i;

  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4698))+8);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 4704)), 0);
  *(OOC_INT32*)((_check_pointer(i0, 4684))+12) = ((OOC_INT32)RT0__NewObject(_td_ADT_StringBuffer__CharsUTF16.baseTypes[0], i1));
  i = 0;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 4728))+4);
  i2 = 0<i1;
  if (!i2) goto l8;
  i2=0;
l3_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4749))+12);
  i3 = _check_pointer(i3, 4756);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4764))+8);
  i5 = _check_pointer(i5, 4770);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = *(OOC_UINT8*)(i5+(_check_index(i2, i6, OOC_UINT32, 4770)));
  *(OOC_UINT16*)(i3+(_check_index(i2, i4, OOC_UINT32, 4756))*2) = i5;
  i2 = i2+1;
  i = i2;
  i3 = i2<i1;
  if (i3) goto l3_loop;
l8:
  *(OOC_INT32*)((_check_pointer(i0, 4789))+8) = (OOC_INT32)0;
  return;
  ;
}

ADT_StringBuffer__CharsUTF16 ADT_StringBuffer__StringBufferDesc_CharsUTF16(ADT_StringBuffer__StringBuffer b) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5522))+12);
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l4;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 5566))+4);
  ADT_StringBuffer__StringBufferDesc_EnsureCapacity((ADT_StringBuffer__StringBuffer)i0, (i1+1));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5585))+12);
  i1 = _check_pointer(i1, 5592);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i3 = *(OOC_INT32*)((_check_pointer(i0, 5594))+4);
  *(OOC_UINT16*)(i1+(_check_index(i3, i2, OOC_UINT32, 5592))*2) = 0u;
l4:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5631))+12);
  return (ADT_StringBuffer__CharsUTF16)i0;
  ;
}

void ADT_StringBuffer__StringBufferDesc_AppendLatin1Region(ADT_StringBuffer__StringBuffer b, const OOC_CHAR8 data[], OOC_LEN data_0d, OOC_INT32 start, OOC_INT32 end) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_INT32 len;
  OOC_INT32 i;

  i0 = start;
  i1 = end;
  _assert((i0>=0), 127, 5846);
  _assert((i0<=i1), 127, 5870);
  _assert((i1<=data_0d), 127, 5896);
  i2 = i1-i0;
  len = i2;
  i3 = (OOC_INT32)b;
  i4 = *(OOC_INT32*)((_check_pointer(i3, 5971))+4);
  ADT_StringBuffer__StringBufferDesc_EnsureCapacity((ADT_StringBuffer__StringBuffer)i3, (i4+i2));
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 5994))+8);
  i4 = i4!=(OOC_INT32)0;
  if (i4) goto l11;
  i2 = *(OOC_INT32*)((_check_pointer(i3, 6146))+4);
  i = i2;
  i4 = i0!=i1;
  if (!i4) goto l12;
  {register OOC_INT32 h0=i0;i0=i2;i2=h0;}
l5_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 6193))+12);
  i4 = _check_pointer(i4, 6200);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = *(OOC_UINT8*)((OOC_INT32)data+(_check_index(i2, data_0d, OOC_UINT32, 6211)));
  *(OOC_UINT16*)(i4+(_check_index(i0, i5, OOC_UINT32, 6200))*2) = i6;
  i2 = i2+1;
  start = i2;
  i0 = i0+1;
  i = i0;
  i4 = i2!=i1;
  if (i4) goto l5_loop;
  goto l12;
l11:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 6081))+8);
  i3 = *(OOC_INT32*)((_check_pointer(i3, 6089))+4);
  _move_block(((OOC_INT32)data+i0),((_check_pointer(i1, 6087))+i3),i2);
l12:
  i0 = (OOC_INT32)b;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 6277))+4);
  i2 = len;
  *(OOC_INT32*)((_check_pointer(i0, 6277))+4) = (i1+i2);
  return;
  ;
}

static OOC_INT32 ADT_StringBuffer__Length(const OOC_CHAR8 data[], OOC_LEN data_0d) {
  register OOC_INT32 i0,i1;

  i0 = *(OOC_UINT8*)((OOC_INT32)data+(_check_index(0, data_0d, OOC_UINT32, 6433)));
  i0 = i0!=0u;
  if (i0) goto l3;
  i0=0;
  goto l9;
l3:
  i0=0;
l4_loop:
  i0 = i0+1;
  i1 = *(OOC_UINT8*)((OOC_INT32)data+(_check_index(i0, data_0d, OOC_UINT32, 6433)));
  i1 = i1!=0u;
  if (i1) goto l4_loop;
l9:
  return i0;
  ;
}

void ADT_StringBuffer__StringBufferDesc_AppendLatin1(ADT_StringBuffer__StringBuffer b, const OOC_CHAR8 data[], OOC_LEN data_0d) {
  register OOC_INT32 i0,i1;

  i0 = ADT_StringBuffer__Length((void*)(OOC_INT32)data, data_0d);
  i1 = (OOC_INT32)b;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6584)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1Region)),ADT_StringBuffer__StringBufferDesc_AppendLatin1Region)((ADT_StringBuffer__StringBuffer)i1, (void*)(OOC_INT32)data, data_0d, 0, i0);
  return;
  ;
}

void ADT_StringBuffer__StringBufferDesc_AppendLatin1Char(ADT_StringBuffer__StringBuffer b, OOC_CHAR8 ch) {
  register OOC_INT32 i0,i1,i2,i3,i4;

  i0 = (OOC_INT32)b;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 6736))+4);
  ADT_StringBuffer__StringBufferDesc_EnsureCapacity((ADT_StringBuffer__StringBuffer)i0, (i1+1));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6757))+8);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l3;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6823))+12);
  i1 = _check_pointer(i1, 6830);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i3 = *(OOC_INT32*)((_check_pointer(i0, 6832))+4);
  i4 = ch;
  *(OOC_UINT16*)(i1+(_check_index(i3, i2, OOC_UINT32, 6830))*2) = i4;
  goto l4;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6783))+8);
  i1 = _check_pointer(i1, 6789);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i3 = *(OOC_INT32*)((_check_pointer(i0, 6791))+4);
  i4 = ch;
  *(OOC_UINT8*)(i1+(_check_index(i3, i2, OOC_UINT32, 6789))) = i4;
l4:
  i1 = *(OOC_INT32*)((_check_pointer(i0, 6866))+4);
  *(OOC_INT32*)((_check_pointer(i0, 6866))+4) = (i1+1);
  return;
  ;
}

void ADT_StringBuffer__StringBufferDesc_AppendLn(ADT_StringBuffer__StringBuffer b) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)b;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7022)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)),ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)((ADT_StringBuffer__StringBuffer)i0, 10u);
  return;
  ;
}

void ADT_StringBuffer__StringBufferDesc_AppendUTF16Region(ADT_StringBuffer__StringBuffer b, const OOC_CHAR16 data[], OOC_LEN data_0d, OOC_INT32 start, OOC_INT32 end) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_INT32 len;

  i0 = start;
  i1 = end;
  _assert((i0>=0), 127, 7253);
  _assert((i0<=i1), 127, 7277);
  _assert((i1<=data_0d), 127, 7303);
  i1 = i1-i0;
  len = i1;
  i2 = (OOC_INT32)b;
  i3 = *(OOC_INT32*)((_check_pointer(i2, 7378))+4);
  ADT_StringBuffer__StringBufferDesc_EnsureCapacity((ADT_StringBuffer__StringBuffer)i2, (i3+i1));
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7401))+12);
  i3 = i3==(OOC_INT32)0;
  if (!i3) goto l4;
  ADT_StringBuffer__StringBufferDesc_ConvertTo16((ADT_StringBuffer__StringBuffer)i2);
l4:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7517))+12);
  i2 = *(OOC_INT32*)((_check_pointer(i2, 7526))+4);
  _move_block(((OOC_INT32)data+i0*2),((_check_pointer(i3, 7524))+i2*2),(i1*2));
  i0 = (OOC_INT32)b;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 7575))+4);
  i2 = len;
  *(OOC_INT32*)((_check_pointer(i0, 7575))+4) = (i1+i2);
  return;
  ;
}

void ADT_StringBuffer__StringBufferDesc_AppendChar(ADT_StringBuffer__StringBuffer b, OOC_CHAR32 ch) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT32 v;

  i0 = (OOC_INT32)b;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 7723))+4);
  ADT_StringBuffer__StringBufferDesc_EnsureCapacity((ADT_StringBuffer__StringBuffer)i0, (i1+2));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7744))+12);
  i1 = i1==(OOC_INT32)0;
  if (!i1) goto l3;
  ADT_StringBuffer__StringBufferDesc_ConvertTo16((ADT_StringBuffer__StringBuffer)i0);
l3:
  i1 = ch;
  i2 = (OOC_UINT32)i1<(OOC_UINT32)65536u;
  if (i2) goto l6;
  i1 = i1-65536;
  v = i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7963))+12);
  i2 = _check_pointer(i2, 7970);
  i3 = *(OOC_INT32*)((_check_pointer(i0, 7972))+4);
  i4 = OOC_ARRAY_LENGTH(i2, 0);
  *(OOC_UINT16*)(i2+(_check_index(i3, i4, OOC_UINT32, 7970))*2) = (55296+(i1>>10));
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8039))+12);
  i2 = _check_pointer(i2, 8046);
  i3 = *(OOC_INT32*)((_check_pointer(i0, 8048))+4);
  i4 = OOC_ARRAY_LENGTH(i2, 0);
  *(OOC_UINT16*)(i2+(_check_index((i3+1), i4, OOC_UINT32, 8046))*2) = (56320+(_mod(i1,1024)));
  i1 = *(OOC_INT32*)((_check_pointer(i0, 8122))+4);
  *(OOC_INT32*)((_check_pointer(i0, 8122))+4) = (i1+2);
  goto l7;
l6:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7847))+12);
  i2 = _check_pointer(i2, 7854);
  i3 = *(OOC_INT32*)((_check_pointer(i0, 7856))+4);
  i4 = OOC_ARRAY_LENGTH(i2, 0);
  *(OOC_UINT16*)(i2+(_check_index(i3, i4, OOC_UINT32, 7854))*2) = i1;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 7890))+4);
  *(OOC_INT32*)((_check_pointer(i0, 7890))+4) = (i1+1);
l7:
  return;
  ;
}

void ADT_StringBuffer__StringBufferDesc_Append(ADT_StringBuffer__StringBuffer b, Object__Object obj) {
  register OOC_INT32 i0,i1,i2,i3;
  Object__String s;
  Object__CharsLatin1 c8;
  Object__CharsUTF16 c16;

  i0 = (OOC_INT32)obj;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l15;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8375)))), &_td_Object__StringDesc);
  if (i1) goto l5;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8432)))), Object__ObjectDesc_ToString)),Object__ObjectDesc_ToString)((Object__Object)i0);
  s = (Object__String)i0;
  
  goto l6;
l5:
  s = (Object__String)i0;
  
l6:
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8475)))), &_td_Object__String8Desc);
  if (i1) goto l13;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8583)))), &_td_Object__String16Desc);
  if (i1) goto l11;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8580)))), 8580);
  goto l16;
l11:
  i1 = (OOC_INT32)Object__String16Desc_CharsUTF16((Object__String16)i0);
  c16 = (Object__CharsUTF16)i1;
  i2 = (OOC_INT32)b;
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i1, 8666)), 0);
  i0 = *(OOC_INT32*)(_check_pointer(i0, 8673));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 8644)))), ADT_StringBuffer__StringBufferDesc_AppendUTF16Region)),ADT_StringBuffer__StringBufferDesc_AppendUTF16Region)((ADT_StringBuffer__StringBuffer)i2, (void*)(_check_pointer(i1, 8666)), i3, 0, i0);
  goto l16;
l13:
  i1 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)i0);
  c8 = (Object__CharsLatin1)i1;
  i2 = (OOC_INT32)b;
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i1, 8557)), 0);
  i0 = *(OOC_INT32*)(_check_pointer(i0, 8564));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 8535)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1Region)),ADT_StringBuffer__StringBufferDesc_AppendLatin1Region)((ADT_StringBuffer__StringBuffer)i2, (void*)(_check_pointer(i1, 8557)), i3, 0, i0);
  goto l16;
l15:
  i0 = (OOC_INT32)b;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8336)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c0));
l16:
  return;
  ;
}

ADT_StringBuffer__StringBuffer ADT_StringBuffer__New(Object__String str) {
  register OOC_INT32 i0,i1,i2;
  ADT_StringBuffer__StringBuffer b;

  i0 = (OOC_INT32)RT0__NewObject(_td_ADT_StringBuffer__StringBuffer.baseTypes[0]);
  i1 = (OOC_INT32)str;
  i2 = *(OOC_INT32*)(_check_pointer(i1, 8826));
  ADT_StringBuffer__StringBufferDesc_INIT((ADT_StringBuffer__StringBuffer)i0, (i2+1));
  b = (ADT_StringBuffer__StringBuffer)i0;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8843)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i1);
  return (ADT_StringBuffer__StringBuffer)i0;
  ;
}

ADT_StringBuffer__StringBuffer ADT_StringBuffer__NewLatin1(const OOC_CHAR8 str[], OOC_LEN str_0d) {
  register OOC_INT32 i0,i1;
  ADT_StringBuffer__StringBuffer b;

  i0 = (OOC_INT32)RT0__NewObject(_td_ADT_StringBuffer__StringBuffer.baseTypes[0]);
  i1 = ADT_StringBuffer__Length((void*)(OOC_INT32)str, str_0d);
  ADT_StringBuffer__StringBufferDesc_INIT((ADT_StringBuffer__StringBuffer)i0, (i1+1));
  b = (ADT_StringBuffer__StringBuffer)i0;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9031)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i0, (void*)(OOC_INT32)str, str_0d);
  return (ADT_StringBuffer__StringBuffer)i0;
  ;
}

ADT_StringBuffer__StringBuffer ADT_StringBuffer__NewLatin1Region(const OOC_CHAR8 str[], OOC_LEN str_0d, OOC_INT32 start, OOC_INT32 end) {
  register OOC_INT32 i0,i1,i2;
  ADT_StringBuffer__StringBuffer b;

  i0 = end;
  i1 = start;
  i2 = (OOC_INT32)RT0__NewObject(_td_ADT_StringBuffer__StringBuffer.baseTypes[0]);
  ADT_StringBuffer__StringBufferDesc_INIT((ADT_StringBuffer__StringBuffer)i2, ((i0-i1)+1));
  b = (ADT_StringBuffer__StringBuffer)i2;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 9283)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1Region)),ADT_StringBuffer__StringBufferDesc_AppendLatin1Region)((ADT_StringBuffer__StringBuffer)i2, (void*)(OOC_INT32)str, str_0d, i1, i0);
  return (ADT_StringBuffer__StringBuffer)i2;
  ;
}

void ADT_StringBuffer__StringBufferDesc_AppendInt(ADT_StringBuffer__StringBuffer b, OOC_INT32 val) {
  register OOC_INT32 i0;
  OOC_CHAR8 a[32];

  i0 = val;
  IntStr__IntToStr(i0, (void*)(OOC_INT32)a, 32);
  i0 = (OOC_INT32)b;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9578)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i0, (void*)(OOC_INT32)a, 32);
  return;
  ;
}

void ADT_StringBuffer__StringBufferDesc_AppendReal(ADT_StringBuffer__StringBuffer b, OOC_REAL32 val) {
  register OOC_INT32 i0;
  register OOC_REAL32 f0;
  OOC_CHAR8 a[32];

  f0 = val;
  RealStr__RealToStr(f0, (void*)(OOC_INT32)a, 32);
  i0 = (OOC_INT32)b;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9830)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i0, (void*)(OOC_INT32)a, 32);
  return;
  ;
}

void ADT_StringBuffer__StringBufferDesc_AppendSet(ADT_StringBuffer__StringBuffer b, OOC_UINT32 val) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_CHAR8 comma;
  OOC_INT8 i;
  OOC_INT8 begin;

  i0 = (OOC_INT32)b;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10072)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)),ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)((ADT_StringBuffer__StringBuffer)i0, 123u);
  comma = 0u;
  i1 = val;
  i = 0;
  i2=0;i3=0u;
l1_loop:
  i4 = _in(i2,i1);
  if (i4) goto l4;
  {register OOC_INT32 h0=i2;i2=i3;i3=h0;}
  goto l32;
l4:
  begin = i2;
  i4 = i2<31;
  if (i4) goto l7;
  i4=0u;
  goto l9;
l7:
  i4 = _in((i2+1),i1);
  
l9:
  if (i4) goto l11;
  i4=i2;
  goto l22;
l11:
  i4=i2;
l12_loop:
  i4 = i4+1;
  i = i4;
  i5 = i4<31;
  if (i5) goto l15;
  i5=0u;
  goto l17;
l15:
  i5 = _in((i4+1),i1);
  
l17:
  if (i5) goto l12_loop;
l22:
  if (!i3) goto l24;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10300)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)),ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)((ADT_StringBuffer__StringBuffer)i0, 44u);
l24:
  comma = 1u;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10368)))), ADT_StringBuffer__StringBufferDesc_AppendInt)),ADT_StringBuffer__StringBufferDesc_AppendInt)((ADT_StringBuffer__StringBuffer)i0, i2);
  i3 = i2<i4;
  if (!i3) goto l31;
  i2 = i4==(i2+1);
  if (i2) goto l29;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10510)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i0, "..", 3);
  goto l30;
l29:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10458)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)),ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)((ADT_StringBuffer__StringBuffer)i0, 44u);
l30:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10557)))), ADT_StringBuffer__StringBufferDesc_AppendInt)),ADT_StringBuffer__StringBufferDesc_AppendInt)((ADT_StringBuffer__StringBuffer)i0, i4);
l31:
  i3=i4;i2=1u;
l32:
  i3 = i3+1;
  i = i3;
  i4 = i3<=31;
  if (!i4) goto l36;
  {register OOC_INT32 h0=i2;i2=i3;i3=h0;}
  goto l1_loop;
l36:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10624)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)),ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)((ADT_StringBuffer__StringBuffer)i0, 125u);
  return;
  ;
}

void ADT_StringBuffer__StringBufferDesc_AppendBool(ADT_StringBuffer__StringBuffer b, OOC_CHAR8 val) {
  register OOC_INT32 i0;

  i0 = val;
  if (i0) goto l3;
  i0 = (OOC_INT32)b;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10889)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i0, "FALSE", 6);
  goto l4;
l3:
  i0 = (OOC_INT32)b;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10851)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i0, "TRUE", 5);
l4:
  return;
  ;
}

void ADT_StringBuffer__StringBufferDesc_Insert(ADT_StringBuffer__StringBuffer b, Object__Object obj, OOC_INT32 at) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9;
  Object__String s;
  Object__CharsLatin1 c8;
  OOC_INT32 i;
  Object__CharsUTF16 c16;

  i0 = (OOC_INT32)obj;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l70;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11184)))), &_td_Object__StringDesc);
  if (i1) goto l5;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11241)))), Object__ObjectDesc_ToString)),Object__ObjectDesc_ToString)((Object__Object)i0);
  s = (Object__String)i0;
  
  goto l6;
l5:
  s = (Object__String)i0;
  
l6:
  i1 = (OOC_INT32)b;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 11290))+4);
  i3 = *(OOC_INT32*)(_check_pointer(i0, 11299));
  ADT_StringBuffer__StringBufferDesc_EnsureCapacity((ADT_StringBuffer__StringBuffer)i1, (i2+i3));
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11321)))), &_td_Object__String8Desc);
  if (i2) goto l32;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11843)))), &_td_Object__String16Desc);
  if (i2) goto l11;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11840)))), 11840);
  goto l69;
l11:
  i2 = (OOC_INT32)Object__String16Desc_CharsUTF16((Object__String16)i0);
  c16 = (Object__CharsUTF16)i2;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11908))+12);
  i3 = i3==(OOC_INT32)0;
  if (!i3) goto l14;
  ADT_StringBuffer__StringBufferDesc_ConvertTo16((ADT_StringBuffer__StringBuffer)i1);
l14:
  i3 = *(OOC_INT32*)((_check_pointer(i1, 11984))+4);
  i3 = i3-1;
  i = i3;
  i4 = at;
  i5 = i3>=i4;
  if (!i5) goto l22;
l17_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12020))+12);
  i5 = _check_pointer(i5, 12027);
  i6 = *(OOC_INT32*)(_check_pointer(i0, 12031));
  i7 = OOC_ARRAY_LENGTH(i5, 0);
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12044))+12);
  i8 = _check_pointer(i8, 12051);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i8 = *(OOC_UINT16*)(i8+(_check_index(i3, i9, OOC_UINT32, 12051))*2);
  *(OOC_UINT16*)(i5+(_check_index((i3+i6), i7, OOC_UINT32, 12027))*2) = i8;
  i3 = i3+(-1);
  i = i3;
  i5 = i3>=i4;
  if (i5) goto l17_loop;
l22:
  i = 0;
  i3 = *(OOC_INT32*)(_check_pointer(i0, 12092));
  i5 = 0<i3;
  if (!i5) goto l69;
  i5=i4;i4=0;
l25_loop:
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12116))+12);
  i6 = _check_pointer(i6, 12123);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i8 = _check_pointer(i2, 12136);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i8 = *(OOC_UINT16*)(i8+(_check_index(i4, i9, OOC_UINT32, 12136))*2);
  *(OOC_UINT16*)(i6+(_check_index(i5, i7, OOC_UINT32, 12123))*2) = i8;
  i4 = i4+1;
  i = i4;
  i5 = i5+1;
  i6 = i4<i3;
  if (i6) goto l25_loop;
  goto l69;
l32:
  i2 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)i0);
  c8 = (Object__CharsLatin1)i2;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11385))+8);
  i3 = i3!=(OOC_INT32)0;
  if (i3) goto l51;
  i3 = *(OOC_INT32*)((_check_pointer(i1, 11633))+4);
  i3 = i3-1;
  i = i3;
  i4 = at;
  i5 = i3>=i4;
  if (!i5) goto l42;
l37_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11671))+12);
  i5 = _check_pointer(i5, 11678);
  i6 = *(OOC_INT32*)(_check_pointer(i0, 11682));
  i7 = OOC_ARRAY_LENGTH(i5, 0);
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11695))+12);
  i8 = _check_pointer(i8, 11702);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i8 = *(OOC_UINT16*)(i8+(_check_index(i3, i9, OOC_UINT32, 11702))*2);
  *(OOC_UINT16*)(i5+(_check_index((i3+i6), i7, OOC_UINT32, 11678))*2) = i8;
  i3 = i3+(-1);
  i = i3;
  i5 = i3>=i4;
  if (i5) goto l37_loop;
l42:
  i = 0;
  i3 = *(OOC_INT32*)(_check_pointer(i0, 11747));
  i5 = 0<i3;
  if (!i5) goto l69;
  i5=i4;i4=0;
l45_loop:
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11773))+12);
  i6 = _check_pointer(i6, 11780);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i8 = _check_pointer(i2, 11792);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i8 = *(OOC_UINT8*)(i8+(_check_index(i4, i9, OOC_UINT32, 11792)));
  *(OOC_UINT16*)(i6+(_check_index(i5, i7, OOC_UINT32, 11780))*2) = i8;
  i4 = i4+1;
  i = i4;
  i5 = i5+1;
  i6 = i4<i3;
  if (i6) goto l45_loop;
  goto l69;
l51:
  i3 = *(OOC_INT32*)((_check_pointer(i1, 11424))+4);
  i3 = i3-1;
  i = i3;
  i4 = at;
  i5 = i3>=i4;
  if (!i5) goto l59;
l54_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11462))+8);
  i5 = _check_pointer(i5, 11468);
  i6 = *(OOC_INT32*)(_check_pointer(i0, 11472));
  i7 = OOC_ARRAY_LENGTH(i5, 0);
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11485))+8);
  i8 = _check_pointer(i8, 11491);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i8 = *(OOC_UINT8*)(i8+(_check_index(i3, i9, OOC_UINT32, 11491)));
  *(OOC_UINT8*)(i5+(_check_index((i3+i6), i7, OOC_UINT32, 11468))) = i8;
  i3 = i3+(-1);
  i = i3;
  i5 = i3>=i4;
  if (i5) goto l54_loop;
l59:
  i = 0;
  i3 = *(OOC_INT32*)(_check_pointer(i0, 11536));
  i5 = 0<i3;
  if (!i5) goto l69;
  i5=i4;i4=0;
l62_loop:
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11562))+8);
  i6 = _check_pointer(i6, 11568);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i8 = _check_pointer(i2, 11580);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i8 = *(OOC_UINT8*)(i8+(_check_index(i4, i9, OOC_UINT32, 11580)));
  *(OOC_UINT8*)(i6+(_check_index(i5, i7, OOC_UINT32, 11568))) = i8;
  i4 = i4+1;
  i = i4;
  i5 = i5+1;
  i6 = i4<i3;
  if (i6) goto l62_loop;
l69:
  i2 = *(OOC_INT32*)((_check_pointer(i1, 12176))+4);
  i0 = *(OOC_INT32*)(_check_pointer(i0, 12186));
  *(OOC_INT32*)((_check_pointer(i1, 12176))+4) = (i2+i0);
  goto l71;
l70:
  i0 = (OOC_INT32)b;
  i1 = at;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11141)))), ADT_StringBuffer__StringBufferDesc_Insert)),ADT_StringBuffer__StringBufferDesc_Insert)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c1), i1);
l71:
  return;
  ;
}

void ADT_StringBuffer__StringBufferDesc_Delete(ADT_StringBuffer__StringBuffer b, OOC_INT32 start, OOC_INT32 end) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
  OOC_INT32 d;
  OOC_INT32 i;

  i0 = start;
  i1 = end;
  _assert((i0>=0), 127, 12315);
  _assert((i0<=i1), 127, 12340);
  i2 = (OOC_INT32)b;
  i3 = *(OOC_INT32*)((_check_pointer(i2, 12383))+4);
  _assert((i1<=i3), 127, 12367);
  i3 = *(OOC_INT32*)((_check_pointer(i2, 12413))+4);
  i3 = i1==i3;
  if (i3) goto l26;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 12464))+8);
  i3 = i3!=(OOC_INT32)0;
  if (i3) goto l16;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 12628))+12);
  i3 = i3!=(OOC_INT32)0;
  if (!i3) goto l27;
  i1 = i1-i0;
  d = i1;
  i3 = *(OOC_INT32*)((_check_pointer(i2, 12695))+4);
  i3 = i3-i1;
  i = i0;
  i4 = i0<i3;
  if (!i4) goto l14;
  i4 = i1+i0;
  
l9_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 12719))+12);
  i5 = _check_pointer(i5, 12726);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 12734))+12);
  i7 = _check_pointer(i7, 12741);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = *(OOC_UINT16*)(i7+(_check_index(i4, i8, OOC_UINT32, 12741))*2);
  *(OOC_UINT16*)(i5+(_check_index(i0, i6, OOC_UINT32, 12726))*2) = i7;
  i0 = i0+1;
  i = i0;
  i4 = i4+1;
  i5 = i0<i3;
  if (i5) goto l9_loop;
l14:
  i0 = *(OOC_INT32*)((_check_pointer(i2, 12770))+4);
  *(OOC_INT32*)((_check_pointer(i2, 12770))+4) = (i0-i1);
  goto l27;
l16:
  i1 = i1-i0;
  d = i1;
  i3 = *(OOC_INT32*)((_check_pointer(i2, 12530))+4);
  i3 = i3-i1;
  i = i0;
  i4 = i0<i3;
  if (!i4) goto l24;
  i4 = i1+i0;
  
l19_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 12554))+8);
  i5 = _check_pointer(i5, 12560);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 12568))+8);
  i7 = _check_pointer(i7, 12574);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = *(OOC_UINT8*)(i7+(_check_index(i4, i8, OOC_UINT32, 12574)));
  *(OOC_UINT8*)(i5+(_check_index(i0, i6, OOC_UINT32, 12560))) = i7;
  i0 = i0+1;
  i = i0;
  i4 = i4+1;
  i5 = i0<i3;
  if (i5) goto l19_loop;
l24:
  i0 = *(OOC_INT32*)((_check_pointer(i2, 12603))+4);
  *(OOC_INT32*)((_check_pointer(i2, 12603))+4) = (i0-i1);
  goto l27;
l26:
  *(OOC_INT32*)((_check_pointer(i2, 12434))+4) = i0;
l27:
  return;
  ;
}

void OOC_ADT_StringBuffer_init(void) {
  _c0 = Object__NewLatin1Region("NIL", 4, 0, 3);
  _c1 = Object__NewLatin1Region("NIL", 4, 0, 3);

  return;
  ;
}

/* --- */
