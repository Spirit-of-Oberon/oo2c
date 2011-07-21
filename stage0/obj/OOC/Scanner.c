#include <OOC/Scanner.d>
#include <__oo2c.h>
#include <setjmp.h>

void OOC_Scanner__ErrorContextDesc_GetTemplate(OOC_Scanner__ErrorContext context, Msg__Msg msg, Msg__LString templ, OOC_LEN templ_0d) {
  register OOC_INT32 i0,i1;
  OOC_CHAR16 t[128];

  i0 = (OOC_INT32)msg;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 3764))+8);
  switch (i1) {
  case 1:
    _copy_16((const void*)((OOC_CHAR16[]){67,111,109,109,101,110,116,32,110,111,116,32,99,108,111,115,101,100,0}),(void*)(OOC_INT32)t,128);
    goto l11;
  case 2:
    _copy_16((const void*)((OOC_CHAR16[]){73,108,108,101,103,97,108,32,99,104,97,114,97,99,116,101,114,32,48,36,123,99,104,97,114,95,99,111,100,101,125,88,32,105,110,32,115,116,114,105,110,103,0}),(void*)(OOC_INT32)t,128);
    goto l11;
  case 3:
    _copy_16((const void*)((OOC_CHAR16[]){83,116,114,105,110,103,32,110,111,116,32,101,110,100,101,100,0}),(void*)(OOC_INT32)t,128);
    goto l11;
  case 4:
    _copy_16((const void*)((OOC_CHAR16[]){78,111,116,32,119,105,116,104,105,110,32,99,111,109,109,101,110,116,0}),(void*)(OOC_INT32)t,128);
    goto l11;
  case 5:
    _copy_16((const void*)((OOC_CHAR16[]){73,108,108,101,103,97,108,32,115,121,109,98,111,108,32,96,36,123,115,121,109,95,115,116,114,105,110,103,125,39,0}),(void*)(OOC_INT32)t,128);
    goto l11;
  case 6:
    _copy_16((const void*)((OOC_CHAR16[]){73,108,108,101,103,97,108,32,101,120,112,111,110,101,110,116,32,102,111,114,109,97,116,0}),(void*)(OOC_INT32)t,128);
    goto l11;
  case 7:
    _copy_16((const void*)((OOC_CHAR16[]){73,108,108,101,103,97,108,32,99,105,112,104,101,114,0}),(void*)(OOC_INT32)t,128);
    goto l11;
  case 8:
    _copy_16((const void*)((OOC_CHAR16[]){78,111,116,32,119,105,116,104,105,110,32,112,114,97,103,109,97,0}),(void*)(OOC_INT32)t,128);
    goto l11;
  default:
    _failed_case(i1, 3756);
    goto l11;
  }
l11:
  i1 = (OOC_INT32)context;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4269)))), OOC_Error__ContextDesc_BaseTemplate)),OOC_Error__ContextDesc_BaseTemplate)((OOC_Error__Context)i1, (Msg__Msg)i0, (void*)(OOC_INT32)t, 128, (void*)(OOC_INT32)templ, templ_0d);
  return;
  ;
}

void OOC_Scanner__ScanInput(OOC_Scanner_SymList__Builder builder, OOC_Config_Pragmas__Section defaultPragmas, OOC_UINT32 scanOptions) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  OOC_Scanner_InputBuffer__Buffer b;
  Msg__Msg lastError;
  OOC_Scanner_InputBuffer__CharArray chars;
  OOC_INT32 cpos;
  OOC_INT32 currLine;
  OOC_INT32 currLinePos;
  OOC_INT32 currLineTab;
  OOC_INT8 inputMode;
  OOC_CHAR8 eolIsCRLF;
  struct OOC_Scanner_Pragma__State pragma;
  OOC_INT32 cstart;
  OOC_INT32 startLine;
  OOC_INT32 startColumn;
  OOC_CHAR8 dummy;
  OOC_INT32 currColumn;
  OOC_INT32 sum;
  OOC_INT8 sym;
  Msg__StringPtr strPtr;
  OOC_INT32 i;
  auto void OOC_Scanner__ScanInput_Err(OOC_INT32 code);
  auto void OOC_Scanner__ScanInput_ErrPos(OOC_INT32 code, OOC_INT32 cpos);
  auto OOC_CHAR8 OOC_Scanner__ScanInput_NextBlock(void);
  auto void OOC_Scanner__ScanInput_EndOfLine(OOC_INT32 sizeEOL);
  auto void OOC_Scanner__ScanInput_Lookahead(OOC_INT32 len);
  auto OOC_CHAR8 OOC_Scanner__ScanInput_LookaheadChar(void);
  auto OOC_CHAR8 OOC_Scanner__ScanInput_CompareIdent(OOC_INT32 start, OOC_CHAR8 kw[], OOC_LEN kw_0d);
  auto void OOC_Scanner__ScanInput_SetCharAttrib(OOC_INT32 ch);
    
    void OOC_Scanner__ScanInput_Err(OOC_INT32 code) {
      register OOC_INT32 i0,i1,i2;

      i0 = (OOC_INT32)OOC_Scanner__scannerContext;
      i1 = code;
      i0 = (OOC_INT32)OOC_Error__New((OOC_Error__Context)i0, i1);
      lastError = (Msg__Msg)i0;
      i1 = (OOC_INT32)b;
      i1 = *(OOC_INT32*)((_check_pointer(i1, 6247))+8);
      i2 = cstart;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6216)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i0, "pos", 4, (i2+i1));
      i0 = (OOC_INT32)lastError;
      i1 = startLine;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6281)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i0, "line", 5, i1);
      i0 = (OOC_INT32)lastError;
      i1 = startColumn;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6332)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i0, "column", 7, i1);
      i0 = (OOC_INT32)b;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6379))+20);
      i1 = (OOC_INT32)lastError;
      OOC_Error__ListDesc_Append((OOC_Error__List)i0, (Msg__Msg)i1);
      sym = 73;
      return;
      ;
    }

    
    void OOC_Scanner__ScanInput_ErrPos(OOC_INT32 code, OOC_INT32 cpos) {
      register OOC_INT32 i0,i1,i2,i3;

      i0 = code;
      OOC_Scanner__ScanInput_Err(i0);
      i0 = (OOC_INT32)lastError;
      i1 = (OOC_INT32)b;
      i1 = *(OOC_INT32*)((_check_pointer(i1, 6582))+8);
      i2 = cpos;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6553)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i0, "pos", 4, (i2+i1));
      i0 = (OOC_INT32)lastError;
      i1 = currLinePos;
      i3 = currLineTab;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6616)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i0, "column", 7, ((i2-i1)+i3));
      return;
      ;
    }

    
    OOC_CHAR8 OOC_Scanner__ScanInput_NextBlock(void) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      OOC_INT32 oldOffset;
      OOC_CHAR8 res;

      i0 = (OOC_INT32)b;
      i1 = *(OOC_INT32*)((_check_pointer(i0, 6840))+8);
      oldOffset = i1;
      i0 = OOC_Scanner_InputBuffer__BufferDesc_NextBlock((OOC_Scanner_InputBuffer__Buffer)i0);
      res = i0;
      i2 = (OOC_INT32)b;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 6903))+4);
      chars = (OOC_Scanner_InputBuffer__CharArray)i3;
      i3 = *(OOC_INT32*)((_check_pointer(i2, 6930))+8);
      i4 = cpos;
      cpos = (i4-(i3-i1));
      i3 = *(OOC_INT32*)((_check_pointer(i2, 6979))+8);
      i4 = cstart;
      cstart = (i4-(i3-i1));
      i2 = *(OOC_INT32*)((_check_pointer(i2, 7033))+8);
      i3 = currLinePos;
      currLinePos = (i3-(i2-i1));
      return i0;
      ;
    }

    
    void OOC_Scanner__ScanInput_EndOfLine(OOC_INT32 sizeEOL) {
      register OOC_INT32 i0,i1,i2;

      i0 = cpos;
      i1 = sizeEOL;
      i0 = i0+i1;
      i2 = currLine;
      cpos = i0;
      currLine = (i2+1);
      currLinePos = i0;
      currLineTab = 0;
      i0 = i1==2;
      if (!i0) goto l4;
      eolIsCRLF = 1u;
l4:
      return;
      ;
    }

    
    void OOC_Scanner__ScanInput_Lookahead(OOC_INT32 len) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      OOC_INT32 i;

      i = 1;
      i0 = len;
      i1 = 1<=i0;
      if (!i1) goto l15;
      i1=1;
l3_loop:
      i2 = (OOC_INT32)chars;
      i2 = _check_pointer(i2, 7485);
      i3 = cpos;
      i4 = OOC_ARRAY_LENGTH(i2, 0);
      i2 = *(OOC_UINT8*)(i2+(_check_index((i3+i1), i4, OOC_UINT32, 7485)));
      i2 = i2==0u;
      if (i2) goto l6;
      i2=0u;
      goto l8;
