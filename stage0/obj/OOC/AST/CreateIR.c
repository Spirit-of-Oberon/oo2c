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
      i1 = (OOC_INT32)b;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3986))+4);
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4039));
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 3989));
      i3 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i3);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4056))+8);
      i4 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i4);
      i5 = isSet;
      i6 = (OOC_INT32)type;
      i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3969)))), OOC_IR__BuilderDesc_NewSetRange)),OOC_IR__BuilderDesc_NewSetRange)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i6, (OOC_IR__Expression)i3, (OOC_IR__Expression)i4, i5);
      return (OOC_IR__Expression)i1;
l6:
      i0 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i0);
      e = (OOC_IR__Expression)i0;
      i1 = (OOC_INT32)b;
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4149));
      i3 = (OOC_INT32)type;
      i4 = isSet;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4135)))), OOC_IR__BuilderDesc_NewSetRange)),OOC_IR__BuilderDesc_NewSetRange)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i3, (OOC_IR__Expression)i0, (OOC_IR__Expression)i0, i4);
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
      i4=1;
l10_loop:
      i5 = (OOC_INT32)b;
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4754))+8);
      i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 4766))+4);
      i6 = _check_pointer(i6, 4768);
      i7 = OOC_ARRAY_LENGTH(i6, 0);
      i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index((i4*2), i7, OOC_UINT32, 4768))*4);
      i6 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Range((OOC_IR__Expression)i1, (OOC_AST__Node)i6, 1u);
      i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 4675)))), OOC_IR__BuilderDesc_NewSetOp)),OOC_IR__BuilderDesc_NewSetOp)((OOC_IR__Builder)i5, (OOC_Scanner_SymList__Symbol)0, 6, (OOC_IR__Expression)i3, (OOC_IR__Expression)i6);
      result = (OOC_IR__Expression)i3;
      i4 = i4+1;
      i = i4;
      i5 = i4<i2;
      if (i5) goto l10_loop;
l14:
      i0=i3;
l15:
      return (OOC_IR__Expression)i0;
      goto l17;
l16:
      i2 = (OOC_INT32)b;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4482))+4);
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
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5057));
      i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Designator((OOC_AST__Node)i1);
      type = (OOC_IR__Expression)i1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5100))+8);
      i2 = *(OOC_INT32*)(_check_pointer(i2, 5110));
      i2 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__ExpressionList.baseTypes[0], ((i2+1)>>1));
      arguments = (OOC_IR__ExpressionList)i2;
      i = 0;
      i3 = OOC_ARRAY_LENGTH((_check_pointer(i2, 5159)), 0);
      i4 = 0<i3;
      if (!i4) goto l12;
      i4=0;
l3_loop:
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5188))+8);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 5198))+4);
      i5 = _check_pointer(i5, 5200);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index((i4*2), i6, OOC_UINT32, 5200))*4);
      n = (OOC_AST__Node)i5;
      i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 5221)))), &_td_OOC_AST__QualTypeDesc);
      if (i6) goto l6;
      i6 = _check_pointer(i2, 5310);
      i7 = OOC_ARRAY_LENGTH(i6, 0);
      i5 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Designator((OOC_AST__Node)i5);
      *(OOC_INT32*)(i6+(_check_index(i4, i7, OOC_UINT32, 5310))*4) = i5;
      goto l7;
l6:
      i6 = _check_pointer(i2, 5258);
      i7 = OOC_ARRAY_LENGTH(i6, 0);
      i5 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_QualType((OOC_AST__QualType)i5);
      *(OOC_INT32*)(i6+(_check_index(i4, i7, OOC_UINT32, 5258))*4) = i5;
l7:
      i4 = i4+1;
      i = i4;
      i5 = i4<i3;
      if (i5) goto l3_loop;
l12:
      i3 = (OOC_INT32)b;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5434))+12);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5441));
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 5396)))), OOC_IR__BuilderDesc_NewQualType)),OOC_IR__BuilderDesc_NewQualType)((OOC_IR__Builder)i3, (OOC_IR__Expression)i1, (OOC_IR__ExpressionList)i2, (OOC_Scanner_SymList__Symbol)i0);
      return (OOC_IR__Expression)i0;
      ;
    }

    
    OOC_IR__Expression OOC_AST_CreateIR__CreateIR_Expr(OOC_AST__Node expr) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_IR__Expression res;
      OOC_IR__Expression left;
      OOC_IR__Expression right;

      i0 = (OOC_INT32)expr;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5592)))), &_td_OOC_AST__TerminalDesc);
      if (i1) goto l43;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6283)))), &_td_OOC_AST__FactorDesc);
      if (i1) goto l41;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6357)))), &_td_OOC_AST__ArrayIndexDesc);
      if (i1) goto l39;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6460)))), &_td_OOC_AST__OperatorDesc);
      if (i1) goto l21;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7024)))), &_td_OOC_AST__SetDesc);
      if (i1) goto l19;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7085)))), &_td_OOC_AST__FunctionCallDesc);
      if (i1) goto l17;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7163)))), &_td_OOC_AST__QualTypeDesc);
      if (i1) goto l15;
      Log__Type("++ Unknown expression class in Expr", 36, (void*)i0);
      _assert(0u, 127, 7303);
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
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6494))+4);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 6498));
      i1 = *(OOC_INT8*)((_check_pointer(i1, 6503))+4);
      i1 = i1==18;
      if (i1) goto l24;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6544))+4);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 6548));
      i1 = *(OOC_INT8*)((_check_pointer(i1, 6553))+4);
      i1 = i1==17;
      
      goto l26;
l24:
      i1=1u;
l26:
      if (i1) goto l36;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6692));
      i1 = i1!=0;
      if (i1) goto l30;
      left = (OOC_IR__Expression)0;
      i1=0;
      goto l31;
l30:
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6741));
      i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i1);
      left = (OOC_IR__Expression)i1;
      
