#include <OOC/IR/ConstFold.d>
#include <__oo2c.h>
#include <setjmp.h>

static void OOC_IR_ConstFold__InitConstFold(OOC_IR_ConstFold__ConstFold c) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)c;
  OOC_IR__InitConstFold((OOC_IR__ConstFold)i0, (OOC_IR__Builder)(OOC_INT32)0);
  return;
  ;
}

OOC_IR_ConstFold__ConstFold OOC_IR_ConstFold__NewConstFold(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_IR_ConstFold__ConstFold.baseTypes[0]);
  OOC_IR_ConstFold__InitConstFold((OOC_IR_ConstFold__ConstFold)i0);
  return (OOC_IR_ConstFold__ConstFold)i0;
  ;
}

static OOC_SymbolTable__Type OOC_IR_ConstFold__SmallestType(Object_Boxed__Object value) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)value;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1697)))), &_td_Object_BigInt__BigIntDesc);
  if (i1) goto l11;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1769)))), &_td_Object_Boxed__LongRealDesc);
  if (i1) goto l9;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1893)))), &_td_Object_Boxed__SetDesc);
  if (i1) goto l7;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1885)))), 1885);
  goto l12;
l7:
  i0 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(10);
  return (OOC_SymbolTable__Type)i0;
  goto l12;
l9:
  i0 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(8);
  return (OOC_SymbolTable__Type)i0;
  goto l12;
l11:
  i0 = (OOC_INT32)OOC_SymbolTable_Predef__SmallestIntType((Object_BigInt__BigInt)i0);
  return (OOC_SymbolTable__Type)i0;
l12:
  _failed_function(1565); return 0;
  ;
}

OOC_IR__Const OOC_IR_ConstFold__ConstFoldDesc_ValueConst(OOC_IR_ConstFold__ConstFold c, Object_Boxed__Object value, OOC_IR__Operator op) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_SymbolTable__Type type;

  i0 = (OOC_INT32)value;
  i1 = (OOC_INT32)OOC_IR_ConstFold__SmallestType((Object_Boxed__Object)i0);
  type = (OOC_SymbolTable__Type)i1;
  i2 = i1==(OOC_INT32)0;
  if (i2) goto l3;
  i2 = (OOC_INT32)c;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 2273));
  i4 = (OOC_INT32)op;
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 2293));
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 2273));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 2281)))), OOC_IR__BuilderDesc_NewConst)),OOC_IR__BuilderDesc_NewConst)((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i4, (OOC_SymbolTable__Type)i1, (Object_Boxed__Object)i0);
  return (OOC_IR__Const)i0;
  goto l4;
l3:
  i0 = (OOC_INT32)c;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2199));
  i2 = (OOC_INT32)op;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 2232));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2199));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2207)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 10, (OOC_Scanner_SymList__Symbol)i2);
  return (OOC_IR__Const)(OOC_INT32)0;
l4:
  _failed_function(2052); return 0;
  ;
}

OOC_IR__Const OOC_IR_ConstFold__ConstFoldDesc_BooleanConst(OOC_IR_ConstFold__ConstFold c, OOC_CHAR8 value, OOC_IR__Operator op) {
  register OOC_INT32 i0,i1,i2,i3,i4;

  i0 = (OOC_INT32)c;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2437));
  i2 = (OOC_INT32)op;
  i3 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(0);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 2457));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2437));
  i4 = value;
  i4 = (OOC_INT32)Object_Boxed__NewBoolean(i4);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2445)))), OOC_IR__BuilderDesc_NewConst)),OOC_IR__BuilderDesc_NewConst)((OOC_IR__Builder)i0, (OOC_Scanner_SymList__Symbol)i2, (OOC_SymbolTable__Type)i3, (Object_Boxed__Object)i4);
  return (OOC_IR__Const)i0;
  ;
}

OOC_CHAR8 OOC_IR_ConstFold__ConstFoldDesc_ValidEval(OOC_IR_ConstFold__ConstFold c, OOC_IR__Expression expr, Object_Boxed__Object *result) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)c;
  *(OOC_INT32*)((_check_pointer(i0, 2646))+4) = (OOC_INT32)0;
  i1 = (OOC_INT32)expr;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2668)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i1, (OOC_IR__Visitor)i0);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2687))+4);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2717));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2725))+20);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2706))+4);
  i1 = i2!=i1;
  
l5:
  if (!i1) goto l7;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2757))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2768)))), &_td_OOC_IR__ConstDesc, 2768)), 2774))+8);
  *result = (Object_Boxed__Object)i0;
  return 1u;
l7:
  return 0u;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitConst(OOC_IR_ConstFold__ConstFold c, OOC_IR__Const _const) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)c;
  i1 = (OOC_INT32)_const;
  *(OOC_INT32*)((_check_pointer(i0, 2907))+4) = i1;
  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitVar(OOC_IR_ConstFold__ConstFold c, OOC_IR__Var car) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitPredefProc(OOC_IR_ConstFold__ConstFold c, OOC_IR__PredefProc pproc) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitProcedureRef(OOC_IR_ConstFold__ConstFold c, OOC_IR__ProcedureRef procRef) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitTypeRef(OOC_IR_ConstFold__ConstFold c, OOC_IR__TypeRef typeRef) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitModuleRef(OOC_IR_ConstFold__ConstFold c, OOC_IR__ModuleRef modRef) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitAdr(OOC_IR_ConstFold__ConstFold c, OOC_IR__Adr adr) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitLen(OOC_IR_ConstFold__ConstFold c, OOC_IR__Len len) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 length;
  OOC_SymbolTable__Type type;

  i0 = (OOC_INT32)len;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 3619))+8);
  switch (i1) {
  case 16:
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3670))+12);
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3680)))), &_td_OOC_IR__ConstDesc, 3680)), 3686))+8);
    i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3693)))), &_td_Object_Boxed__StringDesc);
    if (i1) goto l5;
    length = 1;
    
    goto l10;
l5:
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3736))+12);
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3746)))), &_td_OOC_IR__ConstDesc, 3746)), 3752))+8);
    i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3765)))), &_td_Object_Boxed__StringDesc, 3765)), 3772));
    i1 = *(OOC_INT32*)(_check_pointer(i1, 3779));
    length = (i1+1);
    
    goto l10;
  case 17:
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3946))+20);
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3961))+4);
    i2 = *(OOC_INT32*)((_check_pointer(i0, 4002))+16);
    i1 = (OOC_INT32)OOC_SymbolTable__ArrayDesc_GetNthElementType((OOC_SymbolTable__Array)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3972)))), &_td_OOC_SymbolTable__ArrayDesc, 3972)), i2);
    type = (OOC_SymbolTable__Type)i1;
    i1 = *(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4034)))), &_td_OOC_SymbolTable__ArrayDesc, 4034)), 4040))+52);
    length = i1;
    goto l10;
  case 18:
  case 19:
    i1 = (OOC_INT32)c;
    *(OOC_INT32*)((_check_pointer(i1, 4112))+4) = 0;
    return;
    goto l10;
  default:
    _failed_case(i1, 3611);
    goto l10;
  }
