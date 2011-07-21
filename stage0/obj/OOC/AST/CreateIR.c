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
  auto OOC_IR__Expression OOC_AST_CreateIR__CreateIR_Range(OOC_IR__Expression type, OOC_AST__Node expr, OOC_CHAR8 isSet);
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
      register OOC_INT32 i0,i1,i2,i3,i4,i5;
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
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 2140))+24);
          i3 = i1==i3;
          if (i3) goto l5;
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2359))+8);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2281))+4);
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2285));
          i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 2371)))), &_td_OOC_AST__TerminalDesc, 2371)), 2380));
          i4 = (OOC_INT32)currentSourceContext;
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 2262)))), OOC_IR__BuilderDesc_NewSelect)),OOC_IR__BuilderDesc_NewSelect)((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i0, (OOC_IR__Expression)i1, (OOC_SymbolTable__Item)i4, (OOC_Scanner_SymList__Symbol)i3);
          return (OOC_IR__Expression)i0;
          goto l8;
l5:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 2177))+24);
          return (OOC_IR__Expression)i0;
          goto l8;
l7:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2010))+8);
          i2 = (OOC_INT32)b;
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
      Log__Type((OOC_CHAR8*)"++ Unknown type in Designator", 30, (void*)i0);
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
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3364));
      i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Designator((OOC_AST__Node)i1);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3335))+4);
      i2 = (OOC_INT32)b;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3339));
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 3317)))), OOC_IR__BuilderDesc_NewDeref)),OOC_IR__BuilderDesc_NewDeref)((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i0, (OOC_IR__Expression)i1);
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
      i3=i2;i2=i1;i1=0;
l25_loop:
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2888))+8);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 2897))+4);
      i4 = _check_pointer(i4, 2900);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i1, i5, OOC_UINT32, 2900))*4);
      i4 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i4);
      i5 = (OOC_INT32)b;
      i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 2822)))), OOC_IR__BuilderDesc_NewIndex)),OOC_IR__BuilderDesc_NewIndex)((OOC_IR__Builder)i5, (OOC_Scanner_SymList__Symbol)i3, (OOC_IR__Expression)i2, (OOC_IR__Expression)i4);
      left = (OOC_IR__Expression)i2;
      i1 = i1+1;
      i = i1;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2950))+8);
      i4 = *(OOC_INT32*)(_check_pointer(i4, 2959));
      i4 = i1<i4;
      if (!i4) goto l29;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2996))+8);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 3005))+4);
      i3 = _check_pointer(i3, 3008);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i1, i4, OOC_UINT32, 3008))*4);
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 3016)))), &_td_OOC_AST__TerminalDesc, 3016)), 3025));
      sym = (OOC_Scanner_SymList__Symbol)i3;
      
l29:
      i1 = i1+1;
      i = i1;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2784))+8);
      i4 = *(OOC_INT32*)(_check_pointer(i4, 2793));
      i4 = i1<i4;
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

    
    OOC_IR__Expression OOC_AST_CreateIR__CreateIR_Range(OOC_IR__Expression type, OOC_AST__Node expr, OOC_CHAR8 isSet) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
      OOC_IR__Expression e;

      i0 = (OOC_INT32)expr;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3887)))), &_td_OOC_AST__OperatorDesc);
      if (!i1) goto l6;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3919))+4);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 3923));
      i1 = *(OOC_INT8*)((_check_pointer(i1, 3928))+4);
      i1 = i1==21;
      if (!i1) goto l6;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4056))+8);
      i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i1);
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4039));
      i2 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i2);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3986))+4);
      i4 = (OOC_INT32)b;
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 3989));
      i5 = isSet;
      i6 = (OOC_INT32)type;
      i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 3969)))), OOC_IR__BuilderDesc_NewSetRange)),OOC_IR__BuilderDesc_NewSetRange)((OOC_IR__Builder)i4, (OOC_Scanner_SymList__Symbol)i3, (OOC_IR__Expression)i6, (OOC_IR__Expression)i2, (OOC_IR__Expression)i1, i5);
      return (OOC_IR__Expression)i1;
l6:
      i0 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i0);
      e = (OOC_IR__Expression)i0;
      i1 = (OOC_INT32)b;
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4149));
      i3 = isSet;
      i4 = (OOC_INT32)type;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4135)))), OOC_IR__BuilderDesc_NewSetRange)),OOC_IR__BuilderDesc_NewSetRange)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i4, (OOC_IR__Expression)i0, (OOC_IR__Expression)i0, i3);
      return (OOC_IR__Expression)i0;
      ;
    }

    
    OOC_IR__Expression OOC_AST_CreateIR__CreateIR_SetConstruct(OOC_AST__Set sc) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
      OOC_IR__Expression type;
      OOC_INT32 len;
      OOC_IR__Expression result;
      OOC_INT32 i;

      i0 = (OOC_INT32)sc;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4324));
      i1 = i1==0;
      if (i1) goto l3;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4397));
      i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Designator((OOC_AST__Node)i1);
      type = (OOC_IR__Expression)i1;
      
      goto l4;
l3:
      type = (OOC_IR__Expression)0;
      i1=0;
l4:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4424))+8);
      i2 = *(OOC_INT32*)(_check_pointer(i2, 4437));
      i2 = i2==0;
      if (i2) goto l16;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4543))+8);
      i2 = *(OOC_INT32*)(_check_pointer(i2, 4555));
      i2 = (i2+1)>>1;
      len = i2;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4601))+8);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 4613))+4);
      i3 = _check_pointer(i3, 4615);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(0, i4, OOC_UINT8, 4615))*4);
      i3 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Range((OOC_IR__Expression)i1, (OOC_AST__Node)i3, 1u);
      result = (OOC_IR__Expression)i3;
      i = 1;
      i4 = 1<i2;
      if (i4) goto l9;
      i0=i3;
      goto l15;
l9:
      i4=i3;i3=1;
l10_loop:
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4761))+8);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 4773))+4);
      i5 = _check_pointer(i5, 4775);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index((i3*2), i6, OOC_UINT32, 4775))*4);
      i5 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Range((OOC_IR__Expression)i1, (OOC_AST__Node)i5, 1u);
      i6 = (OOC_INT32)b;
      i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 4691));
      i4 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 4675)))), OOC_IR__BuilderDesc_NewSetOp)),OOC_IR__BuilderDesc_NewSetOp)((OOC_IR__Builder)i6, (OOC_Scanner_SymList__Symbol)i7, 6, (OOC_IR__Expression)i4, (OOC_IR__Expression)i5);
      result = (OOC_IR__Expression)i4;
      i3 = i3+1;
      i = i3;
      i5 = i3<i2;
      if (i5) goto l10_loop;
l14:
      i0=i4;
l15:
      return (OOC_IR__Expression)i0;
      goto l17;
l16:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4482))+4);
      i2 = (OOC_INT32)b;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4489));
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 4467)))), OOC_IR__BuilderDesc_NewSetRange)),OOC_IR__BuilderDesc_NewSetRange)((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i0, (OOC_IR__Expression)i1, (OOC_IR__Expression)0, (OOC_IR__Expression)0, 1u);
      return (OOC_IR__Expression)i0;
l17:
      _failed_function(4201); return 0;
      ;
    }

    
    OOC_IR__Expression OOC_AST_CreateIR__CreateIR_QualType(OOC_AST__QualType qualType) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
      OOC_IR__Expression type;
      OOC_IR__ExpressionList arguments;
      OOC_INT32 i;
      OOC_AST__Node n;

      i0 = (OOC_INT32)qualType;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5064));
      i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Designator((OOC_AST__Node)i1);
      type = (OOC_IR__Expression)i1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5107))+8);
      i2 = *(OOC_INT32*)(_check_pointer(i2, 5117));
      i2 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__ExpressionList.baseTypes[0], ((i2+1)>>1));
      arguments = (OOC_IR__ExpressionList)i2;
      i = 0;
      i3 = OOC_ARRAY_LENGTH((_check_pointer(i2, 5166)), 0);
      i4 = 0<i3;
      if (!i4) goto l12;
      i4=0;
