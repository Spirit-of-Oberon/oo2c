#include <XML/Error.d>
#include <__oo2c.h>
#include <setjmp.h>

void XML_Error__InitContext(XML_Error__Context c, const Msg__String id__ref, OOC_LEN id_0d) {
  register OOC_INT32 i0;
  OOC_ALLOCATE_VPAR(id,OOC_CHAR8 ,id_0d)

  OOC_INITIALIZE_VPAR(id__ref,id,OOC_CHAR8 ,id_0d)
  i0 = (OOC_INT32)c;
  Msg__InitContext((Msg__Context)i0, (void*)(OOC_INT32)id, id_0d);
  *(OOC_INT32*)((_check_pointer(i0, 2272))+4) = (OOC_INT32)0;
  return;
  ;
}

XML_Error__Context XML_Error__NewContext(const Msg__String id__ref, OOC_LEN id_0d) {
  register OOC_INT32 i0;
  OOC_ALLOCATE_VPAR(id,OOC_CHAR8 ,id_0d)

  OOC_INITIALIZE_VPAR(id__ref,id,OOC_CHAR8 ,id_0d)
  i0 = (OOC_INT32)RT0__NewObject(_td_XML_Error__Context.baseTypes[0]);
  XML_Error__InitContext((XML_Error__Context)i0, (void*)(OOC_INT32)id, id_0d);
  return (XML_Error__Context)i0;
  ;
}

void XML_Error__ContextDesc_WriteTemplate(XML_Error__Context context, Msg__Msg msg, const Msg__LString msgText__ref, OOC_LEN msgText_0d, Msg__LString templ, OOC_LEN templ_0d) {
  register OOC_INT32 i0,i1;
  OOC_ALLOCATE_VPAR(msgText,OOC_CHAR16 ,msgText_0d)
  Msg__Attribute entityName;

  OOC_INITIALIZE_VPAR(msgText__ref,msgText,OOC_CHAR16 ,(msgText_0d*2))
  i0 = (OOC_INT32)msg;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2751)))), Msg__MsgDesc_GetAttribute)),Msg__MsgDesc_GetAttribute)((Msg__Msg)i0, "entity_name", 12);
  entityName = (Msg__Attribute)i0;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l3;
  _copy_16((const void*)((OOC_CHAR16[]){87,104,105,108,101,32,101,120,112,97,110,100,105,110,103,32,101,110,116,105,116,121,32,96,0}),(void*)(OOC_INT32)templ,templ_0d);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2933)))), &_td_Msg__LStringAttributeDesc, 2933)), 2950))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2933)))), &_td_Msg__LStringAttributeDesc, 2933)), 2950))+8);
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 2958)), 0);
  LongStrings__Append((void*)(_check_pointer(i1, 2958)), i0, (void*)(OOC_INT32)templ, templ_0d);
  LongStrings__Append(((OOC_CHAR16[]){39,58,32,0}), 4, (void*)(OOC_INT32)templ, templ_0d);
  goto l4;
l3:
  _copy_16((const void*)((OOC_CHAR16[]){0}),(void*)(OOC_INT32)templ,templ_0d);
l4:
  LongStrings__Append((void*)(OOC_INT32)msgText, msgText_0d, (void*)(OOC_INT32)templ, templ_0d);
  LongStrings__Insert(((OOC_CHAR16[]){108,105,110,101,61,36,123,108,105,110,101,125,44,32,99,111,108,117,109,110,61,36,123,99,111,108,117,109,110,125,10,36,123,99,104,97,114,125,58,32,0}), 41, 0, (void*)(OOC_INT32)templ, templ_0d);
  return;
  ;
}

void XML_Error__ContextDesc_GetTemplate(XML_Error__Context context, Msg__Msg msg, Msg__LString templ, OOC_LEN templ_0d) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  XML_Error__Mapping m;

  i0 = (OOC_INT32)context;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3316))+4);
  m = (XML_Error__Mapping)i1;
  i2 = i1!=(OOC_INT32)0;
  if (i2) goto l3;
  i2=0u;
  goto l5;
l3:
  i2 = (OOC_INT32)msg;
  i3 = *(OOC_INT32*)((_check_pointer(i1, 3351))+4);
  i2 = *(OOC_INT32*)((_check_pointer(i2, 3363))+8);
  i2 = i3!=i2;
  
