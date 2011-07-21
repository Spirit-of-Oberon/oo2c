#include <OOC/Doc/ResolveRef.d>
#include <__oo2c.h>
#include <setjmp.h>

void OOC_Doc_ResolveRef__ErrorContextDesc_GetTemplate(OOC_Doc_ResolveRef__ErrorContext context, Msg__Msg msg, Msg__LString templ, OOC_LEN templ_0d) {
  register OOC_INT32 i0,i1;
  OOC_CHAR16 t[128];

  i0 = (OOC_INT32)msg;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 1702))+8);
  switch (i1) {
  case 0:
    _copy_16((const void*)((OOC_CHAR16[]){82,101,102,101,114,101,110,99,101,32,99,111,109,109,97,110,100,32,105,115,32,101,109,112,116,121,0}),(void*)(OOC_INT32)t,128);
    goto l18;
  case 1:
    _copy_16((const void*)((OOC_CHAR16[]){82,101,102,101,114,101,110,99,101,32,99,111,109,109,97,110,100,32,99,111,110,116,97,105,110,115,32,109,97,114,107,117,112,32,99,111,109,109,97,110,100,115,0}),(void*)(OOC_INT32)t,128);
    goto l18;
  case 2:
    _copy_16((const void*)((OOC_CHAR16[]){73,110,118,97,108,105,100,32,99,104,97,114,97,99,116,101,114,32,96,36,123,99,104,97,114,125,39,32,105,110,32,114,101,102,101,114,101,110,99,101,32,99,111,109,109,97,110,100,0}),(void*)(OOC_INT32)t,128);
    goto l18;
  case 3:
    _copy_16((const void*)((OOC_CHAR16[]){69,120,112,101,99,116,101,100,32,109,111,100,117,108,101,32,110,97,109,101,44,32,98,117,116,32,102,111,117,110,100,32,96,36,123,99,104,97,114,125,39,0}),(void*)(OOC_INT32)t,128);
    goto l18;
  case 4:
    _copy_16((const void*)((OOC_CHAR16[]){69,120,112,101,99,116,101,100,32,105,100,101,110,116,105,102,105,101,114,44,32,98,117,116,32,102,111,117,110,100,32,96,36,123,99,104,97,114,125,39,0}),(void*)(OOC_INT32)t,128);
    goto l18;
  case 5:
    _copy_16((const void*)((OOC_CHAR16[]){69,120,112,101,99,116,101,100,32,105,100,101,110,116,105,102,105,101,114,32,97,116,32,101,110,100,32,111,102,32,114,101,102,101,114,101,110,99,101,32,99,111,109,109,97,110,100,0}),(void*)(OOC_INT32)t,128);
    goto l18;
  case 6:
    _copy_16((const void*)((OOC_CHAR16[]){67,111,117,108,100,32,110,111,116,32,114,101,115,111,108,118,101,32,105,100,101,110,116,105,102,105,101,114,32,96,36,123,105,100,101,110,116,125,39,0}),(void*)(OOC_INT32)t,128);
    goto l18;
  case 7:
    _copy_16((const void*)((OOC_CHAR16[]){84,104,101,32,114,101,102,101,114,101,110,99,101,100,32,100,101,99,108,97,114,97,116,105,111,110,32,105,115,32,110,111,116,32,97,32,109,111,100,117,108,101,0}),(void*)(OOC_INT32)t,128);
    goto l18;
  case 8:
    _copy_16((const void*)((OOC_CHAR16[]){84,104,101,32,114,101,102,101,114,101,110,99,101,100,32,100,101,99,108,97,114,97,116,105,111,110,32,105,115,32,110,111,116,32,97,32,99,111,110,115,116,97,110,116,0}),(void*)(OOC_INT32)t,128);
    goto l18;
  case 9:
    _copy_16((const void*)((OOC_CHAR16[]){84,104,101,32,114,101,102,101,114,101,110,99,101,100,32,100,101,99,108,97,114,97,116,105,111,110,32,105,115,32,110,111,116,32,97,32,114,101,99,111,114,100,32,102,105,101,108,100,0}),(void*)(OOC_INT32)t,128);
    goto l18;
  case 10:
    _copy_16((const void*)((OOC_CHAR16[]){84,104,101,32,114,101,102,101,114,101,110,99,101,100,32,100,101,99,108,97,114,97,116,105,111,110,32,105,115,32,110,111,116,32,97,32,112,97,114,97,109,101,116,101,114,0}),(void*)(OOC_INT32)t,128);
    goto l18;
  case 11:
    _copy_16((const void*)((OOC_CHAR16[]){84,104,101,32,114,101,102,101,114,101,110,99,101,100,32,100,101,99,108,97,114,97,116,105,111,110,32,105,115,32,110,111,116,32,97,32,112,114,111,99,101,100,117,114,101,0}),(void*)(OOC_INT32)t,128);
    goto l18;
  case 12:
    _copy_16((const void*)((OOC_CHAR16[]){84,104,101,32,114,101,102,101,114,101,110,99,101,100,32,100,101,99,108,97,114,97,116,105,111,110,32,105,115,32,110,111,116,32,97,32,116,121,112,101,0}),(void*)(OOC_INT32)t,128);
    goto l18;
  case 13:
    _copy_16((const void*)((OOC_CHAR16[]){84,104,101,32,114,101,102,101,114,101,110,99,101,100,32,100,101,99,108,97,114,97,116,105,111,110,32,105,115,32,110,111,116,32,97,32,118,97,114,105,97,98,108,101,0}),(void*)(OOC_INT32)t,128);
    goto l18;
  case 14:
    _copy_16((const void*)((OOC_CHAR16[]){84,104,101,32,114,101,102,101,114,101,110,99,101,100,32,100,101,99,108,97,114,97,116,105,111,110,32,105,115,32,110,111,116,32,101,120,112,111,114,116,101,100,0}),(void*)(OOC_INT32)t,128);
    goto l18;
  default:
    _failed_case(i1, 1694);
    goto l18;
  }
