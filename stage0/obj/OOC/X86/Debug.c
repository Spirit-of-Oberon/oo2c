#include <OOC/X86/Debug.d>
#include <__oo2c.h>
#include <setjmp.h>

void OOC_X86_Debug__OutputDesc_INIT(OOC_X86_Debug__Output out, OOC_X86_SSA__Block b, Object__String name) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)out;
  i1 = (OOC_INT32)b;
  *(OOC_INT32*)(_check_pointer(i0, 877)) = i1;
  i1 = (OOC_INT32)name;
  *(OOC_INT32*)((_check_pointer(i0, 893))+4) = i1;
  i1 = (OOC_INT32)RT0__NewObject(_td__qtd1.baseTypes[0]);
  ADT_Dictionary__DictionaryDesc_INIT((ADT_Dictionary__Dictionary)i1);
  *(OOC_INT32*)((_check_pointer(i0, 915))+8) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 980))+12) = 0;
  return;
  ;
}

void OOC_X86_Debug__StateDesc_INIT(OOC_X86_Debug__State s, OOC_X86_SSA__Block block) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)s;
  i1 = (OOC_INT32)block;
  *(OOC_INT32*)(_check_pointer(i0, 1067)) = i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 1104))+48);
  *(OOC_INT32*)((_check_pointer(i0, 1089))+4) = i2;
  *(OOC_INT32*)((_check_pointer(i0, 1121))+8) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 1147))+48) = (-1);
  *(OOC_INT32*)((_check_pointer(i0, 1171))+52) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 1191))+56) = 0;
  return;
  ;
}

OOC_X86_Debug__State OOC_X86_Debug__StateDesc_Copy(OOC_X86_Debug__State s) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_X86_Debug__State t;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_Debug__State.baseTypes[0]);
  t = (OOC_X86_Debug__State)i0;
  i1 = (OOC_INT32)s;
  i1 = _check_pointer(i1, 1306);
  i2 = _check_pointer(i0, 1300);
  i3 = (OOC_INT32)&_td_OOC_X86_Debug__StateDesc;
  i3 = i3!=i3;
  if (!i3) goto l4;
  _failed_type_assert(1300);
l4:
  _copy_block(i1,i2,60);
  return (OOC_X86_Debug__State)i0;
  ;
}

static Object__String OOC_X86_Debug__Type(OOC_INT8 type) {
  register OOC_INT32 i0;

  i0 = type;
  switch (i0) {
  case 0:
    return (Object__String)((OOC_INT32)_c0);
    goto l15;
  case 1:
    return (Object__String)((OOC_INT32)_c1);
    goto l15;
  case 2:
    return (Object__String)((OOC_INT32)_c2);
    goto l15;
  case 3:
    return (Object__String)((OOC_INT32)_c3);
    goto l15;
  case 4:
    return (Object__String)((OOC_INT32)_c4);
    goto l15;
  case 5:
    return (Object__String)((OOC_INT32)_c5);
    goto l15;
  case 6:
    return (Object__String)((OOC_INT32)_c6);
    goto l15;
  case 7:
    return (Object__String)((OOC_INT32)_c7);
    goto l15;
  case 8:
    return (Object__String)((OOC_INT32)_c8);
    goto l15;
  case 9:
    return (Object__String)((OOC_INT32)_c9);
    goto l15;
  case 10:
    return (Object__String)((OOC_INT32)_c10);
    goto l15;
  case 11:
    return (Object__String)((OOC_INT32)_c11);
    goto l15;
  default:
    _failed_case(i0, 1386);
    goto l15;
  }
l15:
  _failed_function(1346); return 0;
  ;
}

Object__String OOC_X86_Debug__Opcode(OOC_X86_SSA__Instr instr) {
  register OOC_INT32 i0,i1;
  Object__String str;
  Object__String type;

  i0 = (OOC_INT32)instr;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 1893))+20);
  switch (i1) {
  case 0:
    str = (Object__String)((OOC_INT32)_c12);
    goto l51;
  case 1:
    str = (Object__String)((OOC_INT32)_c13);
    goto l51;
  case 2:
    str = (Object__String)((OOC_INT32)_c14);
    goto l51;
  case 3:
    str = (Object__String)((OOC_INT32)_c15);
    goto l51;
  case 4:
    str = (Object__String)((OOC_INT32)_c16);
    goto l51;
  case 5:
    str = (Object__String)((OOC_INT32)_c17);
    goto l51;
  case 6:
    str = (Object__String)((OOC_INT32)_c18);
    goto l51;
  case 7:
    str = (Object__String)((OOC_INT32)_c19);
    goto l51;
  case 8:
    str = (Object__String)((OOC_INT32)_c20);
    goto l51;
  case 9:
    str = (Object__String)((OOC_INT32)_c21);
    goto l51;
  case 10:
    str = (Object__String)((OOC_INT32)_c22);
    goto l51;
  case 11:
    str = (Object__String)((OOC_INT32)_c23);
    goto l51;
  case 12:
    str = (Object__String)((OOC_INT32)_c24);
    goto l51;
  case 13:
    str = (Object__String)((OOC_INT32)_c25);
    goto l51;
  case 14:
    str = (Object__String)((OOC_INT32)_c26);
    goto l51;
  case 15:
    str = (Object__String)((OOC_INT32)_c27);
    goto l51;
  case 16:
    str = (Object__String)((OOC_INT32)_c28);
    goto l51;
  case 17:
    str = (Object__String)((OOC_INT32)_c29);
    goto l51;
  case 18:
    str = (Object__String)((OOC_INT32)_c30);
    goto l51;
  case 19:
    str = (Object__String)((OOC_INT32)_c31);
    goto l51;
  case 20:
    str = (Object__String)((OOC_INT32)_c32);
    goto l51;
  case 21:
    str = (Object__String)((OOC_INT32)_c33);
    goto l51;
  case 22:
    str = (Object__String)((OOC_INT32)_c34);
    goto l51;
  case 23:
    str = (Object__String)((OOC_INT32)_c35);
    goto l51;
  case 24:
    str = (Object__String)((OOC_INT32)_c36);
    goto l51;
  case 25:
    str = (Object__String)((OOC_INT32)_c37);
    goto l51;
  case 26:
    str = (Object__String)((OOC_INT32)_c38);
    goto l51;
  case 27:
    str = (Object__String)((OOC_INT32)_c39);
    goto l51;
  case 28:
    str = (Object__String)((OOC_INT32)_c40);
    goto l51;
  case 29:
    str = (Object__String)((OOC_INT32)_c41);
    goto l51;
  case 30:
    str = (Object__String)((OOC_INT32)_c42);
    goto l51;
  case 31:
    str = (Object__String)((OOC_INT32)_c43);
    goto l51;
  case 32:
    str = (Object__String)((OOC_INT32)_c44);
    goto l51;
  case 33:
    str = (Object__String)((OOC_INT32)_c45);
    goto l51;
  case 34:
    str = (Object__String)((OOC_INT32)_c46);
    goto l51;
  case 35:
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3137)))), &_td_OOC_X86_SSA__MergeInstrDesc, 3137)), 3148))+56);
    i1 = i1!=(OOC_INT32)0;
    if (i1) goto l40;
    str = (Object__String)((OOC_INT32)_c47);
    
    goto l51;
l40:
    str = (Object__String)((OOC_INT32)_c48);
    
    goto l51;
  case 36:
    str = (Object__String)((OOC_INT32)_c49);
    goto l51;
  case 37:
    str = (Object__String)((OOC_INT32)_c50);
    goto l51;
  case 38:
    str = (Object__String)((OOC_INT32)_c51);
    goto l51;
  case 39:
    str = (Object__String)((OOC_INT32)_c52);
    goto l51;
  case 40:
    str = (Object__String)((OOC_INT32)_c53);
    goto l51;
  case 41:
    str = (Object__String)((OOC_INT32)_c54);
    goto l51;
  case 42:
    str = (Object__String)((OOC_INT32)_c55);
    goto l51;
  case 43:
    str = (Object__String)((OOC_INT32)_c56);
    goto l51;
  default:
    _failed_case(i1, 1883);
    goto l51;
  }
l51:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3563))+4);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l54;
  i1=0u;
  goto l56;
l54:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3590))+4);
  i1 = *(OOC_INT8*)((_check_pointer(i1, 3601))+12);
  i1 = i1!=0;
  
l56:
  if (i1) goto l58;
  i0 = (OOC_INT32)str;
  return (Object__String)i0;
  goto l63;
