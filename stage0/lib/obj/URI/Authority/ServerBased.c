#include <URI/Authority/ServerBased.d>
#include <__oo2c.h>
#include <setjmp.h>

void URI_Authority_ServerBased__Init(URI_Authority_ServerBased__Authority auth, Object__String userinfo, Object__String host, OOC_INT32 port, OOC_INT32 defaultPort) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)host;
  _assert((i0!=(OOC_INT32)0), 127, 1869);
  i1 = (OOC_INT32)auth;
  i2 = (OOC_INT32)userinfo;
  *(OOC_INT32*)(_check_pointer(i1, 1898)) = i2;
  *(OOC_INT32*)((_check_pointer(i1, 1930))+4) = i0;
  i0 = port;
  *(OOC_INT32*)((_check_pointer(i1, 1954))+8) = i0;
  i0 = defaultPort;
  *(OOC_INT32*)((_check_pointer(i1, 1978))+12) = i0;
  return;
  ;
}

URI_Authority_ServerBased__Authority URI_Authority_ServerBased__New(Object__String userinfo, Object__String host, OOC_INT32 port, OOC_INT32 defaultPort) {
  register OOC_INT32 i0,i1,i2,i3,i4;

  i0 = (OOC_INT32)RT0__NewObject(_td_URI_Authority_ServerBased__Authority.baseTypes[0]);
  i1 = defaultPort;
  i2 = port;
  i3 = (OOC_INT32)host;
  i4 = (OOC_INT32)userinfo;
  URI_Authority_ServerBased__Init((URI_Authority_ServerBased__Authority)i0, (Object__String)i4, (Object__String)i3, i2, i1);
  return (URI_Authority_ServerBased__Authority)i0;
  ;
}

URI_Authority_ServerBased__Authority URI_Authority_ServerBased__AuthorityDesc_Clone(URI_Authority_ServerBased__Authority auth) {
  register OOC_INT32 i0,i1;
  URI_Authority_ServerBased__Authority copy;

  i0 = (OOC_INT32)RT0__NewObject(_td_URI_Authority_ServerBased__Authority.baseTypes[0]);
  copy = (URI_Authority_ServerBased__Authority)i0;
  i1 = (OOC_INT32)auth;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2648)))), URI__AuthorityDesc_Copy)),URI__AuthorityDesc_Copy)((URI__Authority)i1, (URI__Authority)i0);
  return (URI_Authority_ServerBased__Authority)i0;
  ;
}

void URI_Authority_ServerBased__AuthorityDesc_Copy(URI_Authority_ServerBased__Authority auth, URI__Authority dest) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)dest;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2837)))), &_td_URI_Authority_ServerBased__AuthorityDesc);
  if (i1) goto l3;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2828)))), 2828);
  goto l12;
l3:
  i1 = (OOC_INT32)auth;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 2866));
  i2 = i2!=0;
  if (i2) goto l6;
  *(OOC_INT32*)(_check_pointer(i0, 2953)) = 0;
  goto l7;
l6:
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 2919));
  *(OOC_INT32*)(_check_pointer(i0, 2901)) = i2;
l7:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2996))+4);
  i2 = i2!=0;
  if (i2) goto l10;
  *(OOC_INT32*)((_check_pointer(i0, 3071))+4) = 0;
  goto l11;
l10:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3041))+4);
  *(OOC_INT32*)((_check_pointer(i0, 3027))+4) = i2;
l11:
  i2 = *(OOC_INT32*)((_check_pointer(i1, 3120))+8);
  *(OOC_INT32*)((_check_pointer(i0, 3106))+8) = i2;
  i1 = *(OOC_INT32*)((_check_pointer(i1, 3159))+12);
  *(OOC_INT32*)((_check_pointer(i0, 3138))+12) = i1;
l12:
  return;
  ;
}

static void URI_Authority_ServerBased__ParseHost(Object__CharsLatin1 str, OOC_INT16 offset) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_INT16 i;
  OOC_INT16 j;
  OOC_INT16 lastLabelStart;
  auto OOC_CHAR8 URI_Authority_ServerBased__ParseHost_IsIPv4Address(Object__CharsLatin1 str);
  auto OOC_CHAR8 URI_Authority_ServerBased__ParseHost_SkipDigits(void);
  auto OOC_CHAR8 URI_Authority_ServerBased__ParseHost_SkipLabel(void);
  auto void URI_Authority_ServerBased__ParseHost_ErrorIPv4(void);
    
    OOC_CHAR8 URI_Authority_ServerBased__ParseHost_IsIPv4Address(Object__CharsLatin1 str) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_INT16 i;

      i = 0;
      i0 = (OOC_INT32)str;
      i1 = _check_pointer(i0, 3469);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i1 = *(OOC_UINT8*)(i1+(_check_index(0, i2, OOC_UINT16, 3469)));
      i1 = i1!=0u;
      if (!i1) goto l15;
      i1=0;
