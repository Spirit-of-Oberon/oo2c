#include <OOC/IR/VisitAll.d>
#include <__oo2c.h>
#include <setjmp.h>

void OOC_IR_VisitAll__InitVisitor(OOC_IR_VisitAll__Visitor v) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)v;
  OOC_IR__InitVisitor((OOC_IR__Visitor)i0);
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitConst(OOC_IR_VisitAll__Visitor v, OOC_IR__Const _const) {

  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitAbs(OOC_IR_VisitAll__Visitor v, OOC_IR__Abs abs) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)abs;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1547))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1547))+8);
  i2 = (OOC_INT32)v;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 1556)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i0, (OOC_IR__Visitor)i2);
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitAdr(OOC_IR_VisitAll__Visitor v, OOC_IR__Adr adr) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)adr;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1650))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1650))+8);
  i2 = (OOC_INT32)v;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 1658)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i0, (OOC_IR__Visitor)i2);
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitAsh(OOC_IR_VisitAll__Visitor v, OOC_IR__Ash ash) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)ash;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1752))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1752))+8);
  i3 = (OOC_INT32)v;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 1759)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i2, (OOC_IR__Visitor)i3);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1780))+12);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1780))+12);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 1785)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i0, (OOC_IR__Visitor)i3);
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitBinaryArith(OOC_IR_VisitAll__Visitor v, OOC_IR__BinaryArith op) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)op;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1893))+12);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1893))+12);
  i3 = (OOC_INT32)v;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 1899)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i2, (OOC_IR__Visitor)i3);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1919))+16);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1919))+16);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 1926)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i0, (OOC_IR__Visitor)i3);
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitBooleanOp(OOC_IR_VisitAll__Visitor v, OOC_IR__BooleanOp op) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)op;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2038))+12);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2038))+12);
  i3 = (OOC_INT32)v;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2044)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i2, (OOC_IR__Visitor)i3);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2064))+16);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2064))+16);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2071)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i0, (OOC_IR__Visitor)i3);
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitCap(OOC_IR_VisitAll__Visitor v, OOC_IR__Cap cap) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)cap;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2171))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2171))+8);
  i2 = (OOC_INT32)v;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2180)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i0, (OOC_IR__Visitor)i2);
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitConcat(OOC_IR_VisitAll__Visitor v, OOC_IR__Concat op) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_INT32 i;

  i0 = (OOC_INT32)op;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2318))+8);
  i = 0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 2326)), 0);
  i2 = 0<i1;
  if (!i2) goto l8;
  i2 = (OOC_INT32)v;
  i3=0;
l3_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2342))+8);
  i4 = _check_pointer(i4, 2350);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 2350))*4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2342))+8);
  i5 = _check_pointer(i5, 2350);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 2350))*4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 2353)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i5, (OOC_IR__Visitor)i2);
  i3 = i3+1;
  i = i3;
  i4 = i3<i1;
  if (i4) goto l3_loop;
l8:
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitCompare(OOC_IR_VisitAll__Visitor v, OOC_IR__Compare op) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)op;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2463))+12);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2463))+12);
  i3 = (OOC_INT32)v;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2469)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i2, (OOC_IR__Visitor)i3);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2489))+16);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2489))+16);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2496)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i0, (OOC_IR__Visitor)i3);
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitConstructor(OOC_IR_VisitAll__Visitor v, OOC_IR__Constructor cons) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)cons;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2612))+8);
  i2 = (OOC_INT32)v;
  OOC_IR__NewObjectDesc_Accept((OOC_IR__NewObject)i1, (OOC_IR__Visitor)i2);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2642))+12);
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l4;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2670))+12);
  OOC_IR__CallDesc_Accept((OOC_IR__Call)i0, (OOC_IR__Visitor)i2);
