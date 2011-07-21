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
      *(OOC_INT32*)(((_check_pointer(i0, 9774))+24)+(_check_index(i1, 17, OOC_UINT8, 9785))*4) = i2;
      return;
      ;
    }


  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)ch;
  *(OOC_INT32*)(_check_pointer(i0, 9858)) = i1;
  i2 = (OOC_INT32)baseURI;
  *(OOC_INT32*)((_check_pointer(i0, 9875))+4) = i2;
  *(OOC_INT32*)((_check_pointer(i0, 9902))+20) = 0;
  i1 = (OOC_INT32)IO_TextRider__ConnectWriter((IO__ByteChannel)i1);
  *(OOC_INT32*)((_check_pointer(i0, 9932))+8) = i1;
  i1 = (OOC_INT32)ADT_ArrayList__New(4);
  *(OOC_INT32*)((_check_pointer(i0, 9983))+12) = i1;
  i1 = (OOC_INT32)ADT_ArrayList__New(16);
  *(OOC_INT32*)((_check_pointer(i0, 10021))+16) = i1;
  OOC_C_DeclWriter__InitWriter_CreateBasicType(0, (OOC_CHAR8*)"void", 5);
  OOC_C_DeclWriter__InitWriter_CreateBasicType(1, (OOC_CHAR8*)"OOC_PTR", 8);
  OOC_C_DeclWriter__InitWriter_CreateBasicType(2, (OOC_CHAR8*)"OOC_INT8", 9);
  OOC_C_DeclWriter__InitWriter_CreateBasicType(3, (OOC_CHAR8*)"OOC_INT16", 10);
  OOC_C_DeclWriter__InitWriter_CreateBasicType(4, (OOC_CHAR8*)"OOC_INT32", 10);
  OOC_C_DeclWriter__InitWriter_CreateBasicType(5, (OOC_CHAR8*)"OOC_INT64", 10);
  OOC_C_DeclWriter__InitWriter_CreateBasicType(6, (OOC_CHAR8*)"OOC_UINT8", 10);
  OOC_C_DeclWriter__InitWriter_CreateBasicType(7, (OOC_CHAR8*)"OOC_UINT16", 11);
  OOC_C_DeclWriter__InitWriter_CreateBasicType(8, (OOC_CHAR8*)"OOC_UINT32", 11);
  OOC_C_DeclWriter__InitWriter_CreateBasicType(9, (OOC_CHAR8*)"OOC_UINT64", 11);
  OOC_C_DeclWriter__InitWriter_CreateBasicType(10, (OOC_CHAR8*)"OOC_CHAR8", 10);
  OOC_C_DeclWriter__InitWriter_CreateBasicType(11, (OOC_CHAR8*)"OOC_CHAR16", 11);
  OOC_C_DeclWriter__InitWriter_CreateBasicType(12, (OOC_CHAR8*)"OOC_CHAR32", 11);
  OOC_C_DeclWriter__InitWriter_CreateBasicType(13, (OOC_CHAR8*)"OOC_REAL32", 11);
  OOC_C_DeclWriter__InitWriter_CreateBasicType(14, (OOC_CHAR8*)"OOC_REAL64", 11);
  OOC_C_DeclWriter__InitWriter_CreateBasicType(15, (OOC_CHAR8*)"OOC_LEN", 8);
  OOC_C_DeclWriter__InitWriter_CreateBasicType(16, (OOC_CHAR8*)"RT0__Struct", 12);
  return;
  ;
}

OOC_C_DeclWriter__Writer OOC_C_DeclWriter__NewWriter(IO__ByteChannel ch, URI__HierarchicalURI baseURI) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_C_DeclWriter__Writer.baseTypes[0]);
  i1 = (OOC_INT32)baseURI;
  i2 = (OOC_INT32)ch;
  OOC_C_DeclWriter__InitWriter((OOC_C_DeclWriter__Writer)i0, (IO__ByteChannel)i2, (URI__HierarchicalURI)i1);
  return (OOC_C_DeclWriter__Writer)i0;
  ;
}

void OOC_C_DeclWriter__WriterDesc_CopyTo(OOC_C_DeclWriter__Writer w, OOC_C_DeclWriter__Writer dest) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)dest;
  i1 = (OOC_INT32)w;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 11525));
  *(OOC_INT32*)(_check_pointer(i0, 11516)) = i2;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11553))+4);
  *(OOC_INT32*)((_check_pointer(i0, 11539))+4) = i2;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11589))+8);
  *(OOC_INT32*)((_check_pointer(i0, 11572))+8) = i2;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11626))+12);
  *(OOC_INT32*)((_check_pointer(i0, 11611))+12) = i2;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11665))+16);
  *(OOC_INT32*)((_check_pointer(i0, 11646))+16) = i2;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 11707))+20);
  *(OOC_INT32*)((_check_pointer(i0, 11689))+20) = i2;
  _copy_block(((_check_pointer(i1, 11746))+24),((_check_pointer(i0, 11730))+24),68);
  return;
  ;
}

void OOC_C_DeclWriter__WriterDesc_WriteString(OOC_C_DeclWriter__Writer w, const OOC_CHAR8 str[], OOC_LEN str_0d) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11853))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11853))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11865)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (void*)(OOC_INT32)str, str_0d);
  return;
  ;
}

void OOC_C_DeclWriter__WriterDesc_WriteObject(OOC_C_DeclWriter__Writer w, Object__Object obj) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11975))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11975))+8);
  i2 = (OOC_INT32)obj;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11986)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i0, (Object__Object)i2);
  return;
  ;
}

void OOC_C_DeclWriter__WriterDesc_WriteChar(OOC_C_DeclWriter__Writer w, OOC_CHAR8 ch) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12083))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12083))+8);
  i2 = ch;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 12095)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i0, i2);
  return;
  ;
}

void OOC_C_DeclWriter__WriterDesc_WriteLn(OOC_C_DeclWriter__Writer w) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12177))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12177))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 12189)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
  return;
  ;
}

void OOC_C_DeclWriter__WriterDesc_WriteLInt(OOC_C_DeclWriter__Writer w, OOC_INT32 lint, OOC_INT32 n) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12289))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12289))+8);
  i2 = lint;
  i3 = n;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 12301)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i0, i2, i3);
  return;
  ;
}

void OOC_C_DeclWriter__WriterDesc_Indent(OOC_C_DeclWriter__Writer w, OOC_INT32 delta) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)w;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 12467))+20);
  i2 = delta;
  *(OOC_INT32*)((_check_pointer(i0, 12467))+20) = (i1+i2);
  return;
  ;
}

void OOC_C_DeclWriter__WriterDesc_Newline(OOC_C_DeclWriter__Writer w) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_INT32 i;

  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12574)))), OOC_C_DeclWriter__WriterDesc_WriteLn)),OOC_C_DeclWriter__WriterDesc_WriteLn)((OOC_C_DeclWriter__Writer)i0);
  i = 1;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 12604))+20);
  i2 = 1<=i1;
  if (!i2) goto l8;
  i2=1;
l3_loop:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12628)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, (OOC_CHAR8*)"  ", 3);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12841)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, (OOC_CHAR8*)"#include <", 11);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12876)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, (void*)(OOC_INT32)includePath, includePath_0d);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12910)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, (OOC_CHAR8*)">", 2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12936)))), OOC_C_DeclWriter__WriterDesc_WriteLn)),OOC_C_DeclWriter__WriterDesc_WriteLn)((OOC_C_DeclWriter__Writer)i0);
  return;
  ;
}

