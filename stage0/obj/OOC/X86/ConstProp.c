#include <OOC/X86/ConstProp.d>
#include <__oo2c.h>
#include <setjmp.h>

static OOC_X86_SSA__Result OOC_X86_ConstProp__ComputeConst(OOC_X86_SSA__FunctionBlock pb, OOC_X86_SSA__Instr instr) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  Object_Boxed__Object v;
  OOC_X86_SSA__Result arg1;
  Object_Boxed__Object val1;
  OOC_X86_SSA__Result arg2;
  Object_Boxed__Object val2;
  Object_BigInt__BigInt _i1;
  Object_BigInt__BigInt _i2;

  i0 = (OOC_INT32)instr;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 531))+20);
  i1 = i1==16;
  if (i1) goto l41;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 841))+20);
  i1 = i1==38;
  if (i1) goto l39;
  i1 = OOC_X86_SSA__InstrDesc_SizeOpndList((OOC_X86_SSA__Instr)i0);
  i1 = i1>=2;
  if (!i1) goto l49;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 1009));
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 1018));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 1022))+20);
  i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 1030)))), &_td_OOC_X86_SSA__ResultDesc, 1030);
  arg1 = (OOC_X86_SSA__Result)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 1057))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 1063))+28);
  i2 = _check_pointer(i2, 1074);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(0, i3, OOC_UINT8, 1074))*4);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 1080)))), &_td_OOC_X86_SSA__ConstDesc, 1080)), 1086));
  val1 = (Object_Boxed__Object)i2;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 1113));
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 1122))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 1131));
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 1135))+20);
  i3 = _type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 1143)))), &_td_OOC_X86_SSA__ResultDesc, 1143);
  arg2 = (OOC_X86_SSA__Result)i3;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 1170))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 1176))+28);
  i3 = _check_pointer(i3, 1187);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(0, i4, OOC_UINT8, 1187))*4);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 1193)))), &_td_OOC_X86_SSA__ConstDesc, 1193)), 1199));
  val2 = (Object_Boxed__Object)i3;
  v = (Object_Boxed__Object)0;
  i1 = *(OOC_INT8*)((_check_pointer(i1, 1245))+12);
  switch (i1) {
  case 1 ... 9:
    i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 1303)))), &_td_Object_BigInt__BigIntDesc);
    if (i1) goto l11;
    i1=0u;
    goto l13;
l11:
    i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 1329)))), &_td_Object_BigInt__BigIntDesc);
    
l13:
    if (i1) goto l15;
    i1=0;
    goto l30;
l15:
    i1 = _type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 1456)))), &_td_Object_BigInt__BigIntDesc, 1456);
    _i1 = (Object_BigInt__BigInt)i1;
    i2 = _type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 1493)))), &_td_Object_BigInt__BigIntDesc, 1493);
    _i2 = (Object_BigInt__BigInt)i2;
    i3 = *(OOC_INT8*)((_check_pointer(i0, 1533))+20);
    switch (i3) {
    case 1:
      i1 = (OOC_INT32)Object_BigInt__BigIntDesc_Add((Object_BigInt__BigInt)i1, (Object_BigInt__BigInt)i2);
      v = (Object_Boxed__Object)i1;
      
      goto l30;
    case 2:
      i1 = (OOC_INT32)Object_BigInt__BigIntDesc_Sub((Object_BigInt__BigInt)i1, (Object_BigInt__BigInt)i2);
      v = (Object_Boxed__Object)i1;
      
      goto l30;
    case 3:
      i1 = (OOC_INT32)Object_BigInt__BigIntDesc_Mul((Object_BigInt__BigInt)i1, (Object_BigInt__BigInt)i2);
      v = (Object_Boxed__Object)i1;
      
      goto l30;
    case 9:
      i1 = Object_BigInt__BigIntDesc_Cmp((Object_BigInt__BigInt)i1, (Object__Object)i2);
      i1 = (OOC_INT32)Object_Boxed__NewBoolean((i1==0));
      v = (Object_Boxed__Object)i1;
      
      goto l30;
    case 10:
      i1 = Object_BigInt__BigIntDesc_Cmp((Object_BigInt__BigInt)i1, (Object__Object)i2);
      i1 = (OOC_INT32)Object_Boxed__NewBoolean((i1!=0));
      v = (Object_Boxed__Object)i1;
      
      goto l30;
    case 12:
      i1 = Object_BigInt__BigIntDesc_Cmp((Object_BigInt__BigInt)i1, (Object__Object)i2);
      i1 = (OOC_INT32)Object_Boxed__NewBoolean((i1<=0));
      v = (Object_Boxed__Object)i1;
      
      goto l30;
    case 11:
      i1 = Object_BigInt__BigIntDesc_Cmp((Object_BigInt__BigInt)i1, (Object__Object)i2);
      i1 = (OOC_INT32)Object_Boxed__NewBoolean((i1<0));
      v = (Object_Boxed__Object)i1;
      
      goto l30;
    case 14:
      i1 = Object_BigInt__BigIntDesc_Cmp((Object_BigInt__BigInt)i1, (Object__Object)i2);
      i1 = (OOC_INT32)Object_Boxed__NewBoolean((i1>=0));
      v = (Object_Boxed__Object)i1;
      
      goto l30;
    case 13:
      i1 = Object_BigInt__BigIntDesc_Cmp((Object_BigInt__BigInt)i1, (Object__Object)i2);
      i1 = (OOC_INT32)Object_Boxed__NewBoolean((i1>0));
      v = (Object_Boxed__Object)i1;
      
      goto l30;
    default:
      _failed_case(i3, 1523);
      i1=0;
      goto l30;
    }
    /* goto: unreachable */
  default:
    i1=0;
    goto l30;
  }
