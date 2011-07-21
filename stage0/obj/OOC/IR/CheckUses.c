#include <OOC/IR/CheckUses.d>
#include <__oo2c.h>
#include <setjmp.h>

void OOC_IR_CheckUses__ErrorContextDesc_GetTemplate(OOC_IR_CheckUses__ErrorContext context, Msg__Msg msg, Msg__LString templ, OOC_LEN templ_0d) {
  register OOC_INT32 i0,i1;
  OOC_CHAR16 t[128];

  i0 = (OOC_INT32)msg;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 5016))+8);
  switch (i1) {
  case 1:
    _copy_16((const void*)((OOC_CHAR16[]){87,97,114,110,105,110,103,58,32,85,110,100,101,102,105,110,101,100,32,118,97,114,105,97,98,108,101,0}),(void*)(OOC_INT32)t,128);
    goto l9;
  case 2:
    _copy_16((const void*)((OOC_CHAR16[]){87,97,114,110,105,110,103,58,32,86,97,114,105,97,98,108,101,32,109,97,121,32,98,101,32,117,110,100,101,102,105,110,101,100,0}),(void*)(OOC_INT32)t,128);
    goto l9;
  case 3:
    _copy_16((const void*)((OOC_CHAR16[]){87,97,114,110,105,110,103,58,32,85,110,114,101,97,99,104,97,98,108,101,32,99,111,100,101,0}),(void*)(OOC_INT32)t,128);
    goto l9;
  case 4:
    _copy_16((const void*)((OOC_CHAR16[]){87,97,114,110,105,110,103,58,32,67,111,110,116,114,111,108,32,109,97,121,32,114,101,97,99,104,32,101,110,100,32,111,102,32,102,117,110,99,116,105,111,110,32,112,114,111,99,101,100,117,114,101,0}),(void*)(OOC_INT32)t,128);
    goto l9;
  case 5:
    _copy_16((const void*)((OOC_CHAR16[]){87,97,114,110,105,110,103,58,32,84,121,112,101,32,116,101,115,116,32,109,97,100,101,32,117,110,114,101,97,99,104,97,98,108,101,32,98,121,32,112,114,101,99,101,101,100,105,110,103,32,103,117,97,114,100,0}),(void*)(OOC_INT32)t,128);
    goto l9;
  case 6:
    _copy_16((const void*)((OOC_CHAR16[]){87,97,114,110,105,110,103,58,32,67,97,108,108,101,101,32,109,97,121,32,114,101,97,100,32,117,110,100,101,102,105,110,101,100,32,118,97,114,105,97,98,108,101,32,96,36,123,110,97,109,101,125,39,0}),(void*)(OOC_INT32)t,128);
    goto l9;
  default:
    _failed_case(i1, 5008);
    goto l9;
  }
l9:
  i1 = (OOC_INT32)context;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5578)))), OOC_Error__ContextDesc_BaseTemplate)),OOC_Error__ContextDesc_BaseTemplate)((OOC_Error__Context)i1, (Msg__Msg)i0, (void*)(OOC_INT32)t, 128, (void*)(OOC_INT32)templ, templ_0d);
  return;
  ;
}

void OOC_IR_CheckUses__VisitorCallsDesc_VisitCall(OOC_IR_CheckUses__VisitorCalls v, OOC_IR__Call call) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_SymbolTable__Declaration procDecl;
  Object__Object obj;

  i0 = (OOC_INT32)call;
  i1 = (OOC_INT32)v;
  OOC_IR_VisitAll__VisitorDesc_VisitCall((OOC_IR_VisitAll__Visitor)i1, (OOC_IR__Call)i0);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5797))+8);
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 5805)))), &_td_OOC_IR__ProcedureRefDesc);
  if (i2) goto l3;
  i2=0u;
  goto l5;
l3:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5858))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 5869)))), &_td_OOC_IR__ProcedureRefDesc, 5869)), 5882))+8);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5835))+4);
  i2 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i3, (Object__Object)i2);
  
l5:
  if (!i2) goto l7;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5916))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5927)))), &_td_OOC_IR__ProcedureRefDesc, 5927)), 5940))+8);
  procDecl = (OOC_SymbolTable__Declaration)i0;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5961))+4);
  i0 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i2, (Object__Object)i0);
  obj = (Object__Object)i0;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5998)))), &_td_OOC_IR_CheckUses__ProcDataDesc, 5998)), 6007));
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 6024));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5998)))), &_td_OOC_IR_CheckUses__ProcDataDesc, 5998)), 6007));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 6015)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i0, (Object__Object)i1);
l7:
  return;
  ;
}

static ADT_Dictionary__Dictionary OOC_IR_CheckUses__KnownProcs(OOC_IR__Module module) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  ADT_Dictionary__Dictionary knownProcs;
  OOC_INT32 i;
  OOC_IR_CheckUses__ProcData pd;
  OOC_IR_CheckUses__VisitorCalls v;

  i0 = (OOC_INT32)ADT_Dictionary__New();
  knownProcs = (ADT_Dictionary__Dictionary)i0;
  i1 = (OOC_INT32)module;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6466))+8);
  i = 0;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 6475)), 0);
  i3 = 0<i2;
  if (!i3) goto l8;
  i3=0;
l3_loop:
  i4 = (OOC_INT32)RT0__NewObject(_td_OOC_IR_CheckUses__ProcData.baseTypes[0]);
  pd = (OOC_IR_CheckUses__ProcData)i4;
  i5 = (OOC_INT32)ADT_ArrayList__New(4);
  *(OOC_INT32*)(_check_pointer(i4, 6506)) = i5;
  i5 = (OOC_INT32)ADT_Dictionary_IntValue__New();
  *(OOC_INT32*)((_check_pointer(i4, 6544))+4) = i5;
  *(OOC_UINT8*)((_check_pointer(i4, 6577))+8) = 1u;
  *(OOC_UINT8*)((_check_pointer(i4, 6606))+9) = 0u;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6657))+8);
  i5 = _check_pointer(i5, 6666);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 6666))*4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 6669))+4);
  ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i0, (Object__Object)i5, (Object__Object)i4);
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l3_loop;
l8:
  i2 = (OOC_INT32)RT0__NewObject(_td_OOC_IR_CheckUses__VisitorCalls.baseTypes[0]);
  v = (OOC_IR_CheckUses__VisitorCalls)i2;
  OOC_IR_VisitAll__InitVisitor((OOC_IR_VisitAll__Visitor)i2);
  *(OOC_INT32*)((_check_pointer(i2, 6737))+4) = i0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6793))+8);
  i = 0;
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 6802)), 0);
  i4 = 0<i3;
  if (!i4) goto l16;
  i4=0;
l11_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6837))+8);
  i5 = _check_pointer(i5, 6846);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 6846))*4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 6849))+4);
  *(OOC_INT32*)(_check_pointer(i2, 6817)) = i5;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6868))+8);
  i5 = _check_pointer(i5, 6877);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 6877))*4);
  OOC_IR__ProcedureDesc_Accept((OOC_IR__Procedure)i5, (OOC_IR__Visitor)i2);
  i4 = i4+1;
  i = i4;
  i5 = i4<i3;
  if (i5) goto l11_loop;
l16:
  return (ADT_Dictionary__Dictionary)i0;
  ;
}

static OOC_IR_CheckUses__Def OOC_IR_CheckUses__NewDef(void) {
  register OOC_INT32 i0,i1;
  OOC_IR_CheckUses__Def def;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_IR_CheckUses__Def.baseTypes[0]);
  def = (OOC_IR_CheckUses__Def)i0;
  i1 = (OOC_INT32)ADT_Dictionary_IntValue__New();
  *(OOC_INT32*)(_check_pointer(i0, 7020)) = i1;
  *(OOC_UINT8*)((_check_pointer(i0, 7052))+4) = 0u;
  return (OOC_IR_CheckUses__Def)i0;
  ;
}

OOC_IR_CheckUses__Def OOC_IR_CheckUses__DefDesc_Copy(OOC_IR_CheckUses__Def def) {
  register OOC_INT32 i0,i1,i2;
  OOC_IR_CheckUses__Def def2;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_IR_CheckUses__Def.baseTypes[0]);
  def2 = (OOC_IR_CheckUses__Def)i0;
  i1 = (OOC_INT32)def;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 7205));
  i2 = (OOC_INT32)ADT_Dictionary_IntValue__DictionaryDesc_Copy((ADT_Dictionary_IntValue__Dictionary)i2);
  *(OOC_INT32*)(_check_pointer(i0, 7192)) = i2;
  i1 = *(OOC_UINT8*)((_check_pointer(i1, 7247))+4);
  *(OOC_UINT8*)((_check_pointer(i0, 7228))+4) = i1;
  return (OOC_IR_CheckUses__Def)i0;
  ;
}

OOC_INT32 OOC_IR_CheckUses__DefDesc_GetClass(OOC_IR_CheckUses__Def def, OOC_SymbolTable__Item var) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)def;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7364));
  i2 = (OOC_INT32)var;
  i1 = ADT_Dictionary_IntValue__DictionaryDesc_HasKey((ADT_Dictionary_IntValue__Dictionary)i1, (Object__Object)i2);
  if (i1) goto l3;
  return 0;
  goto l4;
l3:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7404));
  i0 = ADT_Dictionary_IntValue__DictionaryDesc_Get((ADT_Dictionary_IntValue__Dictionary)i0, (Object__Object)i2);
  return i0;
l4:
  _failed_function(7312); return 0;
  ;
}

void OOC_IR_CheckUses__DefDesc_SetClass(OOC_IR_CheckUses__Def def, OOC_SymbolTable__Item var, OOC_INT32 _class) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)def;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7557));
  i1 = (OOC_INT32)var;
  i2 = _class;
  ADT_Dictionary_IntValue__DictionaryDesc_Set((ADT_Dictionary_IntValue__Dictionary)i0, (Object__Object)i1, i2);
  return;
  ;
}

void OOC_IR_CheckUses__DefDesc_Merge(OOC_IR_CheckUses__Def def, OOC_IR_CheckUses__Def def2) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  Object__ObjectArrayPtr k;
  OOC_INT32 i;
  OOC_SymbolTable__Item v;
  auto OOC_INT32 OOC_IR_CheckUses__DefDesc_Merge_Merge(OOC_INT32 a, OOC_INT32 b);
    
    OOC_INT32 OOC_IR_CheckUses__DefDesc_Merge_Merge(OOC_INT32 a, OOC_INT32 b) {
      register OOC_INT32 i0,i1;

      i0 = a;
      i1 = b;
      i1 = i0==i1;
      if (i1) goto l3;
      i1=0u;
      goto l5;
l3:
      i1 = i0!=1;
      
l5:
      if (i1) goto l7;
      return 1;
      goto l8;
l7:
      return i0;
l8:
      _failed_function(7719); return 0;
      ;
    }


  i0 = (OOC_INT32)def;
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 7912))+4);
  if (i1) goto l22;
  i1 = (OOC_INT32)def2;
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 8026))+4);
  i2 = !i2;
  if (!i2) goto l23;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 8084));
  i2 = (OOC_INT32)ADT_Dictionary_IntValue__DictionaryDesc_Keys((ADT_Dictionary_IntValue__Dictionary)i2);
  k = (Object__ObjectArrayPtr)i2;
  i = 0;
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i2, 8124)), 0);
  i4 = 0<i3;
  if (!i4) goto l12;
  i4=0;
l7_loop:
  i5 = _check_pointer(i2, 8146);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 8146))*4);
  i5 = _type_guard(i5, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 8154)))), &_td_OOC_SymbolTable__ItemDesc, 8154);
  v = (OOC_SymbolTable__Item)i5;
  i6 = OOC_IR_CheckUses__DefDesc_GetClass((OOC_IR_CheckUses__Def)i1, (OOC_SymbolTable__Item)i5);
  i7 = OOC_IR_CheckUses__DefDesc_GetClass((OOC_IR_CheckUses__Def)i0, (OOC_SymbolTable__Item)i5);
  i6 = OOC_IR_CheckUses__DefDesc_Merge_Merge(i7, i6);
  OOC_IR_CheckUses__DefDesc_SetClass((OOC_IR_CheckUses__Def)i0, (OOC_SymbolTable__Item)i5, i6);
  i4 = i4+1;
  i = i4;
  i5 = i4<i3;
  if (i5) goto l7_loop;
