#include <OOC/X86/RuntimeData.d>
#include <__oo2c.h>
#include <setjmp.h>

void OOC_X86_RuntimeData__DataWriterDesc_INIT(OOC_X86_RuntimeData__DataWriter dw, ADT_StringBuffer__StringBuffer sb, OOC_INT32 align) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)dw;
  i1 = (OOC_INT32)sb;
  *(OOC_INT32*)(_check_pointer(i0, 703)) = i1;
  i2 = align;
  *(OOC_INT32*)((_check_pointer(i0, 720))+4) = i2;
  *(OOC_INT32*)((_check_pointer(i0, 743))+8) = (-1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 773)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i1, (Object__Object)((OOC_INT32)_c0));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 803)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i1, (Object__Object)((OOC_INT32)_c1));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 835)))), ADT_StringBuffer__StringBufferDesc_AppendInt)),ADT_StringBuffer__StringBufferDesc_AppendInt)((ADT_StringBuffer__StringBuffer)i1, i2);
  return;
  ;
}

void OOC_X86_RuntimeData__DataWriterDesc_Align(OOC_X86_RuntimeData__DataWriter dw) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)dw;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 917));
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 917));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 920)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i2, (Object__Object)((OOC_INT32)_c2));
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 952));
  i2 = *(OOC_INT32*)((_check_pointer(i0, 968))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 952));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 955)))), ADT_StringBuffer__StringBufferDesc_AppendInt)),ADT_StringBuffer__StringBufferDesc_AppendInt)((ADT_StringBuffer__StringBuffer)i0, i2);
  return;
  ;
}

void OOC_X86_RuntimeData__DataWriterDesc_Object(OOC_X86_RuntimeData__DataWriter dw, Object__String name, OOC_INT32 size, OOC_CHAR8 global) {
  register OOC_INT32 i0,i1,i2,i3,i4;

  i0 = global;
  if (!i0) goto l4;
  i0 = (OOC_INT32)dw;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 1141));
  i2 = (OOC_INT32)name;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 1141));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 1144)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c3),(void*)i2)));
l4:
  i0 = (OOC_INT32)dw;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 1187));
  i2 = (OOC_INT32)name;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 1187));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 1190)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i3, (Object__Object)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c4),(void*)i2)),(void*)((OOC_INT32)_c5))));
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 1238));
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 1238));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 1241)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i3, (Object__Object)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c6),(void*)i2)),(void*)((OOC_INT32)_c7))));
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 1282));
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 1282));
  i4 = size;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 1285)))), ADT_StringBuffer__StringBufferDesc_AppendInt)),ADT_StringBuffer__StringBufferDesc_AppendInt)((ADT_StringBuffer__StringBuffer)i3, i4);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 1309));
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 1309));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 1312)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i3, (Object__Object)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c8),(void*)i2)),(void*)((OOC_INT32)_c9))));
  *(OOC_INT32*)((_check_pointer(i0, 1340))+8) = 0;
  return;
  ;
}

void OOC_X86_RuntimeData__DataWriterDesc_Pad(OOC_X86_RuntimeData__DataWriter dw, OOC_INT32 bytes) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)dw;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 1439));
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 1439));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 1442)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i2, (Object__Object)((OOC_INT32)_c10));
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 1473));
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 1473));
  i3 = bytes;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 1476)))), ADT_StringBuffer__StringBufferDesc_AppendInt)),ADT_StringBuffer__StringBufferDesc_AppendInt)((ADT_StringBuffer__StringBuffer)i2, i3);
  i1 = *(OOC_INT32*)((_check_pointer(i0, 1505))+8);
  *(OOC_INT32*)((_check_pointer(i0, 1505))+8) = (i1+i3);
  return;
  ;
}

void OOC_X86_RuntimeData__DataWriterDesc_PadTo(OOC_X86_RuntimeData__DataWriter dw, OOC_INT32 pos) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)dw;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 1608))+8);
  i2 = pos;
  i1 = i1!=i2;
  if (!i1) goto l4;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 1655))+8);
  OOC_X86_RuntimeData__DataWriterDesc_Pad((OOC_X86_RuntimeData__DataWriter)i0, (i2-i1));
l4:
  return;
  ;
}

void OOC_X86_RuntimeData__DataWriterDesc_FixAlign(OOC_X86_RuntimeData__DataWriter dw, OOC_INT32 size) {
  register OOC_INT32 i0,i1,i2;

  i0 = size;
  i1 = (OOC_INT32)dw;
  OOC_X86_RuntimeData__DataWriterDesc_PadTo((OOC_X86_RuntimeData__DataWriter)i1, i0);
  i2 = *(OOC_INT32*)((_check_pointer(i1, 1795))+4);
  i0 = (_mod(i0,i2))!=0;
  if (!i0) goto l4;
  OOC_X86_RuntimeData__DataWriterDesc_Align((OOC_X86_RuntimeData__DataWriter)i1);
l4:
  return;
  ;
}

