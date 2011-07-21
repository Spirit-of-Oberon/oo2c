#include <OOC/C/DeclWriter.d>
#include <__oo2c.h>
#include <setjmp.h>

static void OOC_C_DeclWriter__InitWriter(OOC_C_DeclWriter__Writer w, IO__ByteChannel ch, URI__HierarchicalURI baseURI) {
  register OOC_INT32 i0,i1,i2;
  auto void OOC_C_DeclWriter__InitWriter_CreateBasicType(OOC_INT8 id, const OOC_CHAR8 repr__ref[], OOC_LEN repr_0d);
    
    void OOC_C_DeclWriter__InitWriter_CreateBasicType(OOC_INT8 id, const OOC_CHAR8 repr__ref[], OOC_LEN repr_0d) {
      register OOC_INT32 i0,i1,i2;
      OOC_ALLOCATE_VPAR(repr,OOC_CHAR8 ,repr_0d)

      OOC_INITIALIZE_VPAR(repr__ref,repr,OOC_CHAR8 ,repr_0d)
      i0 = (OOC_INT32)w;
      i1 = id;
      i2 = (OOC_INT32)OOC_C_DeclWriter__NewBasicType(i1, (void*)(OOC_INT32)repr, repr_0d);
      *(OOC_INT32*)(((_check_pointer(i0, 9619))+24)+(_check_index(i1, 17, OOC_UINT8, 9630))*4) = i2;
      return;
      ;
    }


  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)ch;
  *(OOC_INT32*)(_check_pointer(i0, 9703)) = i1;
  i2 = (OOC_INT32)baseURI;
  *(OOC_INT32*)((_check_pointer(i0, 9720))+4) = i2;
  *(OOC_INT32*)((_check_pointer(i0, 9747))+20) = 0;
  i1 = (OOC_INT32)IO_TextRider__ConnectWriter((IO__ByteChannel)i1);
  *(OOC_INT32*)((_check_pointer(i0, 9777))+8) = i1;
  i1 = (OOC_INT32)ADT_ArrayList__New(4);
  *(OOC_INT32*)((_check_pointer(i0, 9828))+12) = i1;
  i1 = (OOC_INT32)ADT_ArrayList__New(16);
  *(OOC_INT32*)((_check_pointer(i0, 9866))+16) = i1;
  OOC_C_DeclWriter__InitWriter_CreateBasicType(0, "void", 5);
  OOC_C_DeclWriter__InitWriter_CreateBasicType(1, "OOC_PTR", 8);
  OOC_C_DeclWriter__InitWriter_CreateBasicType(2, "OOC_INT8", 9);
  OOC_C_DeclWriter__InitWriter_CreateBasicType(3, "OOC_INT16", 10);
  OOC_C_DeclWriter__InitWriter_CreateBasicType(4, "OOC_INT32", 10);
  OOC_C_DeclWriter__InitWriter_CreateBasicType(5, "OOC_INT64", 10);
  OOC_C_DeclWriter__InitWriter_CreateBasicType(6, "OOC_UINT8", 10);
  OOC_C_DeclWriter__InitWriter_CreateBasicType(7, "OOC_UINT16", 11);
  OOC_C_DeclWriter__InitWriter_CreateBasicType(8, "OOC_UINT32", 11);
  OOC_C_DeclWriter__InitWriter_CreateBasicType(9, "OOC_UINT64", 11);
  OOC_C_DeclWriter__InitWriter_CreateBasicType(10, "OOC_CHAR8", 10);
  OOC_C_DeclWriter__InitWriter_CreateBasicType(11, "OOC_CHAR16", 11);
  OOC_C_DeclWriter__InitWriter_CreateBasicType(12, "OOC_CHAR32", 11);
  OOC_C_DeclWriter__InitWriter_CreateBasicType(13, "OOC_REAL32", 11);
  OOC_C_DeclWriter__InitWriter_CreateBasicType(14, "OOC_REAL64", 11);
  OOC_C_DeclWriter__InitWriter_CreateBasicType(15, "OOC_LEN", 8);
  OOC_C_DeclWriter__InitWriter_CreateBasicType(16, "RT0__Struct", 12);
  return;
  ;
}

OOC_C_DeclWriter__Writer OOC_C_DeclWriter__NewWriter(IO__ByteChannel ch, URI__HierarchicalURI baseURI) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_C_DeclWriter__Writer.baseTypes[0]);
  i1 = (OOC_INT32)ch;
  i2 = (OOC_INT32)baseURI;
  OOC_C_DeclWriter__InitWriter((OOC_C_DeclWriter__Writer)i0, (IO__ByteChannel)i1, (URI__HierarchicalURI)i2);
  return (OOC_C_DeclWriter__Writer)i0;
  ;
}

void OOC_C_DeclWriter__WriterDesc_CopyTo(OOC_C_DeclWriter__Writer w, OOC_C_DeclWriter__Writer dest) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)dest;
  i1 = (OOC_INT32)w;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 11370));
  *(OOC_INT32*)(_check_pointer(i0, 11361)) = i2;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11398))+4);
  *(OOC_INT32*)((_check_pointer(i0, 11384))+4) = i2;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11434))+8);
  *(OOC_INT32*)((_check_pointer(i0, 11417))+8) = i2;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11471))+12);
  *(OOC_INT32*)((_check_pointer(i0, 11456))+12) = i2;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11510))+16);
  *(OOC_INT32*)((_check_pointer(i0, 11491))+16) = i2;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 11552))+20);
  *(OOC_INT32*)((_check_pointer(i0, 11534))+20) = i2;
  _copy_block(((_check_pointer(i1, 11591))+24),((_check_pointer(i0, 11575))+24),68);
  return;
  ;
}

void OOC_C_DeclWriter__WriterDesc_WriteString(OOC_C_DeclWriter__Writer w, const OOC_CHAR8 str[], OOC_LEN str_0d) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11698))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11698))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11710)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (void*)(OOC_INT32)str, str_0d);
  return;
  ;
}

void OOC_C_DeclWriter__WriterDesc_WriteObject(OOC_C_DeclWriter__Writer w, Object__Object obj) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11820))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11820))+8);
  i2 = (OOC_INT32)obj;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11831)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i0, (Object__Object)i2);
  return;
  ;
}

void OOC_C_DeclWriter__WriterDesc_WriteChar(OOC_C_DeclWriter__Writer w, OOC_CHAR8 ch) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11928))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11928))+8);
  i2 = ch;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11940)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i0, i2);
  return;
  ;
}

void OOC_C_DeclWriter__WriterDesc_WriteLn(OOC_C_DeclWriter__Writer w) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12022))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12022))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 12034)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
  return;
  ;
}

void OOC_C_DeclWriter__WriterDesc_WriteLInt(OOC_C_DeclWriter__Writer w, OOC_INT32 lint, OOC_INT32 n) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12134))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12134))+8);
  i2 = lint;
  i3 = n;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 12146)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i0, i2, i3);
  return;
  ;
}

void OOC_C_DeclWriter__WriterDesc_Indent(OOC_C_DeclWriter__Writer w, OOC_INT32 delta) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)w;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 12312))+20);
  i2 = delta;
  *(OOC_INT32*)((_check_pointer(i0, 12312))+20) = (i1+i2);
  return;
  ;
}

void OOC_C_DeclWriter__WriterDesc_Newline(OOC_C_DeclWriter__Writer w) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_INT32 i;

  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12419)))), OOC_C_DeclWriter__WriterDesc_WriteLn)),OOC_C_DeclWriter__WriterDesc_WriteLn)((OOC_C_DeclWriter__Writer)i0);
  i = 1;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 12449))+20);
  i2 = 1<=i1;
  if (!i2) goto l8;
  i2=1;
l3_loop:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12473)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "  ", 3);
  i2 = i2+1;
  i = i2;
  i3 = i2<=i1;
  if (i3) goto l3_loop;
l8:
  return;
  ;
}

void OOC_C_DeclWriter__WriterDesc_WriteInclude(OOC_C_DeclWriter__Writer w, const OOC_CHAR8 includePath__ref[], OOC_LEN includePath_0d) {
  register OOC_INT32 i0;
  OOC_ALLOCATE_VPAR(includePath,OOC_CHAR8 ,includePath_0d)

  OOC_INITIALIZE_VPAR(includePath__ref,includePath,OOC_CHAR8 ,includePath_0d)
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12686)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "#include <", 11);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12721)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, (void*)(OOC_INT32)includePath, includePath_0d);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12755)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ">", 2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12781)))), OOC_C_DeclWriter__WriterDesc_WriteLn)),OOC_C_DeclWriter__WriterDesc_WriteLn)((OOC_C_DeclWriter__Writer)i0);
  return;
  ;
}

void OOC_C_DeclWriter__WriterDesc_Close(OOC_C_DeclWriter__Writer w) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 12919));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 12919));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 12922)))), IO__ChannelDesc_CloseAndRegister)),IO__ChannelDesc_CloseAndRegister)((IO__Channel)i0);
  return;
  ;
}

