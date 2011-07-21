#include <OOC/Error.d>
#include <__oo2c.h>
#include <setjmp.h>

void OOC_Error__InitContext(OOC_Error__Context c, const Msg__String id__ref, OOC_LEN id_0d) {
  register OOC_INT32 i0;
  OOC_ALLOCATE_VPAR(id,OOC_CHAR8 ,id_0d)

  OOC_INITIALIZE_VPAR(id__ref,id,OOC_CHAR8 ,id_0d)
  i0 = (OOC_INT32)c;
  Msg__InitContext((Msg__Context)i0, (void*)(OOC_INT32)id, id_0d);
  return;
  ;
}

Msg__Msg OOC_Error__New(OOC_Error__Context context, OOC_INT32 code) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)context;
  i1 = code;
  i0 = (OOC_INT32)Msg__New((Msg__Context)i0, i1);
  return (Msg__Msg)i0;
  ;
}

OOC_Error__List OOC_Error__NewList(Object__String fileName) {
  register OOC_INT32 i0,i1;
  Object__CharsLatin1 chars;
  OOC_Error__List list;

  i0 = (OOC_INT32)fileName;
  i0 = (OOC_INT32)OS_Path__Encode((Object__String)i0);
  chars = (Object__CharsLatin1)i0;
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_Error__List.baseTypes[0]);
  list = (OOC_Error__List)i1;
  Msg__InitMsgList((Msg__MsgList)i1);
  _copy_8((const void*)(_check_pointer(i0, 3138)),(void*)((_check_pointer(i1, 3145))+12),256);
  *(OOC_UINT8*)((_check_pointer(i1, 3166))+268) = 0u;
  *(OOC_UINT8*)((_check_pointer(i1, 3200))+269) = 1u;
  return (OOC_Error__List)i1;
  ;
}

static OOC_CHAR8 OOC_Error__IsWarning(Msg__Msg msg) {
  register OOC_INT32 i0,i1,i2;
  OOC_CHAR16 _template[128];
  OOC_CHAR8 found;
  OOC_INT16 pos;

  i0 = (OOC_INT32)msg;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3388))+12);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3388))+12);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3396)))), Msg__ContextDesc_GetTemplate)),Msg__ContextDesc_GetTemplate)((Msg__Context)i2, (Msg__Msg)i0, (void*)(OOC_INT32)_template, 128);
  LongStrings__FindNext(((OOC_CHAR16[]){87,97,114,110,105,110,103,58,32,0}), 10, (void*)(OOC_INT32)_template, 128, 0, (void*)(OOC_INT32)&found, (void*)(OOC_INT32)&pos);
  i0 = found;
  return i0;
  ;
}

void OOC_Error__ListDesc_AppendWarning(OOC_Error__List l, Msg__Msg msg) {
  register OOC_INT32 i0,i1,i2;
  OOC_CHAR8 oldNoError;

  i0 = (OOC_INT32)l;
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 3631))+269);
  oldNoError = i1;
  i2 = (OOC_INT32)msg;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3646)))), Msg__MsgListDesc_Append)),Msg__MsgListDesc_Append)((Msg__MsgList)i0, (Msg__Msg)i2);
  *(OOC_UINT8*)((_check_pointer(i0, 3665))+269) = i1;
  return;
  ;
}

void OOC_Error__ListDesc_Append(OOC_Error__List l, Msg__Msg msg) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_CHAR8 isError;
  Msg__Attribute msgPos;
  Msg__Msg ptr;
  Msg__Attribute ptrPos;

  i0 = (OOC_INT32)msg;
  i1 = OOC_Error__IsWarning((Msg__Msg)i0);
  i1 = !i1;
  isError = i1;
  i2 = (OOC_INT32)l;
  i3 = *(OOC_UINT8*)((_check_pointer(i2, 3947))+269);
  if (i3) goto l3;
  i3=0u;
  goto l5;
l3:
  i3=i1;
l5:
  if (!i3) goto l7;
  *(OOC_UINT8*)((_check_pointer(i2, 3978))+269) = 0u;
l7:
  i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4028)))), Msg__MsgDesc_GetAttribute)),Msg__MsgDesc_GetAttribute)((Msg__Msg)i0, "pos", 4);
  msgPos = (Msg__Attribute)i3;
  if (!i1) goto l29;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 4086))+4);
  ptr = (Msg__Msg)i1;
  i4 = i1!=(OOC_INT32)0;
  if (!i4) goto l29;
