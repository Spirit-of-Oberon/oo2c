#include <OOC/X86/Debug.d>
#include <__oo2c.h>
#include <setjmp.h>

void OOC_X86_Debug__OutputDesc_INIT(OOC_X86_Debug__Output out, OOC_X86_SSA__Block b, Object__String name) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)out;
  i1 = (OOC_INT32)b;
  *(OOC_INT32*)(_check_pointer(i0, 903)) = i1;
  i1 = (OOC_INT32)name;
  *(OOC_INT32*)((_check_pointer(i0, 919))+4) = i1;
  i1 = (OOC_INT32)RT0__NewObject(_td__qtd1.baseTypes[0]);
  ADT_Dictionary__DictionaryDesc_INIT((ADT_Dictionary__Dictionary)i1);
  *(OOC_INT32*)((_check_pointer(i0, 941))+8) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 1006))+12) = 0;
  return;
  ;
}

void OOC_X86_Debug__StateDesc_INIT(OOC_X86_Debug__State s, OOC_X86_SSA__Block block) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)s;
  i1 = (OOC_INT32)block;
  *(OOC_INT32*)(_check_pointer(i0, 1093)) = i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 1130))+48);
  *(OOC_INT32*)((_check_pointer(i0, 1115))+4) = i2;
  *(OOC_INT32*)((_check_pointer(i0, 1147))+8) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 1173))+84) = (-1);
  *(OOC_INT32*)((_check_pointer(i0, 1197))+88) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 1217))+92) = 0;
  return;
  ;
}

OOC_X86_Debug__State OOC_X86_Debug__StateDesc_Copy(OOC_X86_Debug__State s) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_X86_Debug__State t;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_Debug__State.baseTypes[0]);
  t = (OOC_X86_Debug__State)i0;
  i1 = (OOC_INT32)s;
  i1 = _check_pointer(i1, 1332);
  i2 = _check_pointer(i0, 1326);
  i3 = (OOC_INT32)&_td_OOC_X86_Debug__StateDesc;
  i3 = i3!=i3;
  if (!i3) goto l4;
  _failed_type_assert(1326);
l4:
  _copy_block(i1,i2,96);
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
    _failed_case(i0, 1412);
    goto l15;
  }
l15:
  _failed_function(1372); return 0;
  ;
}

Object__String OOC_X86_Debug__Opcode(OOC_X86_SSA__Instr instr) {
  register OOC_INT32 i0,i1;
  Object__String str;
  Object__String type;

  i0 = (OOC_INT32)instr;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 1919))+20);
  switch (i1) {
  case 0:
    str = (Object__String)((OOC_INT32)_c12);
    goto l61;
  case 1:
    str = (Object__String)((OOC_INT32)_c13);
    goto l61;
  case 2:
    str = (Object__String)((OOC_INT32)_c14);
    goto l61;
  case 3:
    str = (Object__String)((OOC_INT32)_c15);
    goto l61;
  case 4:
    str = (Object__String)((OOC_INT32)_c16);
    goto l61;
  case 5:
    str = (Object__String)((OOC_INT32)_c17);
    goto l61;
  case 6:
    str = (Object__String)((OOC_INT32)_c18);
    goto l61;
  case 7:
    str = (Object__String)((OOC_INT32)_c19);
    goto l61;
  case 8:
    str = (Object__String)((OOC_INT32)_c20);
    goto l61;
  case 9:
    str = (Object__String)((OOC_INT32)_c21);
    goto l61;
  case 10:
    str = (Object__String)((OOC_INT32)_c22);
    goto l61;
  case 11:
    str = (Object__String)((OOC_INT32)_c23);
    goto l61;
  case 12:
    str = (Object__String)((OOC_INT32)_c24);
    goto l61;
  case 13:
    str = (Object__String)((OOC_INT32)_c25);
    goto l61;
  case 14:
    str = (Object__String)((OOC_INT32)_c26);
    goto l61;
  case 15:
    str = (Object__String)((OOC_INT32)_c27);
    goto l61;
  case 16:
    str = (Object__String)((OOC_INT32)_c28);
    goto l61;
  case 17:
    str = (Object__String)((OOC_INT32)_c29);
    goto l61;
  case 18:
    str = (Object__String)((OOC_INT32)_c30);
    goto l61;
  case 19:
    str = (Object__String)((OOC_INT32)_c31);
    goto l61;
  case 20:
    str = (Object__String)((OOC_INT32)_c32);
    goto l61;
  case 21:
    str = (Object__String)((OOC_INT32)_c33);
    goto l61;
  case 22:
    str = (Object__String)((OOC_INT32)_c34);
    goto l61;
  case 23:
    str = (Object__String)((OOC_INT32)_c35);
    goto l61;
  case 24:
    str = (Object__String)((OOC_INT32)_c36);
    goto l61;
  case 26:
    str = (Object__String)((OOC_INT32)_c37);
    goto l61;
  case 27:
    str = (Object__String)((OOC_INT32)_c38);
    goto l61;
  case 28:
    str = (Object__String)((OOC_INT32)_c39);
    goto l61;
  case 29:
    str = (Object__String)((OOC_INT32)_c40);
    goto l61;
  case 30:
    str = (Object__String)((OOC_INT32)_c41);
    goto l61;
  case 31:
    str = (Object__String)((OOC_INT32)_c42);
    goto l61;
  case 32:
    str = (Object__String)((OOC_INT32)_c43);
    goto l61;
  case 33:
    str = (Object__String)((OOC_INT32)_c44);
    goto l61;
  case 34:
    str = (Object__String)((OOC_INT32)_c45);
    goto l61;
  case 35:
    str = (Object__String)((OOC_INT32)_c46);
    goto l61;
  case 36:
    str = (Object__String)((OOC_INT32)_c47);
    goto l61;
  case 37:
    str = (Object__String)((OOC_INT32)_c48);
    goto l61;
  case 38:
    str = (Object__String)((OOC_INT32)_c49);
    goto l61;
  case 39:
    str = (Object__String)((OOC_INT32)_c50);
    goto l61;
  case 40:
    str = (Object__String)((OOC_INT32)_c51);
    goto l61;
  case 41:
    str = (Object__String)((OOC_INT32)_c52);
    goto l61;
  case 42:
    str = (Object__String)((OOC_INT32)_c53);
    goto l61;
  case 43:
    str = (Object__String)((OOC_INT32)_c54);
    goto l61;
  case 44:
    str = (Object__String)((OOC_INT32)_c55);
    goto l61;
  case 46:
    str = (Object__String)((OOC_INT32)_c56);
    goto l61;
  case 47:
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3517)))), &_td_OOC_X86_SSA__MergeInstrDesc, 3517)), 3528))+56);
    i1 = i1!=(OOC_INT32)0;
    if (i1) goto l50;
    str = (Object__String)((OOC_INT32)_c57);
    
    goto l61;
l50:
    str = (Object__String)((OOC_INT32)_c58);
    
    goto l61;
  case 48:
    str = (Object__String)((OOC_INT32)_c59);
    goto l61;
  case 49:
    str = (Object__String)((OOC_INT32)_c60);
    goto l61;
  case 50:
    str = (Object__String)((OOC_INT32)_c61);
    goto l61;
  case 51:
    str = (Object__String)((OOC_INT32)_c62);
    goto l61;
  case 52:
    str = (Object__String)((OOC_INT32)_c63);
    goto l61;
  case 53:
    str = (Object__String)((OOC_INT32)_c64);
    goto l61;
  case 54:
    str = (Object__String)((OOC_INT32)_c65);
    goto l61;
  case 55:
    str = (Object__String)((OOC_INT32)_c66);
    goto l61;
  default:
    _failed_case(i1, 1909);
    goto l61;
  }
l61:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3943))+4);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l64;
  i1=0u;
  goto l66;
l64:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3970))+4);
  i1 = *(OOC_INT8*)((_check_pointer(i1, 3981))+12);
  i1 = i1!=0;
  
