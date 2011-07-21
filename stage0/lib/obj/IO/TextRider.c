#include <IO/TextRider.d>
#include <__oo2c.h>
#include <setjmp.h>

IO__ProtocolError IO_TextRider__NewProtocolError(Object__String msg) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)RT0__NewObject(_td_IO__ProtocolError.baseTypes[0]);
  i1 = (OOC_INT32)msg;
  IO__ErrorDesc_INIT((IO__Error)i0, (Object__String)i1);
  return (IO__ProtocolError)i0;
  ;
}

void IO_TextRider__RaiseProtocolError(Object__String msg) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)msg;
  i0 = (OOC_INT32)IO_TextRider__NewProtocolError((Object__String)i0);
  Exception__Raise((void*)i0);
  
  ;
}

IO_TextRider__OverflowError IO_TextRider__NewOverflowError(Object__String msg) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)RT0__NewObject(_td_IO_TextRider__OverflowError.baseTypes[0]);
  i1 = (OOC_INT32)msg;
  IO__ErrorDesc_INIT((IO__Error)i0, (Object__String)i1);
  return (IO_TextRider__OverflowError)i0;
  ;
}

void IO_TextRider__RaiseOverflowError(Object__String msg) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)msg;
  i0 = (OOC_INT32)IO_TextRider__NewOverflowError((Object__String)i0);
  Exception__Raise((void*)i0);
  
  ;
}

void IO_TextRider__InitWriter(IO_TextRider__Writer w, IO__ByteChannel ch) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_INT16 i;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)ch;
  *(OOC_INT32*)(_check_pointer(i0, 4109)) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 4131))+4) = 0;
  i1 = Strings__Length((void*)(OOC_INT32)CharClass__systemEol, 3);
  *(OOC_INT16*)((_check_pointer(i0, 4152))+10) = i1;
  i = 0;
  i1 = *(OOC_INT16*)((_check_pointer(i0, 4221))+10);
  i2 = 0<i1;
  if (!i2) goto l8;
  i2=0;
l3_loop:
  i3 = *(OOC_UINT8*)((OOC_INT32)CharClass__systemEol+(_check_index(i2, 3, OOC_UINT16, 4273)));
  *(OOC_UINT8*)(((_check_pointer(i0, 4242))+8)+(_check_index(i2, 2, OOC_UINT16, 4247))) = i3;
  i2 = i2+1;
  i = i2;
  i3 = i2<i1;
  if (i3) goto l3_loop;
l8:
  return;
  ;
}

IO_TextRider__Writer IO_TextRider__ConnectWriter(IO__ByteChannel ch) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)RT0__NewObject(_td_IO_TextRider__Writer.baseTypes[0]);
  i1 = (OOC_INT32)ch;
  IO_TextRider__InitWriter((IO_TextRider__Writer)i0, (IO__ByteChannel)i1);
  return (IO_TextRider__Writer)i0;
  ;
}

void IO_TextRider__WriterDesc_SetEol(IO_TextRider__Writer w, const OOC_CHAR8 marker__ref[], OOC_LEN marker_0d, OOC_INT16 markerLen) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_ALLOCATE_VPAR(marker,OOC_CHAR8 ,marker_0d)
  OOC_INT16 i;

  OOC_INITIALIZE_VPAR(marker__ref,marker,OOC_CHAR8 ,marker_0d)
  i0 = markerLen;
  i1 = i0<0;
  if (i1) goto l3;
  i1 = i0>2;
  
  goto l5;
l3:
  i1=1u;
l5:
  if (i1) goto l15;
  i = 0;
  i1 = (OOC_INT32)w;
  i2 = 0<i0;
  if (!i2) goto l14;
  i2=0;
l9_loop:
  i3 = *(OOC_UINT8*)((OOC_INT32)marker+(_check_index(i2, marker_0d, OOC_UINT16, 5321)));
  *(OOC_UINT8*)(((_check_pointer(i1, 5303))+8)+(_check_index(i2, 2, OOC_UINT16, 5308))) = i3;
  i2 = i2+1;
  i = i2;
  i3 = i2<i0;
  if (i3) goto l9_loop;
l14:
  *(OOC_INT16*)((_check_pointer(i1, 5343))+10) = i0;
l15:
  return;
  ;
}

static void IO_TextRider__SetError(IO_TextRider__Writer w) {
  register OOC_INT32 i0,i1;
  Exception__Exception e;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5470))+4);
  i1 = i1==(OOC_INT32)0;
  if (!i1) goto l4;
  i1 = (OOC_INT32)Exception__Current();
  e = (Exception__Exception)i1;
  *(OOC_INT32*)((_check_pointer(i0, 5528))+4) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5543)))), &_td_IO__ErrorDesc, 5543));
l4:
  return;
  ;
}

void IO_TextRider__WriterDesc_WriteString(volatile IO_TextRider__Writer w, const OOC_CHAR8 s[], volatile OOC_LEN s_0d) {
  register OOC_INT32 i0,i1,i2;
  volatile OOC_INT32 len;
  volatile OOC_INT32 d;
  jmp_buf _target0;
  Exception__Context _context0;

  i0 = Strings__Length((void*)(OOC_INT32)s, s_0d);
  len = i0;
  {
    Exception__PushContext(&_context0, &_target0);
    if (!setjmp(_target0)) goto l7;
    Exception__PopContext(1);
    i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG(((OOC_INT32)Exception__Current()))), &_td_IO__ErrorDesc);
    if (i0) goto l5;
    Exception__ActivateContext();
    goto l6;
l5:
    i0 = (OOC_INT32)w;
    IO_TextRider__SetError((IO_TextRider__Writer)i0);
l6:
    Exception__Clear();
    goto l8;
l7:
    i1 = (OOC_INT32)w;
    i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 5765));
    i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 5765));
    i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 5773)))), IO__ByteChannelDesc_Write)),IO__ByteChannelDesc_Write)((IO__ByteChannel)i1, (void*)(OOC_INT32)s, (-1), 0, i0);
    d = i0;
    Exception__PopContext(1);
l8:;
  }
  return;
  ;
}

void IO_TextRider__WriterDesc_WriteStringRegion(volatile IO_TextRider__Writer w, const OOC_CHAR8 s[], volatile OOC_LEN s_0d, volatile OOC_INT32 start, volatile OOC_INT32 end) {
  register OOC_INT32 i0,i1,i2,i3;
  volatile OOC_INT32 d;
  jmp_buf _target0;
  Exception__Context _context0;

  {
    Exception__PushContext(&_context0, &_target0);
    if (!setjmp(_target0)) goto l7;
    Exception__PopContext(1);
    i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG(((OOC_INT32)Exception__Current()))), &_td_IO__ErrorDesc);
    if (i0) goto l5;
    Exception__ActivateContext();
    goto l6;
l5:
    i0 = (OOC_INT32)w;
    IO_TextRider__SetError((IO_TextRider__Writer)i0);
l6:
    Exception__Clear();
    goto l8;
l7:
    i0 = (OOC_INT32)w;
    i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6041));
    i2 = end;
    i3 = start;
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6041));
    i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6049)))), IO__ByteChannelDesc_Write)),IO__ByteChannelDesc_Write)((IO__ByteChannel)i0, (void*)(OOC_INT32)s, (-1), i3, (i2-i3));
    d = i0;
    Exception__PopContext(1);
l8:;
  }
  return;
  ;
}