l5:
  if (!i2) goto l17;
  i2 = (OOC_INT32)msg;
  
l8_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 3386));
  m = (XML_Error__Mapping)i1;
  i3 = i1!=(OOC_INT32)0;
  if (i3) goto l11;
  i3=0u;
  goto l13;
l11:
  i3 = *(OOC_INT32*)((_check_pointer(i1, 3351))+4);
  i4 = *(OOC_INT32*)((_check_pointer(i2, 3363))+8);
  i3 = i3!=i4;
  
l13:
  if (i3) goto l8_loop;
l17:
  i2 = i1!=(OOC_INT32)0;
  if (i2) goto l20;
  i1 = (OOC_INT32)msg;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3498)))), XML_Error__ContextDesc_WriteTemplate)),XML_Error__ContextDesc_WriteTemplate)((XML_Error__Context)i0, (Msg__Msg)i1, ((OOC_CHAR16[]){45,45,117,110,107,110,111,119,110,32,101,114,114,111,114,32,99,111,100,101,59,32,109,115,103,95,99,111,110,116,101,120,116,61,36,123,77,83,71,95,67,79,78,84,69,88,84,125,59,32,109,115,103,95,99,111,100,101,61,36,123,77,83,71,95,67,79,68,69,125,45,45,0}), 73, (void*)(OOC_INT32)templ, templ_0d);
  goto l21;
l20:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3460))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3460))+8);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 3466)), 0);
  i3 = (OOC_INT32)msg;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3437)))), XML_Error__ContextDesc_WriteTemplate)),XML_Error__ContextDesc_WriteTemplate)((XML_Error__Context)i0, (Msg__Msg)i3, (void*)(_check_pointer(i2, 3466)), i1, (void*)(OOC_INT32)templ, templ_0d);
l21:
  return;
  ;
}

void XML_Error__ContextDesc_SetString(XML_Error__Context context, OOC_INT32 code, const Msg__String str__ref, OOC_LEN str_0d) {
  register OOC_INT32 i0;
  OOC_ALLOCATE_VPAR(str,OOC_CHAR8 ,str_0d)
  auto void XML_Error__ContextDesc_SetString_Append(XML_Error__Mapping *mlist);
    
    void XML_Error__ContextDesc_SetString_Append(XML_Error__Mapping *mlist) {
      register OOC_INT32 i0,i1,i2;
      OOC_CHAR16 str16[1024];

      i0 = (OOC_INT32)*mlist;
      i1 = i0==(OOC_INT32)0;
      if (i1) goto l7;
      i1 = *(OOC_INT32*)((_check_pointer(i0, 4142))+4);
      i2 = code;
      i1 = i1==i2;
      if (i1) goto l5;
      XML_Error__ContextDesc_SetString_Append((void*)(_check_pointer(i0, 4268)));
      goto l8;
l5:
      _copy_8to16((const void*)(OOC_INT32)str,(void*)(OOC_INT32)str16,1024);
      i1 = (OOC_INT32)Msg__GetLStringPtr((void*)(OOC_INT32)str16, 1024);
      *(OOC_INT32*)((_check_pointer(i0, 4202))+8) = i1;
      goto l8;
l7:
      i0 = (OOC_INT32)RT0__NewObject(_td_XML_Error__Mapping.baseTypes[0]);
      *mlist = (XML_Error__Mapping)i0;
      *(OOC_INT32*)(_check_pointer(i0, 4006)) = (OOC_INT32)0;
      i0 = (OOC_INT32)*mlist;
      i1 = code;
      *(OOC_INT32*)((_check_pointer(i0, 4034))+4) = i1;
      _copy_8to16((const void*)(OOC_INT32)str,(void*)(OOC_INT32)str16,1024);
      i0 = (OOC_INT32)*mlist;
      i1 = (OOC_INT32)Msg__GetLStringPtr((void*)(OOC_INT32)str16, 1024);
      *(OOC_INT32*)((_check_pointer(i0, 4090))+8) = i1;
l8:
      return;
      ;
    }


  OOC_INITIALIZE_VPAR(str__ref,str,OOC_CHAR8 ,str_0d)
  i0 = (OOC_INT32)context;
  XML_Error__ContextDesc_SetString_Append((void*)((_check_pointer(i0, 4332))+4));
  return;
  ;
}

