#include <OOC/AST.d>
#include <__oo2c.h>
#include <setjmp.h>

void OOC_AST__NodeDesc_Accept(OOC_AST__Node node, OOC_AST__Visitor v) {

  return;
  ;
}

void OOC_AST__InitVisitor(OOC_AST__Visitor v) {

  return;
  ;
}

void OOC_AST__VisitorDesc_VisitNodeList(OOC_AST__Visitor v, OOC_AST__NodeList nl) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_INT32 i;

  i0 = (OOC_INT32)nl;
  i = 0;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 16656));
  i2 = 0<i1;
  if (!i2) goto l11;
  i2 = (OOC_INT32)v;
  i3=0;
l3_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16679))+4);
  i4 = _check_pointer(i4, 16682);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 16682))*4);
  i4 = i4!=0;
  if (!i4) goto l6;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16708))+4);
  i4 = _check_pointer(i4, 16711);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 16711))*4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16708))+4);
  i5 = _check_pointer(i5, 16711);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i3, i6, OOC_UINT32, 16711))*4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 16714)))), OOC_AST__NodeDesc_Accept)),OOC_AST__NodeDesc_Accept)((OOC_AST__Node)i5, (OOC_AST__Visitor)i2);
l6:
  i3 = i3+1;
  i = i3;
  i4 = i3<i1;
  if (i4) goto l3_loop;
l11:
  return;
  ;
}

void OOC_AST__VisitorDesc_VisitTerminal(OOC_AST__Visitor v, OOC_AST__Terminal terminal) {

  return;
  ;
}

void OOC_AST__VisitorDesc_VisitIdentDef(OOC_AST__Visitor v, OOC_AST__IdentDef identDef) {

  return;
  ;
}

void OOC_AST__VisitorDesc_VisitModuleIdent(OOC_AST__Visitor v, OOC_AST__ModuleIdent moduleIdent) {

  return;
  ;
}

void OOC_AST__VisitorDesc_VisitArrayType(OOC_AST__Visitor v, OOC_AST__ArrayType arrayType) {

  return;
  ;
}

void OOC_AST__VisitorDesc_VisitFieldList(OOC_AST__Visitor v, OOC_AST__FieldList fieldList) {

  return;
  ;
}

void OOC_AST__VisitorDesc_VisitRecordType(OOC_AST__Visitor v, OOC_AST__RecordType recordType) {

  return;
  ;
}

void OOC_AST__VisitorDesc_VisitPointerType(OOC_AST__Visitor v, OOC_AST__PointerType pointerType) {

  return;
  ;
}

void OOC_AST__VisitorDesc_VisitFPSection(OOC_AST__Visitor v, OOC_AST__FPSection fpSection) {

  return;
  ;
}

void OOC_AST__VisitorDesc_VisitFormalPars(OOC_AST__Visitor v, OOC_AST__FormalPars formalPars) {

  return;
  ;
}

void OOC_AST__VisitorDesc_VisitProcType(OOC_AST__Visitor v, OOC_AST__ProcType procType) {

  return;
  ;
}

void OOC_AST__VisitorDesc_VisitTPSection(OOC_AST__Visitor v, OOC_AST__TPSection tpSection) {

  return;
  ;
}

void OOC_AST__VisitorDesc_VisitTypePars(OOC_AST__Visitor v, OOC_AST__TypePars typePars) {

  return;
  ;
}

void OOC_AST__VisitorDesc_VisitQualType(OOC_AST__Visitor v, OOC_AST__QualType qualType) {

  return;
  ;
}

void OOC_AST__VisitorDesc_VisitImportDecl(OOC_AST__Visitor v, OOC_AST__ImportDecl importDecl) {

  return;
  ;
}

void OOC_AST__VisitorDesc_VisitConstDecl(OOC_AST__Visitor v, OOC_AST__ConstDecl constDecl) {

  return;
  ;
}

void OOC_AST__VisitorDesc_VisitTypeDecl(OOC_AST__Visitor v, OOC_AST__TypeDecl typeDecl) {

  return;
  ;
}

void OOC_AST__VisitorDesc_VisitVarDecl(OOC_AST__Visitor v, OOC_AST__VarDecl varDecl) {

  return;
  ;
}

void OOC_AST__VisitorDesc_VisitReceiver(OOC_AST__Visitor v, OOC_AST__Receiver receiver) {

  return;
  ;
}

void OOC_AST__VisitorDesc_VisitProcDecl(OOC_AST__Visitor v, OOC_AST__ProcDecl procDecl) {

  return;
  ;
}

void OOC_AST__VisitorDesc_VisitImportList(OOC_AST__Visitor v, OOC_AST__ImportList importList) {

  return;
  ;
}

void OOC_AST__VisitorDesc_VisitBody(OOC_AST__Visitor v, OOC_AST__Body body) {

  return;
  ;
}

void OOC_AST__VisitorDesc_VisitModule(OOC_AST__Visitor v, OOC_AST__Module module) {

  return;
  ;
}

void OOC_AST__VisitorDesc_VisitOperator(OOC_AST__Visitor v, OOC_AST__Operator _operator) {

  return;
  ;
}

void OOC_AST__VisitorDesc_VisitFactor(OOC_AST__Visitor v, OOC_AST__Factor factor) {

  return;
  ;
}

void OOC_AST__VisitorDesc_VisitSet(OOC_AST__Visitor v, OOC_AST__Set set) {

  return;
  ;
}

void OOC_AST__VisitorDesc_VisitArrayIndex(OOC_AST__Visitor v, OOC_AST__ArrayIndex arrayIndex) {

  return;
  ;
}

void OOC_AST__VisitorDesc_VisitFunctionCall(OOC_AST__Visitor v, OOC_AST__FunctionCall functionCall) {

  return;
  ;
}

void OOC_AST__VisitorDesc_VisitAssignment(OOC_AST__Visitor v, OOC_AST__Assignment assignment) {

  return;
  ;
}

void OOC_AST__VisitorDesc_VisitProcedureCall(OOC_AST__Visitor v, OOC_AST__ProcedureCall procedureCall) {

  return;
  ;
}

void OOC_AST__VisitorDesc_VisitIfStatm(OOC_AST__Visitor v, OOC_AST__IfStatm ifStatm) {

  return;
  ;
}

void OOC_AST__VisitorDesc_VisitCaseStatm(OOC_AST__Visitor v, OOC_AST__CaseStatm caseStatm) {

  return;
  ;
}

void OOC_AST__VisitorDesc_VisitWhileStatm(OOC_AST__Visitor v, OOC_AST__WhileStatm whileStatm) {

  return;
  ;
}

void OOC_AST__VisitorDesc_VisitRepeatStatm(OOC_AST__Visitor v, OOC_AST__RepeatStatm repeatStatm) {

  return;
  ;
}

void OOC_AST__VisitorDesc_VisitForStatm(OOC_AST__Visitor v, OOC_AST__ForStatm forStatm) {

  return;
  ;
}

void OOC_AST__VisitorDesc_VisitLoopStatm(OOC_AST__Visitor v, OOC_AST__LoopStatm loopStatm) {

  return;
  ;
}

void OOC_AST__VisitorDesc_VisitWithStatm(OOC_AST__Visitor v, OOC_AST__WithStatm withStatm) {

  return;
  ;
}

void OOC_AST__VisitorDesc_VisitExitStatm(OOC_AST__Visitor v, OOC_AST__ExitStatm exitStatm) {

  return;
  ;
}

void OOC_AST__VisitorDesc_VisitReturnStatm(OOC_AST__Visitor v, OOC_AST__ReturnStatm returnStatm) {

  return;
  ;
}

void OOC_AST__VisitorDesc_VisitCatch(OOC_AST__Visitor v, OOC_AST__Catch _catch) {

  return;
  ;
}

void OOC_AST__VisitorDesc_VisitTryStatm(OOC_AST__Visitor v, OOC_AST__TryStatm tryStatm) {

  return;
  ;
}

void OOC_AST__VisitorDesc_VisitFlags(OOC_AST__Visitor v, OOC_AST__Flags flags) {

  return;
  ;
}

void OOC_AST__VisitorDesc_VisitProcIdFlag(OOC_AST__Visitor v, OOC_AST__ProcIdFlag procIdFlag) {

  return;
  ;
}

void OOC_AST__VisitorDesc_VisitModuleFlags(OOC_AST__Visitor v, OOC_AST__ModuleFlags moduleFlags) {

  return;
  ;
}

void OOC_AST__VisitorDesc_VisitLinkFileFlag(OOC_AST__Visitor v, OOC_AST__LinkFileFlag linkFileFlag) {

  return;
  ;
}

void OOC_AST__VisitorDesc_VisitLinkObjFlag(OOC_AST__Visitor v, OOC_AST__LinkObjFlag linkObjFlag) {

  return;
  ;
}

void OOC_AST__VisitorDesc_VisitLinkLibFlag(OOC_AST__Visitor v, OOC_AST__LinkLibFlag linkLibFlag) {

  return;
  ;
}

void OOC_AST__Init(OOC_AST__Builder b) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)b;
  *(OOC_INT32*)(_check_pointer(i0, 20815)) = 0;
  return;
  ;
}

OOC_AST__Builder OOC_AST__New(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__Builder.baseTypes[0]);
  OOC_AST__Init((OOC_AST__Builder)i0);
  return (OOC_AST__Builder)i0;
  ;
}

static void OOC_AST__InitNodeList(OOC_AST__NodeList nl) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)nl;
  *(OOC_INT32*)(_check_pointer(i0, 21066)) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 21089))+4) = ((OOC_INT32)RT0__NewObject(_td_OOC_AST__NodeArray.baseTypes[0], 8));
  return;
  ;
}

void OOC_AST__BuilderDesc_SetModuleName(OOC_AST__Builder b, const OOC_CHAR8 name__ref[], OOC_LEN name_0d) {
  register OOC_INT32 i0,i1;
  OOC_ALLOCATE_VPAR(name,OOC_CHAR8 ,name_0d)

  OOC_INITIALIZE_VPAR(name__ref,name,OOC_CHAR8 ,name_0d)
  i0 = (OOC_INT32)b;
  i1 = Strings__Length((void*)(OOC_INT32)name, name_0d);
  *(OOC_INT32*)(_check_pointer(i0, 21376)) = ((OOC_INT32)RT0__NewObject(_td_OOC_Scanner_InputBuffer__CharArray.baseTypes[0], (i1+1)));
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 21441));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 21441));
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 21461)), 0);
  _copy_8((const void*)(OOC_INT32)name,(void*)(_check_pointer(i1, 21461)),i0);
  return;
  ;
}