l18:
  i1 = (OOC_INT32)context;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2885)))), OOC_Error__ContextDesc_BaseTemplate)),OOC_Error__ContextDesc_BaseTemplate)((OOC_Error__Context)i1, (Msg__Msg)i0, (void*)(OOC_INT32)t, 128, (void*)(OOC_INT32)templ, templ_0d);
  return;
  ;
}

static OOC_CHAR8 OOC_Doc_ResolveRef__ParseRef(OOC_Doc__OberonRef ref, OOC_Error__List errList, OOC_CHAR8 *external, OOC_Doc__InlineList *tokenList) {
  register OOC_INT32 i0,i1;
  Msg__Msg lastError;
  OOC_Doc__InlineElement currElement;
  OOC_Doc__Text currText;
  OOC_INT32 currPos;
  OOC_CHAR8 _char;
  auto void OOC_Doc_ResolveRef__ParseRef_Err(OOC_INT32 code);
  auto OOC_CHAR8 OOC_Doc_ResolveRef__ParseRef_HasMarkup(OOC_Doc__InlineElement ptr);
  auto void OOC_Doc_ResolveRef__ParseRef_NextChar(void);
  auto void OOC_Doc_ResolveRef__ParseRef_S(void);
  auto void OOC_Doc_ResolveRef__ParseRef_SetCharAttribute(void);
  auto void OOC_Doc_ResolveRef__ParseRef_Ident(OOC_CHAR8 isModule);
    
    void OOC_Doc_ResolveRef__ParseRef_Err(OOC_INT32 code) {
      register OOC_INT32 i0,i1,i2;
      OOC_Doc__Element pos;

      i0 = (OOC_INT32)ref;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3306))+20);
      i1 = i1==(OOC_INT32)0;
      if (i1) goto l3;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3334))+20);
      i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3347)))), &_td_OOC_Doc__TextDesc));
      
      goto l5;
l3:
      i1=1u;
l5:
      if (i1) goto l7;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3413))+20);
      pos = (OOC_Doc__Element)i0;
      
      goto l8;
l7:
      pos = (OOC_Doc__Element)i0;
      
l8:
      i1 = (OOC_INT32)OOC_Doc_ResolveRef__resolveContext;
      i2 = code;
      i1 = (OOC_INT32)OOC_Error__New((OOC_Error__Context)i1, i2);
      lastError = (Msg__Msg)i1;
      i2 = *(OOC_INT32*)(_check_pointer(i0, 3531));
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3505)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i1, "pos", 4, i2);
      i1 = (OOC_INT32)lastError;
      i2 = *(OOC_INT32*)((_check_pointer(i0, 3587))+4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3560)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i1, "line", 5, i2);
      i1 = (OOC_INT32)lastError;
      i0 = *(OOC_INT32*)((_check_pointer(i0, 3645))+8);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3616)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i1, "column", 7, i0);
      i0 = (OOC_INT32)errList;
      i1 = (OOC_INT32)lastError;
      OOC_Error__ListDesc_Append((OOC_Error__List)i0, (Msg__Msg)i1);
      currText = (OOC_Doc__Text)(OOC_INT32)0;
      return;
      ;
    }

    
    OOC_CHAR8 OOC_Doc_ResolveRef__ParseRef_HasMarkup(OOC_Doc__InlineElement ptr) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)ptr;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l11;
      
l3_loop:
      i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3884)))), &_td_OOC_Doc__TextDesc));
      if (!i1) goto l6;
      return 1u;
l6:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3955))+12);
      ptr = (OOC_Doc__InlineElement)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l3_loop;
l11:
      return 0u;
      ;
    }

    
    void OOC_Doc_ResolveRef__ParseRef_NextChar(void) {
      register OOC_INT32 i0,i1,i2,i3;

      i0 = currPos;
      i0 = i0+1;
      currPos = i0;
      i1 = (OOC_INT32)currText;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4093))+16);
      i2 = _check_pointer(i2, 4101);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i0 = *(OOC_UINT8*)(i2+(_check_index(i0, i3, OOC_UINT32, 4101)));
      _char = i0;
      i1 = i1!=(OOC_INT32)0;
      if (i1) goto l3;
      i1=0u;
      goto l5;
l3:
      i1 = i0==0u;
      
l5:
      if (!i1) goto l20;
l7_loop:
      i1 = (OOC_INT32)currElement;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4192))+12);
      currElement = (OOC_Doc__InlineElement)i1;
      currPos = 0;
      i2 = i1==(OOC_INT32)0;
      if (i2) goto l10;
      i0 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4341)))), &_td_OOC_Doc__TextDesc, 4341);
      currText = (OOC_Doc__Text)i0;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4374))+16);
      i1 = _check_pointer(i1, 4382);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i1 = *(OOC_UINT8*)(i1+(_check_index(0, i2, OOC_UINT32, 4382)));
      _char = i1;
      
      goto l11;
l10:
      currText = (OOC_Doc__Text)(OOC_INT32)0;
      i1=i0;i0=(OOC_INT32)0;
l11:
      i0 = i0!=(OOC_INT32)0;
      if (i0) goto l14;
      i0=0u;
      goto l16;
l14:
      i0 = i1==0u;
      
l16:
      if (!i0) goto l20;
      i0=i1;
      goto l7_loop;
