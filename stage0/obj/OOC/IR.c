#include <OOC/IR.d>
#include <__oo2c.h>
#include <setjmp.h>

static void OOC_IR__AppendContext(ADT_StringBuffer__StringBuffer buffer, OOC_SymbolTable__Item item) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)item;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 39794)))), &_td_OOC_SymbolTable__DeclarationDesc);
  if (i1) goto l3;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 39784)))), 39784);
  goto l7;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 39828))+4);
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l6;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 39881))+4);
  i2 = (OOC_INT32)buffer;
  OOC_IR__AppendContext((ADT_StringBuffer__StringBuffer)i2, (OOC_SymbolTable__Item)i1);
l6:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 39932))+20);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 39937))+12);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 39932))+20);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 39937))+12);
  i2 = (OOC_INT32)buffer;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 39941)), 0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 39914)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i2, (void*)(_check_pointer(i0, 39941)), i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 39957)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)),ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)((ADT_StringBuffer__StringBuffer)i2, 46u);
l7:
  return;
  ;
}

Object__String OOC_IR__TypeName(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1,i2;
  ADT_StringBuffer__StringBuffer name;

  i0 = (OOC_INT32)ADT_StringBuffer__New((Object__String)((OOC_INT32)_c0));
  name = (ADT_StringBuffer__StringBuffer)i0;
  i1 = (OOC_INT32)type;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 40354))+4);
  i2 = i2!=(OOC_INT32)0;
  if (!i2) goto l3;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 40401))+4);
  OOC_IR__AppendContext((ADT_StringBuffer__StringBuffer)i0, (OOC_SymbolTable__Item)i2);
l3:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 40427))+24);
  i2 = i2!=(OOC_INT32)0;
  if (i2) goto l26;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 40528)))), &_td_OOC_SymbolTable__PredefTypeDesc);
  if (i2) goto l24;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 40723)))), &_td_OOC_SymbolTable__PointerDesc);
  if (i2) goto l22;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 40786)))), &_td_OOC_SymbolTable__FormalParsDesc);
  if (i2) goto l20;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 40854)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (i2) goto l18;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 40913)))), &_td_OOC_SymbolTable__RecordDesc);
  if (i2) goto l16;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 40906)))), 40906);
  goto l27;
l16:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 40939)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i0, "RECORD", 7);
  goto l27;
l18:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 40879)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i0, "ARRAY", 6);
  goto l27;
l20:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 40816)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i0, "PROCEDURE", 10);
  goto l27;
l22:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 40750)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i0, "POINTER", 8);
  goto l27;
l24:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 40622)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i0, "PredefType(", 12);
  i1 = *(OOC_INT16*)((_check_pointer(i1, 40677))+40);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 40662)))), ADT_StringBuffer__StringBufferDesc_AppendInt)),ADT_StringBuffer__StringBufferDesc_AppendInt)((ADT_StringBuffer__StringBuffer)i0, i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 40693)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i0, ")", 2);
  goto l27;
l26:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 40476))+24);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 40487))+20);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 40492))+12);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 40476))+24);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 40487))+20);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 40492))+12);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 40496)), 0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 40458)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i0, (void*)(_check_pointer(i1, 40496)), i2);
l27:
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 40991)))), ADT_StringBuffer__StringBufferDesc_ToString)),ADT_StringBuffer__StringBufferDesc_ToString)((ADT_StringBuffer__StringBuffer)i0);
  return (Object__String)i0;
  ;
}

static void OOC_IR__LogTypeName(const OOC_CHAR8 message__ref[], OOC_LEN message_0d, OOC_SymbolTable__Type type) {
  register OOC_INT32 i0;
  OOC_ALLOCATE_VPAR(message,OOC_CHAR8 ,message_0d)

  OOC_INITIALIZE_VPAR(message__ref,message,OOC_CHAR8 ,message_0d)
  i0 = (OOC_INT32)type;
  i0 = (OOC_INT32)OOC_IR__TypeName((OOC_SymbolTable__Type)i0);
  Log__Object((void*)(OOC_INT32)message, message_0d, (Object__Object)i0);
  return;
  ;
}

void OOC_IR__ErrorContextDesc_GetTemplate(OOC_IR__ErrorContext context, Msg__Msg msg, Msg__LString templ, OOC_LEN templ_0d) {
  register OOC_INT32 i0,i1;
  OOC_CHAR16 t[128];

  i0 = (OOC_INT32)msg;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 41331))+8);
  switch (i1) {
  case 1:
    _copy_16((const void*)((OOC_CHAR16[]){85,110,100,101,99,108,97,114,101,100,32,105,100,101,110,116,105,102,105,101,114,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 2:
    _copy_16((const void*)((OOC_CHAR16[]){69,120,112,101,99,116,101,100,32,105,100,101,110,116,105,102,105,101,114,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 3:
    _copy_16((const void*)((OOC_CHAR16[]){78,117,109,98,101,114,32,111,117,116,32,111,102,32,114,97,110,103,101,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 4:
    _copy_16((const void*)((OOC_CHAR16[]){67,104,97,114,97,99,116,101,114,32,118,97,108,117,101,32,111,117,116,32,111,102,32,114,97,110,103,101,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 5:
    _copy_16((const void*)((OOC_CHAR16[]){73,110,118,97,108,105,100,32,116,121,112,101,32,102,111,114,32,111,112,101,114,97,116,111,114,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 6:
    _copy_16((const void*)((OOC_CHAR16[]){85,110,107,110,111,119,110,32,111,112,101,114,97,116,111,114,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 7:
    _copy_16((const void*)((OOC_CHAR16[]){73,110,99,111,109,112,97,116,105,98,108,101,32,116,121,112,101,115,32,102,111,114,32,111,112,101,114,97,116,111,114,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 8:
    _copy_16((const void*)((OOC_CHAR16[]){68,105,118,105,115,111,114,32,105,115,32,122,101,114,111,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 9:
    _copy_16((const void*)((OOC_CHAR16[]){69,120,112,114,101,115,115,105,111,110,32,105,115,32,110,111,116,32,99,111,110,115,116,97,110,116,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 10:
    _copy_16((const void*)((OOC_CHAR16[]){86,97,108,117,101,32,111,117,116,32,111,102,32,114,97,110,103,101,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 11:
    _copy_16((const void*)((OOC_CHAR16[]){69,120,112,114,101,115,115,105,111,110,32,109,97,121,32,110,111,116,32,98,101,32,112,97,115,115,101,100,32,98,121,32,114,101,102,101,114,101,110,99,101,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 12:
    _copy_16((const void*)((OOC_CHAR16[]){65,114,103,117,109,101,110,116,32,110,111,116,32,99,111,109,112,97,116,105,98,108,101,32,119,105,116,104,32,102,111,114,109,97,108,32,116,121,112,101,32,96,36,123,110,97,109,101,125,39,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 24:
    _copy_16((const void*)((OOC_CHAR16[]){69,120,112,114,101,115,115,105,111,110,32,110,111,116,32,99,111,109,112,97,116,105,98,108,101,32,119,105,116,104,32,118,97,114,105,97,98,108,101,32,116,121,112,101,32,96,36,123,110,97,109,101,125,39,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 13:
    _copy_16((const void*)((OOC_CHAR16[]){87,114,111,110,103,32,110,117,109,98,101,114,32,111,102,32,97,114,103,117,109,101,110,116,115,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 14:
    _copy_16((const void*)((OOC_CHAR16[]){73,110,116,101,103,101,114,32,99,111,110,115,116,97,110,116,32,105,110,32,116,104,101,32,114,97,110,103,101,32,96,36,123,115,116,97,114,116,125,32,60,61,32,120,32,60,32,36,123,101,110,100,125,39,32,114,101,113,117,105,114,101,100,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 15:
    _copy_16((const void*)((OOC_CHAR16[]){69,120,112,114,101,115,115,105,111,110,32,109,117,115,116,32,98,101,32,97,110,32,97,114,114,97,121,32,118,97,108,117,101,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 16:
    _copy_16((const void*)((OOC_CHAR16[]){84,121,112,101,32,110,97,109,101,32,101,120,112,101,99,116,101,100,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 17:
    _copy_16((const void*)((OOC_CHAR16[]){84,121,112,101,32,109,117,115,116,32,98,101,32,97,110,32,101,120,116,101,110,115,105,111,110,32,111,102,32,116,104,101,32,108,101,102,116,32,111,112,101,114,97,110,100,39,115,32,116,121,112,101,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 18:
    _copy_16((const void*)((OOC_CHAR16[]){77,73,78,47,77,65,88,32,105,115,32,110,111,116,32,97,112,112,108,105,99,97,98,108,101,32,116,111,32,116,104,105,115,32,116,121,112,101,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 19:
    _copy_16((const void*)((OOC_CHAR16[]){69,120,112,114,101,115,115,105,111,110,32,109,117,115,116,32,98,101,32,111,102,32,105,110,116,101,103,101,114,32,116,121,112,101,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 20:
    _copy_16((const void*)((OOC_CHAR16[]){69,120,112,114,101,115,115,105,111,110,32,109,117,115,116,32,98,101,32,111,102,32,114,101,99,111,114,100,32,116,121,112,101,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 21:
    _copy_16((const void*)((OOC_CHAR16[]){69,120,112,114,101,115,115,105,111,110,32,109,117,115,116,32,98,101,32,111,102,32,112,111,105,110,116,101,114,32,116,121,112,101,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 22:
    _copy_16((const void*)((OOC_CHAR16[]){69,120,112,114,101,115,115,105,111,110,32,109,117,115,116,32,98,101,32,111,102,32,116,121,112,101,32,66,79,79,76,69,65,78,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 23:
    _copy_16((const void*)((OOC_CHAR16[]){79,112,101,114,97,116,111,114,32,109,97,121,32,110,111,116,32,98,101,32,97,112,112,108,105,101,100,32,116,111,32,102,117,110,99,116,105,111,110,32,114,101,115,117,108,116,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 25:
    _copy_16((const void*)((OOC_CHAR16[]){69,88,73,84,32,111,117,116,115,105,100,101,32,111,102,32,76,79,79,80,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 26:
    _copy_16((const void*)((OOC_CHAR16[]){83,101,108,101,99,116,32,101,120,112,114,101,115,115,105,111,110,32,109,117,115,116,32,98,101,32,105,110,116,101,103,101,114,32,111,114,32,99,104,97,114,97,99,116,101,114,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 27:
    _copy_16((const void*)((OOC_CHAR16[]){76,97,98,101,108,32,110,111,116,32,105,110,32,116,121,112,101,32,111,102,32,115,101,108,101,99,116,32,101,120,112,114,101,115,115,105,111,110,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 28:
    _copy_16((const void*)((OOC_CHAR16[]){76,97,98,101,108,32,97,108,114,101,97,100,121,32,105,110,32,117,115,101,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 29:
    _copy_16((const void*)((OOC_CHAR16[]){84,104,105,115,32,109,117,115,116,32,98,101,32,97,32,118,97,114,105,97,98,108,101,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 30:
    _copy_16((const void*)((OOC_CHAR16[]){83,116,101,112,32,118,97,108,117,101,32,110,111,116,32,105,110,32,116,121,112,101,32,111,102,32,108,111,111,112,32,118,97,114,105,97,98,108,101,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 31:
    _copy_16((const void*)((OOC_CHAR16[]){83,116,101,112,32,118,97,108,117,101,32,109,117,115,116,32,110,111,116,32,98,101,32,122,101,114,111,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 32:
    _copy_16((const void*)((OOC_CHAR16[]){82,69,84,85,82,78,32,109,117,115,116,32,110,111,116,32,112,114,111,118,105,100,101,32,97,32,114,101,115,117,108,116,32,118,97,108,117,101,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 33:
    _copy_16((const void*)((OOC_CHAR16[]){82,69,84,85,82,78,32,109,117,115,116,32,112,114,111,118,105,100,101,32,97,32,114,101,115,117,108,116,32,118,97,108,117,101,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 34:
    _copy_16((const void*)((OOC_CHAR16[]){84,104,105,115,32,118,97,114,105,97,98,108,101,32,105,115,32,114,101,97,100,45,111,110,108,121,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 35:
    _copy_16((const void*)((OOC_CHAR16[]){84,104,105,115,32,109,117,115,116,32,98,101,32,97,32,112,114,111,99,101,100,117,114,101,32,100,101,115,105,103,110,97,116,111,114,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 36:
    _copy_16((const void*)((OOC_CHAR16[]){84,104,105,115,32,105,115,32,97,32,102,117,110,99,116,105,111,110,32,112,114,111,99,101,100,117,114,101,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 37:
    _copy_16((const void*)((OOC_CHAR16[]){84,104,105,115,32,105,115,32,110,111,116,32,97,32,102,117,110,99,116,105,111,110,32,112,114,111,99,101,100,117,114,101,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 38:
    _copy_16((const void*)((OOC_CHAR16[]){84,111,111,32,102,101,119,32,97,114,103,117,109,101,110,116,115,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 39:
    _copy_16((const void*)((OOC_CHAR16[]){84,111,111,32,109,97,110,121,32,97,114,103,117,109,101,110,116,115,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 40:
    _copy_16((const void*)((OOC_CHAR16[]){65,114,103,117,109,101,110,116,32,110,111,116,32,99,111,109,112,97,116,105,98,108,101,32,119,105,116,104,32,102,111,114,109,97,108,32,86,65,82,32,112,97,114,97,109,101,116,101,114,32,96,36,123,110,97,109,101,125,39,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 41:
    _copy_16((const void*)((OOC_CHAR16[]){73,110,116,101,114,110,97,108,32,101,114,114,111,114,58,32,78,97,109,101,32,114,101,100,105,114,101,99,116,105,111,110,32,102,97,105,108,101,100,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 42:
    _copy_16((const void*)((OOC_CHAR16[]){84,104,105,115,32,112,97,114,97,109,101,116,101,114,32,105,115,32,114,101,97,100,45,111,110,108,121,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 43:
    _copy_16((const void*)((OOC_CHAR16[]){84,104,105,115,32,118,97,114,105,97,98,108,101,32,104,97,115,32,110,111,32,100,121,110,97,109,105,99,32,116,121,112,101,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 44:
    _copy_16((const void*)((OOC_CHAR16[]){69,120,112,114,101,115,115,105,111,110,32,109,117,115,116,32,98,101,32,110,117,109,101,114,105,99,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 45:
    _copy_16((const void*)((OOC_CHAR16[]){69,120,112,114,101,115,115,105,111,110,32,109,117,115,116,32,98,101,32,97,32,99,104,97,114,97,99,116,101,114,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 46:
    _copy_16((const void*)((OOC_CHAR16[]){69,120,112,114,101,115,115,105,111,110,32,109,117,115,116,32,98,101,32,111,102,32,114,101,97,108,32,116,121,112,101,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 47:
    _copy_16((const void*)((OOC_CHAR16[]){84,121,112,101,32,104,97,115,32,110,111,32,102,105,120,101,100,32,115,105,122,101,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 48:
    _copy_16((const void*)((OOC_CHAR16[]){65,114,103,117,109,101,110,116,32,109,117,115,116,32,98,101,32,97,32,99,104,97,114,97,99,116,101,114,32,97,114,114,97,121,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 49:
    _copy_16((const void*)((OOC_CHAR16[]){69,120,112,114,101,115,115,105,111,110,32,109,117,115,116,32,98,101,32,111,102,32,115,101,116,32,116,121,112,101,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 50:
    _copy_16((const void*)((OOC_CHAR16[]){84,104,105,115,32,109,117,115,116,32,98,101,32,97,32,112,111,105,110,116,101,114,32,118,97,114,105,97,98,108,101,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 51:
    _copy_16((const void*)((OOC_CHAR16[]){84,104,105,115,32,101,120,112,114,101,115,115,105,111,110,32,104,97,115,32,110,111,32,97,100,100,114,101,115,115,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 52:
    _copy_16((const void*)((OOC_CHAR16[]){83,105,122,101,32,109,105,115,109,97,116,99,104,32,98,101,116,119,101,101,110,32,116,121,112,101,32,97,110,100,32,101,120,112,114,101,115,115,105,111,110,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 53:
    _copy_16((const void*)((OOC_CHAR16[]){87,97,114,110,105,110,103,58,32,85,110,117,115,101,100,32,111,98,106,101,99,116,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 54:
    _copy_16((const void*)((OOC_CHAR16[]){76,101,110,103,116,104,32,111,102,32,116,104,105,115,32,97,114,114,97,121,32,118,97,108,117,101,32,99,97,110,110,111,116,32,98,101,32,100,101,116,101,114,109,105,110,101,100,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 55:
    _copy_16((const void*)((OOC_CHAR16[]){84,104,105,115,32,118,97,114,105,97,98,108,101,32,104,97,115,32,110,111,32,116,121,112,101,32,116,97,103,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 56:
    _copy_16((const void*)((OOC_CHAR16[]){67,97,110,110,111,116,32,99,114,101,97,116,101,32,105,110,115,116,97,110,99,101,32,111,102,32,97,98,115,116,114,97,99,116,32,116,121,112,101,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 57:
    _copy_16((const void*)((OOC_CHAR16[]){65,98,115,116,114,97,99,116,32,112,114,111,99,101,100,117,114,101,32,99,97,110,110,111,116,32,104,97,118,101,32,97,32,66,69,71,73,78,32,112,97,114,116,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 58:
    _copy_16((const void*)((OOC_CHAR16[]){67,97,108,108,101,100,32,112,114,111,99,101,100,117,114,101,32,105,115,32,100,101,99,108,97,114,101,100,32,97,98,115,116,114,97,99,116,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 59:
    _copy_16((const void*)((OOC_CHAR16[]){67,97,108,108,101,100,32,112,114,111,99,101,100,117,114,101,32,110,111,116,32,100,101,102,105,110,101,100,32,105,110,32,98,97,115,101,32,116,121,112,101,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 60:
    _copy_16((const void*)((OOC_CHAR16[]){83,117,112,101,114,32,99,97,108,108,32,99,97,110,32,111,110,108,121,32,97,112,112,108,121,32,116,111,32,116,104,101,32,100,105,114,101,99,116,32,98,97,115,101,32,116,121,112,101,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 61:
    _copy_16((const void*)((OOC_CHAR16[]){87,97,114,110,105,110,103,58,32,82,101,100,117,110,100,97,110,116,32,116,121,112,101,32,116,101,115,116,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 62:
    _copy_16((const void*)((OOC_CHAR16[]){84,121,112,101,32,105,115,32,110,111,116,32,97,110,32,101,120,116,101,110,115,105,111,110,32,111,102,32,96,69,120,99,101,112,116,105,111,110,46,69,120,99,101,112,116,105,111,110,39,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 63:
    _copy_16((const void*)((OOC_CHAR16[]){69,120,99,101,112,116,105,111,110,32,96,36,123,109,111,100,117,108,101,125,46,36,123,110,97,109,101,125,39,32,110,101,105,116,104,101,114,32,99,97,117,103,104,116,32,110,111,114,32,112,97,115,115,101,100,32,117,112,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 64:
    _copy_16((const void*)((OOC_CHAR16[]){87,97,114,110,105,110,103,58,32,69,120,99,101,112,116,105,111,110,32,96,36,123,109,111,100,117,108,101,125,46,36,123,110,97,109,101,125,39,32,110,111,116,32,99,97,117,103,104,116,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 65:
    _copy_16((const void*)((OOC_CHAR16[]){87,97,114,110,105,110,103,58,32,85,110,114,101,97,99,104,97,98,108,101,32,103,117,97,114,100,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 66:
    _copy_16((const void*)((OOC_CHAR16[]){87,97,114,110,105,110,103,58,32,84,121,112,101,32,109,97,116,99,104,101,115,32,110,111,110,101,32,111,102,32,116,104,101,32,114,97,105,115,101,100,32,101,120,99,101,112,116,105,111,110,115,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 67:
    _copy_16((const void*)((OOC_CHAR16[]){84,121,112,101,32,116,101,115,116,32,114,101,113,117,105,114,101,115,32,115,116,97,116,105,99,32,116,121,112,101,32,105,110,115,116,97,110,99,101,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 69:
    _copy_16((const void*)((OOC_CHAR16[]){84,104,105,115,32,105,115,32,110,111,116,32,97,32,112,97,114,97,109,101,116,114,105,99,32,116,121,112,101,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 70:
    _copy_16((const void*)((OOC_CHAR16[]){84,111,111,32,102,101,119,32,116,121,112,101,32,97,114,103,117,109,101,110,116,115,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 71:
    _copy_16((const void*)((OOC_CHAR16[]){84,111,111,32,109,97,110,121,32,116,121,112,101,32,97,114,103,117,109,101,110,116,115,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 72:
    _copy_16((const void*)((OOC_CHAR16[]){84,104,105,115,32,105,115,32,110,111,116,32,97,110,32,101,120,116,101,110,115,105,111,110,32,111,102,32,116,104,101,32,116,121,112,101,32,98,111,117,110,100,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 73:
    _copy_16((const void*)((OOC_CHAR16[]){78,111,116,32,97,32,114,101,99,111,114,100,32,112,111,105,110,116,101,114,32,116,121,112,101,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 74:
    _copy_16((const void*)((OOC_CHAR16[]){87,97,114,110,105,110,103,58,32,78,111,32,99,97,108,108,32,116,111,32,116,104,101,32,98,97,115,101,32,116,121,112,101,39,115,32,73,78,73,84,32,112,114,111,99,101,100,117,114,101,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 75:
    _copy_16((const void*)((OOC_CHAR16[]){84,104,101,32,116,121,112,101,39,115,32,73,78,73,84,32,112,114,111,99,101,100,117,114,101,32,109,117,115,116,32,98,101,32,100,101,102,105,110,101,100,32,98,101,102,111,114,101,32,105,116,115,32,117,115,101,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 76:
    _copy_16((const void*)((OOC_CHAR16[]){73,116,101,114,97,116,111,114,32,114,101,113,117,105,114,101,115,32,97,114,114,97,121,32,101,108,101,109,101,110,116,115,32,111,102,32,115,99,97,108,97,114,32,116,121,112,101,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 77:
    _copy_16((const void*)((OOC_CHAR16[]){84,104,105,115,32,101,120,112,114,101,115,115,105,111,110,32,109,117,115,116,32,112,114,111,100,117,99,101,32,97,110,32,105,116,101,114,97,116,111,114,32,111,98,106,101,99,116,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 78:
    _copy_16((const void*)((OOC_CHAR16[]){84,104,101,32,105,116,101,114,97,116,111,114,32,111,98,106,101,99,116,32,104,97,115,32,110,111,32,78,101,120,116,40,41,32,109,101,116,104,111,100,32,119,105,116,104,32,97,32,118,97,108,105,100,32,115,105,103,110,97,116,117,114,101,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  case 79:
    _copy_16((const void*)((OOC_CHAR16[]){78,111,116,32,97,32,115,101,116,32,116,121,112,101,0}),(void*)(OOC_INT32)t,128);
    goto l81;
  default:
    _failed_case(i1, 41323);
    goto l81;
  }
l81:
  i1 = (OOC_INT32)context;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 46999)))), OOC_Error__ContextDesc_BaseTemplate)),OOC_Error__ContextDesc_BaseTemplate)((OOC_Error__Context)i1, (Msg__Msg)i0, (void*)(OOC_INT32)t, 128, (void*)(OOC_INT32)templ, templ_0d);
  return;
  ;
}

static void OOC_IR__InitGuardedVar(OOC_IR__GuardedVar gv, OOC_SymbolTable__VarDecl var, OOC_SymbolTable__Name name, OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT8 exportMark;

  i0 = (OOC_INT32)var;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 47349))+28);
  exportMark = i1;
  i2 = i1==0;
  if (!i2) goto l4;
  exportMark = 2;
  i1=2;
l4:
  i2 = *(OOC_INT32*)((_check_pointer(i0, 47501))+24);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 47555))+32);
  i4 = (OOC_INT32)gv;
  i5 = (OOC_INT32)name;
  OOC_SymbolTable__InitDeclaration((OOC_SymbolTable__Declaration)i4, (OOC_SymbolTable__Item)(OOC_INT32)0, (OOC_SymbolTable__Name)i5, i2, i1, (OOC_Doc__Document)i3);
  *(OOC_INT32*)((_check_pointer(i4, 47574))+48) = i0;
  i0 = (OOC_INT32)type;
  *(OOC_INT32*)((_check_pointer(i4, 47593))+52) = i0;
  return;
  ;
}

static OOC_IR__GuardedVar OOC_IR__NewGuardedVar(OOC_SymbolTable__VarDecl var, OOC_SymbolTable__Name name, OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__GuardedVar.baseTypes[0]);
  i1 = (OOC_INT32)type;
  i2 = (OOC_INT32)name;
  i3 = (OOC_INT32)var;
  OOC_IR__InitGuardedVar((OOC_IR__GuardedVar)i0, (OOC_SymbolTable__VarDecl)i3, (OOC_SymbolTable__Name)i2, (OOC_SymbolTable__Type)i1);
  return (OOC_IR__GuardedVar)i0;
  ;
}

OOC_SymbolTable__Module OOC_IR__GuardedVarDesc_Module(OOC_IR__GuardedVar gv) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)gv;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 47942))+48);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 47942))+48);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 47947)))), OOC_SymbolTable__ItemDesc_Module)),OOC_SymbolTable__ItemDesc_Module)((OOC_SymbolTable__Item)i0);
  return (OOC_SymbolTable__Module)i0;
  ;
}

void OOC_IR__InitNode(OOC_IR__Node n, OOC_Scanner_SymList__Symbol sym) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)n;
  i1 = (OOC_INT32)sym;
  *(OOC_INT32*)(_check_pointer(i0, 48133)) = i1;
  return;
  ;
}

void OOC_IR__NodeDesc_Accept(OOC_IR__Node node, OOC_IR__Visitor v) {

  return;
  ;
}

OOC_IR__Expression OOC_IR__ConstFoldDesc_TryConstFold(OOC_IR__ConstFold c, OOC_IR__Expression expr) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)c;
  *(OOC_INT32*)((_check_pointer(i0, 48546))+4) = (OOC_INT32)0;
  i1 = (OOC_INT32)expr;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 48570)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i1, (OOC_IR__Visitor)i0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 48590))+4);
  i2 = i2==(OOC_INT32)0;
  if (i2) goto l3;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 48650))+4);
  return (OOC_IR__Expression)i0;
  goto l4;
l3:
  return (OOC_IR__Expression)i1;
l4:
  _failed_function(48261); return 0;
  ;
}

void OOC_IR__BuilderDesc_ErrSym(OOC_IR__Builder b, OOC_INT32 code, OOC_Scanner_SymList__Symbol sym) {
  register OOC_INT32 i0,i1,i2,i3;
  Msg__Msg e;

  i0 = code;
  i1 = (OOC_INT32)OOC_IR__irContext;
  i0 = (OOC_INT32)OOC_Error__New((OOC_Error__Context)i1, i0);
  e = (Msg__Msg)i0;
  i1 = (OOC_INT32)b;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 48838))+20);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 48849));
  i3 = (OOC_INT32)sym;
  i2 = i3!=i2;
  if (!i2) goto l4;
  i2 = *(OOC_INT32*)((_check_pointer(i3, 48935))+16);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 48909)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i0, "pos", 4, i2);
  i2 = *(OOC_INT32*)((_check_pointer(i3, 48977))+20);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 48950)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i0, "line", 5, i2);
  i2 = *(OOC_INT32*)((_check_pointer(i3, 49022))+24);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 48993)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i0, "column", 7, i2);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 49040))+8);
  OOC_Error__ListDesc_Append((OOC_Error__List)i2, (Msg__Msg)i0);
l4:
  *(OOC_INT32*)((_check_pointer(i1, 49077))+36) = i0;
  return;
  ;
}

void OOC_IR__BuilderDesc_SetNameToType(OOC_IR__Builder b, OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_SymbolTable__Module module;
  OOC_CHAR8 name[256];

  i0 = (OOC_INT32)type;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 49362))+24);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l31;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 49818)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  type = (OOC_SymbolTable__Type)i0;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 49845)))), &_td_OOC_SymbolTable__TypeNameDesc);
  if (i1) goto l29;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 49995)))), &_td_OOC_SymbolTable__PointerDesc);
  if (i1) goto l27;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 50051)))), &_td_OOC_SymbolTable__FormalParsDesc);
  if (i1) goto l25;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 50112)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (i1) goto l23;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 50164)))), &_td_OOC_SymbolTable__RecordDesc);
  if (i1) goto l21;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 50218)))), &_td_OOC_SymbolTable__TypeVarDesc);
  if (i1) goto l19;
  i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 50275)))), &_td_OOC_SymbolTable__PredefTypeDesc);
  if (i0) goto l17;
  _copy_8((const void*)"unknown",(void*)(OOC_INT32)name,256);
  goto l40;
l17:
  _copy_8((const void*)"unknown",(void*)(OOC_INT32)name,256);
  goto l40;
l19:
  _copy_8((const void*)"TYPE_VAR",(void*)(OOC_INT32)name,256);
  goto l40;
l21:
  _copy_8((const void*)"RECORD",(void*)(OOC_INT32)name,256);
  goto l40;
l23:
  _copy_8((const void*)"ARRAY",(void*)(OOC_INT32)name,256);
  goto l40;
l25:
  _copy_8((const void*)"PROCEDURE",(void*)(OOC_INT32)name,256);
  goto l40;
l27:
  _copy_8((const void*)"POINTER",(void*)(OOC_INT32)name,256);
  goto l40;
l29:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 49880))+40);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 49887))+12);
  _copy_8((const void*)(_check_pointer(i1, 49891)),(void*)(OOC_INT32)name,256);
  Strings__Append(".", 2, (void*)(OOC_INT32)name, 256);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 49963))+44);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 49969))+12);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 49963))+44);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 49969))+12);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 49973)), 0);
  Strings__Append((void*)(_check_pointer(i0, 49973)), i1, (void*)(OOC_INT32)name, 256);
  goto l40;
l31:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 49406))+24);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 49406))+24);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 49417)))), OOC_SymbolTable__ItemDesc_Module)),OOC_SymbolTable__ItemDesc_Module)((OOC_SymbolTable__Item)i2);
  module = (OOC_SymbolTable__Module)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 49444))+20);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 49449))+12);
  i2 = _check_pointer(i2, 49453);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = *(OOC_UINT8*)(i2+(_check_index(0, i3, OOC_UINT8, 49453)));
  i2 = i2==35u;
  if (i2) goto l34;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 49473)))), &_td_OOC_SymbolTable__TypeVarDesc);
  
  goto l36;
l34:
  i2=1u;
l36:
  if (i2) goto l38;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 49671))+20);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 49676))+12);
  _copy_8((const void*)(_check_pointer(i1, 49680)),(void*)(OOC_INT32)name,256);
  Strings__Append(".", 2, (void*)(OOC_INT32)name, 256);
  goto l39;
l38:
  _copy_8((const void*)"",(void*)(OOC_INT32)name,256);
l39:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 49761))+24);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 49772))+20);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 49777))+12);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 49761))+24);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 49772))+20);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 49777))+12);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 49781)), 0);
  Strings__Append((void*)(_check_pointer(i0, 49781)), i1, (void*)(OOC_INT32)name, 256);
l40:
  i0 = (OOC_INT32)Msg__GetStringPtr((void*)(OOC_INT32)name, 256);
  i1 = (OOC_INT32)b;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 50445))+36);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 50445))+36);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 50455)))), Msg__MsgDesc_SetStringAttrib)),Msg__MsgDesc_SetStringAttrib)((Msg__Msg)i1, "name", 5, (Msg__StringPtr)i0);
  return;
  ;
}

static OOC_CHAR8 OOC_IR__GetPragmaValue(OOC_IR__Builder b, Config_Section_Options__Option pragma, OOC_INT32 charPos) {
  register OOC_INT32 i0,i1,i2;
  Config__Variable value;

  i0 = (OOC_INT32)pragma;
  i1 = (OOC_INT32)b;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 50681))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 50712))+4);
  i2 = charPos;
  i0 = (OOC_INT32)OOC_Config_Pragmas__HistoryDesc_GetValue((OOC_Config_Pragmas__History)i1, (Object__String)i0, i2);
  value = (Config__Variable)i0;
  i0 = *(OOC_UINT8*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 50753)))), &_td_Config__BooleanVarDesc, 50753)), 50764));
  return i0;
  ;
}

void OOC_IR__BuilderDesc_WarnSym(OOC_IR__Builder b, OOC_INT32 code, OOC_Scanner_SymList__Symbol sym) {
  register OOC_INT32 i0,i1,i2,i3;
  Msg__Msg e;

  i0 = code;
  i1 = (OOC_INT32)OOC_IR__irContext;
  i0 = (OOC_INT32)OOC_Error__New((OOC_Error__Context)i1, i0);
  e = (Msg__Msg)i0;
  i1 = (OOC_INT32)sym;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 50962))+16);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 50936)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i0, "pos", 4, i2);
  i2 = *(OOC_INT32*)((_check_pointer(i1, 51002))+20);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 50975)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i0, "line", 5, i2);
  i2 = *(OOC_INT32*)((_check_pointer(i1, 51045))+24);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 51016)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i0, "column", 7, i2);
  i2 = (OOC_INT32)b;
  *(OOC_INT32*)((_check_pointer(i2, 51187))+36) = i0;
  i1 = *(OOC_INT32*)((_check_pointer(i1, 51259))+16);
  i3 = (OOC_INT32)OOC_Config_StdPragmas__warnings;
  i1 = OOC_IR__GetPragmaValue((OOC_IR__Builder)i2, (Config_Section_Options__Option)i3, i1);
  if (!i1) goto l4;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 51277))+8);
  OOC_Error__ListDesc_Append((OOC_Error__List)i1, (Msg__Msg)i0);
l4:
  return;
  ;
}

void OOC_IR__BuilderDesc_WarnName(OOC_IR__Builder b, OOC_INT32 code, OOC_SymbolTable__Name name) {
  register OOC_INT32 i0,i1,i2,i3;
  Msg__Msg e;

  i0 = (OOC_INT32)name;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 51437))+12);
  i1 = _check_pointer(i1, 51441);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_UINT8*)(i1+(_check_index(0, i2, OOC_UINT8, 51441)));
  i1 = i1!=45u;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = *(OOC_INT32*)(_check_pointer(i0, 51504));
  i2 = (OOC_INT32)OOC_Config_StdPragmas__warnings;
  i3 = (OOC_INT32)b;
  i1 = OOC_IR__GetPragmaValue((OOC_IR__Builder)i3, (Config_Section_Options__Option)i2, i1);
  
l5:
  if (!i1) goto l7;
  i1 = (OOC_INT32)OOC_IR__irContext;
  i2 = code;
  i1 = (OOC_INT32)OOC_Error__New((OOC_Error__Context)i1, i2);
  e = (Msg__Msg)i1;
  i2 = *(OOC_INT32*)(_check_pointer(i0, 51696));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 51669)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i1, "pos", 4, i2);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 51739))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 51711)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i1, "line", 5, i2);
  i0 = *(OOC_INT32*)((_check_pointer(i0, 51785))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 51755)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i1, "column", 7, i0);
  i0 = (OOC_INT32)b;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 51803))+8);
  OOC_Error__ListDesc_Append((OOC_Error__List)i2, (Msg__Msg)i1);
  *(OOC_INT32*)((_check_pointer(i0, 51833))+36) = i1;
l7:
  return;
  ;
}

OOC_IR__Const OOC_IR__BuilderDesc_ErrExpr(OOC_IR__Builder b, OOC_INT32 code, OOC_Scanner_SymList__Symbol sym) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)b;
  i1 = code;
  i2 = (OOC_INT32)sym;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 51966)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, i1, (OOC_Scanner_SymList__Symbol)i2);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 51998))+20);
  return (OOC_IR__Const)i0;
  ;
}

OOC_SymbolTable__Name OOC_IR__BuilderDesc_GetName(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_SymbolTable__Name name;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SymbolTable__Name.baseTypes[0]);
  name = (OOC_SymbolTable__Name)i0;
  i1 = (OOC_INT32)sym;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 52192))+24);
  i3 = *(OOC_INT32*)((_check_pointer(i1, 52181))+20);
  i4 = *(OOC_INT32*)((_check_pointer(i1, 52171))+16);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 52161))+8);
  OOC_SymbolTable__InitName((OOC_SymbolTable__Name)i0, (OOC_Scanner_InputBuffer__CharArray)i1, i4, i3, i2);
  return (OOC_SymbolTable__Name)i0;
  ;
}

OOC_SymbolTable__Name OOC_IR__BuilderDesc_GetName2(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, const OOC_CHAR8 str__ref[], OOC_LEN str_0d) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_ALLOCATE_VPAR(str,OOC_CHAR8 ,str_0d)
  OOC_Scanner_InputBuffer__CharArray s;
  OOC_SymbolTable__Name name;

  OOC_INITIALIZE_VPAR(str__ref,str,OOC_CHAR8 ,str_0d)
  i0 = Strings__Length((void*)(OOC_INT32)str, str_0d);
  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Scanner_InputBuffer__CharArray.baseTypes[0], (i0+1));
  s = (OOC_Scanner_InputBuffer__CharArray)i0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 52420)), 0);
  _copy_8((const void*)(OOC_INT32)str,(void*)(_check_pointer(i0, 52420)),i1);
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_SymbolTable__Name.baseTypes[0]);
  name = (OOC_SymbolTable__Name)i1;
  i2 = (OOC_INT32)sym;
  i3 = *(OOC_INT32*)((_check_pointer(i2, 52496))+24);
  i4 = *(OOC_INT32*)((_check_pointer(i2, 52485))+20);
  i2 = *(OOC_INT32*)((_check_pointer(i2, 52475))+16);
  OOC_SymbolTable__InitName((OOC_SymbolTable__Name)i1, (OOC_Scanner_InputBuffer__CharArray)i0, i2, i4, i3);
  return (OOC_SymbolTable__Name)i1;
  ;
}

OOC_SymbolTable__Type OOC_IR__BuilderDesc_AssertType(OOC_IR__Builder b, OOC_IR__Expression expr) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)expr;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 52797)))), &_td_OOC_IR__TypeRefDesc);
  if (i1) goto l3;
  i1 = (OOC_INT32)b;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 52917));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 52886)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 16, (OOC_Scanner_SymList__Symbol)i2);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 52941))+4);
  return (OOC_SymbolTable__Type)i0;
  goto l4;
l3:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 52827))+12);
  return (OOC_SymbolTable__Type)i0;
l4:
  _failed_function(52563); return 0;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_AssertBoolean(OOC_IR__Builder b, OOC_IR__Expression expr) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)expr;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53225))+4);
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 53232)))), &_td_OOC_SymbolTable__PredefTypeDesc);
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53265))+4);
  i1 = *(OOC_INT16*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 53276)))), &_td_OOC_SymbolTable__PredefTypeDesc, 53276)), 53287))+40);
  i1 = i1==0;
  
l5:
  if (i1) goto l7;
  i1 = (OOC_INT32)b;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 53384));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 53357)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i1, 22, (OOC_Scanner_SymList__Symbol)i0);
  return (OOC_IR__Expression)i0;
  goto l8;
l7:
  return (OOC_IR__Expression)i0;
l8:
  _failed_function(52999); return 0;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_Fold(OOC_IR__Builder b, OOC_IR__Expression expr) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53503))+12);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53503))+12);
  i2 = (OOC_INT32)expr;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 53513)))), OOC_IR__ConstFoldDesc_TryConstFold)),OOC_IR__ConstFoldDesc_TryConstFold)((OOC_IR__ConstFold)i0, (OOC_IR__Expression)i2);
  return (OOC_IR__Expression)i0;
  ;
}

static OOC_CHAR8 OOC_IR__IsPredefType(OOC_SymbolTable__Type type, OOC_INT16 id) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 53636)))), &_td_OOC_SymbolTable__PredefTypeDesc);
  if (i1) goto l3;
  i0=0u;
  goto l4;
l3:
  i0 = *(OOC_INT16*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 53667)))), &_td_OOC_SymbolTable__PredefTypeDesc, 53667)), 53678))+40);
  i1 = id;
  i0 = i0==i1;
  
l4:
  return i0;
  ;
}

void OOC_IR__BuilderDesc_CheckFunctionOp(OOC_IR__Builder b, OOC_IR__Expression expr, OOC_Scanner_SymList__Symbol op) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)expr;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 55033)))), &_td_OOC_IR__PredefProcDesc);
  if (i1) goto l3;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 55057)))), &_td_OOC_IR__CallDesc);
  
  goto l5;
l3:
  i1=1u;
l5:
  if (i1) goto l7;
  i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 55075)))), &_td_OOC_IR__ConstructorDesc);
  
  goto l9;
l7:
  i0=1u;
l9:
  if (!i0) goto l11;
  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)op;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 55101)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 23, (OOC_Scanner_SymList__Symbol)i1);
l11:
  return;
  ;
}

void OOC_IR__InitExpression(OOC_IR__Expression expr, OOC_Scanner_SymList__Symbol sym, OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)expr;
  OOC_IR__InitNode((OOC_IR__Node)i1, (OOC_Scanner_SymList__Symbol)i0);
  i0 = (OOC_INT32)type;
  *(OOC_INT32*)((_check_pointer(i1, 55391))+4) = i0;
  return;
  ;
}

static void OOC_IR__InitConst(OOC_IR__Const _const, OOC_Scanner_SymList__Symbol sym, OOC_SymbolTable__Type type, Object_Boxed__Object value) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)type;
  i1 = (OOC_INT32)sym;
  i2 = (OOC_INT32)_const;
  OOC_IR__InitExpression((OOC_IR__Expression)i2, (OOC_Scanner_SymList__Symbol)i1, (OOC_SymbolTable__Type)i0);
  i0 = (OOC_INT32)value;
  *(OOC_INT32*)((_check_pointer(i2, 55700))+8) = i0;
  return;
  ;
}

static OOC_IR__Const OOC_IR__NewConst(OOC_Scanner_SymList__Symbol sym, OOC_SymbolTable__Type type, Object_Boxed__Object value) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)type;
  _assert((i0!=(OOC_INT32)0), 127, 55870);
  i1 = (OOC_INT32)sym;
  i2 = (OOC_INT32)value;
  i3 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__Const.baseTypes[0]);
  OOC_IR__InitConst((OOC_IR__Const)i3, (OOC_Scanner_SymList__Symbol)i1, (OOC_SymbolTable__Type)i0, (Object_Boxed__Object)i2);
  return (OOC_IR__Const)i3;
  ;
}

void OOC_IR__VisitorDesc_VisitConst(OOC_IR__Visitor v, OOC_IR__Const _const) {

  return;
  ;
}

void OOC_IR__ConstDesc_Accept(OOC_IR__Const _const, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)_const;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 56124)))), OOC_IR__VisitorDesc_VisitConst)),OOC_IR__VisitorDesc_VisitConst)((OOC_IR__Visitor)i0, (OOC_IR__Const)i1);
  return;
  ;
}

Object__String OOC_IR__ConstDesc_ToString(OOC_IR__Const _const) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)_const;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 56227))+8);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l3;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 56294))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 56294))+8);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 56301)))), Object_Boxed__ObjectDesc_ToString)),Object_Boxed__ObjectDesc_ToString)((Object_Boxed__Object)i0);
  return (Object__String)i0;
  goto l4;
l3:
  return (Object__String)((OOC_INT32)_c1);
l4:
  _failed_function(56185); return 0;
  ;
}

OOC_IR__Const OOC_IR__BuilderDesc_NewConst(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_SymbolTable__Type type, Object_Boxed__Object value) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)value;
  i1 = (OOC_INT32)type;
  i2 = (OOC_INT32)sym;
  i0 = (OOC_INT32)OOC_IR__NewConst((OOC_Scanner_SymList__Symbol)i2, (OOC_SymbolTable__Type)i1, (Object_Boxed__Object)i0);
  return (OOC_IR__Const)i0;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_NewStringConst(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 56603))+8);
  i1 = _check_pointer(i1, 56608);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_UINT8*)(i1+(_check_index(2, i2, OOC_UINT8, 56608)));
  i1 = i1!=0u;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 56624))+8);
  i1 = _check_pointer(i1, 56629);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_UINT8*)(i1+(_check_index(3, i2, OOC_UINT8, 56629)));
  i1 = i1==0u;
  
l5:
  if (i1) goto l7;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 57070))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 57070))+8);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 57075)), 0);
  i1 = (OOC_INT32)Object_Boxed__ParseString((void*)(_check_pointer(i2, 57075)), i1);
  i2 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(13);
  i0 = (OOC_INT32)OOC_IR__NewConst((OOC_Scanner_SymList__Symbol)i0, (OOC_SymbolTable__Type)i2, (Object_Boxed__Object)i1);
  return (OOC_IR__Expression)i0;
  goto l8;
l7:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 56943))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 56943))+8);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 56948)), 0);
  i1 = (OOC_INT32)Object_Boxed__ParseString((void*)(_check_pointer(i2, 56948)), i1);
  i2 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(1);
  i0 = (OOC_INT32)OOC_IR__NewConst((OOC_Scanner_SymList__Symbol)i0, (OOC_SymbolTable__Type)i2, (Object_Boxed__Object)i1);
  return (OOC_IR__Expression)i0;
l8:
  _failed_function(56541); return 0;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_NewIntConst10(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym) {
  register OOC_INT32 i0,i1,i2;
  Object_BigInt__BigInt v;

  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 57242))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 57242))+8);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 57247)), 0);
  i1 = (OOC_INT32)Object_BigInt__NewLatin1((void*)(_check_pointer(i2, 57247)), i1, 10);
  v = (Object_BigInt__BigInt)i1;
  i2 = i1==(OOC_INT32)0;
  if (i2) goto l3;
  i2 = (OOC_INT32)OOC_SymbolTable_Predef__SmallestIntType((Object_BigInt__BigInt)i1);
  i0 = (OOC_INT32)OOC_IR__NewConst((OOC_Scanner_SymList__Symbol)i0, (OOC_SymbolTable__Type)i2, (Object_Boxed__Object)i1);
  return (OOC_IR__Expression)i0;
  goto l4;
l3:
  i1 = (OOC_INT32)b;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 57284)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 3, (OOC_Scanner_SymList__Symbol)i0);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 57332))+20);
  return (OOC_IR__Expression)i0;
l4:
  _failed_function(57135); return 0;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_NewIntConst16(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_INT32 epos;

  epos = 0;
  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 57591))+8);
  i1 = _check_pointer(i1, 57595);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_UINT8*)(i1+(_check_index(0, i2, OOC_UINT32, 57595)));
  i1 = i1!=72u;
  if (i1) goto l3;
  i1=0;
  goto l9;
l3:
  i1=0;
l4_loop:
  i1 = i1+1;
  epos = i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 57591))+8);
  i2 = _check_pointer(i2, 57595);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = *(OOC_UINT8*)(i2+(_check_index(i1, i3, OOC_UINT32, 57595)));
  i2 = i2!=72u;
  if (i2) goto l4_loop;
l9:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 57673))+8);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 57673))+8);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 57677)), 0);
  i1 = (OOC_INT32)Object_BigInt__NewLatin1Region((void*)(_check_pointer(i3, 57677)), i2, 0, i1, 16);
  i2 = (OOC_INT32)OOC_SymbolTable_Predef__SmallestIntType((Object_BigInt__BigInt)i1);
  i0 = (OOC_INT32)OOC_IR__NewConst((OOC_Scanner_SymList__Symbol)i0, (OOC_SymbolTable__Type)i2, (Object_Boxed__Object)i1);
  return (OOC_IR__Expression)i0;
  ;
}

OOC_IR__Const OOC_IR__BuilderDesc_AssertConst(OOC_IR__Builder b, OOC_IR__Expression expr) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)expr;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 58076)))), &_td_OOC_IR__ConstDesc);
  if (i1) goto l3;
  i1 = (OOC_INT32)b;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 58197));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 58165)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i1, 9, (OOC_Scanner_SymList__Symbol)i0);
  return (OOC_IR__Const)i0;
  goto l4;
l3:
  return (OOC_IR__Const)i0;
l4:
  _failed_function(57795); return 0;
  ;
}

OOC_INT32 OOC_IR__BuilderDesc_AssertIntConst(OOC_IR__Builder b, OOC_IR__Expression expr, OOC_INT32 start, OOC_INT32 end) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_IR__Const _const;
  OOC_INT32 v;

  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)expr;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 58763)))), OOC_IR__BuilderDesc_AssertConst)),OOC_IR__BuilderDesc_AssertConst)((OOC_IR__Builder)i0, (OOC_IR__Expression)i1);
  _const = (OOC_IR__Const)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 58802))+20);
  i2 = i1!=i2;
  if (!i2) goto l20;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 58852))+4);
  i2 = OOC_SymbolTable_TypeRules__IsIntegerType((OOC_SymbolTable__Type)i2);
  if (!i2) goto l16;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 58883))+8);
  i2 = Object_BigInt__BigIntDesc_ToLongInt((Object_BigInt__BigInt)(_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 58898)))), &_td_Object_BigInt__BigIntDesc, 58898)));
  v = i2;
  i3 = start;
  i3 = i3<=i2;
  if (i3) goto l7;
  i3=0u;
  goto l13;
l7:
  i3 = end;
  i4 = i3==(-2147483647-1);
  if (i4) goto l10;
  i3 = i2<i3;
  
  goto l13;
l10:
  i3=1u;
l13:
  if (!i3) goto l16;
  return i2;
l16:
  i2 = start;
  i3 = end;
  i4 = i2<i3;
  if (!i4) goto l20;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 59157));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 59121)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 14, (OOC_Scanner_SymList__Symbol)i1);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 59174))+36);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 59174))+36);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 59185)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i4, "start", 6, i2);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 59227))+36);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 59227))+36);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 59238)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i0, "end", 4, i3);
l20:
  i0 = start;
  return i0;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_AssertInteger(OOC_IR__Builder b, OOC_IR__Expression expr) {
  register OOC_INT32 i0,i1,i2,i3;
  Object_BigInt__BigInt v;

  i0 = (OOC_INT32)expr;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 59611))+4);
  i1 = OOC_SymbolTable_TypeRules__IsIntegerType((OOC_SymbolTable__Type)i1);
  i1 = !i1;
  if (!i1) goto l6;
  i1 = (OOC_INT32)b;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 59641))+20);
  i2 = i0!=i2;
  if (!i2) goto l5;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 59691));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 59667)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 19, (OOC_Scanner_SymList__Symbol)i2);
l5:
  i1 = (OOC_INT32)Object_BigInt__NewInt(1);
  v = (Object_BigInt__BigInt)i1;
  i2 = (OOC_INT32)OOC_SymbolTable_Predef__SmallestIntType((Object_BigInt__BigInt)i1);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 59764));
  i1 = (OOC_INT32)OOC_IR__NewConst((OOC_Scanner_SymList__Symbol)i3, (OOC_SymbolTable__Type)i2, (Object_Boxed__Object)i1);
  return (OOC_IR__Expression)i1;
l6:
  return (OOC_IR__Expression)i0;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_AssertReal(OOC_IR__Builder b, OOC_IR__Expression expr) {
  register OOC_INT32 i0,i1,i2,i3;
  Object_Boxed__LongReal v;

  i0 = (OOC_INT32)expr;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 60131))+4);
  i1 = OOC_SymbolTable_TypeRules__IsRealType((OOC_SymbolTable__Type)i1);
  i1 = !i1;
  if (!i1) goto l6;
  i1 = (OOC_INT32)b;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 60161))+20);
  i2 = i0!=i2;
  if (!i2) goto l5;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 60208));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 60187)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 46, (OOC_Scanner_SymList__Symbol)i2);
l5:
  i1 = (OOC_INT32)RT0__NewObject(_td_Object_Boxed__LongReal.baseTypes[0]);
  Object_Boxed__LongRealDesc_INIT((Object_Boxed__LongReal)i1, 1.0000000000000000);
  v = (Object_Boxed__LongReal)i1;
  i2 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(8);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 60287));
  i1 = (OOC_INT32)OOC_IR__NewConst((OOC_Scanner_SymList__Symbol)i3, (OOC_SymbolTable__Type)i2, (Object_Boxed__Object)i1);
  return (OOC_IR__Expression)i1;
l6:
  return (OOC_IR__Expression)i0;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_AssertNumeric(OOC_IR__Builder b, OOC_IR__Expression expr) {
  register OOC_INT32 i0,i1,i2,i3;
  Object_BigInt__BigInt v;

  i0 = (OOC_INT32)expr;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 60663))+4);
  i1 = OOC_SymbolTable_TypeRules__IsNumericType((OOC_SymbolTable__Type)i1);
  i1 = !i1;
  if (!i1) goto l6;
  i1 = (OOC_INT32)b;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 60693))+20);
  i2 = i0!=i2;
  if (!i2) goto l5;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 60743));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 60719)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 44, (OOC_Scanner_SymList__Symbol)i2);
l5:
  i1 = (OOC_INT32)Object_BigInt__NewInt(1);
  v = (Object_BigInt__BigInt)i1;
  i2 = (OOC_INT32)OOC_SymbolTable_Predef__SmallestIntType((Object_BigInt__BigInt)i1);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 60816));
  i1 = (OOC_INT32)OOC_IR__NewConst((OOC_Scanner_SymList__Symbol)i3, (OOC_SymbolTable__Type)i2, (Object_Boxed__Object)i1);
  return (OOC_IR__Expression)i1;
l6:
  return (OOC_IR__Expression)i0;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_AssertChar(OOC_IR__Builder b, OOC_IR__Expression expr) {
  register OOC_INT32 i0,i1,i2,i3;
  Object_Boxed__String v;

  i0 = (OOC_INT32)expr;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 61177))+4);
  i1 = OOC_SymbolTable_TypeRules__IsCharType((OOC_SymbolTable__Type)i1);
  i1 = !i1;
  if (!i1) goto l6;
  i1 = (OOC_INT32)b;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 61207))+20);
  i2 = i0!=i2;
  if (!i2) goto l5;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 61259));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 61233)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 45, (OOC_Scanner_SymList__Symbol)i2);
l5:
  i1 = (OOC_INT32)RT0__NewObject(_td_Object_Boxed__String.baseTypes[0]);
  Object_Boxed__StringDesc_INIT((Object_Boxed__String)i1, (Object__String)((OOC_INT32)_c2));
  v = (Object_Boxed__String)i1;
  i2 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(1);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 61338));
  i1 = (OOC_INT32)OOC_IR__NewConst((OOC_Scanner_SymList__Symbol)i3, (OOC_SymbolTable__Type)i2, (Object_Boxed__Object)i1);
  return (OOC_IR__Expression)i1;
l6:
  return (OOC_IR__Expression)i0;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_AssertSet(OOC_IR__Builder b, OOC_IR__Expression expr) {
  register OOC_INT32 i0,i1,i2,i3;
  Object_Boxed__Set v;

  i0 = (OOC_INT32)expr;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 61664))+4);
  i1 = OOC_SymbolTable_TypeRules__IsSetType((OOC_SymbolTable__Type)i1);
  i1 = !i1;
  if (!i1) goto l6;
  i1 = (OOC_INT32)b;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 61694))+20);
  i2 = i0!=i2;
  if (!i2) goto l5;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 61740));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 61720)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 49, (OOC_Scanner_SymList__Symbol)i2);
l5:
  i1 = (OOC_INT32)RT0__NewObject(_td_Object_Boxed__Set.baseTypes[0]);
  Object_Boxed__SetDesc_INIT((Object_Boxed__Set)i1, 0u);
  v = (Object_Boxed__Set)i1;
  i2 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(10);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 61815));
  i1 = (OOC_INT32)OOC_IR__NewConst((OOC_Scanner_SymList__Symbol)i3, (OOC_SymbolTable__Type)i2, (Object_Boxed__Object)i1);
  return (OOC_IR__Expression)i1;
l6:
  return (OOC_IR__Expression)i0;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_NewRealConst(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_INT16 type) {
  register OOC_INT32 i0,i1,i2;
  Object_Boxed__Object v;

  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 62056))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 62056))+8);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 62061)), 0);
  i1 = (OOC_INT32)Object_Boxed__ParseLongRealLiteral((void*)(_check_pointer(i2, 62061)), i1);
  v = (Object_Boxed__Object)i1;
  i2 = i1==(OOC_INT32)0;
  if (i2) goto l3;
  i2 = type;
  i2 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(i2);
  i0 = (OOC_INT32)OOC_IR__NewConst((OOC_Scanner_SymList__Symbol)i0, (OOC_SymbolTable__Type)i2, (Object_Boxed__Object)i1);
  return (OOC_IR__Expression)i0;
  goto l4;
l3:
  i1 = (OOC_INT32)b;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 62094)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 3, (OOC_Scanner_SymList__Symbol)i0);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 62142))+20);
  return (OOC_IR__Expression)i0;
l4:
  _failed_function(61920); return 0;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_NewCharConst16(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym) {
  register OOC_INT32 i0,i1,i2;
  OOC_INT32 v;
  auto OOC_INT32 OOC_IR__BuilderDesc_NewCharConst16_ValueOf(const OOC_CHAR8 str[], OOC_LEN str_0d);
    
    OOC_INT32 OOC_IR__BuilderDesc_NewCharConst16_ValueOf(const OOC_CHAR8 str[], OOC_LEN str_0d) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_INT32 i;
      OOC_INT32 hexCount;
      OOC_INT32 ord;
      auto OOC_INT32 OOC_IR__BuilderDesc_NewCharConst16_ValueOf_HexDigit(OOC_CHAR8 ch);
      auto OOC_CHAR8 OOC_IR__BuilderDesc_NewCharConst16_ValueOf_HexToInt(const OOC_CHAR8 str__ref[], OOC_LEN str_0d, OOC_CHAR8 end, OOC_INT32 *result);
        
        OOC_INT32 OOC_IR__BuilderDesc_NewCharConst16_ValueOf_HexDigit(OOC_CHAR8 ch) {
          register OOC_INT32 i0;

          i0 = ch;
          i0 = _cap(i0);
          switch (i0) {
          case 48u ... 57u:
            return (i0-48);
            goto l5;
          case 65u ... 70u:
            return (i0+(-55));
            goto l5;
          default:
            return (-1);
            goto l5;
          }
l5:
          _failed_function(62492); return 0;
          ;
        }

        
        OOC_CHAR8 OOC_IR__BuilderDesc_NewCharConst16_ValueOf_HexToInt(const OOC_CHAR8 str__ref[], OOC_LEN str_0d, OOC_CHAR8 end, OOC_INT32 *result) {
          register OOC_INT32 i0,i1,i2,i3;
          OOC_ALLOCATE_VPAR(str,OOC_CHAR8 ,str_0d)

          OOC_INITIALIZE_VPAR(str__ref,str,OOC_CHAR8 ,str_0d)
          *result = 0;
          i = 0;
          i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT32, 62886)));
          i1 = end;
          i0 = i0!=i1;
          if (!i0) goto l11;
          i0=0;
l3_loop:
          i2 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 62942)));
          i2 = OOC_IR__BuilderDesc_NewCharConst16_ValueOf_HexDigit(i2);
          i3 = *result;
          i2 = ((2147483647-i2)>>4)<i3;
          if (!i2) goto l6;
          return 0u;
l6:
          i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 63053)));
          i0 = OOC_IR__BuilderDesc_NewCharConst16_ValueOf_HexDigit(i0);
          *result = ((i3*16)+i0);
          i0 = i;
          i0 = i0+1;
          i = i0;
          i2 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 62886)));
          i2 = i2!=i1;
          if (i2) goto l3_loop;
l11:
          return 1u;
          ;
        }


      i = 0;
      hexCount = 0;
      i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT32, 63190)));
      i0 = i0!=0u;
      if (i0) goto l3;
      i0=0;i1=0;
      goto l13;
l3:
      i0=0;i1=0;
l4_loop:
      i2 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 63228)));
      i2 = OOC_IR__BuilderDesc_NewCharConst16_ValueOf_HexDigit(i2);
      i2 = i2>=0;
      if (!i2) goto l8;
      i1 = i1+1;
      hexCount = i1;
      
l8:
      i0 = i0+1;
      i = i0;
      i2 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 63190)));
      i2 = i2!=0u;
      if (i2) goto l4_loop;
l13:
      i2 = i0==3;
      if (i2) goto l16;
      i2=0u;
      goto l18;
l16:
      i2 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT8, 63332)));
      i3 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index((i0-1), str_0d, OOC_UINT32, 63341)));
      i2 = i2==i3;
      
l18:
      if (i2) goto l20;
      i2=0u;
      goto l26;
l20:
      i2 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT8, 63355)));
      i2 = i2==34u;
      if (i2) goto l23;
      i2 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT8, 63373)));
      i2 = i2==39u;
      
      goto l26;
l23:
      i2=1u;
l26:
      if (i2) goto l52;
      i2 = i0>=2;
      if (i2) goto l30;
      i2=0u;
      goto l32;
l30:
      i2 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index((i0-1), str_0d, OOC_UINT32, 63503)));
      i2 = i2==88u;
      
l32:
      if (i2) goto l34;
      i0=0u;
      goto l36;
l34:
      i0 = (i1+1)==i0;
      
l36:
      if (i0) goto l38;
      return (-1);
      goto l53;
l38:
      i0 = OOC_IR__BuilderDesc_NewCharConst16_ValueOf_HexToInt((void*)(OOC_INT32)str, str_0d, 88u, (void*)(OOC_INT32)&ord);
      if (i0) goto l41;
      i0=0u;
      goto l43;
l41:
      i0 = ord;
      i0 = 0<=i0;
      
l43:
      if (i0) goto l45;
      i0=0u;
      goto l47;
l45:
      i0 = ord;
      i0 = i0<=1114111;
      
l47:
      if (i0) goto l49;
      return (-1);
      goto l53;
l49:
      i0 = ord;
      return i0;
      goto l53;
l52:
      i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(1, str_0d, OOC_UINT8, 63471)));
      return i0;
l53:
      _failed_function(62383); return 0;
      ;
    }


  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 63970))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 63970))+8);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 63975)), 0);
  i0 = OOC_IR__BuilderDesc_NewCharConst16_ValueOf((void*)(_check_pointer(i0, 63975)), i1);
  v = i0;
  i1 = i0<0;
  if (i1) goto l11;
  i1 = i0<=255;
  if (i1) goto l9;
  i1 = i0<=65535;
  if (i1) goto l7;
  i0 = (OOC_INT32)Object__NewUCS4Char(i0);
  i1=3;
  goto l10;
l7:
  i0 = (OOC_INT32)Object__NewUCS4Char(i0);
  i1=2;
  goto l10;
l9:
  i0 = (OOC_INT32)Object__NewLatin1Char(i0);
  i1=1;
l10:
  i2 = (OOC_INT32)RT0__NewObject(_td_Object_Boxed__String.baseTypes[0]);
  Object_Boxed__StringDesc_INIT((Object_Boxed__String)i2, (Object__String)i0);
  i0 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(i1);
  i1 = (OOC_INT32)sym;
  i0 = (OOC_INT32)OOC_IR__NewConst((OOC_Scanner_SymList__Symbol)i1, (OOC_SymbolTable__Type)i0, (Object_Boxed__Object)i2);
  return (OOC_IR__Expression)i0;
  goto l12;
l11:
  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)sym;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 64006)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 4, (OOC_Scanner_SymList__Symbol)i1);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 64057))+20);
  return (OOC_IR__Expression)i0;
l12:
  _failed_function(62269); return 0;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_NewNil(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(16);
  i1 = (OOC_INT32)sym;
  i0 = (OOC_INT32)OOC_IR__NewConst((OOC_Scanner_SymList__Symbol)i1, (OOC_SymbolTable__Type)i0, (Object_Boxed__Object)(OOC_INT32)0);
  return (OOC_IR__Expression)i0;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_NewSize(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression type) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_SymbolTable__Type t;
  OOC_INT32 size;

  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)type;
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 64808)))), OOC_IR__BuilderDesc_AssertType)),OOC_IR__BuilderDesc_AssertType)((OOC_IR__Builder)i0, (OOC_IR__Expression)i1);
  t = (OOC_SymbolTable__Type)i2;
  i3 = *(OOC_INT32*)((_check_pointer(i2, 64836))+32);
  i3 = i3<0;
  if (i3) goto l3;
  i1 = *(OOC_INT32*)((_check_pointer(i2, 64932))+32);
  size = i1;
  
  goto l4;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 64884));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 64859)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 47, (OOC_Scanner_SymList__Symbol)i1);
  size = 1;
  i1=1;
l4:
  i1 = (OOC_INT32)Object_BigInt__NewInt(i1);
  i2 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(6);
  i3 = (OOC_INT32)sym;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 64960)))), OOC_IR__BuilderDesc_NewConst)),OOC_IR__BuilderDesc_NewConst)((OOC_IR__Builder)i0, (OOC_Scanner_SymList__Symbol)i3, (OOC_SymbolTable__Type)i2, (Object_Boxed__Object)i1);
  return (OOC_IR__Expression)i0;
  ;
}

OOC_IR__Const OOC_IR__BuilderDesc_GetOne(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)Object_BigInt__NewInt(1);
  i1 = (OOC_INT32)b;
  i2 = (OOC_INT32)sym;
  i3 = (OOC_INT32)type;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 65147)))), OOC_IR__BuilderDesc_NewConst)),OOC_IR__BuilderDesc_NewConst)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i2, (OOC_SymbolTable__Type)i3, (Object_Boxed__Object)i0);
  return (OOC_IR__Const)i0;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_ValidSetElement(OOC_IR__Builder b, OOC_IR__Expression expr, OOC_SymbolTable__Type set) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  Object_Boxed__Object val;
  Object_BigInt__BigInt min;
  Object_BigInt__BigInt max;
  Object_BigInt__BigInt element;
  auto OOC_IR__Expression OOC_IR__BuilderDesc_ValidSetElement_MinElement(void);
    
    OOC_IR__Expression OOC_IR__BuilderDesc_ValidSetElement_MinElement(void) {
      register OOC_INT32 i0,i1,i2,i3;

      i0 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(4);
      i1 = (OOC_INT32)expr;
      i2 = (OOC_INT32)b;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 65901));
      i3 = (OOC_INT32)min;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 65887)))), OOC_IR__BuilderDesc_NewConst)),OOC_IR__BuilderDesc_NewConst)((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i1, (OOC_SymbolTable__Type)i0, (Object_Boxed__Object)i3);
      return (OOC_IR__Expression)i0;
      ;
    }


  i0 = (OOC_INT32)set;
  i1 = (OOC_INT32)OOC_SymbolTable_Predef__GetMin((OOC_SymbolTable__Type)i0);
  val = (Object_Boxed__Object)i1;
  i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 66022)))), &_td_Object_BigInt__BigIntDesc, 66022);
  min = (Object_BigInt__BigInt)i1;
  i0 = (OOC_INT32)OOC_SymbolTable_Predef__GetMax((OOC_SymbolTable__Type)i0);
  val = (Object_Boxed__Object)i0;
  i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 66080)))), &_td_Object_BigInt__BigIntDesc, 66080);
  max = (Object_BigInt__BigInt)i0;
  i2 = (OOC_INT32)b;
  i3 = (OOC_INT32)expr;
  i3 = (OOC_INT32)OOC_IR__BuilderDesc_AssertInteger((OOC_IR__Builder)i2, (OOC_IR__Expression)i3);
  expr = (OOC_IR__Expression)i3;
  i4 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 66139)))), &_td_OOC_IR__ConstDesc);
  if (!i4) goto l10;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 66171))+8);
  i4 = _type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 66185)))), &_td_Object_BigInt__BigIntDesc, 66185);
  element = (Object_BigInt__BigInt)i4;
  i5 = Object_BigInt__BigIntDesc_Cmp((Object_BigInt__BigInt)i4, (Object__Object)i1);
  i5 = i5<0;
  if (i5) goto l5;
  i4 = Object_BigInt__BigIntDesc_Cmp((Object_BigInt__BigInt)i4, (Object__Object)i0);
  i4 = i4>0;
  
  goto l7;
l5:
  i4=1u;
l7:
  if (!i4) goto l10;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 66301));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 66266)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i2, 14, (OOC_Scanner_SymList__Symbol)i3);
  i1 = Object_BigInt__BigIntDesc_ToLongInt((Object_BigInt__BigInt)i1);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 66318))+36);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 66318))+36);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 66329)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i4, "start", 6, i1);
  i0 = Object_BigInt__BigIntDesc_ToLongInt((Object_BigInt__BigInt)i0);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 66381))+36);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 66381))+36);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 66392)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i2, "end", 4, (i0+1));
  i0 = (OOC_INT32)OOC_IR__BuilderDesc_ValidSetElement_MinElement();
  return (OOC_IR__Expression)i0;
l10:
  i0 = (OOC_INT32)expr;
  return (OOC_IR__Expression)i0;
  ;
}

void OOC_IR__InitOperator(OOC_IR__Operator op, OOC_Scanner_SymList__Symbol sym, OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)type;
  i1 = (OOC_INT32)sym;
  i2 = (OOC_INT32)op;
  OOC_IR__InitExpression((OOC_IR__Expression)i2, (OOC_Scanner_SymList__Symbol)i1, (OOC_SymbolTable__Type)i0);
  return;
  ;
}

static void OOC_IR__InitAbs(OOC_IR__Abs abs, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression operand) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)operand;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 66985))+4);
  i2 = (OOC_INT32)abs;
  i3 = (OOC_INT32)sym;
  OOC_IR__InitOperator((OOC_IR__Operator)i2, (OOC_Scanner_SymList__Symbol)i3, (OOC_SymbolTable__Type)i1);
  *(OOC_INT32*)((_check_pointer(i2, 67001))+8) = i0;
  return;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_NewAbs(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression operand) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__Abs.baseTypes[0]);
  i1 = (OOC_INT32)operand;
  i2 = (OOC_INT32)b;
  i1 = (OOC_INT32)OOC_IR__BuilderDesc_AssertNumeric((OOC_IR__Builder)i2, (OOC_IR__Expression)i1);
  i2 = (OOC_INT32)sym;
  OOC_IR__InitAbs((OOC_IR__Abs)i0, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i1);
  return (OOC_IR__Expression)i0;
  ;
}

void OOC_IR__VisitorDesc_VisitAbs(OOC_IR__Visitor v, OOC_IR__Abs abs) {

  return;
  ;
}

void OOC_IR__AbsDesc_Accept(OOC_IR__Abs abs, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)abs;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 67370)))), OOC_IR__VisitorDesc_VisitAbs)),OOC_IR__VisitorDesc_VisitAbs)((OOC_IR__Visitor)i0, (OOC_IR__Abs)i1);
  return;
  ;
}

static void OOC_IR__InitAdr(OOC_IR__Adr adr, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression design) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(12);
  i1 = (OOC_INT32)adr;
  i2 = (OOC_INT32)sym;
  OOC_IR__InitOperator((OOC_IR__Operator)i1, (OOC_Scanner_SymList__Symbol)i2, (OOC_SymbolTable__Type)i0);
  i0 = (OOC_INT32)design;
  *(OOC_INT32*)((_check_pointer(i1, 67641))+8) = i0;
  return;
  ;
}

OOC_IR__Adr OOC_IR__BuilderDesc_NewAdr(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression design) {
  register OOC_INT32 i0,i1,i2;
  OOC_IR__Adr adr;
  auto OOC_IR__Expression OOC_IR__BuilderDesc_NewAdr_AssertAddressable(OOC_IR__Expression expr);
    
    OOC_IR__Expression OOC_IR__BuilderDesc_NewAdr_AssertAddressable(OOC_IR__Expression expr) {
      register OOC_INT32 i0,i1;
      OOC_IR__Expression e;
      OOC_CHAR8 hasAddress;
      OOC_CHAR8 dummy;

      i0 = (OOC_INT32)expr;
      e = (OOC_IR__Expression)i0;
      hasAddress = 1u;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 67959)))), &_td_OOC_IR__VarDesc);
      if (i1) goto l30;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 67977)))), &_td_OOC_IR__DerefDesc);
      if (i1) goto l28;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 67997)))), &_td_OOC_IR__IndexDesc);
      if (i1) goto l26;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 68017)))), &_td_OOC_IR__SelectFieldDesc);
      if (i1) goto l24;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 68043)))), &_td_OOC_IR__TypeGuardDesc);
      if (i1) goto l22;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 68067)))), &_td_OOC_IR__ProcedureRefDesc);
      if (i1) goto l20;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 68094)))), &_td_OOC_IR__ConstDesc);
      if (i1) goto l15;
      hasAddress = 0u;
      i0=0u;
      goto l31;
l15:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 68134))+4);
      i1 = OOC_SymbolTable_TypeRules__IsCharType((OOC_SymbolTable__Type)i1);
      if (!i1) goto l18;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 68206))+4);
      i0 = (OOC_INT32)OOC_SymbolTable_TypeRules__MatchingStringConst((OOC_SymbolTable__Type)i0);
      i1 = (OOC_INT32)b;
      i0 = OOC_IR__BuilderDesc_Widen((OOC_IR__Builder)i1, (void*)(OOC_INT32)&expr, (OOC_SymbolTable__Type)i0);
      dummy = i0;
l18:
      i0 = (OOC_INT32)expr;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 68271))+4);
      i0 = OOC_SymbolTable_TypeRules__IsStringConst((OOC_SymbolTable__Type)i0);
      hasAddress = i0;
      
      goto l31;
l20:
      i0=1u;
      goto l31;
l22:
      i0=1u;
      goto l31;
l24:
      i0=1u;
      goto l31;
l26:
      i0=1u;
      goto l31;
l28:
      i0=1u;
      goto l31;
l30:
      i0=1u;
l31:
      i0 = !i0;
      if (!i0) goto l34;
      i0 = (OOC_INT32)expr;
      i1 = (OOC_INT32)b;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 68393));
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 68365)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 51, (OOC_Scanner_SymList__Symbol)i0);
l34:
      i0 = (OOC_INT32)expr;
      return (OOC_IR__Expression)i0;
      ;
    }


  adr = (OOC_IR__Adr)((OOC_INT32)RT0__NewObject(_td_OOC_IR__Adr.baseTypes[0]));
  i0 = (OOC_INT32)design;
  i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewAdr_AssertAddressable((OOC_IR__Expression)i0);
  i1 = (OOC_INT32)sym;
  i2 = (OOC_INT32)adr;
  OOC_IR__InitAdr((OOC_IR__Adr)i2, (OOC_Scanner_SymList__Symbol)i1, (OOC_IR__Expression)i0);
  return (OOC_IR__Adr)i2;
  ;
}

void OOC_IR__VisitorDesc_VisitAdr(OOC_IR__Visitor v, OOC_IR__Adr adr) {

  return;
  ;
}

void OOC_IR__AdrDesc_Accept(OOC_IR__Adr adr, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)adr;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 68693)))), OOC_IR__VisitorDesc_VisitAdr)),OOC_IR__VisitorDesc_VisitAdr)((OOC_IR__Visitor)i0, (OOC_IR__Adr)i1);
  return;
  ;
}

static void OOC_IR__InitAsh(OOC_IR__Ash ash, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression value, OOC_IR__Expression exp) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(6);
  i1 = (OOC_INT32)ash;
  i2 = (OOC_INT32)sym;
  OOC_IR__InitOperator((OOC_IR__Operator)i1, (OOC_Scanner_SymList__Symbol)i2, (OOC_SymbolTable__Type)i0);
  i0 = (OOC_INT32)value;
  *(OOC_INT32*)((_check_pointer(i1, 68972))+8) = i0;
  i0 = (OOC_INT32)exp;
  *(OOC_INT32*)((_check_pointer(i1, 68997))+12) = i0;
  return;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_NewAsh(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression value, OOC_IR__Expression exp) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__Ash.baseTypes[0]);
  i1 = (OOC_INT32)exp;
  i2 = (OOC_INT32)b;
  i1 = (OOC_INT32)OOC_IR__BuilderDesc_AssertInteger((OOC_IR__Builder)i2, (OOC_IR__Expression)i1);
  i3 = (OOC_INT32)value;
  i2 = (OOC_INT32)OOC_IR__BuilderDesc_AssertInteger((OOC_IR__Builder)i2, (OOC_IR__Expression)i3);
  i3 = (OOC_INT32)sym;
  OOC_IR__InitAsh((OOC_IR__Ash)i0, (OOC_Scanner_SymList__Symbol)i3, (OOC_IR__Expression)i2, (OOC_IR__Expression)i1);
  return (OOC_IR__Expression)i0;
  ;
}

void OOC_IR__VisitorDesc_VisitAsh(OOC_IR__Visitor v, OOC_IR__Ash ash) {

  return;
  ;
}

void OOC_IR__AshDesc_Accept(OOC_IR__Ash ash, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)ash;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 69381)))), OOC_IR__VisitorDesc_VisitAsh)),OOC_IR__VisitorDesc_VisitAsh)((OOC_IR__Visitor)i0, (OOC_IR__Ash)i1);
  return;
  ;
}

static void OOC_IR__InitBinaryArith(OOC_IR__BinaryArith op, OOC_Scanner_SymList__Symbol sym, OOC_INT8 variant, OOC_IR__Expression left, OOC_IR__Expression right, OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)type;
  i1 = (OOC_INT32)sym;
  i2 = (OOC_INT32)op;
  OOC_IR__InitOperator((OOC_IR__Operator)i2, (OOC_Scanner_SymList__Symbol)i1, (OOC_SymbolTable__Type)i0);
  i0 = variant;
  *(OOC_INT8*)((_check_pointer(i2, 69691))+8) = i0;
  i0 = (OOC_INT32)left;
  *(OOC_INT32*)((_check_pointer(i2, 69718))+12) = i0;
  i0 = (OOC_INT32)right;
  *(OOC_INT32*)((_check_pointer(i2, 69739))+16) = i0;
  return;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_NewBinaryArith(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_INT8 variant, OOC_IR__Expression left, OOC_IR__Expression right) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_IR__BinaryArith op;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__BinaryArith.baseTypes[0]);
  op = (OOC_IR__BinaryArith)i0;
  i1 = (OOC_INT32)right;
  i2 = (OOC_INT32)left;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 69977))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 69965))+4);
  i3 = OOC_SymbolTable_TypeRules__SameType((OOC_SymbolTable__Type)i4, (OOC_SymbolTable__Type)i3);
  _assert(i3, 127, 69942);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 70042))+4);
  i4 = (OOC_INT32)sym;
  i5 = variant;
  OOC_IR__InitBinaryArith((OOC_IR__BinaryArith)i0, (OOC_Scanner_SymList__Symbol)i4, i5, (OOC_IR__Expression)i2, (OOC_IR__Expression)i1, (OOC_SymbolTable__Type)i3);
  return (OOC_IR__Expression)i0;
  ;
}

void OOC_IR__VisitorDesc_VisitBinaryArith(OOC_IR__Visitor v, OOC_IR__BinaryArith op) {

  return;
  ;
}

void OOC_IR__BinaryArithDesc_Accept(OOC_IR__BinaryArith op, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)op;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 70247)))), OOC_IR__VisitorDesc_VisitBinaryArith)),OOC_IR__VisitorDesc_VisitBinaryArith)((OOC_IR__Visitor)i0, (OOC_IR__BinaryArith)i1);
  return;
  ;
}

static void OOC_IR__InitBooleanOp(OOC_IR__BooleanOp op, OOC_Scanner_SymList__Symbol sym, OOC_INT8 variant, OOC_IR__Expression left, OOC_IR__Expression right, OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)type;
  i1 = (OOC_INT32)sym;
  i2 = (OOC_INT32)op;
  OOC_IR__InitOperator((OOC_IR__Operator)i2, (OOC_Scanner_SymList__Symbol)i1, (OOC_SymbolTable__Type)i0);
  i0 = variant;
  *(OOC_INT8*)((_check_pointer(i2, 70558))+8) = i0;
  i0 = (OOC_INT32)left;
  *(OOC_INT32*)((_check_pointer(i2, 70585))+12) = i0;
  i0 = (OOC_INT32)right;
  *(OOC_INT32*)((_check_pointer(i2, 70606))+16) = i0;
  return;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_NewBooleanOp(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_INT8 variant, OOC_IR__Expression left, OOC_IR__Expression right) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_IR__BooleanOp op;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__BooleanOp.baseTypes[0]);
  op = (OOC_IR__BooleanOp)i0;
  i1 = (OOC_INT32)left;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 70815))+4);
  i2 = *(OOC_INT16*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 70826)))), &_td_OOC_SymbolTable__PredefTypeDesc, 70826)), 70837))+40);
  _assert((i2==0), 127, 70803);
  i2 = (OOC_INT32)right;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 70878))+4);
  i3 = *(OOC_INT16*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 70889)))), &_td_OOC_SymbolTable__PredefTypeDesc, 70889)), 70900))+40);
  _assert((i3==0), 127, 70865);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 70978))+4);
  i4 = (OOC_INT32)sym;
  i5 = variant;
  OOC_IR__InitBooleanOp((OOC_IR__BooleanOp)i0, (OOC_Scanner_SymList__Symbol)i4, i5, (OOC_IR__Expression)i1, (OOC_IR__Expression)i2, (OOC_SymbolTable__Type)i3);
  return (OOC_IR__Expression)i0;
  ;
}

void OOC_IR__VisitorDesc_VisitBooleanOp(OOC_IR__Visitor v, OOC_IR__BooleanOp op) {

  return;
  ;
}

void OOC_IR__BooleanOpDesc_Accept(OOC_IR__BooleanOp op, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)op;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 71173)))), OOC_IR__VisitorDesc_VisitBooleanOp)),OOC_IR__VisitorDesc_VisitBooleanOp)((OOC_IR__Visitor)i0, (OOC_IR__BooleanOp)i1);
  return;
  ;
}

static void OOC_IR__InitCap(OOC_IR__Cap cap, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression expr) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)expr;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 71414))+4);
  i2 = (OOC_INT32)cap;
  i3 = (OOC_INT32)sym;
  OOC_IR__InitOperator((OOC_IR__Operator)i2, (OOC_Scanner_SymList__Symbol)i3, (OOC_SymbolTable__Type)i1);
  *(OOC_INT32*)((_check_pointer(i2, 71430))+8) = i0;
  return;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_NewCap(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression expr) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__Cap.baseTypes[0]);
  i1 = (OOC_INT32)expr;
  i2 = (OOC_INT32)b;
  i1 = (OOC_INT32)OOC_IR__BuilderDesc_AssertChar((OOC_IR__Builder)i2, (OOC_IR__Expression)i1);
  i2 = (OOC_INT32)sym;
  OOC_IR__InitCap((OOC_IR__Cap)i0, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i1);
  return (OOC_IR__Expression)i0;
  ;
}

void OOC_IR__VisitorDesc_VisitCap(OOC_IR__Visitor v, OOC_IR__Cap cap) {

  return;
  ;
}

void OOC_IR__CapDesc_Accept(OOC_IR__Cap cap, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)cap;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 71787)))), OOC_IR__VisitorDesc_VisitCap)),OOC_IR__VisitorDesc_VisitCap)((OOC_IR__Visitor)i0, (OOC_IR__Cap)i1);
  return;
  ;
}

static void OOC_IR__InitChangeElement(OOC_IR__ChangeElement ch, OOC_Scanner_SymList__Symbol sym, OOC_INT8 variant, OOC_IR__Expression set, OOC_IR__Expression element) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)set;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 72105))+4);
  i2 = (OOC_INT32)ch;
  i3 = (OOC_INT32)sym;
  OOC_IR__InitOperator((OOC_IR__Operator)i2, (OOC_Scanner_SymList__Symbol)i3, (OOC_SymbolTable__Type)i1);
  i1 = variant;
  *(OOC_INT8*)((_check_pointer(i2, 72120))+8) = i1;
  *(OOC_INT32*)((_check_pointer(i2, 72148))+12) = i0;
  i0 = (OOC_INT32)element;
  *(OOC_INT32*)((_check_pointer(i2, 72168))+16) = i0;
  return;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_NewChangeElement(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_INT8 variant, OOC_IR__Expression set, OOC_IR__Expression element) {
  register OOC_INT32 i0,i1,i2,i3,i4;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__ChangeElement.baseTypes[0]);
  i1 = (OOC_INT32)element;
  i2 = (OOC_INT32)set;
  i3 = variant;
  i4 = (OOC_INT32)sym;
  OOC_IR__InitChangeElement((OOC_IR__ChangeElement)i0, (OOC_Scanner_SymList__Symbol)i4, i3, (OOC_IR__Expression)i2, (OOC_IR__Expression)i1);
  return (OOC_IR__Expression)i0;
  ;
}

void OOC_IR__VisitorDesc_VisitChangeElement(OOC_IR__Visitor v, OOC_IR__ChangeElement ch) {

  return;
  ;
}

void OOC_IR__ChangeElementDesc_Accept(OOC_IR__ChangeElement ch, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)ch;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 72685)))), OOC_IR__VisitorDesc_VisitChangeElement)),OOC_IR__VisitorDesc_VisitChangeElement)((OOC_IR__Visitor)i0, (OOC_IR__ChangeElement)i1);
  return;
  ;
}

static void OOC_IR__InitCompare(OOC_IR__Compare op, OOC_Scanner_SymList__Symbol sym, OOC_INT8 variant, OOC_IR__Expression left, OOC_IR__Expression right) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(0);
  i1 = (OOC_INT32)op;
  i2 = (OOC_INT32)sym;
  OOC_IR__InitOperator((OOC_IR__Operator)i1, (OOC_Scanner_SymList__Symbol)i2, (OOC_SymbolTable__Type)i0);
  i0 = (OOC_INT32)left;
  *(OOC_INT32*)((_check_pointer(i1, 73001))+12) = i0;
  i0 = (OOC_INT32)right;
  *(OOC_INT32*)((_check_pointer(i1, 73022))+16) = i0;
  i0 = variant;
  *(OOC_INT8*)((_check_pointer(i1, 73045))+8) = i0;
  return;
  ;
}

OOC_IR__Compare OOC_IR__BuilderDesc_NewCompare(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression left, OOC_IR__Expression right) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT8 variant;

  i0 = (OOC_INT32)sym;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 73288))+4);
  switch (i1) {
  case 9:
    variant = 10;
    goto l9;
  case 10:
    variant = 11;
    goto l9;
  case 11:
    variant = 12;
    goto l9;
  case 12:
    variant = 13;
    goto l9;
  case 13:
    variant = 14;
    goto l9;
  case 14:
    variant = 15;
    goto l9;
  default:
    _failed_case(i1, 73280);
    goto l9;
  }
l9:
  i1 = (OOC_INT32)left;
  i2 = (OOC_INT32)right;
  i3 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__Compare.baseTypes[0]);
  i4 = variant;
  OOC_IR__InitCompare((OOC_IR__Compare)i3, (OOC_Scanner_SymList__Symbol)i0, i4, (OOC_IR__Expression)i1, (OOC_IR__Expression)i2);
  return (OOC_IR__Compare)i3;
  ;
}

void OOC_IR__VisitorDesc_VisitCompare(OOC_IR__Visitor v, OOC_IR__Compare op) {

  return;
  ;
}

void OOC_IR__CompareDesc_Accept(OOC_IR__Compare op, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)op;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 73757)))), OOC_IR__VisitorDesc_VisitCompare)),OOC_IR__VisitorDesc_VisitCompare)((OOC_IR__Visitor)i0, (OOC_IR__Compare)i1);
  return;
  ;
}

static void OOC_IR__InitConcat(OOC_IR__Concat op, OOC_Scanner_SymList__Symbol sym, OOC_SymbolTable__Type type, OOC_IR__ExpressionList strings) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)type;
  i1 = (OOC_INT32)sym;
  i2 = (OOC_INT32)op;
  OOC_IR__InitOperator((OOC_IR__Operator)i2, (OOC_Scanner_SymList__Symbol)i1, (OOC_SymbolTable__Type)i0);
  i0 = (OOC_INT32)strings;
  *(OOC_INT32*)((_check_pointer(i2, 74057))+8) = i0;
  return;
  ;
}

OOC_IR__Concat OOC_IR__BuilderDesc_NewConcat(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__ExpressionList strings) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
  OOC_INT16 id;
  OOC_INT32 i;
  OOC_SymbolTable__Type type;
  OOC_INT16 tid;
  OOC_CHAR8 dummy;

  id = (-1);
  i0 = (OOC_INT32)strings;
  i = 0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 74329)), 0);
  i2 = (OOC_INT32)sym;
  i3 = 0<i1;
  if (i3) goto l3;
  i1=(-1);
  goto l28;
l3:
  i3 = (OOC_INT32)b;
  i4=0;i5=(-1);
l4_loop:
  i6 = _check_pointer(i0, 74358);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i4, i7, OOC_UINT32, 74358))*4);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 74361))+4);
  type = (OOC_SymbolTable__Type)i6;
  tid = 32767;
  i7 = OOC_SymbolTable_TypeRules__IsStringConst((OOC_SymbolTable__Type)i6);
  if (i7) goto l18;
  i7 = OOC_SymbolTable_TypeRules__IsCharType((OOC_SymbolTable__Type)i6);
  if (i7) goto l12;
  i6 = OOC_SymbolTable_TypeRules__IsSTRING((OOC_SymbolTable__Type)i6);
  i6 = !i6;
  if (!i6) goto l11;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 74852)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i3, 7, (OOC_Scanner_SymList__Symbol)i2);
l11:
  i6=32767;
  goto l19;
l12:
  i6 = (OOC_INT32)OOC_SymbolTable_TypeRules__MatchingStringConst((OOC_SymbolTable__Type)i6);
  i7 = _check_pointer(i0, 74610);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i6 = OOC_IR__BuilderDesc_Widen((OOC_IR__Builder)i3, (void*)(i7+(_check_index(i4, i8, OOC_UINT32, 74610))*4), (OOC_SymbolTable__Type)i6);
  if (i6) goto l15;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 74727)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i3, 7, (OOC_Scanner_SymList__Symbol)i2);
  i6=32767;
  goto l19;
l15:
  i6 = _check_pointer(i0, 74674);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i4, i7, OOC_UINT32, 74674))*4);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 74677))+4);
  i6 = *(OOC_INT16*)((_check_pointer((_type_guard(i6, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 74687)))), &_td_OOC_SymbolTable__PredefTypeDesc, 74687)), 74698))+40);
  tid = i6;
  
  goto l19;
l18:
  i6 = *(OOC_INT16*)((_check_pointer((_type_guard(i6, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 74489)))), &_td_OOC_SymbolTable__PredefTypeDesc, 74489)), 74500))+40);
  tid = i6;
  
l19:
  i7 = i6>i5;
  if (!i7) goto l23;
  id = i6;
  i5=i6;
l23:
  i4 = i4+1;
  i = i4;
  i6 = i4<i1;
  if (i6) goto l4_loop;
l27:
  i1=i5;
l28:
  i3 = i1<32767;
  if (i3) goto l42;
  i1 = (OOC_INT32)b;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 75167))+32);
  type = (OOC_SymbolTable__Type)i3;
  i = 0;
  i4 = OOC_ARRAY_LENGTH((_check_pointer(i0, 75211)), 0);
  i5 = 0<i4;
  if (!i5) goto l41;
  i5=0;
l33_loop:
  i6 = _check_pointer(i0, 75254);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i5, i7, OOC_UINT32, 75254))*4);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 75257))+4);
  i6 = OOC_SymbolTable_TypeRules__IsStringConst((OOC_SymbolTable__Type)i6);
  if (!i6) goto l36;
  i6 = _check_pointer(i0, 75362);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = OOC_IR__BuilderDesc_Widen((OOC_IR__Builder)i1, (void*)(i6+(_check_index(i5, i7, OOC_UINT32, 75362))*4), (OOC_SymbolTable__Type)i3);
  dummy = i6;
  _assert(i6, 127, 75384);
l36:
  i5 = i5+1;
  i = i5;
  i6 = i5<i4;
  if (i6) goto l33_loop;
l41:
  i1=i3;
  goto l51;
l42:
  i1 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(i1);
  type = (OOC_SymbolTable__Type)i1;
  i = 0;
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i0, 75057)), 0);
  i4 = 0<i3;
  if (!i4) goto l51;
  i4 = (OOC_INT32)b;
  i5=0;
l45_loop:
  i6 = _check_pointer(i0, 75097);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = OOC_IR__BuilderDesc_Widen((OOC_IR__Builder)i4, (void*)(i6+(_check_index(i5, i7, OOC_UINT32, 75097))*4), (OOC_SymbolTable__Type)i1);
  dummy = i6;
  _assert(i6, 127, 75117);
  i5 = i5+1;
  i = i5;
  i6 = i5<i3;
  if (i6) goto l45_loop;
l51:
  i3 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__Concat.baseTypes[0]);
  OOC_IR__InitConcat((OOC_IR__Concat)i3, (OOC_Scanner_SymList__Symbol)i2, (OOC_SymbolTable__Type)i1, (OOC_IR__ExpressionList)i0);
  return (OOC_IR__Concat)i3;
  ;
}

void OOC_IR__VisitorDesc_VisitConcat(OOC_IR__Visitor v, OOC_IR__Concat op) {

  return;
  ;
}

void OOC_IR__ConcatDesc_Accept(OOC_IR__Concat op, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)op;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 75664)))), OOC_IR__VisitorDesc_VisitConcat)),OOC_IR__VisitorDesc_VisitConcat)((OOC_IR__Visitor)i0, (OOC_IR__Concat)i1);
  return;
  ;
}

static void OOC_IR__InitConstructor(OOC_IR__Constructor cons, OOC_Scanner_SymList__Symbol sym, OOC_IR__NewObject alloc, OOC_IR__Call init) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)alloc;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 75967))+4);
  i2 = (OOC_INT32)cons;
  i3 = (OOC_INT32)sym;
  OOC_IR__InitOperator((OOC_IR__Operator)i2, (OOC_Scanner_SymList__Symbol)i3, (OOC_SymbolTable__Type)i1);
  *(OOC_INT32*)((_check_pointer(i2, 75983))+8) = i0;
  i0 = (OOC_INT32)init;
  *(OOC_INT32*)((_check_pointer(i2, 76008))+12) = i0;
  return;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_NewConstructor(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression type, OOC_IR__ExpressionList arguments, OOC_SymbolTable__Item context, OOC_Scanner_SymList__Symbol endOfArgsSym) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
  OOC_SymbolTable__Type consType;
  OOC_SymbolTable__Type ptr;
  OOC_SymbolTable__Type qualRecord;
  OOC_SymbolTable__Record consClass;
  OOC_SymbolTable__Name n;
  OOC_SymbolTable__Declaration initDecl;
  OOC_IR__Call init;
  OOC_IR__Expression pseudoDesign;
  OOC_IR__Expression expr;

  i0 = (OOC_INT32)type;
  i1 = (OOC_INT32)b;
  i2 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 76573)))), &_td_OOC_IR__TypeRefDesc));
  if (i2) goto l3;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 76613)))), &_td_OOC_IR__TypeRefDesc, 76613)), 76621))+12);
  i2 = OOC_SymbolTable_TypeRules__IsRecordPointer((OOC_SymbolTable__Type)i2);
  i2 = !i2;
  
  goto l5;
l3:
  i2=1u;
l5:
  if (!i2) goto l7;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 76686));
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 76651)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i1, 73, (OOC_Scanner_SymList__Symbol)i2);
  return (OOC_IR__Expression)i2;
l7:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 76723)))), &_td_OOC_IR__TypeRefDesc, 76723)), 76731))+12);
  i2 = (OOC_INT32)OOC_SymbolTable__Expand((OOC_SymbolTable__Type)i2);
  consType = (OOC_SymbolTable__Type)i2;
  i3 = (OOC_INT32)OOC_SymbolTable_TypeRules__PointerBaseType((OOC_SymbolTable__Type)i2);
  ptr = (OOC_SymbolTable__Type)i3;
  i4 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 76847)))), OOC_SymbolTable__TypeDesc_Closure)),OOC_SymbolTable__TypeDesc_Closure)((OOC_SymbolTable__Type)i2, (OOC_SymbolTable__Type)i3);
  qualRecord = (OOC_SymbolTable__Type)i4;
  i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 76876)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i3);
  ptr = (OOC_SymbolTable__Type)i3;
  i3 = _type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 76913)))), &_td_OOC_SymbolTable__RecordDesc, 76913);
  consClass = (OOC_SymbolTable__Record)i3;
  i5 = (OOC_INT32)sym;
  i6 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 76981)))), OOC_IR__BuilderDesc_GetName2)),OOC_IR__BuilderDesc_GetName2)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i5, "INIT", 5);
  n = (OOC_SymbolTable__Name)i6;
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 77041))+52);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 77041))+52);
  i8 = (OOC_INT32)context;
  i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 77044)))), OOC_SymbolTable__NamespaceDesc_Identify)),OOC_SymbolTable__NamespaceDesc_Identify)((OOC_SymbolTable__Namespace)i3, (OOC_SymbolTable__Item)i8, (OOC_SymbolTable__Name)i6, 1u);
  initDecl = (OOC_SymbolTable__Declaration)i3;
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 77098))+16);
  OOC_SymbolTable_Uses__Mark((OOC_SymbolTable__Declaration)i3, (OOC_SymbolTable_Uses__Uses)i7, (OOC_SymbolTable__Name)i6);
  init = (OOC_IR__Call)0;
  i6 = i3==0;
  if (i6) goto l10;
  i6 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 77164)))), &_td_OOC_SymbolTable__ProcDeclDesc));
  
  goto l12;
l10:
  i6=1u;
l12:
  if (i6) goto l21;
  i6 = *(OOC_INT32*)((_check_pointer(i3, 77322))+24);
  i7 = *(OOC_INT32*)((_check_pointer(i5, 77340))+16);
  i6 = i6>i7;
  if (!i6) goto l16;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 77396));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 77360)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 75, (OOC_Scanner_SymList__Symbol)i0);
l16:
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 77444)))), OOC_IR__BuilderDesc_NewNil)),OOC_IR__BuilderDesc_NewNil)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i5);
  pseudoDesign = (OOC_IR__Expression)i0;
  i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewSelectProc((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i5, (OOC_IR__Expression)i0, (OOC_SymbolTable__Type)i4, (OOC_SymbolTable__ProcDecl)(_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 77578)))), &_td_OOC_SymbolTable__ProcDeclDesc, 77578)), (OOC_Scanner_SymList__Symbol)i5, 1u);
  pseudoDesign = (OOC_IR__Expression)i0;
  i3 = (OOC_INT32)endOfArgsSym;
  i4 = (OOC_INT32)arguments;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 77616)))), OOC_IR__BuilderDesc_NewCall)),OOC_IR__BuilderDesc_NewCall)((OOC_IR__Builder)i1, (OOC_IR__Expression)i0, (OOC_IR__ExpressionList)i4, 0u, (OOC_SymbolTable__Item)i8, (OOC_Scanner_SymList__Symbol)i3);
  expr = (OOC_IR__Expression)i0;
  i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 77696)))), &_td_OOC_IR__CallDesc);
  if (i3) goto l19;
  i0=0;
  goto l25;
l19:
  i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 77731)))), &_td_OOC_IR__CallDesc, 77731);
  
  goto l25;
l21:
  i0 = (OOC_INT32)arguments;
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i0, 77209)), 0);
  i3 = i3!=0;
  if (!i3) goto l24;
  i0 = _check_pointer(i0, 77274);
  i3 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i3, OOC_UINT8, 77274))*4);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 77277));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 77238)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i1, 39, (OOC_Scanner_SymList__Symbol)i0);
  return (OOC_IR__Expression)i0;
l24:
  i0=0;
l25:
  i3 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__Constructor.baseTypes[0]);
  i2 = (OOC_INT32)OOC_SymbolTable__Expand((OOC_SymbolTable__Type)i2);
  i1 = (OOC_INT32)OOC_IR__BuilderDesc_NewNewObject((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i5, (OOC_SymbolTable__Type)i2, (OOC_IR__ExpressionList)0);
  OOC_IR__InitConstructor((OOC_IR__Constructor)i3, (OOC_Scanner_SymList__Symbol)i5, (OOC_IR__NewObject)i1, (OOC_IR__Call)i0);
  return (OOC_IR__Expression)i3;
  ;
}

void OOC_IR__VisitorDesc_VisitConstructor(OOC_IR__Visitor v, OOC_IR__Constructor cons) {

  return;
  ;
}

void OOC_IR__ConstructorDesc_Accept(OOC_IR__Constructor cons, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)cons;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 78095)))), OOC_IR__VisitorDesc_VisitConstructor)),OOC_IR__VisitorDesc_VisitConstructor)((OOC_IR__Visitor)i0, (OOC_IR__Constructor)i1);
  return;
  ;
}

static void OOC_IR__InitCurrentException(OOC_IR__CurrentException ce, OOC_Scanner_SymList__Symbol sym, OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)type;
  i1 = (OOC_INT32)sym;
  i2 = (OOC_INT32)ce;
  OOC_IR__InitOperator((OOC_IR__Operator)i2, (OOC_Scanner_SymList__Symbol)i1, (OOC_SymbolTable__Type)i0);
  *(OOC_INT32*)((_check_pointer(i2, 78413))+8) = (OOC_INT32)0;
  return;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_NewCurrentException(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__CurrentException.baseTypes[0]);
  i1 = (OOC_INT32)type;
  i2 = (OOC_INT32)sym;
  OOC_IR__InitCurrentException((OOC_IR__CurrentException)i0, (OOC_Scanner_SymList__Symbol)i2, (OOC_SymbolTable__Type)i1);
  return (OOC_IR__Expression)i0;
  ;
}

void OOC_IR__VisitorDesc_VisitCurrentException(OOC_IR__Visitor v, OOC_IR__CurrentException ce) {

  return;
  ;
}

void OOC_IR__CurrentExceptionDesc_Accept(OOC_IR__CurrentException ce, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)ce;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 78900)))), OOC_IR__VisitorDesc_VisitCurrentException)),OOC_IR__VisitorDesc_VisitCurrentException)((OOC_IR__Visitor)i0, (OOC_IR__CurrentException)i1);
  return;
  ;
}

static void OOC_IR__InitDeref(OOC_IR__Deref d, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression pointer, OOC_CHAR8 checkPointer) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_SymbolTable__Type baseType;

  i0 = (OOC_INT32)pointer;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 79257))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 79257))+4);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 79262)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i2);
  baseType = (OOC_SymbolTable__Type)i1;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 79298)))), OOC_SymbolTable__TypeDesc_Bound)),OOC_SymbolTable__TypeDesc_Bound)((OOC_SymbolTable__Type)i1);
  baseType = (OOC_SymbolTable__Type)i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 79337)))), &_td_OOC_SymbolTable__PointerDesc, 79337)), 79345))+40);
  baseType = (OOC_SymbolTable__Type)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 79394))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 79394))+4);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 79399)))), OOC_SymbolTable__TypeDesc_Closure)),OOC_SymbolTable__TypeDesc_Closure)((OOC_SymbolTable__Type)i3, (OOC_SymbolTable__Type)i1);
  i2 = (OOC_INT32)d;
  i3 = (OOC_INT32)sym;
  OOC_IR__InitOperator((OOC_IR__Operator)i2, (OOC_Scanner_SymList__Symbol)i3, (OOC_SymbolTable__Type)i1);
  *(OOC_INT32*)((_check_pointer(i2, 79425))+8) = i0;
  i0 = checkPointer;
  *(OOC_UINT8*)((_check_pointer(i2, 79452))+12) = i0;
  return;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_NewDeref(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression design) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_SymbolTable__Type type;
  OOC_SymbolTable__Record _class;
  OOC_IR__Deref i;

  i0 = (OOC_INT32)design;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 79668)))), &_td_OOC_IR__SelectProcDesc);
  if (i1) goto l7;
  i1 = (OOC_INT32)sym;
  i2 = (OOC_INT32)b;
  OOC_IR__BuilderDesc_CheckFunctionOp((OOC_IR__Builder)i2, (OOC_IR__Expression)i0, (OOC_Scanner_SymList__Symbol)i1);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 80427))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 80427))+4);
  i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 80432)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i4);
  type = (OOC_SymbolTable__Type)i3;
  i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 80459)))), OOC_SymbolTable__TypeDesc_Bound)),OOC_SymbolTable__TypeDesc_Bound)((OOC_SymbolTable__Type)i3);
  i3 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 80468)))), &_td_OOC_SymbolTable__PointerDesc));
  if (i3) goto l5;
  i3 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__Deref.baseTypes[0]);
  i = (OOC_IR__Deref)i3;
  i4 = *(OOC_INT32*)((_check_pointer(i1, 80666))+16);
  i5 = (OOC_INT32)OOC_Config_StdPragmas__derefCheck;
  i2 = OOC_IR__GetPragmaValue((OOC_IR__Builder)i2, (Config_Section_Options__Option)i5, i4);
  OOC_IR__InitDeref((OOC_IR__Deref)i3, (OOC_Scanner_SymList__Symbol)i1, (OOC_IR__Expression)i0, i2);
  return (OOC_IR__Expression)i3;
  goto l19;
l5:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 80532));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 80505)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i2, 21, (OOC_Scanner_SymList__Symbol)i0);
  return (OOC_IR__Expression)i0;
  goto l19;
l7:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 79745))+12);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 79745))+12);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 79756)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i2);
  type = (OOC_SymbolTable__Type)i1;
  i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 79792)))), &_td_OOC_SymbolTable__RecordDesc, 79792);
  _class = (OOC_SymbolTable__Record)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 79891))+20);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 79830))+52);
  i2 = *(OOC_INT32*)((_check_pointer(i2, 79898))+56);
  i1 = (OOC_INT32)OOC_SymbolTable_Namespace__ExtendedDesc_GetSuperProcByIndex((OOC_SymbolTable_Namespace__Extended)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 79844)))), &_td_OOC_SymbolTable_Namespace__ExtendedDesc, 79844)), i2);
  *(OOC_INT32*)((_check_pointer(i0, 79813))+20) = i1;
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 79928))+29);
  if (i1) goto l17;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 80016))+20);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l15;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 80130))+20);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 80138))+64);
  *(OOC_INT32*)((_check_pointer(i0, 80114))+4) = i1;
  *(OOC_UINT8*)((_check_pointer(i0, 80166))+28) = 1u;
  *(OOC_UINT8*)((_check_pointer(i0, 80204))+29) = 1u;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 80244))+20);
  i1 = *(OOC_UINT8*)((_check_pointer(i1, 80251))+50);
  if (!i1) goto l14;
  i1 = (OOC_INT32)b;
  i2 = (OOC_INT32)sym;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 80279)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 58, (OOC_Scanner_SymList__Symbol)i2);
l14:
  return (OOC_IR__Expression)i0;
  goto l19;
l15:
  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)sym;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 80052)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i0, 59, (OOC_Scanner_SymList__Symbol)i1);
  return (OOC_IR__Expression)i0;
  goto l19;
l17:
  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)sym;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 79962)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i0, 60, (OOC_Scanner_SymList__Symbol)i1);
  return (OOC_IR__Expression)i0;
l19:
  _failed_function(79525); return 0;
  ;
}

void OOC_IR__VisitorDesc_VisitDeref(OOC_IR__Visitor v, OOC_IR__Deref index) {

  return;
  ;
}

void OOC_IR__DerefDesc_Accept(OOC_IR__Deref index, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)index;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 80869)))), OOC_IR__VisitorDesc_VisitDeref)),OOC_IR__VisitorDesc_VisitDeref)((OOC_IR__Visitor)i0, (OOC_IR__Deref)i1);
  return;
  ;
}

static void OOC_IR__InitEntier(OOC_IR__Entier entier, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression expr) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(6);
  i1 = (OOC_INT32)entier;
  i2 = (OOC_INT32)sym;
  OOC_IR__InitOperator((OOC_IR__Operator)i1, (OOC_Scanner_SymList__Symbol)i2, (OOC_SymbolTable__Type)i0);
  i0 = (OOC_INT32)expr;
  *(OOC_INT32*)((_check_pointer(i1, 81164))+8) = i0;
  return;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_NewEntier(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression expr) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__Entier.baseTypes[0]);
  i1 = (OOC_INT32)expr;
  i2 = (OOC_INT32)b;
  i1 = (OOC_INT32)OOC_IR__BuilderDesc_AssertReal((OOC_IR__Builder)i2, (OOC_IR__Expression)i1);
  i2 = (OOC_INT32)sym;
  OOC_IR__InitEntier((OOC_IR__Entier)i0, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i1);
  return (OOC_IR__Expression)i0;
  ;
}

void OOC_IR__VisitorDesc_VisitEntier(OOC_IR__Visitor v, OOC_IR__Entier entier) {

  return;
  ;
}

void OOC_IR__EntierDesc_Accept(OOC_IR__Entier entier, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)entier;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 81566)))), OOC_IR__VisitorDesc_VisitEntier)),OOC_IR__VisitorDesc_VisitEntier)((OOC_IR__Visitor)i0, (OOC_IR__Entier)i1);
  return;
  ;
}

static void OOC_IR__InitIndex(OOC_IR__Index i, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression array, OOC_IR__Expression index, OOC_CHAR8 checkIndex) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_SymbolTable__Type elementType;

  i0 = (OOC_INT32)array;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 81925))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 81925))+4);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 81930)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i2);
  elementType = (OOC_SymbolTable__Type)i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 81977)))), &_td_OOC_SymbolTable__ArrayDesc, 81977)), 81983))+44);
  elementType = (OOC_SymbolTable__Type)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 82033))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 82033))+4);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 82038)))), OOC_SymbolTable__TypeDesc_Closure)),OOC_SymbolTable__TypeDesc_Closure)((OOC_SymbolTable__Type)i3, (OOC_SymbolTable__Type)i1);
  i2 = (OOC_INT32)i;
  i3 = (OOC_INT32)sym;
  OOC_IR__InitOperator((OOC_IR__Operator)i2, (OOC_Scanner_SymList__Symbol)i3, (OOC_SymbolTable__Type)i1);
  *(OOC_INT32*)((_check_pointer(i2, 82067))+8) = i0;
  i0 = (OOC_INT32)index;
  *(OOC_INT32*)((_check_pointer(i2, 82089))+12) = i0;
  i0 = checkIndex;
  *(OOC_UINT8*)((_check_pointer(i2, 82111))+16) = i0;
  return;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_NewIndex(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression array, OOC_IR__Expression index) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_CHAR8 checkIndex;
  OOC_SymbolTable__Type type;
  OOC_SymbolTable__Array a;

  i0 = (OOC_INT32)sym;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 82414))+16);
  i2 = (OOC_INT32)b;
  i3 = (OOC_INT32)OOC_Config_StdPragmas__indexCheck;
  i1 = OOC_IR__GetPragmaValue((OOC_IR__Builder)i2, (Config_Section_Options__Option)i3, i1);
  checkIndex = i1;
  i3 = (OOC_INT32)array;
  OOC_IR__BuilderDesc_CheckFunctionOp((OOC_IR__Builder)i2, (OOC_IR__Expression)i3, (OOC_Scanner_SymList__Symbol)i0);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 82479))+4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 82479))+4);
  i4 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 82484)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i5);
  type = (OOC_SymbolTable__Type)i4;
  i5 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 82509)))), &_td_OOC_SymbolTable__PointerDesc);
  if (i5) goto l3;
  {register OOC_INT32 h0=i3;i3=i4;i4=h0;}
  goto l4;
l3:
  i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 82546)))), OOC_IR__BuilderDesc_NewDeref)),OOC_IR__BuilderDesc_NewDeref)((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i0, (OOC_IR__Expression)i3);
  array = (OOC_IR__Expression)i3;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 82590))+4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 82590))+4);
  i4 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 82595)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i5);
  type = (OOC_SymbolTable__Type)i4;
  {register OOC_INT32 h0=i3;i3=i4;i4=h0;}
l4:
  i5 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 82630)))), &_td_OOC_SymbolTable__ArrayDesc));
  if (i5) goto l18;
  i3 = _type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 82719)))), &_td_OOC_SymbolTable__ArrayDesc, 82719);
  a = (OOC_SymbolTable__Array)i3;
  if (i1) goto l9;
  i1=0u;
  goto l10;
l9:
  i1 = *(OOC_UINT8*)((_check_pointer(i3, 82761))+41);
  
l10:
  checkIndex = i1;
  i5 = (OOC_INT32)index;
  i5 = (OOC_INT32)OOC_IR__BuilderDesc_AssertInteger((OOC_IR__Builder)i2, (OOC_IR__Expression)i5);
  index = (OOC_IR__Expression)i5;
  i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 82831)))), &_td_OOC_IR__ConstDesc);
  if (!i6) goto l17;
  i6 = *(OOC_UINT8*)((_check_pointer(i3, 82857))+40);
  if (i6) goto l15;
  i3 = *(OOC_INT32*)((_check_pointer(i3, 83150))+52);
  i2 = OOC_IR__BuilderDesc_AssertIntConst((OOC_IR__Builder)i2, (OOC_IR__Expression)i5, 0, i3);
  goto l17;
l15:
  i2 = OOC_IR__BuilderDesc_AssertIntConst((OOC_IR__Builder)i2, (OOC_IR__Expression)i5, 0, 2147483647);
l17:
  i2 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__Index.baseTypes[0]);
  OOC_IR__InitIndex((OOC_IR__Index)i2, (OOC_Scanner_SymList__Symbol)i0, (OOC_IR__Expression)i4, (OOC_IR__Expression)i5, i1);
  return (OOC_IR__Expression)i2;
  goto l19;
l18:
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 82663)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i2, 15, (OOC_Scanner_SymList__Symbol)i0);
  return (OOC_IR__Expression)i0;
l19:
  _failed_function(82179); return 0;
  ;
}

void OOC_IR__VisitorDesc_VisitIndex(OOC_IR__Visitor v, OOC_IR__Index index) {

  return;
  ;
}

void OOC_IR__IndexDesc_Accept(OOC_IR__Index index, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)index;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 83432)))), OOC_IR__VisitorDesc_VisitIndex)),OOC_IR__VisitorDesc_VisitIndex)((OOC_IR__Visitor)i0, (OOC_IR__Index)i1);
  return;
  ;
}

static void OOC_IR__InitLen(OOC_IR__Len len, OOC_Scanner_SymList__Symbol sym, OOC_INT8 variant, OOC_IR__Expression array, OOC_IR__Expression arrayVariable, OOC_INT32 dim) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(6);
  i1 = (OOC_INT32)len;
  i2 = (OOC_INT32)sym;
  OOC_IR__InitOperator((OOC_IR__Operator)i1, (OOC_Scanner_SymList__Symbol)i2, (OOC_SymbolTable__Type)i0);
  i0 = variant;
  *(OOC_INT8*)((_check_pointer(i1, 83779))+8) = i0;
  i0 = (OOC_INT32)array;
  *(OOC_INT32*)((_check_pointer(i1, 83808))+12) = i0;
  i0 = (OOC_INT32)arrayVariable;
  *(OOC_INT32*)((_check_pointer(i1, 83833))+20) = i0;
  i0 = dim;
  *(OOC_INT32*)((_check_pointer(i1, 83874))+16) = i0;
  return;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_NewLen(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression array, OOC_INT32 dim) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_IR__Len len;
  OOC_IR__Expression arrayVariable;
  OOC_SymbolTable__Type type;
  OOC_INT8 variant;

  i0 = (OOC_INT32)array;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 84152))+4);
  i1 = OOC_SymbolTable_TypeRules__IsArray((OOC_SymbolTable__Type)i1);
  i1 = !i1;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 84184))+4);
  i1 = OOC_SymbolTable_TypeRules__IsStringConst((OOC_SymbolTable__Type)i1);
  i1 = !i1;
  
l5:
  if (!i1) goto l7;
  i1 = (OOC_INT32)b;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 84226));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 84203)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 15, (OOC_Scanner_SymList__Symbol)i2);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 84247))+20);
  return (OOC_IR__Expression)i1;
l7:
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__Len.baseTypes[0]);
  len = (OOC_IR__Len)i1;
  arrayVariable = (OOC_IR__Expression)i0;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 84342)))), &_td_OOC_IR__IndexDesc);
  if (i2) goto l10;
  i2=i0;
  goto l16;
l10:
  i2=i0;
l11_loop:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 84392)))), &_td_OOC_IR__IndexDesc, 84392)), 84398))+8);
  i3 = dim;
  arrayVariable = (OOC_IR__Expression)i2;
  dim = (i3+1);
  i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 84342)))), &_td_OOC_IR__IndexDesc);
  if (i3) goto l11_loop;
l16:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 84459))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 84459))+4);
  i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 84464)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i4);
  type = (OOC_SymbolTable__Type)i3;
  i4 = dim;
  i5 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 84489)))), &_td_OOC_SymbolTable__PredefTypeDesc);
  if (i5) goto l31;
  i5 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 84561)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (i5) goto l21;
  i5=0u;
  goto l23;
l21:
  i5 = OOC_SymbolTable__ArrayDesc_GetOpenDimensions((OOC_SymbolTable__Array)(_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 84604)))), &_td_OOC_SymbolTable__ArrayDesc, 84604)));
  i5 = i4>=i5;
  
l23:
  if (i5) goto l29;
  i5 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 84694)))), &_td_OOC_IR__VarDesc);
  if (i5) goto l27;
  variant = 19;
  i5=19;
  goto l32;
l27:
  variant = 18;
  i5=18;
  goto l32;
l29:
  variant = 17;
  i5=17;
  goto l32;
l31:
  variant = 16;
  i5=16;
l32:
  i6 = i5==19;
  if (!i6) goto l37;
  i6=1u;
l37:
  if (i6) goto l39;
  i3=0u;
  goto l41;
l39:
  i3 = *(OOC_UINT8*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 84889)))), &_td_OOC_SymbolTable__ArrayDesc, 84889)), 84895))+41);
  i3 = !i3;
  
l41:
  if (!i3) goto l43;
  i3 = (OOC_INT32)b;
  i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 84959));
  i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 84929)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i3, 54, (OOC_Scanner_SymList__Symbol)i6);
  return (OOC_IR__Expression)i3;
l43:
  i3 = (OOC_INT32)sym;
  OOC_IR__InitLen((OOC_IR__Len)i1, (OOC_Scanner_SymList__Symbol)i3, i5, (OOC_IR__Expression)i0, (OOC_IR__Expression)i2, i4);
  return (OOC_IR__Expression)i1;
  ;
}

void OOC_IR__VisitorDesc_VisitLen(OOC_IR__Visitor v, OOC_IR__Len len) {

  return;
  ;
}

void OOC_IR__LenDesc_Accept(OOC_IR__Len len, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)len;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 85200)))), OOC_IR__VisitorDesc_VisitLen)),OOC_IR__VisitorDesc_VisitLen)((OOC_IR__Visitor)i0, (OOC_IR__Len)i1);
  return;
  ;
}

static void OOC_IR__InitNegate(OOC_IR__Negate neg, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression expr) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)expr;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 85445))+4);
  i2 = (OOC_INT32)neg;
  i3 = (OOC_INT32)sym;
  OOC_IR__InitOperator((OOC_IR__Operator)i2, (OOC_Scanner_SymList__Symbol)i3, (OOC_SymbolTable__Type)i1);
  *(OOC_INT32*)((_check_pointer(i2, 85461))+8) = i0;
  return;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_NewNegate(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression expr) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__Negate.baseTypes[0]);
  i1 = (OOC_INT32)expr;
  i2 = (OOC_INT32)sym;
  OOC_IR__InitNegate((OOC_IR__Negate)i0, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i1);
  return (OOC_IR__Expression)i0;
  ;
}

void OOC_IR__VisitorDesc_VisitNegate(OOC_IR__Visitor v, OOC_IR__Negate neg) {

  return;
  ;
}

void OOC_IR__NegateDesc_Accept(OOC_IR__Negate neg, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)neg;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 85830)))), OOC_IR__VisitorDesc_VisitNegate)),OOC_IR__VisitorDesc_VisitNegate)((OOC_IR__Visitor)i0, (OOC_IR__Negate)i1);
  return;
  ;
}

static void OOC_IR__InitNewBlock(OOC_IR__NewBlock _new, OOC_Scanner_SymList__Symbol sym, OOC_SymbolTable__Type type, OOC_IR__Expression size) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)type;
  i1 = (OOC_INT32)sym;
  i2 = (OOC_INT32)_new;
  OOC_IR__InitOperator((OOC_IR__Operator)i2, (OOC_Scanner_SymList__Symbol)i1, (OOC_SymbolTable__Type)i0);
  i0 = (OOC_INT32)size;
  *(OOC_INT32*)((_check_pointer(i2, 86134))+8) = i0;
  return;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_NewNewBlock(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_SymbolTable__Type type, OOC_IR__Expression size) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__NewBlock.baseTypes[0]);
  i1 = (OOC_INT32)size;
  i2 = (OOC_INT32)type;
  i3 = (OOC_INT32)sym;
  OOC_IR__InitNewBlock((OOC_IR__NewBlock)i0, (OOC_Scanner_SymList__Symbol)i3, (OOC_SymbolTable__Type)i2, (OOC_IR__Expression)i1);
  return (OOC_IR__Expression)i0;
  ;
}

void OOC_IR__VisitorDesc_VisitNewBlock(OOC_IR__Visitor v, OOC_IR__NewBlock _new) {

  return;
  ;
}

void OOC_IR__NewBlockDesc_Accept(OOC_IR__NewBlock _new, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)_new;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 86577)))), OOC_IR__VisitorDesc_VisitNewBlock)),OOC_IR__VisitorDesc_VisitNewBlock)((OOC_IR__Visitor)i0, (OOC_IR__NewBlock)i1);
  return;
  ;
}

static void OOC_IR__InitNewObject(OOC_IR__NewObject _new, OOC_Scanner_SymList__Symbol sym, OOC_SymbolTable__Type type, OOC_IR__ExpressionList length) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)type;
  i1 = (OOC_INT32)sym;
  i2 = (OOC_INT32)_new;
  OOC_IR__InitOperator((OOC_IR__Operator)i2, (OOC_Scanner_SymList__Symbol)i1, (OOC_SymbolTable__Type)i0);
  i0 = (OOC_INT32)length;
  *(OOC_INT32*)((_check_pointer(i2, 86892))+8) = i0;
  return;
  ;
}

OOC_IR__NewObject OOC_IR__BuilderDesc_NewNewObject(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_SymbolTable__Type type, OOC_IR__ExpressionList args) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9;
  OOC_IR__ExpressionList length;
  OOC_INT32 i;

  i0 = (OOC_INT32)args;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l11;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 87232)), 0);
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__ExpressionList.baseTypes[0], (i1-1));
  length = (OOC_IR__ExpressionList)i1;
  i = 0;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i1, 87270)), 0);
  i3 = 0<i2;
  if (!i3) goto l10;
  i3 = (OOC_INT32)b;
  i4=0;
l5_loop:
  i5 = _check_pointer(i1, 87292);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i7 = _check_pointer(i0, 87319);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i9 = i4+1;
  i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i9, i8, OOC_UINT32, 87319))*4);
  i7 = (OOC_INT32)OOC_IR__BuilderDesc_AssertInteger((OOC_IR__Builder)i3, (OOC_IR__Expression)i7);
  *(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 87292))*4) = i7;
  i = i9;
  i4 = i9<i2;
  if (!i4) goto l10;
  i4=i9;
  goto l5_loop;
l10:
  i0=i1;
  goto l12;
l11:
  i0=(OOC_INT32)0;
l12:
  i1 = (OOC_INT32)sym;
  i2 = (OOC_INT32)type;
  i3 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__NewObject.baseTypes[0]);
  OOC_IR__InitNewObject((OOC_IR__NewObject)i3, (OOC_Scanner_SymList__Symbol)i1, (OOC_SymbolTable__Type)i2, (OOC_IR__ExpressionList)i0);
  return (OOC_IR__NewObject)i3;
  ;
}

void OOC_IR__VisitorDesc_VisitNewObject(OOC_IR__Visitor v, OOC_IR__NewObject _new) {

  return;
  ;
}

void OOC_IR__NewObjectDesc_Accept(OOC_IR__NewObject _new, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)_new;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 87601)))), OOC_IR__VisitorDesc_VisitNewObject)),OOC_IR__VisitorDesc_VisitNewObject)((OOC_IR__Visitor)i0, (OOC_IR__NewObject)i1);
  return;
  ;
}

static void OOC_IR__InitNot(OOC_IR__Not neg, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression expr) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)expr;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 87843))+4);
  i2 = (OOC_INT32)neg;
  i3 = (OOC_INT32)sym;
  OOC_IR__InitOperator((OOC_IR__Operator)i2, (OOC_Scanner_SymList__Symbol)i3, (OOC_SymbolTable__Type)i1);
  *(OOC_INT32*)((_check_pointer(i2, 87859))+8) = i0;
  return;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_NewNot(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression expr) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__Not.baseTypes[0]);
  i1 = (OOC_INT32)expr;
  i2 = (OOC_INT32)sym;
  OOC_IR__InitNot((OOC_IR__Not)i0, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i1);
  return (OOC_IR__Expression)i0;
  ;
}

void OOC_IR__VisitorDesc_VisitNot(OOC_IR__Visitor v, OOC_IR__Not neg) {

  return;
  ;
}

void OOC_IR__NotDesc_Accept(OOC_IR__Not neg, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)neg;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 88201)))), OOC_IR__VisitorDesc_VisitNot)),OOC_IR__VisitorDesc_VisitNot)((OOC_IR__Visitor)i0, (OOC_IR__Not)i1);
  return;
  ;
}

static void OOC_IR__InitOdd(OOC_IR__Odd odd, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression expr) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(0);
  i1 = (OOC_INT32)odd;
  i2 = (OOC_INT32)sym;
  OOC_IR__InitOperator((OOC_IR__Operator)i1, (OOC_Scanner_SymList__Symbol)i2, (OOC_SymbolTable__Type)i0);
  i0 = (OOC_INT32)expr;
  *(OOC_INT32*)((_check_pointer(i1, 88474))+8) = i0;
  return;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_NewOdd(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression expr) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__Odd.baseTypes[0]);
  i1 = (OOC_INT32)expr;
  i2 = (OOC_INT32)b;
  i1 = (OOC_INT32)OOC_IR__BuilderDesc_AssertInteger((OOC_IR__Builder)i2, (OOC_IR__Expression)i1);
  i2 = (OOC_INT32)sym;
  OOC_IR__InitOdd((OOC_IR__Odd)i0, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i1);
  return (OOC_IR__Expression)i0;
  ;
}

void OOC_IR__VisitorDesc_VisitOdd(OOC_IR__Visitor v, OOC_IR__Odd odd) {

  return;
  ;
}

void OOC_IR__OddDesc_Accept(OOC_IR__Odd odd, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)odd;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 88834)))), OOC_IR__VisitorDesc_VisitOdd)),OOC_IR__VisitorDesc_VisitOdd)((OOC_IR__Visitor)i0, (OOC_IR__Odd)i1);
  return;
  ;
}

static void OOC_IR__InitSelectField(OOC_IR__SelectField sf, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression record, OOC_SymbolTable__FieldDecl field, OOC_Scanner_SymList__Symbol fieldSym) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_SymbolTable__Type recordType;
  OOC_SymbolTable__Type ptr;

  i0 = (OOC_INT32)record;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 89248))+4);
  recordType = (OOC_SymbolTable__Type)i1;
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 89276)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i1);
  i3 = (OOC_INT32)field;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 89294))+4);
  i2 = i2!=i4;
  if (!i2) goto l9;
l4_loop:
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 89329)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i1);
  ptr = (OOC_SymbolTable__Type)i2;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 89388)))), &_td_OOC_SymbolTable__RecordDesc, 89388)), 89395))+40);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 89371)))), OOC_SymbolTable__TypeDesc_Closure)),OOC_SymbolTable__TypeDesc_Closure)((OOC_SymbolTable__Type)i1, (OOC_SymbolTable__Type)i2);
  recordType = (OOC_SymbolTable__Type)i1;
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 89276)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i1);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 89294))+4);
  i2 = i2!=i4;
  if (i2) goto l4_loop;
l9:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 89472))+48);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 89458)))), OOC_SymbolTable__TypeDesc_Closure)),OOC_SymbolTable__TypeDesc_Closure)((OOC_SymbolTable__Type)i1, (OOC_SymbolTable__Type)i2);
  i2 = (OOC_INT32)sf;
  i4 = (OOC_INT32)sym;
  OOC_IR__InitOperator((OOC_IR__Operator)i2, (OOC_Scanner_SymList__Symbol)i4, (OOC_SymbolTable__Type)i1);
  *(OOC_INT32*)((_check_pointer(i2, 89487))+8) = i0;
  *(OOC_INT32*)((_check_pointer(i2, 89512))+12) = i3;
  i0 = (OOC_INT32)fieldSym;
  *(OOC_INT32*)((_check_pointer(i2, 89535))+16) = i0;
  return;
  ;
}

OOC_IR__SelectField OOC_IR__BuilderDesc_NewSelectField(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression record, OOC_SymbolTable__FieldDecl field, OOC_Scanner_SymList__Symbol fieldSym) {
  register OOC_INT32 i0,i1,i2,i3,i4;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__SelectField.baseTypes[0]);
  i1 = (OOC_INT32)fieldSym;
  i2 = (OOC_INT32)field;
  i3 = (OOC_INT32)record;
  i4 = (OOC_INT32)sym;
  OOC_IR__InitSelectField((OOC_IR__SelectField)i0, (OOC_Scanner_SymList__Symbol)i4, (OOC_IR__Expression)i3, (OOC_SymbolTable__FieldDecl)i2, (OOC_Scanner_SymList__Symbol)i1);
  return (OOC_IR__SelectField)i0;
  ;
}

void OOC_IR__VisitorDesc_VisitSelectField(OOC_IR__Visitor v, OOC_IR__SelectField sf) {

  return;
  ;
}

void OOC_IR__SelectFieldDesc_Accept(OOC_IR__SelectField sf, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)sf;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 90044)))), OOC_IR__VisitorDesc_VisitSelectField)),OOC_IR__VisitorDesc_VisitSelectField)((OOC_IR__Visitor)i0, (OOC_IR__SelectField)i1);
  return;
  ;
}

static void OOC_IR__InitSelectProc(OOC_IR__SelectProc sp, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression receiver, OOC_CHAR8 checkPointer, OOC_SymbolTable__Type recordType, OOC_SymbolTable__ProcDecl tbProc, OOC_Scanner_SymList__Symbol tbProcSym, OOC_CHAR8 isStaticCall) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_SymbolTable__Type _class;
  OOC_SymbolTable__Type baseRecord;
  OOC_SymbolTable__Type ptr;

  i0 = (OOC_INT32)sp;
  i1 = (OOC_INT32)recordType;
  *(OOC_INT32*)((_check_pointer(i0, 90516))+12) = i1;
  i2 = (OOC_INT32)tbProc;
  i3 = (OOC_INT32)OOC_SymbolTable__ProcDeclDesc_Class((OOC_SymbolTable__ProcDecl)i2);
  _class = (OOC_SymbolTable__Type)i3;
  baseRecord = (OOC_SymbolTable__Type)i1;
  i4 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 90686)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i1);
  i4 = i4!=i3;
  if (!i4) goto l9;
l4_loop:
  i4 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 90732)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i1);
  ptr = (OOC_SymbolTable__Type)i4;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 90791)))), &_td_OOC_SymbolTable__RecordDesc, 90791)), 90798))+40);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 90774)))), OOC_SymbolTable__TypeDesc_Closure)),OOC_SymbolTable__TypeDesc_Closure)((OOC_SymbolTable__Type)i1, (OOC_SymbolTable__Type)i4);
  baseRecord = (OOC_SymbolTable__Type)i1;
  i4 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 90686)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i1);
  i4 = i4!=i3;
  if (i4) goto l4_loop;
l9:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 90872))+64);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 90857)))), OOC_SymbolTable__TypeDesc_Closure)),OOC_SymbolTable__TypeDesc_Closure)((OOC_SymbolTable__Type)i1, (OOC_SymbolTable__Type)i3);
  i3 = (OOC_INT32)sym;
  OOC_IR__InitOperator((OOC_IR__Operator)i0, (OOC_Scanner_SymList__Symbol)i3, (OOC_SymbolTable__Type)i1);
  i1 = (OOC_INT32)receiver;
  *(OOC_INT32*)((_check_pointer(i0, 90893))+8) = i1;
  i1 = checkPointer;
  *(OOC_UINT8*)((_check_pointer(i0, 90923))+16) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 90961))+20) = i2;
  i1 = (OOC_INT32)tbProcSym;
  *(OOC_INT32*)((_check_pointer(i0, 90987))+24) = i1;
  i1 = isStaticCall;
  *(OOC_UINT8*)((_check_pointer(i0, 91019))+28) = i1;
  *(OOC_UINT8*)((_check_pointer(i0, 91057))+29) = 0u;
  return;
  ;
}

OOC_IR__SelectProc OOC_IR__BuilderDesc_NewSelectProc(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression receiver, OOC_SymbolTable__Type recordType, OOC_SymbolTable__ProcDecl tbProc, OOC_Scanner_SymList__Symbol tbProcSym, OOC_CHAR8 isStaticCall) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;

  i0 = (OOC_INT32)sym;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 91553))+16);
  i2 = (OOC_INT32)b;
  i3 = (OOC_INT32)OOC_Config_StdPragmas__derefCheck;
  i1 = OOC_IR__GetPragmaValue((OOC_IR__Builder)i2, (Config_Section_Options__Option)i3, i1);
  i2 = (OOC_INT32)receiver;
  i3 = (OOC_INT32)recordType;
  i4 = (OOC_INT32)tbProc;
  i5 = (OOC_INT32)tbProcSym;
  i6 = isStaticCall;
  i7 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__SelectProc.baseTypes[0]);
  OOC_IR__InitSelectProc((OOC_IR__SelectProc)i7, (OOC_Scanner_SymList__Symbol)i0, (OOC_IR__Expression)i2, i1, (OOC_SymbolTable__Type)i3, (OOC_SymbolTable__ProcDecl)i4, (OOC_Scanner_SymList__Symbol)i5, i6);
  return (OOC_IR__SelectProc)i7;
  ;
}

void OOC_IR__VisitorDesc_VisitSelectProc(OOC_IR__Visitor v, OOC_IR__SelectProc sp) {

  return;
  ;
}

void OOC_IR__SelectProcDesc_Accept(OOC_IR__SelectProc sp, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)sp;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 91887)))), OOC_IR__VisitorDesc_VisitSelectProc)),OOC_IR__VisitorDesc_VisitSelectProc)((OOC_IR__Visitor)i0, (OOC_IR__SelectProc)i1);
  return;
  ;
}

static void OOC_IR__InitSetMember(OOC_IR__SetMember op, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression element, OOC_IR__Expression set) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(0);
  i1 = (OOC_INT32)op;
  i2 = (OOC_INT32)sym;
  OOC_IR__InitOperator((OOC_IR__Operator)i1, (OOC_Scanner_SymList__Symbol)i2, (OOC_SymbolTable__Type)i0);
  i0 = (OOC_INT32)element;
  *(OOC_INT32*)((_check_pointer(i1, 92189))+8) = i0;
  i0 = (OOC_INT32)set;
  *(OOC_INT32*)((_check_pointer(i1, 92216))+12) = i0;
  return;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_NewSetMember(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression element, OOC_IR__Expression set) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_IR__SetMember op;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__SetMember.baseTypes[0]);
  op = (OOC_IR__SetMember)i0;
  i1 = (OOC_INT32)set;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 92448))+4);
  i3 = (OOC_INT32)b;
  i4 = (OOC_INT32)element;
  i2 = (OOC_INT32)OOC_IR__BuilderDesc_ValidSetElement((OOC_IR__Builder)i3, (OOC_IR__Expression)i4, (OOC_SymbolTable__Type)i2);
  i3 = (OOC_INT32)sym;
  OOC_IR__InitSetMember((OOC_IR__SetMember)i0, (OOC_Scanner_SymList__Symbol)i3, (OOC_IR__Expression)i2, (OOC_IR__Expression)i1);
  return (OOC_IR__Expression)i0;
  ;
}

void OOC_IR__VisitorDesc_VisitSetMember(OOC_IR__Visitor v, OOC_IR__SetMember op) {

  return;
  ;
}

void OOC_IR__SetMemberDesc_Accept(OOC_IR__SetMember op, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)op;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 92648)))), OOC_IR__VisitorDesc_VisitSetMember)),OOC_IR__VisitorDesc_VisitSetMember)((OOC_IR__Visitor)i0, (OOC_IR__SetMember)i1);
  return;
  ;
}

static void OOC_IR__InitSetOp(OOC_IR__SetOp op, OOC_Scanner_SymList__Symbol sym, OOC_INT8 variant, OOC_IR__Expression left, OOC_IR__Expression right, OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)type;
  i1 = (OOC_INT32)sym;
  i2 = (OOC_INT32)op;
  OOC_IR__InitOperator((OOC_IR__Operator)i2, (OOC_Scanner_SymList__Symbol)i1, (OOC_SymbolTable__Type)i0);
  i0 = variant;
  *(OOC_INT8*)((_check_pointer(i2, 92945))+8) = i0;
  i0 = (OOC_INT32)left;
  *(OOC_INT32*)((_check_pointer(i2, 92972))+12) = i0;
  i0 = (OOC_INT32)right;
  *(OOC_INT32*)((_check_pointer(i2, 92993))+16) = i0;
  return;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_NewSetOp(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_INT8 variant, OOC_IR__Expression left, OOC_IR__Expression right) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_IR__SetOp op;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__SetOp.baseTypes[0]);
  op = (OOC_IR__SetOp)i0;
  i1 = (OOC_INT32)right;
  i2 = (OOC_INT32)left;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 93214))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 93202))+4);
  i3 = OOC_SymbolTable_TypeRules__SameType((OOC_SymbolTable__Type)i4, (OOC_SymbolTable__Type)i3);
  _assert(i3, 127, 93179);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 93273))+4);
  i4 = (OOC_INT32)sym;
  i5 = variant;
  OOC_IR__InitSetOp((OOC_IR__SetOp)i0, (OOC_Scanner_SymList__Symbol)i4, i5, (OOC_IR__Expression)i2, (OOC_IR__Expression)i1, (OOC_SymbolTable__Type)i3);
  return (OOC_IR__Expression)i0;
  ;
}

void OOC_IR__VisitorDesc_VisitSetOp(OOC_IR__Visitor v, OOC_IR__SetOp op) {

  return;
  ;
}

void OOC_IR__SetOpDesc_Accept(OOC_IR__SetOp op, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)op;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 93448)))), OOC_IR__VisitorDesc_VisitSetOp)),OOC_IR__VisitorDesc_VisitSetOp)((OOC_IR__Visitor)i0, (OOC_IR__SetOp)i1);
  return;
  ;
}

static void OOC_IR__InitSetRange(OOC_IR__SetRange range, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression from, OOC_IR__Expression to) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(10);
  i1 = (OOC_INT32)range;
  i2 = (OOC_INT32)sym;
  OOC_IR__InitOperator((OOC_IR__Operator)i1, (OOC_Scanner_SymList__Symbol)i2, (OOC_SymbolTable__Type)i0);
  i0 = (OOC_INT32)from;
  *(OOC_INT32*)((_check_pointer(i1, 93768))+8) = i0;
  i0 = (OOC_INT32)to;
  *(OOC_INT32*)((_check_pointer(i1, 93792))+12) = i0;
  return;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_NewSetRange(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression type, OOC_IR__Expression from, OOC_IR__Expression to, OOC_CHAR8 isSet) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_SymbolTable__Type set;
  OOC_SymbolTable__Type t;

  i0 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(10);
  set = (OOC_SymbolTable__Type)i0;
  i1 = (OOC_INT32)type;
  i2 = i1!=(OOC_INT32)0;
  if (!i2) goto l8;
  i2 = (OOC_INT32)b;
  i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 94102)))), OOC_IR__BuilderDesc_AssertType)),OOC_IR__BuilderDesc_AssertType)((OOC_IR__Builder)i2, (OOC_IR__Expression)i1);
  t = (OOC_SymbolTable__Type)i3;
  i4 = OOC_SymbolTable_TypeRules__IsSetType((OOC_SymbolTable__Type)i3);
  if (i4) goto l6;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 94221));
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 94196)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i2, 79, (OOC_Scanner_SymList__Symbol)i1);
  return (OOC_IR__Expression)i1;
  
  goto l8;
l6:
  set = (OOC_SymbolTable__Type)i3;
  i0=i3;
l8:
  i1 = (OOC_INT32)from;
  i2 = i1==(OOC_INT32)0;
  if (i2) goto l11;
  i2=0u;
  goto l13;
l11:
  i2 = (OOC_INT32)to;
  i2 = i2==(OOC_INT32)0;
  
l13:
  if (i2) goto l18;
  i2 = isSet;
  if (!i2) goto l17;
  i2 = (OOC_INT32)b;
  i1 = (OOC_INT32)OOC_IR__BuilderDesc_ValidSetElement((OOC_IR__Builder)i2, (OOC_IR__Expression)i1, (OOC_SymbolTable__Type)i0);
  from = (OOC_IR__Expression)i1;
  i1 = (OOC_INT32)to;
  i0 = (OOC_INT32)OOC_IR__BuilderDesc_ValidSetElement((OOC_IR__Builder)i2, (OOC_IR__Expression)i1, (OOC_SymbolTable__Type)i0);
  to = (OOC_IR__Expression)i0;
l17:
  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__SetRange.baseTypes[0]);
  i1 = (OOC_INT32)to;
  i2 = (OOC_INT32)from;
  i3 = (OOC_INT32)sym;
  OOC_IR__InitSetRange((OOC_IR__SetRange)i0, (OOC_Scanner_SymList__Symbol)i3, (OOC_IR__Expression)i2, (OOC_IR__Expression)i1);
  return (OOC_IR__Expression)i0;
  goto l19;
l18:
  i1 = (OOC_INT32)RT0__NewObject(_td_Object_Boxed__Set.baseTypes[0]);
  Object_Boxed__SetDesc_INIT((Object_Boxed__Set)i1, 0u);
  i2 = (OOC_INT32)b;
  i3 = (OOC_INT32)sym;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 94317)))), OOC_IR__BuilderDesc_NewConst)),OOC_IR__BuilderDesc_NewConst)((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i3, (OOC_SymbolTable__Type)i0, (Object_Boxed__Object)i1);
  return (OOC_IR__Expression)i0;
l19:
  _failed_function(93847); return 0;
  ;
}

void OOC_IR__VisitorDesc_VisitSetRange(OOC_IR__Visitor v, OOC_IR__SetRange range) {

  return;
  ;
}

void OOC_IR__SetRangeDesc_Accept(OOC_IR__SetRange range, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)range;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 94814)))), OOC_IR__VisitorDesc_VisitSetRange)),OOC_IR__VisitorDesc_VisitSetRange)((OOC_IR__Visitor)i0, (OOC_IR__SetRange)i1);
  return;
  ;
}

OOC_CHAR8 OOC_IR__SetRangeDesc_IsEmpty(OOC_IR__SetRange range) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)range;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 95006))+12);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 94974))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 94974))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 94981)))), &_td_OOC_IR__ConstDesc, 94981)), 94987))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 95011)))), &_td_OOC_IR__ConstDesc, 95011)), 95017))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 94981)))), &_td_OOC_IR__ConstDesc, 94981)), 94987))+8);
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 94994)))), Object_Boxed__ObjectDesc_Cmp)),Object_Boxed__ObjectDesc_Cmp)((Object_Boxed__Object)i2, (Object__Object)i1);
  return (i0>0);
  ;
}

OOC_CHAR8 OOC_IR__SetRangeDesc_IntersectsWith(OOC_IR__SetRange range, OOC_IR__SetRange range2) {
  register OOC_INT32 i0,i1,i2,i3,i4;

  i0 = (OOC_INT32)range2;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 95273))+8);
  i2 = (OOC_INT32)range;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 95244))+12);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 95244))+12);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 95248)))), &_td_OOC_IR__ConstDesc, 95248)), 95254))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 95279)))), &_td_OOC_IR__ConstDesc, 95279)), 95285))+8);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 95248)))), &_td_OOC_IR__ConstDesc, 95248)), 95254))+8);
  i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 95260)))), Object_Boxed__ObjectDesc_Cmp)),Object_Boxed__ObjectDesc_Cmp)((Object_Boxed__Object)i3, (Object__Object)i1);
  i1 = i1<0;
  if (i1) goto l3;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 95348))+12);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 95317))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 95317))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 95323)))), &_td_OOC_IR__ConstDesc, 95323)), 95329))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 95352)))), &_td_OOC_IR__ConstDesc, 95352)), 95358))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 95323)))), &_td_OOC_IR__ConstDesc, 95323)), 95329))+8);
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 95335)))), Object_Boxed__ObjectDesc_Cmp)),Object_Boxed__ObjectDesc_Cmp)((Object_Boxed__Object)i1, (Object__Object)i0);
  i0 = i0>0;
  
  goto l4;
l3:
  i0=1u;
l4:
  return (!i0);
  ;
}

static void OOC_IR__InitShift(OOC_IR__Shift shift, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression value, OOC_IR__Expression by, OOC_CHAR8 rotate) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)value;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 95653))+4);
  i2 = (OOC_INT32)shift;
  i3 = (OOC_INT32)sym;
  OOC_IR__InitOperator((OOC_IR__Operator)i2, (OOC_Scanner_SymList__Symbol)i3, (OOC_SymbolTable__Type)i1);
  *(OOC_INT32*)((_check_pointer(i2, 95671))+8) = i0;
  i0 = (OOC_INT32)by;
  *(OOC_INT32*)((_check_pointer(i2, 95698))+12) = i0;
  i0 = rotate;
  *(OOC_UINT8*)((_check_pointer(i2, 95719))+16) = i0;
  return;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_NewShift(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression value, OOC_IR__Expression by, OOC_CHAR8 rotate) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_IR__Shift shift;
  auto OOC_IR__Expression OOC_IR__BuilderDesc_NewShift_AssertShiftable(OOC_IR__Expression expr);
    
    OOC_IR__Expression OOC_IR__BuilderDesc_NewShift_AssertShiftable(OOC_IR__Expression expr) {
      register OOC_INT32 i0,i1,i2,i3;
      Object_BigInt__BigInt v;

      i0 = (OOC_INT32)b;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 96038))+20);
      i2 = (OOC_INT32)expr;
      i1 = i2!=i1;
      if (!i1) goto l18;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 96089))+4);
      i1 = OOC_SymbolTable_TypeRules__IsIntegerType((OOC_SymbolTable__Type)i1);
      if (i1) goto l5;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 96130))+4);
      i1 = OOC_SymbolTable_TypeRules__IsCharType((OOC_SymbolTable__Type)i1);
      
      goto l7;
l5:
      i1=1u;
l7:
      if (i1) goto l9;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 96173))+4);
      i1 = OOC_SymbolTable_TypeRules__IsPredefType((OOC_SymbolTable__Type)i1, 11);
      
      goto l11;
l9:
      i1=1u;
l11:
      if (i1) goto l13;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 96226))+4);
      i1 = OOC_SymbolTable_TypeRules__IsSetType((OOC_SymbolTable__Type)i1);
      
      goto l14;
l13:
      i1=1u;
l14:
      i1 = !i1;
      if (!i1) goto l18;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 96277));
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 96250)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 5, (OOC_Scanner_SymList__Symbol)i1);
      i0 = (OOC_INT32)Object_BigInt__NewInt(1);
      v = (Object_BigInt__BigInt)i0;
      i1 = (OOC_INT32)OOC_SymbolTable_Predef__SmallestIntType((Object_BigInt__BigInt)i0);
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 96347));
      i0 = (OOC_INT32)OOC_IR__NewConst((OOC_Scanner_SymList__Symbol)i3, (OOC_SymbolTable__Type)i1, (Object_Boxed__Object)i0);
      return (OOC_IR__Expression)i0;
l18:
      return (OOC_IR__Expression)i2;
      ;
    }


  shift = (OOC_IR__Shift)((OOC_INT32)RT0__NewObject(_td_OOC_IR__Shift.baseTypes[0]));
  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)by;
  i0 = (OOC_INT32)OOC_IR__BuilderDesc_AssertInteger((OOC_IR__Builder)i0, (OOC_IR__Expression)i1);
  i1 = (OOC_INT32)value;
  i1 = (OOC_INT32)OOC_IR__BuilderDesc_NewShift_AssertShiftable((OOC_IR__Expression)i1);
  i2 = (OOC_INT32)sym;
  i3 = rotate;
  i4 = (OOC_INT32)shift;
  OOC_IR__InitShift((OOC_IR__Shift)i4, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i1, (OOC_IR__Expression)i0, i3);
  return (OOC_IR__Expression)i4;
  ;
}

void OOC_IR__VisitorDesc_VisitShift(OOC_IR__Visitor v, OOC_IR__Shift shift) {

  return;
  ;
}

void OOC_IR__ShiftDesc_Accept(OOC_IR__Shift shift, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)shift;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 96752)))), OOC_IR__VisitorDesc_VisitShift)),OOC_IR__VisitorDesc_VisitShift)((OOC_IR__Visitor)i0, (OOC_IR__Shift)i1);
  return;
  ;
}

static void OOC_IR__InitTypeCast(OOC_IR__TypeCast cast, OOC_Scanner_SymList__Symbol sym, OOC_SymbolTable__Type type, OOC_IR__Expression expr) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)type;
  i1 = (OOC_INT32)sym;
  i2 = (OOC_INT32)cast;
  OOC_IR__InitOperator((OOC_IR__Operator)i2, (OOC_Scanner_SymList__Symbol)i1, (OOC_SymbolTable__Type)i0);
  i0 = (OOC_INT32)expr;
  *(OOC_INT32*)((_check_pointer(i2, 97060))+8) = i0;
  return;
  ;
}

OOC_IR__TypeCast OOC_IR__BuilderDesc_NewTypeCast(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression typeExpr, OOC_IR__Expression expr) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_SymbolTable__Type type;

  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)typeExpr;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 97299)))), OOC_IR__BuilderDesc_AssertType)),OOC_IR__BuilderDesc_AssertType)((OOC_IR__Builder)i0, (OOC_IR__Expression)i1);
  i1 = (OOC_INT32)OOC_SymbolTable__Expand((OOC_SymbolTable__Type)i1);
  type = (OOC_SymbolTable__Type)i1;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 97335))+32);
  i2 = i2<0;
  if (i2) goto l3;
  i2 = (OOC_INT32)expr;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 97354))+4);
  i2 = *(OOC_INT32*)((_check_pointer(i2, 97359))+32);
  i2 = i2<0;
  
  goto l4;
l3:
  i2=1u;
l4:
  i3 = (OOC_INT32)expr;
  if (i2) goto l7;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 97397))+4);
  i4 = *(OOC_INT32*)((_check_pointer(i1, 97385))+32);
  i2 = *(OOC_INT32*)((_check_pointer(i2, 97402))+32);
  i2 = i4!=i2;
  
  goto l9;
l7:
  i2=1u;
l9:
  if (!i2) goto l11;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 97453));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 97421)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 52, (OOC_Scanner_SymList__Symbol)i2);
l11:
  i0 = (OOC_INT32)sym;
  i2 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__TypeCast.baseTypes[0]);
  OOC_IR__InitTypeCast((OOC_IR__TypeCast)i2, (OOC_Scanner_SymList__Symbol)i0, (OOC_SymbolTable__Type)i1, (OOC_IR__Expression)i3);
  return (OOC_IR__TypeCast)i2;
  ;
}

void OOC_IR__VisitorDesc_VisitTypeCast(OOC_IR__Visitor v, OOC_IR__TypeCast cast) {

  return;
  ;
}

void OOC_IR__TypeCastDesc_Accept(OOC_IR__TypeCast cast, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)cast;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 97714)))), OOC_IR__VisitorDesc_VisitTypeCast)),OOC_IR__VisitorDesc_VisitTypeCast)((OOC_IR__Visitor)i0, (OOC_IR__TypeCast)i1);
  return;
  ;
}

static void OOC_IR__InitTypeConv(OOC_IR__TypeConv conv, OOC_Scanner_SymList__Symbol sym, OOC_SymbolTable__Type type, OOC_IR__Expression expr) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)type;
  i1 = (OOC_INT32)sym;
  i2 = (OOC_INT32)conv;
  OOC_IR__InitOperator((OOC_IR__Operator)i2, (OOC_Scanner_SymList__Symbol)i1, (OOC_SymbolTable__Type)i0);
  i0 = (OOC_INT32)expr;
  *(OOC_INT32*)((_check_pointer(i2, 98021))+8) = i0;
  return;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_NewTypeConv(OOC_IR__Builder b, OOC_SymbolTable__Type type, OOC_IR__Expression expr) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_IR__TypeConv conv;

  i0 = (OOC_INT32)expr;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 98188))+4);
  i2 = (OOC_INT32)type;
  i1 = i1==i2;
  if (i1) goto l11;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 98303)))), &_td_OOC_IR__TypeConvDesc);
  if (i1) goto l5;
  i1=0u;
  goto l7;
l5:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 98344))+4);
  i1 = OOC_SymbolTable_TypeRules__IncludesType((OOC_SymbolTable__Type)i2, (OOC_SymbolTable__Type)i1);
  
l7:
  if (!i1) goto l10;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 98411)))), &_td_OOC_IR__TypeConvDesc, 98411)), 98420))+8);
  expr = (OOC_IR__Expression)i0;
  
l10:
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__TypeConv.baseTypes[0]);
  conv = (OOC_IR__TypeConv)i1;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 98486));
  OOC_IR__InitTypeConv((OOC_IR__TypeConv)i1, (OOC_Scanner_SymList__Symbol)i3, (OOC_SymbolTable__Type)i2, (OOC_IR__Expression)i0);
  return (OOC_IR__Expression)i1;
  goto l12;
l11:
  return (OOC_IR__Expression)i0;
l12:
  _failed_function(98082); return 0;
  ;
}

void OOC_IR__VisitorDesc_VisitTypeConv(OOC_IR__Visitor v, OOC_IR__TypeConv conv) {

  return;
  ;
}

void OOC_IR__TypeConvDesc_Accept(OOC_IR__TypeConv conv, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)conv;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 98703)))), OOC_IR__VisitorDesc_VisitTypeConv)),OOC_IR__VisitorDesc_VisitTypeConv)((OOC_IR__Visitor)i0, (OOC_IR__TypeConv)i1);
  return;
  ;
}

OOC_CHAR8 OOC_IR__BuilderDesc_Widen(OOC_IR__Builder b, OOC_IR__Expression *expr, OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)type;
  _assert((i0!=(OOC_INT32)0), 127, 100175);
  i1 = (OOC_INT32)*expr;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 100209))+4);
  i2 = i2==(OOC_INT32)0;
  if (i2) goto l107;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 100413))+4);
  i1 = OOC_SymbolTable_TypeRules__SameType((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
  if (i1) goto l105;
  i1 = (OOC_INT32)*expr;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 100532))+4);
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 100539)))), &_td_OOC_SymbolTable__FormalParsDesc);
  if (i2) goto l99;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 100869))+4);
  i1 = OOC_SymbolTable_TypeRules__IncludesType((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
  if (i1) goto l97;
  i1 = (OOC_INT32)*expr;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 101118))+4);
  i1 = OOC_SymbolTable_TypeRules__IsExtensionOf((OOC_SymbolTable__Type)i1, (OOC_SymbolTable__Type)i0);
  if (i1) goto l95;
  i1 = (OOC_INT32)*expr;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 101280))+4);
  i1 = OOC_IR__IsPredefType((OOC_SymbolTable__Type)i1, 16);
  if (i1) goto l13;
  i1=0u;
  goto l15;
l13:
  i1 = OOC_SymbolTable_TypeRules__IsNilCompatible((OOC_SymbolTable__Type)i0);
  
l15:
  if (i1) goto l93;
  i1 = OOC_SymbolTable_TypeRules__IsPredefType((OOC_SymbolTable__Type)i0, 12);
  if (i1) goto l19;
  i1=0u;
  goto l21;
l19:
  i1 = (OOC_INT32)*expr;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 101510))+4);
  i1 = OOC_SymbolTable_TypeRules__IsPtrCompatible((OOC_SymbolTable__Type)i1);
  
l21:
  if (i1) goto l91;
  i1 = (OOC_INT32)*expr;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 101611)))), &_td_OOC_IR__ConstDesc);
  if (i2) goto l25;
  i2=0u;
  goto l27;
l25:
  i2 = OOC_SymbolTable_TypeRules__IsStringConst((OOC_SymbolTable__Type)i0);
  
l27:
  if (i2) goto l29;
  i1=0u;
  goto l31;
l29:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 101691))+4);
  i1 = (OOC_INT32)OOC_SymbolTable_TypeRules__BaseCharType((OOC_SymbolTable__Type)i1);
  i1 = i1!=(OOC_INT32)0;
  
l31:
  if (i1) goto l33;
  i1=0u;
  goto l35;
l33:
  i1 = (OOC_INT32)*expr;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 101806))+4);
  i1 = (OOC_INT32)OOC_SymbolTable_TypeRules__BaseCharType((OOC_SymbolTable__Type)i1);
  i2 = (OOC_INT32)OOC_SymbolTable_TypeRules__BaseCharType((OOC_SymbolTable__Type)i0);
  i1 = OOC_SymbolTable_TypeRules__IncludesType((OOC_SymbolTable__Type)i2, (OOC_SymbolTable__Type)i1);
  
l35:
  if (i1) goto l89;
  i1 = (OOC_INT32)*expr;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 101972)))), &_td_OOC_IR__ConstDesc);
  if (i2) goto l39;
  i1=0u;
  goto l41;
l39:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 102016))+4);
  i1 = (OOC_INT32)OOC_SymbolTable_TypeRules__BaseCharType((OOC_SymbolTable__Type)i1);
  i1 = i1!=(OOC_INT32)0;
  
l41:
  if (i1) goto l43;
  i1=0u;
  goto l45;
l43:
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 102049)))), &_td_OOC_SymbolTable__ArrayDesc);
  
l45:
  if (i1) goto l47;
  i1=0u;
  goto l49;
l47:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 102099)))), &_td_OOC_SymbolTable__ArrayDesc, 102099)), 102105))+44);
  i1 = OOC_SymbolTable_TypeRules__IsCharType((OOC_SymbolTable__Type)i1);
  
l49:
  if (i1) goto l87;
  i1 = (OOC_INT32)*expr;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 102278)))), &_td_OOC_IR__ConstDesc);
  if (i2) goto l53;
  i2=0u;
  goto l59;
l53:
  i2 = OOC_SymbolTable_TypeRules__IsSTRING((OOC_SymbolTable__Type)i0);
  if (i2) goto l56;
  i2 = OOC_SymbolTable_TypeRules__IsObjectType((OOC_SymbolTable__Type)i0);
  
  goto l59;
l56:
  i2=1u;
l59:
  if (i2) goto l61;
  i1=0u;
  goto l63;
l61:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 102378))+4);
  i1 = (OOC_INT32)OOC_SymbolTable_TypeRules__BaseCharType((OOC_SymbolTable__Type)i1);
  i1 = i1!=(OOC_INT32)0;
  
l63:
  if (i1) goto l85;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 102688)))), &_td_OOC_SymbolTable__PointerDesc);
  if (i1) goto l67;
  i1=0u;
  goto l69;
l67:
  i1 = (OOC_INT32)OOC_SymbolTable_TypeRules__PointerBaseType((OOC_SymbolTable__Type)i0);
  i1 = OOC_SymbolTable_TypeRules__IsArrayOfChar((OOC_SymbolTable__Type)i1, 0u);
  
l69:
  if (i1) goto l71;
  i1=0u;
  goto l73;
l71:
  i1 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 102787)))), &_td_OOC_SymbolTable__PointerDesc, 102787)), 102795))+48);
  
l73:
  if (i1) goto l75;
  i0=0u;
  goto l81;
l75:
  i1 = (OOC_INT32)OOC_SymbolTable_TypeRules__PointerBaseType((OOC_SymbolTable__Type)i0);
  i2 = (OOC_INT32)b;
  i1 = OOC_IR__BuilderDesc_Widen((OOC_IR__Builder)i2, (void*)(OOC_INT32)expr, (OOC_SymbolTable__Type)i1);
  if (i1) goto l78;
  i0 = (OOC_INT32)OOC_SymbolTable_TypeRules__PointerBaseType((OOC_SymbolTable__Type)i0);
  i1 = (OOC_INT32)*expr;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 102907))+4);
  i0 = OOC_SymbolTable_TypeRules__IsArrayCompatible((OOC_SymbolTable__Type)i1, (OOC_SymbolTable__Type)i0);
  
  goto l81;
l78:
  i0=1u;
l81:
  if (i0) goto l83;
  return 0u;
  goto l108;
l83:
  i0 = (OOC_INT32)*expr;
  i1 = (OOC_INT32)b;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 103165));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 103152)))), OOC_IR__BuilderDesc_NewAdr)),OOC_IR__BuilderDesc_NewAdr)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i0);
  *expr = (OOC_IR__Expression)i0;
  return 1u;
  goto l108;
l85:
  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 102630))+32);
  i2 = (OOC_INT32)*expr;
  i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewTypeConv((OOC_IR__Builder)i0, (OOC_SymbolTable__Type)i1, (OOC_IR__Expression)i2);
  *expr = (OOC_IR__Expression)i0;
  return 1u;
  goto l108;
l87:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 102238)))), &_td_OOC_SymbolTable__ArrayDesc, 102238)), 102244))+44);
  i0 = (OOC_INT32)OOC_SymbolTable_TypeRules__MatchingStringConst((OOC_SymbolTable__Type)i0);
  i1 = (OOC_INT32)b;
  i0 = OOC_IR__BuilderDesc_Widen((OOC_IR__Builder)i1, (void*)(OOC_INT32)expr, (OOC_SymbolTable__Type)i0);
  return i0;
  goto l108;
l89:
  i1 = (OOC_INT32)*expr;
  i2 = (OOC_INT32)b;
  i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewTypeConv((OOC_IR__Builder)i2, (OOC_SymbolTable__Type)i0, (OOC_IR__Expression)i1);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 101898)))), OOC_IR__BuilderDesc_Fold)),OOC_IR__BuilderDesc_Fold)((OOC_IR__Builder)i2, (OOC_IR__Expression)i0);
  *expr = (OOC_IR__Expression)i0;
  return 1u;
  goto l108;
l91:
  return 1u;
  goto l108;
l93:
  return 1u;
  goto l108;
l95:
  return 1u;
  goto l108;
l97:
  i1 = (OOC_INT32)*expr;
  i2 = (OOC_INT32)b;
  i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewTypeConv((OOC_IR__Builder)i2, (OOC_SymbolTable__Type)i0, (OOC_IR__Expression)i1);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 101023)))), OOC_IR__BuilderDesc_Fold)),OOC_IR__BuilderDesc_Fold)((OOC_IR__Builder)i2, (OOC_IR__Expression)i0);
  *expr = (OOC_IR__Expression)i0;
  return 1u;
  goto l108;
l99:
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 100688)))), &_td_OOC_SymbolTable__FormalParsDesc);
  if (i2) goto l102;
  i0=0u;
  goto l103;
l102:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 100800))+4);
  i0 = OOC_SymbolTable_TypeRules__FormalParamsMatch((OOC_SymbolTable__Type)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 100750)))), &_td_OOC_SymbolTable__FormalParsDesc, 100750)), (OOC_SymbolTable__FormalPars)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 100811)))), &_td_OOC_SymbolTable__FormalParsDesc, 100811)), 0u);
  
l103:
  return i0;
  goto l108;
l105:
  return 1u;
  goto l108;
l107:
  return 0u;
l108:
  _failed_function(98764); return 0;
  ;
}

OOC_CHAR8 OOC_IR__BuilderDesc_WidenForAssign(OOC_IR__Builder b, OOC_IR__Expression *expr, OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1,i2;
  OOC_IR__Expression oldExpr;
  auto OOC_CHAR8 OOC_IR__BuilderDesc_WidenForAssign_LengthOk(void);
    
    OOC_CHAR8 OOC_IR__BuilderDesc_WidenForAssign_LengthOk(void) {
      register OOC_INT32 i0,i1,i2;

      i0 = (OOC_INT32)*expr;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 103776))+4);
      i1 = OOC_SymbolTable_TypeRules__IsStringConst((OOC_SymbolTable__Type)i1);
      if (i1) goto l3;
      return 1u;
      goto l8;
l3:
      i1 = (OOC_INT32)type;
      i2 = *(OOC_UINT8*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 103809)))), &_td_OOC_SymbolTable__ArrayDesc, 103809)), 103815))+40);
      if (i2) goto l6;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 103894)))), &_td_OOC_IR__ConstDesc, 103894)), 103900))+8);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 103914)))), &_td_Object_Boxed__StringDesc, 103914)), 103921));
      i0 = *(OOC_INT32*)(_check_pointer(i0, 103928));
      i1 = *(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 103966)))), &_td_OOC_SymbolTable__ArrayDesc, 103966)), 103972))+52);
      return (i0<i1);
      goto l8;
l6:
      return 0u;
l8:
      _failed_function(103713); return 0;
      ;
    }


  i0 = (OOC_INT32)*expr;
  oldExpr = (OOC_IR__Expression)i0;
  i1 = (OOC_INT32)type;
  i2 = i1==(OOC_INT32)0;
  if (i2) goto l31;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 104177)))), &_td_OOC_SymbolTable__TypeVarDesc);
  if (i2) goto l5;
  i2=0u;
  goto l11;
l5:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 104216))+4);
  i2 = i1==i2;
  if (i2) goto l8;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 104244))+4);
  i2 = OOC_IR__IsPredefType((OOC_SymbolTable__Type)i2, 16);
  
  goto l9;
l8:
  i2=1u;
l9:
  i2 = !i2;
  
l11:
  if (i2) goto l29;
  i2 = OOC_IR__IsPredefType((OOC_SymbolTable__Type)i1, 11);
  if (i2) goto l15;
  i2=0u;
  goto l17;
l15:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 104507))+4);
  i2 = OOC_SymbolTable_TypeRules__IsByteCompatible((OOC_SymbolTable__Type)i2);
  
l17:
  if (i2) goto l23;
  i2 = (OOC_INT32)b;
  i1 = OOC_IR__BuilderDesc_Widen((OOC_IR__Builder)i2, (void*)(OOC_INT32)expr, (OOC_SymbolTable__Type)i1);
  if (i1) goto l21;
  i1=0u;
  goto l25;
l21:
  i1 = OOC_IR__BuilderDesc_WidenForAssign_LengthOk();
  
  goto l25;
l23:
  i1=1u;
l25:
  if (i1) goto l27;
  *expr = (OOC_IR__Expression)i0;
  return 0u;
  goto l32;
l27:
  return 1u;
  goto l32;
l29:
  return 0u;
  goto l32;
l31:
  i0 = (OOC_INT32)b;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 104129))+20);
  *expr = (OOC_IR__Expression)i0;
  return 0u;
l32:
  _failed_function(103273); return 0;
  ;
}

OOC_CHAR8 OOC_IR__BuilderDesc_WidenToCommon(OOC_IR__Builder b, OOC_IR__Expression *left, OOC_IR__Expression *right) {
  register OOC_INT32 i0,i1,i2;
  auto OOC_SymbolTable__Type OOC_IR__BuilderDesc_WidenToCommon_CommonBase(OOC_SymbolTable__Type t1, OOC_SymbolTable__Type t2);
    
    OOC_SymbolTable__Type OOC_IR__BuilderDesc_WidenToCommon_CommonBase(OOC_SymbolTable__Type t1, OOC_SymbolTable__Type t2) {
      register OOC_INT32 i0,i1,i2;

      i0 = (OOC_INT32)t1;
      i0 = (OOC_INT32)OOC_SymbolTable_TypeRules__BaseCharType((OOC_SymbolTable__Type)i0);
      i1 = (OOC_INT32)t2;
      i1 = (OOC_INT32)OOC_SymbolTable_TypeRules__BaseCharType((OOC_SymbolTable__Type)i1);
      i2 = i0!=(OOC_INT32)0;
      if (i2) goto l3;
      i2=0u;
      goto l5;
l3:
      i2 = i1!=(OOC_INT32)0;
      
l5:
      if (i2) goto l7;
      return (OOC_SymbolTable__Type)(OOC_INT32)0;
      goto l12;
l7:
      i2 = OOC_SymbolTable_TypeRules__IncludesType((OOC_SymbolTable__Type)i1, (OOC_SymbolTable__Type)i0);
      if (!i2) goto l11;
      i0=i1;
l11:
      i0 = (OOC_INT32)OOC_SymbolTable_TypeRules__MatchingStringConst((OOC_SymbolTable__Type)i0);
      return (OOC_SymbolTable__Type)i0;
l12:
      _failed_function(105250); return 0;
      ;
    }


  i0 = (OOC_INT32)*right;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 105785))+4);
  i1 = (OOC_INT32)b;
  i0 = OOC_IR__BuilderDesc_Widen((OOC_IR__Builder)i1, (void*)(OOC_INT32)left, (OOC_SymbolTable__Type)i0);
  if (i0) goto l3;
  i0 = (OOC_INT32)*left;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 105814))+4);
  i0 = OOC_IR__BuilderDesc_Widen((OOC_IR__Builder)i1, (void*)(OOC_INT32)right, (OOC_SymbolTable__Type)i0);
  
  goto l5;
l3:
  i0=1u;
l5:
  if (i0) goto l21;
  i0 = (OOC_INT32)*left;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 105857)))), &_td_OOC_IR__ConstDesc);
  if (i1) goto l9;
  i1=0u;
  goto l11;
l9:
  i1 = (OOC_INT32)*right;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 105876)))), &_td_OOC_IR__ConstDesc);
  
l11:
  if (!i1) goto l22;
  i1 = (OOC_INT32)*right;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 105930))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 105918))+4);
  i0 = (OOC_INT32)OOC_IR__BuilderDesc_WidenToCommon_CommonBase((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l22;
  i1 = (OOC_INT32)b;
  i2 = OOC_IR__BuilderDesc_Widen((OOC_IR__Builder)i1, (void*)(OOC_INT32)left, (OOC_SymbolTable__Type)i0);
  if (i2) goto l17;
  i0=0u;
  goto l18;
l17:
  i0 = OOC_IR__BuilderDesc_Widen((OOC_IR__Builder)i1, (void*)(OOC_INT32)right, (OOC_SymbolTable__Type)i0);
  
l18:
  _assert(i0, 127, 106023);
  return 1u;
  goto l22;
l21:
  return 1u;
l22:
  return 0u;
  ;
}

static void OOC_IR__MakeAssignmentCompatible(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression *expr, OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)type;
  i1 = (OOC_INT32)b;
  i2 = OOC_IR__BuilderDesc_WidenForAssign((OOC_IR__Builder)i1, (void*)(OOC_INT32)expr, (OOC_SymbolTable__Type)i0);
  i2 = !i2;
  if (i2) goto l3;
  i2=0u;
  goto l5;
l3:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 106544))+20);
  i3 = (OOC_INT32)*expr;
  i2 = i3!=i2;
  
l5:
  if (!i2) goto l10;
  i2 = (OOC_INT32)sym;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 106568)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 24, (OOC_Scanner_SymList__Symbol)i2);
  OOC_IR__BuilderDesc_SetNameToType((OOC_IR__Builder)i1, (OOC_SymbolTable__Type)i0);
  i0 = (OOC_INT32)*expr;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 106656))+4);
  i0 = i0==(OOC_INT32)0;
  if (!i0) goto l10;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 106729))+20);
  *expr = (OOC_IR__Expression)i0;
l10:
  return;
  ;
}

static void OOC_IR__InitTypeTag(OOC_IR__TypeTag tag, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression design) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(6);
  i1 = (OOC_INT32)tag;
  i2 = (OOC_INT32)sym;
  OOC_IR__InitOperator((OOC_IR__Operator)i1, (OOC_Scanner_SymList__Symbol)i2, (OOC_SymbolTable__Type)i0);
  i0 = (OOC_INT32)design;
  *(OOC_INT32*)((_check_pointer(i1, 107048))+8) = i0;
  return;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_NewTypeTag(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression design) {
  register OOC_INT32 i0,i1,i2;
  OOC_SymbolTable__Type type;

  i0 = (OOC_INT32)design;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 107239))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 107239))+4);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 107244)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i2);
  type = (OOC_SymbolTable__Type)i1;
  i2 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 107270)))), &_td_OOC_SymbolTable__RecordDesc));
  if (i2) goto l3;
  i1 = *(OOC_UINT8*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 107298)))), &_td_OOC_SymbolTable__RecordDesc, 107298)), 107305))+38);
  i1 = !i1;
  
  goto l5;
l3:
  i1=1u;
l5:
  if (!i1) goto l7;
  i1 = (OOC_INT32)b;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 107357));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 107332)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 55, (OOC_Scanner_SymList__Symbol)i2);
l7:
  i1 = (OOC_INT32)sym;
  i2 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__TypeTag.baseTypes[0]);
  OOC_IR__InitTypeTag((OOC_IR__TypeTag)i2, (OOC_Scanner_SymList__Symbol)i1, (OOC_IR__Expression)i0);
  return (OOC_IR__Expression)i2;
  ;
}

void OOC_IR__VisitorDesc_VisitTypeTag(OOC_IR__Visitor v, OOC_IR__TypeTag tag) {

  return;
  ;
}

void OOC_IR__TypeTagDesc_Accept(OOC_IR__TypeTag tag, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)tag;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 107609)))), OOC_IR__VisitorDesc_VisitTypeTag)),OOC_IR__VisitorDesc_VisitTypeTag)((OOC_IR__Visitor)i0, (OOC_IR__TypeTag)i1);
  return;
  ;
}

static void OOC_IR__InitTypeTest(OOC_IR__TypeTest test, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression expr, OOC_SymbolTable__Type referenceType, OOC_CHAR8 checkPointer, OOC_IR__Expression origExpr, OOC_IR__TypeRef origType) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(0);
  i1 = (OOC_INT32)test;
  i2 = (OOC_INT32)sym;
  OOC_IR__InitOperator((OOC_IR__Operator)i1, (OOC_Scanner_SymList__Symbol)i2, (OOC_SymbolTable__Type)i0);
  i0 = (OOC_INT32)expr;
  *(OOC_INT32*)((_check_pointer(i1, 108064))+8) = i0;
  i0 = (OOC_INT32)referenceType;
  *(OOC_INT32*)((_check_pointer(i1, 108088))+12) = i0;
  i0 = checkPointer;
  *(OOC_UINT8*)((_check_pointer(i1, 108130))+16) = i0;
  i0 = (OOC_INT32)origExpr;
  *(OOC_INT32*)((_check_pointer(i1, 108170))+20) = i0;
  i0 = (OOC_INT32)origType;
  *(OOC_INT32*)((_check_pointer(i1, 108202))+24) = i0;
  return;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_NewTypeTest(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression expr, OOC_IR__Expression referenceType) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  OOC_SymbolTable__Type refType;
  OOC_IR__Expression origExpr;
  OOC_CHAR8 checkPointer;
  OOC_IR__TypeTest test;
  auto OOC_CHAR8 OOC_IR__BuilderDesc_NewTypeTest_HasDynamicType(OOC_IR__Expression expr);
    
    OOC_CHAR8 OOC_IR__BuilderDesc_NewTypeTest_HasDynamicType(OOC_IR__Expression expr) {
      register OOC_INT32 i0,i1,i2;
      OOC_SymbolTable__Type type;

      i0 = (OOC_INT32)expr;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 108582))+4);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 108582))+4);
      i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 108587)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i2);
      type = (OOC_SymbolTable__Type)i1;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 108614)))), &_td_OOC_SymbolTable__RecordDesc);
      if (i2) goto l15;
      i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 108787)))), &_td_OOC_SymbolTable__PointerDesc);
      if (i0) goto l9;
      i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 108876)))), &_td_OOC_SymbolTable__TypeVarDesc);
      if (i0) goto l7;
      return 0u;
      goto l24;
l7:
      return 1u;
      goto l24;
l9:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 108835))+40);
      i0 = OOC_SymbolTable_TypeRules__IsRecord((OOC_SymbolTable__Type)i0);
      if (i0) goto l12;
      i0=0u;
      goto l13;
l12:
      i0 = *(OOC_UINT8*)((_check_pointer(i1, 108853))+49);
      i0 = !i0;
      
l13:
      return i0;
      goto l24;
l15:
      i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 108652)))), &_td_OOC_IR__VarDesc));
      if (i1) goto l22;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 108681)))), &_td_OOC_IR__VarDesc, 108681)), 108685))+8);
      i1 = *(OOC_UINT8*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 108695)))), &_td_OOC_SymbolTable__VarDeclDesc, 108695)), 108703))+59);
      if (i1) goto l20;
      i0=0u;
      goto l23;
l20:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 108735)))), &_td_OOC_IR__VarDesc, 108735)), 108739))+8);
      i0 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 108749)))), &_td_OOC_SymbolTable__VarDeclDesc, 108749)), 108757))+64);
      
      goto l23;
l22:
      i0=1u;
l23:
      return i0;
l24:
      _failed_function(108480); return 0;
      ;
    }


  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)referenceType;
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 109072)))), OOC_IR__BuilderDesc_AssertType)),OOC_IR__BuilderDesc_AssertType)((OOC_IR__Builder)i0, (OOC_IR__Expression)i1);
  i2 = (OOC_INT32)OOC_SymbolTable__Expand((OOC_SymbolTable__Type)i2);
  refType = (OOC_SymbolTable__Type)i2;
  i3 = i2==(OOC_INT32)0;
  if (i3) goto l34;
  i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 109175)))), &_td_OOC_SymbolTable__TypeVarDesc);
  if (i3) goto l32;
  i3 = (OOC_INT32)expr;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 109297))+4);
  i2 = OOC_SymbolTable_TypeRules__IsExtensionOf((OOC_SymbolTable__Type)i2, (OOC_SymbolTable__Type)i4);
  i2 = !i2;
  if (i2) goto l30;
  i0 = OOC_IR__BuilderDesc_NewTypeTest_HasDynamicType((OOC_IR__Expression)i3);
  i0 = !i0;
  if (i0) goto l28;
  i0 = (OOC_INT32)expr;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 109722))+4);
  i2 = (OOC_INT32)refType;
  i1 = OOC_SymbolTable_TypeRules__SameType((OOC_SymbolTable__Type)i2, (OOC_SymbolTable__Type)i1);
  if (!i1) goto l11;
  i1 = (OOC_INT32)referenceType;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 109784));
  i3 = (OOC_INT32)b;
  OOC_IR__BuilderDesc_WarnSym((OOC_IR__Builder)i3, 61, (OOC_Scanner_SymList__Symbol)i1);
l11:
  origExpr = (OOC_IR__Expression)i0;
  i1 = (OOC_INT32)sym;
  i3 = *(OOC_INT32*)((_check_pointer(i1, 109900))+16);
  i4 = (OOC_INT32)OOC_Config_StdPragmas__derefCheck;
  i5 = (OOC_INT32)b;
  i3 = OOC_IR__GetPragmaValue((OOC_IR__Builder)i5, (Config_Section_Options__Option)i4, i3);
  checkPointer = i3;
  i4 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 109923)))), &_td_OOC_IR__DerefDesc);
  if (i4) goto l22;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 109993))+4);
  i4 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 109999)))), &_td_OOC_SymbolTable__PointerDesc);
  if (i4) goto l16;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 110023))+4);
  i4 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 110029)))), &_td_OOC_SymbolTable__TypeVarDesc);
  
  goto l18;
l16:
  i4=1u;
l18:
  if (!i4) goto l21;
  i2 = (OOC_INT32)OOC_SymbolTable_TypeRules__PointerBaseType((OOC_SymbolTable__Type)i2);
  refType = (OOC_SymbolTable__Type)i2;
  
l21:
  i4=i0;
  goto l23;
l22:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 109959)))), &_td_OOC_IR__DerefDesc, 109959)), 109965))+8);
  expr = (OOC_IR__Expression)i4;
  
l23:
  i5 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__TypeTest.baseTypes[0]);
  test = (OOC_IR__TypeTest)i5;
  i6 = (OOC_INT32)referenceType;
  i7 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 110151)))), &_td_OOC_IR__TypeRefDesc);
  if (i7) goto l26;
  i6=(OOC_INT32)0;
  goto l27;
l26:
  i6 = _type_guard(i6, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 110201)))), &_td_OOC_IR__TypeRefDesc, 110201);
  
l27:
  OOC_IR__InitTypeTest((OOC_IR__TypeTest)i5, (OOC_Scanner_SymList__Symbol)i1, (OOC_IR__Expression)i4, (OOC_SymbolTable__Type)i2, i3, (OOC_IR__Expression)i0, (OOC_IR__TypeRef)i6);
  return (OOC_IR__Expression)i5;
  goto l35;
l28:
  i0 = (OOC_INT32)expr;
  i1 = (OOC_INT32)b;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 109672));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 109642)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i1, 43, (OOC_Scanner_SymList__Symbol)i0);
  return (OOC_IR__Expression)i0;
  goto l35;
l30:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 109366));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 109323)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i0, 17, (OOC_Scanner_SymList__Symbol)i1);
  return (OOC_IR__Expression)i0;
  goto l35;
l32:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 109249));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 109210)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i0, 67, (OOC_Scanner_SymList__Symbol)i1);
  return (OOC_IR__Expression)i0;
  goto l35;
l34:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 109143))+20);
  return (OOC_IR__Expression)i0;
l35:
  _failed_function(108270); return 0;
  ;
}

void OOC_IR__VisitorDesc_VisitTypeTest(OOC_IR__Visitor v, OOC_IR__TypeTest test) {

  return;
  ;
}

void OOC_IR__TypeTestDesc_Accept(OOC_IR__TypeTest test, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)test;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 110535)))), OOC_IR__VisitorDesc_VisitTypeTest)),OOC_IR__VisitorDesc_VisitTypeTest)((OOC_IR__Visitor)i0, (OOC_IR__TypeTest)i1);
  return;
  ;
}

static void OOC_IR__InitTypeGuard(OOC_IR__TypeGuard guard, OOC_Scanner_SymList__Symbol sym, OOC_SymbolTable__Type type, OOC_IR__TypeTest test, OOC_CHAR8 checkPointer, OOC_CHAR8 checkType) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)type;
  i1 = (OOC_INT32)sym;
  i2 = (OOC_INT32)guard;
  OOC_IR__InitOperator((OOC_IR__Operator)i2, (OOC_Scanner_SymList__Symbol)i1, (OOC_SymbolTable__Type)i0);
  i0 = (OOC_INT32)test;
  *(OOC_INT32*)((_check_pointer(i2, 110909))+8) = i0;
  i0 = checkPointer;
  *(OOC_UINT8*)((_check_pointer(i2, 110934))+12) = i0;
  i0 = checkType;
  *(OOC_UINT8*)((_check_pointer(i2, 110975))+13) = i0;
  return;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_NewTypeGuard(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression design, OOC_IR__TypeRef ref) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  OOC_SymbolTable__Type guardType;
  OOC_IR__Expression test;
  OOC_IR__TypeGuard guard;

  i0 = (OOC_INT32)ref;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 111252))+12);
  guardType = (OOC_SymbolTable__Type)i1;
  i2 = (OOC_INT32)b;
  i3 = (OOC_INT32)design;
  i4 = (OOC_INT32)sym;
  OOC_IR__BuilderDesc_CheckFunctionOp((OOC_IR__Builder)i2, (OOC_IR__Expression)i3, (OOC_Scanner_SymList__Symbol)i4);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 111308)))), OOC_IR__BuilderDesc_NewTypeTest)),OOC_IR__BuilderDesc_NewTypeTest)((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i4, (OOC_IR__Expression)i3, (OOC_IR__Expression)i0);
  test = (OOC_IR__Expression)i0;
  i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 111350)))), &_td_OOC_IR__TypeTestDesc);
  if (i3) goto l3;
  return (OOC_IR__Expression)i0;
  goto l4;
l3:
  i3 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__TypeGuard.baseTypes[0]);
  guard = (OOC_IR__TypeGuard)i3;
  i5 = *(OOC_INT32*)((_check_pointer(i4, 111582))+16);
  i6 = (OOC_INT32)OOC_Config_StdPragmas__typeGuard;
  i5 = OOC_IR__GetPragmaValue((OOC_IR__Builder)i2, (Config_Section_Options__Option)i6, i5);
  i6 = *(OOC_INT32*)((_check_pointer(i4, 111514))+16);
  i7 = (OOC_INT32)OOC_Config_StdPragmas__derefCheck;
  i2 = OOC_IR__GetPragmaValue((OOC_IR__Builder)i2, (Config_Section_Options__Option)i7, i6);
  i1 = (OOC_INT32)OOC_SymbolTable__Expand((OOC_SymbolTable__Type)i1);
  OOC_IR__InitTypeGuard((OOC_IR__TypeGuard)i3, (OOC_Scanner_SymList__Symbol)i4, (OOC_SymbolTable__Type)i1, (OOC_IR__TypeTest)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 111441)))), &_td_OOC_IR__TypeTestDesc, 111441)), i2, i5);
  return (OOC_IR__Expression)i3;
l4:
  _failed_function(111047); return 0;
  ;
}

void OOC_IR__VisitorDesc_VisitTypeGuard(OOC_IR__Visitor v, OOC_IR__TypeGuard test) {

  return;
  ;
}

void OOC_IR__TypeGuardDesc_Accept(OOC_IR__TypeGuard test, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)test;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 111813)))), OOC_IR__VisitorDesc_VisitTypeGuard)),OOC_IR__VisitorDesc_VisitTypeGuard)((OOC_IR__Visitor)i0, (OOC_IR__TypeGuard)i1);
  return;
  ;
}

static void OOC_IR__InitReference(OOC_IR__Reference ref, OOC_Scanner_SymList__Symbol name, OOC_SymbolTable__Type type, OOC_SymbolTable__Declaration decl) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)type;
  i1 = (OOC_INT32)name;
  i2 = (OOC_INT32)ref;
  OOC_IR__InitExpression((OOC_IR__Expression)i2, (OOC_Scanner_SymList__Symbol)i1, (OOC_SymbolTable__Type)i0);
  i0 = (OOC_INT32)decl;
  *(OOC_INT32*)((_check_pointer(i2, 112137))+8) = i0;
  return;
  ;
}

static void OOC_IR__InitModuleRef(OOC_IR__ModuleRef modRef, OOC_Scanner_SymList__Symbol name, OOC_SymbolTable__Type type, OOC_SymbolTable__Module decl) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)decl;
  i1 = (OOC_INT32)type;
  i2 = (OOC_INT32)name;
  i3 = (OOC_INT32)modRef;
  OOC_IR__InitReference((OOC_IR__Reference)i3, (OOC_Scanner_SymList__Symbol)i2, (OOC_SymbolTable__Type)i1, (OOC_SymbolTable__Declaration)i0);
  return;
  ;
}

OOC_IR__ModuleRef OOC_IR__BuilderDesc_NewModuleRef(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol name, OOC_SymbolTable__Module decl) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_IR__ModuleRef modRef;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__ModuleRef.baseTypes[0]);
  modRef = (OOC_IR__ModuleRef)i0;
  i1 = (OOC_INT32)b;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 112650))+28);
  i2 = (OOC_INT32)name;
  i3 = (OOC_INT32)decl;
  OOC_IR__InitModuleRef((OOC_IR__ModuleRef)i0, (OOC_Scanner_SymList__Symbol)i2, (OOC_SymbolTable__Type)i1, (OOC_SymbolTable__Module)i3);
  return (OOC_IR__ModuleRef)i0;
  ;
}

void OOC_IR__VisitorDesc_VisitModuleRef(OOC_IR__Visitor v, OOC_IR__ModuleRef modRef) {

  return;
  ;
}

void OOC_IR__ModuleRefDesc_Accept(OOC_IR__ModuleRef modRef, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)modRef;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 112869)))), OOC_IR__VisitorDesc_VisitModuleRef)),OOC_IR__VisitorDesc_VisitModuleRef)((OOC_IR__Visitor)i0, (OOC_IR__ModuleRef)i1);
  return;
  ;
}

static void OOC_IR__InitPredefProc(OOC_IR__PredefProc pproc, OOC_Scanner_SymList__Symbol name, OOC_SymbolTable__Type type, OOC_SymbolTable__PredefProc decl) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)decl;
  i1 = (OOC_INT32)type;
  i2 = (OOC_INT32)name;
  i3 = (OOC_INT32)pproc;
  OOC_IR__InitReference((OOC_IR__Reference)i3, (OOC_Scanner_SymList__Symbol)i2, (OOC_SymbolTable__Type)i1, (OOC_SymbolTable__Declaration)i0);
  return;
  ;
}

static OOC_IR__PredefProc OOC_IR__NewPredefProc(OOC_Scanner_SymList__Symbol name, OOC_SymbolTable__PredefProc decl) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__PredefProc.baseTypes[0]);
  i1 = (OOC_INT32)decl;
  i2 = (OOC_INT32)name;
  OOC_IR__InitPredefProc((OOC_IR__PredefProc)i0, (OOC_Scanner_SymList__Symbol)i2, (OOC_SymbolTable__Type)(OOC_INT32)0, (OOC_SymbolTable__PredefProc)i1);
  return (OOC_IR__PredefProc)i0;
  ;
}

void OOC_IR__VisitorDesc_VisitPredefProc(OOC_IR__Visitor v, OOC_IR__PredefProc pproc) {

  return;
  ;
}

void OOC_IR__PredefProcDesc_Accept(OOC_IR__PredefProc pproc, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)pproc;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 113595)))), OOC_IR__VisitorDesc_VisitPredefProc)),OOC_IR__VisitorDesc_VisitPredefProc)((OOC_IR__Visitor)i0, (OOC_IR__PredefProc)i1);
  return;
  ;
}

static void OOC_IR__InitProcedureRef(OOC_IR__ProcedureRef procRef, OOC_Scanner_SymList__Symbol name, OOC_SymbolTable__ProcDecl decl) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)decl;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 113882))+64);
  i2 = (OOC_INT32)procRef;
  i3 = (OOC_INT32)name;
  OOC_IR__InitReference((OOC_IR__Reference)i2, (OOC_Scanner_SymList__Symbol)i3, (OOC_SymbolTable__Type)i1, (OOC_SymbolTable__Declaration)i0);
  return;
  ;
}

static OOC_IR__ProcedureRef OOC_IR__NewProcedureRef(OOC_Scanner_SymList__Symbol name, OOC_SymbolTable__ProcDecl decl) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__ProcedureRef.baseTypes[0]);
  i1 = (OOC_INT32)decl;
  i2 = (OOC_INT32)name;
  OOC_IR__InitProcedureRef((OOC_IR__ProcedureRef)i0, (OOC_Scanner_SymList__Symbol)i2, (OOC_SymbolTable__ProcDecl)i1);
  return (OOC_IR__ProcedureRef)i0;
  ;
}

void OOC_IR__VisitorDesc_VisitProcedureRef(OOC_IR__Visitor v, OOC_IR__ProcedureRef procRef) {

  return;
  ;
}

void OOC_IR__ProcedureRefDesc_Accept(OOC_IR__ProcedureRef procRef, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)procRef;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 114324)))), OOC_IR__VisitorDesc_VisitProcedureRef)),OOC_IR__VisitorDesc_VisitProcedureRef)((OOC_IR__Visitor)i0, (OOC_IR__ProcedureRef)i1);
  return;
  ;
}

static void OOC_IR__InitTypeRef(OOC_IR__TypeRef typeRef, OOC_Scanner_SymList__Symbol name, OOC_SymbolTable__Type type, OOC_SymbolTable__TypeDecl decl, OOC_SymbolTable__Type qualType) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)decl;
  i1 = (OOC_INT32)type;
  i2 = (OOC_INT32)name;
  i3 = (OOC_INT32)typeRef;
  OOC_IR__InitReference((OOC_IR__Reference)i3, (OOC_Scanner_SymList__Symbol)i2, (OOC_SymbolTable__Type)i1, (OOC_SymbolTable__Declaration)i0);
  i0 = (OOC_INT32)qualType;
  *(OOC_INT32*)((_check_pointer(i3, 114678))+12) = i0;
  return;
  ;
}

OOC_IR__TypeRef OOC_IR__BuilderDesc_NewTypeRef(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol name, OOC_SymbolTable__TypeDecl decl) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
  OOC_SymbolTable__Type qualType;
  OOC_SymbolTable__TypeRefArray arguments;
  OOC_INT32 i;
  OOC_IR__TypeRef typeRef;

  i0 = (OOC_INT32)decl;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 114929))+48);
  qualType = (OOC_SymbolTable__Type)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 114952))+28);
  i2 = i2!=(OOC_INT32)0;
  if (i2) goto l3;
  i2=0u;
  goto l5;
l3:
  i2 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 114982)))), &_td_OOC_SymbolTable__TypeVarDesc));
  
l5:
  if (!i2) goto l16;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 115106))+28);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 115115))+20);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 115122)), 0);
  i2 = (OOC_INT32)RT0__NewObject(_td_OOC_SymbolTable__TypeRefArray.baseTypes[0], i2);
  arguments = (OOC_SymbolTable__TypeRefArray)i2;
  i = 0;
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i2, 115160)), 0);
  i4 = 0<i3;
  if (!i4) goto l15;
  i4 = (OOC_INT32)&_td_OOC_SymbolTable__TypeRef;
  i5=0;
l10_loop:
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 115214))+28);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 115223))+20);
  i6 = _check_pointer(i6, 115230);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i5, i7, OOC_UINT32, 115230))*4);
  i7 = OOC_ARRAY_LENGTH((_check_pointer(i2, 115201)), 0);
  i7 = _check_index(i5, i7, OOC_UINT32, 115201);
  i7 = _check_pointer(i2, 115201);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 115233))+40);
  OOC_SymbolTable__InitTypeRef((void*)(i7+(_check_index(i5, i8, OOC_UINT32, 115201))*8), (RT0__Struct)i4, (OOC_SymbolTable__Type)i6);
  i5 = i5+1;
  i = i5;
  i6 = i5<i3;
  if (i6) goto l10_loop;
l15:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 115300))+20);
  i1 = (OOC_INT32)OOC_SymbolTable__NewQualType((OOC_SymbolTable__Item)(OOC_INT32)0, (OOC_SymbolTable__Position)i3, (OOC_SymbolTable__Type)i1, (OOC_SymbolTable__TypeRefArray)i2);
  qualType = (OOC_SymbolTable__Type)i1;
  
l16:
  i2 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__TypeRef.baseTypes[0]);
  typeRef = (OOC_IR__TypeRef)i2;
  i3 = (OOC_INT32)b;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 115431))+24);
  i4 = (OOC_INT32)name;
  OOC_IR__InitTypeRef((OOC_IR__TypeRef)i2, (OOC_Scanner_SymList__Symbol)i4, (OOC_SymbolTable__Type)i3, (OOC_SymbolTable__TypeDecl)i0, (OOC_SymbolTable__Type)i1);
  return (OOC_IR__TypeRef)i2;
  ;
}

void OOC_IR__VisitorDesc_VisitTypeRef(OOC_IR__Visitor v, OOC_IR__TypeRef typeRef) {

  return;
  ;
}

void OOC_IR__TypeRefDesc_Accept(OOC_IR__TypeRef typeRef, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)typeRef;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 115650)))), OOC_IR__VisitorDesc_VisitTypeRef)),OOC_IR__VisitorDesc_VisitTypeRef)((OOC_IR__Visitor)i0, (OOC_IR__TypeRef)i1);
  return;
  ;
}

static void OOC_IR__InitVar(OOC_IR__Var var, OOC_Scanner_SymList__Symbol name, OOC_SymbolTable__Type type, OOC_SymbolTable__VarDecl decl) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)decl;
  i1 = (OOC_INT32)type;
  i2 = (OOC_INT32)name;
  i3 = (OOC_INT32)var;
  OOC_IR__InitReference((OOC_IR__Reference)i3, (OOC_Scanner_SymList__Symbol)i2, (OOC_SymbolTable__Type)i1, (OOC_SymbolTable__Declaration)i0);
  return;
  ;
}

OOC_IR__Var OOC_IR__BuilderDesc_NewVar(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol name, OOC_SymbolTable__VarDecl decl) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11,i12;
  OOC_IR__Var var;
  OOC_SymbolTable__TypeRefArray args;
  OOC_SymbolTable__TypeVarArray params;
  OOC_SymbolTable__TypeRefArray recordArgs;
  OOC_INT32 i;
  OOC_INT32 j;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__Var.baseTypes[0]);
  var = (OOC_IR__Var)i0;
  i1 = (OOC_INT32)decl;
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 116216))+57);
  if (i2) goto l3;
  i2=0u;
  goto l5;
l3:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 116235))+48);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 116240))+28);
  i2 = i2!=(OOC_INT32)0;
  
l5:
  if (i2) goto l7;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 117862))+48);
  i2 = (OOC_INT32)OOC_SymbolTable__Expand((OOC_SymbolTable__Type)i2);
  
  goto l53;
l7:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 116507))+48);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 116512))+28);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 116521))+20);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 116528)), 0);
  i2 = (OOC_INT32)RT0__NewObject(_td_OOC_SymbolTable__TypeRefArray.baseTypes[0], i2);
  args = (OOC_SymbolTable__TypeRefArray)i2;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 116547))+48);
  i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 116553)))), &_td_OOC_SymbolTable__PointerDesc);
  if (i3) goto l10;
  i3=0u;
  goto l12;
l10:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 116585))+48);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 116595)))), &_td_OOC_SymbolTable__PointerDesc, 116595)), 116603))+40);
  i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 116613)))), &_td_OOC_SymbolTable__QualTypeDesc);
  
l12:
  if (i3) goto l22;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 117560))+48);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 117565))+28);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 117574))+20);
  params = (OOC_SymbolTable__TypeVarArray)i3;
  i = 0;
  i4 = OOC_ARRAY_LENGTH((_check_pointer(i2, 117613)), 0);
  i5 = 0<i4;
  if (!i5) goto l52;
  i5 = (OOC_INT32)&_td_OOC_SymbolTable__TypeRef;
  i6=0;
l16_loop:
  i7 = _check_pointer(i3, 117662);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i9 = OOC_ARRAY_LENGTH((_check_pointer(i2, 117651)), 0);
  i9 = _check_index(i6, i9, OOC_UINT32, 117651);
  i9 = _check_pointer(i2, 117651);
  i10 = OOC_ARRAY_LENGTH(i9, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i6, i8, OOC_UINT32, 117662))*4);
  OOC_SymbolTable__InitTypeRef((void*)(i9+(_check_index(i6, i10, OOC_UINT32, 117651))*8), (RT0__Struct)i5, (OOC_SymbolTable__Type)i7);
  i6 = i6+1;
  i = i6;
  i7 = i6<i4;
  if (i7) goto l16_loop;
  goto l52;
l22:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 116951))+48);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 116961)))), &_td_OOC_SymbolTable__PointerDesc, 116961)), 116969))+40);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 116996)))), &_td_OOC_SymbolTable__QualTypeDesc, 116996)), 117005))+40);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 117019)))), &_td_OOC_SymbolTable__RecordDesc, 117019)), 117026))+28);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 117035))+20);
  params = (OOC_SymbolTable__TypeVarArray)i3;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 117070))+48);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 117080)))), &_td_OOC_SymbolTable__PointerDesc, 117080)), 117088))+40);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 117102)))), &_td_OOC_SymbolTable__QualTypeDesc, 117102)), 117111))+48);
  recordArgs = (OOC_SymbolTable__TypeRefArray)i4;
  i = 0;
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i2, 117153)), 0);
  i6 = 0<i5;
  if (!i6) goto l52;
  i6 = (OOC_INT32)&_td_OOC_SymbolTable__TypeRef;
  i7=0;
l25_loop:
  j = 0;
  i8 = OOC_ARRAY_LENGTH((_check_pointer(i4, 117214)), 0);
  i8 = 0!=i8;
  if (i8) goto l28;
  i8=0u;
  goto l30;
l28:
  i8 = _check_pointer(i4, 117247);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i10 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 117262))+48);
  i10 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i10, 117267))+28);
  i10 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i10, 117276))+20);
  i10 = _check_pointer(i10, 117283);
  i11 = OOC_ARRAY_LENGTH(i10, 0);
  i8 = (OOC_INT32)*(OOC_INT32*)(i8+(_check_index(0, i9, OOC_UINT32, 117247))*8);
  i9 = (OOC_INT32)*(OOC_INT32*)(i10+(_check_index(i7, i11, OOC_UINT32, 117283))*4);
  i8 = i8!=i9;
  
l30:
  if (i8) goto l32;
  i8=0;
  goto l42;
l32:
  i8=0;
l33_loop:
  i8 = i8+1;
  j = i8;
  i9 = OOC_ARRAY_LENGTH((_check_pointer(i4, 117214)), 0);
  i9 = i8!=i9;
  if (i9) goto l36;
  i9=0u;
  goto l38;
l36:
  i9 = _check_pointer(i4, 117247);
  i10 = OOC_ARRAY_LENGTH(i9, 0);
  i11 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 117262))+48);
  i11 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i11, 117267))+28);
  i11 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i11, 117276))+20);
  i11 = _check_pointer(i11, 117283);
  i12 = OOC_ARRAY_LENGTH(i11, 0);
  i9 = (OOC_INT32)*(OOC_INT32*)(i9+(_check_index(i8, i10, OOC_UINT32, 117247))*8);
  i10 = (OOC_INT32)*(OOC_INT32*)(i11+(_check_index(i7, i12, OOC_UINT32, 117283))*4);
  i9 = i9!=i10;
  
l38:
  if (i9) goto l33_loop;
l42:
  i9 = OOC_ARRAY_LENGTH((_check_pointer(i4, 117358)), 0);
  i9 = i8==i9;
  if (i9) goto l45;
  i9 = _check_pointer(i3, 117493);
  i10 = OOC_ARRAY_LENGTH(i9, 0);
  i11 = OOC_ARRAY_LENGTH((_check_pointer(i2, 117482)), 0);
  i11 = _check_index(i7, i11, OOC_UINT32, 117482);
  i11 = _check_pointer(i2, 117482);
  i12 = OOC_ARRAY_LENGTH(i11, 0);
  i8 = (OOC_INT32)*(OOC_INT32*)(i9+(_check_index(i8, i10, OOC_UINT32, 117493))*4);
  OOC_SymbolTable__InitTypeRef((void*)(i11+(_check_index(i7, i12, OOC_UINT32, 117482))*8), (RT0__Struct)i6, (OOC_SymbolTable__Type)i8);
  goto l46;
l45:
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 117408))+48);
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i8, 117413))+28);
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i8, 117422))+20);
  i8 = _check_pointer(i8, 117429);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i10 = OOC_ARRAY_LENGTH((_check_pointer(i2, 117399)), 0);
  i10 = _check_index(i7, i10, OOC_UINT32, 117399);
  i10 = _check_pointer(i2, 117399);
  i11 = OOC_ARRAY_LENGTH(i10, 0);
  i8 = (OOC_INT32)*(OOC_INT32*)(i8+(_check_index(i7, i9, OOC_UINT32, 117429))*4);
  OOC_SymbolTable__InitTypeRef((void*)(i10+(_check_index(i7, i11, OOC_UINT32, 117399))*8), (RT0__Struct)i6, (OOC_SymbolTable__Type)i8);
l46:
  i7 = i7+1;
  i = i7;
  i8 = i7<i5;
  if (i8) goto l25_loop;
l52:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 117794))+48);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 117799))+28);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 117730))+48);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 117735))+20);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 117808))+20);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 117750))+48);
  i2 = (OOC_INT32)OOC_SymbolTable__NewTypeClosure((OOC_SymbolTable__Position)i4, (OOC_SymbolTable__Type)i5, (OOC_SymbolTable__TypeVarArray)i3, (OOC_SymbolTable__TypeRefArray)i2);
  
l53:
  i2 = (OOC_INT32)OOC_SymbolTable__Expand((OOC_SymbolTable__Type)i2);
  i3 = (OOC_INT32)name;
  OOC_IR__InitVar((OOC_IR__Var)i0, (OOC_Scanner_SymList__Symbol)i3, (OOC_SymbolTable__Type)i2, (OOC_SymbolTable__VarDecl)i1);
  return (OOC_IR__Var)i0;
  ;
}

void OOC_IR__VisitorDesc_VisitVar(OOC_IR__Visitor v, OOC_IR__Var var) {

  return;
  ;
}

void OOC_IR__VarDesc_Accept(OOC_IR__Var var, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)var;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 118087)))), OOC_IR__VisitorDesc_VisitVar)),OOC_IR__VisitorDesc_VisitVar)((OOC_IR__Visitor)i0, (OOC_IR__Var)i1);
  return;
  ;
}

void OOC_IR__InitStatement(OOC_IR__Statement statm, OOC_Scanner_SymList__Symbol sym) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(17);
  i1 = (OOC_INT32)statm;
  i2 = (OOC_INT32)sym;
  OOC_IR__InitExpression((OOC_IR__Expression)i1, (OOC_Scanner_SymList__Symbol)i2, (OOC_SymbolTable__Type)i0);
  return;
  ;
}

static void OOC_IR__InitAssert(OOC_IR__Assert assert, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression predicate, OOC_INT32 code, OOC_CHAR8 disabled) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)assert;
  OOC_IR__InitStatement((OOC_IR__Statement)i1, (OOC_Scanner_SymList__Symbol)i0);
  i0 = (OOC_INT32)predicate;
  *(OOC_INT32*)((_check_pointer(i1, 118670))+8) = i0;
  i0 = code;
  *(OOC_INT32*)((_check_pointer(i1, 118706))+12) = i0;
  i0 = disabled;
  *(OOC_UINT8*)((_check_pointer(i1, 118732))+16) = i0;
  return;
  ;
}

OOC_IR__Assert OOC_IR__BuilderDesc_NewAssert(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression predicate, OOC_IR__Expression code, OOC_CHAR8 disabled) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_IR__Assert assert;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__Assert.baseTypes[0]);
  assert = (OOC_IR__Assert)i0;
  i1 = (OOC_INT32)predicate;
  i2 = i1!=(OOC_INT32)0;
  if (!i2) goto l4;
  i2 = (OOC_INT32)b;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 119031)))), OOC_IR__BuilderDesc_AssertBoolean)),OOC_IR__BuilderDesc_AssertBoolean)((OOC_IR__Builder)i2, (OOC_IR__Expression)i1);
  
l4:
  i2 = (OOC_INT32)code;
  i3 = i2==(OOC_INT32)0;
  if (i3) goto l7;
  i3 = (OOC_INT32)b;
  i2 = OOC_IR__BuilderDesc_AssertIntConst((OOC_IR__Builder)i3, (OOC_IR__Expression)i2, 0, 128);
  
  goto l8;
l7:
  i2=127;
l8:
  i3 = (OOC_INT32)sym;
  i4 = disabled;
  OOC_IR__InitAssert((OOC_IR__Assert)i0, (OOC_Scanner_SymList__Symbol)i3, (OOC_IR__Expression)i1, i2, i4);
  return (OOC_IR__Assert)i0;
  ;
}

void OOC_IR__VisitorDesc_VisitAssert(OOC_IR__Visitor v, OOC_IR__Assert assert) {

  return;
  ;
}

void OOC_IR__AssertDesc_Accept(OOC_IR__Assert assert, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)assert;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 119459)))), OOC_IR__VisitorDesc_VisitAssert)),OOC_IR__VisitorDesc_VisitAssert)((OOC_IR__Visitor)i0, (OOC_IR__Assert)i1);
  return;
  ;
}

void OOC_IR__InitAssignment(OOC_IR__Assignment assignment, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression variable, OOC_IR__Expression value) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)assignment;
  OOC_IR__InitStatement((OOC_IR__Statement)i1, (OOC_Scanner_SymList__Symbol)i0);
  i0 = (OOC_INT32)variable;
  *(OOC_INT32*)((_check_pointer(i1, 119788))+8) = i0;
  i0 = (OOC_INT32)value;
  *(OOC_INT32*)((_check_pointer(i1, 119826))+12) = i0;
  return;
  ;
}

void OOC_IR__BuilderDesc_AssertVar(OOC_IR__Builder b, OOC_IR__Expression expr) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)expr;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 119940))+4);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l40;
  i1 = (OOC_INT32)b;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 120029));
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 120042))+4);
  i2 = OOC_SymbolTable_TypeRules__IsReadOnlyType((OOC_SymbolTable__Module)i2, (OOC_SymbolTable__Type)i3);
  if (i2) goto l38;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 120125)))), &_td_OOC_IR__VarDesc);
  if (i2) goto l25;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 120395)))), &_td_OOC_IR__DerefDesc);
  if (i2) goto l41;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 120475)))), &_td_OOC_IR__IndexDesc);
  if (i2) goto l22;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 120571)))), &_td_OOC_IR__SelectFieldDesc);
  if (i2) goto l17;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 120797)))), &_td_OOC_IR__TypeGuardDesc);
  if (i2) goto l15;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 120934));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 120907)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 29, (OOC_Scanner_SymList__Symbol)i0);
  goto l41;
l15:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 120837))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 120843))+8);
  OOC_IR__BuilderDesc_AssertVar((OOC_IR__Builder)i1, (OOC_IR__Expression)i0);
  goto l41;
l17:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 120614))+8);
  OOC_IR__BuilderDesc_AssertVar((OOC_IR__Builder)i1, (OOC_IR__Expression)i2);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 120702))+12);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 120688));
  i2 = OOC_SymbolTable_TypeRules__IsReadOnly((OOC_SymbolTable__Module)i3, (OOC_SymbolTable__Declaration)i2);
  if (!i2) goto l41;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 120759))+16);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 120727)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 34, (OOC_Scanner_SymList__Symbol)i0);
  goto l41;
l22:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 120512))+8);
  OOC_IR__BuilderDesc_AssertVar((OOC_IR__Builder)i1, (OOC_IR__Expression)i0);
  goto l41;
l25:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 120175))+8);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 120161));
  i2 = OOC_SymbolTable_TypeRules__IsReadOnly((OOC_SymbolTable__Module)i3, (OOC_SymbolTable__Declaration)i2);
  if (i2) goto l35;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 120258))+8);
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 120264)))), &_td_OOC_SymbolTable__VarDeclDesc);
  if (i2) goto l30;
  i2=0u;
  goto l32;
l30:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 120286))+8);
  i2 = *(OOC_UINT8*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 120296)))), &_td_OOC_SymbolTable__VarDeclDesc, 120296)), 120304))+62);
  
l32:
  if (!i2) goto l41;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 120363));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 120332)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 42, (OOC_Scanner_SymList__Symbol)i0);
  goto l41;
l35:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 120231));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 120199)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 34, (OOC_Scanner_SymList__Symbol)i0);
  goto l41;
l38:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 120093));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 120061)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 34, (OOC_Scanner_SymList__Symbol)i0);
  goto l41;
l40:
  i1 = (OOC_INT32)b;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 119992));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 119965)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 29, (OOC_Scanner_SymList__Symbol)i0);
l41:
  return;
  ;
}

OOC_IR__Statement OOC_IR__BuilderDesc_NewAssignment(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression variable, OOC_IR__Expression value) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_SymbolTable__Type valueType;

  i0 = (OOC_INT32)variable;
  i1 = (OOC_INT32)b;
  OOC_IR__BuilderDesc_AssertVar((OOC_IR__Builder)i1, (OOC_IR__Expression)i0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 121261))+4);
  i3 = (OOC_INT32)sym;
  OOC_IR__MakeAssignmentCompatible((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i3, (void*)(OOC_INT32)&value, (OOC_SymbolTable__Type)i2);
  i2 = (OOC_INT32)value;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 121292))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 121292))+4);
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 121297)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i2);
  valueType = (OOC_SymbolTable__Type)i2;
  i4 = OOC_SymbolTable_TypeRules__IsStringConst((OOC_SymbolTable__Type)i2);
  if (i4) goto l11;
  i4 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 121562)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (i4) goto l5;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 121590)))), &_td_OOC_SymbolTable__RecordDesc);
  
  goto l7;
l5:
  i2=1u;
l7:
  if (i2) goto l9;
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__Assignment.baseTypes[0]);
  i2 = (OOC_INT32)value;
  OOC_IR__InitAssignment((OOC_IR__Assignment)i1, (OOC_Scanner_SymList__Symbol)i3, (OOC_IR__Expression)i0, (OOC_IR__Expression)i2);
  return (OOC_IR__Statement)i1;
  goto l12;
l9:
  i2 = (OOC_INT32)value;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 121685)))), OOC_IR__BuilderDesc_NewCopy)),OOC_IR__BuilderDesc_NewCopy)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i3, (OOC_IR__Expression)i2, (OOC_IR__Expression)i0);
  return (OOC_IR__Statement)i0;
  goto l12;
l11:
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 121510)))), OOC_IR__BuilderDesc_NewLen)),OOC_IR__BuilderDesc_NewLen)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i3, (OOC_IR__Expression)i0, 0);
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 121501)))), OOC_IR__BuilderDesc_Fold)),OOC_IR__BuilderDesc_Fold)((OOC_IR__Builder)i1, (OOC_IR__Expression)i2);
  i4 = (OOC_INT32)value;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 121430)))), OOC_IR__BuilderDesc_NewCopyString)),OOC_IR__BuilderDesc_NewCopyString)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i3, (OOC_IR__Expression)i4, (OOC_IR__Expression)i0, (OOC_IR__Expression)i2);
  return (OOC_IR__Statement)i0;
l12:
  _failed_function(121003); return 0;
  ;
}

void OOC_IR__VisitorDesc_VisitAssignment(OOC_IR__Visitor v, OOC_IR__Assignment assignment) {

  return;
  ;
}

void OOC_IR__AssignmentDesc_Accept(OOC_IR__Assignment assignment, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)assignment;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 122035)))), OOC_IR__VisitorDesc_VisitAssignment)),OOC_IR__VisitorDesc_VisitAssignment)((OOC_IR__Visitor)i0, (OOC_IR__Assignment)i1);
  return;
  ;
}

static void OOC_IR__InitAssignOp(OOC_IR__AssignOp ao, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression op) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)op;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 122277)))), &_td_OOC_IR__BinaryArithDesc);
  if (i1) goto l7;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 122348)))), &_td_OOC_IR__ChangeElementDesc);
  if (i1) goto l5;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 122344)))), 122344);
  goto l8;
l5:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 122400))+12);
  i2 = (OOC_INT32)sym;
  i3 = (OOC_INT32)ao;
  OOC_IR__InitAssignment((OOC_IR__Assignment)i3, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i1, (OOC_IR__Expression)i0);
  goto l8;
l7:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 122327))+12);
  i2 = (OOC_INT32)sym;
  i3 = (OOC_INT32)ao;
  OOC_IR__InitAssignment((OOC_IR__Assignment)i3, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i1, (OOC_IR__Expression)i0);
l8:
  return;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_NewAssignOp(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression op) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)op;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 122562)))), &_td_OOC_IR__ConstDesc);
  if (i1) goto l3;
  i1 = (OOC_INT32)sym;
  i2 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__AssignOp.baseTypes[0]);
  OOC_IR__InitAssignOp((OOC_IR__AssignOp)i2, (OOC_Scanner_SymList__Symbol)i1, (OOC_IR__Expression)i0);
  return (OOC_IR__Expression)i2;
  goto l4;
l3:
  i0 = (OOC_INT32)b;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 122587))+20);
  return (OOC_IR__Expression)i0;
l4:
  _failed_function(122465); return 0;
  ;
}

void OOC_IR__VisitorDesc_VisitAssignOp(OOC_IR__Visitor v, OOC_IR__AssignOp ao) {

  return;
  ;
}

void OOC_IR__AssignOpDesc_Accept(OOC_IR__AssignOp ao, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)ao;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 122895)))), OOC_IR__VisitorDesc_VisitAssignOp)),OOC_IR__VisitorDesc_VisitAssignOp)((OOC_IR__Visitor)i0, (OOC_IR__AssignOp)i1);
  return;
  ;
}

static void OOC_IR__InitCall(OOC_IR__Call call, OOC_IR__Expression design, OOC_IR__ExpressionList arguments, OOC_SymbolTable__VarDeclArray formalPars) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_SymbolTable__Type resultType;

  i0 = (OOC_INT32)design;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 123238));
  i2 = (OOC_INT32)call;
  OOC_IR__InitStatement((OOC_IR__Statement)i2, (OOC_Scanner_SymList__Symbol)i1);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 123303))+4);
  i1 = (OOC_INT32)OOC_SymbolTable_TypeRules__FunctionResultType((OOC_SymbolTable__Type)i1);
  i1 = (OOC_INT32)OOC_SymbolTable__Expand((OOC_SymbolTable__Type)i1);
  resultType = (OOC_SymbolTable__Type)i1;
  i3 = i1!=0;
  if (!i3) goto l4;
  *(OOC_INT32*)((_check_pointer(i2, 123394))+4) = i1;
l4:
  *(OOC_INT32*)((_check_pointer(i2, 123432))+8) = i0;
  i0 = (OOC_INT32)arguments;
  *(OOC_INT32*)((_check_pointer(i2, 123460))+12) = i0;
  i0 = (OOC_INT32)formalPars;
  *(OOC_INT32*)((_check_pointer(i2, 123494))+16) = i0;
  return;
  ;
}

void OOC_IR__VisitorDesc_VisitCall(OOC_IR__Visitor v, OOC_IR__Call call) {

  return;
  ;
}

void OOC_IR__CallDesc_Accept(OOC_IR__Call call, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)call;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 123674)))), OOC_IR__VisitorDesc_VisitCall)),OOC_IR__VisitorDesc_VisitCall)((OOC_IR__Visitor)i0, (OOC_IR__Call)i1);
  return;
  ;
}

static void OOC_IR__InitCopy(OOC_IR__Copy cp, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression source, OOC_IR__Expression dest, OOC_CHAR8 checkDynamicType) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)cp;
  OOC_IR__InitStatement((OOC_IR__Statement)i1, (OOC_Scanner_SymList__Symbol)i0);
  i0 = (OOC_INT32)source;
  *(OOC_INT32*)((_check_pointer(i1, 123973))+8) = i0;
  i0 = (OOC_INT32)dest;
  *(OOC_INT32*)((_check_pointer(i1, 123999))+12) = i0;
  i0 = checkDynamicType;
  *(OOC_UINT8*)((_check_pointer(i1, 124021))+16) = i0;
  return;
  ;
}

OOC_IR__Copy OOC_IR__BuilderDesc_NewCopy(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression source, OOC_IR__Expression dest) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  auto OOC_CHAR8 OOC_IR__BuilderDesc_NewCopy_HasDynamicType(OOC_IR__Expression dest);
    
    OOC_CHAR8 OOC_IR__BuilderDesc_NewCopy_HasDynamicType(OOC_IR__Expression dest) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)dest;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 124289))+4);
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 124296)))), &_td_OOC_SymbolTable__RecordDesc);
      if (i1) goto l3;
      i1=0u;
      goto l5;
l3:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 124317))+4);
      i1 = *(OOC_UINT8*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 124327)))), &_td_OOC_SymbolTable__RecordDesc, 124327)), 124334))+38);
      
l5:
      if (!i1) goto l14;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 124371)))), &_td_OOC_IR__DerefDesc);
      if (i1) goto l12;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 124429)))), &_td_OOC_IR__VarDesc);
      if (!i1) goto l14;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 124464)))), &_td_OOC_IR__VarDesc, 124464)), 124468))+8);
      i0 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 124479)))), &_td_OOC_SymbolTable__VarDeclDesc, 124479)), 124487))+59);
      return i0;
      goto l14;
l12:
      return 1u;
l14:
      return 0u;
      ;
    }


  i0 = (OOC_INT32)dest;
  i1 = OOC_IR__BuilderDesc_NewCopy_HasDynamicType((OOC_IR__Expression)i0);
  if (i1) goto l3;
  i1=0u;
  goto l4;
l3:
  i1 = (OOC_INT32)sym;
  i1 = *(OOC_INT32*)((_check_pointer(i1, 124688))+16);
  i2 = (OOC_INT32)b;
  i3 = (OOC_INT32)OOC_Config_StdPragmas__typeGuard;
  i1 = OOC_IR__GetPragmaValue((OOC_IR__Builder)i2, (Config_Section_Options__Option)i3, i1);
  
l4:
  i2 = (OOC_INT32)source;
  i3 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__Copy.baseTypes[0]);
  i4 = (OOC_INT32)sym;
  OOC_IR__InitCopy((OOC_IR__Copy)i3, (OOC_Scanner_SymList__Symbol)i4, (OOC_IR__Expression)i2, (OOC_IR__Expression)i0, i1);
  return (OOC_IR__Copy)i3;
  ;
}

void OOC_IR__VisitorDesc_VisitCopy(OOC_IR__Visitor v, OOC_IR__Copy cp) {

  return;
  ;
}

void OOC_IR__CopyDesc_Accept(OOC_IR__Copy cp, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)cp;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 124932)))), OOC_IR__VisitorDesc_VisitCopy)),OOC_IR__VisitorDesc_VisitCopy)((OOC_IR__Visitor)i0, (OOC_IR__Copy)i1);
  return;
  ;
}

static void OOC_IR__InitCopyParameter(OOC_IR__CopyParameter cp, OOC_Scanner_SymList__Symbol sym, OOC_IR__Var param) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)cp;
  OOC_IR__InitStatement((OOC_IR__Statement)i1, (OOC_Scanner_SymList__Symbol)i0);
  i0 = (OOC_INT32)param;
  *(OOC_INT32*)((_check_pointer(i1, 125195))+8) = i0;
  return;
  ;
}

OOC_IR__CopyParameter OOC_IR__BuilderDesc_NewCopyParameter(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Var param) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__CopyParameter.baseTypes[0]);
  i1 = (OOC_INT32)param;
  i2 = (OOC_INT32)sym;
  OOC_IR__InitCopyParameter((OOC_IR__CopyParameter)i0, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Var)i1);
  return (OOC_IR__CopyParameter)i0;
  ;
}

void OOC_IR__VisitorDesc_VisitCopyParameter(OOC_IR__Visitor v, OOC_IR__CopyParameter cp) {

  return;
  ;
}

void OOC_IR__CopyParameterDesc_Accept(OOC_IR__CopyParameter cp, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)cp;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 125619)))), OOC_IR__VisitorDesc_VisitCopyParameter)),OOC_IR__VisitorDesc_VisitCopyParameter)((OOC_IR__Visitor)i0, (OOC_IR__CopyParameter)i1);
  return;
  ;
}

static void OOC_IR__InitCopyString(OOC_IR__CopyString cp, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression source, OOC_IR__Expression dest, OOC_IR__Expression maxLength) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)cp;
  OOC_IR__InitStatement((OOC_IR__Statement)i1, (OOC_Scanner_SymList__Symbol)i0);
  i0 = (OOC_INT32)source;
  *(OOC_INT32*)((_check_pointer(i1, 125933))+8) = i0;
  i0 = (OOC_INT32)dest;
  *(OOC_INT32*)((_check_pointer(i1, 125959))+12) = i0;
  i0 = (OOC_INT32)maxLength;
  *(OOC_INT32*)((_check_pointer(i1, 125981))+16) = i0;
  return;
  ;
}

OOC_IR__CopyString OOC_IR__BuilderDesc_NewCopyString(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression source, OOC_IR__Expression dest, OOC_IR__Expression maxLength) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_SymbolTable__Type baseChar;
  OOC_CHAR8 ok;
  OOC_IR__CopyString cp;

  i0 = (OOC_INT32)dest;
  i1 = (OOC_INT32)b;
  OOC_IR__BuilderDesc_AssertVar((OOC_IR__Builder)i1, (OOC_IR__Expression)i0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 126299))+4);
  i2 = OOC_SymbolTable_TypeRules__IsArrayOfChar((OOC_SymbolTable__Type)i2, 1u);
  i2 = !i2;
  if (!i2) goto l3;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 126355));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 126324)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 48, (OOC_Scanner_SymList__Symbol)i2);
l3:
  i2 = (OOC_INT32)source;
  i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 126391)))), &_td_OOC_IR__ConstDesc);
  if (i3) goto l9;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 126861))+4);
  i3 = OOC_SymbolTable_TypeRules__IsArrayOfChar((OOC_SymbolTable__Type)i3, 1u);
  i3 = !i3;
  if (!i3) goto l14;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 126919));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 126886)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 48, (OOC_Scanner_SymList__Symbol)i2);
  goto l14;
l9:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 126648))+4);
  i2 = (OOC_INT32)OOC_SymbolTable_TypeRules__BaseCharType((OOC_SymbolTable__Type)i2);
  baseChar = (OOC_SymbolTable__Type)i2;
  i3 = i2==0;
  if (i3) goto l12;
  i2 = (OOC_INT32)OOC_SymbolTable_TypeRules__MatchingStringConst((OOC_SymbolTable__Type)i2);
  i2 = OOC_IR__BuilderDesc_Widen((OOC_IR__Builder)i1, (void*)(OOC_INT32)&source, (OOC_SymbolTable__Type)i2);
  ok = i2;
  goto l14;
l12:
  i2 = (OOC_INT32)source;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 126730));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 126697)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 48, (OOC_Scanner_SymList__Symbol)i2);
l14:
  i2 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__CopyString.baseTypes[0]);
  cp = (OOC_IR__CopyString)i2;
  i3 = (OOC_INT32)maxLength;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 126998)))), OOC_IR__BuilderDesc_Fold)),OOC_IR__BuilderDesc_Fold)((OOC_IR__Builder)i1, (OOC_IR__Expression)i3);
  i3 = (OOC_INT32)sym;
  i4 = (OOC_INT32)source;
  OOC_IR__InitCopyString((OOC_IR__CopyString)i2, (OOC_Scanner_SymList__Symbol)i3, (OOC_IR__Expression)i4, (OOC_IR__Expression)i0, (OOC_IR__Expression)i1);
  return (OOC_IR__CopyString)i2;
  ;
}

void OOC_IR__VisitorDesc_VisitCopyString(OOC_IR__Visitor v, OOC_IR__CopyString cp) {

  return;
  ;
}

void OOC_IR__CopyStringDesc_Accept(OOC_IR__CopyString cp, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)cp;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 127210)))), OOC_IR__VisitorDesc_VisitCopyString)),OOC_IR__VisitorDesc_VisitCopyString)((OOC_IR__Visitor)i0, (OOC_IR__CopyString)i1);
  return;
  ;
}

void OOC_IR__InitExit(OOC_IR__Exit exit, OOC_Scanner_SymList__Symbol sym) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)exit;
  OOC_IR__InitStatement((OOC_IR__Statement)i1, (OOC_Scanner_SymList__Symbol)i0);
  *(OOC_INT32*)((_check_pointer(i1, 127447))+8) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i1, 127470))+12) = 0;
  return;
  ;
}

OOC_IR__Exit OOC_IR__BuilderDesc_NewExit(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__Exit.baseTypes[0]);
  i1 = (OOC_INT32)sym;
  OOC_IR__InitExit((OOC_IR__Exit)i0, (OOC_Scanner_SymList__Symbol)i1);
  return (OOC_IR__Exit)i0;
  ;
}

void OOC_IR__VisitorDesc_VisitExit(OOC_IR__Visitor v, OOC_IR__Exit exit) {

  return;
  ;
}

void OOC_IR__ExitDesc_Accept(OOC_IR__Exit exit, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)exit;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 127807)))), OOC_IR__VisitorDesc_VisitExit)),OOC_IR__VisitorDesc_VisitExit)((OOC_IR__Visitor)i0, (OOC_IR__Exit)i1);
  return;
  ;
}

static void OOC_IR__InitForStatm(OOC_IR__ForStatm forStatm, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression var, OOC_IR__Expression start, OOC_IR__Expression end, OOC_IR__Expression step, OOC_IR__StatementSeq body) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)forStatm;
  OOC_IR__InitStatement((OOC_IR__Statement)i1, (OOC_Scanner_SymList__Symbol)i0);
  i0 = (OOC_INT32)var;
  *(OOC_INT32*)((_check_pointer(i1, 128166))+8) = i0;
  i0 = (OOC_INT32)start;
  *(OOC_INT32*)((_check_pointer(i1, 128192))+12) = i0;
  i0 = (OOC_INT32)end;
  *(OOC_INT32*)((_check_pointer(i1, 128222))+16) = i0;
  i0 = (OOC_INT32)step;
  *(OOC_INT32*)((_check_pointer(i1, 128248))+20) = i0;
  i0 = (OOC_INT32)body;
  *(OOC_INT32*)((_check_pointer(i1, 128276))+24) = i0;
  return;
  ;
}

OOC_IR__ForStatm OOC_IR__BuilderDesc_NewForStatm(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression var, OOC_IR__Expression start, OOC_IR__Expression end, OOC_IR__Expression step, OOC_IR__StatementSeq body) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;

  i0 = (OOC_INT32)step;
  i0 = i0==(OOC_INT32)0;
  if (!i0) goto l3;
  i0 = (OOC_INT32)Object_BigInt__NewInt(1);
  i1 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(4);
  i2 = (OOC_INT32)b;
  i3 = (OOC_INT32)sym;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 128580)))), OOC_IR__BuilderDesc_NewConst)),OOC_IR__BuilderDesc_NewConst)((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i3, (OOC_SymbolTable__Type)i1, (Object_Boxed__Object)i0);
  step = (OOC_IR__Expression)i0;
l3:
  i0 = (OOC_INT32)var;
  i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 128683)))), &_td_OOC_IR__VarDesc));
  if (i1) goto l21;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 128769))+4);
  i1 = OOC_SymbolTable_TypeRules__IsIntegerType((OOC_SymbolTable__Type)i1);
  i1 = !i1;
  if (i1) goto l19;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 128852))+4);
  i2 = (OOC_INT32)b;
  i1 = OOC_IR__BuilderDesc_Widen((OOC_IR__Builder)i2, (void*)(OOC_INT32)&step, (OOC_SymbolTable__Type)i1);
  i1 = !i1;
  if (i1) goto l17;
  i1 = (OOC_INT32)start;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 128977))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 128960));
  OOC_IR__MakeAssignmentCompatible((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i1, (void*)(OOC_INT32)&start, (OOC_SymbolTable__Type)i3);
  i1 = (OOC_INT32)end;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 129039))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 129024));
  OOC_IR__MakeAssignmentCompatible((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i1, (void*)(OOC_INT32)&end, (OOC_SymbolTable__Type)i3);
  i1 = (OOC_INT32)step;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 129063)))), OOC_IR__BuilderDesc_AssertConst)),OOC_IR__BuilderDesc_AssertConst)((OOC_IR__Builder)i2, (OOC_IR__Expression)i1);
  step = (OOC_IR__Expression)i1;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 129116))+4);
  i3 = OOC_SymbolTable_TypeRules__IsIntegerType((OOC_SymbolTable__Type)i3);
  if (i3) goto l12;
  i3=0u;
  goto l14;
l12:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 129158)))), &_td_OOC_IR__ConstDesc, 129158)), 129164))+8);
  i4 = (OOC_INT32)Object_BigInt__zero;
  i3 = Object_BigInt__BigIntDesc_Cmp((Object_BigInt__BigInt)i4, (Object__Object)i3);
  i3 = i3==0;
  
l14:
  if (!i3) goto l22;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 129218));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 129192)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i2, 31, (OOC_Scanner_SymList__Symbol)i1);
  goto l22;
l17:
  i1 = (OOC_INT32)step;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 128903));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 128872)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i2, 30, (OOC_Scanner_SymList__Symbol)i1);
  goto l22;
l19:
  i1 = (OOC_INT32)b;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 128814));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 128789)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 19, (OOC_Scanner_SymList__Symbol)i2);
  goto l22;
l21:
  i1 = (OOC_INT32)b;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 128729));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 128703)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 29, (OOC_Scanner_SymList__Symbol)i2);
l22:
  i1 = (OOC_INT32)body;
  i2 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__ForStatm.baseTypes[0]);
  i3 = (OOC_INT32)step;
  i4 = (OOC_INT32)end;
  i5 = (OOC_INT32)start;
  i6 = (OOC_INT32)sym;
  OOC_IR__InitForStatm((OOC_IR__ForStatm)i2, (OOC_Scanner_SymList__Symbol)i6, (OOC_IR__Expression)i0, (OOC_IR__Expression)i5, (OOC_IR__Expression)i4, (OOC_IR__Expression)i3, (OOC_IR__StatementSeq)i1);
  return (OOC_IR__ForStatm)i2;
  ;
}

void OOC_IR__VisitorDesc_VisitForStatm(OOC_IR__Visitor v, OOC_IR__ForStatm forStatm) {

  return;
  ;
}

void OOC_IR__ForStatmDesc_Accept(OOC_IR__ForStatm forStatm, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)forStatm;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 129533)))), OOC_IR__VisitorDesc_VisitForStatm)),OOC_IR__VisitorDesc_VisitForStatm)((OOC_IR__Visitor)i0, (OOC_IR__ForStatm)i1);
  return;
  ;
}

OOC_CHAR8 OOC_IR__ForStatmDesc_PositiveStep(OOC_IR__ForStatm forStatm) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)forStatm;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 129660))+20);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 129666)))), &_td_OOC_IR__ConstDesc, 129666)), 129672))+8);
  i0 = Object_BigInt__BigIntDesc_Sign((Object_BigInt__BigInt)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 129686)))), &_td_Object_BigInt__BigIntDesc, 129686)));
  return (i0>=0);
  ;
}

static void OOC_IR__InitIterateArrayStatm(OOC_IR__IterateArrayStatm iterStatm, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression var, OOC_IR__Expression range, OOC_IR__StatementSeq body) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)iterStatm;
  OOC_IR__InitStatement((OOC_IR__Statement)i1, (OOC_Scanner_SymList__Symbol)i0);
  i0 = (OOC_INT32)var;
  *(OOC_INT32*)((_check_pointer(i1, 130091))+8) = i0;
  i0 = (OOC_INT32)range;
  *(OOC_INT32*)((_check_pointer(i1, 130118))+12) = i0;
  i0 = (OOC_INT32)body;
  *(OOC_INT32*)((_check_pointer(i1, 130149))+16) = i0;
  return;
  ;
}

void OOC_IR__VisitorDesc_VisitIterateArrayStatm(OOC_IR__Visitor v, OOC_IR__IterateArrayStatm iterStatm) {

  return;
  ;
}

void OOC_IR__IterateArrayStatmDesc_Accept(OOC_IR__IterateArrayStatm iterStatm, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)iterStatm;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 130392)))), OOC_IR__VisitorDesc_VisitIterateArrayStatm)),OOC_IR__VisitorDesc_VisitIterateArrayStatm)((OOC_IR__Visitor)i0, (OOC_IR__IterateArrayStatm)i1);
  return;
  ;
}

static void OOC_IR__InitIterateObjectStatm(OOC_IR__IterateObjectStatm iterStatm, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression var, OOC_IR__Expression iteratorFactory, OOC_IR__Call stepperCall, OOC_IR__StatementSeq body) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)iterStatm;
  OOC_IR__InitStatement((OOC_IR__Statement)i1, (OOC_Scanner_SymList__Symbol)i0);
  i0 = (OOC_INT32)var;
  *(OOC_INT32*)((_check_pointer(i1, 130840))+8) = i0;
  i0 = (OOC_INT32)iteratorFactory;
  *(OOC_INT32*)((_check_pointer(i1, 130867))+12) = i0;
  i0 = (OOC_INT32)stepperCall;
  *(OOC_INT32*)((_check_pointer(i1, 130918))+16) = i0;
  i0 = (OOC_INT32)body;
  *(OOC_INT32*)((_check_pointer(i1, 130961))+20) = i0;
  return;
  ;
}

void OOC_IR__VisitorDesc_VisitIterateObjectStatm(OOC_IR__Visitor v, OOC_IR__IterateObjectStatm iterStatm) {

  return;
  ;
}

void OOC_IR__IterateObjectStatmDesc_Accept(OOC_IR__IterateObjectStatm iterStatm, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)iterStatm;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 131209)))), OOC_IR__VisitorDesc_VisitIterateObjectStatm)),OOC_IR__VisitorDesc_VisitIterateObjectStatm)((OOC_IR__Visitor)i0, (OOC_IR__IterateObjectStatm)i1);
  return;
  ;
}

OOC_IR__Statement OOC_IR__BuilderDesc_NewIterateStatm(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_SymbolTable__Item context, OOC_IR__Expression var, OOC_IR__Expression sequence, OOC_IR__StatementSeq body) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  Object_BigInt__BigInt v;
  OOC_IR__Expression elem;
  OOC_SymbolTable__ProcDecl stepper;
  OOC_SymbolTable__Type _class;
  OOC_IR__Expression pseudoDesign;
  OOC_IR__ExpressionList arguments;
  OOC_IR__Expression expr;
  auto OOC_SymbolTable__ProcDecl OOC_IR__BuilderDesc_NewIterateStatm_GetStepper(OOC_SymbolTable__Type type, OOC_SymbolTable__Type *_class);
    
    OOC_SymbolTable__ProcDecl OOC_IR__BuilderDesc_NewIterateStatm_GetStepper(OOC_SymbolTable__Type type, OOC_SymbolTable__Type *_class) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_SymbolTable__Record record;
      OOC_SymbolTable__Name n;
      OOC_SymbolTable__Declaration decl;
      OOC_SymbolTable__FormalPars fp;

      i0 = (OOC_INT32)type;
      i1 = OOC_SymbolTable_TypeRules__IsPointer((OOC_SymbolTable__Type)i0);
      if (!i1) goto l4;
      i0 = (OOC_INT32)OOC_SymbolTable_TypeRules__PointerBaseType((OOC_SymbolTable__Type)i0);
      type = (OOC_SymbolTable__Type)i0;
      
l4:
      *_class = (OOC_SymbolTable__Type)i0;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 132051)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
      type = (OOC_SymbolTable__Type)i0;
      i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 132088)))), &_td_OOC_SymbolTable__RecordDesc, 132088);
      record = (OOC_SymbolTable__Record)i0;
      i1 = (OOC_INT32)sequence;
      i2 = (OOC_INT32)b;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 132127));
      i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 132109)))), OOC_IR__BuilderDesc_GetName2)),OOC_IR__BuilderDesc_GetName2)((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i1, "Next", 5);
      n = (OOC_SymbolTable__Name)i1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 132162))+52);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 132162))+52);
      i3 = (OOC_INT32)context;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 132165)))), OOC_SymbolTable__NamespaceDesc_Identify)),OOC_SymbolTable__NamespaceDesc_Identify)((OOC_SymbolTable__Namespace)i0, (OOC_SymbolTable__Item)i3, (OOC_SymbolTable__Name)i1, 0u);
      decl = (OOC_SymbolTable__Declaration)i0;
      i1 = i0!=0;
      if (!i1) goto l21;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 132239)))), &_td_OOC_SymbolTable__ProcDeclDesc);
      if (!i1) goto l21;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 132277))+64);
      fp = (OOC_SymbolTable__FormalPars)i1;
      i2 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(0);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 132306))+44);
      i2 = i3==i2;
      if (i2) goto l11;
      i2=0u;
      goto l13;
l11:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 132374))+52);
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 132381)), 0);
      i2 = i2==1;
      
l13:
      if (i2) goto l15;
      i1=0u;
      goto l17;
l15:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 132406))+52);
      i1 = _check_pointer(i1, 132413);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 132413))*4);
      i1 = *(OOC_UINT8*)((_check_pointer(i1, 132416))+59);
      
l17:
      if (!i1) goto l21;
      return (OOC_SymbolTable__ProcDecl)i0;
l21:
      return (OOC_SymbolTable__ProcDecl)0;
      ;
    }


  i0 = (OOC_INT32)var;
  i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 132584)))), &_td_OOC_IR__VarDesc));
  if (i1) goto l23;
  i1 = (OOC_INT32)sequence;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 132664))+4);
  i2 = OOC_SymbolTable_TypeRules__IsArray((OOC_SymbolTable__Type)i2);
  if (i2) goto l17;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 133375))+4);
  i0 = OOC_SymbolTable_TypeRules__IsRecordPointer((OOC_SymbolTable__Type)i0);
  i0 = !i0;
  if (i0) goto l15;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 133487))+4);
  i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewIterateStatm_GetStepper((OOC_SymbolTable__Type)i0, (void*)(OOC_INT32)&_class);
  stepper = (OOC_SymbolTable__ProcDecl)i0;
  i1 = i0==0;
  if (i1) goto l13;
  i1 = (OOC_INT32)b;
  i2 = (OOC_INT32)sym;
  i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 133622)))), OOC_IR__BuilderDesc_NewNil)),OOC_IR__BuilderDesc_NewNil)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i2);
  pseudoDesign = (OOC_IR__Expression)i3;
  i4 = (OOC_INT32)sequence;
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 133763));
  i6 = (OOC_INT32)_class;
  i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewSelectProc((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i3, (OOC_SymbolTable__Type)i6, (OOC_SymbolTable__ProcDecl)i0, (OOC_Scanner_SymList__Symbol)i5, 0u);
  pseudoDesign = (OOC_IR__Expression)i0;
  i3 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__ExpressionList.baseTypes[0], 1);
  arguments = (OOC_IR__ExpressionList)i3;
  i5 = _check_pointer(i3, 133825);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i7 = (OOC_INT32)var;
  *(OOC_INT32*)(i5+(_check_index(0, i6, OOC_UINT8, 133825))*4) = i7;
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 133941));
  i6 = (OOC_INT32)context;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 133856)))), OOC_IR__BuilderDesc_NewCall)),OOC_IR__BuilderDesc_NewCall)((OOC_IR__Builder)i1, (OOC_IR__Expression)i0, (OOC_IR__ExpressionList)i3, 1u, (OOC_SymbolTable__Item)i6, (OOC_Scanner_SymList__Symbol)i5);
  expr = (OOC_IR__Expression)i0;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 133967)))), &_td_OOC_IR__CallDesc);
  if (i1) goto l11;
  i0=0;
  goto l12;
l11:
  i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 134013)))), &_td_OOC_IR__CallDesc, 134013);
  
l12:
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__IterateObjectStatm.baseTypes[0]);
  i3 = (OOC_INT32)body;
  OOC_IR__InitIterateObjectStatm((OOC_IR__IterateObjectStatm)i1, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i7, (OOC_IR__Expression)i4, (OOC_IR__Call)i0, (OOC_IR__StatementSeq)i3);
  return (OOC_IR__Statement)i1;
  goto l24;
l13:
  i0 = (OOC_INT32)sequence;
  i1 = (OOC_INT32)b;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 133575));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 133545)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 78, (OOC_Scanner_SymList__Symbol)i0);
  goto l24;
l15:
  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 133431));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 133396)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 77, (OOC_Scanner_SymList__Symbol)i1);
  goto l24;
l17:
  sequence = (OOC_IR__Expression)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 132772))+4);
  i2 = OOC_SymbolTable_TypeRules__IsValidArrayIteratorRange((OOC_SymbolTable__Type)i2);
  i2 = !i2;
  if (i2) goto l20;
  i2 = (OOC_INT32)Object_BigInt__NewInt(0);
  v = (Object_BigInt__BigInt)i2;
  i3 = (OOC_INT32)OOC_SymbolTable_Predef__SmallestIntType((Object_BigInt__BigInt)i2);
  i4 = (OOC_INT32)sym;
  i2 = (OOC_INT32)OOC_IR__NewConst((OOC_Scanner_SymList__Symbol)i4, (OOC_SymbolTable__Type)i3, (Object_Boxed__Object)i2);
  i3 = (OOC_INT32)b;
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 132954)))), OOC_IR__BuilderDesc_NewIndex)),OOC_IR__BuilderDesc_NewIndex)((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i4, (OOC_IR__Expression)i1, (OOC_IR__Expression)i2);
  elem = (OOC_IR__Expression)i2;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 133111))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 133096));
  OOC_IR__MakeAssignmentCompatible((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i4, (void*)(OOC_INT32)&elem, (OOC_SymbolTable__Type)i2);
  goto l21;
l20:
  i2 = (OOC_INT32)b;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 132832));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 132793)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i2, 76, (OOC_Scanner_SymList__Symbol)i3);
l21:
  i2 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__IterateArrayStatm.baseTypes[0]);
  i3 = (OOC_INT32)sym;
  i4 = (OOC_INT32)body;
  OOC_IR__InitIterateArrayStatm((OOC_IR__IterateArrayStatm)i2, (OOC_Scanner_SymList__Symbol)i3, (OOC_IR__Expression)i0, (OOC_IR__Expression)i1, (OOC_IR__StatementSeq)i4);
  return (OOC_IR__Statement)i2;
  goto l24;
l23:
  i1 = (OOC_INT32)b;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 132628));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 132604)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 29, (OOC_Scanner_SymList__Symbol)i0);
l24:
  return (OOC_IR__Statement)0;
  ;
}

static void OOC_IR__InitIfStatm(OOC_IR__IfStatm ifStatm, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression guard, OOC_IR__StatementSeq pathTrue, OOC_IR__StatementSeq pathFalse) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)ifStatm;
  OOC_IR__InitStatement((OOC_IR__Statement)i1, (OOC_Scanner_SymList__Symbol)i0);
  i0 = (OOC_INT32)guard;
  *(OOC_INT32*)((_check_pointer(i1, 134650))+8) = i0;
  i0 = (OOC_INT32)pathTrue;
  *(OOC_INT32*)((_check_pointer(i1, 134679))+12) = i0;
  i0 = (OOC_INT32)pathFalse;
  *(OOC_INT32*)((_check_pointer(i1, 134714))+16) = i0;
  return;
  ;
}

OOC_IR__IfStatm OOC_IR__BuilderDesc_NewIfStatm(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression guard, OOC_IR__StatementSeq pathTrue, OOC_IR__StatementSeq pathFalse) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_IR__IfStatm ifStatm;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__IfStatm.baseTypes[0]);
  ifStatm = (OOC_IR__IfStatm)i0;
  i1 = (OOC_INT32)b;
  i2 = (OOC_INT32)guard;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 134996)))), OOC_IR__BuilderDesc_AssertBoolean)),OOC_IR__BuilderDesc_AssertBoolean)((OOC_IR__Builder)i1, (OOC_IR__Expression)i2);
  i2 = (OOC_INT32)sym;
  i3 = (OOC_INT32)pathTrue;
  i4 = (OOC_INT32)pathFalse;
  OOC_IR__InitIfStatm((OOC_IR__IfStatm)i0, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i1, (OOC_IR__StatementSeq)i3, (OOC_IR__StatementSeq)i4);
  return (OOC_IR__IfStatm)i0;
  ;
}

void OOC_IR__VisitorDesc_VisitIfStatm(OOC_IR__Visitor v, OOC_IR__IfStatm ifStatm) {

  return;
  ;
}

void OOC_IR__IfStatmDesc_Accept(OOC_IR__IfStatm ifStatm, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)ifStatm;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 135234)))), OOC_IR__VisitorDesc_VisitIfStatm)),OOC_IR__VisitorDesc_VisitIfStatm)((OOC_IR__Visitor)i0, (OOC_IR__IfStatm)i1);
  return;
  ;
}

static void OOC_IR__InitCase(OOC_IR__Case _case, OOC_Scanner_SymList__Symbol sym, OOC_IR__CaseLabels labels, OOC_IR__StatementSeq statmSeq) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)_case;
  OOC_IR__InitStatement((OOC_IR__Statement)i1, (OOC_Scanner_SymList__Symbol)i0);
  i0 = (OOC_INT32)labels;
  *(OOC_INT32*)((_check_pointer(i1, 135536))+8) = i0;
  i0 = (OOC_INT32)statmSeq;
  *(OOC_INT32*)((_check_pointer(i1, 135564))+12) = i0;
  return;
  ;
}

OOC_IR__Case OOC_IR__BuilderDesc_NewCase(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__CaseLabels labels, OOC_IR__StatementSeq statmSeq) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 i;
  OOC_IR__SetRange range;

  i0 = (OOC_INT32)labels;
  i = 0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 135831)), 0);
  i2 = 0<i1;
  if (!i2) goto l8;
  i2 = (OOC_INT32)b;
  i3=0;
l3_loop:
  i4 = _check_pointer(i0, 135860);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 135860))*4);
  i4 = _type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 135864)))), &_td_OOC_IR__SetRangeDesc, 135864);
  range = (OOC_IR__SetRange)i4;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 135916))+8);
  i5 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 135896)))), OOC_IR__BuilderDesc_AssertConst)),OOC_IR__BuilderDesc_AssertConst)((OOC_IR__Builder)i2, (OOC_IR__Expression)i5);
  *(OOC_INT32*)((_check_pointer(i4, 135886))+8) = i5;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 135964))+12);
  i5 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 135944)))), OOC_IR__BuilderDesc_AssertConst)),OOC_IR__BuilderDesc_AssertConst)((OOC_IR__Builder)i2, (OOC_IR__Expression)i5);
  *(OOC_INT32*)((_check_pointer(i4, 135936))+12) = i5;
  i3 = i3+1;
  i = i3;
  i4 = i3<i1;
  if (i4) goto l3_loop;
l8:
  i1 = (OOC_INT32)sym;
  i2 = (OOC_INT32)statmSeq;
  i3 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__Case.baseTypes[0]);
  OOC_IR__InitCase((OOC_IR__Case)i3, (OOC_Scanner_SymList__Symbol)i1, (OOC_IR__CaseLabels)i0, (OOC_IR__StatementSeq)i2);
  return (OOC_IR__Case)i3;
  ;
}

void OOC_IR__VisitorDesc_VisitCase(OOC_IR__Visitor v, OOC_IR__Case _case) {

  return;
  ;
}

void OOC_IR__CaseDesc_Accept(OOC_IR__Case _case, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)_case;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 136212)))), OOC_IR__VisitorDesc_VisitCase)),OOC_IR__VisitorDesc_VisitCase)((OOC_IR__Visitor)i0, (OOC_IR__Case)i1);
  return;
  ;
}

void OOC_IR__CaseDesc_CheckLabels(OOC_IR__Case _case, OOC_IR__Builder b, OOC_SymbolTable__Type type, OOC_IR__CaseList caseList) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
  OOC_INT32 deleted;
  OOC_INT32 i;
  OOC_IR__SetRange range;
  OOC_CHAR8 inUse;
  OOC_INT32 j;
  OOC_IR__CaseLabels _new;
  auto OOC_CHAR8 OOC_IR__CaseDesc_CheckLabels_IntersectsWith(OOC_IR__SetRange range, OOC_IR__CaseLabels list, OOC_INT32 end);
    
    OOC_CHAR8 OOC_IR__CaseDesc_CheckLabels_IntersectsWith(OOC_IR__SetRange range, OOC_IR__CaseLabels list, OOC_INT32 end) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5;
      OOC_INT32 i;

      i = 0;
      i0 = end;
      i1 = 0!=i0;
      if (!i1) goto l15;
      i1 = (OOC_INT32)list;
      i2 = (OOC_INT32)range;
      i3=0;
l3_loop:
      i4 = _check_pointer(i1, 136670);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 136670))*4);
      i4 = i4!=(OOC_INT32)0;
      if (i4) goto l6;
      i4=0u;
      goto l8;
l6:
      i4 = _check_pointer(i1, 136710);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 136710))*4);
      i4 = OOC_IR__SetRangeDesc_IntersectsWith((OOC_IR__SetRange)i2, (OOC_IR__SetRange)(_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 136714)))), &_td_OOC_IR__SetRangeDesc, 136714)));
      
l8:
      if (!i4) goto l10;
      return 1u;
l10:
      i3 = i3+1;
      i = i3;
      i4 = i3!=i0;
      if (i4) goto l3_loop;
l15:
      return 0u;
      ;
    }


  deleted = 0;
  i0 = (OOC_INT32)_case;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 136894))+8);
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 136902)), 0);
  i = 0;
  i1 = 0<i0;
  if (!i1) goto l44;
  i1 = !0u;
  i2=0;
l3_loop:
  i3 = (OOC_INT32)_case;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 136929))+8);
  i4 = _check_pointer(i4, 136937);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i2, i5, OOC_UINT32, 136937))*4);
  i4 = _type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 136941)))), &_td_OOC_IR__SetRangeDesc, 136941);
  range = (OOC_IR__SetRange)i4;
  i5 = (OOC_INT32)type;
  i6 = (OOC_INT32)b;
  i7 = OOC_IR__BuilderDesc_Widen((OOC_IR__Builder)i6, (void*)((_check_pointer(i4, 136977))+8), (OOC_SymbolTable__Type)i5);
  i7 = !i7;
  if (i7) goto l38;
  i5 = OOC_IR__BuilderDesc_Widen((OOC_IR__Builder)i6, (void*)((_check_pointer(i4, 137156))+12), (OOC_SymbolTable__Type)i5);
  i5 = !i5;
  if (i5) goto l36;
  i4 = OOC_IR__SetRangeDesc_IsEmpty((OOC_IR__SetRange)i4);
  if (i4) goto l34;
  inUse = 0u;
  j = 0;
  i2 = (OOC_INT32)caseList;
  i2 = _check_pointer(i2, 137516);
  i4 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(0, i4, OOC_UINT32, 137516))*4);
  i2 = i2!=i3;
  if (i2) goto l12;
  i2=0u;
  goto l14;
l12:
  i2=i1;
l14:
  if (i2) goto l16;
  i2=0u;
  goto l27;
l16:
  i2=0;
l17_loop:
  i3 = (OOC_INT32)caseList;
  i4 = _check_pointer(i3, 137651);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i2, i5, OOC_UINT32, 137651))*4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 137654))+8);
  i3 = _check_pointer(i3, 137590);
  i5 = OOC_ARRAY_LENGTH(i3, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i5, OOC_UINT32, 137590))*4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 137593))+8);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i4, 137662)), 0);
  i4 = (OOC_INT32)range;
  i2 = OOC_IR__CaseDesc_CheckLabels_IntersectsWith((OOC_IR__SetRange)i4, (OOC_IR__CaseLabels)i2, i3);
  i3 = j;
  inUse = i2;
  i3 = i3+1;
  j = i3;
  i4 = (OOC_INT32)caseList;
  i4 = _check_pointer(i4, 137516);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 137516))*4);
  i5 = (OOC_INT32)_case;
  i4 = i4!=i5;
  if (i4) goto l20;
  i4=0u;
  goto l22;
l20:
  i4 = !i2;
  
l22:
  if (!i4) goto l27;
  i2=i3;
  goto l17_loop;
l27:
  if (i2) goto l29;
  i2 = (OOC_INT32)_case;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 137752))+8);
  i3 = i;
  i4 = (OOC_INT32)range;
  i2 = OOC_IR__CaseDesc_CheckLabels_IntersectsWith((OOC_IR__SetRange)i4, (OOC_IR__CaseLabels)i2, i3);
  
  goto l30;
l29:
  i2=1u;
l30:
  inUse = i2;
  if (!i2) goto l39;
  i2 = (OOC_INT32)range;
  i3 = (OOC_INT32)b;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 137830));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 137799)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i3, 28, (OOC_Scanner_SymList__Symbol)i2);
  goto l39;
l34:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 137407))+8);
  i3 = _check_pointer(i3, 137415);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i5 = deleted;
  *(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 137415))*4) = 0;
  deleted = (i5+1);
  goto l39;
l36:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 137215))+12);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 137219));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 137182)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i6, 27, (OOC_Scanner_SymList__Symbol)i4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 137239))+8);
  i3 = _check_pointer(i3, 137247);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i5 = deleted;
  *(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 137247))*4) = 0;
  deleted = (i5+1);
  goto l39;
l38:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 137038))+8);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 137044));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 137005)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i6, 27, (OOC_Scanner_SymList__Symbol)i4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 137064))+8);
  i3 = _check_pointer(i3, 137072);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i5 = deleted;
  *(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 137072))*4) = 0;
  deleted = (i5+1);
l39:
  i2 = i;
  i2 = i2+1;
  i = i2;
  i3 = i2<i0;
  if (i3) goto l3_loop;
l44:
  i0 = deleted;
  i1 = i0!=0;
  if (!i1) goto l60;
  i1 = (OOC_INT32)_case;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 137923))+8);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 137931)), 0);
  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__CaseLabels.baseTypes[0], (i2-i0));
  _new = (OOC_IR__CaseLabels)i0;
  j = (-1);
  i = 0;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i0, 137987)), 0);
  i3 = 0<i2;
  if (!i3) goto l59;
  i3=(-1);i4=0;
l49_loop:
  
l50_loop:
  i3 = i3+1;
  j = i3;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 138048))+8);
  i5 = _check_pointer(i5, 138056);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 138056))*4);
  i5 = i5!=0;
  if (!i5) goto l50_loop;
l54:
  i5 = _check_pointer(i0, 138079);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 138090))+8);
  i7 = _check_pointer(i7, 138098);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i3, i8, OOC_UINT32, 138098))*4);
  *(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 138079))*4) = i7;
  i4 = i4+1;
  i = i4;
  i5 = i4<i2;
  if (i5) goto l49_loop;
l59:
  *(OOC_INT32*)((_check_pointer(i1, 138124))+8) = i0;
l60:
  return;
  ;
}

static void OOC_IR__InitCaseStatm(OOC_IR__CaseStatm caseStatm, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression select, OOC_IR__CaseList caseList, OOC_IR__StatementSeq _default, OOC_CHAR8 checkMatch) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)caseStatm;
  OOC_IR__InitStatement((OOC_IR__Statement)i1, (OOC_Scanner_SymList__Symbol)i0);
  i0 = (OOC_INT32)select;
  *(OOC_INT32*)((_check_pointer(i1, 138532))+8) = i0;
  i0 = (OOC_INT32)caseList;
  *(OOC_INT32*)((_check_pointer(i1, 138565))+12) = i0;
  i0 = (OOC_INT32)_default;
  *(OOC_INT32*)((_check_pointer(i1, 138602))+16) = i0;
  i0 = checkMatch;
  *(OOC_UINT8*)((_check_pointer(i1, 138637))+20) = i0;
  return;
  ;
}

OOC_IR__CaseStatm OOC_IR__BuilderDesc_NewCaseStatm(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression select, OOC_IR__CaseList caseList, OOC_IR__StatementSeq _default) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
  OOC_IR__CaseStatm caseStatm;
  OOC_INT32 i;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__CaseStatm.baseTypes[0]);
  caseStatm = (OOC_IR__CaseStatm)i0;
  i1 = (OOC_INT32)select;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 138966))+4);
  i2 = OOC_SymbolTable_TypeRules__IsValidCaseSelector((OOC_SymbolTable__Type)i2);
  i2 = !i2;
  if (i2) goto l11;
  i2 = (OOC_INT32)caseList;
  i = 0;
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i2, 139073)), 0);
  i4 = 0<i3;
  if (!i4) goto l12;
  i4 = (OOC_INT32)b;
  i5=0;
l5_loop:
  i6 = _check_pointer(i2, 139097);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 139124))+4);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i5, i7, OOC_UINT32, 139097))*4);
  OOC_IR__CaseDesc_CheckLabels((OOC_IR__Case)i6, (OOC_IR__Builder)i4, (OOC_SymbolTable__Type)i8, (OOC_IR__CaseList)i2);
  i5 = i5+1;
  i = i5;
  i6 = i5<i3;
  if (i6) goto l5_loop;
  goto l12;
l11:
  i2 = (OOC_INT32)b;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 139023));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 138986)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i2, 26, (OOC_Scanner_SymList__Symbol)i3);
l12:
  i2 = (OOC_INT32)sym;
  i3 = *(OOC_INT32*)((_check_pointer(i2, 139294))+16);
  i4 = (OOC_INT32)OOC_Config_StdPragmas__caseSelectCheck;
  i5 = (OOC_INT32)b;
  i3 = OOC_IR__GetPragmaValue((OOC_IR__Builder)i5, (Config_Section_Options__Option)i4, i3);
  i4 = (OOC_INT32)_default;
  i5 = (OOC_INT32)caseList;
  OOC_IR__InitCaseStatm((OOC_IR__CaseStatm)i0, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i1, (OOC_IR__CaseList)i5, (OOC_IR__StatementSeq)i4, i3);
  return (OOC_IR__CaseStatm)i0;
  ;
}

void OOC_IR__VisitorDesc_VisitCaseStatm(OOC_IR__Visitor v, OOC_IR__CaseStatm caseStatm) {

  return;
  ;
}

void OOC_IR__CaseStatmDesc_Accept(OOC_IR__CaseStatm caseStatm, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)caseStatm;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 139510)))), OOC_IR__VisitorDesc_VisitCaseStatm)),OOC_IR__VisitorDesc_VisitCaseStatm)((OOC_IR__Visitor)i0, (OOC_IR__CaseStatm)i1);
  return;
  ;
}

static void OOC_IR__InitLoopStatm(OOC_IR__LoopStatm loopStatm, OOC_Scanner_SymList__Symbol sym, OOC_IR__StatementSeq body) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)loopStatm;
  OOC_IR__InitStatement((OOC_IR__Statement)i1, (OOC_Scanner_SymList__Symbol)i0);
  i0 = (OOC_INT32)body;
  *(OOC_INT32*)((_check_pointer(i1, 139827))+8) = i0;
  return;
  ;
}

OOC_IR__LoopStatm OOC_IR__BuilderDesc_NewLoopStatm(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__StatementSeq body) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__LoopStatm.baseTypes[0]);
  i1 = (OOC_INT32)body;
  i2 = (OOC_INT32)sym;
  OOC_IR__InitLoopStatm((OOC_IR__LoopStatm)i0, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__StatementSeq)i1);
  return (OOC_IR__LoopStatm)i0;
  ;
}

void OOC_IR__VisitorDesc_VisitLoopStatm(OOC_IR__Visitor v, OOC_IR__LoopStatm loopStatm) {

  return;
  ;
}

void OOC_IR__LoopStatmDesc_Accept(OOC_IR__LoopStatm loopStatm, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)loopStatm;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 140295)))), OOC_IR__VisitorDesc_VisitLoopStatm)),OOC_IR__VisitorDesc_VisitLoopStatm)((OOC_IR__Visitor)i0, (OOC_IR__LoopStatm)i1);
  return;
  ;
}

static void OOC_IR__InitMoveBlock(OOC_IR__MoveBlock move, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression source, OOC_IR__Expression dest, OOC_IR__Expression size) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)move;
  OOC_IR__InitStatement((OOC_IR__Statement)i1, (OOC_Scanner_SymList__Symbol)i0);
  i0 = (OOC_INT32)source;
  *(OOC_INT32*)((_check_pointer(i1, 140609))+8) = i0;
  i0 = (OOC_INT32)dest;
  *(OOC_INT32*)((_check_pointer(i1, 140637))+12) = i0;
  i0 = (OOC_INT32)size;
  *(OOC_INT32*)((_check_pointer(i1, 140661))+16) = i0;
  return;
  ;
}

OOC_IR__MoveBlock OOC_IR__BuilderDesc_NewMoveBlock(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression source, OOC_IR__Expression dest, OOC_IR__Expression size) {
  register OOC_INT32 i0,i1,i2,i3,i4;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__MoveBlock.baseTypes[0]);
  i1 = (OOC_INT32)size;
  i2 = (OOC_INT32)b;
  i1 = (OOC_INT32)OOC_IR__BuilderDesc_AssertInteger((OOC_IR__Builder)i2, (OOC_IR__Expression)i1);
  i3 = (OOC_INT32)dest;
  i3 = (OOC_INT32)OOC_IR__BuilderDesc_AssertInteger((OOC_IR__Builder)i2, (OOC_IR__Expression)i3);
  i4 = (OOC_INT32)source;
  i2 = (OOC_INT32)OOC_IR__BuilderDesc_AssertInteger((OOC_IR__Builder)i2, (OOC_IR__Expression)i4);
  i4 = (OOC_INT32)sym;
  OOC_IR__InitMoveBlock((OOC_IR__MoveBlock)i0, (OOC_Scanner_SymList__Symbol)i4, (OOC_IR__Expression)i2, (OOC_IR__Expression)i3, (OOC_IR__Expression)i1);
  return (OOC_IR__MoveBlock)i0;
  ;
}

void OOC_IR__VisitorDesc_VisitMoveBlock(OOC_IR__Visitor v, OOC_IR__MoveBlock move) {

  return;
  ;
}

void OOC_IR__MoveBlockDesc_Accept(OOC_IR__MoveBlock move, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)move;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 141246)))), OOC_IR__VisitorDesc_VisitMoveBlock)),OOC_IR__VisitorDesc_VisitMoveBlock)((OOC_IR__Visitor)i0, (OOC_IR__MoveBlock)i1);
  return;
  ;
}

static void OOC_IR__InitRaise(OOC_IR__Raise raise, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression exception) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)raise;
  OOC_IR__InitStatement((OOC_IR__Statement)i1, (OOC_Scanner_SymList__Symbol)i0);
  i0 = (OOC_INT32)exception;
  *(OOC_INT32*)((_check_pointer(i1, 141512))+8) = i0;
  return;
  ;
}

OOC_IR__Raise OOC_IR__BuilderDesc_NewRaise(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression exception) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)exception;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 141697))+4);
  i1 = OOC_SymbolTable_TypeRules__IsException((OOC_SymbolTable__Type)i1);
  if (i1) goto l3;
  i1 = (OOC_INT32)b;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 141836));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 141805)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 62, (OOC_Scanner_SymList__Symbol)i0);
  return (OOC_IR__Raise)0;
  goto l4;
l3:
  i1 = (OOC_INT32)sym;
  i2 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__Raise.baseTypes[0]);
  OOC_IR__InitRaise((OOC_IR__Raise)i2, (OOC_Scanner_SymList__Symbol)i1, (OOC_IR__Expression)i0);
  return (OOC_IR__Raise)i2;
l4:
  _failed_function(141579); return 0;
  ;
}

void OOC_IR__VisitorDesc_VisitRaise(OOC_IR__Visitor v, OOC_IR__Raise raise) {

  return;
  ;
}

void OOC_IR__RaiseDesc_Accept(OOC_IR__Raise raise, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)raise;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 142028)))), OOC_IR__VisitorDesc_VisitRaise)),OOC_IR__VisitorDesc_VisitRaise)((OOC_IR__Visitor)i0, (OOC_IR__Raise)i1);
  return;
  ;
}

static void OOC_IR__InitRepeatStatm(OOC_IR__RepeatStatm repeatStatm, OOC_Scanner_SymList__Symbol sym, OOC_IR__StatementSeq body, OOC_IR__Expression exitCondition) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)repeatStatm;
  OOC_IR__InitStatement((OOC_IR__Statement)i1, (OOC_Scanner_SymList__Symbol)i0);
  i0 = (OOC_INT32)body;
  *(OOC_INT32*)((_check_pointer(i1, 142378))+8) = i0;
  i0 = (OOC_INT32)exitCondition;
  *(OOC_INT32*)((_check_pointer(i1, 142409))+12) = i0;
  return;
  ;
}

OOC_IR__RepeatStatm OOC_IR__BuilderDesc_NewRepeatStatm(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__StatementSeq body, OOC_IR__Expression exitCondition) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_IR__RepeatStatm repeatStatm;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__RepeatStatm.baseTypes[0]);
  repeatStatm = (OOC_IR__RepeatStatm)i0;
  i1 = (OOC_INT32)b;
  i2 = (OOC_INT32)exitCondition;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 142733)))), OOC_IR__BuilderDesc_AssertBoolean)),OOC_IR__BuilderDesc_AssertBoolean)((OOC_IR__Builder)i1, (OOC_IR__Expression)i2);
  i2 = (OOC_INT32)sym;
  i3 = (OOC_INT32)body;
  OOC_IR__InitRepeatStatm((OOC_IR__RepeatStatm)i0, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__StatementSeq)i3, (OOC_IR__Expression)i1);
  return (OOC_IR__RepeatStatm)i0;
  ;
}

void OOC_IR__VisitorDesc_VisitRepeatStatm(OOC_IR__Visitor v, OOC_IR__RepeatStatm repeatStatm) {

  return;
  ;
}

void OOC_IR__RepeatStatmDesc_Accept(OOC_IR__RepeatStatm repeatStatm, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)repeatStatm;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 142990)))), OOC_IR__VisitorDesc_VisitRepeatStatm)),OOC_IR__VisitorDesc_VisitRepeatStatm)((OOC_IR__Visitor)i0, (OOC_IR__RepeatStatm)i1);
  return;
  ;
}

static void OOC_IR__InitReturn(OOC_IR__Return _return, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression result) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)_return;
  OOC_IR__InitStatement((OOC_IR__Statement)i1, (OOC_Scanner_SymList__Symbol)i0);
  i0 = (OOC_INT32)result;
  *(OOC_INT32*)((_check_pointer(i1, 143268))+8) = i0;
  *(OOC_INT32*)((_check_pointer(i1, 143298))+12) = 0;
  return;
  ;
}

OOC_IR__Return OOC_IR__BuilderDesc_NewReturn(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression result) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__Return.baseTypes[0]);
  i1 = (OOC_INT32)result;
  i2 = (OOC_INT32)sym;
  OOC_IR__InitReturn((OOC_IR__Return)i0, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i1);
  return (OOC_IR__Return)i0;
  ;
}

void OOC_IR__VisitorDesc_VisitReturn(OOC_IR__Visitor v, OOC_IR__Return _return) {

  return;
  ;
}

void OOC_IR__ReturnDesc_Accept(OOC_IR__Return _return, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)_return;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 143695)))), OOC_IR__VisitorDesc_VisitReturn)),OOC_IR__VisitorDesc_VisitReturn)((OOC_IR__Visitor)i0, (OOC_IR__Return)i1);
  return;
  ;
}

static void OOC_IR__InitCatchClause(OOC_IR__CatchClause _catch, OOC_Scanner_SymList__Symbol sym, OOC_SymbolTable__Type exceptionType, OOC_IR__StatementSeq statmSeq) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)_catch;
  OOC_IR__InitStatement((OOC_IR__Statement)i1, (OOC_Scanner_SymList__Symbol)i0);
  i0 = (OOC_INT32)exceptionType;
  *(OOC_INT32*)((_check_pointer(i1, 144051))+8) = i0;
  i0 = (OOC_INT32)statmSeq;
  *(OOC_INT32*)((_check_pointer(i1, 144093))+12) = i0;
  *(OOC_UINT8*)((_check_pointer(i1, 144125))+16) = 0u;
  return;
  ;
}

OOC_IR__CatchClause OOC_IR__BuilderDesc_NewCatchClause(OOC_IR__Builder b, OOC_IR__Expression guardType, OOC_IR__StatementSeq statmSeq) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_IR__CatchClause _catch;
  OOC_SymbolTable__Type type;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__CatchClause.baseTypes[0]);
  _catch = (OOC_IR__CatchClause)i0;
  i1 = (OOC_INT32)b;
  i2 = (OOC_INT32)guardType;
  i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 144396)))), OOC_IR__BuilderDesc_AssertType)),OOC_IR__BuilderDesc_AssertType)((OOC_IR__Builder)i1, (OOC_IR__Expression)i2);
  type = (OOC_SymbolTable__Type)i3;
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 144456));
  i5 = (OOC_INT32)statmSeq;
  OOC_IR__InitCatchClause((OOC_IR__CatchClause)i0, (OOC_Scanner_SymList__Symbol)i4, (OOC_SymbolTable__Type)i3, (OOC_IR__StatementSeq)i5);
  i3 = OOC_SymbolTable_TypeRules__IsException((OOC_SymbolTable__Type)i3);
  i3 = !i3;
  if (!i3) goto l4;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 144551));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 144520)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 62, (OOC_Scanner_SymList__Symbol)i2);
  *(OOC_UINT8*)((_check_pointer(i0, 144569))+16) = 1u;
l4:
  return (OOC_IR__CatchClause)i0;
  ;
}

void OOC_IR__VisitorDesc_VisitCatchClause(OOC_IR__Visitor v, OOC_IR__CatchClause _catch) {

  return;
  ;
}

void OOC_IR__CatchClauseDesc_Accept(OOC_IR__CatchClause _catch, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)_catch;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 144851)))), OOC_IR__VisitorDesc_VisitCatchClause)),OOC_IR__VisitorDesc_VisitCatchClause)((OOC_IR__Visitor)i0, (OOC_IR__CatchClause)i1);
  return;
  ;
}

static void OOC_IR__InitTryStatm(OOC_IR__TryStatm tryStatm, OOC_Scanner_SymList__Symbol sym, OOC_IR__StatementSeq statmSeq, OOC_IR__CatchList catchList) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)tryStatm;
  OOC_IR__InitStatement((OOC_IR__Statement)i1, (OOC_Scanner_SymList__Symbol)i0);
  i0 = (OOC_INT32)statmSeq;
  *(OOC_INT32*)((_check_pointer(i1, 145075))+8) = i0;
  i0 = (OOC_INT32)catchList;
  *(OOC_INT32*)((_check_pointer(i1, 145110))+12) = i0;
  *(OOC_INT32*)((_check_pointer(i1, 145147))+16) = (OOC_INT32)0;
  return;
  ;
}

OOC_IR__TryStatm OOC_IR__BuilderDesc_NewTryStatm(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__StatementSeq statmSeq, OOC_IR__CatchList catchList) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  OOC_INT32 i;
  OOC_INT32 j;

  i0 = (OOC_INT32)catchList;
  i = 0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 145422)), 0);
  i2 = 0<i1;
  if (!i2) goto l28;
  i2 = (OOC_INT32)b;
  i3=0;
l3_loop:
  j = 0;
  i4 = i3!=0;
  if (i4) goto l6;
  i4=0u;
  goto l8;
l6:
  i4 = _check_pointer(i0, 145561);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(0, i5, OOC_UINT32, 145561))*4);
  i5 = _check_pointer(i0, 145493);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 145493))*4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 145564))+8);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 145496))+8);
  i4 = OOC_SymbolTable_TypeRules__IsExtensionOf((OOC_SymbolTable__Type)i5, (OOC_SymbolTable__Type)i4);
  i4 = !i4;
  
l8:
  if (i4) goto l10;
  i4=0;
  goto l20;
l10:
  i4=0;
l11_loop:
  i4 = i4+1;
  j = i4;
  i5 = i3!=i4;
  if (i5) goto l14;
  i5=0u;
  goto l16;
l14:
  i5 = _check_pointer(i0, 145561);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 145561))*4);
  i6 = _check_pointer(i0, 145493);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i3, i7, OOC_UINT32, 145493))*4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 145564))+8);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 145496))+8);
  i5 = OOC_SymbolTable_TypeRules__IsExtensionOf((OOC_SymbolTable__Type)i6, (OOC_SymbolTable__Type)i5);
  i5 = !i5;
  
l16:
  if (i5) goto l11_loop;
l20:
  i4 = i3!=i4;
  if (!i4) goto l23;
  i4 = _check_pointer(i0, 145677);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 145677))*4);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 145680));
  OOC_IR__BuilderDesc_WarnSym((OOC_IR__Builder)i2, 65, (OOC_Scanner_SymList__Symbol)i4);
  i4 = _check_pointer(i0, 145704);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 145704))*4);
  *(OOC_UINT8*)((_check_pointer(i4, 145707))+16) = 1u;
l23:
  i3 = i3+1;
  i = i3;
  i4 = i3<i1;
  if (i4) goto l3_loop;
l28:
  i1 = (OOC_INT32)sym;
  i2 = (OOC_INT32)statmSeq;
  i3 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__TryStatm.baseTypes[0]);
  OOC_IR__InitTryStatm((OOC_IR__TryStatm)i3, (OOC_Scanner_SymList__Symbol)i1, (OOC_IR__StatementSeq)i2, (OOC_IR__CatchList)i0);
  return (OOC_IR__TryStatm)i3;
  ;
}

void OOC_IR__VisitorDesc_VisitTryStatm(OOC_IR__Visitor v, OOC_IR__TryStatm tryStatm) {

  return;
  ;
}

void OOC_IR__TryStatmDesc_Accept(OOC_IR__TryStatm tryStatm, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)tryStatm;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 146055)))), OOC_IR__VisitorDesc_VisitTryStatm)),OOC_IR__VisitorDesc_VisitTryStatm)((OOC_IR__Visitor)i0, (OOC_IR__TryStatm)i1);
  return;
  ;
}

static void OOC_IR__InitWhileStatm(OOC_IR__WhileStatm whileStatm, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression guard, OOC_IR__StatementSeq body) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)whileStatm;
  OOC_IR__InitStatement((OOC_IR__Statement)i1, (OOC_Scanner_SymList__Symbol)i0);
  i0 = (OOC_INT32)guard;
  *(OOC_INT32*)((_check_pointer(i1, 146396))+8) = i0;
  i0 = (OOC_INT32)body;
  *(OOC_INT32*)((_check_pointer(i1, 146428))+12) = i0;
  return;
  ;
}

OOC_IR__WhileStatm OOC_IR__BuilderDesc_NewWhileStatm(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression guard, OOC_IR__StatementSeq body) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_IR__WhileStatm whileStatm;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__WhileStatm.baseTypes[0]);
  whileStatm = (OOC_IR__WhileStatm)i0;
  i1 = (OOC_INT32)b;
  i2 = (OOC_INT32)guard;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 146711)))), OOC_IR__BuilderDesc_AssertBoolean)),OOC_IR__BuilderDesc_AssertBoolean)((OOC_IR__Builder)i1, (OOC_IR__Expression)i2);
  i2 = (OOC_INT32)sym;
  i3 = (OOC_INT32)body;
  OOC_IR__InitWhileStatm((OOC_IR__WhileStatm)i0, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i1, (OOC_IR__StatementSeq)i3);
  return (OOC_IR__WhileStatm)i0;
  ;
}

void OOC_IR__VisitorDesc_VisitWhileStatm(OOC_IR__Visitor v, OOC_IR__WhileStatm whileStatm) {

  return;
  ;
}

void OOC_IR__WhileStatmDesc_Accept(OOC_IR__WhileStatm whileStatm, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)whileStatm;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 146958)))), OOC_IR__VisitorDesc_VisitWhileStatm)),OOC_IR__VisitorDesc_VisitWhileStatm)((OOC_IR__Visitor)i0, (OOC_IR__WhileStatm)i1);
  return;
  ;
}

static void OOC_IR__InitWithStatm(OOC_IR__WithStatm withStatm, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression guard, OOC_IR__StatementSeq pathTrue, OOC_IR__StatementSeq pathFalse, OOC_CHAR8 checkMatch) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)withStatm;
  OOC_IR__InitStatement((OOC_IR__Statement)i1, (OOC_Scanner_SymList__Symbol)i0);
  i0 = (OOC_INT32)guard;
  *(OOC_INT32*)((_check_pointer(i1, 147357))+8) = i0;
  i0 = (OOC_INT32)pathTrue;
  *(OOC_INT32*)((_check_pointer(i1, 147388))+12) = i0;
  i0 = (OOC_INT32)pathFalse;
  *(OOC_INT32*)((_check_pointer(i1, 147425))+16) = i0;
  i0 = checkMatch;
  *(OOC_UINT8*)((_check_pointer(i1, 147464))+20) = i0;
  return;
  ;
}

OOC_IR__WithStatm OOC_IR__BuilderDesc_NewWithStatm(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression guard, OOC_IR__StatementSeq pathTrue, OOC_IR__StatementSeq pathFalse) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;

  i0 = (OOC_INT32)sym;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 147796))+16);
  i2 = (OOC_INT32)b;
  i3 = (OOC_INT32)OOC_Config_StdPragmas__typeGuard;
  i1 = OOC_IR__GetPragmaValue((OOC_IR__Builder)i2, (Config_Section_Options__Option)i3, i1);
  i2 = (OOC_INT32)guard;
  i3 = (OOC_INT32)pathTrue;
  i4 = (OOC_INT32)pathFalse;
  i5 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__WithStatm.baseTypes[0]);
  OOC_IR__InitWithStatm((OOC_IR__WithStatm)i5, (OOC_Scanner_SymList__Symbol)i0, (OOC_IR__Expression)i2, (OOC_IR__StatementSeq)i3, (OOC_IR__StatementSeq)i4, i1);
  return (OOC_IR__WithStatm)i5;
  ;
}

void OOC_IR__VisitorDesc_VisitWithStatm(OOC_IR__Visitor v, OOC_IR__WithStatm withStatm) {

  return;
  ;
}

void OOC_IR__WithStatmDesc_Accept(OOC_IR__WithStatm withStatm, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)withStatm;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 148113)))), OOC_IR__VisitorDesc_VisitWithStatm)),OOC_IR__VisitorDesc_VisitWithStatm)((OOC_IR__Visitor)i0, (OOC_IR__WithStatm)i1);
  return;
  ;
}

void OOC_IR__BuilderDesc_CheckExit(OOC_IR__Builder b, OOC_SymbolTable__ProcDecl procDecl, OOC_IR__StatementSeq statmSeq) {
  register OOC_INT32 i0,i1,i2;
  OOC_IR__LoopStatm currentLoop;
  OOC_IR__TryStatm currentTry;
  OOC_INT32 enclosingTry;
  OOC_INT32 enclosingTryLastLoop;
  OOC_CHAR8 initWithoutSuper;
  OOC_SymbolTable__Record procClass;
  auto void OOC_IR__BuilderDesc_CheckExit_CheckException(OOC_SymbolTable__Type exception, OOC_Scanner_SymList__Symbol sym);
  auto void OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq(OOC_IR__StatementSeq statmSeq);
    
    void OOC_IR__BuilderDesc_CheckExit_CheckException(OOC_SymbolTable__Type exception, OOC_Scanner_SymList__Symbol sym) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5;
      OOC_IR__TryStatm _try;
      OOC_INT32 i;
      OOC_SymbolTable__ExceptionNameArray raises;
      OOC_SymbolTable__Module module;

      i0 = (OOC_INT32)exception;
      i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 149119)))), OOC_SymbolTable__TypeDesc_IsCheckedException)),OOC_SymbolTable__TypeDesc_IsCheckedException)((OOC_SymbolTable__Type)i0);
      if (!i1) goto l47;
      i1 = (OOC_INT32)currentTry;
      _try = (OOC_IR__TryStatm)i1;
      i2 = i1!=(OOC_INT32)0;
      if (!i2) goto l24;
l5_loop:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 149331))+12);
      i = 0;
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 149341)), 0);
      i3 = 0<i2;
      if (!i3) goto l19;
      i3=0;
l8_loop:
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 149384))+12);
      i4 = _check_pointer(i4, 149394);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 149394))*4);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 149397))+8);
      i4 = OOC_SymbolTable_TypeRules__IsExtensionOf((OOC_SymbolTable__Type)i4, (OOC_SymbolTable__Type)i0);
      if (!i4) goto l11;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 149478))+12);
      i4 = _check_pointer(i4, 149488);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 149488))*4);
      *(OOC_UINT8*)((_check_pointer(i4, 149491))+16) = 1u;
l11:
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 149606))+12);
      i4 = _check_pointer(i4, 149616);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 149616))*4);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 149619))+8);
      i4 = OOC_SymbolTable_TypeRules__IsExtensionOf((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i4);
      if (!i4) goto l14;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 149657))+12);
      i4 = _check_pointer(i4, 149667);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 149667))*4);
      *(OOC_UINT8*)((_check_pointer(i4, 149670))+16) = 1u;
      return;
l14:
      i3 = i3+1;
      i = i3;
      i4 = i3<i2;
      if (i4) goto l8_loop;
l19:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 149764))+16);
      _try = (OOC_IR__TryStatm)i1;
      i2 = i1!=(OOC_INT32)0;
      if (i2) goto l5_loop;
l24:
      i1 = (OOC_INT32)procDecl;
      i2 = i1!=(OOC_INT32)0;
      if (!i2) goto l38;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 149862))+64);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 149873))+60);
      raises = (OOC_SymbolTable__ExceptionNameArray)i1;
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i1, 149916)), 0);
      i = 0;
      i3 = 0<i2;
      if (!i3) goto l38;
      i3=0;
l29_loop:
      i4 = _check_pointer(i1, 149973);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 149973))*4);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 149976))+20);
      i4 = OOC_SymbolTable_TypeRules__IsExtensionOf((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i4);
      if (!i4) goto l32;
      return;
l32:
      i3 = i3+1;
      i = i3;
      i4 = i3<i2;
      if (i4) goto l29_loop;
l38:
      i1 = (OOC_INT32)procDecl;
      i2 = i1==(OOC_INT32)0;
      if (i2) goto l41;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 150115))+4);
      i1 = i1==(OOC_INT32)0;
      
      goto l43;
l41:
      i1=1u;
l43:
      if (i1) goto l45;
      i1 = (OOC_INT32)b;
      i2 = (OOC_INT32)sym;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 150232)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 63, (OOC_Scanner_SymList__Symbol)i2);
      goto l46;
l45:
      i1 = (OOC_INT32)sym;
      i2 = (OOC_INT32)b;
      OOC_IR__BuilderDesc_WarnSym((OOC_IR__Builder)i2, 64, (OOC_Scanner_SymList__Symbol)i1);
l46:
      i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 150306)))), OOC_SymbolTable__ItemDesc_Module)),OOC_SymbolTable__ItemDesc_Module)((OOC_SymbolTable__Item)i0);
      module = (OOC_SymbolTable__Module)i1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 150422))+20);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 150427))+12);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 150422))+20);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 150427))+12);
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 150431)), 0);
      i1 = (OOC_INT32)Msg__GetStringPtr((void*)(_check_pointer(i1, 150431)), i2);
      i2 = (OOC_INT32)b;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 150326))+36);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 150326))+36);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 150336)))), Msg__MsgDesc_SetStringAttrib)),Msg__MsgDesc_SetStringAttrib)((Msg__Msg)i2, "module", 7, (Msg__StringPtr)i1);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 150542))+24);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 150553))+20);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 150558))+12);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 150542))+24);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 150553))+20);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 150558))+12);
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 150562)), 0);
      i0 = (OOC_INT32)Msg__GetStringPtr((void*)(_check_pointer(i0, 150562)), i1);
      i1 = (OOC_INT32)b;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 150445))+36);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 150445))+36);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 150455)))), Msg__MsgDesc_SetStringAttrib)),Msg__MsgDesc_SetStringAttrib)((Msg__Msg)i1, "name", 5, (Msg__StringPtr)i0);
l47:
      return;
      ;
    }

    
    void OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq(OOC_IR__StatementSeq statmSeq) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_INT32 i;
      auto void OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckStatm(OOC_IR__Statement statm);
      auto void OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr(OOC_IR__Expression expr);
      auto void OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckStatm(OOC_IR__Statement statm);
        
        void OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr(OOC_IR__Expression expr) {
          register OOC_INT32 i0,i1,i2,i3,i4;
          OOC_INT32 i;

          i0 = (OOC_INT32)expr;
          i1 = i0==(OOC_INT32)0;
          if (!i1) goto l3;
          return;
l3:
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 150910)))), &_td_OOC_IR__ConstDesc);
          if (i1) goto l156;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 150959)))), &_td_OOC_IR__AbsDesc);
          if (i1) goto l154;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 151017)))), &_td_OOC_IR__AdrDesc);
          if (i1) goto l152;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 151074)))), &_td_OOC_IR__AshDesc);
          if (i1) goto l150;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 151161)))), &_td_OOC_IR__BinaryArithDesc);
          if (i1) goto l148;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 151257)))), &_td_OOC_IR__BooleanOpDesc);
          if (i1) goto l146;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 151351)))), &_td_OOC_IR__CapDesc);
          if (i1) goto l144;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 151409)))), &_td_OOC_IR__CompareDesc);
          if (i1) goto l142;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 151501)))), &_td_OOC_IR__ConcatDesc);
          if (i1) goto l132;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 151630)))), &_td_OOC_IR__ConstructorDesc);
          if (i1) goto l130;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 151726)))), &_td_OOC_IR__CurrentExceptionDesc);
          if (i1) goto l128;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 151796)))), &_td_OOC_IR__ChangeElementDesc);
          if (i1) goto l126;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 151895)))), &_td_OOC_IR__DerefDesc);
          if (i1) goto l124;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 151955)))), &_td_OOC_IR__EntierDesc);
          if (i1) goto l122;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 152016)))), &_td_OOC_IR__IndexDesc);
          if (i1) goto l120;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 152107)))), &_td_OOC_IR__LenDesc);
          if (i1) goto l118;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 152163)))), &_td_OOC_IR__NegateDesc);
          if (i1) goto l116;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 152224)))), &_td_OOC_IR__NewBlockDesc);
          if (i1) goto l114;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 152284)))), &_td_OOC_IR__NewObjectDesc);
          if (i1) goto l101;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 152473)))), &_td_OOC_IR__NotDesc);
          if (i1) goto l99;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 152531)))), &_td_OOC_IR__OddDesc);
          if (i1) goto l97;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 152589)))), &_td_OOC_IR__ReferenceDesc);
          if (i1) goto l156;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 152642)))), &_td_OOC_IR__SelectFieldDesc);
          if (i1) goto l94;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 152707)))), &_td_OOC_IR__SelectProcDesc);
          if (i1) goto l92;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 152773)))), &_td_OOC_IR__SetMemberDesc);
          if (i1) goto l90;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 152868)))), &_td_OOC_IR__SetOpDesc);
          if (i1) goto l88;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 152958)))), &_td_OOC_IR__SetRangeDesc);
          if (i1) goto l86;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 153048)))), &_td_OOC_IR__ShiftDesc);
          if (i1) goto l84;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 153136)))), &_td_OOC_IR__TypeCastDesc);
          if (i1) goto l82;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 153196)))), &_td_OOC_IR__TypeConvDesc);
          if (i1) goto l80;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 153256)))), &_td_OOC_IR__TypeTagDesc);
          if (i1) goto l78;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 153317)))), &_td_OOC_IR__TypeTestDesc);
          if (i1) goto l76;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 153377)))), &_td_OOC_IR__TypeGuardDesc);
          if (i1) goto l74;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 153449)))), &_td_OOC_IR__CallDesc);
          if (i1) goto l72;
          _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 153443)))), 153443);
          goto l156;
l72:
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckStatm((OOC_IR__Statement)i0);
          goto l156;
l74:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 153416))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l76:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 153355))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l78:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 153293))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l80:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 153234))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l82:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 153174))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l84:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 153083))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 153116))+12);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l86:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 152996))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 153028))+12);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l88:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 152903))+12);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 152935))+16);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l90:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 152812))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 152847))+12);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l92:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 152747))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l94:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 152683))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l97:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 152564))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l99:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 152506))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l101:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 152317))+8);
          i1 = i1!=(OOC_INT32)0;
          if (!i1) goto l156;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 152371))+8);
          i = 0;
          i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 152378)), 0);
          i2 = 0<i1;
          if (!i2) goto l156;
          i2=0;
l106_loop:
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 152414))+8);
          i3 = _check_pointer(i3, 152421);
          i4 = OOC_ARRAY_LENGTH(i3, 0);
          i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 152421))*4);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i3);
          i2 = i2+1;
          i = i2;
          i3 = i2<i1;
          if (i3) goto l106_loop;
          goto l156;
l114:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 152262))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l116:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 152199))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l118:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 152140))+12);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l120:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 152051))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 152084))+12);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l122:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 151991))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l124:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 151930))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l126:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 151839))+12);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 151870))+16);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l128:
          i1 = (OOC_INT32)currentTry;
          *(OOC_INT32*)((_check_pointer(i0, 151762))+8) = i1;
          goto l156;
l130:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 151671))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 151704))+12);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l132:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 151545))+8);
          i = 0;
          i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 151553)), 0);
          i2 = 0<i1;
          if (!i2) goto l156;
          i2=0;
l135_loop:
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 151587))+8);
          i3 = _check_pointer(i3, 151595);
          i4 = OOC_ARRAY_LENGTH(i3, 0);
          i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 151595))*4);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i3);
          i2 = i2+1;
          i = i2;
          i3 = i2<i1;
          if (i3) goto l135_loop;
          goto l156;
l142:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 151446))+12);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 151478))+16);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l144:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 151384))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l146:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 151296))+12);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 151328))+16);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l148:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 151202))+12);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 151234))+16);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l150:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 151107))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 151140))+12);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l152:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 151050))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l154:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 150992))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
l156:
          return;
          ;
        }

        
        void OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckStatm(OOC_IR__Statement statm) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5;
          OOC_INT32 i;
          OOC_SymbolTable__Type type;
          OOC_SymbolTable__FormalPars fpars;
          OOC_IR__LoopStatm oldLoop;
          OOC_INT32 oldEnclTryLastLoop;
          auto OOC_CHAR8 OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckStatm_IsInitSuper(OOC_IR__Expression design);
            
            OOC_CHAR8 OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckStatm_IsInitSuper(OOC_IR__Expression design) {
              register OOC_INT32 i0,i1,i2;

              i0 = (OOC_INT32)design;
              i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 153815)))), &_td_OOC_IR__SelectProcDesc);
              if (i1) goto l3;
              return 0u;
              goto l16;
l3:
              i1 = *(OOC_UINT8*)((_check_pointer(i0, 153853))+29);
              i1 = !i1;
              if (i1) goto l6;
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 153892))+8);
              i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 153902)))), &_td_OOC_IR__VarDesc));
              
              goto l8;
l6:
              i1=1u;
l8:
              if (i1) goto l10;
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 153935))+8);
              i2 = (OOC_INT32)procDecl;
              i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 153965))+64);
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 153945)))), &_td_OOC_IR__VarDesc, 153945)), 153949))+8);
              i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 153976))+40);
              i1 = i1!=i2;
              
              goto l12;
l10:
              i1=1u;
l12:
              if (i1) goto l14;
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 154128))+20);
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 154135))+20);
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 154140))+12);
              return ((
              _cmp8((const void*)(_check_pointer(i0, 154144)),(const void*)"INIT"))==0);
              goto l16;
l14:
              return 0u;
l16:
              _failed_function(153738); return 0;
              ;
            }


          i0 = (OOC_INT32)statm;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 154303)))), &_td_OOC_IR__AssertDesc);
          if (i1) goto l147;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 154368)))), &_td_OOC_IR__AssignmentDesc);
          if (i1) goto l145;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 154510)))), &_td_OOC_IR__CallDesc);
          if (i1) goto l120;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 155021)))), &_td_OOC_IR__CopyDesc);
          if (i1) goto l118;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 155114)))), &_td_OOC_IR__CopyParameterDesc);
          if (i1) goto l148;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 155172)))), &_td_OOC_IR__CopyStringDesc);
          if (i1) goto l115;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 155271)))), &_td_OOC_IR__ExitDesc);
          if (i1) goto l109;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 155532)))), &_td_OOC_IR__ForStatmDesc);
          if (i1) goto l107;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 155731)))), &_td_OOC_IR__IterateArrayStatmDesc);
          if (i1) goto l105;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 155874)))), &_td_OOC_IR__IterateObjectStatmDesc);
          if (i1) goto l103;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 156068)))), &_td_OOC_IR__IfStatmDesc);
          if (i1) goto l101;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 156217)))), &_td_OOC_IR__CaseDesc);
          if (i1) goto l99;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 156285)))), &_td_OOC_IR__CaseStatmDesc);
          if (i1) goto l89;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 156517)))), &_td_OOC_IR__LoopStatmDesc);
          if (i1) goto l87;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 156842)))), &_td_OOC_IR__MoveBlockDesc);
          if (i1) goto l85;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 156940)))), &_td_OOC_IR__RaiseDesc);
          if (i1) goto l83;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 157063)))), &_td_OOC_IR__RepeatStatmDesc);
          if (i1) goto l81;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 157176)))), &_td_OOC_IR__ReturnDesc);
          if (i1) goto l64;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 157928)))), &_td_OOC_IR__TryStatmDesc);
          if (i1) goto l47;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 158542)))), &_td_OOC_IR__WhileStatmDesc);
          if (i1) goto l45;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 158646)))), &_td_OOC_IR__WithStatmDesc);
          if (i1) goto l43;
          _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 158639)))), 158639);
          goto l148;
l43:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 158686))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 158725))+12);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq((OOC_IR__StatementSeq)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 158768))+16);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq((OOC_IR__StatementSeq)i0);
          goto l148;
l45:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 158583))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 158622))+12);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq((OOC_IR__StatementSeq)i0);
          goto l148;
l47:
          i1 = (OOC_INT32)procDecl;
          i2 = enclosingTry;
          *(OOC_UINT8*)((_check_pointer(i1, 157960))+76) = 1u;
          enclosingTry = (i2+1);
          i1 = (OOC_INT32)currentTry;
          *(OOC_INT32*)((_check_pointer(i0, 158026))+16) = i1;
          currentTry = (OOC_IR__TryStatm)i0;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 158115))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq((OOC_IR__StatementSeq)i1);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 158156))+16);
          i2 = enclosingTry;
          currentTry = (OOC_IR__TryStatm)i1;
          enclosingTry = (i2-1);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 158233))+12);
          i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 158243)), 0);
          i = 0;
          i2 = 0<i1;
          if (!i2) goto l148;
          i2=0;
l50_loop:
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 158271))+12);
          i3 = _check_pointer(i3, 158281);
          i4 = OOC_ARRAY_LENGTH(i3, 0);
          i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 158281))*4);
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 158271))+12);
          i4 = _check_pointer(i4, 158281);
          i5 = OOC_ARRAY_LENGTH(i4, 0);
          i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i2, i5, OOC_UINT32, 158281))*4);
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 158284))+8);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 158284))+8);
          i3 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 158298)))), OOC_SymbolTable__TypeDesc_IsCheckedException)),OOC_SymbolTable__TypeDesc_IsCheckedException)((OOC_SymbolTable__Type)i3);
          if (i3) goto l53;
          i3=0u;
          goto l55;
l53:
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 158343))+12);
          i3 = _check_pointer(i3, 158353);
          i4 = OOC_ARRAY_LENGTH(i3, 0);
          i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 158353))*4);
          i3 = *(OOC_UINT8*)((_check_pointer(i3, 158356))+16);
          i3 = !i3;
          
l55:
          if (!i3) goto l57;
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 158419))+12);
          i3 = _check_pointer(i3, 158429);
          i4 = OOC_ARRAY_LENGTH(i3, 0);
          i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 158429))*4);
          i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 158432));
          i4 = (OOC_INT32)b;
          OOC_IR__BuilderDesc_WarnSym((OOC_IR__Builder)i4, 66, (OOC_Scanner_SymList__Symbol)i3);
l57:
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 158487))+12);
          i3 = _check_pointer(i3, 158497);
          i4 = OOC_ARRAY_LENGTH(i3, 0);
          i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 158497))*4);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 158500))+12);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq((OOC_IR__StatementSeq)i3);
          i2 = i2+1;
          i = i2;
          i3 = i2<i1;
          if (i3) goto l50_loop;
          goto l148;
l64:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 157213))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i1 = (OOC_INT32)procDecl;
          i2 = i1==0;
          if (i2) goto l67;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 157278))+64);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 157290))+44);
          i2 = i2==0;
          
          goto l69;
l67:
          i2=1u;
l69:
          if (i2) goto l75;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 157567))+8);
          i2 = i2==0;
          if (i2) goto l73;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 157801))+64);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 157812))+44);
          i1 = (OOC_INT32)OOC_SymbolTable__Expand((OOC_SymbolTable__Type)i1);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 157712))+8);
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 157720));
          i3 = (OOC_INT32)b;
          OOC_IR__MakeAssignmentCompatible((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i2, (void*)((_check_pointer(i0, 157732))+8), (OOC_SymbolTable__Type)i1);
          goto l79;
l73:
          i1 = (OOC_INT32)b;
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 157639));
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 157603)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 33, (OOC_Scanner_SymList__Symbol)i2);
          goto l79;
l75:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 157392))+8);
          i1 = i1!=0;
          if (!i1) goto l79;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 157461))+8);
          i2 = (OOC_INT32)b;
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 157469));
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 157428)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i2, 32, (OOC_Scanner_SymList__Symbol)i1);
l79:
          i1 = enclosingTry;
          *(OOC_INT32*)((_check_pointer(i0, 157874))+12) = i1;
          goto l148;
l81:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 157110))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq((OOC_IR__StatementSeq)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 157144))+12);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l148;
l83:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 156976))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 157019))+8);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 157029))+4);
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 157041));
          OOC_IR__BuilderDesc_CheckExit_CheckException((OOC_SymbolTable__Type)i1, (OOC_Scanner_SymList__Symbol)i0);
          goto l148;
l85:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 156882))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 156917))+12);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l148;
l87:
          i1 = (OOC_INT32)currentLoop;
          oldLoop = (OOC_IR__LoopStatm)i1;
          currentLoop = (OOC_IR__LoopStatm)i0;
          i2 = enclosingTryLastLoop;
          oldEnclTryLastLoop = i2;
          i3 = enclosingTry;
          enclosingTryLastLoop = i3;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 156730))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq((OOC_IR__StatementSeq)i0);
          enclosingTryLastLoop = i2;
          currentLoop = (OOC_IR__LoopStatm)i1;
          goto l148;
l89:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 156325))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 156369))+12);
          i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 156379)), 0);
          i = 0;
          i2 = 0<i1;
          if (!i2) goto l97;
          i2=0;
l92_loop:
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 156419))+12);
          i3 = _check_pointer(i3, 156429);
          i4 = OOC_ARRAY_LENGTH(i3, 0);
          i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 156429))*4);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 156432))+12);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq((OOC_IR__StatementSeq)i3);
          i2 = i2+1;
          i = i2;
          i3 = i2<i1;
          if (i3) goto l92_loop;
l97:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 156490))+16);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq((OOC_IR__StatementSeq)i0);
          goto l148;
l99:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 156257))+12);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq((OOC_IR__StatementSeq)i0);
          goto l148;
l101:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 156106))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 156145))+12);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq((OOC_IR__StatementSeq)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 156188))+16);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq((OOC_IR__StatementSeq)i0);
          goto l148;
l103:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 155923))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 155955))+12);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 155999))+16);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 156044))+20);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq((OOC_IR__StatementSeq)i0);
          goto l148;
l105:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 155779))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 155811))+12);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 155850))+16);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq((OOC_IR__StatementSeq)i0);
          goto l148;
l107:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 155571))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 155603))+12);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 155637))+16);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 155669))+20);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 155707))+24);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq((OOC_IR__StatementSeq)i0);
          goto l148;
l109:
          i1 = (OOC_INT32)currentLoop;
          i2 = i1==0;
          if (i2) goto l112;
          *(OOC_INT32*)((_check_pointer(i0, 155404))+8) = i1;
          goto l113;
l112:
          i1 = (OOC_INT32)b;
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 155364));
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 155332)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 25, (OOC_Scanner_SymList__Symbol)i2);
l113:
          i1 = enclosingTry;
          i2 = enclosingTryLastLoop;
          *(OOC_INT32*)((_check_pointer(i0, 155457))+12) = (i1-i2);
          goto l148;
l115:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 155213))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 155248))+12);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l148;
l118:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 155056))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 155091))+12);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l148;
l120:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 154545))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i1 = initWithoutSuper;
          if (i1) goto l123;
          i1=0u;
          goto l125;
l123:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 154605))+8);
          i1 = OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckStatm_IsInitSuper((OOC_IR__Expression)i1);
          
l125:
          if (!i1) goto l127;
          initWithoutSuper = 0u;
l127:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 154717))+12);
          i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 154727)), 0);
          i = 0;
          i2 = 0<i1;
          if (!i2) goto l135;
          i2=0;
l130_loop:
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 154762))+12);
          i3 = _check_pointer(i3, 154772);
          i4 = OOC_ARRAY_LENGTH(i3, 0);
          i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 154772))*4);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i3);
          i2 = i2+1;
          i = i2;
          i3 = i2<i1;
          if (i3) goto l130_loop;
l135:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 154817))+8);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 154817))+8);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 154824))+4);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 154824))+4);
          i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 154829)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i1);
          type = (OOC_SymbolTable__Type)i1;
          i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 154869)))), &_td_OOC_SymbolTable__FormalParsDesc, 154869);
          fpars = (OOC_SymbolTable__FormalPars)i1;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 154915))+60);
          i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 154922)), 0);
          i = 0;
          i3 = 0<i2;
          if (!i3) goto l148;
          i3=0;
l138_loop:
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 154962))+60);
          i4 = _check_pointer(i4, 154969);
          i5 = OOC_ARRAY_LENGTH(i4, 0);
          i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 154969))*4);
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 154972))+20);
          i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 154984));
          OOC_IR__BuilderDesc_CheckExit_CheckException((OOC_SymbolTable__Type)i4, (OOC_Scanner_SymList__Symbol)i5);
          i3 = i3+1;
          i = i3;
          i4 = i3<i2;
          if (i4) goto l138_loop;
          goto l148;
l145:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 154450))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 154487))+12);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l148;
l147:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 154340))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
l148:
          return;
          ;
        }


      i0 = (OOC_INT32)statmSeq;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l11;
      i = 0;
      i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 158898)), 0);
      i1 = 0<i0;
      if (!i1) goto l11;
      i1=0;
l5_loop:
      i2 = (OOC_INT32)statmSeq;
      i2 = _check_pointer(i2, 158936);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i1 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i1, i3, OOC_UINT32, 158936))*4);
      OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckStatm((OOC_IR__Statement)i1);
      i1 = i;
      i1 = i1+1;
      i = i1;
      i2 = i1<i0;
      if (i2) goto l5_loop;
l11:
      return;
      ;
    }


  currentLoop = (OOC_IR__LoopStatm)(OOC_INT32)0;
  currentTry = (OOC_IR__TryStatm)(OOC_INT32)0;
  enclosingTry = 0;
  enclosingTryLastLoop = 0;
  initWithoutSuper = 0u;
  i0 = (OOC_INT32)procDecl;
  i1 = (OOC_INT32)OOC_SymbolTable__ProcDeclDesc_Class((OOC_SymbolTable__ProcDecl)i0);
  procClass = (OOC_SymbolTable__Record)i1;
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 159205)))), OOC_SymbolTable__ItemDesc_InStandardModule)),OOC_SymbolTable__ItemDesc_InStandardModule)((OOC_SymbolTable__Item)i0);
  if (i2) goto l3;
  i2=0u;
  goto l5;
l3:
  i2 = i1!=(OOC_INT32)0;
  
l5:
  if (i2) goto l7;
  i2=0u;
  goto l9;
l7:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 159265))+40);
  i2 = i2!=(OOC_INT32)0;
  
l9:
  if (i2) goto l11;
  i2=0u;
  goto l13;
l11:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 159302))+40);
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 159312)))), &_td_OOC_SymbolTable__RecordDesc);
  
l13:
  if (i2) goto l15;
  i2=0u;
  goto l17;
l15:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 159346))+20);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 159351))+12);
  i2 = (
  _cmp8((const void*)(_check_pointer(i2, 159355)),(const void*)"INIT"))==0;
  
l17:
  if (i2) goto l19;
  i0=0u;
  goto l20;
l19:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 159421))+40);
  i0 = *(OOC_INT32*)((_check_pointer(i0, 159397))+56);
  i1 = *(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 159435)))), &_td_OOC_SymbolTable__RecordDesc, 159435)), 159442))+48);
  i0 = i0<i1;
  
l20:
  initWithoutSuper = i0;
  i0 = (OOC_INT32)statmSeq;
  OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq((OOC_IR__StatementSeq)i0);
  i0 = initWithoutSuper;
  if (!i0) goto l23;
  i0 = (OOC_INT32)procDecl;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 159569))+20);
  i1 = (OOC_INT32)b;
  OOC_IR__BuilderDesc_WarnName((OOC_IR__Builder)i1, 74, (OOC_SymbolTable__Name)i0);
l23:
  return;
  ;
}

void OOC_IR__InitProcedure(OOC_IR__Procedure p, OOC_Scanner_SymList__Symbol sym, OOC_SymbolTable__ProcDecl decl, OOC_IR__StatementSeq statmSeq, OOC_Scanner_SymList__Symbol endOfProc, OOC_CHAR8 checkFunctionResult) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)p;
  OOC_IR__InitNode((OOC_IR__Node)i1, (OOC_Scanner_SymList__Symbol)i0);
  i0 = (OOC_INT32)decl;
  *(OOC_INT32*)((_check_pointer(i1, 159866))+4) = i0;
  i0 = (OOC_INT32)statmSeq;
  *(OOC_INT32*)((_check_pointer(i1, 159887))+8) = i0;
  i0 = (OOC_INT32)endOfProc;
  *(OOC_INT32*)((_check_pointer(i1, 159916))+16) = i0;
  i0 = checkFunctionResult;
  *(OOC_UINT8*)((_check_pointer(i1, 159947))+12) = i0;
  return;
  ;
}

OOC_IR__Procedure OOC_IR__BuilderDesc_NewProcedure(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_SymbolTable__ProcDecl decl, OOC_IR__StatementSeq statmSeq, OOC_Scanner_SymList__Symbol endOfProc, OOC_CHAR8 hasBegin) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_IR__Procedure p;
  auto OOC_IR__StatementSeq OOC_IR__BuilderDesc_NewProcedure_AddSetupCode(OOC_Scanner_SymList__Symbol sym, OOC_SymbolTable__ProcDecl decl, OOC_IR__StatementSeq statmSeq);
    
    OOC_IR__StatementSeq OOC_IR__BuilderDesc_NewProcedure_AddSetupCode(OOC_Scanner_SymList__Symbol sym, OOC_SymbolTable__ProcDecl decl, OOC_IR__StatementSeq statmSeq) {
      register OOC_INT32 i0,i1,i2;
      ADT_ArrayList__ArrayList newStatm;
      OOC_SymbolTable__VarDeclArray formalPars;
      OOC_INT32 fparIndex;
      OOC_SymbolTable__VarDecl fpar;
      auto void OOC_IR__BuilderDesc_NewProcedure_AddSetupCode_AddStatm(OOC_IR__Statement statm);
      auto OOC_IR__StatementSeq OOC_IR__BuilderDesc_NewProcedure_AddSetupCode_Prepend(ADT_ArrayList__ArrayList prefix, OOC_IR__StatementSeq statmSeq);
        
        void OOC_IR__BuilderDesc_NewProcedure_AddSetupCode_AddStatm(OOC_IR__Statement statm) {
          register OOC_INT32 i0,i1;

          i0 = (OOC_INT32)newStatm;
          i1 = i0==(OOC_INT32)0;
          if (!i1) goto l4;
          i0 = (OOC_INT32)ADT_ArrayList__New(4);
          newStatm = (ADT_ArrayList__ArrayList)i0;
          
l4:
          i1 = (OOC_INT32)statm;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 161009)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i0, (Object__Object)i1);
          return;
          ;
        }

        
        OOC_IR__StatementSeq OOC_IR__BuilderDesc_NewProcedure_AddSetupCode_Prepend(ADT_ArrayList__ArrayList prefix, OOC_IR__StatementSeq statmSeq) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9;
          OOC_IR__StatementSeq _new;
          OOC_INT32 i;

          i0 = (OOC_INT32)prefix;
          i1 = (OOC_INT32)statmSeq;
          i2 = *(OOC_INT32*)((_check_pointer(i0, 161235))+4);
          i3 = OOC_ARRAY_LENGTH((_check_pointer(i1, 161255)), 0);
          i2 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__StatementSeq.baseTypes[0], (i2+i3));
          _new = (OOC_IR__StatementSeq)i2;
          i = 0;
          i3 = *(OOC_INT32*)((_check_pointer(i0, 161288))+4);
          i4 = 0<i3;
          if (!i4) goto l8;
          i4=0;
l3_loop:
          i5 = _check_pointer(i2, 161313);
          i6 = OOC_ARRAY_LENGTH(i5, 0);
          i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 161326));
          i7 = _check_pointer(i7, 161333);
          i8 = OOC_ARRAY_LENGTH(i7, 0);
          i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i4, i8, OOC_UINT32, 161333))*4);
          *(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 161313))*4) = (_type_guard(i7, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 161337)))), &_td_OOC_IR__StatementDesc, 161337));
          i4 = i4+1;
          i = i4;
          i5 = i4<i3;
          if (i5) goto l3_loop;
l8:
          i = 0;
          i3 = OOC_ARRAY_LENGTH((_check_pointer(i1, 161396)), 0);
          i4 = 0<i3;
          if (!i4) goto l16;
          i4=0;
l11_loop:
          i5 = _check_pointer(i2, 161417);
          i6 = *(OOC_INT32*)((_check_pointer(i0, 161426))+4);
          i7 = OOC_ARRAY_LENGTH(i5, 0);
          i8 = _check_pointer(i1, 161445);
          i9 = OOC_ARRAY_LENGTH(i8, 0);
          i8 = (OOC_INT32)*(OOC_INT32*)(i8+(_check_index(i4, i9, OOC_UINT32, 161445))*4);
          *(OOC_INT32*)(i5+(_check_index((i4+i6), i7, OOC_UINT32, 161417))*4) = i8;
          i4 = i4+1;
          i = i4;
          i5 = i4<i3;
          if (i5) goto l11_loop;
l16:
          return (OOC_IR__StatementSeq)i2;
          ;
        }


      newStatm = (ADT_ArrayList__ArrayList)(OOC_INT32)0;
      i0 = (OOC_INT32)decl;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 161562))+64);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 161574))+52);
      formalPars = (OOC_SymbolTable__VarDeclArray)i0;
      fparIndex = 0;
      i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 161675)), 0);
      i0 = 0!=i0;
      if (!i0) goto l11;
      i0=0;
l3_loop:
      i1 = (OOC_INT32)formalPars;
      i1 = _check_pointer(i1, 161708);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i0 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(i0, i2, OOC_UINT32, 161708))*4);
      fpar = (OOC_SymbolTable__VarDecl)i0;
      i1 = *(OOC_UINT8*)((_check_pointer(i0, 161736))+61);
      if (!i1) goto l6;
      i1 = (OOC_INT32)b;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 161803)))), OOC_IR__BuilderDesc_NewVar)),OOC_IR__BuilderDesc_NewVar)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)(OOC_INT32)0, (OOC_SymbolTable__VarDecl)i0);
      i1 = (OOC_INT32)b;
      i2 = (OOC_INT32)sym;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 161777)))), OOC_IR__BuilderDesc_NewCopyParameter)),OOC_IR__BuilderDesc_NewCopyParameter)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Var)i0);
      OOC_IR__BuilderDesc_NewProcedure_AddSetupCode_AddStatm((OOC_IR__Statement)i0);
l6:
      i0 = fparIndex;
      i0 = i0+1;
      fparIndex = i0;
      i1 = (OOC_INT32)formalPars;
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 161675)), 0);
      i1 = i0!=i1;
      if (i1) goto l3_loop;
l11:
      i0 = (OOC_INT32)newStatm;
      i1 = i0==(OOC_INT32)0;
      if (i1) goto l14;
      i1 = (OOC_INT32)statmSeq;
      i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewProcedure_AddSetupCode_Prepend((ADT_ArrayList__ArrayList)i0, (OOC_IR__StatementSeq)i1);
      return (OOC_IR__StatementSeq)i0;
      goto l15;
l14:
      i0 = (OOC_INT32)statmSeq;
      return (OOC_IR__StatementSeq)i0;
l15:
      _failed_function(160353); return 0;
      ;
    }


  i0 = (OOC_INT32)decl;
  i1 = (OOC_INT32)b;
  i2 = (OOC_INT32)sym;
  i3 = *(OOC_UINT8*)((_check_pointer(i0, 162046))+50);
  if (i3) goto l3;
  i3=0u;
  goto l5;
l3:
  i3 = hasBegin;
  
l5:
  if (!i3) goto l7;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 162081)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 57, (OOC_Scanner_SymList__Symbol)i2);
l7:
  i3 = (OOC_INT32)statmSeq;
  OOC_IR__BuilderDesc_CheckExit((OOC_IR__Builder)i1, (OOC_SymbolTable__ProcDecl)i0, (OOC_IR__StatementSeq)i3);
  p = (OOC_IR__Procedure)((OOC_INT32)RT0__NewObject(_td_OOC_IR__Procedure.baseTypes[0]));
  i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewProcedure_AddSetupCode((OOC_Scanner_SymList__Symbol)i2, (OOC_SymbolTable__ProcDecl)i0, (OOC_IR__StatementSeq)i3);
  statmSeq = (OOC_IR__StatementSeq)i0;
  i1 = (OOC_INT32)decl;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 162306))+64);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 162317))+44);
  i2 = i2!=(OOC_INT32)0;
  if (i2) goto l10;
  i2=0u;
  goto l11;
l10:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 162447))+20);
  i2 = *(OOC_INT32*)(_check_pointer(i2, 162453));
  i3 = (OOC_INT32)OOC_Config_StdPragmas__functionResultCheck;
  i4 = (OOC_INT32)b;
  i2 = OOC_IR__GetPragmaValue((OOC_IR__Builder)i4, (Config_Section_Options__Option)i3, i2);
  
l11:
  i3 = (OOC_INT32)endOfProc;
  i4 = (OOC_INT32)sym;
  i5 = (OOC_INT32)p;
  OOC_IR__InitProcedure((OOC_IR__Procedure)i5, (OOC_Scanner_SymList__Symbol)i4, (OOC_SymbolTable__ProcDecl)i1, (OOC_IR__StatementSeq)i0, (OOC_Scanner_SymList__Symbol)i3, i2);
  return (OOC_IR__Procedure)i5;
  ;
}

void OOC_IR__VisitorDesc_VisitProcedure(OOC_IR__Visitor v, OOC_IR__Procedure procedure) {

  return;
  ;
}

void OOC_IR__ProcedureDesc_Accept(OOC_IR__Procedure p, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)p;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 162653)))), OOC_IR__VisitorDesc_VisitProcedure)),OOC_IR__VisitorDesc_VisitProcedure)((OOC_IR__Visitor)i0, (OOC_IR__Procedure)i1);
  return;
  ;
}

void OOC_IR__InitModule(OOC_IR__Module m, OOC_Scanner_SymList__Symbol sym, OOC_Scanner_InputBuffer__CharArray name, OOC_IR__ProcedureList procList, OOC_IR__Procedure moduleBody) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)m;
  OOC_IR__InitNode((OOC_IR__Node)i1, (OOC_Scanner_SymList__Symbol)i0);
  i0 = (OOC_INT32)name;
  *(OOC_INT32*)((_check_pointer(i1, 162953))+4) = i0;
  i0 = (OOC_INT32)procList;
  *(OOC_INT32*)((_check_pointer(i1, 162974))+8) = i0;
  i0 = (OOC_INT32)moduleBody;
  *(OOC_INT32*)((_check_pointer(i1, 163003))+12) = i0;
  return;
  ;
}

OOC_IR__Module OOC_IR__BuilderDesc_NewModule(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_Scanner_InputBuffer__CharArray name, OOC_SymbolTable__Module decl, OOC_IR__ProcedureList procList, OOC_IR__StatementSeq statmSeq, OOC_Scanner_SymList__Symbol endOfModule) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_IR__Module m;
  auto void OOC_IR__BuilderDesc_NewModule_UnusedDeclarations(OOC_SymbolTable__Item item);
    
    void OOC_IR__BuilderDesc_NewModule_UnusedDeclarations(OOC_SymbolTable__Item item) {
      register OOC_INT32 i0,i1,i2;
      OOC_SymbolTable__Item nested;

      i0 = (OOC_INT32)item;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 163444)))), &_td_OOC_SymbolTable__DeclarationDesc);
      if (!i1) goto l38;
      i1 = *(OOC_INT32*)((_check_pointer(i0, 163691))+44);
      i1 = i1==0;
      if (i1) goto l5;
      i1=0u;
      goto l7;
l5:
      i1 = *(OOC_INT8*)((_check_pointer(i0, 163726))+28);
      i1 = i1==0;
      
l7:
      if (i1) goto l9;
      i1=0u;
      goto l15;
l9:
      i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 163782)))), &_td_OOC_SymbolTable__VarDeclDesc));
      if (i1) goto l12;
      i1 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 163811)))), &_td_OOC_SymbolTable__VarDeclDesc, 163811)), 163819))+56);
      i1 = !i1;
      
      goto l15;
l12:
      i1=1u;
l15:
      if (i1) goto l17;
      i1=0u;
      goto l23;
l17:
      i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 163854)))), &_td_OOC_SymbolTable__TypeDeclDesc));
      if (i1) goto l20;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 163880))+4);
      i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 163888)))), &_td_OOC_SymbolTable__FormalParsDesc));
      
      goto l23;
l20:
      i1=1u;
l23:
      if (i1) goto l25;
      i1=0u;
      goto l35;
l25:
      i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 163929)))), &_td_OOC_SymbolTable__ProcDeclDesc));
      if (i1) goto l32;
      i1 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 163972)))), &_td_OOC_SymbolTable__ProcDeclDesc, 163972)), 163981))+49);
      if (i1) goto l30;
      i1 = OOC_SymbolTable__ProcDeclDesc_IsTypeBound((OOC_SymbolTable__ProcDecl)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 164022)))), &_td_OOC_SymbolTable__ProcDeclDesc, 164022)));
      
      goto l31;
l30:
      i1=1u;
l31:
      i1 = !i1;
      
      goto l35;
l32:
      i1=1u;
l35:
      if (!i1) goto l38;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 164097))+20);
      i2 = (OOC_INT32)b;
      OOC_IR__BuilderDesc_WarnName((OOC_IR__Builder)i2, 53, (OOC_SymbolTable__Name)i1);
l38:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 164181))+8);
      nested = (OOC_SymbolTable__Item)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l46;
l41_loop:
      OOC_IR__BuilderDesc_NewModule_UnusedDeclarations((OOC_SymbolTable__Item)i0);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 164285));
      nested = (OOC_SymbolTable__Item)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l41_loop;
l46:
      return;
      ;
    }


  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__Module.baseTypes[0]);
  m = (OOC_IR__Module)i0;
  i1 = (OOC_INT32)decl;
  i2 = (OOC_INT32)b;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 164441))+80);
  i4 = (OOC_INT32)sym;
  i5 = (OOC_INT32)statmSeq;
  i6 = (OOC_INT32)endOfModule;
  i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 164416)))), OOC_IR__BuilderDesc_NewProcedure)),OOC_IR__BuilderDesc_NewProcedure)((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i4, (OOC_SymbolTable__ProcDecl)i3, (OOC_IR__StatementSeq)i5, (OOC_Scanner_SymList__Symbol)i6, 1u);
  i5 = (OOC_INT32)name;
  i6 = (OOC_INT32)procList;
  OOC_IR__InitModule((OOC_IR__Module)i0, (OOC_Scanner_SymList__Symbol)i4, (OOC_Scanner_InputBuffer__CharArray)i5, (OOC_IR__ProcedureList)i6, (OOC_IR__Procedure)i3);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 164525))+8);
  i0 = OOC_Error__ListDesc_NoErrors((OOC_Error__List)i0);
  if (!i0) goto l4;
  OOC_IR__BuilderDesc_NewModule_UnusedDeclarations((OOC_SymbolTable__Item)i1);
l4:
  i0 = (OOC_INT32)m;
  return (OOC_IR__Module)i0;
  ;
}

void OOC_IR__VisitorDesc_VisitModule(OOC_IR__Visitor v, OOC_IR__Module module) {

  return;
  ;
}

void OOC_IR__ModuleDesc_Accept(OOC_IR__Module m, OOC_IR__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)m;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 164764)))), OOC_IR__VisitorDesc_VisitModule)),OOC_IR__VisitorDesc_VisitModule)((OOC_IR__Visitor)i0, (OOC_IR__Module)i1);
  return;
  ;
}

void OOC_IR__ModuleDesc_Destroy(OOC_IR__Module m) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT32 i;
  auto void OOC_IR__ModuleDesc_Destroy_E(OOC_IR__Expression *n);
  auto void OOC_IR__ModuleDesc_Destroy_S(OOC_IR__Statement *n);
  auto void OOC_IR__ModuleDesc_Destroy_EList(OOC_IR__ExpressionList *e);
  auto void OOC_IR__ModuleDesc_Destroy_E(OOC_IR__Expression *n);
  auto void OOC_IR__ModuleDesc_Destroy_SSeq(OOC_IR__StatementSeq *n);
  auto void OOC_IR__ModuleDesc_Destroy_S(OOC_IR__Statement *n);
    
    void OOC_IR__ModuleDesc_Destroy_EList(OOC_IR__ExpressionList *e) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      OOC_INT32 i;

      i0 = (OOC_INT32)*e;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l11;
      i = 0;
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 165182)), 0);
      i2 = 0<i1;
      if (!i2) goto l10;
      i2=0;
l5_loop:
      i3 = _check_pointer(i0, 165203);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      OOC_IR__ModuleDesc_Destroy_E((void*)(i3+(_check_index(i2, i4, OOC_UINT32, 165203))*4));
      i2 = i2+1;
      i = i2;
      i3 = i2<i1;
      if (i3) goto l5_loop;
l10:
      *e = (OOC_IR__ExpressionList)(OOC_INT32)0;
l11:
      return;
      ;
    }

    
    void OOC_IR__ModuleDesc_Destroy_E(OOC_IR__Expression *n) {
      register OOC_INT32 i0,i1;
      OOC_IR__Expression expr;

      i0 = (OOC_INT32)*n;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l142;
      *(OOC_INT32*)((_check_pointer(i0, 165379))+4) = (OOC_INT32)0;
      i0 = (OOC_INT32)*n;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 165407)))), &_td_OOC_IR__ConstDesc);
      if (i1) goto l140;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 165455)))), &_td_OOC_IR__OperatorDesc);
      if (i1) goto l15;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 167848)))), &_td_OOC_IR__ReferenceDesc);
      if (i1) goto l13;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 167899)))), &_td_OOC_IR__StatementDesc);
      if (i1) goto l11;
      Log__Type("--- expression type", 20, (void*)i0);
      _assert(0u, 127, 168034);
      goto l141;
l11:
      OOC_IR__ModuleDesc_Destroy_S((void*)(OOC_INT32)n);
      goto l141;
l13:
      *(OOC_INT32*)((_check_pointer(i0, 167874))+8) = (OOC_INT32)0;
      goto l141;
l15:
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 165485)))), &_td_OOC_IR__AbsDesc);
      if (i1) goto l137;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 165533)))), &_td_OOC_IR__AdrDesc);
      if (i1) goto l135;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 165580)))), &_td_OOC_IR__AshDesc);
      if (i1) goto l133;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 165648)))), &_td_OOC_IR__BinaryArithDesc);
      if (i1) goto l131;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 165725)))), &_td_OOC_IR__BooleanOpDesc);
      if (i1) goto l129;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 165800)))), &_td_OOC_IR__CapDesc);
      if (i1) goto l127;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 165848)))), &_td_OOC_IR__CompareDesc);
      if (i1) goto l125;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 165921)))), &_td_OOC_IR__ConcatDesc);
      if (i1) goto l123;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 165976)))), &_td_OOC_IR__ConstructorDesc);
      if (i1) goto l121;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 166160)))), &_td_OOC_IR__CurrentExceptionDesc);
      if (i1) goto l141;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 166221)))), &_td_OOC_IR__ChangeElementDesc);
      if (i1) goto l118;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 166301)))), &_td_OOC_IR__DerefDesc);
      if (i1) goto l116;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 166351)))), &_td_OOC_IR__EntierDesc);
      if (i1) goto l114;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 166402)))), &_td_OOC_IR__IndexDesc);
      if (i1) goto l112;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 166474)))), &_td_OOC_IR__LenDesc);
      if (i1) goto l110;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 166576)))), &_td_OOC_IR__NegateDesc);
      if (i1) goto l108;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 166627)))), &_td_OOC_IR__NewBlockDesc);
      if (i1) goto l106;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 166677)))), &_td_OOC_IR__NewObjectDesc);
      if (i1) goto l104;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 166734)))), &_td_OOC_IR__NotDesc);
      if (i1) goto l102;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 166782)))), &_td_OOC_IR__OddDesc);
      if (i1) goto l100;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 166830)))), &_td_OOC_IR__SelectFieldDesc);
      if (i1) goto l98;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 166944)))), &_td_OOC_IR__SelectProcDesc);
      if (i1) goto l96;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 167061)))), &_td_OOC_IR__SetMemberDesc);
      if (i1) goto l94;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 167137)))), &_td_OOC_IR__SetOpDesc);
      if (i1) goto l92;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 167208)))), &_td_OOC_IR__SetRangeDesc);
      if (i1) goto l90;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 167279)))), &_td_OOC_IR__ShiftDesc);
      if (i1) goto l88;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 167348)))), &_td_OOC_IR__TypeCastDesc);
      if (i1) goto l86;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 167398)))), &_td_OOC_IR__TypeConvDesc);
      if (i1) goto l84;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 167448)))), &_td_OOC_IR__TypeTagDesc);
      if (i1) goto l82;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 167499)))), &_td_OOC_IR__TypeTestDesc);
      if (i1) goto l80;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 167643)))), &_td_OOC_IR__TypeGuardDesc);
      if (i1) goto l78;
      Log__Type("--- operator type", 18, (void*)i0);
      _assert(0u, 127, 167807);
      goto l141;
l78:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 167679))+8);
      expr = (OOC_IR__Expression)i0;
      OOC_IR__ModuleDesc_Destroy_E((void*)(OOC_INT32)&expr);
      i0 = (OOC_INT32)*n;
      *(OOC_INT32*)((_check_pointer(i0, 167720))+8) = (OOC_INT32)0;
      goto l141;
l80:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 167528))+8));
      i0 = (OOC_INT32)*n;
      *(OOC_INT32*)((_check_pointer(i0, 167549))+12) = (OOC_INT32)0;
      i0 = (OOC_INT32)*n;
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 167587))+20));
      i0 = (OOC_INT32)*n;
      *(OOC_INT32*)((_check_pointer(i0, 167612))+24) = (OOC_INT32)0;
      goto l141;
l82:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 167476))+8));
      goto l141;
l84:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 167427))+8));
      goto l141;
l86:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 167377))+8));
      goto l141;
l88:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 167305))+8));
      i0 = (OOC_INT32)*n;
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 167329))+12));
      goto l141;
l90:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 167237))+8));
      i0 = (OOC_INT32)*n;
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 167260))+12));
      goto l141;
l92:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 167163))+12));
      i0 = (OOC_INT32)*n;
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 167186))+16));
      goto l141;
l94:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 167091))+8));
      i0 = (OOC_INT32)*n;
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 167117))+12));
      goto l141;
l96:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 166975))+8));
      i0 = (OOC_INT32)*n;
      *(OOC_INT32*)((_check_pointer(i0, 167000))+20) = (OOC_INT32)0;
      i0 = (OOC_INT32)*n;
      *(OOC_INT32*)((_check_pointer(i0, 167029))+24) = (OOC_INT32)0;
      goto l141;
l98:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 166862))+8));
      i0 = (OOC_INT32)*n;
      *(OOC_INT32*)((_check_pointer(i0, 166885))+12) = (OOC_INT32)0;
      i0 = (OOC_INT32)*n;
      *(OOC_INT32*)((_check_pointer(i0, 166913))+16) = (OOC_INT32)0;
      goto l141;
l100:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 166806))+8));
      goto l141;
l102:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 166758))+8));
      goto l141;
l104:
      OOC_IR__ModuleDesc_Destroy_EList((void*)((_check_pointer(i0, 166711))+8));
      goto l141;
l106:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 166656))+8));
      goto l141;
l108:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 166603))+8));
      goto l141;
l110:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 166498))+12));
      i0 = (OOC_INT32)*n;
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 166522))+20));
      i0 = (OOC_INT32)*n;
      *(OOC_INT32*)((_check_pointer(i0, 166552))+16) = 0;
      goto l141;
l112:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 166428))+8));
      i0 = (OOC_INT32)*n;
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 166452))+12));
      goto l141;
l114:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 166378))+8));
      goto l141;
l116:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 166327))+8));
      goto l141;
l118:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 166255))+12));
      i0 = (OOC_INT32)*n;
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 166277))+16));
      goto l141;
l121:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 166014))+8);
      expr = (OOC_IR__Expression)i0;
      OOC_IR__ModuleDesc_Destroy_E((void*)(OOC_INT32)&expr);
      i0 = (OOC_INT32)*n;
      *(OOC_INT32*)((_check_pointer(i0, 166056))+8) = (OOC_INT32)0;
      i0 = (OOC_INT32)*n;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 166092))+12);
      expr = (OOC_IR__Expression)i0;
      OOC_IR__ModuleDesc_Destroy_E((void*)(OOC_INT32)&expr);
      i0 = (OOC_INT32)*n;
      *(OOC_INT32*)((_check_pointer(i0, 166133))+12) = (OOC_INT32)0;
      goto l141;
l123:
      OOC_IR__ModuleDesc_Destroy_EList((void*)((_check_pointer(i0, 165952))+8));
      goto l141;
l125:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 165876))+12));
      i0 = (OOC_INT32)*n;
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 165899))+16));
      goto l141;
l127:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 165824))+8));
      goto l141;
l129:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 165755))+12));
      i0 = (OOC_INT32)*n;
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 165778))+16));
      goto l141;
l131:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 165680))+12));
      i0 = (OOC_INT32)*n;
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 165703))+16));
      goto l141;
l133:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 165604))+8));
      i0 = (OOC_INT32)*n;
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 165628))+12));
      goto l141;
l135:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 165557))+8));
      goto l141;
l137:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 165509))+8));
      goto l141;
l140:
      *(OOC_INT32*)((_check_pointer(i0, 165429))+8) = (OOC_INT32)0;
l141:
      *n = (OOC_IR__Expression)(OOC_INT32)0;
l142:
      return;
      ;
    }

    
    void OOC_IR__ModuleDesc_Destroy_SSeq(OOC_IR__StatementSeq *n) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      OOC_INT32 i;

      i0 = (OOC_INT32)*n;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l11;
      i = 0;
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 168230)), 0);
      i2 = 0<i1;
      if (!i2) goto l11;
      i2=0;
l5_loop:
      i3 = _check_pointer(i0, 168251);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      OOC_IR__ModuleDesc_Destroy_S((void*)(i3+(_check_index(i2, i4, OOC_UINT32, 168251))*4));
      i2 = i2+1;
      i = i2;
      i3 = i2<i1;
      if (i3) goto l5_loop;
l11:
      return;
      ;
    }

    
    void OOC_IR__ModuleDesc_Destroy_S(OOC_IR__Statement *n) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      OOC_INT32 i;

      i0 = (OOC_INT32)*n;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l101;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 168406)))), &_td_OOC_IR__AssertDesc);
      if (i1) goto l99;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 168478)))), &_td_OOC_IR__AssignmentDesc);
      if (i1) goto l97;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 168552)))), &_td_OOC_IR__CallDesc);
      if (i1) goto l95;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 168657)))), &_td_OOC_IR__CopyDesc);
      if (i1) goto l93;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 168722)))), &_td_OOC_IR__CopyParameterDesc);
      if (i1) goto l91;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 168778)))), &_td_OOC_IR__CopyStringDesc);
      if (i1) goto l89;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 168875)))), &_td_OOC_IR__ExitDesc);
      if (i1) goto l87;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 168921)))), &_td_OOC_IR__ForStatmDesc);
      if (i1) goto l85;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 169053)))), &_td_OOC_IR__IterateArrayStatmDesc);
      if (i1) goto l83;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 169153)))), &_td_OOC_IR__IterateObjectStatmDesc);
      if (i1) goto l81;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 169264)))), &_td_OOC_IR__IfStatmDesc);
      if (i1) goto l79;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 169367)))), &_td_OOC_IR__CaseStatmDesc);
      if (i1) goto l68;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 169650)))), &_td_OOC_IR__LoopStatmDesc);
      if (i1) goto l66;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 169700)))), &_td_OOC_IR__MoveBlockDesc);
      if (i1) goto l64;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 169791)))), &_td_OOC_IR__RaiseDesc);
      if (i1) goto l62;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 169839)))), &_td_OOC_IR__RepeatStatmDesc);
      if (i1) goto l60;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 169921)))), &_td_OOC_IR__ReturnDesc);
      if (i1) goto l58;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 169967)))), &_td_OOC_IR__TryStatmDesc);
      if (i1) goto l47;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 170195)))), &_td_OOC_IR__WhileStatmDesc);
      if (i1) goto l45;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 170268)))), &_td_OOC_IR__WithStatmDesc);
      if (i1) goto l43;
      _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 170265)))), 170265);
      goto l100;
l43:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 170296))+8));
      OOC_IR__ModuleDesc_Destroy_SSeq((void*)((_check_pointer(i0, 170321))+12));
      OOC_IR__ModuleDesc_Destroy_SSeq((void*)((_check_pointer(i0, 170349))+16));
      goto l100;
l45:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 170224))+8));
      OOC_IR__ModuleDesc_Destroy_SSeq((void*)((_check_pointer(i0, 170249))+12));
      goto l100;
l47:
      OOC_IR__ModuleDesc_Destroy_SSeq((void*)((_check_pointer(i0, 169997))+8));
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 170038))+12);
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 170048)), 0);
      i = 0;
      i2 = 0<i1;
      if (!i2) goto l56;
      i2=0;
l51_loop:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 170069))+12);
      i0 = _check_pointer(i0, 170079);
      i3 = OOC_ARRAY_LENGTH(i0, 0);
      i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(i2, i3, OOC_UINT32, 170079))*4);
      *(OOC_INT32*)((_check_pointer(i0, 170082))+4) = (OOC_INT32)0;
      i0 = (OOC_INT32)*n;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 170114))+12);
      i3 = _check_pointer(i3, 170124);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 170124))*4);
      OOC_IR__ModuleDesc_Destroy_SSeq((void*)((_check_pointer(i3, 170127))+12));
      i2 = i2+1;
      i = i2;
      i3 = i2<i1;
      if (i3) goto l51_loop;
l56:
      *(OOC_INT32*)((_check_pointer(i0, 170165))+12) = (OOC_INT32)0;
      goto l100;
l58:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 169946))+8));
      goto l100;
l60:
      OOC_IR__ModuleDesc_Destroy_SSeq((void*)((_check_pointer(i0, 169872))+8));
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 169893))+12));
      goto l100;
l62:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 169815))+8));
      goto l100;
l64:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 169728))+8));
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 169751))+12));
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 169772))+16));
      goto l100;
l66:
      OOC_IR__ModuleDesc_Destroy_SSeq((void*)((_check_pointer(i0, 169681))+8));
      goto l100;
l68:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 169395))+8));
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 169434))+12);
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 169443)), 0);
      i = 0;
      i2 = 0<i1;
      if (!i2) goto l77;
      i2=0;
l72_loop:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 169464))+12);
      i0 = _check_pointer(i0, 169473);
      i3 = OOC_ARRAY_LENGTH(i0, 0);
      i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(i2, i3, OOC_UINT32, 169473))*4);
      *(OOC_INT32*)((_check_pointer(i0, 169476))+8) = (OOC_INT32)0;
      i0 = (OOC_INT32)*n;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 169510))+12);
      i3 = _check_pointer(i3, 169519);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 169519))*4);
      OOC_IR__ModuleDesc_Destroy_SSeq((void*)((_check_pointer(i3, 169522))+12));
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 169547))+12);
      i3 = _check_pointer(i3, 169556);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      *(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 169556))*4) = (OOC_INT32)0;
      i2 = i2+1;
      i = i2;
      i3 = i2<i1;
      if (i3) goto l72_loop;
l77:
      *(OOC_INT32*)((_check_pointer(i0, 169594))+12) = (OOC_INT32)0;
      i0 = (OOC_INT32)*n;
      OOC_IR__ModuleDesc_Destroy_SSeq((void*)((_check_pointer(i0, 169628))+16));
      goto l100;
l79:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 169290))+8));
      OOC_IR__ModuleDesc_Destroy_SSeq((void*)((_check_pointer(i0, 169315))+12));
      OOC_IR__ModuleDesc_Destroy_SSeq((void*)((_check_pointer(i0, 169343))+16));
      goto l100;
l81:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 169190))+8));
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 169210))+12));
      OOC_IR__ModuleDesc_Destroy_SSeq((void*)((_check_pointer(i0, 169245))+20));
      goto l100;
l83:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 169089))+8));
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 169109))+12));
      OOC_IR__ModuleDesc_Destroy_SSeq((void*)((_check_pointer(i0, 169134))+16));
      goto l100;
l85:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 168948))+8));
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 168968))+12));
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 168990))+16));
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 169010))+20));
      OOC_IR__ModuleDesc_Destroy_SSeq((void*)((_check_pointer(i0, 169034))+24));
      goto l100;
l87:
      *(OOC_INT32*)((_check_pointer(i0, 168896))+8) = (OOC_INT32)0;
      goto l100;
l89:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 168807))+8));
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 168830))+12));
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 168851))+16));
      goto l100;
l91:
      *(OOC_INT32*)((_check_pointer(i0, 168752))+8) = (OOC_INT32)0;
      goto l100;
l93:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 168680))+8));
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 168703))+12));
      goto l100;
l95:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 168575))+8));
      OOC_IR__ModuleDesc_Destroy_EList((void*)((_check_pointer(i0, 168602))+12));
      *(OOC_INT32*)((_check_pointer(i0, 168626))+16) = (OOC_INT32)0;
      goto l100;
l97:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 168507))+8));
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 168532))+12));
      goto l100;
l99:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 168431))+8));
      *(OOC_INT32*)((_check_pointer(i0, 168455))+12) = 0;
l100:
      *n = (OOC_IR__Statement)(OOC_INT32)0;
l101:
      return;
      ;
    }


  i0 = (OOC_INT32)m;
  *(OOC_INT32*)((_check_pointer(i0, 170431))+4) = (OOC_INT32)0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 170468))+8);
  i = 0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 170477)), 0);
  i2 = 0<i1;
  if (!i2) goto l9;
  i2=0;
l4_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 170492))+8);
  i3 = _check_pointer(i3, 170501);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 170501))*4);
  *(OOC_INT32*)((_check_pointer(i3, 170504))+4) = (OOC_INT32)0;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 170530))+8);
  i0 = _check_pointer(i0, 170539);
  i3 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(i2, i3, OOC_UINT32, 170539))*4);
  OOC_IR__ModuleDesc_Destroy_SSeq((void*)((_check_pointer(i0, 170542))+8));
  i0 = (OOC_INT32)m;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 170561))+8);
  i2 = _check_pointer(i2, 170570);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = i;
  *(OOC_INT32*)(i2+(_check_index(i4, i3, OOC_UINT32, 170570))*4) = (OOC_INT32)0;
  i2 = i4+1;
  i = i2;
  i3 = i2<i1;
  if (i3) goto l4_loop;
l9:
  *(OOC_INT32*)((_check_pointer(i0, 170596))+8) = (OOC_INT32)0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 170620))+12);
  *(OOC_INT32*)((_check_pointer(i1, 170631))+4) = (OOC_INT32)0;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 170655))+12);
  OOC_IR__ModuleDesc_Destroy_SSeq((void*)((_check_pointer(i0, 170666))+8));
  i0 = (OOC_INT32)m;
  *(OOC_INT32*)((_check_pointer(i0, 170683))+12) = (OOC_INT32)0;
  return;
  ;
}

void OOC_IR__InitVisitor(OOC_IR__Visitor v) {

  return;
  ;
}

void OOC_IR__InitConstFold(OOC_IR__ConstFold c, OOC_IR__Builder b) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)c;
  OOC_IR__InitVisitor((OOC_IR__Visitor)i0);
  i1 = (OOC_INT32)b;
  *(OOC_INT32*)(_check_pointer(i0, 170981)) = i1;
  return;
  ;
}

void OOC_IR__InitBuilder(OOC_IR__Builder b, OOC_SymbolTable__Module module, OOC_SymbolTable_Uses__Uses uses, OOC_Config_Pragmas__History pragmaHistory, OOC_Error__List errList, OOC_IR__ConstFold fold) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_SymbolTable__Item string;
  auto OOC_IR__TypeType OOC_IR__InitBuilder_NewTypeType(OOC_SymbolTable__Item parent, OOC_SymbolTable__Position position);
  auto OOC_IR__ModuleType OOC_IR__InitBuilder_NewModuleType(OOC_SymbolTable__Item parent, OOC_SymbolTable__Position position);
    
    OOC_IR__TypeType OOC_IR__InitBuilder_NewTypeType(OOC_SymbolTable__Item parent, OOC_SymbolTable__Position position) {
      register OOC_INT32 i0,i1,i2;

      i0 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__TypeType.baseTypes[0]);
      i1 = (OOC_INT32)position;
      i2 = (OOC_INT32)parent;
      OOC_SymbolTable__InitType((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Item)i2, (OOC_SymbolTable__Position)i1);
      return (OOC_IR__TypeType)i0;
      ;
    }

    
    OOC_IR__ModuleType OOC_IR__InitBuilder_NewModuleType(OOC_SymbolTable__Item parent, OOC_SymbolTable__Position position) {
      register OOC_INT32 i0,i1,i2;

      i0 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__ModuleType.baseTypes[0]);
      i1 = (OOC_INT32)position;
      i2 = (OOC_INT32)parent;
      OOC_SymbolTable__InitType((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Item)i2, (OOC_SymbolTable__Position)i1);
      return (OOC_IR__ModuleType)i0;
      ;
    }


  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)module;
  *(OOC_INT32*)(_check_pointer(i0, 171850)) = i1;
  i1 = (OOC_INT32)pragmaHistory;
  *(OOC_INT32*)((_check_pointer(i0, 171875))+4) = i1;
  i1 = (OOC_INT32)errList;
  *(OOC_INT32*)((_check_pointer(i0, 171914))+8) = i1;
  i1 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(17);
  i2 = (OOC_INT32)Object_Boxed__false;
  i3 = (OOC_INT32)OOC_Scanner_SymList__NewSymbol((OOC_Scanner_InputBuffer__CharArray)0, (-1));
  i1 = (OOC_INT32)OOC_IR__NewConst((OOC_Scanner_SymList__Symbol)i3, (OOC_SymbolTable__Type)i1, (Object_Boxed__Object)i2);
  *(OOC_INT32*)((_check_pointer(i0, 171941))+20) = i1;
  i1 = (OOC_INT32)OOC_IR__InitBuilder_NewTypeType((OOC_SymbolTable__Item)0, (OOC_SymbolTable__Position)0);
  *(OOC_INT32*)((_check_pointer(i0, 172103))+24) = i1;
  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)OOC_IR__InitBuilder_NewModuleType((OOC_SymbolTable__Item)0, (OOC_SymbolTable__Position)0);
  *(OOC_INT32*)((_check_pointer(i0, 172146))+28) = i1;
  i0 = (OOC_INT32)b;
  *(OOC_INT32*)((_check_pointer(i0, 172193))+36) = 0;
  i1 = (OOC_INT32)fold;
  *(OOC_INT32*)((_check_pointer(i0, 172218))+12) = i1;
  i2 = (OOC_INT32)uses;
  *(OOC_INT32*)((_check_pointer(i0, 172244))+16) = i2;
  *(OOC_INT32*)(_check_pointer(i1, 172268)) = i0;
  i1 = (OOC_INT32)module;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 172338))+48);
  i4 = (OOC_INT32)OOC_SymbolTable_Predef__nameStringType;
  i5 = (OOC_INT32)OOC_SymbolTable_Predef__nameStringModule;
  i1 = (OOC_INT32)OOC_SymbolTable_CreateNamespace__ResolveQualident((OOC_SymbolTable__Namespace)i3, (OOC_SymbolTable__Item)i1, (OOC_SymbolTable_Uses__Uses)i2, (OOC_SymbolTable__Name)i5, (OOC_SymbolTable__Name)i4);
  string = (OOC_SymbolTable__Item)i1;
  i2 = i1==0;
  if (i2) goto l3;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 172598)))), &_td_OOC_SymbolTable__TypeDeclDesc, 172598)), 172607))+48);
  *(OOC_INT32*)((_check_pointer(i0, 172571))+32) = i1;
  goto l4;
l3:
  *(OOC_INT32*)((_check_pointer(i0, 172534))+32) = 0;
l4:
  return;
  ;
}

OOC_IR__Builder OOC_IR__NewBuilder(OOC_SymbolTable__Module module, OOC_SymbolTable_Uses__Uses uses, OOC_Config_Pragmas__History pragmaHistory, OOC_Error__List errList, OOC_IR__ConstFold constFold) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__Builder.baseTypes[0]);
  i1 = (OOC_INT32)constFold;
  i2 = (OOC_INT32)errList;
  i3 = (OOC_INT32)pragmaHistory;
  i4 = (OOC_INT32)uses;
  i5 = (OOC_INT32)module;
  OOC_IR__InitBuilder((OOC_IR__Builder)i0, (OOC_SymbolTable__Module)i5, (OOC_SymbolTable_Uses__Uses)i4, (OOC_Config_Pragmas__History)i3, (OOC_Error__List)i2, (OOC_IR__ConstFold)i1);
  return (OOC_IR__Builder)i0;
  ;
}

void OOC_IR__BuilderDesc_StartTypeGuard(OOC_IR__Builder b, OOC_IR__TypeTest typeTest, OOC_SymbolTable__Namespace *namespace) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_SymbolTable__VarDecl var;
  OOC_SymbolTable__DeclarationArray da;
  OOC_SymbolTable_Namespace__Nested nested;

  i0 = (OOC_INT32)typeTest;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 173223))+8);
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 173229)))), &_td_OOC_IR__VarDesc);
  if (i1) goto l3;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 173630))+8);
  i1 = (OOC_INT32)b;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 173635));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 173599)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 29, (OOC_Scanner_SymList__Symbol)i0);
  goto l4;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 173263))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 173270)))), &_td_OOC_IR__VarDesc, 173270)), 173274))+8);
  i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 173285)))), &_td_OOC_SymbolTable__VarDeclDesc, 173285);
  var = (OOC_SymbolTable__VarDecl)i1;
  i2 = (OOC_INT32)RT0__NewObject(_td_OOC_SymbolTable__DeclarationArray.baseTypes[0], 1);
  da = (OOC_SymbolTable__DeclarationArray)i2;
  i3 = _check_pointer(i2, 173322);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 173408))+24);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 173417))+12);
  i0 = (OOC_INT32)OOC_SymbolTable__Expand((OOC_SymbolTable__Type)i0);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 173352))+20);
  i0 = (OOC_INT32)OOC_IR__NewGuardedVar((OOC_SymbolTable__VarDecl)i1, (OOC_SymbolTable__Name)i5, (OOC_SymbolTable__Type)i0);
  *(OOC_INT32*)(i3+(_check_index(0, i4, OOC_UINT8, 173322))*4) = i0;
  i0 = (OOC_INT32)OOC_SymbolTable_Namespace__NewNested((OOC_SymbolTable__DeclarationArray)i2, 1);
  nested = (OOC_SymbolTable_Namespace__Nested)i0;
  i1 = (OOC_INT32)*namespace;
  OOC_SymbolTable_Namespace__NestedDesc_SetEnclosingNamespace((OOC_SymbolTable_Namespace__Nested)i0, (OOC_SymbolTable_Namespace__Namespace)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 173532)))), &_td_OOC_SymbolTable_Namespace__NestedDesc, 173532)));
  *namespace = (OOC_SymbolTable__Namespace)i0;
  return;
l4:
  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SymbolTable__DeclarationArray.baseTypes[0], 0);
  da = (OOC_SymbolTable__DeclarationArray)i0;
  i0 = (OOC_INT32)OOC_SymbolTable_Namespace__NewNested((OOC_SymbolTable__DeclarationArray)i0, 0);
  nested = (OOC_SymbolTable_Namespace__Nested)i0;
  i1 = (OOC_INT32)*namespace;
  OOC_SymbolTable_Namespace__NestedDesc_SetEnclosingNamespace((OOC_SymbolTable_Namespace__Nested)i0, (OOC_SymbolTable_Namespace__Namespace)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 173843)))), &_td_OOC_SymbolTable_Namespace__NestedDesc, 173843)));
  *namespace = (OOC_SymbolTable__Namespace)i0;
  return;
  ;
}

void OOC_IR__BuilderDesc_EndTypeGuard(OOC_IR__Builder b, OOC_SymbolTable__Namespace *namespace) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)*namespace;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 174015)))), &_td_OOC_SymbolTable_Namespace__NestedDesc, 174015)), 174022))+8);
  *namespace = (OOC_SymbolTable__Namespace)i0;
  return;
  ;
}

void OOC_IR__BuilderDesc_StartExceptionScope(OOC_IR__Builder b, OOC_IR__Expression exceptionType, OOC_Scanner_SymList__Symbol varName, OOC_SymbolTable__Namespace *namespace) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_SymbolTable__Type type;
  OOC_SymbolTable__DeclarationArray da;
  OOC_SymbolTable_Namespace__Nested nested;

  i0 = (OOC_INT32)exceptionType;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 174378)))), &_td_OOC_IR__TypeRefDesc);
  if (i1) goto l3;
  i0 = (OOC_INT32)b;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 174453))+20);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 174463))+4);
  type = (OOC_SymbolTable__Type)i0;
  
  goto l4;
l3:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 174418))+12);
  type = (OOC_SymbolTable__Type)i0;
  
l4:
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_SymbolTable__DeclarationArray.baseTypes[0], 1);
  da = (OOC_SymbolTable__DeclarationArray)i1;
  i2 = _check_pointer(i1, 174506);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = (OOC_INT32)b;
  i5 = (OOC_INT32)varName;
  i4 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 174582)))), OOC_IR__BuilderDesc_GetName)),OOC_IR__BuilderDesc_GetName)((OOC_IR__Builder)i4, (OOC_Scanner_SymList__Symbol)i5);
  i5 = (OOC_INT32)OOC_SymbolTable_CreateNamespace__exception;
  i0 = (OOC_INT32)OOC_IR__NewGuardedVar((OOC_SymbolTable__VarDecl)i5, (OOC_SymbolTable__Name)i4, (OOC_SymbolTable__Type)i0);
  *(OOC_INT32*)(i2+(_check_index(0, i3, OOC_UINT8, 174506))*4) = i0;
  i0 = (OOC_INT32)OOC_SymbolTable_Namespace__NewNested((OOC_SymbolTable__DeclarationArray)i1, 1);
  nested = (OOC_SymbolTable_Namespace__Nested)i0;
  i1 = (OOC_INT32)*namespace;
  OOC_SymbolTable_Namespace__NestedDesc_SetEnclosingNamespace((OOC_SymbolTable_Namespace__Nested)i0, (OOC_SymbolTable_Namespace__Namespace)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 174703)))), &_td_OOC_SymbolTable_Namespace__NestedDesc, 174703)));
  *namespace = (OOC_SymbolTable__Namespace)i0;
  return;
  ;
}

void OOC_IR__BuilderDesc_EndExceptionScope(OOC_IR__Builder b, OOC_SymbolTable__Namespace *namespace) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)*namespace;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 174884)))), &_td_OOC_SymbolTable_Namespace__NestedDesc, 174884)), 174891))+8);
  *namespace = (OOC_SymbolTable__Namespace)i0;
  return;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_NewIdentRef(OOC_IR__Builder b, OOC_SymbolTable__Namespace baseNS, OOC_SymbolTable__Namespace ns, OOC_SymbolTable__Item context, OOC_Scanner_SymList__Symbol name) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_SymbolTable__Name n;
  OOC_SymbolTable__Declaration decl;
  OOC_IR__Var varRef;
  OOC_SymbolTable__Item redirModule;

  i0 = (OOC_INT32)name;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 175227))+4);
  i1 = i1==45;
  if (i1) goto l3;
  i1 = (OOC_INT32)b;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 176790)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 2, (OOC_Scanner_SymList__Symbol)i0);
  i0=i1;
  goto l52;
l3:
  i1 = (OOC_INT32)b;
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 175261)))), OOC_IR__BuilderDesc_GetName)),OOC_IR__BuilderDesc_GetName)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i0);
  n = (OOC_SymbolTable__Name)i2;
  i3 = (OOC_INT32)ns;
  i4 = (OOC_INT32)context;
  i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 175293)))), OOC_SymbolTable__NamespaceDesc_Identify)),OOC_SymbolTable__NamespaceDesc_Identify)((OOC_SymbolTable__Namespace)i3, (OOC_SymbolTable__Item)i4, (OOC_SymbolTable__Name)i2, 0u);
  decl = (OOC_SymbolTable__Declaration)i3;
  i5 = i3==(OOC_INT32)0;
  if (i5) goto l50;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 175430))+16);
  OOC_SymbolTable_Uses__Mark((OOC_SymbolTable__Declaration)i3, (OOC_SymbolTable_Uses__Uses)i5, (OOC_SymbolTable__Name)i2);
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 175458)))), &_td_OOC_SymbolTable__ConstDeclDesc);
  if (i2) goto l48;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 175549)))), &_td_OOC_SymbolTable__VarDeclDesc);
  if (i2) goto l46;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 175620)))), &_td_OOC_IR__GuardedVarDesc);
  if (i2) goto l40;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 175909)))), &_td_OOC_SymbolTable__TypeDeclDesc);
  if (i2) goto l38;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 175985)))), &_td_OOC_SymbolTable__PredefProcDesc);
  if (i2) goto l36;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 176063)))), &_td_OOC_SymbolTable__ProcDeclDesc);
  if (i2) goto l34;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 176141)))), &_td_OOC_SymbolTable__ImportDesc);
  if (i2) goto l32;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 176233)))), &_td_OOC_SymbolTable__RedirectDesc);
  if (i2) goto l22;
  Log__Type("Unknown decl in NewIdentRef", 28, (void*)i3);
  _assert(0u, 127, 176736);
  goto l51;
l22:
  i2 = (OOC_INT32)baseNS;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 176305))+48);
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 176282)))), OOC_SymbolTable__NamespaceDesc_Identify)),OOC_SymbolTable__NamespaceDesc_Identify)((OOC_SymbolTable__Namespace)i2, (OOC_SymbolTable__Item)i4, (OOC_SymbolTable__Name)i5, 0u);
  redirModule = (OOC_SymbolTable__Item)i2;
  i5 = i2==(OOC_INT32)0;
  if (i5) goto l25;
  i5 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 176372)))), &_td_OOC_SymbolTable__ImportDesc));
  
  goto l27;
l25:
  i5=1u;
l27:
  if (i5) goto l29;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 176485)))), &_td_OOC_SymbolTable__ImportDesc, 176485)), 176492))+52);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 176507))+48);
  ns = (OOC_SymbolTable__Namespace)i2;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 176625))+52);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 176631))+12);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 176625))+52);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 176631))+12);
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 176635)), 0);
  i0 = (OOC_INT32)OOC_Scanner_SymList__CloneSymbol((OOC_Scanner_SymList__Symbol)i0, (void*)(_check_pointer(i3, 176635)), i5);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 176532)))), OOC_IR__BuilderDesc_NewIdentRef)),OOC_IR__BuilderDesc_NewIdentRef)((OOC_IR__Builder)i1, (OOC_SymbolTable__Namespace)i2, (OOC_SymbolTable__Namespace)i2, (OOC_SymbolTable__Item)i4, (OOC_Scanner_SymList__Symbol)i0);
  return (OOC_IR__Expression)i0;
  goto l51;
l29:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 176405)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 41, (OOC_Scanner_SymList__Symbol)i0);
  goto l51;
l32:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 176201))+52);
  i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewModuleRef((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i0, (OOC_SymbolTable__Module)i2);
  return (OOC_IR__Expression)i0;
  goto l51;
l34:
  i0 = (OOC_INT32)OOC_IR__NewProcedureRef((OOC_Scanner_SymList__Symbol)i0, (OOC_SymbolTable__ProcDecl)i3);
  return (OOC_IR__Expression)i0;
  goto l51;
l36:
  i0 = (OOC_INT32)OOC_IR__NewPredefProc((OOC_Scanner_SymList__Symbol)i0, (OOC_SymbolTable__PredefProc)i3);
  return (OOC_IR__Expression)i0;
  goto l51;
l38:
  i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewTypeRef((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i0, (OOC_SymbolTable__TypeDecl)i3);
  return (OOC_IR__Expression)i0;
  goto l51;
l40:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 175654))+48);
  i4 = (OOC_INT32)OOC_SymbolTable_CreateNamespace__exception;
  i2 = i2==i4;
  if (i2) goto l43;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 175808))+48);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 175790)))), OOC_IR__BuilderDesc_NewVar)),OOC_IR__BuilderDesc_NewVar)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i0, (OOC_SymbolTable__VarDecl)i2);
  varRef = (OOC_IR__Var)i0;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 175846))+52);
  *(OOC_INT32*)((_check_pointer(i0, 175833))+4) = i2;
  return (OOC_IR__Expression)i0;
  goto l51;
l43:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 175744))+52);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 175713)))), OOC_IR__BuilderDesc_NewCurrentException)),OOC_IR__BuilderDesc_NewCurrentException)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i0, (OOC_SymbolTable__Type)i2);
  return (OOC_IR__Expression)i0;
  goto l51;
l46:
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 175584)))), OOC_IR__BuilderDesc_NewVar)),OOC_IR__BuilderDesc_NewVar)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i0, (OOC_SymbolTable__VarDecl)i3);
  return (OOC_IR__Expression)i0;
  goto l51;
l48:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 175526))+48);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 175514))+52);
  i0 = (OOC_INT32)OOC_IR__NewConst((OOC_Scanner_SymList__Symbol)i0, (OOC_SymbolTable__Type)i3, (Object_Boxed__Object)i2);
  return (OOC_IR__Expression)i0;
  goto l51;
l50:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 175361)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 1, (OOC_Scanner_SymList__Symbol)i0);
l51:
  i0=i1;
l52:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 177031))+20);
  return (OOC_IR__Expression)i0;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_NewQualident(OOC_IR__Builder b, OOC_SymbolTable__Namespace baseNS, OOC_IR__ModuleRef modref, OOC_SymbolTable__Item context, OOC_Scanner_SymList__Symbol name) {
  register OOC_INT32 i0,i1,i2,i3,i4;

  i0 = (OOC_INT32)modref;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 177316))+8);
  i1 = (OOC_INT32)b;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 177327)))), &_td_OOC_SymbolTable__ModuleDesc, 177327)), 177334))+48);
  i2 = (OOC_INT32)baseNS;
  i3 = (OOC_INT32)context;
  i4 = (OOC_INT32)name;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 177287)))), OOC_IR__BuilderDesc_NewIdentRef)),OOC_IR__BuilderDesc_NewIdentRef)((OOC_IR__Builder)i1, (OOC_SymbolTable__Namespace)i2, (OOC_SymbolTable__Namespace)i0, (OOC_SymbolTable__Item)i3, (OOC_Scanner_SymList__Symbol)i4);
  return (OOC_IR__Expression)i0;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_NewTypeVar(OOC_IR__Builder b, OOC_SymbolTable__Namespace baseNS, OOC_IR__TypeRef typeRef, OOC_SymbolTable__Item context, OOC_Scanner_SymList__Symbol name) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_SymbolTable__Type type;

  i0 = (OOC_INT32)typeRef;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 177625))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 177635)))), &_td_OOC_SymbolTable__TypeDeclDesc, 177635)), 177644))+48);
  type = (OOC_SymbolTable__Type)i0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 177663))+28);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l3;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 177780))+28);
  i1 = (OOC_INT32)b;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 177789))+24);
  i2 = (OOC_INT32)baseNS;
  i3 = (OOC_INT32)context;
  i4 = (OOC_INT32)name;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 177755)))), OOC_IR__BuilderDesc_NewIdentRef)),OOC_IR__BuilderDesc_NewIdentRef)((OOC_IR__Builder)i1, (OOC_SymbolTable__Namespace)i2, (OOC_SymbolTable__Namespace)i0, (OOC_SymbolTable__Item)i3, (OOC_Scanner_SymList__Symbol)i4);
  return (OOC_IR__Expression)i0;
  goto l4;
l3:
  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)name;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 177699)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i0, 1, (OOC_Scanner_SymList__Symbol)i1);
  return (OOC_IR__Expression)i0;
l4:
  _failed_function(177399); return 0;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_NewQualType(OOC_IR__Builder b, OOC_IR__Expression type, OOC_IR__ExpressionList arguments, OOC_Scanner_SymList__Symbol rParen) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10;
  OOC_SymbolTable__Type qualType;
  OOC_SymbolTable__TypeVarArray params;
  OOC_INT32 i;
  OOC_SymbolTable__Type t;

  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)type;
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 178124)))), OOC_IR__BuilderDesc_AssertType)),OOC_IR__BuilderDesc_AssertType)((OOC_IR__Builder)i0, (OOC_IR__Expression)i1);
  qualType = (OOC_SymbolTable__Type)i2;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 178159))+4);
  i3 = i3==(OOC_INT32)0;
  if (i3) goto l3;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 178914));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 178883)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 69, (OOC_Scanner_SymList__Symbol)i2);
  goto l31;
l3:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 178208)))), &_td_OOC_SymbolTable__QualTypeDesc, 178208)), 178217))+40);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 178226))+28);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 178235))+20);
  params = (OOC_SymbolTable__TypeVarArray)i3;
  i4 = (OOC_INT32)arguments;
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i3, 178264)), 0);
  i6 = OOC_ARRAY_LENGTH((_check_pointer(i4, 178282)), 0);
  i5 = i5<i6;
  if (i5) goto l29;
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i4, 178396)), 0);
  i6 = OOC_ARRAY_LENGTH((_check_pointer(i3, 178378)), 0);
  i5 = i6>i5;
  if (i5) goto l27;
  i = 0;
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i3, 178490)), 0);
  i6 = 0<i5;
  if (!i6) goto l31;
  i6 = (OOC_INT32)&_td_OOC_SymbolTable__TypeRef;
  i7=0;
l10_loop:
  i8 = _check_pointer(i4, 178521);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i8 = (OOC_INT32)*(OOC_INT32*)(i8+(_check_index(i7, i9, OOC_UINT32, 178521))*4);
  i8 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i8, 178525)))), &_td_OOC_IR__TypeRefDesc);
  if (!i8) goto l21;
  i8 = _check_pointer(i4, 178568);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i8 = (OOC_INT32)*(OOC_INT32*)(i8+(_check_index(i7, i9, OOC_UINT32, 178568))*4);
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i8, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i8, 178572)))), &_td_OOC_IR__TypeRefDesc, 178572)), 178580))+12);
  t = (OOC_SymbolTable__Type)i8;
  i9 = i8!=(OOC_INT32)0;
  if (i9) goto l15;
  i9=0u;
  goto l17;
l15:
  i9 = _check_pointer(i3, 178644);
  i10 = OOC_ARRAY_LENGTH(i9, 0);
  i9 = (OOC_INT32)*(OOC_INT32*)(i9+(_check_index(i7, i10, OOC_UINT32, 178644))*4);
  i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i9, 178647))+40);
  i9 = OOC_SymbolTable_TypeRules__IsExtensionOf((OOC_SymbolTable__Type)i8, (OOC_SymbolTable__Type)i9);
  
l17:
  if (i9) goto l19;
  i8 = _check_pointer(i4, 178801);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i8 = (OOC_INT32)*(OOC_INT32*)(i8+(_check_index(i7, i9, OOC_UINT32, 178801))*4);
  i8 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i8, 178804));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 178763)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 72, (OOC_Scanner_SymList__Symbol)i8);
  goto l21;
l19:
  i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 178703)))), &_td_OOC_SymbolTable__QualTypeDesc, 178703)), 178712))+48);
  i9 = OOC_ARRAY_LENGTH((_check_pointer(i9, 178722)), 0);
  i9 = _check_index(i7, i9, OOC_UINT32, 178722);
  i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 178703)))), &_td_OOC_SymbolTable__QualTypeDesc, 178703)), 178712))+48);
  i9 = _check_pointer(i9, 178722);
  i10 = OOC_ARRAY_LENGTH(i9, 0);
  OOC_SymbolTable__InitTypeRef((void*)(i9+(_check_index(i7, i10, OOC_UINT32, 178722))*8), (RT0__Struct)i6, (OOC_SymbolTable__Type)i8);
l21:
  i7 = i7+1;
  i = i7;
  i8 = i7<i5;
  if (i8) goto l10_loop;
  goto l31;
l27:
  i2 = (OOC_INT32)rParen;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 178414)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 70, (OOC_Scanner_SymList__Symbol)i2);
  goto l31;
l29:
  i2 = _check_pointer(i4, 178334);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 178345)), 0);
  i4 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i3, i4, OOC_UINT32, 178334))*4);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 178348));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 178300)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 71, (OOC_Scanner_SymList__Symbol)i2);
l31:
  return (OOC_IR__Expression)i1;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_NewSelect(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression var, OOC_SymbolTable__Item context, OOC_Scanner_SymList__Symbol name) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
  OOC_IR__Expression varRef;
  OOC_SymbolTable__Type type;
  OOC_SymbolTable__Name n;
  OOC_SymbolTable__Declaration decl;
  OOC_SymbolTable__ProcDecl procDecl;

  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)var;
  i2 = (OOC_INT32)b;
  OOC_IR__BuilderDesc_CheckFunctionOp((OOC_IR__Builder)i2, (OOC_IR__Expression)i1, (OOC_Scanner_SymList__Symbol)i0);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 179345))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 179345))+4);
  i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 179350)))), OOC_SymbolTable__TypeDesc_Bound)),OOC_SymbolTable__TypeDesc_Bound)((OOC_SymbolTable__Type)i4);
  i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 179359)))), &_td_OOC_SymbolTable__PointerDesc);
  if (i3) goto l3;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 179389))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 179389))+4);
  i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 179394)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i4);
  i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 179405)))), &_td_OOC_SymbolTable__PointerDesc);
  
  goto l5;
l3:
  i3=1u;
l5:
  if (i3) goto l7;
  varRef = (OOC_IR__Expression)i1;
  i3=i1;
  goto l8;
l7:
  i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 179443)))), OOC_IR__BuilderDesc_NewDeref)),OOC_IR__BuilderDesc_NewDeref)((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i0, (OOC_IR__Expression)i1);
  varRef = (OOC_IR__Expression)i3;
  
l8:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 179524))+4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 179524))+4);
  i4 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 179529)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i5);
  type = (OOC_SymbolTable__Type)i4;
  i5 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 179553)))), &_td_OOC_SymbolTable__RecordDesc);
  if (i5) goto l11;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 180274));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 180248)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i2, 20, (OOC_Scanner_SymList__Symbol)i0);
  return (OOC_IR__Expression)i0;
  goto l28;
l11:
  i5 = (OOC_INT32)name;
  i6 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 179584)))), OOC_IR__BuilderDesc_GetName)),OOC_IR__BuilderDesc_GetName)((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i5);
  n = (OOC_SymbolTable__Name)i6;
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 179623)))), &_td_OOC_SymbolTable__RecordDesc, 179623)), 179630))+52);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 179623)))), &_td_OOC_SymbolTable__RecordDesc, 179623)), 179630))+52);
  i8 = (OOC_INT32)context;
  i4 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 179633)))), OOC_SymbolTable__NamespaceDesc_Identify)),OOC_SymbolTable__NamespaceDesc_Identify)((OOC_SymbolTable__Namespace)i4, (OOC_SymbolTable__Item)i8, (OOC_SymbolTable__Name)i6, 0u);
  decl = (OOC_SymbolTable__Declaration)i4;
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 179686))+16);
  OOC_SymbolTable_Uses__Mark((OOC_SymbolTable__Declaration)i4, (OOC_SymbolTable_Uses__Uses)i7, (OOC_SymbolTable__Name)i6);
  i6 = i4==(OOC_INT32)0;
  if (i6) goto l26;
  i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 179796)))), &_td_OOC_SymbolTable__FieldDeclDesc);
  if (i6) goto l24;
  i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 179912)))), &_td_OOC_SymbolTable__ProcDeclDesc);
  if (i6) goto l18;
  _assert(0u, 127, 180198);
  goto l28;
l18:
  i4 = _type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 179963)))), &_td_OOC_SymbolTable__ProcDeclDesc, 179963);
  procDecl = (OOC_SymbolTable__ProcDecl)i4;
  i6 = *(OOC_INT8*)((_check_pointer(i4, 180088))+48);
  i6 = i6==2;
  if (i6) goto l21;
  i6 = *(OOC_UINT8*)((_check_pointer(i4, 180163))+51);
  
  goto l22;
l21:
  i6=1u;
l22:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 180023))+4);
  i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewSelectProc((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i0, (OOC_IR__Expression)i1, (OOC_SymbolTable__Type)i3, (OOC_SymbolTable__ProcDecl)i4, (OOC_Scanner_SymList__Symbol)i5, i6);
  return (OOC_IR__Expression)i0;
  goto l28;
l24:
  i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewSelectField((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i0, (OOC_IR__Expression)i3, (OOC_SymbolTable__FieldDecl)(_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 179875)))), &_td_OOC_SymbolTable__FieldDeclDesc, 179875)), (OOC_Scanner_SymList__Symbol)i5);
  return (OOC_IR__Expression)i0;
  goto l28;
l26:
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 179745)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i2, 1, (OOC_Scanner_SymList__Symbol)i5);
  return (OOC_IR__Expression)i0;
l28:
  _failed_function(178990); return 0;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_NewOperator(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression left, OOC_IR__Expression right) {
  register OOC_INT32 i0;
  OOC_INT8 id;
  auto OOC_CHAR8 OOC_IR__BuilderDesc_NewOperator_IsPredefClass(OOC_SymbolTable__Type type, OOC_UINT32 classes);
  auto OOC_IR__Expression OOC_IR__BuilderDesc_NewOperator_UnaryOperator(void);
  auto OOC_IR__Expression OOC_IR__BuilderDesc_NewOperator_BinaryOperator(void);
    
    OOC_CHAR8 OOC_IR__BuilderDesc_NewOperator_IsPredefClass(OOC_SymbolTable__Type type, OOC_UINT32 classes) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)type;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 181172)))), &_td_OOC_SymbolTable__PredefTypeDesc);
      if (i1) goto l3;
      return 0u;
      goto l4;
l3:
      i0 = *(OOC_INT16*)((_check_pointer(i0, 181209))+40);
      i1 = classes;
      return (_in(i0,i1));
l4:
      _failed_function(181093); return 0;
      ;
    }

    
    OOC_IR__Expression OOC_IR__BuilderDesc_NewOperator_UnaryOperator(void) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5;
      OOC_SymbolTable__Type type;
      OOC_CHAR8 isNumeric;
      OOC_CHAR8 isSet;
      OOC_CHAR8 isBoolean;

      i0 = (OOC_INT32)b;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 181422))+20);
      i2 = (OOC_INT32)left;
      i1 = i2==i1;
      if (i1) goto l3;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 181447))+20);
      i2 = (OOC_INT32)right;
      i1 = i2==i1;
      
      goto l5;
l3:
      i1=1u;
l5:
      if (i1) goto l28;
      i1 = (OOC_INT32)right;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 181697))+4);
      type = (OOC_SymbolTable__Type)i2;
      i3 = OOC_SymbolTable_TypeRules__IsNumericType((OOC_SymbolTable__Type)i2);
      isNumeric = i3;
      i4 = OOC_SymbolTable_TypeRules__IsSetType((OOC_SymbolTable__Type)i2);
      isSet = i4;
      i2 = OOC_IR__BuilderDesc_NewOperator_IsPredefClass((OOC_SymbolTable__Type)i2, 1u);
      isBoolean = i2;
      i5 = id;
      switch (i5) {
      case 7:
        if (i3) goto l14;
        if (i4) goto l12;
        i1 = (OOC_INT32)sym;
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 182119)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i0, 5, (OOC_Scanner_SymList__Symbol)i1);
        return (OOC_IR__Expression)i0;
        goto l29;
l12:
        i2 = (OOC_INT32)sym;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewNegate((OOC_IR__Builder)i0, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i1);
        return (OOC_IR__Expression)i0;
        goto l29;
l14:
        i2 = (OOC_INT32)sym;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewNegate((OOC_IR__Builder)i0, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i1);
        return (OOC_IR__Expression)i0;
        goto l29;
      case 6:
        if (i3) goto l19;
        i1 = (OOC_INT32)sym;
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 182260)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i0, 5, (OOC_Scanner_SymList__Symbol)i1);
        return (OOC_IR__Expression)i0;
        goto l29;
l19:
        return (OOC_IR__Expression)i1;
        goto l29;
      case 35:
        if (i2) goto l24;
        i1 = (OOC_INT32)sym;
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 182414)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i0, 5, (OOC_Scanner_SymList__Symbol)i1);
        return (OOC_IR__Expression)i0;
        goto l29;
l24:
        i2 = (OOC_INT32)sym;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewNot((OOC_IR__Builder)i0, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i1);
        return (OOC_IR__Expression)i0;
        goto l29;
      default:
        i1 = (OOC_INT32)sym;
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 182483)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i0, 6, (OOC_Scanner_SymList__Symbol)i1);
        return (OOC_IR__Expression)i0;
        goto l29;
      }
l28:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 181657))+20);
      return (OOC_IR__Expression)i0;
l29:
      _failed_function(181297); return 0;
      ;
    }

    
    OOC_IR__Expression OOC_IR__BuilderDesc_NewOperator_BinaryOperator(void) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9;
      OOC_SymbolTable__Type nil;
      OOC_SymbolTable__Type real;
      OOC_IR__Expression result;
      OOC_SymbolTable__Type leftType;
      OOC_SymbolTable__Type rightType;
      OOC_CHAR8 isNumeric;
      OOC_CHAR8 isInteger;
      OOC_CHAR8 isSet;
      OOC_CHAR8 isBoolean;
      OOC_CHAR8 isChar;
      OOC_INT8 variant;
      OOC_IR__ExpressionList exprList;
      auto OOC_CHAR8 OOC_IR__BuilderDesc_NewOperator_BinaryOperator_IsString(OOC_SymbolTable__Type type);
        
        OOC_CHAR8 OOC_IR__BuilderDesc_NewOperator_BinaryOperator_IsString(OOC_SymbolTable__Type type) {
          register OOC_INT32 i0,i1;

          i0 = (OOC_INT32)type;
          i1 = OOC_SymbolTable_TypeRules__IsStringConst((OOC_SymbolTable__Type)i0);
          if (i1) goto l7;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 182915)))), &_td_OOC_SymbolTable__ArrayDesc);
          if (i1) goto l5;
          i0=0u;
          goto l8;
l5:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 182955)))), &_td_OOC_SymbolTable__ArrayDesc, 182955)), 182961))+44);
          i0 = OOC_SymbolTable_TypeRules__IsCharType((OOC_SymbolTable__Type)i0);
          
          goto l8;
l7:
          i0=1u;
l8:
          return i0;
          ;
        }


      i0 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(16);
      nil = (OOC_SymbolTable__Type)i0;
      i1 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(8);
      real = (OOC_SymbolTable__Type)i1;
      result = (OOC_IR__Expression)(OOC_INT32)0;
      i2 = (OOC_INT32)b;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 183184))+20);
      i4 = (OOC_INT32)left;
      i3 = i4==i3;
      if (i3) goto l3;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 183209))+20);
      i5 = (OOC_INT32)right;
      i3 = i5==i3;
      
      goto l5;
l3:
      i3=1u;
l5:
      if (i3) goto l168;
      i3 = id;
      i5 = i3==15;
      if (i5) goto l9;
      i5=0u;
      goto l11;
l9:
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 183487))+4);
      i5 = OOC_SymbolTable_TypeRules__IsIntegerType((OOC_SymbolTable__Type)i5);
      
l11:
      if (i5) goto l13;
      i5=0u;
      goto l15;
l13:
      i5 = (OOC_INT32)right;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 183521))+4);
      i5 = OOC_SymbolTable_TypeRules__IsSetType((OOC_SymbolTable__Type)i5);
      
l15:
      if (i5) goto l166;
      i3 = i3==16;
      if (i3) goto l164;
      i2 = OOC_IR__BuilderDesc_WidenToCommon((OOC_IR__Builder)i2, (void*)(OOC_INT32)&left, (void*)(OOC_INT32)&right);
      if (i2) goto l33;
      i0 = (OOC_INT32)left;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 186599))+4);
      i1 = OOC_IR__BuilderDesc_NewOperator_BinaryOperator_IsString((OOC_SymbolTable__Type)i1);
      if (i1) goto l23;
      i1=0u;
      goto l25;
l23:
      i1 = (OOC_INT32)right;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 186622))+4);
      i1 = OOC_IR__BuilderDesc_NewOperator_BinaryOperator_IsString((OOC_SymbolTable__Type)i1);
      
l25:
      if (i1) goto l27;
      i0 = (OOC_INT32)b;
      i1 = (OOC_INT32)sym;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 186853)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i0, 7, (OOC_Scanner_SymList__Symbol)i1);
      
      goto l169;
l27:
      i1 = id;
      i1 = _in(i1,32256u);
      if (i1) goto l30;
      i0 = (OOC_INT32)b;
      i1 = (OOC_INT32)sym;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 186786)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i0, 5, (OOC_Scanner_SymList__Symbol)i1);
      
      goto l169;
l30:
      i1 = (OOC_INT32)right;
      i2 = (OOC_INT32)sym;
      i3 = (OOC_INT32)b;
      i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewCompare((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i0, (OOC_IR__Expression)i1);
      
      goto l169;
l33:
      i2 = (OOC_INT32)left;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 183726))+4);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 183726))+4);
      i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 183731)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i2);
      leftType = (OOC_SymbolTable__Type)i2;
      i3 = (OOC_INT32)right;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 183761))+4);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 183761))+4);
      i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 183766)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i3);
      rightType = (OOC_SymbolTable__Type)i3;
      i3 = OOC_SymbolTable_TypeRules__IsNumericType((OOC_SymbolTable__Type)i2);
      isNumeric = i3;
      i4 = OOC_SymbolTable_TypeRules__IsIntegerType((OOC_SymbolTable__Type)i2);
      isInteger = i4;
      i5 = OOC_SymbolTable_TypeRules__IsSetType((OOC_SymbolTable__Type)i2);
      isSet = i5;
      i6 = OOC_IR__BuilderDesc_NewOperator_IsPredefClass((OOC_SymbolTable__Type)i2, 1u);
      isBoolean = i6;
      i7 = OOC_SymbolTable_TypeRules__IsCharType((OOC_SymbolTable__Type)i2);
      isChar = i7;
      i8 = id;
      i9 = _in(i8,194u);
      if (i9) goto l36;
      i9=0u;
      goto l38;
l36:
      i9=i3;
l38:
      if (i9) goto l156;
      i9 = _in(i8,4u);
      if (i9) goto l42;
      i9=0u;
      goto l44;
l42:
      i9=i3;
l44:
      if (i9) goto l152;
      i1 = _in(i8,24u);
      if (i1) goto l48;
      i1=0u;
      goto l50;
l48:
      i1=i4;
l50:
      if (i1) goto l146;
      i1 = _in(i8,198u);
      if (i1) goto l54;
      i1=0u;
      goto l56;
l54:
      i1=i5;
l56:
      if (i1) goto l138;
      i1 = _in(i8,288u);
      if (i1) goto l60;
      i1=0u;
      goto l62;
l60:
      i1=i6;
l62:
      if (i1) goto l132;
      i1 = _in(i8,32256u);
      if (i1) goto l66;
      i4=0u;
      goto l68;
l66:
      i4 = (OOC_INT32)left;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 185653))+4);
      i4 = OOC_IR__BuilderDesc_NewOperator_BinaryOperator_IsString((OOC_SymbolTable__Type)i4);
      
l68:
      if (i4) goto l70;
      i4=0u;
      goto l72;
l70:
      i4 = (OOC_INT32)right;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 185676))+4);
      i4 = OOC_IR__BuilderDesc_NewOperator_BinaryOperator_IsString((OOC_SymbolTable__Type)i4);
      
l72:
      if (i4) goto l130;
      i4 = i8==6;
      if (i4) goto l76;
      i4=0u;
      goto l85;
l76:
      if (i7) goto l78;
      i4 = (OOC_INT32)left;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 185826))+4);
      i4 = OOC_SymbolTable_TypeRules__IsStringConst((OOC_SymbolTable__Type)i4);
      
      goto l80;
l78:
      i4=1u;
l80:
      if (i4) goto l82;
      i4 = (OOC_INT32)left;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 185865))+4);
      i4 = OOC_SymbolTable_TypeRules__IsSTRING((OOC_SymbolTable__Type)i4);
      
      goto l85;
l82:
      i4=1u;
l85:
      if (i4) goto l128;
      if (i1) goto l88;
      i1=0u;
      goto l93;
l88:
      if (i3) goto l90;
      i1=i7;
      goto l93;
l90:
      i1=1u;
l93:
      if (i1) goto l126;
      i1 = _in(i8,1536u);
      if (i1) goto l97;
      i0=0u;
      goto l122;
l97:
      if (i6) goto l99;
      i1=i5;
      goto l101;
l99:
      i1=1u;
l101:
      if (i1) goto l103;
      i1 = i2==i0;
      
      goto l105;
l103:
      i1=1u;
l105:
      if (i1) goto l107;
      i1 = (OOC_INT32)right;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 186294))+4);
      i0 = i1==i0;
      
      goto l109;
l107:
      i0=1u;
l109:
      if (i0) goto l111;
      i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 186335)))), &_td_OOC_SymbolTable__PointerDesc);
      
      goto l113;
l111:
      i0=1u;
l113:
      if (i0) goto l115;
      i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 186379)))), &_td_OOC_SymbolTable__TypeVarDesc);
      
      goto l117;
l115:
      i0=1u;
l117:
      if (i0) goto l119;
      i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 186423)))), &_td_OOC_SymbolTable__FormalParsDesc);
      
      goto l122;
l119:
      i0=1u;
l122:
      if (i0) goto l124;
      i0 = (OOC_INT32)b;
      i1 = (OOC_INT32)sym;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 186528)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i0, 5, (OOC_Scanner_SymList__Symbol)i1);
      
      goto l169;
l124:
      i0 = (OOC_INT32)right;
      i1 = (OOC_INT32)left;
      i2 = (OOC_INT32)sym;
      i3 = (OOC_INT32)b;
      i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewCompare((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i1, (OOC_IR__Expression)i0);
      
      goto l169;
l126:
      i0 = (OOC_INT32)right;
      i1 = (OOC_INT32)left;
      i2 = (OOC_INT32)sym;
      i3 = (OOC_INT32)b;
      i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewCompare((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i1, (OOC_IR__Expression)i0);
      
      goto l169;
l128:
      i0 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__ExpressionList.baseTypes[0], 2);
      exprList = (OOC_IR__ExpressionList)i0;
      i1 = _check_pointer(i0, 185920);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i3 = (OOC_INT32)left;
      *(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 185920))*4) = i3;
      i1 = _check_pointer(i0, 185949);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i3 = (OOC_INT32)right;
      *(OOC_INT32*)(i1+(_check_index(1, i2, OOC_UINT8, 185949))*4) = i3;
      i1 = (OOC_INT32)sym;
      i2 = (OOC_INT32)b;
      i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewConcat((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i1, (OOC_IR__ExpressionList)i0);
      
      goto l169;
l130:
      i0 = (OOC_INT32)right;
      i1 = (OOC_INT32)left;
      i2 = (OOC_INT32)sym;
      i3 = (OOC_INT32)b;
      i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewCompare((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i1, (OOC_IR__Expression)i0);
      
      goto l169;
l132:
      switch (i8) {
      case 5:
        variant = 20;
        goto l136;
      case 8:
        variant = 21;
        goto l136;
      default:
        _failed_case(i8, 185396);
        goto l136;
      }
l136:
      i0 = variant;
      i1 = (OOC_INT32)right;
      i2 = (OOC_INT32)left;
      i3 = (OOC_INT32)sym;
      i4 = (OOC_INT32)b;
      i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewBooleanOp((OOC_IR__Builder)i4, (OOC_Scanner_SymList__Symbol)i3, i0, (OOC_IR__Expression)i2, (OOC_IR__Expression)i1);
      
      goto l169;
l138:
      switch (i8) {
      case 6:
        variant = 6;
        goto l144;
      case 7:
        variant = 7;
        goto l144;
      case 1:
        variant = 8;
        goto l144;
      case 2:
        variant = 9;
        goto l144;
      default:
        _failed_case(i8, 185081);
        goto l144;
      }
l144:
      i0 = (OOC_INT32)b;
      i1 = variant;
      i2 = (OOC_INT32)right;
      i3 = (OOC_INT32)left;
      i4 = (OOC_INT32)sym;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 185288)))), OOC_IR__BuilderDesc_NewSetOp)),OOC_IR__BuilderDesc_NewSetOp)((OOC_IR__Builder)i0, (OOC_Scanner_SymList__Symbol)i4, i1, (OOC_IR__Expression)i3, (OOC_IR__Expression)i2);
      return (OOC_IR__Expression)i0;
      i0=(OOC_INT32)0;
      goto l169;
l146:
      switch (i8) {
      case 3:
        variant = 2;
        goto l150;
      case 4:
        variant = 5;
        goto l150;
      default:
        _failed_case(i8, 184785);
        goto l150;
      }
l150:
      i0 = variant;
      i1 = (OOC_INT32)right;
      i2 = (OOC_INT32)left;
      i3 = (OOC_INT32)sym;
      i4 = (OOC_INT32)b;
      i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewBinaryArith((OOC_IR__Builder)i4, (OOC_Scanner_SymList__Symbol)i3, i0, (OOC_IR__Expression)i2, (OOC_IR__Expression)i1);
      
      goto l169;
l152:
      if (!i4) goto l154;
      i0 = (OOC_INT32)b;
      i0 = OOC_IR__BuilderDesc_Widen((OOC_IR__Builder)i0, (void*)(OOC_INT32)&left, (OOC_SymbolTable__Type)i1);
      i0 = (OOC_INT32)b;
      i0 = OOC_IR__BuilderDesc_Widen((OOC_IR__Builder)i0, (void*)(OOC_INT32)&right, (OOC_SymbolTable__Type)i1);
l154:
      i0 = (OOC_INT32)right;
      i1 = (OOC_INT32)left;
      i2 = (OOC_INT32)sym;
      i3 = (OOC_INT32)b;
      i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewBinaryArith((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i2, 3, (OOC_IR__Expression)i1, (OOC_IR__Expression)i0);
      
      goto l169;
l156:
      switch (i8) {
      case 6:
        variant = 0;
        goto l161;
      case 7:
        variant = 1;
        goto l161;
      case 1:
        variant = 4;
        goto l161;
      default:
        _failed_case(i8, 184144);
        goto l161;
      }
l161:
      i0 = variant;
      i1 = (OOC_INT32)right;
      i2 = (OOC_INT32)left;
      i3 = (OOC_INT32)sym;
      i4 = (OOC_INT32)b;
      i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewBinaryArith((OOC_IR__Builder)i4, (OOC_Scanner_SymList__Symbol)i3, i0, (OOC_IR__Expression)i2, (OOC_IR__Expression)i1);
      
      goto l169;
l164:
      i0 = (OOC_INT32)right;
      i1 = (OOC_INT32)sym;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 183628)))), OOC_IR__BuilderDesc_NewTypeTest)),OOC_IR__BuilderDesc_NewTypeTest)((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i1, (OOC_IR__Expression)i4, (OOC_IR__Expression)i0);
      
      goto l169;
l166:
      i0 = (OOC_INT32)right;
      i1 = (OOC_INT32)sym;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 183550)))), OOC_IR__BuilderDesc_NewSetMember)),OOC_IR__BuilderDesc_NewSetMember)((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i1, (OOC_IR__Expression)i4, (OOC_IR__Expression)i0);
      
      goto l169;
l168:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 183429))+20);
      
l169:
      return (OOC_IR__Expression)i0;
      ;
    }


  i0 = (OOC_INT32)sym;
  i0 = *(OOC_INT8*)((_check_pointer(i0, 186959))+4);
  id = i0;
  i0 = (OOC_INT32)left;
  i0 = i0==(OOC_INT32)0;
  if (i0) goto l3;
  i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewOperator_BinaryOperator();
  return (OOC_IR__Expression)i0;
  goto l4;
l3:
  i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewOperator_UnaryOperator();
  return (OOC_IR__Expression)i0;
l4:
  _failed_function(180330); return 0;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_NewCall(OOC_IR__Builder b, OOC_IR__Expression design, OOC_IR__ExpressionList arguments, OOC_CHAR8 isFunctionCall, OOC_SymbolTable__Item context, OOC_Scanner_SymList__Symbol endOfArgsSym) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_SymbolTable__PredefProc predefProc;
  OOC_IR__Expression expr;
  OOC_SymbolTable__Type type;
  OOC_IR__Call call;
  OOC_IR__Expression receiver;
  OOC_SymbolTable__VarDeclArray formalPars;
  OOC_INT16 targetType;
  OOC_INT32 dim;
  OOC_INT32 dummy;
  OOC_INT8 op;
  OOC_IR__Expression delta;
  OOC_IR__Expression code;
  Object_Boxed__Object value;
  auto void OOC_IR__BuilderDesc_NewCall_MakeParameterCompatible(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression *arg, OOC_SymbolTable__VarDecl fpar, OOC_SymbolTable__Type fparType);
  auto void OOC_IR__BuilderDesc_NewCall_TransformArgs(OOC_Scanner_SymList__Symbol sym, OOC_Scanner_SymList__Symbol endOfArgsSym, OOC_SymbolTable__Type formalParsClosure, OOC_IR__Expression receiver, OOC_IR__ExpressionList *arguments, OOC_SymbolTable__VarDeclArray *argFormalPars);
  auto OOC_CHAR8 OOC_IR__BuilderDesc_NewCall_CheckNumberOfArguments(OOC_INT32 min, OOC_INT32 max);
  auto OOC_IR__Expression OOC_IR__BuilderDesc_NewCall_TranslatePredef(OOC_IR__PredefProc design, OOC_INT16 id);
  auto OOC_CHAR8 OOC_IR__BuilderDesc_NewCall_IsStatement(OOC_IR__Expression expr);
    
    void OOC_IR__BuilderDesc_NewCall_MakeParameterCompatible(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression *arg, OOC_SymbolTable__VarDecl fpar, OOC_SymbolTable__Type fparType) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_SymbolTable__Type argType;
      OOC_CHAR8 ok;

      i0 = (OOC_INT32)*arg;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 188142))+4);
      argType = (OOC_SymbolTable__Type)i0;
      i1 = (OOC_INT32)fpar;
      i2 = *(OOC_UINT8*)((_check_pointer(i1, 188163))+57);
      if (!i2) goto l4;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 188206)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
      argType = (OOC_SymbolTable__Type)i0;
      i2 = (OOC_INT32)fparType;
      i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 188246)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i2);
      fparType = (OOC_SymbolTable__Type)i2;
      
l4:
      i2 = *(OOC_UINT8*)((_check_pointer(i1, 188289))+63);
      if (i2) goto l7;
      i2=0u;
      goto l9;
l7:
      i2 = OOC_SymbolTable_TypeRules__IsPredefType((OOC_SymbolTable__Type)i0, 16);
      
l9:
      if (i2) goto l87;
      i2 = *(OOC_UINT8*)((_check_pointer(i1, 188495))+59);
      if (i2) goto l36;
      i2 = (OOC_INT32)fparType;
      i3 = OOC_SymbolTable_TypeRules__IsOpenArrayType((OOC_SymbolTable__Type)i2);
      if (i3) goto l23;
      i1 = *(OOC_UINT8*)((_check_pointer(i1, 190819))+57);
      if (i1) goto l17;
      i0=0u;
      goto l19;
l17:
      i0 = OOC_SymbolTable_TypeRules__IsExtensionOfNoParams((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i2);
      
l19:
      if (i0) goto l21;
      i0 = (OOC_INT32)b;
      i0 = OOC_IR__BuilderDesc_WidenForAssign((OOC_IR__Builder)i0, (void*)(OOC_INT32)arg, (OOC_SymbolTable__Type)i2);
      ok = i0;
      
      goto l32;
l21:
      ok = 1u;
      i0=1u;
      goto l32;
l23:
      i0 = OOC_SymbolTable_TypeRules__IsArrayCompatible((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i2);
      if (i0) goto l26;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 190698)))), &_td_OOC_SymbolTable__ArrayDesc, 190698)), 190704))+44);
      i0 = OOC_IR__IsPredefType((OOC_SymbolTable__Type)i0, 11);
      
      goto l28;
l26:
      i0=1u;
l28:
      if (i0) goto l30;
      i0 = (OOC_INT32)b;
      i0 = OOC_IR__BuilderDesc_Widen((OOC_IR__Builder)i0, (void*)(OOC_INT32)arg, (OOC_SymbolTable__Type)i2);
      
      goto l31;
l30:
      i0=1u;
l31:
      ok = i0;
      
l32:
      i0 = !i0;
      if (!i0) goto l87;
      i0 = (OOC_INT32)*arg;
      i1 = (OOC_INT32)b;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 191217));
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 191181)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 12, (OOC_Scanner_SymList__Symbol)i0);
      OOC_IR__BuilderDesc_SetNameToType((OOC_IR__Builder)i1, (OOC_SymbolTable__Type)i2);
      goto l87;
l36:
      i2 = (OOC_INT32)*arg;
      i3 = (OOC_INT32)b;
      OOC_IR__BuilderDesc_AssertVar((OOC_IR__Builder)i3, (OOC_IR__Expression)i2);
      i1 = *(OOC_UINT8*)((_check_pointer(i1, 188589))+57);
      if (i1) goto l39;
      i1=0u;
      goto l41;
l39:
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 188612)))), &_td_OOC_SymbolTable__PointerDesc);
      
l41:
      if (!i1) goto l44;
      i0 = (OOC_INT32)*arg;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 188737));
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 188723)))), OOC_IR__BuilderDesc_NewDeref)),OOC_IR__BuilderDesc_NewDeref)((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i1, (OOC_IR__Expression)i0);
      *arg = (OOC_IR__Expression)i0;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 188773))+4);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 188773))+4);
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 188778)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
      argType = (OOC_SymbolTable__Type)i0;
      
l44:
      i1 = (OOC_INT32)fparType;
      i2 = OOC_SymbolTable_TypeRules__SameType((OOC_SymbolTable__Type)i1, (OOC_SymbolTable__Type)i0);
      if (i2) goto l51;
      i2 = OOC_IR__IsPredefType((OOC_SymbolTable__Type)i1, 11);
      if (i2) goto l49;
      i2=0u;
      goto l53;
l49:
      i2 = OOC_SymbolTable_TypeRules__IsByteCompatible((OOC_SymbolTable__Type)i0);
      
      goto l53;
l51:
      i2=1u;
l53:
      if (i2) goto l59;
      i2 = OOC_IR__IsPredefType((OOC_SymbolTable__Type)i1, 12);
      if (i2) goto l57;
      i2=0u;
      goto l61;
l57:
      i2 = OOC_SymbolTable_TypeRules__IsPtrCompatible((OOC_SymbolTable__Type)i0);
      
      goto l61;
l59:
      i2=1u;
l61:
      if (i2) goto l67;
      i2 = OOC_SymbolTable_TypeRules__IsOpenArrayType((OOC_SymbolTable__Type)i1);
      if (i2) goto l65;
      i2=0u;
      goto l69;
l65:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 189131)))), &_td_OOC_SymbolTable__ArrayDesc, 189131)), 189137))+44);
      i2 = OOC_IR__IsPredefType((OOC_SymbolTable__Type)i2, 11);
      
      goto l69;
l67:
      i2=1u;
l69:
      if (i2) goto l87;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 189403)))), &_td_OOC_SymbolTable__RecordDesc);
      if (i2) goto l80;
      i2 = OOC_SymbolTable_TypeRules__IsOpenArrayType((OOC_SymbolTable__Type)i1);
      if (i2) goto l75;
      i0 = (OOC_INT32)*arg;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 190159));
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 190125)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i3, 40, (OOC_Scanner_SymList__Symbol)i0);
      OOC_IR__BuilderDesc_SetNameToType((OOC_IR__Builder)i3, (OOC_SymbolTable__Type)i1);
      goto l87;
l75:
      i0 = OOC_SymbolTable_TypeRules__IsArrayCompatible((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
      i0 = !i0;
      if (!i0) goto l87;
      i0 = (OOC_INT32)*arg;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 189990));
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 189956)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i3, 40, (OOC_Scanner_SymList__Symbol)i0);
      OOC_IR__BuilderDesc_SetNameToType((OOC_IR__Builder)i3, (OOC_SymbolTable__Type)i1);
      goto l87;
l80:
      i0 = OOC_SymbolTable_TypeRules__IsExtensionOfNoParams((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
      i0 = !i0;
      if (!i0) goto l87;
      i0 = (OOC_INT32)*arg;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 189655));
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 189621)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i3, 40, (OOC_Scanner_SymList__Symbol)i0);
      OOC_IR__BuilderDesc_SetNameToType((OOC_IR__Builder)i3, (OOC_SymbolTable__Type)i1);
l87:
      return;
      ;
    }

    
    void OOC_IR__BuilderDesc_NewCall_TransformArgs(OOC_Scanner_SymList__Symbol sym, OOC_Scanner_SymList__Symbol endOfArgsSym, OOC_SymbolTable__Type formalParsClosure, OOC_IR__Expression receiver, OOC_IR__ExpressionList *arguments, OOC_SymbolTable__VarDeclArray *argFormalPars) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
      ADT_ArrayList__ArrayList newArgs;
      ADT_ArrayList__ArrayList newFPars;
      OOC_INT32 argIndex;
      OOC_INT32 fparIndex;
      OOC_SymbolTable__Type fparType;
      OOC_SymbolTable__FormalPars formalPars;
      OOC_SymbolTable__VarDecl fpar;
      OOC_IR__Expression arg;
      OOC_SymbolTable__Type argType;
      OOC_INT32 i;
      auto OOC_INT32 OOC_IR__BuilderDesc_NewCall_TransformArgs_Dimensions(OOC_SymbolTable__Type type);
        
        OOC_INT32 OOC_IR__BuilderDesc_NewCall_TransformArgs_Dimensions(OOC_SymbolTable__Type type) {
          register OOC_INT32 i0,i1;

          i0 = (OOC_INT32)type;
          i1 = OOC_SymbolTable_TypeRules__IsStringConst((OOC_SymbolTable__Type)i0);
          if (i1) goto l7;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 192389)))), &_td_OOC_SymbolTable__ArrayDesc);
          if (i1) goto l5;
          return 0;
          goto l8;
l5:
          i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 192434)))), &_td_OOC_SymbolTable__ArrayDesc, 192434)), 192440)))), OOC_SymbolTable__TypeDesc_ArrayDimensions)),OOC_SymbolTable__TypeDesc_ArrayDimensions)((OOC_SymbolTable__Type)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 192434)))), &_td_OOC_SymbolTable__ArrayDesc, 192434)));
          return i0;
          goto l8;
l7:
          return 1;
l8:
          _failed_function(192259); return 0;
          ;
        }


      i0 = (OOC_INT32)*arguments;
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 192590)), 0);
      i1 = (OOC_INT32)ADT_ArrayList__New(i1);
      newArgs = (ADT_ArrayList__ArrayList)i1;
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 192642)), 0);
      i1 = (OOC_INT32)ADT_ArrayList__New(i1);
      newFPars = (ADT_ArrayList__ArrayList)i1;
      i1 = (OOC_INT32)receiver;
      i1 = i1!=(OOC_INT32)0;
      if (i1) goto l3;
      argIndex = 0;
      fparIndex = 0;
      i1=0;i2=0;
      goto l4;
l3:
      argIndex = (-1);
      fparIndex = (-1);
      i1=(-1);i2=(-1);
l4:
      i3 = (OOC_INT32)formalParsClosure;
      i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 192846)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i3);
      fparType = (OOC_SymbolTable__Type)i3;
      i3 = _type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 192891)))), &_td_OOC_SymbolTable__FormalParsDesc, 192891);
      formalPars = (OOC_SymbolTable__FormalPars)i3;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 192944))+52);
      i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 192952)), 0);
      i3 = i1!=i3;
      if (i3) goto l7;
      i0=0u;
      goto l9;
l7:
      i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 192996)), 0);
      i0 = i2!=i0;
      
l9:
      if (i0) goto l11;
      i0=i2;
      goto l61;
l11:
      i0=i2;
l12_loop:
      i2 = i0==(-1);
      if (i2) goto l15;
      i2 = (OOC_INT32)formalPars;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 193143))+52);
      i2 = _check_pointer(i2, 193151);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i1 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i1, i3, OOC_UINT32, 193151))*4);
      fpar = (OOC_SymbolTable__VarDecl)i1;
      i2 = (OOC_INT32)*arguments;
      i2 = _check_pointer(i2, 193190);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i0 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i0, i3, OOC_UINT32, 193190))*4);
      arg = (OOC_IR__Expression)i0;
      i0=i1;
      goto l16;
l15:
      i0 = (OOC_INT32)formalPars;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 193063))+40);
      fpar = (OOC_SymbolTable__VarDecl)i0;
      i1 = (OOC_INT32)receiver;
      arg = (OOC_IR__Expression)i1;
      
l16:
      i1 = (OOC_INT32)formalParsClosure;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 193335))+48);
      i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 193322)))), OOC_SymbolTable__TypeDesc_Closure)),OOC_SymbolTable__TypeDesc_Closure)((OOC_SymbolTable__Type)i1, (OOC_SymbolTable__Type)i2);
      i2 = (OOC_INT32)arg;
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 193254));
      i3 = (OOC_INT32)b;
      OOC_IR__BuilderDesc_NewCall_MakeParameterCompatible((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i2, (void*)(OOC_INT32)&arg, (OOC_SymbolTable__VarDecl)i0, (OOC_SymbolTable__Type)i1);
      i1 = *(OOC_UINT8*)((_check_pointer(i0, 193368))+60);
      if (i1) goto l19;
      i1=0u;
      goto l21;
l19:
      i1 = (OOC_INT32)arg;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 193421))+4);
      i1 = OOC_SymbolTable_TypeRules__IsPredefType((OOC_SymbolTable__Type)i1, 16);
      i1 = !i1;
      
l21:
      if (i1) goto l23;
      i1 = (OOC_INT32)newArgs;
      i2 = (OOC_INT32)arg;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 193776)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i1, (Object__Object)i2);
      goto l24;
l23:
      i1 = (OOC_INT32)b;
      i2 = (OOC_INT32)arg;
      i3 = (OOC_INT32)sym;
      i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 193724)))), OOC_IR__BuilderDesc_NewAdr)),OOC_IR__BuilderDesc_NewAdr)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i3, (OOC_IR__Expression)i2);
      i2 = (OOC_INT32)newArgs;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 193713)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i2, (Object__Object)i1);
l24:
      i1 = (OOC_INT32)newFPars;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 193821)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i1, (Object__Object)i0);
      i2 = *(OOC_UINT8*)((_check_pointer(i0, 193854))+64);
      if (!i2) goto l52;
      i2 = (OOC_INT32)arg;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 193900))+4);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 193900))+4);
      i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 193905)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i2);
      argType = (OOC_SymbolTable__Type)i2;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 193943))+48);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 193943))+48);
      i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 193948)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i4);
      fparType = (OOC_SymbolTable__Type)i3;
      i4 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 193983)))), &_td_OOC_SymbolTable__ArrayDesc);
      if (i4) goto l35;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 194967)))), &_td_OOC_SymbolTable__RecordDesc);
      if (!i2) goto l52;
      i0 = *(OOC_UINT8*)((_check_pointer(i0, 195002))+59);
      if (!i0) goto l52;
      i0 = (OOC_INT32)arg;
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 195069));
      i3 = (OOC_INT32)b;
      i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewTypeTag((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i0);
      i2 = (OOC_INT32)newArgs;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 195041)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i2, (Object__Object)i0);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 195105)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i1, (Object__Object)(OOC_INT32)0);
      goto l52;
l35:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 194035))+44);
      i0 = OOC_IR__IsPredefType((OOC_SymbolTable__Type)i0, 11);
      if (i0) goto l49;
      i0 = OOC_IR__BuilderDesc_NewCall_TransformArgs_Dimensions((OOC_SymbolTable__Type)i2);
      i1 = (OOC_INT32)fparType;
      i2 = OOC_SymbolTable__ArrayDesc_GetOpenDimensions((OOC_SymbolTable__Array)i1);
      i0 = i0>=i2;
      if (!i0) goto l52;
      i0 = OOC_SymbolTable__ArrayDesc_GetOpenDimensions((OOC_SymbolTable__Array)i1);
      i = 0;
      i1 = 0<i0;
      if (!i1) goto l52;
      i1 = (OOC_INT32)newFPars;
      i2 = (OOC_INT32)newArgs;
      i3=0;
l42_loop:
      i4 = (OOC_INT32)arg;
      i5 = (OOC_INT32)b;
      i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 194852));
      i4 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 194839)))), OOC_IR__BuilderDesc_NewLen)),OOC_IR__BuilderDesc_NewLen)((OOC_IR__Builder)i5, (OOC_Scanner_SymList__Symbol)i6, (OOC_IR__Expression)i4, i3);
      i5 = (OOC_INT32)b;
      i4 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 194830)))), OOC_IR__BuilderDesc_Fold)),OOC_IR__BuilderDesc_Fold)((OOC_IR__Builder)i5, (OOC_IR__Expression)i4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 194819)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i2, (Object__Object)i4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 194894)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i1, (Object__Object)(OOC_INT32)0);
      i3 = i3+1;
      i = i3;
      i4 = i3<i0;
      if (i4) goto l42_loop;
      goto l52;
l49:
      i0 = *(OOC_INT32*)((_check_pointer(i2, 194393))+32);
      i0 = (OOC_INT32)Object_BigInt__NewInt(i0);
      i2 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(6);
      i3 = (OOC_INT32)arg;
      i4 = (OOC_INT32)b;
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 194241));
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 194226)))), OOC_IR__BuilderDesc_NewConst)),OOC_IR__BuilderDesc_NewConst)((OOC_IR__Builder)i4, (OOC_Scanner_SymList__Symbol)i3, (OOC_SymbolTable__Type)i2, (Object_Boxed__Object)i0);
      i2 = (OOC_INT32)newArgs;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 194215)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i2, (Object__Object)i0);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 194425)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i1, (Object__Object)(OOC_INT32)0);
l52:
      i0 = argIndex;
      i0 = i0+1;
      i1 = fparIndex;
      argIndex = i0;
      i1 = i1+1;
      fparIndex = i1;
      i2 = (OOC_INT32)formalPars;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 192944))+52);
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 192952)), 0);
      i2 = i1!=i2;
      if (i2) goto l55;
      i2=0u;
      goto l57;
l55:
      i2 = (OOC_INT32)*arguments;
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 192996)), 0);
      i2 = i0!=i2;
      
l57:
      if (i2) goto l12_loop;
l61:
      i2 = (OOC_INT32)formalPars;
      i3 = (OOC_INT32)newArgs;
      i4 = *(OOC_UINT8*)((_check_pointer(i2, 195356))+56);
      if (!i4) goto l74;
      i4 = (OOC_INT32)*arguments;
      i5 = OOC_ARRAY_LENGTH((_check_pointer(i4, 195421)), 0);
      i5 = i0!=i5;
      if (!i5) goto l74;
      i5 = (OOC_INT32)newFPars;
      
l68_loop:
      i6 = _check_pointer(i4, 195454);
      i7 = OOC_ARRAY_LENGTH(i6, 0);
      i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i0, i7, OOC_UINT32, 195454))*4);
      arg = (OOC_IR__Expression)i6;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 195483)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i3, (Object__Object)i6);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 195517)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i5, (Object__Object)(OOC_INT32)0);
      i0 = i0+1;
      argIndex = i0;
      i6 = OOC_ARRAY_LENGTH((_check_pointer(i4, 195421)), 0);
      i6 = i0!=i6;
      if (i6) goto l68_loop;
l74:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 195627))+52);
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 195635)), 0);
      i1 = i1!=i2;
      if (i1) goto l80;
      i1 = (OOC_INT32)*arguments;
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i1, 195785)), 0);
      i2 = i0!=i2;
      if (!i2) goto l81;
      i1 = _check_pointer(i1, 195892);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i0 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(i0, i2, OOC_UINT32, 195892))*4);
      i1 = (OOC_INT32)b;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 195902));
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 195855)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 39, (OOC_Scanner_SymList__Symbol)i0);
      goto l81;
l80:
      i0 = (OOC_INT32)b;
      i1 = (OOC_INT32)endOfArgsSym;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 195705)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 38, (OOC_Scanner_SymList__Symbol)i1);
l81:
      i0 = *(OOC_INT32*)((_check_pointer(i3, 195957))+4);
      *arguments = (OOC_IR__ExpressionList)((OOC_INT32)RT0__NewObject(_td_OOC_IR__ExpressionList.baseTypes[0], i0));
      i0 = *(OOC_INT32*)((_check_pointer(i3, 195999))+4);
      *argFormalPars = (OOC_SymbolTable__VarDeclArray)((OOC_INT32)RT0__NewObject(_td_OOC_SymbolTable__VarDeclArray.baseTypes[0], i0));
      i0 = *(OOC_INT32*)((_check_pointer(i3, 196035))+4);
      i = 0;
      i1 = 0<i0;
      if (!i1) goto l93;
      i1 = (OOC_INT32)newFPars;
      i2=0;
l84_loop:
      i4 = (OOC_INT32)*arguments;
      i4 = _check_pointer(i4, 196064);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 196078));
      i6 = _check_pointer(i6, 196085);
      i7 = OOC_ARRAY_LENGTH(i6, 0);
      i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i2, i7, OOC_UINT32, 196085))*4);
      *(OOC_INT32*)(i4+(_check_index(i2, i5, OOC_UINT32, 196064))*4) = (_type_guard(i6, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 196089)))), &_td_OOC_IR__ExpressionDesc, 196089));
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 196122));
      i4 = _check_pointer(i4, 196129);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i2, i5, OOC_UINT32, 196129))*4);
      i4 = i4==(OOC_INT32)0;
      if (i4) goto l87;
      i4 = (OOC_INT32)*argFormalPars;
      i4 = _check_pointer(i4, 196216);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 196231));
      i6 = _check_pointer(i6, 196238);
      i7 = OOC_ARRAY_LENGTH(i6, 0);
      i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i2, i7, OOC_UINT32, 196238))*4);
      *(OOC_INT32*)(i4+(_check_index(i2, i5, OOC_UINT32, 196216))*4) = (_type_guard(i6, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 196246)))), &_td_OOC_SymbolTable__VarDeclDesc, 196246));
      goto l88;
l87:
      i4 = (OOC_INT32)*argFormalPars;
      i4 = _check_pointer(i4, 196168);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      *(OOC_INT32*)(i4+(_check_index(i2, i5, OOC_UINT32, 196168))*4) = (OOC_INT32)0;
l88:
      i2 = i2+1;
      i = i2;
      i4 = i2<i0;
      if (i4) goto l84_loop;
l93:
      return;
      ;
    }

    
    OOC_CHAR8 OOC_IR__BuilderDesc_NewCall_CheckNumberOfArguments(OOC_INT32 min, OOC_INT32 max) {
      register OOC_INT32 i0,i1,i2;

      i0 = (OOC_INT32)arguments;
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 196403)), 0);
      i2 = min;
      i1 = i1<i2;
      if (i1) goto l3;
      i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 196431)), 0);
      i1 = max;
      i0 = i0>i1;
      
      goto l5;
l3:
      i0=1u;
l5:
      if (i0) goto l7;
      return 1u;
      goto l8;
l7:
      i0 = (OOC_INT32)design;
      i1 = (OOC_INT32)b;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 196495));
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 196455)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 13, (OOC_Scanner_SymList__Symbol)i0);
      return 0u;
l8:
      _failed_function(196316); return 0;
      ;
    }

    
    OOC_IR__Expression OOC_IR__BuilderDesc_NewCall_TranslatePredef(OOC_IR__PredefProc design, OOC_INT16 id) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
      auto OOC_IR__ExpressionList OOC_IR__BuilderDesc_NewCall_TranslatePredef_StripFirst(OOC_IR__ExpressionList exprList);
        
        OOC_IR__ExpressionList OOC_IR__BuilderDesc_NewCall_TranslatePredef_StripFirst(OOC_IR__ExpressionList exprList) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
          OOC_IR__ExpressionList newList;
          OOC_INT32 i;

          i0 = (OOC_INT32)exprList;
          i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 196889)), 0);
          i1 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__ExpressionList.baseTypes[0], (i1-1));
          newList = (OOC_IR__ExpressionList)i1;
          i = 1;
          i2 = OOC_ARRAY_LENGTH((_check_pointer(i0, 196930)), 0);
          i3 = 1<i2;
          if (!i3) goto l8;
          i3=1;
l3_loop:
          i4 = _check_pointer(i1, 196955);
          i5 = OOC_ARRAY_LENGTH(i4, 0);
          i6 = _check_pointer(i0, 196972);
          i7 = OOC_ARRAY_LENGTH(i6, 0);
          i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i3, i7, OOC_UINT32, 196972))*4);
          *(OOC_INT32*)(i4+(_check_index((i3-1), i5, OOC_UINT32, 196955))*4) = i6;
          i3 = i3+1;
          i = i3;
          i4 = i3<i2;
          if (i4) goto l3_loop;
l8:
          return (OOC_IR__ExpressionList)i1;
          ;
        }


      i0 = id;
      switch (i0) {
      case 0:
        i0 = (OOC_INT32)arguments;
        i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 197151)), 0);
        i1 = i1>1;
        if (i1) goto l5;
        code = (OOC_IR__Expression)(OOC_INT32)0;
        goto l6;
l5:
        i0 = _check_pointer(i0, 197191);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(1, i1, OOC_UINT8, 197191))*4);
        code = (OOC_IR__Expression)i0;
l6:
        i0 = (OOC_INT32)design;
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 197373));
        i1 = *(OOC_INT32*)((_check_pointer(i1, 197378))+16);
        i2 = (OOC_INT32)OOC_Config_StdPragmas__assertions;
        i3 = (OOC_INT32)b;
        i1 = OOC_IR__GetPragmaValue((OOC_IR__Builder)i3, (Config_Section_Options__Option)i2, i1);
        i2 = (OOC_INT32)arguments;
        i2 = _check_pointer(i2, 197296);
        i3 = OOC_ARRAY_LENGTH(i2, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 197280));
        i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(0, i3, OOC_UINT8, 197296))*4);
        i3 = (OOC_INT32)code;
        i4 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewAssert((OOC_IR__Builder)i4, (OOC_Scanner_SymList__Symbol)i0, (OOC_IR__Expression)i2, (OOC_IR__Expression)i3, (!i1));
        return (OOC_IR__Expression)i0;
        goto l168;
      case 1:
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 197465);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i2 = (OOC_INT32)design;
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 197444));
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 197465))*4);
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewAssert((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)(OOC_INT32)0, (OOC_IR__Expression)i0, 0u);
        return (OOC_IR__Expression)i0;
        goto l168;
      case 22:
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 197640);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i2 = (OOC_INT32)design;
        i3 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(1, i1, OOC_UINT8, 197640))*4);
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 197624));
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 197608)))), OOC_IR__BuilderDesc_NewLen)),OOC_IR__BuilderDesc_NewLen)((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i1, (OOC_IR__Expression)i0, 0);
        i1 = (OOC_INT32)arguments;
        i3 = _check_pointer(i1, 197569);
        i4 = OOC_ARRAY_LENGTH(i3, 0);
        i1 = _check_pointer(i1, 197555);
        i5 = OOC_ARRAY_LENGTH(i1, 0);
        i6 = (OOC_INT32)b;
        i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(1, i4, OOC_UINT8, 197569))*4);
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i5, OOC_UINT8, 197555))*4);
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 197539));
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 197516)))), OOC_IR__BuilderDesc_NewCopyString)),OOC_IR__BuilderDesc_NewCopyString)((OOC_IR__Builder)i6, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i1, (OOC_IR__Expression)i3, (OOC_IR__Expression)i0);
        return (OOC_IR__Expression)i0;
        goto l168;
      case 21:
        i0 = (OOC_INT32)arguments;
        i1 = _check_pointer(i0, 197704);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 197704))*4);
        i0 = _check_pointer(i0, 197704);
        i2 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i2, OOC_UINT8, 197704))*4);
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 197707))+4);
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 197707))+4);
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 197712)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i1);
        type = (OOC_SymbolTable__Type)i0;
        i1 = (OOC_INT32)b;
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 197744))+24);
        i2 = i0==i2;
        if (i2) goto l29;
        i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 198181)))), &_td_OOC_SymbolTable__PointerDesc);
        if (i0) goto l14;
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 199086);
        i2 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i2, OOC_UINT8, 199086))*4);
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 199089));
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 199054)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 50, (OOC_Scanner_SymList__Symbol)i0);
        goto l37;
l14:
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 198233);
        i2 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i2, OOC_UINT8, 198233))*4);
        OOC_IR__BuilderDesc_AssertVar((OOC_IR__Builder)i1, (OOC_IR__Expression)i0);
        i0 = (OOC_INT32)type;
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 198266)))), &_td_OOC_SymbolTable__PointerDesc, 198266)), 198274))+40);
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 198266)))), &_td_OOC_SymbolTable__PointerDesc, 198266)), 198274))+40);
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 198283)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
        type = (OOC_SymbolTable__Type)i0;
        i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 198314)))), &_td_OOC_SymbolTable__ArrayDesc);
        if (i1) goto l23;
        i0 = OOC_SymbolTable_TypeRules__VariableInstance((OOC_SymbolTable__Type)i0);
        i0 = !i0;
        if (!i0) goto l19;
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 198766);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 198766))*4);
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 198769));
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 198727)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 56, (OOC_Scanner_SymList__Symbol)i0);
l19:
        i0 = OOC_IR__BuilderDesc_NewCall_CheckNumberOfArguments(1, 1);
        if (!i0) goto l37;
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 198981);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 198981))*4);
        i1 = (OOC_INT32)design;
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 198984))+4);
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 198966));
        i3 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewNewObject((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i2, (OOC_SymbolTable__Type)i0, (OOC_IR__ExpressionList)(OOC_INT32)0);
        i2 = (OOC_INT32)arguments;
        i2 = _check_pointer(i2, 198921);
        i3 = OOC_ARRAY_LENGTH(i2, 0);
        i4 = (OOC_INT32)b;
        i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(0, i3, OOC_UINT8, 198921))*4);
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 198906));
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 198865)))), OOC_IR__BuilderDesc_NewAssignment)),OOC_IR__BuilderDesc_NewAssignment)((OOC_IR__Builder)i4, (OOC_Scanner_SymList__Symbol)i1, (OOC_IR__Expression)i2, (OOC_IR__Expression)i0);
        return (OOC_IR__Expression)i0;
        goto l37;
l23:
        i0 = OOC_SymbolTable__ArrayDesc_GetOpenDimensions((OOC_SymbolTable__Array)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 198363)))), &_td_OOC_SymbolTable__ArrayDesc, 198363)));
        i0 = 1+i0;
        dim = i0;
        i0 = OOC_IR__BuilderDesc_NewCall_CheckNumberOfArguments(i0, i0);
        if (!i0) goto l37;
        i0 = (OOC_INT32)arguments;
        i1 = _check_pointer(i0, 198583);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 198583))*4);
        i2 = (OOC_INT32)design;
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 198586))+4);
        i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 198568));
        i4 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewNewObject((OOC_IR__Builder)i4, (OOC_Scanner_SymList__Symbol)i3, (OOC_SymbolTable__Type)i1, (OOC_IR__ExpressionList)i0);
        i1 = (OOC_INT32)arguments;
        i1 = _check_pointer(i1, 198523);
        i3 = OOC_ARRAY_LENGTH(i1, 0);
        i4 = (OOC_INT32)b;
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i3, OOC_UINT8, 198523))*4);
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 198508));
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 198467)))), OOC_IR__BuilderDesc_NewAssignment)),OOC_IR__BuilderDesc_NewAssignment)((OOC_IR__Builder)i4, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i1, (OOC_IR__Expression)i0);
        return (OOC_IR__Expression)i0;
        goto l37;
l29:
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 197787);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 197787))*4);
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 197791)))), &_td_OOC_IR__TypeRefDesc, 197791)), 197799))+12);
        type = (OOC_SymbolTable__Type)i0;
        i0 = OOC_SymbolTable_TypeRules__IsPointer((OOC_SymbolTable__Type)i0);
        if (i0) goto l32;
        i0=0u;
        goto l34;
l32:
        i0 = (OOC_INT32)type;
        i0 = (OOC_INT32)OOC_SymbolTable_TypeRules__PointerBaseType((OOC_SymbolTable__Type)i0);
        i0 = OOC_SymbolTable_TypeRules__VariableInstance((OOC_SymbolTable__Type)i0);
        i0 = !i0;
        
l34:
        if (!i0) goto l36;
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 197961);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 197961))*4);
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 197964));
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 197922)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 56, (OOC_Scanner_SymList__Symbol)i0);
l36:
        i0 = (OOC_INT32)endOfArgsSym;
        i1 = (OOC_INT32)context;
        i2 = (OOC_INT32)arguments;
        i2 = (OOC_INT32)OOC_IR__BuilderDesc_NewCall_TranslatePredef_StripFirst((OOC_IR__ExpressionList)i2);
        i3 = (OOC_INT32)arguments;
        i3 = _check_pointer(i3, 198041);
        i4 = OOC_ARRAY_LENGTH(i3, 0);
        i5 = (OOC_INT32)design;
        i6 = (OOC_INT32)b;
        i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(0, i4, OOC_UINT8, 198041))*4);
        i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 198026));
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 198004)))), OOC_IR__BuilderDesc_NewConstructor)),OOC_IR__BuilderDesc_NewConstructor)((OOC_IR__Builder)i6, (OOC_Scanner_SymList__Symbol)i4, (OOC_IR__Expression)i3, (OOC_IR__ExpressionList)i2, (OOC_SymbolTable__Item)i1, (OOC_Scanner_SymList__Symbol)i0);
        return (OOC_IR__Expression)i0;
l37:
        i0 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 199125))+20);
        return (OOC_IR__Expression)i0;
        goto l168;
      case 4:
      case 5:
        i0 = (OOC_INT32)arguments;
        i1 = _check_pointer(i0, 199196);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i0 = _check_pointer(i0, 199228);
        i3 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i3, OOC_UINT8, 199228))*4);
        i3 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_AssertInteger((OOC_IR__Builder)i3, (OOC_IR__Expression)i0);
        *(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 199196))*4) = i0;
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 199263);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 199263))*4);
        i1 = (OOC_INT32)b;
        OOC_IR__BuilderDesc_AssertVar((OOC_IR__Builder)i1, (OOC_IR__Expression)i0);
        i0 = (OOC_INT32)arguments;
        i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 199295)), 0);
        i1 = i1==1;
        if (i1) goto l41;
        i0 = _check_pointer(i0, 199413);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(1, i1, OOC_UINT8, 199413))*4);
        delta = (OOC_IR__Expression)i0;
        goto l42;
l41:
        i0 = _check_pointer(i0, 199360);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 199360))*4);
        i1 = (OOC_INT32)design;
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 199363))+4);
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 199344));
        i2 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_GetOne((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i1, (OOC_SymbolTable__Type)i0);
        delta = (OOC_IR__Expression)i0;
l42:
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 199466);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 199466))*4);
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 199469))+4);
        i1 = (OOC_INT32)b;
        i0 = OOC_IR__BuilderDesc_Widen((OOC_IR__Builder)i1, (void*)(OOC_INT32)&delta, (OOC_SymbolTable__Type)i0);
        if (i0) goto l45;
        i0 = (OOC_INT32)delta;
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 199856));
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 199828)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 5, (OOC_Scanner_SymList__Symbol)i0);
        i0 = (OOC_INT32)arguments;
        i1 = _check_pointer(i0, 199932);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i0 = _check_pointer(i0, 199918);
        i3 = OOC_ARRAY_LENGTH(i0, 0);
        i4 = (OOC_INT32)design;
        i5 = (OOC_INT32)b;
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 199932))*4);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i3, OOC_UINT8, 199918))*4);
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 199903));
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 199881)))), OOC_IR__BuilderDesc_NewAssignment)),OOC_IR__BuilderDesc_NewAssignment)((OOC_IR__Builder)i5, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i0, (OOC_IR__Expression)i1);
        return (OOC_IR__Expression)i0;
        goto l168;
l45:
        i0 = (OOC_INT32)design;
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 199501))+8);
        i1 = *(OOC_INT16*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 199512)))), &_td_OOC_SymbolTable__PredefProcDesc, 199512)), 199523))+48);
        i1 = i1==4;
        if (i1) goto l48;
        op = 1;
        i1=1;
        goto l49;
l48:
        op = 0;
        i1=0;
l49:
        i2 = (OOC_INT32)arguments;
        i2 = _check_pointer(i2, 199790);
        i3 = OOC_ARRAY_LENGTH(i2, 0);
        i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 199770));
        i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(0, i3, OOC_UINT8, 199790))*4);
        i3 = (OOC_INT32)b;
        i5 = (OOC_INT32)delta;
        i1 = (OOC_INT32)OOC_IR__BuilderDesc_NewBinaryArith((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i4, i1, (OOC_IR__Expression)i2, (OOC_IR__Expression)i5);
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 199672));
        i2 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewAssignOp((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i0, (OOC_IR__Expression)i1);
        return (OOC_IR__Expression)i0;
        goto l168;
      case 6:
      case 7:
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 200023);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 200023))*4);
        i1 = (OOC_INT32)b;
        OOC_IR__BuilderDesc_AssertVar((OOC_IR__Builder)i1, (OOC_IR__Expression)i0);
        i0 = (OOC_INT32)arguments;
        i1 = _check_pointer(i0, 200046);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i0 = _check_pointer(i0, 200074);
        i3 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i3, OOC_UINT8, 200074))*4);
        i3 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_AssertSet((OOC_IR__Builder)i3, (OOC_IR__Expression)i0);
        *(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 200046))*4) = i0;
        i0 = (OOC_INT32)arguments;
        i1 = _check_pointer(i0, 200097);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i0 = _check_pointer(i0, 200129);
        i3 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(1, i3, OOC_UINT8, 200129))*4);
        i3 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_AssertInteger((OOC_IR__Builder)i3, (OOC_IR__Expression)i0);
        *(OOC_INT32*)(i1+(_check_index(1, i2, OOC_UINT8, 200097))*4) = i0;
        i0 = (OOC_INT32)design;
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 200153))+8);
        i1 = *(OOC_INT16*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 200164)))), &_td_OOC_SymbolTable__PredefProcDesc, 200164)), 200175))+48);
        i1 = i1==6;
        if (i1) goto l54;
        op = 23;
        i1=23;
        goto l55;
l54:
        op = 22;
        i1=22;
l55:
        i2 = (OOC_INT32)arguments;
        i3 = _check_pointer(i2, 200467);
        i4 = OOC_ARRAY_LENGTH(i3, 0);
        i2 = _check_pointer(i2, 200453);
        i5 = OOC_ARRAY_LENGTH(i2, 0);
        i6 = (OOC_INT32)b;
        i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(1, i4, OOC_UINT8, 200467))*4);
        i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(0, i5, OOC_UINT8, 200453))*4);
        i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 200383));
        i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 200358)))), OOC_IR__BuilderDesc_NewChangeElement)),OOC_IR__BuilderDesc_NewChangeElement)((OOC_IR__Builder)i6, (OOC_Scanner_SymList__Symbol)i4, i1, (OOC_IR__Expression)i2, (OOC_IR__Expression)i3);
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 200320));
        i2 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewAssignOp((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i0, (OOC_IR__Expression)i1);
        return (OOC_IR__Expression)i0;
        goto l168;
      case 23:
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 200544);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i2 = (OOC_INT32)design;
        i3 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 200544))*4);
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 200529));
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 200513)))), OOC_IR__BuilderDesc_NewRaise)),OOC_IR__BuilderDesc_NewRaise)((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i1, (OOC_IR__Expression)i0);
        return (OOC_IR__Expression)i0;
        goto l168;
      case 2:
        i0 = (OOC_INT32)arguments;
        i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 200638)), 0);
        i1 = i1!=2;
        if (i1) goto l60;
        i1 = _check_pointer(i0, 200810);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 200810))*4);
        i0 = _check_pointer(i0, 200810);
        i2 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i2, OOC_UINT8, 200810))*4);
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 200813))+4);
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 200813))+4);
        i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 200819)))), OOC_SymbolTable__TypeDesc_ArrayDimensions)),OOC_SymbolTable__TypeDesc_ArrayDimensions)((OOC_SymbolTable__Type)i1);
        i1 = (OOC_INT32)arguments;
        i1 = _check_pointer(i1, 200757);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(1, i2, OOC_UINT8, 200757))*4);
        i2 = (OOC_INT32)b;
        i0 = OOC_IR__BuilderDesc_AssertIntConst((OOC_IR__Builder)i2, (OOC_IR__Expression)i1, 0, i0);
        dim = i0;
        goto l61;
l60:
        dim = 0;
l61:
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 200895);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 200895))*4);
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 200898))+4);
        i0 = OOC_SymbolTable_TypeRules__IsArray((OOC_SymbolTable__Type)i0);
        i0 = !i0;
        if (!i0) goto l64;
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 200995);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 200995))*4);
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 200998));
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 200966)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 15, (OOC_Scanner_SymList__Symbol)i0);
l64:
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 201076);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i2 = (OOC_INT32)design;
        i3 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 201076))*4);
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 201060));
        i2 = dim;
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 201044)))), OOC_IR__BuilderDesc_NewLen)),OOC_IR__BuilderDesc_NewLen)((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i1, (OOC_IR__Expression)i0, i2);
        return (OOC_IR__Expression)i0;
        goto l168;
      case 20:
      case 19:
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 201160);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i2 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 201160))*4);
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 201137)))), OOC_IR__BuilderDesc_AssertType)),OOC_IR__BuilderDesc_AssertType)((OOC_IR__Builder)i2, (OOC_IR__Expression)i0);
        type = (OOC_SymbolTable__Type)i0;
        i1 = (OOC_INT32)design;
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 201184))+8);
        i1 = *(OOC_INT16*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 201195)))), &_td_OOC_SymbolTable__PredefProcDesc, 201195)), 201206))+48);
        i1 = i1==20;
        if (i1) goto l68;
        i1 = (OOC_INT32)OOC_SymbolTable_Predef__GetMax((OOC_SymbolTable__Type)i0);
        value = (Object_Boxed__Object)i1;
        
        goto l69;
l68:
        i1 = (OOC_INT32)OOC_SymbolTable_Predef__GetMin((OOC_SymbolTable__Type)i0);
        value = (Object_Boxed__Object)i1;
        
l69:
        i2 = i1==(OOC_INT32)0;
        if (i2) goto l76;
        i2 = OOC_SymbolTable_TypeRules__IsSetType((OOC_SymbolTable__Type)i0);
        if (!i2) goto l75;
        i0 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(4);
        type = (OOC_SymbolTable__Type)i0;
        
l75:
        i2 = (OOC_INT32)arguments;
        i2 = _check_pointer(i2, 201609);
        i3 = OOC_ARRAY_LENGTH(i2, 0);
        i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(0, i3, OOC_UINT8, 201609))*4);
        i3 = (OOC_INT32)b;
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 201612));
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 201588)))), OOC_IR__BuilderDesc_NewConst)),OOC_IR__BuilderDesc_NewConst)((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i2, (OOC_SymbolTable__Type)i0, (Object_Boxed__Object)i1);
        return (OOC_IR__Expression)i0;
        goto l168;
l76:
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 201416);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 201416))*4);
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 201419));
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 201386)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i1, 18, (OOC_Scanner_SymList__Symbol)i0);
        return (OOC_IR__Expression)i0;
        goto l168;
      case 3:
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 201725);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i2 = (OOC_INT32)design;
        i3 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 201725))*4);
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 201709));
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 201692)))), OOC_IR__BuilderDesc_NewSize)),OOC_IR__BuilderDesc_NewSize)((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i1, (OOC_IR__Expression)i0);
        return (OOC_IR__Expression)i0;
        goto l168;
      case 8:
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 201799);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i2 = (OOC_INT32)design;
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 201783));
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 201799))*4);
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewAbs((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i0);
        return (OOC_IR__Expression)i0;
        goto l168;
      case 9:
        i0 = (OOC_INT32)arguments;
        i1 = _check_pointer(i0, 201896);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i0 = _check_pointer(i0, 201882);
        i3 = OOC_ARRAY_LENGTH(i0, 0);
        i4 = (OOC_INT32)design;
        i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 201866));
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(1, i2, OOC_UINT8, 201896))*4);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i3, OOC_UINT8, 201882))*4);
        i2 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewAsh((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i4, (OOC_IR__Expression)i0, (OOC_IR__Expression)i1);
        return (OOC_IR__Expression)i0;
        goto l168;
      case 10:
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 201992);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 201992))*4);
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_AssertChar((OOC_IR__Builder)i1, (OOC_IR__Expression)i0);
        i1 = (OOC_INT32)design;
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 201963));
        i2 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewCap((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i1, (OOC_IR__Expression)i0);
        return (OOC_IR__Expression)i0;
        goto l168;
      case 11:
        i0 = (OOC_INT32)arguments;
        i1 = _check_pointer(i0, 202042);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 202042))*4);
        i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 202046)))), &_td_OOC_IR__ConstDesc);
        if (i1) goto l85;
        i1=0u;
        goto l87;
l85:
        i1 = _check_pointer(i0, 202084);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 202084))*4);
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 202087))+4);
        i1 = OOC_SymbolTable_TypeRules__IsIntegerType((OOC_SymbolTable__Type)i1);
        
l87:
        if (i1) goto l102;
        i1 = _check_pointer(i0, 202207);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 202207))*4);
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 202210))+4);
        i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 202216)))), &_td_OOC_SymbolTable__PredefTypeDesc);
        if (i1) goto l91;
        i0 = _check_pointer(i0, 202954);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 202954))*4);
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 202957));
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 202922)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 5, (OOC_Scanner_SymList__Symbol)i0);
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 202990);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 202990))*4);
        return (OOC_IR__Expression)i0;
        goto l168;
l91:
        i1 = _check_pointer(i0, 202264);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 202264))*4);
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 202267))+4);
        i1 = *(OOC_INT16*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 202277)))), &_td_OOC_SymbolTable__PredefTypeDesc, 202277)), 202288))+40);
        switch (i1) {
        case 4:
          targetType = 5;
          
          goto l100;
        case 5:
          targetType = 6;
          
          goto l100;
        case 6:
          targetType = 7;
          
          goto l100;
        case 8:
          targetType = 9;
          
          goto l100;
        case 1:
          targetType = 2;
          
          goto l100;
        case 2:
          targetType = 3;
          
          goto l100;
        default:
          i0 = _check_pointer(i0, 202712);
          i1 = OOC_ARRAY_LENGTH(i0, 0);
          i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 202712))*4);
          i1 = (OOC_INT32)b;
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 202715));
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 202680)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 5, (OOC_Scanner_SymList__Symbol)i0);
          i0 = (OOC_INT32)arguments;
          i1 = _check_pointer(i0, 202750);
          i2 = OOC_ARRAY_LENGTH(i1, 0);
          i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 202750))*4);
          return (OOC_IR__Expression)i1;
          
          goto l100;
        }
l100:
        i0 = _check_pointer(i0, 202840);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i2 = targetType;
        i2 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(i2);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 202840))*4);
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewTypeConv((OOC_IR__Builder)i1, (OOC_SymbolTable__Type)i2, (OOC_IR__Expression)i0);
        return (OOC_IR__Expression)i0;
        goto l168;
l102:
        i0 = _check_pointer(i0, 202178);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 202178))*4);
        return (OOC_IR__Expression)i0;
        goto l168;
      case 12:
        i0 = (OOC_INT32)arguments;
        i1 = _check_pointer(i0, 203060);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 203060))*4);
        i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 203064)))), &_td_OOC_IR__ConstDesc);
        if (i1) goto l107;
        i1=0u;
        goto l109;
l107:
        i1 = _check_pointer(i0, 203102);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 203102))*4);
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 203105))+4);
        i1 = OOC_SymbolTable_TypeRules__IsIntegerType((OOC_SymbolTable__Type)i1);
        
l109:
        if (i1) goto l124;
        i1 = _check_pointer(i0, 203226);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 203226))*4);
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 203229))+4);
        i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 203235)))), &_td_OOC_SymbolTable__PredefTypeDesc);
        if (i1) goto l113;
        i0 = _check_pointer(i0, 203963);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 203963))*4);
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 203966));
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 203931)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 5, (OOC_Scanner_SymList__Symbol)i0);
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 203999);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 203999))*4);
        return (OOC_IR__Expression)i0;
        goto l168;
l113:
        i1 = _check_pointer(i0, 203283);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 203283))*4);
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 203286))+4);
        i1 = *(OOC_INT16*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 203296)))), &_td_OOC_SymbolTable__PredefTypeDesc, 203296)), 203307))+40);
        switch (i1) {
        case 5:
          targetType = 4;
          
          goto l122;
        case 6:
          targetType = 5;
          
          goto l122;
        case 7:
          targetType = 6;
          
          goto l122;
        case 9:
          targetType = 8;
          
          goto l122;
        case 2:
          targetType = 1;
          
          goto l122;
        case 3:
          targetType = 2;
          
          goto l122;
        default:
          i0 = _check_pointer(i0, 203721);
          i1 = OOC_ARRAY_LENGTH(i0, 0);
          i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 203721))*4);
          i1 = (OOC_INT32)b;
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 203724));
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 203689)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 5, (OOC_Scanner_SymList__Symbol)i0);
          i0 = (OOC_INT32)arguments;
          i1 = _check_pointer(i0, 203759);
          i2 = OOC_ARRAY_LENGTH(i1, 0);
          i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 203759))*4);
          return (OOC_IR__Expression)i1;
          
          goto l122;
        }
l122:
        i0 = _check_pointer(i0, 203849);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i2 = targetType;
        i2 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(i2);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 203849))*4);
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewTypeConv((OOC_IR__Builder)i1, (OOC_SymbolTable__Type)i2, (OOC_IR__Expression)i0);
        return (OOC_IR__Expression)i0;
        goto l168;
l124:
        i0 = _check_pointer(i0, 203197);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 203197))*4);
        return (OOC_IR__Expression)i0;
        goto l168;
      case 13:
        i0 = (OOC_INT32)arguments;
        i1 = _check_pointer(i0, 204063);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i0 = _check_pointer(i0, 204095);
        i3 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i3, OOC_UINT8, 204095))*4);
        i3 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_AssertInteger((OOC_IR__Builder)i3, (OOC_IR__Expression)i0);
        *(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 204063))*4) = i0;
        i0 = (OOC_INT32)arguments;
        i1 = _check_pointer(i0, 204122);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 204122))*4);
        i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 204126)))), &_td_OOC_IR__ConstDesc);
        if (!i1) goto l129;
        i0 = _check_pointer(i0, 204336);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 204336))*4);
        i1 = (OOC_INT32)b;
        i0 = OOC_IR__BuilderDesc_AssertIntConst((OOC_IR__Builder)i1, (OOC_IR__Expression)i0, 0, 256);
        dummy = i0;
l129:
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 204504);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i2 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(1);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 204504))*4);
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewTypeConv((OOC_IR__Builder)i1, (OOC_SymbolTable__Type)i2, (OOC_IR__Expression)i0);
        return (OOC_IR__Expression)i0;
        goto l168;
      case 14:
        i0 = (OOC_INT32)arguments;
        i1 = _check_pointer(i0, 204551);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i0 = _check_pointer(i0, 204583);
        i3 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i3, OOC_UINT8, 204583))*4);
        i3 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_AssertInteger((OOC_IR__Builder)i3, (OOC_IR__Expression)i0);
        *(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 204551))*4) = i0;
        i0 = (OOC_INT32)arguments;
        i1 = _check_pointer(i0, 204610);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 204610))*4);
        i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 204614)))), &_td_OOC_IR__ConstDesc);
        if (!i1) goto l133;
        i0 = _check_pointer(i0, 204824);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 204824))*4);
        i1 = (OOC_INT32)b;
        i0 = OOC_IR__BuilderDesc_AssertIntConst((OOC_IR__Builder)i1, (OOC_IR__Expression)i0, 0, 65536);
        dummy = i0;
l133:
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 205040);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i2 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(2);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 205040))*4);
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewTypeConv((OOC_IR__Builder)i1, (OOC_SymbolTable__Type)i2, (OOC_IR__Expression)i0);
        return (OOC_IR__Expression)i0;
        goto l168;
      case 15:
        i0 = (OOC_INT32)arguments;
        i1 = _check_pointer(i0, 205096);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i0 = _check_pointer(i0, 205128);
        i3 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i3, OOC_UINT8, 205128))*4);
        i3 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_AssertInteger((OOC_IR__Builder)i3, (OOC_IR__Expression)i0);
        *(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 205096))*4) = i0;
        i0 = (OOC_INT32)arguments;
        i1 = _check_pointer(i0, 205155);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 205155))*4);
        i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 205159)))), &_td_OOC_IR__ConstDesc);
        if (!i1) goto l137;
        i0 = _check_pointer(i0, 205369);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 205369))*4);
        i1 = (OOC_INT32)b;
        i0 = OOC_IR__BuilderDesc_AssertIntConst((OOC_IR__Builder)i1, (OOC_IR__Expression)i0, 0, 1114111);
        dummy = i0;
l137:
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 205630);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i2 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(3);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 205630))*4);
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewTypeConv((OOC_IR__Builder)i1, (OOC_SymbolTable__Type)i2, (OOC_IR__Expression)i0);
        return (OOC_IR__Expression)i0;
        goto l168;
      case 16:
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 205719);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i2 = (OOC_INT32)design;
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 205703));
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 205719))*4);
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewEntier((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i0);
        return (OOC_IR__Expression)i0;
        goto l168;
      case 17:
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 205802);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i2 = (OOC_INT32)design;
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 205786));
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 205802))*4);
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewOdd((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i0);
        return (OOC_IR__Expression)i0;
        goto l168;
      case 18:
        i0 = (OOC_INT32)arguments;
        i1 = _check_pointer(i0, 205858);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 205858))*4);
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 205861))+4);
        i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 205867)))), &_td_OOC_SymbolTable__PredefTypeDesc);
        if (i1) goto l143;
        i1=0u;
        goto l149;
l143:
        i1 = _check_pointer(i0, 205910);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 205910))*4);
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 205913))+4);
        i1 = *(OOC_INT16*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 205923)))), &_td_OOC_SymbolTable__PredefTypeDesc, 205923)), 205934))+40);
        i1 = i1==2;
        if (i1) goto l146;
        i1 = _check_pointer(i0, 205982);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 205982))*4);
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 205985))+4);
        i1 = *(OOC_INT16*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 205995)))), &_td_OOC_SymbolTable__PredefTypeDesc, 205995)), 206006))+40);
        i1 = i1==3;
        
        goto l149;
l146:
        i1=1u;
l149:
        if (i1) goto l151;
        targetType = 5;
        goto l152;
l151:
        targetType = 6;
l152:
        i0 = _check_pointer(i0, 206286);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 206286))*4);
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_AssertChar((OOC_IR__Builder)i1, (OOC_IR__Expression)i0);
        i1 = targetType;
        i1 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(i1);
        i2 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewTypeConv((OOC_IR__Builder)i2, (OOC_SymbolTable__Type)i1, (OOC_IR__Expression)i0);
        return (OOC_IR__Expression)i0;
        goto l168;
      case 26:
        i0 = (OOC_INT32)arguments;
        i1 = _check_pointer(i0, 206468);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i3 = _check_pointer(i0, 206454);
        i4 = OOC_ARRAY_LENGTH(i3, 0);
        i0 = _check_pointer(i0, 206440);
        i5 = OOC_ARRAY_LENGTH(i0, 0);
        i6 = (OOC_INT32)design;
        i7 = (OOC_INT32)b;
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(2, i2, OOC_UINT8, 206468))*4);
        i2 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(1, i4, OOC_UINT8, 206454))*4);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i5, OOC_UINT8, 206440))*4);
        i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i6, 206392));
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 206370)))), OOC_IR__BuilderDesc_NewMoveBlock)),OOC_IR__BuilderDesc_NewMoveBlock)((OOC_IR__Builder)i7, (OOC_Scanner_SymList__Symbol)i3, (OOC_IR__Expression)i0, (OOC_IR__Expression)i2, (OOC_IR__Expression)i1);
        return (OOC_IR__Expression)i0;
        goto l168;
      case 27:
        i0 = (OOC_INT32)arguments;
        i1 = _check_pointer(i0, 206530);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 206530))*4);
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 206533))+4);
        i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 206539)))), &_td_OOC_SymbolTable__PointerDesc);
        if (i1) goto l157;
        i1 = _check_pointer(i0, 206593);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 206593))*4);
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 206596))+4);
        i1 = OOC_SymbolTable_TypeRules__IsPredefType((OOC_SymbolTable__Type)i1, 12);
        
        goto l159;
l157:
        i1=1u;
l159:
        if (i1) goto l161;
        i0 = _check_pointer(i0, 206904);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 206904))*4);
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 206907));
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 206872)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 50, (OOC_Scanner_SymList__Symbol)i0);
        goto l162;
l161:
        i0 = _check_pointer(i0, 206651);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 206651))*4);
        i1 = (OOC_INT32)b;
        OOC_IR__BuilderDesc_AssertVar((OOC_IR__Builder)i1, (OOC_IR__Expression)i0);
        i0 = (OOC_INT32)arguments;
        i1 = _check_pointer(i0, 206684);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 206684))*4);
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 206687))+4);
        type = (OOC_SymbolTable__Type)i1;
        i1 = _check_pointer(i0, 206841);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i0 = _check_pointer(i0, 206822);
        i3 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i3, OOC_UINT8, 206822))*4);
        i3 = (OOC_INT32)design;
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 206825))+4);
        i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 206807));
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(1, i2, OOC_UINT8, 206841))*4);
        i2 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewNewBlock((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i4, (OOC_SymbolTable__Type)i0, (OOC_IR__Expression)i1);
        i1 = (OOC_INT32)arguments;
        i1 = _check_pointer(i1, 206765);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i4 = (OOC_INT32)b;
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 206765))*4);
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 206749));
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 206712)))), OOC_IR__BuilderDesc_NewAssignment)),OOC_IR__BuilderDesc_NewAssignment)((OOC_IR__Builder)i4, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i1, (OOC_IR__Expression)i0);
        return (OOC_IR__Expression)i0;
l162:
        i0 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 206943))+20);
        return (OOC_IR__Expression)i0;
        goto l168;
      case 24:
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 207135);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i2 = (OOC_INT32)design;
        i3 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 207135))*4);
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 207120));
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 207106)))), OOC_IR__BuilderDesc_NewAdr)),OOC_IR__BuilderDesc_NewAdr)((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i1, (OOC_IR__Expression)i0);
        i1 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(6);
        i2 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewTypeConv((OOC_IR__Builder)i2, (OOC_SymbolTable__Type)i1, (OOC_IR__Expression)i0);
        return (OOC_IR__Expression)i0;
        goto l168;
      case 25:
        i0 = (OOC_INT32)arguments;
        i1 = _check_pointer(i0, 207227);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i0 = _check_pointer(i0, 207213);
        i3 = OOC_ARRAY_LENGTH(i0, 0);
        i4 = (OOC_INT32)design;
        i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 207197));
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(1, i2, OOC_UINT8, 207227))*4);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i3, OOC_UINT8, 207213))*4);
        i2 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewShift((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i4, (OOC_IR__Expression)i0, (OOC_IR__Expression)i1, 0u);
        return (OOC_IR__Expression)i0;
        goto l168;
      case 29:
        i0 = (OOC_INT32)arguments;
        i1 = _check_pointer(i0, 207336);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i0 = _check_pointer(i0, 207322);
        i3 = OOC_ARRAY_LENGTH(i0, 0);
        i4 = (OOC_INT32)design;
        i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 207306));
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(1, i2, OOC_UINT8, 207336))*4);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i3, OOC_UINT8, 207322))*4);
        i2 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewTypeCast((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i4, (OOC_IR__Expression)i0, (OOC_IR__Expression)i1);
        return (OOC_IR__Expression)i0;
        goto l168;
      case 28:
        i0 = (OOC_INT32)arguments;
        i1 = _check_pointer(i0, 207435);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i0 = _check_pointer(i0, 207421);
        i3 = OOC_ARRAY_LENGTH(i0, 0);
        i4 = (OOC_INT32)design;
        i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 207405));
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(1, i2, OOC_UINT8, 207435))*4);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i3, OOC_UINT8, 207421))*4);
        i2 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewShift((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i4, (OOC_IR__Expression)i0, (OOC_IR__Expression)i1, 1u);
        return (OOC_IR__Expression)i0;
        goto l168;
      default:
        _failed_case(i0, 197057);
        goto l168;
      }
l168:
      _failed_function(196613); return 0;
      ;
    }

    
    OOC_CHAR8 OOC_IR__BuilderDesc_NewCall_IsStatement(OOC_IR__Expression expr) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)expr;
      i1 = i0==(OOC_INT32)0;
      if (i1) goto l3;
      i1 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(17);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 207633))+4);
      i0 = i0==i1;
      
      goto l4;
l3:
      i0=1u;
l4:
      return i0;
      ;
    }


  i0 = (OOC_INT32)design;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 207718)))), &_td_OOC_IR__PredefProcDesc);
  if (i1) goto l51;
  i1 = (OOC_INT32)b;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 208437))+20);
  i2 = i0==i2;
  if (i2) goto l49;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 208577))+4);
  i2 = OOC_SymbolTable_TypeRules__IsValidReceiverType((OOC_SymbolTable__Type)i2);
  if (i2) goto l7;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 208607))+4);
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 208613)))), &_td_OOC_SymbolTable__TypeVarDesc);
  
  goto l9;
l7:
  i2=1u;
l9:
  if (i2) goto l11;
  i2=0u;
  goto l13;
l11:
  i2 = (OOC_INT32)arguments;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 208658)), 0);
  i2 = i2==1;
  
l13:
  if (i2) goto l15;
  i2=0u;
  goto l17;
l15:
  i2 = (OOC_INT32)arguments;
  i2 = _check_pointer(i2, 208678);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(0, i3, OOC_UINT8, 208678))*4);
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 208682)))), &_td_OOC_IR__TypeRefDesc);
  
l17:
  if (i2) goto l47;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 208838))+24);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 208829))+4);
  i2 = i3==i2;
  if (i2) goto l45;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 208937))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 208937))+4);
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 208942)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i3);
  i2 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 208953)))), &_td_OOC_SymbolTable__FormalParsDesc));
  if (i2) goto l43;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 209065))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 209065))+4);
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 209070)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i3);
  type = (OOC_SymbolTable__Type)i2;
  i3 = isFunctionCall;
  if (i3) goto l25;
  i4=0u;
  goto l27;
l25:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 209120)))), &_td_OOC_SymbolTable__FormalParsDesc, 209120)), 209131))+44);
  i4 = i4==0;
  
l27:
  if (i4) goto l41;
  i3 = !i3;
  if (i3) goto l31;
  i2=0u;
  goto l33;
l31:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 209262)))), &_td_OOC_SymbolTable__FormalParsDesc, 209262)), 209273))+44);
  i2 = i2!=0;
  
l33:
  if (i2) goto l39;
  call = (OOC_IR__Call)((OOC_INT32)RT0__NewObject(_td_OOC_IR__Call.baseTypes[0]));
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 209417)))), &_td_OOC_IR__SelectProcDesc);
  if (i1) goto l37;
  receiver = (OOC_IR__Expression)0;
  i1=0;
  goto l38;
l37:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 209468)))), &_td_OOC_IR__SelectProcDesc, 209468)), 209479))+8);
  receiver = (OOC_IR__Expression)i1;
  
l38:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 209606))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 209580));
  i3 = (OOC_INT32)endOfArgsSym;
  OOC_IR__BuilderDesc_NewCall_TransformArgs((OOC_Scanner_SymList__Symbol)i0, (OOC_Scanner_SymList__Symbol)i3, (OOC_SymbolTable__Type)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&arguments, (void*)(OOC_INT32)&formalPars);
  i0 = (OOC_INT32)formalPars;
  i1 = (OOC_INT32)arguments;
  i2 = (OOC_INT32)design;
  i3 = (OOC_INT32)call;
  OOC_IR__InitCall((OOC_IR__Call)i3, (OOC_IR__Expression)i2, (OOC_IR__ExpressionList)i1, (OOC_SymbolTable__VarDeclArray)i0);
  return (OOC_IR__Expression)i3;
  goto l70;
l39:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 209353));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 209315)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i1, 36, (OOC_Scanner_SymList__Symbol)i0);
  return (OOC_IR__Expression)i0;
  goto l70;
l41:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 209212));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 209173)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i1, 37, (OOC_Scanner_SymList__Symbol)i0);
  return (OOC_IR__Expression)i0;
  goto l70;
l43:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 209024));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 208993)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i1, 35, (OOC_Scanner_SymList__Symbol)i0);
  return (OOC_IR__Expression)i0;
  goto l70;
l45:
  i2 = (OOC_INT32)endOfArgsSym;
  i3 = (OOC_INT32)arguments;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 208870)))), OOC_IR__BuilderDesc_NewQualType)),OOC_IR__BuilderDesc_NewQualType)((OOC_IR__Builder)i1, (OOC_IR__Expression)i0, (OOC_IR__ExpressionList)i3, (OOC_Scanner_SymList__Symbol)i2);
  return (OOC_IR__Expression)i0;
  goto l70;
l47:
  i2 = (OOC_INT32)arguments;
  i3 = _check_pointer(i2, 208795);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(0, i4, OOC_UINT8, 208795))*4);
  i2 = _check_pointer(i2, 208738);
  i4 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(0, i4, OOC_UINT8, 208738))*4);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 208741));
  i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewTypeGuard((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i0, (OOC_IR__TypeRef)(_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 208799)))), &_td_OOC_IR__TypeRefDesc, 208799)));
  return (OOC_IR__Expression)i0;
  goto l70;
l49:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 208471))+20);
  return (OOC_IR__Expression)i0;
  goto l70;
l51:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 207760))+8);
  i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 207771)))), &_td_OOC_SymbolTable__PredefProcDesc, 207771);
  predefProc = (OOC_SymbolTable__PredefProc)i0;
  i1 = *(OOC_INT16*)((_check_pointer(i0, 207849))+52);
  i0 = *(OOC_INT16*)((_check_pointer(i0, 207828))+50);
  i0 = OOC_IR__BuilderDesc_NewCall_CheckNumberOfArguments(i0, i1);
  i0 = !i0;
  if (!i0) goto l54;
  i0 = (OOC_INT32)b;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 208065))+20);
  return (OOC_IR__Expression)i0;
l54:
  i0 = (OOC_INT32)predefProc;
  i0 = *(OOC_INT16*)((_check_pointer(i0, 208137))+48);
  i1 = (OOC_INT32)design;
  i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewCall_TranslatePredef((OOC_IR__PredefProc)i1, i0);
  expr = (OOC_IR__Expression)i0;
  i1 = isFunctionCall;
  if (i1) goto l57;
  i2=0u;
  goto l59;
l57:
  i2 = OOC_IR__BuilderDesc_NewCall_IsStatement((OOC_IR__Expression)i0);
  
l59:
  if (i2) goto l68;
  i1 = !i1;
  if (i1) goto l63;
  i1=0u;
  goto l65;
l63:
  i1 = OOC_IR__BuilderDesc_NewCall_IsStatement((OOC_IR__Expression)i0);
  i1 = !i1;
  
l65:
  if (!i1) goto l69;
  i1 = (OOC_INT32)design;
  i2 = (OOC_INT32)b;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 208363));
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 208325)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i2, 36, (OOC_Scanner_SymList__Symbol)i1);
  return (OOC_IR__Expression)i1;
  goto l69;
l68:
  i1 = (OOC_INT32)design;
  i2 = (OOC_INT32)b;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 208247));
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 208208)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i2, 37, (OOC_Scanner_SymList__Symbol)i1);
  return (OOC_IR__Expression)i1;
l69:
  return (OOC_IR__Expression)i0;
l70:
  _failed_function(187115); return 0;
  ;
}

void OOC_OOC_IR_init(void) {
  register OOC_INT32 i0;
  _c0 = Object__NewLatin1Region("", 1, 0, 0);
  _c1 = Object__NewLatin1Region("NIL", 4, 0, 3);
  _c2 = Object__NewLatin1Char(97u);

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__ErrorContext.baseTypes[0]);
  OOC_IR__irContext = (OOC_IR__ErrorContext)i0;
  OOC_Error__InitContext((OOC_Error__Context)i0, "OOC:IR", 7);
  return;
  ;
}

void OOC_OOC_IR_destroy(void) {
}

/* --- */
