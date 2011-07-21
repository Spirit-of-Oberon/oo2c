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
  i2 = (OOC_INT32)op;
  i3 = (OOC_INT32)c;
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 2273));
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 2273));
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 2293));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 2281)))), OOC_IR__BuilderDesc_NewConst)),OOC_IR__BuilderDesc_NewConst)((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i2, (OOC_SymbolTable__Type)i1, (Object_Boxed__Object)i0);
  return (OOC_IR__Const)i0;
  goto l4;
l3:
  i0 = (OOC_INT32)op;
  i1 = (OOC_INT32)c;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 2199));
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 2199));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2232));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 2207)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 10, (OOC_Scanner_SymList__Symbol)i0);
  return (OOC_IR__Const)(OOC_INT32)0;
l4:
  _failed_function(2052); return 0;
  ;
}

OOC_IR__Const OOC_IR_ConstFold__ConstFoldDesc_BooleanConst(OOC_IR_ConstFold__ConstFold c, OOC_CHAR8 value, OOC_IR__Operator op) {
  register OOC_INT32 i0,i1,i2,i3,i4;

  i0 = (OOC_INT32)RT0__NewObject(_td_Object_Boxed__Boolean.baseTypes[0]);
  i1 = value;
  Object_Boxed__BooleanDesc_INIT((Object_Boxed__Boolean)i0, i1);
  i1 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(0);
  i2 = (OOC_INT32)op;
  i3 = (OOC_INT32)c;
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 2437));
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 2457));
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 2437));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 2445)))), OOC_IR__BuilderDesc_NewConst)),OOC_IR__BuilderDesc_NewConst)((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i2, (OOC_SymbolTable__Type)i1, (Object_Boxed__Object)i0);
  return (OOC_IR__Const)i0;
  ;
}

OOC_CHAR8 OOC_IR_ConstFold__ConstFoldDesc_ValidEval(OOC_IR_ConstFold__ConstFold c, OOC_IR__Expression expr, Object_Boxed__Object *result) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)c;
  *(OOC_INT32*)((_check_pointer(i0, 2648))+4) = (OOC_INT32)0;
  i1 = (OOC_INT32)expr;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2670)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i1, (OOC_IR__Visitor)i0);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2689))+4);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2719));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2727))+20);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2708))+4);
  i1 = i2!=i1;
  
l5:
  if (!i1) goto l7;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2759))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2770)))), &_td_OOC_IR__ConstDesc, 2770)), 2776))+8);
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
  *(OOC_INT32*)((_check_pointer(i0, 2909))+4) = i1;
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
  i1 = *(OOC_INT8*)((_check_pointer(i0, 3621))+8);
  switch (i1) {
  case 16:
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3672))+12);
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3682)))), &_td_OOC_IR__ConstDesc, 3682)), 3688))+8);
    i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3695)))), &_td_Object_Boxed__StringDesc);
    if (i1) goto l5;
    length = 1;
    
    goto l10;
l5:
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3738))+12);
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3748)))), &_td_OOC_IR__ConstDesc, 3748)), 3754))+8);
    i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3767)))), &_td_Object_Boxed__StringDesc, 3767)), 3774));
    i1 = *(OOC_INT32*)(_check_pointer(i1, 3781));
    length = (i1+1);
    
    goto l10;
  case 17:
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3948))+20);
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3963))+4);
    i2 = *(OOC_INT32*)((_check_pointer(i0, 4004))+16);
    i1 = (OOC_INT32)OOC_SymbolTable__ArrayDesc_GetNthElementType((OOC_SymbolTable__Array)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3974)))), &_td_OOC_SymbolTable__ArrayDesc, 3974)), i2);
    type = (OOC_SymbolTable__Type)i1;
    i1 = *(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4036)))), &_td_OOC_SymbolTable__ArrayDesc, 4036)), 4042))+52);
    length = i1;
    goto l10;
  case 18:
  case 19:
    i1 = (OOC_INT32)c;
    *(OOC_INT32*)((_check_pointer(i1, 4114))+4) = 0;
    return;
    goto l10;
  default:
    _failed_case(i1, 3613);
    goto l10;
  }
l10:
  i1 = (OOC_INT32)c;
  i2 = length;
  i2 = (OOC_INT32)Object_BigInt__NewInt(i2);
  i3 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(6);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 4164));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4185));
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 4164));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 4172)))), OOC_IR__BuilderDesc_NewConst)),OOC_IR__BuilderDesc_NewConst)((OOC_IR__Builder)i5, (OOC_Scanner_SymList__Symbol)i0, (OOC_SymbolTable__Type)i3, (Object_Boxed__Object)i2);
  *(OOC_INT32*)((_check_pointer(i1, 4152))+4) = i0;
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
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4975))+8);
  i2 = (OOC_INT32)c;
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&e);
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5004))+12);
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&s);
  
l5:
  if (i1) goto l7;
  *(OOC_INT32*)((_check_pointer(i2, 5168))+4) = 0;
  goto l8;
l7:
  i1 = (OOC_INT32)e;
  i1 = Object_BigInt__BigIntDesc_ToLongInt((Object_BigInt__BigInt)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5044)))), &_td_Object_BigInt__BigIntDesc, 5044)));
  element = i1;
  i3 = (OOC_INT32)s;
  i3 = *(OOC_UINT32*)(_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 5086)))), &_td_Object_Boxed__SetDesc, 5086)), 5090));
  set = i3;
  i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_BooleanConst((OOC_IR_ConstFold__ConstFold)i2, (_in(i1,i3)), (OOC_IR__Operator)i0);
  *(OOC_INT32*)((_check_pointer(i2, 5105))+4) = i0;
