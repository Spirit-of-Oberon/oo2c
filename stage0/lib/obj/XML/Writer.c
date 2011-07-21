#include <XML/Writer.d>
#include <__oo2c.h>
#include <setjmp.h>

void XML_Writer__Init(XML_Writer__Writer w, IO__ByteChannel writer, XML_UnicodeCodec__Factory codecFactory, OOC_CHAR8 writeBOM, OOC_INT32 indentLevel) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = writeBOM;
  i1 = (OOC_INT32)codecFactory;
  i2 = (OOC_INT32)writer;
  i3 = (OOC_INT32)w;
  XML_UnicodeBuffer__InitOutput((XML_UnicodeBuffer__Output)i3, 1u, (IO__ByteChannel)i2, (XML_UnicodeCodec__Factory)i1, i0);
  *(OOC_INT32*)((_check_pointer(i3, 2403))+60) = ((OOC_INT32)RT0__NewObject(_td_XML_Writer__Elements.baseTypes[0], 8));
  i0 = indentLevel;
  *(OOC_INT32*)((_check_pointer(i3, 2433))+36) = i0;
  *(OOC_INT32*)((_check_pointer(i3, 2468))+40) = 0;
  *(OOC_UINT8*)((_check_pointer(i3, 2488))+52) = 0u;
  *(OOC_INT32*)((_check_pointer(i3, 2522))+56) = (OOC_INT32)0;
  _copy_8((const void*)"\012",(void*)((_check_pointer(i3, 2545))+44),3);
  *(OOC_INT32*)((_check_pointer(i3, 2573))+48) = 1;
  *(OOC_INT32*)((_check_pointer(i3, 2602))+64) = 0;
  *(OOC_UINT8*)((_check_pointer(i3, 2631))+68) = 0u;
  *(OOC_UINT8*)((_check_pointer(i3, 2707))+69) = 0u;
  *(OOC_UINT8*)((_check_pointer(i3, 2737))+70) = 0u;
  return;
  ;
}

XML_Writer__Writer XML_Writer__New(IO__ByteChannel writer, XML_UnicodeCodec__Factory codecFactory, OOC_CHAR8 writeBOM, OOC_INT32 indentLevel) {
  register OOC_INT32 i0,i1,i2,i3,i4;

  i0 = (OOC_INT32)RT0__NewObject(_td_XML_Writer__Writer.baseTypes[0]);
  i1 = indentLevel;
  i2 = writeBOM;
  i3 = (OOC_INT32)codecFactory;
  i4 = (OOC_INT32)writer;
  XML_Writer__Init((XML_Writer__Writer)i0, (IO__ByteChannel)i4, (XML_UnicodeCodec__Factory)i3, i2, i1);
  return (XML_Writer__Writer)i0;
  ;
}

void XML_Writer__WriterDesc_SetBaseURI(XML_Writer__Writer w, URI__HierarchicalURI baseURI) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)baseURI;
  *(OOC_INT32*)((_check_pointer(i0, 3422))+56) = i1;
  return;
  ;
}

void XML_Writer__WriterDesc_SetEmptyElementHTML(XML_Writer__Writer w, OOC_CHAR8 html) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)w;
  i1 = html;
  *(OOC_UINT8*)((_check_pointer(i0, 3535))+52) = i1;
  return;
  ;
}

void XML_Writer__WriterDesc_WriteTextDecl(XML_Writer__Writer w, const OOC_CHAR8 version__ref[], OOC_LEN version_0d, const OOC_CHAR8 standalone__ref[], OOC_LEN standalone_0d) {
  register OOC_INT32 i0,i1,i2;
  OOC_ALLOCATE_VPAR(version,OOC_CHAR8 ,version_0d)
  OOC_ALLOCATE_VPAR(standalone,OOC_CHAR8 ,standalone_0d)
  OOC_CHAR8 encoding[256];

  OOC_INITIALIZE_VPAR(version__ref,version,OOC_CHAR8 ,version_0d)
  OOC_INITIALIZE_VPAR(standalone__ref,standalone,OOC_CHAR8 ,standalone_0d)
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3717)))), XML_UnicodeBuffer__OutputDesc_Write8)),XML_UnicodeBuffer__OutputDesc_Write8)((XML_UnicodeBuffer__Output)i0, "<?xml", 6);
  i1 = (
  _cmp8((const void*)(OOC_INT32)version,(const void*)""))!=0;
  if (!i1) goto l3;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3771)))), XML_UnicodeBuffer__OutputDesc_Write8)),XML_UnicodeBuffer__OutputDesc_Write8)((XML_UnicodeBuffer__Output)i0, " version=\047", 11);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3803)))), XML_UnicodeBuffer__OutputDesc_Write8)),XML_UnicodeBuffer__OutputDesc_Write8)((XML_UnicodeBuffer__Output)i0, (void*)(OOC_INT32)version, version_0d);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3830)))), XML_UnicodeBuffer__OutputDesc_Write8)),XML_UnicodeBuffer__OutputDesc_Write8)((XML_UnicodeBuffer__Output)i0, "\047", 2);
l3:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3859)))), XML_UnicodeBuffer__OutputDesc_Write8)),XML_UnicodeBuffer__OutputDesc_Write8)((XML_UnicodeBuffer__Output)i0, " encoding=\047", 12);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3890));
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3890));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3904)))), XML_UnicodeCodec__FactoryDesc_GetEncodingName)),XML_UnicodeCodec__FactoryDesc_GetEncodingName)((XML_UnicodeCodec__Factory)i2, (void*)(OOC_INT32)encoding, 256);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3939)))), XML_UnicodeBuffer__OutputDesc_Write8)),XML_UnicodeBuffer__OutputDesc_Write8)((XML_UnicodeBuffer__Output)i0, (void*)(OOC_INT32)encoding, 256);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3965)))), XML_UnicodeBuffer__OutputDesc_Write8)),XML_UnicodeBuffer__OutputDesc_Write8)((XML_UnicodeBuffer__Output)i0, "\047", 2);
  i1 = (
  _cmp8((const void*)(OOC_INT32)standalone,(const void*)""))!=0;
  if (!i1) goto l6;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4018)))), XML_UnicodeBuffer__OutputDesc_Write8)),XML_UnicodeBuffer__OutputDesc_Write8)((XML_UnicodeBuffer__Output)i0, " standalone=\047", 14);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4053)))), XML_UnicodeBuffer__OutputDesc_Write8)),XML_UnicodeBuffer__OutputDesc_Write8)((XML_UnicodeBuffer__Output)i0, (void*)(OOC_INT32)standalone, standalone_0d);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4083)))), XML_UnicodeBuffer__OutputDesc_Write8)),XML_UnicodeBuffer__OutputDesc_Write8)((XML_UnicodeBuffer__Output)i0, "\047", 2);
