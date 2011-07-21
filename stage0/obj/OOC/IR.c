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
  i1 = (OOC_INT32)Object_Boxed__NewLongReal(1.0000000000000000);
  v = (Object_Boxed__LongReal)i1;
  i2 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(8);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 60285));
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
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 60661))+4);
  i1 = OOC_SymbolTable_TypeRules__IsNumericType((OOC_SymbolTable__Type)i1);
  i1 = !i1;
  if (!i1) goto l6;
  i1 = (OOC_INT32)b;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 60691))+20);
  i2 = i0!=i2;
  if (!i2) goto l5;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 60741));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 60717)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 44, (OOC_Scanner_SymList__Symbol)i2);
l5:
  i1 = (OOC_INT32)Object_BigInt__NewInt(1);
  v = (Object_BigInt__BigInt)i1;
  i2 = (OOC_INT32)OOC_SymbolTable_Predef__SmallestIntType((Object_BigInt__BigInt)i1);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 60814));
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
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 61175))+4);
  i1 = OOC_SymbolTable_TypeRules__IsCharType((OOC_SymbolTable__Type)i1);
  i1 = !i1;
  if (!i1) goto l6;
  i1 = (OOC_INT32)b;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 61205))+20);
  i2 = i0!=i2;
  if (!i2) goto l5;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 61257));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 61231)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 45, (OOC_Scanner_SymList__Symbol)i2);
l5:
  i1 = (OOC_INT32)Object_Boxed__NewString((Object__String)((OOC_INT32)_c2));
  v = (Object_Boxed__String)i1;
  i2 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(1);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 61334));
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
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 61660))+4);
  i1 = OOC_SymbolTable_TypeRules__IsSetType((OOC_SymbolTable__Type)i1);
  i1 = !i1;
  if (!i1) goto l6;
  i1 = (OOC_INT32)b;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 61690))+20);
  i2 = i0!=i2;
  if (!i2) goto l5;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 61736));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 61716)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 49, (OOC_Scanner_SymList__Symbol)i2);
l5:
  i1 = (OOC_INT32)Object_Boxed__NewSet(0u);
  v = (Object_Boxed__Set)i1;
  i2 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(10);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 61809));
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
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 62050))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 62050))+8);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 62055)), 0);
  i1 = (OOC_INT32)Object_Boxed__ParseLongRealLiteral((void*)(_check_pointer(i2, 62055)), i1);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 62088)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 3, (OOC_Scanner_SymList__Symbol)i0);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 62136))+20);
  return (OOC_IR__Expression)i0;
l4:
  _failed_function(61914); return 0;
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
          _failed_function(62486); return 0;
          ;
        }

        
        OOC_CHAR8 OOC_IR__BuilderDesc_NewCharConst16_ValueOf_HexToInt(const OOC_CHAR8 str__ref[], OOC_LEN str_0d, OOC_CHAR8 end, OOC_INT32 *result) {
          register OOC_INT32 i0,i1,i2,i3;
          OOC_ALLOCATE_VPAR(str,OOC_CHAR8 ,str_0d)

          OOC_INITIALIZE_VPAR(str__ref,str,OOC_CHAR8 ,str_0d)
          *result = 0;
          i = 0;
          i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT32, 62880)));
          i1 = end;
          i0 = i0!=i1;
          if (!i0) goto l11;
          i0=0;
l3_loop:
          i2 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 62936)));
          i2 = OOC_IR__BuilderDesc_NewCharConst16_ValueOf_HexDigit(i2);
          i3 = *result;
          i2 = ((2147483647-i2)>>4)<i3;
          if (!i2) goto l6;
          return 0u;
l6:
          i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 63047)));
          i0 = OOC_IR__BuilderDesc_NewCharConst16_ValueOf_HexDigit(i0);
          *result = ((i3*16)+i0);
          i0 = i;
          i0 = i0+1;
          i = i0;
          i2 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 62880)));
          i2 = i2!=i1;
          if (i2) goto l3_loop;
l11:
          return 1u;
          ;
        }


      i = 0;
      hexCount = 0;
      i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT32, 63184)));
      i0 = i0!=0u;
      if (i0) goto l3;
      i0=0;i1=0;
      goto l13;
l3:
      i0=0;i1=0;
l4_loop:
      i2 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 63222)));
      i2 = OOC_IR__BuilderDesc_NewCharConst16_ValueOf_HexDigit(i2);
      i2 = i2>=0;
      if (!i2) goto l8;
      i1 = i1+1;
      hexCount = i1;
      
l8:
      i0 = i0+1;
      i = i0;
      i2 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, str_0d, OOC_UINT32, 63184)));
      i2 = i2!=0u;
      if (i2) goto l4_loop;
l13:
      i2 = i0==3;
      if (i2) goto l16;
      i2=0u;
      goto l18;
l16:
      i2 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT8, 63326)));
      i3 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index((i0-1), str_0d, OOC_UINT32, 63335)));
      i2 = i2==i3;
      
l18:
      if (i2) goto l20;
      i2=0u;
      goto l26;
l20:
      i2 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT8, 63349)));
      i2 = i2==34u;
      if (i2) goto l23;
      i2 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, str_0d, OOC_UINT8, 63367)));
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
      i2 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index((i0-1), str_0d, OOC_UINT32, 63497)));
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
      i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(1, str_0d, OOC_UINT8, 63465)));
      return i0;
l53:
      _failed_function(62377); return 0;
      ;
    }


  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 63964))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 63964))+8);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 63969)), 0);
  i0 = OOC_IR__BuilderDesc_NewCharConst16_ValueOf((void*)(_check_pointer(i0, 63969)), i1);
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
  i0 = (OOC_INT32)Object_Boxed__NewString((Object__String)i0);
  i1 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(i1);
  i2 = (OOC_INT32)sym;
  i0 = (OOC_INT32)OOC_IR__NewConst((OOC_Scanner_SymList__Symbol)i2, (OOC_SymbolTable__Type)i1, (Object_Boxed__Object)i0);
  return (OOC_IR__Expression)i0;
  goto l12;
l11:
  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)sym;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 64000)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 4, (OOC_Scanner_SymList__Symbol)i1);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 64051))+20);
  return (OOC_IR__Expression)i0;
l12:
  _failed_function(62263); return 0;
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
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 64800)))), OOC_IR__BuilderDesc_AssertType)),OOC_IR__BuilderDesc_AssertType)((OOC_IR__Builder)i0, (OOC_IR__Expression)i1);
  t = (OOC_SymbolTable__Type)i2;
  i3 = *(OOC_INT32*)((_check_pointer(i2, 64828))+32);
  i3 = i3<0;
  if (i3) goto l3;
  i1 = *(OOC_INT32*)((_check_pointer(i2, 64924))+32);
  size = i1;
  
  goto l4;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 64876));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 64851)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 47, (OOC_Scanner_SymList__Symbol)i1);
  size = 1;
  i1=1;
l4:
  i1 = (OOC_INT32)Object_BigInt__NewInt(i1);
  i2 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(6);
  i3 = (OOC_INT32)sym;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 64952)))), OOC_IR__BuilderDesc_NewConst)),OOC_IR__BuilderDesc_NewConst)((OOC_IR__Builder)i0, (OOC_Scanner_SymList__Symbol)i3, (OOC_SymbolTable__Type)i2, (Object_Boxed__Object)i1);
  return (OOC_IR__Expression)i0;
  ;
}

OOC_IR__Const OOC_IR__BuilderDesc_GetOne(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)Object_BigInt__NewInt(1);
  i1 = (OOC_INT32)b;
  i2 = (OOC_INT32)sym;
  i3 = (OOC_INT32)type;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 65139)))), OOC_IR__BuilderDesc_NewConst)),OOC_IR__BuilderDesc_NewConst)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i2, (OOC_SymbolTable__Type)i3, (Object_Boxed__Object)i0);
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
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 65893));
      i3 = (OOC_INT32)min;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 65879)))), OOC_IR__BuilderDesc_NewConst)),OOC_IR__BuilderDesc_NewConst)((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i1, (OOC_SymbolTable__Type)i0, (Object_Boxed__Object)i3);
      return (OOC_IR__Expression)i0;
      ;
    }


  i0 = (OOC_INT32)set;
  i1 = (OOC_INT32)OOC_SymbolTable_Predef__GetMin((OOC_SymbolTable__Type)i0);
  val = (Object_Boxed__Object)i1;
  i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 66014)))), &_td_Object_BigInt__BigIntDesc, 66014);
  min = (Object_BigInt__BigInt)i1;
  i0 = (OOC_INT32)OOC_SymbolTable_Predef__GetMax((OOC_SymbolTable__Type)i0);
  val = (Object_Boxed__Object)i0;
  i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 66072)))), &_td_Object_BigInt__BigIntDesc, 66072);
  max = (Object_BigInt__BigInt)i0;
  i2 = (OOC_INT32)b;
  i3 = (OOC_INT32)expr;
  i3 = (OOC_INT32)OOC_IR__BuilderDesc_AssertInteger((OOC_IR__Builder)i2, (OOC_IR__Expression)i3);
  expr = (OOC_IR__Expression)i3;
  i4 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 66131)))), &_td_OOC_IR__ConstDesc);
  if (!i4) goto l10;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 66163))+8);
  i4 = _type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 66177)))), &_td_Object_BigInt__BigIntDesc, 66177);
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
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 66293));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 66258)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i2, 14, (OOC_Scanner_SymList__Symbol)i3);
  i1 = Object_BigInt__BigIntDesc_ToLongInt((Object_BigInt__BigInt)i1);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 66310))+36);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 66310))+36);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 66321)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i4, "start", 6, i1);
  i0 = Object_BigInt__BigIntDesc_ToLongInt((Object_BigInt__BigInt)i0);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 66373))+36);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 66373))+36);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 66384)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i2, "end", 4, (i0+1));
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
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 66977))+4);
  i2 = (OOC_INT32)abs;
  i3 = (OOC_INT32)sym;
  OOC_IR__InitOperator((OOC_IR__Operator)i2, (OOC_Scanner_SymList__Symbol)i3, (OOC_SymbolTable__Type)i1);
  *(OOC_INT32*)((_check_pointer(i2, 66993))+8) = i0;
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 67362)))), OOC_IR__VisitorDesc_VisitAbs)),OOC_IR__VisitorDesc_VisitAbs)((OOC_IR__Visitor)i0, (OOC_IR__Abs)i1);
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
  *(OOC_INT32*)((_check_pointer(i1, 67633))+8) = i0;
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
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 67951)))), &_td_OOC_IR__VarDesc);
      if (i1) goto l30;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 67969)))), &_td_OOC_IR__DerefDesc);
      if (i1) goto l28;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 67989)))), &_td_OOC_IR__IndexDesc);
      if (i1) goto l26;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 68009)))), &_td_OOC_IR__SelectFieldDesc);
      if (i1) goto l24;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 68035)))), &_td_OOC_IR__TypeGuardDesc);
      if (i1) goto l22;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 68059)))), &_td_OOC_IR__ProcedureRefDesc);
      if (i1) goto l20;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 68086)))), &_td_OOC_IR__ConstDesc);
      if (i1) goto l15;
      hasAddress = 0u;
      i0=0u;
      goto l31;
l15:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 68126))+4);
      i1 = OOC_SymbolTable_TypeRules__IsCharType((OOC_SymbolTable__Type)i1);
      if (!i1) goto l18;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 68198))+4);
      i0 = (OOC_INT32)OOC_SymbolTable_TypeRules__MatchingStringConst((OOC_SymbolTable__Type)i0);
      i1 = (OOC_INT32)b;
      i0 = OOC_IR__BuilderDesc_Widen((OOC_IR__Builder)i1, (void*)(OOC_INT32)&expr, (OOC_SymbolTable__Type)i0);
      dummy = i0;
l18:
      i0 = (OOC_INT32)expr;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 68263))+4);
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
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 68385));
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 68357)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 51, (OOC_Scanner_SymList__Symbol)i0);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 68685)))), OOC_IR__VisitorDesc_VisitAdr)),OOC_IR__VisitorDesc_VisitAdr)((OOC_IR__Visitor)i0, (OOC_IR__Adr)i1);
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
  *(OOC_INT32*)((_check_pointer(i1, 68964))+8) = i0;
  i0 = (OOC_INT32)exp;
  *(OOC_INT32*)((_check_pointer(i1, 68989))+12) = i0;
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 69373)))), OOC_IR__VisitorDesc_VisitAsh)),OOC_IR__VisitorDesc_VisitAsh)((OOC_IR__Visitor)i0, (OOC_IR__Ash)i1);
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
  *(OOC_INT8*)((_check_pointer(i2, 69683))+8) = i0;
  i0 = (OOC_INT32)left;
  *(OOC_INT32*)((_check_pointer(i2, 69710))+12) = i0;
  i0 = (OOC_INT32)right;
  *(OOC_INT32*)((_check_pointer(i2, 69731))+16) = i0;
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
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 69969))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 69957))+4);
  i3 = OOC_SymbolTable_TypeRules__SameType((OOC_SymbolTable__Type)i4, (OOC_SymbolTable__Type)i3);
  _assert(i3, 127, 69934);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 70034))+4);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 70239)))), OOC_IR__VisitorDesc_VisitBinaryArith)),OOC_IR__VisitorDesc_VisitBinaryArith)((OOC_IR__Visitor)i0, (OOC_IR__BinaryArith)i1);
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
  *(OOC_INT8*)((_check_pointer(i2, 70550))+8) = i0;
  i0 = (OOC_INT32)left;
  *(OOC_INT32*)((_check_pointer(i2, 70577))+12) = i0;
  i0 = (OOC_INT32)right;
  *(OOC_INT32*)((_check_pointer(i2, 70598))+16) = i0;
  return;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_NewBooleanOp(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_INT8 variant, OOC_IR__Expression left, OOC_IR__Expression right) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_IR__BooleanOp op;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__BooleanOp.baseTypes[0]);
  op = (OOC_IR__BooleanOp)i0;
  i1 = (OOC_INT32)left;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 70807))+4);
  i2 = *(OOC_INT16*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 70818)))), &_td_OOC_SymbolTable__PredefTypeDesc, 70818)), 70829))+40);
  _assert((i2==0), 127, 70795);
  i2 = (OOC_INT32)right;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 70870))+4);
  i3 = *(OOC_INT16*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 70881)))), &_td_OOC_SymbolTable__PredefTypeDesc, 70881)), 70892))+40);
  _assert((i3==0), 127, 70857);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 70970))+4);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 71165)))), OOC_IR__VisitorDesc_VisitBooleanOp)),OOC_IR__VisitorDesc_VisitBooleanOp)((OOC_IR__Visitor)i0, (OOC_IR__BooleanOp)i1);
  return;
  ;
}

static void OOC_IR__InitCap(OOC_IR__Cap cap, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression expr) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)expr;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 71406))+4);
  i2 = (OOC_INT32)cap;
  i3 = (OOC_INT32)sym;
  OOC_IR__InitOperator((OOC_IR__Operator)i2, (OOC_Scanner_SymList__Symbol)i3, (OOC_SymbolTable__Type)i1);
  *(OOC_INT32*)((_check_pointer(i2, 71422))+8) = i0;
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 71779)))), OOC_IR__VisitorDesc_VisitCap)),OOC_IR__VisitorDesc_VisitCap)((OOC_IR__Visitor)i0, (OOC_IR__Cap)i1);
  return;
  ;
}

static void OOC_IR__InitChangeElement(OOC_IR__ChangeElement ch, OOC_Scanner_SymList__Symbol sym, OOC_INT8 variant, OOC_IR__Expression set, OOC_IR__Expression element) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)set;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 72097))+4);
  i2 = (OOC_INT32)ch;
  i3 = (OOC_INT32)sym;
  OOC_IR__InitOperator((OOC_IR__Operator)i2, (OOC_Scanner_SymList__Symbol)i3, (OOC_SymbolTable__Type)i1);
  i1 = variant;
  *(OOC_INT8*)((_check_pointer(i2, 72112))+8) = i1;
  *(OOC_INT32*)((_check_pointer(i2, 72140))+12) = i0;
  i0 = (OOC_INT32)element;
  *(OOC_INT32*)((_check_pointer(i2, 72160))+16) = i0;
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 72677)))), OOC_IR__VisitorDesc_VisitChangeElement)),OOC_IR__VisitorDesc_VisitChangeElement)((OOC_IR__Visitor)i0, (OOC_IR__ChangeElement)i1);
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
  *(OOC_INT32*)((_check_pointer(i1, 72993))+12) = i0;
  i0 = (OOC_INT32)right;
  *(OOC_INT32*)((_check_pointer(i1, 73014))+16) = i0;
  i0 = variant;
  *(OOC_INT8*)((_check_pointer(i1, 73037))+8) = i0;
  return;
  ;
}

OOC_IR__Compare OOC_IR__BuilderDesc_NewCompare(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression left, OOC_IR__Expression right) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT8 variant;

  i0 = (OOC_INT32)sym;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 73280))+4);
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
    _failed_case(i1, 73272);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 73749)))), OOC_IR__VisitorDesc_VisitCompare)),OOC_IR__VisitorDesc_VisitCompare)((OOC_IR__Visitor)i0, (OOC_IR__Compare)i1);
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
  *(OOC_INT32*)((_check_pointer(i2, 74049))+8) = i0;
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
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 74321)), 0);
  i2 = (OOC_INT32)sym;
  i3 = 0<i1;
  if (i3) goto l3;
  i1=(-1);
  goto l28;
l3:
  i3 = (OOC_INT32)b;
  i4=0;i5=(-1);
l4_loop:
  i6 = _check_pointer(i0, 74350);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i4, i7, OOC_UINT32, 74350))*4);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 74353))+4);
  type = (OOC_SymbolTable__Type)i6;
  tid = 32767;
  i7 = OOC_SymbolTable_TypeRules__IsStringConst((OOC_SymbolTable__Type)i6);
  if (i7) goto l18;
  i7 = OOC_SymbolTable_TypeRules__IsCharType((OOC_SymbolTable__Type)i6);
  if (i7) goto l12;
  i6 = OOC_SymbolTable_TypeRules__IsSTRING((OOC_SymbolTable__Type)i6);
  i6 = !i6;
  if (!i6) goto l11;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 74844)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i3, 7, (OOC_Scanner_SymList__Symbol)i2);
l11:
  i6=32767;
  goto l19;
l12:
  i6 = (OOC_INT32)OOC_SymbolTable_TypeRules__MatchingStringConst((OOC_SymbolTable__Type)i6);
  i7 = _check_pointer(i0, 74602);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i6 = OOC_IR__BuilderDesc_Widen((OOC_IR__Builder)i3, (void*)(i7+(_check_index(i4, i8, OOC_UINT32, 74602))*4), (OOC_SymbolTable__Type)i6);
  if (i6) goto l15;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 74719)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i3, 7, (OOC_Scanner_SymList__Symbol)i2);
  i6=32767;
  goto l19;
l15:
  i6 = _check_pointer(i0, 74666);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i4, i7, OOC_UINT32, 74666))*4);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 74669))+4);
  i6 = *(OOC_INT16*)((_check_pointer((_type_guard(i6, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 74679)))), &_td_OOC_SymbolTable__PredefTypeDesc, 74679)), 74690))+40);
  tid = i6;
  
  goto l19;
l18:
  i6 = *(OOC_INT16*)((_check_pointer((_type_guard(i6, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 74481)))), &_td_OOC_SymbolTable__PredefTypeDesc, 74481)), 74492))+40);
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
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 75159))+32);
  type = (OOC_SymbolTable__Type)i3;
  i = 0;
  i4 = OOC_ARRAY_LENGTH((_check_pointer(i0, 75203)), 0);
  i5 = 0<i4;
  if (!i5) goto l41;
  i5=0;
l33_loop:
  i6 = _check_pointer(i0, 75246);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i5, i7, OOC_UINT32, 75246))*4);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 75249))+4);
  i6 = OOC_SymbolTable_TypeRules__IsStringConst((OOC_SymbolTable__Type)i6);
  if (!i6) goto l36;
  i6 = _check_pointer(i0, 75354);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = OOC_IR__BuilderDesc_Widen((OOC_IR__Builder)i1, (void*)(i6+(_check_index(i5, i7, OOC_UINT32, 75354))*4), (OOC_SymbolTable__Type)i3);
  dummy = i6;
  _assert(i6, 127, 75376);
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
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i0, 75049)), 0);
  i4 = 0<i3;
  if (!i4) goto l51;
  i4 = (OOC_INT32)b;
  i5=0;
l45_loop:
  i6 = _check_pointer(i0, 75089);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = OOC_IR__BuilderDesc_Widen((OOC_IR__Builder)i4, (void*)(i6+(_check_index(i5, i7, OOC_UINT32, 75089))*4), (OOC_SymbolTable__Type)i1);
  dummy = i6;
  _assert(i6, 127, 75109);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 75656)))), OOC_IR__VisitorDesc_VisitConcat)),OOC_IR__VisitorDesc_VisitConcat)((OOC_IR__Visitor)i0, (OOC_IR__Concat)i1);
  return;
  ;
}

static void OOC_IR__InitConstructor(OOC_IR__Constructor cons, OOC_Scanner_SymList__Symbol sym, OOC_IR__NewObject alloc, OOC_IR__Call init) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)alloc;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 75959))+4);
  i2 = (OOC_INT32)cons;
  i3 = (OOC_INT32)sym;
  OOC_IR__InitOperator((OOC_IR__Operator)i2, (OOC_Scanner_SymList__Symbol)i3, (OOC_SymbolTable__Type)i1);
  *(OOC_INT32*)((_check_pointer(i2, 75975))+8) = i0;
  i0 = (OOC_INT32)init;
  *(OOC_INT32*)((_check_pointer(i2, 76000))+12) = i0;
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
  i2 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 76565)))), &_td_OOC_IR__TypeRefDesc));
  if (i2) goto l3;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 76605)))), &_td_OOC_IR__TypeRefDesc, 76605)), 76613))+12);
  i2 = OOC_SymbolTable_TypeRules__IsRecordPointer((OOC_SymbolTable__Type)i2);
  i2 = !i2;
  
  goto l5;
l3:
  i2=1u;
l5:
  if (!i2) goto l7;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 76678));
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 76643)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i1, 73, (OOC_Scanner_SymList__Symbol)i2);
  return (OOC_IR__Expression)i2;
l7:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 76715)))), &_td_OOC_IR__TypeRefDesc, 76715)), 76723))+12);
  i2 = (OOC_INT32)OOC_SymbolTable__Expand((OOC_SymbolTable__Type)i2);
  consType = (OOC_SymbolTable__Type)i2;
  i3 = (OOC_INT32)OOC_SymbolTable_TypeRules__PointerBaseType((OOC_SymbolTable__Type)i2);
  ptr = (OOC_SymbolTable__Type)i3;
  i4 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 76839)))), OOC_SymbolTable__TypeDesc_Closure)),OOC_SymbolTable__TypeDesc_Closure)((OOC_SymbolTable__Type)i2, (OOC_SymbolTable__Type)i3);
  qualRecord = (OOC_SymbolTable__Type)i4;
  i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 76868)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i3);
  ptr = (OOC_SymbolTable__Type)i3;
  i3 = _type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 76905)))), &_td_OOC_SymbolTable__RecordDesc, 76905);
  consClass = (OOC_SymbolTable__Record)i3;
  i5 = (OOC_INT32)sym;
  i6 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 76973)))), OOC_IR__BuilderDesc_GetName2)),OOC_IR__BuilderDesc_GetName2)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i5, "INIT", 5);
  n = (OOC_SymbolTable__Name)i6;
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 77033))+52);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 77033))+52);
  i8 = (OOC_INT32)context;
  i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 77036)))), OOC_SymbolTable__NamespaceDesc_Identify)),OOC_SymbolTable__NamespaceDesc_Identify)((OOC_SymbolTable__Namespace)i3, (OOC_SymbolTable__Item)i8, (OOC_SymbolTable__Name)i6, 1u);
  initDecl = (OOC_SymbolTable__Declaration)i3;
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 77090))+16);
  OOC_SymbolTable_Uses__Mark((OOC_SymbolTable__Declaration)i3, (OOC_SymbolTable_Uses__Uses)i7, (OOC_SymbolTable__Name)i6);
  init = (OOC_IR__Call)0;
  i6 = i3==0;
  if (i6) goto l10;
  i6 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 77156)))), &_td_OOC_SymbolTable__ProcDeclDesc));
  
  goto l12;
l10:
  i6=1u;
l12:
  if (i6) goto l21;
  i6 = *(OOC_INT32*)((_check_pointer(i3, 77314))+24);
  i7 = *(OOC_INT32*)((_check_pointer(i5, 77332))+16);
  i6 = i6>i7;
  if (!i6) goto l16;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 77388));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 77352)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 75, (OOC_Scanner_SymList__Symbol)i0);
l16:
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 77436)))), OOC_IR__BuilderDesc_NewNil)),OOC_IR__BuilderDesc_NewNil)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i5);
  pseudoDesign = (OOC_IR__Expression)i0;
  i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewSelectProc((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i5, (OOC_IR__Expression)i0, (OOC_SymbolTable__Type)i4, (OOC_SymbolTable__ProcDecl)(_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 77570)))), &_td_OOC_SymbolTable__ProcDeclDesc, 77570)), (OOC_Scanner_SymList__Symbol)i5, 1u);
  pseudoDesign = (OOC_IR__Expression)i0;
  i3 = (OOC_INT32)endOfArgsSym;
  i4 = (OOC_INT32)arguments;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 77608)))), OOC_IR__BuilderDesc_NewCall)),OOC_IR__BuilderDesc_NewCall)((OOC_IR__Builder)i1, (OOC_IR__Expression)i0, (OOC_IR__ExpressionList)i4, 0u, (OOC_SymbolTable__Item)i8, (OOC_Scanner_SymList__Symbol)i3);
  expr = (OOC_IR__Expression)i0;
  i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 77688)))), &_td_OOC_IR__CallDesc);
  if (i3) goto l19;
  i0=0;
  goto l25;
l19:
  i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 77723)))), &_td_OOC_IR__CallDesc, 77723);
  
  goto l25;
l21:
  i0 = (OOC_INT32)arguments;
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i0, 77201)), 0);
  i3 = i3!=0;
  if (!i3) goto l24;
  i0 = _check_pointer(i0, 77266);
  i3 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i3, OOC_UINT8, 77266))*4);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 77269));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 77230)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i1, 39, (OOC_Scanner_SymList__Symbol)i0);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 78087)))), OOC_IR__VisitorDesc_VisitConstructor)),OOC_IR__VisitorDesc_VisitConstructor)((OOC_IR__Visitor)i0, (OOC_IR__Constructor)i1);
  return;
  ;
}

static void OOC_IR__InitCurrentException(OOC_IR__CurrentException ce, OOC_Scanner_SymList__Symbol sym, OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)type;
  i1 = (OOC_INT32)sym;
  i2 = (OOC_INT32)ce;
  OOC_IR__InitOperator((OOC_IR__Operator)i2, (OOC_Scanner_SymList__Symbol)i1, (OOC_SymbolTable__Type)i0);
  *(OOC_INT32*)((_check_pointer(i2, 78405))+8) = (OOC_INT32)0;
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 78892)))), OOC_IR__VisitorDesc_VisitCurrentException)),OOC_IR__VisitorDesc_VisitCurrentException)((OOC_IR__Visitor)i0, (OOC_IR__CurrentException)i1);
  return;
  ;
}

static void OOC_IR__InitDeref(OOC_IR__Deref d, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression pointer, OOC_CHAR8 checkPointer) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_SymbolTable__Type baseType;

  i0 = (OOC_INT32)pointer;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 79249))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 79249))+4);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 79254)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i2);
  baseType = (OOC_SymbolTable__Type)i1;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 79290)))), OOC_SymbolTable__TypeDesc_Bound)),OOC_SymbolTable__TypeDesc_Bound)((OOC_SymbolTable__Type)i1);
  baseType = (OOC_SymbolTable__Type)i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 79329)))), &_td_OOC_SymbolTable__PointerDesc, 79329)), 79337))+40);
  baseType = (OOC_SymbolTable__Type)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 79386))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 79386))+4);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 79391)))), OOC_SymbolTable__TypeDesc_Closure)),OOC_SymbolTable__TypeDesc_Closure)((OOC_SymbolTable__Type)i3, (OOC_SymbolTable__Type)i1);
  i2 = (OOC_INT32)d;
  i3 = (OOC_INT32)sym;
  OOC_IR__InitOperator((OOC_IR__Operator)i2, (OOC_Scanner_SymList__Symbol)i3, (OOC_SymbolTable__Type)i1);
  *(OOC_INT32*)((_check_pointer(i2, 79417))+8) = i0;
  i0 = checkPointer;
  *(OOC_UINT8*)((_check_pointer(i2, 79444))+12) = i0;
  return;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_NewDeref(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression design) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_SymbolTable__Type type;
  OOC_SymbolTable__Record _class;
  OOC_IR__Deref i;

  i0 = (OOC_INT32)design;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 79660)))), &_td_OOC_IR__SelectProcDesc);
  if (i1) goto l7;
  i1 = (OOC_INT32)sym;
  i2 = (OOC_INT32)b;
  OOC_IR__BuilderDesc_CheckFunctionOp((OOC_IR__Builder)i2, (OOC_IR__Expression)i0, (OOC_Scanner_SymList__Symbol)i1);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 80419))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 80419))+4);
  i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 80424)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i4);
  type = (OOC_SymbolTable__Type)i3;
  i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 80451)))), OOC_SymbolTable__TypeDesc_Bound)),OOC_SymbolTable__TypeDesc_Bound)((OOC_SymbolTable__Type)i3);
  i3 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 80460)))), &_td_OOC_SymbolTable__PointerDesc));
  if (i3) goto l5;
  i3 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__Deref.baseTypes[0]);
  i = (OOC_IR__Deref)i3;
  i4 = *(OOC_INT32*)((_check_pointer(i1, 80658))+16);
  i5 = (OOC_INT32)OOC_Config_StdPragmas__derefCheck;
  i2 = OOC_IR__GetPragmaValue((OOC_IR__Builder)i2, (Config_Section_Options__Option)i5, i4);
  OOC_IR__InitDeref((OOC_IR__Deref)i3, (OOC_Scanner_SymList__Symbol)i1, (OOC_IR__Expression)i0, i2);
  return (OOC_IR__Expression)i3;
  goto l19;
l5:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 80524));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 80497)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i2, 21, (OOC_Scanner_SymList__Symbol)i0);
  return (OOC_IR__Expression)i0;
  goto l19;
l7:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 79737))+12);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 79737))+12);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 79748)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i2);
  type = (OOC_SymbolTable__Type)i1;
  i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 79784)))), &_td_OOC_SymbolTable__RecordDesc, 79784);
  _class = (OOC_SymbolTable__Record)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 79883))+20);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 79822))+52);
  i2 = *(OOC_INT32*)((_check_pointer(i2, 79890))+56);
  i1 = (OOC_INT32)OOC_SymbolTable_Namespace__ExtendedDesc_GetSuperProcByIndex((OOC_SymbolTable_Namespace__Extended)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 79836)))), &_td_OOC_SymbolTable_Namespace__ExtendedDesc, 79836)), i2);
  *(OOC_INT32*)((_check_pointer(i0, 79805))+20) = i1;
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 79920))+29);
  if (i1) goto l17;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 80008))+20);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l15;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 80122))+20);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 80130))+64);
  *(OOC_INT32*)((_check_pointer(i0, 80106))+4) = i1;
  *(OOC_UINT8*)((_check_pointer(i0, 80158))+28) = 1u;
  *(OOC_UINT8*)((_check_pointer(i0, 80196))+29) = 1u;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 80236))+20);
  i1 = *(OOC_UINT8*)((_check_pointer(i1, 80243))+50);
  if (!i1) goto l14;
  i1 = (OOC_INT32)b;
  i2 = (OOC_INT32)sym;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 80271)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 58, (OOC_Scanner_SymList__Symbol)i2);
l14:
  return (OOC_IR__Expression)i0;
  goto l19;
l15:
  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)sym;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 80044)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i0, 59, (OOC_Scanner_SymList__Symbol)i1);
  return (OOC_IR__Expression)i0;
  goto l19;
l17:
  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)sym;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 79954)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i0, 60, (OOC_Scanner_SymList__Symbol)i1);
  return (OOC_IR__Expression)i0;
l19:
  _failed_function(79517); return 0;
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 80861)))), OOC_IR__VisitorDesc_VisitDeref)),OOC_IR__VisitorDesc_VisitDeref)((OOC_IR__Visitor)i0, (OOC_IR__Deref)i1);
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
  *(OOC_INT32*)((_check_pointer(i1, 81156))+8) = i0;
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 81558)))), OOC_IR__VisitorDesc_VisitEntier)),OOC_IR__VisitorDesc_VisitEntier)((OOC_IR__Visitor)i0, (OOC_IR__Entier)i1);
  return;
  ;
}

static void OOC_IR__InitIndex(OOC_IR__Index i, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression array, OOC_IR__Expression index, OOC_CHAR8 checkIndex) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_SymbolTable__Type elementType;

  i0 = (OOC_INT32)array;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 81917))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 81917))+4);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 81922)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i2);
  elementType = (OOC_SymbolTable__Type)i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 81969)))), &_td_OOC_SymbolTable__ArrayDesc, 81969)), 81975))+44);
  elementType = (OOC_SymbolTable__Type)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 82025))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 82025))+4);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 82030)))), OOC_SymbolTable__TypeDesc_Closure)),OOC_SymbolTable__TypeDesc_Closure)((OOC_SymbolTable__Type)i3, (OOC_SymbolTable__Type)i1);
  i2 = (OOC_INT32)i;
  i3 = (OOC_INT32)sym;
  OOC_IR__InitOperator((OOC_IR__Operator)i2, (OOC_Scanner_SymList__Symbol)i3, (OOC_SymbolTable__Type)i1);
  *(OOC_INT32*)((_check_pointer(i2, 82059))+8) = i0;
  i0 = (OOC_INT32)index;
  *(OOC_INT32*)((_check_pointer(i2, 82081))+12) = i0;
  i0 = checkIndex;
  *(OOC_UINT8*)((_check_pointer(i2, 82103))+16) = i0;
  return;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_NewIndex(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression array, OOC_IR__Expression index) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_CHAR8 checkIndex;
  OOC_SymbolTable__Type type;
  OOC_SymbolTable__Array a;

  i0 = (OOC_INT32)sym;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 82406))+16);
  i2 = (OOC_INT32)b;
  i3 = (OOC_INT32)OOC_Config_StdPragmas__indexCheck;
  i1 = OOC_IR__GetPragmaValue((OOC_IR__Builder)i2, (Config_Section_Options__Option)i3, i1);
  checkIndex = i1;
  i3 = (OOC_INT32)array;
  OOC_IR__BuilderDesc_CheckFunctionOp((OOC_IR__Builder)i2, (OOC_IR__Expression)i3, (OOC_Scanner_SymList__Symbol)i0);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 82471))+4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 82471))+4);
  i4 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 82476)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i5);
  type = (OOC_SymbolTable__Type)i4;
  i5 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 82501)))), &_td_OOC_SymbolTable__PointerDesc);
  if (i5) goto l3;
  {register OOC_INT32 h0=i3;i3=i4;i4=h0;}
  goto l4;
l3:
  i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 82538)))), OOC_IR__BuilderDesc_NewDeref)),OOC_IR__BuilderDesc_NewDeref)((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i0, (OOC_IR__Expression)i3);
  array = (OOC_IR__Expression)i3;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 82582))+4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 82582))+4);
  i4 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 82587)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i5);
  type = (OOC_SymbolTable__Type)i4;
  {register OOC_INT32 h0=i3;i3=i4;i4=h0;}