Msg__Msg XML_Error__New(XML_Error__Context context, OOC_INT32 code) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)context;
  i1 = code;
  i0 = (OOC_INT32)Msg__New((Msg__Context)i0, i1);
  return (Msg__Msg)i0;
  ;
}

XML_Error__List XML_Error__NewList(void) {
  register OOC_INT32 i0,i1;
  XML_Error__List list;

  i0 = (OOC_INT32)RT0__NewObject(_td_XML_Error__List.baseTypes[0]);
  list = (XML_Error__List)i0;
  Msg__InitMsgList((Msg__MsgList)i0);
  i1 = (OOC_INT32)URI_Scheme_File__GetCwd();
  *(OOC_INT32*)((_check_pointer(i0, 4605))+12) = i1;
  return (XML_Error__List)i0;
  ;
}

void XML_Error__ListDesc_Write(volatile XML_Error__List errList, volatile Channel__Channel ch) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  volatile TextRider__Writer writer;
  volatile OOC_CHAR8 repl1[1024];
  volatile OOC_CHAR8 repl2[1024];
  volatile Msg__Msg prev;
  volatile Msg__StringPtr prevURI;
  volatile Msg__Msg msg;
  volatile Msg__Attribute uriAttr;
  volatile Msg__StringPtr uri;
  volatile OOC_CHAR8 text[8192];
  volatile Object__String cwd;
  volatile OOC_INT32 len;
  auto void XML_Error__ListDesc_Write_Replace(OOC_CHAR8 text[], OOC_LEN text_0d, const OOC_CHAR8 pattern__ref[], OOC_LEN pattern_0d, const OOC_CHAR8 repl__ref[], OOC_LEN repl_0d);
  auto OOC_CHAR8 XML_Error__ListDesc_Write_DistanceOk(Msg__Msg m0, Msg__Msg m1);
  auto void XML_Error__ListDesc_Write_Copy(Object__String s, OOC_CHAR8 str[], OOC_LEN str_0d);
  jmp_buf _target0;
  Exception__Context _context0;
    
    void XML_Error__ListDesc_Write_Replace(OOC_CHAR8 text[], OOC_LEN text_0d, const OOC_CHAR8 pattern__ref[], OOC_LEN pattern_0d, const OOC_CHAR8 repl__ref[], OOC_LEN repl_0d) {
      register OOC_INT32 i0,i1;
      OOC_ALLOCATE_VPAR(pattern,OOC_CHAR8 ,pattern_0d)
      OOC_ALLOCATE_VPAR(repl,OOC_CHAR8 ,repl_0d)
      OOC_CHAR8 found;
      OOC_INT16 pos;

      OOC_INITIALIZE_VPAR(pattern__ref,pattern,OOC_CHAR8 ,pattern_0d)
      OOC_INITIALIZE_VPAR(repl__ref,repl,OOC_CHAR8 ,repl_0d)
      Strings__FindNext((void*)(OOC_INT32)pattern, pattern_0d, (void*)(OOC_INT32)text, text_0d, 0, (void*)(OOC_INT32)&found, (void*)(OOC_INT32)&pos);
      i0 = found;
      if (!i0) goto l8;
l3_loop:
      i0 = Strings__Length((void*)(OOC_INT32)pattern, pattern_0d);
      i1 = pos;
      Strings__Delete((void*)(OOC_INT32)text, text_0d, i1, i0);
      i0 = pos;
      Strings__Insert((void*)(OOC_INT32)repl, repl_0d, i0, (void*)(OOC_INT32)text, text_0d);
      i0 = Strings__Length((void*)(OOC_INT32)repl, repl_0d);
      i1 = pos;
      i0 = i1+i0;
      pos = i0;
      Strings__FindNext((void*)(OOC_INT32)pattern, pattern_0d, (void*)(OOC_INT32)text, text_0d, i0, (void*)(OOC_INT32)&found, (void*)(OOC_INT32)&pos);
      i0 = found;
      if (i0) goto l3_loop;
l8:
      return;
      ;
    }

    
    OOC_CHAR8 XML_Error__ListDesc_Write_DistanceOk(Msg__Msg m0, Msg__Msg m1) {
      register OOC_INT32 i0,i1,i2;
      Msg__Attribute p0;
      Msg__Attribute p1;

      i0 = (OOC_INT32)m0;
      i1 = i0==(OOC_INT32)0;
      if (i1) goto l23;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5881)))), Msg__MsgDesc_GetAttribute)),Msg__MsgDesc_GetAttribute)((Msg__Msg)i0, "char", 5);
      p0 = (Msg__Attribute)i0;
      i1 = (OOC_INT32)m1;
      i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5922)))), Msg__MsgDesc_GetAttribute)),Msg__MsgDesc_GetAttribute)((Msg__Msg)i1, "char", 5);
      p1 = (Msg__Attribute)i1;
      i2 = i0!=(OOC_INT32)0;
      if (i2) goto l5;
      i2=0u;
      goto l7;
