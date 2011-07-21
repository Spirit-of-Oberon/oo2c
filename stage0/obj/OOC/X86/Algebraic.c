#include <OOC/X86/Algebraic.d>
#include <__oo2c.h>
#include <setjmp.h>

static OOC_INT32 OOC_X86_Algebraic__IsPowerOf2(Object_BigInt__BigInt value) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)value;
  i1=0;
l1_loop:
  i2 = (OOC_INT32)*(OOC_INT32*)((OOC_INT32)OOC_X86_Algebraic__power2+(_check_index(i1, 64, OOC_UINT32, 623))*4);
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

static OOC_CHAR8 OOC_X86_Algebraic__IsNMinus1(OOC_X86_SSA__Result res) {
  register OOC_INT32 i0,i1,i2;
  OOC_X86_SSA__Instr instr;
  OOC_X86_SSA__Result arg;

  i0 = (OOC_INT32)res;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1004))+4);
  instr = (OOC_X86_SSA__Instr)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1023))+4);
  i2 = *(OOC_INT8*)((_check_pointer(i2, 1029))+20);
  i2 = i2==2;
  if (i2) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = OOC_X86_SSA__InstrDesc_Unchecked((OOC_X86_SSA__Instr)i1);
  
l5:
  if (i1) goto l7;
  return 0u;
  goto l12;
l7:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1087))+4);
  i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_NthArg((OOC_X86_SSA__Instr)i0, 1);
  arg = (OOC_X86_SSA__Result)i0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1122))+4);
  i1 = *(OOC_INT8*)((_check_pointer(i1, 1128))+20);
  i1 = i1==0;
  if (i1) goto l10;
  i0=0u;
  goto l11;
l10:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1180))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1186))+28);
  i0 = _check_pointer(i0, 1197);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 1197))*4);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1203)))), &_td_OOC_X86_SSA__ConstDesc, 1203)), 1209));
  i1 = (OOC_INT32)Object_BigInt__one;
  i0 = Object_BigInt__BigIntDesc_Equals((Object_BigInt__BigInt)i1, (Object__Object)i0);
  
l11:
  return i0;
l12:
  _failed_function(796); return 0;
  ;
}

void OOC_X86_Algebraic__Transform(OOC_X86_SSA__FunctionBlock pb, OOC_CHAR8 enableSubstitution) {
  register OOC_INT32 i0,i1,i2;
  OOC_X86_Algebraic__Worklist worklist;
  OOC_X86_SSA__Instr instr;
  auto void OOC_X86_Algebraic__Transform_InspectInstr(OOC_X86_SSA__Instr instr);
    
    void OOC_X86_Algebraic__Transform_InspectInstr(OOC_X86_SSA__Instr instr) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_X86_SSA__Instr _new;
      Object_Boxed__Object val;
      OOC_INT32 exp;
      OOC_X86_SSA__Instr sub;
      auto void OOC_X86_Algebraic__Transform_InspectInstr_AddUsesToWorklist(OOC_X86_SSA__Instr instr);
      auto void OOC_X86_Algebraic__Transform_InspectInstr_Replace(OOC_X86_SSA__Instr instr, OOC_X86_SSA__Result with);
      auto void OOC_X86_Algebraic__Transform_InspectInstr_ReplaceWithOpnd(OOC_X86_SSA__Instr instr, OOC_X86_SSA__Opnd with);
      auto OOC_CHAR8 OOC_X86_Algebraic__Transform_InspectInstr_Equals(OOC_X86_SSA__Opnd opnd, Object_Boxed__Object _const);
      auto OOC_CHAR8 OOC_X86_Algebraic__Transform_InspectInstr_Scaled(OOC_X86_SSA__Result res);
      auto void OOC_X86_Algebraic__Transform_InspectInstr_ReplaceIndexed(OOC_X86_SSA__Instr instr, OOC_X86_SSA__Opnd base, OOC_X86_SSA__Opnd scale);
      auto OOC_CHAR8 OOC_X86_Algebraic__Transform_InspectInstr_AdrOfGlobalVar(OOC_X86_SSA__Instr instr);
        
        void OOC_X86_Algebraic__Transform_InspectInstr_AddUsesToWorklist(OOC_X86_SSA__Instr instr) {
          register OOC_INT32 i0,i1;
          OOC_X86_SSA__Opnd use;
          auto void OOC_X86_Algebraic__Transform_InspectInstr_AddUsesToWorklist_AddToWorklist(OOC_X86_SSA__Instr instr);
            
            void OOC_X86_Algebraic__Transform_InspectInstr_AddUsesToWorklist_AddToWorklist(OOC_X86_SSA__Instr instr) {
              register OOC_INT32 i0,i1;
              OOC_X86_Algebraic__Worklist wl;

              i0 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_Algebraic__Worklist.baseTypes[0]);
              wl = (OOC_X86_Algebraic__Worklist)i0;
              i1 = (OOC_INT32)worklist;
              *(OOC_INT32*)(_check_pointer(i0, 1924)) = i1;
              i1 = (OOC_INT32)instr;
              *(OOC_INT32*)((_check_pointer(i0, 1955))+4) = i1;
              worklist = (OOC_X86_Algebraic__Worklist)i0;
              return;
              ;
            }


          i0 = (OOC_INT32)instr;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2064))+4);
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 2075));
          _assert((i1==0), 127, 2052);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2115))+4);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2126))+8);
          use = (OOC_X86_SSA__Opnd)i0;
          i1 = i0!=0;
          if (!i1) goto l8;