l66:
  if (i1) goto l68;
  i0 = (OOC_INT32)str;
  return (Object__String)i0;
  goto l73;
l68:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4028))+4);
  i1 = *(OOC_INT8*)((_check_pointer(i1, 4039))+12);
  i1 = (OOC_INT32)OOC_X86_Debug__Type(i1);
  type = (Object__String)i1;
  i0 = *(OOC_INT8*)((_check_pointer(i0, 4062))+20);
  i0 = i0==0;
  if (i0) goto l71;
  i0 = (OOC_INT32)str;
  return (Object__String)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)i0,(void*)((OOC_INT32)_c67))),(void*)i1));
  goto l73;
l71:
  return (Object__String)i1;
l73:
  _failed_function(1835); return 0;
  ;
}

Object__String OOC_X86_Debug__Register(OOC_INT8 reg) {
  register OOC_INT32 i0;

  i0 = reg;
  switch (i0) {
  case 0:
    return (Object__String)((OOC_INT32)_c68);
    goto l21;
  case 1:
    return (Object__String)((OOC_INT32)_c69);
    goto l21;
  case 2:
    return (Object__String)((OOC_INT32)_c70);
    goto l21;
  case 3:
    return (Object__String)((OOC_INT32)_c71);
    goto l21;
  case 4:
    return (Object__String)((OOC_INT32)_c72);
    goto l21;
  case 5:
    return (Object__String)((OOC_INT32)_c73);
    goto l21;
  case 6:
    return (Object__String)((OOC_INT32)_c74);
    goto l21;
  case 7:
    return (Object__String)((OOC_INT32)_c75);
    goto l21;
  case 8:
    return (Object__String)((OOC_INT32)_c76);
    goto l21;
  case 9:
    return (Object__String)((OOC_INT32)_c77);
    goto l21;
  case 10:
    return (Object__String)((OOC_INT32)_c78);
    goto l21;
  case 11:
    return (Object__String)((OOC_INT32)_c79);
    goto l21;
  case 12:
    return (Object__String)((OOC_INT32)_c80);
    goto l21;
  case 13:
    return (Object__String)((OOC_INT32)_c81);
    goto l21;
  case 14:
    return (Object__String)((OOC_INT32)_c82);
    goto l21;
  case 15:
    return (Object__String)((OOC_INT32)_c83);
    goto l21;
  case 16:
    return (Object__String)((OOC_INT32)_c84);
    goto l21;
  case 17:
    return (Object__String)((OOC_INT32)_c85);
    goto l21;
  default:
    return (Object__String)((OOC_INT32)_c86);
    goto l21;
  }
l21:
  _failed_function(4219); return 0;
  ;
}

Object__String OOC_X86_Debug__OutputDesc_GetInstrCode(OOC_X86_Debug__Output out, OOC_X86_SSA__Instr instr) {
  register OOC_INT32 i0,i1,i2;
  Object__String str;

  i0 = (OOC_INT32)out;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4917))+8);
  i2 = (OOC_INT32)instr;
  i1 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i1, (Object__Object)i2);
  if (i1) goto l3;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 5006))+12);
  *(OOC_INT32*)((_check_pointer(i0, 5006))+12) = (i1+1);
  i1 = *(OOC_INT32*)((_check_pointer(i0, 5053))+12);
  i1 = (OOC_INT32)Object_Boxed__IntToString(i1);
  str = (Object__String)i1;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5075))+8);
  ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i0, (Object__Object)i2, (Object__Object)i1);
  return (Object__String)i1;
  goto l4;
l3:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4962))+8);
  i0 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i0, (Object__Object)i2);
  return (Object__String)i0;
l4:
  _failed_function(4838); return 0;
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
      i1 = *(OOC_INT8*)((_check_pointer(i0, 5335))+14);
      switch (i1) {
      case 0:
        i0 = *(OOC_INT8*)((_check_pointer(i0, 5398))+13);
        i0 = (OOC_INT32)OOC_X86_Debug__Register(i0);
        return (Object__String)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c87),(void*)i0));
        goto l6;
      case 1:
        return (Object__String)((OOC_INT32)_c88);
        goto l6;
      case (-1):
        return (Object__String)((OOC_INT32)_c89);
        goto l6;
      default:
        _failed_case(i1, 5327);
        goto l6;
      }
l6:
      _failed_function(5278); return 0;
      ;
    }


  i0 = (OOC_INT32)node;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l28;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5608)))), &_td_OOC_X86_SSA__InstrDesc);
  if (i1) goto l26;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5696)))), &_td_OOC_X86_SSA__ResultDesc);
  if (i1) goto l11;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6222)))), &_td_OOC_X86_SSA__OpndDesc);
  if (i1) goto l9;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6216)))), 6216);
  goto l29;
l9:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6270))+8);
  i2 = (OOC_INT32)out;
  i1 = (OOC_INT32)OOC_X86_Debug__OutputDesc_GetInstrCode((OOC_X86_Debug__Output)i2, (OOC_X86_SSA__Instr)i1);
  i3 = OOC_X86_SSA__OpndDesc_OpndIndex((OOC_X86_SSA__Opnd)i0);
  i3 = (OOC_INT32)Object_Boxed__IntToString(i3);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6349));
  i0 = (OOC_INT32)OOC_X86_Debug__OutputDesc_Label((OOC_X86_Debug__Output)i2, (OOC_X86_SSA__Node)i0);
  return (Object__String)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)i1,(void*)((OOC_INT32)_c90))),(void*)i3)),(void*)((OOC_INT32)_c91))),(void*)i0));
  goto l29;
l11:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5726))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5732))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 5743));
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l23;
  i = 1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5942))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5948))+4);
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
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 6035));
  res = (OOC_X86_SSA__Result)i2;
  i3 = i2!=i0;
  if (i3) goto l17_loop;
l22:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6114))+4);
  i3 = (OOC_INT32)out;
  i2 = (OOC_INT32)OOC_X86_Debug__OutputDesc_GetInstrCode((OOC_X86_Debug__Output)i3, (OOC_X86_SSA__Instr)i2);
  i1 = (OOC_INT32)Object_Boxed__IntToString(i1);
  i1 = (OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c92),(void*)i2)),(void*)((OOC_INT32)_c93))),(void*)i1)),(void*)((OOC_INT32)_c94));
  str = (Object__String)i1;
  
  goto l24;
l23:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5867))+4);
  i2 = (OOC_INT32)out;
  i1 = (OOC_INT32)OOC_X86_Debug__OutputDesc_GetInstrCode((OOC_X86_Debug__Output)i2, (OOC_X86_SSA__Instr)i1);
  i1 = (OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c95),(void*)i1)),(void*)((OOC_INT32)_c96));
  str = (Object__String)i1;
  
l24:
  i0 = (OOC_INT32)OOC_X86_Debug__OutputDesc_Label_Location((OOC_X86_SSA__Result)i0);
  return (Object__String)((OOC_INT32)Object__Concat2((void*)i1,(void*)i0));
  goto l29;
l26:
  i1 = (OOC_INT32)out;
  i0 = (OOC_INT32)OOC_X86_Debug__OutputDesc_GetInstrCode((OOC_X86_Debug__Output)i1, (OOC_X86_SSA__Instr)i0);
  return (Object__String)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c97),(void*)i0)),(void*)((OOC_INT32)_c98)));
  goto l29;
l28:
  return (Object__String)((OOC_INT32)_c99);
l29:
  _failed_function(5174); return 0;
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
      register OOC_INT32 i0,i1,i2;

      i0 = (OOC_INT32)selector;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6939)))), &_td_OOC_X86_SSA__ConstDesc);
      if (i1) goto l34;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7007)))), &_td_OOC_X86_SSA__VarDesc);
      if (i1) goto l21;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7467)))), &_td_OOC_X86_SSA__ProcDesc);
      if (i1) goto l19;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7551)))), &_td_OOC_X86_SSA__ProcNameDesc);
      if (i1) goto l17;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7634)))), &_td_OOC_X86_SSA__TypeDescrDesc);
      if (i1) goto l15;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7752)))), &_td_OOC_X86_SSA__ModuleDescrDesc);
      if (i1) goto l13;
      _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7742)))), 7742);
      goto l35;
