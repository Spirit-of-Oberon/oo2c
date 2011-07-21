#include <Real0.d>
#include <__oo2c.h>
#include <setjmp.h>

static OOC_CHAR8 Real0__IsSign(OOC_CHAR8 ch) {
  register OOC_INT32 i0,i1;

  i0 = ch;
  i1 = i0==43u;
  if (i1) goto l3;
  i0 = i0==45u;
  
  goto l4;
l3:
  i0=1u;
l4:
  return i0;
  ;
}

static void Real0__RSState(OOC_CHAR8 inputCh, OOC_INT8 *chClass, ConvTypes__ScanState *nextState) {
  register OOC_INT32 i0;

  i0 = inputCh;
  i0 = CharClass__IsNumeric(i0);
  if (i0) goto l3;
  *chClass = 2;
  i0 = (OOC_INT32)Real0__RS;
  *nextState = (ConvTypes__ScanState)i0;
  goto l4;
l3:
  *chClass = 1;
  i0 = (OOC_INT32)Real0__P;
  *nextState = (ConvTypes__ScanState)i0;
l4:
  return;
  ;
}

static void Real0__PState(OOC_CHAR8 inputCh, OOC_INT8 *chClass, ConvTypes__ScanState *nextState) {
  register OOC_INT32 i0,i1;

  i0 = inputCh;
  i1 = CharClass__IsNumeric(i0);
  if (i1) goto l11;
  i1 = i0==46u;
  if (i1) goto l9;
  i0 = i0==69u;
  if (i0) goto l7;
  *chClass = 3;
  *nextState = (ConvTypes__ScanState)(OOC_INT32)0;
  goto l12;
l7:
  *chClass = 1;
  i0 = (OOC_INT32)Real0__E;
  *nextState = (ConvTypes__ScanState)i0;
  goto l12;
l9:
  *chClass = 1;
  i0 = (OOC_INT32)Real0__F;
  *nextState = (ConvTypes__ScanState)i0;
  goto l12;
l11:
  *chClass = 1;
  i0 = (OOC_INT32)Real0__P;
  *nextState = (ConvTypes__ScanState)i0;
l12:
  return;
  ;
}

static void Real0__FState(OOC_CHAR8 inputCh, OOC_INT8 *chClass, ConvTypes__ScanState *nextState) {
  register OOC_INT32 i0,i1;

  i0 = inputCh;
  i1 = CharClass__IsNumeric(i0);
  if (i1) goto l7;
  i0 = i0==69u;
  if (i0) goto l5;
  *chClass = 3;
  *nextState = (ConvTypes__ScanState)(OOC_INT32)0;
  goto l8;
l5:
  *chClass = 1;
  i0 = (OOC_INT32)Real0__E;
  *nextState = (ConvTypes__ScanState)i0;
  goto l8;
l7:
  *chClass = 1;
  i0 = (OOC_INT32)Real0__F;
  *nextState = (ConvTypes__ScanState)i0;
l8:
  return;
  ;
}

static void Real0__EState(OOC_CHAR8 inputCh, OOC_INT8 *chClass, ConvTypes__ScanState *nextState) {
  register OOC_INT32 i0,i1;

  i0 = inputCh;
  i1 = Real0__IsSign(i0);
  if (i1) goto l7;
  i0 = CharClass__IsNumeric(i0);
  if (i0) goto l5;
  *chClass = 2;
  i0 = (OOC_INT32)Real0__E;
  *nextState = (ConvTypes__ScanState)i0;
  goto l8;
l5:
  *chClass = 1;
  i0 = (OOC_INT32)Real0__WE;
  *nextState = (ConvTypes__ScanState)i0;
  goto l8;
l7:
  *chClass = 1;
  i0 = (OOC_INT32)Real0__SE;
  *nextState = (ConvTypes__ScanState)i0;
l8:
  return;
  ;
}

static void Real0__SEState(OOC_CHAR8 inputCh, OOC_INT8 *chClass, ConvTypes__ScanState *nextState) {
  register OOC_INT32 i0;

  i0 = inputCh;
  i0 = CharClass__IsNumeric(i0);
  if (i0) goto l3;
  *chClass = 2;
  i0 = (OOC_INT32)Real0__SE;
  *nextState = (ConvTypes__ScanState)i0;
  goto l4;
l3:
  *chClass = 1;
  i0 = (OOC_INT32)Real0__WE;
  *nextState = (ConvTypes__ScanState)i0;
l4:
  return;
  ;
}

static void Real0__WEState(OOC_CHAR8 inputCh, OOC_INT8 *chClass, ConvTypes__ScanState *nextState) {
  register OOC_INT32 i0;

  i0 = inputCh;
  i0 = CharClass__IsNumeric(i0);
  if (i0) goto l3;
  *chClass = 3;
  *nextState = (ConvTypes__ScanState)(OOC_INT32)0;
  goto l4;
l3:
  *chClass = 1;
  i0 = (OOC_INT32)Real0__WE;
  *nextState = (ConvTypes__ScanState)i0;
l4:
  return;
  ;
}