l3_loop:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2192))+8);
          OOC_X86_Algebraic__Transform_InspectInstr_AddUsesToWorklist_AddToWorklist((OOC_X86_SSA__Instr)i0);
          i0 = (OOC_INT32)use;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2221))+12);
          use = (OOC_X86_SSA__Opnd)i0;
          i1 = i0!=0;
          if (i1) goto l3_loop;
l8:
          return;
          ;
        }

        
        void OOC_X86_Algebraic__Transform_InspectInstr_Replace(OOC_X86_SSA__Instr instr, OOC_X86_SSA__Result with) {
          register OOC_INT32 i0,i1;

          i0 = (OOC_INT32)instr;
          OOC_X86_Algebraic__Transform_InspectInstr_AddUsesToWorklist((OOC_X86_SSA__Instr)i0);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2392))+4);
          i1 = (OOC_INT32)with;
          OOC_X86_SSA__ResultDesc_ReplaceUses((OOC_X86_SSA__Result)i0, (OOC_X86_SSA__Result)i1);
          return;
          ;
        }

        
        void OOC_X86_Algebraic__Transform_InspectInstr_ReplaceWithOpnd(OOC_X86_SSA__Instr instr, OOC_X86_SSA__Opnd with) {
          register OOC_INT32 i0,i1;

          i0 = (OOC_INT32)with;
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2543));
          i1 = (OOC_INT32)instr;
          OOC_X86_Algebraic__Transform_InspectInstr_Replace((OOC_X86_SSA__Instr)i1, (OOC_X86_SSA__Result)i0);
          return;
          ;
        }

        
        OOC_CHAR8 OOC_X86_Algebraic__Transform_InspectInstr_Equals(OOC_X86_SSA__Opnd opnd, Object_Boxed__Object _const) {
          register OOC_INT32 i0,i1;

          i0 = (OOC_INT32)opnd;
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2689));
          i0 = (OOC_INT32)OOC_X86_SSA__ResultDesc_GetConst((OOC_X86_SSA__Result)i0);
          i1 = (OOC_INT32)_const;
          i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2677)))), Object__ObjectDesc_Equals)),Object__ObjectDesc_Equals)((Object__Object)i1, (Object__Object)i0);
          return i0;
          ;
        }

        
        OOC_CHAR8 OOC_X86_Algebraic__Transform_InspectInstr_Scaled(OOC_X86_SSA__Result res) {
          register OOC_INT32 i0,i1;
          OOC_X86_SSA__Instr instr;
          Object_Boxed__Object val;

          i0 = enableSubstitution;
          if (i0) goto l3;
          i0=0u;
          goto l5;
l3:
          i0 = (OOC_INT32)res;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3084))+4);
          i0 = *(OOC_INT8*)((_check_pointer(i0, 3090))+20);
          i0 = i0==3;
          
l5:
          if (i0) goto l7;
          i0=0u;
          goto l9;
l7:
          i0 = (OOC_INT32)res;
          i0 = *(OOC_INT8*)((_check_pointer(i0, 3113))+12);
          i0 = i0<=9;
          