l10:
  i1 = (OOC_INT32)c;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 4162));
  i3 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(6);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4183));
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 4162));
  i5 = length;
  i5 = (OOC_INT32)Object_BigInt__NewInt(i5);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 4170)))), OOC_IR__BuilderDesc_NewConst)),OOC_IR__BuilderDesc_NewConst)((OOC_IR__Builder)i4, (OOC_Scanner_SymList__Symbol)i0, (OOC_SymbolTable__Type)i3, (Object_Boxed__Object)i5);
  *(OOC_INT32*)((_check_pointer(i1, 4150))+4) = i0;
  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitConstructor(OOC_IR_ConstFold__ConstFold c, OOC_IR__Constructor cons) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitCurrentException(OOC_IR_ConstFold__ConstFold c, OOC_IR__CurrentException ce) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitDeref(OOC_IR_ConstFold__ConstFold c, OOC_IR__Deref deref) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitIndex(OOC_IR_ConstFold__ConstFold c, OOC_IR__Index index) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitSetMember(OOC_IR_ConstFold__ConstFold c, OOC_IR__SetMember op) {
  register OOC_INT32 i0,i1,i2,i3;
  Object_Boxed__Object e;
  Object_Boxed__Object s;
  OOC_INT32 element;
  OOC_UINT32 set;

  i0 = (OOC_INT32)op;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4973))+8);
  i2 = (OOC_INT32)c;
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&e);
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5002))+12);
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&s);
  
l5:
  if (i1) goto l7;
  *(OOC_INT32*)((_check_pointer(i2, 5166))+4) = 0;
  goto l8;
l7:
  i1 = (OOC_INT32)e;
  i1 = Object_BigInt__BigIntDesc_ToLongInt((Object_BigInt__BigInt)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5042)))), &_td_Object_BigInt__BigIntDesc, 5042)));
  element = i1;
  i3 = (OOC_INT32)s;
  i3 = *(OOC_UINT32*)(_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 5084)))), &_td_Object_Boxed__SetDesc, 5084)), 5088));
  set = i3;
  i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_BooleanConst((OOC_IR_ConstFold__ConstFold)i2, (_in(i1,i3)), (OOC_IR__Operator)i0);
  *(OOC_INT32*)((_check_pointer(i2, 5103))+4) = i0;
l8:
  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitSetRange(OOC_IR_ConstFold__ConstFold c, OOC_IR__SetRange op) {
  register OOC_INT32 i0,i1,i2,i3;
  Object_Boxed__Object l;
  Object_Boxed__Object r;
  OOC_INT32 left;
  OOC_INT32 right;

  i0 = (OOC_INT32)op;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5361))+8);
  i2 = (OOC_INT32)c;
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&l);
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5387))+12);
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&r);
  
l5:
  if (i1) goto l7;
  *(OOC_INT32*)((_check_pointer(i2, 5570))+4) = (OOC_INT32)0;
  goto l8;
l7:
  i1 = (OOC_INT32)l;
  i1 = Object_BigInt__BigIntDesc_ToLongInt((Object_BigInt__BigInt)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5423)))), &_td_Object_BigInt__BigIntDesc, 5423)));
  left = i1;
  i3 = (OOC_INT32)r;
  i3 = Object_BigInt__BigIntDesc_ToLongInt((Object_BigInt__BigInt)(_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 5468)))), &_td_Object_BigInt__BigIntDesc, 5468)));
  right = i3;
  i1 = (OOC_INT32)Object_Boxed__NewSet((_bit_range(i1,i3)));
  i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_ValueConst((OOC_IR_ConstFold__ConstFold)i2, (Object_Boxed__Object)i1, (OOC_IR__Operator)i0);
  *(OOC_INT32*)((_check_pointer(i2, 5496))+4) = i0;
l8:
  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitSetOp(OOC_IR_ConstFold__ConstFold c, OOC_IR__SetOp op) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  Object_Boxed__Object l;
  Object_Boxed__Object r;
  OOC_UINT32 left;
  OOC_UINT32 right;
  OOC_UINT32 result;

  i0 = (OOC_INT32)op;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5774))+12);
  i2 = (OOC_INT32)c;
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&l);
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5800))+16);
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&r);
  
l5:
  if (i1) goto l7;
  *(OOC_INT32*)((_check_pointer(i2, 6289))+4) = 0;
  goto l15;
l7:
  i1 = (OOC_INT32)l;
  i1 = *(OOC_UINT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5838)))), &_td_Object_Boxed__SetDesc, 5838)), 5842));
  left = i1;
  i3 = (OOC_INT32)r;
  i3 = *(OOC_UINT32*)(_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 5874)))), &_td_Object_Boxed__SetDesc, 5874)), 5878));
  right = i3;
  i4 = *(OOC_INT8*)((_check_pointer(i0, 5904))+8);
  switch (i4) {
  case 6:
    result = (i1|i3);
    goto l14;
  case 7:
    result = (_logical_subtr(i1,i3));
    goto l14;
  case 8:
    result = (i1&i3);
    goto l14;
  case 9:
    result = (i1^i3);
    goto l14;
  default:
    i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 6132));
    i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6164));
    i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 6132));
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6140)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i4, 6, (OOC_Scanner_SymList__Symbol)i3);
    *(OOC_INT32*)((_check_pointer(i2, 6181))+4) = 0;
    return;
    goto l14;
  }
l14:
  i1 = result;
  i1 = (OOC_INT32)Object_Boxed__NewSet(i1);
  i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_ValueConst((OOC_IR_ConstFold__ConstFold)i2, (Object_Boxed__Object)i1, (OOC_IR__Operator)i0);
  *(OOC_INT32*)((_check_pointer(i2, 6222))+4) = i0;
l15:
  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitChangeElement(OOC_IR_ConstFold__ConstFold c, OOC_IR__ChangeElement op) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitSelectField(OOC_IR_ConstFold__ConstFold c, OOC_IR__SelectField sf) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitSelectProc(OOC_IR_ConstFold__ConstFold c, OOC_IR__SelectProc sp) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitNegate(OOC_IR_ConstFold__ConstFold c, OOC_IR__Negate op) {
  register OOC_INT32 i0,i1,i2,i3;
  Object_Boxed__Object value;
  OOC_INT16 id;

  i0 = (OOC_INT32)op;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6760))+8);
  i2 = (OOC_INT32)c;
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&value);
  if (i1) goto l3;
  *(OOC_INT32*)((_check_pointer(i2, 7321))+4) = 0;
  goto l10;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6794))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6802))+4);
  i1 = *(OOC_INT16*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6812)))), &_td_OOC_SymbolTable__PredefTypeDesc, 6812)), 6823))+40);
  id = i1;
  switch (i1) {
  case 4 ... 7:
    i1 = (OOC_INT32)value;
    i1 = (OOC_INT32)Object_BigInt__BigIntDesc_Neg((Object_BigInt__BigInt)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6927)))), &_td_Object_BigInt__BigIntDesc, 6927)));
    i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_ValueConst((OOC_IR_ConstFold__ConstFold)i2, (Object_Boxed__Object)i1, (OOC_IR__Operator)i0);
    *(OOC_INT32*)((_check_pointer(i2, 6890))+4) = i0;
    goto l10;
  case 10:
    i1 = (OOC_INT32)value;
    i1 = *(OOC_UINT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7022)))), &_td_Object_Boxed__SetDesc, 7022)), 7026));
    i1 = (OOC_INT32)Object_Boxed__NewSet((~i1));
    i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_ValueConst((OOC_IR_ConstFold__ConstFold)i2, (Object_Boxed__Object)i1, (OOC_IR__Operator)i0);
    *(OOC_INT32*)((_check_pointer(i2, 6972))+4) = i0;
    goto l10;
  case 8:
  case 9:
    i1 = (OOC_INT32)value;
    i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7145)))), &_td_Object_Boxed__LongRealDesc, 7145)), 7154)))), Object_Boxed__LongRealDesc_Neg)),Object_Boxed__LongRealDesc_Neg)((Object_Boxed__LongReal)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7145)))), &_td_Object_Boxed__LongRealDesc, 7145)));
    i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_ValueConst((OOC_IR_ConstFold__ConstFold)i2, (Object_Boxed__Object)i1, (OOC_IR__Operator)i0);
    *(OOC_INT32*)((_check_pointer(i2, 7109))+4) = i0;
    goto l10;
  default:
    i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 7230));
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7270));
    i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 7230));
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7238)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i3, 7, (OOC_Scanner_SymList__Symbol)i0);
    *(OOC_INT32*)((_check_pointer(i2, 7284))+4) = 0;
    goto l10;
  }