void OOC_C_DeclWriter__WriterDesc_Close(OOC_C_DeclWriter__Writer w) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13074));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13074));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 13077)))), IO__ChannelDesc_CloseAndRegister)),IO__ChannelDesc_CloseAndRegister)((IO__Channel)i0);
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
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13709)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i0, (i1+48));
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
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14095)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, i0);
      goto l16;
l15:
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 13945)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 92u);
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
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14241)))), &_td_Object_Boxed__BooleanDesc);
  if (i1) goto l105;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14415)))), &_td_Object_Boxed__StringDesc);
  if (i1) goto l38;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17040)))), &_td_Object_Boxed__LongRealDesc);
  if (i1) goto l27;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17347)))), &_td_Object_BigInt__BigIntDesc);
  if (i1) goto l15;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17938)))), &_td_Object_Boxed__SetDesc);
  if (i1) goto l13;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17931)))), 17931);
  goto l112;
l13:
  i0 = *(OOC_UINT32*)(_check_pointer(i0, 18013));
  i0 = (OOC_INT32)Object_BigInt__NewInt((_type_cast_fast(OOC_INT32, OOC_UINT32, i0)));
  i1 = (OOC_INT32)w;
  i2 = (OOC_INT32)type;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17962)))), OOC_C_DeclWriter__WriterDesc_WriteConst)),OOC_C_DeclWriter__WriterDesc_WriteConst)((OOC_C_DeclWriter__Writer)i1, (Object_Boxed__Object)i0, (OOC_SymbolTable__Type)i2);
  goto l112;
l15:
  i1 = Object_BigInt__BigIntDesc_ToLongInt((Object_BigInt__BigInt)i0);
  i1 = i1==(-2147483647-1);
  if (i1) goto l24;
  i1 = Object_BigInt__BigIntDesc_Sign((Object_BigInt__BigInt)i0);
  paren = (i1<0);
  if (!(i1<0)) goto l20;
  i2 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 17788)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, (OOC_CHAR8*)"(", 2);
l20:
  i0 = (OOC_INT32)Object_BigInt__BigIntDesc_ToString((Object_BigInt__BigInt)i0);
  i2 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 17822)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i2, (Object__Object)i0);
  if (!(i1<0)) goto l112;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 17880)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, (OOC_CHAR8*)")", 2);
  goto l112;
l24:
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17612)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, (OOC_CHAR8*)"(-", 3);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17645)))), OOC_C_DeclWriter__WriterDesc_WriteLInt)),OOC_C_DeclWriter__WriterDesc_WriteLInt)((OOC_C_DeclWriter__Writer)i0, 2147483647, 0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17688)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, (OOC_CHAR8*)"-1)", 4);
  goto l112;
l27:
  d0 = *(OOC_REAL64*)(_check_pointer(i0, 17083));
  paren = (d0<0.0000000000000000);
  if (!(d0<0.0000000000000000)) goto l30;
  i1 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17119)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, (OOC_CHAR8*)"(", 2);
l30:
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17170)))), Object_Boxed__LongRealDesc_ToString)),Object_Boxed__LongRealDesc_ToString)((Object_Boxed__LongReal)i0);
  i1 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17151)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i1, (Object__Object)i0);
  i0 = (OOC_INT32)type;
  i0 = OOC_SymbolTable_TypeRules__IsPredefType((OOC_SymbolTable__Type)i0, 8);
  if (!i0) goto l34;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17246)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, (OOC_CHAR8*)"f", 2);
l34:
  if (!(d0<0.0000000000000000)) goto l112;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17302)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, (OOC_CHAR8*)")", 2);
  goto l112;
l38:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14451));
  s = (Object__String)i0;
  i1 = (OOC_INT32)type;
  i2 = (OOC_INT32)OOC_SymbolTable_TypeRules__BaseCharType((OOC_SymbolTable__Type)i1);
  i2 = OOC_SymbolTable_TypeRules__IsPredefType((OOC_SymbolTable__Type)i2, 1);
  if (i2) goto l86;
  i2 = OOC_SymbolTable_TypeRules__IsCharType((OOC_SymbolTable__Type)i1);
  if (i2) goto l63;
  i1 = *(OOC_INT16*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16386)))), &_td_OOC_SymbolTable__PredefTypeDesc, 16386)), 16397))+40);
  switch (i1) {
  case 14:
    i1 = (OOC_INT32)w;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16456)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, (OOC_CHAR8*)"((OOC_CHAR16[]){", 17);
    goto l47;
  case 15:
    i1 = (OOC_INT32)w;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16544)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, (OOC_CHAR8*)"((OOC_CHAR32[]){", 17);
    goto l47;
  default:
    _failed_case(i1, 16372);
    goto l47;
  }
l47:
  i = 0;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 16625));
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 16712)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i2, 44u);
l54:
  i3 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16795)))), Object__StringDesc_NextChar)),Object__StringDesc_NextChar)((Object__String)i0, (void*)(OOC_INT32)&i);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 16765))+8);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 16765))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 16777)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i5, i3, 0);
  i3 = i;
  i4 = i3!=i1;
  if (i4) goto l51_loop;
l58:
  i0=i3;
l59:
  i0 = i0!=0;
  if (!i0) goto l62;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 16874)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i2, 44u);
l62:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 16923))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 16923))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16935)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i1, 0, 0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 16968)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, (OOC_CHAR8*)"})", 3);
  goto l112;
l63:
  i1 = *(OOC_INT16*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15498)))), &_td_OOC_SymbolTable__PredefTypeDesc, 15498)), 15509))+40);
  switch (i1) {
  case 2:
    i1 = (OOC_INT32)w;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15562)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, (OOC_CHAR8*)"(OOC_CHAR16)", 13);
    goto l68;
  case 3:
    i1 = (OOC_INT32)w;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15640)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, (OOC_CHAR8*)"(OOC_CHAR32)", 13);
    goto l68;
  default:
    _failed_case(i1, 15484);
    goto l68;
  }
l68:
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15719)))), Object__StringDesc_CharAt)),Object__StringDesc_CharAt)((Object__String)i0, 0);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15959)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 39u);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15993)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16039)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 39u);
  goto l112;
l83:
  i1 = (OOC_INT32)w;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15887))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15887))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 15899)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i1, i0, 0);
  goto l112;
l86:
  i1 = *(OOC_INT16*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14550)))), &_td_OOC_SymbolTable__PredefTypeDesc, 14550)), 14561))+40);
  i1 = i1==1;
  if (i1) goto l101;
  i1 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14972)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, (OOC_CHAR8*)"(OOC_CHAR8[])", 14);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15018)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 34u);
  i = 0;
  i0 = *(OOC_INT32*)(_check_pointer(i0, 15067));
  len = i0;
  i0 = 0!=i0;
  if (!i0) goto l100;
  i0=0;
l91_loop:
  i1 = (OOC_INT32)s;
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15127)))), Object__StringDesc_CharAt)),Object__StringDesc_CharAt)((Object__String)i1, i0);
  i0 = i0==34u;
  if (i0) goto l94;
  i0 = i;
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15300)))), Object__StringDesc_CharAt)),Object__StringDesc_CharAt)((Object__String)i1, i0);
  OOC_C_DeclWriter__WriterDesc_WriteConst_WriteChar(i0);
  goto l95;