l8:
  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitSetRange(OOC_IR_ConstFold__ConstFold c, OOC_IR__SetRange op) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  Object_Boxed__Object l;
  Object_Boxed__Object r;
  OOC_INT32 left;
  OOC_INT32 right;

  i0 = (OOC_INT32)op;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5363))+8);
  i2 = (OOC_INT32)c;
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&l);
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5389))+12);
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&r);
  
l5:
  if (i1) goto l7;
  *(OOC_INT32*)((_check_pointer(i2, 5574))+4) = (OOC_INT32)0;
  goto l8;
l7:
  i1 = (OOC_INT32)l;
  i1 = Object_BigInt__BigIntDesc_ToLongInt((Object_BigInt__BigInt)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5425)))), &_td_Object_BigInt__BigIntDesc, 5425)));
  left = i1;
  i3 = (OOC_INT32)r;
  i3 = Object_BigInt__BigIntDesc_ToLongInt((Object_BigInt__BigInt)(_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 5470)))), &_td_Object_BigInt__BigIntDesc, 5470)));
  right = i3;
  i4 = (OOC_INT32)RT0__NewObject(_td_Object_Boxed__Set.baseTypes[0]);
  Object_Boxed__SetDesc_INIT((Object_Boxed__Set)i4, (_bit_range(i1,i3)));
  i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_ValueConst((OOC_IR_ConstFold__ConstFold)i2, (Object_Boxed__Object)i4, (OOC_IR__Operator)i0);
  *(OOC_INT32*)((_check_pointer(i2, 5498))+4) = i0;
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
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5778))+12);
  i2 = (OOC_INT32)c;
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&l);
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5804))+16);
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&r);
  
l5:
  if (i1) goto l7;
  *(OOC_INT32*)((_check_pointer(i2, 6295))+4) = 0;
  goto l15;
l7:
  i1 = (OOC_INT32)l;
  i1 = *(OOC_UINT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5842)))), &_td_Object_Boxed__SetDesc, 5842)), 5846));
  left = i1;
  i3 = (OOC_INT32)r;
  i3 = *(OOC_UINT32*)(_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 5878)))), &_td_Object_Boxed__SetDesc, 5878)), 5882));
  right = i3;
  i4 = *(OOC_INT8*)((_check_pointer(i0, 5908))+8);
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
    i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 6136));
    i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6168));
    i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 6136));
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6144)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i4, 6, (OOC_Scanner_SymList__Symbol)i3);
    *(OOC_INT32*)((_check_pointer(i2, 6185))+4) = 0;
    return;
    goto l14;
  }
l14:
  i1 = (OOC_INT32)RT0__NewObject(_td_Object_Boxed__Set.baseTypes[0]);
  i3 = result;
  Object_Boxed__SetDesc_INIT((Object_Boxed__Set)i1, i3);
  i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_ValueConst((OOC_IR_ConstFold__ConstFold)i2, (Object_Boxed__Object)i1, (OOC_IR__Operator)i0);
  *(OOC_INT32*)((_check_pointer(i2, 6226))+4) = i0;
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
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6766))+8);
  i2 = (OOC_INT32)c;
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&value);
  if (i1) goto l3;
  *(OOC_INT32*)((_check_pointer(i2, 7329))+4) = 0;
  goto l10;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6800))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6808))+4);
  i1 = *(OOC_INT16*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6818)))), &_td_OOC_SymbolTable__PredefTypeDesc, 6818)), 6829))+40);
  id = i1;
  switch (i1) {
  case 4 ... 7:
    i1 = (OOC_INT32)value;
    i1 = (OOC_INT32)Object_BigInt__BigIntDesc_Neg((Object_BigInt__BigInt)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6933)))), &_td_Object_BigInt__BigIntDesc, 6933)));
    i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_ValueConst((OOC_IR_ConstFold__ConstFold)i2, (Object_Boxed__Object)i1, (OOC_IR__Operator)i0);
    *(OOC_INT32*)((_check_pointer(i2, 6896))+4) = i0;
    goto l10;
  case 10:
    i1 = (OOC_INT32)RT0__NewObject(_td_Object_Boxed__Set.baseTypes[0]);
    i3 = (OOC_INT32)value;
    i3 = *(OOC_UINT32*)(_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 7030)))), &_td_Object_Boxed__SetDesc, 7030)), 7034));
    Object_Boxed__SetDesc_INIT((Object_Boxed__Set)i1, (~i3));
    i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_ValueConst((OOC_IR_ConstFold__ConstFold)i2, (Object_Boxed__Object)i1, (OOC_IR__Operator)i0);
    *(OOC_INT32*)((_check_pointer(i2, 6978))+4) = i0;
    goto l10;
  case 8:
  case 9:
    i1 = (OOC_INT32)value;
    i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7153)))), &_td_Object_Boxed__LongRealDesc, 7153)), 7162)))), Object_Boxed__LongRealDesc_Neg)),Object_Boxed__LongRealDesc_Neg)((Object_Boxed__LongReal)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7153)))), &_td_Object_Boxed__LongRealDesc, 7153)));
    i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_ValueConst((OOC_IR_ConstFold__ConstFold)i2, (Object_Boxed__Object)i1, (OOC_IR__Operator)i0);
    *(OOC_INT32*)((_check_pointer(i2, 7117))+4) = i0;
    goto l10;
  default:
    i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 7238));
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7278));
    i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 7238));
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7246)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i3, 7, (OOC_Scanner_SymList__Symbol)i0);
    *(OOC_INT32*)((_check_pointer(i2, 7292))+4) = 0;
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
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7656))+8);
  i2 = (OOC_INT32)c;
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&value);
  if (i1) goto l3;
  *(OOC_INT32*)((_check_pointer(i2, 7755))+4) = 0;
  goto l4;
