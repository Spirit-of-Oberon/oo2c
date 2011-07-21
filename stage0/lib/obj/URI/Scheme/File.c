#include <URI/Scheme/File.d>
#include <__oo2c.h>
#include <setjmp.h>

void URI_Scheme_File__Init(URI_Scheme_File__URI file, Object__String schemeId, URI__Authority authority, URI__Query query) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)query;
  i1 = (OOC_INT32)authority;
  i2 = (OOC_INT32)schemeId;
  i3 = (OOC_INT32)file;
  URI_Scheme_Hierarchical__Init((URI_Scheme_Hierarchical__Generic)i3, (Object__String)i2, (URI__Authority)i1, (URI__Query)i0);
  return;
  ;
}

URI_Scheme_File__URI URI_Scheme_File__New(Object__String schemeId, URI__Authority authority, URI__Query query) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)RT0__NewObject(_td_URI_Scheme_File__URI.baseTypes[0]);
  i1 = (OOC_INT32)query;
  i2 = (OOC_INT32)authority;
  i3 = (OOC_INT32)schemeId;
  URI_Scheme_File__Init((URI_Scheme_File__URI)i0, (Object__String)i3, (URI__Authority)i2, (URI__Query)i1);
  return (URI_Scheme_File__URI)i0;
  ;
}

URI__Authority URI_Scheme_File__URIDesc_NewAuthority(URI_Scheme_File__URI file) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)URI_Authority_ServerBased__New((Object__String)(OOC_INT32)0, (Object__String)((OOC_INT32)_c0), (-1), (-1));
  return (URI__Authority)i0;
  ;
}

OOC_CHAR8 URI_Scheme_File__URIDesc_AuthorityMandatory(URI_Scheme_File__URI file) {

  return 1u;
  ;
}

URI__Query URI_Scheme_File__URIDesc_NewQuery(URI_Scheme_File__URI file) {

  return (URI__Query)(OOC_INT32)0;
  ;
}

URI_Scheme_File__URI URI_Scheme_File__URIDesc_Clone(URI_Scheme_File__URI file) {
  register OOC_INT32 i0,i1;
  URI_Scheme_File__URI copy;

  i0 = (OOC_INT32)RT0__NewObject(_td_URI_Scheme_File__URI.baseTypes[0]);
  copy = (URI_Scheme_File__URI)i0;
  i1 = (OOC_INT32)file;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2207)))), URI_Scheme_Hierarchical__GenericDesc_Copy)),URI_Scheme_Hierarchical__GenericDesc_Copy)((URI_Scheme_Hierarchical__Generic)i1, (URI__URI)i0);
  return (URI_Scheme_File__URI)i0;
  ;
}

Object__String8 URI_Scheme_File__URIDesc_GetPath(URI_Scheme_File__URI file) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  ADT_StringBuffer__StringBuffer sb;
  URI_Scheme_Hierarchical__Segment segm;
  Object__String str;

  i0 = (OOC_INT32)ADT_StringBuffer__New((Object__String)((OOC_INT32)_c1));
  sb = (ADT_StringBuffer__StringBuffer)i0;
  i1 = (OOC_INT32)file;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2586))+12);
  segm = (URI_Scheme_Hierarchical__Segment)i2;
  i3 = i2!=(OOC_INT32)0;
  if (!i3) goto l15;
  i3 = (OOC_INT32)_c2;
  
l3_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2645))+12);
  i4 = i2!=i4;
  if (i4) goto l6;
  i4 = *(OOC_UINT8*)((_check_pointer(i1, 2664))+16);
  
  goto l8;
l6:
  i4=1u;
l8:
  if (!i4) goto l10;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2694)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i3);
l10:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 2739))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2727)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i4);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 2767));
  segm = (URI_Scheme_Hierarchical__Segment)i2;
  i4 = i2!=(OOC_INT32)0;
  if (i4) goto l3_loop;
l15:
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2822)))), ADT_StringBuffer__StringBufferDesc_ToString)),ADT_StringBuffer__StringBufferDesc_ToString)((ADT_StringBuffer__StringBuffer)i0);
  i0 = (OOC_INT32)OS_HostPath__Denormalize((Object__String)i0);
  str = (Object__String)i0;
  return (Object__String8)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2858)))), &_td_Object__String8Desc, 2858));
  ;
}

