#include <XML/EntityResolver.d>
#include <__oo2c.h>
#include <setjmp.h>

XML_DTD__StringURI XML_EntityResolver__NormalizeURI(XML_UnicodeBuffer__CharArray uri) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT16 len16;
  XML_UnicodeCodec__Codec codec;
  OOC_CHAR8 str8[8192];
  OOC_INT32 srcDone;
  OOC_INT32 destDone;
  OOC_INT16 i;
  OOC_CHAR8 repl[4];
  auto OOC_CHAR8 XML_EntityResolver__NormalizeURI_ToHex(OOC_INT16 i);
    
    OOC_CHAR8 XML_EntityResolver__NormalizeURI_ToHex(OOC_INT16 i) {
      register OOC_INT32 i0,i1;

      i0 = i;
      i1 = i0<10;
      if (i1) goto l3;
      return (i0+55);
      goto l4;
l3:
      return (i0+48);
l4:
      _failed_function(1803); return 0;
      ;
    }


  i0 = (OOC_INT32)uri;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 2014)), 0);
  i1 = LongStrings__Length((void*)(_check_pointer(i0, 2014)), i1);
  len16 = i1;
  i2 = (OOC_INT32)XML_UnicodeCodec_UTF8__factory;
  i2 = (OOC_INT32)XML_UnicodeCodec_UTF8__FactoryDesc_NewCodec((XML_UnicodeCodec_UTF8__Factory)i2);
  codec = (XML_UnicodeCodec__Codec)i2;
  i3 = i1!=0;
  if (i3) goto l3;
  _copy_8((const void*)"",(void*)(OOC_INT32)str8,8192);
  goto l7;
l3:
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i0, 2176)), 0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 2163)))), XML_UnicodeCodec__CodecDesc_Encode)),XML_UnicodeCodec__CodecDesc_Encode)((XML_UnicodeCodec__Codec)i2, (void*)(_check_pointer(i0, 2176)), i3, 0, i1, (void*)(OOC_INT32)str8, 8192, 0, 8192, (void*)(OOC_INT32)&srcDone, (void*)(OOC_INT32)&destDone);
  i3 = srcDone;
  i4 = i3!=i1;
  if (!i4) goto l6;
  i4 = OOC_ARRAY_LENGTH((_check_pointer(i0, 2288)), 0);
  i5 = destDone;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 2275)))), XML_UnicodeCodec__CodecDesc_Encode)),XML_UnicodeCodec__CodecDesc_Encode)((XML_UnicodeCodec__Codec)i2, (void*)(_check_pointer(i0, 2288)), i4, i3, i1, (void*)(OOC_INT32)str8, 8192, i5, 8192, (void*)(OOC_INT32)&srcDone, (void*)(OOC_INT32)&destDone);
  i0 = srcDone;
  _assert((i0==i1), 127, 2386);
l6:
  i0 = destDone;
  *(OOC_UINT8*)((OOC_INT32)str8+(_check_index(i0, 8192, OOC_UINT32, 2432))) = 0u;
l7:
  i = 0;
  i0 = *(OOC_UINT8*)((OOC_INT32)str8+(_check_index(0, 8192, OOC_UINT16, 2620)));
  i0 = i0!=0u;
  if (i0) goto l10;
  i0=0;
  goto l36;
l10:
  i0=0;
l11_loop:
  i1 = *(OOC_UINT8*)((OOC_INT32)str8+(_check_index(i0, 8192, OOC_UINT16, 2647)));
  i1 = (OOC_UINT8)i1>=(OOC_UINT8)128u;
  if (i1) goto l26;
  i1 = *(OOC_UINT8*)((OOC_INT32)str8+(_check_index(i0, 8192, OOC_UINT16, 2699)));
  i1 = URI_CharClass__IsReserved(i1);
  if (i1) goto l16;
  i1 = *(OOC_UINT8*)((OOC_INT32)str8+(_check_index(i0, 8192, OOC_UINT16, 2746)));
  i1 = URI_CharClass__IsUnreserved(i1);
  
  goto l18;
l16:
  i1=1u;
l18:
  if (i1) goto l20;
  i1 = *(OOC_UINT8*)((OOC_INT32)str8+(_check_index(i0, 8192, OOC_UINT16, 2770)));
  i1 = i1==35u;
  
  goto l22;
l20:
  i1=1u;
l22:
  if (i1) goto l24;
  i1 = *(OOC_UINT8*)((OOC_INT32)str8+(_check_index(i0, 8192, OOC_UINT16, 2800)));
  i1 = i1==37u;
  
  goto l25;
l24:
  i1=1u;
l25:
  i1 = !i1;
  
  goto l28;
l26:
  i1=1u;
l28:
  if (i1) goto l30;
  i0 = i0+1;
  i = i0;
  
  goto l31;
