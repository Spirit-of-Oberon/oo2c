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
      i0 = *(OOC_UINT8*)(_check_pointer(i0, 6444));
      i0 = i0!=0u;
      if (!i0) goto l12;
      i0 = (OOC_INT32)name;
      i1=0;
l3_loop:
      i2 = i;
      i3 = *(OOC_UINT8*)((_check_pointer(i0, 6479))+i1);
      *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i2, 280, OOC_UINT32, 6468))) = i3;
      i = (i2+1);
      i1 = i1+1;
      j = i1;
      i2 = i1!=128;
      if (i2) goto l6;
      i2=0u;
      goto l8;
l6:
      i2 = *(OOC_UINT8*)((_check_pointer(i0, 6444))+i1);
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
      *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i2, 280, OOC_UINT32, 6767))) = i4;
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
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6936))+12);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6943));
  Object__ObjectDesc_ToString_Append((RT0__Name)i0);
  i0 = i;
  *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, 280, OOC_UINT32, 6958))) = 46u;
  i = (i0+1);
  i0 = (OOC_INT32)_struct;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6996))+16);
  Object__ObjectDesc_ToString_Append((RT0__Name)i0);
  i0 = i;
  *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, 280, OOC_UINT32, 7011))) = 32u;
  i0 = i0+1;
  *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, 280, OOC_UINT32, 7038))) = 97u;
  i0 = i0+1;
  *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, 280, OOC_UINT32, 7065))) = 116u;
  i0 = i0+1;
  *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, 280, OOC_UINT32, 7092))) = 32u;
  i1 = (OOC_INT32)x;
  i = (i0+1);
  Object__ObjectDesc_ToString_AppendHex((_type_cast_fast(OOC_INT32, OOC_INT32, i1)));
  i0 = i;
  *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, 280, OOC_UINT32, 7331))) = 62u;
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
  *(OOC_INT32*)(_check_pointer(i0, 10749)) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 10774))+4) = i2;
  i0 = source;
  _move_block(i0,(_check_pointer(i2, 10813)),i1);
  i0 = (OOC_INT32)d;
  i0 = _check_pointer(i0, 10842);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i2 = length;
  *(OOC_UINT8*)(i0+(_check_index(i2, i1, OOC_UINT32, 10842))) = 0u;
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
  *(OOC_INT32*)(_check_pointer(i0, 11049)) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 11074))+4) = i2;
  i0 = source;
  _move_block(i0,(_check_pointer(i2, 11113)),(i1*2));
  i0 = (OOC_INT32)d;
  i0 = _check_pointer(i0, 11146);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i2 = length;
  *(OOC_UINT16*)(i0+(_check_index(i2, i1, OOC_UINT32, 11146))*2) = 0u;
  i0 = (OOC_INT32)s;
  return (Object__String16)i0;
  ;
}

Object__String8 Object__NewLatin1(const OOC_CHAR8 str[], OOC_LEN str_0d) {
  register OOC_INT32 i0,i1;

  i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT32, 11472)));
  i0 = i0!=0u;
  if (i0) goto l3;
  i0=0;
  goto l9;
l3:
  i0=0;
l4_loop:
  i0 = i0+1;
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 11472)));
  i1 = i1!=0u;
  if (i1) goto l4_loop;
l9:
  i0 = (OOC_INT32)Object__NewString8((OOC_INT32)str, i0);
  return (Object__String8)i0;
  ;
}

Object__String8 Object__NewLatin1Region(const OOC_CHAR8 str[], OOC_LEN str_0d, OOC_INT32 start, OOC_INT32 end) {
  register OOC_INT32 i0,i1;

  i0 = end;
  i1 = start;
  i0 = (OOC_INT32)Object__NewString8(((OOC_INT32)str+i1), (i0-i1));
  return (Object__String8)i0;
  ;
}

Object__String8 Object__NewLatin1Char(OOC_CHAR8 ch) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)Object__NewString8((OOC_INT32)&ch, 1);
  return (Object__String8)i0;
  ;
}

Object__String16 Object__NewUTF16(const OOC_CHAR16 str[], OOC_LEN str_0d) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_INT32 i;
  Object__String16 s;
  Object__CharsUTF16 d;
  OOC_INT32 j;

  i = 0;
  i0 = *(OOC_UINT16*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT32, 12590))*2);
  i0 = i0!=0u;
  if (i0) goto l3;
  i0=0;
  goto l9;
l3:
  i0=0;
l4_loop:
  i0 = i0+1;
  i = i0;
  i1 = *(OOC_UINT16*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 12590))*2);
  i1 = i1!=0u;
  if (i1) goto l4_loop;
l9:
  i1 = (OOC_INT32)RT0__NewObject(_td_Object__String16.baseTypes[0]);
  s = (Object__String16)i1;
  i2 = (OOC_INT32)RT0__NewObject(_td_Object__CharsUTF16.baseTypes[0], (i0+1));
  d = (Object__CharsUTF16)i2;
  *(OOC_INT32*)(_check_pointer(i1, 12665)) = i0;
  *(OOC_INT32*)((_check_pointer(i1, 12685))+4) = i2;
  j = 0;
  i3 = 0<=i0;
  if (!i3) goto l17;
  i3=0;
l12_loop:
  i4 = _check_pointer(i2, 12728);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = *(OOC_UINT16*)((OOC_INT32)str+(_check_index(i3, str_0d, OOC_UINT32, 12738))*2);
  *(OOC_UINT16*)(i4+(_check_index(i3, i5, OOC_UINT32, 12728))*2) = i6;
  i3 = i3+1;
  j = i3;
  i4 = i3<=i0;
  if (i4) goto l12_loop;
l17:
  return (Object__String16)i1;
  ;
}

Object__String16 Object__NewUTF16Region(const OOC_CHAR16 str[], OOC_LEN str_0d, OOC_INT32 start, OOC_INT32 end) {
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
  *(OOC_INT32*)(_check_pointer(i3, 13275)) = i2;
  *(OOC_INT32*)((_check_pointer(i3, 13295))+4) = i4;
  j = i1;
  i5 = i1<i0;
  if (!i5) goto l8;
  i5 = (i1*(-1))+i1;
  
l3_loop:
  i6 = _check_pointer(i4, 13346);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i8 = *(OOC_UINT16*)((OOC_INT32)str+(_check_index(i1, str_0d, OOC_UINT32, 13362))*2);
  *(OOC_UINT16*)(i6+(_check_index(i5, i7, OOC_UINT32, 13346))*2) = i8;
  i1 = i1+1;
  j = i1;
  i5 = i5+1;
  i6 = i1<i0;
  if (i6) goto l3_loop;
l8:
  i0 = _check_pointer(i4, 13381);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  *(OOC_UINT16*)(i0+(_check_index(i2, i1, OOC_UINT32, 13381))*2) = 0u;
  return (Object__String16)i3;
  ;
}

Object__String16 Object__NewUTF16Char(OOC_CHAR16 ch) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  Object__String16 s;
  Object__CharsUTF16 d;

  i0 = (OOC_INT32)RT0__NewObject(_td_Object__String16.baseTypes[0]);
  s = (Object__String16)i0;
  i1 = (OOC_INT32)RT0__NewObject(_td_Object__CharsUTF16.baseTypes[0], 2);
  d = (Object__CharsUTF16)i1;
  *(OOC_INT32*)(_check_pointer(i0, 13745)) = 1;
  *(OOC_INT32*)((_check_pointer(i0, 13765))+4) = i1;
  i2 = _check_pointer(i1, 13783);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = ch;
  *(OOC_UINT16*)(i2+(_check_index(0, i3, OOC_UINT8, 13783))*2) = i4;
  i1 = _check_pointer(i1, 13799);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  *(OOC_UINT16*)(i1+(_check_index(1, i2, OOC_UINT8, 13799))*2) = 0u;
  return (Object__String16)i0;
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
  *(OOC_INT32*)(_check_pointer(i1, 14302)) = 2;
  *(OOC_INT32*)((_check_pointer(i1, 14324))+4) = i2;
  i0 = i0-65536;
  v = i0;
  i3 = _check_pointer(i2, 14385);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_UINT16*)(i3+(_check_index(0, i4, OOC_UINT8, 14385))*2) = (55296+(i0>>10));
  i3 = _check_pointer(i2, 14440);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_UINT16*)(i3+(_check_index(1, i4, OOC_UINT8, 14440))*2) = (56320+(_mod(i0,1024)));
  i0 = _check_pointer(i2, 14496);
  i2 = OOC_ARRAY_LENGTH(i0, 0);
  *(OOC_UINT16*)(i0+(_check_index(2, i2, OOC_UINT8, 14496))*2) = 0u;
  return (Object__String)i1;
  goto l4;