l3_loop:
      i2 = _check_pointer(i0, 3516);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i2 = *(OOC_UINT8*)(i2+(_check_index(i1, i3, OOC_UINT16, 3516)));
      i2 = URI_CharClass__IsDigit(i2);
      i2 = !i2;
      if (i2) goto l6;
      i2=0u;
      goto l8;
l6:
      i2 = _check_pointer(i0, 3527);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i2 = *(OOC_UINT8*)(i2+(_check_index(i1, i3, OOC_UINT16, 3527)));
      i2 = i2!=46u;
      
l8:
      if (!i2) goto l10;
      return 0u;
l10:
      i1 = i1+1;
      i = i1;
      i2 = _check_pointer(i0, 3469);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i2 = *(OOC_UINT8*)(i2+(_check_index(i1, i3, OOC_UINT16, 3469)));
      i2 = i2!=0u;
      if (i2) goto l3_loop;
l15:
      return 1u;
      ;
    }

    
    OOC_CHAR8 URI_Authority_ServerBased__ParseHost_SkipDigits(void) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5;
      OOC_INT16 start;
      OOC_INT16 val;

      i0 = (OOC_INT32)str;
      i1 = _check_pointer(i0, 3762);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i3 = i;
      i1 = *(OOC_UINT8*)(i1+(_check_index(i3, i2, OOC_UINT16, 3762)));
      i1 = URI_CharClass__IsDigit(i1);
      if (i1) goto l3;
      i1=0u;
      goto l9;
l3:
      i1 = _check_pointer(i0, 3783);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i1 = *(OOC_UINT8*)(i1+(_check_index(i3, i2, OOC_UINT16, 3783)));
      i1 = i1!=48u;
      if (i1) goto l6;
      i1 = _check_pointer(i0, 3820);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i1 = *(OOC_UINT8*)(i1+(_check_index((i3+1), i2, OOC_UINT16, 3820)));
      i1 = URI_CharClass__IsDigit(i1);
      i1 = !i1;
      
      goto l9;
l6:
      i1=1u;
l9:
      if (!i1) goto l24;
      start = i3;
      val = 0;
      i2=i3;i1=0;
l11_loop:
      i4 = i1<1000;
      if (!i4) goto l15;
      i4 = _check_pointer(i0, 3952);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = *(OOC_UINT8*)(i4+(_check_index(i2, i5, OOC_UINT16, 3952)));
      i1 = ((i1*10)+i4)-48;
      val = i1;
      
l15:
      i2 = i2+1;
      i = i2;
      i4 = _check_pointer(i0, 4036);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = *(OOC_UINT8*)(i4+(_check_index(i2, i5, OOC_UINT16, 4036)));
      i4 = URI_CharClass__IsDigit(i4);
      i4 = !i4;
      if (!i4) goto l11_loop;
l19:
      i0 = i1>255;
      if (i0) goto l22;
      return 1u;
      goto l24;
l22:
      i = i3;