l13:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7780)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i0, (Object__Object)((OOC_INT32)_c100));
      goto l35;
l15:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7717));
      i0 = (OOC_INT32)OOC_C_Naming__NameOfTypeDescriptor((OOC_SymbolTable__Type)i0, (OOC_C_Naming__QualTypeData)0);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7660)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i1, (Object__Object)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c101),(void*)i0)),(void*)((OOC_INT32)_c102))));
      goto l35;
l17:
      i1 = (OOC_INT32)w;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7605));
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7576)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i1, (Object__Object)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c103),(void*)i0)),(void*)((OOC_INT32)_c104))));
      goto l35;
l19:
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7516));
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7516));
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7521)))), OOC_SymbolTable__DeclarationDesc_Name)),OOC_SymbolTable__DeclarationDesc_Name)((OOC_SymbolTable__Declaration)i0);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7488)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i1, (Object__Object)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c105),(void*)i0)),(void*)((OOC_INT32)_c106))));
      goto l35;
l21:
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7038));
      i1 = i1==0;
      if (i1) goto l31;
      i1 = OOC_X86_SSA__VarDesc_IsGlobalVar((OOC_X86_SSA__Var)i0);
      if (i1) goto l29;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7268));
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7268));
      i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7273)))), OOC_SymbolTable__DeclarationDesc_Name)),OOC_SymbolTable__DeclarationDesc_Name)((OOC_SymbolTable__Declaration)i2);
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 7237)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i2, (Object__Object)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c107),(void*)i1)));
      i1 = *(OOC_INT32*)((_check_pointer(i0, 7305))+4);
      i1 = i1>=0;
      if (!i1) goto l28;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7334)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i1, 46u);
      i1 = (OOC_INT32)w;
      i0 = *(OOC_INT32*)((_check_pointer(i0, 7383))+4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7364)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i1, i0, 0);
l28:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7419)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i0, (Object__Object)((OOC_INT32)_c108));
      goto l35;
l29:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7200));
      i0 = (OOC_INT32)OOC_C_Naming__NameOfDeclaration((OOC_SymbolTable__Declaration)i0);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7147)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i1, (Object__Object)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c109),(void*)i0)),(void*)((OOC_INT32)_c110))));
      goto l35;
l31:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7067)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i0, (Object__Object)((OOC_INT32)_c111));
      goto l35;
l34:
      i1 = (OOC_INT32)w;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6982));
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6961)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i1, (Object__Object)i0);
l35:
      return;
      ;
    }

    
    void OOC_X86_Debug__OutputDesc_WriteFunction_Expr(OOC_X86_SSA__Instr instr) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
      OOC_X86_SSA__Selector s;
      OOC_X86_SSA__Opnd opnd;
      OOC_INT32 i;
      OOC_X86_SSA__Instr jump;

      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7973)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "(", 2);
      i0 = (OOC_INT32)instr;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8025))+28);
      i1 = (OOC_INT32)instr;
      i0 = i0!=(OOC_INT32)0;
      if (!i0) goto l51;
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8058)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "<", 2);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8099))+28);
      i0 = _check_pointer(i0, 8110);
      i2 = OOC_ARRAY_LENGTH(i0, 0);
      i2 = i0+i2*4;
      i3 = i2!=i0;
      if (!i3) goto l50;
      i3 = (OOC_INT32)_c112;
      i4 = (OOC_INT32)_c113;
      i5 = (OOC_INT32)_c114;
      
l5_loop:
      i6 = (OOC_INT32)*(OOC_INT32*)i0;
      s = (OOC_X86_SSA__Selector)i6;
      i7 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 8131)))), &_td_OOC_X86_SSA__VarDesc);
      if (i7) goto l40;
      i7 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 8313)))), &_td_OOC_X86_SSA__ConstDesc);
      if (i7) goto l38;
      i7 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 8375)))), &_td_OOC_X86_SSA__ProcDesc);
      if (i7) goto l36;
      i7 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 8445)))), &_td_OOC_X86_SSA__IndexDesc);
      if (i7) goto l34;
      i7 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 8598)))), &_td_OOC_X86_SSA__FieldDesc);
      if (i7) goto l32;
      i7 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 8702)))), &_td_OOC_X86_SSA__ProcNameDesc);
      if (i7) goto l30;
      i7 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 8774)))), &_td_OOC_X86_SSA__TypeDescrDesc);
      if (i7) goto l28;
      i7 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 8873)))), &_td_OOC_X86_SSA__ModuleDescrDesc);
      if (i7) goto l26;
      i7 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 8940)))), &_td_OOC_X86_SSA__HeapObjDesc);
      if (i7) goto l24;
      _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 8937)))), 8937);
      goto l45;
l24:
      i6 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 8968)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i6, (Object__Object)i5);
      goto l45;
l26:
      i6 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 8905)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i6, "_mid", 5);
      goto l45;
l28:
      i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i6, 8846));
      i6 = (OOC_INT32)OOC_C_Naming__NameOfTypeDescriptor((OOC_SymbolTable__Type)i6, (OOC_C_Naming__QualTypeData)(OOC_INT32)0);
      i7 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 8804)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i7, (Object__Object)i6);
      goto l45;
l30:
      i7 = (OOC_INT32)w;
      i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i6, 8749));
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 8731)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i7, (Object__Object)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)i3,(void*)i6)),(void*)i4)));
      goto l45;
l32:
      i7 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 8624)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i7, ".", 2);
      i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i6, 8670));
      i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i7, 8676))+20);
      i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i7, 8681))+12);
      i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i6, 8670));
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 8676))+20);
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 8681))+12);
      i8 = (OOC_INT32)w;
      i7 = OOC_ARRAY_LENGTH((_check_pointer(i7, 8685)), 0);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i8, 8656)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i8, (void*)(_check_pointer(i6, 8685)), i7);
      goto l45;
l34:
      i7 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 8471)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i7, "[", 2);
      i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i6, 8527));
      i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i6, 8540));
      i7 = (OOC_INT32)out;
      i6 = (OOC_INT32)OOC_X86_Debug__OutputDesc_Label((OOC_X86_Debug__Output)i7, (OOC_X86_SSA__Node)i6);
      i7 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 8503)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i7, (Object__Object)i6);
      i6 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 8566)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i6, "]", 2);
      goto l45;
l36:
      i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i6, 8414));
      i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i7, 8419))+20);
      i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i7, 8424))+12);
      i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i6, 8414));
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 8419))+20);
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 8424))+12);
      i8 = (OOC_INT32)w;
      i7 = OOC_ARRAY_LENGTH((_check_pointer(i7, 8428)), 0);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i8, 8400)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i8, (void*)(_check_pointer(i6, 8428)), i7);
      goto l45;
l38:
      i6 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 8339)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i6, "const", 6);
      goto l45;
l40:
      i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i6, 8159));
      i7 = i7==(OOC_INT32)0;
      if (i7) goto l43;
      i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i6, 8265));
      i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i7, 8270))+20);
      i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i7, 8275))+12);
      i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i6, 8265));
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 8270))+20);
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 8275))+12);
      i8 = (OOC_INT32)w;
      i7 = OOC_ARRAY_LENGTH((_check_pointer(i7, 8279)), 0);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i8, 8251)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i8, (void*)(_check_pointer(i6, 8279)), i7);
      goto l45;
l43:
      i6 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 8192)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i6, "offset(.)", 10);
l45:
      i0 = i0+4;
      i6 = i2!=i0;
      if (i6) goto l5_loop;