l4:
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitCurrentException(OOC_IR_VisitAll__Visitor v, OOC_IR__CurrentException ce) {

  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitDeref(OOC_IR_VisitAll__Visitor v, OOC_IR__Deref deref) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)deref;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2902))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2902))+8);
  i2 = (OOC_INT32)v;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2911)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i0, (OOC_IR__Visitor)i2);
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitEntier(OOC_IR_VisitAll__Visitor v, OOC_IR__Entier entier) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)entier;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3019))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3019))+8);
  i2 = (OOC_INT32)v;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3028)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i0, (OOC_IR__Visitor)i2);
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitIndex(OOC_IR_VisitAll__Visitor v, OOC_IR__Index index) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)index;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3133))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3133))+8);
  i3 = (OOC_INT32)v;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3140)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i2, (OOC_IR__Visitor)i3);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3163))+12);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3163))+12);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3170)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i0, (OOC_IR__Visitor)i3);
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitLen(OOC_IR_VisitAll__Visitor v, OOC_IR__Len len) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)len;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3266))+12);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3266))+12);
  i2 = (OOC_INT32)v;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3273)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i0, (OOC_IR__Visitor)i2);
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitNegate(OOC_IR_VisitAll__Visitor v, OOC_IR__Negate neg) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)neg;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3373))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3373))+8);
  i2 = (OOC_INT32)v;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3382)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i0, (OOC_IR__Visitor)i2);
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitNewBlock(OOC_IR_VisitAll__Visitor v, OOC_IR__NewBlock _new) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)_new;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3489))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3489))+8);
  i2 = (OOC_INT32)v;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3494)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i0, (OOC_IR__Visitor)i2);
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitNewObject(OOC_IR_VisitAll__Visitor v, OOC_IR__NewObject _new) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_INT32 i;

  i0 = (OOC_INT32)_new;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3629))+8);
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l11;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3678))+8);
  i = 0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 3686)), 0);
  i2 = 0<i1;
  if (!i2) goto l11;
  i2 = (OOC_INT32)v;
  i3=0;
l5_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3705))+8);
  i4 = _check_pointer(i4, 3713);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 3713))*4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3705))+8);
  i5 = _check_pointer(i5, 3713);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 3713))*4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 3716)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i5, (OOC_IR__Visitor)i2);
  i3 = i3+1;
  i = i3;
  i4 = i3<i1;
  if (i4) goto l5_loop;