l4:
  i5 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 82622)))), &_td_OOC_SymbolTable__ArrayDesc));
  if (i5) goto l18;
  i3 = _type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 82711)))), &_td_OOC_SymbolTable__ArrayDesc, 82711);
  a = (OOC_SymbolTable__Array)i3;
  if (i1) goto l9;
  i1=0u;
  goto l10;
l9:
  i1 = *(OOC_UINT8*)((_check_pointer(i3, 82753))+41);
  
l10:
  checkIndex = i1;
  i5 = (OOC_INT32)index;
  i5 = (OOC_INT32)OOC_IR__BuilderDesc_AssertInteger((OOC_IR__Builder)i2, (OOC_IR__Expression)i5);
  index = (OOC_IR__Expression)i5;
  i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 82823)))), &_td_OOC_IR__ConstDesc);
  if (!i6) goto l17;
  i6 = *(OOC_UINT8*)((_check_pointer(i3, 82849))+40);
  if (i6) goto l15;
  i3 = *(OOC_INT32*)((_check_pointer(i3, 83142))+52);
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
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 82655)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i2, 15, (OOC_Scanner_SymList__Symbol)i0);
  return (OOC_IR__Expression)i0;
l19:
  _failed_function(82171); return 0;
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 83424)))), OOC_IR__VisitorDesc_VisitIndex)),OOC_IR__VisitorDesc_VisitIndex)((OOC_IR__Visitor)i0, (OOC_IR__Index)i1);
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
  *(OOC_INT8*)((_check_pointer(i1, 83771))+8) = i0;
  i0 = (OOC_INT32)array;
  *(OOC_INT32*)((_check_pointer(i1, 83800))+12) = i0;
  i0 = (OOC_INT32)arrayVariable;
  *(OOC_INT32*)((_check_pointer(i1, 83825))+20) = i0;
  i0 = dim;
  *(OOC_INT32*)((_check_pointer(i1, 83866))+16) = i0;
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
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 84144))+4);
  i1 = OOC_SymbolTable_TypeRules__IsArray((OOC_SymbolTable__Type)i1);
  i1 = !i1;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 84176))+4);
  i1 = OOC_SymbolTable_TypeRules__IsStringConst((OOC_SymbolTable__Type)i1);
  i1 = !i1;
  
l5:
  if (!i1) goto l7;
  i1 = (OOC_INT32)b;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 84218));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 84195)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 15, (OOC_Scanner_SymList__Symbol)i2);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 84239))+20);
  return (OOC_IR__Expression)i1;
l7:
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__Len.baseTypes[0]);
  len = (OOC_IR__Len)i1;
  arrayVariable = (OOC_IR__Expression)i0;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 84334)))), &_td_OOC_IR__IndexDesc);
  if (i2) goto l10;
  i2=i0;
  goto l16;
l10:
  i2=i0;
l11_loop:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 84384)))), &_td_OOC_IR__IndexDesc, 84384)), 84390))+8);
  i3 = dim;
  arrayVariable = (OOC_IR__Expression)i2;
  dim = (i3+1);
  i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 84334)))), &_td_OOC_IR__IndexDesc);
  if (i3) goto l11_loop;
l16:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 84451))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 84451))+4);
  i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 84456)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i4);
  type = (OOC_SymbolTable__Type)i3;
  i4 = dim;
  i5 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 84481)))), &_td_OOC_SymbolTable__PredefTypeDesc);
  if (i5) goto l31;
  i5 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 84553)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (i5) goto l21;
  i5=0u;
  goto l23;
l21:
  i5 = OOC_SymbolTable__ArrayDesc_GetOpenDimensions((OOC_SymbolTable__Array)(_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 84596)))), &_td_OOC_SymbolTable__ArrayDesc, 84596)));
  i5 = i4>=i5;
  
l23:
  if (i5) goto l29;
  i5 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 84686)))), &_td_OOC_IR__VarDesc);
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
  i3 = *(OOC_UINT8*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 84881)))), &_td_OOC_SymbolTable__ArrayDesc, 84881)), 84887))+41);
  i3 = !i3;
  
l41:
  if (!i3) goto l43;
  i3 = (OOC_INT32)b;
  i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 84951));
  i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 84921)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i3, 54, (OOC_Scanner_SymList__Symbol)i6);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 85192)))), OOC_IR__VisitorDesc_VisitLen)),OOC_IR__VisitorDesc_VisitLen)((OOC_IR__Visitor)i0, (OOC_IR__Len)i1);
  return;
  ;
}

static void OOC_IR__InitNegate(OOC_IR__Negate neg, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression expr) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)expr;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 85437))+4);
  i2 = (OOC_INT32)neg;
  i3 = (OOC_INT32)sym;
  OOC_IR__InitOperator((OOC_IR__Operator)i2, (OOC_Scanner_SymList__Symbol)i3, (OOC_SymbolTable__Type)i1);
  *(OOC_INT32*)((_check_pointer(i2, 85453))+8) = i0;
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 85822)))), OOC_IR__VisitorDesc_VisitNegate)),OOC_IR__VisitorDesc_VisitNegate)((OOC_IR__Visitor)i0, (OOC_IR__Negate)i1);
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
  *(OOC_INT32*)((_check_pointer(i2, 86126))+8) = i0;
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 86569)))), OOC_IR__VisitorDesc_VisitNewBlock)),OOC_IR__VisitorDesc_VisitNewBlock)((OOC_IR__Visitor)i0, (OOC_IR__NewBlock)i1);
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
  *(OOC_INT32*)((_check_pointer(i2, 86884))+8) = i0;
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
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 87224)), 0);
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__ExpressionList.baseTypes[0], (i1-1));
  length = (OOC_IR__ExpressionList)i1;
  i = 0;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i1, 87262)), 0);
  i3 = 0<i2;
  if (!i3) goto l10;
  i3 = (OOC_INT32)b;
  i4=0;
l5_loop:
  i5 = _check_pointer(i1, 87284);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i7 = _check_pointer(i0, 87311);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i9 = i4+1;
  i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i9, i8, OOC_UINT32, 87311))*4);
  i7 = (OOC_INT32)OOC_IR__BuilderDesc_AssertInteger((OOC_IR__Builder)i3, (OOC_IR__Expression)i7);
  *(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 87284))*4) = i7;
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 87593)))), OOC_IR__VisitorDesc_VisitNewObject)),OOC_IR__VisitorDesc_VisitNewObject)((OOC_IR__Visitor)i0, (OOC_IR__NewObject)i1);
  return;
  ;
}

static void OOC_IR__InitNot(OOC_IR__Not neg, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression expr) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)expr;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 87835))+4);
  i2 = (OOC_INT32)neg;
  i3 = (OOC_INT32)sym;
  OOC_IR__InitOperator((OOC_IR__Operator)i2, (OOC_Scanner_SymList__Symbol)i3, (OOC_SymbolTable__Type)i1);
  *(OOC_INT32*)((_check_pointer(i2, 87851))+8) = i0;
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 88193)))), OOC_IR__VisitorDesc_VisitNot)),OOC_IR__VisitorDesc_VisitNot)((OOC_IR__Visitor)i0, (OOC_IR__Not)i1);
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
  *(OOC_INT32*)((_check_pointer(i1, 88466))+8) = i0;
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 88826)))), OOC_IR__VisitorDesc_VisitOdd)),OOC_IR__VisitorDesc_VisitOdd)((OOC_IR__Visitor)i0, (OOC_IR__Odd)i1);
  return;
  ;
}

static void OOC_IR__InitSelectField(OOC_IR__SelectField sf, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression record, OOC_SymbolTable__FieldDecl field, OOC_Scanner_SymList__Symbol fieldSym) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_SymbolTable__Type recordType;
  OOC_SymbolTable__Type ptr;

  i0 = (OOC_INT32)record;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 89240))+4);
  recordType = (OOC_SymbolTable__Type)i1;
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 89268)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i1);
  i3 = (OOC_INT32)field;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 89286))+4);
  i2 = i2!=i4;
  if (!i2) goto l9;
l4_loop:
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 89321)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i1);
  ptr = (OOC_SymbolTable__Type)i2;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 89380)))), &_td_OOC_SymbolTable__RecordDesc, 89380)), 89387))+40);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 89363)))), OOC_SymbolTable__TypeDesc_Closure)),OOC_SymbolTable__TypeDesc_Closure)((OOC_SymbolTable__Type)i1, (OOC_SymbolTable__Type)i2);
  recordType = (OOC_SymbolTable__Type)i1;
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 89268)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i1);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 89286))+4);
  i2 = i2!=i4;
  if (i2) goto l4_loop;
l9:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 89464))+48);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 89450)))), OOC_SymbolTable__TypeDesc_Closure)),OOC_SymbolTable__TypeDesc_Closure)((OOC_SymbolTable__Type)i1, (OOC_SymbolTable__Type)i2);
  i2 = (OOC_INT32)sf;
  i4 = (OOC_INT32)sym;
  OOC_IR__InitOperator((OOC_IR__Operator)i2, (OOC_Scanner_SymList__Symbol)i4, (OOC_SymbolTable__Type)i1);
  *(OOC_INT32*)((_check_pointer(i2, 89479))+8) = i0;
  *(OOC_INT32*)((_check_pointer(i2, 89504))+12) = i3;
  i0 = (OOC_INT32)fieldSym;
  *(OOC_INT32*)((_check_pointer(i2, 89527))+16) = i0;
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 90036)))), OOC_IR__VisitorDesc_VisitSelectField)),OOC_IR__VisitorDesc_VisitSelectField)((OOC_IR__Visitor)i0, (OOC_IR__SelectField)i1);
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
  *(OOC_INT32*)((_check_pointer(i0, 90508))+12) = i1;
  i2 = (OOC_INT32)tbProc;
  i3 = (OOC_INT32)OOC_SymbolTable__ProcDeclDesc_Class((OOC_SymbolTable__ProcDecl)i2);
  _class = (OOC_SymbolTable__Type)i3;
  baseRecord = (OOC_SymbolTable__Type)i1;
  i4 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 90678)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i1);
  i4 = i4!=i3;
  if (!i4) goto l9;
l4_loop:
  i4 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 90724)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i1);
  ptr = (OOC_SymbolTable__Type)i4;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 90783)))), &_td_OOC_SymbolTable__RecordDesc, 90783)), 90790))+40);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 90766)))), OOC_SymbolTable__TypeDesc_Closure)),OOC_SymbolTable__TypeDesc_Closure)((OOC_SymbolTable__Type)i1, (OOC_SymbolTable__Type)i4);
  baseRecord = (OOC_SymbolTable__Type)i1;
  i4 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 90678)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i1);
  i4 = i4!=i3;
  if (i4) goto l4_loop;
l9:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 90864))+64);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 90849)))), OOC_SymbolTable__TypeDesc_Closure)),OOC_SymbolTable__TypeDesc_Closure)((OOC_SymbolTable__Type)i1, (OOC_SymbolTable__Type)i3);
  i3 = (OOC_INT32)sym;
  OOC_IR__InitOperator((OOC_IR__Operator)i0, (OOC_Scanner_SymList__Symbol)i3, (OOC_SymbolTable__Type)i1);
  i1 = (OOC_INT32)receiver;
  *(OOC_INT32*)((_check_pointer(i0, 90885))+8) = i1;
  i1 = checkPointer;
  *(OOC_UINT8*)((_check_pointer(i0, 90915))+16) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 90953))+20) = i2;
  i1 = (OOC_INT32)tbProcSym;
  *(OOC_INT32*)((_check_pointer(i0, 90979))+24) = i1;
  i1 = isStaticCall;
  *(OOC_UINT8*)((_check_pointer(i0, 91011))+28) = i1;
  *(OOC_UINT8*)((_check_pointer(i0, 91049))+29) = 0u;
  return;
  ;
}

OOC_IR__SelectProc OOC_IR__BuilderDesc_NewSelectProc(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression receiver, OOC_SymbolTable__Type recordType, OOC_SymbolTable__ProcDecl tbProc, OOC_Scanner_SymList__Symbol tbProcSym, OOC_CHAR8 isStaticCall) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;

  i0 = (OOC_INT32)sym;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 91545))+16);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 91879)))), OOC_IR__VisitorDesc_VisitSelectProc)),OOC_IR__VisitorDesc_VisitSelectProc)((OOC_IR__Visitor)i0, (OOC_IR__SelectProc)i1);
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
  *(OOC_INT32*)((_check_pointer(i1, 92181))+8) = i0;
  i0 = (OOC_INT32)set;
  *(OOC_INT32*)((_check_pointer(i1, 92208))+12) = i0;
  return;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_NewSetMember(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression element, OOC_IR__Expression set) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_IR__SetMember op;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__SetMember.baseTypes[0]);
  op = (OOC_IR__SetMember)i0;
  i1 = (OOC_INT32)set;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 92440))+4);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 92640)))), OOC_IR__VisitorDesc_VisitSetMember)),OOC_IR__VisitorDesc_VisitSetMember)((OOC_IR__Visitor)i0, (OOC_IR__SetMember)i1);
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
  *(OOC_INT8*)((_check_pointer(i2, 92937))+8) = i0;
  i0 = (OOC_INT32)left;
  *(OOC_INT32*)((_check_pointer(i2, 92964))+12) = i0;
  i0 = (OOC_INT32)right;
  *(OOC_INT32*)((_check_pointer(i2, 92985))+16) = i0;
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
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 93206))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 93194))+4);
  i3 = OOC_SymbolTable_TypeRules__SameType((OOC_SymbolTable__Type)i4, (OOC_SymbolTable__Type)i3);
  _assert(i3, 127, 93171);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 93265))+4);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 93440)))), OOC_IR__VisitorDesc_VisitSetOp)),OOC_IR__VisitorDesc_VisitSetOp)((OOC_IR__Visitor)i0, (OOC_IR__SetOp)i1);
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
  *(OOC_INT32*)((_check_pointer(i1, 93760))+8) = i0;
  i0 = (OOC_INT32)to;
  *(OOC_INT32*)((_check_pointer(i1, 93784))+12) = i0;
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
  i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 94094)))), OOC_IR__BuilderDesc_AssertType)),OOC_IR__BuilderDesc_AssertType)((OOC_IR__Builder)i2, (OOC_IR__Expression)i1);
  t = (OOC_SymbolTable__Type)i3;
  i4 = OOC_SymbolTable_TypeRules__IsSetType((OOC_SymbolTable__Type)i3);
  if (i4) goto l6;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 94213));
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 94188)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i2, 79, (OOC_Scanner_SymList__Symbol)i1);
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
  i1 = (OOC_INT32)Object_Boxed__NewSet(0u);
  i2 = (OOC_INT32)b;
  i3 = (OOC_INT32)sym;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 94309)))), OOC_IR__BuilderDesc_NewConst)),OOC_IR__BuilderDesc_NewConst)((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i3, (OOC_SymbolTable__Type)i0, (Object_Boxed__Object)i1);
  return (OOC_IR__Expression)i0;
l19:
  _failed_function(93839); return 0;
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 94804)))), OOC_IR__VisitorDesc_VisitSetRange)),OOC_IR__VisitorDesc_VisitSetRange)((OOC_IR__Visitor)i0, (OOC_IR__SetRange)i1);
  return;
  ;
}

OOC_CHAR8 OOC_IR__SetRangeDesc_IsEmpty(OOC_IR__SetRange range) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)range;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 94996))+12);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 94964))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 94964))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 94971)))), &_td_OOC_IR__ConstDesc, 94971)), 94977))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 95001)))), &_td_OOC_IR__ConstDesc, 95001)), 95007))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 94971)))), &_td_OOC_IR__ConstDesc, 94971)), 94977))+8);
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 94984)))), Object_Boxed__ObjectDesc_Cmp)),Object_Boxed__ObjectDesc_Cmp)((Object_Boxed__Object)i2, (Object__Object)i1);
  return (i0>0);
  ;
}

OOC_CHAR8 OOC_IR__SetRangeDesc_IntersectsWith(OOC_IR__SetRange range, OOC_IR__SetRange range2) {
  register OOC_INT32 i0,i1,i2,i3,i4;

  i0 = (OOC_INT32)range2;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 95263))+8);
  i2 = (OOC_INT32)range;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 95234))+12);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 95234))+12);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 95238)))), &_td_OOC_IR__ConstDesc, 95238)), 95244))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 95269)))), &_td_OOC_IR__ConstDesc, 95269)), 95275))+8);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 95238)))), &_td_OOC_IR__ConstDesc, 95238)), 95244))+8);
  i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 95250)))), Object_Boxed__ObjectDesc_Cmp)),Object_Boxed__ObjectDesc_Cmp)((Object_Boxed__Object)i3, (Object__Object)i1);
  i1 = i1<0;
  if (i1) goto l3;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 95338))+12);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 95307))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 95307))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 95313)))), &_td_OOC_IR__ConstDesc, 95313)), 95319))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 95342)))), &_td_OOC_IR__ConstDesc, 95342)), 95348))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 95313)))), &_td_OOC_IR__ConstDesc, 95313)), 95319))+8);
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 95325)))), Object_Boxed__ObjectDesc_Cmp)),Object_Boxed__ObjectDesc_Cmp)((Object_Boxed__Object)i1, (Object__Object)i0);
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
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 95643))+4);
  i2 = (OOC_INT32)shift;
  i3 = (OOC_INT32)sym;
  OOC_IR__InitOperator((OOC_IR__Operator)i2, (OOC_Scanner_SymList__Symbol)i3, (OOC_SymbolTable__Type)i1);
  *(OOC_INT32*)((_check_pointer(i2, 95661))+8) = i0;
  i0 = (OOC_INT32)by;
  *(OOC_INT32*)((_check_pointer(i2, 95688))+12) = i0;
  i0 = rotate;
  *(OOC_UINT8*)((_check_pointer(i2, 95709))+16) = i0;
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
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 96028))+20);
      i2 = (OOC_INT32)expr;
      i1 = i2!=i1;
      if (!i1) goto l18;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 96079))+4);
      i1 = OOC_SymbolTable_TypeRules__IsIntegerType((OOC_SymbolTable__Type)i1);
      if (i1) goto l5;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 96120))+4);
      i1 = OOC_SymbolTable_TypeRules__IsCharType((OOC_SymbolTable__Type)i1);
      
      goto l7;
l5:
      i1=1u;
l7:
      if (i1) goto l9;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 96163))+4);
      i1 = OOC_SymbolTable_TypeRules__IsPredefType((OOC_SymbolTable__Type)i1, 11);
      
      goto l11;
l9:
      i1=1u;
l11:
      if (i1) goto l13;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 96216))+4);
      i1 = OOC_SymbolTable_TypeRules__IsSetType((OOC_SymbolTable__Type)i1);
      
      goto l14;
l13:
      i1=1u;
l14:
      i1 = !i1;
      if (!i1) goto l18;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 96267));
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 96240)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 5, (OOC_Scanner_SymList__Symbol)i1);
      i0 = (OOC_INT32)Object_BigInt__NewInt(1);
      v = (Object_BigInt__BigInt)i0;
      i1 = (OOC_INT32)OOC_SymbolTable_Predef__SmallestIntType((Object_BigInt__BigInt)i0);
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 96337));
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 96742)))), OOC_IR__VisitorDesc_VisitShift)),OOC_IR__VisitorDesc_VisitShift)((OOC_IR__Visitor)i0, (OOC_IR__Shift)i1);
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
  *(OOC_INT32*)((_check_pointer(i2, 97050))+8) = i0;
  return;
  ;
}

OOC_IR__TypeCast OOC_IR__BuilderDesc_NewTypeCast(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression typeExpr, OOC_IR__Expression expr) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_SymbolTable__Type type;

  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)typeExpr;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 97289)))), OOC_IR__BuilderDesc_AssertType)),OOC_IR__BuilderDesc_AssertType)((OOC_IR__Builder)i0, (OOC_IR__Expression)i1);
  i1 = (OOC_INT32)OOC_SymbolTable__Expand((OOC_SymbolTable__Type)i1);
  type = (OOC_SymbolTable__Type)i1;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 97325))+32);
  i2 = i2<0;
  if (i2) goto l3;
  i2 = (OOC_INT32)expr;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 97344))+4);
  i2 = *(OOC_INT32*)((_check_pointer(i2, 97349))+32);
  i2 = i2<0;
  
  goto l4;
l3:
  i2=1u;
l4:
  i3 = (OOC_INT32)expr;
  if (i2) goto l7;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 97387))+4);
  i4 = *(OOC_INT32*)((_check_pointer(i1, 97375))+32);
  i2 = *(OOC_INT32*)((_check_pointer(i2, 97392))+32);
  i2 = i4!=i2;
  
  goto l9;
l7:
  i2=1u;
l9:
  if (!i2) goto l11;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 97443));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 97411)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 52, (OOC_Scanner_SymList__Symbol)i2);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 97704)))), OOC_IR__VisitorDesc_VisitTypeCast)),OOC_IR__VisitorDesc_VisitTypeCast)((OOC_IR__Visitor)i0, (OOC_IR__TypeCast)i1);
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
  *(OOC_INT32*)((_check_pointer(i2, 98011))+8) = i0;
  return;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_NewTypeConv(OOC_IR__Builder b, OOC_SymbolTable__Type type, OOC_IR__Expression expr) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_IR__TypeConv conv;

  i0 = (OOC_INT32)expr;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 98178))+4);
  i2 = (OOC_INT32)type;
  i1 = i1==i2;
  if (i1) goto l11;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 98293)))), &_td_OOC_IR__TypeConvDesc);
  if (i1) goto l5;
  i1=0u;
  goto l7;
l5:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 98334))+4);
  i1 = OOC_SymbolTable_TypeRules__IncludesType((OOC_SymbolTable__Type)i2, (OOC_SymbolTable__Type)i1);
  
l7:
  if (!i1) goto l10;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 98401)))), &_td_OOC_IR__TypeConvDesc, 98401)), 98410))+8);
  expr = (OOC_IR__Expression)i0;
  
l10:
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__TypeConv.baseTypes[0]);
  conv = (OOC_IR__TypeConv)i1;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 98476));
  OOC_IR__InitTypeConv((OOC_IR__TypeConv)i1, (OOC_Scanner_SymList__Symbol)i3, (OOC_SymbolTable__Type)i2, (OOC_IR__Expression)i0);
  return (OOC_IR__Expression)i1;
  goto l12;
l11:
  return (OOC_IR__Expression)i0;
l12:
  _failed_function(98072); return 0;
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 98693)))), OOC_IR__VisitorDesc_VisitTypeConv)),OOC_IR__VisitorDesc_VisitTypeConv)((OOC_IR__Visitor)i0, (OOC_IR__TypeConv)i1);
  return;
  ;
}

OOC_CHAR8 OOC_IR__BuilderDesc_Widen(OOC_IR__Builder b, OOC_IR__Expression *expr, OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)*expr;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 100177))+4);
  i2 = (OOC_INT32)type;
  _assert((i1!=(OOC_INT32)0), 127, 100165);
  _assert((i2!=(OOC_INT32)0), 127, 100195);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 100250))+4);
  i0 = OOC_SymbolTable_TypeRules__SameType((OOC_SymbolTable__Type)i2, (OOC_SymbolTable__Type)i0);
  if (i0) goto l99;
  i0 = (OOC_INT32)*expr;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 100369))+4);
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 100376)))), &_td_OOC_SymbolTable__FormalParsDesc);
  if (i1) goto l93;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 100706))+4);
  i0 = OOC_SymbolTable_TypeRules__IncludesType((OOC_SymbolTable__Type)i2, (OOC_SymbolTable__Type)i0);
  if (i0) goto l91;
  i0 = (OOC_INT32)*expr;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 100955))+4);
  i0 = OOC_SymbolTable_TypeRules__IsExtensionOf((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i2);
  if (i0) goto l89;
  i0 = (OOC_INT32)*expr;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 101117))+4);
  i0 = OOC_IR__IsPredefType((OOC_SymbolTable__Type)i0, 16);
  if (i0) goto l11;
  i0=0u;
  goto l13;
l11:
  i0 = OOC_SymbolTable_TypeRules__IsNilCompatible((OOC_SymbolTable__Type)i2);
  
l13:
  if (i0) goto l87;
  i0 = OOC_SymbolTable_TypeRules__IsPredefType((OOC_SymbolTable__Type)i2, 12);
  if (i0) goto l17;
  i0=0u;
  goto l19;
l17:
  i0 = (OOC_INT32)*expr;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 101347))+4);
  i0 = OOC_SymbolTable_TypeRules__IsPtrCompatible((OOC_SymbolTable__Type)i0);
  
l19:
  if (i0) goto l85;
  i0 = (OOC_INT32)*expr;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 101448)))), &_td_OOC_IR__ConstDesc);
  if (i1) goto l23;
  i1=0u;
  goto l25;
l23:
  i1 = OOC_SymbolTable_TypeRules__IsStringConst((OOC_SymbolTable__Type)i2);
  
l25:
  if (i1) goto l27;
  i0=0u;
  goto l29;
l27:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 101528))+4);
  i0 = (OOC_INT32)OOC_SymbolTable_TypeRules__BaseCharType((OOC_SymbolTable__Type)i0);
  i0 = i0!=(OOC_INT32)0;
  
l29:
  if (i0) goto l31;
  i0=0u;
  goto l33;
l31:
  i0 = (OOC_INT32)*expr;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 101643))+4);
  i0 = (OOC_INT32)OOC_SymbolTable_TypeRules__BaseCharType((OOC_SymbolTable__Type)i0);
  i1 = (OOC_INT32)OOC_SymbolTable_TypeRules__BaseCharType((OOC_SymbolTable__Type)i2);
  i0 = OOC_SymbolTable_TypeRules__IncludesType((OOC_SymbolTable__Type)i1, (OOC_SymbolTable__Type)i0);
  
l33:
  if (i0) goto l83;
  i0 = (OOC_INT32)*expr;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 101809)))), &_td_OOC_IR__ConstDesc);
  if (i1) goto l37;
  i0=0u;
  goto l39;
l37:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 101853))+4);
  i0 = (OOC_INT32)OOC_SymbolTable_TypeRules__BaseCharType((OOC_SymbolTable__Type)i0);
  i0 = i0!=(OOC_INT32)0;
  
l39:
  if (i0) goto l41;
  i0=0u;
  goto l43;
l41:
  i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 101886)))), &_td_OOC_SymbolTable__ArrayDesc);
  
l43:
  if (i0) goto l45;
  i0=0u;
  goto l47;
l45:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 101936)))), &_td_OOC_SymbolTable__ArrayDesc, 101936)), 101942))+44);
  i0 = OOC_SymbolTable_TypeRules__IsCharType((OOC_SymbolTable__Type)i0);
  
l47:
  if (i0) goto l81;
  i0 = (OOC_INT32)*expr;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 102115)))), &_td_OOC_IR__ConstDesc);
  if (i1) goto l51;
  i1=0u;
  goto l53;
l51:
  i1 = OOC_SymbolTable_TypeRules__IsObject((OOC_SymbolTable__Type)i2);
  
l53:
  if (i1) goto l55;
  i0=0u;
  goto l57;
l55:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 102188))+4);
  i0 = (OOC_INT32)OOC_SymbolTable_TypeRules__BaseCharType((OOC_SymbolTable__Type)i0);
  i0 = i0!=(OOC_INT32)0;
  
l57:
  if (i0) goto l79;
  i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 102361)))), &_td_OOC_SymbolTable__PointerDesc);
  if (i0) goto l61;
  i0=0u;
  goto l63;
l61:
  i0 = (OOC_INT32)OOC_SymbolTable_TypeRules__PointerBaseType((OOC_SymbolTable__Type)i2);
  i0 = OOC_SymbolTable_TypeRules__IsArrayOfChar((OOC_SymbolTable__Type)i0, 0u);
  
l63:
  if (i0) goto l65;
  i0=0u;
  goto l67;
l65:
  i0 = *(OOC_UINT8*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 102460)))), &_td_OOC_SymbolTable__PointerDesc, 102460)), 102468))+48);
  
l67:
  if (i0) goto l69;
  i0=0u;
  goto l75;
l69:
  i0 = (OOC_INT32)OOC_SymbolTable_TypeRules__PointerBaseType((OOC_SymbolTable__Type)i2);
  i1 = (OOC_INT32)b;
  i0 = OOC_IR__BuilderDesc_Widen((OOC_IR__Builder)i1, (void*)(OOC_INT32)expr, (OOC_SymbolTable__Type)i0);
  if (i0) goto l72;
  i0 = (OOC_INT32)OOC_SymbolTable_TypeRules__PointerBaseType((OOC_SymbolTable__Type)i2);
  i1 = (OOC_INT32)*expr;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 102580))+4);
  i0 = OOC_SymbolTable_TypeRules__IsArrayCompatible((OOC_SymbolTable__Type)i1, (OOC_SymbolTable__Type)i0);
  
  goto l75;
l72:
  i0=1u;
l75:
  if (i0) goto l77;
  return 0u;
  goto l100;
l77:
  i0 = (OOC_INT32)*expr;
  i1 = (OOC_INT32)b;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 102838));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 102825)))), OOC_IR__BuilderDesc_NewAdr)),OOC_IR__BuilderDesc_NewAdr)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i0);
  *expr = (OOC_IR__Expression)i0;
  return 1u;
  goto l100;
l79:
  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 102303))+32);
  i2 = (OOC_INT32)*expr;
  i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewTypeConv((OOC_IR__Builder)i0, (OOC_SymbolTable__Type)i1, (OOC_IR__Expression)i2);
  *expr = (OOC_IR__Expression)i0;
  return 1u;
  goto l100;
l81:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 102075)))), &_td_OOC_SymbolTable__ArrayDesc, 102075)), 102081))+44);
  i0 = (OOC_INT32)OOC_SymbolTable_TypeRules__MatchingStringConst((OOC_SymbolTable__Type)i0);
  i1 = (OOC_INT32)b;
  i0 = OOC_IR__BuilderDesc_Widen((OOC_IR__Builder)i1, (void*)(OOC_INT32)expr, (OOC_SymbolTable__Type)i0);
  return i0;
  goto l100;
l83:
  i0 = (OOC_INT32)*expr;
  i1 = (OOC_INT32)b;
  i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewTypeConv((OOC_IR__Builder)i1, (OOC_SymbolTable__Type)i2, (OOC_IR__Expression)i0);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 101735)))), OOC_IR__BuilderDesc_Fold)),OOC_IR__BuilderDesc_Fold)((OOC_IR__Builder)i1, (OOC_IR__Expression)i0);
  *expr = (OOC_IR__Expression)i0;
  return 1u;
  goto l100;
l85:
  return 1u;
  goto l100;
l87:
  return 1u;
  goto l100;
l89:
  return 1u;
  goto l100;
l91:
  i0 = (OOC_INT32)*expr;
  i1 = (OOC_INT32)b;
  i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewTypeConv((OOC_IR__Builder)i1, (OOC_SymbolTable__Type)i2, (OOC_IR__Expression)i0);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 100860)))), OOC_IR__BuilderDesc_Fold)),OOC_IR__BuilderDesc_Fold)((OOC_IR__Builder)i1, (OOC_IR__Expression)i0);
  *expr = (OOC_IR__Expression)i0;
  return 1u;
  goto l100;
l93:
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 100525)))), &_td_OOC_SymbolTable__FormalParsDesc);
  if (i1) goto l96;
  i0=0u;
  goto l97;
l96:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 100637))+4);
  i0 = OOC_SymbolTable_TypeRules__FormalParamsMatch((OOC_SymbolTable__Type)(_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 100587)))), &_td_OOC_SymbolTable__FormalParsDesc, 100587)), (OOC_SymbolTable__FormalPars)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 100648)))), &_td_OOC_SymbolTable__FormalParsDesc, 100648)), 0u);
  
l97:
  return i0;
  goto l100;
l99:
  return 1u;
l100:
  _failed_function(98754); return 0;
  ;
}

OOC_CHAR8 OOC_IR__BuilderDesc_WidenForAssign(OOC_IR__Builder b, OOC_IR__Expression *expr, OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1,i2;
  OOC_IR__Expression oldExpr;
  auto OOC_CHAR8 OOC_IR__BuilderDesc_WidenForAssign_LengthOk(void);
    
    OOC_CHAR8 OOC_IR__BuilderDesc_WidenForAssign_LengthOk(void) {
      register OOC_INT32 i0,i1,i2;

      i0 = (OOC_INT32)*expr;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 103449))+4);
      i1 = OOC_SymbolTable_TypeRules__IsStringConst((OOC_SymbolTable__Type)i1);
      if (i1) goto l3;
      return 1u;
      goto l8;
l3:
      i1 = (OOC_INT32)type;
      i2 = *(OOC_UINT8*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 103482)))), &_td_OOC_SymbolTable__ArrayDesc, 103482)), 103488))+40);
      if (i2) goto l6;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 103567)))), &_td_OOC_IR__ConstDesc, 103567)), 103573))+8);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 103587)))), &_td_Object_Boxed__StringDesc, 103587)), 103594));
      i0 = *(OOC_INT32*)(_check_pointer(i0, 103601));
      i1 = *(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 103639)))), &_td_OOC_SymbolTable__ArrayDesc, 103639)), 103645))+52);
      return (i0<i1);
      goto l8;
l6:
      return 0u;
l8:
      _failed_function(103386); return 0;
      ;
    }


  i0 = (OOC_INT32)*expr;
  oldExpr = (OOC_IR__Expression)i0;
  i1 = (OOC_INT32)type;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 103775)))), &_td_OOC_SymbolTable__TypeVarDesc);
  if (i2) goto l3;
  i2=0u;
  goto l9;
l3:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 103814))+4);
  i2 = i1==i2;
  if (i2) goto l6;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 103842))+4);
  i2 = OOC_IR__IsPredefType((OOC_SymbolTable__Type)i2, 16);
  
  goto l7;
l6:
  i2=1u;
l7:
  i2 = !i2;
  
l9:
  if (i2) goto l27;
  i2 = OOC_IR__IsPredefType((OOC_SymbolTable__Type)i1, 11);
  if (i2) goto l13;
  i2=0u;
  goto l15;
l13:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 104105))+4);
  i2 = OOC_SymbolTable_TypeRules__IsByteCompatible((OOC_SymbolTable__Type)i2);
  
l15:
  if (i2) goto l21;
  i2 = (OOC_INT32)b;
  i1 = OOC_IR__BuilderDesc_Widen((OOC_IR__Builder)i2, (void*)(OOC_INT32)expr, (OOC_SymbolTable__Type)i1);
  if (i1) goto l19;
  i1=0u;
  goto l23;
l19:
  i1 = OOC_IR__BuilderDesc_WidenForAssign_LengthOk();
  
  goto l23;
l21:
  i1=1u;
l23:
  if (i1) goto l25;
  *expr = (OOC_IR__Expression)i0;
  return 0u;
  goto l28;
l25:
  return 1u;
  goto l28;
l27:
  return 0u;
l28:
  _failed_function(102946); return 0;
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
      _failed_function(104848); return 0;
      ;
    }


  i0 = (OOC_INT32)*right;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 105383))+4);
  i1 = (OOC_INT32)b;
  i0 = OOC_IR__BuilderDesc_Widen((OOC_IR__Builder)i1, (void*)(OOC_INT32)left, (OOC_SymbolTable__Type)i0);
  if (i0) goto l3;
  i0 = (OOC_INT32)*left;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 105412))+4);
  i0 = OOC_IR__BuilderDesc_Widen((OOC_IR__Builder)i1, (void*)(OOC_INT32)right, (OOC_SymbolTable__Type)i0);
  
  goto l5;
l3:
  i0=1u;
l5:
  if (i0) goto l21;
  i0 = (OOC_INT32)*left;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 105455)))), &_td_OOC_IR__ConstDesc);
  if (i1) goto l9;
  i1=0u;
  goto l11;
