#include <OOC/AST/CreateSymTab.d>
#include <__oo2c.h>
#include <setjmp.h>

OOC_SymbolTable__Name OOC_AST_CreateSymTab__GetName(OOC_AST__Node node) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_Scanner_SymList__Symbol sym;
  OOC_SymbolTable__Name name;

  i0 = (OOC_INT32)node;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2321)))), &_td_OOC_AST__TerminalDesc);
  if (i1) goto l7;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2372)))), &_td_OOC_AST__IdentDefDesc);
  if (i1) goto l5;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2366)))), 2366);
  goto l8;
l5:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2407));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2414));
  sym = (OOC_Scanner_SymList__Symbol)i0;
  goto l8;
l7:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2356));
  sym = (OOC_Scanner_SymList__Symbol)i0;
l8:
  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SymbolTable__Name.baseTypes[0]);
  name = (OOC_SymbolTable__Name)i0;
  i1 = (OOC_INT32)sym;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 2503))+24);
  i3 = *(OOC_INT32*)((_check_pointer(i1, 2492))+20);
  i4 = *(OOC_INT32*)((_check_pointer(i1, 2482))+16);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2472))+8);
  OOC_SymbolTable__InitName((OOC_SymbolTable__Name)i0, (OOC_Scanner_InputBuffer__CharArray)i1, i4, i3, i2);
  return (OOC_SymbolTable__Name)i0;
  ;
}

static OOC_SymbolTable__Position OOC_AST_CreateSymTab__GetPosition(OOC_AST__Node node) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_Scanner_SymList__Symbol sym;
  OOC_SymbolTable__Position position;

  i0 = (OOC_INT32)node;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2680)))), &_td_OOC_AST__TerminalDesc);
  if (i1) goto l11;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2731)))), &_td_OOC_AST__IdentDefDesc);
  if (i1) goto l9;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2789)))), &_td_OOC_AST__OperatorDesc);
  if (i1) goto l7;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2783)))), 2783);
  goto l12;
l7:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2824))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 2827));
  i1 = *(OOC_INT8*)((_check_pointer(i1, 2831))+4);
  _assert((i1==18), 127, 2813);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2870))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2881)))), &_td_OOC_AST__TerminalDesc, 2881)), 2890));
  sym = (OOC_Scanner_SymList__Symbol)i0;
  goto l12;
l9:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2766));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2773));
  sym = (OOC_Scanner_SymList__Symbol)i0;
  goto l12;
l11:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2715));
  sym = (OOC_Scanner_SymList__Symbol)i0;
l12:
  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SymbolTable__Position.baseTypes[0]);
  position = (OOC_SymbolTable__Position)i0;
  i1 = (OOC_INT32)sym;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 2960))+16);
  i3 = *(OOC_INT32*)((_check_pointer(i1, 2970))+20);
  i1 = *(OOC_INT32*)((_check_pointer(i1, 2981))+24);
  OOC_SymbolTable__InitPosition((OOC_SymbolTable__Position)i0, i2, i3, i1);
  return (OOC_SymbolTable__Position)i0;
  ;
}

static OOC_INT8 OOC_AST_CreateSymTab__ExportMark(OOC_AST__Node id) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)id;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3104)))), &_td_OOC_AST__IdentDefDesc);
  if (i1) goto l3;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3097)))), 3097);
  goto l12;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3134))+4);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l10;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3203))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3209));
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3214))+8);
  i0 = (
  _cmp8((const void*)(_check_pointer(i0, 3219)),(const void*)"*"))==0;
  if (i0) goto l8;
  return 2;
  goto l12;
l8:
  return 1;
  goto l12;
l10:
  return 0;
l12:
  _failed_function(3042); return 0;
  ;
}

static OOC_INT32 OOC_AST_CreateSymTab__EndOfType(OOC_AST__Node t) {
  register OOC_INT32 i0,i1,i2;
  OOC_INT32 end;

  i0 = (OOC_INT32)t;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l51;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3528)))), &_td_OOC_AST__TerminalDesc);
  if (i1) goto l49;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3594)))), &_td_OOC_AST__OperatorDesc);
  if (i1) goto l47;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3657)))), &_td_OOC_AST__ArrayTypeDesc);
  if (i1) goto l45;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3720)))), &_td_OOC_AST__RecordTypeDesc);
  if (i1) goto l43;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3783)))), &_td_OOC_AST__PointerTypeDesc);
  if (i1) goto l41;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3848)))), &_td_OOC_AST__ProcTypeDesc);
  if (i1) goto l31;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4149)))), &_td_OOC_AST__FormalParsDesc);
  if (i1) goto l21;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4372)))), &_td_OOC_AST__QualTypeDesc);
  if (i1) goto l19;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4369)))), 4369);
  goto l52;
l19:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4416))+12);
  i0 = OOC_AST_CreateSymTab__EndOfType((OOC_AST__Node)i0);
  return i0;
  goto l52;
l21:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4182))+20);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l28;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4258))+12);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l26;
  return (-1);
  goto l52;
l26:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4308))+12);
  i0 = OOC_AST_CreateSymTab__EndOfType((OOC_AST__Node)i0);
  return i0;
  goto l52;
l28:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4232))+20);
  i0 = OOC_AST_CreateSymTab__EndOfType((OOC_AST__Node)i0);
  return i0;
  goto l52;
l31:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3879))+4);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l34;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4115));
  i0 = OOC_AST_CreateSymTab__EndOfType((OOC_AST__Node)i0);
  return i0;
  goto l52;
l34:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3933))+4);
  i1 = OOC_AST_CreateSymTab__EndOfType((OOC_AST__Node)i1);
  end = i1;
  i2 = i1==(-1);
  if (i2) goto l37;
  return i1;
  goto l52;
l37:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4008));
  i0 = OOC_AST_CreateSymTab__EndOfType((OOC_AST__Node)i0);
  return i0;
  goto l52;
l41:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3831))+12);
  i0 = OOC_AST_CreateSymTab__EndOfType((OOC_AST__Node)i0);
  return i0;
  goto l52;
l43:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3767))+24);
  i0 = OOC_AST_CreateSymTab__EndOfType((OOC_AST__Node)i0);
  return i0;
  goto l52;
l45:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3703))+16);
  i0 = OOC_AST_CreateSymTab__EndOfType((OOC_AST__Node)i0);
  return i0;
  goto l52;
l47:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3639))+8);
  i0 = OOC_AST_CreateSymTab__EndOfType((OOC_AST__Node)i0);
  return i0;
  goto l52;
l49:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3562));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3574));
  i1 = *(OOC_INT32*)((_check_pointer(i1, 3567))+16);
  i0 = *(OOC_INT32*)((_check_pointer(i0, 3579))+12);
  return (i1+i0);
  goto l52;
l51:
  return (-1);
l52:
  _failed_function(3391); return 0;
  ;
}

static void OOC_AST_CreateSymTab__Accept(OOC_AST_CreateSymTab__Visitor v, OOC_AST__Node node) {
  register OOC_INT32 i0,i1,i2;
  OOC_SymbolTable__Item oldParent;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4566))+4);
  oldParent = (OOC_SymbolTable__Item)i1;
  i2 = (OOC_INT32)node;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 4584)))), OOC_AST__NodeDesc_Accept)),OOC_AST__NodeDesc_Accept)((OOC_AST__Node)i2, (OOC_AST__Visitor)i0);
  *(OOC_INT32*)((_check_pointer(i0, 4603))+4) = i1;
  return;
  ;
}

static void OOC_AST_CreateSymTab__AcceptParent(OOC_AST_CreateSymTab__Visitor v, OOC_AST__Node node, OOC_SymbolTable__Item newParent) {
  register OOC_INT32 i0,i1,i2;
  OOC_SymbolTable__Item oldParent;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4978))+4);
  oldParent = (OOC_SymbolTable__Item)i1;
  i2 = (OOC_INT32)newParent;
  *(OOC_INT32*)((_check_pointer(i0, 4993))+4) = i2;
  i2 = (OOC_INT32)node;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 5024)))), OOC_AST__NodeDesc_Accept)),OOC_AST__NodeDesc_Accept)((OOC_AST__Node)i2, (OOC_AST__Visitor)i0);
  *(OOC_INT32*)((_check_pointer(i0, 5043))+4) = i1;
  return;
  ;
}

static OOC_SymbolTable__Type OOC_AST_CreateSymTab__GetType(OOC_AST_CreateSymTab__Visitor v, OOC_AST__Node node) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  *(OOC_INT32*)((_check_pointer(i0, 5180))+8) = (OOC_INT32)0;
  i1 = (OOC_INT32)node;
  OOC_AST_CreateSymTab__Accept((OOC_AST_CreateSymTab__Visitor)i0, (OOC_AST__Node)i1);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5230))+8);
  _assert((i1!=(OOC_INT32)0), 127, 5221);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5255))+8);
  return (OOC_SymbolTable__Type)i0;
  ;
}

static OOC_SymbolTable__Type OOC_AST_CreateSymTab__GetTypeParent(OOC_AST_CreateSymTab__Visitor v, OOC_AST__Node node, OOC_SymbolTable__Item newParent) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)v;
  *(OOC_INT32*)((_check_pointer(i0, 5413))+8) = (OOC_INT32)0;
  i1 = (OOC_INT32)node;
  i2 = (OOC_INT32)newParent;
  OOC_AST_CreateSymTab__AcceptParent((OOC_AST_CreateSymTab__Visitor)i0, (OOC_AST__Node)i1, (OOC_SymbolTable__Item)i2);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5480))+8);
  _assert((i1!=(OOC_INT32)0), 127, 5471);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5505))+8);
  return (OOC_SymbolTable__Type)i0;
  ;
}

static void OOC_AST_CreateSymTab__AddFlags(OOC_SymbolTable__Item item, OOC_AST__Flags flags) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_AST__NodeList l;
  OOC_INT32 i;
  OOC_AST__Node n;

  i0 = (OOC_INT32)flags;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l15;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5713))+8);
  l = (OOC_AST__NodeList)i0;
  i = 0;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 5745));
  i2 = 0<i1;
  if (!i2) goto l15;
  i2 = (OOC_INT32)item;
  i3=0;
l5_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5775))+4);
  i4 = _check_pointer(i4, 5778);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 5778))*4);
  n = (OOC_AST__Node)i4;
  i5 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 5797)))), &_td_OOC_AST__TerminalDesc);
  if (i5) goto l8;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 5791)))), 5791);
  goto l9;