l9:
          if (!i0) goto l18;
          i0 = (OOC_INT32)res;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3160))+4);
          instr = (OOC_X86_SSA__Instr)i0;
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3190));
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3199))+4);
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3208));
          i0 = (OOC_INT32)OOC_X86_SSA__ResultDesc_GetConst((OOC_X86_SSA__Result)i0);
          val = (Object_Boxed__Object)i0;
          i1 = i0!=0;
          if (!i1) goto l18;
          i0 = OOC_X86_Algebraic__IsPowerOf2((Object_BigInt__BigInt)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3296)))), &_td_Object_BigInt__BigIntDesc, 3296)));
          i1 = 0<=i0;
          if (i1) goto l15;
          i0=0u;
          goto l16;
l15:
          i0 = i0<=3;
          
l16:
          return i0;
l18:
          return 0u;
          ;
        }

        
        void OOC_X86_Algebraic__Transform_InspectInstr_ReplaceIndexed(OOC_X86_SSA__Instr instr, OOC_X86_SSA__Opnd base, OOC_X86_SSA__Opnd scale) {
          register OOC_INT32 i0,i1,i2;
          OOC_X86_SSA__Instr _new;
          OOC_X86_SSA__Instr s;

          i0 = (OOC_INT32)pb;
          i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr0((OOC_X86_SSA__Block)i0, 8);
          _new = (OOC_X86_SSA__Instr)i0;
          i1 = (OOC_INT32)base;
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 3619));
          OOC_X86_SSA__InstrDesc_AddOpnd((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Result)i1);
          i1 = (OOC_INT32)scale;
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 3644));
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3648))+4);
          s = (OOC_X86_SSA__Instr)i1;
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 3677));
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 3686));
          OOC_X86_SSA__InstrDesc_AddOpnd((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Result)i2);
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 3714));
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3723))+4);
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 3732));
          OOC_X86_SSA__InstrDesc_AddOpnd((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Result)i1);
          i1 = (OOC_INT32)instr;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3781))+4);
          i2 = *(OOC_INT8*)((_check_pointer(i2, 3792))+12);
          i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i0, i2);
          OOC_X86_Algebraic__Transform_InspectInstr_Replace((OOC_X86_SSA__Instr)i1, (OOC_X86_SSA__Result)i0);
          return;
          ;
        }

        
        OOC_CHAR8 OOC_X86_Algebraic__Transform_InspectInstr_AdrOfGlobalVar(OOC_X86_SSA__Instr instr) {
          register OOC_INT32 i0,i1,i2;

          i0 = (OOC_INT32)instr;
          i1 = *(OOC_INT8*)((_check_pointer(i0, 3916))+20);
          i1 = i1==0;
          if (i1) goto l3;
          i1=0u;
          goto l5;
l3:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3955))+28);
          i1 = _check_pointer(i1, 3966);
          i2 = OOC_ARRAY_LENGTH(i1, 0);
          i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 3966))*4);
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3970)))), &_td_OOC_X86_SSA__VarDesc);
          
l5:
          if (i1) goto l7;
          i0=0u;
          goto l8;
l7:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3999))+28);
          i0 = _check_pointer(i0, 4010);
          i1 = OOC_ARRAY_LENGTH(i0, 0);
          i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 4010))*4);
          i0 = OOC_X86_SSA__VarDesc_IsGlobalVar((OOC_X86_SSA__Var)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4016)))), &_td_OOC_X86_SSA__VarDesc, 4016)));
          
l8:
          return i0;
          ;
        }


      i0 = (OOC_INT32)instr;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 4093))+20);
      switch (i1) {
      case 1:
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4143));
        i1 = (OOC_INT32)OOC_X86_Algebraic__intZero;
        i0 = OOC_X86_Algebraic__Transform_InspectInstr_Equals((OOC_X86_SSA__Opnd)i0, (Object_Boxed__Object)i1);
        if (i0) goto l24;
        i0 = (OOC_INT32)instr;
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4267));
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4276))+4);
        i1 = (OOC_INT32)OOC_X86_Algebraic__intZero;
        i0 = OOC_X86_Algebraic__Transform_InspectInstr_Equals((OOC_X86_SSA__Opnd)i0, (Object_Boxed__Object)i1);
        if (i0) goto l22;
        i0 = (OOC_INT32)instr;
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4391));
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4400));
        i0 = OOC_X86_Algebraic__Transform_InspectInstr_Scaled((OOC_X86_SSA__Result)i0);
        if (i0) goto l20;
        i0 = (OOC_INT32)instr;
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4550));
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4559))+4);
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4568));
        i0 = OOC_X86_Algebraic__Transform_InspectInstr_Scaled((OOC_X86_SSA__Result)i0);
        if (i0) goto l18;
        i0 = (OOC_INT32)instr;
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4726));
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4735));
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4739))+4);
        i0 = OOC_X86_Algebraic__Transform_InspectInstr_AdrOfGlobalVar((OOC_X86_SSA__Instr)i0);
        if (i0) goto l13;
        i0=0u;
        goto l15;
