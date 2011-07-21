#include <OOC/SSA.d>
#include <__oo2c.h>
#include <setjmp.h>

void OOC_SSA__InitNode(OOC_SSA__Node n) {

  return;
  ;
}

static void OOC_SSA__SetUse(OOC_SSA__Result arg, OOC_SSA__Opnd opnd) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)opnd;
  i1 = (OOC_INT32)arg;
  *(OOC_INT32*)(_check_pointer(i0, 8898)) = i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8936))+12);
  *(OOC_INT32*)((_check_pointer(i0, 8920))+16) = i2;
  *(OOC_INT32*)((_check_pointer(i1, 8954))+12) = i0;
  return;
  ;
}

static void OOC_SSA__DeleteUse(OOC_SSA__Opnd opnd) {
  register OOC_INT32 i0,i1,i2;
  OOC_SSA__Opnd prev;

  i0 = (OOC_INT32)opnd;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9123));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 9128))+12);
  i1 = i1==i0;
  if (i1) goto l12;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9220));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 9225))+12);
  prev = (OOC_SSA__Opnd)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 9253))+16);
  i2 = i2!=i0;
  if (!i2) goto l11;
l6_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 9294))+16);
  prev = (OOC_SSA__Opnd)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 9253))+16);
  i2 = i2!=i0;
  if (i2) goto l6_loop;
l11:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9342))+16);
  *(OOC_INT32*)((_check_pointer(i1, 9325))+16) = i2;
  goto l13;
l12:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9161));
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9183))+16);
  *(OOC_INT32*)((_check_pointer(i1, 9166))+12) = i2;
l13:
  *(OOC_INT32*)((_check_pointer(i0, 9369))+16) = 0;
  *(OOC_INT32*)(_check_pointer(i0, 9395)) = 0;
  return;
  ;
}

static void OOC_SSA__InitOpnd(OOC_SSA__Opnd opnd, OOC_SSA__Result arg, OOC_INT8 _class) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)opnd;
  OOC_SSA__InitNode((OOC_SSA__Node)i0);
  i1 = (OOC_INT32)arg;
  *(OOC_INT32*)(_check_pointer(i0, 9598)) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 9620))+16) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 9646))+8) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 9673))+12) = 0;
  i2 = _class;
  *(OOC_INT8*)((_check_pointer(i0, 9697))+4) = i2;
  OOC_SSA__SetUse((OOC_SSA__Result)i1, (OOC_SSA__Opnd)i0);
  return;
  ;
}

static OOC_SSA__Opnd OOC_SSA__NewOpnd(OOC_SSA__Result arg, OOC_INT8 _class) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA__Opnd.baseTypes[0]);
  i1 = (OOC_INT32)arg;
  i2 = _class;
  OOC_SSA__InitOpnd((OOC_SSA__Opnd)i0, (OOC_SSA__Result)i1, i2);
  return (OOC_SSA__Opnd)i0;
  ;
}

static void OOC_SSA__InitTypedOpnd(OOC_SSA__TypedOpnd opnd, OOC_SSA__Result arg, OOC_INT8 _class, OOC_SymbolTable__Type type, OOC_CHAR8 passByReference) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)opnd;
  i1 = (OOC_INT32)arg;
  i2 = _class;
  OOC_SSA__InitOpnd((OOC_SSA__Opnd)i0, (OOC_SSA__Result)i1, i2);
  i1 = (OOC_INT32)type;
  *(OOC_INT32*)((_check_pointer(i0, 10242))+20) = i1;
  i1 = passByReference;
  *(OOC_UINT8*)((_check_pointer(i0, 10266))+24) = i1;
  return;
  ;
}

static OOC_SSA__Opnd OOC_SSA__NewTypedOpnd(OOC_SSA__Result arg, OOC_INT8 _class, OOC_SymbolTable__Type type, OOC_CHAR8 passByReference) {
  register OOC_INT32 i0,i1,i2,i3,i4;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA__TypedOpnd.baseTypes[0]);
  i1 = (OOC_INT32)arg;
  i2 = _class;
  i3 = (OOC_INT32)type;
  i4 = passByReference;
  OOC_SSA__InitTypedOpnd((OOC_SSA__TypedOpnd)i0, (OOC_SSA__Result)i1, i2, (OOC_SymbolTable__Type)i3, i4);
  return (OOC_SSA__Opnd)i0;
  ;
}

void OOC_SSA__OpndDesc_DeleteOpnd(OOC_SSA__Opnd opnd) {
  register OOC_INT32 i0,i1,i2;
  OOC_SSA__Opnd prev;

  i0 = (OOC_INT32)opnd;
  OOC_SSA__DeleteUse((OOC_SSA__Opnd)i0);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10813))+12);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10820))+24);
  i1 = i1==i0;
  if (i1) goto l12;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10917))+12);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10924))+24);
  prev = (OOC_SSA__Opnd)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10953))+8);
  i2 = i2!=i0;
  if (!i2) goto l11;
l6_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10995))+8);
  prev = (OOC_SSA__Opnd)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10953))+8);
  i2 = i2!=i0;
  if (i2) goto l6_loop;
l11:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11045))+8);
  *(OOC_INT32*)((_check_pointer(i1, 11027))+8) = i2;
  goto l13;
l12:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10854))+12);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10879))+8);
  *(OOC_INT32*)((_check_pointer(i1, 10861))+24) = i2;
l13:
  *(OOC_INT32*)((_check_pointer(i0, 11073))+8) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i0, 11100))+12) = (OOC_INT32)0;
  return;
  ;
}

void OOC_SSA__OpndDesc_ReplaceArg(OOC_SSA__Opnd opnd, OOC_SSA__Result arg) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)opnd;
  OOC_SSA__DeleteUse((OOC_SSA__Opnd)i0);
  i1 = (OOC_INT32)arg;
  OOC_SSA__SetUse((OOC_SSA__Result)i1, (OOC_SSA__Opnd)i0);
  return;
  ;
}

OOC_INT32 OOC_SSA__OpndDesc_OpndIndex(OOC_SSA__Opnd opnd) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_INT32 i;
  OOC_SSA__Opnd ptr;

  i = 0;
  i0 = (OOC_INT32)opnd;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11976))+12);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11983))+24);
  ptr = (OOC_SSA__Opnd)i1;
  i2 = i1!=i0;
  if (i2) goto l3;
  i0=0;
  goto l9;
l3:
  i2=i1;i1=0;
l4_loop:
  i1 = i1+1;
  i = i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 12052))+8);
  ptr = (OOC_SSA__Opnd)i2;
  i3 = i2!=i0;
  if (i3) goto l4_loop;
l8:
  i0=i1;
l9:
  return i0;
  ;
}

OOC_INT32 OOC_SSA__OpndDesc_GetIntConst(OOC_SSA__Opnd opnd) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)opnd;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 12249));
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12255)))), &_td_OOC_SSA__ConstDesc, 12255)), 12261))+44);
  i0 = Object_BigInt__BigIntDesc_ToLongInt((Object_BigInt__BigInt)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12276)))), &_td_Object_BigInt__BigIntDesc, 12276)));
  return i0;
  ;
}

OOC_CHAR8 OOC_SSA__OpndDesc_IsScheduleOpnd(OOC_SSA__Opnd opnd) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)opnd;
  i0 = *(OOC_INT8*)((_check_pointer(i0, 12390))+4);
  switch (i0) {
  case 17:
  case 18:
  case 20:
    return 1u;
    goto l4;
  default:
    return 0u;
    goto l4;
  }
l4:
  _failed_function(12341); return 0;
  ;
}

OOC_CHAR8 OOC_SSA__OpndDesc_IsValueOpnd(OOC_SSA__Opnd opnd) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)opnd;
  i0 = *(OOC_INT8*)((_check_pointer(i0, 12921))+4);
  switch (i0) {
  case 18:
  case 20:
  case 5:
  case 7:
    return 0u;
    goto l4;
  default:
    return 1u;
    goto l4;
  }
l4:
  _failed_function(12603); return 0;
  ;
}

OOC_CHAR8 OOC_SSA__OpndDesc_IsValueOpndHere(OOC_SSA__Opnd opnd) {
  register OOC_INT32 i0,i1,i2;
  OOC_SSA__Instr instr;

  i0 = (OOC_INT32)opnd;
  i1 = OOC_SSA__OpndDesc_IsValueOpnd((OOC_SSA__Opnd)i0);
  if (i1) goto l3;
  return 0u;
  goto l8;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13892))+12);
  instr = (OOC_SSA__Instr)i1;
  i2 = *(OOC_INT8*)((_check_pointer(i1, 14209))+36);
  i2 = i2!=5;
  if (i2) goto l6;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14244))+24);
  i0 = i1!=i0;
  
  goto l7;
l6:
  i0=1u;
l7:
  return i0;
l8:
  _failed_function(13155); return 0;
  ;
}

static void OOC_SSA__InitResult(OOC_SSA__Result res, OOC_SSA__Instr instr, OOC_INT8 _class, OOC_INT8 subclass) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)res;
  OOC_SSA__InitNode((OOC_SSA__Node)i0);
  *(OOC_INT32*)(_check_pointer(i0, 14595)) = 0;
  i1 = (OOC_INT32)instr;
  *(OOC_INT32*)((_check_pointer(i0, 14623))+8) = i1;
  i1 = _class;
  *(OOC_INT8*)((_check_pointer(i0, 14648))+4) = i1;
  i1 = subclass;
  *(OOC_INT8*)((_check_pointer(i0, 14673))+5) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 14704))+16) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 14726))+20) = (-1);
  *(OOC_INT32*)((_check_pointer(i0, 14757))+12) = 0;
  return;
  ;
}

OOC_SSA__Result OOC_SSA__NewResult(OOC_SSA__Instr instr, OOC_INT8 _class, OOC_INT8 subclass) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA__Result.baseTypes[0]);
  i1 = (OOC_INT32)instr;
  i2 = _class;
  i3 = subclass;
  OOC_SSA__InitResult((OOC_SSA__Result)i0, (OOC_SSA__Instr)i1, i2, i3);
  return (OOC_SSA__Result)i0;
  ;
}

void OOC_SSA__ResultDesc_DeleteResult(OOC_SSA__Result res) {
  register OOC_INT32 i0,i1,i2;
  OOC_SSA__Result prev;

  i0 = (OOC_INT32)res;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15602))+8);
  prev = (OOC_SSA__Result)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 15626));
  i2 = i2!=i0;
  if (!i2) goto l9;
l4_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 15667));
  prev = (OOC_SSA__Result)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 15626));
  i2 = i2!=i0;
  if (i2) goto l4_loop;
l9:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 15716));
  *(OOC_INT32*)(_check_pointer(i1, 15697)) = i0;
  return;
  ;
}

void OOC_SSA__ResultDesc_ReplaceUses(OOC_SSA__Result res, OOC_SSA__Result with) {
  register OOC_INT32 i0,i1,i2;
  OOC_SSA__Opnd use;
  OOC_SSA__Opnd nextUse;

  i0 = (OOC_INT32)res;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15916))+12);
  use = (OOC_SSA__Opnd)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l8;
  i1 = (OOC_INT32)with;
  