void IO_TextRider__WriterDesc_WriteObject(volatile IO_TextRider__Writer w, volatile Object__Object obj) {
  register OOC_INT32 i0,i1,i2,i3;
  volatile Object__String s;
  volatile Object__CharsLatin1 chars;
  volatile OOC_INT32 i;
  jmp_buf _target0;
  Exception__Context _context0;

  i0 = (OOC_INT32)obj;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l19;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6368)))), Object__ObjectDesc_ToString)),Object__ObjectDesc_ToString)((Object__Object)i0);
  s = (Object__String)i0;
  {
    Exception__PushContext(&_context0, &_target0);
    if (!setjmp(_target0)) goto l9;
    Exception__PopContext(1);
    i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG(((OOC_INT32)Exception__Current()))), &_td_IO__ErrorDesc);
    if (i0) goto l7;
    Exception__ActivateContext();
    goto l8;
l7:
    i0 = (OOC_INT32)w;
    IO_TextRider__SetError((IO_TextRider__Writer)i0);
l8:
    Exception__Clear();
    goto l18;
l9:
    i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6405)))), &_td_Object__String8Desc);
    if (i1) goto l16;
    i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6525)))), &_td_Object__String16Desc);
    if (i1) goto l14;
    _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6522)))), 6522);
    goto l17;
l14:
    i0 = (OOC_INT32)w;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6557)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "[IO:TextRider.WriteObject: String16 not implemented]", 53);
    goto l17;
l16:
    i1 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)i0);
    chars = (Object__CharsLatin1)i1;
    i2 = (OOC_INT32)w;
    i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 6477));
    i0 = *(OOC_INT32*)(_check_pointer(i0, 6504));
    i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 6477));
    i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 6485)))), IO__ByteChannelDesc_Write)),IO__ByteChannelDesc_Write)((IO__ByteChannel)i2, (void*)(_check_pointer(i1, 6497)), (-1), 0, i0);
    i = i0;
l17:
    Exception__PopContext(1);
l18:;
  }
  goto l20;
l19:
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6322)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "<NIL>", 6);
l20:
  return;
  ;
}

void IO_TextRider__WriterDesc_WriteBool(IO_TextRider__Writer w, OOC_CHAR8 _bool) {
  register OOC_INT32 i0;

  i0 = _bool;
  if (i0) goto l3;
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6831)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "FALSE", 6);
  goto l4;
l3:
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6798)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "TRUE", 5);
l4:
  return;
  ;
}

void IO_TextRider__WriterDesc_WriteChar(volatile IO_TextRider__Writer w, volatile OOC_CHAR8 ch) {
  register OOC_INT32 i0,i1;
  volatile OOC_INT32 d;
  jmp_buf _target0;
  Exception__Context _context0;

  {
    Exception__PushContext(&_context0, &_target0);
    if (!setjmp(_target0)) goto l7;
    Exception__PopContext(1);
    i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG(((OOC_INT32)Exception__Current()))), &_td_IO__ErrorDesc);
    if (i0) goto l5;
    Exception__ActivateContext();
    goto l6;
l5:
    i0 = (OOC_INT32)w;
    IO_TextRider__SetError((IO_TextRider__Writer)i0);
l6:
    Exception__Clear();
    goto l8;
l7:
    i0 = (OOC_INT32)w;
    i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6975));
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6975));
    i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6983)))), IO__ByteChannelDesc_Write)),IO__ByteChannelDesc_Write)((IO__ByteChannel)i0, (void*)(OOC_INT32)&ch, 1, 0, 1);
    d = i0;
    Exception__PopContext(1);
l8:;
  }
  return;
  ;
}

static void IO_TextRider__WritePad(IO_TextRider__Writer w, OOC_INT32 n) {
  register OOC_INT32 i0,i1,i2;

  i0 = n;
  i1 = i0>0;
  if (!i1) goto l8;
  i1 = (OOC_INT32)w;
  
l3_loop:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7162)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i1, 32u);
  i0 = i0-1;
  n = i0;
  i2 = i0>0;
  if (i2) goto l3_loop;
l8:
  return;
  ;
}

void IO_TextRider__WriterDesc_WriteLInt(IO_TextRider__Writer w, OOC_INT32 lint, OOC_INT32 n) {
  register OOC_INT32 i0,i1,i2;
  OOC_CHAR8 val[16];

  i0 = lint;
  IntStr__IntToStr(i0, (void*)(OOC_INT32)val, 16);
  i0 = Strings__Length((void*)(OOC_INT32)val, 16);
  i1 = n;
  i2 = (OOC_INT32)w;
  IO_TextRider__WritePad((IO_TextRider__Writer)i2, (i1-i0));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 7728)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, (void*)(OOC_INT32)val, 16);
  return;
  ;
}

void IO_TextRider__WriterDesc_WriteSInt(IO_TextRider__Writer w, OOC_INT8 sint, OOC_INT32 n) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)w;
  i1 = sint;
  i2 = n;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7840)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i0, i1, i2);
  return;
  ;
}

void IO_TextRider__WriterDesc_WriteInt(IO_TextRider__Writer w, OOC_INT16 _int, OOC_INT32 n) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)w;
  i1 = _int;
  i2 = n;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7951)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i0, i1, i2);
  return;
  ;
}

void IO_TextRider__WriterDesc_WriteHex(IO_TextRider__Writer w, OOC_INT32 lint, OOC_INT32 d) {
  register OOC_INT32 i0,i1;
  auto void IO_TextRider__WriterDesc_WriteHex_WriteHexDigits(IO_TextRider__Writer w, OOC_INT32 *n, OOC_INT32 digits);
    
    void IO_TextRider__WriterDesc_WriteHex_WriteHexDigits(IO_TextRider__Writer w, OOC_INT32 *n, OOC_INT32 digits) {
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
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8395)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i1, 48u);
      goto l8;
l7:
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8373)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i1, 70u);
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
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8643)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i1, (55+i3));
      goto l20;
l19:
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8597)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i1, (48+i3));
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
  IO_TextRider__WriterDesc_WriteHex_WriteHexDigits((IO_TextRider__Writer)i1, (void*)(OOC_INT32)&lint, i0);
  return;
  ;
}

void IO_TextRider__WriterDesc_WriteLReal(IO_TextRider__Writer w, OOC_REAL64 lreal, OOC_INT32 n, OOC_INT32 k) {
  register OOC_INT32 i0,i1,i2;
  register OOC_REAL64 d0;
  OOC_CHAR8 val[128];

  i0 = k;
  d0 = lreal;
  LRealStr__RealToFloat(d0, i0, (void*)(OOC_INT32)val, 128);
  i0 = Strings__Length((void*)(OOC_INT32)val, 128);
  i1 = n;
  i2 = (OOC_INT32)w;
  IO_TextRider__WritePad((IO_TextRider__Writer)i2, (i1-i0));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 9208)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, (void*)(OOC_INT32)val, 128);
  return;
  ;
}

void IO_TextRider__WriterDesc_WriteReal(IO_TextRider__Writer w, OOC_REAL32 real, OOC_INT32 n, OOC_INT32 k) {
  register OOC_INT32 i0,i1,i2;
  register OOC_REAL32 f0;
  OOC_CHAR8 val[128];

  i0 = k;
  f0 = real;
  RealStr__RealToFloat(f0, i0, (void*)(OOC_INT32)val, 128);
  i0 = Strings__Length((void*)(OOC_INT32)val, 128);
  i1 = n;
  i2 = (OOC_INT32)w;
  IO_TextRider__WritePad((IO_TextRider__Writer)i2, (i1-i0));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 9575)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, (void*)(OOC_INT32)val, 128);
  return;
  ;
}