void OOC_C_DeclWriter__WriterDesc_WriteConst(OOC_C_DeclWriter__Writer w, Object_Boxed__Object value, OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  register OOC_REAL64 d0;
  Object__String s;
  OOC_INT32 charValue;
  OOC_INT32 i;
  OOC_INT32 len;
  OOC_CHAR8 paren;
  auto void OOC_C_DeclWriter__WriterDesc_WriteConst_WriteOct(OOC_INT32 ch);
  auto void OOC_C_DeclWriter__WriterDesc_WriteConst_WriteChar(OOC_INT32 charValue);
    
    void OOC_C_DeclWriter__WriterDesc_WriteConst_WriteOct(OOC_INT32 ch) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)w;
      i1 = ch;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13554)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i0, (i1+48));
      return;
      ;
    }

    
    void OOC_C_DeclWriter__WriterDesc_WriteConst_WriteChar(OOC_INT32 charValue) {
      register OOC_INT32 i0,i1;

      i0 = charValue;
      i1 = i0<32;
      if (i1) goto l3;
      i1 = i0>=127;
      
      goto l5;
l3:
      i1=1u;
l5:
      if (i1) goto l7;
      i1 = i0==39;
      
      goto l9;
l7:
      i1=1u;
l9:
      if (i1) goto l11;
      i1 = i0==92;
      
      goto l13;
l11:
      i1=1u;
l13:
      if (i1) goto l15;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 13940)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, i0);
      goto l16;
l15:
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 13790)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 92u);
      OOC_C_DeclWriter__WriterDesc_WriteConst_WriteOct((i0>>6));
      OOC_C_DeclWriter__WriterDesc_WriteConst_WriteOct((_mod((i0>>3),8)));
      OOC_C_DeclWriter__WriterDesc_WriteConst_WriteOct((_mod(i0,8)));
l16:
      return;
      ;
    }


  i0 = (OOC_INT32)value;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l111;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14086)))), &_td_Object_Boxed__BooleanDesc);
  if (i1) goto l105;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14260)))), &_td_Object_Boxed__StringDesc);
  if (i1) goto l38;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16839)))), &_td_Object_Boxed__LongRealDesc);
  if (i1) goto l27;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17146)))), &_td_Object_BigInt__BigIntDesc);
  if (i1) goto l15;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17737)))), &_td_Object_Boxed__SetDesc);
  if (i1) goto l13;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17730)))), 17730);
  goto l112;
l13:
  i1 = (OOC_INT32)w;
  i0 = *(OOC_UINT32*)(_check_pointer(i0, 17812));
  i0 = (OOC_INT32)Object_BigInt__NewInt((_type_cast_fast(OOC_INT32, OOC_UINT32, i0)));
  i2 = (OOC_INT32)type;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17761)))), OOC_C_DeclWriter__WriterDesc_WriteConst)),OOC_C_DeclWriter__WriterDesc_WriteConst)((OOC_C_DeclWriter__Writer)i1, (Object_Boxed__Object)i0, (OOC_SymbolTable__Type)i2);
  goto l112;
l15:
  i1 = Object_BigInt__BigIntDesc_ToLongInt((Object_BigInt__BigInt)i0);
  i1 = i1==(-2147483647-1);
  if (i1) goto l24;
  i1 = Object_BigInt__BigIntDesc_Sign((Object_BigInt__BigInt)i0);
  paren = (i1<0);
  if (!(i1<0)) goto l20;
  i2 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 17587)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, "(", 2);
l20:
  i2 = (OOC_INT32)w;
  i0 = (OOC_INT32)Object_BigInt__BigIntDesc_ToString((Object_BigInt__BigInt)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 17621)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i2, (Object__Object)i0);
  if (!(i1<0)) goto l112;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 17679)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, ")", 2);
  goto l112;
l24:
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17411)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "(-", 3);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17444)))), OOC_C_DeclWriter__WriterDesc_WriteLInt)),OOC_C_DeclWriter__WriterDesc_WriteLInt)((OOC_C_DeclWriter__Writer)i0, 2147483647, 0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17487)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "-1)", 4);
  goto l112;
l27:
  d0 = *(OOC_REAL64*)(_check_pointer(i0, 16882));
  paren = (d0<0.0000000000000000);
  if (!(d0<0.0000000000000000)) goto l30;
  i1 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16918)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "(", 2);
l30:
  i1 = (OOC_INT32)w;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16969)))), Object_Boxed__LongRealDesc_ToString)),Object_Boxed__LongRealDesc_ToString)((Object_Boxed__LongReal)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16950)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i1, (Object__Object)i0);
  i0 = (OOC_INT32)type;
  i0 = OOC_SymbolTable_TypeRules__IsPredefType((OOC_SymbolTable__Type)i0, 8);
  if (!i0) goto l34;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17045)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "f", 2);
l34:
  if (!(d0<0.0000000000000000)) goto l112;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17101)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ")", 2);
  goto l112;
l38:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14296));
  s = (Object__String)i0;
  i1 = (OOC_INT32)type;
  i2 = (OOC_INT32)OOC_SymbolTable_TypeRules__BaseCharType((OOC_SymbolTable__Type)i1);
  i2 = OOC_SymbolTable_TypeRules__IsPredefType((OOC_SymbolTable__Type)i2, 1);
  if (i2) goto l86;
  i2 = OOC_SymbolTable_TypeRules__IsCharType((OOC_SymbolTable__Type)i1);
  if (i2) goto l63;
  i1 = *(OOC_INT16*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16185)))), &_td_OOC_SymbolTable__PredefTypeDesc, 16185)), 16196))+40);
  switch (i1) {
  case 14:
    i1 = (OOC_INT32)w;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16255)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "((OOC_CHAR16[]){", 17);
    goto l47;
  case 15:
    i1 = (OOC_INT32)w;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16343)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "((OOC_CHAR32[]){", 17);
    goto l47;
  default:
    _failed_case(i1, 16171);
    goto l47;
  }
l47:
  i = 0;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 16424));
  len = i1;
  i2 = (OOC_INT32)w;
  i3 = 0!=i1;
  if (i3) goto l50;
  i0=0;
  goto l59;
l50:
  i3=0;
l51_loop:
  i3 = i3!=0;
  if (!i3) goto l54;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 16511)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i2, 44u);
l54:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 16564))+8);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 16564))+8);
  i5 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16594)))), Object__StringDesc_NextChar)),Object__StringDesc_NextChar)((Object__String)i0, (void*)(OOC_INT32)&i);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 16576)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i4, i5, 0);
  i3 = i;
  i4 = i3!=i1;
  if (i4) goto l51_loop;
l58:
  i0=i3;
l59:
  i0 = i0!=0;
  if (!i0) goto l62;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 16673)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i2, 44u);
l62:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 16722))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 16722))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16734)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i1, 0, 0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 16767)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, "})", 3);
  goto l112;
l63:
  i1 = *(OOC_INT16*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15297)))), &_td_OOC_SymbolTable__PredefTypeDesc, 15297)), 15308))+40);
  switch (i1) {
  case 2:
    i1 = (OOC_INT32)w;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15361)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "(OOC_CHAR16)", 13);
    goto l68;
  case 3:
    i1 = (OOC_INT32)w;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15439)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "(OOC_CHAR32)", 13);
    goto l68;
  default:
    _failed_case(i1, 15283);
    goto l68;
  }
l68:
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15518)))), Object__StringDesc_CharAt)),Object__StringDesc_CharAt)((Object__String)i0, 0);
  charValue = i0;
  i1 = (OOC_UINT32)i0<(OOC_UINT32)32;
  if (i1) goto l71;
  i1 = (OOC_UINT32)i0>=(OOC_UINT32)127;
  
  goto l73;
l71:
  i1=1u;
l73:
  if (i1) goto l75;
  i1 = i0==39;
  
  goto l77;
l75:
  i1=1u;
l77:
  if (i1) goto l79;
  i1 = i0==92;
  
  goto l81;
l79:
  i1=1u;
l81:
  if (i1) goto l83;
  i1 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15758)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 39u);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15792)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15838)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 39u);
  goto l112;
l83:
  i1 = (OOC_INT32)w;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15686))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15686))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 15698)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i1, i0, 0);
  goto l112;
l86:
  i1 = *(OOC_INT16*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14395)))), &_td_OOC_SymbolTable__PredefTypeDesc, 14395)), 14406))+40);
  i1 = i1==1;
  if (i1) goto l101;
  i1 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14817)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 34u);
  i = 0;
  i0 = *(OOC_INT32*)(_check_pointer(i0, 14866));
  len = i0;
  i0 = 0!=i0;
  if (!i0) goto l100;
  i0=0;
