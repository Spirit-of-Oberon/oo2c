#include <OOC/C/IRtoC.d>
#include <__oo2c.h>
#include <setjmp.h>

static void OOC_C_IRtoC__Call(OOC_C_DeclWriter__Writer w, OOC_IR__Call statm) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_IR__Expression design;
  Object__String name;
  OOC_INT32 i;

  i0 = (OOC_INT32)statm;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 504))+8);
  design = (OOC_IR__Expression)i1;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 529)))), &_td_OOC_IR__ProcedureRefDesc);
  if (i2) goto l3;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 518)))), 518);
  goto l4;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 596))+8);
  i1 = (OOC_INT32)OOC_C_Naming__NameOfDeclaration((OOC_SymbolTable__Declaration)i1);
  name = (Object__String)i1;
  i2 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 612)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i2, (Object__Object)i1);
l4:
  i1 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 647)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "(", 2);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 696))+12);
  i = 0;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 707)), 0);
  i3 = 0<i2;
  if (!i3) goto l15;
  i3=0;
l7_loop:
  i4 = i3!=0;
  if (!i4) goto l10;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 908)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ", ", 3);
l10:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 965))+12);
  i4 = _check_pointer(i4, 976);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 976))*4);
  OOC_C_IRtoC__WriteExpr((OOC_C_DeclWriter__Writer)i1, (OOC_IR__Expression)i4);
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l7_loop;
l15:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 995)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ")", 2);
  return;
  ;
}

static void OOC_C_IRtoC__WriteExpr(OOC_C_DeclWriter__Writer w, OOC_IR__Expression expr) {
  register OOC_INT32 i0,i1,i2;
  Object__String name;
  auto void OOC_C_IRtoC__WriteExpr_SetRange(OOC_IR__SetRange expr);
    
    void OOC_C_IRtoC__WriteExpr_SetRange(OOC_IR__SetRange expr) {
      register OOC_INT32 i0,i1,i2;
      auto void OOC_C_IRtoC__WriteExpr_SetRange_Bit(OOC_IR__Expression expr, OOC_CHAR8 next);
        
        void OOC_C_IRtoC__WriteExpr_SetRange_Bit(OOC_IR__Expression expr, OOC_CHAR8 next) {
          register OOC_INT32 i0,i1;

          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1265)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "(1<<(", 6);
          i0 = (OOC_INT32)expr;
          i1 = (OOC_INT32)w;
          OOC_C_IRtoC__WriteExpr((OOC_C_DeclWriter__Writer)i1, (OOC_IR__Expression)i0);
          i0 = next;
          if (!i0) goto l4;
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1339)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "+1", 3);
l4:
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1372)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "))", 3);
          return;
          ;
        }


      i0 = (OOC_INT32)expr;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1435))+12);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1445))+8);
      i1 = i1==i2;
      if (i1) goto l3;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 1507)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "(", 2);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1544))+12);
      OOC_C_IRtoC__WriteExpr_SetRange_Bit((OOC_IR__Expression)i0, 1u);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1565)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "-", 2);
      i0 = (OOC_INT32)expr;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1601))+8);
      OOC_C_IRtoC__WriteExpr_SetRange_Bit((OOC_IR__Expression)i0, 0u);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1625)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ")", 2);
      goto l4;
l3:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1472))+8);
      OOC_C_IRtoC__WriteExpr_SetRange_Bit((OOC_IR__Expression)i0, 0u);
l4:
      return;
      ;
    }


  i0 = (OOC_INT32)expr;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1698)))), &_td_OOC_IR__ConstDesc);
  if (i1) goto l55;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1779)))), &_td_OOC_IR__VarDesc);
  if (i1) goto l53;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1890)))), &_td_OOC_IR__AdrDesc);
  if (i1) goto l51;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2099)))), &_td_OOC_IR__LenDesc);
  if (i1) goto l49;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2391)))), &_td_OOC_IR__NegateDesc);
  if (i1) goto l47;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2485)))), &_td_OOC_IR__BinaryArithDesc);
  if (i1) goto l36;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2871)))), &_td_OOC_IR__SetOpDesc);
  if (i1) goto l27;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3185)))), &_td_OOC_IR__TypeConvDesc);
  if (i1) goto l25;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3296)))), &_td_OOC_IR__CallDesc);
  if (i1) goto l23;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3352)))), &_td_OOC_IR__SetRangeDesc);
  if (i1) goto l21;
  Log__Type("++ Unknown operator class in WriteExpr", 39, (void*)i0);
  _assert(0u, 127, 3470);
  goto l56;
l21:
  OOC_C_IRtoC__WriteExpr_SetRange((OOC_IR__SetRange)i0);
  goto l56;
l23:
  i1 = (OOC_INT32)w;
  OOC_C_IRtoC__Call((OOC_C_DeclWriter__Writer)i1, (OOC_IR__Call)i0);
  goto l56;