l10:
  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitNewBlock(OOC_IR_ConstFold__ConstFold c, OOC_IR__NewBlock _new) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitNewObject(OOC_IR_ConstFold__ConstFold c, OOC_IR__NewObject _new) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitNot(OOC_IR_ConstFold__ConstFold c, OOC_IR__Not op) {
  register OOC_INT32 i0,i1,i2;
  Object_Boxed__Object value;

  i0 = (OOC_INT32)op;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7648))+8);
  i2 = (OOC_INT32)c;
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&value);
  if (i1) goto l3;
  *(OOC_INT32*)((_check_pointer(i2, 7747))+4) = 0;
  goto l4;
l3:
  i1 = (OOC_INT32)value;
  i1 = *(OOC_UINT8*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7714)))), &_td_Object_Boxed__BooleanDesc, 7714)), 7722));
  i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_BooleanConst((OOC_IR_ConstFold__ConstFold)i2, (!i1), (OOC_IR__Operator)i0);
  *(OOC_INT32*)((_check_pointer(i2, 7675))+4) = i0;
l4:
  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitAbs(OOC_IR_ConstFold__ConstFold c, OOC_IR__Abs op) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitAsh(OOC_IR_ConstFold__ConstFold c, OOC_IR__Ash op) {
  register OOC_INT32 i0,i1,i2,i3;
  Object_Boxed__Object v;
  Object_Boxed__Object e;
  OOC_INT32 shift;

  i0 = (OOC_INT32)op;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8006))+8);
  i2 = (OOC_INT32)c;
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&v);
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8033))+12);
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&e);
  
l5:
  if (i1) goto l7;
  *(OOC_INT32*)((_check_pointer(i2, 8305))+4) = (OOC_INT32)0;
  goto l12;
l7:
  i1 = (OOC_INT32)e;
  i1 = Object_BigInt__BigIntDesc_ToLongInt((Object_BigInt__BigInt)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8071)))), &_td_Object_BigInt__BigIntDesc, 8071)));
  shift = i1;
  i3 = i1<0;
  if (i3) goto l10;
  i3 = (OOC_INT32)v;
  i1 = (OOC_INT32)Object_BigInt__BigIntDesc_LShift((Object_BigInt__BigInt)(_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 8248)))), &_td_Object_BigInt__BigIntDesc, 8248)), i1);
  i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_ValueConst((OOC_IR_ConstFold__ConstFold)i2, (Object_Boxed__Object)i1, (OOC_IR__Operator)i0);
  *(OOC_INT32*)((_check_pointer(i2, 8213))+4) = i0;
  goto l12;
l10:
  i3 = (OOC_INT32)v;
  i1 = (OOC_INT32)Object_BigInt__BigIntDesc_RShift((Object_BigInt__BigInt)(_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 8162)))), &_td_Object_BigInt__BigIntDesc, 8162)), (-i1));
  i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_ValueConst((OOC_IR_ConstFold__ConstFold)i2, (Object_Boxed__Object)i1, (OOC_IR__Operator)i0);
  *(OOC_INT32*)((_check_pointer(i2, 8127))+4) = i0;
l12:
  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitCap(OOC_IR_ConstFold__ConstFold c, OOC_IR__Cap op) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  Object_Boxed__Object value;
  OOC_CHAR8 str[2];

  i0 = (OOC_INT32)op;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8474))+8);
  i2 = (OOC_INT32)c;
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&value);
  if (i1) goto l3;
  *(OOC_INT32*)((_check_pointer(i2, 8745))+4) = 0;
  goto l4;
l3:
  i1 = (OOC_INT32)value;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8538)))), &_td_Object_Boxed__StringDesc, 8538)), 8545));
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8538)))), &_td_Object_Boxed__StringDesc, 8538)), 8545));
  i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 8551)))), Object__StringDesc_CharAt)),Object__StringDesc_CharAt)((Object__String)i1, 0);
  *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, 2, OOC_UINT8, 8503))) = (_cap(i1));
  *(OOC_UINT8*)((OOC_INT32)str+(_check_index(1, 2, OOC_UINT8, 8573))) = 0u;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 8601));
  i3 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(1);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 8621));
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 8601));
  i5 = (OOC_INT32)Object__NewLatin1((void*)(OOC_INT32)str, 2);
  i5 = (OOC_INT32)Object_Boxed__NewString((Object__String)i5);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8609)))), OOC_IR__BuilderDesc_NewConst)),OOC_IR__BuilderDesc_NewConst)((OOC_IR__Builder)i4, (OOC_Scanner_SymList__Symbol)i0, (OOC_SymbolTable__Type)i3, (Object_Boxed__Object)i5);
  *(OOC_INT32*)((_check_pointer(i2, 8589))+4) = i0;
l4:
  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitEntier(OOC_IR_ConstFold__ConstFold c, OOC_IR__Entier op) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  register OOC_REAL64 d0;
  Object_Boxed__Object value;
  OOC_INT32 i;

  i0 = (OOC_INT32)op;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8914))+8);
  i2 = (OOC_INT32)c;
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&value);
  if (i1) goto l3;
  *(OOC_INT32*)((_check_pointer(i2, 9134))+4) = 0;
  goto l4;
l3:
  i1 = (OOC_INT32)value;
  d0 = *(OOC_REAL64*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8966)))), &_td_Object_Boxed__LongRealDesc, 8966)), 8975));
  i1 = _entier(d0);
  i = i1;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 9003));
  i4 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(6);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9023));
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 9003));
  i1 = (OOC_INT32)Object_BigInt__NewInt(i1);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 9011)))), OOC_IR__BuilderDesc_NewConst)),OOC_IR__BuilderDesc_NewConst)((OOC_IR__Builder)i5, (OOC_Scanner_SymList__Symbol)i0, (OOC_SymbolTable__Type)i4, (Object_Boxed__Object)i1);
  *(OOC_INT32*)((_check_pointer(i2, 8991))+4) = i0;