l8:
  i4 = (OOC_INT32)OOC_AST_CreateSymTab__GetName((OOC_AST__Node)i4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 5829)))), OOC_SymbolTable__ItemDesc_AddFlag)),OOC_SymbolTable__ItemDesc_AddFlag)((OOC_SymbolTable__Item)i2, (OOC_SymbolTable__Name)i4);
l9:
  i3 = i3+2;
  i = i3;
  i4 = i3<i1;
  if (i4) goto l5_loop;
l15:
  return;
  ;
}

void OOC_AST_CreateSymTab__VisitorDesc_VisitNodeList(OOC_AST_CreateSymTab__Visitor v, OOC_AST__NodeList nl) {

  _assert(0u, 127, 5973);
  
  ;
}

void OOC_AST_CreateSymTab__VisitorDesc_VisitModule(volatile OOC_AST_CreateSymTab__Visitor v, volatile OOC_AST__Module module) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11;
  volatile OOC_SymbolTable__Name moduleName;
  volatile OOC_AST__ModuleFlags mf;
  volatile OOC_INT8 _class;
  volatile OOC_INT8 callConv;
  volatile OOC_INT32 i;
  volatile OOC_AST__Node n;
  volatile Object__String str;
  volatile OOC_SymbolTable__Module moduleDecl;
  volatile OOC_SymbolTable__Name name;
  volatile URI__URI uri;
  volatile Object__String prefixOption;
  volatile Object__String suffixOption;
  volatile Object__StringArrayPtr depList;
  volatile OOC_INT32 j;
  jmp_buf _target0;
  Exception__Context _context0;

  i0 = (OOC_INT32)module;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6424))+4);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 6430));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6440))+4);
  i1 = _check_pointer(i1, 6443);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 6443))*4);
  i1 = (OOC_INT32)OOC_AST_CreateSymTab__GetName((OOC_AST__Node)i1);
  moduleName = (OOC_SymbolTable__Name)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6485))+28);
  i3 = *(OOC_INT32*)((_check_pointer(i1, 6564))+8);
  i4 = *(OOC_INT32*)((_check_pointer(i1, 6546))+4);
  i5 = *(OOC_INT32*)(_check_pointer(i1, 6509));
  OOC_SymbolTable__InitName((OOC_SymbolTable__Name)i1, (OOC_Scanner_InputBuffer__CharArray)i2, i5, i4, i3);
  mf = (OOC_AST__ModuleFlags)0;
  _class = 0;
  callConv = 0;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6675))+8);
  i3 = (OOC_INT32)v;
  i2 = i2!=0;
  if (i2) goto l3;
  i2=0;i4=0;i5=0;
  goto l28;
l3:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6721))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 6727))+8);
  i = 0;
  i2 = *(OOC_INT32*)(_check_pointer(i2, 6736));
  i4 = 0<i2;
  if (i4) goto l6;
  i2=0;i4=0;i5=0;
  goto l28;
l6:
  i4=0;i5=0;i6=0;i7=0;
l7_loop:
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6765))+8);
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i8, 6772))+8);
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i8, 6782))+4);
  i8 = _check_pointer(i8, 6785);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i8 = (OOC_INT32)*(OOC_INT32*)(i8+(_check_index(i4, i9, OOC_UINT32, 6785))*4);
  n = (OOC_AST__Node)i8;
  i9 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i8, 6804)))), &_td_OOC_AST__ModuleFlagsDesc);
  if (i9) goto l13;
  i9 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i8, 7205)))), &_td_OOC_AST__TerminalDesc);
  if (i9) goto l22;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i8, 7202)))), 7202);
  goto l22;
l13:
  mf = (OOC_AST__ModuleFlags)i8;
  i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i8, 6860));
  i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i6, 6870));
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 6875))+8);
  i6 = (
  _cmp8((const void*)(_check_pointer(i6, 6880)),(const void*)"FOREIGN"))==0;
  if (i6) goto l20;
  i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i8, 6954));
  i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i6, 6964));
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 6969))+8);
  i6 = (
  _cmp8((const void*)(_check_pointer(i6, 6974)),(const void*)"INTERFACE"))==0;
  if (!i6) goto l21;
  _class = 3;
  i5=3;
  goto l21;
l20:
  _class = 2;
  i5=2;
l21:
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i8, 7067))+4);
  i6 = (OOC_INT32)OOC_AST__TerminalDesc_GetString((OOC_AST__Terminal)i6, 1u);
  str = (Object__String)i6;
  i6 = OOC_SymbolTable__StringToCallConv((Object__String)i6);
  callConv = i6;
  i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 7158));
  i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 7158));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 7163)))), OOC_SymbolTable_Builder__BuilderDesc_SetClass)),OOC_SymbolTable_Builder__BuilderDesc_SetClass)((OOC_SymbolTable_Builder__Builder)i9, i5);
  i7=i8;
l22:
  i4 = i4+1;
  i = i4;
  i8 = i4<i2;
  if (i8) goto l7_loop;
l26:
  i2=i6;i4=i5;i5=i7;
l28:
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7333))+4);
  i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 7297));
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 7339))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 7297));
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 7302)))), OOC_SymbolTable_Builder__BuilderDesc_NewModule)),OOC_SymbolTable_Builder__BuilderDesc_NewModule)((OOC_SymbolTable_Builder__Builder)i3, (OOC_SymbolTable__Name)i1, (OOC_Doc__Document)i6, i4, i2, (OOC_AST__Node)i0);
  moduleDecl = (OOC_SymbolTable__Module)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7429))+8);
  i2 = i2!=0;
  if (!i2) goto l49;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7509))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7515))+8);
  i = 0;
  i2 = *(OOC_INT32*)(_check_pointer(i2, 7524));
  i3 = 0<i2;
  if (!i3) goto l49;
  i3=0;
l33_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7553))+8);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 7560))+8);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 7570))+4);
  i4 = _check_pointer(i4, 7573);
  i6 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i6, OOC_UINT32, 7573))*4);
  n = (OOC_AST__Node)i4;
  i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 7592)))), &_td_OOC_AST__TerminalDesc);
  if (!i6) goto l43;
  i6 = (OOC_INT32)OOC_AST_CreateSymTab__GetName((OOC_AST__Node)i4);
  name = (OOC_SymbolTable__Name)i6;
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 7669))+12);
  i7 = _check_pointer(i7, 7673);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = *(OOC_UINT8*)(i7+(_check_index(0, i8, OOC_UINT8, 7673)));
  i7 = (OOC_UINT8)65u<=(OOC_UINT8)(_cap(i7));
  if (i7) goto l38;
  i6=0u;
  goto l40;
l38:
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 7690))+12);
  i6 = _check_pointer(i6, 7694);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = *(OOC_UINT8*)(i6+(_check_index(0, i7, OOC_UINT8, 7694)));
  i6 = (OOC_UINT8)(_cap(i6))<=(OOC_UINT8)90u;
  
l40:
  if (!i6) goto l43;
  i4 = (OOC_INT32)OOC_AST_CreateSymTab__GetName((OOC_AST__Node)i4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7798)))), OOC_SymbolTable__ItemDesc_AddFlag)),OOC_SymbolTable__ItemDesc_AddFlag)((OOC_SymbolTable__Item)i1, (OOC_SymbolTable__Name)i4);
l43:
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l33_loop;
l49:
  i0 = i5!=0;
  if (i0) goto l52;
  i0=0u;
  goto l54;
l52:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 7927))+20);
  i0 = i0!=0;
  
l54:
  if (!i0) goto l118;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 7976))+20);
  i = 0;
  i0 = *(OOC_INT32*)(_check_pointer(i0, 7990));
  i1 = 0<i0;
  if (!i1) goto l118;
  i1=0;
l58_loop:
  i2 = (OOC_INT32)mf;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 8016))+20);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 8030))+4);
  i2 = _check_pointer(i2, 8033);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i1, i3, OOC_UINT32, 8033))*4);
  n = (OOC_AST__Node)i1;
  i2 = i1!=0;
  if (!i2) goto l112;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8106)))), &_td_OOC_AST__LinkFileFlagDesc);
  if (i2) goto l94;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8931)))), &_td_OOC_AST__LinkLibFlagDesc);
  if (!i2) goto l112;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8972))+4);
  i2 = (OOC_INT32)OOC_AST__TerminalDesc_GetString((OOC_AST__Terminal)i2, 1u);
  str = (Object__String)i2;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 9018))+24);
  i3 = i3!=0;
  if (i3) goto l67;
  prefixOption = (Object__String)0;
  i3=0;
  goto l68;
l67:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 9073))+24);
  i3 = (OOC_INT32)OOC_AST__TerminalDesc_GetString((OOC_AST__Terminal)i3, 0u);
  prefixOption = (Object__String)i3;
  
l68:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 9189))+32);
  i4 = i4!=0;
  if (i4) goto l71;
  suffixOption = (Object__String)0;
  i4=0;
  goto l72;
l71:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 9244))+32);
  i4 = (OOC_INT32)OOC_AST__TerminalDesc_GetString((OOC_AST__Terminal)i4, 0u);
  suffixOption = (Object__String)i4;
  
l72:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 9360))+12);
  i5 = i5==0;
  if (i5) goto l83;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 9465))+12);
  i5 = *(OOC_INT32*)(_check_pointer(i5, 9479));
  i5 = (OOC_INT32)RT0__NewObject(_td_Object__StringArrayPtr.baseTypes[0], ((i5>>1)+1));
  depList = (Object__StringArrayPtr)i5;
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 9524))+12);
  j = 0;
  i6 = *(OOC_INT32*)(_check_pointer(i6, 9538));
  i7 = 0<i6;
  if (!i7) goto l84;
  i7=0;
l77_loop:
  i8 = _check_pointer(i5, 9577);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i10 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 9591))+12);
  i10 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i10, 9605))+4);
  i10 = _check_pointer(i10, 9608);
  i11 = OOC_ARRAY_LENGTH(i10, 0);
  i10 = (OOC_INT32)*(OOC_INT32*)(i10+(_check_index(i7, i11, OOC_UINT32, 9608))*4);
  i10 = (OOC_INT32)OOC_AST__TerminalDesc_GetString((OOC_AST__Terminal)(_type_guard(i10, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i10, 9616)))), &_td_OOC_AST__TerminalDesc, 9616)), 1u);
  *(OOC_INT32*)(i8+(_check_index((i7>>1), i9, OOC_UINT32, 9577))*4) = i10;
  i7 = i7+2;
  j = i7;
  i8 = i7<i6;
  if (i8) goto l77_loop;
  goto l84;