void Real0__ScanReal(OOC_CHAR8 inputCh, OOC_INT8 *chClass, ConvTypes__ScanState *nextState) {
  register OOC_INT32 i0,i1;

  i0 = inputCh;
  i1 = CharClass__IsWhiteSpace(i0);
  if (i1) goto l11;
  i1 = Real0__IsSign(i0);
  if (i1) goto l9;
  i0 = CharClass__IsNumeric(i0);
  if (i0) goto l7;
  *chClass = 2;
  i0 = (OOC_INT32)Real0__SR;
  *nextState = (ConvTypes__ScanState)i0;
  goto l12;
l7:
  *chClass = 1;
  i0 = (OOC_INT32)Real0__P;
  *nextState = (ConvTypes__ScanState)i0;
  goto l12;
l9:
  *chClass = 1;
  i0 = (OOC_INT32)Real0__RS;
  *nextState = (ConvTypes__ScanState)i0;
  goto l12;
l11:
  *chClass = 0;
  i0 = (OOC_INT32)Real0__SR;
  *nextState = (ConvTypes__ScanState)i0;
l12:
  return;
  ;
}

OOC_INT8 Real0__FormatReal(const OOC_CHAR8 str__ref[], OOC_LEN str_0d, OOC_INT32 maxExp, const OOC_CHAR8 maxValue__ref[], OOC_LEN maxValue_0d) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  OOC_ALLOCATE_VPAR(str,OOC_CHAR8 ,str_0d)
  OOC_ALLOCATE_VPAR(maxValue,OOC_CHAR8 ,maxValue_0d)
  OOC_INT32 i;
  ConvTypes__ScanState state;
  OOC_CHAR8 ch;
  OOC_INT8 _class;
  OOC_INT32 wSigFigs;
  OOC_INT32 fLeadingZeros;
  OOC_CHAR8 allZeroDigit;
  OOC_INT32 startOfExp;
  OOC_INT32 exp;
  OOC_CHAR8 expNegative;
  auto OOC_INT32 Real0__FormatReal_NonZeroDigit(void);
  auto OOC_CHAR8 Real0__FormatReal_LessOrEqual(const OOC_CHAR8 upperBound__ref[], OOC_LEN upperBound_0d);
    
    OOC_INT32 Real0__FormatReal_NonZeroDigit(void) {
      register OOC_INT32 i0,i1,i2;

      i = 0;
      i0 = startOfExp;
      i1 = 0!=i0;
      if (i1) goto l3;
      i1=0u;
      goto l9;
l3:
      i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT32, 4407)));
      i1 = (OOC_UINT8)i1<(OOC_UINT8)49u;
      if (i1) goto l6;
      i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT32, 4425)));
      i1 = (OOC_UINT8)i1>(OOC_UINT8)57u;
      
      goto l9;
l6:
      i1=1u;
l9:
      if (i1) goto l11;
      i0=0;
      goto l25;
l11:
      i1=0;
l12_loop:
      i1 = i1+1;
      i = i1;
      i2 = i1!=i0;
      if (i2) goto l15;
      i2=0u;
      goto l21;
l15:
      i2 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i1, str_0d, OOC_UINT32, 4407)));
      i2 = (OOC_UINT8)i2<(OOC_UINT8)49u;
      if (i2) goto l18;
      i2 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i1, str_0d, OOC_UINT32, 4425)));
      i2 = (OOC_UINT8)i2>(OOC_UINT8)57u;
      
      goto l21;
l18:
      i2=1u;
l21:
      if (i2) goto l12_loop;
l24:
      i0=i1;
l25:
      return i0;
      ;
    }

    
    OOC_CHAR8 Real0__FormatReal_LessOrEqual(const OOC_CHAR8 upperBound__ref[], OOC_LEN upperBound_0d) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      OOC_ALLOCATE_VPAR(upperBound,OOC_CHAR8 ,upperBound_0d)

      OOC_INITIALIZE_VPAR(upperBound__ref,upperBound,OOC_CHAR8 ,upperBound_0d)
      i0 = Real0__FormatReal_NonZeroDigit();
      i1 = startOfExp;
      i2 = i0!=i1;
      if (!i2) goto l54;
      if (i2) goto l6;
      i2=0u;
      goto l8;
l6:
      i2 = *(OOC_UINT8*)((OOC_INT32)upperBound+(_check_index(0, upperBound_0d, OOC_UINT32, 4768)));
      i2 = i2!=0u;
      
l8:
      if (i2) goto l10;
      i2=i0;i0=0;
      goto l32;
l10:
      i2=0;