l30:
  i2 = i1!=0;
  if (!i2) goto l49;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2360)))), &_td_Object_Boxed__BooleanDesc);
  if (i2) goto l35;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2513))+4);
  i0 = *(OOC_INT8*)((_check_pointer(i0, 2524))+12);
  i2 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Const.baseTypes[0]);
  OOC_X86_SSA__ConstDesc_INIT((OOC_X86_SSA__Const)i2, (Object_Boxed__Object)i1, (-1));
  i1 = (OOC_INT32)pb;
  i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConstType((OOC_X86_SSA__Block)i1, (OOC_X86_SSA__Const)i2, i0);
  return (OOC_X86_SSA__Result)i0;
  goto l49;
l35:
  i0 = *(OOC_UINT8*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2424)))), &_td_Object_Boxed__BooleanDesc, 2424)), 2432));
  i1 = (OOC_INT32)pb;
  i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConstBool((OOC_X86_SSA__Block)i1, i0);
  return (OOC_X86_SSA__Result)i0;
  goto l49;
l39:
  return (OOC_X86_SSA__Result)0;
  goto l49;
l41:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 574));
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 583));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 587))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 593))+28);
  i1 = _check_pointer(i1, 604);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 604))*4);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 610)))), &_td_OOC_X86_SSA__ConstDesc, 610)), 616));
  v = (Object_Boxed__Object)i1;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 636)))), &_td_Object_BigInt__BigIntDesc);
  if (i2) goto l44;
  i2=0u;
  goto l46;
l44:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 662))+4);
  i2 = *(OOC_INT8*)((_check_pointer(i2, 673))+12);
  i2 = i2<10;
  
l46:
  if (!i2) goto l49;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 795))+4);
  i0 = *(OOC_INT8*)((_check_pointer(i0, 806))+12);
  i2 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Const.baseTypes[0]);
  OOC_X86_SSA__ConstDesc_INIT((OOC_X86_SSA__Const)i2, (Object_Boxed__Object)i1, (-1));
  i1 = (OOC_INT32)pb;
  i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConstType((OOC_X86_SSA__Block)i1, (OOC_X86_SSA__Const)i2, i0);
  return (OOC_X86_SSA__Result)i0;
l49:
  return (OOC_X86_SSA__Result)0;
  ;
}

void OOC_X86_ConstProp__Transform(OOC_X86_SSA__FunctionBlock pb) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_X86_SSA__Instr instr;
  OOC_X86_ConstProp__Worklist worklist;
  OOC_X86_SSA__Node v;
  auto void OOC_X86_ConstProp__Transform_AddToWorklist(OOC_X86_SSA__Instr instr);
  auto void OOC_X86_ConstProp__Transform_SetInfo(OOC_X86_SSA__Instr instr, OOC_X86_SSA__Result info);
  auto void OOC_X86_ConstProp__Transform_AddUsesToWorklist(OOC_X86_SSA__Result res);
  auto void OOC_X86_ConstProp__Transform_UpdateInfo(OOC_X86_SSA__Instr instr, OOC_X86_SSA__Result info);
  auto void OOC_X86_ConstProp__Transform_ClassifyInstr(OOC_X86_SSA__Instr instr);
    
    void OOC_X86_ConstProp__Transform_AddToWorklist(OOC_X86_SSA__Instr instr) {
      register OOC_INT32 i0,i1,i2;
      OOC_X86_ConstProp__Worklist wl;

      i0 = (OOC_INT32)instr;
      i1 = *(OOC_INT32*)((_check_pointer(i0, 2868))+44);
      i1 = i1==0;
      if (!i1) goto l4;
      *(OOC_INT32*)((_check_pointer(i0, 2899))+44) = 1;
      i1 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_ConstProp__Worklist.baseTypes[0]);
      wl = (OOC_X86_ConstProp__Worklist)i1;
      i2 = (OOC_INT32)worklist;
      *(OOC_INT32*)(_check_pointer(i1, 2950)) = i2;
      *(OOC_INT32*)((_check_pointer(i1, 2979))+4) = i0;
      worklist = (OOC_X86_ConstProp__Worklist)i1;