l31:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6821))+8);
      i2 = i2!=0;
      if (i2) goto l34;
      right = (OOC_IR__Expression)0;
      i2=0;
      goto l35;
l34:
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6872))+8);
      i2 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i2);
      right = (OOC_IR__Expression)i2;
      
l35:
      i3 = (OOC_INT32)b;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6973))+4);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6977));
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 6954)))), OOC_IR__BuilderDesc_NewOperator)),OOC_IR__BuilderDesc_NewOperator)((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i0, (OOC_IR__Expression)i1, (OOC_IR__Expression)i2);
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
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6324))+4);
      i0 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i0);
      res = (OOC_IR__Expression)i0;
      goto l55;
l43:
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5627));
      i1 = *(OOC_INT8*)((_check_pointer(i1, 5632))+4);
      switch (i1) {
      case 45:
        i0 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Designator((OOC_AST__Node)i0);
        res = (OOC_IR__Expression)i0;
        goto l55;
      case 43:
      case 44:
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5791));
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5769)))), OOC_IR__BuilderDesc_NewStringConst)),OOC_IR__BuilderDesc_NewStringConst)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i0);
        res = (OOC_IR__Expression)i0;
        goto l55;
      case 37:
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5864));
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5843)))), OOC_IR__BuilderDesc_NewIntConst10)),OOC_IR__BuilderDesc_NewIntConst10)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i0);
        res = (OOC_IR__Expression)i0;
        goto l55;
      case 38:
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5937));
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5916)))), OOC_IR__BuilderDesc_NewIntConst16)),OOC_IR__BuilderDesc_NewIntConst16)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i0);
        res = (OOC_IR__Expression)i0;
        goto l55;
      case 39:
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6012));
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5990)))), OOC_IR__BuilderDesc_NewCharConst16)),OOC_IR__BuilderDesc_NewCharConst16)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i0);
        res = (OOC_IR__Expression)i0;
        goto l55;
      case 40:
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6086));
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6066)))), OOC_IR__BuilderDesc_NewRealConst)),OOC_IR__BuilderDesc_NewRealConst)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i0, 8);
        res = (OOC_IR__Expression)i0;
        goto l55;
      case 41:
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6173));
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6153)))), OOC_IR__BuilderDesc_NewRealConst)),OOC_IR__BuilderDesc_NewRealConst)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i0, 9);
        res = (OOC_IR__Expression)i0;
        goto l55;
      case 42:
        i1 = (OOC_INT32)b;
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6251));
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6237)))), OOC_IR__BuilderDesc_NewNil)),OOC_IR__BuilderDesc_NewNil)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i0);
        res = (OOC_IR__Expression)i0;
        goto l55;
      default:
        _failed_case(i1, 5618);
        goto l55;
      }
l55:
      i0 = (OOC_INT32)b;
      i1 = (OOC_INT32)res;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7343)))), OOC_IR__BuilderDesc_Fold)),OOC_IR__BuilderDesc_Fold)((OOC_IR__Builder)i0, (OOC_IR__Expression)i1);
      return (OOC_IR__Expression)i0;
      ;
    }

    
    OOC_IR__Expression OOC_AST_CreateIR__CreateIR_FunctionCall(OOC_AST__FunctionCall call, OOC_CHAR8 isProcCall) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
      OOC_IR__Expression design;
      OOC_IR__ExpressionList arguments;
      OOC_INT32 i;

      i0 = (OOC_INT32)call;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7619));
      i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Designator((OOC_AST__Node)i1);
      design = (OOC_IR__Expression)i1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7657))+8);
      i2 = *(OOC_INT32*)(_check_pointer(i2, 7668));
      i2 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__ExpressionList.baseTypes[0], ((i2+1)>>1));
      arguments = (OOC_IR__ExpressionList)i2;
      i = 0;
      i3 = OOC_ARRAY_LENGTH((_check_pointer(i2, 7719)), 0);
      i4 = 0<i3;
      if (!i4) goto l8;
      i4=0;
l3_loop:
      i5 = _check_pointer(i2, 7744);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7761))+8);
      i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i7, 7772))+4);
      i7 = _check_pointer(i7, 7775);
      i8 = OOC_ARRAY_LENGTH(i7, 0);
      i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index((i4*2), i8, OOC_UINT32, 7775))*4);
      i7 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i7);
      *(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 7744))*4) = i7;
      i4 = i4+1;
      i = i4;
      i5 = i4<i3;
      if (i5) goto l3_loop;
l8:
      i3 = (OOC_INT32)b;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7897))+12);
      i4 = isProcCall;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7904));
      i5 = (OOC_INT32)currentSourceContext;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 7807)))), OOC_IR__BuilderDesc_NewCall)),OOC_IR__BuilderDesc_NewCall)((OOC_IR__Builder)i3, (OOC_IR__Expression)i1, (OOC_IR__ExpressionList)i2, (!i4), (OOC_SymbolTable__Item)i5, (OOC_Scanner_SymList__Symbol)i0);
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
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 8305));
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8312)))), &_td_OOC_AST__FunctionCallDesc);
          if (i1) goto l3;
          i1 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__ExpressionList.baseTypes[0], 0);
          arguments = (OOC_IR__ExpressionList)i1;
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 8547));
          i0 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Designator((OOC_AST__Node)i0);
          design = (OOC_IR__Expression)i0;
          i2 = (OOC_INT32)b;
          i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 8666));
          i4 = (OOC_INT32)currentSourceContext;
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 8575)))), OOC_IR__BuilderDesc_NewCall)),OOC_IR__BuilderDesc_NewCall)((OOC_IR__Builder)i2, (OOC_IR__Expression)i0, (OOC_IR__ExpressionList)i1, 0u, (OOC_SymbolTable__Item)i4, (OOC_Scanner_SymList__Symbol)i3);
          expr = (OOC_IR__Expression)i0;
          
          goto l4;
