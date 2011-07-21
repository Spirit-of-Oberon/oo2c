#include <OOC/SSA/XML.d>
#include <__oo2c.h>
#include <setjmp.h>

void OOC_SSA_XML__InitWriter(OOC_SSA_XML__Writer w, IO__ByteChannel cw) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)cw;
  i2 = (OOC_INT32)XML_UnicodeCodec_Latin1__factory;
  XML_Writer__Init((XML_Writer__Writer)i0, (IO__ByteChannel)i1, (XML_UnicodeCodec__Factory)i2, 1u, 2);
  i1 = (OOC_INT32)ADT_StringBuffer__New((Object__String)((OOC_INT32)_c0));
  *(OOC_INT32*)((_check_pointer(i0, 1578))+72) = i1;
  return;
  ;
}

OOC_SSA_XML__Writer OOC_SSA_XML__NewWriter(IO__ByteChannel cw) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_XML__Writer.baseTypes[0]);
  i1 = (OOC_INT32)cw;
  OOC_SSA_XML__InitWriter((OOC_SSA_XML__Writer)i0, (IO__ByteChannel)i1);
  return (OOC_SSA_XML__Writer)i0;
  ;
}

void OOC_SSA_XML__WriterDesc_WriteInstrAttr(OOC_SSA_XML__Writer w, OOC_SSA__Instr instr) {

  return;
  ;
}

void OOC_SSA_XML__WriterDesc_WriteInstrChildren(OOC_SSA_XML__Writer w, OOC_SSA__Instr instr) {

  return;
  ;
}

OOC_INT32 OOC_SSA_XML__WriterDesc_GetId(OOC_SSA_XML__Writer w, OOC_SSA__Result result) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2036))+76);
  i2 = (OOC_INT32)result;
  i1 = ADT_Dictionary_IntValue__DictionaryDesc_HasKey((ADT_Dictionary_IntValue__Dictionary)i1, (Object__Object)i2);
  if (i1) goto l3;
  return (-1);
  goto l4;
l3:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2085))+76);
  i0 = ADT_Dictionary_IntValue__DictionaryDesc_Get((ADT_Dictionary_IntValue__Dictionary)i0, (Object__Object)i2);
  return (_abs(i0));
l4:
  _failed_function(1983); return 0;
  ;
}

void OOC_SSA_XML__WriterDesc_AttrId(OOC_SSA_XML__Writer w, const OOC_CHAR16 name__ref[], OOC_LEN name_0d, OOC_SSA__Result result) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_ALLOCATE_VPAR(name,OOC_CHAR16 ,name_0d)
  OOC_CHAR8 str[64];
  OOC_INT32 countSameId;
  OOC_INT32 posSameId;
  OOC_SSA__Result res;

  OOC_INITIALIZE_VPAR(name__ref,name,OOC_CHAR16 ,(name_0d*2))
  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2337))+72);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2355))+72);
  i2 = *(OOC_INT32*)((_check_pointer(i2, 2359))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2337))+72);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2341)))), ADT_StringBuffer__StringBufferDesc_Delete)),ADT_StringBuffer__StringBufferDesc_Delete)((ADT_StringBuffer__StringBuffer)i3, 0, i2);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2375))+72);
  i2 = (OOC_INT32)result;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 2413))+8);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2375))+72);
  i3 = OOC_SSA_XML__WriterDesc_GetId((OOC_SSA_XML__Writer)i0, (OOC_SSA__Result)i3);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2379)))), ADT_StringBuffer__StringBufferDesc_AppendInt)),ADT_StringBuffer__StringBufferDesc_AppendInt)((ADT_StringBuffer__StringBuffer)i4, (_abs(i3)));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 2448))+8);
  i1 = i2!=i1;
  if (!i1) goto l19;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2469))+72);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2469))+72);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2473)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)),ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)((ADT_StringBuffer__StringBuffer)i3, 46u);
  i1 = *(OOC_INT8*)((_check_pointer(i2, 2527))+4);
  OOC_SSA_Result__GetName(i1, (void*)(OOC_INT32)str, 64);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2549))+72);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2549))+72);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2553)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i3, (void*)(OOC_INT32)str, 64);
  countSameId = 0;
  posSameId = 0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 2641))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 2648));
  res = (OOC_SSA__Result)i1;
  i3=0;i4=0;