OOC_AST__NodeList OOC_AST__BuilderDesc_NewNodeList(OOC_AST__Builder b) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__NodeList.baseTypes[0]);
  OOC_AST__InitNodeList((OOC_AST__NodeList)i0);
  return (OOC_AST__NodeList)i0;
  ;
}

void OOC_AST__NodeListDesc_Append(OOC_AST__NodeList nl, OOC_AST__Node node) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  OOC_AST__NodeArray _new;
  OOC_INT32 i;

  i0 = (OOC_INT32)nl;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21872))+4);
  i2 = *(OOC_INT32*)(_check_pointer(i0, 21857));
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 21875)), 0);
  i1 = i2==i1;
  if (!i1) goto l11;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21907))+4);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 21910)), 0);
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__NodeArray.baseTypes[0], (i1*2));
  _new = (OOC_AST__NodeArray)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21944))+4);
  i = 0;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 21947)), 0);
  i3 = 0<i2;
  if (!i3) goto l10;
  i3=0;
l5_loop:
  i4 = _check_pointer(i1, 21966);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 21975))+4);
  i6 = _check_pointer(i6, 21978);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i3, i7, OOC_UINT32, 21978))*4);
  *(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 21966))*4) = i6;
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l5_loop;
l10:
  *(OOC_INT32*)((_check_pointer(i0, 22001))+4) = i1;
l11:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22027))+4);
  i1 = _check_pointer(i1, 22030);
  i2 = *(OOC_INT32*)(_check_pointer(i0, 22033));
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i4 = (OOC_INT32)node;
  *(OOC_INT32*)(i1+(_check_index(i2, i3, OOC_UINT32, 22030))*4) = i4;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 22060));
  *(OOC_INT32*)(_check_pointer(i0, 22060)) = (i1+1);
  return;
  ;
}

void OOC_AST__NodeListDesc_Accept(OOC_AST__NodeList nl, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)nl;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22142)))), OOC_AST__VisitorDesc_VisitNodeList)),OOC_AST__VisitorDesc_VisitNodeList)((OOC_AST__Visitor)i0, (OOC_AST__NodeList)i1);
  return;
  ;
}

void OOC_AST__NodeDesc_AttachDocString(OOC_AST__Node n, OOC_Doc__Document docComment) {

  return;
  ;
}

OOC_AST__Terminal OOC_AST__BuilderDesc_Terminal(OOC_AST__Builder b, OOC_Scanner_SymList__Symbol sym) {
  register OOC_INT32 i0,i1;
  OOC_AST__Terminal t;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__Terminal.baseTypes[0]);
  t = (OOC_AST__Terminal)i0;
  i1 = (OOC_INT32)sym;
  *(OOC_INT32*)(_check_pointer(i0, 23112)) = i1;
  return (OOC_AST__Terminal)i0;
  ;
}

void OOC_AST__TerminalDesc_Accept(OOC_AST__Terminal terminal, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)terminal;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23222)))), OOC_AST__VisitorDesc_VisitTerminal)),OOC_AST__VisitorDesc_VisitTerminal)((OOC_AST__Visitor)i0, (OOC_AST__Terminal)i1);
  return;
  ;
}

Object__String OOC_AST__TerminalDesc_GetString(OOC_AST__Terminal terminal, OOC_CHAR8 stripQuotes) {
  register OOC_INT32 i0,i1,i2;

  i0 = stripQuotes;
  if (i0) goto l3;
  i0 = (OOC_INT32)terminal;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 23532));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23537))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 23532));
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23537))+8);
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 23542)), 0);
  i0 = (OOC_INT32)Object__NewLatin1((void*)(_check_pointer(i1, 23542)), i0);
  return (Object__String)i0;
  goto l4;
l3:
  i0 = (OOC_INT32)terminal;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 23415));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23420))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 23415));
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 23420))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 23470));
  i0 = *(OOC_INT32*)((_check_pointer(i0, 23475))+12);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 23425)), 0);
  i0 = (OOC_INT32)Object__NewLatin1Region((void*)(_check_pointer(i1, 23425)), i2, 1, (i0-1));
  return (Object__String)i0;
l4:
  _failed_function(23295); return 0;
  ;
}

OOC_AST__IdentDef OOC_AST__BuilderDesc_IdentDef(OOC_AST__Builder b, OOC_AST__Terminal ident, OOC_AST__Terminal mark) {
  register OOC_INT32 i0,i1;
  OOC_AST__IdentDef id;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__IdentDef.baseTypes[0]);
  id = (OOC_AST__IdentDef)i0;
  i1 = (OOC_INT32)ident;
  *(OOC_INT32*)(_check_pointer(i0, 24078)) = i1;
  i1 = (OOC_INT32)mark;
  *(OOC_INT32*)((_check_pointer(i0, 24102))+4) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 24124))+8) = 0;
  return (OOC_AST__IdentDef)i0;
  ;
}

void OOC_AST__IdentDefDesc_AttachDocString(OOC_AST__IdentDef identDef, OOC_Doc__Document docString) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)identDef;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24274))+8);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l3;
  i1 = (OOC_INT32)docString;
  *(OOC_INT32*)((_check_pointer(i0, 24366))+8) = i1;
  goto l4;
l3:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24312))+8);
  i1 = (OOC_INT32)docString;
  OOC_Doc__DocumentDesc_Merge((OOC_Doc__Document)i0, (OOC_Doc__Document)i1);
l4:
  return;
  ;
}

void OOC_AST__IdentDefDesc_Accept(OOC_AST__IdentDef identDef, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)identDef;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 24489)))), OOC_AST__VisitorDesc_VisitIdentDef)),OOC_AST__VisitorDesc_VisitIdentDef)((OOC_AST__Visitor)i0, (OOC_AST__IdentDef)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_ModuleIdent(OOC_AST__Builder b, OOC_AST__NodeList nameList) {
  register OOC_INT32 i0,i1;
  OOC_AST__ModuleIdent moduleIdent;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__ModuleIdent.baseTypes[0]);
  moduleIdent = (OOC_AST__ModuleIdent)i0;
  i1 = (OOC_INT32)nameList;
  *(OOC_INT32*)(_check_pointer(i0, 24848)) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 24887))+4) = 0;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__ModuleIdentDesc_AttachDocString(OOC_AST__ModuleIdent moduleIdent, OOC_Doc__Document docString) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)moduleIdent;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25058))+4);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l3;
  i1 = (OOC_INT32)docString;
  *(OOC_INT32*)((_check_pointer(i0, 25156))+4) = i1;
  goto l4;
l3:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25099))+4);
  i1 = (OOC_INT32)docString;
  OOC_Doc__DocumentDesc_Merge((OOC_Doc__Document)i0, (OOC_Doc__Document)i1);
l4:
  return;
  ;
}

void OOC_AST__ModuleIdentDesc_Accept(OOC_AST__ModuleIdent moduleIdent, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)moduleIdent;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25285)))), OOC_AST__VisitorDesc_VisitModuleIdent)),OOC_AST__VisitorDesc_VisitModuleIdent)((OOC_AST__Visitor)i0, (OOC_AST__ModuleIdent)i1);
  return;
  ;
}

