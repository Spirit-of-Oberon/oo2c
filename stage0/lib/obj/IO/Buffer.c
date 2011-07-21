#include <IO/Buffer.d>
#include <__oo2c.h>
#include <setjmp.h>

static void IO_Buffer__Init(IO_Buffer__Channel ch, IO__ByteChannel base) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)ch;
  IO__InitByteChannel((IO__ByteChannel)i0);
  i1 = (OOC_INT32)base;
  *(OOC_INT32*)((_check_pointer(i0, 1488))+8) = i1;
  *(OOC_UINT8*)((_check_pointer(i0, 1509))+12) = 1u;
  *(OOC_INT32*)((_check_pointer(i0, 1533))+16) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 1550))+20) = 0;
  return;
  ;
}

IO_Buffer__Channel IO_Buffer__Open(IO__ByteChannel base) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)RT0__NewObject(_td_IO_Buffer__Channel.baseTypes[0]);
  i1 = (OOC_INT32)base;
  IO_Buffer__Init((IO_Buffer__Channel)i0, (IO__ByteChannel)i1);
  return (IO_Buffer__Channel)i0;
  ;
}

void IO_Buffer__ChannelDesc_Flush(IO_Buffer__Channel ch) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_INT32 d;

  i0 = (OOC_INT32)ch;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 1812))+16);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 1821))+20);
  i1 = i1!=i2;
  if (!i1) goto l7;
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 1851))+12);
  if (i1) goto l5;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 1943))+16);
  _assert((i1==0), 127, 1934);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1969))+8);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 1997))+20);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1969))+8);
  i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 1974)))), IO__ByteChannelDesc_Write)),IO__ByteChannelDesc_Write)((IO__ByteChannel)i3, (void*)((_check_pointer(i0, 1983))+24), 8192, 0, i2);
  d = i1;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 2033))+20);
  _assert((i1==i2), 127, 2020);
  *(OOC_INT32*)((_check_pointer(i0, 2058))+20) = 0;
  goto l6;
l5:
  *(OOC_INT32*)((_check_pointer(i0, 1875))+16) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 1896))+20) = 0;
l6:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2096))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2096))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2101)))), IO__ByteChannelDesc_Flush)),IO__ByteChannelDesc_Flush)((IO__ByteChannel)i0);
l7:
  return;
  ;
}

void IO_Buffer__ChannelDesc_SetPos(IO_Buffer__Channel ch, OOC_INT32 pos) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)ch;
  IO_Buffer__ChannelDesc_Flush((IO_Buffer__Channel)i0);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2227))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2227))+8);
  i2 = pos;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2232)))), IO__ChannelDesc_SetPos)),IO__ChannelDesc_SetPos)((IO__Channel)i0, i2);
  return;
  ;
}

OOC_INT32 IO_Buffer__ChannelDesc_Read(IO_Buffer__Channel ch, OOC_CHAR8 buffer[], OOC_LEN buffer_0d, OOC_INT32 start, OOC_INT32 length) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_INT32 i;
  OOC_INT32 d;

  i0 = (OOC_INT32)ch;
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 2447))+12);
  if (i1) goto l3;
  IO_Buffer__ChannelDesc_Flush((IO_Buffer__Channel)i0);
  i = 0;
  
  goto l8;
l3:
  i1 = *(OOC_INT32*)((_check_pointer(i0, 2474))+20);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 2489))+16);
  i1 = i1-i2;
  i = i1;
  _assert((i1>=0), 127, 2501);
  i2 = length;
  i3 = i1>=i2;
  if (i3) goto l6;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 2889))+16);
  i3 = start;
  _move_block((((_check_pointer(i0, 2878))+24)+i2),((OOC_INT32)buffer+i3),i1);
  i0 = (OOC_INT32)ch;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 2979))+16);
  i2 = i;
  i3 = start;
  *(OOC_INT32*)((_check_pointer(i0, 2979))+16) = (i1+i2);
  i1 = length;
  start = (i3+i2);
  length = (i1-i2);
  
  goto l8;
l6:
  i1 = *(OOC_INT32*)((_check_pointer(i0, 2641))+16);
  i3 = start;
  _move_block((((_check_pointer(i0, 2630))+24)+i1),((OOC_INT32)buffer+i3),i2);
  i0 = (OOC_INT32)ch;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 2736))+16);
  i2 = length;
  *(OOC_INT32*)((_check_pointer(i0, 2736))+16) = (i1+i2);
  return i2;
  
l8:
  i1 = length;
  i2 = i1!=0;
  if (i2) goto l11;
  i0 = i;
  return i0;
  goto l32;
