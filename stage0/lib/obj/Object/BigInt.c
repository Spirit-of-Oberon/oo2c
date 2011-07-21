#include <Object/BigInt.d>
#include <__oo2c.h>
#include <setjmp.h>

static Object_BigInt__BigInt Object_BigInt__NewInstance(OOC_INT32 size) {
  register OOC_INT32 i0,i1;
  Object_BigInt__BigInt big;

  i0 = (OOC_INT32)RT0__NewObject(_td_Object_BigInt__BigInt.baseTypes[0]);
  big = (Object_BigInt__BigInt)i0;
  i1 = size;
  *(OOC_INT32*)(_check_pointer(i0, 2280)) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 2306))+4) = ((OOC_INT32)RT0__NewObject(_td_Object_BigInt__DigitArray.baseTypes[0], (_abs(i1))));
  return (Object_BigInt__BigInt)i0;
  ;
}

static void Object_BigInt__Normalize(Object_BigInt__BigInt big) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT32 j;
  OOC_INT32 i;

  i0 = (OOC_INT32)big;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 2446));
  i1 = _abs(i1);
  j = i1;
  i = i1;
  i2 = i1!=0;
  if (i2) goto l3;
  i2=0u;
  goto l5;
l3:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2490))+4);
  i2 = _check_pointer(i2, 2496);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = *(OOC_INT16*)(i2+(_check_index((i1-1), i3, OOC_UINT32, 2496))*2);
  i2 = i2==0;
  
l5:
  if (i2) goto l7;
  i2=i1;
  goto l17;
l7:
  i2=i1;
l8_loop:
  i2 = i2-1;
  i = i2;
  i3 = i2!=0;
  if (i3) goto l11;
  i3=0u;
  goto l13;
l11:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2490))+4);
  i3 = _check_pointer(i3, 2496);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = *(OOC_INT16*)(i3+(_check_index((i2-1), i4, OOC_UINT32, 2496))*2);
  i3 = i3==0;
  
l13:
  if (i3) goto l8_loop;
l17:
  i1 = i2!=i1;
  if (!i1) goto l24;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 2567));
  i1 = i1<0;
  if (i1) goto l22;
  i1=i2;
  goto l23;
l22:
  i1 = -i2;
  i = i1;
  
l23:
  *(OOC_INT32*)(_check_pointer(i0, 2620)) = i1;
l24:
  return;
  ;
}

static Object_BigInt__BigInt Object_BigInt__AddAbs(Object_BigInt__BigInt a, Object_BigInt__BigInt b) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10;
  Object_BigInt__BigInt z;
  OOC_INT32 sizeA;
  OOC_INT32 sizeB;
  OOC_INT32 carry;
  OOC_INT32 i;

  i0 = (OOC_INT32)a;
  i1 = (OOC_INT32)b;
  i2 = *(OOC_INT32*)(_check_pointer(i0, 3200));
  i3 = *(OOC_INT32*)(_check_pointer(i1, 3214));
  i2 = (_abs(i2))<(_abs(i3));
  if (!i2) goto l4;
  z = (Object_BigInt__BigInt)i0;
  a = (Object_BigInt__BigInt)i1;
  b = (Object_BigInt__BigInt)i0;
  {register OOC_INT32 h0=i0;i0=i1;i1=h0;}
l4:
  i2 = *(OOC_INT32*)(_check_pointer(i0, 3284));
  i2 = _abs(i2);
  sizeA = i2;
  i3 = *(OOC_INT32*)(_check_pointer(i1, 3306));
  i3 = _abs(i3);
  sizeB = i3;
  i4 = (OOC_INT32)Object_BigInt__NewInstance((i2+1));
  z = (Object_BigInt__BigInt)i4;
  carry = 0;
  i = 0;
  i5 = 0!=i3;
  if (i5) goto l7;
  i1=0;i3=0;
  goto l13;
l7:
  i5=0;i6=0;
l8_loop:
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3417))+4);
  i7 = _check_pointer(i7, 3423);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3428))+4);
  i9 = _check_pointer(i9, 3434);
  i10 = OOC_ARRAY_LENGTH(i9, 0);
  i7 = *(OOC_INT16*)(i7+(_check_index(i6, i8, OOC_UINT32, 3423))*2);
  i8 = *(OOC_INT16*)(i9+(_check_index(i6, i10, OOC_UINT32, 3434))*2);
  i5 = i5+(i7+i8);
  carry = i5;
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 3447))+4);
  i7 = _check_pointer(i7, 3453);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  *(OOC_INT16*)(i7+(_check_index(i6, i8, OOC_UINT32, 3453))*2) = (_mod(i5,32768));
  i5 = i5>>15;
  carry = i5;
  i6 = i6+1;
  i = i6;
  i7 = i6!=i3;
  if (i7) goto l8_loop;
l12:
  i1=i6;i3=i5;
l13:
  i5 = i1!=i2;
  if (i5) goto l16;
  i0=i1;i1=i3;
  goto l22;
l16:
  {register OOC_INT32 h0=i1;i1=i3;i3=h0;}
l17_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3581))+4);
  i5 = _check_pointer(i5, 3587);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = *(OOC_INT16*)(i5+(_check_index(i3, i6, OOC_UINT32, 3587))*2);
  i1 = i1+i5;
  carry = i1;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 3600))+4);
  i5 = _check_pointer(i5, 3606);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  *(OOC_INT16*)(i5+(_check_index(i3, i6, OOC_UINT32, 3606))*2) = (_mod(i1,32768));
  i1 = i1>>15;
  carry = i1;
  i3 = i3+1;
  i = i3;
  i5 = i3!=i2;
  if (i5) goto l17_loop;
l21:
  i0=i3;
l22:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 3695))+4);
  i2 = _check_pointer(i2, 3701);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  *(OOC_INT16*)(i2+(_check_index(i0, i3, OOC_UINT32, 3701))*2) = i1;
  Object_BigInt__Normalize((Object_BigInt__BigInt)i4);
  return (Object_BigInt__BigInt)i4;
  ;
}

Object_BigInt__BigInt Object_BigInt__NewInt(OOC_INT32 _int) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 sign;
  Object_BigInt__BigInt big;
  OOC_INT32 size;

  i0 = _int;
  i1 = i0==0;
  if (i1) goto l23;
  sign = 1;
  i1 = i0<0;
  if (i1) goto l5;
  i1=1;
  goto l14;
l5:
  i1 = i0==(-2147483647-1);
  if (i1) goto l8;
  i0 = -i0;
  _int = i0;
  sign = (-1);
  i1=(-1);
  goto l14;
l8:
  i1 = (OOC_INT32)Object_BigInt__NewInt((i0+1));
  big = (Object_BigInt__BigInt)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4148))+4);
  i2 = _check_pointer(i2, 4154);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = *(OOC_INT16*)(i2+(_check_index(0, i3, OOC_UINT8, 4154))*2);
  i2 = i2==32767;
  if (i2) goto l11;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4277))+4);
  i2 = _check_pointer(i2, 4283);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4277))+4);
  i4 = _check_pointer(i4, 4283);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = *(OOC_INT16*)(i4+(_check_index(0, i5, OOC_UINT8, 4283))*2);
  *(OOC_INT16*)(i2+(_check_index(0, i3, OOC_UINT8, 4283))*2) = (i4+1);
  
  goto l12;
l11:
  i2 = (OOC_INT32)Object_BigInt__one;
  i1 = (OOC_INT32)Object_BigInt__AddAbs((Object_BigInt__BigInt)i1, (Object_BigInt__BigInt)i2);
  big = (Object_BigInt__BigInt)i1;
  i2 = *(OOC_INT32*)(_check_pointer(i1, 4236));
  *(OOC_INT32*)(_check_pointer(i1, 4223)) = (-i2);
  
l12:
  return (Object_BigInt__BigInt)i1;
  i1=1;
l14:
  i2 = (OOC_INT32)Object_BigInt__NewInstance(3);
  big = (Object_BigInt__BigInt)i2;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 4567))+4);
  i3 = _check_pointer(i3, 4573);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT16*)(i3+(_check_index(0, i4, OOC_UINT8, 4573))*2) = (_mod(i0,32768));
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 4612))+4);
  i3 = _check_pointer(i3, 4618);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT16*)(i3+(_check_index(1, i4, OOC_UINT8, 4618))*2) = (_mod((i0>>15),32768));
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 4668))+4);
  i3 = _check_pointer(i3, 4674);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT16*)(i3+(_check_index(2, i4, OOC_UINT8, 4674))*2) = (i0>>30);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 4724))+4);
  i0 = _check_pointer(i0, 4730);
  i3 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = *(OOC_INT16*)(i0+(_check_index(2, i3, OOC_UINT8, 4730))*2);
  i0 = i0!=0;
  if (i0) goto l21;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 4783))+4);
  i0 = _check_pointer(i0, 4789);
  i3 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = *(OOC_INT16*)(i0+(_check_index(1, i3, OOC_UINT8, 4789))*2);
  i0 = i0!=0;
  if (i0) goto l19;
  size = 1;
  i0=1;
  goto l22;
l19:
  size = 2;
  i0=2;
  goto l22;
l21:
  size = 3;
  i0=3;
l22:
  *(OOC_INT32*)(_check_pointer(i2, 5176)) = (i0*i1);
  return (Object_BigInt__BigInt)i2;
  goto l24;
l23:
  i0 = (OOC_INT32)Object_BigInt__zero;
  return (Object_BigInt__BigInt)i0;
l24:
  _failed_function(3779); return 0;
  ;
}

Object_BigInt__BigInt Object_BigInt__BigIntDesc_Copy(Object_BigInt__BigInt a) {
  register OOC_INT32 i0,i1,i2;
  OOC_INT32 size;
  Object_BigInt__BigInt z;

  i0 = (OOC_INT32)a;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 5342));
  i1 = _abs(i1);
  size = i1;
  i2 = *(OOC_INT32*)(_check_pointer(i0, 5372));
  i2 = (OOC_INT32)Object_BigInt__NewInstance(i2);
  z = (Object_BigInt__BigInt)i2;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5398))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 5414))+4);
  _move_block((_check_pointer(i0, 5404)),(_check_pointer(i2, 5420)),(i1*2));
  i0 = (OOC_INT32)z;
  return (Object_BigInt__BigInt)i0;
  ;
}