l83:
  i5 = (OOC_INT32)RT0__NewObject(_td_Object__StringArrayPtr.baseTypes[0], 0);
  depList = (Object__StringArrayPtr)i5;
  
l84:
  i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 9697));
  i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i6, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 9706)))), &_td_OOC_AST__TerminalDesc, 9706)), 9715));
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 9719))+8);
  i6 = (
  _cmp8((const void*)(_check_pointer(i6, 9723)),(const void*)"LIB"))==0;
  if (i6) goto l91;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 9856));
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9865)))), &_td_OOC_AST__TerminalDesc, 9865)), 9874));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 9878))+8);
  i1 = (
  _cmp8((const void*)(_check_pointer(i1, 9882)),(const void*)"FRAMEWORK"))==0;
  if (i1) goto l89;
  _assert(0u, 127, 10108);
  goto l112;
l89:
  i1 = (OOC_INT32)moduleDecl;
  OOC_SymbolTable__ModuleDesc_AddLinkLib((OOC_SymbolTable__Module)i1, (Object__String)i2, (Object__StringArrayPtr)i5, (Object__String)i3, (Object__String)i4, 1);
  goto l112;
l91:
  i1 = (OOC_INT32)moduleDecl;
  OOC_SymbolTable__ModuleDesc_AddLinkLib((OOC_SymbolTable__Module)i1, (Object__String)i2, (Object__StringArrayPtr)i5, (Object__String)i3, (Object__String)i4, 0);
  goto l112;
l94:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8148))+4);
  i1 = (OOC_INT32)OOC_AST__TerminalDesc_GetString((OOC_AST__Terminal)i1, 1u);
  str = (Object__String)i1;
  {
    Exception__PushContext(&_context0, &_target0);
    if (!setjmp(_target0)) goto l101;
    Exception__PopContext(1);
    i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG(((OOC_INT32)Exception__Current()))), &_td_Exception__ParseErrorDesc);
    if (i1) goto l99;
    Exception__ActivateContext();
    goto l100;
l99:
    _assert(0u, 127, 8319);
l100:
    Exception__Clear();
    goto l102;
l101:
    i2 = (OOC_INT32)v;
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 8254))+16);
    i1 = (OOC_INT32)URI_Parser__NewURI((Object__String8)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8243)))), &_td_Object__String8Desc, 8243)), (URI__HierarchicalURI)i2);
    uri = (URI__URI)i1;
    Exception__PopContext(1);
l102:;
  }
  i1 = (OOC_INT32)uri;
  _assert((i1!=0), 127, 8363);
  i2 = (OOC_INT32)v;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 8422))+20);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8405)))), URI__URIDesc_MakeRelative)),URI__URIDesc_MakeRelative)((URI__URI)i1, (URI__HierarchicalURI)i2);
  uri = (URI__URI)i1;
  i2 = (OOC_INT32)n;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 8451))+12);
  i3 = i3!=0;
  if (i3) goto l105;
  prefixOption = (Object__String)0;
  i3=0;
  goto l106;
l105:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 8506))+12);
  i3 = (OOC_INT32)OOC_AST__TerminalDesc_GetString((OOC_AST__Terminal)i3, 0u);
  prefixOption = (Object__String)i3;
  
l106:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 8622))+20);
  i4 = i4!=0;
  if (i4) goto l109;
  suffixOption = (Object__String)0;
  i2=0;
  goto l110;
l109:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 8677))+20);
  i2 = (OOC_INT32)OOC_AST__TerminalDesc_GetString((OOC_AST__Terminal)i2, 0u);
  suffixOption = (Object__String)i2;
  
l110:
  i4 = (OOC_INT32)moduleDecl;
  OOC_SymbolTable__ModuleDesc_AddLinkFile((OOC_SymbolTable__Module)i4, (URI__HierarchicalURI)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8821)))), &_td_URI__HierarchicalURIDesc, 8821)), (Object__String)i3, (Object__String)i2);
l112:
  i1 = i;
  i1 = i1+1;
  i = i1;
  i2 = i1<i0;
  if (i2) goto l58_loop;
l118:
  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)moduleDecl;
  *(OOC_INT32*)((_check_pointer(i0, 10260))+12) = i1;
  i2 = (OOC_INT32)module;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 10296))+16);
  i3 = i3!=0;
  if (!i3) goto l121;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 10350))+16);
  OOC_AST_CreateSymTab__AcceptParent((OOC_AST_CreateSymTab__Visitor)i0, (OOC_AST__Node)i3, (OOC_SymbolTable__Item)i1);
l121:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 10399))+20);
  i3 = i3!=0;
  if (!i3) goto l124;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 10493))+20);
  OOC_AST_CreateSymTab__AcceptParent((OOC_AST_CreateSymTab__Visitor)i0, (OOC_AST__Node)i2, (OOC_SymbolTable__Item)i1);
l124:
  return;
  ;
}

void OOC_AST_CreateSymTab__VisitorDesc_VisitImportList(OOC_AST_CreateSymTab__Visitor v, OOC_AST__ImportList importList) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 i;

  i0 = (OOC_INT32)importList;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10670))+4);
  i = 0;
  i1 = *(OOC_INT32*)(_check_pointer(i1, 10679));
  i2 = 0<i1;
  if (!i2) goto l8;
  i2 = (OOC_INT32)v;
  i3=0;
l3_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10722))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 10731))+4);
  i4 = _check_pointer(i4, 10734);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 10734))*4);
  OOC_AST_CreateSymTab__Accept((OOC_AST_CreateSymTab__Visitor)i2, (OOC_AST__Node)i4);
  i3 = i3+2;
  i = i3;
  i4 = i3<i1;
  if (i4) goto l3_loop;
l8:
  return;
  ;
}

void OOC_AST_CreateSymTab__VisitorDesc_VisitBody(OOC_AST_CreateSymTab__Visitor v, OOC_AST__Body body) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 i;

  i0 = (OOC_INT32)body;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10875));
  i = 0;
  i1 = *(OOC_INT32*)(_check_pointer(i1, 10884));
  i2 = 0<i1;
  if (!i2) goto l11;
  i2 = (OOC_INT32)v;
  i3=0;
l3_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10910));
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 10919))+4);
  i4 = _check_pointer(i4, 10922);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 10922))*4);
  i4 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 10926)))), &_td_OOC_AST__TerminalDesc));
  if (!i4) goto l6;
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10971));
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 10980))+4);
  i4 = _check_pointer(i4, 10983);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 10983))*4);
  OOC_AST_CreateSymTab__Accept((OOC_AST_CreateSymTab__Visitor)i2, (OOC_AST__Node)i4);
l6:
  i3 = i3+1;
  i = i3;
  i4 = i3<i1;
  if (i4) goto l3_loop;
l11:
  return;
  ;
}

void OOC_AST_CreateSymTab__VisitorDesc_VisitImportDecl(OOC_AST_CreateSymTab__Visitor v, OOC_AST__ImportDecl importDecl) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  OOC_SymbolTable__Name moduleName;
  OOC_Scanner_SymList__Symbol nameSym;
  OOC_SymbolTable__Name name;

  i0 = (OOC_INT32)importDecl;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11281))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 11289));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11299))+4);
  i1 = _check_pointer(i1, 11302);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(0, i2, OOC_UINT8, 11302))*4);
  i1 = (OOC_INT32)OOC_AST_CreateSymTab__GetName((OOC_AST__Node)i1);
  moduleName = (OOC_SymbolTable__Name)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11348))+12);
  i3 = *(OOC_INT32*)((_check_pointer(i1, 11427))+8);
  i4 = *(OOC_INT32*)((_check_pointer(i1, 11409))+4);
  i5 = *(OOC_INT32*)(_check_pointer(i1, 11372));
  OOC_SymbolTable__InitName((OOC_SymbolTable__Name)i1, (OOC_Scanner_InputBuffer__CharArray)i2, i5, i4, i3);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11515))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 11523));
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 11533))+4);
  i2 = _check_pointer(i2, 11554);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11565))+8);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 11573));
  i3 = *(OOC_INT32*)(_check_pointer(i3, 11583));
  i4 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index((i3-1), i4, OOC_UINT32, 11554))*4);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 11596)))), &_td_OOC_AST__TerminalDesc, 11596)), 11605));
  nameSym = (OOC_Scanner_SymList__Symbol)i2;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11630))+4);
  i3 = i3!=0;
  if (i3) goto l3;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11736))+8);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 11744));
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 11754))+4);
  i3 = _check_pointer(i3, 11782);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11793))+8);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 11801));
  i4 = *(OOC_INT32*)(_check_pointer(i4, 11811));
  i5 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index((i4-1), i5, OOC_UINT32, 11782))*4);
  i3 = (OOC_INT32)OOC_AST_CreateSymTab__GetName((OOC_AST__Node)i3);
  name = (OOC_SymbolTable__Name)i3;
  
  goto l4;
l3:
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 11685));
  i3 = (OOC_INT32)OOC_AST_CreateSymTab__GetName((OOC_AST__Node)i3);
  name = (OOC_SymbolTable__Name)i3;
  
l4:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11955))+8);
  i4 = (OOC_INT32)v;
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 11850));
  i6 = *(OOC_INT32*)((_check_pointer(i2, 11892))+16);
  i2 = *(OOC_INT32*)((_check_pointer(i2, 11905))+12);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 11869))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11963))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 11850));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 11855)))), OOC_SymbolTable_Builder__BuilderDesc_NewImport)),OOC_SymbolTable_Builder__BuilderDesc_NewImport)((OOC_SymbolTable_Builder__Builder)i4, (OOC_SymbolTable__Item)i7, (OOC_SymbolTable__Name)i3, (i6+i2), (OOC_Doc__Document)i0, (OOC_SymbolTable__Name)i1);
  return;
  ;
}