l6:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4112)))), XML_UnicodeBuffer__OutputDesc_Write8)),XML_UnicodeBuffer__OutputDesc_Write8)((XML_UnicodeBuffer__Output)i0, "?>", 3);
  i1 = *(OOC_INT32*)((_check_pointer(i0, 4150))+36);
  *(OOC_UINT8*)((_check_pointer(i0, 4134))+68) = (i1>=0);
  return;
  ;
}

void XML_Writer__WriterDesc_NewLine(XML_Writer__Writer w) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_INT32 i;

  i0 = (OOC_INT32)w;
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 4262))+68);
  if (!i1) goto l11;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 4312))+48);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4285)))), XML_UnicodeBuffer__OutputDesc_Write8I)),XML_UnicodeBuffer__OutputDesc_Write8I)((XML_UnicodeBuffer__Output)i0, (void*)((_check_pointer(i0, 4297))+44), 3, 0, i1);
  i = 1;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 4348))+40);
  i2 = 1<=i1;
  if (!i2) goto l11;
  i2=1;
l5_loop:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4369)))), XML_UnicodeBuffer__OutputDesc_Write8)),XML_UnicodeBuffer__OutputDesc_Write8)((XML_UnicodeBuffer__Output)i0, " ", 2);
  i2 = i2+1;
  i = i2;
  i3 = i2<=i1;
  if (i3) goto l5_loop;
l11:
  return;
  ;
}

void XML_Writer__WriterDesc_CloseStartTag(XML_Writer__Writer w) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)w;
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 4478))+69);
  _assert(i1, 127, 4469);
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 4503))+70);
  if (i1) goto l3;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4677)))), XML_UnicodeBuffer__OutputDesc_Write8)),XML_UnicodeBuffer__OutputDesc_Write8)((XML_UnicodeBuffer__Output)i0, ">", 2);
  goto l8;
l3:
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 4533))+52);
  if (i1) goto l6;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4603)))), XML_UnicodeBuffer__OutputDesc_Write8)),XML_UnicodeBuffer__OutputDesc_Write8)((XML_UnicodeBuffer__Output)i0, "/>", 3);
  goto l7;
l6:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4566)))), XML_UnicodeBuffer__OutputDesc_Write8)),XML_UnicodeBuffer__OutputDesc_Write8)((XML_UnicodeBuffer__Output)i0, " />", 4);
l7:
  *(OOC_UINT8*)((_check_pointer(i0, 4637))+70) = 0u;
l8:
  *(OOC_UINT8*)((_check_pointer(i0, 4706))+69) = 0u;
  return;
  ;
}

void XML_Writer__WriterDesc_WriteI(XML_Writer__Writer w, const OOC_CHAR16 str[], OOC_LEN str_0d, OOC_INT32 s, OOC_INT32 e) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT32 last;

  i0 = (OOC_INT32)w;
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 4870))+69);
  if (!i1) goto l3;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4891)))), XML_Writer__WriterDesc_CloseStartTag)),XML_Writer__WriterDesc_CloseStartTag)((XML_Writer__Writer)i0);
l3:
  i1 = s;
  i2 = e;
  i1 = i1!=i2;
  if (!i1) goto l51;
l6_loop:
  i1 = s;
  last = i1;
  i3 = i1!=i2;
  if (i3) goto l9;
  i3=0u;
  goto l11;
l9:
  i3 = *(OOC_UINT16*)((OOC_INT32)str+(_check_index(i1, str_0d, OOC_UINT32, 4988))*2);
  i3 = i3!=38u;
  
l11:
  if (i3) goto l13;
  i3=0u;
  goto l15;
l13:
  i3 = *(OOC_UINT16*)((OOC_INT32)str+(_check_index(i1, str_0d, OOC_UINT32, 5005))*2);
  i3 = i3!=60u;
  
l15:
  if (i3) goto l17;
  i3=0u;
  goto l19;
l17:
  i3 = *(OOC_UINT16*)((OOC_INT32)str+(_check_index(i1, str_0d, OOC_UINT32, 5022))*2);
  i3 = i3!=62u;
  
l19:
  if (!i3) goto l37;
l20_loop:
  i3 = s;
  i3 = i3+1;
  s = i3;
  i4 = i3!=i2;
  if (i4) goto l23;
  i4=0u;
  goto l25;
l23:
  i4 = *(OOC_UINT16*)((OOC_INT32)str+(_check_index(i3, str_0d, OOC_UINT32, 4988))*2);
  i4 = i4!=38u;
  
l25:
  if (i4) goto l27;
  i4=0u;
  goto l29;
l27:
  i4 = *(OOC_UINT16*)((OOC_INT32)str+(_check_index(i3, str_0d, OOC_UINT32, 5005))*2);
  i4 = i4!=60u;
  
l29:
  if (i4) goto l31;
  i3=0u;
  goto l33;
l31:
  i3 = *(OOC_UINT16*)((OOC_INT32)str+(_check_index(i3, str_0d, OOC_UINT32, 5022))*2);
  i3 = i3!=62u;
  
l33:
  if (i3) goto l20_loop;
