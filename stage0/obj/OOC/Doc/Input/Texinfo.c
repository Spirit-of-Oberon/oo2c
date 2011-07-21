#include <OOC/Doc/Input/Texinfo.d>
#include <__oo2c.h>
#include <setjmp.h>

void OOC_Doc_Input_Texinfo__ErrorContextDesc_GetTemplate(OOC_Doc_Input_Texinfo__ErrorContext context, Msg__Msg msg, Msg__LString templ, OOC_LEN templ_0d) {
  register OOC_INT32 i0,i1;
  OOC_CHAR16 t[128];

  i0 = (OOC_INT32)msg;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 4361))+8);
  switch (i1) {
  case 1:
    _copy_16((const void*)((OOC_CHAR16[]){85,110,107,110,111,119,110,32,84,101,120,105,110,102,111,32,99,111,109,109,97,110,100,32,110,97,109,101,32,96,64,36,123,110,97,109,101,125,39,0}),(void*)(OOC_INT32)t,128);
    goto l16;
  case 2:
    _copy_16((const void*)((OOC_CHAR16[]){69,120,112,101,99,116,101,100,32,97,114,103,117,109,101,110,116,32,100,101,108,105,109,105,116,101,114,32,96,123,39,0}),(void*)(OOC_INT32)t,128);
    goto l16;
  case 3:
    _copy_16((const void*)((OOC_CHAR16[]){69,120,112,101,99,116,101,100,32,97,114,103,117,109,101,110,116,32,100,101,108,105,109,105,116,101,114,32,96,125,39,0}),(void*)(OOC_INT32)t,128);
    goto l16;
  case 4:
    _copy_16((const void*)((OOC_CHAR16[]){74,117,110,107,32,97,102,116,101,114,32,101,110,100,32,111,102,32,116,101,120,116,0}),(void*)(OOC_INT32)t,128);
    goto l16;
  case 5:
    _copy_16((const void*)((OOC_CHAR16[]){74,117,110,107,32,97,116,32,101,110,100,32,111,102,32,108,105,110,101,0}),(void*)(OOC_INT32)t,128);
    goto l16;
  case 6:
    _copy_16((const void*)((OOC_CHAR16[]){69,120,112,101,99,116,101,100,32,105,116,101,109,32,109,97,114,107,0}),(void*)(OOC_INT32)t,128);
    goto l16;
  case 7:
    _copy_16((const void*)((OOC_CHAR16[]){84,104,105,115,32,99,111,109,109,97,110,100,32,109,117,115,116,32,115,116,97,110,100,32,97,116,32,116,104,101,32,98,101,103,105,110,110,105,110,103,32,111,102,32,116,104,101,32,108,105,110,101,0}),(void*)(OOC_INT32)t,128);
    goto l16;
  case 8:
    _copy_16((const void*)((OOC_CHAR16[]){69,120,112,101,99,116,101,100,32,99,111,109,109,97,110,100,32,96,64,101,110,100,32,36,123,110,97,109,101,125,39,0}),(void*)(OOC_INT32)t,128);
    goto l16;
  case 9:
    _copy_16((const void*)((OOC_CHAR16[]){70,111,117,110,100,32,96,123,39,32,111,117,116,115,105,100,101,32,111,102,32,97,32,99,111,109,109,97,110,100,0}),(void*)(OOC_INT32)t,128);
    goto l16;
  case 10:
    _copy_16((const void*)((OOC_CHAR16[]){70,111,117,110,100,32,96,125,39,32,111,117,116,115,105,100,101,32,111,102,32,97,32,99,111,109,109,97,110,100,0}),(void*)(OOC_INT32)t,128);
    goto l16;
  case 11:
    _copy_16((const void*)((OOC_CHAR16[]){67,111,109,109,97,110,100,32,96,64,36,123,110,97,109,101,125,39,32,114,101,113,117,105,114,101,115,32,36,123,109,105,110,105,109,117,109,125,32,97,114,103,117,109,101,110,116,115,0}),(void*)(OOC_INT32)t,128);
    goto l16;
  case 12:
    _copy_16((const void*)((OOC_CHAR16[]){82,101,113,117,105,114,101,32,109,97,114,107,117,112,32,99,111,109,109,97,110,100,32,97,102,116,101,114,32,96,64,116,97,98,108,101,39,0}),(void*)(OOC_INT32)t,128);
    goto l16;
  case 13:
    _copy_16((const void*)((OOC_CHAR16[]){73,110,118,97,108,105,100,32,115,116,97,114,116,32,105,110,100,101,120,32,102,111,114,32,101,110,117,109,101,114,97,116,105,111,110,0}),(void*)(OOC_INT32)t,128);
    goto l16;
  default:
    _failed_case(i1, 4353);
    goto l16;
  }
l16:
  i1 = (OOC_INT32)context;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5308)))), OOC_Error__ContextDesc_BaseTemplate)),OOC_Error__ContextDesc_BaseTemplate)((OOC_Error__Context)i1, (Msg__Msg)i0, (void*)(OOC_INT32)t, 128, (void*)(OOC_INT32)templ, templ_0d);
  return;
  ;
}

static OOC_Doc_Input_Texinfo__Token OOC_Doc_Input_Texinfo__Tokenize(OOC_Scanner_SymList__Symbol sym, OOC_Scanner_InputBuffer__CharArray str, OOC_Error__List errList) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_Doc_Input_Texinfo__Token tokenList;
  OOC_Doc_Input_Texinfo__Token tokenTail;
  OOC_INT32 pos;
  OOC_CHAR8 beginningOfLine;
  OOC_INT32 currLine;
  OOC_INT32 currLinePos;
  OOC_INT32 currLineTab;
  OOC_INT32 startPos;
  OOC_INT32 startColumn;
  OOC_INT32 i;
  OOC_CHAR8 name[16];
  OOC_INT32 len;
  Msg__Msg lastError;
  auto void OOC_Doc_Input_Texinfo__Tokenize_Err(OOC_INT32 code);
  auto void OOC_Doc_Input_Texinfo__Tokenize_Append(OOC_Doc_Input_Texinfo__Token t);
  auto void OOC_Doc_Input_Texinfo__Tokenize_InitToken(OOC_Doc_Input_Texinfo__Token t, OOC_INT32 id);
  auto void OOC_Doc_Input_Texinfo__Tokenize_AddToken(OOC_INT32 id);
  auto void OOC_Doc_Input_Texinfo__Tokenize_AddText(void);
  auto OOC_CHAR8 OOC_Doc_Input_Texinfo__Tokenize_LookingAt(const OOC_CHAR8 pattern__ref[], OOC_LEN pattern_0d);
  auto OOC_CHAR8 OOC_Doc_Input_Texinfo__Tokenize_OutOfBandCommand(void);
  auto OOC_CHAR8 OOC_Doc_Input_Texinfo__Tokenize_IsTextChar(void);
  auto void OOC_Doc_Input_Texinfo__Tokenize_Newline(OOC_INT32 incr);
  auto OOC_CHAR8 OOC_Doc_Input_Texinfo__Tokenize_BeginningOfLine(OOC_INT32 pos);
    
    void OOC_Doc_Input_Texinfo__Tokenize_Err(OOC_INT32 code) {
      register OOC_INT32 i0,i1,i2;

      i0 = code;
      i1 = (OOC_INT32)OOC_Doc_Input_Texinfo__texinfoContext;
      i0 = (OOC_INT32)OOC_Error__New((OOC_Error__Context)i1, i0);
      lastError = (Msg__Msg)i0;
      i1 = (OOC_INT32)sym;
      i1 = *(OOC_INT32*)((_check_pointer(i1, 5955))+16);
      i2 = startPos;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5929)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i0, (OOC_CHAR8*)"pos", 4, (i1+i2));
      i0 = (OOC_INT32)lastError;
      i1 = currLine;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5987)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i0, (OOC_CHAR8*)"line", 5, i1);
      i0 = (OOC_INT32)lastError;
      i1 = startColumn;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6037)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i0, (OOC_CHAR8*)"column", 7, i1);
      i0 = (OOC_INT32)errList;
      i1 = (OOC_INT32)lastError;
      OOC_Error__ListDesc_Append((OOC_Error__List)i0, (Msg__Msg)i1);
      return;
      ;
    }

    
    void OOC_Doc_Input_Texinfo__Tokenize_Append(OOC_Doc_Input_Texinfo__Token t) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)t;
      *(OOC_INT32*)(_check_pointer(i0, 6181)) = 0;
      i1 = (OOC_INT32)tokenList;
      i1 = i1==0;
      if (i1) goto l3;
      i1 = (OOC_INT32)tokenTail;
      *(OOC_INT32*)(_check_pointer(i1, 6279)) = i0;
      goto l4;
l3:
      tokenList = (OOC_Doc_Input_Texinfo__Token)i0;
l4:
      tokenTail = (OOC_Doc_Input_Texinfo__Token)i0;
      return;
      ;
    }

    
    void OOC_Doc_Input_Texinfo__Tokenize_InitToken(OOC_Doc_Input_Texinfo__Token t, OOC_INT32 id) {
      register OOC_INT32 i0,i1,i2;

      i0 = (OOC_INT32)t;
      *(OOC_INT32*)(_check_pointer(i0, 6406)) = 0;
      i1 = id;
      *(OOC_INT8*)((_check_pointer(i0, 6428))+5) = i1;
      i1 = (OOC_INT32)sym;
      i1 = *(OOC_INT32*)((_check_pointer(i1, 6475))+16);
      i2 = startPos;
      *(OOC_INT32*)((_check_pointer(i0, 6463))+8) = (i1+i2);
      i1 = currLine;
      *(OOC_INT32*)((_check_pointer(i0, 6498))+12) = i1;
      i1 = startColumn;
      *(OOC_INT32*)((_check_pointer(i0, 6525))+16) = i1;
      i1 = beginningOfLine;
      *(OOC_UINT8*)((_check_pointer(i0, 6557))+4) = i1;
      *(OOC_INT32*)((_check_pointer(i0, 6590))+20) = 0;
      return;
      ;
    }

    
    void OOC_Doc_Input_Texinfo__Tokenize_AddToken(OOC_INT32 id) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Doc_Input_Texinfo__Token.baseTypes[0]);
      i1 = id;
      OOC_Doc_Input_Texinfo__Tokenize_InitToken((OOC_Doc_Input_Texinfo__Token)i0, i1);
      OOC_Doc_Input_Texinfo__Tokenize_Append((OOC_Doc_Input_Texinfo__Token)i0);
      beginningOfLine = 0u;
      return;
      ;
    }

    
    void OOC_Doc_Input_Texinfo__Tokenize_AddText(void) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9;
      OOC_Doc_Input_Texinfo__Token t;
      OOC_INT32 j;

      i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Doc_Input_Texinfo__Token.baseTypes[0]);
      t = (OOC_Doc_Input_Texinfo__Token)i0;
      OOC_Doc_Input_Texinfo__Tokenize_InitToken((OOC_Doc_Input_Texinfo__Token)i0, 42);
      OOC_Doc_Input_Texinfo__Tokenize_Append((OOC_Doc_Input_Texinfo__Token)i0);
      i1 = startPos;
      i2 = pos;
      i3 = i2-i1;
      beginningOfLine = 0u;
      *(OOC_INT32*)((_check_pointer(i0, 7040))+20) = ((OOC_INT32)RT0__NewObject(_td_OOC_Scanner_InputBuffer__CharArray.baseTypes[0], (i3+1)));
      j = i1;
      i4 = i1<i2;
      if (!i4) goto l8;
      i4 = (OOC_INT32)str;
      i5 = (i1*(-1))+i1;
      
l3_loop:
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7109))+20);
      i6 = _check_pointer(i6, 7113);
      i7 = OOC_ARRAY_LENGTH(i6, 0);
      i8 = _check_pointer(i4, 7132);
      i9 = OOC_ARRAY_LENGTH(i8, 0);
      i8 = *(OOC_UINT8*)(i8+(_check_index(i1, i9, OOC_UINT32, 7132)));
      *(OOC_UINT8*)(i6+(_check_index(i5, i7, OOC_UINT32, 7113))) = i8;
      i1 = i1+1;
      j = i1;
      i5 = i5+1;
      i6 = i1<i2;
      if (i6) goto l3_loop;
l8:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7154))+20);
      i0 = _check_pointer(i0, 7159);
      i1 = OOC_ARRAY_LENGTH(i0, 0);
      *(OOC_UINT8*)(i0+(_check_index(i3, i1, OOC_UINT32, 7159))) = 0u;
      return;
      ;
    }

    
    OOC_CHAR8 OOC_Doc_Input_Texinfo__Tokenize_LookingAt(const OOC_CHAR8 pattern__ref[], OOC_LEN pattern_0d) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
      OOC_ALLOCATE_VPAR(pattern,OOC_CHAR8 ,pattern_0d)
      OOC_INT32 i;

      OOC_INITIALIZE_VPAR(pattern__ref,pattern,OOC_CHAR8 ,pattern_0d)
      i = 0;
      i0 = *(OOC_UINT8*)((OOC_INT32)pattern+(_check_index(0, pattern_0d, OOC_UINT32, 7327)));
      i0 = i0!=0u;
      if (i0) goto l3;
      i0=0u;
      goto l5;
l3:
      i0 = (OOC_INT32)str;
      i0 = _check_pointer(i0, 7343);
      i1 = OOC_ARRAY_LENGTH(i0, 0);
      i2 = pos;
      i3 = *(OOC_UINT8*)((OOC_INT32)pattern+(_check_index(0, pattern_0d, OOC_UINT32, 7360)));
      i0 = *(OOC_UINT8*)(i0+(_check_index(i2, i1, OOC_UINT32, 7343)));
      i0 = i0==i3;
      
l5:
      if (i0) goto l7;
      i0=0;
      goto l17;
l7:
      i0 = (OOC_INT32)str;
      i1 = pos;
      i3=i1;i2=0;
l8_loop:
      i2 = i2+1;
      i = i2;
      i4 = *(OOC_UINT8*)((OOC_INT32)pattern+(_check_index(i2, pattern_0d, OOC_UINT32, 7327)));
      i3 = i3+1;
      i4 = i4!=0u;
      if (i4) goto l11;
      i4=0u;
      goto l13;
l11:
      i4 = _check_pointer(i0, 7343);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i6 = *(OOC_UINT8*)((OOC_INT32)pattern+(_check_index(i2, pattern_0d, OOC_UINT32, 7360)));
      i4 = *(OOC_UINT8*)(i4+(_check_index(i3, i5, OOC_UINT32, 7343)));
      i4 = i4==i6;
      
l13:
      if (i4) goto l8_loop;
l16:
      i0 = i3-i1;
      
