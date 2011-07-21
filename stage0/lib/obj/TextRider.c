#include <TextRider.d>
#include <__oo2c.h>
#include <setjmp.h>

static Msg__Msg TextRider__GetError(OOC_INT32 code) {
  register OOC_INT32 i0,i1;

  i0 = code;
  i1 = (OOC_INT32)TextRider__errorContext;
  i0 = (OOC_INT32)Msg__New((Msg__Context)i1, i0);
  return (Msg__Msg)i0;
  ;
}

void TextRider__ErrorContextDesc_GetTemplate(TextRider__ErrorContext context, Msg__Msg msg, Msg__LString templ, OOC_LEN templ_0d) {
  register OOC_INT32 i0,i1;
  OOC_CHAR8 str[128];

  i0 = (OOC_INT32)msg;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 7849))+8);
  switch (i1) {
  case 1:
    _copy_8((const void*)"Number exceeded limits or string was too long",(void*)(OOC_INT32)str,128);
    goto l4;
  default:
    _copy_8((const void*)"",(void*)(OOC_INT32)str,128);
    i1 = (OOC_INT32)context;
    Msg__ContextDesc_GetTemplate((Msg__Context)i1, (Msg__Msg)i0, (void*)(OOC_INT32)templ, templ_0d);
    goto l4;
  }
l4:
  i0 = (
  _cmp8((const void*)(OOC_INT32)str,(const void*)""))!=0;
  if (!i0) goto l7;
  _copy_8to16((const void*)(OOC_INT32)str,(void*)(OOC_INT32)templ,templ_0d);
l7:
  return;
  ;
}

static void TextRider__EolDetect(TextRider__Reader r, OOC_CHAR8 ch) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 8342));
  i1 = i1==0;
  if (!i1) goto l15;
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 8371))+20);
  if (i1) goto l9;
  i1 = ch;
  *(OOC_UINT8*)(((_check_pointer(i0, 8667))+16)+(_check_index(0, 2, OOC_UINT8, 8672))) = i1;
  i1 = i1==10u;
  if (i1) goto l7;
  *(OOC_UINT8*)((_check_pointer(i0, 8809))+20) = 1u;
  goto l15;
l7:
  *(OOC_INT16*)((_check_pointer(i0, 8748))+18) = 1;
  goto l15;
l9:
  i1 = ch;
  i2 = i1==10u;
  if (i2) goto l12;
  *(OOC_INT16*)((_check_pointer(i0, 8588))+18) = 1;
  goto l13;
l12:
  *(OOC_UINT8*)(((_check_pointer(i0, 8501))+16)+(_check_index(1, 2, OOC_UINT8, 8506))) = i1;
  *(OOC_INT16*)((_check_pointer(i0, 8528))+18) = 2;
l13:
  *(OOC_UINT8*)((_check_pointer(i0, 8624))+20) = 0u;
l15:
  return;
  ;
}

static OOC_CHAR8 TextRider__Lookahead(TextRider__Reader r, OOC_INT16 len) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_CHAR8 ch;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9466));
  _assert((i1==0), 127, 9457);
  i1 = *(OOC_INT16*)((_check_pointer(i0, 9490))+32);
  i2 = len;
  i1 = i1==0;
  if (i1) goto l3;
  i1 = *(OOC_INT16*)((_check_pointer(i0, 9517))+32);
  i1 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i0, 9508))+24)+(_check_index((i1-1), 2, OOC_UINT16, 9515))*4);
  i1 = i1==0;
  
  goto l5;
l3:
  i1=1u;
l5:
  if (!i1) goto l38;
  i1 = *(OOC_INT16*)((_check_pointer(i0, 9555))+32);
  i1 = i1<i2;
  if (i1) goto l9;
  i1=0u;
  goto l11;
l9:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9574))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 9586))+4);
  i1 = i1==0;
  
l11:
  if (!i1) goto l38;
l13_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9612))+8);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9612))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9624)))), Channel__ReaderDesc_ReadByte)),Channel__ReaderDesc_ReadByte)((Channel__Reader)i3, (void*)(OOC_INT32)&ch);
  i1 = *(OOC_INT16*)((_check_pointer(i0, 9655))+18);
  i1 = i1<0;
  if (i1) goto l16;
  i1=0u;
  goto l26;
l16:
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 9685))+20);
  if (i1) goto l19;
  i1 = ch;
  i1 = i1==10u;
  
  goto l21;
l19:
  i1=1u;
l21:
  if (i1) goto l23;
  i1 = ch;
  i1 = i1==13u;
  
  goto l26;
l23:
  i1=1u;
l26:
  if (!i1) goto l28;
  i1 = ch;
  TextRider__EolDetect((TextRider__Reader)i0, i1);
l28:
  i1 = *(OOC_INT16*)((_check_pointer(i0, 9801))+32);
  i3 = ch;
  *(OOC_UINT8*)(((_check_pointer(i0, 9795))+21)+(_check_index(i1, 2, OOC_UINT16, 9799))) = i3;
  i1 = *(OOC_INT16*)((_check_pointer(i0, 9835))+32);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9848))+8);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 9860))+4);
  *(OOC_INT32*)(((_check_pointer(i0, 9826))+24)+(_check_index(i1, 2, OOC_UINT16, 9833))*4) = i3;
  i1 = *(OOC_INT16*)((_check_pointer(i0, 9881))+32);
  *(OOC_INT16*)((_check_pointer(i0, 9881))+32) = (i1+1);
  i1 = *(OOC_INT16*)((_check_pointer(i0, 9555))+32);
  i1 = i1<i2;
  if (i1) goto l31;
  i1=0u;
  goto l33;
l31:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9574))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 9586))+4);
  i1 = i1==0;
  
l33:
  if (i1) goto l13_loop;
l38:
  i1 = *(OOC_INT16*)((_check_pointer(i0, 9929))+32);
  i1 = i2<=i1;
  if (i1) goto l41;
  i0=0u;
  goto l42;
l41:
  i0 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i0, 9942))+24)+(_check_index((i2-1), 2, OOC_UINT16, 9949))*4);
  i0 = i0==0;
  
l42:
  return i0;
  ;
}

static OOC_CHAR8 TextRider__Consume(TextRider__Reader r) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_CHAR8 ch;
  OOC_INT16 i;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10201));
  i1 = i1==0;
  if (i1) goto l3;
  ch = 0u;
  goto l35;
l3:
  i1 = *(OOC_INT16*)((_check_pointer(i0, 10231))+32);
  i1 = i1>0;
  if (i1) goto l25;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10469))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10469))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10481)))), Channel__ReaderDesc_ReadByte)),Channel__ReaderDesc_ReadByte)((Channel__Reader)i2, (void*)(OOC_INT32)&ch);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10512))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10524))+4);
  i1 = i1!=0;
  if (i1) goto l23;
  i1 = *(OOC_INT16*)((_check_pointer(i0, 10618))+18);
  i1 = i1<0;
  if (i1) goto l10;
  i1=0u;
  goto l20;
l10:
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 10651))+20);
  if (i1) goto l13;
  i1 = ch;
  i1 = i1==10u;
  
  goto l15;
l13:
  i1=1u;
l15:
  if (i1) goto l17;
  i1 = ch;
  i1 = i1==13u;
  
  goto l20;
l17:
  i1=1u;
l20:
  if (!i1) goto l35;
  i1 = ch;
  TextRider__EolDetect((TextRider__Reader)i0, i1);
  goto l35;
l23:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10564))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10576))+4);
  *(OOC_INT32*)(_check_pointer(i0, 10554)) = i1;
  ch = 0u;
  goto l35;
l25:
  i1 = *(OOC_UINT8*)(((_check_pointer(i0, 10264))+21)+(_check_index(0, 2, OOC_UINT8, 10268)));
  ch = i1;
  i1 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i0, 10292))+24)+(_check_index(0, 2, OOC_UINT8, 10299))*4);
  *(OOC_INT32*)(_check_pointer(i0, 10282)) = i1;
  i = 1;
  i1 = *(OOC_INT16*)((_check_pointer(i0, 10327))+32);
  i2 = 1<i1;
  if (!i2) goto l33;
  i2=1;
l28_loop:
  i3 = i2-1;
  i4 = *(OOC_UINT8*)(((_check_pointer(i0, 10365))+21)+(_check_index(i2, 2, OOC_UINT16, 10369)));
  *(OOC_UINT8*)(((_check_pointer(i0, 10351))+21)+(_check_index(i3, 2, OOC_UINT16, 10355))) = i4;
  i4 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i0, 10402))+24)+(_check_index(i2, 2, OOC_UINT16, 10409))*4);
  *(OOC_INT32*)(((_check_pointer(i0, 10385))+24)+(_check_index(i3, 2, OOC_UINT16, 10392))*4) = i4;
  i2 = i2+1;
  i = i2;
  i3 = i2<i1;
  if (i3) goto l28_loop;
l33:
  i1 = *(OOC_INT16*)((_check_pointer(i0, 10440))+32);
  *(OOC_INT16*)((_check_pointer(i0, 10440))+32) = (i1-1);
l35:
  i0 = ch;
  return i0;
  ;
}

OOC_INT32 TextRider__ReaderDesc_Pos(TextRider__Reader r) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11073))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11073))+8);
  i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11084)))), Channel__ReaderDesc_Pos)),Channel__ReaderDesc_Pos)((Channel__Reader)i2);
  i0 = *(OOC_INT16*)((_check_pointer(i0, 11092))+32);
  return (i1-i0);
  ;
}

void TextRider__ReaderDesc_ClearError(TextRider__Reader r) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11160))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11160))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11172)))), Channel__ReaderDesc_ClearError)),Channel__ReaderDesc_ClearError)((Channel__Reader)i2);
  *(OOC_INT32*)(_check_pointer(i0, 11191)) = 0;
  *(OOC_UINT8*)((_check_pointer(i0, 11211))+20) = 0u;
  return;
  ;
}

OOC_INT32 TextRider__ReaderDesc_Available(TextRider__Reader r) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_INT32 avail;
  OOC_INT32 laChars;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11357))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11357))+8);
  i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11369)))), Channel__ReaderDesc_Available)),Channel__ReaderDesc_Available)((Channel__Reader)i2);
  avail = i1;
  laChars = 0;
  i2 = *(OOC_INT16*)((_check_pointer(i0, 11424))+32);
  i2 = 0!=i2;
  if (i2) goto l3;
  i2=0u;
  goto l5;
l3:
  i2 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i0, 11437))+24)+(_check_index(0, 2, OOC_UINT32, 11444))*4);
  i2 = i2==(OOC_INT32)0;
  
l5:
  if (i2) goto l7;
  i0=0;
  goto l17;
l7:
  i2=0;
l8_loop:
  i2 = i2+1;
  laChars = i2;
  i3 = *(OOC_INT16*)((_check_pointer(i0, 11424))+32);
  i3 = i2!=i3;
  if (i3) goto l11;
  i3=0u;
  goto l13;
l11:
  i3 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i0, 11437))+24)+(_check_index(i2, 2, OOC_UINT32, 11444))*4);
  i3 = i3==(OOC_INT32)0;
  
l13:
  if (i3) goto l8_loop;
l16:
  i0=i2;
l17:
  i2 = i1<0;
  if (i2) goto l20;
  i2=0u;
  goto l22;
l20:
  i2 = i0>0;
  
l22:
  if (i2) goto l24;
  return (i1+i0);
  goto l25;
l24:
  return i0;
l25:
  _failed_function(11275); return 0;
  ;
}

void TextRider__ReaderDesc_SetPos(TextRider__Reader r, OOC_INT32 newPos) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 11683));
  i1 = i1==0;
  if (!i1) goto l3;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11709))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11709))+8);
  i3 = newPos;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11721)))), Channel__ReaderDesc_SetPos)),Channel__ReaderDesc_SetPos)((Channel__Reader)i2, i3);
  *(OOC_INT16*)((_check_pointer(i0, 11746))+32) = 0;
  *(OOC_UINT8*)((_check_pointer(i0, 11824))+20) = 0u;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11909))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11921))+4);
  *(OOC_INT32*)(_check_pointer(i0, 11899)) = i1;
l3:
  return;
  ;
}

void TextRider__ReaderDesc_SetOpts(TextRider__Reader r, OOC_UINT32 opts) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)r;
  i1 = opts;
  *(OOC_UINT32*)((_check_pointer(i0, 12053))+4) = i1;
  return;
  ;
}

void TextRider__ReaderDesc_SetEol(TextRider__Reader r, const OOC_CHAR8 marker__ref[], OOC_LEN marker_0d, OOC_INT16 markerLen) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_ALLOCATE_VPAR(marker,OOC_CHAR8 ,marker_0d)
  OOC_INT16 i;

  OOC_INITIALIZE_VPAR(marker__ref,marker,OOC_CHAR8 ,marker_0d)
  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13891));
  i1 = i1==0;
  if (!i1) goto l26;
  i1 = markerLen;
  i2 = i1<1;
  if (i2) goto l5;
  i2=0u;
  goto l7;