void OOC_AST_CreateSymTab__VisitorDesc_VisitConstDecl(OOC_AST_CreateSymTab__Visitor v, OOC_AST__ConstDecl constDecl) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
  OOC_SymbolTable__ConstDecl _const;

  i0 = (OOC_INT32)constDecl;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 12317));
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 12295));
  i2 = OOC_AST_CreateSymTab__ExportMark((OOC_AST__Node)i2);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12229))+16);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 12245)))), &_td_OOC_AST__TerminalDesc, 12245)), 12254));
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 12192));
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12367))+12);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12327))+8);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 12202));
  i3 = *(OOC_INT32*)((_check_pointer(i3, 12259))+16);
  i4 = (OOC_INT32)OOC_AST_CreateSymTab__GetName((OOC_AST__Node)i4);
  i6 = (OOC_INT32)v;
  i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i6, 12133));
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 12164))+4);
  i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i6, 12133));
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 12138)))), OOC_SymbolTable_Builder__BuilderDesc_NewConstDecl)),OOC_SymbolTable_Builder__BuilderDesc_NewConstDecl)((OOC_SymbolTable_Builder__Builder)i6, (OOC_SymbolTable__Item)i8, (OOC_SymbolTable__Name)i4, i3, i2, (OOC_Doc__Document)i1, (Object_Boxed__Object)(OOC_INT32)0, (OOC_SymbolTable__PredefType)(OOC_INT32)0, (OOC_AST__Node)i5);
  _const = (OOC_SymbolTable__ConstDecl)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12393))+4);
  i2 = i2!=(OOC_INT32)0;
  if (!i2) goto l4;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12443))+4);
  OOC_AST_CreateSymTab__AddFlags((OOC_SymbolTable__Item)i1, (OOC_AST__Flags)i0);
l4:
  return;
  ;
}

void OOC_AST_CreateSymTab__VisitorDesc_VisitTPSection(OOC_AST_CreateSymTab__Visitor v, OOC_AST__TPSection tpSection) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10;
  OOC_SymbolTable__Type type;
  OOC_INT32 i;
  OOC_SymbolTable__TypeDecl typeDecl;

  i0 = (OOC_INT32)tpSection;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12662))+12);
  i2 = (OOC_INT32)v;
  i1 = (OOC_INT32)OOC_AST_CreateSymTab__GetType((OOC_AST_CreateSymTab__Visitor)i2, (OOC_AST__Node)i1);
  type = (OOC_SymbolTable__Type)i1;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12697))+4);
  i = 0;
  i3 = *(OOC_INT32*)(_check_pointer(i3, 12707));
  i4 = 0<i3;
  if (!i4) goto l8;
  i4=0;
l3_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12893))+4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 12903))+4);
  i5 = _check_pointer(i5, 12905);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 12905))*4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i5, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 12913)))), &_td_OOC_AST__IdentDefDesc, 12913)), 12922))+8);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12844))+12);
  i6 = OOC_AST_CreateSymTab__EndOfType((OOC_AST__Node)i6);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12796))+4);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i7, 12806))+4);
  i7 = _check_pointer(i7, 12808);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i4, i8, OOC_UINT32, 12808))*4);
  i7 = (OOC_INT32)OOC_AST_CreateSymTab__GetName((OOC_AST__Node)i7);
  i8 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 12741));
  i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 12770))+4);
  i10 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 12741));
  i5 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i8, 12745)))), OOC_SymbolTable_Builder__BuilderDesc_NewTypeDecl)),OOC_SymbolTable_Builder__BuilderDesc_NewTypeDecl)((OOC_SymbolTable_Builder__Builder)i10, (OOC_SymbolTable__Item)i9, (OOC_SymbolTable__Name)i7, i6, 0, (OOC_Doc__Document)i5, (OOC_SymbolTable__Type)i1, 1u);
  typeDecl = (OOC_SymbolTable__TypeDecl)i5;
  i4 = i4+2;
  i = i4;
  i5 = i4<i3;
  if (i5) goto l3_loop;
l8:
  return;
  ;
}

void OOC_AST_CreateSymTab__VisitorDesc_VisitTypeDecl(OOC_AST_CreateSymTab__Visitor v, OOC_AST__TypeDecl typeDecl) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
  OOC_SymbolTable__Type base;
  OOC_SymbolTable__TypePars typePars;
  OOC_INT32 i;
  OOC_SymbolTable__TypeDecl type;

  i0 = (OOC_INT32)typeDecl;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13161))+8);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l11;
  i1 = (OOC_INT32)v;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 13252));
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 13270))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 13252));
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 13256)))), OOC_SymbolTable_Builder__BuilderDesc_NewTypePars)),OOC_SymbolTable_Builder__BuilderDesc_NewTypePars)((OOC_SymbolTable_Builder__Builder)i4, (OOC_SymbolTable__Item)i3);
  typePars = (OOC_SymbolTable__TypePars)i2;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13308))+8);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 13317))+4);
  i = 0;
  i3 = *(OOC_INT32*)(_check_pointer(i3, 13328));
  i4 = 0<i3;
  if (!i4) goto l10;
  i4=0;
l5_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13375))+8);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 13384))+4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 13395))+4);
  i5 = _check_pointer(i5, 13397);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 13397))*4);
  OOC_AST_CreateSymTab__AcceptParent((OOC_AST_CreateSymTab__Visitor)i1, (OOC_AST__Node)i5, (OOC_SymbolTable__Item)i2);
  i4 = i4+2;
  i = i4;
  i5 = i4<i3;
  if (i5) goto l5_loop;
l10:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13463))+16);
  i3 = (OOC_INT32)OOC_AST_CreateSymTab__GetTypeParent((OOC_AST_CreateSymTab__Visitor)i1, (OOC_AST__Node)i3, (OOC_SymbolTable__Item)i2);
  base = (OOC_SymbolTable__Type)i3;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 13498))+24);
  _assert((i4==(OOC_INT32)0), 127, 13487);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 13528)))), OOC_SymbolTable__TypeDesc_SetTypePars)),OOC_SymbolTable__TypeDesc_SetTypePars)((OOC_SymbolTable__Type)i3, (OOC_SymbolTable__TypePars)i2);
  i2=i1;i1=i3;
  goto l12;
l11:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13216))+16);
  i2 = (OOC_INT32)v;
  i1 = (OOC_INT32)OOC_AST_CreateSymTab__GetType((OOC_AST_CreateSymTab__Visitor)i2, (OOC_AST__Node)i1);
  base = (OOC_SymbolTable__Type)i1;
  
l12:
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13730));
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13700));
  i4 = OOC_AST_CreateSymTab__ExportMark((OOC_AST__Node)i4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 13739))+8);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13673))+16);
  i5 = OOC_AST_CreateSymTab__EndOfType((OOC_AST__Node)i5);
  i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13628));
  i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i6, 13637));
  i6 = (OOC_INT32)OOC_AST_CreateSymTab__GetName((OOC_AST__Node)i6);
  i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 13574));
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 13603))+4);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 13574));
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 13579)))), OOC_SymbolTable_Builder__BuilderDesc_NewTypeDecl)),OOC_SymbolTable_Builder__BuilderDesc_NewTypeDecl)((OOC_SymbolTable_Builder__Builder)i2, (OOC_SymbolTable__Item)i8, (OOC_SymbolTable__Name)i6, i5, i4, (OOC_Doc__Document)i3, (OOC_SymbolTable__Type)i1, 0u);
  type = (OOC_SymbolTable__TypeDecl)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13781))+4);
  i2 = i2!=(OOC_INT32)0;
  if (!i2) goto l15;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13829))+4);
  OOC_AST_CreateSymTab__AddFlags((OOC_SymbolTable__Item)i1, (OOC_AST__Flags)i0);
l15:
  return;
  ;
}

void OOC_AST_CreateSymTab__VisitorDesc_VisitVarDecl(OOC_AST_CreateSymTab__Visitor v, OOC_AST__VarDecl varDecl) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11;
  OOC_SymbolTable__Type type;
  OOC_INT32 i;
  OOC_SymbolTable__VarDecl var;
  OOC_AST__Node flags;

  i0 = (OOC_INT32)varDecl;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14054))+8);
  i2 = (OOC_INT32)v;
  i1 = (OOC_INT32)OOC_AST_CreateSymTab__GetType((OOC_AST_CreateSymTab__Visitor)i2, (OOC_AST__Node)i1);
  type = (OOC_SymbolTable__Type)i1;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14088));
  i = 0;
  i3 = *(OOC_INT32*)(_check_pointer(i3, 14099));
  i4 = 0<i3;
  if (!i4) goto l11;
  i4=0;
l3_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14322));
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 14333))+4);
  i5 = _check_pointer(i5, 14336);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 14336))*4);
  i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14286));
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 14297))+4);
  i6 = _check_pointer(i6, 14300);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i4, i7, OOC_UINT32, 14300))*4);
  i6 = OOC_AST_CreateSymTab__ExportMark((OOC_AST__Node)i6);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i5, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 14344)))), &_td_OOC_AST__IdentDefDesc, 14344)), 14353))+8);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14250))+8);
  i7 = OOC_AST_CreateSymTab__EndOfType((OOC_AST__Node)i7);
  i8 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14183));
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i8, 14194))+4);
  i8 = _check_pointer(i8, 14197);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i8 = (OOC_INT32)*(OOC_INT32*)(i8+(_check_index(i4, i9, OOC_UINT32, 14197))*4);
  i8 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i8, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i8, 14205)))), &_td_OOC_AST__IdentDefDesc, 14205)), 14214));
  i8 = (OOC_INT32)OOC_AST_CreateSymTab__GetName((OOC_AST__Node)i8);
  i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 14129));
  i10 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14149))+4);
  i11 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 14129));
  i5 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i9, 14134)))), OOC_SymbolTable_Builder__BuilderDesc_NewVarDecl)),OOC_SymbolTable_Builder__BuilderDesc_NewVarDecl)((OOC_SymbolTable_Builder__Builder)i11, (OOC_SymbolTable__Item)i10, (OOC_SymbolTable__Name)i8, i7, i6, (OOC_Doc__Document)i5, 0u, 0u, 0u, (OOC_SymbolTable__Type)i1);
  var = (OOC_SymbolTable__VarDecl)i5;
  i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14424));
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 14435))+4);
  i6 = _check_pointer(i6, 14438);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index((i4+1), i7, OOC_UINT32, 14438))*4);
  flags = (OOC_AST__Node)i6;
  i7 = i6!=0;
  if (!i7) goto l6;
  OOC_AST_CreateSymTab__AddFlags((OOC_SymbolTable__Item)i5, (OOC_AST__Flags)(_type_guard(i6, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 14505)))), &_td_OOC_AST__FlagsDesc, 14505)));
l6:
  i4 = i4+3;
  i = i4;
  i5 = i4<i3;
  if (i5) goto l3_loop;
l11:
  return;
  ;
}

