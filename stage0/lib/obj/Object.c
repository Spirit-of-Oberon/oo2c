#include <Object.d>
#include <__oo2c.h>
#include <setjmp.h>

Object__String Object__ObjectDesc_ToString(Object__Object x) {
  register OOC_INT32 i0,i1;
  OOC_CHAR8 str[280];
  OOC_INT32 i;
  RT0__Struct _struct;
  auto void Object__ObjectDesc_ToString_Append(RT0__Name name);
  auto void Object__ObjectDesc_ToString_AppendHex(OOC_INT32 x);
    
    void Object__ObjectDesc_ToString_Append(RT0__Name name) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_INT32 j;

      j = 0;
      i0 = (OOC_INT32)name;
      i0 = *(OOC_UINT8*)(_check_pointer(i0, 6438));
      i0 = i0!=0u;
      if (!i0) goto l12;
      i0 = (OOC_INT32)name;
      i1=0;
l3_loop:
      i2 = i;
      i3 = *(OOC_UINT8*)((_check_pointer(i0, 6473))+i1);
      *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i2, 280, OOC_UINT32, 6462))) = i3;
      i = (i2+1);
      i1 = i1+1;
      j = i1;
      i2 = i1!=128;
      if (i2) goto l6;
      i2=0u;
      goto l8;
l6:
      i2 = *(OOC_UINT8*)((_check_pointer(i0, 6438))+i1);
      i2 = i2!=0u;
      
l8:
      if (i2) goto l3_loop;
l12:
      return;
      ;
    }

    
    void Object__ObjectDesc_ToString_AppendHex(OOC_INT32 x) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5;

      i0 = i;
      i1 = i0+7;
      i2=i1;i1=7;
l1_loop:
      i3 = x;
      i4 = (_mod(i3,16))+48;
      i5 = i4>57;
      if (!i5) goto l5;
      i4 = i4+39;
      
l5:
      *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i2, 280, OOC_UINT32, 6761))) = i4;
      x = (i3>>4);
      i2 = i2+(-1);
      i1 = i1+(-1);
      i3 = i1>=0;
      if (i3) goto l1_loop;
l9:
      i = (i0+8);
      return;
      ;
    }


  _copy_8((const void*)"<",(void*)(OOC_INT32)str,280);
  i = 1;
  i0 = (OOC_INT32)x;
  i0 = (OOC_INT32)RT0__TypeOf((void*)i0);
  _struct = (RT0__Struct)i0;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6930))+12);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6937));
  Object__ObjectDesc_ToString_Append((RT0__Name)i0);
  i0 = i;
  *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, 280, OOC_UINT32, 6952))) = 46u;
  i = (i0+1);
  i0 = (OOC_INT32)_struct;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6990))+16);
  Object__ObjectDesc_ToString_Append((RT0__Name)i0);
  i0 = i;
  *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, 280, OOC_UINT32, 7005))) = 32u;
  i0 = i0+1;
  *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, 280, OOC_UINT32, 7032))) = 97u;
  i0 = i0+1;
  *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, 280, OOC_UINT32, 7059))) = 116u;
  i0 = i0+1;
  *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, 280, OOC_UINT32, 7086))) = 32u;
  i1 = (OOC_INT32)x;
  i = (i0+1);
  Object__ObjectDesc_ToString_AppendHex((_type_cast_fast(OOC_INT32, OOC_INT32, i1)));
  i0 = i;
  *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, 280, OOC_UINT32, 7325))) = 62u;
  i0 = (OOC_INT32)Object__NewLatin1Region((void*)(OOC_INT32)str, 280, 0, (i0+1));
  return (Object__String)i0;
  ;
}

OOC_CHAR8 Object__ObjectDesc_Equals(Object__Object x, Object__Object y) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)x;
  i1 = (OOC_INT32)y;
  return (i0==i1);
  ;
}

OOC_INT32 Object__ObjectDesc_HashCode(Object__Object x) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)x;
  i0 = HashCode__Ptr((void*)i0);
  return i0;
  ;
}

static Object__String8 Object__NewString8(OOC_INT32 source, OOC_INT32 length) {
  register OOC_INT32 i0,i1,i2;
  Object__String8 s;
  Object__CharsLatin1 d;

  i0 = (OOC_INT32)RT0__NewObject(_td_Object__String8.baseTypes[0]);
  i1 = length;
  s = (Object__String8)i0;
  i2 = (OOC_INT32)RT0__NewObject(_td_Object__CharsLatin1.baseTypes[0], (i1+1));
  d = (Object__CharsLatin1)i2;
  *(OOC_INT32*)(_check_pointer(i0, 10743)) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 10768))+4) = i2;
  i0 = source;
  _move_block(i0,(_check_pointer(i2, 10807)),i1);
  i0 = (OOC_INT32)d;
  i0 = _check_pointer(i0, 10836);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i2 = length;
  *(OOC_UINT8*)(i0+(_check_index(i2, i1, OOC_UINT32, 10836))) = 0u;
  i0 = (OOC_INT32)s;
  return (Object__String8)i0;
  ;
}

static Object__String16 Object__NewString16(OOC_INT32 source, OOC_INT32 length) {
  register OOC_INT32 i0,i1,i2;
  Object__String16 s;
  Object__CharsUTF16 d;

  i0 = (OOC_INT32)RT0__NewObject(_td_Object__String16.baseTypes[0]);
  i1 = length;
  s = (Object__String16)i0;
  i2 = (OOC_INT32)RT0__NewObject(_td_Object__CharsUTF16.baseTypes[0], (i1+1));
  d = (Object__CharsUTF16)i2;
  *(OOC_INT32*)(_check_pointer(i0, 11043)) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 11068))+4) = i2;
  i0 = source;
  _move_block(i0,(_check_pointer(i2, 11107)),(i1*2));
  i0 = (OOC_INT32)d;
  i0 = _check_pointer(i0, 11140);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i2 = length;
  *(OOC_UINT16*)(i0+(_check_index(i2, i1, OOC_UINT32, 11140))*2) = 0u;
  i0 = (OOC_INT32)s;
  return (Object__String16)i0;
  ;
}

Object__String8 Object__NewLatin1(const OOC_CHAR8 str[], OOC_LEN str_0d) {
  register OOC_INT32 i0,i1;

  i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT32, 11466)));
  i0 = i0!=0u;
  if (i0) goto l3;
  i0=0;
  goto l9;
l3:
  i0=0;
l4_loop:
  i0 = i0+1;
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 11466)));
  i1 = i1!=0u;
  if (i1) goto l4_loop;
l9:
  i0 = (OOC_INT32)Object__NewString8((OOC_INT32)str, i0);
  return (Object__String8)i0;
  ;
}

Object__String8 Object__NewLatin1Region(const OOC_CHAR8 str[], OOC_LEN str_0d, OOC_INT32 start, OOC_INT32 end) {
  register OOC_INT32 i0,i1;

  i0 = start;
  i1 = end;
  i0 = (OOC_INT32)Object__NewString8(((OOC_INT32)str+i0), (i1-i0));
  return (Object__String8)i0;
  ;
}

Object__String8 Object__NewLatin1Char(OOC_CHAR8 ch) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)Object__NewString8((OOC_INT32)&ch, 1);
  return (Object__String8)i0;
  ;
}

Object__String Object__NewUTF16(const OOC_CHAR16 str[], OOC_LEN str_0d) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_INT32 i;
  Object__String16 s;
  Object__CharsUTF16 d;
  OOC_INT32 j;

  i = 0;
  i0 = *(OOC_UINT16*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT32, 12582))*2);
  i0 = i0!=0u;
  if (i0) goto l3;
  i0=0;
  goto l9;
l3:
  i0=0;
l4_loop:
  i0 = i0+1;
  i = i0;
  i1 = *(OOC_UINT16*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 12582))*2);
  i1 = i1!=0u;
  if (i1) goto l4_loop;
l9:
  i1 = (OOC_INT32)RT0__NewObject(_td_Object__String16.baseTypes[0]);
  s = (Object__String16)i1;
  i2 = (OOC_INT32)RT0__NewObject(_td_Object__CharsUTF16.baseTypes[0], (i0+1));
  d = (Object__CharsUTF16)i2;
  *(OOC_INT32*)(_check_pointer(i1, 12657)) = i0;
  *(OOC_INT32*)((_check_pointer(i1, 12677))+4) = i2;
  j = 0;
  i3 = 0<=i0;
  if (!i3) goto l17;
  i3=0;
l12_loop:
  i4 = _check_pointer(i2, 12720);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = *(OOC_UINT16*)((OOC_INT32)str+(_check_index(i3, str_0d, OOC_UINT32, 12730))*2);
  *(OOC_UINT16*)(i4+(_check_index(i3, i5, OOC_UINT32, 12720))*2) = i6;
  i3 = i3+1;
  j = i3;
  i4 = i3<=i0;
  if (i4) goto l12_loop;
l17:
  return (Object__String)i1;
  ;
}

Object__String Object__NewUTF16Region(const OOC_CHAR16 str[], OOC_LEN str_0d, OOC_INT32 start, OOC_INT32 end) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
  OOC_INT32 i;
  Object__String16 s;
  Object__CharsUTF16 d;
  OOC_INT32 j;

  i0 = end;
  i1 = start;
  i2 = i0-i1;
  i = i2;
  i3 = (OOC_INT32)RT0__NewObject(_td_Object__String16.baseTypes[0]);
  s = (Object__String16)i3;
  i4 = (OOC_INT32)RT0__NewObject(_td_Object__CharsUTF16.baseTypes[0], (i2+1));
  d = (Object__CharsUTF16)i4;
  *(OOC_INT32*)(_check_pointer(i3, 13265)) = i2;
  *(OOC_INT32*)((_check_pointer(i3, 13285))+4) = i4;
  j = i1;
  i5 = i1<i0;
  if (!i5) goto l8;
  i5 = (i1*(-1))+i1;
  
