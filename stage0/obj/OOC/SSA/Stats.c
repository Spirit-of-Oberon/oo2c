#include <OOC/SSA/Stats.d>
#include <__oo2c.h>
#include <setjmp.h>

static OOC_SSA_Stats__Stats OOC_SSA_Stats__NewStats(void) {
  register OOC_INT32 i0,i1,i2;
  OOC_SSA_Stats__Stats st;
  OOC_INT32 i;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_Stats__Stats.baseTypes[0]);
  st = (OOC_SSA_Stats__Stats)i0;
  i = 0;
  i1=0;
l1_loop:
  *(OOC_INT32*)((_check_pointer(i0, 571))+(_check_index(i1, 1068, OOC_UINT32, 577))*4) = 0;
  i1 = i1+1;
  i = i1;
  i2 = i1<=1067;
  if (i2) goto l1_loop;
l5:
  return (OOC_SSA_Stats__Stats)i0;
  ;
}

void OOC_SSA_Stats__AddProcBlock(Object__String label, OOC_SSA__ProcBlock pb) {
  register OOC_INT32 i0,i1,i2,i3;
  Object__Object obj;
  OOC_SSA_Stats__Stats st;
  OOC_SSA__Instr instr;
  OOC_INT32 i;

  i0 = (OOC_INT32)label;
  i1 = (OOC_INT32)OOC_SSA_Stats__stage;
  i1 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i1, (Object__Object)i0);
  if (i1) goto l3;
  i1 = (OOC_INT32)OOC_SSA_Stats__NewStats();
  st = (OOC_SSA_Stats__Stats)i1;
  i2 = (OOC_INT32)OOC_SSA_Stats__stage;
  ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i2, (Object__Object)i0, (Object__Object)i1);
  i2 = (OOC_INT32)OOC_SSA_Stats__labels;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 938)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i2, (Object__Object)i0);
  i0=i1;
  goto l4;
l3:
  i1 = (OOC_INT32)OOC_SSA_Stats__stage;
  i0 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i1, (Object__Object)i0);
  obj = (Object__Object)i0;
  i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 857)))), &_td_OOC_SSA_Stats__StatsDesc, 857);
  st = (OOC_SSA_Stats__Stats)i0;
  
l4:
  i1 = (OOC_INT32)pb;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 979))+12);
  instr = (OOC_SSA__Instr)i1;
  i2 = i1!=(OOC_INT32)0;
  if (!i2) goto l12;
l7_loop:
  i2 = *(OOC_INT8*)((_check_pointer(i1, 1044))+36);
  i3 = *(OOC_INT8*)((_check_pointer(i1, 1075))+5);
  i2 = (i2*12)+i3;
  i = i2;
  i3 = *(OOC_INT32*)((_check_pointer(i0, 1098))+(_check_index(i2, 1068, OOC_UINT32, 1104))*4);
  *(OOC_INT32*)((_check_pointer(i0, 1098))+(_check_index(i2, 1068, OOC_UINT32, 1104))*4) = (i3+1);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 1130))+28);
  instr = (OOC_SSA__Instr)i1;
  i2 = i1!=(OOC_INT32)0;
  if (i2) goto l7_loop;
l12:
  return;
  ;
}

void OOC_SSA_Stats__Write(void) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10;
  OOC_SSA_Stats__Stats *stList;
  OOC_INT32 *total;
  OOC_INT32 i;
  Object__Object obj;
  Object__String s;
  Object__String sub;
  OOC_INT32 k;
  OOC_INT32 j;
  OOC_INT32 o[1068];
  OOC_CHAR8 str[64];
  auto void OOC_SSA_Stats__Write_Pad(OOC_INT32 l, OOC_INT32 to);
  auto void OOC_SSA_Stats__Write_Sort(void);
  auto void OOC_SSA_Stats__Write_Sep(void);
    
    void OOC_SSA_Stats__Write_Pad(OOC_INT32 l, OOC_INT32 to) {
      register OOC_INT32 i0,i1,i2;

      i0 = to;
      i1 = l;
      i2 = i1<=i0;
      if (!i2) goto l8;
l3_loop:
      Out__Char(32u);
      i1 = i1+1;
      i2 = i1<=i0;
      if (i2) goto l3_loop;
l8:
      return;
      ;
    }

    
    void OOC_SSA_Stats__Write_Sort(void) {
      register OOC_INT32 i0,i1,i2;
      OOC_INT32 i;
      OOC_INT32 j;
      auto OOC_INT32 OOC_SSA_Stats__Write_Sort_Best(OOC_INT32 start);
      auto void OOC_SSA_Stats__Write_Sort_Swap(OOC_INT32 *a, OOC_INT32 *b);
        
        OOC_INT32 OOC_SSA_Stats__Write_Sort_Best(OOC_INT32 start) {
          register OOC_INT32 i0,i1,i2,i3;
          OOC_INT32 best;
          OOC_INT32 i;
          auto OOC_CHAR8 OOC_SSA_Stats__Write_Sort_Best_Larger(OOC_INT32 a, OOC_INT32 b);
          auto OOC_CHAR8 OOC_SSA_Stats__Write_Sort_Best_AllZero(OOC_INT32 a);
            
            OOC_CHAR8 OOC_SSA_Stats__Write_Sort_Best_Larger(OOC_INT32 a, OOC_INT32 b) {
              register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
              OOC_INT32 j;

              i0 = (OOC_INT32)stList;
              i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 1878)), 0);
              i1 = i1-1;
              j = i1;
              i2 = i1>=0;
              if (!i2) goto l16;
              i2 = a;
              i3 = b;
              
