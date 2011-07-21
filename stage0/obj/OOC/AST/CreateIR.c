#include <OOC/AST/CreateIR.d>
#include <__oo2c.h>
#include <setjmp.h>

OOC_IR__Module OOC_AST_CreateIR__CreateIR(OOC_AST__Module module, OOC_SymbolTable__Module symTab, OOC_IR__Builder b) {
  register OOC_INT32 i0,i1;
  OOC_SymbolTable__Item currentSourceContext;
  OOC_SymbolTable__Namespace currentNamespace;
  auto OOC_IR__Expression OOC_AST_CreateIR__CreateIR_Expr(OOC_AST__Node expr);
  auto OOC_IR__Expression OOC_AST_CreateIR__CreateIR_FunctionCall(OOC_AST__FunctionCall call, OOC_CHAR8 isProcCall);
  auto OOC_IR__Expression OOC_AST_CreateIR__CreateIR_QualType(OOC_AST__QualType qualType);
  auto OOC_IR__Expression OOC_AST_CreateIR__CreateIR_Designator(OOC_AST__Node design);
  auto OOC_IR__Expression OOC_AST_CreateIR__CreateIR_Range(OOC_AST__Node expr, OOC_CHAR8 isSet);
  auto OOC_IR__Expression OOC_AST_CreateIR__CreateIR_SetConstruct(OOC_AST__Set sc);
  auto OOC_IR__Expression OOC_AST_CreateIR__CreateIR_QualType(OOC_AST__QualType qualType);
  auto OOC_IR__Expression OOC_AST_CreateIR__CreateIR_Expr(OOC_AST__Node expr);
  auto OOC_IR__Expression OOC_AST_CreateIR__CreateIR_FunctionCall(OOC_AST__FunctionCall call, OOC_CHAR8 isProcCall);
  auto OOC_IR__StatementSeq OOC_AST_CreateIR__CreateIR_StatementSeq(OOC_AST__NodeList statmSeq);
  auto void OOC_AST_CreateIR__CreateIR_ConstDecl(OOC_SymbolTable__ConstDecl constDecl, OOC_AST__Node constExpr);
  auto OOC_IR__Procedure OOC_AST_CreateIR__CreateIR_ProcDecl(OOC_SymbolTable__ProcDecl procDecl, OOC_AST__ProcDecl procCode);
  auto OOC_IR__Module OOC_AST_CreateIR__CreateIR_Module(OOC_SymbolTable__Module moduleDecl, OOC_AST__Module moduleAST);
  auto void OOC_AST_CreateIR__CreateIR_TranslateEmbeddedExpr(OOC_SymbolTable__Item item);
    
    OOC_IR__Expression OOC_AST_CreateIR__CreateIR_Designator(OOC_AST__Node design) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
      OOC_IR__Expression left;
      OOC_Scanner_SymList__Symbol sym;
      OOC_INT32 i;
      auto OOC_IR__Expression OOC_AST_CreateIR__CreateIR_Designator_Select(OOC_AST__Operator design);
        
        OOC_IR__Expression OOC_AST_CreateIR__CreateIR_Designator_Select(OOC_AST__Operator design) {
          register OOC_INT32 i0,i1,i2,i3,i4;
          OOC_IR__Expression left;

          i0 = (OOC_INT32)design;
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 1846));
          i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Designator((OOC_AST__Node)i1);
          left = (OOC_IR__Expression)i1;
          i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 1872)))), &_td_OOC_IR__ModuleRefDesc);
          if (i2) goto l7;
          i2 = (OOC_INT32)b;
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 2140))+20);
          i3 = i1==i3;
          if (i3) goto l5;
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2281))+4);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2359))+8);
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2371)))), &_td_OOC_AST__TerminalDesc, 2371)), 2380));
          i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 2285));
          i4 = (OOC_INT32)currentSourceContext;
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 2262)))), OOC_IR__BuilderDesc_NewSelect)),OOC_IR__BuilderDesc_NewSelect)((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i3, (OOC_IR__Expression)i1, (OOC_SymbolTable__Item)i4, (OOC_Scanner_SymList__Symbol)i0);
          return (OOC_IR__Expression)i0;
          goto l8;
l5:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 2177))+20);
          return (OOC_IR__Expression)i0;
          goto l8;
l7:
          i2 = (OOC_INT32)b;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2010))+8);
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2022)))), &_td_OOC_AST__TerminalDesc, 2022)), 2031));
          i3 = (OOC_INT32)currentNamespace;
          i4 = (OOC_INT32)currentSourceContext;
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 1908)))), OOC_IR__BuilderDesc_NewQualident)),OOC_IR__BuilderDesc_NewQualident)((OOC_IR__Builder)i2, (OOC_SymbolTable__Namespace)i3, (OOC_IR__ModuleRef)i1, (OOC_SymbolTable__Item)i4, (OOC_Scanner_SymList__Symbol)i0);
          return (OOC_IR__Expression)i0;
l8:
          _failed_function(1716); return 0;
          ;
        }


      i0 = (OOC_INT32)design;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2465)))), &_td_OOC_AST__TerminalDesc);
      if (i1) goto l36;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2643)))), &_td_OOC_AST__ArrayIndexDesc);
      if (i1) goto l21;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3125)))), &_td_OOC_AST__OperatorDesc);
      if (i1) goto l15;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3402)))), &_td_OOC_AST__FunctionCallDesc);
      if (i1) goto l13;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3484)))), &_td_OOC_AST__QualTypeDesc);
      if (i1) goto l11;
      Log__Type("++ Unknown type in Designator", 30, (void*)i0);
      _assert(0u, 127, 3622);
      goto l37;
l11:
      i0 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_QualType((OOC_AST__QualType)i0);
      return (OOC_IR__Expression)i0;
      goto l37;
l13:
      i0 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_FunctionCall((OOC_AST__FunctionCall)i0, 0u);
      return (OOC_IR__Expression)i0;
      goto l37;
l15:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3161))+4);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 3165));
      i1 = *(OOC_INT8*)((_check_pointer(i1, 3170))+4);
      i1 = i1==18;
      if (i1) goto l18;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3268))+4);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 3272));
      i1 = *(OOC_INT8*)((_check_pointer(i1, 3277))+4);
      _assert((i1==17), 127, 3254);
      i1 = (OOC_INT32)b;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3335))+4);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3364));
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 3339));
      i0 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Designator((OOC_AST__Node)i0);
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3317)))), OOC_IR__BuilderDesc_NewDeref)),OOC_IR__BuilderDesc_NewDeref)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i0);
      return (OOC_IR__Expression)i0;
      goto l37;
l18:
      i0 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Designator_Select((OOC_AST__Operator)i0);
      return (OOC_IR__Expression)i0;
      goto l37;
l21:
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2697));
      i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Designator((OOC_AST__Node)i1);
      left = (OOC_IR__Expression)i1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2729))+4);
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 2736));
      sym = (OOC_Scanner_SymList__Symbol)i2;
      i = 0;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2784))+8);
      i3 = *(OOC_INT32*)(_check_pointer(i3, 2793));
      i3 = 0<i3;
      if (i3) goto l24;
      i0=i1;
      goto l34;
l24:
      {register OOC_INT32 h0=i1;i1=i2;i2=h0;}i3=0;
l25_loop:
      i4 = (OOC_INT32)b;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2888))+8);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 2897))+4);
      i5 = _check_pointer(i5, 2900);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 2900))*4);
      i5 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i5);
      i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 2822)))), OOC_IR__BuilderDesc_NewIndex)),OOC_IR__BuilderDesc_NewIndex)((OOC_IR__Builder)i4, (OOC_Scanner_SymList__Symbol)i1, (OOC_IR__Expression)i2, (OOC_IR__Expression)i5);
      left = (OOC_IR__Expression)i2;
      i3 = i3+1;
      i = i3;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2950))+8);
      i4 = *(OOC_INT32*)(_check_pointer(i4, 2959));
      i4 = i3<i4;
      if (!i4) goto l29;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2996))+8);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3005))+4);
      i1 = _check_pointer(i1, 3008);
      i4 = OOC_ARRAY_LENGTH(i1, 0);
      i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(i3, i4, OOC_UINT32, 3008))*4);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3016)))), &_td_OOC_AST__TerminalDesc, 3016)), 3025));
      sym = (OOC_Scanner_SymList__Symbol)i1;
      
l29:
      i3 = i3+1;
      i = i3;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2784))+8);
      i4 = *(OOC_INT32*)(_check_pointer(i4, 2793));
      i4 = i3<i4;
      if (i4) goto l25_loop;
l33:
      i0=i2;
l34:
      return (OOC_IR__Expression)i0;
      goto l37;
l36:
      i1 = (OOC_INT32)b;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2609));
      i2 = (OOC_INT32)currentNamespace;
      i3 = (OOC_INT32)currentSourceContext;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2499)))), OOC_IR__BuilderDesc_NewIdentRef)),OOC_IR__BuilderDesc_NewIdentRef)((OOC_IR__Builder)i1, (OOC_SymbolTable__Namespace)i2, (OOC_SymbolTable__Namespace)i2, (OOC_SymbolTable__Item)i3, (OOC_Scanner_SymList__Symbol)i0);
      return (OOC_IR__Expression)i0;