void OOC_AST_CreateSymTab__VisitorDesc_VisitReceiver(OOC_AST_CreateSymTab__Visitor v, OOC_AST__Receiver receiver) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9;
  OOC_SymbolTable__Type type;
  OOC_SymbolTable__VarDecl var;
  OOC_AST__NodeArray nodes;
  OOC_INT32 i;
  OOC_SymbolTable__TypeDecl alias;

  i0 = (OOC_INT32)receiver;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14773))+16);
  i2 = (OOC_INT32)v;
  i1 = (OOC_INT32)OOC_AST_CreateSymTab__GetType((OOC_AST_CreateSymTab__Visitor)i2, (OOC_AST__Node)i1);
  type = (OOC_SymbolTable__Type)i1;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14921))+8);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14967))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 14928))+8);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14877))+16);
  i5 = OOC_AST_CreateSymTab__EndOfType((OOC_AST__Node)i5);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14848))+8);
  i6 = (OOC_INT32)OOC_AST_CreateSymTab__GetName((OOC_AST__Node)i6);
  i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 14794));
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 14814))+4);
  i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 14794));
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 14799)))), OOC_SymbolTable_Builder__BuilderDesc_NewVarDecl)),OOC_SymbolTable_Builder__BuilderDesc_NewVarDecl)((OOC_SymbolTable_Builder__Builder)i9, (OOC_SymbolTable__Item)i8, (OOC_SymbolTable__Name)i6, i5, 0, (OOC_Doc__Document)i3, 1u, 1u, (i4!=(OOC_INT32)0), (OOC_SymbolTable__Type)i1);
  var = (OOC_SymbolTable__VarDecl)i1;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15004))+20);
  i3 = i3!=(OOC_INT32)0;
  if (!i3) goto l11;
  *(OOC_UINT8*)((_check_pointer(i1, 15038))+58) = 1u;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15084))+24);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15094))+4);
  nodes = (OOC_AST__NodeArray)i1;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15126))+24);
  i = 0;
  i0 = *(OOC_INT32*)(_check_pointer(i0, 15136));
  i3 = 0<i0;
  if (!i3) goto l11;
  i3=0;
l5_loop:
  i4 = _check_pointer(i1, 15243);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 15243))*4);
  i4 = OOC_AST_CreateSymTab__EndOfType((OOC_AST__Node)i4);
  i5 = _check_pointer(i1, 15222);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 15222))*4);
  i5 = (OOC_INT32)OOC_AST_CreateSymTab__GetName((OOC_AST__Node)i5);
  i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 15169));
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 15200))+4);
  i8 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 15169));
  i4 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 15173)))), OOC_SymbolTable_Builder__BuilderDesc_NewTypeDecl)),OOC_SymbolTable_Builder__BuilderDesc_NewTypeDecl)((OOC_SymbolTable_Builder__Builder)i8, (OOC_SymbolTable__Item)i7, (OOC_SymbolTable__Name)i5, i4, 0, (OOC_Doc__Document)(OOC_INT32)0, (OOC_SymbolTable__Type)(OOC_INT32)0, 0u);
  alias = (OOC_SymbolTable__TypeDecl)i4;
  i3 = i3+2;
  i = i3;
  i4 = i3<i0;
  if (i4) goto l5_loop;
l11:
  return;
  ;
}

void OOC_AST_CreateSymTab__VisitorDesc_VisitFPSection(OOC_AST_CreateSymTab__Visitor v, OOC_AST__FPSection fpSection) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11;
  OOC_SymbolTable__Type type;
  OOC_INT32 i;
  OOC_SymbolTable__VarDecl var;
  OOC_AST__Node flags;

  i0 = (OOC_INT32)fpSection;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15536))+12);
  i2 = (OOC_INT32)v;
  i1 = (OOC_INT32)OOC_AST_CreateSymTab__GetType((OOC_AST_CreateSymTab__Visitor)i2, (OOC_AST__Node)i1);
  type = (OOC_SymbolTable__Type)i1;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15572))+4);
  i = 0;
  i3 = *(OOC_INT32*)(_check_pointer(i3, 15583));
  i4 = 0<i3;
  if (!i4) goto l11;
  i4=0;
l3_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15764))+4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 15775))+4);
  i5 = _check_pointer(i5, 15778);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 15778))*4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i5, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 15786)))), &_td_OOC_AST__IdentDefDesc, 15786)), 15795))+8);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15717))+12);
  i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 15838));
  i6 = OOC_AST_CreateSymTab__EndOfType((OOC_AST__Node)i6);
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15669))+4);
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i8, 15680))+4);
  i8 = _check_pointer(i8, 15683);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i8 = (OOC_INT32)*(OOC_INT32*)(i8+(_check_index(i4, i9, OOC_UINT32, 15683))*4);
  i8 = (OOC_INT32)OOC_AST_CreateSymTab__GetName((OOC_AST__Node)i8);
  i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 15613));
  i10 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 15633))+4);
  i11 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 15613));
  i5 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i9, 15618)))), OOC_SymbolTable_Builder__BuilderDesc_NewVarDecl)),OOC_SymbolTable_Builder__BuilderDesc_NewVarDecl)((OOC_SymbolTable_Builder__Builder)i11, (OOC_SymbolTable__Item)i10, (OOC_SymbolTable__Name)i8, i6, 0, (OOC_Doc__Document)i5, 1u, 0u, (i7!=0), (OOC_SymbolTable__Type)i1);
  var = (OOC_SymbolTable__VarDecl)i5;
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15882))+4);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 15893))+4);
  i6 = _check_pointer(i6, 15896);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index((i4+1), i7, OOC_UINT32, 15896))*4);
  flags = (OOC_AST__Node)i6;
  i7 = i6!=0;
  if (!i7) goto l6;
  OOC_AST_CreateSymTab__AddFlags((OOC_SymbolTable__Item)i5, (OOC_AST__Flags)(_type_guard(i6, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 15963)))), &_td_OOC_AST__FlagsDesc, 15963)));
l6:
  i4 = i4+3;
  i = i4;
  i5 = i4<i3;
  if (i5) goto l3_loop;
l11:
  return;
  ;
}

static void OOC_AST_CreateSymTab__ParseFormalParsFlags(OOC_SymbolTable__FormalPars fpars, OOC_AST__NodeList flags) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 i;
  OOC_AST__Node n;

  i0 = (OOC_INT32)flags;
  i = 0;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 16173));
  i2 = 0<i1;
  if (!i2) goto l16;
  i2 = (OOC_INT32)fpars;
  i3=0;
l3_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16207))+4);
  i4 = _check_pointer(i4, 16210);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 16210))*4);
  n = (OOC_AST__Node)i4;
  i5 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 16229)))), &_td_OOC_AST__TerminalDesc);
  if (i5) goto l6;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 16223)))), 16223);
  goto l11;
l6:
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 16263));
  i5 = *(OOC_INT8*)((_check_pointer(i5, 16267))+4);
  switch (i5) {
  case 43:
  case 44:
    i4 = (OOC_INT32)OOC_AST__TerminalDesc_GetString((OOC_AST__Terminal)i4, 1u);
    i4 = OOC_SymbolTable__StringToCallConv((Object__String)i4);
    *(OOC_INT8*)((_check_pointer(i2, 16345))+58) = i4;
    goto l11;
  default:
    i4 = (OOC_INT32)OOC_AST_CreateSymTab__GetName((OOC_AST__Node)i4);
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 16434)))), OOC_SymbolTable__ItemDesc_AddFlag)),OOC_SymbolTable__ItemDesc_AddFlag)((OOC_SymbolTable__Item)i2, (OOC_SymbolTable__Name)i4);
    goto l11;
  }
l11:
  i3 = i3+2;
  i = i3;
  i4 = i3<i1;
  if (i4) goto l3_loop;
l16:
  return;
  ;
}

void OOC_AST_CreateSymTab__VisitorDesc_VisitProcDecl(OOC_AST_CreateSymTab__Visitor v, OOC_AST__ProcDecl procDecl) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11;
  OOC_INT32 endPos;
  OOC_INT8 procClass;
  OOC_SymbolTable__ProcDecl proc;
  OOC_SymbolTable__FormalPars formalPars;
  OOC_AST__FormalPars fpar;
  OOC_INT32 i;
  OOC_AST__Node nodePtr;
  OOC_SymbolTable__Type type;
  auto void OOC_AST_CreateSymTab__VisitorDesc_VisitProcDecl_ParseProcDeclFlags(OOC_SymbolTable__ProcDecl proc, OOC_AST__NodeList flags);
    
    void OOC_AST_CreateSymTab__VisitorDesc_VisitProcDecl_ParseProcDeclFlags(OOC_SymbolTable__ProcDecl proc, OOC_AST__NodeList flags) {
      register OOC_INT32 i0,i1,i2,i3,i4,i5;
      OOC_INT32 i;
      OOC_AST__Node n;

      i0 = (OOC_INT32)flags;
      i = 0;
      i1 = *(OOC_INT32*)(_check_pointer(i0, 16945));
      i2 = 0<i1;
      if (!i2) goto l16;
      i2 = (OOC_INT32)proc;
      i3=0;
l3_loop:
      i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16979))+4);
      i4 = _check_pointer(i4, 16982);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 16982))*4);
      n = (OOC_AST__Node)i4;
      i5 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 17001)))), &_td_OOC_AST__TerminalDesc);
      if (i5) goto l6;
      _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 16995)))), 16995);
      goto l11;
l6:
      i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 17035));
      i5 = *(OOC_INT8*)((_check_pointer(i5, 17039))+4);
      switch (i5) {
      case 43:
      case 44:
        i4 = (OOC_INT32)OOC_AST__TerminalDesc_GetString((OOC_AST__Terminal)i4, 1u);
        OOC_SymbolTable__ProcDeclDesc_SetLinkName((OOC_SymbolTable__ProcDecl)i2, (Object__String)i4);
        goto l11;
      default:
        i4 = (OOC_INT32)OOC_AST_CreateSymTab__GetName((OOC_AST__Node)i4);
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 17184)))), OOC_SymbolTable__ItemDesc_AddFlag)),OOC_SymbolTable__ItemDesc_AddFlag)((OOC_SymbolTable__Item)i2, (OOC_SymbolTable__Name)i4);
        goto l11;
      }
l11:
      i3 = i3+2;
      i = i3;
      i4 = i3<i1;
      if (i4) goto l3_loop;
l16:
      return;
      ;
    }


  i0 = (OOC_INT32)procDecl;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17318))+20);
  i1 = OOC_AST_CreateSymTab__EndOfType((OOC_AST__Node)i1);
  endPos = i1;
  i2 = i1<0;
  if (!i2) goto l4;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17393))+16);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 17403));
  i1 = OOC_AST_CreateSymTab__EndOfType((OOC_AST__Node)i1);
  endPos = i1;
  
