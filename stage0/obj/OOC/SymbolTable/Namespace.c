#include <OOC/SymbolTable/Namespace.d>
#include <__oo2c.h>
#include <setjmp.h>

void OOC_SymbolTable_Namespace__ErrorContextDesc_GetTemplate(OOC_SymbolTable_Namespace__ErrorContext context, Msg__Msg msg, Msg__LString templ, OOC_LEN templ_0d) {
  register OOC_INT32 i0,i1;
  OOC_CHAR16 t[128];

  i0 = (OOC_INT32)msg;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 3171))+8);
  switch (i1) {
  case 1:
    _copy_16((const void*)((OOC_CHAR16[]){77,117,108,116,105,112,108,101,32,100,101,99,108,97,114,97,116,105,111,110,32,111,102,32,115,97,109,101,32,110,97,109,101,0}),(void*)(OOC_INT32)t,128);
    goto l12;
  case 2:
    _copy_16((const void*)((OOC_CHAR16[]){65,32,114,101,99,111,114,100,32,109,101,109,98,101,114,32,111,102,32,116,104,105,115,32,110,97,109,101,32,97,108,114,101,97,100,121,32,101,120,105,115,116,115,0}),(void*)(OOC_INT32)t,128);
    goto l12;
  case 3:
    _copy_16((const void*)((OOC_CHAR16[]){84,104,105,115,32,110,97,109,101,32,105,115,32,97,108,114,101,97,100,121,32,100,101,102,105,110,101,100,32,105,110,32,116,104,101,32,114,101,99,111,114,100,39,115,32,98,97,115,101,32,116,121,112,101,0}),(void*)(OOC_INT32)t,128);
    goto l12;
  case 4:
    _copy_16((const void*)((OOC_CHAR16[]){65,32,102,105,101,108,100,32,111,102,32,116,104,105,115,32,110,97,109,101,32,105,115,32,97,108,114,101,97,100,121,32,100,101,102,105,110,101,100,32,102,111,114,32,116,104,101,32,98,97,115,101,32,116,121,112,101,0}),(void*)(OOC_INT32)t,128);
    goto l12;
  case 5:
    _copy_16((const void*)((OOC_CHAR16[]){77,117,115,116,32,98,101,32,101,120,112,111,114,116,101,100,32,108,105,107,101,32,105,110,104,101,114,105,116,101,100,32,100,101,99,108,97,114,97,116,105,111,110,0}),(void*)(OOC_INT32)t,128);
    goto l12;
  case 6:
    _copy_16((const void*)((OOC_CHAR16[]){70,111,114,109,97,108,32,112,97,114,97,109,101,116,101,114,115,32,100,111,110,39,116,32,109,97,116,99,104,32,105,110,104,101,114,105,116,101,100,32,100,101,99,108,97,114,97,116,105,111,110,0}),(void*)(OOC_INT32)t,128);
    goto l12;
  case 7:
    _copy_16((const void*)((OOC_CHAR16[]){84,104,105,115,32,112,114,111,99,101,100,117,114,101,32,114,101,100,101,102,105,110,101,115,32,97,32,112,114,111,99,101,100,117,114,101,32,116,104,97,116,32,105,115,32,100,101,99,108,97,114,101,100,32,108,97,116,101,114,0}),(void*)(OOC_INT32)t,128);
    goto l12;
  case 8:
    _copy_16((const void*)((OOC_CHAR16[]){84,104,105,115,32,115,116,97,116,105,99,32,116,121,112,101,45,98,111,117,110,100,32,112,114,111,99,101,100,117,114,101,32,109,117,115,116,32,98,101,32,101,120,112,111,114,116,101,100,0}),(void*)(OOC_INT32)t,128);
    goto l12;
  case 9:
    _copy_16((const void*)((OOC_CHAR16[]){84,104,105,115,32,109,117,115,116,32,98,101,32,97,32,110,111,110,45,102,117,110,99,116,105,111,110,32,112,114,111,99,101,100,117,114,101,0}),(void*)(OOC_INT32)t,128);
    goto l12;
  default:
    _failed_case(i1, 3163);
    goto l12;
  }
l12:
  i1 = (OOC_INT32)context;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3998)))), OOC_Error__ContextDesc_BaseTemplate)),OOC_Error__ContextDesc_BaseTemplate)((OOC_Error__Context)i1, (Msg__Msg)i0, (void*)(OOC_INT32)t, 128, (void*)(OOC_INT32)templ, templ_0d);
  return;
  ;
}

static void OOC_SymbolTable_Namespace__InitNamespace(OOC_SymbolTable_Namespace__Namespace ns, OOC_SymbolTable__DeclarationArray da, OOC_INT32 len) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)ns;
  OOC_SymbolTable__InitNamespace((OOC_SymbolTable__Namespace)i0);
  i1 = (OOC_INT32)da;
  *(OOC_INT32*)(_check_pointer(i0, 4200)) = i1;
  i1 = len;
  *(OOC_INT32*)((_check_pointer(i0, 4225))+4) = i1;
  return;
  ;
}

OOC_SymbolTable__Declaration OOC_SymbolTable_Namespace__NamespaceDesc_IdentifyLocal2(OOC_SymbolTable_Namespace__Namespace ns, OOC_SymbolTable__Item sourceContext, OOC_SymbolTable__Name name, OOC_CHAR8 ignorePosition, OOC_CHAR8 *baseNotExported) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_INT32 s;
  OOC_INT32 e;
  OOC_INT32 m;
  OOC_SymbolTable__Declaration decl;

  s = 0;
  i0 = (OOC_INT32)ns;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 4789))+4);
  e = i1;
  i2 = 0<i1;
  if (i2) goto l3;
  i2=i1;i1=0;
  goto l13;