l3_loop:
              i4 = _check_pointer(i0, 1934);
              i5 = OOC_ARRAY_LENGTH(i4, 0);
              i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i1, i5, OOC_UINT32, 1934))*4);
              i5 = _check_pointer(i0, 1955);
              i6 = OOC_ARRAY_LENGTH(i5, 0);
              i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i1, i6, OOC_UINT32, 1955))*4);
              i4 = *(OOC_INT32*)((_check_pointer(i4, 1937))+(_check_index(i2, 1068, OOC_UINT32, 1943))*4);
              i5 = *(OOC_INT32*)((_check_pointer(i5, 1958))+(_check_index(i3, 1068, OOC_UINT32, 1964))*4);
              i4 = i4>i5;
              if (i4) goto l10;
              i4 = _check_pointer(i0, 2026);
              i5 = OOC_ARRAY_LENGTH(i4, 0);
              i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i1, i5, OOC_UINT32, 2026))*4);
              i5 = _check_pointer(i0, 2047);
              i6 = OOC_ARRAY_LENGTH(i5, 0);
              i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i1, i6, OOC_UINT32, 2047))*4);
              i4 = *(OOC_INT32*)((_check_pointer(i4, 2029))+(_check_index(i2, 1068, OOC_UINT32, 2035))*4);
              i5 = *(OOC_INT32*)((_check_pointer(i5, 2050))+(_check_index(i3, 1068, OOC_UINT32, 2056))*4);
              i4 = i4<i5;
              if (i4) goto l8;
              i1 = i1-1;
              j = i1;
              
              goto l11;
l8:
              return 0u;
              
              goto l11;
l10:
              return 1u;
              
l11:
              i4 = i1>=0;
              if (i4) goto l3_loop;
l16:
              return 0u;
              ;
            }

            
            OOC_CHAR8 OOC_SSA_Stats__Write_Sort_Best_AllZero(OOC_INT32 a) {
              register OOC_INT32 i0,i1,i2,i3,i4,i5;
              OOC_INT32 j;

              i0 = (OOC_INT32)stList;
              j = 0;
              i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 2338)), 0);
              i2 = 0<i1;
              if (!i2) goto l11;
              i2 = a;
              i3=0;
l3_loop:
              i4 = _check_pointer(i0, 2368);
              i5 = OOC_ARRAY_LENGTH(i4, 0);
              i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 2368))*4);
              i4 = *(OOC_INT32*)((_check_pointer(i4, 2371))+(_check_index(i2, 1068, OOC_UINT32, 2377))*4);
              i4 = i4!=0;
              if (!i4) goto l6;
              return 0u;
l6:
              i3 = i3+1;
              j = i3;
              i4 = i3<i1;
              if (i4) goto l3_loop;
l11:
              return 1u;
              ;
            }


          i0 = start;
          best = i0;
          i1 = i0+1;
          i = i1;
          i2 = i1<=1067;
          if (!i2) goto l13;
l4_loop:
          i2 = *(OOC_INT32*)((OOC_INT32)o+(_check_index(i0, 1068, OOC_UINT32, 2610))*4);
          i3 = *(OOC_INT32*)((OOC_INT32)o+(_check_index(i1, 1068, OOC_UINT32, 2604))*4);
          i2 = OOC_SSA_Stats__Write_Sort_Best_Larger(i3, i2);
          if (!i2) goto l8;
          best = i1;
          i0=i1;
l8:
          i1 = i1+1;
          i = i1;
          i2 = i1<=1067;
          if (i2) goto l4_loop;
