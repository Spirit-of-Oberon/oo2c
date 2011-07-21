#include <OOC/X86/Machine.d>
#include <__oo2c.h>
#include <setjmp.h>

OOC_X86_SSA__Opnd OOC_X86_Machine__InOutOpnd(OOC_X86_SSA__Instr instr) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)instr;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 401))+20);
  switch (i1) {
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
  case 11:
  case 10:
  case 20:
  case 21:
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 559));
    return (OOC_X86_SSA__Opnd)i0;
    goto l4;
  default:
    return (OOC_X86_SSA__Opnd)0;
    goto l4;
  }
l4:
  _failed_function(86); return 0;
  ;
}

static OOC_X86_SSA__Opnd OOC_X86_Machine__ImmediateOpnd(OOC_X86_SSA__Instr instr) {
  register OOC_INT32 i0,i1,i2;
  OOC_INT32 n;
  OOC_X86_SSA__Opnd opnd;
  auto OOC_CHAR8 OOC_X86_Machine__ImmediateOpnd_ImmediateValue(OOC_INT8 type);
    
    OOC_CHAR8 OOC_X86_Machine__ImmediateOpnd_ImmediateValue(OOC_INT8 type) {
      register OOC_INT32 i0,i1;

      i0 = type;
      i1 = i0!=10;
      if (i1) goto l3;
      i0=0u;
      goto l4;
l3:
      i0 = i0!=11;
      
l4:
      return i0;
      ;
    }


  i0 = (OOC_INT32)instr;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 1064))+20);
  switch (i1) {
  case 29:
  case 47:
    n = 0;
    goto l12;
  case 28:
    i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 1147));
    opnd = (OOC_X86_SSA__Opnd)i1;
    i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 1172));
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 1176))+4);
    i2 = *(OOC_INT8*)((_check_pointer(i2, 1182))+20);
    i2 = i2==0;
    if (i2) goto l6;
    return (OOC_X86_SSA__Opnd)0;
    goto l12;
l6:
    return (OOC_X86_SSA__Opnd)i1;
    goto l12;
  case 13:
  case 14:
  case 15:
  case 16:
  case 17:
  case 18:
  case 1:
  case 2:
  case 20:
  case 21:
  case 32:
    n = 1;
    goto l12;
  case 35:
    n = 1;
    goto l12;
  case 43:
    n = 2;
    goto l12;
  default:
    return (OOC_X86_SSA__Opnd)0;
    goto l12;
  }
l12:
  i1 = n;
  i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_NthOpnd((OOC_X86_SSA__Instr)i0, i1);
  opnd = (OOC_X86_SSA__Opnd)i0;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 1798));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 1802))+4);
  i1 = *(OOC_INT8*)((_check_pointer(i1, 1808))+20);
  i1 = i1==0;
  if (i1) goto l15;
  i1=0u;
  goto l17;
l15:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 1856));
  i1 = *(OOC_INT8*)((_check_pointer(i1, 1860))+12);
  i1 = OOC_X86_Machine__ImmediateOpnd_ImmediateValue(i1);
  
l17:
  if (i1) goto l19;
  return (OOC_X86_SSA__Opnd)0;
  goto l20;
l19:
  return (OOC_X86_SSA__Opnd)i0;
l20:
  _failed_function(634); return 0;
  ;
}

static OOC_X86_SSA__Opnd OOC_X86_Machine__MemOpnd(OOC_X86_SSA__Instr instr) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_INT8 opcode;
  OOC_X86_SSA__Opnd inout;
  OOC_X86_SSA__Opnd opnd;
  auto OOC_CHAR8 OOC_X86_Machine__MemOpnd_IsOffset(OOC_X86_SSA__Instr instr);
    
    OOC_CHAR8 OOC_X86_Machine__MemOpnd_IsOffset(OOC_X86_SSA__Instr instr) {
      register OOC_INT32 i0;

      i0 = (OOC_INT32)instr;
      i0 = *(OOC_INT8*)((_check_pointer(i0, 2240))+20);
      return (i0==1);
      ;
    }


  i0 = (OOC_INT32)instr;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 2304))+20);
  opcode = i1;
  i2 = *(OOC_INT8*)((_check_pointer(i0, 2327))+20);
  switch (i2) {
  case 35:
  case 34:
    i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2372));
    i1 = OOC_X86_SSA__OpndDesc_IsConst((OOC_X86_SSA__Opnd)i1);
    if (i1) goto l5;
    i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2409));
    i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 2418));
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2422))+4);
    i1 = OOC_X86_Machine__MemOpnd_IsOffset((OOC_X86_SSA__Instr)i1);
    
    goto l7;