l11_loop:
      i3 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 4798)));
      i4 = *(OOC_UINT8*)((OOC_INT32)upperBound+(_check_index(i2, upperBound_0d, OOC_UINT32, 4814)));
      i3 = (OOC_UINT8)i3<(OOC_UINT8)i4;
      if (i3) goto l22;
      i3 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 4869)));
      i4 = *(OOC_UINT8*)((OOC_INT32)upperBound+(_check_index(i2, upperBound_0d, OOC_UINT32, 4885)));
      i3 = (OOC_UINT8)i3>(OOC_UINT8)i4;
      if (i3) goto l20;
      i0 = i0+1;
      i3 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 4985)));
      i3 = i3==46u;
      if (!i3) goto l19;
      i0 = i0+1;
      
l19:
      i2 = i2+1;
      
      goto l23;
l20:
      return 0u;
      
      goto l23;
l22:
      return 1u;
      
l23:
      i3 = i0!=i1;
      if (i3) goto l26;
      i3=0u;
      goto l28;
l26:
      i3 = *(OOC_UINT8*)((OOC_INT32)upperBound+(_check_index(i2, upperBound_0d, OOC_UINT32, 4768)));
      i3 = i3!=0u;
      
l28:
      if (i3) goto l11_loop;
l31:
      {register OOC_INT32 h0=i0;i0=i2;i2=h0;}
l32:
      i0 = *(OOC_UINT8*)((OOC_INT32)upperBound+(_check_index(i0, upperBound_0d, OOC_UINT32, 5131)));
      i0 = i0==0u;
      if (i0) goto l35;
      i0=i2;
      goto l54;
l35:
      i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i2, str_0d, OOC_UINT32, 5237)));
      i0 = i0==48u;
      if (i0) goto l38;
      i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i2, str_0d, OOC_UINT32, 5255)));
      i0 = i0==46u;
      
      goto l40;
l38:
      i0=1u;
l40:
      if (i0) goto l42;
      i0=i2;
      goto l54;
l42:
      i0=i2;
l43_loop:
      i0 = i0+1;
      i2 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 5237)));
      i2 = i2==48u;
      if (i2) goto l46;
      i2 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 5255)));
      i2 = i2==46u;
      
      goto l48;
l46:
      i2=1u;
l48:
      if (i2) goto l43_loop;
l54:
      return (i0==i1);
      ;
    }


  OOC_INITIALIZE_VPAR(str__ref,str,OOC_CHAR8 ,str_0d)
  OOC_INITIALIZE_VPAR(maxValue__ref,maxValue,OOC_CHAR8 ,maxValue_0d)
  i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT32, 5457)));
  i0 = i0!=0u;
  if (i0) goto l3;
  i0=0u;
  goto l5;
l3:
  i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT32, 5473)));
  i0 = i0!=101u;
  
l5:
  if (i0) goto l7;
  i0=0;
  goto l17;
l7:
  i0=0;
l8_loop:
  i0 = i0+1;
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 5457)));
  i1 = i1!=0u;
  if (i1) goto l11;
  i1=0u;
  goto l13;
l11:
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 5473)));
  i1 = i1!=101u;
  
l13:
  if (i1) goto l8_loop;
l17:
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 5522)));
  i1 = i1==101u;
  if (!i1) goto l20;
  *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 5547))) = 69u;
l20:
  i = 0;
  i0 = (OOC_INT32)Real0__SR;
  state = (ConvTypes__ScanState)i0;
  i0=0;
l21_loop:
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 5681)));
  ch = i1;
  i2 = (OOC_INT32)state;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 5697));
  ((void (*)(OOC_CHAR8 ch, OOC_INT8 *cl, ConvTypes__ScanState *st))i2)(i1, (void*)(OOC_INT32)&_class, (void*)(OOC_INT32)&state);
  i0 = i0+1;
  i = i0;
  i2 = _class;
  i3 = i2!=0;
  if (!i3) goto l21_loop;
l25:
  i3 = i1==0u;
  if (i3) goto l180;
  i3 = i2==1;
  if (i3) goto l30;
  i3=0u;
  goto l32;
l30:
  i3 = (OOC_INT32)Real0__F;
  i4 = (OOC_INT32)state;
  i3 = i4!=i3;
  
l32:
  if (i3) goto l34;
  i3=0u;
  goto l36;
l34:
  i3 = (OOC_INT32)Real0__E;
  i4 = (OOC_INT32)state;
  i3 = i4!=i3;
  
l36:
  if (i3) goto l38;
  i3=0u;
  goto l44;
l38:
  i3 = (OOC_UINT8)i1<(OOC_UINT8)49u;
  if (i3) goto l41;
  i3 = (OOC_UINT8)i1>(OOC_UINT8)57u;
  
  goto l44;
l41:
  i3=1u;
l44:
  if (i3) goto l47_loop;
  {register OOC_INT32 h0=i0;i0=i2;i2=i1;i1=h0;}
  goto l68;