l91_loop:
  i1 = (OOC_INT32)s;
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14926)))), Object__StringDesc_CharAt)),Object__StringDesc_CharAt)((Object__String)i1, i0);
  i0 = i0==34u;
  if (i0) goto l94;
  i0 = i;
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15099)))), Object__StringDesc_CharAt)),Object__StringDesc_CharAt)((Object__String)i1, i0);
  OOC_C_DeclWriter__WriterDesc_WriteConst_WriteChar(i0);
  goto l95;
l94:
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14968)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "\134\"", 3);
l95:
  i0 = i;
  i0 = i0+1;
  i = i0;
  i1 = len;
  i1 = i0!=i1;
  if (i1) goto l91_loop;
l100:
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15183)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i0, 34u);
  goto l112;
l101:
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14665)))), Object__StringDesc_CharAt)),Object__StringDesc_CharAt)((Object__String)i0, 0);
  charValue = i0;
  i1 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14691)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "(OOC_CHAR8)\047", 13);
  OOC_C_DeclWriter__WriterDesc_WriteConst_WriteChar(i0);
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14770)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i0, 39u);
  goto l112;
l105:
  i0 = *(OOC_UINT8*)(_check_pointer(i0, 14121));
  if (i0) goto l108;
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14195)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "OOC_FALSE", 10);
  goto l112;
l108:
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14145)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "OOC_TRUE", 9);
  goto l112;
l111:
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14040)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "0", 2);
l112:
  return;
  ;
}

void OOC_C_DeclWriter__WriterDesc_WriteBasicConst(OOC_C_DeclWriter__Writer w, Object_Boxed__Object value, OOC_INT8 type) {
  register OOC_INT32 i0,i1,i2,i3;
  register OOC_REAL64 d0;
  Object__String s;
  OOC_INT32 charValue;
  OOC_CHAR8 paren;
  OOC_CHAR8 _signed;
  auto void OOC_C_DeclWriter__WriterDesc_WriteBasicConst_WriteOct(OOC_INT32 ch);
  auto void OOC_C_DeclWriter__WriterDesc_WriteBasicConst_WriteChar(OOC_INT32 charValue);
    
    void OOC_C_DeclWriter__WriterDesc_WriteBasicConst_WriteOct(OOC_INT32 ch) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)w;
      i1 = ch;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18443)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i0, (i1+48));
      return;
      ;
    }

    
    void OOC_C_DeclWriter__WriterDesc_WriteBasicConst_WriteChar(OOC_INT32 charValue) {
      register OOC_INT32 i0,i1;

      i0 = charValue;
      i1 = i0<32;
      if (i1) goto l3;
      i1 = i0>=127;
      
      goto l5;
l3:
      i1=1u;
l5:
      if (i1) goto l7;
      i1 = i0==39;
      
      goto l9;
l7:
      i1=1u;
l9:
      if (i1) goto l11;
      i1 = i0==92;
      
      goto l13;
l11:
      i1=1u;
l13:
      if (i1) goto l15;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 18829)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, i0);
      goto l16;
l15:
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 18679)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 92u);
      OOC_C_DeclWriter__WriterDesc_WriteBasicConst_WriteOct((i0>>6));
      OOC_C_DeclWriter__WriterDesc_WriteBasicConst_WriteOct((_mod((i0>>3),8)));
      OOC_C_DeclWriter__WriterDesc_WriteBasicConst_WriteOct((_mod(i0,8)));
l16:
      return;
      ;
    }


  i0 = (OOC_INT32)value;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l81;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18975)))), &_td_Object_Boxed__BooleanDesc);
  if (i1) goto l75;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19149)))), &_td_Object_Boxed__StringDesc);
  if (i1) goto l45;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20186)))), &_td_Object_Boxed__LongRealDesc);
  if (i1) goto l34;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20474)))), &_td_Object_BigInt__BigIntDesc);
  if (i1) goto l15;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21181)))), &_td_Object_Boxed__SetDesc);
  if (i1) goto l13;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21174)))), 21174);
  goto l82;
l13:
  i1 = (OOC_INT32)w;
  i0 = *(OOC_UINT32*)(_check_pointer(i0, 21261));
  i0 = (OOC_INT32)Object_BigInt__NewInt((_type_cast_fast(OOC_INT32, OOC_UINT32, i0)));
  i2 = type;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 21205)))), OOC_C_DeclWriter__WriterDesc_WriteBasicConst)),OOC_C_DeclWriter__WriterDesc_WriteBasicConst)((OOC_C_DeclWriter__Writer)i1, (Object_Boxed__Object)i0, i2);
  goto l82;
l15:
  i1 = type;
  i1 = i1<6;
  _signed = i1;
  if (i1) goto l18;
  i2=0u;
  goto l20;
l18:
  i2 = Object_BigInt__BigIntDesc_ToLongInt((Object_BigInt__BigInt)i0);
  i2 = i2==(-2147483647-1);
  
l20:
  if (i2) goto l31;
  i2 = Object_BigInt__BigIntDesc_Sign((Object_BigInt__BigInt)i0);
  paren = (i2<0);
  i3 = (OOC_INT32)w;
  if (!(i2<0)) goto l24;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 20958)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i3, "(", 2);
l24:
  i0 = (OOC_INT32)Object_BigInt__BigIntDesc_ToString((Object_BigInt__BigInt)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 20992)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i3, (Object__Object)i0);
  i0 = !i1;
  if (!i0) goto l28;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 21064)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i3, "u", 2);
l28:
  if (!(i2<0)) goto l82;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 21123)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i3, ")", 2);
  goto l82;
l31:
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20782)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "(-", 3);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20815)))), OOC_C_DeclWriter__WriterDesc_WriteLInt)),OOC_C_DeclWriter__WriterDesc_WriteLInt)((OOC_C_DeclWriter__Writer)i0, 2147483647, 0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20858)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "-1)", 4);
  goto l82;
l34:
  d0 = *(OOC_REAL64*)(_check_pointer(i0, 20229));
  paren = (d0<0.0000000000000000);
  if (!(d0<0.0000000000000000)) goto l37;
  i1 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 20265)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "(", 2);
l37:
  i1 = (OOC_INT32)w;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20316)))), Object_Boxed__LongRealDesc_ToString)),Object_Boxed__LongRealDesc_ToString)((Object_Boxed__LongReal)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 20297)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i1, (Object__Object)i0);
  i0 = type;
  i0 = i0==13;
  if (!i0) goto l41;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 20373)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "f", 2);
l41:
  if (!(d0<0.0000000000000000)) goto l82;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 20429)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ")", 2);
  goto l82;
l45:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 19185));
  s = (Object__String)i0;
  i1 = type;
  i2 = i1==10;
  if (i2) goto l48;
  i2 = i1==6;
  
  goto l50;
l48:
  i2=1u;
l50:
  if (i2) goto l72;
  switch (i1) {
  case 7:
  case 11:
    i1 = (OOC_INT32)w;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 19663)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "(OOC_CHAR16)", 13);
    goto l55;
  case 8:
  case 12:
    i1 = (OOC_INT32)w;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 19736)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "(OOC_CHAR32)", 13);
    goto l55;
  default:
    _failed_case(i1, 19609);
    goto l55;
  }
l55:
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19811)))), Object__StringDesc_CharAt)),Object__StringDesc_CharAt)((Object__String)i0, 0);
  charValue = i0;
  i1 = (OOC_UINT32)i0<(OOC_UINT32)32;
  if (i1) goto l58;
  i1 = (OOC_UINT32)i0>=(OOC_UINT32)127;
  
  goto l60;
l58:
  i1=1u;
l60:
  if (i1) goto l62;
  i1 = i0==39;
  
  goto l64;
l62:
  i1=1u;
l64:
  if (i1) goto l66;
  i1 = i0==92;
  
  goto l68;
l66:
  i1=1u;
l68:
  if (i1) goto l70;
  i1 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 20041)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 39u);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 20073)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 20117)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 39u);
  goto l82;
l70:
  i1 = (OOC_INT32)w;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 19973))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 19973))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 19985)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i1, i0, 0);
  goto l82;
l72:
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19468)))), Object__StringDesc_CharAt)),Object__StringDesc_CharAt)((Object__String)i0, 0);
  charValue = i0;
  i1 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 19492)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "(OOC_CHAR8)\047", 13);
  OOC_C_DeclWriter__WriterDesc_WriteBasicConst_WriteChar(i0);
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19567)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i0, 39u);
  goto l82;
l75:
  i0 = *(OOC_UINT8*)(_check_pointer(i0, 19010));
  if (i0) goto l78;
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19084)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "OOC_FALSE", 10);
  goto l82;
l78:
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19034)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "OOC_TRUE", 9);
  goto l82;
l81:
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18929)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "0", 2);
l82:
  return;
  ;
}