l58:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3648))+4);
  i1 = *(OOC_INT8*)((_check_pointer(i1, 3659))+12);
  i1 = (OOC_INT32)OOC_X86_Debug__Type(i1);
  type = (Object__String)i1;
  i0 = *(OOC_INT8*)((_check_pointer(i0, 3682))+20);
  i0 = i0==0;
  if (i0) goto l61;
  i0 = (OOC_INT32)str;
  return (Object__String)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)i0,(void*)((OOC_INT32)_c57))),(void*)i1));
  goto l63;
l61:
  return (Object__String)i1;
l63:
  _failed_function(1809); return 0;
  ;
}

Object__String OOC_X86_Debug__Register(OOC_INT8 reg) {
  register OOC_INT32 i0;

  i0 = reg;
  switch (i0) {
  case 0:
    return (Object__String)((OOC_INT32)_c58);
    goto l12;
  case 1:
    return (Object__String)((OOC_INT32)_c59);
    goto l12;
  case 2:
    return (Object__String)((OOC_INT32)_c60);
    goto l12;
  case 3:
    return (Object__String)((OOC_INT32)_c61);
    goto l12;
  case 4:
    return (Object__String)((OOC_INT32)_c62);
    goto l12;
  case 5:
    return (Object__String)((OOC_INT32)_c63);
    goto l12;
  case 6:
    return (Object__String)((OOC_INT32)_c64);
    goto l12;
  case 7:
    return (Object__String)((OOC_INT32)_c65);
    goto l12;
  case 8:
    return (Object__String)((OOC_INT32)_c66);
    goto l12;
  default:
    _failed_case(i0, 3887);
    goto l12;
  }
l12:
  _failed_function(3839); return 0;
  ;
}

Object__String OOC_X86_Debug__OutputDesc_GetInstrCode(OOC_X86_Debug__Output out, OOC_X86_SSA__Instr instr) {
  register OOC_INT32 i0,i1,i2;
  Object__String str;

  i0 = (OOC_INT32)out;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4265))+8);
  i2 = (OOC_INT32)instr;
  i1 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i1, (Object__Object)i2);
  if (i1) goto l3;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 4354))+12);
  *(OOC_INT32*)((_check_pointer(i0, 4354))+12) = (i1+1);
  i1 = *(OOC_INT32*)((_check_pointer(i0, 4401))+12);
  i1 = (OOC_INT32)Object_Boxed__IntToString(i1);
  str = (Object__String)i1;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4423))+8);
  ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i0, (Object__Object)i2, (Object__Object)i1);
  return (Object__String)i1;
  goto l4;
l3:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4310))+8);
  i0 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i0, (Object__Object)i2);
  return (Object__String)i0;
l4:
  _failed_function(4186); return 0;
  ;
}

Object__String OOC_X86_Debug__OutputDesc_Label(OOC_X86_Debug__Output out, OOC_X86_SSA__Node node) {
  register OOC_INT32 i0,i1,i2,i3;
  Object__String str;
  OOC_INT32 i;
  OOC_X86_SSA__Result res;
  auto Object__String OOC_X86_Debug__OutputDesc_Label_Location(OOC_X86_SSA__Result res);
    
    Object__String OOC_X86_Debug__OutputDesc_Label_Location(OOC_X86_SSA__Result res) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)res;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 4683))+14);
      switch (i1) {
      case 0:
        i0 = *(OOC_INT8*)((_check_pointer(i0, 4746))+13);
        i0 = (OOC_INT32)OOC_X86_Debug__Register(i0);
        return (Object__String)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c67),(void*)i0));
        goto l6;
      case 1:
        return (Object__String)((OOC_INT32)_c68);
        goto l6;
      case (-1):
        return (Object__String)((OOC_INT32)_c69);
        goto l6;
      default:
        _failed_case(i1, 4675);
        goto l6;
      }
l6:
      _failed_function(4626); return 0;
      ;
    }


  i0 = (OOC_INT32)node;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l28;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4956)))), &_td_OOC_X86_SSA__InstrDesc);
  if (i1) goto l26;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5044)))), &_td_OOC_X86_SSA__ResultDesc);
  if (i1) goto l11;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5570)))), &_td_OOC_X86_SSA__OpndDesc);
  if (i1) goto l9;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5564)))), 5564);
  goto l29;
l9:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5618))+8);
  i2 = (OOC_INT32)out;
  i1 = (OOC_INT32)OOC_X86_Debug__OutputDesc_GetInstrCode((OOC_X86_Debug__Output)i2, (OOC_X86_SSA__Instr)i1);
  i3 = OOC_X86_SSA__OpndDesc_OpndIndex((OOC_X86_SSA__Opnd)i0);
  i3 = (OOC_INT32)Object_Boxed__IntToString(i3);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5697));
  i0 = (OOC_INT32)OOC_X86_Debug__OutputDesc_Label((OOC_X86_Debug__Output)i2, (OOC_X86_SSA__Node)i0);
  return (Object__String)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)i1,(void*)((OOC_INT32)_c70))),(void*)i3)),(void*)((OOC_INT32)_c71))),(void*)i0));
  goto l29;
l11:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5074))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5080))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 5091));
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l23;
  i = 1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5290))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5296))+4);
  res = (OOC_X86_SSA__Result)i1;
  i2 = i1!=i0;
  if (i2) goto l16;
  i1=1;
  goto l22;
l16:
  i2=i1;i1=1;
l17_loop:
  i1 = i1+1;
  i = i1;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 5383));
  res = (OOC_X86_SSA__Result)i2;
  i3 = i2!=i0;
  if (i3) goto l17_loop;
l22:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5462))+4);
  i3 = (OOC_INT32)out;
  i2 = (OOC_INT32)OOC_X86_Debug__OutputDesc_GetInstrCode((OOC_X86_Debug__Output)i3, (OOC_X86_SSA__Instr)i2);
  i1 = (OOC_INT32)Object_Boxed__IntToString(i1);
  i1 = (OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c72),(void*)i2)),(void*)((OOC_INT32)_c73))),(void*)i1)),(void*)((OOC_INT32)_c74));
  str = (Object__String)i1;
  
  goto l24;
l23:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5215))+4);
  i2 = (OOC_INT32)out;
  i1 = (OOC_INT32)OOC_X86_Debug__OutputDesc_GetInstrCode((OOC_X86_Debug__Output)i2, (OOC_X86_SSA__Instr)i1);
  i1 = (OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c75),(void*)i1)),(void*)((OOC_INT32)_c76));
  str = (Object__String)i1;
  
l24:
  i0 = (OOC_INT32)OOC_X86_Debug__OutputDesc_Label_Location((OOC_X86_SSA__Result)i0);
  return (Object__String)((OOC_INT32)Object__Concat2((void*)i1,(void*)i0));
  goto l29;
l26:
  i1 = (OOC_INT32)out;
  i0 = (OOC_INT32)OOC_X86_Debug__OutputDesc_GetInstrCode((OOC_X86_Debug__Output)i1, (OOC_X86_SSA__Instr)i0);
  return (Object__String)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c77),(void*)i0)),(void*)((OOC_INT32)_c78)));
  goto l29;
l28:
  return (Object__String)((OOC_INT32)_c79);
l29:
  _failed_function(4522); return 0;
  ;
}

void OOC_X86_Debug__OutputDesc_Result(OOC_X86_Debug__Output out, Object__String msg, OOC_X86_SSA__Result res) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)msg;
  Out__Object((Object__Object)i0);
  Out__String(": ", 3);
  i0 = (OOC_INT32)out;
  i1 = (OOC_INT32)res;
  i0 = (OOC_INT32)OOC_X86_Debug__OutputDesc_Label((OOC_X86_Debug__Output)i0, (OOC_X86_SSA__Node)i1);
  Out__Object((Object__Object)i0);
  Out__Ln();
  return;
  ;
}

void OOC_X86_Debug__OutputDesc_Instr(OOC_X86_Debug__Output out, Object__String msg, OOC_X86_SSA__Instr instr) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)msg;
  Out__Object((Object__Object)i0);
  Out__String(": ", 3);
  i0 = (OOC_INT32)out;
  i1 = (OOC_INT32)instr;
  i0 = (OOC_INT32)OOC_X86_Debug__OutputDesc_Label((OOC_X86_Debug__Output)i0, (OOC_X86_SSA__Node)i1);
  Out__Object((Object__Object)i0);
  Out__String(": ", 3);
  i0 = (OOC_INT32)OOC_X86_Debug__Opcode((OOC_X86_SSA__Instr)i1);
  Out__Object((Object__Object)i0);
  Out__Ln();
  return;
  ;
}

