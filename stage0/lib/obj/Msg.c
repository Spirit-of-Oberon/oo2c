#include <Msg.d>
#include <__oo2c.h>
#include <setjmp.h>

void Msg__InitContext(Msg__Context context, const Msg__String id__ref, OOC_LEN id_0d) {
  register OOC_INT32 i0,i1;
  OOC_ALLOCATE_VPAR(id,OOC_CHAR8 ,id_0d)

  OOC_INITIALIZE_VPAR(id__ref,id,OOC_CHAR8 ,id_0d)
  i0 = (OOC_INT32)context;
  i1 = Strings__Length((void*)(OOC_INT32)id, id_0d);
  *(OOC_INT32*)(_check_pointer(i0, 6817)) = ((OOC_INT32)RT0__NewObject(_td_Msg__StringPtr.baseTypes[0], (i1+1)));
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6868));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6868));
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 6872)), 0);
  _copy_8((const void*)(OOC_INT32)id,(void*)(_check_pointer(i1, 6872)),i0);
  return;
  ;
}

void Msg__ContextDesc_GetTemplate(Msg__Context context, Msg__Msg msg, Msg__LString templ, OOC_LEN templ_0d) {
  register OOC_INT32 i0,i1;
  Msg__Attribute attrib;
  OOC_CHAR16 buffer[16384];

  _copy_16((const void*)((OOC_CHAR16[]){77,83,71,95,67,79,78,84,69,88,84,58,32,36,123,77,83,71,95,67,79,78,84,69,88,84,125,0}),(void*)(OOC_INT32)templ,templ_0d);
  LongStrings__Append(((OOC_CHAR16[]){10,0}), 2, (void*)(OOC_INT32)templ, templ_0d);
  LongStrings__Append(((OOC_CHAR16[]){77,83,71,95,67,79,68,69,58,32,36,123,77,83,71,95,67,79,68,69,125,0}), 22, (void*)(OOC_INT32)templ, templ_0d);
  LongStrings__Append(((OOC_CHAR16[]){10,0}), 2, (void*)(OOC_INT32)templ, templ_0d);
  i0 = (OOC_INT32)msg;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8196))+16);
  attrib = (Msg__Attribute)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l8;
l3_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8256))+4);
  _copy_8to16((const void*)(_check_pointer(i1, 8262)),(void*)(OOC_INT32)buffer,16384);
  LongStrings__Append((void*)(OOC_INT32)buffer, 16384, (void*)(OOC_INT32)templ, templ_0d);
  LongStrings__Append(((OOC_CHAR16[]){58,32,36,123,0}), 5, (void*)(OOC_INT32)templ, templ_0d);
  LongStrings__Append((void*)(OOC_INT32)buffer, 16384, (void*)(OOC_INT32)templ, templ_0d);
  LongStrings__Append(((OOC_CHAR16[]){125,0}), 2, (void*)(OOC_INT32)templ, templ_0d);
  LongStrings__Append(((OOC_CHAR16[]){10,0}), 2, (void*)(OOC_INT32)templ, templ_0d);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 8540));
  attrib = (Msg__Attribute)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3_loop;
l8:
  return;
  ;
}

void Msg__InitAttribute(Msg__Attribute attr, const Msg__String name__ref, OOC_LEN name_0d) {
  register OOC_INT32 i0,i1;
  OOC_ALLOCATE_VPAR(name,OOC_CHAR8 ,name_0d)

  OOC_INITIALIZE_VPAR(name__ref,name,OOC_CHAR8 ,name_0d)
  i0 = (OOC_INT32)attr;
  *(OOC_INT32*)(_check_pointer(i0, 8814)) = 0;
  i1 = Strings__Length((void*)(OOC_INT32)name, name_0d);
  *(OOC_INT32*)((_check_pointer(i0, 8848))+4) = ((OOC_INT32)RT0__NewObject(_td_Msg__StringPtr.baseTypes[0], (i1+1)));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8902))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8902))+4);
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 8908)), 0);
  _copy_8((const void*)(OOC_INT32)name,(void*)(_check_pointer(i1, 8908)),i0);
  return;
  ;
}