IO__ByteChannel URI_Scheme_File__URIDesc_GetChannel(URI_Scheme_File__URI file, OOC_INT8 mode) {
  register OOC_INT32 i0,i1;
  Object__String s;

  i0 = (OOC_INT32)file;
  i0 = (OOC_INT32)URI_Scheme_File__URIDesc_GetPath((URI_Scheme_File__URI)i0);
  s = (Object__String)i0;
  i1 = mode;
  switch (i1) {
  case 0:
    i0 = (OOC_INT32)IO_FileChannel__Open((Object__String)i0, 23u);
    return (IO__ByteChannel)i0;
    goto l6;
  case 1:
    i0 = (OOC_INT32)IO_FileChannel__Open((Object__String)i0, 67u);
    return (IO__ByteChannel)i0;
    goto l6;
  case 2:
    i0 = (OOC_INT32)IO_FileChannel__Open((Object__String)i0, 1u);
    return (IO__ByteChannel)i0;
    goto l6;
  default:
    _failed_case(i1, 3034);
    goto l6;
  }
l6:
  _failed_function(2906); return 0;
  ;
}

URI_Scheme_File__URI URI_Scheme_File__NewPrototype(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)URI_Scheme_File__New((Object__String)((OOC_INT32)_c3), (URI__Authority)(OOC_INT32)0, (URI__Query)(OOC_INT32)0);
  return (URI_Scheme_File__URI)i0;
  ;
}

URI_Scheme_File__URI URI_Scheme_File__GetCwd(void) {
  register OOC_INT32 i0,i1;
  volatile Object__String cwd;
  volatile ADT_StringBuffer__StringBuffer uriString;
  volatile Object__String str;
  volatile URI__URI uri;
  jmp_buf _target0, _target1;
  Exception__Context _context0, _context1;

  {
    Exception__PushContext(&_context0, &_target0);
    if (!setjmp(_target0)) goto l7;
    Exception__PopContext(1);
    i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG(((OOC_INT32)Exception__Current()))), &_td_IO__ErrorDesc);
    if (i0) goto l5;
    Exception__ActivateContext();
    goto l6;
l5:
    return (URI_Scheme_File__URI)(OOC_INT32)0;
l6:
    Exception__Clear();
    goto l19;
l7:
    i0 = (OOC_INT32)OS_ProcessParameters__GetCwd();
    i0 = (OOC_INT32)OS_HostPath__Normalize((Object__String)i0);
    cwd = (Object__String)i0;
    i1 = (OOC_INT32)ADT_StringBuffer__New((Object__String)((OOC_INT32)_c4));
    uriString = (ADT_StringBuffer__StringBuffer)i1;
    URI_String__AppendEscaped((Object__String)i0, (OOC_CHAR8*)":@&=+$,/", 9, (ADT_StringBuffer__StringBuffer)i1);
    i0 = *(OOC_INT32*)((_check_pointer(i1, 4260))+4);
    i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4243)))), ADT_StringBuffer__StringBufferDesc_CharAt)),ADT_StringBuffer__StringBufferDesc_CharAt)((ADT_StringBuffer__StringBuffer)i1, (i0-1));
    i0 = i0!=47u;
    if (!i0) goto l10;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4300)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i1, (Object__Object)((OOC_INT32)_c5));
l10:
    i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4348)))), ADT_StringBuffer__StringBufferDesc_ToString)),ADT_StringBuffer__StringBufferDesc_ToString)((ADT_StringBuffer__StringBuffer)i1);
    str = (Object__String)i0;
    {
      Exception__PushContext(&_context1, &_target1);
      if (!setjmp(_target1)) goto l17;
      Exception__PopContext(1);
      i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG(((OOC_INT32)Exception__Current()))), &_td_Exception__ParseErrorDesc);
      if (i0) goto l15;
      Exception__ActivateContext();
      goto l16;
l15:
      _assert(0u, 127, 4494);
l16:
      Exception__Clear();
      goto l18;
l17:
      i0 = (OOC_INT32)URI_Parser__NewURI((Object__String8)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4411)))), &_td_Object__String8Desc, 4411)), (URI__HierarchicalURI)(OOC_INT32)0);
      uri = (URI__URI)i0;
      Exception__PopContext(2);
      return (URI_Scheme_File__URI)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4446)))), &_td_URI_Scheme_File__URIDesc, 4446));
      Exception__PopContext(1);
l18:;
    }
    Exception__PopContext(1);
l19:;
  }
  _failed_function(3633); return 0;
  ;
}