l3_loop:
  i5 = i1==i2;
  if (!i5) goto l7;
  posSameId = i3;
  i4=i3;
l7:
  i5 = *(OOC_INT8*)((_check_pointer(i1, 2770))+4);
  i6 = *(OOC_INT8*)((_check_pointer(i2, 2786))+4);
  i5 = i5==i6;
  if (!i5) goto l11;
  i3 = i3+1;
  countSameId = i3;
  
l11:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 2859));
  res = (OOC_SSA__Result)i1;
  i5 = i1==0;
  if (!i5) goto l3_loop;
l15:
  i1 = i3!=1;
  if (!i1) goto l19;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2938))+72);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2938))+72);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2942)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)),ADT_StringBuffer__StringBufferDesc_AppendLatin1Char)((ADT_StringBuffer__StringBuffer)i2, 46u);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2977))+72);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2977))+72);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2981)))), ADT_StringBuffer__StringBufferDesc_AppendInt)),ADT_StringBuffer__StringBufferDesc_AppendInt)((ADT_StringBuffer__StringBuffer)i2, i4);
l19:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3051))+72);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3051))+72);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3055)))), ADT_StringBuffer__StringBufferDesc_ToString)),ADT_StringBuffer__StringBufferDesc_ToString)((ADT_StringBuffer__StringBuffer)i2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3031)))), XML_Writer__WriterDesc_AttrObject)),XML_Writer__WriterDesc_AttrObject)((XML_Writer__Writer)i0, (void*)(OOC_INT32)name, name_0d, (Object__String)i1);
  return;
  ;
}

void OOC_SSA_XML__WriterDesc_AttrRef(OOC_SSA_XML__Writer w, OOC_SSA__Result res) {
  register OOC_INT32 i0,i1,i2;
  Object__String value;

  i0 = (OOC_INT32)res;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l23;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3260)))), &_td_OOC_SSA__ConstDesc);
  if (i1) goto l13;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3615)))), &_td_OOC_SSA__DeclRefDesc);
  if (i1) goto l11;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3707)))), &_td_OOC_SSA__AddressDesc);
  if (i1) goto l9;
  i1 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3811)))), OOC_SSA_XML__WriterDesc_AttrId)),OOC_SSA_XML__WriterDesc_AttrId)((OOC_SSA_XML__Writer)i1, ((OOC_CHAR16[]){97,114,103,114,101,102,0}), 7, (OOC_SSA__Result)i0);
  goto l24;
l9:
  i1 = (OOC_INT32)w;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3770))+44);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 3776))+20);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 3782))+12);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3770))+44);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3776))+20);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3782))+12);
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 3787)), 0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3733)))), XML_Writer__WriterDesc_AttrStringLatin1)),XML_Writer__WriterDesc_AttrStringLatin1)((XML_Writer__Writer)i1, ((OOC_CHAR16[]){97,100,100,114,101,115,115,45,111,102,0}), 11, (void*)(_check_pointer(i2, 3787)), i0);
  goto l24;
l11:
  i1 = (OOC_INT32)w;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3675))+44);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 3681))+20);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 3687))+12);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3675))+44);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3681))+20);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3687))+12);
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 3692)), 0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3641)))), XML_Writer__WriterDesc_AttrStringLatin1)),XML_Writer__WriterDesc_AttrStringLatin1)((XML_Writer__Writer)i1, ((OOC_CHAR16[]){100,101,99,108,114,101,102,0}), 8, (void*)(_check_pointer(i2, 3692)), i0);
  goto l24;
l13:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3290))+44);
  i2 = (OOC_INT32)OOC_SSA__nil;
  i1 = i1==i2;
  if (i1) goto l16;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3375))+44);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3375))+44);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3382)))), Object_Boxed__ObjectDesc_ToString)),Object_Boxed__ObjectDesc_ToString)((Object_Boxed__Object)i0);
  value = (Object__String)i0;
  
  goto l17;