void Msg__AttributeDesc_ReplacementText(Msg__Attribute attr, Msg__LString text, OOC_LEN text_0d) {

  return;
  ;
}

Msg__Msg Msg__New(Msg__Context context, OOC_INT32 code) {
  register OOC_INT32 i0,i1;
  Msg__Msg msg;

  i0 = (OOC_INT32)RT0__NewObject(_td_Msg__Msg.baseTypes[0]);
  msg = (Msg__Msg)i0;
  *(OOC_INT32*)((_check_pointer(i0, 9651))+4) = (OOC_INT32)0;
  *(OOC_INT32*)(_check_pointer(i0, 9676)) = (OOC_INT32)0;
  i1 = code;
  *(OOC_INT32*)((_check_pointer(i0, 9701))+8) = i1;
  i1 = (OOC_INT32)context;
  *(OOC_INT32*)((_check_pointer(i0, 9724))+12) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 9753))+16) = (OOC_INT32)0;
  return (Msg__Msg)i0;
  ;
}

void Msg__MsgDesc_SetAttribute(Msg__Msg msg, Msg__Attribute attr) {
  register OOC_INT32 i0,i1;
  auto void Msg__MsgDesc_SetAttribute_Insert(Msg__Attribute *aList, Msg__Attribute attr);
    
    void Msg__MsgDesc_SetAttribute_Insert(Msg__Attribute *aList, Msg__Attribute attr) {
      register OOC_INT32 i0,i1,i2,i3;

      i0 = (OOC_INT32)*aList;
      i1 = i0==(OOC_INT32)0;
      if (i1) goto l11;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10314))+4);
      i2 = (OOC_INT32)attr;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 10328))+4);
      i1 = (
      _cmp8((const void*)(_check_pointer(i1, 10320)),(const void*)(_check_pointer(i3, 10334))))==0;
      if (i1) goto l9;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10457))+4);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 10471))+4);
      i1 = (
      _cmp8((const void*)(_check_pointer(i1, 10463)),(const void*)(_check_pointer(i3, 10476))))>0;
      if (i1) goto l7;
      Msg__MsgDesc_SetAttribute_Insert((void*)(_check_pointer(i0, 10672)), (Msg__Attribute)i2);
      goto l12;
l7:
      *(OOC_INT32*)(_check_pointer(i2, 10530)) = i0;
      *aList = (Msg__Attribute)i2;
      goto l12;
l9:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10403));
      *(OOC_INT32*)(_check_pointer(i2, 10382)) = i0;
      *aList = (Msg__Attribute)i2;
      goto l12;
l11:
      i0 = (OOC_INT32)attr;
      *aList = (Msg__Attribute)i0;
l12:
      return;
      ;
    }


  i0 = (OOC_INT32)msg;
  i1 = (OOC_INT32)attr;
  Msg__MsgDesc_SetAttribute_Insert((void*)((_check_pointer(i0, 10742))+16), (Msg__Attribute)i1);
  return;
  ;
}

Msg__Attribute Msg__MsgDesc_GetAttribute(Msg__Msg msg, const Msg__String name__ref, OOC_LEN name_0d) {
  register OOC_INT32 i0,i1;
  OOC_ALLOCATE_VPAR(name,OOC_CHAR8 ,name_0d)
  Msg__Attribute a;

  OOC_INITIALIZE_VPAR(name__ref,name,OOC_CHAR8 ,name_0d)
  i0 = (OOC_INT32)msg;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11022))+16);
  a = (Msg__Attribute)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11060))+4);
  i1 = (
  _cmp8((const void*)(_check_pointer(i1, 11066)),(const void*)(OOC_INT32)name))!=0;
  
l5:
  if (!i1) goto l17;