l5:
  i2 = i1!=(-1);
  
l7:
  if (i2) goto l9;
  i2 = i1>2;
  
  goto l11;
l9:
  i2=1u;
l11:
  if (i2) goto l24;
  i = 0;
  i2 = 0<i1;
  if (!i2) goto l23;
  i2=0;
l15_loop:
  i3 = *(OOC_UINT8*)((OOC_INT32)marker+(_check_index(i2, marker_0d, OOC_UINT16, 14100)));
  i3 = (OOC_UINT8)i3>=(OOC_UINT8)32u;
  if (!i3) goto l18;
  i3 = (OOC_INT32)TextRider__GetError(8);
  *(OOC_INT32*)(_check_pointer(i0, 14130)) = i3;
l18:
  i3 = *(OOC_UINT8*)((OOC_INT32)marker+(_check_index(i2, marker_0d, OOC_UINT16, 14208)));
  *(OOC_UINT8*)(((_check_pointer(i0, 14190))+16)+(_check_index(i2, 2, OOC_UINT16, 14195))) = i3;
  i2 = i2+1;
  i = i2;
  i3 = i2<i1;
  if (i3) goto l15_loop;
l23:
  *(OOC_INT16*)((_check_pointer(i0, 14234))+18) = i1;
  goto l26;
l24:
  i1 = (OOC_INT32)TextRider__GetError(8);
  *(OOC_INT32*)(_check_pointer(i0, 13998)) = i1;
l26:
  return;
  ;
}

void TextRider__ReaderDesc_ReadChar(TextRider__Reader r, OOC_CHAR8 *ch) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)r;
  i0 = TextRider__Consume((TextRider__Reader)i0);
  *ch = i0;
  return;
  ;
}

OOC_CHAR8 TextRider__ReaderDesc_Eol(TextRider__Reader r) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT16 i;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14774));
  i1 = i1==0;
  if (i1) goto l3;
  return 1u;
  goto l31;
l3:
  i1 = *(OOC_INT16*)((_check_pointer(i0, 14804))+18);
  i1 = i1>0;
  if (i1) goto l14;
  i1 = TextRider__Lookahead((TextRider__Reader)i0, 1);
  if (i1) goto l8;
  return 1u;
  goto l31;
l8:
  i1 = *(OOC_INT16*)((_check_pointer(i0, 15126))+18);
  i1 = i1>0;
  if (i1) goto l11;
  i0 = *(OOC_UINT8*)(((_check_pointer(i0, 15289))+21)+(_check_index(0, 2, OOC_UINT8, 15293)));
  return (i0==13u);
  goto l31;
l11:
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15163)))), TextRider__ReaderDesc_Eol)),TextRider__ReaderDesc_Eol)((TextRider__Reader)i0);
  return i0;
  goto l31;
l14:
  i = 0;
  i1 = *(OOC_INT16*)((_check_pointer(i0, 14846))+18);
  i2 = 0<i1;
  if (!i2) goto l29;
  i2=0;
l17_loop:
  i3 = i2+1;
  i4 = TextRider__Lookahead((TextRider__Reader)i0, i3);
  if (i4) goto l20;
  i2 = *(OOC_INT16*)((_check_pointer(i0, 15019))+32);
  return (i2==1);
  goto l24;
l20:
  i4 = *(OOC_UINT8*)(((_check_pointer(i0, 14925))+16)+(_check_index(i2, 2, OOC_UINT16, 14930)));
  i2 = *(OOC_UINT8*)(((_check_pointer(i0, 14914))+21)+(_check_index(i2, 2, OOC_UINT16, 14918)));
  i2 = i2!=i4;
  if (!i2) goto l24;
  return 0u;
l24:
  i = i3;
  i2 = i3<i1;
  if (!i2) goto l29;
  i2=i3;
  goto l17_loop;
l29:
  return 1u;
l31:
  _failed_function(14507); return 0;
  ;
}

static void TextRider__SkipBlanks(TextRider__Reader r) {
  register OOC_INT32 i0,i1;
  OOC_CHAR8 ch;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 15716));
  i1 = i1==0;
  if (!i1) goto l53;
  i1 = *(OOC_UINT32*)((_check_pointer(i0, 15765))+4);
  i1 = _in(0,i1);
  if (i1) goto l20;
  i1 = TextRider__Lookahead((TextRider__Reader)i0, 1);
  if (i1) goto l7;
  i1=0u;
  goto l9;
l7:
  i1 = *(OOC_UINT8*)(((_check_pointer(i0, 15982))+21)+(_check_index(0, 2, OOC_UINT8, 15986)));
  i1 = (OOC_UINT8)i1<=(OOC_UINT8)32u;
  
l9:
  if (!i1) goto l53;
l10_loop:
  i1 = TextRider__Consume((TextRider__Reader)i0);
  ch = i1;
  i1 = TextRider__Lookahead((TextRider__Reader)i0, 1);
  if (i1) goto l13;
  i1=0u;
  goto l15;
l13:
  i1 = *(OOC_UINT8*)(((_check_pointer(i0, 15982))+21)+(_check_index(0, 2, OOC_UINT8, 15986)));
  i1 = (OOC_UINT8)i1<=(OOC_UINT8)32u;
  
l15:
  if (i1) goto l10_loop;
  goto l53;
l20:
  i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15792)))), TextRider__ReaderDesc_Eol)),TextRider__ReaderDesc_Eol)((TextRider__Reader)i0);
  i1 = !i1;
  if (i1) goto l23;
  i1=0u;
  goto l25;
l23:
  i1 = TextRider__Lookahead((TextRider__Reader)i0, 1);
  
l25:
  if (i1) goto l27;
  i1=0u;
  goto l29;
l27:
  i1 = *(OOC_UINT8*)(((_check_pointer(i0, 15839))+21)+(_check_index(0, 2, OOC_UINT8, 15843)));
  i1 = (OOC_UINT8)i1<=(OOC_UINT8)32u;
  
l29:
  if (i1) goto l31;
  i1=0u;
  goto l33;
l31:
  i1 = *(OOC_UINT8*)(((_check_pointer(i0, 15873))+21)+(_check_index(0, 2, OOC_UINT8, 15877)));
  i1 = i1!=9u;
  
l33:
  if (!i1) goto l53;
l34_loop:
  i1 = TextRider__Consume((TextRider__Reader)i0);
  ch = i1;
  i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15792)))), TextRider__ReaderDesc_Eol)),TextRider__ReaderDesc_Eol)((TextRider__Reader)i0);
  i1 = !i1;
  if (i1) goto l37;
  i1=0u;
  goto l39;
l37:
  i1 = TextRider__Lookahead((TextRider__Reader)i0, 1);
  
l39:
  if (i1) goto l41;
  i1=0u;
  goto l43;
l41:
  i1 = *(OOC_UINT8*)(((_check_pointer(i0, 15839))+21)+(_check_index(0, 2, OOC_UINT8, 15843)));
  i1 = (OOC_UINT8)i1<=(OOC_UINT8)32u;
  
l43:
  if (i1) goto l45;
  i1=0u;
  goto l47;
l45:
  i1 = *(OOC_UINT8*)(((_check_pointer(i0, 15873))+21)+(_check_index(0, 2, OOC_UINT8, 15877)));
  i1 = i1!=9u;
  
l47:
  if (i1) goto l34_loop;
l53:
  return;
  ;
}

static void TextRider__SkipEol(TextRider__Reader r) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)r;
  i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16161)))), TextRider__ReaderDesc_Eol)),TextRider__ReaderDesc_Eol)((TextRider__Reader)i0);
  if (!i1) goto l11;
  i1 = *(OOC_INT16*)((_check_pointer(i0, 16200))+18);
  i1 = _abs(i1);
  i2 = 1<=i1;
  if (!i2) goto l11;
  i2=1;
l5_loop:
  i3 = TextRider__Consume((TextRider__Reader)i0);
  i2 = i2+1;
  i3 = i2<=i1;
  if (i3) goto l5_loop;
l11:
  return;
  ;
}

void TextRider__ReaderDesc_ReadLn(TextRider__Reader r) {
  register OOC_INT32 i0,i1;
  OOC_CHAR8 ch;

  i0 = (OOC_INT32)r;
  i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16464)))), TextRider__ReaderDesc_Eol)),TextRider__ReaderDesc_Eol)((TextRider__Reader)i0);
  i1 = !i1;
  if (!i1) goto l8;
l3_loop:
  i1 = TextRider__Consume((TextRider__Reader)i0);
  ch = i1;
  i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16464)))), TextRider__ReaderDesc_Eol)),TextRider__ReaderDesc_Eol)((TextRider__Reader)i0);
  i1 = !i1;
  if (i1) goto l3_loop;
l8:
  TextRider__SkipEol((TextRider__Reader)i0);
  return;
  ;
}

void TextRider__ReaderDesc_ReadString(TextRider__Reader r, OOC_CHAR8 s[], OOC_LEN s_0d) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT16 cnt;
  OOC_CHAR8 quote;

  i0 = (OOC_INT32)r;
  TextRider__SkipBlanks((TextRider__Reader)i0);
  cnt = 0;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 16905));
  i1 = i1==0;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = TextRider__Lookahead((TextRider__Reader)i0, 1);
  
l5:
  if (i1) goto l7;
  i0 = TextRider__Consume((TextRider__Reader)i0);
  i0=0;
  goto l34;
l7:
  i1 = *(OOC_UINT8*)(((_check_pointer(i0, 16954))+21)+(_check_index(0, 2, OOC_UINT8, 16958)));
  i1 = i1!=34u;
  if (i1) goto l10;
  i1=0u;
  goto l12;
l10:
  i1 = *(OOC_UINT8*)(((_check_pointer(i0, 16973))+21)+(_check_index(0, 2, OOC_UINT8, 16977)));
  i1 = i1!=39u;
  
l12:
  if (i1) goto l32;
  i1 = TextRider__Consume((TextRider__Reader)i0);
  i2 = s_0d-1;
  quote = i1;
  i3=0;
l14_loop:
  i4 = TextRider__Lookahead((TextRider__Reader)i0, 1);
  i4 = !i4;
  if (i4) goto l30;
  i4 = *(OOC_UINT8*)(((_check_pointer(i0, 17218))+21)+(_check_index(0, 2, OOC_UINT8, 17222)));
  i4 = (OOC_UINT8)i4<(OOC_UINT8)32u;
  if (i4) goto l28;
  i4 = *(OOC_UINT8*)(((_check_pointer(i0, 17321))+21)+(_check_index(0, 2, OOC_UINT8, 17325)));
  i4 = i4==i1;
  if (i4) goto l26;
  i4 = i3==i2;
  if (i4) goto l24;
  i4 = TextRider__Consume((TextRider__Reader)i0);
  *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i3, s_0d, OOC_UINT16, 17545))) = i4;
  i3 = i3+1;
  cnt = i3;
  
  goto l14_loop;
l24:
  i1 = (OOC_INT32)TextRider__GetError(1);
  *(OOC_INT32*)(_check_pointer(i0, 17463)) = i1;
  goto l31;
l26:
  i0 = TextRider__Consume((TextRider__Reader)i0);
  goto l31;
l28:
  i1 = (OOC_INT32)TextRider__GetError(8);
  *(OOC_INT32*)(_check_pointer(i0, 17251)) = i1;
  goto l31;
l30:
  i0 = TextRider__Consume((TextRider__Reader)i0);
l31:
  i0=i3;
  goto l34;
l32:
  i1 = (OOC_INT32)TextRider__GetError(8);
  *(OOC_INT32*)(_check_pointer(i0, 17002)) = i1;
  i0=0;
l34:
  *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i0, s_0d, OOC_UINT16, 17703))) = 0u;
  return;
  ;
}

void TextRider__ReaderDesc_ReadLine(TextRider__Reader r, OOC_CHAR8 s[], OOC_LEN s_0d) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_CHAR8 dummy;
  OOC_INT16 cnt;

  i0 = (OOC_INT32)r;
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 18226))+20);
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = TextRider__Lookahead((TextRider__Reader)i0, 1);
  
l5:
  if (i1) goto l7;
  i1=0u;
  goto l9;
l7:
  i1 = *(OOC_UINT8*)(((_check_pointer(i0, 18263))+21)+(_check_index(0, 2, OOC_UINT8, 18267)));
  i1 = i1==10u;
  
l9:
  if (!i1) goto l11;
  i1 = TextRider__Consume((TextRider__Reader)i0);
  dummy = i1;
l11:
  cnt = 0;
  i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18388)))), TextRider__ReaderDesc_Eol)),TextRider__ReaderDesc_Eol)((TextRider__Reader)i0);
  i1 = !i1;
  if (i1) goto l14;
  i1=0u;
  goto l16;
l14:
  i1 = TextRider__Lookahead((TextRider__Reader)i0, 1);
  
l16:
  if (i1) goto l18;
  i1=0u;
  goto l20;
l18:
  i1 = 0!=(s_0d-1);
  
l20:
  if (i1) goto l22;
  i1=0;
  goto l36;
