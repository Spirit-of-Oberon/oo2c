#include <OOC/X86/SSA.d>
#include <__oo2c.h>
#include <setjmp.h>

OOC_CHAR8 OOC_X86_SSA__IsUnsigned(OOC_INT8 type) {
  register OOC_INT32 i0,i1;

  i0 = type;
  i1 = 5<=i0;
  if (i1) goto l3;
  i0=0u;
  goto l4;
l3:
  i0 = i0<=8;
  
l4:
  return i0;
  ;
}

void OOC_X86_SSA__SelectorDesc_INIT(OOC_X86_SSA__Selector s) {

  return;
  ;
}

OOC_CHAR8 OOC_X86_SSA__SelectorDesc_SameSelector(OOC_X86_SSA__Selector s, OOC_X86_SSA__Selector sel) {

  _failed_function(25066); return 0;
  ;
}

OOC_SymbolTable__Type OOC_X86_SSA__SelectorDesc_Type(OOC_X86_SSA__Selector s) {

  _assert(0u, 127, 25181);
  _failed_function(25150); return 0;
  ;
}

void OOC_X86_SSA__VarDesc_INIT(OOC_X86_SSA__Var s, OOC_SymbolTable__VarDecl var) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)s;
  OOC_X86_SSA__SelectorDesc_INIT((OOC_X86_SSA__Selector)i0);
  i1 = (OOC_INT32)var;
  *(OOC_INT32*)(_check_pointer(i0, 25281)) = i1;
  return;
  ;
}

OOC_CHAR8 OOC_X86_SSA__VarDesc_SameSelector(OOC_X86_SSA__Var s, OOC_X86_SSA__Selector sel) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sel;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25390)))), &_td_OOC_X86_SSA__VarDesc);
  if (i1) goto l3;
  i0=0u;
  goto l4;
l3:
  i1 = (OOC_INT32)s;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 25402));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25414)))), &_td_OOC_X86_SSA__VarDesc, 25414)), 25418));
  i0 = i1==i0;
  
l4:
  return i0;
  ;
}

OOC_CHAR8 OOC_X86_SSA__VarDesc_IsGlobalVar(OOC_X86_SSA__Var s) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)s;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 25512));
  i1 = i1!=0;
  if (i1) goto l3;
  i0=0u;
  goto l4;
l3:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 25529));
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25534))+4);
  i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25542)))), &_td_OOC_SymbolTable__ModuleDesc);
  
l4:
  return i0;
  ;
}

OOC_SymbolTable__Type OOC_X86_SSA__VarDesc_Type(OOC_X86_SSA__Var s) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)s;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 25636));
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25641))+48);
  return (OOC_SymbolTable__Type)i0;
  ;
}

void OOC_X86_SSA__ProcDesc_INIT(OOC_X86_SSA__Proc s, OOC_SymbolTable__ProcDecl decl) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)s;
  OOC_X86_SSA__SelectorDesc_INIT((OOC_X86_SSA__Selector)i0);
  i1 = (OOC_INT32)decl;
  *(OOC_INT32*)(_check_pointer(i0, 25736)) = i1;
  return;
  ;
}

OOC_CHAR8 OOC_X86_SSA__ProcDesc_SameSelector(OOC_X86_SSA__Proc s, OOC_X86_SSA__Selector sel) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sel;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25847)))), &_td_OOC_X86_SSA__ProcDesc);
  if (i1) goto l3;
  i0=0u;
  goto l4;
l3:
  i1 = (OOC_INT32)s;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 25860));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25872)))), &_td_OOC_X86_SSA__ProcDesc, 25872)), 25877));
  i0 = i1==i0;
  
l4:
  return i0;
  ;
}

void OOC_X86_SSA__ProcNameDesc_INIT(OOC_X86_SSA__ProcName s, Object__String name) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)s;
  OOC_X86_SSA__SelectorDesc_INIT((OOC_X86_SSA__Selector)i0);
  i1 = (OOC_INT32)name;
  *(OOC_INT32*)(_check_pointer(i0, 25979)) = i1;
  return;
  ;
}

OOC_CHAR8 OOC_X86_SSA__ProcNameDesc_SameSelector(OOC_X86_SSA__ProcName s, OOC_X86_SSA__Selector sel) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)sel;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26094)))), &_td_OOC_X86_SSA__ProcNameDesc);
  if (i1) goto l3;
  i0=0u;
  goto l4;
l3:
  i1 = (OOC_INT32)s;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 26111));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26128)))), &_td_OOC_X86_SSA__ProcNameDesc, 26128)), 26137));
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 26111));
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 26116)))), Object__StringDesc_Equals)),Object__StringDesc_Equals)((Object__String)i1, (Object__Object)i0);
  
l4:
  return i0;
  ;
}

void OOC_X86_SSA__TypeDescrDesc_INIT(OOC_X86_SSA__TypeDescr s, OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)s;
  OOC_X86_SSA__SelectorDesc_INIT((OOC_X86_SSA__Selector)i0);
  i1 = (OOC_INT32)type;
  *(OOC_INT32*)(_check_pointer(i0, 26243)) = i1;
  return;
  ;
}

OOC_CHAR8 OOC_X86_SSA__TypeDescrDesc_SameSelector(OOC_X86_SSA__TypeDescr s, OOC_X86_SSA__Selector sel) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sel;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26359)))), &_td_OOC_X86_SSA__TypeDescrDesc);
  if (i1) goto l3;
  i0=0u;
  goto l4;
l3:
  i1 = (OOC_INT32)s;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 26377));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26389)))), &_td_OOC_X86_SSA__TypeDescrDesc, 26389)), 26399));
  i0 = i1==i0;
  
l4:
  return i0;
  ;
}

void OOC_X86_SSA__ModuleDescrDesc_INIT(OOC_X86_SSA__ModuleDescr s) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)s;
  OOC_X86_SSA__SelectorDesc_INIT((OOC_X86_SSA__Selector)i0);
  return;
  ;
}

OOC_CHAR8 OOC_X86_SSA__ModuleDescrDesc_SameSelector(OOC_X86_SSA__ModuleDescr s, OOC_X86_SSA__Selector sel) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)sel;
  return (OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26590)))), &_td_OOC_X86_SSA__ModuleDescrDesc));
  ;
}

void OOC_X86_SSA__ConstDesc_INIT(OOC_X86_SSA__Const s, Object_Boxed__Object value, OOC_INT16 type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)s;
  OOC_X86_SSA__SelectorDesc_INIT((OOC_X86_SSA__Selector)i0);
  i1 = (OOC_INT32)value;
  *(OOC_INT32*)(_check_pointer(i0, 26725)) = i1;
  i1 = type;
  *(OOC_INT16*)((_check_pointer(i0, 26747))+4) = i1;
  return;
  ;
}

OOC_CHAR8 OOC_X86_SSA__ConstDesc_SameSelector(OOC_X86_SSA__Const s, OOC_X86_SSA__Selector sel) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)sel;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26859)))), &_td_OOC_X86_SSA__ConstDesc);
  if (i1) goto l3;
  i0=0u;
  goto l4;
l3:
  i1 = (OOC_INT32)s;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 26872));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 26890)))), &_td_OOC_X86_SSA__ConstDesc, 26890)), 26896));
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 26872));
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 26878)))), Object__ObjectDesc_Equals)),Object__ObjectDesc_Equals)((Object__Object)i1, (Object__Object)i0);
  
l4:
  return i0;
  ;
}

void OOC_X86_SSA__HeapObjDesc_INIT(OOC_X86_SSA__HeapObj s, OOC_X86_SSA__FunctionBlock fctBlock, OOC_SymbolTable__Type type, OOC_X86_SSA__Result adr) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)s;
  OOC_X86_SSA__SelectorDesc_INIT((OOC_X86_SSA__Selector)i0);
  i1 = (OOC_INT32)type;
  *(OOC_INT32*)(_check_pointer(i0, 27067)) = i1;
  i1 = (OOC_INT32)fctBlock;
  i2 = (OOC_INT32)adr;
  i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr1((OOC_X86_SSA__Block)i1, 23, (OOC_X86_SSA__Result)i2);
  *(OOC_INT32*)((_check_pointer(i0, 27087))+4) = i1;
  return;
  ;
}

OOC_CHAR8 OOC_X86_SSA__HeapObjDesc_SameSelector(OOC_X86_SSA__HeapObj s, OOC_X86_SSA__Selector sel) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sel;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 27268)))), &_td_OOC_X86_SSA__HeapObjDesc);
  if (i1) goto l3;
  i0=0u;
  goto l4;
l3:
  i1 = (OOC_INT32)s;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 27292))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 27303));
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 27323)))), &_td_OOC_X86_SSA__HeapObjDesc, 27323)), 27331))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 27342));
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 27312));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 27351));
  i0 = i1==i0;
  
l4:
  return i0;
  ;
}

OOC_SymbolTable__Type OOC_X86_SSA__HeapObjDesc_Type(OOC_X86_SSA__HeapObj s) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)s;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 27441));
  return (OOC_SymbolTable__Type)i0;
  ;
}

void OOC_X86_SSA__IndexDesc_INIT(OOC_X86_SSA__Index s, OOC_X86_SSA__FunctionBlock fctBlock, OOC_X86_SSA__Result index) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)s;
  OOC_X86_SSA__SelectorDesc_INIT((OOC_X86_SSA__Selector)i0);
  i1 = (OOC_INT32)fctBlock;
  i2 = (OOC_INT32)index;
  i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr1((OOC_X86_SSA__Block)i1, 23, (OOC_X86_SSA__Result)i2);
  *(OOC_INT32*)(_check_pointer(i0, 27557)) = i1;
  return;
  ;
}

OOC_CHAR8 OOC_X86_SSA__IndexDesc_SameSelector(OOC_X86_SSA__Index s, OOC_X86_SSA__Selector sel) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sel;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 27707)))), &_td_OOC_X86_SSA__IndexDesc);
  if (i1) goto l3;
  i0=0u;
  goto l4;
l3:
  i1 = (OOC_INT32)s;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 27729));
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 27742));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 27762)))), &_td_OOC_X86_SSA__IndexDesc, 27762)), 27768));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 27781));
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 27751));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 27790));
  i0 = i1==i0;
  
l4:
  return i0;
  ;
}

void OOC_X86_SSA__FieldDesc_INIT(OOC_X86_SSA__Field s, OOC_SymbolTable__FieldDecl field) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)s;
  OOC_X86_SSA__SelectorDesc_INIT((OOC_X86_SSA__Selector)i0);
  i1 = (OOC_INT32)field;
  *(OOC_INT32*)(_check_pointer(i0, 27896)) = i1;
  return;
  ;
}

OOC_CHAR8 OOC_X86_SSA__FieldDesc_SameSelector(OOC_X86_SSA__Field s, OOC_X86_SSA__Selector sel) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)sel;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 28010)))), &_td_OOC_X86_SSA__FieldDesc);
  if (i1) goto l3;
  i0=0u;
  goto l4;
l3:
  i1 = (OOC_INT32)s;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 28024));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 28037)))), &_td_OOC_X86_SSA__FieldDesc, 28037)), 28043));
  i0 = i1==i0;
  
l4:
  return i0;
  ;
}

OOC_CHAR8 OOC_X86_SSA__SameDesignator(OOC_X86_SSA__Designator _d1, OOC_X86_SSA__Designator _d2) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9;
  OOC_INT32 i;

  i0 = (OOC_INT32)_d1;
  i1 = (OOC_INT32)_d2;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i0, 28173)), 0);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i1, 28184)), 0);
  i2 = i2!=i3;
  if (i2) goto l14;
  i = 0;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i0, 28248)), 0);
  i3 = 0<i2;
  if (!i3) goto l13;
  i3=0;
l5_loop:
  i4 = _check_pointer(i1, 28289);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = _check_pointer(i0, 28270);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i8 = _check_pointer(i0, 28270);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i8 = (OOC_INT32)*(OOC_INT32*)(i8+(_check_index(i3, i9, OOC_UINT32, 28270))*4);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 28289))*4);
  i5 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i3, i7, OOC_UINT32, 28270))*4);
  i4 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i8, 28273)))), OOC_X86_SSA__SelectorDesc_SameSelector)),OOC_X86_SSA__SelectorDesc_SameSelector)((OOC_X86_SSA__Selector)i5, (OOC_X86_SSA__Selector)i4);
  i4 = !i4;
  if (!i4) goto l8;
  return 0u;
l8:
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l5_loop;
l13:
  return 1u;
  goto l15;
l14:
  return 0u;
l15:
  _failed_function(28083); return 0;
  ;
}

void OOC_X86_SSA__NodeDesc_INIT(OOC_X86_SSA__Node node) {

  return;
  ;
}

static void OOC_X86_SSA__SetUse(OOC_X86_SSA__Result arg, OOC_X86_SSA__Opnd opnd) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)opnd;
  i1 = (OOC_INT32)arg;
  *(OOC_INT32*)(_check_pointer(i0, 28663)) = i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 28699))+8);
  *(OOC_INT32*)((_check_pointer(i0, 28684))+12) = i2;
  *(OOC_INT32*)((_check_pointer(i1, 28716))+8) = i0;
  return;
  ;
}

static void OOC_X86_SSA__DeleteUse(OOC_X86_SSA__Opnd opnd) {
  register OOC_INT32 i0,i1,i2;
  OOC_X86_SSA__Opnd prev;

  i0 = (OOC_INT32)opnd;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 28883));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 28887))+8);
  i1 = i1==i0;
  if (i1) goto l12;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 28976));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 28980))+8);
  prev = (OOC_X86_SSA__Opnd)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 29007))+12);
  i2 = i2!=i0;
  if (!i2) goto l11;
l6_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 29047))+12);
  prev = (OOC_X86_SSA__Opnd)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 29007))+12);
  i2 = i2!=i0;
  if (i2) goto l6_loop;
l11:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29094))+12);
  *(OOC_INT32*)((_check_pointer(i1, 29078))+12) = i2;
  goto l13;
l12:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 28919));
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 28939))+12);
  *(OOC_INT32*)((_check_pointer(i1, 28923))+8) = i2;
l13:
  *(OOC_INT32*)((_check_pointer(i0, 29121))+12) = 0;
  *(OOC_INT32*)(_check_pointer(i0, 29146)) = 0;
  return;
  ;
}

void OOC_X86_SSA__OpndDesc_INIT(OOC_X86_SSA__Opnd opnd, OOC_X86_SSA__Result arg) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)opnd;
  OOC_X86_SSA__NodeDesc_INIT((OOC_X86_SSA__Node)i0);
  i1 = (OOC_INT32)arg;
  *(OOC_INT32*)(_check_pointer(i0, 29326)) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 29347))+12) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 29372))+4) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 29398))+8) = 0;
  *(OOC_UINT8*)((_check_pointer(i0, 29421))+16) = 0u;
  OOC_X86_SSA__SetUse((OOC_X86_SSA__Result)i1, (OOC_X86_SSA__Opnd)i0);
  return;
  ;
}

void OOC_X86_SSA__OpndDesc_DeleteOpnd(OOC_X86_SSA__Opnd opnd) {
  register OOC_INT32 i0,i1,i2;
  OOC_X86_SSA__Opnd prev;

  i0 = (OOC_INT32)opnd;
  OOC_X86_SSA__DeleteUse((OOC_X86_SSA__Opnd)i0);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29728))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 29734));
  i1 = i1==i0;
  if (i1) goto l12;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29828))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 29834));
  prev = (OOC_X86_SSA__Opnd)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 29862))+4);
  i2 = i2!=i0;
  if (!i2) goto l11;
l6_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 29903))+4);
  prev = (OOC_X86_SSA__Opnd)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 29862))+4);
  i2 = i2!=i0;
  if (i2) goto l6_loop;
l11:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29952))+4);
  *(OOC_INT32*)((_check_pointer(i1, 29935))+4) = i2;
  goto l13;
l12:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29767))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 29790))+4);
  *(OOC_INT32*)(_check_pointer(i1, 29773)) = i2;
l13:
  *(OOC_INT32*)((_check_pointer(i0, 29980))+4) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 30006))+8) = 0;
  return;
  ;
}

void OOC_X86_SSA__OpndDesc_ReplaceArg(OOC_X86_SSA__Opnd opnd, OOC_X86_SSA__Result arg) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)opnd;
  OOC_X86_SSA__DeleteUse((OOC_X86_SSA__Opnd)i0);
  i1 = (OOC_INT32)arg;
  OOC_X86_SSA__SetUse((OOC_X86_SSA__Result)i1, (OOC_X86_SSA__Opnd)i0);
  return;
  ;
}

OOC_INT32 OOC_X86_SSA__OpndDesc_OpndIndex(OOC_X86_SSA__Opnd opnd) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_INT32 i;
  OOC_X86_SSA__Opnd ptr;

  i = 0;
  i0 = (OOC_INT32)opnd;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30528))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 30534));
  ptr = (OOC_X86_SSA__Opnd)i1;
  i2 = i1!=i0;
  if (i2) goto l3;
  i0=0;
  goto l9;