l3:
  i0 = (OOC_INT32)Object__NewUTF16Char(i0);
  return (Object__String)i0;
l4:
  _failed_function(13855); return 0;
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
  i5 = *(OOC_UINT32*)((OOC_INT32)str+(_check_index(i3, str_0d, OOC_UINT32, 15055))*4);
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
  i5 = *(OOC_UINT32*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 15233))*4);
  i5 = (OOC_UINT32)i5>=(OOC_UINT32)65536u;
  if (i5) goto l19;
  i5 = _check_pointer(i4, 15471);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i7 = *(OOC_UINT32*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 15487))*4);
  *(OOC_UINT16*)(i5+(_check_index(i2, i6, OOC_UINT32, 15471))*2) = i7;
  i2 = i2+1;
  i = i2;
  
  goto l20;
l19:
  i5 = *(OOC_UINT32*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 15285))*4);
  i5 = i5-65536;
  v = i5;
  i6 = _check_pointer(i4, 15324);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  *(OOC_UINT16*)(i6+(_check_index(i2, i7, OOC_UINT32, 15324))*2) = (55296+(i5>>10));
  i6 = _check_pointer(i4, 15381);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  *(OOC_UINT16*)(i6+(_check_index((i2+1), i7, OOC_UINT32, 15381))*2) = (56320+(_mod(i5,1024)));
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
  *(OOC_INT32*)(_check_pointer(i0, 15569)) = i3;
  *(OOC_INT32*)((_check_pointer(i0, 15588))+4) = i4;
  return (Object__String)i0;
  ;
}

Object__String Object__NewUCS4(const OOC_CHAR32 str[], OOC_LEN str_0d) {
  register OOC_INT32 i0,i1;

  i0 = *(OOC_UINT32*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT32, 15947))*4);
  i0 = i0!=0u;
  if (i0) goto l3;
  i0=0;
  goto l9;
l3:
  i0=0;
l4_loop:
  i0 = i0+1;
  i1 = *(OOC_UINT32*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 15947))*4);
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
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16273)))), &_td_Object__String8Desc);
  if (i1) goto l23;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17187)))), &_td_Object__String16Desc);
  if (i1) goto l5;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17183)))), 17183);
  goto l40;
l5:
  i1 = (OOC_INT32)s2;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17214)))), &_td_Object__String8Desc);
  if (i2) goto l12;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17585)))), &_td_Object__String16Desc);
  if (i2) goto l10;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17581)))), 17581);
  goto l40;
l10:
  i2 = (OOC_INT32)RT0__NewObject(_td_Object__String16.baseTypes[0]);
  c32 = (Object__String16)i2;
  i3 = *(OOC_INT32*)(_check_pointer(i1, 17692));
  i4 = *(OOC_INT32*)(_check_pointer(i0, 17682));
  *(OOC_INT32*)(_check_pointer(i2, 17669)) = (i4+i3);
  i1 = *(OOC_INT32*)(_check_pointer(i1, 17735));
  i3 = *(OOC_INT32*)(_check_pointer(i0, 17725));
  *(OOC_INT32*)((_check_pointer(i2, 17716))+4) = ((OOC_INT32)RT0__NewObject(_td_Object__CharsUTF16.baseTypes[0], ((i3+i1)+1)));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17770))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 17808))+4);
  i0 = *(OOC_INT32*)(_check_pointer(i0, 17839));
  _move_block((_check_pointer(i1, 17775)),(_check_pointer(i2, 17813)),(i0*2));
  i0 = (OOC_INT32)s2;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17887))+4);
  i2 = (OOC_INT32)c32;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 17925))+4);
  i3 = (OOC_INT32)s1;
  i0 = *(OOC_INT32*)(_check_pointer(i0, 17981));
  i3 = *(OOC_INT32*)(_check_pointer(i3, 17935));
  _move_block((_check_pointer(i1, 17892)),((_check_pointer(i2, 17930))+i3*2),(2+i0*2));
  i0 = (OOC_INT32)c32;
  return (Object__String)i0;
  goto l40;
l12:
  i2 = (OOC_INT32)RT0__NewObject(_td_Object__String16.baseTypes[0]);
  c32 = (Object__String16)i2;
  i3 = *(OOC_INT32*)(_check_pointer(i1, 17279));
  i4 = *(OOC_INT32*)(_check_pointer(i0, 17269));
  *(OOC_INT32*)(_check_pointer(i2, 17256)) = (i4+i3);
  i1 = *(OOC_INT32*)(_check_pointer(i1, 17322));
  i3 = *(OOC_INT32*)(_check_pointer(i0, 17312));
  *(OOC_INT32*)((_check_pointer(i2, 17303))+4) = ((OOC_INT32)RT0__NewObject(_td_Object__CharsUTF16.baseTypes[0], ((i3+i1)+1)));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17357))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 17395))+4);
  i0 = *(OOC_INT32*)(_check_pointer(i0, 17426));
  _move_block((_check_pointer(i1, 17362)),(_check_pointer(i2, 17400)),(i0*2));
  i0 = (OOC_INT32)s2;
  i = 0;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 17475));
  i2 = (OOC_INT32)c32;
  i3 = 0<=i1;
  if (!i3) goto l20;
  i3 = (OOC_INT32)s1;
  i4=0;
l15_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 17499))+4);
  i5 = _check_pointer(i5, 17504);
  i6 = *(OOC_INT32*)(_check_pointer(i3, 17507));
  i7 = OOC_ARRAY_LENGTH(i5, 0);
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17523))+4);
  i8 = _check_pointer(i8, 17528);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i8 = *(OOC_UINT8*)(i8+(_check_index(i4, i9, OOC_UINT32, 17528)));
  *(OOC_UINT16*)(i5+(_check_index((i6+i4), i7, OOC_UINT32, 17504))*2) = i8;
  i4 = i4+1;
  i = i4;
  i5 = i4<=i1;
  if (i5) goto l15_loop;
l20:
  return (Object__String)i2;
  goto l40;
l23:
  i1 = (OOC_INT32)s2;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16299)))), &_td_Object__String8Desc);
  if (i2) goto l38;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16736)))), &_td_Object__String16Desc);
  if (i2) goto l28;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16732)))), 16732);
  goto l40;
l28:
  i2 = (OOC_INT32)RT0__NewObject(_td_Object__String16.baseTypes[0]);
  c32 = (Object__String16)i2;
  i3 = *(OOC_INT32*)(_check_pointer(i1, 16842));
  i4 = *(OOC_INT32*)(_check_pointer(i0, 16832));
  *(OOC_INT32*)(_check_pointer(i2, 16819)) = (i4+i3);
  i3 = *(OOC_INT32*)(_check_pointer(i1, 16885));
  i4 = *(OOC_INT32*)(_check_pointer(i0, 16875));
  *(OOC_INT32*)((_check_pointer(i2, 16866))+4) = ((OOC_INT32)RT0__NewObject(_td_Object__CharsUTF16.baseTypes[0], ((i4+i3)+1)));
  i = 0;
  i3 = *(OOC_INT32*)(_check_pointer(i0, 16921));
  i4 = 0<i3;
  if (!i4) goto l36;
  i4=0;