l9:
  i1 = (OOC_INT32)*right;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 105474)))), &_td_OOC_IR__ConstDesc);
  
l11:
  if (!i1) goto l22;
  i1 = (OOC_INT32)*right;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 105528))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 105516))+4);
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
  _assert(i0, 127, 105621);
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
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 106142))+20);
  i3 = (OOC_INT32)*expr;
  i2 = i3!=i2;
  
l5:
  if (!i2) goto l7;
  i2 = (OOC_INT32)sym;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 106166)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 24, (OOC_Scanner_SymList__Symbol)i2);
  OOC_IR__BuilderDesc_SetNameToType((OOC_IR__Builder)i1, (OOC_SymbolTable__Type)i0);
l7:
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
  *(OOC_INT32*)((_check_pointer(i1, 106529))+8) = i0;
  return;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_NewTypeTag(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression design) {
  register OOC_INT32 i0,i1,i2;
  OOC_SymbolTable__Type type;

  i0 = (OOC_INT32)design;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 106720))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 106720))+4);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 106725)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i2);
  type = (OOC_SymbolTable__Type)i1;
  i2 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 106751)))), &_td_OOC_SymbolTable__RecordDesc));
  if (i2) goto l3;
  i1 = *(OOC_UINT8*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 106779)))), &_td_OOC_SymbolTable__RecordDesc, 106779)), 106786))+38);
  i1 = !i1;
  
  goto l5;
l3:
  i1=1u;
l5:
  if (!i1) goto l7;
  i1 = (OOC_INT32)b;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 106838));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 106813)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 55, (OOC_Scanner_SymList__Symbol)i2);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 107090)))), OOC_IR__VisitorDesc_VisitTypeTag)),OOC_IR__VisitorDesc_VisitTypeTag)((OOC_IR__Visitor)i0, (OOC_IR__TypeTag)i1);
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
  *(OOC_INT32*)((_check_pointer(i1, 107545))+8) = i0;
  i0 = (OOC_INT32)referenceType;
  *(OOC_INT32*)((_check_pointer(i1, 107569))+12) = i0;
  i0 = checkPointer;
  *(OOC_UINT8*)((_check_pointer(i1, 107611))+16) = i0;
  i0 = (OOC_INT32)origExpr;
  *(OOC_INT32*)((_check_pointer(i1, 107651))+20) = i0;
  i0 = (OOC_INT32)origType;
  *(OOC_INT32*)((_check_pointer(i1, 107683))+24) = i0;
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
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 108063))+4);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 108063))+4);
      i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 108068)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i2);
      type = (OOC_SymbolTable__Type)i1;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 108095)))), &_td_OOC_SymbolTable__RecordDesc);
      if (i2) goto l15;
      i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 108268)))), &_td_OOC_SymbolTable__PointerDesc);
      if (i0) goto l9;
      i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 108357)))), &_td_OOC_SymbolTable__TypeVarDesc);
      if (i0) goto l7;
      return 0u;
      goto l24;
l7:
      return 1u;
      goto l24;
l9:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 108316))+40);
      i0 = OOC_SymbolTable_TypeRules__IsRecord((OOC_SymbolTable__Type)i0);
      if (i0) goto l12;
      i0=0u;
      goto l13;
l12:
      i0 = *(OOC_UINT8*)((_check_pointer(i1, 108334))+49);
      i0 = !i0;
      
l13:
      return i0;
      goto l24;
l15:
      i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 108133)))), &_td_OOC_IR__VarDesc));
      if (i1) goto l22;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 108162)))), &_td_OOC_IR__VarDesc, 108162)), 108166))+8);
      i1 = *(OOC_UINT8*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 108176)))), &_td_OOC_SymbolTable__VarDeclDesc, 108176)), 108184))+59);
      if (i1) goto l20;
      i0=0u;
      goto l23;
l20:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 108216)))), &_td_OOC_IR__VarDesc, 108216)), 108220))+8);
      i0 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 108230)))), &_td_OOC_SymbolTable__VarDeclDesc, 108230)), 108238))+64);
      
      goto l23;
l22:
      i0=1u;
l23:
      return i0;
l24:
      _failed_function(107961); return 0;
      ;
    }


  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)referenceType;
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 108553)))), OOC_IR__BuilderDesc_AssertType)),OOC_IR__BuilderDesc_AssertType)((OOC_IR__Builder)i0, (OOC_IR__Expression)i1);
  i2 = (OOC_INT32)OOC_SymbolTable__Expand((OOC_SymbolTable__Type)i2);
  refType = (OOC_SymbolTable__Type)i2;
  i3 = i2==(OOC_INT32)0;
  if (i3) goto l34;
  i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 108656)))), &_td_OOC_SymbolTable__TypeVarDesc);
  if (i3) goto l32;
  i3 = (OOC_INT32)expr;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 108778))+4);
  i2 = OOC_SymbolTable_TypeRules__IsExtensionOf((OOC_SymbolTable__Type)i2, (OOC_SymbolTable__Type)i4);
  i2 = !i2;
  if (i2) goto l30;
  i0 = OOC_IR__BuilderDesc_NewTypeTest_HasDynamicType((OOC_IR__Expression)i3);
  i0 = !i0;
  if (i0) goto l28;
  i0 = (OOC_INT32)expr;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 109203))+4);
  i2 = (OOC_INT32)refType;
  i1 = OOC_SymbolTable_TypeRules__SameType((OOC_SymbolTable__Type)i2, (OOC_SymbolTable__Type)i1);
  if (!i1) goto l11;
  i1 = (OOC_INT32)referenceType;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 109265));
  i3 = (OOC_INT32)b;
  OOC_IR__BuilderDesc_WarnSym((OOC_IR__Builder)i3, 61, (OOC_Scanner_SymList__Symbol)i1);
l11:
  origExpr = (OOC_IR__Expression)i0;
  i1 = (OOC_INT32)sym;
  i3 = *(OOC_INT32*)((_check_pointer(i1, 109381))+16);
  i4 = (OOC_INT32)OOC_Config_StdPragmas__derefCheck;
  i5 = (OOC_INT32)b;
  i3 = OOC_IR__GetPragmaValue((OOC_IR__Builder)i5, (Config_Section_Options__Option)i4, i3);
  checkPointer = i3;
  i4 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 109404)))), &_td_OOC_IR__DerefDesc);
  if (i4) goto l22;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 109474))+4);
  i4 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 109480)))), &_td_OOC_SymbolTable__PointerDesc);
  if (i4) goto l16;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 109504))+4);
  i4 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 109510)))), &_td_OOC_SymbolTable__TypeVarDesc);
  
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
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 109440)))), &_td_OOC_IR__DerefDesc, 109440)), 109446))+8);
  expr = (OOC_IR__Expression)i4;
  
l23:
  i5 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__TypeTest.baseTypes[0]);
  test = (OOC_IR__TypeTest)i5;
  i6 = (OOC_INT32)referenceType;
  i7 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 109632)))), &_td_OOC_IR__TypeRefDesc);
  if (i7) goto l26;
  i6=(OOC_INT32)0;
  goto l27;
l26:
  i6 = _type_guard(i6, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 109682)))), &_td_OOC_IR__TypeRefDesc, 109682);
  
l27:
  OOC_IR__InitTypeTest((OOC_IR__TypeTest)i5, (OOC_Scanner_SymList__Symbol)i1, (OOC_IR__Expression)i4, (OOC_SymbolTable__Type)i2, i3, (OOC_IR__Expression)i0, (OOC_IR__TypeRef)i6);
  return (OOC_IR__Expression)i5;
  goto l35;
l28:
  i0 = (OOC_INT32)expr;
  i1 = (OOC_INT32)b;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 109153));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 109123)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i1, 43, (OOC_Scanner_SymList__Symbol)i0);
  return (OOC_IR__Expression)i0;
  goto l35;
l30:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 108847));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 108804)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i0, 17, (OOC_Scanner_SymList__Symbol)i1);
  return (OOC_IR__Expression)i0;
  goto l35;
l32:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 108730));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 108691)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i0, 67, (OOC_Scanner_SymList__Symbol)i1);
  return (OOC_IR__Expression)i0;
  goto l35;
l34:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 108624))+20);
  return (OOC_IR__Expression)i0;
l35:
  _failed_function(107751); return 0;
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 110016)))), OOC_IR__VisitorDesc_VisitTypeTest)),OOC_IR__VisitorDesc_VisitTypeTest)((OOC_IR__Visitor)i0, (OOC_IR__TypeTest)i1);
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
  *(OOC_INT32*)((_check_pointer(i2, 110390))+8) = i0;
  i0 = checkPointer;
  *(OOC_UINT8*)((_check_pointer(i2, 110415))+12) = i0;
  i0 = checkType;
  *(OOC_UINT8*)((_check_pointer(i2, 110456))+13) = i0;
  return;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_NewTypeGuard(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression design, OOC_IR__TypeRef ref) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  OOC_SymbolTable__Type guardType;
  OOC_IR__Expression test;
  OOC_IR__TypeGuard guard;

  i0 = (OOC_INT32)ref;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 110733))+12);
  guardType = (OOC_SymbolTable__Type)i1;
  i2 = (OOC_INT32)b;
  i3 = (OOC_INT32)design;
  i4 = (OOC_INT32)sym;
  OOC_IR__BuilderDesc_CheckFunctionOp((OOC_IR__Builder)i2, (OOC_IR__Expression)i3, (OOC_Scanner_SymList__Symbol)i4);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 110789)))), OOC_IR__BuilderDesc_NewTypeTest)),OOC_IR__BuilderDesc_NewTypeTest)((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i4, (OOC_IR__Expression)i3, (OOC_IR__Expression)i0);
  test = (OOC_IR__Expression)i0;
  i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 110831)))), &_td_OOC_IR__TypeTestDesc);
  if (i3) goto l3;
  return (OOC_IR__Expression)i0;
  goto l4;
l3:
  i3 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__TypeGuard.baseTypes[0]);
  guard = (OOC_IR__TypeGuard)i3;
  i5 = *(OOC_INT32*)((_check_pointer(i4, 111063))+16);
  i6 = (OOC_INT32)OOC_Config_StdPragmas__typeGuard;
  i5 = OOC_IR__GetPragmaValue((OOC_IR__Builder)i2, (Config_Section_Options__Option)i6, i5);
  i6 = *(OOC_INT32*)((_check_pointer(i4, 110995))+16);
  i7 = (OOC_INT32)OOC_Config_StdPragmas__derefCheck;
  i2 = OOC_IR__GetPragmaValue((OOC_IR__Builder)i2, (Config_Section_Options__Option)i7, i6);
  i1 = (OOC_INT32)OOC_SymbolTable__Expand((OOC_SymbolTable__Type)i1);
  OOC_IR__InitTypeGuard((OOC_IR__TypeGuard)i3, (OOC_Scanner_SymList__Symbol)i4, (OOC_SymbolTable__Type)i1, (OOC_IR__TypeTest)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 110922)))), &_td_OOC_IR__TypeTestDesc, 110922)), i2, i5);
  return (OOC_IR__Expression)i3;
l4:
  _failed_function(110528); return 0;
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 111294)))), OOC_IR__VisitorDesc_VisitTypeGuard)),OOC_IR__VisitorDesc_VisitTypeGuard)((OOC_IR__Visitor)i0, (OOC_IR__TypeGuard)i1);
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
  *(OOC_INT32*)((_check_pointer(i2, 111618))+8) = i0;
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
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 112131))+28);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 112350)))), OOC_IR__VisitorDesc_VisitModuleRef)),OOC_IR__VisitorDesc_VisitModuleRef)((OOC_IR__Visitor)i0, (OOC_IR__ModuleRef)i1);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 113076)))), OOC_IR__VisitorDesc_VisitPredefProc)),OOC_IR__VisitorDesc_VisitPredefProc)((OOC_IR__Visitor)i0, (OOC_IR__PredefProc)i1);
  return;
  ;
}

static void OOC_IR__InitProcedureRef(OOC_IR__ProcedureRef procRef, OOC_Scanner_SymList__Symbol name, OOC_SymbolTable__ProcDecl decl) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)decl;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 113363))+64);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 113805)))), OOC_IR__VisitorDesc_VisitProcedureRef)),OOC_IR__VisitorDesc_VisitProcedureRef)((OOC_IR__Visitor)i0, (OOC_IR__ProcedureRef)i1);
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
  *(OOC_INT32*)((_check_pointer(i3, 114159))+12) = i0;
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
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 114410))+48);
  qualType = (OOC_SymbolTable__Type)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 114433))+28);
  i2 = i2!=(OOC_INT32)0;
  if (i2) goto l3;
  i2=0u;
  goto l5;
l3:
  i2 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 114463)))), &_td_OOC_SymbolTable__TypeVarDesc));
  
l5:
  if (!i2) goto l16;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 114587))+28);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 114596))+20);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 114603)), 0);
  i2 = (OOC_INT32)RT0__NewObject(_td_OOC_SymbolTable__TypeRefArray.baseTypes[0], i2);
  arguments = (OOC_SymbolTable__TypeRefArray)i2;
  i = 0;
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i2, 114641)), 0);
  i4 = 0<i3;
  if (!i4) goto l15;
  i4 = (OOC_INT32)&_td_OOC_SymbolTable__TypeRef;
  i5=0;
l10_loop:
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 114695))+28);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 114704))+20);
  i6 = _check_pointer(i6, 114711);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i5, i7, OOC_UINT32, 114711))*4);
  i7 = OOC_ARRAY_LENGTH((_check_pointer(i2, 114682)), 0);
  i7 = _check_index(i5, i7, OOC_UINT32, 114682);
  i7 = _check_pointer(i2, 114682);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 114714))+40);
  OOC_SymbolTable__InitTypeRef((void*)(i7+(_check_index(i5, i8, OOC_UINT32, 114682))*8), (RT0__Struct)i4, (OOC_SymbolTable__Type)i6);
  i5 = i5+1;
  i = i5;
  i6 = i5<i3;
  if (i6) goto l10_loop;
l15:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 114781))+20);
  i1 = (OOC_INT32)OOC_SymbolTable__NewQualType((OOC_SymbolTable__Item)(OOC_INT32)0, (OOC_SymbolTable__Position)i3, (OOC_SymbolTable__Type)i1, (OOC_SymbolTable__TypeRefArray)i2);
  qualType = (OOC_SymbolTable__Type)i1;
  
l16:
  i2 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__TypeRef.baseTypes[0]);
  typeRef = (OOC_IR__TypeRef)i2;
  i3 = (OOC_INT32)b;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 114912))+24);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 115131)))), OOC_IR__VisitorDesc_VisitTypeRef)),OOC_IR__VisitorDesc_VisitTypeRef)((OOC_IR__Visitor)i0, (OOC_IR__TypeRef)i1);
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
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 115697))+57);
  if (i2) goto l3;
  i2=0u;
  goto l5;
l3:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 115716))+48);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 115721))+28);
  i2 = i2!=(OOC_INT32)0;
  
l5:
  if (i2) goto l7;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 117343))+48);
  i2 = (OOC_INT32)OOC_SymbolTable__Expand((OOC_SymbolTable__Type)i2);
  
  goto l53;
l7:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 115988))+48);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 115993))+28);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 116002))+20);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 116009)), 0);
  i2 = (OOC_INT32)RT0__NewObject(_td_OOC_SymbolTable__TypeRefArray.baseTypes[0], i2);
  args = (OOC_SymbolTable__TypeRefArray)i2;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 116028))+48);
  i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 116034)))), &_td_OOC_SymbolTable__PointerDesc);
  if (i3) goto l10;
  i3=0u;
  goto l12;
l10:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 116066))+48);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 116076)))), &_td_OOC_SymbolTable__PointerDesc, 116076)), 116084))+40);
  i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 116094)))), &_td_OOC_SymbolTable__QualTypeDesc);
  
l12:
  if (i3) goto l22;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 117041))+48);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 117046))+28);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 117055))+20);
  params = (OOC_SymbolTable__TypeVarArray)i3;
  i = 0;
  i4 = OOC_ARRAY_LENGTH((_check_pointer(i2, 117094)), 0);
  i5 = 0<i4;
  if (!i5) goto l52;
  i5 = (OOC_INT32)&_td_OOC_SymbolTable__TypeRef;
  i6=0;
l16_loop:
  i7 = _check_pointer(i3, 117143);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i9 = OOC_ARRAY_LENGTH((_check_pointer(i2, 117132)), 0);
  i9 = _check_index(i6, i9, OOC_UINT32, 117132);
  i9 = _check_pointer(i2, 117132);
  i10 = OOC_ARRAY_LENGTH(i9, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i6, i8, OOC_UINT32, 117143))*4);
  OOC_SymbolTable__InitTypeRef((void*)(i9+(_check_index(i6, i10, OOC_UINT32, 117132))*8), (RT0__Struct)i5, (OOC_SymbolTable__Type)i7);
  i6 = i6+1;
  i = i6;
  i7 = i6<i4;
  if (i7) goto l16_loop;
  goto l52;
l22:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 116432))+48);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 116442)))), &_td_OOC_SymbolTable__PointerDesc, 116442)), 116450))+40);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 116477)))), &_td_OOC_SymbolTable__QualTypeDesc, 116477)), 116486))+40);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 116500)))), &_td_OOC_SymbolTable__RecordDesc, 116500)), 116507))+28);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 116516))+20);
  params = (OOC_SymbolTable__TypeVarArray)i3;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 116551))+48);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 116561)))), &_td_OOC_SymbolTable__PointerDesc, 116561)), 116569))+40);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 116583)))), &_td_OOC_SymbolTable__QualTypeDesc, 116583)), 116592))+48);
  recordArgs = (OOC_SymbolTable__TypeRefArray)i4;
  i = 0;
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i2, 116634)), 0);
  i6 = 0<i5;
  if (!i6) goto l52;
  i6 = (OOC_INT32)&_td_OOC_SymbolTable__TypeRef;
  i7=0;
l25_loop:
  j = 0;
  i8 = OOC_ARRAY_LENGTH((_check_pointer(i4, 116695)), 0);
  i8 = 0!=i8;
  if (i8) goto l28;
  i8=0u;
  goto l30;
l28:
  i8 = _check_pointer(i4, 116728);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i10 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 116743))+48);
  i10 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i10, 116748))+28);
  i10 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i10, 116757))+20);
  i10 = _check_pointer(i10, 116764);
  i11 = OOC_ARRAY_LENGTH(i10, 0);
  i8 = (OOC_INT32)*(OOC_INT32*)(i8+(_check_index(0, i9, OOC_UINT32, 116728))*8);
  i9 = (OOC_INT32)*(OOC_INT32*)(i10+(_check_index(i7, i11, OOC_UINT32, 116764))*4);
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
  i9 = OOC_ARRAY_LENGTH((_check_pointer(i4, 116695)), 0);
  i9 = i8!=i9;
  if (i9) goto l36;
  i9=0u;
  goto l38;
l36:
  i9 = _check_pointer(i4, 116728);
  i10 = OOC_ARRAY_LENGTH(i9, 0);
  i11 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 116743))+48);
  i11 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i11, 116748))+28);
  i11 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i11, 116757))+20);
  i11 = _check_pointer(i11, 116764);
  i12 = OOC_ARRAY_LENGTH(i11, 0);
  i9 = (OOC_INT32)*(OOC_INT32*)(i9+(_check_index(i8, i10, OOC_UINT32, 116728))*8);
  i10 = (OOC_INT32)*(OOC_INT32*)(i11+(_check_index(i7, i12, OOC_UINT32, 116764))*4);
  i9 = i9!=i10;
  
l38:
  if (i9) goto l33_loop;
l42:
  i9 = OOC_ARRAY_LENGTH((_check_pointer(i4, 116839)), 0);
  i9 = i8==i9;
  if (i9) goto l45;
  i9 = _check_pointer(i3, 116974);
  i10 = OOC_ARRAY_LENGTH(i9, 0);
  i11 = OOC_ARRAY_LENGTH((_check_pointer(i2, 116963)), 0);
  i11 = _check_index(i7, i11, OOC_UINT32, 116963);
  i11 = _check_pointer(i2, 116963);
  i12 = OOC_ARRAY_LENGTH(i11, 0);
  i8 = (OOC_INT32)*(OOC_INT32*)(i9+(_check_index(i8, i10, OOC_UINT32, 116974))*4);
  OOC_SymbolTable__InitTypeRef((void*)(i11+(_check_index(i7, i12, OOC_UINT32, 116963))*8), (RT0__Struct)i6, (OOC_SymbolTable__Type)i8);
  goto l46;
l45:
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 116889))+48);
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i8, 116894))+28);
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i8, 116903))+20);
  i8 = _check_pointer(i8, 116910);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i10 = OOC_ARRAY_LENGTH((_check_pointer(i2, 116880)), 0);
  i10 = _check_index(i7, i10, OOC_UINT32, 116880);
  i10 = _check_pointer(i2, 116880);
  i11 = OOC_ARRAY_LENGTH(i10, 0);
  i8 = (OOC_INT32)*(OOC_INT32*)(i8+(_check_index(i7, i9, OOC_UINT32, 116910))*4);
  OOC_SymbolTable__InitTypeRef((void*)(i10+(_check_index(i7, i11, OOC_UINT32, 116880))*8), (RT0__Struct)i6, (OOC_SymbolTable__Type)i8);
l46:
  i7 = i7+1;
  i = i7;
  i8 = i7<i5;
  if (i8) goto l25_loop;
l52:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 117275))+48);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 117280))+28);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 117211))+48);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 117216))+20);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 117289))+20);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 117231))+48);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 117568)))), OOC_IR__VisitorDesc_VisitVar)),OOC_IR__VisitorDesc_VisitVar)((OOC_IR__Visitor)i0, (OOC_IR__Var)i1);
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
  *(OOC_INT32*)((_check_pointer(i1, 118151))+8) = i0;
  i0 = code;
  *(OOC_INT32*)((_check_pointer(i1, 118187))+12) = i0;
  i0 = disabled;
  *(OOC_UINT8*)((_check_pointer(i1, 118213))+16) = i0;
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
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 118512)))), OOC_IR__BuilderDesc_AssertBoolean)),OOC_IR__BuilderDesc_AssertBoolean)((OOC_IR__Builder)i2, (OOC_IR__Expression)i1);
  
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 118940)))), OOC_IR__VisitorDesc_VisitAssert)),OOC_IR__VisitorDesc_VisitAssert)((OOC_IR__Visitor)i0, (OOC_IR__Assert)i1);
  return;
  ;
}

void OOC_IR__InitAssignment(OOC_IR__Assignment assignment, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression variable, OOC_IR__Expression value) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)assignment;
  OOC_IR__InitStatement((OOC_IR__Statement)i1, (OOC_Scanner_SymList__Symbol)i0);
  i0 = (OOC_INT32)variable;
  *(OOC_INT32*)((_check_pointer(i1, 119269))+8) = i0;
  i0 = (OOC_INT32)value;
  *(OOC_INT32*)((_check_pointer(i1, 119307))+12) = i0;
  return;
  ;
}

void OOC_IR__BuilderDesc_AssertVar(OOC_IR__Builder b, OOC_IR__Expression expr) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)expr;
  i1 = (OOC_INT32)b;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 119435));
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 119448))+4);
  i2 = OOC_SymbolTable_TypeRules__IsReadOnlyType((OOC_SymbolTable__Module)i2, (OOC_SymbolTable__Type)i3);
  if (i2) goto l36;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 119531)))), &_td_OOC_IR__VarDesc);
  if (i2) goto l23;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 119801)))), &_td_OOC_IR__DerefDesc);
  if (i2) goto l37;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 119881)))), &_td_OOC_IR__IndexDesc);
  if (i2) goto l20;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 119977)))), &_td_OOC_IR__SelectFieldDesc);
  if (i2) goto l15;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 120203)))), &_td_OOC_IR__TypeGuardDesc);
  if (i2) goto l13;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 120340));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 120313)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 29, (OOC_Scanner_SymList__Symbol)i0);
  goto l37;
l13:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 120243))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 120249))+8);
  OOC_IR__BuilderDesc_AssertVar((OOC_IR__Builder)i1, (OOC_IR__Expression)i0);
  goto l37;
l15:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 120020))+8);
  OOC_IR__BuilderDesc_AssertVar((OOC_IR__Builder)i1, (OOC_IR__Expression)i2);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 120108))+12);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 120094));
  i2 = OOC_SymbolTable_TypeRules__IsReadOnly((OOC_SymbolTable__Module)i3, (OOC_SymbolTable__Declaration)i2);
  if (!i2) goto l37;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 120165))+16);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 120133)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 34, (OOC_Scanner_SymList__Symbol)i0);
  goto l37;
l20:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 119918))+8);
  OOC_IR__BuilderDesc_AssertVar((OOC_IR__Builder)i1, (OOC_IR__Expression)i0);
  goto l37;
l23:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 119581))+8);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 119567));
  i2 = OOC_SymbolTable_TypeRules__IsReadOnly((OOC_SymbolTable__Module)i3, (OOC_SymbolTable__Declaration)i2);
  if (i2) goto l33;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 119664))+8);
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 119670)))), &_td_OOC_SymbolTable__VarDeclDesc);
  if (i2) goto l28;
  i2=0u;
  goto l30;
l28:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 119692))+8);
  i2 = *(OOC_UINT8*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 119702)))), &_td_OOC_SymbolTable__VarDeclDesc, 119702)), 119710))+62);
  
l30:
  if (!i2) goto l37;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 119769));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 119738)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 42, (OOC_Scanner_SymList__Symbol)i0);
  goto l37;
l33:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 119637));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 119605)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 34, (OOC_Scanner_SymList__Symbol)i0);
  goto l37;
l36:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 119499));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 119467)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 34, (OOC_Scanner_SymList__Symbol)i0);
l37:
  return;
  ;
}

OOC_IR__Statement OOC_IR__BuilderDesc_NewAssignment(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression variable, OOC_IR__Expression value) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_SymbolTable__Type valueType;

  i0 = (OOC_INT32)variable;
  i1 = (OOC_INT32)b;
  OOC_IR__BuilderDesc_AssertVar((OOC_IR__Builder)i1, (OOC_IR__Expression)i0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 120667))+4);
  i3 = (OOC_INT32)sym;
  OOC_IR__MakeAssignmentCompatible((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i3, (void*)(OOC_INT32)&value, (OOC_SymbolTable__Type)i2);
  i2 = (OOC_INT32)value;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 120698))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 120698))+4);
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 120703)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i2);
  valueType = (OOC_SymbolTable__Type)i2;
  i4 = OOC_SymbolTable_TypeRules__IsStringConst((OOC_SymbolTable__Type)i2);
  if (i4) goto l11;
  i4 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 120968)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (i4) goto l5;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 120996)))), &_td_OOC_SymbolTable__RecordDesc);
  
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
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 121091)))), OOC_IR__BuilderDesc_NewCopy)),OOC_IR__BuilderDesc_NewCopy)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i3, (OOC_IR__Expression)i2, (OOC_IR__Expression)i0);
  return (OOC_IR__Statement)i0;
  goto l12;
l11:
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 120916)))), OOC_IR__BuilderDesc_NewLen)),OOC_IR__BuilderDesc_NewLen)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i3, (OOC_IR__Expression)i0, 0);
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 120907)))), OOC_IR__BuilderDesc_Fold)),OOC_IR__BuilderDesc_Fold)((OOC_IR__Builder)i1, (OOC_IR__Expression)i2);
  i4 = (OOC_INT32)value;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 120836)))), OOC_IR__BuilderDesc_NewCopyString)),OOC_IR__BuilderDesc_NewCopyString)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i3, (OOC_IR__Expression)i4, (OOC_IR__Expression)i0, (OOC_IR__Expression)i2);
  return (OOC_IR__Statement)i0;
l12:
  _failed_function(120409); return 0;
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 121441)))), OOC_IR__VisitorDesc_VisitAssignment)),OOC_IR__VisitorDesc_VisitAssignment)((OOC_IR__Visitor)i0, (OOC_IR__Assignment)i1);
  return;
  ;
}

static void OOC_IR__InitAssignOp(OOC_IR__AssignOp ao, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression op) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)op;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 121683)))), &_td_OOC_IR__BinaryArithDesc);
  if (i1) goto l7;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 121754)))), &_td_OOC_IR__ChangeElementDesc);
  if (i1) goto l5;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 121750)))), 121750);
  goto l8;
l5:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 121806))+12);
  i2 = (OOC_INT32)sym;
  i3 = (OOC_INT32)ao;
  OOC_IR__InitAssignment((OOC_IR__Assignment)i3, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i1, (OOC_IR__Expression)i0);
  goto l8;
l7:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 121733))+12);
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
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 121968)))), &_td_OOC_IR__ConstDesc);
  if (i1) goto l3;
  i1 = (OOC_INT32)sym;
  i2 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__AssignOp.baseTypes[0]);
  OOC_IR__InitAssignOp((OOC_IR__AssignOp)i2, (OOC_Scanner_SymList__Symbol)i1, (OOC_IR__Expression)i0);
  return (OOC_IR__Expression)i2;
  goto l4;
l3:
  i0 = (OOC_INT32)b;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 121993))+20);
  return (OOC_IR__Expression)i0;
l4:
  _failed_function(121871); return 0;
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 122301)))), OOC_IR__VisitorDesc_VisitAssignOp)),OOC_IR__VisitorDesc_VisitAssignOp)((OOC_IR__Visitor)i0, (OOC_IR__AssignOp)i1);
  return;
  ;
}

static void OOC_IR__InitCall(OOC_IR__Call call, OOC_IR__Expression design, OOC_IR__ExpressionList arguments, OOC_SymbolTable__VarDeclArray formalPars) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_SymbolTable__Type resultType;

  i0 = (OOC_INT32)design;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 122644));
  i2 = (OOC_INT32)call;
  OOC_IR__InitStatement((OOC_IR__Statement)i2, (OOC_Scanner_SymList__Symbol)i1);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 122709))+4);
  i1 = (OOC_INT32)OOC_SymbolTable_TypeRules__FunctionResultType((OOC_SymbolTable__Type)i1);
  i1 = (OOC_INT32)OOC_SymbolTable__Expand((OOC_SymbolTable__Type)i1);
  resultType = (OOC_SymbolTable__Type)i1;
  i3 = i1!=0;
  if (!i3) goto l4;
  *(OOC_INT32*)((_check_pointer(i2, 122800))+4) = i1;
l4:
  *(OOC_INT32*)((_check_pointer(i2, 122838))+8) = i0;
  i0 = (OOC_INT32)arguments;
  *(OOC_INT32*)((_check_pointer(i2, 122866))+12) = i0;
  i0 = (OOC_INT32)formalPars;
  *(OOC_INT32*)((_check_pointer(i2, 122900))+16) = i0;
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 123080)))), OOC_IR__VisitorDesc_VisitCall)),OOC_IR__VisitorDesc_VisitCall)((OOC_IR__Visitor)i0, (OOC_IR__Call)i1);
  return;
  ;
}

static void OOC_IR__InitCopy(OOC_IR__Copy cp, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression source, OOC_IR__Expression dest, OOC_CHAR8 checkDynamicType) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)cp;
  OOC_IR__InitStatement((OOC_IR__Statement)i1, (OOC_Scanner_SymList__Symbol)i0);
  i0 = (OOC_INT32)source;
  *(OOC_INT32*)((_check_pointer(i1, 123379))+8) = i0;
  i0 = (OOC_INT32)dest;
  *(OOC_INT32*)((_check_pointer(i1, 123405))+12) = i0;
  i0 = checkDynamicType;
  *(OOC_UINT8*)((_check_pointer(i1, 123427))+16) = i0;
  return;
  ;
}

OOC_IR__Copy OOC_IR__BuilderDesc_NewCopy(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression source, OOC_IR__Expression dest) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  auto OOC_CHAR8 OOC_IR__BuilderDesc_NewCopy_HasDynamicType(OOC_IR__Expression dest);
    
    OOC_CHAR8 OOC_IR__BuilderDesc_NewCopy_HasDynamicType(OOC_IR__Expression dest) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)dest;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 123695))+4);
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 123702)))), &_td_OOC_SymbolTable__RecordDesc);
      if (i1) goto l3;
      i1=0u;
      goto l5;
l3:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 123723))+4);
      i1 = *(OOC_UINT8*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 123733)))), &_td_OOC_SymbolTable__RecordDesc, 123733)), 123740))+38);
      
l5:
      if (!i1) goto l14;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 123777)))), &_td_OOC_IR__DerefDesc);
      if (i1) goto l12;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 123835)))), &_td_OOC_IR__VarDesc);
      if (!i1) goto l14;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 123870)))), &_td_OOC_IR__VarDesc, 123870)), 123874))+8);
      i0 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 123885)))), &_td_OOC_SymbolTable__VarDeclDesc, 123885)), 123893))+59);
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
  i1 = *(OOC_INT32*)((_check_pointer(i1, 124094))+16);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 124338)))), OOC_IR__VisitorDesc_VisitCopy)),OOC_IR__VisitorDesc_VisitCopy)((OOC_IR__Visitor)i0, (OOC_IR__Copy)i1);
  return;
  ;
}

static void OOC_IR__InitCopyParameter(OOC_IR__CopyParameter cp, OOC_Scanner_SymList__Symbol sym, OOC_IR__Var param) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)cp;
  OOC_IR__InitStatement((OOC_IR__Statement)i1, (OOC_Scanner_SymList__Symbol)i0);
  i0 = (OOC_INT32)param;
  *(OOC_INT32*)((_check_pointer(i1, 124601))+8) = i0;
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 125025)))), OOC_IR__VisitorDesc_VisitCopyParameter)),OOC_IR__VisitorDesc_VisitCopyParameter)((OOC_IR__Visitor)i0, (OOC_IR__CopyParameter)i1);
  return;
  ;
}

static void OOC_IR__InitCopyString(OOC_IR__CopyString cp, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression source, OOC_IR__Expression dest, OOC_IR__Expression maxLength) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)cp;
  OOC_IR__InitStatement((OOC_IR__Statement)i1, (OOC_Scanner_SymList__Symbol)i0);
  i0 = (OOC_INT32)source;
  *(OOC_INT32*)((_check_pointer(i1, 125339))+8) = i0;
  i0 = (OOC_INT32)dest;
  *(OOC_INT32*)((_check_pointer(i1, 125365))+12) = i0;
  i0 = (OOC_INT32)maxLength;
  *(OOC_INT32*)((_check_pointer(i1, 125387))+16) = i0;
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
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 125705))+4);
  i2 = OOC_SymbolTable_TypeRules__IsArrayOfChar((OOC_SymbolTable__Type)i2, 1u);
  i2 = !i2;
  if (!i2) goto l3;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 125761));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 125730)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 48, (OOC_Scanner_SymList__Symbol)i2);
l3:
  i2 = (OOC_INT32)source;
  i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 125797)))), &_td_OOC_IR__ConstDesc);
  if (i3) goto l9;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 126267))+4);
  i3 = OOC_SymbolTable_TypeRules__IsArrayOfChar((OOC_SymbolTable__Type)i3, 1u);
  i3 = !i3;
  if (!i3) goto l14;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 126325));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 126292)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 48, (OOC_Scanner_SymList__Symbol)i2);
  goto l14;
l9:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 126054))+4);
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
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 126136));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 126103)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 48, (OOC_Scanner_SymList__Symbol)i2);
l14:
  i2 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__CopyString.baseTypes[0]);
  cp = (OOC_IR__CopyString)i2;
  i3 = (OOC_INT32)maxLength;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 126404)))), OOC_IR__BuilderDesc_Fold)),OOC_IR__BuilderDesc_Fold)((OOC_IR__Builder)i1, (OOC_IR__Expression)i3);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 126616)))), OOC_IR__VisitorDesc_VisitCopyString)),OOC_IR__VisitorDesc_VisitCopyString)((OOC_IR__Visitor)i0, (OOC_IR__CopyString)i1);
  return;
  ;
}