l8_loop:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 11091));
  a = (Msg__Attribute)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l11;
  i1=0u;
  goto l13;
l11:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11060))+4);
  i1 = (
  _cmp8((const void*)(_check_pointer(i1, 11066)),(const void*)(OOC_INT32)name))!=0;
  
l13:
  if (i1) goto l8_loop;
l17:
  return (Msg__Attribute)i0;
  ;
}

void Msg__MsgDesc_GetLText(Msg__Msg msg, Msg__LString text, OOC_LEN text_0d) {
  register OOC_INT32 i0,i1,i2,i3;
  Msg__Attribute attr;
  OOC_CHAR16 attrName[131];
  OOC_INT16 pos;
  OOC_CHAR8 found;
  OOC_INT16 len;
  OOC_CHAR16 insert[16384];
  OOC_CHAR8 num[48];

  i0 = (OOC_INT32)msg;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11876))+12);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11876))+12);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11885)))), Msg__ContextDesc_GetTemplate)),Msg__ContextDesc_GetTemplate)((Msg__Context)i2, (Msg__Msg)i0, (void*)(OOC_INT32)text, text_0d);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11927))+16);
  attr = (Msg__Attribute)i1;
  i2 = i1!=(OOC_INT32)0;
  if (!i2) goto l15;
l3_loop:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11983))+4);
  _copy_8to16((const void*)(_check_pointer(i2, 11989)),(void*)(OOC_INT32)attrName,131);
  LongStrings__Insert(((OOC_CHAR16[]){36,123,0}), 3, 0, (void*)(OOC_INT32)attrName, 131);
  LongStrings__Append(((OOC_CHAR16[]){125,0}), 2, (void*)(OOC_INT32)attrName, 131);
  LongStrings__FindNext((void*)(OOC_INT32)attrName, 131, (void*)(OOC_INT32)text, text_0d, 0, (void*)(OOC_INT32)&found, (void*)(OOC_INT32)&pos);
  i2 = found;
  if (!i2) goto l10;
l5_loop:
  i2 = LongStrings__Length((void*)(OOC_INT32)attrName, 131);
  len = i2;
  i3 = pos;
  LongStrings__Delete((void*)(OOC_INT32)text, text_0d, i3, i2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 12282)))), Msg__AttributeDesc_ReplacementText)),Msg__AttributeDesc_ReplacementText)((Msg__Attribute)i1, (void*)(OOC_INT32)insert, 16384);
  i2 = pos;
  LongStrings__Insert((void*)(OOC_INT32)insert, 16384, i2, (void*)(OOC_INT32)text, text_0d);
  i2 = LongStrings__Length((void*)(OOC_INT32)insert, 16384);
  i3 = pos;
  LongStrings__FindNext((void*)(OOC_INT32)attrName, 131, (void*)(OOC_INT32)text, text_0d, (i3+i2), (void*)(OOC_INT32)&found, (void*)(OOC_INT32)&pos);
  i2 = found;
  if (i2) goto l5_loop;
l10:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 12515));
  attr = (Msg__Attribute)i1;
  i2 = i1!=(OOC_INT32)0;
  if (i2) goto l3_loop;
l15:
  LongStrings__FindNext(((OOC_CHAR16[]){36,123,77,83,71,95,67,79,78,84,69,88,84,125,0}), 15, (void*)(OOC_INT32)text, text_0d, 0, (void*)(OOC_INT32)&found, (void*)(OOC_INT32)&pos);
  i1 = found;
  if (!i1) goto l18;
  i1 = pos;
  LongStrings__Delete((void*)(OOC_INT32)text, text_0d, i1, 14);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12683))+12);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 12692));
  _copy_8to16((const void*)(_check_pointer(i1, 12696)),(void*)(OOC_INT32)insert,16384);
  i1 = pos;
  LongStrings__Insert((void*)(OOC_INT32)insert, 16384, i1, (void*)(OOC_INT32)text, text_0d);