l3:
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 8374));
          i0 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_FunctionCall((OOC_AST__FunctionCall)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8385)))), &_td_OOC_AST__FunctionCallDesc, 8385)), 1u);
          expr = (OOC_IR__Expression)i0;
          
l4:
          i1 = i0!=0;
          if (i1) goto l7;
          i1=0u;
          goto l9;
l7:
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8718)))), &_td_OOC_IR__StatementDesc);
          
l9:
          if (i1) goto l11;
          return (OOC_IR__Statement)0;
          goto l12;
l11:
          return (OOC_IR__Statement)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8765)))), &_td_OOC_IR__StatementDesc, 8765));
l12:
          _failed_function(8137); return 0;
          ;
        }

        
        OOC_IR__Statement OOC_AST_CreateIR__CreateIR_StatementSeq_Return(OOC_AST__ReturnStatm _return) {
          register OOC_INT32 i0,i1,i2;

          i0 = (OOC_INT32)_return;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9001))+4);
          i1 = i1==(OOC_INT32)0;
          if (i1) goto l3;
          i1 = (OOC_INT32)b;
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9127));
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9185))+4);
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 9135));
          i0 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i0);
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9108)))), OOC_IR__BuilderDesc_NewReturn)),OOC_IR__BuilderDesc_NewReturn)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i0);
          return (OOC_IR__Statement)i0;
          goto l4;
l3:
          i1 = (OOC_INT32)b;
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9057));
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9065));
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9038)))), OOC_IR__BuilderDesc_NewReturn)),OOC_IR__BuilderDesc_NewReturn)((OOC_IR__Builder)i1, (OOC_Scanner_SymList__Symbol)i0, (OOC_IR__Expression)(OOC_INT32)0);
          return (OOC_IR__Statement)i0;
l4:
          _failed_function(8923); return 0;
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
          i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 9478)))), &_td_OOC_AST__TerminalDesc, 9478)), 9487));
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 9454)))), OOC_IR__BuilderDesc_NewAssignment)),OOC_IR__BuilderDesc_NewAssignment)((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i3, (OOC_IR__Expression)i0, (OOC_IR__Expression)i1);
          return (OOC_IR__Statement)i0;
          ;
        }

        
        OOC_IR__Statement OOC_AST_CreateIR__CreateIR_StatementSeq_IfStatm(OOC_AST__IfStatm ifStatm) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
          OOC_IR__StatementSeq elseSeq;
          OOC_INT32 i;
          OOC_IR__Statement _else;

          i0 = (OOC_INT32)ifStatm;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9725))+4);
          i1 = i1!=(OOC_INT32)0;
          if (i1) goto l3;
          elseSeq = (OOC_IR__StatementSeq)(OOC_INT32)0;
          i1=(OOC_INT32)0;
          goto l4;
l3:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9786))+8);
          i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq((OOC_AST__NodeList)i1);
          elseSeq = (OOC_IR__StatementSeq)i1;
          
l4:
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9873));
          i2 = *(OOC_INT32*)(_check_pointer(i2, 9884));
          i2 = i2-4;
          i = i2;
          {register OOC_INT32 h0=i1;i1=i2;i2=h0;}
l5_loop:
          i3 = (OOC_INT32)b;
          i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9962));
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 9973))+4);
          i4 = _check_pointer(i4, 9976);
          i5 = OOC_ARRAY_LENGTH(i4, 0);
          i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i1, i5, OOC_UINT32, 9976))*4);
          i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10028));
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 10039))+4);
          i5 = _check_pointer(i5, 10042);
          i6 = OOC_ARRAY_LENGTH(i5, 0);
          i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index((i1+1), i6, OOC_UINT32, 10042))*4);
          i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 9984)))), &_td_OOC_AST__TerminalDesc, 9984)), 9993));
          i5 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i5);
          i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10086));
          i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 10097))+4);
          i6 = _check_pointer(i6, 10100);
          i7 = OOC_ARRAY_LENGTH(i6, 0);
          i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index((i1+3), i7, OOC_UINT32, 10100))*4);
          i6 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq((OOC_AST__NodeList)(_type_guard(i6, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 10110)))), &_td_OOC_AST__NodeListDesc, 10110)));
          i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 9927)))), OOC_IR__BuilderDesc_NewIfStatm)),OOC_IR__BuilderDesc_NewIfStatm)((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i4, (OOC_IR__Expression)i5, (OOC_IR__StatementSeq)i6, (OOC_IR__StatementSeq)i2);
          _else = (OOC_IR__Statement)i2;
          i3 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__StatementSeq.baseTypes[0], 1);
          elseSeq = (OOC_IR__StatementSeq)i3;
          i4 = _check_pointer(i3, 10192);
          i5 = OOC_ARRAY_LENGTH(i4, 0);
          *(OOC_INT32*)(i4+(_check_index(0, i5, OOC_UINT8, 10192))*4) = i2;
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
              i1 = *(OOC_INT32*)(_check_pointer(i0, 10670));
              i1 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__CaseLabels.baseTypes[0], ((i1+1)>>1));
              setRanges = (OOC_IR__CaseLabels)i1;
              i = 0;
              i2 = *(OOC_INT32*)(_check_pointer(i0, 10717));
              i3 = 0<i2;
              if (!i3) goto l8;
              i3=0;
l3_loop:
              i4 = _check_pointer(i1, 10754);
              i5 = OOC_ARRAY_LENGTH(i4, 0);
              i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10785))+4);
              i6 = _check_pointer(i6, 10788);
              i7 = OOC_ARRAY_LENGTH(i6, 0);
              i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i3, i7, OOC_UINT32, 10788))*4);
              i6 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Range((OOC_IR__Expression)0, (OOC_AST__Node)i6, 0u);
              *(OOC_INT32*)(i4+(_check_index((i3>>1), i5, OOC_UINT32, 10754))*4) = i6;
              i3 = i3+2;
              i = i3;
              i4 = i3<i2;
              if (i4) goto l3_loop;
