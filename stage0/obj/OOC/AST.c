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
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  OOC_INT32 i;

  i0 = (OOC_INT32)nl;
  i = 0;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 16898));
  i2 = 0<i1;
  if (!i2) goto l11;
  i2 = (OOC_INT32)v;
  i3=0;
l3_loop:
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16921))+4);
  i4 = _check_pointer(i4, 16924);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 16924))*4);
  i4 = i4!=0;
  if (!i4) goto l6;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16950))+4);
  i4 = _check_pointer(i4, 16953);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16950))+4);
  i6 = _check_pointer(i6, 16953);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i3, i7, OOC_UINT32, 16953))*4);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 16953))*4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 16956)))), OOC_AST__NodeDesc_Accept)),OOC_AST__NodeDesc_Accept)((OOC_AST__Node)i4, (OOC_AST__Visitor)i2);
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

void OOC_AST__VisitorDesc_VisitIterateStatm(OOC_AST__Visitor v, OOC_AST__IterateStatm iterStatm) {

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
  *(OOC_INT32*)(_check_pointer(i0, 21152)) = 0;
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
  *(OOC_INT32*)(_check_pointer(i0, 21403)) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 21426))+4) = ((OOC_INT32)RT0__NewObject(_td_OOC_AST__NodeArray.baseTypes[0], 8));
  return;
  ;
}

void OOC_AST__BuilderDesc_SetModuleName(OOC_AST__Builder b, const OOC_CHAR8 name__ref[], OOC_LEN name_0d) {
  register OOC_INT32 i0,i1;
  OOC_ALLOCATE_VPAR(name,OOC_CHAR8 ,name_0d)

  OOC_INITIALIZE_VPAR(name__ref,name,OOC_CHAR8 ,name_0d)
  i0 = (OOC_INT32)b;
  i1 = Strings__Length((void*)(OOC_INT32)name, name_0d);
  *(OOC_INT32*)(_check_pointer(i0, 21713)) = ((OOC_INT32)RT0__NewObject(_td_OOC_Scanner_InputBuffer__CharArray.baseTypes[0], (i1+1)));
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 21778));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 21778));
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 21798)), 0);
  _copy_8((const void*)(OOC_INT32)name,(void*)(_check_pointer(i1, 21798)),i0);
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
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22209))+4);
  i2 = *(OOC_INT32*)(_check_pointer(i0, 22194));
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 22212)), 0);
  i1 = i2==i1;
  if (!i1) goto l11;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22244))+4);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 22247)), 0);
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__NodeArray.baseTypes[0], (i1*2));
  _new = (OOC_AST__NodeArray)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22281))+4);
  i = 0;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 22284)), 0);
  i3 = 0<i2;
  if (!i3) goto l10;
  i3=0;
l5_loop:
  i4 = _check_pointer(i1, 22303);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22312))+4);
  i6 = _check_pointer(i6, 22315);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i3, i7, OOC_UINT32, 22315))*4);
  *(OOC_INT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 22303))*4) = i6;
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l5_loop;
l10:
  *(OOC_INT32*)((_check_pointer(i0, 22338))+4) = i1;
l11:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 22364))+4);
  i1 = _check_pointer(i1, 22367);
  i2 = *(OOC_INT32*)(_check_pointer(i0, 22370));
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i4 = (OOC_INT32)node;
  *(OOC_INT32*)(i1+(_check_index(i2, i3, OOC_UINT32, 22367))*4) = i4;
  i1 = *(OOC_INT32*)(_check_pointer(i0, 22397));
  *(OOC_INT32*)(_check_pointer(i0, 22397)) = (i1+1);
  return;
  ;
}

void OOC_AST__NodeListDesc_Accept(OOC_AST__NodeList nl, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)nl;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 22479)))), OOC_AST__VisitorDesc_VisitNodeList)),OOC_AST__VisitorDesc_VisitNodeList)((OOC_AST__Visitor)i0, (OOC_AST__NodeList)i1);
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
  *(OOC_INT32*)(_check_pointer(i0, 23449)) = i1;
  return (OOC_AST__Terminal)i0;
  ;
}

void OOC_AST__TerminalDesc_Accept(OOC_AST__Terminal terminal, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)terminal;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 23559)))), OOC_AST__VisitorDesc_VisitTerminal)),OOC_AST__VisitorDesc_VisitTerminal)((OOC_AST__Visitor)i0, (OOC_AST__Terminal)i1);
  return;
  ;
}

Object__String OOC_AST__TerminalDesc_GetString(OOC_AST__Terminal terminal, OOC_CHAR8 stripQuotes) {
  register OOC_INT32 i0,i1,i2;

  i0 = stripQuotes;
  if (i0) goto l3;
  i0 = (OOC_INT32)terminal;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 23869));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 23874))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 23869));
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23874))+8);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 23879)), 0);
  i0 = (OOC_INT32)Object__NewLatin1((void*)(_check_pointer(i0, 23879)), i1);
  return (Object__String)i0;
  goto l4;
l3:
  i0 = (OOC_INT32)terminal;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 23807));
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 23752));
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 23757))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 23752));
  i1 = *(OOC_INT32*)((_check_pointer(i1, 23812))+12);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 23757))+8);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 23762)), 0);
  i0 = (OOC_INT32)Object__NewLatin1Region((void*)(_check_pointer(i0, 23762)), i2, 1, (i1-1));
  return (Object__String)i0;
l4:
  _failed_function(23632); return 0;
  ;
}

OOC_AST__IdentDef OOC_AST__BuilderDesc_IdentDef(OOC_AST__Builder b, OOC_AST__Terminal ident, OOC_AST__Terminal mark) {
  register OOC_INT32 i0,i1;
  OOC_AST__IdentDef id;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__IdentDef.baseTypes[0]);
  id = (OOC_AST__IdentDef)i0;
  i1 = (OOC_INT32)ident;
  *(OOC_INT32*)(_check_pointer(i0, 24415)) = i1;
  i1 = (OOC_INT32)mark;
  *(OOC_INT32*)((_check_pointer(i0, 24439))+4) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 24461))+8) = 0;
  return (OOC_AST__IdentDef)i0;
  ;
}

void OOC_AST__IdentDefDesc_AttachDocString(OOC_AST__IdentDef identDef, OOC_Doc__Document docString) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)identDef;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24611))+8);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l3;
  i1 = (OOC_INT32)docString;
  *(OOC_INT32*)((_check_pointer(i0, 24703))+8) = i1;
  goto l4;
l3:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 24649))+8);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 24826)))), OOC_AST__VisitorDesc_VisitIdentDef)),OOC_AST__VisitorDesc_VisitIdentDef)((OOC_AST__Visitor)i0, (OOC_AST__IdentDef)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_ModuleIdent(OOC_AST__Builder b, OOC_AST__NodeList nameList) {
  register OOC_INT32 i0,i1;
  OOC_AST__ModuleIdent moduleIdent;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__ModuleIdent.baseTypes[0]);
  moduleIdent = (OOC_AST__ModuleIdent)i0;
  i1 = (OOC_INT32)nameList;
  *(OOC_INT32*)(_check_pointer(i0, 25185)) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 25224))+4) = 0;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__ModuleIdentDesc_AttachDocString(OOC_AST__ModuleIdent moduleIdent, OOC_Doc__Document docString) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)moduleIdent;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25395))+4);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l3;
  i1 = (OOC_INT32)docString;
  *(OOC_INT32*)((_check_pointer(i0, 25493))+4) = i1;
  goto l4;