l94:
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15169)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, (OOC_CHAR8*)"\134\"", 3);
l95:
  i0 = i;
  i0 = i0+1;
  i = i0;
  i1 = len;
  i1 = i0!=i1;
  if (i1) goto l91_loop;
l100:
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15384)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i0, 34u);
  goto l112;
l101:
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14820)))), Object__StringDesc_CharAt)),Object__StringDesc_CharAt)((Object__String)i0, 0);
  charValue = i0;
  i1 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14846)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, (OOC_CHAR8*)"(OOC_CHAR8)\047", 13);
  OOC_C_DeclWriter__WriterDesc_WriteConst_WriteChar(i0);
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14925)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i0, 39u);
  goto l112;
l105:
  i0 = *(OOC_UINT8*)(_check_pointer(i0, 14276));
  if (i0) goto l108;
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14350)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, (OOC_CHAR8*)"OOC_FALSE", 10);
  goto l112;
l108:
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14300)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, (OOC_CHAR8*)"OOC_TRUE", 9);
  goto l112;
l111:
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14195)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, (OOC_CHAR8*)"0", 2);
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
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18644)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i0, (i1+48));
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
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 19030)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, i0);
      goto l16;
l15:
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 18880)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 92u);
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
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19176)))), &_td_Object_Boxed__BooleanDesc);
  if (i1) goto l75;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19350)))), &_td_Object_Boxed__StringDesc);
  if (i1) goto l45;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20387)))), &_td_Object_Boxed__LongRealDesc);
  if (i1) goto l34;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20675)))), &_td_Object_BigInt__BigIntDesc);
  if (i1) goto l15;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21382)))), &_td_Object_Boxed__SetDesc);
  if (i1) goto l13;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21375)))), 21375);
  goto l82;
l13:
  i0 = *(OOC_UINT32*)(_check_pointer(i0, 21462));
  i0 = (OOC_INT32)Object_BigInt__NewInt((_type_cast_fast(OOC_INT32, OOC_UINT32, i0)));
  i1 = (OOC_INT32)w;
  i2 = type;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 21406)))), OOC_C_DeclWriter__WriterDesc_WriteBasicConst)),OOC_C_DeclWriter__WriterDesc_WriteBasicConst)((OOC_C_DeclWriter__Writer)i1, (Object_Boxed__Object)i0, i2);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 21159)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i3, (OOC_CHAR8*)"(", 2);
l24:
  i0 = (OOC_INT32)Object_BigInt__BigIntDesc_ToString((Object_BigInt__BigInt)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 21193)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i3, (Object__Object)i0);
  i0 = !i1;
  if (!i0) goto l28;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 21265)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i3, (OOC_CHAR8*)"u", 2);
l28:
  if (!(i2<0)) goto l82;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 21324)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i3, (OOC_CHAR8*)")", 2);
  goto l82;
l31:
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20983)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, (OOC_CHAR8*)"(-", 3);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21016)))), OOC_C_DeclWriter__WriterDesc_WriteLInt)),OOC_C_DeclWriter__WriterDesc_WriteLInt)((OOC_C_DeclWriter__Writer)i0, 2147483647, 0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21059)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, (OOC_CHAR8*)"-1)", 4);
  goto l82;
l34:
  d0 = *(OOC_REAL64*)(_check_pointer(i0, 20430));
  paren = (d0<0.0000000000000000);
  if (!(d0<0.0000000000000000)) goto l37;
  i1 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 20466)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, (OOC_CHAR8*)"(", 2);
l37:
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20517)))), Object_Boxed__LongRealDesc_ToString)),Object_Boxed__LongRealDesc_ToString)((Object_Boxed__LongReal)i0);
  i1 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 20498)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i1, (Object__Object)i0);
  i0 = type;
  i0 = i0==13;
  if (!i0) goto l41;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 20574)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, (OOC_CHAR8*)"f", 2);
l41:
  if (!(d0<0.0000000000000000)) goto l82;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 20630)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, (OOC_CHAR8*)")", 2);
  goto l82;
l45:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 19386));
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
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 19864)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, (OOC_CHAR8*)"(OOC_CHAR16)", 13);
    goto l55;
  case 8:
  case 12:
    i1 = (OOC_INT32)w;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 19937)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, (OOC_CHAR8*)"(OOC_CHAR32)", 13);
    goto l55;
  default:
    _failed_case(i1, 19810);
    goto l55;
  }
l55:
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20012)))), Object__StringDesc_CharAt)),Object__StringDesc_CharAt)((Object__String)i0, 0);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 20242)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 39u);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 20274)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 20318)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 39u);
  goto l82;
l70:
  i1 = (OOC_INT32)w;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 20174))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 20174))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 20186)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i1, i0, 0);
  goto l82;
l72:
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19669)))), Object__StringDesc_CharAt)),Object__StringDesc_CharAt)((Object__String)i0, 0);
  charValue = i0;
  i1 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 19693)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, (OOC_CHAR8*)"(OOC_CHAR8)\047", 13);
  OOC_C_DeclWriter__WriterDesc_WriteBasicConst_WriteChar(i0);
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19768)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i0, 39u);
  goto l82;
l75:
  i0 = *(OOC_UINT8*)(_check_pointer(i0, 19211));
  if (i0) goto l78;
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19285)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, (OOC_CHAR8*)"OOC_FALSE", 10);
  goto l82;
l78:
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19235)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, (OOC_CHAR8*)"OOC_TRUE", 9);
  goto l82;
l81:
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19130)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, (OOC_CHAR8*)"0", 2);
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
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21989)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i0, (i1+48));
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
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 22375)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, i0);
      goto l16;
l15:
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 22225)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 92u);
      OOC_C_DeclWriter__WriterDesc_WriteStringConst_WriteOct((i0>>6));
      OOC_C_DeclWriter__WriterDesc_WriteStringConst_WriteOct((_mod((i0>>3),8)));
      OOC_C_DeclWriter__WriterDesc_WriteStringConst_WriteOct((_mod(i0,8)));
l16:
      return;
      ;
    }


  i0 = (OOC_INT32)value;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22463)))), &_td_Object_Boxed__StringDesc, 22463)), 22470));
  s = (Object__String)i0;
  i1 = (OOC_INT32)type;
  i2 = (OOC_INT32)OOC_SymbolTable_TypeRules__BaseCharType((OOC_SymbolTable__Type)i1);
  i2 = OOC_SymbolTable_TypeRules__IsPredefType((OOC_SymbolTable__Type)i2, 1);
  if (i2) goto l23;
  i1 = *(OOC_INT16*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 23197)))), &_td_OOC_SymbolTable__PredefTypeDesc, 23197)), 23208))+40);
  switch (i1) {
  case 14:
    i1 = (OOC_INT32)w;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 23255)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, (OOC_CHAR8*)"((OOC_CHAR16[]){", 17);
    goto l7;
  case 15:
    i1 = (OOC_INT32)w;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 23331)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, (OOC_CHAR8*)"((OOC_CHAR32[]){", 17);
    goto l7;
  default:
    _failed_case(i1, 23183);
    goto l7;
  }
l7:
  i = 0;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 23400));
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 23469)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i2, 44u);
l14:
  i3 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23540)))), Object__StringDesc_NextChar)),Object__StringDesc_NextChar)((Object__String)i0, (void*)(OOC_INT32)&i);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 23510))+8);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 23510))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 23522)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i5, i3, 0);
  i3 = i;
  i4 = i3!=i1;
  if (i4) goto l11_loop;
l18:
  i0=i3;