l18:
  LongStrings__FindNext(((OOC_CHAR16[]){36,123,77,83,71,95,67,79,68,69,125,0}), 12, (void*)(OOC_INT32)text, text_0d, 0, (void*)(OOC_INT32)&found, (void*)(OOC_INT32)&pos);
  i1 = found;
  if (!i1) goto l21;
  i1 = pos;
  LongStrings__Delete((void*)(OOC_INT32)text, text_0d, i1, 11);
  i0 = *(OOC_INT32*)((_check_pointer(i0, 12916))+8);
  IntStr__IntToStr(i0, (void*)(OOC_INT32)num, 48);
  _copy_8to16((const void*)(OOC_INT32)num,(void*)(OOC_INT32)insert,16384);
  i0 = pos;
  LongStrings__Insert((void*)(OOC_INT32)insert, 16384, i0, (void*)(OOC_INT32)text, text_0d);
l21:
  return;
  ;
}

void Msg__MsgDesc_GetText(Msg__Msg msg, Msg__String text, OOC_LEN text_0d) {
  register OOC_INT32 i0,i1;
  OOC_CHAR16 buffer[32767];

  i0 = (OOC_INT32)msg;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13344)))), Msg__MsgDesc_GetLText)),Msg__MsgDesc_GetLText)((Msg__Msg)i0, (void*)(OOC_INT32)buffer, 32767);
  i0=(-1);
l1_loop:
  i0 = i0+1;
  i1 = *(OOC_UINT16*)((OOC_INT32)buffer+(_check_index(i0, 32767, OOC_UINT16, 13420))*2);
  i1 = (OOC_UINT16)i1<=(OOC_UINT16)255u;
  if (i1) goto l4;
  *(OOC_UINT8*)((OOC_INT32)text+(_check_index(i0, text_0d, OOC_UINT16, 13498))) = 63u;
  goto l5;
l4:
  i1 = *(OOC_UINT16*)((OOC_INT32)buffer+(_check_index(i0, 32767, OOC_UINT16, 13470))*2);
  *(OOC_UINT8*)((OOC_INT32)text+(_check_index(i0, text_0d, OOC_UINT16, 13450))) = i1;
l5:
  i1 = *(OOC_UINT8*)((OOC_INT32)text+(_check_index(i0, text_0d, OOC_UINT16, 13534)));
  i1 = i1==0u;
  if (!i1) goto l1_loop;
l9:
  return;
  ;
}

void Msg__InitMsgList(Msg__MsgList l) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)l;
  *(OOC_INT32*)(_check_pointer(i0, 13710)) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 13732))+4) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 13755))+8) = 0;
  return;
  ;
}

Msg__MsgList Msg__NewMsgList(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)RT0__NewObject(_td_Msg__MsgList.baseTypes[0]);
  Msg__InitMsgList((Msg__MsgList)i0);
  return (Msg__MsgList)i0;
  ;
}

void Msg__MsgListDesc_Append(Msg__MsgList l, Msg__Msg msg) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)msg;
  *(OOC_INT32*)(_check_pointer(i0, 14127)) = 0;
  i1 = (OOC_INT32)l;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14154))+4);
  i2 = i2==0;
  if (i2) goto l3;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14259))+8);
  *(OOC_INT32*)((_check_pointer(i0, 14245))+4) = i2;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14277))+8);
  *(OOC_INT32*)(_check_pointer(i2, 14286)) = i0;
  goto l4;
l3:
  *(OOC_INT32*)((_check_pointer(i0, 14185))+4) = 0;
  *(OOC_INT32*)((_check_pointer(i1, 14210))+4) = i0;
l4:
  *(OOC_INT32*)((_check_pointer(i1, 14317))+8) = i0;
  i0 = *(OOC_INT32*)(_check_pointer(i1, 14345));
  *(OOC_INT32*)(_check_pointer(i1, 14345)) = (i0+1);
  return;
  ;
}