l37:
  i3 = s;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5070)))), XML_UnicodeBuffer__OutputDesc_Write16I)),XML_UnicodeBuffer__OutputDesc_Write16I)((XML_UnicodeBuffer__Output)i0, (void*)(OOC_INT32)str, str_0d, i1, i3);
  i1 = i3!=i2;
  if (!i1) goto l46;
  i1 = *(OOC_UINT16*)((OOC_INT32)str+(_check_index(i3, str_0d, OOC_UINT32, 5135))*2);
  switch (i1) {
  case 38u:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5158)))), XML_UnicodeBuffer__OutputDesc_Write8)),XML_UnicodeBuffer__OutputDesc_Write8)((XML_UnicodeBuffer__Output)i0, "&amp;", 6);
    goto l45;
  case 60u:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5193)))), XML_UnicodeBuffer__OutputDesc_Write8)),XML_UnicodeBuffer__OutputDesc_Write8)((XML_UnicodeBuffer__Output)i0, "&lt;", 5);
    goto l45;
  case 62u:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5227)))), XML_UnicodeBuffer__OutputDesc_Write8)),XML_UnicodeBuffer__OutputDesc_Write8)((XML_UnicodeBuffer__Output)i0, "&gt;", 5);
    goto l45;
  default:
    _failed_case(i1, 5127);
    goto l45;
  }
l45:
  s = (i3+1);
l46:
  i1 = s;
  i1 = i1!=i2;
  if (i1) goto l6_loop;
l51:
  return;
  ;
}

void XML_Writer__WriterDesc_WriteLatin1I(XML_Writer__Writer w, const OOC_CHAR8 str[], OOC_LEN str_0d, OOC_INT32 s, OOC_INT32 e) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT32 last;

  i0 = (OOC_INT32)w;
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 5467))+69);
  if (!i1) goto l3;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5488)))), XML_Writer__WriterDesc_CloseStartTag)),XML_Writer__WriterDesc_CloseStartTag)((XML_Writer__Writer)i0);
l3:
  i1 = s;
  i2 = e;
  i1 = i1!=i2;
  if (!i1) goto l51;
l6_loop:
  i1 = s;
  last = i1;
  i3 = i1!=i2;
  if (i3) goto l9;
  i3=0u;
  goto l11;
l9:
  i3 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i1, str_0d, OOC_UINT32, 5585)));
  i3 = i3!=38u;
  
l11:
  if (i3) goto l13;
  i3=0u;
  goto l15;
l13:
  i3 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i1, str_0d, OOC_UINT32, 5602)));
  i3 = i3!=60u;
  
l15:
  if (i3) goto l17;
  i3=0u;
  goto l19;
l17:
  i3 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i1, str_0d, OOC_UINT32, 5619)));
  i3 = i3!=62u;
  
l19:
  if (!i3) goto l37;
l20_loop:
  i3 = s;
  i3 = i3+1;
  s = i3;
  i4 = i3!=i2;
  if (i4) goto l23;
  i4=0u;
  goto l25;
l23:
  i4 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i3, str_0d, OOC_UINT32, 5585)));
  i4 = i4!=38u;
  
l25:
  if (i4) goto l27;
  i4=0u;
  goto l29;
l27:
  i4 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i3, str_0d, OOC_UINT32, 5602)));
  i4 = i4!=60u;
  
l29:
  if (i4) goto l31;
  i3=0u;
  goto l33;
l31:
  i3 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i3, str_0d, OOC_UINT32, 5619)));
  i3 = i3!=62u;
  
l33:
  if (i3) goto l20_loop;
l37:
  i3 = s;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5667)))), XML_UnicodeBuffer__OutputDesc_Write8I)),XML_UnicodeBuffer__OutputDesc_Write8I)((XML_UnicodeBuffer__Output)i0, (void*)(OOC_INT32)str, str_0d, i1, i3);
  i1 = i3!=i2;
  if (!i1) goto l46;
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i3, str_0d, OOC_UINT32, 5731)));
  switch (i1) {
  case 38u:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5754)))), XML_UnicodeBuffer__OutputDesc_Write8)),XML_UnicodeBuffer__OutputDesc_Write8)((XML_UnicodeBuffer__Output)i0, "&amp;", 6);
    goto l45;
  case 60u:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5789)))), XML_UnicodeBuffer__OutputDesc_Write8)),XML_UnicodeBuffer__OutputDesc_Write8)((XML_UnicodeBuffer__Output)i0, "&lt;", 5);
    goto l45;
  case 62u:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5823)))), XML_UnicodeBuffer__OutputDesc_Write8)),XML_UnicodeBuffer__OutputDesc_Write8)((XML_UnicodeBuffer__Output)i0, "&gt;", 5);
    goto l45;
  default:
    _failed_case(i1, 5723);
    goto l45;
  }
l45:
  s = (i3+1);
l46:
  i1 = s;
  i1 = i1!=i2;
  if (i1) goto l6_loop;
l51:
  return;
  ;
}

void XML_Writer__WriterDesc_Write(XML_Writer__Writer w, const OOC_CHAR16 str[], OOC_LEN str_0d) {
  register OOC_INT32 i0,i1;

  i0 = LongStrings__Length((void*)(OOC_INT32)str, str_0d);
  i1 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5982)))), XML_Writer__WriterDesc_WriteI)),XML_Writer__WriterDesc_WriteI)((XML_Writer__Writer)i1, (void*)(OOC_INT32)str, str_0d, 0, i0);
  return;
  ;
}

void XML_Writer__WriterDesc_WriteObject(XML_Writer__Writer w, Object__Object obj) {
  register OOC_INT32 i0,i1,i2,i3;
  Object__String str;
  Object__String8 str8;
  Object__CharsLatin1 chars;

  i0 = (OOC_INT32)obj;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6198)))), Object__ObjectDesc_ToString)),Object__ObjectDesc_ToString)((Object__Object)i0);
  str = (Object__String)i0;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6226)))), Object__StringDesc_ToString8)),Object__StringDesc_ToString8)((Object__String)i0, 63u);
  str8 = (Object__String8)i0;
  i1 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)i0);
  chars = (Object__CharsLatin1)i1;
  i2 = (OOC_INT32)w;
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i1, 6300)), 0);
  i0 = *(OOC_INT32*)(_check_pointer(i0, 6310));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 6281)))), XML_Writer__WriterDesc_WriteLatin1I)),XML_Writer__WriterDesc_WriteLatin1I)((XML_Writer__Writer)i2, (void*)(_check_pointer(i1, 6300)), i3, 0, i0);
  return;
  ;
}