l3_loop:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15972))+16);
  nextUse = (OOC_SSA__Opnd)i2;
  OOC_SSA__DeleteUse((OOC_SSA__Opnd)i0);
  OOC_SSA__SetUse((OOC_SSA__Result)i1, (OOC_SSA__Opnd)i0);
  use = (OOC_SSA__Opnd)i2;
  i0 = i2!=(OOC_INT32)0;
  if (!i0) goto l8;
  i0=i2;
  goto l3_loop;
l8:
  return;
  ;
}

OOC_INT32 OOC_SSA__ResultDesc_ResultIndex(OOC_SSA__Result result) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_INT32 i;
  OOC_SSA__Result ptr;

  i = 0;
  i0 = (OOC_INT32)result;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16490))+8);
  ptr = (OOC_SSA__Result)i1;
  i2 = i1!=i0;
  if (i2) goto l3;
  i0=0;
  goto l9;
l3:
  i2=i1;i1=0;
l4_loop:
  i1 = i1+1;
  i = i1;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 16558));
  ptr = (OOC_SSA__Result)i2;
  i3 = i2!=i0;
  if (i3) goto l4_loop;
l8:
  i0=i1;
l9:
  return i0;
  ;
}

OOC_SymbolTable__ProcDecl OOC_SSA__ResultDesc_CalledProc(OOC_SSA__Result calledAdr) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)calledAdr;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16860))+8);
  i1 = *(OOC_INT8*)((_check_pointer(i1, 16866))+36);
  i1 = i1==3;
  if (i1) goto l7;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16975))+8);
  i1 = *(OOC_INT8*)((_check_pointer(i1, 16981))+36);
  i1 = i1==1;
  if (i1) goto l5;
  return (OOC_SymbolTable__ProcDecl)(OOC_INT32)0;
  goto l8;
l5:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17034))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17041)))), &_td_OOC_SSA__DeclRefDesc, 17041)), 17049))+44);
  return (OOC_SymbolTable__ProcDecl)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17059)))), &_td_OOC_SymbolTable__ProcDeclDesc, 17059));
  goto l8;
l7:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16919))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16926)))), &_td_OOC_SSA__AddressDesc, 16926)), 16934))+44);
  return (OOC_SymbolTable__ProcDecl)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16944)))), &_td_OOC_SymbolTable__ProcDeclDesc, 16944));
l8:
  _failed_function(16649); return 0;
  ;
}

OOC_CHAR8 OOC_SSA__ResultDesc_IsBooleanConst(OOC_SSA__Result result, OOC_CHAR8 value) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)result;
  _assert((OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17478)))), &_td_OOC_SSA__ConstDesc)), 127, 17463);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17508)))), &_td_OOC_SSA__ConstDesc, 17508)), 17514))+44);
  _assert((OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17521)))), &_td_Object_BigInt__BigIntDesc)), 127, 17493);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17559)))), &_td_OOC_SSA__ConstDesc, 17559)), 17565))+44);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17559)))), &_td_OOC_SSA__ConstDesc, 17559)), 17565))+44);
  i2 = (OOC_INT32)Object_BigInt__zero;
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17571)))), Object__ObjectDesc_Equals)),Object__ObjectDesc_Equals)((Object__Object)i0, (Object__Object)i2);
  i1 = value;
  return (i0!=i1);
  ;
}

void OOC_SSA__ResultDesc_LogId(OOC_SSA__Result result, const OOC_CHAR8 msg__ref[], OOC_LEN msg_0d) {
  register OOC_INT32 i0,i1,i2;
  OOC_ALLOCATE_VPAR(msg,OOC_CHAR8 ,msg_0d)
  OOC_INT32 i;

  OOC_INITIALIZE_VPAR(msg__ref,msg,OOC_CHAR8 ,msg_0d)
  i0 = (OOC_INT32)Log__writer;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17724)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (void*)(OOC_INT32)msg, msg_0d);
  i0 = (OOC_INT32)Log__writer;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17759)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, ": ", 3);
  i0 = (OOC_INT32)Log__writer;
  i1 = (OOC_INT32)result;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 17912))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17873)))), TextRider__WriterDesc_WriteHex)),TextRider__WriterDesc_WriteHex)((TextRider__Writer)i0, (_type_cast_fast(OOC_INT32, OOC_INT32, i2)), 8);
  i0 = OOC_SSA__ResultDesc_ResultIndex((OOC_SSA__Result)i1);
  i = i0;
  i1 = i0!=0;
  if (!i1) goto l4;
  i1 = (OOC_INT32)Log__writer;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 18002)))), TextRider__WriterDesc_WriteChar)),TextRider__WriterDesc_WriteChar)((TextRider__Writer)i1, 46u);
  i1 = (OOC_INT32)Log__writer;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 18037)))), TextRider__WriterDesc_WriteLInt)),TextRider__WriterDesc_WriteLInt)((TextRider__Writer)i1, i0, 0);
l4:
  i0 = (OOC_INT32)Log__writer;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18080)))), TextRider__WriterDesc_WriteLn)),TextRider__WriterDesc_WriteLn)((TextRider__Writer)i0);
  return;
  ;
}

static void OOC_SSA__InitInstr(OOC_SSA__Instr instr, OOC_INT8 opcode, OOC_INT8 subclass) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)instr;
  i1 = subclass;
  OOC_SSA__InitResult((OOC_SSA__Result)i0, (OOC_SSA__Instr)i0, (-1), i1);
  *(OOC_INT32*)((_check_pointer(i0, 18349))+24) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i0, 18377))+28) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i0, 18406))+32) = (OOC_INT32)0;
  i2 = opcode;
  *(OOC_INT8*)((_check_pointer(i0, 18435))+36) = i2;
  *(OOC_INT8*)((_check_pointer(i0, 18464))+5) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 18497))+40) = (-1);
  return;
  ;
}

void OOC_SSA__InstrDesc_SetSubclass(OOC_SSA__Instr instr, OOC_INT8 subclass) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)instr;
  i1 = subclass;
  *(OOC_INT8*)((_check_pointer(i0, 18682))+5) = i1;
  return;
  ;
}

void OOC_SSA__InstrDesc_SetPos(OOC_SSA__Instr instr, OOC_Scanner_SymList__Symbol sym) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)instr;
  i1 = (OOC_INT32)sym;
  i1 = *(OOC_INT32*)((_check_pointer(i1, 18806))+16);
  *(OOC_INT32*)((_check_pointer(i0, 18794))+40) = i1;
  return;
  ;
}

static void OOC_SSA__AddOpnd(OOC_SSA__Instr instr, OOC_SSA__Opnd opnd) {
  register OOC_INT32 i0,i1,i2;
  OOC_SSA__Opnd prev;

  i0 = (OOC_INT32)opnd;
  i1 = (OOC_INT32)instr;
  *(OOC_INT32*)((_check_pointer(i0, 19108))+12) = i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 19139))+24);
  i2 = i2==(OOC_INT32)0;
  if (i2) goto l12;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 19220))+24);
  prev = (OOC_SSA__Opnd)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 19249))+8);
  i2 = i2!=(OOC_INT32)0;
  if (!i2) goto l11;
l6_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 19290))+8);
  prev = (OOC_SSA__Opnd)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 19249))+8);
  i2 = i2!=(OOC_INT32)0;
  if (i2) goto l6_loop;
l11:
  *(OOC_INT32*)((_check_pointer(i1, 19322))+8) = i0;
  goto l13;
l12:
  *(OOC_INT32*)((_check_pointer(i1, 19173))+24) = i0;
l13:
  return;
  ;
}

void OOC_SSA__InstrDesc_AddOpnd(OOC_SSA__Instr instr, OOC_SSA__Result arg, OOC_INT8 _class) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)arg;
  i1 = _class;
  i0 = (OOC_INT32)OOC_SSA__NewOpnd((OOC_SSA__Result)i0, i1);
  i1 = (OOC_INT32)instr;
  OOC_SSA__AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Opnd)i0);
  return;
  ;
}

OOC_SSA__Opnd OOC_SSA__InstrDesc_AddOpndFct(OOC_SSA__Instr instr, OOC_SSA__Result arg, OOC_INT8 _class) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)arg;
  i1 = _class;
  i0 = (OOC_INT32)OOC_SSA__NewOpnd((OOC_SSA__Result)i0, i1);
  i1 = (OOC_INT32)instr;
  OOC_SSA__AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Opnd)i0);
  return (OOC_SSA__Opnd)i0;
  ;
}

void OOC_SSA__InstrDesc_AddUniqueOpnd(OOC_SSA__Instr instr, OOC_SSA__Result arg, OOC_INT8 _class) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_SSA__Opnd opnd;
  OOC_SSA__Opnd prev;

  i0 = (OOC_INT32)instr;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20291))+24);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l23;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20437))+24);
  prev = (OOC_SSA__Opnd)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 20466));
  i3 = (OOC_INT32)arg;
  i2 = i2!=i3;
  if (i2) goto l5;
  i2=0u;
  goto l7;
l5:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 20486))+8);
  i2 = i2!=(OOC_INT32)0;
  
l7:
  if (!i2) goto l19;
l10_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 20527))+8);
  prev = (OOC_SSA__Opnd)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 20466));
  i2 = i2!=i3;
  if (i2) goto l13;
  i2=0u;
  goto l15;
l13:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 20486))+8);
  i2 = i2!=(OOC_INT32)0;
  
l15:
  if (i2) goto l10_loop;
l19:
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 20563));
  i2 = i2!=i3;
  if (!i2) goto l24;
  i2 = _class;
  i2 = (OOC_INT32)OOC_SSA__NewOpnd((OOC_SSA__Result)i3, i2);
  opnd = (OOC_SSA__Opnd)i2;
  *(OOC_INT32*)((_check_pointer(i2, 20631))+12) = i0;
  *(OOC_INT32*)((_check_pointer(i1, 20661))+8) = i2;
  goto l24;
l23:
  i1 = _class;
  i2 = (OOC_INT32)arg;
  i1 = (OOC_INT32)OOC_SSA__NewOpnd((OOC_SSA__Result)i2, i1);
  opnd = (OOC_SSA__Opnd)i1;
  *(OOC_INT32*)((_check_pointer(i1, 20360))+12) = i0;
  *(OOC_INT32*)((_check_pointer(i0, 20389))+24) = i1;
l24:
  return;
  ;
}

void OOC_SSA__InstrDesc_AddTypedOpnd(OOC_SSA__Instr instr, OOC_SSA__Result arg, OOC_INT8 _class, OOC_SymbolTable__Type type, OOC_CHAR8 passByReference) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)arg;
  i1 = _class;
  i2 = (OOC_INT32)type;
  i3 = passByReference;
  i0 = (OOC_INT32)OOC_SSA__NewTypedOpnd((OOC_SSA__Result)i0, i1, (OOC_SymbolTable__Type)i2, i3);
  i1 = (OOC_INT32)instr;
  OOC_SSA__AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Opnd)i0);
  return;
  ;
}