URI_Scheme_File__URI URI_Scheme_File__ToURI(const OOC_CHAR8 filePath__ref[], volatile OOC_LEN filePath_0d) {
  register OOC_INT32 i0,i1;
  OOC_ALLOCATE_VPAR(filePath,OOC_CHAR8 ,filePath_0d)
  volatile Object__String normPath;
  volatile ADT_StringBuffer__StringBuffer uriString;
  volatile Object__String str;
  volatile URI__URI uri;
  jmp_buf _target0;
  Exception__Context _context0;

  OOC_INITIALIZE_VPAR(filePath__ref,filePath,OOC_CHAR8 ,filePath_0d)
  {
    Exception__PushContext(&_context0, &_target0);
    if (!setjmp(_target0)) goto l11;
    Exception__PopContext(1);
    i0 = (OOC_INT32)OOC_TYPE_TAG(((OOC_INT32)Exception__Current()));
    i1 = OOC_TYPE_TEST(i0, &_td_IO__ErrorDesc);
    if (i1) goto l9;
    i0 = OOC_TYPE_TEST(i0, &_td_Exception__ParseErrorDesc);
    if (i0) goto l7;
    Exception__ActivateContext();
    goto l10;
l7:
    return (URI_Scheme_File__URI)(OOC_INT32)0;
    goto l10;
l9:
    return (URI_Scheme_File__URI)(OOC_INT32)0;
l10:
    Exception__Clear();
    goto l16;
l11:
    i0 = (OOC_INT32)Object__NewLatin1((void*)(OOC_INT32)filePath, filePath_0d);
    i0 = (OOC_INT32)OS_HostPath__Normalize((Object__String)i0);
    normPath = (Object__String)i0;
    i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4965)))), Object__StringDesc_CharAt)),Object__StringDesc_CharAt)((Object__String)i0, 0);
    i1 = i1==47u;
    if (i1) goto l14;
    i1 = (OOC_INT32)ADT_StringBuffer__New((Object__String)((OOC_INT32)_c6));
    uriString = (ADT_StringBuffer__StringBuffer)i1;
    URI_String__AppendEscaped((Object__String)i0, (OOC_CHAR8*)"@&=+$,/", 8, (ADT_StringBuffer__StringBuffer)i1);
    i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5374)))), ADT_StringBuffer__StringBufferDesc_ToString)),ADT_StringBuffer__StringBufferDesc_ToString)((ADT_StringBuffer__StringBuffer)i1);
    str = (Object__String)i0;
    i1 = (OOC_INT32)URI_Scheme_File__GetCwd();
    i0 = (OOC_INT32)URI_Parser__NewURI((Object__String8)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5428)))), &_td_Object__String8Desc, 5428)), (URI__HierarchicalURI)i1);
    uri = (URI__URI)i0;
    
    goto l15;
l14:
    i1 = (OOC_INT32)ADT_StringBuffer__New((Object__String)((OOC_INT32)_c7));
    uriString = (ADT_StringBuffer__StringBuffer)i1;
    URI_String__AppendEscaped((Object__String)i0, (OOC_CHAR8*)":@&=+$,/", 9, (ADT_StringBuffer__StringBuffer)i1);
    i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5145)))), ADT_StringBuffer__StringBufferDesc_ToString)),ADT_StringBuffer__StringBufferDesc_ToString)((ADT_StringBuffer__StringBuffer)i1);
    str = (Object__String)i0;
    i0 = (OOC_INT32)URI_Parser__NewURI((Object__String8)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5199)))), &_td_Object__String8Desc, 5199)), (URI__HierarchicalURI)(OOC_INT32)0);
    uri = (URI__URI)i0;
    
l15:
    Exception__PopContext(1);
    return (URI_Scheme_File__URI)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5476)))), &_td_URI_Scheme_File__URIDesc, 5476));
    Exception__PopContext(1);
l16:;
  }
  _failed_function(4592); return 0;
  ;
}

void OOC_URI_Scheme_File_init(void) {
  _c0 = Object__NewLatin1Region((OOC_CHAR8*)"", 1, 0, 0);
  _c1 = Object__NewLatin1Region((OOC_CHAR8*)"", 1, 0, 0);
  _c2 = Object__NewLatin1Char(47u);
  _c3 = Object__NewLatin1Region((OOC_CHAR8*)"file", 5, 0, 4);
  _c4 = Object__NewLatin1Region((OOC_CHAR8*)"file://", 8, 0, 7);
  _c5 = Object__NewLatin1Char(47u);
  _c6 = Object__NewLatin1Region((OOC_CHAR8*)"", 1, 0, 0);
  _c7 = Object__NewLatin1Region((OOC_CHAR8*)"file://", 8, 0, 7);

  return;
  ;
}

void OOC_URI_Scheme_File_destroy(void) {
}

/* --- */