l4:
  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitOdd(OOC_IR_ConstFold__ConstFold c, OOC_IR__Odd op) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitShift(OOC_IR_ConstFold__ConstFold c, OOC_IR__Shift op) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitBinaryArith(OOC_IR_ConstFold__ConstFold c, OOC_IR__BinaryArith op) {
  register OOC_INT32 i0,i1,i2;
  Object_Boxed__Object l;
  Object_Boxed__Object r;
  Object_Boxed__Object result;
  auto Object_Boxed__Object OOC_IR_ConstFold__ConstFoldDesc_VisitBinaryArith_IntegerOp(void);
  auto Object_Boxed__Object OOC_IR_ConstFold__ConstFoldDesc_VisitBinaryArith_RealOp(void);
    
    Object_Boxed__Object OOC_IR_ConstFold__ConstFoldDesc_VisitBinaryArith_IntegerOp(void) {
      register OOC_INT32 i0,i1,i2,i3;
      Object_BigInt__BigInt left;
      Object_BigInt__BigInt right;

      i0 = (OOC_INT32)l;
      i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9557)))), &_td_Object_BigInt__BigIntDesc, 9557);
      left = (Object_BigInt__BigInt)i0;
      i1 = (OOC_INT32)r;
      i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9588)))), &_td_Object_BigInt__BigIntDesc, 9588);
      right = (Object_BigInt__BigInt)i1;
      i2 = (OOC_INT32)op;
      i3 = *(OOC_INT8*)((_check_pointer(i2, 9613))+8);
      switch (i3) {
      case 0:
        i0 = (OOC_INT32)Object_BigInt__BigIntDesc_Add((Object_BigInt__BigInt)i0, (Object_BigInt__BigInt)i1);
        return (Object_Boxed__Object)i0;
        goto l16;
      case 1:
        i0 = (OOC_INT32)Object_BigInt__BigIntDesc_Sub((Object_BigInt__BigInt)i0, (Object_BigInt__BigInt)i1);
        return (Object_Boxed__Object)i0;
        goto l16;
      case 4:
        i0 = (OOC_INT32)Object_BigInt__BigIntDesc_Mul((Object_BigInt__BigInt)i0, (Object_BigInt__BigInt)i1);
        return (Object_Boxed__Object)i0;
        goto l16;
      case 2:
        i3 = Object_BigInt__BigIntDesc_Sign((Object_BigInt__BigInt)i1);
        i3 = i3==0;
        if (i3) goto l8;
        i0 = (OOC_INT32)Object_BigInt__BigIntDesc_Div((Object_BigInt__BigInt)i0, (Object_BigInt__BigInt)i1);
        return (Object_Boxed__Object)i0;
        goto l16;
l8:
        i0 = (OOC_INT32)c;
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9866));
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 9901));
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9866));
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9874)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 8, (OOC_Scanner_SymList__Symbol)i2);
        goto l16;
      case 5:
        i3 = Object_BigInt__BigIntDesc_Sign((Object_BigInt__BigInt)i1);
        i3 = i3==0;
        if (i3) goto l13;
        i0 = (OOC_INT32)Object_BigInt__BigIntDesc_Mod((Object_BigInt__BigInt)i0, (Object_BigInt__BigInt)i1);
        return (Object_Boxed__Object)i0;
        goto l16;
l13:
        i0 = (OOC_INT32)c;
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10021));
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 10056));
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10021));
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10029)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 8, (OOC_Scanner_SymList__Symbol)i2);
        goto l16;
      default:
        i0 = (OOC_INT32)c;
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10133));
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 10165));
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10133));
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10141)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 6, (OOC_Scanner_SymList__Symbol)i2);
        goto l16;
      }
l16:
      return (Object_Boxed__Object)0;
      ;
    }

    
    Object_Boxed__Object OOC_IR_ConstFold__ConstFoldDesc_VisitBinaryArith_RealOp(void) {
      register OOC_INT32 i0,i1,i2,i3;
      register OOC_REAL64 d0;
      Object_Boxed__LongReal left;
      Object_Boxed__LongReal right;

      i0 = (OOC_INT32)l;
      i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10321)))), &_td_Object_Boxed__LongRealDesc, 10321);
      left = (Object_Boxed__LongReal)i0;
      i1 = (OOC_INT32)r;
      i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10353)))), &_td_Object_Boxed__LongRealDesc, 10353);
      right = (Object_Boxed__LongReal)i1;
      i2 = (OOC_INT32)op;
      i3 = *(OOC_INT8*)((_check_pointer(i2, 10380))+8);
      switch (i3) {
      case 0:
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10423)))), Object_Boxed__LongRealDesc_Add)),Object_Boxed__LongRealDesc_Add)((Object_Boxed__LongReal)i0, (Object_Boxed__LongReal)i1);
        return (Object_Boxed__Object)i0;
        goto l11;
      case 1:
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10467)))), Object_Boxed__LongRealDesc_Sub)),Object_Boxed__LongRealDesc_Sub)((Object_Boxed__LongReal)i0, (Object_Boxed__LongReal)i1);
        return (Object_Boxed__Object)i0;
        goto l11;
      case 4:
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10511)))), Object_Boxed__LongRealDesc_Mul)),Object_Boxed__LongRealDesc_Mul)((Object_Boxed__LongReal)i0, (Object_Boxed__LongReal)i1);
        return (Object_Boxed__Object)i0;
        goto l11;
      case 3:
        d0 = *(OOC_REAL64*)(_check_pointer(i1, 10560));
        i3 = d0==0.0000000000000000;
        if (i3) goto l8;
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10658)))), Object_Boxed__LongRealDesc_Div)),Object_Boxed__LongRealDesc_Div)((Object_Boxed__LongReal)i0, (Object_Boxed__LongReal)i1);
        return (Object_Boxed__Object)i0;
        goto l11;
l8:
        i0 = (OOC_INT32)c;
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10586));
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 10621));
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10586));
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10594)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 8, (OOC_Scanner_SymList__Symbol)i2);
        goto l11;
      default:
        i0 = (OOC_INT32)c;
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10698));
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 10730));
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10698));
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10706)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 6, (OOC_Scanner_SymList__Symbol)i2);
        goto l11;
      }
l11:
      return (Object_Boxed__Object)0;
      ;
    }


  i0 = (OOC_INT32)op;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10866))+12);
  i2 = (OOC_INT32)c;
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&l);
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10892))+16);
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&r);
  
l5:
  if (!i1) goto l14;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10934))+12);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10939))+4);
  i0 = OOC_SymbolTable_TypeRules__IsIntegerType((OOC_SymbolTable__Type)i0);
  if (i0) goto l9;
  i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_VisitBinaryArith_RealOp();
  result = (Object_Boxed__Object)i0;
  
  goto l10;
l9:
  i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_VisitBinaryArith_IntegerOp();
  result = (Object_Boxed__Object)i0;
  
l10:
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l14;
  i1 = (OOC_INT32)c;
  i2 = (OOC_INT32)op;
  i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_ValueConst((OOC_IR_ConstFold__ConstFold)i1, (Object_Boxed__Object)i0, (OOC_IR__Operator)i2);
  *(OOC_INT32*)((_check_pointer(i1, 11127))+4) = i0;
  return;