l20:
      return;
      ;
    }

    
    void OOC_Doc_ResolveRef__ParseRef_S(void) {
      register OOC_INT32 i0;

      i0 = (OOC_INT32)currText;
      i0 = i0!=(OOC_INT32)0;
      if (i0) goto l3;
      i0=0u;
      goto l5;
l3:
      i0 = _char;
      i0 = (OOC_UINT8)i0<=(OOC_UINT8)32u;
      
l5:
      if (!i0) goto l16;
l7_loop:
      OOC_Doc_ResolveRef__ParseRef_NextChar();
      i0 = (OOC_INT32)currText;
      i0 = i0!=(OOC_INT32)0;
      if (i0) goto l10;
      i0=0u;
      goto l12;
l10:
      i0 = _char;
      i0 = (OOC_UINT8)i0<=(OOC_UINT8)32u;
      
l12:
      if (i0) goto l7_loop;
l16:
      return;
      ;
    }

    
    void OOC_Doc_ResolveRef__ParseRef_SetCharAttribute(void) {
      register OOC_INT32 i0,i1;
      OOC_CHAR8 str[2];

      i0 = _char;
      *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, 2, OOC_UINT8, 4632))) = i0;
      *(OOC_UINT8*)((OOC_INT32)str+(_check_index(1, 2, OOC_UINT8, 4648))) = 0u;
      i0 = (OOC_INT32)Msg__GetStringPtr((void*)(OOC_INT32)str, 2);
      i1 = (OOC_INT32)lastError;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4674)))), Msg__MsgDesc_SetStringAttrib)),Msg__MsgDesc_SetStringAttrib)((Msg__Msg)i1, "char", 5, (Msg__StringPtr)i0);
      return;
      ;
    }

    
    void OOC_Doc_ResolveRef__ParseRef_Ident(OOC_CHAR8 isModule) {
      register OOC_INT32 i0,i1;
      OOC_INT32 i;
      OOC_CHAR8 str[1024];
      auto OOC_CHAR8 OOC_Doc_ResolveRef__ParseRef_Ident_Valid(OOC_CHAR8 ch);
        
        OOC_CHAR8 OOC_Doc_ResolveRef__ParseRef_Ident_Valid(OOC_CHAR8 ch) {
          register OOC_INT32 i0;

          i0 = ch;
          switch (i0) {
          case 97u ... 122u:
          case 65u ... 90u:
          case 48u ... 57u:
          case 95u:
            return 1u;
            goto l5;
          case 58u:
            i0 = isModule;
            return i0;
            goto l5;
          default:
            return 0u;
            goto l5;
          }
l5:
          _failed_function(4871); return 0;
          ;
        }


      i0 = (OOC_INT32)currText;
      i0 = i0==(OOC_INT32)0;
      if (i0) goto l24;
      i0 = _char;
      i0 = OOC_Doc_ResolveRef__ParseRef_Ident_Valid(i0);
      if (i0) goto l9;
      i0 = isModule;
      if (i0) goto l7;
      OOC_Doc_ResolveRef__ParseRef_Err(4);
      OOC_Doc_ResolveRef__ParseRef_SetCharAttribute();
      goto l25;
l7:
      OOC_Doc_ResolveRef__ParseRef_Err(3);
      OOC_Doc_ResolveRef__ParseRef_SetCharAttribute();
      goto l25;
l9:
      i = 0;
      i0=0;
l10_loop:
      i1 = i0<1023;
      if (!i1) goto l14;
      i1 = _char;
      *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, 1024, OOC_UINT32, 5286))) = i1;
      i0 = i0+1;
      i = i0;
      
l14:
      OOC_Doc_ResolveRef__ParseRef_NextChar();
      i1 = (OOC_INT32)currText;
      i1 = i1==(OOC_INT32)0;
      if (i1) goto l17;
      i1 = _char;
      i1 = OOC_Doc_ResolveRef__ParseRef_Ident_Valid(i1);
      i1 = !i1;
      
      goto l19;
l17:
      i1=1u;
l19:
      if (!i1) goto l10_loop;
l22:
      *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, 1024, OOC_UINT32, 5413))) = 0u;
      i0 = (OOC_INT32)ref;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5472))+20);
      i1 = _check_pointer(i1, 5484);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5472))+20);
      i0 = (OOC_INT32)OOC_Doc__NewText((void*)(OOC_INT32)str, 1024, (void*)(_check_pointer(i0, 5484)), (RT0__Struct)((OOC_INT32)&_td_OOC_Doc__Position));
      i1 = (OOC_INT32)*tokenList;
      OOC_Doc__InlineListDesc_Append((OOC_Doc__InlineList)i1, (OOC_Doc__InlineElement)i0);
      goto l25;
l24:
      OOC_Doc_ResolveRef__ParseRef_Err(5);
l25:
      return;
      ;
    }


  lastError = (Msg__Msg)(OOC_INT32)0;
  *external = 0u;
  i0 = (OOC_INT32)OOC_Doc__NewInlineList();
  *tokenList = (OOC_Doc__InlineList)i0;
  i0 = (OOC_INT32)ref;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5781))+20);
  currElement = (OOC_Doc__InlineElement)i0;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l30;
  i1 = OOC_Doc_ResolveRef__ParseRef_HasMarkup((OOC_Doc__InlineElement)i0);
  if (i1) goto l28;
  i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5956)))), &_td_OOC_Doc__TextDesc, 5956);
  currText = (OOC_Doc__Text)i0;
  currPos = 0;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6005))+16);
  i0 = _check_pointer(i0, 6013);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = *(OOC_UINT8*)(i0+(_check_index(0, i1, OOC_UINT32, 6013)));
  _char = i0;
  OOC_Doc_ResolveRef__ParseRef_S();
  i0 = _char;
  i0 = i0==42u;
  if (i0) goto l7;
  OOC_Doc_ResolveRef__ParseRef_Ident(0u);
  goto l8;
l7:
  *external = 1u;
  OOC_Doc_ResolveRef__ParseRef_NextChar();
  OOC_Doc_ResolveRef__ParseRef_S();
  OOC_Doc_ResolveRef__ParseRef_Ident(1u);
l8:
  OOC_Doc_ResolveRef__ParseRef_S();
  i0 = (OOC_INT32)currText;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l11;
  i1=0u;
  goto l13;
l11:
  i1 = _char;
  i1 = i1==46u;
  
l13:
  if (!i1) goto l24;
l15_loop:
  OOC_Doc_ResolveRef__ParseRef_NextChar();
  OOC_Doc_ResolveRef__ParseRef_S();
  OOC_Doc_ResolveRef__ParseRef_Ident(0u);
  OOC_Doc_ResolveRef__ParseRef_S();
  i0 = (OOC_INT32)currText;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l18;
  i1=0u;
  goto l20;
