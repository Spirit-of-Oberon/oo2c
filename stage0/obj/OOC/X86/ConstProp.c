#include <OOC/X86/ConstProp.d>
#include <__oo2c.h>
#include <setjmp.h>

static OOC_X86_SSA__Result OOC_X86_ConstProp__ComputeConst(OOC_X86_SSA__FunctionBlock pb, OOC_X86_SSA__Instr instr) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_X86_SSA__Result arg1;
  Object__Object v;
  Object__Object val1;
  OOC_X86_SSA__Result arg2;
  Object__Object val2;
  Object_BigInt__BigInt _i1;
  Object_BigInt__BigInt _i2;

  i0 = (OOC_INT32)instr;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 539))+20);
  i1 = i1==22;
  if (i1) goto l42;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 884))+20);
  i1 = i1==50;
  if (i1) goto l40;
  i1 = OOC_X86_SSA__InstrDesc_SizeOpndList((OOC_X86_SSA__Instr)i0);
  i1 = i1>=2;
  if (!i1) goto l50;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 1052));
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 1061));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 1065))+20);
  i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 1073)))), &_td_OOC_X86_SSA__ResultDesc, 1073);
  arg1 = (OOC_X86_SSA__Result)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 1100))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 1106))+28);
  i2 = _check_pointer(i2, 1117);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(0, i3, OOC_UINT8, 1117))*4);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 1123)))), &_td_OOC_X86_SSA__ConstDesc, 1123)), 1129));
  val1 = (Object__Object)i2;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 1156));
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 1165))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 1174));
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 1178))+20);
  i3 = _type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 1186)))), &_td_OOC_X86_SSA__ResultDesc, 1186);
  arg2 = (OOC_X86_SSA__Result)i3;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 1213))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 1219))+28);
  i3 = _check_pointer(i3, 1230);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(0, i4, OOC_UINT8, 1230))*4);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 1236)))), &_td_OOC_X86_SSA__ConstDesc, 1236)), 1242));
  val2 = (Object__Object)i3;
  v = (Object__Object)0;
  i1 = *(OOC_INT8*)((_check_pointer(i1, 1288))+12);
  switch (i1) {
  case 1 ... 9:
    i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 1346)))), &_td_Object_BigInt__BigIntDesc);
    if (i1) goto l11;
    i1=0u;
    goto l13;
l11:
    i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 1372)))), &_td_Object_BigInt__BigIntDesc);
    
l13:
    if (i1) goto l15;
    i1=0;
    goto l31;
l15:
    i1 = _type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 1499)))), &_td_Object_BigInt__BigIntDesc, 1499);
    _i1 = (Object_BigInt__BigInt)i1;
    i2 = _type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 1536)))), &_td_Object_BigInt__BigIntDesc, 1536);
    _i2 = (Object_BigInt__BigInt)i2;
    i3 = *(OOC_INT8*)((_check_pointer(i0, 1576))+20);
    switch (i3) {
    case 1:
      i1 = (OOC_INT32)Object_BigInt__BigIntDesc_Add((Object_BigInt__BigInt)i1, (Object_BigInt__BigInt)i2);
      v = (Object__Object)i1;
      
      goto l31;
    case 2:
      i1 = (OOC_INT32)Object_BigInt__BigIntDesc_Sub((Object_BigInt__BigInt)i1, (Object_BigInt__BigInt)i2);
      v = (Object__Object)i1;
      
      goto l31;
    case 3:
      i1 = (OOC_INT32)Object_BigInt__BigIntDesc_Mul((Object_BigInt__BigInt)i1, (Object_BigInt__BigInt)i2);
      v = (Object__Object)i1;
      
      goto l31;
    case 6:
    case 7:
    case 8:
    case 9:
    case 11:
    case 10:
      v = (Object__Object)0;
      i1=0;
      goto l31;
    case 13:
      i1 = Object_BigInt__BigIntDesc_Cmp((Object_BigInt__BigInt)i1, (Object__Object)i2);
      i1 = (OOC_INT32)Object_Boxed__NewBoolean((i1==0));
      v = (Object__Object)i1;
      
      goto l31;
    case 14:
      i1 = Object_BigInt__BigIntDesc_Cmp((Object_BigInt__BigInt)i1, (Object__Object)i2);
      i1 = (OOC_INT32)Object_Boxed__NewBoolean((i1!=0));
      v = (Object__Object)i1;
      
      goto l31;
    case 16:
      i1 = Object_BigInt__BigIntDesc_Cmp((Object_BigInt__BigInt)i1, (Object__Object)i2);
      i1 = (OOC_INT32)Object_Boxed__NewBoolean((i1<=0));
      v = (Object__Object)i1;
      
      goto l31;
    case 15:
      i1 = Object_BigInt__BigIntDesc_Cmp((Object_BigInt__BigInt)i1, (Object__Object)i2);
      i1 = (OOC_INT32)Object_Boxed__NewBoolean((i1<0));
      v = (Object__Object)i1;
      
      goto l31;
    case 18:
      i1 = Object_BigInt__BigIntDesc_Cmp((Object_BigInt__BigInt)i1, (Object__Object)i2);
      i1 = (OOC_INT32)Object_Boxed__NewBoolean((i1>=0));
      v = (Object__Object)i1;
      
      goto l31;
    case 17:
      i1 = Object_BigInt__BigIntDesc_Cmp((Object_BigInt__BigInt)i1, (Object__Object)i2);
      i1 = (OOC_INT32)Object_Boxed__NewBoolean((i1>0));
      v = (Object__Object)i1;
      
      goto l31;
    default:
      _failed_case(i3, 1566);
      i1=0;
      goto l31;
    }
    /* goto: unreachable */
  default:
    i1=0;
    goto l31;
  }