l50:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9027)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "> ", 3);
l51:
      i0 = (OOC_INT32)OOC_X86_Debug__Opcode((OOC_X86_SSA__Instr)i1);
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 9074)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i2, (Object__Object)i0);
      i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_Operands((OOC_X86_SSA__Instr)i1);
      i2 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i0)), OOC_X86_SSA__IterInstrOperandsDesc_Next);
      i3 = OOC_TBCALL(i2,OOC_X86_SSA__IterInstrOperandsDesc_Next)((OOC_X86_SSA__IterInstrOperands)i0, (void*)(OOC_INT32)&opnd);
      if (!i3) goto l63;
l54_loop:
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 9150)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i3, 32u);
      i3 = (OOC_INT32)opnd;
      i4 = *(OOC_UINT8*)((_check_pointer(i3, 9182))+16);
      if (i4) goto l57;
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 9281));
      i4 = (OOC_INT32)out;
      i3 = (OOC_INT32)OOC_X86_Debug__OutputDesc_Label((OOC_X86_Debug__Output)i4, (OOC_X86_SSA__Node)i3);
      i4 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 9254)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i4, (Object__Object)i3);
      goto l58;
l57:
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 9217));
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 9221))+4);
      OOC_X86_Debug__OutputDesc_WriteFunction_Expr((OOC_X86_SSA__Instr)i3);
l58:
      i3 = OOC_TBCALL(i2,OOC_X86_SSA__IterInstrOperandsDesc_Next)((OOC_X86_SSA__IterInstrOperands)i0, (void*)(OOC_INT32)&opnd);
      if (i3) goto l54_loop;
l63:
      i0 = *(OOC_INT8*)((_check_pointer(i1, 9330))+20);
      switch (i0) {
      case 0:
        i0 = (OOC_INT32)w;
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9367)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i0, 32u);
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 9415))+28);
        i = 0;
        i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 9426)), 0);
        i2 = 0<i0;
        if (!i2) goto l78;
        i2=0;
l68_loop:
        i3 = i2!=0;
        if (!i3) goto l71;
        i3 = (OOC_INT32)w;
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 9473)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i3, 43u);
l71:
        i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 9531))+28);
        i3 = _check_pointer(i3, 9542);
        i4 = OOC_ARRAY_LENGTH(i3, 0);
        i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 9542))*4);
        OOC_X86_Debug__OutputDesc_WriteFunction_WriteConst((OOC_X86_SSA__Selector)i3);
        i2 = i2+1;
        i = i2;
        i3 = i2<i0;
        if (i3) goto l68_loop;
        goto l78;
      default:
        goto l78;
      }
l78:
      i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9622)))), &_td_OOC_X86_SSA__MergeInstrDesc);
      if (!i0) goto l93;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 9657))+56);
      i0 = i0==(OOC_INT32)0;
      if (i0) goto l91;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 9767))+56);
      i0 = _check_pointer(i0, 9773);
      i1 = OOC_ARRAY_LENGTH(i0, 0);
      i1 = i0+i1*4;
      i2 = i1!=i0;
      if (!i2) goto l93;
l85_loop:
      i2 = (OOC_INT32)*(OOC_INT32*)i0;
      jump = (OOC_X86_SSA__Instr)i2;
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 9791)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i3, " [", 3);
      i3 = (OOC_INT32)out;
      i2 = (OOC_INT32)OOC_X86_Debug__OutputDesc_Label((OOC_X86_Debug__Output)i3, (OOC_X86_SSA__Node)i2);
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 9824)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i3, (Object__Object)i2);
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 9868)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i2, 93u);
      i0 = i0+4;
      i2 = i1!=i0;
      if (i2) goto l85_loop;
      goto l93;
l91:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9689)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, " [no incoming jumps]", 21);
l93:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9964)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, ")", 2);
      return;
      ;
    }

    
    void OOC_X86_Debug__OutputDesc_WriteFunction_WriteBlock(OOC_X86_SSA__Block b, OOC_INT32 indent) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
      OOC_X86_SSA__Instr instr;
      OOC_INT32 i;
      OOC_X86_SSA__Dep dep;

      i0 = (OOC_INT32)b;
      i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_Instructions((OOC_X86_SSA__Block)i0);
      i1 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i0)), OOC_X86_SSA__IterBlockInstructionsDesc_Next);
      i2 = OOC_TBCALL(i1,OOC_X86_SSA__IterBlockInstructionsDesc_Next)((OOC_X86_SSA__IterBlockInstructions)i0, (void*)(OOC_INT32)&instr);
      if (!i2) goto l59;
      i2 = indent;
      i3 = i2+1;
      i4 = 1<=i2;
l3_loop:
      i5 = (OOC_INT32)instr;
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 10218))+32);
      i6 = i6!=(OOC_INT32)0;
      if (i6) goto l6;
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 10246))+36);
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
      if (!i5) goto l51;
      i5 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 10309)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i5);
      i = 1;
      if (!i4) goto l21;
      i5=1;
l16_loop:
      i6 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 10366)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i6, "  ", 3);
      i5 = i5+1;
      i = i5;
      i6 = i5<=i2;
      if (i6) goto l16_loop;
l21:
      i5 = (OOC_INT32)instr;
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 10431))+4);
      i6 = i6==(OOC_INT32)0;
      if (i6) goto l30;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 10586))+4);
      i6 = (OOC_INT32)out;
      i5 = (OOC_INT32)OOC_X86_Debug__OutputDesc_Label((OOC_X86_Debug__Output)i6, (OOC_X86_SSA__Node)i5);
      i6 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 10558)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i6, (Object__Object)i5);
      i5 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 10614)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i5, 32u);
      i5 = (OOC_INT32)instr;
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 10652))+4);
      i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i6, 10663));
      i6 = i6!=(OOC_INT32)0;
      if (!i6) goto l29;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 10730))+4);
      i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 10741));
      i6 = (OOC_INT32)out;
      i5 = (OOC_INT32)OOC_X86_Debug__OutputDesc_Label((OOC_X86_Debug__Output)i6, (OOC_X86_SSA__Node)i5);
      i6 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 10702)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i6, (Object__Object)i5);
      i5 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 10771)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i5, 32u);
      i5 = (OOC_INT32)instr;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 10811))+4);
      i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 10822));
      i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 10833));
      i5 = i5!=(OOC_INT32)0;
      if (!i5) goto l29;
      i5 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 10874)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i5, "... ", 5);
l29:
      i5 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 10945)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i5, "<- ", 4);
      goto l31;
l30:
      i6 = (OOC_INT32)out;
      i5 = (OOC_INT32)OOC_X86_Debug__OutputDesc_Label((OOC_X86_Debug__Output)i6, (OOC_X86_SSA__Node)i5);
      i6 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 10468)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i6, (Object__Object)i5);
      i5 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 10513)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i5, 32u);
l31:
      i5 = (OOC_INT32)instr;
      OOC_X86_Debug__OutputDesc_WriteFunction_Expr((OOC_X86_SSA__Instr)i5);
      i5 = (OOC_INT32)instr;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 11024))+32);
      i5 = i5!=(OOC_INT32)0;
      if (!i5) goto l51;
      i5 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 11061)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i5, "   [", 5);
      i5 = (OOC_INT32)instr;
      i5 = (OOC_INT32)OOC_X86_SSA__InstrDesc_BeforeList((OOC_X86_SSA__Instr)i5, (-1));
      i6 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i5)), OOC_X86_SSA__IterInstrBeforeListDesc_Next);
      i7 = OOC_TBCALL(i6,OOC_X86_SSA__IterInstrBeforeListDesc_Next)((OOC_X86_SSA__IterInstrBeforeList)i5, (void*)(OOC_INT32)&dep);
      if (!i7) goto l49;
l35_loop:
      i7 = (OOC_INT32)instr;
      i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i7, 11168))+32);
      i8 = (OOC_INT32)dep;
      i7 = i8!=i7;
      if (!i7) goto l38;
      i7 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 11203)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i7, 32u);
