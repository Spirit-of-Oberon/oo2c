#include <IO/Memory.d>
#include <__oo2c.h>
#include <setjmp.h>

void IO_Memory__ChannelDesc_INIT(IO_Memory__Channel ch) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)ch;
  IO__ByteChannelDesc_INIT((IO__ByteChannel)i0);
  *(OOC_INT32*)((_check_pointer(i0, 1201))+16) = ((OOC_INT32)RT0__NewObject(_td_IO_Memory__Data.baseTypes[0], 4080));
  *(OOC_INT32*)((_check_pointer(i0, 1230))+8) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 1247))+12) = 0;
  return;
  ;
}

IO_Memory__Channel IO_Memory__Open(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)RT0__NewObject(_td_IO_Memory__Channel.baseTypes[0]);
  IO_Memory__ChannelDesc_INIT((IO_Memory__Channel)i0);
  return (IO_Memory__Channel)i0;
  ;
}

void IO_Memory__ChannelDesc_SetBlocking(IO_Memory__Channel ch, OOC_CHAR8 block) {

  return;
  ;
}

OOC_INT32 IO_Memory__ChannelDesc_FileDescriptor(IO_Memory__Channel ch) {

  return (-1);
  ;
}

void IO_Memory__ChannelDesc_SetPos(IO_Memory__Channel ch, OOC_INT32 pos) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)ch;
  i1 = pos;
  *(OOC_INT32*)((_check_pointer(i0, 1662))+8) = i1;
  return;
  ;
}

OOC_INT32 IO_Memory__ChannelDesc_Read(IO_Memory__Channel ch, OOC_CHAR8 buffer[], OOC_LEN buffer_0d, OOC_INT32 start, OOC_INT32 length) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)ch;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 1836))+8);
  i2 = length;
  i3 = *(OOC_INT32*)((_check_pointer(i0, 1853))+12);
  i1 = (i1+i2)<=i3;
  if (i1) goto l7;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 2080))+8);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 2089))+12);
  i1 = i1==i2;
  if (i1) goto l5;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 2223))+12);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 2233))+8);
  i1 = i1-i2;
  length = i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2270))+16);
  i0 = *(OOC_INT32*)((_check_pointer(i0, 2280))+8);
  i3 = start;
  _move_block(((_check_pointer(i2, 2275))+i0),((OOC_INT32)buffer+i3),i1);
  i0 = (OOC_INT32)ch;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 2369))+8);
  i2 = length;
  *(OOC_INT32*)((_check_pointer(i0, 2369))+8) = (i1+i2);
  return i2;
  goto l8;
l5:
  return (-1);
  goto l8;
l7:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1932))+16);
  i0 = *(OOC_INT32*)((_check_pointer(i0, 1942))+8);
  i3 = start;
  _move_block(((_check_pointer(i1, 1937))+i0),((OOC_INT32)buffer+i3),i2);
  i0 = (OOC_INT32)ch;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 2031))+8);
  i2 = length;
  *(OOC_INT32*)((_check_pointer(i0, 2031))+8) = (i1+i2);
  return i2;
l8:
  _failed_function(1714); return 0;
  ;
}

OOC_INT32 IO_Memory__ChannelDesc_Write(IO_Memory__Channel ch, const OOC_CHAR8 buffer[], OOC_LEN buffer_0d, OOC_INT32 start, OOC_INT32 length) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_INT32 i;
  IO_Memory__Data n;

  i0 = (OOC_INT32)ch;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2635))+16);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 2615))+8);
  i3 = length;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 2640)), 0);
  i1 = (i2+i3)>i1;
  if (!i1) goto l9;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2666))+16);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 2671)), 0);
  
l4_loop:
  i1 = 16+i1*2;
  i = i1;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 2733))+8);
  i2 = i1>=(i2+i3);
  if (!i2) goto l4_loop;