l3:
  i1 = (OOC_INT32)value;
  i1 = *(OOC_UINT8*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7722)))), &_td_Object_Boxed__BooleanDesc, 7722)), 7730));
  i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_BooleanConst((OOC_IR_ConstFold__ConstFold)i2, (!i1), (OOC_IR__Operator)i0);
  *(OOC_INT32*)((_check_pointer(i2, 7683))+4) = i0;
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
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8014))+8);
  i2 = (OOC_INT32)c;
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&v);
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8041))+12);
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&e);
  
l5:
  if (i1) goto l7;
  *(OOC_INT32*)((_check_pointer(i2, 8313))+4) = (OOC_INT32)0;
  goto l12;
l7:
  i1 = (OOC_INT32)e;
  i1 = Object_BigInt__BigIntDesc_ToLongInt((Object_BigInt__BigInt)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8079)))), &_td_Object_BigInt__BigIntDesc, 8079)));
  shift = i1;
  i3 = i1<0;
  if (i3) goto l10;
  i3 = (OOC_INT32)v;
  i1 = (OOC_INT32)Object_BigInt__BigIntDesc_LShift((Object_BigInt__BigInt)(_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 8256)))), &_td_Object_BigInt__BigIntDesc, 8256)), i1);
  i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_ValueConst((OOC_IR_ConstFold__ConstFold)i2, (Object_Boxed__Object)i1, (OOC_IR__Operator)i0);
  *(OOC_INT32*)((_check_pointer(i2, 8221))+4) = i0;
  goto l12;
l10:
  i3 = (OOC_INT32)v;
  i1 = (OOC_INT32)Object_BigInt__BigIntDesc_RShift((Object_BigInt__BigInt)(_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 8170)))), &_td_Object_BigInt__BigIntDesc, 8170)), (-i1));
  i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_ValueConst((OOC_IR_ConstFold__ConstFold)i2, (Object_Boxed__Object)i1, (OOC_IR__Operator)i0);
  *(OOC_INT32*)((_check_pointer(i2, 8135))+4) = i0;
l12:
  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitCap(OOC_IR_ConstFold__ConstFold c, OOC_IR__Cap op) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  Object_Boxed__Object value;
  OOC_CHAR8 str[2];

  i0 = (OOC_INT32)op;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8482))+8);
  i2 = (OOC_INT32)c;
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&value);
  if (i1) goto l3;
  *(OOC_INT32*)((_check_pointer(i2, 8755))+4) = 0;
  goto l4;
l3:
  i1 = (OOC_INT32)value;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8546)))), &_td_Object_Boxed__StringDesc, 8546)), 8553));
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8546)))), &_td_Object_Boxed__StringDesc, 8546)), 8553));
  i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 8559)))), Object__StringDesc_CharAt)),Object__StringDesc_CharAt)((Object__String)i1, 0);
  *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, 2, OOC_UINT8, 8511))) = (_cap(i1));
  *(OOC_UINT8*)((OOC_INT32)str+(_check_index(1, 2, OOC_UINT8, 8581))) = 0u;
  i1 = (OOC_INT32)RT0__NewObject(_td_Object_Boxed__String.baseTypes[0]);
  i3 = (OOC_INT32)Object__NewLatin1((void*)(OOC_INT32)str, 2);
  Object_Boxed__StringDesc_INIT((Object_Boxed__String)i1, (Object__String)i3);
  i3 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(1);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 8609));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 8629));
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 8609));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 8617)))), OOC_IR__BuilderDesc_NewConst)),OOC_IR__BuilderDesc_NewConst)((OOC_IR__Builder)i5, (OOC_Scanner_SymList__Symbol)i0, (OOC_SymbolTable__Type)i3, (Object_Boxed__Object)i1);
  *(OOC_INT32*)((_check_pointer(i2, 8597))+4) = i0;
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
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8924))+8);
  i2 = (OOC_INT32)c;
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&value);
  if (i1) goto l3;
  *(OOC_INT32*)((_check_pointer(i2, 9144))+4) = 0;
  goto l4;
l3:
  i1 = (OOC_INT32)value;
  d0 = *(OOC_REAL64*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8976)))), &_td_Object_Boxed__LongRealDesc, 8976)), 8985));
  i1 = _entier(d0);
  i = i1;
  i1 = (OOC_INT32)Object_BigInt__NewInt(i1);
  i3 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(6);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 9013));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9033));
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 9013));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 9021)))), OOC_IR__BuilderDesc_NewConst)),OOC_IR__BuilderDesc_NewConst)((OOC_IR__Builder)i5, (OOC_Scanner_SymList__Symbol)i0, (OOC_SymbolTable__Type)i3, (Object_Boxed__Object)i1);
  *(OOC_INT32*)((_check_pointer(i2, 9001))+4) = i0;
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
      i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9567)))), &_td_Object_BigInt__BigIntDesc, 9567);
      left = (Object_BigInt__BigInt)i0;
      i1 = (OOC_INT32)r;
      i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9598)))), &_td_Object_BigInt__BigIntDesc, 9598);
      right = (Object_BigInt__BigInt)i1;
      i2 = (OOC_INT32)op;
      i3 = *(OOC_INT8*)((_check_pointer(i2, 9623))+8);
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
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9876));
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9876));
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 9911));
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9884)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 8, (OOC_Scanner_SymList__Symbol)i2);
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
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10031));
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10031));
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 10066));
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10039)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 8, (OOC_Scanner_SymList__Symbol)i2);
        goto l16;
      default:
        i0 = (OOC_INT32)c;
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10143));
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10143));
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 10175));
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10151)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 6, (OOC_Scanner_SymList__Symbol)i2);
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
      i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10331)))), &_td_Object_Boxed__LongRealDesc, 10331);
      left = (Object_Boxed__LongReal)i0;
      i1 = (OOC_INT32)r;
      i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10363)))), &_td_Object_Boxed__LongRealDesc, 10363);
      right = (Object_Boxed__LongReal)i1;
      i2 = (OOC_INT32)op;
      i3 = *(OOC_INT8*)((_check_pointer(i2, 10390))+8);
      switch (i3) {
      case 0:
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10433)))), Object_Boxed__LongRealDesc_Add)),Object_Boxed__LongRealDesc_Add)((Object_Boxed__LongReal)i0, (Object_Boxed__LongReal)i1);
        return (Object_Boxed__Object)i0;
        goto l11;
      case 1:
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10477)))), Object_Boxed__LongRealDesc_Sub)),Object_Boxed__LongRealDesc_Sub)((Object_Boxed__LongReal)i0, (Object_Boxed__LongReal)i1);
        return (Object_Boxed__Object)i0;
        goto l11;
      case 4:
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10521)))), Object_Boxed__LongRealDesc_Mul)),Object_Boxed__LongRealDesc_Mul)((Object_Boxed__LongReal)i0, (Object_Boxed__LongReal)i1);
        return (Object_Boxed__Object)i0;
        goto l11;
      case 3:
        d0 = *(OOC_REAL64*)(_check_pointer(i1, 10570));
        i3 = d0==0.0000000000000000;
        if (i3) goto l8;
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10668)))), Object_Boxed__LongRealDesc_Div)),Object_Boxed__LongRealDesc_Div)((Object_Boxed__LongReal)i0, (Object_Boxed__LongReal)i1);
        return (Object_Boxed__Object)i0;
        goto l11;