l3_loop:
  i6 = _check_pointer(i4, 13336);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i8 = *(OOC_UINT16*)((OOC_INT32)str+(_check_index(i1, str_0d, OOC_UINT32, 13352))*2);
  *(OOC_UINT16*)(i6+(_check_index(i5, i7, OOC_UINT32, 13336))*2) = i8;
  i1 = i1+1;
  j = i1;
  i5 = i5+1;
  i6 = i1<i0;
  if (i6) goto l3_loop;
l8:
  i0 = _check_pointer(i4, 13371);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  *(OOC_UINT16*)(i0+(_check_index(i2, i1, OOC_UINT32, 13371))*2) = 0u;
  return (Object__String)i3;
  ;
}

Object__String Object__NewUTF16Char(OOC_CHAR16 ch) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  Object__String16 s;
  Object__CharsUTF16 d;

  i0 = (OOC_INT32)RT0__NewObject(_td_Object__String16.baseTypes[0]);
  s = (Object__String16)i0;
  i1 = (OOC_INT32)RT0__NewObject(_td_Object__CharsUTF16.baseTypes[0], 2);
  d = (Object__CharsUTF16)i1;
  *(OOC_INT32*)(_check_pointer(i0, 13733)) = 1;
  *(OOC_INT32*)((_check_pointer(i0, 13753))+4) = i1;
  i2 = _check_pointer(i1, 13771);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = ch;
  *(OOC_UINT16*)(i2+(_check_index(0, i3, OOC_UINT8, 13771))*2) = i4;
  i1 = _check_pointer(i1, 13787);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  *(OOC_UINT16*)(i1+(_check_index(1, i2, OOC_UINT8, 13787))*2) = 0u;
  return (Object__String)i0;
  ;
}

Object__String Object__NewUCS4Char(OOC_CHAR32 ch) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  Object__String16 s;
  Object__CharsUTF16 d;
  OOC_INT32 v;

  i0 = ch;
  i1 = (OOC_UINT32)i0<(OOC_UINT32)65536u;
  if (i1) goto l3;
  i1 = (OOC_INT32)RT0__NewObject(_td_Object__String16.baseTypes[0]);
  s = (Object__String16)i1;
  i2 = (OOC_INT32)RT0__NewObject(_td_Object__CharsUTF16.baseTypes[0], 3);
  d = (Object__CharsUTF16)i2;
  *(OOC_INT32*)(_check_pointer(i1, 14290)) = 2;
  *(OOC_INT32*)((_check_pointer(i1, 14312))+4) = i2;
  i0 = i0-65536;
  v = i0;
  i3 = _check_pointer(i2, 14373);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_UINT16*)(i3+(_check_index(0, i4, OOC_UINT8, 14373))*2) = (55296+(i0>>10));
  i3 = _check_pointer(i2, 14428);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_UINT16*)(i3+(_check_index(1, i4, OOC_UINT8, 14428))*2) = (56320+(_mod(i0,1024)));
  i0 = _check_pointer(i2, 14484);
  i2 = OOC_ARRAY_LENGTH(i0, 0);
  *(OOC_UINT16*)(i0+(_check_index(2, i2, OOC_UINT8, 14484))*2) = 0u;
  return (Object__String)i1;
  goto l4;
l3:
  i0 = (OOC_INT32)Object__NewUTF16Char(i0);
  return (Object__String)i0;
l4:
  _failed_function(13843); return 0;
  ;
}

Object__String Object__NewUCS4Region(const OOC_CHAR32 str[], OOC_LEN str_0d, OOC_INT32 start, OOC_INT32 end) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  OOC_INT32 c;
  OOC_INT32 i;
  Object__CharsUTF16 d;
  OOC_INT32 v;
  Object__String16 s;

  c = 0;
  i0 = start;
  i1 = end;
  i2 = i0!=i1;
  if (i2) goto l3;
  i3=0;
  goto l13;
l3:
  i3=i0;i4=0;
l4_loop:
  i5 = *(OOC_UINT32*)((OOC_INT32)str+(_check_index(i3, str_0d, OOC_UINT32, 15043))*4);
  i5 = (OOC_UINT32)i5>=(OOC_UINT32)65536u;
  if (i5) goto l7;
  i4 = i4+1;
  c = i4;
  
  goto l8;
l7:
  i4 = i4+2;
  c = i4;
  
l8:
  i3 = i3+1;
  i5 = i3!=i1;
  if (i5) goto l4_loop;
l12:
  i3=i4;
l13:
  i4 = (OOC_INT32)RT0__NewObject(_td_Object__CharsUTF16.baseTypes[0], (i3+1));
  d = (Object__CharsUTF16)i4;
  i = 0;
  if (!i2) goto l25;
  i2=0;
l16_loop:
  i5 = *(OOC_UINT32*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 15221))*4);
  i5 = (OOC_UINT32)i5>=(OOC_UINT32)65536u;
  if (i5) goto l19;
  i5 = _check_pointer(i4, 15459);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i7 = *(OOC_UINT32*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 15475))*4);
  *(OOC_UINT16*)(i5+(_check_index(i2, i6, OOC_UINT32, 15459))*2) = i7;
  i2 = i2+1;
  i = i2;
  
  goto l20;
l19:
  i5 = *(OOC_UINT32*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 15273))*4);
  i5 = i5-65536;
  v = i5;
  i6 = _check_pointer(i4, 15312);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  *(OOC_UINT16*)(i6+(_check_index(i2, i7, OOC_UINT32, 15312))*2) = (55296+(i5>>10));
  i6 = _check_pointer(i4, 15369);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  *(OOC_UINT16*)(i6+(_check_index((i2+1), i7, OOC_UINT32, 15369))*2) = (56320+(_mod(i5,1024)));
  i2 = i2+2;
  i = i2;
  
l20:
  i0 = i0+1;
  start = i0;
  i5 = i0!=i1;
  if (i5) goto l16_loop;
l25:
  i0 = (OOC_INT32)RT0__NewObject(_td_Object__String16.baseTypes[0]);
  s = (Object__String16)i0;
  *(OOC_INT32*)(_check_pointer(i0, 15557)) = i3;
  *(OOC_INT32*)((_check_pointer(i0, 15576))+4) = i4;
  return (Object__String)i0;
  ;
}

Object__String Object__NewUCS4(const OOC_CHAR32 str[], OOC_LEN str_0d) {
  register OOC_INT32 i0,i1;

  i0 = *(OOC_UINT32*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT32, 15935))*4);
  i0 = i0!=0u;
  if (i0) goto l3;
  i0=0;
  goto l9;
l3:
  i0=0;
l4_loop:
  i0 = i0+1;
  i1 = *(OOC_UINT32*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 15935))*4);
  i1 = i1!=0u;
  if (i1) goto l4_loop;
l9:
  i0 = (OOC_INT32)Object__NewUCS4Region((void*)(OOC_INT32)str, str_0d, 0, i0);
  return (Object__String)i0;
  ;
}

Object__String Object__Concat2(Object__String s1, Object__String s2) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9;
  Object__String8 c8;
  Object__String16 c32;
  OOC_INT32 i;

  i0 = (OOC_INT32)s1;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16261)))), &_td_Object__String8Desc);
  if (i1) goto l23;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17175)))), &_td_Object__String16Desc);
  if (i1) goto l5;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17171)))), 17171);
  goto l40;
l5:
  i1 = (OOC_INT32)s2;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17202)))), &_td_Object__String8Desc);
  if (i2) goto l12;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17573)))), &_td_Object__String16Desc);
  if (i2) goto l10;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17569)))), 17569);
  goto l40;
l10:
  i2 = (OOC_INT32)RT0__NewObject(_td_Object__String16.baseTypes[0]);
  c32 = (Object__String16)i2;
  i3 = *(OOC_INT32*)(_check_pointer(i1, 17680));
  i4 = *(OOC_INT32*)(_check_pointer(i0, 17670));
  *(OOC_INT32*)(_check_pointer(i2, 17657)) = (i4+i3);
  i1 = *(OOC_INT32*)(_check_pointer(i1, 17723));
  i3 = *(OOC_INT32*)(_check_pointer(i0, 17713));
  *(OOC_INT32*)((_check_pointer(i2, 17704))+4) = ((OOC_INT32)RT0__NewObject(_td_Object__CharsUTF16.baseTypes[0], ((i3+i1)+1)));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17758))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 17796))+4);
  i0 = *(OOC_INT32*)(_check_pointer(i0, 17827));
  _move_block((_check_pointer(i1, 17763)),(_check_pointer(i2, 17801)),(i0*2));
  i0 = (OOC_INT32)s2;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17875))+4);
  i2 = (OOC_INT32)c32;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 17913))+4);
  i3 = (OOC_INT32)s1;
  i0 = *(OOC_INT32*)(_check_pointer(i0, 17969));
  i3 = *(OOC_INT32*)(_check_pointer(i3, 17923));
  _move_block((_check_pointer(i1, 17880)),((_check_pointer(i2, 17918))+i3*2),(2+i0*2));
  i0 = (OOC_INT32)c32;
  return (Object__String)i0;
  goto l40;