static void OOC_AST__InitType(OOC_AST__Type t) {

  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_ArrayType(OOC_AST__Builder b, OOC_AST__Node array, OOC_AST__Flags flags, OOC_AST__NodeList exprList, OOC_AST__Node of, OOC_AST__Node type) {
  register OOC_INT32 i0,i1;
  OOC_AST__ArrayType at;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__ArrayType.baseTypes[0]);
  at = (OOC_AST__ArrayType)i0;
  OOC_AST__InitType((OOC_AST__Type)i0);
  i1 = (OOC_INT32)array;
  *(OOC_INT32*)(_check_pointer(i0, 27287)) = i1;
  i1 = (OOC_INT32)flags;
  *(OOC_INT32*)((_check_pointer(i0, 27311))+4) = i1;
  i1 = (OOC_INT32)exprList;
  *(OOC_INT32*)((_check_pointer(i0, 27335))+8) = i1;
  i1 = (OOC_INT32)of;
  *(OOC_INT32*)((_check_pointer(i0, 27365))+12) = i1;
  i1 = (OOC_INT32)type;
  *(OOC_INT32*)((_check_pointer(i0, 27383))+16) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__ArrayTypeDesc_Accept(OOC_AST__ArrayType arrayType, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)arrayType;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 27499)))), OOC_AST__VisitorDesc_VisitArrayType)),OOC_AST__VisitorDesc_VisitArrayType)((OOC_AST__Visitor)i0, (OOC_AST__ArrayType)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_FieldList(OOC_AST__Builder b, OOC_AST__NodeList identList, OOC_AST__Node colon, OOC_AST__Node type) {
  register OOC_INT32 i0,i1;
  OOC_AST__FieldList fl;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__FieldList.baseTypes[0]);
  fl = (OOC_AST__FieldList)i0;
  i1 = (OOC_INT32)identList;
  *(OOC_INT32*)(_check_pointer(i0, 28235)) = i1;
  i1 = (OOC_INT32)colon;
  *(OOC_INT32*)((_check_pointer(i0, 28267))+4) = i1;
  i1 = (OOC_INT32)type;
  *(OOC_INT32*)((_check_pointer(i0, 28291))+8) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__FieldListDesc_Accept(OOC_AST__FieldList fieldList, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)fieldList;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 28407)))), OOC_AST__VisitorDesc_VisitFieldList)),OOC_AST__VisitorDesc_VisitFieldList)((OOC_AST__Visitor)i0, (OOC_AST__FieldList)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_RecordType(OOC_AST__Builder b, OOC_AST__Node record, OOC_AST__Flags flags, OOC_AST__Node lParen, OOC_AST__Node baseType, OOC_AST__Node rParen, OOC_AST__NodeList fieldLists, OOC_AST__Node end) {
  register OOC_INT32 i0,i1;
  OOC_AST__RecordType rt;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__RecordType.baseTypes[0]);
  rt = (OOC_AST__RecordType)i0;
  OOC_AST__InitType((OOC_AST__Type)i0);
  i1 = (OOC_INT32)record;
  *(OOC_INT32*)(_check_pointer(i0, 31061)) = i1;
  i1 = (OOC_INT32)flags;
  *(OOC_INT32*)((_check_pointer(i0, 31087))+4) = i1;
  i1 = (OOC_INT32)lParen;
  *(OOC_INT32*)((_check_pointer(i0, 31111))+8) = i1;
  i1 = (OOC_INT32)baseType;
  *(OOC_INT32*)((_check_pointer(i0, 31137))+12) = i1;
  i1 = (OOC_INT32)rParen;
  *(OOC_INT32*)((_check_pointer(i0, 31167))+16) = i1;
  i1 = (OOC_INT32)fieldLists;
  *(OOC_INT32*)((_check_pointer(i0, 31193))+20) = i1;
  i1 = (OOC_INT32)end;
  *(OOC_INT32*)((_check_pointer(i0, 31227))+24) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__RecordTypeDesc_Accept(OOC_AST__RecordType recordType, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)recordType;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31344)))), OOC_AST__VisitorDesc_VisitRecordType)),OOC_AST__VisitorDesc_VisitRecordType)((OOC_AST__Visitor)i0, (OOC_AST__RecordType)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_PointerType(OOC_AST__Builder b, OOC_AST__Node pointer, OOC_AST__Flags flags, OOC_AST__Node to, OOC_AST__Node type) {
  register OOC_INT32 i0,i1;
  OOC_AST__PointerType pt;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__PointerType.baseTypes[0]);
  pt = (OOC_AST__PointerType)i0;
  OOC_AST__InitType((OOC_AST__Type)i0);
  i1 = (OOC_INT32)pointer;
  *(OOC_INT32*)(_check_pointer(i0, 31902)) = i1;
  i1 = (OOC_INT32)flags;
  *(OOC_INT32*)((_check_pointer(i0, 31930))+4) = i1;
  i1 = (OOC_INT32)to;
  *(OOC_INT32*)((_check_pointer(i0, 31954))+8) = i1;
  i1 = (OOC_INT32)type;
  *(OOC_INT32*)((_check_pointer(i0, 31972))+12) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__PointerTypeDesc_Accept(OOC_AST__PointerType pointerType, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)pointerType;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32094)))), OOC_AST__VisitorDesc_VisitPointerType)),OOC_AST__VisitorDesc_VisitPointerType)((OOC_AST__Visitor)i0, (OOC_AST__PointerType)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_FPSection(OOC_AST__Builder b, OOC_AST__Node var, OOC_AST__NodeList identList, OOC_AST__Node colon, OOC_AST__Node type) {
  register OOC_INT32 i0,i1;
  OOC_AST__FPSection fp;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__FPSection.baseTypes[0]);
  fp = (OOC_AST__FPSection)i0;
  i1 = (OOC_INT32)var;
  *(OOC_INT32*)(_check_pointer(i0, 32985)) = i1;
  i1 = (OOC_INT32)identList;
  *(OOC_INT32*)((_check_pointer(i0, 33005))+4) = i1;
  i1 = (OOC_INT32)colon;
  *(OOC_INT32*)((_check_pointer(i0, 33037))+8) = i1;
  i1 = (OOC_INT32)type;
  *(OOC_INT32*)((_check_pointer(i0, 33061))+12) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__FPSectionDesc_Accept(OOC_AST__FPSection fpSection, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)fpSection;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33177)))), OOC_AST__VisitorDesc_VisitFPSection)),OOC_AST__VisitorDesc_VisitFPSection)((OOC_AST__Visitor)i0, (OOC_AST__FPSection)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_FormalPars(OOC_AST__Builder b, OOC_AST__Flags flags, OOC_AST__Node lParen, OOC_AST__NodeList fpSections, OOC_AST__Node rParen, OOC_AST__Node colon, OOC_AST__Node result, OOC_AST__Node raises, OOC_AST__NodeList raisesList) {
  register OOC_INT32 i0,i1;
  OOC_AST__FormalPars fp;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__FormalPars.baseTypes[0]);
  fp = (OOC_AST__FormalPars)i0;
  i1 = (OOC_INT32)flags;
  *(OOC_INT32*)(_check_pointer(i0, 35346)) = i1;
  i1 = (OOC_INT32)lParen;
  *(OOC_INT32*)((_check_pointer(i0, 35370))+4) = i1;
  i1 = (OOC_INT32)fpSections;
  *(OOC_INT32*)((_check_pointer(i0, 35396))+8) = i1;
  i1 = (OOC_INT32)rParen;
  *(OOC_INT32*)((_check_pointer(i0, 35430))+12) = i1;
  i1 = (OOC_INT32)colon;
  *(OOC_INT32*)((_check_pointer(i0, 35456))+16) = i1;
  i1 = (OOC_INT32)result;
  *(OOC_INT32*)((_check_pointer(i0, 35480))+20) = i1;
  i1 = (OOC_INT32)raises;
  *(OOC_INT32*)((_check_pointer(i0, 35506))+24) = i1;
  i1 = (OOC_INT32)raisesList;
  *(OOC_INT32*)((_check_pointer(i0, 35532))+28) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__FormalParsDesc_Accept(OOC_AST__FormalPars formalPars, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)formalPars;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 35665)))), OOC_AST__VisitorDesc_VisitFormalPars)),OOC_AST__VisitorDesc_VisitFormalPars)((OOC_AST__Visitor)i0, (OOC_AST__FormalPars)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_ProcType(OOC_AST__Builder b, OOC_AST__Node procedure, OOC_AST__Node formalPars) {
  register OOC_INT32 i0,i1;
  OOC_AST__ProcType pt;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__ProcType.baseTypes[0]);
  pt = (OOC_AST__ProcType)i0;
  OOC_AST__InitType((OOC_AST__Type)i0);
  i1 = (OOC_INT32)procedure;
  *(OOC_INT32*)(_check_pointer(i0, 36162)) = i1;
  i1 = (OOC_INT32)formalPars;
  *(OOC_INT32*)((_check_pointer(i0, 36194))+4) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__ProcTypeDesc_Accept(OOC_AST__ProcType procType, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)procType;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36319)))), OOC_AST__VisitorDesc_VisitProcType)),OOC_AST__VisitorDesc_VisitProcType)((OOC_AST__Visitor)i0, (OOC_AST__ProcType)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_TPSection(OOC_AST__Builder b, OOC_AST__NodeList identList, OOC_AST__Node colon, OOC_AST__Node type) {
  register OOC_INT32 i0,i1;
  OOC_AST__TPSection tp;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__TPSection.baseTypes[0]);
  tp = (OOC_AST__TPSection)i0;
  i1 = (OOC_INT32)identList;
  *(OOC_INT32*)((_check_pointer(i0, 36951))+4) = i1;
  i1 = (OOC_INT32)colon;
  *(OOC_INT32*)((_check_pointer(i0, 36983))+8) = i1;
  i1 = (OOC_INT32)type;
  *(OOC_INT32*)((_check_pointer(i0, 37007))+12) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__TPSectionDesc_Accept(OOC_AST__TPSection tpSection, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)tpSection;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37123)))), OOC_AST__VisitorDesc_VisitTPSection)),OOC_AST__VisitorDesc_VisitTPSection)((OOC_AST__Visitor)i0, (OOC_AST__TPSection)i1);
  return;
  ;
}

OOC_AST__TypePars OOC_AST__BuilderDesc_TypePars(OOC_AST__Builder b, OOC_AST__Node lParen, OOC_AST__NodeList tpSections, OOC_AST__Node rParen) {
  register OOC_INT32 i0,i1;
  OOC_AST__TypePars tp;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__TypePars.baseTypes[0]);
  tp = (OOC_AST__TypePars)i0;
  i1 = (OOC_INT32)lParen;
  *(OOC_INT32*)(_check_pointer(i0, 37930)) = i1;
  i1 = (OOC_INT32)tpSections;
  *(OOC_INT32*)((_check_pointer(i0, 37956))+4) = i1;
  i1 = (OOC_INT32)rParen;
  *(OOC_INT32*)((_check_pointer(i0, 37990))+8) = i1;
  return (OOC_AST__TypePars)i0;
  ;
}