void OOC_X86_RuntimeData__DataWriterDesc_Adr(OOC_X86_RuntimeData__DataWriter dw, Object__String symbol) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)dw;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 1918));
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 1918));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 1921)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i2, (Object__Object)((OOC_INT32)_c11));
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 1952));
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 1952));
  i3 = (OOC_INT32)symbol;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 1955)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i2, (Object__Object)i3);
  i1 = *(OOC_INT32*)((_check_pointer(i0, 1982))+8);
  *(OOC_INT32*)((_check_pointer(i0, 1982))+8) = (i1+4);
  return;
  ;
}

void OOC_X86_RuntimeData__DataWriterDesc_Null(OOC_X86_RuntimeData__DataWriter dw) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)dw;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2074));
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2074));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2077)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i2, (Object__Object)((OOC_INT32)_c12));
  i1 = *(OOC_INT32*)((_check_pointer(i0, 2113))+8);
  *(OOC_INT32*)((_check_pointer(i0, 2113))+8) = (i1+4);
  return;
  ;
}

void OOC_X86_RuntimeData__DataWriterDesc_LongInt(OOC_X86_RuntimeData__DataWriter dw, OOC_INT32 x) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)dw;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2219));
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2219));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2222)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i2, (Object__Object)((OOC_INT32)_c13));
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2253));
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2253));
  i3 = x;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2256)))), ADT_StringBuffer__StringBufferDesc_AppendInt)),ADT_StringBuffer__StringBufferDesc_AppendInt)((ADT_StringBuffer__StringBuffer)i2, i3);
  i1 = *(OOC_INT32*)((_check_pointer(i0, 2281))+8);
  *(OOC_INT32*)((_check_pointer(i0, 2281))+8) = (i1+4);
  return;
  ;
}

void OOC_X86_RuntimeData__DataWriterDesc_ShortInt(OOC_X86_RuntimeData__DataWriter dw, OOC_INT8 x) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)dw;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2382));
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2382));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2385)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i2, (Object__Object)((OOC_INT32)_c14));
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2416));
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2416));
  i3 = x;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2419)))), ADT_StringBuffer__StringBufferDesc_AppendInt)),ADT_StringBuffer__StringBufferDesc_AppendInt)((ADT_StringBuffer__StringBuffer)i2, i3);
  i1 = *(OOC_INT32*)((_check_pointer(i0, 2444))+8);
  *(OOC_INT32*)((_check_pointer(i0, 2444))+8) = (i1+1);
  return;
  ;
}

void OOC_X86_RuntimeData__DataWriterDesc_StringObject(OOC_X86_RuntimeData__DataWriter dw, Object__String name, Object__String value) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT32 size;

  i0 = (OOC_INT32)value;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 2594));
  i1 = i1+1;
  size = i1;
  i2 = (OOC_INT32)dw;
  i3 = (OOC_INT32)name;
  OOC_X86_RuntimeData__DataWriterDesc_Object((OOC_X86_RuntimeData__DataWriter)i2, (Object__String)i3, i1, 0u);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 2645));
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 2645));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 2648)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i4, (Object__Object)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)Object__Concat2((void*)((OOC_INT32)_c15),(void*)i0)),(void*)((OOC_INT32)_c16))));
  i0 = *(OOC_INT32*)((_check_pointer(i2, 2696))+8);
  *(OOC_INT32*)((_check_pointer(i2, 2696))+8) = (i0+i1);
  OOC_X86_RuntimeData__DataWriterDesc_FixAlign((OOC_X86_RuntimeData__DataWriter)i2, i1);
  return;
  ;
}

void OOC_X86_RuntimeData__DataWriterDesc_TypeFlags(OOC_X86_RuntimeData__DataWriter dw, OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1,i2;
  OOC_INT32 flags;

  flags = 0;
  i0 = (OOC_INT32)type;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3;
  i0=0;
  goto l28;
l3:
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2985)))), &_td_OOC_SymbolTable__RecordDesc);
  if (i1) goto l14;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3301)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (i1) goto l8;
  i0=0;
  goto l28;
l8:
  i0 = *(OOC_UINT8*)((_check_pointer(i0, 3331))+60);
  if (i0) goto l11;
  i0=0;
  goto l28;
l11:
  i0=1;
  goto l28;
l14:
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 3016))+60);
  if (i1) goto l17;
  i1=0;
  goto l18;
l17:
  flags = 2;
  i1=2;
l18:
  i2 = *(OOC_UINT8*)((_check_pointer(i0, 3105))+61);
  if (!i2) goto l22;
  i1 = i1+1;
  
l22:
  i0 = OOC_SymbolTable_Predef__ImplementsFinalize((OOC_SymbolTable__Record)i0);
  if (i0) goto l25;
  i0=i1;
  goto l28;