l3:
  i2 = (OOC_INT32)name;
  i3=i1;i1=0;
l4_loop:
  i4 = (i1+i3)>>1;
  m = i4;
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4860));
  i5 = _check_pointer(i5, 4871);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 4871))*4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 4874))+20);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 4880))+12);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 4893))+12);
  i5 = (
  _cmp8((const void*)(_check_pointer(i5, 4885)),(const void*)(_check_pointer(i6, 4898))))<0;
  if (i5) goto l7;
  e = i4;
  i3=i4;
  goto l8;
l7:
  i1 = i4+1;
  s = i1;
  
l8:
  i4 = i1<i3;
  if (i4) goto l4_loop;
l12:
  i2=i3;
l13:
  _assert((i1==i2), 127, 4972);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 5002))+4);
  i2 = i1<i2;
  if (i2) goto l16;
  i2=0u;
  goto l18;
l16:
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5021));
  i2 = _check_pointer(i2, 5032);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i1, i3, OOC_UINT32, 5032))*4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 5035))+20);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 5041))+12);
  i3 = (OOC_INT32)name;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 5054))+12);
  i2 = (
  _cmp8((const void*)(_check_pointer(i2, 5046)),(const void*)(_check_pointer(i3, 5059))))==0;
  
l18:
  if (i2) goto l20;
  return (OOC_SymbolTable__Declaration)0;
  goto l37;
l20:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5083));
  i0 = _check_pointer(i0, 5094);
  i2 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(i1, i2, OOC_UINT32, 5094))*4);
  decl = (OOC_SymbolTable__Declaration)i0;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5113)))), OOC_SymbolTable__ItemDesc_Module)),OOC_SymbolTable__ItemDesc_Module)((OOC_SymbolTable__Item)i0);
  i2 = (OOC_INT32)sourceContext;
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 5139)))), OOC_SymbolTable__ItemDesc_Module)),OOC_SymbolTable__ItemDesc_Module)((OOC_SymbolTable__Item)i2);
  i1 = i1==i2;
  if (i1) goto l27;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 5385))+28);
  i1 = i1==0;
  if (!i1) goto l36;
  *baseNotExported = 1u;
  i0=0;
  goto l36;
l27:
  i1 = (OOC_INT32)name;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 5284))+24);
  i1 = *(OOC_INT32*)(_check_pointer(i1, 5304));
  i1 = i2>i1;
  if (i1) goto l30;
  i1=0u;
  goto l32;
l30:
  i1 = ignorePosition;
  i1 = !i1;
  
l32:
  if (!i1) goto l36;
  i0=0;
l36:
  return (OOC_SymbolTable__Declaration)i0;
l37:
  _failed_function(4293); return 0;
  ;
}

OOC_SymbolTable__Declaration OOC_SymbolTable_Namespace__NamespaceDesc_Identify2(OOC_SymbolTable_Namespace__Namespace ns, OOC_SymbolTable__Item sourceContext, OOC_SymbolTable__Name name, OOC_CHAR8 ignorePosition, OOC_CHAR8 *baseNotExported) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)ns;
  i1 = (OOC_INT32)sourceContext;
  i2 = (OOC_INT32)name;
  i3 = ignorePosition;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5952)))), OOC_SymbolTable_Namespace__NamespaceDesc_IdentifyLocal2)),OOC_SymbolTable_Namespace__NamespaceDesc_IdentifyLocal2)((OOC_SymbolTable_Namespace__Namespace)i0, (OOC_SymbolTable__Item)i1, (OOC_SymbolTable__Name)i2, i3, (void*)(OOC_INT32)baseNotExported);
  return (OOC_SymbolTable__Declaration)i0;
  ;
}

static void OOC_SymbolTable_Namespace__ErrDecl(OOC_INT32 code, OOC_SymbolTable__Declaration decl, OOC_Error__List errList) {
  register OOC_INT32 i0,i1,i2;
  Msg__Msg lastError;

  i0 = (OOC_INT32)OOC_SymbolTable_Namespace__namespaceContext;
  i1 = code;
  i0 = (OOC_INT32)OOC_Error__New((OOC_Error__Context)i0, i1);
  lastError = (Msg__Msg)i0;
  i1 = (OOC_INT32)decl;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6256))+20);
  i2 = *(OOC_INT32*)(_check_pointer(i2, 6262));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6229)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i0, "pos", 4, i2);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6311))+20);
  i2 = *(OOC_INT32*)((_check_pointer(i2, 6317))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6283)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i0, "line", 5, i2);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6369))+20);
  i1 = *(OOC_INT32*)((_check_pointer(i1, 6375))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6339)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i0, "column", 7, i1);
  i1 = (OOC_INT32)errList;
  OOC_Error__ListDesc_Append((OOC_Error__List)i1, (Msg__Msg)i0);
  return;
  ;
}

