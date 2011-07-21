#include <OOC/SSA/Algebraic.d>
#include <__oo2c.h>
#include <setjmp.h>

static OOC_INT32 OOC_SSA_Algebraic__IsPowerOf2(Object_BigInt__BigInt value) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)value;
  i1=0;
l1_loop:
  i2 = (OOC_INT32)*(OOC_INT32*)((OOC_INT32)OOC_SSA_Algebraic__power2+(_check_index(i1, 64, OOC_UINT32, 1535))*4);
  i2 = Object_BigInt__BigIntDesc_Cmp((Object_BigInt__BigInt)i0, (Object__Object)i2);
  i3 = i2==0;
  if (i3) goto l7;
  i2 = i2<0;
  if (!i2) goto l8;
  return (-1);
  goto l8;
l7:
  return i1;
l8:
  i1 = i1+1;
  i2 = i1<=63;
  if (i2) goto l1_loop;
l12:
  return (-1);
  ;
}

static OOC_CHAR8 OOC_SSA_Algebraic__IsNMinus1(OOC_SSA__Result res) {
  register OOC_INT32 i0,i1;
  OOC_SSA__Result arg;

  i0 = (OOC_INT32)res;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1896)))), &_td_OOC_SSA__InstrDesc);
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = *(OOC_INT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1928)))), &_td_OOC_SSA__InstrDesc, 1928)), 1934))+36);
  i1 = i1==20;
  
l5:
  if (i1) goto l7;
  i1=0u;
  goto l9;
l7:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 1974));
  i1 = i1==0;
  
l9:
  if (i1) goto l11;
  return 0u;
  goto l16;
l11:
  i0 = (OOC_INT32)OOC_SSA__InstrDesc_NthArg((OOC_SSA__Instr)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2045)))), &_td_OOC_SSA__InstrDesc, 2045)), 1);
  arg = (OOC_SSA__Result)i0;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2081)))), &_td_OOC_SSA__ConstDesc);
  if (i1) goto l14;
  i0=0u;
  goto l15;
l14:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2133)))), &_td_OOC_SSA__ConstDesc, 2133)), 2139))+44);
  i1 = (OOC_INT32)Object_BigInt__one;
  i0 = Object_BigInt__BigIntDesc_Equals((Object_BigInt__BigInt)i1, (Object__Object)i0);
  
l15:
  return i0;
l16:
  _failed_function(1708); return 0;
  ;
}

void OOC_SSA_Algebraic__Transform(OOC_SSA__ProcBlock pb, OOC_CHAR8 enableSubstitution) {
  register OOC_INT32 i0,i1;
  OOC_SSA_Algebraic__Worklist worklist;
  OOC_SSA__Instr instr;
  auto void OOC_SSA_Algebraic__Transform_InspectInstr(OOC_SSA__Instr instr);
    
    void OOC_SSA_Algebraic__Transform_InspectInstr(OOC_SSA__Instr instr) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_INT32 exp;
      OOC_SSA__Instr _new;
      OOC_SSA__Instr sub;
      auto void OOC_SSA_Algebraic__Transform_InspectInstr_AddUsesToWorklist(OOC_SSA__Instr instr);
      auto void OOC_SSA_Algebraic__Transform_InspectInstr_Replace(OOC_SSA__Instr instr, OOC_SSA__Result with);
      auto void OOC_SSA_Algebraic__Transform_InspectInstr_ReplaceWithOpnd(OOC_SSA__Instr instr, OOC_SSA__Opnd with);
      auto OOC_CHAR8 OOC_SSA_Algebraic__Transform_InspectInstr_Equals(OOC_SSA__Opnd opnd, Object_Boxed__Object _const);
      auto OOC_CHAR8 OOC_SSA_Algebraic__Transform_InspectInstr_Scaled(OOC_SSA__Result res);
      auto void OOC_SSA_Algebraic__Transform_InspectInstr_ReplaceIndexed(OOC_SSA__Instr instr, OOC_SSA__Opnd base, OOC_SSA__Opnd scale);
        
        void OOC_SSA_Algebraic__Transform_InspectInstr_AddUsesToWorklist(OOC_SSA__Instr instr) {
          register OOC_INT32 i0,i1;
          OOC_SSA__Opnd use;
          auto void OOC_SSA_Algebraic__Transform_InspectInstr_AddUsesToWorklist_AddToWorklist(OOC_SSA__Instr instr);
            
            void OOC_SSA_Algebraic__Transform_InspectInstr_AddUsesToWorklist_AddToWorklist(OOC_SSA__Instr instr) {
              register OOC_INT32 i0,i1;
              OOC_SSA_Algebraic__Worklist wl;

              i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_Algebraic__Worklist.baseTypes[0]);
              wl = (OOC_SSA_Algebraic__Worklist)i0;
              i1 = (OOC_INT32)worklist;
              *(OOC_INT32*)(_check_pointer(i0, 2842)) = i1;
              i1 = (OOC_INT32)instr;
              *(OOC_INT32*)((_check_pointer(i0, 2874))+4) = i1;
              worklist = (OOC_SSA_Algebraic__Worklist)i0;
              return;
              ;
            }


          i0 = (OOC_INT32)instr;
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2985));
          _assert((i1==0), 127, 2972);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3026))+12);
          use = (OOC_SSA__Opnd)i0;
          i1 = i0!=0;
          if (!i1) goto l8;