l37:
      _failed_function(1575); return 0;
      ;
    }

    
    OOC_IR__Expression OOC_AST_CreateIR__CreateIR_Range(OOC_AST__Node expr, OOC_CHAR8 isSet) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5;
      OOC_IR__Expression e;

      i0 = (OOC_INT32)expr;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3850)))), &_td_OOC_AST__OperatorDesc);
      if (!i1) goto l6;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3882))+4);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 3886));
      i1 = *(OOC_INT8*)((_check_pointer(i1, 3891))+4);
      i1 = i1==21;
      if (!i1) goto l6;
      i1 = (OOC_INT32)b;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3949))+4);
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3967));
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 3952));
      i3 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i3);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3984))+8);
      i4 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i4);
      i5 = isSet;
      i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3932)))), OOC_IR__BuilderDesc_NewSetRange)),OOC_IR__BuilderDesc_NewSetRange)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i3, (OOC_IR__Expression)i4, i5);
      return (OOC_IR__Expression)i1;
l6:
      i0 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i0);
      e = (OOC_IR__Expression)i0;
      i1 = (OOC_INT32)b;
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4077));
      i3 = isSet;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4063)))), OOC_IR__BuilderDesc_NewSetRange)),OOC_IR__BuilderDesc_NewSetRange)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i0, (OOC_IR__Expression)i0, i3);
      return (OOC_IR__Expression)i0;
      ;
    }

    
    OOC_IR__Expression OOC_AST_CreateIR__CreateIR_SetConstruct(OOC_AST__Set sc) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
      OOC_INT32 len;
      OOC_IR__Expression result;
      OOC_INT32 i;

      i0 = (OOC_INT32)sc;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4241))+8);
      i1 = *(OOC_INT32*)(_check_pointer(i1, 4254));
      i1 = i1==0;
      if (i1) goto l12;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4358))+8);
      i1 = *(OOC_INT32*)(_check_pointer(i1, 4370));
      i1 = (i1+1)>>1;
      len = i1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4410))+8);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 4422))+4);
      i2 = _check_pointer(i2, 4424);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(0, i3, OOC_UINT8, 4424))*4);
      i2 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Range((OOC_AST__Node)i2, 1u);
      result = (OOC_IR__Expression)i2;
      i = 1;
      i3 = 1<i1;
      if (i3) goto l5;
      i0=i2;
      goto l11;
l5:
      i3=1;
l6_loop:
      i4 = (OOC_INT32)b;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4528))+8);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 4540))+4);
      i5 = _check_pointer(i5, 4542);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index((i3*2), i6, OOC_UINT32, 4542))*4);
      i5 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Range((OOC_AST__Node)i5, 1u);
      i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 4484)))), OOC_IR__BuilderDesc_NewSetOp)),OOC_IR__BuilderDesc_NewSetOp)((OOC_IR__Builder)i4, (OOC_Scanner_SymList__Symbol)0, 6, (OOC_IR__Expression)i2, (OOC_IR__Expression)i5);
      result = (OOC_IR__Expression)i2;
      i3 = i3+1;
      i = i3;
      i4 = i3<i1;
      if (i4) goto l6_loop;
l10:
      i0=i2;
l11:
      return (OOC_IR__Expression)i0;
      goto l13;
l12:
      i1 = (OOC_INT32)b;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4301))+4);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4309));
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4284)))), OOC_IR__BuilderDesc_NewSetRange)),OOC_IR__BuilderDesc_NewSetRange)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i0, (OOC_IR__Expression)0, (OOC_IR__Expression)0, 1u);
      return (OOC_IR__Expression)i0;
l13:
      _failed_function(4123); return 0;
      ;
    }

    
    OOC_IR__Expression OOC_AST_CreateIR__CreateIR_QualType(OOC_AST__QualType qualType) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
      OOC_IR__Expression type;
      OOC_IR__ExpressionList arguments;
      OOC_INT32 i;
      OOC_AST__Node n;

      i0 = (OOC_INT32)qualType;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4831));
      i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Designator((OOC_AST__Node)i1);
      type = (OOC_IR__Expression)i1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4874))+8);
      i2 = *(OOC_INT32*)(_check_pointer(i2, 4884));
      i2 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__ExpressionList.baseTypes[0], ((i2+1)>>1));
      arguments = (OOC_IR__ExpressionList)i2;
      i = 0;
      i3 = OOC_ARRAY_LENGTH((_check_pointer(i2, 4933)), 0);
      i4 = 0<i3;
      if (!i4) goto l12;
      i4=0;
l3_loop:
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4962))+8);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 4972))+4);
      i5 = _check_pointer(i5, 4974);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index((i4*2), i6, OOC_UINT32, 4974))*4);
      n = (OOC_AST__Node)i5;
      i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 4995)))), &_td_OOC_AST__QualTypeDesc);
      if (i6) goto l6;
      i6 = _check_pointer(i2, 5084);
      i7 = OOC_ARRAY_LENGTH(i6, 0);
      i5 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Designator((OOC_AST__Node)i5);
      *(OOC_INT32*)(i6+(_check_index(i4, i7, OOC_UINT32, 5084))*4) = i5;
      goto l7;
l6:
      i6 = _check_pointer(i2, 5032);
      i7 = OOC_ARRAY_LENGTH(i6, 0);
      i5 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_QualType((OOC_AST__QualType)i5);
      *(OOC_INT32*)(i6+(_check_index(i4, i7, OOC_UINT32, 5032))*4) = i5;
l7:
      i4 = i4+1;
      i = i4;
      i5 = i4<i3;
      if (i5) goto l3_loop;
l12:
      i3 = (OOC_INT32)b;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5208))+12);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5215));
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 5170)))), OOC_IR__BuilderDesc_NewQualType)),OOC_IR__BuilderDesc_NewQualType)((OOC_IR__Builder)i3, (OOC_IR__Expression)i1, (OOC_IR__ExpressionList)i2, (OOC_Scanner_SymList__Symbol)i0);
      return (OOC_IR__Expression)i0;
      ;
    }

    
    OOC_IR__Expression OOC_AST_CreateIR__CreateIR_Expr(OOC_AST__Node expr) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_IR__Expression res;
      OOC_IR__Expression left;
      OOC_IR__Expression right;

      i0 = (OOC_INT32)expr;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5366)))), &_td_OOC_AST__TerminalDesc);
      if (i1) goto l43;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6057)))), &_td_OOC_AST__FactorDesc);
      if (i1) goto l41;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6131)))), &_td_OOC_AST__ArrayIndexDesc);
      if (i1) goto l39;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6234)))), &_td_OOC_AST__OperatorDesc);
      if (i1) goto l21;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6798)))), &_td_OOC_AST__SetDesc);
      if (i1) goto l19;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6859)))), &_td_OOC_AST__FunctionCallDesc);
      if (i1) goto l17;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6937)))), &_td_OOC_AST__QualTypeDesc);
      if (i1) goto l15;
      Log__Type("++ Unknown expression class in Expr", 36, (void*)i0);
      _assert(0u, 127, 7077);
      goto l55;
l15:
      i0 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_QualType((OOC_AST__QualType)i0);
      res = (OOC_IR__Expression)i0;
      goto l55;
l17:
      i0 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_FunctionCall((OOC_AST__FunctionCall)i0, 0u);
      res = (OOC_IR__Expression)i0;
      goto l55;
l19:
      i0 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_SetConstruct((OOC_AST__Set)i0);
      res = (OOC_IR__Expression)i0;
      goto l55;
l21:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6268))+4);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 6272));
      i1 = *(OOC_INT8*)((_check_pointer(i1, 6277))+4);
      i1 = i1==18;
      if (i1) goto l24;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6318))+4);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 6322));
      i1 = *(OOC_INT8*)((_check_pointer(i1, 6327))+4);
      i1 = i1==17;
      
      goto l26;
l24:
      i1=1u;
l26:
      if (i1) goto l36;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6466));
      i1 = i1!=0;
      if (i1) goto l30;
      left = (OOC_IR__Expression)0;
      i1=0;
      goto l31;
l30:
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6515));
      i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i1);
      left = (OOC_IR__Expression)i1;
      
l31:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6595))+8);
      i2 = i2!=0;
      if (i2) goto l34;
      right = (OOC_IR__Expression)0;
      i2=0;
      goto l35;
l34:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6646))+8);
      i2 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i2);
      right = (OOC_IR__Expression)i2;
      
l35:
      i3 = (OOC_INT32)b;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6747))+4);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6751));
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 6728)))), OOC_IR__BuilderDesc_NewOperator)),OOC_IR__BuilderDesc_NewOperator)((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i0, (OOC_IR__Expression)i1, (OOC_IR__Expression)i2);
      res = (OOC_IR__Expression)i0;
      
      goto l55;
l36:
      i0 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Designator((OOC_AST__Node)i0);
      res = (OOC_IR__Expression)i0;
      
      goto l55;
l39:
      i0 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Designator((OOC_AST__Node)i0);
      res = (OOC_IR__Expression)i0;
      goto l55;
l41:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6098))+4);
      i0 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i0);
      res = (OOC_IR__Expression)i0;
      goto l55;