l8:
        i0 = (OOC_INT32)c;
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10596));
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10596));
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 10631));
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10604)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 8, (OOC_Scanner_SymList__Symbol)i2);
        goto l11;
      default:
        i0 = (OOC_INT32)c;
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10708));
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10708));
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 10740));
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10716)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 6, (OOC_Scanner_SymList__Symbol)i2);
        goto l11;
      }
l11:
      return (Object_Boxed__Object)0;
      ;
    }


  i0 = (OOC_INT32)op;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10876))+12);
  i2 = (OOC_INT32)c;
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&l);
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10902))+16);
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&r);
  
l5:
  if (!i1) goto l14;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10944))+12);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10949))+4);
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
  *(OOC_INT32*)((_check_pointer(i1, 11137))+4) = i0;
  return;
l14:
  i0 = (OOC_INT32)c;
  *(OOC_INT32*)((_check_pointer(i0, 11206))+4) = (OOC_INT32)0;
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
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11402))+12);
  i2 = (OOC_INT32)c;
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&l);
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11428))+16);
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&r);
  
l5:
  if (i1) goto l7;
  *(OOC_INT32*)((_check_pointer(i2, 11702))+4) = 0;
  goto l21;
l7:
  i1 = (OOC_INT32)l;
  i1 = *(OOC_UINT8*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11466)))), &_td_Object_Boxed__BooleanDesc, 11466)), 11474));
  left = i1;
  i3 = (OOC_INT32)r;
  i3 = *(OOC_UINT8*)(_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 11505)))), &_td_Object_Boxed__BooleanDesc, 11505)), 11513));
  right = i3;
  i4 = *(OOC_INT8*)((_check_pointer(i0, 11534))+8);
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
    _failed_case(i4, 11527);
    goto l20;
  }
l20:
  i1 = result;
  i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_BooleanConst((OOC_IR_ConstFold__ConstFold)i2, i1, (OOC_IR__Operator)i0);
  *(OOC_INT32*)((_check_pointer(i2, 11647))+4) = i0;
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
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11903))+8);
  i = 0;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 11911)), 0);
  i3 = (OOC_INT32)c;
  i4 = 0<i2;
  if (!i4) goto l13;
  i4=i0;i0=0;
l4_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11931))+8);
  i5 = _check_pointer(i5, 11939);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i0, i6, OOC_UINT32, 11939))*4);
  i5 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 11943)))), &_td_OOC_IR__ConstDesc);
  if (i5) goto l7;
  *(OOC_INT32*)((_check_pointer(i3, 12047))+4) = 0;
  return;
  
  goto l8;