l8:
              return (OOC_IR__CaseLabels)i1;
              ;
            }


          i0 = (OOC_INT32)caseStatm;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10916))+4);
          i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i1);
          select = (OOC_IR__Expression)i1;
          count = 0;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11016))+12);
          i1 = *(OOC_INT32*)(_check_pointer(i1, 11026));
          i = 0;
          i2 = 0<i1;
          if (i2) goto l3;
          i1=0;
          goto l13;
l3:
          i2=0;i3=0;
l4_loop:
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11065))+12);
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 11075))+4);
          i4 = _check_pointer(i4, 11078);
          i5 = OOC_ARRAY_LENGTH(i4, 0);
          i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i2, i5, OOC_UINT32, 11078))*4);
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
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11277))+12);
          i = 0;
          i1 = *(OOC_INT32*)(_check_pointer(i1, 11287));
          i2 = 0<i1;
          if (!i2) goto l26;
          i2=0;i3=0;
l17_loop:
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11326))+12);
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 11336))+4);
          i4 = _check_pointer(i4, 11339);
          i5 = OOC_ARRAY_LENGTH(i4, 0);
          i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i2, i5, OOC_UINT32, 11339))*4);
          i4 = i4!=0;
          if (i4) goto l20;
          {register OOC_INT32 h0=i2;i2=i3;i3=h0;}
          goto l21;
l20:
          i4 = (OOC_INT32)caseList;
          i4 = _check_pointer(i4, 11375);
          i5 = OOC_ARRAY_LENGTH(i4, 0);
          i6 = (OOC_INT32)b;
          i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11421))+12);
          i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i7, 11431))+4);
          i7 = _check_pointer(i7, 11434);
          i8 = OOC_ARRAY_LENGTH(i7, 0);
          i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index((i2+1), i8, OOC_UINT32, 11434))*4);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11492))+12);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11502))+4);
          i0 = _check_pointer(i0, 11505);
          i8 = OOC_ARRAY_LENGTH(i0, 0);
          i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(i2, i8, OOC_UINT32, 11505))*4);
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i7, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 11444)))), &_td_OOC_AST__TerminalDesc, 11444)), 11453));
          i0 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq_CaseStatm_Labels((OOC_AST__NodeList)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11513)))), &_td_OOC_AST__NodeListDesc, 11513)));
          i7 = (OOC_INT32)caseStatm;
          i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i7, 11563))+12);
          i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i8, 11573))+4);
          i8 = _check_pointer(i8, 11576);
          i9 = i;
          i10 = OOC_ARRAY_LENGTH(i8, 0);
          i8 = (OOC_INT32)*(OOC_INT32*)(i8+(_check_index((i9+2), i10, OOC_UINT32, 11576))*4);
          i8 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq((OOC_AST__NodeList)(_type_guard(i8, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i8, 11586)))), &_td_OOC_AST__NodeListDesc, 11586)));
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 11387)))), OOC_IR__BuilderDesc_NewCase)),OOC_IR__BuilderDesc_NewCase)((OOC_IR__Builder)i6, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__CaseLabels)i0, (OOC_IR__StatementSeq)i8);
          i2 = count;
          *(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 11375))*4) = i0;
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
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11673))+16);
          i1 = i1!=0;
          if (i1) goto l29;
          elseSeq = (OOC_IR__StatementSeq)0;
          i1=0;
          goto l30;
l29:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11736))+20);
          i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq((OOC_AST__NodeList)i1);
          elseSeq = (OOC_IR__StatementSeq)i1;
          
l30:
          i2 = (OOC_INT32)b;
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 11844));
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 11850));
          i3 = (OOC_INT32)select;
          i4 = (OOC_INT32)caseList;
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 11819)))), OOC_IR__BuilderDesc_NewCaseStatm)),OOC_IR__BuilderDesc_NewCaseStatm)((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i0, (OOC_IR__Expression)i3, (OOC_IR__CaseList)i4, (OOC_IR__StatementSeq)i1);
          return (OOC_IR__Statement)i0;
          ;
        }

        
        OOC_IR__Statement OOC_AST_CreateIR__CreateIR_StatementSeq_RepeatStatm(OOC_AST__RepeatStatm repeatStatm) {
          register OOC_INT32 i0,i1,i2,i3;

          i0 = (OOC_INT32)b;
          i1 = (OOC_INT32)repeatStatm;
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 12070));
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 12078));
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12144))+4);
          i3 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq((OOC_AST__NodeList)i3);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12208))+12);
          i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i1);
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12041)))), OOC_IR__BuilderDesc_NewRepeatStatm)),OOC_IR__BuilderDesc_NewRepeatStatm)((OOC_IR__Builder)i0, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__StatementSeq)i3, (OOC_IR__Expression)i1);
          return (OOC_IR__Statement)i0;
          ;
        }

        
        OOC_IR__Statement OOC_AST_CreateIR__CreateIR_StatementSeq_WhileStatm(OOC_AST__WhileStatm whileStatm) {
          register OOC_INT32 i0,i1,i2,i3;

          i0 = (OOC_INT32)b;
          i1 = (OOC_INT32)whileStatm;
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 12368));
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 12375));
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12431))+4);
          i3 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i3);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12498))+12);
          i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq((OOC_AST__NodeList)i1);
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12341)))), OOC_IR__BuilderDesc_NewWhileStatm)),OOC_IR__BuilderDesc_NewWhileStatm)((OOC_IR__Builder)i0, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i3, (OOC_IR__StatementSeq)i1);
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
              i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12847))+4);
              i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 12850));
              i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 12864));
              i3 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i3);
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12881))+8);
              i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i1);
              i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12830)))), OOC_IR__BuilderDesc_NewTypeTest)),OOC_IR__BuilderDesc_NewTypeTest)((OOC_IR__Builder)i0, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i3, (OOC_IR__Expression)i1);
              return (OOC_IR__Expression)i0;
              ;
            }


          i0 = (OOC_INT32)withStatm;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12958))+4);
          i1 = i1!=(OOC_INT32)0;
          if (i1) goto l3;
          elseSeq = (OOC_IR__StatementSeq)(OOC_INT32)0;
          goto l4;