l3:
  i2=i1;i1=0;
l4_loop:
  i1 = i1+1;
  i = i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 30601))+4);
  ptr = (OOC_X86_SSA__Opnd)i2;
  i3 = i2!=i0;
  if (i3) goto l4_loop;
l8:
  i0=i1;
l9:
  return i0;
  ;
}

OOC_CHAR8 OOC_X86_SSA__OpndDesc_IsBackedgeOpnd(OOC_X86_SSA__Opnd opnd) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)opnd;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30728))+8);
  i1 = *(OOC_INT8*)((_check_pointer(i1, 30734))+20);
  i1 = i1==38;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30765))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 30772)))), &_td_OOC_X86_SSA__GateInstrDesc, 30772)), 30782))+48);
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 30789)))), &_td_OOC_X86_SSA__LoopStartInstrDesc);
  
l5:
  if (i1) goto l7;
  i0=0u;
  goto l8;
l7:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30823))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 30829));
  i0 = i1!=i0;
  
l8:
  return i0;
  ;
}

OOC_CHAR8 OOC_X86_SSA__OpndDesc_IsConst(OOC_X86_SSA__Opnd opnd) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)opnd;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 30939));
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 30943))+4);
  i0 = *(OOC_INT8*)((_check_pointer(i0, 30949))+20);
  return (i0==0);
  ;
}

void OOC_X86_SSA__ResultDesc_INIT(OOC_X86_SSA__Result res, OOC_INT8 type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)res;
  OOC_X86_SSA__NodeDesc_INIT((OOC_X86_SSA__Node)i0);
  *(OOC_INT32*)(_check_pointer(i0, 31087)) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 31114))+4) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 31136))+8) = 0;
  i1 = type;
  *(OOC_INT8*)((_check_pointer(i0, 31160))+12) = i1;
  *(OOC_INT8*)((_check_pointer(i0, 31182))+13) = 0;
  *(OOC_INT8*)((_check_pointer(i0, 31212))+14) = (-1);
  *(OOC_INT32*)((_check_pointer(i0, 31243))+16) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 31270))+20) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 31291))+24) = 0;
  return;
  ;
}

void OOC_X86_SSA__ResultDesc_SetType(OOC_X86_SSA__Result res, OOC_INT8 type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)res;
  i1 = type;
  *(OOC_INT8*)((_check_pointer(i0, 31379))+12) = i1;
  return;
  ;
}

OOC_CHAR8 OOC_X86_SSA__ResultDesc_NonImmediateUses(OOC_X86_SSA__Result res) {
  register OOC_INT32 i0,i1;
  OOC_X86_SSA__Opnd use;

  i0 = (OOC_INT32)res;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31677))+8);
  use = (OOC_X86_SSA__Opnd)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l15;
l3_loop:
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 31725))+16);
  i1 = !i1;
  if (i1) goto l6;
  i1=0u;
  goto l8;
l6:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31742))+8);
  i1 = *(OOC_INT8*)((_check_pointer(i1, 31748))+20);
  i1 = i1!=23;
  
l8:
  if (!i1) goto l10;
  return 1u;
l10:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 31820))+12);
  use = (OOC_X86_SSA__Opnd)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3_loop;
l15:
  return 0u;
  ;
}

OOC_CHAR8 OOC_X86_SSA__ResultDesc_SameLocation(OOC_X86_SSA__Result res, OOC_X86_SSA__Result res2) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)res;
  i1 = (OOC_INT32)res2;
  i2 = *(OOC_INT8*)((_check_pointer(i0, 31967))+14);
  i3 = *(OOC_INT8*)((_check_pointer(i1, 31982))+14);
  i2 = i2==i3;
  if (i2) goto l3;
  i2=0u;
  goto l5;
l3:
  i2 = *(OOC_INT8*)((_check_pointer(i0, 32006))+13);
  i3 = *(OOC_INT8*)((_check_pointer(i1, 32022))+13);
  i2 = i2==i3;
  
l5:
  if (i2) goto l7;
  i1=0u;
  goto l9;
l7:
  i2 = *(OOC_INT32*)((_check_pointer(i0, 32047))+16);
  i1 = *(OOC_INT32*)((_check_pointer(i1, 32067))+16);
  i1 = i2==i1;
  
l9:
  if (i1) goto l11;
  i0=0u;
  goto l12;
l11:
  i0 = *(OOC_INT8*)((_check_pointer(i0, 32096))+14);
  i0 = i0!=(-1);
  
l12:
  return i0;
  ;
}

void OOC_X86_SSA__ResultDesc_DeleteResult(OOC_X86_SSA__Result res) {
  register OOC_INT32 i0,i1,i2;
  OOC_X86_SSA__Result prev;

  i0 = (OOC_INT32)res;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32549))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 32555))+4);
  i1 = i0==i1;
  if (i1) goto l12;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32645))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 32651))+4);
  prev = (OOC_X86_SSA__Result)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 32681));
  i2 = i2!=i0;
  if (!i2) goto l11;
l6_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 32723));
  prev = (OOC_X86_SSA__Result)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 32681));
  i2 = i2!=i0;
  if (i2) goto l6_loop;
l11:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 32775));
  *(OOC_INT32*)(_check_pointer(i1, 32757)) = i0;
  goto l13;
l12:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32582))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 32606));
  *(OOC_INT32*)((_check_pointer(i1, 32588))+4) = i0;
l13:
  return;
  ;
}

void OOC_X86_SSA__ResultDesc_ReplaceUses(OOC_X86_SSA__Result res, OOC_X86_SSA__Result with) {
  register OOC_INT32 i0,i1,i2;
  OOC_X86_SSA__Opnd use;
  OOC_X86_SSA__Opnd nextUse;

  i0 = (OOC_INT32)res;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 32984))+8);
  use = (OOC_X86_SSA__Opnd)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l8;
  i1 = (OOC_INT32)with;
  
l3_loop:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33039))+12);
  nextUse = (OOC_X86_SSA__Opnd)i2;
  OOC_X86_SSA__DeleteUse((OOC_X86_SSA__Opnd)i0);
  OOC_X86_SSA__SetUse((OOC_X86_SSA__Result)i1, (OOC_X86_SSA__Opnd)i0);
  use = (OOC_X86_SSA__Opnd)i2;
  i0 = i2!=(OOC_INT32)0;
  if (!i0) goto l8;
  i0=i2;
  goto l3_loop;
l8:
  return;
  ;
}

OOC_SymbolTable__ProcDecl OOC_X86_SSA__ResultDesc_CalledProc(OOC_X86_SSA__Result calledAdr) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)calledAdr;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33380))+4);
  i1 = *(OOC_INT8*)((_check_pointer(i1, 33386))+20);
  i1 = i1==0;
  if (i1) goto l3;
  return (OOC_SymbolTable__ProcDecl)0;
  goto l4;
l3:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33430))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33436))+28);
  i0 = _check_pointer(i0, 33447);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 33447))*4);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33451)))), &_td_OOC_X86_SSA__ProcDesc, 33451)), 33456));
  return (OOC_SymbolTable__ProcDecl)i0;
l4:
  _failed_function(33176); return 0;
  ;
}

OOC_CHAR8 OOC_X86_SSA__ResultDesc_IsFalse(OOC_X86_SSA__Result res) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)res;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 33666))+12);
  i1 = i1==5;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33697))+4);
  i1 = *(OOC_INT8*)((_check_pointer(i1, 33703))+20);
  i1 = i1==0;
  
l5:
  if (i1) goto l7;
  i0=0u;
  goto l8;
l7:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33733))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 33739))+28);
  i1 = _check_pointer(i1, 33750);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 33750))*4);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33733))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33739))+28);
  i0 = _check_pointer(i0, 33750);
  i2 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i2, OOC_UINT8, 33750))*4);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33754)))), &_td_OOC_X86_SSA__ConstDesc, 33754)), 33760));
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 33754)))), &_td_OOC_X86_SSA__ConstDesc, 33754)), 33760));
  i2 = (OOC_INT32)Object_BigInt__zero;
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33766)))), Object__ObjectDesc_Equals)),Object__ObjectDesc_Equals)((Object__Object)i1, (Object__Object)i2);
  
l8:
  return i0;
  ;
}

OOC_CHAR8 OOC_X86_SSA__ResultDesc_IsTrue(OOC_X86_SSA__Result res) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)res;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 33950))+12);
  i1 = i1==5;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 33981))+4);
  i1 = *(OOC_INT8*)((_check_pointer(i1, 33987))+20);
  i1 = i1==0;
  
l5:
  if (i1) goto l7;
  i0=0u;
  goto l8;
l7:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34018))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34024))+28);
  i1 = _check_pointer(i1, 34035);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 34035))*4);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34018))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34024))+28);
  i0 = _check_pointer(i0, 34035);
  i2 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i2, OOC_UINT8, 34035))*4);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34039)))), &_td_OOC_X86_SSA__ConstDesc, 34039)), 34045));
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 34039)))), &_td_OOC_X86_SSA__ConstDesc, 34039)), 34045));
  i2 = (OOC_INT32)Object_BigInt__zero;
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34051)))), Object__ObjectDesc_Equals)),Object__ObjectDesc_Equals)((Object__Object)i1, (Object__Object)i2);
  i0 = !i0;
  
l8:
  return i0;
  ;
}

Object_Boxed__Object OOC_X86_SSA__ResultDesc_GetConst(OOC_X86_SSA__Result res) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)res;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34281))+4);
  i1 = *(OOC_INT8*)((_check_pointer(i1, 34287))+20);
  i1 = i1==0;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34310))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34316))+28);
  i1 = _check_pointer(i1, 34327);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 34327))*4);
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 34331)))), &_td_OOC_X86_SSA__ConstDesc);
  
l5:
  if (i1) goto l7;
  return (Object_Boxed__Object)0;
  goto l8;
l7:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34361))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 34367))+28);
  i0 = _check_pointer(i0, 34378);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 34378))*4);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 34382)))), &_td_OOC_X86_SSA__ConstDesc, 34382)), 34388));
  return (Object_Boxed__Object)i0;
l8:
  _failed_function(34112); return 0;
  ;
}

OOC_X86_SSA__IterResultUses OOC_X86_SSA__ResultDesc_Uses(OOC_X86_SSA__Result res) {
  register OOC_INT32 i0,i1;
  OOC_X86_SSA__IterResultUses iter;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__IterResultUses.baseTypes[0]);
  iter = (OOC_X86_SSA__IterResultUses)i0;
  i1 = (OOC_INT32)res;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34573))+8);
  *(OOC_INT32*)(_check_pointer(i0, 34561)) = i1;
  return (OOC_X86_SSA__IterResultUses)i0;
  ;
}

OOC_CHAR8 OOC_X86_SSA__IterResultUsesDesc_Next(OOC_X86_SSA__IterResultUses iter, OOC_X86_SSA__Opnd *use) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)iter;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 34700));
  *use = (OOC_X86_SSA__Opnd)i1;
  i2 = i1==0;
  if (i2) goto l3;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 34782))+12);
  *(OOC_INT32*)(_check_pointer(i0, 34770)) = i1;
  return 1u;
  goto l4;
l3:
  return 0u;
l4:
  _failed_function(34646); return 0;
  ;
}

void OOC_X86_SSA__DepDesc_INIT(OOC_X86_SSA__Dep dep, OOC_INT8 type, OOC_X86_SSA__Instr before, OOC_X86_SSA__Instr after) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)dep;
  i1 = type;
  *(OOC_INT8*)((_check_pointer(i0, 34915))+8) = i1;
  i1 = (OOC_INT32)before;
  *(OOC_INT32*)(_check_pointer(i0, 34937)) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 34963))+4) = 0;
  i1 = (OOC_INT32)after;
  *(OOC_INT32*)((_check_pointer(i0, 34990))+12) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 35014))+16) = 0;
  return;
  ;
}

void OOC_X86_SSA__DepDesc_DeleteDep(OOC_X86_SSA__Dep dep) {
  register OOC_INT32 i0,i1,i2;
  OOC_X86_SSA__Instr instr;
  OOC_X86_SSA__Dep ptr;

  i0 = (OOC_INT32)dep;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35143))+12);
  instr = (OOC_X86_SSA__Instr)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 35164))+32);
  i2 = i2==i0;
  if (i2) goto l12;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 35257))+32);
  ptr = (OOC_X86_SSA__Dep)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 35286))+4);
  i2 = i2!=i0;
  if (!i2) goto l11;
l6_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 35326))+4);
  ptr = (OOC_X86_SSA__Dep)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 35286))+4);
  i2 = i2!=i0;
  if (i2) goto l6_loop;
l11:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35377))+4);
  *(OOC_INT32*)((_check_pointer(i1, 35359))+4) = i2;
  goto l13;
l12:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35217))+4);
  *(OOC_INT32*)((_check_pointer(i1, 35199))+32) = i2;
l13:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 35416));
  instr = (OOC_X86_SSA__Instr)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 35438))+36);
  i2 = i2==i0;
  if (i2) goto l25;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 35528))+36);
  ptr = (OOC_X86_SSA__Dep)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 35556))+16);
  i2 = i2!=i0;
  if (!i2) goto l24;
l19_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 35595))+16);
  ptr = (OOC_X86_SSA__Dep)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 35556))+16);
  i2 = i2!=i0;
  if (i2) goto l19_loop;
l24:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35644))+16);
  *(OOC_INT32*)((_check_pointer(i1, 35627))+16) = i0;
  goto l26;
l25:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 35489))+16);
  *(OOC_INT32*)((_check_pointer(i1, 35472))+36) = i0;
l26:
  return;
  ;
}

void OOC_X86_SSA__InstrDesc_INIT(OOC_X86_SSA__Instr instr, OOC_INT8 opcode) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)instr;
  OOC_X86_SSA__NodeDesc_INIT((OOC_X86_SSA__Node)i0);
  *(OOC_INT32*)(_check_pointer(i0, 35768)) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 35795))+4) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 35824))+8) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 35852))+12) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 35880))+16) = 0;
  i1 = opcode;
  *(OOC_INT8*)((_check_pointer(i0, 35904))+20) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 35932))+24) = (-1);
  *(OOC_INT32*)((_check_pointer(i0, 35953))+28) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 35982))+32) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 36011))+36) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 36039))+40) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 36062))+44) = 0;
  return;
  ;
}

void OOC_X86_SSA__InstrDesc_SetOpcode(OOC_X86_SSA__Instr instr, OOC_INT8 opcode) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)instr;
  i1 = opcode;
  *(OOC_INT8*)((_check_pointer(i0, 36159))+20) = i1;
  return;
  ;
}

OOC_CHAR8 OOC_X86_SSA__InstrDesc_NonImmediateUses(OOC_X86_SSA__Instr instr) {
  register OOC_INT32 i0,i1,i2;
  OOC_X86_SSA__Result res;
  OOC_X86_SSA__Opnd use;

  i0 = (OOC_INT32)instr;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36453))+4);
  res = (OOC_X86_SSA__Result)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l23;
l3_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 36507))+8);
  use = (OOC_X86_SSA__Opnd)i1;
  i2 = i1!=(OOC_INT32)0;
  if (!i2) goto l18;
l6_loop:
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 36559))+16);
  i2 = !i2;
  if (i2) goto l9;
  i2=0u;
  goto l11;
l9:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 36576))+8);
  i2 = *(OOC_INT8*)((_check_pointer(i2, 36582))+20);
  i2 = i2!=23;
  
l11:
  if (!i2) goto l13;
  return 1u;
l13:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 36660))+12);
  use = (OOC_X86_SSA__Opnd)i1;
  i2 = i1!=(OOC_INT32)0;
  if (i2) goto l6_loop;
l18:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 36697));
  res = (OOC_X86_SSA__Result)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3_loop;
l23:
  return 0u;
  ;
}

OOC_CHAR8 OOC_X86_SSA__InstrDesc_IsLive(OOC_X86_SSA__Instr instr) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)instr;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 36829))+20);
  switch (i1) {
  case 17:
  case 18:
  case 19:
  case 34:
  case 37:
  case 25:
  case 32:
  case 39:
  case 40:
  case 42:
  case 41:
  case 43:
  case 20:
    return 1u;
    goto l4;
  default:
    i0 = OOC_X86_SSA__InstrDesc_NonImmediateUses((OOC_X86_SSA__Instr)i0);
    return i0;
    goto l4;
  }
l4:
  _failed_function(36787); return 0;
  ;
}

OOC_CHAR8 OOC_X86_SSA__InstrDesc_Unchecked(OOC_X86_SSA__Instr instr) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)instr;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 37323))+36);
  return (i0==(OOC_INT32)0);
  ;
}

OOC_CHAR8 OOC_X86_SSA__InstrDesc_IsLoopEndGate(OOC_X86_SSA__Instr instr) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)instr;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 37437))+20);
  i1 = i1==38;
  if (i1) goto l3;
  i0=0u;
  goto l4;