l25:
  i0 = i1+4;
  
l28:
  i1 = (OOC_INT32)dw;
  OOC_X86_RuntimeData__DataWriterDesc_LongInt((OOC_X86_RuntimeData__DataWriter)i1, i0);
  return;
  ;
}

void OOC_X86_RuntimeData__Write(ADT_StringBuffer__StringBuffer sb, OOC_SymbolTable__Module symTab) {
  register OOC_INT32 i0,i1;
  OOC_C_Naming__QualTypeData qtdData;
  OOC_X86_RuntimeData__DataWriter dw;
  ADT_ArrayList__ArrayList tdNames;
  auto void OOC_X86_RuntimeData__Write_ModuleDescr(OOC_SymbolTable__Module module, ADT_ArrayList__ArrayList tdNames);
  auto Object__String OOC_X86_RuntimeData__Write_WriteName(Object__String name, OOC_SymbolTable__Type type);
  auto void OOC_X86_RuntimeData__Write_TypeDescrRef(OOC_SymbolTable__Type type);
  auto void OOC_X86_RuntimeData__Write_ArrayTypeDescr(OOC_SymbolTable__Array array);
  auto void OOC_X86_RuntimeData__Write_RecordTypeDescr(OOC_SymbolTable__Record record);
  auto void OOC_X86_RuntimeData__Write_PointerTypeDescr(OOC_SymbolTable__Pointer pointer);
  auto void OOC_X86_RuntimeData__Write_Traverse(OOC_SymbolTable__Item item, OOC_SymbolTable__ProcDecl proc);
    
    void OOC_X86_RuntimeData__Write_ModuleDescr(OOC_SymbolTable__Module module, ADT_ArrayList__ArrayList tdNames) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      OOC_INT32 size;
      OOC_INT32 i;

      i0 = (OOC_INT32)module;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3802)))), OOC_SymbolTable__DeclarationDesc_Name)),OOC_SymbolTable__DeclarationDesc_Name)((OOC_SymbolTable__Declaration)i0);
      i1 = (OOC_INT32)dw;
      OOC_X86_RuntimeData__DataWriterDesc_StringObject((OOC_X86_RuntimeData__DataWriter)i1, (Object__String)((OOC_INT32)_c17), (Object__String)i0);
      i0 = (OOC_INT32)tdNames;
      i1 = *(OOC_INT32*)((_check_pointer(i0, 3835))+4);
      i1 = (i1+1)*4;
      size = i1;
      i2 = (OOC_INT32)dw;
      OOC_X86_RuntimeData__DataWriterDesc_Object((OOC_X86_RuntimeData__DataWriter)i2, (Object__String)((OOC_INT32)_c18), i1, 0u);
      i = 0;
      i1 = *(OOC_INT32*)((_check_pointer(i0, 3935))+4);
      i2 = 0<i1;
      if (!i2) goto l8;
      i2=0;
l3_loop:
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3968));
      i3 = _check_pointer(i3, 3974);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 3974))*4);
      i4 = (OOC_INT32)dw;
      OOC_X86_RuntimeData__DataWriterDesc_Adr((OOC_X86_RuntimeData__DataWriter)i4, (Object__String)(_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 3978)))), &_td_Object__StringDesc, 3978)));
      i2 = i2+1;
      i = i2;
      i3 = i2<i1;
      if (i3) goto l3_loop;
l8:
      i0 = (OOC_INT32)dw;
      OOC_X86_RuntimeData__DataWriterDesc_Null((OOC_X86_RuntimeData__DataWriter)i0);
      i0 = (OOC_INT32)dw;
      OOC_X86_RuntimeData__DataWriterDesc_Object((OOC_X86_RuntimeData__DataWriter)i0, (Object__String)((OOC_INT32)_c19), 8, 0u);
      i0 = (OOC_INT32)dw;
      OOC_X86_RuntimeData__DataWriterDesc_Adr((OOC_X86_RuntimeData__DataWriter)i0, (Object__String)((OOC_INT32)_c20));
      i0 = (OOC_INT32)dw;
      OOC_X86_RuntimeData__DataWriterDesc_Adr((OOC_X86_RuntimeData__DataWriter)i0, (Object__String)((OOC_INT32)_c21));
      i0 = (OOC_INT32)dw;
      OOC_X86_RuntimeData__DataWriterDesc_FixAlign((OOC_X86_RuntimeData__DataWriter)i0, 8);
      return;
      ;
    }

    
    Object__String OOC_X86_RuntimeData__Write_WriteName(Object__String name, OOC_SymbolTable__Type type) {
      register OOC_INT32 i0,i1,i2;

      i0 = (OOC_INT32)type;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4284))+24);
      i1 = i1==(OOC_INT32)0;
      if (i1) goto l3;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4390))+24);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4401))+20);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4406))+12);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4390))+24);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4401))+20);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4406))+12);
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 4410)), 0);
      i0 = (OOC_INT32)Object__NewLatin1((void*)(_check_pointer(i0, 4410)), i1);
      i1 = (OOC_INT32)dw;
      i2 = (OOC_INT32)name;
      OOC_X86_RuntimeData__DataWriterDesc_StringObject((OOC_X86_RuntimeData__DataWriter)i1, (Object__String)i2, (Object__String)i0);
      return (Object__String)i2;
      goto l4;