l8:
  i1 = (OOC_INT32)RT0__NewObject(_td_IO_Memory__Data.baseTypes[0], i1);
  n = (IO_Memory__Data)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2795))+16);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2826))+16);
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 2831)), 0);
  _move_block((_check_pointer(i2, 2800)),(_check_pointer(i1, 2816)),i0);
  i0 = (OOC_INT32)ch;
  i1 = (OOC_INT32)n;
  *(OOC_INT32*)((_check_pointer(i0, 2844))+16) = i1;
  
l9:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2941))+16);
  i0 = *(OOC_INT32*)((_check_pointer(i0, 2951))+8);
  i2 = start;
  i3 = length;
  _move_block(((OOC_INT32)buffer+i2),((_check_pointer(i1, 2946))+i0),i3);
  i0 = (OOC_INT32)ch;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 2992))+8);
  i2 = length;
  *(OOC_INT32*)((_check_pointer(i0, 2992))+8) = (i1+i2);
  i1 = *(OOC_INT32*)((_check_pointer(i0, 3026))+12);
  i3 = *(OOC_INT32*)((_check_pointer(i0, 3017))+8);
  i1 = i3>i1;
  if (!i1) goto l12;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 3061))+8);
  *(OOC_INT32*)((_check_pointer(i0, 3048))+12) = i1;
l12:
  return i2;
  ;
}

void IO_Memory__ChannelDesc_Truncate(IO_Memory__Channel ch, OOC_INT32 newLength) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)ch;
  i1 = newLength;
  *(OOC_INT32*)((_check_pointer(i0, 3247))+12) = i1;
  return;
  ;
}

void IO_Memory__ChannelDesc_Fingerprint(IO_Memory__Channel ch, OOC_CHAR8 key[], OOC_LEN key_0d, OOC_INT32 start, OOC_INT32 end) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_INT16 i;
  OOC_INT16 j;
  OOC_INT32 pos;
  OOC_CHAR8 byte;
  OOC_INT16 old;
  OOC_INT16 _new;

  i0=0;
l1_loop:
  *(OOC_UINT8*)((OOC_INT32)key+(_check_index(i0, key_0d, OOC_UINT16, 3993))) = 0;
  i0 = i0+1;
  i1 = i0<=3;
  if (i1) goto l1_loop;
l5:
  i = 0;
  j = 0;
  i0 = start;
  pos = i0;
  i1 = end;
  i2 = i0<i1;
  if (!i2) goto l17;
  i2 = (OOC_INT32)ch;
  i3=0;i4=0;
l8_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 4121))+16);
  i5 = _check_pointer(i5, 4127);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = *(OOC_UINT8*)(i5+(_check_index(i0, i6, OOC_UINT32, 4127)));
  i5 = _type_cast_fast(OOC_UINT8, OOC_UINT8, i5);
  byte = i5;
  i6 = *(OOC_UINT8*)((OOC_INT32)key+(_check_index(i3, key_0d, OOC_UINT16, 4174)));
  i6 = _type_cast_fast(OOC_UINT8, OOC_UINT8, i6);
  old = i6;
  i5 = _type_cast_fast(OOC_UINT8, OOC_UINT8, (_rot(OOC_UINT8, i5, i4)));
  _new = i5;
  *(OOC_UINT8*)((OOC_INT32)key+(_check_index(i3, key_0d, OOC_UINT16, 4250))) = (_mod((i6+i5),256));
  i3 = i3+1;
  i = i3;
  i5 = i3==4;
  if (!i5) goto l12;
  i3 = _mod((i4+1),8);
  j = i3;
  i = 0;
  i4=i3;i3=0;
l12:
  i0 = i0+1;
  pos = i0;
  i5 = i0<i1;
  if (i5) goto l8_loop;
l17:
  return;
  ;
}

void OOC_IO_Memory_init(void) {

  return;
  ;
}

void OOC_IO_Memory_destroy(void) {
}

/* --- */