l11:
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitNot(OOC_IR_VisitAll__Visitor v, OOC_IR__Not neg) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)neg;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3836))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3836))+8);
  i2 = (OOC_INT32)v;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3845)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i0, (OOC_IR__Visitor)i2);
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitOdd(OOC_IR_VisitAll__Visitor v, OOC_IR__Odd odd) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)odd;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3939))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3939))+8);
  i2 = (OOC_INT32)v;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3948)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i0, (OOC_IR__Visitor)i2);
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitSelectField(OOC_IR_VisitAll__Visitor v, OOC_IR__SelectField sf) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)sf;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4056))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4056))+8);
  i2 = (OOC_INT32)v;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4064)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i0, (OOC_IR__Visitor)i2);
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitSelectProc(OOC_IR_VisitAll__Visitor v, OOC_IR__SelectProc sp) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)sp;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4178))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4178))+8);
  i2 = (OOC_INT32)v;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4188)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i0, (OOC_IR__Visitor)i2);
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitSetMember(OOC_IR_VisitAll__Visitor v, OOC_IR__SetMember range) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)range;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4305))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4305))+8);
  i3 = (OOC_INT32)v;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4314)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i2, (OOC_IR__Visitor)i3);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4337))+12);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4337))+12);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4342)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i0, (OOC_IR__Visitor)i3);
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitSetOp(OOC_IR_VisitAll__Visitor v, OOC_IR__SetOp op) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)op;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4444))+12);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4444))+12);
  i3 = (OOC_INT32)v;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4450)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i2, (OOC_IR__Visitor)i3);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4470))+16);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4470))+16);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4477)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i0, (OOC_IR__Visitor)i3);
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitSetRange(OOC_IR_VisitAll__Visitor v, OOC_IR__SetRange range) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)range;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4587))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4587))+8);
  i3 = (OOC_INT32)v;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4593)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i2, (OOC_IR__Visitor)i3);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4616))+12);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4616))+12);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4620)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i0, (OOC_IR__Visitor)i3);
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitChangeElement(OOC_IR_VisitAll__Visitor v, OOC_IR__ChangeElement ch) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)ch;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4737))+12);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4737))+12);
  i3 = (OOC_INT32)v;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4742)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i2, (OOC_IR__Visitor)i3);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4762))+16);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4762))+16);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4771)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i0, (OOC_IR__Visitor)i3);
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitShift(OOC_IR_VisitAll__Visitor v, OOC_IR__Shift shift) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)shift;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4883))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4883))+8);
  i3 = (OOC_INT32)v;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4890)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i2, (OOC_IR__Visitor)i3);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4913))+12);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4913))+12);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4917)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i0, (OOC_IR__Visitor)i3);
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitTypeCast(OOC_IR_VisitAll__Visitor v, OOC_IR__TypeCast op) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)op;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5021))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5021))+8);
  i2 = (OOC_INT32)v;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5027)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i0, (OOC_IR__Visitor)i2);
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitTypeConv(OOC_IR_VisitAll__Visitor v, OOC_IR__TypeConv op) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)op;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5134))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5134))+8);
  i2 = (OOC_INT32)v;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5140)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i0, (OOC_IR__Visitor)i2);
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitTypeGuard(OOC_IR_VisitAll__Visitor v, OOC_IR__TypeGuard op) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)op;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5249))+8);
  i1 = (OOC_INT32)v;
  OOC_IR__TypeTestDesc_Accept((OOC_IR__TypeTest)i0, (OOC_IR__Visitor)i1);
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitTypeTag(OOC_IR_VisitAll__Visitor v, OOC_IR__TypeTag op) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)op;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5360))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5360))+8);
  i2 = (OOC_INT32)v;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5368)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i0, (OOC_IR__Visitor)i2);
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitTypeTest(OOC_IR_VisitAll__Visitor v, OOC_IR__TypeTest op) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)op;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5474))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5474))+8);
  i2 = (OOC_INT32)v;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5480)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i0, (OOC_IR__Visitor)i2);
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitModuleRef(OOC_IR_VisitAll__Visitor v, OOC_IR__ModuleRef modRef) {

  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitPredefProc(OOC_IR_VisitAll__Visitor v, OOC_IR__PredefProc pproc) {

  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitProcedureRef(OOC_IR_VisitAll__Visitor v, OOC_IR__ProcedureRef procRef) {

  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitTypeRef(OOC_IR_VisitAll__Visitor v, OOC_IR__TypeRef typeRef) {

  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitVar(OOC_IR_VisitAll__Visitor v, OOC_IR__Var var) {

  return;
  ;
}

static void OOC_IR_VisitAll__VisitStatementSeq(OOC_IR_VisitAll__Visitor v, OOC_IR__StatementSeq statmSeq) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_INT32 i;

  i0 = (OOC_INT32)statmSeq;
  i = 0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 6063)), 0);
  i2 = 0<i1;
  if (!i2) goto l8;
  i2 = (OOC_INT32)v;
  i3=0;
l3_loop:
  i4 = _check_pointer(i0, 6085);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 6085))*4);
  i5 = _check_pointer(i0, 6085);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 6085))*4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 6088)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i5, (OOC_IR__Visitor)i2);
  i3 = i3+1;
  i = i3;
  i4 = i3<i1;
  if (i4) goto l3_loop;
l8:
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitAssert(OOC_IR_VisitAll__Visitor v, OOC_IR__Assert assert) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)assert;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6215))+8);
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l4;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6251))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6251))+8);
  i2 = (OOC_INT32)v;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6262)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i0, (OOC_IR__Visitor)i2);
