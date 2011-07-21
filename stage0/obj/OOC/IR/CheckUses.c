#include <OOC/IR/CheckUses.d>
#include <__oo2c.h>
#include <setjmp.h>

void OOC_IR_CheckUses__ErrorContextDesc_GetTemplate(OOC_IR_CheckUses__ErrorContext context, Msg__Msg msg, Msg__LString templ, OOC_LEN templ_0d) {
  register OOC_INT32 i0,i1;
  OOC_CHAR16 t[128];

  i0 = (OOC_INT32)msg;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 5010))+8);
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
    _failed_case(i1, 5002);
    goto l9;
  }
l9:
  i1 = (OOC_INT32)context;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5572)))), OOC_Error__ContextDesc_BaseTemplate)),OOC_Error__ContextDesc_BaseTemplate)((OOC_Error__Context)i1, (Msg__Msg)i0, (void*)(OOC_INT32)t, 128, (void*)(OOC_INT32)templ, templ_0d);
  return;
  ;
}

void OOC_IR_CheckUses__VisitorCallsDesc_VisitCall(OOC_IR_CheckUses__VisitorCalls v, OOC_IR__Call call) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_SymbolTable__Declaration procDecl;
  Object__Object obj;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)call;
  OOC_IR_VisitAll__VisitorDesc_VisitCall((OOC_IR_VisitAll__Visitor)i0, (OOC_IR__Call)i1);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5791))+8);
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 5799)))), &_td_OOC_IR__ProcedureRefDesc);
  if (i2) goto l3;
  i2=0u;
  goto l5;
l3:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5852))+8);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5829))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 5863)))), &_td_OOC_IR__ProcedureRefDesc, 5863)), 5876))+8);
  i2 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i3, (Object__Object)i2);
  
l5:
  if (!i2) goto l7;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5910))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5921)))), &_td_OOC_IR__ProcedureRefDesc, 5921)), 5934))+8);
  procDecl = (OOC_SymbolTable__Declaration)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5955))+4);
  i1 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i2, (Object__Object)i1);
  obj = (Object__Object)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5992)))), &_td_OOC_IR_CheckUses__ProcDataDesc, 5992)), 6001));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6018));
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5992)))), &_td_OOC_IR_CheckUses__ProcDataDesc, 5992)), 6001));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 6009)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i1, (Object__Object)i0);
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
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6460))+8);
  i = 0;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 6469)), 0);
  i3 = 0<i2;
  if (!i3) goto l8;
  i3=0;
l3_loop:
  i4 = (OOC_INT32)RT0__NewObject(_td_OOC_IR_CheckUses__ProcData.baseTypes[0]);
  pd = (OOC_IR_CheckUses__ProcData)i4;
  i5 = (OOC_INT32)ADT_ArrayList__New(4);
  *(OOC_INT32*)(_check_pointer(i4, 6500)) = i5;
  i5 = (OOC_INT32)ADT_Dictionary_IntValue__New();
  *(OOC_INT32*)((_check_pointer(i4, 6538))+4) = i5;
  *(OOC_UINT8*)((_check_pointer(i4, 6571))+8) = 1u;
  *(OOC_UINT8*)((_check_pointer(i4, 6600))+9) = 0u;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6651))+8);
  i5 = _check_pointer(i5, 6660);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 6660))*4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 6663))+4);
  ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i0, (Object__Object)i5, (Object__Object)i4);
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l3_loop;
l8:
  i2 = (OOC_INT32)RT0__NewObject(_td_OOC_IR_CheckUses__VisitorCalls.baseTypes[0]);
  v = (OOC_IR_CheckUses__VisitorCalls)i2;
  OOC_IR_VisitAll__InitVisitor((OOC_IR_VisitAll__Visitor)i2);
  *(OOC_INT32*)((_check_pointer(i2, 6731))+4) = i0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6787))+8);
  i = 0;
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 6796)), 0);
  i4 = 0<i3;
  if (!i4) goto l16;
  i4=0;
l11_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6831))+8);
  i5 = _check_pointer(i5, 6840);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 6840))*4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 6843))+4);
  *(OOC_INT32*)(_check_pointer(i2, 6811)) = i5;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6862))+8);
  i5 = _check_pointer(i5, 6871);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 6871))*4);
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
  *(OOC_INT32*)(_check_pointer(i0, 7014)) = i1;
  *(OOC_UINT8*)((_check_pointer(i0, 7046))+4) = 0u;
  return (OOC_IR_CheckUses__Def)i0;
  ;
}

OOC_IR_CheckUses__Def OOC_IR_CheckUses__DefDesc_Copy(OOC_IR_CheckUses__Def def) {
  register OOC_INT32 i0,i1,i2;
  OOC_IR_CheckUses__Def def2;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_IR_CheckUses__Def.baseTypes[0]);
  def2 = (OOC_IR_CheckUses__Def)i0;
  i1 = (OOC_INT32)def;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 7199));
  i2 = (OOC_INT32)ADT_Dictionary_IntValue__DictionaryDesc_Copy((ADT_Dictionary_IntValue__Dictionary)i2);
  *(OOC_INT32*)(_check_pointer(i0, 7186)) = i2;
  i1 = *(OOC_UINT8*)((_check_pointer(i1, 7241))+4);
  *(OOC_UINT8*)((_check_pointer(i0, 7222))+4) = i1;
  return (OOC_IR_CheckUses__Def)i0;
  ;
}

OOC_INT32 OOC_IR_CheckUses__DefDesc_GetClass(OOC_IR_CheckUses__Def def, OOC_SymbolTable__Item var) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)def;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7358));
  i2 = (OOC_INT32)var;
  i1 = ADT_Dictionary_IntValue__DictionaryDesc_HasKey((ADT_Dictionary_IntValue__Dictionary)i1, (Object__Object)i2);
  if (i1) goto l3;
  return 0;
  goto l4;
l3:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7398));
  i0 = ADT_Dictionary_IntValue__DictionaryDesc_Get((ADT_Dictionary_IntValue__Dictionary)i0, (Object__Object)i2);
  return i0;
l4:
  _failed_function(7306); return 0;
  ;
}

void OOC_IR_CheckUses__DefDesc_SetClass(OOC_IR_CheckUses__Def def, OOC_SymbolTable__Item var, OOC_INT32 _class) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)def;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7551));
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
      _failed_function(7713); return 0;
      ;
    }


  i0 = (OOC_INT32)def;
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 7906))+4);
  if (i1) goto l22;
  i1 = (OOC_INT32)def2;
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 8020))+4);
  i2 = !i2;
  if (!i2) goto l23;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 8078));
  i2 = (OOC_INT32)ADT_Dictionary_IntValue__DictionaryDesc_Keys((ADT_Dictionary_IntValue__Dictionary)i2);
  k = (Object__ObjectArrayPtr)i2;
  i = 0;
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i2, 8118)), 0);
  i4 = 0<i3;
  if (!i4) goto l12;
  i4=0;
l7_loop:
  i5 = _check_pointer(i2, 8140);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 8140))*4);
  i5 = _type_guard(i5, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 8148)))), &_td_OOC_SymbolTable__ItemDesc, 8148);
  v = (OOC_SymbolTable__Item)i5;
  i6 = OOC_IR_CheckUses__DefDesc_GetClass((OOC_IR_CheckUses__Def)i0, (OOC_SymbolTable__Item)i5);
  i7 = OOC_IR_CheckUses__DefDesc_GetClass((OOC_IR_CheckUses__Def)i1, (OOC_SymbolTable__Item)i5);
  i6 = OOC_IR_CheckUses__DefDesc_Merge_Merge(i6, i7);
  OOC_IR_CheckUses__DefDesc_SetClass((OOC_IR_CheckUses__Def)i0, (OOC_SymbolTable__Item)i5, i6);
  i4 = i4+1;
  i = i4;
  i5 = i4<i3;
  if (i5) goto l7_loop;
l12:
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 8255));
  i2 = (OOC_INT32)ADT_Dictionary_IntValue__DictionaryDesc_Keys((ADT_Dictionary_IntValue__Dictionary)i2);
  k = (Object__ObjectArrayPtr)i2;
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i2, 8295)), 0);
  i = 0;
  i4 = 0<i3;
  if (!i4) goto l23;
  i4=0;
l15_loop:
  i5 = _check_pointer(i2, 8317);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 8317))*4);
  i5 = _type_guard(i5, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 8325)))), &_td_OOC_SymbolTable__ItemDesc, 8325);
  v = (OOC_SymbolTable__Item)i5;
  i6 = OOC_IR_CheckUses__DefDesc_GetClass((OOC_IR_CheckUses__Def)i0, (OOC_SymbolTable__Item)i5);
  i7 = OOC_IR_CheckUses__DefDesc_GetClass((OOC_IR_CheckUses__Def)i1, (OOC_SymbolTable__Item)i5);
  i6 = OOC_IR_CheckUses__DefDesc_Merge_Merge(i6, i7);
  OOC_IR_CheckUses__DefDesc_SetClass((OOC_IR_CheckUses__Def)i0, (OOC_SymbolTable__Item)i5, i6);
  i4 = i4+1;
  i = i4;
  i5 = i4<i3;
  if (i5) goto l15_loop;
  goto l23;
l22:
  i1 = (OOC_INT32)def2;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 7947));
  i2 = (OOC_INT32)ADT_Dictionary_IntValue__DictionaryDesc_Copy((ADT_Dictionary_IntValue__Dictionary)i2);
  *(OOC_INT32*)(_check_pointer(i0, 7933)) = i2;
  i1 = *(OOC_UINT8*)((_check_pointer(i1, 7991))+4);
  *(OOC_UINT8*)((_check_pointer(i0, 7971))+4) = i1;
l23:
  return;
  ;
}