l3_loop:
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5195))+8);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 5205))+4);
      i5 = _check_pointer(i5, 5207);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index((i4*2), i6, OOC_UINT32, 5207))*4);
      n = (OOC_AST__Node)i5;
      i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 5228)))), &_td_OOC_AST__QualTypeDesc);
      if (i6) goto l6;
      i6 = _check_pointer(i2, 5317);
      i7 = OOC_ARRAY_LENGTH(i6, 0);
      i5 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Designator((OOC_AST__Node)i5);
      *(OOC_INT32*)(i6+(_check_index(i4, i7, OOC_UINT32, 5317))*4) = i5;
      goto l7;
l6:
      i6 = _check_pointer(i2, 5265);
      i7 = OOC_ARRAY_LENGTH(i6, 0);
      i5 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_QualType((OOC_AST__QualType)i5);
      *(OOC_INT32*)(i6+(_check_index(i4, i7, OOC_UINT32, 5265))*4) = i5;
l7:
      i4 = i4+1;
      i = i4;
      i5 = i4<i3;
      if (i5) goto l3_loop;
l12:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5441))+12);
      i3 = (OOC_INT32)b;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5448));
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 5403)))), OOC_IR__BuilderDesc_NewQualType)),OOC_IR__BuilderDesc_NewQualType)((OOC_IR__Builder)i3, (OOC_IR__Expression)i1, (OOC_IR__ExpressionList)i2, (OOC_Scanner_SymList__Symbol)i0);
      return (OOC_IR__Expression)i0;
      ;
    }

    
    OOC_IR__Expression OOC_AST_CreateIR__CreateIR_Expr(OOC_AST__Node expr) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_IR__Expression res;
      OOC_IR__Expression left;
      OOC_IR__Expression right;

      i0 = (OOC_INT32)expr;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5599)))), &_td_OOC_AST__TerminalDesc);
      if (i1) goto l43;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6290)))), &_td_OOC_AST__FactorDesc);
      if (i1) goto l41;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6364)))), &_td_OOC_AST__ArrayIndexDesc);
      if (i1) goto l39;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6467)))), &_td_OOC_AST__OperatorDesc);
      if (i1) goto l21;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7031)))), &_td_OOC_AST__SetDesc);
      if (i1) goto l19;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7092)))), &_td_OOC_AST__FunctionCallDesc);
      if (i1) goto l17;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7170)))), &_td_OOC_AST__QualTypeDesc);
      if (i1) goto l15;
      Log__Type((OOC_CHAR8*)"++ Unknown expression class in Expr", 36, (void*)i0);
      _assert(0u, 127, 7310);
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
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6501))+4);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 6505));
      i1 = *(OOC_INT8*)((_check_pointer(i1, 6510))+4);
      i1 = i1==18;
      if (i1) goto l24;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6551))+4);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 6555));
      i1 = *(OOC_INT8*)((_check_pointer(i1, 6560))+4);
      i1 = i1==17;
      
      goto l26;
l24:
      i1=1u;
l26:
      if (i1) goto l36;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6699));
      i1 = i1!=(OOC_INT32)0;
      if (i1) goto l30;
      left = (OOC_IR__Expression)(OOC_INT32)0;
      i1=(OOC_INT32)0;
      goto l31;
l30:
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6748));
      i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i1);
      left = (OOC_IR__Expression)i1;
      
l31:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6828))+8);
      i2 = i2!=(OOC_INT32)0;
      if (i2) goto l34;
      right = (OOC_IR__Expression)(OOC_INT32)0;
      i2=(OOC_INT32)0;
      goto l35;
l34:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6879))+8);
      i2 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i2);
      right = (OOC_IR__Expression)i2;
      
l35:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6980))+4);
      i3 = (OOC_INT32)b;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6984));
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 6961)))), OOC_IR__BuilderDesc_NewOperator)),OOC_IR__BuilderDesc_NewOperator)((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i0, (OOC_IR__Expression)i1, (OOC_IR__Expression)i2);
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
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6331))+4);
      i0 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i0);
      res = (OOC_IR__Expression)i0;
      goto l55;
l43:
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5634));
      i1 = *(OOC_INT8*)((_check_pointer(i1, 5639))+4);
      switch (i1) {
      case 45:
        i0 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Designator((OOC_AST__Node)i0);
        res = (OOC_IR__Expression)i0;
        goto l55;
      case 43:
      case 44:
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5798));
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5776)))), OOC_IR__BuilderDesc_NewStringConst)),OOC_IR__BuilderDesc_NewStringConst)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i0);
        res = (OOC_IR__Expression)i0;
        goto l55;
      case 37:
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5871));
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5850)))), OOC_IR__BuilderDesc_NewIntConst10)),OOC_IR__BuilderDesc_NewIntConst10)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i0);
        res = (OOC_IR__Expression)i0;
        goto l55;
      case 38:
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5944));
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5923)))), OOC_IR__BuilderDesc_NewIntConst16)),OOC_IR__BuilderDesc_NewIntConst16)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i0);
        res = (OOC_IR__Expression)i0;
        goto l55;
      case 39:
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6019));
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5997)))), OOC_IR__BuilderDesc_NewCharConst16)),OOC_IR__BuilderDesc_NewCharConst16)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i0);
        res = (OOC_IR__Expression)i0;
        goto l55;
      case 40:
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6093));
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6073)))), OOC_IR__BuilderDesc_NewRealConst)),OOC_IR__BuilderDesc_NewRealConst)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i0, 8);
        res = (OOC_IR__Expression)i0;
        goto l55;
      case 41:
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6180));
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6160)))), OOC_IR__BuilderDesc_NewRealConst)),OOC_IR__BuilderDesc_NewRealConst)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i0, 9);
        res = (OOC_IR__Expression)i0;
        goto l55;
      case 42:
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6258));
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6244)))), OOC_IR__BuilderDesc_NewNil)),OOC_IR__BuilderDesc_NewNil)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i0);
        res = (OOC_IR__Expression)i0;
        goto l55;
      default:
        _failed_case(i1, 5625);
        goto l55;
      }
l55:
      i0 = (OOC_INT32)b;
      i1 = (OOC_INT32)res;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7350)))), OOC_IR__BuilderDesc_Fold)),OOC_IR__BuilderDesc_Fold)((OOC_IR__Builder)i0, (OOC_IR__Expression)i1);
      return (OOC_IR__Expression)i0;
      ;
    }

    
    OOC_IR__Expression OOC_AST_CreateIR__CreateIR_FunctionCall(OOC_AST__FunctionCall call, OOC_CHAR8 isProcCall) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
      OOC_IR__Expression design;
      OOC_IR__ExpressionList arguments;
      OOC_INT32 i;

      i0 = (OOC_INT32)call;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7626));
      i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Designator((OOC_AST__Node)i1);
      design = (OOC_IR__Expression)i1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7664))+8);
      i2 = *(OOC_INT32*)(_check_pointer(i2, 7675));
      i2 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__ExpressionList.baseTypes[0], ((i2+1)>>1));
      arguments = (OOC_IR__ExpressionList)i2;
      i = 0;
      i3 = OOC_ARRAY_LENGTH((_check_pointer(i2, 7726)), 0);
      i4 = 0<i3;
      if (!i4) goto l8;
      i4=0;