l14:
  i0 = (OOC_INT32)c;
  *(OOC_INT32*)((_check_pointer(i0, 11196))+4) = (OOC_INT32)0;
  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitBooleanOp(OOC_IR_ConstFold__ConstFold c, OOC_IR__BooleanOp op) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  Object_Boxed__Object l;
  Object_Boxed__Object r;
  OOC_CHAR8 left;
  OOC_CHAR8 right;
  OOC_CHAR8 result;

  i0 = (OOC_INT32)op;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11392))+12);
  i2 = (OOC_INT32)c;
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&l);
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11418))+16);
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&r);
  
l5:
  if (i1) goto l7;
  *(OOC_INT32*)((_check_pointer(i2, 11692))+4) = 0;
  goto l21;
l7:
  i1 = (OOC_INT32)l;
  i1 = *(OOC_UINT8*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11456)))), &_td_Object_Boxed__BooleanDesc, 11456)), 11464));
  left = i1;
  i3 = (OOC_INT32)r;
  i3 = *(OOC_UINT8*)(_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 11495)))), &_td_Object_Boxed__BooleanDesc, 11495)), 11503));
  right = i3;
  i4 = *(OOC_INT8*)((_check_pointer(i0, 11524))+8);
  switch (i4) {
  case 20:
    if (i1) goto l12;
    i1=0u;
    goto l13;
l12:
    i1=i3;
l13:
    result = i1;
    goto l20;
  case 21:
    if (i1) goto l17;
    i1=i3;
    goto l18;
l17:
    i1=1u;
l18:
    result = i1;
    goto l20;
  default:
    _failed_case(i4, 11517);
    goto l20;
  }
l20:
  i1 = result;
  i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_BooleanConst((OOC_IR_ConstFold__ConstFold)i2, i1, (OOC_IR__Operator)i0);
  *(OOC_INT32*)((_check_pointer(i2, 11637))+4) = i0;
l21:
  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitConcat(OOC_IR_ConstFold__ConstFold c, OOC_IR__Concat op) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  Object__String s;
  OOC_INT32 i;

  i0 = (OOC_INT32)Object__emptyString;
  s = (Object__String)i0;
  i1 = (OOC_INT32)op;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11893))+8);
  i = 0;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 11901)), 0);
  i3 = (OOC_INT32)c;
  i4 = 0<i2;
  if (!i4) goto l13;
  i4=i0;i0=0;
l4_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11921))+8);
  i5 = _check_pointer(i5, 11929);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i0, i6, OOC_UINT32, 11929))*4);
  i5 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 11933)))), &_td_OOC_IR__ConstDesc);
  if (i5) goto l7;
  *(OOC_INT32*)((_check_pointer(i3, 12037))+4) = 0;
  return;
  
  goto l8;
l7:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11968))+8);
  i5 = _check_pointer(i5, 11976);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i0, i6, OOC_UINT32, 11976))*4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i5, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 11983)))), &_td_OOC_IR__ConstDesc, 11983)), 11989))+8);
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i5, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 12002)))), &_td_Object_Boxed__StringDesc, 12002)), 12009));
  i4 = (OOC_INT32)Object__Concat2((void*)i4,(void*)i5);
  s = (Object__String)i4;
  
l8:
  i0 = i0+1;
  i = i0;
  i5 = i0<i2;
  if (i5) goto l4_loop;
l12:
  i0=i4;
l13:
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 12106));
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 12126));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12134))+4);
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 12106));
  i0 = (OOC_INT32)Object_Boxed__NewString((Object__String)i0);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 12114)))), OOC_IR__BuilderDesc_NewConst)),OOC_IR__BuilderDesc_NewConst)((OOC_IR__Builder)i5, (OOC_Scanner_SymList__Symbol)i4, (OOC_SymbolTable__Type)i1, (Object_Boxed__Object)i0);
  *(OOC_INT32*)((_check_pointer(i3, 12094))+4) = i0;
  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitCompare(OOC_IR_ConstFold__ConstFold c, OOC_IR__Compare op) {
  register OOC_INT32 i0,i1,i2;
  Object_Boxed__Object l;
  Object_Boxed__Object r;
  Object_Boxed__Boolean result;
  auto Object_Boxed__Boolean OOC_IR_ConstFold__ConstFoldDesc_VisitCompare_StringOp(void);
  auto Object_Boxed__Boolean OOC_IR_ConstFold__ConstFoldDesc_VisitCompare_IntegerOp(void);
  auto Object_Boxed__Boolean OOC_IR_ConstFold__ConstFoldDesc_VisitCompare_RealOp(void);
  auto Object_Boxed__Boolean OOC_IR_ConstFold__ConstFoldDesc_VisitCompare_CharOp(void);
  auto Object_Boxed__Boolean OOC_IR_ConstFold__ConstFoldDesc_VisitCompare_BooleanOp(void);
    
    Object_Boxed__Boolean OOC_IR_ConstFold__ConstFoldDesc_VisitCompare_StringOp(void) {
      register OOC_INT32 i0,i1,i2,i3;
      Object_Boxed__String left;
      Object_Boxed__String right;
      OOC_CHAR8 result;

      i0 = (OOC_INT32)l;
      i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12452)))), &_td_Object_Boxed__StringDesc, 12452);
      left = (Object_Boxed__String)i0;
      i1 = (OOC_INT32)r;
      i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 12482)))), &_td_Object_Boxed__StringDesc, 12482);
      right = (Object_Boxed__String)i1;
      i2 = (OOC_INT32)op;
      i3 = *(OOC_INT8*)((_check_pointer(i2, 12502))+8);
      switch (i3) {
      case 10:
        i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12551)))), Object_Boxed__StringDesc_Cmp)),Object_Boxed__StringDesc_Cmp)((Object_Boxed__String)i0, (Object__Object)i1);
        result = (i0==0);
        goto l9;
      case 11:
        i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12605)))), Object_Boxed__StringDesc_Cmp)),Object_Boxed__StringDesc_Cmp)((Object_Boxed__String)i0, (Object__Object)i1);
        result = (i0!=0);
        goto l9;
      case 12:
        i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12659)))), Object_Boxed__StringDesc_Cmp)),Object_Boxed__StringDesc_Cmp)((Object_Boxed__String)i0, (Object__Object)i1);
        result = (i0<0);
        goto l9;
      case 13:
        i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12713)))), Object_Boxed__StringDesc_Cmp)),Object_Boxed__StringDesc_Cmp)((Object_Boxed__String)i0, (Object__Object)i1);
        result = (i0<=0);
        goto l9;
      case 14:
        i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12768)))), Object_Boxed__StringDesc_Cmp)),Object_Boxed__StringDesc_Cmp)((Object_Boxed__String)i0, (Object__Object)i1);
        result = (i0>0);
        goto l9;
      case 15:
        i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12822)))), Object_Boxed__StringDesc_Cmp)),Object_Boxed__StringDesc_Cmp)((Object_Boxed__String)i0, (Object__Object)i1);
        result = (i0>=0);
        goto l9;
      default:
        i0 = (OOC_INT32)c;
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 12856));
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 12888));
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 12856));
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 12864)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 6, (OOC_Scanner_SymList__Symbol)i2);
        return (Object_Boxed__Boolean)0;
        goto l9;
      }