OOC_INT32 Object_BigInt__BigIntDesc_HashCode(Object_BigInt__BigInt a) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 len;
  OOC_INT32 x;
  OOC_INT32 p;

  i0 = (OOC_INT32)a;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 5588));
  i1 = _abs(i1);
  len = i1;
  i2 = i1==0;
  if (i2) goto l12;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5659))+4);
  i2 = _check_pointer(i2, 5665);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = *(OOC_INT16*)(i2+(_check_index(0, i3, OOC_UINT8, 5665))*2);
  i2 = _ash(i2,7);
  x = i2;
  p = 0;
  i3 = 0!=i1;
  if (i3) goto l5;
  i0=i2;
  goto l11;
l5:
  i3=0;
l6_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5840))+4);
  i4 = _check_pointer(i4, 5846);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = *(OOC_INT16*)(i4+(_check_index(i3, i5, OOC_UINT32, 5846))*2);
  i2 = _type_cast_fast(OOC_INT32, OOC_UINT32, ((_type_cast_fast(OOC_UINT32, OOC_INT32, (1000003*i2)))^(_type_cast_fast(OOC_UINT32, OOC_INT16, i4))));
  x = i2;
  i3 = i3+1;
  p = i3;
  i4 = i3!=i1;
  if (i4) goto l6_loop;
l10:
  i0=i2;
l11:
  return (_type_cast_fast(OOC_INT32, OOC_UINT32, ((_type_cast_fast(OOC_UINT32, OOC_INT32, i0))^(_type_cast_fast(OOC_UINT32, OOC_INT32, i1)))));
  goto l13;
l12:
  return 0;
l13:
  _failed_function(5491); return 0;
  ;
}

OOC_CHAR8 Object_BigInt__BigIntDesc_Equals(Object_BigInt__BigInt a, Object__Object b) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  OOC_INT32 i;

  i0 = (OOC_INT32)b;
  i1 = i0==(OOC_INT32)0;
  if (!i1) goto l3;
  return 0u;
l3:
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6149)))), &_td_Object_BigInt__BigIntDesc);
  if (i1) goto l6;
  return 0u;
  goto l22;
l6:
  i1 = (OOC_INT32)a;
  i2 = *(OOC_INT32*)(_check_pointer(i1, 6172));
  i3 = *(OOC_INT32*)(_check_pointer(i0, 6181));
  i2 = i2!=i3;
  if (i2) goto l20;
  i2 = *(OOC_INT32*)(_check_pointer(i1, 6253));
  i = 0;
  i2 = _abs(i2);
  i3 = 0<i2;
  if (!i3) goto l19;
  i3=0;
l11_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6280))+4);
  i4 = _check_pointer(i4, 6286);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6293))+4);
  i6 = _check_pointer(i6, 6299);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i4 = *(OOC_INT16*)(i4+(_check_index(i3, i5, OOC_UINT32, 6286))*2);
  i5 = *(OOC_INT16*)(i6+(_check_index(i3, i7, OOC_UINT32, 6299))*2);
  i4 = i4!=i5;
  if (!i4) goto l14;
  return 0u;
l14:
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l11_loop;
l19:
  return 1u;
  goto l22;
l20:
  return 0u;
l22:
  _failed_function(6016); return 0;
  ;
}

OOC_CHAR8 Object_BigInt__BigIntDesc_IsZero(Object_BigInt__BigInt a) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)a;
  i0 = *(OOC_INT32*)(_check_pointer(i0, 6511));
  return (i0==0);
  ;
}

OOC_CHAR8 Object_BigInt__BigIntDesc_NonZero(Object_BigInt__BigInt a) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)a;
  i0 = *(OOC_INT32*)(_check_pointer(i0, 6602));
  return (i0!=0);
  ;
}

OOC_INT32 Object_BigInt__BigIntDesc_ToLongInt(Object_BigInt__BigInt a) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT32 _int;
  OOC_INT32 i;

  _int = 0;
  i0 = (OOC_INT32)a;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 6742));
  i1 = (_abs(i1))-1;
  i = i1;
  i2 = i1>=0;
  if (i2) goto l3;
  i1=0;
  goto l9;
l3:
  i2=i1;i1=0;
l4_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6788))+4);
  i3 = _check_pointer(i3, 6794);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = *(OOC_INT16*)(i3+(_check_index(i2, i4, OOC_UINT32, 6794))*2);
  i1 = (i1*32768)+i3;
  _int = i1;
  i2 = i2+(-1);
  i = i2;
  i3 = i2>=0;
  if (i3) goto l4_loop;
l9:
  i0 = *(OOC_INT32*)(_check_pointer(i0, 6817));
  i0 = i0<0;
  if (i0) goto l12;
  return i1;
  goto l13;
l12:
  return (-i1);
l13:
  _failed_function(6652); return 0;
  ;
}

OOC_INT32 Object_BigInt__BigIntDesc_Sign(Object_BigInt__BigInt a) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)a;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 6963));
  i1 = i1>0;
  if (i1) goto l7;
  i0 = *(OOC_INT32*)(_check_pointer(i0, 7007));
  i0 = i0<0;
  if (i0) goto l5;
  return 0;
  goto l8;
l5:
  return (-1);
  goto l8;
l7:
  return 1;
l8:
  _failed_function(6928); return 0;
  ;
}

OOC_INT32 Object_BigInt__BigIntDesc_Cmp(Object_BigInt__BigInt a, Object__Object b) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  OOC_INT32 i;
  OOC_INT32 res;

  i0 = (OOC_INT32)b;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7188)))), &_td_Object_BigInt__BigIntDesc);
  if (i1) goto l3;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7182)))), 7182);
  goto l33;
l3:
  i1 = (OOC_INT32)a;
  i2 = *(OOC_INT32*)(_check_pointer(i1, 7211));
  i3 = *(OOC_INT32*)(_check_pointer(i0, 7220));
  i2 = i2<i3;
  if (i2) goto l31;
  i2 = *(OOC_INT32*)(_check_pointer(i0, 7274));
  i3 = *(OOC_INT32*)(_check_pointer(i1, 7265));
  i2 = i3>i2;
  if (i2) goto l29;
  i2 = *(OOC_INT32*)(_check_pointer(i1, 7333));
  i2 = _abs(i2);
  
l8_loop:
  i2 = i2-1;
  i = i2;
  i3 = i2<0;
  if (i3) goto l11;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 7401))+4);
  i4 = _check_pointer(i4, 7407);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7414))+4);
  i6 = _check_pointer(i6, 7420);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i4 = *(OOC_INT16*)(i4+(_check_index(i2, i5, OOC_UINT32, 7407))*2);
  i5 = *(OOC_INT16*)(i6+(_check_index(i2, i7, OOC_UINT32, 7420))*2);
  i4 = i4!=i5;
  
  goto l13;
l11:
  i4=1u;
l13:
  if (!i4) goto l8_loop;
l17:
  if (i3) goto l23;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 7486))+4);
  i3 = _check_pointer(i3, 7492);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7499))+4);
  i0 = _check_pointer(i0, 7505);
  i5 = OOC_ARRAY_LENGTH(i0, 0);
  i3 = *(OOC_INT16*)(i3+(_check_index(i2, i4, OOC_UINT32, 7492))*2);
  i0 = *(OOC_INT16*)(i0+(_check_index(i2, i5, OOC_UINT32, 7505))*2);
  i0 = i3<i0;
  if (i0) goto l21;
  res = 1;
  
  goto l24;
l21:
  res = (-1);
  
  goto l24;
l23:
  return 0;
l24:
  i0 = *(OOC_INT32*)(_check_pointer(i1, 7595));
  i0 = i0<0;
  if (i0) goto l27;
  i0 = res;
  return i0;
  goto l33;
l27:
  i0 = res;
  return (-i0);
  goto l33;
l29:
  return 1;
  goto l33;
l31:
  return (-1);
l33:
  _failed_function(7109); return 0;
  ;
}

Object_BigInt__BigInt Object_BigInt__BigIntDesc_Abs(Object_BigInt__BigInt a) {
  register OOC_INT32 i0,i1,i2;
  OOC_INT32 size;
  Object_BigInt__BigInt z;

  i0 = (OOC_INT32)a;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 7809));
  i1 = i1>=0;
  if (i1) goto l3;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 7867));
  i1 = -i1;
  size = i1;
  i2 = (OOC_INT32)Object_BigInt__NewInstance(i1);
  z = (Object_BigInt__BigInt)i2;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7924))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7959))+4);
  _move_block((_check_pointer(i0, 7930)),(_check_pointer(i2, 7965)),(i1*2));
  i0 = (OOC_INT32)z;
  return (Object_BigInt__BigInt)i0;
  goto l4;
l3:
  return (Object_BigInt__BigInt)i0;
l4:
  _failed_function(7736); return 0;
  ;
}

Object_BigInt__BigInt Object_BigInt__BigIntDesc_Neg(Object_BigInt__BigInt a) {
  register OOC_INT32 i0,i1;
  Object_BigInt__BigInt z;

  i0 = (OOC_INT32)a;
  i0 = (OOC_INT32)Object_BigInt__BigIntDesc_Copy((Object_BigInt__BigInt)i0);
  z = (Object_BigInt__BigInt)i0;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 8145));
  *(OOC_INT32*)(_check_pointer(i0, 8134)) = (-i1);
  return (Object_BigInt__BigInt)i0;
  ;
}

static Object_BigInt__BigInt Object_BigInt__SubAbs(Object_BigInt__BigInt a, Object_BigInt__BigInt b) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11;
  OOC_INT32 sign;
  Object_BigInt__BigInt z;
  OOC_INT32 i;
  OOC_INT32 sizeA;
  OOC_INT32 sizeB;
  OOC_INT32 borrow;

  sign = 1;
  i0 = (OOC_INT32)a;
  i1 = (OOC_INT32)b;
  i2 = *(OOC_INT32*)(_check_pointer(i0, 8372));
  i3 = *(OOC_INT32*)(_check_pointer(i1, 8386));
  i2 = (_abs(i2))<(_abs(i3));
  if (i2) goto l32;
  i2 = *(OOC_INT32*)(_check_pointer(i1, 8477));
  i3 = *(OOC_INT32*)(_check_pointer(i0, 8463));
  i2 = (_abs(i3))==(_abs(i2));
  if (i2) goto l5;
  i2=1;
  goto l33;
l5:
  i2 = *(OOC_INT32*)(_check_pointer(i0, 8558));
  i2 = (_abs(i2))-1;
  i = i2;
  i3 = i2>=0;
  if (i3) goto l8;
  i3=0u;
  goto l10;