l43:
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5401));
      i1 = *(OOC_INT8*)((_check_pointer(i1, 5406))+4);
      switch (i1) {
      case 45:
        i0 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Designator((OOC_AST__Node)i0);
        res = (OOC_IR__Expression)i0;
        goto l55;
      case 43:
      case 44:
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5565));
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5543)))), OOC_IR__BuilderDesc_NewStringConst)),OOC_IR__BuilderDesc_NewStringConst)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i0);
        res = (OOC_IR__Expression)i0;
        goto l55;
      case 37:
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5638));
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5617)))), OOC_IR__BuilderDesc_NewIntConst10)),OOC_IR__BuilderDesc_NewIntConst10)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i0);
        res = (OOC_IR__Expression)i0;
        goto l55;
      case 38:
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5711));
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5690)))), OOC_IR__BuilderDesc_NewIntConst16)),OOC_IR__BuilderDesc_NewIntConst16)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i0);
        res = (OOC_IR__Expression)i0;
        goto l55;
      case 39:
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5786));
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5764)))), OOC_IR__BuilderDesc_NewCharConst16)),OOC_IR__BuilderDesc_NewCharConst16)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i0);
        res = (OOC_IR__Expression)i0;
        goto l55;
      case 40:
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5860));
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5840)))), OOC_IR__BuilderDesc_NewRealConst)),OOC_IR__BuilderDesc_NewRealConst)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i0, 8);
        res = (OOC_IR__Expression)i0;
        goto l55;
      case 41:
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5947));
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5927)))), OOC_IR__BuilderDesc_NewRealConst)),OOC_IR__BuilderDesc_NewRealConst)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i0, 9);
        res = (OOC_IR__Expression)i0;
        goto l55;
      case 42:
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6025));
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6011)))), OOC_IR__BuilderDesc_NewNil)),OOC_IR__BuilderDesc_NewNil)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i0);
        res = (OOC_IR__Expression)i0;
        goto l55;
      default:
        _failed_case(i1, 5392);
        goto l55;
      }
l55:
      i0 = (OOC_INT32)b;
      i1 = (OOC_INT32)res;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7117)))), OOC_IR__BuilderDesc_Fold)),OOC_IR__BuilderDesc_Fold)((OOC_IR__Builder)i0, (OOC_IR__Expression)i1);
      return (OOC_IR__Expression)i0;
      ;
    }

    
    OOC_IR__Expression OOC_AST_CreateIR__CreateIR_FunctionCall(OOC_AST__FunctionCall call, OOC_CHAR8 isProcCall) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
      OOC_IR__Expression design;
      OOC_IR__ExpressionList arguments;
      OOC_INT32 i;

      i0 = (OOC_INT32)call;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7393));
      i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Designator((OOC_AST__Node)i1);
      design = (OOC_IR__Expression)i1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7431))+8);
      i2 = *(OOC_INT32*)(_check_pointer(i2, 7442));
      i2 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__ExpressionList.baseTypes[0], ((i2+1)>>1));
      arguments = (OOC_IR__ExpressionList)i2;
      i = 0;
      i3 = OOC_ARRAY_LENGTH((_check_pointer(i2, 7493)), 0);
      i4 = 0<i3;
      if (!i4) goto l8;
      i4=0;
l3_loop:
      i5 = _check_pointer(i2, 7518);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7535))+8);
      i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i7, 7546))+4);
      i7 = _check_pointer(i7, 7549);
      i8 = OOC_ARRAY_LENGTH(i7, 0);
      i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index((i4*2), i8, OOC_UINT32, 7549))*4);
      i7 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i7);
      *(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 7518))*4) = i7;
      i4 = i4+1;
      i = i4;
      i5 = i4<i3;
      if (i5) goto l3_loop;
l8:
      i3 = (OOC_INT32)b;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7671))+12);
      i4 = isProcCall;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7678));
      i5 = (OOC_INT32)currentSourceContext;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 7581)))), OOC_IR__BuilderDesc_NewCall)),OOC_IR__BuilderDesc_NewCall)((OOC_IR__Builder)i3, (OOC_IR__Expression)i1, (OOC_IR__ExpressionList)i2, (!i4), (OOC_SymbolTable__Item)i5, (OOC_Scanner_SymList__Symbol)i0);
      return (OOC_IR__Expression)i0;
      ;
    }

    
    OOC_IR__StatementSeq OOC_AST_CreateIR__CreateIR_StatementSeq(OOC_AST__NodeList statmSeq) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
      OOC_INT32 count;
      OOC_INT32 i;
      OOC_IR__StatementSeq statmSeqIR;
      OOC_AST__Node n;
      OOC_IR__Statement statm;
      OOC_IR__StatementSeq copy;
      auto OOC_IR__Statement OOC_AST_CreateIR__CreateIR_StatementSeq_ProcedureCall(OOC_AST__ProcedureCall call);
      auto OOC_IR__Statement OOC_AST_CreateIR__CreateIR_StatementSeq_Return(OOC_AST__ReturnStatm _return);
      auto OOC_IR__Statement OOC_AST_CreateIR__CreateIR_StatementSeq_Assignment(OOC_AST__Node design, OOC_AST__Node op, OOC_AST__Node value);
      auto OOC_IR__Statement OOC_AST_CreateIR__CreateIR_StatementSeq_IfStatm(OOC_AST__IfStatm ifStatm);
      auto OOC_IR__Statement OOC_AST_CreateIR__CreateIR_StatementSeq_CaseStatm(OOC_AST__CaseStatm caseStatm);
      auto OOC_IR__Statement OOC_AST_CreateIR__CreateIR_StatementSeq_RepeatStatm(OOC_AST__RepeatStatm repeatStatm);
      auto OOC_IR__Statement OOC_AST_CreateIR__CreateIR_StatementSeq_WhileStatm(OOC_AST__WhileStatm whileStatm);
      auto OOC_IR__Statement OOC_AST_CreateIR__CreateIR_StatementSeq_WithStatm(OOC_AST__WithStatm withStatm);
      auto OOC_IR__Statement OOC_AST_CreateIR__CreateIR_StatementSeq_ForStatm(OOC_AST__ForStatm forStatm);
      auto OOC_IR__Statement OOC_AST_CreateIR__CreateIR_StatementSeq_LoopStatm(OOC_AST__LoopStatm loopStatm);
      auto OOC_IR__Statement OOC_AST_CreateIR__CreateIR_StatementSeq_TryStatm(OOC_AST__TryStatm tryStatm);
        
        OOC_IR__Statement OOC_AST_CreateIR__CreateIR_StatementSeq_ProcedureCall(OOC_AST__ProcedureCall call) {
          register OOC_INT32 i0,i1,i2,i3,i4;
          OOC_IR__Expression expr;
          OOC_IR__ExpressionList arguments;
          OOC_IR__Expression design;

          i0 = (OOC_INT32)call;
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 8079));
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8086)))), &_td_OOC_AST__FunctionCallDesc);
          if (i1) goto l3;
          i1 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__ExpressionList.baseTypes[0], 0);
          arguments = (OOC_IR__ExpressionList)i1;
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 8321));
          i0 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Designator((OOC_AST__Node)i0);
          design = (OOC_IR__Expression)i0;
          i2 = (OOC_INT32)b;
          i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 8440));
          i4 = (OOC_INT32)currentSourceContext;
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 8349)))), OOC_IR__BuilderDesc_NewCall)),OOC_IR__BuilderDesc_NewCall)((OOC_IR__Builder)i2, (OOC_IR__Expression)i0, (OOC_IR__ExpressionList)i1, 0u, (OOC_SymbolTable__Item)i4, (OOC_Scanner_SymList__Symbol)i3);
          expr = (OOC_IR__Expression)i0;
          
          goto l4;
l3:
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 8148));
          i0 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_FunctionCall((OOC_AST__FunctionCall)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8159)))), &_td_OOC_AST__FunctionCallDesc, 8159)), 1u);
          expr = (OOC_IR__Expression)i0;
          
l4:
          i1 = i0!=0;
          if (i1) goto l7;
          i1=0u;
          goto l9;
l7:
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8492)))), &_td_OOC_IR__StatementDesc);
          
l9:
          if (i1) goto l11;
          return (OOC_IR__Statement)0;
          goto l12;
l11:
          return (OOC_IR__Statement)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8539)))), &_td_OOC_IR__StatementDesc, 8539));
l12:
          _failed_function(7911); return 0;
          ;
        }

        
        OOC_IR__Statement OOC_AST_CreateIR__CreateIR_StatementSeq_Return(OOC_AST__ReturnStatm _return) {
          register OOC_INT32 i0,i1,i2;

          i0 = (OOC_INT32)_return;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8775))+4);
          i1 = i1==(OOC_INT32)0;
          if (i1) goto l3;
          i1 = (OOC_INT32)b;
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 8901));
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8959))+4);
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 8909));
          i0 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i0);
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8882)))), OOC_IR__BuilderDesc_NewReturn)),OOC_IR__BuilderDesc_NewReturn)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i0);
          return (OOC_IR__Statement)i0;
          goto l4;