l5:
    i1=1u;
l7:
    if (!i1) goto l39;
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2448));
    *(OOC_UINT8*)((_check_pointer(i0, 2457))+16) = 1u;
    goto l39;
  case 43:
  case 44:
    return (OOC_X86_SSA__Opnd)0;
    goto l39;
  default:
    i2 = (OOC_INT32)OOC_X86_Machine__InOutOpnd((OOC_X86_SSA__Instr)i0);
    inout = (OOC_X86_SSA__Opnd)i2;
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2596));
    opnd = (OOC_X86_SSA__Opnd)i0;
    i3 = 13<=i1;
    if (i3) goto l14;
    i1=0u;
    goto l16;
l14:
    i1 = i1<=18;
    
l16:
    if (i1) goto l18;
    i1=0u;
    goto l20;
l18:
    i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2670));
    i1 = *(OOC_INT8*)((_check_pointer(i1, 2674))+12);
    i1 = OOC_X86_SSA__IsFloat(i1);
    
l20:
    if (!i1) goto l23;
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2756))+4);
    opnd = (OOC_X86_SSA__Opnd)i0;
    
l23:
    i1 = i0!=0;
    if (!i1) goto l39;
l26_loop:
    i1 = i0!=i2;
    if (i1) goto l29;
    i1=0u;
    goto l31;
l29:
    i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2839));
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2843))+4);
    i1 = *(OOC_INT8*)((_check_pointer(i1, 2849))+20);
    i1 = i1==34;
    
l31:
    if (!i1) goto l33;
    return (OOC_X86_SSA__Opnd)i0;
l33:
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2927))+4);
    opnd = (OOC_X86_SSA__Opnd)i0;
    i1 = i0!=0;
    if (i1) goto l26_loop;
    goto l39;
  }
l39:
  return (OOC_X86_SSA__Opnd)0;
  ;
}

void OOC_X86_Machine__ApplyMachineModel(OOC_X86_SSA__FunctionBlock b) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT32 maxSizeCallStack;
  OOC_INT8 type;
  OOC_X86_SSA__Instr instr;
  OOC_X86_SSA__Opnd opnd;
  OOC_X86_SSA__Opnd imm;
  OOC_X86_SSA__Opnd mem;
  auto OOC_CHAR8 OOC_X86_Machine__ApplyMachineModel_IsConst(OOC_X86_SSA__Opnd opnd);
  auto void OOC_X86_Machine__ApplyMachineModel_ExpandCall(OOC_X86_SSA__Instr call);
    
    OOC_CHAR8 OOC_X86_Machine__ApplyMachineModel_IsConst(OOC_X86_SSA__Opnd opnd) {
      register OOC_INT32 i0;

      i0 = (OOC_INT32)opnd;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3505));
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3509))+4);
      i0 = *(OOC_INT8*)((_check_pointer(i0, 3515))+20);
      return (i0==0);
      ;
    }

    
    void OOC_X86_Machine__ApplyMachineModel_ExpandCall(OOC_X86_SSA__Instr call) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
      OOC_INT32 offset;
      OOC_X86_SSA__Instr memoryDep;
      OOC_X86_SSA__Result sp;
      OOC_X86_SSA__Opnd opnd;
      OOC_X86_SSA__Opnd next;
      OOC_X86_SSA__Result arg;
      OOC_X86_SSA__Instr instr;
      OOC_INT8 type;
      OOC_X86_SSA__Result res;
      OOC_X86_SSA__Dep dep;
      OOC_UINT32 clobbered;
      auto OOC_INT32 OOC_X86_Machine__ApplyMachineModel_ExpandCall_ArgSize(OOC_X86_SSA__Result arg);
        
        OOC_INT32 OOC_X86_Machine__ApplyMachineModel_ExpandCall_ArgSize(OOC_X86_SSA__Result arg) {
          register OOC_INT32 i0,i1;

          i0 = (OOC_INT32)arg;
          i0 = *(OOC_INT8*)((_check_pointer(i0, 3918))+12);
          i0 = OOC_X86_SSA__TypeSize(i0);
          i1 = i0<4;
          if (i1) goto l3;
          return i0;
          goto l4;
l3:
          return 4;
l4:
          _failed_function(3810); return 0;
          ;
        }


      offset = 0;
      i0 = (OOC_INT32)call;
      i1 = (OOC_INT32)OOC_X86_SSA__InstrDesc_GetBeforeInstr((OOC_X86_SSA__Instr)i0, 1);
      memoryDep = (OOC_X86_SSA__Instr)i1;
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4188));
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 4197))+4);
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 4206));
      sp = (OOC_X86_SSA__Result)i2;
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4230));
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 4239))+4);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 4248))+4);
      opnd = (OOC_X86_SSA__Opnd)i3;
      i4 = i3!=0;
      if (i4) goto l3;
      i1=0;
      goto l25;