l3:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37462)))), &_td_OOC_X86_SSA__GateInstrDesc, 37462)), 37472))+48);
  i0 = *(OOC_INT8*)((_check_pointer(i0, 37478))+20);
  i0 = i0==41;
  
l4:
  return i0;
  ;
}

OOC_X86_SSA__MergeInstr OOC_X86_SSA__InstrDesc_TopLevelMerge(OOC_X86_SSA__Instr instr) {
  register OOC_INT32 i0,i1;
  OOC_X86_SSA__Instr last;

  i0 = (OOC_INT32)instr;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37921)))), &_td_OOC_X86_SSA__BranchInstrDesc, 37921)), 37933))+52);
  last = (OOC_X86_SSA__Instr)i0;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37958)))), &_td_OOC_X86_SSA__MergeInstrDesc);
  if (i1) goto l3;
  return (OOC_X86_SSA__MergeInstr)(OOC_INT32)0;
  goto l4;
l3:
  return (OOC_X86_SSA__MergeInstr)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 38032)))), &_td_OOC_X86_SSA__MergeInstrDesc, 38032));
l4:
  _failed_function(37545); return 0;
  ;
}

OOC_CHAR8 OOC_X86_SSA__InstrDesc_AllOpndsSameValue(OOC_X86_SSA__Instr instr) {
  register OOC_INT32 i0,i1,i2;
  OOC_X86_SSA__Opnd opnd;

  i0 = (OOC_INT32)instr;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 38202));
  i1 = i1==0;
  if (i1) goto l14;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 38271));
  opnd = (OOC_X86_SSA__Opnd)i0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 38299))+4);
  i1 = i1!=0;
  if (!i1) goto l13;
l5_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 38346))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 38355));
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 38335));
  i1 = i2!=i1;
  if (!i1) goto l8;
  return 0u;
l8:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 38423))+4);
  opnd = (OOC_X86_SSA__Opnd)i0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 38299))+4);
  i1 = i1!=0;
  if (i1) goto l5_loop;
l13:
  return 1u;
  goto l15;
l14:
  return 1u;
l15:
  _failed_function(38128); return 0;
  ;
}

OOC_INT32 OOC_X86_SSA__InstrDesc_SizeOpndList(OOC_X86_SSA__Instr instr) {
  register OOC_INT32 i0,i1,i2;
  OOC_INT32 num;
  OOC_X86_SSA__Opnd opnd;

  num = 0;
  i0 = (OOC_INT32)instr;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 38685));
  opnd = (OOC_X86_SSA__Opnd)i0;
  i1 = i0!=0;
  if (i1) goto l3;
  i0=0;
  goto l9;
l3:
  i1=i0;i0=0;
l4_loop:
  i0 = i0+1;
  num = i0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 38756))+4);
  opnd = (OOC_X86_SSA__Opnd)i1;
  i2 = i1!=0;
  if (i2) goto l4_loop;
l9:
  return i0;
  ;
}

static void OOC_X86_SSA__AddOpnd(OOC_X86_SSA__Instr instr, OOC_X86_SSA__Opnd opnd) {
  register OOC_INT32 i0,i1,i2;
  OOC_X86_SSA__Opnd prev;

  i0 = (OOC_INT32)opnd;
  i1 = (OOC_INT32)instr;
  *(OOC_INT32*)((_check_pointer(i0, 38987))+8) = i1;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 39017));
  i2 = i2==0;
  if (i2) goto l12;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 39097));
  prev = (OOC_X86_SSA__Opnd)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 39125))+4);
  i2 = i2!=0;
  if (!i2) goto l11;
l6_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 39165))+4);
  prev = (OOC_X86_SSA__Opnd)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 39125))+4);
  i2 = i2!=0;
  if (i2) goto l6_loop;
l11:
  *(OOC_INT32*)((_check_pointer(i1, 39197))+4) = i0;
  goto l13;
l12:
  *(OOC_INT32*)(_check_pointer(i1, 39050)) = i0;
l13:
  return;
  ;
}

void OOC_X86_SSA__InstrDesc_SetDesignator(OOC_X86_SSA__Instr instr, OOC_X86_SSA__Designator designator) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)instr;
  i1 = (OOC_INT32)designator;
  *(OOC_INT32*)((_check_pointer(i0, 39323))+28) = i1;
  return;
  ;
}

void OOC_X86_SSA__InstrDesc_ExtendDesignator(OOC_X86_SSA__Instr instr, OOC_X86_SSA__Selector selector) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  OOC_X86_SSA__Designator _new;
  OOC_INT32 i;

  i0 = (OOC_INT32)instr;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 39509))+28);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 39520)), 0);
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Designator.baseTypes[0], (i1+1));
  _new = (OOC_X86_SSA__Designator)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 39554))+28);
  i = 0;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 39565)), 0);
  i3 = 0<i2;
  if (!i3) goto l8;
  i3=0;
l3_loop:
  i4 = _check_pointer(i1, 39582);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 39594))+28);
  i6 = _check_pointer(i6, 39605);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i3, i7, OOC_UINT32, 39605))*4);
  *(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 39582))*4) = i6;
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l3_loop;
l8:
  i2 = _check_pointer(i1, 39626);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 39636))+28);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 39647)), 0);
  i4 = OOC_ARRAY_LENGTH(i2, 0);
  i5 = (OOC_INT32)selector;
  *(OOC_INT32*)(i2+(_check_index(i3, i4, OOC_UINT32, 39626))*4) = i5;
  *(OOC_INT32*)((_check_pointer(i0, 39673))+28) = i1;
  return;
  ;
}

void OOC_X86_SSA__InstrDesc_AddOpnd(OOC_X86_SSA__Instr instr, OOC_X86_SSA__Result arg) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Opnd.baseTypes[0]);
  i1 = (OOC_INT32)arg;
  OOC_X86_SSA__OpndDesc_INIT((OOC_X86_SSA__Opnd)i0, (OOC_X86_SSA__Result)i1);
  i1 = (OOC_INT32)instr;
  OOC_X86_SSA__AddOpnd((OOC_X86_SSA__Instr)i1, (OOC_X86_SSA__Opnd)i0);
  return;
  ;
}

OOC_X86_SSA__Result OOC_X86_SSA__InstrDesc_AddResult(OOC_X86_SSA__Instr instr, OOC_INT8 type) {
  register OOC_INT32 i0,i1,i2;
  OOC_X86_SSA__Result res;
  OOC_X86_SSA__Result prev;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Result.baseTypes[0]);
  i1 = type;
  OOC_X86_SSA__ResultDesc_INIT((OOC_X86_SSA__Result)i0, i1);
  res = (OOC_X86_SSA__Result)i0;
  i1 = (OOC_INT32)instr;
  *(OOC_INT32*)((_check_pointer(i0, 40228))+4) = i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 40258))+4);
  i2 = i2==(OOC_INT32)0;
  if (i2) goto l12;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 40341))+4);
  prev = (OOC_X86_SSA__Result)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 40371));
  i2 = i2!=(OOC_INT32)0;
  if (!i2) goto l11;
l6_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 40413));
  prev = (OOC_X86_SSA__Result)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 40371));
  i2 = i2!=(OOC_INT32)0;
  if (i2) goto l6_loop;
l11:
  *(OOC_INT32*)(_check_pointer(i1, 40447)) = i0;
  goto l13;
l12:
  *(OOC_INT32*)((_check_pointer(i1, 40293))+4) = i0;
l13:
  return (OOC_X86_SSA__Result)i0;
  ;
}

OOC_INT8 OOC_X86_SSA__MapType(OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 40576)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
  type = (OOC_SymbolTable__Type)i0;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 40601)))), &_td_OOC_SymbolTable__PredefTypeDesc);
  if (i1) goto l23;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 41340)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (i1) goto l21;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 41386)))), &_td_OOC_SymbolTable__RecordDesc);
  if (i1) goto l19;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 41433)))), &_td_OOC_SymbolTable__PointerDesc);
  if (i1) goto l17;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 41482)))), &_td_OOC_SymbolTable__FormalParsDesc);
  if (i1) goto l15;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 41534)))), &_td_OOC_SymbolTable__TypeVarDesc);
  if (i1) goto l13;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 41528)))), 41528);
  goto l43;
l13:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 41576))+40);
  i0 = OOC_X86_SSA__MapType((OOC_SymbolTable__Type)i0);
  return i0;
  goto l43;
l15:
  return 9;
  goto l43;
l17:
  return 9;
  goto l43;
l19:
  return 0;
  goto l43;
l21:
  return 0;
  goto l43;
l23:
  i0 = *(OOC_INT16*)((_check_pointer(i0, 40636))+40);
  switch (i0) {
  case 17:
    return 0;
    goto l43;
  case 1:
    return 5;
    goto l43;
  case 2:
    return 6;
    goto l43;
  case 3:
    return 7;
    goto l43;
  case 0:
    return 5;
    goto l43;
  case 4:
    return 1;
    goto l43;
  case 5:
    return 2;
    goto l43;
  case 6:
    return 3;
    goto l43;
  case 7:
    return 4;
    goto l43;
  case 8:
    return 10;
    goto l43;
  case 9:
    return 11;
    goto l43;
  case 10:
    return 7;
    goto l43;
  case 11:
    return 5;
    goto l43;
  case 12:
    return 9;
    goto l43;
  case 13:
  case 14:
  case 15:
    return 9;
    goto l43;
  case 16:
    return 9;
    goto l43;
  default:
    _failed_case(i0, 40627);
    goto l43;
  }
l43:
  _failed_function(40520); return 0;
  ;
}

OOC_INT32 OOC_X86_SSA__TypeSize(OOC_INT8 type) {
  register OOC_INT32 i0;

  i0 = type;
  switch (i0) {
  case 1:
  case 5:
    return 1;
    goto l7;
  case 2:
  case 6:
    return 2;
    goto l7;
  case 3:
  case 7:
  case 10:
  case 9:
    return 4;
    goto l7;
  case 4:
  case 8:
  case 11:
    return 8;
    goto l7;
  default:
    _failed_case(i0, 41664);
    goto l7;
  }
l7:
  _failed_function(41620); return 0;
  ;
}

OOC_X86_SSA__Result OOC_X86_SSA__InstrDesc_AddResultExpr(OOC_X86_SSA__Instr instr, OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)type;
  i0 = OOC_X86_SSA__MapType((OOC_SymbolTable__Type)i0);
  i1 = (OOC_INT32)instr;
  i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i1, i0);
  return (OOC_X86_SSA__Result)i0;
  ;
}

OOC_X86_SSA__Result OOC_X86_SSA__InstrDesc_AddResultReg(OOC_X86_SSA__Instr instr, OOC_INT8 type, OOC_INT8 reg) {
  register OOC_INT32 i0,i1;
  OOC_X86_SSA__Result res;

  i0 = type;
  i1 = (OOC_INT32)instr;
  i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i1, i0);
  res = (OOC_X86_SSA__Result)i0;
  *(OOC_INT8*)((_check_pointer(i0, 42472))+14) = 0;
  i1 = reg;
  *(OOC_INT8*)((_check_pointer(i0, 42501))+13) = i1;
  return (OOC_X86_SSA__Result)i0;
  ;
}

OOC_X86_SSA__Opnd OOC_X86_SSA__InstrDesc_NthOpnd(OOC_X86_SSA__Instr instr, OOC_INT32 nth) {
  register OOC_INT32 i0,i1,i2;
  OOC_X86_SSA__Opnd opnd;

  i0 = (OOC_INT32)instr;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 42806));
  opnd = (OOC_X86_SSA__Opnd)i0;
  i1 = nth;
  i2 = i1!=0;
  if (!i2) goto l9;
l4_loop:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 42858))+4);
  opnd = (OOC_X86_SSA__Opnd)i0;
  i1 = i1-1;
  nth = i1;
  i2 = i1!=0;
  if (i2) goto l4_loop;
l9:
  return (OOC_X86_SSA__Opnd)i0;
  ;
}

OOC_X86_SSA__Result OOC_X86_SSA__InstrDesc_NthArg(OOC_X86_SSA__Instr instr, OOC_INT32 nth) {
  register OOC_INT32 i0,i1,i2;
  OOC_X86_SSA__Opnd opnd;

  i0 = (OOC_INT32)instr;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 43194));
  opnd = (OOC_X86_SSA__Opnd)i0;
  i1 = nth;
  i2 = i1!=0;
  if (!i2) goto l9;
l4_loop:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 43246))+4);
  opnd = (OOC_X86_SSA__Opnd)i0;
  i1 = i1-1;
  nth = i1;
  i2 = i1!=0;
  if (i2) goto l4_loop;
l9:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 43297));
  return (OOC_X86_SSA__Result)i0;
  ;
}

OOC_INT32 OOC_X86_SSA__InstrDesc_IncomingPaths(OOC_X86_SSA__Instr instr) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)instr;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 43392))+20);
  switch (i1) {
  case 36:
  case 35:
  case 41:
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 43455)))), &_td_OOC_X86_SSA__MergeInstrDesc, 43455)), 43466))+56);
    i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 43472)), 0);
    return i0;
    goto l5;
  case 40:
    return 2;
    goto l5;
  default:
    _failed_case(i1, 43382);
    goto l5;
  }
l5:
  _failed_function(43343); return 0;
  ;
}

void OOC_X86_SSA__InstrDesc_AddDep(OOC_X86_SSA__Instr instr, OOC_INT8 type, OOC_X86_SSA__Instr beforeInstr) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_X86_SSA__Dep ptr;
  OOC_X86_SSA__Dep dep;

  i0 = (OOC_INT32)instr;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 43823))+32);
  ptr = (OOC_X86_SSA__Dep)i1;
  i2 = (OOC_INT32)beforeInstr;
  i3 = type;
  i4 = i1!=(OOC_INT32)0;
  if (!i4) goto l15;
l3_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 43874));
  i4 = i4==i2;
  if (i4) goto l6;
  i4=0u;
  goto l8;
l6:
  i4 = *(OOC_INT8*)((_check_pointer(i1, 43903))+8);
  i4 = i4==i3;
  
l8:
  if (!i4) goto l10;
  return;
l10:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 43965))+4);
  ptr = (OOC_X86_SSA__Dep)i1;
  i4 = i1!=(OOC_INT32)0;
  if (i4) goto l3_loop;
l15:
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Dep.baseTypes[0]);
  OOC_X86_SSA__DepDesc_INIT((OOC_X86_SSA__Dep)i1, i3, (OOC_X86_SSA__Instr)i2, (OOC_X86_SSA__Instr)i0);
  dep = (OOC_X86_SSA__Dep)i1;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 44062))+32);
  *(OOC_INT32*)((_check_pointer(i1, 44042))+4) = i3;
  *(OOC_INT32*)((_check_pointer(i0, 44084))+32) = i1;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 44136))+36);
  *(OOC_INT32*)((_check_pointer(i1, 44111))+16) = i0;
  *(OOC_INT32*)((_check_pointer(i2, 44163))+36) = i1;
  return;
  ;
}

OOC_X86_SSA__Dep OOC_X86_SSA__InstrDesc_GetDep(OOC_X86_SSA__Instr instr, OOC_INT8 type) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_X86_SSA__Dep x;
  OOC_X86_SSA__Dep dep;

  x = (OOC_X86_SSA__Dep)(OOC_INT32)0;
  i0 = (OOC_INT32)instr;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 44321))+32);
  dep = (OOC_X86_SSA__Dep)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3;
  i0=(OOC_INT32)0;
  goto l13;
l3:
  i1 = type;
  i2=(OOC_INT32)0;
l4_loop:
  i3 = *(OOC_INT8*)((_check_pointer(i0, 44372))+8);
  i3 = i3==i1;
  if (!i3) goto l8;
  _assert((i2==(OOC_INT32)0), 127, 44399);
  x = (OOC_X86_SSA__Dep)i0;
  i2=i0;
l8:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 44461))+4);
  dep = (OOC_X86_SSA__Dep)i0;
  i3 = i0!=(OOC_INT32)0;
  if (i3) goto l4_loop;
l12:
  i0=i2;
l13:
  _assert((i0!=(OOC_INT32)0), 127, 44487);
  return (OOC_X86_SSA__Dep)i0;
  ;
}

void OOC_X86_SSA__InstrDesc_DeleteDep(OOC_X86_SSA__Instr instr, OOC_INT8 type) {
  register OOC_INT32 i0,i1;

  i0 = type;
  i1 = (OOC_INT32)instr;
  i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_GetDep((OOC_X86_SSA__Instr)i1, i0);
  OOC_X86_SSA__DepDesc_DeleteDep((OOC_X86_SSA__Dep)i0);
  return;
  ;
}

OOC_X86_SSA__Instr OOC_X86_SSA__InstrDesc_GetBeforeInstr(OOC_X86_SSA__Instr instr, OOC_INT8 type) {
  register OOC_INT32 i0,i1;
  OOC_X86_SSA__Dep dep;

  i0 = type;
  i1 = (OOC_INT32)instr;
  i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_GetDep((OOC_X86_SSA__Instr)i1, i0);
  dep = (OOC_X86_SSA__Dep)i0;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 44820));
  return (OOC_X86_SSA__Instr)i0;
  ;
}