l5:
      i2 = i1!=(OOC_INT32)0;
      
l7:
      if (i2) goto l9;
      i2=0u;
      goto l11;
l9:
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5999)))), &_td_Msg__IntAttributeDesc);
      
l11:
      if (i2) goto l13;
      i2=0u;
      goto l15;
l13:
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6035)))), &_td_Msg__IntAttributeDesc);
      
l15:
      if (i2) goto l17;
      i0=0u;
      goto l19;
l17:
      i0 = *(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6078)))), &_td_Msg__IntAttributeDesc, 6078)), 6091))+8);
      i1 = *(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6104)))), &_td_Msg__IntAttributeDesc, 6104)), 6117))+8);
      i0 = (_abs((i0-i1)))<16;
      
l19:
      if (i0) goto l21;
      return 1u;
      goto l24;
l21:
      return 0u;
      goto l24;
l23:
      return 1u;
l24:
      _failed_function(5727); return 0;
      ;
    }

    
    void XML_Error__ListDesc_Write_Copy(Object__String s, OOC_CHAR8 str[], OOC_LEN str_0d) {
      register OOC_INT32 i0;
      Object__String8 s8;
      Object__CharsLatin1 chars;

      i0 = (OOC_INT32)s;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6379)))), Object__StringDesc_ToString8)),Object__StringDesc_ToString8)((Object__String)i0, 63u);
      s8 = (Object__String8)i0;
      i0 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)i0);
      chars = (Object__CharsLatin1)i0;
      _copy_8((const void*)(_check_pointer(i0, 6445)),(void*)(OOC_INT32)str,str_0d);
      return;
      ;
    }


  i0 = (OOC_INT32)ch;
  i0 = (OOC_INT32)TextRider__ConnectWriter((Channel__Channel)i0);
  writer = (TextRider__Writer)i0;
  _assert((i0!=(OOC_INT32)0), 127, 6527);
  i0 = (OOC_INT32)errList;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6567))+12);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6567))+12);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6574)))), URI__URIDesc_ToString)),URI__URIDesc_ToString)((URI__URI)i0);
  XML_Error__ListDesc_Write_Copy((Object__String)i0, (void*)(OOC_INT32)repl1, 1024);
  i0 = (OOC_INT32)errList;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6611))+12);
  i0 = (OOC_INT32)URI_Scheme_File__URIDesc_GetPath((URI_Scheme_File__URI)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6624)))), &_td_URI_Scheme_File__URIDesc, 6624)));
  XML_Error__ListDesc_Write_Copy((Object__String)i0, (void*)(OOC_INT32)repl2, 1024);
  Strings__Insert("file_name=", 11, 0, (void*)(OOC_INT32)repl2, 1024);
  prev = (Msg__Msg)(OOC_INT32)0;
  prevURI = (Msg__StringPtr)(OOC_INT32)0;
  i0 = (OOC_INT32)errList;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6749))+4);
  msg = (Msg__Msg)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l28;
  i1 = (OOC_INT32)_c0;
  i2 = (OOC_INT32)_c1;
  