l3:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 25436))+4);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 25622)))), OOC_AST__VisitorDesc_VisitModuleIdent)),OOC_AST__VisitorDesc_VisitModuleIdent)((OOC_AST__Visitor)i0, (OOC_AST__ModuleIdent)i1);
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
  *(OOC_INT32*)(_check_pointer(i0, 27624)) = i1;
  i1 = (OOC_INT32)flags;
  *(OOC_INT32*)((_check_pointer(i0, 27648))+4) = i1;
  i1 = (OOC_INT32)exprList;
  *(OOC_INT32*)((_check_pointer(i0, 27672))+8) = i1;
  i1 = (OOC_INT32)of;
  *(OOC_INT32*)((_check_pointer(i0, 27702))+12) = i1;
  i1 = (OOC_INT32)type;
  *(OOC_INT32*)((_check_pointer(i0, 27720))+16) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__ArrayTypeDesc_Accept(OOC_AST__ArrayType arrayType, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)arrayType;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 27836)))), OOC_AST__VisitorDesc_VisitArrayType)),OOC_AST__VisitorDesc_VisitArrayType)((OOC_AST__Visitor)i0, (OOC_AST__ArrayType)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_FieldList(OOC_AST__Builder b, OOC_AST__NodeList identList, OOC_AST__Node colon, OOC_AST__Node type) {
  register OOC_INT32 i0,i1;
  OOC_AST__FieldList fl;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__FieldList.baseTypes[0]);
  fl = (OOC_AST__FieldList)i0;
  i1 = (OOC_INT32)identList;
  *(OOC_INT32*)(_check_pointer(i0, 28572)) = i1;
  i1 = (OOC_INT32)colon;
  *(OOC_INT32*)((_check_pointer(i0, 28604))+4) = i1;
  i1 = (OOC_INT32)type;
  *(OOC_INT32*)((_check_pointer(i0, 28628))+8) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__FieldListDesc_Accept(OOC_AST__FieldList fieldList, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)fieldList;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 28744)))), OOC_AST__VisitorDesc_VisitFieldList)),OOC_AST__VisitorDesc_VisitFieldList)((OOC_AST__Visitor)i0, (OOC_AST__FieldList)i1);
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
  *(OOC_INT32*)(_check_pointer(i0, 31398)) = i1;
  i1 = (OOC_INT32)flags;
  *(OOC_INT32*)((_check_pointer(i0, 31424))+4) = i1;
  i1 = (OOC_INT32)lParen;
  *(OOC_INT32*)((_check_pointer(i0, 31448))+8) = i1;
  i1 = (OOC_INT32)baseType;
  *(OOC_INT32*)((_check_pointer(i0, 31474))+12) = i1;
  i1 = (OOC_INT32)rParen;
  *(OOC_INT32*)((_check_pointer(i0, 31504))+16) = i1;
  i1 = (OOC_INT32)fieldLists;
  *(OOC_INT32*)((_check_pointer(i0, 31530))+20) = i1;
  i1 = (OOC_INT32)end;
  *(OOC_INT32*)((_check_pointer(i0, 31564))+24) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__RecordTypeDesc_Accept(OOC_AST__RecordType recordType, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)recordType;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 31681)))), OOC_AST__VisitorDesc_VisitRecordType)),OOC_AST__VisitorDesc_VisitRecordType)((OOC_AST__Visitor)i0, (OOC_AST__RecordType)i1);
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
  *(OOC_INT32*)(_check_pointer(i0, 32239)) = i1;
  i1 = (OOC_INT32)flags;
  *(OOC_INT32*)((_check_pointer(i0, 32267))+4) = i1;
  i1 = (OOC_INT32)to;
  *(OOC_INT32*)((_check_pointer(i0, 32291))+8) = i1;
  i1 = (OOC_INT32)type;
  *(OOC_INT32*)((_check_pointer(i0, 32309))+12) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__PointerTypeDesc_Accept(OOC_AST__PointerType pointerType, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)pointerType;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 32431)))), OOC_AST__VisitorDesc_VisitPointerType)),OOC_AST__VisitorDesc_VisitPointerType)((OOC_AST__Visitor)i0, (OOC_AST__PointerType)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_FPSection(OOC_AST__Builder b, OOC_AST__Node var, OOC_AST__NodeList identList, OOC_AST__Node colon, OOC_AST__Node type) {
  register OOC_INT32 i0,i1;
  OOC_AST__FPSection fp;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__FPSection.baseTypes[0]);
  fp = (OOC_AST__FPSection)i0;
  i1 = (OOC_INT32)var;
  *(OOC_INT32*)(_check_pointer(i0, 33322)) = i1;
  i1 = (OOC_INT32)identList;
  *(OOC_INT32*)((_check_pointer(i0, 33342))+4) = i1;
  i1 = (OOC_INT32)colon;
  *(OOC_INT32*)((_check_pointer(i0, 33374))+8) = i1;
  i1 = (OOC_INT32)type;
  *(OOC_INT32*)((_check_pointer(i0, 33398))+12) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__FPSectionDesc_Accept(OOC_AST__FPSection fpSection, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)fpSection;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 33514)))), OOC_AST__VisitorDesc_VisitFPSection)),OOC_AST__VisitorDesc_VisitFPSection)((OOC_AST__Visitor)i0, (OOC_AST__FPSection)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_FormalPars(OOC_AST__Builder b, OOC_AST__Flags flags, OOC_AST__Node lParen, OOC_AST__NodeList fpSections, OOC_AST__Node rParen, OOC_AST__Node colon, OOC_AST__Node result, OOC_AST__Node raises, OOC_AST__NodeList raisesList) {
  register OOC_INT32 i0,i1;
  OOC_AST__FormalPars fp;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__FormalPars.baseTypes[0]);
  fp = (OOC_AST__FormalPars)i0;
  i1 = (OOC_INT32)flags;
  *(OOC_INT32*)(_check_pointer(i0, 35683)) = i1;
  i1 = (OOC_INT32)lParen;
  *(OOC_INT32*)((_check_pointer(i0, 35707))+4) = i1;
  i1 = (OOC_INT32)fpSections;
  *(OOC_INT32*)((_check_pointer(i0, 35733))+8) = i1;
  i1 = (OOC_INT32)rParen;
  *(OOC_INT32*)((_check_pointer(i0, 35767))+12) = i1;
  i1 = (OOC_INT32)colon;
  *(OOC_INT32*)((_check_pointer(i0, 35793))+16) = i1;
  i1 = (OOC_INT32)result;
  *(OOC_INT32*)((_check_pointer(i0, 35817))+20) = i1;
  i1 = (OOC_INT32)raises;
  *(OOC_INT32*)((_check_pointer(i0, 35843))+24) = i1;
  i1 = (OOC_INT32)raisesList;
  *(OOC_INT32*)((_check_pointer(i0, 35869))+28) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__FormalParsDesc_Accept(OOC_AST__FormalPars formalPars, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)formalPars;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36002)))), OOC_AST__VisitorDesc_VisitFormalPars)),OOC_AST__VisitorDesc_VisitFormalPars)((OOC_AST__Visitor)i0, (OOC_AST__FormalPars)i1);
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
  *(OOC_INT32*)(_check_pointer(i0, 36499)) = i1;
  i1 = (OOC_INT32)formalPars;
  *(OOC_INT32*)((_check_pointer(i0, 36531))+4) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__ProcTypeDesc_Accept(OOC_AST__ProcType procType, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)procType;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 36656)))), OOC_AST__VisitorDesc_VisitProcType)),OOC_AST__VisitorDesc_VisitProcType)((OOC_AST__Visitor)i0, (OOC_AST__ProcType)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_TPSection(OOC_AST__Builder b, OOC_AST__NodeList identList, OOC_AST__Node colon, OOC_AST__Node type) {
  register OOC_INT32 i0,i1;
  OOC_AST__TPSection tp;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__TPSection.baseTypes[0]);
  tp = (OOC_AST__TPSection)i0;
  i1 = (OOC_INT32)identList;
  *(OOC_INT32*)((_check_pointer(i0, 37288))+4) = i1;
  i1 = (OOC_INT32)colon;
  *(OOC_INT32*)((_check_pointer(i0, 37320))+8) = i1;
  i1 = (OOC_INT32)type;
  *(OOC_INT32*)((_check_pointer(i0, 37344))+12) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__TPSectionDesc_Accept(OOC_AST__TPSection tpSection, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)tpSection;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 37460)))), OOC_AST__VisitorDesc_VisitTPSection)),OOC_AST__VisitorDesc_VisitTPSection)((OOC_AST__Visitor)i0, (OOC_AST__TPSection)i1);
  return;
  ;
}

OOC_AST__TypePars OOC_AST__BuilderDesc_TypePars(OOC_AST__Builder b, OOC_AST__Node lParen, OOC_AST__NodeList tpSections, OOC_AST__Node rParen) {
  register OOC_INT32 i0,i1;
  OOC_AST__TypePars tp;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__TypePars.baseTypes[0]);
  tp = (OOC_AST__TypePars)i0;
  i1 = (OOC_INT32)lParen;
  *(OOC_INT32*)(_check_pointer(i0, 38267)) = i1;
  i1 = (OOC_INT32)tpSections;
  *(OOC_INT32*)((_check_pointer(i0, 38293))+4) = i1;
  i1 = (OOC_INT32)rParen;
  *(OOC_INT32*)((_check_pointer(i0, 38327))+8) = i1;
  return (OOC_AST__TypePars)i0;
  ;
}