l4:
      return;
      ;
    }

    
    void OOC_X86_ConstProp__Transform_SetInfo(OOC_X86_SSA__Instr instr, OOC_X86_SSA__Result info) {
      register OOC_INT32 i0,i1,i2;
      OOC_X86_SSA__Result res;

      i0 = (OOC_INT32)info;
      i1 = (OOC_INT32)instr;
      i2 = i0==(OOC_INT32)0;
      if (i2) goto l3;
      i2 = (OOC_INT32)OOC_X86_ConstProp__notConstant;
      i2 = i0==i2;
      
      goto l5;
l3:
      i2=1u;
l5:
      if (i2) goto l7;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3272))+4);
      *(OOC_INT32*)((_check_pointer(i1, 3259))+40) = i2;
      goto l8;
l7:
      *(OOC_INT32*)((_check_pointer(i1, 3220))+40) = i0;
l8:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3309))+4);
      res = (OOC_X86_SSA__Result)i1;
      i2 = i1!=(OOC_INT32)0;
      if (!i2) goto l16;
l11_loop:
      *(OOC_INT32*)((_check_pointer(i1, 3360))+20) = i0;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 3393));
      res = (OOC_X86_SSA__Result)i1;
      i2 = i1!=(OOC_INT32)0;
      if (i2) goto l11_loop;
l16:
      return;
      ;
    }

    
    void OOC_X86_ConstProp__Transform_AddUsesToWorklist(OOC_X86_SSA__Result res) {
      register OOC_INT32 i0,i1,i2;
      OOC_X86_SSA__Opnd use;
      OOC_X86_SSA__Instr useInstr;

      i0 = (OOC_INT32)res;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3559))+8);
      use = (OOC_X86_SSA__Opnd)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l11;
l3_loop:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3619))+8);
      useInstr = (OOC_X86_SSA__Instr)i1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3647))+40);
      i2 = i2==(OOC_INT32)0;
      if (!i2) goto l6;
      OOC_X86_ConstProp__Transform_AddToWorklist((OOC_X86_SSA__Instr)i1);
l6:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3740))+12);
      use = (OOC_X86_SSA__Opnd)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l3_loop;
l11:
      return;
      ;
    }

    
    void OOC_X86_ConstProp__Transform_UpdateInfo(OOC_X86_SSA__Instr instr, OOC_X86_SSA__Result info) {
      register OOC_INT32 i0,i1,i2;
      OOC_X86_SSA__Result res;

      i0 = (OOC_INT32)info;
      i1 = (OOC_INT32)instr;
      i2 = i0==(OOC_INT32)0;
      if (i2) goto l3;
      i2 = (OOC_INT32)OOC_X86_ConstProp__notConstant;
      i2 = i0==i2;
      
      goto l5;
l3:
      i2=1u;
l5:
      if (i2) goto l7;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4011))+4);
      *(OOC_INT32*)((_check_pointer(i1, 3998))+40) = i2;
      goto l8;
l7:
      *(OOC_INT32*)((_check_pointer(i1, 3959))+40) = i0;
l8:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4048))+4);
      res = (OOC_X86_SSA__Result)i1;
      i2 = i1!=(OOC_INT32)0;
      if (!i2) goto l16;
l11_loop:
      *(OOC_INT32*)((_check_pointer(i1, 4099))+20) = i0;
      OOC_X86_ConstProp__Transform_AddUsesToWorklist((OOC_X86_SSA__Result)i1);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 4164));
      res = (OOC_X86_SSA__Result)i1;
      i2 = i1!=(OOC_INT32)0;
      if (i2) goto l11_loop;