l6:
      i2 = OOC_Scanner__ScanInput_NextBlock();
      i2 = !i2;
      
l8:
      if (!i2) goto l10;
      return;
l10:
      i1 = i1+1;
      i = i1;
      i2 = i1<=i0;
      if (i2) goto l3_loop;
l15:
      return;
      ;
    }

    
    OOC_CHAR8 OOC_Scanner__ScanInput_LookaheadChar(void) {
      register OOC_INT32 i0,i1,i2;

      OOC_Scanner__ScanInput_Lookahead(1);
      i0 = (OOC_INT32)chars;
      i0 = _check_pointer(i0, 7700);
      i1 = cpos;
      i2 = OOC_ARRAY_LENGTH(i0, 0);
      i0 = *(OOC_UINT8*)(i0+(_check_index((i1+1), i2, OOC_UINT32, 7700)));
      return i0;
      ;
    }

    
    OOC_CHAR8 OOC_Scanner__ScanInput_CompareIdent(OOC_INT32 start, OOC_CHAR8 kw[], OOC_LEN kw_0d) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
      OOC_INT32 i;

      i = 0;
      i0 = *(OOC_UINT8*)((OOC_INT32)kw+(_check_index(0, kw_0d, OOC_UINT32, 8061)));
      i0 = i0!=0u;
      if (i0) goto l3;
      i0=0u;
      goto l5;
l3:
      i0 = (OOC_INT32)chars;
      i0 = _check_pointer(i0, 8087);
      i1 = OOC_ARRAY_LENGTH(i0, 0);
      i2 = start;
      i3 = *(OOC_UINT8*)((OOC_INT32)kw+(_check_index(0, kw_0d, OOC_UINT32, 8076)));
      i0 = *(OOC_UINT8*)(i0+(_check_index(i2, i1, OOC_UINT32, 8087)));
      i0 = i3==i0;
      
l5:
      if (i0) goto l7;
      i0=0;
      goto l17;
l7:
      i0 = (OOC_INT32)chars;
      i1 = start;
      i3=i1;i2=0;
l8_loop:
      i2 = i2+1;
      i = i2;
      i4 = *(OOC_UINT8*)((OOC_INT32)kw+(_check_index(i2, kw_0d, OOC_UINT32, 8061)));
      i3 = i3+1;
      i4 = i4!=0u;
      if (i4) goto l11;
      i4=0u;
      goto l13;
l11:
      i4 = _check_pointer(i0, 8087);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i6 = *(OOC_UINT8*)((OOC_INT32)kw+(_check_index(i2, kw_0d, OOC_UINT32, 8076)));
      i4 = *(OOC_UINT8*)(i4+(_check_index(i3, i5, OOC_UINT32, 8087)));
      i4 = i6==i4;
      
l13:
      if (i4) goto l8_loop;
l16:
      i0 = i3-i1;
      
l17:
      i1 = *(OOC_UINT8*)((OOC_INT32)kw+(_check_index(i0, kw_0d, OOC_UINT32, 8144)));
      i1 = i1==0u;
      if (i1) goto l20;
      i0=0u;
      goto l21;
l20:
      i1 = start;
      i2 = cpos;
      i0 = (i1+i0)==i2;
      
l21:
      return i0;
      ;
    }

    
    void OOC_Scanner__ScanInput_SetCharAttrib(OOC_INT32 ch) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
      Msg__StringPtr str;
      OOC_INT32 i;
      OOC_INT32 j;
      OOC_CHAR8 h;

      i0 = (OOC_INT32)RT0__NewObject(_td_Msg__StringPtr.baseTypes[0], 6);
      str = (Msg__StringPtr)i0;
      i = 0;
      i1=0;
l1_loop:
      i2 = ch;
      i3 = _mod(i2,16);
      i4 = i3<10;
      if (i4) goto l4;
      i4 = _check_pointer(i0, 8473);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      *(OOC_UINT8*)(i4+(_check_index(i1, i5, OOC_UINT32, 8473))) = (i3+55);
      goto l5;
l4:
      i4 = _check_pointer(i0, 8414);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      *(OOC_UINT8*)(i4+(_check_index(i1, i5, OOC_UINT32, 8414))) = (i3+48);
l5:
      i2 = i2>>4;
      ch = i2;
      i1 = i1+1;
      i = i1;
      i2 = i2==0;
      if (!i2) goto l1_loop;
l9:
      i2 = _check_pointer(i0, 8596);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      *(OOC_UINT8*)(i2+(_check_index(i1, i3, OOC_UINT32, 8596))) = 0u;
      j = 0;
      i1 = i1-1;
      i = i1;
      i2 = 0<i1;
      if (!i2) goto l17;
      i2=i1;i1=0;
l12_loop:
      i3 = _check_pointer(i0, 8676);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = *(OOC_UINT8*)(i3+(_check_index(i1, i4, OOC_UINT32, 8676)));
      h = i3;
      i4 = _check_pointer(i0, 8684);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i6 = _check_pointer(i0, 8694);
      i7 = OOC_ARRAY_LENGTH(i6, 0);
      i6 = *(OOC_UINT8*)(i6+(_check_index(i2, i7, OOC_UINT32, 8694)));
      *(OOC_UINT8*)(i4+(_check_index(i1, i5, OOC_UINT32, 8684))) = i6;
      i4 = _check_pointer(i0, 8702);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      *(OOC_UINT8*)(i4+(_check_index(i2, i5, OOC_UINT32, 8702))) = i3;
      i1 = i1+1;
      j = i1;
      i2 = i2-1;
      i = i2;
      i3 = i1<i2;
      if (i3) goto l12_loop;
l17:
      i1 = (OOC_INT32)lastError;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8770)))), Msg__MsgDesc_SetStringAttrib)),Msg__MsgDesc_SetStringAttrib)((Msg__Msg)i1, "char_code", 10, (Msg__StringPtr)i0);
      return;
      ;
    }


  i0 = (OOC_INT32)builder;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 8860));
  b = (OOC_Scanner_InputBuffer__Buffer)i1;
  lastError = (Msg__Msg)0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8911))+4);
  chars = (OOC_Scanner_InputBuffer__CharArray)i1;
  cpos = 0;
  currLine = 0;
  currLinePos = 0;
  currLineTab = 0;
  inputMode = 0;
  eolIsCRLF = 0u;
  i1 = (OOC_INT32)&_td_OOC_Scanner_Pragma__State;
  i2 = (OOC_INT32)defaultPragmas;
  OOC_Scanner_Pragma__Init((void*)(OOC_INT32)&pragma, (RT0__Struct)i1, (OOC_Scanner_SymList__Builder)i0, (OOC_Config_Pragmas__Section)i2);
l1_loop:
  i0 = cpos;
  i2 = currLinePos;
  cstart = i0;
  i3 = currLine;
  i4 = currLineTab;
  startLine = i3;
  startColumn = ((i0-i2)+i4);
l2_loop:
  i0 = (OOC_INT32)chars;
  i2 = _check_pointer(i0, 9286);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = cpos;
  i2 = *(OOC_UINT8*)(i2+(_check_index(i4, i3, OOC_UINT32, 9286)));
  switch (i2) {
  case 0u:
    i0 = (OOC_INT32)b;
    i0 = OOC_Scanner_InputBuffer__BufferDesc_EndOfBuffer((OOC_Scanner_InputBuffer__Buffer)i0, i4);
    if (i0) goto l7;
    cpos = (i4+1);
    goto l2_loop;
l7:
    i0 = OOC_Scanner__ScanInput_NextBlock();
    i0 = !i0;
    if (!i0) goto l2_loop;
    goto l25;
  case 10u:
    OOC_Scanner__ScanInput_EndOfLine(1);
    goto l2_loop;
  case 13u:
    i0 = _check_pointer(i0, 9614);
    i2 = OOC_ARRAY_LENGTH(i0, 0);
    i0 = *(OOC_UINT8*)(i0+(_check_index((i4+1), i2, OOC_UINT32, 9614)));
    i0 = i0==0u;
    if (!i0) goto l16;
    i0 = OOC_Scanner__ScanInput_NextBlock();
    dummy = i0;
l16:
    i0 = (OOC_INT32)chars;
    i0 = _check_pointer(i0, 9763);
    i2 = cpos;
    i3 = OOC_ARRAY_LENGTH(i0, 0);
    i0 = *(OOC_UINT8*)(i0+(_check_index((i2+1), i3, OOC_UINT32, 9763)));
    i0 = i0==10u;
    if (!i0) goto l18;
    goto l19;
l18:
    OOC_Scanner__ScanInput_EndOfLine(1);
    goto l2_loop;
l19:
    OOC_Scanner__ScanInput_EndOfLine(2);
    goto l2_loop;
  case 9u:
    i0 = currLinePos;
    i2 = currLineTab;
    i0 = (i4-i0)+i2;
    currColumn = i0;
    currLineTab = (i2+((8-(_mod(i0,8)))-1));
    cpos = (i4+1);
    goto l2_loop;
  case 33u ... 255u:
    goto l25;
  default:
    cpos = (i4+1);
    goto l2_loop;
  }