l31_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 16947))+4);
  i5 = _check_pointer(i5, 16952);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16961))+4);
  i7 = _check_pointer(i7, 16966);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = *(OOC_UINT8*)(i7+(_check_index(i4, i8, OOC_UINT32, 16966)));
  *(OOC_UINT16*)(i5+(_check_index(i4, i6, OOC_UINT32, 16952))*2) = i7;
  i4 = i4+1;
  i = i4;
  i5 = i4<i3;
  if (i5) goto l31_loop;
l36:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 17007))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 17045))+4);
  i1 = *(OOC_INT32*)(_check_pointer(i1, 17101));
  i0 = *(OOC_INT32*)(_check_pointer(i0, 17055));
  _move_block((_check_pointer(i3, 17012)),((_check_pointer(i2, 17050))+i0*2),(2+i1*2));
  i0 = (OOC_INT32)c32;
  return (Object__String)i0;
  goto l40;
l38:
  i2 = (OOC_INT32)RT0__NewObject(_td_Object__String8.baseTypes[0]);
  c8 = (Object__String8)i2;
  i3 = *(OOC_INT32*)(_check_pointer(i1, 16399));
  i4 = *(OOC_INT32*)(_check_pointer(i0, 16389));
  *(OOC_INT32*)(_check_pointer(i2, 16376)) = (i4+i3);
  i1 = *(OOC_INT32*)(_check_pointer(i1, 16441));
  i3 = *(OOC_INT32*)(_check_pointer(i0, 16431));
  *(OOC_INT32*)((_check_pointer(i2, 16422))+4) = ((OOC_INT32)RT0__NewObject(_td_Object__CharsLatin1.baseTypes[0], ((i3+i1)+1)));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16476))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 16513))+4);
  i0 = *(OOC_INT32*)(_check_pointer(i0, 16544));
  _move_block((_check_pointer(i1, 16481)),(_check_pointer(i2, 16518)),i0);
  i0 = (OOC_INT32)s2;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16588))+4);
  i2 = (OOC_INT32)c8;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 16625))+4);
  i3 = (OOC_INT32)s1;
  i0 = *(OOC_INT32*)(_check_pointer(i0, 16666));
  i3 = *(OOC_INT32*)(_check_pointer(i3, 16635));
  _move_block((_check_pointer(i1, 16593)),((_check_pointer(i2, 16630))+i3),(i0+1));
  i0 = (OOC_INT32)c8;
  return (Object__String)i0;
l40:
  _failed_function(16046); return 0;
  ;
}

Object__String Object__StringDesc_Concat(Object__String s, Object__String t) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)t;
  i1 = (OOC_INT32)s;
  i0 = (OOC_INT32)Object__Concat2((Object__String)i1, (Object__String)i0);
  return (Object__String)i0;
  ;
}

Object__CharsLatin1 Object__String8Desc_CharsLatin1(Object__String8 s) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)s;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18564))+4);
  return (Object__CharsLatin1)i0;
  ;
}

Object__CharsUTF16 Object__String16Desc_CharsUTF16(Object__String16 s) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)s;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18862))+4);
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

  _failed_function(19051); return 0;
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
  i1 = *(OOC_INT32*)(_check_pointer(i0, 19540));
  i1 = (OOC_INT32)RT0__NewObject(_td_Object__CharsLatin1.baseTypes[0], (i1+1));
  data8 = (Object__CharsLatin1)i1;
  i = 0;
  i2 = *(OOC_INT32*)(_check_pointer(i0, 19571));
  i3 = 0<=i2;
  if (!i3) goto l12;
  i3 = replace;
  i4=0;
l3_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19593))+4);
  i5 = _check_pointer(i5, 19598);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = *(OOC_UINT16*)(i5+(_check_index(i4, i6, OOC_UINT32, 19598))*2);
  i5 = (OOC_UINT16)i5>(OOC_UINT16)255u;
  if (i5) goto l6;
  i5 = _check_pointer(i1, 19725);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19739))+4);
  i7 = _check_pointer(i7, 19744);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = *(OOC_UINT16*)(i7+(_check_index(i4, i8, OOC_UINT32, 19744))*2);
  *(OOC_UINT8*)(i5+(_check_index(i4, i6, OOC_UINT32, 19725))) = i7;
  goto l7;
l6:
  i5 = _check_pointer(i1, 19685);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  *(OOC_UINT8*)(i5+(_check_index(i4, i6, OOC_UINT32, 19685))) = i3;
l7:
  i4 = i4+1;
  i = i4;
  i5 = i4<=i2;
  if (i5) goto l3_loop;
l12:
  i2 = (OOC_INT32)RT0__NewObject(_td_Object__String8.baseTypes[0]);
  s8 = (Object__String8)i2;
  i0 = *(OOC_INT32*)(_check_pointer(i0, 19802));
  *(OOC_INT32*)(_check_pointer(i2, 19790)) = i0;
  *(OOC_INT32*)((_check_pointer(i2, 19817))+4) = i1;
  return (Object__String8)i2;
  ;
}

Object__String16 Object__StringDesc_ToString16(Object__String s) {

  _failed_function(19899); return 0;
  ;
}

Object__String16 Object__String8Desc_ToString16(Object__String8 s) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  Object__CharsUTF16 data16;
  OOC_INT32 i;
  Object__String16 s16;

  i0 = (OOC_INT32)s;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 20164));
  i1 = (OOC_INT32)RT0__NewObject(_td_Object__CharsUTF16.baseTypes[0], (i1+1));
  data16 = (Object__CharsUTF16)i1;
  i = 0;
  i2 = *(OOC_INT32*)(_check_pointer(i0, 20195));
  i3 = 0<=i2;
  if (!i3) goto l8;
  i3=0;
l3_loop:
  i4 = _check_pointer(i1, 20218);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20226))+4);
  i6 = _check_pointer(i6, 20231);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = *(OOC_UINT8*)(i6+(_check_index(i3, i7, OOC_UINT32, 20231)));
  *(OOC_UINT16*)(i4+(_check_index(i3, i5, OOC_UINT32, 20218))*2) = i6;
  i3 = i3+1;
  i = i3;
  i4 = i3<=i2;
  if (i4) goto l3_loop;
l8:
  i2 = (OOC_INT32)RT0__NewObject(_td_Object__String16.baseTypes[0]);
  s16 = (Object__String16)i2;
  i0 = *(OOC_INT32*)(_check_pointer(i0, 20283));
  *(OOC_INT32*)(_check_pointer(i2, 20271)) = i0;
  *(OOC_INT32*)((_check_pointer(i2, 20299))+4) = i1;
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

  _failed_function(20474); return 0;
  ;
}

OOC_CHAR8 Object__String8Desc_Equals(Object__String8 s, Object__Object y) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_INT32 i;

  i0 = (OOC_INT32)y;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l3;
  i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20624)))), &_td_Object__StringDesc));
  
  goto l5;
l3:
  i1=1u;
l5:
  if (i1) goto l7;
  i1 = (OOC_INT32)s;
  i2 = *(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20652)))), &_td_Object__StringDesc, 20652)), 20659));
  i1 = *(OOC_INT32*)(_check_pointer(i1, 20640));
  i1 = i1!=i2;
  
  goto l9;
l7:
  i1=1u;
l9:
  if (i1) goto l53;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20714)))), &_td_Object__String8Desc);
  if (i1) goto l34;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20872)))), &_td_Object__String16Desc);
  if (i1) goto l15;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20869)))), 20869);
  goto l54;
l15:
  i = 0;
  i1 = (OOC_INT32)s;
  i2 = *(OOC_INT32*)(_check_pointer(i1, 20922));
  i2 = 0!=i2;
  if (i2) goto l18;
  i2=0u;
  goto l20;