l38:
      i7 = (OOC_INT32)dep;
      i7 = *(OOC_INT8*)((_check_pointer(i7, 11261))+8);
      switch (i7) {
      case 0:
        i7 = (OOC_INT32)w;
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 11301)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i7, "c:", 3);
        goto l44;
      case 1:
        i7 = (OOC_INT32)w;
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 11351)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i7, "m:", 3);
        goto l44;
      case 2:
        i7 = (OOC_INT32)w;
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 11401)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i7, "r:", 3);
        goto l44;
      default:
        _failed_case(i7, 11253);
        goto l44;
      }
l44:
      i7 = (OOC_INT32)dep;
      i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i7, 11481));
      i8 = (OOC_INT32)out;
      i7 = (OOC_INT32)OOC_X86_Debug__OutputDesc_Label((OOC_X86_Debug__Output)i8, (OOC_X86_SSA__Node)i7);
      i8 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i8, 11455)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i8, (Object__Object)i7);
      i7 = OOC_TBCALL(i6,OOC_X86_SSA__IterInstrBeforeListDesc_Next)((OOC_X86_SSA__IterInstrBeforeList)i5, (void*)(OOC_INT32)&dep);
      if (i7) goto l35_loop;
l49:
      i5 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 11522)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i5, "]", 2);
l51:
      i5 = (OOC_INT32)instr;
      i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 11594)))), &_td_OOC_X86_SSA__BlockDesc);
      if (!i6) goto l54;
      OOC_X86_Debug__OutputDesc_WriteFunction_WriteBlock((OOC_X86_SSA__Block)(_type_guard(i5, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 11640)))), &_td_OOC_X86_SSA__BlockDesc, 11640)), i3);
l54:
      i5 = OOC_TBCALL(i1,OOC_X86_SSA__IterBlockInstructionsDesc_Next)((OOC_X86_SSA__IterBlockInstructions)i0, (void*)(OOC_INT32)&instr);
      if (i5) goto l3_loop;
l59:
      return;
      ;
    }


  i0 = (OOC_INT32)IO_StdChannels__stderr;
  i0 = (OOC_INT32)IO_TextRider__ConnectWriter((IO__ByteChannel)i0);
  w = (IO_TextRider__Writer)i0;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11773)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
  i1 = (OOC_INT32)out;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11817))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11788)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i0, (Object__Object)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c115),(void*)i2)));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 11843));
  OOC_X86_Debug__OutputDesc_WriteFunction_WriteBlock((OOC_X86_SSA__Block)i0, 0);
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11856)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
  return;
  ;
}

static void OOC_X86_Debug__UndefState(OOC_X86_Debug__State s) {
  register OOC_INT32 i0,i1,i2;
  OOC_INT32 i;

  i0 = (OOC_INT32)s;
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Instr.baseTypes[0]);
  OOC_X86_SSA__InstrDesc_INIT((OOC_X86_SSA__Instr)i1, (-1));
  *(OOC_INT32*)((_check_pointer(i0, 11956))+88) = i1;
  i = 0;
  i1=0;
l1_loop:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12039))+88);
  i2 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i2, 3);
  *(OOC_INT32*)(((_check_pointer(i0, 12027))+12)+(_check_index(i1, 18, OOC_UINT32, 12031))*4) = i2;
  i1 = i1+1;
  i = i1;
  i2 = i1<=17;
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
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12277))+56);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12286))+72);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l3;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12385))+56);
  i1 = (OOC_INT32)OOC_C_Naming__NameOfDeclaration((OOC_SymbolTable__Declaration)i1);
  
  goto l4;
l3:
  i1 = (OOC_INT32)_c116;
  
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
  Log__Object((void*)(OOC_INT32)msg1, msg1_0d, (Object__Object)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)i0,(void*)((OOC_INT32)_c117))),(void*)i1)),(void*)((OOC_INT32)_c118))),(void*)i2)));
  return;
  ;
}

void OOC_X86_Debug__ValidateAllocation(OOC_X86_SSA__FunctionBlock b) {
  register OOC_INT32 i0,i1,i2,i3;
  ADT_Dictionary__Dictionary waiting;
  OOC_X86_Debug__State s;
  OOC_X86_Debug__State ready;
  OOC_X86_SSA__Block block;
  OOC_X86_SSA__LoopStartInstr loopStart;
  OOC_X86_SSA__Dep dep;
  Object__ObjectArrayPtr keys;
  auto void OOC_X86_Debug__ValidateAllocation_ValidateBlock(OOC_X86_Debug__State s);
  auto void OOC_X86_Debug__ValidateAllocation_PushState(OOC_X86_Debug__State s);
  auto void OOC_X86_Debug__ValidateAllocation_PushBlock(OOC_X86_Debug__State s, OOC_X86_SSA__Block block);
  auto OOC_X86_Debug__State OOC_X86_Debug__ValidateAllocation_PopState(void);
  auto OOC_INT32 OOC_X86_Debug__ValidateAllocation_MergedBlocks(OOC_X86_SSA__Instr merge);
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
          i1 = *(OOC_INT8*)((_check_pointer(i0, 14074))+20);
          switch (i1) {
          case 49:
            i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_GateOperands((OOC_X86_SSA__Instr)i0);
            iter = (OOC_X86_SSA__IterOperands)i0;
            goto l5;
          case 50:
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
          i3 = *(OOC_UINT8*)((_check_pointer(i2, 14446))+16);
          if (i3) goto l14;
          i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 14543));
          arg = (OOC_X86_SSA__Result)i3;
          i4 = *(OOC_INT8*)((_check_pointer(i3, 14571))+14);
          _assert((i4==0), 127, 14561);
          i4 = (OOC_INT32)s;
          i5 = *(OOC_INT8*)((_check_pointer(i3, 14626))+13);
          i4 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i4, 14618))+12)+(_check_index(i5, 18, OOC_UINT8, 14622))*4);
          i4 = i3!=i4;
          if (!i4) goto l15;
          i2 = (OOC_INT32)OOC_X86_Debug__Label((OOC_X86_SSA__Node)i2);
          Log__Object("arg not in register", 20, (Object__Object)i2);
          i2 = (OOC_INT32)s;
          i4 = *(OOC_INT8*)((_check_pointer(i3, 14794))+13);
          i2 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i2, 14786))+12)+(_check_index(i4, 18, OOC_UINT8, 14790))*4);
          i2 = (OOC_INT32)OOC_X86_Debug__Label((OOC_X86_SSA__Node)i2);
          Log__Object("instead the register holds", 27, (Object__Object)i2);
          i2 = (OOC_INT32)s;
          i4 = *(OOC_INT8*)((_check_pointer(i3, 14850))+13);
          i2 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i2, 14842))+12)+(_check_index(i4, 18, OOC_UINT8, 14846))*4);
          i2 = (OOC_INT32)OOC_X86_Debug__Label((OOC_X86_SSA__Node)i2);
          Log__Ptr("ptr", 4, (void*)i2);
          i2 = (OOC_INT32)s;
          i4 = *(OOC_INT8*)((_check_pointer(i3, 14910))+13);
          i2 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i2, 14902))+12)+(_check_index(i4, 18, OOC_UINT8, 14906))*4);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14920))+4);
          i2 = (OOC_INT32)OOC_X86_Debug__Opcode((OOC_X86_SSA__Instr)i2);
          Log__Ptr("opcode", 7, (void*)i2);
          i2 = (OOC_INT32)s;
          i4 = *(OOC_INT8*)((_check_pointer(i3, 14966))+13);
          i2 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i2, 14958))+12)+(_check_index(i4, 18, OOC_UINT8, 14962))*4);
          _assert((i3==i2), 127, 14944);
          goto l15;
l14:
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 14492));
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14496))+4);
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
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15316))+4);
      instr = (OOC_X86_SSA__Instr)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l39;