l3_loop:
      i5 = _check_pointer(i2, 7751);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7768))+8);
      i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i7, 7779))+4);
      i7 = _check_pointer(i7, 7782);
      i8 = OOC_ARRAY_LENGTH(i7, 0);
      i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index((i4*2), i8, OOC_UINT32, 7782))*4);
      i7 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i7);
      *(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 7751))*4) = i7;
      i4 = i4+1;
      i = i4;
      i5 = i4<i3;
      if (i5) goto l3_loop;
l8:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7904))+12);
      i3 = (OOC_INT32)b;
      i4 = isProcCall;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7911));
      i5 = (OOC_INT32)currentSourceContext;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 7814)))), OOC_IR__BuilderDesc_NewCall)),OOC_IR__BuilderDesc_NewCall)((OOC_IR__Builder)i3, (OOC_IR__Expression)i1, (OOC_IR__ExpressionList)i2, (!i4), (OOC_SymbolTable__Item)i5, (OOC_Scanner_SymList__Symbol)i0);
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
      auto OOC_IR__Statement OOC_AST_CreateIR__CreateIR_StatementSeq_IterateStatm(OOC_AST__IterateStatm iterStatm);
      auto OOC_IR__Statement OOC_AST_CreateIR__CreateIR_StatementSeq_LoopStatm(OOC_AST__LoopStatm loopStatm);
      auto OOC_IR__Statement OOC_AST_CreateIR__CreateIR_StatementSeq_TryStatm(OOC_AST__TryStatm tryStatm);
        
        OOC_IR__Statement OOC_AST_CreateIR__CreateIR_StatementSeq_ProcedureCall(OOC_AST__ProcedureCall call) {
          register OOC_INT32 i0,i1,i2,i3,i4;
          OOC_IR__Expression expr;
          OOC_IR__ExpressionList arguments;
          OOC_IR__Expression design;

          i0 = (OOC_INT32)call;
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 8312));
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8319)))), &_td_OOC_AST__FunctionCallDesc);
          if (i1) goto l3;
          i1 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__ExpressionList.baseTypes[0], 0);
          arguments = (OOC_IR__ExpressionList)i1;
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 8554));
          i0 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Designator((OOC_AST__Node)i0);
          design = (OOC_IR__Expression)i0;
          i2 = (OOC_INT32)b;
          i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 8673));
          i4 = (OOC_INT32)currentSourceContext;
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 8582)))), OOC_IR__BuilderDesc_NewCall)),OOC_IR__BuilderDesc_NewCall)((OOC_IR__Builder)i2, (OOC_IR__Expression)i0, (OOC_IR__ExpressionList)i1, 0u, (OOC_SymbolTable__Item)i4, (OOC_Scanner_SymList__Symbol)i3);
          expr = (OOC_IR__Expression)i0;
          
          goto l4;
l3:
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 8381));
          i0 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_FunctionCall((OOC_AST__FunctionCall)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8392)))), &_td_OOC_AST__FunctionCallDesc, 8392)), 1u);
          expr = (OOC_IR__Expression)i0;
          
l4:
          i1 = i0!=(OOC_INT32)0;
          if (i1) goto l7;
          i1=0u;
          goto l9;
l7:
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8725)))), &_td_OOC_IR__StatementDesc);
          
l9:
          if (i1) goto l11;
          return (OOC_IR__Statement)(OOC_INT32)0;
          goto l12;
l11:
          return (OOC_IR__Statement)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8772)))), &_td_OOC_IR__StatementDesc, 8772));
l12:
          _failed_function(8144); return 0;
          ;
        }

        
        OOC_IR__Statement OOC_AST_CreateIR__CreateIR_StatementSeq_Return(OOC_AST__ReturnStatm _return) {
          register OOC_INT32 i0,i1,i2;

          i0 = (OOC_INT32)_return;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9008))+4);
          i1 = i1==(OOC_INT32)0;
          if (i1) goto l3;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9192))+4);
          i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9134));
          i2 = (OOC_INT32)b;
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9142));
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 9115)))), OOC_IR__BuilderDesc_NewReturn)),OOC_IR__BuilderDesc_NewReturn)((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i0, (OOC_IR__Expression)i1);
          return (OOC_IR__Statement)i0;
          goto l4;
l3:
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9064));
          i1 = (OOC_INT32)b;
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9072));
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9045)))), OOC_IR__BuilderDesc_NewReturn)),OOC_IR__BuilderDesc_NewReturn)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i0, (OOC_IR__Expression)(OOC_INT32)0);
          return (OOC_IR__Statement)i0;
l4:
          _failed_function(8930); return 0;
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
          i2 = (OOC_INT32)op;
          i3 = (OOC_INT32)b;
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 9485)))), &_td_OOC_AST__TerminalDesc, 9485)), 9494));
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 9461)))), OOC_IR__BuilderDesc_NewAssignment)),OOC_IR__BuilderDesc_NewAssignment)((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i0, (OOC_IR__Expression)i1);
          return (OOC_IR__Statement)i0;
          ;
        }

        
        OOC_IR__Statement OOC_AST_CreateIR__CreateIR_StatementSeq_IfStatm(OOC_AST__IfStatm ifStatm) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
          OOC_IR__StatementSeq elseSeq;
          OOC_INT32 i;
          OOC_IR__Statement _else;

          i0 = (OOC_INT32)ifStatm;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9732))+4);
          i1 = i1!=(OOC_INT32)0;
          if (i1) goto l3;
          elseSeq = (OOC_IR__StatementSeq)(OOC_INT32)0;
          i1=(OOC_INT32)0;
          goto l4;
l3:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9793))+8);
          i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq((OOC_AST__NodeList)i1);
          elseSeq = (OOC_IR__StatementSeq)i1;
          
l4:
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9880));
          i2 = *(OOC_INT32*)(_check_pointer(i2, 9891));
          i2 = i2-4;
          i = i2;
          
l5_loop:
          i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10093));
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 10104))+4);
          i3 = _check_pointer(i3, 10107);
          i4 = OOC_ARRAY_LENGTH(i3, 0);
          i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index((i2+3), i4, OOC_UINT32, 10107))*4);
          i3 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq((OOC_AST__NodeList)(_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 10117)))), &_td_OOC_AST__NodeListDesc, 10117)));
          i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10035));
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 10046))+4);
          i4 = _check_pointer(i4, 10049);
          i5 = OOC_ARRAY_LENGTH(i4, 0);
          i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index((i2+1), i5, OOC_UINT32, 10049))*4);
          i4 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i4);
          i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9969));
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 9980))+4);
          i5 = _check_pointer(i5, 9983);
          i6 = OOC_ARRAY_LENGTH(i5, 0);
          i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i2, i6, OOC_UINT32, 9983))*4);
          i6 = (OOC_INT32)b;
          i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i5, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 9991)))), &_td_OOC_AST__TerminalDesc, 9991)), 10000));
          i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 9934)))), OOC_IR__BuilderDesc_NewIfStatm)),OOC_IR__BuilderDesc_NewIfStatm)((OOC_IR__Builder)i6, (OOC_Scanner_SymList__Symbol)i5, (OOC_IR__Expression)i4, (OOC_IR__StatementSeq)i3, (OOC_IR__StatementSeq)i1);
          _else = (OOC_IR__Statement)i1;
          i3 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__StatementSeq.baseTypes[0], 1);
          elseSeq = (OOC_IR__StatementSeq)i3;
          i4 = _check_pointer(i3, 10199);
          i5 = OOC_ARRAY_LENGTH(i4, 0);
          *(OOC_INT32*)(i4+(_check_index(0, i5, OOC_UINT8, 10199))*4) = i1;
          i2 = i2-4;
          i = i2;
          i4 = i2<0;
          if (i4) goto l9;
          i1=i3;
          goto l5_loop;