l12:
  i2 = (OOC_INT32)RT0__NewObject(_td_Object__String16.baseTypes[0]);
  c32 = (Object__String16)i2;
  i3 = *(OOC_INT32*)(_check_pointer(i1, 17267));
  i4 = *(OOC_INT32*)(_check_pointer(i0, 17257));
  *(OOC_INT32*)(_check_pointer(i2, 17244)) = (i4+i3);
  i1 = *(OOC_INT32*)(_check_pointer(i1, 17310));
  i3 = *(OOC_INT32*)(_check_pointer(i0, 17300));
  *(OOC_INT32*)((_check_pointer(i2, 17291))+4) = ((OOC_INT32)RT0__NewObject(_td_Object__CharsUTF16.baseTypes[0], ((i3+i1)+1)));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17345))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 17383))+4);
  i0 = *(OOC_INT32*)(_check_pointer(i0, 17414));
  _move_block((_check_pointer(i1, 17350)),(_check_pointer(i2, 17388)),(i0*2));
  i0 = (OOC_INT32)s2;
  i = 0;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 17463));
  i2 = (OOC_INT32)c32;
  i3 = 0<=i1;
  if (!i3) goto l20;
  i3 = (OOC_INT32)s1;
  i4=0;
l15_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 17487))+4);
  i5 = _check_pointer(i5, 17492);
  i6 = *(OOC_INT32*)(_check_pointer(i3, 17495));
  i7 = OOC_ARRAY_LENGTH(i5, 0);
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17511))+4);
  i8 = _check_pointer(i8, 17516);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i8 = *(OOC_UINT8*)(i8+(_check_index(i4, i9, OOC_UINT32, 17516)));
  *(OOC_UINT16*)(i5+(_check_index((i6+i4), i7, OOC_UINT32, 17492))*2) = i8;
  i4 = i4+1;
  i = i4;
  i5 = i4<=i1;
  if (i5) goto l15_loop;
l20:
  return (Object__String)i2;
  goto l40;
l23:
  i1 = (OOC_INT32)s2;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16287)))), &_td_Object__String8Desc);
  if (i2) goto l38;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16724)))), &_td_Object__String16Desc);
  if (i2) goto l28;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16720)))), 16720);
  goto l40;
l28:
  i2 = (OOC_INT32)RT0__NewObject(_td_Object__String16.baseTypes[0]);
  c32 = (Object__String16)i2;
  i3 = *(OOC_INT32*)(_check_pointer(i1, 16830));
  i4 = *(OOC_INT32*)(_check_pointer(i0, 16820));
  *(OOC_INT32*)(_check_pointer(i2, 16807)) = (i4+i3);
  i3 = *(OOC_INT32*)(_check_pointer(i1, 16873));
  i4 = *(OOC_INT32*)(_check_pointer(i0, 16863));
  *(OOC_INT32*)((_check_pointer(i2, 16854))+4) = ((OOC_INT32)RT0__NewObject(_td_Object__CharsUTF16.baseTypes[0], ((i4+i3)+1)));
  i = 0;
  i3 = *(OOC_INT32*)(_check_pointer(i0, 16909));
  i4 = 0<i3;
  if (!i4) goto l36;
  i4=0;
l31_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 16935))+4);
  i5 = _check_pointer(i5, 16940);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16949))+4);
  i7 = _check_pointer(i7, 16954);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = *(OOC_UINT8*)(i7+(_check_index(i4, i8, OOC_UINT32, 16954)));
  *(OOC_UINT16*)(i5+(_check_index(i4, i6, OOC_UINT32, 16940))*2) = i7;
  i4 = i4+1;
  i = i4;
  i5 = i4<i3;
  if (i5) goto l31_loop;
l36:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 16995))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 17033))+4);
  i1 = *(OOC_INT32*)(_check_pointer(i1, 17089));
  i0 = *(OOC_INT32*)(_check_pointer(i0, 17043));
  _move_block((_check_pointer(i3, 17000)),((_check_pointer(i2, 17038))+i0*2),(2+i1*2));
  i0 = (OOC_INT32)c32;
  return (Object__String)i0;
  goto l40;
l38:
  i2 = (OOC_INT32)RT0__NewObject(_td_Object__String8.baseTypes[0]);
  c8 = (Object__String8)i2;
  i3 = *(OOC_INT32*)(_check_pointer(i1, 16387));
  i4 = *(OOC_INT32*)(_check_pointer(i0, 16377));
  *(OOC_INT32*)(_check_pointer(i2, 16364)) = (i4+i3);
  i1 = *(OOC_INT32*)(_check_pointer(i1, 16429));
  i3 = *(OOC_INT32*)(_check_pointer(i0, 16419));
  *(OOC_INT32*)((_check_pointer(i2, 16410))+4) = ((OOC_INT32)RT0__NewObject(_td_Object__CharsLatin1.baseTypes[0], ((i3+i1)+1)));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16464))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 16501))+4);
  i0 = *(OOC_INT32*)(_check_pointer(i0, 16532));
  _move_block((_check_pointer(i1, 16469)),(_check_pointer(i2, 16506)),i0);
  i0 = (OOC_INT32)s2;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16576))+4);
  i2 = (OOC_INT32)c8;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 16613))+4);
  i3 = (OOC_INT32)s1;
  i0 = *(OOC_INT32*)(_check_pointer(i0, 16654));
  i3 = *(OOC_INT32*)(_check_pointer(i3, 16623));
  _move_block((_check_pointer(i1, 16581)),((_check_pointer(i2, 16618))+i3),(i0+1));
  i0 = (OOC_INT32)c8;
  return (Object__String)i0;
l40:
  _failed_function(16034); return 0;
  ;
}

Object__String Object__StringDesc_Concat(Object__String s, Object__String t) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)s;
  i1 = (OOC_INT32)t;
  i0 = (OOC_INT32)Object__Concat2((Object__String)i0, (Object__String)i1);
  return (Object__String)i0;
  ;
}

Object__CharsLatin1 Object__String8Desc_CharsLatin1(Object__String8 s) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)s;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18552))+4);
  return (Object__CharsLatin1)i0;
  ;
}

Object__CharsUTF16 Object__String16Desc_CharsUTF16(Object__String16 s) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)s;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18850))+4);
  return (Object__CharsUTF16)i0;
  ;
}

Object__String Object__StringDesc_ToString(Object__String s) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)s;
  return (Object__String)i0;
  ;
}

Object__String8 Object__StringDesc_ToString8(Object__String s, OOC_CHAR8 replace) {

  _failed_function(19039); return 0;
  ;
}

Object__String8 Object__String8Desc_ToString8(Object__String8 s, OOC_CHAR8 replace) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)s;
  return (Object__String8)i0;
  ;
}

Object__String8 Object__String16Desc_ToString8(Object__String16 s, OOC_CHAR8 replace) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
  Object__CharsLatin1 data8;
  OOC_INT32 i;
  Object__String8 s8;

  i0 = (OOC_INT32)s;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 19528));
  i1 = (OOC_INT32)RT0__NewObject(_td_Object__CharsLatin1.baseTypes[0], (i1+1));
  data8 = (Object__CharsLatin1)i1;
  i = 0;
  i2 = *(OOC_INT32*)(_check_pointer(i0, 19559));
  i3 = 0<=i2;
  if (!i3) goto l12;
  i3 = replace;
  i4=0;
l3_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19581))+4);
  i5 = _check_pointer(i5, 19586);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = *(OOC_UINT16*)(i5+(_check_index(i4, i6, OOC_UINT32, 19586))*2);
  i5 = (OOC_UINT16)i5>(OOC_UINT16)255u;
  if (i5) goto l6;
  i5 = _check_pointer(i1, 19713);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19727))+4);
  i7 = _check_pointer(i7, 19732);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = *(OOC_UINT16*)(i7+(_check_index(i4, i8, OOC_UINT32, 19732))*2);
  *(OOC_UINT8*)(i5+(_check_index(i4, i6, OOC_UINT32, 19713))) = i7;
  goto l7;
l6:
  i5 = _check_pointer(i1, 19673);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  *(OOC_UINT8*)(i5+(_check_index(i4, i6, OOC_UINT32, 19673))) = i3;
l7:
  i4 = i4+1;
  i = i4;
  i5 = i4<=i2;
  if (i5) goto l3_loop;
l12:
  i2 = (OOC_INT32)RT0__NewObject(_td_Object__String8.baseTypes[0]);
  s8 = (Object__String8)i2;
  i0 = *(OOC_INT32*)(_check_pointer(i0, 19790));
  *(OOC_INT32*)(_check_pointer(i2, 19778)) = i0;
  *(OOC_INT32*)((_check_pointer(i2, 19805))+4) = i1;
  return (Object__String8)i2;
  ;
}

Object__String16 Object__StringDesc_ToString16(Object__String s) {

  _failed_function(19887); return 0;
  ;
}

Object__String16 Object__String8Desc_ToString16(Object__String8 s) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  Object__CharsUTF16 data16;
  OOC_INT32 i;
  Object__String16 s16;

  i0 = (OOC_INT32)s;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 20152));
  i1 = (OOC_INT32)RT0__NewObject(_td_Object__CharsUTF16.baseTypes[0], (i1+1));
  data16 = (Object__CharsUTF16)i1;
  i = 0;
  i2 = *(OOC_INT32*)(_check_pointer(i0, 20183));
  i3 = 0<=i2;
  if (!i3) goto l8;
  i3=0;
l3_loop:
  i4 = _check_pointer(i1, 20206);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20214))+4);
  i6 = _check_pointer(i6, 20219);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = *(OOC_UINT8*)(i6+(_check_index(i3, i7, OOC_UINT32, 20219)));
  *(OOC_UINT16*)(i4+(_check_index(i3, i5, OOC_UINT32, 20206))*2) = i6;
  i3 = i3+1;
  i = i3;
  i4 = i3<=i2;
  if (i4) goto l3_loop;