l4:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17438))+8);
  i2 = i2==0;
  if (i2) goto l11;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17537))+16);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 17546));
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 17552));
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 17556))+8);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17537))+16);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 17546));
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 17552));
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 17556))+8);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 17560)), 0);
  i2 = OOC_SymbolTable_Predef__IsStaticMethod((void*)(_check_pointer(i3, 17560)), i2);
  if (i2) goto l9;
  procClass = 1;
  i2=1;
  goto l12;
l9:
  procClass = 2;
  i2=2;
  goto l12;
l11:
  procClass = 0;
  i2=0;
l12:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17810))+16);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17783))+16);
  i4 = OOC_AST_CreateSymTab__ExportMark((OOC_AST__Node)i4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17729))+16);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17858))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 17820))+8);
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i5, 17739));
  i5 = (OOC_INT32)OOC_AST_CreateSymTab__GetName((OOC_AST__Node)i5);
  i7 = (OOC_INT32)v;
  i8 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i7, 17674));
  i9 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i7, 17695))+4);
  i10 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i7, 17674));
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i8, 17679)))), OOC_SymbolTable_Builder__BuilderDesc_NewProcDecl)),OOC_SymbolTable_Builder__BuilderDesc_NewProcDecl)((OOC_SymbolTable_Builder__Builder)i10, (OOC_SymbolTable__Item)i9, (OOC_SymbolTable__Name)i5, i1, i4, (OOC_Doc__Document)i3, i2, (i6!=0), (OOC_AST__Node)i0);
  proc = (OOC_SymbolTable__ProcDecl)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 17998));
  i2 = (OOC_INT32)OOC_AST_CreateSymTab__GetPosition((OOC_AST__Node)i2);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i7, 17908));
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i7, 17908));
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 17913)))), OOC_SymbolTable_Builder__BuilderDesc_NewFormalPars)),OOC_SymbolTable_Builder__BuilderDesc_NewFormalPars)((OOC_SymbolTable_Builder__Builder)i4, (OOC_SymbolTable__Item)i1, (OOC_SymbolTable__Position)i2);
  formalPars = (OOC_SymbolTable__FormalPars)i2;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18024))+20);
  i3 = i3!=0;
  if (i3) goto l15;
  i3=0u;
  goto l17;
l15:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18062))+20);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 18079)))), &_td_OOC_AST__FormalParsDesc, 18079)), 18090))+20);
  i3 = i3!=0;
  
l17:
  if (!i3) goto l19;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18178))+20);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 18194)))), &_td_OOC_AST__FormalParsDesc, 18194)), 18205))+20);
  i3 = (OOC_INT32)OOC_AST_CreateSymTab__GetTypeParent((OOC_AST_CreateSymTab__Visitor)i7, (OOC_AST__Node)i3, (OOC_SymbolTable__Item)i2);
  OOC_SymbolTable__FormalParsDesc_SetResultType((OOC_SymbolTable__FormalPars)i2, (OOC_SymbolTable__Type)i3);
l19:
  *(OOC_INT32*)((_check_pointer(i1, 18270))+64) = i2;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18315))+8);
  i3 = i3!=0;
  if (!i3) goto l22;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18369))+8);
  OOC_AST_CreateSymTab__AcceptParent((OOC_AST_CreateSymTab__Visitor)i7, (OOC_AST__Node)i3, (OOC_SymbolTable__Item)i2);
l22:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18418))+20);
  i3 = i3!=0;
  if (!i3) goto l55;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18465))+20);
  i3 = _type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 18482)))), &_td_OOC_AST__FormalParsDesc, 18482);
  fpar = (OOC_AST__FormalPars)i3;
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 18508));
  i4 = i4!=0;
  if (!i4) goto l27;
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 18571));
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 18577))+8);
  OOC_AST_CreateSymTab__ParseFormalParsFlags((OOC_SymbolTable__FormalPars)i2, (OOC_AST__NodeList)i4);
l27:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 18614))+8);
  i4 = i4!=0;
  if (!i4) goto l42;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 18665))+8);
  i = 0;
  i4 = *(OOC_INT32*)(_check_pointer(i4, 18677));
  i5 = 0<i4;
  if (!i5) goto l42;
  i5=0;
l32_loop:
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 18718))+8);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 18730))+4);
  i6 = _check_pointer(i6, 18733);
  i8 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i5, i8, OOC_UINT32, 18733))*4);
  nodePtr = (OOC_AST__Node)i6;
  i8 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 18760)))), &_td_OOC_AST__TerminalDesc);
  if (i8) goto l35;
  OOC_AST_CreateSymTab__AcceptParent((OOC_AST_CreateSymTab__Visitor)i7, (OOC_AST__Node)i6, (OOC_SymbolTable__Item)i2);
  goto l36;
l35:
  i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i6, 18826));
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 18831))+8);
  _assert(((
  _cmp8((const void*)(_check_pointer(i6, 18836)),(const void*)"..."))==0), 127, 18811);
  OOC_SymbolTable__FormalParsDesc_EnableRestParameters((OOC_SymbolTable__FormalPars)i2);
l36:
  i5 = i5+2;
  i = i5;
  i6 = i5<i4;
  if (i6) goto l32_loop;
l42:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 19012))+28);
  i4 = i4!=0;
  if (i4) goto l45;
  *(OOC_INT32*)((_check_pointer(i2, 19378))+60) = ((OOC_INT32)RT0__NewObject(_td_OOC_SymbolTable__ExceptionNameArray.baseTypes[0], 0));
  goto l55;
l45:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 19072))+28);
  i4 = *(OOC_INT32*)(_check_pointer(i4, 19083));
  *(OOC_INT32*)((_check_pointer(i2, 19058))+60) = ((OOC_INT32)RT0__NewObject(_td_OOC_SymbolTable__ExceptionNameArray.baseTypes[0], ((i4+1)>>1)));
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 19125))+28);
  i = 0;
  i4 = *(OOC_INT32*)(_check_pointer(i4, 19137));
  i5 = 0<i4;
  if (!i5) goto l55;
  i5=0;
l48_loop:
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 19178))+28);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 19190))+4);
  i6 = _check_pointer(i6, 19193);
  i8 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i5, i8, OOC_UINT32, 19193))*4);
  nodePtr = (OOC_AST__Node)i6;
  i6 = (OOC_INT32)OOC_AST_CreateSymTab__GetType((OOC_AST_CreateSymTab__Visitor)i7, (OOC_AST__Node)i6);
  type = (OOC_SymbolTable__Type)i6;
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 19257))+60);
  i8 = _check_pointer(i8, 19264);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i10 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i7, 19292));
  i11 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i7, 19292));
  i6 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i10, 19296)))), OOC_SymbolTable_Builder__BuilderDesc_NewExceptionName)),OOC_SymbolTable_Builder__BuilderDesc_NewExceptionName)((OOC_SymbolTable_Builder__Builder)i11, (OOC_SymbolTable__Item)i2, (OOC_SymbolTable__Type)i6);
  *(OOC_INT32*)(i8+(_check_index((i5>>1), i9, OOC_UINT32, 19264))*4) = i6;
  i5 = i5+2;
  i = i5;
  i6 = i5<i4;
  if (i6) goto l48_loop;
l55:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19427))+12);
  i2 = i2!=0;
  if (!i2) goto l58;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19487))+12);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19494))+8);
  OOC_AST_CreateSymTab__VisitorDesc_VisitProcDecl_ParseProcDeclFlags((OOC_SymbolTable__ProcDecl)i1, (OOC_AST__NodeList)i0);
l58:
  i0 = (OOC_INT32)procDecl;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19537))+28);
  i1 = i1!=0;
  if (!i1) goto l61;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19587))+28);
  i1 = (OOC_INT32)proc;
  i2 = (OOC_INT32)v;
  OOC_AST_CreateSymTab__AcceptParent((OOC_AST_CreateSymTab__Visitor)i2, (OOC_AST__Node)i0, (OOC_SymbolTable__Item)i1);
l61:
  return;
  ;
}

void OOC_AST_CreateSymTab__VisitorDesc_VisitFieldList(OOC_AST_CreateSymTab__Visitor v, OOC_AST__FieldList fieldList) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11;
  OOC_SymbolTable__Type type;
  OOC_INT32 i;
  OOC_SymbolTable__FieldDecl field;
  OOC_AST__Node flags;

  i0 = (OOC_INT32)fieldList;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 19828))+8);
  i2 = (OOC_INT32)v;
  i1 = (OOC_INT32)OOC_AST_CreateSymTab__GetType((OOC_AST_CreateSymTab__Visitor)i2, (OOC_AST__Node)i1);
  type = (OOC_SymbolTable__Type)i1;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 19864));
  i = 0;
  i3 = *(OOC_INT32*)(_check_pointer(i3, 19875));
  i4 = 0<i3;
  if (!i4) goto l11;
  i4=0;
l3_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 20124));
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 20135))+4);
  i5 = _check_pointer(i5, 20138);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 20138))*4);
  i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 20072));
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 20083))+4);
  i6 = _check_pointer(i6, 20086);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i4, i7, OOC_UINT32, 20086))*4);
  i6 = OOC_AST_CreateSymTab__ExportMark((OOC_AST__Node)(_type_guard(i6, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 20094)))), &_td_OOC_AST__IdentDefDesc, 20094)));
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i5, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 20146)))), &_td_OOC_AST__IdentDefDesc, 20146)), 20155))+8);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20034))+8);
  i7 = OOC_AST_CreateSymTab__EndOfType((OOC_AST__Node)i7);
  i8 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 19965));
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i8, 19976))+4);
  i8 = _check_pointer(i8, 19979);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i8 = (OOC_INT32)*(OOC_INT32*)(i8+(_check_index(i4, i9, OOC_UINT32, 19979))*4);
  i8 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i8, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i8, 19987)))), &_td_OOC_AST__IdentDefDesc, 19987)), 19996));
  i8 = (OOC_INT32)OOC_AST_CreateSymTab__GetName((OOC_AST__Node)i8);
  i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 19907));
  i10 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 19929))+4);
  i11 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 19907));
  i5 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i9, 19912)))), OOC_SymbolTable_Builder__BuilderDesc_NewFieldDecl)),OOC_SymbolTable_Builder__BuilderDesc_NewFieldDecl)((OOC_SymbolTable_Builder__Builder)i11, (OOC_SymbolTable__Item)i10, (OOC_SymbolTable__Name)i8, i7, i6, (OOC_Doc__Document)i5, (OOC_SymbolTable__Type)i1);
  field = (OOC_SymbolTable__FieldDecl)i5;
  i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 20207));
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 20218))+4);
  i6 = _check_pointer(i6, 20221);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index((i4+1), i7, OOC_UINT32, 20221))*4);
  flags = (OOC_AST__Node)i6;
  i7 = i6!=0;
  if (!i7) goto l6;
  OOC_AST_CreateSymTab__AddFlags((OOC_SymbolTable__Item)i5, (OOC_AST__Flags)(_type_guard(i6, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 20290)))), &_td_OOC_AST__FlagsDesc, 20290)));