l18:
  i1 = _char;
  i1 = i1==46u;
  
l20:
  if (i1) goto l15_loop;
l24:
  i0 = i0!=(OOC_INT32)0;
  if (!i0) goto l31;
  OOC_Doc_ResolveRef__ParseRef_Err(2);
  OOC_Doc_ResolveRef__ParseRef_SetCharAttribute();
  goto l31;
l28:
  OOC_Doc_ResolveRef__ParseRef_Err(1);
  goto l31;
l30:
  OOC_Doc_ResolveRef__ParseRef_Err(0);
l31:
  i0 = (OOC_INT32)lastError;
  return (i0==(OOC_INT32)0);
  ;
}

void OOC_Doc_ResolveRef__Resolve(OOC_SymbolTable__Module symTab, OOC_Error__List errList) {
  register OOC_INT32 i0;
  ADT_Dictionary__Dictionary interfaceCache;
  auto void OOC_Doc_ResolveRef__Resolve_ResolveRef(OOC_Doc__Document doc, OOC_Doc__OberonRef ref, OOC_SymbolTable__Declaration refererDecl, OOC_SymbolTable__Item identificationContext, OOC_SymbolTable__Namespace nsRecord);
  auto void OOC_Doc_ResolveRef__Resolve_ResolveDoc(OOC_Doc__Document doc, OOC_SymbolTable__Declaration refererDecl, OOC_SymbolTable__Item identificationContext, OOC_SymbolTable__Namespace nsRecord);
  auto void OOC_Doc_ResolveRef__Resolve_RecResolve(OOC_SymbolTable__Item item, OOC_SymbolTable__Item identificationContext, OOC_SymbolTable__Namespace nsRecord);
    
    void OOC_Doc_ResolveRef__Resolve_ResolveRef(OOC_Doc__Document doc, OOC_Doc__OberonRef ref, OOC_SymbolTable__Declaration refererDecl, OOC_SymbolTable__Item identificationContext, OOC_SymbolTable__Namespace nsRecord) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
      OOC_Doc__InlineList tokenList;
      OOC_CHAR8 external;
      OOC_Doc__InlineElement part;
      OOC_Scanner_InputBuffer__CharArray module;
      OOC_INT32 len;
      OOC_Doc__InlineElement ptr;
      OOC_Scanner_InputBuffer__CharArray id;
      OOC_SymbolTable__Declaration decl;
      OOC_SymbolTable__Namespace ns;
      Msg__Msg lastError;
      auto OOC_SymbolTable__Name OOC_Doc_ResolveRef__Resolve_ResolveRef_GetName(void);
      auto void OOC_Doc_ResolveRef__Resolve_ResolveRef_Err(OOC_INT32 code);
      auto OOC_CHAR8 OOC_Doc_ResolveRef__Resolve_ResolveRef_Exported(OOC_SymbolTable__Declaration decl);
        
        OOC_SymbolTable__Name OOC_Doc_ResolveRef__Resolve_ResolveRef_GetName(void) {
          register OOC_INT32 i0,i1,i2,i3,i4;
          OOC_SymbolTable__Name n;

          i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SymbolTable__Name.baseTypes[0]);
          n = (OOC_SymbolTable__Name)i0;
          i1 = (OOC_INT32)ref;
          i2 = (OOC_INT32)part;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 7284)))), &_td_OOC_Doc__TextDesc, 7284)), 7289))+16);
          i3 = *(OOC_INT32*)((_check_pointer(i1, 7357))+8);
          i4 = *(OOC_INT32*)((_check_pointer(i1, 7341))+4);
          i1 = *(OOC_INT32*)(_check_pointer(i1, 7302));
          OOC_SymbolTable__InitName((OOC_SymbolTable__Name)i0, (OOC_Scanner_InputBuffer__CharArray)i2, i1, i4, i3);
          return (OOC_SymbolTable__Name)i0;
          ;
        }

        
        void OOC_Doc_ResolveRef__Resolve_ResolveRef_Err(OOC_INT32 code) {
          register OOC_INT32 i0,i1,i2;
          OOC_Doc__Element pos;

          i0 = (OOC_INT32)ref;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7518))+20);
          pos = (OOC_Doc__Element)i0;
          i1 = (OOC_INT32)OOC_Doc_ResolveRef__resolveContext;
          i2 = code;
          i1 = (OOC_INT32)OOC_Error__New((OOC_Error__Context)i1, i2);
          lastError = (Msg__Msg)i1;
          i2 = *(OOC_INT32*)(_check_pointer(i0, 7630));
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7604)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i1, "pos", 4, i2);
          i1 = (OOC_INT32)lastError;
          i2 = *(OOC_INT32*)((_check_pointer(i0, 7688))+4);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7661)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i1, "line", 5, i2);
          i1 = (OOC_INT32)lastError;
          i0 = *(OOC_INT32*)((_check_pointer(i0, 7748))+8);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7719)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i1, "column", 7, i0);
          i0 = (OOC_INT32)errList;
          i1 = (OOC_INT32)lastError;
          OOC_Error__ListDesc_Append((OOC_Error__List)i0, (Msg__Msg)i1);
          return;
          ;
        }

        
        OOC_CHAR8 OOC_Doc_ResolveRef__Resolve_ResolveRef_Exported(OOC_SymbolTable__Declaration decl) {
          register OOC_INT32 i0,i1,i2,i3;
          OOC_SymbolTable__Module module;
          Object__Object obj;

          i0 = (OOC_INT32)decl;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7998)))), &_td_OOC_SymbolTable__ModuleDesc);
          if (i1) goto l6;
          i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8157)))), OOC_SymbolTable__ItemDesc_Module)),OOC_SymbolTable__ItemDesc_Module)((OOC_SymbolTable__Item)i0);
          module = (OOC_SymbolTable__Module)i1;
          i2 = (OOC_INT32)interfaceCache;
          i2 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i2, (Object__Object)i1);
          i2 = !i2;
          if (!i2) goto l5;
          i2 = (OOC_INT32)OOC_SymbolTable_Exports__GetExports((OOC_SymbolTable__Module)i1, 0u);
          i3 = (OOC_INT32)interfaceCache;
          ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i3, (Object__Object)i1, (Object__Object)i2);