l8:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8593))+4);
  i3 = _check_pointer(i3, 8599);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8606))+4);
  i5 = _check_pointer(i5, 8612);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i3 = *(OOC_INT16*)(i3+(_check_index(i2, i4, OOC_UINT32, 8599))*2);
  i4 = *(OOC_INT16*)(i5+(_check_index(i2, i6, OOC_UINT32, 8612))*2);
  i3 = i3==i4;
  
l10:
  if (!i3) goto l22;
l13_loop:
  i2 = i2-1;
  i = i2;
  i3 = i2>=0;
  if (i3) goto l16;
  i3=0u;
  goto l18;
l16:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8593))+4);
  i3 = _check_pointer(i3, 8599);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8606))+4);
  i5 = _check_pointer(i5, 8612);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i3 = *(OOC_INT16*)(i3+(_check_index(i2, i4, OOC_UINT32, 8599))*2);
  i4 = *(OOC_INT16*)(i5+(_check_index(i2, i6, OOC_UINT32, 8612))*2);
  i3 = i3==i4;
  
l18:
  if (i3) goto l13_loop;
l22:
  i3 = i2<0;
  if (i3) goto l29;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8704))+4);
  i3 = _check_pointer(i3, 8710);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8717))+4);
  i5 = _check_pointer(i5, 8723);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i3 = *(OOC_INT16*)(i3+(_check_index(i2, i4, OOC_UINT32, 8710))*2);
  i2 = *(OOC_INT16*)(i5+(_check_index(i2, i6, OOC_UINT32, 8723))*2);
  i2 = i3<i2;
  if (i2) goto l27;
  i2=1;
  goto l33;
l27:
  z = (Object_BigInt__BigInt)i0;
  a = (Object_BigInt__BigInt)i1;
  b = (Object_BigInt__BigInt)i0;
  sign = (-1);
  {register OOC_INT32 h0=i0;i0=i1;i1=h0;}i2=(-1);
  goto l33;
l29:
  i2 = (OOC_INT32)Object_BigInt__zero;
  return (Object_BigInt__BigInt)i2;
  i2=1;
  goto l33;
l32:
  z = (Object_BigInt__BigInt)i0;
  a = (Object_BigInt__BigInt)i1;
  b = (Object_BigInt__BigInt)i0;
  sign = (-1);
  {register OOC_INT32 h0=i0;i0=i1;i1=h0;}i2=(-1);
l33:
  i3 = *(OOC_INT32*)(_check_pointer(i0, 8823));
  i3 = _abs(i3);
  sizeA = i3;
  i4 = *(OOC_INT32*)(_check_pointer(i1, 8845));
  i4 = _abs(i4);
  sizeB = i4;
  i5 = (OOC_INT32)Object_BigInt__NewInstance(i3);
  z = (Object_BigInt__BigInt)i5;
  borrow = 0;
  i = 0;
  i6 = 0!=i4;
  if (i6) goto l36;
  i1=0;i4=0;
  goto l42;
l36:
  i6=0;i7=0;
l37_loop:
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8958))+4);
  i8 = _check_pointer(i8, 8964);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i10 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8969))+4);
  i10 = _check_pointer(i10, 8975);
  i11 = OOC_ARRAY_LENGTH(i10, 0);
  i8 = *(OOC_INT16*)(i8+(_check_index(i6, i9, OOC_UINT32, 8964))*2);
  i9 = *(OOC_INT16*)(i10+(_check_index(i6, i11, OOC_UINT32, 8975))*2);
  i7 = (i8-i9)-i7;
  borrow = i7;
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 8994))+4);
  i8 = _check_pointer(i8, 9000);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  *(OOC_INT16*)(i8+(_check_index(i6, i9, OOC_UINT32, 9000))*2) = (_mod(i7,32768));
  i7 = _mod((i7>>15),2);
  borrow = i7;
  i6 = i6+1;
  i = i6;
  i8 = i6!=i4;
  if (i8) goto l37_loop;
l41:
  i1=i6;i4=i7;
l42:
  i6 = i1!=i3;
  if (i6) goto l46_loop;
  i0=i4;
  goto l51;
l46_loop:
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9165))+4);
  i6 = _check_pointer(i6, 9171);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = *(OOC_INT16*)(i6+(_check_index(i1, i7, OOC_UINT32, 9171))*2);
  i4 = i6-i4;
  borrow = i4;
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 9190))+4);
  i6 = _check_pointer(i6, 9196);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  *(OOC_INT16*)(i6+(_check_index(i1, i7, OOC_UINT32, 9196))*2) = (_mod(i4,32768));
  i4 = _mod((i4>>15),2);
  borrow = i4;
  i1 = i1+1;
  i = i1;
  i6 = i1!=i3;
  if (i6) goto l46_loop;
l50:
  i0=i4;
l51:
  _assert((i0==0), 127, 9295);
  i0 = i2<0;
  if (!i0) goto l54;
  i0 = *(OOC_INT32*)(_check_pointer(i5, 9356));
  *(OOC_INT32*)(_check_pointer(i5, 9345)) = (-i0);
l54:
  Object_BigInt__Normalize((Object_BigInt__BigInt)i5);
  return (Object_BigInt__BigInt)i5;
  ;
}

static Object_BigInt__BigInt Object_BigInt__MulAbs(Object_BigInt__BigInt a, Object_BigInt__BigInt b) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11,i12,i13,i14;
  OOC_INT32 sizeA;
  OOC_INT32 sizeB;
  Object_BigInt__BigInt z;
  OOC_INT32 i;
  OOC_INT32 f;
  OOC_INT32 carry;
  OOC_INT32 j;

  i0 = (OOC_INT32)a;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 9655));
  i1 = _abs(i1);
  sizeA = i1;
  i2 = (OOC_INT32)b;
  i3 = *(OOC_INT32*)(_check_pointer(i2, 9677));
  i3 = _abs(i3);
  sizeB = i3;
  i4 = i1+i3;
  i5 = (OOC_INT32)Object_BigInt__NewInstance(i4);
  z = (Object_BigInt__BigInt)i5;
  i = 0;
  i6 = 0<i4;
  if (!i6) goto l8;
  i6=0;
l3_loop:
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 9767))+4);
  i7 = _check_pointer(i7, 9773);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  *(OOC_INT16*)(i7+(_check_index(i6, i8, OOC_UINT32, 9773))*2) = 0;
  i6 = i6+1;
  i = i6;
  i7 = i6<i4;
  if (i7) goto l3_loop;
l8:
  i = 0;
  i4 = 0!=i1;
  if (!i4) goto l33;
  i4 = 0!=i3;
  i6=0;
l11_loop:
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9846))+4);
  i7 = _check_pointer(i7, 9852);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = *(OOC_INT16*)(i7+(_check_index(i6, i8, OOC_UINT32, 9852))*2);
  f = i7;
  carry = 0;
  j = 0;
  if (i4) goto l14;
  i7=0;i8=0;
  goto l20;
l14:
  i8=0;i9=0;
l15_loop:
  i10 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 9937))+4);
  i10 = _check_pointer(i10, 9943);
  i11 = i6+i9;
  i12 = OOC_ARRAY_LENGTH(i10, 0);
  i13 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 9950))+4);
  i13 = _check_pointer(i13, 9956);
  i14 = OOC_ARRAY_LENGTH(i13, 0);
  i13 = *(OOC_INT16*)(i13+(_check_index(i9, i14, OOC_UINT32, 9956))*2);
  i10 = *(OOC_INT16*)(i10+(_check_index(i11, i12, OOC_UINT32, 9943))*2);
  i8 = i8+(i10+(i13*i7));
  carry = i8;
  _assert((i8>=0), 127, 9972);
  i10 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 10001))+4);
  i10 = _check_pointer(i10, 10007);
  i12 = OOC_ARRAY_LENGTH(i10, 0);
  *(OOC_INT16*)(i10+(_check_index(i11, i12, OOC_UINT32, 10007))*2) = (_mod(i8,32768));
  i8 = i8>>15;
  carry = i8;
  i9 = i9+1;
  j = i9;
  i10 = i9!=i3;
  if (i10) goto l15_loop;
l19:
  i7=i8;i8=i9;
l20:
  i9 = i7!=0;
  if (!i9) goto l28;
l23_loop:
  i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 10146))+4);
  i9 = _check_pointer(i9, 10152);
  i10 = i6+i8;
  i11 = OOC_ARRAY_LENGTH(i9, 0);
  i9 = *(OOC_INT16*)(i9+(_check_index(i10, i11, OOC_UINT32, 10152))*2);
  i7 = i7+i9;
  carry = i7;
  _assert((i7>=0), 127, 10168);
  i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 10197))+4);
  i9 = _check_pointer(i9, 10203);
  i11 = OOC_ARRAY_LENGTH(i9, 0);
  *(OOC_INT16*)(i9+(_check_index(i10, i11, OOC_UINT32, 10203))*2) = (_mod(i7,32768));
  i7 = i7>>15;
  carry = i7;
  i8 = i8+1;
  j = i8;
  i9 = i7!=0;
  if (i9) goto l23_loop;
l28:
  i6 = i6+1;
  i = i6;
  i7 = i6!=i1;
  if (i7) goto l11_loop;
l33:
  Object_BigInt__Normalize((Object_BigInt__BigInt)i5);
  return (Object_BigInt__BigInt)i5;
  ;
}

Object_BigInt__BigInt Object_BigInt__BigIntDesc_Add(Object_BigInt__BigInt a, Object_BigInt__BigInt b) {
  register OOC_INT32 i0,i1,i2;
  Object_BigInt__BigInt z;

  i0 = (OOC_INT32)a;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 10451));
  i1 = i1<0;
  if (i1) goto l7;
  i1 = (OOC_INT32)b;
  i2 = *(OOC_INT32*)(_check_pointer(i1, 10637));
  i2 = i2<0;
  if (i2) goto l5;
  i0 = (OOC_INT32)Object_BigInt__AddAbs((Object_BigInt__BigInt)i0, (Object_BigInt__BigInt)i1);
  return (Object_BigInt__BigInt)i0;
  goto l12;
l5:
  i0 = (OOC_INT32)Object_BigInt__SubAbs((Object_BigInt__BigInt)i0, (Object_BigInt__BigInt)i1);
  return (Object_BigInt__BigInt)i0;
  goto l12;
l7:
  i1 = (OOC_INT32)b;
  i2 = *(OOC_INT32*)(_check_pointer(i1, 10478));
  i2 = i2<0;
  if (i2) goto l10;
  i0 = (OOC_INT32)Object_BigInt__SubAbs((Object_BigInt__BigInt)i1, (Object_BigInt__BigInt)i0);
  return (Object_BigInt__BigInt)i0;
  goto l12;