l12_loop:
  i4 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4144)))), Msg__MsgDesc_GetAttribute)),Msg__MsgDesc_GetAttribute)((Msg__Msg)i1, "pos", 4);
  ptrPos = (Msg__Attribute)i4;
  i5 = OOC_Error__IsWarning((Msg__Msg)i1);
  i5 = !i5;
  if (i5) goto l15;
  i5=0u;
  goto l17;
l15:
  i5 = i4!=(OOC_INT32)0;
  
l17:
  if (i5) goto l19;
  i4=0u;
  goto l21;
l19:
  i4 = *(OOC_INT32*)((_check_pointer((_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 4250)))), &_td_Msg__IntAttributeDesc, 4250)), 4263))+8);
  i5 = *(OOC_INT32*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 4279)))), &_td_Msg__IntAttributeDesc, 4279)), 4292))+8);
  i6 = OOC_Error__minErrorDistance;
  i4 = (_abs((i4-i5)))<i6;
  
l21:
  if (!i4) goto l23;
  return;
l23:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 4385));
  ptr = (Msg__Msg)i1;
  i4 = i1!=(OOC_INT32)0;
  if (i4) goto l12_loop;
l29:
  Msg__MsgListDesc_Append((Msg__MsgList)i2, (Msg__Msg)i0);
  return;
  ;
}

OOC_CHAR8 OOC_Error__ListDesc_NoErrors(OOC_Error__List l) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)l;
  i0 = *(OOC_UINT8*)((_check_pointer(i0, 4512))+269);
  return i0;
  ;
}

void OOC_Error__ContextDesc_BaseTemplate(OOC_Error__Context c, Msg__Msg msg, const Msg__LString text__ref, OOC_LEN text_0d, Msg__LString templ, OOC_LEN templ_0d) {
  register OOC_INT32 i0,i1;
  OOC_ALLOCATE_VPAR(text,OOC_CHAR16 ,text_0d)
  OOC_CHAR16 repl[8192];
  Msg__Attribute attr;

  OOC_INITIALIZE_VPAR(text__ref,text,OOC_CHAR16 ,(text_0d*2))
  i0 = OOC_Error__style;
  i1 = i0==1;
  if (i1) goto l15;
  i0 = i0==0;
  if (i0) goto l13;
  _copy_16((const void*)(OOC_INT32)text,(void*)(OOC_INT32)templ,templ_0d);
  _copy_16((const void*)((OOC_CHAR16[]){10,0}),(void*)(OOC_INT32)repl,8192);
  LongStrings__Append((void*)(OOC_INT32)repl, 8192, (void*)(OOC_INT32)templ, templ_0d);
  i0 = (OOC_INT32)msg;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5386))+16);
  attr = (Msg__Attribute)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l16;
l7_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5446))+4);
  _copy_8to16((const void*)(_check_pointer(i1, 5452)),(void*)(OOC_INT32)repl,8192);
  LongStrings__Append((void*)(OOC_INT32)repl, 8192, (void*)(OOC_INT32)templ, templ_0d);
  LongStrings__Append(((OOC_CHAR16[]){61,36,123,0}), 4, (void*)(OOC_INT32)templ, templ_0d);
  LongStrings__Append((void*)(OOC_INT32)repl, 8192, (void*)(OOC_INT32)templ, templ_0d);
  LongStrings__Append(((OOC_CHAR16[]){125,0}), 2, (void*)(OOC_INT32)templ, templ_0d);
  _copy_16((const void*)((OOC_CHAR16[]){10,0}),(void*)(OOC_INT32)repl,8192);
  LongStrings__Append((void*)(OOC_INT32)repl, 8192, (void*)(OOC_INT32)templ, templ_0d);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5728));
  attr = (Msg__Attribute)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l7_loop;
  goto l16;
l13:
  _copy_16((const void*)((OOC_CHAR16[]){58,36,123,108,105,110,101,125,58,36,123,99,111,108,117,109,110,125,58,32,0}),(void*)(OOC_INT32)templ,templ_0d);
  LongStrings__Append((void*)(OOC_INT32)text, text_0d, (void*)(OOC_INT32)templ, templ_0d);
  goto l16;
l15:
  _copy_16((const void*)((OOC_CHAR16[]){36,123,112,111,115,125,58,32,0}),(void*)(OOC_INT32)templ,templ_0d);
  LongStrings__Append((void*)(OOC_INT32)text, text_0d, (void*)(OOC_INT32)templ, templ_0d);
l16:
  return;
  ;
}