l8:
  i2 = (OOC_INT32)RT0__NewObject(_td_Object__String16.baseTypes[0]);
  s16 = (Object__String16)i2;
  i0 = *(OOC_INT32*)(_check_pointer(i0, 20271));
  *(OOC_INT32*)(_check_pointer(i2, 20259)) = i0;
  *(OOC_INT32*)((_check_pointer(i2, 20287))+4) = i1;
  return (Object__String16)i2;
  ;
}

Object__String16 Object__String16Desc_ToString16(Object__String16 s) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)s;
  return (Object__String16)i0;
  ;
}

OOC_CHAR8 Object__StringDesc_Equals(Object__String s, Object__Object y) {

  _failed_function(20462); return 0;
  ;
}

OOC_CHAR8 Object__String8Desc_Equals(Object__String8 s, Object__Object y) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_INT32 i;

  i0 = (OOC_INT32)y;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l3;
  i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20612)))), &_td_Object__StringDesc));
  
  goto l5;
l3:
  i1=1u;
l5:
  if (i1) goto l7;
  i1 = (OOC_INT32)s;
  i2 = *(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20640)))), &_td_Object__StringDesc, 20640)), 20647));
  i1 = *(OOC_INT32*)(_check_pointer(i1, 20628));
  i1 = i1!=i2;
  
  goto l9;
l7:
  i1=1u;
l9:
  if (i1) goto l53;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20702)))), &_td_Object__String8Desc);
  if (i1) goto l34;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20860)))), &_td_Object__String16Desc);
  if (i1) goto l15;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20857)))), 20857);
  goto l54;
l15:
  i = 0;
  i1 = (OOC_INT32)s;
  i2 = *(OOC_INT32*)(_check_pointer(i1, 20910));
  i2 = 0!=i2;
  if (i2) goto l18;
  i2=0u;
  goto l20;
l18:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 20923))+4);
  i2 = _check_pointer(i2, 20928);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20935))+4);
  i4 = _check_pointer(i4, 20940);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i2 = *(OOC_UINT8*)(i2+(_check_index(0, i3, OOC_UINT32, 20928)));
  i3 = *(OOC_UINT16*)(i4+(_check_index(0, i5, OOC_UINT32, 20940))*2);
  i2 = i2==i3;
  
l20:
  if (i2) goto l22;
  i0=0;
  goto l32;
l22:
  i2=0;
l23_loop:
  i2 = i2+1;
  i = i2;
  i3 = *(OOC_INT32*)(_check_pointer(i1, 20910));
  i3 = i2!=i3;
  if (i3) goto l26;
  i3=0u;
  goto l28;
l26:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 20923))+4);
  i3 = _check_pointer(i3, 20928);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20935))+4);
  i5 = _check_pointer(i5, 20940);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i3 = *(OOC_UINT8*)(i3+(_check_index(i2, i4, OOC_UINT32, 20928)));
  i4 = *(OOC_UINT16*)(i5+(_check_index(i2, i6, OOC_UINT32, 20940))*2);
  i3 = i3==i4;
  
l28:
  if (i3) goto l23_loop;
l31:
  i0=i2;
l32:
  i1 = *(OOC_INT32*)(_check_pointer(i1, 21000));
  return (i0==i1);
  goto l54;
l34:
  i = 0;
  i1 = (OOC_INT32)s;
  i2 = *(OOC_INT32*)(_check_pointer(i1, 20751));
  i2 = 0!=i2;
  if (i2) goto l37;
  i2=0u;
  goto l39;
l37:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 20764))+4);
  i2 = _check_pointer(i2, 20769);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20776))+4);
  i4 = _check_pointer(i4, 20781);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i2 = *(OOC_UINT8*)(i2+(_check_index(0, i3, OOC_UINT32, 20769)));
  i3 = *(OOC_UINT8*)(i4+(_check_index(0, i5, OOC_UINT32, 20781)));
  i2 = i2==i3;
  
l39:
  if (i2) goto l41;
  i0=0;
  goto l51;
l41:
  i2=0;
l42_loop:
  i2 = i2+1;
  i = i2;
  i3 = *(OOC_INT32*)(_check_pointer(i1, 20751));
  i3 = i2!=i3;
  if (i3) goto l45;
  i3=0u;
  goto l47;
l45:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 20764))+4);
  i3 = _check_pointer(i3, 20769);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20776))+4);
  i5 = _check_pointer(i5, 20781);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i3 = *(OOC_UINT8*)(i3+(_check_index(i2, i4, OOC_UINT32, 20769)));
  i4 = *(OOC_UINT8*)(i5+(_check_index(i2, i6, OOC_UINT32, 20781)));
  i3 = i3==i4;
  
l47:
  if (i3) goto l42_loop;
l50:
  i0=i2;
l51:
  i1 = *(OOC_INT32*)(_check_pointer(i1, 20841));
  return (i0==i1);
  goto l54;
l53:
  return 0u;
l54:
  _failed_function(20529); return 0;
  ;
}

OOC_CHAR8 Object__String16Desc_Equals(Object__String16 s, Object__Object y) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_INT32 i;

  i0 = (OOC_INT32)y;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l3;
  i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21152)))), &_td_Object__StringDesc));
  
  goto l5;
l3:
  i1=1u;
l5:
  if (i1) goto l7;
  i1 = (OOC_INT32)s;
  i2 = *(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21180)))), &_td_Object__StringDesc, 21180)), 21187));
  i1 = *(OOC_INT32*)(_check_pointer(i1, 21168));
  i1 = i1!=i2;
  
  goto l9;
l7:
  i1=1u;
l9:
  if (i1) goto l53;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21242)))), &_td_Object__String8Desc);
  if (i1) goto l34;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21400)))), &_td_Object__String16Desc);
  if (i1) goto l15;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21397)))), 21397);
  goto l54;
l15:
  i = 0;
  i1 = (OOC_INT32)s;
  i2 = *(OOC_INT32*)(_check_pointer(i1, 21450));
  i2 = 0!=i2;
  if (i2) goto l18;
  i2=0u;
  goto l20;
l18:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 21463))+4);
  i2 = _check_pointer(i2, 21468);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21475))+4);
  i4 = _check_pointer(i4, 21480);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i2 = *(OOC_UINT16*)(i2+(_check_index(0, i3, OOC_UINT32, 21468))*2);
  i3 = *(OOC_UINT16*)(i4+(_check_index(0, i5, OOC_UINT32, 21480))*2);
  i2 = i2==i3;
  
l20:
  if (i2) goto l22;
  i0=0;
  goto l32;
l22:
  i2=0;
l23_loop:
  i2 = i2+1;
  i = i2;
  i3 = *(OOC_INT32*)(_check_pointer(i1, 21450));
  i3 = i2!=i3;
  if (i3) goto l26;
  i3=0u;
  goto l28;
l26:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 21463))+4);
  i3 = _check_pointer(i3, 21468);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21475))+4);
  i5 = _check_pointer(i5, 21480);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i3 = *(OOC_UINT16*)(i3+(_check_index(i2, i4, OOC_UINT32, 21468))*2);
  i4 = *(OOC_UINT16*)(i5+(_check_index(i2, i6, OOC_UINT32, 21480))*2);
  i3 = i3==i4;
  
l28:
  if (i3) goto l23_loop;
l31:
  i0=i2;
l32:
  i1 = *(OOC_INT32*)(_check_pointer(i1, 21540));
  return (i0==i1);
  goto l54;
l34:
  i = 0;
  i1 = (OOC_INT32)s;
  i2 = *(OOC_INT32*)(_check_pointer(i1, 21291));
  i2 = 0!=i2;
  if (i2) goto l37;
  i2=0u;
  goto l39;
l37:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 21304))+4);
  i2 = _check_pointer(i2, 21309);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21316))+4);
  i4 = _check_pointer(i4, 21321);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i2 = *(OOC_UINT16*)(i2+(_check_index(0, i3, OOC_UINT32, 21309))*2);
  i3 = *(OOC_UINT8*)(i4+(_check_index(0, i5, OOC_UINT32, 21321)));
  i2 = i2==i3;
  
l39:
  if (i2) goto l41;
  i0=0;
  goto l51;
l41:
  i2=0;
l42_loop:
  i2 = i2+1;
  i = i2;
  i3 = *(OOC_INT32*)(_check_pointer(i1, 21291));
  i3 = i2!=i3;
  if (i3) goto l45;
  i3=0u;
  goto l47;
l45:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 21304))+4);
  i3 = _check_pointer(i3, 21309);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21316))+4);
  i5 = _check_pointer(i5, 21321);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i3 = *(OOC_UINT16*)(i3+(_check_index(i2, i4, OOC_UINT32, 21309))*2);
  i4 = *(OOC_UINT8*)(i5+(_check_index(i2, i6, OOC_UINT32, 21321)));
  i3 = i3==i4;
  
l47:
  if (i3) goto l42_loop;
l50:
  i0=i2;
l51:
  i1 = *(OOC_INT32*)(_check_pointer(i1, 21381));
  return (i0==i1);
  goto l54;
l53:
  return 0u;
l54:
  _failed_function(21069); return 0;
  ;
}

OOC_CHAR8 Object__StringDesc_EqualsIgnoreCase(Object__String s, Object__Object y) {

  _failed_function(21618); return 0;
  ;
}