l5:
          i2 = (OOC_INT32)interfaceCache;
          i1 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i2, (Object__Object)i1);
          obj = (Object__Object)i1;
          i0 = ADT_Dictionary_AddressKey__DictionaryDesc_HasKey((ADT_Dictionary_AddressKey__Dictionary)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8388)))), &_td_ADT_Dictionary_AddressKey__DictionaryDesc, 8388)), (Object__Object)i0);
          return i0;
          goto l7;
l6:
          return 1u;
l7:
          _failed_function(7830); return 0;
          ;
        }


      i0 = (OOC_INT32)errList;
      i1 = (OOC_INT32)ref;
      i0 = OOC_Doc_ResolveRef__ParseRef((OOC_Doc__OberonRef)i1, (OOC_Error__List)i0, (void*)(OOC_INT32)&external, (void*)(OOC_INT32)&tokenList);
      if (!i0) goto l122;
      i0 = (OOC_INT32)tokenList;
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 8569));
      part = (OOC_Doc__InlineElement)i2;
      i3 = external;
      if (i3) goto l100;
      decl = (OOC_SymbolTable__Declaration)0;
      i2 = (OOC_INT32)nsRecord;
      i2 = i2!=0;
      if (i2) goto l7;
      i1=0u;
      goto l9;
l7:
      i1 = *(OOC_INT32*)((_check_pointer(i1, 9559))+16);
      i1 = i1==14;
      
l9:
      if (i1) goto l11;
      i0=0u;
      goto l13;
l11:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9615));
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9621))+12);
      i0 = i0==0;
      
l13:
      if (i0) goto l15;
      i0=0;
      goto l16;
l15:
      i0 = (OOC_INT32)OOC_Doc_ResolveRef__Resolve_ResolveRef_GetName();
      i1 = (OOC_INT32)nsRecord;
      i2 = (OOC_INT32)identificationContext;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9887)))), OOC_SymbolTable__NamespaceDesc_Identify)),OOC_SymbolTable__NamespaceDesc_Identify)((OOC_SymbolTable__Namespace)i1, (OOC_SymbolTable__Item)i2, (OOC_SymbolTable__Name)i0, 1u);
      decl = (OOC_SymbolTable__Declaration)i0;
      
l16:
      i1 = i0==0;
      if (!i1) goto l20;
      i0 = (OOC_INT32)identificationContext;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10170)))), OOC_SymbolTable__ItemDesc_Namespace)),OOC_SymbolTable__ItemDesc_Namespace)((OOC_SymbolTable__Item)i0);
      ns = (OOC_SymbolTable__Namespace)i0;
      i0 = (OOC_INT32)OOC_Doc_ResolveRef__Resolve_ResolveRef_GetName();
      i1 = (OOC_INT32)ns;
      i2 = (OOC_INT32)identificationContext;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10207)))), OOC_SymbolTable__NamespaceDesc_Identify)),OOC_SymbolTable__NamespaceDesc_Identify)((OOC_SymbolTable__Namespace)i1, (OOC_SymbolTable__Item)i2, (OOC_SymbolTable__Name)i0, 1u);
      decl = (OOC_SymbolTable__Declaration)i0;
      
l20:
      i1 = i0!=0;
      if (i1) goto l23;
      i1=0u;
      goto l25;
l23:
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10308)))), &_td_OOC_SymbolTable__ImportDesc);
      
l25:
      if (!i1) goto l28;
      i1 = (OOC_INT32)doc;
      OOC_Doc__DocumentDesc_AddUsedImport((OOC_Doc__Document)i1, (ADT_Storable__Object)i0);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10454)))), &_td_OOC_SymbolTable__ImportDesc, 10454)), 10461))+52);
      decl = (OOC_SymbolTable__Declaration)i0;
      
l28:
      i1 = i0!=0;
      if (i1) goto l31;
      i1=0u;
      goto l33;
l31:
      i1 = (OOC_INT32)part;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10530))+12);
      i1 = i1!=0;
      
l33:
      if (!i1) goto l49;
l36_loop:
      i1 = (OOC_INT32)part;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10577))+12);
      part = (OOC_Doc__InlineElement)i1;
      i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10613)))), OOC_SymbolTable__DeclarationDesc_GetEmbeddedNamespace)),OOC_SymbolTable__DeclarationDesc_GetEmbeddedNamespace)((OOC_SymbolTable__Declaration)i0, 1u);
      ns = (OOC_SymbolTable__Namespace)i1;
      i1 = i1!=0;
      if (!i1) goto l40;
      i0 = (OOC_INT32)OOC_Doc_ResolveRef__Resolve_ResolveRef_GetName();
      i1 = (OOC_INT32)ns;
      i2 = (OOC_INT32)identificationContext;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10699)))), OOC_SymbolTable__NamespaceDesc_Identify)),OOC_SymbolTable__NamespaceDesc_Identify)((OOC_SymbolTable__Namespace)i1, (OOC_SymbolTable__Item)i2, (OOC_SymbolTable__Name)i0, 1u);
      decl = (OOC_SymbolTable__Declaration)i0;
      
l40:
      i1 = i0!=0;
      if (i1) goto l43;
      i1=0u;
      goto l45;
l43:
      i1 = (OOC_INT32)part;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10530))+12);
      i1 = i1!=0;
      
l45:
      if (i1) goto l36_loop;