void OOC_Error__ListDesc_SetAdjustCharPos(OOC_Error__List errList, OOC_CHAR8 adjust) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)errList;
  i1 = adjust;
  *(OOC_UINT8*)((_check_pointer(i0, 6215))+268) = i1;
  return;
  ;
}

void OOC_Error__ListDesc_Write(OOC_Error__List errList, IO__ByteChannel ch) {
  register OOC_INT32 i0,i1,i2;
  IO_TextRider__Writer writer;
  Msg__Msg msg;
  Msg__Attribute attrPos;
  OOC_INT32 lastPos;
  OOC_CHAR8 text[8192];
  Msg__Attribute attrLine;
  Msg__Attribute attrColumn;
  auto void OOC_Error__ListDesc_Write_WriteMsg(Msg__Msg msg);
  auto Msg__Msg OOC_Error__ListDesc_Write_GetNext(OOC_INT32 *lastPos);
    
    void OOC_Error__ListDesc_Write_WriteMsg(Msg__Msg msg) {
      register OOC_INT32 i0,i1,i2,i3;

      i0 = (OOC_INT32)msg;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6725)))), Msg__MsgDesc_GetText)),Msg__MsgDesc_GetText)((Msg__Msg)i0, (void*)(OOC_INT32)text, 8192);
      i1 = (OOC_INT32)errList;
      i1 = *(OOC_UINT8*)((_check_pointer(i1, 6766))+268);
      if (!i1) goto l10;
      i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6842)))), Msg__MsgDesc_GetAttribute)),Msg__MsgDesc_GetAttribute)((Msg__Msg)i0, "pos", 4);
      attrPos = (Msg__Attribute)i1;
      i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6891)))), Msg__MsgDesc_GetAttribute)),Msg__MsgDesc_GetAttribute)((Msg__Msg)i0, "line", 5);
      attrLine = (Msg__Attribute)i1;
      i2 = (OOC_INT32)attrPos;
      i3 = i2!=(OOC_INT32)0;
      if (i3) goto l5;
      i3=0u;
      goto l7;
l5:
      i3 = i1!=(OOC_INT32)0;
      
l7:
      if (!i3) goto l10;
      i2 = *(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 7017)))), &_td_Msg__IntAttributeDesc, 7017)), 7030))+8);
      i1 = *(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7077)))), &_td_Msg__IntAttributeDesc, 7077)), 7090))+8);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6982)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i0, "pos", 4, (i2-i1));
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7111)))), Msg__MsgDesc_GetText)),Msg__MsgDesc_GetText)((Msg__Msg)i0, (void*)(OOC_INT32)text, 8192);
      i1 = (OOC_INT32)attrPos;
      i1 = *(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7177)))), &_td_Msg__IntAttributeDesc, 7177)), 7190))+8);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7142)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i0, "pos", 4, i1);
l10:
      i1 = OOC_Error__style;
      i1 = i1==0;
      if (!i1) goto l30;
      i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7406)))), Msg__MsgDesc_GetAttribute)),Msg__MsgDesc_GetAttribute)((Msg__Msg)i0, "line", 5);
      attrLine = (Msg__Attribute)i1;
      i2 = i1!=(OOC_INT32)0;
      if (!i2) goto l15;
      i1 = *(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7516)))), &_td_Msg__IntAttributeDesc, 7516)), 7529))+8);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7479)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i0, "line", 5, (i1+1));
l15:
      i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7577)))), Msg__MsgDesc_GetAttribute)),Msg__MsgDesc_GetAttribute)((Msg__Msg)i0, "column", 7);
      attrColumn = (Msg__Attribute)i1;
      i2 = i1!=(OOC_INT32)0;
      if (i2) goto l18;
      i2=0u;
      goto l20;
l18:
      i2 = (OOC_INT32)attrLine;
      i2 = i2!=(OOC_INT32)0;
      
l20:
      if (!i2) goto l22;
      i1 = *(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7714)))), &_td_Msg__IntAttributeDesc, 7714)), 7727))+8);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7673)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i0, "column", 7, (i1+1));
l22:
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7761)))), Msg__MsgDesc_GetText)),Msg__MsgDesc_GetText)((Msg__Msg)i0, (void*)(OOC_INT32)text, 8192);
      i0 = (OOC_INT32)attrLine;
      i0 = i0!=(OOC_INT32)0;
      if (i0) goto l25;
      i0=0u;
      goto l27;
l25:
      i0 = (OOC_INT32)attrColumn;
      i0 = i0!=(OOC_INT32)0;
      
l27:
      if (!i0) goto l30;
      i0 = (OOC_INT32)writer;
      i1 = (OOC_INT32)errList;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7850)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (void*)((_check_pointer(i1, 7872))+12), 256);