l19:
  i0 = i0!=0;
  if (!i0) goto l22;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 23601)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i2, 44u);
l22:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 23638))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 23638))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23650)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i1, 0, 0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 23677)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, (OOC_CHAR8*)"})", 3);
  goto l36;
l23:
  i1 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 22549)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, (OOC_CHAR8*)"(OOC_CHAR8*)", 13);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 22588)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 34u);
  i = 0;
  i0 = *(OOC_INT32*)(_check_pointer(i0, 22631));
  len = i0;
  i0 = 0!=i0;
  if (!i0) goto l35;
  i0=0;
l26_loop:
  i1 = (OOC_INT32)s;
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 22679)))), Object__StringDesc_CharAt)),Object__StringDesc_CharAt)((Object__String)i1, i0);
  i0 = i0==34u;
  if (i0) goto l29;
  i0 = i;
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 22834)))), Object__StringDesc_CharAt)),Object__StringDesc_CharAt)((Object__String)i1, i0);
  OOC_C_DeclWriter__WriterDesc_WriteStringConst_WriteChar(i0);
  goto l30;
l29:
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22715)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, (OOC_CHAR8*)"\134\"", 3);
l30:
  i0 = i;
  i0 = i0+1;
  i = i0;
  i1 = len;
  i1 = i0!=i1;
  if (i1) goto l26_loop;
l35:
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22894)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i0, 34u);
l36:
  return;
  ;
}

void OOC_C_DeclWriter__WriterDesc_WriteDeclaration(OOC_C_DeclWriter__Writer w, OOC_C_DeclWriter__Declaration d) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)d;
  i1 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23860)))), OOC_C_DeclWriter__DeclarationDesc_Write)),OOC_C_DeclWriter__DeclarationDesc_Write)((OOC_C_DeclWriter__Declaration)i0, (OOC_C_DeclWriter__Writer)i1);
  return;
  ;
}

void OOC_C_DeclWriter__WriterDesc_AddDeclaration(OOC_C_DeclWriter__Writer w, OOC_C_DeclWriter__Declaration d) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)d;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 24183)))), &_td_OOC_C_DeclWriter__IncludeModuleDesc);
  if (i1) goto l3;
  i1 = (OOC_INT32)w;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 24248))+16);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 24248))+16);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 24262)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i1, (Object__Object)i0);
  goto l4;
l3:
  i1 = (OOC_INT32)w;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 24209))+12);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 24209))+12);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 24219)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i1, (Object__Object)i0);
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
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24683))+12);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24683))+12);
      i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 24693)))), ADT_ArrayList__ArrayListDesc_Size)),ADT_ArrayList__ArrayListDesc_Size)((ADT_ArrayList__ArrayList)i0);
      i = 0;
      i1 = 0<i0;
      if (!i1) goto l8;
      i1=0;
l3_loop:
      i2 = (OOC_INT32)w;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 24716))+12);
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 24726));
      i3 = _check_pointer(i3, 24733);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i1, i4, OOC_UINT32, 24733))*4);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 24716))+12);
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 24726));
      i4 = _check_pointer(i4, 24733);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i1, i5, OOC_UINT32, 24733))*4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer((_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 24737)))), &_td_OOC_C_DeclWriter__IncludeModuleDesc, 24737)), 24751)))), OOC_C_DeclWriter__DeclarationDesc_Write)),OOC_C_DeclWriter__DeclarationDesc_Write)((OOC_C_DeclWriter__Declaration)(_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 24737)))), &_td_OOC_C_DeclWriter__IncludeModuleDesc, 24737)), (OOC_C_DeclWriter__Writer)i2);
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
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24911))+16);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24911))+16);
      i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 24925)))), ADT_ArrayList__ArrayListDesc_Size)),ADT_ArrayList__ArrayListDesc_Size)((ADT_ArrayList__ArrayList)i0);
      i = 0;
      i1 = 0<i0;
      if (!i1) goto l11;
      i1=0;
l3_loop:
      i2 = (OOC_INT32)w;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 24953))+16);
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 24967));
      i3 = _check_pointer(i3, 24974);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i1, i4, OOC_UINT32, 24974))*4);
      i3 = _type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 24978)))), &_td_OOC_C_DeclWriter__DeclarationDesc, 24978);
      d = (OOC_C_DeclWriter__Declaration)i3;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 25001)))), OOC_C_DeclWriter__WriterDesc_WriteDeclaration)),OOC_C_DeclWriter__WriterDesc_WriteDeclaration)((OOC_C_DeclWriter__Writer)i2, (OOC_C_DeclWriter__Declaration)i3);
      i2 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 25040)))), &_td_OOC_C_DeclWriter__DefineDesc));
      if (!i2) goto l6;
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 25067)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i2, 59u);
l6:
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 25108)))), OOC_C_DeclWriter__WriterDesc_WriteLn)),OOC_C_DeclWriter__WriterDesc_WriteLn)((OOC_C_DeclWriter__Writer)i2);
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

  _assert(0u, 127, 25463);
  _failed_function(25401); return 0;
  ;
}

void OOC_C_DeclWriter__TypeDesc_WriteLeft(OOC_C_DeclWriter__Type t, OOC_C_DeclWriter__Writer w) {

  _assert(0u, 127, 25559);
  return;
  ;
}

void OOC_C_DeclWriter__TypeDesc_WriteRight(OOC_C_DeclWriter__Type t, OOC_C_DeclWriter__Writer w) {

  _assert(0u, 127, 25649);
  return;
  ;
}

static void OOC_C_DeclWriter__WriteLeft(OOC_C_DeclWriter__Writer w, OOC_C_DeclWriter__Type t, OOC_INT8 callerPri) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)t;
  i1 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25760)))), OOC_C_DeclWriter__TypeDesc_WriteLeft)),OOC_C_DeclWriter__TypeDesc_WriteLeft)((OOC_C_DeclWriter__Type)i0, (OOC_C_DeclWriter__Writer)i1);
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25798)))), OOC_C_DeclWriter__TypeDesc_Priority)),OOC_C_DeclWriter__TypeDesc_Priority)((OOC_C_DeclWriter__Type)i0);
  i2 = callerPri;
  i0 = i2<i0;
  if (!i0) goto l4;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 25824)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 40u);
l4:
  return;
  ;
}

static void OOC_C_DeclWriter__WriteRight(OOC_C_DeclWriter__Writer w, OOC_C_DeclWriter__Type t, OOC_INT8 callerPri) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)t;
  i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25962)))), OOC_C_DeclWriter__TypeDesc_Priority)),OOC_C_DeclWriter__TypeDesc_Priority)((OOC_C_DeclWriter__Type)i0);
  i2 = callerPri;
  i1 = i2<i1;
  if (!i1) goto l4;
  i1 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 25988)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 41u);
l4:
  i1 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26020)))), OOC_C_DeclWriter__TypeDesc_WriteRight)),OOC_C_DeclWriter__TypeDesc_WriteRight)((OOC_C_DeclWriter__Type)i0, (OOC_C_DeclWriter__Writer)i1);
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
  *(OOC_INT8*)(_check_pointer(i0, 26171)) = i1;
  _copy_8((const void*)(OOC_INT32)repr,(void*)((_check_pointer(i0, 26201))+1),32);
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

  i0 = (OOC_INT32)bt;
  i1 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 26577)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, (void*)((_check_pointer(i0, 26594))+1), 32);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 26608)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 32u);
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
  *(OOC_INT8*)(_check_pointer(i0, 26831)) = i1;
  i1 = (OOC_INT32)base;
  *(OOC_INT32*)((_check_pointer(i0, 26870))+4) = i1;
  return;
  ;
}

