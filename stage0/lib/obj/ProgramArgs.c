#include <ProgramArgs.d>
#include <__oo2c.h>
#include <setjmp.h>

static Msg__Msg ProgramArgs__GetError(OOC_INT32 code) {
  register OOC_INT32 i0,i1;

  i0 = code;
  i1 = (OOC_INT32)ProgramArgs__errorContext;
  i0 = (OOC_INT32)Msg__New((Msg__Context)i1, i0);
  return (Msg__Msg)i0;
  ;
}

OOC_INT32 ProgramArgs__ReaderDesc_Pos(ProgramArgs__Reader r) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 i;
  OOC_INT32 j;
  OOC_INT32 count;

  i0 = (OOC_INT32)r;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 2881))+16);
  i2 = RT0__argc;
  i1 = i1==i2;
  if (i1) goto l24;
  i = 0;
  j = 0;
  count = 0;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 3054))+16);
  i1 = 0!=i1;
  if (i1) goto l5;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 3071))+20);
  i1 = 0!=i1;
  
  goto l7;
l5:
  i1=1u;
l7:
  if (i1) goto l9;
  i0=0;
  goto l23;
l9:
  i1 = (OOC_INT32)RT0__argv;
  i2=0;i3=0;i4=0;
l10_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3102))+i2*4);
  i5 = *(OOC_UINT8*)((_check_pointer(i5, 3105))+i3);
  i5 = i5==0u;
  if (i5) goto l13;
  i3 = i3+1;
  j = i3;
  
  goto l14;
l13:
  i2 = i2+1;
  i = i2;
  j = 0;
  i3=0;
l14:
  i4 = i4+1;
  count = i4;
  i5 = *(OOC_INT32*)((_check_pointer(i0, 3054))+16);
  i5 = i2!=i5;
  if (i5) goto l17;
  i5 = *(OOC_INT32*)((_check_pointer(i0, 3071))+20);
  i5 = i3!=i5;
  
  goto l19;
l17:
  i5=1u;
l19:
  if (i5) goto l10_loop;
l22:
  i0=i4;
l23:
  return i0;
  goto l25;
l24:
  i0 = *(OOC_INT32*)((_check_pointer(i0, 2986))+20);
  return i0;
l25:
  _failed_function(2815); return 0;
  ;
}

OOC_INT32 ProgramArgs__ReaderDesc_Available(ProgramArgs__Reader r) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3343));
  i1 = *(OOC_UINT8*)((_check_pointer(i1, 3349))+6);
  if (i1) goto l3;
  return (-1);
  goto l8;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3373));
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3373));
  i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3379)))), Channel__ChannelDesc_Length)),Channel__ChannelDesc_Length)((Channel__Channel)i2);
  i0 = ProgramArgs__ReaderDesc_Pos((ProgramArgs__Reader)i0);
  i0 = i1-i0;
  i1 = i0<0;
  if (i1) goto l6;
  return i0;
  goto l8;
l6:
  return 0;
l8:
  _failed_function(3282); return 0;
  ;
}

void ProgramArgs__ReaderDesc_SetPos(ProgramArgs__Reader r, OOC_INT32 newPos) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  OOC_INT32 i;
  OOC_INT32 j;
  OOC_INT32 count;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3630))+4);
  i1 = i1==(OOC_INT32)0;
  if (!i1) goto l36;
  i1 = newPos;
  i2 = i1<0;
  if (i2) goto l34;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3729));
  i2 = *(OOC_UINT8*)((_check_pointer(i2, 3735))+6);
  if (i2) goto l7;
  i1 = (OOC_INT32)ProgramArgs__GetError(6);
  *(OOC_INT32*)((_check_pointer(i0, 4238))+4) = i1;
  goto l36;
l7:
  i = 0;
  j = 0;
  count = 0;
  i2 = RT0__argc;
  i3 = 0<i2;
  if (i3) goto l10;
  i3=0u;
  goto l12;
l10:
  i3 = 0!=i1;
  
l12:
  if (i3) goto l14;
  i3=0;i4=0;
  goto l28;
l14:
  i3 = (OOC_INT32)RT0__argv;
  i4=0;i5=0;i6=0;
l15_loop:
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 3856))+i4*4);
  i7 = *(OOC_UINT8*)((_check_pointer(i7, 3859))+i5);
  i7 = i7==0u;
  if (i7) goto l18;
  i5 = i5+1;
  j = i5;
  
  goto l19;
l18:
  i4 = i4+1;
  i = i4;
  j = 0;
  i5=0;
l19:
  i6 = i6+1;
  count = i6;
  i7 = i4<i2;
  if (i7) goto l22;
  i7=0u;
  goto l24;
l22:
  i7 = i6!=i1;
  
l24:
  if (i7) goto l15_loop;
l27:
  i3=i4;i4=i5;