l7:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11978))+8);
  i5 = _check_pointer(i5, 11986);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i0, i6, OOC_UINT32, 11986))*4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i5, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 11993)))), &_td_OOC_IR__ConstDesc, 11993)), 11999))+8);
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i5, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 12012)))), &_td_Object_Boxed__StringDesc, 12012)), 12019));
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
  i2 = (OOC_INT32)RT0__NewObject(_td_Object_Boxed__String.baseTypes[0]);
  Object_Boxed__StringDesc_INIT((Object_Boxed__String)i2, (Object__String)i0);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 12116));
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 12136));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12144))+4);
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 12116));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12124)))), OOC_IR__BuilderDesc_NewConst)),OOC_IR__BuilderDesc_NewConst)((OOC_IR__Builder)i5, (OOC_Scanner_SymList__Symbol)i4, (OOC_SymbolTable__Type)i1, (Object_Boxed__Object)i2);
  *(OOC_INT32*)((_check_pointer(i3, 12104))+4) = i0;
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
  auto Object_Boxed__Boolean OOC_IR_ConstFold__ConstFoldDesc_VisitCompare_SetOp(void);
    
    Object_Boxed__Boolean OOC_IR_ConstFold__ConstFoldDesc_VisitCompare_StringOp(void) {
      register OOC_INT32 i0,i1,i2,i3;
      Object_Boxed__String left;
      Object_Boxed__String right;
      OOC_CHAR8 result;

      i0 = (OOC_INT32)l;
      i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12464)))), &_td_Object_Boxed__StringDesc, 12464);
      left = (Object_Boxed__String)i0;
      i1 = (OOC_INT32)r;
      i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 12494)))), &_td_Object_Boxed__StringDesc, 12494);
      right = (Object_Boxed__String)i1;
      i2 = (OOC_INT32)op;
      i3 = *(OOC_INT8*)((_check_pointer(i2, 12514))+8);
      switch (i3) {
      case 10:
        i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12563)))), Object_Boxed__StringDesc_Cmp)),Object_Boxed__StringDesc_Cmp)((Object_Boxed__String)i0, (Object__Object)i1);
        result = (i0==0);
        goto l9;
      case 11:
        i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12617)))), Object_Boxed__StringDesc_Cmp)),Object_Boxed__StringDesc_Cmp)((Object_Boxed__String)i0, (Object__Object)i1);
        result = (i0!=0);
        goto l9;
      case 12:
        i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12671)))), Object_Boxed__StringDesc_Cmp)),Object_Boxed__StringDesc_Cmp)((Object_Boxed__String)i0, (Object__Object)i1);
        result = (i0<0);
        goto l9;
      case 13:
        i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12725)))), Object_Boxed__StringDesc_Cmp)),Object_Boxed__StringDesc_Cmp)((Object_Boxed__String)i0, (Object__Object)i1);
        result = (i0<=0);
        goto l9;
      case 14:
        i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12780)))), Object_Boxed__StringDesc_Cmp)),Object_Boxed__StringDesc_Cmp)((Object_Boxed__String)i0, (Object__Object)i1);
        result = (i0>0);
        goto l9;
      case 15:
        i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12834)))), Object_Boxed__StringDesc_Cmp)),Object_Boxed__StringDesc_Cmp)((Object_Boxed__String)i0, (Object__Object)i1);
        result = (i0>=0);
        goto l9;
      default:
        i0 = (OOC_INT32)c;
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 12868));
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 12900));
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 12868));
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 12876)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 6, (OOC_Scanner_SymList__Symbol)i2);
        return (Object_Boxed__Boolean)0;
        goto l9;
      }
l9:
      i0 = (OOC_INT32)RT0__NewObject(_td_Object_Boxed__Boolean.baseTypes[0]);
      i1 = result;
      Object_Boxed__BooleanDesc_INIT((Object_Boxed__Boolean)i0, i1);
      return (Object_Boxed__Boolean)i0;
      ;
    }

    
    Object_Boxed__Boolean OOC_IR_ConstFold__ConstFoldDesc_VisitCompare_IntegerOp(void) {
      register OOC_INT32 i0,i1,i2,i3;
      Object_BigInt__BigInt left;
      Object_BigInt__BigInt right;
      OOC_CHAR8 result;

      i0 = (OOC_INT32)l;
      i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13112)))), &_td_Object_BigInt__BigIntDesc, 13112);
      left = (Object_BigInt__BigInt)i0;
      i1 = (OOC_INT32)r;
      i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 13144)))), &_td_Object_BigInt__BigIntDesc, 13144);
      right = (Object_BigInt__BigInt)i1;
      i2 = (OOC_INT32)op;
      i3 = *(OOC_INT8*)((_check_pointer(i2, 13169))+8);
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
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13523));
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 13555));
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13523));
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 13531)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 6, (OOC_Scanner_SymList__Symbol)i2);
        return (Object_Boxed__Boolean)0;
        goto l9;
      }
l9:
      i0 = (OOC_INT32)RT0__NewObject(_td_Object_Boxed__Boolean.baseTypes[0]);
      i1 = result;
      Object_Boxed__BooleanDesc_INIT((Object_Boxed__Boolean)i0, i1);
      return (Object_Boxed__Boolean)i0;
      ;
    }

    
    Object_Boxed__Boolean OOC_IR_ConstFold__ConstFoldDesc_VisitCompare_RealOp(void) {
      register OOC_INT32 i0,i1,i2,i3;
      Object_Boxed__LongReal left;
      Object_Boxed__LongReal right;
      OOC_CHAR8 result;

      i0 = (OOC_INT32)l;
      i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13765)))), &_td_Object_Boxed__LongRealDesc, 13765);
      left = (Object_Boxed__LongReal)i0;
      i1 = (OOC_INT32)r;
      i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 13798)))), &_td_Object_Boxed__LongRealDesc, 13798);
      right = (Object_Boxed__LongReal)i1;
      i2 = (OOC_INT32)op;
      i3 = *(OOC_INT8*)((_check_pointer(i2, 13825))+8);
      switch (i3) {
      case 10:
        i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13874)))), Object_Boxed__LongRealDesc_Cmp)),Object_Boxed__LongRealDesc_Cmp)((Object_Boxed__LongReal)i0, (Object__Object)i1);
        result = (i0==0);
        goto l9;
      case 11:
        i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13928)))), Object_Boxed__LongRealDesc_Cmp)),Object_Boxed__LongRealDesc_Cmp)((Object_Boxed__LongReal)i0, (Object__Object)i1);
        result = (i0!=0);
        goto l9;
      case 12:
        i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13982)))), Object_Boxed__LongRealDesc_Cmp)),Object_Boxed__LongRealDesc_Cmp)((Object_Boxed__LongReal)i0, (Object__Object)i1);
        result = (i0<0);
        goto l9;
      case 13:
        i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14036)))), Object_Boxed__LongRealDesc_Cmp)),Object_Boxed__LongRealDesc_Cmp)((Object_Boxed__LongReal)i0, (Object__Object)i1);
        result = (i0<=0);
        goto l9;
      case 14:
        i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14091)))), Object_Boxed__LongRealDesc_Cmp)),Object_Boxed__LongRealDesc_Cmp)((Object_Boxed__LongReal)i0, (Object__Object)i1);
        result = (i0>0);
        goto l9;
      case 15:
        i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14145)))), Object_Boxed__LongRealDesc_Cmp)),Object_Boxed__LongRealDesc_Cmp)((Object_Boxed__LongReal)i0, (Object__Object)i1);
        result = (i0>=0);
        goto l9;
      default:
        i0 = (OOC_INT32)c;
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14179));
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 14211));
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14179));
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14187)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 6, (OOC_Scanner_SymList__Symbol)i2);
        return (Object_Boxed__Boolean)0;
        goto l9;
      }