l13:
        i0 = (OOC_INT32)instr;
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4768));
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4777))+4);
        i0 = OOC_X86_SSA__OpndDesc_IsConst((OOC_X86_SSA__Opnd)i0);
        
l15:
        if (!i0) goto l69;
        i0 = (OOC_INT32)pb;
        i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr0((OOC_X86_SSA__Block)i0, 0);
        _new = (OOC_X86_SSA__Instr)i0;
        i1 = (OOC_INT32)instr;
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 4934));
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 4943));
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 4947))+4);
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 4953))+28);
        OOC_X86_SSA__InstrDesc_SetDesignator((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Designator)i2);
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 5003));
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 5012))+4);
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 5021));
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 5025))+4);
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 5031))+28);
        i2 = _check_pointer(i2, 5042);
        i3 = OOC_ARRAY_LENGTH(i2, 0);
        i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(0, i3, OOC_UINT8, 5042))*4);
        OOC_X86_SSA__InstrDesc_ExtendDesignator((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Selector)i2);
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5092))+4);
        i2 = *(OOC_INT8*)((_check_pointer(i2, 5103))+12);
        i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i0, i2);
        OOC_X86_Algebraic__Transform_InspectInstr_Replace((OOC_X86_SSA__Instr)i1, (OOC_X86_SSA__Result)i0);
        goto l69;
l18:
        i0 = (OOC_INT32)instr;
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4671));
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4680))+4);
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4655));
        OOC_X86_Algebraic__Transform_InspectInstr_ReplaceIndexed((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Opnd)i2, (OOC_X86_SSA__Opnd)i1);
        goto l69;
l20:
        i0 = (OOC_INT32)instr;
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4487));
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4496))+4);
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4512));
        OOC_X86_Algebraic__Transform_InspectInstr_ReplaceIndexed((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Opnd)i1, (OOC_X86_SSA__Opnd)i2);
        goto l69;
l22:
        i0 = (OOC_INT32)instr;
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4353));
        OOC_X86_Algebraic__Transform_InspectInstr_ReplaceWithOpnd((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Opnd)i1);
        goto l69;
l24:
        i0 = (OOC_INT32)instr;
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4220));
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4229))+4);
        OOC_X86_Algebraic__Transform_InspectInstr_ReplaceWithOpnd((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Opnd)i1);
        goto l69;
      case 2:
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5172));
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5181))+4);
        i1 = (OOC_INT32)OOC_X86_Algebraic__intZero;
        i0 = OOC_X86_Algebraic__Transform_InspectInstr_Equals((OOC_X86_SSA__Opnd)i0, (Object_Boxed__Object)i1);
        if (!i0) goto l69;
        i0 = (OOC_INT32)instr;
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5258));
        OOC_X86_Algebraic__Transform_InspectInstr_ReplaceWithOpnd((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Opnd)i1);
        goto l69;
      case 3:
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5330));
        i1 = (OOC_INT32)OOC_X86_Algebraic__intOne;
        i0 = OOC_X86_Algebraic__Transform_InspectInstr_Equals((OOC_X86_SSA__Opnd)i0, (Object_Boxed__Object)i1);
        if (i0) goto l44;
        i0 = (OOC_INT32)instr;
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5453));
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5462))+4);
        i1 = (OOC_INT32)OOC_X86_Algebraic__intOne;
        i0 = OOC_X86_Algebraic__Transform_InspectInstr_Equals((OOC_X86_SSA__Opnd)i0, (Object_Boxed__Object)i1);
        if (i0) goto l42;
        i0 = (OOC_INT32)instr;
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5576));
        i1 = (OOC_INT32)OOC_X86_Algebraic__intZero;
        i0 = OOC_X86_Algebraic__Transform_InspectInstr_Equals((OOC_X86_SSA__Opnd)i0, (Object_Boxed__Object)i1);
        if (i0) goto l40;
        i0 = (OOC_INT32)instr;
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5691));
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5700))+4);
        i1 = (OOC_INT32)OOC_X86_Algebraic__intZero;
        i0 = OOC_X86_Algebraic__Transform_InspectInstr_Equals((OOC_X86_SSA__Opnd)i0, (Object_Boxed__Object)i1);
        if (!i0) goto l69;
        i0 = (OOC_INT32)instr;
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5777));
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5786))+4);
        OOC_X86_Algebraic__Transform_InspectInstr_ReplaceWithOpnd((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Opnd)i1);
        goto l69;