l10:
  i0 = (OOC_INT32)Object_BigInt__AddAbs((Object_BigInt__BigInt)i0, (Object_BigInt__BigInt)i1);
  z = (Object_BigInt__BigInt)i0;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 10541));
  *(OOC_INT32*)(_check_pointer(i0, 10530)) = (-i1);
  return (Object_BigInt__BigInt)i0;
l12:
  _failed_function(10387); return 0;
  ;
}

Object_BigInt__BigInt Object_BigInt__BigIntDesc_Sub(Object_BigInt__BigInt a, Object_BigInt__BigInt b) {
  register OOC_INT32 i0,i1,i2;
  Object_BigInt__BigInt z;

  i0 = (OOC_INT32)a;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 10840));
  i1 = i1<0;
  if (i1) goto l7;
  i1 = (OOC_INT32)b;
  i2 = *(OOC_INT32*)(_check_pointer(i1, 11020));
  i2 = i2<0;
  if (i2) goto l5;
  i0 = (OOC_INT32)Object_BigInt__SubAbs((Object_BigInt__BigInt)i0, (Object_BigInt__BigInt)i1);
  return (Object_BigInt__BigInt)i0;
  goto l12;
l5:
  i0 = (OOC_INT32)Object_BigInt__AddAbs((Object_BigInt__BigInt)i0, (Object_BigInt__BigInt)i1);
  return (Object_BigInt__BigInt)i0;
  goto l12;
l7:
  i1 = (OOC_INT32)b;
  i2 = *(OOC_INT32*)(_check_pointer(i1, 10867));
  i2 = i2<0;
  if (i2) goto l10;
  i0 = (OOC_INT32)Object_BigInt__AddAbs((Object_BigInt__BigInt)i0, (Object_BigInt__BigInt)i1);
  z = (Object_BigInt__BigInt)i0;
  
  goto l11;
l10:
  i0 = (OOC_INT32)Object_BigInt__SubAbs((Object_BigInt__BigInt)i0, (Object_BigInt__BigInt)i1);
  z = (Object_BigInt__BigInt)i0;
  
l11:
  i1 = *(OOC_INT32*)(_check_pointer(i0, 10977));
  *(OOC_INT32*)(_check_pointer(i0, 10966)) = (-i1);
  return (Object_BigInt__BigInt)i0;
l12:
  _failed_function(10776); return 0;
  ;
}

Object_BigInt__BigInt Object_BigInt__BigIntDesc_Mul(Object_BigInt__BigInt a, Object_BigInt__BigInt b) {
  register OOC_INT32 i0,i1,i2;
  Object_BigInt__BigInt z;

  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)a;
  i2 = (OOC_INT32)Object_BigInt__MulAbs((Object_BigInt__BigInt)i1, (Object_BigInt__BigInt)i0);
  z = (Object_BigInt__BigInt)i2;
  i1 = *(OOC_INT32*)(_check_pointer(i1, 11247));
  i0 = *(OOC_INT32*)(_check_pointer(i0, 11262));
  i0 = (i1<0)!=(i0<0);
  if (!i0) goto l4;
  i0 = *(OOC_INT32*)(_check_pointer(i2, 11297));
  *(OOC_INT32*)(_check_pointer(i2, 11286)) = (-i0);
l4:
  return (Object_BigInt__BigInt)i2;
  ;
}

static OOC_INT16 Object_BigInt__InplaceDivRem1(OOC_INT16 pout[], OOC_LEN pout_0d, OOC_INT16 pin[], OOC_LEN pin_0d, OOC_INT32 size, OOC_INT16 n) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = n;
  i1 = i0>0;
  if (i1) goto l3;
  i1=0u;
  goto l4;
l3:
  i1 = i0<32768;
  
l4:
  _assert(i1, 127, 11923);
  i1 = size;
  i1 = i1>0;
  if (i1) goto l7;
  i0=0;
  goto l13;
l7:
  i1=0;
l8_loop:
  i2 = size;
  i2 = i2-1;
  size = i2;
  i3 = *(OOC_INT16*)((OOC_INT32)pin+(_check_index(i2, pin_0d, OOC_UINT32, 12040))*2);
  i1 = (i1*32768)+i3;
  i3 = _div(i1,i0);
  *(OOC_INT16*)((OOC_INT32)pout+(_check_index(i2, pout_0d, OOC_UINT32, 12081))*2) = i3;
  i1 = i1-(i3*i0);
  i2 = i2>0;
  if (i2) goto l8_loop;
l12:
  i0=i1;
l13:
  return i0;
  ;
}

static Object_BigInt__BigInt Object_BigInt__DivRem1(Object_BigInt__BigInt a, OOC_INT16 n, OOC_INT16 *rem) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_INT32 size;
  Object_BigInt__BigInt z;

  i0 = n;
  i1 = i0>0;
  if (i1) goto l3;
  i1=0u;
  goto l4;
l3:
  i1 = i0<32768;
  
l4:
  _assert(i1, 127, 12474);
  i1 = (OOC_INT32)a;
  i2 = *(OOC_INT32*)(_check_pointer(i1, 12522));
  i2 = _abs(i2);
  size = i2;
  i3 = (OOC_INT32)Object_BigInt__NewInstance(i2);
  z = (Object_BigInt__BigInt)i3;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12595))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12595))+4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 12585))+4);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 12585))+4);
  i4 = OOC_ARRAY_LENGTH((_check_pointer(i4, 12601)), 0);
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 12591)), 0);
  i0 = Object_BigInt__InplaceDivRem1((void*)(_check_pointer(i6, 12591)), i5, (void*)(_check_pointer(i1, 12601)), i4, i2, i0);
  *rem = i0;
  Object_BigInt__Normalize((Object_BigInt__BigInt)i3);
  return (Object_BigInt__BigInt)i3;
  ;
}

static Object_BigInt__BigInt Object_BigInt__MulAdd1(Object_BigInt__BigInt a, OOC_INT16 n, OOC_INT16 add) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  OOC_INT32 sizeA;
  Object_BigInt__BigInt z;
  OOC_INT32 carry;
  OOC_INT32 i;

  i0 = (OOC_INT32)a;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 12869));
  i1 = _abs(i1);
  sizeA = i1;
  i2 = (OOC_INT32)Object_BigInt__NewInstance((i1+1));
  z = (Object_BigInt__BigInt)i2;
  i3 = add;
  carry = i3;
  i = 0;
  i4 = 0!=i1;
  if (i4) goto l3;
  i1=i3;i0=0;
  goto l9;
l3:
  i4 = n;
  i5=0;
l4_loop:
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12986))+4);
  i6 = _check_pointer(i6, 12992);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = *(OOC_INT16*)(i6+(_check_index(i5, i7, OOC_UINT32, 12992))*2);
  i3 = i3+(i6*i4);
  carry = i3;
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 13008))+4);
  i6 = _check_pointer(i6, 13014);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  *(OOC_INT16*)(i6+(_check_index(i5, i7, OOC_UINT32, 13014))*2) = (_mod(i3,32768));
  i3 = i3>>15;
  carry = i3;
  i5 = i5+1;
  i = i5;
  i6 = i5!=i1;
  if (i6) goto l4_loop;
l8:
  i0=i5;i1=i3;
l9:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 13103))+4);
  i3 = _check_pointer(i3, 13109);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT16*)(i3+(_check_index(i0, i4, OOC_UINT32, 13109))*2) = i1;
  Object_BigInt__Normalize((Object_BigInt__BigInt)i2);
  return (Object_BigInt__BigInt)i2;
  ;
}

static Object_BigInt__BigInt Object_BigInt__DivRemAbs(Object_BigInt__BigInt v1, Object_BigInt__BigInt _w1, Object_BigInt__BigInt *rem) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11,i12,i13,i14,i15,i16,i17,i18,i19,i20;
  OOC_INT32 sizeV;
  OOC_INT32 sizeW;
  OOC_INT16 d;
  Object_BigInt__BigInt v;
  Object_BigInt__BigInt w;
  Object_BigInt__BigInt a;
  OOC_INT32 j;
  OOC_INT32 k;
  OOC_INT16 vj;
  OOC_INT32 carry;
  OOC_INT32 q;
  OOC_INT32 i;
  OOC_INT32 z;
  OOC_INT16 zz;

  i0 = (OOC_INT32)v1;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 13445));
  i1 = _abs(i1);
  sizeV = i1;
  i2 = (OOC_INT32)_w1;
  i3 = *(OOC_INT32*)(_check_pointer(i2, 13468));
  i3 = _abs(i3);
  sizeW = i3;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 13508))+4);
  i4 = _check_pointer(i4, 13514);
  i5 = i3-1;
  i6 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = *(OOC_INT16*)(i4+(_check_index(i5, i6, OOC_UINT32, 13514))*2);
  i4 = _div(32768,(i4+1));
  d = i4;
  i0 = (OOC_INT32)Object_BigInt__MulAdd1((Object_BigInt__BigInt)i0, i4, 0);
  v = (Object_BigInt__BigInt)i0;
  i4 = d;
  i2 = (OOC_INT32)Object_BigInt__MulAdd1((Object_BigInt__BigInt)i2, i4, 0);
  w = (Object_BigInt__BigInt)i2;
  i1 = i1>=i3;
  if (i1) goto l3;
  i1=0u;
  goto l4;
l3:
  i1 = i3>1;
  
l4:
  _assert(i1, 127, 13595);
  i1 = *(OOC_INT32*)(_check_pointer(i2, 13659));
  _assert((i3==(_abs(i1))), 127, 13639);
  i1 = *(OOC_INT32*)(_check_pointer(i0, 13686));
  i1 = _abs(i1);
  sizeV = i1;
  i4 = (OOC_INT32)Object_BigInt__NewInstance(((i1-i3)+1));
  a = (Object_BigInt__BigInt)i4;
  j = i1;
  i6 = *(OOC_INT32*)(_check_pointer(i4, 13758));
  i6 = i6-1;
  k = i6;
  i7 = i6>=0;
  if (!i7) goto l70;
  i7 = i3-2;
  i8 = 0<i3;
  i9=i6;i6=i1;
l7_loop:
  i10 = i6>=i1;
  if (i10) goto l10;
  i10 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13859))+4);
  i10 = _check_pointer(i10, 13865);
  i11 = OOC_ARRAY_LENGTH(i10, 0);
  i10 = *(OOC_INT16*)(i10+(_check_index(i6, i11, OOC_UINT32, 13865))*2);
  vj = i10;
  
  goto l11;