l11:
  i2 = *(OOC_INT32*)((_check_pointer(i0, 3273))+16);
  i3 = *(OOC_INT32*)((_check_pointer(i0, 3282))+20);
  _assert((i2==i3), 127, 3264);
  i2 = i1>=4096;
  if (i2) goto l22;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3617))+8);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3617))+8);
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 3622)))), IO__ByteChannelDesc_Read)),IO__ByteChannelDesc_Read)((IO__ByteChannel)i3, (void*)((_check_pointer(i0, 3630))+24), 8192, 0, 8192);
  d = i2;
  *(OOC_UINT8*)((_check_pointer(i0, 3665))+12) = 1u;
  *(OOC_INT32*)((_check_pointer(i0, 3693))+16) = 0;
  i3 = i2<0;
  if (i3) goto l16;
  *(OOC_INT32*)((_check_pointer(i0, 3979))+20) = i2;
  i2 = start;
  i0 = IO_Buffer__ChannelDesc_Read((IO_Buffer__Channel)i0, (void*)(OOC_INT32)buffer, (-1), i2, i1);
  i1 = i;
  return (i1+i0);
  goto l32;
l16:
  *(OOC_INT32*)((_check_pointer(i0, 3775))+20) = 0;
  i0 = i;
  i1 = i0>0;
  if (i1) goto l19;
  return (-1);
  goto l32;
l19:
  return i0;
  goto l32;
l22:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3349))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3349))+8);
  i3 = start;
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 3354)))), IO__ByteChannelDesc_Read)),IO__ByteChannelDesc_Read)((IO__ByteChannel)i0, (void*)(OOC_INT32)buffer, (-1), i3, i1);
  i1 = i0<0;
  if (i1) goto l25;
  i1 = i;
  return (i0+i1);
  goto l32;
l25:
  i1 = i;
  i2 = i1>0;
  if (i2) goto l28;
  return i0;
  goto l32;
l28:
  return i1;
l32:
  _failed_function(2285); return 0;
  ;
}

Object__String8 IO_Buffer__ChannelDesc_ReadLineLF(IO_Buffer__Channel ch) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT32 i;
  Object__String8 str8;
  ADT_StringBuffer__StringBuffer sb;
  OOC_INT32 d;
  Object__String str;

  i0 = (OOC_INT32)ch;
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 4769))+12);
  i1 = !i1;
  if (!i1) goto l3;
  IO_Buffer__ChannelDesc_Flush((IO_Buffer__Channel)i0);
l3:
  i1 = *(OOC_INT32*)((_check_pointer(i0, 4822))+16);
  i = i1;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 4845))+20);
  i2 = i1!=i2;
  if (!i2) goto l14;
l6_loop:
  i2 = *(OOC_UINT8*)(((_check_pointer(i0, 4874))+24)+(_check_index(i1, 8192, OOC_UINT32, 4881)));
  i1 = i1+1;
  i2 = i2==10u;
  if (!i2) goto l9;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 4991))+16);
  i2 = (OOC_INT32)Object__NewLatin1Region((void*)((_check_pointer(i0, 4980))+24), 8192, i2, i1);
  str8 = (Object__String8)i2;
  *(OOC_INT32*)((_check_pointer(i0, 5013))+16) = i1;
  return (Object__String8)i2;
l9:
  i = i1;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 4845))+20);
  i2 = i1!=i2;
  if (i2) goto l6_loop;
l14:
  i1 = *(OOC_INT32*)((_check_pointer(i0, 5274))+20);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 5266))+16);
  i1 = (OOC_INT32)ADT_StringBuffer__NewLatin1Region((void*)((_check_pointer(i0, 5255))+24), 8192, i2, i1);
  sb = (ADT_StringBuffer__StringBuffer)i1;
l15_loop:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5311))+8);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5311))+8);
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 5316)))), IO__ByteChannelDesc_Read)),IO__ByteChannelDesc_Read)((IO__ByteChannel)i3, (void*)((_check_pointer(i0, 5324))+24), 8192, 0, 8192);
  d = i2;
  i3 = i2<0;
  if (i3) goto l39;
  i = 0;
  i3 = 0!=i2;
  if (i3) goto l20;
  i3=0u;
  goto l22;
l20:
  i3 = *(OOC_UINT8*)(((_check_pointer(i0, 5711))+24)+(_check_index(0, 8192, OOC_UINT32, 5718)));
  i3 = i3!=10u;
  
l22:
  if (i3) goto l24;
  i3=0;
  goto l34;
l24:
  i3=0;
l25_loop:
  i3 = i3+1;
  i = i3;
  i4 = i3!=i2;
  if (i4) goto l28;
  i4=0u;
  goto l30;
l28:
  i4 = *(OOC_UINT8*)(((_check_pointer(i0, 5711))+24)+(_check_index(i3, 8192, OOC_UINT32, 5718)));
  i4 = i4!=10u;
  
l30:
  if (i4) goto l25_loop;