OOC_SSA__Result OOC_SSA__InstrDesc_AddResultSubclass(OOC_SSA__Instr instr, OOC_INT8 _class, OOC_INT8 subclass) {
  register OOC_INT32 i0,i1,i2;
  OOC_SSA__Result res;
  OOC_SSA__Result prev;

  i0 = (OOC_INT32)instr;
  i1 = _class;
  i2 = subclass;
  i1 = (OOC_INT32)OOC_SSA__NewResult((OOC_SSA__Instr)i0, i1, i2);
  res = (OOC_SSA__Result)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 21513));
  i2 = i2==0;
  if (i2) goto l12;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 21597));
  prev = (OOC_SSA__Result)i0;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 21628));
  i2 = i2!=0;
  if (!i2) goto l11;
l6_loop:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 21671));
  prev = (OOC_SSA__Result)i0;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 21628));
  i2 = i2!=0;
  if (i2) goto l6_loop;
l11:
  *(OOC_INT32*)(_check_pointer(i0, 21705)) = i1;
  goto l13;
l12:
  *(OOC_INT32*)(_check_pointer(i0, 21549)) = i1;
l13:
  return (OOC_SSA__Result)i1;
  ;
}

OOC_SSA__Result OOC_SSA__InstrDesc_AddResult(OOC_SSA__Instr instr, OOC_INT8 _class) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)instr;
  i1 = _class;
  i0 = (OOC_INT32)OOC_SSA__InstrDesc_AddResultSubclass((OOC_SSA__Instr)i0, i1, 0);
  return (OOC_SSA__Result)i0;
  ;
}

OOC_INT32 OOC_SSA__InstrDesc_SizeOpndList(OOC_SSA__Instr instr) {
  register OOC_INT32 i0,i1,i2;
  OOC_INT32 num;
  OOC_SSA__Opnd opnd;

  num = 0;
  i0 = (OOC_INT32)instr;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22266))+24);
  opnd = (OOC_SSA__Opnd)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3;
  i0=0;
  goto l9;
l3:
  i1=i0;i0=0;
l4_loop:
  i0 = i0+1;
  num = i0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 22339))+8);
  opnd = (OOC_SSA__Opnd)i1;
  i2 = i1!=(OOC_INT32)0;
  if (i2) goto l4_loop;
l9:
  return i0;
  ;
}

OOC_INT32 OOC_SSA__InstrDesc_CountOpndClass(OOC_SSA__Instr instr, OOC_INT8 _class) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_INT32 num;
  OOC_SSA__Opnd opnd;

  num = 0;
  i0 = (OOC_INT32)instr;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22642))+24);
  opnd = (OOC_SSA__Opnd)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3;
  i0=0;
  goto l13;
l3:
  i1 = _class;
  i2=0;
l4_loop:
  i3 = *(OOC_INT8*)((_check_pointer(i0, 22694))+4);
  i3 = i3==i1;
  if (!i3) goto l8;
  i2 = i2+1;
  num = i2;
  
l8:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22764))+8);
  opnd = (OOC_SSA__Opnd)i0;
  i3 = i0!=(OOC_INT32)0;
  if (i3) goto l4_loop;
l12:
  i0=i2;
l13:
  return i0;
  ;
}

OOC_INT32 OOC_SSA__InstrDesc_SizeResultList(OOC_SSA__Instr instr) {
  register OOC_INT32 i0,i1,i2;
  OOC_INT32 num;
  OOC_SSA__Result res;

  i0 = (OOC_INT32)instr;
  res = (OOC_SSA__Result)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3;
  i0=0;
  goto l9;
l3:
  i1=i0;i0=0;
l4_loop:
  i0 = i0+1;
  num = i0;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 23175));
  res = (OOC_SSA__Result)i1;
  i2 = i1!=(OOC_INT32)0;
  if (i2) goto l4_loop;
l9:
  return i0;
  ;
}

OOC_SSA__Opnd OOC_SSA__InstrDesc_NthOpnd(OOC_SSA__Instr instr, OOC_INT32 nth) {
  register OOC_INT32 i0,i1,i2;
  OOC_SSA__Opnd opnd;

  i0 = (OOC_INT32)instr;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23489))+24);
  opnd = (OOC_SSA__Opnd)i0;
  i1 = nth;
  i2 = i1!=0;
  if (!i2) goto l9;
l4_loop:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23542))+8);
  opnd = (OOC_SSA__Opnd)i0;
  i1 = i1-1;
  nth = i1;
  i2 = i1!=0;
  if (i2) goto l4_loop;
l9:
  return (OOC_SSA__Opnd)i0;
  ;
}

OOC_SSA__Result OOC_SSA__InstrDesc_NthArg(OOC_SSA__Instr instr, OOC_INT32 nth) {
  register OOC_INT32 i0,i1,i2;
  OOC_SSA__Opnd opnd;

  i0 = (OOC_INT32)instr;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23879))+24);
  opnd = (OOC_SSA__Opnd)i0;
  i1 = nth;
  i2 = i1!=0;
  if (!i2) goto l9;
l4_loop:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23932))+8);
  opnd = (OOC_SSA__Opnd)i0;
  i1 = i1-1;
  nth = i1;
  i2 = i1!=0;
  if (i2) goto l4_loop;
l9:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 23984));
  return (OOC_SSA__Result)i0;
  ;
}

OOC_SSA__Opnd OOC_SSA__InstrDesc_LastOpnd(OOC_SSA__Instr instr) {
  register OOC_INT32 i0,i1;
  OOC_SSA__Opnd opnd;

  i0 = (OOC_INT32)instr;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24217))+24);
  opnd = (OOC_SSA__Opnd)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l13;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24271))+8);
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l13;
l7_loop:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24312))+8);
  opnd = (OOC_SSA__Opnd)i0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24271))+8);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l7_loop;
l13:
  return (OOC_SSA__Opnd)i0;
  ;
}

OOC_SSA__Opnd OOC_SSA__InstrDesc_GetOpndClass(OOC_SSA__Instr instr, OOC_INT8 _class) {
  register OOC_INT32 i0,i1,i2;
  OOC_SSA__Opnd opnd;

  i0 = (OOC_INT32)instr;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24649))+24);
  opnd = (OOC_SSA__Opnd)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = *(OOC_INT8*)((_check_pointer(i0, 24691))+4);
  i2 = _class;
  i1 = i1!=i2;
  
l5:
  if (!i1) goto l17;
  i1 = _class;
  
l8_loop:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24729))+8);
  opnd = (OOC_SSA__Opnd)i0;
  i2 = i0!=(OOC_INT32)0;
  if (i2) goto l11;
  i2=0u;
  goto l13;
l11:
  i2 = *(OOC_INT8*)((_check_pointer(i0, 24691))+4);
  i2 = i2!=i1;
  
l13:
  if (i2) goto l8_loop;
l17:
  return (OOC_SSA__Opnd)i0;
  ;
}

OOC_SSA__Result OOC_SSA__InstrDesc_GetArgClass(OOC_SSA__Instr instr, OOC_INT8 _class) {
  register OOC_INT32 i0,i1,i2;
  OOC_SSA__Opnd opnd;

  i0 = (OOC_INT32)instr;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25074))+24);
  opnd = (OOC_SSA__Opnd)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = *(OOC_INT8*)((_check_pointer(i0, 25116))+4);
  i2 = _class;
  i1 = i1!=i2;
  
l5:
  if (!i1) goto l17;
  i1 = _class;
  
l8_loop:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25154))+8);
  opnd = (OOC_SSA__Opnd)i0;
  i2 = i0!=(OOC_INT32)0;
  if (i2) goto l11;
  i2=0u;
  goto l13;
l11:
  i2 = *(OOC_INT8*)((_check_pointer(i0, 25116))+4);
  i2 = i2!=i1;
  
l13:
  if (i2) goto l8_loop;
l17:
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l20;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 25243));
  return (OOC_SSA__Result)i0;
  goto l21;
l20:
  return (OOC_SSA__Result)(OOC_INT32)0;
l21:
  _failed_function(24812); return 0;
  ;
}

OOC_SSA__Result OOC_SSA__InstrDesc_GetArgStore(OOC_SSA__Instr instr) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)instr;
  i0 = (OOC_INT32)OOC_SSA__InstrDesc_GetArgClass((OOC_SSA__Instr)i0, 2);
  return (OOC_SSA__Result)i0;
  ;
}

OOC_SSA__Result OOC_SSA__InstrDesc_NthResult(OOC_SSA__Instr instr, OOC_INT32 nth) {
  register OOC_INT32 i0,i1,i2;
  OOC_SSA__Result res;

  i0 = (OOC_INT32)instr;
  res = (OOC_SSA__Result)i0;
  i1 = nth;
  i2 = i1!=0;
  if (!i2) goto l9;
  
l4_loop:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 25820));
  res = (OOC_SSA__Result)i0;
  i1 = i1-1;
  nth = i1;
  i2 = i1!=0;
  if (i2) goto l4_loop;
l9:
  return (OOC_SSA__Result)i0;
  ;
}

OOC_SSA__Result OOC_SSA__InstrDesc_GetResultClass(OOC_SSA__Instr instr, OOC_INT8 _class) {
  register OOC_INT32 i0,i1,i2;
  OOC_SSA__Result result;

  i0 = (OOC_INT32)instr;
  result = (OOC_SSA__Result)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = *(OOC_INT8*)((_check_pointer(i0, 26220))+4);
  i2 = _class;
  i1 = i1!=i2;
  
l5:
  if (!i1) goto l17;
  i1 = _class;
  
l8_loop:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 26262));
  result = (OOC_SSA__Result)i0;
  i2 = i0!=(OOC_INT32)0;
  if (i2) goto l11;
  i2=0u;
  goto l13;
l11:
  i2 = *(OOC_INT8*)((_check_pointer(i0, 26220))+4);
  i2 = i2!=i1;
  
l13:
  if (i2) goto l8_loop;
l17:
  return (OOC_SSA__Result)i0;
  ;
}

OOC_SSA__Result OOC_SSA__InstrDesc_GetResultStore(OOC_SSA__Instr instr) {
  register OOC_INT32 i0,i1;
  OOC_SSA__Result result;

  i0 = (OOC_INT32)instr;
  result = (OOC_SSA__Result)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = *(OOC_INT8*)((_check_pointer(i0, 26514))+4);
  i1 = i1!=2;
  
l5:
  if (!i1) goto l17;
l8_loop:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 26568));
  result = (OOC_SSA__Result)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l11;
  i1=0u;
  goto l13;
l11:
  i1 = *(OOC_INT8*)((_check_pointer(i0, 26514))+4);
  i1 = i1!=2;
  
l13:
  if (i1) goto l8_loop;
l17:
  return (OOC_SSA__Result)i0;
  ;
}