l16:
  i0 = (OOC_INT32)_c1;
  value = (Object__String)i0;
  
l17:
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3427)))), &_td_Object__String16Desc);
  if (i1) goto l20;
  i1 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3538)))), XML_Writer__WriterDesc_AttrObject)),XML_Writer__WriterDesc_AttrObject)((XML_Writer__Writer)i1, ((OOC_CHAR16[]){99,111,110,115,116,45,118,97,108,117,101,0}), 12, (Object__String)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3580)))), &_td_Object__String8Desc, 3580)));
  goto l24;
l20:
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3463)))), XML_Writer__WriterDesc_AttrObject)),XML_Writer__WriterDesc_AttrObject)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){99,111,110,115,116,45,118,97,108,117,101,0}), 12, (Object__String)((OOC_INT32)_c2));
  goto l24;
l23:
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3205)))), XML_Writer__WriterDesc_AttrString)),XML_Writer__WriterDesc_AttrString)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){97,114,103,114,101,102,0}), 7, ((OOC_CHAR16[]){78,73,76,0}), 4);
l24:
  return;
  ;
}

static OOC_CHAR8 OOC_SSA_XML__Omit(OOC_SSA__Instr instr) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)instr;
  i0 = OOC_SSA__InstrDesc_IsConst((OOC_SSA__Instr)i0);
  return i0;
  ;
}

void OOC_SSA_XML__WriterDesc_WriteInstr(OOC_SSA_XML__Writer w, OOC_SSA__Instr instr) {
  register OOC_INT32 i0,i1,i2,i3;
  Object__String value;
  OOC_SSA__Opnd opnd;
  OOC_SSA__Result res;
  auto void OOC_SSA_XML__WriterDesc_WriteInstr_StartTagInstr(XML_Writer__Writer w, OOC_SSA__Instr instr);
  auto void OOC_SSA_XML__WriterDesc_WriteInstr_WriteResult(OOC_SSA__Result res);
  auto void OOC_SSA_XML__WriterDesc_WriteInstr_WriteOpnd(OOC_SSA__Opnd opnd);
    
    void OOC_SSA_XML__WriterDesc_WriteInstr_StartTagInstr(XML_Writer__Writer w, OOC_SSA__Instr instr) {
      register OOC_INT32 i0,i1;
      OOC_CHAR8 str[64];

      i0 = (OOC_INT32)instr;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 4239))+36);
      i0 = *(OOC_INT8*)((_check_pointer(i0, 4254))+5);
      OOC_SSA_Opcode__GetName(i1, i0, (void*)(OOC_INT32)str, 64);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4279)))), XML_Writer__WriterDesc_StartTagLatin1)),XML_Writer__WriterDesc_StartTagLatin1)((XML_Writer__Writer)i0, (void*)(OOC_INT32)str, 64, 0u);
      return;
      ;
    }

    
    void OOC_SSA_XML__WriterDesc_WriteInstr_WriteResult(OOC_SSA__Result res) {
      register OOC_INT32 i0,i1;
      OOC_CHAR8 str[64];

      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4433)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){114,101,115,0}), 4, 0u);
      i0 = (OOC_INT32)w;
      i1 = (OOC_INT32)res;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4474)))), OOC_SSA_XML__WriterDesc_AttrId)),OOC_SSA_XML__WriterDesc_AttrId)((OOC_SSA_XML__Writer)i0, ((OOC_CHAR16[]){105,100,0}), 3, (OOC_SSA__Result)i1);
      i0 = *(OOC_INT8*)((_check_pointer(i1, 4528))+4);
      OOC_SSA_Result__GetName(i0, (void*)(OOC_INT32)str, 64);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4550)))), XML_Writer__WriterDesc_AttrStringLatin1)),XML_Writer__WriterDesc_AttrStringLatin1)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){99,108,97,115,115,0}), 6, (void*)(OOC_INT32)str, 64);
      i0 = *(OOC_INT8*)((_check_pointer(i1, 4599))+5);
      i0 = i0!=0;
      if (!i0) goto l3;
      i0 = *(OOC_INT8*)((_check_pointer(i1, 4667))+5);
      OOC_SSA_Opcode__GetSubclassName(i0, (void*)(OOC_INT32)str, 64);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4694)))), XML_Writer__WriterDesc_AttrStringLatin1)),XML_Writer__WriterDesc_AttrStringLatin1)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){115,117,98,99,108,97,115,115,0}), 9, (void*)(OOC_INT32)str, 64);
