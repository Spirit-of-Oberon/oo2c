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
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 471));
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
  register OOC_INT32 i0,i1;
  OOC_INT32 n;
  OOC_X86_SSA__Opnd opnd;

  i0 = (OOC_INT32)instr;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 835))+20);
  switch (i1) {
  case 19:
  case 20:
  case 35:
    n = 0;
    goto l7;
  case 9:
  case 10:
  case 11:
  case 12:
  case 13:
  case 14:
  case 1:
  case 2:
  case 22:
    n = 1;
    goto l7;
  case 25:
    n = 1;
    goto l7;
  case 32:
    n = 2;
    goto l7;
  default:
    return (OOC_X86_SSA__Opnd)(OOC_INT32)0;
    goto l7;
  }
l7:
  i1 = n;
  i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_NthOpnd((OOC_X86_SSA__Instr)i0, i1);
  opnd = (OOC_X86_SSA__Opnd)i0;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 1317));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 1321))+4);
  i1 = *(OOC_INT8*)((_check_pointer(i1, 1327))+20);
  i1 = i1==0;
  if (i1) goto l10;
  return (OOC_X86_SSA__Opnd)(OOC_INT32)0;
  goto l11;
l10:
  return (OOC_X86_SSA__Opnd)i0;
l11:
  _failed_function(546); return 0;
  ;
}

static OOC_X86_SSA__Opnd OOC_X86_Machine__MemOpnd(OOC_X86_SSA__Instr instr) {
  register OOC_INT32 i0,i1,i2;
  OOC_X86_SSA__Opnd inout;
  OOC_X86_SSA__Opnd opnd;
  auto OOC_CHAR8 OOC_X86_Machine__MemOpnd_IsOffset(OOC_X86_SSA__Instr instr);
    
    OOC_CHAR8 OOC_X86_Machine__MemOpnd_IsOffset(OOC_X86_SSA__Instr instr) {
      register OOC_INT32 i0;

      i0 = (OOC_INT32)instr;
      i0 = *(OOC_INT8*)((_check_pointer(i0, 1697))+20);
      return (i0==1);
      ;
    }


  i0 = (OOC_INT32)instr;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 1756))+20);
  switch (i1) {
  case 25:
  case 24:
    i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 1801));
    i1 = OOC_X86_SSA__OpndDesc_IsConst((OOC_X86_SSA__Opnd)i1);
    if (i1) goto l5;
    i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 1838));
    i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 1847));
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 1851))+4);
    i1 = OOC_X86_Machine__MemOpnd_IsOffset((OOC_X86_SSA__Instr)i1);
    
    goto l7;
l5:
    i1=1u;
l7:
    if (!i1) goto l27;
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 1877));
    *(OOC_UINT8*)((_check_pointer(i0, 1886))+16) = 1u;
    goto l27;
  case 32:
  case 33:
    return (OOC_X86_SSA__Opnd)0;
    goto l27;
  default:
    i1 = (OOC_INT32)OOC_X86_Machine__InOutOpnd((OOC_X86_SSA__Instr)i0);
    inout = (OOC_X86_SSA__Opnd)i1;
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2025));
    opnd = (OOC_X86_SSA__Opnd)i0;
    i2 = i0!=0;
    if (!i2) goto l27;
l14_loop:
    i2 = i0!=i1;
    if (i2) goto l17;
    i2=0u;
    goto l19;
l17:
    i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2097));
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 2101))+4);
    i2 = *(OOC_INT8*)((_check_pointer(i2, 2107))+20);
    i2 = i2==24;
    
l19:
    if (!i2) goto l21;
    return (OOC_X86_SSA__Opnd)i0;
l21:
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2185))+4);
    opnd = (OOC_X86_SSA__Opnd)i0;
    i2 = i0!=0;
    if (i2) goto l14_loop;
    goto l27;
  }
l27:
  return (OOC_X86_SSA__Opnd)0;
  ;
}