void XML_Writer__WriterDesc_WriteLatin1(XML_Writer__Writer w, const OOC_CHAR8 str[], OOC_LEN str_0d) {
  register OOC_INT32 i0,i1;

  i0 = Strings__Length((void*)(OOC_INT32)str, str_0d);
  i1 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6419)))), XML_Writer__WriterDesc_WriteLatin1I)),XML_Writer__WriterDesc_WriteLatin1I)((XML_Writer__Writer)i1, (void*)(OOC_INT32)str, str_0d, 0, i0);
  return;
  ;
}

void XML_Writer__WriterDesc_WriteURI(XML_Writer__Writer w, URI__URI uri, OOC_CHAR8 absolute) {
  register OOC_INT32 i0,i1;

  i0 = absolute;
  i0 = !i0;
  if (!i0) goto l4;
  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)uri;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6613))+56);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6598)))), URI__URIDesc_MakeRelative)),URI__URIDesc_MakeRelative)((URI__URI)i1, (URI__HierarchicalURI)i0);
  uri = (URI__URI)i0;
l4:
  i0 = (OOC_INT32)uri;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6654)))), URI__URIDesc_ToString)),URI__URIDesc_ToString)((URI__URI)i0);
  i1 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6638)))), XML_Writer__WriterDesc_WriteObject)),XML_Writer__WriterDesc_WriteObject)((XML_Writer__Writer)i1, (Object__Object)i0);
  return;
  ;
}

void XML_Writer__WriterDesc_WriteLInt(XML_Writer__Writer w, OOC_INT32 value) {
  register OOC_INT32 i0;
  OOC_CHAR8 val[32];

  i0 = value;
  IntStr__IntToStr(i0, (void*)(OOC_INT32)val, 32);
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6815)))), XML_Writer__WriterDesc_WriteLatin1)),XML_Writer__WriterDesc_WriteLatin1)((XML_Writer__Writer)i0, (void*)(OOC_INT32)val, 32);
  return;
  ;
}

void XML_Writer__WriterDesc_WriteRealFix(XML_Writer__Writer w, OOC_REAL32 real, OOC_INT32 k) {
  register OOC_INT32 i0;
  register OOC_REAL32 f0;
  OOC_CHAR8 val[128];

  i0 = k;
  f0 = real;
  RealStr__RealToFixed(f0, i0, (void*)(OOC_INT32)val, 128);
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7008)))), XML_Writer__WriterDesc_WriteLatin1)),XML_Writer__WriterDesc_WriteLatin1)((XML_Writer__Writer)i0, (void*)(OOC_INT32)val, 128);
  return;
  ;
}

static XML_Writer__String XML_Writer__GetString(const OOC_CHAR16 str[], OOC_LEN str_0d) {
  register OOC_INT32 i0,i1;
  XML_Writer__String s;

  i0 = LongStrings__Length((void*)(OOC_INT32)str, str_0d);
  i0 = (OOC_INT32)RT0__NewObject(_td_XML_Writer__String.baseTypes[0], (i0+1));
  s = (XML_Writer__String)i0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 7194)), 0);
  _copy_16((const void*)(OOC_INT32)str,(void*)(_check_pointer(i0, 7194)),i1);
  return (XML_Writer__String)i0;
  ;
}

void XML_Writer__WriterDesc_StartTag(XML_Writer__Writer w, const OOC_CHAR16 name[], OOC_LEN name_0d, OOC_CHAR8 mixedContent) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  XML_Writer__Elements _new;
  OOC_INT32 i;

  i0 = (OOC_INT32)w;
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 7406))+69);
  if (!i1) goto l3;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7427)))), XML_Writer__WriterDesc_CloseStartTag)),XML_Writer__WriterDesc_CloseStartTag)((XML_Writer__Writer)i0);
l3:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7453)))), XML_Writer__WriterDesc_NewLine)),XML_Writer__WriterDesc_NewLine)((XML_Writer__Writer)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7469)))), XML_UnicodeBuffer__OutputDesc_Write8)),XML_UnicodeBuffer__OutputDesc_Write8)((XML_UnicodeBuffer__Output)i0, "<", 2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7490)))), XML_UnicodeBuffer__OutputDesc_Write16)),XML_UnicodeBuffer__OutputDesc_Write16)((XML_UnicodeBuffer__Output)i0, (void*)(OOC_INT32)name, name_0d);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7548))+60);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 7522))+64);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 7562)), 0);
  i1 = i2==i1;
  if (!i1) goto l14;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 7588))+64);
  i1 = (OOC_INT32)RT0__NewObject(_td_XML_Writer__Elements.baseTypes[0], (i1*2));
  _new = (XML_Writer__Elements)i1;
  i = 0;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 7631))+64);
  i3 = 0<i2;
  if (!i3) goto l13;
  i3=0;
l8_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7673))+60);
  i4 = _check_pointer(i4, 7687);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = _check_pointer(i1, 7665);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  _copy_block((i4+(_check_index(i3, i5, OOC_UINT32, 7687))*8),(i6+(_check_index(i3, i7, OOC_UINT32, 7665))*8),8);
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l8_loop;
l13:
  *(OOC_INT32*)((_check_pointer(i0, 7709))+60) = i1;
l14:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7745))+60);
  i1 = _check_pointer(i1, 7759);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 7761))+64);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i4 = (OOC_INT32)XML_Writer__GetString((void*)(OOC_INT32)name, name_0d);
  *(OOC_INT32*)(i1+(_check_index(i2, i3, OOC_UINT32, 7759))*8) = i4;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7812))+60);
  i1 = _check_pointer(i1, 7826);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 7828))+64);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i4 = mixedContent;
  *(OOC_UINT8*)((i1+(_check_index(i2, i3, OOC_UINT32, 7826))*8)+4) = i4;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 7888))+64);
  *(OOC_INT32*)((_check_pointer(i0, 7888))+64) = (i1+1);
  *(OOC_UINT8*)((_check_pointer(i0, 7913))+69) = 1u;
  i1 = _check_pointer(i0, 7947);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 7963))+36);
  i2 = i2>=0;
  if (i2) goto l17;
  i2=0u;
  goto l18;