l3:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4757)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i0);
      return;
      ;
    }

    
    void OOC_SSA_XML__WriterDesc_WriteInstr_WriteOpnd(OOC_SSA__Opnd opnd) {
      register OOC_INT32 i0,i1;
      OOC_CHAR8 str[64];

      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4896)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){111,112,110,100,0}), 5, 0u);
      i0 = (OOC_INT32)opnd;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 4955))+4);
      OOC_SSA_Opnd__GetName(i1, (void*)(OOC_INT32)str, 64);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4977)))), XML_Writer__WriterDesc_AttrStringLatin1)),XML_Writer__WriterDesc_AttrStringLatin1)((XML_Writer__Writer)i1, ((OOC_CHAR16[]){99,108,97,115,115,0}), 6, (void*)(OOC_INT32)str, 64);
      i1 = (OOC_INT32)w;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5034));
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5019)))), OOC_SSA_XML__WriterDesc_AttrRef)),OOC_SSA_XML__WriterDesc_AttrRef)((OOC_SSA_XML__Writer)i1, (OOC_SSA__Result)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5049)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i0);
      return;
      ;
    }


  i0 = (OOC_INT32)instr;
  i1 = OOC_SSA_XML__Omit((OOC_SSA__Instr)i0);
  if (!i1) goto l3;
  return;
l3:
  i1 = (OOC_INT32)w;
  OOC_SSA_XML__WriterDesc_WriteInstr_StartTagInstr((XML_Writer__Writer)i1, (OOC_SSA__Instr)i0);
  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)instr;
  i2 = OOC_SSA_XML__WriterDesc_GetId((OOC_SSA_XML__Writer)i0, (OOC_SSA__Result)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5374)))), XML_Writer__WriterDesc_AttrInt)),XML_Writer__WriterDesc_AttrInt)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){105,100,0}), 3, i2);
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5429)))), &_td_OOC_SSA__ConstDesc);
  if (i2) goto l9;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5646)))), &_td_OOC_SSA__AddressDesc);
  if (!i2) goto l14;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5709))+44);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 5715))+20);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 5721))+12);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5709))+44);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 5715))+20);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 5721))+12);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 5726)), 0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5670)))), XML_Writer__WriterDesc_AttrStringLatin1)),XML_Writer__WriterDesc_AttrStringLatin1)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){97,100,100,114,101,115,115,45,111,102,0}), 11, (void*)(_check_pointer(i2, 5726)), i3);
  goto l14;
l9:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5459))+44);
  i3 = (OOC_INT32)OOC_SSA__nil;
  i2 = i2==i3;
  if (i2) goto l12;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5540))+44);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5540))+44);
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 5547)))), Object_Boxed__ObjectDesc_ToString)),Object_Boxed__ObjectDesc_ToString)((Object_Boxed__Object)i3);
  value = (Object__String)i2;
  
  goto l13;
l12:
  i2 = (OOC_INT32)_c3;
  value = (Object__String)i2;
  
l13:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5587)))), XML_Writer__WriterDesc_AttrObject)),XML_Writer__WriterDesc_AttrObject)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){118,97,108,117,101,0}), 6, (Object__String)(_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 5623)))), &_td_Object__String8Desc, 5623)));
l14:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5753)))), OOC_SSA_XML__WriterDesc_WriteInstrAttr)),OOC_SSA_XML__WriterDesc_WriteInstrAttr)((OOC_SSA_XML__Writer)i0, (OOC_SSA__Instr)i1);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5801))+24);
  opnd = (OOC_SSA__Opnd)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l22;