void OOC_SSA__InstrDesc_GetOpcodeName(OOC_SSA__Instr instr, OOC_CHAR8 name[], OOC_LEN name_0d) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)instr;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 26911))+36);
  i0 = *(OOC_INT8*)((_check_pointer(i0, 26926))+5);
  OOC_SSA_Opcode__GetName(i1, i0, (void*)(OOC_INT32)name, name_0d);
  return;
  ;
}

OOC_INT8 OOC_SSA__InstrDesc_GetResultType(OOC_SSA__Instr instr) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)instr;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 27050))+36);
  switch (i1) {
  case 13:
    return 0;
    goto l4;
  default:
    i0 = *(OOC_INT8*)((_check_pointer(i0, 27299))+5);
    return i0;
    goto l4;
  }
l4:
  _failed_function(26992); return 0;
  ;
}

OOC_SSA__Instr OOC_SSA__InstrDesc_GetLoopEnd(OOC_SSA__Instr instr) {
  register OOC_INT32 i0,i1;
  OOC_SSA__Opnd use;
  OOC_SSA__Result res;

  i0 = (OOC_INT32)instr;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 27579))+36);
  switch (i1) {
  case 10:
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27633))+12);
    use = (OOC_SSA__Opnd)i0;
    goto l5;
  case 9:
    i0 = (OOC_INT32)OOC_SSA__InstrDesc_GetResultStore((OOC_SSA__Instr)i0);
    res = (OOC_SSA__Result)i0;
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27717))+12);
    use = (OOC_SSA__Opnd)i0;
    goto l5;
  default:
    _failed_case(i1, 27569);
    goto l5;
  }
l5:
  i0 = (OOC_INT32)use;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l8;
  i0=0u;
  goto l10;
l8:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27765))+12);
  i0 = *(OOC_INT8*)((_check_pointer(i0, 27772))+36);
  i0 = i0!=11;
  
l10:
  if (!i0) goto l21;
l12_loop:
  i0 = (OOC_INT32)use;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27818))+16);
  use = (OOC_SSA__Opnd)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l15;
  i0=0u;
  goto l17;
l15:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27765))+12);
  i0 = *(OOC_INT8*)((_check_pointer(i0, 27772))+36);
  i0 = i0!=11;
  
l17:
  if (i0) goto l12_loop;
l21:
  i0 = (OOC_INT32)use;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27852))+12);
  return (OOC_SSA__Instr)i0;
  ;
}

OOC_SSA__Result OOC_SSA__InstrDesc_GetBackwardFeed(OOC_SSA__Instr instr) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)instr;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 28134))+36);
  i1 = i1==10;
  if (!i1) goto l4;
  i0 = (OOC_INT32)OOC_SSA__InstrDesc_GetLoopEnd((OOC_SSA__Instr)i0);
  instr = (OOC_SSA__Instr)i0;
  
l4:
  i1 = *(OOC_INT8*)((_check_pointer(i0, 28230))+36);
  _assert((i1==11), 127, 28217);
  i0 = (OOC_INT32)OOC_SSA__InstrDesc_GetArgClass((OOC_SSA__Instr)i0, 13);
  return (OOC_SSA__Result)i0;
  ;
}

OOC_SSA__Instr OOC_SSA__InstrDesc_GetLoopStart(OOC_SSA__Instr instr) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)instr;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 28521))+36);
  _assert((i1==11), 127, 28508);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28565))+24);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 28575));
  return (OOC_SSA__Instr)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 28581)))), &_td_OOC_SSA__InstrDesc, 28581));
  ;
}

OOC_SSA__Instr OOC_SSA__InstrDesc_GetCollectTarget(OOC_SSA__Instr instr) {
  register OOC_INT32 i0,i1;
  OOC_SSA__Result storeOut;
  OOC_SSA__Opnd use;

  i0 = (OOC_INT32)instr;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 28831))+36);
  _assert((i1==6), 127, 28818);
  i0 = (OOC_INT32)OOC_SSA__InstrDesc_GetResultStore((OOC_SSA__Instr)i0);
  storeOut = (OOC_SSA__Result)i0;
  _assert((i0!=(OOC_INT32)0), 127, 28904);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28949))+12);
  _assert((i1!=(OOC_INT32)0), 127, 28933);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28987))+12);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 28996))+16);
  _assert((i1==(OOC_INT32)0), 127, 28971);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29030))+12);
  i1 = *(OOC_INT8*)((_check_pointer(i1, 29039))+4);
  i1 = i1==13;
  if (i1) goto l16;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29288))+12);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 29297))+12);
  i1 = *(OOC_INT8*)((_check_pointer(i1, 29304))+36);
  i1 = i1==9;
  if (i1) goto l5;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29698))+12);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29707))+12);
  return (OOC_SSA__Instr)i0;
  goto l17;
l5:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29482))+12);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29491))+12);
  i0 = (OOC_INT32)OOC_SSA__InstrDesc_GetResultStore((OOC_SSA__Instr)i0);
  storeOut = (OOC_SSA__Result)i0;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29539))+12);
  use = (OOC_SSA__Opnd)i0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29566))+12);
  i1 = *(OOC_INT8*)((_check_pointer(i1, 29573))+36);
  i1 = i1!=11;
  if (!i1) goto l14;
l9_loop:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29621))+16);
  use = (OOC_SSA__Opnd)i0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29566))+12);
  i1 = *(OOC_INT8*)((_check_pointer(i1, 29573))+36);
  i1 = i1!=11;
  if (i1) goto l9_loop;
l14:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29659))+12);
  return (OOC_SSA__Instr)i0;
  goto l17;
l16:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29235))+12);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29244))+12);
  i0 = (OOC_INT32)OOC_SSA__InstrDesc_GetLoopStart((OOC_SSA__Instr)i0);
  return (OOC_SSA__Instr)i0;
l17:
  _failed_function(28635); return 0;
  ;
}

OOC_INT32 OOC_SSA__InstrDesc_NumberOfPaths(OOC_SSA__Instr select) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)select;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 30021))+36);
  switch (i1) {
  case 5:
    i1 = (OOC_INT32)OOC_SSA__InstrDesc_GetOpndClass((OOC_SSA__Instr)i0, 16);
    i1 = i1==(OOC_INT32)0;
    if (i1) goto l5;
    i0 = OOC_SSA__InstrDesc_CountOpndClass((OOC_SSA__Instr)i0, 16);
    return i0;
    goto l10;
l5:
    i0 = OOC_SSA__InstrDesc_CountOpndClass((OOC_SSA__Instr)i0, 1);
    return (i0>>1);
    goto l10;
  case 10:
    return 2;
    goto l10;
  case 11:
    i0 = OOC_SSA__InstrDesc_CountOpndClass((OOC_SSA__Instr)i0, 11);
    return i0;
    goto l10;
  default:
    _failed_case(i1, 30010);
    goto l10;
  }
l10:
  _failed_function(29776); return 0;
  ;
}

OOC_SSA__Instr OOC_SSA__InstrDesc_GetCollect(OOC_SSA__Instr select, OOC_SSA__ProcBlock pb, OOC_INT32 pathNum) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_SSA__Opnd opnd;
  OOC_SSA__Instr loopEnd;
  OOC_SSA__Instr collect;

  i0 = (OOC_INT32)select;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 31038))+36);
  switch (i1) {
  case 5:
    i1 = pathNum;
    i0 = (OOC_INT32)OOC_SSA__InstrDesc_NthOpnd((OOC_SSA__Instr)i0, (2+i1*2));
    opnd = (OOC_SSA__Opnd)i0;
    goto l10;
  case 11:
    i1 = pathNum;
    i0 = (OOC_INT32)OOC_SSA__InstrDesc_NthOpnd((OOC_SSA__Instr)i0, (i1+2));
    opnd = (OOC_SSA__Opnd)i0;
    i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 31244));
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 31248))+8);
    i1 = *(OOC_INT8*)((_check_pointer(i1, 31254))+36);
    _assert((i1==9), 127, 31233);
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 31296));
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31300))+8);
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31306))+24);
    opnd = (OOC_SSA__Opnd)i0;
    goto l10;
  case 10:
    i1 = pathNum;
    i2 = i1==0;
    if (i2) goto l7;
    i0 = (OOC_INT32)OOC_SSA__InstrDesc_GetLoopEnd((OOC_SSA__Instr)i0);
    loopEnd = (OOC_SSA__Instr)i0;
    i0 = (OOC_INT32)OOC_SSA__InstrDesc_GetOpndClass((OOC_SSA__Instr)i0, 13);
    opnd = (OOC_SSA__Opnd)i0;
    
    goto l10;
l7:
    i0 = (OOC_INT32)OOC_SSA__InstrDesc_NthOpnd((OOC_SSA__Instr)i0, i1);
    opnd = (OOC_SSA__Opnd)i0;
    
    goto l10;
  default:
    _failed_case(i1, 31027);
    goto l10;
  }
l10:
  i0 = (OOC_INT32)opnd;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 31567));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 31571))+8);
  i1 = *(OOC_INT8*)((_check_pointer(i1, 31577))+36);
  i1 = i1==6;
  if (i1) goto l13;
  i1 = (OOC_INT32)pb;
  i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i1, 6, 0);
  collect = (OOC_SSA__Instr)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 31728));
  i3 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i1, 2);
  OOC_SSA__OpndDesc_ReplaceArg((OOC_SSA__Opnd)i0, (OOC_SSA__Result)i3);
  OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i2, 2);
  return (OOC_SSA__Instr)i1;
  goto l14;
l13:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 31625));
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31629))+8);
  return (OOC_SSA__Instr)i0;
l14:
  _failed_function(30566); return 0;
  ;
}

void OOC_SSA__InstrDesc_LogOpcode(OOC_SSA__Instr instr, const OOC_CHAR8 msg__ref[], OOC_LEN msg_0d) {
  register OOC_INT32 i0;
  OOC_ALLOCATE_VPAR(msg,OOC_CHAR8 ,msg_0d)
  OOC_CHAR8 name[64];

  OOC_INITIALIZE_VPAR(msg__ref,msg,OOC_CHAR8 ,msg_0d)
  i0 = (OOC_INT32)instr;
  OOC_SSA__InstrDesc_GetOpcodeName((OOC_SSA__Instr)i0, (void*)(OOC_INT32)name, 64);
  Log__String((void*)(OOC_INT32)msg, msg_0d, (void*)(OOC_INT32)name, 64);
  return;
  ;
}

OOC_CHAR8 OOC_SSA__InstrDesc_IsConst(OOC_SSA__Instr instr) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)instr;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 32417))+36);
  i1 = i1==57;
  if (i1) goto l3;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32469)))), &_td_OOC_SSA__ConstDesc);
  
  goto l5;
l3:
  i1=1u;
l5:
  if (i1) goto l7;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32489)))), &_td_OOC_SSA__DeclRefDesc);
  
  goto l9;
l7:
  i1=1u;
l9:
  if (i1) goto l11;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32519)))), &_td_OOC_SSA__TypeRefDesc);
  
  goto l13;
l11:
  i1=1u;