l49:
      i1 = i0==0;
      if (i1) goto l98;
      i1 = (OOC_INT32)ref;
      i1 = *(OOC_INT32*)((_check_pointer(i1, 11014))+16);
      switch (i1) {
      case 12:
        i0 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11084)))), &_td_OOC_SymbolTable__ModuleDesc));
        if (!i0) goto l90;
        OOC_Doc_ResolveRef__Resolve_ResolveRef_Err(7);
        goto l90;
      case 13:
        i0 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11213)))), &_td_OOC_SymbolTable__ConstDeclDesc));
        if (!i0) goto l90;
        OOC_Doc_ResolveRef__Resolve_ResolveRef_Err(8);
        goto l90;
      case 14:
        i0 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11348)))), &_td_OOC_SymbolTable__FieldDeclDesc));
        if (!i0) goto l90;
        OOC_Doc_ResolveRef__Resolve_ResolveRef_Err(9);
        goto l90;
      case 15:
        i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11483)))), &_td_OOC_SymbolTable__VarDeclDesc));
        if (i1) goto l68;
        i0 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11529)))), &_td_OOC_SymbolTable__VarDeclDesc, 11529)), 11537))+56);
        i0 = !i0;
        
        goto l70;
l68:
        i0=1u;
l70:
        if (!i0) goto l90;
        OOC_Doc_ResolveRef__Resolve_ResolveRef_Err(10);
        goto l90;
      case 16:
        i0 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11671)))), &_td_OOC_SymbolTable__ProcDeclDesc));
        if (!i0) goto l90;
        OOC_Doc_ResolveRef__Resolve_ResolveRef_Err(11);
        goto l90;
      case 17:
        i0 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11803)))), &_td_OOC_SymbolTable__TypeDeclDesc));
        if (!i0) goto l90;
        OOC_Doc_ResolveRef__Resolve_ResolveRef_Err(12);
        goto l90;
      case 18:
        i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11934)))), &_td_OOC_SymbolTable__VarDeclDesc));
        if (i1) goto l84;
        i0 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11962)))), &_td_OOC_SymbolTable__VarDeclDesc, 11962)), 11970))+56);
        
        goto l86;
l84:
        i0=1u;
l86:
        if (!i0) goto l90;
        OOC_Doc_ResolveRef__Resolve_ResolveRef_Err(13);
        goto l90;
      default:
        _failed_case(i1, 11006);
        goto l90;
      }
l90:
      i0 = (OOC_INT32)decl;
      i0 = OOC_Doc_ResolveRef__Resolve_ResolveRef_Exported((OOC_SymbolTable__Declaration)i0);
      i0 = !i0;
      if (i0) goto l93;
      i0=0u;
      goto l95;
l93:
      i0 = (OOC_INT32)refererDecl;
      i0 = OOC_Doc_ResolveRef__Resolve_ResolveRef_Exported((OOC_SymbolTable__Declaration)i0);
      
l95:
      if (!i0) goto l97;
      OOC_Doc_ResolveRef__Resolve_ResolveRef_Err(14);
l97:
      i0 = (OOC_INT32)decl;
      i1 = (OOC_INT32)ref;
      OOC_Doc__OberonRefDesc_SetTarget((OOC_Doc__OberonRef)i1, (ADT_Storable__Object)i0);
      goto l122;
l98:
      OOC_Doc_ResolveRef__Resolve_ResolveRef_Err(6);
      i0 = (OOC_INT32)part;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10962)))), &_td_OOC_Doc__TextDesc, 10962)), 10967))+16);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10962)))), &_td_OOC_Doc__TextDesc, 10962)), 10967))+16);
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 10975)), 0);
      i0 = (OOC_INT32)Msg__GetStringPtr((void*)(_check_pointer(i0, 10975)), i1);
      i1 = (OOC_INT32)lastError;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10870)))), Msg__MsgDesc_SetStringAttrib)),Msg__MsgDesc_SetStringAttrib)((Msg__Msg)i1, "ident", 6, (Msg__StringPtr)i0);
      goto l122;
l100:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 8864)))), &_td_OOC_Doc__TextDesc, 8864)), 8869))+16);
      module = (OOC_Scanner_InputBuffer__CharArray)i0;
      len = 1;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 8931))+12);
      ptr = (OOC_Doc__InlineElement)i3;
      i4 = i3!=0;
      if (i4) goto l103;
      i3=1;
      goto l109;
l103:
      i4=i3;i3=1;
l104_loop:
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 9022)))), &_td_OOC_Doc__TextDesc, 9022)), 9027))+16);
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 9022)))), &_td_OOC_Doc__TextDesc, 9022)), 9027))+16);
      i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 9035)), 0);
      i5 = Strings__Length((void*)(_check_pointer(i6, 9035)), i5);
      i3 = i3+(i5+1);
      len = i3;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 9064))+12);
      ptr = (OOC_Doc__InlineElement)i4;
      i5 = i4!=0;
      if (i5) goto l104_loop;
l109:
      i3 = (OOC_INT32)RT0__NewObject(_td_OOC_Scanner_InputBuffer__CharArray.baseTypes[0], i3);
      id = (OOC_Scanner_InputBuffer__CharArray)i3;
      i4 = OOC_ARRAY_LENGTH((_check_pointer(i3, 9150)), 0);
      _copy_8((const void*)"",(void*)(_check_pointer(i3, 9150)),i4);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 9175))+12);
      ptr = (OOC_Doc__InlineElement)i2;
      i4 = i2!=0;
      if (!i4) goto l120;
l112_loop:
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 9256)))), &_td_OOC_Doc__TextDesc, 9256)), 9261))+16);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 9256)))), &_td_OOC_Doc__TextDesc, 9256)), 9261))+16);
      i4 = OOC_ARRAY_LENGTH((_check_pointer(i4, 9269)), 0);
      i6 = OOC_ARRAY_LENGTH((_check_pointer(i3, 9274)), 0);
      Strings__Append((void*)(_check_pointer(i5, 9269)), i4, (void*)(_check_pointer(i3, 9274)), i6);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 9300))+12);
      ptr = (OOC_Doc__InlineElement)i2;
      i4 = i2!=0;
      if (!i4) goto l116;
      i5 = OOC_ARRAY_LENGTH((_check_pointer(i3, 9383)), 0);
      Strings__Append(".", 2, (void*)(_check_pointer(i3, 9383)), i5);