void OOC_X86_Debug__OutputDesc_WriteFunction(OOC_X86_Debug__Output out) {
  register OOC_INT32 i0,i1,i2;
  IO_TextRider__Writer w;
  auto void OOC_X86_Debug__OutputDesc_WriteFunction_WriteConst(OOC_X86_SSA__Selector selector);
  auto void OOC_X86_Debug__OutputDesc_WriteFunction_Expr(OOC_X86_SSA__Instr instr);
  auto void OOC_X86_Debug__OutputDesc_WriteFunction_WriteBlock(OOC_X86_SSA__Block b, OOC_INT32 indent);
    
    void OOC_X86_Debug__OutputDesc_WriteFunction_WriteConst(OOC_X86_SSA__Selector selector) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)selector;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6287)))), &_td_OOC_X86_SSA__ConstDesc);
      if (i1) goto l31;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6355)))), &_td_OOC_X86_SSA__VarDesc);
      if (i1) goto l21;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6664)))), &_td_OOC_X86_SSA__ProcDesc);
      if (i1) goto l19;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6748)))), &_td_OOC_X86_SSA__ProcNameDesc);
      if (i1) goto l17;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6831)))), &_td_OOC_X86_SSA__TypeDescrDesc);
      if (i1) goto l15;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6949)))), &_td_OOC_X86_SSA__ModuleDescrDesc);
      if (i1) goto l13;
      _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6939)))), 6939);
      goto l32;
l13:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6977)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i0, (Object__Object)((OOC_INT32)_c80));
      goto l32;
l15:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6914));
      i0 = (OOC_INT32)OOC_C_Naming__NameOfTypeDescriptor((OOC_SymbolTable__Type)i0, (OOC_C_Naming__QualTypeData)0);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6857)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i1, (Object__Object)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c81),(void*)i0)),(void*)((OOC_INT32)_c82))));
      goto l32;
l17:
      i1 = (OOC_INT32)w;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6802));
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6773)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i1, (Object__Object)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c83),(void*)i0)),(void*)((OOC_INT32)_c84))));
      goto l32;
l19:
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6713));
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6713));
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6718)))), OOC_SymbolTable__DeclarationDesc_Name)),OOC_SymbolTable__DeclarationDesc_Name)((OOC_SymbolTable__Declaration)i0);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6685)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i1, (Object__Object)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c85),(void*)i0)),(void*)((OOC_INT32)_c86))));
      goto l32;
l21:
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6386));
      i1 = i1==0;
      if (i1) goto l28;
      i1 = OOC_X86_SSA__VarDesc_IsGlobalVar((OOC_X86_SSA__Var)i0);
      if (i1) goto l26;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6616));
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6616));
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6621)))), OOC_SymbolTable__DeclarationDesc_Name)),OOC_SymbolTable__DeclarationDesc_Name)((OOC_SymbolTable__Declaration)i0);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6585)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i1, (Object__Object)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c87),(void*)i0)),(void*)((OOC_INT32)_c88))));
      goto l32;
l26:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6548));
      i0 = (OOC_INT32)OOC_C_Naming__NameOfDeclaration((OOC_SymbolTable__Declaration)i0);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6495)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i1, (Object__Object)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c89),(void*)i0)),(void*)((OOC_INT32)_c90))));
      goto l32;
l28:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6415)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i0, (Object__Object)((OOC_INT32)_c91));
      goto l32;
l31:
      i1 = (OOC_INT32)w;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6330));
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6309)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i1, (Object__Object)i0);
l32:
      return;
      ;
    }

    
    void OOC_X86_Debug__OutputDesc_WriteFunction_Expr(OOC_X86_SSA__Instr instr) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      OOC_X86_SSA__Opnd opnd;
      OOC_INT32 i;
      OOC_X86_SSA__Instr jump;

      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7170)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "(", 2);
      i0 = (OOC_INT32)instr;
      i1 = (OOC_INT32)OOC_X86_Debug__Opcode((OOC_X86_SSA__Instr)i0);
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 8261)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i2, (Object__Object)i1);
      i1 = (OOC_INT32)OOC_X86_SSA__InstrDesc_Operands((OOC_X86_SSA__Instr)i0);
      i2 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i1)), OOC_X86_SSA__IterInstrOperandsDesc_Next);
      i3 = OOC_TBCALL(i2,OOC_X86_SSA__IterInstrOperandsDesc_Next)((OOC_X86_SSA__IterInstrOperands)i1, (void*)(OOC_INT32)&opnd);
      if (!i3) goto l12;
l3_loop:
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 8337)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i3, 32u);
      i3 = (OOC_INT32)opnd;
      i4 = *(OOC_UINT8*)((_check_pointer(i3, 8369))+16);
      if (i4) goto l6;
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 8468));
      i4 = (OOC_INT32)out;
      i3 = (OOC_INT32)OOC_X86_Debug__OutputDesc_Label((OOC_X86_Debug__Output)i4, (OOC_X86_SSA__Node)i3);
      i4 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 8441)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i4, (Object__Object)i3);
      goto l7;
l6:
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 8404));
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 8408))+4);
      OOC_X86_Debug__OutputDesc_WriteFunction_Expr((OOC_X86_SSA__Instr)i3);
l7:
      i3 = OOC_TBCALL(i2,OOC_X86_SSA__IterInstrOperandsDesc_Next)((OOC_X86_SSA__IterInstrOperands)i1, (void*)(OOC_INT32)&opnd);
      if (i3) goto l3_loop;
l12:
      i1 = *(OOC_INT8*)((_check_pointer(i0, 8517))+20);
      switch (i1) {
      case 0:
        i1 = (OOC_INT32)w;
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8554)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i1, 32u);
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8602))+28);
        i = 0;
        i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 8613)), 0);
        i2 = 0<i1;
        if (!i2) goto l27;
        i2=0;
l17_loop:
        i3 = i2!=0;
        if (!i3) goto l20;
        i3 = (OOC_INT32)w;
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 8660)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i3, 43u);
l20:
        i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8718))+28);
        i3 = _check_pointer(i3, 8729);
        i4 = OOC_ARRAY_LENGTH(i3, 0);
        i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 8729))*4);
        OOC_X86_Debug__OutputDesc_WriteFunction_WriteConst((OOC_X86_SSA__Selector)i3);
        i2 = i2+1;
        i = i2;
        i3 = i2<i1;
        if (i3) goto l17_loop;
        goto l27;
      default:
        goto l27;
      }
l27:
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8809)))), &_td_OOC_X86_SSA__MergeInstrDesc);
      if (!i1) goto l42;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8844))+56);
      i1 = i1==(OOC_INT32)0;
      if (i1) goto l40;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8954))+56);
      i0 = _check_pointer(i0, 8960);
      i1 = OOC_ARRAY_LENGTH(i0, 0);
      i1 = i0+i1*4;
      i2 = i1!=i0;
      if (!i2) goto l42;
l34_loop:
      i2 = (OOC_INT32)*(OOC_INT32*)i0;
      jump = (OOC_X86_SSA__Instr)i2;
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 8978)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i3, " [", 3);
      i3 = (OOC_INT32)out;
      i2 = (OOC_INT32)OOC_X86_Debug__OutputDesc_Label((OOC_X86_Debug__Output)i3, (OOC_X86_SSA__Node)i2);
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 9011)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i3, (Object__Object)i2);
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 9055)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i2, 93u);
      i0 = i0+4;
      i2 = i1!=i0;
      if (i2) goto l34_loop;
      goto l42;
l40:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8876)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, " [no incoming jumps]", 21);
l42:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9151)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, ")", 2);
      return;
      ;
    }

    
    void OOC_X86_Debug__OutputDesc_WriteFunction_WriteBlock(OOC_X86_SSA__Block b, OOC_INT32 indent) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
      OOC_X86_SSA__Instr instr;
      OOC_INT32 i;
      OOC_X86_SSA__Result res;
      OOC_X86_SSA__Dep dep;

      i0 = (OOC_INT32)b;
      i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_Instructions((OOC_X86_SSA__Block)i0);
      i1 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i0)), OOC_X86_SSA__IterBlockInstructionsDesc_Next);
      i2 = OOC_TBCALL(i1,OOC_X86_SSA__IterBlockInstructionsDesc_Next)((OOC_X86_SSA__IterBlockInstructions)i0, (void*)(OOC_INT32)&instr);
      if (!i2) goto l60;
      i2 = indent;
      i3 = i2+1;
      i4 = 1<=i2;