l25:
  i0 = cpos;
  i2 = cstart;
  i3 = i2!=i0;
  if (i3) goto l28;
  i3=0u;
  goto l30;
l28:
  i3 = inputMode;
  i3 = i3==0;
  
l30:
  if (!i3) goto l32;
  i3 = (OOC_INT32)builder;
  i4 = startColumn;
  i5 = startLine;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 10260)))), OOC_Scanner_SymList__BuilderDesc_AddSymbol)),OOC_Scanner_SymList__BuilderDesc_AddSymbol)((OOC_Scanner_SymList__Builder)i3, 80, i2, i0, i5, i4);
l32:
  i2 = currLinePos;
  cstart = i0;
  i3 = currLine;
  i4 = currLineTab;
  startLine = i3;
  startColumn = ((i0-i2)+i4);
  i2 = (OOC_INT32)chars;
  i3 = _check_pointer(i2, 10701);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = *(OOC_UINT8*)(i3+(_check_index(i0, i4, OOC_UINT32, 10701)));
  switch (i3) {
  case 0u:
    goto l447;
  case 95u:
    i0 = scanOptions;
    i0 = _in(0,i0);
    if (i0) goto l38_loop;
    OOC_Scanner__ScanInput_Err(5);
    i0 = (OOC_INT32)RT0__NewObject(_td_Msg__StringPtr.baseTypes[0], 2);
    strPtr = (Msg__StringPtr)i0;
    i2 = _check_pointer(i0, 11428);
    i3 = OOC_ARRAY_LENGTH(i2, 0);
    i4 = (OOC_INT32)chars;
    i4 = _check_pointer(i4, 11440);
    i5 = OOC_ARRAY_LENGTH(i4, 0);
    i6 = cpos;
    i4 = *(OOC_UINT8*)(i4+(_check_index(i6, i5, OOC_UINT32, 11440)));
    *(OOC_UINT8*)(i2+(_check_index(0, i3, OOC_UINT8, 11428))) = i4;
    i2 = _check_pointer(i0, 11454);
    i3 = OOC_ARRAY_LENGTH(i2, 0);
    *(OOC_UINT8*)(i2+(_check_index(1, i3, OOC_UINT8, 11454))) = 0u;
    i2 = (OOC_INT32)lastError;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 11484)))), Msg__MsgDesc_SetStringAttrib)),Msg__MsgDesc_SetStringAttrib)((Msg__Msg)i2, "sym_string", 11, (Msg__StringPtr)i0);
    cpos = (i6+1);
    goto l431;
l38_loop:
    i0 = cstart;
    cpos = i0;
    i2 = (OOC_INT32)chars;
    sum = 0;
    i3=i0;i0=0;
l39_loop:
    i4 = _check_pointer(i2, 11018);
    i5 = OOC_ARRAY_LENGTH(i4, 0);
    i4 = *(OOC_UINT8*)(i4+(_check_index(i3, i5, OOC_UINT32, 11018)));
    i0 = i0+i4;
    sum = i0;
    i3 = i3+1;
    cpos = i3;
    i4 = _check_pointer(i2, 11091);
    i5 = OOC_ARRAY_LENGTH(i4, 0);
    i4 = *(OOC_UINT8*)(i4+(_check_index(i3, i5, OOC_UINT32, 11091)));
    i4 = (OOC_UINT8)65u<=(OOC_UINT8)(_cap(i4));
    if (i4) goto l42;
    i4=0u;
    goto l44;
l42:
    i4 = _check_pointer(i2, 11113);
    i5 = OOC_ARRAY_LENGTH(i4, 0);
    i4 = *(OOC_UINT8*)(i4+(_check_index(i3, i5, OOC_UINT32, 11113)));
    i4 = (OOC_UINT8)(_cap(i4))<=(OOC_UINT8)90u;
    
l44:
    if (i4) goto l50;
    i4 = _check_pointer(i2, 11165);
    i5 = OOC_ARRAY_LENGTH(i4, 0);
    i4 = *(OOC_UINT8*)(i4+(_check_index(i3, i5, OOC_UINT32, 11165)));
    i4 = (OOC_UINT8)48u<=(OOC_UINT8)i4;
    if (i4) goto l48;
    i4=0u;
    goto l52;
l48:
    i4 = _check_pointer(i2, 11181);
    i5 = OOC_ARRAY_LENGTH(i4, 0);
    i4 = *(OOC_UINT8*)(i4+(_check_index(i3, i5, OOC_UINT32, 11181)));
    i4 = (OOC_UINT8)i4<=(OOC_UINT8)57u;
    
    goto l52;
l50:
    i4=1u;
l52:
    if (i4) goto l54;
    i4 = _check_pointer(i2, 11225);
    i5 = OOC_ARRAY_LENGTH(i4, 0);
    i4 = *(OOC_UINT8*)(i4+(_check_index(i3, i5, OOC_UINT32, 11225)));
    i4 = i4==95u;
    
    goto l55;
l54:
    i4=1u;
l55:
    i4 = !i4;
    if (!i4) goto l39_loop;
l59:
    i0 = _check_pointer(i2, 11262);
    i2 = OOC_ARRAY_LENGTH(i0, 0);
    i0 = *(OOC_UINT8*)(i0+(_check_index(i3, i2, OOC_UINT32, 11262)));
    i0 = i0!=0u;
    if (i0) goto l62;
    i0 = OOC_Scanner__ScanInput_NextBlock();
    i0 = !i0;
    
    goto l64;
l62:
    i0=1u;
l64:
    if (!i0) goto l38_loop;
l67:
    sym = 45;
    goto l431;
  case 97u ... 122u:
  case 65u ... 90u:
l70_loop:
    i0 = scanOptions;
    i2 = cstart;
    cpos = i2;
    i0 = _in(0,i0);
    i3 = (OOC_INT32)chars;
    sum = 0;
    i4=i2;i2=0;
l71_loop:
    i5 = _check_pointer(i3, 11769);
    i6 = OOC_ARRAY_LENGTH(i5, 0);
    i5 = *(OOC_UINT8*)(i5+(_check_index(i4, i6, OOC_UINT32, 11769)));
    i2 = i2+i5;
    sum = i2;
    i4 = i4+1;
    cpos = i4;
    i5 = _check_pointer(i3, 11838);
    i6 = OOC_ARRAY_LENGTH(i5, 0);
    i5 = *(OOC_UINT8*)(i5+(_check_index(i4, i6, OOC_UINT32, 11838)));
    i5 = (OOC_UINT8)65u<=(OOC_UINT8)(_cap(i5));
    if (i5) goto l74;
    i5=0u;
    goto l76;
l74:
    i5 = _check_pointer(i3, 11860);
    i6 = OOC_ARRAY_LENGTH(i5, 0);
    i5 = *(OOC_UINT8*)(i5+(_check_index(i4, i6, OOC_UINT32, 11860)));
    i5 = (OOC_UINT8)(_cap(i5))<=(OOC_UINT8)90u;
    
l76:
    if (i5) goto l82;
    i5 = _check_pointer(i3, 11910);
    i6 = OOC_ARRAY_LENGTH(i5, 0);
    i5 = *(OOC_UINT8*)(i5+(_check_index(i4, i6, OOC_UINT32, 11910)));
    i5 = (OOC_UINT8)48u<=(OOC_UINT8)i5;
    if (i5) goto l80;
    i5=0u;
    goto l84;
l80:
    i5 = _check_pointer(i3, 11926);
    i6 = OOC_ARRAY_LENGTH(i5, 0);
    i5 = *(OOC_UINT8*)(i5+(_check_index(i4, i6, OOC_UINT32, 11926)));
    i5 = (OOC_UINT8)i5<=(OOC_UINT8)57u;
    
    goto l84;
l82:
    i5=1u;
l84:
    if (i5) goto l90;
    i5 = _check_pointer(i3, 11968);
    i6 = OOC_ARRAY_LENGTH(i5, 0);
    i5 = *(OOC_UINT8*)(i5+(_check_index(i4, i6, OOC_UINT32, 11968)));
    i5 = i5==95u;
    if (i5) goto l88;
    i5=0u;
    goto l91;
l88:
    i5=i0;
    goto l91;
l90:
    i5=1u;
l91:
    i5 = !i5;
    if (!i5) goto l71_loop;
l95:
    i0 = _check_pointer(i3, 12044);
    i2 = OOC_ARRAY_LENGTH(i0, 0);
    i0 = *(OOC_UINT8*)(i0+(_check_index(i4, i2, OOC_UINT32, 12044)));
    i0 = i0!=0u;
    if (i0) goto l98;
    i0 = OOC_Scanner__ScanInput_NextBlock();
    i0 = !i0;
    
    goto l100;