l3:
      return (Object__String)((OOC_INT32)_c22);
l4:
      _failed_function(4211); return 0;
      ;
    }

    
    void OOC_X86_RuntimeData__Write_TypeDescrRef(OOC_SymbolTable__Type type) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)type;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4537)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
      type = (OOC_SymbolTable__Type)i0;
      i1 = *(OOC_UINT8*)((_check_pointer(i0, 4562))+38);
      if (i1) goto l3;
      i0 = (OOC_INT32)dw;
      OOC_X86_RuntimeData__DataWriterDesc_Null((OOC_X86_RuntimeData__DataWriter)i0);
      goto l4;
l3:
      i1 = (OOC_INT32)qtdData;
      i0 = (OOC_INT32)OOC_C_Naming__NameOfTypeDescriptor((OOC_SymbolTable__Type)i0, (OOC_C_Naming__QualTypeData)i1);
      i1 = (OOC_INT32)dw;
      OOC_X86_RuntimeData__DataWriterDesc_Adr((OOC_X86_RuntimeData__DataWriter)i1, (Object__String)i0);
l4:
      return;
      ;
    }

    
    void OOC_X86_RuntimeData__Write_ArrayTypeDescr(OOC_SymbolTable__Array array) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5;
      Object__String nameTypeDesc;
      Object__String nameTypeName;
      Object__String nameBaseTypes;
      OOC_SymbolTable__Type base;

      i0 = (OOC_INT32)qtdData;
      i1 = (OOC_INT32)array;
      i0 = (OOC_INT32)OOC_C_Naming__NameOfTypeDescriptor((OOC_SymbolTable__Type)i1, (OOC_C_Naming__QualTypeData)i0);
      i2 = (OOC_INT32)Object__Concat2((void*)i0,(void*)((OOC_INT32)_c23));
      nameTypeDesc = (Object__String)i0;
      nameBaseTypes = (Object__String)i2;
      i3 = (OOC_INT32)OOC_X86_RuntimeData__Write_WriteName((Object__String)((OOC_INT32)Object__Concat2((void*)i0,(void*)((OOC_INT32)_c24))), (OOC_SymbolTable__Type)i1);
      nameTypeName = (Object__String)i3;
      i4 = *(OOC_UINT8*)((_check_pointer(i1, 5082))+40);
      if (i4) goto l3;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5179))+44);
      base = (OOC_SymbolTable__Type)i4;
      
      goto l4;
l3:
      i4 = (OOC_INT32)OOC_SymbolTable__ArrayDesc_GetNonOpenElementType((OOC_SymbolTable__Array)i1);
      base = (OOC_SymbolTable__Type)i4;
      
l4:
      i5 = (OOC_INT32)dw;
      OOC_X86_RuntimeData__DataWriterDesc_Object((OOC_X86_RuntimeData__DataWriter)i5, (Object__String)i2, 4, 0u);
      OOC_X86_RuntimeData__Write_TypeDescrRef((OOC_SymbolTable__Type)i4);
      i5 = (OOC_INT32)dw;
      OOC_X86_RuntimeData__DataWriterDesc_Object((OOC_X86_RuntimeData__DataWriter)i5, (Object__String)i0, 36, 0u);
      i0 = (OOC_INT32)dw;
      OOC_X86_RuntimeData__DataWriterDesc_Adr((OOC_X86_RuntimeData__DataWriter)i0, (Object__String)i2);
      i0 = (OOC_INT32)dw;
      OOC_X86_RuntimeData__DataWriterDesc_Null((OOC_X86_RuntimeData__DataWriter)i0);
      i0 = (OOC_INT32)dw;
      OOC_X86_RuntimeData__DataWriterDesc_Null((OOC_X86_RuntimeData__DataWriter)i0);
      i0 = (OOC_INT32)dw;
      OOC_X86_RuntimeData__DataWriterDesc_Adr((OOC_X86_RuntimeData__DataWriter)i0, (Object__String)((OOC_INT32)_c25));
      i0 = (OOC_INT32)dw;
      OOC_X86_RuntimeData__DataWriterDesc_Adr((OOC_X86_RuntimeData__DataWriter)i0, (Object__String)i3);
      i0 = *(OOC_UINT8*)((_check_pointer(i1, 5603))+40);
      if (i0) goto l7;
      i0 = *(OOC_INT32*)((_check_pointer(i1, 5908))+32);
      i2 = (OOC_INT32)dw;
      OOC_X86_RuntimeData__DataWriterDesc_LongInt((OOC_X86_RuntimeData__DataWriter)i2, i0);
      i0 = *(OOC_INT32*)((_check_pointer(i1, 5962))+52);
      i2 = (OOC_INT32)dw;
      OOC_X86_RuntimeData__DataWriterDesc_LongInt((OOC_X86_RuntimeData__DataWriter)i2, i0);
      i0 = (OOC_INT32)dw;
      OOC_X86_RuntimeData__DataWriterDesc_TypeFlags((OOC_X86_RuntimeData__DataWriter)i0, (OOC_SymbolTable__Type)i1);
      i0 = (OOC_INT32)dw;
      OOC_X86_RuntimeData__DataWriterDesc_ShortInt((OOC_X86_RuntimeData__DataWriter)i0, (-1));
      goto l8;