l18:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 20935))+4);
  i2 = _check_pointer(i2, 20940);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20947))+4);
  i4 = _check_pointer(i4, 20952);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i2 = *(OOC_UINT8*)(i2+(_check_index(0, i3, OOC_UINT32, 20940)));
  i3 = *(OOC_UINT16*)(i4+(_check_index(0, i5, OOC_UINT32, 20952))*2);
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
  i3 = *(OOC_INT32*)(_check_pointer(i1, 20922));
  i3 = i2!=i3;
  if (i3) goto l26;
  i3=0u;
  goto l28;
l26:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 20935))+4);
  i3 = _check_pointer(i3, 20940);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20947))+4);
  i5 = _check_pointer(i5, 20952);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i3 = *(OOC_UINT8*)(i3+(_check_index(i2, i4, OOC_UINT32, 20940)));
  i4 = *(OOC_UINT16*)(i5+(_check_index(i2, i6, OOC_UINT32, 20952))*2);
  i3 = i3==i4;
  
l28:
  if (i3) goto l23_loop;
l31:
  i0=i2;
l32:
  i1 = *(OOC_INT32*)(_check_pointer(i1, 21012));
  return (i0==i1);
  goto l54;
l34:
  i = 0;
  i1 = (OOC_INT32)s;
  i2 = *(OOC_INT32*)(_check_pointer(i1, 20763));
  i2 = 0!=i2;
  if (i2) goto l37;
  i2=0u;
  goto l39;
l37:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 20776))+4);
  i2 = _check_pointer(i2, 20781);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20788))+4);
  i4 = _check_pointer(i4, 20793);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i2 = *(OOC_UINT8*)(i2+(_check_index(0, i3, OOC_UINT32, 20781)));
  i3 = *(OOC_UINT8*)(i4+(_check_index(0, i5, OOC_UINT32, 20793)));
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
  i3 = *(OOC_INT32*)(_check_pointer(i1, 20763));
  i3 = i2!=i3;
  if (i3) goto l45;
  i3=0u;
  goto l47;
l45:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 20776))+4);
  i3 = _check_pointer(i3, 20781);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20788))+4);
  i5 = _check_pointer(i5, 20793);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i3 = *(OOC_UINT8*)(i3+(_check_index(i2, i4, OOC_UINT32, 20781)));
  i4 = *(OOC_UINT8*)(i5+(_check_index(i2, i6, OOC_UINT32, 20793)));
  i3 = i3==i4;
  
l47:
  if (i3) goto l42_loop;
l50:
  i0=i2;
l51:
  i1 = *(OOC_INT32*)(_check_pointer(i1, 20853));
  return (i0==i1);
  goto l54;
l53:
  return 0u;
l54:
  _failed_function(20541); return 0;
  ;
}

OOC_CHAR8 Object__String16Desc_Equals(Object__String16 s, Object__Object y) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_INT32 i;

  i0 = (OOC_INT32)y;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l3;
  i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21164)))), &_td_Object__StringDesc));
  
  goto l5;
l3:
  i1=1u;
l5:
  if (i1) goto l7;
  i1 = (OOC_INT32)s;
  i2 = *(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21192)))), &_td_Object__StringDesc, 21192)), 21199));
  i1 = *(OOC_INT32*)(_check_pointer(i1, 21180));
  i1 = i1!=i2;
  
  goto l9;
l7:
  i1=1u;
l9:
  if (i1) goto l53;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21254)))), &_td_Object__String8Desc);
  if (i1) goto l34;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21412)))), &_td_Object__String16Desc);
  if (i1) goto l15;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21409)))), 21409);
  goto l54;
l15:
  i = 0;
  i1 = (OOC_INT32)s;
  i2 = *(OOC_INT32*)(_check_pointer(i1, 21462));
  i2 = 0!=i2;
  if (i2) goto l18;
  i2=0u;
  goto l20;
l18:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 21475))+4);
  i2 = _check_pointer(i2, 21480);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21487))+4);
  i4 = _check_pointer(i4, 21492);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i2 = *(OOC_UINT16*)(i2+(_check_index(0, i3, OOC_UINT32, 21480))*2);
  i3 = *(OOC_UINT16*)(i4+(_check_index(0, i5, OOC_UINT32, 21492))*2);
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
  i3 = *(OOC_INT32*)(_check_pointer(i1, 21462));
  i3 = i2!=i3;
  if (i3) goto l26;
  i3=0u;
  goto l28;
l26:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 21475))+4);
  i3 = _check_pointer(i3, 21480);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21487))+4);
  i5 = _check_pointer(i5, 21492);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i3 = *(OOC_UINT16*)(i3+(_check_index(i2, i4, OOC_UINT32, 21480))*2);
  i4 = *(OOC_UINT16*)(i5+(_check_index(i2, i6, OOC_UINT32, 21492))*2);
  i3 = i3==i4;
  
l28:
  if (i3) goto l23_loop;
l31:
  i0=i2;
l32:
  i1 = *(OOC_INT32*)(_check_pointer(i1, 21552));
  return (i0==i1);
  goto l54;
l34:
  i = 0;
  i1 = (OOC_INT32)s;
  i2 = *(OOC_INT32*)(_check_pointer(i1, 21303));
  i2 = 0!=i2;
  if (i2) goto l37;
  i2=0u;
  goto l39;
l37:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 21316))+4);
  i2 = _check_pointer(i2, 21321);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21328))+4);
  i4 = _check_pointer(i4, 21333);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i2 = *(OOC_UINT16*)(i2+(_check_index(0, i3, OOC_UINT32, 21321))*2);
  i3 = *(OOC_UINT8*)(i4+(_check_index(0, i5, OOC_UINT32, 21333)));
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
  i3 = *(OOC_INT32*)(_check_pointer(i1, 21303));
  i3 = i2!=i3;
  if (i3) goto l45;
  i3=0u;
  goto l47;
l45:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 21316))+4);
  i3 = _check_pointer(i3, 21321);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21328))+4);
  i5 = _check_pointer(i5, 21333);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i3 = *(OOC_UINT16*)(i3+(_check_index(i2, i4, OOC_UINT32, 21321))*2);
  i4 = *(OOC_UINT8*)(i5+(_check_index(i2, i6, OOC_UINT32, 21333)));
  i3 = i3==i4;
  
l47:
  if (i3) goto l42_loop;
l50:
  i0=i2;
l51:
  i1 = *(OOC_INT32*)(_check_pointer(i1, 21393));
  return (i0==i1);
  goto l54;
l53:
  return 0u;
l54:
  _failed_function(21081); return 0;
  ;
}

OOC_CHAR8 Object__StringDesc_EqualsIgnoreCase(Object__String s, Object__Object y) {

  _failed_function(21630); return 0;
  ;
}

OOC_CHAR8 Object__String8Desc_EqualsIgnoreCase(Object__String8 s, Object__Object y) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_INT32 i;

  i0 = (OOC_INT32)y;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l3;
  i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21810)))), &_td_Object__StringDesc));
  
  goto l5;
l3:
  i1=1u;
l5:
  if (i1) goto l7;
  i1 = (OOC_INT32)s;
  i2 = *(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21838)))), &_td_Object__StringDesc, 21838)), 21845));
  i1 = *(OOC_INT32*)(_check_pointer(i1, 21826));
  i1 = i1!=i2;
  
  goto l9;
l7:
  i1=1u;
l9:
  if (i1) goto l53;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21975)))), &_td_Object__String8Desc);
  if (i1) goto l34;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22143)))), &_td_Object__String16Desc);
  if (i1) goto l15;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22140)))), 22140);
  goto l54;
l15:
  i = 0;
  i1 = (OOC_INT32)s;
  i2 = *(OOC_INT32*)(_check_pointer(i1, 22193));
  i2 = 0!=i2;
  if (i2) goto l18;
  i2=0u;
  goto l20;