l22:
  i1 = s_0d-1;
  i2=0;
l23_loop:
  i3 = TextRider__Consume((TextRider__Reader)i0);
  *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i2, s_0d, OOC_UINT16, 18445))) = i3;
  i2 = i2+1;
  cnt = i2;
  i3 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18388)))), TextRider__ReaderDesc_Eol)),TextRider__ReaderDesc_Eol)((TextRider__Reader)i0);
  i3 = !i3;
  if (i3) goto l26;
  i3=0u;
  goto l28;
l26:
  i3 = TextRider__Lookahead((TextRider__Reader)i0, 1);
  
l28:
  if (i3) goto l30;
  i3=0u;
  goto l32;
l30:
  i3 = i2!=i1;
  
l32:
  if (i3) goto l23_loop;
l35:
  i1=i2;
l36:
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18505)))), TextRider__ReaderDesc_Eol)),TextRider__ReaderDesc_Eol)((TextRider__Reader)i0);
  if (i2) goto l42;
  i2 = i1==(s_0d-1);
  if (!i2) goto l43;
  i2 = (OOC_INT32)TextRider__GetError(1);
  *(OOC_INT32*)(_check_pointer(i0, 18577)) = i2;
  goto l43;
l42:
  TextRider__SkipEol((TextRider__Reader)i0);
l43:
  *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i1, s_0d, OOC_UINT16, 18627))) = 0u;
  return;
  ;
}

void TextRider__ReaderDesc_ReadIdentifier(TextRider__Reader r, OOC_CHAR8 s[], OOC_LEN s_0d) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_INT16 cnt;

  i0 = (OOC_INT32)r;
  TextRider__SkipBlanks((TextRider__Reader)i0);
  cnt = 0;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 18922));
  i1 = i1==0;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = TextRider__Lookahead((TextRider__Reader)i0, 1);
  
l5:
  if (i1) goto l7;
  i0 = TextRider__Consume((TextRider__Reader)i0);
  i0=0;
  goto l30;
l7:
  i1 = *(OOC_UINT8*)(((_check_pointer(i0, 18990))+21)+(_check_index(0, 2, OOC_UINT8, 18994)));
  i1 = CharClass__IsLetter(i1);
  i1 = !i1;
  if (i1) goto l28;
  i1 = TextRider__Consume((TextRider__Reader)i0);
  *(OOC_UINT8*)((OOC_INT32)s+(_check_index(0, s_0d, OOC_UINT8, 19067))) = i1;
  i1 = s_0d-1;
  cnt = 1;
  i2=1;
l10_loop:
  i3 = TextRider__Lookahead((TextRider__Reader)i0, 1);
  if (i3) goto l13;
  i3=0u;
  goto l18;
l13:
  i3 = *(OOC_UINT8*)(((_check_pointer(i0, 19188))+21)+(_check_index(0, 2, OOC_UINT8, 19192)));
  i3 = CharClass__IsLetter(i3);
  if (i3) goto l16;
  i3 = *(OOC_UINT8*)(((_check_pointer(i0, 19237))+21)+(_check_index(0, 2, OOC_UINT8, 19241)));
  i3 = CharClass__IsNumeric(i3);
  
  goto l18;
l16:
  i3=1u;
l18:
  i3 = !i3;
  if (i3) goto l27;
  i3 = i2==i1;
  if (i3) goto l24;
  i3 = TextRider__Consume((TextRider__Reader)i0);
  *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i2, s_0d, OOC_UINT16, 19404))) = i3;
  i2 = i2+1;
  cnt = i2;
  
  goto l10_loop;
l24:
  i1 = (OOC_INT32)TextRider__GetError(1);
  *(OOC_INT32*)(_check_pointer(i0, 19322)) = i1;
l27:
  i0=i2;
  goto l30;
l28:
  i1 = (OOC_INT32)TextRider__GetError(8);
  *(OOC_INT32*)(_check_pointer(i0, 19013)) = i1;
  i0=0;
l30:
  *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i0, s_0d, OOC_UINT16, 19559))) = 0u;
  return;
  ;
}

void TextRider__ReaderDesc_ReadBool(TextRider__Reader r, OOC_CHAR8 *_bool) {
  register OOC_INT32 i0,i1;
  OOC_CHAR8 ident[8];

  i0 = (OOC_INT32)r;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19962)))), TextRider__ReaderDesc_ReadIdentifier)),TextRider__ReaderDesc_ReadIdentifier)((TextRider__Reader)i0, (void*)(OOC_INT32)ident, 8);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 19997));
  i1 = i1==0;
  if (!i1) goto l11;
  i1 = (
  _cmp8((const void*)(OOC_INT32)ident,(const void*)"TRUE"))==0;
  if (i1) goto l9;
  i1 = (
  _cmp8((const void*)(OOC_INT32)ident,(const void*)"FALSE"))==0;
  if (i1) goto l7;
  i1 = (OOC_INT32)TextRider__GetError(8);
  *(OOC_INT32*)(_check_pointer(i0, 20145)) = i1;
  goto l11;
l7:
  *_bool = 0u;
  goto l11;
l9:
  *_bool = 1u;
l11:
  return;
  ;
}

static OOC_CHAR8 TextRider__HexDigit(OOC_CHAR8 ch) {
  register OOC_INT32 i0,i1;

  i0 = ch;
  i1 = (OOC_UINT8)i0>=(OOC_UINT8)48u;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_UINT8)i0<=(OOC_UINT8)57u;
  
l5:
  if (i1) goto l11;
  i1 = (OOC_UINT8)i0>=(OOC_UINT8)65u;
  if (i1) goto l9;
  i0=0u;
  goto l12;
l9:
  i0 = (OOC_UINT8)i0<=(OOC_UINT8)70u;
  
  goto l12;
l11:
  i0=1u;
l12:
  return i0;
  ;
}

static OOC_CHAR8 TextRider__HexToInt(const OOC_CHAR8 str__ref[], OOC_LEN str_0d, OOC_INT32 *lint) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_ALLOCATE_VPAR(str,OOC_CHAR8 ,str_0d)
  OOC_INT16 spos;
  OOC_INT16 epos;
  auto OOC_INT16 TextRider__HexToInt_GetDigit(OOC_CHAR8 c);
    
    OOC_INT16 TextRider__HexToInt_GetDigit(OOC_CHAR8 c) {
      register OOC_INT32 i0,i1;

      i0 = c;
      i1 = 48<=i0;
      if (i1) goto l3;
      i1=0u;
      goto l5;
l3:
      i1 = (OOC_UINT8)i0<=(OOC_UINT8)57;
      
l5:
      if (i1) goto l7;
      i0 = i0-55;
      
      goto l8;
l7:
      i0 = i0-48;
      
l8:
      return i0;
      ;
    }


  OOC_INITIALIZE_VPAR(str__ref,str,OOC_CHAR8 ,str_0d)
  *lint = 0;
  spos = 0;
  i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT16, 21296)));
  i0 = i0!=0u;
  if (i0) goto l3;
  i0=0;
  goto l9;
l3:
  i0=0;
l4_loop:
  i0 = i0+1;
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT16, 21296)));
  i1 = i1!=0u;
  if (i1) goto l4_loop;
l9:
  i1 = i0-1;
  epos = i1;
  i2 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT16, 21403)));
  i2 = i2==48u;
  if (i2) goto l12;
  i2=0;
  goto l18;
l12:
  i2=0;
l13_loop:
  i2 = i2+1;
  spos = i2;
  i3 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i2, str_0d, OOC_UINT16, 21403)));
  i3 = i3==48u;
  if (i3) goto l13_loop;
l18:
  i3 = (i1-i2)>7;
  if (i3) goto l40;
  i3 = i2<i0;
  if (!i3) goto l41;
  i3 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i2, str_0d, OOC_UINT16, 21691)));
  i3 = TextRider__HexToInt_GetDigit(i3);
  *lint = i3;
  i2 = i2+1;
  spos = i2;
  i4 = (i1-i2)==6;
  if (i4) goto l25;
  i4=0u;
  goto l27;
l25:
  i4 = i3>=8;
  
l27:
  if (!i4) goto l30;
  i3 = i3-16;
  *lint = i3;
  
l30:
  i4 = i2<i0;
  if (!i4) goto l41;
  {register OOC_INT32 h0=i2;i2=i3;i3=h0;}
l33_loop:
  i4 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i3, str_0d, OOC_UINT16, 22081)));
  i4 = TextRider__HexToInt_GetDigit(i4);
  i2 = (i2*16)+i4;
  *lint = i2;
  i3 = i3+1;
  spos = i3;
  i4 = i3<i0;
  if (i4) goto l33_loop;
  goto l41;
l40:
  return 0u;
l41:
  return (i1>=0);
  ;
}

void TextRider__ReaderDesc_ReadLInt(TextRider__Reader r, OOC_INT32 *lint) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT16 pos;
  OOC_CHAR8 str[14];
  OOC_CHAR8 ch;
  OOC_CHAR8 ignoreZeros;
  OOC_INT8 res;

  i0 = (OOC_INT32)r;
  TextRider__SkipBlanks((TextRider__Reader)i0);
  pos = 0;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 22712));
  i1 = i1==0;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = TextRider__Lookahead((TextRider__Reader)i0, 1);
  
l5:
  if (i1) goto l7;
  i0 = TextRider__Consume((TextRider__Reader)i0);
  goto l56;
l7:
  i1 = *(OOC_UINT8*)(((_check_pointer(i0, 22761))+21)+(_check_index(0, 2, OOC_UINT8, 22765)));
  i1 = i1==43u;
  if (i1) goto l10;
  i1 = *(OOC_UINT8*)(((_check_pointer(i0, 22781))+21)+(_check_index(0, 2, OOC_UINT8, 22785)));
  i1 = i1==45u;
  
  goto l12;
l10:
  i1=1u;
l12:
  if (i1) goto l14;
  i1=0;
  goto l18;
l14:
  i1 = TextRider__Consume((TextRider__Reader)i0);
  *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, 14, OOC_UINT8, 22812))) = i1;
  pos = 1;
  i1 = TextRider__Lookahead((TextRider__Reader)i0, 1);
  i1 = !i1;
  if (!i1) goto l17;
  i1 = TextRider__Consume((TextRider__Reader)i0);
  return;
l17:
  i1=1;
l18:
  i2 = *(OOC_UINT8*)(((_check_pointer(i0, 23021))+21)+(_check_index(0, 2, OOC_UINT8, 23025)));
  i2 = CharClass__IsNumeric(i2);
  if (i2) goto l21;
  i1 = (OOC_INT32)TextRider__GetError(8);
  *(OOC_INT32*)(_check_pointer(i0, 24064)) = i1;
  goto l56;
l21:
  *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i1, 14, OOC_UINT16, 23046))) = 48u;
  i1 = i1+1;
  pos = i1;
  ignoreZeros = 1u;
  i2=i1;i1=1u;
l22_loop:
  i3 = TextRider__Lookahead((TextRider__Reader)i0, 1);
  if (i3) goto l25;
  i3=0u;
  goto l26;
l25:
  i3 = *(OOC_UINT8*)(((_check_pointer(i0, 23176))+21)+(_check_index(0, 2, OOC_UINT8, 23180)));
  i3 = CharClass__IsNumeric(i3);
  
l26:
  i3 = !i3;
  if (i3) goto l43;
  i3 = TextRider__Consume((TextRider__Reader)i0);
  ch = i3;
  i4 = !i1;
  if (i4) goto l31;
  i4 = i3!=48u;
  
  goto l33;
l31:
  i4=1u;
l33:
  if (!i4) goto l22_loop;
  i1 = i2!=14;
  if (i1) goto l38;
  i1=i2;
  goto l39;
l38:
  *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i2, 14, OOC_UINT16, 23464))) = i3;
  i1 = i2+1;
  pos = i1;
  
l39:
  ignoreZeros = 0u;
  i2=i1;i1=0u;
  goto l22_loop;
l43:
  i1 = i2==14;
  if (i1) goto l46;
  *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i2, 14, OOC_UINT16, 23740))) = 0u;
  IntStr__StrToInt((void*)(OOC_INT32)str, 14, (void*)(OOC_INT32)lint, (void*)(OOC_INT32)&res);
  goto l47;
l46:
  res = 1;
l47:
  i1 = res;
  i2 = i1==1;
  if (i2) goto l53;
  i1 = i1!=0;
  if (!i1) goto l56;
  i1 = (OOC_INT32)TextRider__GetError(8);
  *(OOC_INT32*)(_check_pointer(i0, 23998)) = i1;
  goto l56;
l53:
  i1 = (OOC_INT32)TextRider__GetError(1);
  *(OOC_INT32*)(_check_pointer(i0, 23905)) = i1;
l56:
  return;
  ;
}

void TextRider__ReaderDesc_ReadHex(TextRider__Reader r, OOC_INT32 *lint) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT16 pos;
  OOC_CHAR8 str[11];
  OOC_CHAR8 ignoreZeros;
  OOC_CHAR8 ch;

  i0 = (OOC_INT32)r;
  TextRider__SkipBlanks((TextRider__Reader)i0);
  pos = 0;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 25033));
  i1 = i1==0;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = TextRider__Lookahead((TextRider__Reader)i0, 1);
  