l17:
      i0 = *(OOC_UINT8*)((OOC_INT32)pattern+(_check_index(i0, pattern_0d, OOC_UINT32, 7416)));
      return (i0==0u);
      ;
    }

    
    OOC_CHAR8 OOC_Doc_Input_Texinfo__Tokenize_OutOfBandCommand(void) {
      register OOC_INT32 i0;

      i0 = OOC_Doc_Input_Texinfo__Tokenize_LookingAt((OOC_CHAR8*)"---", 4);
      if (i0) goto l3;
      i0 = OOC_Doc_Input_Texinfo__Tokenize_LookingAt((OOC_CHAR8*)"``", 3);
      
      goto l5;
l3:
      i0=1u;
l5:
      if (i0) goto l7;
      i0 = OOC_Doc_Input_Texinfo__Tokenize_LookingAt((OOC_CHAR8*)"\047\047", 3);
      
      goto l8;
l7:
      i0=1u;
l8:
      return i0;
      ;
    }

    
    OOC_CHAR8 OOC_Doc_Input_Texinfo__Tokenize_IsTextChar(void) {
      register OOC_INT32 i0,i1,i2;

      i0 = (OOC_INT32)str;
      i0 = _check_pointer(i0, 7662);
      i1 = OOC_ARRAY_LENGTH(i0, 0);
      i2 = pos;
      i0 = *(OOC_UINT8*)(i0+(_check_index(i2, i1, OOC_UINT32, 7662)));
      switch (i0) {
      case 64u:
      case 123u:
      case 125u:
      case 44u:
      case 10u:
      case 13u:
        return 0u;
        goto l4;
      default:
        return 1u;
        goto l4;
      }
l4:
      _failed_function(7614); return 0;
      ;
    }

    
    void OOC_Doc_Input_Texinfo__Tokenize_Newline(OOC_INT32 incr) {
      register OOC_INT32 i0,i1;

      i0 = pos;
      i1 = incr;
      i0 = i0+i1;
      pos = i0;
      beginningOfLine = 1u;
      currLinePos = i0;
      i0 = currLine;
      currLineTab = 0;
      currLine = (i0+1);
      return;
      ;
    }

    
    OOC_CHAR8 OOC_Doc_Input_Texinfo__Tokenize_BeginningOfLine(OOC_INT32 pos) {
      register OOC_INT32 i0,i1,i2,i3,i4;

      i0 = pos;
      i1 = i0!=0;
      if (i1) goto l3;
      i1=0u;
      goto l9;
l3:
      i1 = (OOC_INT32)str;
      i2 = _check_pointer(i1, 8103);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i4 = i0-1;
      i2 = *(OOC_UINT8*)(i2+(_check_index(i4, i3, OOC_UINT32, 8103)));
      i2 = i2==2u;
      if (i2) goto l6;
      i1 = _check_pointer(i1, 8158);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i1 = *(OOC_UINT8*)(i1+(_check_index(i4, i2, OOC_UINT32, 8158)));
      i1 = i1==3u;
      
      goto l9;
l6:
      i1=1u;
l9:
      if (!i1) goto l25;
      i1 = (OOC_INT32)str;
      
l12_loop:
      i0 = i0-1;
      pos = i0;
      i2 = i0!=0;
      if (i2) goto l15;
      i2=0u;
      goto l21;
l15:
      i2 = _check_pointer(i1, 8103);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i4 = i0-1;
      i2 = *(OOC_UINT8*)(i2+(_check_index(i4, i3, OOC_UINT32, 8103)));
      i2 = i2==2u;
      if (i2) goto l18;
      i2 = _check_pointer(i1, 8158);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i2 = *(OOC_UINT8*)(i2+(_check_index(i4, i3, OOC_UINT32, 8158)));
      i2 = i2==3u;
      
      goto l21;
l18:
      i2=1u;
l21:
      if (i2) goto l12_loop;
l25:
      i1 = i0==0;
      if (i1) goto l28;
      i1 = (OOC_INT32)str;
      i1 = _check_pointer(i1, 8254);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i1 = *(OOC_UINT8*)(i1+(_check_index((i0-1), i2, OOC_UINT32, 8254)));
      i1 = i1==13u;
      
      goto l30;
l28:
      i1=1u;
l30:
      if (i1) goto l32;
      i1 = (OOC_INT32)str;
      i1 = _check_pointer(i1, 8281);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i0 = *(OOC_UINT8*)(i1+(_check_index((i0-1), i2, OOC_UINT32, 8281)));
      i0 = i0==10u;
      
      goto l33;
l32:
      i0=1u;
l33:
      return i0;
      ;
    }


  tokenList = (OOC_Doc_Input_Texinfo__Token)(OOC_INT32)0;
  tokenTail = (OOC_Doc_Input_Texinfo__Token)(OOC_INT32)0;
  pos = 0;
  beginningOfLine = 1u;
  i0 = (OOC_INT32)sym;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 8431))+20);
  currLine = i1;
  i0 = *(OOC_INT32*)((_check_pointer(i0, 8458))+24);
  currLinePos = (-i0);
  currLineTab = 0;
  i0 = (OOC_INT32)str;
  i0 = _check_pointer(i0, 8505);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = *(OOC_UINT8*)(i0+(_check_index(0, i1, OOC_UINT32, 8505)));
  i0 = i0!=0u;
  if (!i0) goto l108;
l3_loop:
  i0 = pos;
  i1 = currLinePos;
  i2 = currLineTab;
  i3 = (i0-i1)+i2;
  startPos = i0;
  startColumn = i3;
  i4 = (OOC_INT32)str;
  i5 = _check_pointer(i4, 8607);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = *(OOC_UINT8*)(i5+(_check_index(i0, i6, OOC_UINT32, 8607)));
  switch (i5) {
  case 64u:
    i0 = i0+1;
    pos = i0;
    i1 = _check_pointer(i4, 8776);
    i2 = OOC_ARRAY_LENGTH(i1, 0);
    i1 = *(OOC_UINT8*)(i1+(_check_index(i0, i2, OOC_UINT32, 8776)));
    i1 = CharClass__IsLetter(i1);
    if (i1) goto l8;
    i1 = _check_pointer(i4, 9175);
    i2 = OOC_ARRAY_LENGTH(i1, 0);
    i1 = *(OOC_UINT8*)(i1+(_check_index(i0, i2, OOC_UINT32, 9175)));
    *(OOC_UINT8*)((OOC_INT32)name+(_check_index(0, 16, OOC_UINT8, 9165))) = i1;
    *(OOC_UINT8*)((OOC_INT32)name+(_check_index(1, 16, OOC_UINT8, 9196))) = 0u;
    len = 1;
    pos = (i0+1);
    goto l18;
l8:
    i = 0;
    i1=i0;i0=0;
l9_loop:
    i2 = i0<15;
    if (!i2) goto l13;
    i2 = _check_pointer(i4, 8923);
    i3 = OOC_ARRAY_LENGTH(i2, 0);
    i2 = *(OOC_UINT8*)(i2+(_check_index(i1, i3, OOC_UINT32, 8923)));
    *(OOC_UINT8*)((OOC_INT32)name+(_check_index(i0, 16, OOC_UINT32, 8913))) = i2;
    i0 = i0+1;
    i = i0;
    
l13:
    i1 = i1+1;
    pos = i1;
    i2 = _check_pointer(i4, 9031);
    i3 = OOC_ARRAY_LENGTH(i2, 0);
    i2 = *(OOC_UINT8*)(i2+(_check_index(i1, i3, OOC_UINT32, 9031)));
    i2 = CharClass__IsLetter(i2);
    i2 = !i2;
    if (!i2) goto l9_loop;
l17:
    len = i0;
    *(OOC_UINT8*)((OOC_INT32)name+(_check_index(i0, 16, OOC_UINT32, 9073))) = 0u;
l18:
    i = 37;
    i0 = (OOC_INT32)*(OOC_INT32*)((OOC_INT32)OOC_Doc_Input_Texinfo__cmdList+(_check_index(37, 38, OOC_UINT32, 9453))*4);
    i0 = (
    _cmp8((const void*)((_check_pointer(i0, 9456))+2),(const void*)(OOC_INT32)name))!=0;
    if (i0) goto l21;
    i0=37;
    goto l31;
l21:
    i0=37;
l22_loop:
    i0 = i0-1;
    i = i0;
    i1 = i0>=0;
    if (i1) goto l25;
    i1=0u;
    goto l27;
l25:
    i1 = (OOC_INT32)*(OOC_INT32*)((OOC_INT32)OOC_Doc_Input_Texinfo__cmdList+(_check_index(i0, 38, OOC_UINT32, 9453))*4);
    i1 = (
    _cmp8((const void*)((_check_pointer(i1, 9456))+2),(const void*)(OOC_INT32)name))!=0;
    
l27:
    if (i1) goto l22_loop;
l31:
    i1 = i0<0;
    if (i1) goto l45;
    i1 = 28<=i0;
    if (i1) goto l36;
    i0=0u;
    goto l38;
l36:
    i0 = i0<=37;
    
l38:
    if (i0) goto l40;
    i0=0u;
    goto l42;
l40:
    i0 = beginningOfLine;
    i0 = !i0;
    
l42:
    if (!i0) goto l46;
    OOC_Doc_Input_Texinfo__Tokenize_Err(7);
    goto l46;
l45:
    OOC_Doc_Input_Texinfo__Tokenize_Err(1);
    i0 = (OOC_INT32)Msg__GetStringPtr((void*)(OOC_INT32)name, 16);
    i1 = (OOC_INT32)lastError;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9626)))), Msg__MsgDesc_SetStringAttrib)),Msg__MsgDesc_SetStringAttrib)((Msg__Msg)i1, (OOC_CHAR8*)"name", 5, (Msg__StringPtr)i0);
    i = 38;
l46:
    i0 = i;
    OOC_Doc_Input_Texinfo__Tokenize_AddToken(i0);
    goto l103;
  case 123u:
    OOC_Doc_Input_Texinfo__Tokenize_AddToken(43);
    i0 = pos;
    pos = (i0+1);
    goto l103;
  case 125u:
    OOC_Doc_Input_Texinfo__Tokenize_AddToken(44);
    i0 = pos;
    pos = (i0+1);
    goto l103;
  case 44u:
    OOC_Doc_Input_Texinfo__Tokenize_AddToken(45);
    i0 = pos;
    pos = (i0+1);
    goto l103;
  case 10u:
    i0 = OOC_Doc_Input_Texinfo__Tokenize_BeginningOfLine(i0);
    if (!i0) goto l53;
    OOC_Doc_Input_Texinfo__Tokenize_AddText();
l53:
    OOC_Doc_Input_Texinfo__Tokenize_Newline(1);
    goto l103;
  case 13u:
    i0 = OOC_Doc_Input_Texinfo__Tokenize_BeginningOfLine(i0);
    if (!i0) goto l57;
    OOC_Doc_Input_Texinfo__Tokenize_AddText();
l57:
    i0 = (OOC_INT32)str;
    i0 = _check_pointer(i0, 10439);
    i1 = pos;
    i2 = OOC_ARRAY_LENGTH(i0, 0);
    i0 = *(OOC_UINT8*)(i0+(_check_index((i1+1), i2, OOC_UINT32, 10439)));
    i0 = i0==10u;
    if (i0) goto l60;
    OOC_Doc_Input_Texinfo__Tokenize_Newline(1);
    goto l103;
l60:
    OOC_Doc_Input_Texinfo__Tokenize_Newline(2);
    goto l103;
  case 2u:
    pos = (i0+1);
    goto l103;
  case 3u:
    i = i3;
    currLineTab = (i2+((8-(_mod(i3,8)))-1));
    pos = (i0+1);
    goto l103;
  default:
    i2 = OOC_Doc_Input_Texinfo__Tokenize_LookingAt((OOC_CHAR8*)"---", 4);
    if (i2) goto l101;
    i2 = OOC_Doc_Input_Texinfo__Tokenize_LookingAt((OOC_CHAR8*)"``", 3);
    if (i2) goto l99;
    i2 = OOC_Doc_Input_Texinfo__Tokenize_LookingAt((OOC_CHAR8*)"\047\047", 3);
    if (i2) goto l97;
    i2 = _check_pointer(i4, 11333);
    i3 = OOC_ARRAY_LENGTH(i2, 0);
    i0 = *(OOC_UINT8*)(i2+(_check_index(i0, i3, OOC_UINT32, 11333)));
    i0 = i0!=0u;
    if (i0) goto l73;
    i0=0u;
    goto l75;
l73:
    i0 = OOC_Doc_Input_Texinfo__Tokenize_IsTextChar();
    
l75:
    if (i0) goto l77;
    i0=0u;
    goto l79;
l77:
    i0 = OOC_Doc_Input_Texinfo__Tokenize_OutOfBandCommand();
    i0 = !i0;
    
l79:
    if (!i0) goto l96;
l80_loop:
    i0 = _check_pointer(i4, 11404);
    i2 = OOC_ARRAY_LENGTH(i0, 0);
    i3 = pos;
    i0 = *(OOC_UINT8*)(i0+(_check_index(i3, i2, OOC_UINT32, 11404)));
    i0 = i0==9u;
    if (!i0) goto l83;
    i0 = currLineTab;
    i2 = (i3-i1)+i0;
    i = i2;
    currLineTab = (i0+((8-(_mod(i2,8)))-1));
l83:
    i0 = i3+1;
    pos = i0;
    i2 = _check_pointer(i4, 11333);
    i3 = OOC_ARRAY_LENGTH(i2, 0);
    i0 = *(OOC_UINT8*)(i2+(_check_index(i0, i3, OOC_UINT32, 11333)));
    i0 = i0!=0u;
    if (i0) goto l86;
    i0=0u;
    goto l88;
l86:
    i0 = OOC_Doc_Input_Texinfo__Tokenize_IsTextChar();
    
l88:
    if (i0) goto l90;
    i0=0u;
    goto l92;
l90:
    i0 = OOC_Doc_Input_Texinfo__Tokenize_OutOfBandCommand();
    i0 = !i0;
    
l92:
    if (i0) goto l80_loop;
l96:
    OOC_Doc_Input_Texinfo__Tokenize_AddText();
    goto l103;
l97:
    OOC_Doc_Input_Texinfo__Tokenize_AddToken(41);
    i0 = pos;
    pos = (i0+2);
    goto l103;
l99:
    OOC_Doc_Input_Texinfo__Tokenize_AddToken(40);
    i0 = pos;
    pos = (i0+2);
    goto l103;
l101:
    OOC_Doc_Input_Texinfo__Tokenize_AddToken(39);
    i0 = pos;
    pos = (i0+3);
    goto l103;
  }
l103:
  i0 = (OOC_INT32)str;
  i0 = _check_pointer(i0, 8505);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i2 = pos;
  i0 = *(OOC_UINT8*)(i0+(_check_index(i2, i1, OOC_UINT32, 8505)));
  i0 = i0!=0u;
  if (i0) goto l3_loop;
l108:
  i0 = pos;
  i1 = currLinePos;
  i2 = currLineTab;
  startPos = i0;
  startColumn = ((i0-i1)+i2);
  OOC_Doc_Input_Texinfo__Tokenize_AddToken(46);
  i0 = (OOC_INT32)tokenList;
  return (OOC_Doc_Input_Texinfo__Token)i0;
  ;
}