l6:
  i4 = i4+3;
  i = i4;
  i5 = i4<i3;
  if (i5) goto l3_loop;
l11:
  return;
  ;
}

void OOC_AST_CreateSymTab__VisitorDesc_VisitTerminal(OOC_AST_CreateSymTab__Visitor v, OOC_AST__Terminal terminal) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)terminal;
  i2 = (OOC_INT32)OOC_AST_CreateSymTab__GetName((OOC_AST__Node)i1);
  i1 = (OOC_INT32)OOC_AST_CreateSymTab__GetPosition((OOC_AST__Node)i1);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 20430));
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20451))+4);
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 20430));
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 20435)))), OOC_SymbolTable_Builder__BuilderDesc_NewTypeName)),OOC_SymbolTable_Builder__BuilderDesc_NewTypeName)((OOC_SymbolTable_Builder__Builder)i5, (OOC_SymbolTable__Item)i4, (OOC_SymbolTable__Position)i1, (OOC_SymbolTable__Name)(OOC_INT32)0, (OOC_SymbolTable__Name)i2);
  *(OOC_INT32*)((_check_pointer(i0, 20419))+8) = i1;
  return;
  ;
}

void OOC_AST_CreateSymTab__VisitorDesc_VisitOperator(OOC_AST_CreateSymTab__Visitor v, OOC_AST__Operator _operator) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)_operator;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 20788))+8);
  i2 = (OOC_INT32)OOC_AST_CreateSymTab__GetName((OOC_AST__Node)i2);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 20762));
  i3 = (OOC_INT32)OOC_AST_CreateSymTab__GetName((OOC_AST__Node)i3);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 20709));
  i1 = (OOC_INT32)OOC_AST_CreateSymTab__GetPosition((OOC_AST__Node)i1);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 20657));
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20678))+4);
  i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 20657));
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 20662)))), OOC_SymbolTable_Builder__BuilderDesc_NewTypeName)),OOC_SymbolTable_Builder__BuilderDesc_NewTypeName)((OOC_SymbolTable_Builder__Builder)i6, (OOC_SymbolTable__Item)i5, (OOC_SymbolTable__Position)i1, (OOC_SymbolTable__Name)i3, (OOC_SymbolTable__Name)i2);
  *(OOC_INT32*)((_check_pointer(i0, 20646))+8) = i1;
  return;
  ;
}

void OOC_AST_CreateSymTab__VisitorDesc_VisitRecordType(OOC_AST_CreateSymTab__Visitor v, OOC_AST__RecordType recordType) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_SymbolTable__Type baseType;
  OOC_SymbolTable__Record record;
  OOC_INT32 i;

  i0 = (OOC_INT32)recordType;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 20986))+12);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l3;
  baseType = (OOC_SymbolTable__Type)(OOC_INT32)0;
  i1=(OOC_INT32)0;
  goto l4;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21049))+12);
  i2 = (OOC_INT32)v;
  i1 = (OOC_INT32)OOC_AST_CreateSymTab__GetType((OOC_AST_CreateSymTab__Visitor)i2, (OOC_AST__Node)i1);
  baseType = (OOC_SymbolTable__Type)i1;
  
l4:
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 21169));
  i2 = (OOC_INT32)OOC_AST_CreateSymTab__GetPosition((OOC_AST__Node)i2);
  i3 = (OOC_INT32)v;
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 21117));
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 21136))+4);
  i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 21117));
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 21122)))), OOC_SymbolTable_Builder__BuilderDesc_NewRecord)),OOC_SymbolTable_Builder__BuilderDesc_NewRecord)((OOC_SymbolTable_Builder__Builder)i6, (OOC_SymbolTable__Item)i5, (OOC_SymbolTable__Position)i2, (OOC_SymbolTable__Type)i1);
  record = (OOC_SymbolTable__Record)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21255))+4);
  OOC_AST_CreateSymTab__AddFlags((OOC_SymbolTable__Item)i1, (OOC_AST__Flags)i2);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21292))+20);
  i = 0;
  i2 = *(OOC_INT32*)(_check_pointer(i2, 21304));
  i4 = 0<i2;
  if (!i4) goto l15;
  i4=0;
l7_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21340))+20);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 21352))+4);
  i5 = _check_pointer(i5, 21355);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 21355))*4);
  i5 = i5!=(OOC_INT32)0;
  if (!i5) goto l10;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21406))+20);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 21418))+4);
  i5 = _check_pointer(i5, 21421);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 21421))*4);
  OOC_AST_CreateSymTab__AcceptParent((OOC_AST_CreateSymTab__Visitor)i3, (OOC_AST__Node)i5, (OOC_SymbolTable__Item)i1);
l10:
  i4 = i4+2;
  i = i4;
  i5 = i4<i2;
  if (i5) goto l7_loop;
l15:
  *(OOC_INT32*)((_check_pointer(i3, 21458))+8) = i1;
  return;
  ;
}

void OOC_AST_CreateSymTab__VisitorDesc_VisitPointerType(OOC_AST_CreateSymTab__Visitor v, OOC_AST__PointerType pointerType) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)pointerType;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 21755))+12);
  i2 = (OOC_INT32)OOC_AST_CreateSymTab__GetType((OOC_AST_CreateSymTab__Visitor)i0, (OOC_AST__Node)i2);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 21685));
  i3 = (OOC_INT32)OOC_AST_CreateSymTab__GetPosition((OOC_AST__Node)i3);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 21596));
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21616))+4);
  i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 21596));
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 21601)))), OOC_SymbolTable_Builder__BuilderDesc_NewPointer)),OOC_SymbolTable_Builder__BuilderDesc_NewPointer)((OOC_SymbolTable_Builder__Builder)i6, (OOC_SymbolTable__Item)i5, (OOC_SymbolTable__Position)i3, (OOC_SymbolTable__Type)i2);
  *(OOC_INT32*)((_check_pointer(i0, 21585))+8) = i2;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 21797))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21779))+8);
  OOC_AST_CreateSymTab__AddFlags((OOC_SymbolTable__Item)i0, (OOC_AST__Flags)i1);
  return;
  ;
}

void OOC_AST_CreateSymTab__VisitorDesc_VisitArrayType(OOC_AST_CreateSymTab__Visitor v, OOC_AST__ArrayType arrayType) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8;
  OOC_SymbolTable__Type baseType;
  OOC_INT32 i;
  OOC_SymbolTable__Position pos;
  OOC_SymbolTable__Array array;

  i0 = (OOC_INT32)arrayType;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22014))+8);
  i1 = *(OOC_INT32*)(_check_pointer(i1, 22024));
  i1 = i1>0;
  if (i1) goto l3;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22707))+16);
  i2 = (OOC_INT32)v;
  i1 = (OOC_INT32)OOC_AST_CreateSymTab__GetType((OOC_AST_CreateSymTab__Visitor)i2, (OOC_AST__Node)i1);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 22632));
  i3 = (OOC_INT32)OOC_AST_CreateSymTab__GetPosition((OOC_AST__Node)i3);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 22582));
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 22600))+4);
  i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 22582));
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 22587)))), OOC_SymbolTable_Builder__BuilderDesc_NewArray)),OOC_SymbolTable_Builder__BuilderDesc_NewArray)((OOC_SymbolTable_Builder__Builder)i6, (OOC_SymbolTable__Item)i5, (OOC_SymbolTable__Position)i3, 1u, (OOC_AST__Node)0, (OOC_SymbolTable__Type)i1);
  array = (OOC_SymbolTable__Array)i1;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22748))+4);
  OOC_AST_CreateSymTab__AddFlags((OOC_SymbolTable__Item)i1, (OOC_AST__Flags)i0);
  i0=i2;
  goto l17;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22079))+16);
  i2 = (OOC_INT32)v;
  i1 = (OOC_INT32)OOC_AST_CreateSymTab__GetType((OOC_AST_CreateSymTab__Visitor)i2, (OOC_AST__Node)i1);
  baseType = (OOC_SymbolTable__Type)i1;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22112))+8);
  i3 = *(OOC_INT32*)(_check_pointer(i3, 22122));
  i3 = i3-1;
  i = i3;
  i4 = i3>=0;
  if (i4) goto l6;
  i0=i1;
  goto l16;
l6:
  {register OOC_INT32 h0=i1;i1=i3;i3=h0;}
l7_loop:
  i4 = i1==0;
  if (i4) goto l10;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22269))+8);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 22279))+4);
  i4 = _check_pointer(i4, 22282);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index((i1-1), i5, OOC_UINT32, 22282))*4);
  i4 = (OOC_INT32)OOC_AST_CreateSymTab__GetPosition((OOC_AST__Node)i4);
  pos = (OOC_SymbolTable__Position)i4;
  
  goto l11;
l10:
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 22207));
  i4 = (OOC_INT32)OOC_AST_CreateSymTab__GetPosition((OOC_AST__Node)i4);
  pos = (OOC_SymbolTable__Position)i4;
  
l11:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22424))+8);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 22434))+4);
  i5 = _check_pointer(i5, 22437);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 22324));
  i8 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 22354))+4);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i1, i6, OOC_UINT32, 22437))*4);
  i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 22324));
  i3 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i7, 22329)))), OOC_SymbolTable_Builder__BuilderDesc_NewArray)),OOC_SymbolTable_Builder__BuilderDesc_NewArray)((OOC_SymbolTable_Builder__Builder)i6, (OOC_SymbolTable__Item)i8, (OOC_SymbolTable__Position)i4, 0u, (OOC_AST__Node)i5, (OOC_SymbolTable__Type)i3);
  baseType = (OOC_SymbolTable__Type)i3;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22502))+4);
  OOC_AST_CreateSymTab__AddFlags((OOC_SymbolTable__Item)i3, (OOC_AST__Flags)i4);
  i1 = i1+(-2);
  i = i1;
  i4 = i1>=0;
  if (i4) goto l7_loop;
l15:
  i0=i3;