l98:
    i0=1u;
l100:
    if (!i0) goto l70_loop;
l103:
    i0 = sum;
    i0 = _mod(i0,256);
    sym = 45;
    i = i0;
    i2 = *(OOC_INT8*)(((OOC_INT32)OOC_Scanner__kwSym+(_check_index(i0, 256, OOC_UINT32, 12182))*2)+(_check_index(0, 2, OOC_UINT8, 12184)));
    i2 = i2>=0;
    if (!i2) goto l431;
    i2 = (OOC_INT32)*(OOC_INT32*)(((OOC_INT32)OOC_Scanner__kwStr+(_check_index(i0, 256, OOC_UINT32, 12270))*8)+(_check_index(0, 2, OOC_UINT8, 12272))*4);
    i3 = (OOC_INT32)*(OOC_INT32*)(((OOC_INT32)OOC_Scanner__kwStr+(_check_index(i0, 256, OOC_UINT32, 12270))*8)+(_check_index(0, 2, OOC_UINT8, 12272))*4);
    i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 12276)), 0);
    i4 = cstart;
    i2 = OOC_Scanner__ScanInput_CompareIdent(i4, (void*)(_check_pointer(i2, 12276)), i3);
    if (i2) goto l117;
    i2 = *(OOC_INT8*)(((OOC_INT32)OOC_Scanner__kwSym+(_check_index(i0, 256, OOC_UINT32, 12337))*2)+(_check_index(1, 2, OOC_UINT8, 12339)));
    i2 = i2>=0;
    if (i2) goto l111;
    i2=0u;
    goto l113;
l111:
    i2 = (OOC_INT32)*(OOC_INT32*)(((OOC_INT32)OOC_Scanner__kwStr+(_check_index(i0, 256, OOC_UINT32, 12379))*8)+(_check_index(1, 2, OOC_UINT8, 12381))*4);
    i3 = (OOC_INT32)*(OOC_INT32*)(((OOC_INT32)OOC_Scanner__kwStr+(_check_index(i0, 256, OOC_UINT32, 12379))*8)+(_check_index(1, 2, OOC_UINT8, 12381))*4);
    i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 12385)), 0);
    i2 = OOC_Scanner__ScanInput_CompareIdent(i4, (void*)(_check_pointer(i2, 12385)), i3);
    
l113:
    if (i2) goto l115;
    i0=45;
    goto l118;
l115:
    i0 = *(OOC_INT8*)(((OOC_INT32)OOC_Scanner__kwSym+(_check_index(i0, 256, OOC_UINT32, 12417))*2)+(_check_index(1, 2, OOC_UINT8, 12419)));
    sym = i0;
    
    goto l118;
l117:
    i0 = *(OOC_INT8*)(((OOC_INT32)OOC_Scanner__kwSym+(_check_index(i0, 256, OOC_UINT32, 12308))*2)+(_check_index(0, 2, OOC_UINT8, 12310)));
    sym = i0;
    
l118:
    i2 = i0>=66;
    if (i2) goto l121;
    i0=0u;
    goto l123;
l121:
    i0 = i0<70;
    
l123:
    if (i0) goto l125;
    i0=0u;
    goto l127;
l125:
    i0 = scanOptions;
    i0 = _in(5,i0);
    
l127:
    if (i0) goto l447;
    goto l431;
  case 48u ... 57u:
l132_loop:
    i0 = (OOC_INT32)chars;
    i2 = cstart;
    
l133_loop:
    i2 = i2+1;
    cpos = i2;
    i3 = _check_pointer(i0, 12982);
    i4 = OOC_ARRAY_LENGTH(i3, 0);
    i3 = *(OOC_UINT8*)(i3+(_check_index(i2, i4, OOC_UINT32, 12982)));
    i3 = (OOC_UINT8)48u<=(OOC_UINT8)i3;
    if (i3) goto l136;
    i3=0u;
    goto l138;
l136:
    i3 = _check_pointer(i0, 12998);
    i4 = OOC_ARRAY_LENGTH(i3, 0);
    i3 = *(OOC_UINT8*)(i3+(_check_index(i2, i4, OOC_UINT32, 12998)));
    i3 = (OOC_UINT8)i3<=(OOC_UINT8)57u;
    
l138:
    if (i3) goto l144;
    i3 = _check_pointer(i0, 13049);
    i4 = OOC_ARRAY_LENGTH(i3, 0);
    i3 = *(OOC_UINT8*)(i3+(_check_index(i2, i4, OOC_UINT32, 13049)));
    i3 = (OOC_UINT8)65u<=(OOC_UINT8)i3;
    if (i3) goto l142;
    i3=0u;
    goto l145;
l142:
    i3 = _check_pointer(i0, 13065);
    i4 = OOC_ARRAY_LENGTH(i3, 0);
    i3 = *(OOC_UINT8*)(i3+(_check_index(i2, i4, OOC_UINT32, 13065)));
    i3 = (OOC_UINT8)i3<=(OOC_UINT8)70u;
    
    goto l145;
l144:
    i3=1u;
l145:
    i3 = !i3;
    if (!i3) goto l133_loop;
l149:
    i0 = _check_pointer(i0, 13101);
    i3 = OOC_ARRAY_LENGTH(i0, 0);
    i0 = *(OOC_UINT8*)(i0+(_check_index(i2, i3, OOC_UINT32, 13101)));
    i0 = i0!=0u;
    if (i0) goto l152;
    i0 = OOC_Scanner__ScanInput_NextBlock();
    i0 = !i0;
    
    goto l154;
l152:
    i0=1u;
l154:
    if (!i0) goto l132_loop;
l157:
    i0 = (OOC_INT32)chars;
    i0 = _check_pointer(i0, 13176);
    i2 = OOC_ARRAY_LENGTH(i0, 0);
    i3 = cpos;
    i0 = *(OOC_UINT8*)(i0+(_check_index(i3, i2, OOC_UINT32, 13176)));
    i0 = i0==46u;
    if (i0) goto l160;
    i0=0u;
    goto l162;
l160:
    i0 = OOC_Scanner__ScanInput_LookaheadChar();
    i0 = i0!=46u;
    
l162:
    if (i0) goto l200;
    i0 = (OOC_INT32)chars;
    i2 = _check_pointer(i0, 14407);
    i3 = OOC_ARRAY_LENGTH(i2, 0);
    i4 = cpos;
    i2 = *(OOC_UINT8*)(i2+(_check_index(i4, i3, OOC_UINT32, 14407)));
    i2 = i2==72u;
    if (i2) goto l198;
    i2 = _check_pointer(i0, 14507);
    i3 = OOC_ARRAY_LENGTH(i2, 0);
    i2 = *(OOC_UINT8*)(i2+(_check_index(i4, i3, OOC_UINT32, 14507)));
    i2 = i2==88u;
    if (i2) goto l196;
    sym = 37;
    i2 = cstart;
    i = i2;
    i3 = i2!=i4;
    if (i3) goto l170;
    i3=0u;
    goto l172;
l170:
    i3 = _check_pointer(i0, 14761);
    i5 = OOC_ARRAY_LENGTH(i3, 0);
    i3 = *(OOC_UINT8*)(i3+(_check_index(i2, i5, OOC_UINT32, 14761)));
    i3 = (OOC_UINT8)48u<=(OOC_UINT8)i3;
    
l172:
    if (i3) goto l174;
    i3=0u;
    goto l176;
l174:
    i3 = _check_pointer(i0, 14774);
    i5 = OOC_ARRAY_LENGTH(i3, 0);
    i3 = *(OOC_UINT8*)(i3+(_check_index(i2, i5, OOC_UINT32, 14774)));
    i3 = (OOC_UINT8)i3<=(OOC_UINT8)57u;
    
l176:
    if (i3) goto l179_loop;
    i0=i2;
    goto l192;
l179_loop:
    i2 = i2+1;
    i = i2;
    i3 = i2!=i4;
    if (i3) goto l182;
    i3=0u;
    goto l184;
l182:
    i3 = _check_pointer(i0, 14761);
    i5 = OOC_ARRAY_LENGTH(i3, 0);
    i3 = *(OOC_UINT8*)(i3+(_check_index(i2, i5, OOC_UINT32, 14761)));
    i3 = (OOC_UINT8)48u<=(OOC_UINT8)i3;
    
l184:
    if (i3) goto l186;
    i3=0u;
    goto l188;
l186:
    i3 = _check_pointer(i0, 14774);
    i5 = OOC_ARRAY_LENGTH(i3, 0);
    i3 = *(OOC_UINT8*)(i3+(_check_index(i2, i5, OOC_UINT32, 14774)));
    i3 = (OOC_UINT8)i3<=(OOC_UINT8)57u;
    
l188:
    if (i3) goto l179_loop;
l191:
    i0=i2;
