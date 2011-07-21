#include <OOC/SSA/Opcode.d>
#include <__oo2c.h>
#include <setjmp.h>

OOC_CHAR8 OOC_SSA_Opcode__IsSigned(OOC_INT8 subclass) {
  register OOC_INT32 i0,i1;

  i0 = subclass;
  i1 = 1<=i0;
  if (i1) goto l3;
  i0=0u;
  goto l4;
l3:
  i0 = i0<=4;
  
l4:
  return i0;
  ;
}

OOC_CHAR8 OOC_SSA_Opcode__IsUnsigned(OOC_INT8 subclass) {
  register OOC_INT32 i0,i1;

  i0 = subclass;
  i1 = 5<=i0;
  if (i1) goto l3;
  i0=0u;
  goto l4;
l3:
  i0 = i0<=8;
  
l4:
  return i0;
  ;
}

OOC_CHAR8 OOC_SSA_Opcode__ConvDiffersFromCast(OOC_INT8 from, OOC_INT8 to) {
  register OOC_INT32 i0,i1;

  i0 = from;
  i1 = to;
  return ((i0<10)!=(i1<10));
  ;
}

void OOC_SSA_Opcode__GetSubclassName(OOC_INT8 subclass, OOC_CHAR8 name[], OOC_LEN name_0d) {
  register OOC_INT32 i0;
  OOC_CHAR8 scstr[16];

  i0 = subclass;
  switch (i0) {
  case 0:
    _copy_8((const void*)"none",(void*)(OOC_INT32)scstr,16);
    goto l15;
  case 1:
    _copy_8((const void*)"i8",(void*)(OOC_INT32)scstr,16);
    goto l15;
  case 2:
    _copy_8((const void*)"i16",(void*)(OOC_INT32)scstr,16);
    goto l15;
  case 3:
    _copy_8((const void*)"i32",(void*)(OOC_INT32)scstr,16);
    goto l15;
  case 4:
    _copy_8((const void*)"i64",(void*)(OOC_INT32)scstr,16);
    goto l15;
  case 5:
    _copy_8((const void*)"u8",(void*)(OOC_INT32)scstr,16);
    goto l15;
  case 6:
    _copy_8((const void*)"u16",(void*)(OOC_INT32)scstr,16);
    goto l15;
  case 7:
    _copy_8((const void*)"u32",(void*)(OOC_INT32)scstr,16);
    goto l15;
  case 8:
    _copy_8((const void*)"u64",(void*)(OOC_INT32)scstr,16);
    goto l15;
  case 9:
    _copy_8((const void*)"adr",(void*)(OOC_INT32)scstr,16);
    goto l15;
  case 10:
    _copy_8((const void*)"r32",(void*)(OOC_INT32)scstr,16);
    goto l15;
  case 11:
    _copy_8((const void*)"r64",(void*)(OOC_INT32)scstr,16);
    goto l15;
  default:
    _failed_case(i0, 34480);
    goto l15;
  }
l15:
  _copy_8((const void*)(OOC_INT32)scstr,(void*)(OOC_INT32)name,name_0d);
  return;
  ;
}