void IO_TextRider__WriterDesc_WriteLRealFix(IO_TextRider__Writer w, OOC_REAL64 *lreal, OOC_INT32 n, OOC_INT32 k) {
  register OOC_INT32 i0,i1,i2;
  register OOC_REAL64 d0;
  OOC_CHAR8 val[128];

  i0 = k;
  d0 = *lreal;
  LRealStr__RealToFixed(d0, i0, (void*)(OOC_INT32)val, 128);
  i0 = Strings__Length((void*)(OOC_INT32)val, 128);
  i1 = n;
  i2 = (OOC_INT32)w;
  IO_TextRider__WritePad((IO_TextRider__Writer)i2, (i1-i0));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 10016)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, (void*)(OOC_INT32)val, 128);
  return;
  ;
}

void IO_TextRider__WriterDesc_WriteRealFix(IO_TextRider__Writer w, OOC_REAL32 real, OOC_INT32 n, OOC_INT32 k) {
  register OOC_INT32 i0,i1,i2;
  register OOC_REAL32 f0;
  OOC_CHAR8 val[128];

  i0 = k;
  f0 = real;
  RealStr__RealToFixed(f0, i0, (void*)(OOC_INT32)val, 128);
  i0 = Strings__Length((void*)(OOC_INT32)val, 128);
  i1 = n;
  i2 = (OOC_INT32)w;
  IO_TextRider__WritePad((IO_TextRider__Writer)i2, (i1-i0));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 10391)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, (void*)(OOC_INT32)val, 128);
  return;
  ;
}

void IO_TextRider__WriterDesc_WriteLRealEng(IO_TextRider__Writer w, OOC_REAL64 *lreal, OOC_INT32 n, OOC_INT32 k) {
  register OOC_INT32 i0,i1,i2;
  register OOC_REAL64 d0;
  OOC_CHAR8 val[128];

  i0 = k;
  d0 = *lreal;
  LRealStr__RealToEng(d0, i0, (void*)(OOC_INT32)val, 128);
  i0 = Strings__Length((void*)(OOC_INT32)val, 128);
  i1 = n;
  i2 = (OOC_INT32)w;
  IO_TextRider__WritePad((IO_TextRider__Writer)i2, (i1-i0));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 10831)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, (void*)(OOC_INT32)val, 128);
  return;
  ;
}

void IO_TextRider__WriterDesc_WriteRealEng(IO_TextRider__Writer w, OOC_REAL32 real, OOC_INT32 n, OOC_INT32 k) {
  register OOC_INT32 i0,i1,i2;
  register OOC_REAL32 f0;
  OOC_CHAR8 val[128];

  i0 = k;
  f0 = real;
  RealStr__RealToEng(f0, i0, (void*)(OOC_INT32)val, 128);
  i0 = Strings__Length((void*)(OOC_INT32)val, 128);
  i1 = n;
  i2 = (OOC_INT32)w;
  IO_TextRider__WritePad((IO_TextRider__Writer)i2, (i1-i0));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 11204)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, (void*)(OOC_INT32)val, 128);
  return;
  ;
}

void IO_TextRider__WriterDesc_WriteSet(IO_TextRider__Writer w, OOC_UINT32 s) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT8 bit;
  OOC_CHAR8 addComma;
  OOC_INT8 lo;

  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11395)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i0, 123u);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11653)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, ", ", 3);
  
l25:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11706)))), IO_TextRider__WriterDesc_WriteInt)),IO_TextRider__WriterDesc_WriteInt)((IO_TextRider__Writer)i0, i2, 0);
  i2 = i2<i4;
  if (!i2) goto l28;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11758)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "..", 3);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11779)))), IO_TextRider__WriterDesc_WriteInt)),IO_TextRider__WriterDesc_WriteInt)((IO_TextRider__Writer)i0, i4, 0);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11849)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i0, 125u);
  return;
  ;
}

void IO_TextRider__WriterDesc_WriteLn(IO_TextRider__Writer w) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_INT16 i;

  i0 = (OOC_INT32)w;
  i = 0;
  i1 = *(OOC_INT16*)((_check_pointer(i0, 11990))+10);
  i2 = 0<i1;
  if (!i2) goto l8;
  i2=0;
l3_loop:
  i3 = *(OOC_UINT8*)(((_check_pointer(i0, 12025))+8)+(_check_index(i2, 2, OOC_UINT16, 12029)));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12011)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i0, i3);
  i2 = i2+1;
  i = i2;
  i3 = i2<i1;
  if (i3) goto l3_loop;
l8:
  return;
  ;
}

void IO_TextRider__ReaderDesc_INIT(IO_TextRider__Reader r, IO__ByteChannel ch) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)ch;
  *(OOC_INT32*)(_check_pointer(i0, 12387)) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 12408))+4) = 0;
  *(OOC_INT8*)((_check_pointer(i0, 12427))+21) = 0;
  *(OOC_UINT8*)((_check_pointer(i0, 12445))+20) = 0u;
  *(OOC_INT32*)((_check_pointer(i0, 12474))+4) = ((OOC_INT32)RT0__NewObject(_td_IO_TextRider__Buffer.baseTypes[0], 80));
  *(OOC_INT32*)((_check_pointer(i0, 12514))+8) = ((OOC_INT32)RT0__NewObject(_td_IO_TextRider__Buffer.baseTypes[0], 80));
  *(OOC_INT32*)((_check_pointer(i0, 12547))+16) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 12568))+12) = 0;
  return;
  ;
}

IO_TextRider__Reader IO_TextRider__ConnectReader(IO__ByteChannel ch) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)RT0__NewObject(_td_IO_TextRider__Reader.baseTypes[0]);
  i1 = (OOC_INT32)ch;
  IO_TextRider__ReaderDesc_INIT((IO_TextRider__Reader)i0, (IO__ByteChannel)i1);
  return (IO_TextRider__Reader)i0;
  ;
}

void IO_TextRider__ReaderDesc_SetEOL(IO_TextRider__Reader r, OOC_INT8 type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)r;
  i1 = type;
  *(OOC_INT8*)((_check_pointer(i0, 13251))+21) = i1;
  return;
  ;
}

void IO_TextRider__ReaderDesc_AquireBufferWithSize(IO_TextRider__Reader r, OOC_INT32 size) {
  register OOC_INT32 i0,i1,i2,i3;
  IO_TextRider__Buffer tmp;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13484))+4);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l3;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13506))+4);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 13513)), 0);
  i2 = size;
  i1 = i1<i2;
  
  goto l5;
l3:
  i1=1u;
l5:
  if (!i1) goto l7;
  i1 = size;
  i1 = i1+(i1>>1);
  *(OOC_INT32*)((_check_pointer(i0, 13538))+8) = ((OOC_INT32)RT0__NewObject(_td_IO_TextRider__Buffer.baseTypes[0], i1));
  i1 = (OOC_INT32)RT0__NewObject(_td_IO_TextRider__Buffer.baseTypes[0], i1);
  tmp = (IO_TextRider__Buffer)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13606))+4);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i1, 13618)), 0);
  _copy_8((const void*)(_check_pointer(i2, 13613)),(void*)(_check_pointer(i1, 13618)),i3);
  *(OOC_INT32*)((_check_pointer(i0, 13651))+4) = i1;
l7:
  return;
  ;
}