l18:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 22210))+4);
  i2 = _check_pointer(i2, 22215);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22227))+4);
  i4 = _check_pointer(i4, 22232);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i2 = *(OOC_UINT8*)(i2+(_check_index(0, i3, OOC_UINT32, 22215)));
  i3 = *(OOC_UINT16*)(i4+(_check_index(0, i5, OOC_UINT32, 22232))*2);
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
  i3 = *(OOC_INT32*)(_check_pointer(i1, 22193));
  i3 = i2!=i3;
  if (i3) goto l26;
  i3=0u;
  goto l28;
l26:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 22210))+4);
  i3 = _check_pointer(i3, 22215);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22227))+4);
  i5 = _check_pointer(i5, 22232);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i3 = *(OOC_UINT8*)(i3+(_check_index(i2, i4, OOC_UINT32, 22215)));
  i4 = *(OOC_UINT16*)(i5+(_check_index(i2, i6, OOC_UINT32, 22232))*2);
  i3 = (_cap(i3))==(_cap(i4));
  
l28:
  if (i3) goto l23_loop;
l31:
  i0=i2;
l32:
  i1 = *(OOC_INT32*)(_check_pointer(i1, 22293));
  return (i0==i1);
  goto l54;
l34:
  i = 0;
  i1 = (OOC_INT32)s;
  i2 = *(OOC_INT32*)(_check_pointer(i1, 22024));
  i2 = 0!=i2;
  if (i2) goto l37;
  i2=0u;
  goto l39;
l37:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 22041))+4);
  i2 = _check_pointer(i2, 22046);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22058))+4);
  i4 = _check_pointer(i4, 22063);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i2 = *(OOC_UINT8*)(i2+(_check_index(0, i3, OOC_UINT32, 22046)));
  i3 = *(OOC_UINT8*)(i4+(_check_index(0, i5, OOC_UINT32, 22063)));
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
  i3 = *(OOC_INT32*)(_check_pointer(i1, 22024));
  i3 = i2!=i3;
  if (i3) goto l45;
  i3=0u;
  goto l47;
l45:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 22041))+4);
  i3 = _check_pointer(i3, 22046);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22058))+4);
  i5 = _check_pointer(i5, 22063);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i3 = *(OOC_UINT8*)(i3+(_check_index(i2, i4, OOC_UINT32, 22046)));
  i4 = *(OOC_UINT8*)(i5+(_check_index(i2, i6, OOC_UINT32, 22063)));
  i3 = (_cap(i3))==(_cap(i4));
  
l47:
  if (i3) goto l42_loop;
l50:
  i0=i2;
l51:
  i1 = *(OOC_INT32*)(_check_pointer(i1, 22124));
  return (i0==i1);
  goto l54;
l53:
  return 0u;
l54:
  _failed_function(21717); return 0;
  ;
}

OOC_CHAR8 Object__String16Desc_EqualsIgnoreCase(Object__String16 s, Object__Object y) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_INT32 i;

  i0 = (OOC_INT32)y;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l3;
  i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22465)))), &_td_Object__StringDesc));
  
  goto l5;
l3:
  i1=1u;
l5:
  if (i1) goto l7;
  i1 = (OOC_INT32)s;
  i2 = *(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22493)))), &_td_Object__StringDesc, 22493)), 22500));
  i1 = *(OOC_INT32*)(_check_pointer(i1, 22481));
  i1 = i1!=i2;
  
  goto l9;
l7:
  i1=1u;
l9:
  if (i1) goto l53;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22630)))), &_td_Object__String8Desc);
  if (i1) goto l34;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22798)))), &_td_Object__String16Desc);
  if (i1) goto l15;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22795)))), 22795);
  goto l54;
l15:
  i = 0;
  i1 = (OOC_INT32)s;
  i2 = *(OOC_INT32*)(_check_pointer(i1, 22848));
  i2 = 0!=i2;
  if (i2) goto l18;
  i2=0u;
  goto l20;
l18:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 22865))+4);
  i2 = _check_pointer(i2, 22870);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22882))+4);
  i4 = _check_pointer(i4, 22887);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i2 = *(OOC_UINT16*)(i2+(_check_index(0, i3, OOC_UINT32, 22870))*2);
  i3 = *(OOC_UINT16*)(i4+(_check_index(0, i5, OOC_UINT32, 22887))*2);
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
  i3 = *(OOC_INT32*)(_check_pointer(i1, 22848));
  i3 = i2!=i3;
  if (i3) goto l26;
  i3=0u;
  goto l28;
l26:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 22865))+4);
  i3 = _check_pointer(i3, 22870);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22882))+4);
  i5 = _check_pointer(i5, 22887);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i3 = *(OOC_UINT16*)(i3+(_check_index(i2, i4, OOC_UINT32, 22870))*2);
  i4 = *(OOC_UINT16*)(i5+(_check_index(i2, i6, OOC_UINT32, 22887))*2);
  i3 = (_cap(i3))==(_cap(i4));
  
l28:
  if (i3) goto l23_loop;
l31:
  i0=i2;
l32:
  i1 = *(OOC_INT32*)(_check_pointer(i1, 22948));
  return (i0==i1);
  goto l54;
l34:
  i = 0;
  i1 = (OOC_INT32)s;
  i2 = *(OOC_INT32*)(_check_pointer(i1, 22679));
  i2 = 0!=i2;
  if (i2) goto l37;
  i2=0u;
  goto l39;
l37:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 22696))+4);
  i2 = _check_pointer(i2, 22701);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22713))+4);
  i4 = _check_pointer(i4, 22718);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i2 = *(OOC_UINT16*)(i2+(_check_index(0, i3, OOC_UINT32, 22701))*2);
  i3 = *(OOC_UINT8*)(i4+(_check_index(0, i5, OOC_UINT32, 22718)));
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
  i3 = *(OOC_INT32*)(_check_pointer(i1, 22679));
  i3 = i2!=i3;
  if (i3) goto l45;
  i3=0u;
  goto l47;
l45:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 22696))+4);
  i3 = _check_pointer(i3, 22701);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22713))+4);
  i5 = _check_pointer(i5, 22718);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i3 = *(OOC_UINT16*)(i3+(_check_index(i2, i4, OOC_UINT32, 22701))*2);
  i4 = *(OOC_UINT8*)(i5+(_check_index(i2, i6, OOC_UINT32, 22718)));
  i3 = (_cap(i3))==(_cap(i4));
  
l47:
  if (i3) goto l42_loop;
l50:
  i0=i2;
l51:
  i1 = *(OOC_INT32*)(_check_pointer(i1, 22779));
  return (i0==i1);
  goto l54;
l53:
  return 0u;
l54:
  _failed_function(22372); return 0;
  ;
}

OOC_INT32 Object__StringDesc_Compare(Object__String s, Object__Object y) {

  _failed_function(23036); return 0;
  ;
}

OOC_INT32 Object__String8Desc_Compare(Object__String8 s, Object__Object y) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  OOC_INT32 min;
  OOC_INT32 i;

  i0 = (OOC_INT32)s;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 23588));
  min = i1;
  i2 = (OOC_INT32)y;
  i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 23607)))), &_td_Object__String8Desc);
  if (i3) goto l32;
  i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 23906)))), &_td_Object__String16Desc);
  if (i3) goto l5;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 23903)))), 23903);
  goto l58;
l5:
  i3 = *(OOC_INT32*)(_check_pointer(i2, 23931));
  i3 = i3<i1;
  if (!i3) goto l9;
  i1 = *(OOC_INT32*)(_check_pointer(i2, 23959));
  min = i1;
  
l9:
  i = 0;
  i3 = 0!=i1;
  if (i3) goto l12;
  i3=0u;
  goto l14;