l40:
        i0 = (OOC_INT32)instr;
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5653));
        OOC_X86_Algebraic__Transform_InspectInstr_ReplaceWithOpnd((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Opnd)i1);
        goto l69;
l42:
        i0 = (OOC_INT32)instr;
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5538));
        OOC_X86_Algebraic__Transform_InspectInstr_ReplaceWithOpnd((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Opnd)i1);
        goto l69;
l44:
        i0 = (OOC_INT32)instr;
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5406));
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5415))+4);
        OOC_X86_Algebraic__Transform_InspectInstr_ReplaceWithOpnd((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Opnd)i1);
        goto l69;
      case 4:
        i1 = enableSubstitution;
        if (i1) goto l49;
        i1=0u;
        goto l51;
l49:
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5916))+4);
        i1 = *(OOC_INT8*)((_check_pointer(i1, 5927))+12);
        i1 = i1<10;
        
l51:
        if (!i1) goto l69;
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5972));
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5981))+4);
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 5990));
        i1 = (OOC_INT32)OOC_X86_SSA__ResultDesc_GetConst((OOC_X86_SSA__Result)i1);
        val = (Object_Boxed__Object)i1;
        i2 = i1!=0;
        if (!i2) goto l69;
        i1 = OOC_X86_Algebraic__IsPowerOf2((Object_BigInt__BigInt)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6079)))), &_td_Object_BigInt__BigIntDesc, 6079)));
        exp = i1;
        i2 = i1>=0;
        if (!i2) goto l69;
        i2 = (OOC_INT32)pb;
        i2 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr0((OOC_X86_SSA__Block)i2, 6);
        _new = (OOC_X86_SSA__Instr)i2;
        i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6193));
        i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 6202));
        OOC_X86_SSA__InstrDesc_AddOpnd((OOC_X86_SSA__Instr)i2, (OOC_X86_SSA__Result)i3);
        i3 = (OOC_INT32)pb;
        i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConstDim((OOC_X86_SSA__Block)i3, i1);
        OOC_X86_SSA__InstrDesc_AddOpnd((OOC_X86_SSA__Instr)i2, (OOC_X86_SSA__Result)i1);
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6319))+4);
        i1 = *(OOC_INT8*)((_check_pointer(i1, 6330))+12);
        i1 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i2, i1);
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6276))+4);
        OOC_X86_SSA__ResultDesc_ReplaceUses((OOC_X86_SSA__Result)i2, (OOC_X86_SSA__Result)i1);
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6365))+4);
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6376));
        _assert((i0==0), 127, 6353);
        goto l69;
      case 12:
        i1 = (OOC_INT32)OOC_X86_SSA__InstrDesc_NthArg((OOC_X86_SSA__Instr)i0, 1);
        i1 = OOC_X86_Algebraic__IsNMinus1((OOC_X86_SSA__Result)i1);
        if (!i1) goto l69;
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6541));
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6550))+4);
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 6559));
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6563))+4);
        sub = (OOC_X86_SSA__Instr)i1;
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 6619));
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6586));
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 6595))+4);
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 6628));
        OOC_X86_SSA__OpndDesc_ReplaceArg((OOC_X86_SSA__Opnd)i2, (OOC_X86_SSA__Result)i1);
        OOC_X86_SSA__InstrDesc_SetOpcode((OOC_X86_SSA__Instr)i0, 11);
        OOC_X86_Algebraic__Transform_InspectInstr_AddUsesToWorklist((OOC_X86_SSA__Instr)i0);
        goto l69;
      case 13:
        i1 = (OOC_INT32)OOC_X86_SSA__InstrDesc_NthArg((OOC_X86_SSA__Instr)i0, 1);
        i1 = OOC_X86_Algebraic__IsNMinus1((OOC_X86_SSA__Result)i1);
        if (!i1) goto l69;
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6826));
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6835))+4);
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 6844));
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6848))+4);
        sub = (OOC_X86_SSA__Instr)i1;
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 6904));
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6871));
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 6880))+4);
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 6913));
        OOC_X86_SSA__OpndDesc_ReplaceArg((OOC_X86_SSA__Opnd)i2, (OOC_X86_SSA__Result)i1);
        OOC_X86_SSA__InstrDesc_SetOpcode((OOC_X86_SSA__Instr)i0, 14);
        OOC_X86_Algebraic__Transform_InspectInstr_AddUsesToWorklist((OOC_X86_SSA__Instr)i0);
        goto l69;
      default:
        goto l69;
      }