l9:
      i0 = (OOC_INT32)RT0__NewObject(_td_Object_Boxed__Boolean.baseTypes[0]);
      i1 = result;
      Object_Boxed__BooleanDesc_INIT((Object_Boxed__Boolean)i0, i1);
      return (Object_Boxed__Boolean)i0;
      ;
    }

    
    Object_Boxed__Boolean OOC_IR_ConstFold__ConstFoldDesc_VisitCompare_CharOp(void) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_CHAR32 left;
      OOC_CHAR32 right;
      OOC_CHAR8 result;

      i0 = (OOC_INT32)l;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14412)))), &_td_Object_Boxed__StringDesc, 14412)), 14419));
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14412)))), &_td_Object_Boxed__StringDesc, 14412)), 14419));
      i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14425)))), Object__StringDesc_CharAt)),Object__StringDesc_CharAt)((Object__String)i0, 0);
      left = i0;
      i1 = (OOC_INT32)r;
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14458)))), &_td_Object_Boxed__StringDesc, 14458)), 14465));
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14458)))), &_td_Object_Boxed__StringDesc, 14458)), 14465));
      i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 14471)))), Object__StringDesc_CharAt)),Object__StringDesc_CharAt)((Object__String)i1, 0);
      right = i1;
      i2 = (OOC_INT32)op;
      i3 = *(OOC_INT8*)((_check_pointer(i2, 14499))+8);
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
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14811));
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 14843));
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14811));
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14819)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 6, (OOC_Scanner_SymList__Symbol)i2);
        return (Object_Boxed__Boolean)0;
        goto l9;
      }
l9:
      i0 = (OOC_INT32)RT0__NewObject(_td_Object_Boxed__Boolean.baseTypes[0]);
      i1 = result;
      Object_Boxed__BooleanDesc_INIT((Object_Boxed__Boolean)i0, i1);
      return (Object_Boxed__Boolean)i0;
      ;
    }

    
    Object_Boxed__Boolean OOC_IR_ConstFold__ConstFoldDesc_VisitCompare_BooleanOp(void) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_CHAR8 left;
      OOC_CHAR8 right;
      OOC_CHAR8 result;

      i0 = (OOC_INT32)l;
      i0 = *(OOC_UINT8*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15046)))), &_td_Object_Boxed__BooleanDesc, 15046)), 15054));
      left = i0;
      i1 = (OOC_INT32)r;
      i1 = *(OOC_UINT8*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15083)))), &_td_Object_Boxed__BooleanDesc, 15083)), 15091));
      right = i1;
      i2 = (OOC_INT32)op;
      i3 = *(OOC_INT8*)((_check_pointer(i2, 15111))+8);
      switch (i3) {
      case 10:
        result = (i0==i1);
        goto l5;
      case 11:
        result = (i0!=i1);
        goto l5;
      default:
        i0 = (OOC_INT32)c;
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 15233));
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 15265));
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 15233));
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15241)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 6, (OOC_Scanner_SymList__Symbol)i2);
        return (Object_Boxed__Boolean)0;
        goto l5;
      }
l5:
      i0 = (OOC_INT32)RT0__NewObject(_td_Object_Boxed__Boolean.baseTypes[0]);
      i1 = result;
      Object_Boxed__BooleanDesc_INIT((Object_Boxed__Boolean)i0, i1);
      return (Object_Boxed__Boolean)i0;
      ;
    }

    
    Object_Boxed__Boolean OOC_IR_ConstFold__ConstFoldDesc_VisitCompare_SetOp(void) {
      register OOC_INT32 i0,i1,i2,i3;
      Object_Boxed__Set left;
      Object_Boxed__Set right;
      OOC_CHAR8 result;

      i0 = (OOC_INT32)l;
      i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15479)))), &_td_Object_Boxed__SetDesc, 15479);
      left = (Object_Boxed__Set)i0;
      i1 = (OOC_INT32)r;
      i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15508)))), &_td_Object_Boxed__SetDesc, 15508);
      right = (Object_Boxed__Set)i1;
      i2 = (OOC_INT32)op;
      i3 = *(OOC_INT8*)((_check_pointer(i2, 15534))+8);
      switch (i3) {
      case 10:
        i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15585)))), Object_Boxed__SetDesc_Equals)),Object_Boxed__SetDesc_Equals)((Object_Boxed__Set)i0, (Object__Object)i1);
        result = i0;
        goto l5;
      case 11:
        i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15641)))), Object_Boxed__SetDesc_Equals)),Object_Boxed__SetDesc_Equals)((Object_Boxed__Set)i0, (Object__Object)i1);
        result = (!i0);
        goto l5;
      default:
        i0 = (OOC_INT32)c;
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 15677));
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 15709));
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 15677));
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15685)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 6, (OOC_Scanner_SymList__Symbol)i2);
        return (Object_Boxed__Boolean)0;
        goto l5;
      }