l3_loop:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3094))+12);
          OOC_SSA_Algebraic__Transform_InspectInstr_AddUsesToWorklist_AddToWorklist((OOC_SSA__Instr)i0);
          i0 = (OOC_INT32)use;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3124))+16);
          use = (OOC_SSA__Opnd)i0;
          i1 = i0!=0;
          if (i1) goto l3_loop;
l8:
          return;
          ;
        }

        
        void OOC_SSA_Algebraic__Transform_InspectInstr_Replace(OOC_SSA__Instr instr, OOC_SSA__Result with) {
          register OOC_INT32 i0,i1;

          i0 = (OOC_INT32)instr;
          OOC_SSA_Algebraic__Transform_InspectInstr_AddUsesToWorklist((OOC_SSA__Instr)i0);
          i1 = (OOC_INT32)with;
          OOC_SSA__ResultDesc_ReplaceUses((OOC_SSA__Result)i0, (OOC_SSA__Result)i1);
          return;
          ;
        }

        
        void OOC_SSA_Algebraic__Transform_InspectInstr_ReplaceWithOpnd(OOC_SSA__Instr instr, OOC_SSA__Opnd with) {
          register OOC_INT32 i0,i1;

          i0 = (OOC_INT32)with;
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3449));
          i1 = (OOC_INT32)instr;
          OOC_SSA_Algebraic__Transform_InspectInstr_Replace((OOC_SSA__Instr)i1, (OOC_SSA__Result)i0);
          return;
          ;
        }

        
        OOC_CHAR8 OOC_SSA_Algebraic__Transform_InspectInstr_Equals(OOC_SSA__Opnd opnd, Object_Boxed__Object _const) {
          register OOC_INT32 i0,i1;
          OOC_SSA__Result arg;

          i0 = (OOC_INT32)opnd;
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3620));
          arg = (OOC_SSA__Result)i0;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3643)))), &_td_OOC_SSA__ConstDesc);
          if (i1) goto l3;
          return 0u;
          goto l4;
l3:
          i1 = (OOC_INT32)_const;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3693))+44);
          i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3680)))), Object__ObjectDesc_Equals)),Object__ObjectDesc_Equals)((Object__Object)i1, (Object__Object)i0);
          return i0;
l4:
          _failed_function(3499); return 0;
          ;
        }

        
        OOC_CHAR8 OOC_SSA_Algebraic__Transform_InspectInstr_Scaled(OOC_SSA__Result res) {
          register OOC_INT32 i0,i1;
          OOC_SSA__Instr instr;

          i0 = enableSubstitution;
          if (i0) goto l3;
          i0=0u;
          goto l5;
l3:
          i0 = (OOC_INT32)res;
          i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4108)))), &_td_OOC_SSA__InstrDesc);
          
l5:
          if (i0) goto l7;
          i0=0u;
          goto l9;
l7:
          i0 = (OOC_INT32)res;
          i0 = *(OOC_INT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4144)))), &_td_OOC_SSA__InstrDesc, 4144)), 4150))+36);
          i0 = i0==22;
          
l9:
          if (i0) goto l11;
          i0=0u;
          goto l13;
l11:
          i0 = (OOC_INT32)res;
          i0 = *(OOC_INT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4200)))), &_td_OOC_SSA__InstrDesc, 4200)), 4206))+5);
          i0 = i0<=9;
          
l13:
          if (!i0) goto l22;
          i0 = (OOC_INT32)res;
          i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4270)))), &_td_OOC_SSA__InstrDesc, 4270);
          instr = (OOC_SSA__Instr)i0;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4297))+24);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4307))+8);
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 4317));
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4323)))), &_td_OOC_SSA__ConstDesc);
          if (!i1) goto l22;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4378))+24);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4388))+8);
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4398));
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4408)))), &_td_OOC_SSA__ConstDesc, 4408)), 4414))+44);
          i0 = OOC_SSA_Algebraic__IsPowerOf2((Object_BigInt__BigInt)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4429)))), &_td_Object_BigInt__BigIntDesc, 4429)));
          i1 = 0<=i0;
          if (i1) goto l19;
          i0=0u;
          goto l20;