l12:
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 8261));
  i2 = (OOC_INT32)ADT_Dictionary_IntValue__DictionaryDesc_Keys((ADT_Dictionary_IntValue__Dictionary)i2);
  k = (Object__ObjectArrayPtr)i2;
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i2, 8301)), 0);
  i = 0;
  i4 = 0<i3;
  if (!i4) goto l23;
  i4=0;
l15_loop:
  i5 = _check_pointer(i2, 8323);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 8323))*4);
  i5 = _type_guard(i5, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 8331)))), &_td_OOC_SymbolTable__ItemDesc, 8331);
  v = (OOC_SymbolTable__Item)i5;
  i6 = OOC_IR_CheckUses__DefDesc_GetClass((OOC_IR_CheckUses__Def)i1, (OOC_SymbolTable__Item)i5);
  i7 = OOC_IR_CheckUses__DefDesc_GetClass((OOC_IR_CheckUses__Def)i0, (OOC_SymbolTable__Item)i5);
  i6 = OOC_IR_CheckUses__DefDesc_Merge_Merge(i7, i6);
  OOC_IR_CheckUses__DefDesc_SetClass((OOC_IR_CheckUses__Def)i0, (OOC_SymbolTable__Item)i5, i6);
  i4 = i4+1;
  i = i4;
  i5 = i4<i3;
  if (i5) goto l15_loop;
  goto l23;
l22:
  i1 = (OOC_INT32)def2;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 7953));
  i2 = (OOC_INT32)ADT_Dictionary_IntValue__DictionaryDesc_Copy((ADT_Dictionary_IntValue__Dictionary)i2);
  *(OOC_INT32*)(_check_pointer(i0, 7939)) = i2;
  i1 = *(OOC_UINT8*)((_check_pointer(i1, 7997))+4);
  *(OOC_UINT8*)((_check_pointer(i0, 7977))+4) = i1;
l23:
  return;
  ;
}

void OOC_IR_CheckUses__DefDesc_Unreachable(OOC_IR_CheckUses__Def def) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)def;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 8542));
  ADT_Dictionary_IntValue__DictionaryDesc_Clear((ADT_Dictionary_IntValue__Dictionary)i1);
  *(OOC_UINT8*)((_check_pointer(i0, 8565))+4) = 1u;
  return;
  ;
}

static OOC_IR_CheckUses__Def OOC_IR_CheckUses__NewUnreachableDef(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)OOC_IR_CheckUses__NewDef();
  OOC_IR_CheckUses__DefDesc_Unreachable((OOC_IR_CheckUses__Def)i0);
  return (OOC_IR_CheckUses__Def)i0;
  ;
}

static Msg__Msg OOC_IR_CheckUses__WarnSymE(OOC_Error__List errList, OOC_Config_Pragmas__History pragmaHistory, OOC_Scanner_SymList__Symbol sym, OOC_INT32 code) {
  register OOC_INT32 i0,i1,i2,i3;
  Config__Variable value;
  Msg__Msg e;

  i0 = (OOC_INT32)sym;
  i1 = (OOC_INT32)OOC_Config_StdPragmas__warnings;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 9007))+4);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 9017))+16);
  i3 = (OOC_INT32)pragmaHistory;
  i1 = (OOC_INT32)OOC_Config_Pragmas__HistoryDesc_GetValue((OOC_Config_Pragmas__History)i3, (Object__String)i1, i2);
  value = (Config__Variable)i1;
  i1 = *(OOC_UINT8*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9044)))), &_td_Config__BooleanVarDesc, 9044)), 9055));
  if (i1) goto l3;
  return (Msg__Msg)0;
  goto l4;
l3:
  i1 = (OOC_INT32)OOC_IR_CheckUses__checkUsesContext;
  i2 = code;
  i1 = (OOC_INT32)OOC_Error__New((OOC_Error__Context)i1, i2);
  e = (Msg__Msg)i1;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 9146))+16);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9122)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i1, "pos", 4, i2);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 9185))+20);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9160)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i1, "line", 5, i2);
  i0 = *(OOC_INT32*)((_check_pointer(i0, 9227))+24);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9200)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i1, "column", 7, i0);
  i0 = (OOC_INT32)errList;
  OOC_Error__ListDesc_Append((OOC_Error__List)i0, (Msg__Msg)i1);
  return (Msg__Msg)i1;
l4:
  _failed_function(8768); return 0;
  ;
}

static void OOC_IR_CheckUses__WarnSym(OOC_Error__List errList, OOC_Config_Pragmas__History pragmaHistory, OOC_Scanner_SymList__Symbol sym, OOC_INT32 code) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = code;
  i1 = (OOC_INT32)sym;
  i2 = (OOC_INT32)pragmaHistory;
  i3 = (OOC_INT32)errList;
  i0 = (OOC_INT32)OOC_IR_CheckUses__WarnSymE((OOC_Error__List)i3, (OOC_Config_Pragmas__History)i2, (OOC_Scanner_SymList__Symbol)i1, i0);
  return;
  ;
}

static void OOC_IR_CheckUses__WarnSymV(OOC_IR_CheckUses__Visitor v, OOC_Scanner_SymList__Symbol sym, OOC_INT32 code, OOC_SymbolTable__VarDecl varDecl) {
  register OOC_INT32 i0,i1,i2,i3;
  Msg__Msg e;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9721))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9710));
  i2 = (OOC_INT32)sym;
  i3 = code;
  i0 = (OOC_INT32)OOC_IR_CheckUses__WarnSymE((OOC_Error__List)i0, (OOC_Config_Pragmas__History)i1, (OOC_Scanner_SymList__Symbol)i2, i3);
  e = (Msg__Msg)i0;
  i1 = i0!=0;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)varDecl;
  i1 = i1!=0;
  
l5:
  if (!i1) goto l7;
  i1 = (OOC_INT32)varDecl;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 9845))+20);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 9850))+12);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 9845))+20);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 9850))+12);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 9854)), 0);
  i1 = (OOC_INT32)Msg__GetStringPtr((void*)(_check_pointer(i1, 9854)), i2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9796)))), Msg__MsgDesc_SetStringAttrib)),Msg__MsgDesc_SetStringAttrib)((Msg__Msg)i0, "name", 5, (Msg__StringPtr)i1);
l7:
  return;
  ;
}

static OOC_CHAR8 OOC_IR_CheckUses__NonlocalVar(OOC_SymbolTable__ProcDecl localProc, OOC_SymbolTable__VarDecl varDecl) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)varDecl;
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 10103))+59);
  if (i1) goto l3;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10169)))), OOC_SymbolTable__ItemDesc_Procedure)),OOC_SymbolTable__ItemDesc_Procedure)((OOC_SymbolTable__Item)i0);
  i1 = (OOC_INT32)localProc;
  return (i0!=i1);
  goto l4;
l3:
  return 1u;
l4:
  _failed_function(9896); return 0;
  ;
}

void OOC_IR_CheckUses__ProcDataDesc_SetReadFlag(OOC_IR_CheckUses__ProcData pd, OOC_SymbolTable__VarDecl varDecl, OOC_INT32 flag) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT32 oldFlag;
  OOC_INT32 newFlag;

  i0 = (OOC_INT32)pd;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10411))+4);
  i2 = (OOC_INT32)varDecl;
  i1 = ADT_Dictionary_IntValue__DictionaryDesc_HasKey((ADT_Dictionary_IntValue__Dictionary)i1, (Object__Object)i2);
  if (i1) goto l3;
  oldFlag = 0;
  i1=0;
  goto l4;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10458))+4);
  i1 = ADT_Dictionary_IntValue__DictionaryDesc_Get((ADT_Dictionary_IntValue__Dictionary)i1, (Object__Object)i2);
  oldFlag = i1;
  
l4:
  i3 = flag;
  i3 = (_mod(i1,4))+i3*4;
  newFlag = i3;
  i4 = i3!=i1;
  if (!i4) goto l7;
  _assert((i1<i3), 127, 10641);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10676))+4);
  ADT_Dictionary_IntValue__DictionaryDesc_Set((ADT_Dictionary_IntValue__Dictionary)i1, (Object__Object)i2, i3);
  *(OOC_UINT8*)((_check_pointer(i0, 10714))+9) = 1u;
l7:
  return;
  ;
}

void OOC_IR_CheckUses__ProcDataDesc_SetWriteFlag(OOC_IR_CheckUses__ProcData pd, OOC_SymbolTable__Item item, OOC_INT32 flag) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT32 oldFlag;
  OOC_INT32 newFlag;

  i0 = (OOC_INT32)pd;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10890))+4);
  i2 = (OOC_INT32)item;
  i1 = ADT_Dictionary_IntValue__DictionaryDesc_HasKey((ADT_Dictionary_IntValue__Dictionary)i1, (Object__Object)i2);
  if (i1) goto l3;
  oldFlag = 0;
  i1=0;
  goto l4;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10934))+4);
  i1 = ADT_Dictionary_IntValue__DictionaryDesc_Get((ADT_Dictionary_IntValue__Dictionary)i1, (Object__Object)i2);
  oldFlag = i1;
  
l4:
  i3 = flag;
  i3 = i3+(i1>>2)*4;
  newFlag = i3;
  i4 = i3!=i1;
  if (!i4) goto l7;
  _assert((i1>i3), 127, 11116);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11151))+4);
  ADT_Dictionary_IntValue__DictionaryDesc_Set((ADT_Dictionary_IntValue__Dictionary)i1, (Object__Object)i2, i3);
  *(OOC_UINT8*)((_check_pointer(i0, 11186))+9) = 1u;
l7:
  return;
  ;
}

static void OOC_IR_CheckUses__EmitVarWarning(OOC_IR_CheckUses__Visitor v, OOC_SymbolTable__VarDecl varDecl, OOC_Scanner_SymList__Symbol sym, OOC_CHAR8 contextCall) {
  register OOC_INT32 i0,i1,i2;
  OOC_INT32 _class;
  auto OOC_CHAR8 OOC_IR_CheckUses__EmitVarWarning_LocalVar(OOC_SymbolTable__VarDecl varDecl);
    
    OOC_CHAR8 OOC_IR_CheckUses__EmitVarWarning_LocalVar(OOC_SymbolTable__VarDecl varDecl) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)varDecl;
      i1 = *(OOC_UINT8*)((_check_pointer(i0, 11471))+56);
      i1 = !i1;
      if (i1) goto l3;
      i0=0u;
      goto l4;
l3:
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11504)))), OOC_SymbolTable__ItemDesc_Procedure)),OOC_SymbolTable__ItemDesc_Procedure)((OOC_SymbolTable__Item)i0);
      i1 = (OOC_INT32)v;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11520))+20);
      i0 = i0==i1;
      
l4:
      return i0;
      ;
    }


  i0 = (OOC_INT32)varDecl;
  i0 = OOC_IR_CheckUses__EmitVarWarning_LocalVar((OOC_SymbolTable__VarDecl)i0);
  if (!i0) goto l28;
  i0 = (OOC_INT32)v;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 11603))+32);
  i1 = i1==0;
  if (i1) goto l12;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 12151))+32);
  i1 = i1==1;
  if (i1) goto l10;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12227))+28);
  i2 = (OOC_INT32)varDecl;
  i1 = OOC_IR_CheckUses__DefDesc_GetClass((OOC_IR_CheckUses__Def)i1, (OOC_SymbolTable__Item)i2);
  i1 = i1!=2;
  if (!i1) goto l28;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12300))+28);
  OOC_IR_CheckUses__DefDesc_SetClass((OOC_IR_CheckUses__Def)i0, (OOC_SymbolTable__Item)i2, 1);
  goto l28;
l10:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12180))+28);
  i1 = (OOC_INT32)varDecl;
  OOC_IR_CheckUses__DefDesc_SetClass((OOC_IR_CheckUses__Def)i0, (OOC_SymbolTable__Item)i1, 2);
  goto l28;