l12:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24013))+4);
  i3 = _check_pointer(i3, 24018);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 24025))+4);
  i5 = _check_pointer(i5, 24030);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i3 = *(OOC_UINT8*)(i3+(_check_index(0, i4, OOC_UINT32, 24018)));
  i4 = *(OOC_UINT16*)(i5+(_check_index(0, i6, OOC_UINT32, 24030))*2);
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
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24013))+4);
  i4 = _check_pointer(i4, 24018);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 24025))+4);
  i6 = _check_pointer(i6, 24030);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i4 = *(OOC_UINT8*)(i4+(_check_index(i3, i5, OOC_UINT32, 24018)));
  i5 = *(OOC_UINT16*)(i6+(_check_index(i3, i7, OOC_UINT32, 24030))*2);
  i4 = i4==i5;
  
l22:
  if (i4) goto l17_loop;
l26:
  i1 = i3==i1;
  if (i1) goto l29;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24159))+4);
  i0 = _check_pointer(i0, 24164);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 24176))+4);
  i2 = _check_pointer(i2, 24181);
  i4 = OOC_ARRAY_LENGTH(i2, 0);
  i0 = *(OOC_UINT8*)(i0+(_check_index(i3, i1, OOC_UINT32, 24164)));
  i1 = *(OOC_UINT16*)(i2+(_check_index(i3, i4, OOC_UINT32, 24181))*2);
  return (i0-i1);
  goto l58;
l29:
  i1 = *(OOC_INT32*)(_check_pointer(i2, 24117));
  i0 = *(OOC_INT32*)(_check_pointer(i0, 24106));
  return (i0-i1);
  goto l58;
l32:
  i3 = *(OOC_INT32*)(_check_pointer(i2, 23631));
  i3 = i3<i1;
  if (!i3) goto l36;
  i1 = *(OOC_INT32*)(_check_pointer(i2, 23659));
  min = i1;
  
l36:
  i = 0;
  i3 = 0!=i1;
  if (i3) goto l39;
  i3=0u;
  goto l41;
l39:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23713))+4);
  i3 = _check_pointer(i3, 23718);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 23725))+4);
  i5 = _check_pointer(i5, 23730);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i3 = *(OOC_UINT8*)(i3+(_check_index(0, i4, OOC_UINT32, 23718)));
  i4 = *(OOC_UINT8*)(i5+(_check_index(0, i6, OOC_UINT32, 23730)));
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
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23713))+4);
  i4 = _check_pointer(i4, 23718);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 23725))+4);
  i6 = _check_pointer(i6, 23730);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i4 = *(OOC_UINT8*)(i4+(_check_index(i3, i5, OOC_UINT32, 23718)));
  i5 = *(OOC_UINT8*)(i6+(_check_index(i3, i7, OOC_UINT32, 23730)));
  i4 = i4==i5;
  
l49:
  if (i4) goto l44_loop;
l53:
  i1 = i3==i1;
  if (i1) goto l56;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23859))+4);
  i0 = _check_pointer(i0, 23864);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 23876))+4);
  i2 = _check_pointer(i2, 23881);
  i4 = OOC_ARRAY_LENGTH(i2, 0);
  i0 = *(OOC_UINT8*)(i0+(_check_index(i3, i1, OOC_UINT32, 23864)));
  i1 = *(OOC_UINT8*)(i2+(_check_index(i3, i4, OOC_UINT32, 23881)));
  return (i0-i1);
  goto l58;
l56:
  i1 = *(OOC_INT32*)(_check_pointer(i2, 23817));
  i0 = *(OOC_INT32*)(_check_pointer(i0, 23806));
  return (i0-i1);
l58:
  _failed_function(23511); return 0;
  ;
}

OOC_INT32 Object__String16Desc_Compare(Object__String16 s, Object__Object y) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  OOC_INT32 min;
  OOC_INT32 i;

  i0 = (OOC_INT32)s;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 24325));
  min = i1;
  i2 = (OOC_INT32)y;
  i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 24344)))), &_td_Object__String8Desc);
  if (i3) goto l32;
  i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 24643)))), &_td_Object__String16Desc);
  if (i3) goto l5;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 24640)))), 24640);
  goto l58;
l5:
  i3 = *(OOC_INT32*)(_check_pointer(i2, 24668));
  i3 = i3<i1;
  if (!i3) goto l9;
  i1 = *(OOC_INT32*)(_check_pointer(i2, 24696));
  min = i1;
  
l9:
  i = 0;
  i3 = 0!=i1;
  if (i3) goto l12;
  i3=0u;
  goto l14;
l12:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24750))+4);
  i3 = _check_pointer(i3, 24755);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 24762))+4);
  i5 = _check_pointer(i5, 24767);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i3 = *(OOC_UINT16*)(i3+(_check_index(0, i4, OOC_UINT32, 24755))*2);
  i4 = *(OOC_UINT16*)(i5+(_check_index(0, i6, OOC_UINT32, 24767))*2);
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
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24750))+4);
  i4 = _check_pointer(i4, 24755);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 24762))+4);
  i6 = _check_pointer(i6, 24767);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i4 = *(OOC_UINT16*)(i4+(_check_index(i3, i5, OOC_UINT32, 24755))*2);
  i5 = *(OOC_UINT16*)(i6+(_check_index(i3, i7, OOC_UINT32, 24767))*2);
  i4 = i4==i5;
  
l22:
  if (i4) goto l17_loop;
l26:
  i1 = i3==i1;
  if (i1) goto l29;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24896))+4);
  i0 = _check_pointer(i0, 24901);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 24913))+4);
  i2 = _check_pointer(i2, 24918);
  i4 = OOC_ARRAY_LENGTH(i2, 0);
  i0 = *(OOC_UINT16*)(i0+(_check_index(i3, i1, OOC_UINT32, 24901))*2);
  i1 = *(OOC_UINT16*)(i2+(_check_index(i3, i4, OOC_UINT32, 24918))*2);
  return (i0-i1);
  goto l58;
l29:
  i1 = *(OOC_INT32*)(_check_pointer(i2, 24854));
  i0 = *(OOC_INT32*)(_check_pointer(i0, 24843));
  return (i0-i1);
  goto l58;
l32:
  i3 = *(OOC_INT32*)(_check_pointer(i2, 24368));
  i3 = i3<i1;
  if (!i3) goto l36;
  i1 = *(OOC_INT32*)(_check_pointer(i2, 24396));
  min = i1;
  
l36:
  i = 0;
  i3 = 0!=i1;
  if (i3) goto l39;
  i3=0u;
  goto l41;
l39:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24450))+4);
  i3 = _check_pointer(i3, 24455);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 24462))+4);
  i5 = _check_pointer(i5, 24467);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i3 = *(OOC_UINT16*)(i3+(_check_index(0, i4, OOC_UINT32, 24455))*2);
  i4 = *(OOC_UINT8*)(i5+(_check_index(0, i6, OOC_UINT32, 24467)));
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
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24450))+4);
  i4 = _check_pointer(i4, 24455);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 24462))+4);
  i6 = _check_pointer(i6, 24467);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i4 = *(OOC_UINT16*)(i4+(_check_index(i3, i5, OOC_UINT32, 24455))*2);
  i5 = *(OOC_UINT8*)(i6+(_check_index(i3, i7, OOC_UINT32, 24467)));
  i4 = i4==i5;
  
l49:
  if (i4) goto l44_loop;
l53:
  i1 = i3==i1;
  if (i1) goto l56;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24596))+4);
  i0 = _check_pointer(i0, 24601);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 24613))+4);
  i2 = _check_pointer(i2, 24618);
  i4 = OOC_ARRAY_LENGTH(i2, 0);
  i0 = *(OOC_UINT16*)(i0+(_check_index(i3, i1, OOC_UINT32, 24601))*2);
  i1 = *(OOC_UINT8*)(i2+(_check_index(i3, i4, OOC_UINT32, 24618)));
  return (i0-i1);
  goto l58;
l56:
  i1 = *(OOC_INT32*)(_check_pointer(i2, 24554));
  i0 = *(OOC_INT32*)(_check_pointer(i0, 24543));
  return (i0-i1);
l58:
  _failed_function(24248); return 0;
  ;
}