l10:
  vj = 0;
  i10=0;
l11:
  carry = 0;
  i11 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 13916))+4);
  i11 = _check_pointer(i11, 13922);
  i12 = OOC_ARRAY_LENGTH(i11, 0);
  i11 = *(OOC_INT16*)(i11+(_check_index(i5, i12, OOC_UINT32, 13922))*2);
  i12 = i10*32768;
  i13 = i6-1;
  i10 = i10==i11;
  if (i10) goto l14;
  i10 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13999))+4);
  i10 = _check_pointer(i10, 14005);
  i11 = OOC_ARRAY_LENGTH(i10, 0);
  i14 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14017))+4);
  i14 = _check_pointer(i14, 14023);
  i15 = OOC_ARRAY_LENGTH(i14, 0);
  i10 = *(OOC_INT16*)(i10+(_check_index(i13, i11, OOC_UINT32, 14005))*2);
  i11 = *(OOC_INT16*)(i14+(_check_index(i5, i15, OOC_UINT32, 14023))*2);
  i10 = _div((i12+i10),i11);
  q = i10;
  
  goto l15;
l14:
  q = 32767;
  i10=32767;
l15:
  i11 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14059))+4);
  i11 = _check_pointer(i11, 14065);
  i14 = OOC_ARRAY_LENGTH(i11, 0);
  i15 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14111))+4);
  i15 = _check_pointer(i15, 14117);
  i16 = OOC_ARRAY_LENGTH(i15, 0);
  i17 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14142))+4);
  i17 = _check_pointer(i17, 14148);
  i18 = OOC_ARRAY_LENGTH(i17, 0);
  i19 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14168))+4);
  i19 = _check_pointer(i19, 14174);
  i20 = OOC_ARRAY_LENGTH(i19, 0);
  i15 = *(OOC_INT16*)(i15+(_check_index(i13, i16, OOC_UINT32, 14117))*2);
  i16 = *(OOC_INT16*)(i17+(_check_index(i5, i18, OOC_UINT32, 14148))*2);
  i6 = i6-2;
  i11 = *(OOC_INT16*)(i11+(_check_index(i7, i14, OOC_UINT32, 14065))*2);
  i14 = *(OOC_INT16*)(i19+(_check_index(i6, i20, OOC_UINT32, 14174))*2);
  i11 = (i11*i10)>((((i12+i15)-(i10*i16))*32768)+i14);
  if (i11) goto l19_loop;
  i6=i10;
  goto l24;
l19_loop:
  i10 = i10-1;
  q = i10;
  i11 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14059))+4);
  i11 = _check_pointer(i11, 14065);
  i14 = OOC_ARRAY_LENGTH(i11, 0);
  i15 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14111))+4);
  i15 = _check_pointer(i15, 14117);
  i16 = OOC_ARRAY_LENGTH(i15, 0);
  i17 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14142))+4);
  i17 = _check_pointer(i17, 14148);
  i18 = OOC_ARRAY_LENGTH(i17, 0);
  i19 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14168))+4);
  i19 = _check_pointer(i19, 14174);
  i20 = OOC_ARRAY_LENGTH(i19, 0);
  i15 = *(OOC_INT16*)(i15+(_check_index(i13, i16, OOC_UINT32, 14117))*2);
  i16 = *(OOC_INT16*)(i17+(_check_index(i5, i18, OOC_UINT32, 14148))*2);
  i11 = *(OOC_INT16*)(i11+(_check_index(i7, i14, OOC_UINT32, 14065))*2);
  i14 = *(OOC_INT16*)(i19+(_check_index(i6, i20, OOC_UINT32, 14174))*2);
  i11 = (i11*i10)>((((i12+i15)-(i10*i16))*32768)+i14);
  if (i11) goto l19_loop;
l23:
  i6=i10;
l24:
  i = 0;
  if (i8) goto l27;
  i10=0u;
  goto l29;
l27:
  i10 = i9<i1;
  
l29:
  if (i10) goto l31;
  i10=0;i11=0;
  goto l41;
l31:
  i10=0;i11=0;
l32_loop:
  i12 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14283))+4);
  i12 = _check_pointer(i12, 14289);
  i14 = OOC_ARRAY_LENGTH(i12, 0);
  i12 = *(OOC_INT16*)(i12+(_check_index(i10, i14, OOC_UINT32, 14289))*2);
  i12 = i12*i6;
  z = i12;
  i14 = i12>>15;
  zz = i14;
  i15 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14349))+4);
  i15 = _check_pointer(i15, 14355);
  i16 = i10+i9;
  i17 = OOC_ARRAY_LENGTH(i15, 0);
  i15 = *(OOC_INT16*)(i15+(_check_index(i16, i17, OOC_UINT32, 14355))*2);
  i11 = i11+((i15-i12)+(i14*32768));
  carry = i11;
  i12 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14392))+4);
  i12 = _check_pointer(i12, 14398);
  i15 = OOC_ARRAY_LENGTH(i12, 0);
  *(OOC_INT16*)(i12+(_check_index(i16, i15, OOC_UINT32, 14398))*2) = (_mod(i11,32768));
  i11 = (_ash(i11,(-15)))-i14;
  carry = i11;
  i10 = i10+1;
  i = i10;
  i12 = i10<i3;
  if (i12) goto l35;
  i12=0u;
  goto l37;
l35:
  i12 = (i10+i9)<i1;
  
l37:
  if (i12) goto l32_loop;
l41:
  i10 = i10+i9;
  i12 = i10<i1;
  if (i12) goto l44;
  i10=i11;
  goto l45;
l44:
  i12 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14567))+4);
  i12 = _check_pointer(i12, 14573);
  i14 = OOC_ARRAY_LENGTH(i12, 0);
  i12 = *(OOC_INT16*)(i12+(_check_index(i10, i14, OOC_UINT32, 14573))*2);
  i11 = i11+i12;
  carry = i11;
  i12 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14590))+4);
  i12 = _check_pointer(i12, 14596);
  i14 = OOC_ARRAY_LENGTH(i12, 0);
  *(OOC_INT16*)(i12+(_check_index(i10, i14, OOC_UINT32, 14596))*2) = 0;
  i10=i11;
l45:
  i11 = i10==0;
  if (i11) goto l64;
  _assert((i10==(-1)), 127, 14697);
  i10 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 14726))+4);
  i10 = _check_pointer(i10, 14732);
  i11 = OOC_ARRAY_LENGTH(i10, 0);
  *(OOC_INT16*)(i10+(_check_index(i9, i11, OOC_UINT32, 14732))*2) = (i6-1);
  carry = 0;
  i = 0;
  if (i8) goto l50;
  i6=0u;
  goto l52;
l50:
  i6 = i9<i1;
  
l52:
  if (!i6) goto l65;
  i6=0;i10=0;
l54_loop:
  i11 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14854))+4);
  i11 = _check_pointer(i11, 14860);
  i12 = i10+i9;
  i14 = OOC_ARRAY_LENGTH(i11, 0);
  i15 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14869))+4);
  i15 = _check_pointer(i15, 14875);
  i16 = OOC_ARRAY_LENGTH(i15, 0);
  i11 = *(OOC_INT16*)(i11+(_check_index(i12, i14, OOC_UINT32, 14860))*2);
  i14 = *(OOC_INT16*)(i15+(_check_index(i10, i16, OOC_UINT32, 14875))*2);
  i6 = i6+(i11+i14);
  carry = i6;
  i11 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14892))+4);
  i11 = _check_pointer(i11, 14898);
  i14 = OOC_ARRAY_LENGTH(i11, 0);
  *(OOC_INT16*)(i11+(_check_index(i12, i14, OOC_UINT32, 14898))*2) = (_mod(i6,32768));
  i6 = _ash(i6,(-15));
  carry = i6;
  i10 = i10+1;
  i = i10;
  i11 = i10<i3;
  if (i11) goto l57;
  i11=0u;
  goto l59;
l57:
  i11 = (i10+i9)<i1;
  
l59:
  if (i11) goto l54_loop;
  goto l65;
l64:
  i10 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 14655))+4);
  i10 = _check_pointer(i10, 14661);
  i11 = OOC_ARRAY_LENGTH(i10, 0);
  *(OOC_INT16*)(i10+(_check_index(i9, i11, OOC_UINT32, 14661))*2) = i6;
l65:
  j = i13;
  i6 = i9-1;
  k = i6;
  i9 = i6>=0;
  if (!i9) goto l70;
  i9=i6;i6=i13;
  goto l7_loop;
l70:
  Object_BigInt__Normalize((Object_BigInt__BigInt)i4);
  i1 = d;
  i0 = (OOC_INT32)Object_BigInt__DivRem1((Object_BigInt__BigInt)i0, i1, (void*)(OOC_INT32)&d);
  *rem = (Object_BigInt__BigInt)i0;
  return (Object_BigInt__BigInt)i4;
  ;
}

static void Object_BigInt__DivRem(Object_BigInt__BigInt a, Object_BigInt__BigInt b, Object_BigInt__BigInt *div, Object_BigInt__BigInt *rem) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  OOC_INT32 sizeA;
  OOC_INT32 sizeB;
  OOC_INT16 remDigit;
  Object_BigInt__BigInt z;

  i0 = (OOC_INT32)a;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 15286));
  i1 = _abs(i1);
  sizeA = i1;
  i2 = (OOC_INT32)b;
  i3 = *(OOC_INT32*)(_check_pointer(i2, 15308));
  i3 = _abs(i3);
  sizeB = i3;
  _assert((i3!=0), 127, 15352);
  i4 = i1<i3;
  if (i4) goto l7;
  i4 = i1==i3;
  if (i4) goto l5;
  i1=0u;
  goto l9;
l5:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15478))+4);
  i4 = _check_pointer(i4, 15484);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 15497))+4);
  i6 = _check_pointer(i6, 15503);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i1 = *(OOC_INT16*)(i4+(_check_index((i1-1), i5, OOC_UINT32, 15484))*2);
  i4 = *(OOC_INT16*)(i6+(_check_index((i3-1), i7, OOC_UINT32, 15503))*2);
  i1 = i1<i4;
  
  goto l9;
l7:
  i1=1u;
l9:
  if (i1) goto l25;
  i1 = i3==1;
  if (i1) goto l13;
  i1 = (OOC_INT32)Object_BigInt__DivRemAbs((Object_BigInt__BigInt)i0, (Object_BigInt__BigInt)i2, (void*)(OOC_INT32)rem);
  z = (Object_BigInt__BigInt)i1;
  
  goto l14;