l16:
  i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22550)))), &_td_OOC_SymbolTable__ArrayDesc, 22550);
  array = (OOC_SymbolTable__Array)i0;
  i1=i0;i0=i2;
l17:
  *(OOC_INT32*)((_check_pointer(i0, 22771))+8) = i1;
  return;
  ;
}

void OOC_AST_CreateSymTab__VisitorDesc_VisitProcType(OOC_AST_CreateSymTab__Visitor v, OOC_AST__ProcType procType) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9;
  OOC_SymbolTable__FormalPars formalPars;
  OOC_AST__FormalPars fpars;
  OOC_AST__FormalPars fpar;
  OOC_INT32 i;
  OOC_AST__Node nodePtr;
  OOC_SymbolTable__Type type;

  i0 = (OOC_INT32)procType;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 23145));
  i1 = (OOC_INT32)OOC_AST_CreateSymTab__GetPosition((OOC_AST__Node)i1);
  i2 = (OOC_INT32)v;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 23052));
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 23075))+4);
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 23052));
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 23057)))), OOC_SymbolTable_Builder__BuilderDesc_NewFormalPars)),OOC_SymbolTable_Builder__BuilderDesc_NewFormalPars)((OOC_SymbolTable_Builder__Builder)i5, (OOC_SymbolTable__Item)i4, (OOC_SymbolTable__Position)i1);
  formalPars = (OOC_SymbolTable__FormalPars)i1;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23176))+4);
  i3 = i3!=0;
  if (i3) goto l3;
  i3=0u;
  goto l5;
l3:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23214))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 23231)))), &_td_OOC_AST__FormalParsDesc, 23231)), 23242))+20);
  i3 = i3!=0;
  
l5:
  if (!i3) goto l7;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23330))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 23346)))), &_td_OOC_AST__FormalParsDesc, 23346)), 23357))+20);
  i3 = (OOC_INT32)OOC_AST_CreateSymTab__GetTypeParent((OOC_AST_CreateSymTab__Visitor)i2, (OOC_AST__Node)i3, (OOC_SymbolTable__Item)i1);
  OOC_SymbolTable__FormalParsDesc_SetResultType((OOC_SymbolTable__FormalPars)i1, (OOC_SymbolTable__Type)i3);
l7:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23430))+4);
  i3 = i3!=0;
  if (!i3) goto l13;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23477))+4);
  i3 = _type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 23493)))), &_td_OOC_AST__FormalParsDesc, 23493);
  fpars = (OOC_AST__FormalPars)i3;
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 23520));
  i4 = i4!=0;
  if (!i4) goto l13;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 23594));
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 23600))+8);
  OOC_AST_CreateSymTab__ParseFormalParsFlags((OOC_SymbolTable__FormalPars)i1, (OOC_AST__NodeList)i3);
l13:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23646))+4);
  i3 = i3!=0;
  if (!i3) goto l39;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23693))+4);
  i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23710)))), &_td_OOC_AST__FormalParsDesc, 23710);
  fpar = (OOC_AST__FormalPars)i0;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23737))+8);
  i3 = i3!=0;
  if (!i3) goto l26;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23788))+8);
  i = 0;
  i3 = *(OOC_INT32*)(_check_pointer(i3, 23800));
  i4 = 0<i3;
  if (!i4) goto l26;
  i4=0;
l20_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23847))+8);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 23859))+4);
  i5 = _check_pointer(i5, 23862);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 23862))*4);
  OOC_AST_CreateSymTab__AcceptParent((OOC_AST_CreateSymTab__Visitor)i2, (OOC_AST__Node)i5, (OOC_SymbolTable__Item)i1);
  i4 = i4+2;
  i = i4;
  i5 = i4<i3;
  if (i5) goto l20_loop;
l26:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23924))+28);
  i3 = i3!=0;
  if (i3) goto l29;
  *(OOC_INT32*)((_check_pointer(i1, 24290))+60) = ((OOC_INT32)RT0__NewObject(_td_OOC_SymbolTable__ExceptionNameArray.baseTypes[0], 0));
  goto l39;
l29:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23984))+28);
  i3 = *(OOC_INT32*)(_check_pointer(i3, 23995));
  *(OOC_INT32*)((_check_pointer(i1, 23970))+60) = ((OOC_INT32)RT0__NewObject(_td_OOC_SymbolTable__ExceptionNameArray.baseTypes[0], ((i3+1)>>1)));
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24037))+28);
  i = 0;
  i3 = *(OOC_INT32*)(_check_pointer(i3, 24049));
  i4 = 0<i3;
  if (!i4) goto l39;
  i4=0;
l32_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24090))+28);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 24102))+4);
  i5 = _check_pointer(i5, 24105);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 24105))*4);
  nodePtr = (OOC_AST__Node)i5;
  i5 = (OOC_INT32)OOC_AST_CreateSymTab__GetType((OOC_AST_CreateSymTab__Visitor)i2, (OOC_AST__Node)i5);
  type = (OOC_SymbolTable__Type)i5;
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 24169))+60);
  i6 = _check_pointer(i6, 24176);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i8 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 24204));
  i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 24204));
  i5 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i8, 24208)))), OOC_SymbolTable_Builder__BuilderDesc_NewExceptionName)),OOC_SymbolTable_Builder__BuilderDesc_NewExceptionName)((OOC_SymbolTable_Builder__Builder)i9, (OOC_SymbolTable__Item)i1, (OOC_SymbolTable__Type)i5);
  *(OOC_INT32*)(i6+(_check_index((i4>>1), i7, OOC_UINT32, 24176))*4) = i5;
  i4 = i4+2;
  i = i4;
  i5 = i4<i3;
  if (i5) goto l32_loop;
l39:
  *(OOC_INT32*)((_check_pointer(i2, 24328))+8) = i1;
  return;
  ;
}

void OOC_AST_CreateSymTab__VisitorDesc_VisitQualType(OOC_AST_CreateSymTab__Visitor v, OOC_AST__QualType qualType) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10;
  OOC_SymbolTable__Type baseType;
  OOC_SymbolTable__TypeRefArray arguments;
  OOC_INT32 i;

  i0 = (OOC_INT32)qualType;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 24557));
  i2 = (OOC_INT32)v;
  i1 = (OOC_INT32)OOC_AST_CreateSymTab__GetType((OOC_AST_CreateSymTab__Visitor)i2, (OOC_AST__Node)i1);
  baseType = (OOC_SymbolTable__Type)i1;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24598))+8);
  i3 = *(OOC_INT32*)(_check_pointer(i3, 24608));
  i3 = (OOC_INT32)RT0__NewObject(_td_OOC_SymbolTable__TypeRefArray.baseTypes[0], ((i3+1)>>1));
  arguments = (OOC_SymbolTable__TypeRefArray)i3;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24650))+8);
  i = 0;
  i4 = *(OOC_INT32*)(_check_pointer(i4, 24660));
  i5 = 0<i4;
  if (!i5) goto l8;
  i5 = (OOC_INT32)&_td_OOC_SymbolTable__TypeRef;
  i6=0;
l3_loop:
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24758))+8);
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i7, 24768))+4);
  i7 = _check_pointer(i7, 24770);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i6, i8, OOC_UINT32, 24770))*4);
  i7 = (OOC_INT32)OOC_AST_CreateSymTab__GetType((OOC_AST_CreateSymTab__Visitor)i2, (OOC_AST__Node)i7);
  i8 = OOC_ARRAY_LENGTH((_check_pointer(i3, 24706)), 0);
  i9 = i6>>1;
  i8 = _check_index(i9, i8, OOC_UINT32, 24706);
  i8 = _check_pointer(i3, 24706);
  i10 = OOC_ARRAY_LENGTH(i8, 0);
  OOC_SymbolTable__InitTypeRef((void*)(i8+(_check_index(i9, i10, OOC_UINT32, 24706))*8), (RT0__Struct)i5, (OOC_SymbolTable__Type)i7);
  i6 = i6+2;
  i = i6;
  i7 = i6<i4;
  if (i7) goto l3_loop;
l8:
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 24880));
  i0 = (OOC_INT32)OOC_AST_CreateSymTab__GetPosition((OOC_AST__Node)i0);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 24801));
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 24819))+4);
  i6 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 24801));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 24805)))), OOC_SymbolTable_Builder__BuilderDesc_NewQualType)),OOC_SymbolTable_Builder__BuilderDesc_NewQualType)((OOC_SymbolTable_Builder__Builder)i6, (OOC_SymbolTable__Item)i5, (OOC_SymbolTable__Position)i0, (OOC_SymbolTable__Type)i1, (OOC_SymbolTable__TypeRefArray)i3);
  *(OOC_INT32*)((_check_pointer(i2, 24791))+8) = i0;
  return;
  ;
}

OOC_SymbolTable__Module OOC_AST_CreateSymTab__CreateSymTab(OOC_AST__Node module, OOC_SymbolTable_Builder__Builder stb, Object__String libraryName, URI__HierarchicalURI baseURI, URI__HierarchicalURI rootURI) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_AST_CreateSymTab__Visitor v;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST_CreateSymTab__Visitor.baseTypes[0]);
  v = (OOC_AST_CreateSymTab__Visitor)i0;
  i1 = (OOC_INT32)stb;
  *(OOC_INT32*)(_check_pointer(i0, 25545)) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 25564))+4) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 25586))+8) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 25606))+12) = 0;
  i2 = (OOC_INT32)baseURI;
  *(OOC_INT32*)((_check_pointer(i0, 25626))+16) = i2;
  i2 = (OOC_INT32)rootURI;
  *(OOC_INT32*)((_check_pointer(i0, 25653))+20) = i2;
  i2 = (OOC_INT32)module;
  OOC_AST_CreateSymTab__Accept((OOC_AST_CreateSymTab__Visitor)i0, (OOC_AST__Node)i2);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25704))+12);
  i3 = (OOC_INT32)libraryName;
  OOC_SymbolTable__ModuleDesc_SetLibraryName((OOC_SymbolTable__Module)i2, (Object__String)i3);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25759))+12);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 25746)))), OOC_SymbolTable_Builder__BuilderDesc_Finalize)),OOC_SymbolTable_Builder__BuilderDesc_Finalize)((OOC_SymbolTable_Builder__Builder)i1, (OOC_SymbolTable__Module)i2);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25780))+12);
  return (OOC_SymbolTable__Module)i0;
  ;
}

void OOC_OOC_AST_CreateSymTab_init(void) {

  return;
  ;
}

void OOC_OOC_AST_CreateSymTab_destroy(void) {
}

/* --- */