void OOC_IR_CheckUses__DefDesc_Unreachable(OOC_IR_CheckUses__Def def) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)def;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 8536));
  ADT_Dictionary_IntValue__DictionaryDesc_Clear((ADT_Dictionary_IntValue__Dictionary)i1);
  *(OOC_UINT8*)((_check_pointer(i0, 8559))+4) = 1u;
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

  i0 = (OOC_INT32)OOC_Config_StdPragmas__warnings;
  i1 = (OOC_INT32)sym;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9001))+4);
  i2 = *(OOC_INT32*)((_check_pointer(i1, 9011))+16);
  i3 = (OOC_INT32)pragmaHistory;
  i0 = (OOC_INT32)OOC_Config_Pragmas__HistoryDesc_GetValue((OOC_Config_Pragmas__History)i3, (Object__String)i0, i2);
  value = (Config__Variable)i0;
  i0 = *(OOC_UINT8*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9038)))), &_td_Config__BooleanVarDesc, 9038)), 9049));
  if (i0) goto l3;
  return (Msg__Msg)0;
  goto l4;
l3:
  i0 = (OOC_INT32)OOC_IR_CheckUses__checkUsesContext;
  i2 = code;
  i0 = (OOC_INT32)OOC_Error__New((OOC_Error__Context)i0, i2);
  e = (Msg__Msg)i0;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 9140))+16);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9116)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i0, "pos", 4, i2);
  i2 = *(OOC_INT32*)((_check_pointer(i1, 9179))+20);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9154)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i0, "line", 5, i2);
  i1 = *(OOC_INT32*)((_check_pointer(i1, 9221))+24);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9194)))), Msg__MsgDesc_SetIntAttrib)),Msg__MsgDesc_SetIntAttrib)((Msg__Msg)i0, "column", 7, i1);
  i1 = (OOC_INT32)errList;
  OOC_Error__ListDesc_Append((OOC_Error__List)i1, (Msg__Msg)i0);
  return (Msg__Msg)i0;
l4:
  _failed_function(8762); return 0;
  ;
}

static void OOC_IR_CheckUses__WarnSym(OOC_Error__List errList, OOC_Config_Pragmas__History pragmaHistory, OOC_Scanner_SymList__Symbol sym, OOC_INT32 code) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)errList;
  i1 = (OOC_INT32)pragmaHistory;
  i2 = (OOC_INT32)sym;
  i3 = code;
  i0 = (OOC_INT32)OOC_IR_CheckUses__WarnSymE((OOC_Error__List)i0, (OOC_Config_Pragmas__History)i1, (OOC_Scanner_SymList__Symbol)i2, i3);
  return;
  ;
}

static void OOC_IR_CheckUses__WarnSymV(OOC_IR_CheckUses__Visitor v, OOC_Scanner_SymList__Symbol sym, OOC_INT32 code, OOC_SymbolTable__VarDecl varDecl) {
  register OOC_INT32 i0,i1,i2,i3;
  Msg__Msg e;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9704));
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9715))+4);
  i2 = (OOC_INT32)sym;
  i3 = code;
  i0 = (OOC_INT32)OOC_IR_CheckUses__WarnSymE((OOC_Error__List)i1, (OOC_Config_Pragmas__History)i0, (OOC_Scanner_SymList__Symbol)i2, i3);
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
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 9839))+20);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 9844))+12);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 9839))+20);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 9844))+12);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 9848)), 0);
  i1 = (OOC_INT32)Msg__GetStringPtr((void*)(_check_pointer(i2, 9848)), i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9790)))), Msg__MsgDesc_SetStringAttrib)),Msg__MsgDesc_SetStringAttrib)((Msg__Msg)i0, "name", 5, (Msg__StringPtr)i1);
l7:
  return;
  ;
}

static OOC_CHAR8 OOC_IR_CheckUses__NonlocalVar(OOC_SymbolTable__ProcDecl localProc, OOC_SymbolTable__VarDecl varDecl) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)varDecl;
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 10097))+59);
  if (i1) goto l3;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10163)))), OOC_SymbolTable__ItemDesc_Procedure)),OOC_SymbolTable__ItemDesc_Procedure)((OOC_SymbolTable__Item)i0);
  i1 = (OOC_INT32)localProc;
  return (i0!=i1);
  goto l4;
l3:
  return 1u;
l4:
  _failed_function(9890); return 0;
  ;
}

void OOC_IR_CheckUses__ProcDataDesc_SetReadFlag(OOC_IR_CheckUses__ProcData pd, OOC_SymbolTable__VarDecl varDecl, OOC_INT32 flag) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT32 oldFlag;
  OOC_INT32 newFlag;

  i0 = (OOC_INT32)pd;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10405))+4);
  i2 = (OOC_INT32)varDecl;
  i1 = ADT_Dictionary_IntValue__DictionaryDesc_HasKey((ADT_Dictionary_IntValue__Dictionary)i1, (Object__Object)i2);
  if (i1) goto l3;
  oldFlag = 0;
  i1=0;
  goto l4;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10452))+4);
  i1 = ADT_Dictionary_IntValue__DictionaryDesc_Get((ADT_Dictionary_IntValue__Dictionary)i1, (Object__Object)i2);
  oldFlag = i1;
  
l4:
  i3 = flag;
  i3 = (_mod(i1,4))+i3*4;
  newFlag = i3;
  i4 = i3!=i1;
  if (!i4) goto l7;
  _assert((i1<i3), 127, 10635);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10670))+4);
  ADT_Dictionary_IntValue__DictionaryDesc_Set((ADT_Dictionary_IntValue__Dictionary)i1, (Object__Object)i2, i3);
  *(OOC_UINT8*)((_check_pointer(i0, 10708))+9) = 1u;
l7:
  return;
  ;
}

void OOC_IR_CheckUses__ProcDataDesc_SetWriteFlag(OOC_IR_CheckUses__ProcData pd, OOC_SymbolTable__Item item, OOC_INT32 flag) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT32 oldFlag;
  OOC_INT32 newFlag;

  i0 = (OOC_INT32)pd;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10884))+4);
  i2 = (OOC_INT32)item;
  i1 = ADT_Dictionary_IntValue__DictionaryDesc_HasKey((ADT_Dictionary_IntValue__Dictionary)i1, (Object__Object)i2);
  if (i1) goto l3;
  oldFlag = 0;
  i1=0;
  goto l4;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10928))+4);
  i1 = ADT_Dictionary_IntValue__DictionaryDesc_Get((ADT_Dictionary_IntValue__Dictionary)i1, (Object__Object)i2);
  oldFlag = i1;
  
l4:
  i3 = flag;
  i3 = i3+(i1>>2)*4;
  newFlag = i3;
  i4 = i3!=i1;
  if (!i4) goto l7;
  _assert((i1>i3), 127, 11110);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11145))+4);
  ADT_Dictionary_IntValue__DictionaryDesc_Set((ADT_Dictionary_IntValue__Dictionary)i1, (Object__Object)i2, i3);
  *(OOC_UINT8*)((_check_pointer(i0, 11180))+9) = 1u;
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
      i1 = *(OOC_UINT8*)((_check_pointer(i0, 11465))+56);
      i1 = !i1;
      if (i1) goto l3;
      i0=0u;
      goto l4;
l3:
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11498)))), OOC_SymbolTable__ItemDesc_Procedure)),OOC_SymbolTable__ItemDesc_Procedure)((OOC_SymbolTable__Item)i0);
      i1 = (OOC_INT32)v;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11514))+20);
      i0 = i0==i1;
      
l4:
      return i0;
      ;
    }


  i0 = (OOC_INT32)varDecl;
  i0 = OOC_IR_CheckUses__EmitVarWarning_LocalVar((OOC_SymbolTable__VarDecl)i0);
  if (!i0) goto l28;
  i0 = (OOC_INT32)v;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 11597))+32);
  i1 = i1==0;
  if (i1) goto l12;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 12145))+32);
  i1 = i1==1;
  if (i1) goto l10;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12221))+28);
  i2 = (OOC_INT32)varDecl;
  i1 = OOC_IR_CheckUses__DefDesc_GetClass((OOC_IR_CheckUses__Def)i1, (OOC_SymbolTable__Item)i2);
  i1 = i1!=2;
  if (!i1) goto l28;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12294))+28);
  OOC_IR_CheckUses__DefDesc_SetClass((OOC_IR_CheckUses__Def)i0, (OOC_SymbolTable__Item)i2, 1);
  goto l28;
l10:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12174))+28);
  i1 = (OOC_INT32)varDecl;
  OOC_IR_CheckUses__DefDesc_SetClass((OOC_IR_CheckUses__Def)i0, (OOC_SymbolTable__Item)i1, 2);
  goto l28;
l12:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11634))+28);
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
    _failed_case(i1, 11666);
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
  i1 = *(OOC_INT8*)((_check_pointer(i0, 12560))+8);
  switch (i1) {
  case 0:
    i1 = *(OOC_INT8*)((_check_pointer(i0, 12605))+32);
    i1 = i1>=1;
    if (i1) goto l5;
    i1=0u;
    goto l7;
l5:
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12636))+20);
    i2 = (OOC_INT32)varDecl;
    i1 = OOC_IR_CheckUses__NonlocalVar((OOC_SymbolTable__ProcDecl)i1, (OOC_SymbolTable__VarDecl)i2);
    
l7:
    if (!i1) goto l30;
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12677))+12);
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12694))+20);
    i0 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i1, (Object__Object)i0);
    pb = (Object__Object)i0;
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12718)))), &_td_OOC_IR_CheckUses__ProcDataDesc, 12718)), 12727))+4);
    i1 = (OOC_INT32)varDecl;
    ADT_Dictionary_IntValue__DictionaryDesc_Set((ADT_Dictionary_IntValue__Dictionary)i0, (Object__Object)i1, 2);
    goto l30;
  case 1:
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12817))+20);
    i2 = (OOC_INT32)varDecl;
    i1 = OOC_IR_CheckUses__NonlocalVar((OOC_SymbolTable__ProcDecl)i1, (OOC_SymbolTable__VarDecl)i2);
    if (!i1) goto l30;
    i1 = *(OOC_INT8*)((_check_pointer(i0, 12856))+32);
    i1 = i1==0;
    if (i1) goto l22;
    i1 = *(OOC_INT8*)((_check_pointer(i0, 13046))+32);
    i1 = i1==1;
    if (i1) goto l20;
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13126))+28);
    i1 = OOC_IR_CheckUses__DefDesc_GetClass((OOC_IR_CheckUses__Def)i1, (OOC_SymbolTable__Item)i2);
    i1 = i1!=2;
    if (!i1) goto l30;
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13201))+28);
    OOC_IR_CheckUses__DefDesc_SetClass((OOC_IR_CheckUses__Def)i0, (OOC_SymbolTable__Item)i2, 1);
    goto l30;