l30:
      i0 = (OOC_INT32)writer;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7921)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (void*)(OOC_INT32)text, 8192);
      i0 = (OOC_INT32)writer;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7955)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
      return;
      ;
    }

    
    Msg__Msg OOC_Error__ListDesc_Write_GetNext(OOC_INT32 *lastPos) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5;
      Msg__Msg best;
      OOC_INT32 bestPos;
      Msg__Msg msg;
      Msg__Attribute pos;

      best = (Msg__Msg)(OOC_INT32)0;
      bestPos = (-1);
      i0 = (OOC_INT32)errList;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8182))+4);
      msg = (Msg__Msg)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l3;
      i0=(-1);i1=(OOC_INT32)0;
      goto l25;
l3:
      i1 = *lastPos;
      i2=(OOC_INT32)0;i3=(-1);
l4_loop:
      i4 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8238)))), Msg__MsgDesc_GetAttribute)),Msg__MsgDesc_GetAttribute)((Msg__Msg)i0, "pos", 4);
      pos = (Msg__Attribute)i4;
      i5 = i4!=(OOC_INT32)0;
      if (i5) goto l7;
      i5=0u;
      goto l9;
l7:
      i5 = *(OOC_INT32*)((_check_pointer((_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 8294)))), &_td_Msg__IntAttributeDesc, 8294)), 8307))+8);
      i5 = i5>=i1;
      
l9:
      if (i5) goto l11;
      i5=0u;
      goto l17;
l11:
      i5 = i2==(OOC_INT32)0;
      if (i5) goto l14;
      i5 = *(OOC_INT32*)((_check_pointer((_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 8361)))), &_td_Msg__IntAttributeDesc, 8361)), 8374))+8);
      i5 = i5<i3;
      
      goto l17;
l14:
      i5=1u;
l17:
      if (!i5) goto l20;
      best = (Msg__Msg)i0;
      i2 = *(OOC_INT32*)((_check_pointer((_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 8446)))), &_td_Msg__IntAttributeDesc, 8446)), 8459))+8);
      bestPos = i2;
      i3=i2;i2=i0;
l20:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 8496));
      msg = (Msg__Msg)i0;
      i4 = i0!=(OOC_INT32)0;
      if (i4) goto l4_loop;
l24:
      i0=i3;i1=i2;
l25:
      *lastPos = i0;
      return (Msg__Msg)i1;
      ;
    }


  i0 = (OOC_INT32)ch;
  i0 = (OOC_INT32)IO_TextRider__ConnectWriter((IO__ByteChannel)i0);
  writer = (IO_TextRider__Writer)i0;
  _assert((i0!=(OOC_INT32)0), 127, 8638);
  i1 = (OOC_INT32)errList;
  i2 = (
  _cmp8((const void*)((_check_pointer(i1, 8681))+12),(const void*)""))!=0;
  if (i2) goto l3;
  i2=0u;
  goto l5;
l3:
  i2 = OOC_Error__style;
  i2 = i2!=0;
  
l5:
  if (!i2) goto l7;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8747)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "In file ", 9);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8787)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (void*)((_check_pointer(i1, 8809))+12), 256);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8834)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, ": ", 3);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8868)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
l7:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8976))+4);
  msg = (Msg__Msg)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l18;
l10_loop:
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9032)))), Msg__MsgDesc_GetAttribute)),Msg__MsgDesc_GetAttribute)((Msg__Msg)i0, "pos", 4);
  attrPos = (Msg__Attribute)i1;
  i1 = i1==(OOC_INT32)0;
  if (!i1) goto l13;
  OOC_Error__ListDesc_Write_WriteMsg((Msg__Msg)i0);
l13:
  i0 = (OOC_INT32)msg;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9137));
  msg = (Msg__Msg)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l10_loop;
l18:
  lastPos = (-1);
l19_loop:
  i0 = (OOC_INT32)OOC_Error__ListDesc_Write_GetNext((void*)(OOC_INT32)&lastPos);
  msg = (Msg__Msg)i0;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l24;
  OOC_Error__ListDesc_Write_WriteMsg((Msg__Msg)i0);
  i0 = (OOC_INT32)msg;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9371)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i0, "pos", 4, (-2));
  goto l19_loop;
l24:
  return;
  ;
}

void OOC_OOC_Error_init(void) {

  OOC_Error__style = 2;
  OOC_Error__minErrorDistance = 0;
  return;
  ;
}

/* --- */