OOC_X86_SSA__Instr OOC_X86_SSA__InstrDesc_GetAfterInstr(OOC_X86_SSA__Instr instr, OOC_INT8 type) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_X86_SSA__Instr x;
  OOC_X86_SSA__Dep dep;

  x = (OOC_X86_SSA__Instr)(OOC_INT32)0;
  i0 = (OOC_INT32)instr;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 44987))+36);
  dep = (OOC_X86_SSA__Dep)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3;
  i0=(OOC_INT32)0;
  goto l13;
l3:
  i1 = type;
  i2=(OOC_INT32)0;
l4_loop:
  i3 = *(OOC_INT8*)((_check_pointer(i0, 45037))+8);
  i3 = i3==i1;
  if (!i3) goto l8;
  _assert((i2==(OOC_INT32)0), 127, 45064);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 45097))+12);
  x = (OOC_X86_SSA__Instr)i2;
  
l8:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 45132))+16);
  dep = (OOC_X86_SSA__Dep)i0;
  i3 = i0!=(OOC_INT32)0;
  if (i3) goto l4_loop;
l12:
  i0=i2;
l13:
  _assert((i0!=(OOC_INT32)0), 127, 45157);
  return (OOC_X86_SSA__Instr)i0;
  ;
}

OOC_X86_SSA__Instr OOC_X86_SSA__InstrDesc_GetAfterInstrOpcode(OOC_X86_SSA__Instr instr, OOC_INT8 type, OOC_INT8 opcode) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_X86_SSA__Instr x;
  OOC_X86_SSA__Dep dep;

  x = (OOC_X86_SSA__Instr)(OOC_INT32)0;
  i0 = (OOC_INT32)instr;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 45413))+36);
  dep = (OOC_X86_SSA__Dep)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3;
  i0=(OOC_INT32)0;
  goto l17;
l3:
  i1 = type;
  i2 = opcode;
  i3=(OOC_INT32)0;
l4_loop:
  i4 = *(OOC_INT8*)((_check_pointer(i0, 45463))+8);
  i4 = i4==i1;
  if (i4) goto l7;
  i4=0u;
  goto l9;
l7:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 45483))+12);
  i4 = *(OOC_INT8*)((_check_pointer(i4, 45489))+20);
  i4 = i4==i2;
  
l9:
  if (!i4) goto l12;
  _assert((i3==(OOC_INT32)0), 127, 45520);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 45553))+12);
  x = (OOC_X86_SSA__Instr)i3;
  
l12:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 45588))+16);
  dep = (OOC_X86_SSA__Dep)i0;
  i4 = i0!=(OOC_INT32)0;
  if (i4) goto l4_loop;
l16:
  i0=i3;
l17:
  _assert((i0!=(OOC_INT32)0), 127, 45613);
  return (OOC_X86_SSA__Instr)i0;
  ;
}

OOC_X86_SSA__BranchInstr OOC_X86_SSA__InstrDesc_GetBranchBeforeInstr(OOC_X86_SSA__Instr instr, OOC_INT8 type) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_X86_SSA__Dep x;
  OOC_X86_SSA__Dep dep;

  x = (OOC_X86_SSA__Dep)(OOC_INT32)0;
  i0 = (OOC_INT32)instr;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 45818))+32);
  dep = (OOC_X86_SSA__Dep)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3;
  i0=(OOC_INT32)0;
  goto l17;
l3:
  i1 = type;
  i2=(OOC_INT32)0;
l4_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 45869));
  i3 = *(OOC_INT8*)((_check_pointer(i3, 45876))+20);
  i3 = i3==34;
  if (i3) goto l7;
  i3=0u;
  goto l9;
l7:
  i3 = *(OOC_INT8*)((_check_pointer(i0, 45900))+8);
  i3 = i3==i1;
  
l9:
  if (!i3) goto l12;
  _assert((i2==(OOC_INT32)0), 127, 45927);
  x = (OOC_X86_SSA__Dep)i0;
  i2=i0;
l12:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 45989))+4);
  dep = (OOC_X86_SSA__Dep)i0;
  i3 = i0!=(OOC_INT32)0;
  if (i3) goto l4_loop;
l16:
  i0=i2;
l17:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 46023));
  return (OOC_X86_SSA__BranchInstr)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 46031)))), &_td_OOC_X86_SSA__BranchInstrDesc, 46031));
  ;
}

OOC_X86_SSA__MergeInstr OOC_X86_SSA__InstrDesc_JumpTarget(OOC_X86_SSA__Instr instr) {
  register OOC_INT32 i0,i1;
  OOC_X86_SSA__Instr merge;

  i0 = (OOC_INT32)instr;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 46174))+20);
  _assert((i1==37), 127, 46162);
  i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_GetAfterInstr((OOC_X86_SSA__Instr)i0, 0);
  merge = (OOC_X86_SSA__Instr)i0;
  return (OOC_X86_SSA__MergeInstr)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 46254)))), &_td_OOC_X86_SSA__MergeInstrDesc, 46254));
  ;
}

OOC_X86_SSA__Block OOC_X86_SSA__InstrDesc_MergingTarget(OOC_X86_SSA__Instr instr) {
  register OOC_INT32 i0,i1;
  OOC_X86_SSA__Instr target;

  i0 = (OOC_INT32)instr;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 46383))+20);
  switch (i1) {
  case 37:
    i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_JumpTarget((OOC_X86_SSA__Instr)i0);
    return (OOC_X86_SSA__Block)i0;
    goto l7;
  case 40:
    return (OOC_X86_SSA__Block)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 46475)))), &_td_OOC_X86_SSA__LoopStartInstrDesc, 46475));
    goto l7;
  case 42:
    i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_GetAfterInstrOpcode((OOC_X86_SSA__Instr)i0, 0, 41);
    target = (OOC_X86_SSA__Instr)i0;
    return (OOC_X86_SSA__Block)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 46592)))), &_td_OOC_X86_SSA__BlockDesc, 46592));
    goto l7;
  case 43:
    i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 46639)))), &_td_OOC_X86_SSA__LoopBackedgeInstrDesc, 46639)), 46657))+48);
    return (OOC_X86_SSA__Block)i0;
    goto l7;
  default:
    _failed_case(i1, 46373);
    goto l7;
  }
l7:
  _failed_function(46311); return 0;
  ;
}

void OOC_X86_SSA__InstrDesc_TransferDeps(OOC_X86_SSA__Instr instr) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_X86_SSA__Dep after;
  OOC_X86_SSA__Dep nextAfter;
  OOC_X86_SSA__Dep before;

  i0 = (OOC_INT32)instr;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 47061))+36);
  after = (OOC_X86_SSA__Dep)i1;
  i2 = i1!=(OOC_INT32)0;
  if (!i2) goto l16;
l3_loop:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 47124))+16);
  nextAfter = (OOC_X86_SSA__Dep)i2;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 47157))+32);
  before = (OOC_X86_SSA__Dep)i3;
  i4 = i3!=(OOC_INT32)0;
  if (!i4) goto l11;
l6_loop:
  i4 = *(OOC_INT8*)((_check_pointer(i3, 47233))+8);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 47213))+12);
  i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 47246));
  OOC_X86_SSA__InstrDesc_AddDep((OOC_X86_SSA__Instr)i5, i4, (OOC_X86_SSA__Instr)i6);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 47280))+4);
  before = (OOC_X86_SSA__Dep)i3;
  i4 = i3!=(OOC_INT32)0;
  if (i4) goto l6_loop;
l11:
  OOC_X86_SSA__DepDesc_DeleteDep((OOC_X86_SSA__Dep)i1);
  after = (OOC_X86_SSA__Dep)i2;
  i1 = i2!=(OOC_INT32)0;
  if (!i1) goto l16;
  i1=i2;
  goto l3_loop;
l16:
  return;
  ;
}

void OOC_X86_SSA__InstrDesc_DesignatorGateToGate(OOC_X86_SSA__Instr instr) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)instr;
  *(OOC_INT8*)((_check_pointer(i0, 47453))+20) = 38;
  *(OOC_INT32*)((_check_pointer(i0, 47479))+28) = (OOC_INT32)0;
  return;
  ;
}

OOC_CHAR8 OOC_X86_SSA__IterOperandsDesc_Next(OOC_X86_SSA__IterOperands iter, OOC_X86_SSA__Opnd *opnd) {

  _failed_function(47570); return 0;
  ;
}

OOC_X86_SSA__IterInstrOperands OOC_X86_SSA__InstrDesc_Operands(OOC_X86_SSA__Instr instr) {
  register OOC_INT32 i0,i1;
  OOC_X86_SSA__IterInstrOperands iter;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__IterInstrOperands.baseTypes[0]);
  iter = (OOC_X86_SSA__IterInstrOperands)i0;
  i1 = (OOC_INT32)instr;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 47752));
  *(OOC_INT32*)(_check_pointer(i0, 47738)) = i1;
  return (OOC_X86_SSA__IterInstrOperands)i0;
  ;
}

OOC_CHAR8 OOC_X86_SSA__IterInstrOperandsDesc_Next(OOC_X86_SSA__IterInstrOperands iter, OOC_X86_SSA__Opnd *opnd) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)iter;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 47889));
  *opnd = (OOC_X86_SSA__Opnd)i1;
  i2 = i1==0;
  if (i2) goto l3;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 47973))+4);
  *(OOC_INT32*)(_check_pointer(i0, 47960)) = i1;
  return 1u;
  goto l4;
l3:
  return 0u;
l4:
  _failed_function(47833); return 0;
  ;
}

OOC_X86_SSA__IterInstrResults OOC_X86_SSA__InstrDesc_Results(OOC_X86_SSA__Instr instr) {
  register OOC_INT32 i0,i1;
  OOC_X86_SSA__IterInstrResults iter;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__IterInstrResults.baseTypes[0]);
  iter = (OOC_X86_SSA__IterInstrResults)i0;
  i1 = (OOC_INT32)instr;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 48159))+4);
  *(OOC_INT32*)(_check_pointer(i0, 48145)) = i1;
  return (OOC_X86_SSA__IterInstrResults)i0;
  ;
}

OOC_CHAR8 OOC_X86_SSA__IterInstrResultsDesc_Next(OOC_X86_SSA__IterInstrResults iter, OOC_X86_SSA__Result *res) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)iter;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 48296));
  *res = (OOC_X86_SSA__Result)i1;
  i2 = i1==0;
  if (i2) goto l3;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 48378));
  *(OOC_INT32*)(_check_pointer(i0, 48366)) = i1;
  return 1u;
  goto l4;
l3:
  return 0u;
l4:
  _failed_function(48240); return 0;
  ;
}

OOC_X86_SSA__IterJumpGateOperands OOC_X86_SSA__InstrDesc_GateOperands(OOC_X86_SSA__Instr instr) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_X86_SSA__IterJumpGateOperands iter;
  OOC_X86_SSA__Block merge;
  OOC_INT32 i;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__IterJumpGateOperands.baseTypes[0]);
  iter = (OOC_X86_SSA__IterJumpGateOperands)i0;
  i1 = (OOC_INT32)instr;
  i2 = (OOC_INT32)OOC_X86_SSA__InstrDesc_MergingTarget((OOC_X86_SSA__Instr)i1);
  merge = (OOC_X86_SSA__Block)i2;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 48654))+48);
  *(OOC_INT32*)(_check_pointer(i0, 48635)) = i3;
  i3 = *(OOC_INT8*)((_check_pointer(i1, 48680))+20);
  switch (i3) {
  case 37:
    i = 0;
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 48736)))), &_td_OOC_X86_SSA__MergeInstrDesc, 48736)), 48747))+56);
    i3 = _check_pointer(i3, 48753);
    i4 = OOC_ARRAY_LENGTH(i3, 0);
    i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(0, i4, OOC_UINT32, 48753))*4);
    i3 = i3!=i1;
    if (!i3) goto l25;
    i3=0;
l6_loop:
    i3 = i3+1;
    i = i3;
    i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 48736)))), &_td_OOC_X86_SSA__MergeInstrDesc, 48736)), 48747))+56);
    i4 = _check_pointer(i4, 48753);
    i5 = OOC_ARRAY_LENGTH(i4, 0);
    i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 48753))*4);
    i4 = i4!=i1;
    if (i4) goto l6_loop;
    goto l25;
  case 40:
    i = 0;
    goto l25;
  case 42:
    i = 0;
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 48876)))), &_td_OOC_X86_SSA__MergeInstrDesc, 48876)), 48887))+56);
    i3 = _check_pointer(i3, 48893);
    i4 = OOC_ARRAY_LENGTH(i3, 0);
    i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(0, i4, OOC_UINT32, 48893))*4);
    i3 = i3!=i1;
    if (!i3) goto l25;
    i3=0;
l17_loop:
    i3 = i3+1;
    i = i3;
    i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 48876)))), &_td_OOC_X86_SSA__MergeInstrDesc, 48876)), 48887))+56);
    i4 = _check_pointer(i4, 48893);
    i5 = OOC_ARRAY_LENGTH(i4, 0);
    i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 48893))*4);
    i4 = i4!=i1;
    if (i4) goto l17_loop;
    goto l25;
  case 43:
    i = 1;
    goto l25;
  default:
    _failed_case(i3, 48670);
    goto l25;
  }
l25:
  i1 = i;
  *(OOC_INT32*)((_check_pointer(i0, 48987))+4) = i1;
  return (OOC_X86_SSA__IterJumpGateOperands)i0;
  ;
}

OOC_CHAR8 OOC_X86_SSA__IterJumpGateOperandsDesc_Next(OOC_X86_SSA__IterJumpGateOperands iter, OOC_X86_SSA__Opnd *opnd) {
  register OOC_INT32 i0,i1,i2;
  OOC_X86_SSA__Instr instr;

  i0 = (OOC_INT32)iter;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 49158));
  instr = (OOC_X86_SSA__Instr)i1;
  i2 = i1!=0;
  if (i2) goto l3;
  i2=0u;
  goto l5;
l3:
  i2 = *(OOC_INT8*)((_check_pointer(i1, 49202))+20);
  i2 = i2!=38;
  
l5:
  if (!i2) goto l17;
l8_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 49241))+8);
  instr = (OOC_X86_SSA__Instr)i1;
  i2 = i1!=0;
  if (i2) goto l11;
  i2=0u;
  goto l13;
l11:
  i2 = *(OOC_INT8*)((_check_pointer(i1, 49202))+20);
  i2 = i2!=38;
  
l13:
  if (i2) goto l8_loop;
l17:
  i2 = i1==0;
  if (i2) goto l20;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 49365))+8);
  *(OOC_INT32*)(_check_pointer(i0, 49346)) = i2;
  i0 = *(OOC_INT32*)((_check_pointer(i0, 49409))+4);
  i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_NthOpnd((OOC_X86_SSA__Instr)i1, i0);
  *opnd = (OOC_X86_SSA__Opnd)i0;
  return 1u;
  goto l21;
l20:
  *opnd = (OOC_X86_SSA__Opnd)0;
  return 0u;
l21:
  _failed_function(49077); return 0;
  ;
}

OOC_X86_SSA__IterInstrBeforeList OOC_X86_SSA__InstrDesc_BeforeList(OOC_X86_SSA__Instr instr, OOC_INT8 type) {
  register OOC_INT32 i0,i1,i2;
  OOC_X86_SSA__IterInstrBeforeList iter;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__IterInstrBeforeList.baseTypes[0]);
  iter = (OOC_X86_SSA__IterInstrBeforeList)i0;
  i1 = (OOC_INT32)instr;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 49612))+32);
  *(OOC_INT32*)(_check_pointer(i0, 49598)) = i1;
  i1 = type;
  i2 = i1==(-1);
  if (i2) goto l3;
  *(OOC_UINT32*)((_check_pointer(i0, 49700))+4) = (_bit_range(i1,i1));
  goto l4;
l3:
  *(OOC_UINT32*)((_check_pointer(i0, 49663))+4) = 7u;
l4:
  return (OOC_X86_SSA__IterInstrBeforeList)i0;
  ;
}

OOC_CHAR8 OOC_X86_SSA__IterInstrBeforeListDesc_Next(OOC_X86_SSA__IterInstrBeforeList iter, OOC_X86_SSA__Dep *dep) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)iter;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 49854));
  *dep = (OOC_X86_SSA__Dep)i1;
  i2 = i1!=0;
  if (i2) goto l3;
  i2=0u;
  goto l5;
l3:
  i2 = *(OOC_INT8*)((_check_pointer(i1, 49890))+8);
  i3 = *(OOC_UINT32*)((_check_pointer(i0, 49903))+4);
  i2 = !(_in(i2,i3));
  
l5:
  if (!i2) goto l17;
l8_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 49930))+4);
  *dep = (OOC_X86_SSA__Dep)i1;
  i2 = i1!=0;
  if (i2) goto l11;
  i2=0u;
  goto l13;