l30:
  _copy_8((const void*)"%HH",(void*)(OOC_INT32)repl,4);
  i1 = *(OOC_UINT8*)((OOC_INT32)str8+(_check_index(i0, 8192, OOC_UINT16, 2875)));
  i1 = XML_EntityResolver__NormalizeURI_ToHex((i1>>4));
  *(OOC_UINT8*)((OOC_INT32)repl+(_check_index(1, 4, OOC_UINT8, 2852))) = i1;
  i1 = *(OOC_UINT8*)((OOC_INT32)str8+(_check_index(i0, 8192, OOC_UINT16, 2924)));
  i1 = XML_EntityResolver__NormalizeURI_ToHex((_mod(i1,16)));
  *(OOC_UINT8*)((OOC_INT32)repl+(_check_index(2, 4, OOC_UINT8, 2901))) = i1;
  Strings__Delete((void*)(OOC_INT32)str8, 8192, i0, 1);
  Strings__Insert((void*)(OOC_INT32)repl, 4, i0, (void*)(OOC_INT32)str8, 8192);
  i0 = i0+3;
  i = i0;
  
l31:
  i1 = *(OOC_UINT8*)((OOC_INT32)str8+(_check_index(i0, 8192, OOC_UINT16, 2620)));
  i1 = i1!=0u;
  if (i1) goto l11_loop;
l36:
  i0 = (OOC_INT32)XML_DTD__GetStringURI((void*)(OOC_INT32)str8, 8192, 0, i0);
  return (XML_DTD__StringURI)i0;
  ;
}

void XML_EntityResolver__ResolverDesc_GetURI(volatile XML_EntityResolver__Resolver r, volatile XML_UnicodeBuffer__CharArray _public, volatile XML_UnicodeBuffer__CharArray system, volatile URI__URI baseURI, volatile URI__URI *uri, volatile Msg__Msg *res) {
  register OOC_INT32 i0,i1,i2;
  volatile XML_DTD__StringURI str8;
  volatile Msg__Msg err;
  volatile Exception__Exception e;
  volatile Object__String str;
  volatile Object__CharsLatin1 chars;
  jmp_buf _target0;
  Exception__Context _context0;

  i0 = (OOC_INT32)system;
  i1 = i0==(OOC_INT32)0;
  if (!i1) goto l3;
  *uri = (URI__URI)(OOC_INT32)0;
  *res = (Msg__Msg)(OOC_INT32)0;
  return;
l3:
  i0 = (OOC_INT32)XML_EntityResolver__NormalizeURI((XML_UnicodeBuffer__CharArray)i0);
  str8 = (XML_DTD__StringURI)i0;
  {
    Exception__PushContext(&_context0, &_target0);
    if (!setjmp(_target0)) goto l10;
    Exception__PopContext(1);
    i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG(((OOC_INT32)Exception__Current()))), &_td_Exception__ParseErrorDesc);
    if (i0) goto l8;
    Exception__ActivateContext();
    goto l9;
l8:
    i0 = (OOC_INT32)XML_EntityResolver__resolverContext;
    i0 = (OOC_INT32)XML_Error__New((XML_Error__Context)i0, 1);
    err = (Msg__Msg)i0;
    i1 = (OOC_INT32)Exception__Current();
    e = (Exception__Exception)i1;
    i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4539)))), Exception__ExceptionDesc_GetMessage)),Exception__ExceptionDesc_GetMessage)((Exception__Exception)i1);
    str = (Object__String)i1;
    i1 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4580)))), &_td_Object__String8Desc, 4580)));
    chars = (Object__CharsLatin1)i1;
    i2 = OOC_ARRAY_LENGTH((_check_pointer(i1, 4662)), 0);
    i1 = (OOC_INT32)Msg__GetStringPtr((void*)(_check_pointer(i1, 4662)), i2);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4613)))), Msg__MsgDesc_SetStringAttrib)),Msg__MsgDesc_SetStringAttrib)((Msg__Msg)i0, "reason", 7, (Msg__StringPtr)i1);
    *res = (Msg__Msg)i0;
l9:
    Exception__Clear();
    goto l19;
l10:
    i1 = (OOC_INT32)baseURI;
    i2 = i1!=(OOC_INT32)0;
    if (i2) goto l13;
    i2=0u;
    goto l15;
l13:
    i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4218)))), &_td_URI__HierarchicalURIDesc);
    
l15:
    if (i2) goto l17;
    i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 4370)), 0);
    i0 = (OOC_INT32)URI_Parser__NewURILatin1((void*)(_check_pointer(i0, 4370)), i1, (URI__HierarchicalURI)(OOC_INT32)0);
    *uri = (URI__URI)i0;
    goto l18;
l17:
    i2 = OOC_ARRAY_LENGTH((_check_pointer(i0, 4286)), 0);
    i0 = (OOC_INT32)URI_Parser__NewURILatin1((void*)(_check_pointer(i0, 4286)), i2, (URI__HierarchicalURI)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4301)))), &_td_URI__HierarchicalURIDesc, 4301)));
    *uri = (URI__URI)i0;
l18:
    *res = (Msg__Msg)(OOC_INT32)0;
    Exception__PopContext(1);
l19:;
  }
  return;
  ;
}

XML_EntityResolver__Resolver XML_EntityResolver__New(void) {

  return (XML_EntityResolver__Resolver)((OOC_INT32)RT0__NewObject(_td_XML_EntityResolver__Resolver.baseTypes[0]));
  ;
}

void OOC_XML_EntityResolver_init(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)XML_Error__NewContext("XML:EntityResolver", 19);
  XML_EntityResolver__resolverContext = (XML_Error__Context)i0;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4896)))), XML_Error__ContextDesc_SetString)),XML_Error__ContextDesc_SetString)((XML_Error__Context)i0, 1, "Invalid URI: ${reason}", 23);
  return;
  ;
}

/* --- */