l13:
          i1 = (OOC_INT32)stList;
          i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 2696)), 0);
          i1 = i1==0;
          if (i1) goto l16;
          i1 = *(OOC_INT32*)((OOC_INT32)o+(_check_index(i0, 1068, OOC_UINT32, 2716))*4);
          i1 = OOC_SSA_Stats__Write_Sort_Best_AllZero(i1);
          
          goto l18;
l16:
          i1=1u;
l18:
          if (i1) goto l20;
          return i0;
          goto l21;
l20:
          return (-1);
l21:
          _failed_function(1664); return 0;
          ;
        }

        
        void OOC_SSA_Stats__Write_Sort_Swap(OOC_INT32 *a, OOC_INT32 *b) {
          register OOC_INT32 i0,i1;

          i0 = *a;
          i1 = *b;
          *a = i1;
          *b = i0;
          return;
          ;
        }


      i0=0;
l1_loop:
      *(OOC_INT32*)((OOC_INT32)o+(_check_index(i0, 1068, OOC_UINT32, 3007))*4) = i0;
      i0 = i0+1;
      i1 = i0<=1067;
      if (i1) goto l1_loop;
l5:
      i = 0;
      i0=0;
l6_loop:
      i1 = i0==1067;
      if (i1) goto l15;
      i1 = OOC_SSA_Stats__Write_Sort_Best(i0);
      j = i1;
      i2 = i1<0;
      if (i2) goto l15;
      OOC_SSA_Stats__Write_Sort_Swap((void*)((OOC_INT32)o+(_check_index(i0, 1068, OOC_UINT32, 3221))*4), (void*)((OOC_INT32)o+(_check_index(i1, 1068, OOC_UINT32, 3227))*4));
l13:
      i0 = i;
      i0 = i0+1;
      i = i0;
      
      goto l6_loop;
l15:
      i1 = i0<1068;
      if (!i1) goto l23;
l18_loop:
      *(OOC_INT32*)((OOC_INT32)o+(_check_index(i0, 1068, OOC_UINT32, 3331))*4) = (-1);
      i0 = i0+1;
      i1 = i0<1068;
      if (i1) goto l18_loop;
l23:
      return;
      ;
    }

    
    void OOC_SSA_Stats__Write_Sep(void) {
      register OOC_INT32 i0,i1,i2;

      i0 = (OOC_INT32)stList;
      i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 3478)), 0);
      i0 = 21+(i0*10);
      i1 = 0<=i0;
      if (!i1) goto l8;
      i1=0;
l3_loop:
      Out__Char(45u);
      i1 = i1+1;
      i2 = i1<=i0;
      if (i2) goto l3_loop;
l8:
      Out__Ln();
      return;
      ;
    }


  i0 = (OOC_INT32)OOC_SSA_Stats__labels;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 3590))+4);
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_Stats__1327.baseTypes[0], i1);
  stList = (void*)i1;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 3619))+4);
  i2 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_Stats__1365.baseTypes[0], i2);
  total = (void*)i2;
  i = 0;
  i0 = *(OOC_INT32*)((_check_pointer(i0, 3651))+4);
  i3 = 0<i0;
  if (!i3) goto l8;
  i3=0;
l3_loop:
  i4 = (OOC_INT32)OOC_SSA_Stats__labels;
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 3691));
  i4 = _check_pointer(i4, 3697);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 3697))*4);
  i5 = (OOC_INT32)OOC_SSA_Stats__stage;
  i4 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i5, (Object__Object)i4);
  obj = (Object__Object)i4;
  i5 = _check_pointer(i1, 3715);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  *(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 3715))*4) = (_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 3726)))), &_td_OOC_SSA_Stats__StatsDesc, 3726));
  i4 = _check_pointer(i2, 3745);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  *(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 3745))*4) = 0;
  i3 = i3+1;
  i = i3;
  i4 = i3<i0;
  if (i4) goto l3_loop;
l8:
  OOC_SSA_Stats__Write_Pad(6, 21);
  Out__String("Opcode", 7);
  i0 = (OOC_INT32)OOC_SSA_Stats__labels;
  i0 = *(OOC_INT32*)((_check_pointer(i0, 3841))+4);
  i = 0;
  i1 = 0<i0;
  if (!i1) goto l24;
  i1 = (OOC_INT32)_c0;
  i2=0;