void OOC_C_DeclWriter__WriterDesc_WriteStringConst(OOC_C_DeclWriter__Writer w, Object_Boxed__Object value, OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  Object__String s;
  OOC_INT32 i;
  OOC_INT32 len;
  auto void OOC_C_DeclWriter__WriterDesc_WriteStringConst_WriteOct(OOC_INT32 ch);
  auto void OOC_C_DeclWriter__WriterDesc_WriteStringConst_WriteChar(OOC_INT32 charValue);
    
    void OOC_C_DeclWriter__WriterDesc_WriteStringConst_WriteOct(OOC_INT32 ch) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)w;
      i1 = ch;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21788)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i0, (i1+48));
      return;
      ;
    }

    
    void OOC_C_DeclWriter__WriterDesc_WriteStringConst_WriteChar(OOC_INT32 charValue) {
      register OOC_INT32 i0,i1;

      i0 = charValue;
      i1 = i0<32;
      if (i1) goto l3;
      i1 = i0>=127;
      
      goto l5;
l3:
      i1=1u;
l5:
      if (i1) goto l7;
      i1 = i0==39;
      
      goto l9;
l7:
      i1=1u;
l9:
      if (i1) goto l11;
      i1 = i0==92;
      
      goto l13;
l11:
      i1=1u;
l13:
      if (i1) goto l15;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 22174)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, i0);
      goto l16;
l15:
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 22024)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 92u);
      OOC_C_DeclWriter__WriterDesc_WriteStringConst_WriteOct((i0>>6));
      OOC_C_DeclWriter__WriterDesc_WriteStringConst_WriteOct((_mod((i0>>3),8)));
      OOC_C_DeclWriter__WriterDesc_WriteStringConst_WriteOct((_mod(i0,8)));
l16:
      return;
      ;
    }


  i0 = (OOC_INT32)value;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22262)))), &_td_Object_Boxed__StringDesc, 22262)), 22269));
  s = (Object__String)i0;
  i1 = (OOC_INT32)type;
  i2 = (OOC_INT32)OOC_SymbolTable_TypeRules__BaseCharType((OOC_SymbolTable__Type)i1);
  i2 = OOC_SymbolTable_TypeRules__IsPredefType((OOC_SymbolTable__Type)i2, 1);
  if (i2) goto l23;
  i1 = *(OOC_INT16*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 22957)))), &_td_OOC_SymbolTable__PredefTypeDesc, 22957)), 22968))+40);
  switch (i1) {
  case 14:
    i1 = (OOC_INT32)w;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 23015)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "((OOC_CHAR16[]){", 17);
    goto l7;
  case 15:
    i1 = (OOC_INT32)w;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 23091)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "((OOC_CHAR32[]){", 17);
    goto l7;
  default:
    _failed_case(i1, 22943);
    goto l7;
  }
l7:
  i = 0;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 23160));
  len = i1;
  i2 = (OOC_INT32)w;
  i3 = 0!=i1;
  if (i3) goto l10;
  i0=0;
  goto l19;
l10:
  i3=0;
l11_loop:
  i3 = i3!=0;
  if (!i3) goto l14;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 23229)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i2, 44u);
l14:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 23270))+8);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 23270))+8);
  i5 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23300)))), Object__StringDesc_NextChar)),Object__StringDesc_NextChar)((Object__String)i0, (void*)(OOC_INT32)&i);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 23282)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i4, i5, 0);
  i3 = i;
  i4 = i3!=i1;
  if (i4) goto l11_loop;
l18:
  i0=i3;
l19:
  i0 = i0!=0;
  if (!i0) goto l22;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 23361)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i2, 44u);
l22:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 23398))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 23398))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23410)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i1, 0, 0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 23437)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, "})", 3);
  goto l36;
l23:
  i1 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 22348)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 34u);
  i = 0;
  i0 = *(OOC_INT32*)(_check_pointer(i0, 22391));
  len = i0;
  i0 = 0!=i0;
  if (!i0) goto l35;
  i0=0;
l26_loop:
  i1 = (OOC_INT32)s;
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 22439)))), Object__StringDesc_CharAt)),Object__StringDesc_CharAt)((Object__String)i1, i0);
  i0 = i0==34u;
  if (i0) goto l29;
  i0 = i;
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 22594)))), Object__StringDesc_CharAt)),Object__StringDesc_CharAt)((Object__String)i1, i0);
  OOC_C_DeclWriter__WriterDesc_WriteStringConst_WriteChar(i0);
  goto l30;
l29:
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22475)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "\134\"", 3);
l30:
  i0 = i;
  i0 = i0+1;
  i = i0;
  i1 = len;
  i1 = i0!=i1;
  if (i1) goto l26_loop;
l35:
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22654)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i0, 34u);
l36:
  return;
  ;
}

void OOC_C_DeclWriter__WriterDesc_WriteDeclaration(OOC_C_DeclWriter__Writer w, OOC_C_DeclWriter__Declaration d) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)d;
  i1 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23620)))), OOC_C_DeclWriter__DeclarationDesc_Write)),OOC_C_DeclWriter__DeclarationDesc_Write)((OOC_C_DeclWriter__Declaration)i0, (OOC_C_DeclWriter__Writer)i1);
  return;
  ;
}

void OOC_C_DeclWriter__WriterDesc_AddDeclaration(OOC_C_DeclWriter__Writer w, OOC_C_DeclWriter__Declaration d) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)d;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23943)))), &_td_OOC_C_DeclWriter__IncludeModuleDesc);
  if (i1) goto l3;
  i1 = (OOC_INT32)w;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 24008))+16);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 24008))+16);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 24022)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i1, (Object__Object)i0);
  goto l4;
l3:
  i1 = (OOC_INT32)w;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23969))+12);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23969))+12);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 23979)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i1, (Object__Object)i0);
l4:
  return;
  ;
}

void OOC_C_DeclWriter__WriterDesc_WriteDeclarationList(OOC_C_DeclWriter__Writer w) {
  auto void OOC_C_DeclWriter__WriterDesc_WriteDeclarationList_WriteIncludes(void);
  auto void OOC_C_DeclWriter__WriterDesc_WriteDeclarationList_WriteDeclarations(void);
    
    void OOC_C_DeclWriter__WriterDesc_WriteDeclarationList_WriteIncludes(void) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5;
      OOC_INT32 i;

      i0 = (OOC_INT32)w;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24443))+12);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24443))+12);
      i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 24453)))), ADT_ArrayList__ArrayListDesc_Size)),ADT_ArrayList__ArrayListDesc_Size)((ADT_ArrayList__ArrayList)i0);
      i = 0;
      i1 = 0<i0;
      if (!i1) goto l8;
      i1=0;
l3_loop:
      i2 = (OOC_INT32)w;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 24476))+12);
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 24486));
      i3 = _check_pointer(i3, 24493);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i1, i4, OOC_UINT32, 24493))*4);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 24476))+12);
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 24486));
      i4 = _check_pointer(i4, 24493);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i1, i5, OOC_UINT32, 24493))*4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 24497)))), &_td_OOC_C_DeclWriter__IncludeModuleDesc, 24497)), 24511)))), OOC_C_DeclWriter__DeclarationDesc_Write)),OOC_C_DeclWriter__DeclarationDesc_Write)((OOC_C_DeclWriter__Declaration)(_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 24497)))), &_td_OOC_C_DeclWriter__IncludeModuleDesc, 24497)), (OOC_C_DeclWriter__Writer)i2);
      i1 = i1+1;
      i = i1;
      i2 = i1<i0;
      if (i2) goto l3_loop;
l8:
      return;
      ;
    }

    
    void OOC_C_DeclWriter__WriterDesc_WriteDeclarationList_WriteDeclarations(void) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      OOC_INT32 i;
      OOC_C_DeclWriter__Declaration d;

      i0 = (OOC_INT32)w;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24671))+16);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24671))+16);
      i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 24685)))), ADT_ArrayList__ArrayListDesc_Size)),ADT_ArrayList__ArrayListDesc_Size)((ADT_ArrayList__ArrayList)i0);
      i = 0;
      i1 = 0<i0;
      if (!i1) goto l11;
      i1=0;
l3_loop:
      i2 = (OOC_INT32)w;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 24713))+16);
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 24727));
      i3 = _check_pointer(i3, 24734);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i1, i4, OOC_UINT32, 24734))*4);
      i3 = _type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 24738)))), &_td_OOC_C_DeclWriter__DeclarationDesc, 24738);
      d = (OOC_C_DeclWriter__Declaration)i3;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 24761)))), OOC_C_DeclWriter__WriterDesc_WriteDeclaration)),OOC_C_DeclWriter__WriterDesc_WriteDeclaration)((OOC_C_DeclWriter__Writer)i2, (OOC_C_DeclWriter__Declaration)i3);
      i2 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 24800)))), &_td_OOC_C_DeclWriter__DefineDesc));
      if (!i2) goto l6;
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 24827)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i2, 59u);
l6:
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 24868)))), OOC_C_DeclWriter__WriterDesc_WriteLn)),OOC_C_DeclWriter__WriterDesc_WriteLn)((OOC_C_DeclWriter__Writer)i2);
      i1 = i1+1;
      i = i1;
      i2 = i1<i0;
      if (i2) goto l3_loop;