void OOC_SymbolTable_Namespace__NamespaceDesc_CheckLocalUniqueness(OOC_SymbolTable_Namespace__Namespace ns, OOC_Error__List errList) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11;
  OOC_SymbolTable__DeclarationArray da;
  OOC_INT32 i;
  OOC_INT32 min;
  OOC_INT32 j;
  OOC_INT32 h;

  i0 = (OOC_INT32)ns;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6926));
  da = (OOC_SymbolTable__DeclarationArray)i1;
  i = 0;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 6968))+4);
  i2 = 0<(i2-1);
  if (!i2) goto l51;
  i2 = (OOC_INT32)errList;
  i3=0;
l3_loop:
  i4 = _check_pointer(i1, 6999);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 6999))*4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 7002))+20);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 7008))+12);
  i5 = _check_pointer(i1, 7019);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i7 = i3+1;
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i7, i6, OOC_UINT32, 7019))*4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 7024))+20);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 7030))+12);
  i4 = (
  _cmp8((const void*)(_check_pointer(i4, 7013)),(const void*)(_check_pointer(i5, 7035))))==0;
  if (!i4) goto l46;
  min = i3;
  j = i7;
  i4 = *(OOC_INT32*)((_check_pointer(i0, 7255))+4);
  i4 = i7<i4;
  if (i4) goto l8;
  i4=0u;
  goto l10;
l8:
  i4 = _check_pointer(i1, 7289);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 7289))*4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 7292))+20);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 7298))+12);
  i5 = _check_pointer(i1, 7309);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i7, i6, OOC_UINT32, 7309))*4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 7312))+20);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 7318))+12);
  i4 = (
  _cmp8((const void*)(_check_pointer(i4, 7303)),(const void*)(_check_pointer(i5, 7323))))==0;
  
l10:
  if (i4) goto l12;
  i4=i7;i5=i3;
  goto l26;
l12:
  i4=i7;i5=i3;
l13_loop:
  i6 = _check_pointer(i1, 7345);
  i8 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i4, i8, OOC_UINT32, 7345))*4);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 7348))+20);
  i8 = _check_pointer(i1, 7364);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i8 = (OOC_INT32)*(OOC_INT32*)(i8+(_check_index(i5, i9, OOC_UINT32, 7364))*4);
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i8, 7369))+20);
  i8 = *(OOC_INT32*)(_check_pointer(i8, 7375));
  i6 = *(OOC_INT32*)(_check_pointer(i6, 7354));
  i6 = i6<i8;
  if (!i6) goto l17;
  min = i4;
  i5=i4;
l17:
  i4 = i4+1;
  j = i4;
  i6 = *(OOC_INT32*)((_check_pointer(i0, 7255))+4);
  i6 = i4<i6;
  if (i6) goto l20;
  i6=0u;
  goto l22;
l20:
  i6 = _check_pointer(i1, 7289);
  i8 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i3, i8, OOC_UINT32, 7289))*4);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 7292))+20);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 7298))+12);
  i8 = _check_pointer(i1, 7309);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i8 = (OOC_INT32)*(OOC_INT32*)(i8+(_check_index(i4, i9, OOC_UINT32, 7309))*4);
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i8, 7312))+20);
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i8, 7318))+12);
  i6 = (
  _cmp8((const void*)(_check_pointer(i6, 7303)),(const void*)(_check_pointer(i8, 7323))))==0;
  
l22:
  if (i6) goto l13_loop;
l26:
  h = i3;
  i6 = i3<i4;
  if (!i6) goto l37;
  i6=i3;
l29_loop:
  i8 = i6!=i5;
  if (!i8) goto l32;
  i8 = _check_pointer(i1, 7620);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i8 = (OOC_INT32)*(OOC_INT32*)(i8+(_check_index(i6, i9, OOC_UINT32, 7620))*4);
  OOC_SymbolTable_Namespace__ErrDecl(1, (OOC_SymbolTable__Declaration)i8, (OOC_Error__List)i2);
l32:
  i6 = i6+1;
  h = i6;
  i8 = i6<i4;
  if (i8) goto l29_loop;
l37:
  i6 = _check_pointer(i1, 7735);
  i8 = OOC_ARRAY_LENGTH(i6, 0);
  i9 = _check_pointer(i1, 7744);
  i10 = OOC_ARRAY_LENGTH(i9, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i9+(_check_index(i5, i10, OOC_UINT32, 7744))*4);
  *(OOC_INT32*)(i6+(_check_index(i3, i8, OOC_UINT32, 7735))*4) = i5;
  i4 = (i4-i3)-1;
  h = i4;
  i3 = i3+(i4+1);
  j = i3;
  i5 = *(OOC_INT32*)((_check_pointer(i0, 7801))+4);
  i6 = i3<i5;
  if (!i6) goto l45;
  i6 = (i4*(-1))+i3;
  
l40_loop:
  i8 = _check_pointer(i1, 7831);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i10 = _check_pointer(i1, 7842);
  i11 = OOC_ARRAY_LENGTH(i10, 0);
  i10 = (OOC_INT32)*(OOC_INT32*)(i10+(_check_index(i3, i11, OOC_UINT32, 7842))*4);
  *(OOC_INT32*)(i8+(_check_index(i6, i9, OOC_UINT32, 7831))*4) = i10;
  i3 = i3+1;
  j = i3;
  i6 = i6+1;
  i8 = i3<i5;
  if (i8) goto l40_loop;
l45:
  i3 = *(OOC_INT32*)((_check_pointer(i0, 7874))+4);
  *(OOC_INT32*)((_check_pointer(i0, 7874))+4) = (i3-i4);