l13:
  if (i1) goto l15;
  i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32541)))), &_td_OOC_SSA__AddressDesc);
  
  goto l16;
l15:
  i0=1u;
l16:
  return i0;
  ;
}

OOC_CHAR8 OOC_SSA__InstrDesc_UniqueResult(OOC_SSA__Instr instr) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)instr;
  i0 = *(OOC_INT8*)((_check_pointer(i0, 32877))+36);
  switch (i0) {
  case 59:
  case 9:
  case 7:
    return 1u;
    goto l4;
  default:
    return 0u;
    goto l4;
  }
l4:
  _failed_function(32595); return 0;
  ;
}

OOC_CHAR8 OOC_SSA__InstrDesc_IsSync(OOC_SSA__Instr instr) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)instr;
  i0 = *(OOC_INT8*)((_check_pointer(i0, 33478))+36);
  switch (i0) {
  case 7:
  case 9:
  case 12:
  case 59:
  case 64:
  case 65:
  case 66:
  case 67:
  case 68:
  case 69:
  case 70:
  case 71:
    return 1u;
    goto l4;
  default:
    return 0u;
    goto l4;
  }
l4:
  _failed_function(33064); return 0;
  ;
}

OOC_CHAR8 OOC_SSA__InstrDesc_IsSwitchStatm(OOC_SSA__Instr instr) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)instr;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 34077))+36);
  _assert((i1==5), 127, 34064);
  i1 = (OOC_INT32)OOC_SSA__InstrDesc_GetOpndClass((OOC_SSA__Instr)i0, 16);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l3;
  i0 = OOC_SSA__InstrDesc_CountOpndClass((OOC_SSA__Instr)i0, 1);
  i0 = i0<4;
  
  goto l4;
l3:
  i0=1u;
l4:
  return i0;
  ;
}

static void OOC_SSA__InitConst(OOC_SSA__Const _const, OOC_INT8 subclass, Object_Boxed__Object value, OOC_SymbolTable__Type stringType) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)_const;
  i1 = subclass;
  OOC_SSA__InitInstr((OOC_SSA__Instr)i0, 0, i1);
  i1 = (OOC_INT32)value;
  _assert((i1!=(OOC_INT32)0), 127, 34646);
  *(OOC_INT32*)((_check_pointer(i0, 34677))+44) = i1;
  i1 = (OOC_INT32)stringType;
  *(OOC_INT32*)((_check_pointer(i0, 34704))+48) = i1;
  return;
  ;
}

static void OOC_SSA__InitDeclRef(OOC_SSA__DeclRef declRef, OOC_SymbolTable__Declaration decl) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)declRef;
  OOC_SSA__InitInstr((OOC_SSA__Instr)i0, 1, 0);
  i1 = (OOC_INT32)decl;
  *(OOC_INT32*)((_check_pointer(i0, 34890))+44) = i1;
  return;
  ;
}

static void OOC_SSA__InitTypeRef(OOC_SSA__TypeRef typeRef, OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)typeRef;
  OOC_SSA__InitInstr((OOC_SSA__Instr)i0, 2, 0);
  i1 = (OOC_INT32)type;
  *(OOC_INT32*)((_check_pointer(i0, 35059))+44) = i1;
  return;
  ;
}

static void OOC_SSA__InitAddress(OOC_SSA__Address address, OOC_INT8 opcode, OOC_SymbolTable__Declaration decl) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)address;
  i1 = opcode;
  OOC_SSA__InitInstr((OOC_SSA__Instr)i0, i1, 9);
  i1 = (OOC_INT32)decl;
  *(OOC_INT32*)((_check_pointer(i0, 35275))+44) = i1;
  return;
  ;
}

static OOC_SSA__Address OOC_SSA__NewAddress(OOC_INT8 opcode, OOC_SymbolTable__Declaration decl) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA__Address.baseTypes[0]);
  i1 = opcode;
  i2 = (OOC_INT32)decl;
  OOC_SSA__InitAddress((OOC_SSA__Address)i0, i1, (OOC_SymbolTable__Declaration)i2);
  return (OOC_SSA__Address)i0;
  ;
}

static void OOC_SSA__InitProcBlock(OOC_SSA__ProcBlock pb, OOC_SymbolTable__ProcDecl procDecl, OOC_CHAR8 checkFunctionResult) {
  register OOC_INT32 i0,i1,i2;
  OOC_SSA__Instr enter;
  OOC_SSA__Result initialStore;
  OOC_INT32 i;

  i0 = (OOC_INT32)pb;
  OOC_SSA__InitNode((OOC_SSA__Node)i0);
  *(OOC_INT32*)((_check_pointer(i0, 35821))+12) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i0, 35847))+16) = (OOC_INT32)0;
  i1 = (OOC_INT32)procDecl;
  *(OOC_INT32*)((_check_pointer(i0, 35873))+20) = i1;
  i1 = checkFunctionResult;
  *(OOC_UINT8*)((_check_pointer(i0, 35903))+24) = i1;
  i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i0, 8, 0);
  *(OOC_INT32*)(_check_pointer(i0, 35960)) = i1;
  i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i0, 4, 0);
  enter = (OOC_SSA__Instr)i1;
  i1 = (OOC_INT32)OOC_SSA__InstrDesc_AddResult((OOC_SSA__Instr)i1, 2);
  initialStore = (OOC_SSA__Result)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 36150));
  OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i1, 10);
  *(OOC_INT32*)((_check_pointer(i0, 36223))+4) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i0, 36251))+8) = (OOC_INT32)0;
  i = 0;
  i1=0;
l1_loop:
  *(OOC_INT32*)(((_check_pointer(i0, 36320))+28)+(_check_index(i1, 12, OOC_UINT32, 36330))*4) = (OOC_INT32)0;
  i1 = i1+1;
  i = i1;
  i2 = i1<=11;
  if (i2) goto l1_loop;
l5:
  i1 = (OOC_INT32)ADT_Dictionary__New();
  *(OOC_INT32*)((_check_pointer(i0, 36357))+76) = i1;
  i1 = (OOC_INT32)ADT_Dictionary__New();
  *(OOC_INT32*)((_check_pointer(i0, 36393))+80) = i1;
  return;
  ;
}

OOC_SSA__ProcBlock OOC_SSA__NewProcBlock(OOC_IR__Procedure proc) {
  register OOC_INT32 i0,i1,i2;
  OOC_SSA__ProcBlock pb;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA__ProcBlock.baseTypes[0]);
  pb = (OOC_SSA__ProcBlock)i0;
  i1 = (OOC_INT32)proc;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 36628))+4);
  i1 = *(OOC_UINT8*)((_check_pointer(i1, 36640))+12);
  OOC_SSA__InitProcBlock((OOC_SSA__ProcBlock)i0, (OOC_SymbolTable__ProcDecl)i2, i1);
  return (OOC_SSA__ProcBlock)i0;
  ;
}

static void OOC_SSA__AppendInstr(OOC_SSA__ProcBlock pb, OOC_SSA__Instr instr) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)instr;
  *(OOC_INT32*)((_check_pointer(i0, 36826))+28) = (OOC_INT32)0;
  i1 = (OOC_INT32)pb;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 36872))+16);
  *(OOC_INT32*)((_check_pointer(i0, 36855))+32) = i2;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 36895))+12);
  i2 = i2==(OOC_INT32)0;
  if (i2) goto l3;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 37097))+16);
  *(OOC_INT32*)((_check_pointer(i2, 37108))+28) = i0;
  *(OOC_INT32*)((_check_pointer(i1, 37138))+16) = i0;
  goto l4;
l3:
  *(OOC_INT32*)((_check_pointer(i1, 36969))+12) = i0;
  *(OOC_INT32*)((_check_pointer(i1, 36999))+16) = i0;
l4:
  return;
  ;
}

OOC_SSA__Instr OOC_SSA__ProcBlockDesc_AddInstr(OOC_SSA__ProcBlock pb, OOC_INT8 opcode, OOC_INT8 subclass) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA__Instr.baseTypes[0]);
  i1 = opcode;
  i2 = subclass;
  OOC_SSA__InitInstr((OOC_SSA__Instr)i0, i1, i2);
  i1 = (OOC_INT32)pb;
  OOC_SSA__AppendInstr((OOC_SSA__ProcBlock)i1, (OOC_SSA__Instr)i0);
  return (OOC_SSA__Instr)i0;
  ;
}

void OOC_SSA__ProcBlockDesc_DeleteInstr(OOC_SSA__ProcBlock pb, OOC_SSA__Instr instr) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)instr;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 38210)))), &_td_OOC_SSA__AddressDesc);
  if (i1) goto l17;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 38274)))), &_td_OOC_SSA__ConstDesc);
  if (i1) goto l12;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 38403)))), &_td_OOC_SSA__DeclRefDesc);
  if (i1) goto l10;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 38467)))), &_td_OOC_SSA__TypeRefDesc);
  if (!i1) goto l18;
  i1 = (OOC_INT32)pb;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 38511))+44);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 38488))+76);
  ADT_Dictionary__DictionaryDesc_Delete((ADT_Dictionary__Dictionary)i1, (Object__Object)i2);
  goto l18;
l10:
  i1 = (OOC_INT32)pb;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 38447))+44);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 38424))+76);
  ADT_Dictionary__DictionaryDesc_Delete((ADT_Dictionary__Dictionary)i1, (Object__Object)i2);
  goto l18;
l12:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 38300))+48);
  i1 = i1==(OOC_INT32)0;
  if (!i1) goto l18;
  i1 = (OOC_INT32)pb;
  i2 = *(OOC_INT8*)((_check_pointer(i0, 38349))+5);
  i1 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i1, 38334))+28)+(_check_index(i2, 12, OOC_UINT8, 38343))*4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 38372))+44);
  ADT_Dictionary__DictionaryDesc_Delete((ADT_Dictionary__Dictionary)i1, (Object__Object)i2);
  goto l18;
l17:
  i1 = (OOC_INT32)pb;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 38231))+80);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 38254))+44);
  ADT_Dictionary__DictionaryDesc_Delete((ADT_Dictionary__Dictionary)i1, (Object__Object)i2);
l18:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 38646))+24);
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l26;
l21_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 38678))+24);
  OOC_SSA__OpndDesc_DeleteOpnd((OOC_SSA__Opnd)i1);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 38646))+24);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l21_loop;
l26:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 38727))+32);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l29;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 38811))+32);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 38842))+28);
  *(OOC_INT32*)((_check_pointer(i1, 38822))+28) = i2;
  goto l30;
l29:
  i1 = (OOC_INT32)pb;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 38779))+28);
  *(OOC_INT32*)((_check_pointer(i1, 38759))+12) = i2;
l30:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 38876))+28);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l33;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 38960))+28);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 38991))+32);
  *(OOC_INT32*)((_check_pointer(i1, 38971))+32) = i2;
  goto l34;
l33:
  i1 = (OOC_INT32)pb;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 38928))+32);
  *(OOC_INT32*)((_check_pointer(i1, 38908))+16) = i2;