l20:
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13077))+28);
    OOC_IR_CheckUses__DefDesc_SetClass((OOC_IR_CheckUses__Def)i0, (OOC_SymbolTable__Item)i2, 2);
    goto l30;
l22:
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12895))+28);
    i1 = OOC_IR_CheckUses__DefDesc_GetClass((OOC_IR_CheckUses__Def)i1, (OOC_SymbolTable__Item)i2);
    _class = i1;
    i1 = i1!=2;
    if (!i1) goto l30;
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12968))+24);
    OOC_IR_CheckUses__ProcDataDesc_SetReadFlag((OOC_IR_CheckUses__ProcData)i0, (OOC_SymbolTable__VarDecl)i2, 1);
    goto l30;
  case 2:
    i1 = (OOC_INT32)sym;
    i2 = contextCall;
    i3 = (OOC_INT32)varDecl;
    OOC_IR_CheckUses__EmitVarWarning((OOC_IR_CheckUses__Visitor)i0, (OOC_SymbolTable__VarDecl)i3, (OOC_Scanner_SymList__Symbol)i1, i2);
    goto l30;
  default:
    _failed_case(i1, 12554);
    goto l30;
  }
l30:
  return;
  ;
}

void OOC_IR_CheckUses__VisitorDesc_VisitVar(OOC_IR_CheckUses__Visitor v, OOC_IR__Var var) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)var;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13457))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13480));
  i2 = (OOC_INT32)v;
  OOC_IR_CheckUses__VisitVarDecl((OOC_IR_CheckUses__Visitor)i2, (OOC_SymbolTable__VarDecl)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 13467)))), &_td_OOC_SymbolTable__VarDeclDesc, 13467)), (OOC_Scanner_SymList__Symbol)i0, 0u);
  return;
  ;
}

void OOC_IR_CheckUses__VisitorDesc_VisitDeref(OOC_IR_CheckUses__Visitor v, OOC_IR__Deref deref) {
  register OOC_INT32 i0,i1,i2,i3;
  Object__Object pb;
  OOC_INT8 oldMode;

  i0 = (OOC_INT32)v;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 13635))+8);
  switch (i1) {
  case 0:
    i1 = *(OOC_INT8*)((_check_pointer(i0, 13680))+32);
    i1 = i1>=1;
    if (!i1) goto l12;
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13716))+12);
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13733))+20);
    i0 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i1, (Object__Object)i0);
    pb = (Object__Object)i0;
    i1 = (OOC_INT32)deref;
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13757)))), &_td_OOC_IR_CheckUses__ProcDataDesc, 13757)), 13766))+4);
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 13782))+4);
    ADT_Dictionary_IntValue__DictionaryDesc_Set((ADT_Dictionary_IntValue__Dictionary)i0, (Object__Object)i1, 2);
    goto l12;
  case 1:
  case 2:
    i1 = *(OOC_INT8*)((_check_pointer(i0, 13866))+32);
    i1 = i1==0;
    if (i1) goto l9;
    i1 = (OOC_INT32)deref;
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13938))+28);
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 13957))+4);
    OOC_IR_CheckUses__DefDesc_SetClass((OOC_IR_CheckUses__Def)i2, (OOC_SymbolTable__Item)i3, 2);
    i2 = *(OOC_INT8*)((_check_pointer(i0, 13994))+32);
    oldMode = i2;
    *(OOC_INT8*)((_check_pointer(i0, 14010))+32) = 0;
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14038))+8);
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14038))+8);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 14046)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i1, (OOC_IR__Visitor)i0);
    *(OOC_INT8*)((_check_pointer(i0, 14067))+32) = i2;
    goto l12;
l9:
    i1 = (OOC_INT32)deref;
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 13898))+8);
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 13898))+8);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 13906)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i1, (OOC_IR__Visitor)i0);
    goto l12;
  default:
    _failed_case(i1, 13629);
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
  i1 = *(OOC_INT8*)((_check_pointer(i0, 14231))+32);
  oldMode = i1;
  i2 = (OOC_INT32)index;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14247))+8);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14247))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 14253)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i4, (OOC_IR__Visitor)i0);
  *(OOC_INT8*)((_check_pointer(i0, 14271))+32) = 0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14295))+12);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14295))+12);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 14301)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i2, (OOC_IR__Visitor)i0);
  *(OOC_INT8*)((_check_pointer(i0, 14319))+32) = i1;
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
  i1 = *(OOC_INT8*)((_check_pointer(i0, 14855))+32);
  oldMode = i1;
  i2 = (OOC_INT32)call;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14870))+8);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14870))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 14877)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i4, (OOC_IR__Visitor)i0);
  i3 = *(OOC_INT8*)((_check_pointer(i0, 14904))+8);
  switch (i3) {
  case 0:
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14953))+8);
    i3 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 14961)))), &_td_OOC_IR__ProcedureRefDesc));
    if (i3) goto l5;
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14997))+8);
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 15008)))), &_td_OOC_IR__ProcedureRefDesc, 15008)), 15021))+8);
    i3 = *(OOC_UINT8*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 15031)))), &_td_OOC_SymbolTable__ProcDeclDesc, 15031)), 15040))+52);
    
    goto l7;
l5:
    i3=1u;
l7:
    if (!i3) goto l9;
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15070))+24);
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 15084))+4);
    i4 = (OOC_INT32)OOC_IR_CheckUses__any;
    ADT_Dictionary_IntValue__DictionaryDesc_Set((ADT_Dictionary_IntValue__Dictionary)i3, (Object__Object)i4, 2);
l9:
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 15178))+12);
    i = 0;
    i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 15188)), 0);
    i4 = 0<i3;
    if (!i4) goto l131;
    i4=0;
l12_loop:
    i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 15212))+16);
    i5 = _check_pointer(i5, 15223);
    i6 = OOC_ARRAY_LENGTH(i5, 0);
    i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 15223))*4);
    i5 = i5!=(OOC_INT32)0;
    if (i5) goto l15;
    i5=0u;
    goto l17;
l15:
    i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 15240))+16);
    i5 = _check_pointer(i5, 15251);
    i6 = OOC_ARRAY_LENGTH(i5, 0);
    i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 15251))*4);
    i5 = *(OOC_UINT8*)((_check_pointer(i5, 15254))+59);
    
l17:
    if (i5) goto l19;
    *(OOC_INT8*)((_check_pointer(i0, 15475))+32) = 0;
    i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 15504))+12);
    i5 = _check_pointer(i5, 15514);
    i6 = OOC_ARRAY_LENGTH(i5, 0);
    i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 15514))*4);
    i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 15504))+12);
    i6 = _check_pointer(i6, 15514);
    i7 = OOC_ARRAY_LENGTH(i6, 0);
    i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i4, i7, OOC_UINT32, 15514))*4);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 15517)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i6, (OOC_IR__Visitor)i0);
    goto l23;
l19:
    i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 15290))+12);
    i5 = _check_pointer(i5, 15300);
    i6 = OOC_ARRAY_LENGTH(i5, 0);
    i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 15300))*4);
    i5 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 15304)))), &_td_OOC_IR__ConstDesc));
    if (!i5) goto l23;
    *(OOC_INT8*)((_check_pointer(i0, 15364))+32) = 1;
    i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 15396))+12);
    i5 = _check_pointer(i5, 15406);
    i6 = OOC_ARRAY_LENGTH(i5, 0);
    i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 15406))*4);
    i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i5, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 15413)))), &_td_OOC_IR__AdrDesc, 15413)), 15417))+8);
    i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 15396))+12);
    i6 = _check_pointer(i6, 15406);
    i7 = OOC_ARRAY_LENGTH(i6, 0);
    i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i4, i7, OOC_UINT32, 15406))*4);
    i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i6, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 15413)))), &_td_OOC_IR__AdrDesc, 15413)), 15417))+8);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 15424)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i6, (OOC_IR__Visitor)i0);
l23:
    i4 = i4+1;
    i = i4;
    i5 = i4<i3;
    if (i5) goto l12_loop;
    goto l131;
  case 1:
  case 2:
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 15618))+8);
    i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 15626)))), &_td_OOC_IR__ProcedureRefDesc);
    if (i3) goto l32;
    i3=0u;
    goto l34;
l32:
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 15681))+8);
    i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15658))+12);
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 15692)))), &_td_OOC_IR__ProcedureRefDesc, 15692)), 15705))+8);
    i3 = ADT_Dictionary__DictionaryDesc_HasKey((ADT_Dictionary__Dictionary)i4, (Object__Object)i3);
    
l34:
    if (i3) goto l43;
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 15918))+8);
    i3 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 15926)))), &_td_OOC_IR__ProcedureRefDesc));
    if (i3) goto l38;
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 15964))+8);
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 15975)))), &_td_OOC_IR__ProcedureRefDesc, 15975)), 15988))+8);
    i3 = *(OOC_UINT8*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 15998)))), &_td_OOC_SymbolTable__ProcDeclDesc, 15998)), 16007))+52);
    
    goto l40;
l38:
    i3=1u;
l40:
    if (!i3) goto l42;
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16039))+28);
    i4 = (OOC_INT32)OOC_IR_CheckUses__any;
    OOC_IR_CheckUses__DefDesc_SetClass((OOC_IR_CheckUses__Def)i3, (OOC_SymbolTable__Item)i4, 2);