static void OOC_Doc_Input_Texinfo__WriteTokens(Channel__Channel ch, OOC_Doc_Input_Texinfo__Token t) {
  register OOC_INT32 i0,i1,i2,i3;
  TextRider__Writer w;
  auto void OOC_Doc_Input_Texinfo__WriteTokens_WriteQuoted(TextRider__Writer w, OOC_CHAR8 str[], OOC_LEN str_0d, OOC_INT32 s, OOC_INT32 e);
    
    void OOC_Doc_Input_Texinfo__WriteTokens_WriteQuoted(TextRider__Writer w, OOC_CHAR8 str[], OOC_LEN str_0d, OOC_INT32 s, OOC_INT32 e) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5;
      OOC_INT32 last;

      i0 = s;
      i1 = e;
      i2 = i0!=i1;
      if (!i2) goto l78;
      i3 = (OOC_INT32)w;
      
l3_loop:
      last = i0;
      if (i2) goto l6;
      i2=0u;
      goto l8;
l6:
      i2 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 12118)));
      i2 = i2!=38u;
      
l8:
      if (i2) goto l10;
      i2=0u;
      goto l12;
l10:
      i2 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 12135)));
      i2 = i2!=60u;
      
l12:
      if (i2) goto l14;
      i2=0u;
      goto l16;
l14:
      i2 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 12152)));
      i2 = i2!=62u;
      
l16:
      if (i2) goto l18;
      i2=0u;
      goto l20;
l18:
      i2 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 12184)));
      i2 = i2!=9u;
      
l20:
      if (i2) goto l22;
      i2=0u;
      goto l24;
l22:
      i2 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 12201)));
      i2 = i2!=10u;
      
l24:
      if (i2) goto l26;
      i2=0u;
      goto l28;
l26:
      i2 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 12218)));
      i2 = i2!=13u;
      
l28:
      if (i2) goto l30;
      i2=i0;
      goto l60;
l30:
      i2=i0;
l31_loop:
      i2 = i2+1;
      s = i2;
      i4 = i2!=i1;
      if (i4) goto l34;
      i4=0u;
      goto l36;
l34:
      i4 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i2, str_0d, OOC_UINT32, 12118)));
      i4 = i4!=38u;
      
l36:
      if (i4) goto l38;
      i4=0u;
      goto l40;
l38:
      i4 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i2, str_0d, OOC_UINT32, 12135)));
      i4 = i4!=60u;
      
l40:
      if (i4) goto l42;
      i4=0u;
      goto l44;
l42:
      i4 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i2, str_0d, OOC_UINT32, 12152)));
      i4 = i4!=62u;
      
l44:
      if (i4) goto l46;
      i4=0u;
      goto l48;
l46:
      i4 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i2, str_0d, OOC_UINT32, 12184)));
      i4 = i4!=9u;
      
l48:
      if (i4) goto l50;
      i4=0u;
      goto l52;
l50:
      i4 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i2, str_0d, OOC_UINT32, 12201)));
      i4 = i4!=10u;
      
l52:
      if (i4) goto l54;
      i4=0u;
      goto l56;
l54:
      i4 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i2, str_0d, OOC_UINT32, 12218)));
      i4 = i4!=13u;
      
l56:
      if (i4) goto l31_loop;
l60:
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 12272))+8);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 12272))+8);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 12284)))), Channel__WriterDesc_WriteBytes)),Channel__WriterDesc_WriteBytes)((Channel__Writer)i5, (void*)(OOC_INT32)str, (-1), i0, (i2-i0));
      i0 = i2!=i1;
      if (i0) goto l63;
      i0=i2;
      goto l73;
l63:
      i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i2, str_0d, OOC_UINT32, 12360)));
      switch (i0) {
      case 38u:
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 12385)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i3, (OOC_CHAR8*)"&amp;", 6);
        goto l72;
      case 60u:
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 12427)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i3, (OOC_CHAR8*)"&lt;", 5);
        goto l72;
      case 62u:
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 12468)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i3, (OOC_CHAR8*)"&gt;", 5);
        goto l72;
      case 9u:
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 12509)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i3, (OOC_CHAR8*)"&#9;", 5);
        goto l72;
      case 10u:
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 12550)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i3, (OOC_CHAR8*)"&#10;", 6);
        goto l72;
      case 13u:
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 12592)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i3, (OOC_CHAR8*)"&#13;", 6);
        goto l72;
      default:
        _failed_case(i0, 12352);
        goto l72;
      }
l72:
      i0 = i2+1;
      s = i0;
      
l73:
      i2 = i0!=i1;
      if (i2) goto l3_loop;
l78:
      return;
      ;
    }


  i0 = (OOC_INT32)ch;
  i0 = (OOC_INT32)TextRider__ConnectWriter((Channel__Channel)i0);
  w = (TextRider__Writer)i0;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12745)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (OOC_CHAR8*)"<?xml version=\0471.0\047 encoding=\047ISO-8859-1\047 standalone=\047yes\047?>", 61);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12830)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (OOC_CHAR8*)"<token-list>", 13);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12867)))), TextRider__WriterDesc_WriteLn)),TextRider__WriterDesc_WriteLn)((TextRider__Writer)i0);
  i1 = (OOC_INT32)t;
  i2 = i1!=(OOC_INT32)0;
  if (!i2) goto l28;
  
l4_loop:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12908)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (OOC_CHAR8*)"  <token id=\047", 14);
  i2 = *(OOC_INT8*)((_check_pointer(i1, 12953))+5);
  switch (i2) {
  case 38:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12982)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (OOC_CHAR8*)"#unknown", 9);
    goto l16;
  case 39:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13029)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (OOC_CHAR8*)"#---", 5);
    goto l16;
  case 40:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13074)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (OOC_CHAR8*)"#``", 4);
    goto l16;
  case 41:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13119)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (OOC_CHAR8*)"#\047\047", 4);
    goto l16;
  case 42:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13159)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (OOC_CHAR8*)"#text", 6);
    goto l16;
  case 43:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13209)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (OOC_CHAR8*)"#{", 3);
    goto l16;
  case 44:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13256)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (OOC_CHAR8*)"#}", 3);
    goto l16;
  case 45:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13303)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (OOC_CHAR8*)"#,", 3);
    goto l16;
  case 46:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13347)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (OOC_CHAR8*)"#end-of-text", 13);
    goto l16;
  default:
    i2 = *(OOC_INT8*)((_check_pointer(i1, 13422))+5);
    i2 = (OOC_INT32)*(OOC_INT32*)((OOC_INT32)OOC_Doc_Input_Texinfo__cmdList+(_check_index(i2, 38, OOC_UINT8, 13420))*4);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13398)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (void*)((_check_pointer(i2, 13427))+2), 16);
    goto l16;
  }
l16:
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 13456))+4);
  if (!i2) goto l19;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13476)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (OOC_CHAR8*)"\047 bol=\047yes", 11);
l19:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13524)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (OOC_CHAR8*)"\047 pos=\047", 8);
  i2 = *(OOC_INT32*)((_check_pointer(i1, 13572))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13558)))), TextRider__WriterDesc_WriteLInt)),TextRider__WriterDesc_WriteLInt)((TextRider__Writer)i0, i2, 0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13590)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (OOC_CHAR8*)"\047 line=\047", 9);
  i2 = *(OOC_INT32*)((_check_pointer(i1, 13639))+12);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13625)))), TextRider__WriterDesc_WriteLInt)),TextRider__WriterDesc_WriteLInt)((TextRider__Writer)i0, i2, 0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13658)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (OOC_CHAR8*)"\047 column=\047", 11);
  i2 = *(OOC_INT32*)((_check_pointer(i1, 13709))+16);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13695)))), TextRider__WriterDesc_WriteLInt)),TextRider__WriterDesc_WriteLInt)((TextRider__Writer)i0, i2, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 13734))+20);
  i2 = i2!=(OOC_INT32)0;
  if (i2) goto l22;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13902)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (OOC_CHAR8*)"\047/>", 4);
  
  goto l23;
l22:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13761)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (OOC_CHAR8*)"\047>", 3);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 13836))+20);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 13836))+20);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 13841)), 0);
  i2 = Strings__Length((void*)(_check_pointer(i3, 13841)), i2);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 13808))+20);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 13808))+20);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 13813)), 0);
  OOC_Doc_Input_Texinfo__WriteTokens_WriteQuoted((TextRider__Writer)i0, (void*)(_check_pointer(i1, 13813)), i3, 0, i2);
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13855)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (OOC_CHAR8*)"</token>", 9);
  
l23:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13942)))), TextRider__WriterDesc_WriteLn)),TextRider__WriterDesc_WriteLn)((TextRider__Writer)i0);
  i1 = (OOC_INT32)t;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 13965));
  t = (OOC_Doc_Input_Texinfo__Token)i1;
  i2 = i1!=(OOC_INT32)0;
  if (i2) goto l4_loop;
l28:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13986)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (OOC_CHAR8*)"</token-list>", 14);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14024)))), TextRider__WriterDesc_WriteLn)),TextRider__WriterDesc_WriteLn)((TextRider__Writer)i0);
  return;
  ;
}

OOC_Doc__Document OOC_Doc_Input_Texinfo__Parse(OOC_Scanner_SymList__Symbol sym, OOC_CHAR8 removeDecoration, OOC_Error__List errList) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_Doc_TextBuffer__Buffer buffer;
  OOC_Scanner_InputBuffer__CharArray str;
  OOC_Doc_Decoration__Decoration decoration;
  OOC_INT32 oldErrors;
  OOC_Doc_Input_Texinfo__Token tokenList;
  OOC_Doc_Input_Texinfo__Token token;
  OOC_Doc__BlockElement blockList;
  Msg__Msg lastError;
  struct OOC_Doc__Position bufferPos;
  auto OOC_CHAR8 OOC_Doc_Input_Texinfo__Parse_IsInlineToken(OOC_Doc_Input_Texinfo__Token t);
  auto OOC_CHAR8 OOC_Doc_Input_Texinfo__Parse_IsBlockToken(OOC_Doc_Input_Texinfo__Token t);
  auto void OOC_Doc_Input_Texinfo__Parse_Err(OOC_INT32 code);
  auto void OOC_Doc_Input_Texinfo__Parse_NextToken(void);
  auto void OOC_Doc_Input_Texinfo__Parse_CheckToken(OOC_INT8 id);
  auto void OOC_Doc_Input_Texinfo__Parse_SkipWhitespace(void);
  auto OOC_CHAR8 OOC_Doc_Input_Texinfo__Parse_IdToChar(OOC_INT8 id);
  auto OOC_INT32 OOC_Doc_Input_Texinfo__Parse_IdToGlyph(OOC_INT8 id);
  auto OOC_INT32 OOC_Doc_Input_Texinfo__Parse_IdToMark(OOC_INT8 id);
  auto OOC_CHAR8 OOC_Doc_Input_Texinfo__Parse_IsOberonRef(OOC_INT32 mark);
  auto OOC_Doc__BlockElement OOC_Doc_Input_Texinfo__Parse_ParseBlockList(void);
    
    OOC_CHAR8 OOC_Doc_Input_Texinfo__Parse_IsInlineToken(OOC_Doc_Input_Texinfo__Token t) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)t;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 14534))+5);
      i1 = 0<=i1;
      if (i1) goto l3;
      i1=0u;
      goto l5;
l3:
      i1 = *(OOC_INT8*)((_check_pointer(i0, 14544))+5);
      i1 = i1<=27;
      
l5:
      if (i1) goto l11;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 14595))+5);
      i1 = 38<i1;
      if (i1) goto l9;
      i0=0u;
      goto l12;
l9:
      i0 = *(OOC_INT8*)((_check_pointer(i0, 14605))+5);
      i0 = i0<=45;
      
      goto l12;
l11:
      i0=1u;
l12:
      return i0;
      ;
    }

    
    OOC_CHAR8 OOC_Doc_Input_Texinfo__Parse_IsBlockToken(OOC_Doc_Input_Texinfo__Token t) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)t;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 14740))+5);
      i1 = 28<=i1;
      if (i1) goto l3;
      i0=0u;
      goto l4;
l3:
      i0 = *(OOC_INT8*)((_check_pointer(i0, 14750))+5);
      i0 = i0<35;
      
l4:
      return i0;
      ;
    }

    
    void OOC_Doc_Input_Texinfo__Parse_Err(OOC_INT32 code) {
      register OOC_INT32 i0,i1;

      i0 = code;
      i1 = (OOC_INT32)OOC_Doc_Input_Texinfo__texinfoContext;
      i0 = (OOC_INT32)OOC_Error__New((OOC_Error__Context)i1, i0);
      lastError = (Msg__Msg)i0;
      i1 = (OOC_INT32)token;
      i1 = *(OOC_INT32*)((_check_pointer(i1, 14932))+8);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14904)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i0, (OOC_CHAR8*)"pos", 4, i1);
      i0 = (OOC_INT32)token;
      i1 = (OOC_INT32)lastError;
      i0 = *(OOC_INT32*)((_check_pointer(i0, 14984))+12);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14955)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i1, (OOC_CHAR8*)"line", 5, i0);
      i0 = (OOC_INT32)token;
      i1 = (OOC_INT32)lastError;
      i0 = *(OOC_INT32*)((_check_pointer(i0, 15039))+16);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15008)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i1, (OOC_CHAR8*)"column", 7, i0);
      i0 = (OOC_INT32)errList;
      i1 = (OOC_INT32)lastError;
      OOC_Error__ListDesc_Append((OOC_Error__List)i0, (Msg__Msg)i1);
      return;
      ;
    }

    
    void OOC_Doc_Input_Texinfo__Parse_NextToken(void) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)token;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 15148))+5);
      i1 = i1!=46;
      if (!i1) goto l4;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 15196));
      token = (OOC_Doc_Input_Texinfo__Token)i0;
l4:
      return;
      ;
    }

    
    void OOC_Doc_Input_Texinfo__Parse_CheckToken(OOC_INT8 id) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)token;
      i0 = *(OOC_INT8*)((_check_pointer(i0, 15298))+5);
      i1 = id;
      i0 = i1!=i0;
      if (!i0) goto l9;
l3:
      switch (i1) {
      case 43:
        OOC_Doc_Input_Texinfo__Parse_Err(2);
        goto l9;
      case 44:
        OOC_Doc_Input_Texinfo__Parse_Err(3);
        goto l9;
      case 46:
        OOC_Doc_Input_Texinfo__Parse_Err(4);
        goto l9;
      default:
        _failed_case(i1, 15317);
        goto l9;
      }
l9:
      OOC_Doc_Input_Texinfo__Parse_NextToken();
      return;
      ;
    }

    
    void OOC_Doc_Input_Texinfo__Parse_SkipWhitespace(void) {
      register OOC_INT32 i0,i1,i2;
      auto OOC_CHAR8 OOC_Doc_Input_Texinfo__Parse_SkipWhitespace_OnlyWS(OOC_CHAR8 str[], OOC_LEN str_0d);
        
        OOC_CHAR8 OOC_Doc_Input_Texinfo__Parse_SkipWhitespace_OnlyWS(OOC_CHAR8 str[], OOC_LEN str_0d) {
          register OOC_INT32 i0,i1;

          i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT32, 15727)));
          i0 = i0!=0u;
          if (i0) goto l3;
          i0=0u;
          goto l5;
l3:
          i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT32, 15743)));
          i0 = (OOC_UINT8)i0<=(OOC_UINT8)32u;
          
l5:
          if (i0) goto l7;
          i0=0;
          goto l17;
l7:
          i0=0;
l8_loop:
          i0 = i0+1;
          i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 15727)));
          i1 = i1!=0u;
          if (i1) goto l11;
          i1=0u;
          goto l13;
