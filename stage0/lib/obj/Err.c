#include <Err.d>
#include <__oo2c.h>
#include <setjmp.h>

OOC_CHAR8 Err__Done(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)Err__writer;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 1490));
  return (i0==0);
  ;
}

void Err__ClearError(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)Err__writer;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1568)))), TextRider__WriterDesc_ClearError)),TextRider__WriterDesc_ClearError)((TextRider__Writer)i0);
  return;
  ;
}

void Err__SetWriter(TextRider__Writer w) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)w;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l3;
  Err__writer = (TextRider__Writer)i0;
  goto l4;
l3:
  i0 = (OOC_INT32)StdChannels__stderr;
  i0 = (OOC_INT32)TextRider__ConnectWriter((Channel__Channel)i0);
  Err__writer = (TextRider__Writer)i0;
l4:
  return;
  ;
}

void Err__Flush(void) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)Err__writer;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2080))+12);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2080))+12);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2086)))), Channel__ChannelDesc_Flush)),Channel__ChannelDesc_Flush)((Channel__Channel)i0);
  return;
  ;
}

void Err__Char(OOC_CHAR8 ch) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)Err__writer;
  i1 = ch;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2155)))), TextRider__WriterDesc_WriteChar)),TextRider__WriterDesc_WriteChar)((TextRider__Writer)i0, i1);
  return;
  ;
}

void Err__String(const OOC_CHAR8 s__ref[], OOC_LEN s_0d) {
  register OOC_INT32 i0;
  OOC_ALLOCATE_VPAR(s,OOC_CHAR8 ,s_0d)

  OOC_INITIALIZE_VPAR(s__ref,s,OOC_CHAR8 ,s_0d)
  i0 = (OOC_INT32)Err__writer;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2243)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (void*)(OOC_INT32)s, s_0d);
  return;
  ;
}

void Err__Object(Object__Object obj) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)Err__writer;
  i1 = (OOC_INT32)obj;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2333)))), TextRider__WriterDesc_WriteObject)),TextRider__WriterDesc_WriteObject)((TextRider__Writer)i0, (Object__Object)i1);
  return;
  ;
}

void Err__Bool(OOC_CHAR8 _bool) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)Err__writer;
  i1 = _bool;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2421)))), TextRider__WriterDesc_WriteBool)),TextRider__WriterDesc_WriteBool)((TextRider__Writer)i0, i1);
  return;
  ;
}

void Err__LongInt(OOC_INT32 lint, OOC_INT32 n) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)Err__writer;
  i1 = lint;
  i2 = n;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2521)))), TextRider__WriterDesc_WriteLInt)),TextRider__WriterDesc_WriteLInt)((TextRider__Writer)i0, i1, i2);
  return;
  ;
}

void Err__ShortInt(OOC_INT8 sint, OOC_INT32 n) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)Err__writer;
  i1 = sint;
  i2 = n;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2627)))), TextRider__WriterDesc_WriteSInt)),TextRider__WriterDesc_WriteSInt)((TextRider__Writer)i0, i1, i2);
  return;
  ;
}

void Err__Int(OOC_INT32 _int, OOC_INT32 n) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)Err__writer;
  i1 = _int;
  i2 = n;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2727)))), TextRider__WriterDesc_WriteLInt)),TextRider__WriterDesc_WriteLInt)((TextRider__Writer)i0, i1, i2);
  return;
  ;
}

void Err__Hex(OOC_INT32 lint, OOC_INT32 n) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)Err__writer;
  i1 = lint;
  i2 = n;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2822)))), TextRider__WriterDesc_WriteHex)),TextRider__WriterDesc_WriteHex)((TextRider__Writer)i0, i1, i2);
  return;
  ;
}

void Err__LongReal(OOC_REAL64 lreal, OOC_INT32 n, OOC_INT32 k) {
  register OOC_INT32 i0,i1,i2;
  register OOC_REAL64 d0;

  i0 = (OOC_INT32)Err__writer;
  d0 = lreal;
  i1 = n;
  i2 = k;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3046)))), TextRider__WriterDesc_WriteLReal)),TextRider__WriterDesc_WriteLReal)((TextRider__Writer)i0, d0, i1, i2);
  return;
  ;
}

void Err__Real(OOC_REAL32 real, OOC_INT32 n, OOC_INT32 k) {
  register OOC_INT32 i0,i1,i2;
  register OOC_REAL32 f0;

  i0 = (OOC_INT32)Err__writer;
  f0 = real;
  i1 = n;
  i2 = k;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3181)))), TextRider__WriterDesc_WriteReal)),TextRider__WriterDesc_WriteReal)((TextRider__Writer)i0, f0, i1, i2);
  return;
  ;
}

void Err__LongRealFix(OOC_REAL64 lreal, OOC_INT32 n, OOC_INT32 k) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)Err__writer;
  i1 = n;
  i2 = k;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3577)))), TextRider__WriterDesc_WriteLRealFix)),TextRider__WriterDesc_WriteLRealFix)((TextRider__Writer)i0, (void*)(OOC_INT32)&lreal, i1, i2);
  return;
  ;
}

void Err__RealFix(OOC_REAL32 real, OOC_INT32 n, OOC_INT32 k) {
  register OOC_INT32 i0,i1,i2;
  register OOC_REAL32 f0;

  i0 = (OOC_INT32)Err__writer;
  f0 = real;
  i1 = n;
  i2 = k;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3724)))), TextRider__WriterDesc_WriteRealFix)),TextRider__WriterDesc_WriteRealFix)((TextRider__Writer)i0, f0, i1, i2);
  return;
  ;
}

void Err__LongRealEng(OOC_REAL64 lreal, OOC_INT32 n, OOC_INT32 k) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)Err__writer;
  i1 = n;
  i2 = k;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3987)))), TextRider__WriterDesc_WriteLRealEng)),TextRider__WriterDesc_WriteLRealEng)((TextRider__Writer)i0, (void*)(OOC_INT32)&lreal, i1, i2);
  return;
  ;
}

void Err__RealEng(OOC_REAL32 real, OOC_INT32 n, OOC_INT32 k) {
  register OOC_INT32 i0,i1,i2;
  register OOC_REAL32 f0;

  i0 = (OOC_INT32)Err__writer;
  f0 = real;
  i1 = n;
  i2 = k;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4134)))), TextRider__WriterDesc_WriteRealEng)),TextRider__WriterDesc_WriteRealEng)((TextRider__Writer)i0, f0, i1, i2);
  return;
  ;
}

void Err__Set(OOC_UINT32 s) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)Err__writer;
  i1 = s;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4223)))), TextRider__WriterDesc_WriteSet)),TextRider__WriterDesc_WriteSet)((TextRider__Writer)i0, i1);
  return;
  ;
}

void Err__Ln(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)Err__writer;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4283)))), TextRider__WriterDesc_WriteLn)),TextRider__WriterDesc_WriteLn)((TextRider__Writer)i0);
  return;
  ;
}

void OOC_Err_init(void) {

  Err__SetWriter((TextRider__Writer)(OOC_INT32)0);
  return;
  ;
}

/* --- */