void OOC_IR__InitExit(OOC_IR__Exit exit, OOC_Scanner_SymList__Symbol sym) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)exit;
  OOC_IR__InitStatement((OOC_IR__Statement)i1, (OOC_Scanner_SymList__Symbol)i0);
  *(OOC_INT32*)((_check_pointer(i1, 126853))+8) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i1, 126876))+12) = 0;
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 127213)))), OOC_IR__VisitorDesc_VisitExit)),OOC_IR__VisitorDesc_VisitExit)((OOC_IR__Visitor)i0, (OOC_IR__Exit)i1);
  return;
  ;
}

static void OOC_IR__InitForStatm(OOC_IR__ForStatm forStatm, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression var, OOC_IR__Expression start, OOC_IR__Expression end, OOC_IR__Expression step, OOC_IR__StatementSeq body) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)forStatm;
  OOC_IR__InitStatement((OOC_IR__Statement)i1, (OOC_Scanner_SymList__Symbol)i0);
  i0 = (OOC_INT32)var;
  *(OOC_INT32*)((_check_pointer(i1, 127572))+8) = i0;
  i0 = (OOC_INT32)start;
  *(OOC_INT32*)((_check_pointer(i1, 127598))+12) = i0;
  i0 = (OOC_INT32)end;
  *(OOC_INT32*)((_check_pointer(i1, 127628))+16) = i0;
  i0 = (OOC_INT32)step;
  *(OOC_INT32*)((_check_pointer(i1, 127654))+20) = i0;
  i0 = (OOC_INT32)body;
  *(OOC_INT32*)((_check_pointer(i1, 127682))+24) = i0;
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
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 127986)))), OOC_IR__BuilderDesc_NewConst)),OOC_IR__BuilderDesc_NewConst)((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i3, (OOC_SymbolTable__Type)i1, (Object_Boxed__Object)i0);
  step = (OOC_IR__Expression)i0;
l3:
  i0 = (OOC_INT32)var;
  i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 128089)))), &_td_OOC_IR__VarDesc));
  if (i1) goto l21;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 128175))+4);
  i1 = OOC_SymbolTable_TypeRules__IsIntegerType((OOC_SymbolTable__Type)i1);
  i1 = !i1;
  if (i1) goto l19;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 128258))+4);
  i2 = (OOC_INT32)b;
  i1 = OOC_IR__BuilderDesc_Widen((OOC_IR__Builder)i2, (void*)(OOC_INT32)&step, (OOC_SymbolTable__Type)i1);
  i1 = !i1;
  if (i1) goto l17;
  i1 = (OOC_INT32)start;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 128383))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 128366));
  OOC_IR__MakeAssignmentCompatible((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i1, (void*)(OOC_INT32)&start, (OOC_SymbolTable__Type)i3);
  i1 = (OOC_INT32)end;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 128445))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 128430));
  OOC_IR__MakeAssignmentCompatible((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i1, (void*)(OOC_INT32)&end, (OOC_SymbolTable__Type)i3);
  i1 = (OOC_INT32)step;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 128469)))), OOC_IR__BuilderDesc_AssertConst)),OOC_IR__BuilderDesc_AssertConst)((OOC_IR__Builder)i2, (OOC_IR__Expression)i1);
  step = (OOC_IR__Expression)i1;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 128522))+4);
  i3 = OOC_SymbolTable_TypeRules__IsIntegerType((OOC_SymbolTable__Type)i3);
  if (i3) goto l12;
  i3=0u;
  goto l14;
l12:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 128564)))), &_td_OOC_IR__ConstDesc, 128564)), 128570))+8);
  i4 = (OOC_INT32)Object_BigInt__zero;
  i3 = Object_BigInt__BigIntDesc_Cmp((Object_BigInt__BigInt)i4, (Object__Object)i3);
  i3 = i3==0;
  
l14:
  if (!i3) goto l22;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 128624));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 128598)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i2, 31, (OOC_Scanner_SymList__Symbol)i1);
  goto l22;
l17:
  i1 = (OOC_INT32)step;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 128309));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 128278)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i2, 30, (OOC_Scanner_SymList__Symbol)i1);
  goto l22;
l19:
  i1 = (OOC_INT32)b;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 128220));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 128195)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 19, (OOC_Scanner_SymList__Symbol)i2);
  goto l22;
l21:
  i1 = (OOC_INT32)b;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 128135));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 128109)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 29, (OOC_Scanner_SymList__Symbol)i2);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 128939)))), OOC_IR__VisitorDesc_VisitForStatm)),OOC_IR__VisitorDesc_VisitForStatm)((OOC_IR__Visitor)i0, (OOC_IR__ForStatm)i1);
  return;
  ;
}

static void OOC_IR__InitIterateArrayStatm(OOC_IR__IterateArrayStatm iterStatm, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression var, OOC_IR__Expression range, OOC_IR__StatementSeq body) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)iterStatm;
  OOC_IR__InitStatement((OOC_IR__Statement)i1, (OOC_Scanner_SymList__Symbol)i0);
  i0 = (OOC_INT32)var;
  *(OOC_INT32*)((_check_pointer(i1, 129343))+8) = i0;
  i0 = (OOC_INT32)range;
  *(OOC_INT32*)((_check_pointer(i1, 129370))+12) = i0;
  i0 = (OOC_INT32)body;
  *(OOC_INT32*)((_check_pointer(i1, 129401))+16) = i0;
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 129644)))), OOC_IR__VisitorDesc_VisitIterateArrayStatm)),OOC_IR__VisitorDesc_VisitIterateArrayStatm)((OOC_IR__Visitor)i0, (OOC_IR__IterateArrayStatm)i1);
  return;
  ;
}

static void OOC_IR__InitIterateObjectStatm(OOC_IR__IterateObjectStatm iterStatm, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression var, OOC_IR__Expression iteratorFactory, OOC_IR__Call stepperCall, OOC_IR__StatementSeq body) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)iterStatm;
  OOC_IR__InitStatement((OOC_IR__Statement)i1, (OOC_Scanner_SymList__Symbol)i0);
  i0 = (OOC_INT32)var;
  *(OOC_INT32*)((_check_pointer(i1, 130092))+8) = i0;
  i0 = (OOC_INT32)iteratorFactory;
  *(OOC_INT32*)((_check_pointer(i1, 130119))+12) = i0;
  i0 = (OOC_INT32)stepperCall;
  *(OOC_INT32*)((_check_pointer(i1, 130170))+16) = i0;
  i0 = (OOC_INT32)body;
  *(OOC_INT32*)((_check_pointer(i1, 130213))+20) = i0;
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 130461)))), OOC_IR__VisitorDesc_VisitIterateObjectStatm)),OOC_IR__VisitorDesc_VisitIterateObjectStatm)((OOC_IR__Visitor)i0, (OOC_IR__IterateObjectStatm)i1);
  return;
  ;
}

OOC_IR__Statement OOC_IR__BuilderDesc_NewIterateStatm(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_SymbolTable__Item context, OOC_IR__Expression var, OOC_IR__Expression sequence, OOC_IR__StatementSeq body) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  Object_BigInt__BigInt v;
  OOC_IR__Expression elem;
  OOC_SymbolTable__ProcDecl stepper;
  OOC_SymbolTable__Record _class;
  OOC_IR__Expression pseudoDesign;
  OOC_IR__ExpressionList arguments;
  OOC_IR__Expression expr;
  auto OOC_SymbolTable__ProcDecl OOC_IR__BuilderDesc_NewIterateStatm_GetStepper(OOC_SymbolTable__Type type, OOC_SymbolTable__Record *_class);
    
    OOC_SymbolTable__ProcDecl OOC_IR__BuilderDesc_NewIterateStatm_GetStepper(OOC_SymbolTable__Type type, OOC_SymbolTable__Record *_class) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_SymbolTable__Name n;
      OOC_SymbolTable__Declaration decl;
      OOC_SymbolTable__FormalPars fp;

      i0 = (OOC_INT32)type;
      i1 = OOC_SymbolTable_TypeRules__IsPointer((OOC_SymbolTable__Type)i0);
      if (!i1) goto l4;
      i0 = (OOC_INT32)OOC_SymbolTable_TypeRules__PointerBaseType((OOC_SymbolTable__Type)i0);
      type = (OOC_SymbolTable__Type)i0;
      
l4:
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 131260)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
      type = (OOC_SymbolTable__Type)i0;
      i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 131296)))), &_td_OOC_SymbolTable__RecordDesc, 131296);
      *_class = (OOC_SymbolTable__Record)i0;
      i1 = (OOC_INT32)sequence;
      i2 = (OOC_INT32)b;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 131335));
      i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 131317)))), OOC_IR__BuilderDesc_GetName2)),OOC_IR__BuilderDesc_GetName2)((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i1, "Next", 5);
      n = (OOC_SymbolTable__Name)i1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 131369))+52);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 131369))+52);
      i3 = (OOC_INT32)context;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 131372)))), OOC_SymbolTable__NamespaceDesc_Identify)),OOC_SymbolTable__NamespaceDesc_Identify)((OOC_SymbolTable__Namespace)i0, (OOC_SymbolTable__Item)i3, (OOC_SymbolTable__Name)i1, 0u);
      decl = (OOC_SymbolTable__Declaration)i0;
      i1 = i0!=0;
      if (!i1) goto l21;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 131446)))), &_td_OOC_SymbolTable__ProcDeclDesc);
      if (!i1) goto l21;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 131484))+64);
      fp = (OOC_SymbolTable__FormalPars)i1;
      i2 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(0);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 131513))+44);
      i2 = i3==i2;
      if (i2) goto l11;
      i2=0u;
      goto l13;
l11:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 131581))+52);
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 131588)), 0);
      i2 = i2==1;
      
l13:
      if (i2) goto l15;
      i1=0u;
      goto l17;
l15:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 131613))+52);
      i1 = _check_pointer(i1, 131620);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 131620))*4);
      i1 = *(OOC_UINT8*)((_check_pointer(i1, 131623))+59);
      
l17:
      if (!i1) goto l21;
      return (OOC_SymbolTable__ProcDecl)i0;
l21:
      return (OOC_SymbolTable__ProcDecl)0;
      ;
    }


  i0 = (OOC_INT32)var;
  i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 131791)))), &_td_OOC_IR__VarDesc));
  if (i1) goto l23;
  i1 = (OOC_INT32)sequence;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 131871))+4);
  i2 = OOC_SymbolTable_TypeRules__IsArray((OOC_SymbolTable__Type)i2);
  if (i2) goto l17;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 132582))+4);
  i0 = OOC_SymbolTable_TypeRules__IsRecordPointer((OOC_SymbolTable__Type)i0);
  i0 = !i0;
  if (i0) goto l15;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 132694))+4);
  i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewIterateStatm_GetStepper((OOC_SymbolTable__Type)i0, (void*)(OOC_INT32)&_class);
  stepper = (OOC_SymbolTable__ProcDecl)i0;
  i1 = i0==0;
  if (i1) goto l13;
  i1 = (OOC_INT32)b;
  i2 = (OOC_INT32)sym;
  i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 132829)))), OOC_IR__BuilderDesc_NewNil)),OOC_IR__BuilderDesc_NewNil)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i2);
  pseudoDesign = (OOC_IR__Expression)i3;
  i4 = (OOC_INT32)sequence;
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 132970));
  i6 = (OOC_INT32)_class;
  i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewSelectProc((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i3, (OOC_SymbolTable__Type)i6, (OOC_SymbolTable__ProcDecl)i0, (OOC_Scanner_SymList__Symbol)i5, 0u);
  pseudoDesign = (OOC_IR__Expression)i0;
  i3 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__ExpressionList.baseTypes[0], 1);
  arguments = (OOC_IR__ExpressionList)i3;
  i5 = _check_pointer(i3, 133032);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i7 = (OOC_INT32)var;
  *(OOC_INT32*)(i5+(_check_index(0, i6, OOC_UINT8, 133032))*4) = i7;
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 133148));
  i6 = (OOC_INT32)context;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 133063)))), OOC_IR__BuilderDesc_NewCall)),OOC_IR__BuilderDesc_NewCall)((OOC_IR__Builder)i1, (OOC_IR__Expression)i0, (OOC_IR__ExpressionList)i3, 1u, (OOC_SymbolTable__Item)i6, (OOC_Scanner_SymList__Symbol)i5);
  expr = (OOC_IR__Expression)i0;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 133174)))), &_td_OOC_IR__CallDesc);
  if (i1) goto l11;
  i0=0;
  goto l12;
l11:
  i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 133220)))), &_td_OOC_IR__CallDesc, 133220);
  
l12:
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__IterateObjectStatm.baseTypes[0]);
  i3 = (OOC_INT32)body;
  OOC_IR__InitIterateObjectStatm((OOC_IR__IterateObjectStatm)i1, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i7, (OOC_IR__Expression)i4, (OOC_IR__Call)i0, (OOC_IR__StatementSeq)i3);
  return (OOC_IR__Statement)i1;
  goto l24;
l13:
  i0 = (OOC_INT32)sequence;
  i1 = (OOC_INT32)b;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 132782));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 132752)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 78, (OOC_Scanner_SymList__Symbol)i0);
  goto l24;
l15:
  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 132638));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 132603)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 77, (OOC_Scanner_SymList__Symbol)i1);
  goto l24;
l17:
  sequence = (OOC_IR__Expression)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 131979))+4);
  i2 = OOC_SymbolTable_TypeRules__IsValidArrayIteratorRange((OOC_SymbolTable__Type)i2);
  i2 = !i2;
  if (i2) goto l20;
  i2 = (OOC_INT32)Object_BigInt__NewInt(0);
  v = (Object_BigInt__BigInt)i2;
  i3 = (OOC_INT32)OOC_SymbolTable_Predef__SmallestIntType((Object_BigInt__BigInt)i2);
  i4 = (OOC_INT32)sym;
  i2 = (OOC_INT32)OOC_IR__NewConst((OOC_Scanner_SymList__Symbol)i4, (OOC_SymbolTable__Type)i3, (Object_Boxed__Object)i2);
  i3 = (OOC_INT32)b;
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 132161)))), OOC_IR__BuilderDesc_NewIndex)),OOC_IR__BuilderDesc_NewIndex)((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i4, (OOC_IR__Expression)i1, (OOC_IR__Expression)i2);
  elem = (OOC_IR__Expression)i2;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 132318))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 132303));
  OOC_IR__MakeAssignmentCompatible((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i4, (void*)(OOC_INT32)&elem, (OOC_SymbolTable__Type)i2);
  goto l21;
l20:
  i2 = (OOC_INT32)b;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 132039));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 132000)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i2, 76, (OOC_Scanner_SymList__Symbol)i3);
l21:
  i2 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__IterateArrayStatm.baseTypes[0]);
  i3 = (OOC_INT32)sym;
  i4 = (OOC_INT32)body;
  OOC_IR__InitIterateArrayStatm((OOC_IR__IterateArrayStatm)i2, (OOC_Scanner_SymList__Symbol)i3, (OOC_IR__Expression)i0, (OOC_IR__Expression)i1, (OOC_IR__StatementSeq)i4);
  return (OOC_IR__Statement)i2;
  goto l24;
l23:
  i1 = (OOC_INT32)b;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 131835));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 131811)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 29, (OOC_Scanner_SymList__Symbol)i0);
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
  *(OOC_INT32*)((_check_pointer(i1, 133857))+8) = i0;
  i0 = (OOC_INT32)pathTrue;
  *(OOC_INT32*)((_check_pointer(i1, 133886))+12) = i0;
  i0 = (OOC_INT32)pathFalse;
  *(OOC_INT32*)((_check_pointer(i1, 133921))+16) = i0;
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
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 134203)))), OOC_IR__BuilderDesc_AssertBoolean)),OOC_IR__BuilderDesc_AssertBoolean)((OOC_IR__Builder)i1, (OOC_IR__Expression)i2);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 134441)))), OOC_IR__VisitorDesc_VisitIfStatm)),OOC_IR__VisitorDesc_VisitIfStatm)((OOC_IR__Visitor)i0, (OOC_IR__IfStatm)i1);
  return;
  ;
}

static void OOC_IR__InitCase(OOC_IR__Case _case, OOC_Scanner_SymList__Symbol sym, OOC_IR__CaseLabels labels, OOC_IR__StatementSeq statmSeq) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)_case;
  OOC_IR__InitStatement((OOC_IR__Statement)i1, (OOC_Scanner_SymList__Symbol)i0);
  i0 = (OOC_INT32)labels;
  *(OOC_INT32*)((_check_pointer(i1, 134743))+8) = i0;
  i0 = (OOC_INT32)statmSeq;
  *(OOC_INT32*)((_check_pointer(i1, 134771))+12) = i0;
  return;
  ;
}

OOC_IR__Case OOC_IR__BuilderDesc_NewCase(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__CaseLabels labels, OOC_IR__StatementSeq statmSeq) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 i;
  OOC_IR__SetRange range;

  i0 = (OOC_INT32)labels;
  i = 0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 135038)), 0);
  i2 = 0<i1;
  if (!i2) goto l8;
  i2 = (OOC_INT32)b;
  i3=0;
l3_loop:
  i4 = _check_pointer(i0, 135067);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 135067))*4);
  i4 = _type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 135071)))), &_td_OOC_IR__SetRangeDesc, 135071);
  range = (OOC_IR__SetRange)i4;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 135123))+8);
  i5 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 135103)))), OOC_IR__BuilderDesc_AssertConst)),OOC_IR__BuilderDesc_AssertConst)((OOC_IR__Builder)i2, (OOC_IR__Expression)i5);
  *(OOC_INT32*)((_check_pointer(i4, 135093))+8) = i5;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 135171))+12);
  i5 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 135151)))), OOC_IR__BuilderDesc_AssertConst)),OOC_IR__BuilderDesc_AssertConst)((OOC_IR__Builder)i2, (OOC_IR__Expression)i5);
  *(OOC_INT32*)((_check_pointer(i4, 135143))+12) = i5;
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 135419)))), OOC_IR__VisitorDesc_VisitCase)),OOC_IR__VisitorDesc_VisitCase)((OOC_IR__Visitor)i0, (OOC_IR__Case)i1);
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
      i4 = _check_pointer(i1, 135877);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 135877))*4);
      i4 = i4!=(OOC_INT32)0;
      if (i4) goto l6;
      i4=0u;
      goto l8;
l6:
      i4 = _check_pointer(i1, 135917);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 135917))*4);
      i4 = OOC_IR__SetRangeDesc_IntersectsWith((OOC_IR__SetRange)i2, (OOC_IR__SetRange)(_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 135921)))), &_td_OOC_IR__SetRangeDesc, 135921)));
      
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
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 136101))+8);
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 136109)), 0);
  i = 0;
  i1 = 0<i0;
  if (!i1) goto l44;
  i1 = !0u;
  i2=0;
l3_loop:
  i3 = (OOC_INT32)_case;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 136136))+8);
  i4 = _check_pointer(i4, 136144);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i2, i5, OOC_UINT32, 136144))*4);
  i4 = _type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 136148)))), &_td_OOC_IR__SetRangeDesc, 136148);
  range = (OOC_IR__SetRange)i4;
  i5 = (OOC_INT32)type;
  i6 = (OOC_INT32)b;
  i7 = OOC_IR__BuilderDesc_Widen((OOC_IR__Builder)i6, (void*)((_check_pointer(i4, 136184))+8), (OOC_SymbolTable__Type)i5);
  i7 = !i7;
  if (i7) goto l38;
  i5 = OOC_IR__BuilderDesc_Widen((OOC_IR__Builder)i6, (void*)((_check_pointer(i4, 136363))+12), (OOC_SymbolTable__Type)i5);
  i5 = !i5;
  if (i5) goto l36;
  i4 = OOC_IR__SetRangeDesc_IsEmpty((OOC_IR__SetRange)i4);
  if (i4) goto l34;
  inUse = 0u;
  j = 0;
  i2 = (OOC_INT32)caseList;
  i2 = _check_pointer(i2, 136723);
  i4 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(0, i4, OOC_UINT32, 136723))*4);
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
  i4 = _check_pointer(i3, 136858);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i2, i5, OOC_UINT32, 136858))*4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 136861))+8);
  i3 = _check_pointer(i3, 136797);
  i5 = OOC_ARRAY_LENGTH(i3, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i5, OOC_UINT32, 136797))*4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 136800))+8);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i4, 136869)), 0);
  i4 = (OOC_INT32)range;
  i2 = OOC_IR__CaseDesc_CheckLabels_IntersectsWith((OOC_IR__SetRange)i4, (OOC_IR__CaseLabels)i2, i3);
  i3 = j;
  inUse = i2;
  i3 = i3+1;
  j = i3;
  i4 = (OOC_INT32)caseList;
  i4 = _check_pointer(i4, 136723);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 136723))*4);
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
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 136959))+8);
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
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 137037));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 137006)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i3, 28, (OOC_Scanner_SymList__Symbol)i2);
  goto l39;
l34:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 136614))+8);
  i3 = _check_pointer(i3, 136622);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i5 = deleted;
  *(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 136622))*4) = 0;
  deleted = (i5+1);
  goto l39;
l36:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 136422))+12);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 136426));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 136389)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i6, 27, (OOC_Scanner_SymList__Symbol)i4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 136446))+8);
  i3 = _check_pointer(i3, 136454);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i5 = deleted;
  *(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 136454))*4) = 0;
  deleted = (i5+1);
  goto l39;
l38:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 136245))+8);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 136251));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 136212)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i6, 27, (OOC_Scanner_SymList__Symbol)i4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 136271))+8);
  i3 = _check_pointer(i3, 136279);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i5 = deleted;
  *(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 136279))*4) = 0;
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
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 137130))+8);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 137138)), 0);
  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__CaseLabels.baseTypes[0], (i2-i0));
  _new = (OOC_IR__CaseLabels)i0;
  j = (-1);
  i = 0;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i0, 137194)), 0);
  i3 = 0<i2;
  if (!i3) goto l59;
  i3=(-1);i4=0;
l49_loop:
  
l50_loop:
  i3 = i3+1;
  j = i3;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 137255))+8);
  i5 = _check_pointer(i5, 137263);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 137263))*4);
  i5 = i5!=0;
  if (!i5) goto l50_loop;
l54:
  i5 = _check_pointer(i0, 137286);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 137297))+8);
  i7 = _check_pointer(i7, 137305);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i3, i8, OOC_UINT32, 137305))*4);
  *(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 137286))*4) = i7;
  i4 = i4+1;
  i = i4;
  i5 = i4<i2;
  if (i5) goto l49_loop;
l59:
  *(OOC_INT32*)((_check_pointer(i1, 137331))+8) = i0;
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
  *(OOC_INT32*)((_check_pointer(i1, 137739))+8) = i0;
  i0 = (OOC_INT32)caseList;
  *(OOC_INT32*)((_check_pointer(i1, 137772))+12) = i0;
  i0 = (OOC_INT32)_default;
  *(OOC_INT32*)((_check_pointer(i1, 137809))+16) = i0;
  i0 = checkMatch;
  *(OOC_UINT8*)((_check_pointer(i1, 137844))+20) = i0;
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
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 138173))+4);
  i2 = OOC_SymbolTable_TypeRules__IsValidCaseSelector((OOC_SymbolTable__Type)i2);
  i2 = !i2;
  if (i2) goto l11;
  i2 = (OOC_INT32)caseList;
  i = 0;
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i2, 138280)), 0);
  i4 = 0<i3;
  if (!i4) goto l12;
  i4 = (OOC_INT32)b;
  i5=0;
l5_loop:
  i6 = _check_pointer(i2, 138304);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 138331))+4);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i5, i7, OOC_UINT32, 138304))*4);
  OOC_IR__CaseDesc_CheckLabels((OOC_IR__Case)i6, (OOC_IR__Builder)i4, (OOC_SymbolTable__Type)i8, (OOC_IR__CaseList)i2);
  i5 = i5+1;
  i = i5;
  i6 = i5<i3;
  if (i6) goto l5_loop;
  goto l12;
l11:
  i2 = (OOC_INT32)b;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 138230));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 138193)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i2, 26, (OOC_Scanner_SymList__Symbol)i3);
l12:
  i2 = (OOC_INT32)sym;
  i3 = *(OOC_INT32*)((_check_pointer(i2, 138501))+16);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 138717)))), OOC_IR__VisitorDesc_VisitCaseStatm)),OOC_IR__VisitorDesc_VisitCaseStatm)((OOC_IR__Visitor)i0, (OOC_IR__CaseStatm)i1);
  return;
  ;
}

static void OOC_IR__InitLoopStatm(OOC_IR__LoopStatm loopStatm, OOC_Scanner_SymList__Symbol sym, OOC_IR__StatementSeq body) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)loopStatm;
  OOC_IR__InitStatement((OOC_IR__Statement)i1, (OOC_Scanner_SymList__Symbol)i0);
  i0 = (OOC_INT32)body;
  *(OOC_INT32*)((_check_pointer(i1, 139034))+8) = i0;
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 139502)))), OOC_IR__VisitorDesc_VisitLoopStatm)),OOC_IR__VisitorDesc_VisitLoopStatm)((OOC_IR__Visitor)i0, (OOC_IR__LoopStatm)i1);
  return;
  ;
}

static void OOC_IR__InitMoveBlock(OOC_IR__MoveBlock move, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression source, OOC_IR__Expression dest, OOC_IR__Expression size) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)move;
  OOC_IR__InitStatement((OOC_IR__Statement)i1, (OOC_Scanner_SymList__Symbol)i0);
  i0 = (OOC_INT32)source;
  *(OOC_INT32*)((_check_pointer(i1, 139816))+8) = i0;
  i0 = (OOC_INT32)dest;
  *(OOC_INT32*)((_check_pointer(i1, 139844))+12) = i0;
  i0 = (OOC_INT32)size;
  *(OOC_INT32*)((_check_pointer(i1, 139868))+16) = i0;
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 140453)))), OOC_IR__VisitorDesc_VisitMoveBlock)),OOC_IR__VisitorDesc_VisitMoveBlock)((OOC_IR__Visitor)i0, (OOC_IR__MoveBlock)i1);
  return;
  ;
}

static void OOC_IR__InitRaise(OOC_IR__Raise raise, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression exception) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)raise;
  OOC_IR__InitStatement((OOC_IR__Statement)i1, (OOC_Scanner_SymList__Symbol)i0);
  i0 = (OOC_INT32)exception;
  *(OOC_INT32*)((_check_pointer(i1, 140719))+8) = i0;
  return;
  ;
}

OOC_IR__Raise OOC_IR__BuilderDesc_NewRaise(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression exception) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)exception;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 140904))+4);
  i1 = OOC_SymbolTable_TypeRules__IsException((OOC_SymbolTable__Type)i1);
  if (i1) goto l3;
  i1 = (OOC_INT32)b;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 141043));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 141012)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 62, (OOC_Scanner_SymList__Symbol)i0);
  return (OOC_IR__Raise)0;
  goto l4;
l3:
  i1 = (OOC_INT32)sym;
  i2 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__Raise.baseTypes[0]);
  OOC_IR__InitRaise((OOC_IR__Raise)i2, (OOC_Scanner_SymList__Symbol)i1, (OOC_IR__Expression)i0);
  return (OOC_IR__Raise)i2;
l4:
  _failed_function(140786); return 0;
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 141235)))), OOC_IR__VisitorDesc_VisitRaise)),OOC_IR__VisitorDesc_VisitRaise)((OOC_IR__Visitor)i0, (OOC_IR__Raise)i1);
  return;
  ;
}

static void OOC_IR__InitRepeatStatm(OOC_IR__RepeatStatm repeatStatm, OOC_Scanner_SymList__Symbol sym, OOC_IR__StatementSeq body, OOC_IR__Expression exitCondition) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)repeatStatm;
  OOC_IR__InitStatement((OOC_IR__Statement)i1, (OOC_Scanner_SymList__Symbol)i0);
  i0 = (OOC_INT32)body;
  *(OOC_INT32*)((_check_pointer(i1, 141585))+8) = i0;
  i0 = (OOC_INT32)exitCondition;
  *(OOC_INT32*)((_check_pointer(i1, 141616))+12) = i0;
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
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 141940)))), OOC_IR__BuilderDesc_AssertBoolean)),OOC_IR__BuilderDesc_AssertBoolean)((OOC_IR__Builder)i1, (OOC_IR__Expression)i2);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 142197)))), OOC_IR__VisitorDesc_VisitRepeatStatm)),OOC_IR__VisitorDesc_VisitRepeatStatm)((OOC_IR__Visitor)i0, (OOC_IR__RepeatStatm)i1);
  return;
  ;
}

static void OOC_IR__InitReturn(OOC_IR__Return _return, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression result) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)_return;
  OOC_IR__InitStatement((OOC_IR__Statement)i1, (OOC_Scanner_SymList__Symbol)i0);
  i0 = (OOC_INT32)result;
  *(OOC_INT32*)((_check_pointer(i1, 142475))+8) = i0;
  *(OOC_INT32*)((_check_pointer(i1, 142505))+12) = 0;
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 142902)))), OOC_IR__VisitorDesc_VisitReturn)),OOC_IR__VisitorDesc_VisitReturn)((OOC_IR__Visitor)i0, (OOC_IR__Return)i1);
  return;
  ;
}

static void OOC_IR__InitCatchClause(OOC_IR__CatchClause _catch, OOC_Scanner_SymList__Symbol sym, OOC_SymbolTable__Type exceptionType, OOC_IR__StatementSeq statmSeq) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)_catch;
  OOC_IR__InitStatement((OOC_IR__Statement)i1, (OOC_Scanner_SymList__Symbol)i0);
  i0 = (OOC_INT32)exceptionType;
  *(OOC_INT32*)((_check_pointer(i1, 143258))+8) = i0;
  i0 = (OOC_INT32)statmSeq;
  *(OOC_INT32*)((_check_pointer(i1, 143300))+12) = i0;
  *(OOC_UINT8*)((_check_pointer(i1, 143332))+16) = 0u;
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
  i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 143603)))), OOC_IR__BuilderDesc_AssertType)),OOC_IR__BuilderDesc_AssertType)((OOC_IR__Builder)i1, (OOC_IR__Expression)i2);
  type = (OOC_SymbolTable__Type)i3;
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 143663));
  i5 = (OOC_INT32)statmSeq;
  OOC_IR__InitCatchClause((OOC_IR__CatchClause)i0, (OOC_Scanner_SymList__Symbol)i4, (OOC_SymbolTable__Type)i3, (OOC_IR__StatementSeq)i5);
  i3 = OOC_SymbolTable_TypeRules__IsException((OOC_SymbolTable__Type)i3);
  i3 = !i3;
  if (!i3) goto l4;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 143758));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 143727)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 62, (OOC_Scanner_SymList__Symbol)i2);
  *(OOC_UINT8*)((_check_pointer(i0, 143776))+16) = 1u;
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 144058)))), OOC_IR__VisitorDesc_VisitCatchClause)),OOC_IR__VisitorDesc_VisitCatchClause)((OOC_IR__Visitor)i0, (OOC_IR__CatchClause)i1);
  return;
  ;
}

static void OOC_IR__InitTryStatm(OOC_IR__TryStatm tryStatm, OOC_Scanner_SymList__Symbol sym, OOC_IR__StatementSeq statmSeq, OOC_IR__CatchList catchList) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)tryStatm;
  OOC_IR__InitStatement((OOC_IR__Statement)i1, (OOC_Scanner_SymList__Symbol)i0);
  i0 = (OOC_INT32)statmSeq;
  *(OOC_INT32*)((_check_pointer(i1, 144282))+8) = i0;
  i0 = (OOC_INT32)catchList;
  *(OOC_INT32*)((_check_pointer(i1, 144317))+12) = i0;
  *(OOC_INT32*)((_check_pointer(i1, 144354))+16) = (OOC_INT32)0;
  return;
  ;
}

OOC_IR__TryStatm OOC_IR__BuilderDesc_NewTryStatm(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__StatementSeq statmSeq, OOC_IR__CatchList catchList) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  OOC_INT32 i;
  OOC_INT32 j;

  i0 = (OOC_INT32)catchList;
  i = 0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 144629)), 0);
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
  i4 = _check_pointer(i0, 144768);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(0, i5, OOC_UINT32, 144768))*4);
  i5 = _check_pointer(i0, 144700);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 144700))*4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 144771))+8);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 144703))+8);
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
  i5 = _check_pointer(i0, 144768);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 144768))*4);
  i6 = _check_pointer(i0, 144700);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i3, i7, OOC_UINT32, 144700))*4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 144771))+8);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 144703))+8);
  i5 = OOC_SymbolTable_TypeRules__IsExtensionOf((OOC_SymbolTable__Type)i6, (OOC_SymbolTable__Type)i5);
  i5 = !i5;
  
l16:
  if (i5) goto l11_loop;
l20:
  i4 = i3!=i4;
  if (!i4) goto l23;
  i4 = _check_pointer(i0, 144884);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 144884))*4);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 144887));
  OOC_IR__BuilderDesc_WarnSym((OOC_IR__Builder)i2, 65, (OOC_Scanner_SymList__Symbol)i4);
  i4 = _check_pointer(i0, 144911);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 144911))*4);
  *(OOC_UINT8*)((_check_pointer(i4, 144914))+16) = 1u;
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 145262)))), OOC_IR__VisitorDesc_VisitTryStatm)),OOC_IR__VisitorDesc_VisitTryStatm)((OOC_IR__Visitor)i0, (OOC_IR__TryStatm)i1);
  return;
  ;
}

static void OOC_IR__InitWhileStatm(OOC_IR__WhileStatm whileStatm, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression guard, OOC_IR__StatementSeq body) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)whileStatm;
  OOC_IR__InitStatement((OOC_IR__Statement)i1, (OOC_Scanner_SymList__Symbol)i0);
  i0 = (OOC_INT32)guard;
  *(OOC_INT32*)((_check_pointer(i1, 145603))+8) = i0;
  i0 = (OOC_INT32)body;
  *(OOC_INT32*)((_check_pointer(i1, 145635))+12) = i0;
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
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 145918)))), OOC_IR__BuilderDesc_AssertBoolean)),OOC_IR__BuilderDesc_AssertBoolean)((OOC_IR__Builder)i1, (OOC_IR__Expression)i2);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 146165)))), OOC_IR__VisitorDesc_VisitWhileStatm)),OOC_IR__VisitorDesc_VisitWhileStatm)((OOC_IR__Visitor)i0, (OOC_IR__WhileStatm)i1);
  return;
  ;
}

static void OOC_IR__InitWithStatm(OOC_IR__WithStatm withStatm, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression guard, OOC_IR__StatementSeq pathTrue, OOC_IR__StatementSeq pathFalse, OOC_CHAR8 checkMatch) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)withStatm;
  OOC_IR__InitStatement((OOC_IR__Statement)i1, (OOC_Scanner_SymList__Symbol)i0);
  i0 = (OOC_INT32)guard;
  *(OOC_INT32*)((_check_pointer(i1, 146564))+8) = i0;
  i0 = (OOC_INT32)pathTrue;
  *(OOC_INT32*)((_check_pointer(i1, 146595))+12) = i0;
  i0 = (OOC_INT32)pathFalse;
  *(OOC_INT32*)((_check_pointer(i1, 146632))+16) = i0;
  i0 = checkMatch;
  *(OOC_UINT8*)((_check_pointer(i1, 146671))+20) = i0;
  return;
  ;
}