l47_loop:
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 6010)));
  ch = i1;
  i2 = (OOC_INT32)state;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 6028));
  ((void (*)(OOC_CHAR8 ch, OOC_INT8 *cl, ConvTypes__ScanState *st))i2)(i1, (void*)(OOC_INT32)&_class, (void*)(OOC_INT32)&state);
  i0 = i0+1;
  i = i0;
  i2 = _class;
  i3 = i2==1;
  if (i3) goto l50;
  i3=0u;
  goto l52;
l50:
  i3 = (OOC_INT32)Real0__F;
  i4 = (OOC_INT32)state;
  i3 = i4!=i3;
  
l52:
  if (i3) goto l54;
  i3=0u;
  goto l56;
l54:
  i3 = (OOC_INT32)Real0__E;
  i4 = (OOC_INT32)state;
  i3 = i4!=i3;
  
l56:
  if (i3) goto l58;
  i3=0u;
  goto l64;
l58:
  i3 = (OOC_UINT8)i1<(OOC_UINT8)49u;
  if (i3) goto l61;
  i3 = (OOC_UINT8)i1>(OOC_UINT8)57u;
  
  goto l64;
l61:
  i3=1u;
l64:
  if (i3) goto l47_loop;
l67:
  {register OOC_INT32 h0=i0;i0=i2;i2=i1;i1=h0;}
l68:
  wSigFigs = 0;
  i3 = i0==1;
  if (i3) goto l71;
  i3=0u;
  goto l73;
l71:
  i3 = (OOC_INT32)Real0__F;
  i4 = (OOC_INT32)state;
  i3 = i4!=i3;
  
l73:
  if (i3) goto l75;
  i3=0u;
  goto l77;
l75:
  i3 = (OOC_INT32)Real0__E;
  i4 = (OOC_INT32)state;
  i3 = i4!=i3;
  
l77:
  if (i3) goto l79;
  i3=0;
  goto l93;
l79:
  i0=0;
l80_loop:
  i0 = i0+1;
  wSigFigs = i0;
  i2 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i1, str_0d, OOC_UINT32, 6209)));
  ch = i2;
  i3 = (OOC_INT32)state;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 6227));
  ((void (*)(OOC_CHAR8 ch, OOC_INT8 *cl, ConvTypes__ScanState *st))i3)(i2, (void*)(OOC_INT32)&_class, (void*)(OOC_INT32)&state);
  i1 = i1+1;
  i = i1;
  i3 = _class;
  i4 = i3==1;
  if (i4) goto l83;
  i4=0u;
  goto l85;
l83:
  i4 = (OOC_INT32)Real0__F;
  i5 = (OOC_INT32)state;
  i4 = i5!=i4;
  
l85:
  if (i4) goto l87;
  i4=0u;
  goto l89;
l87:
  i4 = (OOC_INT32)Real0__E;
  i5 = (OOC_INT32)state;
  i4 = i5!=i4;
  
l89:
  if (i4) goto l80_loop;
l92:
  {register OOC_INT32 h0=i0;i0=i3;i3=h0;}
l93:
  fLeadingZeros = 0;
  allZeroDigit = 1u;
  i4 = i0==1;
  if (i4) goto l96;
  i4=0u;
  goto l98;
l96:
  i4 = (OOC_INT32)Real0__E;
  i5 = (OOC_INT32)state;
  i4 = i5!=i4;
  
l98:
  if (i4) goto l100;
  {register OOC_INT32 h0=i0;i0=i1;i1=h0;}i4=0;
  goto l122;
l100:
  i0=i1;i1=1u;i2=0;
l101_loop:
  i4 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 6627)));
  ch = i4;
  if (!i1) goto l113;
  i5 = i4==48u;
  if (i5) goto l111;
  i5 = i4!=46u;
  if (!i5) goto l113;
  allZeroDigit = 0u;
  i1=0u;
  goto l113;
l111:
  i2 = i2+1;
  fLeadingZeros = i2;
  
l113:
  i5 = (OOC_INT32)state;
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 6831));
  ((void (*)(OOC_CHAR8 ch, OOC_INT8 *cl, ConvTypes__ScanState *st))i5)(i4, (void*)(OOC_INT32)&_class, (void*)(OOC_INT32)&state);
  i0 = i0+1;
  i = i0;
  i5 = _class;
  i6 = i5==1;
  if (i6) goto l116;
  i6=0u;
  goto l118;
l116:
  i6 = (OOC_INT32)Real0__E;
  i7 = (OOC_INT32)state;
  i6 = i7!=i6;
  
l118:
  if (i6) goto l101_loop;
l121:
  i1=i5;{register OOC_INT32 h0=i4;i4=i2;i2=h0;}
l122:
  startOfExp = (i0-1);
  exp = 0;
  expNegative = 0u;
  i5 = i1==1;
  if (i5) goto l125;
  i5=i2;i2=i1;i0=0u;i1=0;
  goto l148;