l11:
          i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 15743)));
          i1 = (OOC_UINT8)i1<=(OOC_UINT8)32u;
          
l13:
          if (i1) goto l8_loop;
l17:
          i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 15808)));
          return (i0==0u);
          ;
        }


      i0 = (OOC_INT32)token;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 15869))+5);
      i1 = i1==42;
      if (i1) goto l3;
      i1=0u;
      goto l5;
l3:
      i1 = *(OOC_UINT8*)((_check_pointer(i0, 15893))+4);
      i1 = !i1;
      
l5:
      if (i1) goto l7;
      i1=0u;
      goto l9;
l7:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15914))+20);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15914))+20);
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 15919)), 0);
      i1 = OOC_Doc_Input_Texinfo__Parse_SkipWhitespace_OnlyWS((void*)(_check_pointer(i2, 15919)), i1);
      
l9:
      if (!i1) goto l24;
l11_loop:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 15947));
      token = (OOC_Doc_Input_Texinfo__Token)i0;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 15869))+5);
      i1 = i1==42;
      if (i1) goto l14;
      i1=0u;
      goto l16;
l14:
      i1 = *(OOC_UINT8*)((_check_pointer(i0, 15893))+4);
      i1 = !i1;
      
l16:
      if (i1) goto l18;
      i1=0u;
      goto l20;
l18:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15914))+20);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15914))+20);
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 15919)), 0);
      i1 = OOC_Doc_Input_Texinfo__Parse_SkipWhitespace_OnlyWS((void*)(_check_pointer(i2, 15919)), i1);
      
l20:
      if (i1) goto l11_loop;
l24:
      return;
      ;
    }

    
    OOC_CHAR8 OOC_Doc_Input_Texinfo__Parse_IdToChar(OOC_INT8 id) {
      register OOC_INT32 i0;

      i0 = (OOC_INT32)token;
      i0 = *(OOC_INT8*)((_check_pointer(i0, 16053))+5);
      switch (i0) {
      case 0:
        return 64u;
        goto l6;
      case 1:
        return 123u;
        goto l6;
      case 2:
        return 125u;
        goto l6;
      default:
        _failed_case(i0, 16043);
        goto l6;
      }
l6:
      _failed_function(16003); return 0;
      ;
    }

    
    OOC_INT32 OOC_Doc_Input_Texinfo__Parse_IdToGlyph(OOC_INT8 id) {
      register OOC_INT32 i0;

      i0 = (OOC_INT32)token;
      i0 = *(OOC_INT8*)((_check_pointer(i0, 16259))+5);
      switch (i0) {
      case 3:
        return 0;
        goto l7;
      case 4:
        return 1;
        goto l7;
      case 5:
        return 2;
        goto l7;
      case 6:
        return 4;
        goto l7;
      default:
        _failed_case(i0, 16249);
        goto l7;
      }
l7:
      _failed_function(16204); return 0;
      ;
    }

    
    OOC_INT32 OOC_Doc_Input_Texinfo__Parse_IdToMark(OOC_INT8 id) {
      register OOC_INT32 i0;

      i0 = id;
      switch (i0) {
      case 7:
        return 0;
        goto l22;
      case 8:
        return 1;
        goto l22;
      case 9:
        return 2;
        goto l22;
      case 10:
        return 3;
        goto l22;
      case 11:
        return 4;
        goto l22;
      case 12:
        return 5;
        goto l22;
      case 13:
        return 6;
        goto l22;
      case 14:
        return 7;
        goto l22;
      case 19:
        return 12;
        goto l22;
      case 20:
        return 13;
        goto l22;
      case 21:
        return 14;
        goto l22;
      case 22:
        return 15;
        goto l22;
      case 23:
        return 16;
        goto l22;
      case 24:
        return 17;
        goto l22;
      case 25:
        return 18;
        goto l22;
      case 15:
        return 8;
        goto l22;
      case 16:
        return 9;
        goto l22;
      case 17:
        return 11;
        goto l22;
      case 18:
        return 10;
        goto l22;
      default:
        _failed_case(i0, 16518);
        goto l22;
      }
l22:
      _failed_function(16474); return 0;
      ;
    }

    
    OOC_CHAR8 OOC_Doc_Input_Texinfo__Parse_IsOberonRef(OOC_INT32 mark) {
      register OOC_INT32 i0,i1;

      i0 = mark;
      i1 = 12<=i0;
      if (i1) goto l3;
      i0=0u;
      goto l4;
l3:
      i0 = i0<=18;
      
l4:
      return i0;
      ;
    }

    
    OOC_Doc__BlockElement OOC_Doc_Input_Texinfo__Parse_ParseBlockList(void) {
      register OOC_INT32 i0,i1,i2;
      OOC_CHAR8 noIndent;
      OOC_Doc__BlockList list;
      OOC_Doc__InlineElement inlineText;
      auto OOC_Doc__InlineElement OOC_Doc_Input_Texinfo__Parse_ParseBlockList_ParseInlineList(OOC_CHAR8 isArg, OOC_CHAR8 ignoreParagraph, OOC_CHAR8 exitAfterEOL);
      auto OOC_CHAR8 OOC_Doc_Input_Texinfo__Parse_ParseBlockList_AtEmptyLine(void);
      auto void OOC_Doc_Input_Texinfo__Parse_ParseBlockList_CheckEnd(OOC_INT8 id);
      auto OOC_Doc__Itemize OOC_Doc_Input_Texinfo__Parse_ParseBlockList_Itemize(void);
      auto OOC_Doc__Enumerate OOC_Doc_Input_Texinfo__Parse_ParseBlockList_Enumerate(void);
      auto OOC_Doc__Example OOC_Doc_Input_Texinfo__Parse_ParseBlockList_Example(void);
      auto OOC_Doc__BlockElement OOC_Doc_Input_Texinfo__Parse_ParseBlockList_PCond(void);
      auto OOC_Doc__Table OOC_Doc_Input_Texinfo__Parse_ParseBlockList_Table(void);
        
        OOC_Doc__InlineElement OOC_Doc_Input_Texinfo__Parse_ParseBlockList_ParseInlineList(OOC_CHAR8 isArg, OOC_CHAR8 ignoreParagraph, OOC_CHAR8 exitAfterEOL) {
          register OOC_INT32 i0,i1,i2,i3,i4;
          OOC_Doc__InlineList list;
          OOC_CHAR8 str2[2];
          OOC_INT32 mark;
          OOC_Doc_Input_Texinfo__Token posToken;
          OOC_Doc__InlineElement inlineText;
          auto void OOC_Doc_Input_Texinfo__Parse_ParseBlockList_ParseInlineList_AddText(const OOC_CHAR8 str__ref[], OOC_LEN str_0d);
          auto void OOC_Doc_Input_Texinfo__Parse_ParseBlockList_ParseInlineList_FlushBuffer(void);
          auto void OOC_Doc_Input_Texinfo__Parse_ParseBlockList_ParseInlineList_AddInline(OOC_Doc__InlineElement i);
          auto OOC_CHAR8 OOC_Doc_Input_Texinfo__Parse_ParseBlockList_ParseInlineList_EndOfArguments(void);
          auto void OOC_Doc_Input_Texinfo__Parse_ParseBlockList_ParseInlineList_CheckNumOfArgs(OOC_INT8 id, OOC_INT32 num);
          auto OOC_Doc__Email OOC_Doc_Input_Texinfo__Parse_ParseBlockList_ParseInlineList_Email(void);
          auto OOC_Doc__Uref OOC_Doc_Input_Texinfo__Parse_ParseBlockList_ParseInlineList_Uref(void);
            
            void OOC_Doc_Input_Texinfo__Parse_ParseBlockList_ParseInlineList_AddText(const OOC_CHAR8 str__ref[], OOC_LEN str_0d) {
              register OOC_INT32 i0,i1,i2;
              OOC_ALLOCATE_VPAR(str,OOC_CHAR8 ,str_0d)

              OOC_INITIALIZE_VPAR(str__ref,str,OOC_CHAR8 ,str_0d)
              i0 = (OOC_INT32)buffer;
              i0 = *(OOC_INT32*)((_check_pointer(i0, 18102))+4);
              i0 = i0==0;
              if (!i0) goto l3;
              i0 = (OOC_INT32)token;
              i1 = *(OOC_INT32*)((_check_pointer(i0, 18297))+8);
              i2 = *(OOC_INT32*)((_check_pointer(i0, 18309))+12);
              i0 = *(OOC_INT32*)((_check_pointer(i0, 18322))+16);
              OOC_Doc__SetPosition((void*)(OOC_INT32)&bufferPos, (RT0__Struct)((OOC_INT32)&_td_OOC_Doc__Position), i1, i2, i0);
l3:
              i0 = (OOC_INT32)buffer;
              OOC_Doc_TextBuffer__BufferDesc_Append((OOC_Doc_TextBuffer__Buffer)i0, (void*)(OOC_INT32)str, str_0d);
              i0 = (OOC_INT32)token;
              i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 18408));
              i0 = *(OOC_UINT8*)((_check_pointer(i0, 18414))+4);
              if (i0) goto l6;
              i0=0u;
              goto l8;
l6:
              i0 = (OOC_INT32)buffer;
              i0 = *(OOC_INT32*)((_check_pointer(i0, 18429))+4);
              i0 = i0!=0;
              
l8:
              if (!i0) goto l10;
              i0 = (OOC_INT32)buffer;
              OOC_Doc_TextBuffer__BufferDesc_AppendEOL((OOC_Doc_TextBuffer__Buffer)i0);
l10:
              return;
              ;
            }

            
            void OOC_Doc_Input_Texinfo__Parse_ParseBlockList_ParseInlineList_FlushBuffer(void) {
              register OOC_INT32 i0,i1;

              i0 = (OOC_INT32)buffer;
              i1 = *(OOC_INT32*)((_check_pointer(i0, 18580))+4);
              i1 = i1!=0;
              if (!i1) goto l4;
              i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 18641));
              i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 18641));
              i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 18646)), 0);
              i0 = (OOC_INT32)OOC_Doc__NewText((void*)(_check_pointer(i0, 18646)), i1, (void*)(OOC_INT32)&bufferPos, (RT0__Struct)((OOC_INT32)&_td_OOC_Doc__Position));
              i1 = (OOC_INT32)list;
              OOC_Doc__InlineListDesc_Append((OOC_Doc__InlineList)i1, (OOC_Doc__InlineElement)i0);
              i0 = (OOC_INT32)buffer;
              OOC_Doc_TextBuffer__BufferDesc_Clear((OOC_Doc_TextBuffer__Buffer)i0);
l4:
              return;
              ;
            }

            
            void OOC_Doc_Input_Texinfo__Parse_ParseBlockList_ParseInlineList_AddInline(OOC_Doc__InlineElement i) {
              register OOC_INT32 i0,i1;

              OOC_Doc_Input_Texinfo__Parse_ParseBlockList_ParseInlineList_FlushBuffer();
              i0 = (OOC_INT32)list;
              i1 = (OOC_INT32)i;
              OOC_Doc__InlineListDesc_Append((OOC_Doc__InlineList)i0, (OOC_Doc__InlineElement)i1);
              i0 = (OOC_INT32)token;
              i0 = *(OOC_UINT8*)((_check_pointer(i0, 18960))+4);
              if (!i0) goto l4;
              i0 = (OOC_INT32)buffer;
              OOC_Doc_TextBuffer__BufferDesc_AppendEOL((OOC_Doc_TextBuffer__Buffer)i0);
l4:
              return;
              ;
            }

            
            OOC_CHAR8 OOC_Doc_Input_Texinfo__Parse_ParseBlockList_ParseInlineList_EndOfArguments(void) {
              register OOC_INT32 i0,i1;

              i0 = (OOC_INT32)token;
              i1 = *(OOC_INT8*)((_check_pointer(i0, 19126))+5);
              i1 = i1==44;
              if (i1) goto l3;
              i1 = *(OOC_INT8*)((_check_pointer(i0, 19176))+5);
              i1 = i1==46;
              
              goto l5;
l3:
              i1=1u;
l5:
              if (i1) goto l11;
              i1 = *(OOC_INT8*)((_check_pointer(i0, 19236))+5);
              i1 = 28<=i1;
              if (i1) goto l9;
              i0=0u;
              goto l12;
l9:
              i0 = *(OOC_INT8*)((_check_pointer(i0, 19250))+5);
              i0 = i0<=37;
              
              goto l12;
l11:
              i0=1u;
l12:
              return i0;
              ;
            }

            
            void OOC_Doc_Input_Texinfo__Parse_ParseBlockList_ParseInlineList_CheckNumOfArgs(OOC_INT8 id, OOC_INT32 num) {
              register OOC_INT32 i0,i1,i2;

              i0 = id;
              i1 = (OOC_INT32)*(OOC_INT32*)((OOC_INT32)OOC_Doc_Input_Texinfo__cmdList+(_check_index(i0, 38, OOC_UINT8, 19395))*4);
              i1 = *(OOC_INT8*)((_check_pointer(i1, 19399))+18);
              i2 = num;
              i1 = i1>i2;
              if (!i1) goto l4;
              OOC_Doc_Input_Texinfo__Parse_Err(11);
              i1 = (OOC_INT32)*(OOC_INT32*)((OOC_INT32)OOC_Doc_Input_Texinfo__cmdList+(_check_index(i0, 38, OOC_UINT8, 19570))*4);
              i1 = (OOC_INT32)Msg__GetStringPtr((void*)((_check_pointer(i1, 19574))+2), 16);
              i2 = (OOC_INT32)lastError;
              OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 19478)))), Msg__MsgDesc_SetStringAttrib)),Msg__MsgDesc_SetStringAttrib)((Msg__Msg)i2, (OOC_CHAR8*)"name", 5, (Msg__StringPtr)i1);
              i0 = (OOC_INT32)*(OOC_INT32*)((OOC_INT32)OOC_Doc_Input_Texinfo__cmdList+(_check_index(i0, 38, OOC_UINT8, 19639))*4);
              i1 = (OOC_INT32)lastError;
              i0 = *(OOC_INT8*)((_check_pointer(i0, 19643))+18);
              OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 19605)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i1, (OOC_CHAR8*)"minimum", 8, i0);