l34:
  *(OOC_INT32*)((_check_pointer(i0, 39021))+28) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i0, 39050))+32) = (OOC_INT32)0;
  return;
  ;
}

OOC_SSA__Const OOC_SSA__ProcBlockDesc_GetConst(OOC_SSA__ProcBlock pb, Object_Boxed__Object value, OOC_INT8 subclass, OOC_SymbolTable__Type stringType) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  Object__Object obj;
  OOC_SSA__Const _const;

  i0 = (OOC_INT32)pb;
  i1 = subclass;
  i2 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i0, 40014))+28)+(_check_index(i1, 12, OOC_UINT8, 40024))*4);
  i2 = i2==(OOC_INT32)0;
  if (!i2) goto l3;
  i2 = (OOC_INT32)ADT_Dictionary__New();
  *(OOC_INT32*)(((_check_pointer(i0, 40055))+28)+(_check_index(i1, 12, OOC_UINT8, 40065))*4) = i2;
l3:
  i2 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i0, 40120))+28)+(_check_index(i1, 12, OOC_UINT8, 40129))*4);
  i3 = (OOC_INT32)value;
  i2 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i2, (Object__Object)i3);
  if (i2) goto l9;
  i2 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA__Const.baseTypes[0]);
  _const = (OOC_SSA__Const)i2;
  i4 = (OOC_INT32)stringType;
  OOC_SSA__InitConst((OOC_SSA__Const)i2, i1, (Object_Boxed__Object)i3, (OOC_SymbolTable__Type)i4);
  OOC_SSA__AppendInstr((OOC_SSA__ProcBlock)i0, (OOC_SSA__Instr)i2);
  i4 = i4==(OOC_INT32)0;
  if (!i4) goto l8;
  i0 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i0, 40503))+28)+(_check_index(i1, 12, OOC_UINT8, 40513))*4);
  ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i0, (Object__Object)i3, (Object__Object)i2);
l8:
  return (OOC_SSA__Const)i2;
  goto l10;
l9:
  i0 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i0, 40174))+28)+(_check_index(i1, 12, OOC_UINT8, 40184))*4);
  i0 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i0, (Object__Object)i3);
  obj = (Object__Object)i0;
  return (OOC_SSA__Const)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 40226)))), &_td_OOC_SSA__ConstDesc, 40226));
l10:
  _failed_function(39118); return 0;
  ;
}

OOC_SSA__Const OOC_SSA__ProcBlockDesc_GetConstInt(OOC_SSA__ProcBlock pb, OOC_INT32 _int) {
  register OOC_INT32 i0,i1,i2;

  i0 = _int;
  i0 = (OOC_INT32)Object_BigInt__NewInt(i0);
  i1 = (OOC_INT32)OOC_SymbolTable_Predef__SmallestIntType((Object_BigInt__BigInt)i0);
  i1 = OOC_SSA_Opcode__TypeToSubclass((OOC_SymbolTable__Type)i1);
  i2 = (OOC_INT32)pb;
  i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConst((OOC_SSA__ProcBlock)i2, (Object_Boxed__Object)i0, i1, (OOC_SymbolTable__Type)(OOC_INT32)0);
  return (OOC_SSA__Const)i0;
  ;
}

OOC_SSA__Const OOC_SSA__ProcBlockDesc_GetConstBool(OOC_SSA__ProcBlock pb, OOC_CHAR8 b) {
  register OOC_INT32 i0,i1;

  i0 = b;
  if (i0) goto l3;
  i0 = (OOC_INT32)Object_BigInt__zero;
  
  goto l4;
l3:
  i0 = (OOC_INT32)Object_BigInt__one;
  
l4:
  i1 = (OOC_INT32)pb;
  i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConst((OOC_SSA__ProcBlock)i1, (Object_Boxed__Object)i0, 5, (OOC_SymbolTable__Type)(OOC_INT32)0);
  return (OOC_SSA__Const)i0;
  ;
}

OOC_SSA__Const OOC_SSA__ProcBlockDesc_GetConstNil(OOC_SSA__ProcBlock pb) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(16);
  i1 = (OOC_INT32)OOC_SSA__nil;
  i0 = OOC_SSA_Opcode__TypeToSubclass((OOC_SymbolTable__Type)i0);
  i2 = (OOC_INT32)pb;
  i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConst((OOC_SSA__ProcBlock)i2, (Object_Boxed__Object)i1, i0, (OOC_SymbolTable__Type)(OOC_INT32)0);
  return (OOC_SSA__Const)i0;
  ;
}

OOC_SSA__DeclRef OOC_SSA__ProcBlockDesc_GetDeclRef(OOC_SSA__ProcBlock pb, OOC_SymbolTable__Declaration decl) {
  register OOC_INT32 i0,i1,i2;
  Object__Object obj;
  OOC_SSA__DeclRef declRef;

  i0 = (OOC_INT32)pb;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 41630))+76);
  i2 = (OOC_INT32)decl;
  i1 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i1, (Object__Object)i2);
  if (i1) goto l3;
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA__DeclRef.baseTypes[0]);
  declRef = (OOC_SSA__DeclRef)i1;
  OOC_SSA__InitDeclRef((OOC_SSA__DeclRef)i1, (OOC_SymbolTable__Declaration)i2);
  OOC_SSA__AppendInstr((OOC_SSA__ProcBlock)i0, (OOC_SSA__Instr)i1);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 41829))+76);
  ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i0, (Object__Object)i2, (Object__Object)i1);
  return (OOC_SSA__DeclRef)i1;
  goto l4;
l3:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 41674))+76);
  i0 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i0, (Object__Object)i2);
  obj = (Object__Object)i0;
  return (OOC_SSA__DeclRef)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 41713)))), &_td_OOC_SSA__DeclRefDesc, 41713));
l4:
  _failed_function(41369); return 0;
  ;
}

OOC_SSA__TypeRef OOC_SSA__ProcBlockDesc_GetTypeRef(OOC_SSA__ProcBlock pb, OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1,i2;
  Object__Object obj;
  OOC_SSA__TypeRef typeRef;

  i0 = (OOC_INT32)pb;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 42175))+76);
  i2 = (OOC_INT32)type;
  i1 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i1, (Object__Object)i2);
  if (i1) goto l3;
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA__TypeRef.baseTypes[0]);
  typeRef = (OOC_SSA__TypeRef)i1;
  OOC_SSA__InitTypeRef((OOC_SSA__TypeRef)i1, (OOC_SymbolTable__Type)i2);
  OOC_SSA__AppendInstr((OOC_SSA__ProcBlock)i0, (OOC_SSA__Instr)i1);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 42374))+76);
  ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i0, (Object__Object)i2, (Object__Object)i1);
  return (OOC_SSA__TypeRef)i1;
  goto l4;
l3:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 42219))+76);
  i0 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i0, (Object__Object)i2);
  obj = (Object__Object)i0;
  return (OOC_SSA__TypeRef)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 42258)))), &_td_OOC_SSA__TypeRefDesc, 42258));
l4:
  _failed_function(41935); return 0;
  ;
}

void OOC_SSA__ProcBlockDesc_SetAddress(OOC_SSA__ProcBlock pb, OOC_SymbolTable__Declaration decl, OOC_SSA__Address address) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)pb;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 42586))+80);
  i1 = (OOC_INT32)decl;
  i2 = (OOC_INT32)address;
  ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i0, (Object__Object)i1, (Object__Object)i2);
  return;
  ;
}

OOC_SSA__Address OOC_SSA__ProcBlockDesc_GetAddress(OOC_SSA__ProcBlock pb, OOC_SymbolTable__Declaration decl) {
  register OOC_INT32 i0,i1,i2;
  Object__Object obj;

  i0 = (OOC_INT32)pb;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 42923))+80);
  i2 = (OOC_INT32)decl;
  i1 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i1, (Object__Object)i2);
  if (i1) goto l3;
  i1 = (OOC_INT32)OOC_SSA__NewAddress(3, (OOC_SymbolTable__Declaration)i2);
  OOC_SSA__AppendInstr((OOC_SSA__ProcBlock)i0, (OOC_SSA__Instr)i1);
  OOC_SSA__ProcBlockDesc_SetAddress((OOC_SSA__ProcBlock)i0, (OOC_SymbolTable__Declaration)i2, (OOC_SSA__Address)i1);
  return (OOC_SSA__Address)i1;
  goto l4;
l3:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 42967))+80);
  i0 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i0, (Object__Object)i2);
  obj = (Object__Object)i0;
  return (OOC_SSA__Address)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 43006)))), &_td_OOC_SSA__AddressDesc, 43006));
l4:
  _failed_function(42662); return 0;
  ;
}

OOC_SSA__Address OOC_SSA__ProcBlockDesc_AddCopyParameter(OOC_SSA__ProcBlock pb, OOC_SymbolTable__VarDecl param, OOC_SSA__Result storeIn, OOC_SSA__Result length, OOC_SSA__Result size) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)param;
  i1 = (OOC_INT32)OOC_SSA__NewAddress(58, (OOC_SymbolTable__Declaration)i0);
  i2 = (OOC_INT32)storeIn;
  OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i2, 2);
  i2 = (OOC_INT32)length;
  OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i2, 1);
  i2 = (OOC_INT32)size;
  OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i2, 1);
  i2 = (OOC_INT32)pb;
  OOC_SSA__AppendInstr((OOC_SSA__ProcBlock)i2, (OOC_SSA__Instr)i1);
  OOC_SSA__ProcBlockDesc_SetAddress((OOC_SSA__ProcBlock)i2, (OOC_SymbolTable__Declaration)i0, (OOC_SSA__Address)i1);
  return (OOC_SSA__Address)i1;
  ;
}

void OOC_SSA__ProcBlockDesc_SetMarkers(OOC_SSA__ProcBlock pb, OOC_SSA__Node newInfo, OOC_INT32 newMarker) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_SSA__Instr instr;
  OOC_SSA__Result res;

  i0 = (OOC_INT32)pb;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 44262))+12);
  instr = (OOC_SSA__Instr)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l16;
  i2 = (OOC_INT32)newInfo;
  i3 = newMarker;
  
l3_loop:
  res = (OOC_SSA__Result)i0;
  if (!i1) goto l11;
  i1=i0;
l6_loop:
  *(OOC_INT32*)((_check_pointer(i1, 44360))+16) = i2;
  *(OOC_INT32*)((_check_pointer(i1, 44390))+20) = i3;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 44431));
  res = (OOC_SSA__Result)i1;
  i4 = i1!=(OOC_INT32)0;
  if (i4) goto l6_loop;
l11:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 44475))+28);
  instr = (OOC_SSA__Instr)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3_loop;
l16:
  return;
  ;
}