l24:
      return 0u;
      ;
    }

    
    OOC_CHAR8 URI_Authority_ServerBased__ParseHost_SkipLabel(void) {
      register OOC_INT32 i0,i1,i2,i3;

      i0 = (OOC_INT32)str;
      i1 = _check_pointer(i0, 4325);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i3 = i;
      i1 = *(OOC_UINT8*)(i1+(_check_index(i3, i2, OOC_UINT16, 4325)));
      i1 = URI_CharClass__IsAlpha(i1);
      if (!i1) goto l16;
      i1=i3;
l3_loop:
      i1 = i1+1;
      i = i1;
      i2 = _check_pointer(i0, 4408);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i2 = *(OOC_UINT8*)(i2+(_check_index(i1, i3, OOC_UINT16, 4408)));
      i2 = URI_CharClass__IsAlphaNum(i2);
      i2 = !i2;
      if (i2) goto l6;
      i2=0u;
      goto l8;
l6:
      i2 = _check_pointer(i0, 4419);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i2 = *(OOC_UINT8*)(i2+(_check_index(i1, i3, OOC_UINT16, 4419)));
      i2 = i2!=45u;
      
l8:
      if (!i2) goto l3_loop;
l11:
      i0 = _check_pointer(i0, 4468);
      i2 = OOC_ARRAY_LENGTH(i0, 0);
      i1 = i1-1;
      i0 = *(OOC_UINT8*)(i0+(_check_index(i1, i2, OOC_UINT16, 4468)));
      i0 = URI_CharClass__IsAlphaNum(i0);
      i0 = !i0;
      if (i0) goto l14;
      return 1u;
      goto l16;
l14:
      i = i1;
l16:
      return 0u;
      ;
    }

    
    void URI_Authority_ServerBased__ParseHost_ErrorIPv4(void) {
      register OOC_INT32 i0,i1,i2;

      i0 = i;
      i1 = offset;
      i2 = (OOC_INT32)RT0__NewObject(_td_Exception__ParseError.baseTypes[0]);
      Exception__ParseErrorDesc_INIT((Exception__ParseError)i2, (Object__String)((OOC_INT32)_c0), (i0+i1));
      Exception__Raise((void*)i2);
      
      ;
    }


  i = 0;
  i0 = (OOC_INT32)str;
  i0 = URI_Authority_ServerBased__ParseHost_IsIPv4Address((Object__CharsLatin1)i0);
  if (i0) goto l22;
l3_loop:
  i0 = i;
  lastLabelStart = i0;
  i0 = URI_Authority_ServerBased__ParseHost_SkipLabel();
  i0 = !i0;
  if (!i0) goto l6;
  URI_Authority_ServerBased__ParseHost_ErrorIPv4();
l6:
  i0 = (OOC_INT32)str;
  i1 = _check_pointer(i0, 5280);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i3 = i;
  i1 = *(OOC_UINT8*)(i1+(_check_index(i3, i2, OOC_UINT16, 5280)));
  i1 = i1==46u;
  if (!i1) goto l18;
  i1 = i3+1;
  i = i1;
  i2 = _check_pointer(i0, 5332);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = *(OOC_UINT8*)(i2+(_check_index(i1, i3, OOC_UINT16, 5332)));
  i2 = i2==0u;
  if (i2) goto l12;
  i2 = _check_pointer(i0, 5349);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i1 = *(OOC_UINT8*)(i2+(_check_index(i1, i3, OOC_UINT16, 5349)));
  i1 = i1==58u;
  
  goto l14;
l12:
  i1=1u;
l14:
  if (!i1) goto l3_loop;
l18:
  i0 = _check_pointer(i0, 5479);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i2 = lastLabelStart;
  i0 = *(OOC_UINT8*)(i0+(_check_index(i2, i1, OOC_UINT16, 5479)));
  i0 = URI_CharClass__IsAlpha(i0);
  i0 = !i0;
  if (!i0) goto l38;
  i0 = offset;
  i1 = i;
  i2 = (OOC_INT32)RT0__NewObject(_td_Exception__ParseError.baseTypes[0]);
  Exception__ParseErrorDesc_INIT((Exception__ParseError)i2, (Object__String)((OOC_INT32)_c1), (i1+i0));
  Exception__Raise((void*)i2);
  goto l38;
l22:
  j = 1;
l23_loop:
  i0 = URI_Authority_ServerBased__ParseHost_SkipDigits();
  i0 = !i0;
  if (!i0) goto l26;
  URI_Authority_ServerBased__ParseHost_ErrorIPv4();
l26:
  i0 = j;
  i1 = i0<4;
  if (!i1) goto l33;
  i1 = (OOC_INT32)str;
  i1 = _check_pointer(i1, 5039);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i3 = i;
  i1 = *(OOC_UINT8*)(i1+(_check_index(i3, i2, OOC_UINT16, 5039)));
  i1 = i1==46u;
  if (i1) goto l31;
  URI_Authority_ServerBased__ParseHost_ErrorIPv4();
  goto l33;
l31:
  i = (i3+1);
l33:
  i0 = i0+1;
  j = i0;
  i0 = i0<=4;
  if (i0) goto l23_loop;
l38:
  return;
  ;
}

void URI_Authority_ServerBased__AuthorityDesc_ParseAuthority(URI_Authority_ServerBased__Authority auth, Object__CharsLatin1 str, OOC_INT16 offset) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_INT16 i;
  Object__String userinfo;
  OOC_INT16 start;
  Object__String8 host;
  OOC_INT32 port;

  i0 = (OOC_INT32)str;
  i1 = _check_pointer(i0, 5935);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_UINT8*)(i1+(_check_index(0, i2, OOC_UINT8, 5935)));
  switch (i1) {
  case 47u:
  case 63u:
  case 35u:
  case 0u:
    return;
    goto l4;
  default:
    goto l4;
  }
