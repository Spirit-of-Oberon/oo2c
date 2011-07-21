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

void IO_TextRider__WriterDesc_INIT(IO_TextRider__Writer w, IO__ByteChannel ch) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_INT16 i;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)ch;
  *(OOC_INT32*)(_check_pointer(i0, 4103)) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 4125))+4) = 0;
  i1 = Strings__Length((void*)(OOC_INT32)CharClass__systemEol, 3);
  *(OOC_INT16*)((_check_pointer(i0, 4146))+10) = i1;
  i = 0;
  i1 = *(OOC_INT16*)((_check_pointer(i0, 4215))+10);
  i2 = 0<i1;
  if (!i2) goto l8;
  i2=0;
l3_loop:
  i3 = *(OOC_UINT8*)((OOC_INT32)CharClass__systemEol+(_check_index(i2, 3, OOC_UINT16, 4267)));
  *(OOC_UINT8*)(((_check_pointer(i0, 4236))+8)+(_check_index(i2, 2, OOC_UINT16, 4241))) = i3;
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
  IO_TextRider__WriterDesc_INIT((IO_TextRider__Writer)i0, (IO__ByteChannel)i1);
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
  i3 = *(OOC_UINT8*)((OOC_INT32)marker+(_check_index(i2, marker_0d, OOC_UINT16, 5266)));
  *(OOC_UINT8*)(((_check_pointer(i1, 5248))+8)+(_check_index(i2, 2, OOC_UINT16, 5253))) = i3;
  i2 = i2+1;
  i = i2;
  i3 = i2<i0;
  if (i3) goto l9_loop;
l14:
  *(OOC_INT16*)((_check_pointer(i1, 5288))+10) = i0;
l15:
  return;
  ;
}

static void IO_TextRider__SetError(IO_TextRider__Writer w) {
  register OOC_INT32 i0,i1;
  Exception__Exception e;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5415))+4);
  i1 = i1==(OOC_INT32)0;
  if (!i1) goto l4;
  i1 = (OOC_INT32)Exception__Current();
  e = (Exception__Exception)i1;
  *(OOC_INT32*)((_check_pointer(i0, 5473))+4) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5488)))), &_td_IO__ErrorDesc, 5488));
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
    i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 5710));
    i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 5710));
    i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 5718)))), IO__ByteChannelDesc_Write)),IO__ByteChannelDesc_Write)((IO__ByteChannel)i1, (void*)(OOC_INT32)s, (-1), 0, i0);
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
    i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5986));
    i2 = end;
    i3 = start;
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5986));
    i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5994)))), IO__ByteChannelDesc_Write)),IO__ByteChannelDesc_Write)((IO__ByteChannel)i0, (void*)(OOC_INT32)s, (-1), i3, (i2-i3));
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
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6313)))), Object__ObjectDesc_ToString)),Object__ObjectDesc_ToString)((Object__Object)i0);
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
    i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6350)))), &_td_Object__String8Desc);
    if (i1) goto l16;
    i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6470)))), &_td_Object__String16Desc);
    if (i1) goto l14;
    _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6467)))), 6467);
    goto l17;
l14:
    i0 = (OOC_INT32)w;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6502)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (OOC_CHAR8*)"[IO:TextRider.WriteObject: String16 not implemented]", 53);
    goto l17;
l16:
    i1 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)i0);
    chars = (Object__CharsLatin1)i1;
    i2 = (OOC_INT32)w;
    i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 6422));
    i0 = *(OOC_INT32*)(_check_pointer(i0, 6449));
    i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 6422));
    i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 6430)))), IO__ByteChannelDesc_Write)),IO__ByteChannelDesc_Write)((IO__ByteChannel)i2, (void*)(_check_pointer(i1, 6442)), (-1), 0, i0);
    i = i0;
l17:
    Exception__PopContext(1);
l18:;
  }
  goto l20;
l19:
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6267)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (OOC_CHAR8*)"<NIL>", 6);
l20:
  return;
  ;
}

void IO_TextRider__WriterDesc_WriteBool(IO_TextRider__Writer w, OOC_CHAR8 _bool) {
  register OOC_INT32 i0;

  i0 = _bool;
  if (i0) goto l3;
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6776)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (OOC_CHAR8*)"FALSE", 6);
  goto l4;
l3:
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6743)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (OOC_CHAR8*)"TRUE", 5);
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
    i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6920));
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6920));
    i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6928)))), IO__ByteChannelDesc_Write)),IO__ByteChannelDesc_Write)((IO__ByteChannel)i0, (void*)(OOC_INT32)&ch, 1, 0, 1);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7107)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i1, 32u);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 7673)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, (void*)(OOC_INT32)val, 16);
  return;
  ;
}

void IO_TextRider__WriterDesc_WriteSInt(IO_TextRider__Writer w, OOC_INT8 sint, OOC_INT32 n) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)w;
  i1 = sint;
  i2 = n;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7785)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i0, i1, i2);
  return;
  ;
}

void IO_TextRider__WriterDesc_WriteInt(IO_TextRider__Writer w, OOC_INT16 _int, OOC_INT32 n) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)w;
  i1 = _int;
  i2 = n;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7896)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i0, i1, i2);
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
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8340)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i1, 48u);
      goto l8;
l7:
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8318)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i1, 70u);
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
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8588)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i1, (55+i3));
      goto l20;