l11:
      return;
      ;
    }


  OOC_C_DeclWriter__WriterDesc_WriteDeclarationList_WriteIncludes();
  OOC_C_DeclWriter__WriterDesc_WriteDeclarationList_WriteDeclarations();
  return;
  ;
}

static void OOC_C_DeclWriter__InitType(OOC_C_DeclWriter__Type t) {

  return;
  ;
}

OOC_INT8 OOC_C_DeclWriter__TypeDesc_Priority(OOC_C_DeclWriter__Type t) {

  _assert(0u, 127, 25223);
  _failed_function(25161); return 0;
  ;
}

void OOC_C_DeclWriter__TypeDesc_WriteLeft(OOC_C_DeclWriter__Type t, OOC_C_DeclWriter__Writer w) {

  _assert(0u, 127, 25319);
  return;
  ;
}

void OOC_C_DeclWriter__TypeDesc_WriteRight(OOC_C_DeclWriter__Type t, OOC_C_DeclWriter__Writer w) {

  _assert(0u, 127, 25409);
  return;
  ;
}

static void OOC_C_DeclWriter__WriteLeft(OOC_C_DeclWriter__Writer w, OOC_C_DeclWriter__Type t, OOC_INT8 callerPri) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)t;
  i1 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25520)))), OOC_C_DeclWriter__TypeDesc_WriteLeft)),OOC_C_DeclWriter__TypeDesc_WriteLeft)((OOC_C_DeclWriter__Type)i0, (OOC_C_DeclWriter__Writer)i1);
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25558)))), OOC_C_DeclWriter__TypeDesc_Priority)),OOC_C_DeclWriter__TypeDesc_Priority)((OOC_C_DeclWriter__Type)i0);
  i2 = callerPri;
  i0 = i2<i0;
  if (!i0) goto l4;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 25584)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 40u);
l4:
  return;
  ;
}

static void OOC_C_DeclWriter__WriteRight(OOC_C_DeclWriter__Writer w, OOC_C_DeclWriter__Type t, OOC_INT8 callerPri) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)t;
  i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25722)))), OOC_C_DeclWriter__TypeDesc_Priority)),OOC_C_DeclWriter__TypeDesc_Priority)((OOC_C_DeclWriter__Type)i0);
  i2 = callerPri;
  i1 = i2<i1;
  if (!i1) goto l4;
  i1 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 25748)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 41u);
l4:
  i1 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25780)))), OOC_C_DeclWriter__TypeDesc_WriteRight)),OOC_C_DeclWriter__TypeDesc_WriteRight)((OOC_C_DeclWriter__Type)i0, (OOC_C_DeclWriter__Writer)i1);
  return;
  ;
}

static void OOC_C_DeclWriter__InitBasicType(OOC_C_DeclWriter__BasicType bt, OOC_INT8 id, const OOC_CHAR8 repr__ref[], OOC_LEN repr_0d) {
  register OOC_INT32 i0,i1;
  OOC_ALLOCATE_VPAR(repr,OOC_CHAR8 ,repr_0d)

  OOC_INITIALIZE_VPAR(repr__ref,repr,OOC_CHAR8 ,repr_0d)
  i0 = (OOC_INT32)bt;
  OOC_C_DeclWriter__InitType((OOC_C_DeclWriter__Type)i0);
  i1 = id;
  *(OOC_INT8*)(_check_pointer(i0, 25931)) = i1;
  _copy_8((const void*)(OOC_INT32)repr,(void*)((_check_pointer(i0, 25961))+1),32);
  return;
  ;
}

static OOC_C_DeclWriter__BasicType OOC_C_DeclWriter__NewBasicType(OOC_INT8 id, const OOC_CHAR8 repr__ref[], OOC_LEN repr_0d) {
  register OOC_INT32 i0,i1;
  OOC_ALLOCATE_VPAR(repr,OOC_CHAR8 ,repr_0d)

  OOC_INITIALIZE_VPAR(repr__ref,repr,OOC_CHAR8 ,repr_0d)
  i0 = id;
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_C_DeclWriter__BasicType.baseTypes[0]);
  OOC_C_DeclWriter__InitBasicType((OOC_C_DeclWriter__BasicType)i1, i0, (void*)(OOC_INT32)repr, repr_0d);
  return (OOC_C_DeclWriter__BasicType)i1;
  ;
}

OOC_INT8 OOC_C_DeclWriter__BasicTypeDesc_Priority(OOC_C_DeclWriter__BasicType bt) {

  return 0;
  ;
}

void OOC_C_DeclWriter__BasicTypeDesc_WriteLeft(OOC_C_DeclWriter__BasicType bt, OOC_C_DeclWriter__Writer w) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)bt;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26337)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, (void*)((_check_pointer(i1, 26354))+1), 32);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26368)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i0, 32u);
  return;
  ;
}

void OOC_C_DeclWriter__BasicTypeDesc_WriteRight(OOC_C_DeclWriter__BasicType bt, OOC_C_DeclWriter__Writer w) {

  return;
  ;
}

static void OOC_C_DeclWriter__InitPointer(OOC_C_DeclWriter__Pointer p, OOC_INT8 typeQualifier, OOC_C_DeclWriter__Type base) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)p;
  OOC_C_DeclWriter__InitType((OOC_C_DeclWriter__Type)i0);
  i1 = typeQualifier;
  *(OOC_INT8*)(_check_pointer(i0, 26591)) = i1;
  i1 = (OOC_INT32)base;
  *(OOC_INT32*)((_check_pointer(i0, 26630))+4) = i1;
  return;
  ;
}

OOC_C_DeclWriter__Pointer OOC_C_DeclWriter__WriterDesc_NewPointer(OOC_C_DeclWriter__Writer w, OOC_INT8 typeQualifier, OOC_C_DeclWriter__Type base) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_C_DeclWriter__Pointer.baseTypes[0]);
  i1 = typeQualifier;
  i2 = (OOC_INT32)base;
  OOC_C_DeclWriter__InitPointer((OOC_C_DeclWriter__Pointer)i0, i1, (OOC_C_DeclWriter__Type)i2);
  return (OOC_C_DeclWriter__Pointer)i0;
  ;
}

OOC_INT8 OOC_C_DeclWriter__PointerDesc_Priority(OOC_C_DeclWriter__Pointer p) {

  return 1;
  ;
}

void OOC_C_DeclWriter__PointerDesc_WriteLeft(OOC_C_DeclWriter__Pointer p, OOC_C_DeclWriter__Writer w) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)p;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27036))+4);
  i1 = (OOC_INT32)w;
  OOC_C_DeclWriter__WriteLeft((OOC_C_DeclWriter__Writer)i1, (OOC_C_DeclWriter__Type)i0, 1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 27062)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 42u);
  return;
  ;
}

void OOC_C_DeclWriter__PointerDesc_WriteRight(OOC_C_DeclWriter__Pointer p, OOC_C_DeclWriter__Writer w) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)p;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27172))+4);
  i1 = (OOC_INT32)w;
  OOC_C_DeclWriter__WriteRight((OOC_C_DeclWriter__Writer)i1, (OOC_C_DeclWriter__Type)i0, 1);
  return;
  ;
}

static void OOC_C_DeclWriter__InitArray(OOC_C_DeclWriter__Array a, OOC_C_DeclWriter__Type base, OOC_INT32 size) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)a;
  OOC_C_DeclWriter__InitType((OOC_C_DeclWriter__Type)i0);
  i1 = (OOC_INT32)base;
  *(OOC_INT32*)(_check_pointer(i0, 27304)) = i1;
  i1 = size;
  *(OOC_INT32*)((_check_pointer(i0, 27325))+4) = i1;
  return;
  ;
}

OOC_C_DeclWriter__Array OOC_C_DeclWriter__WriterDesc_NewArray(OOC_C_DeclWriter__Writer w, OOC_C_DeclWriter__Type base, OOC_INT32 size) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_C_DeclWriter__Array.baseTypes[0]);
  i1 = (OOC_INT32)base;
  i2 = size;
  OOC_C_DeclWriter__InitArray((OOC_C_DeclWriter__Array)i0, (OOC_C_DeclWriter__Type)i1, i2);
  return (OOC_C_DeclWriter__Array)i0;
  ;
}

OOC_INT8 OOC_C_DeclWriter__ArrayDesc_Priority(OOC_C_DeclWriter__Array a) {

  return 2;
  ;
}

void OOC_C_DeclWriter__ArrayDesc_WriteLeft(OOC_C_DeclWriter__Array a, OOC_C_DeclWriter__Writer w) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)a;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 27689));
  i1 = (OOC_INT32)w;
  OOC_C_DeclWriter__WriteLeft((OOC_C_DeclWriter__Writer)i1, (OOC_C_DeclWriter__Type)i0, 2);
  return;
  ;
}