l46:
  i = i7;
  i3 = *(OOC_INT32*)((_check_pointer(i0, 6968))+4);
  i3 = i7<(i3-1);
  if (!i3) goto l51;
  i3=i7;
  goto l3_loop;
l51:
  return;
  ;
}

static void OOC_SymbolTable_Namespace__InitNested(OOC_SymbolTable_Namespace__Nested ns, OOC_SymbolTable__DeclarationArray da, OOC_INT32 len) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)ns;
  i1 = (OOC_INT32)da;
  i2 = len;
  OOC_SymbolTable_Namespace__InitNamespace((OOC_SymbolTable_Namespace__Namespace)i0, (OOC_SymbolTable__DeclarationArray)i1, i2);
  *(OOC_INT32*)((_check_pointer(i0, 8109))+8) = (OOC_INT32)0;
  return;
  ;
}

OOC_SymbolTable_Namespace__Nested OOC_SymbolTable_Namespace__NewNested(OOC_SymbolTable__DeclarationArray da, OOC_INT32 len) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SymbolTable_Namespace__Nested.baseTypes[0]);
  i1 = (OOC_INT32)da;
  i2 = len;
  OOC_SymbolTable_Namespace__InitNested((OOC_SymbolTable_Namespace__Nested)i0, (OOC_SymbolTable__DeclarationArray)i1, i2);
  return (OOC_SymbolTable_Namespace__Nested)i0;
  ;
}

void OOC_SymbolTable_Namespace__NestedDesc_SetEnclosingNamespace(OOC_SymbolTable_Namespace__Nested ns, OOC_SymbolTable_Namespace__Namespace ns0) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)ns;
  i1 = (OOC_INT32)ns0;
  *(OOC_INT32*)((_check_pointer(i0, 8469))+8) = i1;
  return;
  ;
}

OOC_SymbolTable__Declaration OOC_SymbolTable_Namespace__NestedDesc_IdentifyLocal2(OOC_SymbolTable_Namespace__Nested ns, OOC_SymbolTable__Item sourceContext, OOC_SymbolTable__Name name, OOC_CHAR8 ignorePosition, OOC_CHAR8 *baseNotExported) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)ns;
  i1 = (OOC_INT32)sourceContext;
  i2 = (OOC_INT32)name;
  i3 = ignorePosition;
  i0 = (OOC_INT32)OOC_SymbolTable_Namespace__NamespaceDesc_IdentifyLocal2((OOC_SymbolTable_Namespace__Namespace)i0, (OOC_SymbolTable__Item)i1, (OOC_SymbolTable__Name)i2, i3, (void*)(OOC_INT32)baseNotExported);
  return (OOC_SymbolTable__Declaration)i0;
  ;
}

OOC_SymbolTable__Declaration OOC_SymbolTable_Namespace__NestedDesc_Identify2(OOC_SymbolTable_Namespace__Nested ns, OOC_SymbolTable__Item sourceContext, OOC_SymbolTable__Name name, OOC_CHAR8 ignorePosition, OOC_CHAR8 *baseNotExported) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_SymbolTable__Declaration decl;

  i0 = (OOC_INT32)ns;
  i1 = (OOC_INT32)sourceContext;
  i2 = (OOC_INT32)name;
  i3 = ignorePosition;
  i4 = (OOC_INT32)OOC_SymbolTable_Namespace__NestedDesc_IdentifyLocal2((OOC_SymbolTable_Namespace__Nested)i0, (OOC_SymbolTable__Item)i1, (OOC_SymbolTable__Name)i2, i3, (void*)(OOC_INT32)baseNotExported);
  decl = (OOC_SymbolTable__Declaration)i4;
  i5 = i4==(OOC_INT32)0;
  if (i5) goto l3;
  i5=0u;
  goto l5;
l3:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9305))+8);
  i5 = i5!=(OOC_INT32)0;
  
l5:
  if (i5) goto l7;
  i0=i4;
  goto l8;
l7:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9344))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9344))+8);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 9354)))), OOC_SymbolTable_Namespace__NamespaceDesc_Identify2)),OOC_SymbolTable_Namespace__NamespaceDesc_Identify2)((OOC_SymbolTable_Namespace__Namespace)i0, (OOC_SymbolTable__Item)i1, (OOC_SymbolTable__Name)i2, i3, (void*)(OOC_INT32)baseNotExported);
  
l8:
  return (OOC_SymbolTable__Declaration)i0;
  ;
}

static void OOC_SymbolTable_Namespace__InitExtended(OOC_SymbolTable_Namespace__Extended ns, OOC_SymbolTable__DeclarationArray da, OOC_INT32 len) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)ns;
  i1 = (OOC_INT32)da;
  i2 = len;
  OOC_SymbolTable_Namespace__InitNamespace((OOC_SymbolTable_Namespace__Namespace)i0, (OOC_SymbolTable__DeclarationArray)i1, i2);
  *(OOC_INT32*)((_check_pointer(i0, 9653))+8) = (OOC_INT32)0;
  return;
  ;
}

OOC_SymbolTable_Namespace__Namespace OOC_SymbolTable_Namespace__NewExtended(OOC_SymbolTable__DeclarationArray da, OOC_INT32 len) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SymbolTable_Namespace__Extended.baseTypes[0]);
  i1 = (OOC_INT32)da;
  i2 = len;
  OOC_SymbolTable_Namespace__InitExtended((OOC_SymbolTable_Namespace__Extended)i0, (OOC_SymbolTable__DeclarationArray)i1, i2);
  return (OOC_SymbolTable_Namespace__Namespace)i0;
  ;
}