l192:
    i2 = i0!=i4;
    if (!i2) goto l431;
    OOC_Scanner__ScanInput_ErrPos(7, i0);
    goto l431;
l196:
    sym = 39;
    cpos = (i4+1);
    goto l431;
l198:
    sym = 38;
    cpos = (i4+1);
    goto l431;
l200:
    i0 = cpos;
    sym = 40;
    cpos = (i0+1);
l201_loop:
    i0 = (OOC_INT32)chars;
    i2 = _check_pointer(i0, 13434);
    i3 = OOC_ARRAY_LENGTH(i2, 0);
    i4 = cpos;
    i2 = *(OOC_UINT8*)(i2+(_check_index(i4, i3, OOC_UINT32, 13434)));
    i2 = (OOC_UINT8)48u<=(OOC_UINT8)i2;
    if (i2) goto l204;
    i2=0u;
    goto l206;
l204:
    i2 = _check_pointer(i0, 13450);
    i3 = OOC_ARRAY_LENGTH(i2, 0);
    i2 = *(OOC_UINT8*)(i2+(_check_index(i4, i3, OOC_UINT32, 13450)));
    i2 = (OOC_UINT8)i2<=(OOC_UINT8)57u;
    
l206:
    if (!i2) goto l216;
l207_loop:
    i2 = cpos;
    i2 = i2+1;
    cpos = i2;
    i3 = _check_pointer(i0, 13434);
    i4 = OOC_ARRAY_LENGTH(i3, 0);
    i3 = *(OOC_UINT8*)(i3+(_check_index(i2, i4, OOC_UINT32, 13434)));
    i3 = (OOC_UINT8)48u<=(OOC_UINT8)i3;
    if (i3) goto l210;
    i2=0u;
    goto l212;
l210:
    i3 = _check_pointer(i0, 13450);
    i4 = OOC_ARRAY_LENGTH(i3, 0);
    i2 = *(OOC_UINT8*)(i3+(_check_index(i2, i4, OOC_UINT32, 13450)));
    i2 = (OOC_UINT8)i2<=(OOC_UINT8)57u;
    
l212:
    if (i2) goto l207_loop;
l216:
    i0 = _check_pointer(i0, 13531);
    i2 = OOC_ARRAY_LENGTH(i0, 0);
    i3 = cpos;
    i0 = *(OOC_UINT8*)(i0+(_check_index(i3, i2, OOC_UINT32, 13531)));
    i0 = i0!=0u;
    if (i0) goto l219;
    i0 = OOC_Scanner__ScanInput_NextBlock();
    i0 = !i0;
    
    goto l221;
l219:
    i0=1u;
l221:
    if (!i0) goto l201_loop;
l224:
    i0 = (OOC_INT32)chars;
    i2 = _check_pointer(i0, 13599);
    i3 = OOC_ARRAY_LENGTH(i2, 0);
    i4 = cpos;
    i2 = *(OOC_UINT8*)(i2+(_check_index(i4, i3, OOC_UINT32, 13599)));
    i2 = i2==69u;
    if (i2) goto l227;
    i2 = _check_pointer(i0, 13622);
    i3 = OOC_ARRAY_LENGTH(i2, 0);
    i2 = *(OOC_UINT8*)(i2+(_check_index(i4, i3, OOC_UINT32, 13622)));
    i2 = i2==68u;
    
    goto l229;
l227:
    i2=1u;
l229:
    if (!i2) goto l431;
    i0 = _check_pointer(i0, 13662);
    i2 = OOC_ARRAY_LENGTH(i0, 0);
    i0 = *(OOC_UINT8*)(i0+(_check_index(i4, i2, OOC_UINT32, 13662)));
    i0 = i0==68u;
    if (!i0) goto l233;
    sym = 41;
l233:
    OOC_Scanner__ScanInput_Lookahead(2);
    i0 = cpos;
    i0 = i0+1;
    cpos = i0;
    i2 = (OOC_INT32)chars;
    i3 = _check_pointer(i2, 13858);
    i4 = OOC_ARRAY_LENGTH(i3, 0);
    i3 = *(OOC_UINT8*)(i3+(_check_index(i0, i4, OOC_UINT32, 13858)));
    i3 = i3==45u;
    if (i3) goto l236;
    i3 = _check_pointer(i2, 13881);
    i4 = OOC_ARRAY_LENGTH(i3, 0);
    i3 = *(OOC_UINT8*)(i3+(_check_index(i0, i4, OOC_UINT32, 13881)));
    i3 = i3==43u;
    
    goto l238;
l236:
    i3=1u;
l238:
    if (!i3) goto l241;
    i0 = i0+1;
    cpos = i0;
    
l241:
    i3 = _check_pointer(i2, 13970);
    i4 = OOC_ARRAY_LENGTH(i3, 0);
    i3 = *(OOC_UINT8*)(i3+(_check_index(i0, i4, OOC_UINT32, 13970)));
    i3 = (OOC_UINT8)48u<=(OOC_UINT8)i3;
    if (i3) goto l244;
    i2=0u;
    goto l246;
l244:
    i2 = _check_pointer(i2, 13986);
    i3 = OOC_ARRAY_LENGTH(i2, 0);
    i2 = *(OOC_UINT8*)(i2+(_check_index(i0, i3, OOC_UINT32, 13986)));
    i2 = (OOC_UINT8)i2<=(OOC_UINT8)57u;
    
l246:
    if (i2) goto l248_loop;
    OOC_Scanner__ScanInput_ErrPos(6, i0);
    goto l431;
l248_loop:
    i0 = (OOC_INT32)chars;
    i2 = _check_pointer(i0, 14062);
    i3 = OOC_ARRAY_LENGTH(i2, 0);
    i4 = cpos;
    i2 = *(OOC_UINT8*)(i2+(_check_index(i4, i3, OOC_UINT32, 14062)));
    i2 = (OOC_UINT8)48u<=(OOC_UINT8)i2;
    if (i2) goto l251;
    i2=0u;
    goto l253;
l251:
    i2 = _check_pointer(i0, 14078);
    i3 = OOC_ARRAY_LENGTH(i2, 0);
    i2 = *(OOC_UINT8*)(i2+(_check_index(i4, i3, OOC_UINT32, 14078)));
    i2 = (OOC_UINT8)i2<=(OOC_UINT8)57u;
    
l253:
    if (!i2) goto l263;
l254_loop:
    i2 = cpos;
    i2 = i2+1;
    cpos = i2;
    i3 = _check_pointer(i0, 14062);
    i4 = OOC_ARRAY_LENGTH(i3, 0);
    i3 = *(OOC_UINT8*)(i3+(_check_index(i2, i4, OOC_UINT32, 14062)));
    i3 = (OOC_UINT8)48u<=(OOC_UINT8)i3;
    if (i3) goto l257;
    i2=0u;
    goto l259;
l257:
    i3 = _check_pointer(i0, 14078);
    i4 = OOC_ARRAY_LENGTH(i3, 0);
    i2 = *(OOC_UINT8*)(i3+(_check_index(i2, i4, OOC_UINT32, 14078)));
    i2 = (OOC_UINT8)i2<=(OOC_UINT8)57u;
    
l259:
    if (i2) goto l254_loop;
l263:
    i0 = _check_pointer(i0, 14171);
    i2 = OOC_ARRAY_LENGTH(i0, 0);
    i3 = cpos;
    i0 = *(OOC_UINT8*)(i0+(_check_index(i3, i2, OOC_UINT32, 14171)));
    i0 = i0!=0u;
    if (i0) goto l266;
    i0 = OOC_Scanner__ScanInput_NextBlock();
    i0 = !i0;
    
    goto l268;
l266:
    i0=1u;
l268:
    if (!i0) goto l248_loop;
    goto l431;
  case 34u:
  case 39u:
    i2 = _check_pointer(i2, 15023);
    i3 = OOC_ARRAY_LENGTH(i2, 0);
    i0 = *(OOC_UINT8*)(i2+(_check_index(i0, i3, OOC_UINT32, 15023)));
    i0 = i0==34u;
    if (i0) goto l278;
    sym = 43;
    
    goto l280_loop;
l278:
    sym = 44;
    
l280_loop:
    i0 = (OOC_INT32)chars;
    i2 = cstart;
    i3=i2;
l281_loop:
    i3 = i3+1;
    cpos = i3;
    i4 = _check_pointer(i0, 15343);
    i5 = OOC_ARRAY_LENGTH(i4, 0);
    i4 = *(OOC_UINT8*)(i4+(_check_index(i3, i5, OOC_UINT32, 15343)));
    i4 = (OOC_UINT8)i4<(OOC_UINT8)32u;
    if (i4) goto l284;
    i4 = _check_pointer(i0, 15366);
    i5 = OOC_ARRAY_LENGTH(i4, 0);
    i6 = _check_pointer(i0, 15380);
    i7 = OOC_ARRAY_LENGTH(i6, 0);
    i4 = *(OOC_UINT8*)(i4+(_check_index(i3, i5, OOC_UINT32, 15366)));
    i5 = *(OOC_UINT8*)(i6+(_check_index(i2, i7, OOC_UINT32, 15380)));
    i4 = i4==i5;
    
    goto l286;