l9:
          return (OOC_IR__Statement)i1;
          ;
        }

        
        OOC_IR__Statement OOC_AST_CreateIR__CreateIR_StatementSeq_CaseStatm(OOC_AST__CaseStatm caseStatm) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9;
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
              i1 = *(OOC_INT32*)(_check_pointer(i0, 10677));
              i1 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__CaseLabels.baseTypes[0], ((i1+1)>>1));
              setRanges = (OOC_IR__CaseLabels)i1;
              i = 0;
              i2 = *(OOC_INT32*)(_check_pointer(i0, 10724));
              i3 = 0<i2;
              if (!i3) goto l8;
              i3=0;
l3_loop:
              i4 = _check_pointer(i1, 10761);
              i5 = OOC_ARRAY_LENGTH(i4, 0);
              i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10792))+4);
              i6 = _check_pointer(i6, 10795);
              i7 = OOC_ARRAY_LENGTH(i6, 0);
              i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i3, i7, OOC_UINT32, 10795))*4);
              i6 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Range((OOC_IR__Expression)0, (OOC_AST__Node)i6, 0u);
              *(OOC_INT32*)(i4+(_check_index((i3>>1), i5, OOC_UINT32, 10761))*4) = i6;
              i3 = i3+2;
              i = i3;
              i4 = i3<i2;
              if (i4) goto l3_loop;
l8:
              return (OOC_IR__CaseLabels)i1;
              ;
            }


          i0 = (OOC_INT32)caseStatm;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10923))+4);
          i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i1);
          select = (OOC_IR__Expression)i1;
          count = 0;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11023))+12);
          i1 = *(OOC_INT32*)(_check_pointer(i1, 11033));
          i = 0;
          i2 = 0<i1;
          if (i2) goto l3;
          i1=0;
          goto l13;
l3:
          i2=0;i3=0;
l4_loop:
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11072))+12);
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 11082))+4);
          i4 = _check_pointer(i4, 11085);
          i5 = OOC_ARRAY_LENGTH(i4, 0);
          i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i2, i5, OOC_UINT32, 11085))*4);
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
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11284))+12);
          i = 0;
          i1 = *(OOC_INT32*)(_check_pointer(i1, 11294));
          i2 = 0<i1;
          if (!i2) goto l26;
          i2=0;i3=0;
l17_loop:
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11333))+12);
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 11343))+4);
          i4 = _check_pointer(i4, 11346);
          i5 = OOC_ARRAY_LENGTH(i4, 0);
          i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i2, i5, OOC_UINT32, 11346))*4);
          i4 = i4!=0;
          if (i4) goto l20;
          {register OOC_INT32 h0=i2;i2=i3;i3=h0;}
          goto l21;
l20:
          i4 = (OOC_INT32)caseList;
          i4 = _check_pointer(i4, 11382);
          i5 = OOC_ARRAY_LENGTH(i4, 0);
          i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11570))+12);
          i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 11580))+4);
          i6 = _check_pointer(i6, 11583);
          i7 = OOC_ARRAY_LENGTH(i6, 0);
          i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index((i2+2), i7, OOC_UINT32, 11583))*4);
          i6 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq((OOC_AST__NodeList)(_type_guard(i6, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 11593)))), &_td_OOC_AST__NodeListDesc, 11593)));
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11499))+12);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11509))+4);
          i0 = _check_pointer(i0, 11512);
          i7 = OOC_ARRAY_LENGTH(i0, 0);
          i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(i2, i7, OOC_UINT32, 11512))*4);
          i0 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq_CaseStatm_Labels((OOC_AST__NodeList)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11520)))), &_td_OOC_AST__NodeListDesc, 11520)));
          i2 = (OOC_INT32)caseStatm;
          i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 11428))+12);
          i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i7, 11438))+4);
          i7 = _check_pointer(i7, 11441);
          i8 = i;
          i9 = OOC_ARRAY_LENGTH(i7, 0);
          i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index((i8+1), i9, OOC_UINT32, 11441))*4);
          i9 = (OOC_INT32)b;
          i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i7, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 11451)))), &_td_OOC_AST__TerminalDesc, 11451)), 11460));
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i9, 11394)))), OOC_IR__BuilderDesc_NewCase)),OOC_IR__BuilderDesc_NewCase)((OOC_IR__Builder)i9, (OOC_Scanner_SymList__Symbol)i7, (OOC_IR__CaseLabels)i0, (OOC_IR__StatementSeq)i6);
          i6 = count;
          *(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 11382))*4) = i0;
          i0 = i6+1;
          count = i0;
          i3=i8;{register OOC_INT32 h0=i0;i0=i2;i2=h0;}
l21:
          i3 = i3+4;
          i = i3;
          i4 = i3<i1;
          if (!i4) goto l26;
          {register OOC_INT32 h0=i2;i2=i3;i3=h0;}
          goto l17_loop;
l26:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11680))+16);
          i1 = i1!=0;
          if (i1) goto l29;
          elseSeq = (OOC_IR__StatementSeq)0;
          i1=0;
          goto l30;
l29:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11743))+20);
          i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq((OOC_AST__NodeList)i1);
          elseSeq = (OOC_IR__StatementSeq)i1;
          