l4:
  i = 0;
  i1 = _check_pointer(i0, 6107);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_UINT8*)(i1+(_check_index(0, i2, OOC_UINT16, 6107)));
  i1 = i1!=0u;
  if (i1) goto l7;
  i1=0u;
  goto l9;
l7:
  i1 = _check_pointer(i0, 6123);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_UINT8*)(i1+(_check_index(0, i2, OOC_UINT16, 6123)));
  i1 = i1!=64u;
  
l9:
  if (i1) goto l11;
  i1=0;
  goto l21;
l11:
  i1=0;
l12_loop:
  i1 = i1+1;
  i = i1;
  i2 = _check_pointer(i0, 6107);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = *(OOC_UINT8*)(i2+(_check_index(i1, i3, OOC_UINT16, 6107)));
  i2 = i2!=0u;
  if (i2) goto l15;
  i2=0u;
  goto l17;
l15:
  i2 = _check_pointer(i0, 6123);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = *(OOC_UINT8*)(i2+(_check_index(i1, i3, OOC_UINT16, 6123)));
  i2 = i2!=64u;
  
l17:
  if (i2) goto l12_loop;
l21:
  userinfo = (Object__String)(OOC_INT32)0;
  i2 = _check_pointer(i0, 6197);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i1 = *(OOC_UINT8*)(i2+(_check_index(i1, i3, OOC_UINT16, 6197)));
  i1 = i1!=0u;
  if (i1) goto l24;
  i = 0;
  i1=(OOC_INT32)0;
  goto l53;
l24:
  i = 0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 6329)), 0);
  i1 = URI_CharClass__SkipUnreserved((void*)(_check_pointer(i0, 6329)), i1, (void*)(OOC_INT32)&i);
  if (i1) goto l27;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 6376)), 0);
  i1 = URI_CharClass__SkipEscaped((void*)(_check_pointer(i0, 6376)), i1, (void*)(OOC_INT32)&i);
  
  goto l29;
l27:
  i1=1u;
l29:
  if (i1) goto l31;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 6422)), 0);
  i1 = URI_CharClass__SkipMember((void*)(_check_pointer(i0, 6422)), i1, (void*)(OOC_INT32)&i, ";:&=+$,", 8);
  
  goto l33;
l31:
  i1=1u;
l33:
  if (!i1) goto l48;
l35_loop:
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 6329)), 0);
  i1 = URI_CharClass__SkipUnreserved((void*)(_check_pointer(i0, 6329)), i1, (void*)(OOC_INT32)&i);
  if (i1) goto l38;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 6376)), 0);
  i1 = URI_CharClass__SkipEscaped((void*)(_check_pointer(i0, 6376)), i1, (void*)(OOC_INT32)&i);
  
  goto l40;
l38:
  i1=1u;
l40:
  if (i1) goto l42;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 6422)), 0);
  i1 = URI_CharClass__SkipMember((void*)(_check_pointer(i0, 6422)), i1, (void*)(OOC_INT32)&i, ";:&=+$,", 8);
  
  goto l44;
l42:
  i1=1u;
l44:
  if (i1) goto l35_loop;
l48:
  i1 = _check_pointer(i0, 6466);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i3 = i;
  i1 = *(OOC_UINT8*)(i1+(_check_index(i3, i2, OOC_UINT16, 6466)));
  i1 = i1==64u;
  if (i1) goto l51;
  i1 = offset;
  i2 = (OOC_INT32)RT0__NewObject(_td_Exception__ParseError.baseTypes[0]);
  Exception__ParseErrorDesc_INIT((Exception__ParseError)i2, (Object__String)((OOC_INT32)_c2), (i3+i1));
  Exception__Raise((void*)i2);
  i1=(OOC_INT32)0;
  goto l53;
l51:
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 6545)), 0);
  i1 = (OOC_INT32)Object__NewLatin1Region((void*)(_check_pointer(i0, 6545)), i1, 0, i3);
  i1 = (OOC_INT32)URI_String__Unescape((Object__String)i1);
  i2 = i;
  userinfo = (Object__String)i1;
  i = (i2+1);
  