l116:
      if (i4) goto l112_loop;
l120:
      OOC_Doc__OberonRefDesc_SetExternalTarget((OOC_Doc__OberonRef)i1, (OOC_Scanner_InputBuffer__CharArray)i0, (OOC_Scanner_InputBuffer__CharArray)i3);
l122:
      return;
      ;
    }

    
    void OOC_Doc_ResolveRef__Resolve_ResolveDoc(OOC_Doc__Document doc, OOC_SymbolTable__Declaration refererDecl, OOC_SymbolTable__Item identificationContext, OOC_SymbolTable__Namespace nsRecord) {
      register OOC_INT32 i0;
      auto void OOC_Doc_ResolveRef__Resolve_ResolveDoc_ResolveInlineList(OOC_Doc__InlineElement inlineList);
      auto void OOC_Doc_ResolveRef__Resolve_ResolveDoc_ResolveBlockList(OOC_Doc__BlockElement blockList);
        
        void OOC_Doc_ResolveRef__Resolve_ResolveDoc_ResolveInlineList(OOC_Doc__InlineElement inlineList) {
          register OOC_INT32 i0,i1,i2,i3,i4;
          OOC_Doc__InlineElement ptr;

          i0 = (OOC_INT32)inlineList;
          ptr = (OOC_Doc__InlineElement)i0;
          i1 = i0!=(OOC_INT32)0;
          if (!i1) goto l30;
          
l3_loop:
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12690)))), &_td_OOC_Doc__GlyphDesc);
          if (i1) goto l25;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12746)))), &_td_OOC_Doc__TextDesc);
          if (i1) goto l25;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12801)))), &_td_OOC_Doc__OberonRefDesc);
          if (i1) goto l22;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12915)))), &_td_OOC_Doc__MarkedInlineDesc);
          if (i1) goto l20;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13000)))), &_td_OOC_Doc__EmailDesc);
          if (i1) goto l18;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13123)))), &_td_OOC_Doc__UrefDesc);
          if (i1) goto l16;
          _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13118)))), 13118);
          goto l25;
l16:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13171))+16);
          OOC_Doc_ResolveRef__Resolve_ResolveDoc_ResolveInlineList((OOC_Doc__InlineElement)i1);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13213))+20);
          OOC_Doc_ResolveRef__Resolve_ResolveDoc_ResolveInlineList((OOC_Doc__InlineElement)i1);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13256))+24);
          OOC_Doc_ResolveRef__Resolve_ResolveDoc_ResolveInlineList((OOC_Doc__InlineElement)i1);
          goto l25;
l18:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13049))+16);
          OOC_Doc_ResolveRef__Resolve_ResolveDoc_ResolveInlineList((OOC_Doc__InlineElement)i1);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13095))+20);
          OOC_Doc_ResolveRef__Resolve_ResolveDoc_ResolveInlineList((OOC_Doc__InlineElement)i1);
          goto l25;
l20:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12971))+20);
          OOC_Doc_ResolveRef__Resolve_ResolveDoc_ResolveInlineList((OOC_Doc__InlineElement)i1);
          goto l25;
l22:
          i1 = (OOC_INT32)nsRecord;
          i2 = (OOC_INT32)identificationContext;
          i3 = (OOC_INT32)refererDecl;
          i4 = (OOC_INT32)doc;
          OOC_Doc_ResolveRef__Resolve_ResolveRef((OOC_Doc__Document)i4, (OOC_Doc__OberonRef)i0, (OOC_SymbolTable__Declaration)i3, (OOC_SymbolTable__Item)i2, (OOC_SymbolTable__Namespace)i1);
l25:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13306))+12);
          ptr = (OOC_Doc__InlineElement)i0;
          i1 = i0!=(OOC_INT32)0;
          if (i1) goto l3_loop;
l30:
          return;
          ;
        }

        
        void OOC_Doc_ResolveRef__Resolve_ResolveDoc_ResolveBlockList(OOC_Doc__BlockElement blockList) {
          register OOC_INT32 i0,i1;
          OOC_Doc__BlockElement ptr;

          i0 = (OOC_INT32)blockList;
          ptr = (OOC_Doc__BlockElement)i0;
          i1 = i0!=(OOC_INT32)0;
          if (!i1) goto l48;
          
l3_loop:
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13553)))), &_td_OOC_Doc__ParagraphDesc);
          if (i1) goto l42;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13635)))), &_td_OOC_Doc__ExampleDesc);
          if (i1) goto l40;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13715)))), &_td_OOC_Doc__PreCondDesc);
          if (i1) goto l38;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13793)))), &_td_OOC_Doc__PostCondDesc);
          if (i1) goto l36;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13872)))), &_td_OOC_Doc__ItemDesc);
          if (i1) goto l34;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13947)))), &_td_OOC_Doc__ItemizeDesc);
          if (i1) goto l32;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14109)))), &_td_OOC_Doc__EnumerateDesc);
          if (i1) goto l30;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14230)))), &_td_OOC_Doc__FirstColumnDesc);
          if (i1) goto l28;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14314)))), &_td_OOC_Doc__TableRowDesc);
          if (i1) goto l26;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14441)))), &_td_OOC_Doc__TableDesc);
          if (i1) goto l24;
          _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14436)))), 14436);
          goto l43;
l24:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14489))+20);
          OOC_Doc_ResolveRef__Resolve_ResolveDoc_ResolveBlockList((OOC_Doc__BlockElement)i1);
          goto l43;
l26:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14365))+20);
          OOC_Doc_ResolveRef__Resolve_ResolveDoc_ResolveBlockList((OOC_Doc__BlockElement)i1);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14418))+24);
          OOC_Doc_ResolveRef__Resolve_ResolveDoc_ResolveBlockList((OOC_Doc__BlockElement)i1);
          goto l43;