l17:
  i2 = !i4;
  
l18:
  *(OOC_UINT8*)(i1+68) = i2;
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 8008))+68);
  if (!i1) goto l21;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 8036))+40);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 8047))+36);
  *(OOC_INT32*)((_check_pointer(i0, 8036))+40) = (i1+i2);
l21:
  return;
  ;
}

void XML_Writer__WriterDesc_StartTagLatin1(XML_Writer__Writer w, const OOC_CHAR8 name[], OOC_LEN name_0d, OOC_CHAR8 mixedContent) {
  register OOC_INT32 i0,i1;
  OOC_CHAR16 name16[1024];

  _copy_8to16((const void*)(OOC_INT32)name,(void*)(OOC_INT32)name16,1024);
  i0 = (OOC_INT32)w;
  i1 = mixedContent;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8295)))), XML_Writer__WriterDesc_StartTag)),XML_Writer__WriterDesc_StartTag)((XML_Writer__Writer)i0, (void*)(OOC_INT32)name16, 1024, i1);
  return;
  ;
}

void XML_Writer__WriterDesc_EmptyTag(XML_Writer__Writer w, const OOC_CHAR16 name[], OOC_LEN name_0d) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)w;
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 8432))+69);
  if (!i1) goto l4;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8453)))), XML_Writer__WriterDesc_CloseStartTag)),XML_Writer__WriterDesc_CloseStartTag)((XML_Writer__Writer)i0);
l4:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8479)))), XML_Writer__WriterDesc_NewLine)),XML_Writer__WriterDesc_NewLine)((XML_Writer__Writer)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8495)))), XML_UnicodeBuffer__OutputDesc_Write8)),XML_UnicodeBuffer__OutputDesc_Write8)((XML_UnicodeBuffer__Output)i0, "<", 2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8516)))), XML_UnicodeBuffer__OutputDesc_Write16)),XML_UnicodeBuffer__OutputDesc_Write16)((XML_UnicodeBuffer__Output)i0, (void*)(OOC_INT32)name, name_0d);
  *(OOC_UINT8*)((_check_pointer(i0, 8662))+69) = 1u;
  *(OOC_UINT8*)((_check_pointer(i0, 8691))+70) = 1u;
  return;
  ;
}

void XML_Writer__WriterDesc_EmptyTagLatin1(XML_Writer__Writer w, const OOC_CHAR16 name[], OOC_LEN name_0d) {
  register OOC_INT32 i0;
  OOC_CHAR16 name16[1024];

  _copy_16((const void*)(OOC_INT32)name,(void*)(OOC_INT32)name16,1024);
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8877)))), XML_Writer__WriterDesc_EmptyTag)),XML_Writer__WriterDesc_EmptyTag)((XML_Writer__Writer)i0, (void*)(OOC_INT32)name16, 1024);
  return;
  ;
}

void XML_Writer__WriterDesc_AttrString(XML_Writer__Writer w, const OOC_CHAR16 name[], OOC_LEN name_0d, const OOC_CHAR16 value[], OOC_LEN value_0d) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT32 s;
  OOC_INT32 e;
  OOC_INT32 last;

  i0 = (OOC_INT32)w;
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 9055))+69);
  _assert(i1, 127, 9046);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9077)))), XML_UnicodeBuffer__OutputDesc_Write8)),XML_UnicodeBuffer__OutputDesc_Write8)((XML_UnicodeBuffer__Output)i0, " ", 2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9098)))), XML_UnicodeBuffer__OutputDesc_Write16)),XML_UnicodeBuffer__OutputDesc_Write16)((XML_UnicodeBuffer__Output)i0, (void*)(OOC_INT32)name, name_0d);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9121)))), XML_UnicodeBuffer__OutputDesc_Write8)),XML_UnicodeBuffer__OutputDesc_Write8)((XML_UnicodeBuffer__Output)i0, "=\047", 3);
  s = 0;
  i1 = LongStrings__Length((void*)(OOC_INT32)value, value_0d);
  e = i1;
  i2 = 0!=i1;
  if (!i2) goto l60;
  i3=i2;i2=0;
l3_loop:
  last = i2;
  if (i3) goto l6;
  i3=0u;
  goto l8;
l6:
  i3 = *(OOC_UINT16*)((OOC_INT32)value+(_check_index(i2, value_0d, OOC_UINT32, 9254))*2);
  i3 = i3!=39u;
  
l8:
  if (i3) goto l10;
  i3=0u;
  goto l12;
l10:
  i3 = *(OOC_UINT16*)((OOC_INT32)value+(_check_index(i2, value_0d, OOC_UINT32, 9285))*2);
  i3 = i3!=38u;
  
l12:
  if (i3) goto l14;
  i3=0u;
  goto l16;
l14:
  i3 = *(OOC_UINT16*)((OOC_INT32)value+(_check_index(i2, value_0d, OOC_UINT32, 9304))*2);
  i3 = i3!=60u;
  
l16:
  if (i3) goto l18;
  i3=0u;
  goto l20;
l18:
  i3 = *(OOC_UINT16*)((OOC_INT32)value+(_check_index(i2, value_0d, OOC_UINT32, 9323))*2);
  i3 = i3!=62u;
  
l20:
  if (i3) goto l22;
  i3=i2;
  goto l44;
l22:
  i3=i2;
l23_loop:
  i3 = i3+1;
  s = i3;
  i4 = i3!=i1;
  if (i4) goto l26;
  i4=0u;
  goto l28;
l26:
  i4 = *(OOC_UINT16*)((OOC_INT32)value+(_check_index(i3, value_0d, OOC_UINT32, 9254))*2);
  i4 = i4!=39u;
  
l28:
  if (i4) goto l30;
  i4=0u;
  goto l32;
l30:
  i4 = *(OOC_UINT16*)((OOC_INT32)value+(_check_index(i3, value_0d, OOC_UINT32, 9285))*2);
  i4 = i4!=38u;
  