OOC_C_DeclWriter__Pointer OOC_C_DeclWriter__WriterDesc_NewPointer(OOC_C_DeclWriter__Writer w, OOC_INT8 typeQualifier, OOC_C_DeclWriter__Type base) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_C_DeclWriter__Pointer.baseTypes[0]);
  i1 = (OOC_INT32)base;
  i2 = typeQualifier;
  OOC_C_DeclWriter__InitPointer((OOC_C_DeclWriter__Pointer)i0, i2, (OOC_C_DeclWriter__Type)i1);
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
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27276))+4);
  i1 = (OOC_INT32)w;
  OOC_C_DeclWriter__WriteLeft((OOC_C_DeclWriter__Writer)i1, (OOC_C_DeclWriter__Type)i0, 1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 27302)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 42u);
  return;
  ;
}

void OOC_C_DeclWriter__PointerDesc_WriteRight(OOC_C_DeclWriter__Pointer p, OOC_C_DeclWriter__Writer w) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)p;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27412))+4);
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
  *(OOC_INT32*)(_check_pointer(i0, 27544)) = i1;
  i1 = size;
  *(OOC_INT32*)((_check_pointer(i0, 27565))+4) = i1;
  return;
  ;
}

static OOC_CHAR8 OOC_C_DeclWriter__ArrayAsPointer(OOC_C_DeclWriter__Array a) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)a;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 27665))+4);
  i1 = i1<0;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 27680));
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 27686)))), &_td_OOC_C_DeclWriter__ArrayDesc);
  
l5:
  if (i1) goto l7;
  i0=0u;
  goto l8;
l7:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 27700));
  i0 = *(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 27706)))), &_td_OOC_C_DeclWriter__ArrayDesc, 27706)), 27712))+4);
  i0 = i0<0;
  
l8:
  return i0;
  ;
}

OOC_C_DeclWriter__Array OOC_C_DeclWriter__WriterDesc_NewArray(OOC_C_DeclWriter__Writer w, OOC_C_DeclWriter__Type base, OOC_INT32 size) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_C_DeclWriter__Array.baseTypes[0]);
  i1 = size;
  i2 = (OOC_INT32)base;
  OOC_C_DeclWriter__InitArray((OOC_C_DeclWriter__Array)i0, (OOC_C_DeclWriter__Type)i2, i1);
  return (OOC_C_DeclWriter__Array)i0;
  ;
}

OOC_INT8 OOC_C_DeclWriter__ArrayDesc_Priority(OOC_C_DeclWriter__Array a) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)a;
  i0 = OOC_C_DeclWriter__ArrayAsPointer((OOC_C_DeclWriter__Array)i0);
  if (i0) goto l3;
  return 2;
  goto l4;
l3:
  return 1;
l4:
  _failed_function(27938); return 0;
  ;
}

void OOC_C_DeclWriter__ArrayDesc_WriteLeft(OOC_C_DeclWriter__Array a, OOC_C_DeclWriter__Writer w) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)a;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 28151));
  i2 = (OOC_INT32)w;
  OOC_C_DeclWriter__WriteLeft((OOC_C_DeclWriter__Writer)i2, (OOC_C_DeclWriter__Type)i1, 2);
  i0 = OOC_C_DeclWriter__ArrayAsPointer((OOC_C_DeclWriter__Array)i0);
  if (!i0) goto l4;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 28207)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i2, 42u);
l4:
  return;
  ;
}

void OOC_C_DeclWriter__ArrayDesc_WriteRight(OOC_C_DeclWriter__Array a, OOC_C_DeclWriter__Writer w) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)a;
  i1 = OOC_C_DeclWriter__ArrayAsPointer((OOC_C_DeclWriter__Array)i0);
  i1 = !i1;
  if (!i1) goto l6;
  i1 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 28344)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 91u);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 28374))+4);
  i2 = i2>=0;
  if (!i2) goto l5;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 28414))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 28400)))), OOC_C_DeclWriter__WriterDesc_WriteLInt)),OOC_C_DeclWriter__WriterDesc_WriteLInt)((OOC_C_DeclWriter__Writer)i1, i2, 0);
l5:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 28444)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 93u);
l6:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 28492));
  i1 = (OOC_INT32)w;
  OOC_C_DeclWriter__WriteRight((OOC_C_DeclWriter__Writer)i1, (OOC_C_DeclWriter__Type)i0, 2);
  return;
  ;
}

static void OOC_C_DeclWriter__InitFunction(OOC_C_DeclWriter__Function fct, OOC_C_DeclWriter__Type resultType, OOC_CHAR8 restParameters) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)fct;
  i1 = (OOC_INT32)resultType;
  *(OOC_INT32*)(_check_pointer(i0, 28630)) = i1;
  i1 = (OOC_INT32)ADT_ArrayList__New(4);
  *(OOC_INT32*)((_check_pointer(i0, 28665))+4) = i1;
  i1 = restParameters;
  *(OOC_UINT8*)((_check_pointer(i0, 28707))+8) = i1;
  *(OOC_UINT8*)((_check_pointer(i0, 28750))+9) = 0u;
  *(OOC_INT8*)((_check_pointer(i0, 28778))+10) = 0;
  return;
  ;
}

OOC_C_DeclWriter__Function OOC_C_DeclWriter__WriterDesc_NewFunction(OOC_C_DeclWriter__Writer w, OOC_C_DeclWriter__Type resultType, OOC_CHAR8 restParameters) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_C_DeclWriter__Function.baseTypes[0]);
  i1 = restParameters;
  i2 = (OOC_INT32)resultType;
  OOC_C_DeclWriter__InitFunction((OOC_C_DeclWriter__Function)i0, (OOC_C_DeclWriter__Type)i2, i1);
  return (OOC_C_DeclWriter__Function)i0;
  ;
}

void OOC_C_DeclWriter__FunctionDesc_SetNoReturn(OOC_C_DeclWriter__Function fct, OOC_CHAR8 noReturn) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)fct;
  i1 = noReturn;
  *(OOC_UINT8*)((_check_pointer(i0, 29134))+9) = i1;
  return;
  ;
}

void OOC_C_DeclWriter__FunctionDesc_SetCallConv(OOC_C_DeclWriter__Function fct, OOC_INT8 callConv) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)fct;
  i1 = callConv;
  *(OOC_INT8*)((_check_pointer(i0, 29257))+10) = i1;
  return;
  ;
}

void OOC_C_DeclWriter__FunctionDesc_AddParameter(OOC_C_DeclWriter__Function fct, OOC_C_DeclWriter__Declaration param) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)fct;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29377))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29377))+4);
  i2 = (OOC_INT32)param;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 29389)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i0, (Object__Object)i2);
  return;
  ;
}

void OOC_C_DeclWriter__FunctionDesc_MakeParametersVolatile(OOC_C_DeclWriter__Function fct) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT32 i;
  OOC_C_DeclWriter__Declaration param;

  i0 = (OOC_INT32)fct;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29555))+4);
  i = 0;
  i1 = *(OOC_INT32*)((_check_pointer(i1, 29566))+4);
  i2 = 0<i1;
  if (!i2) goto l11;
  i2=0;