void OOC_X86_Machine__ApplyMachineModel(OOC_X86_SSA__FunctionBlock b) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_INT32 maxSizeCallStack;
  OOC_X86_SSA__Instr instr;
  OOC_X86_SSA__Opnd opnd;
  OOC_X86_SSA__Opnd imm;
  OOC_X86_SSA__Opnd mem;
  auto OOC_CHAR8 OOC_X86_Machine__ApplyMachineModel_IsConst(OOC_X86_SSA__Opnd opnd);
  auto void OOC_X86_Machine__ApplyMachineModel_ExpandCall(OOC_X86_SSA__Instr call);
    
    OOC_CHAR8 OOC_X86_Machine__ApplyMachineModel_IsConst(OOC_X86_SSA__Opnd opnd) {
      register OOC_INT32 i0;

      i0 = (OOC_INT32)opnd;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2594));
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2598))+4);
      i0 = *(OOC_INT8*)((_check_pointer(i0, 2604))+20);
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
      OOC_X86_SSA__Instr instr;
      OOC_X86_SSA__Result res;
      auto OOC_INT32 OOC_X86_Machine__ApplyMachineModel_ExpandCall_ArgSize(OOC_X86_SSA__Result arg);
        
        OOC_INT32 OOC_X86_Machine__ApplyMachineModel_ExpandCall_ArgSize(OOC_X86_SSA__Result arg) {
          register OOC_INT32 i0,i1;

          i0 = (OOC_INT32)arg;
          i0 = *(OOC_INT8*)((_check_pointer(i0, 2942))+12);
          i0 = OOC_X86_SSA__TypeSize(i0);
          i1 = i0<4;
          if (i1) goto l3;
          return i0;
          goto l4;
l3:
          return 4;
l4:
          _failed_function(2834); return 0;
          ;
        }


      offset = 0;
      i0 = (OOC_INT32)call;
      i1 = (OOC_INT32)OOC_X86_SSA__InstrDesc_GetBeforeInstr((OOC_X86_SSA__Instr)i0, 1);
      memoryDep = (OOC_X86_SSA__Instr)i1;
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3212));
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 3221))+4);
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 3230));
      sp = (OOC_X86_SSA__Result)i2;
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3254));
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 3263))+4);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 3272))+4);
      opnd = (OOC_X86_SSA__Opnd)i3;
      i4 = i3!=0;
      if (i4) goto l3;
      i1=0;
      goto l9;
l3:
      i4=0;
l4_loop:
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 3354))+4);
      next = (OOC_X86_SSA__Opnd)i5;
      i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 3470));
      i7 = (OOC_INT32)b;
      i7 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConstLength((OOC_X86_SSA__Block)i7, i4);
      i8 = (OOC_INT32)b;
      i6 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr3((OOC_X86_SSA__Block)i8, 32, (OOC_X86_SSA__Result)i2, (OOC_X86_SSA__Result)i7, (OOC_X86_SSA__Result)i6);
      instr = (OOC_X86_SSA__Instr)i6;
      OOC_X86_SSA__InstrDesc_AddDep((OOC_X86_SSA__Instr)i6, 1, (OOC_X86_SSA__Instr)i1);
      OOC_X86_SSA__InstrDesc_AddDep((OOC_X86_SSA__Instr)i0, 1, (OOC_X86_SSA__Instr)i6);
      i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 3596));
      i6 = OOC_X86_Machine__ApplyMachineModel_ExpandCall_ArgSize((OOC_X86_SSA__Result)i6);
      i4 = i4+i6;
      offset = i4;
      OOC_X86_SSA__OpndDesc_DeleteOpnd((OOC_X86_SSA__Opnd)i3);
      opnd = (OOC_X86_SSA__Opnd)i5;
      i3 = i5!=0;
      if (!i3) goto l8;
      i3=i5;
      goto l4_loop;
l8:
      i1=i4;
l9:
      i2 = maxSizeCallStack;
      i2 = i1>i2;
      if (!i2) goto l12;
      maxSizeCallStack = i1;
l12:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3858))+4);
      i1 = i1==0;
      if (!i1) goto l15;
      i1 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i0, 3);
      res = (OOC_X86_SSA__Result)i1;
l15:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3952))+4);
      *(OOC_INT8*)((_check_pointer(i1, 3963))+14) = 0;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3997))+4);
      *(OOC_INT8*)((_check_pointer(i1, 4008))+13) = 3;
      i1=4;
l16_loop:
      i2 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResultReg((OOC_X86_SSA__Instr)i0, 3, i1);
      i1 = i1+1;
      i2 = i1<=5;
      if (i2) goto l16_loop;