OOC_CHAR8 Object__String8Desc_EqualsIgnoreCase(Object__String8 s, Object__Object y) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_INT32 i;

  i0 = (OOC_INT32)y;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l3;
  i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21798)))), &_td_Object__StringDesc));
  
  goto l5;
l3:
  i1=1u;
l5:
  if (i1) goto l7;
  i1 = (OOC_INT32)s;
  i2 = *(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21826)))), &_td_Object__StringDesc, 21826)), 21833));
  i1 = *(OOC_INT32*)(_check_pointer(i1, 21814));
  i1 = i1!=i2;
  
  goto l9;
l7:
  i1=1u;
l9:
  if (i1) goto l53;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21963)))), &_td_Object__String8Desc);
  if (i1) goto l34;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22131)))), &_td_Object__String16Desc);
  if (i1) goto l15;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22128)))), 22128);
  goto l54;
l15:
  i = 0;
  i1 = (OOC_INT32)s;
  i2 = *(OOC_INT32*)(_check_pointer(i1, 22181));
  i2 = 0!=i2;
  if (i2) goto l18;
  i2=0u;
  goto l20;
l18:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 22198))+4);
  i2 = _check_pointer(i2, 22203);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22215))+4);
  i4 = _check_pointer(i4, 22220);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i2 = *(OOC_UINT8*)(i2+(_check_index(0, i3, OOC_UINT32, 22203)));
  i3 = *(OOC_UINT16*)(i4+(_check_index(0, i5, OOC_UINT32, 22220))*2);
  i2 = (_cap(i2))==(_cap(i3));
  
l20:
  if (i2) goto l22;
  i0=0;
  goto l32;
l22:
  i2=0;
l23_loop:
  i2 = i2+1;
  i = i2;
  i3 = *(OOC_INT32*)(_check_pointer(i1, 22181));
  i3 = i2!=i3;
  if (i3) goto l26;
  i3=0u;
  goto l28;
l26:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 22198))+4);
  i3 = _check_pointer(i3, 22203);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22215))+4);
  i5 = _check_pointer(i5, 22220);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i3 = *(OOC_UINT8*)(i3+(_check_index(i2, i4, OOC_UINT32, 22203)));
  i4 = *(OOC_UINT16*)(i5+(_check_index(i2, i6, OOC_UINT32, 22220))*2);
  i3 = (_cap(i3))==(_cap(i4));
  
l28:
  if (i3) goto l23_loop;
l31:
  i0=i2;
l32:
  i1 = *(OOC_INT32*)(_check_pointer(i1, 22281));
  return (i0==i1);
  goto l54;
l34:
  i = 0;
  i1 = (OOC_INT32)s;
  i2 = *(OOC_INT32*)(_check_pointer(i1, 22012));
  i2 = 0!=i2;
  if (i2) goto l37;
  i2=0u;
  goto l39;
l37:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 22029))+4);
  i2 = _check_pointer(i2, 22034);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22046))+4);
  i4 = _check_pointer(i4, 22051);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i2 = *(OOC_UINT8*)(i2+(_check_index(0, i3, OOC_UINT32, 22034)));
  i3 = *(OOC_UINT8*)(i4+(_check_index(0, i5, OOC_UINT32, 22051)));
  i2 = (_cap(i2))==(_cap(i3));
  
l39:
  if (i2) goto l41;
  i0=0;
  goto l51;
l41:
  i2=0;
l42_loop:
  i2 = i2+1;
  i = i2;
  i3 = *(OOC_INT32*)(_check_pointer(i1, 22012));
  i3 = i2!=i3;
  if (i3) goto l45;
  i3=0u;
  goto l47;
l45:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 22029))+4);
  i3 = _check_pointer(i3, 22034);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22046))+4);
  i5 = _check_pointer(i5, 22051);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i3 = *(OOC_UINT8*)(i3+(_check_index(i2, i4, OOC_UINT32, 22034)));
  i4 = *(OOC_UINT8*)(i5+(_check_index(i2, i6, OOC_UINT32, 22051)));
  i3 = (_cap(i3))==(_cap(i4));
  
l47:
  if (i3) goto l42_loop;
l50:
  i0=i2;
l51:
  i1 = *(OOC_INT32*)(_check_pointer(i1, 22112));
  return (i0==i1);
  goto l54;
l53:
  return 0u;
l54:
  _failed_function(21705); return 0;
  ;
}

OOC_CHAR8 Object__String16Desc_EqualsIgnoreCase(Object__String16 s, Object__Object y) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_INT32 i;

  i0 = (OOC_INT32)y;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l3;
  i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22453)))), &_td_Object__StringDesc));
  
  goto l5;
l3:
  i1=1u;
l5:
  if (i1) goto l7;
  i1 = (OOC_INT32)s;
  i2 = *(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22481)))), &_td_Object__StringDesc, 22481)), 22488));
  i1 = *(OOC_INT32*)(_check_pointer(i1, 22469));
  i1 = i1!=i2;
  
  goto l9;
l7:
  i1=1u;
l9:
  if (i1) goto l53;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22618)))), &_td_Object__String8Desc);
  if (i1) goto l34;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22786)))), &_td_Object__String16Desc);
  if (i1) goto l15;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22783)))), 22783);
  goto l54;
l15:
  i = 0;
  i1 = (OOC_INT32)s;
  i2 = *(OOC_INT32*)(_check_pointer(i1, 22836));
  i2 = 0!=i2;
  if (i2) goto l18;
  i2=0u;
  goto l20;
l18:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 22853))+4);
  i2 = _check_pointer(i2, 22858);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22870))+4);
  i4 = _check_pointer(i4, 22875);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i2 = *(OOC_UINT16*)(i2+(_check_index(0, i3, OOC_UINT32, 22858))*2);
  i3 = *(OOC_UINT16*)(i4+(_check_index(0, i5, OOC_UINT32, 22875))*2);
  i2 = (_cap(i2))==(_cap(i3));
  
l20:
  if (i2) goto l22;
  i0=0;
  goto l32;
l22:
  i2=0;
l23_loop:
  i2 = i2+1;
  i = i2;
  i3 = *(OOC_INT32*)(_check_pointer(i1, 22836));
  i3 = i2!=i3;
  if (i3) goto l26;
  i3=0u;
  goto l28;
l26:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 22853))+4);
  i3 = _check_pointer(i3, 22858);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22870))+4);
  i5 = _check_pointer(i5, 22875);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i3 = *(OOC_UINT16*)(i3+(_check_index(i2, i4, OOC_UINT32, 22858))*2);
  i4 = *(OOC_UINT16*)(i5+(_check_index(i2, i6, OOC_UINT32, 22875))*2);
  i3 = (_cap(i3))==(_cap(i4));
  
l28:
  if (i3) goto l23_loop;
l31:
  i0=i2;
l32:
  i1 = *(OOC_INT32*)(_check_pointer(i1, 22936));
  return (i0==i1);
  goto l54;
l34:
  i = 0;
  i1 = (OOC_INT32)s;
  i2 = *(OOC_INT32*)(_check_pointer(i1, 22667));
  i2 = 0!=i2;
  if (i2) goto l37;
  i2=0u;
  goto l39;
l37:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 22684))+4);
  i2 = _check_pointer(i2, 22689);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22701))+4);
  i4 = _check_pointer(i4, 22706);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i2 = *(OOC_UINT16*)(i2+(_check_index(0, i3, OOC_UINT32, 22689))*2);
  i3 = *(OOC_UINT8*)(i4+(_check_index(0, i5, OOC_UINT32, 22706)));
  i2 = (_cap(i2))==(_cap(i3));
  
l39:
  if (i2) goto l41;
  i0=0;
  goto l51;
l41:
  i2=0;
l42_loop:
  i2 = i2+1;
  i = i2;
  i3 = *(OOC_INT32*)(_check_pointer(i1, 22667));
  i3 = i2!=i3;
  if (i3) goto l45;
  i3=0u;
  goto l47;
l45:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 22684))+4);
  i3 = _check_pointer(i3, 22689);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22701))+4);
  i5 = _check_pointer(i5, 22706);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i3 = *(OOC_UINT16*)(i3+(_check_index(i2, i4, OOC_UINT32, 22689))*2);
  i4 = *(OOC_UINT8*)(i5+(_check_index(i2, i6, OOC_UINT32, 22706)));
  i3 = (_cap(i3))==(_cap(i4));
  
l47:
  if (i3) goto l42_loop;
l50:
  i0=i2;
l51:
  i1 = *(OOC_INT32*)(_check_pointer(i1, 22767));
  return (i0==i1);
  goto l54;
l53:
  return 0u;
l54:
  _failed_function(22360); return 0;
  ;
}

OOC_INT32 Object__StringDesc_Compare(Object__String s, Object__Object y) {

  _failed_function(23024); return 0;
  ;
}

OOC_INT32 Object__String8Desc_Compare(Object__String8 s, Object__Object y) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  OOC_INT32 min;
  OOC_INT32 i;

  i0 = (OOC_INT32)s;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 23576));
  min = i1;
  i2 = (OOC_INT32)y;
  i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 23595)))), &_td_Object__String8Desc);
  if (i3) goto l32;
  i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 23894)))), &_td_Object__String16Desc);
  if (i3) goto l5;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 23891)))), 23891);
  goto l58;
l5:
  i3 = *(OOC_INT32*)(_check_pointer(i2, 23919));
  i3 = i3<i1;
  if (!i3) goto l9;
  i1 = *(OOC_INT32*)(_check_pointer(i2, 23947));
  min = i1;
  