l7:
      i0 = *(OOC_INT32*)((_check_pointer(i4, 5640))+32);
      _assert((i0>=0), 127, 5629);
      i0 = *(OOC_INT32*)((_check_pointer(i4, 5676))+32);
      i2 = (OOC_INT32)dw;
      OOC_X86_RuntimeData__DataWriterDesc_LongInt((OOC_X86_RuntimeData__DataWriter)i2, i0);
      i0 = OOC_SymbolTable__ArrayDesc_GetOpenDimensions((OOC_SymbolTable__Array)i1);
      i2 = (OOC_INT32)dw;
      OOC_X86_RuntimeData__DataWriterDesc_LongInt((OOC_X86_RuntimeData__DataWriter)i2, i0);
      i0 = (OOC_INT32)dw;
      OOC_X86_RuntimeData__DataWriterDesc_TypeFlags((OOC_X86_RuntimeData__DataWriter)i0, (OOC_SymbolTable__Type)i1);
      i0 = (OOC_INT32)dw;
      OOC_X86_RuntimeData__DataWriterDesc_ShortInt((OOC_X86_RuntimeData__DataWriter)i0, (-2));
l8:
      i0 = (OOC_INT32)dw;
      OOC_X86_RuntimeData__DataWriterDesc_FixAlign((OOC_X86_RuntimeData__DataWriter)i0, 36);
      return;
      ;
    }

    
    void OOC_X86_RuntimeData__Write_RecordTypeDescr(OOC_SymbolTable__Record record) {
      register OOC_INT32 i0,i1,i2,i3;
      Object__String nameTypeDesc;
      Object__String nameTypeName;
      Object__String nameBaseTypes;
      OOC_INT32 len;
      auto OOC_INT32 OOC_X86_RuntimeData__Write_RecordTypeDescr_BaseTypes(OOC_SymbolTable__Type t);
        
        OOC_INT32 OOC_X86_RuntimeData__Write_RecordTypeDescr_BaseTypes(OOC_SymbolTable__Type t) {
          register OOC_INT32 i0,i1,i2;

          i0 = (OOC_INT32)t;
          i1 = i0==(OOC_INT32)0;
          if (i1) goto l3;
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6475)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
          t = (OOC_SymbolTable__Type)i0;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6520)))), &_td_OOC_SymbolTable__RecordDesc, 6520)), 6527))+40);
          i1 = OOC_X86_RuntimeData__Write_RecordTypeDescr_BaseTypes((OOC_SymbolTable__Type)i1);
          i2 = (OOC_INT32)qtdData;
          i0 = (OOC_INT32)OOC_C_Naming__NameOfTypeDescriptor((OOC_SymbolTable__Type)i0, (OOC_C_Naming__QualTypeData)i2);
          i2 = (OOC_INT32)dw;
          OOC_X86_RuntimeData__DataWriterDesc_Adr((OOC_X86_RuntimeData__DataWriter)i2, (Object__String)i0);
          return (i1+1);
          goto l4;
l3:
          return (-1);