l125:
  i1=0;i2=0u;
l126_loop:
  i5 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 7126)));
  ch = i5;
  i6 = i5==45u;
  if (i6) goto l141;
  i6 = (OOC_UINT8)48u<=(OOC_UINT8)i5;
  if (i6) goto l131;
  i6=0u;
  goto l133;
l131:
  i6 = (OOC_UINT8)i5<=(OOC_UINT8)57u;
  
l133:
  if (i6) goto l135;
  i6=0u;
  goto l137;
l135:
  i6 = i1<100000000;
  
l137:
  if (!i6) goto l142;
  i1 = (i1*10)+(i5-48);
  exp = i1;
  
  goto l142;
l141:
  expNegative = 1u;
  i2=1u;
l142:
  i6 = (OOC_INT32)state;
  i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i6, 7326));
  ((void (*)(OOC_CHAR8 ch, OOC_INT8 *cl, ConvTypes__ScanState *st))i6)(i5, (void*)(OOC_INT32)&_class, (void*)(OOC_INT32)&state);
  i0 = i0+1;
  i = i0;
  i6 = _class;
  i7 = i6==1;
  if (i7) goto l126_loop;
l146:
  i0=i2;i2=i6;
l148:
  if (i0) goto l150;
  i0=i1;
  goto l151;
l150:
  i0 = -i1;
  
l151:
  i1 = i2==2;
  if (i1) goto l154;
  i1 = i5!=0u;
  
  goto l156;
l154:
  i1=1u;
l156:
  if (i1) goto l178;
  i1 = i3>0;
  if (i1) goto l160;
  i0 = (i0-i4)-1;
  exp = i0;
  
  goto l161;
l160:
  i0 = (i0+i3)-1;
  exp = i0;
  
l161:
  i1 = maxExp;
  i0 = i0>i1;
  if (i0) goto l164;
  i0=0u;
  goto l166;
l164:
  i0 = Real0__FormatReal_NonZeroDigit();
  i1 = startOfExp;
  i0 = i0!=i1;
  
l166:
  if (i0) goto l172;
  i0 = maxExp;
  i1 = exp;
  i0 = i1==i0;
  if (i0) goto l170;
  i0=0u;
  goto l174;
l170:
  i0 = Real0__FormatReal_LessOrEqual((void*)(OOC_INT32)maxValue, maxValue_0d);
  i0 = !i0;
  
  goto l174;
l172:
  i0=1u;
l174:
  if (i0) goto l176;
  return 0;
  goto l181;
l176:
  return 1;
  goto l181;
l178:
  return 2;
  goto l181;
l180:
  return 3;
l181:
  _failed_function(3843); return 0;
  ;
}

void Real0__NormalizeFloat(OOC_CHAR8 s[], OOC_LEN s_0d) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = *(OOC_UINT8*)((OOC_INT32)s+(_check_index(0, s_0d, OOC_UINT8, 8560)));
  i0 = i0==43u;
  if (i0) goto l3;
  i0=0;
  goto l4;
l3:
  i0=1;
l4:
  i1 = *(OOC_UINT8*)((OOC_INT32)s+(_check_index(1, s_0d, OOC_UINT16, 8647)));
  i1 = i1!=0u;
  if (i1) goto l7;
  i1=i0;i0=1;
  goto l33;
l7:
  i1=i0;i0=1;
l8_loop:
  i2 = *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i0, s_0d, OOC_UINT16, 8671)));
  i3 = i0+1;
  i2 = i2==46u;
  if (i2) goto l11;
  i2=0u;
  goto l13;
l11:
  i2 = *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i3, s_0d, OOC_UINT16, 8686)));
  i2 = i2==69u;
  
l13:
  if (i2) goto l27;
  i2 = *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i0, s_0d, OOC_UINT16, 8791)));
  i2 = i2==48u;
  if (i2) goto l17;
  i2=0u;
  goto l19;
l17:
  i2 = ((i0-i1)-1)>=0;
  
l19:
  if (i2) goto l21;
  i2=0u;
  goto l23;
l21:
  i2 = *(OOC_UINT8*)((OOC_INT32)s+(_check_index(((i0-i1)-1), s_0d, OOC_UINT16, 8828)));
  i2 = Real0__IsSign(i2);
  
l23:
  if (i2) goto l25;
  i2 = *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i0, s_0d, OOC_UINT16, 8941)));
  *(OOC_UINT8*)((OOC_INT32)s+(_check_index((i0-i1), s_0d, OOC_UINT16, 8931))) = i2;
  i0=i1;
  goto l28;
l25:
  i0 = i1+1;
  
  goto l28;
l27:
  i0 = i1+1;
  
l28:
  i1 = *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i3, s_0d, OOC_UINT16, 8647)));
  i1 = i1!=0u;
  if (!i1) goto l32;
  i1=i0;i0=i3;
  goto l8_loop;