l3:
      i4=0;
l4_loop:
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 4330))+4);
      next = (OOC_X86_SSA__Opnd)i5;
      i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 4361));
      arg = (OOC_X86_SSA__Result)i6;
      i7 = *(OOC_INT8*)((_check_pointer(i6, 4392))+12);
      i7 = OOC_X86_SSA__IsSigned(i7);
      if (i7) goto l7;
      i7=0u;
      goto l9;
l7:
      i7 = *(OOC_INT8*)((_check_pointer(i6, 4405))+12);
      i7 = i7<3;
      
l9:
      if (i7) goto l19;
      i7 = *(OOC_INT8*)((_check_pointer(i6, 4505))+12);
      i7 = OOC_X86_SSA__IsUnsigned(i7);
      if (i7) goto l13;
      i7=0u;
      goto l15;
l13:
      i7 = *(OOC_INT8*)((_check_pointer(i6, 4518))+12);
      i7 = i7<7;
      
l15:
      if (!i7) goto l20;
      i7 = (OOC_INT32)b;
      i6 = (OOC_INT32)OOC_X86_SSA__FunctionBlockDesc_FixType((OOC_X86_SSA__FunctionBlock)i7, (OOC_X86_SSA__Result)i6, 7);
      arg = (OOC_X86_SSA__Result)i6;
      
      goto l20;
l19:
      i7 = (OOC_INT32)b;
      i6 = (OOC_INT32)OOC_X86_SSA__FunctionBlockDesc_FixType((OOC_X86_SSA__FunctionBlock)i7, (OOC_X86_SSA__Result)i6, 3);
      arg = (OOC_X86_SSA__Result)i6;
      
l20:
      i7 = (OOC_INT32)b;
      i7 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConstLength((OOC_X86_SSA__Block)i7, i4);
      i8 = (OOC_INT32)b;
      i6 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr3((OOC_X86_SSA__Block)i8, 43, (OOC_X86_SSA__Result)i2, (OOC_X86_SSA__Result)i7, (OOC_X86_SSA__Result)i6);
      instr = (OOC_X86_SSA__Instr)i6;
      OOC_X86_SSA__InstrDesc_AddDep((OOC_X86_SSA__Instr)i6, 1, (OOC_X86_SSA__Instr)i1);
      OOC_X86_SSA__InstrDesc_AddDep((OOC_X86_SSA__Instr)i0, 1, (OOC_X86_SSA__Instr)i6);
      i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 4801));
      i6 = OOC_X86_Machine__ApplyMachineModel_ExpandCall_ArgSize((OOC_X86_SSA__Result)i6);
      i4 = i4+i6;
      offset = i4;
      OOC_X86_SSA__OpndDesc_DeleteOpnd((OOC_X86_SSA__Opnd)i3);
      opnd = (OOC_X86_SSA__Opnd)i5;
      i3 = i5!=0;
      if (!i3) goto l24;
      i3=i5;
      goto l4_loop;
l24:
      i1=i4;
l25:
      i3 = maxSizeCallStack;
      i3 = i1>i3;
      if (!i3) goto l28;
      maxSizeCallStack = i1;
l28:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4988))+4);
      i1 = i1!=0;
      if (!i1) goto l45;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5164))+4);
      i1 = *(OOC_INT8*)((_check_pointer(i1, 5175))+12);
      type = i1;
      i3 = OOC_X86_SSA__IsFloat(i1);
      if (!i3) goto l45;
      i3 = OOC_X86_SSA__TypeSize(i1);
      i4 = maxSizeCallStack;
      i3 = i3>i4;
      if (!i3) goto l35;
      i3 = OOC_X86_SSA__TypeSize(i1);
      maxSizeCallStack = i3;