l42:
    callee = (OOC_SymbolTable__ProcDecl)(OOC_INT32)0;
    inout = (ADT_Dictionary_IntValue__Dictionary)(OOC_INT32)0;
    i3=(OOC_INT32)0;i4=(OOC_INT32)0;
    goto l44;
l43:
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 15739))+8);
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 15750)))), &_td_OOC_IR__ProcedureRefDesc, 15750)), 15763))+8);
    i3 = _type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 15773)))), &_td_OOC_SymbolTable__ProcDeclDesc, 15773);
    callee = (OOC_SymbolTable__ProcDecl)i3;
    i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 15820))+8);
    i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15800))+12);
    i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 15831)))), &_td_OOC_IR__ProcedureRefDesc, 15831)), 15844))+8);
    i4 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i5, (Object__Object)i4);
    obj = (Object__Object)i4;
    i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 15873)))), &_td_OOC_IR_CheckUses__ProcDataDesc, 15873)), 15882))+4);
    inout = (ADT_Dictionary_IntValue__Dictionary)i4;
    {register OOC_INT32 h0=i3;i3=i4;i4=h0;}
l44:
    i5 = (OOC_INT32)ADT_ArrayList__New(8);
    readList = (ADT_ArrayList__ArrayList)i5;
    i6 = (OOC_INT32)ADT_ArrayList__New(8);
    writeList = (ADT_ArrayList__ArrayList)i6;
    i7 = (OOC_INT32)ADT_Dictionary_IntValue__New();
    writeMaybeDict = (ADT_Dictionary_IntValue__Dictionary)i7;
    i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 16317))+12);
    i = 0;
    i8 = OOC_ARRAY_LENGTH((_check_pointer(i8, 16327)), 0);
    i9 = 0<i8;
    if (!i9) goto l80;
    i9 = i3==(OOC_INT32)0;
    i10=0;
l47_loop:
    i11 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 16351))+16);
    i11 = _check_pointer(i11, 16362);
    i12 = OOC_ARRAY_LENGTH(i11, 0);
    i11 = (OOC_INT32)*(OOC_INT32*)(i11+(_check_index(i10, i12, OOC_UINT32, 16362))*4);
    i11 = i11==(OOC_INT32)0;
    if (i11) goto l75;
    i11 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 16419))+16);
    i11 = _check_pointer(i11, 16430);
    i12 = OOC_ARRAY_LENGTH(i11, 0);
    i11 = (OOC_INT32)*(OOC_INT32*)(i11+(_check_index(i10, i12, OOC_UINT32, 16430))*4);
    i11 = *(OOC_UINT8*)((_check_pointer(i11, 16433))+59);
    if (i11) goto l52;
    i11 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 17383))+12);
    i11 = _check_pointer(i11, 17393);
    i12 = OOC_ARRAY_LENGTH(i11, 0);
    i11 = (OOC_INT32)*(OOC_INT32*)(i11+(_check_index(i10, i12, OOC_UINT32, 17393))*4);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 17371)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i5, (Object__Object)i11);
    goto l75;
l52:
    i11 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 16469))+12);
    i11 = _check_pointer(i11, 16479);
    i12 = OOC_ARRAY_LENGTH(i11, 0);
    i11 = (OOC_INT32)*(OOC_INT32*)(i11+(_check_index(i10, i12, OOC_UINT32, 16479))*4);
    i11 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i11, 16483)))), &_td_OOC_IR__ConstDesc));
    if (!i11) goto l75;
    i11 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 16556))+12);
    i11 = _check_pointer(i11, 16566);
    i12 = OOC_ARRAY_LENGTH(i11, 0);
    i11 = (OOC_INT32)*(OOC_INT32*)(i11+(_check_index(i10, i12, OOC_UINT32, 16566))*4);
    i11 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i11, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i11, 16573)))), &_td_OOC_IR__AdrDesc, 16573)), 16577))+8);
    design = (OOC_IR__Expression)i11;
    if (i9) goto l71;
    i12 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 16734))+16);
    i12 = _check_pointer(i12, 16745);
    i13 = OOC_ARRAY_LENGTH(i12, 0);
    i12 = (OOC_INT32)*(OOC_INT32*)(i12+(_check_index(i10, i13, OOC_UINT32, 16745))*4);
    i12 = ADT_Dictionary_IntValue__DictionaryDesc_HasKey((ADT_Dictionary_IntValue__Dictionary)i3, (Object__Object)i12);
    if (!i12) goto l75;
    i12 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 16792))+16);
    i12 = _check_pointer(i12, 16803);
    i13 = OOC_ARRAY_LENGTH(i12, 0);
    i12 = (OOC_INT32)*(OOC_INT32*)(i12+(_check_index(i10, i13, OOC_UINT32, 16803))*4);
    i12 = ADT_Dictionary_IntValue__DictionaryDesc_Get((ADT_Dictionary_IntValue__Dictionary)i3, (Object__Object)i12);
    _class = i12;
    i13 = i12>>2;
    switch (i13) {
    case 1:
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 16898)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i5, (Object__Object)i11);
      goto l63;
    case 0:
      goto l63;
    default:
      _failed_case(i13, 16823);
      goto l63;
    }
l63:
    i12 = _mod(i12,4);
    switch (i12) {
    case 2:
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 17098)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i6, (Object__Object)i11);
      goto l75;
    case 1:
      ADT_Dictionary_IntValue__DictionaryDesc_Set((ADT_Dictionary_IntValue__Dictionary)i7, (Object__Object)i11, 0);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 17213)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i6, (Object__Object)i11);
      goto l75;
    case 0:
      goto l75;
    default:
      _failed_case(i12, 17021);
      goto l75;
    }
l71:
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 16682)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i6, (Object__Object)i11);
l75:
    i10 = i10+1;
    i = i10;
    i11 = i10<i8;
    if (i11) goto l47_loop;
l80:
    i8 = *(OOC_INT32*)((_check_pointer(i5, 17452))+4);
    i = 0;
    i9 = 0<i8;
    if (!i9) goto l88;
    i9=0;
l83_loop:
    *(OOC_INT8*)((_check_pointer(i0, 17472))+32) = 0;
    i10 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 17503));
    i10 = _check_pointer(i10, 17509);
    i11 = OOC_ARRAY_LENGTH(i10, 0);
    i10 = (OOC_INT32)*(OOC_INT32*)(i10+(_check_index(i9, i11, OOC_UINT32, 17509))*4);
    i11 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 17503));
    i11 = _check_pointer(i11, 17509);
    i12 = OOC_ARRAY_LENGTH(i11, 0);
    i11 = (OOC_INT32)*(OOC_INT32*)(i11+(_check_index(i9, i12, OOC_UINT32, 17509))*4);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer((_type_guard(i10, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i10, 17516)))), &_td_OOC_IR__ExpressionDesc, 17516)), 17527)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)(_type_guard(i11, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i11, 17516)))), &_td_OOC_IR__ExpressionDesc, 17516)), (OOC_IR__Visitor)i0);
    i9 = i9+1;
    i = i9;
    i10 = i9<i8;
    if (i10) goto l83_loop;
l88:
    i5 = i3!=(OOC_INT32)0;
    if (!i5) goto l117;
    i5 = (OOC_INT32)ADT_Dictionary_IntValue__DictionaryDesc_Keys((ADT_Dictionary_IntValue__Dictionary)i3);
    k = (Object__ObjectArrayPtr)i5;
    i8 = OOC_ARRAY_LENGTH((_check_pointer(i5, 17639)), 0);
    i = 0;
    i9 = 0<i8;
    if (!i9) goto l117;
    i9=0;
l93_loop:
    i10 = _check_pointer(i5, 17662);
    i11 = OOC_ARRAY_LENGTH(i10, 0);
    i10 = (OOC_INT32)*(OOC_INT32*)(i10+(_check_index(i9, i11, OOC_UINT32, 17662))*4);
    i10 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i10, 17666)))), &_td_OOC_SymbolTable__VarDeclDesc);
    if (i10) goto l96;
    i10 = _check_pointer(i5, 18526);
    i11 = OOC_ARRAY_LENGTH(i10, 0);
    i10 = (OOC_INT32)*(OOC_INT32*)(i10+(_check_index(i9, i11, OOC_UINT32, 18526))*4);
    i11 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18511))+28);
    OOC_IR_CheckUses__DefDesc_SetClass((OOC_IR_CheckUses__Def)i11, (OOC_SymbolTable__Item)(_type_guard(i10, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i10, 18534)))), &_td_OOC_SymbolTable__TypeDesc, 18534)), 2);
    goto l111;
l96:
    i10 = _check_pointer(i5, 17711);
    i11 = OOC_ARRAY_LENGTH(i10, 0);
    i10 = (OOC_INT32)*(OOC_INT32*)(i10+(_check_index(i9, i11, OOC_UINT32, 17711))*4);
    i10 = _type_guard(i10, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i10, 17719)))), &_td_OOC_SymbolTable__VarDeclDesc, 17719);
    varDecl = (OOC_SymbolTable__VarDecl)i10;
    i11 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i10, 17752)))), OOC_SymbolTable__ItemDesc_Procedure)),OOC_SymbolTable__ItemDesc_Procedure)((OOC_SymbolTable__Item)i10);
    i11 = i11!=i4;
    if (!i11) goto l111;
    i11 = ADT_Dictionary_IntValue__DictionaryDesc_Get((ADT_Dictionary_IntValue__Dictionary)i3, (Object__Object)i10);
    _class = i11;
    i12 = i11>>2;
    switch (i12) {
    case 1:
      *(OOC_INT8*)((_check_pointer(i0, 17920))+32) = 0;
      i12 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 17980));
      OOC_IR_CheckUses__VisitVarDecl((OOC_IR_CheckUses__Visitor)i0, (OOC_SymbolTable__VarDecl)i10, (OOC_Scanner_SymList__Symbol)i12, 1u);
      goto l103;
    case 0:
      goto l103;
    default:
      _failed_case(i12, 17852);
      goto l103;
    }