l19:
          i0 = i0<=3;
          
l20:
          return i0;
l22:
          return 0u;
          ;
        }

        
        void OOC_SSA_Algebraic__Transform_InspectInstr_ReplaceIndexed(OOC_SSA__Instr instr, OOC_SSA__Opnd base, OOC_SSA__Opnd scale) {
          register OOC_INT32 i0,i1,i2,i3,i4;
          OOC_SSA__Instr _new;
          OOC_SSA__Instr s;

          i0 = (OOC_INT32)instr;
          i1 = *(OOC_INT8*)((_check_pointer(i0, 4744))+5);
          i2 = (OOC_INT32)pb;
          i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i2, 51, i1);
          _new = (OOC_SSA__Instr)i1;
          i2 = (OOC_INT32)base;
          i3 = *(OOC_INT8*)((_check_pointer(i2, 4794))+4);
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 4783));
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i2, i3);
          i2 = (OOC_INT32)scale;
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 4822));
          i2 = _type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 4832)))), &_td_OOC_SSA__InstrDesc, 4832);
          s = (OOC_SSA__Instr)i2;
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 4881))+24);
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 4863))+24);
          i3 = *(OOC_INT8*)((_check_pointer(i3, 4891))+4);
          i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 4873));
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i4, i3);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 4974))+24);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 4984))+8);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 4924))+24);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 4934))+8);
          i3 = *(OOC_INT8*)((_check_pointer(i3, 4994))+4);
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 4944));
          OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i1, (OOC_SSA__Result)i2, i3);
          OOC_SSA_Algebraic__Transform_InspectInstr_Replace((OOC_SSA__Instr)i0, (OOC_SSA__Result)i1);
          return;
          ;
        }


      i0 = (OOC_INT32)instr;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 5091))+36);
      switch (i1) {
      case 19:
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5147))+24);
        i1 = (OOC_INT32)OOC_SSA_Algebraic__intZero;
        i0 = OOC_SSA_Algebraic__Transform_InspectInstr_Equals((OOC_SSA__Opnd)i0, (Object_Boxed__Object)i1);
        if (i0) goto l16;
        i0 = (OOC_INT32)instr;
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5276))+24);
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5286))+8);
        i1 = (OOC_INT32)OOC_SSA_Algebraic__intZero;
        i0 = OOC_SSA_Algebraic__Transform_InspectInstr_Equals((OOC_SSA__Opnd)i0, (Object_Boxed__Object)i1);
        if (i0) goto l14;
        i0 = (OOC_INT32)instr;
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5405))+24);
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5415));
        i0 = OOC_SSA_Algebraic__Transform_InspectInstr_Scaled((OOC_SSA__Result)i0);
        if (i0) goto l12;
        i0 = (OOC_INT32)instr;
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5571))+24);
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5581))+8);
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5591));
        i0 = OOC_SSA_Algebraic__Transform_InspectInstr_Scaled((OOC_SSA__Result)i0);
        if (!i0) goto l62;
        i0 = (OOC_INT32)instr;
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5697))+24);
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5707))+8);
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5680))+24);
        OOC_SSA_Algebraic__Transform_InspectInstr_ReplaceIndexed((OOC_SSA__Instr)i0, (OOC_SSA__Opnd)i2, (OOC_SSA__Opnd)i1);
        goto l62;
l12:
        i0 = (OOC_INT32)instr;
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5504))+24);
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5531))+24);
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5514))+8);
        OOC_SSA_Algebraic__Transform_InspectInstr_ReplaceIndexed((OOC_SSA__Instr)i0, (OOC_SSA__Opnd)i1, (OOC_SSA__Opnd)i2);
        goto l62;
l14:
        i0 = (OOC_INT32)instr;
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5365))+24);
        OOC_SSA_Algebraic__Transform_InspectInstr_ReplaceWithOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Opnd)i1);
        goto l62;