void OOC_AST__TypeParsDesc_Accept(OOC_AST__TypePars typePars, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)typePars;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 38109)))), OOC_AST__VisitorDesc_VisitTypePars)),OOC_AST__VisitorDesc_VisitTypePars)((OOC_AST__Visitor)i0, (OOC_AST__TypePars)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_QualType(OOC_AST__Builder b, OOC_AST__Node qualident, OOC_AST__Node lParen, OOC_AST__NodeList arguments, OOC_AST__Node rParen) {
  register OOC_INT32 i0,i1;
  OOC_AST__QualType qt;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__QualType.baseTypes[0]);
  qt = (OOC_AST__QualType)i0;
  i1 = (OOC_INT32)qualident;
  *(OOC_INT32*)(_check_pointer(i0, 39234)) = i1;
  i1 = (OOC_INT32)lParen;
  *(OOC_INT32*)((_check_pointer(i0, 39265))+4) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 39283)))), &_td_OOC_AST__TerminalDesc, 39283));
  i1 = (OOC_INT32)arguments;
  *(OOC_INT32*)((_check_pointer(i0, 39300))+8) = i1;
  i1 = (OOC_INT32)rParen;
  *(OOC_INT32*)((_check_pointer(i0, 39331))+12) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 39349)))), &_td_OOC_AST__TerminalDesc, 39349));
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__QualTypeDesc_Accept(OOC_AST__QualType qualType, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)qualType;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 39460)))), OOC_AST__VisitorDesc_VisitQualType)),OOC_AST__VisitorDesc_VisitQualType)((OOC_AST__Visitor)i0, (OOC_AST__QualType)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_ImportDecl(OOC_AST__Builder b, OOC_AST__Node alias, OOC_AST__Node becomes, OOC_AST__Node module, OOC_Scanner_InputBuffer__CharArray moduleName) {
  register OOC_INT32 i0,i1;
  OOC_AST__ImportDecl id;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__ImportDecl.baseTypes[0]);
  id = (OOC_AST__ImportDecl)i0;
  i1 = (OOC_INT32)alias;
  *(OOC_INT32*)(_check_pointer(i0, 40333)) = i1;
  i1 = (OOC_INT32)becomes;
  *(OOC_INT32*)((_check_pointer(i0, 40357))+4) = i1;
  i1 = (OOC_INT32)module;
  *(OOC_INT32*)((_check_pointer(i0, 40385))+8) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 40404)))), &_td_OOC_AST__ModuleIdentDesc, 40404));
  i1 = (OOC_INT32)moduleName;
  *(OOC_INT32*)((_check_pointer(i0, 40424))+12) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__ImportDeclDesc_Accept(OOC_AST__ImportDecl importDecl, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)importDecl;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 40555)))), OOC_AST__VisitorDesc_VisitImportDecl)),OOC_AST__VisitorDesc_VisitImportDecl)((OOC_AST__Visitor)i0, (OOC_AST__ImportDecl)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_ConstDecl(OOC_AST__Builder b, OOC_AST__Node identDef, OOC_AST__Flags flags, OOC_AST__Node equal, OOC_AST__Node expr, OOC_AST__Node semicolon) {
  register OOC_INT32 i0,i1;
  OOC_AST__ConstDecl cd;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__ConstDecl.baseTypes[0]);
  cd = (OOC_AST__ConstDecl)i0;
  i1 = (OOC_INT32)identDef;
  *(OOC_INT32*)(_check_pointer(i0, 41291)) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 41314)))), &_td_OOC_AST__IdentDefDesc, 41314));
  i1 = (OOC_INT32)flags;
  *(OOC_INT32*)((_check_pointer(i0, 41331))+4) = i1;
  i1 = (OOC_INT32)equal;
  *(OOC_INT32*)((_check_pointer(i0, 41355))+8) = i1;
  i1 = (OOC_INT32)expr;
  *(OOC_INT32*)((_check_pointer(i0, 41379))+12) = i1;
  i1 = (OOC_INT32)semicolon;
  *(OOC_INT32*)((_check_pointer(i0, 41401))+16) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__ConstDeclDesc_Accept(OOC_AST__ConstDecl constDecl, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)constDecl;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 41527)))), OOC_AST__VisitorDesc_VisitConstDecl)),OOC_AST__VisitorDesc_VisitConstDecl)((OOC_AST__Visitor)i0, (OOC_AST__ConstDecl)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_TypeDecl(OOC_AST__Builder b, OOC_AST__Node identDef, OOC_AST__Flags flags, OOC_AST__TypePars typePars, OOC_AST__Node equal, OOC_AST__Node type, OOC_AST__Node semicolon) {
  register OOC_INT32 i0,i1;
  OOC_AST__TypeDecl td;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__TypeDecl.baseTypes[0]);
  td = (OOC_AST__TypeDecl)i0;
  i1 = (OOC_INT32)identDef;
  *(OOC_INT32*)(_check_pointer(i0, 42397)) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 42420)))), &_td_OOC_AST__IdentDefDesc, 42420));
  i1 = (OOC_INT32)flags;
  *(OOC_INT32*)((_check_pointer(i0, 42437))+4) = i1;
  i1 = (OOC_INT32)typePars;
  *(OOC_INT32*)((_check_pointer(i0, 42461))+8) = i1;
  i1 = (OOC_INT32)equal;
  *(OOC_INT32*)((_check_pointer(i0, 42491))+12) = i1;
  i1 = (OOC_INT32)type;
  *(OOC_INT32*)((_check_pointer(i0, 42515))+16) = i1;
  i1 = (OOC_INT32)semicolon;
  *(OOC_INT32*)((_check_pointer(i0, 42537))+20) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__TypeDeclDesc_Accept(OOC_AST__TypeDecl typeDecl, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)typeDecl;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 42660)))), OOC_AST__VisitorDesc_VisitTypeDecl)),OOC_AST__VisitorDesc_VisitTypeDecl)((OOC_AST__Visitor)i0, (OOC_AST__TypeDecl)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_VarDecl(OOC_AST__Builder b, OOC_AST__NodeList identList, OOC_AST__Node colon, OOC_AST__Node type, OOC_AST__Node semicolon) {
  register OOC_INT32 i0,i1;
  OOC_AST__VarDecl vd;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__VarDecl.baseTypes[0]);
  vd = (OOC_AST__VarDecl)i0;
  i1 = (OOC_INT32)identList;
  *(OOC_INT32*)(_check_pointer(i0, 43554)) = i1;
  i1 = (OOC_INT32)colon;
  *(OOC_INT32*)((_check_pointer(i0, 43586))+4) = i1;
  i1 = (OOC_INT32)type;
  *(OOC_INT32*)((_check_pointer(i0, 43610))+8) = i1;
  i1 = (OOC_INT32)semicolon;
  *(OOC_INT32*)((_check_pointer(i0, 43632))+12) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__VarDeclDesc_Accept(OOC_AST__VarDecl varDecl, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)varDecl;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 43752)))), OOC_AST__VisitorDesc_VisitVarDecl)),OOC_AST__VisitorDesc_VisitVarDecl)((OOC_AST__Visitor)i0, (OOC_AST__VarDecl)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_Receiver(OOC_AST__Builder b, OOC_AST__Node lParen, OOC_AST__Node var, OOC_AST__IdentDef ident, OOC_AST__Node colon, OOC_AST__Node type, OOC_AST__Terminal lParenAlias, OOC_AST__NodeList aliasList, OOC_AST__Terminal rParenAlias, OOC_AST__Node rParen) {
  register OOC_INT32 i0,i1;
  OOC_AST__Receiver r;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__Receiver.baseTypes[0]);
  r = (OOC_AST__Receiver)i0;
  i1 = (OOC_INT32)lParen;
  *(OOC_INT32*)(_check_pointer(i0, 45128)) = i1;
  i1 = (OOC_INT32)var;
  *(OOC_INT32*)((_check_pointer(i0, 45153))+4) = i1;
  i1 = (OOC_INT32)ident;
  *(OOC_INT32*)((_check_pointer(i0, 45172))+8) = i1;
  i1 = (OOC_INT32)colon;
  *(OOC_INT32*)((_check_pointer(i0, 45195))+12) = i1;
  i1 = (OOC_INT32)type;
  *(OOC_INT32*)((_check_pointer(i0, 45218))+16) = i1;
  i1 = (OOC_INT32)lParenAlias;
  *(OOC_INT32*)((_check_pointer(i0, 45239))+20) = i1;
  i1 = (OOC_INT32)aliasList;
  *(OOC_INT32*)((_check_pointer(i0, 45274))+24) = i1;
  i1 = (OOC_INT32)rParenAlias;
  *(OOC_INT32*)((_check_pointer(i0, 45305))+28) = i1;
  i1 = (OOC_INT32)rParen;
  *(OOC_INT32*)((_check_pointer(i0, 45340))+32) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__ReceiverDesc_Accept(OOC_AST__Receiver receiver, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)receiver;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 45456)))), OOC_AST__VisitorDesc_VisitReceiver)),OOC_AST__VisitorDesc_VisitReceiver)((OOC_AST__Visitor)i0, (OOC_AST__Receiver)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_ProcDecl(OOC_AST__Builder b, OOC_AST__Node proc, OOC_AST__Node arrow, OOC_AST__Node receiver, OOC_AST__Flags flags, OOC_AST__Node identDef, OOC_AST__Node formalPars, OOC_AST__Node semicolon1, OOC_AST__Body body, OOC_AST__Node semicolon2) {
  register OOC_INT32 i0,i1;
  OOC_AST__ProcDecl pd;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__ProcDecl.baseTypes[0]);
  pd = (OOC_AST__ProcDecl)i0;
  i1 = (OOC_INT32)proc;
  *(OOC_INT32*)(_check_pointer(i0, 47002)) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 47017)))), &_td_OOC_AST__TerminalDesc, 47017));
  i1 = (OOC_INT32)arrow;
  *(OOC_INT32*)((_check_pointer(i0, 47034))+4) = i1;
  i1 = (OOC_INT32)receiver;
  *(OOC_INT32*)((_check_pointer(i0, 47058))+8) = i1;
  i1 = (OOC_INT32)flags;
  *(OOC_INT32*)((_check_pointer(i0, 47088))+12) = i1;
  i1 = (OOC_INT32)identDef;
  *(OOC_INT32*)((_check_pointer(i0, 47112))+16) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 47135)))), &_td_OOC_AST__IdentDefDesc, 47135));
  i1 = (OOC_INT32)formalPars;
  *(OOC_INT32*)((_check_pointer(i0, 47152))+20) = i1;
  i1 = (OOC_INT32)semicolon1;
  *(OOC_INT32*)((_check_pointer(i0, 47186))+24) = i1;
  i1 = (OOC_INT32)body;
  *(OOC_INT32*)((_check_pointer(i0, 47220))+28) = i1;
  i1 = (OOC_INT32)semicolon2;
  *(OOC_INT32*)((_check_pointer(i0, 47242))+32) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__ProcDeclDesc_Accept(OOC_AST__ProcDecl procDecl, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)procDecl;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 47367)))), OOC_AST__VisitorDesc_VisitProcDecl)),OOC_AST__VisitorDesc_VisitProcDecl)((OOC_AST__Visitor)i0, (OOC_AST__ProcDecl)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_ImportList(OOC_AST__Builder b, OOC_AST__Node import, OOC_AST__NodeList imports, OOC_AST__Node semicolon) {
  register OOC_INT32 i0,i1;
  OOC_AST__ImportList il;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__ImportList.baseTypes[0]);
  il = (OOC_AST__ImportList)i0;
  i1 = (OOC_INT32)import;
  *(OOC_INT32*)(_check_pointer(i0, 48118)) = i1;
  i1 = (OOC_INT32)imports;
  *(OOC_INT32*)((_check_pointer(i0, 48144))+4) = i1;
  i1 = (OOC_INT32)semicolon;
  *(OOC_INT32*)((_check_pointer(i0, 48172))+8) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__ImportListDesc_Accept(OOC_AST__ImportList importList, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)importList;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 48301)))), OOC_AST__VisitorDesc_VisitImportList)),OOC_AST__VisitorDesc_VisitImportList)((OOC_AST__Visitor)i0, (OOC_AST__ImportList)i1);
  return;
  ;
}