l4:
          _failed_function(6322); return 0;
          ;
        }


      i0 = (OOC_INT32)qtdData;
      i1 = (OOC_INT32)record;
      i0 = (OOC_INT32)OOC_C_Naming__NameOfTypeDescriptor((OOC_SymbolTable__Type)i1, (OOC_C_Naming__QualTypeData)i0);
      i2 = (OOC_INT32)Object__Concat2((void*)i0,(void*)((OOC_INT32)_c26));
      nameTypeDesc = (Object__String)i0;
      nameBaseTypes = (Object__String)i2;
      i0 = (OOC_INT32)OOC_X86_RuntimeData__Write_WriteName((Object__String)((OOC_INT32)Object__Concat2((void*)i0,(void*)((OOC_INT32)_c27))), (OOC_SymbolTable__Type)i1);
      nameTypeName = (Object__String)i0;
      i0 = OOC_SymbolTable__RecordDesc_ExtensionLevel((OOC_SymbolTable__Record)i1);
      i3 = (OOC_INT32)dw;
      OOC_X86_RuntimeData__DataWriterDesc_Object((OOC_X86_RuntimeData__DataWriter)i3, (Object__String)i2, ((i0+1)*4), 0u);
      i0 = OOC_X86_RuntimeData__Write_RecordTypeDescr_BaseTypes((OOC_SymbolTable__Type)i1);
      len = i0;
      i1 = (OOC_INT32)nameTypeDesc;
      i2 = (OOC_INT32)dw;
      OOC_X86_RuntimeData__DataWriterDesc_Object((OOC_X86_RuntimeData__DataWriter)i2, (Object__String)i1, 36, 0u);
      i1 = (OOC_INT32)dw;
      i2 = (OOC_INT32)nameBaseTypes;
      OOC_X86_RuntimeData__DataWriterDesc_Adr((OOC_X86_RuntimeData__DataWriter)i1, (Object__String)i2);
      i1 = (OOC_INT32)dw;
      OOC_X86_RuntimeData__DataWriterDesc_Null((OOC_X86_RuntimeData__DataWriter)i1);
      i1 = (OOC_INT32)dw;
      OOC_X86_RuntimeData__DataWriterDesc_Null((OOC_X86_RuntimeData__DataWriter)i1);
      i1 = (OOC_INT32)dw;
      OOC_X86_RuntimeData__DataWriterDesc_Adr((OOC_X86_RuntimeData__DataWriter)i1, (Object__String)((OOC_INT32)_c28));
      i1 = (OOC_INT32)dw;
      i2 = (OOC_INT32)nameTypeName;
      OOC_X86_RuntimeData__DataWriterDesc_Adr((OOC_X86_RuntimeData__DataWriter)i1, (Object__String)i2);
      i1 = (OOC_INT32)record;
      i2 = *(OOC_INT32*)((_check_pointer(i1, 7329))+32);
      i3 = (OOC_INT32)dw;
      OOC_X86_RuntimeData__DataWriterDesc_LongInt((OOC_X86_RuntimeData__DataWriter)i3, i2);
      i2 = (OOC_INT32)dw;
      OOC_X86_RuntimeData__DataWriterDesc_LongInt((OOC_X86_RuntimeData__DataWriter)i2, i0);
      i0 = (OOC_INT32)dw;
      OOC_X86_RuntimeData__DataWriterDesc_TypeFlags((OOC_X86_RuntimeData__DataWriter)i0, (OOC_SymbolTable__Type)i1);
      i0 = (OOC_INT32)dw;
      OOC_X86_RuntimeData__DataWriterDesc_ShortInt((OOC_X86_RuntimeData__DataWriter)i0, (-3));
      i0 = (OOC_INT32)dw;
      OOC_X86_RuntimeData__DataWriterDesc_FixAlign((OOC_X86_RuntimeData__DataWriter)i0, 36);
      return;
      ;
    }

    
    void OOC_X86_RuntimeData__Write_PointerTypeDescr(OOC_SymbolTable__Pointer pointer) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      Object__String nameTypeDesc;
      Object__String nameTypeName;
      Object__String nameBaseTypes;

      i0 = (OOC_INT32)qtdData;
      i1 = (OOC_INT32)pointer;
      i0 = (OOC_INT32)OOC_C_Naming__NameOfTypeDescriptor((OOC_SymbolTable__Type)i1, (OOC_C_Naming__QualTypeData)i0);
      i2 = (OOC_INT32)Object__Concat2((void*)i0,(void*)((OOC_INT32)_c29));
      nameTypeDesc = (Object__String)i0;
      nameBaseTypes = (Object__String)i2;
      i3 = (OOC_INT32)OOC_X86_RuntimeData__Write_WriteName((Object__String)((OOC_INT32)Object__Concat2((void*)i0,(void*)((OOC_INT32)_c30))), (OOC_SymbolTable__Type)i1);
      nameTypeName = (Object__String)i3;
      i4 = (OOC_INT32)dw;
      OOC_X86_RuntimeData__DataWriterDesc_Object((OOC_X86_RuntimeData__DataWriter)i4, (Object__String)i2, 4, 0u);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8004))+40);
      OOC_X86_RuntimeData__Write_TypeDescrRef((OOC_SymbolTable__Type)i4);
      i4 = (OOC_INT32)dw;
      OOC_X86_RuntimeData__DataWriterDesc_Object((OOC_X86_RuntimeData__DataWriter)i4, (Object__String)i0, 36, 0u);
      i0 = (OOC_INT32)dw;
      OOC_X86_RuntimeData__DataWriterDesc_Adr((OOC_X86_RuntimeData__DataWriter)i0, (Object__String)i2);
      i0 = (OOC_INT32)dw;
      OOC_X86_RuntimeData__DataWriterDesc_Null((OOC_X86_RuntimeData__DataWriter)i0);
      i0 = (OOC_INT32)dw;
      OOC_X86_RuntimeData__DataWriterDesc_Null((OOC_X86_RuntimeData__DataWriter)i0);
      i0 = (OOC_INT32)dw;
      OOC_X86_RuntimeData__DataWriterDesc_Adr((OOC_X86_RuntimeData__DataWriter)i0, (Object__String)((OOC_INT32)_c31));
      i0 = (OOC_INT32)dw;
      OOC_X86_RuntimeData__DataWriterDesc_Adr((OOC_X86_RuntimeData__DataWriter)i0, (Object__String)i3);
      i0 = *(OOC_INT32*)((_check_pointer(i1, 8347))+32);
      i2 = (OOC_INT32)dw;
      OOC_X86_RuntimeData__DataWriterDesc_LongInt((OOC_X86_RuntimeData__DataWriter)i2, i0);
      i0 = (OOC_INT32)dw;
      OOC_X86_RuntimeData__DataWriterDesc_LongInt((OOC_X86_RuntimeData__DataWriter)i0, (-1));
      i0 = (OOC_INT32)dw;
      OOC_X86_RuntimeData__DataWriterDesc_TypeFlags((OOC_X86_RuntimeData__DataWriter)i0, (OOC_SymbolTable__Type)i1);
      i0 = (OOC_INT32)dw;
      OOC_X86_RuntimeData__DataWriterDesc_ShortInt((OOC_X86_RuntimeData__DataWriter)i0, (-4));
      i0 = (OOC_INT32)dw;
      OOC_X86_RuntimeData__DataWriterDesc_FixAlign((OOC_X86_RuntimeData__DataWriter)i0, 36);
      return;
      ;
    }

    
    void OOC_X86_RuntimeData__Write_Traverse(OOC_SymbolTable__Item item, OOC_SymbolTable__ProcDecl proc) {
      register OOC_INT32 i0,i1,i2;
      OOC_SymbolTable__Item nested;
      auto OOC_CHAR8 OOC_X86_RuntimeData__Write_Traverse_IsParameter(OOC_SymbolTable__Item item);
        
        OOC_CHAR8 OOC_X86_RuntimeData__Write_Traverse_IsParameter(OOC_SymbolTable__Item item) {
          register OOC_INT32 i0,i1,i2;

          i0 = (OOC_INT32)item;
          i1 = (OOC_INT32)proc;
          i2 = i0!=i1;
          if (i2) goto l3;
          i2=0u;
          goto l9;
l3:
          i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8802)))), &_td_OOC_SymbolTable__VarDeclDesc);
          if (i2) goto l6;
          i2=0u;
          goto l7;