void OOC_C_DeclWriter__ArrayDesc_WriteRight(OOC_C_DeclWriter__Array a, OOC_C_DeclWriter__Writer w) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 27783)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i0, 91u);
  i1 = (OOC_INT32)a;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 27811))+4);
  i2 = i2>=0;
  if (!i2) goto l4;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 27850))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 27836)))), OOC_C_DeclWriter__WriterDesc_WriteLInt)),OOC_C_DeclWriter__WriterDesc_WriteLInt)((OOC_C_DeclWriter__Writer)i0, i2, 0);
l4:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 27876)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i0, 93u);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 27915));
  OOC_C_DeclWriter__WriteRight((OOC_C_DeclWriter__Writer)i0, (OOC_C_DeclWriter__Type)i1, 2);
  return;
  ;
}

static void OOC_C_DeclWriter__InitFunction(OOC_C_DeclWriter__Function fct, OOC_C_DeclWriter__Type resultType, OOC_CHAR8 restParameters) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)fct;
  i1 = (OOC_INT32)resultType;
  *(OOC_INT32*)(_check_pointer(i0, 28053)) = i1;
  i1 = (OOC_INT32)ADT_ArrayList__New(4);
  *(OOC_INT32*)((_check_pointer(i0, 28088))+4) = i1;
  i1 = restParameters;
  *(OOC_UINT8*)((_check_pointer(i0, 28130))+8) = i1;
  *(OOC_UINT8*)((_check_pointer(i0, 28173))+9) = 0u;
  *(OOC_INT8*)((_check_pointer(i0, 28201))+10) = 0;
  return;
  ;
}

OOC_C_DeclWriter__Function OOC_C_DeclWriter__WriterDesc_NewFunction(OOC_C_DeclWriter__Writer w, OOC_C_DeclWriter__Type resultType, OOC_CHAR8 restParameters) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_C_DeclWriter__Function.baseTypes[0]);
  i1 = (OOC_INT32)resultType;
  i2 = restParameters;
  OOC_C_DeclWriter__InitFunction((OOC_C_DeclWriter__Function)i0, (OOC_C_DeclWriter__Type)i1, i2);
  return (OOC_C_DeclWriter__Function)i0;
  ;
}

void OOC_C_DeclWriter__FunctionDesc_SetNoReturn(OOC_C_DeclWriter__Function fct, OOC_CHAR8 noReturn) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)fct;
  i1 = noReturn;
  *(OOC_UINT8*)((_check_pointer(i0, 28557))+9) = i1;
  return;
  ;
}

void OOC_C_DeclWriter__FunctionDesc_SetCallConv(OOC_C_DeclWriter__Function fct, OOC_INT8 callConv) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)fct;
  i1 = callConv;
  *(OOC_INT8*)((_check_pointer(i0, 28680))+10) = i1;
  return;
  ;
}

void OOC_C_DeclWriter__FunctionDesc_AddParameter(OOC_C_DeclWriter__Function fct, OOC_C_DeclWriter__Declaration param) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)fct;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28800))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28800))+4);
  i2 = (OOC_INT32)param;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 28812)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i0, (Object__Object)i2);
  return;
  ;
}

void OOC_C_DeclWriter__FunctionDesc_MakeParametersVolatile(OOC_C_DeclWriter__Function fct) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT32 i;
  OOC_C_DeclWriter__Declaration param;

  i0 = (OOC_INT32)fct;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28978))+4);
  i = 0;
  i1 = *(OOC_INT32*)((_check_pointer(i1, 28989))+4);
  i2 = 0<i1;
  if (!i2) goto l11;
  i2=0;
l3_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29018))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 29029));
  i3 = _check_pointer(i3, 29035);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 29035))*4);
  i3 = _type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 29039)))), &_td_OOC_C_DeclWriter__DeclarationDesc, 29039);
  param = (OOC_C_DeclWriter__Declaration)i3;
  i4 = *(OOC_INT8*)(_check_pointer(i3, 29068));
  i4 = i4==0;
  if (!i4) goto l6;
  *(OOC_INT8*)(_check_pointer(i3, 29111)) = 2;
l6:
  i2 = i2+1;
  i = i2;
  i3 = i2<i1;
  if (i3) goto l3_loop;
l11:
  return;
  ;
}

OOC_INT8 OOC_C_DeclWriter__FunctionDesc_Priority(OOC_C_DeclWriter__Function fct) {

  return 2;
  ;
}

void OOC_C_DeclWriter__FunctionDesc_WriteLeft(OOC_C_DeclWriter__Function fct, OOC_C_DeclWriter__Writer w) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)fct;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 29368));
  i2 = (OOC_INT32)w;
  OOC_C_DeclWriter__WriteLeft((OOC_C_DeclWriter__Writer)i2, (OOC_C_DeclWriter__Type)i1, 2);
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 29406))+9);
  if (!i1) goto l3;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 29428)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, "NORETURN ", 10);
l3:
  i0 = *(OOC_INT8*)((_check_pointer(i0, 29476))+10);
  switch (i0) {
  case 2:
    goto l8;
  case 3:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 29598)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, "__attribute__ ((stdcall)) ", 27);
    goto l8;
  default:
    goto l8;
  }
l8:
  return;
  ;
}

void OOC_C_DeclWriter__FunctionDesc_WriteRight(OOC_C_DeclWriter__Function fct, OOC_C_DeclWriter__Writer w) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 i;

  i0 = (OOC_INT32)fct;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29769))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29769))+4);
  i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 29780)))), ADT_ArrayList__ArrayListDesc_Size)),ADT_ArrayList__ArrayListDesc_Size)((ADT_ArrayList__ArrayList)i2);
  i1 = i1==0;
  if (i1) goto l17;
  i1 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 29846)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 40u);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29887))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29887))+4);
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 29899)))), ADT_ArrayList__ArrayListDesc_Size)),ADT_ArrayList__ArrayListDesc_Size)((ADT_ArrayList__ArrayList)i3);
  i = 0;
  i3 = 0<i2;
  if (!i3) goto l13;
  i3=0;
l5_loop:
  i4 = i3!=0;
  if (!i4) goto l8;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 29948)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ", ", 3);
l8:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30014))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 30026));
  i4 = _check_pointer(i4, 30033);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 30033))*4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 29991)))), OOC_C_DeclWriter__WriterDesc_WriteDeclaration)),OOC_C_DeclWriter__WriterDesc_WriteDeclaration)((OOC_C_DeclWriter__Writer)i1, (OOC_C_DeclWriter__Declaration)(_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 30037)))), &_td_OOC_C_DeclWriter__DeclarationDesc, 30037)));
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l5_loop;
l13:
  i2 = *(OOC_UINT8*)((_check_pointer(i0, 30074))+8);
  if (!i2) goto l16;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 30105)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ", ...", 6);
l16:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 30148)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 41u);
  
  goto l18;
l17:
  i1 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 29805)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "(void)", 7);
  
l18:
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 30197));
  OOC_C_DeclWriter__WriteRight((OOC_C_DeclWriter__Writer)i1, (OOC_C_DeclWriter__Type)i2, 2);
  i0 = *(OOC_UINT8*)((_check_pointer(i0, 30235))+9);
  if (!i0) goto l21;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 30257)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, " NORETURN2", 11);
l21:
  return;
  ;
}

static void OOC_C_DeclWriter__InitStruct(OOC_C_DeclWriter__Struct _struct, OOC_CHAR8 isUnion, Object__String name) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)_struct;
  i1 = isUnion;
  *(OOC_UINT8*)(_check_pointer(i0, 30418)) = i1;
  i1 = (OOC_INT32)ADT_ArrayList__New(4);
  *(OOC_INT32*)((_check_pointer(i0, 30450))+8) = i1;
  i1 = (OOC_INT32)name;
  *(OOC_INT32*)((_check_pointer(i0, 30492))+4) = i1;
  return;
  ;
}

OOC_C_DeclWriter__Struct OOC_C_DeclWriter__WriterDesc_NewStruct(OOC_C_DeclWriter__Writer w, OOC_CHAR8 isUnion, Object__String name) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_C_DeclWriter__Struct.baseTypes[0]);
  i1 = isUnion;
  i2 = (OOC_INT32)name;
  OOC_C_DeclWriter__InitStruct((OOC_C_DeclWriter__Struct)i0, i1, (Object__String)i2);
  return (OOC_C_DeclWriter__Struct)i0;
  ;
}

void OOC_C_DeclWriter__StructDesc_AddMember(OOC_C_DeclWriter__Struct _struct, OOC_C_DeclWriter__Declaration param) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)_struct;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30808))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30808))+8);
  i2 = (OOC_INT32)param;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 30817)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i0, (Object__Object)i2);
  return;
  ;
}