OOC_AST__Body OOC_AST__BuilderDesc_Body(OOC_AST__Builder b, OOC_AST__NodeList declSeq, OOC_AST__Node begin, OOC_AST__NodeList statmSeq, OOC_AST__Node end, OOC_AST__Node name) {
  register OOC_INT32 i0,i1;
  OOC_AST__Body body;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__Body.baseTypes[0]);
  body = (OOC_AST__Body)i0;
  i1 = (OOC_INT32)declSeq;
  *(OOC_INT32*)(_check_pointer(i0, 49947)) = i1;
  i1 = (OOC_INT32)begin;
  *(OOC_INT32*)((_check_pointer(i0, 49977))+4) = i1;
  i1 = (OOC_INT32)statmSeq;
  *(OOC_INT32*)((_check_pointer(i0, 50003))+8) = i1;
  i1 = (OOC_INT32)end;
  *(OOC_INT32*)((_check_pointer(i0, 50035))+12) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 50048)))), &_td_OOC_AST__TerminalDesc, 50048));
  i1 = (OOC_INT32)name;
  *(OOC_INT32*)((_check_pointer(i0, 50067))+16) = i1;
  return (OOC_AST__Body)i0;
  ;
}

void OOC_AST__BodyDesc_Accept(OOC_AST__Body body, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)body;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 50170)))), OOC_AST__VisitorDesc_VisitBody)),OOC_AST__VisitorDesc_VisitBody)((OOC_AST__Visitor)i0, (OOC_AST__Body)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_Module(OOC_AST__Builder b, OOC_AST__Terminal module, OOC_AST__Node name, OOC_AST__Flags flags, OOC_AST__Node semicolon, OOC_AST__Node importList, OOC_AST__Body body, OOC_AST__Node period, OOC_Scanner_InputBuffer__CharArray moduleName) {
  register OOC_INT32 i0,i1;
  OOC_AST__Module m;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__Module.baseTypes[0]);
  m = (OOC_AST__Module)i0;
  i1 = (OOC_INT32)module;
  *(OOC_INT32*)(_check_pointer(i0, 51427)) = i1;
  i1 = (OOC_INT32)name;
  *(OOC_INT32*)((_check_pointer(i0, 51452))+4) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 51467)))), &_td_OOC_AST__ModuleIdentDesc, 51467));
  i1 = (OOC_INT32)flags;
  *(OOC_INT32*)((_check_pointer(i0, 51486))+8) = i1;
  i1 = (OOC_INT32)semicolon;
  *(OOC_INT32*)((_check_pointer(i0, 51509))+12) = i1;
  i1 = (OOC_INT32)importList;
  *(OOC_INT32*)((_check_pointer(i0, 51540))+16) = i1;
  i1 = (OOC_INT32)body;
  *(OOC_INT32*)((_check_pointer(i0, 51573))+20) = i1;
  i1 = (OOC_INT32)period;
  *(OOC_INT32*)((_check_pointer(i0, 51594))+24) = i1;
  i1 = (OOC_INT32)moduleName;
  *(OOC_INT32*)((_check_pointer(i0, 51619))+28) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__ModuleDesc_Accept(OOC_AST__Module module, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)module;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 51737)))), OOC_AST__VisitorDesc_VisitModule)),OOC_AST__VisitorDesc_VisitModule)((OOC_AST__Visitor)i0, (OOC_AST__Module)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_Operator(OOC_AST__Builder b, OOC_AST__Node left, OOC_AST__Node op, OOC_AST__Node right) {
  register OOC_INT32 i0,i1,i2;
  OOC_AST__Operator o;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__Operator.baseTypes[0]);
  o = (OOC_AST__Operator)i0;
  i1 = (OOC_INT32)left;
  i2 = i1==(OOC_INT32)0;
  if (i2) goto l3;
  *(OOC_INT32*)(_check_pointer(i0, 52552)) = i1;
  goto l4;
l3:
  *(OOC_INT32*)(_check_pointer(i0, 52522)) = (OOC_INT32)0;
l4:
  i1 = (OOC_INT32)op;
  *(OOC_INT32*)((_check_pointer(i0, 52581))+4) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 52592)))), &_td_OOC_AST__TerminalDesc, 52592));
  i1 = (OOC_INT32)right;
  i2 = i1==(OOC_INT32)0;
  if (i2) goto l7;
  *(OOC_INT32*)((_check_pointer(i0, 52667))+8) = i1;
  goto l8;
l7:
  *(OOC_INT32*)((_check_pointer(i0, 52636))+8) = (OOC_INT32)0;
l8:
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__OperatorDesc_Accept(OOC_AST__Operator _operator, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)_operator;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 52789)))), OOC_AST__VisitorDesc_VisitOperator)),OOC_AST__VisitorDesc_VisitOperator)((OOC_AST__Visitor)i0, (OOC_AST__Operator)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_Factor(OOC_AST__Builder b, OOC_AST__Node lParen, OOC_AST__Node expr, OOC_AST__Node rParen) {
  register OOC_INT32 i0,i1;
  OOC_AST__Factor f;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__Factor.baseTypes[0]);
  f = (OOC_AST__Factor)i0;
  i1 = (OOC_INT32)lParen;
  *(OOC_INT32*)(_check_pointer(i0, 53362)) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 53381)))), &_td_OOC_AST__TerminalDesc, 53381));
  i1 = (OOC_INT32)expr;
  *(OOC_INT32*)((_check_pointer(i0, 53397))+4) = i1;
  i1 = (OOC_INT32)rParen;
  *(OOC_INT32*)((_check_pointer(i0, 53418))+8) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 53437)))), &_td_OOC_AST__TerminalDesc, 53437));
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__FactorDesc_Accept(OOC_AST__Factor factor, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)factor;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 53538)))), OOC_AST__VisitorDesc_VisitFactor)),OOC_AST__VisitorDesc_VisitFactor)((OOC_AST__Visitor)i0, (OOC_AST__Factor)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_Set(OOC_AST__Builder b, OOC_AST__Node type, OOC_AST__Node lBrace, OOC_AST__NodeList elementList, OOC_AST__Node rBrace) {
  register OOC_INT32 i0,i1;
  OOC_AST__Set s;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__Set.baseTypes[0]);
  s = (OOC_AST__Set)i0;
  i1 = (OOC_INT32)type;
  *(OOC_INT32*)(_check_pointer(i0, 54451)) = i1;
  i1 = (OOC_INT32)lBrace;
  *(OOC_INT32*)((_check_pointer(i0, 54472))+4) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 54491)))), &_td_OOC_AST__TerminalDesc, 54491));
  i1 = (OOC_INT32)elementList;
  *(OOC_INT32*)((_check_pointer(i0, 54507))+8) = i1;
  i1 = (OOC_INT32)rBrace;
  *(OOC_INT32*)((_check_pointer(i0, 54542))+12) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 54561)))), &_td_OOC_AST__TerminalDesc, 54561));
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__SetDesc_Accept(OOC_AST__Set set, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)set;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 54653)))), OOC_AST__VisitorDesc_VisitSet)),OOC_AST__VisitorDesc_VisitSet)((OOC_AST__Visitor)i0, (OOC_AST__Set)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_ArrayIndex(OOC_AST__Builder b, OOC_AST__Node design, OOC_AST__Node lBrak, OOC_AST__NodeList indices, OOC_AST__Node rBrak) {
  register OOC_INT32 i0,i1;
  OOC_AST__ArrayIndex ai;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__ArrayIndex.baseTypes[0]);
  ai = (OOC_AST__ArrayIndex)i0;
  i1 = (OOC_INT32)design;
  *(OOC_INT32*)(_check_pointer(i0, 55363)) = i1;
  i1 = (OOC_INT32)lBrak;
  *(OOC_INT32*)((_check_pointer(i0, 55389))+4) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 55406)))), &_td_OOC_AST__TerminalDesc, 55406));
  i1 = (OOC_INT32)indices;
  *(OOC_INT32*)((_check_pointer(i0, 55423))+8) = i1;
  i1 = (OOC_INT32)rBrak;
  *(OOC_INT32*)((_check_pointer(i0, 55451))+12) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 55468)))), &_td_OOC_AST__TerminalDesc, 55468));
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__ArrayIndexDesc_Accept(OOC_AST__ArrayIndex arrayIndex, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)arrayIndex;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 55582)))), OOC_AST__VisitorDesc_VisitArrayIndex)),OOC_AST__VisitorDesc_VisitArrayIndex)((OOC_AST__Visitor)i0, (OOC_AST__ArrayIndex)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_FunctionCall(OOC_AST__Builder b, OOC_AST__Node design, OOC_AST__Node lParen, OOC_AST__NodeList arguments, OOC_AST__Node rParen) {
  register OOC_INT32 i0,i1;
  OOC_AST__FunctionCall fc;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__FunctionCall.baseTypes[0]);
  fc = (OOC_AST__FunctionCall)i0;
  i1 = (OOC_INT32)design;
  *(OOC_INT32*)(_check_pointer(i0, 56658)) = i1;
  i1 = (OOC_INT32)lParen;
  *(OOC_INT32*)((_check_pointer(i0, 56684))+4) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 56703)))), &_td_OOC_AST__TerminalDesc, 56703));
  i1 = (OOC_INT32)arguments;
  *(OOC_INT32*)((_check_pointer(i0, 56720))+8) = i1;
  i1 = (OOC_INT32)rParen;
  *(OOC_INT32*)((_check_pointer(i0, 56752))+12) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 56771)))), &_td_OOC_AST__TerminalDesc, 56771));
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__FunctionCallDesc_Accept(OOC_AST__FunctionCall functionCall, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)functionCall;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 56891)))), OOC_AST__VisitorDesc_VisitFunctionCall)),OOC_AST__VisitorDesc_VisitFunctionCall)((OOC_AST__Visitor)i0, (OOC_AST__FunctionCall)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_Assignment(OOC_AST__Builder b, OOC_AST__Node assignment) {
  register OOC_INT32 i0,i1;
  OOC_AST__Assignment a;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__Assignment.baseTypes[0]);
  a = (OOC_AST__Assignment)i0;
  i1 = (OOC_INT32)assignment;
  *(OOC_INT32*)(_check_pointer(i0, 57360)) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 57387)))), &_td_OOC_AST__OperatorDesc, 57387));
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__AssignmentDesc_Accept(OOC_AST__Assignment assignment, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)assignment;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 57500)))), OOC_AST__VisitorDesc_VisitAssignment)),OOC_AST__VisitorDesc_VisitAssignment)((OOC_AST__Visitor)i0, (OOC_AST__Assignment)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_ProcedureCall(OOC_AST__Builder b, OOC_AST__Node call) {
  register OOC_INT32 i0,i1;
  OOC_AST__ProcedureCall p;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__ProcedureCall.baseTypes[0]);
  p = (OOC_AST__ProcedureCall)i0;
  i1 = (OOC_INT32)call;
  *(OOC_INT32*)(_check_pointer(i0, 58049)) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__ProcedureCallDesc_Accept(OOC_AST__ProcedureCall procedureCall, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)procedureCall;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 58176)))), OOC_AST__VisitorDesc_VisitProcedureCall)),OOC_AST__VisitorDesc_VisitProcedureCall)((OOC_AST__Visitor)i0, (OOC_AST__ProcedureCall)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_IfStatm(OOC_AST__Builder b, OOC_AST__NodeList guardList, OOC_AST__Node _else, OOC_AST__NodeList elseStatmSeq, OOC_AST__Node end) {
  register OOC_INT32 i0,i1,i2;
  OOC_AST__IfStatm i;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__IfStatm.baseTypes[0]);
  i = (OOC_AST__IfStatm)i0;
  i1 = (OOC_INT32)guardList;
  *(OOC_INT32*)(_check_pointer(i0, 59377)) = i1;
  i1 = (OOC_INT32)_else;
  *(OOC_INT32*)((_check_pointer(i0, 59408))+4) = i1;
  i1 = (OOC_INT32)elseStatmSeq;
  i2 = i1!=0;
  if (i2) goto l3;
  *(OOC_INT32*)((_check_pointer(i0, 59512))+8) = 0;
  goto l4;
l3:
  *(OOC_INT32*)((_check_pointer(i0, 59464))+8) = i1;
l4:
  i1 = (OOC_INT32)end;
  *(OOC_INT32*)((_check_pointer(i0, 59549))+12) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__IfStatmDesc_Accept(OOC_AST__IfStatm ifStatm, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)ifStatm;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 59656)))), OOC_AST__VisitorDesc_VisitIfStatm)),OOC_AST__VisitorDesc_VisitIfStatm)((OOC_AST__Visitor)i0, (OOC_AST__IfStatm)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_CaseStatm(OOC_AST__Builder b, OOC_AST__Node _case, OOC_AST__Node expr, OOC_AST__Node of, OOC_AST__NodeList caseList, OOC_AST__Node _else, OOC_AST__NodeList elseStatmSeq, OOC_AST__Node end) {
  register OOC_INT32 i0,i1,i2;
  OOC_AST__CaseStatm c;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__CaseStatm.baseTypes[0]);
  c = (OOC_AST__CaseStatm)i0;
  i1 = (OOC_INT32)_case;
  *(OOC_INT32*)(_check_pointer(i0, 61362)) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 61377)))), &_td_OOC_AST__TerminalDesc, 61377));
  i1 = (OOC_INT32)expr;
  *(OOC_INT32*)((_check_pointer(i0, 61393))+4) = i1;
  i1 = (OOC_INT32)of;
  *(OOC_INT32*)((_check_pointer(i0, 61414))+8) = i1;
  i1 = (OOC_INT32)caseList;
  *(OOC_INT32*)((_check_pointer(i0, 61431))+12) = i1;
  i1 = (OOC_INT32)_else;
  *(OOC_INT32*)((_check_pointer(i0, 61460))+16) = i1;
  i1 = (OOC_INT32)elseStatmSeq;
  i2 = i1==0;
  if (i2) goto l3;
  *(OOC_INT32*)((_check_pointer(i0, 61555))+20) = i1;
  goto l4;