l4:
              return;
              ;
            }

            
            OOC_Doc__Email OOC_Doc_Input_Texinfo__Parse_ParseBlockList_ParseInlineList_Email(void) {
              register OOC_INT32 i0,i1,i2;
              OOC_Doc__InlineElement displayed;

              OOC_Doc_Input_Texinfo__Parse_NextToken();
              OOC_Doc_Input_Texinfo__Parse_CheckToken(43);
              displayed = (OOC_Doc__InlineElement)(OOC_INT32)0;
              i0 = OOC_Doc_Input_Texinfo__Parse_ParseBlockList_ParseInlineList_EndOfArguments();
              i0 = !i0;
              if (i0) goto l3;
              i0=0;i1=(OOC_INT32)0;
              goto l17;
l3:
              i0=0;i1=(OOC_INT32)0;
l4_loop:
              i2 = i0!=0;
              if (!i2) goto l7;
              OOC_Doc_Input_Texinfo__Parse_CheckToken(45);
l7:
              i2 = (OOC_INT32)OOC_Doc_Input_Texinfo__Parse_ParseBlockList_ParseInlineList(1u, 0u, 0u);
              switch (i0) {
              case 0:
                i1=i2;
                goto l12;
              case 1:
                displayed = (OOC_Doc__InlineElement)i2;
                
                goto l12;
              default:
                OOC_Doc__MergeInline((void*)(OOC_INT32)&displayed, (OOC_Doc__InlineElement)i2);
                
                goto l12;
              }
l12:
              i2 = OOC_Doc_Input_Texinfo__Parse_ParseBlockList_ParseInlineList_EndOfArguments();
              i0 = i0+1;
              i2 = !i2;
              if (i2) goto l4_loop;
l17:
              OOC_Doc_Input_Texinfo__Parse_ParseBlockList_ParseInlineList_CheckNumOfArgs(26, i0);
              OOC_Doc_Input_Texinfo__Parse_CheckToken(44);
              i0 = (OOC_INT32)displayed;
              i0 = (OOC_INT32)OOC_Doc__NewEmail((OOC_Doc__InlineElement)i1, (OOC_Doc__InlineElement)i0);
              return (OOC_Doc__Email)i0;
              ;
            }

            
            OOC_Doc__Uref OOC_Doc_Input_Texinfo__Parse_ParseBlockList_ParseInlineList_Uref(void) {
              register OOC_INT32 i0,i1,i2,i3;
              OOC_Doc__InlineElement replacement;

              OOC_Doc_Input_Texinfo__Parse_NextToken();
              OOC_Doc_Input_Texinfo__Parse_CheckToken(43);
              replacement = (OOC_Doc__InlineElement)(OOC_INT32)0;
              i0 = OOC_Doc_Input_Texinfo__Parse_ParseBlockList_ParseInlineList_EndOfArguments();
              i0 = !i0;
              if (i0) goto l3;
              i0=0;i1=(OOC_INT32)0;i2=(OOC_INT32)0;
              goto l18;
l3:
              i0=0;i1=(OOC_INT32)0;i2=(OOC_INT32)0;
l4_loop:
              i3 = i0!=0;
              if (!i3) goto l7;
              OOC_Doc_Input_Texinfo__Parse_CheckToken(45);
l7:
              i3 = (OOC_INT32)OOC_Doc_Input_Texinfo__Parse_ParseBlockList_ParseInlineList(1u, 0u, 0u);
              switch (i0) {
              case 0:
                i2=i3;
                goto l13;
              case 1:
                i1=i3;
                goto l13;
              case 2:
                replacement = (OOC_Doc__InlineElement)i3;
                
                goto l13;
              default:
                OOC_Doc__MergeInline((void*)(OOC_INT32)&replacement, (OOC_Doc__InlineElement)i3);
                
                goto l13;
              }
l13:
              i3 = OOC_Doc_Input_Texinfo__Parse_ParseBlockList_ParseInlineList_EndOfArguments();
              i0 = i0+1;
              i3 = !i3;
              if (i3) goto l4_loop;
l18:
              OOC_Doc_Input_Texinfo__Parse_ParseBlockList_ParseInlineList_CheckNumOfArgs(27, i0);
              OOC_Doc_Input_Texinfo__Parse_CheckToken(44);
              i0 = (OOC_INT32)replacement;
              i0 = (OOC_INT32)OOC_Doc__NewUref((OOC_Doc__InlineElement)i2, (OOC_Doc__InlineElement)i1, (OOC_Doc__InlineElement)i0);
              return (OOC_Doc__Uref)i0;
              ;
            }


          i0 = (OOC_INT32)OOC_Doc__NewInlineList();
          list = (OOC_Doc__InlineList)i0;
          i0 = (OOC_INT32)&_td_OOC_Doc__Position;
l1_loop:
          i1 = (OOC_INT32)token;
          i2 = *(OOC_INT8*)((_check_pointer(i1, 21514))+5);
          switch (i2) {
          case 0 ... 2:
            _copy_8((const void*)(OOC_CHAR8*)"x",(void*)(OOC_INT32)str2,2);
            i1 = *(OOC_INT8*)((_check_pointer(i1, 21620))+5);
            i1 = OOC_Doc_Input_Texinfo__Parse_IdToChar(i1);
            *(OOC_UINT8*)((OOC_INT32)str2+(_check_index(0, 2, OOC_UINT8, 21598))) = i1;
            OOC_Doc_Input_Texinfo__Parse_ParseBlockList_ParseInlineList_AddText((void*)(OOC_INT32)str2, 2);
            OOC_Doc_Input_Texinfo__Parse_NextToken();
            goto l35;
          case 3 ... 6:
            i1 = *(OOC_INT8*)((_check_pointer(i1, 21766))+5);
            i1 = OOC_Doc_Input_Texinfo__Parse_IdToGlyph(i1);
            i1 = (OOC_INT32)OOC_Doc__NewGlyph(i1);
            OOC_Doc_Input_Texinfo__Parse_ParseBlockList_ParseInlineList_AddInline((OOC_Doc__InlineElement)i1);
            OOC_Doc_Input_Texinfo__Parse_NextToken();
            OOC_Doc_Input_Texinfo__Parse_CheckToken(43);
            OOC_Doc_Input_Texinfo__Parse_CheckToken(44);
            goto l35;
          case 7 ... 25:
            OOC_Doc_Input_Texinfo__Parse_ParseBlockList_ParseInlineList_FlushBuffer();
            i1 = (OOC_INT32)token;
            i2 = *(OOC_INT8*)((_check_pointer(i1, 21979))+5);
            i2 = OOC_Doc_Input_Texinfo__Parse_IdToMark(i2);
            mark = i2;
            posToken = (OOC_Doc_Input_Texinfo__Token)i1;
            OOC_Doc_Input_Texinfo__Parse_NextToken();
            OOC_Doc_Input_Texinfo__Parse_CheckToken(43);
            i1 = (OOC_INT32)OOC_Doc_Input_Texinfo__Parse_ParseBlockList_ParseInlineList(0u, 0u, 0u);
            inlineText = (OOC_Doc__InlineElement)i1;
            OOC_Doc_Input_Texinfo__Parse_CheckToken(44);
            i3 = 12<=i2;
            if (i3) goto l8;
            i3=0u;
            goto l10;
l8:
            i3 = i2<=18;
            
l10:
            if (i3) goto l12;
            i1 = (OOC_INT32)OOC_Doc__NewMarkedInline(i2, (OOC_Doc__InlineElement)i1);
            OOC_Doc_Input_Texinfo__Parse_ParseBlockList_ParseInlineList_AddInline((OOC_Doc__InlineElement)i1);
            goto l35;
l12:
            i1 = (OOC_INT32)OOC_Doc__NewOberonRef(i2, (OOC_Doc__InlineElement)i1, (ADT_Storable__Object)(OOC_INT32)0);
            OOC_Doc_Input_Texinfo__Parse_ParseBlockList_ParseInlineList_AddInline((OOC_Doc__InlineElement)i1);
            i1 = (OOC_INT32)posToken;
            i2 = (OOC_INT32)list;
            i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 22387))+4);
            i3 = _check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 22398)))), &_td_OOC_Doc__OberonRefDesc, 22398)), 22408);
            i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 22387))+4);
            i3 = *(OOC_INT32*)((_check_pointer(i1, 22485))+16);
            i4 = *(OOC_INT32*)((_check_pointer(i1, 22469))+12);
            i1 = *(OOC_INT32*)((_check_pointer(i1, 22454))+8);
            OOC_Doc__SetPosition((void*)(_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 22398)))), &_td_OOC_Doc__OberonRefDesc, 22398)), 22408)), (RT0__Struct)i0, i1, i4, i3);
            goto l35;
          case 26:
            OOC_Doc_Input_Texinfo__Parse_ParseBlockList_ParseInlineList_FlushBuffer();
            i1 = (OOC_INT32)OOC_Doc_Input_Texinfo__Parse_ParseBlockList_ParseInlineList_Email();
            OOC_Doc_Input_Texinfo__Parse_ParseBlockList_ParseInlineList_AddInline((OOC_Doc__InlineElement)i1);
            goto l35;
          case 27:
            OOC_Doc_Input_Texinfo__Parse_ParseBlockList_ParseInlineList_FlushBuffer();
            i1 = (OOC_INT32)OOC_Doc_Input_Texinfo__Parse_ParseBlockList_ParseInlineList_Uref();
            OOC_Doc_Input_Texinfo__Parse_ParseBlockList_ParseInlineList_AddInline((OOC_Doc__InlineElement)i1);
            goto l35;
          case 39:
            i1 = (OOC_INT32)OOC_Doc__NewGlyph(3);
            OOC_Doc_Input_Texinfo__Parse_ParseBlockList_ParseInlineList_AddInline((OOC_Doc__InlineElement)i1);
            OOC_Doc_Input_Texinfo__Parse_NextToken();
            goto l35;
          case 40:
            i1 = (OOC_INT32)OOC_Doc__NewGlyph(5);
            OOC_Doc_Input_Texinfo__Parse_ParseBlockList_ParseInlineList_AddInline((OOC_Doc__InlineElement)i1);
            OOC_Doc_Input_Texinfo__Parse_NextToken();
            goto l35;
          case 41:
            i1 = (OOC_INT32)OOC_Doc__NewGlyph(6);
            OOC_Doc_Input_Texinfo__Parse_ParseBlockList_ParseInlineList_AddInline((OOC_Doc__InlineElement)i1);
            OOC_Doc_Input_Texinfo__Parse_NextToken();
            goto l35;
          case 42:
            i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23146))+20);
            i2 = (
            _cmp8((const void*)(_check_pointer(i2, 23151)),(const void*)(OOC_CHAR8*)""))==0;
            if (i2) goto l22;
            i2=0u;
            goto l24;
l22:
            i2 = ignoreParagraph;
            i2 = !i2;
            
l24:
            if (i2) goto l43;
            i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23247))+20);
            i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23247))+20);
            i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 23252)), 0);
            OOC_Doc_Input_Texinfo__Parse_ParseBlockList_ParseInlineList_AddText((void*)(_check_pointer(i1, 23252)), i2);
            OOC_Doc_Input_Texinfo__Parse_NextToken();
            goto l35;
          case 43:
            OOC_Doc_Input_Texinfo__Parse_Err(9);
            OOC_Doc_Input_Texinfo__Parse_NextToken();
            goto l35;
          case 45:
            i1 = isArg;
            if (i1) goto l43;
            OOC_Doc_Input_Texinfo__Parse_ParseBlockList_ParseInlineList_AddText((OOC_CHAR8*)",", 2);
            OOC_Doc_Input_Texinfo__Parse_NextToken();
            goto l35;
          default:
            goto l43;
          }
l35:
          i1 = exitAfterEOL;
          if (i1) goto l38;
          i1=0u;
          goto l40;
l38:
          i1 = (OOC_INT32)token;
          i1 = *(OOC_UINT8*)((_check_pointer(i1, 23646))+4);
          
l40:
          if (!i1) goto l1_loop;
l43:
          OOC_Doc_Input_Texinfo__Parse_ParseBlockList_ParseInlineList_FlushBuffer();
          i0 = (OOC_INT32)list;
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 23741));
          return (OOC_Doc__InlineElement)i0;
          ;
        }

        
        OOC_CHAR8 OOC_Doc_Input_Texinfo__Parse_ParseBlockList_AtEmptyLine(void) {
          register OOC_INT32 i0,i1;

          i0 = (OOC_INT32)token;
          i1 = *(OOC_INT8*)((_check_pointer(i0, 23851))+5);
          i1 = i1==42;
          if (i1) goto l3;
          i1=0u;
          goto l5;
l3:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23875))+20);
          i1 = (
          _cmp8((const void*)(_check_pointer(i1, 23880)),(const void*)(OOC_CHAR8*)""))==0;
          
l5:
          if (i1) goto l7;
          i0 = *(OOC_INT8*)((_check_pointer(i0, 23912))+5);
          i0 = i0==46;
          
          goto l8;
l7:
          i0=1u;
l8:
          return i0;
          ;
        }

        
        void OOC_Doc_Input_Texinfo__Parse_ParseBlockList_CheckEnd(OOC_INT8 id) {
          register OOC_INT32 i0,i1,i2;
          auto OOC_CHAR8 OOC_Doc_Input_Texinfo__Parse_ParseBlockList_CheckEnd_Substr(OOC_CHAR8 string[], OOC_LEN string_0d, OOC_CHAR8 pattern[], OOC_LEN pattern_0d);
            
            OOC_CHAR8 OOC_Doc_Input_Texinfo__Parse_ParseBlockList_CheckEnd_Substr(OOC_CHAR8 string[], OOC_LEN string_0d, OOC_CHAR8 pattern[], OOC_LEN pattern_0d) {
              register OOC_INT32 i0,i1,i2;
              OOC_INT16 pos;
              OOC_CHAR8 found;

              Strings__FindNext((void*)(OOC_INT32)pattern, pattern_0d, (void*)(OOC_INT32)string, string_0d, 0, (void*)(OOC_INT32)&found, (void*)(OOC_INT32)&pos);
              i0 = found;
              if (i0) goto l3;
              return 0u;
              goto l26;
l3:
              i0 = pos;
              i1 = 0<i0;
              if (!i1) goto l14;
              i1=0;
l6_loop:
              i2 = *(OOC_UINT8*)((OOC_INT32)string+(_check_index(i1, string_0d, OOC_UINT16, 24287)));
              i2 = (OOC_UINT8)i2>(OOC_UINT8)32u;
              if (!i2) goto l9;
              return 0u;
l9:
              i1 = i1+1;
              i2 = i1<i0;
              if (i2) goto l6_loop;
l14:
              i1 = Strings__Length((void*)(OOC_INT32)pattern, pattern_0d);
              i0 = i0+i1;
              i1 = *(OOC_UINT8*)((OOC_INT32)string+(_check_index(i0, string_0d, OOC_UINT16, 24441)));
              i1 = i1!=0u;
              if (!i1) goto l25;
l17_loop:
              i1 = *(OOC_UINT8*)((OOC_INT32)string+(_check_index(i0, string_0d, OOC_UINT16, 24478)));
              i1 = (OOC_UINT8)i1>(OOC_UINT8)32u;
              if (!i1) goto l20;
              return 0u;
l20:
              i0 = i0+1;
              i1 = *(OOC_UINT8*)((OOC_INT32)string+(_check_index(i0, string_0d, OOC_UINT16, 24441)));
              i1 = i1!=0u;
              if (i1) goto l17_loop;
l25:
              return 1u;
l26:
              _failed_function(24010); return 0;
              ;
            }


          i0 = (OOC_INT32)token;
          i1 = *(OOC_INT8*)((_check_pointer(i0, 24715))+5);
          i1 = i1!=35;
          if (i1) goto l7;
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 24750));
          i1 = i1!=0;
          if (i1) goto l5;
          i0=0u;
          goto l9;
l5:
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 24771));
          i0 = *(OOC_UINT8*)((_check_pointer(i0, 24777))+4);
          
          goto l9;
l7:
          i0=1u;