l32:
  if (i4) goto l34;
  i4=0u;
  goto l36;
l34:
  i4 = *(OOC_UINT16*)((OOC_INT32)value+(_check_index(i3, value_0d, OOC_UINT32, 9304))*2);
  i4 = i4!=60u;
  
l36:
  if (i4) goto l38;
  i4=0u;
  goto l40;
l38:
  i4 = *(OOC_UINT16*)((OOC_INT32)value+(_check_index(i3, value_0d, OOC_UINT32, 9323))*2);
  i4 = i4!=62u;
  
l40:
  if (i4) goto l23_loop;
l44:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9371)))), XML_UnicodeBuffer__OutputDesc_Write16I)),XML_UnicodeBuffer__OutputDesc_Write16I)((XML_UnicodeBuffer__Output)i0, (void*)(OOC_INT32)value, value_0d, i2, i3);
  i2 = i3!=i1;
  if (i2) goto l47;
  i2=i3;
  goto l55;
l47:
  i2 = *(OOC_UINT16*)((OOC_INT32)value+(_check_index(i3, value_0d, OOC_UINT32, 9440))*2);
  switch (i2) {
  case 38u:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9463)))), XML_UnicodeBuffer__OutputDesc_Write8)),XML_UnicodeBuffer__OutputDesc_Write8)((XML_UnicodeBuffer__Output)i0, "&amp;", 6);
    goto l54;
  case 60u:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9498)))), XML_UnicodeBuffer__OutputDesc_Write8)),XML_UnicodeBuffer__OutputDesc_Write8)((XML_UnicodeBuffer__Output)i0, "&lt;", 5);
    goto l54;
  case 62u:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9532)))), XML_UnicodeBuffer__OutputDesc_Write8)),XML_UnicodeBuffer__OutputDesc_Write8)((XML_UnicodeBuffer__Output)i0, "&gt;", 5);
    goto l54;
  case 39u:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9566)))), XML_UnicodeBuffer__OutputDesc_Write8)),XML_UnicodeBuffer__OutputDesc_Write8)((XML_UnicodeBuffer__Output)i0, "&apos;", 7);
    goto l54;
  default:
    _failed_case(i2, 9430);
    goto l54;
  }
l54:
  i2 = i3+1;
  s = i2;
  
l55:
  i3 = i2!=i1;
  if (i3) goto l3_loop;
l60:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9644)))), XML_UnicodeBuffer__OutputDesc_Write8)),XML_UnicodeBuffer__OutputDesc_Write8)((XML_UnicodeBuffer__Output)i0, "\047", 2);
  return;
  ;
}

void XML_Writer__WriterDesc_AttrStringLatin1(XML_Writer__Writer w, const OOC_CHAR16 name[], OOC_LEN name_0d, const OOC_CHAR8 value[], OOC_LEN value_0d) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT32 s;
  OOC_INT32 e;
  OOC_INT32 last;

  i0 = (OOC_INT32)w;
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 9874))+69);
  _assert(i1, 127, 9865);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9896)))), XML_UnicodeBuffer__OutputDesc_Write8)),XML_UnicodeBuffer__OutputDesc_Write8)((XML_UnicodeBuffer__Output)i0, " ", 2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9917)))), XML_UnicodeBuffer__OutputDesc_Write16)),XML_UnicodeBuffer__OutputDesc_Write16)((XML_UnicodeBuffer__Output)i0, (void*)(OOC_INT32)name, name_0d);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9940)))), XML_UnicodeBuffer__OutputDesc_Write8)),XML_UnicodeBuffer__OutputDesc_Write8)((XML_UnicodeBuffer__Output)i0, "=\047", 3);
  s = 0;
  i1 = Strings__Length((void*)(OOC_INT32)value, value_0d);
  e = i1;
  i2 = 0!=i1;
  if (!i2) goto l60;
  i3=i2;i2=0;
l3_loop:
  last = i2;
  if (i3) goto l6;
  i3=0u;
  goto l8;
l6:
  i3 = *(OOC_UINT8*)((OOC_INT32)value+(_check_index(i2, value_0d, OOC_UINT32, 10069)));
  i3 = i3!=39u;
  
l8:
  if (i3) goto l10;
  i3=0u;
  goto l12;
l10:
  i3 = *(OOC_UINT8*)((OOC_INT32)value+(_check_index(i2, value_0d, OOC_UINT32, 10100)));
  i3 = i3!=38u;
  
l12:
  if (i3) goto l14;
  i3=0u;
  goto l16;
l14:
  i3 = *(OOC_UINT8*)((OOC_INT32)value+(_check_index(i2, value_0d, OOC_UINT32, 10119)));
  i3 = i3!=60u;
  
l16:
  if (i3) goto l18;
  i3=0u;
  goto l20;
l18:
  i3 = *(OOC_UINT8*)((OOC_INT32)value+(_check_index(i2, value_0d, OOC_UINT32, 10138)));
  i3 = i3!=62u;
  
l20:
  if (i3) goto l22;
  i3=i2;
  goto l44;
l22:
  i3=i2;
l23_loop:
  i3 = i3+1;
  s = i3;
  i4 = i3!=i1;
  if (i4) goto l26;
  i4=0u;
  goto l28;
l26:
  i4 = *(OOC_UINT8*)((OOC_INT32)value+(_check_index(i3, value_0d, OOC_UINT32, 10069)));
  i4 = i4!=39u;
  
l28:
  if (i4) goto l30;
  i4=0u;
  goto l32;
l30:
  i4 = *(OOC_UINT8*)((OOC_INT32)value+(_check_index(i3, value_0d, OOC_UINT32, 10100)));
  i4 = i4!=38u;
  
l32:
  if (i4) goto l34;
  i4=0u;
  goto l36;
l34:
  i4 = *(OOC_UINT8*)((OOC_INT32)value+(_check_index(i3, value_0d, OOC_UINT32, 10119)));
  i4 = i4!=60u;
  
l36:
  if (i4) goto l38;
  i4=0u;
  goto l40;