void OOC_C_DeclWriter__StructDesc_AddPadding(OOC_C_DeclWriter__Struct _struct, OOC_C_DeclWriter__Writer w, OOC_INT32 offset) {
  register OOC_INT32 i0,i1,i2;
  OOC_CHAR8 str[32];

  i0 = offset;
  IntStr__IntToStr(i0, (void*)(OOC_INT32)str, 32);
  Strings__Insert("__pad", 6, 0, (void*)(OOC_INT32)str, 32);
  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)Object__NewLatin1((void*)(OOC_INT32)str, 32);
  i2 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i0, 31161))+24)+(_check_index(10, 17, OOC_UINT8, 31172))*4);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31059)))), OOC_C_DeclWriter__WriterDesc_NewDeclaration)),OOC_C_DeclWriter__WriterDesc_NewDeclaration)((OOC_C_DeclWriter__Writer)i0, (Object__String)i1, 0, 0, (OOC_C_DeclWriter__Type)i2);
  i1 = (OOC_INT32)_struct;
  OOC_C_DeclWriter__StructDesc_AddMember((OOC_C_DeclWriter__Struct)i1, (OOC_C_DeclWriter__Declaration)i0);
  return;
  ;
}

OOC_INT8 OOC_C_DeclWriter__StructDesc_Priority(OOC_C_DeclWriter__Struct _struct) {

  return 1;
  ;
}

void OOC_C_DeclWriter__StructDesc_WriteLeft(OOC_C_DeclWriter__Struct _struct, OOC_C_DeclWriter__Writer w) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 i;

  i0 = (OOC_INT32)_struct;
  i1 = *(OOC_UINT8*)(_check_pointer(i0, 31391));
  if (i1) goto l3;
  i1 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 31454)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "struct", 7);
  
  goto l4;
l3:
  i1 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 31413)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "union", 6);
  
l4:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31503))+4);
  i2 = i2!=0;
  if (!i2) goto l7;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 31529)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, " ", 2);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31578))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 31557)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i1, (Object__Object)i2);
l7:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 31601)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, " {", 3);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 31628)))), OOC_C_DeclWriter__WriterDesc_Indent)),OOC_C_DeclWriter__WriterDesc_Indent)((OOC_C_DeclWriter__Writer)i1, 1);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31666))+8);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31666))+8);
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 31675)))), ADT_ArrayList__ArrayListDesc_Size)),ADT_ArrayList__ArrayListDesc_Size)((ADT_ArrayList__ArrayList)i3);
  i = 0;
  i3 = 0<i2;
  if (!i3) goto l15;
  i3=0;
l10_loop:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 31696)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i1);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31740))+8);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 31749));
  i4 = _check_pointer(i4, 31756);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 31756))*4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 31714)))), OOC_C_DeclWriter__WriterDesc_WriteDeclaration)),OOC_C_DeclWriter__WriterDesc_WriteDeclaration)((OOC_C_DeclWriter__Writer)i1, (OOC_C_DeclWriter__Declaration)(_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 31760)))), &_td_OOC_C_DeclWriter__DeclarationDesc, 31760)));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 31782)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ";", 2);
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l10_loop;
l15:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31825))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31825))+8);
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 31834)))), ADT_ArrayList__ArrayListDesc_Size)),ADT_ArrayList__ArrayListDesc_Size)((ADT_ArrayList__ArrayList)i0);
  i0 = i0==0;
  if (!i0) goto l18;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 31958)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 31976)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "char __dummy;", 14);
l18:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 32023)))), OOC_C_DeclWriter__WriterDesc_Indent)),OOC_C_DeclWriter__WriterDesc_Indent)((OOC_C_DeclWriter__Writer)i1, (-1));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 32043)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 32059)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "} ", 3);
  return;
  ;
}

void OOC_C_DeclWriter__StructDesc_WriteRight(OOC_C_DeclWriter__Struct _struct, OOC_C_DeclWriter__Writer w) {

  return;
  ;
}

static void OOC_C_DeclWriter__InitTypeRef(OOC_C_DeclWriter__TypeRef typeRef, OOC_INT8 _class, Object__String name) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)typeRef;
  i1 = _class;
  *(OOC_INT8*)(_check_pointer(i0, 32289)) = i1;
  i1 = (OOC_INT32)name;
  *(OOC_INT32*)((_check_pointer(i0, 32318))+4) = i1;
  return;
  ;
}

OOC_C_DeclWriter__TypeRef OOC_C_DeclWriter__WriterDesc_NewTypeRef(OOC_C_DeclWriter__Writer w, OOC_INT8 _class, Object__String name) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_C_DeclWriter__TypeRef.baseTypes[0]);
  i1 = _class;
  i2 = (OOC_INT32)name;
  OOC_C_DeclWriter__InitTypeRef((OOC_C_DeclWriter__TypeRef)i0, i1, (Object__String)i2);
  return (OOC_C_DeclWriter__TypeRef)i0;
  ;
}

OOC_INT8 OOC_C_DeclWriter__TypeRefDesc_Priority(OOC_C_DeclWriter__TypeRef typeRef) {

  return 0;
  ;
}

void OOC_C_DeclWriter__TypeRefDesc_WriteLeft(OOC_C_DeclWriter__TypeRef typeRef, OOC_C_DeclWriter__Writer w) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)typeRef;
  i1 = *(OOC_INT8*)(_check_pointer(i0, 32739));
  switch (i1) {
  case 0:
    goto l6;
  case 1:
    i1 = (OOC_INT32)w;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 32787)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "struct ", 8);
    goto l6;
  case 2:
    i1 = (OOC_INT32)w;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 32833)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "union ", 7);
    goto l6;
  default:
    _failed_case(i1, 32727);
    goto l6;
  }
l6:
  i1 = (OOC_INT32)w;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32895))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 32873)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i1, (Object__Object)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 32909)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 32u);
  return;
  ;
}

void OOC_C_DeclWriter__TypeRefDesc_WriteRight(OOC_C_DeclWriter__TypeRef typeRef, OOC_C_DeclWriter__Writer w) {

  return;
  ;
}

void OOC_C_DeclWriter__WriterDesc_WriteType(OOC_C_DeclWriter__Writer w, OOC_C_DeclWriter__Type t) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)t;
  i1 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33084)))), OOC_C_DeclWriter__TypeDesc_WriteLeft)),OOC_C_DeclWriter__TypeDesc_WriteLeft)((OOC_C_DeclWriter__Type)i0, (OOC_C_DeclWriter__Writer)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33106)))), OOC_C_DeclWriter__TypeDesc_WriteRight)),OOC_C_DeclWriter__TypeDesc_WriteRight)((OOC_C_DeclWriter__Type)i0, (OOC_C_DeclWriter__Writer)i1);
  return;
  ;
}

static void OOC_C_DeclWriter__InitDeclaration(OOC_C_DeclWriter__Declaration d, Object__String name, OOC_INT8 typeQualifier, OOC_INT8 storageClass, OOC_C_DeclWriter__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)d;
  i1 = (OOC_INT32)name;
  *(OOC_INT32*)((_check_pointer(i0, 33435))+8) = i1;
  i1 = typeQualifier;
  *(OOC_INT8*)(_check_pointer(i0, 33456)) = i1;
  i1 = storageClass;
  *(OOC_INT8*)((_check_pointer(i0, 33495))+1) = i1;
  i1 = (OOC_INT32)type;
  *(OOC_INT32*)((_check_pointer(i0, 33532))+4) = i1;
  return;
  ;
}

OOC_C_DeclWriter__Declaration OOC_C_DeclWriter__WriterDesc_NewDeclaration(OOC_C_DeclWriter__Writer w, Object__String name, OOC_INT8 typeQualifier, OOC_INT8 storageClass, OOC_C_DeclWriter__Type type) {
  register OOC_INT32 i0,i1,i2,i3,i4;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_C_DeclWriter__Declaration.baseTypes[0]);
  i1 = (OOC_INT32)name;
  i2 = typeQualifier;
  i3 = storageClass;
  i4 = (OOC_INT32)type;
  OOC_C_DeclWriter__InitDeclaration((OOC_C_DeclWriter__Declaration)i0, (Object__String)i1, i2, i3, (OOC_C_DeclWriter__Type)i4);
  return (OOC_C_DeclWriter__Declaration)i0;
  ;
}

void OOC_C_DeclWriter__DeclarationDesc_SetTypeQualifier(OOC_C_DeclWriter__Declaration d, OOC_INT8 typeQualifier) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)d;
  i1 = typeQualifier;
  *(OOC_INT8*)(_check_pointer(i0, 33946)) = i1;
  return;
  ;
}