l9:
          if (!i0) goto l11;
          OOC_Doc_Input_Texinfo__Parse_Err(8);
          i0 = id;
          i0 = (OOC_INT32)*(OOC_INT32*)((OOC_INT32)OOC_Doc_Input_Texinfo__cmdList+(_check_index(i0, 38, OOC_UINT8, 24926))*4);
          i0 = (OOC_INT32)Msg__GetStringPtr((void*)((_check_pointer(i0, 24930))+2), 16);
          i1 = (OOC_INT32)lastError;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 24836)))), Msg__MsgDesc_SetStringAttrib)),Msg__MsgDesc_SetStringAttrib)((Msg__Msg)i1, (OOC_CHAR8*)"name", 5, (Msg__StringPtr)i0);
l11:
          OOC_Doc_Input_Texinfo__Parse_NextToken();
          i0 = (OOC_INT32)token;
          i1 = *(OOC_UINT8*)((_check_pointer(i0, 24989))+4);
          i1 = !i1;
          if (!i1) goto l21;
          i1 = *(OOC_INT8*)((_check_pointer(i0, 25019))+5);
          i1 = i1!=42;
          if (i1) goto l16;
          i1 = id;
          i1 = (OOC_INT32)*(OOC_INT32*)((OOC_INT32)OOC_Doc_Input_Texinfo__cmdList+(_check_index(i1, 38, OOC_UINT8, 25080))*4);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25065))+20);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25065))+20);
          i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 25070)), 0);
          i0 = OOC_Doc_Input_Texinfo__Parse_ParseBlockList_CheckEnd_Substr((void*)(_check_pointer(i0, 25070)), i2, (void*)((_check_pointer(i1, 25084))+2), 16);
          i0 = !i0;
          
          goto l18;
l16:
          i0=1u;
l18:
          if (!i0) goto l20;
          OOC_Doc_Input_Texinfo__Parse_Err(8);
          i0 = id;
          i0 = (OOC_INT32)*(OOC_INT32*)((OOC_INT32)OOC_Doc_Input_Texinfo__cmdList+(_check_index(i0, 38, OOC_UINT8, 25241))*4);
          i0 = (OOC_INT32)Msg__GetStringPtr((void*)((_check_pointer(i0, 25245))+2), 16);
          i1 = (OOC_INT32)lastError;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 25149)))), Msg__MsgDesc_SetStringAttrib)),Msg__MsgDesc_SetStringAttrib)((Msg__Msg)i1, (OOC_CHAR8*)"name", 5, (Msg__StringPtr)i0);
l20:
          OOC_Doc_Input_Texinfo__Parse_NextToken();
l21:
          return;
          ;
        }

        
        OOC_Doc__Itemize OOC_Doc_Input_Texinfo__Parse_ParseBlockList_Itemize(void) {
          register OOC_INT32 i0,i1,i2,i3,i4;
          OOC_Doc__InlineElement mark;
          struct OOC_Doc__Position pos;
          OOC_CHAR8 str2[2];
          OOC_Doc__BlockElement text;
          OOC_Doc__Item textItem;
          OOC_Doc__BlockList itemList;
          OOC_Doc__BlockElement itemText;

          OOC_Doc_Input_Texinfo__Parse_NextToken();
          OOC_Doc_Input_Texinfo__Parse_SkipWhitespace();
          i0 = (OOC_INT32)token;
          i1 = *(OOC_UINT8*)((_check_pointer(i0, 25702))+4);
          if (i1) goto l26;
          i1 = *(OOC_INT32*)((_check_pointer(i0, 25861))+8);
          i2 = *(OOC_INT32*)((_check_pointer(i0, 25873))+12);
          i0 = *(OOC_INT32*)((_check_pointer(i0, 25886))+16);
          i3 = (OOC_INT32)&_td_OOC_Doc__Position;
          OOC_Doc__SetPosition((void*)(OOC_INT32)&pos, (RT0__Struct)i3, i1, i2, i0);
          i0 = (OOC_INT32)token;
          i1 = *(OOC_INT8*)((_check_pointer(i0, 25916))+5);
          i1 = i1==42;
          if (i1) goto l21;
          i1 = *(OOC_INT8*)((_check_pointer(i0, 26023))+5);
          i1 = 0<=i1;
          if (i1) goto l7;
          i1=0u;
          goto l9;
l7:
          i1 = *(OOC_INT8*)((_check_pointer(i0, 26037))+5);
          i1 = i1<=2;
          
l9:
          if (i1) goto l19;
          i1 = *(OOC_INT8*)((_check_pointer(i0, 26218))+5);
          i1 = 3<=i1;
          if (i1) goto l13;
          i1=0u;
          goto l15;
l13:
          i1 = *(OOC_INT8*)((_check_pointer(i0, 26232))+5);
          i1 = i1<=6;
          
l15:
          if (i1) goto l17;
          OOC_Doc_Input_Texinfo__Parse_Err(6);
          i0 = (OOC_INT32)OOC_Doc__NewGlyph(0);
          mark = (OOC_Doc__InlineElement)i0;
          
          goto l22;
l17:
          i0 = *(OOC_INT8*)((_check_pointer(i0, 26307))+5);
          i0 = OOC_Doc_Input_Texinfo__Parse_IdToGlyph(i0);
          i0 = (OOC_INT32)OOC_Doc__NewGlyph(i0);
          mark = (OOC_Doc__InlineElement)i0;
          
          goto l22;
l19:
          _copy_8((const void*)(OOC_CHAR8*)"x",(void*)(OOC_INT32)str2,2);
          i1 = *(OOC_INT8*)((_check_pointer(i0, 26125))+5);
          i1 = OOC_Doc_Input_Texinfo__Parse_IdToChar(i1);
          *(OOC_UINT8*)((OOC_INT32)str2+(_check_index(0, 2, OOC_UINT8, 26103))) = i1;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26170))+20);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26170))+20);
          i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 26175)), 0);
          i0 = (OOC_INT32)OOC_Doc__NewText((void*)(_check_pointer(i0, 26175)), i1, (void*)(OOC_INT32)&pos, (RT0__Struct)i3);
          mark = (OOC_Doc__InlineElement)i0;
          
          goto l22;
l21:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25975))+20);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25975))+20);
          i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 25980)), 0);
          i0 = (OOC_INT32)OOC_Doc__NewText((void*)(_check_pointer(i0, 25980)), i1, (void*)(OOC_INT32)&pos, (RT0__Struct)i3);
          mark = (OOC_Doc__InlineElement)i0;
          
l22:
          OOC_Doc_Input_Texinfo__Parse_NextToken();
          i1 = (OOC_INT32)token;
          i1 = *(OOC_UINT8*)((_check_pointer(i1, 26470))+4);
          i1 = !i1;
          if (!i1) goto l27;
          OOC_Doc_Input_Texinfo__Parse_Err(5);
          goto l27;
l26:
          i0 = (OOC_INT32)OOC_Doc__NewGlyph(0);
          mark = (OOC_Doc__InlineElement)i0;
          
l27:
          i1 = (OOC_INT32)OOC_Doc_Input_Texinfo__Parse_ParseBlockList();
          text = (OOC_Doc__BlockElement)i1;
          i2 = i1!=(OOC_INT32)0;
          if (i2) goto l30;
          textItem = (OOC_Doc__Item)(OOC_INT32)0;
          i1=(OOC_INT32)0;
          goto l31;
l30:
          i2 = OOC_Doc_Input_Texinfo__Parse_ParseBlockList_AtEmptyLine();
          i1 = (OOC_INT32)OOC_Doc__NewItem(i2, (OOC_Doc__BlockElement)i1);
          textItem = (OOC_Doc__Item)i1;
          
l31:
          i2 = (OOC_INT32)OOC_Doc__NewBlockList();
          itemList = (OOC_Doc__BlockList)i2;
          i3 = (OOC_INT32)token;
          i3 = *(OOC_INT8*)((_check_pointer(i3, 26791))+5);
          i3 = i3==36;
          if (!i3) goto l39;
l34_loop:
          OOC_Doc_Input_Texinfo__Parse_NextToken();
          i3 = (OOC_INT32)OOC_Doc_Input_Texinfo__Parse_ParseBlockList();
          itemText = (OOC_Doc__BlockElement)i3;
          i4 = OOC_Doc_Input_Texinfo__Parse_ParseBlockList_AtEmptyLine();
          i3 = (OOC_INT32)OOC_Doc__NewItem(i4, (OOC_Doc__BlockElement)i3);
          OOC_Doc__BlockListDesc_Append((OOC_Doc__BlockList)i2, (OOC_Doc__BlockElement)i3);
          i3 = (OOC_INT32)token;
          i3 = *(OOC_INT8*)((_check_pointer(i3, 26791))+5);
          i3 = i3==36;
          if (i3) goto l34_loop;
l39:
          OOC_Doc_Input_Texinfo__Parse_ParseBlockList_CheckEnd(29);
          i3 = OOC_Doc_Input_Texinfo__Parse_ParseBlockList_AtEmptyLine();
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 27052));
          i0 = (OOC_INT32)OOC_Doc__NewItemize(i3, (OOC_Doc__InlineElement)i0, (OOC_Doc__Item)i1, (OOC_Doc__BlockElement)i2);
          return (OOC_Doc__Itemize)i0;
          ;
        }

        
        OOC_Doc__Enumerate OOC_Doc_Input_Texinfo__Parse_ParseBlockList_Enumerate(void) {
          register OOC_INT32 i0,i1,i2,i3,i4;
          OOC_INT8 mode;
          OOC_INT32 start;
          struct OOC_Doc__Position pos;
          OOC_INT32 whitespace;
          OOC_INT8 res;
          OOC_Doc__BlockElement text;
          OOC_Doc__Item textItem;
          OOC_Doc__BlockList itemList;
          OOC_Doc__BlockElement itemText;

          OOC_Doc_Input_Texinfo__Parse_NextToken();
          OOC_Doc_Input_Texinfo__Parse_SkipWhitespace();
          i0 = (OOC_INT32)token;
          i1 = *(OOC_UINT8*)((_check_pointer(i0, 27526))+4);
          if (i1) goto l44;
          mode = (-1);
          i1 = *(OOC_INT32*)((_check_pointer(i0, 27690))+8);
          i2 = *(OOC_INT32*)((_check_pointer(i0, 27702))+12);
          i0 = *(OOC_INT32*)((_check_pointer(i0, 27715))+16);
          OOC_Doc__SetPosition((void*)(OOC_INT32)&pos, (RT0__Struct)((OOC_INT32)&_td_OOC_Doc__Position), i1, i2, i0);
          i0 = (OOC_INT32)token;
          i1 = *(OOC_INT8*)((_check_pointer(i0, 27745))+5);
          i1 = i1==42;
          if (i1) goto l5;
          i0=(-1);
          goto l36;
l5:
          whitespace = 0;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27819))+20);
          i1 = _check_pointer(i1, 27823);
          i2 = OOC_ARRAY_LENGTH(i1, 0);
          i1 = *(OOC_UINT8*)(i1+(_check_index(0, i2, OOC_UINT32, 27823)));
          i1 = i1!=0u;
          if (i1) goto l8;
          i1=0u;
          goto l10;
l8:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27868))+20);
          i1 = _check_pointer(i1, 27872);
          i2 = OOC_ARRAY_LENGTH(i1, 0);
          i1 = *(OOC_UINT8*)(i1+(_check_index(0, i2, OOC_UINT32, 27872)));
          i1 = (OOC_UINT8)i1<=(OOC_UINT8)32u;
          
l10:
          if (i1) goto l12;
          i1=0;
          goto l22;
l12:
          i1=0;
l13_loop:
          i1 = i1+1;
          whitespace = i1;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27819))+20);
          i2 = _check_pointer(i2, 27823);
          i3 = OOC_ARRAY_LENGTH(i2, 0);
          i2 = *(OOC_UINT8*)(i2+(_check_index(i1, i3, OOC_UINT32, 27823)));
          i2 = i2!=0u;
          if (i2) goto l16;
          i2=0u;
          goto l18;
l16:
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27868))+20);
          i2 = _check_pointer(i2, 27872);
          i3 = OOC_ARRAY_LENGTH(i2, 0);
          i2 = *(OOC_UINT8*)(i2+(_check_index(i1, i3, OOC_UINT32, 27872)));
          i2 = (OOC_UINT8)i2<=(OOC_UINT8)32u;
          
l18:
          if (i2) goto l13_loop;
l22:
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27977))+20);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27977))+20);
          i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 27981)), 0);
          IntStr__StrToInt((void*)(_check_pointer(i0, 27981)), i2, (void*)(OOC_INT32)&start, (void*)(OOC_INT32)&res);
          i0 = res;
          i0 = i0==0;
          if (i0) goto l34;
          i0 = (OOC_INT32)token;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28121))+20);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28121))+20);
          i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 28125)), 0);
          i2 = Strings__Length((void*)(_check_pointer(i3, 28125)), i2);
          i2 = (i2-i1)==1;
          if (i2) goto l27;
          i0=(-1);
          goto l36;
l27:
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28173))+20);
          i2 = _check_pointer(i2, 28177);
          i3 = OOC_ARRAY_LENGTH(i2, 0);
          i2 = *(OOC_UINT8*)(i2+(_check_index(i1, i3, OOC_UINT32, 28177)));
          switch (i2) {
          case 97u ... 122u:
            mode = 1;
            i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28298))+20);
            i0 = _check_pointer(i0, 28302);
            i2 = OOC_ARRAY_LENGTH(i0, 0);
            i0 = *(OOC_UINT8*)(i0+(_check_index(i1, i2, OOC_UINT32, 28302)));
            start = (i0-96);
            i0=1;
            goto l36;
          case 65u ... 90u:
            mode = 2;
            i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28435))+20);
            i0 = _check_pointer(i0, 28439);
            i2 = OOC_ARRAY_LENGTH(i0, 0);
            i0 = *(OOC_UINT8*)(i0+(_check_index(i1, i2, OOC_UINT32, 28439)));
            start = (i0-64);
            i0=2;
            goto l36;
          default:
            i0=(-1);
            goto l36;
          }
l34:
          mode = 0;
          i0=0;
l36:
          i1 = i0<0;
          if (!i1) goto l40;
          OOC_Doc_Input_Texinfo__Parse_Err(13);
          mode = 0;
          start = 1;
          i0=0;
l40:
          OOC_Doc_Input_Texinfo__Parse_NextToken();
          i1 = (OOC_INT32)token;
          i1 = *(OOC_UINT8*)((_check_pointer(i1, 28718))+4);
          i1 = !i1;
          if (!i1) goto l45;
          OOC_Doc_Input_Texinfo__Parse_Err(5);
          goto l45;
l44:
          mode = 0;
          start = 1;
          i0=0;
l45:
          i1 = (OOC_INT32)OOC_Doc_Input_Texinfo__Parse_ParseBlockList();
          text = (OOC_Doc__BlockElement)i1;
          i2 = i1!=(OOC_INT32)0;
          if (i2) goto l48;
          textItem = (OOC_Doc__Item)(OOC_INT32)0;
          i1=(OOC_INT32)0;
          goto l49;
l48:
          i2 = OOC_Doc_Input_Texinfo__Parse_ParseBlockList_AtEmptyLine();
          i1 = (OOC_INT32)OOC_Doc__NewItem(i2, (OOC_Doc__BlockElement)i1);
          textItem = (OOC_Doc__Item)i1;
          