l9:
      i0 = result;
      i0 = (OOC_INT32)Object_Boxed__NewBoolean(i0);
      return (Object_Boxed__Boolean)i0;
      ;
    }

    
    Object_Boxed__Boolean OOC_IR_ConstFold__ConstFoldDesc_VisitCompare_IntegerOp(void) {
      register OOC_INT32 i0,i1,i2,i3;
      Object_BigInt__BigInt left;
      Object_BigInt__BigInt right;
      OOC_CHAR8 result;

      i0 = (OOC_INT32)l;
      i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13098)))), &_td_Object_BigInt__BigIntDesc, 13098);
      left = (Object_BigInt__BigInt)i0;
      i1 = (OOC_INT32)r;
      i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 13130)))), &_td_Object_BigInt__BigIntDesc, 13130);
      right = (Object_BigInt__BigInt)i1;
      i2 = (OOC_INT32)op;
      i3 = *(OOC_INT8*)((_check_pointer(i2, 13155))+8);
      switch (i3) {
      case 10:
        i0 = Object_BigInt__BigIntDesc_Cmp((Object_BigInt__BigInt)i0, (Object__Object)i1);
        result = (i0==0);
        goto l9;
      case 11:
        i0 = Object_BigInt__BigIntDesc_Cmp((Object_BigInt__BigInt)i0, (Object__Object)i1);
        result = (i0!=0);
        goto l9;
      case 12:
        i0 = Object_BigInt__BigIntDesc_Cmp((Object_BigInt__BigInt)i0, (Object__Object)i1);
        result = (i0<0);
        goto l9;
      case 13:
        i0 = Object_BigInt__BigIntDesc_Cmp((Object_BigInt__BigInt)i0, (Object__Object)i1);
        result = (i0<=0);
        goto l9;
      case 14:
        i0 = Object_BigInt__BigIntDesc_Cmp((Object_BigInt__BigInt)i0, (Object__Object)i1);
        result = (i0>0);
        goto l9;
      case 15:
        i0 = Object_BigInt__BigIntDesc_Cmp((Object_BigInt__BigInt)i0, (Object__Object)i1);
        result = (i0>=0);
        goto l9;
      default:
        i0 = (OOC_INT32)c;
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13509));
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 13541));
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13509));
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 13517)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 6, (OOC_Scanner_SymList__Symbol)i2);
        return (Object_Boxed__Boolean)0;
        goto l9;
      }
l9:
      i0 = result;
      i0 = (OOC_INT32)Object_Boxed__NewBoolean(i0);
      return (Object_Boxed__Boolean)i0;
      ;
    }

    
    Object_Boxed__Boolean OOC_IR_ConstFold__ConstFoldDesc_VisitCompare_RealOp(void) {
      register OOC_INT32 i0,i1,i2,i3;
      Object_Boxed__LongReal left;
      Object_Boxed__LongReal right;
      OOC_CHAR8 result;

      i0 = (OOC_INT32)l;
      i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13749)))), &_td_Object_Boxed__LongRealDesc, 13749);
      left = (Object_Boxed__LongReal)i0;
      i1 = (OOC_INT32)r;
      i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 13782)))), &_td_Object_Boxed__LongRealDesc, 13782);
      right = (Object_Boxed__LongReal)i1;
      i2 = (OOC_INT32)op;
      i3 = *(OOC_INT8*)((_check_pointer(i2, 13809))+8);
      switch (i3) {
      case 10:
        i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13858)))), Object_Boxed__LongRealDesc_Cmp)),Object_Boxed__LongRealDesc_Cmp)((Object_Boxed__LongReal)i0, (Object__Object)i1);
        result = (i0==0);
        goto l9;
      case 11:
        i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13912)))), Object_Boxed__LongRealDesc_Cmp)),Object_Boxed__LongRealDesc_Cmp)((Object_Boxed__LongReal)i0, (Object__Object)i1);
        result = (i0!=0);
        goto l9;
      case 12:
        i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13966)))), Object_Boxed__LongRealDesc_Cmp)),Object_Boxed__LongRealDesc_Cmp)((Object_Boxed__LongReal)i0, (Object__Object)i1);
        result = (i0<0);
        goto l9;
      case 13:
        i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14020)))), Object_Boxed__LongRealDesc_Cmp)),Object_Boxed__LongRealDesc_Cmp)((Object_Boxed__LongReal)i0, (Object__Object)i1);
        result = (i0<=0);
        goto l9;
      case 14:
        i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14075)))), Object_Boxed__LongRealDesc_Cmp)),Object_Boxed__LongRealDesc_Cmp)((Object_Boxed__LongReal)i0, (Object__Object)i1);
        result = (i0>0);
        goto l9;
      case 15:
        i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14129)))), Object_Boxed__LongRealDesc_Cmp)),Object_Boxed__LongRealDesc_Cmp)((Object_Boxed__LongReal)i0, (Object__Object)i1);
        result = (i0>=0);
        goto l9;
      default:
        i0 = (OOC_INT32)c;
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14163));
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 14195));
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14163));
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14171)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 6, (OOC_Scanner_SymList__Symbol)i2);
        return (Object_Boxed__Boolean)0;
        goto l9;
      }
l9:
      i0 = result;
      i0 = (OOC_INT32)Object_Boxed__NewBoolean(i0);
      return (Object_Boxed__Boolean)i0;
      ;
    }

    
    Object_Boxed__Boolean OOC_IR_ConstFold__ConstFoldDesc_VisitCompare_CharOp(void) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_CHAR32 left;
      OOC_CHAR32 right;
      OOC_CHAR8 result;

      i0 = (OOC_INT32)l;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14394)))), &_td_Object_Boxed__StringDesc, 14394)), 14401));
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14394)))), &_td_Object_Boxed__StringDesc, 14394)), 14401));
      i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14407)))), Object__StringDesc_CharAt)),Object__StringDesc_CharAt)((Object__String)i0, 0);
      left = i0;
      i1 = (OOC_INT32)r;
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14440)))), &_td_Object_Boxed__StringDesc, 14440)), 14447));
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14440)))), &_td_Object_Boxed__StringDesc, 14440)), 14447));
      i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 14453)))), Object__StringDesc_CharAt)),Object__StringDesc_CharAt)((Object__String)i1, 0);
      right = i1;
      i2 = (OOC_INT32)op;
      i3 = *(OOC_INT8*)((_check_pointer(i2, 14481))+8);
      switch (i3) {
      case 10:
        result = (i0==i1);
        goto l9;
      case 11:
        result = (i0!=i1);
        goto l9;
      case 12:
        result = ((OOC_UINT32)i0<(OOC_UINT32)i1);
        goto l9;
      case 13:
        result = ((OOC_UINT32)i0<=(OOC_UINT32)i1);
        goto l9;
      case 14:
        result = ((OOC_UINT32)i0>(OOC_UINT32)i1);
        goto l9;
      case 15:
        result = ((OOC_UINT32)i0>=(OOC_UINT32)i1);
        goto l9;
      default:
        i0 = (OOC_INT32)c;
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14793));
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 14825));
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14793));
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14801)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 6, (OOC_Scanner_SymList__Symbol)i2);
        return (Object_Boxed__Boolean)0;
        goto l9;
      }