l16:
        i0 = (OOC_INT32)instr;
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5226))+24);
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5236))+8);
        OOC_SSA_Algebraic__Transform_InspectInstr_ReplaceWithOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Opnd)i1);
        goto l62;
      case 20:
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5791))+24);
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5801))+8);
        i1 = (OOC_INT32)OOC_SSA_Algebraic__intZero;
        i0 = OOC_SSA_Algebraic__Transform_InspectInstr_Equals((OOC_SSA__Opnd)i0, (Object_Boxed__Object)i1);
        if (!i0) goto l62;
        i0 = (OOC_INT32)instr;
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5880))+24);
        OOC_SSA_Algebraic__Transform_InspectInstr_ReplaceWithOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Opnd)i1);
        goto l62;
      case 22:
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5964))+24);
        i1 = (OOC_INT32)OOC_SSA_Algebraic__intOne;
        i0 = OOC_SSA_Algebraic__Transform_InspectInstr_Equals((OOC_SSA__Opnd)i0, (Object_Boxed__Object)i1);
        if (i0) goto l36;
        i0 = (OOC_INT32)instr;
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6092))+24);
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6102))+8);
        i1 = (OOC_INT32)OOC_SSA_Algebraic__intOne;
        i0 = OOC_SSA_Algebraic__Transform_InspectInstr_Equals((OOC_SSA__Opnd)i0, (Object_Boxed__Object)i1);
        if (i0) goto l34;
        i0 = (OOC_INT32)instr;
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6220))+24);
        i1 = (OOC_INT32)OOC_SSA_Algebraic__intZero;
        i0 = OOC_SSA_Algebraic__Transform_InspectInstr_Equals((OOC_SSA__Opnd)i0, (Object_Boxed__Object)i1);
        if (i0) goto l32;
        i0 = (OOC_INT32)instr;
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6339))+24);
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6349))+8);
        i1 = (OOC_INT32)OOC_SSA_Algebraic__intZero;
        i0 = OOC_SSA_Algebraic__Transform_InspectInstr_Equals((OOC_SSA__Opnd)i0, (Object_Boxed__Object)i1);
        if (!i0) goto l62;
        i0 = (OOC_INT32)instr;
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6428))+24);
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6438))+8);
        OOC_SSA_Algebraic__Transform_InspectInstr_ReplaceWithOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Opnd)i1);
        goto l62;
l32:
        i0 = (OOC_INT32)instr;
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6299))+24);
        OOC_SSA_Algebraic__Transform_InspectInstr_ReplaceWithOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Opnd)i1);
        goto l62;
l34:
        i0 = (OOC_INT32)instr;
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6180))+24);
        OOC_SSA_Algebraic__Transform_InspectInstr_ReplaceWithOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Opnd)i1);
        goto l62;
l36:
        i0 = (OOC_INT32)instr;
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6042))+24);
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6052))+8);
        OOC_SSA_Algebraic__Transform_InspectInstr_ReplaceWithOpnd((OOC_SSA__Instr)i0, (OOC_SSA__Opnd)i1);
        goto l62;
      case 23:
        i1 = enableSubstitution;
        if (i1) goto l41;
        i1=0u;
        goto l43;
l41:
        i1 = *(OOC_INT8*)((_check_pointer(i0, 6588))+5);
        i1 = i1<10;
        
l43:
        if (i1) goto l45;
        i1=0u;
        goto l47;
l45:
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6637))+24);
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6647))+8);
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 6657));
        i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6663)))), &_td_OOC_SSA__ConstDesc);
        