l19:
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8542)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i1, (48+i3));
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 9153)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, (void*)(OOC_INT32)val, 128);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 9520)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, (void*)(OOC_INT32)val, 128);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 9961)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, (void*)(OOC_INT32)val, 128);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 10336)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, (void*)(OOC_INT32)val, 128);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 10776)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, (void*)(OOC_INT32)val, 128);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 11149)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, (void*)(OOC_INT32)val, 128);
  return;
  ;
}

void IO_TextRider__WriterDesc_WriteSet(IO_TextRider__Writer w, OOC_UINT32 s) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT8 bit;
  OOC_CHAR8 addComma;
  OOC_INT8 lo;

  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11340)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i0, 123u);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11598)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (OOC_CHAR8*)", ", 3);
  
l25:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11651)))), IO_TextRider__WriterDesc_WriteInt)),IO_TextRider__WriterDesc_WriteInt)((IO_TextRider__Writer)i0, i2, 0);
  i2 = i2<i4;
  if (!i2) goto l28;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11703)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (OOC_CHAR8*)"..", 3);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11724)))), IO_TextRider__WriterDesc_WriteInt)),IO_TextRider__WriterDesc_WriteInt)((IO_TextRider__Writer)i0, i4, 0);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11794)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i0, 125u);
  return;
  ;
}

void IO_TextRider__WriterDesc_WriteLn(IO_TextRider__Writer w) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_INT16 i;

  i0 = (OOC_INT32)w;
  i = 0;
  i1 = *(OOC_INT16*)((_check_pointer(i0, 11935))+10);
  i2 = 0<i1;
  if (!i2) goto l8;
  i2=0;
l3_loop:
  i3 = *(OOC_UINT8*)(((_check_pointer(i0, 11970))+8)+(_check_index(i2, 2, OOC_UINT16, 11974)));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11956)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i0, i3);
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
  *(OOC_INT32*)(_check_pointer(i0, 12332)) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 12353))+4) = 0;
  *(OOC_INT8*)((_check_pointer(i0, 12372))+21) = 0;
  *(OOC_UINT8*)((_check_pointer(i0, 12390))+20) = 0u;
  *(OOC_INT32*)((_check_pointer(i0, 12419))+4) = ((OOC_INT32)RT0__NewObject(_td_IO_TextRider__Buffer.baseTypes[0], 80));
  *(OOC_INT32*)((_check_pointer(i0, 12459))+8) = ((OOC_INT32)RT0__NewObject(_td_IO_TextRider__Buffer.baseTypes[0], 80));
  *(OOC_INT32*)((_check_pointer(i0, 12492))+16) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 12513))+12) = 0;
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
  *(OOC_INT8*)((_check_pointer(i0, 13196))+21) = i1;
  return;
  ;
}

void IO_TextRider__ReaderDesc_AquireBufferWithSize(IO_TextRider__Reader r, OOC_INT32 size) {
  register OOC_INT32 i0,i1,i2,i3;
  IO_TextRider__Buffer tmp;

  i0 = (OOC_INT32)r;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13429))+4);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l3;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13451))+4);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 13458)), 0);
  i2 = size;
  i1 = i1<i2;
  
  goto l5;
l3:
  i1=1u;
l5:
  if (!i1) goto l7;
  i1 = size;
  i1 = i1+(i1>>1);
  *(OOC_INT32*)((_check_pointer(i0, 13483))+8) = ((OOC_INT32)RT0__NewObject(_td_IO_TextRider__Buffer.baseTypes[0], i1));
  i1 = (OOC_INT32)RT0__NewObject(_td_IO_TextRider__Buffer.baseTypes[0], i1);
  tmp = (IO_TextRider__Buffer)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13551))+4);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i1, 13563)), 0);
  _copy_8((const void*)(_check_pointer(i2, 13558)),(void*)(_check_pointer(i1, 13563)),i3);
  *(OOC_INT32*)((_check_pointer(i0, 13596))+4) = i1;
l7:
  return;
  ;
}

void IO_TextRider__ReaderDesc_ReadLineBuffer(IO_TextRider__Reader r) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_CHAR8 ch;

  i0 = (OOC_INT32)r;
  *(OOC_INT32*)((_check_pointer(i0, 14056))+12) = 0;
  *(OOC_UINT8*)((_check_pointer(i0, 14070))+20) = 0u;
  *(OOC_INT32*)((_check_pointer(i0, 14095))+16) = 0;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 14122))+21);
  switch (i1) {
  case 0:
    i1 = (OOC_INT32)_c0;
l3_loop:
    i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14167));
    i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14167));
    i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 14175)))), IO__ByteChannelDesc_Read)),IO__ByteChannelDesc_Read)((IO__ByteChannel)i3, (void*)(OOC_INT32)&ch, 1, 0, 1);
    i2 = i2!=1;
    if (!i2) goto l10;
    i2 = *(OOC_INT32*)((_check_pointer(i0, 14211))+16);
    i2 = i2==0;
    if (i2) goto l8;
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14304))+4);
    i2 = _check_pointer(i2, 14311);
    i3 = *(OOC_INT32*)((_check_pointer(i0, 14313))+16);
    i4 = OOC_ARRAY_LENGTH(i2, 0);
    *(OOC_UINT8*)(i2+(_check_index(i3, i4, OOC_UINT32, 14311))) = 0u;
    return;
    goto l10;
l8:
    IO_TextRider__RaiseProtocolError((Object__String)i1);