l103:
    i11 = _mod(i11,4);
    switch (i11) {
    case 2:
      *(OOC_INT8*)((_check_pointer(i0, 18168))+32) = 1;
      i11 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 18229));
      OOC_IR_CheckUses__VisitVarDecl((OOC_IR_CheckUses__Visitor)i0, (OOC_SymbolTable__VarDecl)i10, (OOC_Scanner_SymList__Symbol)i11, 1u);
      goto l111;
    case 1:
      *(OOC_INT8*)((_check_pointer(i0, 18285))+32) = 2;
      i11 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 18351));
      OOC_IR_CheckUses__VisitVarDecl((OOC_IR_CheckUses__Visitor)i0, (OOC_SymbolTable__VarDecl)i10, (OOC_Scanner_SymList__Symbol)i11, 1u);
      goto l111;
    case 0:
      goto l111;
    default:
      _failed_case(i11, 18099);
      goto l111;
    }
l111:
    i9 = i9+1;
    i = i9;
    i10 = i9<i8;
    if (i10) goto l93_loop;
l117:
    i3 = *(OOC_INT32*)((_check_pointer(i6, 18626))+4);
    i = 0;
    i4 = 0<i3;
    if (!i4) goto l131;
    i4=0;
l120_loop:
    i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i6, 18679));
    i5 = _check_pointer(i5, 18685);
    i8 = OOC_ARRAY_LENGTH(i5, 0);
    i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i8, OOC_UINT32, 18685))*4);
    i5 = ADT_Dictionary_IntValue__DictionaryDesc_HasKey((ADT_Dictionary_IntValue__Dictionary)i7, (Object__Object)i5);
    if (i5) goto l123;
    *(OOC_INT8*)((_check_pointer(i0, 18751))+32) = 1;
    goto l124;
l123:
    *(OOC_INT8*)((_check_pointer(i0, 18706))+32) = 2;
l124:
    i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i6, 18797));
    i5 = _check_pointer(i5, 18803);
    i8 = OOC_ARRAY_LENGTH(i5, 0);
    i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i8, OOC_UINT32, 18803))*4);
    i8 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i6, 18797));
    i8 = _check_pointer(i8, 18803);
    i9 = OOC_ARRAY_LENGTH(i8, 0);
    i8 = (OOC_INT32)*(OOC_INT32*)(i8+(_check_index(i4, i9, OOC_UINT32, 18803))*4);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer((_type_guard(i5, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 18810)))), &_td_OOC_IR__ExpressionDesc, 18810)), 18821)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)(_type_guard(i8, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i8, 18810)))), &_td_OOC_IR__ExpressionDesc, 18810)), (OOC_IR__Visitor)i0);
    i4 = i4+1;
    i = i4;
    i5 = i4<i3;
    if (i5) goto l120_loop;
    goto l131;
  default:
    _failed_case(i3, 14898);
    goto l131;
  }
l131:
  *(OOC_INT8*)((_check_pointer(i0, 18863))+32) = i1;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 18897))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 18904))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 18897))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 18904))+4);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 18909)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i2);
  type = (OOC_SymbolTable__Type)i1;
  i1 = *(OOC_UINT8*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 18937)))), &_td_OOC_SymbolTable__FormalParsDesc, 18937)), 18948))+57);
  if (!i1) goto l134;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18970))+28);
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
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19286))+4);
  i1 = (OOC_INT32)ADT_Dictionary_IntValue__DictionaryDesc_Keys((ADT_Dictionary_IntValue__Dictionary)i1);
  k = (Object__ObjectArrayPtr)i1;
  i = 0;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i1, 19324)), 0);
  i3 = 0<i2;
  if (!i3) goto l27;
  i3 = (OOC_INT32)knownProcs;
  i4=0;
l3_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 19354));
  i5 = *(OOC_INT32*)((_check_pointer(i5, 19362))+4);
  j = 0;
  i6 = 0<i5;
  if (!i6) goto l22;
  i6=0;
l6_loop:
  i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 19397));
  i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i7, 19405));
  i7 = _check_pointer(i7, 19411);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i6, i8, OOC_UINT32, 19411))*4);
  i7 = _type_guard(i7, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 19419)))), &_td_OOC_SymbolTable__ProcDeclDesc, 19419);
  callerDecl = (OOC_SymbolTable__ProcDecl)i7;
  i8 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i3, (Object__Object)i7);
  obj = (Object__Object)i8;
  i8 = _type_guard(i8, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i8, 19497)))), &_td_OOC_IR_CheckUses__ProcDataDesc, 19497);
  pdCaller = (OOC_IR_CheckUses__ProcData)i8;
  i9 = _check_pointer(i1, 19543);
  i10 = OOC_ARRAY_LENGTH(i9, 0);
  i11 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i8, 19528))+4);
  i9 = (OOC_INT32)*(OOC_INT32*)(i9+(_check_index(i4, i10, OOC_UINT32, 19543))*4);
  i9 = ADT_Dictionary_IntValue__DictionaryDesc_HasKey((ADT_Dictionary_IntValue__Dictionary)i11, (Object__Object)i9);
  i9 = !i9;
  if (i9) goto l9;
  i7=0u;
  goto l15;
l9:
  i9 = _check_pointer(i1, 19564);
  i10 = OOC_ARRAY_LENGTH(i9, 0);
  i9 = (OOC_INT32)*(OOC_INT32*)(i9+(_check_index(i4, i10, OOC_UINT32, 19564))*4);
  i9 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i9, 19568)))), &_td_OOC_SymbolTable__TypeDesc);
  if (i9) goto l12;
  i9 = _check_pointer(i1, 19621);
  i10 = OOC_ARRAY_LENGTH(i9, 0);
  i9 = (OOC_INT32)*(OOC_INT32*)(i9+(_check_index(i4, i10, OOC_UINT32, 19621))*4);
  i7 = OOC_IR_CheckUses__NonlocalVar((OOC_SymbolTable__ProcDecl)i7, (OOC_SymbolTable__VarDecl)(_type_guard(i9, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i9, 19629)))), &_td_OOC_SymbolTable__VarDeclDesc, 19629)));
  
  goto l15;
l12:
  i7=1u;
l15:
  if (!i7) goto l17;
  i7 = _check_pointer(i1, 19675);
  i9 = OOC_ARRAY_LENGTH(i7, 0);
  i10 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i8, 19663))+4);
  i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i4, i9, OOC_UINT32, 19675))*4);
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
          *(OOC_INT32*)((_check_pointer(i0, 20281))+28) = i1;
          *(OOC_INT8*)((_check_pointer(i0, 20303))+32) = 0;
          i1 = (OOC_INT32)expr;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 20330)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i1, (OOC_IR__Visitor)i0);
          return;
          ;
        }

        
        void OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckDesign(OOC_IR__Expression design, OOC_INT8 mode) {
          register OOC_INT32 i0,i1;

          i0 = (OOC_INT32)v;
          i1 = (OOC_INT32)def;
          *(OOC_INT32*)((_check_pointer(i0, 20455))+28) = i1;
          i1 = mode;
          *(OOC_INT8*)((_check_pointer(i0, 20477))+32) = i1;
          i1 = (OOC_INT32)design;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 20506)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i1, (OOC_IR__Visitor)i0);
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
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20947))+8);
              i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 20957)))), &_td_OOC_IR__TypeTestDesc, 20957);
              localTest = (OOC_IR__TypeTest)i1;
              i2 = (OOC_INT32)prevGuards;
              i = 0;
              i3 = *(OOC_INT32*)((_check_pointer(i2, 21002))+4);
              i4 = 0<i3;
              if (!i4) goto l19;
              i4=0;
l3_loop:
              i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 21043));
              i5 = _check_pointer(i5, 21049);
              i6 = OOC_ARRAY_LENGTH(i5, 0);
              i4 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 21049))*4);
              i4 = _type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 21056)))), &_td_OOC_IR__TypeTestDesc, 21056);
              test = (OOC_IR__TypeTest)i4;
              i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 21087))+8);
              i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 21117))+8);
              i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i5, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 21096)))), &_td_OOC_IR__VarDesc, 21096)), 21100))+8);
              i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i6, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 21126)))), &_td_OOC_IR__VarDesc, 21126)), 21130))+8);
              i5 = i5==i6;
              if (i5) goto l6;
              i4=0u;
              goto l8;
l6:
              i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 21180))+12);
              i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 21232))+12);
              i4 = OOC_SymbolTable_TypeRules__IsExtensionOf((OOC_SymbolTable__Type)i5, (OOC_SymbolTable__Type)i4);
              
l8:
              if (i4) goto l10;
              i4=0u;
              goto l12;
l10:
              i4 = (OOC_INT32)v;
              i4 = *(OOC_INT8*)((_check_pointer(i4, 21267))+8);
              i4 = i4==2;
              
l12:
              if (!i4) goto l14;
              i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 21353));
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
              i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21480))+8);
              OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i4);
              def = (OOC_IR_CheckUses__Def)i1;
              i1 = (OOC_INT32)OOC_IR_CheckUses__DefDesc_Copy((OOC_IR_CheckUses__Def)i3);
              def2 = (OOC_IR_CheckUses__Def)i1;
              i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21591))+12);
              OOC_IR_CheckUses__CheckUses_CheckStatmSeq((OOC_IR_CheckUses__Def)i1, (OOC_IR__StatementSeq)i4);
              i4 = (OOC_INT32)def;
              OOC_IR_CheckUses__DefDesc_Merge((OOC_IR_CheckUses__Def)i4, (OOC_IR_CheckUses__Def)i1);
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21659))+16);
              i1 = i1!=0;
              if (!i1) goto l30;
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21706))+16);
              i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 21716)), 0);
              i1 = i1==1;
              if (i1) goto l24;
              i1=0u;
              goto l26;