l32:
  i1=i0;i0=i3;
l33:
  i0 = i0-i1;
  i1 = i0-2;
  i2 = *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i1, s_0d, OOC_UINT16, 8990)));
  i2 = i2==69u;
  if (i2) goto l36;
  *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i0, s_0d, OOC_UINT16, 9091))) = 0u;
  goto l37;
l36:
  *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i1, s_0d, OOC_UINT16, 9017))) = 0u;
l37:
  return;
  ;
}

void Real0__FormatForEng(OOC_CHAR8 s[], OOC_LEN s_0d) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;

  i0 = *(OOC_UINT8*)((OOC_INT32)s+(_check_index(1, s_0d, OOC_UINT8, 9413)));
  i0 = CharClass__IsNumeric(i0);
  if (i0) goto l3;
  i0=0;i1=0;i2=0;
  goto l30;
l3:
  i0 = *(OOC_UINT8*)((OOC_INT32)s+(_check_index(0, s_0d, OOC_UINT16, 9485)));
  i0 = i0!=69u;
  if (i0) goto l6;
  i0=0;i1=0;
  goto l16;
l6:
  i0=0;i1=0;i2=0;
l7_loop:
  i3 = *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i2, s_0d, OOC_UINT16, 9540)));
  i3 = i3==46u;
  i2 = i2+1;
  if (i3) goto l10;
  i3=i1;
  goto l11;
l10:
  i3=1;
l11:
  i0 = i0+i1;
  i1 = *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i2, s_0d, OOC_UINT16, 9485)));
  i1 = i1!=69u;
  if (!i1) goto l15;
  i1=i3;
  goto l7_loop;
l15:
  i1=i0;i0=i2;
l16:
  i0 = i0+1;
  i2 = *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i0, s_0d, OOC_UINT16, 9623)));
  i2 = i2==45u;
  if (i2) goto l19;
  i2=1;
  goto l20;
l19:
  i2=(-1);
l20:
  i3 = i0+1;
  i4 = *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i3, s_0d, OOC_UINT16, 9714)));
  i4 = i4!=0u;
  if (i4) goto l23;
  i2=0;
  goto l29;
l23:
  i4=i3;i3=0;
l24_loop:
  i5 = *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i4, s_0d, OOC_UINT16, 9760)));
  i4 = i4+1;
  i3 = (i3*10)+(i2*(i5-48));
  i5 = *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i4, s_0d, OOC_UINT16, 9714)));
  i5 = i5!=0u;
  if (i5) goto l24_loop;
l28:
  i2=i3;
l29:
  {register OOC_INT32 h0=i0;i0=i2;i2=h0;}
l30:
  i3 = _mod(i0,3);
  i4 = i3!=0;
  if (!i4) goto l55;
  i4 = i1<i3;
  if (i4) goto l35;
  i1=i2;
  goto l41;
l35:
  {register OOC_INT32 h0=i1;i1=i2;i2=h0;}
l36_loop:
  Strings__Insert((OOC_CHAR8*)"0", 2, (i1-1), (void*)(OOC_INT32)s, s_0d);
  i2 = i2+1;
  i1 = i1+1;
  i4 = i2<i3;
  if (i4) goto l36_loop;
l41:
  i2 = i3+2;
  i4 = 2<i2;
  if (i4) goto l44;
  i2=2;
  goto l50;
l44:
  i4=2;
l45_loop:
  i5 = i4+1;
  i6 = *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i5, s_0d, OOC_UINT16, 10126)));
  *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i4, s_0d, OOC_UINT16, 10118))) = i6;
  i4 = i5<i2;
  if (!i4) goto l49;
  i4=i5;
  goto l45_loop;
l49:
  i2=i5;
l50:
  *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i2, s_0d, OOC_UINT16, 10160))) = 46u;
  i0 = i0-i3;
  i2 = i0<0;
  if (i2) goto l53;
  *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i1, s_0d, OOC_UINT16, 10312))) = 43u;
  
  goto l54;
l53:
  *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i1, s_0d, OOC_UINT16, 10275))) = 45u;
  i0 = -i0;
  
l54:
  *(OOC_UINT8*)((OOC_INT32)s+(_check_index((i1+1), s_0d, OOC_UINT16, 10347))) = ((_div(i0,100))+48);
  *(OOC_UINT8*)((OOC_INT32)s+(_check_index((i1+2), s_0d, OOC_UINT16, 10398))) = ((_mod((_div(i0,10)),10))+48);
  *(OOC_UINT8*)((OOC_INT32)s+(_check_index((i1+3), s_0d, OOC_UINT16, 10455))) = ((_mod(i0,10))+48);
  *(OOC_UINT8*)((OOC_INT32)s+(_check_index((i1+4), s_0d, OOC_UINT16, 10505))) = 0u;