l12:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11640))+28);
  i2 = (OOC_INT32)varDecl;
  i1 = OOC_IR_CheckUses__DefDesc_GetClass((OOC_IR_CheckUses__Def)i1, (OOC_SymbolTable__Item)i2);
  _class = i1;
  switch (i1) {
  case 0:
    i1 = contextCall;
    if (i1) goto l17;
    i1 = (OOC_INT32)sym;
    OOC_IR_CheckUses__WarnSymV((OOC_IR_CheckUses__Visitor)i0, (OOC_Scanner_SymList__Symbol)i1, 1, (OOC_SymbolTable__VarDecl)i2);
    goto l28;
l17:
    i1 = (OOC_INT32)sym;
    OOC_IR_CheckUses__WarnSymV((OOC_IR_CheckUses__Visitor)i0, (OOC_Scanner_SymList__Symbol)i1, 6, (OOC_SymbolTable__VarDecl)i2);
    goto l28;
  case 1:
    i1 = contextCall;
    if (i1) goto l22;
    i1 = (OOC_INT32)sym;
    OOC_IR_CheckUses__WarnSymV((OOC_IR_CheckUses__Visitor)i0, (OOC_Scanner_SymList__Symbol)i1, 2, (OOC_SymbolTable__VarDecl)i2);
    goto l28;
l22:
    i1 = (OOC_INT32)sym;
    OOC_IR_CheckUses__WarnSymV((OOC_IR_CheckUses__Visitor)i0, (OOC_Scanner_SymList__Symbol)i1, 6, (OOC_SymbolTable__VarDecl)i2);
    goto l28;
  case 2:
    goto l28;
  default:
    _failed_case(i1, 11672);
    goto l28;
  }
l28:
  return;
  ;
}

static void OOC_IR_CheckUses__VisitVarDecl(OOC_IR_CheckUses__Visitor v, OOC_SymbolTable__VarDecl varDecl, OOC_Scanner_SymList__Symbol sym, OOC_CHAR8 contextCall) {
  register OOC_INT32 i0,i1,i2,i3;
  Object__Object pb;
  OOC_INT32 _class;

  i0 = (OOC_INT32)v;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 12566))+8);
  switch (i1) {
  case 0:
    i1 = *(OOC_INT8*)((_check_pointer(i0, 12611))+32);
    i1 = i1>=1;
    if (i1) goto l5;
    i1=0u;
    goto l7;
l5:
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12642))+20);
    i2 = (OOC_INT32)varDecl;
    i1 = OOC_IR_CheckUses__NonlocalVar((OOC_SymbolTable__ProcDecl)i1, (OOC_SymbolTable__VarDecl)i2);
    
l7:
    if (!i1) goto l30;
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12683))+12);
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12700))+20);
    i0 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i1, (Object__Object)i0);
    pb = (Object__Object)i0;
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12724)))), &_td_OOC_IR_CheckUses__ProcDataDesc, 12724)), 12733))+4);
    i1 = (OOC_INT32)varDecl;
    ADT_Dictionary_IntValue__DictionaryDesc_Set((ADT_Dictionary_IntValue__Dictionary)i0, (Object__Object)i1, 2);
    goto l30;
  case 1:
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12823))+20);
    i2 = (OOC_INT32)varDecl;
    i1 = OOC_IR_CheckUses__NonlocalVar((OOC_SymbolTable__ProcDecl)i1, (OOC_SymbolTable__VarDecl)i2);
    if (!i1) goto l30;
    i1 = *(OOC_INT8*)((_check_pointer(i0, 12862))+32);
    i1 = i1==0;
    if (i1) goto l22;
    i1 = *(OOC_INT8*)((_check_pointer(i0, 13052))+32);
    i1 = i1==1;
    if (i1) goto l20;
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13132))+28);
    i1 = OOC_IR_CheckUses__DefDesc_GetClass((OOC_IR_CheckUses__Def)i1, (OOC_SymbolTable__Item)i2);
    i1 = i1!=2;
    if (!i1) goto l30;
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13207))+28);
    OOC_IR_CheckUses__DefDesc_SetClass((OOC_IR_CheckUses__Def)i0, (OOC_SymbolTable__Item)i2, 1);
    goto l30;
l20:
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13083))+28);
    OOC_IR_CheckUses__DefDesc_SetClass((OOC_IR_CheckUses__Def)i0, (OOC_SymbolTable__Item)i2, 2);
    goto l30;
l22:
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12901))+28);
    i1 = OOC_IR_CheckUses__DefDesc_GetClass((OOC_IR_CheckUses__Def)i1, (OOC_SymbolTable__Item)i2);
    _class = i1;
    i1 = i1!=2;
    if (!i1) goto l30;
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12974))+24);
    OOC_IR_CheckUses__ProcDataDesc_SetReadFlag((OOC_IR_CheckUses__ProcData)i0, (OOC_SymbolTable__VarDecl)i2, 1);
    goto l30;
  case 2:
    i1 = (OOC_INT32)sym;
    i2 = contextCall;
    i3 = (OOC_INT32)varDecl;
    OOC_IR_CheckUses__EmitVarWarning((OOC_IR_CheckUses__Visitor)i0, (OOC_SymbolTable__VarDecl)i3, (OOC_Scanner_SymList__Symbol)i1, i2);
    goto l30;
  default:
    _failed_case(i1, 12560);
    goto l30;
  }
l30:
  return;
  ;
}

void OOC_IR_CheckUses__VisitorDesc_VisitVar(OOC_IR_CheckUses__Visitor v, OOC_IR__Var var) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)var;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13463))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13486));
  i2 = (OOC_INT32)v;
  OOC_IR_CheckUses__VisitVarDecl((OOC_IR_CheckUses__Visitor)i2, (OOC_SymbolTable__VarDecl)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 13473)))), &_td_OOC_SymbolTable__VarDeclDesc, 13473)), (OOC_Scanner_SymList__Symbol)i0, 0u);
  return;
  ;
}

void OOC_IR_CheckUses__VisitorDesc_VisitDeref(OOC_IR_CheckUses__Visitor v, OOC_IR__Deref deref) {
  register OOC_INT32 i0,i1,i2,i3;
  Object__Object pb;
  OOC_INT8 oldMode;

  i0 = (OOC_INT32)v;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 13641))+8);
  switch (i1) {
  case 0:
    i1 = *(OOC_INT8*)((_check_pointer(i0, 13686))+32);
    i1 = i1>=1;
    if (!i1) goto l12;
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13722))+12);
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13739))+20);
    i0 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i1, (Object__Object)i0);
    pb = (Object__Object)i0;
    i1 = (OOC_INT32)deref;
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13763)))), &_td_OOC_IR_CheckUses__ProcDataDesc, 13763)), 13772))+4);
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 13788))+4);
    ADT_Dictionary_IntValue__DictionaryDesc_Set((ADT_Dictionary_IntValue__Dictionary)i0, (Object__Object)i1, 2);
    goto l12;
  case 1:
  case 2:
    i1 = *(OOC_INT8*)((_check_pointer(i0, 13872))+32);
    i1 = i1==0;
    if (i1) goto l9;
    i1 = (OOC_INT32)deref;
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13944))+28);
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 13963))+4);
    OOC_IR_CheckUses__DefDesc_SetClass((OOC_IR_CheckUses__Def)i2, (OOC_SymbolTable__Item)i3, 2);
    i2 = *(OOC_INT8*)((_check_pointer(i0, 14000))+32);
    oldMode = i2;
    *(OOC_INT8*)((_check_pointer(i0, 14016))+32) = 0;
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14044))+8);
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14044))+8);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 14052)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i1, (OOC_IR__Visitor)i0);
    *(OOC_INT8*)((_check_pointer(i0, 14073))+32) = i2;
    goto l12;
l9:
    i1 = (OOC_INT32)deref;
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 13904))+8);
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 13904))+8);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 13912)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i1, (OOC_IR__Visitor)i0);
    goto l12;
  default:
    _failed_case(i1, 13635);
    goto l12;
  }
l12:
  return;
  ;
}

void OOC_IR_CheckUses__VisitorDesc_VisitIndex(OOC_IR_CheckUses__Visitor v, OOC_IR__Index index) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT8 oldMode;

  i0 = (OOC_INT32)v;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 14237))+32);
  oldMode = i1;
  i2 = (OOC_INT32)index;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14253))+8);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14253))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 14259)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i4, (OOC_IR__Visitor)i0);
  *(OOC_INT8*)((_check_pointer(i0, 14277))+32) = 0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14301))+12);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14301))+12);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 14307)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i2, (OOC_IR__Visitor)i0);
  *(OOC_INT8*)((_check_pointer(i0, 14325))+32) = i1;
  return;
  ;
}

void OOC_IR_CheckUses__VisitorDesc_VisitAdr(OOC_IR_CheckUses__Visitor v, OOC_IR__Adr adr) {

  return;
  ;
}

void OOC_IR_CheckUses__VisitorDesc_VisitCall(OOC_IR_CheckUses__Visitor v, OOC_IR__Call call) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11,i12,i13;
  OOC_INT8 oldMode;
  OOC_INT32 i;
  OOC_SymbolTable__ProcDecl callee;
  Object__Object obj;
  ADT_Dictionary_IntValue__Dictionary inout;
  ADT_ArrayList__ArrayList readList;
  ADT_ArrayList__ArrayList writeList;
  ADT_Dictionary_IntValue__Dictionary writeMaybeDict;
  OOC_IR__Expression design;
  OOC_INT32 _class;
  Object__ObjectArrayPtr k;
  OOC_SymbolTable__VarDecl varDecl;
  OOC_SymbolTable__Type type;

  i0 = (OOC_INT32)v;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 14861))+32);
  oldMode = i1;
  i2 = (OOC_INT32)call;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14876))+8);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14876))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 14883)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i4, (OOC_IR__Visitor)i0);
  i3 = *(OOC_INT8*)((_check_pointer(i0, 14910))+8);
  switch (i3) {
  case 0:
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14959))+8);
    i3 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 14967)))), &_td_OOC_IR__ProcedureRefDesc));
    if (i3) goto l5;
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 15003))+8);
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 15014)))), &_td_OOC_IR__ProcedureRefDesc, 15014)), 15027))+8);
    i3 = *(OOC_UINT8*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 15037)))), &_td_OOC_SymbolTable__ProcDeclDesc, 15037)), 15046))+52);
    
    goto l7;
l5:
    i3=1u;
l7:
    if (!i3) goto l9;
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15076))+24);
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 15090))+4);
    i4 = (OOC_INT32)OOC_IR_CheckUses__any;
    ADT_Dictionary_IntValue__DictionaryDesc_Set((ADT_Dictionary_IntValue__Dictionary)i3, (Object__Object)i4, 2);
l9:
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 15184))+12);
    i = 0;
    i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 15194)), 0);
    i4 = 0<i3;
    if (!i4) goto l131;
    i4=0;
l12_loop:
    i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 15218))+16);
    i5 = _check_pointer(i5, 15229);
    i6 = OOC_ARRAY_LENGTH(i5, 0);
    i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 15229))*4);
    i5 = i5!=(OOC_INT32)0;
    if (i5) goto l15;
    i5=0u;
    goto l17;
l15:
    i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 15246))+16);
    i5 = _check_pointer(i5, 15257);
    i6 = OOC_ARRAY_LENGTH(i5, 0);
    i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 15257))*4);
    i5 = *(OOC_UINT8*)((_check_pointer(i5, 15260))+59);
    
l17:
    if (i5) goto l19;
    *(OOC_INT8*)((_check_pointer(i0, 15481))+32) = 0;
    i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 15510))+12);
    i5 = _check_pointer(i5, 15520);
    i6 = OOC_ARRAY_LENGTH(i5, 0);
    i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 15510))+12);
    i7 = _check_pointer(i7, 15520);
    i8 = OOC_ARRAY_LENGTH(i7, 0);
    i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i4, i8, OOC_UINT32, 15520))*4);
    i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 15520))*4);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 15523)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i5, (OOC_IR__Visitor)i0);
    goto l23;