OOC_IR__WithStatm OOC_IR__BuilderDesc_NewWithStatm(OOC_IR__Builder b, OOC_Scanner_SymList__Symbol sym, OOC_IR__Expression guard, OOC_IR__StatementSeq pathTrue, OOC_IR__StatementSeq pathFalse) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;

  i0 = (OOC_INT32)sym;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 147003))+16);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 147320)))), OOC_IR__VisitorDesc_VisitWithStatm)),OOC_IR__VisitorDesc_VisitWithStatm)((OOC_IR__Visitor)i0, (OOC_IR__WithStatm)i1);
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
      i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 148326)))), OOC_SymbolTable__TypeDesc_IsCheckedException)),OOC_SymbolTable__TypeDesc_IsCheckedException)((OOC_SymbolTable__Type)i0);
      if (!i1) goto l47;
      i1 = (OOC_INT32)currentTry;
      _try = (OOC_IR__TryStatm)i1;
      i2 = i1!=(OOC_INT32)0;
      if (!i2) goto l24;
l5_loop:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 148538))+12);
      i = 0;
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 148548)), 0);
      i3 = 0<i2;
      if (!i3) goto l19;
      i3=0;
l8_loop:
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 148591))+12);
      i4 = _check_pointer(i4, 148601);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 148601))*4);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 148604))+8);
      i4 = OOC_SymbolTable_TypeRules__IsExtensionOf((OOC_SymbolTable__Type)i4, (OOC_SymbolTable__Type)i0);
      if (!i4) goto l11;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 148685))+12);
      i4 = _check_pointer(i4, 148695);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 148695))*4);
      *(OOC_UINT8*)((_check_pointer(i4, 148698))+16) = 1u;
l11:
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 148813))+12);
      i4 = _check_pointer(i4, 148823);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 148823))*4);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 148826))+8);
      i4 = OOC_SymbolTable_TypeRules__IsExtensionOf((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i4);
      if (!i4) goto l14;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 148864))+12);
      i4 = _check_pointer(i4, 148874);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 148874))*4);
      *(OOC_UINT8*)((_check_pointer(i4, 148877))+16) = 1u;
      return;
l14:
      i3 = i3+1;
      i = i3;
      i4 = i3<i2;
      if (i4) goto l8_loop;
l19:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 148971))+16);
      _try = (OOC_IR__TryStatm)i1;
      i2 = i1!=(OOC_INT32)0;
      if (i2) goto l5_loop;
l24:
      i1 = (OOC_INT32)procDecl;
      i2 = i1!=(OOC_INT32)0;
      if (!i2) goto l38;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 149069))+64);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 149080))+60);
      raises = (OOC_SymbolTable__ExceptionNameArray)i1;
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i1, 149123)), 0);
      i = 0;
      i3 = 0<i2;
      if (!i3) goto l38;
      i3=0;
l29_loop:
      i4 = _check_pointer(i1, 149180);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 149180))*4);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 149183))+20);
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
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 149322))+4);
      i1 = i1==(OOC_INT32)0;
      
      goto l43;
l41:
      i1=1u;
l43:
      if (i1) goto l45;
      i1 = (OOC_INT32)b;
      i2 = (OOC_INT32)sym;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 149439)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 63, (OOC_Scanner_SymList__Symbol)i2);
      goto l46;
l45:
      i1 = (OOC_INT32)sym;
      i2 = (OOC_INT32)b;
      OOC_IR__BuilderDesc_WarnSym((OOC_IR__Builder)i2, 64, (OOC_Scanner_SymList__Symbol)i1);
l46:
      i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 149513)))), OOC_SymbolTable__ItemDesc_Module)),OOC_SymbolTable__ItemDesc_Module)((OOC_SymbolTable__Item)i0);
      module = (OOC_SymbolTable__Module)i1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 149629))+20);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 149634))+12);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 149629))+20);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 149634))+12);
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 149638)), 0);
      i1 = (OOC_INT32)Msg__GetStringPtr((void*)(_check_pointer(i1, 149638)), i2);
      i2 = (OOC_INT32)b;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 149533))+36);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 149533))+36);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 149543)))), Msg__MsgDesc_SetStringAttrib)),Msg__MsgDesc_SetStringAttrib)((Msg__Msg)i2, "module", 7, (Msg__StringPtr)i1);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 149749))+24);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 149760))+20);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 149765))+12);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 149749))+24);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 149760))+20);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 149765))+12);
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 149769)), 0);
      i0 = (OOC_INT32)Msg__GetStringPtr((void*)(_check_pointer(i0, 149769)), i1);
      i1 = (OOC_INT32)b;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 149652))+36);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 149652))+36);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 149662)))), Msg__MsgDesc_SetStringAttrib)),Msg__MsgDesc_SetStringAttrib)((Msg__Msg)i1, "name", 5, (Msg__StringPtr)i0);
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
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 150117)))), &_td_OOC_IR__ConstDesc);
          if (i1) goto l156;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 150166)))), &_td_OOC_IR__AbsDesc);
          if (i1) goto l154;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 150224)))), &_td_OOC_IR__AdrDesc);
          if (i1) goto l152;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 150281)))), &_td_OOC_IR__AshDesc);
          if (i1) goto l150;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 150368)))), &_td_OOC_IR__BinaryArithDesc);
          if (i1) goto l148;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 150464)))), &_td_OOC_IR__BooleanOpDesc);
          if (i1) goto l146;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 150558)))), &_td_OOC_IR__CapDesc);
          if (i1) goto l144;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 150616)))), &_td_OOC_IR__CompareDesc);
          if (i1) goto l142;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 150708)))), &_td_OOC_IR__ConcatDesc);
          if (i1) goto l132;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 150837)))), &_td_OOC_IR__ConstructorDesc);
          if (i1) goto l130;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 150933)))), &_td_OOC_IR__CurrentExceptionDesc);
          if (i1) goto l128;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 151003)))), &_td_OOC_IR__ChangeElementDesc);
          if (i1) goto l126;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 151102)))), &_td_OOC_IR__DerefDesc);
          if (i1) goto l124;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 151162)))), &_td_OOC_IR__EntierDesc);
          if (i1) goto l122;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 151223)))), &_td_OOC_IR__IndexDesc);
          if (i1) goto l120;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 151314)))), &_td_OOC_IR__LenDesc);
          if (i1) goto l118;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 151370)))), &_td_OOC_IR__NegateDesc);
          if (i1) goto l116;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 151431)))), &_td_OOC_IR__NewBlockDesc);
          if (i1) goto l114;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 151491)))), &_td_OOC_IR__NewObjectDesc);
          if (i1) goto l101;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 151680)))), &_td_OOC_IR__NotDesc);
          if (i1) goto l99;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 151738)))), &_td_OOC_IR__OddDesc);
          if (i1) goto l97;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 151796)))), &_td_OOC_IR__ReferenceDesc);
          if (i1) goto l156;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 151849)))), &_td_OOC_IR__SelectFieldDesc);
          if (i1) goto l94;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 151914)))), &_td_OOC_IR__SelectProcDesc);
          if (i1) goto l92;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 151980)))), &_td_OOC_IR__SetMemberDesc);
          if (i1) goto l90;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 152075)))), &_td_OOC_IR__SetOpDesc);
          if (i1) goto l88;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 152165)))), &_td_OOC_IR__SetRangeDesc);
          if (i1) goto l86;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 152255)))), &_td_OOC_IR__ShiftDesc);
          if (i1) goto l84;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 152343)))), &_td_OOC_IR__TypeCastDesc);
          if (i1) goto l82;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 152403)))), &_td_OOC_IR__TypeConvDesc);
          if (i1) goto l80;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 152463)))), &_td_OOC_IR__TypeTagDesc);
          if (i1) goto l78;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 152524)))), &_td_OOC_IR__TypeTestDesc);
          if (i1) goto l76;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 152584)))), &_td_OOC_IR__TypeGuardDesc);
          if (i1) goto l74;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 152656)))), &_td_OOC_IR__CallDesc);
          if (i1) goto l72;
          _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 152650)))), 152650);
          goto l156;
l72:
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckStatm((OOC_IR__Statement)i0);
          goto l156;
l74:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 152623))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l76:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 152562))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l78:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 152500))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l80:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 152441))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l82:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 152381))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l84:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 152290))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 152323))+12);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l86:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 152203))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 152235))+12);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l88:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 152110))+12);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 152142))+16);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l90:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 152019))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 152054))+12);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l92:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 151954))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l94:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 151890))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l97:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 151771))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l99:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 151713))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l101:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 151524))+8);
          i1 = i1!=(OOC_INT32)0;
          if (!i1) goto l156;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 151578))+8);
          i = 0;
          i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 151585)), 0);
          i2 = 0<i1;
          if (!i2) goto l156;
          i2=0;
l106_loop:
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 151621))+8);
          i3 = _check_pointer(i3, 151628);
          i4 = OOC_ARRAY_LENGTH(i3, 0);
          i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 151628))*4);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i3);
          i2 = i2+1;
          i = i2;
          i3 = i2<i1;
          if (i3) goto l106_loop;
          goto l156;
l114:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 151469))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l116:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 151406))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l118:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 151347))+12);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l120:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 151258))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 151291))+12);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l122:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 151198))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l124:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 151137))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l126:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 151046))+12);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 151077))+16);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l128:
          i1 = (OOC_INT32)currentTry;
          *(OOC_INT32*)((_check_pointer(i0, 150969))+8) = i1;
          goto l156;
l130:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 150878))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 150911))+12);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l132:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 150752))+8);
          i = 0;
          i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 150760)), 0);
          i2 = 0<i1;
          if (!i2) goto l156;
          i2=0;
l135_loop:
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 150794))+8);
          i3 = _check_pointer(i3, 150802);
          i4 = OOC_ARRAY_LENGTH(i3, 0);
          i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 150802))*4);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i3);
          i2 = i2+1;
          i = i2;
          i3 = i2<i1;
          if (i3) goto l135_loop;
          goto l156;
l142:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 150653))+12);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 150685))+16);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l144:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 150591))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l146:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 150503))+12);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 150535))+16);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l148:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 150409))+12);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 150441))+16);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l150:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 150314))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 150347))+12);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l152:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 150257))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l156;
l154:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 150199))+8);
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
              i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 153022)))), &_td_OOC_IR__SelectProcDesc);
              if (i1) goto l3;
              return 0u;
              goto l16;
l3:
              i1 = *(OOC_UINT8*)((_check_pointer(i0, 153060))+29);
              i1 = !i1;
              if (i1) goto l6;
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 153099))+8);
              i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 153109)))), &_td_OOC_IR__VarDesc));
              
              goto l8;
l6:
              i1=1u;
l8:
              if (i1) goto l10;
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 153142))+8);
              i2 = (OOC_INT32)procDecl;
              i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 153172))+64);
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 153152)))), &_td_OOC_IR__VarDesc, 153152)), 153156))+8);
              i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 153183))+40);
              i1 = i1!=i2;
              
              goto l12;
l10:
              i1=1u;
l12:
              if (i1) goto l14;
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 153335))+20);
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 153342))+20);
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 153347))+12);
              return ((
              _cmp8((const void*)(_check_pointer(i0, 153351)),(const void*)"INIT"))==0);
              goto l16;
l14:
              return 0u;
l16:
              _failed_function(152945); return 0;
              ;
            }


          i0 = (OOC_INT32)statm;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 153510)))), &_td_OOC_IR__AssertDesc);
          if (i1) goto l147;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 153575)))), &_td_OOC_IR__AssignmentDesc);
          if (i1) goto l145;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 153717)))), &_td_OOC_IR__CallDesc);
          if (i1) goto l120;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 154228)))), &_td_OOC_IR__CopyDesc);
          if (i1) goto l118;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 154321)))), &_td_OOC_IR__CopyParameterDesc);
          if (i1) goto l148;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 154379)))), &_td_OOC_IR__CopyStringDesc);
          if (i1) goto l115;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 154478)))), &_td_OOC_IR__ExitDesc);
          if (i1) goto l109;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 154739)))), &_td_OOC_IR__ForStatmDesc);
          if (i1) goto l107;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 154938)))), &_td_OOC_IR__IterateArrayStatmDesc);
          if (i1) goto l105;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 155081)))), &_td_OOC_IR__IterateObjectStatmDesc);
          if (i1) goto l103;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 155275)))), &_td_OOC_IR__IfStatmDesc);
          if (i1) goto l101;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 155424)))), &_td_OOC_IR__CaseDesc);
          if (i1) goto l99;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 155492)))), &_td_OOC_IR__CaseStatmDesc);
          if (i1) goto l89;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 155724)))), &_td_OOC_IR__LoopStatmDesc);
          if (i1) goto l87;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 156049)))), &_td_OOC_IR__MoveBlockDesc);
          if (i1) goto l85;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 156147)))), &_td_OOC_IR__RaiseDesc);
          if (i1) goto l83;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 156270)))), &_td_OOC_IR__RepeatStatmDesc);
          if (i1) goto l81;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 156383)))), &_td_OOC_IR__ReturnDesc);
          if (i1) goto l64;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 157135)))), &_td_OOC_IR__TryStatmDesc);
          if (i1) goto l47;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 157749)))), &_td_OOC_IR__WhileStatmDesc);
          if (i1) goto l45;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 157853)))), &_td_OOC_IR__WithStatmDesc);
          if (i1) goto l43;
          _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 157846)))), 157846);
          goto l148;
l43:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 157893))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 157932))+12);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq((OOC_IR__StatementSeq)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 157975))+16);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq((OOC_IR__StatementSeq)i0);
          goto l148;
l45:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 157790))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 157829))+12);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq((OOC_IR__StatementSeq)i0);
          goto l148;
l47:
          i1 = (OOC_INT32)procDecl;
          i2 = enclosingTry;
          *(OOC_UINT8*)((_check_pointer(i1, 157167))+76) = 1u;
          enclosingTry = (i2+1);
          i1 = (OOC_INT32)currentTry;
          *(OOC_INT32*)((_check_pointer(i0, 157233))+16) = i1;
          currentTry = (OOC_IR__TryStatm)i0;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 157322))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq((OOC_IR__StatementSeq)i1);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 157363))+16);
          i2 = enclosingTry;
          currentTry = (OOC_IR__TryStatm)i1;
          enclosingTry = (i2-1);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 157440))+12);
          i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 157450)), 0);
          i = 0;
          i2 = 0<i1;
          if (!i2) goto l148;
          i2=0;
l50_loop:
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 157478))+12);
          i3 = _check_pointer(i3, 157488);
          i4 = OOC_ARRAY_LENGTH(i3, 0);
          i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 157488))*4);
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 157478))+12);
          i4 = _check_pointer(i4, 157488);
          i5 = OOC_ARRAY_LENGTH(i4, 0);
          i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i2, i5, OOC_UINT32, 157488))*4);
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 157491))+8);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 157491))+8);
          i3 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 157505)))), OOC_SymbolTable__TypeDesc_IsCheckedException)),OOC_SymbolTable__TypeDesc_IsCheckedException)((OOC_SymbolTable__Type)i3);
          if (i3) goto l53;
          i3=0u;
          goto l55;
l53:
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 157550))+12);
          i3 = _check_pointer(i3, 157560);
          i4 = OOC_ARRAY_LENGTH(i3, 0);
          i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 157560))*4);
          i3 = *(OOC_UINT8*)((_check_pointer(i3, 157563))+16);
          i3 = !i3;
          
l55:
          if (!i3) goto l57;
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 157626))+12);
          i3 = _check_pointer(i3, 157636);
          i4 = OOC_ARRAY_LENGTH(i3, 0);
          i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 157636))*4);
          i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 157639));
          i4 = (OOC_INT32)b;
          OOC_IR__BuilderDesc_WarnSym((OOC_IR__Builder)i4, 66, (OOC_Scanner_SymList__Symbol)i3);
l57:
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 157694))+12);
          i3 = _check_pointer(i3, 157704);
          i4 = OOC_ARRAY_LENGTH(i3, 0);
          i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 157704))*4);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 157707))+12);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq((OOC_IR__StatementSeq)i3);
          i2 = i2+1;
          i = i2;
          i3 = i2<i1;
          if (i3) goto l50_loop;
          goto l148;
l64:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 156420))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i1 = (OOC_INT32)procDecl;
          i2 = i1==0;
          if (i2) goto l67;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 156485))+64);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 156497))+44);
          i2 = i2==0;
          
          goto l69;
l67:
          i2=1u;
l69:
          if (i2) goto l75;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 156774))+8);
          i2 = i2==0;
          if (i2) goto l73;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 157008))+64);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 157019))+44);
          i1 = (OOC_INT32)OOC_SymbolTable__Expand((OOC_SymbolTable__Type)i1);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 156919))+8);
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 156927));
          i3 = (OOC_INT32)b;
          OOC_IR__MakeAssignmentCompatible((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i2, (void*)((_check_pointer(i0, 156939))+8), (OOC_SymbolTable__Type)i1);
          goto l79;
l73:
          i1 = (OOC_INT32)b;
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 156846));
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 156810)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 33, (OOC_Scanner_SymList__Symbol)i2);
          goto l79;
l75:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 156599))+8);
          i1 = i1!=0;
          if (!i1) goto l79;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 156668))+8);
          i2 = (OOC_INT32)b;
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 156676));
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 156635)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i2, 32, (OOC_Scanner_SymList__Symbol)i1);
l79:
          i1 = enclosingTry;
          *(OOC_INT32*)((_check_pointer(i0, 157081))+12) = i1;
          goto l148;
l81:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 156317))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq((OOC_IR__StatementSeq)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 156351))+12);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l148;
l83:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 156183))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 156226))+8);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 156236))+4);
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 156248));
          OOC_IR__BuilderDesc_CheckExit_CheckException((OOC_SymbolTable__Type)i1, (OOC_Scanner_SymList__Symbol)i0);
          goto l148;
l85:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 156089))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 156124))+12);
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
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 155937))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq((OOC_IR__StatementSeq)i0);
          enclosingTryLastLoop = i2;
          currentLoop = (OOC_IR__LoopStatm)i1;
          goto l148;
l89:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 155532))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 155576))+12);
          i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 155586)), 0);
          i = 0;
          i2 = 0<i1;
          if (!i2) goto l97;
          i2=0;
l92_loop:
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 155626))+12);
          i3 = _check_pointer(i3, 155636);
          i4 = OOC_ARRAY_LENGTH(i3, 0);
          i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 155636))*4);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 155639))+12);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq((OOC_IR__StatementSeq)i3);
          i2 = i2+1;
          i = i2;
          i3 = i2<i1;
          if (i3) goto l92_loop;
l97:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 155697))+16);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq((OOC_IR__StatementSeq)i0);
          goto l148;
l99:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 155464))+12);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq((OOC_IR__StatementSeq)i0);
          goto l148;
l101:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 155313))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 155352))+12);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq((OOC_IR__StatementSeq)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 155395))+16);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq((OOC_IR__StatementSeq)i0);
          goto l148;
l103:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 155130))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 155162))+12);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 155206))+16);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 155251))+20);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq((OOC_IR__StatementSeq)i0);
          goto l148;
l105:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 154986))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 155018))+12);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 155057))+16);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq((OOC_IR__StatementSeq)i0);
          goto l148;
l107:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 154778))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 154810))+12);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 154844))+16);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 154876))+20);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 154914))+24);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq((OOC_IR__StatementSeq)i0);
          goto l148;
l109:
          i1 = (OOC_INT32)currentLoop;
          i2 = i1==0;
          if (i2) goto l112;
          *(OOC_INT32*)((_check_pointer(i0, 154611))+8) = i1;
          goto l113;
l112:
          i1 = (OOC_INT32)b;
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 154571));
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 154539)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 25, (OOC_Scanner_SymList__Symbol)i2);
l113:
          i1 = enclosingTry;
          i2 = enclosingTryLastLoop;
          *(OOC_INT32*)((_check_pointer(i0, 154664))+12) = (i1-i2);
          goto l148;
l115:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 154420))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 154455))+12);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l148;
l118:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 154263))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 154298))+12);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l148;
l120:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 153752))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i1 = initWithoutSuper;
          if (i1) goto l123;
          i1=0u;
          goto l125;
l123:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 153812))+8);
          i1 = OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckStatm_IsInitSuper((OOC_IR__Expression)i1);
          
l125:
          if (!i1) goto l127;
          initWithoutSuper = 0u;
l127:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 153924))+12);
          i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 153934)), 0);
          i = 0;
          i2 = 0<i1;
          if (!i2) goto l135;
          i2=0;
l130_loop:
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 153969))+12);
          i3 = _check_pointer(i3, 153979);
          i4 = OOC_ARRAY_LENGTH(i3, 0);
          i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 153979))*4);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i3);
          i2 = i2+1;
          i = i2;
          i3 = i2<i1;
          if (i3) goto l130_loop;
l135:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 154024))+8);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 154024))+8);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 154031))+4);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 154031))+4);
          i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 154036)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i1);
          type = (OOC_SymbolTable__Type)i1;
          i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 154076)))), &_td_OOC_SymbolTable__FormalParsDesc, 154076);
          fpars = (OOC_SymbolTable__FormalPars)i1;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 154122))+60);
          i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 154129)), 0);
          i = 0;
          i3 = 0<i2;
          if (!i3) goto l148;
          i3=0;
l138_loop:
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 154169))+60);
          i4 = _check_pointer(i4, 154176);
          i5 = OOC_ARRAY_LENGTH(i4, 0);
          i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 154176))*4);
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 154179))+20);
          i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 154191));
          OOC_IR__BuilderDesc_CheckExit_CheckException((OOC_SymbolTable__Type)i4, (OOC_Scanner_SymList__Symbol)i5);
          i3 = i3+1;
          i = i3;
          i4 = i3<i2;
          if (i4) goto l138_loop;
          goto l148;
l145:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 153657))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 153694))+12);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l148;
l147:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 153547))+8);
          OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
l148:
          return;
          ;
        }


      i0 = (OOC_INT32)statmSeq;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l11;
      i = 0;
      i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 158105)), 0);
      i1 = 0<i0;
      if (!i1) goto l11;
      i1=0;
l5_loop:
      i2 = (OOC_INT32)statmSeq;
      i2 = _check_pointer(i2, 158143);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i1 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i1, i3, OOC_UINT32, 158143))*4);
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
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 158412)))), OOC_SymbolTable__ItemDesc_InStandardModule)),OOC_SymbolTable__ItemDesc_InStandardModule)((OOC_SymbolTable__Item)i0);
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
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 158472))+40);
  i2 = i2!=(OOC_INT32)0;
  
l9:
  if (i2) goto l11;
  i2=0u;
  goto l13;
l11:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 158509))+40);
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 158519)))), &_td_OOC_SymbolTable__RecordDesc);
  
l13:
  if (i2) goto l15;
  i2=0u;
  goto l17;
l15:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 158553))+20);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 158558))+12);
  i2 = (
  _cmp8((const void*)(_check_pointer(i2, 158562)),(const void*)"INIT"))==0;
  
l17:
  if (i2) goto l19;
  i0=0u;
  goto l20;
l19:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 158628))+40);
  i0 = *(OOC_INT32*)((_check_pointer(i0, 158604))+56);
  i1 = *(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 158642)))), &_td_OOC_SymbolTable__RecordDesc, 158642)), 158649))+48);
  i0 = i0<i1;
  
l20:
  initWithoutSuper = i0;
  i0 = (OOC_INT32)statmSeq;
  OOC_IR__BuilderDesc_CheckExit_CheckStatmSeq((OOC_IR__StatementSeq)i0);
  i0 = initWithoutSuper;
  if (!i0) goto l23;
  i0 = (OOC_INT32)procDecl;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 158776))+20);
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
  *(OOC_INT32*)((_check_pointer(i1, 159073))+4) = i0;
  i0 = (OOC_INT32)statmSeq;
  *(OOC_INT32*)((_check_pointer(i1, 159094))+8) = i0;
  i0 = (OOC_INT32)endOfProc;
  *(OOC_INT32*)((_check_pointer(i1, 159123))+16) = i0;
  i0 = checkFunctionResult;
  *(OOC_UINT8*)((_check_pointer(i1, 159154))+12) = i0;
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
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 160216)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i0, (Object__Object)i1);
          return;
          ;
        }

        
        OOC_IR__StatementSeq OOC_IR__BuilderDesc_NewProcedure_AddSetupCode_Prepend(ADT_ArrayList__ArrayList prefix, OOC_IR__StatementSeq statmSeq) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9;
          OOC_IR__StatementSeq _new;
          OOC_INT32 i;

          i0 = (OOC_INT32)prefix;
          i1 = (OOC_INT32)statmSeq;
          i2 = *(OOC_INT32*)((_check_pointer(i0, 160442))+4);
          i3 = OOC_ARRAY_LENGTH((_check_pointer(i1, 160462)), 0);
          i2 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__StatementSeq.baseTypes[0], (i2+i3));
          _new = (OOC_IR__StatementSeq)i2;
          i = 0;
          i3 = *(OOC_INT32*)((_check_pointer(i0, 160495))+4);
          i4 = 0<i3;
          if (!i4) goto l8;
          i4=0;
l3_loop:
          i5 = _check_pointer(i2, 160520);
          i6 = OOC_ARRAY_LENGTH(i5, 0);
          i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 160533));
          i7 = _check_pointer(i7, 160540);
          i8 = OOC_ARRAY_LENGTH(i7, 0);
          i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i4, i8, OOC_UINT32, 160540))*4);
          *(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 160520))*4) = (_type_guard(i7, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 160544)))), &_td_OOC_IR__StatementDesc, 160544));
          i4 = i4+1;
          i = i4;
          i5 = i4<i3;
          if (i5) goto l3_loop;
l8:
          i = 0;
          i3 = OOC_ARRAY_LENGTH((_check_pointer(i1, 160603)), 0);
          i4 = 0<i3;
          if (!i4) goto l16;
          i4=0;
l11_loop:
          i5 = _check_pointer(i2, 160624);
          i6 = *(OOC_INT32*)((_check_pointer(i0, 160633))+4);
          i7 = OOC_ARRAY_LENGTH(i5, 0);
          i8 = _check_pointer(i1, 160652);
          i9 = OOC_ARRAY_LENGTH(i8, 0);
          i8 = (OOC_INT32)*(OOC_INT32*)(i8+(_check_index(i4, i9, OOC_UINT32, 160652))*4);
          *(OOC_INT32*)(i5+(_check_index((i4+i6), i7, OOC_UINT32, 160624))*4) = i8;
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
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 160769))+64);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 160781))+52);
      formalPars = (OOC_SymbolTable__VarDeclArray)i0;
      fparIndex = 0;
      i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 160882)), 0);
      i0 = 0!=i0;
      if (!i0) goto l11;
      i0=0;
l3_loop:
      i1 = (OOC_INT32)formalPars;
      i1 = _check_pointer(i1, 160915);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i0 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(i0, i2, OOC_UINT32, 160915))*4);
      fpar = (OOC_SymbolTable__VarDecl)i0;
      i1 = *(OOC_UINT8*)((_check_pointer(i0, 160943))+61);
      if (!i1) goto l6;
      i1 = (OOC_INT32)b;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 161010)))), OOC_IR__BuilderDesc_NewVar)),OOC_IR__BuilderDesc_NewVar)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)(OOC_INT32)0, (OOC_SymbolTable__VarDecl)i0);
      i1 = (OOC_INT32)b;
      i2 = (OOC_INT32)sym;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 160984)))), OOC_IR__BuilderDesc_NewCopyParameter)),OOC_IR__BuilderDesc_NewCopyParameter)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Var)i0);
      OOC_IR__BuilderDesc_NewProcedure_AddSetupCode_AddStatm((OOC_IR__Statement)i0);
l6:
      i0 = fparIndex;
      i0 = i0+1;
      fparIndex = i0;
      i1 = (OOC_INT32)formalPars;
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 160882)), 0);
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
      _failed_function(159560); return 0;
      ;
    }


  i0 = (OOC_INT32)decl;
  i1 = (OOC_INT32)b;
  i2 = (OOC_INT32)sym;
  i3 = *(OOC_UINT8*)((_check_pointer(i0, 161253))+50);
  if (i3) goto l3;
  i3=0u;
  goto l5;
l3:
  i3 = hasBegin;
  
l5:
  if (!i3) goto l7;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 161288)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 57, (OOC_Scanner_SymList__Symbol)i2);
l7:
  i3 = (OOC_INT32)statmSeq;
  OOC_IR__BuilderDesc_CheckExit((OOC_IR__Builder)i1, (OOC_SymbolTable__ProcDecl)i0, (OOC_IR__StatementSeq)i3);
  p = (OOC_IR__Procedure)((OOC_INT32)RT0__NewObject(_td_OOC_IR__Procedure.baseTypes[0]));
  i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewProcedure_AddSetupCode((OOC_Scanner_SymList__Symbol)i2, (OOC_SymbolTable__ProcDecl)i0, (OOC_IR__StatementSeq)i3);
  statmSeq = (OOC_IR__StatementSeq)i0;
  i1 = (OOC_INT32)decl;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 161598))+20);
  i2 = *(OOC_INT32*)(_check_pointer(i2, 161604));
  i3 = (OOC_INT32)OOC_Config_StdPragmas__functionResultCheck;
  i4 = (OOC_INT32)b;
  i2 = OOC_IR__GetPragmaValue((OOC_IR__Builder)i4, (Config_Section_Options__Option)i3, i2);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 161804)))), OOC_IR__VisitorDesc_VisitProcedure)),OOC_IR__VisitorDesc_VisitProcedure)((OOC_IR__Visitor)i0, (OOC_IR__Procedure)i1);
  return;
  ;
}

void OOC_IR__InitModule(OOC_IR__Module m, OOC_Scanner_SymList__Symbol sym, OOC_Scanner_InputBuffer__CharArray name, OOC_IR__ProcedureList procList, OOC_IR__Procedure moduleBody) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)m;
  OOC_IR__InitNode((OOC_IR__Node)i1, (OOC_Scanner_SymList__Symbol)i0);
  i0 = (OOC_INT32)name;
  *(OOC_INT32*)((_check_pointer(i1, 162104))+4) = i0;
  i0 = (OOC_INT32)procList;
  *(OOC_INT32*)((_check_pointer(i1, 162125))+8) = i0;
  i0 = (OOC_INT32)moduleBody;
  *(OOC_INT32*)((_check_pointer(i1, 162154))+12) = i0;
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
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 162595)))), &_td_OOC_SymbolTable__DeclarationDesc);
      if (!i1) goto l38;
      i1 = *(OOC_INT32*)((_check_pointer(i0, 162842))+44);
      i1 = i1==0;
      if (i1) goto l5;
      i1=0u;
      goto l7;
l5:
      i1 = *(OOC_INT8*)((_check_pointer(i0, 162877))+28);
      i1 = i1==0;
      
l7:
      if (i1) goto l9;
      i1=0u;
      goto l15;
l9:
      i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 162933)))), &_td_OOC_SymbolTable__VarDeclDesc));
      if (i1) goto l12;
      i1 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 162962)))), &_td_OOC_SymbolTable__VarDeclDesc, 162962)), 162970))+56);
      i1 = !i1;
      
      goto l15;
l12:
      i1=1u;
l15:
      if (i1) goto l17;
      i1=0u;
      goto l23;
l17:
      i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 163005)))), &_td_OOC_SymbolTable__TypeDeclDesc));
      if (i1) goto l20;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 163031))+4);
      i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 163039)))), &_td_OOC_SymbolTable__FormalParsDesc));
      
      goto l23;
l20:
      i1=1u;
l23:
      if (i1) goto l25;
      i1=0u;
      goto l35;
l25:
      i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 163080)))), &_td_OOC_SymbolTable__ProcDeclDesc));
      if (i1) goto l32;
      i1 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 163123)))), &_td_OOC_SymbolTable__ProcDeclDesc, 163123)), 163132))+49);
      if (i1) goto l30;
      i1 = OOC_SymbolTable__ProcDeclDesc_IsTypeBound((OOC_SymbolTable__ProcDecl)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 163173)))), &_td_OOC_SymbolTable__ProcDeclDesc, 163173)));
      
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
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 163248))+20);
      i2 = (OOC_INT32)b;
      OOC_IR__BuilderDesc_WarnName((OOC_IR__Builder)i2, 53, (OOC_SymbolTable__Name)i1);
l38:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 163332))+8);
      nested = (OOC_SymbolTable__Item)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l46;
l41_loop:
      OOC_IR__BuilderDesc_NewModule_UnusedDeclarations((OOC_SymbolTable__Item)i0);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 163436));
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
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 163592))+80);
  i4 = (OOC_INT32)sym;
  i5 = (OOC_INT32)statmSeq;
  i6 = (OOC_INT32)endOfModule;
  i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 163567)))), OOC_IR__BuilderDesc_NewProcedure)),OOC_IR__BuilderDesc_NewProcedure)((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i4, (OOC_SymbolTable__ProcDecl)i3, (OOC_IR__StatementSeq)i5, (OOC_Scanner_SymList__Symbol)i6, 1u);
  i5 = (OOC_INT32)name;
  i6 = (OOC_INT32)procList;
  OOC_IR__InitModule((OOC_IR__Module)i0, (OOC_Scanner_SymList__Symbol)i4, (OOC_Scanner_InputBuffer__CharArray)i5, (OOC_IR__ProcedureList)i6, (OOC_IR__Procedure)i3);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 163676))+8);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 163915)))), OOC_IR__VisitorDesc_VisitModule)),OOC_IR__VisitorDesc_VisitModule)((OOC_IR__Visitor)i0, (OOC_IR__Module)i1);
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
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 164333)), 0);
      i2 = 0<i1;
      if (!i2) goto l10;
      i2=0;
l5_loop:
      i3 = _check_pointer(i0, 164354);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      OOC_IR__ModuleDesc_Destroy_E((void*)(i3+(_check_index(i2, i4, OOC_UINT32, 164354))*4));
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
      *(OOC_INT32*)((_check_pointer(i0, 164530))+4) = (OOC_INT32)0;
      i0 = (OOC_INT32)*n;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 164558)))), &_td_OOC_IR__ConstDesc);
      if (i1) goto l140;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 164606)))), &_td_OOC_IR__OperatorDesc);
      if (i1) goto l15;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 166999)))), &_td_OOC_IR__ReferenceDesc);
      if (i1) goto l13;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 167050)))), &_td_OOC_IR__StatementDesc);
      if (i1) goto l11;
      Log__Type("--- expression type", 20, (void*)i0);
      _assert(0u, 127, 167185);
      goto l141;
l11:
      OOC_IR__ModuleDesc_Destroy_S((void*)(OOC_INT32)n);
      goto l141;
l13:
      *(OOC_INT32*)((_check_pointer(i0, 167025))+8) = (OOC_INT32)0;
      goto l141;