l53:
  i2 = i;
  start = i2;
  i3 = _check_pointer(i0, 6860);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = *(OOC_UINT8*)(i3+(_check_index(i2, i4, OOC_UINT16, 6860)));
  i3 = i3!=0u;
  if (i3) goto l56;
  i3=0u;
  goto l58;
l56:
  i3 = _check_pointer(i0, 6876);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = *(OOC_UINT8*)(i3+(_check_index(i2, i4, OOC_UINT16, 6876)));
  i3 = i3!=58u;
  
l58:
  if (!i3) goto l68;
l59_loop:
  i3 = i;
  i3 = i3+1;
  i = i3;
  i4 = _check_pointer(i0, 6860);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = *(OOC_UINT8*)(i4+(_check_index(i3, i5, OOC_UINT16, 6860)));
  i4 = i4!=0u;
  if (i4) goto l62;
  i3=0u;
  goto l64;
l62:
  i4 = _check_pointer(i0, 6876);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i3 = *(OOC_UINT8*)(i4+(_check_index(i3, i5, OOC_UINT16, 6876)));
  i3 = i3!=58u;
  
l64:
  if (i3) goto l59_loop;
l68:
  i3 = i;
  i4 = i3==i2;
  if (i4) goto l71;
  i4 = OOC_ARRAY_LENGTH((_check_pointer(i0, 7097)), 0);
  i3 = (OOC_INT32)Object__NewLatin1Region((void*)(_check_pointer(i0, 7097)), i4, i2, i3);
  host = (Object__String8)i3;
  i3 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)i3);
  i4 = offset;
  URI_Authority_ServerBased__ParseHost((Object__CharsLatin1)i3, (i4+i2));
  goto l72;
l71:
  i2 = offset;
  i4 = (OOC_INT32)RT0__NewObject(_td_Exception__ParseError.baseTypes[0]);
  Exception__ParseErrorDesc_INIT((Exception__ParseError)i4, (Object__String)((OOC_INT32)_c3), (i3+i2));
  Exception__Raise((void*)i4);
l72:
  port = (-1);
  i2 = _check_pointer(i0, 7213);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = i;
  i2 = *(OOC_UINT8*)(i2+(_check_index(i4, i3, OOC_UINT16, 7213)));
  i2 = i2==58u;
  if (i2) goto l75;
  i2=(-1);
  goto l96;
l75:
  i2 = i4+1;
  i = i2;
  i3 = i2+1;
  start = i3;
  i4 = _check_pointer(i0, 7277);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = *(OOC_UINT8*)(i4+(_check_index(i2, i5, OOC_UINT16, 7277)));
  i4 = i4!=0u;
  if (i4) goto l78;
  i2=(-1);
  goto l96;
l78:
  port = 0;
  i4 = _check_pointer(i0, 7347);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = *(OOC_UINT8*)(i4+(_check_index(i2, i5, OOC_UINT16, 7347)));
  i4 = URI_CharClass__IsDigit(i4);
  if (i4) goto l81;
  i2=0;
  goto l91;
l81:
  i4=i2;i2=0;
l82_loop:
  i5 = i2<1000000;
  if (!i5) goto l86;
  i5 = _check_pointer(i0, 7425);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = *(OOC_UINT8*)(i5+(_check_index(i4, i6, OOC_UINT16, 7425)));
  i2 = ((i2*10)+i5)-48;
  port = i2;
  
l86:
  i4 = i4+1;
  i = i4;
  i5 = _check_pointer(i0, 7347);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = *(OOC_UINT8*)(i5+(_check_index(i4, i6, OOC_UINT16, 7347)));
  i5 = URI_CharClass__IsDigit(i5);
  if (i5) goto l82_loop;
l91:
  i4 = i2>65535;
  if (!i4) goto l96;
  i4 = offset;
  i5 = (OOC_INT32)RT0__NewObject(_td_Exception__ParseError.baseTypes[0]);
  Exception__ParseErrorDesc_INIT((Exception__ParseError)i5, (Object__String)((OOC_INT32)_c4), (i3+i4));
  Exception__Raise((void*)i5);
l96:
  i0 = _check_pointer(i0, 7712);
  i3 = OOC_ARRAY_LENGTH(i0, 0);
  i4 = i;
  i0 = *(OOC_UINT8*)(i0+(_check_index(i4, i3, OOC_UINT16, 7712)));
  i0 = i0!=0u;
  if (!i0) goto l99;
  i0 = offset;
  i3 = (OOC_INT32)RT0__NewObject(_td_Exception__ParseError.baseTypes[0]);
  Exception__ParseErrorDesc_INIT((Exception__ParseError)i3, (Object__String)((OOC_INT32)_c5), (i4+i0));
  Exception__Raise((void*)i3);