l19:
    i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 15296))+12);
    i5 = _check_pointer(i5, 15306);
    i6 = OOC_ARRAY_LENGTH(i5, 0);
    i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 15306))*4);
    i5 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 15310)))), &_td_OOC_IR__ConstDesc));
    if (!i5) goto l23;
    *(OOC_INT8*)((_check_pointer(i0, 15370))+32) = 1;
    i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 15402))+12);
    i5 = _check_pointer(i5, 15412);
    i6 = OOC_ARRAY_LENGTH(i5, 0);
    i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 15412))*4);
    i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 15402))+12);
    i6 = _check_pointer(i6, 15412);
    i7 = OOC_ARRAY_LENGTH(i6, 0);
    i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i4, i7, OOC_UINT32, 15412))*4);
    i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i6, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 15419)))), &_td_OOC_IR__AdrDesc, 15419)), 15423))+8);
    i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i5, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 15419)))), &_td_OOC_IR__AdrDesc, 15419)), 15423))+8);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 15430)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i5, (OOC_IR__Visitor)i0);
l23:
    i4 = i4+1;
    i = i4;
    i5 = i4<i3;
    if (i5) goto l12_loop;
    goto l131;
  case 1:
  case 2:
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 15624))+8);
    i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 15632)))), &_td_OOC_IR__ProcedureRefDesc);
    if (i3) goto l32;
    i3=0u;
    goto l34;
l32:
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 15687))+8);
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 15698)))), &_td_OOC_IR__ProcedureRefDesc, 15698)), 15711))+8);
    i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15664))+12);
    i3 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i4, (Object__Object)i3);
    
l34:
    if (i3) goto l43;
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 15924))+8);
    i3 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 15932)))), &_td_OOC_IR__ProcedureRefDesc));
    if (i3) goto l38;
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 15970))+8);
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 15981)))), &_td_OOC_IR__ProcedureRefDesc, 15981)), 15994))+8);
    i3 = *(OOC_UINT8*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 16004)))), &_td_OOC_SymbolTable__ProcDeclDesc, 16004)), 16013))+52);
    
    goto l40;
l38:
    i3=1u;
l40:
    if (!i3) goto l42;
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16045))+28);
    i4 = (OOC_INT32)OOC_IR_CheckUses__any;
    OOC_IR_CheckUses__DefDesc_SetClass((OOC_IR_CheckUses__Def)i3, (OOC_SymbolTable__Item)i4, 2);
l42:
    callee = (OOC_SymbolTable__ProcDecl)(OOC_INT32)0;
    inout = (ADT_Dictionary_IntValue__Dictionary)(OOC_INT32)0;
    i3=(OOC_INT32)0;i4=(OOC_INT32)0;
    goto l44;
l43:
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 15745))+8);
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 15756)))), &_td_OOC_IR__ProcedureRefDesc, 15756)), 15769))+8);
    i3 = _type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 15779)))), &_td_OOC_SymbolTable__ProcDeclDesc, 15779);
    callee = (OOC_SymbolTable__ProcDecl)i3;
    i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 15826))+8);
    i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 15837)))), &_td_OOC_IR__ProcedureRefDesc, 15837)), 15850))+8);
    i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15806))+12);
    i4 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i5, (Object__Object)i4);
    obj = (Object__Object)i4;
    i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 15879)))), &_td_OOC_IR_CheckUses__ProcDataDesc, 15879)), 15888))+4);
    inout = (ADT_Dictionary_IntValue__Dictionary)i4;
    {register OOC_INT32 h0=i3;i3=i4;i4=h0;}
l44:
    i5 = (OOC_INT32)ADT_ArrayList__New(8);
    readList = (ADT_ArrayList__ArrayList)i5;
    i6 = (OOC_INT32)ADT_ArrayList__New(8);
    writeList = (ADT_ArrayList__ArrayList)i6;
    i7 = (OOC_INT32)ADT_Dictionary_IntValue__New();
    writeMaybeDict = (ADT_Dictionary_IntValue__Dictionary)i7;
    i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 16323))+12);
    i = 0;
    i8 = OOC_ARRAY_LENGTH((_check_pointer(i8, 16333)), 0);
    i9 = 0<i8;
    if (!i9) goto l80;
    i9 = i3==(OOC_INT32)0;
    i10=0;
l47_loop:
    i11 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 16357))+16);
    i11 = _check_pointer(i11, 16368);
    i12 = OOC_ARRAY_LENGTH(i11, 0);
    i11 = (OOC_INT32)*(OOC_INT32*)(i11+(_check_index(i10, i12, OOC_UINT32, 16368))*4);
    i11 = i11==(OOC_INT32)0;
    if (i11) goto l75;
    i11 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 16425))+16);
    i11 = _check_pointer(i11, 16436);
    i12 = OOC_ARRAY_LENGTH(i11, 0);
    i11 = (OOC_INT32)*(OOC_INT32*)(i11+(_check_index(i10, i12, OOC_UINT32, 16436))*4);
    i11 = *(OOC_UINT8*)((_check_pointer(i11, 16439))+59);
    if (i11) goto l52;
    i11 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 17389))+12);
    i11 = _check_pointer(i11, 17399);
    i12 = OOC_ARRAY_LENGTH(i11, 0);
    i11 = (OOC_INT32)*(OOC_INT32*)(i11+(_check_index(i10, i12, OOC_UINT32, 17399))*4);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 17377)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i5, (Object__Object)i11);
    goto l75;
l52:
    i11 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 16475))+12);
    i11 = _check_pointer(i11, 16485);
    i12 = OOC_ARRAY_LENGTH(i11, 0);
    i11 = (OOC_INT32)*(OOC_INT32*)(i11+(_check_index(i10, i12, OOC_UINT32, 16485))*4);
    i11 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i11, 16489)))), &_td_OOC_IR__ConstDesc));
    if (!i11) goto l75;
    i11 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 16562))+12);
    i11 = _check_pointer(i11, 16572);
    i12 = OOC_ARRAY_LENGTH(i11, 0);
    i11 = (OOC_INT32)*(OOC_INT32*)(i11+(_check_index(i10, i12, OOC_UINT32, 16572))*4);
    i11 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i11, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i11, 16579)))), &_td_OOC_IR__AdrDesc, 16579)), 16583))+8);
    design = (OOC_IR__Expression)i11;
    if (i9) goto l71;
    i12 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 16740))+16);
    i12 = _check_pointer(i12, 16751);
    i13 = OOC_ARRAY_LENGTH(i12, 0);
    i12 = (OOC_INT32)*(OOC_INT32*)(i12+(_check_index(i10, i13, OOC_UINT32, 16751))*4);
    i12 = ADT_Dictionary_IntValue__DictionaryDesc_HasKey((ADT_Dictionary_IntValue__Dictionary)i3, (Object__Object)i12);
    if (!i12) goto l75;
    i12 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 16798))+16);
    i12 = _check_pointer(i12, 16809);
    i13 = OOC_ARRAY_LENGTH(i12, 0);
    i12 = (OOC_INT32)*(OOC_INT32*)(i12+(_check_index(i10, i13, OOC_UINT32, 16809))*4);
    i12 = ADT_Dictionary_IntValue__DictionaryDesc_Get((ADT_Dictionary_IntValue__Dictionary)i3, (Object__Object)i12);
    _class = i12;
    i13 = i12>>2;
    switch (i13) {
    case 1:
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 16904)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i5, (Object__Object)i11);
      goto l63;
    case 0:
      goto l63;
    default:
      _failed_case(i13, 16829);
      goto l63;
    }
l63:
    i12 = _mod(i12,4);
    switch (i12) {
    case 2:
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 17104)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i6, (Object__Object)i11);
      goto l75;
    case 1:
      ADT_Dictionary_IntValue__DictionaryDesc_Set((ADT_Dictionary_IntValue__Dictionary)i7, (Object__Object)i11, 0);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 17219)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i6, (Object__Object)i11);
      goto l75;
    case 0:
      goto l75;
    default:
      _failed_case(i12, 17027);
      goto l75;
    }
l71:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 16688)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i6, (Object__Object)i11);
l75:
    i10 = i10+1;
    i = i10;
    i11 = i10<i8;
    if (i11) goto l47_loop;
l80:
    i8 = *(OOC_INT32*)((_check_pointer(i5, 17458))+4);
    i = 0;
    i9 = 0<i8;
    if (!i9) goto l88;
    i9=0;
l83_loop:
    *(OOC_INT8*)((_check_pointer(i0, 17478))+32) = 0;
    i10 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 17509));
    i10 = _check_pointer(i10, 17515);
    i11 = OOC_ARRAY_LENGTH(i10, 0);
    i10 = (OOC_INT32)*(OOC_INT32*)(i10+(_check_index(i9, i11, OOC_UINT32, 17515))*4);
    i11 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 17509));
    i11 = _check_pointer(i11, 17515);
    i12 = OOC_ARRAY_LENGTH(i11, 0);
    i11 = (OOC_INT32)*(OOC_INT32*)(i11+(_check_index(i9, i12, OOC_UINT32, 17515))*4);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer((_type_guard(i11, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i11, 17522)))), &_td_OOC_IR__ExpressionDesc, 17522)), 17533)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)(_type_guard(i10, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i10, 17522)))), &_td_OOC_IR__ExpressionDesc, 17522)), (OOC_IR__Visitor)i0);
    i9 = i9+1;
    i = i9;
    i10 = i9<i8;
    if (i10) goto l83_loop;
l88:
    i5 = i3!=(OOC_INT32)0;
    if (!i5) goto l117;
    i5 = (OOC_INT32)ADT_Dictionary_IntValue__DictionaryDesc_Keys((ADT_Dictionary_IntValue__Dictionary)i3);
    k = (Object__ObjectArrayPtr)i5;
    i8 = OOC_ARRAY_LENGTH((_check_pointer(i5, 17645)), 0);
    i = 0;
    i9 = 0<i8;
    if (!i9) goto l117;
    i9=0;
l93_loop:
    i10 = _check_pointer(i5, 17668);
    i11 = OOC_ARRAY_LENGTH(i10, 0);
    i10 = (OOC_INT32)*(OOC_INT32*)(i10+(_check_index(i9, i11, OOC_UINT32, 17668))*4);
    i10 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i10, 17672)))), &_td_OOC_SymbolTable__VarDeclDesc);
    if (i10) goto l96;
    i10 = _check_pointer(i5, 18532);
    i11 = OOC_ARRAY_LENGTH(i10, 0);
    i10 = (OOC_INT32)*(OOC_INT32*)(i10+(_check_index(i9, i11, OOC_UINT32, 18532))*4);
    i11 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18517))+28);
    OOC_IR_CheckUses__DefDesc_SetClass((OOC_IR_CheckUses__Def)i11, (OOC_SymbolTable__Item)(_type_guard(i10, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i10, 18540)))), &_td_OOC_SymbolTable__TypeDesc, 18540)), 2);
    goto l111;
l96:
    i10 = _check_pointer(i5, 17717);
    i11 = OOC_ARRAY_LENGTH(i10, 0);
    i10 = (OOC_INT32)*(OOC_INT32*)(i10+(_check_index(i9, i11, OOC_UINT32, 17717))*4);
    i10 = _type_guard(i10, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i10, 17725)))), &_td_OOC_SymbolTable__VarDeclDesc, 17725);
    varDecl = (OOC_SymbolTable__VarDecl)i10;
    i11 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i10, 17758)))), OOC_SymbolTable__ItemDesc_Procedure)),OOC_SymbolTable__ItemDesc_Procedure)((OOC_SymbolTable__Item)i10);
    i11 = i11!=i4;
    if (!i11) goto l111;
    i11 = ADT_Dictionary_IntValue__DictionaryDesc_Get((ADT_Dictionary_IntValue__Dictionary)i3, (Object__Object)i10);
    _class = i11;
    i12 = i11>>2;
    switch (i12) {
    case 1:
      *(OOC_INT8*)((_check_pointer(i0, 17926))+32) = 0;
      i12 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 17986));
      OOC_IR_CheckUses__VisitVarDecl((OOC_IR_CheckUses__Visitor)i0, (OOC_SymbolTable__VarDecl)i10, (OOC_Scanner_SymList__Symbol)i12, 1u);
      goto l103;
    case 0:
      goto l103;
    default:
      _failed_case(i12, 17858);
      goto l103;
    }