l3_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29595))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 29606));
  i3 = _check_pointer(i3, 29612);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 29612))*4);
  i3 = _type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 29616)))), &_td_OOC_C_DeclWriter__DeclarationDesc, 29616);
  param = (OOC_C_DeclWriter__Declaration)i3;
  i4 = *(OOC_INT8*)(_check_pointer(i3, 29645));
  i4 = i4==0;
  if (!i4) goto l6;
  *(OOC_INT8*)(_check_pointer(i3, 29688)) = 2;
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
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 29945));
  i2 = (OOC_INT32)w;
  OOC_C_DeclWriter__WriteLeft((OOC_C_DeclWriter__Writer)i2, (OOC_C_DeclWriter__Type)i1, 2);
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 29983))+9);
  if (!i1) goto l3;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 30005)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, (OOC_CHAR8*)"NORETURN ", 10);
l3:
  i0 = *(OOC_INT8*)((_check_pointer(i0, 30053))+10);
  switch (i0) {
  case 2:
    goto l9;
  case 3:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 30175)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, (OOC_CHAR8*)"__attribute__ ((stdcall)) ", 27);
    goto l9;
  case 4:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 30254)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, (OOC_CHAR8*)"__attribute__ ((fastcall)) ", 28);
    goto l9;
  default:
    goto l9;
  }
l9:
  return;
  ;
}

void OOC_C_DeclWriter__FunctionDesc_WriteRight(OOC_C_DeclWriter__Function fct, OOC_C_DeclWriter__Writer w) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 i;

  i0 = (OOC_INT32)fct;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30426))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30426))+4);
  i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 30437)))), ADT_ArrayList__ArrayListDesc_Size)),ADT_ArrayList__ArrayListDesc_Size)((ADT_ArrayList__ArrayList)i2);
  i1 = i1==0;
  if (i1) goto l17;
  i1 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 30503)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 40u);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30544))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30544))+4);
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 30556)))), ADT_ArrayList__ArrayListDesc_Size)),ADT_ArrayList__ArrayListDesc_Size)((ADT_ArrayList__ArrayList)i3);
  i = 0;
  i3 = 0<i2;
  if (!i3) goto l13;
  i3=0;
l5_loop:
  i4 = i3!=0;
  if (!i4) goto l8;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 30605)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, (OOC_CHAR8*)", ", 3);
l8:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30671))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 30683));
  i4 = _check_pointer(i4, 30690);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 30690))*4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 30648)))), OOC_C_DeclWriter__WriterDesc_WriteDeclaration)),OOC_C_DeclWriter__WriterDesc_WriteDeclaration)((OOC_C_DeclWriter__Writer)i1, (OOC_C_DeclWriter__Declaration)(_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 30694)))), &_td_OOC_C_DeclWriter__DeclarationDesc, 30694)));
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l5_loop;
l13:
  i2 = *(OOC_UINT8*)((_check_pointer(i0, 30731))+8);
  if (!i2) goto l16;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 30762)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, (OOC_CHAR8*)", ...", 6);
l16:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 30805)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 41u);
  
  goto l18;
l17:
  i1 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 30462)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, (OOC_CHAR8*)"(void)", 7);
  
l18:
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 30854));
  OOC_C_DeclWriter__WriteRight((OOC_C_DeclWriter__Writer)i1, (OOC_C_DeclWriter__Type)i2, 2);
  i0 = *(OOC_UINT8*)((_check_pointer(i0, 30892))+9);
  if (!i0) goto l21;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 30914)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, (OOC_CHAR8*)" NORETURN2", 11);
l21:
  return;
  ;
}

static void OOC_C_DeclWriter__InitStruct(OOC_C_DeclWriter__Struct _struct, OOC_CHAR8 isUnion, Object__String name) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)_struct;
  i1 = isUnion;
  *(OOC_UINT8*)(_check_pointer(i0, 31075)) = i1;
  i1 = (OOC_INT32)ADT_ArrayList__New(4);
  *(OOC_INT32*)((_check_pointer(i0, 31107))+8) = i1;
  i1 = (OOC_INT32)name;
  *(OOC_INT32*)((_check_pointer(i0, 31149))+4) = i1;
  return;
  ;
}

OOC_C_DeclWriter__Struct OOC_C_DeclWriter__WriterDesc_NewStruct(OOC_C_DeclWriter__Writer w, OOC_CHAR8 isUnion, Object__String name) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_C_DeclWriter__Struct.baseTypes[0]);
  i1 = (OOC_INT32)name;
  i2 = isUnion;
  OOC_C_DeclWriter__InitStruct((OOC_C_DeclWriter__Struct)i0, i2, (Object__String)i1);
  return (OOC_C_DeclWriter__Struct)i0;
  ;
}

void OOC_C_DeclWriter__StructDesc_AddMember(OOC_C_DeclWriter__Struct _struct, OOC_C_DeclWriter__Declaration param) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)_struct;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31465))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31465))+8);
  i2 = (OOC_INT32)param;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 31474)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i0, (Object__Object)i2);
  return;
  ;
}

void OOC_C_DeclWriter__StructDesc_AddPadding(OOC_C_DeclWriter__Struct _struct, OOC_C_DeclWriter__Writer w, OOC_INT32 offset) {
  register OOC_INT32 i0,i1,i2;
  OOC_CHAR8 str[32];

  i0 = offset;
  IntStr__IntToStr(i0, (void*)(OOC_INT32)str, 32);
  Strings__Insert((OOC_CHAR8*)"__pad", 6, 0, (void*)(OOC_INT32)str, 32);
  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)*(OOC_INT32*)(((_check_pointer(i0, 31818))+24)+(_check_index(10, 17, OOC_UINT8, 31829))*4);
  i2 = (OOC_INT32)Object__NewLatin1((void*)(OOC_INT32)str, 32);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31716)))), OOC_C_DeclWriter__WriterDesc_NewDeclaration)),OOC_C_DeclWriter__WriterDesc_NewDeclaration)((OOC_C_DeclWriter__Writer)i0, (Object__String)i2, 0, 0, (OOC_C_DeclWriter__Type)i1);
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
  i1 = *(OOC_UINT8*)(_check_pointer(i0, 32048));
  if (i1) goto l3;
  i1 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 32111)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, (OOC_CHAR8*)"struct", 7);
  
  goto l4;
l3:
  i1 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 32070)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, (OOC_CHAR8*)"union", 6);
  
l4:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32160))+4);
  i2 = i2!=0;
  if (!i2) goto l7;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 32186)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, (OOC_CHAR8*)" ", 2);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32235))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 32214)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i1, (Object__Object)i2);
l7:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 32258)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, (OOC_CHAR8*)" {", 3);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 32285)))), OOC_C_DeclWriter__WriterDesc_Indent)),OOC_C_DeclWriter__WriterDesc_Indent)((OOC_C_DeclWriter__Writer)i1, 1);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32323))+8);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32323))+8);
  i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 32332)))), ADT_ArrayList__ArrayListDesc_Size)),ADT_ArrayList__ArrayListDesc_Size)((ADT_ArrayList__ArrayList)i3);
  i = 0;
  i3 = 0<i2;
  if (!i3) goto l15;
  i3=0;