void OOC_AST__TypeParsDesc_Accept(OOC_AST__TypePars typePars, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)typePars;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 38446)))), OOC_AST__VisitorDesc_VisitTypePars)),OOC_AST__VisitorDesc_VisitTypePars)((OOC_AST__Visitor)i0, (OOC_AST__TypePars)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_QualType(OOC_AST__Builder b, OOC_AST__Node qualident, OOC_AST__Node lParen, OOC_AST__NodeList arguments, OOC_AST__Node rParen) {
  register OOC_INT32 i0,i1;
  OOC_AST__QualType qt;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__QualType.baseTypes[0]);
  qt = (OOC_AST__QualType)i0;
  i1 = (OOC_INT32)qualident;
  *(OOC_INT32*)(_check_pointer(i0, 39571)) = i1;
  i1 = (OOC_INT32)lParen;
  *(OOC_INT32*)((_check_pointer(i0, 39602))+4) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 39620)))), &_td_OOC_AST__TerminalDesc, 39620));
  i1 = (OOC_INT32)arguments;
  *(OOC_INT32*)((_check_pointer(i0, 39637))+8) = i1;
  i1 = (OOC_INT32)rParen;
  *(OOC_INT32*)((_check_pointer(i0, 39668))+12) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 39686)))), &_td_OOC_AST__TerminalDesc, 39686));
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__QualTypeDesc_Accept(OOC_AST__QualType qualType, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)qualType;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 39797)))), OOC_AST__VisitorDesc_VisitQualType)),OOC_AST__VisitorDesc_VisitQualType)((OOC_AST__Visitor)i0, (OOC_AST__QualType)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_ImportDecl(OOC_AST__Builder b, OOC_AST__Node alias, OOC_AST__Node becomes, OOC_AST__Node module, OOC_Scanner_InputBuffer__CharArray moduleName) {
  register OOC_INT32 i0,i1;
  OOC_AST__ImportDecl id;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__ImportDecl.baseTypes[0]);
  id = (OOC_AST__ImportDecl)i0;
  i1 = (OOC_INT32)alias;
  *(OOC_INT32*)(_check_pointer(i0, 40670)) = i1;
  i1 = (OOC_INT32)becomes;
  *(OOC_INT32*)((_check_pointer(i0, 40694))+4) = i1;
  i1 = (OOC_INT32)module;
  *(OOC_INT32*)((_check_pointer(i0, 40722))+8) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 40741)))), &_td_OOC_AST__ModuleIdentDesc, 40741));
  i1 = (OOC_INT32)moduleName;
  *(OOC_INT32*)((_check_pointer(i0, 40761))+12) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__ImportDeclDesc_Accept(OOC_AST__ImportDecl importDecl, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)importDecl;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 40892)))), OOC_AST__VisitorDesc_VisitImportDecl)),OOC_AST__VisitorDesc_VisitImportDecl)((OOC_AST__Visitor)i0, (OOC_AST__ImportDecl)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_ConstDecl(OOC_AST__Builder b, OOC_AST__Node identDef, OOC_AST__Flags flags, OOC_AST__Node equal, OOC_AST__Node expr, OOC_AST__Node semicolon) {
  register OOC_INT32 i0,i1;
  OOC_AST__ConstDecl cd;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__ConstDecl.baseTypes[0]);
  cd = (OOC_AST__ConstDecl)i0;
  i1 = (OOC_INT32)identDef;
  *(OOC_INT32*)(_check_pointer(i0, 41628)) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 41651)))), &_td_OOC_AST__IdentDefDesc, 41651));
  i1 = (OOC_INT32)flags;
  *(OOC_INT32*)((_check_pointer(i0, 41668))+4) = i1;
  i1 = (OOC_INT32)equal;
  *(OOC_INT32*)((_check_pointer(i0, 41692))+8) = i1;
  i1 = (OOC_INT32)expr;
  *(OOC_INT32*)((_check_pointer(i0, 41716))+12) = i1;
  i1 = (OOC_INT32)semicolon;
  *(OOC_INT32*)((_check_pointer(i0, 41738))+16) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__ConstDeclDesc_Accept(OOC_AST__ConstDecl constDecl, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)constDecl;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 41864)))), OOC_AST__VisitorDesc_VisitConstDecl)),OOC_AST__VisitorDesc_VisitConstDecl)((OOC_AST__Visitor)i0, (OOC_AST__ConstDecl)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_TypeDecl(OOC_AST__Builder b, OOC_AST__Node identDef, OOC_AST__Flags flags, OOC_AST__TypePars typePars, OOC_AST__Node equal, OOC_AST__Node type, OOC_AST__Node semicolon) {
  register OOC_INT32 i0,i1;
  OOC_AST__TypeDecl td;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__TypeDecl.baseTypes[0]);
  td = (OOC_AST__TypeDecl)i0;
  i1 = (OOC_INT32)identDef;
  *(OOC_INT32*)(_check_pointer(i0, 42734)) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 42757)))), &_td_OOC_AST__IdentDefDesc, 42757));
  i1 = (OOC_INT32)flags;
  *(OOC_INT32*)((_check_pointer(i0, 42774))+4) = i1;
  i1 = (OOC_INT32)typePars;
  *(OOC_INT32*)((_check_pointer(i0, 42798))+8) = i1;
  i1 = (OOC_INT32)equal;
  *(OOC_INT32*)((_check_pointer(i0, 42828))+12) = i1;
  i1 = (OOC_INT32)type;
  *(OOC_INT32*)((_check_pointer(i0, 42852))+16) = i1;
  i1 = (OOC_INT32)semicolon;
  *(OOC_INT32*)((_check_pointer(i0, 42874))+20) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__TypeDeclDesc_Accept(OOC_AST__TypeDecl typeDecl, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)typeDecl;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 42997)))), OOC_AST__VisitorDesc_VisitTypeDecl)),OOC_AST__VisitorDesc_VisitTypeDecl)((OOC_AST__Visitor)i0, (OOC_AST__TypeDecl)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_VarDecl(OOC_AST__Builder b, OOC_AST__NodeList identList, OOC_AST__Node colon, OOC_AST__Node type, OOC_AST__Node semicolon) {
  register OOC_INT32 i0,i1;
  OOC_AST__VarDecl vd;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__VarDecl.baseTypes[0]);
  vd = (OOC_AST__VarDecl)i0;
  i1 = (OOC_INT32)identList;
  *(OOC_INT32*)(_check_pointer(i0, 43891)) = i1;
  i1 = (OOC_INT32)colon;
  *(OOC_INT32*)((_check_pointer(i0, 43923))+4) = i1;
  i1 = (OOC_INT32)type;
  *(OOC_INT32*)((_check_pointer(i0, 43947))+8) = i1;
  i1 = (OOC_INT32)semicolon;
  *(OOC_INT32*)((_check_pointer(i0, 43969))+12) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__VarDeclDesc_Accept(OOC_AST__VarDecl varDecl, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)varDecl;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 44089)))), OOC_AST__VisitorDesc_VisitVarDecl)),OOC_AST__VisitorDesc_VisitVarDecl)((OOC_AST__Visitor)i0, (OOC_AST__VarDecl)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_Receiver(OOC_AST__Builder b, OOC_AST__Node lParen, OOC_AST__Node var, OOC_AST__IdentDef ident, OOC_AST__Node colon, OOC_AST__Node type, OOC_AST__Terminal lParenAlias, OOC_AST__NodeList aliasList, OOC_AST__Terminal rParenAlias, OOC_AST__Node rParen) {
  register OOC_INT32 i0,i1;
  OOC_AST__Receiver r;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__Receiver.baseTypes[0]);
  r = (OOC_AST__Receiver)i0;
  i1 = (OOC_INT32)lParen;
  *(OOC_INT32*)(_check_pointer(i0, 45465)) = i1;
  i1 = (OOC_INT32)var;
  *(OOC_INT32*)((_check_pointer(i0, 45490))+4) = i1;
  i1 = (OOC_INT32)ident;
  *(OOC_INT32*)((_check_pointer(i0, 45509))+8) = i1;
  i1 = (OOC_INT32)colon;
  *(OOC_INT32*)((_check_pointer(i0, 45532))+12) = i1;
  i1 = (OOC_INT32)type;
  *(OOC_INT32*)((_check_pointer(i0, 45555))+16) = i1;
  i1 = (OOC_INT32)lParenAlias;
  *(OOC_INT32*)((_check_pointer(i0, 45576))+20) = i1;
  i1 = (OOC_INT32)aliasList;
  *(OOC_INT32*)((_check_pointer(i0, 45611))+24) = i1;
  i1 = (OOC_INT32)rParenAlias;
  *(OOC_INT32*)((_check_pointer(i0, 45642))+28) = i1;
  i1 = (OOC_INT32)rParen;
  *(OOC_INT32*)((_check_pointer(i0, 45677))+32) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__ReceiverDesc_Accept(OOC_AST__Receiver receiver, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)receiver;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 45793)))), OOC_AST__VisitorDesc_VisitReceiver)),OOC_AST__VisitorDesc_VisitReceiver)((OOC_AST__Visitor)i0, (OOC_AST__Receiver)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_ProcDecl(OOC_AST__Builder b, OOC_AST__Node proc, OOC_AST__Node arrow, OOC_AST__Node receiver, OOC_AST__Flags flags, OOC_AST__Node identDef, OOC_AST__Node formalPars, OOC_AST__Node semicolon1, OOC_AST__Body body, OOC_AST__Node semicolon2) {
  register OOC_INT32 i0,i1;
  OOC_AST__ProcDecl pd;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__ProcDecl.baseTypes[0]);
  pd = (OOC_AST__ProcDecl)i0;
  i1 = (OOC_INT32)proc;
  *(OOC_INT32*)(_check_pointer(i0, 47339)) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 47354)))), &_td_OOC_AST__TerminalDesc, 47354));
  i1 = (OOC_INT32)arrow;
  *(OOC_INT32*)((_check_pointer(i0, 47371))+4) = i1;
  i1 = (OOC_INT32)receiver;
  *(OOC_INT32*)((_check_pointer(i0, 47395))+8) = i1;
  i1 = (OOC_INT32)flags;
  *(OOC_INT32*)((_check_pointer(i0, 47425))+12) = i1;
  i1 = (OOC_INT32)identDef;
  *(OOC_INT32*)((_check_pointer(i0, 47449))+16) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 47472)))), &_td_OOC_AST__IdentDefDesc, 47472));
  i1 = (OOC_INT32)formalPars;
  *(OOC_INT32*)((_check_pointer(i0, 47489))+20) = i1;
  i1 = (OOC_INT32)semicolon1;
  *(OOC_INT32*)((_check_pointer(i0, 47523))+24) = i1;
  i1 = (OOC_INT32)body;
  *(OOC_INT32*)((_check_pointer(i0, 47557))+28) = i1;
  i1 = (OOC_INT32)semicolon2;
  *(OOC_INT32*)((_check_pointer(i0, 47579))+32) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__ProcDeclDesc_Accept(OOC_AST__ProcDecl procDecl, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)procDecl;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 47704)))), OOC_AST__VisitorDesc_VisitProcDecl)),OOC_AST__VisitorDesc_VisitProcDecl)((OOC_AST__Visitor)i0, (OOC_AST__ProcDecl)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_ImportList(OOC_AST__Builder b, OOC_AST__Node import, OOC_AST__NodeList imports, OOC_AST__Node semicolon) {
  register OOC_INT32 i0,i1;
  OOC_AST__ImportList il;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__ImportList.baseTypes[0]);
  il = (OOC_AST__ImportList)i0;
  i1 = (OOC_INT32)import;
  *(OOC_INT32*)(_check_pointer(i0, 48455)) = i1;
  i1 = (OOC_INT32)imports;
  *(OOC_INT32*)((_check_pointer(i0, 48481))+4) = i1;
  i1 = (OOC_INT32)semicolon;
  *(OOC_INT32*)((_check_pointer(i0, 48509))+8) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__ImportListDesc_Accept(OOC_AST__ImportList importList, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)importList;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 48638)))), OOC_AST__VisitorDesc_VisitImportList)),OOC_AST__VisitorDesc_VisitImportList)((OOC_AST__Visitor)i0, (OOC_AST__ImportList)i1);
  return;
  ;
}