l3_loop:
      i5 = (OOC_INT32)instr;
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 9426))+32);
      i6 = i6!=(OOC_INT32)0;
      if (i6) goto l6;
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 9454))+36);
      i6 = i6!=(OOC_INT32)0;
      
      goto l8;
l6:
      i6=1u;
l8:
      if (i6) goto l10;
      i5 = OOC_X86_SSA__InstrDesc_IsLive((OOC_X86_SSA__Instr)i5);
      
      goto l12;
l10:
      i5=1u;
l12:
      if (!i5) goto l52;
      i5 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 9517)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i5);
      i = 1;
      if (!i4) goto l21;
      i5=1;
l16_loop:
      i6 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 9574)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i6, "  ", 3);
      i5 = i5+1;
      i = i5;
      i6 = i5<=i2;
      if (i6) goto l16_loop;
l21:
      i5 = (OOC_INT32)instr;
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 9639))+4);
      i6 = i6==(OOC_INT32)0;
      if (i6) goto l31;
      i5 = (OOC_INT32)OOC_X86_SSA__InstrDesc_Results((OOC_X86_SSA__Instr)i5);
      i6 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i5)), OOC_X86_SSA__IterInstrResultsDesc_Next);
      i7 = OOC_TBCALL(i6,OOC_X86_SSA__IterInstrResultsDesc_Next)((OOC_X86_SSA__IterInstrResults)i5, (void*)(OOC_INT32)&res);
      if (!i7) goto l30;
l25_loop:
      i7 = (OOC_INT32)res;
      i8 = (OOC_INT32)out;
      i7 = (OOC_INT32)OOC_X86_Debug__OutputDesc_Label((OOC_X86_Debug__Output)i8, (OOC_X86_SSA__Node)i7);
      i8 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i8, 9810)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i8, (Object__Object)i7);
      i7 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 9855)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i7, 32u);
      i7 = OOC_TBCALL(i6,OOC_X86_SSA__IterInstrResultsDesc_Next)((OOC_X86_SSA__IterInstrResults)i5, (void*)(OOC_INT32)&res);
      if (i7) goto l25_loop;
l30:
      i5 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 9902)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i5, "<- ", 4);
      goto l32;
l31:
      i6 = (OOC_INT32)out;
      i5 = (OOC_INT32)OOC_X86_Debug__OutputDesc_Label((OOC_X86_Debug__Output)i6, (OOC_X86_SSA__Node)i5);
      i6 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 9676)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i6, (Object__Object)i5);
      i5 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 9721)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i5, 32u);
l32:
      i5 = (OOC_INT32)instr;
      OOC_X86_Debug__OutputDesc_WriteFunction_Expr((OOC_X86_SSA__Instr)i5);
      i5 = (OOC_INT32)instr;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 9981))+32);
      i5 = i5!=(OOC_INT32)0;
      if (!i5) goto l52;
      i5 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 10018)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i5, "   [", 5);
      i5 = (OOC_INT32)instr;
      i5 = (OOC_INT32)OOC_X86_SSA__InstrDesc_BeforeList((OOC_X86_SSA__Instr)i5, (-1));
      i6 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i5)), OOC_X86_SSA__IterInstrBeforeListDesc_Next);
      i7 = OOC_TBCALL(i6,OOC_X86_SSA__IterInstrBeforeListDesc_Next)((OOC_X86_SSA__IterInstrBeforeList)i5, (void*)(OOC_INT32)&dep);
      if (!i7) goto l50;
l36_loop:
      i7 = (OOC_INT32)instr;
      i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i7, 10125))+32);
      i8 = (OOC_INT32)dep;
      i7 = i8!=i7;
      if (!i7) goto l39;
      i7 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 10160)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i7, 32u);
l39:
      i7 = (OOC_INT32)dep;
      i7 = *(OOC_INT8*)((_check_pointer(i7, 10218))+8);
      switch (i7) {
      case 0:
        i7 = (OOC_INT32)w;
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 10258)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i7, "c:", 3);
        goto l45;
      case 1:
        i7 = (OOC_INT32)w;
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 10308)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i7, "m:", 3);
        goto l45;
      case 2:
        i7 = (OOC_INT32)w;
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 10358)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i7, "r:", 3);
        goto l45;
      default:
        _failed_case(i7, 10210);
        goto l45;
      }
l45:
      i7 = (OOC_INT32)dep;
      i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i7, 10438));
      i8 = (OOC_INT32)out;
      i7 = (OOC_INT32)OOC_X86_Debug__OutputDesc_Label((OOC_X86_Debug__Output)i8, (OOC_X86_SSA__Node)i7);
      i8 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i8, 10412)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i8, (Object__Object)i7);
      i7 = OOC_TBCALL(i6,OOC_X86_SSA__IterInstrBeforeListDesc_Next)((OOC_X86_SSA__IterInstrBeforeList)i5, (void*)(OOC_INT32)&dep);
      if (i7) goto l36_loop;
l50:
      i5 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 10479)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i5, "]", 2);
l52:
      i5 = (OOC_INT32)instr;
      i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 10551)))), &_td_OOC_X86_SSA__BlockDesc);
      if (!i6) goto l55;
      OOC_X86_Debug__OutputDesc_WriteFunction_WriteBlock((OOC_X86_SSA__Block)(_type_guard(i5, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 10597)))), &_td_OOC_X86_SSA__BlockDesc, 10597)), i3);
l55:
      i5 = OOC_TBCALL(i1,OOC_X86_SSA__IterBlockInstructionsDesc_Next)((OOC_X86_SSA__IterBlockInstructions)i0, (void*)(OOC_INT32)&instr);
      if (i5) goto l3_loop;
l60:
      return;
      ;
    }


  i0 = (OOC_INT32)IO_StdChannels__stderr;
  i0 = (OOC_INT32)IO_TextRider__ConnectWriter((IO__ByteChannel)i0);
  w = (IO_TextRider__Writer)i0;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10730)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
  i1 = (OOC_INT32)out;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10774))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10745)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i0, (Object__Object)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c92),(void*)i2)));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 10800));
  OOC_X86_Debug__OutputDesc_WriteFunction_WriteBlock((OOC_X86_SSA__Block)i0, 0);
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10813)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
  return;
  ;
}

static void OOC_X86_Debug__UndefState(OOC_X86_Debug__State s) {
  register OOC_INT32 i0,i1,i2;
  OOC_INT32 i;

  i0 = (OOC_INT32)s;
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Instr.baseTypes[0]);
  OOC_X86_SSA__InstrDesc_INIT((OOC_X86_SSA__Instr)i1, (-1));
  *(OOC_INT32*)((_check_pointer(i0, 10913))+52) = i1;
  i = 0;
  i1=0;
l1_loop:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10996))+52);
  i2 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i2, 3);
  *(OOC_INT32*)(((_check_pointer(i0, 10984))+12)+(_check_index(i1, 9, OOC_UINT32, 10988))*4) = i2;
  i1 = i1+1;
  i = i1;
  i2 = i1<=8;
  if (i2) goto l1_loop;
l5:
  return;
  ;
}

void OOC_X86_Debug__WriteFunctionAgain(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)OOC_X86_Debug__out;
  OOC_X86_Debug__OutputDesc_WriteFunction((OOC_X86_Debug__Output)i0);
  return;
  ;
}

void OOC_X86_Debug__WriteFunction(OOC_X86_SSA__FunctionBlock b) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11234))+56);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11243))+72);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l3;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11342))+56);
  i1 = (OOC_INT32)OOC_C_Naming__NameOfDeclaration((OOC_SymbolTable__Declaration)i1);
  
  goto l4;
l3:
  i1 = (OOC_INT32)_c93;
  
l4:
  i2 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_Debug__Output.baseTypes[0]);
  OOC_X86_Debug__OutputDesc_INIT((OOC_X86_Debug__Output)i2, (OOC_X86_SSA__Block)i0, (Object__String)i1);
  OOC_X86_Debug__out = (OOC_X86_Debug__Output)i2;
  OOC_X86_Debug__OutputDesc_WriteFunction((OOC_X86_Debug__Output)i2);
  return;
  ;
}

Object__String OOC_X86_Debug__Label(OOC_X86_SSA__Node node) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)node;
  i1 = (OOC_INT32)OOC_X86_Debug__out;
  i0 = (OOC_INT32)OOC_X86_Debug__OutputDesc_Label((OOC_X86_Debug__Output)i1, (OOC_X86_SSA__Node)i0);
  return (Object__String)i0;
  ;
}