l5:
      i0 = (OOC_INT32)RT0__NewObject(_td_Object_Boxed__Boolean.baseTypes[0]);
      i1 = result;
      Object_Boxed__BooleanDesc_INIT((Object_Boxed__Boolean)i0, i1);
      return (Object_Boxed__Boolean)i0;
      ;
    }


  i0 = (OOC_INT32)op;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15825))+12);
  i2 = (OOC_INT32)c;
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&l);
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15851))+16);
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&r);
  
l5:
  if (i1) goto l7;
  *(OOC_INT32*)((_check_pointer(i2, 16556))+4) = (OOC_INT32)0;
  goto l21;
l7:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15880))+12);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15885))+4);
  i0 = *(OOC_INT16*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15895)))), &_td_OOC_SymbolTable__PredefTypeDesc, 15895)), 15906))+40);
  switch (i0) {
  case 4:
  case 5:
  case 6:
    i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_VisitCompare_IntegerOp();
    result = (Object_Boxed__Boolean)i0;
    goto l16;
  case 8:
  case 9:
    i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_VisitCompare_RealOp();
    result = (Object_Boxed__Boolean)i0;
    goto l16;
  case 1:
    i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_VisitCompare_CharOp();
    result = (Object_Boxed__Boolean)i0;
    goto l16;
  case 13:
  case 14:
  case 15:
    i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_VisitCompare_StringOp();
    result = (Object_Boxed__Boolean)i0;
    goto l16;
  case 0:
    i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_VisitCompare_BooleanOp();
    result = (Object_Boxed__Boolean)i0;
    goto l16;
  case 10:
    i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_VisitCompare_SetOp();
    result = (Object_Boxed__Boolean)i0;
    goto l16;
  default:
    _failed_case(i0, 15873);
    goto l16;
  }
l16:
  i0 = (OOC_INT32)result;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l19;
  i1 = (OOC_INT32)c;
  i0 = *(OOC_UINT8*)(_check_pointer(i0, 16516));
  i2 = (OOC_INT32)op;
  i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_BooleanConst((OOC_IR_ConstFold__ConstFold)i1, i0, (OOC_IR__Operator)i2);
  *(OOC_INT32*)((_check_pointer(i1, 16484))+4) = i0;
  goto l21;
l19:
  i0 = (OOC_INT32)c;
  *(OOC_INT32*)((_check_pointer(i0, 16449))+4) = (OOC_INT32)0;
l21:
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
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17230))+8);
  i2 = (OOC_INT32)c;
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&value);
  if (i1) goto l3;
  *(OOC_INT32*)((_check_pointer(i2, 19253))+4) = 0;
  goto l54;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17278))+4);
  i1 = OOC_SymbolTable_TypeRules__IsIntegerType((OOC_SymbolTable__Type)i1);
  if (i1) goto l6;
  i1=0u;
  goto l8;
l6:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17314))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 17320))+4);
  i1 = OOC_SymbolTable_TypeRules__IsCharType((OOC_SymbolTable__Type)i1);
  
l8:
  if (i1) goto l52;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17582))+4);
  i1 = OOC_SymbolTable_TypeRules__IsCharType((OOC_SymbolTable__Type)i1);
  if (i1) goto l12;
  i1=0u;
  goto l14;
l12:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17624))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 17630))+4);
  i1 = OOC_SymbolTable_TypeRules__IsIntegerType((OOC_SymbolTable__Type)i1);
  
l14:
  if (i1) goto l44;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18293))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 18298))+4);
  i1 = OOC_SymbolTable_TypeRules__IsIntegerType((OOC_SymbolTable__Type)i1);
  if (i1) goto l18;
  i1=0u;
  goto l20;
l18:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18323))+4);
  i1 = OOC_SymbolTable_TypeRules__IsRealType((OOC_SymbolTable__Type)i1);
  
l20:
  if (i1) goto l42;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18553))+4);
  i1 = OOC_SymbolTable_TypeRules__IsCharType((OOC_SymbolTable__Type)i1);
  if (i1) goto l24;
  i1=0u;
  goto l26;
l24:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18578))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 18583))+4);
  i1 = OOC_SymbolTable_TypeRules__IsCharType((OOC_SymbolTable__Type)i1);
  
l26:
  if (i1) goto l40;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18776))+4);
  i1 = OOC_SymbolTable_TypeRules__IsStringConst((OOC_SymbolTable__Type)i1);
  if (i1) goto l30;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 19184));
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19212))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 19184));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 19204));
  i5 = (OOC_INT32)value;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 19192)))), OOC_IR__BuilderDesc_NewConst)),OOC_IR__BuilderDesc_NewConst)((OOC_IR__Builder)i4, (OOC_Scanner_SymList__Symbol)i0, (OOC_SymbolTable__Type)i3, (Object_Boxed__Object)i5);
  *(OOC_INT32*)((_check_pointer(i2, 19172))+4) = i0;
  goto l54;
l30:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18922))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 18928))+4);
  i1 = OOC_SymbolTable_TypeRules__IsStringConst((OOC_SymbolTable__Type)i1);
  if (i1) goto l37;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18958))+8);
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 18965)))), &_td_OOC_IR__ConstDesc);
  if (i1) goto l35;
  i1=0u;
  goto l38;
l35:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18997))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 19003))+4);
  i1 = OOC_SymbolTable_TypeRules__IsCharType((OOC_SymbolTable__Type)i1);
  
  goto l38;
l37:
  i1=1u;
l38:
  _assert(i1, 127, 18894);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19030))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 19040)))), &_td_OOC_IR__ConstDesc, 19040)), 19046))+8);
  i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 19060)))), &_td_Object_Boxed__StringDesc, 19060);
  str = (Object_Boxed__String)i1;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19114))+8);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 19091));
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19129))+4);
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 19091));
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 19120));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 19100)))), OOC_IR__BuilderDesc_NewConst)),OOC_IR__BuilderDesc_NewConst)((OOC_IR__Builder)i5, (OOC_Scanner_SymList__Symbol)i3, (OOC_SymbolTable__Type)i0, (Object_Boxed__Object)i1);
  *(OOC_INT32*)((_check_pointer(i2, 19078))+4) = i0;
  goto l54;