l9:
      i0 = result;
      i0 = (OOC_INT32)Object_Boxed__NewBoolean(i0);
      return (Object_Boxed__Boolean)i0;
      ;
    }

    
    Object_Boxed__Boolean OOC_IR_ConstFold__ConstFoldDesc_VisitCompare_BooleanOp(void) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_CHAR8 left;
      OOC_CHAR8 right;
      OOC_CHAR8 result;

      i0 = (OOC_INT32)l;
      i0 = *(OOC_UINT8*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15026)))), &_td_Object_Boxed__BooleanDesc, 15026)), 15034));
      left = i0;
      i1 = (OOC_INT32)r;
      i1 = *(OOC_UINT8*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15063)))), &_td_Object_Boxed__BooleanDesc, 15063)), 15071));
      right = i1;
      i2 = (OOC_INT32)op;
      i3 = *(OOC_INT8*)((_check_pointer(i2, 15091))+8);
      switch (i3) {
      case 10:
        result = (i0==i1);
        goto l5;
      case 11:
        result = (i0!=i1);
        goto l5;
      default:
        i0 = (OOC_INT32)c;
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 15213));
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 15245));
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 15213));
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15221)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 6, (OOC_Scanner_SymList__Symbol)i2);
        return (Object_Boxed__Boolean)0;
        goto l5;
      }
l5:
      i0 = result;
      i0 = (OOC_INT32)Object_Boxed__NewBoolean(i0);
      return (Object_Boxed__Boolean)i0;
      ;
    }


  i0 = (OOC_INT32)op;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15357))+12);
  i2 = (OOC_INT32)c;
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&l);
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15383))+16);
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&r);
  
l5:
  if (i1) goto l7;
  *(OOC_INT32*)((_check_pointer(i2, 16041))+4) = (OOC_INT32)0;
  goto l20;
l7:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15412))+12);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15417))+4);
  i0 = *(OOC_INT16*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15427)))), &_td_OOC_SymbolTable__PredefTypeDesc, 15427)), 15438))+40);
  switch (i0) {
  case 4:
  case 5:
  case 6:
    i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_VisitCompare_IntegerOp();
    result = (Object_Boxed__Boolean)i0;
    goto l15;
  case 8:
  case 9:
    i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_VisitCompare_RealOp();
    result = (Object_Boxed__Boolean)i0;
    goto l15;
  case 1:
    i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_VisitCompare_CharOp();
    result = (Object_Boxed__Boolean)i0;
    goto l15;
  case 13:
  case 14:
  case 15:
    i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_VisitCompare_StringOp();
    result = (Object_Boxed__Boolean)i0;
    goto l15;
  case 0:
    i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_VisitCompare_BooleanOp();
    result = (Object_Boxed__Boolean)i0;
    goto l15;
  default:
    _failed_case(i0, 15405);
    goto l15;
  }
l15:
  i0 = (OOC_INT32)result;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l18;
  i1 = (OOC_INT32)c;
  i0 = *(OOC_UINT8*)(_check_pointer(i0, 16001));
  i2 = (OOC_INT32)op;
  i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_BooleanConst((OOC_IR_ConstFold__ConstFold)i1, i0, (OOC_IR__Operator)i2);
  *(OOC_INT32*)((_check_pointer(i1, 15969))+4) = i0;
  goto l20;
l18:
  i0 = (OOC_INT32)c;
  *(OOC_INT32*)((_check_pointer(i0, 15934))+4) = (OOC_INT32)0;
l20:
  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitTypeCast(OOC_IR_ConstFold__ConstFold c, OOC_IR__TypeCast op) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitTypeConv(OOC_IR_ConstFold__ConstFold c, OOC_IR__TypeConv op) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  Object_Boxed__Object value;
  Object_Boxed__String str;

  i0 = (OOC_INT32)op;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16715))+8);
  i2 = (OOC_INT32)c;
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&value);
  if (i1) goto l3;
  *(OOC_INT32*)((_check_pointer(i2, 18654))+4) = 0;
  goto l53;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16763))+4);
  i1 = OOC_SymbolTable_TypeRules__IsIntegerType((OOC_SymbolTable__Type)i1);
  if (i1) goto l6;
  i1=0u;
  goto l8;
l6:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16799))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 16805))+4);
  i1 = OOC_SymbolTable_TypeRules__IsCharType((OOC_SymbolTable__Type)i1);
  
l8:
  if (i1) goto l51;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17067))+4);
  i1 = OOC_SymbolTable_TypeRules__IsCharType((OOC_SymbolTable__Type)i1);
  if (i1) goto l12;
  i1=0u;
  goto l14;
l12:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17109))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 17115))+4);
  i1 = OOC_SymbolTable_TypeRules__IsIntegerType((OOC_SymbolTable__Type)i1);
  
l14:
  if (i1) goto l43;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17772))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 17777))+4);
  i1 = OOC_SymbolTable_TypeRules__IsIntegerType((OOC_SymbolTable__Type)i1);
  if (i1) goto l18;
  i1=0u;
  goto l20;
l18:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17802))+4);
  i1 = OOC_SymbolTable_TypeRules__IsRealType((OOC_SymbolTable__Type)i1);
  
l20:
  if (i1) goto l41;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18030))+4);
  i1 = OOC_SymbolTable_TypeRules__IsCharType((OOC_SymbolTable__Type)i1);
  if (i1) goto l24;
  i1=0u;
  goto l26;
l24:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18055))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 18060))+4);
  i1 = OOC_SymbolTable_TypeRules__IsCharType((OOC_SymbolTable__Type)i1);
  
l26:
  if (i1) goto l53;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18177))+4);
  i1 = OOC_SymbolTable_TypeRules__IsStringConst((OOC_SymbolTable__Type)i1);
  if (i1) goto l30;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 18585));
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18613))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 18605));
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 18585));
  i5 = (OOC_INT32)value;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 18593)))), OOC_IR__BuilderDesc_NewConst)),OOC_IR__BuilderDesc_NewConst)((OOC_IR__Builder)i4, (OOC_Scanner_SymList__Symbol)i0, (OOC_SymbolTable__Type)i3, (Object_Boxed__Object)i5);
  *(OOC_INT32*)((_check_pointer(i2, 18573))+4) = i0;
  goto l53;
l30:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18323))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 18329))+4);
  i1 = OOC_SymbolTable_TypeRules__IsStringConst((OOC_SymbolTable__Type)i1);
  if (i1) goto l37;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18359))+8);
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 18366)))), &_td_OOC_IR__ConstDesc);
  if (i1) goto l35;
  i1=0u;
  goto l38;
l35:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18398))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 18404))+4);
  i1 = OOC_SymbolTable_TypeRules__IsCharType((OOC_SymbolTable__Type)i1);
  
  goto l38;
l37:
  i1=1u;