l3:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13021))+8);
          i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq((OOC_AST__NodeList)i1);
          elseSeq = (OOC_IR__StatementSeq)i1;
l4:
          _else = (OOC_IR__Statement)(OOC_INT32)0;
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13131));
          i0 = *(OOC_INT32*)(_check_pointer(i0, 13142));
          i0 = i0-4;
          i = i0;
          
l5_loop:
          i1 = (OOC_INT32)withStatm;
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 13207));
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 13217))+4);
          i1 = _check_pointer(i1, 13219);
          i2 = OOC_ARRAY_LENGTH(i1, 0);
          i0 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index((i0+1), i2, OOC_UINT32, 13219))*4);
          i0 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq_WithStatm_TypeTestExpr((OOC_AST__Operator)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13229)))), &_td_OOC_AST__OperatorDesc, 13229)));
          guard = (OOC_IR__Expression)i0;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13261)))), &_td_OOC_IR__TypeTestDesc);
          if (!i1) goto l8;
          i1 = (OOC_INT32)b;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 13330)))), OOC_IR__BuilderDesc_StartTypeGuard)),OOC_IR__BuilderDesc_StartTypeGuard)((OOC_IR__Builder)i1, (OOC_IR__TypeTest)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13357)))), &_td_OOC_IR__TypeTestDesc, 13357)), (void*)(OOC_INT32)&currentNamespace);
          i1 = (OOC_INT32)withStatm;
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 13431));
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 13441))+4);
          i2 = _check_pointer(i2, 13443);
          i3 = i;
          i4 = OOC_ARRAY_LENGTH(i2, 0);
          i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index((i3+3), i4, OOC_UINT32, 13443))*4);
          i2 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq((OOC_AST__NodeList)(_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 13453)))), &_td_OOC_AST__NodeListDesc, 13453)));
          region = (OOC_IR__StatementSeq)i2;
          i4 = (OOC_INT32)b;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 13478)))), OOC_IR__BuilderDesc_EndTypeGuard)),OOC_IR__BuilderDesc_EndTypeGuard)((OOC_IR__Builder)i4, (void*)(OOC_INT32)&currentNamespace);
          i4 = (OOC_INT32)b;
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 13588));
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 13599))+4);
          i1 = _check_pointer(i1, 13602);
          i5 = OOC_ARRAY_LENGTH(i1, 0);
          i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(i3, i5, OOC_UINT32, 13602))*4);
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 13610)))), &_td_OOC_AST__TerminalDesc, 13610)), 13619));
          i3 = (OOC_INT32)elseSeq;
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 13547)))), OOC_IR__BuilderDesc_NewWithStatm)),OOC_IR__BuilderDesc_NewWithStatm)((OOC_IR__Builder)i4, (OOC_Scanner_SymList__Symbol)i1, (OOC_IR__Expression)i0, (OOC_IR__StatementSeq)i2, (OOC_IR__StatementSeq)i3);
          _else = (OOC_IR__Statement)i0;
          i1 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__StatementSeq.baseTypes[0], 1);
          elseSeq = (OOC_IR__StatementSeq)i1;
          i1 = _check_pointer(i1, 13717);
          i2 = OOC_ARRAY_LENGTH(i1, 0);
          *(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 13717))*4) = i0;
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
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13972))+28);
              i1 = i1!=(OOC_INT32)0;
              if (i1) goto l3;
              return (OOC_IR__Expression)(OOC_INT32)0;
              goto l4;
l3:
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14024))+28);
              i0 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i0);
              return (OOC_IR__Expression)i0;
l4:
              _failed_function(13912); return 0;
              ;
            }


          i0 = (OOC_INT32)b;
          i1 = (OOC_INT32)forStatm;
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 14163));
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 14168));
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14226))+4);
          i3 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Designator((OOC_AST__Node)i3);
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14281))+12);
          i4 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i4);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14341))+20);
          i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i1);
          i5 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq_ForStatm_Step();
          i6 = (OOC_INT32)forStatm;
          i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 14446))+36);
          i6 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq((OOC_AST__NodeList)i6);
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14140)))), OOC_IR__BuilderDesc_NewForStatm)),OOC_IR__BuilderDesc_NewForStatm)((OOC_IR__Builder)i0, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__Expression)i3, (OOC_IR__Expression)i4, (OOC_IR__Expression)i1, (OOC_IR__Expression)i5, (OOC_IR__StatementSeq)i6);
          return (OOC_IR__Statement)i0;
          ;
        }

        
        OOC_IR__Statement OOC_AST_CreateIR__CreateIR_StatementSeq_IterateStatm(OOC_AST__IterateStatm iterStatm) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5;

          i0 = (OOC_INT32)b;
          i1 = (OOC_INT32)iterStatm;
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 14611));
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 14616));
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14701))+4);
          i4 = (OOC_INT32)currentSourceContext;
          i3 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Designator((OOC_AST__Node)i3);
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14761))+12);
          i5 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i5);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14829))+20);
          i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq((OOC_AST__NodeList)i1);
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14583)))), OOC_IR__BuilderDesc_NewIterateStatm)),OOC_IR__BuilderDesc_NewIterateStatm)((OOC_IR__Builder)i0, (OOC_Scanner_SymList__Symbol)i2, (OOC_SymbolTable__Item)i4, (OOC_IR__Expression)i3, (OOC_IR__Expression)i5, (OOC_IR__StatementSeq)i1);
          return (OOC_IR__Statement)i0;
          ;
        }

        
        OOC_IR__Statement OOC_AST_CreateIR__CreateIR_StatementSeq_LoopStatm(OOC_AST__LoopStatm loopStatm) {
          register OOC_INT32 i0,i1,i2;

          i0 = (OOC_INT32)b;
          i1 = (OOC_INT32)loopStatm;
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 14989));
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 14995));
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15057))+4);
          i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq((OOC_AST__NodeList)i1);
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14964)))), OOC_IR__BuilderDesc_NewLoopStatm)),OOC_IR__BuilderDesc_NewLoopStatm)((OOC_IR__Builder)i0, (OOC_Scanner_SymList__Symbol)i2, (OOC_IR__StatementSeq)i1);
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
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15367))+8);
          i1 = *(OOC_INT32*)(_check_pointer(i1, 15377));
          i1 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__CatchList.baseTypes[0], i1);
          catchList = (OOC_IR__CatchList)i1;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15425))+4);
          i2 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq((OOC_AST__NodeList)i2);
          statmSeq = (OOC_IR__StatementSeq)i2;
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15467))+8);
          i = 0;
          i3 = *(OOC_INT32*)(_check_pointer(i3, 15477));
          i4 = 0<i3;
          if (!i4) goto l12;
          i4=0;