l49:
          i2 = (OOC_INT32)OOC_Doc__NewBlockList();
          itemList = (OOC_Doc__BlockList)i2;
          i3 = (OOC_INT32)token;
          i3 = *(OOC_INT8*)((_check_pointer(i3, 29039))+5);
          i3 = i3==36;
          if (!i3) goto l57;
l52_loop:
          OOC_Doc_Input_Texinfo__Parse_NextToken();
          i3 = (OOC_INT32)OOC_Doc_Input_Texinfo__Parse_ParseBlockList();
          itemText = (OOC_Doc__BlockElement)i3;
          i4 = OOC_Doc_Input_Texinfo__Parse_ParseBlockList_AtEmptyLine();
          i3 = (OOC_INT32)OOC_Doc__NewItem(i4, (OOC_Doc__BlockElement)i3);
          OOC_Doc__BlockListDesc_Append((OOC_Doc__BlockList)i2, (OOC_Doc__BlockElement)i3);
          i3 = (OOC_INT32)token;
          i3 = *(OOC_INT8*)((_check_pointer(i3, 29039))+5);
          i3 = i3==36;
          if (i3) goto l52_loop;
l57:
          OOC_Doc_Input_Texinfo__Parse_ParseBlockList_CheckEnd(30);
          i3 = OOC_Doc_Input_Texinfo__Parse_ParseBlockList_AtEmptyLine();
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 29344));
          i4 = start;
          i0 = (OOC_INT32)OOC_Doc__NewEnumerate(i3, i0, i4, (OOC_Doc__Item)i1, (OOC_Doc__BlockElement)i2);
          return (OOC_Doc__Enumerate)i0;
          ;
        }

        
        OOC_Doc__Example OOC_Doc_Input_Texinfo__Parse_ParseBlockList_Example(void) {
          register OOC_INT32 i0,i1;

          OOC_Doc_Input_Texinfo__Parse_NextToken();
          OOC_Doc_Input_Texinfo__Parse_SkipWhitespace();
          i0 = (OOC_INT32)token;
          i0 = *(OOC_UINT8*)((_check_pointer(i0, 29573))+4);
          i0 = !i0;
          if (!i0) goto l3;
          OOC_Doc_Input_Texinfo__Parse_Err(5);
l3:
          i0 = (OOC_INT32)OOC_Doc_Input_Texinfo__Parse_ParseBlockList_ParseInlineList(0u, 1u, 0u);
          OOC_Doc_Input_Texinfo__Parse_ParseBlockList_CheckEnd(28);
          i1 = OOC_Doc_Input_Texinfo__Parse_ParseBlockList_AtEmptyLine();
          i0 = (OOC_INT32)OOC_Doc__NewExample(i1, (OOC_Doc__InlineElement)i0);
          return (OOC_Doc__Example)i0;
          ;
        }

        
        OOC_Doc__BlockElement OOC_Doc_Input_Texinfo__Parse_ParseBlockList_PCond(void) {
          register OOC_INT32 i0,i1;
          OOC_INT8 cmdId;

          i0 = (OOC_INT32)token;
          i0 = *(OOC_INT8*)((_check_pointer(i0, 29997))+5);
          cmdId = i0;
          OOC_Doc_Input_Texinfo__Parse_NextToken();
          OOC_Doc_Input_Texinfo__Parse_SkipWhitespace();
          i1 = (OOC_INT32)token;
          i1 = *(OOC_UINT8*)((_check_pointer(i1, 30063))+4);
          i1 = !i1;
          if (!i1) goto l3;
          OOC_Doc_Input_Texinfo__Parse_Err(5);
l3:
          i1 = (OOC_INT32)OOC_Doc_Input_Texinfo__Parse_ParseBlockList();
          blockList = (OOC_Doc__BlockElement)i1;
          OOC_Doc_Input_Texinfo__Parse_ParseBlockList_CheckEnd(i0);
          switch (i0) {
          case 32:
            i0 = OOC_Doc_Input_Texinfo__Parse_ParseBlockList_AtEmptyLine();
            i1 = (OOC_INT32)blockList;
            i0 = (OOC_INT32)OOC_Doc__NewPreCond(i0, (OOC_Doc__BlockElement)i1);
            return (OOC_Doc__BlockElement)i0;
            goto l8;
          case 33:
            i0 = OOC_Doc_Input_Texinfo__Parse_ParseBlockList_AtEmptyLine();
            i1 = (OOC_INT32)blockList;
            i0 = (OOC_INT32)OOC_Doc__NewPostCond(i0, (OOC_Doc__BlockElement)i1);
            return (OOC_Doc__BlockElement)i0;
            goto l8;
          default:
            _failed_case(i0, 30193);
            goto l8;
          }
l8:
          _failed_function(29816); return 0;
          ;
        }

        
        OOC_Doc__Table OOC_Doc_Input_Texinfo__Parse_ParseBlockList_Table(void) {
          register OOC_INT32 i0,i1,i2,i3;
          OOC_INT32 mark;
          OOC_Doc__BlockList rowList;
          OOC_Doc__BlockList firstColumnList;
          OOC_Doc__MarkedInline first;
          OOC_Doc__BlockElement tableEntry;

          OOC_Doc_Input_Texinfo__Parse_NextToken();
          OOC_Doc_Input_Texinfo__Parse_SkipWhitespace();
          i0 = (OOC_INT32)token;
          i1 = *(OOC_UINT8*)((_check_pointer(i0, 30799))+4);
          if (i1) goto l11;
          i1 = *(OOC_INT8*)((_check_pointer(i0, 30962))+5);
          i1 = 7<=i1;
          if (i1) goto l5;
          i1=0u;
          goto l7;
l5:
          i1 = *(OOC_INT8*)((_check_pointer(i0, 30976))+5);
          i1 = i1<26;
          
l7:
          if (i1) goto l9;
          mark = 0;
          OOC_Doc_Input_Texinfo__Parse_Err(12);
          OOC_Doc_Input_Texinfo__Parse_NextToken();
          i0=0;
          goto l12;
l9:
          i0 = *(OOC_INT8*)((_check_pointer(i0, 31033))+5);
          i0 = OOC_Doc_Input_Texinfo__Parse_IdToMark(i0);
          mark = i0;
          OOC_Doc_Input_Texinfo__Parse_NextToken();
          OOC_Doc_Input_Texinfo__Parse_SkipWhitespace();
          
          goto l12;
l11:
          mark = 0;
          OOC_Doc_Input_Texinfo__Parse_Err(12);
          i0=0;
l12:
          i1 = (OOC_INT32)token;
          i1 = *(OOC_UINT8*)((_check_pointer(i1, 31220))+4);
          i1 = !i1;
          if (!i1) goto l15;
          OOC_Doc_Input_Texinfo__Parse_Err(5);
l15:
          i1 = (OOC_INT32)OOC_Doc__NewBlockList();
          rowList = (OOC_Doc__BlockList)i1;
          i2 = (OOC_INT32)token;
          i3 = *(OOC_INT8*)((_check_pointer(i2, 31344))+5);
          i3 = i3!=35;
          if (i3) goto l18;
          i2=0u;
          goto l20;
l18:
          i2 = *(OOC_INT8*)((_check_pointer(i2, 31367))+5);
          i2 = i2!=46;
          
l20:
          if (!i2) goto l42;
l22_loop:
          i2 = (OOC_INT32)OOC_Doc__NewBlockList();
          firstColumnList = (OOC_Doc__BlockList)i2;
          i3 = (OOC_INT32)token;
          i3 = *(OOC_INT8*)((_check_pointer(i3, 31459))+5);
          i3 = i3==36;
          if (!i3) goto l33;
l24_loop:
          OOC_Doc_Input_Texinfo__Parse_NextToken();
          i3 = OOC_Doc_Input_Texinfo__Parse_IsOberonRef(i0);
          if (i3) goto l27;
          i3 = (OOC_INT32)OOC_Doc_Input_Texinfo__Parse_ParseBlockList_ParseInlineList(0u, 0u, 1u);
          i3 = (OOC_INT32)OOC_Doc__NewMarkedInline(i0, (OOC_Doc__InlineElement)i3);
          first = (OOC_Doc__MarkedInline)i3;
          
          goto l28;
l27:
          i3 = (OOC_INT32)OOC_Doc_Input_Texinfo__Parse_ParseBlockList_ParseInlineList(0u, 0u, 1u);
          i3 = (OOC_INT32)OOC_Doc__NewOberonRef(i0, (OOC_Doc__InlineElement)i3, (ADT_Storable__Object)(OOC_INT32)0);
          first = (OOC_Doc__MarkedInline)i3;
          
l28:
          i3 = (OOC_INT32)OOC_Doc__NewFirstColumn(0u, (OOC_Doc__InlineElement)i3);
          OOC_Doc__BlockListDesc_Append((OOC_Doc__BlockList)i2, (OOC_Doc__BlockElement)i3);
          i3 = (OOC_INT32)token;
          i3 = *(OOC_INT8*)((_check_pointer(i3, 31964))+5);
          i3 = i3!=37;
          if (!i3) goto l24_loop;
l33:
          i3 = (OOC_INT32)OOC_Doc_Input_Texinfo__Parse_ParseBlockList();
          tableEntry = (OOC_Doc__BlockElement)i3;
          i3 = (OOC_INT32)OOC_Doc__NewItem(0u, (OOC_Doc__BlockElement)i3);
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 32116));
          i2 = (OOC_INT32)OOC_Doc__NewTableRow(0u, (OOC_Doc__BlockElement)i2, (OOC_Doc__Item)i3);
          OOC_Doc__BlockListDesc_Append((OOC_Doc__BlockList)i1, (OOC_Doc__BlockElement)i2);
          i2 = (OOC_INT32)token;
          i3 = *(OOC_INT8*)((_check_pointer(i2, 31344))+5);
          i3 = i3!=35;
          if (i3) goto l36;
          i2=0u;
          goto l38;
l36:
          i2 = *(OOC_INT8*)((_check_pointer(i2, 31367))+5);
          i2 = i2!=46;
          
l38:
          if (i2) goto l22_loop;
l42:
          OOC_Doc_Input_Texinfo__Parse_ParseBlockList_CheckEnd(34);
          i0 = OOC_Doc_Input_Texinfo__Parse_ParseBlockList_AtEmptyLine();
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 32251));
          i0 = (OOC_INT32)OOC_Doc__NewTable(i0, (OOC_Doc__BlockElement)i1);
          return (OOC_Doc__Table)i0;
          ;
        }


      noIndent = 1u;
      i0 = (OOC_INT32)OOC_Doc__NewBlockList();
      list = (OOC_Doc__BlockList)i0;
      
l1_loop:
      i1 = (OOC_INT32)token;
      i2 = *(OOC_INT8*)((_check_pointer(i1, 32378))+5);
      switch (i2) {
      case 46:
        goto l25;
      case 44:
        OOC_Doc_Input_Texinfo__Parse_Err(10);
        OOC_Doc_Input_Texinfo__Parse_NextToken();
        
        goto l1_loop;
      case 31:
        noIndent = 1u;
        OOC_Doc_Input_Texinfo__Parse_NextToken();
        
        goto l1_loop;
      case 29:
        i0 = (OOC_INT32)OOC_Doc_Input_Texinfo__Parse_ParseBlockList_Itemize();
        i1 = (OOC_INT32)list;
        OOC_Doc__BlockListDesc_Append((OOC_Doc__BlockList)i1, (OOC_Doc__BlockElement)i0);
        i0=i1;
        goto l1_loop;
      case 30:
        i0 = (OOC_INT32)OOC_Doc_Input_Texinfo__Parse_ParseBlockList_Enumerate();
        i1 = (OOC_INT32)list;
        OOC_Doc__BlockListDesc_Append((OOC_Doc__BlockList)i1, (OOC_Doc__BlockElement)i0);
        i0=i1;
        goto l1_loop;
      case 28:
        i0 = (OOC_INT32)OOC_Doc_Input_Texinfo__Parse_ParseBlockList_Example();
        i1 = (OOC_INT32)list;
        OOC_Doc__BlockListDesc_Append((OOC_Doc__BlockList)i1, (OOC_Doc__BlockElement)i0);
        i0=i1;
        goto l1_loop;
      case 32:
      case 33:
        i0 = (OOC_INT32)OOC_Doc_Input_Texinfo__Parse_ParseBlockList_PCond();
        i1 = (OOC_INT32)list;
        OOC_Doc__BlockListDesc_Append((OOC_Doc__BlockList)i1, (OOC_Doc__BlockElement)i0);
        i0=i1;
        goto l1_loop;
      case 34:
        i0 = (OOC_INT32)OOC_Doc_Input_Texinfo__Parse_ParseBlockList_Table();
        i1 = (OOC_INT32)list;
        OOC_Doc__BlockListDesc_Append((OOC_Doc__BlockList)i1, (OOC_Doc__BlockElement)i0);
        i0=i1;
        goto l1_loop;
      default:
        i2 = *(OOC_INT8*)((_check_pointer(i1, 33027))+5);
        i2 = i2==42;
        if (i2) goto l14;
        i2=0u;
        goto l16;
l14:
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 33051))+20);
        i2 = (
        _cmp8((const void*)(_check_pointer(i2, 33056)),(const void*)(OOC_CHAR8*)""))==0;
        
l16:
        if (!i2) goto l17;
        goto l22;
l17:
        i1 = OOC_Doc_Input_Texinfo__Parse_IsInlineToken((OOC_Doc_Input_Texinfo__Token)i1);
        i1 = !i1;
        if (i1) goto l25;
        i0 = (OOC_INT32)OOC_Doc_Input_Texinfo__Parse_ParseBlockList_ParseInlineList(0u, 0u, 0u);
        inlineText = (OOC_Doc__InlineElement)i0;
        i1 = OOC_Doc_Input_Texinfo__Parse_ParseBlockList_AtEmptyLine();
        i2 = noIndent;
        i0 = (OOC_INT32)OOC_Doc__NewParagraph(i1, (OOC_Doc__InlineElement)i0, i2);
        i1 = (OOC_INT32)list;
        OOC_Doc__BlockListDesc_Append((OOC_Doc__BlockList)i1, (OOC_Doc__BlockElement)i0);
        noIndent = 0u;
        i0=i1;
        goto l1_loop;
l22:
        OOC_Doc_Input_Texinfo__Parse_NextToken();
        
        goto l1_loop;
      }
l25:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 33482));
      return (OOC_Doc__BlockElement)i0;
      ;
    }


  i0 = (OOC_INT32)OOC_Doc_TextBuffer__New();
  buffer = (OOC_Doc_TextBuffer__Buffer)i0;
  i0 = removeDecoration;
  if (i0) goto l3;
  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33659))+8);
  str = (OOC_Scanner_InputBuffer__CharArray)i1;
  decoration = (OOC_Doc_Decoration__Decoration)(OOC_INT32)0;
  {register OOC_INT32 h0=i0;i0=i1;i1=h0;}
  goto l4;
l3:
  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)OOC_Doc_Decoration__Remove((OOC_Scanner_SymList__Symbol)i0, (void*)(OOC_INT32)&decoration);
  str = (OOC_Scanner_InputBuffer__CharArray)i1;
  {register OOC_INT32 h0=i0;i0=i1;i1=h0;}