OOC_INT32 Object__StringDesc_HashCode(Object__String s) {

  _failed_function(24994); return 0;
  ;
}

OOC_INT32 Object__String8Desc_HashCode(Object__String8 s) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)s;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25112))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25112))+4);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 25117)), 0);
  i0 = *(OOC_INT32*)(_check_pointer(i0, 25124));
  i0 = HashCode__CharRegion((void*)(_check_pointer(i2, 25117)), i1, 0, i0);
  return i0;
  ;
}

OOC_INT32 Object__String16Desc_HashCode(Object__String16 s) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)s;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25238))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25238))+4);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 25243)), 0);
  i0 = *(OOC_INT32*)(_check_pointer(i0, 25250));
  i0 = HashCode__LongCharRegion((void*)(_check_pointer(i2, 25243)), i1, 0, i0);
  return i0;
  ;
}

OOC_CHAR32 Object__StringDesc_CharAt(Object__String s, OOC_INT32 index) {

  _failed_function(25310); return 0;
  ;
}

OOC_CHAR32 Object__String8Desc_CharAt(Object__String8 s, OOC_INT32 index) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)s;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25572))+4);
  i0 = _check_pointer(i0, 25577);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i2 = index;
  i0 = *(OOC_UINT8*)(i0+(_check_index(i2, i1, OOC_UINT32, 25577)));
  return i0;
  ;
}

OOC_CHAR32 Object__String16Desc_CharAt(Object__String16 s, OOC_INT32 index) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_CHAR16 _w1;

  i0 = (OOC_INT32)s;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25707))+4);
  i1 = _check_pointer(i1, 25712);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i3 = index;
  i1 = *(OOC_UINT16*)(i1+(_check_index(i3, i2, OOC_UINT32, 25712))*2);
  _w1 = i1;
  i2 = (OOC_UINT16)i1<(OOC_UINT16)55296u;
  if (i2) goto l3;
  i2 = (OOC_UINT16)i1>=(OOC_UINT16)57344u;
  
  goto l5;
l3:
  i2=1u;
l5:
  if (i2) goto l19;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25985))+4);
  i0 = _check_pointer(i0, 25990);
  i2 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = *(OOC_UINT16*)(i0+(_check_index((i3+1), i2, OOC_UINT32, 25990))*2);
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
  _failed_function(25625); return 0;
  ;
}

OOC_CHAR32 Object__StringDesc_NextChar(Object__String s, OOC_INT32 *index) {

  _failed_function(26357); return 0;
  ;
}

OOC_CHAR32 Object__String8Desc_NextChar(Object__String8 s, OOC_INT32 *index) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)s;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26809))+4);
  i0 = _check_pointer(i0, 26814);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i2 = *index;
  *index = (i2+1);
  i0 = *(OOC_UINT8*)(i0+(_check_index(i2, i1, OOC_UINT32, 26814)));
  return i0;
  ;
}

OOC_CHAR32 Object__String16Desc_NextChar(Object__String16 s, OOC_INT32 *index) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_CHAR16 _w1;

  i0 = (OOC_INT32)s;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26982))+4);
  i1 = _check_pointer(i1, 26987);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i3 = *index;
  i1 = *(OOC_UINT16*)(i1+(_check_index(i3, i2, OOC_UINT32, 26987))*2);
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
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27275))+4);
  i0 = _check_pointer(i0, 27280);
  i3 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = *(OOC_UINT16*)(i0+(_check_index(i2, i3, OOC_UINT32, 27280))*2);
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
  _failed_function(26894); return 0;
  ;
}

Object__String Object__StringDesc_Substring(Object__String s, OOC_INT32 start, OOC_INT32 end) {

  _failed_function(27666); return 0;
  ;
}

Object__String8 Object__String8Desc_Substring(Object__String8 s, OOC_INT32 start, OOC_INT32 end) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)s;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28098))+4);
  i1 = start;
  i2 = end;
  i0 = (OOC_INT32)Object__NewString8(((_check_pointer(i0, 28103))+i1), (i2-i1));
  return (Object__String8)i0;
  ;
}

Object__String16 Object__String16Desc_Substring(Object__String16 s, OOC_INT32 start, OOC_INT32 end) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)s;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28249))+4);
  i1 = start;
  i2 = end;
  i0 = (OOC_INT32)Object__NewString16(((_check_pointer(i0, 28254))+i1*2), (i2-i1));
  return (Object__String16)i0;
  ;
}

Object__String Object__StringDesc_Trim(Object__String s) {

  _failed_function(28343); return 0;
  ;
}

Object__String8 Object__String8Desc_Trim(Object__String8 s) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT32 a;
  OOC_INT32 b;

  a = 0;
  i0 = (OOC_INT32)s;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 28732));
  i1 = 0!=i1;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28745))+4);
  i1 = _check_pointer(i1, 28750);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_UINT8*)(i1+(_check_index(0, i2, OOC_UINT32, 28750)));
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
  i2 = *(OOC_INT32*)(_check_pointer(i0, 28732));
  i2 = i1!=i2;
  if (i2) goto l11;
  i2=0u;
  goto l13;
l11:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28745))+4);
  i2 = _check_pointer(i2, 28750);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = *(OOC_UINT8*)(i2+(_check_index(i1, i3, OOC_UINT32, 28750)));
  i2 = (OOC_UINT8)i2<=(OOC_UINT8)32u;
  
l13:
  if (i2) goto l8_loop;
l17:
  i2 = *(OOC_INT32*)(_check_pointer(i0, 28798));
  b = i2;
  i3 = i2!=i1;
  if (i3) goto l20;
  i3=0u;
  goto l22;
l20:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28829))+4);
  i3 = _check_pointer(i3, 28834);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = *(OOC_UINT8*)(i3+(_check_index((i2-1), i4, OOC_UINT32, 28834)));
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
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28829))+4);
  i3 = _check_pointer(i3, 28834);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = *(OOC_UINT8*)(i3+(_check_index((i2-1), i4, OOC_UINT32, 28834)));
  i3 = (OOC_UINT8)i3<=(OOC_UINT8)32u;
  
l30:
  if (i3) goto l25_loop;
l34:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28903))+4);
  i0 = (OOC_INT32)Object__NewString8(((_check_pointer(i0, 28908))+i1), (i2-i1));
  return (Object__String8)i0;
  ;
}

Object__String16 Object__String16Desc_Trim(Object__String16 s) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT32 a;
  OOC_INT32 b;

  a = 0;
  i0 = (OOC_INT32)s;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 29037));
  i1 = 0!=i1;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29050))+4);
  i1 = _check_pointer(i1, 29055);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_UINT16*)(i1+(_check_index(0, i2, OOC_UINT32, 29055))*2);
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
  i2 = *(OOC_INT32*)(_check_pointer(i0, 29037));
  i2 = i1!=i2;
  if (i2) goto l11;
  i2=0u;
  goto l13;
l11:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29050))+4);
  i2 = _check_pointer(i2, 29055);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = *(OOC_UINT16*)(i2+(_check_index(i1, i3, OOC_UINT32, 29055))*2);
  i2 = (OOC_UINT16)i2<=(OOC_UINT16)32u;
  
l13:
  if (i2) goto l8_loop;
l17:
  i2 = *(OOC_INT32*)(_check_pointer(i0, 29103));
  b = i2;
  i3 = i2!=i1;
  if (i3) goto l20;
  i3=0u;
  goto l22;
l20:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29134))+4);
  i3 = _check_pointer(i3, 29139);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = *(OOC_UINT16*)(i3+(_check_index((i2-1), i4, OOC_UINT32, 29139))*2);
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
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29134))+4);
  i3 = _check_pointer(i3, 29139);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = *(OOC_UINT16*)(i3+(_check_index((i2-1), i4, OOC_UINT32, 29139))*2);
  i3 = (OOC_UINT16)i3<=(OOC_UINT16)32u;
  