l30:
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 11851));
          i2 = (OOC_INT32)b;
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 11857));
          i3 = (OOC_INT32)caseList;
          i4 = (OOC_INT32)select;
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 11826)))), OOC_IR__BuilderDesc_NewCaseStatm)),OOC_IR__BuilderDesc_NewCaseStatm)((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i0, (OOC_IR__Expression)i4, (OOC_IR__CaseList)i3, (OOC_IR__StatementSeq)i1);
          return (OOC_IR__Statement)i0;
          ;
        }

        
        OOC_IR__Statement OOC_AST_CreateIR__CreateIR_StatementSeq_RepeatStatm(OOC_AST__RepeatStatm repeatStatm) {
          register OOC_INT32 i0,i1,i2,i3;

          i0 = (OOC_INT32)repeatStatm;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12215))+12);
          i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i1);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12151))+4);
          i2 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq((OOC_AST__NodeList)i2);
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 12077));
          i3 = (OOC_INT32)b;
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 12085));
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 12048)))), OOC_IR__BuilderDesc_NewRepeatStatm)),OOC_IR__BuilderDesc_NewRepeatStatm)((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i0, (OOC_IR__StatementSeq)i2, (OOC_IR__Expression)i1);
          return (OOC_IR__Statement)i0;
          ;
        }

        
        OOC_IR__Statement OOC_AST_CreateIR__CreateIR_StatementSeq_WhileStatm(OOC_AST__WhileStatm whileStatm) {
          register OOC_INT32 i0,i1,i2,i3;

          i0 = (OOC_INT32)whileStatm;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12505))+12);
          i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq((OOC_AST__NodeList)i1);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12438))+4);
          i2 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i2);
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 12375));
          i3 = (OOC_INT32)b;
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 12382));
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 12348)))), OOC_IR__BuilderDesc_NewWhileStatm)),OOC_IR__BuilderDesc_NewWhileStatm)((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i0, (OOC_IR__Expression)i2, (OOC_IR__StatementSeq)i1);
          return (OOC_IR__Statement)i0;
          ;
        }

        
        OOC_IR__Statement OOC_AST_CreateIR__CreateIR_StatementSeq_WithStatm(OOC_AST__WithStatm withStatm) {
          register OOC_INT32 i0,i1,i2,i3,i4;
          OOC_IR__StatementSeq elseSeq;
          OOC_IR__Statement _else;
          OOC_INT32 i;
          OOC_IR__Expression guard;
          OOC_IR__StatementSeq region;
          auto OOC_IR__Expression OOC_AST_CreateIR__CreateIR_StatementSeq_WithStatm_TypeTestExpr(OOC_AST__Operator op);
            
            OOC_IR__Expression OOC_AST_CreateIR__CreateIR_StatementSeq_WithStatm_TypeTestExpr(OOC_AST__Operator op) {
              register OOC_INT32 i0,i1,i2,i3;

              i0 = (OOC_INT32)op;
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12888))+8);
              i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i1);
              i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 12871));
              i2 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i2);
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12854))+4);
              i3 = (OOC_INT32)b;
              i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 12857));
              i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 12837)))), OOC_IR__BuilderDesc_NewTypeTest)),OOC_IR__BuilderDesc_NewTypeTest)((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i0, (OOC_IR__Expression)i2, (OOC_IR__Expression)i1);
              return (OOC_IR__Expression)i0;
              ;
            }


          i0 = (OOC_INT32)withStatm;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12965))+4);
          i1 = i1!=(OOC_INT32)0;
          if (i1) goto l3;
          elseSeq = (OOC_IR__StatementSeq)(OOC_INT32)0;
          goto l4;
l3:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13028))+8);
          i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq((OOC_AST__NodeList)i1);
          elseSeq = (OOC_IR__StatementSeq)i1;
l4:
          _else = (OOC_IR__Statement)(OOC_INT32)0;
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13138));
          i0 = *(OOC_INT32*)(_check_pointer(i0, 13149));
          i0 = i0-4;
          i = i0;
          
l5_loop:
          i1 = (OOC_INT32)withStatm;
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 13214));
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 13224))+4);
          i1 = _check_pointer(i1, 13226);
          i2 = OOC_ARRAY_LENGTH(i1, 0);
          i0 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index((i0+1), i2, OOC_UINT32, 13226))*4);
          i0 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq_WithStatm_TypeTestExpr((OOC_AST__Operator)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13236)))), &_td_OOC_AST__OperatorDesc, 13236)));
          guard = (OOC_IR__Expression)i0;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13268)))), &_td_OOC_IR__TypeTestDesc);
          if (!i1) goto l8;
          i1 = (OOC_INT32)b;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 13337)))), OOC_IR__BuilderDesc_StartTypeGuard)),OOC_IR__BuilderDesc_StartTypeGuard)((OOC_IR__Builder)i1, (OOC_IR__TypeTest)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13364)))), &_td_OOC_IR__TypeTestDesc, 13364)), (void*)(OOC_INT32)&currentNamespace);
          i1 = (OOC_INT32)withStatm;
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 13438));
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 13448))+4);
          i2 = _check_pointer(i2, 13450);
          i3 = i;
          i4 = OOC_ARRAY_LENGTH(i2, 0);
          i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index((i3+3), i4, OOC_UINT32, 13450))*4);
          i2 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq((OOC_AST__NodeList)(_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 13460)))), &_td_OOC_AST__NodeListDesc, 13460)));
          region = (OOC_IR__StatementSeq)i2;
          i4 = (OOC_INT32)b;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 13485)))), OOC_IR__BuilderDesc_EndTypeGuard)),OOC_IR__BuilderDesc_EndTypeGuard)((OOC_IR__Builder)i4, (void*)(OOC_INT32)&currentNamespace);
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 13595));
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 13606))+4);
          i1 = _check_pointer(i1, 13609);
          i4 = OOC_ARRAY_LENGTH(i1, 0);
          i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(i3, i4, OOC_UINT32, 13609))*4);
          i3 = (OOC_INT32)b;
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 13617)))), &_td_OOC_AST__TerminalDesc, 13617)), 13626));
          i4 = (OOC_INT32)elseSeq;
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 13554)))), OOC_IR__BuilderDesc_NewWithStatm)),OOC_IR__BuilderDesc_NewWithStatm)((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i1, (OOC_IR__Expression)i0, (OOC_IR__StatementSeq)i2, (OOC_IR__StatementSeq)i4);
          _else = (OOC_IR__Statement)i0;
          i1 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__StatementSeq.baseTypes[0], 1);
          elseSeq = (OOC_IR__StatementSeq)i1;
          i1 = _check_pointer(i1, 13724);
          i2 = OOC_ARRAY_LENGTH(i1, 0);
          *(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 13724))*4) = i0;
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
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13979))+28);
              i1 = i1!=(OOC_INT32)0;
              if (i1) goto l3;
              return (OOC_IR__Expression)(OOC_INT32)0;
              goto l4;
l3:
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14031))+28);
              i0 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i0);
              return (OOC_IR__Expression)i0;
l4:
              _failed_function(13919); return 0;
              ;
            }


          i0 = (OOC_INT32)forStatm;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14453))+36);
          i0 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq((OOC_AST__NodeList)i0);
          i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq_ForStatm_Step();
          i2 = (OOC_INT32)forStatm;
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14348))+20);
          i3 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i3);
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14288))+12);
          i4 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i4);
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14233))+4);
          i5 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Designator((OOC_AST__Node)i5);
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 14170));
          i6 = (OOC_INT32)b;
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 14175));
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 14147)))), OOC_IR__BuilderDesc_NewForStatm)),OOC_IR__BuilderDesc_NewForStatm)((OOC_IR__Builder)i6, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i5, (OOC_IR__Expression)i4, (OOC_IR__Expression)i3, (OOC_IR__Expression)i1, (OOC_IR__StatementSeq)i0);
          return (OOC_IR__Statement)i0;
          ;
        }

        
        OOC_IR__Statement OOC_AST_CreateIR__CreateIR_StatementSeq_IterateStatm(OOC_AST__IterateStatm iterStatm) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5;

          i0 = (OOC_INT32)iterStatm;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14836))+20);
          i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq((OOC_AST__NodeList)i1);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14768))+12);
          i2 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i2);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14708))+4);
          i3 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Designator((OOC_AST__Node)i3);
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14618));
          i4 = (OOC_INT32)b;
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14623));
          i5 = (OOC_INT32)currentSourceContext;
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 14590)))), OOC_IR__BuilderDesc_NewIterateStatm)),OOC_IR__BuilderDesc_NewIterateStatm)((OOC_IR__Builder)i4, (OOC_Scanner_SymList__Symbol)i0, (OOC_SymbolTable__Item)i5, (OOC_IR__Expression)i3, (OOC_IR__Expression)i2, (OOC_IR__StatementSeq)i1);
          return (OOC_IR__Statement)i0;
          ;
        }

        
        OOC_IR__Statement OOC_AST_CreateIR__CreateIR_StatementSeq_LoopStatm(OOC_AST__LoopStatm loopStatm) {
          register OOC_INT32 i0,i1,i2;

          i0 = (OOC_INT32)loopStatm;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15064))+4);
          i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq((OOC_AST__NodeList)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14996));
          i2 = (OOC_INT32)b;
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 15002));
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 14971)))), OOC_IR__BuilderDesc_NewLoopStatm)),OOC_IR__BuilderDesc_NewLoopStatm)((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i0, (OOC_IR__StatementSeq)i1);
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
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15374))+8);
          i1 = *(OOC_INT32*)(_check_pointer(i1, 15384));
          i1 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__CatchList.baseTypes[0], i1);
          catchList = (OOC_IR__CatchList)i1;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15432))+4);
          i2 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq((OOC_AST__NodeList)i2);
          statmSeq = (OOC_IR__StatementSeq)i2;
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15474))+8);
          i = 0;
          i3 = *(OOC_INT32*)(_check_pointer(i3, 15484));
          i4 = 0<i3;
          if (!i4) goto l12;
          i4=0;