l40:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18704))+8);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 18681));
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18719))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 18681));
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 18710));
  i5 = (OOC_INT32)value;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 18690)))), OOC_IR__BuilderDesc_NewConst)),OOC_IR__BuilderDesc_NewConst)((OOC_IR__Builder)i4, (OOC_Scanner_SymList__Symbol)i1, (OOC_SymbolTable__Type)i0, (Object_Boxed__Object)i5);
  *(OOC_INT32*)((_check_pointer(i2, 18668))+4) = i0;
  goto l54;
l42:
  i1 = (OOC_INT32)RT0__NewObject(_td_Object_Boxed__LongReal.baseTypes[0]);
  i3 = (OOC_INT32)value;
  i3 = Object_BigInt__BigIntDesc_ToLongInt((Object_BigInt__BigInt)(_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 18431)))), &_td_Object_BigInt__BigIntDesc, 18431)));
  Object_Boxed__LongRealDesc_INIT((Object_Boxed__LongReal)i1, ((OOC_REAL64)i3));
  value = (Object_Boxed__Object)i1;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 18474));
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18502))+4);
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 18474));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 18494));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 18482)))), OOC_IR__BuilderDesc_NewConst)),OOC_IR__BuilderDesc_NewConst)((OOC_IR__Builder)i5, (OOC_Scanner_SymList__Symbol)i0, (OOC_SymbolTable__Type)i4, (Object_Boxed__Object)i1);
  *(OOC_INT32*)((_check_pointer(i2, 18462))+4) = i0;
  goto l54;
l44:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17756))+4);
  i1 = *(OOC_INT16*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17767)))), &_td_OOC_SymbolTable__PredefTypeDesc, 17767)), 17778))+40);
  switch (i1) {
  case 1:
    i1 = (OOC_INT32)value;
    i3 = (OOC_INT32)RT0__NewObject(_td_Object_Boxed__String.baseTypes[0]);
    i1 = Object_BigInt__BigIntDesc_ToLongInt((Object_BigInt__BigInt)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17885)))), &_td_Object_BigInt__BigIntDesc, 17885)));
    i1 = (OOC_INT32)Object__NewLatin1Char(i1);
    Object_Boxed__StringDesc_INIT((Object_Boxed__String)i3, (Object__String)i1);
    value = (Object_Boxed__Object)i3;
    goto l50;
  case 2:
    i1 = (OOC_INT32)value;
    i3 = (OOC_INT32)RT0__NewObject(_td_Object_Boxed__String.baseTypes[0]);
    i1 = Object_BigInt__BigIntDesc_ToLongInt((Object_BigInt__BigInt)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 18016)))), &_td_Object_BigInt__BigIntDesc, 18016)));
    i1 = (OOC_INT32)Object__NewUTF16Char(i1);
    Object_Boxed__StringDesc_INIT((Object_Boxed__String)i3, (Object__String)i1);
    value = (Object_Boxed__Object)i3;
    goto l50;
  case 3:
    i1 = (OOC_INT32)value;
    i3 = (OOC_INT32)RT0__NewObject(_td_Object_Boxed__String.baseTypes[0]);
    i1 = Object_BigInt__BigIntDesc_ToLongInt((Object_BigInt__BigInt)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 18146)))), &_td_Object_BigInt__BigIntDesc, 18146)));
    i1 = (OOC_INT32)Object__NewUCS4Char(i1);
    Object_Boxed__StringDesc_INIT((Object_Boxed__String)i3, (Object__String)i1);
    value = (Object_Boxed__Object)i3;
    goto l50;
  default:
    _failed_case(i1, 17749);
    goto l50;
  }
l50:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 18205));
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18237))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 18205));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 18228));
  i5 = (OOC_INT32)value;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 18214)))), OOC_IR__BuilderDesc_NewConst)),OOC_IR__BuilderDesc_NewConst)((OOC_IR__Builder)i4, (OOC_Scanner_SymList__Symbol)i0, (OOC_SymbolTable__Type)i3, (Object_Boxed__Object)i5);
  *(OOC_INT32*)((_check_pointer(i2, 18193))+4) = i0;
  goto l54;
l52:
  i1 = (OOC_INT32)value;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17448)))), &_td_Object_Boxed__StringDesc, 17448)), 17455));
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17448)))), &_td_Object_Boxed__StringDesc, 17448)), 17455));
  i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 17461)))), Object__StringDesc_CharAt)),Object__StringDesc_CharAt)((Object__String)i1, 0);
  i1 = (OOC_INT32)Object_BigInt__NewInt(i1);
  value = (Object_Boxed__Object)i1;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 17496));
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17528))+4);
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 17496));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 17519));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 17505)))), OOC_IR__BuilderDesc_NewConst)),OOC_IR__BuilderDesc_NewConst)((OOC_IR__Builder)i5, (OOC_Scanner_SymList__Symbol)i0, (OOC_SymbolTable__Type)i4, (Object_Boxed__Object)i1);
  *(OOC_INT32*)((_check_pointer(i2, 17484))+4) = i0;
l54:
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

void OOC_IR_ConstFold__ConstFoldDesc_VisitIterateArrayStatm(OOC_IR_ConstFold__ConstFold c, OOC_IR__IterateArrayStatm iterStatm) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitIterateObjectStatm(OOC_IR_ConstFold__ConstFold c, OOC_IR__IterateObjectStatm iterStatm) {

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