void OOC_SymbolTable_Namespace__ExtendedDesc_SetBaseNamespace(OOC_SymbolTable_Namespace__Extended ns, OOC_SymbolTable_Namespace__Namespace ns0) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)ns;
  i1 = (OOC_INT32)ns0;
  *(OOC_INT32*)((_check_pointer(i0, 10017))+8) = i1;
  return;
  ;
}

OOC_SymbolTable__Declaration OOC_SymbolTable_Namespace__ExtendedDesc_IdentifyLocal2(OOC_SymbolTable_Namespace__Extended ns, OOC_SymbolTable__Item sourceContext, OOC_SymbolTable__Name name, OOC_CHAR8 ignorePosition, OOC_CHAR8 *baseNotExported) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)ns;
  i1 = (OOC_INT32)sourceContext;
  i2 = (OOC_INT32)name;
  i3 = ignorePosition;
  i0 = (OOC_INT32)OOC_SymbolTable_Namespace__NamespaceDesc_IdentifyLocal2((OOC_SymbolTable_Namespace__Namespace)i0, (OOC_SymbolTable__Item)i1, (OOC_SymbolTable__Name)i2, i3, (void*)(OOC_INT32)baseNotExported);
  return (OOC_SymbolTable__Declaration)i0;
  ;
}

OOC_SymbolTable__Declaration OOC_SymbolTable_Namespace__ExtendedDesc_Identify2(OOC_SymbolTable_Namespace__Extended ns, OOC_SymbolTable__Item sourceContext, OOC_SymbolTable__Name name, OOC_CHAR8 ignorePosition, OOC_CHAR8 *baseNotExported) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_SymbolTable__Declaration decl;

  i0 = (OOC_INT32)ns;
  i1 = (OOC_INT32)sourceContext;
  i2 = (OOC_INT32)name;
  i3 = ignorePosition;
  i4 = (OOC_INT32)OOC_SymbolTable_Namespace__ExtendedDesc_IdentifyLocal2((OOC_SymbolTable_Namespace__Extended)i0, (OOC_SymbolTable__Item)i1, (OOC_SymbolTable__Name)i2, i3, (void*)(OOC_INT32)baseNotExported);
  decl = (OOC_SymbolTable__Declaration)i4;
  i5 = i4==(OOC_INT32)0;
  if (i5) goto l3;
  i5=0u;
  goto l5;
l3:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10863))+8);
  i5 = i5!=(OOC_INT32)0;
  
l5:
  if (i5) goto l7;
  i0=i4;
  goto l8;
l7:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10901))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10901))+8);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 10910)))), OOC_SymbolTable_Namespace__NamespaceDesc_Identify2)),OOC_SymbolTable_Namespace__NamespaceDesc_Identify2)((OOC_SymbolTable_Namespace__Namespace)i0, (OOC_SymbolTable__Item)i1, (OOC_SymbolTable__Name)i2, i3, (void*)(OOC_INT32)baseNotExported);
  
l8:
  return (OOC_SymbolTable__Declaration)i0;
  ;
}

void OOC_SymbolTable_Namespace__ExtendedDesc_InsertTBProc(OOC_SymbolTable_Namespace__Extended ns, OOC_SymbolTable__ProcDecl procDecl, OOC_Error__List errList) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
  OOC_INT32 s;
  OOC_INT32 e;
  OOC_INT32 m;
  OOC_SymbolTable__DeclarationArray n;
  OOC_INT32 i;

  i0 = (OOC_INT32)ns;
  i1 = (OOC_INT32)procDecl;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11638))+20);
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11603)))), OOC_SymbolTable__NamespaceDesc_IdentifyLocal)),OOC_SymbolTable__NamespaceDesc_IdentifyLocal)((OOC_SymbolTable__Namespace)i0, (OOC_SymbolTable__Item)i1, (OOC_SymbolTable__Name)i2, 0u);
  i2 = i2!=(OOC_INT32)0;
  if (i2) goto l35;
  s = 0;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 11752))+4);
  e = i2;
  i3 = 0<i2;
  if (i3) goto l5;
  i3=i2;i2=0;
  goto l15;
l5:
  i3=i2;i2=0;
l6_loop:
  i4 = (i2+i3)>>1;
  m = i4;
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 11829));
  i5 = _check_pointer(i5, 11840);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 11840))*4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 11843))+20);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 11849))+12);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11866))+20);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 11872))+12);
  i5 = (
  _cmp8((const void*)(_check_pointer(i5, 11854)),(const void*)(_check_pointer(i6, 11877))))<0;
  if (i5) goto l9;
  e = i4;
  i3=i4;
  goto l10;
l9:
  i2 = i4+1;
  s = i2;
  
l10:
  i4 = i2<i3;
  if (i4) goto l6_loop;
l15:
  _assert((i2==i3), 127, 11970);
  i3 = *(OOC_INT32*)((_check_pointer(i0, 12002))+4);
  i3 = i2<i3;
  if (!i3) goto l18;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 12039));
  i3 = _check_pointer(i3, 12050);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 12050))*4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 12053))+20);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 12059))+12);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12076))+20);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 12082))+12);
  _assert(((
  _cmp8((const void*)(_check_pointer(i3, 12064)),(const void*)(_check_pointer(i4, 12087))))>0), 127, 12029);