l3_loop:
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15521))+8);
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 15531))+4);
          i5 = _check_pointer(i5, 15533);
          i6 = OOC_ARRAY_LENGTH(i5, 0);
          i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 15533))*4);
          i5 = _type_guard(i5, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 15541)))), &_td_OOC_AST__CatchDesc, 15541);
          _catch = (OOC_AST__Catch)i5;
          i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 15578))+4);
          i6 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i6);
          guard = (OOC_IR__Expression)i6;
          i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 15606))+12);
          i7 = i7==0;
          if (i7) goto l6;
          i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 15742))+12);
          i8 = (OOC_INT32)b;
          i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i7, 15748));
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i8, 15709)))), OOC_IR__BuilderDesc_StartExceptionScope)),OOC_IR__BuilderDesc_StartExceptionScope)((OOC_IR__Builder)i8, (OOC_IR__Expression)i6, (OOC_Scanner_SymList__Symbol)i7, (void*)(OOC_INT32)&currentNamespace);
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 15817))+24);
          i5 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq((OOC_AST__NodeList)i5);
          catchStatm = (OOC_IR__StatementSeq)i5;
          i7 = (OOC_INT32)b;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 15842)))), OOC_IR__BuilderDesc_EndExceptionScope)),OOC_IR__BuilderDesc_EndExceptionScope)((OOC_IR__Builder)i7, (void*)(OOC_INT32)&currentNamespace);
          
          goto l7;
l6:
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 15669))+24);
          i5 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq((OOC_AST__NodeList)i5);
          catchStatm = (OOC_IR__StatementSeq)i5;
          
l7:
          i7 = _check_pointer(i1, 15925);
          i8 = OOC_ARRAY_LENGTH(i7, 0);
          i9 = (OOC_INT32)b;
          i5 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i9, 15933)))), OOC_IR__BuilderDesc_NewCatchClause)),OOC_IR__BuilderDesc_NewCatchClause)((OOC_IR__Builder)i9, (OOC_IR__Expression)i6, (OOC_IR__StatementSeq)i5);
          *(OOC_INT32*)(i7+(_check_index(i4, i8, OOC_UINT32, 15925))*4) = i5;
          i4 = i4+1;
          i = i4;
          i5 = i4<i3;
          if (i5) goto l3_loop;
l12:
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 16019));
          i3 = (OOC_INT32)b;
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 16023));
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 15998)))), OOC_IR__BuilderDesc_NewTryStatm)),OOC_IR__BuilderDesc_NewTryStatm)((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i0, (OOC_IR__StatementSeq)i2, (OOC_IR__CatchList)i1);
          return (OOC_IR__Statement)i0;
          ;
        }


      count = 0;
      i0 = (OOC_INT32)statmSeq;
      i1 = *(OOC_INT32*)(_check_pointer(i0, 16208));
      i = 0;
      i2 = 0<i1;
      if (i2) goto l3;
      i1=0;
      goto l13;
l3:
      i2=0;i3=0;
l4_loop:
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16244))+4);
      i4 = _check_pointer(i4, 16247);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i2, i5, OOC_UINT32, 16247))*4);
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
      i0 = *(OOC_INT32*)(_check_pointer(i0, 16385));
      i1 = 0<i0;
      if (!i1) goto l79;
      i1=0;
l16_loop:
      i2 = (OOC_INT32)statmSeq;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 16421))+4);
      i3 = _check_pointer(i3, 16424);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i1, i4, OOC_UINT32, 16424))*4);
      i3 = i3!=0;
      if (!i3) goto l74;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 16463))+4);
      i2 = _check_pointer(i2, 16466);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i1 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i1, i3, OOC_UINT32, 16466))*4);
      n = (OOC_AST__Node)i1;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16487)))), &_td_OOC_AST__ProcedureCallDesc);
      if (i2) goto l69;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16576)))), &_td_OOC_AST__ReturnStatmDesc);
      if (i2) goto l67;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16644)))), &_td_OOC_AST__AssignmentDesc);
      if (i2) goto l65;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16839)))), &_td_OOC_AST__IfStatmDesc);
      if (i2) goto l63;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16903)))), &_td_OOC_AST__CaseStatmDesc);
      if (i2) goto l61;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16987)))), &_td_OOC_AST__WithStatmDesc);
      if (i2) goto l59;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17055)))), &_td_OOC_AST__RepeatStatmDesc);
      if (i2) goto l57;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17141)))), &_td_OOC_AST__WhileStatmDesc);
      if (i2) goto l55;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17211)))), &_td_OOC_AST__ForStatmDesc);
      if (i2) goto l53;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17278)))), &_td_OOC_AST__IterateStatmDesc);
      if (i2) goto l51;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17353)))), &_td_OOC_AST__LoopStatmDesc);
      if (i2) goto l49;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17422)))), &_td_OOC_AST__ExitStatmDesc);
      if (i2) goto l47;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17503)))), &_td_OOC_AST__TryStatmDesc);
      if (i2) goto l45;
      Log__Type((OOC_CHAR8*)"++ Unknown type in StatementSeq", 32, (void*)i1);
      _assert(0u, 127, 17655);
      goto l70;
l45:
      i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq_TryStatm((OOC_AST__TryStatm)i1);
      statm = (OOC_IR__Statement)i1;
      goto l70;
l47:
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 17475));
      i2 = (OOC_INT32)b;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 17481));
      i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 17463)))), OOC_IR__BuilderDesc_NewExit)),OOC_IR__BuilderDesc_NewExit)((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i1);
      statm = (OOC_IR__Statement)i1;
      goto l70;
l49:
      i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq_LoopStatm((OOC_AST__LoopStatm)i1);
      statm = (OOC_IR__Statement)i1;
      goto l70;
l51:
      i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq_IterateStatm((OOC_AST__IterateStatm)i1);
      statm = (OOC_IR__Statement)i1;
      goto l70;
l53:
      i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq_ForStatm((OOC_AST__ForStatm)i1);
      statm = (OOC_IR__Statement)i1;
      goto l70;
l55:
      i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq_WhileStatm((OOC_AST__WhileStatm)i1);
      statm = (OOC_IR__Statement)i1;
      goto l70;
l57:
      i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq_RepeatStatm((OOC_AST__RepeatStatm)i1);
      statm = (OOC_IR__Statement)i1;
      goto l70;
l59:
      i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq_WithStatm((OOC_AST__WithStatm)i1);
      statm = (OOC_IR__Statement)i1;
      goto l70;
l61:
      i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq_CaseStatm((OOC_AST__CaseStatm)i1);
      statm = (OOC_IR__Statement)i1;
      goto l70;
l63:
      i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq_IfStatm((OOC_AST__IfStatm)i1);
      statm = (OOC_IR__Statement)i1;
      goto l70;
l65:
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 16804));
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 16752));
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 16698));
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 16816))+8);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 16764))+4);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 16710));
      i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq_Assignment((OOC_AST__Node)i1, (OOC_AST__Node)i3, (OOC_AST__Node)i2);
      statm = (OOC_IR__Statement)i1;
      goto l70;