l31:
  i2 = i1!=0;
  if (!i2) goto l50;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2527)))), &_td_Object_Boxed__BooleanDesc);
  if (i2) goto l36;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2680))+4);
  i0 = *(OOC_INT8*)((_check_pointer(i0, 2691))+12);
  i2 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Const.baseTypes[0]);
  OOC_X86_SSA__ConstDesc_INIT((OOC_X86_SSA__Const)i2, (Object__Object)i1, (-1));
  i1 = (OOC_INT32)pb;
  i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConstType((OOC_X86_SSA__Block)i1, (OOC_X86_SSA__Const)i2, i0);
  return (OOC_X86_SSA__Result)i0;
  goto l50;
l36:
  i0 = *(OOC_UINT8*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2591)))), &_td_Object_Boxed__BooleanDesc, 2591)), 2599));
  i1 = (OOC_INT32)pb;
  i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConstBool((OOC_X86_SSA__Block)i1, i0);
  return (OOC_X86_SSA__Result)i0;
  goto l50;
l40:
  return (OOC_X86_SSA__Result)0;
  goto l50;
l42:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 585));
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 594));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 598))+20);
  i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 606)))), &_td_OOC_X86_SSA__ResultDesc, 606);
  arg1 = (OOC_X86_SSA__Result)i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 630))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 636))+28);
  i1 = _check_pointer(i1, 647);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 647))*4);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 653)))), &_td_OOC_X86_SSA__ConstDesc, 653)), 659));
  v = (Object__Object)i1;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 679)))), &_td_Object_BigInt__BigIntDesc);
  if (i2) goto l45;
  i2=0u;
  goto l47;
l45:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 705))+4);
  i2 = *(OOC_INT8*)((_check_pointer(i2, 716))+12);
  i2 = i2<10;
  
l47:
  if (!i2) goto l50;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 838))+4);
  i0 = *(OOC_INT8*)((_check_pointer(i0, 849))+12);
  i2 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Const.baseTypes[0]);
  OOC_X86_SSA__ConstDesc_INIT((OOC_X86_SSA__Const)i2, (Object__Object)i1, (-1));
  i1 = (OOC_INT32)pb;
  i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConstType((OOC_X86_SSA__Block)i1, (OOC_X86_SSA__Const)i2, i0);
  return (OOC_X86_SSA__Result)i0;
l50:
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
      i1 = *(OOC_INT32*)((_check_pointer(i0, 3035))+44);
      i1 = i1==0;
      if (!i1) goto l4;
      *(OOC_INT32*)((_check_pointer(i0, 3066))+44) = 1;
      i1 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_ConstProp__Worklist.baseTypes[0]);
      wl = (OOC_X86_ConstProp__Worklist)i1;
      i2 = (OOC_INT32)worklist;
      *(OOC_INT32*)(_check_pointer(i1, 3117)) = i2;
      *(OOC_INT32*)((_check_pointer(i1, 3146))+4) = i0;
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
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3439))+4);
      *(OOC_INT32*)((_check_pointer(i1, 3426))+40) = i2;
      goto l8;