l18:
  i3 = *(OOC_INT32*)((_check_pointer(i0, 12124))+4);
  i3 = (OOC_INT32)RT0__NewObject(_td_OOC_SymbolTable__DeclarationArray.baseTypes[0], (i3+1));
  n = (OOC_SymbolTable__DeclarationArray)i3;
  i = 0;
  i4 = 0<i2;
  if (!i4) goto l26;
  i4=0;
l21_loop:
  i5 = _check_pointer(i3, 12177);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 12186));
  i7 = _check_pointer(i7, 12197);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i4, i8, OOC_UINT32, 12197))*4);
  *(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 12177))*4) = i7;
  i4 = i4+1;
  i = i4;
  i5 = i4<i2;
  if (i5) goto l21_loop;
l26:
  i4 = _check_pointer(i3, 12219);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  *(OOC_INT32*)(i4+(_check_index(i2, i5, OOC_UINT32, 12219))*4) = i1;
  i = i2;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 12258))+4);
  i4 = i2<i1;
  if (!i4) goto l34;
l29_loop:
  i4 = _check_pointer(i3, 12285);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = i2+1;
  i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 12296));
  i7 = _check_pointer(i7, 12307);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i2, i8, OOC_UINT32, 12307))*4);
  *(OOC_INT32*)(i4+(_check_index(i6, i5, OOC_UINT32, 12285))*4) = i2;
  i = i6;
  i2 = i6<i1;
  if (!i2) goto l34;
  i2=i6;
  goto l29_loop;
l34:
  *(OOC_INT32*)(_check_pointer(i0, 12337)) = i3;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 12368))+4);
  *(OOC_INT32*)((_check_pointer(i0, 12368))+4) = (i1+1);
  goto l36;
l35:
  i0 = (OOC_INT32)errList;
  OOC_SymbolTable_Namespace__ErrDecl(2, (OOC_SymbolTable__Declaration)i1, (OOC_Error__List)i0);
l36:
  return;
  ;
}

OOC_SymbolTable__ProcDecl OOC_SymbolTable_Namespace__ExtendedDesc_GetTBProcByIndex(OOC_SymbolTable_Namespace__Extended ns, OOC_INT32 index) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 i;
  OOC_SymbolTable__Declaration decl;

  i0 = (OOC_INT32)ns;
  i = 0;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 12742))+4);
  i2 = 0<i1;
  if (!i2) goto l14;
  i2 = index;
  i3=0;
l3_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 12776));
  i4 = _check_pointer(i4, 12787);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 12787))*4);
  decl = (OOC_SymbolTable__Declaration)i4;
  i5 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 12807)))), &_td_OOC_SymbolTable__ProcDeclDesc);
  if (!i5) goto l9;
  i5 = *(OOC_INT32*)((_check_pointer(i4, 12841))+56);
  i5 = i5==i2;
  if (!i5) goto l9;
  return (OOC_SymbolTable__ProcDecl)i4;
l9:
  i3 = i3+1;
  i = i3;
  i4 = i3<i1;
  if (i4) goto l3_loop;
l14:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12960))+8);
  i1 = i1==0;
  if (i1) goto l17;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13024))+8);
  i1 = index;
  i0 = (OOC_INT32)OOC_SymbolTable_Namespace__ExtendedDesc_GetTBProcByIndex((OOC_SymbolTable_Namespace__Extended)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13034)))), &_td_OOC_SymbolTable_Namespace__ExtendedDesc, 13034)), i1);
  return (OOC_SymbolTable__ProcDecl)i0;
  goto l18;
l17:
  return (OOC_SymbolTable__ProcDecl)0;
l18:
  _failed_function(12436); return 0;
  ;
}

OOC_SymbolTable__ProcDecl OOC_SymbolTable_Namespace__ExtendedDesc_GetSuperProcByIndex(OOC_SymbolTable_Namespace__Extended ns, OOC_INT32 index) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)ns;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13330))+8);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l3;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13394))+8);
  i1 = index;
  i0 = (OOC_INT32)OOC_SymbolTable_Namespace__ExtendedDesc_GetTBProcByIndex((OOC_SymbolTable_Namespace__Extended)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13404)))), &_td_OOC_SymbolTable_Namespace__ExtendedDesc, 13404)), i1);
  return (OOC_SymbolTable__ProcDecl)i0;
  goto l4;
l3:
  return (OOC_SymbolTable__ProcDecl)(OOC_INT32)0;
l4:
  _failed_function(13130); return 0;
  ;
}

void OOC_SymbolTable_Namespace__ExtendedDesc_CheckRestrictions(OOC_SymbolTable_Namespace__Extended ns, OOC_SymbolTable__Record record, OOC_SymbolTable_Uses__Uses uses, OOC_Error__List errList) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11,i12,i13,i14,i15;
  OOC_INT32 i;
  OOC_SymbolTable__Declaration decl;
  OOC_CHAR8 baseNotExported;
  OOC_SymbolTable__Declaration base;
  OOC_SymbolTable__Type rec;
  OOC_SymbolTable__TypeRefArray args;
  OOC_INT32 j;
  OOC_SymbolTable__QualType qualType;
  OOC_SymbolTable__Type ptr;
  OOC_SymbolTable__Type baseFormalPars;

  i0 = (OOC_INT32)ns;
  i = 0;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 14212))+4);
  i2 = 0<i1;
  if (!i2) goto l93;
  i2 = (OOC_INT32)errList;
  i3 = (OOC_INT32)&_td_OOC_SymbolTable__TypeRef;
  i4 = (OOC_INT32)uses;
  i5=0;