void IO_TextRider__ReaderDesc_ReadLineBuffer(IO_TextRider__Reader r) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_CHAR8 ch;

  i0 = (OOC_INT32)r;
  *(OOC_INT32*)((_check_pointer(i0, 14111))+12) = 0;
  *(OOC_UINT8*)((_check_pointer(i0, 14125))+20) = 0u;
  *(OOC_INT32*)((_check_pointer(i0, 14150))+16) = 0;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 14177))+21);
  switch (i1) {
  case 0:
    i1 = (OOC_INT32)_c0;
l3_loop:
    i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14222));
    i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14222));
    i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 14230)))), IO__ByteChannelDesc_Read)),IO__ByteChannelDesc_Read)((IO__ByteChannel)i3, (void*)(OOC_INT32)&ch, 1, 0, 1);
    i2 = i2!=1;
    if (!i2) goto l10;
    i2 = *(OOC_INT32*)((_check_pointer(i0, 14266))+16);
    i2 = i2==0;
    if (i2) goto l8;
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14359))+4);
    i2 = _check_pointer(i2, 14366);
    i3 = *(OOC_INT32*)((_check_pointer(i0, 14368))+16);
    i4 = OOC_ARRAY_LENGTH(i2, 0);
    *(OOC_UINT8*)(i2+(_check_index(i3, i4, OOC_UINT32, 14366))) = 0u;
    return;
    goto l10;
l8:
    IO_TextRider__RaiseProtocolError((Object__String)i1);
l10:
    i2 = *(OOC_INT32*)((_check_pointer(i0, 14467))+16);
    IO_TextRider__ReaderDesc_AquireBufferWithSize((IO_TextRider__Reader)i0, (i2+1));
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14492))+4);
    i2 = _check_pointer(i2, 14499);
    i3 = *(OOC_INT32*)((_check_pointer(i0, 14501))+16);
    i4 = OOC_ARRAY_LENGTH(i2, 0);
    i5 = ch;
    *(OOC_UINT8*)(i2+(_check_index(i3, i4, OOC_UINT32, 14499))) = i5;
    i2 = i5==10u;
    if (i2) goto l12;
    goto l13;
l12:
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14559))+4);
    i2 = _check_pointer(i2, 14566);
    i3 = *(OOC_INT32*)((_check_pointer(i0, 14568))+16);
    i4 = OOC_ARRAY_LENGTH(i2, 0);
    *(OOC_UINT8*)(i2+(_check_index(i3, i4, OOC_UINT32, 14566))) = 0u;
    *(OOC_UINT8*)((_check_pointer(i0, 14597))+20) = 1u;
    return;
l13:
    i2 = *(OOC_INT32*)((_check_pointer(i0, 14661))+16);
    *(OOC_INT32*)((_check_pointer(i0, 14661))+16) = (i2+1);
    
    goto l3_loop;
  case 1:
    i1 = (OOC_INT32)_c1;
l16_loop:
    i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14724));
    i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14724));
    i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 14732)))), IO__ByteChannelDesc_Read)),IO__ByteChannelDesc_Read)((IO__ByteChannel)i3, (void*)(OOC_INT32)&ch, 1, 0, 1);
    i2 = i2!=1;
    if (!i2) goto l23;
    i2 = *(OOC_INT32*)((_check_pointer(i0, 14768))+16);
    i2 = i2==0;
    if (i2) goto l21;
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14861))+4);
    i2 = _check_pointer(i2, 14868);
    i3 = *(OOC_INT32*)((_check_pointer(i0, 14870))+16);
    i4 = OOC_ARRAY_LENGTH(i2, 0);
    *(OOC_UINT8*)(i2+(_check_index(i3, i4, OOC_UINT32, 14868))) = 0u;
    return;
    goto l23;
l21:
    IO_TextRider__RaiseProtocolError((Object__String)i1);
l23:
    i2 = *(OOC_INT32*)((_check_pointer(i0, 14969))+16);
    IO_TextRider__ReaderDesc_AquireBufferWithSize((IO_TextRider__Reader)i0, (i2+1));
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14994))+4);
    i2 = _check_pointer(i2, 15001);
    i3 = *(OOC_INT32*)((_check_pointer(i0, 15003))+16);
    i4 = OOC_ARRAY_LENGTH(i2, 0);
    i5 = ch;
    *(OOC_UINT8*)(i2+(_check_index(i3, i4, OOC_UINT32, 15001))) = i5;
    i2 = i5==13u;
    if (i2) goto l25;
    goto l26;
l25:
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15061))+4);
    i2 = _check_pointer(i2, 15068);
    i3 = *(OOC_INT32*)((_check_pointer(i0, 15070))+16);
    i4 = OOC_ARRAY_LENGTH(i2, 0);
    *(OOC_UINT8*)(i2+(_check_index(i3, i4, OOC_UINT32, 15068))) = 0u;
    *(OOC_UINT8*)((_check_pointer(i0, 15099))+20) = 1u;
    return;
l26:
    i2 = *(OOC_INT32*)((_check_pointer(i0, 15163))+16);
    *(OOC_INT32*)((_check_pointer(i0, 15163))+16) = (i2+1);
    
    goto l16_loop;
  case 2:
    i1 = (OOC_INT32)_c2;
l29_loop:
    i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 15227));
    i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 15227));
    i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 15235)))), IO__ByteChannelDesc_Read)),IO__ByteChannelDesc_Read)((IO__ByteChannel)i3, (void*)(OOC_INT32)&ch, 1, 0, 1);
    i2 = i2!=1;
    if (!i2) goto l36;
    i2 = *(OOC_INT32*)((_check_pointer(i0, 15271))+16);
    i2 = i2==0;
    if (i2) goto l34;
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15364))+4);
    i2 = _check_pointer(i2, 15371);
    i3 = *(OOC_INT32*)((_check_pointer(i0, 15373))+16);
    i4 = OOC_ARRAY_LENGTH(i2, 0);
    *(OOC_UINT8*)(i2+(_check_index(i3, i4, OOC_UINT32, 15371))) = 0u;
    return;
    goto l36;
l34:
    IO_TextRider__RaiseProtocolError((Object__String)i1);
l36:
    i2 = *(OOC_INT32*)((_check_pointer(i0, 15472))+16);
    IO_TextRider__ReaderDesc_AquireBufferWithSize((IO_TextRider__Reader)i0, (i2+1));
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15497))+4);
    i2 = _check_pointer(i2, 15504);
    i3 = *(OOC_INT32*)((_check_pointer(i0, 15506))+16);
    i4 = OOC_ARRAY_LENGTH(i2, 0);
    i5 = ch;
    *(OOC_UINT8*)(i2+(_check_index(i3, i4, OOC_UINT32, 15504))) = i5;
    i2 = i5==10u;
    if (i2) goto l39;
    i2=0u;
    goto l41;
l39:
    i2 = *(OOC_INT32*)((_check_pointer(i0, 15554))+16);
    i2 = i2>0;
    
l41:
    if (i2) goto l43;
    i2=0u;
    goto l45;
l43:
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15573))+4);
    i2 = _check_pointer(i2, 15580);
    i3 = *(OOC_INT32*)((_check_pointer(i0, 15582))+16);
    i4 = OOC_ARRAY_LENGTH(i2, 0);
    i2 = *(OOC_UINT8*)(i2+(_check_index((i3-1), i4, OOC_UINT32, 15580)));
    i2 = i2==13u;
    
l45:
    if (i2) goto l46;
    goto l47;