void OOC_X86_Debug__Log(const OOC_CHAR8 msg__ref[], OOC_LEN msg_0d, OOC_X86_SSA__Node node) {
  register OOC_INT32 i0;
  OOC_ALLOCATE_VPAR(msg,OOC_CHAR8 ,msg_0d)

  OOC_INITIALIZE_VPAR(msg__ref,msg,OOC_CHAR8 ,msg_0d)
  i0 = (OOC_INT32)node;
  i0 = (OOC_INT32)OOC_X86_Debug__Label((OOC_X86_SSA__Node)i0);
  Log__Object((void*)(OOC_INT32)msg, msg_0d, (Object__Object)i0);
  return;
  ;
}

void OOC_X86_Debug__Log2(const OOC_CHAR8 msg1__ref[], OOC_LEN msg1_0d, OOC_X86_SSA__Node node1, const OOC_CHAR8 msg2__ref[], OOC_LEN msg2_0d, OOC_X86_SSA__Node node2) {
  register OOC_INT32 i0,i1,i2;
  OOC_ALLOCATE_VPAR(msg1,OOC_CHAR8 ,msg1_0d)
  OOC_ALLOCATE_VPAR(msg2,OOC_CHAR8 ,msg2_0d)

  OOC_INITIALIZE_VPAR(msg1__ref,msg1,OOC_CHAR8 ,msg1_0d)
  OOC_INITIALIZE_VPAR(msg2__ref,msg2,OOC_CHAR8 ,msg2_0d)
  i0 = (OOC_INT32)node1;
  i0 = (OOC_INT32)OOC_X86_Debug__Label((OOC_X86_SSA__Node)i0);
  i1 = (OOC_INT32)Object__NewLatin1((void*)(OOC_INT32)msg2, msg2_0d);
  i2 = (OOC_INT32)node2;
  i2 = (OOC_INT32)OOC_X86_Debug__Label((OOC_X86_SSA__Node)i2);
  Log__Object((void*)(OOC_INT32)msg1, msg1_0d, (Object__Object)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)i0,(void*)((OOC_INT32)_c94))),(void*)i1)),(void*)((OOC_INT32)_c95))),(void*)i2)));
  return;
  ;
}

void OOC_X86_Debug__ValidateAllocation(OOC_X86_SSA__FunctionBlock b) {
  register OOC_INT32 i0,i1,i2,i3;
  ADT_Dictionary__Dictionary waiting;
  OOC_X86_Debug__State s;
  OOC_X86_Debug__State ready;
  OOC_X86_SSA__Block block;
  OOC_X86_SSA__Dep dep;
  Object__ObjectArrayPtr keys;
  auto void OOC_X86_Debug__ValidateAllocation_ValidateBlock(OOC_X86_Debug__State s);
  auto void OOC_X86_Debug__ValidateAllocation_PushState(OOC_X86_Debug__State s);
  auto void OOC_X86_Debug__ValidateAllocation_PushBlock(OOC_X86_Debug__State s, OOC_X86_SSA__Block block);
  auto OOC_X86_Debug__State OOC_X86_Debug__ValidateAllocation_PopState(void);
  auto void OOC_X86_Debug__ValidateAllocation_MergeState(OOC_X86_SSA__MergeInstr merge, OOC_X86_Debug__State s);
    
    void OOC_X86_Debug__ValidateAllocation_ValidateBlock(OOC_X86_Debug__State s) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5;
      OOC_X86_SSA__Instr instr;
      OOC_X86_SSA__Result res;
      OOC_X86_SSA__Opnd inOutOpnd;
      auto void OOC_X86_Debug__ValidateAllocation_ValidateBlock_ValidateOpnds(OOC_X86_SSA__Instr instr);
      auto OOC_CHAR8 OOC_X86_Debug__ValidateAllocation_ValidateBlock_HasControlDep(OOC_X86_SSA__Instr instr);
        
        void OOC_X86_Debug__ValidateAllocation_ValidateBlock_ValidateOpnds(OOC_X86_SSA__Instr instr) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5;
          OOC_X86_SSA__IterOperands iter;
          OOC_X86_SSA__Opnd opnd;
          OOC_X86_SSA__Result arg;

          i0 = (OOC_INT32)instr;
          i1 = *(OOC_INT8*)((_check_pointer(i0, 12998))+20);
          switch (i1) {
          case 37:
            i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_GateOperands((OOC_X86_SSA__Instr)i0);
            iter = (OOC_X86_SSA__IterOperands)i0;
            goto l5;
          case 38:
            return;
            goto l5;
          default:
            i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_Operands((OOC_X86_SSA__Instr)i0);
            iter = (OOC_X86_SSA__IterOperands)i0;
            goto l5;
          }
l5:
          i0 = (OOC_INT32)iter;
          i1 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i0)), OOC_X86_SSA__IterOperandsDesc_Next);
          i2 = OOC_TBCALL(i1,OOC_X86_SSA__IterOperandsDesc_Next)((OOC_X86_SSA__IterOperands)i0, (void*)(OOC_INT32)&opnd);
          if (!i2) goto l20;
l8_loop:
          i2 = (OOC_INT32)opnd;
          i3 = *(OOC_UINT8*)((_check_pointer(i2, 13370))+16);
          if (i3) goto l14;
          i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 13467));
          arg = (OOC_X86_SSA__Result)i3;
          i4 = *(OOC_INT8*)((_check_pointer(i3, 13495))+14);
          _assert((i4==0), 127, 13485);
          i4 = (OOC_INT32)s;
          i5 = *(OOC_INT8*)((_check_pointer(i3, 13550))+13);
          i4 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i4, 13542))+12)+(_check_index(i5, 9, OOC_UINT8, 13546))*4);
          i4 = i3!=i4;
          if (!i4) goto l15;
          i2 = (OOC_INT32)OOC_X86_Debug__Label((OOC_X86_SSA__Node)i2);
          Log__Object("arg not in register", 20, (Object__Object)i2);
          i2 = (OOC_INT32)s;
          i4 = *(OOC_INT8*)((_check_pointer(i3, 13718))+13);
          i2 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i2, 13710))+12)+(_check_index(i4, 9, OOC_UINT8, 13714))*4);
          i2 = (OOC_INT32)OOC_X86_Debug__Label((OOC_X86_SSA__Node)i2);
          Log__Object("instead the register holds", 27, (Object__Object)i2);
          i2 = (OOC_INT32)s;
          i4 = *(OOC_INT8*)((_check_pointer(i3, 13774))+13);
          i2 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i2, 13766))+12)+(_check_index(i4, 9, OOC_UINT8, 13770))*4);
          i2 = (OOC_INT32)OOC_X86_Debug__Label((OOC_X86_SSA__Node)i2);
          Log__Ptr("ptr", 4, (void*)i2);
          i2 = (OOC_INT32)s;
          i4 = *(OOC_INT8*)((_check_pointer(i3, 13834))+13);
          i2 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i2, 13826))+12)+(_check_index(i4, 9, OOC_UINT8, 13830))*4);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 13844))+4);
          i2 = (OOC_INT32)OOC_X86_Debug__Opcode((OOC_X86_SSA__Instr)i2);
          Log__Ptr("opcode", 7, (void*)i2);
          i2 = (OOC_INT32)s;
          i4 = *(OOC_INT8*)((_check_pointer(i3, 13890))+13);
          i2 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i2, 13882))+12)+(_check_index(i4, 9, OOC_UINT8, 13886))*4);
          _assert((i3==i2), 127, 13868);
          goto l15;
l14:
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 13416));
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 13420))+4);
          OOC_X86_Debug__ValidateAllocation_ValidateBlock_ValidateOpnds((OOC_X86_SSA__Instr)i2);
l15:
          i2 = OOC_TBCALL(i1,OOC_X86_SSA__IterOperandsDesc_Next)((OOC_X86_SSA__IterOperands)i0, (void*)(OOC_INT32)&opnd);
          if (i2) goto l8_loop;
l20:
          return;
          ;
        }

        
        OOC_CHAR8 OOC_X86_Debug__ValidateAllocation_ValidateBlock_HasControlDep(OOC_X86_SSA__Instr instr) {
          register OOC_INT32 i0;
          OOC_X86_SSA__Dep dep;

          i0 = (OOC_INT32)instr;
          i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AfterList((OOC_X86_SSA__Instr)i0, 0);
          i0 = OOC_X86_SSA__IterInstrAfterListDesc_Next((OOC_X86_SSA__IterInstrAfterList)i0, (void*)(OOC_INT32)&dep);
          return i0;
          ;
        }


      i0 = (OOC_INT32)s;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14240))+4);
      instr = (OOC_X86_SSA__Instr)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l39;