void Msg__MsgListDesc_AppendList(Msg__MsgList l, Msg__MsgList source) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)source;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 14652));
  i1 = i1!=0;
  if (!i1) goto l10;
  i1 = (OOC_INT32)l;
  i2 = *(OOC_INT32*)(_check_pointer(i1, 14684));
  i2 = i2==0;
  if (i2) goto l5;
  i2 = *(OOC_INT32*)(_check_pointer(i0, 14813));
  i3 = *(OOC_INT32*)(_check_pointer(i1, 14795));
  *(OOC_INT32*)(_check_pointer(i1, 14795)) = (i3+i2);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14835))+8);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14863))+4);
  *(OOC_INT32*)(_check_pointer(i2, 14844)) = i3;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14888))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14911))+8);
  *(OOC_INT32*)((_check_pointer(i2, 14897))+4) = i3;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14950))+8);
  *(OOC_INT32*)((_check_pointer(i1, 14931))+8) = i2;
  Msg__InitMsgList((Msg__MsgList)i0);
  goto l10;
l5:
  i0 = _check_pointer(i0, 14725);
  i1 = _check_pointer(i1, 14714);
  i2 = (OOC_INT32)&_td_Msg__MsgListDesc;
  i2 = i2!=i2;
  if (!i2) goto l8;
  _failed_type_assert(14714);
l8:
  _copy_block(i0,i1,12);
l10:
  return;
  ;
}

Msg__IntAttribute Msg__NewIntAttrib(const Msg__String name__ref, OOC_LEN name_0d, OOC_INT32 value) {
  register OOC_INT32 i0,i1;
  OOC_ALLOCATE_VPAR(name,OOC_CHAR8 ,name_0d)
  Msg__IntAttribute attr;

  OOC_INITIALIZE_VPAR(name__ref,name,OOC_CHAR8 ,name_0d)
  i0 = (OOC_INT32)RT0__NewObject(_td_Msg__IntAttribute.baseTypes[0]);
  attr = (Msg__IntAttribute)i0;
  Msg__InitAttribute((Msg__Attribute)i0, (void*)(OOC_INT32)name, name_0d);
  i1 = value;
  *(OOC_INT32*)((_check_pointer(i0, 15336))+8) = i1;
  return (Msg__IntAttribute)i0;
  ;
}

void Msg__MsgDesc_SetIntAttrib(Msg__Msg msg, const Msg__String name__ref, OOC_LEN name_0d, OOC_INT32 value) {
  register OOC_INT32 i0,i1;
  OOC_ALLOCATE_VPAR(name,OOC_CHAR8 ,name_0d)

  OOC_INITIALIZE_VPAR(name__ref,name,OOC_CHAR8 ,name_0d)
  i0 = value;
  i0 = (OOC_INT32)Msg__NewIntAttrib((void*)(OOC_INT32)name, name_0d, i0);
  i1 = (OOC_INT32)msg;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15509)))), Msg__MsgDesc_SetAttribute)),Msg__MsgDesc_SetAttribute)((Msg__Msg)i1, (Msg__Attribute)i0);
  return;
  ;
}

void Msg__IntAttributeDesc_ReplacementText(Msg__IntAttribute attr, Msg__LString text, OOC_LEN text_0d) {
  register OOC_INT32 i0;
  OOC_CHAR8 num[48];

  i0 = (OOC_INT32)attr;
  i0 = *(OOC_INT32*)((_check_pointer(i0, 15709))+8);
  IntStr__IntToStr(i0, (void*)(OOC_INT32)num, 48);
  _copy_8to16((const void*)(OOC_INT32)num,(void*)(OOC_INT32)text,text_0d);
  return;
  ;
}