l11:
  i2 = *(OOC_INT8*)((_check_pointer(i1, 49890))+8);
  i3 = *(OOC_UINT32*)((_check_pointer(i0, 49903))+4);
  i2 = !(_in(i2,i3));
  
l13:
  if (i2) goto l8_loop;
l17:
  i2 = i1==0;
  if (i2) goto l20;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 50027))+4);
  *(OOC_INT32*)(_check_pointer(i0, 50015)) = i1;
  return 1u;
  goto l21;
l20:
  return 0u;
l21:
  _failed_function(49801); return 0;
  ;
}

OOC_X86_SSA__IterInstrAfterList OOC_X86_SSA__InstrDesc_AfterList(OOC_X86_SSA__Instr instr, OOC_INT8 type) {
  register OOC_INT32 i0,i1,i2;
  OOC_X86_SSA__IterInstrAfterList iter;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__IterInstrAfterList.baseTypes[0]);
  iter = (OOC_X86_SSA__IterInstrAfterList)i0;
  i1 = (OOC_INT32)instr;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 50231))+36);
  *(OOC_INT32*)(_check_pointer(i0, 50217)) = i1;
  i1 = type;
  i2 = i1==(-1);
  if (i2) goto l3;
  *(OOC_UINT32*)((_check_pointer(i0, 50318))+4) = (_bit_range(i1,i1));
  goto l4;
l3:
  *(OOC_UINT32*)((_check_pointer(i0, 50281))+4) = 7u;
l4:
  return (OOC_X86_SSA__IterInstrAfterList)i0;
  ;
}

OOC_CHAR8 OOC_X86_SSA__IterInstrAfterListDesc_Next(OOC_X86_SSA__IterInstrAfterList iter, OOC_X86_SSA__Dep *dep) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)iter;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 50470));
  *dep = (OOC_X86_SSA__Dep)i1;
  i2 = i1!=0;
  if (i2) goto l3;
  i2=0u;
  goto l5;
l3:
  i2 = *(OOC_INT8*)((_check_pointer(i1, 50506))+8);
  i3 = *(OOC_UINT32*)((_check_pointer(i0, 50519))+4);
  i2 = !(_in(i2,i3));
  
l5:
  if (!i2) goto l17;
l8_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 50546))+16);
  *dep = (OOC_X86_SSA__Dep)i1;
  i2 = i1!=0;
  if (i2) goto l11;
  i2=0u;
  goto l13;
l11:
  i2 = *(OOC_INT8*)((_check_pointer(i1, 50506))+8);
  i3 = *(OOC_UINT32*)((_check_pointer(i0, 50519))+4);
  i2 = !(_in(i2,i3));
  
l13:
  if (i2) goto l8_loop;
l17:
  i2 = i1==0;
  if (i2) goto l20;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 50642))+16);
  *(OOC_INT32*)(_check_pointer(i0, 50630)) = i1;
  return 1u;
  goto l21;
l20:
  return 0u;
l21:
  _failed_function(50417); return 0;
  ;
}

void OOC_X86_SSA__BlockDesc_INIT(OOC_X86_SSA__Block b, OOC_INT8 opcode) {
  register OOC_INT32 i0,i1;

  i0 = opcode;
  i1 = (OOC_INT32)b;
  OOC_X86_SSA__InstrDesc_INIT((OOC_X86_SSA__Instr)i1, i0);
  *(OOC_INT32*)((_check_pointer(i1, 50774))+48) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i1, 50798))+52) = (OOC_INT32)0;
  return;
  ;
}

void OOC_X86_SSA__BlockDesc_Add(OOC_X86_SSA__Block b, OOC_X86_SSA__Instr instr) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)instr;
  *(OOC_INT32*)((_check_pointer(i0, 51088))+8) = (OOC_INT32)0;
  i1 = (OOC_INT32)b;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 51131))+52);
  *(OOC_INT32*)((_check_pointer(i0, 51116))+12) = i2;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 51152))+48);
  i2 = i2==(OOC_INT32)0;
  if (i2) goto l3;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 51346))+52);
  *(OOC_INT32*)((_check_pointer(i2, 51356))+8) = i0;
  *(OOC_INT32*)((_check_pointer(i1, 51384))+52) = i0;
  goto l4;
l3:
  *(OOC_INT32*)((_check_pointer(i1, 51221))+48) = i0;
  *(OOC_INT32*)((_check_pointer(i1, 51249))+52) = i0;
l4:
  *(OOC_INT32*)((_check_pointer(i0, 51423))+16) = i1;
  return;
  ;
}

void OOC_X86_SSA__BlockDesc_AddInFront(OOC_X86_SSA__Block b, OOC_X86_SSA__Instr instr) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)instr;
  *(OOC_INT32*)((_check_pointer(i0, 51670))+12) = (OOC_INT32)0;
  i1 = (OOC_INT32)b;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 51713))+48);
  *(OOC_INT32*)((_check_pointer(i0, 51698))+8) = i2;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 51734))+48);
  i2 = i2==(OOC_INT32)0;
  if (i2) goto l3;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 51933))+48);
  *(OOC_INT32*)((_check_pointer(i2, 51943))+12) = i0;
  *(OOC_INT32*)((_check_pointer(i1, 51971))+48) = i0;
  goto l4;
l3:
  *(OOC_INT32*)((_check_pointer(i1, 51802))+48) = i0;
  *(OOC_INT32*)((_check_pointer(i1, 51830))+52) = i0;
l4:
  *(OOC_INT32*)((_check_pointer(i0, 52010))+16) = i1;
  return;
  ;
}

void OOC_X86_SSA__BlockDesc_MoveBehind(OOC_X86_SSA__Block b, OOC_X86_SSA__Instr before, OOC_X86_SSA__Instr after) {
  register OOC_INT32 i0,i1,i2,i3,i4;

  i0 = (OOC_INT32)before;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 52278))+16);
  i2 = (OOC_INT32)b;
  _assert((i1==i2), 127, 52265);
  i1 = (OOC_INT32)after;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 52307))+16);
  _assert((i3==i2), 127, 52295);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 52334))+8);
  i3 = i3!=i1;
  if (!i3) goto l15;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 52401))+12);
  i3 = i3==(OOC_INT32)0;
  if (i3) goto l5;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 52488))+12);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 52517))+8);
  *(OOC_INT32*)((_check_pointer(i3, 52498))+8) = i4;
  goto l6;
l5:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 52452))+8);
  *(OOC_INT32*)((_check_pointer(i2, 52433))+48) = i3;
l6:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 52555))+8);
  i3 = i3==(OOC_INT32)0;
  if (i3) goto l9;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 52642))+8);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 52671))+12);
  *(OOC_INT32*)((_check_pointer(i3, 52652))+12) = i4;
  goto l10;
l9:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 52606))+12);
  *(OOC_INT32*)((_check_pointer(i2, 52587))+52) = i3;
l10:
  *(OOC_INT32*)((_check_pointer(i1, 52738))+12) = i0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 52791))+8);
  *(OOC_INT32*)((_check_pointer(i1, 52771))+8) = i3;
  *(OOC_INT32*)((_check_pointer(i0, 52815))+8) = i1;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 52851))+8);
  i0 = i0==(OOC_INT32)0;
  if (i0) goto l13;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 52928))+8);
  *(OOC_INT32*)((_check_pointer(i0, 52938))+12) = i1;
  goto l15;
l13:
  *(OOC_INT32*)((_check_pointer(i2, 52883))+52) = i1;
l15:
  return;
  ;
}

void OOC_X86_SSA__BlockDesc_Remove(OOC_X86_SSA__Block b, OOC_X86_SSA__Instr instr) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)instr;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53180))+16);
  i2 = (OOC_INT32)b;
  _assert((i2==i1), 127, 53164);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53202))+12);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l3;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53283))+12);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53312))+8);
  *(OOC_INT32*)((_check_pointer(i1, 53293))+8) = i3;
  goto l4;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53251))+8);
  *(OOC_INT32*)((_check_pointer(i2, 53232))+48) = i1;
l4:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53346))+8);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l7;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53427))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53456))+12);
  *(OOC_INT32*)((_check_pointer(i1, 53437))+12) = i2;
  goto l8;
l7:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53395))+12);
  *(OOC_INT32*)((_check_pointer(i2, 53376))+52) = i1;
l8:
  *(OOC_INT32*)((_check_pointer(i0, 53486))+8) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i0, 53514))+12) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i0, 53542))+16) = (OOC_INT32)0;
  return;
  ;
}

void OOC_X86_SSA__InstrDesc_MoveToFront(OOC_X86_SSA__Instr instr) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)instr;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 53655))+16);
  OOC_X86_SSA__BlockDesc_Remove((OOC_X86_SSA__Block)i1, (OOC_X86_SSA__Instr)i0);
  OOC_X86_SSA__BlockDesc_AddInFront((OOC_X86_SSA__Block)i1, (OOC_X86_SSA__Instr)i0);
  return;
  ;
}

void OOC_X86_SSA__InstrDesc_Delete(OOC_X86_SSA__Instr instr) {
  register OOC_INT32 i0,i1,i2;
  OOC_X86_SSA__Block b;

  i0 = (OOC_INT32)instr;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 54492))+16);
  b = (OOC_X86_SSA__Block)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 54582));
  i2 = i2!=0;
  if (!i2) goto l8;
l3_loop:
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 54613));
  OOC_X86_SSA__OpndDesc_DeleteOpnd((OOC_X86_SSA__Opnd)i2);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 54582));
  i2 = i2!=0;
  if (i2) goto l3_loop;
l8:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 54728))+32);
  i2 = i2!=0;
  if (!i2) goto l16;
l11_loop:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 54761))+32);
  OOC_X86_SSA__DepDesc_DeleteDep((OOC_X86_SSA__Dep)i2);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 54728))+32);
  i2 = i2!=0;
  if (i2) goto l11_loop;
l16:
  OOC_X86_SSA__BlockDesc_Remove((OOC_X86_SSA__Block)i1, (OOC_X86_SSA__Instr)i0);
  return;
  ;
}

void OOC_X86_SSA__BlockDesc_RemoveAll(OOC_X86_SSA__Block b) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)b;
  *(OOC_INT32*)((_check_pointer(i0, 54880))+48) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i0, 54904))+52) = (OOC_INT32)0;
  return;
  ;
}

OOC_INT32 OOC_X86_SSA__BlockDesc_NestingDepth(OOC_X86_SSA__Block b) {
  register OOC_INT32 i0,i1,i2;
  OOC_INT32 i;

  i0 = (OOC_INT32)b;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3;
  i0=0;
  goto l9;
l3:
  i1=i0;i0=0;
l4_loop:
  i0 = i0+1;
  i = i0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 55079))+16);
  b = (OOC_X86_SSA__Block)i1;
  i2 = i1!=(OOC_INT32)0;
  if (i2) goto l4_loop;
l9:
  return i0;
  ;
}

OOC_INT32 OOC_X86_SSA__BlockDesc_Count(OOC_X86_SSA__Block b, OOC_INT8 opcode) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_INT32 i;
  OOC_X86_SSA__Instr instr;

  i = 0;
  i0 = (OOC_INT32)b;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 55259))+48);
  instr = (OOC_X86_SSA__Instr)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3;
  i0=0;
  goto l13;
l3:
  i1 = opcode;
  i2=0;
l4_loop:
  i3 = *(OOC_INT8*)((_check_pointer(i0, 55313))+20);
  i3 = i3==i1;
  if (!i3) goto l8;
  i2 = i2+1;
  i = i2;
  
l8:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 55383))+8);
  instr = (OOC_X86_SSA__Instr)i0;
  i3 = i0!=(OOC_INT32)0;
  if (i3) goto l4_loop;
l12:
  i0=i2;
l13:
  return i0;
  ;
}

OOC_X86_SSA__IterBlockInstructions OOC_X86_SSA__BlockDesc_Instructions(OOC_X86_SSA__Block b) {
  register OOC_INT32 i0,i1;
  OOC_X86_SSA__IterBlockInstructions iter;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__IterBlockInstructions.baseTypes[0]);
  iter = (OOC_X86_SSA__IterBlockInstructions)i0;
  i1 = (OOC_INT32)b;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 55573))+48);
  *(OOC_INT32*)(_check_pointer(i0, 55563)) = i1;
  return (OOC_X86_SSA__IterBlockInstructions)i0;
  ;
}

OOC_CHAR8 OOC_X86_SSA__IterBlockInstructionsDesc_Next(OOC_X86_SSA__IterBlockInstructions iter, OOC_X86_SSA__Instr *instr) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)iter;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 55722));
  *instr = (OOC_X86_SSA__Instr)i1;
  i2 = i1==0;
  if (i2) goto l3;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 55808))+8);
  *(OOC_INT32*)(_check_pointer(i0, 55794)) = i1;
  return 1u;
  goto l4;
l3:
  return 0u;
l4:
  _failed_function(55663); return 0;
  ;
}

OOC_X86_SSA__IterBlockAllInstructions OOC_X86_SSA__BlockDesc_AllInstructions(OOC_X86_SSA__Block b, OOC_INT8 opcode) {
  register OOC_INT32 i0,i1;
  OOC_X86_SSA__IterBlockAllInstructions iter;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__IterBlockAllInstructions.baseTypes[0]);
  iter = (OOC_X86_SSA__IterBlockAllInstructions)i0;
  i1 = (OOC_INT32)b;
  *(OOC_INT32*)(_check_pointer(i0, 56015)) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 56035))+4) = 0;
  i1 = opcode;
  *(OOC_INT8*)((_check_pointer(i0, 56058))+8) = i1;
  return (OOC_X86_SSA__IterBlockAllInstructions)i0;
  ;
}

OOC_CHAR8 OOC_X86_SSA__IterBlockAllInstructionsDesc_Next(OOC_X86_SSA__IterBlockAllInstructions iter, OOC_X86_SSA__Instr *instr) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_X86_SSA__Instr i;

  i0 = (OOC_INT32)iter;
l1_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 56249));
  i = (OOC_X86_SSA__Instr)i1;
  i2 = i1==0;
  if (i2) goto l8;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 56512)))), &_td_OOC_X86_SSA__BlockDesc);
  if (i2) goto l6;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 56641))+8);
  *(OOC_INT32*)(_check_pointer(i0, 56631)) = i2;
  goto l13;
l6:
  *(OOC_INT32*)((_check_pointer(i0, 56541))+4) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 56553)))), &_td_OOC_X86_SSA__BlockDesc, 56553));
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 56586)))), &_td_OOC_X86_SSA__BlockDesc, 56586)), 56592))+48);
  *(OOC_INT32*)(_check_pointer(i0, 56575)) = i2;
  goto l13;
l8:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 56296))+4);
  i2 = i2==0;
  if (i2) goto l11;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 56379))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 56385))+8);
  *(OOC_INT32*)(_check_pointer(i0, 56366)) = i2;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 56425))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 56431))+16);
  *(OOC_INT32*)((_check_pointer(i0, 56411))+4) = i2;
  i2 = OOC_X86_SSA__IterBlockAllInstructionsDesc_Next((OOC_X86_SSA__IterBlockAllInstructions)i0, (void*)(OOC_INT32)instr);
  return i2;
  goto l13;
l11:
  return 0u;
l13:
  i2 = *(OOC_INT8*)((_check_pointer(i0, 56692))+8);
  i2 = i2<0;
  if (i2) goto l16;
  i2 = *(OOC_INT8*)((_check_pointer(i1, 56710))+20);
  i3 = *(OOC_INT8*)((_check_pointer(i0, 56724))+8);
  i2 = i2==i3;
  
  goto l18;
l16:
  i2=1u;
l18:
  if (!i2) goto l1_loop;
l21:
  *instr = (OOC_X86_SSA__Instr)i1;
  return 1u;
  ;
}

OOC_X86_SSA__Instr OOC_X86_SSA__BlockDesc_AddInstr0(OOC_X86_SSA__Block b, OOC_INT8 opcode) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Instr.baseTypes[0]);
  i1 = opcode;
  OOC_X86_SSA__InstrDesc_INIT((OOC_X86_SSA__Instr)i0, i1);
  i1 = (OOC_INT32)b;
  OOC_X86_SSA__BlockDesc_Add((OOC_X86_SSA__Block)i1, (OOC_X86_SSA__Instr)i0);
  return (OOC_X86_SSA__Instr)i0;
  ;
}

OOC_X86_SSA__Instr OOC_X86_SSA__BlockDesc_AddInstr1(OOC_X86_SSA__Block b, OOC_INT8 opcode, OOC_X86_SSA__Result arg1) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Instr.baseTypes[0]);
  i1 = opcode;
  OOC_X86_SSA__InstrDesc_INIT((OOC_X86_SSA__Instr)i0, i1);
  i1 = (OOC_INT32)arg1;
  i2 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Opnd.baseTypes[0]);
  OOC_X86_SSA__OpndDesc_INIT((OOC_X86_SSA__Opnd)i2, (OOC_X86_SSA__Result)i1);
  OOC_X86_SSA__AddOpnd((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Opnd)i2);
  i1 = (OOC_INT32)b;
  OOC_X86_SSA__BlockDesc_Add((OOC_X86_SSA__Block)i1, (OOC_X86_SSA__Instr)i0);
  return (OOC_X86_SSA__Instr)i0;
  ;
}