l6:
          i2 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8829)))), &_td_OOC_SymbolTable__VarDeclDesc, 8829)), 8837))+56);
          
l7:
          i2 = !i2;
          
l9:
          if (!i2) goto l25;
l12_loop:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8876))+4);
          item = (OOC_SymbolTable__Item)i0;
          i2 = i0!=i1;
          if (i2) goto l15;
          i2=0u;
          goto l21;
l15:
          i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8802)))), &_td_OOC_SymbolTable__VarDeclDesc);
          if (i2) goto l18;
          i2=0u;
          goto l19;
l18:
          i2 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8829)))), &_td_OOC_SymbolTable__VarDeclDesc, 8829)), 8837))+56);
          
l19:
          i2 = !i2;
          
l21:
          if (i2) goto l12_loop;
l25:
          return (i0!=i1);
          ;
        }


      i0 = (OOC_INT32)item;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8977)))), &_td_OOC_SymbolTable__ArrayDesc);
      if (i1) goto l20;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9105)))), &_td_OOC_SymbolTable__RecordDesc);
      if (i1) goto l15;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9214)))), &_td_OOC_SymbolTable__PointerDesc);
      if (i1) goto l10;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9325)))), &_td_OOC_SymbolTable__ProcDeclDesc);
      if (!i1) goto l28;
      proc = (OOC_SymbolTable__ProcDecl)i0;
      goto l28;
l10:
      i1 = *(OOC_UINT8*)((_check_pointer(i0, 9246))+38);
      if (!i1) goto l28;
      OOC_X86_RuntimeData__Write_PointerTypeDescr((OOC_SymbolTable__Pointer)i0);
      goto l28;
l15:
      i1 = *(OOC_UINT8*)((_check_pointer(i0, 9136))+38);
      if (!i1) goto l28;
      OOC_X86_RuntimeData__Write_RecordTypeDescr((OOC_SymbolTable__Record)i0);
      goto l28;