OOC_SSA__Instr OOC_SSA__ProcBlockDesc_AddSetInstr(OOC_SSA__ProcBlock pb, OOC_SSA__Instr get, OOC_SSA__Result sourceValue) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_SSA__Instr set;
  OOC_SSA__Opnd opnd;
  auto OOC_INT8 OOC_SSA__ProcBlockDesc_AddSetInstr_MapOpndClass(OOC_INT8 _class);
    
    OOC_INT8 OOC_SSA__ProcBlockDesc_AddSetInstr_MapOpndClass(OOC_INT8 _class) {
      register OOC_INT32 i0;

      i0 = _class;
      switch (i0) {
      case 4:
        return 6;
        goto l5;
      case 5:
        return 7;
        goto l5;
      default:
        return i0;
        goto l5;
      }
l5:
      _failed_function(44824); return 0;
      ;
    }


  i0 = (OOC_INT32)get;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 45113))+8);
  i1 = *(OOC_INT8*)((_check_pointer(i1, 45120))+36);
  _assert((i1==12), 127, 45102);
  i1 = *(OOC_INT8*)((_check_pointer(i0, 45184))+5);
  i2 = (OOC_INT32)pb;
  i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i2, 13, i1);
  set = (OOC_SSA__Instr)i1;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 45212))+24);
  opnd = (OOC_SSA__Opnd)i0;
  i2 = i0!=(OOC_INT32)0;
  if (!i2) goto l8;
l3_loop:
  i2 = *(OOC_INT8*)((_check_pointer(i0, 45299))+4);
  i2 = OOC_SSA__ProcBlockDesc_AddSetInstr_MapOpndClass(i2);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 45274));
  OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i3, i2);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 45328))+8);
  opnd = (OOC_SSA__Opnd)i0;
  i2 = i0!=(OOC_INT32)0;
  if (i2) goto l3_loop;
l8:
  i0 = (OOC_INT32)sourceValue;
  OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 8);
  return (OOC_SSA__Instr)i1;
  ;
}

OOC_SSA__Instr OOC_SSA__ProcBlockDesc_AddGetLengthInstr(OOC_SSA__ProcBlock pb, OOC_SSA__Instr get, OOC_INT32 dim, OOC_SymbolTable__Array dimType) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_SSA__Instr dimension;
  OOC_SSA__DeclRef paramRef;
  OOC_SSA__Instr getLength;
  OOC_INT8 opcode;
  OOC_SSA__Opnd opnd;
  auto OOC_SSA__DeclRef OOC_SSA__ProcBlockDesc_AddGetLengthInstr_VarParamArray(OOC_SSA__Instr get);
  auto OOC_SSA__Instr OOC_SSA__ProcBlockDesc_AddGetLengthInstr_ExistingGetLength(OOC_SSA__Instr varParam, OOC_SSA__Instr dimension);
    
    OOC_SSA__DeclRef OOC_SSA__ProcBlockDesc_AddGetLengthInstr_VarParamArray(OOC_SSA__Instr get) {
      register OOC_INT32 i0,i1;
      OOC_SSA__Opnd opnd;

      i0 = (OOC_INT32)get;
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_GetOpndClass((OOC_SSA__Instr)i0, 5);
      opnd = (OOC_SSA__Opnd)i0;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 46197))+8);
      i1 = i1==(OOC_INT32)0;
      if (i1) goto l3;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 46233))+8);
      i1 = *(OOC_INT8*)((_check_pointer(i1, 46243))+4);
      i1 = i1!=5;
      
      goto l5;
l3:
      i1=1u;
l5:
      if (i1) goto l7;
      i1=0u;
      goto l9;
l7:
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 46292));
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 46298)))), &_td_OOC_SSA__DeclRefDesc);
      
l9:
      if (i1) goto l11;
      i1=0u;
      goto l13;
l11:
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 46325));
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 46331)))), &_td_OOC_SSA__DeclRefDesc, 46331)), 46339))+44);
      i1 = *(OOC_UINT8*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 46350)))), &_td_OOC_SymbolTable__VarDeclDesc, 46350)), 46358))+56);
      
l13:
      if (i1) goto l15;
      return (OOC_SSA__DeclRef)(OOC_INT32)0;
      goto l16;
l15:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 46396));
      return (OOC_SSA__DeclRef)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 46402)))), &_td_OOC_SSA__DeclRefDesc, 46402));
l16:
      _failed_function(45923); return 0;
      ;
    }

    
    OOC_SSA__Instr OOC_SSA__ProcBlockDesc_AddGetLengthInstr_ExistingGetLength(OOC_SSA__Instr varParam, OOC_SSA__Instr dimension) {
      register OOC_INT32 i0,i1,i2;
      OOC_SSA__Opnd use;

      i0 = (OOC_INT32)varParam;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l18;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 46778))+12);
      use = (OOC_SSA__Opnd)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l18;
      i1 = (OOC_INT32)dimension;
      
l5_loop:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 46835))+12);
      i2 = *(OOC_INT8*)((_check_pointer(i2, 46842))+36);
      i2 = i2==57;
      if (i2) goto l8;
      i2=0u;
      goto l10;
l8:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 46895))+12);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 46902))+24);
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 46912));
      i2 = i2==i1;
      
l10:
      if (!i2) goto l12;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 46958))+12);
      return (OOC_SSA__Instr)i2;
l12:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 47002))+16);
      use = (OOC_SSA__Opnd)i0;
      i2 = i0!=(OOC_INT32)0;
      if (i2) goto l5_loop;
l18:
      return (OOC_SSA__Instr)(OOC_INT32)0;
      ;
    }


  i0 = (OOC_INT32)get;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 47108))+8);
  i1 = *(OOC_INT8*)((_check_pointer(i1, 47115))+36);
  _assert((i1==12), 127, 47097);
  i1 = (OOC_INT32)dimType;
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 47153))+40);
  if (i2) goto l3;
  i0 = *(OOC_INT32*)((_check_pointer(i1, 47940))+52);
  i1 = (OOC_INT32)pb;
  i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstInt((OOC_SSA__ProcBlock)i1, i0);
  return (OOC_SSA__Instr)i0;
  goto l24;
l3:
  i1 = dim;
  i2 = (OOC_INT32)pb;
  i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstInt((OOC_SSA__ProcBlock)i2, i1);
  dimension = (OOC_SSA__Instr)i1;
  i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddGetLengthInstr_VarParamArray((OOC_SSA__Instr)i0);
  paramRef = (OOC_SSA__DeclRef)i0;
  i1 = (OOC_INT32)dimension;
  i2 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddGetLengthInstr_ExistingGetLength((OOC_SSA__Instr)i0, (OOC_SSA__Instr)i1);
  i3 = i2==(OOC_INT32)0;
  if (i3) goto l6;
  i0=i2;
  goto l23;
l6:
  i0 = i0!=(OOC_INT32)0;
  if (i0) goto l9;
  opcode = 56;
  i0=56;
  goto l10;
l9:
  opcode = 57;
  i0=57;
l10:
  i2 = (OOC_INT32)pb;
  i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i2, i0, 3);
  getLength = (OOC_SSA__Instr)i0;
  i2 = (OOC_INT32)get;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 47569))+24);
  opnd = (OOC_SSA__Opnd)i2;
  i3 = i2!=(OOC_INT32)0;
  if (!i3) goto l23;
l13_loop:
  i3 = *(OOC_INT8*)((_check_pointer(i2, 47629))+4);
  i3 = i3==2;
  if (i3) goto l16;
  i3 = *(OOC_INT8*)((_check_pointer(i2, 47787))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 47776));
  OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i4, i3);
  goto l17;
l16:
  OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Result)i1, 15);
l17:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 47834))+8);
  opnd = (OOC_SSA__Opnd)i2;
  i3 = i2!=(OOC_INT32)0;
  if (i3) goto l13_loop;
l23:
  return (OOC_SSA__Instr)i0;
l24:
  _failed_function(45464); return 0;
  ;
}

OOC_SSA__Instr OOC_SSA__ProcBlockDesc_SetLoopContext(OOC_SSA__ProcBlock pb, OOC_SSA__Instr loopContext) {
  register OOC_INT32 i0,i1,i2;
  OOC_SSA__Instr old;

  i0 = (OOC_INT32)pb;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 48100))+4);
  old = (OOC_SSA__Instr)i1;
  i2 = (OOC_INT32)loopContext;
  *(OOC_INT32*)((_check_pointer(i0, 48121))+4) = i2;
  return (OOC_SSA__Instr)i1;
  ;
}

OOC_SSA__Instr OOC_SSA__ProcBlockDesc_SetTryContext(OOC_SSA__ProcBlock pb, OOC_SSA__Instr tryContext) {
  register OOC_INT32 i0,i1,i2;
  OOC_SSA__Instr old;

  i0 = (OOC_INT32)pb;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 48301))+8);
  old = (OOC_SSA__Instr)i1;
  i2 = (OOC_INT32)tryContext;
  *(OOC_INT32*)((_check_pointer(i0, 48321))+8) = i2;
  return (OOC_SSA__Instr)i1;
  ;
}

OOC_SSA__Result OOC_SSA__ProcBlockDesc_FixSubclass(OOC_SSA__ProcBlock pb, OOC_SSA__Result arg, OOC_INT8 subclass) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)arg;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 48727))+5);
  i2 = subclass;
  i1 = i1!=i2;
  if (i1) goto l3;
  return (OOC_SSA__Result)i0;
  goto l12;
l3:
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 48768)))), &_td_OOC_SSA__ConstDesc);
  if (i1) goto l6;
  i1=0u;
  goto l8;
l6:
  i1 = *(OOC_INT8*)((_check_pointer(i0, 48794))+5);
  i1 = (i1<10)==(i2<10);
  
l8:
  if (i1) goto l10;
  i1 = (OOC_INT32)pb;
  i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i1, 42, i2);
  OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0, 1);
  return (OOC_SSA__Result)i1;
  goto l12;
l10:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 48891)))), &_td_OOC_SSA__ConstDesc, 48891)), 48897))+44);
  i1 = (OOC_INT32)pb;
  i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConst((OOC_SSA__ProcBlock)i1, (Object_Boxed__Object)i0, i2, (OOC_SymbolTable__Type)(OOC_INT32)0);
  return (OOC_SSA__Result)i0;
l12:
  _failed_function(48412); return 0;
  ;
}

OOC_SSA__Instr OOC_SSA__ProcBlockDesc_FixSubclassInstr(OOC_SSA__ProcBlock pb, OOC_SSA__Instr instr, OOC_INT8 subclass) {
  register OOC_INT32 i0,i1,i2;
  OOC_SSA__Result res;

  i0 = (OOC_INT32)pb;
  i1 = (OOC_INT32)instr;
  i2 = subclass;
  i0 = (OOC_INT32)OOC_SSA__ProcBlockDesc_FixSubclass((OOC_SSA__ProcBlock)i0, (OOC_SSA__Result)i1, i2);
  res = (OOC_SSA__Result)i0;
  return (OOC_SSA__Instr)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 49350)))), &_td_OOC_SSA__InstrDesc, 49350));
  ;
}