l69:
      return;
      ;
    }


  worklist = (OOC_X86_Algebraic__Worklist)(OOC_INT32)0;
  i0 = (OOC_INT32)pb;
  i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AllInstructions((OOC_X86_SSA__Block)i0, (-1));
  i1 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i0)), OOC_X86_SSA__IterBlockAllInstructionsDesc_Next);
  i2 = OOC_TBCALL(i1,OOC_X86_SSA__IterBlockAllInstructionsDesc_Next)((OOC_X86_SSA__IterBlockAllInstructions)i0, (void*)(OOC_INT32)&instr);
  if (!i2) goto l7;
l2_loop:
  i2 = (OOC_INT32)instr;
  OOC_X86_Algebraic__Transform_InspectInstr((OOC_X86_SSA__Instr)i2);
  i2 = OOC_TBCALL(i1,OOC_X86_SSA__IterBlockAllInstructionsDesc_Next)((OOC_X86_SSA__IterBlockAllInstructions)i0, (void*)(OOC_INT32)&instr);
  if (i2) goto l2_loop;
l7:
  i0 = (OOC_INT32)worklist;
  i0 = i0!=(OOC_INT32)0;
  if (!i0) goto l15;
l10_loop:
  i0 = (OOC_INT32)worklist;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7396))+4);
  instr = (OOC_X86_SSA__Instr)i1;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7430));
  worklist = (OOC_X86_Algebraic__Worklist)i0;
  OOC_X86_Algebraic__Transform_InspectInstr((OOC_X86_SSA__Instr)i1);
  i0 = (OOC_INT32)worklist;
  i0 = i0!=(OOC_INT32)0;
  if (i0) goto l10_loop;
l15:
  return;
  ;
}

static void OOC_X86_Algebraic__Init(void) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)Object_BigInt__NewInt(0);
  OOC_X86_Algebraic__intZero = (Object_BigInt__BigInt)i0;
  i0 = (OOC_INT32)Object_BigInt__NewInt(1);
  OOC_X86_Algebraic__intOne = (Object_BigInt__BigInt)i0;
  i0 = (OOC_INT32)Object_BigInt__NewInt(2);
  OOC_X86_Algebraic__intTwo = (Object_BigInt__BigInt)i0;
  i0 = (OOC_INT32)OOC_X86_Algebraic__intOne;
  *(OOC_INT32*)((OOC_INT32)OOC_X86_Algebraic__power2+(_check_index(0, 64, OOC_UINT8, 7652))*4) = i0;
  i0=1;
l1_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((OOC_INT32)OOC_X86_Algebraic__power2+(_check_index((i0-1), 64, OOC_UINT32, 7723))*4);
  i2 = (OOC_INT32)OOC_X86_Algebraic__intTwo;
  i1 = (OOC_INT32)Object_BigInt__BigIntDesc_Mul((Object_BigInt__BigInt)i1, (Object_BigInt__BigInt)i2);
  *(OOC_INT32*)((OOC_INT32)OOC_X86_Algebraic__power2+(_check_index(i0, 64, OOC_UINT32, 7710))*4) = i1;
  i0 = i0+1;
  i1 = i0<=63;
  if (i1) goto l1_loop;
l5:
  return;
  ;
}

void OOC_OOC_X86_Algebraic_init(void) {

  OOC_X86_Algebraic__Init();
  return;
  ;
}

/* --- */