l25:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3225))+8);
  i1 = (OOC_INT32)w;
  OOC_C_IRtoC__WriteExpr((OOC_C_DeclWriter__Writer)i1, (OOC_IR__Expression)i0);
  goto l56;
l27:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2908))+12);
  i2 = (OOC_INT32)w;
  OOC_C_IRtoC__WriteExpr((OOC_C_DeclWriter__Writer)i2, (OOC_IR__Expression)i1);
  i1 = *(OOC_INT8*)((_check_pointer(i0, 2931))+8);
  switch (i1) {
  case 6:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 2966)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i2, 124u);
    goto l34;
  case 7:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 3007)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i2, "& ~", 4);
    goto l34;
  case 8:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 3055)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i2, 38u);
    goto l34;
  case 9:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 3099)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i2, 94u);
    goto l34;
  default:
    _failed_case(i1, 2922);
    goto l34;
  }
l34:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3151))+16);
  OOC_C_IRtoC__WriteExpr((OOC_C_DeclWriter__Writer)i2, (OOC_IR__Expression)i0);
  goto l56;
l36:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2528))+12);
  i2 = (OOC_INT32)w;
  OOC_C_IRtoC__WriteExpr((OOC_C_DeclWriter__Writer)i2, (OOC_IR__Expression)i1);
  i1 = *(OOC_INT8*)((_check_pointer(i0, 2552))+8);
  switch (i1) {
  case 0:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 2587)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i2, 43u);
    goto l45;
  case 1:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 2628)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i2, 45u);
    goto l45;
  case 2:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 2669)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i2, 47u);
    goto l45;
  case 3:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 2710)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i2, 47u);
    goto l45;
  case 4:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 2751)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i2, 42u);
    goto l45;
  case 5:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 2792)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i2, 37u);
    goto l45;
  default:
    _failed_case(i1, 2543);
    goto l45;
  }
l45:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2844))+16);
  OOC_C_IRtoC__WriteExpr((OOC_C_DeclWriter__Writer)i2, (OOC_IR__Expression)i0);
  goto l56;
l47:
  i1 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2413)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i1, 45u);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2456))+8);
  OOC_C_IRtoC__WriteExpr((OOC_C_DeclWriter__Writer)i1, (OOC_IR__Expression)i0);
  goto l56;
l49:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2233))+12);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2240))+4);
  i1 = *(OOC_INT16*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2251)))), &_td_OOC_SymbolTable__PredefTypeDesc, 2251)), 2262))+40);
  _assert((i1==13), 127, 2221);
  i1 = (OOC_INT32)w;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2313))+12);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2324)))), &_td_OOC_IR__ConstDesc, 2324)), 2330))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2344)))), &_td_Object_Boxed__StringDesc, 2344)), 2351));
  i0 = *(OOC_INT32*)(_check_pointer(i0, 2358));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2296)))), OOC_C_DeclWriter__WriterDesc_WriteLInt)),OOC_C_DeclWriter__WriterDesc_WriteLInt)((OOC_C_DeclWriter__Writer)i1, (i0+1), 0);
  goto l56;
l51:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2071))+8);
  i1 = (OOC_INT32)w;
  OOC_C_IRtoC__WriteExpr((OOC_C_DeclWriter__Writer)i1, (OOC_IR__Expression)i0);
  goto l56;
l53:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1835))+8);
  i0 = (OOC_INT32)OOC_C_Naming__NameOfDeclaration((OOC_SymbolTable__Declaration)i0);
  name = (Object__String)i0;
  i1 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 1851)))), OOC_C_DeclWriter__WriterDesc_WriteObject)),OOC_C_DeclWriter__WriterDesc_WriteObject)((OOC_C_DeclWriter__Writer)i1, (Object__Object)i0);
  goto l56;
l55:
  i1 = (OOC_INT32)w;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1737))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1750))+4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 1719)))), OOC_C_DeclWriter__WriterDesc_WriteConst)),OOC_C_DeclWriter__WriterDesc_WriteConst)((OOC_C_DeclWriter__Writer)i1, (Object_Boxed__Object)i2, (OOC_SymbolTable__Type)i0);
l56:
  return;
  ;
}