static void OOC_SSA__Add(OOC_SSA__Instr *list, OOC_SSA__Instr instr) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)instr;
  *(OOC_INT32*)((_check_pointer(i0, 49448))+32) = (OOC_INT32)0;
  i1 = (OOC_INT32)*list;
  *(OOC_INT32*)((_check_pointer(i0, 49477))+28) = i1;
  i1 = (OOC_INT32)*list;
  i2 = i1!=(OOC_INT32)0;
  if (!i2) goto l4;
  *(OOC_INT32*)((_check_pointer(i1, 49533))+32) = i0;
l4:
  *list = (OOC_SSA__Instr)i0;
  return;
  ;
}

static void OOC_SSA__Remove(OOC_SSA__Instr *list, OOC_SSA__Instr instr) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)instr;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 49664))+32);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l3;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 49739))+32);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 49770))+28);
  *(OOC_INT32*)((_check_pointer(i1, 49750))+28) = i2;
  goto l4;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 49707))+28);
  *list = (OOC_SSA__Instr)i1;
l4:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 49804))+28);
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l7;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 49839))+28);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 49870))+32);
  *(OOC_INT32*)((_check_pointer(i1, 49850))+32) = i0;
l7:
  return;
  ;
}

OOC_CHAR8 OOC_SSA__ProcBlockDesc_TopSort(OOC_SSA__ProcBlock pb) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_SSA__Instr ready;
  OOC_SSA__Instr waiting;
  OOC_SSA__Instr instr;
  OOC_SSA__Instr next;
  OOC_INT32 opndCount;
  OOC_SSA__Result res;
  OOC_SSA__Opnd use;

  ready = (OOC_SSA__Instr)(OOC_INT32)0;
  waiting = (OOC_SSA__Instr)(OOC_INT32)0;
  i0 = (OOC_INT32)pb;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 50281))+12);
  instr = (OOC_SSA__Instr)i1;
  i2 = i1!=(OOC_INT32)0;
  if (!i2) goto l12;
l3_loop:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 50340))+28);
  next = (OOC_SSA__Instr)i2;
  i3 = OOC_SSA__InstrDesc_SizeOpndList((OOC_SSA__Instr)i1);
  opndCount = i3;
  *(OOC_INT32*)((_check_pointer(i1, 50407))+20) = i3;
  i3 = i3==0;
  if (i3) goto l6;
  OOC_SSA__Add((void*)(OOC_INT32)&waiting, (OOC_SSA__Instr)i1);
  goto l7;
l6:
  OOC_SSA__Add((void*)(OOC_INT32)&ready, (OOC_SSA__Instr)i1);
l7:
  instr = (OOC_SSA__Instr)i2;
  i1 = i2!=(OOC_INT32)0;
  if (!i1) goto l12;
  i1=i2;
  goto l3_loop;
l12:
  *(OOC_INT32*)((_check_pointer(i0, 50574))+12) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i0, 50600))+16) = (OOC_INT32)0;
  i1 = (OOC_INT32)ready;
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l39;
l15_loop:
  i1 = (OOC_INT32)ready;
  instr = (OOC_SSA__Instr)i1;
  OOC_SSA__Remove((void*)(OOC_INT32)&ready, (OOC_SSA__Instr)i1);
  OOC_SSA__AppendInstr((OOC_SSA__ProcBlock)i0, (OOC_SSA__Instr)i1);
  res = (OOC_SSA__Result)i1;
  i2 = i1!=(OOC_INT32)0;
  if (!i2) goto l34;
l18_loop:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 50907))+12);
  use = (OOC_SSA__Opnd)i2;
  i3 = i2!=(OOC_INT32)0;
  if (!i3) goto l29;
l21_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 50965))+12);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 50965))+12);
  i4 = *(OOC_INT32*)((_check_pointer(i4, 50972))+20);
  *(OOC_INT32*)((_check_pointer(i3, 50972))+20) = (i4-1);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 51000))+12);
  i3 = *(OOC_INT32*)((_check_pointer(i3, 51007))+20);
  i3 = i3==0;
  if (!i3) goto l24;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 51058))+12);
  OOC_SSA__Remove((void*)(OOC_INT32)&waiting, (OOC_SSA__Instr)i3);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 51095))+12);
  OOC_SSA__Add((void*)(OOC_INT32)&ready, (OOC_SSA__Instr)i3);
l24:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 51139))+16);
  use = (OOC_SSA__Opnd)i2;
  i3 = i2!=(OOC_INT32)0;
  if (i3) goto l21_loop;
l29:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 51180));
  res = (OOC_SSA__Result)i1;
  i2 = i1!=(OOC_INT32)0;
  if (i2) goto l18_loop;
l34:
  i1 = (OOC_INT32)ready;
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l15_loop;
l39:
  i0 = (OOC_INT32)waiting;
  return (i0==(OOC_INT32)0);
  ;
}

void OOC_SSA__ProcBlockDesc_Reverse(OOC_SSA__ProcBlock pb) {
  register OOC_INT32 i0,i1,i2;
  OOC_SSA__Instr newList;
  OOC_SSA__Instr instr;
  OOC_SSA__Instr next;

  newList = (OOC_SSA__Instr)(OOC_INT32)0;
  i0 = (OOC_INT32)pb;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 51438))+12);
  instr = (OOC_SSA__Instr)i1;
  i2 = i1!=(OOC_INT32)0;
  if (!i2) goto l8;
l3_loop:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 51497))+28);
  next = (OOC_SSA__Instr)i2;
  OOC_SSA__Add((void*)(OOC_INT32)&newList, (OOC_SSA__Instr)i1);
  instr = (OOC_SSA__Instr)i2;
  i1 = i2!=(OOC_INT32)0;
  if (!i1) goto l8;
  i1=i2;
  goto l3_loop;
l8:
  i1 = (OOC_INT32)newList;
  *(OOC_INT32*)((_check_pointer(i0, 51573))+12) = i1;
  return;
  ;
}

OOC_SSA__Instr OOC_SSA__ProcBlockDesc_GetEnter(OOC_SSA__ProcBlock pb) {
  register OOC_INT32 i0,i1;
  OOC_SSA__Instr instr;

  i0 = (OOC_INT32)pb;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 51706))+12);
  instr = (OOC_SSA__Instr)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = *(OOC_INT8*)((_check_pointer(i0, 51751))+36);
  i1 = i1!=4;
  
l5:
  if (!i1) goto l17;
l8_loop:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 51799))+28);
  instr = (OOC_SSA__Instr)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l11;
  i1=0u;
  goto l13;
l11:
  i1 = *(OOC_INT8*)((_check_pointer(i0, 51751))+36);
  i1 = i1!=4;
  
l13:
  if (i1) goto l8_loop;
l17:
  return (OOC_SSA__Instr)i0;
  ;
}

void OOC_SSA__ProcBlockDesc_Destroy(OOC_SSA__ProcBlock pb) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_SSA__Instr instr;
  OOC_SSA__Instr nextInstr;
  OOC_SSA__Opnd opnd;
  OOC_SSA__Opnd nextOpnd;
  OOC_SSA__Result res;
  OOC_SSA__Result nextResult;
  OOC_INT32 i;

  i0 = (OOC_INT32)pb;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 52137))+12);
  instr = (OOC_SSA__Instr)i1;
  i2 = i1!=(OOC_INT32)0;
  if (!i2) goto l27;
l3_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 52200))+28);
  nextInstr = (OOC_SSA__Instr)i3;
  i4 = *(OOC_INT8*)((_check_pointer(i1, 52227))+36);
  i4 = i4!=81;
  if (!i4) goto l22;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 52363))+24);
  opnd = (OOC_SSA__Opnd)i4;
  i5 = i4!=(OOC_INT32)0;
  if (!i5) goto l13;
l8_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 52430))+8);
  nextOpnd = (OOC_SSA__Opnd)i5;
  *(OOC_INT32*)(_check_pointer(i4, 52455)) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i4, 52482))+8) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i4, 52514))+12) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i4, 52543))+16) = (OOC_INT32)0;
  opnd = (OOC_SSA__Opnd)i5;
  i4 = i5!=(OOC_INT32)0;
  if (!i4) goto l13;
  i4=i5;
  goto l8_loop;
l13:
  res = (OOC_SSA__Result)i1;
  if (!i2) goto l21;
  i2=i1;
l16_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 52688));
  nextResult = (OOC_SSA__Result)i4;
  *(OOC_INT32*)(_check_pointer(i2, 52714)) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i2, 52747))+8) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i2, 52775))+12) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i2, 52805))+16) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i2, 52832))+20) = 0;
  res = (OOC_SSA__Result)i4;
  i2 = i4!=(OOC_INT32)0;
  if (!i2) goto l21;
  i2=i4;
  goto l16_loop;
l21:
  *(OOC_INT32*)((_check_pointer(i1, 52910))+24) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i1, 52941))+28) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i1, 52973))+32) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i1, 53005))+40) = 0;
l22:
  instr = (OOC_SSA__Instr)i3;
  i1 = i3!=(OOC_INT32)0;
  if (!i1) goto l27;
  i2=i1;i1=i3;
  goto l3_loop;
l27:
  *(OOC_INT32*)(_check_pointer(i0, 53073)) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i0, 53101))+4) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i0, 53128))+12) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i0, 53153))+16) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i0, 53178))+20) = (OOC_INT32)0;
  i = 0;
  i1=0;
l28_loop:
  i2 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i0, 53248))+28)+(_check_index(i1, 12, OOC_UINT32, 53257))*4);
  i2 = i2!=(OOC_INT32)0;
  if (!i2) goto l31;
  i2 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i0, 53283))+28)+(_check_index(i1, 12, OOC_UINT32, 53292))*4);
  ADT_Dictionary__DictionaryDesc_Destroy((ADT_Dictionary__Dictionary)i2);
  *(OOC_INT32*)(((_check_pointer(i0, 53309))+28)+(_check_index(i1, 12, OOC_UINT32, 53318))*4) = (OOC_INT32)0;
l31:
  i1 = i1+1;
  i = i1;
  i2 = i1<=11;
  if (i2) goto l28_loop;
l35:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53360))+76);
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l38;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53388))+76);
  ADT_Dictionary__DictionaryDesc_Destroy((ADT_Dictionary__Dictionary)i1);
  *(OOC_INT32*)((_check_pointer(i0, 53409))+76) = (OOC_INT32)0;
l38:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53444))+80);
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l41;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53472))+80);
  ADT_Dictionary__DictionaryDesc_Destroy((ADT_Dictionary__Dictionary)i1);
  *(OOC_INT32*)((_check_pointer(i0, 53493))+80) = (OOC_INT32)0;
l41:
  return;
  ;
}

void OOC_OOC_SSA_init(void) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)Object_BigInt__zero;
  i0 = (OOC_INT32)Object_BigInt__BigIntDesc_Add((Object_BigInt__BigInt)i0, (Object_BigInt__BigInt)i0);
  i1 = (OOC_INT32)Object_BigInt__zero;
  OOC_SSA__nil = (Object_BigInt__BigInt)i0;
  _assert((i0!=i1), 127, 53610);
  return;
  ;
}

/* --- */