l3_loop:
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15514))+8);
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 15524))+4);
          i5 = _check_pointer(i5, 15526);
          i6 = OOC_ARRAY_LENGTH(i5, 0);
          i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 15526))*4);
          i5 = _type_guard(i5, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 15534)))), &_td_OOC_AST__CatchDesc, 15534);
          _catch = (OOC_AST__Catch)i5;
          i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 15571))+4);
          i6 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i6);
          guard = (OOC_IR__Expression)i6;
          i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 15599))+12);
          i7 = i7==0;
          if (i7) goto l6;
          i7 = (OOC_INT32)b;
          i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 15735))+12);
          i8 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i8, 15741));
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 15702)))), OOC_IR__BuilderDesc_StartExceptionScope)),OOC_IR__BuilderDesc_StartExceptionScope)((OOC_IR__Builder)i7, (OOC_IR__Expression)i6, (OOC_Scanner_SymList__Symbol)i8, (void*)(OOC_INT32)&currentNamespace);
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 15810))+24);
          i5 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq((OOC_AST__NodeList)i5);
          catchStatm = (OOC_IR__StatementSeq)i5;
          i7 = (OOC_INT32)b;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 15835)))), OOC_IR__BuilderDesc_EndExceptionScope)),OOC_IR__BuilderDesc_EndExceptionScope)((OOC_IR__Builder)i7, (void*)(OOC_INT32)&currentNamespace);
          
          goto l7;
l6:
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 15662))+24);
          i5 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq((OOC_AST__NodeList)i5);
          catchStatm = (OOC_IR__StatementSeq)i5;
          
l7:
          i7 = _check_pointer(i1, 15918);
          i8 = OOC_ARRAY_LENGTH(i7, 0);
          i9 = (OOC_INT32)b;
          i5 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i9, 15926)))), OOC_IR__BuilderDesc_NewCatchClause)),OOC_IR__BuilderDesc_NewCatchClause)((OOC_IR__Builder)i9, (OOC_IR__Expression)i6, (OOC_IR__StatementSeq)i5);
          *(OOC_INT32*)(i7+(_check_index(i4, i8, OOC_UINT32, 15918))*4) = i5;
          i4 = i4+1;
          i = i4;
          i5 = i4<i3;
          if (i5) goto l3_loop;
l12:
          i3 = (OOC_INT32)b;
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 16012));
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 16016));
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 15991)))), OOC_IR__BuilderDesc_NewTryStatm)),OOC_IR__BuilderDesc_NewTryStatm)((OOC_IR__Builder)i3, (OOC_Scanner_SymList__Symbol)i0, (OOC_IR__StatementSeq)i2, (OOC_IR__CatchList)i1);
          return (OOC_IR__Statement)i0;
          ;
        }


      count = 0;
      i0 = (OOC_INT32)statmSeq;
      i1 = *(OOC_INT32*)(_check_pointer(i0, 16201));
      i = 0;
      i2 = 0<i1;
      if (i2) goto l3;
      i1=0;
      goto l13;
l3:
      i2=0;i3=0;
l4_loop:
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16237))+4);
      i4 = _check_pointer(i4, 16240);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i2, i5, OOC_UINT32, 16240))*4);
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
      i0 = *(OOC_INT32*)(_check_pointer(i0, 16378));
      i1 = 0<i0;
      if (!i1) goto l79;
      i1=0;
l16_loop:
      i2 = (OOC_INT32)statmSeq;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 16414))+4);
      i3 = _check_pointer(i3, 16417);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i1, i4, OOC_UINT32, 16417))*4);
      i3 = i3!=0;
      if (!i3) goto l74;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 16456))+4);
      i2 = _check_pointer(i2, 16459);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i1 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i1, i3, OOC_UINT32, 16459))*4);
      n = (OOC_AST__Node)i1;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16480)))), &_td_OOC_AST__ProcedureCallDesc);
      if (i2) goto l69;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16569)))), &_td_OOC_AST__ReturnStatmDesc);
      if (i2) goto l67;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16637)))), &_td_OOC_AST__AssignmentDesc);
      if (i2) goto l65;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16832)))), &_td_OOC_AST__IfStatmDesc);
      if (i2) goto l63;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16896)))), &_td_OOC_AST__CaseStatmDesc);
      if (i2) goto l61;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16980)))), &_td_OOC_AST__WithStatmDesc);
      if (i2) goto l59;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17048)))), &_td_OOC_AST__RepeatStatmDesc);
      if (i2) goto l57;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17134)))), &_td_OOC_AST__WhileStatmDesc);
      if (i2) goto l55;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17204)))), &_td_OOC_AST__ForStatmDesc);
      if (i2) goto l53;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17271)))), &_td_OOC_AST__IterateStatmDesc);
      if (i2) goto l51;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17346)))), &_td_OOC_AST__LoopStatmDesc);
      if (i2) goto l49;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17415)))), &_td_OOC_AST__ExitStatmDesc);
      if (i2) goto l47;
      i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17496)))), &_td_OOC_AST__TryStatmDesc);
      if (i2) goto l45;
      Log__Type("++ Unknown type in StatementSeq", 32, (void*)i1);
      _assert(0u, 127, 17648);
      goto l70;