OOC_X86_SSA__Instr OOC_X86_SSA__BlockDesc_AddInstr2(OOC_X86_SSA__Block b, OOC_INT8 opcode, OOC_X86_SSA__Result arg1, OOC_X86_SSA__Result arg2) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Instr.baseTypes[0]);
  i1 = opcode;
  OOC_X86_SSA__InstrDesc_INIT((OOC_X86_SSA__Instr)i0, i1);
  i1 = (OOC_INT32)arg1;
  i2 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Opnd.baseTypes[0]);
  OOC_X86_SSA__OpndDesc_INIT((OOC_X86_SSA__Opnd)i2, (OOC_X86_SSA__Result)i1);
  OOC_X86_SSA__AddOpnd((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Opnd)i2);
  i1 = (OOC_INT32)arg2;
  i2 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Opnd.baseTypes[0]);
  OOC_X86_SSA__OpndDesc_INIT((OOC_X86_SSA__Opnd)i2, (OOC_X86_SSA__Result)i1);
  OOC_X86_SSA__AddOpnd((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Opnd)i2);
  i1 = (OOC_INT32)b;
  OOC_X86_SSA__BlockDesc_Add((OOC_X86_SSA__Block)i1, (OOC_X86_SSA__Instr)i0);
  return (OOC_X86_SSA__Instr)i0;
  ;
}

OOC_X86_SSA__Instr OOC_X86_SSA__BlockDesc_AddInstr3(OOC_X86_SSA__Block b, OOC_INT8 opcode, OOC_X86_SSA__Result arg1, OOC_X86_SSA__Result arg2, OOC_X86_SSA__Result arg3) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Instr.baseTypes[0]);
  i1 = opcode;
  OOC_X86_SSA__InstrDesc_INIT((OOC_X86_SSA__Instr)i0, i1);
  i1 = (OOC_INT32)arg1;
  i2 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Opnd.baseTypes[0]);
  OOC_X86_SSA__OpndDesc_INIT((OOC_X86_SSA__Opnd)i2, (OOC_X86_SSA__Result)i1);
  OOC_X86_SSA__AddOpnd((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Opnd)i2);
  i1 = (OOC_INT32)arg2;
  i2 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Opnd.baseTypes[0]);
  OOC_X86_SSA__OpndDesc_INIT((OOC_X86_SSA__Opnd)i2, (OOC_X86_SSA__Result)i1);
  OOC_X86_SSA__AddOpnd((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Opnd)i2);
  i1 = (OOC_INT32)arg3;
  i2 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Opnd.baseTypes[0]);
  OOC_X86_SSA__OpndDesc_INIT((OOC_X86_SSA__Opnd)i2, (OOC_X86_SSA__Result)i1);
  OOC_X86_SSA__AddOpnd((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Opnd)i2);
  i1 = (OOC_INT32)b;
  OOC_X86_SSA__BlockDesc_Add((OOC_X86_SSA__Block)i1, (OOC_X86_SSA__Instr)i0);
  return (OOC_X86_SSA__Instr)i0;
  ;
}

OOC_X86_SSA__Block OOC_X86_SSA__BlockDesc_AddBlock0(OOC_X86_SSA__Block b, OOC_INT8 opcode) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Block.baseTypes[0]);
  i1 = opcode;
  OOC_X86_SSA__BlockDesc_INIT((OOC_X86_SSA__Block)i0, i1);
  i1 = (OOC_INT32)b;
  OOC_X86_SSA__BlockDesc_Add((OOC_X86_SSA__Block)i1, (OOC_X86_SSA__Instr)i0);
  return (OOC_X86_SSA__Block)i0;
  ;
}

OOC_X86_SSA__Block OOC_X86_SSA__BlockDesc_AddBlock1(OOC_X86_SSA__Block b, OOC_INT8 opcode, OOC_X86_SSA__Result arg1) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Block.baseTypes[0]);
  i1 = opcode;
  OOC_X86_SSA__BlockDesc_INIT((OOC_X86_SSA__Block)i0, i1);
  i1 = (OOC_INT32)arg1;
  i2 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Opnd.baseTypes[0]);
  OOC_X86_SSA__OpndDesc_INIT((OOC_X86_SSA__Opnd)i2, (OOC_X86_SSA__Result)i1);
  OOC_X86_SSA__AddOpnd((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Opnd)i2);
  i1 = (OOC_INT32)b;
  OOC_X86_SSA__BlockDesc_Add((OOC_X86_SSA__Block)i1, (OOC_X86_SSA__Instr)i0);
  return (OOC_X86_SSA__Block)i0;
  ;
}

OOC_X86_SSA__Result OOC_X86_SSA__BlockDesc_AddConstType(OOC_X86_SSA__Block b, OOC_X86_SSA__Const selector, OOC_INT8 type) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_X86_SSA__Instr instr;
  OOC_X86_SSA__Designator designator;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Instr.baseTypes[0]);
  OOC_X86_SSA__InstrDesc_INIT((OOC_X86_SSA__Instr)i0, 0);
  instr = (OOC_X86_SSA__Instr)i0;
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Designator.baseTypes[0], 1);
  designator = (OOC_X86_SSA__Designator)i1;
  i2 = _check_pointer(i1, 58366);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = (OOC_INT32)selector;
  *(OOC_INT32*)(i2+(_check_index(0, i3, OOC_UINT8, 58366))*4) = i4;
  OOC_X86_SSA__InstrDesc_SetDesignator((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Designator)i1);
  i1 = (OOC_INT32)b;
  OOC_X86_SSA__BlockDesc_Add((OOC_X86_SSA__Block)i1, (OOC_X86_SSA__Instr)i0);
  i1 = type;
  i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i0, i1);
  return (OOC_X86_SSA__Result)i0;
  ;
}

OOC_X86_SSA__Result OOC_X86_SSA__BlockDesc_AddConst(OOC_X86_SSA__Block b, OOC_X86_SSA__Const selector, OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)type;
  i0 = OOC_X86_SSA__MapType((OOC_SymbolTable__Type)i0);
  i1 = (OOC_INT32)b;
  i2 = (OOC_INT32)selector;
  i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConstType((OOC_X86_SSA__Block)i1, (OOC_X86_SSA__Const)i2, i0);
  return (OOC_X86_SSA__Result)i0;
  ;
}

OOC_X86_SSA__Result OOC_X86_SSA__BlockDesc_AddConstBool(OOC_X86_SSA__Block b, OOC_CHAR8 value) {
  register OOC_INT32 i0,i1,i2;

  i0 = value;
  if (i0) goto l3;
  i0=0;
  goto l4;
l3:
  i0=1;
l4:
  i1 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(0);
  i2 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Const.baseTypes[0]);
  i0 = (OOC_INT32)Object_BigInt__NewInt(i0);
  OOC_X86_SSA__ConstDesc_INIT((OOC_X86_SSA__Const)i2, (Object_Boxed__Object)i0, (-1));
  i0 = (OOC_INT32)b;
  i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConst((OOC_X86_SSA__Block)i0, (OOC_X86_SSA__Const)i2, (OOC_SymbolTable__Type)i1);
  return (OOC_X86_SSA__Result)i0;
  ;
}

OOC_X86_SSA__Result OOC_X86_SSA__BlockDesc_AddConstInt(OOC_X86_SSA__Block b, Object_BigInt__BigInt value, OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Const.baseTypes[0]);
  i1 = (OOC_INT32)value;
  OOC_X86_SSA__ConstDesc_INIT((OOC_X86_SSA__Const)i0, (Object_Boxed__Object)i1, (-1));
  i1 = (OOC_INT32)b;
  i2 = (OOC_INT32)type;
  i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConst((OOC_X86_SSA__Block)i1, (OOC_X86_SSA__Const)i0, (OOC_SymbolTable__Type)i2);
  return (OOC_X86_SSA__Result)i0;
  ;
}

OOC_X86_SSA__Result OOC_X86_SSA__BlockDesc_AddConstDim(OOC_X86_SSA__Block b, OOC_INT32 dim) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(6);
  i1 = dim;
  i2 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Const.baseTypes[0]);
  i1 = (OOC_INT32)Object_BigInt__NewInt(i1);
  OOC_X86_SSA__ConstDesc_INIT((OOC_X86_SSA__Const)i2, (Object_Boxed__Object)i1, (-1));
  i1 = (OOC_INT32)b;
  i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConst((OOC_X86_SSA__Block)i1, (OOC_X86_SSA__Const)i2, (OOC_SymbolTable__Type)i0);
  return (OOC_X86_SSA__Result)i0;
  ;
}

OOC_X86_SSA__Result OOC_X86_SSA__BlockDesc_AddConstLength(OOC_X86_SSA__Block b, OOC_INT32 dim) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(6);
  i1 = dim;
  i2 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Const.baseTypes[0]);
  i1 = (OOC_INT32)Object_BigInt__NewInt(i1);
  OOC_X86_SSA__ConstDesc_INIT((OOC_X86_SSA__Const)i2, (Object_Boxed__Object)i1, (-1));
  i1 = (OOC_INT32)b;
  i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConst((OOC_X86_SSA__Block)i1, (OOC_X86_SSA__Const)i2, (OOC_SymbolTable__Type)i0);
  return (OOC_X86_SSA__Result)i0;
  ;
}

OOC_X86_SSA__Result OOC_X86_SSA__BlockDesc_AddAdr(OOC_X86_SSA__Block b, OOC_X86_SSA__Global selector) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_X86_SSA__Instr instr;
  OOC_X86_SSA__Designator designator;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Instr.baseTypes[0]);
  OOC_X86_SSA__InstrDesc_INIT((OOC_X86_SSA__Instr)i0, 0);
  instr = (OOC_X86_SSA__Instr)i0;
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Designator.baseTypes[0], 1);
  designator = (OOC_X86_SSA__Designator)i1;
  i2 = _check_pointer(i1, 59740);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = (OOC_INT32)selector;
  *(OOC_INT32*)(i2+(_check_index(0, i3, OOC_UINT8, 59740))*4) = i4;
  OOC_X86_SSA__InstrDesc_SetDesignator((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Designator)i1);
  i1 = (OOC_INT32)b;
  OOC_X86_SSA__BlockDesc_Add((OOC_X86_SSA__Block)i1, (OOC_X86_SSA__Instr)i0);
  i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i0, 9);
  return (OOC_X86_SSA__Result)i0;
  ;
}

OOC_X86_SSA__Result OOC_X86_SSA__BlockDesc_AddAdrRT(OOC_X86_SSA__Block b, Object__String name) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_X86_SSA__Instr instr;
  OOC_X86_SSA__Designator designator;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Instr.baseTypes[0]);
  OOC_X86_SSA__InstrDesc_INIT((OOC_X86_SSA__Instr)i0, 0);
  instr = (OOC_X86_SSA__Instr)i0;
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Designator.baseTypes[0], 1);
  designator = (OOC_X86_SSA__Designator)i1;
  i2 = _check_pointer(i1, 60048);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = (OOC_INT32)name;
  i5 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__ProcName.baseTypes[0]);
  OOC_X86_SSA__ProcNameDesc_INIT((OOC_X86_SSA__ProcName)i5, (Object__String)i4);
  *(OOC_INT32*)(i2+(_check_index(0, i3, OOC_UINT8, 60048))*4) = i5;
  OOC_X86_SSA__InstrDesc_SetDesignator((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Designator)i1);
  i1 = (OOC_INT32)b;
  OOC_X86_SSA__BlockDesc_Add((OOC_X86_SSA__Block)i1, (OOC_X86_SSA__Instr)i0);
  i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i0, 9);
  return (OOC_X86_SSA__Result)i0;
  ;
}

OOC_X86_SSA__Result OOC_X86_SSA__BlockDesc_AddAdrTypeDescr(OOC_X86_SSA__Block b, OOC_SymbolTable__Type type) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_X86_SSA__Instr instr;
  OOC_X86_SSA__Designator designator;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Instr.baseTypes[0]);
  OOC_X86_SSA__InstrDesc_INIT((OOC_X86_SSA__Instr)i0, 0);
  instr = (OOC_X86_SSA__Instr)i0;
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Designator.baseTypes[0], 1);
  designator = (OOC_X86_SSA__Designator)i1;
  i2 = _check_pointer(i1, 60378);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = (OOC_INT32)type;
  i5 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__TypeDescr.baseTypes[0]);
  OOC_X86_SSA__TypeDescrDesc_INIT((OOC_X86_SSA__TypeDescr)i5, (OOC_SymbolTable__Type)i4);
  *(OOC_INT32*)(i2+(_check_index(0, i3, OOC_UINT8, 60378))*4) = i5;
  OOC_X86_SSA__InstrDesc_SetDesignator((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Designator)i1);
  i1 = (OOC_INT32)b;
  OOC_X86_SSA__BlockDesc_Add((OOC_X86_SSA__Block)i1, (OOC_X86_SSA__Instr)i0);
  i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i0, 9);
  return (OOC_X86_SSA__Result)i0;
  ;
}

OOC_X86_SSA__Result OOC_X86_SSA__BlockDesc_AddAdrModuleDescr(OOC_X86_SSA__Block b) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_X86_SSA__Instr instr;
  OOC_X86_SSA__Designator designator;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Instr.baseTypes[0]);
  OOC_X86_SSA__InstrDesc_INIT((OOC_X86_SSA__Instr)i0, 0);
  instr = (OOC_X86_SSA__Instr)i0;
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Designator.baseTypes[0], 1);
  designator = (OOC_X86_SSA__Designator)i1;
  i2 = _check_pointer(i1, 60704);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__ModuleDescr.baseTypes[0]);
  OOC_X86_SSA__ModuleDescrDesc_INIT((OOC_X86_SSA__ModuleDescr)i4);
  *(OOC_INT32*)(i2+(_check_index(0, i3, OOC_UINT8, 60704))*4) = i4;
  OOC_X86_SSA__InstrDesc_SetDesignator((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Designator)i1);
  i1 = (OOC_INT32)b;
  OOC_X86_SSA__BlockDesc_Add((OOC_X86_SSA__Block)i1, (OOC_X86_SSA__Instr)i0);
  i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i0, 9);
  return (OOC_X86_SSA__Result)i0;
  ;
}

OOC_X86_SSA__Result OOC_X86_SSA__BlockDesc_AddFramePointerOffset(OOC_X86_SSA__Block b, OOC_SymbolTable__VarDecl varDecl) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_X86_SSA__Instr instr;
  OOC_X86_SSA__Designator designator;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Instr.baseTypes[0]);
  OOC_X86_SSA__InstrDesc_INIT((OOC_X86_SSA__Instr)i0, 0);
  instr = (OOC_X86_SSA__Instr)i0;
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Designator.baseTypes[0], 1);
  designator = (OOC_X86_SSA__Designator)i1;
  i2 = _check_pointer(i1, 61052);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i4 = (OOC_INT32)varDecl;
  i5 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Var.baseTypes[0]);
  OOC_X86_SSA__VarDesc_INIT((OOC_X86_SSA__Var)i5, (OOC_SymbolTable__VarDecl)i4);
  *(OOC_INT32*)(i2+(_check_index(0, i3, OOC_UINT8, 61052))*4) = i5;
  OOC_X86_SSA__InstrDesc_SetDesignator((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Designator)i1);
  i1 = (OOC_INT32)b;
  OOC_X86_SSA__BlockDesc_Add((OOC_X86_SSA__Block)i1, (OOC_X86_SSA__Instr)i0);
  i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i0, 9);
  return (OOC_X86_SSA__Result)i0;
  ;
}

void OOC_X86_SSA__OpndDesc_InsertCopy(OOC_X86_SSA__Opnd opnd) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_X86_SSA__Instr opndInstr;
  OOC_X86_SSA__Instr instr;
  OOC_X86_SSA__Block b;

  i0 = (OOC_INT32)opnd;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 61316))+8);
  opndInstr = (OOC_X86_SSA__Instr)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 61346))+16);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 61373));
  i2 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr1((OOC_X86_SSA__Block)i2, 26, (OOC_X86_SSA__Result)i3);
  instr = (OOC_X86_SSA__Instr)i2;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 61420));
  i3 = *(OOC_INT8*)((_check_pointer(i3, 61424))+12);
  i3 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i2, i3);
  OOC_X86_SSA__OpndDesc_ReplaceArg((OOC_X86_SSA__Opnd)i0, (OOC_X86_SSA__Result)i3);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 61520))+16);
  b = (OOC_X86_SSA__Block)i0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 61552))+12);
  *(OOC_INT32*)((_check_pointer(i0, 61533))+52) = i3;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 61573))+12);
  *(OOC_INT32*)((_check_pointer(i3, 61583))+8) = 0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 61639))+12);
  *(OOC_INT32*)((_check_pointer(i2, 61616))+12) = i3;
  *(OOC_INT32*)((_check_pointer(i2, 61660))+8) = i1;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 61698))+12);
  i3 = i3==0;
  if (i3) goto l3;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 61769))+12);
  *(OOC_INT32*)((_check_pointer(i0, 61779))+8) = i2;
  goto l4;