OOC_AST__Body OOC_AST__BuilderDesc_Body(OOC_AST__Builder b, OOC_AST__NodeList declSeq, OOC_AST__Node begin, OOC_AST__NodeList statmSeq, OOC_AST__Node end, OOC_AST__Node name) {
  register OOC_INT32 i0,i1;
  OOC_AST__Body body;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__Body.baseTypes[0]);
  body = (OOC_AST__Body)i0;
  i1 = (OOC_INT32)declSeq;
  *(OOC_INT32*)(_check_pointer(i0, 50284)) = i1;
  i1 = (OOC_INT32)begin;
  *(OOC_INT32*)((_check_pointer(i0, 50314))+4) = i1;
  i1 = (OOC_INT32)statmSeq;
  *(OOC_INT32*)((_check_pointer(i0, 50340))+8) = i1;
  i1 = (OOC_INT32)end;
  *(OOC_INT32*)((_check_pointer(i0, 50372))+12) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 50385)))), &_td_OOC_AST__TerminalDesc, 50385));
  i1 = (OOC_INT32)name;
  *(OOC_INT32*)((_check_pointer(i0, 50404))+16) = i1;
  return (OOC_AST__Body)i0;
  ;
}

void OOC_AST__BodyDesc_Accept(OOC_AST__Body body, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)body;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 50507)))), OOC_AST__VisitorDesc_VisitBody)),OOC_AST__VisitorDesc_VisitBody)((OOC_AST__Visitor)i0, (OOC_AST__Body)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_Module(OOC_AST__Builder b, OOC_AST__Terminal module, OOC_AST__Node name, OOC_AST__Flags flags, OOC_AST__Node semicolon, OOC_AST__Node importList, OOC_AST__Body body, OOC_AST__Node period, OOC_Scanner_InputBuffer__CharArray moduleName) {
  register OOC_INT32 i0,i1;
  OOC_AST__Module m;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__Module.baseTypes[0]);
  m = (OOC_AST__Module)i0;
  i1 = (OOC_INT32)module;
  *(OOC_INT32*)(_check_pointer(i0, 51764)) = i1;
  i1 = (OOC_INT32)name;
  *(OOC_INT32*)((_check_pointer(i0, 51789))+4) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 51804)))), &_td_OOC_AST__ModuleIdentDesc, 51804));
  i1 = (OOC_INT32)flags;
  *(OOC_INT32*)((_check_pointer(i0, 51823))+8) = i1;
  i1 = (OOC_INT32)semicolon;
  *(OOC_INT32*)((_check_pointer(i0, 51846))+12) = i1;
  i1 = (OOC_INT32)importList;
  *(OOC_INT32*)((_check_pointer(i0, 51877))+16) = i1;
  i1 = (OOC_INT32)body;
  *(OOC_INT32*)((_check_pointer(i0, 51910))+20) = i1;
  i1 = (OOC_INT32)period;
  *(OOC_INT32*)((_check_pointer(i0, 51931))+24) = i1;
  i1 = (OOC_INT32)moduleName;
  *(OOC_INT32*)((_check_pointer(i0, 51956))+28) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__ModuleDesc_Accept(OOC_AST__Module module, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)module;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 52074)))), OOC_AST__VisitorDesc_VisitModule)),OOC_AST__VisitorDesc_VisitModule)((OOC_AST__Visitor)i0, (OOC_AST__Module)i1);
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
  *(OOC_INT32*)(_check_pointer(i0, 52889)) = i1;
  goto l4;
l3:
  *(OOC_INT32*)(_check_pointer(i0, 52859)) = (OOC_INT32)0;
l4:
  i1 = (OOC_INT32)op;
  *(OOC_INT32*)((_check_pointer(i0, 52918))+4) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 52929)))), &_td_OOC_AST__TerminalDesc, 52929));
  i1 = (OOC_INT32)right;
  i2 = i1==(OOC_INT32)0;
  if (i2) goto l7;
  *(OOC_INT32*)((_check_pointer(i0, 53004))+8) = i1;
  goto l8;
l7:
  *(OOC_INT32*)((_check_pointer(i0, 52973))+8) = (OOC_INT32)0;