l17_loop:
  OOC_SSA_XML__WriterDesc_WriteInstr_WriteOpnd((OOC_SSA__Opnd)i0);
  i0 = (OOC_INT32)opnd;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5881))+8);
  opnd = (OOC_SSA__Opnd)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l17_loop;
l22:
  i0 = (OOC_INT32)instr;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5922));
  res = (OOC_SSA__Result)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l30;
l25_loop:
  OOC_SSA_XML__WriterDesc_WriteInstr_WriteResult((OOC_SSA__Result)i0);
  i0 = (OOC_INT32)res;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6002));
  res = (OOC_SSA__Result)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l25_loop;
l30:
  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)instr;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6034)))), OOC_SSA_XML__WriterDesc_WriteInstrChildren)),OOC_SSA_XML__WriterDesc_WriteInstrChildren)((OOC_SSA_XML__Writer)i0, (OOC_SSA__Instr)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6069)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i0);
  return;
  ;
}

void OOC_SSA_XML__WriterDesc_WriteProcBody(OOC_SSA_XML__Writer w, OOC_SSA__ProcBlock pb, OOC_CHAR8 includeDeadCode) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_INT32 instrCount;
  OOC_SSA__Instr instr;
  auto void OOC_SSA_XML__WriterDesc_WriteProcBody_AssignId(OOC_SSA__Instr instr);
  auto void OOC_SSA_XML__WriterDesc_WriteProcBody_TraverseInstr(OOC_SSA__Instr instr);
    
    void OOC_SSA_XML__WriterDesc_WriteProcBody_AssignId(OOC_SSA__Instr instr) {
      register OOC_INT32 i0,i1,i2;
      OOC_SSA__Opnd opnd;

      i0 = (OOC_INT32)w;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6399))+76);
      i1 = (OOC_INT32)instr;
      i0 = ADT_Dictionary_IntValue__DictionaryDesc_HasKey((ADT_Dictionary_IntValue__Dictionary)i0, (Object__Object)i1);
      i0 = !i0;
      if (!i0) goto l22;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6545))+24);
      opnd = (OOC_SSA__Opnd)i0;
      i2 = i0!=(OOC_INT32)0;
      if (!i2) goto l10;
l5_loop:
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6611));
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 6616))+8);
      OOC_SSA_XML__WriterDesc_WriteProcBody_AssignId((OOC_SSA__Instr)i2);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6648))+8);
      opnd = (OOC_SSA__Opnd)i0;
      i2 = i0!=(OOC_INT32)0;
      if (i2) goto l5_loop;
l10:
      i0 = OOC_SSA_XML__Omit((OOC_SSA__Instr)i1);
      i0 = !i0;
      if (!i0) goto l13;
      i0 = (OOC_INT32)w;
      i2 = instrCount;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6722))+76);
      ADT_Dictionary_IntValue__DictionaryDesc_Set((ADT_Dictionary_IntValue__Dictionary)i0, (Object__Object)i1, (-i2));
      i0 = instrCount;
      instrCount = (i0+1);
l13:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6828))+24);
      opnd = (OOC_SSA__Opnd)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l22;
l16_loop:
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6894));
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6899))+8);
      OOC_SSA_XML__WriterDesc_WriteProcBody_AssignId((OOC_SSA__Instr)i1);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6931))+8);
      opnd = (OOC_SSA__Opnd)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l16_loop;
l22:
      return;
      ;
    }

    
    void OOC_SSA_XML__WriterDesc_WriteProcBody_TraverseInstr(OOC_SSA__Instr instr) {
      register OOC_INT32 i0,i1,i2;
      OOC_INT32 id;
      OOC_SSA__Result backwardFeed;
      OOC_SSA__Opnd opnd;

      i0 = (OOC_INT32)instr;
      i1 = OOC_SSA_XML__Omit((OOC_SSA__Instr)i0);
      i1 = !i1;
      if (!i1) goto l18;
      i1 = (OOC_INT32)w;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 7169))+76);
      i1 = ADT_Dictionary_IntValue__DictionaryDesc_Get((ADT_Dictionary_IntValue__Dictionary)i1, (Object__Object)i0);
      id = i1;
      i2 = i1<0;
      if (!i2) goto l18;
      i2 = (OOC_INT32)w;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7270))+76);
      ADT_Dictionary_IntValue__DictionaryDesc_Set((ADT_Dictionary_IntValue__Dictionary)i2, (Object__Object)i0, (-i1));
      i1 = *(OOC_INT8*)((_check_pointer(i0, 7341))+36);
      i1 = i1==10;
      if (i1) goto l15;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7850))+24);
      opnd = (OOC_SSA__Opnd)i1;
      i2 = i1!=0;
      if (!i2) goto l14;