l3:
  *(OOC_INT32*)((_check_pointer(i0, 61728))+48) = i2;
l4:
  *(OOC_INT32*)((_check_pointer(i1, 61822))+12) = i2;
  return;
  ;
}

void OOC_X86_SSA__BranchInstrDesc_INIT(OOC_X86_SSA__BranchInstr instr) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)instr;
  OOC_X86_SSA__BlockDesc_INIT((OOC_X86_SSA__Block)i0, 34);
  *(OOC_INT32*)((_check_pointer(i0, 61946))+56) = (OOC_INT32)0;
  return;
  ;
}

void OOC_X86_SSA__BranchInstrDesc_SetPaths2(OOC_X86_SSA__BranchInstr instr, OOC_X86_SSA__Block pathTrue, OOC_X86_SSA__Block pathFalse) {
  register OOC_INT32 i0,i1,i2,i3;
  Object__ObjectArrayPtr paths;

  i0 = (OOC_INT32)RT0__NewObject(_td_Object__ObjectArrayPtr.baseTypes[0], 2);
  paths = (Object__ObjectArrayPtr)i0;
  i1 = _check_pointer(i0, 62109);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i3 = (OOC_INT32)pathTrue;
  *(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 62109))*4) = i3;
  i1 = _check_pointer(i0, 62135);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i3 = (OOC_INT32)pathFalse;
  *(OOC_INT32*)(i1+(_check_index(1, i2, OOC_UINT8, 62135))*4) = i3;
  i1 = (OOC_INT32)instr;
  *(OOC_INT32*)((_check_pointer(i1, 62162))+56) = i0;
  return;
  ;
}

OOC_X86_SSA__BranchInstr OOC_X86_SSA__BlockDesc_AddBranch(OOC_X86_SSA__Block b, OOC_X86_SSA__Result select) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__BranchInstr.baseTypes[0]);
  OOC_X86_SSA__BranchInstrDesc_INIT((OOC_X86_SSA__BranchInstr)i0);
  i1 = (OOC_INT32)select;
  OOC_X86_SSA__InstrDesc_AddOpnd((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Result)i1);
  i1 = (OOC_INT32)b;
  OOC_X86_SSA__BlockDesc_Add((OOC_X86_SSA__Block)i1, (OOC_X86_SSA__Instr)i0);
  return (OOC_X86_SSA__BranchInstr)i0;
  ;
}

void OOC_X86_SSA__MergeInstrDesc_INIT(OOC_X86_SSA__MergeInstr instr, OOC_INT8 opcode, Object__ObjectArrayPtr jumps) {
  register OOC_INT32 i0,i1;

  i0 = opcode;
  i1 = (OOC_INT32)instr;
  OOC_X86_SSA__BlockDesc_INIT((OOC_X86_SSA__Block)i1, i0);
  i0 = (OOC_INT32)jumps;
  *(OOC_INT32*)((_check_pointer(i1, 62591))+56) = i0;
  return;
  ;
}

void OOC_X86_SSA__MergeInstrDesc_AddJump(OOC_X86_SSA__MergeInstr instr, OOC_X86_SSA__Instr jump) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  Object__ObjectArrayPtr _new;
  OOC_INT32 i;

  i0 = (OOC_INT32)instr;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 62737))+56);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l11;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 62808))+56);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 62814)), 0);
  i1 = (OOC_INT32)RT0__NewObject(_td_Object__ObjectArrayPtr.baseTypes[0], (i1+1));
  _new = (Object__ObjectArrayPtr)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 62850))+56);
  i = 0;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 62856)), 0);
  i3 = 0<i2;
  if (!i3) goto l12;
  i3=0;
l5_loop:
  i4 = _check_pointer(i1, 62875);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 62887))+56);
  i6 = _check_pointer(i6, 62893);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i3, i7, OOC_UINT32, 62893))*4);
  *(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 62875))*4) = i6;
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l5_loop;
  goto l12;
l11:
  i1 = (OOC_INT32)RT0__NewObject(_td_Object__ObjectArrayPtr.baseTypes[0], 1);
  _new = (Object__ObjectArrayPtr)i1;
  
l12:
  i2 = _check_pointer(i1, 62925);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i1, 62933)), 0);
  i4 = OOC_ARRAY_LENGTH(i2, 0);
  i5 = (OOC_INT32)jump;
  *(OOC_INT32*)(i2+(_check_index((i3-1), i4, OOC_UINT32, 62925))*4) = i5;
  *(OOC_INT32*)((_check_pointer(i0, 62957))+56) = i1;
  OOC_X86_SSA__InstrDesc_AddDep((OOC_X86_SSA__Instr)i0, 0, (OOC_X86_SSA__Instr)i5);
  return;
  ;
}

OOC_X86_SSA__MergeInstr OOC_X86_SSA__BlockDesc_AddMerge(OOC_X86_SSA__Block b, OOC_INT8 opcode, Object__ObjectArrayPtr jumps) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_X86_SSA__MergeInstr instr;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__MergeInstr.baseTypes[0]);
  i1 = (OOC_INT32)jumps;
  i2 = opcode;
  OOC_X86_SSA__MergeInstrDesc_INIT((OOC_X86_SSA__MergeInstr)i0, i2, (Object__ObjectArrayPtr)i1);
  instr = (OOC_X86_SSA__MergeInstr)i0;
  i2 = i1!=(OOC_INT32)0;
  if (!i2) goto l11;
  i1 = _check_pointer(i1, 63250);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i2 = i1+i2*4;
  i3 = i2!=i1;
  if (!i3) goto l11;
l5_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)i1;
  OOC_X86_SSA__InstrDesc_AddDep((OOC_X86_SSA__Instr)i0, 0, (OOC_X86_SSA__Instr)i3);
  i1 = i1+4;
  i3 = i2!=i1;
  if (i3) goto l5_loop;
l11:
  i1 = (OOC_INT32)b;
  OOC_X86_SSA__BlockDesc_Add((OOC_X86_SSA__Block)i1, (OOC_X86_SSA__Instr)i0);
  return (OOC_X86_SSA__MergeInstr)i0;
  ;
}

OOC_X86_SSA__MergeInstr OOC_X86_SSA__BlockDesc_AddMerge0(OOC_X86_SSA__Block b, OOC_INT8 opcode, OOC_X86_SSA__Result arg1) {
  register OOC_INT32 i0,i1,i2;

  i0 = opcode;
  i1 = (OOC_INT32)b;
  i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddMerge((OOC_X86_SSA__Block)i1, i0, (Object__ObjectArrayPtr)(OOC_INT32)0);
  i1 = (OOC_INT32)arg1;
  i2 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Opnd.baseTypes[0]);
  OOC_X86_SSA__OpndDesc_INIT((OOC_X86_SSA__Opnd)i2, (OOC_X86_SSA__Result)i1);
  OOC_X86_SSA__AddOpnd((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Opnd)i2);
  return (OOC_X86_SSA__MergeInstr)i0;
  ;
}

OOC_X86_SSA__MergeInstr OOC_X86_SSA__BlockDesc_AddMerge2(OOC_X86_SSA__Block b, OOC_INT8 opcode, OOC_X86_SSA__Instr jump1, OOC_X86_SSA__Instr jump2) {
  register OOC_INT32 i0,i1,i2,i3;
  Object__ObjectArrayPtr jumps;

  i0 = (OOC_INT32)RT0__NewObject(_td_Object__ObjectArrayPtr.baseTypes[0], 2);
  jumps = (Object__ObjectArrayPtr)i0;
  i1 = _check_pointer(i0, 63769);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i3 = (OOC_INT32)jump1;
  *(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 63769))*4) = i3;
  i1 = _check_pointer(i0, 63792);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i3 = (OOC_INT32)jump2;
  *(OOC_INT32*)(i1+(_check_index(1, i2, OOC_UINT8, 63792))*4) = i3;
  i1 = (OOC_INT32)b;
  i2 = opcode;
  i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddMerge((OOC_X86_SSA__Block)i1, i2, (Object__ObjectArrayPtr)i0);
  return (OOC_X86_SSA__MergeInstr)i0;
  ;
}

void OOC_X86_SSA__GateInstrDesc_INIT(OOC_X86_SSA__GateInstr instr, OOC_INT8 opcode, OOC_X86_SSA__Block merge) {
  register OOC_INT32 i0,i1;

  i0 = opcode;
  i1 = (OOC_INT32)instr;
  OOC_X86_SSA__InstrDesc_INIT((OOC_X86_SSA__Instr)i1, i0);
  i0 = (OOC_INT32)merge;
  *(OOC_INT32*)((_check_pointer(i1, 63972))+48) = i0;
  return;
  ;
}

OOC_X86_SSA__GateInstr OOC_X86_SSA__BlockDesc_AddGate(OOC_X86_SSA__Block b, OOC_INT8 opcode) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__GateInstr.baseTypes[0]);
  i1 = (OOC_INT32)b;
  i2 = opcode;
  OOC_X86_SSA__GateInstrDesc_INIT((OOC_X86_SSA__GateInstr)i0, i2, (OOC_X86_SSA__Block)i1);
  OOC_X86_SSA__BlockDesc_Add((OOC_X86_SSA__Block)i1, (OOC_X86_SSA__Instr)i0);
  return (OOC_X86_SSA__GateInstr)i0;
  ;
}

void OOC_X86_SSA__LoopStartInstrDesc_INIT(OOC_X86_SSA__LoopStartInstr instr) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)instr;
  OOC_X86_SSA__BlockDesc_INIT((OOC_X86_SSA__Block)i0, 40);
  *(OOC_INT32*)((_check_pointer(i0, 64278))+56) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i0, 64305))+60) = (OOC_INT32)0;
  return;
  ;
}

void OOC_X86_SSA__LoopStartInstrDesc_SetBackedge(OOC_X86_SSA__LoopStartInstr instr, OOC_X86_SSA__Instr backedge) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)instr;
  i1 = (OOC_INT32)backedge;
  *(OOC_INT32*)((_check_pointer(i0, 64413))+56) = i1;
  return;
  ;
}

void OOC_X86_SSA__LoopStartInstrDesc_SetEnd(OOC_X86_SSA__LoopStartInstr instr, OOC_X86_SSA__Instr end) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)instr;
  i1 = (OOC_INT32)end;
  *(OOC_INT32*)((_check_pointer(i0, 64528))+60) = i1;
  return;
  ;
}

OOC_X86_SSA__LoopStartInstr OOC_X86_SSA__BlockDesc_AddLoopStart(OOC_X86_SSA__Block b) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__LoopStartInstr.baseTypes[0]);
  OOC_X86_SSA__LoopStartInstrDesc_INIT((OOC_X86_SSA__LoopStartInstr)i0);
  i1 = (OOC_INT32)b;
  OOC_X86_SSA__BlockDesc_Add((OOC_X86_SSA__Block)i1, (OOC_X86_SSA__Instr)i0);
  return (OOC_X86_SSA__LoopStartInstr)i0;
  ;
}

void OOC_X86_SSA__LoopBackedgeInstrDesc_INIT(OOC_X86_SSA__LoopBackedgeInstr instr, OOC_X86_SSA__LoopStartInstr start) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)instr;
  OOC_X86_SSA__InstrDesc_INIT((OOC_X86_SSA__Instr)i0, 43);
  i1 = (OOC_INT32)start;
  *(OOC_INT32*)((_check_pointer(i0, 64859))+48) = i1;
  return;
  ;
}

OOC_X86_SSA__LoopBackedgeInstr OOC_X86_SSA__BlockDesc_AddLoopBackedge(OOC_X86_SSA__Block b, OOC_X86_SSA__LoopStartInstr start) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__LoopBackedgeInstr.baseTypes[0]);
  i1 = (OOC_INT32)start;
  OOC_X86_SSA__LoopBackedgeInstrDesc_INIT((OOC_X86_SSA__LoopBackedgeInstr)i0, (OOC_X86_SSA__LoopStartInstr)i1);
  i1 = (OOC_INT32)b;
  OOC_X86_SSA__BlockDesc_Add((OOC_X86_SSA__Block)i1, (OOC_X86_SSA__Instr)i0);
  return (OOC_X86_SSA__LoopBackedgeInstr)i0;
  ;
}

void OOC_X86_SSA__ExitInstrDesc_INIT(OOC_X86_SSA__ExitInstr instr, OOC_X86_SSA__Result sp, OOC_X86_SSA__Result fp, Object__ObjectArrayPtr returns) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)instr;
  OOC_X86_SSA__InstrDesc_INIT((OOC_X86_SSA__Instr)i0, 18);
  i1 = (OOC_INT32)returns;
  *(OOC_INT32*)((_check_pointer(i0, 65232))+48) = i1;
  i1 = (OOC_INT32)sp;
  i2 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Opnd.baseTypes[0]);
  OOC_X86_SSA__OpndDesc_INIT((OOC_X86_SSA__Opnd)i2, (OOC_X86_SSA__Result)i1);
  OOC_X86_SSA__AddOpnd((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Opnd)i2);
  i1 = (OOC_INT32)fp;
  i2 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__Opnd.baseTypes[0]);
  OOC_X86_SSA__OpndDesc_INIT((OOC_X86_SSA__Opnd)i2, (OOC_X86_SSA__Result)i1);
  OOC_X86_SSA__AddOpnd((OOC_X86_SSA__Instr)i0, (OOC_X86_SSA__Opnd)i2);
  return;
  ;
}

OOC_X86_SSA__ExitInstr OOC_X86_SSA__BlockDesc_AddExit(OOC_X86_SSA__Block b, OOC_X86_SSA__Result sp, OOC_X86_SSA__Result fp, Object__ObjectArrayPtr returns) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_X86_SSA__ExitInstr instr;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_X86_SSA__ExitInstr.baseTypes[0]);
  i1 = (OOC_INT32)returns;
  i2 = (OOC_INT32)fp;
  i3 = (OOC_INT32)sp;
  OOC_X86_SSA__ExitInstrDesc_INIT((OOC_X86_SSA__ExitInstr)i0, (OOC_X86_SSA__Result)i3, (OOC_X86_SSA__Result)i2, (Object__ObjectArrayPtr)i1);
  instr = (OOC_X86_SSA__ExitInstr)i0;
  i1 = _check_pointer(i1, 65534);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i2 = i1+i2*4;
  i3 = i2!=i1;
  if (!i3) goto l8;
l3_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)i1;
  OOC_X86_SSA__InstrDesc_AddDep((OOC_X86_SSA__Instr)i0, 0, (OOC_X86_SSA__Instr)i3);
  i1 = i1+4;
  i3 = i2!=i1;
  if (i3) goto l3_loop;
l8:
  i1 = (OOC_INT32)b;
  OOC_X86_SSA__BlockDesc_Add((OOC_X86_SSA__Block)i1, (OOC_X86_SSA__Instr)i0);
  return (OOC_X86_SSA__ExitInstr)i0;
  ;
}

void OOC_X86_SSA__BlockDesc_SetMarkers(OOC_X86_SSA__Block b, OOC_X86_SSA__Node newInfo, OOC_INT32 newMarker) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_X86_SSA__Instr instr;
  OOC_X86_SSA__Result res;

  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)newInfo;
  *(OOC_INT32*)((_check_pointer(i0, 65906))+40) = i1;
  i2 = newMarker;
  *(OOC_INT32*)((_check_pointer(i0, 65929))+44) = i2;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 65970))+48);
  instr = (OOC_X86_SSA__Instr)i0;
  i3 = i0!=(OOC_INT32)0;
  if (!i3) goto l20;
l3_loop:
  i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 66025)))), &_td_OOC_X86_SSA__BlockDesc);
  if (i3) goto l6;
  *(OOC_INT32*)((_check_pointer(i0, 66106))+40) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 66137))+44) = i2;
  goto l7;
l6:
  OOC_X86_SSA__BlockDesc_SetMarkers((OOC_X86_SSA__Block)i0, (OOC_X86_SSA__Node)i1, i2);
l7:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 66195))+4);
  res = (OOC_X86_SSA__Result)i3;
  i4 = i3!=(OOC_INT32)0;
  if (!i4) goto l15;
l10_loop:
  *(OOC_INT32*)((_check_pointer(i3, 66246))+20) = i1;
  *(OOC_INT32*)((_check_pointer(i3, 66275))+24) = i2;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 66315));
  res = (OOC_X86_SSA__Result)i3;
  i4 = i3!=(OOC_INT32)0;
  if (i4) goto l10_loop;
l15:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 66359))+8);
  instr = (OOC_X86_SSA__Instr)i0;
  i3 = i0!=(OOC_INT32)0;
  if (i3) goto l3_loop;
l20:
  return;
  ;
}