l8:
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__OperatorDesc_Accept(OOC_AST__Operator _operator, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)_operator;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 53126)))), OOC_AST__VisitorDesc_VisitOperator)),OOC_AST__VisitorDesc_VisitOperator)((OOC_AST__Visitor)i0, (OOC_AST__Operator)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_Factor(OOC_AST__Builder b, OOC_AST__Node lParen, OOC_AST__Node expr, OOC_AST__Node rParen) {
  register OOC_INT32 i0,i1;
  OOC_AST__Factor f;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__Factor.baseTypes[0]);
  f = (OOC_AST__Factor)i0;
  i1 = (OOC_INT32)lParen;
  *(OOC_INT32*)(_check_pointer(i0, 53699)) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 53718)))), &_td_OOC_AST__TerminalDesc, 53718));
  i1 = (OOC_INT32)expr;
  *(OOC_INT32*)((_check_pointer(i0, 53734))+4) = i1;
  i1 = (OOC_INT32)rParen;
  *(OOC_INT32*)((_check_pointer(i0, 53755))+8) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 53774)))), &_td_OOC_AST__TerminalDesc, 53774));
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__FactorDesc_Accept(OOC_AST__Factor factor, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)factor;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 53875)))), OOC_AST__VisitorDesc_VisitFactor)),OOC_AST__VisitorDesc_VisitFactor)((OOC_AST__Visitor)i0, (OOC_AST__Factor)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_Set(OOC_AST__Builder b, OOC_AST__Node type, OOC_AST__Node lBrace, OOC_AST__NodeList elementList, OOC_AST__Node rBrace) {
  register OOC_INT32 i0,i1;
  OOC_AST__Set s;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__Set.baseTypes[0]);
  s = (OOC_AST__Set)i0;
  i1 = (OOC_INT32)type;
  *(OOC_INT32*)(_check_pointer(i0, 54788)) = i1;
  i1 = (OOC_INT32)lBrace;
  *(OOC_INT32*)((_check_pointer(i0, 54809))+4) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 54828)))), &_td_OOC_AST__TerminalDesc, 54828));
  i1 = (OOC_INT32)elementList;
  *(OOC_INT32*)((_check_pointer(i0, 54844))+8) = i1;
  i1 = (OOC_INT32)rBrace;
  *(OOC_INT32*)((_check_pointer(i0, 54879))+12) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 54898)))), &_td_OOC_AST__TerminalDesc, 54898));
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__SetDesc_Accept(OOC_AST__Set set, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)set;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 54990)))), OOC_AST__VisitorDesc_VisitSet)),OOC_AST__VisitorDesc_VisitSet)((OOC_AST__Visitor)i0, (OOC_AST__Set)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_ArrayIndex(OOC_AST__Builder b, OOC_AST__Node design, OOC_AST__Node lBrak, OOC_AST__NodeList indices, OOC_AST__Node rBrak) {
  register OOC_INT32 i0,i1;
  OOC_AST__ArrayIndex ai;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__ArrayIndex.baseTypes[0]);
  ai = (OOC_AST__ArrayIndex)i0;
  i1 = (OOC_INT32)design;
  *(OOC_INT32*)(_check_pointer(i0, 55700)) = i1;
  i1 = (OOC_INT32)lBrak;
  *(OOC_INT32*)((_check_pointer(i0, 55726))+4) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 55743)))), &_td_OOC_AST__TerminalDesc, 55743));
  i1 = (OOC_INT32)indices;
  *(OOC_INT32*)((_check_pointer(i0, 55760))+8) = i1;
  i1 = (OOC_INT32)rBrak;
  *(OOC_INT32*)((_check_pointer(i0, 55788))+12) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 55805)))), &_td_OOC_AST__TerminalDesc, 55805));
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__ArrayIndexDesc_Accept(OOC_AST__ArrayIndex arrayIndex, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)arrayIndex;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 55919)))), OOC_AST__VisitorDesc_VisitArrayIndex)),OOC_AST__VisitorDesc_VisitArrayIndex)((OOC_AST__Visitor)i0, (OOC_AST__ArrayIndex)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_FunctionCall(OOC_AST__Builder b, OOC_AST__Node design, OOC_AST__Node lParen, OOC_AST__NodeList arguments, OOC_AST__Node rParen) {
  register OOC_INT32 i0,i1;
  OOC_AST__FunctionCall fc;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__FunctionCall.baseTypes[0]);
  fc = (OOC_AST__FunctionCall)i0;
  i1 = (OOC_INT32)design;
  *(OOC_INT32*)(_check_pointer(i0, 56995)) = i1;
  i1 = (OOC_INT32)lParen;
  *(OOC_INT32*)((_check_pointer(i0, 57021))+4) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 57040)))), &_td_OOC_AST__TerminalDesc, 57040));
  i1 = (OOC_INT32)arguments;
  *(OOC_INT32*)((_check_pointer(i0, 57057))+8) = i1;
  i1 = (OOC_INT32)rParen;
  *(OOC_INT32*)((_check_pointer(i0, 57089))+12) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 57108)))), &_td_OOC_AST__TerminalDesc, 57108));
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__FunctionCallDesc_Accept(OOC_AST__FunctionCall functionCall, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)functionCall;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 57228)))), OOC_AST__VisitorDesc_VisitFunctionCall)),OOC_AST__VisitorDesc_VisitFunctionCall)((OOC_AST__Visitor)i0, (OOC_AST__FunctionCall)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_Assignment(OOC_AST__Builder b, OOC_AST__Node assignment) {
  register OOC_INT32 i0,i1;
  OOC_AST__Assignment a;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__Assignment.baseTypes[0]);
  a = (OOC_AST__Assignment)i0;
  i1 = (OOC_INT32)assignment;
  *(OOC_INT32*)(_check_pointer(i0, 57697)) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 57724)))), &_td_OOC_AST__OperatorDesc, 57724));
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__AssignmentDesc_Accept(OOC_AST__Assignment assignment, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)assignment;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 57837)))), OOC_AST__VisitorDesc_VisitAssignment)),OOC_AST__VisitorDesc_VisitAssignment)((OOC_AST__Visitor)i0, (OOC_AST__Assignment)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_ProcedureCall(OOC_AST__Builder b, OOC_AST__Node call) {
  register OOC_INT32 i0,i1;
  OOC_AST__ProcedureCall p;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__ProcedureCall.baseTypes[0]);
  p = (OOC_AST__ProcedureCall)i0;
  i1 = (OOC_INT32)call;
  *(OOC_INT32*)(_check_pointer(i0, 58386)) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__ProcedureCallDesc_Accept(OOC_AST__ProcedureCall procedureCall, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)procedureCall;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 58513)))), OOC_AST__VisitorDesc_VisitProcedureCall)),OOC_AST__VisitorDesc_VisitProcedureCall)((OOC_AST__Visitor)i0, (OOC_AST__ProcedureCall)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_IfStatm(OOC_AST__Builder b, OOC_AST__NodeList guardList, OOC_AST__Node _else, OOC_AST__NodeList elseStatmSeq, OOC_AST__Node end) {
  register OOC_INT32 i0,i1,i2;
  OOC_AST__IfStatm i;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__IfStatm.baseTypes[0]);
  i = (OOC_AST__IfStatm)i0;
  i1 = (OOC_INT32)guardList;
  *(OOC_INT32*)(_check_pointer(i0, 59714)) = i1;
  i1 = (OOC_INT32)_else;
  *(OOC_INT32*)((_check_pointer(i0, 59745))+4) = i1;
  i1 = (OOC_INT32)elseStatmSeq;
  i2 = i1!=0;
  if (i2) goto l3;
  *(OOC_INT32*)((_check_pointer(i0, 59849))+8) = 0;
  goto l4;
l3:
  *(OOC_INT32*)((_check_pointer(i0, 59801))+8) = i1;
l4:
  i1 = (OOC_INT32)end;
  *(OOC_INT32*)((_check_pointer(i0, 59886))+12) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__IfStatmDesc_Accept(OOC_AST__IfStatm ifStatm, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)ifStatm;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 59993)))), OOC_AST__VisitorDesc_VisitIfStatm)),OOC_AST__VisitorDesc_VisitIfStatm)((OOC_AST__Visitor)i0, (OOC_AST__IfStatm)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_CaseStatm(OOC_AST__Builder b, OOC_AST__Node _case, OOC_AST__Node expr, OOC_AST__Node of, OOC_AST__NodeList caseList, OOC_AST__Node _else, OOC_AST__NodeList elseStatmSeq, OOC_AST__Node end) {
  register OOC_INT32 i0,i1,i2;
  OOC_AST__CaseStatm c;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__CaseStatm.baseTypes[0]);
  c = (OOC_AST__CaseStatm)i0;
  i1 = (OOC_INT32)_case;
  *(OOC_INT32*)(_check_pointer(i0, 61699)) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 61714)))), &_td_OOC_AST__TerminalDesc, 61714));
  i1 = (OOC_INT32)expr;
  *(OOC_INT32*)((_check_pointer(i0, 61730))+4) = i1;
  i1 = (OOC_INT32)of;
  *(OOC_INT32*)((_check_pointer(i0, 61751))+8) = i1;
  i1 = (OOC_INT32)caseList;
  *(OOC_INT32*)((_check_pointer(i0, 61768))+12) = i1;
  i1 = (OOC_INT32)_else;
  *(OOC_INT32*)((_check_pointer(i0, 61797))+16) = i1;
  i1 = (OOC_INT32)elseStatmSeq;
  i2 = i1==0;
  if (i2) goto l3;
  *(OOC_INT32*)((_check_pointer(i0, 61892))+20) = i1;
  goto l4;
l3:
  *(OOC_INT32*)((_check_pointer(i0, 61853))+20) = 0;