l5:
  if (i1) goto l7;
  i0 = TextRider__Consume((TextRider__Reader)i0);
  goto l41;
l7:
  i1 = *(OOC_UINT8*)(((_check_pointer(i0, 25101))+21)+(_check_index(0, 2, OOC_UINT8, 25105)));
  i1 = CharClass__IsNumeric(i1);
  if (i1) goto l10;
  i1 = (OOC_INT32)TextRider__GetError(8);
  *(OOC_INT32*)(_check_pointer(i0, 25963)) = i1;
  goto l41;
l10:
  *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, 11, OOC_UINT16, 25126))) = 48u;
  pos = 1;
  ignoreZeros = 1u;
  i1=1u;i2=1;
l11_loop:
  i3 = TextRider__Lookahead((TextRider__Reader)i0, 1);
  if (i3) goto l14;
  i3=0u;
  goto l15;
l14:
  i3 = *(OOC_UINT8*)(((_check_pointer(i0, 25246))+21)+(_check_index(0, 2, OOC_UINT8, 25250)));
  i3 = TextRider__HexDigit(i3);
  
l15:
  i3 = !i3;
  if (i3) goto l32;
  i3 = TextRider__Consume((TextRider__Reader)i0);
  ch = i3;
  i4 = !i1;
  if (i4) goto l20;
  i4 = i3!=48u;
  
  goto l22;
l20:
  i4=1u;
l22:
  if (!i4) goto l11_loop;
  i1 = i2!=11;
  if (i1) goto l27;
  i1=i2;
  goto l28;
l27:
  *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i2, 11, OOC_UINT16, 25534))) = i3;
  i1 = i2+1;
  pos = i1;
  
l28:
  ignoreZeros = 0u;
  i2=i1;i1=0u;
  goto l11_loop;
l32:
  i1 = i2==11;
  if (i1) goto l38;
  *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i2, 11, OOC_UINT16, 25816))) = 0u;
  i1 = TextRider__HexToInt((void*)(OOC_INT32)str, 11, (void*)(OOC_INT32)lint);
  i1 = !i1;
  if (!i1) goto l41;
  i1 = (OOC_INT32)TextRider__GetError(1);
  *(OOC_INT32*)(_check_pointer(i0, 25881)) = i1;
  goto l41;
l38:
  i1 = (OOC_INT32)TextRider__GetError(1);
  *(OOC_INT32*)(_check_pointer(i0, 25754)) = i1;
l41:
  return;
  ;
}

void TextRider__ReaderDesc_ReadInt(TextRider__Reader r, OOC_INT16 *_int) {
  register OOC_INT32 i0,i1,i2;
  OOC_INT32 lint;

  i0 = (OOC_INT32)r;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26212)))), TextRider__ReaderDesc_ReadLInt)),TextRider__ReaderDesc_ReadLInt)((TextRider__Reader)i0, (void*)(OOC_INT32)&lint);
  i1 = lint;
  i2 = i1>32767;
  if (i2) goto l3;
  i2 = i1<(-32768);
  
  goto l5;
l3:
  i2=1u;
l5:
  if (i2) goto l7;
  *_int = i1;
  goto l8;
l7:
  i1 = (OOC_INT32)TextRider__GetError(1);
  *(OOC_INT32*)(_check_pointer(i0, 26291)) = i1;
l8:
  return;
  ;
}

void TextRider__ReaderDesc_ReadSInt(TextRider__Reader r, OOC_INT8 *sint) {
  register OOC_INT32 i0,i1,i2;
  OOC_INT32 lint;

  i0 = (OOC_INT32)r;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26513)))), TextRider__ReaderDesc_ReadLInt)),TextRider__ReaderDesc_ReadLInt)((TextRider__Reader)i0, (void*)(OOC_INT32)&lint);
  i1 = lint;
  i2 = i1>127;
  if (i2) goto l3;
  i2 = i1<(-128);
  
  goto l5;
l3:
  i2=1u;
l5:
  if (i2) goto l7;
  *sint = i1;
  goto l8;
l7:
  i1 = (OOC_INT32)TextRider__GetError(1);
  *(OOC_INT32*)(_check_pointer(i0, 26594)) = i1;
l8:
  return;
  ;
}

void TextRider__ReaderDesc_ReadLReal(TextRider__Reader r, OOC_REAL64 *lreal) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_INT16 pos;
  ConvTypes__ScanState state;
  OOC_INT8 _class;
  OOC_CHAR8 str[1024];
  OOC_INT8 res;

  i0 = (OOC_INT32)r;
  TextRider__SkipBlanks((TextRider__Reader)i0);
  pos = 0;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 27454));
  i1 = i1==0;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = TextRider__Lookahead((TextRider__Reader)i0, 1);
  
l5:
  if (i1) goto l7;
  i0 = TextRider__Consume((TextRider__Reader)i0);
  goto l36;
l7:
  i1 = *(OOC_UINT8*)(((_check_pointer(i0, 27518))+21)+(_check_index(0, 2, OOC_UINT8, 27522)));
  LRealConv__ScanReal(i1, (void*)(OOC_INT32)&_class, (void*)(OOC_INT32)&state);
  i1 = _class;
  i1 = i1==1;
  if (i1) goto l10;
  i1 = (OOC_INT32)TextRider__GetError(8);
  *(OOC_INT32*)(_check_pointer(i0, 28513)) = i1;
  goto l36;
l10:
  i1 = TextRider__Consume((TextRider__Reader)i0);
  *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, 1024, OOC_UINT8, 27600))) = i1;
  pos = 1;
  i1=1;
l11_loop:
  i2 = TextRider__Lookahead((TextRider__Reader)i0, 1);
  i2 = !i2;
  if (i2) goto l23;
  i2 = (OOC_INT32)state;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 27737));
  i3 = *(OOC_UINT8*)(((_check_pointer(i0, 27742))+21)+(_check_index(0, 2, OOC_UINT8, 27746)));
  ((void (*)(OOC_CHAR8 ch, OOC_INT8 *cl, ConvTypes__ScanState *st))i2)(i3, (void*)(OOC_INT32)&_class, (void*)(OOC_INT32)&state);
  i2 = _class;
  i2 = i2==1;
  if (!i2) goto l23;
  i2 = i1<1024;
  if (i2) goto l18;
  goto l19;
l18:
  i2 = TextRider__Consume((TextRider__Reader)i0);
  *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i1, 1024, OOC_UINT16, 27868))) = i2;
l19:
  i1 = i1+1;
  pos = i1;
  
  goto l11_loop;
l23:
  i2 = i1<1024;
  if (i2) goto l26;
  i1 = (OOC_INT32)TextRider__GetError(8);
  *(OOC_INT32*)(_check_pointer(i0, 28438)) = i1;
  goto l36;
l26:
  *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i1, 1024, OOC_UINT16, 28104))) = 0u;
  LRealStr__StrToReal((void*)(OOC_INT32)str, 1024, (void*)(OOC_INT32)lreal, (void*)(OOC_INT32)&res);
  i1 = res;
  i2 = i1==1;
  if (i2) goto l32;
  i1 = i1!=0;
  if (!i1) goto l36;
  i1 = (OOC_INT32)TextRider__GetError(8);
  *(OOC_INT32*)(_check_pointer(i0, 28366)) = i1;
  goto l36;
l32:
  i1 = (OOC_INT32)TextRider__GetError(1);
  *(OOC_INT32*)(_check_pointer(i0, 28267)) = i1;
l36:
  return;
  ;
}

void TextRider__ReaderDesc_ReadReal(TextRider__Reader r, OOC_REAL32 *real) {
  register OOC_INT32 i0,i1;
  register OOC_REAL64 d0;
  OOC_REAL64 n;
  auto OOC_CHAR8 TextRider__ReaderDesc_ReadReal_ValidReal(OOC_REAL64 value);
    
    OOC_CHAR8 TextRider__ReaderDesc_ReadReal_ValidReal(OOC_REAL64 value) {
      register OOC_INT32 i0;
      register OOC_REAL64 d0;

      d0 = value;
      i0 = (-3.4028235677973366E+38)<d0;
      if (i0) goto l3;
      i0=0u;
      goto l4;
l3:
      i0 = d0<3.4028235677973366E+38;
      
l4:
      return i0;
      ;
    }


  i0 = (OOC_INT32)r;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 29418)))), TextRider__ReaderDesc_ReadLReal)),TextRider__ReaderDesc_ReadLReal)((TextRider__Reader)i0, (void*)(OOC_INT32)&n);
  d0 = n;
  i1 = TextRider__ReaderDesc_ReadReal_ValidReal(d0);
  if (i1) goto l3;
  i1 = (OOC_INT32)TextRider__GetError(1);
  *(OOC_INT32*)(_check_pointer(i0, 29498)) = i1;
  goto l4;
l3:
  *real = ((OOC_REAL32)d0);
l4:
  return;
  ;
}

void TextRider__ReaderDesc_ReadSet(TextRider__Reader r, OOC_UINT32 *s) {
  register OOC_INT32 i0,i1,i2;
  OOC_CHAR8 ch;
  auto OOC_UINT32 TextRider__ReaderDesc_ReadSet_ReadRange(void);
    
    OOC_UINT32 TextRider__ReaderDesc_ReadSet_ReadRange(void) {
      register OOC_INT32 i0,i1,i2;
      OOC_INT8 low;
      OOC_INT8 high;

      i0 = (OOC_INT32)r;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 29778)))), TextRider__ReaderDesc_ReadSInt)),TextRider__ReaderDesc_ReadSInt)((TextRider__Reader)i0, (void*)(OOC_INT32)&low);
      i0 = low;
      high = i0;
      i1 = (OOC_INT32)r;
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 29833));
      i2 = i2==0;
      if (!i2) goto l37;
      i2 = i0<0;
      if (i2) goto l5;
      i0 = i0>31;
      
      goto l7;
l5:
      i0=1u;
l7:
      if (i0) goto l35;
      i0 = TextRider__Lookahead((TextRider__Reader)i1, 2);
      if (i0) goto l11;
      i0=0u;
      goto l13;
l11:
      i0 = (OOC_INT32)r;
      i0 = *(OOC_UINT8*)(((_check_pointer(i0, 30004))+21)+(_check_index(0, 2, OOC_UINT8, 30008)));
      i0 = i0==46u;
      
l13:
      if (i0) goto l15;
      i0=0u;
      goto l17;
l15:
      i0 = (OOC_INT32)r;
      i0 = *(OOC_UINT8*)(((_check_pointer(i0, 30023))+21)+(_check_index(1, 2, OOC_UINT8, 30027)));
      i0 = i0==46u;
      
l17:
      if (!i0) goto l37;
      i0 = (OOC_INT32)r;
      i0 = TextRider__Consume((TextRider__Reader)i0);
      ch = i0;
      i0 = (OOC_INT32)r;
      i0 = TextRider__Consume((TextRider__Reader)i0);
      ch = i0;
      i0 = (OOC_INT32)r;
      TextRider__SkipBlanks((TextRider__Reader)i0);
      i0 = (OOC_INT32)r;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 30138)))), TextRider__ReaderDesc_ReadSInt)),TextRider__ReaderDesc_ReadSInt)((TextRider__Reader)i0, (void*)(OOC_INT32)&high);
      i0 = (OOC_INT32)r;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 30172));
      i1 = i1==0;
      if (i1) goto l21;
      i1=0u;
      goto l31;
l21:
      i1 = high;
      i2 = i1<0;
      if (i2) goto l24;
      i2 = i1>31;
      
      goto l26;
l24:
      i2=1u;
l26:
      if (i2) goto l28;
      i2 = low;
      i1 = i1<i2;
      
      goto l31;
l28:
      i1=1u;
l31:
      if (!i1) goto l37;
      i1 = (OOC_INT32)TextRider__GetError(1);
      *(OOC_INT32*)(_check_pointer(i0, 30271)) = i1;
      return 0u;
      goto l37;
l35:
      i0 = (OOC_INT32)TextRider__GetError(1);
      *(OOC_INT32*)(_check_pointer(i1, 29912)) = i0;
      return 0u;
l37:
      i0 = (OOC_INT32)r;
      TextRider__SkipBlanks((TextRider__Reader)i0);
      i0 = low;
      i1 = high;
      return (_bit_range(i0,i1));
      ;
    }


  i0 = (OOC_INT32)r;
  TextRider__SkipBlanks((TextRider__Reader)i0);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 30507));
  i1 = i1==0;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = TextRider__Lookahead((TextRider__Reader)i0, 1);
  
l5:
  if (i1) goto l7;
  i0 = TextRider__Consume((TextRider__Reader)i0);
  goto l57;
l7:
  i1 = *(OOC_UINT8*)(((_check_pointer(i0, 30556))+21)+(_check_index(0, 2, OOC_UINT8, 30560)));
  i1 = i1==123u;
  if (i1) goto l10;
  i1 = (OOC_INT32)TextRider__GetError(8);
  *(OOC_INT32*)(_check_pointer(i0, 31223)) = i1;
  goto l57;