l10:
    i2 = *(OOC_INT32*)((_check_pointer(i0, 14412))+16);
    IO_TextRider__ReaderDesc_AquireBufferWithSize((IO_TextRider__Reader)i0, (i2+1));
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14437))+4);
    i2 = _check_pointer(i2, 14444);
    i3 = *(OOC_INT32*)((_check_pointer(i0, 14446))+16);
    i4 = OOC_ARRAY_LENGTH(i2, 0);
    i5 = ch;
    *(OOC_UINT8*)(i2+(_check_index(i3, i4, OOC_UINT32, 14444))) = i5;
    i2 = i5==10u;
    if (i2) goto l12;
    goto l13;
l12:
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14504))+4);
    i2 = _check_pointer(i2, 14511);
    i3 = *(OOC_INT32*)((_check_pointer(i0, 14513))+16);
    i4 = OOC_ARRAY_LENGTH(i2, 0);
    *(OOC_UINT8*)(i2+(_check_index(i3, i4, OOC_UINT32, 14511))) = 0u;
    *(OOC_UINT8*)((_check_pointer(i0, 14542))+20) = 1u;
    return;
l13:
    i2 = *(OOC_INT32*)((_check_pointer(i0, 14606))+16);
    *(OOC_INT32*)((_check_pointer(i0, 14606))+16) = (i2+1);
    
    goto l3_loop;
  case 1:
    i1 = (OOC_INT32)_c1;
l16_loop:
    i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14669));
    i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14669));
    i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 14677)))), IO__ByteChannelDesc_Read)),IO__ByteChannelDesc_Read)((IO__ByteChannel)i3, (void*)(OOC_INT32)&ch, 1, 0, 1);
    i2 = i2!=1;
    if (!i2) goto l23;
    i2 = *(OOC_INT32*)((_check_pointer(i0, 14713))+16);
    i2 = i2==0;
    if (i2) goto l21;
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14806))+4);
    i2 = _check_pointer(i2, 14813);
    i3 = *(OOC_INT32*)((_check_pointer(i0, 14815))+16);
    i4 = OOC_ARRAY_LENGTH(i2, 0);
    *(OOC_UINT8*)(i2+(_check_index(i3, i4, OOC_UINT32, 14813))) = 0u;
    return;
    goto l23;
l21:
    IO_TextRider__RaiseProtocolError((Object__String)i1);
l23:
    i2 = *(OOC_INT32*)((_check_pointer(i0, 14914))+16);
    IO_TextRider__ReaderDesc_AquireBufferWithSize((IO_TextRider__Reader)i0, (i2+1));
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14939))+4);
    i2 = _check_pointer(i2, 14946);
    i3 = *(OOC_INT32*)((_check_pointer(i0, 14948))+16);
    i4 = OOC_ARRAY_LENGTH(i2, 0);
    i5 = ch;
    *(OOC_UINT8*)(i2+(_check_index(i3, i4, OOC_UINT32, 14946))) = i5;
    i2 = i5==13u;
    if (i2) goto l25;
    goto l26;
l25:
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15006))+4);
    i2 = _check_pointer(i2, 15013);
    i3 = *(OOC_INT32*)((_check_pointer(i0, 15015))+16);
    i4 = OOC_ARRAY_LENGTH(i2, 0);
    *(OOC_UINT8*)(i2+(_check_index(i3, i4, OOC_UINT32, 15013))) = 0u;
    *(OOC_UINT8*)((_check_pointer(i0, 15044))+20) = 1u;
    return;
l26:
    i2 = *(OOC_INT32*)((_check_pointer(i0, 15108))+16);
    *(OOC_INT32*)((_check_pointer(i0, 15108))+16) = (i2+1);
    
    goto l16_loop;
  case 2:
    i1 = (OOC_INT32)_c2;
l29_loop:
    i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 15172));
    i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 15172));
    i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 15180)))), IO__ByteChannelDesc_Read)),IO__ByteChannelDesc_Read)((IO__ByteChannel)i3, (void*)(OOC_INT32)&ch, 1, 0, 1);
    i2 = i2!=1;
    if (!i2) goto l36;
    i2 = *(OOC_INT32*)((_check_pointer(i0, 15216))+16);
    i2 = i2==0;
    if (i2) goto l34;
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15309))+4);
    i2 = _check_pointer(i2, 15316);
    i3 = *(OOC_INT32*)((_check_pointer(i0, 15318))+16);
    i4 = OOC_ARRAY_LENGTH(i2, 0);
    *(OOC_UINT8*)(i2+(_check_index(i3, i4, OOC_UINT32, 15316))) = 0u;
    return;
    goto l36;
l34:
    IO_TextRider__RaiseProtocolError((Object__String)i1);
l36:
    i2 = *(OOC_INT32*)((_check_pointer(i0, 15417))+16);
    IO_TextRider__ReaderDesc_AquireBufferWithSize((IO_TextRider__Reader)i0, (i2+1));
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15442))+4);
    i2 = _check_pointer(i2, 15449);
    i3 = *(OOC_INT32*)((_check_pointer(i0, 15451))+16);
    i4 = OOC_ARRAY_LENGTH(i2, 0);
    i5 = ch;
    *(OOC_UINT8*)(i2+(_check_index(i3, i4, OOC_UINT32, 15449))) = i5;
    i2 = i5==10u;
    if (i2) goto l39;
    i2=0u;
    goto l41;