l3:
          i1 = (OOC_INT32)b;
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 8831));
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 8839));
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8812)))), OOC_IR__BuilderDesc_NewReturn)),OOC_IR__BuilderDesc_NewReturn)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i0, (OOC_IR__Expression)(OOC_INT32)0);
          return (OOC_IR__Statement)i0;
l4:
          _failed_function(8697); return 0;
          ;
        }

        
        OOC_IR__Statement OOC_AST_CreateIR__CreateIR_StatementSeq_Assignment(OOC_AST__Node design, OOC_AST__Node op, OOC_AST__Node value) {
          register OOC_INT32 i0,i1,i2,i3;
          OOC_IR__Expression variable;
          OOC_IR__Expression valueExpr;

          i0 = (OOC_INT32)design;
          i0 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Designator((OOC_AST__Node)i0);
          variable = (OOC_IR__Expression)i0;
          i1 = (OOC_INT32)value;
          i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i1);
          valueExpr = (OOC_IR__Expression)i1;
          i2 = (OOC_INT32)b;
          i3 = (OOC_INT32)op;
          i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 9252)))), &_td_OOC_AST__TerminalDesc, 9252)), 9261));
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 9228)))), OOC_IR__BuilderDesc_NewAssignment)),OOC_IR__BuilderDesc_NewAssignment)((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i3, (OOC_IR__Expression)i0, (OOC_IR__Expression)i1);
          return (OOC_IR__Statement)i0;
          ;
        }

        
        OOC_IR__Statement OOC_AST_CreateIR__CreateIR_StatementSeq_IfStatm(OOC_AST__IfStatm ifStatm) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
          OOC_IR__StatementSeq elseSeq;
          OOC_INT32 i;
          OOC_IR__Statement _else;

          i0 = (OOC_INT32)ifStatm;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9499))+4);
          i1 = i1!=(OOC_INT32)0;
          if (i1) goto l3;
          elseSeq = (OOC_IR__StatementSeq)(OOC_INT32)0;
          i1=(OOC_INT32)0;
          goto l4;
l3:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9560))+8);
          i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq((OOC_AST__NodeList)i1);
          elseSeq = (OOC_IR__StatementSeq)i1;
          
l4:
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9647));
          i2 = *(OOC_INT32*)(_check_pointer(i2, 9658));
          i2 = i2-4;
          i = i2;
          {register OOC_INT32 h0=i1;i1=i2;i2=h0;}
l5_loop:
          i3 = (OOC_INT32)b;
          i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9736));
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 9747))+4);
          i4 = _check_pointer(i4, 9750);
          i5 = OOC_ARRAY_LENGTH(i4, 0);
          i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i1, i5, OOC_UINT32, 9750))*4);
          i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9802));
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 9813))+4);
          i5 = _check_pointer(i5, 9816);
          i6 = OOC_ARRAY_LENGTH(i5, 0);
          i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index((i1+1), i6, OOC_UINT32, 9816))*4);
          i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 9758)))), &_td_OOC_AST__TerminalDesc, 9758)), 9767));
          i5 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i5);
          i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9860));
          i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 9871))+4);
          i6 = _check_pointer(i6, 9874);
          i7 = OOC_ARRAY_LENGTH(i6, 0);
          i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index((i1+3), i7, OOC_UINT32, 9874))*4);
          i6 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq((OOC_AST__NodeList)(_type_guard(i6, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 9884)))), &_td_OOC_AST__NodeListDesc, 9884)));
          i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 9701)))), OOC_IR__BuilderDesc_NewIfStatm)),OOC_IR__BuilderDesc_NewIfStatm)((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i4, (OOC_IR__Expression)i5, (OOC_IR__StatementSeq)i6, (OOC_IR__StatementSeq)i2);
          _else = (OOC_IR__Statement)i2;
          i3 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__StatementSeq.baseTypes[0], 1);
          elseSeq = (OOC_IR__StatementSeq)i3;
          i4 = _check_pointer(i3, 9966);
          i5 = OOC_ARRAY_LENGTH(i4, 0);
          *(OOC_INT32*)(i4+(_check_index(0, i5, OOC_UINT8, 9966))*4) = i2;
          i1 = i1-4;
          i = i1;
          i4 = i1<0;
          if (i4) goto l9;
          i2=i3;
          goto l5_loop;
l9:
          return (OOC_IR__Statement)i2;
          ;
        }

        
        OOC_IR__Statement OOC_AST_CreateIR__CreateIR_StatementSeq_CaseStatm(OOC_AST__CaseStatm caseStatm) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10;
          OOC_IR__Expression select;
          OOC_INT32 count;
          OOC_INT32 i;
          OOC_IR__CaseList caseList;
          OOC_IR__StatementSeq elseSeq;
          auto OOC_IR__CaseLabels OOC_AST_CreateIR__CreateIR_StatementSeq_CaseStatm_Labels(OOC_AST__NodeList labels);
            
            OOC_IR__CaseLabels OOC_AST_CreateIR__CreateIR_StatementSeq_CaseStatm_Labels(OOC_AST__NodeList labels) {
              register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
              OOC_IR__CaseLabels setRanges;
              OOC_INT32 i;

              i0 = (OOC_INT32)labels;
              i1 = *(OOC_INT32*)(_check_pointer(i0, 10444));
              i1 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__CaseLabels.baseTypes[0], ((i1+1)>>1));
              setRanges = (OOC_IR__CaseLabels)i1;
              i = 0;
              i2 = *(OOC_INT32*)(_check_pointer(i0, 10491));
              i3 = 0<i2;
              if (!i3) goto l8;
              i3=0;
l3_loop:
              i4 = _check_pointer(i1, 10528);
              i5 = OOC_ARRAY_LENGTH(i4, 0);
              i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10554))+4);
              i6 = _check_pointer(i6, 10557);
              i7 = OOC_ARRAY_LENGTH(i6, 0);
              i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i3, i7, OOC_UINT32, 10557))*4);
              i6 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Range((OOC_AST__Node)i6, 0u);
              *(OOC_INT32*)(i4+(_check_index((i3>>1), i5, OOC_UINT32, 10528))*4) = i6;
              i3 = i3+2;
              i = i3;
              i4 = i3<i2;
              if (i4) goto l3_loop;
l8:
              return (OOC_IR__CaseLabels)i1;
              ;
            }


          i0 = (OOC_INT32)caseStatm;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10685))+4);
          i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i1);
          select = (OOC_IR__Expression)i1;
          count = 0;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10785))+12);
          i1 = *(OOC_INT32*)(_check_pointer(i1, 10795));
          i = 0;
          i2 = 0<i1;
          if (i2) goto l3;
          i1=0;
          goto l13;
l3:
          i2=0;i3=0;
l4_loop:
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10834))+12);
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 10844))+4);
          i4 = _check_pointer(i4, 10847);
          i5 = OOC_ARRAY_LENGTH(i4, 0);
          i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i2, i5, OOC_UINT32, 10847))*4);
          i4 = i4!=0;
          if (!i4) goto l8;
          i3 = i3+1;
          count = i3;
          
l8:
          i2 = i2+4;
          i = i2;
          i4 = i2<i1;
          if (i4) goto l4_loop;
l12:
          i1=i3;
l13:
          caseList = (OOC_IR__CaseList)((OOC_INT32)RT0__NewObject(_td_OOC_IR__CaseList.baseTypes[0], i1));
          count = 0;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11046))+12);
          i = 0;
          i1 = *(OOC_INT32*)(_check_pointer(i1, 11056));
          i2 = 0<i1;
          if (!i2) goto l26;
          i2=0;i3=0;
l17_loop:
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11095))+12);
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 11105))+4);
          i4 = _check_pointer(i4, 11108);
          i5 = OOC_ARRAY_LENGTH(i4, 0);
          i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i2, i5, OOC_UINT32, 11108))*4);
          i4 = i4!=0;
          if (i4) goto l20;
          {register OOC_INT32 h0=i2;i2=i3;i3=h0;}
          goto l21;
l20:
          i4 = (OOC_INT32)caseList;
          i4 = _check_pointer(i4, 11144);
          i5 = OOC_ARRAY_LENGTH(i4, 0);
          i6 = (OOC_INT32)b;
          i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11190))+12);
          i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i7, 11200))+4);
          i7 = _check_pointer(i7, 11203);
          i8 = OOC_ARRAY_LENGTH(i7, 0);
          i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index((i2+1), i8, OOC_UINT32, 11203))*4);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11261))+12);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11271))+4);
          i0 = _check_pointer(i0, 11274);
          i8 = OOC_ARRAY_LENGTH(i0, 0);
          i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(i2, i8, OOC_UINT32, 11274))*4);
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i7, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 11213)))), &_td_OOC_AST__TerminalDesc, 11213)), 11222));
          i0 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq_CaseStatm_Labels((OOC_AST__NodeList)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11282)))), &_td_OOC_AST__NodeListDesc, 11282)));
          i7 = (OOC_INT32)caseStatm;
          i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i7, 11332))+12);
          i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i8, 11342))+4);
          i8 = _check_pointer(i8, 11345);
          i9 = i;
          i10 = OOC_ARRAY_LENGTH(i8, 0);
          i8 = (OOC_INT32)*(OOC_INT32*)(i8+(_check_index((i9+2), i10, OOC_UINT32, 11345))*4);
          i8 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq((OOC_AST__NodeList)(_type_guard(i8, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i8, 11355)))), &_td_OOC_AST__NodeListDesc, 11355)));
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 11156)))), OOC_IR__BuilderDesc_NewCase)),OOC_IR__BuilderDesc_NewCase)((OOC_IR__Builder)i6, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__CaseLabels)i0, (OOC_IR__StatementSeq)i8);
          i2 = count;
          *(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 11144))*4) = i0;
          i0 = i2+1;
          count = i0;
          i2=i0;i0=i7;i3=i9;