l3_loop:
      i1 = *(OOC_INT8*)((_check_pointer(i0, 14295))+20);
      switch (i1) {
      case 34:
      case 40:
      case 42:
        i1 = (OOC_INT32)s;
        *(OOC_INT32*)((_check_pointer(i1, 14362))+4) = i0;
        return;
        
        goto l34;
      default:
        i1 = OOC_X86_SSA__InstrDesc_IsLive((OOC_X86_SSA__Instr)i0);
        if (!i1) goto l34;
        i0 = OOC_X86_Debug__ValidateAllocation_ValidateBlock_HasControlDep((OOC_X86_SSA__Instr)i0);
        if (!i0) goto l12;
        i0 = (OOC_INT32)s;
        i1 = (OOC_INT32)instr;
        *(OOC_INT32*)((_check_pointer(i0, 14498))+8) = i1;
l12:
        i0 = (OOC_INT32)instr;
        OOC_X86_Debug__ValidateAllocation_ValidateBlock_ValidateOpnds((OOC_X86_SSA__Instr)i0);
        i0 = (OOC_INT32)instr;
        i1 = (OOC_INT32)OOC_X86_SSA__InstrDesc_Results((OOC_X86_SSA__Instr)i0);
        i2 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i1)), OOC_X86_SSA__IterInstrResultsDesc_Next);
        i3 = OOC_TBCALL(i2,OOC_X86_SSA__IterInstrResultsDesc_Next)((OOC_X86_SSA__IterInstrResults)i1, (void*)(OOC_INT32)&res);
        if (!i3) goto l26;
        i3 = (OOC_INT32)s;
l15_loop:
        i4 = (OOC_INT32)res;
        i5 = *(OOC_INT8*)((_check_pointer(i4, 14659))+14);
        i5 = i5!=0;
        if (!i5) goto l18;
        OOC_X86_Debug__Log("not in register", 16, (OOC_X86_SSA__Node)i4);
        i4 = (OOC_INT32)res;
        i4 = *(OOC_INT8*)((_check_pointer(i4, 14758))+14);
        _assert((i4==0), 127, 14748);
l18:
        i4 = (OOC_INT32)res;
        i5 = *(OOC_INT8*)((_check_pointer(i4, 14828))+13);
        i5 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i3, 14820))+12)+(_check_index(i5, 9, OOC_UINT8, 14824))*4);
        i5 = i5!=(OOC_INT32)0;
        if (!i5) goto l21;
        i5 = *(OOC_INT8*)((_check_pointer(i4, 14883))+13);
        i5 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i3, 14875))+12)+(_check_index(i5, 9, OOC_UINT8, 14879))*4);
        i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 14893))+4);
        _assert((i5!=i0), 127, 14867);
l21:
        i5 = *(OOC_INT8*)((_check_pointer(i4, 14952))+13);
        *(OOC_INT32*)(((_check_pointer(i3, 14944))+12)+(_check_index(i5, 9, OOC_UINT8, 14948))*4) = i4;
        i4 = OOC_TBCALL(i2,OOC_X86_SSA__IterInstrResultsDesc_Next)((OOC_X86_SSA__IterInstrResults)i1, (void*)(OOC_INT32)&res);
        if (i4) goto l15_loop;
l26:
        i1 = (OOC_INT32)OOC_X86_Machine__InOutOpnd((OOC_X86_SSA__Instr)i0);
        inOutOpnd = (OOC_X86_SSA__Opnd)i1;
        i2 = i1!=(OOC_INT32)0;
        if (!i2) goto l34;
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 15111));
        i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15132))+4);
        i2 = *(OOC_INT8*)((_check_pointer(i2, 15115))+13);
        i3 = *(OOC_INT8*)((_check_pointer(i3, 15143))+13);
        i2 = i2!=i3;
        if (!i2) goto l34;
        OOC_X86_Debug__Log("in/out opnd mismatch", 21, (OOC_X86_SSA__Node)i1);
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 15247));
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15268))+4);
        i1 = *(OOC_INT8*)((_check_pointer(i1, 15251))+13);
        i2 = *(OOC_INT8*)((_check_pointer(i2, 15279))+13);
        _assert((i1==i2), 127, 15231);
        goto l34;
      }
l34:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15378))+8);
      instr = (OOC_X86_SSA__Instr)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l3_loop;
l39:
      i0 = (OOC_INT32)s;
      *(OOC_INT32*)((_check_pointer(i0, 15408))+4) = (OOC_INT32)0;
      return;
      ;
    }

    
    void OOC_X86_Debug__ValidateAllocation_PushState(OOC_X86_Debug__State s) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)s;
      i1 = (OOC_INT32)ready;
      *(OOC_INT32*)((_check_pointer(i0, 15497))+56) = i1;
      ready = (OOC_X86_Debug__State)i0;
      return;
      ;
    }

    
    void OOC_X86_Debug__ValidateAllocation_PushBlock(OOC_X86_Debug__State s, OOC_X86_SSA__Block block) {
      register OOC_INT32 i0,i1,i2;
      OOC_X86_Debug__State t;

      i0 = (OOC_INT32)s;
      i0 = (OOC_INT32)OOC_X86_Debug__StateDesc_Copy((OOC_X86_Debug__State)i0);
      t = (OOC_X86_Debug__State)i0;
      i1 = (OOC_INT32)block;
      *(OOC_INT32*)(_check_pointer(i0, 15662)) = i1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15701))+48);
      *(OOC_INT32*)((_check_pointer(i0, 15686))+4) = i2;
      *(OOC_INT32*)((_check_pointer(i0, 15720))+8) = i1;
      OOC_X86_Debug__ValidateAllocation_PushState((OOC_X86_Debug__State)i0);
      return;
      ;
    }

    
    OOC_X86_Debug__State OOC_X86_Debug__ValidateAllocation_PopState(void) {
      register OOC_INT32 i0,i1;
      OOC_X86_Debug__State s;

      i0 = (OOC_INT32)ready;
      s = (OOC_X86_Debug__State)i0;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15884))+56);
      ready = (OOC_X86_Debug__State)i1;
      return (OOC_X86_Debug__State)i0;
      ;
    }

    
    void OOC_X86_Debug__ValidateAllocation_MergeState(OOC_X86_SSA__MergeInstr merge, OOC_X86_Debug__State s) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5;
      OOC_X86_Debug__State t;
      OOC_INT32 i;
      auto OOC_INT32 OOC_X86_Debug__ValidateAllocation_MergeState_MergedBlocks(OOC_X86_SSA__Instr merge);
        
        OOC_INT32 OOC_X86_Debug__ValidateAllocation_MergeState_MergedBlocks(OOC_X86_SSA__Instr merge) {
          register OOC_INT32 i0,i1,i2,i3;
          OOC_X86_SSA__Dep dep;

          i0 = (OOC_INT32)merge;
          i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_BeforeList((OOC_X86_SSA__Instr)i0, 0);
          i1 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i0)), OOC_X86_SSA__IterInstrBeforeListDesc_Next);
          i2 = OOC_TBCALL(i1,OOC_X86_SSA__IterInstrBeforeListDesc_Next)((OOC_X86_SSA__IterInstrBeforeList)i0, (void*)(OOC_INT32)&dep);
          if (i2) goto l3;
          i0=0;
          goto l9;
l3:
          i2=0;
l4_loop:
          i2 = i2+1;
          i3 = OOC_TBCALL(i1,OOC_X86_SSA__IterInstrBeforeListDesc_Next)((OOC_X86_SSA__IterInstrBeforeList)i0, (void*)(OOC_INT32)&dep);
          if (i3) goto l4_loop;
l8:
          i0=i2;