l39:
    i2 = *(OOC_INT32*)((_check_pointer(i0, 15499))+16);
    i2 = i2>0;
    
l41:
    if (i2) goto l43;
    i2=0u;
    goto l45;
l43:
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15518))+4);
    i2 = _check_pointer(i2, 15525);
    i3 = *(OOC_INT32*)((_check_pointer(i0, 15527))+16);
    i4 = OOC_ARRAY_LENGTH(i2, 0);
    i2 = *(OOC_UINT8*)(i2+(_check_index((i3-1), i4, OOC_UINT32, 15525)));
    i2 = i2==13u;
    
l45:
    if (i2) goto l46;
    goto l47;
l46:
    i2 = *(OOC_INT32*)((_check_pointer(i0, 15572))+16);
    *(OOC_INT32*)((_check_pointer(i0, 15572))+16) = (i2-1);
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15626))+4);
    i2 = _check_pointer(i2, 15633);
    i3 = *(OOC_INT32*)((_check_pointer(i0, 15635))+16);
    i4 = OOC_ARRAY_LENGTH(i2, 0);
    *(OOC_UINT8*)(i2+(_check_index(i3, i4, OOC_UINT32, 15633))) = 0u;
    *(OOC_UINT8*)((_check_pointer(i0, 15664))+20) = 1u;
    return;
l47:
    i2 = *(OOC_INT32*)((_check_pointer(i0, 15728))+16);
    *(OOC_INT32*)((_check_pointer(i0, 15728))+16) = (i2+1);
    
    goto l29_loop;
  default:
    _failed_case(i1, 14116);
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
  i1 = *(OOC_INT32*)((_check_pointer(i0, 16169))+12);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 16175))+16);
  i1 = i1==i2;
  if (!i1) goto l8;
l3_loop:
  IO_TextRider__ReaderDesc_ReadLineBuffer((IO_TextRider__Reader)i0);
  i1 = *(OOC_INT32*)((_check_pointer(i0, 16169))+12);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 16175))+16);
  i1 = i1==i2;
  if (i1) goto l3_loop;
l8:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16290))+4);
  i1 = _check_pointer(i1, 16297);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 16299))+12);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_UINT8*)(i1+(_check_index(i2, i3, OOC_UINT32, 16297)));
  i1 = (OOC_UINT8)i1>(OOC_UINT8)32u;
  if (i1) goto l11;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16315))+4);
  i1 = _check_pointer(i1, 16322);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 16324))+12);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_UINT8*)(i1+(_check_index(i2, i3, OOC_UINT32, 16322)));
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
  i1 = *(OOC_INT32*)((_check_pointer(i0, 16384))+12);
  *(OOC_INT32*)((_check_pointer(i0, 16384))+12) = (i1+1);
  
  goto l1_loop;
l17:
  ;
}

void IO_TextRider__ReaderDesc_ReadChar(IO_TextRider__Reader r, OOC_CHAR8 *ch) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)r;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 16692))+12);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 16698))+16);
  i1 = i1==i2;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 16715))+20);
  i1 = !i1;
  
l5:
  if (!i1) goto l7;
  IO_TextRider__ReaderDesc_ReadLineBuffer((IO_TextRider__Reader)i0);
l7:
  i1 = *(OOC_INT32*)((_check_pointer(i0, 16775))+12);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 16781))+16);
  i1 = i1==i2;
  if (i1) goto l10;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17118))+4);
  i1 = _check_pointer(i1, 17125);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i3 = *(OOC_INT32*)((_check_pointer(i0, 17127))+12);
  i1 = *(OOC_UINT8*)(i1+(_check_index(i3, i2, OOC_UINT32, 17125)));
  *ch = i1;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 17145))+12);
  *(OOC_INT32*)((_check_pointer(i0, 17145))+12) = (i1+1);
  goto l11;
l10:
  *ch = 10u;
  *(OOC_UINT8*)((_check_pointer(i0, 17078))+20) = 0u;
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
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18384))+4);
  i1 = _check_pointer(i1, 18391);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 18393))+12);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_UINT8*)(i1+(_check_index(i2, i3, OOC_UINT32, 18391)));
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
  i2 = *(OOC_INT32*)((_check_pointer(i0, 18504))+12);
  *(OOC_INT32*)((_check_pointer(i0, 18504))+12) = (i2+1);
  i2 = (OOC_INT32)_c4;
  i3 = (OOC_INT32)_c5;
  i4 = (OOC_INT32)_c6;
  i5 = s_0d-1;
  pos = 0;
  i6=0;
l8_loop:
  i7 = *(OOC_INT32*)((_check_pointer(i0, 18542))+12);
  i8 = *(OOC_INT32*)((_check_pointer(i0, 18548))+16);
  i7 = i7==i8;
  if (i7) goto l23;
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18639))+4);
  i7 = _check_pointer(i7, 18646);
  i8 = *(OOC_INT32*)((_check_pointer(i0, 18648))+12);
  i9 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = *(OOC_UINT8*)(i7+(_check_index(i8, i9, OOC_UINT32, 18646)));
  i7 = i7==i1;
  if (i7) goto l21;
  i7 = i6>=i5;
  if (i7) goto l19;
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18846))+4);
  i7 = _check_pointer(i7, 18853);
  i8 = *(OOC_INT32*)((_check_pointer(i0, 18855))+12);
  i9 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = *(OOC_UINT8*)(i7+(_check_index(i8, i9, OOC_UINT32, 18853)));
  i7 = (OOC_UINT8)i7<(OOC_UINT8)32u;
  if (i7) goto l17;
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19018))+4);
  i7 = _check_pointer(i7, 19025);
  i8 = *(OOC_INT32*)((_check_pointer(i0, 19027))+12);
  i9 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = *(OOC_UINT8*)(i7+(_check_index(i8, i9, OOC_UINT32, 19025)));
  *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i6, s_0d, OOC_UINT32, 19010))) = i7;
  goto l24;