l103:
    i11 = _mod(i11,4);
    switch (i11) {
    case 2:
      *(OOC_INT8*)((_check_pointer(i0, 18174))+32) = 1;
      i11 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 18235));
      OOC_IR_CheckUses__VisitVarDecl((OOC_IR_CheckUses__Visitor)i0, (OOC_SymbolTable__VarDecl)i10, (OOC_Scanner_SymList__Symbol)i11, 1u);
      goto l111;
    case 1:
      *(OOC_INT8*)((_check_pointer(i0, 18291))+32) = 2;
      i11 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 18357));
      OOC_IR_CheckUses__VisitVarDecl((OOC_IR_CheckUses__Visitor)i0, (OOC_SymbolTable__VarDecl)i10, (OOC_Scanner_SymList__Symbol)i11, 1u);
      goto l111;
    case 0:
      goto l111;
    default:
      _failed_case(i11, 18105);
      goto l111;
    }
l111:
    i9 = i9+1;
    i = i9;
    i10 = i9<i8;
    if (i10) goto l93_loop;
l117:
    i3 = *(OOC_INT32*)((_check_pointer(i6, 18632))+4);
    i = 0;
    i4 = 0<i3;
    if (!i4) goto l131;
    i4=0;
l120_loop:
    i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i6, 18685));
    i5 = _check_pointer(i5, 18691);
    i8 = OOC_ARRAY_LENGTH(i5, 0);
    i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i8, OOC_UINT32, 18691))*4);
    i5 = ADT_Dictionary_IntValue__DictionaryDesc_HasKey((ADT_Dictionary_IntValue__Dictionary)i7, (Object__Object)i5);
    if (i5) goto l123;
    *(OOC_INT8*)((_check_pointer(i0, 18757))+32) = 1;
    goto l124;
l123:
    *(OOC_INT8*)((_check_pointer(i0, 18712))+32) = 2;
l124:
    i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i6, 18803));
    i5 = _check_pointer(i5, 18809);
    i8 = OOC_ARRAY_LENGTH(i5, 0);
    i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i8, OOC_UINT32, 18809))*4);
    i8 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i6, 18803));
    i8 = _check_pointer(i8, 18809);
    i9 = OOC_ARRAY_LENGTH(i8, 0);
    i8 = (OOC_INT32)*(OOC_INT32*)(i8+(_check_index(i4, i9, OOC_UINT32, 18809))*4);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer((_type_guard(i8, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i8, 18816)))), &_td_OOC_IR__ExpressionDesc, 18816)), 18827)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)(_type_guard(i5, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 18816)))), &_td_OOC_IR__ExpressionDesc, 18816)), (OOC_IR__Visitor)i0);
    i4 = i4+1;
    i = i4;
    i5 = i4<i3;
    if (i5) goto l120_loop;
    goto l131;
  default:
    _failed_case(i3, 14904);
    goto l131;
  }
l131:
  *(OOC_INT8*)((_check_pointer(i0, 18869))+32) = i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 18903))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 18903))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 18910))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 18910))+4);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 18915)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i1);
  type = (OOC_SymbolTable__Type)i1;
  i1 = *(OOC_UINT8*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 18943)))), &_td_OOC_SymbolTable__FormalParsDesc, 18943)), 18954))+57);
  if (!i1) goto l134;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18976))+28);
  OOC_IR_CheckUses__DefDesc_Unreachable((OOC_IR_CheckUses__Def)i0);
l134:
  return;
  ;
}

static void OOC_IR_CheckUses__TransitiveWriteClosure(ADT_Dictionary__Dictionary knownProcs, OOC_IR_CheckUses__ProcData pd) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11;
  Object__ObjectArrayPtr k;
  OOC_INT32 i;
  OOC_INT32 j;
  OOC_SymbolTable__ProcDecl callerDecl;
  Object__Object obj;
  OOC_IR_CheckUses__ProcData pdCaller;

  i0 = (OOC_INT32)pd;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19292))+4);
  i1 = (OOC_INT32)ADT_Dictionary_IntValue__DictionaryDesc_Keys((ADT_Dictionary_IntValue__Dictionary)i1);
  k = (Object__ObjectArrayPtr)i1;
  i = 0;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i1, 19330)), 0);
  i3 = 0<i2;
  if (!i3) goto l27;
  i3 = (OOC_INT32)knownProcs;
  i4=0;
l3_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 19360));
  i5 = *(OOC_INT32*)((_check_pointer(i5, 19368))+4);
  j = 0;
  i6 = 0<i5;
  if (!i6) goto l22;
  i6=0;
l6_loop:
  i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 19403));
  i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i7, 19411));
  i7 = _check_pointer(i7, 19417);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i6, i8, OOC_UINT32, 19417))*4);
  i7 = _type_guard(i7, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 19425)))), &_td_OOC_SymbolTable__ProcDeclDesc, 19425);
  callerDecl = (OOC_SymbolTable__ProcDecl)i7;
  i8 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i3, (Object__Object)i7);
  obj = (Object__Object)i8;
  i8 = _type_guard(i8, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i8, 19503)))), &_td_OOC_IR_CheckUses__ProcDataDesc, 19503);
  pdCaller = (OOC_IR_CheckUses__ProcData)i8;
  i9 = _check_pointer(i1, 19549);
  i10 = OOC_ARRAY_LENGTH(i9, 0);
  i11 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i8, 19534))+4);
  i9 = (OOC_INT32)*(OOC_INT32*)(i9+(_check_index(i4, i10, OOC_UINT32, 19549))*4);
  i9 = ADT_Dictionary_IntValue__DictionaryDesc_HasKey((ADT_Dictionary_IntValue__Dictionary)i11, (Object__Object)i9);
  i9 = !i9;
  if (i9) goto l9;
  i7=0u;
  goto l15;
l9:
  i9 = _check_pointer(i1, 19570);
  i10 = OOC_ARRAY_LENGTH(i9, 0);
  i9 = (OOC_INT32)*(OOC_INT32*)(i9+(_check_index(i4, i10, OOC_UINT32, 19570))*4);
  i9 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i9, 19574)))), &_td_OOC_SymbolTable__TypeDesc);
  if (i9) goto l12;
  i9 = _check_pointer(i1, 19627);
  i10 = OOC_ARRAY_LENGTH(i9, 0);
  i9 = (OOC_INT32)*(OOC_INT32*)(i9+(_check_index(i4, i10, OOC_UINT32, 19627))*4);
  i7 = OOC_IR_CheckUses__NonlocalVar((OOC_SymbolTable__ProcDecl)i7, (OOC_SymbolTable__VarDecl)(_type_guard(i9, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i9, 19635)))), &_td_OOC_SymbolTable__VarDeclDesc, 19635)));
  
  goto l15;
l12:
  i7=1u;
l15:
  if (!i7) goto l17;
  i7 = _check_pointer(i1, 19681);
  i9 = OOC_ARRAY_LENGTH(i7, 0);
  i10 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i8, 19669))+4);
  i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i4, i9, OOC_UINT32, 19681))*4);
  ADT_Dictionary_IntValue__DictionaryDesc_Set((ADT_Dictionary_IntValue__Dictionary)i10, (Object__Object)i7, 2);
  OOC_IR_CheckUses__TransitiveWriteClosure((ADT_Dictionary__Dictionary)i3, (OOC_IR_CheckUses__ProcData)i8);
l17:
  i6 = i6+1;
  j = i6;
  i7 = i6<i5;
  if (i7) goto l6_loop;
l22:
  i4 = i4+1;
  i = i4;
  i5 = i4<i2;
  if (i5) goto l3_loop;
l27:
  return;
  ;
}

void OOC_IR_CheckUses__CheckUses(OOC_IR__Module module, OOC_SymbolTable__Module moduleDecl, OOC_Config_Pragmas__History pragmaHistory, OOC_Error__List errList) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  ADT_Dictionary__Dictionary knownProcs;
  OOC_IR_CheckUses__Visitor v;
  ADT_Dictionary__Dictionary loopExits;
  OOC_INT32 i;
  OOC_IR__Procedure proc;
  Object__Object pd;
  OOC_INT32 inWorklist;
  OOC_IR_CheckUses__Def def;
  auto void OOC_IR_CheckUses__CheckUses_CheckStatmSeq(OOC_IR_CheckUses__Def def, OOC_IR__StatementSeq statmSeq);
  auto OOC_CHAR8 OOC_IR_CheckUses__CheckUses_CheckedFunction(OOC_SymbolTable__ProcDecl procDecl);
  auto void OOC_IR_CheckUses__CheckUses_CallersToWorklist(ADT_ArrayList__ArrayList callers);
  auto void OOC_IR_CheckUses__CheckUses_SetWriteFlags(OOC_SymbolTable__ProcDecl localProc, OOC_IR_CheckUses__ProcData pd, OOC_IR_CheckUses__Def def, OOC_CHAR8 *nonlocalWrites);
    
    void OOC_IR_CheckUses__CheckUses_CheckStatmSeq(OOC_IR_CheckUses__Def def, OOC_IR__StatementSeq statmSeq) {
      register OOC_INT32 i0,i1,i2;
      OOC_INT32 i;
      auto void OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckExpr(OOC_IR__Expression expr);
      auto void OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckDesign(OOC_IR__Expression design, OOC_INT8 mode);
      auto void OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckStatm(OOC_IR__Statement statm);
        
        void OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckExpr(OOC_IR__Expression expr) {
          register OOC_INT32 i0,i1;

          i0 = (OOC_INT32)v;
          i1 = (OOC_INT32)def;
          *(OOC_INT32*)((_check_pointer(i0, 20287))+28) = i1;
          *(OOC_INT8*)((_check_pointer(i0, 20309))+32) = 0;
          i1 = (OOC_INT32)expr;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 20336)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i1, (OOC_IR__Visitor)i0);
          return;
          ;
        }

        
        void OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckDesign(OOC_IR__Expression design, OOC_INT8 mode) {
          register OOC_INT32 i0,i1;

          i0 = (OOC_INT32)v;
          i1 = (OOC_INT32)def;
          *(OOC_INT32*)((_check_pointer(i0, 20461))+28) = i1;
          i1 = mode;
          *(OOC_INT8*)((_check_pointer(i0, 20483))+32) = i1;
          i1 = (OOC_INT32)design;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 20512)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i1, (OOC_IR__Visitor)i0);
          return;
          ;
        }

        
        void OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckStatm(OOC_IR__Statement statm) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
          OOC_IR_CheckUses__Def def2;
          OOC_IR_CheckUses__Def defIn;
          OOC_INT32 i;
          Object__Object obj;
          OOC_IR__Expression expr;
          auto void OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckStatm_CheckWith(OOC_IR_CheckUses__Def defIn, OOC_IR__WithStatm with, ADT_ArrayList__ArrayList prevGuards);
            
            void OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckStatm_CheckWith(OOC_IR_CheckUses__Def defIn, OOC_IR__WithStatm with, ADT_ArrayList__ArrayList prevGuards) {
              register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
              OOC_IR__TypeTest localTest;
              OOC_IR__TypeTest test;
              OOC_IR_CheckUses__Def defOld;
              OOC_IR_CheckUses__Def def2;

              i0 = (OOC_INT32)with;
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20953))+8);
              i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 20963)))), &_td_OOC_IR__TypeTestDesc, 20963);
              localTest = (OOC_IR__TypeTest)i1;
              i2 = (OOC_INT32)prevGuards;
              i = 0;
              i3 = *(OOC_INT32*)((_check_pointer(i2, 21008))+4);
              i4 = 0<i3;
              if (!i4) goto l19;
              i4=0;