l3:
  *(OOC_INT32*)((_check_pointer(i0, 61516))+20) = 0;
l4:
  i1 = (OOC_INT32)end;
  *(OOC_INT32*)((_check_pointer(i0, 61601))+24) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__CaseStatmDesc_Accept(OOC_AST__CaseStatm caseStatm, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)caseStatm;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 61714)))), OOC_AST__VisitorDesc_VisitCaseStatm)),OOC_AST__VisitorDesc_VisitCaseStatm)((OOC_AST__Visitor)i0, (OOC_AST__CaseStatm)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_WhileStatm(OOC_AST__Builder b, OOC_AST__Node _while, OOC_AST__Node guard, OOC_AST__Node _do, OOC_AST__NodeList statmSeq, OOC_AST__Node end) {
  register OOC_INT32 i0,i1;
  OOC_AST__WhileStatm w;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__WhileStatm.baseTypes[0]);
  w = (OOC_AST__WhileStatm)i0;
  i1 = (OOC_INT32)_while;
  *(OOC_INT32*)(_check_pointer(i0, 62202)) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 62219)))), &_td_OOC_AST__TerminalDesc, 62219));
  i1 = (OOC_INT32)guard;
  *(OOC_INT32*)((_check_pointer(i0, 62235))+4) = i1;
  i1 = (OOC_INT32)_do;
  *(OOC_INT32*)((_check_pointer(i0, 62258))+8) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 62269)))), &_td_OOC_AST__TerminalDesc, 62269));
  i1 = (OOC_INT32)statmSeq;
  *(OOC_INT32*)((_check_pointer(i0, 62285))+12) = i1;
  i1 = (OOC_INT32)end;
  *(OOC_INT32*)((_check_pointer(i0, 62314))+16) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 62327)))), &_td_OOC_AST__TerminalDesc, 62327));
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__WhileStatmDesc_Accept(OOC_AST__WhileStatm whileStatm, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)whileStatm;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 62440)))), OOC_AST__VisitorDesc_VisitWhileStatm)),OOC_AST__VisitorDesc_VisitWhileStatm)((OOC_AST__Visitor)i0, (OOC_AST__WhileStatm)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_RepeatStatm(OOC_AST__Builder b, OOC_AST__Node repeat, OOC_AST__NodeList statmSeq, OOC_AST__Node until, OOC_AST__Node expr) {
  register OOC_INT32 i0,i1;
  OOC_AST__RepeatStatm r;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__RepeatStatm.baseTypes[0]);
  r = (OOC_AST__RepeatStatm)i0;
  i1 = (OOC_INT32)repeat;
  *(OOC_INT32*)(_check_pointer(i0, 62894)) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 62913)))), &_td_OOC_AST__TerminalDesc, 62913));
  i1 = (OOC_INT32)statmSeq;
  *(OOC_INT32*)((_check_pointer(i0, 62929))+4) = i1;
  i1 = (OOC_INT32)until;
  *(OOC_INT32*)((_check_pointer(i0, 62958))+8) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 62975)))), &_td_OOC_AST__TerminalDesc, 62975));
  i1 = (OOC_INT32)expr;
  *(OOC_INT32*)((_check_pointer(i0, 62991))+12) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__RepeatStatmDesc_Accept(OOC_AST__RepeatStatm repeatStatm, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)repeatStatm;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 63112)))), OOC_AST__VisitorDesc_VisitRepeatStatm)),OOC_AST__VisitorDesc_VisitRepeatStatm)((OOC_AST__Visitor)i0, (OOC_AST__RepeatStatm)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_ForStatm(OOC_AST__Builder b, OOC_AST__Node _for, OOC_AST__Node ident, OOC_AST__Node becomes, OOC_AST__Node startValue, OOC_AST__Node to, OOC_AST__Node endValue, OOC_AST__Node by, OOC_AST__Node step, OOC_AST__Node _do, OOC_AST__NodeList statmSeq, OOC_AST__Node end) {
  register OOC_INT32 i0,i1,i2;
  OOC_AST__ForStatm f;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__ForStatm.baseTypes[0]);
  f = (OOC_AST__ForStatm)i0;
  i1 = (OOC_INT32)_for;
  *(OOC_INT32*)(_check_pointer(i0, 64060)) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 64073)))), &_td_OOC_AST__TerminalDesc, 64073));
  i1 = (OOC_INT32)ident;
  *(OOC_INT32*)((_check_pointer(i0, 64089))+4) = i1;
  i1 = (OOC_INT32)becomes;
  *(OOC_INT32*)((_check_pointer(i0, 64112))+8) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 64133)))), &_td_OOC_AST__TerminalDesc, 64133));
  i1 = (OOC_INT32)startValue;
  *(OOC_INT32*)((_check_pointer(i0, 64149))+12) = i1;
  i1 = (OOC_INT32)to;
  *(OOC_INT32*)((_check_pointer(i0, 64182))+16) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 64193)))), &_td_OOC_AST__TerminalDesc, 64193));
  i1 = (OOC_INT32)endValue;
  *(OOC_INT32*)((_check_pointer(i0, 64209))+20) = i1;
  i1 = (OOC_INT32)step;
  i2 = i1==0;
  if (i2) goto l3;
  i2 = (OOC_INT32)by;
  *(OOC_INT32*)((_check_pointer(i0, 64316))+24) = (_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 64327)))), &_td_OOC_AST__TerminalDesc, 64327));
  *(OOC_INT32*)((_check_pointer(i0, 64345))+28) = i1;
  goto l4;
l3:
  *(OOC_INT32*)((_check_pointer(i0, 64265))+24) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 64285))+28) = 0;