l17:
  *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i6, s_0d, OOC_UINT32, 18879))) = 0u;
  IO__RaiseFormatError((Object__String)i3);
  goto l24;
l19:
  IO_TextRider__RaiseOverflowError((Object__String)i4);
  goto l24;
l21:
  i7 = *(OOC_INT32*)((_check_pointer(i0, 18678))+12);
  *(OOC_INT32*)((_check_pointer(i0, 18678))+12) = (i7+1);
  *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i6, s_0d, OOC_UINT32, 18694))) = 0u;
  return;
  goto l24;
l23:
  IO__RaiseFormatError((Object__String)i2);
l24:
  i6 = i6+1;
  pos = i6;
  i7 = *(OOC_INT32*)((_check_pointer(i0, 19073))+12);
  *(OOC_INT32*)((_check_pointer(i0, 19073))+12) = (i7+1);
  
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
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19582))+4);
  i1 = _check_pointer(i1, 19589);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 19591))+12);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_UINT8*)(i1+(_check_index(i2, i3, OOC_UINT32, 19589)));
  i1 = i1==43u;
  if (i1) goto l3;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19607))+4);
  i1 = _check_pointer(i1, 19614);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 19616))+12);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_UINT8*)(i1+(_check_index(i2, i3, OOC_UINT32, 19614)));
  i1 = i1==45u;
  
  goto l5;
l3:
  i1=1u;
l5:
  if (i1) goto l7;
  i1=0;
  goto l8;
l7:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19639))+8);
  i1 = _check_pointer(i1, 19643);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19649))+4);
  i3 = _check_pointer(i3, 19656);
  i4 = *(OOC_INT32*)((_check_pointer(i0, 19658))+12);
  i5 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = *(OOC_UINT8*)(i3+(_check_index(i4, i5, OOC_UINT32, 19656)));
  *(OOC_UINT8*)(i1+(_check_index(0, i2, OOC_UINT32, 19643))) = i3;
  x = 1;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 19690))+12);
  *(OOC_INT32*)((_check_pointer(i0, 19690))+12) = (i1+1);
  i1=1;
l8:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19825))+4);
  i2 = _check_pointer(i2, 19832);
  i3 = *(OOC_INT32*)((_check_pointer(i0, 19834))+12);
  i4 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = *(OOC_UINT8*)(i2+(_check_index(i3, i4, OOC_UINT32, 19832)));
  i2 = (OOC_UINT8)i2>=(OOC_UINT8)48u;
  if (i2) goto l11;
  i2=0u;
  goto l13;
l11:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19850))+4);
  i2 = _check_pointer(i2, 19857);
  i3 = *(OOC_INT32*)((_check_pointer(i0, 19859))+12);
  i4 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = *(OOC_UINT8*)(i2+(_check_index(i3, i4, OOC_UINT32, 19857)));
  i2 = (OOC_UINT8)i2<=(OOC_UINT8)57u;
  
l13:
  if (i2) goto l15;
  IO__RaiseFormatError((Object__String)((OOC_INT32)_c7));
  
  goto l16;
l15:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19883))+8);
  i2 = _check_pointer(i2, 19887);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19893))+4);
  i4 = _check_pointer(i4, 19900);
  i5 = *(OOC_INT32*)((_check_pointer(i0, 19902))+12);
  i6 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = *(OOC_UINT8*)(i4+(_check_index(i5, i6, OOC_UINT32, 19900)));
  *(OOC_UINT8*)(i2+(_check_index(i1, i3, OOC_UINT32, 19887))) = i4;
  i1 = i1+1;
  x = i1;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 19934))+12);
  *(OOC_INT32*)((_check_pointer(i0, 19934))+12) = (i2+1);
  
l16:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20024))+4);
  i2 = _check_pointer(i2, 20031);
  i3 = *(OOC_INT32*)((_check_pointer(i0, 20033))+12);
  i4 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = *(OOC_UINT8*)(i2+(_check_index(i3, i4, OOC_UINT32, 20031)));
  i2 = (OOC_UINT8)i2>=(OOC_UINT8)48u;
  if (i2) goto l19;
  i2=0u;
  goto l21;
l19:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20049))+4);
  i2 = _check_pointer(i2, 20056);
  i3 = *(OOC_INT32*)((_check_pointer(i0, 20058))+12);
  i4 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = *(OOC_UINT8*)(i2+(_check_index(i3, i4, OOC_UINT32, 20056)));
  i2 = (OOC_UINT8)i2<=(OOC_UINT8)57u;
  
l21:
  if (!i2) goto l33;