l21:
          i3 = i3+4;
          i = i3;
          i4 = i3<i1;
          if (!i4) goto l26;
          {register OOC_INT32 h0=i2;i2=i3;i3=h0;}
          goto l17_loop;
l26:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11442))+16);
          i1 = i1!=0;
          if (i1) goto l29;
          elseSeq = (OOC_IR__StatementSeq)0;
          i1=0;
          goto l30;
l29:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11505))+20);
          i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq((OOC_AST__NodeList)i1);
          elseSeq = (OOC_IR__StatementSeq)i1;
          
l30:
          i2 = (OOC_INT32)b;
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 11613));
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 11619));
          i3 = (OOC_INT32)select;
          i4 = (OOC_INT32)caseList;
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 11588)))), OOC_IR__BuilderDesc_NewCaseStatm)),OOC_IR__BuilderDesc_NewCaseStatm)((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i0, (OOC_IR__Expression)i3, (OOC_IR__CaseList)i4, (OOC_IR__StatementSeq)i1);
          return (OOC_IR__Statement)i0;
          ;
        }

        
        OOC_IR__Statement OOC_AST_CreateIR__CreateIR_StatementSeq_RepeatStatm(OOC_AST__RepeatStatm repeatStatm) {
          register OOC_INT32 i0,i1,i2,i3;

          i0 = (OOC_INT32)b;
          i1 = (OOC_INT32)repeatStatm;
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 11839));
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 11847));
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11913))+4);
          i3 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq((OOC_AST__NodeList)i3);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11977))+12);
          i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i1);
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11810)))), OOC_IR__BuilderDesc_NewRepeatStatm)),OOC_IR__BuilderDesc_NewRepeatStatm)((OOC_IR__Builder)i0, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__StatementSeq)i3, (OOC_IR__Expression)i1);
          return (OOC_IR__Statement)i0;
          ;
        }

        
        OOC_IR__Statement OOC_AST_CreateIR__CreateIR_StatementSeq_WhileStatm(OOC_AST__WhileStatm whileStatm) {
          register OOC_INT32 i0,i1,i2,i3;

          i0 = (OOC_INT32)b;
          i1 = (OOC_INT32)whileStatm;
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 12137));
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 12144));
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12200))+4);
          i3 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i3);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12267))+12);
          i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq((OOC_AST__NodeList)i1);
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12110)))), OOC_IR__BuilderDesc_NewWhileStatm)),OOC_IR__BuilderDesc_NewWhileStatm)((OOC_IR__Builder)i0, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i3, (OOC_IR__StatementSeq)i1);
          return (OOC_IR__Statement)i0;
          ;
        }

        
        OOC_IR__Statement OOC_AST_CreateIR__CreateIR_StatementSeq_WithStatm(OOC_AST__WithStatm withStatm) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5;
          OOC_IR__StatementSeq elseSeq;
          OOC_IR__Statement _else;
          OOC_INT32 i;
          OOC_IR__Expression guard;
          OOC_IR__StatementSeq region;
          auto OOC_IR__Expression OOC_AST_CreateIR__CreateIR_StatementSeq_WithStatm_TypeTestExpr(OOC_AST__Operator op);
            
            OOC_IR__Expression OOC_AST_CreateIR__CreateIR_StatementSeq_WithStatm_TypeTestExpr(OOC_AST__Operator op) {
              register OOC_INT32 i0,i1,i2,i3;

              i0 = (OOC_INT32)b;
              i1 = (OOC_INT32)op;
              i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12616))+4);
              i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 12619));
              i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 12633));
              i3 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i3);
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12650))+8);
              i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i1);
              i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12599)))), OOC_IR__BuilderDesc_NewTypeTest)),OOC_IR__BuilderDesc_NewTypeTest)((OOC_IR__Builder)i0, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i3, (OOC_IR__Expression)i1);
              return (OOC_IR__Expression)i0;
              ;
            }


          i0 = (OOC_INT32)withStatm;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12727))+4);
          i1 = i1!=(OOC_INT32)0;
          if (i1) goto l3;
          elseSeq = (OOC_IR__StatementSeq)(OOC_INT32)0;
          goto l4;
l3:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12790))+8);
          i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq((OOC_AST__NodeList)i1);
          elseSeq = (OOC_IR__StatementSeq)i1;
l4:
          _else = (OOC_IR__Statement)(OOC_INT32)0;
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 12900));
          i0 = *(OOC_INT32*)(_check_pointer(i0, 12911));
          i0 = i0-4;
          i = i0;
          
l5_loop:
          i1 = (OOC_INT32)withStatm;
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 12976));
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12986))+4);
          i1 = _check_pointer(i1, 12988);
          i2 = OOC_ARRAY_LENGTH(i1, 0);
          i0 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index((i0+1), i2, OOC_UINT32, 12988))*4);
          i0 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq_WithStatm_TypeTestExpr((OOC_AST__Operator)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12998)))), &_td_OOC_AST__OperatorDesc, 12998)));
          guard = (OOC_IR__Expression)i0;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13030)))), &_td_OOC_IR__TypeTestDesc);
          if (!i1) goto l8;
          i1 = (OOC_INT32)b;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 13099)))), OOC_IR__BuilderDesc_StartTypeGuard)),OOC_IR__BuilderDesc_StartTypeGuard)((OOC_IR__Builder)i1, (OOC_IR__TypeTest)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13126)))), &_td_OOC_IR__TypeTestDesc, 13126)), (void*)(OOC_INT32)&currentNamespace);
          i1 = (OOC_INT32)withStatm;
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 13200));
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 13210))+4);
          i2 = _check_pointer(i2, 13212);
          i3 = i;
          i4 = OOC_ARRAY_LENGTH(i2, 0);
          i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index((i3+3), i4, OOC_UINT32, 13212))*4);
          i2 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq((OOC_AST__NodeList)(_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 13222)))), &_td_OOC_AST__NodeListDesc, 13222)));
          region = (OOC_IR__StatementSeq)i2;
          i4 = (OOC_INT32)b;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 13247)))), OOC_IR__BuilderDesc_EndTypeGuard)),OOC_IR__BuilderDesc_EndTypeGuard)((OOC_IR__Builder)i4, (void*)(OOC_INT32)&currentNamespace);
          i4 = (OOC_INT32)b;
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 13357));
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 13368))+4);
          i1 = _check_pointer(i1, 13371);
          i5 = OOC_ARRAY_LENGTH(i1, 0);
          i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(i3, i5, OOC_UINT32, 13371))*4);
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 13379)))), &_td_OOC_AST__TerminalDesc, 13379)), 13388));
          i3 = (OOC_INT32)elseSeq;
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 13316)))), OOC_IR__BuilderDesc_NewWithStatm)),OOC_IR__BuilderDesc_NewWithStatm)((OOC_IR__Builder)i4, (OOC_Scanner_SymList__Symbol)i1, (OOC_IR__Expression)i0, (OOC_IR__StatementSeq)i2, (OOC_IR__StatementSeq)i3);
          _else = (OOC_IR__Statement)i0;
          i1 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__StatementSeq.baseTypes[0], 1);
          elseSeq = (OOC_IR__StatementSeq)i1;
          i1 = _check_pointer(i1, 13486);
          i2 = OOC_ARRAY_LENGTH(i1, 0);
          *(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 13486))*4) = i0;
l8:
          i0 = i;
          i0 = i0-4;
          i = i0;
          i1 = i0<0;
          if (!i1) goto l5_loop;
l12:
          i0 = (OOC_INT32)_else;
          return (OOC_IR__Statement)i0;
          ;
        }

        
        OOC_IR__Statement OOC_AST_CreateIR__CreateIR_StatementSeq_ForStatm(OOC_AST__ForStatm forStatm) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
          auto OOC_IR__Expression OOC_AST_CreateIR__CreateIR_StatementSeq_ForStatm_Step(void);
            
            OOC_IR__Expression OOC_AST_CreateIR__CreateIR_StatementSeq_ForStatm_Step(void) {
              register OOC_INT32 i0,i1;

              i0 = (OOC_INT32)forStatm;
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13741))+28);
              i1 = i1!=(OOC_INT32)0;
              if (i1) goto l3;
              return (OOC_IR__Expression)(OOC_INT32)0;
              goto l4;