l28:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14285))+20);
          OOC_Doc_ResolveRef__Resolve_ResolveDoc_ResolveInlineList((OOC_Doc__InlineElement)i1);
          goto l43;
l30:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14161))+28);
          OOC_Doc_ResolveRef__Resolve_ResolveDoc_ResolveBlockList((OOC_Doc__BlockElement)i1);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14203))+32);
          OOC_Doc_ResolveRef__Resolve_ResolveDoc_ResolveBlockList((OOC_Doc__BlockElement)i1);
          goto l43;
l32:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13998))+20);
          OOC_Doc_ResolveRef__Resolve_ResolveDoc_ResolveInlineList((OOC_Doc__InlineElement)i1);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14040))+24);
          OOC_Doc_ResolveRef__Resolve_ResolveDoc_ResolveBlockList((OOC_Doc__BlockElement)i1);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14082))+28);
          OOC_Doc_ResolveRef__Resolve_ResolveDoc_ResolveBlockList((OOC_Doc__BlockElement)i1);
          goto l43;
l34:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13919))+20);
          OOC_Doc_ResolveRef__Resolve_ResolveDoc_ResolveBlockList((OOC_Doc__BlockElement)i1);
          goto l43;
l36:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13844))+20);
          OOC_Doc_ResolveRef__Resolve_ResolveDoc_ResolveBlockList((OOC_Doc__BlockElement)i1);
          goto l43;
l38:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13765))+20);
          OOC_Doc_ResolveRef__Resolve_ResolveDoc_ResolveBlockList((OOC_Doc__BlockElement)i1);
          goto l43;
l40:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13686))+20);
          OOC_Doc_ResolveRef__Resolve_ResolveDoc_ResolveInlineList((OOC_Doc__InlineElement)i1);
          goto l43;
l42:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13606))+20);
          OOC_Doc_ResolveRef__Resolve_ResolveDoc_ResolveInlineList((OOC_Doc__InlineElement)i1);
l43:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14535))+12);
          ptr = (OOC_Doc__BlockElement)i0;
          i1 = i0!=(OOC_INT32)0;
          if (i1) goto l3_loop;
l48:
          return;
          ;
        }


      i0 = (OOC_INT32)doc;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14629));
      OOC_Doc_ResolveRef__Resolve_ResolveDoc_ResolveBlockList((OOC_Doc__BlockElement)i0);
      i0 = (OOC_INT32)doc;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14671))+4);
      OOC_Doc_ResolveRef__Resolve_ResolveDoc_ResolveInlineList((OOC_Doc__InlineElement)i0);
      return;
      ;
    }

    
    void OOC_Doc_ResolveRef__Resolve_RecResolve(OOC_SymbolTable__Item item, OOC_SymbolTable__Item identificationContext, OOC_SymbolTable__Namespace nsRecord) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_SymbolTable__Namespace ns;
      OOC_SymbolTable__Item ptr;

      i0 = (OOC_INT32)item;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14907)))), &_td_OOC_SymbolTable__DeclarationDesc);
      if (i1) goto l6;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15316)))), &_td_OOC_SymbolTable__RecordDesc);
      if (!i1) goto l17;
      i1 = (OOC_INT32)OOC_SymbolTable__RecordDesc_Namespace((OOC_SymbolTable__Record)i0);
      nsRecord = (OOC_SymbolTable__Namespace)i1;
      goto l17;
l6:
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14945)))), &_td_OOC_SymbolTable__ProcDeclDesc);
      if (i1) goto l12;
      i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15040)))), OOC_SymbolTable__DeclarationDesc_GetEmbeddedNamespace)),OOC_SymbolTable__DeclarationDesc_GetEmbeddedNamespace)((OOC_SymbolTable__Declaration)i0, 0u);
      ns = (OOC_SymbolTable__Namespace)i1;
      i2 = i1!=(OOC_INT32)0;
      if (!i2) goto l13;
      nsRecord = (OOC_SymbolTable__Namespace)i1;
      goto l13;
l12:
      identificationContext = (OOC_SymbolTable__Item)i0;
l13:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15180))+32);
      i1 = i1!=(OOC_INT32)0;
      if (!i1) goto l17;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15230))+32);
      i2 = (OOC_INT32)nsRecord;
      i3 = (OOC_INT32)identificationContext;
      OOC_Doc_ResolveRef__Resolve_ResolveDoc((OOC_Doc__Document)i1, (OOC_SymbolTable__Declaration)i0, (OOC_SymbolTable__Item)i3, (OOC_SymbolTable__Namespace)i2);
l17:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15446))+8);
      ptr = (OOC_SymbolTable__Item)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l25;
      i1 = (OOC_INT32)nsRecord;
      i2 = (OOC_INT32)identificationContext;
      
l20_loop:
      OOC_Doc_ResolveRef__Resolve_RecResolve((OOC_SymbolTable__Item)i0, (OOC_SymbolTable__Item)i2, (OOC_SymbolTable__Namespace)i1);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 15565));
      ptr = (OOC_SymbolTable__Item)i0;
      i3 = i0!=(OOC_INT32)0;
      if (i3) goto l20_loop;
l25:
      return;
      ;
    }


  i0 = (OOC_INT32)ADT_Dictionary__New();
  interfaceCache = (ADT_Dictionary__Dictionary)i0;
  i0 = (OOC_INT32)symTab;
  OOC_Doc_ResolveRef__Resolve_RecResolve((OOC_SymbolTable__Item)i0, (OOC_SymbolTable__Item)i0, (OOC_SymbolTable__Namespace)(OOC_INT32)0);
  return;
  ;
}

void OOC_OOC_Doc_ResolveRef_init(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Doc_ResolveRef__ErrorContext.baseTypes[0]);
  OOC_Doc_ResolveRef__resolveContext = (OOC_Doc_ResolveRef__ErrorContext)i0;
  OOC_Error__InitContext((OOC_Error__Context)i0, "OOC:Doc:ResolveRef", 19);
  return;
  ;
}

/* --- */