l34:
  i4 = i3==i2;
  if (!i4) goto l36;
  goto l37;
l36:
  i3 = i3+1;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5974)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1Region)),ADT_StringBuffer__StringBufferDesc_AppendLatin1Region)((ADT_StringBuffer__StringBuffer)i1, (void*)((_check_pointer(i0, 5996))+24), 8192, 0, i3);
  *(OOC_INT32*)((_check_pointer(i0, 6026))+16) = i3;
  *(OOC_INT32*)((_check_pointer(i0, 6051))+20) = i2;
  goto l45;
l37:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5852)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1Region)),ADT_StringBuffer__StringBufferDesc_AppendLatin1Region)((ADT_StringBuffer__StringBuffer)i1, (void*)((_check_pointer(i0, 5874))+24), 8192, 0, i2);
  goto l15_loop;
l39:
  i2 = *(OOC_INT32*)((_check_pointer(i1, 5422))+4);
  i2 = i2==0;
  if (!i2) goto l41;
  goto l42;
l41:
  *(OOC_INT32*)((_check_pointer(i0, 5586))+16) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 5609))+20) = 0;
  goto l45;
l42:
  return (Object__String8)(OOC_INT32)0;
  goto l15_loop;
l45:
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6132)))), ADT_StringBuffer__StringBufferDesc_ToString)),ADT_StringBuffer__StringBufferDesc_ToString)((ADT_StringBuffer__StringBuffer)i1);
  str = (Object__String)i0;
  return (Object__String8)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6167)))), &_td_Object__String8Desc, 6167));
  ;
}

OOC_INT32 IO_Buffer__ChannelDesc_Write(IO_Buffer__Channel ch, const OOC_CHAR8 buffer[], OOC_LEN buffer_0d, OOC_INT32 start, OOC_INT32 length) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)ch;
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 6364))+12);
  if (!i1) goto l3;
  IO_Buffer__ChannelDesc_Flush((IO_Buffer__Channel)i0);
  *(OOC_UINT8*)((_check_pointer(i0, 6404))+12) = 0u;
l3:
  i1 = *(OOC_INT32*)((_check_pointer(i0, 6447))+20);
  i2 = length;
  i1 = (i1+i2)<=8192;
  if (i1) goto l10;
  IO_Buffer__ChannelDesc_Flush((IO_Buffer__Channel)i0);
  i1 = i2>=4096;
  if (i1) goto l8;
  i1 = start;
  i0 = IO_Buffer__ChannelDesc_Write((IO_Buffer__Channel)i0, (void*)(OOC_INT32)buffer, (-1), i1, i2);
  return i0;
  goto l11;
l8:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6834))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6834))+8);
  i3 = start;
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6839)))), IO__ByteChannelDesc_Write)),IO__ByteChannelDesc_Write)((IO__ByteChannel)i0, (void*)(OOC_INT32)buffer, (-1), i3, i2);
  return i0;
  goto l11;
l10:
  i1 = *(OOC_INT32*)((_check_pointer(i0, 6596))+20);
  i3 = start;
  _move_block(((OOC_INT32)buffer+i3),(((_check_pointer(i0, 6585))+24)+i1),i2);
  i0 = (OOC_INT32)ch;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 6631))+20);
  i2 = length;
  *(OOC_INT32*)((_check_pointer(i0, 6631))+20) = (i1+i2);
  return i2;
l11:
  _failed_function(6220); return 0;
  ;
}

void IO_Buffer__ChannelDesc_SetBlocking(IO_Buffer__Channel ch, OOC_CHAR8 block) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)ch;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7112))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7112))+8);
  i2 = block;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7117)))), IO__ChannelDesc_SetBlocking)),IO__ChannelDesc_SetBlocking)((IO__Channel)i0, i2);
  return;
  ;
}

OOC_INT32 IO_Buffer__ChannelDesc_FileDescriptor(IO_Buffer__Channel ch) {

  return (-1);
  ;
}

void IO_Buffer__ChannelDesc_Close(IO_Buffer__Channel ch) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)ch;
  IO_Buffer__ChannelDesc_Flush((IO_Buffer__Channel)i0);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7346))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7346))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7351)))), IO__ChannelDesc_Close)),IO__ChannelDesc_Close)((IO__Channel)i0);
  return;
  ;
}

void IO_Buffer__ChannelDesc_CloseAndRegister(IO_Buffer__Channel ch) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)ch;
  IO_Buffer__ChannelDesc_Flush((IO_Buffer__Channel)i0);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7466))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7466))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7471)))), IO__ChannelDesc_CloseAndRegister)),IO__ChannelDesc_CloseAndRegister)((IO__Channel)i0);
  return;
  ;
}

void OOC_IO_Buffer_init(void) {

  return;
  ;
}

/* --- */