l47:
        if (!i1) goto l62;
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6716))+24);
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6726))+8);
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 6736));
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6746)))), &_td_OOC_SSA__ConstDesc, 6746)), 6752))+44);
        i1 = OOC_SSA_Algebraic__IsPowerOf2((Object_BigInt__BigInt)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6767)))), &_td_Object_BigInt__BigIntDesc, 6767)));
        exp = i1;
        i2 = i1>=0;
        if (!i2) goto l62;
        i2 = *(OOC_INT8*)((_check_pointer(i0, 6863))+5);
        i3 = (OOC_INT32)pb;
        i2 = (OOC_INT32)OOC_SSA__ProcBlockDesc_AddInstr((OOC_SSA__ProcBlock)i3, 47, i2);
        _new = (OOC_SSA__Instr)i2;
        i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6907))+24);
        i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 6917));
        OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i3, 1);
        i3 = (OOC_INT32)pb;
        i1 = (OOC_INT32)OOC_SSA__ProcBlockDesc_GetConstInt((OOC_SSA__ProcBlock)i3, i1);
        OOC_SSA__InstrDesc_AddOpnd((OOC_SSA__Instr)i2, (OOC_SSA__Result)i1, 1);
        OOC_SSA__ResultDesc_ReplaceUses((OOC_SSA__Result)i0, (OOC_SSA__Result)i2);
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7058));
        _assert((i0==0), 127, 7045);
        goto l62;
      case 28:
        i1 = (OOC_INT32)OOC_SSA__InstrDesc_NthArg((OOC_SSA__Instr)i0, 1);
        i1 = OOC_SSA_Algebraic__IsNMinus1((OOC_SSA__Result)i1);
        if (!i1) goto l62;
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7212))+24);
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 7221))+8);
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 7230));
        i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7239)))), &_td_OOC_SSA__InstrDesc, 7239);
        sub = (OOC_SSA__Instr)i1;
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 7295))+24);
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7262))+24);
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7271))+8);
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 7304));
        OOC_SSA__OpndDesc_ReplaceArg((OOC_SSA__Opnd)i2, (OOC_SSA__Result)i1);
        *(OOC_INT8*)((_check_pointer(i0, 7326))+36) = 27;
        OOC_SSA_Algebraic__Transform_InspectInstr_AddUsesToWorklist((OOC_SSA__Instr)i0);
        goto l62;
      case 29:
        i1 = (OOC_INT32)OOC_SSA__InstrDesc_NthArg((OOC_SSA__Instr)i0, 1);
        i1 = OOC_SSA_Algebraic__IsNMinus1((OOC_SSA__Result)i1);
        if (!i1) goto l62;
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7511))+24);
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 7520))+8);
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 7529));
        i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7538)))), &_td_OOC_SSA__InstrDesc, 7538);
        sub = (OOC_SSA__Instr)i1;
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 7594))+24);
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7561))+24);
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7570))+8);
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 7603));
        OOC_SSA__OpndDesc_ReplaceArg((OOC_SSA__Opnd)i2, (OOC_SSA__Result)i1);
        *(OOC_INT8*)((_check_pointer(i0, 7625))+36) = 30;
        OOC_SSA_Algebraic__Transform_InspectInstr_AddUsesToWorklist((OOC_SSA__Instr)i0);
        goto l62;
      default:
        goto l62;
      }
l62:
      return;
      ;
    }


  worklist = (OOC_SSA_Algebraic__Worklist)(OOC_INT32)0;
  i0 = (OOC_INT32)pb;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7830))+12);
  instr = (OOC_SSA__Instr)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l8;
l3_loop:
  OOC_SSA_Algebraic__Transform_InspectInstr((OOC_SSA__Instr)i0);
  i0 = (OOC_INT32)instr;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7918))+28);
  instr = (OOC_SSA__Instr)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3_loop;
l8:
  i0 = (OOC_INT32)worklist;
  i0 = i0!=(OOC_INT32)0;
  if (!i0) goto l16;
l11_loop:
  i0 = (OOC_INT32)worklist;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8140))+4);
  instr = (OOC_SSA__Instr)i1;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 8175));
  worklist = (OOC_SSA_Algebraic__Worklist)i0;
  OOC_SSA_Algebraic__Transform_InspectInstr((OOC_SSA__Instr)i1);
  i0 = (OOC_INT32)worklist;
  i0 = i0!=(OOC_INT32)0;
  if (i0) goto l11_loop;
l16:
  return;
  ;
}

static void OOC_SSA_Algebraic__Init(void) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)Object_BigInt__NewInt(0);
  OOC_SSA_Algebraic__intZero = (Object_BigInt__BigInt)i0;
  i0 = (OOC_INT32)Object_BigInt__NewInt(1);
  OOC_SSA_Algebraic__intOne = (Object_BigInt__BigInt)i0;
  i0 = (OOC_INT32)Object_BigInt__NewInt(2);
  OOC_SSA_Algebraic__intTwo = (Object_BigInt__BigInt)i0;
  i0 = (OOC_INT32)OOC_SSA_Algebraic__intOne;
  *(OOC_INT32*)((OOC_INT32)OOC_SSA_Algebraic__power2+(_check_index(0, 64, OOC_UINT8, 8399))*4) = i0;
  i0=1;
l1_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((OOC_INT32)OOC_SSA_Algebraic__power2+(_check_index((i0-1), 64, OOC_UINT32, 8470))*4);
  i2 = (OOC_INT32)OOC_SSA_Algebraic__intTwo;
  i1 = (OOC_INT32)Object_BigInt__BigIntDesc_Mul((Object_BigInt__BigInt)i1, (Object_BigInt__BigInt)i2);
  *(OOC_INT32*)((OOC_INT32)OOC_SSA_Algebraic__power2+(_check_index(i0, 64, OOC_UINT32, 8457))*4) = i1;
  i0 = i0+1;
  i1 = i0<=63;
  if (i1) goto l1_loop;
l5:
  return;
  ;
}

void OOC_OOC_SSA_Algebraic_init(void) {

  OOC_SSA_Algebraic__Init();
  return;
  ;
}

void OOC_OOC_SSA_Algebraic_destroy(void) {
}

/* --- */