void OOC_C_DeclWriter__DeclarationDesc_Write(OOC_C_DeclWriter__Declaration d, OOC_C_DeclWriter__Writer w) {
  register OOC_INT32 i0,i1,i2;
  auto void OOC_C_DeclWriter__DeclarationDesc_Write_WriteTypeQualifier(OOC_C_DeclWriter__Writer w, OOC_INT8 typeQualifier);
    
    void OOC_C_DeclWriter__DeclarationDesc_Write_WriteTypeQualifier(OOC_C_DeclWriter__Writer w, OOC_INT8 typeQualifier) {
      register OOC_INT32 i0;

      i0 = typeQualifier;
      switch (i0) {
      case 0:
        goto l6;
      case 1:
        i0 = (OOC_INT32)w;
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34203)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "const ", 7);
        goto l6;
      case 2:
        i0 = (OOC_INT32)w;
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34249)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "volatile ", 10);
        goto l6;
      default:
        _failed_case(i0, 34140);
        goto l6;
      }
l6:
      return;
      ;
    }


  i0 = (OOC_INT32)d;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 34334))+1);
  switch (i1) {
  case 0:
    goto l10;
  case 1:
    i1 = (OOC_INT32)w;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 34389)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "typedef ", 9);
    goto l10;
  case 2:
    i1 = (OOC_INT32)w;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 34435)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "extern ", 8);
    goto l10;
  case 3:
    i1 = (OOC_INT32)w;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 34480)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "static ", 8);
    goto l10;
  case 4:
    goto l10;
  case 5:
    i1 = (OOC_INT32)w;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 34543)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "register ", 10);
    goto l10;
  case 6:
    i1 = (OOC_INT32)w;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 34591)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "auto ", 6);
    goto l10;
  default:
    _failed_case(i1, 34328);
    goto l10;
  }
l10:
  i0 = *(OOC_INT8*)(_check_pointer(i0, 34652));
  i1 = (OOC_INT32)w;
  OOC_C_DeclWriter__DeclarationDesc_Write_WriteTypeQualifier((OOC_C_DeclWriter__Writer)i1, i0);
  i0 = (OOC_INT32)d;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34689))+4);
  i2 = (OOC_INT32)w;
  OOC_C_DeclWriter__WriteLeft((OOC_C_DeclWriter__Writer)i2, (OOC_C_DeclWriter__Type)i1, 3);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34735))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 34719)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i2, (Object__Object)i1);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34764))+4);
  OOC_C_DeclWriter__WriteRight((OOC_C_DeclWriter__Writer)i2, (OOC_C_DeclWriter__Type)i0, 3);
  return;
  ;
}

static void OOC_C_DeclWriter__InitIncludeModule(OOC_C_DeclWriter__IncludeModule d, OOC_Repository__Module module) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)d;
  OOC_C_DeclWriter__InitDeclaration((OOC_C_DeclWriter__Declaration)i0, (Object__String)(OOC_INT32)0, 0, 4, (OOC_C_DeclWriter__Type)(OOC_INT32)0);
  i1 = (OOC_INT32)module;
  *(OOC_INT32*)((_check_pointer(i0, 34943))+12) = i1;
  return;
  ;
}

OOC_C_DeclWriter__IncludeModule OOC_C_DeclWriter__WriterDesc_NewIncludeModule(OOC_C_DeclWriter__Writer w, OOC_Repository__Module module) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)module;
  _assert((i0!=(OOC_INT32)0), 127, 35113);
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_C_DeclWriter__IncludeModule.baseTypes[0]);
  OOC_C_DeclWriter__InitIncludeModule((OOC_C_DeclWriter__IncludeModule)i1, (OOC_Repository__Module)i0);
  return (OOC_C_DeclWriter__IncludeModule)i1;
  ;
}

void OOC_C_DeclWriter__WriterDesc_WriteModuleInclude(OOC_C_DeclWriter__Writer w, OOC_Repository__Module m, OOC_INT8 fileId) {
  register OOC_INT32 i0,i1,i2,i3;
  Object__String path;
  Object__CharsLatin1 chars;

  i0 = (OOC_INT32)m;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35459))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35459))+4);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 35464)), 0);
  i1 = (OOC_INT32)OOC_Repository_FileSystem__ModuleToFileName((void*)(_check_pointer(i1, 35464)), i2);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 35477));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 35477));
  i3 = fileId;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 35484)))), OOC_Repository__RepositoryDesc_GetDefaultSuffix)),OOC_Repository__RepositoryDesc_GetDefaultSuffix)((OOC_Repository__Repository)i0, i3);
  i0 = (OOC_INT32)Object__Concat2((void*)i1,(void*)i0);
  path = (Object__String)i0;
  i0 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 35536)))), &_td_Object__String8Desc, 35536)));
  chars = (Object__CharsLatin1)i0;
  i1 = (OOC_INT32)w;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i0, 35585)), 0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 35565)))), OOC_C_DeclWriter__WriterDesc_WriteInclude)),OOC_C_DeclWriter__WriterDesc_WriteInclude)((OOC_C_DeclWriter__Writer)i1, (void*)(_check_pointer(i0, 35585)), i2);
  return;
  ;
}

void OOC_C_DeclWriter__IncludeModuleDesc_Write(OOC_C_DeclWriter__IncludeModule d, OOC_C_DeclWriter__Writer w) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)d;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 35698))+12);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 35677)))), OOC_C_DeclWriter__WriterDesc_WriteModuleInclude)),OOC_C_DeclWriter__WriterDesc_WriteModuleInclude)((OOC_C_DeclWriter__Writer)i0, (OOC_Repository__Module)i1, 13);
  return;
  ;
}

static void OOC_C_DeclWriter__InitDefine(OOC_C_DeclWriter__Define d, Object__String name, Object_Boxed__Object _const, OOC_SymbolTable__Type oocType) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)d;
  i1 = (OOC_INT32)name;
  OOC_C_DeclWriter__InitDeclaration((OOC_C_DeclWriter__Declaration)i0, (Object__String)i1, 0, 4, (OOC_C_DeclWriter__Type)(OOC_INT32)0);
  i1 = (OOC_INT32)_const;
  *(OOC_INT32*)((_check_pointer(i0, 35925))+12) = i1;
  i1 = (OOC_INT32)oocType;
  *(OOC_INT32*)((_check_pointer(i0, 35948))+16) = i1;
  return;
  ;
}

OOC_C_DeclWriter__Define OOC_C_DeclWriter__WriterDesc_NewDefine(OOC_C_DeclWriter__Writer w, Object__String name, Object_Boxed__Object _const, OOC_SymbolTable__Type oocType) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_C_DeclWriter__Define.baseTypes[0]);
  i1 = (OOC_INT32)name;
  i2 = (OOC_INT32)_const;
  i3 = (OOC_INT32)oocType;
  OOC_C_DeclWriter__InitDefine((OOC_C_DeclWriter__Define)i0, (Object__String)i1, (Object_Boxed__Object)i2, (OOC_SymbolTable__Type)i3);
  return (OOC_C_DeclWriter__Define)i0;
  ;
}

void OOC_C_DeclWriter__DefineDesc_Write(OOC_C_DeclWriter__Define d, OOC_C_DeclWriter__Writer w) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36323)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "#define ", 9);
  i1 = (OOC_INT32)d;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 36372))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36356)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i0, (Object__Object)i2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36386)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, " ", 2);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 36416))+12);
  i2 = i2==(OOC_INT32)0;
  if (i2) goto l7;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 36500))+16);
  i2 = i2==(OOC_INT32)0;
  if (i2) goto l5;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 36621))+12);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 36631))+16);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36606)))), OOC_C_DeclWriter__WriterDesc_WriteConst)),OOC_C_DeclWriter__WriterDesc_WriteConst)((OOC_C_DeclWriter__Writer)i0, (Object_Boxed__Object)i2, (OOC_SymbolTable__Type)i1);
  goto l8;
l5:
  i2 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(13);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 36544))+12);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36529)))), OOC_C_DeclWriter__WriterDesc_WriteConst)),OOC_C_DeclWriter__WriterDesc_WriteConst)((OOC_C_DeclWriter__Writer)i0, (Object_Boxed__Object)i1, (OOC_SymbolTable__Type)i2);
  goto l8;
l7:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36443)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, " 0", 3);
l8:
  return;
  ;
}

void OOC_C_DeclWriter__WriterDesc_WriteTypeCast(OOC_C_DeclWriter__Writer w, OOC_C_DeclWriter__Type t) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36729)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i0, 40u);
  i1 = (OOC_INT32)t;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 36753)))), OOC_C_DeclWriter__TypeDesc_WriteLeft)),OOC_C_DeclWriter__TypeDesc_WriteLeft)((OOC_C_DeclWriter__Type)i1, (OOC_C_DeclWriter__Writer)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 36775)))), OOC_C_DeclWriter__TypeDesc_WriteRight)),OOC_C_DeclWriter__TypeDesc_WriteRight)((OOC_C_DeclWriter__Type)i1, (OOC_C_DeclWriter__Writer)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36798)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i0, 41u);
  return;
  ;
}

void OOC_OOC_C_DeclWriter_init(void) {

  return;
  ;
}

/* --- */