l30:
  if (i3) goto l25_loop;
l34:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29209))+4);
  i0 = (OOC_INT32)Object__NewString16(((_check_pointer(i0, 29214))+i1*2), (i2-i1));
  return (Object__String16)i0;
  ;
}

OOC_INT32 Object__StringDesc_IndexOf(Object__String s, OOC_CHAR32 _char, OOC_INT32 pos) {

  _failed_function(29288); return 0;
  ;
}

OOC_INT32 Object__String8Desc_IndexOf(Object__String8 s, OOC_CHAR32 _char, OOC_INT32 pos) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 endpos;

  i0 = (OOC_INT32)s;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 29771));
  endpos = i1;
  i2 = pos;
  i3 = i2!=i1;
  if (!i3) goto l11;
  i3 = _char;
  
l3_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29819))+4);
  i4 = _check_pointer(i4, 29824);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = *(OOC_UINT8*)(i4+(_check_index(i2, i5, OOC_UINT32, 29824)));
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
  i3 = *(OOC_INT32*)(_check_pointer(i2, 30455));
  endpos = i3;
  i4 = pos;
  i5 = i4!=i3;
  if (!i5) goto l17;
l5_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 30507))+4);
  i5 = _check_pointer(i5, 30512);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = *(OOC_UINT16*)(i5+(_check_index(i4, i6, OOC_UINT32, 30512))*2);
  i6 = i4+1;
  i5 = i5==i1;
  if (i5) goto l8;
  i5=0u;
  goto l10;
l8:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 30528))+4);
  i5 = _check_pointer(i5, 30533);
  i7 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = *(OOC_UINT16*)(i5+(_check_index(i6, i7, OOC_UINT32, 30533))*2);
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
  i2 = *(OOC_INT32*)(_check_pointer(i1, 30116));
  endpos = i2;
  i3 = pos;
  i4 = i3!=i2;
  if (!i4) goto l29;
l21_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 30168))+4);
  i4 = _check_pointer(i4, 30173);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = *(OOC_UINT16*)(i4+(_check_index(i3, i5, OOC_UINT32, 30173))*2);
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
  _failed_function(29954); return 0;
  ;
}

OOC_INT32 Object__StringDesc_LastIndexOf(Object__String s, OOC_CHAR32 _char, OOC_INT32 pos) {

  _failed_function(30813); return 0;
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
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 31346))+4);
  i3 = _check_pointer(i3, 31351);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = *(OOC_UINT8*)(i3+(_check_index(i0, i4, OOC_UINT32, 31351)));
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
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 31974))+4);
  i4 = _check_pointer(i4, 31979);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = *(OOC_UINT16*)(i4+(_check_index(i2, i5, OOC_UINT32, 31979))*2);
  i4 = i4==i1;
  if (i4) goto l8;
  i4=0u;
  goto l10;
l8:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 31995))+4);
  i4 = _check_pointer(i4, 32000);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = *(OOC_UINT16*)(i4+(_check_index((i2+1), i5, OOC_UINT32, 32000))*2);
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
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 31666))+4);
  i3 = _check_pointer(i3, 31671);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = *(OOC_UINT16*)(i3+(_check_index(i1, i4, OOC_UINT32, 31671))*2);
  i3 = i3==i0;
  if (!i3) goto l24;
  return i1;
l24:
  i3 = i1>0;
  if (i3) goto l21_loop;
l29:
  return (-1);
l30:
  _failed_function(31469); return 0;
  ;
}

OOC_CHAR8 Object__StringDesc_EndsWith(Object__String s, Object__String suffix) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  Object__String e;

  i0 = (OOC_INT32)s;
  i1 = (OOC_INT32)suffix;
  i2 = *(OOC_INT32*)(_check_pointer(i0, 32593));
  i3 = *(OOC_INT32*)(_check_pointer(i1, 32610));
  i2 = i2>=i3;
  if (i2) goto l3;
  return 0u;
  goto l4;
l3:
  i2 = *(OOC_INT32*)(_check_pointer(i1, 32662));
  i3 = *(OOC_INT32*)(_check_pointer(i0, 32648));
  i4 = *(OOC_INT32*)(_check_pointer(i0, 32672));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32636)))), Object__StringDesc_Substring)),Object__StringDesc_Substring)((Object__String)i0, (i3-i2), i4);
  e = (Object__String)i0;
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32696)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i0, (Object__Object)i1);
  return i0;
l4:
  _failed_function(32281); return 0;
  ;
}

OOC_CHAR8 Object__StringDesc_StartsWith(Object__String s, Object__String prefix) {
  register OOC_INT32 i0,i1,i2,i3;
  Object__String e;

  i0 = (OOC_INT32)s;
  i1 = (OOC_INT32)prefix;
  i2 = *(OOC_INT32*)(_check_pointer(i0, 33105));
  i3 = *(OOC_INT32*)(_check_pointer(i1, 33122));
  i2 = i2>=i3;
  if (i2) goto l3;
  return 0u;
  goto l4;
l3:
  i2 = *(OOC_INT32*)(_check_pointer(i1, 33168));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33148)))), Object__StringDesc_Substring)),Object__StringDesc_Substring)((Object__String)i0, 0, i2);
  e = (Object__String)i0;
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33192)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i0, (Object__Object)i1);
  return i0;
l4:
  _failed_function(32790); return 0;
  ;
}

Object__String Object__StringDesc_ToUppercaseLatin1(Object__String s) {

  _failed_function(33300); return 0;
  ;
}

Object__String8 Object__String8Desc_ToUppercaseLatin1(Object__String8 s) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_INT32 i;

  i0 = (OOC_INT32)s;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33588))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33588))+4);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 33593)), 0);
  i0 = *(OOC_INT32*)(_check_pointer(i0, 33600));
  i0 = (OOC_INT32)Object__NewLatin1Region((void*)(_check_pointer(i2, 33593)), i1, 0, i0);
  s = (Object__String8)i0;
  i = 0;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 33629));
  i2 = 0<i1;
  if (!i2) goto l8;
  i2=0;
l3_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33649))+4);
  i3 = _check_pointer(i3, 33654);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33666))+4);
  i5 = _check_pointer(i5, 33671);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = *(OOC_UINT8*)(i5+(_check_index(i2, i6, OOC_UINT32, 33671)));
  *(OOC_UINT8*)(i3+(_check_index(i2, i4, OOC_UINT32, 33654))) = (_cap(i5));
  i2 = i2+1;
  i = i2;
  i3 = i2<i1;
  if (i3) goto l3_loop;
l8:
  return (Object__String8)i0;
  ;
}

Object__String16 Object__String16Desc_ToUppercaseLatin1(Object__String16 s) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_INT32 i;

  i0 = (OOC_INT32)s;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33837))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33837))+4);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 33842)), 0);
  i0 = *(OOC_INT32*)(_check_pointer(i0, 33849));
  i0 = (OOC_INT32)Object__NewUTF16Region((void*)(_check_pointer(i2, 33842)), i1, 0, i0);
  s = (Object__String16)i0;
  i = 0;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 33878));
  i2 = 0<i1;
  if (!i2) goto l8;
  i2=0;
l3_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33898))+4);
  i3 = _check_pointer(i3, 33903);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33915))+4);
  i5 = _check_pointer(i5, 33920);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = *(OOC_UINT16*)(i5+(_check_index(i2, i6, OOC_UINT32, 33920))*2);
  *(OOC_UINT16*)(i3+(_check_index(i2, i4, OOC_UINT32, 33903))*2) = (_cap(i5));
  i2 = i2+1;
  i = i2;
  i3 = i2<i1;
  if (i3) goto l3_loop;
l8:
  return (Object__String16)i0;
  ;
}

void OOC_Object_init(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)Object__NewLatin1("", 1);
  Object__emptyString = (Object__String)i0;
  return;
  ;
}

void OOC_Object_destroy(void) {
}

/* --- */