l3_loop:
              i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 21049));
              i5 = _check_pointer(i5, 21055);
              i6 = OOC_ARRAY_LENGTH(i5, 0);
              i4 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 21055))*4);
              i4 = _type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 21062)))), &_td_OOC_IR__TypeTestDesc, 21062);
              test = (OOC_IR__TypeTest)i4;
              i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 21093))+8);
              i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 21123))+8);
              i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i5, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 21102)))), &_td_OOC_IR__VarDesc, 21102)), 21106))+8);
              i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i6, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 21132)))), &_td_OOC_IR__VarDesc, 21132)), 21136))+8);
              i5 = i5==i6;
              if (i5) goto l6;
              i4=0u;
              goto l8;
l6:
              i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 21238))+12);
              i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 21186))+12);
              i4 = OOC_SymbolTable_TypeRules__IsExtensionOf((OOC_SymbolTable__Type)i5, (OOC_SymbolTable__Type)i4);
              
l8:
              if (i4) goto l10;
              i4=0u;
              goto l12;
l10:
              i4 = (OOC_INT32)v;
              i4 = *(OOC_INT8*)((_check_pointer(i4, 21273))+8);
              i4 = i4==2;
              
l12:
              if (!i4) goto l14;
              i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 21359));
              i5 = (OOC_INT32)pragmaHistory;
              i6 = (OOC_INT32)errList;
              OOC_IR_CheckUses__WarnSym((OOC_Error__List)i6, (OOC_Config_Pragmas__History)i5, (OOC_Scanner_SymList__Symbol)i4, 5);
l14:
              i4 = i;
              i4 = i4+1;
              i = i4;
              i5 = i4<i3;
              if (i5) goto l3_loop;
l19:
              i1 = (OOC_INT32)def;
              defOld = (OOC_IR_CheckUses__Def)i1;
              i3 = (OOC_INT32)defIn;
              def = (OOC_IR_CheckUses__Def)i3;
              i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21486))+8);
              OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i4);
              def = (OOC_IR_CheckUses__Def)i1;
              i1 = (OOC_INT32)OOC_IR_CheckUses__DefDesc_Copy((OOC_IR_CheckUses__Def)i3);
              def2 = (OOC_IR_CheckUses__Def)i1;
              i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21597))+12);
              OOC_IR_CheckUses__CheckUses_CheckStatmSeq((OOC_IR_CheckUses__Def)i1, (OOC_IR__StatementSeq)i4);
              i4 = (OOC_INT32)def;
              OOC_IR_CheckUses__DefDesc_Merge((OOC_IR_CheckUses__Def)i4, (OOC_IR_CheckUses__Def)i1);
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21665))+16);
              i1 = i1!=0;
              if (!i1) goto l30;
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21712))+16);
              i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 21722)), 0);
              i1 = i1==1;
              if (i1) goto l24;
              i1=0u;
              goto l26;
l24:
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21752))+16);
              i1 = _check_pointer(i1, 21762);
              i4 = OOC_ARRAY_LENGTH(i1, 0);
              i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i4, OOC_UINT8, 21762))*4);
              i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 21766)))), &_td_OOC_IR__WithStatmDesc);
              
l26:
              if (i1) goto l28;
              i1 = (OOC_INT32)OOC_IR_CheckUses__DefDesc_Copy((OOC_IR_CheckUses__Def)i3);
              def2 = (OOC_IR_CheckUses__Def)i1;
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22014))+16);
              OOC_IR_CheckUses__CheckUses_CheckStatmSeq((OOC_IR_CheckUses__Def)i1, (OOC_IR__StatementSeq)i0);
              i0 = (OOC_INT32)def;
              OOC_IR_CheckUses__DefDesc_Merge((OOC_IR_CheckUses__Def)i0, (OOC_IR_CheckUses__Def)i1);
              goto l30;
l28:
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21824))+8);
              OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 21812)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i2, (Object__Object)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 21834)))), &_td_OOC_IR__TypeTestDesc, 21834)));
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21881))+16);
              i0 = _check_pointer(i0, 21891);
              i1 = OOC_ARRAY_LENGTH(i0, 0);
              i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 21891))*4);
              OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckStatm_CheckWith((OOC_IR_CheckUses__Def)i3, (OOC_IR__WithStatm)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21898)))), &_td_OOC_IR__WithStatmDesc, 21898)), (ADT_ArrayList__ArrayList)i2);
l30:
              return;
              ;
            }


          i0 = (OOC_INT32)statm;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22150)))), &_td_OOC_IR__AssertDesc);
          if (i1) goto l122;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22451)))), &_td_OOC_IR__AssignOpDesc);
          if (i1) goto l120;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22611)))), &_td_OOC_IR__AssignmentDesc);
          if (i1) goto l118;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22736)))), &_td_OOC_IR__CallDesc);
          if (i1) goto l116;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22803)))), &_td_OOC_IR__CopyDesc);
          if (i1) goto l114;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22919)))), &_td_OOC_IR__CopyParameterDesc);
          if (i1) goto l135;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22990)))), &_td_OOC_IR__CopyStringDesc);
          if (i1) goto l111;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23112)))), &_td_OOC_IR__ForStatmDesc);
          if (i1) goto l109;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23365)))), &_td_OOC_IR__IterateArrayStatmDesc);
          if (i1) goto l107;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23534)))), &_td_OOC_IR__IterateObjectStatmDesc);
          if (i1) goto l105;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23754)))), &_td_OOC_IR__IfStatmDesc);
          if (i1) goto l103;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23981)))), &_td_OOC_IR__CaseStatmDesc);
          if (i1) goto l90;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 24475)))), &_td_OOC_IR__LoopStatmDesc);
          if (i1) goto l85;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 24666)))), &_td_OOC_IR__ExitDesc);
          if (i1) goto l83;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 24809)))), &_td_OOC_IR__MoveBlockDesc);
          if (i1) goto l66;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25529)))), &_td_OOC_IR__RaiseDesc);
          if (i1) goto l64;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25636)))), &_td_OOC_IR__RepeatStatmDesc);
          if (i1) goto l62;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25766)))), &_td_OOC_IR__ReturnDesc);
          if (i1) goto l57;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25960)))), &_td_OOC_IR__TryStatmDesc);
          if (i1) goto l47;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26271)))), &_td_OOC_IR__WhileStatmDesc);
          if (i1) goto l45;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26392)))), &_td_OOC_IR__WithStatmDesc);
          if (i1) goto l43;
          _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26385)))), 26385);
          goto l135;
l43:
          i1 = (OOC_INT32)def;
          i1 = (OOC_INT32)OOC_IR_CheckUses__DefDesc_Copy((OOC_IR_CheckUses__Def)i1);
          defIn = (OOC_IR_CheckUses__Def)i1;
          i2 = (OOC_INT32)def;
          OOC_IR_CheckUses__DefDesc_Unreachable((OOC_IR_CheckUses__Def)i2);
          i2 = (OOC_INT32)ADT_ArrayList__New(4);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckStatm_CheckWith((OOC_IR_CheckUses__Def)i1, (OOC_IR__WithStatm)i0, (ADT_ArrayList__ArrayList)i2);
          goto l135;
l45:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26315))+8);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26358))+12);
          i1 = (OOC_INT32)def;
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq((OOC_IR_CheckUses__Def)i1, (OOC_IR__StatementSeq)i0);
          goto l135;
l47:
          i1 = (OOC_INT32)def;
          i1 = (OOC_INT32)OOC_IR_CheckUses__DefDesc_Copy((OOC_IR_CheckUses__Def)i1);
          defIn = (OOC_IR_CheckUses__Def)i1;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26042))+8);
          i3 = (OOC_INT32)def;
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq((OOC_IR_CheckUses__Def)i3, (OOC_IR__StatementSeq)i2);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26087))+12);
          i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 26097)), 0);
          i = 0;
          i3 = 0<i2;
          if (!i3) goto l135;
          i3=0;
l50_loop:
          i4 = (OOC_INT32)OOC_IR_CheckUses__DefDesc_Copy((OOC_IR_CheckUses__Def)i1);
          def2 = (OOC_IR_CheckUses__Def)i4;
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26176))+12);
          i5 = _check_pointer(i5, 26186);
          i6 = OOC_ARRAY_LENGTH(i5, 0);
          i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 26186))*4);
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 26189))+12);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq((OOC_IR_CheckUses__Def)i4, (OOC_IR__StatementSeq)i5);
          i5 = (OOC_INT32)def;
          OOC_IR_CheckUses__DefDesc_Merge((OOC_IR_CheckUses__Def)i5, (OOC_IR_CheckUses__Def)i4);
          i3 = i3+1;
          i = i3;
          i4 = i3<i2;
          if (i4) goto l50_loop;
          goto l135;
l57:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25800))+8);
          i1 = i1!=(OOC_INT32)0;
          if (!i1) goto l60;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25847))+8);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
l60:
          i0 = (OOC_INT32)v;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25883))+16);
          i1 = (OOC_INT32)def;
          OOC_IR_CheckUses__DefDesc_Merge((OOC_IR_CheckUses__Def)i0, (OOC_IR_CheckUses__Def)i1);
          i0 = (OOC_INT32)def;
          OOC_IR_CheckUses__DefDesc_Unreachable((OOC_IR_CheckUses__Def)i0);
          goto l135;
l62:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25690))+8);
          i2 = (OOC_INT32)def;
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq((OOC_IR_CheckUses__Def)i2, (OOC_IR__StatementSeq)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25723))+12);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l135;
l64:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25568))+8);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          i0 = (OOC_INT32)def;
          OOC_IR_CheckUses__DefDesc_Unreachable((OOC_IR_CheckUses__Def)i0);
          goto l135;
l66:
          i1 = (OOC_INT32)v;
          i2 = *(OOC_INT8*)((_check_pointer(i1, 24842))+8);
          i2 = i2==0;
          if (!i2) goto l69;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 24887))+24);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 24901))+4);
          i2 = (OOC_INT32)OOC_IR_CheckUses__any;
          ADT_Dictionary_IntValue__DictionaryDesc_Set((ADT_Dictionary_IntValue__Dictionary)i1, (Object__Object)i2, 2);
l69:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24992))+8);
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 25000)))), &_td_OOC_IR__AdrDesc);
          if (i1) goto l72;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25110))+8);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          goto l73;
l72:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25043))+8);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 25054)))), &_td_OOC_IR__AdrDesc, 25054)), 25058))+8);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
l73:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25160))+16);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25202))+12);
          expr = (OOC_IR__Expression)i1;
          i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 25228)))), &_td_OOC_IR__TypeConvDesc);
          if (!i2) goto l77;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 25277)))), &_td_OOC_IR__TypeConvDesc, 25277)), 25286))+8);
          expr = (OOC_IR__Expression)i1;
          
l77:
          i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 25327)))), &_td_OOC_IR__AdrDesc);
          if (i2) goto l80;
          i1 = (OOC_INT32)v;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 25424))+28);
          i2 = (OOC_INT32)OOC_IR_CheckUses__any;
          OOC_IR_CheckUses__DefDesc_SetClass((OOC_IR_CheckUses__Def)i1, (OOC_SymbolTable__Item)i2, 2);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25480))+12);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l135;
l80:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 25375)))), &_td_OOC_IR__AdrDesc, 25375)), 25379))+8);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckDesign((OOC_IR__Expression)i0, 1);
          goto l135;
l83:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24715))+8);
          i1 = (OOC_INT32)loopExits;
          i0 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i1, (Object__Object)i0);
          obj = (Object__Object)i0;
          i1 = (OOC_INT32)def;
          OOC_IR_CheckUses__DefDesc_Merge((OOC_IR_CheckUses__Def)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 24737)))), &_td_OOC_IR_CheckUses__DefDesc, 24737)), (OOC_IR_CheckUses__Def)i1);
          i0 = (OOC_INT32)def;
          OOC_IR_CheckUses__DefDesc_Unreachable((OOC_IR_CheckUses__Def)i0);
          goto l135;