l10:
  *s = 0u;
  i1 = TextRider__Consume((TextRider__Reader)i0);
  ch = i1;
  TextRider__SkipBlanks((TextRider__Reader)i0);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 30657));
  i1 = i1==0;
  if (i1) goto l13;
  i1=0u;
  goto l15;
l13:
  i1 = TextRider__Lookahead((TextRider__Reader)i0, 1);
  
l15:
  if (i1) goto l17;
  i0 = TextRider__Consume((TextRider__Reader)i0);
  goto l57;
l17:
  i1 = *(OOC_UINT8*)(((_check_pointer(i0, 30710))+21)+(_check_index(0, 2, OOC_UINT8, 30714)));
  i1 = i1!=125u;
  if (!i1) goto l46;
  i0 = TextRider__ReaderDesc_ReadSet_ReadRange();
  i0 = 0u|i0;
  *s = i0;
  i1 = (OOC_INT32)r;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 30784));
  i2 = i2==0;
  if (i2) goto l23;
  i2=0u;
  goto l25;
l23:
  i2 = TextRider__Lookahead((TextRider__Reader)i1, 1);
  
l25:
  if (i2) goto l27;
  i2=0u;
  goto l29;
l27:
  i2 = *(OOC_UINT8*)(((_check_pointer(i1, 30821))+21)+(_check_index(0, 2, OOC_UINT8, 30825)));
  i2 = i2==44u;
  
l29:
  if (i2) goto l31;
  i0=i1;
  goto l46;
l31:
  {register OOC_INT32 h0=i0;i0=i1;i1=h0;}
l32_loop:
  i2 = TextRider__Consume((TextRider__Reader)i0);
  ch = i2;
  TextRider__SkipBlanks((TextRider__Reader)i0);
  i0 = TextRider__ReaderDesc_ReadSet_ReadRange();
  i0 = i1|i0;
  *s = i0;
  i1 = (OOC_INT32)r;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 30784));
  i2 = i2==0;
  if (i2) goto l35;
  i2=0u;
  goto l37;
l35:
  i2 = TextRider__Lookahead((TextRider__Reader)i1, 1);
  
l37:
  if (i2) goto l39;
  i2=0u;
  goto l41;
l39:
  i2 = *(OOC_UINT8*)(((_check_pointer(i1, 30821))+21)+(_check_index(0, 2, OOC_UINT8, 30825)));
  i2 = i2==44u;
  
l41:
  if (!i2) goto l44;
  {register OOC_INT32 h0=i0;i0=i1;i1=h0;}
  goto l32_loop;
l44:
  i0=i1;
l46:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 30983));
  i1 = i1==0;
  if (i1) goto l49;
  i1=0u;
  goto l51;
l49:
  i1 = *(OOC_UINT8*)(((_check_pointer(i0, 31001))+21)+(_check_index(0, 2, OOC_UINT8, 31005)));
  i1 = i1==125u;
  
l51:
  if (i1) goto l53;
  i1 = (OOC_INT32)TextRider__GetError(8);
  *(OOC_INT32*)(_check_pointer(i0, 31079)) = i1;
  goto l57;
l53:
  i0 = TextRider__Consume((TextRider__Reader)i0);
l57:
  return;
  ;
}

static void TextRider__SkipSpaces(TextRider__Scanner s) {
  register OOC_INT32 i0,i1,i2;
  OOC_CHAR8 ch;

  i0 = (OOC_INT32)s;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 31808));
  _assert((i1==0), 127, 31799);
  i1 = *(OOC_UINT32*)((_check_pointer(i0, 31851))+12);
  i1 = _in(0,i1);
  if (i1) goto l23;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32061))+4);
  i1 = TextRider__Lookahead((TextRider__Reader)i1, 1);
  if (i1) goto l5;
  i1=0u;
  goto l7;
l5:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32073))+4);
  i1 = *(OOC_UINT8*)(((_check_pointer(i1, 32076))+21)+(_check_index(0, 2, OOC_UINT8, 32080)));
  i1 = (OOC_UINT8)i1<=(OOC_UINT8)32u;
  
l7:
  if (!i1) goto l55;
l9_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32107))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32107))+4);
  i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 32110)))), TextRider__ReaderDesc_Eol)),TextRider__ReaderDesc_Eol)((TextRider__Reader)i2);
  if (i1) goto l12;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32213))+4);
  i1 = TextRider__Consume((TextRider__Reader)i1);
  ch = i1;
  goto l13;
l12:
  i1 = *(OOC_INT32*)((_check_pointer(i0, 32139))+24);
  *(OOC_INT32*)((_check_pointer(i0, 32139))+24) = (i1+1);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32169))+4);
  TextRider__SkipEol((TextRider__Reader)i1);
l13:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32061))+4);
  i1 = TextRider__Lookahead((TextRider__Reader)i1, 1);
  if (i1) goto l16;
  i1=0u;
  goto l18;
l16:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32073))+4);
  i1 = *(OOC_UINT8*)(((_check_pointer(i1, 32076))+21)+(_check_index(0, 2, OOC_UINT8, 32080)));
  i1 = (OOC_UINT8)i1<=(OOC_UINT8)32u;
  
l18:
  if (i1) goto l9_loop;
  goto l55;
l23:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31877))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31877))+4);
  i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 31880)))), TextRider__ReaderDesc_Eol)),TextRider__ReaderDesc_Eol)((TextRider__Reader)i2);
  i1 = !i1;
  if (i1) goto l26;
  i1=0u;
  goto l28;
l26:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31903))+4);
  i1 = TextRider__Lookahead((TextRider__Reader)i1, 1);
  
l28:
  if (i1) goto l30;
  i1=0u;
  goto l32;
l30:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31928))+4);
  i1 = *(OOC_UINT8*)(((_check_pointer(i1, 31931))+21)+(_check_index(0, 2, OOC_UINT8, 31935)));
  i1 = (OOC_UINT8)i1<=(OOC_UINT8)32u;
  
l32:
  if (i1) goto l34;
  i1=0u;
  goto l36;
l34:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31963))+4);
  i1 = *(OOC_UINT8*)(((_check_pointer(i1, 31966))+21)+(_check_index(0, 2, OOC_UINT8, 31970)));
  i1 = i1!=9u;
  
l36:
  if (!i1) goto l55;
l37_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32013))+4);
  i1 = TextRider__Consume((TextRider__Reader)i1);
  ch = i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31877))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31877))+4);
  i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 31880)))), TextRider__ReaderDesc_Eol)),TextRider__ReaderDesc_Eol)((TextRider__Reader)i2);
  i1 = !i1;
  if (i1) goto l40;
  i1=0u;
  goto l42;
l40:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31903))+4);
  i1 = TextRider__Lookahead((TextRider__Reader)i1, 1);
  
l42:
  if (i1) goto l44;
  i1=0u;
  goto l46;
l44:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31928))+4);
  i1 = *(OOC_UINT8*)(((_check_pointer(i1, 31931))+21)+(_check_index(0, 2, OOC_UINT8, 31935)));
  i1 = (OOC_UINT8)i1<=(OOC_UINT8)32u;
  
l46:
  if (i1) goto l48;
  i1=0u;
  goto l50;
l48:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31963))+4);
  i1 = *(OOC_UINT8*)(((_check_pointer(i1, 31966))+21)+(_check_index(0, 2, OOC_UINT8, 31970)));
  i1 = i1!=9u;
  
l50:
  if (i1) goto l37_loop;
l55:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32264))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 32267));
  *(OOC_INT32*)(_check_pointer(i0, 32254)) = i1;
  return;
  ;
}

OOC_INT32 TextRider__ScannerDesc_Pos(TextRider__Scanner s) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)s;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32406))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32406))+4);
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 32408)))), TextRider__ReaderDesc_Pos)),TextRider__ReaderDesc_Pos)((TextRider__Reader)i0);
  return i0;
  ;
}

void TextRider__ScannerDesc_ClearError(TextRider__Scanner s) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)s;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32478))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32478))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 32481)))), TextRider__ReaderDesc_ClearError)),TextRider__ReaderDesc_ClearError)((TextRider__Reader)i2);
  *(OOC_INT32*)(_check_pointer(i0, 32500)) = 0;
  *(OOC_INT16*)((_check_pointer(i0, 32520))+16) = (-1);
  return;
  ;
}

OOC_INT32 TextRider__ScannerDesc_Available(TextRider__Scanner s) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)s;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32627))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32627))+4);
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 32629)))), TextRider__ReaderDesc_Available)),TextRider__ReaderDesc_Available)((TextRider__Reader)i0);
  return i0;
  ;
}

void TextRider__ScannerDesc_SetPos(TextRider__Scanner s, OOC_INT32 pos) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)s;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 32724));
  i1 = i1==0;
  if (!i1) goto l4;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32750))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32750))+4);
  i3 = pos;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 32753)))), TextRider__ReaderDesc_SetPos)),TextRider__ReaderDesc_SetPos)((TextRider__Reader)i2, i3);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32785))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 32788));
  *(OOC_INT32*)(_check_pointer(i0, 32775)) = i1;
l4:
  return;
  ;
}

void TextRider__ScannerDesc_Scan(TextRider__Scanner s) {
  register OOC_INT32 i0,i1,i2;
  OOC_CHAR8 ch;
  OOC_CHAR8 str[1024];
  OOC_INT16 pos;
  OOC_INT8 res;
  auto void TextRider__ScannerDesc_Scan_ReadNum(void);
  auto void TextRider__ScannerDesc_Scan_SetType(OOC_INT8 type);
    
    void TextRider__ScannerDesc_Scan_ReadNum(void) {
      register OOC_INT32 i0,i1;
      auto void TextRider__ScannerDesc_Scan_ReadNum_Get(void);
      auto OOC_CHAR8 TextRider__ScannerDesc_Scan_ReadNum_LA(void);
        
        void TextRider__ScannerDesc_Scan_ReadNum_Get(void) {
          register OOC_INT32 i0,i1;

          i0 = pos;
          i1 = i0<1024;
          if (!i1) goto l3;
          i1 = (OOC_INT32)s;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 33335))+4);
          i1 = TextRider__Consume((TextRider__Reader)i1);
          *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, 1024, OOC_UINT16, 33316))) = i1;
l3:
          i0 = pos;
          pos = (i0+1);
          i0 = (OOC_INT32)s;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33386))+4);
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 33389));
          i1 = i1==0;
          if (i1) goto l6;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33471))+4);
          *(OOC_UINT8*)(((_check_pointer(i0, 33474))+21)+(_check_index(0, 2, OOC_UINT8, 33478))) = 0u;
          goto l7;
l6:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33439))+4);
          i0 = TextRider__Lookahead((TextRider__Reader)i0, 1);
l7:
          return;
          ;
        }

        
        OOC_CHAR8 TextRider__ScannerDesc_Scan_ReadNum_LA(void) {
          register OOC_INT32 i0;

          i0 = (OOC_INT32)s;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33575))+4);
          i0 = *(OOC_UINT8*)(((_check_pointer(i0, 33578))+21)+(_check_index(0, 2, OOC_UINT8, 33582)));
          return i0;
          ;
        }


      i0 = (OOC_INT32)s;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33626))+4);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 33629));
      i1 = i1==0;
      if (i1) goto l3;
      i0=0u;
      goto l5;
l3:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33657))+4);
      i0 = TextRider__Lookahead((TextRider__Reader)i0, 1);
      
l5:
      if (!i0) goto l81;
      pos = 0;
      i0 = TextRider__ScannerDesc_Scan_ReadNum_LA();
      i0 = i0==45u;
      if (i0) goto l9;
      i0 = TextRider__ScannerDesc_Scan_ReadNum_LA();
      i0 = i0==43u;
      
      goto l11;
l9:
      i0=1u;
l11:
      if (!i0) goto l13;
      TextRider__ScannerDesc_Scan_ReadNum_Get();
l13:
      i0 = TextRider__ScannerDesc_Scan_ReadNum_LA();
      i0 = CharClass__IsNumeric(i0);
      i0 = !i0;
      if (i0) goto l23;
      i0 = TextRider__ScannerDesc_Scan_ReadNum_LA();
      i0 = TextRider__HexDigit(i0);
      if (!i0) goto l24;
l17_loop:
      TextRider__ScannerDesc_Scan_ReadNum_Get();
      i0 = TextRider__ScannerDesc_Scan_ReadNum_LA();
      i0 = TextRider__HexDigit(i0);
      if (i0) goto l17_loop;
      goto l24;
l23:
      i0 = (OOC_INT32)s;
      i1 = (OOC_INT32)TextRider__GetError(8);
      *(OOC_INT32*)(_check_pointer(i0, 33857)) = i1;
      return;