l9:
  i = 0;
  i3 = 0!=i1;
  if (i3) goto l12;
  i3=0u;
  goto l14;
l12:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24001))+4);
  i3 = _check_pointer(i3, 24006);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 24013))+4);
  i5 = _check_pointer(i5, 24018);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i3 = *(OOC_UINT8*)(i3+(_check_index(0, i4, OOC_UINT32, 24006)));
  i4 = *(OOC_UINT16*)(i5+(_check_index(0, i6, OOC_UINT32, 24018))*2);
  i3 = i3==i4;
  
l14:
  if (i3) goto l16;
  i3=0;
  goto l26;
l16:
  i3=0;
l17_loop:
  i3 = i3+1;
  i = i3;
  i4 = i3!=i1;
  if (i4) goto l20;
  i4=0u;
  goto l22;
l20:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24001))+4);
  i4 = _check_pointer(i4, 24006);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 24013))+4);
  i6 = _check_pointer(i6, 24018);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i4 = *(OOC_UINT8*)(i4+(_check_index(i3, i5, OOC_UINT32, 24006)));
  i5 = *(OOC_UINT16*)(i6+(_check_index(i3, i7, OOC_UINT32, 24018))*2);
  i4 = i4==i5;
  
l22:
  if (i4) goto l17_loop;
l26:
  i1 = i3==i1;
  if (i1) goto l29;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24147))+4);
  i0 = _check_pointer(i0, 24152);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 24164))+4);
  i2 = _check_pointer(i2, 24169);
  i4 = OOC_ARRAY_LENGTH(i2, 0);
  i0 = *(OOC_UINT8*)(i0+(_check_index(i3, i1, OOC_UINT32, 24152)));
  i1 = *(OOC_UINT16*)(i2+(_check_index(i3, i4, OOC_UINT32, 24169))*2);
  return (i0-i1);
  goto l58;
l29:
  i1 = *(OOC_INT32*)(_check_pointer(i2, 24105));
  i0 = *(OOC_INT32*)(_check_pointer(i0, 24094));
  return (i0-i1);
  goto l58;
l32:
  i3 = *(OOC_INT32*)(_check_pointer(i2, 23619));
  i3 = i3<i1;
  if (!i3) goto l36;
  i1 = *(OOC_INT32*)(_check_pointer(i2, 23647));
  min = i1;
  
l36:
  i = 0;
  i3 = 0!=i1;
  if (i3) goto l39;
  i3=0u;
  goto l41;
l39:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23701))+4);
  i3 = _check_pointer(i3, 23706);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 23713))+4);
  i5 = _check_pointer(i5, 23718);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i3 = *(OOC_UINT8*)(i3+(_check_index(0, i4, OOC_UINT32, 23706)));
  i4 = *(OOC_UINT8*)(i5+(_check_index(0, i6, OOC_UINT32, 23718)));
  i3 = i3==i4;
  
l41:
  if (i3) goto l43;
  i3=0;
  goto l53;
l43:
  i3=0;
l44_loop:
  i3 = i3+1;
  i = i3;
  i4 = i3!=i1;
  if (i4) goto l47;
  i4=0u;
  goto l49;
l47:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23701))+4);
  i4 = _check_pointer(i4, 23706);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 23713))+4);
  i6 = _check_pointer(i6, 23718);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i4 = *(OOC_UINT8*)(i4+(_check_index(i3, i5, OOC_UINT32, 23706)));
  i5 = *(OOC_UINT8*)(i6+(_check_index(i3, i7, OOC_UINT32, 23718)));
  i4 = i4==i5;
  
l49:
  if (i4) goto l44_loop;
l53:
  i1 = i3==i1;
  if (i1) goto l56;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23847))+4);
  i0 = _check_pointer(i0, 23852);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 23864))+4);
  i2 = _check_pointer(i2, 23869);
  i4 = OOC_ARRAY_LENGTH(i2, 0);
  i0 = *(OOC_UINT8*)(i0+(_check_index(i3, i1, OOC_UINT32, 23852)));
  i1 = *(OOC_UINT8*)(i2+(_check_index(i3, i4, OOC_UINT32, 23869)));
  return (i0-i1);
  goto l58;
l56:
  i1 = *(OOC_INT32*)(_check_pointer(i2, 23805));
  i0 = *(OOC_INT32*)(_check_pointer(i0, 23794));
  return (i0-i1);
l58:
  _failed_function(23499); return 0;
  ;
}

OOC_INT32 Object__String16Desc_Compare(Object__String16 s, Object__Object y) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  OOC_INT32 min;
  OOC_INT32 i;

  i0 = (OOC_INT32)s;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 24313));
  min = i1;
  i2 = (OOC_INT32)y;
  i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 24332)))), &_td_Object__String8Desc);
  if (i3) goto l32;
  i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 24631)))), &_td_Object__String16Desc);
  if (i3) goto l5;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 24628)))), 24628);
  goto l58;
l5:
  i3 = *(OOC_INT32*)(_check_pointer(i2, 24656));
  i3 = i3<i1;
  if (!i3) goto l9;
  i1 = *(OOC_INT32*)(_check_pointer(i2, 24684));
  min = i1;
  
l9:
  i = 0;
  i3 = 0!=i1;
  if (i3) goto l12;
  i3=0u;
  goto l14;
l12:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24738))+4);
  i3 = _check_pointer(i3, 24743);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 24750))+4);
  i5 = _check_pointer(i5, 24755);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i3 = *(OOC_UINT16*)(i3+(_check_index(0, i4, OOC_UINT32, 24743))*2);
  i4 = *(OOC_UINT16*)(i5+(_check_index(0, i6, OOC_UINT32, 24755))*2);
  i3 = i3==i4;
  
l14:
  if (i3) goto l16;
  i3=0;
  goto l26;
l16:
  i3=0;
l17_loop:
  i3 = i3+1;
  i = i3;
  i4 = i3!=i1;
  if (i4) goto l20;
  i4=0u;
  goto l22;
l20:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24738))+4);
  i4 = _check_pointer(i4, 24743);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 24750))+4);
  i6 = _check_pointer(i6, 24755);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i4 = *(OOC_UINT16*)(i4+(_check_index(i3, i5, OOC_UINT32, 24743))*2);
  i5 = *(OOC_UINT16*)(i6+(_check_index(i3, i7, OOC_UINT32, 24755))*2);
  i4 = i4==i5;
  
l22:
  if (i4) goto l17_loop;
l26:
  i1 = i3==i1;
  if (i1) goto l29;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24884))+4);
  i0 = _check_pointer(i0, 24889);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 24901))+4);
  i2 = _check_pointer(i2, 24906);
  i4 = OOC_ARRAY_LENGTH(i2, 0);
  i0 = *(OOC_UINT16*)(i0+(_check_index(i3, i1, OOC_UINT32, 24889))*2);
  i1 = *(OOC_UINT16*)(i2+(_check_index(i3, i4, OOC_UINT32, 24906))*2);
  return (i0-i1);
  goto l58;
l29:
  i1 = *(OOC_INT32*)(_check_pointer(i2, 24842));
  i0 = *(OOC_INT32*)(_check_pointer(i0, 24831));
  return (i0-i1);
  goto l58;
l32:
  i3 = *(OOC_INT32*)(_check_pointer(i2, 24356));
  i3 = i3<i1;
  if (!i3) goto l36;
  i1 = *(OOC_INT32*)(_check_pointer(i2, 24384));
  min = i1;
  
l36:
  i = 0;
  i3 = 0!=i1;
  if (i3) goto l39;
  i3=0u;
  goto l41;
l39:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24438))+4);
  i3 = _check_pointer(i3, 24443);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 24450))+4);
  i5 = _check_pointer(i5, 24455);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i3 = *(OOC_UINT16*)(i3+(_check_index(0, i4, OOC_UINT32, 24443))*2);
  i4 = *(OOC_UINT8*)(i5+(_check_index(0, i6, OOC_UINT32, 24455)));
  i3 = i3==i4;
  
l41:
  if (i3) goto l43;
  i3=0;
  goto l53;
l43:
  i3=0;
l44_loop:
  i3 = i3+1;
  i = i3;
  i4 = i3!=i1;
  if (i4) goto l47;
  i4=0u;
  goto l49;
l47:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24438))+4);
  i4 = _check_pointer(i4, 24443);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 24450))+4);
  i6 = _check_pointer(i6, 24455);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i4 = *(OOC_UINT16*)(i4+(_check_index(i3, i5, OOC_UINT32, 24443))*2);
  i5 = *(OOC_UINT8*)(i6+(_check_index(i3, i7, OOC_UINT32, 24455)));
  i4 = i4==i5;
  
l49:
  if (i4) goto l44_loop;
l53:
  i1 = i3==i1;
  if (i1) goto l56;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24584))+4);
  i0 = _check_pointer(i0, 24589);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 24601))+4);
  i2 = _check_pointer(i2, 24606);
  i4 = OOC_ARRAY_LENGTH(i2, 0);
  i0 = *(OOC_UINT16*)(i0+(_check_index(i3, i1, OOC_UINT32, 24589))*2);
  i1 = *(OOC_UINT8*)(i2+(_check_index(i3, i4, OOC_UINT32, 24606)));
  return (i0-i1);
  goto l58;
l56:
  i1 = *(OOC_INT32*)(_check_pointer(i2, 24542));
  i0 = *(OOC_INT32*)(_check_pointer(i0, 24531));
  return (i0-i1);
l58:
  _failed_function(24236); return 0;
  ;
}

OOC_INT32 Object__StringDesc_HashCode(Object__String s) {

  _failed_function(24982); return 0;
  ;
}