l28:
  *(OOC_INT32*)((_check_pointer(i0, 3996))+16) = i3;
  i2 = i3==i2;
  if (i2) goto l31;
  *(OOC_INT32*)((_check_pointer(i0, 4163))+20) = i4;
  goto l36;
l31:
  *(OOC_INT32*)((_check_pointer(i0, 4122))+20) = i1;
  goto l36;
l34:
  i1 = (OOC_INT32)ProgramArgs__GetError(4);
  *(OOC_INT32*)((_check_pointer(i0, 3685))+4) = i1;
l36:
  return;
  ;
}

void ProgramArgs__ReaderDesc_ReadByte(ProgramArgs__Reader r, OOC_CHAR8 *x) {
  register OOC_INT32 i0,i1,i2,i3,i4;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4378))+4);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l3;
  *(OOC_INT32*)((_check_pointer(i0, 5214))+8) = 0;
  goto l24;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4407));
  i1 = *(OOC_UINT8*)((_check_pointer(i1, 4413))+6);
  if (i1) goto l6;
  i1 = (OOC_INT32)ProgramArgs__GetError(6);
  *(OOC_INT32*)((_check_pointer(i0, 5127))+4) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 5171))+8) = 0;
  goto l24;
l6:
  i1 = *(OOC_INT32*)((_check_pointer(i0, 4438))+16);
  i2 = RT0__argc;
  i1 = i1==i2;
  if (i1) goto l21;
  i1 = (OOC_INT32)RT0__argv;
  i3 = *(OOC_INT32*)((_check_pointer(i0, 4531))+16);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4529))+i3*4);
  i4 = *(OOC_INT32*)((_check_pointer(i0, 4540))+20);
  i3 = *(OOC_UINT8*)((_check_pointer(i3, 4538))+i4);
  i3 = i3==0u;
  if (i3) goto l15;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 4846))+16);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4844))+i2*4);
  i3 = *(OOC_INT32*)((_check_pointer(i0, 4855))+20);
  i2 = *(OOC_UINT8*)((_check_pointer(i2, 4853))+i3);
  i2 = i2==10u;
  if (i2) goto l13;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 5022))+16);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5020))+i2*4);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 5031))+20);
  i1 = *(OOC_UINT8*)((_check_pointer(i1, 5029))+i2);
  *x = i1;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 5056))+20);
  *(OOC_INT32*)((_check_pointer(i0, 5056))+20) = (i1+1);
  goto l24;
l13:
  *x = 32u;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 4976))+20);
  *(OOC_INT32*)((_check_pointer(i0, 4976))+20) = (i1+1);
  goto l24;
l15:
  *x = 10u;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 4605))+16);
  *(OOC_INT32*)((_check_pointer(i0, 4605))+16) = (i1+1);
  i1 = *(OOC_INT32*)((_check_pointer(i0, 4629))+16);
  i1 = i1==i2;
  if (i1) goto l18;
  *(OOC_INT32*)((_check_pointer(i0, 4795))+20) = 0;
  goto l24;
l18:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4750));
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4750));
  i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4756)))), Channel__ChannelDesc_Length)),Channel__ChannelDesc_Length)((Channel__Channel)i2);
  *(OOC_INT32*)((_check_pointer(i0, 4739))+20) = i1;
  goto l24;
l21:
  i1 = (OOC_INT32)ProgramArgs__GetError(5);
  *(OOC_INT32*)((_check_pointer(i0, 4473))+4) = i1;
l24:
  return;
  ;
}

void ProgramArgs__ReaderDesc_ReadBytes(ProgramArgs__Reader r, OOC_CHAR8 x[], OOC_LEN x_0d, OOC_INT32 start, OOC_INT32 n) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 i;

  i = 0;
  i0 = n;
  i1 = 0<i0;
  if (i1) goto l3;
  i1=0u;
  goto l4;
l3:
  i1 = (OOC_INT32)r;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5530))+4);
  i1 = i1==(OOC_INT32)0;
  
l4:
  i2 = (OOC_INT32)r;
  if (i1) goto l7;
  i0=0;
  goto l21;
l7:
  i1 = start;
  i4=i1;i3=0;
l8_loop:
  ProgramArgs__ReaderDesc_ReadByte((ProgramArgs__Reader)i2, (void*)((OOC_INT32)x+(_check_index(i4, x_0d, OOC_UINT32, 5567))));
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 5590))+4);
  i5 = i5==(OOC_INT32)0;
  if (!i5) goto l12;
  i3 = i3+1;
  i = i3;
  i4 = i4+1;
  
l12:
  i5 = i3<i0;
  if (i5) goto l15;
  i5=0u;
  goto l17;
l15:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 5530))+4);
  i5 = i5==(OOC_INT32)0;
  
l17:
  if (i5) goto l8_loop;
l20:
  i0 = i4-i1;
  
l21:
  *(OOC_INT32*)((_check_pointer(i2, 5649))+8) = i0;
  return;
  ;
}