l284:
    i4=1u;
l286:
    if (!i4) goto l281_loop;
l289:
    i0 = _check_pointer(i0, 15410);
    i2 = OOC_ARRAY_LENGTH(i0, 0);
    i0 = *(OOC_UINT8*)(i0+(_check_index(i3, i2, OOC_UINT32, 15410)));
    i0 = i0!=0u;
    if (i0) goto l292;
    i0 = OOC_Scanner__ScanInput_NextBlock();
    i0 = !i0;
    
    goto l294;
l292:
    i0=1u;
l294:
    if (!i0) goto l280_loop;
l297:
    i0 = (OOC_INT32)chars;
    i2 = _check_pointer(i0, 15485);
    i3 = OOC_ARRAY_LENGTH(i2, 0);
    i4 = cpos;
    i5 = _check_pointer(i0, 15499);
    i6 = OOC_ARRAY_LENGTH(i5, 0);
    i7 = cstart;
    i2 = *(OOC_UINT8*)(i2+(_check_index(i4, i3, OOC_UINT32, 15485)));
    i3 = *(OOC_UINT8*)(i5+(_check_index(i7, i6, OOC_UINT32, 15499)));
    i2 = i2!=i3;
    if (i2) goto l300;
    cpos = (i4+1);
    goto l431;
l300:
    i2 = _check_pointer(i0, 15533);
    i3 = OOC_ARRAY_LENGTH(i2, 0);
    i2 = *(OOC_UINT8*)(i2+(_check_index(i4, i3, OOC_UINT32, 15533)));
    i2 = i2==10u;
    if (i2) goto l303;
    i0 = _check_pointer(i0, 15561);
    i2 = OOC_ARRAY_LENGTH(i0, 0);
    i0 = *(OOC_UINT8*)(i0+(_check_index(i4, i2, OOC_UINT32, 15561)));
    i0 = i0==13u;
    
    goto l305;
l303:
    i0=1u;
l305:
    if (i0) goto l307;
    OOC_Scanner__ScanInput_ErrPos(2, i4);
    i0 = (OOC_INT32)chars;
    i0 = _check_pointer(i0, 15716);
    i2 = OOC_ARRAY_LENGTH(i0, 0);
    i3 = cpos;
    i0 = *(OOC_UINT8*)(i0+(_check_index(i3, i2, OOC_UINT32, 15716)));
    OOC_Scanner__ScanInput_SetCharAttrib(i0);
    goto l431;
l307:
    OOC_Scanner__ScanInput_Err(3);
    goto l431;
  case 126u:
    sym = 35;
    cpos = (i0+1);
    goto l431;
  case 123u:
    sym = 34;
    cpos = (i0+1);
    goto l431;
  case 46u:
    OOC_Scanner__ScanInput_Lookahead(2);
    i0 = cpos;
    i0 = i0+1;
    cpos = i0;
    i2 = (OOC_INT32)chars;
    i3 = _check_pointer(i2, 15964);
    i4 = OOC_ARRAY_LENGTH(i3, 0);
    i3 = *(OOC_UINT8*)(i3+(_check_index(i0, i4, OOC_UINT32, 15964)));
    i3 = i3==46u;
    if (i3) goto l315;
    sym = 18;
    
    goto l431;
l315:
    i0 = i0+1;
    sym = 21;
    cpos = i0;
    i2 = _check_pointer(i2, 16056);
    i3 = OOC_ARRAY_LENGTH(i2, 0);
    i2 = *(OOC_UINT8*)(i2+(_check_index(i0, i3, OOC_UINT32, 16056)));
    i2 = i2==46u;
    if (i2) goto l318;
    i2=0u;
    goto l320;
l318:
    i2 = scanOptions;
    i2 = _in(1,i2);
    
l320:
    if (!i2) goto l431;
    sym = 76;
    cpos = (i0+1);
    
    goto l431;
  case 94u:
    sym = 17;
    cpos = (i0+1);
    goto l431;
  case 91u:
    sym = 33;
    cpos = (i0+1);
    goto l431;
  case 58u:
    OOC_Scanner__ScanInput_Lookahead(1);
    i0 = cpos;
    i0 = i0+1;
    cpos = i0;
    i2 = (OOC_INT32)chars;
    i2 = _check_pointer(i2, 16422);
    i3 = OOC_ARRAY_LENGTH(i2, 0);
    i2 = *(OOC_UINT8*)(i2+(_check_index(i0, i3, OOC_UINT32, 16422)));
    i2 = i2==61u;
    if (i2) goto l330;
    sym = 20;
    
    goto l431;
l330:
    sym = 36;
    cpos = (i0+1);
    
    goto l431;
  case 40u:
    OOC_Scanner__ScanInput_Lookahead(1);
    i0 = cpos;
    i0 = i0+1;
    cpos = i0;
    i2 = (OOC_INT32)chars;
    i3 = _check_pointer(i2, 16616);
    i4 = OOC_ARRAY_LENGTH(i3, 0);
    i3 = *(OOC_UINT8*)(i3+(_check_index(i0, i4, OOC_UINT32, 16616)));
    i3 = i3==42u;
    if (i3) goto l335;
    sym = 32;
    goto l431;
l335:
    i3 = _check_pointer(i2, 16693);
    i4 = OOC_ARRAY_LENGTH(i3, 0);
    i3 = *(OOC_UINT8*)(i3+(_check_index((i0+1), i4, OOC_UINT32, 16693)));
    i3 = i3==42u;
    if (i3) goto l338;
    i0=0u;
    goto l340;
l338:
    i2 = _check_pointer(i2, 16717);
    i3 = OOC_ARRAY_LENGTH(i2, 0);
    i0 = *(OOC_UINT8*)(i2+(_check_index((i0+2), i3, OOC_UINT32, 16717)));
    i0 = i0!=41u;
    
l340:
    if (i0) goto l342;
    sym = 77;
    goto l343;
l342:
    sym = 78;
l343:
    sum = 1;
l344_loop:
    i0 = (OOC_INT32)chars;
    i2 = _check_pointer(i0, 16896);
    i3 = OOC_ARRAY_LENGTH(i2, 0);
    i4 = cpos;
    i2 = *(OOC_UINT8*)(i2+(_check_index(i4, i3, OOC_UINT32, 16896)));
    switch (i2) {
    case 0u:
      i0 = (OOC_INT32)b;
      i0 = OOC_Scanner_InputBuffer__BufferDesc_EndOfBuffer((OOC_Scanner_InputBuffer__Buffer)i0, i4);
      if (i0) goto l349;
      cpos = (i4+1);
      goto l344_loop;
l349:
      i0 = OOC_Scanner__ScanInput_NextBlock();
      i0 = !i0;
      if (!i0) goto l344_loop;
      goto l378;
    case 10u:
      OOC_Scanner__ScanInput_EndOfLine(1);
      goto l344_loop;
    case 13u:
      i0 = _check_pointer(i0, 17269);
      i2 = OOC_ARRAY_LENGTH(i0, 0);
      i0 = *(OOC_UINT8*)(i0+(_check_index((i4+1), i2, OOC_UINT32, 17269)));
      i0 = i0==0u;
      if (!i0) goto l358;
      i0 = OOC_Scanner__ScanInput_NextBlock();
      dummy = i0;
l358:
      i0 = (OOC_INT32)chars;
      i0 = _check_pointer(i0, 17430);
      i2 = cpos;
      i3 = OOC_ARRAY_LENGTH(i0, 0);
      i0 = *(OOC_UINT8*)(i0+(_check_index((i2+1), i3, OOC_UINT32, 17430)));
      i0 = i0==10u;
      if (!i0) goto l360;
      goto l361;
l360:
      OOC_Scanner__ScanInput_EndOfLine(1);
      goto l344_loop;
l361:
      OOC_Scanner__ScanInput_EndOfLine(2);
      goto l344_loop;
    case 9u:
      i0 = currLinePos;
      i2 = currLineTab;
      i0 = (i4-i0)+i2;
      currColumn = i0;
      currLineTab = (i2+((8-(_mod(i0,8)))-1));
      cpos = (i4+1);
      goto l344_loop;
    case 42u:
      OOC_Scanner__ScanInput_Lookahead(1);
      i0 = cpos;
      i0 = i0+1;
      cpos = i0;
      i2 = (OOC_INT32)chars;
      i2 = _check_pointer(i2, 17865);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i2 = *(OOC_UINT8*)(i2+(_check_index(i0, i3, OOC_UINT32, 17865)));
      i2 = i2==41u;
      if (!i2) goto l344_loop;
      i2 = sum;
      cpos = (i0+1);
      i0 = i2-1;
      sum = i0;
      i0 = i0==0;
      if (!i0) goto l344_loop;
      goto l378;
    case 40u:
      OOC_Scanner__ScanInput_Lookahead(1);
      i0 = cpos;
      i0 = i0+1;
      cpos = i0;
      i2 = (OOC_INT32)chars;
      i2 = _check_pointer(i2, 18118);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i0 = *(OOC_UINT8*)(i2+(_check_index(i0, i3, OOC_UINT32, 18118)));
      i0 = i0==42u;
      if (!i0) goto l344_loop;
      i0 = sum;
      sum = (i0+1);
      goto l344_loop;
    default:
      cpos = (i4+1);
      goto l344_loop;
    }