l15:
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 164636)))), &_td_OOC_IR__AbsDesc);
      if (i1) goto l137;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 164684)))), &_td_OOC_IR__AdrDesc);
      if (i1) goto l135;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 164731)))), &_td_OOC_IR__AshDesc);
      if (i1) goto l133;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 164799)))), &_td_OOC_IR__BinaryArithDesc);
      if (i1) goto l131;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 164876)))), &_td_OOC_IR__BooleanOpDesc);
      if (i1) goto l129;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 164951)))), &_td_OOC_IR__CapDesc);
      if (i1) goto l127;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 164999)))), &_td_OOC_IR__CompareDesc);
      if (i1) goto l125;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 165072)))), &_td_OOC_IR__ConcatDesc);
      if (i1) goto l123;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 165127)))), &_td_OOC_IR__ConstructorDesc);
      if (i1) goto l121;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 165311)))), &_td_OOC_IR__CurrentExceptionDesc);
      if (i1) goto l141;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 165372)))), &_td_OOC_IR__ChangeElementDesc);
      if (i1) goto l118;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 165452)))), &_td_OOC_IR__DerefDesc);
      if (i1) goto l116;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 165502)))), &_td_OOC_IR__EntierDesc);
      if (i1) goto l114;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 165553)))), &_td_OOC_IR__IndexDesc);
      if (i1) goto l112;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 165625)))), &_td_OOC_IR__LenDesc);
      if (i1) goto l110;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 165727)))), &_td_OOC_IR__NegateDesc);
      if (i1) goto l108;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 165778)))), &_td_OOC_IR__NewBlockDesc);
      if (i1) goto l106;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 165828)))), &_td_OOC_IR__NewObjectDesc);
      if (i1) goto l104;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 165885)))), &_td_OOC_IR__NotDesc);
      if (i1) goto l102;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 165933)))), &_td_OOC_IR__OddDesc);
      if (i1) goto l100;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 165981)))), &_td_OOC_IR__SelectFieldDesc);
      if (i1) goto l98;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 166095)))), &_td_OOC_IR__SelectProcDesc);
      if (i1) goto l96;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 166212)))), &_td_OOC_IR__SetMemberDesc);
      if (i1) goto l94;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 166288)))), &_td_OOC_IR__SetOpDesc);
      if (i1) goto l92;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 166359)))), &_td_OOC_IR__SetRangeDesc);
      if (i1) goto l90;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 166430)))), &_td_OOC_IR__ShiftDesc);
      if (i1) goto l88;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 166499)))), &_td_OOC_IR__TypeCastDesc);
      if (i1) goto l86;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 166549)))), &_td_OOC_IR__TypeConvDesc);
      if (i1) goto l84;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 166599)))), &_td_OOC_IR__TypeTagDesc);
      if (i1) goto l82;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 166650)))), &_td_OOC_IR__TypeTestDesc);
      if (i1) goto l80;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 166794)))), &_td_OOC_IR__TypeGuardDesc);
      if (i1) goto l78;
      Log__Type("--- operator type", 18, (void*)i0);
      _assert(0u, 127, 166958);
      goto l141;
l78:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 166830))+8);
      expr = (OOC_IR__Expression)i0;
      OOC_IR__ModuleDesc_Destroy_E((void*)(OOC_INT32)&expr);
      i0 = (OOC_INT32)*n;
      *(OOC_INT32*)((_check_pointer(i0, 166871))+8) = (OOC_INT32)0;
      goto l141;
l80:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 166679))+8));
      i0 = (OOC_INT32)*n;
      *(OOC_INT32*)((_check_pointer(i0, 166700))+12) = (OOC_INT32)0;
      i0 = (OOC_INT32)*n;
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 166738))+20));
      i0 = (OOC_INT32)*n;
      *(OOC_INT32*)((_check_pointer(i0, 166763))+24) = (OOC_INT32)0;
      goto l141;
l82:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 166627))+8));
      goto l141;
l84:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 166578))+8));
      goto l141;
l86:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 166528))+8));
      goto l141;
l88:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 166456))+8));
      i0 = (OOC_INT32)*n;
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 166480))+12));
      goto l141;
l90:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 166388))+8));
      i0 = (OOC_INT32)*n;
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 166411))+12));
      goto l141;
l92:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 166314))+12));
      i0 = (OOC_INT32)*n;
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 166337))+16));
      goto l141;
l94:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 166242))+8));
      i0 = (OOC_INT32)*n;
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 166268))+12));
      goto l141;
l96:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 166126))+8));
      i0 = (OOC_INT32)*n;
      *(OOC_INT32*)((_check_pointer(i0, 166151))+20) = (OOC_INT32)0;
      i0 = (OOC_INT32)*n;
      *(OOC_INT32*)((_check_pointer(i0, 166180))+24) = (OOC_INT32)0;
      goto l141;
l98:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 166013))+8));
      i0 = (OOC_INT32)*n;
      *(OOC_INT32*)((_check_pointer(i0, 166036))+12) = (OOC_INT32)0;
      i0 = (OOC_INT32)*n;
      *(OOC_INT32*)((_check_pointer(i0, 166064))+16) = (OOC_INT32)0;
      goto l141;
l100:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 165957))+8));
      goto l141;
l102:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 165909))+8));
      goto l141;
l104:
      OOC_IR__ModuleDesc_Destroy_EList((void*)((_check_pointer(i0, 165862))+8));
      goto l141;
l106:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 165807))+8));
      goto l141;
l108:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 165754))+8));
      goto l141;
l110:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 165649))+12));
      i0 = (OOC_INT32)*n;
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 165673))+20));
      i0 = (OOC_INT32)*n;
      *(OOC_INT32*)((_check_pointer(i0, 165703))+16) = 0;
      goto l141;
l112:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 165579))+8));
      i0 = (OOC_INT32)*n;
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 165603))+12));
      goto l141;
l114:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 165529))+8));
      goto l141;
l116:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 165478))+8));
      goto l141;
l118:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 165406))+12));
      i0 = (OOC_INT32)*n;
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 165428))+16));
      goto l141;
l121:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 165165))+8);
      expr = (OOC_IR__Expression)i0;
      OOC_IR__ModuleDesc_Destroy_E((void*)(OOC_INT32)&expr);
      i0 = (OOC_INT32)*n;
      *(OOC_INT32*)((_check_pointer(i0, 165207))+8) = (OOC_INT32)0;
      i0 = (OOC_INT32)*n;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 165243))+12);
      expr = (OOC_IR__Expression)i0;
      OOC_IR__ModuleDesc_Destroy_E((void*)(OOC_INT32)&expr);
      i0 = (OOC_INT32)*n;
      *(OOC_INT32*)((_check_pointer(i0, 165284))+12) = (OOC_INT32)0;
      goto l141;
l123:
      OOC_IR__ModuleDesc_Destroy_EList((void*)((_check_pointer(i0, 165103))+8));
      goto l141;
l125:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 165027))+12));
      i0 = (OOC_INT32)*n;
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 165050))+16));
      goto l141;
l127:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 164975))+8));
      goto l141;
l129:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 164906))+12));
      i0 = (OOC_INT32)*n;
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 164929))+16));
      goto l141;
l131:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 164831))+12));
      i0 = (OOC_INT32)*n;
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 164854))+16));
      goto l141;
l133:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 164755))+8));
      i0 = (OOC_INT32)*n;
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 164779))+12));
      goto l141;
l135:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 164708))+8));
      goto l141;
l137:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 164660))+8));
      goto l141;
l140:
      *(OOC_INT32*)((_check_pointer(i0, 164580))+8) = (OOC_INT32)0;
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
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 167381)), 0);
      i2 = 0<i1;
      if (!i2) goto l11;
      i2=0;
l5_loop:
      i3 = _check_pointer(i0, 167402);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      OOC_IR__ModuleDesc_Destroy_S((void*)(i3+(_check_index(i2, i4, OOC_UINT32, 167402))*4));
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
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 167557)))), &_td_OOC_IR__AssertDesc);
      if (i1) goto l99;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 167629)))), &_td_OOC_IR__AssignmentDesc);
      if (i1) goto l97;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 167703)))), &_td_OOC_IR__CallDesc);
      if (i1) goto l95;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 167808)))), &_td_OOC_IR__CopyDesc);
      if (i1) goto l93;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 167873)))), &_td_OOC_IR__CopyParameterDesc);
      if (i1) goto l91;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 167929)))), &_td_OOC_IR__CopyStringDesc);
      if (i1) goto l89;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 168026)))), &_td_OOC_IR__ExitDesc);
      if (i1) goto l87;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 168072)))), &_td_OOC_IR__ForStatmDesc);
      if (i1) goto l85;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 168204)))), &_td_OOC_IR__IterateArrayStatmDesc);
      if (i1) goto l83;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 168304)))), &_td_OOC_IR__IterateObjectStatmDesc);
      if (i1) goto l81;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 168415)))), &_td_OOC_IR__IfStatmDesc);
      if (i1) goto l79;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 168518)))), &_td_OOC_IR__CaseStatmDesc);
      if (i1) goto l68;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 168801)))), &_td_OOC_IR__LoopStatmDesc);
      if (i1) goto l66;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 168851)))), &_td_OOC_IR__MoveBlockDesc);
      if (i1) goto l64;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 168942)))), &_td_OOC_IR__RaiseDesc);
      if (i1) goto l62;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 168990)))), &_td_OOC_IR__RepeatStatmDesc);
      if (i1) goto l60;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 169072)))), &_td_OOC_IR__ReturnDesc);
      if (i1) goto l58;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 169118)))), &_td_OOC_IR__TryStatmDesc);
      if (i1) goto l47;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 169346)))), &_td_OOC_IR__WhileStatmDesc);
      if (i1) goto l45;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 169419)))), &_td_OOC_IR__WithStatmDesc);
      if (i1) goto l43;
      _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 169416)))), 169416);
      goto l100;
l43:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 169447))+8));
      OOC_IR__ModuleDesc_Destroy_SSeq((void*)((_check_pointer(i0, 169472))+12));
      OOC_IR__ModuleDesc_Destroy_SSeq((void*)((_check_pointer(i0, 169500))+16));
      goto l100;
l45:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 169375))+8));
      OOC_IR__ModuleDesc_Destroy_SSeq((void*)((_check_pointer(i0, 169400))+12));
      goto l100;
l47:
      OOC_IR__ModuleDesc_Destroy_SSeq((void*)((_check_pointer(i0, 169148))+8));
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 169189))+12);
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 169199)), 0);
      i = 0;
      i2 = 0<i1;
      if (!i2) goto l56;
      i2=0;
l51_loop:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 169220))+12);
      i0 = _check_pointer(i0, 169230);
      i3 = OOC_ARRAY_LENGTH(i0, 0);
      i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(i2, i3, OOC_UINT32, 169230))*4);
      *(OOC_INT32*)((_check_pointer(i0, 169233))+4) = (OOC_INT32)0;
      i0 = (OOC_INT32)*n;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 169265))+12);
      i3 = _check_pointer(i3, 169275);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 169275))*4);
      OOC_IR__ModuleDesc_Destroy_SSeq((void*)((_check_pointer(i3, 169278))+12));
      i2 = i2+1;
      i = i2;
      i3 = i2<i1;
      if (i3) goto l51_loop;
l56:
      *(OOC_INT32*)((_check_pointer(i0, 169316))+12) = (OOC_INT32)0;
      goto l100;
l58:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 169097))+8));
      goto l100;
l60:
      OOC_IR__ModuleDesc_Destroy_SSeq((void*)((_check_pointer(i0, 169023))+8));
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 169044))+12));
      goto l100;
l62:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 168966))+8));
      goto l100;
l64:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 168879))+8));
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 168902))+12));
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 168923))+16));
      goto l100;
l66:
      OOC_IR__ModuleDesc_Destroy_SSeq((void*)((_check_pointer(i0, 168832))+8));
      goto l100;
l68:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 168546))+8));
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 168585))+12);
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 168594)), 0);
      i = 0;
      i2 = 0<i1;
      if (!i2) goto l77;
      i2=0;
l72_loop:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 168615))+12);
      i0 = _check_pointer(i0, 168624);
      i3 = OOC_ARRAY_LENGTH(i0, 0);
      i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(i2, i3, OOC_UINT32, 168624))*4);
      *(OOC_INT32*)((_check_pointer(i0, 168627))+8) = (OOC_INT32)0;
      i0 = (OOC_INT32)*n;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 168661))+12);
      i3 = _check_pointer(i3, 168670);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 168670))*4);
      OOC_IR__ModuleDesc_Destroy_SSeq((void*)((_check_pointer(i3, 168673))+12));
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 168698))+12);
      i3 = _check_pointer(i3, 168707);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      *(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 168707))*4) = (OOC_INT32)0;
      i2 = i2+1;
      i = i2;
      i3 = i2<i1;
      if (i3) goto l72_loop;
l77:
      *(OOC_INT32*)((_check_pointer(i0, 168745))+12) = (OOC_INT32)0;
      i0 = (OOC_INT32)*n;
      OOC_IR__ModuleDesc_Destroy_SSeq((void*)((_check_pointer(i0, 168779))+16));
      goto l100;
l79:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 168441))+8));
      OOC_IR__ModuleDesc_Destroy_SSeq((void*)((_check_pointer(i0, 168466))+12));
      OOC_IR__ModuleDesc_Destroy_SSeq((void*)((_check_pointer(i0, 168494))+16));
      goto l100;
l81:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 168341))+8));
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 168361))+12));
      OOC_IR__ModuleDesc_Destroy_SSeq((void*)((_check_pointer(i0, 168396))+20));
      goto l100;
l83:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 168240))+8));
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 168260))+12));
      OOC_IR__ModuleDesc_Destroy_SSeq((void*)((_check_pointer(i0, 168285))+16));
      goto l100;
l85:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 168099))+8));
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 168119))+12));
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 168141))+16));
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 168161))+20));
      OOC_IR__ModuleDesc_Destroy_SSeq((void*)((_check_pointer(i0, 168185))+24));
      goto l100;
l87:
      *(OOC_INT32*)((_check_pointer(i0, 168047))+8) = (OOC_INT32)0;
      goto l100;
l89:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 167958))+8));
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 167981))+12));
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 168002))+16));
      goto l100;
l91:
      *(OOC_INT32*)((_check_pointer(i0, 167903))+8) = (OOC_INT32)0;
      goto l100;
l93:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 167831))+8));
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 167854))+12));
      goto l100;
l95:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 167726))+8));
      OOC_IR__ModuleDesc_Destroy_EList((void*)((_check_pointer(i0, 167753))+12));
      *(OOC_INT32*)((_check_pointer(i0, 167777))+16) = (OOC_INT32)0;
      goto l100;
l97:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 167658))+8));
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 167683))+12));
      goto l100;
l99:
      OOC_IR__ModuleDesc_Destroy_E((void*)((_check_pointer(i0, 167582))+8));
      *(OOC_INT32*)((_check_pointer(i0, 167606))+12) = 0;
l100:
      *n = (OOC_IR__Statement)(OOC_INT32)0;
l101:
      return;
      ;
    }


  i0 = (OOC_INT32)m;
  *(OOC_INT32*)((_check_pointer(i0, 169582))+4) = (OOC_INT32)0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 169619))+8);
  i = 0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 169628)), 0);
  i2 = 0<i1;
  if (!i2) goto l9;
  i2=0;
l4_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 169643))+8);
  i3 = _check_pointer(i3, 169652);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 169652))*4);
  *(OOC_INT32*)((_check_pointer(i3, 169655))+4) = (OOC_INT32)0;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 169681))+8);
  i0 = _check_pointer(i0, 169690);
  i3 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(i2, i3, OOC_UINT32, 169690))*4);
  OOC_IR__ModuleDesc_Destroy_SSeq((void*)((_check_pointer(i0, 169693))+8));
  i0 = (OOC_INT32)m;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 169712))+8);
  i2 = _check_pointer(i2, 169721);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = i;
  *(OOC_INT32*)(i2+(_check_index(i4, i3, OOC_UINT32, 169721))*4) = (OOC_INT32)0;
  i2 = i4+1;
  i = i2;
  i3 = i2<i1;
  if (i3) goto l4_loop;
l9:
  *(OOC_INT32*)((_check_pointer(i0, 169747))+8) = (OOC_INT32)0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 169771))+12);
  *(OOC_INT32*)((_check_pointer(i1, 169782))+4) = (OOC_INT32)0;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 169806))+12);
  OOC_IR__ModuleDesc_Destroy_SSeq((void*)((_check_pointer(i0, 169817))+8));
  i0 = (OOC_INT32)m;
  *(OOC_INT32*)((_check_pointer(i0, 169834))+12) = (OOC_INT32)0;
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
  *(OOC_INT32*)(_check_pointer(i0, 170132)) = i1;
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
  *(OOC_INT32*)(_check_pointer(i0, 171001)) = i1;
  i1 = (OOC_INT32)pragmaHistory;
  *(OOC_INT32*)((_check_pointer(i0, 171026))+4) = i1;
  i1 = (OOC_INT32)errList;
  *(OOC_INT32*)((_check_pointer(i0, 171065))+8) = i1;
  i1 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(17);
  i2 = (OOC_INT32)Object_Boxed__false;
  i3 = (OOC_INT32)OOC_Scanner_SymList__NewSymbol((OOC_Scanner_InputBuffer__CharArray)0, (-1));
  i1 = (OOC_INT32)OOC_IR__NewConst((OOC_Scanner_SymList__Symbol)i3, (OOC_SymbolTable__Type)i1, (Object_Boxed__Object)i2);
  *(OOC_INT32*)((_check_pointer(i0, 171092))+20) = i1;
  i1 = (OOC_INT32)OOC_IR__InitBuilder_NewTypeType((OOC_SymbolTable__Item)0, (OOC_SymbolTable__Position)0);
  *(OOC_INT32*)((_check_pointer(i0, 171254))+24) = i1;
  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)OOC_IR__InitBuilder_NewModuleType((OOC_SymbolTable__Item)0, (OOC_SymbolTable__Position)0);
  *(OOC_INT32*)((_check_pointer(i0, 171297))+28) = i1;
  i0 = (OOC_INT32)b;
  *(OOC_INT32*)((_check_pointer(i0, 171344))+36) = 0;
  i1 = (OOC_INT32)fold;
  *(OOC_INT32*)((_check_pointer(i0, 171369))+12) = i1;
  i2 = (OOC_INT32)uses;
  *(OOC_INT32*)((_check_pointer(i0, 171395))+16) = i2;
  *(OOC_INT32*)(_check_pointer(i1, 171419)) = i0;
  i1 = (OOC_INT32)module;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 171489))+48);
  i4 = (OOC_INT32)OOC_SymbolTable_Predef__nameStringType;
  i5 = (OOC_INT32)OOC_SymbolTable_Predef__nameStringModule;
  i1 = (OOC_INT32)OOC_SymbolTable_CreateNamespace__ResolveQualident((OOC_SymbolTable__Namespace)i3, (OOC_SymbolTable__Item)i1, (OOC_SymbolTable_Uses__Uses)i2, (OOC_SymbolTable__Name)i5, (OOC_SymbolTable__Name)i4);
  string = (OOC_SymbolTable__Item)i1;
  i2 = i1==0;
  if (i2) goto l3;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 171749)))), &_td_OOC_SymbolTable__TypeDeclDesc, 171749)), 171758))+48);
  *(OOC_INT32*)((_check_pointer(i0, 171722))+32) = i1;
  goto l4;
l3:
  *(OOC_INT32*)((_check_pointer(i0, 171685))+32) = 0;
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
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 172374))+8);
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 172380)))), &_td_OOC_IR__VarDesc);
  if (i1) goto l3;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 172784))+8);
  i1 = (OOC_INT32)b;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 172789));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 172753)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 29, (OOC_Scanner_SymList__Symbol)i0);
  goto l4;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 172414))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 172421)))), &_td_OOC_IR__VarDesc, 172421)), 172425))+8);
  i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 172436)))), &_td_OOC_SymbolTable__VarDeclDesc, 172436);
  var = (OOC_SymbolTable__VarDecl)i1;
  i2 = (OOC_INT32)RT0__NewObject(_td_OOC_SymbolTable__DeclarationArray.baseTypes[0], 1);
  da = (OOC_SymbolTable__DeclarationArray)i2;
  i3 = _check_pointer(i2, 172473);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 172548))+24);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 172557))+8);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 172503))+20);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 172567)))), &_td_OOC_SymbolTable__TypeDeclDesc, 172567)), 172576))+48);
  i0 = (OOC_INT32)OOC_IR__NewGuardedVar((OOC_SymbolTable__VarDecl)i1, (OOC_SymbolTable__Name)i5, (OOC_SymbolTable__Type)i0);
  *(OOC_INT32*)(i3+(_check_index(0, i4, OOC_UINT8, 172473))*4) = i0;
  i0 = (OOC_INT32)OOC_SymbolTable_Namespace__NewNested((OOC_SymbolTable__DeclarationArray)i2, 1);
  nested = (OOC_SymbolTable_Namespace__Nested)i0;
  i1 = (OOC_INT32)*namespace;
  OOC_SymbolTable_Namespace__NestedDesc_SetEnclosingNamespace((OOC_SymbolTable_Namespace__Nested)i0, (OOC_SymbolTable_Namespace__Namespace)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 172686)))), &_td_OOC_SymbolTable_Namespace__NestedDesc, 172686)));
  *namespace = (OOC_SymbolTable__Namespace)i0;
  return;
l4:
  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SymbolTable__DeclarationArray.baseTypes[0], 0);
  da = (OOC_SymbolTable__DeclarationArray)i0;
  i0 = (OOC_INT32)OOC_SymbolTable_Namespace__NewNested((OOC_SymbolTable__DeclarationArray)i0, 0);
  nested = (OOC_SymbolTable_Namespace__Nested)i0;
  i1 = (OOC_INT32)*namespace;
  OOC_SymbolTable_Namespace__NestedDesc_SetEnclosingNamespace((OOC_SymbolTable_Namespace__Nested)i0, (OOC_SymbolTable_Namespace__Namespace)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 172997)))), &_td_OOC_SymbolTable_Namespace__NestedDesc, 172997)));
  *namespace = (OOC_SymbolTable__Namespace)i0;
  return;
  ;
}

void OOC_IR__BuilderDesc_EndTypeGuard(OOC_IR__Builder b, OOC_SymbolTable__Namespace *namespace) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)*namespace;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 173169)))), &_td_OOC_SymbolTable_Namespace__NestedDesc, 173169)), 173176))+8);
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
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 173532)))), &_td_OOC_IR__TypeRefDesc);
  if (i1) goto l3;
  i0 = (OOC_INT32)b;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 173607))+20);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 173617))+4);
  type = (OOC_SymbolTable__Type)i0;
  
  goto l4;
l3:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 173572))+12);
  type = (OOC_SymbolTable__Type)i0;
  
l4:
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_SymbolTable__DeclarationArray.baseTypes[0], 1);
  da = (OOC_SymbolTable__DeclarationArray)i1;
  i2 = _check_pointer(i1, 173660);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = (OOC_INT32)b;
  i5 = (OOC_INT32)varName;
  i4 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 173736)))), OOC_IR__BuilderDesc_GetName)),OOC_IR__BuilderDesc_GetName)((OOC_IR__Builder)i4, (OOC_Scanner_SymList__Symbol)i5);
  i5 = (OOC_INT32)OOC_SymbolTable_CreateNamespace__exception;
  i0 = (OOC_INT32)OOC_IR__NewGuardedVar((OOC_SymbolTable__VarDecl)i5, (OOC_SymbolTable__Name)i4, (OOC_SymbolTable__Type)i0);
  *(OOC_INT32*)(i2+(_check_index(0, i3, OOC_UINT8, 173660))*4) = i0;
  i0 = (OOC_INT32)OOC_SymbolTable_Namespace__NewNested((OOC_SymbolTable__DeclarationArray)i1, 1);
  nested = (OOC_SymbolTable_Namespace__Nested)i0;
  i1 = (OOC_INT32)*namespace;
  OOC_SymbolTable_Namespace__NestedDesc_SetEnclosingNamespace((OOC_SymbolTable_Namespace__Nested)i0, (OOC_SymbolTable_Namespace__Namespace)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 173857)))), &_td_OOC_SymbolTable_Namespace__NestedDesc, 173857)));
  *namespace = (OOC_SymbolTable__Namespace)i0;
  return;
  ;
}

void OOC_IR__BuilderDesc_EndExceptionScope(OOC_IR__Builder b, OOC_SymbolTable__Namespace *namespace) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)*namespace;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 174038)))), &_td_OOC_SymbolTable_Namespace__NestedDesc, 174038)), 174045))+8);
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
  i1 = *(OOC_INT8*)((_check_pointer(i0, 174381))+4);
  i1 = i1==45;
  if (i1) goto l3;
  i1 = (OOC_INT32)b;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 175944)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 2, (OOC_Scanner_SymList__Symbol)i0);
  i0=i1;
  goto l52;
l3:
  i1 = (OOC_INT32)b;
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 174415)))), OOC_IR__BuilderDesc_GetName)),OOC_IR__BuilderDesc_GetName)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i0);
  n = (OOC_SymbolTable__Name)i2;
  i3 = (OOC_INT32)ns;
  i4 = (OOC_INT32)context;
  i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 174447)))), OOC_SymbolTable__NamespaceDesc_Identify)),OOC_SymbolTable__NamespaceDesc_Identify)((OOC_SymbolTable__Namespace)i3, (OOC_SymbolTable__Item)i4, (OOC_SymbolTable__Name)i2, 0u);
  decl = (OOC_SymbolTable__Declaration)i3;
  i5 = i3==(OOC_INT32)0;
  if (i5) goto l50;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 174584))+16);
  OOC_SymbolTable_Uses__Mark((OOC_SymbolTable__Declaration)i3, (OOC_SymbolTable_Uses__Uses)i5, (OOC_SymbolTable__Name)i2);
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 174612)))), &_td_OOC_SymbolTable__ConstDeclDesc);
  if (i2) goto l48;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 174703)))), &_td_OOC_SymbolTable__VarDeclDesc);
  if (i2) goto l46;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 174774)))), &_td_OOC_IR__GuardedVarDesc);
  if (i2) goto l40;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 175063)))), &_td_OOC_SymbolTable__TypeDeclDesc);
  if (i2) goto l38;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 175139)))), &_td_OOC_SymbolTable__PredefProcDesc);
  if (i2) goto l36;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 175217)))), &_td_OOC_SymbolTable__ProcDeclDesc);
  if (i2) goto l34;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 175295)))), &_td_OOC_SymbolTable__ImportDesc);
  if (i2) goto l32;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 175387)))), &_td_OOC_SymbolTable__RedirectDesc);
  if (i2) goto l22;
  Log__Type("Unknown decl in NewIdentRef", 28, (void*)i3);
  _assert(0u, 127, 175890);
  goto l51;
l22:
  i2 = (OOC_INT32)baseNS;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 175459))+48);
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 175436)))), OOC_SymbolTable__NamespaceDesc_Identify)),OOC_SymbolTable__NamespaceDesc_Identify)((OOC_SymbolTable__Namespace)i2, (OOC_SymbolTable__Item)i4, (OOC_SymbolTable__Name)i5, 0u);
  redirModule = (OOC_SymbolTable__Item)i2;
  i5 = i2==(OOC_INT32)0;
  if (i5) goto l25;
  i5 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 175526)))), &_td_OOC_SymbolTable__ImportDesc));
  
  goto l27;
l25:
  i5=1u;
l27:
  if (i5) goto l29;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 175639)))), &_td_OOC_SymbolTable__ImportDesc, 175639)), 175646))+52);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 175661))+48);
  ns = (OOC_SymbolTable__Namespace)i2;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 175779))+52);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 175785))+12);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 175779))+52);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 175785))+12);
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 175789)), 0);
  i0 = (OOC_INT32)OOC_Scanner_SymList__CloneSymbol((OOC_Scanner_SymList__Symbol)i0, (void*)(_check_pointer(i3, 175789)), i5);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 175686)))), OOC_IR__BuilderDesc_NewIdentRef)),OOC_IR__BuilderDesc_NewIdentRef)((OOC_IR__Builder)i1, (OOC_SymbolTable__Namespace)i2, (OOC_SymbolTable__Namespace)i2, (OOC_SymbolTable__Item)i4, (OOC_Scanner_SymList__Symbol)i0);
  return (OOC_IR__Expression)i0;
  goto l51;
l29:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 175559)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 41, (OOC_Scanner_SymList__Symbol)i0);
  goto l51;
l32:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 175355))+52);
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
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 174808))+48);
  i4 = (OOC_INT32)OOC_SymbolTable_CreateNamespace__exception;
  i2 = i2==i4;
  if (i2) goto l43;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 174962))+48);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 174944)))), OOC_IR__BuilderDesc_NewVar)),OOC_IR__BuilderDesc_NewVar)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i0, (OOC_SymbolTable__VarDecl)i2);
  varRef = (OOC_IR__Var)i0;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 175000))+52);
  *(OOC_INT32*)((_check_pointer(i0, 174987))+4) = i2;
  return (OOC_IR__Expression)i0;
  goto l51;
l43:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 174898))+52);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 174867)))), OOC_IR__BuilderDesc_NewCurrentException)),OOC_IR__BuilderDesc_NewCurrentException)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i0, (OOC_SymbolTable__Type)i2);
  return (OOC_IR__Expression)i0;
  goto l51;
l46:
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 174738)))), OOC_IR__BuilderDesc_NewVar)),OOC_IR__BuilderDesc_NewVar)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i0, (OOC_SymbolTable__VarDecl)i3);
  return (OOC_IR__Expression)i0;
  goto l51;
l48:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 174680))+48);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 174668))+52);
  i0 = (OOC_INT32)OOC_IR__NewConst((OOC_Scanner_SymList__Symbol)i0, (OOC_SymbolTable__Type)i3, (Object_Boxed__Object)i2);
  return (OOC_IR__Expression)i0;
  goto l51;
l50:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 174515)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 1, (OOC_Scanner_SymList__Symbol)i0);
l51:
  i0=i1;
l52:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 176185))+20);
  return (OOC_IR__Expression)i0;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_NewQualident(OOC_IR__Builder b, OOC_SymbolTable__Namespace baseNS, OOC_IR__ModuleRef modref, OOC_SymbolTable__Item context, OOC_Scanner_SymList__Symbol name) {
  register OOC_INT32 i0,i1,i2,i3,i4;

  i0 = (OOC_INT32)modref;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 176470))+8);
  i1 = (OOC_INT32)b;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 176481)))), &_td_OOC_SymbolTable__ModuleDesc, 176481)), 176488))+48);
  i2 = (OOC_INT32)baseNS;
  i3 = (OOC_INT32)context;
  i4 = (OOC_INT32)name;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 176441)))), OOC_IR__BuilderDesc_NewIdentRef)),OOC_IR__BuilderDesc_NewIdentRef)((OOC_IR__Builder)i1, (OOC_SymbolTable__Namespace)i2, (OOC_SymbolTable__Namespace)i0, (OOC_SymbolTable__Item)i3, (OOC_Scanner_SymList__Symbol)i4);
  return (OOC_IR__Expression)i0;
  ;
}

OOC_IR__Expression OOC_IR__BuilderDesc_NewTypeVar(OOC_IR__Builder b, OOC_SymbolTable__Namespace baseNS, OOC_IR__TypeRef typeRef, OOC_SymbolTable__Item context, OOC_Scanner_SymList__Symbol name) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_SymbolTable__Type type;

  i0 = (OOC_INT32)typeRef;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 176779))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 176789)))), &_td_OOC_SymbolTable__TypeDeclDesc, 176789)), 176798))+48);
  type = (OOC_SymbolTable__Type)i0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 176817))+28);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l3;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 176934))+28);
  i1 = (OOC_INT32)b;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 176943))+24);
  i2 = (OOC_INT32)baseNS;
  i3 = (OOC_INT32)context;
  i4 = (OOC_INT32)name;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 176909)))), OOC_IR__BuilderDesc_NewIdentRef)),OOC_IR__BuilderDesc_NewIdentRef)((OOC_IR__Builder)i1, (OOC_SymbolTable__Namespace)i2, (OOC_SymbolTable__Namespace)i0, (OOC_SymbolTable__Item)i3, (OOC_Scanner_SymList__Symbol)i4);
  return (OOC_IR__Expression)i0;
  goto l4;
l3:
  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)name;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 176853)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i0, 1, (OOC_Scanner_SymList__Symbol)i1);
  return (OOC_IR__Expression)i0;
l4:
  _failed_function(176553); return 0;
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
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 177278)))), OOC_IR__BuilderDesc_AssertType)),OOC_IR__BuilderDesc_AssertType)((OOC_IR__Builder)i0, (OOC_IR__Expression)i1);
  qualType = (OOC_SymbolTable__Type)i2;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 177313))+4);
  i3 = i3==(OOC_INT32)0;
  if (i3) goto l3;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 178068));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 178037)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 69, (OOC_Scanner_SymList__Symbol)i2);
  goto l31;
l3:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 177362)))), &_td_OOC_SymbolTable__QualTypeDesc, 177362)), 177371))+40);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 177380))+28);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 177389))+20);
  params = (OOC_SymbolTable__TypeVarArray)i3;
  i4 = (OOC_INT32)arguments;
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i3, 177418)), 0);
  i6 = OOC_ARRAY_LENGTH((_check_pointer(i4, 177436)), 0);
  i5 = i5<i6;
  if (i5) goto l29;
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i4, 177550)), 0);
  i6 = OOC_ARRAY_LENGTH((_check_pointer(i3, 177532)), 0);
  i5 = i6>i5;
  if (i5) goto l27;
  i = 0;
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i3, 177644)), 0);
  i6 = 0<i5;
  if (!i6) goto l31;
  i6 = (OOC_INT32)&_td_OOC_SymbolTable__TypeRef;
  i7=0;
l10_loop:
  i8 = _check_pointer(i4, 177675);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i8 = (OOC_INT32)*(OOC_INT32*)(i8+(_check_index(i7, i9, OOC_UINT32, 177675))*4);
  i8 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i8, 177679)))), &_td_OOC_IR__TypeRefDesc);
  if (!i8) goto l21;
  i8 = _check_pointer(i4, 177722);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i8 = (OOC_INT32)*(OOC_INT32*)(i8+(_check_index(i7, i9, OOC_UINT32, 177722))*4);
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i8, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i8, 177726)))), &_td_OOC_IR__TypeRefDesc, 177726)), 177734))+12);
  t = (OOC_SymbolTable__Type)i8;
  i9 = i8!=(OOC_INT32)0;
  if (i9) goto l15;
  i9=0u;
  goto l17;
l15:
  i9 = _check_pointer(i3, 177798);
  i10 = OOC_ARRAY_LENGTH(i9, 0);
  i9 = (OOC_INT32)*(OOC_INT32*)(i9+(_check_index(i7, i10, OOC_UINT32, 177798))*4);
  i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i9, 177801))+40);
  i9 = OOC_SymbolTable_TypeRules__IsExtensionOf((OOC_SymbolTable__Type)i8, (OOC_SymbolTable__Type)i9);
  
l17:
  if (i9) goto l19;
  i8 = _check_pointer(i4, 177955);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i8 = (OOC_INT32)*(OOC_INT32*)(i8+(_check_index(i7, i9, OOC_UINT32, 177955))*4);
  i8 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i8, 177958));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 177917)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 72, (OOC_Scanner_SymList__Symbol)i8);
  goto l21;
l19:
  i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 177857)))), &_td_OOC_SymbolTable__QualTypeDesc, 177857)), 177866))+48);
  i9 = OOC_ARRAY_LENGTH((_check_pointer(i9, 177876)), 0);
  i9 = _check_index(i7, i9, OOC_UINT32, 177876);
  i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 177857)))), &_td_OOC_SymbolTable__QualTypeDesc, 177857)), 177866))+48);
  i9 = _check_pointer(i9, 177876);
  i10 = OOC_ARRAY_LENGTH(i9, 0);
  OOC_SymbolTable__InitTypeRef((void*)(i9+(_check_index(i7, i10, OOC_UINT32, 177876))*8), (RT0__Struct)i6, (OOC_SymbolTable__Type)i8);
l21:
  i7 = i7+1;
  i = i7;
  i8 = i7<i5;
  if (i8) goto l10_loop;
  goto l31;
l27:
  i2 = (OOC_INT32)rParen;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 177568)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 70, (OOC_Scanner_SymList__Symbol)i2);
  goto l31;
l29:
  i2 = _check_pointer(i4, 177488);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 177499)), 0);
  i4 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i3, i4, OOC_UINT32, 177488))*4);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 177502));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 177454)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 71, (OOC_Scanner_SymList__Symbol)i2);
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
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 178499))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 178499))+4);
  i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 178504)))), OOC_SymbolTable__TypeDesc_Bound)),OOC_SymbolTable__TypeDesc_Bound)((OOC_SymbolTable__Type)i4);
  i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 178513)))), &_td_OOC_SymbolTable__PointerDesc);
  if (i3) goto l3;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 178543))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 178543))+4);
  i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 178548)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i4);
  i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 178559)))), &_td_OOC_SymbolTable__PointerDesc);
  
  goto l5;
l3:
  i3=1u;