l99:
  i0 = (OOC_INT32)auth;
  *(OOC_INT32*)(_check_pointer(i0, 7849)) = i1;
  i1 = (OOC_INT32)host;
  *(OOC_INT32*)((_check_pointer(i0, 7881))+4) = i1;
  i1 = i2==(-1);
  if (i1) goto l102;
  *(OOC_INT32*)((_check_pointer(i0, 7987))+8) = i2;
  goto l103;
l102:
  i1 = *(OOC_INT32*)((_check_pointer(i0, 7954))+12);
  *(OOC_INT32*)((_check_pointer(i0, 7940))+8) = i1;
l103:
  return;
  ;
}

void URI_Authority_ServerBased__AuthorityDesc_WriteXML(URI_Authority_ServerBased__Authority auth, TextRider__Writer w) {
  register OOC_INT32 i0,i1,i2;
  OOC_CHAR8 str[32];

  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8141)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, "\012<authority-server-based>", 26);
  i1 = (OOC_INT32)auth;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 8204));
  i2 = i2!=0;
  if (!i2) goto l3;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8234)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, "\012<userinfo>", 12);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 8297));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8278)))), TextRider__WriterDesc_WriteObject)),TextRider__WriterDesc_WriteObject)((TextRider__Writer)i0, (Object__Object)i2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8317)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, "</userinfo>", 12);
l3:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8362)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, "\012<host>", 8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8419))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8400)))), TextRider__WriterDesc_WriteObject)),TextRider__WriterDesc_WriteObject)((TextRider__Writer)i0, (Object__Object)i2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8433)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, "</host>", 8);
  i2 = *(OOC_INT32*)((_check_pointer(i1, 8472))+8);
  i2 = i2>=0;
  if (!i2) goto l6;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8497)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, "\012<port>", 8);
  i1 = *(OOC_INT32*)((_check_pointer(i1, 8557))+8);
  IntStr__IntToStr(i1, (void*)(OOC_INT32)str, 32);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8578)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (void*)(OOC_INT32)str, 32);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8606)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, "</port>", 8);
l6:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8647)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, "\012</authority-server-based>", 27);
  return;
  ;
}

void URI_Authority_ServerBased__AuthorityDesc_Append(URI_Authority_ServerBased__Authority auth, ADT_StringBuffer__StringBuffer sb) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_CHAR8 s[32];

  i0 = (OOC_INT32)sb;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8830)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c6));
  i1 = (OOC_INT32)auth;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 8857));
  i2 = i2!=0;
  if (!i2) goto l3;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 8910));
  URI_String__AppendEscaped((Object__String)i2, ";:&=+$,", 8, (ADT_StringBuffer__StringBuffer)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8964)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c7));
l3:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 9005))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8993)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i2);
  i2 = *(OOC_INT32*)((_check_pointer(i1, 9025))+8);
  i2 = i2>=0;
  if (i2) goto l6;
  i2=0u;
  goto l8;
l6:
  i2 = *(OOC_INT32*)((_check_pointer(i1, 9056))+12);
  i3 = *(OOC_INT32*)((_check_pointer(i1, 9044))+8);
  i2 = i3!=i2;
  
l8:
  if (!i2) goto l10;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9083)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c8));
  i1 = *(OOC_INT32*)((_check_pointer(i1, 9123))+8);
  IntStr__IntToStr(i1, (void*)(OOC_INT32)s, 32);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9142)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i0, (void*)(OOC_INT32)s, 32);
l10:
  return;
  ;
}

void OOC_URI_Authority_ServerBased_init(void) {
  _c0 = Object__NewLatin1Region("Malformed IPv4 address in authority component", 46, 0, 45);
  _c1 = Object__NewLatin1Region("Malformed host name in authority component", 43, 0, 42);
  _c2 = Object__NewLatin1Region("Illegal character in user info part of authority component", 59, 0, 58);
  _c3 = Object__NewLatin1Region("Host name in authority component is empty", 42, 0, 41);
  _c4 = Object__NewLatin1Region("Port number out of range in authority component", 48, 0, 47);
  _c5 = Object__NewLatin1Region("Junk after authority component", 31, 0, 30);
  _c6 = Object__NewLatin1Region("//", 3, 0, 2);
  _c7 = Object__NewLatin1Char(64u);
  _c8 = Object__NewLatin1Char(58u);

  return;
  ;
}

/* --- */