l24:
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21746))+16);
              i1 = _check_pointer(i1, 21756);
              i4 = OOC_ARRAY_LENGTH(i1, 0);
              i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i4, OOC_UINT8, 21756))*4);
              i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 21760)))), &_td_OOC_IR__WithStatmDesc);
              
l26:
              if (i1) goto l28;
              i1 = (OOC_INT32)OOC_IR_CheckUses__DefDesc_Copy((OOC_IR_CheckUses__Def)i3);
              def2 = (OOC_IR_CheckUses__Def)i1;
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22008))+16);
              OOC_IR_CheckUses__CheckUses_CheckStatmSeq((OOC_IR_CheckUses__Def)i1, (OOC_IR__StatementSeq)i0);
              i0 = (OOC_INT32)def;
              OOC_IR_CheckUses__DefDesc_Merge((OOC_IR_CheckUses__Def)i0, (OOC_IR_CheckUses__Def)i1);
              goto l30;
l28:
              i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21818))+8);
              OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 21806)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i2, (Object__Object)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 21828)))), &_td_OOC_IR__TypeTestDesc, 21828)));
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21875))+16);
              i0 = _check_pointer(i0, 21885);
              i1 = OOC_ARRAY_LENGTH(i0, 0);
              i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 21885))*4);
              OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckStatm_CheckWith((OOC_IR_CheckUses__Def)i3, (OOC_IR__WithStatm)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 21892)))), &_td_OOC_IR__WithStatmDesc, 21892)), (ADT_ArrayList__ArrayList)i2);
l30:
              return;
              ;
            }


          i0 = (OOC_INT32)statm;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22144)))), &_td_OOC_IR__AssertDesc);
          if (i1) goto l114;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22445)))), &_td_OOC_IR__AssignOpDesc);
          if (i1) goto l112;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22605)))), &_td_OOC_IR__AssignmentDesc);
          if (i1) goto l110;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22730)))), &_td_OOC_IR__CallDesc);
          if (i1) goto l108;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22797)))), &_td_OOC_IR__CopyDesc);
          if (i1) goto l106;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22913)))), &_td_OOC_IR__CopyParameterDesc);
          if (i1) goto l127;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22984)))), &_td_OOC_IR__CopyStringDesc);
          if (i1) goto l103;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23106)))), &_td_OOC_IR__ForStatmDesc);
          if (i1) goto l101;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23359)))), &_td_OOC_IR__IfStatmDesc);
          if (i1) goto l99;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23586)))), &_td_OOC_IR__CaseStatmDesc);
          if (i1) goto l86;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 24080)))), &_td_OOC_IR__LoopStatmDesc);
          if (i1) goto l81;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 24271)))), &_td_OOC_IR__ExitDesc);
          if (i1) goto l79;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 24414)))), &_td_OOC_IR__MoveBlockDesc);
          if (i1) goto l62;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25134)))), &_td_OOC_IR__RaiseDesc);
          if (i1) goto l60;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25241)))), &_td_OOC_IR__RepeatStatmDesc);
          if (i1) goto l58;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25371)))), &_td_OOC_IR__ReturnDesc);
          if (i1) goto l53;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25565)))), &_td_OOC_IR__TryStatmDesc);
          if (i1) goto l43;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25876)))), &_td_OOC_IR__WhileStatmDesc);
          if (i1) goto l41;
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25997)))), &_td_OOC_IR__WithStatmDesc);
          if (i1) goto l39;
          _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25990)))), 25990);
          goto l127;
l39:
          i1 = (OOC_INT32)def;
          i1 = (OOC_INT32)OOC_IR_CheckUses__DefDesc_Copy((OOC_IR_CheckUses__Def)i1);
          defIn = (OOC_IR_CheckUses__Def)i1;
          i2 = (OOC_INT32)def;
          OOC_IR_CheckUses__DefDesc_Unreachable((OOC_IR_CheckUses__Def)i2);
          i2 = (OOC_INT32)ADT_ArrayList__New(4);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckStatm_CheckWith((OOC_IR_CheckUses__Def)i1, (OOC_IR__WithStatm)i0, (ADT_ArrayList__ArrayList)i2);
          goto l127;
l41:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25920))+8);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25963))+12);
          i1 = (OOC_INT32)def;
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq((OOC_IR_CheckUses__Def)i1, (OOC_IR__StatementSeq)i0);
          goto l127;
l43:
          i1 = (OOC_INT32)def;
          i1 = (OOC_INT32)OOC_IR_CheckUses__DefDesc_Copy((OOC_IR_CheckUses__Def)i1);
          defIn = (OOC_IR_CheckUses__Def)i1;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25647))+8);
          i3 = (OOC_INT32)def;
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq((OOC_IR_CheckUses__Def)i3, (OOC_IR__StatementSeq)i2);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25692))+12);
          i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 25702)), 0);
          i = 0;
          i3 = 0<i2;
          if (!i3) goto l127;
          i3=0;
l46_loop:
          i4 = (OOC_INT32)OOC_IR_CheckUses__DefDesc_Copy((OOC_IR_CheckUses__Def)i1);
          def2 = (OOC_IR_CheckUses__Def)i4;
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25781))+12);
          i5 = _check_pointer(i5, 25791);
          i6 = OOC_ARRAY_LENGTH(i5, 0);
          i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 25791))*4);
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 25794))+12);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq((OOC_IR_CheckUses__Def)i4, (OOC_IR__StatementSeq)i5);
          i5 = (OOC_INT32)def;
          OOC_IR_CheckUses__DefDesc_Merge((OOC_IR_CheckUses__Def)i5, (OOC_IR_CheckUses__Def)i4);
          i3 = i3+1;
          i = i3;
          i4 = i3<i2;
          if (i4) goto l46_loop;
          goto l127;
l53:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25405))+8);
          i1 = i1!=(OOC_INT32)0;
          if (!i1) goto l56;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25452))+8);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
l56:
          i0 = (OOC_INT32)v;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25488))+16);
          i1 = (OOC_INT32)def;
          OOC_IR_CheckUses__DefDesc_Merge((OOC_IR_CheckUses__Def)i0, (OOC_IR_CheckUses__Def)i1);
          i0 = (OOC_INT32)def;
          OOC_IR_CheckUses__DefDesc_Unreachable((OOC_IR_CheckUses__Def)i0);
          goto l127;
l58:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25295))+8);
          i2 = (OOC_INT32)def;
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq((OOC_IR_CheckUses__Def)i2, (OOC_IR__StatementSeq)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25328))+12);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l127;
l60:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25173))+8);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          i0 = (OOC_INT32)def;
          OOC_IR_CheckUses__DefDesc_Unreachable((OOC_IR_CheckUses__Def)i0);
          goto l127;
l62:
          i1 = (OOC_INT32)v;
          i2 = *(OOC_INT8*)((_check_pointer(i1, 24447))+8);
          i2 = i2==0;
          if (!i2) goto l65;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 24492))+24);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 24506))+4);
          i2 = (OOC_INT32)OOC_IR_CheckUses__any;
          ADT_Dictionary_IntValue__DictionaryDesc_Set((ADT_Dictionary_IntValue__Dictionary)i1, (Object__Object)i2, 2);
l65:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24597))+8);
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 24605)))), &_td_OOC_IR__AdrDesc);
          if (i1) goto l68;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24715))+8);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          goto l69;
l68:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24648))+8);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 24659)))), &_td_OOC_IR__AdrDesc, 24659)), 24663))+8);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
l69:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24765))+16);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24807))+12);
          expr = (OOC_IR__Expression)i1;
          i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 24833)))), &_td_OOC_IR__TypeConvDesc);
          if (!i2) goto l73;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 24882)))), &_td_OOC_IR__TypeConvDesc, 24882)), 24891))+8);
          expr = (OOC_IR__Expression)i1;
          
l73:
          i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 24932)))), &_td_OOC_IR__AdrDesc);
          if (i2) goto l76;
          i1 = (OOC_INT32)v;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 25029))+28);
          i2 = (OOC_INT32)OOC_IR_CheckUses__any;
          OOC_IR_CheckUses__DefDesc_SetClass((OOC_IR_CheckUses__Def)i1, (OOC_SymbolTable__Item)i2, 2);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25085))+12);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l127;
l76:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 24980)))), &_td_OOC_IR__AdrDesc, 24980)), 24984))+8);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckDesign((OOC_IR__Expression)i0, 1);
          goto l127;
l79:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24320))+8);
          i1 = (OOC_INT32)loopExits;
          i0 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i1, (Object__Object)i0);
          obj = (Object__Object)i0;
          i1 = (OOC_INT32)def;
          OOC_IR_CheckUses__DefDesc_Merge((OOC_IR_CheckUses__Def)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 24342)))), &_td_OOC_IR_CheckUses__DefDesc, 24342)), (OOC_IR_CheckUses__Def)i1);
          i0 = (OOC_INT32)def;
          OOC_IR_CheckUses__DefDesc_Unreachable((OOC_IR_CheckUses__Def)i0);
          goto l127;
l81:
          i1 = (OOC_INT32)OOC_IR_CheckUses__NewUnreachableDef();
          defIn = (OOC_IR_CheckUses__Def)i1;
          i2 = (OOC_INT32)loopExits;
          ADT_Dictionary__DictionaryDesc_Set((ADT_Dictionary__Dictionary)i2, (Object__Object)i0, (Object__Object)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24211))+8);
          i2 = (OOC_INT32)def;
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq((OOC_IR_CheckUses__Def)i2, (OOC_IR__StatementSeq)i0);
          i0 = _check_pointer(i1, 24242);
          i1 = (OOC_INT32)def;
          i1 = _check_pointer(i1, 24232);
          i2 = (OOC_INT32)&_td_OOC_IR_CheckUses__DefDesc;
          i2 = i2!=i2;
          if (!i2) goto l84;
          _failed_type_assert(24232);