l4:
  i2 = (OOC_INT32)errList;
  i3 = *(OOC_INT32*)(_check_pointer(i2, 33723));
  oldErrors = i3;
  i0 = (OOC_INT32)OOC_Doc_Input_Texinfo__Tokenize((OOC_Scanner_SymList__Symbol)i1, (OOC_Scanner_InputBuffer__CharArray)i0, (OOC_Error__List)i2);
  tokenList = (OOC_Doc_Input_Texinfo__Token)i0;
  i1 = *(OOC_INT32*)(_check_pointer(i2, 33851));
  i1 = i1==i3;
  if (i1) goto l7;
  return (OOC_Doc__Document)(OOC_INT32)0;
  goto l8;
l7:
  token = (OOC_Doc_Input_Texinfo__Token)i0;
  i0 = (OOC_INT32)OOC_Doc_Input_Texinfo__Parse_ParseBlockList();
  blockList = (OOC_Doc__BlockElement)i0;
  OOC_Doc_Input_Texinfo__Parse_CheckToken(46);
  i0 = (OOC_INT32)sym;
  i0 = *(OOC_INT32*)((_check_pointer(i0, 34070))+24);
  i1 = (OOC_INT32)decoration;
  i2 = (OOC_INT32)blockList;
  i0 = (OOC_INT32)OOC_Doc__NewDocument((OOC_Doc__BlockElement)i2, (OOC_Doc_Decoration__Decoration)i1, i0);
  OOC_Doc__DocumentDesc_Normalize((OOC_Doc__Document)i0);
  return (OOC_Doc__Document)i0;
l8:
  _failed_function(14065); return 0;
  ;
}

static void OOC_Doc_Input_Texinfo__Init(void) {
  register OOC_INT32 i0,i1;
  OOC_INT32 i;
  auto void OOC_Doc_Input_Texinfo__Init_Register(OOC_INT32 cmdId, const OOC_CHAR8 name__ref[], OOC_LEN name_0d);
  auto void OOC_Doc_Input_Texinfo__Init_RegisterArgs(OOC_INT32 cmdId, OOC_INT8 low, OOC_INT8 high);
    
    void OOC_Doc_Input_Texinfo__Init_Register(OOC_INT32 cmdId, const OOC_CHAR8 name__ref[], OOC_LEN name_0d) {
      register OOC_INT32 i0,i1;
      OOC_ALLOCATE_VPAR(name,OOC_CHAR8 ,name_0d)

      OOC_INITIALIZE_VPAR(name__ref,name,OOC_CHAR8 ,name_0d)
      i0 = cmdId;
      i1 = (OOC_INT32)*(OOC_INT32*)((OOC_INT32)OOC_Doc_Input_Texinfo__cmdList+(_check_index(i0, 38, OOC_UINT32, 34304))*4);
      i1 = *(OOC_INT8*)((_check_pointer(i1, 34311))+1);
      i1 = i1==(-1);
      if (i1) goto l4;
      Out__String((OOC_CHAR8*)"Module OOC:Doc:Input:Texinfo: Command id ", 42);
      Out__LongInt(i0, 0);
      Out__String((OOC_CHAR8*)" for @", 7);
      Out__String((void*)(OOC_INT32)name, name_0d);
      Out__String((OOC_CHAR8*)" already in use by @", 21);
      i0 = (OOC_INT32)*(OOC_INT32*)((OOC_INT32)OOC_Doc_Input_Texinfo__cmdList+(_check_index(i0, 38, OOC_UINT32, 35179))*4);
      Out__String((void*)((_check_pointer(i0, 35186))+2), 16);
      Out__Ln();
      _halt(1);
      goto l11;
l4:
      switch (i0) {
      case 0 ... 2:
        i1 = (OOC_INT32)*(OOC_INT32*)((OOC_INT32)OOC_Doc_Input_Texinfo__cmdList+(_check_index(i0, 38, OOC_UINT32, 34402))*4);
        *(OOC_INT8*)((_check_pointer(i1, 34409))+1) = 1;
        i1 = *(OOC_UINT8*)((OOC_INT32)name+(_check_index(1, name_0d, OOC_UINT8, 34445)));
        _assert((i1==0u), 127, 34433);
        _assert((i0<127), 127, 34466);
        i1 = *(OOC_UINT8*)((OOC_INT32)name+(_check_index(0, name_0d, OOC_UINT8, 34519)));
        *(OOC_INT8*)((OOC_INT32)OOC_Doc_Input_Texinfo__class1+(_check_index(i1, 256, OOC_UINT16, 34509))) = i0;
        goto l10;
      case 3 ... 6:
        i1 = (OOC_INT32)*(OOC_INT32*)((OOC_INT32)OOC_Doc_Input_Texinfo__cmdList+(_check_index(i0, 38, OOC_UINT32, 34600))*4);
        *(OOC_INT8*)((_check_pointer(i1, 34607))+1) = 2;
        goto l10;
      case 7 ... 27:
        i1 = (OOC_INT32)*(OOC_INT32*)((OOC_INT32)OOC_Doc_Input_Texinfo__cmdList+(_check_index(i0, 38, OOC_UINT32, 34670))*4);
        *(OOC_INT8*)((_check_pointer(i1, 34677))+1) = 3;
        i1 = (OOC_INT32)*(OOC_INT32*)((OOC_INT32)OOC_Doc_Input_Texinfo__cmdList+(_check_index(i0, 38, OOC_UINT32, 34708))*4);
        *(OOC_INT8*)((_check_pointer(i1, 34715))+18) = 1;
        i1 = (OOC_INT32)*(OOC_INT32*)((OOC_INT32)OOC_Doc_Input_Texinfo__cmdList+(_check_index(i0, 38, OOC_UINT32, 34747))*4);
        *(OOC_INT8*)((_check_pointer(i1, 34754))+19) = 1;
        goto l10;
      case 28 ... 37:
        i1 = (OOC_INT32)*(OOC_INT32*)((OOC_INT32)OOC_Doc_Input_Texinfo__cmdList+(_check_index(i0, 38, OOC_UINT32, 34819))*4);
        *(OOC_INT8*)((_check_pointer(i1, 34826))+1) = 4;
        goto l10;
      default:
        _failed_case(i0, 34338);
        goto l10;
      }
l10:
      i1 = (OOC_INT32)*(OOC_INT32*)((OOC_INT32)OOC_Doc_Input_Texinfo__cmdList+(_check_index(i0, 38, OOC_UINT32, 34879))*4);
      _copy_8((const void*)(OOC_INT32)name,(void*)((_check_pointer(i1, 34886))+2),16);
      i0 = (OOC_INT32)*(OOC_INT32*)((OOC_INT32)OOC_Doc_Input_Texinfo__cmdList+(_check_index(i0, 38, OOC_UINT32, 34925))*4);
      _assert(((
      _cmp8((const void*)(OOC_INT32)name,(const void*)((_check_pointer(i0, 34932))+2)))==0), 127, 34903);
l11:
      return;
      ;
    }

    
    void OOC_Doc_Input_Texinfo__Init_RegisterArgs(OOC_INT32 cmdId, OOC_INT8 low, OOC_INT8 high) {
      register OOC_INT32 i0,i1,i2;

      i0 = cmdId;
      i1 = (OOC_INT32)*(OOC_INT32*)((OOC_INT32)OOC_Doc_Input_Texinfo__cmdList+(_check_index(i0, 38, OOC_UINT32, 35343))*4);
      i2 = low;
      *(OOC_INT8*)((_check_pointer(i1, 35350))+18) = i2;
      i0 = (OOC_INT32)*(OOC_INT32*)((OOC_INT32)OOC_Doc_Input_Texinfo__cmdList+(_check_index(i0, 38, OOC_UINT32, 35380))*4);
      i1 = high;
      *(OOC_INT8*)((_check_pointer(i0, 35387))+19) = i1;
      return;
      ;
    }


  i0=0;
l1_loop:
  *(OOC_INT8*)((OOC_INT32)OOC_Doc_Input_Texinfo__class1+(_check_index(i0, 256, OOC_UINT32, 35473))) = (-1);
  i0 = i0+1;
  i1 = i0<=255;
  if (i1) goto l1_loop;
l5:
  i = 0;
  i0=0;
l6_loop:
  *(OOC_INT32*)((OOC_INT32)OOC_Doc_Input_Texinfo__cmdList+(_check_index(i0, 38, OOC_UINT32, 35542))*4) = ((OOC_INT32)RT0__NewObject(_td_OOC_Doc_Input_Texinfo__Command.baseTypes[0]));
  i1 = (OOC_INT32)*(OOC_INT32*)((OOC_INT32)OOC_Doc_Input_Texinfo__cmdList+(_check_index(i0, 38, OOC_UINT32, 35561))*4);
  *(OOC_INT8*)((_check_pointer(i1, 35564))+1) = (-1);
  i1 = (OOC_INT32)*(OOC_INT32*)((OOC_INT32)OOC_Doc_Input_Texinfo__cmdList+(_check_index(i0, 38, OOC_UINT32, 35592))*4);
  _copy_8((const void*)(OOC_CHAR8*)"",(void*)((_check_pointer(i1, 35595))+2),16);
  i1 = (OOC_INT32)*(OOC_INT32*)((OOC_INT32)OOC_Doc_Input_Texinfo__cmdList+(_check_index(i0, 38, OOC_UINT32, 35622))*4);
  *(OOC_INT8*)((_check_pointer(i1, 35625))+18) = (-1);
  i1 = (OOC_INT32)*(OOC_INT32*)((OOC_INT32)OOC_Doc_Input_Texinfo__cmdList+(_check_index(i0, 38, OOC_UINT32, 35654))*4);
  *(OOC_INT8*)((_check_pointer(i1, 35657))+19) = (-1);
  i0 = i0+1;
  i = i0;
  i1 = i0<=37;
  if (i1) goto l6_loop;
l10:
  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Scanner_InputBuffer__CharArray.baseTypes[0], 1);
  OOC_Doc_Input_Texinfo__emptyString = (OOC_Scanner_InputBuffer__CharArray)i0;
  i0 = _check_pointer(i0, 35723);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  *(OOC_UINT8*)(i0+(_check_index(0, i1, OOC_UINT8, 35723))) = 0u;
  OOC_Doc_Input_Texinfo__Init_Register(0, (OOC_CHAR8*)"@", 2);
  OOC_Doc_Input_Texinfo__Init_Register(1, (OOC_CHAR8*)"{", 2);
  OOC_Doc_Input_Texinfo__Init_Register(2, (OOC_CHAR8*)"}", 2);
  OOC_Doc_Input_Texinfo__Init_Register(3, (OOC_CHAR8*)"bullet", 7);
  OOC_Doc_Input_Texinfo__Init_Register(4, (OOC_CHAR8*)"dots", 5);
  OOC_Doc_Input_Texinfo__Init_Register(5, (OOC_CHAR8*)"minus", 6);
  OOC_Doc_Input_Texinfo__Init_Register(6, (OOC_CHAR8*)"result", 7);
  OOC_Doc_Input_Texinfo__Init_Register(7, (OOC_CHAR8*)"asis", 5);
  OOC_Doc_Input_Texinfo__Init_Register(8, (OOC_CHAR8*)"cite", 5);
  OOC_Doc_Input_Texinfo__Init_Register(9, (OOC_CHAR8*)"code", 5);
  OOC_Doc_Input_Texinfo__Init_Register(10, (OOC_CHAR8*)"command", 8);
  OOC_Doc_Input_Texinfo__Init_Register(11, (OOC_CHAR8*)"dfn", 4);
  OOC_Doc_Input_Texinfo__Init_Register(26, (OOC_CHAR8*)"email", 6);
  OOC_Doc_Input_Texinfo__Init_RegisterArgs(26, 1, 2);
  OOC_Doc_Input_Texinfo__Init_Register(12, (OOC_CHAR8*)"emph", 5);
  OOC_Doc_Input_Texinfo__Init_Register(13, (OOC_CHAR8*)"file", 5);
  OOC_Doc_Input_Texinfo__Init_Register(14, (OOC_CHAR8*)"kbd", 4);
  OOC_Doc_Input_Texinfo__Init_Register(19, (OOC_CHAR8*)"omodule", 8);
  OOC_Doc_Input_Texinfo__Init_Register(20, (OOC_CHAR8*)"oconst", 7);
  OOC_Doc_Input_Texinfo__Init_Register(21, (OOC_CHAR8*)"ofield", 7);
  OOC_Doc_Input_Texinfo__Init_Register(22, (OOC_CHAR8*)"oparam", 7);
  OOC_Doc_Input_Texinfo__Init_Register(23, (OOC_CHAR8*)"oproc", 6);
  OOC_Doc_Input_Texinfo__Init_Register(24, (OOC_CHAR8*)"otype", 6);
  OOC_Doc_Input_Texinfo__Init_Register(25, (OOC_CHAR8*)"ovar", 5);
  OOC_Doc_Input_Texinfo__Init_Register(15, (OOC_CHAR8*)"samp", 5);
  OOC_Doc_Input_Texinfo__Init_Register(16, (OOC_CHAR8*)"strong", 7);
  OOC_Doc_Input_Texinfo__Init_Register(27, (OOC_CHAR8*)"uref", 5);
  OOC_Doc_Input_Texinfo__Init_RegisterArgs(27, 1, 3);
  OOC_Doc_Input_Texinfo__Init_Register(17, (OOC_CHAR8*)"url", 4);
  OOC_Doc_Input_Texinfo__Init_Register(18, (OOC_CHAR8*)"var", 4);
  OOC_Doc_Input_Texinfo__Init_Register(35, (OOC_CHAR8*)"end", 4);
  OOC_Doc_Input_Texinfo__Init_Register(30, (OOC_CHAR8*)"enumerate", 10);
  OOC_Doc_Input_Texinfo__Init_Register(28, (OOC_CHAR8*)"example", 8);
  OOC_Doc_Input_Texinfo__Init_Register(36, (OOC_CHAR8*)"item", 5);
  OOC_Doc_Input_Texinfo__Init_Register(29, (OOC_CHAR8*)"itemize", 8);
  OOC_Doc_Input_Texinfo__Init_Register(37, (OOC_CHAR8*)"itemx", 6);
  OOC_Doc_Input_Texinfo__Init_Register(31, (OOC_CHAR8*)"noindent", 9);
  OOC_Doc_Input_Texinfo__Init_Register(32, (OOC_CHAR8*)"precond", 8);
  OOC_Doc_Input_Texinfo__Init_Register(33, (OOC_CHAR8*)"postcond", 9);
  OOC_Doc_Input_Texinfo__Init_Register(34, (OOC_CHAR8*)"table", 6);
  return;
  ;
}

void OOC_OOC_Doc_Input_Texinfo_init(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Doc_Input_Texinfo__ErrorContext.baseTypes[0]);
  OOC_Doc_Input_Texinfo__texinfoContext = (OOC_Doc_Input_Texinfo__ErrorContext)i0;
  OOC_Error__InitContext((OOC_Error__Context)i0, (OOC_CHAR8*)"OOC:Doc:Texinfo", 16);
  OOC_Doc_Input_Texinfo__Init();
  return;
  ;
}

void OOC_OOC_Doc_Input_Texinfo_destroy(void) {
}

/* --- */