l9:
          return i0;
          ;
        }


      i0 = (OOC_INT32)merge;
      i1 = (OOC_INT32)waiting;
      i1 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i1, (Object__Object)i0);
      if (i1) goto l7;
      i1 = (OOC_INT32)s;
      i1 = (OOC_INT32)OOC_X86_Debug__StateDesc_Copy((OOC_X86_Debug__State)i1);
      t = (OOC_X86_Debug__State)i1;
      *(OOC_INT32*)(_check_pointer(i1, 16677)) = i0;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16718))+48);
      *(OOC_INT32*)((_check_pointer(i1, 16703))+4) = i2;
      *(OOC_INT32*)((_check_pointer(i1, 16739))+8) = i0;
      i0 = OOC_X86_Debug__ValidateAllocation_MergeState_MergedBlocks((OOC_X86_SSA__Instr)i0);
      *(OOC_INT32*)((_check_pointer(i1, 16769))+48) = (i0-1);
      i0 = (OOC_INT32)t;
      i1 = *(OOC_INT32*)((_check_pointer(i0, 16820))+48);
      i1 = i1==0;
      if (i1) goto l5;
      i1 = (OOC_INT32)merge;
      i2 = (OOC_INT32)waiting;
      ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i2, (Object__Object)i1, (Object__Object)i0);
      goto l19;
l5:
      OOC_X86_Debug__ValidateAllocation_PushState((OOC_X86_Debug__State)i0);
      goto l19;
l7:
      i1 = (OOC_INT32)waiting;
      i1 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i1, (Object__Object)i0);
      t = (OOC_X86_Debug__State)i1;
      i2 = (OOC_INT32)s;
      i = 0;
      i3=0;
l8_loop:
      i4 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i2, 16431))+12)+(_check_index(i3, 9, OOC_UINT32, 16435))*4);
      i5 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i1, 16420))+12)+(_check_index(i3, 9, OOC_UINT32, 16424))*4);
      i4 = i5!=i4;
      if (!i4) goto l11;
      *(OOC_INT32*)(((_check_pointer(i1, 16458))+12)+(_check_index(i3, 9, OOC_UINT32, 16462))*4) = (OOC_INT32)0;
l11:
      i3 = i3+1;
      i = i3;
      i4 = i3<=8;
      if (i4) goto l8_loop;
l15:
      i2 = *(OOC_INT32*)((_check_pointer(i1, 16515))+48);
      *(OOC_INT32*)((_check_pointer(i1, 16515))+48) = (i2-1);
      i2 = *(OOC_INT32*)((_check_pointer(i1, 16542))+48);
      i2 = i2==0;
      if (!i2) goto l19;
      OOC_X86_Debug__ValidateAllocation_PushState((OOC_X86_Debug__State)i1);
      i1 = (OOC_INT32)waiting;
      ADT_Dictionary__DictionaryDesc_Delete((ADT_Dictionary__Dictionary)i1, (Object__Object)i0);
l19:
      return;
      ;
    }


  i0 = (OOC_INT32)RT0__NewObject(_td__qtd3.baseTypes[0]);
  ADT_Dictionary__DictionaryDesc_INIT((ADT_Dictionary__Dictionary)i0);
  waiting = (ADT_Dictionary__Dictionary)i0;
  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_Debug__State.baseTypes[0]);
  OOC_X86_Debug__StateDesc_INIT((OOC_X86_Debug__State)i1, (OOC_X86_SSA__Block)i0);
  s = (OOC_X86_Debug__State)i1;
  OOC_X86_Debug__UndefState((OOC_X86_Debug__State)i1);
  ready = (OOC_X86_Debug__State)(OOC_INT32)0;
  OOC_X86_Debug__ValidateAllocation_PushState((OOC_X86_Debug__State)i1);
  i0 = (OOC_INT32)ready;
  i0 = i0!=(OOC_INT32)0;
  if (!i0) goto l44;
l3_loop:
  i0 = (OOC_INT32)OOC_X86_Debug__ValidateAllocation_PopState();
  s = (OOC_X86_Debug__State)i0;
  OOC_X86_Debug__ValidateAllocation_ValidateBlock((OOC_X86_Debug__State)i0);
  i0 = (OOC_INT32)s;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17198))+4);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l24;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 17748));
  i1 = *(OOC_INT8*)((_check_pointer(i1, 17754))+20);
  i1 = i1==36;
  if (i1) goto l22;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 18089));
  i1 = *(OOC_INT8*)((_check_pointer(i1, 18095))+20);
  i1 = i1==41;
  if (i1) goto l20;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18325))+8);
  i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AfterList((OOC_X86_SSA__Instr)i0, 0);
  i1 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i0)), OOC_X86_SSA__IterInstrAfterListDesc_Next);
  i2 = OOC_TBCALL(i1,OOC_X86_SSA__IterInstrAfterListDesc_Next)((OOC_X86_SSA__IterInstrAfterList)i0, (void*)(OOC_INT32)&dep);
  if (!i2) goto l39;
l11_loop:
  i2 = (OOC_INT32)dep;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 18380))+12);
  i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 18387)))), &_td_OOC_X86_SSA__MergeInstrDesc);
  if (!i3) goto l14;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 18435))+12);
  i3 = (OOC_INT32)s;
  OOC_X86_Debug__ValidateAllocation_MergeState((OOC_X86_SSA__MergeInstr)(_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 18444)))), &_td_OOC_X86_SSA__MergeInstrDesc, 18444)), (OOC_X86_Debug__State)i3);
l14:
  i2 = OOC_TBCALL(i1,OOC_X86_SSA__IterInstrAfterListDesc_Next)((OOC_X86_SSA__IterInstrAfterList)i0, (void*)(OOC_INT32)&dep);
  if (i2) goto l11_loop;
  goto l39;
l20:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 18188));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 18194))+8);
  *(OOC_INT32*)((_check_pointer(i0, 18177))+4) = i1;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 18226));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 18232))+16);
  *(OOC_INT32*)(_check_pointer(i0, 18215)) = i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18264))+4);
  *(OOC_INT32*)((_check_pointer(i0, 18249))+8) = i1;
  OOC_X86_Debug__ValidateAllocation_PushState((OOC_X86_Debug__State)i0);
  goto l39;
l22:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 17904));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 17910))+16);
  i1 = *(OOC_INT8*)((_check_pointer(i1, 17916))+20);
  _assert((i1==34), 127, 17896);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 17957));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 17963))+16);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 17969))+8);
  *(OOC_INT32*)((_check_pointer(i0, 17946))+4) = i1;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 18001));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 18007))+16);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 18013))+16);
  *(OOC_INT32*)(_check_pointer(i0, 17990)) = i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18045))+4);
  *(OOC_INT32*)((_check_pointer(i0, 18030))+8) = i1;
  OOC_X86_Debug__ValidateAllocation_PushState((OOC_X86_Debug__State)i0);
  goto l39;
l24:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17231))+4);
  i1 = *(OOC_INT8*)((_check_pointer(i1, 17237))+20);
  switch (i1) {
  case 34:
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17292))+4);
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17301)))), &_td_OOC_X86_SSA__BranchInstrDesc, 17301)), 17313))+56);
    i0 = _check_pointer(i0, 17319);
    i1 = OOC_ARRAY_LENGTH(i0, 0);
    i1 = i0+i1*4;
    i2 = i1!=i0;
    if (!i2) goto l39;
l29_loop:
    i2 = (OOC_INT32)*(OOC_INT32*)i0;
    block = (OOC_X86_SSA__Block)i2;
    i3 = (OOC_INT32)s;
    OOC_X86_Debug__ValidateAllocation_MergeState((OOC_X86_SSA__MergeInstr)(_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 17355)))), &_td_OOC_X86_SSA__MergeInstrDesc, 17355)), (OOC_X86_Debug__State)i3);
    i0 = i0+4;
    i2 = i1!=i0;
    if (i2) goto l29_loop;
    goto l39;
  case 40:
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17434))+4);
    OOC_X86_Debug__ValidateAllocation_PushBlock((OOC_X86_Debug__State)i0, (OOC_X86_SSA__Block)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17443)))), &_td_OOC_X86_SSA__BlockDesc, 17443)));
    goto l39;
  case 42:
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17531))+4);
    i1 = (OOC_INT32)OOC_X86_SSA__InstrDesc_MergingTarget((OOC_X86_SSA__Instr)i1);
    block = (OOC_X86_SSA__Block)i1;
    OOC_X86_Debug__ValidateAllocation_MergeState((OOC_X86_SSA__MergeInstr)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17584)))), &_td_OOC_X86_SSA__MergeInstrDesc, 17584)), (OOC_X86_Debug__State)i0);
    i0 = (OOC_INT32)s;
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17679))+4);
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 17685))+8);
    *(OOC_INT32*)((_check_pointer(i0, 17668))+4) = i1;
    OOC_X86_Debug__ValidateAllocation_PushState((OOC_X86_Debug__State)i0);
    goto l39;
  default:
    _failed_case(i1, 17225);
    goto l39;
  }