l13:
  remDigit = 0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 15660))+4);
  i1 = _check_pointer(i1, 15666);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_INT16*)(i1+(_check_index(0, i3, OOC_UINT8, 15666))*2);
  i1 = (OOC_INT32)Object_BigInt__DivRem1((Object_BigInt__BigInt)i0, i1, (void*)(OOC_INT32)&remDigit);
  z = (Object_BigInt__BigInt)i1;
  i3 = remDigit;
  i3 = (OOC_INT32)Object_BigInt__NewInt(i3);
  *rem = (Object_BigInt__BigInt)i3;
  
l14:
  i2 = *(OOC_INT32*)(_check_pointer(i2, 15931));
  i3 = *(OOC_INT32*)(_check_pointer(i0, 15916));
  i2 = (i3<0)!=(i2<0);
  if (!i2) goto l17;
  i2 = *(OOC_INT32*)(_check_pointer(i1, 15961));
  *(OOC_INT32*)(_check_pointer(i1, 15950)) = (-i2);
l17:
  i0 = *(OOC_INT32*)(_check_pointer(i0, 15990));
  i0 = i0<0;
  if (i0) goto l20;
  i0=0u;
  goto l22;
l20:
  i0 = (OOC_INT32)*rem;
  i0 = *(OOC_INT32*)(_check_pointer(i0, 16007));
  i0 = i0!=0;
  
l22:
  if (!i0) goto l24;
  i0 = (OOC_INT32)*rem;
  i2 = *(OOC_INT32*)(_check_pointer(i0, 16040));
  *(OOC_INT32*)(_check_pointer(i0, 16027)) = (-i2);
l24:
  *div = (Object_BigInt__BigInt)i1;
  goto l26;
l25:
  i1 = (OOC_INT32)Object_BigInt__zero;
  *div = (Object_BigInt__BigInt)i1;
  *rem = (Object_BigInt__BigInt)i0;
l26:
  return;
  ;
}

void Object_BigInt__BigIntDesc_DivMod(Object_BigInt__BigInt v, Object_BigInt__BigInt w, Object_BigInt__BigInt *div, Object_BigInt__BigInt *mod) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)v;
  Object_BigInt__DivRem((Object_BigInt__BigInt)i1, (Object_BigInt__BigInt)i0, (void*)(OOC_INT32)div, (void*)(OOC_INT32)mod);
  i1 = (OOC_INT32)*mod;
  i2 = *(OOC_INT32*)(_check_pointer(i1, 16210));
  i2 = i2<0;
  if (i2) goto l3;
  i2=0u;
  goto l5;
l3:
  i2 = *(OOC_INT32*)(_check_pointer(i0, 16225));
  i2 = i2>0;
  
l5:
  if (i2) goto l11;
  i2 = *(OOC_INT32*)(_check_pointer(i1, 16243));
  i2 = i2>0;
  if (i2) goto l9;
  i2=0u;
  goto l13;
l9:
  i2 = *(OOC_INT32*)(_check_pointer(i0, 16258));
  i2 = i2<0;
  
  goto l13;
l11:
  i2=1u;
l13:
  if (!i2) goto l15;
  i0 = (OOC_INT32)Object_BigInt__BigIntDesc_Add((Object_BigInt__BigInt)i1, (Object_BigInt__BigInt)i0);
  *mod = (Object_BigInt__BigInt)i0;
  i0 = (OOC_INT32)*div;
  i1 = (OOC_INT32)Object_BigInt__one;
  i0 = (OOC_INT32)Object_BigInt__BigIntDesc_Sub((Object_BigInt__BigInt)i0, (Object_BigInt__BigInt)i1);
  *div = (Object_BigInt__BigInt)i0;
l15:
  return;
  ;
}

Object_BigInt__BigInt Object_BigInt__BigIntDesc_Div(Object_BigInt__BigInt v, Object_BigInt__BigInt w) {
  register OOC_INT32 i0,i1;
  Object_BigInt__BigInt mod;
  Object_BigInt__BigInt div;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)v;
  Object_BigInt__BigIntDesc_DivMod((Object_BigInt__BigInt)i1, (Object_BigInt__BigInt)i0, (void*)(OOC_INT32)&div, (void*)(OOC_INT32)&mod);
  i0 = (OOC_INT32)div;
  return (Object_BigInt__BigInt)i0;
  ;
}

Object_BigInt__BigInt Object_BigInt__BigIntDesc_Mod(Object_BigInt__BigInt v, Object_BigInt__BigInt w) {
  register OOC_INT32 i0,i1;
  Object_BigInt__BigInt mod;
  Object_BigInt__BigInt div;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)v;
  Object_BigInt__BigIntDesc_DivMod((Object_BigInt__BigInt)i1, (Object_BigInt__BigInt)i0, (void*)(OOC_INT32)&div, (void*)(OOC_INT32)&mod);
  i0 = (OOC_INT32)mod;
  return (Object_BigInt__BigInt)i0;
  ;
}

Object__String8 Object_BigInt__BigIntDesc_Format(Object_BigInt__BigInt a, OOC_INT16 outputBase) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11,i12,i13,i14;
  OOC_INT32 sizeA;
  OOC_INT32 i;
  OOC_INT32 bits;
  OOC_CHAR8 *str;
  OOC_INT32 pos;
  OOC_INT32 baseBits;
  OOC_INT32 accum;
  OOC_INT32 accumBits;
  OOC_INT32 d;
  OOC_CHAR8 c;
  OOC_INT16 powbase;
  OOC_INT32 power;
  OOC_INT32 newpow;
  Object_BigInt__BigInt scratch;
  OOC_INT32 size;
  OOC_INT32 ntostore;
  OOC_INT16 rem;
  OOC_INT16 nextrem;

  i0 = (OOC_INT32)a;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 17053));
  i1 = _abs(i1);
  sizeA = i1;
  i2 = outputBase;
  i3 = i2>=2;
  if (i3) goto l3;
  i3=0u;
  goto l4;
l3:
  i3 = i2<=36;
  
l4:
  _assert(i3, 127, 17065);
  bits = 0;
  i3 = i2>1;
  if (i3) goto l7;
  i3=0;
  goto l13;
l7:
  i4=i2;i3=0;
l8_loop:
  i3 = i3+1;
  bits = i3;
  i4 = i4>>1;
  i5 = i4>1;
  if (i5) goto l8_loop;
l13:
  i3 = 5+(_div((((i1*15)+i3)-1),i3));
  i = i3;
  i4 = (OOC_INT32)RT0__NewObject(_td_Object_BigInt__16933.baseTypes[0], i3);
  str = (void*)i4;
  pos = i3;
  i5 = i1==0;
  if (i5) goto l84;
  i5 = *(OOC_INT8*)((OOC_INT32)Object_BigInt__powerOf2+(_check_index(i2, 37, OOC_UINT16, 17445)));
  i5 = i5>0;
  if (i5) goto l52;
  powbase = i2;
  power = 1;
  i5=i2;i6=1;
l18_loop:
  i7 = i5*i2;
  newpow = i7;
  i8 = i7>32768;
  if (i8) goto l22;
  powbase = i7;
  i5 = i6+1;
  power = i5;
  i6=i5;i5=i7;
  goto l18_loop;
l22:
  i7 = (OOC_INT32)Object_BigInt__BigIntDesc_Copy((Object_BigInt__BigInt)i0);
  scratch = (Object_BigInt__BigInt)i7;
  i8 = i6>0;
  size = i1;
  
l23_loop:
  ntostore = i6;
  i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i7, 18852))+4);
  i10 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i7, 18852))+4);
  i11 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i7, 18836))+4);
  i12 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i7, 18836))+4);
  i11 = OOC_ARRAY_LENGTH((_check_pointer(i11, 18842)), 0);
  i9 = OOC_ARRAY_LENGTH((_check_pointer(i9, 18858)), 0);
  i9 = Object_BigInt__InplaceDivRem1((void*)(_check_pointer(i12, 18842)), i11, (void*)(_check_pointer(i10, 18858)), i9, i1, i5);
  rem = i9;
  i10 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i7, 18889))+4);
  i10 = _check_pointer(i10, 18895);
  i11 = OOC_ARRAY_LENGTH(i10, 0);
  i12 = i1-1;
  i10 = *(OOC_INT16*)(i10+(_check_index(i12, i11, OOC_UINT32, 18895))*2);
  i10 = i10==0;
  if (!i10) goto l27;
  size = i12;
  i1=i12;
l27:
  _assert(i8, 127, 18988);
  i10 = i1==0;
  i11=i6;{register OOC_INT32 h0=i3;i3=i9;i9=h0;}
l28_loop:
  i12 = _div(i3,i2);
  i3 = i3-(i12*i2);
  nextrem = i12;
  d = i3;
  i13 = i3<10;
  if (i13) goto l31;
  i3 = i3+55;
  c = i3;
  
  goto l32;
l31:
  i3 = i3+48;
  c = i3;
  
l32:
  i9 = i9-1;
  pos = i9;
  i13 = _check_pointer(i4, 19249);
  i14 = OOC_ARRAY_LENGTH(i13, 0);
  *(OOC_UINT8*)(i13+(_check_index(i9, i14, OOC_UINT32, 19249))) = i3;
  rem = i12;
  i3 = i11-1;
  ntostore = i3;
  i11 = i3==0;
  if (i11) goto l38;
  if (i10) goto l36;
  i11=0u;
  goto l40;
l36:
  i11 = i12==0;
  
  goto l40;
l38:
  i11=1u;
l40:
  if (i11) goto l44;
  i11=i3;i3=i12;
  goto l28_loop;
l44:
  if (i10) goto l47;
  i3=i9;
  goto l23_loop;
l47:
  i0 = *(OOC_INT32*)(_check_pointer(i0, 19526));
  i0 = i0<0;
  if (i0) goto l50;
  i0=i9;
  goto l51;
l50:
  i0 = i9-1;
  pos = i0;
  i1 = _check_pointer(i4, 19571);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  *(OOC_UINT8*)(i1+(_check_index(i0, i2, OOC_UINT32, 19571))) = 45u;
  
l51:
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i4, 19635)), 0);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i4, 19650)), 0);
  i0 = (OOC_INT32)Object__NewLatin1Region((void*)(_check_pointer(i4, 19635)), i1, i0, i2);
  return (Object__String8)i0;
  goto l85;