l55:
  Real0__NormalizeFloat((void*)(OOC_INT32)s, s_0d);
  return;
  ;
}

void Real0__FormatForFixed(OOC_CHAR8 s[], OOC_LEN s_0d, OOC_INT16 place) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT16 point;
  OOC_INT16 suffix;
  auto OOC_CHAR8 Real0__FormatForFixed_NotZero(OOC_CHAR8 s[], OOC_LEN s_0d, OOC_INT16 pos);
    
    OOC_CHAR8 Real0__FormatForFixed_NotZero(OOC_CHAR8 s[], OOC_LEN s_0d, OOC_INT16 pos) {
      register OOC_INT32 i0,i1;

      i0 = pos;
      i1 = *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i0, s_0d, OOC_UINT16, 10785)));
      i1 = i1!=0u;
      if (!i1) goto l15;
l3_loop:
      i1 = *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i0, s_0d, OOC_UINT16, 10813)));
      i1 = i1!=48u;
      if (i1) goto l6;
      i1=0u;
      goto l8;
l6:
      i1 = *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i0, s_0d, OOC_UINT16, 10830)));
      i1 = i1!=46u;
      
l8:
      if (!i1) goto l10;
      return 1u;
l10:
      i0 = i0+1;
      i1 = *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i0, s_0d, OOC_UINT16, 10785)));
      i1 = i1!=0u;
      if (i1) goto l3_loop;
l15:
      return 0u;
      ;
    }


  i0 = place;
  i1 = i0<0;
  if (!i1) goto l65;
  point = 1;
  i1 = *(OOC_UINT8*)((OOC_INT32)s+(_check_index(1, s_0d, OOC_UINT16, 11073)));
  i1 = i1!=46u;
  if (i1) goto l5;
  i1=1;
  goto l11;
l5:
  i1=1;
l6_loop:
  i1 = i1+1;
  point = i1;
  i2 = *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i1, s_0d, OOC_UINT16, 11073)));
  i2 = i2!=46u;
  if (i2) goto l6_loop;
l11:
  i2 = i1+i0;
  i3 = i2>=0;
  if (i3) goto l14;
  *(OOC_UINT8*)((OOC_INT32)s+(_check_index(1, s_0d, OOC_UINT8, 12356))) = 48u;
  *(OOC_UINT8*)((OOC_INT32)s+(_check_index(2, s_0d, OOC_UINT8, 12369))) = 0u;
  
  goto l64;
l14:
  i3 = i2+1;
  suffix = i3;
  i4 = *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i3, s_0d, OOC_UINT16, 11448)));
  i4 = i4==46u;
  if (!i4) goto l18;
  i3 = i3+1;
  suffix = i3;
  
l18:
  i4 = *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i3, s_0d, OOC_UINT16, 11501)));
  i4 = (OOC_UINT8)i4>(OOC_UINT8)53u;
  if (i4) goto l33;
  i4 = *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i3, s_0d, OOC_UINT16, 11533)));
  i4 = i4==53u;
  if (i4) goto l23;
  i3=0u;
  goto l35;
l23:
  i3 = Real0__FormatForFixed_NotZero((void*)(OOC_INT32)s, s_0d, (i3+1));
  if (i3) goto l30;
  i3 = i2!=0;
  if (i3) goto l28;
  i3=0u;
  goto l35;
l28:
  i3 = *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i2, s_0d, OOC_UINT16, 11633)));
  i3 = _odd(i3);
  
  goto l35;
l30:
  i3=1u;
  goto l35;
l33:
  i3=1u;
l35:
  if (!i3) goto l51;
  i3 = *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i2, s_0d, OOC_UINT16, 11736)));
  i3 = i3==57u;
  if (!i3) goto l46;
l41_loop:
  *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i2, s_0d, OOC_UINT16, 11751))) = 48u;
  i2 = i2-1;
  i3 = *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i2, s_0d, OOC_UINT16, 11736)));
  i3 = i3==57u;
  if (i3) goto l41_loop;
l46:
  i3 = i2==0;
  if (i3) goto l49;
  i3 = *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i2, s_0d, OOC_UINT16, 11939)));
  *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i2, s_0d, OOC_UINT16, 11921))) = (i3+1);
  
  goto l51;
l49:
  Strings__Insert((OOC_CHAR8*)"1", 2, 1, (void*)(OOC_INT32)s, s_0d);
  i1 = i1+1;
  
l51:
  i2 = (i1+i0)+1;
  i3 = i2==1;
  if (i3) goto l62;
  i3 = *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i2, s_0d, OOC_UINT16, 12230)));
  i3 = i3!=46u;
  if (!i3) goto l64;
l56_loop:
  *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i2, s_0d, OOC_UINT16, 12245))) = 48u;
  i2 = i2+1;
  i3 = *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i2, s_0d, OOC_UINT16, 12230)));
  i3 = i3!=46u;
  if (i3) goto l56_loop;
  goto l64;