l39:
  i0 = (OOC_INT32)ready;
  i0 = i0!=(OOC_INT32)0;
  if (i0) goto l3_loop;
l44:
  i0 = (OOC_INT32)waiting;
  i1 = ADT_Dictionary__DictionaryDesc_Size((ADT_Dictionary__Dictionary)i0);
  i1 = i1!=0;
  if (!i1) goto l55;
  i1 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Keys((ADT_Dictionary__Dictionary)i0);
  keys = (Object__ObjectArrayPtr)i1;
  i1 = _check_pointer(i1, 18595);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i2 = i1+i2*4;
  i3 = i2!=i1;
  if (!i3) goto l54;
l49_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)i1;
  OOC_X86_Debug__Log("waiting", 8, (OOC_X86_SSA__Node)i3);
  i1 = i1+4;
  i3 = i2!=i1;
  if (i3) goto l49_loop;
l54:
  i0 = ADT_Dictionary__DictionaryDesc_Size((ADT_Dictionary__Dictionary)i0);
  _assert((i0==0), 127, 18648);
l55:
  return;
  ;
}

void OOC_OOC_X86_Debug_init(void) {
  _c0 = Object__NewLatin1Region("", 1, 0, 0);
  _c1 = Object__NewLatin1Region("i8", 3, 0, 2);
  _c2 = Object__NewLatin1Region("i16", 4, 0, 3);
  _c3 = Object__NewLatin1Region("i32", 4, 0, 3);
  _c4 = Object__NewLatin1Region("i64", 4, 0, 3);
  _c5 = Object__NewLatin1Region("u8", 3, 0, 2);
  _c6 = Object__NewLatin1Region("u16", 4, 0, 3);
  _c7 = Object__NewLatin1Region("u32", 4, 0, 3);
  _c8 = Object__NewLatin1Region("u64", 4, 0, 3);
  _c9 = Object__NewLatin1Region("adr", 4, 0, 3);
  _c10 = Object__NewLatin1Region("r32", 4, 0, 3);
  _c11 = Object__NewLatin1Region("r64", 4, 0, 3);
  _c12 = Object__NewLatin1Region("const", 6, 0, 5);
  _c13 = Object__NewLatin1Region("add", 4, 0, 3);
  _c14 = Object__NewLatin1Region("sub", 4, 0, 3);
  _c15 = Object__NewLatin1Region("mul", 4, 0, 3);
  _c16 = Object__NewLatin1Region("div", 4, 0, 3);
  _c17 = Object__NewLatin1Region("neg", 4, 0, 3);
  _c18 = Object__NewLatin1Region("asr", 4, 0, 3);
  _c19 = Object__NewLatin1Region("asl", 4, 0, 3);
  _c20 = Object__NewLatin1Region("indexed", 8, 0, 7);
  _c21 = Object__NewLatin1Region("eql", 4, 0, 3);
  _c22 = Object__NewLatin1Region("neq", 4, 0, 3);
  _c23 = Object__NewLatin1Region("lss", 4, 0, 3);
  _c24 = Object__NewLatin1Region("leq", 4, 0, 3);
  _c25 = Object__NewLatin1Region("gtr", 4, 0, 3);
  _c26 = Object__NewLatin1Region("geq", 4, 0, 3);
  _c27 = Object__NewLatin1Region("setBool", 8, 0, 7);
  _c28 = Object__NewLatin1Region("typeConv", 9, 0, 8);
  _c29 = Object__NewLatin1Region("enter", 6, 0, 5);
  _c30 = Object__NewLatin1Region("exit", 5, 0, 4);
  _c31 = Object__NewLatin1Region("return", 7, 0, 6);
  _c32 = Object__NewLatin1Region("call", 5, 0, 4);
  _c33 = Object__NewLatin1Region("function", 9, 0, 8);
  _c34 = Object__NewLatin1Region("allocateStack", 14, 0, 13);
  _c35 = Object__NewLatin1Region("standin", 8, 0, 7);
  _c36 = Object__NewLatin1Region("get", 4, 0, 3);
  _c37 = Object__NewLatin1Region("set", 4, 0, 3);
  _c38 = Object__NewLatin1Region("copy", 5, 0, 4);
  _c39 = Object__NewLatin1Region("push", 5, 0, 4);
  _c40 = Object__NewLatin1Region("pop", 4, 0, 3);
  _c41 = Object__NewLatin1Region("leave", 6, 0, 5);
  _c42 = Object__NewLatin1Region("getLengthParam", 15, 0, 14);
  _c43 = Object__NewLatin1Region("getLengthHeap", 14, 0, 13);
  _c44 = Object__NewLatin1Region("setStack", 9, 0, 8);
  _c45 = Object__NewLatin1Region("typeTag", 8, 0, 7);
  _c46 = Object__NewLatin1Region("branch", 7, 0, 6);
  _c47 = Object__NewLatin1Region("guard", 6, 0, 5);
  _c48 = Object__NewLatin1Region("guard-or-merge", 15, 0, 14);
  _c49 = Object__NewLatin1Region("merge", 6, 0, 5);
  _c50 = Object__NewLatin1Region("jump", 5, 0, 4);
  _c51 = Object__NewLatin1Region("gate", 5, 0, 4);
  _c52 = Object__NewLatin1Region("designatorGate", 15, 0, 14);
  _c53 = Object__NewLatin1Region("loopStart", 10, 0, 9);
  _c54 = Object__NewLatin1Region("loopEnd", 8, 0, 7);
  _c55 = Object__NewLatin1Region("loopExit", 9, 0, 8);
  _c56 = Object__NewLatin1Region("loopBackedge", 13, 0, 12);
  _c57 = Object__NewLatin1Char(45u);
  _c58 = Object__NewLatin1Region("sp", 3, 0, 2);
  _c59 = Object__NewLatin1Region("fp", 3, 0, 2);
  _c60 = Object__NewLatin1Region("cc", 3, 0, 2);
  _c61 = Object__NewLatin1Region("gp0", 4, 0, 3);
  _c62 = Object__NewLatin1Region("gp1", 4, 0, 3);
  _c63 = Object__NewLatin1Region("gp2", 4, 0, 3);
  _c64 = Object__NewLatin1Region("gp3", 4, 0, 3);
  _c65 = Object__NewLatin1Region("gp4", 4, 0, 3);
  _c66 = Object__NewLatin1Region("gp5", 4, 0, 3);
  _c67 = Object__NewLatin1Char(58u);
  _c68 = Object__NewLatin1Region(":Indirect", 10, 0, 9);
  _c69 = Object__NewLatin1Region("", 1, 0, 0);
  _c70 = Object__NewLatin1Char(47u);
  _c71 = Object__NewLatin1Char(61u);
  _c72 = Object__NewLatin1Char(40u);
  _c73 = Object__NewLatin1Char(46u);
  _c74 = Object__NewLatin1Char(41u);
  _c75 = Object__NewLatin1Char(40u);
  _c76 = Object__NewLatin1Char(41u);
  _c77 = Object__NewLatin1Char(123u);
  _c78 = Object__NewLatin1Char(125u);
  _c79 = Object__NewLatin1Region("NIL", 4, 0, 3);
  _c80 = Object__NewLatin1Region("_mid", 5, 0, 4);
  _c81 = Object__NewLatin1Region("adr(\"", 6, 0, 5);
  _c82 = Object__NewLatin1Region("\")", 3, 0, 2);
  _c83 = Object__NewLatin1Region("adr(\"", 6, 0, 5);
  _c84 = Object__NewLatin1Region("\")", 3, 0, 2);
  _c85 = Object__NewLatin1Region("adr(", 5, 0, 4);
  _c86 = Object__NewLatin1Char(41u);
  _c87 = Object__NewLatin1Region("offset(", 8, 0, 7);
  _c88 = Object__NewLatin1Char(41u);
  _c89 = Object__NewLatin1Region("adr(", 5, 0, 4);
  _c90 = Object__NewLatin1Char(41u);
  _c91 = Object__NewLatin1Region("offset(.)", 10, 0, 9);
  _c92 = Object__NewLatin1Region("PROCEDURE ", 11, 0, 10);
  _c93 = Object__NewLatin1Region("MODULE_BODY", 12, 0, 11);
  _c94 = Object__NewLatin1Region(", ", 3, 0, 2);
  _c95 = Object__NewLatin1Region(": ", 3, 0, 2);

  return;
  ;
}

/* --- */