l4:
  i1 = (OOC_INT32)end;
  *(OOC_INT32*)((_check_pointer(i0, 61938))+24) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__CaseStatmDesc_Accept(OOC_AST__CaseStatm caseStatm, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)caseStatm;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 62051)))), OOC_AST__VisitorDesc_VisitCaseStatm)),OOC_AST__VisitorDesc_VisitCaseStatm)((OOC_AST__Visitor)i0, (OOC_AST__CaseStatm)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_WhileStatm(OOC_AST__Builder b, OOC_AST__Node _while, OOC_AST__Node guard, OOC_AST__Node _do, OOC_AST__NodeList statmSeq, OOC_AST__Node end) {
  register OOC_INT32 i0,i1;
  OOC_AST__WhileStatm w;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__WhileStatm.baseTypes[0]);
  w = (OOC_AST__WhileStatm)i0;
  i1 = (OOC_INT32)_while;
  *(OOC_INT32*)(_check_pointer(i0, 62539)) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 62556)))), &_td_OOC_AST__TerminalDesc, 62556));
  i1 = (OOC_INT32)guard;
  *(OOC_INT32*)((_check_pointer(i0, 62572))+4) = i1;
  i1 = (OOC_INT32)_do;
  *(OOC_INT32*)((_check_pointer(i0, 62595))+8) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 62606)))), &_td_OOC_AST__TerminalDesc, 62606));
  i1 = (OOC_INT32)statmSeq;
  *(OOC_INT32*)((_check_pointer(i0, 62622))+12) = i1;
  i1 = (OOC_INT32)end;
  *(OOC_INT32*)((_check_pointer(i0, 62651))+16) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 62664)))), &_td_OOC_AST__TerminalDesc, 62664));
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__WhileStatmDesc_Accept(OOC_AST__WhileStatm whileStatm, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)whileStatm;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 62777)))), OOC_AST__VisitorDesc_VisitWhileStatm)),OOC_AST__VisitorDesc_VisitWhileStatm)((OOC_AST__Visitor)i0, (OOC_AST__WhileStatm)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_RepeatStatm(OOC_AST__Builder b, OOC_AST__Node repeat, OOC_AST__NodeList statmSeq, OOC_AST__Node until, OOC_AST__Node expr) {
  register OOC_INT32 i0,i1;
  OOC_AST__RepeatStatm r;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__RepeatStatm.baseTypes[0]);
  r = (OOC_AST__RepeatStatm)i0;
  i1 = (OOC_INT32)repeat;
  *(OOC_INT32*)(_check_pointer(i0, 63231)) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 63250)))), &_td_OOC_AST__TerminalDesc, 63250));
  i1 = (OOC_INT32)statmSeq;
  *(OOC_INT32*)((_check_pointer(i0, 63266))+4) = i1;
  i1 = (OOC_INT32)until;
  *(OOC_INT32*)((_check_pointer(i0, 63295))+8) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 63312)))), &_td_OOC_AST__TerminalDesc, 63312));
  i1 = (OOC_INT32)expr;
  *(OOC_INT32*)((_check_pointer(i0, 63328))+12) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__RepeatStatmDesc_Accept(OOC_AST__RepeatStatm repeatStatm, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)repeatStatm;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 63449)))), OOC_AST__VisitorDesc_VisitRepeatStatm)),OOC_AST__VisitorDesc_VisitRepeatStatm)((OOC_AST__Visitor)i0, (OOC_AST__RepeatStatm)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_ForStatm(OOC_AST__Builder b, OOC_AST__Node _for, OOC_AST__Node ident, OOC_AST__Node becomes, OOC_AST__Node startValue, OOC_AST__Node to, OOC_AST__Node endValue, OOC_AST__Node by, OOC_AST__Node step, OOC_AST__Node _do, OOC_AST__NodeList statmSeq, OOC_AST__Node end) {
  register OOC_INT32 i0,i1,i2;
  OOC_AST__ForStatm f;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__ForStatm.baseTypes[0]);
  f = (OOC_AST__ForStatm)i0;
  i1 = (OOC_INT32)_for;
  *(OOC_INT32*)(_check_pointer(i0, 64397)) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 64410)))), &_td_OOC_AST__TerminalDesc, 64410));
  i1 = (OOC_INT32)ident;
  *(OOC_INT32*)((_check_pointer(i0, 64426))+4) = i1;
  i1 = (OOC_INT32)becomes;
  *(OOC_INT32*)((_check_pointer(i0, 64449))+8) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 64470)))), &_td_OOC_AST__TerminalDesc, 64470));
  i1 = (OOC_INT32)startValue;
  *(OOC_INT32*)((_check_pointer(i0, 64486))+12) = i1;
  i1 = (OOC_INT32)to;
  *(OOC_INT32*)((_check_pointer(i0, 64519))+16) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 64530)))), &_td_OOC_AST__TerminalDesc, 64530));
  i1 = (OOC_INT32)endValue;
  *(OOC_INT32*)((_check_pointer(i0, 64546))+20) = i1;
  i1 = (OOC_INT32)step;
  i2 = i1==0;
  if (i2) goto l3;
  i2 = (OOC_INT32)by;
  *(OOC_INT32*)((_check_pointer(i0, 64653))+24) = (_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 64664)))), &_td_OOC_AST__TerminalDesc, 64664));
  *(OOC_INT32*)((_check_pointer(i0, 64682))+28) = i1;
  goto l4;
l3:
  *(OOC_INT32*)((_check_pointer(i0, 64602))+24) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 64622))+28) = 0;
l4:
  i1 = (OOC_INT32)_do;
  *(OOC_INT32*)((_check_pointer(i0, 64712))+32) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 64723)))), &_td_OOC_AST__TerminalDesc, 64723));
  i1 = (OOC_INT32)statmSeq;
  *(OOC_INT32*)((_check_pointer(i0, 64739))+36) = i1;
  i1 = (OOC_INT32)end;
  *(OOC_INT32*)((_check_pointer(i0, 64768))+40) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 64781)))), &_td_OOC_AST__TerminalDesc, 64781));
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__ForStatmDesc_Accept(OOC_AST__ForStatm forStatm, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)forStatm;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 64888)))), OOC_AST__VisitorDesc_VisitForStatm)),OOC_AST__VisitorDesc_VisitForStatm)((OOC_AST__Visitor)i0, (OOC_AST__ForStatm)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_IterateStatm(OOC_AST__Builder b, OOC_AST__Node _for, OOC_AST__Node ident, OOC_AST__Node in, OOC_AST__Node range, OOC_AST__Node _do, OOC_AST__NodeList statmSeq, OOC_AST__Node end) {
  register OOC_INT32 i0,i1;
  OOC_AST__IterateStatm f;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__IterateStatm.baseTypes[0]);
  f = (OOC_AST__IterateStatm)i0;
  i1 = (OOC_INT32)_for;
  *(OOC_INT32*)(_check_pointer(i0, 65496)) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 65509)))), &_td_OOC_AST__TerminalDesc, 65509));
  i1 = (OOC_INT32)ident;
  *(OOC_INT32*)((_check_pointer(i0, 65525))+4) = i1;
  i1 = (OOC_INT32)in;
  *(OOC_INT32*)((_check_pointer(i0, 65548))+8) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 65559)))), &_td_OOC_AST__TerminalDesc, 65559));
  i1 = (OOC_INT32)range;
  *(OOC_INT32*)((_check_pointer(i0, 65575))+12) = i1;
  i1 = (OOC_INT32)_do;
  *(OOC_INT32*)((_check_pointer(i0, 65598))+16) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 65609)))), &_td_OOC_AST__TerminalDesc, 65609));
  i1 = (OOC_INT32)statmSeq;
  *(OOC_INT32*)((_check_pointer(i0, 65625))+20) = i1;
  i1 = (OOC_INT32)end;
  *(OOC_INT32*)((_check_pointer(i0, 65654))+24) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 65667)))), &_td_OOC_AST__TerminalDesc, 65667));
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__IterateStatmDesc_Accept(OOC_AST__IterateStatm iterStatm, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)iterStatm;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 65783)))), OOC_AST__VisitorDesc_VisitIterateStatm)),OOC_AST__VisitorDesc_VisitIterateStatm)((OOC_AST__Visitor)i0, (OOC_AST__IterateStatm)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_LoopStatm(OOC_AST__Builder b, OOC_AST__Node loop, OOC_AST__NodeList statmSeq, OOC_AST__Node end) {
  register OOC_INT32 i0,i1;
  OOC_AST__LoopStatm l;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__LoopStatm.baseTypes[0]);
  l = (OOC_AST__LoopStatm)i0;
  i1 = (OOC_INT32)loop;
  *(OOC_INT32*)(_check_pointer(i0, 66171)) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 66186)))), &_td_OOC_AST__TerminalDesc, 66186));
  i1 = (OOC_INT32)statmSeq;
  *(OOC_INT32*)((_check_pointer(i0, 66202))+4) = i1;
  i1 = (OOC_INT32)end;
  *(OOC_INT32*)((_check_pointer(i0, 66231))+8) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 66244)))), &_td_OOC_AST__TerminalDesc, 66244));
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__LoopStatmDesc_Accept(OOC_AST__LoopStatm loopStatm, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)loopStatm;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 66354)))), OOC_AST__VisitorDesc_VisitLoopStatm)),OOC_AST__VisitorDesc_VisitLoopStatm)((OOC_AST__Visitor)i0, (OOC_AST__LoopStatm)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_WithStatm(OOC_AST__Builder b, OOC_AST__NodeList guardList, OOC_AST__Node _else, OOC_AST__NodeList elseStatmSeq, OOC_AST__Node end) {
  register OOC_INT32 i0,i1,i2;
  OOC_AST__WithStatm w;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__WithStatm.baseTypes[0]);
  w = (OOC_AST__WithStatm)i0;
  i1 = (OOC_INT32)guardList;
  *(OOC_INT32*)(_check_pointer(i0, 67594)) = i1;
  i1 = (OOC_INT32)_else;
  *(OOC_INT32*)((_check_pointer(i0, 67625))+4) = i1;
  i1 = (OOC_INT32)elseStatmSeq;
  i2 = i1!=0;
  if (i2) goto l3;
  *(OOC_INT32*)((_check_pointer(i0, 67729))+8) = 0;
  goto l4;
l3:
  *(OOC_INT32*)((_check_pointer(i0, 67681))+8) = i1;
l4:
  i1 = (OOC_INT32)end;
  *(OOC_INT32*)((_check_pointer(i0, 67766))+12) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__WithStatmDesc_Accept(OOC_AST__WithStatm withStatm, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)withStatm;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 67879)))), OOC_AST__VisitorDesc_VisitWithStatm)),OOC_AST__VisitorDesc_VisitWithStatm)((OOC_AST__Visitor)i0, (OOC_AST__WithStatm)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_ExitStatm(OOC_AST__Builder b, OOC_AST__Node exit) {
  register OOC_INT32 i0,i1;
  OOC_AST__ExitStatm e;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__ExitStatm.baseTypes[0]);
  e = (OOC_AST__ExitStatm)i0;
  i1 = (OOC_INT32)exit;
  *(OOC_INT32*)(_check_pointer(i0, 68133)) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 68148)))), &_td_OOC_AST__TerminalDesc, 68148));
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__ExitStatmDesc_Accept(OOC_AST__ExitStatm exitStatm, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)exitStatm;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 68258)))), OOC_AST__VisitorDesc_VisitExitStatm)),OOC_AST__VisitorDesc_VisitExitStatm)((OOC_AST__Visitor)i0, (OOC_AST__ExitStatm)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_ReturnStatm(OOC_AST__Builder b, OOC_AST__Node _return, OOC_AST__Node expr) {
  register OOC_INT32 i0,i1;
  OOC_AST__ReturnStatm r;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__ReturnStatm.baseTypes[0]);
  r = (OOC_AST__ReturnStatm)i0;
  i1 = (OOC_INT32)_return;
  *(OOC_INT32*)(_check_pointer(i0, 68659)) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 68678)))), &_td_OOC_AST__TerminalDesc, 68678));
  i1 = (OOC_INT32)expr;
  *(OOC_INT32*)((_check_pointer(i0, 68694))+4) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__ReturnStatmDesc_Accept(OOC_AST__ReturnStatm returnStatm, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)returnStatm;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 68815)))), OOC_AST__VisitorDesc_VisitReturnStatm)),OOC_AST__VisitorDesc_VisitReturnStatm)((OOC_AST__Visitor)i0, (OOC_AST__ReturnStatm)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_Catch(OOC_AST__Builder b, OOC_AST__Node _catch, OOC_AST__Node type, OOC_AST__Node lParen, OOC_AST__Node ident, OOC_AST__Node rParen, OOC_AST__Node colon, OOC_AST__NodeList statmSeq) {
  register OOC_INT32 i0,i1,i2;
  OOC_AST__Catch c;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__Catch.baseTypes[0]);
  c = (OOC_AST__Catch)i0;
  i1 = (OOC_INT32)_catch;
  *(OOC_INT32*)(_check_pointer(i0, 69564)) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 69580)))), &_td_OOC_AST__TerminalDesc, 69580));
  i1 = (OOC_INT32)type;
  *(OOC_INT32*)((_check_pointer(i0, 69596))+4) = i1;
  i1 = (OOC_INT32)lParen;
  *(OOC_INT32*)((_check_pointer(i0, 69616))+8) = i1;
  i1 = (OOC_INT32)ident;
  i2 = i1==0;
  if (i2) goto l3;
  *(OOC_INT32*)((_check_pointer(i0, 69699))+12) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 69715)))), &_td_OOC_AST__TerminalDesc, 69715));
  goto l4;