l84:
          _copy_block(i0,i1,8);
          goto l127;
l86:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23629))+8);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i1 = (OOC_INT32)def;
          i1 = (OOC_INT32)OOC_IR_CheckUses__DefDesc_Copy((OOC_IR_CheckUses__Def)i1);
          defIn = (OOC_IR_CheckUses__Def)i1;
          i2 = (OOC_INT32)def;
          OOC_IR_CheckUses__DefDesc_Unreachable((OOC_IR_CheckUses__Def)i2);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23732))+12);
          i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 23741)), 0);
          i = 0;
          i3 = 0<i2;
          if (!i3) goto l94;
          i3=0;
l89_loop:
          i4 = (OOC_INT32)OOC_IR_CheckUses__DefDesc_Copy((OOC_IR_CheckUses__Def)i1);
          def2 = (OOC_IR_CheckUses__Def)i4;
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23820))+12);
          i5 = _check_pointer(i5, 23829);
          i6 = OOC_ARRAY_LENGTH(i5, 0);
          i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 23829))*4);
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 23832))+12);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq((OOC_IR_CheckUses__Def)i4, (OOC_IR__StatementSeq)i5);
          i5 = (OOC_INT32)def;
          OOC_IR_CheckUses__DefDesc_Merge((OOC_IR_CheckUses__Def)i5, (OOC_IR_CheckUses__Def)i4);
          i3 = i3+1;
          i = i3;
          i4 = i3<i2;
          if (i4) goto l89_loop;
l94:
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23907))+16);
          i2 = i2!=(OOC_INT32)0;
          if (!i2) goto l127;
          i1 = (OOC_INT32)OOC_IR_CheckUses__DefDesc_Copy((OOC_IR_CheckUses__Def)i1);
          def2 = (OOC_IR_CheckUses__Def)i1;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23999))+16);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq((OOC_IR_CheckUses__Def)i1, (OOC_IR__StatementSeq)i0);
          i0 = (OOC_INT32)def;
          OOC_IR_CheckUses__DefDesc_Merge((OOC_IR_CheckUses__Def)i0, (OOC_IR_CheckUses__Def)i1);
          goto l127;
l99:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23400))+8);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i1 = (OOC_INT32)def;
          i1 = (OOC_INT32)OOC_IR_CheckUses__DefDesc_Copy((OOC_IR_CheckUses__Def)i1);
          def2 = (OOC_IR_CheckUses__Def)i1;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23473))+12);
          i3 = (OOC_INT32)def;
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq((OOC_IR_CheckUses__Def)i3, (OOC_IR__StatementSeq)i2);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23520))+16);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq((OOC_IR_CheckUses__Def)i1, (OOC_IR__StatementSeq)i0);
          i0 = (OOC_INT32)def;
          OOC_IR_CheckUses__DefDesc_Merge((OOC_IR_CheckUses__Def)i0, (OOC_IR_CheckUses__Def)i1);
          goto l127;
l101:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23148))+12);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23182))+16);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23216))+8);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckDesign((OOC_IR__Expression)i1, 1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23325))+24);
          i1 = (OOC_INT32)def;
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq((OOC_IR_CheckUses__Def)i1, (OOC_IR__StatementSeq)i0);
          goto l127;
l103:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23028))+8);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23065))+12);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckDesign((OOC_IR__Expression)i0, 1);
          goto l127;
l106:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22835))+8);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22872))+12);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckDesign((OOC_IR__Expression)i0, 1);
          goto l127;
l108:
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l127;
l110:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22649))+12);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22685))+8);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckDesign((OOC_IR__Expression)i0, 1);
          goto l127;
l112:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22487))+12);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22521))+8);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i1);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22560))+8);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckDesign((OOC_IR__Expression)i0, 1);
          goto l127;
l114:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22178))+8);
          i1 = i1==(OOC_INT32)0;
          if (i1) goto l121;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22219))+8);
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 22230)))), &_td_OOC_IR__ConstDesc);
          if (i1) goto l119;
          i1=0u;
          goto l123;
l119:
          i1 = (OOC_INT32)Object_Boxed__false;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22284))+8);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 22298)))), &_td_OOC_IR__ConstDesc, 22298)), 22304))+8);
          i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 22271)))), Object_Boxed__BooleanDesc_Equals)),Object_Boxed__BooleanDesc_Equals)((Object_Boxed__Boolean)i1, (Object__Object)i2);
          
          goto l123;
l121:
          i1=1u;
l123:
          if (i1) goto l125;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22391))+8);
          OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckExpr((OOC_IR__Expression)i0);
          goto l127;
l125:
          i0 = (OOC_INT32)def;
          OOC_IR_CheckUses__DefDesc_Unreachable((OOC_IR_CheckUses__Def)i0);
l127:
          return;
          ;
        }


      i0 = (OOC_INT32)statmSeq;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l27;
      i = 0;
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 26256)), 0);
      i1 = 0!=i1;
      if (i1) goto l5;
      i1=0u;
      goto l7;
l5:
      i1 = (OOC_INT32)def;
      i1 = *(OOC_UINT8*)((_check_pointer(i1, 26266))+4);
      i1 = !i1;
      
l7:
      if (i1) goto l9;
      i1=i0;i0=0;
      goto l19;
l9:
      i1=0;
l10_loop:
      i0 = _check_pointer(i0, 26311);
      i2 = OOC_ARRAY_LENGTH(i0, 0);
      i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(i1, i2, OOC_UINT32, 26311))*4);
      OOC_IR_CheckUses__CheckUses_CheckStatmSeq_CheckStatm((OOC_IR__Statement)i0);
      i0 = i;
      i0 = i0+1;
      i = i0;
      i1 = (OOC_INT32)statmSeq;
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i1, 26256)), 0);
      i2 = i0!=i2;
      if (i2) goto l13;
      i2=0u;
      goto l15;
l13:
      i2 = (OOC_INT32)def;
      i2 = *(OOC_UINT8*)((_check_pointer(i2, 26266))+4);
      i2 = !i2;
      
l15:
      if (!i2) goto l19;
      {register OOC_INT32 h0=i0;i0=i1;i1=h0;}
      goto l10_loop;
l19:
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i1, 26376)), 0);
      i2 = i0!=i2;
      if (i2) goto l22;
      i2=0u;
      goto l24;
l22:
      i2 = (OOC_INT32)v;
      i2 = *(OOC_INT8*)((_check_pointer(i2, 26384))+8);
      i2 = i2==2;
      
l24:
      if (!i2) goto l27;
      i1 = _check_pointer(i1, 26465);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i0 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(i0, i2, OOC_UINT32, 26465))*4);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 26468));
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
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 26636))+64);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 26647))+44);
      i1 = i1!=(OOC_INT32)0;
      if (i1) goto l3;
      i0=0u;
      goto l4;
l3:
      i0 = *(OOC_UINT8*)((_check_pointer(i0, 26687))+50);
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
      i1 = *(OOC_INT32*)((_check_pointer(i0, 26875))+4);
      i2 = 0<i1;
      if (!i2) goto l8;
      i2=0;
l3_loop:
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 26922));
      i3 = _check_pointer(i3, 26928);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 26928))*4);
      i4 = (OOC_INT32)knownProcs;
      i3 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i4, (Object__Object)i3);
      pd = (Object__Object)i3;
      *(OOC_UINT8*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 26945)))), &_td_OOC_IR_CheckUses__ProcDataDesc, 26945)), 26954))+8) = 1u;
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
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 27297))+4);
      i1 = (OOC_INT32)ADT_Dictionary_IntValue__DictionaryDesc_Keys((ADT_Dictionary_IntValue__Dictionary)i1);
      k = (Object__ObjectArrayPtr)i1;
      i = 0;
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i1, 27337)), 0);
      i3 = (OOC_INT32)def;
      i4 = 0<i2;
      if (!i4) goto l11;
      i4=0;
l3_loop:
      i5 = _check_pointer(i1, 27375);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 27375))*4);
      i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 27360));
      i5 = ADT_Dictionary_IntValue__DictionaryDesc_HasKey((ADT_Dictionary_IntValue__Dictionary)i6, (Object__Object)i5);
      i5 = !i5;
      if (!i5) goto l6;
      i5 = _check_pointer(i1, 27432);
      i6 = OOC_ARRAY_LENGTH(i5, 0);
      i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 27432))*4);
      OOC_IR_CheckUses__ProcDataDesc_SetWriteFlag((OOC_IR_CheckUses__ProcData)i0, (OOC_SymbolTable__Item)(_type_guard(i5, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 27440)))), &_td_OOC_SymbolTable__ItemDesc, 27440)), 0);
l6:
      i4 = i4+1;
      i = i4;
      i5 = i4<i2;
      if (i5) goto l3_loop;
l11:
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 27507));
      i1 = (OOC_INT32)ADT_Dictionary_IntValue__DictionaryDesc_Keys((ADT_Dictionary_IntValue__Dictionary)i1);
      k = (Object__ObjectArrayPtr)i1;
      i2 = OOC_ARRAY_LENGTH((_check_pointer(i1, 27547)), 0);
      i = 0;
      i4 = 0<i2;
      if (!i4) goto l36;
      i4 = (OOC_INT32)localProc;
      i5=0;
l14_loop:
      i6 = _check_pointer(i1, 27572);
      i7 = OOC_ARRAY_LENGTH(i6, 0);
      i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i5, i7, OOC_UINT32, 27572))*4);
      item = (Object__Object)i6;
      i7 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 27594)))), &_td_OOC_SymbolTable__VarDeclDesc);
      if (i7) goto l21;
      i7 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 28044)))), &_td_OOC_SymbolTable__TypeDesc);
      if (i7) goto l19;
      _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 28038)))), 28038);
      goto l31;
l19:
      *nonlocalWrites = 1u;
      OOC_IR_CheckUses__ProcDataDesc_SetWriteFlag((OOC_IR_CheckUses__ProcData)i0, (OOC_SymbolTable__Item)i6, 2);
      goto l31;