l38:
  _assert(i1, 127, 18295);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18431))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 18441)))), &_td_OOC_IR__ConstDesc, 18441)), 18447))+8);
  i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 18461)))), &_td_Object_Boxed__StringDesc, 18461);
  str = (Object_Boxed__String)i1;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 18492));
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18515))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18530))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 18521));
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 18492));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 18501)))), OOC_IR__BuilderDesc_NewConst)),OOC_IR__BuilderDesc_NewConst)((OOC_IR__Builder)i5, (OOC_Scanner_SymList__Symbol)i4, (OOC_SymbolTable__Type)i0, (Object_Boxed__Object)i1);
  *(OOC_INT32*)((_check_pointer(i2, 18479))+4) = i0;
  goto l53;
l41:
  i1 = (OOC_INT32)value;
  i1 = Object_BigInt__BigIntDesc_ToLongInt((Object_BigInt__BigInt)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17908)))), &_td_Object_BigInt__BigIntDesc, 17908)));
  i1 = (OOC_INT32)Object_Boxed__NewLongReal(((OOC_REAL64)i1));
  value = (Object_Boxed__Object)i1;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 17951));
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17979))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 17971));
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 17951));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 17959)))), OOC_IR__BuilderDesc_NewConst)),OOC_IR__BuilderDesc_NewConst)((OOC_IR__Builder)i5, (OOC_Scanner_SymList__Symbol)i0, (OOC_SymbolTable__Type)i4, (Object_Boxed__Object)i1);
  *(OOC_INT32*)((_check_pointer(i2, 17939))+4) = i0;
  goto l53;
l43:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17241))+4);
  i1 = *(OOC_INT16*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17252)))), &_td_OOC_SymbolTable__PredefTypeDesc, 17252)), 17263))+40);
  switch (i1) {
  case 1:
    i1 = (OOC_INT32)value;
    i1 = Object_BigInt__BigIntDesc_ToLongInt((Object_BigInt__BigInt)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17368)))), &_td_Object_BigInt__BigIntDesc, 17368)));
    i1 = (OOC_INT32)Object__NewLatin1Char(i1);
    i1 = (OOC_INT32)Object_Boxed__NewString((Object__String)i1);
    value = (Object_Boxed__Object)i1;
    goto l49;
  case 2:
    i1 = (OOC_INT32)value;
    i1 = Object_BigInt__BigIntDesc_ToLongInt((Object_BigInt__BigInt)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17497)))), &_td_Object_BigInt__BigIntDesc, 17497)));
    i1 = (OOC_INT32)Object__NewUTF16Char(i1);
    i1 = (OOC_INT32)Object_Boxed__NewString((Object__String)i1);
    value = (Object_Boxed__Object)i1;
    goto l49;
  case 3:
    i1 = (OOC_INT32)value;
    i1 = Object_BigInt__BigIntDesc_ToLongInt((Object_BigInt__BigInt)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17625)))), &_td_Object_BigInt__BigIntDesc, 17625)));
    i1 = (OOC_INT32)Object__NewUCS4Char(i1);
    i1 = (OOC_INT32)Object_Boxed__NewString((Object__String)i1);
    value = (Object_Boxed__Object)i1;
    goto l49;
  default:
    _failed_case(i1, 17234);
    goto l49;
  }
l49:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 17684));
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17716))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 17707));
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 17684));
  i5 = (OOC_INT32)value;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17693)))), OOC_IR__BuilderDesc_NewConst)),OOC_IR__BuilderDesc_NewConst)((OOC_IR__Builder)i4, (OOC_Scanner_SymList__Symbol)i0, (OOC_SymbolTable__Type)i3, (Object_Boxed__Object)i5);
  *(OOC_INT32*)((_check_pointer(i2, 17672))+4) = i0;
  goto l53;
l51:
  i1 = (OOC_INT32)value;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16933)))), &_td_Object_Boxed__StringDesc, 16933)), 16940));
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16933)))), &_td_Object_Boxed__StringDesc, 16933)), 16940));
  i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 16946)))), Object__StringDesc_CharAt)),Object__StringDesc_CharAt)((Object__String)i1, 0);
  i1 = (OOC_INT32)Object_BigInt__NewInt(i1);
  value = (Object_Boxed__Object)i1;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 16981));
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17013))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 17004));
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 16981));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 16990)))), OOC_IR__BuilderDesc_NewConst)),OOC_IR__BuilderDesc_NewConst)((OOC_IR__Builder)i5, (OOC_Scanner_SymList__Symbol)i0, (OOC_SymbolTable__Type)i4, (Object_Boxed__Object)i1);
  *(OOC_INT32*)((_check_pointer(i2, 16969))+4) = i0;
l53:
  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitTypeGuard(OOC_IR_ConstFold__ConstFold c, OOC_IR__TypeGuard op) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitTypeTag(OOC_IR_ConstFold__ConstFold c, OOC_IR__TypeTag op) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitTypeTest(OOC_IR_ConstFold__ConstFold c, OOC_IR__TypeTest op) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitCall(OOC_IR_ConstFold__ConstFold c, OOC_IR__Call call) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitAssert(OOC_IR_ConstFold__ConstFold c, OOC_IR__Assert assert) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitReturn(OOC_IR_ConstFold__ConstFold c, OOC_IR__Return _return) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitAssignment(OOC_IR_ConstFold__ConstFold c, OOC_IR__Assignment assignment) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitAssignOp(OOC_IR_ConstFold__ConstFold c, OOC_IR__AssignOp assignOp) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitExit(OOC_IR_ConstFold__ConstFold c, OOC_IR__Exit exit) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitForStatm(OOC_IR_ConstFold__ConstFold c, OOC_IR__ForStatm forStatm) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitIfStatm(OOC_IR_ConstFold__ConstFold c, OOC_IR__IfStatm ifStatm) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitCase(OOC_IR_ConstFold__ConstFold c, OOC_IR__Case _case) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitCaseStatm(OOC_IR_ConstFold__ConstFold c, OOC_IR__CaseStatm caseStatm) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitLoopStatm(OOC_IR_ConstFold__ConstFold c, OOC_IR__LoopStatm loopStatm) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitMoveBlock(OOC_IR_ConstFold__ConstFold c, OOC_IR__MoveBlock move) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitRaise(OOC_IR_ConstFold__ConstFold c, OOC_IR__Raise raise) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitRepeatStatm(OOC_IR_ConstFold__ConstFold c, OOC_IR__RepeatStatm repeatStatm) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitCatchClause(OOC_IR_ConstFold__ConstFold c, OOC_IR__CatchClause _catch) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitTryStatm(OOC_IR_ConstFold__ConstFold c, OOC_IR__TryStatm tryStatm) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitWhileStatm(OOC_IR_ConstFold__ConstFold c, OOC_IR__WhileStatm whileStatm) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitWithStatm(OOC_IR_ConstFold__ConstFold c, OOC_IR__WithStatm withStatm) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitCopy(OOC_IR_ConstFold__ConstFold c, OOC_IR__Copy cp) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitCopyParameter(OOC_IR_ConstFold__ConstFold c, OOC_IR__CopyParameter cp) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitCopyString(OOC_IR_ConstFold__ConstFold c, OOC_IR__CopyString cp) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitProcedure(OOC_IR_ConstFold__ConstFold c, OOC_IR__Procedure procedure) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitModule(OOC_IR_ConstFold__ConstFold c, OOC_IR__Module module) {

  return;
  ;
}

void OOC_OOC_IR_ConstFold_init(void) {

  return;
  ;
}

/* --- */