l16:
      return;
      ;
    }

    
    void OOC_X86_ConstProp__Transform_ClassifyInstr(OOC_X86_SSA__Instr instr) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      OOC_X86_SSA__Node state;
      OOC_X86_SSA__Opnd opnd;
      OOC_X86_SSA__Result _const;

      i0 = (OOC_INT32)instr;
      state = (OOC_X86_SSA__Node)i0;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4453));
      i2 = (OOC_INT32)OOC_X86_ConstProp__notConstant;
      opnd = (OOC_X86_SSA__Opnd)i1;
      i3=i0;
l1_loop:
      i4 = i1==0;
      if (i4) goto l13;
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 4539));
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 4543))+20);
      i4 = i4==0;
      if (i4) goto l10;
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 4622));
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 4626))+20);
      i4 = i4==i2;
      if (i4) goto l9;
      goto l12;
l9:
      state = (OOC_X86_SSA__Node)i2;
      i1=i2;
      goto l14;
l10:
      state = (OOC_X86_SSA__Node)0;
      i3=0;
l12:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4733))+4);
      opnd = (OOC_X86_SSA__Opnd)i1;
      
      goto l1_loop;
l13:
      i1=i3;
l14:
      i3 = i1==i0;
      if (i3) goto l20;
      i1 = i1==i2;
      if (!i1) goto l25;
      OOC_X86_ConstProp__Transform_UpdateInfo((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Result)i2);
      goto l25;
l20:
      i1 = (OOC_INT32)pb;
      i1 = (OOC_INT32)OOC_X86_ConstProp__ComputeConst((OOC_X86_SSA__FunctionBlock)i1, (OOC_X86_SSA__Instr)i0);
      _const = (OOC_X86_SSA__Result)i1;
      i2 = i1==0;
      if (i2) goto l23;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5055))+4);
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 5066));
      _assert((i2==0), 127, 5043);
      OOC_X86_ConstProp__Transform_UpdateInfo((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Result)i1);
      goto l25;
l23:
      i1 = (OOC_INT32)OOC_X86_ConstProp__notConstant;
      OOC_X86_ConstProp__Transform_UpdateInfo((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Result)i1);
l25:
      return;
      ;
    }


  i0 = (OOC_INT32)pb;
  i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AllInstructions((OOC_X86_SSA__Block)i0, (-1));
  i1 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i0)), OOC_X86_SSA__IterBlockAllInstructionsDesc_Next);
  i2 = OOC_TBCALL(i1,OOC_X86_SSA__IterBlockAllInstructionsDesc_Next)((OOC_X86_SSA__IterBlockAllInstructions)i0, (void*)(OOC_INT32)&instr);
  if (!i2) goto l24;
l3_loop:
  i2 = (OOC_INT32)instr;
  *(OOC_INT32*)((_check_pointer(i2, 5643))+44) = 0;
  i3 = *(OOC_INT8*)((_check_pointer(i2, 5673))+20);
  i3 = i3==0;
  if (i3) goto l14;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 6029))+32);
  i3 = i3!=(OOC_INT32)0;
  if (i3) goto l8;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 6057))+36);
  i3 = i3!=(OOC_INT32)0;
  
  goto l10;
l8:
  i3=1u;
l10:
  if (i3) goto l12;
  OOC_X86_ConstProp__Transform_SetInfo((OOC_X86_SSA__Instr)i2, (OOC_X86_SSA__Result)(OOC_INT32)0);
  goto l19;
l12:
  i3 = (OOC_INT32)OOC_X86_ConstProp__notConstant;
  OOC_X86_ConstProp__Transform_SetInfo((OOC_X86_SSA__Instr)i2, (OOC_X86_SSA__Result)i3);
  goto l19;
l14:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 5714))+28);
  i3 = _check_pointer(i3, 5725);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(0, i4, OOC_UINT8, 5725))*4);
  i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 5729)))), &_td_OOC_X86_SSA__ConstDesc);
  if (i3) goto l17;
  i3 = (OOC_INT32)OOC_X86_ConstProp__notConstant;
  OOC_X86_ConstProp__Transform_SetInfo((OOC_X86_SSA__Instr)i2, (OOC_X86_SSA__Result)i3);
  goto l19;
l17:
  *(OOC_INT32*)((_check_pointer(i2, 5761))+40) = i2;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 5792))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 5817))+4);
  *(OOC_INT32*)((_check_pointer(i3, 5803))+20) = i4;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 5852))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 5863));
  _assert((i2==(OOC_INT32)0), 127, 5840);