void OOC_SSA_Opcode__GetName(OOC_INT8 _class, OOC_INT8 subclass, OOC_CHAR8 name[], OOC_LEN name_0d) {
  register OOC_INT32 i0,i1;
  OOC_CHAR8 cstr[32];
  OOC_CHAR8 scstr[32];

  i0 = _class;
  switch (i0) {
  case 0:
    _copy_8((const void*)"const",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 1:
    _copy_8((const void*)"declref",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 2:
    _copy_8((const void*)"typeref",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 3:
    _copy_8((const void*)"address",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 4:
    _copy_8((const void*)"enter",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 5:
    _copy_8((const void*)"select",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 6:
    _copy_8((const void*)"collect",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 82:
    _copy_8((const void*)"labels",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 7:
    _copy_8((const void*)"return",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 8:
    _copy_8((const void*)"select-return",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 9:
    _copy_8((const void*)"exit",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 10:
    _copy_8((const void*)"loop-start",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 11:
    _copy_8((const void*)"loop-end",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 12:
    _copy_8((const void*)"get",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 13:
    _copy_8((const void*)"set",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 14:
    _copy_8((const void*)"copy",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 15:
    _copy_8((const void*)"copy-string",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 16:
    _copy_8((const void*)"cmp-string",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 17:
    _copy_8((const void*)"concat",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 18:
    _copy_8((const void*)"move-block",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 56:
    _copy_8((const void*)"get-length-heap",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 57:
    _copy_8((const void*)"get-length-param",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 58:
    _copy_8((const void*)"copy-parameter",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 59:
    _copy_8((const void*)"new-object",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 60:
    _copy_8((const void*)"new-block",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 61:
    _copy_8((const void*)"type-tag",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 62:
    _copy_8((const void*)"type-test",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 63:
    _copy_8((const void*)"tb-proc-address",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 19:
    _copy_8((const void*)"add",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 20:
    _copy_8((const void*)"subtract",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 21:
    _copy_8((const void*)"negate",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 22:
    _copy_8((const void*)"multiply",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 23:
    _copy_8((const void*)"divide",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 24:
    _copy_8((const void*)"modulo",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 25:
    _copy_8((const void*)"eql",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 26:
    _copy_8((const void*)"neq",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 27:
    _copy_8((const void*)"lss",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 28:
    _copy_8((const void*)"leq",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 29:
    _copy_8((const void*)"gtr",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 30:
    _copy_8((const void*)"geq",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 31:
    _copy_8((const void*)"and",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 32:
    _copy_8((const void*)"or",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 33:
    _copy_8((const void*)"not",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 34:
    _copy_8((const void*)"logical-and",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 35:
    _copy_8((const void*)"logical-or",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 36:
    _copy_8((const void*)"logical-xor",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 37:
    _copy_8((const void*)"logical-complement",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 38:
    _copy_8((const void*)"logical-subtr",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 39:
    _copy_8((const void*)"set-bit",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 40:
    _copy_8((const void*)"clear-bit",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 41:
    _copy_8((const void*)"type-cast",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 42:
    _copy_8((const void*)"type-conv",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 43:
    _copy_8((const void*)"set-member",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 44:
    _copy_8((const void*)"set-range",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 45:
    _copy_8((const void*)"abs",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 46:
    _copy_8((const void*)"shift-left",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 47:
    _copy_8((const void*)"shift-right",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 48:
    _copy_8((const void*)"ash",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 49:
    _copy_8((const void*)"cap",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 50:
    _copy_8((const void*)"entier",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 51:
    _copy_8((const void*)"indexed",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 52:
    _copy_8((const void*)"lsh",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 53:
    _copy_8((const void*)"rot",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 54:
    _copy_8((const void*)"odd",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 55:
    _copy_8((const void*)"call",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 64:
    _copy_8((const void*)"assert",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 65:
    _copy_8((const void*)"halt",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 66:
    _copy_8((const void*)"check-index",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 67:
    _copy_8((const void*)"check-pointer",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 68:
    _copy_8((const void*)"type-guard",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 69:
    _copy_8((const void*)"failed-case",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 70:
    _copy_8((const void*)"failed-with",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 71:
    _copy_8((const void*)"failed-type-assert",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 81:
    _copy_8((const void*)"preloaded-var",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 72:
    _copy_8((const void*)"try-start",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 73:
    _copy_8((const void*)"try-end",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 74:
    _copy_8((const void*)"raise-exception",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 76:
    _copy_8((const void*)"current-exception",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 77:
    _copy_8((const void*)"clear-exception",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 78:
    _copy_8((const void*)"push-exception-context",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 79:
    _copy_8((const void*)"pop-exception-context",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 80:
    _copy_8((const void*)"activate-context",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 83:
    _copy_8((const void*)"dgate",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 84:
    _copy_8((const void*)"design-standin",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 85:
    _copy_8((const void*)"equiv",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 86:
    _copy_8((const void*)"equiv-pre",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 87:
    _copy_8((const void*)"vtable-proc-address",(void*)(OOC_INT32)cstr,32);
    goto l91;
  case 88:
    _copy_8((const void*)"noop",(void*)(OOC_INT32)cstr,32);
    goto l91;
  default:
    _failed_case(i0, 35169);
    goto l91;
  }
l91:
  _copy_8((const void*)(OOC_INT32)cstr,(void*)(OOC_INT32)name,name_0d);
  i0 = subclass;
  i1 = i0!=0;
  if (!i1) goto l94;
  OOC_SSA_Opcode__GetSubclassName(i0, (void*)(OOC_INT32)scstr, 32);
  Strings__Append("-", 2, (void*)(OOC_INT32)name, name_0d);
  Strings__Append((void*)(OOC_INT32)scstr, 32, (void*)(OOC_INT32)name, name_0d);
l94:
  return;
  ;
}

OOC_INT8 OOC_SSA_Opcode__TypeToSubclass(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 38721)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  type = (OOC_SymbolTable__Type)i0;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 38746)))), &_td_OOC_SymbolTable__PredefTypeDesc);
  if (i1) goto l23;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 39523)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (i1) goto l21;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 39570)))), &_td_OOC_SymbolTable__RecordDesc);
  if (i1) goto l19;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 39618)))), &_td_OOC_SymbolTable__PointerDesc);
  if (i1) goto l17;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 39670)))), &_td_OOC_SymbolTable__FormalParsDesc);
  if (i1) goto l15;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 39725)))), &_td_OOC_SymbolTable__TypeVarDesc);
  if (i1) goto l13;
  Log__Type("++ Unknown type in TypeToSubclass", 34, (void*)i0);
  _assert(0u, 127, 39865);
  goto l43;
l13:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 39774))+40);
  i0 = OOC_SSA_Opcode__TypeToSubclass((OOC_SymbolTable__Type)i0);
  return i0;
  goto l43;
l15:
  return 9;
  goto l43;
l17:
  return 9;
  goto l43;
l19:
  return 0;
  goto l43;
l21:
  return 0;
  goto l43;
l23:
  i0 = *(OOC_INT16*)((_check_pointer(i0, 38781))+40);
  switch (i0) {
  case 17:
    return 0;
    goto l43;
  case 1:
    return 5;
    goto l43;
  case 2:
    return 6;
    goto l43;
  case 3:
    return 7;
    goto l43;
  case 0:
    return 5;
    goto l43;
  case 4:
    return 1;
    goto l43;
  case 5:
    return 2;
    goto l43;
  case 6:
    return 3;
    goto l43;
  case 7:
    return 4;
    goto l43;
  case 8:
    return 10;
    goto l43;
  case 9:
    return 11;
    goto l43;
  case 10:
    return 7;
    goto l43;
  case 11:
    return 5;
    goto l43;
  case 12:
    return 9;
    goto l43;
  case 13:
  case 14:
  case 15:
    return 9;
    goto l43;
  case 16:
    return 9;
    goto l43;
  default:
    _failed_case(i0, 38772);
    goto l43;
  }
l43:
  _failed_function(38653); return 0;
  ;
}

void OOC_OOC_SSA_Opcode_init(void) {

  return;
  ;
}

/* --- */