l24_loop:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20080))+8);
  i2 = _check_pointer(i2, 20084);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20090))+4);
  i4 = _check_pointer(i4, 20097);
  i5 = *(OOC_INT32*)((_check_pointer(i0, 20099))+12);
  i6 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = *(OOC_UINT8*)(i4+(_check_index(i5, i6, OOC_UINT32, 20097)));
  *(OOC_UINT8*)(i2+(_check_index(i1, i3, OOC_UINT32, 20084))) = i4;
  i1 = i1+1;
  x = i1;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 20131))+12);
  *(OOC_INT32*)((_check_pointer(i0, 20131))+12) = (i2+1);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20024))+4);
  i2 = _check_pointer(i2, 20031);
  i3 = *(OOC_INT32*)((_check_pointer(i0, 20033))+12);
  i4 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = *(OOC_UINT8*)(i2+(_check_index(i3, i4, OOC_UINT32, 20031)));
  i2 = (OOC_UINT8)i2>=(OOC_UINT8)48u;
  if (i2) goto l27;
  i2=0u;
  goto l29;
l27:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20049))+4);
  i2 = _check_pointer(i2, 20056);
  i3 = *(OOC_INT32*)((_check_pointer(i0, 20058))+12);
  i4 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = *(OOC_UINT8*)(i2+(_check_index(i3, i4, OOC_UINT32, 20056)));
  i2 = (OOC_UINT8)i2<=(OOC_UINT8)57u;
  
l29:
  if (i2) goto l24_loop;
l33:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20153))+8);
  i2 = _check_pointer(i2, 20157);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  *(OOC_UINT8*)(i2+(_check_index(i1, i3, OOC_UINT32, 20157))) = 0u;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20188))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20188))+8);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 20192)), 0);
  IntStr__StrToInt((void*)(_check_pointer(i0, 20192)), i1, (void*)(OOC_INT32)lint, (void*)(OOC_INT32)&res);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20571)))), IO_TextRider__ReaderDesc_ReadLInt)),IO_TextRider__ReaderDesc_ReadLInt)((IO_TextRider__Reader)i0, (void*)(OOC_INT32)&tmp);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20895)))), IO_TextRider__ReaderDesc_ReadLInt)),IO_TextRider__ReaderDesc_ReadLInt)((IO_TextRider__Reader)i0, (void*)(OOC_INT32)&tmp);
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

  _assert((s_0d>=2), 127, 21565);
  i0 = (OOC_INT32)r;
  IO_TextRider__ReaderDesc_ConsumeWhiteSpace((IO_TextRider__Reader)i0);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21639))+4);
  i1 = _check_pointer(i1, 21646);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 21648))+12);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_UINT8*)(i1+(_check_index(i2, i3, OOC_UINT32, 21646)));
  i1 = CharClass__IsLetter(i1);
  i1 = !i1;
  if (!i1) goto l3;
  IO__RaiseFormatError((Object__String)((OOC_INT32)_c12));
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21737))+4);
  i1 = _check_pointer(i1, 21744);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 21746))+12);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_UINT8*)(i1+(_check_index(i2, i3, OOC_UINT32, 21744)));
  *(OOC_UINT8*)((OOC_INT32)s+(_check_index(0, s_0d, OOC_UINT8, 21731))) = i1;
  x = 1;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 21772))+12);
  *(OOC_INT32*)((_check_pointer(i0, 21772))+12) = (i1+1);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21811))+4);
  i1 = _check_pointer(i1, 21818);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 21820))+12);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_UINT8*)(i1+(_check_index(i2, i3, OOC_UINT32, 21818)));
  i1 = CharClass__IsLetter(i1);
  if (i1) goto l6;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21851))+4);
  i1 = _check_pointer(i1, 21858);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 21860))+12);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_UINT8*)(i1+(_check_index(i2, i3, OOC_UINT32, 21858)));
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
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22002))+4);
  i4 = _check_pointer(i4, 22009);
  i5 = *(OOC_INT32*)((_check_pointer(i0, 22011))+12);
  i6 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = *(OOC_UINT8*)(i4+(_check_index(i5, i6, OOC_UINT32, 22009)));
  *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i3, s_0d, OOC_UINT32, 21996))) = i4;
  i3 = i3+1;
  x = i3;
  i4 = *(OOC_INT32*)((_check_pointer(i0, 22043))+12);
  *(OOC_INT32*)((_check_pointer(i0, 22043))+12) = (i4+1);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21811))+4);
  i4 = _check_pointer(i4, 21818);
  i5 = *(OOC_INT32*)((_check_pointer(i0, 21820))+12);
  i6 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = *(OOC_UINT8*)(i4+(_check_index(i5, i6, OOC_UINT32, 21818)));
  i4 = CharClass__IsLetter(i4);
  if (i4) goto l17;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21851))+4);
  i4 = _check_pointer(i4, 21858);
  i5 = *(OOC_INT32*)((_check_pointer(i0, 21860))+12);
  i6 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = *(OOC_UINT8*)(i4+(_check_index(i5, i6, OOC_UINT32, 21858)));
  i4 = CharClass__IsNumeric(i4);
  
  goto l19;
l17:
  i4=1u;
l19:
  if (i4) goto l11_loop;
l22:
  i0=i3;
l23:
  *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i0, s_0d, OOC_UINT32, 22065))) = 0u;
  return;
  ;
}