l378:
    i0 = sum;
    i0 = i0!=0;
    if (!i0) goto l431;
    OOC_Scanner__ScanInput_Err(1);
    goto l431;
  case 42u:
    OOC_Scanner__ScanInput_Lookahead(1);
    i0 = cpos;
    i0 = i0+1;
    cpos = i0;
    i2 = (OOC_INT32)chars;
    i3 = _check_pointer(i2, 18495);
    i4 = OOC_ARRAY_LENGTH(i3, 0);
    i3 = *(OOC_UINT8*)(i3+(_check_index(i0, i4, OOC_UINT32, 18495)));
    i3 = i3==41u;
    if (i3) goto l398;
    i2 = _check_pointer(i2, 18589);
    i3 = OOC_ARRAY_LENGTH(i2, 0);
    i0 = *(OOC_UINT8*)(i2+(_check_index(i0, i3, OOC_UINT32, 18589)));
    i0 = i0==62u;
    if (i0) goto l388;
    i0=0u;
    goto l390;
l388:
    i0 = scanOptions;
    i0 = _in(2,i0);
    
l390:
    if (i0) goto l392;
    sym = 1;
    
    goto l431;
l392:
    i0 = inputMode;
    i0 = i0!=1;
    if (i0) goto l395;
    sym = 75;
    goto l396;
l395:
    OOC_Scanner__ScanInput_Err(8);
l396:
    i0 = cpos;
    cpos = (i0+1);
    
    goto l431;
l398:
    OOC_Scanner__ScanInput_Err(4);
    i0 = cpos;
    cpos = (i0+1);
    
    goto l431;
  case 47u:
    sym = 2;
    cpos = (i0+1);
    goto l431;
  case 38u:
    sym = 5;
    cpos = (i0+1);
    goto l431;
  case 43u:
    sym = 6;
    cpos = (i0+1);
    goto l431;
  case 45u:
    sym = 7;
    cpos = (i0+1);
    goto l431;
  case 61u:
    sym = 9;
    cpos = (i0+1);
    goto l431;
  case 35u:
    sym = 10;
    cpos = (i0+1);
    goto l431;
  case 60u:
    OOC_Scanner__ScanInput_Lookahead(1);
    i0 = cpos;
    i0 = i0+1;
    cpos = i0;
    i2 = (OOC_INT32)chars;
    i3 = _check_pointer(i2, 19259);
    i4 = OOC_ARRAY_LENGTH(i3, 0);
    i3 = *(OOC_UINT8*)(i3+(_check_index(i0, i4, OOC_UINT32, 19259)));
    i3 = i3==61u;
    if (i3) goto l417;
    i2 = _check_pointer(i2, 19339);
    i3 = OOC_ARRAY_LENGTH(i2, 0);
    i2 = *(OOC_UINT8*)(i2+(_check_index(i0, i3, OOC_UINT32, 19339)));
    i2 = i2==42u;
    if (i2) goto l411;
    i2=0u;
    goto l413;
l411:
    i2 = scanOptions;
    i2 = _in(2,i2);
    
l413:
    if (i2) goto l415;
    sym = 11;
    
    goto l431;
l415:
    sym = 74;
    cpos = (i0+1);
    
    goto l431;
l417:
    sym = 12;
    cpos = (i0+1);
    
    goto l431;
  case 62u:
    OOC_Scanner__ScanInput_Lookahead(1);
    i0 = cpos;
    i0 = i0+1;
    cpos = i0;
    i2 = (OOC_INT32)chars;
    i2 = _check_pointer(i2, 19584);
    i3 = OOC_ARRAY_LENGTH(i2, 0);
    i2 = *(OOC_UINT8*)(i2+(_check_index(i0, i3, OOC_UINT32, 19584)));
    i2 = i2==61u;
    if (i2) goto l422;
    sym = 13;
    
    goto l431;
l422:
    sym = 14;
    cpos = (i0+1);
    
    goto l431;
  case 125u:
    sym = 24;
    cpos = (i0+1);
    goto l431;
  case 41u:
    sym = 22;
    cpos = (i0+1);
    goto l431;
  case 93u:
    sym = 23;
    cpos = (i0+1);
    goto l431;
  case 124u:
    sym = 47;
    cpos = (i0+1);
    goto l431;
  case 59u:
    sym = 46;
    cpos = (i0+1);
    goto l431;
  case 44u:
    sym = 19;
    cpos = (i0+1);
    goto l431;
  default:
    OOC_Scanner__ScanInput_Err(5);
    i0 = (OOC_INT32)RT0__NewObject(_td_Msg__StringPtr.baseTypes[0], 2);
    strPtr = (Msg__StringPtr)i0;
    i2 = _check_pointer(i0, 20099);
    i3 = OOC_ARRAY_LENGTH(i2, 0);
    i4 = (OOC_INT32)chars;
    i4 = _check_pointer(i4, 20111);
    i5 = OOC_ARRAY_LENGTH(i4, 0);
    i6 = cpos;
    i4 = *(OOC_UINT8*)(i4+(_check_index(i6, i5, OOC_UINT32, 20111)));
    *(OOC_UINT8*)(i2+(_check_index(0, i3, OOC_UINT8, 20099))) = i4;
    i2 = _check_pointer(i0, 20125);
    i3 = OOC_ARRAY_LENGTH(i2, 0);
    *(OOC_UINT8*)(i2+(_check_index(1, i3, OOC_UINT8, 20125))) = 0u;
    i2 = (OOC_INT32)lastError;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 20153)))), Msg__MsgDesc_SetStringAttrib)),Msg__MsgDesc_SetStringAttrib)((Msg__Msg)i2, "sym_string", 11, (Msg__StringPtr)i0);
    cpos = (i6+1);
    goto l431;
  }
l431:
  i0 = sym;
  i2 = i0==74;
  if (i2) goto l434;
  i2=0u;
  goto l436;
l434:
  i2 = scanOptions;
  i2 = _in(3,i2);
  
l436:
  if (!i2) goto l437;
  goto l445;
l437:
  i2 = inputMode;
  i3 = i2==2;
  if (i3) goto l1_loop;
  i2 = i2==0;
  if (!i2) goto l441;
  goto l442;
l441:
  i2 = startColumn;
  i3 = startLine;
  i4 = cpos;
  i5 = cstart;
  OOC_Scanner_Pragma__AddSymbol((void*)(OOC_INT32)&pragma, (RT0__Struct)i1, (void*)(OOC_INT32)&inputMode, i0, i5, i4, i3, i2);
  goto l1_loop;
l442:
  i2 = (OOC_INT32)b;
  i3 = cpos;
  *(OOC_INT32*)((_check_pointer(i2, 20783))+16) = i3;
  i2 = (OOC_INT32)builder;
  i4 = startColumn;
  i5 = startLine;
  i6 = cstart;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 20830)))), OOC_Scanner_SymList__BuilderDesc_AddSymbol)),OOC_Scanner_SymList__BuilderDesc_AddSymbol)((OOC_Scanner_SymList__Builder)i2, i0, i6, i3, i5, i4);
  goto l1_loop;
l445:
  i2 = startColumn;
  i3 = startLine;
  i4 = cpos;
  i5 = cstart;
  OOC_Scanner_Pragma__AddSymbol((void*)(OOC_INT32)&pragma, (RT0__Struct)i1, (void*)(OOC_INT32)&inputMode, i0, i5, i4, i3, i2);
  goto l1_loop;
l447:
  i0 = scanOptions;
  i2 = (OOC_INT32)builder;
  i3 = _in(3,i0);
  if (i3) goto l450;
  i1 = currLinePos;
  i3 = cpos;
  i4 = currLineTab;
  i5 = currLine;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 21539)))), OOC_Scanner_SymList__BuilderDesc_AddSymbol)),OOC_Scanner_SymList__BuilderDesc_AddSymbol)((OOC_Scanner_SymList__Builder)i2, 72, i3, i3, i5, ((i3-i1)+i4));
  goto l451;
l450:
  i3 = currLinePos;
  i4 = cpos;
  i5 = currLineTab;
  i6 = currLine;
  OOC_Scanner_Pragma__AddSymbol((void*)(OOC_INT32)&pragma, (RT0__Struct)i1, (void*)(OOC_INT32)&inputMode, 72, i4, i4, i6, ((i4-i3)+i5));