l20:
      i1 = *(OOC_UINT8*)((_check_pointer(i0, 9007))+38);
      if (i1) goto l23;
      i1=0u;
      goto l25;
l23:
      i1 = OOC_X86_RuntimeData__Write_Traverse_IsParameter((OOC_SymbolTable__Item)i0);
      i1 = !i1;
      
l25:
      if (!i1) goto l28;
      OOC_X86_RuntimeData__Write_ArrayTypeDescr((OOC_SymbolTable__Array)i0);
l28:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9509))+8);
      nested = (OOC_SymbolTable__Item)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l36;
      i1 = (OOC_INT32)proc;
      
l31_loop:
      OOC_X86_RuntimeData__Write_Traverse((OOC_SymbolTable__Item)i0, (OOC_SymbolTable__ProcDecl)i1);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9609));
      nested = (OOC_SymbolTable__Item)i0;
      i2 = i0!=(OOC_INT32)0;
      if (i2) goto l31_loop;
l36:
      return;
      ;
    }


  qtdData = (OOC_C_Naming__QualTypeData)(OOC_INT32)0;
  i0 = (OOC_INT32)sb;
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_RuntimeData__DataWriter.baseTypes[0]);
  OOC_X86_RuntimeData__DataWriterDesc_INIT((OOC_X86_RuntimeData__DataWriter)i1, (ADT_StringBuffer__StringBuffer)i0, 4);
  dw = (OOC_X86_RuntimeData__DataWriter)i1;
  i0 = (OOC_INT32)ADT_ArrayList__New(16);
  tdNames = (ADT_ArrayList__ArrayList)i0;
  i0 = (OOC_INT32)symTab;
  OOC_X86_RuntimeData__Write_Traverse((OOC_SymbolTable__Item)i0, (OOC_SymbolTable__ProcDecl)(OOC_INT32)0);
  i0 = (OOC_INT32)tdNames;
  i1 = (OOC_INT32)symTab;
  OOC_X86_RuntimeData__Write_ModuleDescr((OOC_SymbolTable__Module)i1, (ADT_ArrayList__ArrayList)i0);
  return;
  ;
}

void OOC_OOC_X86_RuntimeData_init(void) {
  _c0 = Object__NewLatin1Region("\012\011.data", 8, 0, 7);
  _c1 = Object__NewLatin1Region("\012\011.align ", 10, 0, 9);
  _c2 = Object__NewLatin1Region("\012\011.align ", 10, 0, 9);
  _c3 = Object__NewLatin1Region("\012.globl ", 9, 0, 8);
  _c4 = Object__NewLatin1Region("\012\011.type ", 9, 0, 8);
  _c5 = Object__NewLatin1Region(", @object", 10, 0, 9);
  _c6 = Object__NewLatin1Region("\012\011.size ", 9, 0, 8);
  _c7 = Object__NewLatin1Region(", ", 3, 0, 2);
  _c8 = Object__NewLatin1Char(10u);
  _c9 = Object__NewLatin1Char(58u);
  _c10 = Object__NewLatin1Region("\012\011.zero ", 9, 0, 8);
  _c11 = Object__NewLatin1Region("\012\011.long ", 9, 0, 8);
  _c12 = Object__NewLatin1Region("\012\011.long 0", 10, 0, 9);
  _c13 = Object__NewLatin1Region("\012\011.long ", 9, 0, 8);
  _c14 = Object__NewLatin1Region("\012\011.byte ", 9, 0, 8);
  _c15 = Object__NewLatin1Region("\012\011.string \"", 12, 0, 11);
  _c16 = Object__NewLatin1Char(34u);
  _c17 = Object__NewLatin1Region("_mid_name", 10, 0, 9);
  _c18 = Object__NewLatin1Region("_mid_tdlist", 12, 0, 11);
  _c19 = Object__NewLatin1Region("_mid", 5, 0, 4);
  _c20 = Object__NewLatin1Region("_mid_name", 10, 0, 9);
  _c21 = Object__NewLatin1Region("_mid_tdlist", 12, 0, 11);
  _c22 = Object__NewLatin1Char(48u);
  _c23 = Object__NewLatin1Region("_base_types", 12, 0, 11);
  _c24 = Object__NewLatin1Region("_name", 6, 0, 5);
  _c25 = Object__NewLatin1Region("_mid", 5, 0, 4);
  _c26 = Object__NewLatin1Region("_base_types", 12, 0, 11);
  _c27 = Object__NewLatin1Region("_name", 6, 0, 5);
  _c28 = Object__NewLatin1Region("_mid", 5, 0, 4);
  _c29 = Object__NewLatin1Region("_base_types", 12, 0, 11);
  _c30 = Object__NewLatin1Region("_name", 6, 0, 5);
  _c31 = Object__NewLatin1Region("_mid", 5, 0, 4);

  return;
  ;
}

/* --- */