l67:
      i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq_Return((OOC_AST__ReturnStatm)i1);
      statm = (OOC_IR__Statement)i1;
      goto l70;
l69:
      i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq_ProcedureCall((OOC_AST__ProcedureCall)i1);
      statm = (OOC_IR__Statement)i1;
l70:
      i1 = (OOC_INT32)statm;
      i2 = i1!=0;
      if (!i2) goto l74;
      i2 = (OOC_INT32)statmSeqIR;
      i2 = _check_pointer(i2, 17780);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i4 = count;
      *(OOC_INT32*)(i2+(_check_index(i4, i3, OOC_UINT32, 17780))*4) = i1;
      count = (i4+1);
l74:
      i1 = i;
      i1 = i1+2;
      i = i1;
      i2 = i1<i0;
      if (i2) goto l16_loop;
l79:
      i0 = (OOC_INT32)statmSeqIR;
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 17894)), 0);
      i2 = count;
      i1 = i2!=i1;
      if (!i1) goto l90;
      i1 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__StatementSeq.baseTypes[0], i2);
      copy = (OOC_IR__StatementSeq)i1;
      i = 0;
      i3 = 0<i2;
      if (!i3) goto l89;
      i3=0;
l84_loop:
      i4 = _check_pointer(i1, 18075);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i6 = _check_pointer(i0, 18092);
      i7 = OOC_ARRAY_LENGTH(i6, 0);
      i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i3, i7, OOC_UINT32, 18092))*4);
      *(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 18075))*4) = i6;
      i3 = i3+1;
      i = i3;
      i4 = i3<i2;
      if (i4) goto l84_loop;
l89:
      statmSeqIR = (OOC_IR__StatementSeq)i1;
l90:
      i0 = (OOC_INT32)statmSeqIR;
      return (OOC_IR__StatementSeq)i0;
      ;
    }

    
    void OOC_AST_CreateIR__CreateIR_ConstDecl(OOC_SymbolTable__ConstDecl constDecl, OOC_AST__Node constExpr) {
      register OOC_INT32 i0,i1,i2;
      OOC_IR__Expression expr;

      i0 = (OOC_INT32)constExpr;
      i0 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i0);
      i1 = (OOC_INT32)b;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 18320)))), OOC_IR__BuilderDesc_AssertConst)),OOC_IR__BuilderDesc_AssertConst)((OOC_IR__Builder)i1, (OOC_IR__Expression)i0);
      expr = (OOC_IR__Expression)i0;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18410))+4);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18391)))), &_td_OOC_IR__ConstDesc, 18391)), 18397))+8);
      i2 = (OOC_INT32)constDecl;
      OOC_SymbolTable__ConstDeclDesc_SetValueType((OOC_SymbolTable__ConstDecl)i2, (Object_Boxed__Object)i0, (OOC_SymbolTable__PredefType)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 18421)))), &_td_OOC_SymbolTable__PredefTypeDesc, 18421)));
      return;
      ;
    }

    
    OOC_IR__Procedure OOC_AST_CreateIR__CreateIR_ProcDecl(OOC_SymbolTable__ProcDecl procDecl, OOC_AST__ProcDecl procCode) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
      OOC_SymbolTable__Namespace oldNamespace;
      OOC_SymbolTable__Item oldSourceContext;
      OOC_IR__Expression receiver;
      OOC_IR__StatementSeq statmSeq;
      OOC_Scanner_SymList__Symbol endOfBody;

      i0 = (OOC_INT32)currentNamespace;
      oldNamespace = (OOC_SymbolTable__Namespace)i0;
      i1 = (OOC_INT32)currentSourceContext;
      oldSourceContext = (OOC_SymbolTable__Item)i1;
      i2 = (OOC_INT32)procDecl;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 18898))+60);
      currentNamespace = (OOC_SymbolTable__Namespace)i3;
      currentSourceContext = (OOC_SymbolTable__Item)i2;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 18963))+64);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 18974))+40);
      i3 = i3!=(OOC_INT32)0;
      if (!i3) goto l3;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 19081))+64);
      i4 = (OOC_INT32)procCode;
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 19033));
      i5 = (OOC_INT32)b;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 19092))+40);
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 19038));
      i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 19017)))), OOC_IR__BuilderDesc_NewVar)),OOC_IR__BuilderDesc_NewVar)((OOC_IR__Builder)i5, (OOC_Scanner_SymList__Symbol)i4, (OOC_SymbolTable__VarDecl)i3);
      receiver = (OOC_IR__Expression)i3;
      i4 = (OOC_INT32)b;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 19113)))), OOC_IR__BuilderDesc_SetCurrentReceiver)),OOC_IR__BuilderDesc_SetCurrentReceiver)((OOC_IR__Builder)i4, (OOC_IR__Expression)i3);
l3:
      i3 = (OOC_INT32)procCode;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 19180))+28);
      i4 = i4==(OOC_INT32)0;
      if (i4) goto l6;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 19206))+28);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 19212))+8);
      i4 = i4==(OOC_INT32)0;
      
      goto l8;
l6:
      i4=1u;
l8:
      if (i4) goto l10;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 19314))+28);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 19320))+8);
      i4 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq((OOC_AST__NodeList)i4);
      statmSeq = (OOC_IR__StatementSeq)i4;
      
      goto l11;
l10:
      i4 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__StatementSeq.baseTypes[0], 0);
      statmSeq = (OOC_IR__StatementSeq)i4;
      
l11:
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 19361))+28);
      i5 = i5==(OOC_INT32)0;
      if (i5) goto l14;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 19445))+28);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 19451))+12);
      i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 19456));
      endOfBody = (OOC_Scanner_SymList__Symbol)i5;
      
      goto l15;
l14:
      endOfBody = (OOC_Scanner_SymList__Symbol)(OOC_INT32)0;
      i5=(OOC_INT32)0;
l15:
      i6 = (OOC_INT32)b;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 19488)))), OOC_IR__BuilderDesc_SetCurrentReceiver)),OOC_IR__BuilderDesc_SetCurrentReceiver)((OOC_IR__Builder)i6, (OOC_IR__Expression)(OOC_INT32)0);
      currentNamespace = (OOC_SymbolTable__Namespace)i0;
      currentSourceContext = (OOC_SymbolTable__Item)i1;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 19753))+28);
      i0 = i0!=(OOC_INT32)0;
      if (i0) goto l18;
      i0=0u;
      goto l19;
l18:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 19808))+28);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19813))+4);
      i0 = i0!=(OOC_INT32)0;
      
l19:
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 19640));
      i3 = (OOC_INT32)b;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 19646));
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 19616)))), OOC_IR__BuilderDesc_NewProcedure)),OOC_IR__BuilderDesc_NewProcedure)((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i1, (OOC_SymbolTable__ProcDecl)i2, (OOC_IR__StatementSeq)i4, (OOC_Scanner_SymList__Symbol)i5, i0);
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
          i0 = *(OOC_UINT8*)((_check_pointer(i0, 20177))+49);
          return (!i0);
          ;
        }

        
        OOC_INT32 OOC_AST_CreateIR__CreateIR_Module_CountProcs(OOC_SymbolTable__Item item) {
          register OOC_INT32 i0,i1,i2;
          OOC_INT32 count;
          OOC_SymbolTable__Item nested;

          i0 = (OOC_INT32)item;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20353)))), &_td_OOC_SymbolTable__ProcDeclDesc);
          if (i1) goto l3;
          i1=0u;
          goto l5;