void OOC_C_IRtoC__WriteStatmSeq(OOC_C_DeclWriter__Writer w, OOC_IR__StatementSeq statmSeq) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_INT32 i;
  OOC_IR__Statement statm;
  auto void OOC_C_IRtoC__WriteStatmSeq_Assert(OOC_IR__Assert statm);
  auto void OOC_C_IRtoC__WriteStatmSeq_Return(OOC_IR__Return _return);
    
    void OOC_C_IRtoC__WriteStatmSeq_Assert(OOC_IR__Assert statm) {
      register OOC_INT32 i0,i1,i2;

      i0 = (OOC_INT32)statm;
      i1 = *(OOC_UINT8*)((_check_pointer(i0, 3730))+16);
      i1 = !i1;
      if (!i1) goto l4;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3755)))), OOC_C_DeclWriter__WriterDesc_WriteLn)),OOC_C_DeclWriter__WriterDesc_WriteLn)((OOC_C_DeclWriter__Writer)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3775)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "_assert(", 9);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3830))+8);
      i2 = (OOC_INT32)w;
      OOC_C_IRtoC__WriteExpr((OOC_C_DeclWriter__Writer)i2, (OOC_IR__Expression)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3853)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, ", ", 3);
      i1 = (OOC_INT32)w;
      i0 = *(OOC_INT32*)((_check_pointer(i0, 3902))+12);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3884)))), OOC_C_DeclWriter__WriterDesc_WriteLInt)),OOC_C_DeclWriter__WriterDesc_WriteLInt)((OOC_C_DeclWriter__Writer)i1, i0, 0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3923)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ", ", 3);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3954)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "0", 2);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4017)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ");", 3);
l4:
      return;
      ;
    }

    
    void OOC_C_IRtoC__WriteStatmSeq_Return(OOC_IR__Return _return) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4124)))), OOC_C_DeclWriter__WriterDesc_WriteLn)),OOC_C_DeclWriter__WriterDesc_WriteLn)((OOC_C_DeclWriter__Writer)i0);
      i0 = (OOC_INT32)_return;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4151))+8);
      i1 = i1==(OOC_INT32)0;
      if (i1) goto l3;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4227)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "return ", 8);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4282))+8);
      i1 = (OOC_INT32)w;
      OOC_C_IRtoC__WriteExpr((OOC_C_DeclWriter__Writer)i1, (OOC_IR__Expression)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4302)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, ";", 2);
      goto l4;
l3:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4181)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "return;", 8);
l4:
      return;
      ;
    }


  i0 = (OOC_INT32)statmSeq;
  i = 0;
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 4498)), 0);
  i1 = 0<i0;
  if (!i1) goto l20;
  i1=0;
l3_loop:
  i2 = (OOC_INT32)statmSeq;
  i2 = _check_pointer(i2, 4529);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i1, i3, OOC_UINT32, 4529))*4);
  statm = (OOC_IR__Statement)i1;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4550)))), &_td_OOC_IR__AssertDesc);
  if (i2) goto l14;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4601)))), &_td_OOC_IR__CallDesc);
  if (i2) goto l12;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4700)))), &_td_OOC_IR__ReturnDesc);
  if (i2) goto l10;
  Log__Type("++ Unknown statement class in WriteStatmSeq", 44, (void*)i1);
  _assert(0u, 127, 4829);
  goto l15;
l10:
  OOC_C_IRtoC__WriteStatmSeq_Return((OOC_IR__Return)i1);
  goto l15;
l12:
  i2 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 4623)))), OOC_C_DeclWriter__WriterDesc_WriteLn)),OOC_C_DeclWriter__WriterDesc_WriteLn)((OOC_C_DeclWriter__Writer)i2);
  OOC_C_IRtoC__Call((OOC_C_DeclWriter__Writer)i2, (OOC_IR__Call)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 4668)))), OOC_C_DeclWriter__WriterDesc_WriteChar)),OOC_C_DeclWriter__WriterDesc_WriteChar)((OOC_C_DeclWriter__Writer)i2, 59u);
  goto l15;
l14:
  OOC_C_IRtoC__WriteStatmSeq_Assert((OOC_IR__Assert)i1);
l15:
  i1 = i;
  i1 = i1+1;
  i = i1;
  i2 = i1<i0;
  if (i2) goto l3_loop;
l20:
  return;
  ;
}

void OOC_C_IRtoC__InitTranslator(OOC_C_IRtoC__Translator t) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)t;
  OOC_Make_TranslateToC__InitTranslator((OOC_Make_TranslateToC__Translator)i0);
  return;
  ;
}

OOC_C_IRtoC__Translator OOC_C_IRtoC__NewTranslator(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_C_IRtoC__Translator.baseTypes[0]);
  OOC_C_IRtoC__InitTranslator((OOC_C_IRtoC__Translator)i0);
  return (OOC_C_IRtoC__Translator)i0;
  ;
}

void OOC_C_IRtoC__TranslatorDesc_WriteProcBody(OOC_C_IRtoC__Translator t, OOC_IR__Procedure proc) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)t;
  i1 = (OOC_INT32)proc;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5232));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5241))+8);
  OOC_C_IRtoC__WriteStatmSeq((OOC_C_DeclWriter__Writer)i0, (OOC_IR__StatementSeq)i1);
  return;
  ;
}

void OOC_OOC_C_IRtoC_init(void) {

  return;
  ;
}

/* --- */