Msg__StringAttribute Msg__NewStringAttrib(const Msg__String name__ref, OOC_LEN name_0d, Msg__StringPtr value) {
  register OOC_INT32 i0,i1;
  OOC_ALLOCATE_VPAR(name,OOC_CHAR8 ,name_0d)
  Msg__StringAttribute attr;

  OOC_INITIALIZE_VPAR(name__ref,name,OOC_CHAR8 ,name_0d)
  i0 = (OOC_INT32)RT0__NewObject(_td_Msg__StringAttribute.baseTypes[0]);
  attr = (Msg__StringAttribute)i0;
  Msg__InitAttribute((Msg__Attribute)i0, (void*)(OOC_INT32)name, name_0d);
  i1 = (OOC_INT32)value;
  *(OOC_INT32*)((_check_pointer(i0, 15980))+8) = i1;
  return (Msg__StringAttribute)i0;
  ;
}

void Msg__MsgDesc_SetStringAttrib(Msg__Msg msg, const Msg__String name__ref, OOC_LEN name_0d, Msg__StringPtr value) {
  register OOC_INT32 i0,i1;
  OOC_ALLOCATE_VPAR(name,OOC_CHAR8 ,name_0d)

  OOC_INITIALIZE_VPAR(name__ref,name,OOC_CHAR8 ,name_0d)
  i0 = (OOC_INT32)value;
  i0 = (OOC_INT32)Msg__NewStringAttrib((void*)(OOC_INT32)name, name_0d, (Msg__StringPtr)i0);
  i1 = (OOC_INT32)msg;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16164)))), Msg__MsgDesc_SetAttribute)),Msg__MsgDesc_SetAttribute)((Msg__Msg)i1, (Msg__Attribute)i0);
  return;
  ;
}

void Msg__StringAttributeDesc_ReplacementText(Msg__StringAttribute attr, Msg__LString text, OOC_LEN text_0d) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)attr;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16329))+8);
  _copy_8to16((const void*)(_check_pointer(i0, 16337)),(void*)(OOC_INT32)text,text_0d);
  return;
  ;
}

Msg__LStringAttribute Msg__NewLStringAttrib(const Msg__String name__ref, OOC_LEN name_0d, Msg__LStringPtr value) {
  register OOC_INT32 i0,i1;
  OOC_ALLOCATE_VPAR(name,OOC_CHAR8 ,name_0d)
  Msg__LStringAttribute attr;

  OOC_INITIALIZE_VPAR(name__ref,name,OOC_CHAR8 ,name_0d)
  i0 = (OOC_INT32)RT0__NewObject(_td_Msg__LStringAttribute.baseTypes[0]);
  attr = (Msg__LStringAttribute)i0;
  Msg__InitAttribute((Msg__Attribute)i0, (void*)(OOC_INT32)name, name_0d);
  i1 = (OOC_INT32)value;
  *(OOC_INT32*)((_check_pointer(i0, 16587))+8) = i1;
  return (Msg__LStringAttribute)i0;
  ;
}

void Msg__MsgDesc_SetLStringAttrib(Msg__Msg msg, const Msg__String name__ref, OOC_LEN name_0d, Msg__LStringPtr value) {
  register OOC_INT32 i0,i1;
  OOC_ALLOCATE_VPAR(name,OOC_CHAR8 ,name_0d)

  OOC_INITIALIZE_VPAR(name__ref,name,OOC_CHAR8 ,name_0d)
  i0 = (OOC_INT32)value;
  i0 = (OOC_INT32)Msg__NewLStringAttrib((void*)(OOC_INT32)name, name_0d, (Msg__LStringPtr)i0);
  i1 = (OOC_INT32)msg;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16774)))), Msg__MsgDesc_SetAttribute)),Msg__MsgDesc_SetAttribute)((Msg__Msg)i1, (Msg__Attribute)i0);
  return;
  ;
}

void Msg__LStringAttributeDesc_ReplacementText(Msg__LStringAttribute attr, Msg__LString text, OOC_LEN text_0d) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)attr;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16942))+8);
  _copy_16((const void*)(_check_pointer(i0, 16950)),(void*)(OOC_INT32)text,text_0d);
  return;
  ;
}