l38:
  i4 = *(OOC_UINT8*)((OOC_INT32)value+(_check_index(i3, value_0d, OOC_UINT32, 10138)));
  i4 = i4!=62u;
  
l40:
  if (i4) goto l23_loop;
l44:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10186)))), XML_UnicodeBuffer__OutputDesc_Write8I)),XML_UnicodeBuffer__OutputDesc_Write8I)((XML_UnicodeBuffer__Output)i0, (void*)(OOC_INT32)value, value_0d, i2, i3);
  i2 = i3!=i1;
  if (i2) goto l47;
  i2=i3;
  goto l55;
l47:
  i2 = *(OOC_UINT8*)((OOC_INT32)value+(_check_index(i3, value_0d, OOC_UINT32, 10254)));
  switch (i2) {
  case 38u:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10277)))), XML_UnicodeBuffer__OutputDesc_Write8)),XML_UnicodeBuffer__OutputDesc_Write8)((XML_UnicodeBuffer__Output)i0, "&amp;", 6);
    goto l54;
  case 60u:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10312)))), XML_UnicodeBuffer__OutputDesc_Write8)),XML_UnicodeBuffer__OutputDesc_Write8)((XML_UnicodeBuffer__Output)i0, "&lt;", 5);
    goto l54;
  case 62u:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10346)))), XML_UnicodeBuffer__OutputDesc_Write8)),XML_UnicodeBuffer__OutputDesc_Write8)((XML_UnicodeBuffer__Output)i0, "&gt;", 5);
    goto l54;
  case 39u:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10380)))), XML_UnicodeBuffer__OutputDesc_Write8)),XML_UnicodeBuffer__OutputDesc_Write8)((XML_UnicodeBuffer__Output)i0, "&apos;", 7);
    goto l54;
  default:
    _failed_case(i2, 10244);
    goto l54;
  }
l54:
  i2 = i3+1;
  s = i2;
  
l55:
  i3 = i2!=i1;
  if (i3) goto l3_loop;
l60:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10458)))), XML_UnicodeBuffer__OutputDesc_Write8)),XML_UnicodeBuffer__OutputDesc_Write8)((XML_UnicodeBuffer__Output)i0, "\047", 2);
  return;
  ;
}

void XML_Writer__WriterDesc_AttrObject(XML_Writer__Writer w, const OOC_CHAR16 name[], OOC_LEN name_0d, Object__String value) {
  register OOC_INT32 i0,i1,i2;
  Object__String s;
  Object__CharsLatin1 chars;

  i0 = (OOC_INT32)value;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10736)))), Object__StringDesc_ToString8)),Object__StringDesc_ToString8)((Object__String)i0, 63u);
  s = (Object__String)i0;
  i0 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10775)))), &_td_Object__String8Desc, 10775)));
  chars = (Object__CharsLatin1)i0;
  i1 = (OOC_INT32)w;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i0, 10833)), 0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10804)))), XML_Writer__WriterDesc_AttrStringLatin1)),XML_Writer__WriterDesc_AttrStringLatin1)((XML_Writer__Writer)i1, (void*)(OOC_INT32)name, name_0d, (void*)(_check_pointer(i0, 10833)), i2);
  return;
  ;
}

void XML_Writer__WriterDesc_AttrInt(XML_Writer__Writer w, const OOC_CHAR16 name[], OOC_LEN name_0d, OOC_INT32 value) {
  register OOC_INT32 i0;
  OOC_CHAR8 val[32];

  i0 = value;
  IntStr__IntToStr(i0, (void*)(OOC_INT32)val, 32);
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11015)))), XML_Writer__WriterDesc_AttrStringLatin1)),XML_Writer__WriterDesc_AttrStringLatin1)((XML_Writer__Writer)i0, (void*)(OOC_INT32)name, name_0d, (void*)(OOC_INT32)val, 32);
  return;
  ;
}

void XML_Writer__WriterDesc_AttrBool(XML_Writer__Writer w, const OOC_CHAR16 name[], OOC_LEN name_0d, OOC_CHAR8 value) {
  register OOC_INT32 i0;

  i0 = value;
  if (i0) goto l3;
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11224)))), XML_Writer__WriterDesc_AttrStringLatin1)),XML_Writer__WriterDesc_AttrStringLatin1)((XML_Writer__Writer)i0, (void*)(OOC_INT32)name, name_0d, "no", 3);
  goto l4;
l3:
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11175)))), XML_Writer__WriterDesc_AttrStringLatin1)),XML_Writer__WriterDesc_AttrStringLatin1)((XML_Writer__Writer)i0, (void*)(OOC_INT32)name, name_0d, "yes", 4);
l4:
  return;
  ;
}

void XML_Writer__WriterDesc_AttrURI(XML_Writer__Writer w, const OOC_CHAR16 name[], OOC_LEN name_0d, URI__URI uri, OOC_CHAR8 absolute) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)w;
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 11430))+69);
  _assert(i1, 127, 11421);
  i1 = absolute;
  i1 = !i1;
  if (!i1) goto l4;
  i1 = (OOC_INT32)uri;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11502))+56);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11485)))), URI__URIDesc_MakeRelative)),URI__URIDesc_MakeRelative)((URI__URI)i1, (URI__HierarchicalURI)i2);
  uri = (URI__URI)i1;
l4:
  i1 = (OOC_INT32)uri;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11548)))), URI__URIDesc_ToString)),URI__URIDesc_ToString)((URI__URI)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11527)))), XML_Writer__WriterDesc_AttrObject)),XML_Writer__WriterDesc_AttrObject)((XML_Writer__Writer)i0, (void*)(OOC_INT32)name, name_0d, (Object__String)i1);
  return;
  ;
}

void XML_Writer__WriterDesc_EndTag(volatile XML_Writer__Writer w) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  jmp_buf _target0;
  Exception__Context _context0;

  i0 = (OOC_INT32)w;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 11627))+64);
  i1 = i1<=0;
  if (!i1) goto l10;
  {
    Exception__PushContext(&_context0, &_target0);
    if (!setjmp(_target0)) goto l8;
    Exception__PopContext(1);
    i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG(((OOC_INT32)Exception__Current()))), &_td_IO__ErrorDesc);
    if (i0) goto l7;
    Exception__ActivateContext();