void IO_TextRider__ReaderDesc_ReadBool(IO_TextRider__Reader r, OOC_CHAR8 *_bool) {
  register OOC_INT32 i0;
  OOC_CHAR8 ident[8];

  i0 = (OOC_INT32)r;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22480)))), IO_TextRider__ReaderDesc_ReadIdentifier)),IO_TextRider__ReaderDesc_ReadIdentifier)((IO_TextRider__Reader)i0, (void*)(OOC_INT32)ident, 8);
  i0 = (
  _cmp8((const void*)(OOC_INT32)ident,(const void*)(OOC_CHAR8*)"TRUE"))==0;
  if (i0) goto l7;
  i0 = (
  _cmp8((const void*)(OOC_INT32)ident,(const void*)(OOC_CHAR8*)"FALSE"))==0;
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
  i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT16, 23746)));
  i0 = i0!=0u;
  if (i0) goto l3;
  i0=0;
  goto l9;
l3:
  i0=0;
l4_loop:
  i0 = i0+1;
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT16, 23746)));
  i1 = i1!=0u;
  if (i1) goto l4_loop;
l9:
  i1 = i0-1;
  epos = i1;
  i2 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT16, 23849)));
  i2 = i2==48u;
  if (i2) goto l12;
  i2=0;
  goto l18;
l12:
  i2=0;
l13_loop:
  i2 = i2+1;
  spos = i2;
  i3 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i2, str_0d, OOC_UINT16, 23849)));
  i3 = i3==48u;
  if (i3) goto l13_loop;
l18:
  i3 = (i1-i2)>7;
  if (i3) goto l40;
  i3 = i2<i0;
  if (!i3) goto l41;
  i3 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i2, str_0d, OOC_UINT16, 24136)));
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
  i4 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i3, str_0d, OOC_UINT16, 24526)));
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
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25028))+4);
  i1 = _check_pointer(i1, 25035);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 25037))+12);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_UINT8*)(i1+(_check_index(i2, i3, OOC_UINT32, 25035)));
  i1 = CharClass__IsNumeric(i1);
  i1 = !i1;
  if (!i1) goto l3;
  IO__RaiseFormatError((Object__String)((OOC_INT32)_c15));
l3:
  x = 0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25141))+8);
  i1 = _check_pointer(i1, 25145);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25151))+4);
  i3 = _check_pointer(i3, 25158);
  i4 = *(OOC_INT32*)((_check_pointer(i0, 25160))+12);
  i5 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = *(OOC_UINT8*)(i3+(_check_index(i4, i5, OOC_UINT32, 25158)));
  *(OOC_UINT8*)(i1+(_check_index(0, i2, OOC_UINT32, 25145))) = i3;
  x = 1;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 25188))+12);
  *(OOC_INT32*)((_check_pointer(i0, 25188))+12) = (i1+1);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25216))+4);
  i1 = _check_pointer(i1, 25223);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 25225))+12);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_UINT8*)(i1+(_check_index(i2, i3, OOC_UINT32, 25223)));
  i1 = IO_TextRider__HexDigit(i1);
  if (i1) goto l6;
  i1=1;
  goto l12;
l6:
  i1=1;
l7_loop:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25242))+8);
  i2 = _check_pointer(i2, 25246);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25252))+4);
  i4 = _check_pointer(i4, 25259);
  i5 = *(OOC_INT32*)((_check_pointer(i0, 25261))+12);
  i6 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = *(OOC_UINT8*)(i4+(_check_index(i5, i6, OOC_UINT32, 25259)));
  *(OOC_UINT8*)(i2+(_check_index(i1, i3, OOC_UINT32, 25246))) = i4;
  i1 = i1+1;
  x = i1;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 25293))+12);
  *(OOC_INT32*)((_check_pointer(i0, 25293))+12) = (i2+1);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25216))+4);
  i2 = _check_pointer(i2, 25223);
  i3 = *(OOC_INT32*)((_check_pointer(i0, 25225))+12);
  i4 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = *(OOC_UINT8*)(i2+(_check_index(i3, i4, OOC_UINT32, 25223)));
  i2 = IO_TextRider__HexDigit(i2);
  if (i2) goto l7_loop;
l12:
  i2 = *(OOC_INT32*)((_check_pointer(i0, 25325))+16);
  i3 = *(OOC_INT32*)((_check_pointer(i0, 25319))+12);
  i2 = i3==i2;
  if (i2) goto l15;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25343))+4);
  i2 = _check_pointer(i2, 25350);
  i3 = *(OOC_INT32*)((_check_pointer(i0, 25352))+12);
  i4 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = *(OOC_UINT8*)(i2+(_check_index(i3, i4, OOC_UINT32, 25350)));
  i2 = i2!=72u;
  
  goto l17;
l15:
  i2=1u;
l17:
  if (!i2) goto l19;
  IO__RaiseFormatError((Object__String)((OOC_INT32)_c16));
l19:
  i2 = *(OOC_INT32*)((_check_pointer(i0, 25511))+12);
  *(OOC_INT32*)((_check_pointer(i0, 25511))+12) = (i2+1);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25524))+8);
  i2 = _check_pointer(i2, 25528);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  *(OOC_UINT8*)(i2+(_check_index(i1, i3, OOC_UINT32, 25528))) = 0u;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25556))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25556))+8);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 25560)), 0);
  i0 = IO_TextRider__HexToInt((void*)(_check_pointer(i0, 25560)), i1, (void*)(OOC_INT32)_int);
  i0 = !i0;
  if (!i0) goto l22;
  IO__RaiseFormatError((Object__String)((OOC_INT32)_c17));
l22:
  return;
  ;
}