l46:
    i2 = *(OOC_INT32*)((_check_pointer(i0, 15627))+16);
    *(OOC_INT32*)((_check_pointer(i0, 15627))+16) = (i2-1);
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15681))+4);
    i2 = _check_pointer(i2, 15688);
    i3 = *(OOC_INT32*)((_check_pointer(i0, 15690))+16);
    i4 = OOC_ARRAY_LENGTH(i2, 0);
    *(OOC_UINT8*)(i2+(_check_index(i3, i4, OOC_UINT32, 15688))) = 0u;
    *(OOC_UINT8*)((_check_pointer(i0, 15719))+20) = 1u;
    return;
l47:
    i2 = *(OOC_INT32*)((_check_pointer(i0, 15783))+16);
    *(OOC_INT32*)((_check_pointer(i0, 15783))+16) = (i2+1);
    
    goto l29_loop;
  default:
    _failed_case(i1, 14171);
    goto l50;
  }
l50:
  return;
  ;
}

void IO_TextRider__ReaderDesc_ConsumeWhiteSpace(IO_TextRider__Reader r) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)r;
l1_loop:
  i1 = *(OOC_INT32*)((_check_pointer(i0, 16224))+12);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 16230))+16);
  i1 = i1==i2;
  if (!i1) goto l8;
l3_loop:
  IO_TextRider__ReaderDesc_ReadLineBuffer((IO_TextRider__Reader)i0);
  i1 = *(OOC_INT32*)((_check_pointer(i0, 16224))+12);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 16230))+16);
  i1 = i1==i2;
  if (i1) goto l3_loop;
l8:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16345))+4);
  i1 = _check_pointer(i1, 16352);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 16354))+12);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_UINT8*)(i1+(_check_index(i2, i3, OOC_UINT32, 16352)));
  i1 = (OOC_UINT8)i1>(OOC_UINT8)32u;
  if (i1) goto l11;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16370))+4);
  i1 = _check_pointer(i1, 16377);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 16379))+12);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_UINT8*)(i1+(_check_index(i2, i3, OOC_UINT32, 16377)));
  i1 = i1==9u;
  
  goto l13;
l11:
  i1=1u;
l13:
  if (i1) goto l14;
  goto l15;
l14:
  return;
l15:
  i1 = *(OOC_INT32*)((_check_pointer(i0, 16439))+12);
  *(OOC_INT32*)((_check_pointer(i0, 16439))+12) = (i1+1);
  
  goto l1_loop;
l17:
  ;
}

void IO_TextRider__ReaderDesc_ReadChar(IO_TextRider__Reader r, OOC_CHAR8 *ch) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)r;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 16747))+12);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 16753))+16);
  i1 = i1==i2;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 16770))+20);
  i1 = !i1;
  
l5:
  if (!i1) goto l7;
  IO_TextRider__ReaderDesc_ReadLineBuffer((IO_TextRider__Reader)i0);
l7:
  i1 = *(OOC_INT32*)((_check_pointer(i0, 16830))+12);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 16836))+16);
  i1 = i1==i2;
  if (i1) goto l10;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17173))+4);
  i1 = _check_pointer(i1, 17180);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i3 = *(OOC_INT32*)((_check_pointer(i0, 17182))+12);
  i1 = *(OOC_UINT8*)(i1+(_check_index(i3, i2, OOC_UINT32, 17180)));
  *ch = i1;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 17200))+12);
  *(OOC_INT32*)((_check_pointer(i0, 17200))+12) = (i1+1);
  goto l11;
l10:
  *ch = 10u;
  *(OOC_UINT8*)((_check_pointer(i0, 17133))+20) = 0u;
l11:
  return;
  ;
}

void IO_TextRider__ReaderDesc_ReadString(IO_TextRider__Reader r, OOC_CHAR8 s[], OOC_LEN s_0d) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9;
  OOC_CHAR8 quote;
  OOC_INT32 pos;

  i0 = (OOC_INT32)r;
  IO_TextRider__ReaderDesc_ConsumeWhiteSpace((IO_TextRider__Reader)i0);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18439))+4);
  i1 = _check_pointer(i1, 18446);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 18448))+12);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_UINT8*)(i1+(_check_index(i2, i3, OOC_UINT32, 18446)));
  quote = i1;
  i2 = i1!=34u;
  if (i2) goto l3;
  i2=0u;
  goto l5;
l3:
  i2 = i1!=39u;
  
l5:
  if (!i2) goto l7;
  IO__RaiseFormatError((Object__String)((OOC_INT32)_c3));
l7:
  i2 = *(OOC_INT32*)((_check_pointer(i0, 18559))+12);
  *(OOC_INT32*)((_check_pointer(i0, 18559))+12) = (i2+1);
  i2 = (OOC_INT32)_c4;
  i3 = (OOC_INT32)_c5;
  i4 = (OOC_INT32)_c6;
  i5 = s_0d-1;
  pos = 0;
  i6=0;
l8_loop:
  i7 = *(OOC_INT32*)((_check_pointer(i0, 18597))+12);
  i8 = *(OOC_INT32*)((_check_pointer(i0, 18603))+16);
  i7 = i7==i8;
  if (i7) goto l23;
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18694))+4);
  i7 = _check_pointer(i7, 18701);
  i8 = *(OOC_INT32*)((_check_pointer(i0, 18703))+12);
  i9 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = *(OOC_UINT8*)(i7+(_check_index(i8, i9, OOC_UINT32, 18701)));
  i7 = i7==i1;
  if (i7) goto l21;
  i7 = i6>=i5;
  if (i7) goto l19;
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18901))+4);
  i7 = _check_pointer(i7, 18908);
  i8 = *(OOC_INT32*)((_check_pointer(i0, 18910))+12);
  i9 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = *(OOC_UINT8*)(i7+(_check_index(i8, i9, OOC_UINT32, 18908)));
  i7 = (OOC_UINT8)i7<(OOC_UINT8)32u;
  if (i7) goto l17;
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19073))+4);
  i7 = _check_pointer(i7, 19080);
  i8 = *(OOC_INT32*)((_check_pointer(i0, 19082))+12);
  i9 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = *(OOC_UINT8*)(i7+(_check_index(i8, i9, OOC_UINT32, 19080)));
  *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i6, s_0d, OOC_UINT32, 19065))) = i7;
  goto l24;
l17:
  *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i6, s_0d, OOC_UINT32, 18934))) = 0u;
  IO__RaiseFormatError((Object__String)i3);
  goto l24;
l19:
  IO_TextRider__RaiseOverflowError((Object__String)i4);
  goto l24;
l21:
  i7 = *(OOC_INT32*)((_check_pointer(i0, 18733))+12);
  *(OOC_INT32*)((_check_pointer(i0, 18733))+12) = (i7+1);
  *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i6, s_0d, OOC_UINT32, 18749))) = 0u;
  return;
  goto l24;
l23:
  IO__RaiseFormatError((Object__String)i2);
l24:
  i6 = i6+1;
  pos = i6;
  i7 = *(OOC_INT32*)((_check_pointer(i0, 19128))+12);
  *(OOC_INT32*)((_check_pointer(i0, 19128))+12) = (i7+1);
  
  goto l8_loop;
l26:
  ;
}