l24:
      i0 = TextRider__ScannerDesc_Scan_ReadNum_LA();
      i0 = i0==46u;
      if (i0) goto l37;
      i0 = TextRider__ScannerDesc_Scan_ReadNum_LA();
      i0 = i0==72u;
      if (i0) goto l32;
      i0 = (OOC_INT32)s;
      *(OOC_INT16*)((_check_pointer(i0, 35352))+16) = 2;
      i1 = pos;
      *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i1, 1024, OOC_UINT16, 35377))) = 0u;
      IntStr__StrToInt((void*)(OOC_INT32)str, 1024, (void*)((_check_pointer(i0, 35420))+28), (void*)(OOC_INT32)&res);
      i0 = res;
      i0 = i0!=0;
      if (!i0) goto l81;
      i0 = (OOC_INT32)s;
      i1 = (OOC_INT32)TextRider__GetError(8);
      *(OOC_INT32*)(_check_pointer(i0, 35487)) = i1;
      goto l81;
l32:
      i0 = (OOC_INT32)s;
      *(OOC_INT16*)((_check_pointer(i0, 35138))+16) = 2;
      i1 = pos;
      *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i1, 1024, OOC_UINT16, 35153))) = 0u;
      i0 = TextRider__HexToInt((void*)(OOC_INT32)str, 1024, (void*)((_check_pointer(i0, 35195))+28));
      i0 = !i0;
      if (!i0) goto l35;
      i0 = (OOC_INT32)s;
      i1 = (OOC_INT32)TextRider__GetError(8);
      *(OOC_INT32*)(_check_pointer(i0, 35220)) = i1;
l35:
      TextRider__ScannerDesc_Scan_ReadNum_Get();
      goto l81;
l37:
      i0 = (OOC_INT32)s;
      *(OOC_INT16*)((_check_pointer(i0, 34084))+16) = 3;
      TextRider__ScannerDesc_Scan_ReadNum_Get();
      i0 = TextRider__ScannerDesc_Scan_ReadNum_LA();
      i0 = CharClass__IsNumeric(i0);
      if (!i0) goto l44;
l39_loop:
      TextRider__ScannerDesc_Scan_ReadNum_Get();
      i0 = TextRider__ScannerDesc_Scan_ReadNum_LA();
      i0 = CharClass__IsNumeric(i0);
      if (i0) goto l39_loop;
l44:
      i0 = TextRider__ScannerDesc_Scan_ReadNum_LA();
      i0 = i0==69u;
      if (i0) goto l47;
      i0 = TextRider__ScannerDesc_Scan_ReadNum_LA();
      i0 = i0==101u;
      
      goto l49;
l47:
      i0=1u;
l49:
      if (!i0) goto l72;
      TextRider__ScannerDesc_Scan_ReadNum_Get();
      i0 = pos;
      i0 = i0-1;
      i1 = i0<1024;
      if (!i1) goto l53;
      *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, 1024, OOC_UINT16, 34342))) = 69u;
l53:
      i0 = TextRider__ScannerDesc_Scan_ReadNum_LA();
      i0 = i0==45u;
      if (i0) goto l56;
      i0 = TextRider__ScannerDesc_Scan_ReadNum_LA();
      i0 = i0==43u;
      
      goto l58;
l56:
      i0=1u;
l58:
      if (!i0) goto l60;
      TextRider__ScannerDesc_Scan_ReadNum_Get();
l60:
      i0 = TextRider__ScannerDesc_Scan_ReadNum_LA();
      i0 = CharClass__IsNumeric(i0);
      i0 = !i0;
      if (i0) goto l70;
      i0 = TextRider__ScannerDesc_Scan_ReadNum_LA();
      i0 = CharClass__IsNumeric(i0);
      if (!i0) goto l72;
l64_loop:
      TextRider__ScannerDesc_Scan_ReadNum_Get();
      i0 = TextRider__ScannerDesc_Scan_ReadNum_LA();
      i0 = CharClass__IsNumeric(i0);
      if (i0) goto l64_loop;
      goto l72;
l70:
      i0 = (OOC_INT32)s;
      i1 = (OOC_INT32)TextRider__GetError(8);
      *(OOC_INT32*)(_check_pointer(i0, 34521)) = i1;
      return;
l72:
      i0 = pos;
      i1 = i0<1024;
      if (i1) goto l75;
      i0 = (OOC_INT32)s;
      i1 = (OOC_INT32)TextRider__GetError(8);
      *(OOC_INT32*)(_check_pointer(i0, 35010)) = i1;
      goto l81;
l75:
      *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, 1024, OOC_UINT16, 34764))) = 0u;
      i0 = (OOC_INT32)s;
      LRealStr__StrToReal((void*)(OOC_INT32)str, 1024, (void*)((_check_pointer(i0, 34812))+32), (void*)(OOC_INT32)&res);
      i0 = res;
      i0 = i0!=0;
      if (!i0) goto l81;
      i0 = (OOC_INT32)s;
      i1 = (OOC_INT32)TextRider__GetError(8);
      *(OOC_INT32*)(_check_pointer(i0, 34932)) = i1;
l81:
      return;
      ;
    }

    
    void TextRider__ScannerDesc_Scan_SetType(OOC_INT8 type) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)s;
      i1 = type;
      *(OOC_INT16*)((_check_pointer(i0, 35647))+16) = i1;
      return;
      ;
    }


  i0 = (OOC_INT32)s;
  i1 = *(OOC_INT16*)((_check_pointer(i0, 35699))+16);
  i1 = i1<9;
  if (!i1) goto l77;
  TextRider__SkipSpaces((TextRider__Scanner)i0);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 35863));
  i1 = i1==0;
  if (i1) goto l5;
  i1=0u;
  goto l7;
l5:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35891))+4);
  i1 = TextRider__Lookahead((TextRider__Reader)i1, 1);
  
l7:
  if (i1) goto l9;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37406))+4);
  i0 = TextRider__Consume((TextRider__Reader)i0);
  ch = i0;
  goto l54;
l9:
  i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 35920)))), TextRider__ScannerDesc_Pos)),TextRider__ScannerDesc_Pos)((TextRider__Scanner)i0);
  *(OOC_INT32*)((_check_pointer(i0, 35913))+20) = i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35941))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35941))+4);
  i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 35944)))), TextRider__ReaderDesc_Eol)),TextRider__ReaderDesc_Eol)((TextRider__Reader)i2);
  if (i1) goto l52;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36064))+4);
  i1 = *(OOC_UINT8*)(((_check_pointer(i1, 36067))+21)+(_check_index(0, 2, OOC_UINT8, 36071)));
  switch (i1) {
  case 34u:
  case 39u:
    i1 = *(OOC_UINT32*)((_check_pointer(i0, 36137))+12);
    i1 = _in(3,i1);
    if (i1) goto l16;
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36257))+4);
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36257))+4);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 36260)))), TextRider__ReaderDesc_ReadChar)),TextRider__ReaderDesc_ReadChar)((TextRider__Reader)i2, (void*)((_check_pointer(i0, 36273))+40));
    TextRider__ScannerDesc_Scan_SetType(0);
    goto l54;
l16:
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36164))+4);
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36164))+4);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 36167)))), TextRider__ReaderDesc_ReadString)),TextRider__ReaderDesc_ReadString)((TextRider__Reader)i2, (void*)((_check_pointer(i0, 36182))+41), 256);
    TextRider__ScannerDesc_Scan_SetType(1);
    goto l54;
  case 97u ... 122u:
  case 65u ... 90u:
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36372))+4);
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36372))+4);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 36375)))), TextRider__ReaderDesc_ReadIdentifier)),TextRider__ReaderDesc_ReadIdentifier)((TextRider__Reader)i2, (void*)((_check_pointer(i0, 36394))+41), 256);
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36422))+4);
    i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 36425));
    i1 = i1==0;
    if (i1) goto l21;
    i1=0u;
    goto l23;
l21:
    i1 = *(OOC_UINT32*)((_check_pointer(i0, 36461))+12);
    i1 = _in(1,i1);
    
l23:
    if (i1) goto l25;
    i1=0u;
    goto l31;
l25:
    i1 = (
    _cmp8((const void*)((_check_pointer(i0, 36487))+41),(const void*)"TRUE"))==0;
    if (i1) goto l28;
    i1 = (
    _cmp8((const void*)((_check_pointer(i0, 36511))+41),(const void*)"FALSE"))==0;
    
    goto l31;
l28:
    i1=1u;
l31:
    if (i1) goto l33;
    TextRider__ScannerDesc_Scan_SetType(8);
    goto l54;
l33:
    *(OOC_UINT8*)((_check_pointer(i0, 36550))+304) = ((
    _cmp8((const void*)((_check_pointer(i0, 36562))+41),(const void*)"TRUE"))==0);
    TextRider__ScannerDesc_Scan_SetType(4);
    goto l54;
  case 43u:
  case 45u:
    i1 = *(OOC_UINT32*)((_check_pointer(i0, 36733))+12);
    i1 = _in(4,i1);
    if (i1) goto l38;
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36798))+4);
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36798))+4);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 36801)))), TextRider__ReaderDesc_ReadChar)),TextRider__ReaderDesc_ReadChar)((TextRider__Reader)i2, (void*)((_check_pointer(i0, 36814))+40));
    TextRider__ScannerDesc_Scan_SetType(0);
    goto l54;
l38:
    TextRider__ScannerDesc_Scan_ReadNum();
    goto l54;
  case 48u ... 57u:
    TextRider__ScannerDesc_Scan_ReadNum();
    goto l54;
  case 123u:
    i1 = *(OOC_UINT32*)((_check_pointer(i0, 36982))+12);
    i1 = _in(2,i1);
    if (i1) goto l44;
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37093))+4);
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37093))+4);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 37096)))), TextRider__ReaderDesc_ReadChar)),TextRider__ReaderDesc_ReadChar)((TextRider__Reader)i2, (void*)((_check_pointer(i0, 37109))+40));
    TextRider__ScannerDesc_Scan_SetType(0);
    goto l54;
l44:
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37009))+4);
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37009))+4);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 37012)))), TextRider__ReaderDesc_ReadSet)),TextRider__ReaderDesc_ReadSet)((TextRider__Reader)i2, (void*)((_check_pointer(i0, 37024))+300));
    TextRider__ScannerDesc_Scan_SetType(5);
    goto l54;
  default:
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37190))+4);
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37190))+4);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 37193)))), TextRider__ReaderDesc_ReadChar)),TextRider__ReaderDesc_ReadChar)((TextRider__Reader)i2, (void*)((_check_pointer(i0, 37206))+40));
    i0 = *(OOC_UINT8*)((_check_pointer(i0, 37231))+40);
    i0 = i0==9u;
    if (i0) goto l49;
    TextRider__ScannerDesc_Scan_SetType(0);
    goto l54;
l49:
    TextRider__ScannerDesc_Scan_SetType(6);
    goto l54;
  }
l52:
  *(OOC_INT16*)((_check_pointer(i0, 35968))+16) = 7;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36004))+4);
  TextRider__SkipEol((TextRider__Reader)i1);
  i1 = *(OOC_INT32*)((_check_pointer(i0, 36026))+24);
  *(OOC_INT32*)((_check_pointer(i0, 36026))+24) = (i1+1);
l54:
  i0 = (OOC_INT32)s;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37457))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 37460));
  i1 = i1!=0;
  if (i1) goto l57;
  i1=0u;
  goto l59;
l57:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 37478));
  i1 = i1==0;
  
l59:
  if (!i1) goto l61;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37518))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 37521));
  *(OOC_INT32*)(_check_pointer(i0, 37508)) = i1;
l61:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 37549));
  i1 = i1!=0;
  if (i1) goto l64;
  i1=0u;
  goto l66;
l64:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 37567));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 37572))+12);
  i2 = (OOC_INT32)TextRider__errorContext;
  i1 = i1==i2;
  
l66:
  if (!i1) goto l77;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 37617));
  i1 = *(OOC_INT32*)((_check_pointer(i1, 37622))+8);
  i1 = i1==8;
  if (i1) goto l70;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 37663));
  i1 = *(OOC_INT32*)((_check_pointer(i1, 37668))+8);
  i1 = i1==1;
  
  goto l72;
l70:
  i1=1u;
l72:
  if (i1) goto l74;
  *(OOC_INT16*)((_check_pointer(i0, 37753))+16) = 9;
  goto l77;
l74:
  *(OOC_INT16*)((_check_pointer(i0, 37711))+16) = 10;
l77:
  return;
  ;
}

void TextRider__ScannerDesc_SetOpts(TextRider__Scanner s, OOC_UINT32 opts) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)s;
  i1 = opts;
  *(OOC_UINT32*)((_check_pointer(i0, 37933))+12) = i1;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37950))+4);
  *(OOC_UINT32*)((_check_pointer(i0, 37952))+4) = (i1&1u);
  return;
  ;
}