OOC_INT32 Object__String8Desc_HashCode(Object__String8 s) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)s;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25100))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25100))+4);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 25105)), 0);
  i0 = *(OOC_INT32*)(_check_pointer(i0, 25112));
  i0 = HashCode__CharRegion((void*)(_check_pointer(i1, 25105)), i2, 0, i0);
  return i0;
  ;
}

OOC_INT32 Object__String16Desc_HashCode(Object__String16 s) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)s;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25226))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25226))+4);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 25231)), 0);
  i0 = *(OOC_INT32*)(_check_pointer(i0, 25238));
  i0 = HashCode__LongCharRegion((void*)(_check_pointer(i1, 25231)), i2, 0, i0);
  return i0;
  ;
}

OOC_CHAR32 Object__StringDesc_CharAt(Object__String s, OOC_INT32 index) {

  _failed_function(25298); return 0;
  ;
}

OOC_CHAR32 Object__String8Desc_CharAt(Object__String8 s, OOC_INT32 index) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)s;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25560))+4);
  i0 = _check_pointer(i0, 25565);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i2 = index;
  i0 = *(OOC_UINT8*)(i0+(_check_index(i2, i1, OOC_UINT32, 25565)));
  return i0;
  ;
}

OOC_CHAR32 Object__String16Desc_CharAt(Object__String16 s, OOC_INT32 index) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_CHAR16 _w1;

  i0 = (OOC_INT32)s;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25695))+4);
  i1 = _check_pointer(i1, 25700);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i3 = index;
  i1 = *(OOC_UINT16*)(i1+(_check_index(i3, i2, OOC_UINT32, 25700))*2);
  _w1 = i1;
  i2 = (OOC_UINT16)i1<(OOC_UINT16)55296u;
  if (i2) goto l3;
  i2 = (OOC_UINT16)i1>=(OOC_UINT16)57344u;
  
  goto l5;
l3:
  i2=1u;
l5:
  if (i2) goto l19;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25973))+4);
  i0 = _check_pointer(i0, 25978);
  i2 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = *(OOC_UINT16*)(i0+(_check_index((i3+1), i2, OOC_UINT32, 25978))*2);
  i2 = (OOC_UINT16)i1<(OOC_UINT16)56320u;
  if (i2) goto l9;
  i2=0u;
  goto l11;
l9:
  i2 = (OOC_UINT16)56320u<=(OOC_UINT16)i0;
  
l11:
  if (i2) goto l13;
  i2=0u;
  goto l15;
l13:
  i2 = (OOC_UINT16)i0<(OOC_UINT16)57344u;
  
l15:
  if (i2) goto l17;
  return i1;
  goto l20;
l17:
  return ((((_mod(i1,1024))*1024)+(_mod(i0,1024)))+65536);
  goto l20;
l19:
  return i1;
l20:
  _failed_function(25613); return 0;
  ;
}

OOC_CHAR32 Object__StringDesc_NextChar(Object__String s, OOC_INT32 *index) {

  _failed_function(26345); return 0;
  ;
}

OOC_CHAR32 Object__String8Desc_NextChar(Object__String8 s, OOC_INT32 *index) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)s;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26797))+4);
  i0 = _check_pointer(i0, 26802);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i2 = *index;
  *index = (i2+1);
  i0 = *(OOC_UINT8*)(i0+(_check_index(i2, i1, OOC_UINT32, 26802)));
  return i0;
  ;
}

OOC_CHAR32 Object__String16Desc_NextChar(Object__String16 s, OOC_INT32 *index) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_CHAR16 _w1;

  i0 = (OOC_INT32)s;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26970))+4);
  i1 = _check_pointer(i1, 26975);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i3 = *index;
  i1 = *(OOC_UINT16*)(i1+(_check_index(i3, i2, OOC_UINT32, 26975))*2);
  _w1 = i1;
  i2 = i3+1;
  *index = i2;
  i3 = (OOC_UINT16)i1<(OOC_UINT16)55296u;
  if (i3) goto l3;
  i3 = (OOC_UINT16)i1>=(OOC_UINT16)57344u;
  
  goto l5;
l3:
  i3=1u;
l5:
  if (i3) goto l19;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27263))+4);
  i0 = _check_pointer(i0, 27268);
  i3 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = *(OOC_UINT16*)(i0+(_check_index(i2, i3, OOC_UINT32, 27268))*2);
  i3 = (OOC_UINT16)i1<(OOC_UINT16)56320u;
  if (i3) goto l9;
  i3=0u;
  goto l11;
l9:
  i3 = (OOC_UINT16)56320u<=(OOC_UINT16)i0;
  
l11:
  if (i3) goto l13;
  i3=0u;
  goto l15;
l13:
  i3 = (OOC_UINT16)i0<(OOC_UINT16)57344u;
  
l15:
  if (i3) goto l17;
  return i1;
  goto l20;
l17:
  *index = (i2+1);
  return ((((_mod(i1,1024))*1024)+(_mod(i0,1024)))+65536);
  goto l20;
l19:
  return i1;
l20:
  _failed_function(26882); return 0;
  ;
}

Object__String Object__StringDesc_Substring(Object__String s, OOC_INT32 start, OOC_INT32 end) {

  _failed_function(27654); return 0;
  ;
}

Object__String8 Object__String8Desc_Substring(Object__String8 s, OOC_INT32 start, OOC_INT32 end) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)s;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28086))+4);
  i1 = start;
  i2 = end;
  i0 = (OOC_INT32)Object__NewString8(((_check_pointer(i0, 28091))+i1), (i2-i1));
  return (Object__String8)i0;
  ;
}

Object__String16 Object__String16Desc_Substring(Object__String16 s, OOC_INT32 start, OOC_INT32 end) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)s;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28237))+4);
  i1 = start;
  i2 = end;
  i0 = (OOC_INT32)Object__NewString16(((_check_pointer(i0, 28242))+i1*2), (i2-i1));
  return (Object__String16)i0;
  ;
}

Object__String Object__StringDesc_Trim(Object__String s) {

  _failed_function(28331); return 0;
  ;
}

Object__String8 Object__String8Desc_Trim(Object__String8 s) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT32 a;
  OOC_INT32 b;

  a = 0;
  i0 = (OOC_INT32)s;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 28720));
  i1 = 0!=i1;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28733))+4);
  i1 = _check_pointer(i1, 28738);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_UINT8*)(i1+(_check_index(0, i2, OOC_UINT32, 28738)));
  i1 = (OOC_UINT8)i1<=(OOC_UINT8)32u;
  
l5:
  if (i1) goto l7;
  i1=0;
  goto l17;
l7:
  i1=0;
l8_loop:
  i1 = i1+1;
  a = i1;
  i2 = *(OOC_INT32*)(_check_pointer(i0, 28720));
  i2 = i1!=i2;
  if (i2) goto l11;
  i2=0u;
  goto l13;
l11:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28733))+4);
  i2 = _check_pointer(i2, 28738);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = *(OOC_UINT8*)(i2+(_check_index(i1, i3, OOC_UINT32, 28738)));
  i2 = (OOC_UINT8)i2<=(OOC_UINT8)32u;
  
l13:
  if (i2) goto l8_loop;
l17:
  i2 = *(OOC_INT32*)(_check_pointer(i0, 28786));
  b = i2;
  i3 = i2!=i1;
  if (i3) goto l20;
  i3=0u;
  goto l22;
l20:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28817))+4);
  i3 = _check_pointer(i3, 28822);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = *(OOC_UINT8*)(i3+(_check_index((i2-1), i4, OOC_UINT32, 28822)));
  i3 = (OOC_UINT8)i3<=(OOC_UINT8)32u;
  
l22:
  if (!i3) goto l34;
l25_loop:
  i2 = i2-1;
  b = i2;
  i3 = i2!=i1;
  if (i3) goto l28;
  i3=0u;
  goto l30;
l28:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28817))+4);
  i3 = _check_pointer(i3, 28822);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = *(OOC_UINT8*)(i3+(_check_index((i2-1), i4, OOC_UINT32, 28822)));
  i3 = (OOC_UINT8)i3<=(OOC_UINT8)32u;
  
l30:
  if (i3) goto l25_loop;
l34:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28891))+4);
  i0 = (OOC_INT32)Object__NewString8(((_check_pointer(i0, 28896))+i1), (i2-i1));
  return (Object__String8)i0;
  ;
}

Object__String16 Object__String16Desc_Trim(Object__String16 s) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT32 a;
  OOC_INT32 b;

  a = 0;
  i0 = (OOC_INT32)s;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 29025));
  i1 = 0!=i1;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29038))+4);
  i1 = _check_pointer(i1, 29043);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_UINT16*)(i1+(_check_index(0, i2, OOC_UINT32, 29043))*2);
  i1 = (OOC_UINT16)i1<=(OOC_UINT16)32u;
  
l5:
  if (i1) goto l7;
  i1=0;
  goto l17;
l7:
  i1=0;
l8_loop:
  i1 = i1+1;
  a = i1;
  i2 = *(OOC_INT32*)(_check_pointer(i0, 29025));
  i2 = i1!=i2;
  if (i2) goto l11;
  i2=0u;
  goto l13;
l11:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29038))+4);
  i2 = _check_pointer(i2, 29043);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = *(OOC_UINT16*)(i2+(_check_index(i1, i3, OOC_UINT32, 29043))*2);
  i2 = (OOC_UINT16)i2<=(OOC_UINT16)32u;
  
l13:
  if (i2) goto l8_loop;