void IO_TextRider__ReaderDesc_ReadLInt(IO_TextRider__Reader r, OOC_INT32 *lint) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_INT32 x;
  OOC_INT8 res;

  i0 = (OOC_INT32)r;
  IO_TextRider__ReaderDesc_ConsumeWhiteSpace((IO_TextRider__Reader)i0);
  x = 0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19637))+4);
  i1 = _check_pointer(i1, 19644);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 19646))+12);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_UINT8*)(i1+(_check_index(i2, i3, OOC_UINT32, 19644)));
  i1 = i1==43u;
  if (i1) goto l3;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19662))+4);
  i1 = _check_pointer(i1, 19669);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 19671))+12);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_UINT8*)(i1+(_check_index(i2, i3, OOC_UINT32, 19669)));
  i1 = i1==45u;
  
  goto l5;
l3:
  i1=1u;
l5:
  if (i1) goto l7;
  i1=0;
  goto l8;
l7:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19694))+8);
  i1 = _check_pointer(i1, 19698);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19704))+4);
  i3 = _check_pointer(i3, 19711);
  i4 = *(OOC_INT32*)((_check_pointer(i0, 19713))+12);
  i5 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = *(OOC_UINT8*)(i3+(_check_index(i4, i5, OOC_UINT32, 19711)));
  *(OOC_UINT8*)(i1+(_check_index(0, i2, OOC_UINT32, 19698))) = i3;
  x = 1;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 19745))+12);
  *(OOC_INT32*)((_check_pointer(i0, 19745))+12) = (i1+1);
  i1=1;
l8:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19880))+4);
  i2 = _check_pointer(i2, 19887);
  i3 = *(OOC_INT32*)((_check_pointer(i0, 19889))+12);
  i4 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = *(OOC_UINT8*)(i2+(_check_index(i3, i4, OOC_UINT32, 19887)));
  i2 = (OOC_UINT8)i2>=(OOC_UINT8)48u;
  if (i2) goto l11;
  i2=0u;
  goto l13;
l11:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19905))+4);
  i2 = _check_pointer(i2, 19912);
  i3 = *(OOC_INT32*)((_check_pointer(i0, 19914))+12);
  i4 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = *(OOC_UINT8*)(i2+(_check_index(i3, i4, OOC_UINT32, 19912)));
  i2 = (OOC_UINT8)i2<=(OOC_UINT8)57u;
  
l13:
  if (i2) goto l15;
  IO__RaiseFormatError((Object__String)((OOC_INT32)_c7));
  
  goto l16;
l15:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19938))+8);
  i2 = _check_pointer(i2, 19942);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19948))+4);
  i4 = _check_pointer(i4, 19955);
  i5 = *(OOC_INT32*)((_check_pointer(i0, 19957))+12);
  i6 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = *(OOC_UINT8*)(i4+(_check_index(i5, i6, OOC_UINT32, 19955)));
  *(OOC_UINT8*)(i2+(_check_index(i1, i3, OOC_UINT32, 19942))) = i4;
  i1 = i1+1;
  x = i1;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 19989))+12);
  *(OOC_INT32*)((_check_pointer(i0, 19989))+12) = (i2+1);
  
l16:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20079))+4);
  i2 = _check_pointer(i2, 20086);
  i3 = *(OOC_INT32*)((_check_pointer(i0, 20088))+12);
  i4 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = *(OOC_UINT8*)(i2+(_check_index(i3, i4, OOC_UINT32, 20086)));
  i2 = (OOC_UINT8)i2>=(OOC_UINT8)48u;
  if (i2) goto l19;
  i2=0u;
  goto l21;
l19:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20104))+4);
  i2 = _check_pointer(i2, 20111);
  i3 = *(OOC_INT32*)((_check_pointer(i0, 20113))+12);
  i4 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = *(OOC_UINT8*)(i2+(_check_index(i3, i4, OOC_UINT32, 20111)));
  i2 = (OOC_UINT8)i2<=(OOC_UINT8)57u;
  
l21:
  if (!i2) goto l33;
l24_loop:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20135))+8);
  i2 = _check_pointer(i2, 20139);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20145))+4);
  i4 = _check_pointer(i4, 20152);
  i5 = *(OOC_INT32*)((_check_pointer(i0, 20154))+12);
  i6 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = *(OOC_UINT8*)(i4+(_check_index(i5, i6, OOC_UINT32, 20152)));
  *(OOC_UINT8*)(i2+(_check_index(i1, i3, OOC_UINT32, 20139))) = i4;
  i1 = i1+1;
  x = i1;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 20186))+12);
  *(OOC_INT32*)((_check_pointer(i0, 20186))+12) = (i2+1);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20079))+4);
  i2 = _check_pointer(i2, 20086);
  i3 = *(OOC_INT32*)((_check_pointer(i0, 20088))+12);
  i4 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = *(OOC_UINT8*)(i2+(_check_index(i3, i4, OOC_UINT32, 20086)));
  i2 = (OOC_UINT8)i2>=(OOC_UINT8)48u;
  if (i2) goto l27;
  i2=0u;
  goto l29;
l27:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20104))+4);
  i2 = _check_pointer(i2, 20111);
  i3 = *(OOC_INT32*)((_check_pointer(i0, 20113))+12);
  i4 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = *(OOC_UINT8*)(i2+(_check_index(i3, i4, OOC_UINT32, 20111)));
  i2 = (OOC_UINT8)i2<=(OOC_UINT8)57u;
  
l29:
  if (i2) goto l24_loop;
l33:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20208))+8);
  i2 = _check_pointer(i2, 20212);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  *(OOC_UINT8*)(i2+(_check_index(i1, i3, OOC_UINT32, 20212))) = 0u;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20243))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20243))+8);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 20247)), 0);
  IntStr__StrToInt((void*)(_check_pointer(i0, 20247)), i1, (void*)(OOC_INT32)lint, (void*)(OOC_INT32)&res);
  i0 = res;
  i1 = i0!=0;
  if (!i1) goto l40;
  i0 = i0==1;
  if (i0) goto l38;
  IO__RaiseFormatError((Object__String)((OOC_INT32)_c8));
  goto l40;
l38:
  IO_TextRider__RaiseOverflowError((Object__String)((OOC_INT32)_c9));
l40:
  return;
  ;
}

void IO_TextRider__ReaderDesc_ReadInt(IO_TextRider__Reader r, OOC_INT16 *_int) {
  register OOC_INT32 i0,i1;
  OOC_INT32 tmp;

  i0 = (OOC_INT32)r;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20626)))), IO_TextRider__ReaderDesc_ReadLInt)),IO_TextRider__ReaderDesc_ReadLInt)((IO_TextRider__Reader)i0, (void*)(OOC_INT32)&tmp);
  i0 = tmp;
  i1 = i0>=(-32768);
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = i0<=32767;
  
l5:
  if (i1) goto l7;
  IO__RaiseFormatError((Object__String)((OOC_INT32)_c10));
  goto l8;
l7:
  *_int = i0;
l8:
  return;
  ;
}

void IO_TextRider__ReaderDesc_ReadSInt(IO_TextRider__Reader r, OOC_INT8 *sint) {
  register OOC_INT32 i0,i1;
  OOC_INT32 tmp;

  i0 = (OOC_INT32)r;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20950)))), IO_TextRider__ReaderDesc_ReadLInt)),IO_TextRider__ReaderDesc_ReadLInt)((IO_TextRider__Reader)i0, (void*)(OOC_INT32)&tmp);
  i0 = tmp;
  i1 = i0>=(-128);
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = i0<=127;
  
l5:
  if (i1) goto l7;
  IO__RaiseFormatError((Object__String)((OOC_INT32)_c11));
  goto l8;