l85:
          i1 = (OOC_INT32)OOC_IR_CheckUses__NewUnreachableDef();
          defIn = (OOC_IR_CheckUses__Def)i1;
          i2 = (OOC_INT32)loopExits;
          ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i2, (Object__Object)i0, (Object__Object)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24606))+8);
          i2 = (OOC_INT32)def;
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq((OOC_IR_CheckUses__Def)i2, (OOC_IR__StatementSeq)i0);
          i0 = _check_pointer(i1, 24637);
          i1 = (OOC_INT32)def;
          i1 = _check_pointer(i1, 24627);
          i2 = (OOC_INT32)&_td_OOC_IR_CheckUses__DefDesc;
          i2 = i2!=i2;
          if (!i2) goto l88;
          _failed_type_assert(24627);
l88:
          _copy_block(i0,i1,8);
          goto l135;
l90:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24024))+8);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i1 = (OOC_INT32)def;
          i1 = (OOC_INT32)OOC_IR_CheckUses__DefDesc_Copy((OOC_IR_CheckUses__Def)i1);
          defIn = (OOC_IR_CheckUses__Def)i1;
          i2 = (OOC_INT32)def;
          OOC_IR_CheckUses__DefDesc_Unreachable((OOC_IR_CheckUses__Def)i2);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24127))+12);
          i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 24136)), 0);
          i = 0;
          i3 = 0<i2;
          if (!i3) goto l98;
          i3=0;
l93_loop:
          i4 = (OOC_INT32)OOC_IR_CheckUses__DefDesc_Copy((OOC_IR_CheckUses__Def)i1);
          def2 = (OOC_IR_CheckUses__Def)i4;
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24215))+12);
          i5 = _check_pointer(i5, 24224);
          i6 = OOC_ARRAY_LENGTH(i5, 0);
          i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 24224))*4);
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 24227))+12);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq((OOC_IR_CheckUses__Def)i4, (OOC_IR__StatementSeq)i5);
          i5 = (OOC_INT32)def;
          OOC_IR_CheckUses__DefDesc_Merge((OOC_IR_CheckUses__Def)i5, (OOC_IR_CheckUses__Def)i4);
          i3 = i3+1;
          i = i3;
          i4 = i3<i2;
          if (i4) goto l93_loop;
l98:
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24302))+16);
          i2 = i2!=(OOC_INT32)0;
          if (!i2) goto l135;
          i1 = (OOC_INT32)OOC_IR_CheckUses__DefDesc_Copy((OOC_IR_CheckUses__Def)i1);
          def2 = (OOC_IR_CheckUses__Def)i1;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24394))+16);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq((OOC_IR_CheckUses__Def)i1, (OOC_IR__StatementSeq)i0);
          i0 = (OOC_INT32)def;
          OOC_IR_CheckUses__DefDesc_Merge((OOC_IR_CheckUses__Def)i0, (OOC_IR_CheckUses__Def)i1);
          goto l135;
l103:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23795))+8);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i1 = (OOC_INT32)def;
          i1 = (OOC_INT32)OOC_IR_CheckUses__DefDesc_Copy((OOC_IR_CheckUses__Def)i1);
          def2 = (OOC_IR_CheckUses__Def)i1;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23868))+12);
          i3 = (OOC_INT32)def;
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq((OOC_IR_CheckUses__Def)i3, (OOC_IR__StatementSeq)i2);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23915))+16);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq((OOC_IR_CheckUses__Def)i1, (OOC_IR__StatementSeq)i0);
          i0 = (OOC_INT32)def;
          OOC_IR_CheckUses__DefDesc_Merge((OOC_IR_CheckUses__Def)i0, (OOC_IR_CheckUses__Def)i1);
          goto l135;
l105:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23586))+12);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23630))+16);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23672))+8);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckDesign((OOC_IR__Expression)i1, 1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23720))+20);
          i1 = (OOC_INT32)def;
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq((OOC_IR_CheckUses__Def)i1, (OOC_IR__StatementSeq)i0);
          goto l135;
l107:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23416))+12);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23452))+8);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckDesign((OOC_IR__Expression)i1, 1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23500))+16);
          i1 = (OOC_INT32)def;
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq((OOC_IR_CheckUses__Def)i1, (OOC_IR__StatementSeq)i0);
          goto l135;
l109:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23154))+12);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23188))+16);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23222))+8);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckDesign((OOC_IR__Expression)i1, 1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23331))+24);
          i1 = (OOC_INT32)def;
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq((OOC_IR_CheckUses__Def)i1, (OOC_IR__StatementSeq)i0);
          goto l135;
l111:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23034))+8);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23071))+12);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckDesign((OOC_IR__Expression)i0, 1);
          goto l135;
l114:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22841))+8);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22878))+12);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckDesign((OOC_IR__Expression)i0, 1);
          goto l135;
l116:
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l135;
l118:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22655))+12);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22691))+8);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckDesign((OOC_IR__Expression)i0, 1);
          goto l135;
l120:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22493))+12);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22527))+8);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22566))+8);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckDesign((OOC_IR__Expression)i0, 1);
          goto l135;
l122:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22184))+8);
          i1 = i1==(OOC_INT32)0;
          if (i1) goto l129;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22225))+8);
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 22236)))), &_td_OOC_IR__ConstDesc);
          if (i1) goto l127;
          i1=0u;
          goto l131;
l127:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22290))+8);
          i2 = (OOC_INT32)Object_Boxed__false;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 22304)))), &_td_OOC_IR__ConstDesc, 22304)), 22310))+8);
          i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 22277)))), Object_Boxed__BooleanDesc_Equals)),Object_Boxed__BooleanDesc_Equals)((Object_Boxed__Boolean)i2, (Object__Object)i1);
          
          goto l131;
l129:
          i1=1u;
l131:
          if (i1) goto l133;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22397))+8);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l135;
l133:
          i0 = (OOC_INT32)def;
          OOC_IR_CheckUses__DefDesc_Unreachable((OOC_IR_CheckUses__Def)i0);
l135:
          return;
          ;
        }


      i0 = (OOC_INT32)statmSeq;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l27;
      i = 0;
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 26651)), 0);
      i1 = 0!=i1;
      if (i1) goto l5;
      i1=0u;
      goto l7;
l5:
      i1 = (OOC_INT32)def;
      i1 = *(OOC_UINT8*)((_check_pointer(i1, 26661))+4);
      i1 = !i1;
      
l7:
      if (i1) goto l9;
      i1=i0;i0=0;
      goto l19;
l9:
      i1=0;
l10_loop:
      i0 = _check_pointer(i0, 26706);
      i2 = OOC_ARRAY_LENGTH(i0, 0);
      i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(i1, i2, OOC_UINT32, 26706))*4);
      OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckStatm((OOC_IR__Statement)i0);
      i0 = i;
      i0 = i0+1;
      i = i0;
      i1 = (OOC_INT32)statmSeq;
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i1, 26651)), 0);
      i2 = i0!=i2;
      if (i2) goto l13;
      i2=0u;
      goto l15;
l13:
      i2 = (OOC_INT32)def;
      i2 = *(OOC_UINT8*)((_check_pointer(i2, 26661))+4);
      i2 = !i2;
      
l15:
      if (!i2) goto l19;
      {register OOC_INT32 h0=i0;i0=i1;i1=h0;}
      goto l10_loop;
l19:
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i1, 26771)), 0);
      i2 = i0!=i2;
      if (i2) goto l22;
      i2=0u;
      goto l24;
l22:
      i2 = (OOC_INT32)v;
      i2 = *(OOC_INT8*)((_check_pointer(i2, 26779))+8);
      i2 = i2==2;
      
l24:
      if (!i2) goto l27;
      i1 = _check_pointer(i1, 26860);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i0 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(i0, i2, OOC_UINT32, 26860))*4);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 26863));
      i1 = (OOC_INT32)errList;
      i2 = (OOC_INT32)pragmaHistory;
      OOC_IR_CheckUses__WarnSym((OOC_Error__List)i1, (OOC_Config_Pragmas__History)i2, (OOC_Scanner_SymList__Symbol)i0, 3);
l27:
      return;
      ;
    }

    
    OOC_CHAR8 OOC_IR_CheckUses__CheckUses_CheckedFunction(OOC_SymbolTable__ProcDecl procDecl) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)procDecl;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27031))+64);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 27042))+44);
      i1 = i1!=(OOC_INT32)0;
      if (i1) goto l3;
      i0=0u;
      goto l4;
l3:
      i0 = *(OOC_UINT8*)((_check_pointer(i0, 27082))+50);
      i0 = !i0;
      
l4:
      return i0;
      ;
    }

    
    void OOC_IR_CheckUses__CheckUses_CallersToWorklist(ADT_ArrayList__ArrayList callers) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      OOC_INT32 i;
      Object__Object pd;

      i0 = (OOC_INT32)callers;
      i = 0;
      i1 = *(OOC_INT32*)((_check_pointer(i0, 27270))+4);
      i2 = 0<i1;
      if (!i2) goto l8;
      i2=0;
l3_loop:
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 27317));
      i3 = _check_pointer(i3, 27323);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 27323))*4);
      i4 = (OOC_INT32)knownProcs;
      i3 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i4, (Object__Object)i3);
      pd = (Object__Object)i3;
      *(OOC_UINT8*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 27340)))), &_td_OOC_IR_CheckUses__ProcDataDesc, 27340)), 27349))+8) = 1u;
      i2 = i2+1;
      i = i2;
      i3 = i2<i1;
      if (i3) goto l3_loop;
l8:
      return;
      ;
    }

    
    void OOC_IR_CheckUses__CheckUses_SetWriteFlags(OOC_SymbolTable__ProcDecl localProc, OOC_IR_CheckUses__ProcData pd, OOC_IR_CheckUses__Def def, OOC_CHAR8 *nonlocalWrites) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
      Object__ObjectArrayPtr k;
      OOC_INT32 i;
      Object__Object item;

      *nonlocalWrites = 0u;
      i0 = (OOC_INT32)pd;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27692))+4);
      i1 = (OOC_INT32)ADT_Dictionary_IntValue__DictionaryDesc_Keys((ADT_Dictionary_IntValue__Dictionary)i1);
      k = (Object__ObjectArrayPtr)i1;
      i = 0;
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i1, 27732)), 0);
      i3 = (OOC_INT32)def;
      i4 = 0<i2;
      if (!i4) goto l11;
      i4=0;
l3_loop:
      i5 = _check_pointer(i1, 27770);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 27755));
      i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 27770))*4);
      i5 = ADT_Dictionary_IntValue__DictionaryDesc_HasKey((ADT_Dictionary_IntValue__Dictionary)i7, (Object__Object)i5);
      i5 = !i5;
      if (!i5) goto l6;
      i5 = _check_pointer(i1, 27827);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 27827))*4);
      OOC_IR_CheckUses__ProcDataDesc_SetWriteFlag((OOC_IR_CheckUses__ProcData)i0, (OOC_SymbolTable__Item)(_type_guard(i5, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 27835)))), &_td_OOC_SymbolTable__ItemDesc, 27835)), 0);
l6:
      i4 = i4+1;
      i = i4;
      i5 = i4<i2;
      if (i5) goto l3_loop;
l11:
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 27902));
      i1 = (OOC_INT32)ADT_Dictionary_IntValue__DictionaryDesc_Keys((ADT_Dictionary_IntValue__Dictionary)i1);
      k = (Object__ObjectArrayPtr)i1;
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i1, 27942)), 0);
      i = 0;
      i4 = 0<i2;
      if (!i4) goto l39;
      i4 = (OOC_INT32)localProc;
      i5=0;
l14_loop:
      i6 = _check_pointer(i1, 27967);
      i7 = OOC_ARRAY_LENGTH(i6, 0);
      i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i5, i7, OOC_UINT32, 27967))*4);
      item = (Object__Object)i6;
      i7 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 27989)))), &_td_OOC_SymbolTable__VarDeclDesc);
      if (i7) goto l24;
      i7 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 28439)))), &_td_OOC_SymbolTable__TypeDesc);
      if (i7) goto l19;
      _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 28433)))), 28433);
      goto l34;