l52:
  i5 = *(OOC_INT8*)((OOC_INT32)Object_BigInt__powerOf2+(_check_index(i2, 37, OOC_UINT16, 17494)));
  baseBits = i5;
  accum = 0;
  accumBits = 0;
  i = 0;
  i6 = 0!=i1;
  if (i6) goto l55;
  i1=i3;
  goto l78;
l55:
  i6 = -i5;
  i7 = i1-1;
  i10=i3;i3=0;i8=0;i9=0;
l56_loop:
  i11 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17620))+4);
  i11 = _check_pointer(i11, 17626);
  i12 = OOC_ARRAY_LENGTH(i11, 0);
  i11 = *(OOC_INT16*)(i11+(_check_index(i8, i12, OOC_UINT32, 17626))*2);
  i3 = i3+(_ash(i11,i9));
  accum = i3;
  i9 = i9+15;
  accumBits = i9;
  i11 = i8<i7;
  _assert((i9>=i5), 127, 17683);
  {register OOC_INT32 h0=i9;i9=i10;i10=h0;}
l57_loop:
  i12 = _mod(i3,i2);
  d = i12;
  i13 = i12<10;
  if (i13) goto l60;
  i12 = i12+55;
  c = i12;
  
  goto l61;
l60:
  i12 = i12+48;
  c = i12;
  
l61:
  i9 = i9-1;
  pos = i9;
  i13 = _check_pointer(i4, 17959);
  i14 = OOC_ARRAY_LENGTH(i13, 0);
  *(OOC_UINT8*)(i13+(_check_index(i9, i14, OOC_UINT32, 17959))) = i12;
  i10 = i10-i5;
  accumBits = i10;
  i3 = _ash(i3,i6);
  accum = i3;
  i12 = i10<i5;
  if (i12) goto l64;
  i12=0u;
  goto l66;
l64:
  i12=i11;
l66:
  if (i12) goto l68;
  i12 = i3==0;
  
  goto l70;
l68:
  i12=1u;
l70:
  if (!i12) goto l57_loop;
l73:
  i8 = i8+1;
  i = i8;
  i11 = i8!=i1;
  if (!i11) goto l77;
  {register OOC_INT32 h0=i9;i9=i10;i10=h0;}
  goto l56_loop;
l77:
  i1=i9;
l78:
  i0 = *(OOC_INT32*)(_check_pointer(i0, 18156));
  i0 = i0<0;
  if (i0) goto l81;
  i0=i1;
  goto l82;
l81:
  i0 = i1-1;
  pos = i0;
  i1 = _check_pointer(i4, 18201);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  *(OOC_UINT8*)(i1+(_check_index(i0, i2, OOC_UINT32, 18201))) = 45u;
  
l82:
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i4, 18265)), 0);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i4, 18280)), 0);
  i0 = (OOC_INT32)Object__NewLatin1Region((void*)(_check_pointer(i4, 18265)), i1, i0, i2);
  return (Object__String8)i0;
  goto l85;
l84:
  i0 = (OOC_INT32)Object__NewLatin1("0", 2);
  return (Object__String8)i0;
l85:
  _failed_function(16650); return 0;
  ;
}

Object__String8 Object_BigInt__BigIntDesc_ToString(Object_BigInt__BigInt a) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)a;
  i0 = (OOC_INT32)Object_BigInt__BigIntDesc_Format((Object_BigInt__BigInt)i0, 10);
  return (Object__String8)i0;
  ;
}

Object_BigInt__BigInt Object_BigInt__NewLatin1Region(const OOC_CHAR8 str[], OOC_LEN str_0d, OOC_INT32 start, OOC_INT32 end, OOC_INT32 inputBase) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  OOC_INT32 sign;
  Object_BigInt__BigInt z;
  OOC_INT32 firstDigit;
  OOC_INT32 d;

  sign = 1;
  i0 = inputBase;
  i1 = 2<=i0;
  if (i1) goto l3;
  i1=0u;
  goto l4;
l3:
  i1 = i0<=36;
  
l4:
  _assert(i1, 127, 20069);
  i1 = start;
  i2 = end;
  i3 = i1!=i2;
  if (i3) goto l7;
  i1=0u;
  goto l9;
l7:
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i1, str_0d, OOC_UINT32, 20202)));
  i1 = CharClass__IsWhiteSpace(i1);
  
l9:
  if (!i1) goto l19;
l10_loop:
  i1 = start;
  i1 = i1+1;
  start = i1;
  i3 = i1!=i2;
  if (i3) goto l13;
  i1=0u;
  goto l15;
l13:
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i1, str_0d, OOC_UINT32, 20202)));
  i1 = CharClass__IsWhiteSpace(i1);
  
l15:
  if (i1) goto l10_loop;
l19:
  i1 = start;
  i3 = i1!=i2;
  if (i3) goto l22;
  i1=1;
  goto l30;
l22:
  i3 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i1, str_0d, OOC_UINT32, 20303)));
  i3 = i3==45u;
  if (i3) goto l28;
  i3 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i1, str_0d, OOC_UINT32, 20379)));
  i3 = i3==43u;
  if (!i3) goto l27;
  start = (i1+1);
l27:
  i1=1;
  goto l30;
l28:
  sign = (-1);
  start = (i1+1);
  i1=(-1);
l30:
  i3 = (OOC_INT32)Object_BigInt__NewInstance(0);
  z = (Object_BigInt__BigInt)i3;
  i4 = start;
  firstDigit = i4;
  i5 = i4!=i2;
  if (i5) goto l34_loop;
  i0=i3;
  goto l55;
l34_loop:
  i5 = start;
  i6 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i5, str_0d, OOC_UINT32, 20535)));
  d = i6;
  i7 = (OOC_UINT8)i6<=(OOC_UINT8)57;
  if (i7) goto l45;
  i7 = (OOC_UINT8)i6>=(OOC_UINT8)97;
  if (i7) goto l43;
  i7 = (OOC_UINT8)i6>=(OOC_UINT8)65;
  if (!i7) goto l46;
  i6 = i6-55;
  d = i6;
  
  goto l46;
l43:
  i6 = i6-87;
  d = i6;
  
  goto l46;
l45:
  i6 = i6-48;
  d = i6;
  
l46:
  i7 = i6>=0;
  if (i7) goto l49;
  i7=0u;
  goto l50;
l49:
  i7 = i6<32768;
  
l50:
  _assert(i7, 127, 20742);
  i3 = (OOC_INT32)Object_BigInt__MulAdd1((Object_BigInt__BigInt)i3, i0, i6);
  z = (Object_BigInt__BigInt)i3;
  i5 = i5+1;
  start = i5;
  i5 = i5!=i2;
  if (i5) goto l34_loop;
l54:
  i0=i3;
l55:
  i2 = *(OOC_INT32*)(_check_pointer(i0, 20872));
  i3 = start;
  *(OOC_INT32*)(_check_pointer(i0, 20857)) = (i1*i2);
  _assert((i3!=i4), 127, 20883);
  return (Object_BigInt__BigInt)i0;
  ;
}

Object_BigInt__BigInt Object_BigInt__NewLatin1(const OOC_CHAR8 str[], OOC_LEN str_0d, OOC_INT32 inputBase) {
  register OOC_INT32 i0,i1;

  i0 = Strings__Length((void*)(OOC_INT32)str, str_0d);
  i1 = inputBase;
  i0 = (OOC_INT32)Object_BigInt__NewLatin1Region((void*)(OOC_INT32)str, str_0d, 0, i0, i1);
  return (Object_BigInt__BigInt)i0;
  ;
}

Object_BigInt__BigInt Object_BigInt__New(Object__String str, OOC_INT32 inputBase) {
  register OOC_INT32 i0,i1,i2,i3;
  Object__String8 str8;
  Object__CharsLatin1 chars;

  i0 = (OOC_INT32)str;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21267)))), Object__StringDesc_ToString8)),Object__StringDesc_ToString8)((Object__String)i0, 63u);
  str8 = (Object__String8)i1;
  i1 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)i1);
  chars = (Object__CharsLatin1)i1;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i1, 21349)), 0);
  i0 = *(OOC_INT32*)(_check_pointer(i0, 21358));
  i3 = inputBase;
  i0 = (OOC_INT32)Object_BigInt__NewLatin1Region((void*)(_check_pointer(i1, 21349)), i2, 0, i0, i3);
  return (Object_BigInt__BigInt)i0;
  ;
}

Object_BigInt__BigInt Object_BigInt__BigIntDesc_Invert(Object_BigInt__BigInt a) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)Object_BigInt__one;
  i1 = (OOC_INT32)a;
  i0 = (OOC_INT32)Object_BigInt__BigIntDesc_Add((Object_BigInt__BigInt)i1, (Object_BigInt__BigInt)i0);
  a = (Object_BigInt__BigInt)i0;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 21538));
  *(OOC_INT32*)(_check_pointer(i0, 21527)) = (-i1);
  return (Object_BigInt__BigInt)i0;
  ;
}

Object_BigInt__BigInt Object_BigInt__BigIntDesc_LShift(Object_BigInt__BigInt a, OOC_INT32 n) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10;
  OOC_INT32 wordShift;
  OOC_INT32 remShift;
  OOC_INT32 oldSize;
  OOC_INT32 newSize;
  Object_BigInt__BigInt z;
  OOC_INT32 i;
  OOC_INT32 accum;
  OOC_INT32 j;

  i0 = n;
  _assert((i0>=0), 127, 21724);
  i1 = _div(i0,15);
  wordShift = i1;
  i0 = _mod(i0,15);
  remShift = i0;
  i2 = (OOC_INT32)a;
  i3 = *(OOC_INT32*)(_check_pointer(i2, 21824));
  i3 = _abs(i3);
  oldSize = i3;
  i4 = i3+i1;
  newSize = i4;
  i5 = i0!=0;
  if (!i5) goto l4;
  i4 = i4+1;
  newSize = i4;
  
l4:
  i6 = (OOC_INT32)Object_BigInt__NewInstance(i4);
  z = (Object_BigInt__BigInt)i6;
  i7 = *(OOC_INT32*)(_check_pointer(i2, 21963));
  i7 = i7<0;
  if (!i7) goto l7;
  i7 = *(OOC_INT32*)(_check_pointer(i6, 21997));
  *(OOC_INT32*)(_check_pointer(i6, 21986)) = (-i7);
l7:
  i = 0;
  i7 = 0!=i1;
  if (i7) goto l10;
  i1=0;
  goto l16;
l10:
  i7=0;