l4:
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitAssignment(OOC_IR_VisitAll__Visitor v, OOC_IR__Assignment assignment) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)assignment;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6396))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6396))+8);
  i3 = (OOC_INT32)v;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6406)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i2, (OOC_IR__Visitor)i3);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6434))+12);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6434))+12);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6441)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i0, (OOC_IR__Visitor)i3);
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitAssignOp(OOC_IR_VisitAll__Visitor v, OOC_IR__AssignOp assignOp) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)assignOp;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6562))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6562))+8);
  i3 = (OOC_INT32)v;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6572)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i2, (OOC_IR__Visitor)i3);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6598))+12);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6598))+12);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6605)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i0, (OOC_IR__Visitor)i3);
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitCall(OOC_IR_VisitAll__Visitor v, OOC_IR__Call call) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_INT32 i;

  i0 = (OOC_INT32)call;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6730))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6730))+8);
  i3 = (OOC_INT32)v;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6738)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i2, (OOC_IR__Visitor)i3);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6779))+12);
  i = 0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 6790)), 0);
  i2 = 0<i1;
  if (!i2) goto l8;
  i2=0;
l3_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6808))+12);
  i4 = _check_pointer(i4, 6819);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i2, i5, OOC_UINT32, 6819))*4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6808))+12);
  i5 = _check_pointer(i5, 6819);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i2, i6, OOC_UINT32, 6819))*4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 6822)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i5, (OOC_IR__Visitor)i3);
  i2 = i2+1;
  i = i2;
  i4 = i2<i1;
  if (i4) goto l3_loop;
l8:
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitCopy(OOC_IR_VisitAll__Visitor v, OOC_IR__Copy cp) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)cp;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6926))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6926))+8);
  i3 = (OOC_INT32)v;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6934)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i2, (OOC_IR__Visitor)i3);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6954))+12);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6954))+12);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6960)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i0, (OOC_IR__Visitor)i3);
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitCopyParameter(OOC_IR_VisitAll__Visitor v, OOC_IR__CopyParameter cp) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)cp;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7073))+8);
  i1 = (OOC_INT32)v;
  OOC_IR__VarDesc_Accept((OOC_IR__Var)i0, (OOC_IR__Visitor)i1);
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitCopyString(OOC_IR_VisitAll__Visitor v, OOC_IR__CopyString cp) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)cp;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7196))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7196))+8);
  i3 = (OOC_INT32)v;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7204)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i2, (OOC_IR__Visitor)i3);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7224))+12);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7224))+12);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7230)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i2, (OOC_IR__Visitor)i3);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7250))+16);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7250))+16);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7261)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i0, (OOC_IR__Visitor)i3);
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitExit(OOC_IR_VisitAll__Visitor v, OOC_IR__Exit exit) {

  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitForStatm(OOC_IR_VisitAll__Visitor v, OOC_IR__ForStatm forStatm) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)forStatm;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7459))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7459))+8);
  i3 = (OOC_INT32)v;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7464)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i2, (OOC_IR__Visitor)i3);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7490))+12);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7490))+12);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7497)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i2, (OOC_IR__Visitor)i3);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7523))+16);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7523))+16);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7528)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i2, (OOC_IR__Visitor)i3);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7554))+20);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7554))+20);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7560)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i2, (OOC_IR__Visitor)i3);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7608))+24);
  OOC_IR_VisitAll__VisitStatementSeq((OOC_IR_VisitAll__Visitor)i3, (OOC_IR__StatementSeq)i0);
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitIfStatm(OOC_IR_VisitAll__Visitor v, OOC_IR__IfStatm ifStatm) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)ifStatm;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7718))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7718))+8);
  i3 = (OOC_INT32)v;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7725)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i2, (OOC_IR__Visitor)i3);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7772))+12);
  OOC_IR_VisitAll__VisitStatementSeq((OOC_IR_VisitAll__Visitor)i3, (OOC_IR__StatementSeq)i1);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7800))+16);
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l4;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7859))+16);
  OOC_IR_VisitAll__VisitStatementSeq((OOC_IR_VisitAll__Visitor)i3, (OOC_IR__StatementSeq)i0);