l19:
      *nonlocalWrites = 1u;
      i7 = (OOC_INT32)OOC_IR_CheckUses__any;
      i7 = i6!=i7;
      if (!i7) goto l34;
      OOC_IR_CheckUses__ProcDataDesc_SetWriteFlag((OOC_IR_CheckUses__ProcData)i0, (OOC_SymbolTable__Item)i6, 2);
      goto l34;
l24:
      i7 = OOC_IR_CheckUses__NonlocalVar((OOC_SymbolTable__ProcDecl)i4, (OOC_SymbolTable__VarDecl)i6);
      if (!i7) goto l34;
      i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 28073));
      i7 = ADT_Dictionary_IntValue__DictionaryDesc_Get((ADT_Dictionary_IntValue__Dictionary)i7, (Object__Object)i6);
      switch (i7) {
      case 0:
        OOC_IR_CheckUses__ProcDataDesc_SetWriteFlag((OOC_IR_CheckUses__ProcData)i0, (OOC_SymbolTable__Item)i6, 0);
        goto l34;
      case 1:
        *nonlocalWrites = 1u;
        OOC_IR_CheckUses__ProcDataDesc_SetWriteFlag((OOC_IR_CheckUses__ProcData)i0, (OOC_SymbolTable__Item)i6, 1);
        goto l34;
      case 2:
        *nonlocalWrites = 1u;
        OOC_IR_CheckUses__ProcDataDesc_SetWriteFlag((OOC_IR_CheckUses__ProcData)i0, (OOC_SymbolTable__Item)i6, 2);
        goto l34;
      default:
        _failed_case(i7, 28065);
        goto l34;
      }
l34:
      i5 = i5+1;
      i = i5;
      i6 = i5<i2;
      if (i6) goto l14_loop;
l39:
      i1 = *(OOC_UINT8*)((_check_pointer(i3, 28982))+4);
      if (i1) goto l42;
      i1=0u;
      goto l44;
l42:
      i1 = (OOC_INT32)localProc;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 29061))+64);
      i1 = *(OOC_UINT8*)((_check_pointer(i1, 29072))+57);
      i1 = !i1;
      
l44:
      if (i1) goto l46;
      i1=0u;
      goto l52;
l46:
      i1 = (OOC_INT32)localProc;
      i2 = OOC_SymbolTable__ProcDeclDesc_IsTypeBound((OOC_SymbolTable__ProcDecl)i1);
      i2 = !i2;
      if (i2) goto l49;
      i1 = *(OOC_UINT8*)((_check_pointer(i1, 29200))+51);
      
      goto l52;
l49:
      i1=1u;
l52:
      if (!i1) goto l54;
      i1 = (OOC_INT32)localProc;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 29238))+64);
      *(OOC_UINT8*)((_check_pointer(i1, 29249))+57) = 1u;
      *(OOC_UINT8*)((_check_pointer(i0, 29278))+9) = 1u;
l54:
      return;
      ;
    }


  i0 = (OOC_INT32)moduleDecl;
  i0 = *(OOC_INT8*)((_check_pointer(i0, 30779))+52);
  i0 = i0!=0;
  if (!i0) goto l3;
  return;
l3:
  i0 = (OOC_INT32)module;
  i1 = (OOC_INT32)OOC_IR_CheckUses__KnownProcs((OOC_IR__Module)i0);
  knownProcs = (ADT_Dictionary__Dictionary)i1;
  i2 = (OOC_INT32)RT0__NewObject(_td_OOC_IR_CheckUses__Visitor.baseTypes[0]);
  v = (OOC_IR_CheckUses__Visitor)i2;
  OOC_IR_VisitAll__InitVisitor((OOC_IR_VisitAll__Visitor)i2);
  i3 = (OOC_INT32)errList;
  *(OOC_INT32*)(_check_pointer(i2, 30950)) = i3;
  i3 = (OOC_INT32)pragmaHistory;
  *(OOC_INT32*)((_check_pointer(i2, 30976))+4) = i3;
  *(OOC_INT32*)((_check_pointer(i2, 31014))+28) = 0;
  *(OOC_INT32*)((_check_pointer(i2, 31032))+12) = i1;
  i3 = (OOC_INT32)ADT_Dictionary__New();
  loopExits = (ADT_Dictionary__Dictionary)i3;
  *(OOC_INT8*)((_check_pointer(i2, 31326))+8) = 0;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31383))+8);
  i = 0;
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 31392)), 0);
  i2 = 0<i0;
  if (!i2) goto l12;
  i2=i1;i1=0;
l7_loop:
  i3 = (OOC_INT32)module;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 31420))+8);
  i3 = _check_pointer(i3, 31429);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i1, i4, OOC_UINT32, 31429))*4);
  proc = (OOC_IR__Procedure)i1;
  i3 = (OOC_INT32)v;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 31459))+4);
  *(OOC_INT32*)((_check_pointer(i3, 31441))+20) = i4;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 31494))+20);
  i2 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i2, (Object__Object)i4);
  pd = (Object__Object)i2;
  *(OOC_INT32*)((_check_pointer(i3, 31514))+24) = (_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 31535)))), &_td_OOC_IR_CheckUses__ProcDataDesc, 31535));
  i2 = (OOC_INT32)OOC_IR_CheckUses__NewUnreachableDef();
  *(OOC_INT32*)((_check_pointer(i3, 31553))+16) = i2;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 31628))+8);
  i2 = (OOC_INT32)OOC_IR_CheckUses__NewDef();
  OOC_IR_CheckUses__CheckUses_CheckStatmSeq((OOC_IR_CheckUses__Def)i2, (OOC_IR__StatementSeq)i1);
  i1 = (OOC_INT32)pd;
  i2 = (OOC_INT32)knownProcs;
  OOC_IR_CheckUses__TransitiveWriteClosure((ADT_Dictionary__Dictionary)i2, (OOC_IR_CheckUses__ProcData)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 31684)))), &_td_OOC_IR_CheckUses__ProcDataDesc, 31684)));
  i1 = i;
  i1 = i1+1;
  i = i1;
  i3 = i1<i0;
  if (i3) goto l7_loop;
l12:
  i0 = (OOC_INT32)v;
  *(OOC_INT8*)((_check_pointer(i0, 31865))+8) = 1;
l13_loop:
  inWorklist = 0;
  i0 = (OOC_INT32)module;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31957))+8);
  i = 0;
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 31966)), 0);
  i1 = 0<i0;
  if (!i1) goto l27;
  i1=0;
l16_loop:
  i2 = (OOC_INT32)module;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 31996))+8);
  i2 = _check_pointer(i2, 32005);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i1, i3, OOC_UINT32, 32005))*4);
  proc = (OOC_IR__Procedure)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 32043))+4);
  i3 = (OOC_INT32)knownProcs;
  i2 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i3, (Object__Object)i2);
  pd = (Object__Object)i2;
  i3 = *(OOC_UINT8*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 32065)))), &_td_OOC_IR_CheckUses__ProcDataDesc, 32065)), 32074))+8);
  if (!i3) goto l22;
  i3 = (OOC_INT32)v;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 32120))+4);
  *(OOC_INT32*)((_check_pointer(i3, 32102))+20) = i4;
  *(OOC_INT32*)((_check_pointer(i3, 32138))+24) = (_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 32159)))), &_td_OOC_IR_CheckUses__ProcDataDesc, 32159));
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 32181))+24);
  *(OOC_UINT8*)((_check_pointer(i2, 32195))+9) = 0u;
  i2 = (OOC_INT32)OOC_IR_CheckUses__NewUnreachableDef();
  *(OOC_INT32*)((_check_pointer(i3, 32230))+16) = i2;
  i2 = (OOC_INT32)OOC_IR_CheckUses__NewDef();
  def = (OOC_IR_CheckUses__Def)i2;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 32325))+8);
  OOC_IR_CheckUses__CheckUses_CheckStatmSeq((OOC_IR_CheckUses__Def)i2, (OOC_IR__StatementSeq)i1);
  i1 = (OOC_INT32)v;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 32348))+16);
  i3 = (OOC_INT32)def;
  OOC_IR_CheckUses__DefDesc_Merge((OOC_IR_CheckUses__Def)i2, (OOC_IR_CheckUses__Def)i3);
  i2 = (OOC_INT32)proc;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 32464))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 32425))+16);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 32408))+24);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 32395))+20);
  OOC_IR_CheckUses__CheckUses_SetWriteFlags((OOC_SymbolTable__ProcDecl)i1, (OOC_IR_CheckUses__ProcData)i4, (OOC_IR_CheckUses__Def)i3, (void*)((_check_pointer(i2, 32469))+52));
  i1 = (OOC_INT32)v;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 32512))+24);
  i1 = *(OOC_UINT8*)((_check_pointer(i1, 32526))+9);
  if (!i1) goto l22;
  i1 = (OOC_INT32)pd;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 32578)))), &_td_OOC_IR_CheckUses__ProcDataDesc, 32578)), 32587));
  OOC_IR_CheckUses__CheckUses_CallersToWorklist((ADT_ArrayList__ArrayList)i1);
  i1 = inWorklist;
  inWorklist = (i1+1);
l22:
  i1 = i;
  i1 = i1+1;
  i = i1;
  i2 = i1<i0;
  if (i2) goto l16_loop;
l27:
  i0 = inWorklist;
  i0 = i0==0;
  if (!i0) goto l13_loop;
l31:
  i0 = (OOC_INT32)v;
  *(OOC_INT8*)((_check_pointer(i0, 32761))+8) = 2;
  i0 = (OOC_INT32)module;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32817))+8);
  i = 0;
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 32826)), 0);
  i1 = 0<i0;
  if (!i1) goto l49;
  i1=0;
l34_loop:
  i2 = (OOC_INT32)module;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 32854))+8);
  i2 = _check_pointer(i2, 32863);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i1, i3, OOC_UINT32, 32863))*4);
  proc = (OOC_IR__Procedure)i1;
  i2 = (OOC_INT32)v;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 32893))+4);
  *(OOC_INT32*)((_check_pointer(i2, 32875))+20) = i3;
  i3 = (OOC_INT32)OOC_IR_CheckUses__NewUnreachableDef();
  *(OOC_INT32*)((_check_pointer(i2, 32907))+16) = i3;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 32955))+16);
  i2 = i2!=0;
  if (!i2) goto l44;
  i2 = (OOC_INT32)OOC_IR_CheckUses__NewDef();
  def = (OOC_IR_CheckUses__Def)i2;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 33034))+8);
  OOC_IR_CheckUses__CheckUses_CheckStatmSeq((OOC_IR_CheckUses__Def)i2, (OOC_IR__StatementSeq)i1);
  i1 = (OOC_INT32)def;
  i1 = *(OOC_UINT8*)((_check_pointer(i1, 33061))+4);
  i1 = !i1;
  if (i1) goto l39;
  i1=0u;
  goto l41;
l39:
  i1 = (OOC_INT32)proc;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 33096))+4);
  i1 = OOC_IR_CheckUses__CheckUses_CheckedFunction((OOC_SymbolTable__ProcDecl)i1);
  
l41:
  if (!i1) goto l44;
  i1 = (OOC_INT32)proc;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 33154))+16);
  i2 = (OOC_INT32)pragmaHistory;
  i3 = (OOC_INT32)errList;
  OOC_IR_CheckUses__WarnSym((OOC_Error__List)i3, (OOC_Config_Pragmas__History)i2, (OOC_Scanner_SymList__Symbol)i1, 4);
l44:
  i1 = i;
  i1 = i1+1;
  i = i1;
  i2 = i1<i0;
  if (i2) goto l34_loop;
l49:
  return;
  ;
}

void OOC_OOC_IR_CheckUses_init(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_IR_CheckUses__ErrorContext.baseTypes[0]);
  OOC_IR_CheckUses__checkUsesContext = (OOC_IR_CheckUses__ErrorContext)i0;
  OOC_Error__InitContext((OOC_Error__Context)i0, "OOC:IR:CheckUses", 17);
  i0 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(17);
  OOC_IR_CheckUses__any = (OOC_SymbolTable__Type)i0;
  return;
  ;
}

void OOC_OOC_IR_CheckUses_destroy(void) {
}

/* --- */