l21:
      i7 = OOC_IR_CheckUses__NonlocalVar((OOC_SymbolTable__ProcDecl)i4, (OOC_SymbolTable__VarDecl)i6);
      if (!i7) goto l31;
      i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 27678));
      i7 = ADT_Dictionary_IntValue__DictionaryDesc_Get((ADT_Dictionary_IntValue__Dictionary)i7, (Object__Object)i6);
      switch (i7) {
      case 0:
        OOC_IR_CheckUses__ProcDataDesc_SetWriteFlag((OOC_IR_CheckUses__ProcData)i0, (OOC_SymbolTable__Item)i6, 0);
        goto l31;
      case 1:
        *nonlocalWrites = 1u;
        OOC_IR_CheckUses__ProcDataDesc_SetWriteFlag((OOC_IR_CheckUses__ProcData)i0, (OOC_SymbolTable__Item)i6, 1);
        goto l31;
      case 2:
        *nonlocalWrites = 1u;
        OOC_IR_CheckUses__ProcDataDesc_SetWriteFlag((OOC_IR_CheckUses__ProcData)i0, (OOC_SymbolTable__Item)i6, 2);
        goto l31;
      default:
        _failed_case(i7, 27670);
        goto l31;
      }
l31:
      i5 = i5+1;
      i = i5;
      i6 = i5<i2;
      if (i6) goto l14_loop;
l36:
      i1 = *(OOC_UINT8*)((_check_pointer(i3, 28173))+4);
      if (i1) goto l39;
      i1=0u;
      goto l41;
l39:
      i1 = (OOC_INT32)localProc;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 28252))+64);
      i1 = *(OOC_UINT8*)((_check_pointer(i1, 28263))+57);
      i1 = !i1;
      
l41:
      if (i1) goto l43;
      i1=0u;
      goto l49;
l43:
      i1 = (OOC_INT32)localProc;
      i2 = OOC_SymbolTable__ProcDeclDesc_IsTypeBound((OOC_SymbolTable__ProcDecl)i1);
      i2 = !i2;
      if (i2) goto l46;
      i1 = *(OOC_UINT8*)((_check_pointer(i1, 28391))+51);
      
      goto l49;
l46:
      i1=1u;
l49:
      if (!i1) goto l51;
      i1 = (OOC_INT32)localProc;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 28429))+64);
      *(OOC_UINT8*)((_check_pointer(i1, 28440))+57) = 1u;
      *(OOC_UINT8*)((_check_pointer(i0, 28469))+9) = 1u;
l51:
      return;
      ;
    }


  i0 = (OOC_INT32)moduleDecl;
  i0 = *(OOC_INT8*)((_check_pointer(i0, 29970))+52);
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
  *(OOC_INT32*)(_check_pointer(i2, 30141)) = i3;
  i3 = (OOC_INT32)pragmaHistory;
  *(OOC_INT32*)((_check_pointer(i2, 30167))+4) = i3;
  *(OOC_INT32*)((_check_pointer(i2, 30205))+28) = 0;
  *(OOC_INT32*)((_check_pointer(i2, 30223))+12) = i1;
  i3 = (OOC_INT32)ADT_Dictionary__New();
  loopExits = (ADT_Dictionary__Dictionary)i3;
  *(OOC_INT8*)((_check_pointer(i2, 30517))+8) = 0;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30574))+8);
  i = 0;
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 30583)), 0);
  i2 = 0<i0;
  if (!i2) goto l12;
  i2=i1;i1=0;
l7_loop:
  i3 = (OOC_INT32)module;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 30611))+8);
  i3 = _check_pointer(i3, 30620);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i1, i4, OOC_UINT32, 30620))*4);
  proc = (OOC_IR__Procedure)i1;
  i3 = (OOC_INT32)v;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 30650))+4);
  *(OOC_INT32*)((_check_pointer(i3, 30632))+20) = i4;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 30685))+20);
  i2 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i2, (Object__Object)i4);
  pd = (Object__Object)i2;
  *(OOC_INT32*)((_check_pointer(i3, 30705))+24) = (_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 30726)))), &_td_OOC_IR_CheckUses__ProcDataDesc, 30726));
  i2 = (OOC_INT32)OOC_IR_CheckUses__NewUnreachableDef();
  *(OOC_INT32*)((_check_pointer(i3, 30744))+16) = i2;
  i2 = (OOC_INT32)OOC_IR_CheckUses__NewDef();
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 30819))+8);
  OOC_IR_CheckUses__CheckUses_CheckStatmSeq((OOC_IR_CheckUses__Def)i2, (OOC_IR__StatementSeq)i1);
  i1 = (OOC_INT32)pd;
  i2 = (OOC_INT32)knownProcs;
  OOC_IR_CheckUses__TransitiveWriteClosure((ADT_Dictionary__Dictionary)i2, (OOC_IR_CheckUses__ProcData)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 30875)))), &_td_OOC_IR_CheckUses__ProcDataDesc, 30875)));
  i1 = i;
  i1 = i1+1;
  i = i1;
  i3 = i1<i0;
  if (i3) goto l7_loop;
l12:
  i0 = (OOC_INT32)v;
  *(OOC_INT8*)((_check_pointer(i0, 31056))+8) = 1;
l13_loop:
  inWorklist = 0;
  i0 = (OOC_INT32)module;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31148))+8);
  i = 0;
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 31157)), 0);
  i1 = 0<i0;
  if (!i1) goto l27;
  i1=0;
l16_loop:
  i2 = (OOC_INT32)module;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 31187))+8);
  i2 = _check_pointer(i2, 31196);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i1, i3, OOC_UINT32, 31196))*4);
  proc = (OOC_IR__Procedure)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 31234))+4);
  i3 = (OOC_INT32)knownProcs;
  i2 = (OOC_INT32)ADT_Dictionary__DictionaryDesc_Get((ADT_Dictionary__Dictionary)i3, (Object__Object)i2);
  pd = (Object__Object)i2;
  i3 = *(OOC_UINT8*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 31256)))), &_td_OOC_IR_CheckUses__ProcDataDesc, 31256)), 31265))+8);
  if (!i3) goto l22;
  i3 = (OOC_INT32)v;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 31311))+4);
  *(OOC_INT32*)((_check_pointer(i3, 31293))+20) = i4;
  *(OOC_INT32*)((_check_pointer(i3, 31329))+24) = (_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 31350)))), &_td_OOC_IR_CheckUses__ProcDataDesc, 31350));
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 31372))+24);
  *(OOC_UINT8*)((_check_pointer(i2, 31386))+9) = 0u;
  i2 = (OOC_INT32)OOC_IR_CheckUses__NewUnreachableDef();
  *(OOC_INT32*)((_check_pointer(i3, 31421))+16) = i2;
  i2 = (OOC_INT32)OOC_IR_CheckUses__NewDef();
  def = (OOC_IR_CheckUses__Def)i2;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 31516))+8);
  OOC_IR_CheckUses__CheckUses_CheckStatmSeq((OOC_IR_CheckUses__Def)i2, (OOC_IR__StatementSeq)i1);
  i1 = (OOC_INT32)v;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 31539))+16);
  i3 = (OOC_INT32)def;
  OOC_IR_CheckUses__DefDesc_Merge((OOC_IR_CheckUses__Def)i2, (OOC_IR_CheckUses__Def)i3);
  i2 = (OOC_INT32)proc;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 31655))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 31586))+20);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 31599))+24);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 31616))+16);
  OOC_IR_CheckUses__CheckUses_SetWriteFlags((OOC_SymbolTable__ProcDecl)i3, (OOC_IR_CheckUses__ProcData)i4, (OOC_IR_CheckUses__Def)i1, (void*)((_check_pointer(i2, 31660))+52));
  i1 = (OOC_INT32)v;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 31703))+24);
  i1 = *(OOC_UINT8*)((_check_pointer(i1, 31717))+9);
  if (!i1) goto l22;
  i1 = (OOC_INT32)pd;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 31769)))), &_td_OOC_IR_CheckUses__ProcDataDesc, 31769)), 31778));
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
  *(OOC_INT8*)((_check_pointer(i0, 31952))+8) = 2;
  i0 = (OOC_INT32)module;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32008))+8);
  i = 0;
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 32017)), 0);
  i1 = 0<i0;
  if (!i1) goto l49;
  i1=0;
l34_loop:
  i2 = (OOC_INT32)module;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 32045))+8);
  i2 = _check_pointer(i2, 32054);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i1, i3, OOC_UINT32, 32054))*4);
  proc = (OOC_IR__Procedure)i1;
  i2 = (OOC_INT32)v;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 32084))+4);
  *(OOC_INT32*)((_check_pointer(i2, 32066))+20) = i3;
  i3 = (OOC_INT32)OOC_IR_CheckUses__NewUnreachableDef();
  *(OOC_INT32*)((_check_pointer(i2, 32098))+16) = i3;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 32146))+16);
  i2 = i2!=0;
  if (!i2) goto l44;
  i2 = (OOC_INT32)OOC_IR_CheckUses__NewDef();
  def = (OOC_IR_CheckUses__Def)i2;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 32225))+8);
  OOC_IR_CheckUses__CheckUses_CheckStatmSeq((OOC_IR_CheckUses__Def)i2, (OOC_IR__StatementSeq)i1);
  i1 = (OOC_INT32)def;
  i1 = *(OOC_UINT8*)((_check_pointer(i1, 32252))+4);
  i1 = !i1;
  if (i1) goto l39;
  i1=0u;
  goto l41;
l39:
  i1 = (OOC_INT32)proc;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 32287))+4);
  i1 = OOC_IR_CheckUses__CheckUses_CheckedFunction((OOC_SymbolTable__ProcDecl)i1);
  
l41:
  if (!i1) goto l44;
  i1 = (OOC_INT32)proc;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 32345))+16);
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

/* --- */