l4:
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitCase(OOC_IR_VisitAll__Visitor v, OOC_IR__Case _case) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_INT32 i;

  i0 = (OOC_INT32)_case;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8011))+8);
  i = 0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 8019)), 0);
  i2 = (OOC_INT32)v;
  i3 = 0<i1;
  if (!i3) goto l8;
  i3=0;
l3_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8037))+8);
  i4 = _check_pointer(i4, 8045);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 8045))*4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8037))+8);
  i5 = _check_pointer(i5, 8045);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 8045))*4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 8048)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i5, (OOC_IR__Visitor)i2);
  i3 = i3+1;
  i = i3;
  i4 = i3<i1;
  if (i4) goto l3_loop;
l8:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8101))+12);
  OOC_IR_VisitAll__VisitStatementSeq((OOC_IR_VisitAll__Visitor)i2, (OOC_IR__StatementSeq)i0);
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitCaseStatm(OOC_IR_VisitAll__Visitor v, OOC_IR__CaseStatm caseStatm) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 i;

  i0 = (OOC_INT32)caseStatm;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8241))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8241))+8);
  i3 = (OOC_INT32)v;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8249)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i2, (OOC_IR__Visitor)i3);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8295))+12);
  i = 0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 8305)), 0);
  i2 = 0<i1;
  if (!i2) goto l8;
  i2=0;
l3_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8328))+12);
  i4 = _check_pointer(i4, 8338);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i2, i5, OOC_UINT32, 8338))*4);
  OOC_IR__CaseDesc_Accept((OOC_IR__Case)i4, (OOC_IR__Visitor)i3);
  i2 = i2+1;
  i = i2;
  i4 = i2<i1;
  if (i4) goto l3_loop;
l8:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8381))+16);
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l11;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8440))+16);
  OOC_IR_VisitAll__VisitStatementSeq((OOC_IR_VisitAll__Visitor)i3, (OOC_IR__StatementSeq)i0);
l11:
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitLoopStatm(OOC_IR_VisitAll__Visitor v, OOC_IR__LoopStatm loopStatm) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)loopStatm;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8593))+8);
  i1 = (OOC_INT32)v;
  OOC_IR_VisitAll__VisitStatementSeq((OOC_IR_VisitAll__Visitor)i1, (OOC_IR__StatementSeq)i0);
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitMoveBlock(OOC_IR_VisitAll__Visitor v, OOC_IR__MoveBlock move) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)move;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8702))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8702))+8);
  i3 = (OOC_INT32)v;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8710)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i2, (OOC_IR__Visitor)i3);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8732))+12);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8732))+12);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8738)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i2, (OOC_IR__Visitor)i3);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8760))+16);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8760))+16);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8766)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i0, (OOC_IR__Visitor)i3);
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitRaise(OOC_IR_VisitAll__Visitor v, OOC_IR__Raise raise) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)raise;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8874))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8874))+8);
  i2 = (OOC_INT32)v;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8885)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i0, (OOC_IR__Visitor)i2);
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitRepeatStatm(OOC_IR_VisitAll__Visitor v, OOC_IR__RepeatStatm repeatStatm) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)repeatStatm;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9035))+8);
  i2 = (OOC_INT32)v;
  OOC_IR_VisitAll__VisitStatementSeq((OOC_IR_VisitAll__Visitor)i2, (OOC_IR__StatementSeq)i1);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9059))+12);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9059))+12);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9074)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i0, (OOC_IR__Visitor)i2);
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitReturn(OOC_IR_VisitAll__Visitor v, OOC_IR__Return _return) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)_return;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9192))+8);
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l4;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9225))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9225))+8);
  i2 = (OOC_INT32)v;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9233)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i0, (OOC_IR__Visitor)i2);