l35:
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5600))+4);
      i4 = (OOC_INT32)b;
      i2 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr2((OOC_X86_SSA__Block)i4, 30, (OOC_X86_SSA__Result)i2, (OOC_X86_SSA__Result)i3);
      instr = (OOC_X86_SSA__Instr)i2;
      i1 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i2, i1);
      res = (OOC_X86_SSA__Result)i1;
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 5708));
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 5717))+4);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5668))+4);
      OOC_X86_SSA__ResultDesc_ReplaceUsesExcept((OOC_X86_SSA__Result)i4, (OOC_X86_SSA__Result)i1, (OOC_X86_SSA__Opnd)i3);
      i1 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AfterList((OOC_X86_SSA__Instr)i0, 1);
      i3 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i1)), OOC_X86_SSA__IterInstrAfterListDesc_Next);
      i4 = OOC_TBCALL(i3,OOC_X86_SSA__IterInstrAfterListDesc_Next)((OOC_X86_SSA__IterInstrAfterList)i1, (void*)(OOC_INT32)&dep);
      if (!i4) goto l43;
l38_loop:
      i4 = (OOC_INT32)dep;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 5797))+12);
      OOC_X86_SSA__InstrDesc_AddDep((OOC_X86_SSA__Instr)i4, 1, (OOC_X86_SSA__Instr)i2);
      i4 = (OOC_INT32)dep;
      OOC_X86_SSA__DepDesc_DeleteDep((OOC_X86_SSA__Dep)i4);
      i4 = OOC_TBCALL(i3,OOC_X86_SSA__IterInstrAfterListDesc_Next)((OOC_X86_SSA__IterInstrAfterList)i1, (void*)(OOC_INT32)&dep);
      if (i4) goto l38_loop;
l43:
      OOC_X86_SSA__InstrDesc_AddDep((OOC_X86_SSA__Instr)i2, 1, (OOC_X86_SSA__Instr)i0);
l45:
      clobbered = 261688u;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6066))+4);
      i1 = i1!=0;
      if (i1) goto l48;
      i1=261688u;
      goto l53;
l48:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6109))+4);
      res = (OOC_X86_SSA__Result)i1;
      i2 = *(OOC_INT8*)((_check_pointer(i1, 6137))+12);
      i2 = i2>=10;
      if (i2) goto l51;
      *(OOC_INT8*)((_check_pointer(i1, 6220))+13) = 3;
      goto l52;
l51:
      *(OOC_INT8*)((_check_pointer(i1, 6174))+13) = 9;
l52:
      *(OOC_INT8*)((_check_pointer(i1, 6264))+14) = 0;
      i1 = *(OOC_INT8*)((_check_pointer(i1, 6315))+13);
      i1 = _clear_bit(261688u,i1);
      
l53:
      i2=0;
l54_loop:
      i3 = _in(i2,i1);
      if (!i3) goto l61;
      i3 = i2<9;
      if (i3) goto l59;
      i3=11;
      goto l60;
l59:
      i3=3;
l60:
      i3 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResultReg((OOC_X86_SSA__Instr)i0, i3, i2);
l61:
      i2 = i2+1;
      i3 = i2<=31;
      if (i3) goto l54_loop;
l65:
      return;
      ;
    }


  maxSizeCallStack = 0;
  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6681))+56);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6690))+64);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6701))+44);
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l8;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6750))+56);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6759))+64);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6770))+44);
  i1 = OOC_X86_SSA__MapType((OOC_SymbolTable__Type)i1);
  type = i1;
  i2 = OOC_X86_SSA__IsFloat(i1);
  if (!i2) goto l8;
  i1 = OOC_X86_SSA__TypeSize(i1);
  maxSizeCallStack = i1;
  
l8:
  i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AllInstructions((OOC_X86_SSA__Block)i0, 29);
  i1 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i0)), OOC_X86_SSA__IterBlockAllInstructionsDesc_Next);
  i2 = OOC_TBCALL(i1,OOC_X86_SSA__IterBlockAllInstructionsDesc_Next)((OOC_X86_SSA__IterBlockAllInstructions)i0, (void*)(OOC_INT32)&instr);
  if (!i2) goto l16;
l11_loop:
  i2 = (OOC_INT32)instr;
  OOC_X86_Machine__ApplyMachineModel_ExpandCall((OOC_X86_SSA__Instr)i2);
  i2 = OOC_TBCALL(i1,OOC_X86_SSA__IterBlockAllInstructionsDesc_Next)((OOC_X86_SSA__IterBlockAllInstructions)i0, (void*)(OOC_INT32)&instr);
  if (i2) goto l11_loop;