l5:
  if (i3) goto l7;
  varRef = (OOC_IR__Expression)i1;
  i3=i1;
  goto l8;
l7:
  i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 178597)))), OOC_IR__BuilderDesc_NewDeref)),OOC_IR__BuilderDesc_NewDeref)((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i0, (OOC_IR__Expression)i1);
  varRef = (OOC_IR__Expression)i3;
  
l8:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 178678))+4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 178678))+4);
  i4 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 178683)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i5);
  type = (OOC_SymbolTable__Type)i4;
  i5 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 178707)))), &_td_OOC_SymbolTable__RecordDesc);
  if (i5) goto l11;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 179428));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 179402)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i2, 20, (OOC_Scanner_SymList__Symbol)i0);
  return (OOC_IR__Expression)i0;
  goto l28;
l11:
  i5 = (OOC_INT32)name;
  i6 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 178738)))), OOC_IR__BuilderDesc_GetName)),OOC_IR__BuilderDesc_GetName)((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i5);
  n = (OOC_SymbolTable__Name)i6;
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 178777)))), &_td_OOC_SymbolTable__RecordDesc, 178777)), 178784))+52);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 178777)))), &_td_OOC_SymbolTable__RecordDesc, 178777)), 178784))+52);
  i8 = (OOC_INT32)context;
  i4 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 178787)))), OOC_SymbolTable__NamespaceDesc_Identify)),OOC_SymbolTable__NamespaceDesc_Identify)((OOC_SymbolTable__Namespace)i4, (OOC_SymbolTable__Item)i8, (OOC_SymbolTable__Name)i6, 0u);
  decl = (OOC_SymbolTable__Declaration)i4;
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 178840))+16);
  OOC_SymbolTable_Uses__Mark((OOC_SymbolTable__Declaration)i4, (OOC_SymbolTable_Uses__Uses)i7, (OOC_SymbolTable__Name)i6);
  i6 = i4==(OOC_INT32)0;
  if (i6) goto l26;
  i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 178950)))), &_td_OOC_SymbolTable__FieldDeclDesc);
  if (i6) goto l24;
  i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 179066)))), &_td_OOC_SymbolTable__ProcDeclDesc);
  if (i6) goto l18;
  _assert(0u, 127, 179352);
  goto l28;
l18:
  i4 = _type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 179117)))), &_td_OOC_SymbolTable__ProcDeclDesc, 179117);
  procDecl = (OOC_SymbolTable__ProcDecl)i4;
  i6 = *(OOC_INT8*)((_check_pointer(i4, 179242))+48);
  i6 = i6==2;
  if (i6) goto l21;
  i6 = *(OOC_UINT8*)((_check_pointer(i4, 179317))+51);
  
  goto l22;
l21:
  i6=1u;
l22:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 179177))+4);
  i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewSelectProc((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i0, (OOC_IR__Expression)i1, (OOC_SymbolTable__Type)i3, (OOC_SymbolTable__ProcDecl)i4, (OOC_Scanner_SymList__Symbol)i5, i6);
  return (OOC_IR__Expression)i0;
  goto l28;
l24:
  i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewSelectField((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i0, (OOC_IR__Expression)i3, (OOC_SymbolTable__FieldDecl)(_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 179029)))), &_td_OOC_SymbolTable__FieldDeclDesc, 179029)), (OOC_Scanner_SymList__Symbol)i5);
  return (OOC_IR__Expression)i0;
  goto l28;
l26:
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 178899)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i2, 1, (OOC_Scanner_SymList__Symbol)i5);
  return (OOC_IR__Expression)i0;
l28:
  _failed_function(178144); return 0;
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
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 180326)))), &_td_OOC_SymbolTable__PredefTypeDesc);
      if (i1) goto l3;
      return 0u;
      goto l4;
l3:
      i0 = *(OOC_INT16*)((_check_pointer(i0, 180363))+40);
      i1 = classes;
      return (_in(i0,i1));
l4:
      _failed_function(180247); return 0;
      ;
    }

    
    OOC_IR__Expression OOC_IR__BuilderDesc_NewOperator_UnaryOperator(void) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5;
      OOC_SymbolTable__Type type;
      OOC_CHAR8 isNumeric;
      OOC_CHAR8 isSet;
      OOC_CHAR8 isBoolean;

      i0 = (OOC_INT32)b;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 180576))+20);
      i2 = (OOC_INT32)left;
      i1 = i2==i1;
      if (i1) goto l3;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 180601))+20);
      i2 = (OOC_INT32)right;
      i1 = i2==i1;
      
      goto l5;
l3:
      i1=1u;
l5:
      if (i1) goto l28;
      i1 = (OOC_INT32)right;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 180851))+4);
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
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 181273)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i0, 5, (OOC_Scanner_SymList__Symbol)i1);
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
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 181414)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i0, 5, (OOC_Scanner_SymList__Symbol)i1);
        return (OOC_IR__Expression)i0;
        goto l29;
l19:
        return (OOC_IR__Expression)i1;
        goto l29;
      case 35:
        if (i2) goto l24;
        i1 = (OOC_INT32)sym;
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 181568)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i0, 5, (OOC_Scanner_SymList__Symbol)i1);
        return (OOC_IR__Expression)i0;
        goto l29;
l24:
        i2 = (OOC_INT32)sym;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewNot((OOC_IR__Builder)i0, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i1);
        return (OOC_IR__Expression)i0;
        goto l29;
      default:
        i1 = (OOC_INT32)sym;
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 181637)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i0, 6, (OOC_Scanner_SymList__Symbol)i1);
        return (OOC_IR__Expression)i0;
        goto l29;
      }
l28:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 180811))+20);
      return (OOC_IR__Expression)i0;
l29:
      _failed_function(180451); return 0;
      ;
    }

    
    OOC_IR__Expression OOC_IR__BuilderDesc_NewOperator_BinaryOperator(void) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11;
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
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 182069)))), &_td_OOC_SymbolTable__ArrayDesc);
          if (i1) goto l5;
          i0=0u;
          goto l8;
l5:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 182109)))), &_td_OOC_SymbolTable__ArrayDesc, 182109)), 182115))+44);
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
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 182338))+20);
      i4 = (OOC_INT32)left;
      i3 = i4==i3;
      if (i3) goto l3;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 182363))+20);
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
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 182641))+4);
      i5 = OOC_SymbolTable_TypeRules__IsIntegerType((OOC_SymbolTable__Type)i5);
      
l11:
      if (i5) goto l13;
      i5=0u;
      goto l15;
l13:
      i5 = (OOC_INT32)right;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 182675))+4);
      i5 = OOC_SymbolTable_TypeRules__IsSetType((OOC_SymbolTable__Type)i5);
      
l15:
      if (i5) goto l166;
      i3 = i3==16;
      if (i3) goto l164;
      i2 = OOC_IR__BuilderDesc_WidenToCommon((OOC_IR__Builder)i2, (void*)(OOC_INT32)&left, (void*)(OOC_INT32)&right);
      if (i2) goto l33;
      i0 = (OOC_INT32)left;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 185733))+4);
      i1 = OOC_IR__BuilderDesc_NewOperator_BinaryOperator_IsString((OOC_SymbolTable__Type)i1);
      if (i1) goto l23;
      i1=0u;
      goto l25;
l23:
      i1 = (OOC_INT32)right;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 185756))+4);
      i1 = OOC_IR__BuilderDesc_NewOperator_BinaryOperator_IsString((OOC_SymbolTable__Type)i1);
      
l25:
      if (i1) goto l27;
      i0 = (OOC_INT32)b;
      i1 = (OOC_INT32)sym;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 185987)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i0, 7, (OOC_Scanner_SymList__Symbol)i1);
      
      goto l169;
l27:
      i1 = id;
      i1 = _in(i1,32256u);
      if (i1) goto l30;
      i0 = (OOC_INT32)b;
      i1 = (OOC_INT32)sym;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 185920)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i0, 5, (OOC_Scanner_SymList__Symbol)i1);
      
      goto l169;
l30:
      i1 = (OOC_INT32)right;
      i2 = (OOC_INT32)sym;
      i3 = (OOC_INT32)b;
      i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewCompare((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i0, (OOC_IR__Expression)i1);
      
      goto l169;
l33:
      i2 = (OOC_INT32)left;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 182880))+4);
      leftType = (OOC_SymbolTable__Type)i3;
      i4 = (OOC_INT32)right;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 182905))+4);
      rightType = (OOC_SymbolTable__Type)i5;
      i5 = OOC_SymbolTable_TypeRules__IsNumericType((OOC_SymbolTable__Type)i3);
      isNumeric = i5;
      i6 = OOC_SymbolTable_TypeRules__IsIntegerType((OOC_SymbolTable__Type)i3);
      isInteger = i6;
      i7 = OOC_SymbolTable_TypeRules__IsSetType((OOC_SymbolTable__Type)i3);
      isSet = i7;
      i8 = OOC_IR__BuilderDesc_NewOperator_IsPredefClass((OOC_SymbolTable__Type)i3, 1u);
      isBoolean = i8;
      i9 = OOC_SymbolTable_TypeRules__IsCharType((OOC_SymbolTable__Type)i3);
      isChar = i9;
      i10 = id;
      i11 = _in(i10,194u);
      if (i11) goto l36;
      i11=0u;
      goto l38;
l36:
      i11=i5;
l38:
      if (i11) goto l156;
      i11 = _in(i10,4u);
      if (i11) goto l42;
      i11=0u;
      goto l44;
l42:
      i11=i5;
l44:
      if (i11) goto l152;
      i1 = _in(i10,24u);
      if (i1) goto l48;
      i1=0u;
      goto l50;
l48:
      i1=i6;
l50:
      if (i1) goto l146;
      i1 = _in(i10,198u);
      if (i1) goto l54;
      i1=0u;
      goto l56;
l54:
      i1=i7;
l56:
      if (i1) goto l138;
      i1 = _in(i10,288u);
      if (i1) goto l60;
      i1=0u;
      goto l62;
l60:
      i1=i8;
l62:
      if (i1) goto l132;
      i1 = _in(i10,32256u);
      if (i1) goto l66;
      i6=0u;
      goto l68;
l66:
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 184787))+4);
      i6 = OOC_IR__BuilderDesc_NewOperator_BinaryOperator_IsString((OOC_SymbolTable__Type)i6);
      
l68:
      if (i6) goto l70;
      i6=0u;
      goto l72;
l70:
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 184810))+4);
      i6 = OOC_IR__BuilderDesc_NewOperator_BinaryOperator_IsString((OOC_SymbolTable__Type)i6);
      
l72:
      if (i6) goto l130;
      i6 = i10==6;
      if (i6) goto l76;
      i6=0u;
      goto l85;
l76:
      if (i9) goto l78;
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 184960))+4);
      i6 = OOC_SymbolTable_TypeRules__IsStringConst((OOC_SymbolTable__Type)i6);
      
      goto l80;
l78:
      i6=1u;
l80:
      if (i6) goto l82;
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 184999))+4);
      i6 = OOC_SymbolTable_TypeRules__IsSTRING((OOC_SymbolTable__Type)i6);
      
      goto l85;
l82:
      i6=1u;
l85:
      if (i6) goto l128;
      if (i1) goto l88;
      i1=0u;
      goto l93;
l88:
      if (i5) goto l90;
      i1=i9;
      goto l93;
l90:
      i1=1u;
l93:
      if (i1) goto l126;
      i1 = _in(i10,1536u);
      if (i1) goto l97;
      i0=0u;
      goto l122;
l97:
      if (i8) goto l99;
      i1=i7;
      goto l101;
l99:
      i1=1u;
l101:
      if (i1) goto l103;
      i1 = i3==i0;
      
      goto l105;
l103:
      i1=1u;
l105:
      if (i1) goto l107;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 185428))+4);
      i0 = i1==i0;
      
      goto l109;
l107:
      i0=1u;
l109:
      if (i0) goto l111;
      i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 185469)))), &_td_OOC_SymbolTable__PointerDesc);
      
      goto l113;
l111:
      i0=1u;
l113:
      if (i0) goto l115;
      i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 185513)))), &_td_OOC_SymbolTable__TypeVarDesc);
      
      goto l117;
l115:
      i0=1u;
l117:
      if (i0) goto l119;
      i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 185557)))), &_td_OOC_SymbolTable__FormalParsDesc);
      
      goto l122;
l119:
      i0=1u;
l122:
      if (i0) goto l124;
      i0 = (OOC_INT32)b;
      i1 = (OOC_INT32)sym;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 185662)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i0, 5, (OOC_Scanner_SymList__Symbol)i1);
      
      goto l169;
l124:
      i0 = (OOC_INT32)sym;
      i1 = (OOC_INT32)b;
      i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewCompare((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i0, (OOC_IR__Expression)i2, (OOC_IR__Expression)i4);
      
      goto l169;
l126:
      i0 = (OOC_INT32)sym;
      i1 = (OOC_INT32)b;
      i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewCompare((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i0, (OOC_IR__Expression)i2, (OOC_IR__Expression)i4);
      
      goto l169;
l128:
      i0 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__ExpressionList.baseTypes[0], 2);
      exprList = (OOC_IR__ExpressionList)i0;
      i1 = _check_pointer(i0, 185054);
      i3 = OOC_ARRAY_LENGTH(i1, 0);
      *(OOC_INT32*)(i1+(_check_index(0, i3, OOC_UINT8, 185054))*4) = i2;
      i1 = _check_pointer(i0, 185083);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      *(OOC_INT32*)(i1+(_check_index(1, i2, OOC_UINT8, 185083))*4) = i4;
      i1 = (OOC_INT32)sym;
      i2 = (OOC_INT32)b;
      i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewConcat((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i1, (OOC_IR__ExpressionList)i0);
      
      goto l169;
l130:
      i0 = (OOC_INT32)sym;
      i1 = (OOC_INT32)b;
      i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewCompare((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i0, (OOC_IR__Expression)i2, (OOC_IR__Expression)i4);
      
      goto l169;
l132:
      switch (i10) {
      case 5:
        variant = 20;
        goto l136;
      case 8:
        variant = 21;
        goto l136;
      default:
        _failed_case(i10, 184530);
        goto l136;
      }
l136:
      i0 = variant;
      i1 = (OOC_INT32)sym;
      i3 = (OOC_INT32)b;
      i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewBooleanOp((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i1, i0, (OOC_IR__Expression)i2, (OOC_IR__Expression)i4);
      
      goto l169;
l138:
      switch (i10) {
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
        _failed_case(i10, 184215);
        goto l144;
      }
l144:
      i0 = (OOC_INT32)b;
      i1 = variant;
      i3 = (OOC_INT32)sym;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 184422)))), OOC_IR__BuilderDesc_NewSetOp)),OOC_IR__BuilderDesc_NewSetOp)((OOC_IR__Builder)i0, (OOC_Scanner_SymList__Symbol)i3, i1, (OOC_IR__Expression)i2, (OOC_IR__Expression)i4);
      return (OOC_IR__Expression)i0;
      i0=(OOC_INT32)0;
      goto l169;
l146:
      switch (i10) {
      case 3:
        variant = 2;
        goto l150;
      case 4:
        variant = 5;
        goto l150;
      default:
        _failed_case(i10, 183919);
        goto l150;
      }
l150:
      i0 = variant;
      i1 = (OOC_INT32)sym;
      i3 = (OOC_INT32)b;
      i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewBinaryArith((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i1, i0, (OOC_IR__Expression)i2, (OOC_IR__Expression)i4);
      
      goto l169;
l152:
      if (!i6) goto l154;
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
      switch (i10) {
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
        _failed_case(i10, 183278);
        goto l161;
      }
l161:
      i0 = variant;
      i1 = (OOC_INT32)sym;
      i3 = (OOC_INT32)b;
      i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewBinaryArith((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i1, i0, (OOC_IR__Expression)i2, (OOC_IR__Expression)i4);
      
      goto l169;
l164:
      i0 = (OOC_INT32)right;
      i1 = (OOC_INT32)sym;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 182782)))), OOC_IR__BuilderDesc_NewTypeTest)),OOC_IR__BuilderDesc_NewTypeTest)((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i1, (OOC_IR__Expression)i4, (OOC_IR__Expression)i0);
      
      goto l169;
l166:
      i0 = (OOC_INT32)right;
      i1 = (OOC_INT32)sym;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 182704)))), OOC_IR__BuilderDesc_NewSetMember)),OOC_IR__BuilderDesc_NewSetMember)((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i1, (OOC_IR__Expression)i4, (OOC_IR__Expression)i0);
      
      goto l169;
l168:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 182583))+20);
      
l169:
      return (OOC_IR__Expression)i0;
      ;
    }


  i0 = (OOC_INT32)sym;
  i0 = *(OOC_INT8*)((_check_pointer(i0, 186093))+4);
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
  _failed_function(179484); return 0;
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
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 187276))+4);
      argType = (OOC_SymbolTable__Type)i0;
      i1 = (OOC_INT32)fpar;
      i2 = *(OOC_UINT8*)((_check_pointer(i1, 187297))+57);
      if (!i2) goto l4;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 187340)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
      argType = (OOC_SymbolTable__Type)i0;
      i2 = (OOC_INT32)fparType;
      i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 187380)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i2);
      fparType = (OOC_SymbolTable__Type)i2;
      
l4:
      i2 = *(OOC_UINT8*)((_check_pointer(i1, 187423))+63);
      if (i2) goto l7;
      i2=0u;
      goto l9;
l7:
      i2 = OOC_SymbolTable_TypeRules__IsPredefType((OOC_SymbolTable__Type)i0, 16);
      
l9:
      if (i2) goto l87;
      i2 = *(OOC_UINT8*)((_check_pointer(i1, 187629))+59);
      if (i2) goto l36;
      i2 = (OOC_INT32)fparType;
      i3 = OOC_SymbolTable_TypeRules__IsOpenArrayType((OOC_SymbolTable__Type)i2);
      if (i3) goto l23;
      i1 = *(OOC_UINT8*)((_check_pointer(i1, 189953))+57);
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
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 189832)))), &_td_OOC_SymbolTable__ArrayDesc, 189832)), 189838))+44);
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
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 190351));
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 190315)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 12, (OOC_Scanner_SymList__Symbol)i0);
      OOC_IR__BuilderDesc_SetNameToType((OOC_IR__Builder)i1, (OOC_SymbolTable__Type)i2);
      goto l87;
l36:
      i2 = (OOC_INT32)*arg;
      i3 = (OOC_INT32)b;
      OOC_IR__BuilderDesc_AssertVar((OOC_IR__Builder)i3, (OOC_IR__Expression)i2);
      i1 = *(OOC_UINT8*)((_check_pointer(i1, 187723))+57);
      if (i1) goto l39;
      i1=0u;
      goto l41;
l39:
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 187746)))), &_td_OOC_SymbolTable__PointerDesc);
      
l41:
      if (!i1) goto l44;
      i0 = (OOC_INT32)*arg;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 187871));
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 187857)))), OOC_IR__BuilderDesc_NewDeref)),OOC_IR__BuilderDesc_NewDeref)((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i1, (OOC_IR__Expression)i0);
      *arg = (OOC_IR__Expression)i0;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 187907))+4);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 187907))+4);
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 187912)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
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
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 188265)))), &_td_OOC_SymbolTable__ArrayDesc, 188265)), 188271))+44);
      i2 = OOC_IR__IsPredefType((OOC_SymbolTable__Type)i2, 11);
      
      goto l69;
l67:
      i2=1u;
l69:
      if (i2) goto l87;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 188537)))), &_td_OOC_SymbolTable__RecordDesc);
      if (i2) goto l80;
      i2 = OOC_SymbolTable_TypeRules__IsOpenArrayType((OOC_SymbolTable__Type)i1);
      if (i2) goto l75;
      i0 = (OOC_INT32)*arg;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 189293));
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 189259)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i3, 40, (OOC_Scanner_SymList__Symbol)i0);
      OOC_IR__BuilderDesc_SetNameToType((OOC_IR__Builder)i3, (OOC_SymbolTable__Type)i1);
      goto l87;
l75:
      i0 = OOC_SymbolTable_TypeRules__IsArrayCompatible((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
      i0 = !i0;
      if (!i0) goto l87;
      i0 = (OOC_INT32)*arg;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 189124));
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 189090)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i3, 40, (OOC_Scanner_SymList__Symbol)i0);
      OOC_IR__BuilderDesc_SetNameToType((OOC_IR__Builder)i3, (OOC_SymbolTable__Type)i1);
      goto l87;
l80:
      i0 = OOC_SymbolTable_TypeRules__IsExtensionOfNoParams((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i1);
      i0 = !i0;
      if (!i0) goto l87;
      i0 = (OOC_INT32)*arg;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 188789));
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 188755)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i3, 40, (OOC_Scanner_SymList__Symbol)i0);
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
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 191523)))), &_td_OOC_SymbolTable__ArrayDesc);
          if (i1) goto l5;
          return 0;
          goto l8;
l5:
          i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 191568)))), &_td_OOC_SymbolTable__ArrayDesc, 191568)), 191574)))), OOC_SymbolTable__TypeDesc_ArrayDimensions)),OOC_SymbolTable__TypeDesc_ArrayDimensions)((OOC_SymbolTable__Type)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 191568)))), &_td_OOC_SymbolTable__ArrayDesc, 191568)));
          return i0;
          goto l8;
l7:
          return 1;
l8:
          _failed_function(191393); return 0;
          ;
        }


      i0 = (OOC_INT32)*arguments;
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 191724)), 0);
      i1 = (OOC_INT32)ADT_ArrayList__New(i1);
      newArgs = (ADT_ArrayList__ArrayList)i1;
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 191776)), 0);
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
      i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 191980)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i3);
      fparType = (OOC_SymbolTable__Type)i3;
      i3 = _type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 192025)))), &_td_OOC_SymbolTable__FormalParsDesc, 192025);
      formalPars = (OOC_SymbolTable__FormalPars)i3;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 192078))+52);
      i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 192086)), 0);
      i3 = i1!=i3;
      if (i3) goto l7;
      i0=0u;
      goto l9;
l7:
      i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 192130)), 0);
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
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 192277))+52);
      i2 = _check_pointer(i2, 192285);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i1 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i1, i3, OOC_UINT32, 192285))*4);
      fpar = (OOC_SymbolTable__VarDecl)i1;
      i2 = (OOC_INT32)*arguments;
      i2 = _check_pointer(i2, 192324);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i0 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i0, i3, OOC_UINT32, 192324))*4);
      arg = (OOC_IR__Expression)i0;
      i0=i1;
      goto l16;
l15:
      i0 = (OOC_INT32)formalPars;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 192197))+40);
      fpar = (OOC_SymbolTable__VarDecl)i0;
      i1 = (OOC_INT32)receiver;
      arg = (OOC_IR__Expression)i1;
      
l16:
      i1 = (OOC_INT32)formalParsClosure;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 192469))+48);
      i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 192456)))), OOC_SymbolTable__TypeDesc_Closure)),OOC_SymbolTable__TypeDesc_Closure)((OOC_SymbolTable__Type)i1, (OOC_SymbolTable__Type)i2);
      i2 = (OOC_INT32)arg;
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 192388));
      i3 = (OOC_INT32)b;
      OOC_IR__BuilderDesc_NewCall_MakeParameterCompatible((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i2, (void*)(OOC_INT32)&arg, (OOC_SymbolTable__VarDecl)i0, (OOC_SymbolTable__Type)i1);
      i1 = *(OOC_UINT8*)((_check_pointer(i0, 192502))+60);
      if (i1) goto l19;
      i1=0u;
      goto l21;
l19:
      i1 = (OOC_INT32)arg;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 192555))+4);
      i1 = OOC_SymbolTable_TypeRules__IsPredefType((OOC_SymbolTable__Type)i1, 16);
      i1 = !i1;
      
l21:
      if (i1) goto l23;
      i1 = (OOC_INT32)newArgs;
      i2 = (OOC_INT32)arg;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 192910)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i1, (Object__Object)i2);
      goto l24;
l23:
      i1 = (OOC_INT32)b;
      i2 = (OOC_INT32)arg;
      i3 = (OOC_INT32)sym;
      i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 192858)))), OOC_IR__BuilderDesc_NewAdr)),OOC_IR__BuilderDesc_NewAdr)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i3, (OOC_IR__Expression)i2);
      i2 = (OOC_INT32)newArgs;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 192847)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i2, (Object__Object)i1);
l24:
      i1 = (OOC_INT32)newFPars;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 192955)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i1, (Object__Object)i0);
      i2 = *(OOC_UINT8*)((_check_pointer(i0, 192988))+64);
      if (!i2) goto l52;
      i2 = (OOC_INT32)arg;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 193034))+4);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 193034))+4);
      i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 193039)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i2);
      argType = (OOC_SymbolTable__Type)i2;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 193077))+48);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 193077))+48);
      i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 193082)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i4);
      fparType = (OOC_SymbolTable__Type)i3;
      i4 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 193117)))), &_td_OOC_SymbolTable__ArrayDesc);
      if (i4) goto l35;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 194101)))), &_td_OOC_SymbolTable__RecordDesc);
      if (!i2) goto l52;
      i0 = *(OOC_UINT8*)((_check_pointer(i0, 194136))+59);
      if (!i0) goto l52;
      i0 = (OOC_INT32)arg;
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 194203));
      i3 = (OOC_INT32)b;
      i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewTypeTag((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i0);
      i2 = (OOC_INT32)newArgs;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 194175)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i2, (Object__Object)i0);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 194239)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i1, (Object__Object)(OOC_INT32)0);
      goto l52;
l35:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 193169))+44);
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
      i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 193986));
      i4 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 193973)))), OOC_IR__BuilderDesc_NewLen)),OOC_IR__BuilderDesc_NewLen)((OOC_IR__Builder)i5, (OOC_Scanner_SymList__Symbol)i6, (OOC_IR__Expression)i4, i3);
      i5 = (OOC_INT32)b;
      i4 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 193964)))), OOC_IR__BuilderDesc_Fold)),OOC_IR__BuilderDesc_Fold)((OOC_IR__Builder)i5, (OOC_IR__Expression)i4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 193953)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i2, (Object__Object)i4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 194028)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i1, (Object__Object)(OOC_INT32)0);
      i3 = i3+1;
      i = i3;
      i4 = i3<i0;
      if (i4) goto l42_loop;
      goto l52;
l49:
      i0 = *(OOC_INT32*)((_check_pointer(i2, 193527))+32);
      i0 = (OOC_INT32)Object_BigInt__NewInt(i0);
      i2 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(6);
      i3 = (OOC_INT32)arg;
      i4 = (OOC_INT32)b;
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 193375));
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 193360)))), OOC_IR__BuilderDesc_NewConst)),OOC_IR__BuilderDesc_NewConst)((OOC_IR__Builder)i4, (OOC_Scanner_SymList__Symbol)i3, (OOC_SymbolTable__Type)i2, (Object_Boxed__Object)i0);
      i2 = (OOC_INT32)newArgs;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 193349)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i2, (Object__Object)i0);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 193559)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i1, (Object__Object)(OOC_INT32)0);
l52:
      i0 = argIndex;
      i0 = i0+1;
      i1 = fparIndex;
      argIndex = i0;
      i1 = i1+1;
      fparIndex = i1;
      i2 = (OOC_INT32)formalPars;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 192078))+52);
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 192086)), 0);
      i2 = i1!=i2;
      if (i2) goto l55;
      i2=0u;
      goto l57;
l55:
      i2 = (OOC_INT32)*arguments;
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 192130)), 0);
      i2 = i0!=i2;
      
l57:
      if (i2) goto l12_loop;
l61:
      i2 = (OOC_INT32)formalPars;
      i3 = (OOC_INT32)newArgs;
      i4 = *(OOC_UINT8*)((_check_pointer(i2, 194490))+56);
      if (!i4) goto l74;
      i4 = (OOC_INT32)*arguments;
      i5 = OOC_ARRAY_LENGTH((_check_pointer(i4, 194555)), 0);
      i5 = i0!=i5;
      if (!i5) goto l74;
      i5 = (OOC_INT32)newFPars;
      
l68_loop:
      i6 = _check_pointer(i4, 194588);
      i7 = OOC_ARRAY_LENGTH(i6, 0);
      i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i0, i7, OOC_UINT32, 194588))*4);
      arg = (OOC_IR__Expression)i6;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 194617)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i3, (Object__Object)i6);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 194651)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i5, (Object__Object)(OOC_INT32)0);
      i0 = i0+1;
      argIndex = i0;
      i6 = OOC_ARRAY_LENGTH((_check_pointer(i4, 194555)), 0);
      i6 = i0!=i6;
      if (i6) goto l68_loop;
l74:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 194761))+52);
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 194769)), 0);
      i1 = i1!=i2;
      if (i1) goto l80;
      i1 = (OOC_INT32)*arguments;
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i1, 194919)), 0);
      i2 = i0!=i2;
      if (!i2) goto l81;
      i1 = _check_pointer(i1, 195026);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i0 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(i0, i2, OOC_UINT32, 195026))*4);
      i1 = (OOC_INT32)b;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 195036));
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 194989)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 39, (OOC_Scanner_SymList__Symbol)i0);
      goto l81;
l80:
      i0 = (OOC_INT32)b;
      i1 = (OOC_INT32)endOfArgsSym;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 194839)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 38, (OOC_Scanner_SymList__Symbol)i1);
l81:
      i0 = *(OOC_INT32*)((_check_pointer(i3, 195091))+4);
      *arguments = (OOC_IR__ExpressionList)((OOC_INT32)RT0__NewObject(_td_OOC_IR__ExpressionList.baseTypes[0], i0));
      i0 = *(OOC_INT32*)((_check_pointer(i3, 195133))+4);
      *argFormalPars = (OOC_SymbolTable__VarDeclArray)((OOC_INT32)RT0__NewObject(_td_OOC_SymbolTable__VarDeclArray.baseTypes[0], i0));
      i0 = *(OOC_INT32*)((_check_pointer(i3, 195169))+4);
      i = 0;
      i1 = 0<i0;
      if (!i1) goto l93;
      i1 = (OOC_INT32)newFPars;
      i2=0;
l84_loop:
      i4 = (OOC_INT32)*arguments;
      i4 = _check_pointer(i4, 195198);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 195212));
      i6 = _check_pointer(i6, 195219);
      i7 = OOC_ARRAY_LENGTH(i6, 0);
      i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i2, i7, OOC_UINT32, 195219))*4);
      *(OOC_INT32*)(i4+(_check_index(i2, i5, OOC_UINT32, 195198))*4) = (_type_guard(i6, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 195223)))), &_td_OOC_IR__ExpressionDesc, 195223));
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 195256));
      i4 = _check_pointer(i4, 195263);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i2, i5, OOC_UINT32, 195263))*4);
      i4 = i4==(OOC_INT32)0;
      if (i4) goto l87;
      i4 = (OOC_INT32)*argFormalPars;
      i4 = _check_pointer(i4, 195350);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 195365));
      i6 = _check_pointer(i6, 195372);
      i7 = OOC_ARRAY_LENGTH(i6, 0);
      i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i2, i7, OOC_UINT32, 195372))*4);
      *(OOC_INT32*)(i4+(_check_index(i2, i5, OOC_UINT32, 195350))*4) = (_type_guard(i6, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 195380)))), &_td_OOC_SymbolTable__VarDeclDesc, 195380));
      goto l88;
l87:
      i4 = (OOC_INT32)*argFormalPars;
      i4 = _check_pointer(i4, 195302);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      *(OOC_INT32*)(i4+(_check_index(i2, i5, OOC_UINT32, 195302))*4) = (OOC_INT32)0;
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
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 195537)), 0);
      i2 = min;
      i1 = i1<i2;
      if (i1) goto l3;
      i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 195565)), 0);
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
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 195629));
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 195589)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 13, (OOC_Scanner_SymList__Symbol)i0);
      return 0u;
l8:
      _failed_function(195450); return 0;
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
          i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 196023)), 0);
          i1 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__ExpressionList.baseTypes[0], (i1-1));
          newList = (OOC_IR__ExpressionList)i1;
          i = 1;
          i2 = OOC_ARRAY_LENGTH((_check_pointer(i0, 196064)), 0);
          i3 = 1<i2;
          if (!i3) goto l8;
          i3=1;
l3_loop:
          i4 = _check_pointer(i1, 196089);
          i5 = OOC_ARRAY_LENGTH(i4, 0);
          i6 = _check_pointer(i0, 196106);
          i7 = OOC_ARRAY_LENGTH(i6, 0);
          i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i3, i7, OOC_UINT32, 196106))*4);
          *(OOC_INT32*)(i4+(_check_index((i3-1), i5, OOC_UINT32, 196089))*4) = i6;
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
        i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 196285)), 0);
        i1 = i1>1;
        if (i1) goto l5;
        code = (OOC_IR__Expression)(OOC_INT32)0;
        goto l6;
l5:
        i0 = _check_pointer(i0, 196325);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(1, i1, OOC_UINT8, 196325))*4);
        code = (OOC_IR__Expression)i0;
l6:
        i0 = (OOC_INT32)design;
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 196507));
        i1 = *(OOC_INT32*)((_check_pointer(i1, 196512))+16);
        i2 = (OOC_INT32)OOC_Config_StdPragmas__assertions;
        i3 = (OOC_INT32)b;
        i1 = OOC_IR__GetPragmaValue((OOC_IR__Builder)i3, (Config_Section_Options__Option)i2, i1);
        i2 = (OOC_INT32)arguments;
        i2 = _check_pointer(i2, 196430);
        i3 = OOC_ARRAY_LENGTH(i2, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 196414));
        i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(0, i3, OOC_UINT8, 196430))*4);
        i3 = (OOC_INT32)code;
        i4 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewAssert((OOC_IR__Builder)i4, (OOC_Scanner_SymList__Symbol)i0, (OOC_IR__Expression)i2, (OOC_IR__Expression)i3, (!i1));
        return (OOC_IR__Expression)i0;
        goto l168;
      case 1:
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 196599);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i2 = (OOC_INT32)design;
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 196578));
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 196599))*4);
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewAssert((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)(OOC_INT32)0, (OOC_IR__Expression)i0, 0u);
        return (OOC_IR__Expression)i0;
        goto l168;
      case 22:
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 196774);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i2 = (OOC_INT32)design;
        i3 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(1, i1, OOC_UINT8, 196774))*4);
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 196758));
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 196742)))), OOC_IR__BuilderDesc_NewLen)),OOC_IR__BuilderDesc_NewLen)((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i1, (OOC_IR__Expression)i0, 0);
        i1 = (OOC_INT32)arguments;
        i3 = _check_pointer(i1, 196703);
        i4 = OOC_ARRAY_LENGTH(i3, 0);
        i1 = _check_pointer(i1, 196689);
        i5 = OOC_ARRAY_LENGTH(i1, 0);
        i6 = (OOC_INT32)b;
        i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(1, i4, OOC_UINT8, 196703))*4);
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i5, OOC_UINT8, 196689))*4);
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 196673));
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 196650)))), OOC_IR__BuilderDesc_NewCopyString)),OOC_IR__BuilderDesc_NewCopyString)((OOC_IR__Builder)i6, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i1, (OOC_IR__Expression)i3, (OOC_IR__Expression)i0);
        return (OOC_IR__Expression)i0;
        goto l168;
      case 21:
        i0 = (OOC_INT32)arguments;
        i1 = _check_pointer(i0, 196838);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 196838))*4);
        i0 = _check_pointer(i0, 196838);
        i2 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i2, OOC_UINT8, 196838))*4);
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 196841))+4);
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 196841))+4);
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 196846)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i1);
        type = (OOC_SymbolTable__Type)i0;
        i1 = (OOC_INT32)b;
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 196878))+24);
        i2 = i0==i2;
        if (i2) goto l29;
        i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 197315)))), &_td_OOC_SymbolTable__PointerDesc);
        if (i0) goto l14;
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 198220);
        i2 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i2, OOC_UINT8, 198220))*4);
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 198223));
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 198188)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 50, (OOC_Scanner_SymList__Symbol)i0);
        goto l37;