l3:
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13793))+28);
              i0 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i0);
              return (OOC_IR__Expression)i0;
l4:
              _failed_function(13681); return 0;
              ;
            }


          i0 = (OOC_INT32)b;
          i1 = (OOC_INT32)forStatm;
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 13932));
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 13937));
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 13995))+4);
          i3 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Designator((OOC_AST__Node)i3);
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14050))+12);
          i4 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i4);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14110))+20);
          i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i1);
          i5 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq_ForStatm_Step();
          i6 = (OOC_INT32)forStatm;
          i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 14215))+36);
          i6 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq((OOC_AST__NodeList)i6);
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13909)))), OOC_IR__BuilderDesc_NewForStatm)),OOC_IR__BuilderDesc_NewForStatm)((OOC_IR__Builder)i0, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i3, (OOC_IR__Expression)i4, (OOC_IR__Expression)i1, (OOC_IR__Expression)i5, (OOC_IR__StatementSeq)i6);
          return (OOC_IR__Statement)i0;
          ;
        }

        
        OOC_IR__Statement OOC_AST_CreateIR__CreateIR_StatementSeq_LoopStatm(OOC_AST__LoopStatm loopStatm) {
          register OOC_INT32 i0,i1,i2;

          i0 = (OOC_INT32)b;
          i1 = (OOC_INT32)loopStatm;
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 14371));
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 14377));
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14439))+4);
          i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq((OOC_AST__NodeList)i1);
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14346)))), OOC_IR__BuilderDesc_NewLoopStatm)),OOC_IR__BuilderDesc_NewLoopStatm)((OOC_IR__Builder)i0, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__StatementSeq)i1);
          return (OOC_IR__Statement)i0;
          ;
        }

        
        OOC_IR__Statement OOC_AST_CreateIR__CreateIR_StatementSeq_TryStatm(OOC_AST__TryStatm tryStatm) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9;
          OOC_IR__CatchList catchList;
          OOC_IR__StatementSeq statmSeq;
          OOC_INT32 i;
          OOC_AST__Catch _catch;
          OOC_IR__Expression guard;
          OOC_IR__StatementSeq catchStatm;

          i0 = (OOC_INT32)tryStatm;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14749))+8);
          i1 = *(OOC_INT32*)(_check_pointer(i1, 14759));
          i1 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__CatchList.baseTypes[0], i1);
          catchList = (OOC_IR__CatchList)i1;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14807))+4);
          i2 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq((OOC_AST__NodeList)i2);
          statmSeq = (OOC_IR__StatementSeq)i2;
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14849))+8);
          i = 0;
          i3 = *(OOC_INT32*)(_check_pointer(i3, 14859));
          i4 = 0<i3;
          if (!i4) goto l12;
          i4=0;
l3_loop:
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14896))+8);
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 14906))+4);
          i5 = _check_pointer(i5, 14908);
          i6 = OOC_ARRAY_LENGTH(i5, 0);
          i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 14908))*4);
          i5 = _type_guard(i5, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 14916)))), &_td_OOC_AST__CatchDesc, 14916);
          _catch = (OOC_AST__Catch)i5;
          i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 14953))+4);
          i6 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i6);
          guard = (OOC_IR__Expression)i6;
          i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 14981))+12);
          i7 = i7==0;
          if (i7) goto l6;
          i7 = (OOC_INT32)b;
          i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 15117))+12);
          i8 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i8, 15123));
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 15084)))), OOC_IR__BuilderDesc_StartExceptionScope)),OOC_IR__BuilderDesc_StartExceptionScope)((OOC_IR__Builder)i7, (OOC_IR__Expression)i6, (OOC_Scanner_SymList__Symbol)i8, (void*)(OOC_INT32)&currentNamespace);
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 15192))+24);
          i5 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq((OOC_AST__NodeList)i5);
          catchStatm = (OOC_IR__StatementSeq)i5;
          i7 = (OOC_INT32)b;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 15217)))), OOC_IR__BuilderDesc_EndExceptionScope)),OOC_IR__BuilderDesc_EndExceptionScope)((OOC_IR__Builder)i7, (void*)(OOC_INT32)&currentNamespace);
          
          goto l7;
l6:
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 15044))+24);
          i5 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq((OOC_AST__NodeList)i5);
          catchStatm = (OOC_IR__StatementSeq)i5;
          
l7:
          i7 = _check_pointer(i1, 15300);
          i8 = OOC_ARRAY_LENGTH(i7, 0);
          i9 = (OOC_INT32)b;
          i5 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i9, 15308)))), OOC_IR__BuilderDesc_NewCatchClause)),OOC_IR__BuilderDesc_NewCatchClause)((OOC_IR__Builder)i9, (OOC_IR__Expression)i6, (OOC_IR__StatementSeq)i5);
          *(OOC_INT32*)(i7+(_check_index(i4, i8, OOC_UINT32, 15300))*4) = i5;
          i4 = i4+1;
          i = i4;
          i5 = i4<i3;
          if (i5) goto l3_loop;
l12:
          i3 = (OOC_INT32)b;
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 15394));
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 15398));
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 15373)))), OOC_IR__BuilderDesc_NewTryStatm)),OOC_IR__BuilderDesc_NewTryStatm)((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i0, (OOC_IR__StatementSeq)i2, (OOC_IR__CatchList)i1);
          return (OOC_IR__Statement)i0;
          ;
        }


      count = 0;
      i0 = (OOC_INT32)statmSeq;
      i1 = *(OOC_INT32*)(_check_pointer(i0, 15583));
      i = 0;
      i2 = 0<i1;
      if (i2) goto l3;
      i1=0;
      goto l13;
l3:
      i2=0;i3=0;
l4_loop:
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15619))+4);
      i4 = _check_pointer(i4, 15622);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i2, i5, OOC_UINT32, 15622))*4);
      i4 = i4!=0;
      if (!i4) goto l8;
      i3 = i3+1;
      count = i3;
      
l8:
      i2 = i2+2;
      i = i2;
      i4 = i2<i1;
      if (i4) goto l4_loop;
l12:
      i1=i3;
l13:
      statmSeqIR = (OOC_IR__StatementSeq)((OOC_INT32)RT0__NewObject(_td_OOC_IR__StatementSeq.baseTypes[0], i1));
      count = 0;
      i = 0;
      i0 = *(OOC_INT32*)(_check_pointer(i0, 15760));
      i1 = 0<i0;
      if (!i1) goto l75;
      i1=0;
l16_loop:
      i2 = (OOC_INT32)statmSeq;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 15796))+4);
      i3 = _check_pointer(i3, 15799);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i1, i4, OOC_UINT32, 15799))*4);
      i3 = i3!=0;
      if (!i3) goto l70;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 15838))+4);
      i2 = _check_pointer(i2, 15841);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i1 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i1, i3, OOC_UINT32, 15841))*4);
      n = (OOC_AST__Node)i1;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15862)))), &_td_OOC_AST__ProcedureCallDesc);
      if (i2) goto l65;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15951)))), &_td_OOC_AST__ReturnStatmDesc);
      if (i2) goto l63;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16019)))), &_td_OOC_AST__AssignmentDesc);
      if (i2) goto l61;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16214)))), &_td_OOC_AST__IfStatmDesc);
      if (i2) goto l59;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16278)))), &_td_OOC_AST__CaseStatmDesc);
      if (i2) goto l57;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16362)))), &_td_OOC_AST__WithStatmDesc);
      if (i2) goto l55;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16430)))), &_td_OOC_AST__RepeatStatmDesc);
      if (i2) goto l53;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16516)))), &_td_OOC_AST__WhileStatmDesc);
      if (i2) goto l51;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16586)))), &_td_OOC_AST__ForStatmDesc);
      if (i2) goto l49;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16653)))), &_td_OOC_AST__LoopStatmDesc);
      if (i2) goto l47;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16722)))), &_td_OOC_AST__ExitStatmDesc);
      if (i2) goto l45;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16803)))), &_td_OOC_AST__TryStatmDesc);
      if (i2) goto l43;
      Log__Type("++ Unknown type in StatementSeq", 32, (void*)i1);
      _assert(0u, 127, 16955);
      goto l66;
l43:
      i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq_TryStatm((OOC_AST__TryStatm)i1);
      statm = (OOC_IR__Statement)i1;
      goto l66;