l17:
  i2 = *(OOC_INT32*)(_check_pointer(i0, 29091));
  b = i2;
  i3 = i2!=i1;
  if (i3) goto l20;
  i3=0u;
  goto l22;
l20:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29122))+4);
  i3 = _check_pointer(i3, 29127);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = *(OOC_UINT16*)(i3+(_check_index((i2-1), i4, OOC_UINT32, 29127))*2);
  i3 = (OOC_UINT16)i3<=(OOC_UINT16)32u;
  
l22:
  if (!i3) goto l34;
l25_loop:
  i2 = i2-1;
  b = i2;
  i3 = i2!=i1;
  if (i3) goto l28;
  i3=0u;
  goto l30;
l28:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29122))+4);
  i3 = _check_pointer(i3, 29127);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = *(OOC_UINT16*)(i3+(_check_index((i2-1), i4, OOC_UINT32, 29127))*2);
  i3 = (OOC_UINT16)i3<=(OOC_UINT16)32u;
  
l30:
  if (i3) goto l25_loop;
l34:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29197))+4);
  i0 = (OOC_INT32)Object__NewString16(((_check_pointer(i0, 29202))+i1*2), (i2-i1));
  return (Object__String16)i0;
  ;
}

OOC_INT32 Object__StringDesc_IndexOf(Object__String s, OOC_CHAR32 _char, OOC_INT32 pos) {

  _failed_function(29276); return 0;
  ;
}

OOC_INT32 Object__String8Desc_IndexOf(Object__String8 s, OOC_CHAR32 _char, OOC_INT32 pos) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 endpos;

  i0 = (OOC_INT32)s;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 29759));
  endpos = i1;
  i2 = pos;
  i3 = i2!=i1;
  if (!i3) goto l11;
  i3 = _char;
  
l3_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29807))+4);
  i4 = _check_pointer(i4, 29812);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = *(OOC_UINT8*)(i4+(_check_index(i2, i5, OOC_UINT32, 29812)));
  i4 = i4==i3;
  if (!i4) goto l6;
  return i2;
l6:
  i2 = i2+1;
  pos = i2;
  i4 = i2!=i1;
  if (i4) goto l3_loop;
l11:
  return (-1);
  ;
}

OOC_INT32 Object__String16Desc_IndexOf(Object__String16 s, OOC_CHAR32 _char, OOC_INT32 pos) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  OOC_INT32 endpos;
  OOC_INT32 v;
  OOC_CHAR16 _w1;
  OOC_CHAR16 _w2;

  i0 = _char;
  i1 = (OOC_UINT32)i0<(OOC_UINT32)65536u;
  if (i1) goto l18;
  i0 = i0-65536;
  v = i0;
  i1 = 55296+(i0>>10);
  _w1 = i1;
  i0 = 56320+(_mod(i0,1024));
  _w2 = i0;
  i2 = (OOC_INT32)s;
  i3 = *(OOC_INT32*)(_check_pointer(i2, 30443));
  endpos = i3;
  i4 = pos;
  i5 = i4!=i3;
  if (!i5) goto l17;
l5_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 30495))+4);
  i5 = _check_pointer(i5, 30500);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = *(OOC_UINT16*)(i5+(_check_index(i4, i6, OOC_UINT32, 30500))*2);
  i6 = i4+1;
  i5 = i5==i1;
  if (i5) goto l8;
  i5=0u;
  goto l10;
l8:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 30516))+4);
  i5 = _check_pointer(i5, 30521);
  i7 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = *(OOC_UINT16*)(i5+(_check_index(i6, i7, OOC_UINT32, 30521))*2);
  i5 = i5==i0;
  
l10:
  if (!i5) goto l12;
  return i4;
l12:
  pos = i6;
  i4 = i6!=i3;
  if (!i4) goto l17;
  i4=i6;
  goto l5_loop;
l17:
  return (-1);
  goto l30;
l18:
  i1 = (OOC_INT32)s;
  i2 = *(OOC_INT32*)(_check_pointer(i1, 30104));
  endpos = i2;
  i3 = pos;
  i4 = i3!=i2;
  if (!i4) goto l29;
l21_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 30156))+4);
  i4 = _check_pointer(i4, 30161);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = *(OOC_UINT16*)(i4+(_check_index(i3, i5, OOC_UINT32, 30161))*2);
  i4 = i4==i0;
  if (!i4) goto l24;
  return i3;
l24:
  i3 = i3+1;
  pos = i3;
  i4 = i3!=i2;
  if (i4) goto l21_loop;
l29:
  return (-1);
l30:
  _failed_function(29942); return 0;
  ;
}

OOC_INT32 Object__StringDesc_LastIndexOf(Object__String s, OOC_CHAR32 _char, OOC_INT32 pos) {

  _failed_function(30801); return 0;
  ;
}

OOC_INT32 Object__String8Desc_LastIndexOf(Object__String8 s, OOC_CHAR32 _char, OOC_INT32 pos) {
  register OOC_INT32 i0,i1,i2,i3,i4;

  i0 = pos;
  i1 = i0>0;
  if (!i1) goto l11;
  i1 = (OOC_INT32)s;
  i2 = _char;
  
l3_loop:
  i0 = i0-1;
  pos = i0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 31334))+4);
  i3 = _check_pointer(i3, 31339);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = *(OOC_UINT8*)(i3+(_check_index(i0, i4, OOC_UINT32, 31339)));
  i3 = i3==i2;
  if (!i3) goto l6;
  return i0;
l6:
  i3 = i0>0;
  if (i3) goto l3_loop;
l11:
  return (-1);
  ;
}

OOC_INT32 Object__String16Desc_LastIndexOf(Object__String16 s, OOC_CHAR32 _char, OOC_INT32 pos) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 v;
  OOC_CHAR16 _w1;
  OOC_CHAR16 _w2;

  i0 = _char;
  i1 = (OOC_UINT32)i0<(OOC_UINT32)65536u;
  if (i1) goto l18;
  i0 = i0-65536;
  v = i0;
  i1 = 55296+(i0>>10);
  _w1 = i1;
  i0 = 56320+(_mod(i0,1024));
  _w2 = i0;
  i2 = pos;
  i3 = i2>0;
  if (!i3) goto l17;
  i3 = (OOC_INT32)s;
  
l5_loop:
  i2 = i2-1;
  pos = i2;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 31962))+4);
  i4 = _check_pointer(i4, 31967);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = *(OOC_UINT16*)(i4+(_check_index(i2, i5, OOC_UINT32, 31967))*2);
  i4 = i4==i1;
  if (i4) goto l8;
  i4=0u;
  goto l10;
l8:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 31983))+4);
  i4 = _check_pointer(i4, 31988);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = *(OOC_UINT16*)(i4+(_check_index((i2+1), i5, OOC_UINT32, 31988))*2);
  i4 = i4==i0;
  
l10:
  if (!i4) goto l12;
  return i2;
l12:
  i4 = i2>0;
  if (i4) goto l5_loop;
l17:
  return (-1);
  goto l30;
l18:
  i1 = pos;
  i2 = i1>0;
  if (!i2) goto l29;
  i2 = (OOC_INT32)s;
  
l21_loop:
  i1 = i1-1;
  pos = i1;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 31654))+4);
  i3 = _check_pointer(i3, 31659);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = *(OOC_UINT16*)(i3+(_check_index(i1, i4, OOC_UINT32, 31659))*2);
  i3 = i3==i0;
  if (!i3) goto l24;
  return i1;
l24:
  i3 = i1>0;
  if (i3) goto l21_loop;
l29:
  return (-1);
l30:
  _failed_function(31457); return 0;
  ;
}

OOC_CHAR8 Object__StringDesc_EndsWith(Object__String s, Object__String suffix) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  Object__String e;

  i0 = (OOC_INT32)s;
  i1 = (OOC_INT32)suffix;
  i2 = *(OOC_INT32*)(_check_pointer(i0, 32581));
  i3 = *(OOC_INT32*)(_check_pointer(i1, 32598));
  i2 = i2>=i3;
  if (i2) goto l3;
  return 0u;
  goto l4;
l3:
  i2 = *(OOC_INT32*)(_check_pointer(i1, 32650));
  i3 = *(OOC_INT32*)(_check_pointer(i0, 32636));
  i4 = *(OOC_INT32*)(_check_pointer(i0, 32660));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32624)))), Object__StringDesc_Substring)),Object__StringDesc_Substring)((Object__String)i0, (i3-i2), i4);
  e = (Object__String)i0;
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32684)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i0, (Object__Object)i1);
  return i0;
l4:
  _failed_function(32269); return 0;
  ;
}

OOC_CHAR8 Object__StringDesc_StartsWith(Object__String s, Object__String prefix) {
  register OOC_INT32 i0,i1,i2,i3;
  Object__String e;

  i0 = (OOC_INT32)s;
  i1 = (OOC_INT32)prefix;
  i2 = *(OOC_INT32*)(_check_pointer(i0, 33093));
  i3 = *(OOC_INT32*)(_check_pointer(i1, 33110));
  i2 = i2>=i3;
  if (i2) goto l3;
  return 0u;
  goto l4;
l3:
  i2 = *(OOC_INT32*)(_check_pointer(i1, 33156));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33136)))), Object__StringDesc_Substring)),Object__StringDesc_Substring)((Object__String)i0, 0, i2);
  e = (Object__String)i0;
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33180)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i0, (Object__Object)i1);
  return i0;
l4:
  _failed_function(32778); return 0;
  ;
}

void OOC_Object_init(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)Object__NewLatin1("", 1);
  Object__emptyString = (Object__String)i0;
  return;
  ;
}

/* --- */