l62:
  *(OOC_UINT8*)((OOC_INT32)s+(_check_index(1, s_0d, OOC_UINT8, 12175))) = 48u;
  *(OOC_UINT8*)((OOC_INT32)s+(_check_index(2, s_0d, OOC_UINT8, 12188))) = 0u;
l64:
  *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i1, s_0d, OOC_UINT16, 12398))) = 0u;
l65:
  i1 = *(OOC_UINT8*)((OOC_INT32)s+(_check_index(0, s_0d, OOC_UINT8, 12492)));
  i1 = i1==43u;
  if (i1) goto l68;
  i1=0;
  goto l69;
l68:
  i1=1;
l69:
  i2 = *(OOC_UINT8*)((OOC_INT32)s+(_check_index(1, s_0d, OOC_UINT16, 12599)));
  i2 = i2!=0u;
  if (i2) goto l72;
  i2=0;i3=1;
  goto l82;
l72:
  i2=1;i3=0;i4=0;
l73_loop:
  i5 = *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i2, s_0d, OOC_UINT16, 12629)));
  *(OOC_UINT8*)((OOC_INT32)s+(_check_index((i2-i1), s_0d, OOC_UINT16, 12619))) = i5;
  i5 = *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i2, s_0d, OOC_UINT16, 12669)));
  i5 = i5==46u;
  i2 = i2+1;
  if (i5) goto l76;
  i5=i4;
  goto l77;
l76:
  i5=1;
l77:
  i3 = i3+i4;
  i4 = *(OOC_UINT8*)((OOC_INT32)s+(_check_index(i2, s_0d, OOC_UINT16, 12599)));
  i4 = i4!=0u;
  if (!i4) goto l81;
  i4=i5;
  goto l73_loop;
l81:
  {register OOC_INT32 h0=i2;i2=i3;i3=h0;}
l82:
  i4 = i2<i0;
  if (i4) goto l85;
  i0=i3;
  goto l91;
l85:
  {register OOC_INT32 h0=i2;i2=i3;i3=h0;}
l86_loop:
  *(OOC_UINT8*)((OOC_INT32)s+(_check_index((i2-i1), s_0d, OOC_UINT16, 12772))) = 48u;
  i3 = i3+1;
  i2 = i2+1;
  i4 = i3<i0;
  if (i4) goto l86_loop;
l90:
  i0=i2;
l91:
  *(OOC_UINT8*)((OOC_INT32)s+(_check_index((i0-i1), s_0d, OOC_UINT16, 12822))) = 0u;
  return;
  ;
}

void OOC_Real0_init(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)RT0__NewObject(_td_ConvTypes__ScanState.baseTypes[0]);
  Real0__RS = (ConvTypes__ScanState)i0;
  *(OOC_INT32*)(_check_pointer(i0, 12877)) = (OOC_INT32)&Real0__RSState;
  i0 = (OOC_INT32)RT0__NewObject(_td_ConvTypes__ScanState.baseTypes[0]);
  Real0__P = (ConvTypes__ScanState)i0;
  *(OOC_INT32*)(_check_pointer(i0, 12903)) = (OOC_INT32)&Real0__PState;
  i0 = (OOC_INT32)RT0__NewObject(_td_ConvTypes__ScanState.baseTypes[0]);
  Real0__F = (ConvTypes__ScanState)i0;
  *(OOC_INT32*)(_check_pointer(i0, 12928)) = (OOC_INT32)&Real0__FState;
  i0 = (OOC_INT32)RT0__NewObject(_td_ConvTypes__ScanState.baseTypes[0]);
  Real0__E = (ConvTypes__ScanState)i0;
  *(OOC_INT32*)(_check_pointer(i0, 12953)) = (OOC_INT32)&Real0__EState;
  i0 = (OOC_INT32)RT0__NewObject(_td_ConvTypes__ScanState.baseTypes[0]);
  Real0__SE = (ConvTypes__ScanState)i0;
  *(OOC_INT32*)(_check_pointer(i0, 12978)) = (OOC_INT32)&Real0__SEState;
  i0 = (OOC_INT32)RT0__NewObject(_td_ConvTypes__ScanState.baseTypes[0]);
  Real0__WE = (ConvTypes__ScanState)i0;
  *(OOC_INT32*)(_check_pointer(i0, 13005)) = (OOC_INT32)&Real0__WEState;
  i0 = (OOC_INT32)RT0__NewObject(_td_ConvTypes__ScanState.baseTypes[0]);
  Real0__SR = (ConvTypes__ScanState)i0;
  *(OOC_INT32*)(_check_pointer(i0, 13032)) = (OOC_INT32)&Real0__ScanReal;
  return;
  ;
}

void OOC_Real0_destroy(void) {
}

/* --- */