l16:
  i0 = maxSizeCallStack;
  i1 = (OOC_INT32)b;
  OOC_X86_SSA__FunctionBlockDesc_SetMaxSizeCallStack((OOC_X86_SSA__FunctionBlock)i1, i0);
  i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AllInstructions((OOC_X86_SSA__Block)i1, (-1));
  i2 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i0)), OOC_X86_SSA__IterBlockAllInstructionsDesc_Next);
  i3 = OOC_TBCALL(i2,OOC_X86_SSA__IterBlockAllInstructionsDesc_Next)((OOC_X86_SSA__IterBlockAllInstructions)i0, (void*)(OOC_INT32)&instr);
  if (!i3) goto l60;
l19_loop:
  i3 = (OOC_INT32)instr;
  i4 = *(OOC_INT8*)((_check_pointer(i3, 7204))+20);
  switch (i4) {
  case 50:
    i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 7252));
    opnd = (OOC_X86_SSA__Opnd)i3;
    i4 = i3!=(OOC_INT32)0;
    if (!i4) goto l55;
l24_loop:
    i4 = OOC_X86_Machine__ApplyMachineModel_IsConst((OOC_X86_SSA__Opnd)i3);
    *(OOC_UINT8*)((_check_pointer(i3, 7307))+16) = i4;
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 7358))+4);
    opnd = (OOC_X86_SSA__Opnd)i3;
    i4 = i3!=(OOC_INT32)0;
    if (i4) goto l24_loop;
    goto l55;
  case 43:
    i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 7472));
    i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 7481))+4);
    *(OOC_UINT8*)((_check_pointer(i4, 7490))+16) = 1u;
    i3 = (OOC_INT32)OOC_X86_Machine__ImmediateOpnd((OOC_X86_SSA__Instr)i3);
    imm = (OOC_X86_SSA__Opnd)i3;
    i4 = i3!=(OOC_INT32)0;
    if (!i4) goto l55;
    *(OOC_UINT8*)((_check_pointer(i3, 7588))+16) = 1u;
    goto l55;
  case 47:
    i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 7721));
    opnd = (OOC_X86_SSA__Opnd)i3;
    i4 = i3!=(OOC_INT32)0;
    if (!i4) goto l55;
l37_loop:
    i4 = OOC_X86_Machine__ApplyMachineModel_IsConst((OOC_X86_SSA__Opnd)i3);
    *(OOC_UINT8*)((_check_pointer(i3, 7776))+16) = i4;
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 7827))+4);
    opnd = (OOC_X86_SSA__Opnd)i3;
    i4 = i3!=(OOC_INT32)0;
    if (i4) goto l37_loop;
    goto l55;
  case 6:
  case 7:
  case 8:
  case 9:
  case 11:
  case 10:
    i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 7920));
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 7929))+4);
    opnd = (OOC_X86_SSA__Opnd)i3;
    i4 = OOC_X86_SSA__OpndDesc_IsConst((OOC_X86_SSA__Opnd)i3);
    if (i4) goto l46;
    i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 8124));
    i4 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddLoadRegister((OOC_X86_SSA__Block)i1, (OOC_X86_SSA__Result)i4, 4);
    OOC_X86_SSA__OpndDesc_ReplaceArg((OOC_X86_SSA__Opnd)i3, (OOC_X86_SSA__Result)i4);
    goto l55;
l46:
    *(OOC_UINT8*)((_check_pointer(i3, 7985))+16) = 1u;
    goto l55;
  default:
    i3 = (OOC_INT32)OOC_X86_Machine__ImmediateOpnd((OOC_X86_SSA__Instr)i3);
    imm = (OOC_X86_SSA__Opnd)i3;
    i4 = i3!=(OOC_INT32)0;
    if (!i4) goto l51;
    *(OOC_UINT8*)((_check_pointer(i3, 8241))+16) = 1u;
l51:
    i3 = (OOC_INT32)instr;
    i3 = (OOC_INT32)OOC_X86_Machine__MemOpnd((OOC_X86_SSA__Instr)i3);
    mem = (OOC_X86_SSA__Opnd)i3;
    i4 = i3!=(OOC_INT32)0;
    if (!i4) goto l55;
    *(OOC_UINT8*)((_check_pointer(i3, 8346))+16) = 1u;
    goto l55;
  }
l55:
  i3 = OOC_TBCALL(i2,OOC_X86_SSA__IterBlockAllInstructionsDesc_Next)((OOC_X86_SSA__IterBlockAllInstructions)i0, (void*)(OOC_INT32)&instr);
  if (i3) goto l19_loop;
l60:
  return;
  ;
}

void OOC_OOC_X86_Machine_init(void) {

  return;
  ;
}

void OOC_OOC_X86_Machine_destroy(void) {
}

/* --- */