void TextRider__ScannerDesc_SetEol(TextRider__Scanner s, const OOC_CHAR8 marker__ref[], OOC_LEN marker_0d, OOC_INT16 markerLen) {
  register OOC_INT32 i0,i1,i2;
  OOC_ALLOCATE_VPAR(marker,OOC_CHAR8 ,marker_0d)

  OOC_INITIALIZE_VPAR(marker__ref,marker,OOC_CHAR8 ,marker_0d)
  i0 = (OOC_INT32)s;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 38152))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 38152))+4);
  i2 = markerLen;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 38155)))), TextRider__ReaderDesc_SetEol)),TextRider__ReaderDesc_SetEol)((TextRider__Reader)i0, (void*)(OOC_INT32)marker, marker_0d, i2);
  return;
  ;
}

OOC_INT32 TextRider__WriterDesc_Pos(TextRider__Writer w) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 38456))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 38456))+8);
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 38467)))), Channel__WriterDesc_Pos)),Channel__WriterDesc_Pos)((Channel__Writer)i0);
  return i0;
  ;
}

void TextRider__WriterDesc_SetPos(TextRider__Writer w, OOC_INT32 newPos) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 38552));
  i1 = i1==0;
  if (!i1) goto l4;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 38578))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 38578))+8);
  i3 = newPos;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 38589)))), Channel__WriterDesc_SetPos)),Channel__WriterDesc_SetPos)((Channel__Writer)i2, i3);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 38623))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 38635))+4);
  *(OOC_INT32*)(_check_pointer(i0, 38613)) = i1;
l4:
  return;
  ;
}

void TextRider__WriterDesc_ClearError(TextRider__Writer w) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 38712))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 38712))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 38723)))), Channel__WriterDesc_ClearError)),Channel__WriterDesc_ClearError)((Channel__Writer)i2);
  *(OOC_INT32*)(_check_pointer(i0, 38741)) = 0;
  return;
  ;
}

void TextRider__WriterDesc_SetOpts(TextRider__Writer w, OOC_UINT32 opts) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)w;
  i1 = opts;
  *(OOC_UINT32*)((_check_pointer(i0, 38876))+4) = i1;
  return;
  ;
}

void TextRider__WriterDesc_SetEol(TextRider__Writer w, const OOC_CHAR8 marker__ref[], OOC_LEN marker_0d, OOC_INT16 markerLen) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_ALLOCATE_VPAR(marker,OOC_CHAR8 ,marker_0d)
  OOC_INT16 i;

  OOC_INITIALIZE_VPAR(marker__ref,marker,OOC_CHAR8 ,marker_0d)
  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 39417));
  i1 = i1==0;
  if (!i1) goto l19;
  i1 = markerLen;
  i2 = i1<0;
  if (i2) goto l5;
  i2 = i1>2;
  
  goto l7;
l5:
  i2=1u;
l7:
  if (i2) goto l17;
  i = 0;
  i2 = 0<i1;
  if (!i2) goto l16;
  i2=0;
l11_loop:
  i3 = *(OOC_UINT8*)((OOC_INT32)marker+(_check_index(i2, marker_0d, OOC_UINT16, 39616)));
  *(OOC_UINT8*)(((_check_pointer(i0, 39598))+16)+(_check_index(i2, 2, OOC_UINT16, 39603))) = i3;
  i2 = i2+1;
  i = i2;
  i3 = i2<i1;
  if (i3) goto l11_loop;
l16:
  *(OOC_INT16*)((_check_pointer(i0, 39642))+18) = i1;
  goto l19;
l17:
  i1 = (OOC_INT32)TextRider__GetError(8);
  *(OOC_INT32*)(_check_pointer(i0, 39505)) = i1;
l19:
  return;
  ;
}

void TextRider__WriterDesc_WriteString(TextRider__Writer w, const OOC_CHAR8 s[], OOC_LEN s_0d) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 39817));
  i1 = i1==0;
  if (!i1) goto l10;
  i1 = Strings__Length((void*)(OOC_INT32)s, s_0d);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 39843))+8);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 39843))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 39855)))), Channel__WriterDesc_WriteBytes)),Channel__WriterDesc_WriteBytes)((Channel__Writer)i3, (void*)(OOC_INT32)s, (-1), 0, i1);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 39913))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 39925))+4);
  *(OOC_INT32*)(_check_pointer(i0, 39903)) = i1;
  i1 = *(OOC_UINT32*)((_check_pointer(i0, 39958))+4);
  i1 = _in(0,i1);
  if (i1) goto l5;
  i1=0u;
  goto l7;
l5:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 39968));
  i1 = i1==0;
  
l7:
  if (!i1) goto l10;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 39996))+12);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 39996))+12);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 40002)))), Channel__ChannelDesc_Flush)),Channel__ChannelDesc_Flush)((Channel__Channel)i2);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 40030))+12);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 40036));
  *(OOC_INT32*)(_check_pointer(i0, 40020)) = i1;
l10:
  return;
  ;
}

void TextRider__WriterDesc_WriteObject(TextRider__Writer w, Object__Object obj) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  Object__String s;
  Object__CharsLatin1 chars;
  Object__CharsUTF16 chars16;
  OOC_INT32 i;
  Object__String8 s8;

  i0 = (OOC_INT32)obj;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l32;
  i1 = (OOC_INT32)w;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 40341));
  i2 = i2==(OOC_INT32)0;
  if (!i2) goto l33;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 40374)))), Object__ObjectDesc_ToString)),Object__ObjectDesc_ToString)((Object__Object)i0);
  s = (Object__String)i0;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 40399)))), &_td_Object__String8Desc);
  if (i2) goto l22;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 40519)))), &_td_Object__String16Desc);
  if (i2) goto l9;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 40516)))), 40516);
  goto l23;
l9:
  i2 = (OOC_INT32)Object__String16Desc_CharsUTF16((Object__String16)i0);
  chars16 = (Object__CharsUTF16)i2;
  i3 = *(OOC_INT32*)(_check_pointer(i0, 40598));
  i = 0;
  i4 = 0<i3;
  if (!i4) goto l20;
  i4=0;
l12_loop:
  i5 = _check_pointer(i2, 40632);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = *(OOC_UINT16*)(i5+(_check_index(i4, i6, OOC_UINT32, 40632))*2);
  i5 = (OOC_UINT16)i5>=(OOC_UINT16)256u;
  if (!i5) goto l15;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 40663)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i1, "[TextRider.WriteObject: String16 not implemented]", 50);
  return;
l15:
  i4 = i4+1;
  i = i4;
  i5 = i4<i3;
  if (i5) goto l12_loop;
l20:
  i0 = (OOC_INT32)Object__String16Desc_ToString8((Object__String16)i0, 63u);
  s8 = (Object__String8)i0;
  i2 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)i0);
  chars = (Object__CharsLatin1)i2;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 40854))+8);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 40854))+8);
  i0 = *(OOC_INT32*)(_check_pointer(i0, 40893));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 40866)))), Channel__WriterDesc_WriteBytes)),Channel__WriterDesc_WriteBytes)((Channel__Writer)i4, (void*)(_check_pointer(i2, 40885)), (-1), 0, i0);
  goto l23;
l22:
  i2 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)i0);
  chars = (Object__CharsLatin1)i2;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 40462))+8);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 40462))+8);
  i0 = *(OOC_INT32*)(_check_pointer(i0, 40500));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 40474)))), Channel__WriterDesc_WriteBytes)),Channel__WriterDesc_WriteBytes)((Channel__Writer)i4, (void*)(_check_pointer(i2, 40493)), (-1), 0, i0);
l23:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 40931))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 40943))+4);
  *(OOC_INT32*)(_check_pointer(i1, 40921)) = i0;
  i0 = *(OOC_UINT32*)((_check_pointer(i1, 40976))+4);
  i0 = _in(0,i0);
  if (i0) goto l26;
  i0=0u;
  goto l28;
l26:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 40986));
  i0 = i0==(OOC_INT32)0;
  
l28:
  if (!i0) goto l33;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 41014))+12);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 41014))+12);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 41020)))), Channel__ChannelDesc_Flush)),Channel__ChannelDesc_Flush)((Channel__Channel)i2);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 41048))+12);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 41054));
  *(OOC_INT32*)(_check_pointer(i1, 41038)) = i0;
  goto l33;
l32:
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 40306)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, "<NIL>", 6);
l33:
  return;
  ;
}

void TextRider__WriterDesc_WriteBool(TextRider__Writer w, OOC_CHAR8 _bool) {
  register OOC_INT32 i0;

  i0 = _bool;
  if (i0) goto l3;
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 41206)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, "FALSE", 6);
  goto l4;
l3:
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 41173)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, "TRUE", 5);
l4:
  return;
  ;
}

void TextRider__WriterDesc_WriteChar(TextRider__Writer w, OOC_CHAR8 ch) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 41319));
  i1 = i1==0;
  if (!i1) goto l10;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 41345))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 41345))+8);
  i3 = ch;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 41356)))), Channel__WriterDesc_WriteByte)),Channel__WriterDesc_WriteByte)((Channel__Writer)i2, i3);
  i1 = *(OOC_UINT32*)((_check_pointer(i0, 41398))+4);
  i1 = _in(0,i1);
  if (i1) goto l5;
  i1=0u;
  goto l7;
l5:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 41408));
  i1 = i1==0;
  
l7:
  if (!i1) goto l10;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 41436))+12);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 41436))+12);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 41442)))), Channel__ChannelDesc_Flush)),Channel__ChannelDesc_Flush)((Channel__Channel)i2);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 41470))+12);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 41476));
  *(OOC_INT32*)(_check_pointer(i0, 41460)) = i1;
l10:
  return;
  ;
}

static void TextRider__WritePad(TextRider__Writer w, OOC_INT32 n) {
  register OOC_INT32 i0,i1,i2;

  i0 = n;
  i1 = i0>0;
  if (!i1) goto l8;
  i1 = (OOC_INT32)w;
  
l3_loop:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 41615)))), TextRider__WriterDesc_WriteChar)),TextRider__WriterDesc_WriteChar)((TextRider__Writer)i1, 32u);
  i0 = i0-1;
  n = i0;
  i2 = i0>0;
  if (i2) goto l3_loop;
l8:
  return;
  ;
}

void TextRider__WriterDesc_WriteLInt(TextRider__Writer w, OOC_INT32 lint, OOC_INT32 n) {
  register OOC_INT32 i0,i1,i2;
  OOC_CHAR8 val[16];

  i0 = lint;
  IntStr__IntToStr(i0, (void*)(OOC_INT32)val, 16);
  i0 = Strings__Length((void*)(OOC_INT32)val, 16);
  i1 = n;
  i2 = (OOC_INT32)w;
  TextRider__WritePad((TextRider__Writer)i2, (i1-i0));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 42193)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i2, (void*)(OOC_INT32)val, 16);
  return;
  ;
}

void TextRider__WriterDesc_WriteSInt(TextRider__Writer w, OOC_INT8 sint, OOC_INT32 n) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)w;
  i1 = sint;
  i2 = n;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 42307)))), TextRider__WriterDesc_WriteLInt)),TextRider__WriterDesc_WriteLInt)((TextRider__Writer)i0, i1, i2);
  return;
  ;
}

void TextRider__WriterDesc_WriteInt(TextRider__Writer w, OOC_INT16 _int, OOC_INT32 n) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)w;
  i1 = _int;
  i2 = n;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 42418)))), TextRider__WriterDesc_WriteLInt)),TextRider__WriterDesc_WriteLInt)((TextRider__Writer)i0, i1, i2);
  return;
  ;
}

void TextRider__WriterDesc_WriteHex(TextRider__Writer w, OOC_INT32 lint, OOC_INT32 d) {
  register OOC_INT32 i0,i1;
  auto void TextRider__WriterDesc_WriteHex_WriteHexDigits(TextRider__Writer w, OOC_INT32 *n, OOC_INT32 digits);
    
    void TextRider__WriterDesc_WriteHex_WriteHexDigits(TextRider__Writer w, OOC_INT32 *n, OOC_INT32 digits) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      OOC_INT32 dig;

      i0 = digits;
      i1 = i0>8;
      if (!i1) goto l13;
      i1 = (OOC_INT32)w;
      i2 = *n;
      i2 = i2<0;
      
l4_loop:
      if (i2) goto l7;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 42865)))), TextRider__WriterDesc_WriteChar)),TextRider__WriterDesc_WriteChar)((TextRider__Writer)i1, 48u);
      goto l8;
l7:
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 42843)))), TextRider__WriterDesc_WriteChar)),TextRider__WriterDesc_WriteChar)((TextRider__Writer)i1, 70u);
l8:
      i0 = i0-1;
      digits = i0;
      i3 = i0>8;
      if (i3) goto l4_loop;
l13:
      i1 = i0>0;
      if (!i1) goto l25;
      i1 = (OOC_INT32)w;
      i2 = *n;
      
l16_loop:
      i0 = i0-1;
      digits = i0;
      i3 = _mod((_ash(i2,(-(4*i0)))),16);
      dig = i3;
      i4 = i3<=9;
      if (i4) goto l19;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 43114)))), TextRider__WriterDesc_WriteChar)),TextRider__WriterDesc_WriteChar)((TextRider__Writer)i1, (55+i3));
      goto l20;