l3:
          i1 = OOC_AST_CreateIR__CreateIR_Module_IsProc((OOC_SymbolTable__ProcDecl)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20389)))), &_td_OOC_SymbolTable__ProcDeclDesc, 20389)));
          
l5:
          if (i1) goto l7;
          count = 0;
          i1=0;
          goto l8;
l7:
          count = 1;
          i1=1;
l8:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20505))+8);
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
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 20622));
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
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20808)))), &_td_OOC_SymbolTable__ProcDeclDesc);
          if (!i1) goto l6;
          i1 = OOC_AST_CreateIR__CreateIR_Module_IsProc((OOC_SymbolTable__ProcDecl)i0);
          if (!i1) goto l6;
          i1 = (OOC_INT32)procList;
          i1 = _check_pointer(i1, 20878);
          i2 = OOC_ARRAY_LENGTH(i1, 0);
          i3 = count;
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20909))+72);
          i4 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_ProcDecl((OOC_SymbolTable__ProcDecl)i0, (OOC_AST__ProcDecl)(_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 20922)))), &_td_OOC_AST__ProcDeclDesc, 20922)));
          i5 = count;
          *(OOC_INT32*)(i1+(_check_index(i3, i2, OOC_UINT32, 20878))*4) = i4;
          count = (i5+1);
l6:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21071))+8);
          nested = (OOC_SymbolTable__Item)i0;
          i1 = i0!=(OOC_INT32)0;
          if (!i1) goto l14;
l9_loop:
          OOC_AST_CreateIR__CreateIR_Module_TraverseProcedures((OOC_SymbolTable__Item)i0);
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 21183));
          nested = (OOC_SymbolTable__Item)i0;
          i1 = i0!=(OOC_INT32)0;
          if (i1) goto l9_loop;
l14:
          return;
          ;
        }


      i0 = (OOC_INT32)moduleAST;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21280))+20);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 21286));
      declSeq = (OOC_AST__NodeList)i0;
      i0 = (OOC_INT32)moduleDecl;
      i0 = OOC_AST_CreateIR__CreateIR_Module_CountProcs((OOC_SymbolTable__Item)i0);
      procList = (OOC_IR__ProcedureList)((OOC_INT32)RT0__NewObject(_td_OOC_IR__ProcedureList.baseTypes[0], i0));
      count = 0;
      i0 = (OOC_INT32)moduleDecl;
      OOC_AST_CreateIR__CreateIR_Module_TraverseProcedures((OOC_SymbolTable__Item)i0);
      i0 = (OOC_INT32)moduleAST;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21428))+20);
      i1 = i1==0;
      if (i1) goto l3;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21455))+20);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 21461))+8);
      i1 = i1==0;
      
      goto l5;
l3:
      i1=1u;
l5:
      if (i1) goto l7;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21564))+20);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 21570))+8);
      i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq((OOC_AST__NodeList)i1);
      statmSeq = (OOC_IR__StatementSeq)i1;
      
      goto l8;
l7:
      i1 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__StatementSeq.baseTypes[0], 0);
      statmSeq = (OOC_IR__StatementSeq)i1;
      
l8:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21769))+20);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 21775))+12);
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 21636));
      i4 = (OOC_INT32)b;
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 21780));
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 21644));
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21660))+28);
      i5 = (OOC_INT32)procList;
      i6 = (OOC_INT32)moduleDecl;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 21614)))), OOC_IR__BuilderDesc_NewModule)),OOC_IR__BuilderDesc_NewModule)((OOC_IR__Builder)i4, (OOC_Scanner_SymList__Symbol)i3, (OOC_Scanner_InputBuffer__CharArray)i0, (OOC_SymbolTable__Module)i6, (OOC_IR__ProcedureList)i5, (OOC_IR__StatementSeq)i1, (OOC_Scanner_SymList__Symbol)i2);
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
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22423))+8);
          nested = (OOC_SymbolTable__Item)i0;
          i1 = i0!=(OOC_INT32)0;
          if (!i1) goto l8;
l3_loop:
          OOC_AST_CreateIR__CreateIR_TranslateEmbeddedExpr((OOC_SymbolTable__Item)i0);
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 22538));
          nested = (OOC_SymbolTable__Item)i0;
          i1 = i0!=(OOC_INT32)0;
          if (i1) goto l3_loop;
l8:
          return;
          ;
        }


      i0 = (OOC_INT32)item;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22620)))), &_td_OOC_SymbolTable__RecordDesc);
      if (!i1) goto l3;
      OOC_AST_CreateIR__CreateIR_TranslateEmbeddedExpr_TraverseNested((OOC_SymbolTable__Item)i0);
l3:
      i0 = (OOC_INT32)item;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22882)))), &_td_OOC_SymbolTable__ArrayDesc);
      if (i1) goto l9;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23223)))), &_td_OOC_SymbolTable__ConstDeclDesc);
      if (!i1) goto l17;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23271))+56);
      OOC_AST_CreateIR__CreateIR_ConstDecl((OOC_SymbolTable__ConstDecl)i0, (OOC_AST__Node)i1);
      goto l17;
l9:
      i1 = *(OOC_UINT8*)((_check_pointer(i0, 22913))+40);
      i1 = !i1;
      if (!i1) goto l17;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22973))+56);
      i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i1);
      i2 = (OOC_INT32)b;
      i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 22951)))), OOC_IR__BuilderDesc_AssertConst)),OOC_IR__BuilderDesc_AssertConst)((OOC_IR__Builder)i2, (OOC_IR__Expression)i1);
      expr = (OOC_IR__Expression)i1;
      i2 = (OOC_INT32)b;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 23010))+24);
      i2 = i1==i2;
      if (i2) goto l14;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 23140)))), &_td_OOC_IR__ConstDesc, 23140)), 23146))+8);
      i1 = Object_BigInt__BigIntDesc_ToLongInt((Object_BigInt__BigInt)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 23160)))), &_td_Object_BigInt__BigIntDesc, 23160)));
      OOC_SymbolTable__ArrayDesc_SetLength((OOC_SymbolTable__Array)i0, i1);
      goto l17;
l14:
      OOC_SymbolTable__ArrayDesc_SetLength((OOC_SymbolTable__Array)i0, 1);
l17:
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23346)))), &_td_OOC_SymbolTable__TypeDesc);
      if (!i1) goto l23;
      i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23378)))), &_td_OOC_SymbolTable__TypeNameDesc));
      if (!i1) goto l23;
      OOC_SymbolTable_TypeRules__AllocateType((OOC_SymbolTable__Type)i0);
l23:
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23500)))), &_td_OOC_SymbolTable__ProcDeclDesc);
      if (i1) goto l29;
      i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23856)))), &_td_OOC_SymbolTable__RecordDesc));
      if (!i1) goto l30;
      OOC_AST_CreateIR__CreateIR_TranslateEmbeddedExpr_TraverseNested((OOC_SymbolTable__Item)i0);
      goto l30;
l29:
      i1 = (OOC_INT32)currentNamespace;
      oldNamespace = (OOC_SymbolTable__Namespace)i1;
      i1 = (OOC_INT32)currentSourceContext;
      oldSourceContext = (OOC_SymbolTable__Item)i1;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23642))+60);
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
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24041))+48);
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

void OOC_OOC_AST_CreateIR_destroy(void) {
}

/* --- */