l10_loop:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 32353)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i1);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32397))+8);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 32406));
  i4 = _check_pointer(i4, 32413);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 32413))*4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 32371)))), OOC_C_DeclWriter__WriterDesc_WriteDeclaration)),OOC_C_DeclWriter__WriterDesc_WriteDeclaration)((OOC_C_DeclWriter__Writer)i1, (OOC_C_DeclWriter__Declaration)(_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 32417)))), &_td_OOC_C_DeclWriter__DeclarationDesc, 32417)));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 32439)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, (OOC_CHAR8*)";", 2);
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l10_loop;
l15:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32482))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32482))+8);
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 32491)))), ADT_ArrayList__ArrayListDesc_Size)),ADT_ArrayList__ArrayListDesc_Size)((ADT_ArrayList__ArrayList)i0);
  i0 = i0==0;
  if (!i0) goto l18;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 32615)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 32633)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, (OOC_CHAR8*)"char __dummy;", 14);
l18:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 32680)))), OOC_C_DeclWriter__WriterDesc_Indent)),OOC_C_DeclWriter__WriterDesc_Indent)((OOC_C_DeclWriter__Writer)i1, (-1));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 32700)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 32716)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, (OOC_CHAR8*)"} ", 3);
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
  *(OOC_INT8*)(_check_pointer(i0, 32946)) = i1;
  i1 = (OOC_INT32)name;
  *(OOC_INT32*)((_check_pointer(i0, 32975))+4) = i1;
  return;
  ;
}

OOC_C_DeclWriter__TypeRef OOC_C_DeclWriter__WriterDesc_NewTypeRef(OOC_C_DeclWriter__Writer w, OOC_INT8 _class, Object__String name) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_C_DeclWriter__TypeRef.baseTypes[0]);
  i1 = (OOC_INT32)name;
  i2 = _class;
  OOC_C_DeclWriter__InitTypeRef((OOC_C_DeclWriter__TypeRef)i0, i2, (Object__String)i1);
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
  i1 = *(OOC_INT8*)(_check_pointer(i0, 33396));
  switch (i1) {
  case 0:
    goto l6;
  case 1:
    i1 = (OOC_INT32)w;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 33444)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, (OOC_CHAR8*)"struct ", 8);
    goto l6;
  case 2:
    i1 = (OOC_INT32)w;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 33490)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, (OOC_CHAR8*)"union ", 7);
    goto l6;
  default:
    _failed_case(i1, 33384);
    goto l6;
  }
l6:
  i1 = (OOC_INT32)w;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33552))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 33530)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i1, (Object__Object)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 33566)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 32u);
  return;
  ;
}

void OOC_C_DeclWriter__TypeRefDesc_WriteRight(OOC_C_DeclWriter__TypeRef typeRef, OOC_C_DeclWriter__Writer w) {

  return;
  ;
}

static void OOC_C_DeclWriter__InitTypeOf(OOC_C_DeclWriter__TypeOf typeOf, Object__String arg) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)typeOf;
  i1 = (OOC_INT32)arg;
  *(OOC_INT32*)(_check_pointer(i0, 33769)) = i1;
  return;
  ;
}

OOC_C_DeclWriter__TypeOf OOC_C_DeclWriter__WriterDesc_NewTypeOf(OOC_C_DeclWriter__Writer w, Object__String arg) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_C_DeclWriter__TypeOf.baseTypes[0]);
  i1 = (OOC_INT32)arg;
  OOC_C_DeclWriter__InitTypeOf((OOC_C_DeclWriter__TypeOf)i0, (Object__String)i1);
  return (OOC_C_DeclWriter__TypeOf)i0;
  ;
}

OOC_INT8 OOC_C_DeclWriter__TypeOfDesc_Priority(OOC_C_DeclWriter__TypeOf typeOf) {

  return 0;
  ;
}

void OOC_C_DeclWriter__TypeOfDesc_WriteLeft(OOC_C_DeclWriter__TypeOf typeOf, OOC_C_DeclWriter__Writer w) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34133)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, (OOC_CHAR8*)"typeof(", 8);
  i1 = (OOC_INT32)typeOf;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 34186));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34165)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i0, (Object__Object)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34199)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, (OOC_CHAR8*)") ", 3);
  return;
  ;
}

void OOC_C_DeclWriter__TypeOfDesc_WriteRight(OOC_C_DeclWriter__TypeOf typeOf, OOC_C_DeclWriter__Writer w) {

  return;
  ;
}

void OOC_C_DeclWriter__WriterDesc_WriteType(OOC_C_DeclWriter__Writer w, OOC_C_DeclWriter__Type t) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)t;
  i1 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34375)))), OOC_C_DeclWriter__TypeDesc_WriteLeft)),OOC_C_DeclWriter__TypeDesc_WriteLeft)((OOC_C_DeclWriter__Type)i0, (OOC_C_DeclWriter__Writer)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34397)))), OOC_C_DeclWriter__TypeDesc_WriteRight)),OOC_C_DeclWriter__TypeDesc_WriteRight)((OOC_C_DeclWriter__Type)i0, (OOC_C_DeclWriter__Writer)i1);
  return;
  ;
}

static void OOC_C_DeclWriter__InitDeclaration(OOC_C_DeclWriter__Declaration d, Object__String name, OOC_INT8 typeQualifier, OOC_INT8 storageClass, OOC_C_DeclWriter__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)d;
  i1 = (OOC_INT32)name;
  *(OOC_INT32*)((_check_pointer(i0, 34726))+8) = i1;
  i1 = typeQualifier;
  *(OOC_INT8*)(_check_pointer(i0, 34747)) = i1;
  i1 = storageClass;
  *(OOC_INT8*)((_check_pointer(i0, 34786))+1) = i1;
  i1 = (OOC_INT32)type;
  *(OOC_INT32*)((_check_pointer(i0, 34823))+4) = i1;
  return;
  ;
}

OOC_C_DeclWriter__Declaration OOC_C_DeclWriter__WriterDesc_NewDeclaration(OOC_C_DeclWriter__Writer w, Object__String name, OOC_INT8 typeQualifier, OOC_INT8 storageClass, OOC_C_DeclWriter__Type type) {
  register OOC_INT32 i0,i1,i2,i3,i4;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_C_DeclWriter__Declaration.baseTypes[0]);
  i1 = (OOC_INT32)type;
  i2 = storageClass;
  i3 = typeQualifier;
  i4 = (OOC_INT32)name;
  OOC_C_DeclWriter__InitDeclaration((OOC_C_DeclWriter__Declaration)i0, (Object__String)i4, i3, i2, (OOC_C_DeclWriter__Type)i1);
  return (OOC_C_DeclWriter__Declaration)i0;
  ;
}

void OOC_C_DeclWriter__DeclarationDesc_SetTypeQualifier(OOC_C_DeclWriter__Declaration d, OOC_INT8 typeQualifier) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)d;
  i1 = typeQualifier;
  *(OOC_INT8*)(_check_pointer(i0, 35237)) = i1;
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
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 35494)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, (OOC_CHAR8*)"const ", 7);
        goto l6;
      case 2:
        i0 = (OOC_INT32)w;
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 35540)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, (OOC_CHAR8*)"volatile ", 10);
        goto l6;
      default:
        _failed_case(i0, 35431);
        goto l6;
      }
l6:
      return;
      ;
    }


  i0 = (OOC_INT32)d;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 35625))+1);
  switch (i1) {
  case 0:
    goto l10;
  case 1:
    i1 = (OOC_INT32)w;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 35680)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, (OOC_CHAR8*)"typedef ", 9);
    goto l10;
  case 2:
    i1 = (OOC_INT32)w;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 35726)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, (OOC_CHAR8*)"extern ", 8);
    goto l10;
  case 3:
    i1 = (OOC_INT32)w;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 35771)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, (OOC_CHAR8*)"static ", 8);
    goto l10;
  case 4:
    goto l10;
  case 5:
    i1 = (OOC_INT32)w;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 35834)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, (OOC_CHAR8*)"register ", 10);
    goto l10;
  case 6:
    i1 = (OOC_INT32)w;
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 35882)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, (OOC_CHAR8*)"auto ", 6);
    goto l10;
  default:
    _failed_case(i1, 35619);
    goto l10;
  }