l11_loop:
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 22061))+4);
  i8 = _check_pointer(i8, 22067);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  *(OOC_INT16*)(i8+(_check_index(i7, i9, OOC_UINT32, 22067))*2) = 0;
  i7 = i7+1;
  i = i7;
  i8 = i7!=i1;
  if (i8) goto l11_loop;
l15:
  i1=i7;
l16:
  accum = 0;
  j = 0;
  i7 = 0!=i3;
  if (i7) goto l19;
  i0=0;
  goto l26;
l19:
  i8=i1;i1=0;i7=0;
l20_loop:
  i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 22177))+4);
  i9 = _check_pointer(i9, 22183);
  i10 = OOC_ARRAY_LENGTH(i9, 0);
  i9 = *(OOC_INT16*)(i9+(_check_index(i7, i10, OOC_UINT32, 22183))*2);
  i1 = i1+(_ash(i9,i0));
  accum = i1;
  i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 22207))+4);
  i9 = _check_pointer(i9, 22213);
  i10 = OOC_ARRAY_LENGTH(i9, 0);
  *(OOC_INT16*)(i9+(_check_index(i8, i10, OOC_UINT32, 22213))*2) = (_mod(i1,32768));
  i1 = i1>>15;
  accum = i1;
  i8 = i8+1;
  i = i8;
  i7 = i7+1;
  j = i7;
  i9 = i7!=i3;
  if (i9) goto l20_loop;
l24:
  i0=i1;
l26:
  if (i5) goto l28;
  _assert((i0==0), 127, 22395);
  goto l29;
l28:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 22345))+4);
  i1 = _check_pointer(i1, 22351);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  *(OOC_INT16*)(i1+(_check_index((i4-1), i2, OOC_UINT32, 22351))*2) = i0;
l29:
  Object_BigInt__Normalize((Object_BigInt__BigInt)i6);
  return (Object_BigInt__BigInt)i6;
  ;
}

Object_BigInt__BigInt Object_BigInt__BigIntDesc_RShift(Object_BigInt__BigInt a, OOC_INT32 n) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11,i12,i13,i14,i15,i16;
  OOC_INT32 wordShift;
  OOC_INT32 newSize;
  OOC_INT32 loShift;
  OOC_INT32 hiShift;
  OOC_UINT32 loMask;
  OOC_UINT32 hiMask;
  Object_BigInt__BigInt z;
  OOC_INT32 i;
  OOC_INT32 j;

  i0 = n;
  _assert((i0>=0), 127, 22637);
  i1 = (OOC_INT32)a;
  i2 = *(OOC_INT32*)(_check_pointer(i1, 22662));
  i2 = i2<0;
  if (i2) goto l18;
  i2 = _div(i0,15);
  wordShift = i2;
  i3 = *(OOC_INT32*)(_check_pointer(i1, 22809));
  i3 = i3-i2;
  newSize = i3;
  i4 = i3<=0;
  if (i4) goto l16;
  i0 = _mod(i0,15);
  i4 = 15-i0;
  loShift = i0;
  i5 = (_ash(1,i4))-1;
  hiShift = i4;
  i6 = _type_cast_fast(OOC_UINT32, OOC_INT32, i5);
  loMask = i6;
  i5 = _type_cast_fast(OOC_UINT32, OOC_INT32, (32767-i5));
  hiMask = i5;
  i7 = (OOC_INT32)Object_BigInt__NewInstance(i3);
  z = (Object_BigInt__BigInt)i7;
  i = 0;
  j = i2;
  i8 = 0<i3;
  if (!i8) goto l15;
  i0 = -i0;
  i8=i2;i2=0;
l7_loop:
  i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i7, 23177))+4);
  i9 = _check_pointer(i9, 23183);
  i10 = OOC_ARRAY_LENGTH(i9, 0);
  i11 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23227))+4);
  i11 = _check_pointer(i11, 23233);
  i12 = OOC_ARRAY_LENGTH(i11, 0);
  i11 = *(OOC_INT16*)(i11+(_check_index(i8, i12, OOC_UINT32, 23233))*2);
  *(OOC_INT16*)(i9+(_check_index(i2, i10, OOC_UINT32, 23183))*2) = (_type_cast_fast(OOC_INT32, OOC_UINT32, ((_type_cast_fast(OOC_UINT32, OOC_INT32, (_ash(i11,i0))))&i6)));
  i8 = i8+1;
  i9 = i2+1;
  i10 = i9<i3;
  if (!i10) goto l10;
  i11 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i7, 23310))+4);
  i11 = _check_pointer(i11, 23316);
  i12 = OOC_ARRAY_LENGTH(i11, 0);
  i13 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i7, 23310))+4);
  i13 = _check_pointer(i13, 23316);
  i14 = OOC_ARRAY_LENGTH(i13, 0);
  i15 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23358))+4);
  i15 = _check_pointer(i15, 23364);
  i16 = OOC_ARRAY_LENGTH(i15, 0);
  i15 = *(OOC_INT16*)(i15+(_check_index(i8, i16, OOC_UINT32, 23364))*2);
  i13 = *(OOC_INT16*)(i13+(_check_index(i2, i14, OOC_UINT32, 23316))*2);
  *(OOC_INT16*)(i11+(_check_index(i2, i12, OOC_UINT32, 23316))*2) = (i13+(_type_cast_fast(OOC_INT32, OOC_UINT32, ((_type_cast_fast(OOC_UINT32, OOC_INT32, (_ash(i15,i4))))&i5))));
l10:
  i = i9;
  j = i8;
  if (!i10) goto l15;
  i2=i9;
  goto l7_loop;
l15:
  Object_BigInt__Normalize((Object_BigInt__BigInt)i7);
  return (Object_BigInt__BigInt)i7;
  goto l19;
l16:
  i0 = (OOC_INT32)Object_BigInt__zero;
  return (Object_BigInt__BigInt)i0;
  goto l19;
l18:
  i1 = (OOC_INT32)Object_BigInt__BigIntDesc_Invert((Object_BigInt__BigInt)i1);
  i0 = (OOC_INT32)Object_BigInt__BigIntDesc_RShift((Object_BigInt__BigInt)i1, i0);
  i0 = (OOC_INT32)Object_BigInt__BigIntDesc_Invert((Object_BigInt__BigInt)i0);
  return (Object_BigInt__BigInt)i0;
l19:
  _failed_function(22492); return 0;
  ;
}

void Object_BigInt__BigIntDesc_Store(Object_BigInt__BigInt a, ADT_Storable__Writer w) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 i;

  i0 = (OOC_INT32)a;
  i1 = (OOC_INT32)w;
  i2 = *(OOC_INT32*)(_check_pointer(i0, 23643));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 23632)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i1, i2);
  i2 = *(OOC_INT32*)(_check_pointer(i0, 23674));
  i = 0;
  i2 = _abs(i2);
  i3 = 0<i2;
  if (!i3) goto l8;
  i3=0;
l3_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23704))+4);
  i4 = _check_pointer(i4, 23710);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = *(OOC_INT16*)(i4+(_check_index(i3, i5, OOC_UINT32, 23710))*2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 23693)))), IO_BinaryRider__WriterDesc_WriteInt)),IO_BinaryRider__WriterDesc_WriteInt)((IO_BinaryRider__Writer)i1, i4);
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l3_loop;
l8:
  return;
  ;
}

void Object_BigInt__BigIntDesc_Load(Object_BigInt__BigInt a, ADT_Storable__Reader r) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 i;

  i0 = (OOC_INT32)a;
  i1 = (OOC_INT32)r;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 23839)))), IO_BinaryRider__ReaderDesc_ReadNum)),IO_BinaryRider__ReaderDesc_ReadNum)((IO_BinaryRider__Reader)i1, (void*)(_check_pointer(i0, 23849)));
  i2 = *(OOC_INT32*)(_check_pointer(i0, 23879));
  *(OOC_INT32*)((_check_pointer(i0, 23866))+4) = ((OOC_INT32)RT0__NewObject(_td_Object_BigInt__DigitArray.baseTypes[0], (_abs(i2))));
  i2 = *(OOC_INT32*)(_check_pointer(i0, 23911));
  i = 0;
  i2 = _abs(i2);
  i3 = 0<i2;
  if (!i3) goto l8;
  i3=0;
l3_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23940))+4);
  i4 = _check_pointer(i4, 23946);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 23930)))), IO_BinaryRider__ReaderDesc_ReadInt)),IO_BinaryRider__ReaderDesc_ReadInt)((IO_BinaryRider__Reader)i1, (void*)(i4+(_check_index(i3, i5, OOC_UINT32, 23946))*2));
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l3_loop;
l8:
  return;
  ;
}

static void Object_BigInt__Init(void) {
  register OOC_INT32 i0,i1;
  OOC_INT32 i;

  i = 0;
  i0=0;
l1_loop:
  *(OOC_INT8*)((OOC_INT32)Object_BigInt__powerOf2+(_check_index(i0, 37, OOC_UINT32, 24074))) = (-1);
  i0 = i0+1;
  i = i0;
  i1 = i0<=36;
  if (i1) goto l1_loop;
l5:
  *(OOC_INT8*)((OOC_INT32)Object_BigInt__powerOf2+(_check_index(2, 37, OOC_UINT8, 24106))) = 1;
  *(OOC_INT8*)((OOC_INT32)Object_BigInt__powerOf2+(_check_index(4, 37, OOC_UINT8, 24129))) = 2;
  *(OOC_INT8*)((OOC_INT32)Object_BigInt__powerOf2+(_check_index(8, 37, OOC_UINT8, 24152))) = 3;
  *(OOC_INT8*)((OOC_INT32)Object_BigInt__powerOf2+(_check_index(16, 37, OOC_UINT8, 24175))) = 4;
  *(OOC_INT8*)((OOC_INT32)Object_BigInt__powerOf2+(_check_index(32, 37, OOC_UINT8, 24198))) = 5;
  i0 = (OOC_INT32)Object_BigInt__NewInstance(0);
  Object_BigInt__zero = (Object_BigInt__BigInt)i0;
  i0 = (OOC_INT32)Object_BigInt__NewInstance(1);
  Object_BigInt__one = (Object_BigInt__BigInt)i0;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24272))+4);
  i0 = _check_pointer(i0, 24278);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  *(OOC_INT16*)(i0+(_check_index(0, i1, OOC_UINT8, 24278))*2) = 1;
  return;
  ;
}

void OOC_Object_BigInt_init(void) {

  Object_BigInt__Init();
  return;
  ;
}

void OOC_Object_BigInt_destroy(void) {
}

/* --- */