l3_loop:
      i1 = *(OOC_INT8*)((_check_pointer(i0, 15371))+20);
      switch (i1) {
      case 46:
      case 52:
      case 54:
        i1 = (OOC_INT32)s;
        *(OOC_INT32*)((_check_pointer(i1, 15438))+4) = i0;
        return;
        
        goto l34;
      default:
        i1 = OOC_X86_SSA__InstrDesc_IsLive((OOC_X86_SSA__Instr)i0);
        if (!i1) goto l34;
        i0 = OOC_X86_Debug__ValidateAllocation_ValidateBlock_HasControlDep((OOC_X86_SSA__Instr)i0);
        if (!i0) goto l12;
        i0 = (OOC_INT32)s;
        i1 = (OOC_INT32)instr;
        *(OOC_INT32*)((_check_pointer(i0, 15574))+8) = i1;
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
        i5 = *(OOC_INT8*)((_check_pointer(i4, 15735))+14);
        i5 = i5!=0;
        if (!i5) goto l18;
        OOC_X86_Debug__Log("not in register", 16, (OOC_X86_SSA__Node)i4);
        i4 = (OOC_INT32)res;
        i4 = *(OOC_INT8*)((_check_pointer(i4, 15834))+14);
        _assert((i4==0), 127, 15824);
l18:
        i4 = (OOC_INT32)res;
        i5 = *(OOC_INT8*)((_check_pointer(i4, 15904))+13);
        i5 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i3, 15896))+12)+(_check_index(i5, 18, OOC_UINT8, 15900))*4);
        i5 = i5!=(OOC_INT32)0;
        if (!i5) goto l21;
        i5 = *(OOC_INT8*)((_check_pointer(i4, 15959))+13);
        i5 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i3, 15951))+12)+(_check_index(i5, 18, OOC_UINT8, 15955))*4);
        i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 15969))+4);
        _assert((i5!=i0), 127, 15943);
l21:
        i5 = *(OOC_INT8*)((_check_pointer(i4, 16028))+13);
        *(OOC_INT32*)(((_check_pointer(i3, 16020))+12)+(_check_index(i5, 18, OOC_UINT8, 16024))*4) = i4;
        i4 = OOC_TBCALL(i2,OOC_X86_SSA__IterInstrResultsDesc_Next)((OOC_X86_SSA__IterInstrResults)i1, (void*)(OOC_INT32)&res);
        if (i4) goto l15_loop;
l26:
        i1 = (OOC_INT32)OOC_X86_Machine__InOutOpnd((OOC_X86_SSA__Instr)i0);
        inOutOpnd = (OOC_X86_SSA__Opnd)i1;
        i2 = i1!=(OOC_INT32)0;
        if (!i2) goto l34;
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 16187));
        i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16208))+4);
        i2 = *(OOC_INT8*)((_check_pointer(i2, 16191))+13);
        i3 = *(OOC_INT8*)((_check_pointer(i3, 16219))+13);
        i2 = i2!=i3;
        if (!i2) goto l34;
        OOC_X86_Debug__Log("in/out opnd mismatch", 21, (OOC_X86_SSA__Node)i1);
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 16323));
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16344))+4);
        i1 = *(OOC_INT8*)((_check_pointer(i1, 16327))+13);
        i2 = *(OOC_INT8*)((_check_pointer(i2, 16355))+13);
        _assert((i1==i2), 127, 16307);
        goto l34;
      }
l34:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16454))+8);
      instr = (OOC_X86_SSA__Instr)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l3_loop;
l39:
      i0 = (OOC_INT32)s;
      *(OOC_INT32*)((_check_pointer(i0, 16484))+4) = (OOC_INT32)0;
      return;
      ;
    }

    
    void OOC_X86_Debug__ValidateAllocation_PushState(OOC_X86_Debug__State s) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)s;
      i1 = (OOC_INT32)ready;
      *(OOC_INT32*)((_check_pointer(i0, 16573))+92) = i1;
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
      *(OOC_INT32*)(_check_pointer(i0, 16738)) = i1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 16777))+48);
      *(OOC_INT32*)((_check_pointer(i0, 16762))+4) = i2;
      *(OOC_INT32*)((_check_pointer(i0, 16796))+8) = i1;
      OOC_X86_Debug__ValidateAllocation_PushState((OOC_X86_Debug__State)i0);
      return;
      ;
    }

    
    OOC_X86_Debug__State OOC_X86_Debug__ValidateAllocation_PopState(void) {
      register OOC_INT32 i0,i1;
      OOC_X86_Debug__State s;

      i0 = (OOC_INT32)ready;
      s = (OOC_X86_Debug__State)i0;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16960))+92);
      ready = (OOC_X86_Debug__State)i1;
      return (OOC_X86_Debug__State)i0;
      ;
    }

    
    OOC_INT32 OOC_X86_Debug__ValidateAllocation_MergedBlocks(OOC_X86_SSA__Instr merge) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      OOC_INT32 c;
      OOC_X86_SSA__Dep dep;

      c = 0;
      i0 = (OOC_INT32)merge;
      i1 = (OOC_INT32)OOC_X86_SSA__InstrDesc_BeforeList((OOC_X86_SSA__Instr)i0, 0);
      i2 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i1)), OOC_X86_SSA__IterInstrBeforeListDesc_Next);
      i3 = OOC_TBCALL(i2,OOC_X86_SSA__IterInstrBeforeListDesc_Next)((OOC_X86_SSA__IterInstrBeforeList)i1, (void*)(OOC_INT32)&dep);
      if (i3) goto l3;
      i1=0;
      goto l9;
l3:
      i3=0;
l4_loop:
      i3 = i3+1;
      c = i3;
      i4 = OOC_TBCALL(i2,OOC_X86_SSA__IterInstrBeforeListDesc_Next)((OOC_X86_SSA__IterInstrBeforeList)i1, (void*)(OOC_INT32)&dep);
      if (i4) goto l4_loop;
l8:
      i1=i3;
l9:
      i0 = *(OOC_INT8*)((_check_pointer(i0, 17214))+20);
      i0 = i0==53;
      if (i0) goto l12;
      i0=i1;
      goto l13;
l12:
      i0 = i1-1;
      
l13:
      return i0;
      ;
    }

    
    void OOC_X86_Debug__ValidateAllocation_MergeState(OOC_X86_SSA__MergeInstr merge, OOC_X86_Debug__State s) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5;
      OOC_X86_Debug__State t;
      OOC_INT32 i;

      i0 = (OOC_INT32)merge;
      i1 = (OOC_INT32)waiting;
      i1 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i1, (Object__Object)i0);
      if (i1) goto l7;
      i1 = (OOC_INT32)s;
      i1 = (OOC_INT32)OOC_X86_Debug__StateDesc_Copy((OOC_X86_Debug__State)i1);
      t = (OOC_X86_Debug__State)i1;
      *(OOC_INT32*)(_check_pointer(i1, 17843)) = i0;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17884))+48);
      *(OOC_INT32*)((_check_pointer(i1, 17869))+4) = i2;
      *(OOC_INT32*)((_check_pointer(i1, 17905))+8) = i0;
      i2 = OOC_X86_Debug__ValidateAllocation_MergedBlocks((OOC_X86_SSA__Instr)i0);
      *(OOC_INT32*)((_check_pointer(i1, 17935))+84) = (i2-1);
      i2 = *(OOC_INT32*)((_check_pointer(i1, 17986))+84);
      i2 = i2==0;
      if (i2) goto l5;
      i2 = (OOC_INT32)waiting;
      ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i2, (Object__Object)i0, (Object__Object)i1);
      goto l19;
l5:
      OOC_X86_Debug__ValidateAllocation_PushState((OOC_X86_Debug__State)i1);
      goto l19;