l19:
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 43067)))), TextRider__WriterDesc_WriteChar)),TextRider__WriterDesc_WriteChar)((TextRider__Writer)i1, (48+i3));
l20:
      i3 = i0>0;
      if (i3) goto l16_loop;
l25:
      return;
      ;
    }


  i0 = d;
  i1 = i0<=0;
  if (!i1) goto l4;
  d = 8;
  i0=8;
l4:
  i1 = (OOC_INT32)w;
  TextRider__WriterDesc_WriteHex_WriteHexDigits((TextRider__Writer)i1, (void*)(OOC_INT32)&lint, i0);
  return;
  ;
}

void TextRider__WriterDesc_WriteLReal(TextRider__Writer w, OOC_REAL64 lreal, OOC_INT32 n, OOC_INT32 k) {
  register OOC_INT32 i0,i1,i2;
  register OOC_REAL64 d0;
  OOC_CHAR8 val[128];

  i0 = k;
  d0 = lreal;
  LRealStr__RealToFloat(d0, i0, (void*)(OOC_INT32)val, 128);
  i0 = Strings__Length((void*)(OOC_INT32)val, 128);
  i1 = n;
  i2 = (OOC_INT32)w;
  TextRider__WritePad((TextRider__Writer)i2, (i1-i0));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 43684)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i2, (void*)(OOC_INT32)val, 128);
  return;
  ;
}

void TextRider__WriterDesc_WriteReal(TextRider__Writer w, OOC_REAL32 real, OOC_INT32 n, OOC_INT32 k) {
  register OOC_INT32 i0,i1,i2;
  register OOC_REAL32 f0;
  OOC_CHAR8 val[128];

  i0 = k;
  f0 = real;
  RealStr__RealToFloat(f0, i0, (void*)(OOC_INT32)val, 128);
  i0 = Strings__Length((void*)(OOC_INT32)val, 128);
  i1 = n;
  i2 = (OOC_INT32)w;
  TextRider__WritePad((TextRider__Writer)i2, (i1-i0));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 44055)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i2, (void*)(OOC_INT32)val, 128);
  return;
  ;
}

void TextRider__WriterDesc_WriteLRealFix(TextRider__Writer w, OOC_REAL64 *lreal, OOC_INT32 n, OOC_INT32 k) {
  register OOC_INT32 i0,i1,i2;
  register OOC_REAL64 d0;
  OOC_CHAR8 val[128];

  i0 = k;
  d0 = *lreal;
  LRealStr__RealToFixed(d0, i0, (void*)(OOC_INT32)val, 128);
  i0 = Strings__Length((void*)(OOC_INT32)val, 128);
  i1 = n;
  i2 = (OOC_INT32)w;
  TextRider__WritePad((TextRider__Writer)i2, (i1-i0));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 44504)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i2, (void*)(OOC_INT32)val, 128);
  return;
  ;
}

void TextRider__WriterDesc_WriteRealFix(TextRider__Writer w, OOC_REAL32 real, OOC_INT32 n, OOC_INT32 k) {
  register OOC_INT32 i0,i1,i2;
  register OOC_REAL32 f0;
  OOC_CHAR8 val[128];

  i0 = k;
  f0 = real;
  RealStr__RealToFixed(f0, i0, (void*)(OOC_INT32)val, 128);
  i0 = Strings__Length((void*)(OOC_INT32)val, 128);
  i1 = n;
  i2 = (OOC_INT32)w;
  TextRider__WritePad((TextRider__Writer)i2, (i1-i0));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 44887)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i2, (void*)(OOC_INT32)val, 128);
  return;
  ;
}

void TextRider__WriterDesc_WriteLRealEng(TextRider__Writer w, OOC_REAL64 *lreal, OOC_INT32 n, OOC_INT32 k) {
  register OOC_INT32 i0,i1,i2;
  register OOC_REAL64 d0;
  OOC_CHAR8 val[128];

  i0 = k;
  d0 = *lreal;
  LRealStr__RealToEng(d0, i0, (void*)(OOC_INT32)val, 128);
  i0 = Strings__Length((void*)(OOC_INT32)val, 128);
  i1 = n;
  i2 = (OOC_INT32)w;
  TextRider__WritePad((TextRider__Writer)i2, (i1-i0));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 45335)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i2, (void*)(OOC_INT32)val, 128);
  return;
  ;
}

void TextRider__WriterDesc_WriteRealEng(TextRider__Writer w, OOC_REAL32 real, OOC_INT32 n, OOC_INT32 k) {
  register OOC_INT32 i0,i1,i2;
  register OOC_REAL32 f0;
  OOC_CHAR8 val[128];

  i0 = k;
  f0 = real;
  RealStr__RealToEng(f0, i0, (void*)(OOC_INT32)val, 128);
  i0 = Strings__Length((void*)(OOC_INT32)val, 128);
  i1 = n;
  i2 = (OOC_INT32)w;
  TextRider__WritePad((TextRider__Writer)i2, (i1-i0));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 45716)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i2, (void*)(OOC_INT32)val, 128);
  return;
  ;
}

void TextRider__WriterDesc_WriteSet(TextRider__Writer w, OOC_UINT32 s) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT8 bit;
  OOC_CHAR8 addComma;
  OOC_INT8 lo;

  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 45909)))), TextRider__WriterDesc_WriteChar)),TextRider__WriterDesc_WriteChar)((TextRider__Writer)i0, 123u);
  bit = 0;
  i1 = s;
  addComma = 0u;
  i2=0;i3=0u;
l1_loop:
  i4 = _in(i2,i1);
  if (i4) goto l4;
  {register OOC_INT32 h0=i2;i2=i3;i3=h0;}
  goto l29;
l4:
  lo = i2;
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
  bit = i4;
  i5 = i4<31;
  if (i5) goto l15;
  i5=0u;
  goto l17;
l15:
  i5 = _in((i4+1),i1);
  
l17:
  if (i5) goto l12_loop;
l22:
  if (i3) goto l24;
  addComma = 1u;
  i3=1u;
  goto l25;
l24:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 46181)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, ", ", 3);
  
l25:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 46234)))), TextRider__WriterDesc_WriteInt)),TextRider__WriterDesc_WriteInt)((TextRider__Writer)i0, i2, 0);
  i2 = i2<i4;
  if (!i2) goto l28;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 46286)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, "..", 3);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 46307)))), TextRider__WriterDesc_WriteInt)),TextRider__WriterDesc_WriteInt)((TextRider__Writer)i0, i4, 0);
l28:
  i2=i3;i3=i4;
l29:
  i3 = i3+1;
  bit = i3;
  i4 = i3<=31;
  if (!i4) goto l33;
  {register OOC_INT32 h0=i2;i2=i3;i3=h0;}
  goto l1_loop;
l33:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 46377)))), TextRider__WriterDesc_WriteChar)),TextRider__WriterDesc_WriteChar)((TextRider__Writer)i0, 125u);
  return;
  ;
}

void TextRider__WriterDesc_WriteLn(TextRider__Writer w) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_INT16 i;

  i0 = (OOC_INT32)w;
  i = 0;
  i1 = *(OOC_INT16*)((_check_pointer(i0, 46517))+18);
  i2 = 0<i1;
  if (!i2) goto l8;
  i2=0;
l3_loop:
  i3 = *(OOC_UINT8*)(((_check_pointer(i0, 46552))+16)+(_check_index(i2, 2, OOC_UINT16, 46556)));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 46538)))), TextRider__WriterDesc_WriteChar)),TextRider__WriterDesc_WriteChar)((TextRider__Writer)i0, i3);
  i2 = i2+1;
  i = i2;
  i3 = i2<i1;
  if (i3) goto l3_loop;
l8:
  return;
  ;
}

void TextRider__InitReader(TextRider__Reader r, Channel__Channel ch) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)r;
  *(OOC_INT32*)(_check_pointer(i0, 46756)) = 0;
  *(OOC_UINT32*)((_check_pointer(i0, 46776))+4) = 0u;
  i1 = (OOC_INT32)ch;
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 46826)))), Channel__ChannelDesc_NewReader)),Channel__ChannelDesc_NewReader)((Channel__Channel)i1);
  *(OOC_INT32*)((_check_pointer(i0, 46808))+8) = i2;
  *(OOC_INT32*)((_check_pointer(i0, 46845))+12) = i1;
  *(OOC_INT16*)((_check_pointer(i0, 46864))+18) = (-1);
  *(OOC_UINT8*)((_check_pointer(i0, 46885))+20) = 0u;
  *(OOC_INT16*)((_check_pointer(i0, 46914))+32) = 0;
  return;
  ;
}

TextRider__Reader TextRider__ConnectReader(Channel__Channel ch) {
  register OOC_INT32 i0,i1;
  TextRider__Reader r;

  i0 = (OOC_INT32)RT0__NewObject(_td_TextRider__Reader.baseTypes[0]);
  r = (TextRider__Reader)i0;
  i1 = (OOC_INT32)ch;
  TextRider__InitReader((TextRider__Reader)i0, (Channel__Channel)i1);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 47075))+8);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l3;
  return (TextRider__Reader)i0;
  goto l4;
l3:
  return (TextRider__Reader)(OOC_INT32)0;
l4:
  _failed_function(46956); return 0;
  ;
}

void TextRider__InitWriter(TextRider__Writer w, Channel__Channel ch) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_INT16 i;

  i0 = (OOC_INT32)w;
  *(OOC_INT32*)(_check_pointer(i0, 47365)) = 0;
  *(OOC_UINT32*)((_check_pointer(i0, 47385))+4) = 0u;
  i1 = (OOC_INT32)ch;
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 47435)))), Channel__ChannelDesc_NewWriter)),Channel__ChannelDesc_NewWriter)((Channel__Channel)i1);
  *(OOC_INT32*)((_check_pointer(i0, 47417))+8) = i2;
  *(OOC_INT32*)((_check_pointer(i0, 47454))+12) = i1;
  i1 = Strings__Length((void*)(OOC_INT32)CharClass__systemEol, 3);
  *(OOC_INT16*)((_check_pointer(i0, 47473))+18) = i1;
  i = 0;
  i1 = *(OOC_INT16*)((_check_pointer(i0, 47542))+18);
  i2 = 0<i1;
  if (!i2) goto l8;
  i2=0;
l3_loop:
  i3 = *(OOC_UINT8*)((OOC_INT32)CharClass__systemEol+(_check_index(i2, 3, OOC_UINT16, 47594)));
  *(OOC_UINT8*)(((_check_pointer(i0, 47563))+16)+(_check_index(i2, 2, OOC_UINT16, 47568))) = i3;
  i2 = i2+1;
  i = i2;
  i3 = i2<i1;
  if (i3) goto l3_loop;
l8:
  return;
  ;
}

TextRider__Writer TextRider__ConnectWriter(Channel__Channel ch) {
  register OOC_INT32 i0,i1;
  TextRider__Writer w;

  i0 = (OOC_INT32)RT0__NewObject(_td_TextRider__Writer.baseTypes[0]);
  w = (TextRider__Writer)i0;
  i1 = (OOC_INT32)ch;
  TextRider__InitWriter((TextRider__Writer)i0, (Channel__Channel)i1);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 47754))+8);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l3;
  return (TextRider__Writer)i0;
  goto l4;
l3:
  return (TextRider__Writer)(OOC_INT32)0;
l4:
  _failed_function(47635); return 0;
  ;
}

void TextRider__InitScanner(TextRider__Scanner s, Channel__Channel ch) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)s;
  *(OOC_INT32*)(_check_pointer(i0, 48023)) = 0;
  i1 = (OOC_INT32)ch;
  i2 = (OOC_INT32)TextRider__ConnectReader((Channel__Channel)i1);
  *(OOC_INT32*)((_check_pointer(i0, 48043))+4) = i2;
  *(OOC_UINT32*)((_check_pointer(i0, 48071))+12) = 30u;
  *(OOC_INT16*)((_check_pointer(i0, 48101))+16) = (-1);
  *(OOC_INT32*)((_check_pointer(i0, 48124))+24) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 48140))+8) = i1;
  return;
  ;
}

TextRider__Scanner TextRider__ConnectScanner(Channel__Channel ch) {
  register OOC_INT32 i0,i1;
  TextRider__Scanner s;

  i0 = (OOC_INT32)RT0__NewObject(_td_TextRider__Scanner.baseTypes[0]);
  s = (TextRider__Scanner)i0;
  i1 = (OOC_INT32)ch;
  TextRider__InitScanner((TextRider__Scanner)i0, (Channel__Channel)i1);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 48307))+4);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l3;
  return (TextRider__Scanner)i0;
  goto l4;
l3:
  return (TextRider__Scanner)(OOC_INT32)0;
l4:
  _failed_function(48184); return 0;
  ;
}

void OOC_TextRider_init(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)RT0__NewObject(_td_TextRider__ErrorContext.baseTypes[0]);
  TextRider__errorContext = (TextRider__ErrorContext)i0;
  Msg__InitContext((Msg__Context)i0, "OOC:Core:TextRider", 19);
  return;
  ;
}

void OOC_TextRider_destroy(void) {
}

/* --- */