l9_loop:
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 7929));
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7934))+8);
      OOC_SSA_XML__WriterDesc_WriteProcBody_TraverseInstr((OOC_SSA__Instr)i2);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 7970))+8);
      opnd = (OOC_SSA__Opnd)i1;
      i2 = i1!=0;
      if (i2) goto l9_loop;
l14:
      i1 = (OOC_INT32)w;
      OOC_SSA_XML__WriterDesc_WriteInstr((OOC_SSA_XML__Writer)i1, (OOC_SSA__Instr)i0);
      goto l18;
l15:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7569))+24);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 7579));
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 7584))+8);
      OOC_SSA_XML__WriterDesc_WriteProcBody_TraverseInstr((OOC_SSA__Instr)i1);
      i1 = (OOC_INT32)w;
      OOC_SSA_XML__WriterDesc_WriteInstr((OOC_SSA_XML__Writer)i1, (OOC_SSA__Instr)i0);
      i0 = (OOC_INT32)OOC_SSA__InstrDesc_GetBackwardFeed((OOC_SSA__Instr)i0);
      backwardFeed = (OOC_SSA__Result)i0;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7722))+8);
      OOC_SSA_XML__WriterDesc_WriteProcBody_TraverseInstr((OOC_SSA__Instr)i0);
l18:
      return;
      ;
    }


  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8111)))), XML_Writer__WriterDesc_WriteTextDecl)),XML_Writer__WriterDesc_WriteTextDecl)((XML_Writer__Writer)i0, "1.0", 4, "no", 3);
  i1 = (OOC_INT32)ADT_Dictionary_IntValue__New();
  *(OOC_INT32*)((_check_pointer(i0, 8271))+76) = i1;
  instrCount = 1;
  i0 = (OOC_INT32)pb;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 8337));
  OOC_SSA_XML__WriterDesc_WriteProcBody_AssignId((OOC_SSA__Instr)i0);
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8364)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){112,114,111,99,101,100,117,114,101,45,98,111,100,121,0}), 15, 0u);
  i1 = (OOC_INT32)pb;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8437))+20);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 8447))+20);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 8453))+12);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8437))+20);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 8447))+20);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 8453))+12);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 8458)), 0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8407)))), XML_Writer__WriterDesc_AttrStringLatin1)),XML_Writer__WriterDesc_AttrStringLatin1)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){110,97,109,101,0}), 5, (void*)(_check_pointer(i2, 8458)), i3);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 8483));
  OOC_SSA_XML__WriterDesc_WriteProcBody_TraverseInstr((OOC_SSA__Instr)i0);
  i0 = includeDeadCode;
  if (!i0) goto l14;
  i0 = (OOC_INT32)pb;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8652))+12);
  instr = (OOC_SSA__Instr)i0;
  i1 = i0!=0;
  if (!i1) goto l14;
l5_loop:
  i1 = (OOC_INT32)w;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8707))+76);
  i1 = ADT_Dictionary_IntValue__DictionaryDesc_HasKey((ADT_Dictionary_IntValue__Dictionary)i1, (Object__Object)i0);
  i1 = !i1;
  if (!i1) goto l8;
  OOC_SSA_XML__WriterDesc_WriteProcBody_AssignId((OOC_SSA__Instr)i0);
  i0 = (OOC_INT32)instr;
  OOC_SSA_XML__WriterDesc_WriteProcBody_TraverseInstr((OOC_SSA__Instr)i0);