l7:
  *sint = i0;
l8:
  return;
  ;
}

void IO_TextRider__ReaderDesc_ReadIdentifier(IO_TextRider__Reader r, OOC_CHAR8 s[], OOC_LEN s_0d) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_INT32 x;

  _assert((s_0d>=2), 127, 21620);
  i0 = (OOC_INT32)r;
  IO_TextRider__ReaderDesc_ConsumeWhiteSpace((IO_TextRider__Reader)i0);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21694))+4);
  i1 = _check_pointer(i1, 21701);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 21703))+12);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_UINT8*)(i1+(_check_index(i2, i3, OOC_UINT32, 21701)));
  i1 = CharClass__IsLetter(i1);
  i1 = !i1;
  if (!i1) goto l3;
  IO__RaiseFormatError((Object__String)((OOC_INT32)_c12));
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21792))+4);
  i1 = _check_pointer(i1, 21799);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 21801))+12);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_UINT8*)(i1+(_check_index(i2, i3, OOC_UINT32, 21799)));
  *(OOC_UINT8*)((OOC_INT32)s+(_check_index(0, s_0d, OOC_UINT8, 21786))) = i1;
  x = 1;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 21827))+12);
  *(OOC_INT32*)((_check_pointer(i0, 21827))+12) = (i1+1);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21866))+4);
  i1 = _check_pointer(i1, 21873);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 21875))+12);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_UINT8*)(i1+(_check_index(i2, i3, OOC_UINT32, 21873)));
  i1 = CharClass__IsLetter(i1);
  if (i1) goto l6;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21906))+4);
  i1 = _check_pointer(i1, 21913);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 21915))+12);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_UINT8*)(i1+(_check_index(i2, i3, OOC_UINT32, 21913)));
  i1 = CharClass__IsNumeric(i1);
  
  goto l8;
l6:
  i1=1u;
l8:
  if (i1) goto l10;
  i0=1;
  goto l23;
l10:
  i1 = (OOC_INT32)_c13;
  i2 = s_0d-1;
  i3=1;
l11_loop:
  i4 = i3>=i2;
  if (!i4) goto l14;
  IO_TextRider__RaiseOverflowError((Object__String)i1);
l14:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22057))+4);
  i4 = _check_pointer(i4, 22064);
  i5 = *(OOC_INT32*)((_check_pointer(i0, 22066))+12);
  i6 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = *(OOC_UINT8*)(i4+(_check_index(i5, i6, OOC_UINT32, 22064)));
  *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i3, s_0d, OOC_UINT32, 22051))) = i4;
  i3 = i3+1;
  x = i3;
  i4 = *(OOC_INT32*)((_check_pointer(i0, 22098))+12);
  *(OOC_INT32*)((_check_pointer(i0, 22098))+12) = (i4+1);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21866))+4);
  i4 = _check_pointer(i4, 21873);
  i5 = *(OOC_INT32*)((_check_pointer(i0, 21875))+12);
  i6 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = *(OOC_UINT8*)(i4+(_check_index(i5, i6, OOC_UINT32, 21873)));
  i4 = CharClass__IsLetter(i4);
  if (i4) goto l17;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21906))+4);
  i4 = _check_pointer(i4, 21913);
  i5 = *(OOC_INT32*)((_check_pointer(i0, 21915))+12);
  i6 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = *(OOC_UINT8*)(i4+(_check_index(i5, i6, OOC_UINT32, 21913)));
  i4 = CharClass__IsNumeric(i4);
  
  goto l19;
l17:
  i4=1u;
l19:
  if (i4) goto l11_loop;
l22:
  i0=i3;
l23:
  *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i0, s_0d, OOC_UINT32, 22120))) = 0u;
  return;
  ;
}

void IO_TextRider__ReaderDesc_ReadBool(IO_TextRider__Reader r, OOC_CHAR8 *_bool) {
  register OOC_INT32 i0;
  OOC_CHAR8 ident[8];

  i0 = (OOC_INT32)r;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22535)))), IO_TextRider__ReaderDesc_ReadIdentifier)),IO_TextRider__ReaderDesc_ReadIdentifier)((IO_TextRider__Reader)i0, (void*)(OOC_INT32)ident, 8);
  i0 = (
  _cmp8((const void*)(OOC_INT32)ident,(const void*)"TRUE"))==0;
  if (i0) goto l7;
  i0 = (
  _cmp8((const void*)(OOC_INT32)ident,(const void*)"FALSE"))==0;
  if (i0) goto l5;
  IO__RaiseFormatError((Object__String)((OOC_INT32)_c14));
  goto l8;
l5:
  *_bool = 0u;
  goto l8;
l7:
  *_bool = 1u;
l8:
  return;
  ;
}

static OOC_CHAR8 IO_TextRider__HexDigit(OOC_CHAR8 ch) {
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

static OOC_CHAR8 IO_TextRider__HexToInt(const OOC_CHAR8 str__ref[], OOC_LEN str_0d, OOC_INT32 *lint) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_ALLOCATE_VPAR(str,OOC_CHAR8 ,str_0d)
  OOC_INT16 spos;
  OOC_INT16 epos;
  auto OOC_INT16 IO_TextRider__HexToInt_GetDigit(OOC_CHAR8 c);
    
    OOC_INT16 IO_TextRider__HexToInt_GetDigit(OOC_CHAR8 c) {
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
  i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT16, 23801)));
  i0 = i0!=0u;
  if (i0) goto l3;
  i0=0;
  goto l9;
l3:
  i0=0;
l4_loop:
  i0 = i0+1;
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT16, 23801)));
  i1 = i1!=0u;
  if (i1) goto l4_loop;
l9:
  i1 = i0-1;
  epos = i1;
  i2 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT16, 23904)));
  i2 = i2==48u;
  if (i2) goto l12;
  i2=0;
  goto l18;
l12:
  i2=0;
l13_loop:
  i2 = i2+1;
  spos = i2;
  i3 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i2, str_0d, OOC_UINT16, 23904)));
  i3 = i3==48u;
  if (i3) goto l13_loop;
l18:
  i3 = (i1-i2)>7;
  if (i3) goto l40;
  i3 = i2<i0;
  if (!i3) goto l41;
  i3 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i2, str_0d, OOC_UINT16, 24191)));
  i3 = IO_TextRider__HexToInt_GetDigit(i3);
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
  i4 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i3, str_0d, OOC_UINT16, 24581)));
  i4 = IO_TextRider__HexToInt_GetDigit(i4);
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

void IO_TextRider__ReaderDesc_ReadHex(IO_TextRider__Reader r, OOC_INT32 *_int) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_INT32 x;

  i0 = (OOC_INT32)r;
  IO_TextRider__ReaderDesc_ConsumeWhiteSpace((IO_TextRider__Reader)i0);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25083))+4);
  i1 = _check_pointer(i1, 25090);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 25092))+12);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_UINT8*)(i1+(_check_index(i2, i3, OOC_UINT32, 25090)));
  i1 = CharClass__IsNumeric(i1);
  i1 = !i1;
  if (!i1) goto l3;
  IO__RaiseFormatError((Object__String)((OOC_INT32)_c15));