l11_loop:
  i3 = (OOC_INT32)OOC_SSA_Stats__labels;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 3869));
  i3 = _check_pointer(i3, 3875);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 3875))*4);
  i2 = _type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 3879)))), &_td_Object__StringDesc, 3879);
  s = (Object__String)i2;
  i3 = *(OOC_INT32*)(_check_pointer(i2, 3899));
  i3 = i3>5;
  if (!i3) goto l19;
  i3 = *(OOC_INT32*)(_check_pointer(i2, 3945));
  i4 = *(OOC_INT32*)(_check_pointer(i2, 3957));
  i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 3933)))), Object__StringDesc_Substring)),Object__StringDesc_Substring)((Object__String)i2, (i3-5), i4);
  sub = (Object__String)i3;
  i3 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 3981)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i3, (Object__Object)i1);
  if (!i3) goto l19;
  i3 = *(OOC_INT32*)(_check_pointer(i2, 4034));
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 4019)))), Object__StringDesc_Substring)),Object__StringDesc_Substring)((Object__String)i2, 0, (i3-5));
  s = (Object__String)i2;
  
l19:
  i2 = *(OOC_INT32*)(_check_pointer(i2, 4081));
  OOC_SSA_Stats__Write_Pad(i2, 9);
  i2 = (OOC_INT32)s;
  Out__Object((Object__Object)i2);
  i2 = i;
  i2 = i2+1;
  i = i2;
  i3 = i2<i0;
  if (i3) goto l11_loop;
l24:
  Out__Ln();
  OOC_SSA_Stats__Write_Sep();
  OOC_SSA_Stats__Write_Sort();
  k = 0;
  i0=0;
l25_loop:
  i0 = *(OOC_INT32*)((OOC_INT32)o+(_check_index(i0, 1068, OOC_UINT32, 4216))*4);
  j = i0;
  i1 = i0>=0;
  if (!i1) goto l36;
  OOC_SSA_Opcode__GetName((_div(i0,12)), (_mod(i0,12)), (void*)(OOC_INT32)str, 64);
  i0 = Strings__Length((void*)(OOC_INT32)str, 64);
  OOC_SSA_Stats__Write_Pad(i0, 21);
  Out__String((void*)(OOC_INT32)str, 64);
  i0 = (OOC_INT32)OOC_SSA_Stats__labels;
  i0 = *(OOC_INT32*)((_check_pointer(i0, 4472))+4);
  i = 0;
  i1 = 0<i0;
  if (!i1) goto l35;
  i1 = (OOC_INT32)total;
  i2 = j;
  i3 = (OOC_INT32)stList;
  i4=0;
l30_loop:
  i5 = _check_pointer(i3, 4511);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 4511))*4);
  i5 = *(OOC_INT32*)((_check_pointer(i5, 4514))+(_check_index(i2, 1068, OOC_UINT32, 4520))*4);
  Out__LongInt(i5, 10);
  i5 = _check_pointer(i1, 4556);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i7 = _check_pointer(i1, 4556);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i9 = _check_pointer(i3, 4567);
  i10 = OOC_ARRAY_LENGTH(i9, 0);
  i9 = (OOC_INT32)*(OOC_INT32*)(i9+(_check_index(i4, i10, OOC_UINT32, 4567))*4);
  i7 = *(OOC_INT32*)(i7+(_check_index(i4, i8, OOC_UINT32, 4556))*4);
  i8 = *(OOC_INT32*)((_check_pointer(i9, 4570))+(_check_index(i2, 1068, OOC_UINT32, 4576))*4);
  *(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 4556))*4) = (i7+i8);
  i4 = i4+1;
  i = i4;
  i5 = i4<i0;
  if (i5) goto l30_loop;
l35:
  Out__Ln();
l36:
  i0 = k;
  i0 = i0+1;
  k = i0;
  i1 = i0<=1067;
  if (i1) goto l25_loop;
l40:
  OOC_SSA_Stats__Write_Sep();
  OOC_SSA_Stats__Write_Pad(5, 21);
  Out__String("TOTAL", 6);
  i0 = (OOC_INT32)OOC_SSA_Stats__labels;
  i0 = *(OOC_INT32*)((_check_pointer(i0, 4712))+4);
  i = 0;
  i1 = 0<i0;
  if (!i1) goto l48;
  i1 = (OOC_INT32)total;
  i2=0;
l43_loop:
  i3 = _check_pointer(i1, 4746);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = *(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 4746))*4);
  Out__LongInt(i3, 10);
  i2 = i2+1;
  i = i2;
  i3 = i2<i0;
  if (i3) goto l43_loop;
l48:
  Out__Ln();
  return;
  ;
}

void OOC_OOC_SSA_Stats_init(void) {
  register OOC_INT32 i0;
  _c0 = Object__NewLatin1Region("-post", 6, 0, 5);

  i0 = (OOC_INT32)ADT_Dictionary__New();
  OOC_SSA_Stats__stage = (ADT_Dictionary__Dictionary)i0;
  i0 = (OOC_INT32)ADT_ArrayList__New(8);
  OOC_SSA_Stats__labels = (ADT_ArrayList__ArrayList)i0;
  return;
  ;
}

/* --- */