l4:
  i1 = (OOC_INT32)_do;
  *(OOC_INT32*)((_check_pointer(i0, 64375))+32) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 64386)))), &_td_OOC_AST__TerminalDesc, 64386));
  i1 = (OOC_INT32)statmSeq;
  *(OOC_INT32*)((_check_pointer(i0, 64402))+36) = i1;
  i1 = (OOC_INT32)end;
  *(OOC_INT32*)((_check_pointer(i0, 64431))+40) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 64444)))), &_td_OOC_AST__TerminalDesc, 64444));
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__ForStatmDesc_Accept(OOC_AST__ForStatm forStatm, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)forStatm;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 64551)))), OOC_AST__VisitorDesc_VisitForStatm)),OOC_AST__VisitorDesc_VisitForStatm)((OOC_AST__Visitor)i0, (OOC_AST__ForStatm)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_LoopStatm(OOC_AST__Builder b, OOC_AST__Node loop, OOC_AST__NodeList statmSeq, OOC_AST__Node end) {
  register OOC_INT32 i0,i1;
  OOC_AST__LoopStatm l;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__LoopStatm.baseTypes[0]);
  l = (OOC_AST__LoopStatm)i0;
  i1 = (OOC_INT32)loop;
  *(OOC_INT32*)(_check_pointer(i0, 64934)) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 64949)))), &_td_OOC_AST__TerminalDesc, 64949));
  i1 = (OOC_INT32)statmSeq;
  *(OOC_INT32*)((_check_pointer(i0, 64965))+4) = i1;
  i1 = (OOC_INT32)end;
  *(OOC_INT32*)((_check_pointer(i0, 64994))+8) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 65007)))), &_td_OOC_AST__TerminalDesc, 65007));
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__LoopStatmDesc_Accept(OOC_AST__LoopStatm loopStatm, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)loopStatm;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 65117)))), OOC_AST__VisitorDesc_VisitLoopStatm)),OOC_AST__VisitorDesc_VisitLoopStatm)((OOC_AST__Visitor)i0, (OOC_AST__LoopStatm)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_WithStatm(OOC_AST__Builder b, OOC_AST__NodeList guardList, OOC_AST__Node _else, OOC_AST__NodeList elseStatmSeq, OOC_AST__Node end) {
  register OOC_INT32 i0,i1,i2;
  OOC_AST__WithStatm w;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__WithStatm.baseTypes[0]);
  w = (OOC_AST__WithStatm)i0;
  i1 = (OOC_INT32)guardList;
  *(OOC_INT32*)(_check_pointer(i0, 66357)) = i1;
  i1 = (OOC_INT32)_else;
  *(OOC_INT32*)((_check_pointer(i0, 66388))+4) = i1;
  i1 = (OOC_INT32)elseStatmSeq;
  i2 = i1!=0;
  if (i2) goto l3;
  *(OOC_INT32*)((_check_pointer(i0, 66492))+8) = 0;
  goto l4;
l3:
  *(OOC_INT32*)((_check_pointer(i0, 66444))+8) = i1;
l4:
  i1 = (OOC_INT32)end;
  *(OOC_INT32*)((_check_pointer(i0, 66529))+12) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__WithStatmDesc_Accept(OOC_AST__WithStatm withStatm, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)withStatm;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 66642)))), OOC_AST__VisitorDesc_VisitWithStatm)),OOC_AST__VisitorDesc_VisitWithStatm)((OOC_AST__Visitor)i0, (OOC_AST__WithStatm)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_ExitStatm(OOC_AST__Builder b, OOC_AST__Node exit) {
  register OOC_INT32 i0,i1;
  OOC_AST__ExitStatm e;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__ExitStatm.baseTypes[0]);
  e = (OOC_AST__ExitStatm)i0;
  i1 = (OOC_INT32)exit;
  *(OOC_INT32*)(_check_pointer(i0, 66896)) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 66911)))), &_td_OOC_AST__TerminalDesc, 66911));
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__ExitStatmDesc_Accept(OOC_AST__ExitStatm exitStatm, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)exitStatm;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 67021)))), OOC_AST__VisitorDesc_VisitExitStatm)),OOC_AST__VisitorDesc_VisitExitStatm)((OOC_AST__Visitor)i0, (OOC_AST__ExitStatm)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_ReturnStatm(OOC_AST__Builder b, OOC_AST__Node _return, OOC_AST__Node expr) {
  register OOC_INT32 i0,i1;
  OOC_AST__ReturnStatm r;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__ReturnStatm.baseTypes[0]);
  r = (OOC_AST__ReturnStatm)i0;
  i1 = (OOC_INT32)_return;
  *(OOC_INT32*)(_check_pointer(i0, 67422)) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 67441)))), &_td_OOC_AST__TerminalDesc, 67441));
  i1 = (OOC_INT32)expr;
  *(OOC_INT32*)((_check_pointer(i0, 67457))+4) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__ReturnStatmDesc_Accept(OOC_AST__ReturnStatm returnStatm, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)returnStatm;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 67578)))), OOC_AST__VisitorDesc_VisitReturnStatm)),OOC_AST__VisitorDesc_VisitReturnStatm)((OOC_AST__Visitor)i0, (OOC_AST__ReturnStatm)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_Catch(OOC_AST__Builder b, OOC_AST__Node _catch, OOC_AST__Node type, OOC_AST__Node lParen, OOC_AST__Node ident, OOC_AST__Node rParen, OOC_AST__Node colon, OOC_AST__NodeList statmSeq) {
  register OOC_INT32 i0,i1,i2;
  OOC_AST__Catch c;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__Catch.baseTypes[0]);
  c = (OOC_AST__Catch)i0;
  i1 = (OOC_INT32)_catch;
  *(OOC_INT32*)(_check_pointer(i0, 68327)) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 68343)))), &_td_OOC_AST__TerminalDesc, 68343));
  i1 = (OOC_INT32)type;
  *(OOC_INT32*)((_check_pointer(i0, 68359))+4) = i1;
  i1 = (OOC_INT32)lParen;
  *(OOC_INT32*)((_check_pointer(i0, 68379))+8) = i1;
  i1 = (OOC_INT32)ident;
  i2 = i1==0;
  if (i2) goto l3;
  *(OOC_INT32*)((_check_pointer(i0, 68462))+12) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 68478)))), &_td_OOC_AST__TerminalDesc, 68478));
  goto l4;
l3:
  *(OOC_INT32*)((_check_pointer(i0, 68431))+12) = 0;
l4:
  i1 = (OOC_INT32)rParen;
  *(OOC_INT32*)((_check_pointer(i0, 68503))+16) = i1;
  i1 = (OOC_INT32)colon;
  *(OOC_INT32*)((_check_pointer(i0, 68527))+20) = i1;
  i1 = (OOC_INT32)statmSeq;
  *(OOC_INT32*)((_check_pointer(i0, 68549))+24) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__CatchDesc_Accept(OOC_AST__Catch _catch, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)_catch;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 68660)))), OOC_AST__VisitorDesc_VisitCatch)),OOC_AST__VisitorDesc_VisitCatch)((OOC_AST__Visitor)i0, (OOC_AST__Catch)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_TryStatm(OOC_AST__Builder b, OOC_AST__Node _try, OOC_AST__NodeList statmSeq, OOC_AST__NodeList catchList, OOC_AST__Node end) {
  register OOC_INT32 i0,i1;
  OOC_AST__TryStatm t;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__TryStatm.baseTypes[0]);
  t = (OOC_AST__TryStatm)i0;
  i1 = (OOC_INT32)_try;
  *(OOC_INT32*)(_check_pointer(i0, 69307)) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 69319)))), &_td_OOC_AST__TerminalDesc, 69319));
  i1 = (OOC_INT32)statmSeq;
  *(OOC_INT32*)((_check_pointer(i0, 69335))+4) = i1;
  i1 = (OOC_INT32)catchList;
  *(OOC_INT32*)((_check_pointer(i0, 69363))+8) = i1;
  i1 = (OOC_INT32)end;
  *(OOC_INT32*)((_check_pointer(i0, 69393))+12) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 69405)))), &_td_OOC_AST__TerminalDesc, 69405));
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__TryStatmDesc_Accept(OOC_AST__TryStatm tryStatm, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)tryStatm;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 69513)))), OOC_AST__VisitorDesc_VisitTryStatm)),OOC_AST__VisitorDesc_VisitTryStatm)((OOC_AST__Visitor)i0, (OOC_AST__TryStatm)i1);
  return;
  ;
}

OOC_AST__Flags OOC_AST__BuilderDesc_Flags(OOC_AST__Builder b, OOC_INT8 context, OOC_AST__Node lBrak, OOC_AST__NodeList flagList, OOC_AST__Node rBrak) {
  register OOC_INT32 i0,i1;
  OOC_AST__Flags f;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__Flags.baseTypes[0]);
  f = (OOC_AST__Flags)i0;
  i1 = context;
  *(OOC_INT8*)(_check_pointer(i0, 69738)) = i1;
  i1 = (OOC_INT32)lBrak;
  *(OOC_INT32*)((_check_pointer(i0, 69765))+4) = i1;
  i1 = (OOC_INT32)flagList;
  *(OOC_INT32*)((_check_pointer(i0, 69788))+8) = i1;
  i1 = (OOC_INT32)rBrak;
  *(OOC_INT32*)((_check_pointer(i0, 69817))+12) = i1;
  return (OOC_AST__Flags)i0;
  ;
}

OOC_CHAR8 OOC_AST__BuilderDesc_ProcWithoutBody(OOC_AST__Builder b, OOC_AST__Node moduleFlags, OOC_AST__Node procFlags) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_INT32 i;
  OOC_AST__Node n;

  i0 = (OOC_INT32)moduleFlags;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3;
  i0=0u;
  goto l5;
l3:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 70364)))), &_td_OOC_AST__FlagsDesc, 70364)), 70370))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 70380))+4);
  i0 = _check_pointer(i0, 70383);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 70383))*4);
  i0 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 70387)))), &_td_OOC_AST__TerminalDesc));
  
l5:
  if (i0) goto l7;
  return 0u;
  goto l26;
l7:
  i0 = (OOC_INT32)procFlags;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l25;
  i = 0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 70644)))), &_td_OOC_AST__FlagsDesc, 70644)), 70650))+8);
  i1 = *(OOC_INT32*)(_check_pointer(i1, 70660));
  i1 = 0<i1;
  if (!i1) goto l25;
  i1=0;
l12_loop:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 70695)))), &_td_OOC_AST__FlagsDesc, 70695)), 70701))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 70711))+4);
  i2 = _check_pointer(i2, 70714);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i1, i3, OOC_UINT32, 70714))*4);
  n = (OOC_AST__Node)i2;
  i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 70735)))), &_td_OOC_AST__TerminalDesc);
  if (i3) goto l15;
  i2=0u;
  goto l17;