l3:
  x = 0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25196))+8);
  i1 = _check_pointer(i1, 25200);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25206))+4);
  i3 = _check_pointer(i3, 25213);
  i4 = *(OOC_INT32*)((_check_pointer(i0, 25215))+12);
  i5 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = *(OOC_UINT8*)(i3+(_check_index(i4, i5, OOC_UINT32, 25213)));
  *(OOC_UINT8*)(i1+(_check_index(0, i2, OOC_UINT32, 25200))) = i3;
  x = 1;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 25243))+12);
  *(OOC_INT32*)((_check_pointer(i0, 25243))+12) = (i1+1);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25271))+4);
  i1 = _check_pointer(i1, 25278);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 25280))+12);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_UINT8*)(i1+(_check_index(i2, i3, OOC_UINT32, 25278)));
  i1 = IO_TextRider__HexDigit(i1);
  if (i1) goto l6;
  i1=1;
  goto l12;
l6:
  i1=1;
l7_loop:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25297))+8);
  i2 = _check_pointer(i2, 25301);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25307))+4);
  i4 = _check_pointer(i4, 25314);
  i5 = *(OOC_INT32*)((_check_pointer(i0, 25316))+12);
  i6 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = *(OOC_UINT8*)(i4+(_check_index(i5, i6, OOC_UINT32, 25314)));
  *(OOC_UINT8*)(i2+(_check_index(i1, i3, OOC_UINT32, 25301))) = i4;
  i1 = i1+1;
  x = i1;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 25348))+12);
  *(OOC_INT32*)((_check_pointer(i0, 25348))+12) = (i2+1);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25271))+4);
  i2 = _check_pointer(i2, 25278);
  i3 = *(OOC_INT32*)((_check_pointer(i0, 25280))+12);
  i4 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = *(OOC_UINT8*)(i2+(_check_index(i3, i4, OOC_UINT32, 25278)));
  i2 = IO_TextRider__HexDigit(i2);
  if (i2) goto l7_loop;
l12:
  i2 = *(OOC_INT32*)((_check_pointer(i0, 25380))+16);
  i3 = *(OOC_INT32*)((_check_pointer(i0, 25374))+12);
  i2 = i3==i2;
  if (i2) goto l15;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25398))+4);
  i2 = _check_pointer(i2, 25405);
  i3 = *(OOC_INT32*)((_check_pointer(i0, 25407))+12);
  i4 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = *(OOC_UINT8*)(i2+(_check_index(i3, i4, OOC_UINT32, 25405)));
  i2 = i2!=72u;
  
  goto l17;
l15:
  i2=1u;
l17:
  if (!i2) goto l19;
  IO__RaiseFormatError((Object__String)((OOC_INT32)_c16));
l19:
  i2 = *(OOC_INT32*)((_check_pointer(i0, 25566))+12);
  *(OOC_INT32*)((_check_pointer(i0, 25566))+12) = (i2+1);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25579))+8);
  i2 = _check_pointer(i2, 25583);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  *(OOC_UINT8*)(i2+(_check_index(i1, i3, OOC_UINT32, 25583))) = 0u;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25611))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25611))+8);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 25615)), 0);
  i0 = IO_TextRider__HexToInt((void*)(_check_pointer(i0, 25615)), i1, (void*)(OOC_INT32)_int);
  i0 = !i0;
  if (!i0) goto l22;
  IO__RaiseFormatError((Object__String)((OOC_INT32)_c17));
l22:
  return;
  ;
}

void IO_TextRider__ReaderDesc_ReadLn(IO_TextRider__Reader r) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)r;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 25885))+16);
  *(OOC_INT32*)((_check_pointer(i0, 25878))+12) = i1;
  return;
  ;
}

void IO_TextRider__ReaderDesc_ReadLine(IO_TextRider__Reader r, OOC_CHAR8 s[], OOC_LEN s_0d) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_INT32 pos;

  _assert((s_0d>0), 127, 26967);
  i0 = (OOC_INT32)r;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 26994))+12);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 27000))+16);
  i1 = i1==i2;
  if (!i1) goto l11;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 27064))+16);
  i1 = i1>0;
  if (i1) goto l5;
  i1=0u;
  goto l7;
l5:
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 27082))+20);
  
l7:
  if (i1) goto l9;
  IO_TextRider__ReaderDesc_ReadLineBuffer((IO_TextRider__Reader)i0);
  goto l11;
l9:
  *(OOC_UINT8*)((OOC_INT32)s+(_check_index(0, s_0d, OOC_UINT8, 27189))) = 0u;
  *(OOC_UINT8*)((_check_pointer(i0, 27207))+20) = 0u;
  return;
l11:
  i1 = s_0d-1;
  i2 = (OOC_INT32)_c18;
  pos = 0;
  i3=0;
l12_loop:
  i4 = i3==i1;
  if (i4) goto l19;
  i4 = *(OOC_INT32*)((_check_pointer(i0, 27469))+12);
  i5 = *(OOC_INT32*)((_check_pointer(i0, 27475))+16);
  i4 = i4==i5;
  if (i4) goto l17;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27639))+4);
  i4 = _check_pointer(i4, 27646);
  i5 = *(OOC_INT32*)((_check_pointer(i0, 27648))+12);
  i6 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = *(OOC_UINT8*)(i4+(_check_index(i5, i6, OOC_UINT32, 27646)));
  *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i3, s_0d, OOC_UINT32, 27631))) = i4;
  goto l20;
l17:
  *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i3, s_0d, OOC_UINT32, 27501))) = 0u;
  *(OOC_UINT8*)((_check_pointer(i0, 27521))+20) = 0u;
  return;
  goto l20;
l19:
  *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i3, s_0d, OOC_UINT32, 27396))) = 0u;
  IO__RaiseFormatError((Object__String)i2);
l20:
  i3 = i3+1;
  pos = i3;
  i4 = *(OOC_INT32*)((_check_pointer(i0, 27694))+12);
  *(OOC_INT32*)((_check_pointer(i0, 27694))+12) = (i4+1);
  
  goto l12_loop;
l22:
  ;
}

void OOC_IO_TextRider_init(void) {
  _c0 = Object__NewLatin1Region("Short file", 11, 0, 10);
  _c1 = Object__NewLatin1Region("Short file", 11, 0, 10);
  _c2 = Object__NewLatin1Region("Short file", 11, 0, 10);
  _c3 = Object__NewLatin1Region("No string found", 16, 0, 15);
  _c4 = Object__NewLatin1Region("No quote mark until line end", 29, 0, 28);
  _c5 = Object__NewLatin1Region("Illegal character in string", 28, 0, 27);
  _c6 = Object__NewLatin1Region("buffer too small", 17, 0, 16);
  _c7 = Object__NewLatin1Region("No valid number found", 22, 0, 21);
  _c8 = Object__NewLatin1Region("No valid number found", 22, 0, 21);
  _c9 = Object__NewLatin1Region("Value out of range", 19, 0, 18);
  _c10 = Object__NewLatin1Region("read value out of range", 24, 0, 23);
  _c11 = Object__NewLatin1Region("read value out of range", 24, 0, 23);
  _c12 = Object__NewLatin1Region("No identifier value found", 26, 0, 25);
  _c13 = Object__NewLatin1Region("buffer too small", 17, 0, 16);
  _c14 = Object__NewLatin1Region("No bool value found", 20, 0, 19);
  _c15 = Object__NewLatin1Region("Hex number does not start with digit", 37, 0, 36);
  _c16 = Object__NewLatin1Region("Hex number does not end with character \047H\047", 43, 0, 42);
  _c17 = Object__NewLatin1Region("No valid hex number found", 26, 0, 25);
  _c18 = Object__NewLatin1Region("buffer too small", 17, 0, 16);

  return;
  ;
}

/* --- */