l45:
      i2 = (OOC_INT32)b;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 16775));
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 16781));
      i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 16763)))), OOC_IR__BuilderDesc_NewExit)),OOC_IR__BuilderDesc_NewExit)((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i1);
      statm = (OOC_IR__Statement)i1;
      goto l66;
l47:
      i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq_LoopStatm((OOC_AST__LoopStatm)i1);
      statm = (OOC_IR__Statement)i1;
      goto l66;
l49:
      i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq_ForStatm((OOC_AST__ForStatm)i1);
      statm = (OOC_IR__Statement)i1;
      goto l66;
l51:
      i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq_WhileStatm((OOC_AST__WhileStatm)i1);
      statm = (OOC_IR__Statement)i1;
      goto l66;
l53:
      i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq_RepeatStatm((OOC_AST__RepeatStatm)i1);
      statm = (OOC_IR__Statement)i1;
      goto l66;
l55:
      i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq_WithStatm((OOC_AST__WithStatm)i1);
      statm = (OOC_IR__Statement)i1;
      goto l66;
l57:
      i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq_CaseStatm((OOC_AST__CaseStatm)i1);
      statm = (OOC_IR__Statement)i1;
      goto l66;
l59:
      i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq_IfStatm((OOC_AST__IfStatm)i1);
      statm = (OOC_IR__Statement)i1;
      goto l66;
l61:
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 16073));
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 16127));
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 16179));
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 16139))+4);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 16191))+8);
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 16085));
      i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq_Assignment((OOC_AST__Node)i2, (OOC_AST__Node)i3, (OOC_AST__Node)i1);
      statm = (OOC_IR__Statement)i1;
      goto l66;
l63:
      i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq_Return((OOC_AST__ReturnStatm)i1);
      statm = (OOC_IR__Statement)i1;
      goto l66;
l65:
      i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq_ProcedureCall((OOC_AST__ProcedureCall)i1);
      statm = (OOC_IR__Statement)i1;
l66:
      i1 = (OOC_INT32)statm;
      i2 = i1!=0;
      if (!i2) goto l70;
      i2 = (OOC_INT32)statmSeqIR;
      i2 = _check_pointer(i2, 17080);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i4 = count;
      *(OOC_INT32*)(i2+(_check_index(i4, i3, OOC_UINT32, 17080))*4) = i1;
      count = (i4+1);
l70:
      i1 = i;
      i1 = i1+2;
      i = i1;
      i2 = i1<i0;
      if (i2) goto l16_loop;
l75:
      i0 = (OOC_INT32)statmSeqIR;
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 17194)), 0);
      i2 = count;
      i1 = i2!=i1;
      if (!i1) goto l86;
      i1 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__StatementSeq.baseTypes[0], i2);
      copy = (OOC_IR__StatementSeq)i1;
      i = 0;
      i3 = 0<i2;
      if (!i3) goto l85;
      i3=0;
l80_loop:
      i4 = _check_pointer(i1, 17375);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i6 = _check_pointer(i0, 17392);
      i7 = OOC_ARRAY_LENGTH(i6, 0);
      i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i3, i7, OOC_UINT32, 17392))*4);
      *(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 17375))*4) = i6;
      i3 = i3+1;
      i = i3;
      i4 = i3<i2;
      if (i4) goto l80_loop;
l85:
      statmSeqIR = (OOC_IR__StatementSeq)i1;
l86:
      i0 = (OOC_INT32)statmSeqIR;
      return (OOC_IR__StatementSeq)i0;
      ;
    }

    
    void OOC_AST_CreateIR__CreateIR_ConstDecl(OOC_SymbolTable__ConstDecl constDecl, OOC_AST__Node constExpr) {
      register OOC_INT32 i0,i1,i2;
      OOC_IR__Expression expr;

      i0 = (OOC_INT32)b;
      i1 = (OOC_INT32)constExpr;
      i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i1);
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17620)))), OOC_IR__BuilderDesc_AssertConst)),OOC_IR__BuilderDesc_AssertConst)((OOC_IR__Builder)i0, (OOC_IR__Expression)i1);
      expr = (OOC_IR__Expression)i0;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17710))+4);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17691)))), &_td_OOC_IR__ConstDesc, 17691)), 17697))+8);
      i2 = (OOC_INT32)constDecl;
      OOC_SymbolTable__ConstDeclDesc_SetValueType((OOC_SymbolTable__ConstDecl)i2, (Object_Boxed__Object)i0, (OOC_SymbolTable__PredefType)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17721)))), &_td_OOC_SymbolTable__PredefTypeDesc, 17721)));
      return;
      ;
    }

    
    OOC_IR__Procedure OOC_AST_CreateIR__CreateIR_ProcDecl(OOC_SymbolTable__ProcDecl procDecl, OOC_AST__ProcDecl procCode) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
      OOC_SymbolTable__Namespace oldNamespace;
      OOC_SymbolTable__Item oldSourceContext;
      OOC_IR__StatementSeq statmSeq;
      OOC_Scanner_SymList__Symbol endOfBody;

      i0 = (OOC_INT32)currentNamespace;
      oldNamespace = (OOC_SymbolTable__Namespace)i0;
      i1 = (OOC_INT32)currentSourceContext;
      oldSourceContext = (OOC_SymbolTable__Item)i1;
      i2 = (OOC_INT32)procDecl;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 18167))+60);
      currentNamespace = (OOC_SymbolTable__Namespace)i3;
      currentSourceContext = (OOC_SymbolTable__Item)i2;
      i3 = (OOC_INT32)procCode;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 18238))+28);
      i4 = i4==(OOC_INT32)0;
      if (i4) goto l3;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 18264))+28);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 18270))+8);
      i4 = i4==(OOC_INT32)0;
      
      goto l5;
l3:
      i4=1u;
l5:
      if (i4) goto l7;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 18372))+28);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 18378))+8);
      i4 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq((OOC_AST__NodeList)i4);
      statmSeq = (OOC_IR__StatementSeq)i4;
      
      goto l8;
l7:
      i4 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__StatementSeq.baseTypes[0], 0);
      statmSeq = (OOC_IR__StatementSeq)i4;
      
l8:
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 18419))+28);
      i5 = i5==(OOC_INT32)0;
      if (i5) goto l11;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 18503))+28);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 18509))+12);
      i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 18514));
      endOfBody = (OOC_Scanner_SymList__Symbol)i5;
      
      goto l12;
l11:
      endOfBody = (OOC_Scanner_SymList__Symbol)(OOC_INT32)0;
      i5=(OOC_INT32)0;
l12:
      currentNamespace = (OOC_SymbolTable__Namespace)i0;
      currentSourceContext = (OOC_SymbolTable__Item)i1;
      i0 = (OOC_INT32)b;
      i1 = _check_pointer(i0, 18641);
      i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 18665));
      i6 = _check_pointer(i6, 18671);
      i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 18778))+28);
      i7 = i7!=(OOC_INT32)0;
      if (i7) goto l15;
      i3=0u;
      goto l16;
l15:
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 18833))+28);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 18838))+4);
      i3 = i3!=(OOC_INT32)0;
      
l16:
      i6 = (OOC_INT32)*(OOC_INT32*)i6;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i1)), OOC_IR__BuilderDesc_NewProcedure)),OOC_IR__BuilderDesc_NewProcedure)((OOC_IR__Builder)i0, (OOC_Scanner_SymList__Symbol)i6, (OOC_SymbolTable__ProcDecl)i2, (OOC_IR__StatementSeq)i4, (OOC_Scanner_SymList__Symbol)i5, i3);
      return (OOC_IR__Procedure)i0;
      ;
    }

    
    OOC_IR__Module OOC_AST_CreateIR__CreateIR_Module(OOC_SymbolTable__Module moduleDecl, OOC_AST__Module moduleAST) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
      OOC_AST__NodeList declSeq;
      OOC_IR__ProcedureList procList;
      OOC_INT32 count;
      OOC_IR__StatementSeq statmSeq;
      auto OOC_CHAR8 OOC_AST_CreateIR__CreateIR_Module_IsProc(OOC_SymbolTable__ProcDecl procDecl);
      auto OOC_INT32 OOC_AST_CreateIR__CreateIR_Module_CountProcs(OOC_SymbolTable__Item item);
      auto void OOC_AST_CreateIR__CreateIR_Module_TraverseProcedures(OOC_SymbolTable__Item item);
        
        OOC_CHAR8 OOC_AST_CreateIR__CreateIR_Module_IsProc(OOC_SymbolTable__ProcDecl procDecl) {
          register OOC_INT32 i0;

          i0 = (OOC_INT32)procDecl;
          i0 = *(OOC_UINT8*)((_check_pointer(i0, 19202))+49);
          return (!i0);
          ;
        }

        
        OOC_INT32 OOC_AST_CreateIR__CreateIR_Module_CountProcs(OOC_SymbolTable__Item item) {
          register OOC_INT32 i0,i1,i2;
          OOC_INT32 count;
          OOC_SymbolTable__Item nested;

          i0 = (OOC_INT32)item;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19378)))), &_td_OOC_SymbolTable__ProcDeclDesc);
          if (i1) goto l3;
          i1=0u;
          goto l5;
l3:
          i1 = OOC_AST_CreateIR__CreateIR_Module_IsProc((OOC_SymbolTable__ProcDecl)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19414)))), &_td_OOC_SymbolTable__ProcDeclDesc, 19414)));
          
l5:
          if (i1) goto l7;
          count = 0;
          i1=0;
          goto l8;
l7:
          count = 1;
          i1=1;
l8:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19530))+8);
          nested = (OOC_SymbolTable__Item)i0;
          i2 = i0!=(OOC_INT32)0;
          if (i2) goto l11;
          i0=i1;
          goto l17;
l11:
          {register OOC_INT32 h0=i0;i0=i1;i1=h0;}