l3:
  *(OOC_INT32*)((_check_pointer(i0, 69668))+12) = 0;
l4:
  i1 = (OOC_INT32)rParen;
  *(OOC_INT32*)((_check_pointer(i0, 69740))+16) = i1;
  i1 = (OOC_INT32)colon;
  *(OOC_INT32*)((_check_pointer(i0, 69764))+20) = i1;
  i1 = (OOC_INT32)statmSeq;
  *(OOC_INT32*)((_check_pointer(i0, 69786))+24) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__CatchDesc_Accept(OOC_AST__Catch _catch, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)_catch;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 69897)))), OOC_AST__VisitorDesc_VisitCatch)),OOC_AST__VisitorDesc_VisitCatch)((OOC_AST__Visitor)i0, (OOC_AST__Catch)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_TryStatm(OOC_AST__Builder b, OOC_AST__Node _try, OOC_AST__NodeList statmSeq, OOC_AST__NodeList catchList, OOC_AST__Node end) {
  register OOC_INT32 i0,i1;
  OOC_AST__TryStatm t;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__TryStatm.baseTypes[0]);
  t = (OOC_AST__TryStatm)i0;
  i1 = (OOC_INT32)_try;
  *(OOC_INT32*)(_check_pointer(i0, 70544)) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 70556)))), &_td_OOC_AST__TerminalDesc, 70556));
  i1 = (OOC_INT32)statmSeq;
  *(OOC_INT32*)((_check_pointer(i0, 70572))+4) = i1;
  i1 = (OOC_INT32)catchList;
  *(OOC_INT32*)((_check_pointer(i0, 70600))+8) = i1;
  i1 = (OOC_INT32)end;
  *(OOC_INT32*)((_check_pointer(i0, 70630))+12) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 70642)))), &_td_OOC_AST__TerminalDesc, 70642));
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__TryStatmDesc_Accept(OOC_AST__TryStatm tryStatm, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)tryStatm;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 70750)))), OOC_AST__VisitorDesc_VisitTryStatm)),OOC_AST__VisitorDesc_VisitTryStatm)((OOC_AST__Visitor)i0, (OOC_AST__TryStatm)i1);
  return;
  ;
}

OOC_AST__Flags OOC_AST__BuilderDesc_Flags(OOC_AST__Builder b, OOC_INT8 context, OOC_AST__Node lBrak, OOC_AST__NodeList flagList, OOC_AST__Node rBrak) {
  register OOC_INT32 i0,i1;
  OOC_AST__Flags f;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__Flags.baseTypes[0]);
  f = (OOC_AST__Flags)i0;
  i1 = context;
  *(OOC_INT8*)(_check_pointer(i0, 70975)) = i1;
  i1 = (OOC_INT32)lBrak;
  *(OOC_INT32*)((_check_pointer(i0, 71002))+4) = i1;
  i1 = (OOC_INT32)flagList;
  *(OOC_INT32*)((_check_pointer(i0, 71025))+8) = i1;
  i1 = (OOC_INT32)rBrak;
  *(OOC_INT32*)((_check_pointer(i0, 71054))+12) = i1;
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
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 71601)))), &_td_OOC_AST__FlagsDesc, 71601)), 71607))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 71617))+4);
  i0 = _check_pointer(i0, 71620);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)(i0+(_check_index(0, i1, OOC_UINT8, 71620))*4);
  i0 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 71624)))), &_td_OOC_AST__TerminalDesc));
  
l5:
  if (i0) goto l7;
  return 0u;
  goto l26;
l7:
  i0 = (OOC_INT32)procFlags;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l25;
  i = 0;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 71881)))), &_td_OOC_AST__FlagsDesc, 71881)), 71887))+8);
  i1 = *(OOC_INT32*)(_check_pointer(i1, 71897));
  i1 = 0<i1;
  if (!i1) goto l25;
  i1=0;
l12_loop:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 71932)))), &_td_OOC_AST__FlagsDesc, 71932)), 71938))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 71948))+4);
  i2 = _check_pointer(i2, 71951);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i1, i3, OOC_UINT32, 71951))*4);
  n = (OOC_AST__Node)i2;
  i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 71972)))), &_td_OOC_AST__TerminalDesc);
  if (i3) goto l15;
  i2=0u;
  goto l17;
l15:
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 71990)))), &_td_OOC_AST__TerminalDesc, 71990)), 71999));
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 72004))+8);
  i2 = (
  _cmp8((const void*)(_check_pointer(i2, 72009)),(const void*)"HAS_BODY"))==0;
  
l17:
  if (!i2) goto l19;
  return 0u;
l19:
  i1 = i1+2;
  i = i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 71881)))), &_td_OOC_AST__FlagsDesc, 71881)), 71887))+8);
  i2 = *(OOC_INT32*)(_check_pointer(i2, 71897));
  i2 = i1<i2;
  if (i2) goto l12_loop;
l25:
  return 1u;
l26:
  _failed_function(71122); return 0;
  ;
}