l19:
  i2 = OOC_TBCALL(i1,OOC_X86_SSA__IterBlockAllInstructionsDesc_Next)((OOC_X86_SSA__IterBlockAllInstructions)i0, (void*)(OOC_INT32)&instr);
  if (i2) goto l3_loop;
l24:
  i0 = (OOC_INT32)pb;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6337))+60);
  i1 = (OOC_INT32)OOC_X86_ConstProp__notConstant;
  OOC_X86_ConstProp__Transform_SetInfo((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Result)i1);
  worklist = (OOC_X86_ConstProp__Worklist)(OOC_INT32)0;
  i0 = (OOC_INT32)pb;
  i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AllInstructions((OOC_X86_SSA__Block)i0, (-1));
  i1 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i0)), OOC_X86_SSA__IterBlockAllInstructionsDesc_Next);
  i2 = OOC_TBCALL(i1,OOC_X86_SSA__IterBlockAllInstructionsDesc_Next)((OOC_X86_SSA__IterBlockAllInstructions)i0, (void*)(OOC_INT32)&instr);
  if (!i2) goto l38;
l26_loop:
  i2 = (OOC_INT32)instr;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 6486))+40);
  i3 = i3==(OOC_INT32)0;
  if (i3) goto l29;
  i3=0u;
  goto l31;
l29:
  i3 = *(OOC_INT32*)((_check_pointer(i2, 6516))+44);
  i3 = i3==0;
  
l31:
  if (!i3) goto l33;
  OOC_X86_ConstProp__Transform_ClassifyInstr((OOC_X86_SSA__Instr)i2);
l33:
  i2 = OOC_TBCALL(i1,OOC_X86_SSA__IterBlockAllInstructionsDesc_Next)((OOC_X86_SSA__IterBlockAllInstructions)i0, (void*)(OOC_INT32)&instr);
  if (i2) goto l26_loop;
l38:
  i0 = (OOC_INT32)worklist;
  i0 = i0!=(OOC_INT32)0;
  if (!i0) goto l46;
l41_loop:
  i0 = (OOC_INT32)worklist;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6825))+4);
  instr = (OOC_X86_SSA__Instr)i1;
  *(OOC_INT32*)((_check_pointer(i1, 6844))+44) = 0;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6884));
  worklist = (OOC_X86_ConstProp__Worklist)i0;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6910))+40);
  _assert((i0==(OOC_INT32)0), 127, 6897);
  OOC_X86_ConstProp__Transform_ClassifyInstr((OOC_X86_SSA__Instr)i1);
  i0 = (OOC_INT32)worklist;
  i0 = i0!=(OOC_INT32)0;
  if (i0) goto l41_loop;
l46:
  i0 = (OOC_INT32)pb;
  i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AllInstructions((OOC_X86_SSA__Block)i0, (-1));
  i1 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i0)), OOC_X86_SSA__IterBlockAllInstructionsDesc_Next);
  i2 = OOC_TBCALL(i1,OOC_X86_SSA__IterBlockAllInstructionsDesc_Next)((OOC_X86_SSA__IterBlockAllInstructions)i0, (void*)(OOC_INT32)&instr);
  if (!i2) goto l65;
l49_loop:
  i2 = (OOC_INT32)instr;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7100))+40);
  v = (OOC_X86_SSA__Node)i3;
  i4 = i3!=(OOC_INT32)0;
  if (i4) goto l52;
  i4=0u;
  goto l54;
l52:
  i4 = (OOC_INT32)OOC_X86_ConstProp__notConstant;
  i4 = i3!=i4;
  
l54:
  if (i4) goto l56;
  i3=0u;
  goto l58;
l56:
  i3 = i3!=i2;
  
l58:
  if (!i3) goto l60;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7216))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 7227))+20);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7187))+4);
  OOC_X86_SSA__ResultDesc_ReplaceUses((OOC_X86_SSA__Result)i2, (OOC_X86_SSA__Result)(_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 7235)))), &_td_OOC_X86_SSA__ResultDesc, 7235)));
l60:
  i2 = OOC_TBCALL(i1,OOC_X86_SSA__IterBlockAllInstructionsDesc_Next)((OOC_X86_SSA__IterBlockAllInstructions)i0, (void*)(OOC_INT32)&instr);
  if (i2) goto l49_loop;
l65:
  return;
  ;
}

void OOC_OOC_X86_ConstProp_init(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Result.baseTypes[0]);
  OOC_X86_SSA__ResultDesc_INIT((OOC_X86_SSA__Result)i0, (-1));
  OOC_X86_ConstProp__notConstant = (OOC_X86_SSA__Result)i0;
  return;
  ;
}

/* --- */