l45:
      i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq_TryStatm((OOC_AST__TryStatm)i1);
      statm = (OOC_IR__Statement)i1;
      goto l70;
l47:
      i2 = (OOC_INT32)b;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 17468));
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 17474));
      i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 17456)))), OOC_IR__BuilderDesc_NewExit)),OOC_IR__BuilderDesc_NewExit)((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i1);
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
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 16691));
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 16745));
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 16797));
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 16757))+4);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 16809))+8);
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 16703));
      i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq_Assignment((OOC_AST__Node)i2, (OOC_AST__Node)i3, (OOC_AST__Node)i1);
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
      i2 = _check_pointer(i2, 17773);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i4 = count;
      *(OOC_INT32*)(i2+(_check_index(i4, i3, OOC_UINT32, 17773))*4) = i1;
      count = (i4+1);
l74:
      i1 = i;
      i1 = i1+2;
      i = i1;
      i2 = i1<i0;
      if (i2) goto l16_loop;
l79:
      i0 = (OOC_INT32)statmSeqIR;
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 17887)), 0);
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
      i4 = _check_pointer(i1, 18068);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i6 = _check_pointer(i0, 18085);
      i7 = OOC_ARRAY_LENGTH(i6, 0);
      i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i3, i7, OOC_UINT32, 18085))*4);
      *(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 18068))*4) = i6;
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

      i0 = (OOC_INT32)b;
      i1 = (OOC_INT32)constExpr;
      i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i1);
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18313)))), OOC_IR__BuilderDesc_AssertConst)),OOC_IR__BuilderDesc_AssertConst)((OOC_IR__Builder)i0, (OOC_IR__Expression)i1);
      expr = (OOC_IR__Expression)i0;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18403))+4);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18384)))), &_td_OOC_IR__ConstDesc, 18384)), 18390))+8);
      i2 = (OOC_INT32)constDecl;
      OOC_SymbolTable__ConstDeclDesc_SetValueType((OOC_SymbolTable__ConstDecl)i2, (Object_Boxed__Object)i0, (OOC_SymbolTable__PredefType)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 18414)))), &_td_OOC_SymbolTable__PredefTypeDesc, 18414)));
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
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 18860))+60);
      currentNamespace = (OOC_SymbolTable__Namespace)i3;
      currentSourceContext = (OOC_SymbolTable__Item)i2;
      i3 = (OOC_INT32)procCode;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 18931))+28);
      i4 = i4==(OOC_INT32)0;
      if (i4) goto l3;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 18957))+28);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 18963))+8);
      i4 = i4==(OOC_INT32)0;
      
      goto l5;
l3:
      i4=1u;
l5:
      if (i4) goto l7;
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 19065))+28);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 19071))+8);
      i4 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq((OOC_AST__NodeList)i4);
      statmSeq = (OOC_IR__StatementSeq)i4;
      
      goto l8;
l7:
      i4 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__StatementSeq.baseTypes[0], 0);
      statmSeq = (OOC_IR__StatementSeq)i4;
      
l8:
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 19112))+28);
      i5 = i5==(OOC_INT32)0;
      if (i5) goto l11;
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 19196))+28);
      i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 19202))+12);
      i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 19207));
      endOfBody = (OOC_Scanner_SymList__Symbol)i5;
      
      goto l12;
l11:
      endOfBody = (OOC_Scanner_SymList__Symbol)(OOC_INT32)0;
      i5=(OOC_INT32)0;
l12:
      currentNamespace = (OOC_SymbolTable__Namespace)i0;
      currentSourceContext = (OOC_SymbolTable__Item)i1;
      i0 = (OOC_INT32)b;
      i1 = _check_pointer(i0, 19334);
      i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 19358));
      i6 = _check_pointer(i6, 19364);
      i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 19471))+28);
      i7 = i7!=(OOC_INT32)0;
      if (i7) goto l15;
      i3=0u;
      goto l16;
l15:
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 19526))+28);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 19531))+4);
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
          i0 = *(OOC_UINT8*)((_check_pointer(i0, 19895))+49);
          return (!i0);
          ;
        }

        
        OOC_INT32 OOC_AST_CreateIR__CreateIR_Module_CountProcs(OOC_SymbolTable__Item item) {
          register OOC_INT32 i0,i1,i2;
          OOC_INT32 count;
          OOC_SymbolTable__Item nested;

          i0 = (OOC_INT32)item;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20071)))), &_td_OOC_SymbolTable__ProcDeclDesc);
          if (i1) goto l3;
          i1=0u;
          goto l5;
l3:
          i1 = OOC_AST_CreateIR__CreateIR_Module_IsProc((OOC_SymbolTable__ProcDecl)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20107)))), &_td_OOC_SymbolTable__ProcDeclDesc, 20107)));
          
l5:
          if (i1) goto l7;
          count = 0;
          i1=0;
          goto l8;
l7:
          count = 1;
          i1=1;
l8:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20223))+8);
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
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 20340));
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
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 20526)))), &_td_OOC_SymbolTable__ProcDeclDesc);
          if (!i1) goto l6;
          i1 = OOC_AST_CreateIR__CreateIR_Module_IsProc((OOC_SymbolTable__ProcDecl)i0);
          if (!i1) goto l6;
          i1 = (OOC_INT32)procList;
          i1 = _check_pointer(i1, 20596);
          i2 = OOC_ARRAY_LENGTH(i1, 0);
          i3 = count;
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20627))+72);
          i4 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_ProcDecl((OOC_SymbolTable__ProcDecl)i0, (OOC_AST__ProcDecl)(_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 20640)))), &_td_OOC_AST__ProcDeclDesc, 20640)));
          i5 = count;
          *(OOC_INT32*)(i1+(_check_index(i3, i2, OOC_UINT32, 20596))*4) = i4;
          count = (i5+1);