l3_loop:
  i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14246));
  i6 = _check_pointer(i6, 14257);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i5, i7, OOC_UINT32, 14257))*4);
  decl = (OOC_SymbolTable__Declaration)i6;
  i7 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 14277)))), &_td_OOC_SymbolTable__FieldDeclDesc);
  if (i7) goto l80;
  i7 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 14655)))), &_td_OOC_SymbolTable__ProcDeclDesc);
  if (i7) goto l8;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 14649)))), 14649);
  goto l88;
l8:
  baseNotExported = 0u;
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14721))+8);
  i7 = i7==0;
  if (i7) goto l11;
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14798))+8);
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14798))+8);
  i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 14829))+20);
  i7 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 14807)))), OOC_SymbolTable__NamespaceDesc_Identify)),OOC_SymbolTable__NamespaceDesc_Identify)((OOC_SymbolTable__Namespace)i8, (OOC_SymbolTable__Item)i6, (OOC_SymbolTable__Name)i9, 1u);
  base = (OOC_SymbolTable__Declaration)i7;
  
  goto l12;
l11:
  base = (OOC_SymbolTable__Declaration)0;
  i7=0;
l12:
  i8 = i7!=0;
  if (!i8) goto l88;
  i8 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 14905)))), &_td_OOC_SymbolTable__FieldDeclDesc);
  if (i8) goto l76;
  i8 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 14999)))), &_td_OOC_SymbolTable__ProcDeclDesc);
  if (i8) goto l19;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 14993)))), 14993);
  goto l88;
l19:
  i8 = *(OOC_INT8*)((_check_pointer(i6, 15037))+28);
  i9 = *(OOC_INT8*)((_check_pointer(i7, 15056))+28);
  i8 = i8!=i9;
  if (!i8) goto l22;
  OOC_SymbolTable_Namespace__ErrDecl(5, (OOC_SymbolTable__Declaration)i6, (OOC_Error__List)i2);
l22:
  i8 = (OOC_INT32)OOC_SymbolTable__ProcDeclDesc_Class((OOC_SymbolTable__ProcDecl)i6);
  rec = (OOC_SymbolTable__Type)i8;
  i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i8, 15204))+28);
  i9 = i9!=0;
  if (i9) goto l25;
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i7, 15972))+64);
  baseFormalPars = (OOC_SymbolTable__Type)i8;
  
  goto l43;
l25:
  i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i8, 15374))+28);
  i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i9, 15383))+20);
  i9 = OOC_ARRAY_LENGTH((_check_pointer(i9, 15390)), 0);
  i9 = (OOC_INT32)RT0__NewObject(_td_OOC_SymbolTable__TypeRefArray.baseTypes[0], i9);
  args = (OOC_SymbolTable__TypeRefArray)i9;
  j = 0;
  i10 = OOC_ARRAY_LENGTH((_check_pointer(i9, 15431)), 0);
  i11 = 0<i10;
  if (!i11) goto l33;
  i11=0;
l28_loop:
  i12 = _check_pointer(i9, 15475);
  i13 = OOC_ARRAY_LENGTH(i12, 0);
  i14 = OOC_ARRAY_LENGTH((_check_pointer(i9, 15475)), 0);
  i14 = _check_index(i11, i14, OOC_UINT32, 15475);
  i14 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i8, 15483))+28);
  i14 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i14, 15492))+20);
  i14 = _check_pointer(i14, 15499);
  i15 = OOC_ARRAY_LENGTH(i14, 0);
  i14 = (OOC_INT32)*(OOC_INT32*)(i14+(_check_index(i11, i15, OOC_UINT32, 15499))*4);
  OOC_SymbolTable__InitTypeRef((void*)(i12+(_check_index(i11, i13, OOC_UINT32, 15475))*8), (RT0__Struct)i3, (OOC_SymbolTable__Type)i14);
  i11 = i11+1;
  j = i11;
  i12 = i11<i10;
  if (i12) goto l28_loop;
l33:
  i10 = (OOC_INT32)RT0__NewObject(_td_OOC_SymbolTable__QualType.baseTypes[0]);
  qualType = (OOC_SymbolTable__QualType)i10;
  i11 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i8, 15617))+20);
  OOC_SymbolTable__InitQualType((OOC_SymbolTable__QualType)i10, (OOC_SymbolTable__Item)0, (OOC_SymbolTable__Position)i11, (OOC_SymbolTable__Type)i8, (OOC_SymbolTable__TypeRefArray)i9);
  i8 = (OOC_INT32)OOC_SymbolTable__Expand((OOC_SymbolTable__Type)i10);
  rec = (OOC_SymbolTable__Type)i8;
  i9 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i8, 15708)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i8);
  i10 = (OOC_INT32)OOC_SymbolTable__ProcDeclDesc_Class((OOC_SymbolTable__ProcDecl)i7);
  i9 = i9!=i10;
  if (!i9) goto l42;
l37_loop:
  i9 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i8, 15764)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i8);
  ptr = (OOC_SymbolTable__Type)i9;
  i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i9, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i9, 15819)))), &_td_OOC_SymbolTable__RecordDesc, 15819)), 15826))+40);
  i8 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i8, 15802)))), OOC_SymbolTable__TypeDesc_Closure)),OOC_SymbolTable__TypeDesc_Closure)((OOC_SymbolTable__Type)i8, (OOC_SymbolTable__Type)i9);
  rec = (OOC_SymbolTable__Type)i8;
  i9 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i8, 15708)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i8);
  i10 = (OOC_INT32)OOC_SymbolTable__ProcDeclDesc_Class((OOC_SymbolTable__ProcDecl)i7);
  i9 = i9!=i10;
  if (i9) goto l37_loop;