l451:
  i1 = (OOC_INT32)*(OOC_INT32*)((OOC_INT32)&pragma+36);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 21668)))), OOC_Scanner_SymList__BuilderDesc_SetPragmaHistory)),OOC_Scanner_SymList__BuilderDesc_SetPragmaHistory)((OOC_Scanner_SymList__Builder)i2, (OOC_Config_Pragmas__History)i1);
  i0 = _in(4,i0);
  if (i0) goto l454;
  i0=0u;
  goto l456;
l454:
  i0 = eolIsCRLF;
  
l456:
  if (!i0) goto l458;
  i0 = (OOC_INT32)b;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21787))+20);
  OOC_Error__ListDesc_SetAdjustCharPos((OOC_Error__List)i0, 1u);
l458:
  return;
  ;
}

static void OOC_Scanner__InitKeywords(void) {
  register OOC_INT32 i0,i1;
  OOC_INT32 i;
  auto void OOC_Scanner__InitKeywords_KW(const OOC_CHAR8 ident__ref[], OOC_LEN ident_0d, OOC_INT8 sym);
    
    void OOC_Scanner__InitKeywords_KW(const OOC_CHAR8 ident__ref[], OOC_LEN ident_0d, OOC_INT8 sym) {
      register OOC_INT32 i0,i1,i2;
      OOC_ALLOCATE_VPAR(ident,OOC_CHAR8 ,ident_0d)
      OOC_INT16 sum;
      OOC_INT16 i;
      OOC_INT16 j;
      OOC_Scanner_InputBuffer__CharArray str;

      OOC_INITIALIZE_VPAR(ident__ref,ident,OOC_CHAR8 ,ident_0d)
      sum = 0;
      i = 0;
      i0 = *(OOC_UINT8*)((OOC_INT32)ident+(_check_index(0, ident_0d, OOC_UINT16, 22164)));
      i0 = i0!=0u;
      if (i0) goto l3;
      i0=0;i1=0;
      goto l9;
l3:
      i0=0;i1=0;
l4_loop:
      i2 = *(OOC_UINT8*)((OOC_INT32)ident+(_check_index(i1, ident_0d, OOC_UINT16, 22205)));
      i0 = i0+i2;
      sum = i0;
      i1 = i1+1;
      i = i1;
      i2 = *(OOC_UINT8*)((OOC_INT32)ident+(_check_index(i1, ident_0d, OOC_UINT16, 22164)));
      i2 = i2!=0u;
      if (i2) goto l4_loop;
l9:
      i0 = _mod(i0,256);
      j = i0;
      i1 = (OOC_INT32)RT0__NewObject(_td_OOC_Scanner_InputBuffer__CharArray.baseTypes[0], (i1+1));
      str = (OOC_Scanner_InputBuffer__CharArray)i1;
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i1, 22307)), 0);
      _copy_8((const void*)(OOC_INT32)ident,(void*)(_check_pointer(i1, 22307)),i2);
      i2 = *(OOC_INT8*)(((OOC_INT32)OOC_Scanner__kwSym+(_check_index(i0, 256, OOC_UINT16, 22326))*2)+(_check_index(0, 2, OOC_UINT8, 22328)));
      i2 = i2<0;
      if (i2) goto l12;
      i2 = sym;
      *(OOC_INT8*)(((OOC_INT32)OOC_Scanner__kwSym+(_check_index(i0, 256, OOC_UINT16, 22422))*2)+(_check_index(1, 2, OOC_UINT8, 22424))) = i2;
      *(OOC_INT32*)(((OOC_INT32)OOC_Scanner__kwStr+(_check_index(i0, 256, OOC_UINT16, 22450))*8)+(_check_index(1, 2, OOC_UINT8, 22452))*4) = i1;
      goto l13;
l12:
      i2 = sym;
      *(OOC_INT8*)(((OOC_INT32)OOC_Scanner__kwSym+(_check_index(i0, 256, OOC_UINT16, 22356))*2)+(_check_index(0, 2, OOC_UINT8, 22358))) = i2;
      *(OOC_INT32*)(((OOC_INT32)OOC_Scanner__kwStr+(_check_index(i0, 256, OOC_UINT16, 22384))*8)+(_check_index(0, 2, OOC_UINT8, 22386))*4) = i1;
l13:
      return;
      ;
    }


  i = 0;
  i0=0;
l1_loop:
  *(OOC_INT8*)(((OOC_INT32)OOC_Scanner__kwSym+(_check_index(i0, 256, OOC_UINT32, 22541))*2)+(_check_index(0, 2, OOC_UINT8, 22543))) = (-1);
  *(OOC_INT8*)(((OOC_INT32)OOC_Scanner__kwSym+(_check_index(i0, 256, OOC_UINT32, 22560))*2)+(_check_index(1, 2, OOC_UINT8, 22562))) = (-1);
  *(OOC_INT32*)(((OOC_INT32)OOC_Scanner__kwStr+(_check_index(i0, 256, OOC_UINT32, 22585))*8)+(_check_index(0, 2, OOC_UINT8, 22587))*4) = (OOC_INT32)0;
  *(OOC_INT32*)(((OOC_INT32)OOC_Scanner__kwStr+(_check_index(i0, 256, OOC_UINT32, 22605))*8)+(_check_index(1, 2, OOC_UINT8, 22607))*4) = (OOC_INT32)0;
  i0 = i0+1;
  i = i0;
  i1 = i0<=255;
  if (i1) goto l1_loop;
l5:
  OOC_Scanner__InitKeywords_KW("ARRAY", 6, 62);
  OOC_Scanner__InitKeywords_KW("BEGIN", 6, 65);
  OOC_Scanner__InitKeywords_KW("BY", 3, 31);
  OOC_Scanner__InitKeywords_KW("CASE", 5, 53);
  OOC_Scanner__InitKeywords_KW("CONST", 6, 66);
  OOC_Scanner__InitKeywords_KW("DIV", 4, 3);
  OOC_Scanner__InitKeywords_KW("DO", 3, 29);
  OOC_Scanner__InitKeywords_KW("ELSE", 5, 49);
  OOC_Scanner__InitKeywords_KW("ELSIF", 6, 50);
  OOC_Scanner__InitKeywords_KW("END", 4, 48);
  OOC_Scanner__InitKeywords_KW("EXIT", 5, 60);
  OOC_Scanner__InitKeywords_KW("FOR", 4, 57);
  OOC_Scanner__InitKeywords_KW("IF", 3, 52);
  OOC_Scanner__InitKeywords_KW("IMPORT", 7, 70);
  OOC_Scanner__InitKeywords_KW("IN", 3, 15);
  OOC_Scanner__InitKeywords_KW("IS", 3, 16);
  OOC_Scanner__InitKeywords_KW("LOOP", 5, 56);
  OOC_Scanner__InitKeywords_KW("MOD", 4, 4);
  OOC_Scanner__InitKeywords_KW("MODULE", 7, 71);
  OOC_Scanner__InitKeywords_KW("NIL", 4, 42);
  OOC_Scanner__InitKeywords_KW("OF", 3, 25);
  OOC_Scanner__InitKeywords_KW("OR", 3, 8);
  OOC_Scanner__InitKeywords_KW("POINTER", 8, 64);
  OOC_Scanner__InitKeywords_KW("PROCEDURE", 10, 69);
  OOC_Scanner__InitKeywords_KW("RECORD", 7, 63);
  OOC_Scanner__InitKeywords_KW("REPEAT", 7, 55);
  OOC_Scanner__InitKeywords_KW("RETURN", 7, 61);
  OOC_Scanner__InitKeywords_KW("THEN", 5, 28);
  OOC_Scanner__InitKeywords_KW("TO", 3, 30);
  OOC_Scanner__InitKeywords_KW("TYPE", 5, 67);
  OOC_Scanner__InitKeywords_KW("UNTIL", 6, 51);
  OOC_Scanner__InitKeywords_KW("VAR", 4, 68);
  OOC_Scanner__InitKeywords_KW("WHILE", 6, 54);
  OOC_Scanner__InitKeywords_KW("WITH", 5, 58);
  OOC_Scanner__InitKeywords_KW("TRY", 4, 59);
  OOC_Scanner__InitKeywords_KW("CATCH", 6, 26);
  OOC_Scanner__InitKeywords_KW("RAISES", 7, 27);
  return;
  ;
}

void OOC_OOC_Scanner_init(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Scanner__ErrorContext.baseTypes[0]);
  OOC_Scanner__scannerContext = (OOC_Scanner__ErrorContext)i0;
  OOC_Error__InitContext((OOC_Error__Context)i0, "OOC:Scanner", 12);
  OOC_Scanner__InitKeywords();
  return;
  ;
}

/* --- */