l6:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20789))+8);
          nested = (OOC_SymbolTable__Item)i0;
          i1 = i0!=(OOC_INT32)0;
          if (!i1) goto l14;
l9_loop:
          OOC_AST_CreateIR__CreateIR_Module_TraverseProcedures((OOC_SymbolTable__Item)i0);
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 20901));
          nested = (OOC_SymbolTable__Item)i0;
          i1 = i0!=(OOC_INT32)0;
          if (i1) goto l9_loop;
l14:
          return;
          ;
        }


      i0 = (OOC_INT32)moduleAST;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20998))+20);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 21004));
      declSeq = (OOC_AST__NodeList)i0;
      i0 = (OOC_INT32)moduleDecl;
      i0 = OOC_AST_CreateIR__CreateIR_Module_CountProcs((OOC_SymbolTable__Item)i0);
      procList = (OOC_IR__ProcedureList)((OOC_INT32)RT0__NewObject(_td_OOC_IR__ProcedureList.baseTypes[0], i0));
      count = 0;
      i0 = (OOC_INT32)moduleDecl;
      OOC_AST_CreateIR__CreateIR_Module_TraverseProcedures((OOC_SymbolTable__Item)i0);
      i0 = (OOC_INT32)moduleAST;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21146))+20);
      i1 = i1==0;
      if (i1) goto l3;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21173))+20);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 21179))+8);
      i1 = i1==0;
      
      goto l5;
l3:
      i1=1u;
l5:
      if (i1) goto l7;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21282))+20);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 21288))+8);
      i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_StatementSeq((OOC_AST__NodeList)i1);
      statmSeq = (OOC_IR__StatementSeq)i1;
      
      goto l8;
l7:
      i1 = (OOC_INT32)RT0__NewObject(_td_OOC_IR__StatementSeq.baseTypes[0], 0);
      statmSeq = (OOC_IR__StatementSeq)i1;
      
l8:
      i2 = (OOC_INT32)b;
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 21354));
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21487))+20);
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 21493))+12);
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 21362));
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 21498));
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21378))+28);
      i5 = (OOC_INT32)moduleDecl;
      i6 = (OOC_INT32)procList;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 21332)))), OOC_IR__BuilderDesc_NewModule)),OOC_IR__BuilderDesc_NewModule)((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i3, (OOC_Scanner_InputBuffer__CharArray)i0, (OOC_SymbolTable__Module)i5, (OOC_IR__ProcedureList)i6, (OOC_IR__StatementSeq)i1, (OOC_Scanner_SymList__Symbol)i4);
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
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22141))+8);
          nested = (OOC_SymbolTable__Item)i0;
          i1 = i0!=(OOC_INT32)0;
          if (!i1) goto l8;
l3_loop:
          OOC_AST_CreateIR__CreateIR_TranslateEmbeddedExpr((OOC_SymbolTable__Item)i0);
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 22256));
          nested = (OOC_SymbolTable__Item)i0;
          i1 = i0!=(OOC_INT32)0;
          if (i1) goto l3_loop;
l8:
          return;
          ;
        }


      i0 = (OOC_INT32)item;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22338)))), &_td_OOC_SymbolTable__RecordDesc);
      if (!i1) goto l3;
      OOC_AST_CreateIR__CreateIR_TranslateEmbeddedExpr_TraverseNested((OOC_SymbolTable__Item)i0);
l3:
      i0 = (OOC_INT32)item;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22600)))), &_td_OOC_SymbolTable__ArrayDesc);
      if (i1) goto l9;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22928)))), &_td_OOC_SymbolTable__ConstDeclDesc);
      if (!i1) goto l17;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22976))+56);
      OOC_AST_CreateIR__CreateIR_ConstDecl((OOC_SymbolTable__ConstDecl)i0, (OOC_AST__Node)i1);
      goto l17;
l9:
      i1 = *(OOC_UINT8*)((_check_pointer(i0, 22631))+40);
      i1 = !i1;
      if (!i1) goto l17;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22678))+56);
      i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR_Expr((OOC_AST__Node)i1);
      expr = (OOC_IR__Expression)i1;
      i2 = (OOC_INT32)b;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 22715))+20);
      i2 = i1==i2;
      if (i2) goto l14;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 22845)))), &_td_OOC_IR__ConstDesc, 22845)), 22851))+8);
      i1 = Object_BigInt__BigIntDesc_ToLongInt((Object_BigInt__BigInt)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 22865)))), &_td_Object_BigInt__BigIntDesc, 22865)));
      OOC_SymbolTable__ArrayDesc_SetLength((OOC_SymbolTable__Array)i0, i1);
      goto l17;
l14:
      OOC_SymbolTable__ArrayDesc_SetLength((OOC_SymbolTable__Array)i0, 1);
l17:
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23051)))), &_td_OOC_SymbolTable__TypeDesc);
      if (!i1) goto l23;
      i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23083)))), &_td_OOC_SymbolTable__TypeNameDesc));
      if (!i1) goto l23;
      OOC_SymbolTable_TypeRules__AllocateType((OOC_SymbolTable__Type)i0);
l23:
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23205)))), &_td_OOC_SymbolTable__ProcDeclDesc);
      if (i1) goto l29;
      i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23561)))), &_td_OOC_SymbolTable__RecordDesc));
      if (!i1) goto l30;
      OOC_AST_CreateIR__CreateIR_TranslateEmbeddedExpr_TraverseNested((OOC_SymbolTable__Item)i0);
      goto l30;
l29:
      i1 = (OOC_INT32)currentNamespace;
      oldNamespace = (OOC_SymbolTable__Namespace)i1;
      i1 = (OOC_INT32)currentSourceContext;
      oldSourceContext = (OOC_SymbolTable__Item)i1;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23347))+60);
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
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23746))+48);
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