void IO_TextRider__ReaderDesc_ReadLn(IO_TextRider__Reader r) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)r;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 25827))+12);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 25833))+16);
  i1 = i1==i2;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 25850))+20);
  i1 = !i1;
  
l5:
  if (!i1) goto l7;
  IO_TextRider__ReaderDesc_ReadLineBuffer((IO_TextRider__Reader)i0);
l7:
  *(OOC_UINT8*)((_check_pointer(i0, 25905))+20) = 0u;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 25937))+16);
  *(OOC_INT32*)((_check_pointer(i0, 25930))+12) = i1;
  return;
  ;
}

void IO_TextRider__ReaderDesc_ReadLine(IO_TextRider__Reader r, OOC_CHAR8 s[], OOC_LEN s_0d) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_INT32 pos;

  _assert((s_0d>0), 127, 27019);
  i0 = (OOC_INT32)r;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 27046))+12);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 27052))+16);
  i1 = i1==i2;
  if (!i1) goto l11;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 27116))+16);
  i1 = i1>0;
  if (i1) goto l5;
  i1=0u;
  goto l7;
l5:
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 27134))+20);
  
l7:
  if (i1) goto l9;
  IO_TextRider__ReaderDesc_ReadLineBuffer((IO_TextRider__Reader)i0);
  goto l11;
l9:
  *(OOC_UINT8*)((OOC_INT32)s+(_check_index(0, s_0d, OOC_UINT8, 27241))) = 0u;
  *(OOC_UINT8*)((_check_pointer(i0, 27259))+20) = 0u;
  return;
l11:
  i1 = s_0d-1;
  i2 = (OOC_INT32)_c18;
  pos = 0;
  i3=0;
l12_loop:
  i4 = i3==i1;
  if (i4) goto l19;
  i4 = *(OOC_INT32*)((_check_pointer(i0, 27521))+12);
  i5 = *(OOC_INT32*)((_check_pointer(i0, 27527))+16);
  i4 = i4==i5;
  if (i4) goto l17;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27691))+4);
  i4 = _check_pointer(i4, 27698);
  i5 = *(OOC_INT32*)((_check_pointer(i0, 27700))+12);
  i6 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = *(OOC_UINT8*)(i4+(_check_index(i5, i6, OOC_UINT32, 27698)));
  *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i3, s_0d, OOC_UINT32, 27683))) = i4;
  goto l20;
l17:
  *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i3, s_0d, OOC_UINT32, 27553))) = 0u;
  *(OOC_UINT8*)((_check_pointer(i0, 27573))+20) = 0u;
  return;
  goto l20;
l19:
  *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i3, s_0d, OOC_UINT32, 27448))) = 0u;
  IO__RaiseFormatError((Object__String)i2);
l20:
  i3 = i3+1;
  pos = i3;
  i4 = *(OOC_INT32*)((_check_pointer(i0, 27746))+12);
  *(OOC_INT32*)((_check_pointer(i0, 27746))+12) = (i4+1);
  
  goto l12_loop;
l22:
  ;
}

void OOC_IO_TextRider_init(void) {
  _c0 = Object__NewLatin1Region((OOC_CHAR8*)"Short file", 11, 0, 10);
  _c1 = Object__NewLatin1Region((OOC_CHAR8*)"Short file", 11, 0, 10);
  _c2 = Object__NewLatin1Region((OOC_CHAR8*)"Short file", 11, 0, 10);
  _c3 = Object__NewLatin1Region((OOC_CHAR8*)"No string found", 16, 0, 15);
  _c4 = Object__NewLatin1Region((OOC_CHAR8*)"No quote mark until line end", 29, 0, 28);
  _c5 = Object__NewLatin1Region((OOC_CHAR8*)"Illegal character in string", 28, 0, 27);
  _c6 = Object__NewLatin1Region((OOC_CHAR8*)"buffer too small", 17, 0, 16);
  _c7 = Object__NewLatin1Region((OOC_CHAR8*)"No valid number found", 22, 0, 21);
  _c8 = Object__NewLatin1Region((OOC_CHAR8*)"No valid number found", 22, 0, 21);
  _c9 = Object__NewLatin1Region((OOC_CHAR8*)"Value out of range", 19, 0, 18);
  _c10 = Object__NewLatin1Region((OOC_CHAR8*)"read value out of range", 24, 0, 23);
  _c11 = Object__NewLatin1Region((OOC_CHAR8*)"read value out of range", 24, 0, 23);
  _c12 = Object__NewLatin1Region((OOC_CHAR8*)"No identifier value found", 26, 0, 25);
  _c13 = Object__NewLatin1Region((OOC_CHAR8*)"buffer too small", 17, 0, 16);
  _c14 = Object__NewLatin1Region((OOC_CHAR8*)"No bool value found", 20, 0, 19);
  _c15 = Object__NewLatin1Region((OOC_CHAR8*)"Hex number does not start with digit", 37, 0, 36);
  _c16 = Object__NewLatin1Region((OOC_CHAR8*)"Hex number does not end with character \047H\047", 43, 0, 42);
  _c17 = Object__NewLatin1Region((OOC_CHAR8*)"No valid hex number found", 26, 0, 25);
  _c18 = Object__NewLatin1Region((OOC_CHAR8*)"buffer too small", 17, 0, 16);

  return;
  ;
}

void OOC_IO_TextRider_destroy(void) {
}

/* --- */