Msg__MsgAttribute Msg__NewMsgAttrib(const Msg__String name__ref, OOC_LEN name_0d, Msg__Msg value) {
  register OOC_INT32 i0,i1;
  OOC_ALLOCATE_VPAR(name,OOC_CHAR8 ,name_0d)
  Msg__MsgAttribute attr;

  OOC_INITIALIZE_VPAR(name__ref,name,OOC_CHAR8 ,name_0d)
  i0 = (OOC_INT32)RT0__NewObject(_td_Msg__MsgAttribute.baseTypes[0]);
  attr = (Msg__MsgAttribute)i0;
  Msg__InitAttribute((Msg__Attribute)i0, (void*)(OOC_INT32)name, name_0d);
  i1 = (OOC_INT32)value;
  *(OOC_INT32*)((_check_pointer(i0, 17181))+8) = i1;
  return (Msg__MsgAttribute)i0;
  ;
}

void Msg__MsgDesc_SetMsgAttrib(Msg__Msg msg, const Msg__String name__ref, OOC_LEN name_0d, Msg__Msg value) {
  register OOC_INT32 i0,i1;
  OOC_ALLOCATE_VPAR(name,OOC_CHAR8 ,name_0d)

  OOC_INITIALIZE_VPAR(name__ref,name,OOC_CHAR8 ,name_0d)
  i0 = (OOC_INT32)value;
  i0 = (OOC_INT32)Msg__NewMsgAttrib((void*)(OOC_INT32)name, name_0d, (Msg__Msg)i0);
  i1 = (OOC_INT32)msg;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17350)))), Msg__MsgDesc_SetAttribute)),Msg__MsgDesc_SetAttribute)((Msg__Msg)i1, (Msg__Attribute)i0);
  return;
  ;
}

void Msg__MsgAttributeDesc_ReplacementText(Msg__MsgAttribute attr, Msg__LString text, OOC_LEN text_0d) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)attr;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17500))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17500))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17505)))), Msg__MsgDesc_GetLText)),Msg__MsgDesc_GetLText)((Msg__Msg)i0, (void*)(OOC_INT32)text, text_0d);
  return;
  ;
}

Msg__StringPtr Msg__GetStringPtr(const Msg__String str__ref, OOC_LEN str_0d) {
  register OOC_INT32 i0,i1;
  OOC_ALLOCATE_VPAR(str,OOC_CHAR8 ,str_0d)
  Msg__StringPtr s;

  OOC_INITIALIZE_VPAR(str__ref,str,OOC_CHAR8 ,str_0d)
  i0 = Strings__Length((void*)(OOC_INT32)str, str_0d);
  i0 = (OOC_INT32)RT0__NewObject(_td_Msg__StringPtr.baseTypes[0], (i0+1));
  s = (Msg__StringPtr)i0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 17866)), 0);
  _copy_8((const void*)(OOC_INT32)str,(void*)(_check_pointer(i0, 17866)),i1);
  return (Msg__StringPtr)i0;
  ;
}

Msg__LStringPtr Msg__GetLStringPtr(const Msg__LString str__ref, OOC_LEN str_0d) {
  register OOC_INT32 i0,i1;
  OOC_ALLOCATE_VPAR(str,OOC_CHAR16 ,str_0d)
  Msg__LStringPtr s;

  OOC_INITIALIZE_VPAR(str__ref,str,OOC_CHAR16 ,(str_0d*2))
  i0 = LongStrings__Length((void*)(OOC_INT32)str, str_0d);
  i0 = (OOC_INT32)RT0__NewObject(_td_Msg__LStringPtr.baseTypes[0], (i0+1));
  s = (Msg__LStringPtr)i0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 18126)), 0);
  _copy_16((const void*)(OOC_INT32)str,(void*)(_check_pointer(i0, 18126)),i1);
  return (Msg__LStringPtr)i0;
  ;
}

void OOC_Msg_init(void) {

  return;
  ;
}

void OOC_Msg_destroy(void) {
}

/* --- */