void OOC_AST__FlagsDesc_Accept(OOC_AST__Flags flags, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)flags;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 72253)))), OOC_AST__VisitorDesc_VisitFlags)),OOC_AST__VisitorDesc_VisitFlags)((OOC_AST__Visitor)i0, (OOC_AST__Flags)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_ProcIdFlag(OOC_AST__Builder b, OOC_AST__Node procId, OOC_AST__Node equal, OOC_AST__Node number) {
  register OOC_INT32 i0,i1;
  OOC_AST__ProcIdFlag pid;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__ProcIdFlag.baseTypes[0]);
  pid = (OOC_AST__ProcIdFlag)i0;
  i1 = (OOC_INT32)procId;
  *(OOC_INT32*)(_check_pointer(i0, 72419)) = i1;
  i1 = (OOC_INT32)equal;
  *(OOC_INT32*)((_check_pointer(i0, 72446))+4) = i1;
  i1 = (OOC_INT32)number;
  *(OOC_INT32*)((_check_pointer(i0, 72471))+8) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__ProcIdFlagDesc_Accept(OOC_AST__ProcIdFlag procIdFlag, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)procIdFlag;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 72595)))), OOC_AST__VisitorDesc_VisitProcIdFlag)),OOC_AST__VisitorDesc_VisitProcIdFlag)((OOC_AST__Visitor)i0, (OOC_AST__ProcIdFlag)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_ModuleFlags(OOC_AST__Builder b, OOC_AST__Node external, OOC_AST__Node callConv, OOC_AST__NodeList moduleFlags, OOC_AST__Node semicolon, OOC_AST__Node link, OOC_AST__NodeList linkSections, OOC_AST__Node end) {
  register OOC_INT32 i0,i1;
  OOC_AST__ModuleFlags mf;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__ModuleFlags.baseTypes[0]);
  mf = (OOC_AST__ModuleFlags)i0;
  i1 = (OOC_INT32)external;
  *(OOC_INT32*)(_check_pointer(i0, 72889)) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 72912)))), &_td_OOC_AST__TerminalDesc, 72912));
  i1 = (OOC_INT32)callConv;
  *(OOC_INT32*)((_check_pointer(i0, 72929))+4) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 72952)))), &_td_OOC_AST__TerminalDesc, 72952));
  i1 = (OOC_INT32)moduleFlags;
  *(OOC_INT32*)((_check_pointer(i0, 72969))+8) = i1;
  i1 = (OOC_INT32)semicolon;
  *(OOC_INT32*)((_check_pointer(i0, 73005))+12) = i1;
  i1 = (OOC_INT32)link;
  *(OOC_INT32*)((_check_pointer(i0, 73037))+16) = i1;
  i1 = (OOC_INT32)linkSections;
  *(OOC_INT32*)((_check_pointer(i0, 73059))+20) = i1;
  i1 = (OOC_INT32)end;
  *(OOC_INT32*)((_check_pointer(i0, 73097))+24) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__ModuleFlagsDesc_Accept(OOC_AST__ModuleFlags moduleFlags, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)moduleFlags;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 73217)))), OOC_AST__VisitorDesc_VisitModuleFlags)),OOC_AST__VisitorDesc_VisitModuleFlags)((OOC_AST__Visitor)i0, (OOC_AST__ModuleFlags)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_LinkFileFlag(OOC_AST__Builder b, OOC_AST__Node file, OOC_AST__Node fileName, OOC_AST__Node addOption, OOC_AST__Node prefixOpt, OOC_AST__Node comma, OOC_AST__Node suffixOpt) {
  register OOC_INT32 i0,i1,i2;
  OOC_AST__LinkFileFlag lff;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__LinkFileFlag.baseTypes[0]);
  lff = (OOC_AST__LinkFileFlag)i0;
  i1 = (OOC_INT32)file;
  *(OOC_INT32*)(_check_pointer(i0, 73432)) = i1;
  i1 = (OOC_INT32)fileName;
  *(OOC_INT32*)((_check_pointer(i0, 73455))+4) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 73478)))), &_td_OOC_AST__TerminalDesc, 73478));
  i1 = (OOC_INT32)addOption;
  *(OOC_INT32*)((_check_pointer(i0, 73496))+8) = i1;
  i1 = (OOC_INT32)prefixOpt;
  i2 = i1==0;
  if (i2) goto l3;
  *(OOC_INT32*)((_check_pointer(i0, 73598))+12) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 73623)))), &_td_OOC_AST__TerminalDesc, 73623));
  goto l4;
l3:
  *(OOC_INT32*)((_check_pointer(i0, 73561))+12) = 0;
l4:
  i1 = (OOC_INT32)comma;
  *(OOC_INT32*)((_check_pointer(i0, 73649))+16) = i1;
  i1 = (OOC_INT32)suffixOpt;
  i2 = i1==0;
  if (i2) goto l7;
  *(OOC_INT32*)((_check_pointer(i0, 73743))+20) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 73768)))), &_td_OOC_AST__TerminalDesc, 73768));
  goto l8;
l7:
  *(OOC_INT32*)((_check_pointer(i0, 73706))+20) = 0;
l8:
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__LinkFileFlagDesc_Accept(OOC_AST__LinkFileFlag linkFileFlag, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)linkFileFlag;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 73897)))), OOC_AST__VisitorDesc_VisitLinkFileFlag)),OOC_AST__VisitorDesc_VisitLinkFileFlag)((OOC_AST__Visitor)i0, (OOC_AST__LinkFileFlag)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_LinkObjFlag(OOC_AST__Builder b, OOC_AST__Node obj, OOC_AST__Node fileName) {
  register OOC_INT32 i0,i1;
  OOC_AST__LinkObjFlag lof;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__LinkObjFlag.baseTypes[0]);
  lof = (OOC_AST__LinkObjFlag)i0;
  i1 = (OOC_INT32)obj;
  *(OOC_INT32*)(_check_pointer(i0, 74071)) = i1;
  i1 = (OOC_INT32)fileName;
  *(OOC_INT32*)((_check_pointer(i0, 74092))+4) = i1;
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__LinkObjFlagDesc_Accept(OOC_AST__LinkObjFlag linkObjFlag, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)linkObjFlag;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 74223)))), OOC_AST__VisitorDesc_VisitLinkObjFlag)),OOC_AST__VisitorDesc_VisitLinkObjFlag)((OOC_AST__Visitor)i0, (OOC_AST__LinkObjFlag)i1);
  return;
  ;
}

OOC_AST__Node OOC_AST__BuilderDesc_LinkLibFlag(OOC_AST__Builder b, OOC_AST__Node lib, OOC_AST__Node libName, OOC_AST__Node lParen, OOC_AST__NodeList dependencies, OOC_AST__Node rParen, OOC_AST__Node addOption, OOC_AST__Node prefixOpt, OOC_AST__Node comma, OOC_AST__Node suffixOpt) {
  register OOC_INT32 i0,i1,i2;
  OOC_AST__LinkLibFlag llf;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_AST__LinkLibFlag.baseTypes[0]);
  llf = (OOC_AST__LinkLibFlag)i0;
  i1 = (OOC_INT32)lib;
  *(OOC_INT32*)(_check_pointer(i0, 74516)) = i1;
  i1 = (OOC_INT32)libName;
  *(OOC_INT32*)((_check_pointer(i0, 74537))+4) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 74558)))), &_td_OOC_AST__TerminalDesc, 74558));
  i1 = (OOC_INT32)lParen;
  *(OOC_INT32*)((_check_pointer(i0, 74576))+8) = i1;
  i1 = (OOC_INT32)dependencies;
  i2 = i1==0;
  if (i2) goto l3;
  *(OOC_INT32*)((_check_pointer(i0, 74679))+12) = i1;
  goto l4;
l3:
  *(OOC_INT32*)((_check_pointer(i0, 74638))+12) = 0;
l4:
  i1 = (OOC_INT32)rParen;
  *(OOC_INT32*)((_check_pointer(i0, 74727))+16) = i1;
  i1 = (OOC_INT32)addOption;
  *(OOC_INT32*)((_check_pointer(i0, 74754))+20) = i1;
  i1 = (OOC_INT32)prefixOpt;
  i2 = i1==0;
  if (i2) goto l7;
  *(OOC_INT32*)((_check_pointer(i0, 74856))+24) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 74881)))), &_td_OOC_AST__TerminalDesc, 74881));
  goto l8;
l7:
  *(OOC_INT32*)((_check_pointer(i0, 74819))+24) = 0;
l8:
  i1 = (OOC_INT32)comma;
  *(OOC_INT32*)((_check_pointer(i0, 74907))+28) = i1;
  i1 = (OOC_INT32)suffixOpt;
  i2 = i1==0;
  if (i2) goto l11;
  *(OOC_INT32*)((_check_pointer(i0, 75001))+32) = (_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 75026)))), &_td_OOC_AST__TerminalDesc, 75026));
  goto l12;
l11:
  *(OOC_INT32*)((_check_pointer(i0, 74964))+32) = 0;
l12:
  return (OOC_AST__Node)i0;
  ;
}

void OOC_AST__LinkLibFlagDesc_Accept(OOC_AST__LinkLibFlag linkLibFlag, OOC_AST__Visitor v) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)linkLibFlag;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 75152)))), OOC_AST__VisitorDesc_VisitLinkLibFlag)),OOC_AST__VisitorDesc_VisitLinkLibFlag)((OOC_AST__Visitor)i0, (OOC_AST__LinkLibFlag)i1);
  return;
  ;
}

void OOC_OOC_AST_init(void) {

  return;
  ;
}

/* --- */