l14:
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 197367);
        i2 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i2, OOC_UINT8, 197367))*4);
        OOC_IR__BuilderDesc_AssertVar((OOC_IR__Builder)i1, (OOC_IR__Expression)i0);
        i0 = (OOC_INT32)type;
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 197400)))), &_td_OOC_SymbolTable__PointerDesc, 197400)), 197408))+40);
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 197400)))), &_td_OOC_SymbolTable__PointerDesc, 197400)), 197408))+40);
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 197417)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
        type = (OOC_SymbolTable__Type)i0;
        i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 197448)))), &_td_OOC_SymbolTable__ArrayDesc);
        if (i1) goto l23;
        i0 = OOC_SymbolTable_TypeRules__VariableInstance((OOC_SymbolTable__Type)i0);
        i0 = !i0;
        if (!i0) goto l19;
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 197900);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 197900))*4);
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 197903));
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 197861)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 56, (OOC_Scanner_SymList__Symbol)i0);
l19:
        i0 = OOC_IR__BuilderDesc_NewCall_CheckNumberOfArguments(1, 1);
        if (!i0) goto l37;
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 198115);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 198115))*4);
        i1 = (OOC_INT32)design;
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 198118))+4);
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 198100));
        i3 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewNewObject((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i2, (OOC_SymbolTable__Type)i0, (OOC_IR__ExpressionList)(OOC_INT32)0);
        i2 = (OOC_INT32)arguments;
        i2 = _check_pointer(i2, 198055);
        i3 = OOC_ARRAY_LENGTH(i2, 0);
        i4 = (OOC_INT32)b;
        i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(0, i3, OOC_UINT8, 198055))*4);
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 198040));
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 197999)))), OOC_IR__BuilderDesc_NewAssignment)),OOC_IR__BuilderDesc_NewAssignment)((OOC_IR__Builder)i4, (OOC_Scanner_SymList__Symbol)i1, (OOC_IR__Expression)i2, (OOC_IR__Expression)i0);
        return (OOC_IR__Expression)i0;
        goto l37;
l23:
        i0 = OOC_SymbolTable__ArrayDesc_GetOpenDimensions((OOC_SymbolTable__Array)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 197497)))), &_td_OOC_SymbolTable__ArrayDesc, 197497)));
        i0 = 1+i0;
        dim = i0;
        i0 = OOC_IR__BuilderDesc_NewCall_CheckNumberOfArguments(i0, i0);
        if (!i0) goto l37;
        i0 = (OOC_INT32)arguments;
        i1 = _check_pointer(i0, 197717);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 197717))*4);
        i2 = (OOC_INT32)design;
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 197720))+4);
        i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 197702));
        i4 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewNewObject((OOC_IR__Builder)i4, (OOC_Scanner_SymList__Symbol)i3, (OOC_SymbolTable__Type)i1, (OOC_IR__ExpressionList)i0);
        i1 = (OOC_INT32)arguments;
        i1 = _check_pointer(i1, 197657);
        i3 = OOC_ARRAY_LENGTH(i1, 0);
        i4 = (OOC_INT32)b;
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i3, OOC_UINT8, 197657))*4);
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 197642));
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 197601)))), OOC_IR__BuilderDesc_NewAssignment)),OOC_IR__BuilderDesc_NewAssignment)((OOC_IR__Builder)i4, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i1, (OOC_IR__Expression)i0);
        return (OOC_IR__Expression)i0;
        goto l37;
l29:
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 196921);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 196921))*4);
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 196925)))), &_td_OOC_IR__TypeRefDesc, 196925)), 196933))+12);
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
        i0 = _check_pointer(i0, 197095);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 197095))*4);
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 197098));
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 197056)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 56, (OOC_Scanner_SymList__Symbol)i0);
l36:
        i0 = (OOC_INT32)endOfArgsSym;
        i1 = (OOC_INT32)context;
        i2 = (OOC_INT32)arguments;
        i2 = (OOC_INT32)OOC_IR__BuilderDesc_NewCall_TranslatePredef_StripFirst((OOC_IR__ExpressionList)i2);
        i3 = (OOC_INT32)arguments;
        i3 = _check_pointer(i3, 197175);
        i4 = OOC_ARRAY_LENGTH(i3, 0);
        i5 = (OOC_INT32)design;
        i6 = (OOC_INT32)b;
        i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(0, i4, OOC_UINT8, 197175))*4);
        i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 197160));
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 197138)))), OOC_IR__BuilderDesc_NewConstructor)),OOC_IR__BuilderDesc_NewConstructor)((OOC_IR__Builder)i6, (OOC_Scanner_SymList__Symbol)i4, (OOC_IR__Expression)i3, (OOC_IR__ExpressionList)i2, (OOC_SymbolTable__Item)i1, (OOC_Scanner_SymList__Symbol)i0);
        return (OOC_IR__Expression)i0;
l37:
        i0 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 198259))+20);
        return (OOC_IR__Expression)i0;
        goto l168;
      case 4:
      case 5:
        i0 = (OOC_INT32)arguments;
        i1 = _check_pointer(i0, 198330);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i0 = _check_pointer(i0, 198362);
        i3 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i3, OOC_UINT8, 198362))*4);
        i3 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_AssertInteger((OOC_IR__Builder)i3, (OOC_IR__Expression)i0);
        *(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 198330))*4) = i0;
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 198397);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 198397))*4);
        i1 = (OOC_INT32)b;
        OOC_IR__BuilderDesc_AssertVar((OOC_IR__Builder)i1, (OOC_IR__Expression)i0);
        i0 = (OOC_INT32)arguments;
        i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 198429)), 0);
        i1 = i1==1;
        if (i1) goto l41;
        i0 = _check_pointer(i0, 198547);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(1, i1, OOC_UINT8, 198547))*4);
        delta = (OOC_IR__Expression)i0;
        goto l42;
l41:
        i0 = _check_pointer(i0, 198494);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 198494))*4);
        i1 = (OOC_INT32)design;
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 198497))+4);
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 198478));
        i2 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_GetOne((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i1, (OOC_SymbolTable__Type)i0);
        delta = (OOC_IR__Expression)i0;
l42:
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 198600);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 198600))*4);
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 198603))+4);
        i1 = (OOC_INT32)b;
        i0 = OOC_IR__BuilderDesc_Widen((OOC_IR__Builder)i1, (void*)(OOC_INT32)&delta, (OOC_SymbolTable__Type)i0);
        if (i0) goto l45;
        i0 = (OOC_INT32)delta;
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 198990));
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 198962)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 5, (OOC_Scanner_SymList__Symbol)i0);
        i0 = (OOC_INT32)arguments;
        i1 = _check_pointer(i0, 199066);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i0 = _check_pointer(i0, 199052);
        i3 = OOC_ARRAY_LENGTH(i0, 0);
        i4 = (OOC_INT32)design;
        i5 = (OOC_INT32)b;
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 199066))*4);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i3, OOC_UINT8, 199052))*4);
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 199037));
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 199015)))), OOC_IR__BuilderDesc_NewAssignment)),OOC_IR__BuilderDesc_NewAssignment)((OOC_IR__Builder)i5, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i0, (OOC_IR__Expression)i1);
        return (OOC_IR__Expression)i0;
        goto l168;
l45:
        i0 = (OOC_INT32)design;
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 198635))+8);
        i1 = *(OOC_INT16*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 198646)))), &_td_OOC_SymbolTable__PredefProcDesc, 198646)), 198657))+48);
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
        i2 = _check_pointer(i2, 198924);
        i3 = OOC_ARRAY_LENGTH(i2, 0);
        i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 198904));
        i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(0, i3, OOC_UINT8, 198924))*4);
        i3 = (OOC_INT32)b;
        i5 = (OOC_INT32)delta;
        i1 = (OOC_INT32)OOC_IR__BuilderDesc_NewBinaryArith((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i4, i1, (OOC_IR__Expression)i2, (OOC_IR__Expression)i5);
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 198806));
        i2 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewAssignOp((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i0, (OOC_IR__Expression)i1);
        return (OOC_IR__Expression)i0;
        goto l168;
      case 6:
      case 7:
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 199157);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 199157))*4);
        i1 = (OOC_INT32)b;
        OOC_IR__BuilderDesc_AssertVar((OOC_IR__Builder)i1, (OOC_IR__Expression)i0);
        i0 = (OOC_INT32)arguments;
        i1 = _check_pointer(i0, 199180);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i0 = _check_pointer(i0, 199208);
        i3 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i3, OOC_UINT8, 199208))*4);
        i3 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_AssertSet((OOC_IR__Builder)i3, (OOC_IR__Expression)i0);
        *(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 199180))*4) = i0;
        i0 = (OOC_INT32)arguments;
        i1 = _check_pointer(i0, 199231);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i0 = _check_pointer(i0, 199263);
        i3 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(1, i3, OOC_UINT8, 199263))*4);
        i3 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_AssertInteger((OOC_IR__Builder)i3, (OOC_IR__Expression)i0);
        *(OOC_INT32*)(i1+(_check_index(1, i2, OOC_UINT8, 199231))*4) = i0;
        i0 = (OOC_INT32)design;
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 199287))+8);
        i1 = *(OOC_INT16*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 199298)))), &_td_OOC_SymbolTable__PredefProcDesc, 199298)), 199309))+48);
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
        i3 = _check_pointer(i2, 199601);
        i4 = OOC_ARRAY_LENGTH(i3, 0);
        i2 = _check_pointer(i2, 199587);
        i5 = OOC_ARRAY_LENGTH(i2, 0);
        i6 = (OOC_INT32)b;
        i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(1, i4, OOC_UINT8, 199601))*4);
        i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(0, i5, OOC_UINT8, 199587))*4);
        i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 199517));
        i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 199492)))), OOC_IR__BuilderDesc_NewChangeElement)),OOC_IR__BuilderDesc_NewChangeElement)((OOC_IR__Builder)i6, (OOC_Scanner_SymList__Symbol)i4, i1, (OOC_IR__Expression)i2, (OOC_IR__Expression)i3);
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 199454));
        i2 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewAssignOp((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i0, (OOC_IR__Expression)i1);
        return (OOC_IR__Expression)i0;
        goto l168;
      case 23:
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 199678);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i2 = (OOC_INT32)design;
        i3 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 199678))*4);
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 199663));
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 199647)))), OOC_IR__BuilderDesc_NewRaise)),OOC_IR__BuilderDesc_NewRaise)((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i1, (OOC_IR__Expression)i0);
        return (OOC_IR__Expression)i0;
        goto l168;
      case 2:
        i0 = (OOC_INT32)arguments;
        i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 199772)), 0);
        i1 = i1!=2;
        if (i1) goto l60;
        i1 = _check_pointer(i0, 199944);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 199944))*4);
        i0 = _check_pointer(i0, 199944);
        i2 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i2, OOC_UINT8, 199944))*4);
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 199947))+4);
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 199947))+4);
        i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 199953)))), OOC_SymbolTable__TypeDesc_ArrayDimensions)),OOC_SymbolTable__TypeDesc_ArrayDimensions)((OOC_SymbolTable__Type)i1);
        i1 = (OOC_INT32)arguments;
        i1 = _check_pointer(i1, 199891);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(1, i2, OOC_UINT8, 199891))*4);
        i2 = (OOC_INT32)b;
        i0 = OOC_IR__BuilderDesc_AssertIntConst((OOC_IR__Builder)i2, (OOC_IR__Expression)i1, 0, i0);
        dim = i0;
        goto l61;
l60:
        dim = 0;
l61:
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 200029);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 200029))*4);
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 200032))+4);
        i0 = OOC_SymbolTable_TypeRules__IsArray((OOC_SymbolTable__Type)i0);
        i0 = !i0;
        if (!i0) goto l64;
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 200129);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 200129))*4);
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 200132));
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 200100)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 15, (OOC_Scanner_SymList__Symbol)i0);
l64:
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 200210);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i2 = (OOC_INT32)design;
        i3 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 200210))*4);
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 200194));
        i2 = dim;
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 200178)))), OOC_IR__BuilderDesc_NewLen)),OOC_IR__BuilderDesc_NewLen)((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i1, (OOC_IR__Expression)i0, i2);
        return (OOC_IR__Expression)i0;
        goto l168;
      case 20:
      case 19:
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 200294);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i2 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 200294))*4);
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 200271)))), OOC_IR__BuilderDesc_AssertType)),OOC_IR__BuilderDesc_AssertType)((OOC_IR__Builder)i2, (OOC_IR__Expression)i0);
        type = (OOC_SymbolTable__Type)i0;
        i1 = (OOC_INT32)design;
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 200318))+8);
        i1 = *(OOC_INT16*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 200329)))), &_td_OOC_SymbolTable__PredefProcDesc, 200329)), 200340))+48);
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
        i2 = _check_pointer(i2, 200743);
        i3 = OOC_ARRAY_LENGTH(i2, 0);
        i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(0, i3, OOC_UINT8, 200743))*4);
        i3 = (OOC_INT32)b;
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 200746));
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 200722)))), OOC_IR__BuilderDesc_NewConst)),OOC_IR__BuilderDesc_NewConst)((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i2, (OOC_SymbolTable__Type)i0, (Object_Boxed__Object)i1);
        return (OOC_IR__Expression)i0;
        goto l168;
l76:
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 200550);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 200550))*4);
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 200553));
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 200520)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i1, 18, (OOC_Scanner_SymList__Symbol)i0);
        return (OOC_IR__Expression)i0;
        goto l168;
      case 3:
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 200859);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i2 = (OOC_INT32)design;
        i3 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 200859))*4);
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 200843));
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 200826)))), OOC_IR__BuilderDesc_NewSize)),OOC_IR__BuilderDesc_NewSize)((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i1, (OOC_IR__Expression)i0);
        return (OOC_IR__Expression)i0;
        goto l168;
      case 8:
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 200933);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i2 = (OOC_INT32)design;
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 200917));
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 200933))*4);
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewAbs((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i0);
        return (OOC_IR__Expression)i0;
        goto l168;
      case 9:
        i0 = (OOC_INT32)arguments;
        i1 = _check_pointer(i0, 201030);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i0 = _check_pointer(i0, 201016);
        i3 = OOC_ARRAY_LENGTH(i0, 0);
        i4 = (OOC_INT32)design;
        i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 201000));
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(1, i2, OOC_UINT8, 201030))*4);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i3, OOC_UINT8, 201016))*4);
        i2 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewAsh((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i4, (OOC_IR__Expression)i0, (OOC_IR__Expression)i1);
        return (OOC_IR__Expression)i0;
        goto l168;
      case 10:
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 201126);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 201126))*4);
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_AssertChar((OOC_IR__Builder)i1, (OOC_IR__Expression)i0);
        i1 = (OOC_INT32)design;
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 201097));
        i2 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewCap((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i1, (OOC_IR__Expression)i0);
        return (OOC_IR__Expression)i0;
        goto l168;
      case 11:
        i0 = (OOC_INT32)arguments;
        i1 = _check_pointer(i0, 201176);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 201176))*4);
        i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 201180)))), &_td_OOC_IR__ConstDesc);
        if (i1) goto l85;
        i1=0u;
        goto l87;
l85:
        i1 = _check_pointer(i0, 201218);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 201218))*4);
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 201221))+4);
        i1 = OOC_SymbolTable_TypeRules__IsIntegerType((OOC_SymbolTable__Type)i1);
        
l87:
        if (i1) goto l102;
        i1 = _check_pointer(i0, 201341);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 201341))*4);
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 201344))+4);
        i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 201350)))), &_td_OOC_SymbolTable__PredefTypeDesc);
        if (i1) goto l91;
        i0 = _check_pointer(i0, 202088);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 202088))*4);
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 202091));
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 202056)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 5, (OOC_Scanner_SymList__Symbol)i0);
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 202124);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 202124))*4);
        return (OOC_IR__Expression)i0;
        goto l168;
l91:
        i1 = _check_pointer(i0, 201398);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 201398))*4);
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 201401))+4);
        i1 = *(OOC_INT16*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 201411)))), &_td_OOC_SymbolTable__PredefTypeDesc, 201411)), 201422))+40);
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
          i0 = _check_pointer(i0, 201846);
          i1 = OOC_ARRAY_LENGTH(i0, 0);
          i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 201846))*4);
          i1 = (OOC_INT32)b;
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 201849));
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 201814)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 5, (OOC_Scanner_SymList__Symbol)i0);
          i0 = (OOC_INT32)arguments;
          i1 = _check_pointer(i0, 201884);
          i2 = OOC_ARRAY_LENGTH(i1, 0);
          i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 201884))*4);
          return (OOC_IR__Expression)i1;
          
          goto l100;
        }
l100:
        i0 = _check_pointer(i0, 201974);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i2 = targetType;
        i2 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(i2);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 201974))*4);
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewTypeConv((OOC_IR__Builder)i1, (OOC_SymbolTable__Type)i2, (OOC_IR__Expression)i0);
        return (OOC_IR__Expression)i0;
        goto l168;
l102:
        i0 = _check_pointer(i0, 201312);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 201312))*4);
        return (OOC_IR__Expression)i0;
        goto l168;
      case 12:
        i0 = (OOC_INT32)arguments;
        i1 = _check_pointer(i0, 202194);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 202194))*4);
        i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 202198)))), &_td_OOC_IR__ConstDesc);
        if (i1) goto l107;
        i1=0u;
        goto l109;
l107:
        i1 = _check_pointer(i0, 202236);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 202236))*4);
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 202239))+4);
        i1 = OOC_SymbolTable_TypeRules__IsIntegerType((OOC_SymbolTable__Type)i1);
        
l109:
        if (i1) goto l124;
        i1 = _check_pointer(i0, 202360);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 202360))*4);
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 202363))+4);
        i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 202369)))), &_td_OOC_SymbolTable__PredefTypeDesc);
        if (i1) goto l113;
        i0 = _check_pointer(i0, 203097);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 203097))*4);
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 203100));
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 203065)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 5, (OOC_Scanner_SymList__Symbol)i0);
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 203133);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 203133))*4);
        return (OOC_IR__Expression)i0;
        goto l168;
l113:
        i1 = _check_pointer(i0, 202417);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 202417))*4);
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 202420))+4);
        i1 = *(OOC_INT16*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 202430)))), &_td_OOC_SymbolTable__PredefTypeDesc, 202430)), 202441))+40);
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
          i0 = _check_pointer(i0, 202855);
          i1 = OOC_ARRAY_LENGTH(i0, 0);
          i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 202855))*4);
          i1 = (OOC_INT32)b;
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 202858));
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 202823)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 5, (OOC_Scanner_SymList__Symbol)i0);
          i0 = (OOC_INT32)arguments;
          i1 = _check_pointer(i0, 202893);
          i2 = OOC_ARRAY_LENGTH(i1, 0);
          i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 202893))*4);
          return (OOC_IR__Expression)i1;
          
          goto l122;
        }
l122:
        i0 = _check_pointer(i0, 202983);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i2 = targetType;
        i2 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(i2);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 202983))*4);
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewTypeConv((OOC_IR__Builder)i1, (OOC_SymbolTable__Type)i2, (OOC_IR__Expression)i0);
        return (OOC_IR__Expression)i0;
        goto l168;
l124:
        i0 = _check_pointer(i0, 202331);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 202331))*4);
        return (OOC_IR__Expression)i0;
        goto l168;
      case 13:
        i0 = (OOC_INT32)arguments;
        i1 = _check_pointer(i0, 203197);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i0 = _check_pointer(i0, 203229);
        i3 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i3, OOC_UINT8, 203229))*4);
        i3 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_AssertInteger((OOC_IR__Builder)i3, (OOC_IR__Expression)i0);
        *(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 203197))*4) = i0;
        i0 = (OOC_INT32)arguments;
        i1 = _check_pointer(i0, 203256);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 203256))*4);
        i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 203260)))), &_td_OOC_IR__ConstDesc);
        if (!i1) goto l129;
        i0 = _check_pointer(i0, 203470);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 203470))*4);
        i1 = (OOC_INT32)b;
        i0 = OOC_IR__BuilderDesc_AssertIntConst((OOC_IR__Builder)i1, (OOC_IR__Expression)i0, 0, 256);
        dummy = i0;
l129:
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 203638);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i2 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(1);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 203638))*4);
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewTypeConv((OOC_IR__Builder)i1, (OOC_SymbolTable__Type)i2, (OOC_IR__Expression)i0);
        return (OOC_IR__Expression)i0;
        goto l168;
      case 14:
        i0 = (OOC_INT32)arguments;
        i1 = _check_pointer(i0, 203685);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i0 = _check_pointer(i0, 203717);
        i3 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i3, OOC_UINT8, 203717))*4);
        i3 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_AssertInteger((OOC_IR__Builder)i3, (OOC_IR__Expression)i0);
        *(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 203685))*4) = i0;
        i0 = (OOC_INT32)arguments;
        i1 = _check_pointer(i0, 203744);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 203744))*4);
        i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 203748)))), &_td_OOC_IR__ConstDesc);
        if (!i1) goto l133;
        i0 = _check_pointer(i0, 203958);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 203958))*4);
        i1 = (OOC_INT32)b;
        i0 = OOC_IR__BuilderDesc_AssertIntConst((OOC_IR__Builder)i1, (OOC_IR__Expression)i0, 0, 65536);
        dummy = i0;
l133:
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 204174);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i2 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(2);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 204174))*4);
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewTypeConv((OOC_IR__Builder)i1, (OOC_SymbolTable__Type)i2, (OOC_IR__Expression)i0);
        return (OOC_IR__Expression)i0;
        goto l168;
      case 15:
        i0 = (OOC_INT32)arguments;
        i1 = _check_pointer(i0, 204230);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i0 = _check_pointer(i0, 204262);
        i3 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i3, OOC_UINT8, 204262))*4);
        i3 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_AssertInteger((OOC_IR__Builder)i3, (OOC_IR__Expression)i0);
        *(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 204230))*4) = i0;
        i0 = (OOC_INT32)arguments;
        i1 = _check_pointer(i0, 204289);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 204289))*4);
        i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 204293)))), &_td_OOC_IR__ConstDesc);
        if (!i1) goto l137;
        i0 = _check_pointer(i0, 204503);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 204503))*4);
        i1 = (OOC_INT32)b;
        i0 = OOC_IR__BuilderDesc_AssertIntConst((OOC_IR__Builder)i1, (OOC_IR__Expression)i0, 0, 1114111);
        dummy = i0;
l137:
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 204764);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i2 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(3);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 204764))*4);
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewTypeConv((OOC_IR__Builder)i1, (OOC_SymbolTable__Type)i2, (OOC_IR__Expression)i0);
        return (OOC_IR__Expression)i0;
        goto l168;
      case 16:
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 204853);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i2 = (OOC_INT32)design;
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 204837));
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 204853))*4);
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewEntier((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i0);
        return (OOC_IR__Expression)i0;
        goto l168;
      case 17:
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 204936);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i2 = (OOC_INT32)design;
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 204920));
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 204936))*4);
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewOdd((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i0);
        return (OOC_IR__Expression)i0;
        goto l168;
      case 18:
        i0 = (OOC_INT32)arguments;
        i1 = _check_pointer(i0, 204992);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 204992))*4);
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 204995))+4);
        i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 205001)))), &_td_OOC_SymbolTable__PredefTypeDesc);
        if (i1) goto l143;
        i1=0u;
        goto l149;
l143:
        i1 = _check_pointer(i0, 205044);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 205044))*4);
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 205047))+4);
        i1 = *(OOC_INT16*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 205057)))), &_td_OOC_SymbolTable__PredefTypeDesc, 205057)), 205068))+40);
        i1 = i1==2;
        if (i1) goto l146;
        i1 = _check_pointer(i0, 205116);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 205116))*4);
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 205119))+4);
        i1 = *(OOC_INT16*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 205129)))), &_td_OOC_SymbolTable__PredefTypeDesc, 205129)), 205140))+40);
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
        i0 = _check_pointer(i0, 205420);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 205420))*4);
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
        i1 = _check_pointer(i0, 205602);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i3 = _check_pointer(i0, 205588);
        i4 = OOC_ARRAY_LENGTH(i3, 0);
        i0 = _check_pointer(i0, 205574);
        i5 = OOC_ARRAY_LENGTH(i0, 0);
        i6 = (OOC_INT32)design;
        i7 = (OOC_INT32)b;
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(2, i2, OOC_UINT8, 205602))*4);
        i2 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(1, i4, OOC_UINT8, 205588))*4);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i5, OOC_UINT8, 205574))*4);
        i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i6, 205526));
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 205504)))), OOC_IR__BuilderDesc_NewMoveBlock)),OOC_IR__BuilderDesc_NewMoveBlock)((OOC_IR__Builder)i7, (OOC_Scanner_SymList__Symbol)i3, (OOC_IR__Expression)i0, (OOC_IR__Expression)i2, (OOC_IR__Expression)i1);
        return (OOC_IR__Expression)i0;
        goto l168;
      case 27:
        i0 = (OOC_INT32)arguments;
        i1 = _check_pointer(i0, 205664);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 205664))*4);
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 205667))+4);
        i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 205673)))), &_td_OOC_SymbolTable__PointerDesc);
        if (i1) goto l157;
        i1 = _check_pointer(i0, 205727);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 205727))*4);
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 205730))+4);
        i1 = OOC_SymbolTable_TypeRules__IsPredefType((OOC_SymbolTable__Type)i1, 12);
        
        goto l159;
l157:
        i1=1u;
l159:
        if (i1) goto l161;
        i0 = _check_pointer(i0, 206038);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 206038))*4);
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 206041));
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 206006)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i1, 50, (OOC_Scanner_SymList__Symbol)i0);
        goto l162;
l161:
        i0 = _check_pointer(i0, 205785);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 205785))*4);
        i1 = (OOC_INT32)b;
        OOC_IR__BuilderDesc_AssertVar((OOC_IR__Builder)i1, (OOC_IR__Expression)i0);
        i0 = (OOC_INT32)arguments;
        i1 = _check_pointer(i0, 205818);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 205818))*4);
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 205821))+4);
        type = (OOC_SymbolTable__Type)i1;
        i1 = _check_pointer(i0, 205975);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i0 = _check_pointer(i0, 205956);
        i3 = OOC_ARRAY_LENGTH(i0, 0);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i3, OOC_UINT8, 205956))*4);
        i3 = (OOC_INT32)design;
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 205959))+4);
        i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 205941));
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(1, i2, OOC_UINT8, 205975))*4);
        i2 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewNewBlock((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i4, (OOC_SymbolTable__Type)i0, (OOC_IR__Expression)i1);
        i1 = (OOC_INT32)arguments;
        i1 = _check_pointer(i1, 205899);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i4 = (OOC_INT32)b;
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 205899))*4);
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 205883));
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 205846)))), OOC_IR__BuilderDesc_NewAssignment)),OOC_IR__BuilderDesc_NewAssignment)((OOC_IR__Builder)i4, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i1, (OOC_IR__Expression)i0);
        return (OOC_IR__Expression)i0;
l162:
        i0 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 206077))+20);
        return (OOC_IR__Expression)i0;
        goto l168;
      case 24:
        i0 = (OOC_INT32)arguments;
        i0 = _check_pointer(i0, 206269);
        i1 = OOC_ARRAY_LENGTH(i0, 0);
        i2 = (OOC_INT32)design;
        i3 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 206269))*4);
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 206254));
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 206240)))), OOC_IR__BuilderDesc_NewAdr)),OOC_IR__BuilderDesc_NewAdr)((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i1, (OOC_IR__Expression)i0);
        i1 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(6);
        i2 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewTypeConv((OOC_IR__Builder)i2, (OOC_SymbolTable__Type)i1, (OOC_IR__Expression)i0);
        return (OOC_IR__Expression)i0;
        goto l168;
      case 25:
        i0 = (OOC_INT32)arguments;
        i1 = _check_pointer(i0, 206361);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i0 = _check_pointer(i0, 206347);
        i3 = OOC_ARRAY_LENGTH(i0, 0);
        i4 = (OOC_INT32)design;
        i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 206331));
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(1, i2, OOC_UINT8, 206361))*4);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i3, OOC_UINT8, 206347))*4);
        i2 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewShift((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i4, (OOC_IR__Expression)i0, (OOC_IR__Expression)i1, 0u);
        return (OOC_IR__Expression)i0;
        goto l168;
      case 29:
        i0 = (OOC_INT32)arguments;
        i1 = _check_pointer(i0, 206470);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i0 = _check_pointer(i0, 206456);
        i3 = OOC_ARRAY_LENGTH(i0, 0);
        i4 = (OOC_INT32)design;
        i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 206440));
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(1, i2, OOC_UINT8, 206470))*4);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i3, OOC_UINT8, 206456))*4);
        i2 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewTypeCast((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i4, (OOC_IR__Expression)i0, (OOC_IR__Expression)i1);
        return (OOC_IR__Expression)i0;
        goto l168;
      case 28:
        i0 = (OOC_INT32)arguments;
        i1 = _check_pointer(i0, 206569);
        i2 = OOC_ARRAY_LENGTH(i1, 0);
        i0 = _check_pointer(i0, 206555);
        i3 = OOC_ARRAY_LENGTH(i0, 0);
        i4 = (OOC_INT32)design;
        i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 206539));
        i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(1, i2, OOC_UINT8, 206569))*4);
        i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i3, OOC_UINT8, 206555))*4);
        i2 = (OOC_INT32)b;
        i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewShift((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i4, (OOC_IR__Expression)i0, (OOC_IR__Expression)i1, 1u);
        return (OOC_IR__Expression)i0;
        goto l168;
      default:
        _failed_case(i0, 196191);
        goto l168;
      }
l168:
      _failed_function(195747); return 0;
      ;
    }

    
    OOC_CHAR8 OOC_IR__BuilderDesc_NewCall_IsStatement(OOC_IR__Expression expr) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)expr;
      i1 = i0==(OOC_INT32)0;
      if (i1) goto l3;
      i1 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(17);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 206767))+4);
      i0 = i0==i1;
      
      goto l4;
l3:
      i0=1u;
l4:
      return i0;
      ;
    }


  i0 = (OOC_INT32)design;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 206852)))), &_td_OOC_IR__PredefProcDesc);
  if (i1) goto l51;
  i1 = (OOC_INT32)b;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 207571))+20);
  i2 = i0==i2;
  if (i2) goto l49;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 207711))+4);
  i2 = OOC_SymbolTable_TypeRules__IsValidReceiverType((OOC_SymbolTable__Type)i2);
  if (i2) goto l7;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 207741))+4);
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 207747)))), &_td_OOC_SymbolTable__TypeVarDesc);
  
  goto l9;
l7:
  i2=1u;
l9:
  if (i2) goto l11;
  i2=0u;
  goto l13;
l11:
  i2 = (OOC_INT32)arguments;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 207792)), 0);
  i2 = i2==1;
  
l13:
  if (i2) goto l15;
  i2=0u;
  goto l17;
l15:
  i2 = (OOC_INT32)arguments;
  i2 = _check_pointer(i2, 207812);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(0, i3, OOC_UINT8, 207812))*4);
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 207816)))), &_td_OOC_IR__TypeRefDesc);
  
l17:
  if (i2) goto l47;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 207972))+24);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 207963))+4);
  i2 = i3==i2;
  if (i2) goto l45;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 208071))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 208071))+4);
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 208076)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i3);
  i2 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 208087)))), &_td_OOC_SymbolTable__FormalParsDesc));
  if (i2) goto l43;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 208199))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 208199))+4);
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 208204)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i3);
  type = (OOC_SymbolTable__Type)i2;
  i3 = isFunctionCall;
  if (i3) goto l25;
  i4=0u;
  goto l27;
l25:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 208254)))), &_td_OOC_SymbolTable__FormalParsDesc, 208254)), 208265))+44);
  i4 = i4==0;
  
l27:
  if (i4) goto l41;
  i3 = !i3;
  if (i3) goto l31;
  i2=0u;
  goto l33;
l31:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 208396)))), &_td_OOC_SymbolTable__FormalParsDesc, 208396)), 208407))+44);
  i2 = i2!=0;
  
l33:
  if (i2) goto l39;
  call = (OOC_IR__Call)((OOC_INT32)RT0__NewObject(_td_OOC_IR__Call.baseTypes[0]));
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 208551)))), &_td_OOC_IR__SelectProcDesc);
  if (i1) goto l37;
  receiver = (OOC_IR__Expression)0;
  i1=0;
  goto l38;
l37:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 208602)))), &_td_OOC_IR__SelectProcDesc, 208602)), 208613))+8);
  receiver = (OOC_IR__Expression)i1;
  
l38:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 208740))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 208714));
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
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 208487));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 208449)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i1, 36, (OOC_Scanner_SymList__Symbol)i0);
  return (OOC_IR__Expression)i0;
  goto l70;
l41:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 208346));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 208307)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i1, 37, (OOC_Scanner_SymList__Symbol)i0);
  return (OOC_IR__Expression)i0;
  goto l70;
l43:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 208158));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 208127)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i1, 35, (OOC_Scanner_SymList__Symbol)i0);
  return (OOC_IR__Expression)i0;
  goto l70;
l45:
  i2 = (OOC_INT32)endOfArgsSym;
  i3 = (OOC_INT32)arguments;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 208004)))), OOC_IR__BuilderDesc_NewQualType)),OOC_IR__BuilderDesc_NewQualType)((OOC_IR__Builder)i1, (OOC_IR__Expression)i0, (OOC_IR__ExpressionList)i3, (OOC_Scanner_SymList__Symbol)i2);
  return (OOC_IR__Expression)i0;
  goto l70;
l47:
  i2 = (OOC_INT32)arguments;
  i3 = _check_pointer(i2, 207929);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(0, i4, OOC_UINT8, 207929))*4);
  i2 = _check_pointer(i2, 207872);
  i4 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(0, i4, OOC_UINT8, 207872))*4);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 207875));
  i0 = (OOC_INT32)OOC_IR__BuilderDesc_NewTypeGuard((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i0, (OOC_IR__TypeRef)(_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 207933)))), &_td_OOC_IR__TypeRefDesc, 207933)));
  return (OOC_IR__Expression)i0;
  goto l70;
l49:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 207605))+20);
  return (OOC_IR__Expression)i0;
  goto l70;
l51:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 206894))+8);
  i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 206905)))), &_td_OOC_SymbolTable__PredefProcDesc, 206905);
  predefProc = (OOC_SymbolTable__PredefProc)i0;
  i1 = *(OOC_INT16*)((_check_pointer(i0, 206983))+52);
  i0 = *(OOC_INT16*)((_check_pointer(i0, 206962))+50);
  i0 = OOC_IR__BuilderDesc_NewCall_CheckNumberOfArguments(i0, i1);
  i0 = !i0;
  if (!i0) goto l54;
  i0 = (OOC_INT32)b;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 207199))+20);
  return (OOC_IR__Expression)i0;
l54:
  i0 = (OOC_INT32)predefProc;
  i0 = *(OOC_INT16*)((_check_pointer(i0, 207271))+48);
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
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 207497));
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 207459)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i2, 36, (OOC_Scanner_SymList__Symbol)i1);
  return (OOC_IR__Expression)i1;
  goto l69;
l68:
  i1 = (OOC_INT32)design;
  i2 = (OOC_INT32)b;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 207381));
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 207342)))), OOC_IR__BuilderDesc_ErrExpr)),OOC_IR__BuilderDesc_ErrExpr)((OOC_IR__Builder)i2, 37, (OOC_Scanner_SymList__Symbol)i1);
  return (OOC_IR__Expression)i1;
l69:
  return (OOC_IR__Expression)i0;
l70:
  _failed_function(186249); return 0;
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

/* --- */