l7:
      i1 = (OOC_INT32)waiting;
      i1 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i1, (Object__Object)i0);
      t = (OOC_X86_Debug__State)i1;
      i2 = (OOC_INT32)s;
      i = 0;
      i3=0;
l8_loop:
      i4 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i2, 17597))+12)+(_check_index(i3, 18, OOC_UINT32, 17601))*4);
      i5 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i1, 17586))+12)+(_check_index(i3, 18, OOC_UINT32, 17590))*4);
      i4 = i5!=i4;
      if (!i4) goto l11;
      *(OOC_INT32*)(((_check_pointer(i1, 17624))+12)+(_check_index(i3, 18, OOC_UINT32, 17628))*4) = (OOC_INT32)0;
l11:
      i3 = i3+1;
      i = i3;
      i4 = i3<=17;
      if (i4) goto l8_loop;
l15:
      i2 = *(OOC_INT32*)((_check_pointer(i1, 17681))+84);
      *(OOC_INT32*)((_check_pointer(i1, 17681))+84) = (i2-1);
      i2 = *(OOC_INT32*)((_check_pointer(i1, 17708))+84);
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
  if (!i0) goto l51;
l3_loop:
  i0 = (OOC_INT32)OOC_X86_Debug__ValidateAllocation_PopState();
  s = (OOC_X86_Debug__State)i0;
  OOC_X86_Debug__ValidateAllocation_ValidateBlock((OOC_X86_Debug__State)i0);
  i0 = (OOC_INT32)s;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18364))+4);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l28;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 19195));
  i1 = *(OOC_INT8*)((_check_pointer(i1, 19201))+20);
  i1 = i1==48;
  if (i1) goto l26;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 19536));
  i1 = *(OOC_INT8*)((_check_pointer(i1, 19542))+20);
  i1 = i1==53;
  if (i1) goto l24;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19772))+8);
  i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AfterList((OOC_X86_SSA__Instr)i0, 0);
  i1 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i0)), OOC_X86_SSA__IterInstrAfterListDesc_Next);
  i2 = OOC_TBCALL(i1,OOC_X86_SSA__IterInstrAfterListDesc_Next)((OOC_X86_SSA__IterInstrAfterList)i0, (void*)(OOC_INT32)&dep);
  if (!i2) goto l46;
l11_loop:
  i2 = (OOC_INT32)dep;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 19827))+12);
  i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 19834)))), &_td_OOC_X86_SSA__MergeInstrDesc);
  if (i3) goto l14;
  i3=0u;
  goto l16;
l14:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 19857))+12);
  i3 = *(OOC_INT8*)((_check_pointer(i3, 19863))+20);
  i3 = i3!=53;
  
l16:
  if (!i3) goto l18;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 19915))+12);
  i3 = (OOC_INT32)s;
  OOC_X86_Debug__ValidateAllocation_MergeState((OOC_X86_SSA__MergeInstr)(_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 19924)))), &_td_OOC_X86_SSA__MergeInstrDesc, 19924)), (OOC_X86_Debug__State)i3);
l18:
  i2 = OOC_TBCALL(i1,OOC_X86_SSA__IterInstrAfterListDesc_Next)((OOC_X86_SSA__IterInstrAfterList)i0, (void*)(OOC_INT32)&dep);
  if (i2) goto l11_loop;
  goto l46;
l24:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 19635));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 19641))+8);
  *(OOC_INT32*)((_check_pointer(i0, 19624))+4) = i1;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 19673));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 19679))+16);
  *(OOC_INT32*)(_check_pointer(i0, 19662)) = i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19711))+4);
  *(OOC_INT32*)((_check_pointer(i0, 19696))+8) = i1;
  OOC_X86_Debug__ValidateAllocation_PushState((OOC_X86_Debug__State)i0);
  goto l46;
l26:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 19351));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 19357))+16);
  i1 = *(OOC_INT8*)((_check_pointer(i1, 19363))+20);
  _assert((i1==46), 127, 19343);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 19404));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 19410))+16);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 19416))+8);
  *(OOC_INT32*)((_check_pointer(i0, 19393))+4) = i1;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 19448));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 19454))+16);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 19460))+16);
  *(OOC_INT32*)(_check_pointer(i0, 19437)) = i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19492))+4);
  *(OOC_INT32*)((_check_pointer(i0, 19477))+8) = i1;
  OOC_X86_Debug__ValidateAllocation_PushState((OOC_X86_Debug__State)i0);
  goto l46;
l28:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18397))+4);
  i1 = *(OOC_INT8*)((_check_pointer(i1, 18403))+20);
  switch (i1) {
  case 46:
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18458))+4);
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18467)))), &_td_OOC_X86_SSA__BranchInstrDesc, 18467)), 18479))+56);
    i0 = _check_pointer(i0, 18485);
    i1 = OOC_ARRAY_LENGTH(i0, 0);
    i1 = i0+i1*4;
    i2 = i1!=i0;
    if (!i2) goto l46;
l33_loop:
    i2 = (OOC_INT32)*(OOC_INT32*)i0;
    block = (OOC_X86_SSA__Block)i2;
    i3 = (OOC_INT32)s;
    OOC_X86_Debug__ValidateAllocation_MergeState((OOC_X86_SSA__MergeInstr)(_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 18521)))), &_td_OOC_X86_SSA__MergeInstrDesc, 18521)), (OOC_X86_Debug__State)i3);
    i0 = i0+4;
    i2 = i1!=i0;
    if (i2) goto l33_loop;
    goto l46;
  case 52:
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18600))+4);
    i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 18609)))), &_td_OOC_X86_SSA__LoopStartInstrDesc, 18609);
    loopStart = (OOC_X86_SSA__LoopStartInstr)i1;
    OOC_X86_Debug__ValidateAllocation_PushBlock((OOC_X86_Debug__State)i0, (OOC_X86_SSA__Block)i1);
    i0 = (OOC_INT32)loopStart;
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18697))+60);
    i0 = OOC_X86_Debug__ValidateAllocation_MergedBlocks((OOC_X86_SSA__Instr)i0);
    i0 = i0==0;
    if (!i0) goto l46;
    i0 = (OOC_INT32)loopStart;
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18877))+60);
    i1 = (OOC_INT32)s;
    OOC_X86_Debug__ValidateAllocation_PushBlock((OOC_X86_Debug__State)i1, (OOC_X86_SSA__Block)i0);
    goto l46;
  case 54:
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18978))+4);
    i1 = (OOC_INT32)OOC_X86_SSA__InstrDesc_MergingTarget((OOC_X86_SSA__Instr)i1);
    block = (OOC_X86_SSA__Block)i1;
    OOC_X86_Debug__ValidateAllocation_MergeState((OOC_X86_SSA__MergeInstr)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 19031)))), &_td_OOC_X86_SSA__MergeInstrDesc, 19031)), (OOC_X86_Debug__State)i0);
    i0 = (OOC_INT32)s;
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19126))+4);
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 19132))+8);
    *(OOC_INT32*)((_check_pointer(i0, 19115))+4) = i1;
    OOC_X86_Debug__ValidateAllocation_PushState((OOC_X86_Debug__State)i0);
    goto l46;
  default:
    _failed_case(i1, 18391);
    goto l46;
  }
l46:
  i0 = (OOC_INT32)ready;
  i0 = i0!=(OOC_INT32)0;
  if (i0) goto l3_loop;
l51:
  i0 = (OOC_INT32)waiting;
  i1 = ADT_Dictionary__DictionaryDesc_Size((ADT_Dictionary__Dictionary)i0);
  i1 = i1!=0;
  if (!i1) goto l62;
  i1 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Keys((ADT_Dictionary__Dictionary)i0);
  keys = (Object__ObjectArrayPtr)i1;
  i1 = _check_pointer(i1, 20075);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i2 = i1+i2*4;
  i3 = i2!=i1;
  if (!i3) goto l61;