l8:
  i0 = (OOC_INT32)instr;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8832))+28);
  instr = (OOC_SSA__Instr)i0;
  i1 = i0!=0;
  if (i1) goto l5_loop;
l14:
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8869)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8906)))), XML_Writer__WriterDesc_EndOfText)),XML_Writer__WriterDesc_EndOfText)((XML_Writer__Writer)i0);
  return;
  ;
}

void OOC_SSA_XML__Write(IO__ByteChannel cw, OOC_SSA__ProcBlock pb, OOC_CHAR8 includeDeadCode) {
  register OOC_INT32 i0,i1,i2;
  OOC_SSA_XML__Writer w;

  i0 = (OOC_INT32)cw;
  i0 = (OOC_INT32)OOC_SSA_XML__NewWriter((IO__ByteChannel)i0);
  w = (OOC_SSA_XML__Writer)i0;
  i1 = (OOC_INT32)pb;
  i2 = includeDeadCode;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9406)))), OOC_SSA_XML__WriterDesc_WriteProcBody)),OOC_SSA_XML__WriterDesc_WriteProcBody)((OOC_SSA_XML__Writer)i0, (OOC_SSA__ProcBlock)i1, i2);
  return;
  ;
}

void OOC_SSA_XML__ToStderr(volatile OOC_SSA__ProcBlock pb) {
  register OOC_INT32 i0,i1;
  jmp_buf _target0;
  Exception__Context _context0;

  {
    Exception__PushContext(&_context0, &_target0);
    if (!setjmp(_target0)) goto l6;
    Exception__PopContext(1);
    i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG(((OOC_INT32)Exception__Current()))), &_td_IO__ErrorDesc);
    if (i0) goto l5;
    Exception__ActivateContext();
l5:
    Exception__Clear();
    goto l7;
l6:
    i0 = (OOC_INT32)IO_StdChannels__stderr;
    i1 = (OOC_INT32)pb;
    OOC_SSA_XML__Write((IO__ByteChannel)i0, (OOC_SSA__ProcBlock)i1, 1u);
    Exception__PopContext(1);
l7:;
  }
  return;
  ;
}

void OOC_SSA_XML__WriterDesc_WriteSchedule(OOC_SSA_XML__Writer w, OOC_SSA_Schedule__Block domRoot) {
  register OOC_INT32 i0,i1;
  OOC_INT32 instrCount;
  auto void OOC_SSA_XML__WriterDesc_WriteSchedule_WriteBlock(OOC_SSA_Schedule__Block b);
  auto void OOC_SSA_XML__WriterDesc_WriteSchedule_AssignIds(OOC_SSA_Schedule__Block b);
    
    void OOC_SSA_XML__WriterDesc_WriteSchedule_WriteBlock(OOC_SSA_Schedule__Block b) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_SSA_Schedule__InstrProxy proxy;
      OOC_SSA_Schedule__Block nested;

      i0 = (OOC_INT32)b;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9858)))), &_td_OOC_SSA_Schedule__BranchBlockDesc);
      if (i1) goto l3;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9948)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i1, ((OOC_CHAR16[]){98,108,111,99,107,0}), 6, 0u);
      goto l4;
l3:
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9893)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i1, ((OOC_CHAR16[]){98,108,111,99,107,45,98,114,97,110,99,104,0}), 13, 0u);
l4:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10010))+8);
      proxy = (OOC_SSA_Schedule__InstrProxy)i1;
      i2 = i1!=(OOC_INT32)0;
      if (!i2) goto l12;
l7_loop:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10080))+12);
      i3 = (OOC_INT32)w;
      OOC_SSA_XML__WriterDesc_WriteInstr((OOC_SSA_XML__Writer)i3, (OOC_SSA__Instr)i2);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 10112));
      proxy = (OOC_SSA_Schedule__InstrProxy)i1;
      i2 = i1!=(OOC_INT32)0;
      if (i2) goto l7_loop;
l12:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10153))+16);
      nested = (OOC_SSA_Schedule__Block)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l20;
l15_loop:
      OOC_SSA_XML__WriterDesc_WriteSchedule_WriteBlock((OOC_SSA_Schedule__Block)i0);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10247));
      nested = (OOC_SSA_Schedule__Block)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l15_loop;