void OOC_X86_SSA__FunctionBlockDesc_INIT(OOC_X86_SSA__FunctionBlock b, OOC_SymbolTable__ProcDecl procDecl, OOC_CHAR8 checkFunctionResult) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)b;
  OOC_X86_SSA__BlockDesc_INIT((OOC_X86_SSA__Block)i0, 21);
  i1 = (OOC_INT32)procDecl;
  *(OOC_INT32*)((_check_pointer(i0, 66562))+56) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 66590))+60) = (OOC_INT32)0;
  *(OOC_INT32*)((_check_pointer(i0, 66610))+64) = (OOC_INT32)0;
  i1 = (OOC_INT32)ADT_Dictionary_IntValue__New();
  *(OOC_INT32*)((_check_pointer(i0, 66629))+68) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 66663))+72) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 66689))+76) = (-1);
  i1 = checkFunctionResult;
  *(OOC_UINT8*)((_check_pointer(i0, 66719))+80) = i1;
  return;
  ;
}

void OOC_X86_SSA__FunctionBlockDesc_SetEnter(OOC_X86_SSA__FunctionBlock b, OOC_X86_SSA__Instr enter) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)enter;
  *(OOC_INT32*)((_check_pointer(i0, 66844))+60) = i1;
  return;
  ;
}

void OOC_X86_SSA__FunctionBlockDesc_SetExit(OOC_X86_SSA__FunctionBlock b, OOC_X86_SSA__ExitInstr exit) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)exit;
  *(OOC_INT32*)((_check_pointer(i0, 66947))+64) = i1;
  return;
  ;
}

OOC_X86_SSA__Result OOC_X86_SSA__FunctionBlockDesc_FixType(OOC_X86_SSA__FunctionBlock b, OOC_X86_SSA__Result arg, OOC_INT8 type) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)arg;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 67260))+12);
  i2 = type;
  i1 = i1!=i2;
  if (i1) goto l3;
  return (OOC_X86_SSA__Result)i0;
  goto l12;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 67292))+4);
  i1 = *(OOC_INT8*)((_check_pointer(i1, 67298))+20);
  i1 = i1==0;
  if (i1) goto l6;
  i1=0u;
  goto l8;
l6:
  i1 = *(OOC_INT8*)((_check_pointer(i0, 67331))+12);
  i1 = (i1<10)==(i2<10);
  
l8:
  if (i1) goto l10;
  i1 = (OOC_INT32)b;
  i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr1((OOC_X86_SSA__Block)i1, 16, (OOC_X86_SSA__Result)i0);
  i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i0, i2);
  return (OOC_X86_SSA__Result)i0;
  goto l12;
l10:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 67404))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 67410))+28);
  i0 = _check_pointer(i0, 67421);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 67421))*4);
  i1 = (OOC_INT32)b;
  i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConstType((OOC_X86_SSA__Block)i1, (OOC_X86_SSA__Const)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 67425)))), &_td_OOC_X86_SSA__ConstDesc, 67425)), i2);
  return (OOC_X86_SSA__Result)i0;
l12:
  _failed_function(67007); return 0;
  ;
}

void OOC_X86_SSA__FunctionBlockDesc_AllocateLocalVar(OOC_X86_SSA__FunctionBlock b, OOC_SymbolTable__VarDecl varDecl) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 i;
  OOC_INT32 align;

  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 67713))+68);
  i2 = (OOC_INT32)varDecl;
  i1 = ADT_Dictionary_IntValue__DictionaryDesc_HasKey((ADT_Dictionary_IntValue__Dictionary)i1, (Object__Object)i2);
  i1 = !i1;
  if (!i1) goto l7;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 67757))+72);
  i = i1;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 67793))+48);
  i3 = *(OOC_INT32*)((_check_pointer(i3, 67798))+32);
  i1 = i1-i3;
  i = i1;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 67828))+48);
  i3 = *(OOC_INT16*)((_check_pointer(i3, 67833))+36);
  align = i3;
  i4 = _mod(i1,i3);
  i5 = i4!=0;
  if (!i5) goto l6;
  i1 = i1-(i3-i4);
  i = i1;
  
l6:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 67926))+68);
  ADT_Dictionary_IntValue__DictionaryDesc_Set((ADT_Dictionary_IntValue__Dictionary)i3, (Object__Object)i2, i1);
  *(OOC_INT32*)((_check_pointer(i0, 67961))+72) = i1;
l7:
  return;
  ;
}

void OOC_X86_SSA__FunctionBlockDesc_SetMaxSizeCallStack(OOC_X86_SSA__FunctionBlock b, OOC_INT32 size) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)b;
  i1 = size;
  *(OOC_INT32*)((_check_pointer(i0, 68095))+76) = i1;
  return;
  ;
}

OOC_INT32 OOC_X86_SSA__FunctionBlockDesc_Offset(OOC_X86_SSA__FunctionBlock b, OOC_SymbolTable__VarDecl varDecl) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_INT32 offset;
  OOC_SymbolTable__VarDecl p;
  OOC_SymbolTable__Type type;
  auto OOC_INT32 OOC_X86_SSA__FunctionBlockDesc_Offset_ArgumentSize(OOC_SymbolTable__Type type);
    
    OOC_INT32 OOC_X86_SSA__FunctionBlockDesc_Offset_ArgumentSize(OOC_SymbolTable__Type type) {

      return 4;
      ;
    }


  i0 = (OOC_INT32)varDecl;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l35;
  i1 = (OOC_INT32)b;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 68921))+68);
  i2 = ADT_Dictionary_IntValue__DictionaryDesc_HasKey((ADT_Dictionary_IntValue__Dictionary)i2, (Object__Object)i0);
  if (i2) goto l33;
  offset = 8;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 69093))+56);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 69102))+64);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 69113))+52);
  i1 = _check_pointer(i1, 69120);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i2 = i1+i2*4;
  i3 = i2!=i1;
  if (!i3) goto l32;
  i3=8;
l7_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)i1;
  p = (OOC_SymbolTable__VarDecl)i4;
  i5 = i4==i0;
  if (i5) goto l26;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 69212))+48);
  type = (OOC_SymbolTable__Type)i5;
  i6 = OOC_X86_SSA__FunctionBlockDesc_Offset_ArgumentSize((OOC_SymbolTable__Type)i5);
  i3 = i3+i6;
  offset = i3;
  i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 69281)))), &_td_OOC_SymbolTable__RecordDesc);
  if (i6) goto l16;
  i4 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 69438)))), &_td_OOC_SymbolTable__ArrayDesc);
  if (!i4) goto l27;
  i4 = OOC_SymbolTable__ArrayDesc_GetOpenDimensions((OOC_SymbolTable__Array)i5);
  i3 = i3+i4*4;
  offset = i3;
  
  goto l27;
l16:
  i4 = *(OOC_UINT8*)((_check_pointer(i4, 69313))+59);
  if (i4) goto l19;
  i4=0u;
  goto l21;
l19:
  i4 = *(OOC_UINT8*)((_check_pointer(i5, 69331))+58);
  
l21:
  if (!i4) goto l27;
  i3 = i3+4;
  offset = i3;
  
  goto l27;
l26:
  return i3;
  
l27:
  i1 = i1+4;
  i4 = i2!=i1;
  if (i4) goto l7_loop;
l32:
  _assert(0u, 127, 69649);
  goto l36;
l33:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 68967))+68);
  i0 = ADT_Dictionary_IntValue__DictionaryDesc_Get((ADT_Dictionary_IntValue__Dictionary)i1, (Object__Object)i0);
  return i0;
  goto l36;
l35:
  i0 = (OOC_INT32)b;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 68745))+72);
  i1 = _abs(i1);
  offset = i1;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 68776))+76);
  _assert((i2>=0), 127, 68768);
  i0 = *(OOC_INT32*)((_check_pointer(i0, 68820))+76);
  return (((((i1+i0)+4)-1)>>2)*4);
l36:
  _failed_function(68179); return 0;
  ;
}

OOC_X86_SSA__Result OOC_X86_SSA__FunctionBlockDesc_AddGetLengthInstr(OOC_X86_SSA__FunctionBlock b, OOC_X86_SSA__Instr getInstr, OOC_INT32 dim, OOC_SymbolTable__Array dimType) {
  register OOC_INT32 i0,i1,i2;
  OOC_X86_SSA__Result dimension;
  auto OOC_SymbolTable__VarDecl OOC_X86_SSA__FunctionBlockDesc_AddGetLengthInstr_VarParamArray(OOC_X86_SSA__Instr get);
    
    OOC_SymbolTable__VarDecl OOC_X86_SSA__FunctionBlockDesc_AddGetLengthInstr_VarParamArray(OOC_X86_SSA__Instr get) {
      register OOC_INT32 i0,i1,i2;

      i0 = (OOC_INT32)get;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 70382))+28);
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 70393)), 0);
      i1 = i1==1;
      if (i1) goto l3;
      i1=0u;
      goto l5;
l3:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 70416))+28);
      i1 = _check_pointer(i1, 70427);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 70427))*4);
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 70431)))), &_td_OOC_X86_SSA__VarDesc);
      
l5:
      if (i1) goto l7;
      i1=0u;
      goto l9;
l7:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 70453))+28);
      i1 = _check_pointer(i1, 70464);
      i2 = OOC_ARRAY_LENGTH(i1, 0);
      i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 70464))*4);
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 70468)))), &_td_OOC_X86_SSA__VarDesc, 70468)), 70472));
      i1 = *(OOC_UINT8*)((_check_pointer(i1, 70477))+56);
      
l9:
      if (i1) goto l11;
      return (OOC_SymbolTable__VarDecl)0;
      goto l12;
l11:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 70513))+28);
      i0 = _check_pointer(i0, 70524);
      i1 = OOC_ARRAY_LENGTH(i0, 0);
      i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 70524))*4);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 70528)))), &_td_OOC_X86_SSA__VarDesc, 70528)), 70532));
      return (OOC_SymbolTable__VarDecl)i0;
l12:
      _failed_function(70184); return 0;
      ;
    }


  i0 = (OOC_INT32)getInstr;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 70632))+20);
  _assert((i1==24), 127, 70617);
  i1 = (OOC_INT32)dimType;
  i2 = *(OOC_UINT8*)((_check_pointer(i1, 70662))+40);
  if (i2) goto l3;
  i0 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(6);
  i1 = *(OOC_INT32*)((_check_pointer(i1, 71021))+52);
  i1 = (OOC_INT32)Object_BigInt__NewInt(i1);
  i2 = (OOC_INT32)b;
  i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConstInt((OOC_X86_SSA__Block)i2, (Object_BigInt__BigInt)i1, (OOC_SymbolTable__Type)i0);
  return (OOC_X86_SSA__Result)i0;
  goto l8;
l3:
  i1 = dim;
  i2 = (OOC_INT32)b;
  i1 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddConstDim((OOC_X86_SSA__Block)i2, i1);
  dimension = (OOC_X86_SSA__Result)i1;
  i0 = (OOC_INT32)OOC_X86_SSA__FunctionBlockDesc_AddGetLengthInstr_VarParamArray((OOC_X86_SSA__Instr)i0);
  i0 = i0!=(OOC_INT32)0;
  if (i0) goto l6;
  i0=31;
  goto l7;
l6:
  i0=30;
l7:
  i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_AddInstr0((OOC_X86_SSA__Block)i2, i0);
  i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_AddResult((OOC_X86_SSA__Instr)i0, 3);
  return (OOC_X86_SSA__Result)i0;
l8:
  _failed_function(69717); return 0;
  ;
}

void OOC_X86_SSA__FunctionBlockDesc_DeadCodeElimination(OOC_X86_SSA__FunctionBlock fctBlock) {
  register OOC_INT32 i0;
  auto void OOC_X86_SSA__FunctionBlockDesc_DeadCodeElimination_MarkLive(OOC_X86_SSA__Instr instr);
  auto void OOC_X86_SSA__FunctionBlockDesc_DeadCodeElimination_RemoveDead(OOC_X86_SSA__Block b);
    
    void OOC_X86_SSA__FunctionBlockDesc_DeadCodeElimination_MarkLive(OOC_X86_SSA__Instr instr) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_X86_SSA__Opnd opnd;
      OOC_X86_SSA__Dep dep;

      i0 = (OOC_INT32)instr;
      i1 = *(OOC_INT32*)((_check_pointer(i0, 71333))+44);
      i1 = i1==0;
      if (!i1) goto l22;
      *(OOC_INT32*)((_check_pointer(i0, 71367))+44) = 1;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 71402)))), &_td_OOC_X86_SSA__LoopStartInstrDesc);
      if (!i1) goto l5;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 71446))+56);
      OOC_X86_SSA__FunctionBlockDesc_DeadCodeElimination_MarkLive((OOC_X86_SSA__Instr)i1);
l5:
      i1 = (OOC_INT32)OOC_X86_SSA__InstrDesc_Operands((OOC_X86_SSA__Instr)i0);
      i2 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i1)), OOC_X86_SSA__IterInstrOperandsDesc_Next);
      i3 = OOC_TBCALL(i2,OOC_X86_SSA__IterInstrOperandsDesc_Next)((OOC_X86_SSA__IterInstrOperands)i1, (void*)(OOC_INT32)&opnd);
      if (!i3) goto l13;
l8_loop:
      i3 = (OOC_INT32)opnd;
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 71571));
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 71575))+4);
      OOC_X86_SSA__FunctionBlockDesc_DeadCodeElimination_MarkLive((OOC_X86_SSA__Instr)i3);
      i3 = OOC_TBCALL(i2,OOC_X86_SSA__IterInstrOperandsDesc_Next)((OOC_X86_SSA__IterInstrOperands)i1, (void*)(OOC_INT32)&opnd);
      if (i3) goto l8_loop;
l13:
      i0 = (OOC_INT32)OOC_X86_SSA__InstrDesc_BeforeList((OOC_X86_SSA__Instr)i0, (-1));
      i1 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i0)), OOC_X86_SSA__IterInstrBeforeListDesc_Next);
      i2 = OOC_TBCALL(i1,OOC_X86_SSA__IterInstrBeforeListDesc_Next)((OOC_X86_SSA__IterInstrBeforeList)i0, (void*)(OOC_INT32)&dep);
      if (!i2) goto l22;
l16_loop:
      i2 = (OOC_INT32)dep;
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 71666));
      OOC_X86_SSA__FunctionBlockDesc_DeadCodeElimination_MarkLive((OOC_X86_SSA__Instr)i2);
      i2 = OOC_TBCALL(i1,OOC_X86_SSA__IterInstrBeforeListDesc_Next)((OOC_X86_SSA__IterInstrBeforeList)i0, (void*)(OOC_INT32)&dep);
      if (i2) goto l16_loop;
l22:
      return;
      ;
    }

    
    void OOC_X86_SSA__FunctionBlockDesc_DeadCodeElimination_RemoveDead(OOC_X86_SSA__Block b) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_X86_SSA__Instr instr;

      i0 = (OOC_INT32)b;
      i0 = (OOC_INT32)OOC_X86_SSA__BlockDesc_Instructions((OOC_X86_SSA__Block)i0);
      i1 = (OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG(i0)), OOC_X86_SSA__IterBlockInstructionsDesc_Next);
      i2 = OOC_TBCALL(i1,OOC_X86_SSA__IterBlockInstructionsDesc_Next)((OOC_X86_SSA__IterBlockInstructions)i0, (void*)(OOC_INT32)&instr);
      if (!i2) goto l14;
l3_loop:
      i2 = (OOC_INT32)instr;
      i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 71848)))), &_td_OOC_X86_SSA__BlockDesc);
      if (!i3) goto l6;
      OOC_X86_SSA__FunctionBlockDesc_DeadCodeElimination_RemoveDead((OOC_X86_SSA__Block)i2);
l6:
      i2 = (OOC_INT32)instr;
      i3 = *(OOC_INT32*)((_check_pointer(i2, 71955))+44);
      i3 = i3==0;
      if (!i3) goto l9;
      OOC_X86_SSA__InstrDesc_Delete((OOC_X86_SSA__Instr)i2);
l9:
      i2 = OOC_TBCALL(i1,OOC_X86_SSA__IterBlockInstructionsDesc_Next)((OOC_X86_SSA__IterBlockInstructions)i0, (void*)(OOC_INT32)&instr);
      if (i2) goto l3_loop;
l14:
      return;
      ;
    }


  i0 = (OOC_INT32)fctBlock;
  OOC_X86_SSA__BlockDesc_SetMarkers((OOC_X86_SSA__Block)i0, (OOC_X86_SSA__Node)(OOC_INT32)0, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 72247))+64);
  OOC_X86_SSA__FunctionBlockDesc_DeadCodeElimination_MarkLive((OOC_X86_SSA__Instr)i0);
  i0 = (OOC_INT32)fctBlock;
  OOC_X86_SSA__FunctionBlockDesc_DeadCodeElimination_RemoveDead((OOC_X86_SSA__Block)i0);
  return;
  ;
}

void OOC_OOC_X86_SSA_init(void) {

  return;
  ;
}

/* --- */