l3_loop:
  i3 = (OOC_INT32)prev;
  i0 = XML_Error__ListDesc_Write_DistanceOk((Msg__Msg)i3, (Msg__Msg)i0);
  if (!i0) goto l23;
  i0 = (OOC_INT32)msg;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6844)))), Msg__MsgDesc_GetAttribute)),Msg__MsgDesc_GetAttribute)((Msg__Msg)i0, "baseURI", 8);
  uriAttr = (Msg__Attribute)i0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6894)))), &_td_Msg__StringAttributeDesc, 6894)), 6910))+8);
  i4 = (OOC_INT32)prevURI;
  i3 = i3!=i4;
  if (!i3) goto l22;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6961)))), &_td_Msg__StringAttributeDesc, 6961)), 6977))+8);
  uri = (Msg__StringPtr)i3;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7011)))), &_td_Msg__StringAttributeDesc, 7011)), 7027))+8);
  _copy_8((const void*)(_check_pointer(i0, 7034)),(void*)(OOC_INT32)text,8192);
  {
    Exception__PushContext(&_context0, &_target0);
    if (!setjmp(_target0)) goto l13;
    Exception__PopContext(1);
    i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG(((OOC_INT32)Exception__Current()))), &_td_IO__ErrorDesc);
    if (i0) goto l12;
    Exception__ActivateContext();
l12:
    Exception__Clear();
    goto l21;
l13:
    i0 = (OOC_INT32)OS_ProcessParameters__GetCwd();
    i0 = (OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)i1,(void*)i0)),(void*)i2);
    cwd = (Object__String)i0;
    i3 = Strings__Length((void*)(OOC_INT32)text, 8192);
    len = i3;
    i4 = *(OOC_INT32*)(_check_pointer(i0, 7179));
    i3 = i4<i3;
    if (i3) goto l16;
    i3=0u;
    goto l18;
l16:
    i3 = *(OOC_INT32*)(_check_pointer(i0, 7257));
    i3 = (OOC_INT32)Object__NewLatin1Region((void*)(OOC_INT32)text, 8192, 0, i3);
    i3 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7214)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i0, (Object__Object)i3);
    
l18:
    if (!i3) goto l20;
    i0 = *(OOC_INT32*)(_check_pointer(i0, 7319));
    Strings__Delete((void*)(OOC_INT32)text, 8192, 0, i0);
l20:
    Exception__PopContext(1);
l21:;
  }
  i0 = (OOC_INT32)writer;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7440)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, "In file ", 9);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7484)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (void*)(OOC_INT32)text, 8192);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7522)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, ": ", 3);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7560)))), TextRider__WriterDesc_WriteLn)),TextRider__WriterDesc_WriteLn)((TextRider__Writer)i0);
l22:
  i0 = (OOC_INT32)uriAttr;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7612)))), &_td_Msg__StringAttributeDesc, 7612)), 7628))+8);
  prevURI = (Msg__StringPtr)i0;
  i0 = (OOC_INT32)msg;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7657)))), Msg__MsgDesc_GetText)),Msg__MsgDesc_GetText)((Msg__Msg)i0, (void*)(OOC_INT32)text, 8192);
  XML_Error__ListDesc_Write_Replace((void*)(OOC_INT32)text, 8192, (void*)(OOC_INT32)repl1, 1024, "file:", 6);
  XML_Error__ListDesc_Write_Replace((void*)(OOC_INT32)text, 8192, (void*)(OOC_INT32)repl2, 1024, "file_name=", 11);
  i0 = (OOC_INT32)writer;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7774)))), TextRider__WriterDesc_WriteString)),TextRider__WriterDesc_WriteString)((TextRider__Writer)i0, (void*)(OOC_INT32)text, 8192);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7810)))), TextRider__WriterDesc_WriteLn)),TextRider__WriterDesc_WriteLn)((TextRider__Writer)i0);
  i0 = (OOC_INT32)msg;
  prev = (Msg__Msg)i0;
l23:
  i0 = (OOC_INT32)msg;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7868));
  msg = (Msg__Msg)i0;
  i3 = i0!=(OOC_INT32)0;
  if (i3) goto l3_loop;
l28:
  return;
  ;
}

void OOC_XML_Error_init(void) {
  register OOC_INT32 i0;
  _c0 = Object__NewLatin1Region("file://", 8, 0, 7);
  _c1 = Object__NewLatin1Char(47u);

  i0 = (OOC_INT32)URI_Scheme_File__NewPrototype();
  URI__RegisterScheme((URI__URI)i0);
  XML_Error__errMsgLineBase = 0;
  XML_Error__errMsgColumnBase = 0;
  XML_Error__errMsgCharPosBase = 0;
  return;
  ;
}

/* --- */