OOC_INT32 ProgramArgs__ChannelDesc_Length(ProgramArgs__Channel ch) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 i;
  OOC_INT32 len;
  OOC_INT32 j;

  i = 0;
  len = 0;
  i0 = RT0__argc;
  i1 = 0<i0;
  if (i1) goto l3;
  i0=0;
  goto l18;
l3:
  i1 = (OOC_INT32)RT0__argv;
  i2=0;i3=0;
l4_loop:
  j = 0;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5958))+i2*4);
  i4 = *(OOC_UINT8*)(_check_pointer(i4, 5961));
  i4 = i4!=0u;
  if (i4) goto l7;
  i4=0;
  goto l13;
l7:
  i4=0;
l8_loop:
  i4 = i4+1;
  j = i4;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5958))+i2*4);
  i5 = *(OOC_UINT8*)((_check_pointer(i5, 5961))+i4);
  i5 = i5!=0u;
  if (i5) goto l8_loop;
l13:
  i3 = i3+(i4+1);
  len = i3;
  i2 = i2+1;
  i = i2;
  i4 = i2<i0;
  if (i4) goto l4_loop;
l17:
  i0=i3;
l18:
  return i0;
  ;
}

OOC_INT32 ProgramArgs__ChannelDesc_ArgNumber(ProgramArgs__Channel ch) {
  register OOC_INT32 i0;

  i0 = RT0__argc;
  return (i0-1);
  ;
}

void ProgramArgs__ChannelDesc_GetModTime(ProgramArgs__Channel ch, struct Time__TimeStamp *mtime, RT0__Struct mtime__tag) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)ch;
  i1 = (OOC_INT32)ProgramArgs__GetError(12);
  *(OOC_INT32*)(_check_pointer(i0, 6485)) = i1;
  return;
  ;
}

ProgramArgs__Reader ProgramArgs__ChannelDesc_NewReader(ProgramArgs__Channel ch) {
  register OOC_INT32 i0,i1;
  ProgramArgs__Reader r;

  i0 = (OOC_INT32)ch;
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 6621))+6);
  if (i1) goto l3;
  r = (ProgramArgs__Reader)0;
  i1 = (OOC_INT32)ProgramArgs__GetError(6);
  *(OOC_INT32*)(_check_pointer(i0, 6840)) = i1;
  i0=0;
  goto l4;
l3:
  i1 = (OOC_INT32)RT0__NewObject(_td_ProgramArgs__Reader.baseTypes[0]);
  r = (ProgramArgs__Reader)i1;
  *(OOC_INT32*)(_check_pointer(i1, 6655)) = i0;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6676)))), Channel__ReaderDesc_ClearError)),Channel__ReaderDesc_ClearError)((Channel__Reader)i1);
  *(OOC_INT32*)((_check_pointer(i1, 6697))+8) = 1;
  *(OOC_UINT8*)((_check_pointer(i1, 6722))+12) = 1u;
  *(OOC_INT32*)((_check_pointer(i1, 6753))+16) = 0;
  *(OOC_INT32*)((_check_pointer(i1, 6773))+20) = 0;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6794)))), Channel__ChannelDesc_ClearError)),Channel__ChannelDesc_ClearError)((Channel__Channel)i0);
  i0=i1;
l4:
  return (ProgramArgs__Reader)i0;
  ;
}

void ProgramArgs__ChannelDesc_Flush(ProgramArgs__Channel ch) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)ch;
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 6966))+6);
  i1 = !i1;
  if (!i1) goto l4;
  i1 = (OOC_INT32)ProgramArgs__GetError(6);
  *(OOC_INT32*)(_check_pointer(i0, 6986)) = i1;
l4:
  return;
  ;
}

void ProgramArgs__ChannelDesc_Close(ProgramArgs__Channel ch) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)ch;
  *(OOC_UINT8*)((_check_pointer(i0, 7088))+6) = 0u;
  return;
  ;
}

void OOC_ProgramArgs_init(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)RT0__NewObject(_td_ProgramArgs__ErrorContext.baseTypes[0]);
  ProgramArgs__errorContext = (ProgramArgs__ErrorContext)i0;
  Msg__InitContext((Msg__Context)i0, (OOC_CHAR8*)"OOC:Core:ProgramArgs", 21);
  i0 = (OOC_INT32)RT0__NewObject(_td_ProgramArgs__Channel.baseTypes[0]);
  ProgramArgs__args = (ProgramArgs__Channel)i0;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7227)))), Channel__ChannelDesc_ClearError)),Channel__ChannelDesc_ClearError)((Channel__Channel)i0);
  i0 = (OOC_INT32)ProgramArgs__args;
  *(OOC_UINT8*)((_check_pointer(i0, 7247))+4) = 1u;
  *(OOC_UINT8*)((_check_pointer(i0, 7273))+5) = 0u;
  *(OOC_UINT8*)((_check_pointer(i0, 7300))+6) = 1u;
  return;
  ;
}

void OOC_ProgramArgs_destroy(void) {
}

/* --- */