l20:
      return;
      ;
    }


  maxSizeCallStack = 0;
  i0 = (OOC_INT32)b;
  i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AllInstructions((OOC_X86_SSA__Block)i0, 20);
  i1 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i0)), OOC_X86_SSA__IterBlockAllInstructionsDesc_Next);
  i2 = OOC_TBCALL(i1,OOC_X86_SSA__IterBlockAllInstructionsDesc_Next)((OOC_X86_SSA__IterBlockAllInstructions)i0, (void*)(OOC_INT32)&instr);
  if (!i2) goto l8;
l3_loop:
  i2 = (OOC_INT32)instr;
  OOC_X86_Machine__ApplyMachineModel_ExpandCall((OOC_X86_SSA__Instr)i2);
  i2 = OOC_TBCALL(i1,OOC_X86_SSA__IterBlockAllInstructionsDesc_Next)((OOC_X86_SSA__IterBlockAllInstructions)i0, (void*)(OOC_INT32)&instr);
  if (i2) goto l3_loop;
l8:
  i0 = maxSizeCallStack;
  i1 = (OOC_INT32)b;
  OOC_X86_SSA__FunctionBlockDesc_SetMaxSizeCallStack((OOC_X86_SSA__FunctionBlock)i1, i0);
  i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AllInstructions((OOC_X86_SSA__Block)i1, (-1));
  i1 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i0)), OOC_X86_SSA__IterBlockAllInstructionsDesc_Next);
  i2 = OOC_TBCALL(i1,OOC_X86_SSA__IterBlockAllInstructionsDesc_Next)((OOC_X86_SSA__IterBlockAllInstructions)i0, (void*)(OOC_INT32)&instr);
  if (!i2) goto l38;
l11_loop:
  i2 = (OOC_INT32)instr;
  i3 = *(OOC_INT8*)((_check_pointer(i2, 4377))+20);
  switch (i3) {
  case 38:
    i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 4425));
    opnd = (OOC_X86_SSA__Opnd)i2;
    i3 = i2!=(OOC_INT32)0;
    if (!i3) goto l33;
l16_loop:
    i3 = OOC_X86_Machine__ApplyMachineModel_IsConst((OOC_X86_SSA__Opnd)i2);
    *(OOC_UINT8*)((_check_pointer(i2, 4480))+16) = i3;
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 4531))+4);
    opnd = (OOC_X86_SSA__Opnd)i2;
    i3 = i2!=(OOC_INT32)0;
    if (i3) goto l16_loop;
    goto l33;
  case 32:
    i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 4645));
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 4654))+4);
    *(OOC_UINT8*)((_check_pointer(i3, 4663))+16) = 1u;
    i2 = (OOC_INT32)OOC_X86_Machine__ImmediateOpnd((OOC_X86_SSA__Instr)i2);
    imm = (OOC_X86_SSA__Opnd)i2;
    i3 = i2!=(OOC_INT32)0;
    if (!i3) goto l33;
    *(OOC_UINT8*)((_check_pointer(i2, 4761))+16) = 1u;
    goto l33;
  default:
    i2 = (OOC_INT32)OOC_X86_Machine__ImmediateOpnd((OOC_X86_SSA__Instr)i2);
    imm = (OOC_X86_SSA__Opnd)i2;
    i3 = i2!=(OOC_INT32)0;
    if (!i3) goto l29;
    *(OOC_UINT8*)((_check_pointer(i2, 4883))+16) = 1u;
l29:
    i2 = (OOC_INT32)instr;
    i2 = (OOC_INT32)OOC_X86_Machine__MemOpnd((OOC_X86_SSA__Instr)i2);
    mem = (OOC_X86_SSA__Opnd)i2;
    i3 = i2!=(OOC_INT32)0;
    if (!i3) goto l33;
    *(OOC_UINT8*)((_check_pointer(i2, 4988))+16) = 1u;
    goto l33;
  }
l33:
  i2 = OOC_TBCALL(i1,OOC_X86_SSA__IterBlockAllInstructionsDesc_Next)((OOC_X86_SSA__IterBlockAllInstructions)i0, (void*)(OOC_INT32)&instr);
  if (i2) goto l11_loop;
l38:
  return;
  ;
}

void OOC_OOC_X86_Machine_init(void) {

  return;
  ;
}

/* --- */