l20:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10276)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i0);
      return;
      ;
    }

    
    void OOC_SSA_XML__WriterDesc_WriteSchedule_AssignIds(OOC_SSA_Schedule__Block b) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      OOC_SSA_Schedule__InstrProxy proxy;
      OOC_SSA_Schedule__Block nested;

      i0 = (OOC_INT32)b;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10461))+8);
      proxy = (OOC_SSA_Schedule__InstrProxy)i1;
      i2 = i1!=(OOC_INT32)0;
      if (!i2) goto l11;
l3_loop:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10526))+12);
      i2 = OOC_SSA_XML__Omit((OOC_SSA__Instr)i2);
      i2 = !i2;
      if (!i2) goto l6;
      i2 = (OOC_INT32)w;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 10551))+76);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10570))+12);
      i4 = instrCount;
      ADT_Dictionary_IntValue__DictionaryDesc_Set((ADT_Dictionary_IntValue__Dictionary)i2, (Object__Object)i3, i4);
      i2 = instrCount;
      instrCount = (i2+1);
l6:
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 10655));
      proxy = (OOC_SSA_Schedule__InstrProxy)i1;
      i2 = i1!=(OOC_INT32)0;
      if (i2) goto l3_loop;
l11:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10696))+16);
      nested = (OOC_SSA_Schedule__Block)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l19;
l14_loop:
      OOC_SSA_XML__WriterDesc_WriteSchedule_AssignIds((OOC_SSA_Schedule__Block)i0);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10789));
      nested = (OOC_SSA_Schedule__Block)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l14_loop;
l19:
      return;
      ;
    }


  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10845)))), XML_Writer__WriterDesc_WriteTextDecl)),XML_Writer__WriterDesc_WriteTextDecl)((XML_Writer__Writer)i0, "1.0", 4, "no", 3);
  i1 = (OOC_INT32)ADT_Dictionary_IntValue__New();
  *(OOC_INT32*)((_check_pointer(i0, 10882))+76) = i1;
  instrCount = 1;
  i0 = (OOC_INT32)domRoot;
  OOC_SSA_XML__WriterDesc_WriteSchedule_AssignIds((OOC_SSA_Schedule__Block)i0);
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10967)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i0, ((OOC_CHAR16[]){115,99,104,101,100,117,108,101,0}), 9, 0u);
  i0 = (OOC_INT32)domRoot;
  OOC_SSA_XML__WriterDesc_WriteSchedule_WriteBlock((OOC_SSA_Schedule__Block)i0);
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11030)))), XML_Writer__WriterDesc_EndTag)),XML_Writer__WriterDesc_EndTag)((XML_Writer__Writer)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11061)))), XML_Writer__WriterDesc_EndOfText)),XML_Writer__WriterDesc_EndOfText)((XML_Writer__Writer)i0);
  return;
  ;
}

void OOC_SSA_XML__WriteSchedule(IO__ByteChannel cw, OOC_SSA_Schedule__Block domRoot) {
  register OOC_INT32 i0,i1;
  OOC_SSA_XML__Writer w;

  i0 = (OOC_INT32)cw;
  i0 = (OOC_INT32)OOC_SSA_XML__NewWriter((IO__ByteChannel)i0);
  w = (OOC_SSA_XML__Writer)i0;
  i1 = (OOC_INT32)domRoot;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11242)))), OOC_SSA_XML__WriterDesc_WriteSchedule)),OOC_SSA_XML__WriterDesc_WriteSchedule)((OOC_SSA_XML__Writer)i0, (OOC_SSA_Schedule__Block)i1);
  return;
  ;
}

void OOC_OOC_SSA_XML_init(void) {
  _c0 = Object__NewLatin1Region("", 1, 0, 0);
  _c1 = Object__NewLatin1Region("NIL", 4, 0, 3);
  _c2 = Object__NewLatin1Region("[Object.String16]", 18, 0, 17);
  _c3 = Object__NewLatin1Region("NIL", 4, 0, 3);

  return;
  ;
}

/* --- */