l42:
  i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i7, 15905))+64);
  i8 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i8, 15892)))), OOC_SymbolTable__TypeDesc_Closure)),OOC_SymbolTable__TypeDesc_Closure)((OOC_SymbolTable__Type)i8, (OOC_SymbolTable__Type)i9);
  baseFormalPars = (OOC_SymbolTable__Type)i8;
  
l43:
  i9 = *(OOC_INT8*)((_check_pointer(i6, 16035))+48);
  i9 = i9==2;
  if (i9) goto l46;
  i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 16127))+64);
  i8 = OOC_SymbolTable_TypeRules__IsValidRedefinition((OOC_SymbolTable__Type)i8, (OOC_SymbolTable__FormalPars)i9);
  
  goto l48;
l46:
  i8=1u;
l48:
  if (i8) goto l50;
  OOC_SymbolTable_Namespace__ErrDecl(6, (OOC_SymbolTable__Declaration)i6, (OOC_Error__List)i2);
  goto l88;
l50:
  i8 = *(OOC_UINT8*)((_check_pointer(i7, 16166))+51);
  if (!i8) goto l53;
  *(OOC_UINT8*)((_check_pointer(i7, 16205))+51) = 0u;
l53:
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 16270))+20);
  i9 = *(OOC_INT32*)((_check_pointer(i7, 16288))+24);
  i8 = *(OOC_INT32*)(_check_pointer(i8, 16276));
  i8 = i8<i9;
  if (!i8) goto l56;
  OOC_SymbolTable_Namespace__ErrDecl(7, (OOC_SymbolTable__Declaration)i6, (OOC_Error__List)i2);
l56:
  i8 = *(OOC_INT8*)((_check_pointer(i6, 16413))+48);
  i8 = i8==2;
  if (!i8) goto l69;
  i8 = *(OOC_INT8*)((_check_pointer(i6, 16473))+28);
  i8 = i8==0;
  if (!i8) goto l61;
  OOC_SymbolTable_Namespace__ErrDecl(8, (OOC_SymbolTable__Declaration)i6, (OOC_Error__List)i2);
l61:
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 16626))+20);
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i8, 16631))+12);
  i8 = (
  _cmp8((const void*)(_check_pointer(i8, 16635)),(const void*)"INIT"))==0;
  if (i8) goto l64;
  i8=0u;
  goto l66;
l64:
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 16684))+64);
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i8, 16695))+44);
  i8 = i8!=0;
  
l66:
  if (!i8) goto l69;
  OOC_SymbolTable_Namespace__ErrDecl(9, (OOC_SymbolTable__Declaration)i6, (OOC_Error__List)i2);
l69:
  i8 = _check_pointer(i6, 16834);
  i9 = *(OOC_UINT8*)((_check_pointer(i6, 16853))+36);
  if (i9) goto l72;
  i9 = *(OOC_UINT8*)((_check_pointer(i7, 16872))+36);
  
  goto l73;
l72:
  i9=1u;
l73:
  *(OOC_UINT8*)(i8+36) = i9;
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 16940))+20);
  OOC_SymbolTable_Uses__Mark((OOC_SymbolTable__Declaration)i7, (OOC_SymbolTable_Uses__Uses)i4, (OOC_SymbolTable__Name)i6);
  goto l88;
l76:
  OOC_SymbolTable_Namespace__ErrDecl(4, (OOC_SymbolTable__Declaration)i6, (OOC_Error__List)i2);
  goto l88;
l80:
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14310))+8);
  i7 = i7!=0;
  if (!i7) goto l88;
  baseNotExported = 0u;
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14388))+8);
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14388))+8);
  i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 14417))+20);
  i7 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 14396)))), OOC_SymbolTable_Namespace__NamespaceDesc_Identify2)),OOC_SymbolTable_Namespace__NamespaceDesc_Identify2)((OOC_SymbolTable_Namespace__Namespace)i8, (OOC_SymbolTable__Item)i6, (OOC_SymbolTable__Name)i9, 1u, (void*)(OOC_INT32)&baseNotExported);
  base = (OOC_SymbolTable__Declaration)i7;
  i7 = i7==0;
  if (i7) goto l85;
  OOC_SymbolTable_Namespace__ErrDecl(3, (OOC_SymbolTable__Declaration)i6, (OOC_Error__List)i2);
  goto l88;
l85:
  i7 = baseNotExported;
  *(OOC_UINT8*)((_check_pointer(i6, 14495))+60) = i7;
l88:
  i5 = i5+1;
  i = i5;
  i6 = i5<i1;
  if (i6) goto l3_loop;
l93:
  return;
  ;
}

void OOC_OOC_SymbolTable_Namespace_init(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SymbolTable_Namespace__ErrorContext.baseTypes[0]);
  OOC_SymbolTable_Namespace__namespaceContext = (OOC_SymbolTable_Namespace__ErrorContext)i0;
  OOC_Error__InitContext((OOC_Error__Context)i0, "OOC:SymbolTable:Namespace", 26);
  return;
  ;
}

/* --- */