l7:
      *(OOC_INT32*)((_check_pointer(i1, 3387))+40) = i0;
l8:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3476))+4);
      res = (OOC_X86_SSA__Result)i1;
      i2 = i1!=(OOC_INT32)0;
      if (!i2) goto l16;
l11_loop:
      *(OOC_INT32*)((_check_pointer(i1, 3527))+20) = i0;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 3560));
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
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3726))+8);
      use = (OOC_X86_SSA__Opnd)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l11;
l3_loop:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3786))+8);
      useInstr = (OOC_X86_SSA__Instr)i1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3814))+40);
      i2 = i2==(OOC_INT32)0;
      if (!i2) goto l6;
      OOC_X86_ConstProp__Transform_AddToWorklist((OOC_X86_SSA__Instr)i1);
l6:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3907))+12);
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
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4178))+4);
      *(OOC_INT32*)((_check_pointer(i1, 4165))+40) = i2;
      goto l8;
l7:
      *(OOC_INT32*)((_check_pointer(i1, 4126))+40) = i0;
l8:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4215))+4);
      res = (OOC_X86_SSA__Result)i1;
      i2 = i1!=(OOC_INT32)0;
      if (!i2) goto l16;
l11_loop:
      *(OOC_INT32*)((_check_pointer(i1, 4266))+20) = i0;
      OOC_X86_ConstProp__Transform_AddUsesToWorklist((OOC_X86_SSA__Result)i1);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 4331));
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
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4620));
      i2 = (OOC_INT32)OOC_X86_ConstProp__notConstant;
      opnd = (OOC_X86_SSA__Opnd)i1;
      i3=i0;
l1_loop:
      i4 = i1==0;
      if (i4) goto l13;
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 4706));
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 4710))+20);
      i4 = i4==0;
      if (i4) goto l10;
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 4789));
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 4793))+20);
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
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4900))+4);
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
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5222))+4);
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 5233));
      _assert((i2==0), 127, 5210);
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
  *(OOC_INT32*)((_check_pointer(i2, 5810))+44) = 0;
  i3 = *(OOC_INT8*)((_check_pointer(i2, 5840))+20);
  i3 = i3==0;
  if (i3) goto l14;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 6196))+32);
  i3 = i3!=(OOC_INT32)0;
  if (i3) goto l8;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 6224))+36);
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
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 5881))+28);
  i3 = _check_pointer(i3, 5892);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(0, i4, OOC_UINT8, 5892))*4);
  i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 5896)))), &_td_OOC_X86_SSA__ConstDesc);
  if (i3) goto l17;
  i3 = (OOC_INT32)OOC_X86_ConstProp__notConstant;
  OOC_X86_ConstProp__Transform_SetInfo((OOC_X86_SSA__Instr)i2, (OOC_X86_SSA__Result)i3);
  goto l19;
l17:
  *(OOC_INT32*)((_check_pointer(i2, 5928))+40) = i2;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 5959))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 5984))+4);
  *(OOC_INT32*)((_check_pointer(i3, 5970))+20) = i4;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 6019))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 6030));
  _assert((i2==(OOC_INT32)0), 127, 6007);
l19:
  i2 = OOC_TBCALL(i1,OOC_X86_SSA__IterBlockAllInstructionsDesc_Next)((OOC_X86_SSA__IterBlockAllInstructions)i0, (void*)(OOC_INT32)&instr);
  if (i2) goto l3_loop;
l24:
  i0 = (OOC_INT32)pb;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6504))+60);
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
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 6653))+40);
  i3 = i3==(OOC_INT32)0;
  if (i3) goto l29;
  i3=0u;
  goto l31;
l29:
  i3 = *(OOC_INT32*)((_check_pointer(i2, 6683))+44);
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
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6992))+4);
  instr = (OOC_X86_SSA__Instr)i1;
  *(OOC_INT32*)((_check_pointer(i1, 7011))+44) = 0;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7051));
  worklist = (OOC_X86_ConstProp__Worklist)i0;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 7077))+40);
  _assert((i0==(OOC_INT32)0), 127, 7064);
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
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7267))+40);
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
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7383))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 7394))+20);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7354))+4);
  OOC_X86_SSA__ResultDesc_ReplaceUses((OOC_X86_SSA__Result)i2, (OOC_X86_SSA__Result)(_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 7402)))), &_td_OOC_X86_SSA__ResultDesc, 7402)));
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