l4:
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitCatchClause(OOC_IR_VisitAll__Visitor v, OOC_IR__CatchClause _catch) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)_catch;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9380))+12);
  i1 = (OOC_INT32)v;
  OOC_IR_VisitAll__VisitStatementSeq((OOC_IR_VisitAll__Visitor)i1, (OOC_IR__StatementSeq)i0);
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitTryStatm(OOC_IR_VisitAll__Visitor v, OOC_IR__TryStatm tryStatm) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 i;

  i0 = (OOC_INT32)tryStatm;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9543))+8);
  i2 = (OOC_INT32)v;
  OOC_IR_VisitAll__VisitStatementSeq((OOC_IR_VisitAll__Visitor)i2, (OOC_IR__StatementSeq)i1);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9585))+12);
  i = 0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 9595)), 0);
  i3 = 0<i1;
  if (!i3) goto l8;
  i3=0;
l3_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9617))+12);
  i4 = _check_pointer(i4, 9627);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 9627))*4);
  OOC_IR__CatchClauseDesc_Accept((OOC_IR__CatchClause)i4, (OOC_IR__Visitor)i2);
  i3 = i3+1;
  i = i3;
  i4 = i3<i1;
  if (i4) goto l3_loop;
l8:
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitWhileStatm(OOC_IR_VisitAll__Visitor v, OOC_IR__WhileStatm whileStatm) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)whileStatm;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9764))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9764))+8);
  i3 = (OOC_INT32)v;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9771)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i2, (OOC_IR__Visitor)i3);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9821))+12);
  OOC_IR_VisitAll__VisitStatementSeq((OOC_IR_VisitAll__Visitor)i3, (OOC_IR__StatementSeq)i0);
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitWithStatm(OOC_IR_VisitAll__Visitor v, OOC_IR__WithStatm withStatm) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)withStatm;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9941))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9941))+8);
  i3 = (OOC_INT32)v;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9948)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i2, (OOC_IR__Visitor)i3);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9997))+12);
  OOC_IR_VisitAll__VisitStatementSeq((OOC_IR_VisitAll__Visitor)i3, (OOC_IR__StatementSeq)i1);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10027))+16);
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l4;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10088))+16);
  OOC_IR_VisitAll__VisitStatementSeq((OOC_IR_VisitAll__Visitor)i3, (OOC_IR__StatementSeq)i0);
l4:
  return;
  ;
}

static void OOC_IR_VisitAll__VisitProcedureList(OOC_IR_VisitAll__Visitor v, OOC_IR__ProcedureList procList) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 i;

  i0 = (OOC_INT32)procList;
  i = 0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 10267)), 0);
  i2 = 0<i1;
  if (!i2) goto l8;
  i2 = (OOC_INT32)v;
  i3=0;
l3_loop:
  i4 = _check_pointer(i0, 10289);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 10289))*4);
  OOC_IR__ProcedureDesc_Accept((OOC_IR__Procedure)i4, (OOC_IR__Visitor)i2);
  i3 = i3+1;
  i = i3;
  i4 = i3<i1;
  if (i4) goto l3_loop;
l8:
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitProcedure(OOC_IR_VisitAll__Visitor v, OOC_IR__Procedure procedure) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)procedure;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10450))+8);
  i1 = (OOC_INT32)v;
  OOC_IR_VisitAll__VisitStatementSeq((OOC_IR_VisitAll__Visitor)i1, (OOC_IR__StatementSeq)i0);
  return;
  ;
}

void OOC_IR_VisitAll__VisitorDesc_VisitModule(OOC_IR_VisitAll__Visitor v, OOC_IR__Module module) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)module;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10584))+8);
  i2 = (OOC_INT32)v;
  OOC_IR_VisitAll__VisitProcedureList((OOC_IR_VisitAll__Visitor)i2, (OOC_IR__ProcedureList)i1);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10629))+12);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10641))+8);
  OOC_IR_VisitAll__VisitStatementSeq((OOC_IR_VisitAll__Visitor)i2, (OOC_IR__StatementSeq)i0);
  return;
  ;
}

void OOC_OOC_IR_VisitAll_init(void) {

  return;
  ;
}

/* --- */