l10:
  i0 = *(OOC_INT8*)(_check_pointer(i0, 35943));
  i1 = (OOC_INT32)w;
  OOC_C_DeclWriter__DeclarationDesc_Write_WriteTypeQualifier((OOC_C_DeclWriter__Writer)i1, i0);
  i0 = (OOC_INT32)d;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35980))+4);
  i2 = (OOC_INT32)w;
  OOC_C_DeclWriter__WriteLeft((OOC_C_DeclWriter__Writer)i2, (OOC_C_DeclWriter__Type)i1, 3);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36026))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 36010)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i2, (Object__Object)i1);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36055))+4);
  OOC_C_DeclWriter__WriteRight((OOC_C_DeclWriter__Writer)i2, (OOC_C_DeclWriter__Type)i0, 3);
  return;
  ;
}

static void OOC_C_DeclWriter__InitIncludeModule(OOC_C_DeclWriter__IncludeModule d, OOC_Repository__Module module) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)d;
  OOC_C_DeclWriter__InitDeclaration((OOC_C_DeclWriter__Declaration)i0, (Object__String)(OOC_INT32)0, 0, 4, (OOC_C_DeclWriter__Type)(OOC_INT32)0);
  i1 = (OOC_INT32)module;
  *(OOC_INT32*)((_check_pointer(i0, 36234))+12) = i1;
  return;
  ;
}

OOC_C_DeclWriter__IncludeModule OOC_C_DeclWriter__WriterDesc_NewIncludeModule(OOC_C_DeclWriter__Writer w, OOC_Repository__Module module) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)module;
  _assert((i0!=(OOC_INT32)0), 127, 36404);
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
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36750))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36750))+4);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 36755)), 0);
  i1 = (OOC_INT32)OOC_Repository_FileSystem__ModuleToFileName((void*)(_check_pointer(i2, 36755)), i1);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 36768));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 36768));
  i3 = fileId;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 36775)))), OOC_Repository__RepositoryDesc_GetDefaultSuffix)),OOC_Repository__RepositoryDesc_GetDefaultSuffix)((OOC_Repository__Repository)i0, i3);
  i0 = (OOC_INT32)Object__Concat2((void*)i1,(void*)i0);
  path = (Object__String)i0;
  i0 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36827)))), &_td_Object__String8Desc, 36827)));
  chars = (Object__CharsLatin1)i0;
  i1 = (OOC_INT32)w;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i0, 36876)), 0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 36856)))), OOC_C_DeclWriter__WriterDesc_WriteInclude)),OOC_C_DeclWriter__WriterDesc_WriteInclude)((OOC_C_DeclWriter__Writer)i1, (void*)(_check_pointer(i0, 36876)), i2);
  return;
  ;
}

void OOC_C_DeclWriter__IncludeModuleDesc_Write(OOC_C_DeclWriter__IncludeModule d, OOC_C_DeclWriter__Writer w) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)d;
  i1 = (OOC_INT32)w;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36989))+12);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 36968)))), OOC_C_DeclWriter__WriterDesc_WriteModuleInclude)),OOC_C_DeclWriter__WriterDesc_WriteModuleInclude)((OOC_C_DeclWriter__Writer)i1, (OOC_Repository__Module)i0, 13);
  return;
  ;
}

static void OOC_C_DeclWriter__InitDefine(OOC_C_DeclWriter__Define d, Object__String name, Object_Boxed__Object _const, OOC_SymbolTable__Type oocType) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)name;
  i1 = (OOC_INT32)d;
  OOC_C_DeclWriter__InitDeclaration((OOC_C_DeclWriter__Declaration)i1, (Object__String)i0, 0, 4, (OOC_C_DeclWriter__Type)(OOC_INT32)0);
  i0 = (OOC_INT32)_const;
  *(OOC_INT32*)((_check_pointer(i1, 37216))+12) = i0;
  i0 = (OOC_INT32)oocType;
  *(OOC_INT32*)((_check_pointer(i1, 37239))+16) = i0;
  return;
  ;
}

OOC_C_DeclWriter__Define OOC_C_DeclWriter__WriterDesc_NewDefine(OOC_C_DeclWriter__Writer w, Object__String name, Object_Boxed__Object _const, OOC_SymbolTable__Type oocType) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_C_DeclWriter__Define.baseTypes[0]);
  i1 = (OOC_INT32)oocType;
  i2 = (OOC_INT32)_const;
  i3 = (OOC_INT32)name;
  OOC_C_DeclWriter__InitDefine((OOC_C_DeclWriter__Define)i0, (Object__String)i3, (Object_Boxed__Object)i2, (OOC_SymbolTable__Type)i1);
  return (OOC_C_DeclWriter__Define)i0;
  ;
}

void OOC_C_DeclWriter__DefineDesc_Write(OOC_C_DeclWriter__Define d, OOC_C_DeclWriter__Writer w) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37614)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, (OOC_CHAR8*)"#define ", 9);
  i1 = (OOC_INT32)d;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 37663))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37647)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i0, (Object__Object)i2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37677)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, (OOC_CHAR8*)" ", 2);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 37707))+12);
  i2 = i2==(OOC_INT32)0;
  if (i2) goto l7;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 37791))+16);
  i2 = i2==(OOC_INT32)0;
  if (i2) goto l5;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 37922))+16);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 37912))+12);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37897)))), OOC_C_DeclWriter__WriterDesc_WriteConst)),OOC_C_DeclWriter__WriterDesc_WriteConst)((OOC_C_DeclWriter__Writer)i0, (Object_Boxed__Object)i1, (OOC_SymbolTable__Type)i2);
  goto l8;
l5:
  i2 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(13);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 37835))+12);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37820)))), OOC_C_DeclWriter__WriterDesc_WriteConst)),OOC_C_DeclWriter__WriterDesc_WriteConst)((OOC_C_DeclWriter__Writer)i0, (Object_Boxed__Object)i1, (OOC_SymbolTable__Type)i2);
  goto l8;
l7:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37734)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, (OOC_CHAR8*)" 0", 3);
l8:
  return;
  ;
}

void OOC_C_DeclWriter__WriterDesc_WriteTypeCast(OOC_C_DeclWriter__Writer w, OOC_C_DeclWriter__Type t) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 38020)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i0, 40u);
  i1 = (OOC_INT32)t;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 38044)))), OOC_C_DeclWriter__TypeDesc_WriteLeft)),OOC_C_DeclWriter__TypeDesc_WriteLeft)((OOC_C_DeclWriter__Type)i1, (OOC_C_DeclWriter__Writer)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 38066)))), OOC_C_DeclWriter__TypeDesc_WriteRight)),OOC_C_DeclWriter__TypeDesc_WriteRight)((OOC_C_DeclWriter__Type)i1, (OOC_C_DeclWriter__Writer)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 38089)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i0, 41u);
  return;
  ;
}

void OOC_OOC_C_DeclWriter_init(void) {

  return;
  ;
}

void OOC_OOC_C_DeclWriter_destroy(void) {
}

/* --- */