l7:
    Exception__Clear();
    goto l9;
l8:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11675)))), XML_UnicodeBuffer__OutputDesc_Flush)),XML_UnicodeBuffer__OutputDesc_Flush)((XML_UnicodeBuffer__Output)i0);
    Exception__PopContext(1);
l9:;
  }
  _assert(0u, 127, 11723);
l10:
  i0 = (OOC_INT32)w;
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 11760))+68);
  if (!i1) goto l13;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 11788))+40);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 11799))+36);
  *(OOC_INT32*)((_check_pointer(i0, 11788))+40) = (i1-i2);
l13:
  i1 = *(OOC_INT32*)((_check_pointer(i0, 11833))+64);
  *(OOC_INT32*)((_check_pointer(i0, 11833))+64) = (i1-1);
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 11866))+70);
  if (i1) goto l24;
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 12099))+69);
  if (i1) goto l18;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12368)))), XML_Writer__WriterDesc_NewLine)),XML_Writer__WriterDesc_NewLine)((XML_Writer__Writer)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12386)))), XML_UnicodeBuffer__OutputDesc_Write8)),XML_UnicodeBuffer__OutputDesc_Write8)((XML_UnicodeBuffer__Output)i0, "</", 3);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12422))+60);
  i1 = _check_pointer(i1, 12436);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 12438))+64);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(i2, i3, OOC_UINT32, 12436))*8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12422))+60);
  i2 = _check_pointer(i2, 12436);
  i3 = *(OOC_INT32*)((_check_pointer(i0, 12438))+64);
  i4 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i3, i4, OOC_UINT32, 12436))*8);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 12462)), 0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12410)))), XML_UnicodeBuffer__OutputDesc_Write16)),XML_UnicodeBuffer__OutputDesc_Write16)((XML_UnicodeBuffer__Output)i0, (void*)(_check_pointer(i2, 12462)), i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12473)))), XML_UnicodeBuffer__OutputDesc_Write8)),XML_UnicodeBuffer__OutputDesc_Write8)((XML_UnicodeBuffer__Output)i0, ">", 2);
  goto l25;
l18:
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 12172))+52);
  if (i1) goto l21;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12242)))), XML_UnicodeBuffer__OutputDesc_Write8)),XML_UnicodeBuffer__OutputDesc_Write8)((XML_UnicodeBuffer__Output)i0, "/>", 3);
  goto l22;
l21:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12205)))), XML_UnicodeBuffer__OutputDesc_Write8)),XML_UnicodeBuffer__OutputDesc_Write8)((XML_UnicodeBuffer__Output)i0, " />", 4);
l22:
  *(OOC_UINT8*)((_check_pointer(i0, 12276))+69) = 0u;
  goto l25;
l24:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11944)))), XML_Writer__WriterDesc_CloseStartTag)),XML_Writer__WriterDesc_CloseStartTag)((XML_Writer__Writer)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11968)))), XML_Writer__WriterDesc_NewLine)),XML_Writer__WriterDesc_NewLine)((XML_Writer__Writer)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11986)))), XML_UnicodeBuffer__OutputDesc_Write8)),XML_UnicodeBuffer__OutputDesc_Write8)((XML_UnicodeBuffer__Output)i0, "</", 3);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12022))+60);
  i1 = _check_pointer(i1, 12036);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 12038))+64);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(i2, i3, OOC_UINT32, 12036))*8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12022))+60);
  i2 = _check_pointer(i2, 12036);
  i3 = *(OOC_INT32*)((_check_pointer(i0, 12038))+64);
  i4 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i3, i4, OOC_UINT32, 12036))*8);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 12062)), 0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12010)))), XML_UnicodeBuffer__OutputDesc_Write16)),XML_UnicodeBuffer__OutputDesc_Write16)((XML_UnicodeBuffer__Output)i0, (void*)(_check_pointer(i2, 12062)), i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12073)))), XML_UnicodeBuffer__OutputDesc_Write8)),XML_UnicodeBuffer__OutputDesc_Write8)((XML_UnicodeBuffer__Output)i0, ">", 2);
l25:
  i1 = *(OOC_INT32*)((_check_pointer(i0, 12523))+36);
  *(OOC_UINT8*)((_check_pointer(i0, 12507))+68) = (i1>=0);
  i1 = *(OOC_INT32*)((_check_pointer(i0, 12553))+64);
  i1 = i1>0;
  if (!i1) goto l32;
  i1 = _check_pointer(i0, 12588);
  i2 = *(OOC_UINT8*)((_check_pointer(i0, 12603))+68);
  if (i2) goto l30;
  i0=0u;
  goto l31;
l30:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12640))+60);
  i2 = _check_pointer(i2, 12654);
  i0 = *(OOC_INT32*)((_check_pointer(i0, 12656))+64);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i0 = *(OOC_UINT8*)((i2+(_check_index((i0-1), i3, OOC_UINT32, 12654))*8)+4);
  i0 = !i0;
  
l31:
  *(OOC_UINT8*)(i1+68) = i0;
l32:
  return;
  ;
}

void XML_Writer__WriterDesc_EndOfText(XML_Writer__Writer w) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)w;
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 12842))+69);
  if (!i1) goto l4;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12863)))), XML_Writer__WriterDesc_CloseStartTag)),XML_Writer__WriterDesc_CloseStartTag)((XML_Writer__Writer)i0);
l4:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12889)))), XML_Writer__WriterDesc_NewLine)),XML_Writer__WriterDesc_NewLine)((XML_Writer__Writer)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12905)))), XML_UnicodeBuffer__OutputDesc_Flush)),XML_UnicodeBuffer__OutputDesc_Flush)((XML_UnicodeBuffer__Output)i0);
  i0 = *(OOC_INT32*)((_check_pointer(i0, 12927))+64);
  _assert((i0==0), 127, 12918);
  return;
  ;
}

void OOC_XML_Writer_init(void) {

  return;
  ;
}

/* --- */