l15:
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 70753)))), &_td_OOC_AST__TerminalDesc, 70753)), 70762));
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 70767))+8);
  i2 = (
  _cmp8((const void*)(_check_pointer(i2, 70772)),(const void*)"HAS_BODY"))==0;
  
l17:
  if (!i2) goto l19;
  return 0u;
l19:
  i1 = i1+2;
  i = i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 70644)))), &_td_OOC_AST__FlagsDesc, 70644)), 70650))+8);
  i2 = *(OOC_INT32*)(_check_pointer(i2, 70660));
  i2 = i1<i2;
  if (i2) goto l12_loop;
l25:
  return 1u;
l26:
  _failed_function(69885); return 0;
  ;
}

void OOC_AST__FlagsDesc_Accept(OOC_AST__Flags flags, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)flags;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 71016)))), OOC_AST__VisitorDesc_VisitFlags)),OOC_AST__VisitorDesc_VisitFlags)((OOC_AST__Visitor)i0, (OOC_AST__Flags)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_ProcIdFlag(OOC_AST__Builder b, OOC_AST__Node procId, OOC_AST__Node equal, OOC_AST__Node number) {
  register OOC_INT32 i0,i1;
  OOC_AST__ProcIdFlag pid;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__ProcIdFlag.baseTypes[0]);
  pid = (OOC_AST__ProcIdFlag)i0;
  i1 = (OOC_INT32)procId;
  *(OOC_INT32*)(_check_pointer(i0, 71182)) = i1;
  i1 = (OOC_INT32)equal;
  *(OOC_INT32*)((_check_pointer(i0, 71209))+4) = i1;
  i1 = (OOC_INT32)number;
  *(OOC_INT32*)((_check_pointer(i0, 71234))+8) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__ProcIdFlagDesc_Accept(OOC_AST__ProcIdFlag procIdFlag, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)procIdFlag;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 71358)))), OOC_AST__VisitorDesc_VisitProcIdFlag)),OOC_AST__VisitorDesc_VisitProcIdFlag)((OOC_AST__Visitor)i0, (OOC_AST__ProcIdFlag)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_ModuleFlags(OOC_AST__Builder b, OOC_AST__Node external, OOC_AST__Node callConv, OOC_AST__NodeList moduleFlags, OOC_AST__Node semicolon, OOC_AST__Node link, OOC_AST__NodeList linkSections, OOC_AST__Node end) {
  register OOC_INT32 i0,i1;
  OOC_AST__ModuleFlags mf;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__ModuleFlags.baseTypes[0]);
  mf = (OOC_AST__ModuleFlags)i0;
  i1 = (OOC_INT32)external;
  *(OOC_INT32*)(_check_pointer(i0, 71652)) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 71675)))), &_td_OOC_AST__TerminalDesc, 71675));
  i1 = (OOC_INT32)callConv;
  *(OOC_INT32*)((_check_pointer(i0, 71692))+4) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 71715)))), &_td_OOC_AST__TerminalDesc, 71715));
  i1 = (OOC_INT32)moduleFlags;
  *(OOC_INT32*)((_check_pointer(i0, 71732))+8) = i1;
  i1 = (OOC_INT32)semicolon;
  *(OOC_INT32*)((_check_pointer(i0, 71768))+12) = i1;
  i1 = (OOC_INT32)link;
  *(OOC_INT32*)((_check_pointer(i0, 71800))+16) = i1;
  i1 = (OOC_INT32)linkSections;
  *(OOC_INT32*)((_check_pointer(i0, 71822))+20) = i1;
  i1 = (OOC_INT32)end;
  *(OOC_INT32*)((_check_pointer(i0, 71860))+24) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__ModuleFlagsDesc_Accept(OOC_AST__ModuleFlags moduleFlags, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)moduleFlags;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 71980)))), OOC_AST__VisitorDesc_VisitModuleFlags)),OOC_AST__VisitorDesc_VisitModuleFlags)((OOC_AST__Visitor)i0, (OOC_AST__ModuleFlags)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_LinkFileFlag(OOC_AST__Builder b, OOC_AST__Node file, OOC_AST__Node fileName, OOC_AST__Node addOption, OOC_AST__Node prefixOpt, OOC_AST__Node comma, OOC_AST__Node suffixOpt) {
  register OOC_INT32 i0,i1,i2;
  OOC_AST__LinkFileFlag lff;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__LinkFileFlag.baseTypes[0]);
  lff = (OOC_AST__LinkFileFlag)i0;
  i1 = (OOC_INT32)file;
  *(OOC_INT32*)(_check_pointer(i0, 72195)) = i1;
  i1 = (OOC_INT32)fileName;
  *(OOC_INT32*)((_check_pointer(i0, 72218))+4) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 72241)))), &_td_OOC_AST__TerminalDesc, 72241));
  i1 = (OOC_INT32)addOption;
  *(OOC_INT32*)((_check_pointer(i0, 72259))+8) = i1;
  i1 = (OOC_INT32)prefixOpt;
  i2 = i1==0;
  if (i2) goto l3;
  *(OOC_INT32*)((_check_pointer(i0, 72361))+12) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 72386)))), &_td_OOC_AST__TerminalDesc, 72386));
  goto l4;
l3:
  *(OOC_INT32*)((_check_pointer(i0, 72324))+12) = 0;
l4:
  i1 = (OOC_INT32)comma;
  *(OOC_INT32*)((_check_pointer(i0, 72412))+16) = i1;
  i1 = (OOC_INT32)suffixOpt;
  i2 = i1==0;
  if (i2) goto l7;
  *(OOC_INT32*)((_check_pointer(i0, 72506))+20) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 72531)))), &_td_OOC_AST__TerminalDesc, 72531));
  goto l8;
l7:
  *(OOC_INT32*)((_check_pointer(i0, 72469))+20) = 0;
l8:
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__LinkFileFlagDesc_Accept(OOC_AST__LinkFileFlag linkFileFlag, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)linkFileFlag;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 72660)))), OOC_AST__VisitorDesc_VisitLinkFileFlag)),OOC_AST__VisitorDesc_VisitLinkFileFlag)((OOC_AST__Visitor)i0, (OOC_AST__LinkFileFlag)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_LinkObjFlag(OOC_AST__Builder b, OOC_AST__Node obj, OOC_AST__Node fileName) {
  register OOC_INT32 i0,i1;
  OOC_AST__LinkObjFlag lof;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__LinkObjFlag.baseTypes[0]);
  lof = (OOC_AST__LinkObjFlag)i0;
  i1 = (OOC_INT32)obj;
  *(OOC_INT32*)(_check_pointer(i0, 72834)) = i1;
  i1 = (OOC_INT32)fileName;
  *(OOC_INT32*)((_check_pointer(i0, 72855))+4) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__LinkObjFlagDesc_Accept(OOC_AST__LinkObjFlag linkObjFlag, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)linkObjFlag;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 72986)))), OOC_AST__VisitorDesc_VisitLinkObjFlag)),OOC_AST__VisitorDesc_VisitLinkObjFlag)((OOC_AST__Visitor)i0, (OOC_AST__LinkObjFlag)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_LinkLibFlag(OOC_AST__Builder b, OOC_AST__Node lib, OOC_AST__Node libName, OOC_AST__Node lParen, OOC_AST__NodeList dependencies, OOC_AST__Node rParen, OOC_AST__Node addOption, OOC_AST__Node prefixOpt, OOC_AST__Node comma, OOC_AST__Node suffixOpt) {
  register OOC_INT32 i0,i1,i2;
  OOC_AST__LinkLibFlag llf;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__LinkLibFlag.baseTypes[0]);
  llf = (OOC_AST__LinkLibFlag)i0;
  i1 = (OOC_INT32)lib;
  *(OOC_INT32*)(_check_pointer(i0, 73279)) = i1;
  i1 = (OOC_INT32)libName;
  *(OOC_INT32*)((_check_pointer(i0, 73300))+4) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 73321)))), &_td_OOC_AST__TerminalDesc, 73321));
  i1 = (OOC_INT32)lParen;
  *(OOC_INT32*)((_check_pointer(i0, 73339))+8) = i1;
  i1 = (OOC_INT32)dependencies;
  i2 = i1==0;
  if (i2) goto l3;
  *(OOC_INT32*)((_check_pointer(i0, 73442))+12) = i1;
  goto l4;
l3:
  *(OOC_INT32*)((_check_pointer(i0, 73401))+12) = 0;
l4:
  i1 = (OOC_INT32)rParen;
  *(OOC_INT32*)((_check_pointer(i0, 73490))+16) = i1;
  i1 = (OOC_INT32)addOption;
  *(OOC_INT32*)((_check_pointer(i0, 73517))+20) = i1;
  i1 = (OOC_INT32)prefixOpt;
  i2 = i1==0;
  if (i2) goto l7;
  *(OOC_INT32*)((_check_pointer(i0, 73619))+24) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 73644)))), &_td_OOC_AST__TerminalDesc, 73644));
  goto l8;
l7:
  *(OOC_INT32*)((_check_pointer(i0, 73582))+24) = 0;
l8:
  i1 = (OOC_INT32)comma;
  *(OOC_INT32*)((_check_pointer(i0, 73670))+28) = i1;
  i1 = (OOC_INT32)suffixOpt;
  i2 = i1==0;
  if (i2) goto l11;
  *(OOC_INT32*)((_check_pointer(i0, 73764))+32) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 73789)))), &_td_OOC_AST__TerminalDesc, 73789));
  goto l12;
l11:
  *(OOC_INT32*)((_check_pointer(i0, 73727))+32) = 0;
l12:
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__LinkLibFlagDesc_Accept(OOC_AST__LinkLibFlag linkLibFlag, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)linkLibFlag;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 73915)))), OOC_AST__VisitorDesc_VisitLinkLibFlag)),OOC_AST__VisitorDesc_VisitLinkLibFlag)((OOC_AST__Visitor)i0, (OOC_AST__LinkLibFlag)i1);
  return;
  ;
}

void OOC_OOC_AST_init(void) {

  return;
  ;
}

/* --- */