l12_loop:
          i2 = OOC_AST_CreateIR__CreateIR_Module_CountProcs((OOC_SymbolTable__Item)i1);
          i0 = i0+i2;
          count = i0;
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 19647));
          nested = (OOC_SymbolTable__Item)i1;
          i2 = i1!=(OOC_INT32)0;
          if (i2) goto l12_loop;
l17:
          return i0;
          ;
        }

        
        void OOC_AST_CreateIR__CreateIR_Module_TraverseProcedures(OOC_SymbolTable__Item item) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5;
          OOC_SymbolTable__Item nested;

          i0 = (OOC_INT32)item;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 19833)))), &_td_OOC_SymbolTable__ProcDeclDesc);
          if (!i1) goto l6;
          i1 = OOC_AST_CreateIR__CreateIR_Module_IsProc((OOC_SymbolTable__ProcDecl)i0);
          if (!i1) goto l6;
          i1 = (OOC_INT32)procList;
          i1 = _check_pointer(i1, 19903);
          i2 = OOC_ARRAY_LENGTH(i1, 0);
          i3 = count;
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19934))+72);
          i4 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_ProcDecl((OOC_SymbolTable__ProcDecl)i0, (OOC_AST__ProcDecl)(_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 19947)))), &_td_OOC_AST__ProcDeclDesc, 19947)));
          i5 = count;
          *(OOC_INT32*)(i1+(_check_index(i3, i2, OOC_UINT32, 19903))*4) = i4;
          count = (i5+1);
l6:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20096))+8);
          nested = (OOC_SymbolTable__Item)i0;
          i1 = i0!=(OOC_INT32)0;
          if (!i1) goto l14;
l9_loop:
          OOC_AST_CreateIR__CreateIR_Module_TraverseProcedures((OOC_SymbolTable__Item)i0);
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 20208));
          nested = (OOC_SymbolTable__Item)i0;
          i1 = i0!=(OOC_INT32)0;
          if (i1) goto l9_loop;
l14:
          return;
          ;
        }


      i0 = (OOC_INT32)moduleAST;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20305))+20);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 20311));
      declSeq = (OOC_AST__NodeList)i0;
      i0 = (OOC_INT32)moduleDecl;
      i0 = OOC_AST_CreateIR__CreateIR_Module_CountProcs((OOC_SymbolTable__Item)i0);
      procList = (OOC_IR__ProcedureList)((OOC_INT32)RT0__NewObject(_td_OOC_IR__ProcedureList.baseTypes[0], i0));
      count = 0;
      i0 = (OOC_INT32)moduleDecl;
      OOC_AST_CreateIR__CreateIR_Module_TraverseProcedures((OOC_SymbolTable__Item)i0);
      i0 = (OOC_INT32)moduleAST;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20453))+20);
      i1 = i1==0;
      if (i1) goto l3;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20480))+20);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 20486))+8);
      i1 = i1==0;
      
      goto l5;
l3:
      i1=1u;
l5:
      if (i1) goto l7;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20589))+20);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 20595))+8);
      i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq((OOC_AST__NodeList)i1);
      statmSeq = (OOC_IR__StatementSeq)i1;
      
      goto l8;
l7:
      i1 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__StatementSeq.baseTypes[0], 0);
      statmSeq = (OOC_IR__StatementSeq)i1;
      
l8:
      i2 = (OOC_INT32)b;
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 20661));
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20794))+20);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 20800))+12);
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 20669));
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 20805));
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20685))+28);
      i5 = (OOC_INT32)moduleDecl;
      i6 = (OOC_INT32)procList;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 20639)))), OOC_IR__BuilderDesc_NewModule)),OOC_IR__BuilderDesc_NewModule)((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i3, (OOC_Scanner_InputBuffer__CharArray)i0, (OOC_SymbolTable__Module)i5, (OOC_IR__ProcedureList)i6, (OOC_IR__StatementSeq)i1, (OOC_Scanner_SymList__Symbol)i4);
      return (OOC_IR__Module)i0;
      ;
    }

    
    void OOC_AST_CreateIR__CreateIR_TranslateEmbeddedExpr(OOC_SymbolTable__Item item) {
      register OOC_INT32 i0,i1,i2;
      OOC_IR__Expression expr;
      OOC_SymbolTable__Namespace oldNamespace;
      OOC_SymbolTable__Item oldSourceContext;
      auto void OOC_AST_CreateIR__CreateIR_TranslateEmbeddedExpr_TraverseNested(OOC_SymbolTable__Item item);
        
        void OOC_AST_CreateIR__CreateIR_TranslateEmbeddedExpr_TraverseNested(OOC_SymbolTable__Item item) {
          register OOC_INT32 i0,i1;
          OOC_SymbolTable__Item nested;

          i0 = (OOC_INT32)item;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21448))+8);
          nested = (OOC_SymbolTable__Item)i0;
          i1 = i0!=(OOC_INT32)0;
          if (!i1) goto l8;
l3_loop:
          OOC_AST_CreateIR__CreateIR_TranslateEmbeddedExpr((OOC_SymbolTable__Item)i0);
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 21563));
          nested = (OOC_SymbolTable__Item)i0;
          i1 = i0!=(OOC_INT32)0;
          if (i1) goto l3_loop;
l8:
          return;
          ;
        }


      i0 = (OOC_INT32)item;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21645)))), &_td_OOC_SymbolTable__RecordDesc);
      if (!i1) goto l3;
      OOC_AST_CreateIR__CreateIR_TranslateEmbeddedExpr_TraverseNested((OOC_SymbolTable__Item)i0);
l3:
      i0 = (OOC_INT32)item;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21907)))), &_td_OOC_SymbolTable__ArrayDesc);
      if (i1) goto l9;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22235)))), &_td_OOC_SymbolTable__ConstDeclDesc);
      if (!i1) goto l17;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22283))+56);
      OOC_AST_CreateIR__CreateIR_ConstDecl((OOC_SymbolTable__ConstDecl)i0, (OOC_AST__Node)i1);
      goto l17;
l9:
      i1 = *(OOC_UINT8*)((_check_pointer(i0, 21938))+40);
      i1 = !i1;
      if (!i1) goto l17;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21985))+56);
      i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i1);
      expr = (OOC_IR__Expression)i1;
      i2 = (OOC_INT32)b;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 22022))+20);
      i2 = i1==i2;
      if (i2) goto l14;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 22152)))), &_td_OOC_IR__ConstDesc, 22152)), 22158))+8);
      i1 = Object_BigInt__BigIntDesc_ToLongInt((Object_BigInt__BigInt)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 22172)))), &_td_Object_BigInt__BigIntDesc, 22172)));
      OOC_SymbolTable__ArrayDesc_SetLength((OOC_SymbolTable__Array)i0, i1);
      goto l17;
l14:
      OOC_SymbolTable__ArrayDesc_SetLength((OOC_SymbolTable__Array)i0, 1);
l17:
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22358)))), &_td_OOC_SymbolTable__TypeDesc);
      if (!i1) goto l23;
      i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22390)))), &_td_OOC_SymbolTable__TypeNameDesc));
      if (!i1) goto l23;
      OOC_SymbolTable_TypeRules__AllocateType((OOC_SymbolTable__Type)i0);
l23:
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22512)))), &_td_OOC_SymbolTable__ProcDeclDesc);
      if (i1) goto l29;
      i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22868)))), &_td_OOC_SymbolTable__RecordDesc));
      if (!i1) goto l30;
      OOC_AST_CreateIR__CreateIR_TranslateEmbeddedExpr_TraverseNested((OOC_SymbolTable__Item)i0);
      goto l30;
l29:
      i1 = (OOC_INT32)currentNamespace;
      oldNamespace = (OOC_SymbolTable__Namespace)i1;
      i1 = (OOC_INT32)currentSourceContext;
      oldSourceContext = (OOC_SymbolTable__Item)i1;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22654))+60);
      currentNamespace = (OOC_SymbolTable__Namespace)i1;
      currentSourceContext = (OOC_SymbolTable__Item)i0;
      OOC_AST_CreateIR__CreateIR_TranslateEmbeddedExpr_TraverseNested((OOC_SymbolTable__Item)i0);
      i0 = (OOC_INT32)oldNamespace;
      currentNamespace = (OOC_SymbolTable__Namespace)i0;
      i0 = (OOC_INT32)oldSourceContext;
      currentSourceContext = (OOC_SymbolTable__Item)i0;
l30:
      return;
      ;
    }


  i0 = (OOC_INT32)symTab;
  currentSourceContext = (OOC_SymbolTable__Item)i0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23053))+48);
  currentNamespace = (OOC_SymbolTable__Namespace)i1;
  OOC_AST_CreateIR__CreateIR_TranslateEmbeddedExpr((OOC_SymbolTable__Item)i0);
  i0 = (OOC_INT32)module;
  i1 = (OOC_INT32)symTab;
  i0 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Module((OOC_SymbolTable__Module)i1, (OOC_AST__Module)i0);
  return (OOC_IR__Module)i0;
  ;
}

void OOC_OOC_AST_CreateIR_init(void) {

  return;
  ;
}

/* --- */