l56_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)i1;
  OOC_X86_Debug__Log("waiting", 8, (OOC_X86_SSA__Node)i3);
  i1 = i1+4;
  i3 = i2!=i1;
  if (i3) goto l56_loop;
l61:
  i0 = ADT_Dictionary__DictionaryDesc_Size((ADT_Dictionary__Dictionary)i0);
  _assert((i0==0), 127, 20128);
l62:
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
  _c20 = Object__NewLatin1Region("lsr", 4, 0, 3);
  _c21 = Object__NewLatin1Region("lsl", 4, 0, 3);
  _c22 = Object__NewLatin1Region("rr", 3, 0, 2);
  _c23 = Object__NewLatin1Region("rl", 3, 0, 2);
  _c24 = Object__NewLatin1Region("indexed", 8, 0, 7);
  _c25 = Object__NewLatin1Region("eql", 4, 0, 3);
  _c26 = Object__NewLatin1Region("neq", 4, 0, 3);
  _c27 = Object__NewLatin1Region("lss", 4, 0, 3);
  _c28 = Object__NewLatin1Region("leq", 4, 0, 3);
  _c29 = Object__NewLatin1Region("gtr", 4, 0, 3);
  _c30 = Object__NewLatin1Region("geq", 4, 0, 3);
  _c31 = Object__NewLatin1Region("setBool", 8, 0, 7);
  _c32 = Object__NewLatin1Region("bitTestAndSet", 14, 0, 13);
  _c33 = Object__NewLatin1Region("bitTestAndClear", 16, 0, 15);
  _c34 = Object__NewLatin1Region("typeConv", 9, 0, 8);
  _c35 = Object__NewLatin1Region("fpLoad", 7, 0, 6);
  _c36 = Object__NewLatin1Region("fpStorePop", 11, 0, 10);
  _c37 = Object__NewLatin1Region("enter", 6, 0, 5);
  _c38 = Object__NewLatin1Region("exit", 5, 0, 4);
  _c39 = Object__NewLatin1Region("return", 7, 0, 6);
  _c40 = Object__NewLatin1Region("call", 5, 0, 4);
  _c41 = Object__NewLatin1Region("bounceResult", 13, 0, 12);
  _c42 = Object__NewLatin1Region("function", 9, 0, 8);
  _c43 = Object__NewLatin1Region("allocateStack", 14, 0, 13);
  _c44 = Object__NewLatin1Region("standin", 8, 0, 7);
  _c45 = Object__NewLatin1Region("get", 4, 0, 3);
  _c46 = Object__NewLatin1Region("set", 4, 0, 3);
  _c47 = Object__NewLatin1Region("copy", 5, 0, 4);
  _c48 = Object__NewLatin1Region("typeCast", 9, 0, 8);
  _c49 = Object__NewLatin1Region("loadRegister", 13, 0, 12);
  _c50 = Object__NewLatin1Region("push", 5, 0, 4);
  _c51 = Object__NewLatin1Region("pop", 4, 0, 3);
  _c52 = Object__NewLatin1Region("leave", 6, 0, 5);
  _c53 = Object__NewLatin1Region("getLengthHeap", 14, 0, 13);
  _c54 = Object__NewLatin1Region("setStack", 9, 0, 8);
  _c55 = Object__NewLatin1Region("typeTag", 8, 0, 7);
  _c56 = Object__NewLatin1Region("branch", 7, 0, 6);
  _c57 = Object__NewLatin1Region("guard", 6, 0, 5);
  _c58 = Object__NewLatin1Region("guard-or-merge", 15, 0, 14);
  _c59 = Object__NewLatin1Region("merge", 6, 0, 5);
  _c60 = Object__NewLatin1Region("jump", 5, 0, 4);
  _c61 = Object__NewLatin1Region("gate", 5, 0, 4);
  _c62 = Object__NewLatin1Region("designatorGate", 15, 0, 14);
  _c63 = Object__NewLatin1Region("loopStart", 10, 0, 9);
  _c64 = Object__NewLatin1Region("loopEnd", 8, 0, 7);
  _c65 = Object__NewLatin1Region("loopExit", 9, 0, 8);
  _c66 = Object__NewLatin1Region("loopBackedge", 13, 0, 12);
  _c67 = Object__NewLatin1Char(45u);
  _c68 = Object__NewLatin1Region("sp", 3, 0, 2);
  _c69 = Object__NewLatin1Region("fp", 3, 0, 2);
  _c70 = Object__NewLatin1Region("cc", 3, 0, 2);
  _c71 = Object__NewLatin1Region("gp0", 4, 0, 3);
  _c72 = Object__NewLatin1Region("gp1", 4, 0, 3);
  _c73 = Object__NewLatin1Region("gp2", 4, 0, 3);
  _c74 = Object__NewLatin1Region("gp3", 4, 0, 3);
  _c75 = Object__NewLatin1Region("gp4", 4, 0, 3);
  _c76 = Object__NewLatin1Region("gp5", 4, 0, 3);
  _c77 = Object__NewLatin1Region("st0", 4, 0, 3);
  _c78 = Object__NewLatin1Region("fp0", 4, 0, 3);
  _c79 = Object__NewLatin1Region("fp1", 4, 0, 3);
  _c80 = Object__NewLatin1Region("fp2", 4, 0, 3);
  _c81 = Object__NewLatin1Region("fp3", 4, 0, 3);
  _c82 = Object__NewLatin1Region("fp4", 4, 0, 3);
  _c83 = Object__NewLatin1Region("fp5", 4, 0, 3);
  _c84 = Object__NewLatin1Region("fp6", 4, 0, 3);
  _c85 = Object__NewLatin1Region("fp7", 4, 0, 3);
  _c86 = Object__NewLatin1Region("???", 4, 0, 3);
  _c87 = Object__NewLatin1Char(58u);
  _c88 = Object__NewLatin1Region(":Indirect", 10, 0, 9);
  _c89 = Object__NewLatin1Region("", 1, 0, 0);
  _c90 = Object__NewLatin1Char(47u);
  _c91 = Object__NewLatin1Char(61u);
  _c92 = Object__NewLatin1Char(40u);
  _c93 = Object__NewLatin1Char(46u);
  _c94 = Object__NewLatin1Char(41u);
  _c95 = Object__NewLatin1Char(40u);
  _c96 = Object__NewLatin1Char(41u);
  _c97 = Object__NewLatin1Char(123u);
  _c98 = Object__NewLatin1Char(125u);
  _c99 = Object__NewLatin1Region("NIL", 4, 0, 3);
  _c100 = Object__NewLatin1Region("_mid", 5, 0, 4);
  _c101 = Object__NewLatin1Region("adr(\"", 6, 0, 5);
  _c102 = Object__NewLatin1Region("\")", 3, 0, 2);
  _c103 = Object__NewLatin1Region("adr(\"", 6, 0, 5);
  _c104 = Object__NewLatin1Region("\")", 3, 0, 2);
  _c105 = Object__NewLatin1Region("adr(", 5, 0, 4);
  _c106 = Object__NewLatin1Char(41u);
  _c107 = Object__NewLatin1Region("offset(", 8, 0, 7);
  _c108 = Object__NewLatin1Char(41u);
  _c109 = Object__NewLatin1Region("adr(", 5, 0, 4);
  _c110 = Object__NewLatin1Char(41u);
  _c111 = Object__NewLatin1Region("offset(.)", 10, 0, 9);
  _c112 = Object__NewLatin1Char(34u);
  _c113 = Object__NewLatin1Char(34u);
  _c114 = Object__NewLatin1Region("heap", 5, 0, 4);
  _c115 = Object__NewLatin1Region("PROCEDURE ", 11, 0, 10);
  _c116 = Object__NewLatin1Region("MODULE_BODY", 12, 0, 11);
  _c117 = Object__NewLatin1Region(", ", 3, 0, 2);
  _c118 = Object__NewLatin1Region(": ", 3, 0, 2);

  return;
  ;
}

/* --- */
