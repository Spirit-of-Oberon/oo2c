#include <OOC/Make/TranslateToIA32.d>
#include <__oo2c.h>
#include <setjmp.h>

void OOC_Make_TranslateToIA32__InitTranslator(OOC_Make_TranslateToIA32__Translator t, OOC_Repository__Module module) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)t;
  *(OOC_INT32*)(_check_pointer(i0, 1893)) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 1910))+12) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 1934))+16) = (-1);
  i1 = (OOC_INT32)module;
  *(OOC_INT32*)((_check_pointer(i0, 1960))+4) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 1985))+8) = 0;
  return;
  ;
}

void OOC_Make_TranslateToIA32__TranslatorDesc_SetWriter(OOC_Make_TranslateToIA32__Translator t, OOC_IA32_Writer__Writer w, OOC_SymbolTable__Module symTab) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)t;
  i1 = (OOC_INT32)w;
  *(OOC_INT32*)(_check_pointer(i0, 2115)) = i1;
  i1 = (OOC_INT32)symTab;
  *(OOC_INT32*)((_check_pointer(i0, 2130))+8) = i1;
  return;
  ;
}

void OOC_Make_TranslateToIA32__TranslatorDesc_SetProcedureList(OOC_Make_TranslateToIA32__Translator t, OOC_IR__ProcedureList procList) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)t;
  i1 = (OOC_INT32)procList;
  *(OOC_INT32*)((_check_pointer(i0, 2255))+12) = i1;
  return;
  ;
}

void OOC_Make_TranslateToIA32__TranslatorDesc_WriteProcBody(OOC_Make_TranslateToIA32__Translator t, OOC_IR__Procedure proc) {

  return;
  ;
}

void OOC_Make_TranslateToIA32__TranslatorDesc_WriteProcedure(OOC_Make_TranslateToIA32__Translator t, OOC_INT32 procIndex) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_INT32 oldProcIndex;

  i0 = (OOC_INT32)t;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 2525))+16);
  oldProcIndex = i1;
  i2 = procIndex;
  *(OOC_INT32*)((_check_pointer(i0, 2545))+16) = i2;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2601))+12);
  i3 = _check_pointer(i3, 2611);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 2611))*4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2583)))), OOC_Make_TranslateToIA32__TranslatorDesc_WriteProcBody)),OOC_Make_TranslateToIA32__TranslatorDesc_WriteProcBody)((OOC_Make_TranslateToIA32__Translator)i0, (OOC_IR__Procedure)i2);
  *(OOC_INT32*)((_check_pointer(i0, 2635))+16) = i1;
  return;
  ;
}

void OOC_Make_TranslateToIA32__TranslatorDesc_WriteNestedProcedures(OOC_Make_TranslateToIA32__Translator t) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_SymbolTable__ProcDecl currentDecl;
  OOC_INT32 i;

  i0 = (OOC_INT32)t;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 3187))+16);
  i1 = i1>=0;
  if (!i1) goto l14;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3280))+12);
  i1 = _check_pointer(i1, 3290);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i3 = *(OOC_INT32*)((_check_pointer(i0, 3292))+16);
  i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(i3, i2, OOC_UINT32, 3290))*4);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3306))+4);
  currentDecl = (OOC_SymbolTable__ProcDecl)i1;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 3326))+16);
  i2 = i2+1;
  i = i2;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3366))+12);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 3376)), 0);
  i3 = i2!=i3;
  if (!i3) goto l14;
l5_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3396))+12);
  i3 = _check_pointer(i3, 3406);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 3406))*4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 3409))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 3415))+4);
  i3 = i3==i1;
  if (!i3) goto l8;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3455));
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3455));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 3458)))), OOC_IA32_Writer__WriterDesc_Newline)),OOC_IA32_Writer__WriterDesc_Newline)((OOC_IA32_Writer__Writer)i4);
  OOC_Make_TranslateToIA32__TranslatorDesc_WriteProcedure((OOC_Make_TranslateToIA32__Translator)i0, i2);
l8:
  i2 = i2+1;
  i = i2;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3366))+12);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 3376)), 0);
  i3 = i2!=i3;
  if (i3) goto l5_loop;
l14:
  return;
  ;
}

static void OOC_Make_TranslateToIA32__WriteCodeFile(OOC_IA32_Writer__Writer w, OOC_Repository__Module m, OOC_SymbolTable__Module symTab, OOC_IR__Module moduleIR, OOC_Make_TranslateToIA32__Translator translator) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_INT32 i;

  i0 = (OOC_INT32)translator;
  i1 = (OOC_INT32)w;
  i2 = (OOC_INT32)symTab;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3776)))), OOC_Make_TranslateToIA32__TranslatorDesc_SetWriter)),OOC_Make_TranslateToIA32__TranslatorDesc_SetWriter)((OOC_Make_TranslateToIA32__Translator)i0, (OOC_IA32_Writer__Writer)i1, (OOC_SymbolTable__Module)i2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3807)))), OOC_IA32_Writer__WriterDesc_Section)),OOC_IA32_Writer__WriterDesc_Section)((OOC_IA32_Writer__Writer)i1, ".text", 6);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3833)))), OOC_IA32_Writer__WriterDesc_Label)),OOC_IA32_Writer__WriterDesc_Label)((OOC_IA32_Writer__Writer)i1, (Object__String)((OOC_INT32)_c0));
  OOC_IA32_RuntimeData__Write((OOC_IA32_Writer__Writer)i1, (OOC_SymbolTable__Module)i2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3918)))), OOC_IA32_Writer__WriterDesc_Section)),OOC_IA32_Writer__WriterDesc_Section)((OOC_IA32_Writer__Writer)i1, ".text", 6);
  i2 = (OOC_INT32)moduleIR;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 3981))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3953)))), OOC_Make_TranslateToIA32__TranslatorDesc_SetProcedureList)),OOC_Make_TranslateToIA32__TranslatorDesc_SetProcedureList)((OOC_Make_TranslateToIA32__Translator)i0, (OOC_IR__ProcedureList)i3);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 4025))+8);
  i = 0;
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 4035)), 0);
  i4 = 0<i3;
  if (!i4) goto l11;
  i4=0;
l3_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 4061))+8);
  i5 = _check_pointer(i5, 4071);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 4071))*4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 4074))+4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 4080))+4);
  i5 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 4089)))), &_td_OOC_SymbolTable__ModuleDesc);
  if (!i5) goto l6;
  OOC_Make_TranslateToIA32__TranslatorDesc_WriteProcedure((OOC_Make_TranslateToIA32__Translator)i0, i4);
l6:
  i4 = i4+1;
  i = i4;
  i5 = i4<i3;
  if (i5) goto l3_loop;
l11:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 4208))+12);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4183)))), OOC_Make_TranslateToIA32__TranslatorDesc_WriteProcBody)),OOC_Make_TranslateToIA32__TranslatorDesc_WriteProcBody)((OOC_Make_TranslateToIA32__Translator)i0, (OOC_IR__Procedure)i2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4237)))), OOC_Make_TranslateToIA32__TranslatorDesc_SetProcedureList)),OOC_Make_TranslateToIA32__TranslatorDesc_SetProcedureList)((OOC_Make_TranslateToIA32__Translator)i0, (OOC_IR__ProcedureList)(OOC_INT32)0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4269)))), OOC_IA32_Writer__WriterDesc_WriteStringData)),OOC_IA32_Writer__WriterDesc_WriteStringData)((OOC_IA32_Writer__Writer)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4300)))), OOC_IA32_Writer__WriterDesc_Label)),OOC_IA32_Writer__WriterDesc_Label)((OOC_IA32_Writer__Writer)i1, (Object__String)((OOC_INT32)_c1));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4326)))), OOC_IA32_Writer__WriterDesc_Directive)),OOC_IA32_Writer__WriterDesc_Directive)((OOC_IA32_Writer__Writer)i1, ".ident\011\"OOC: 0.1\"", 18);
  return;
  ;
}

OOC_Error__List OOC_Make_TranslateToIA32__Run(OOC_Repository__Module m, Object__String libraryName, OOC_SymbolTable_Uses__Uses uses, OOC_CHAR8 writeAST, OOC_CHAR8 writeIR, OOC_Make_TranslateToIA32__Translator translator) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_AST__Node ast;
  OOC_SymbolTable__Module symTab;
  OOC_Config_Pragmas__History pragmaHistory;
  OOC_Error__List errList;
  OOC_IR__Module moduleIR;
  ADT_Dictionary_AddressKey__Dictionary exports;
  OOC_IA32_Writer__Writer w;
  auto void OOC_Make_TranslateToIA32__Run_CloseFile(OOC_IA32_Writer__Writer w);
    
    void OOC_Make_TranslateToIA32__Run_CloseFile(OOC_IA32_Writer__Writer w) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)w;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l4;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4934)))), OOC_IA32_Writer__WriterDesc_Newline)),OOC_IA32_Writer__WriterDesc_Newline)((OOC_IA32_Writer__Writer)i0);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4954)))), OOC_IA32_Writer__WriterDesc_Close)),OOC_IA32_Writer__WriterDesc_Close)((OOC_IA32_Writer__Writer)i0);
l4:
      return;
      ;
    }


  i0 = (OOC_INT32)m;
  i1 = (OOC_INT32)libraryName;
  i2 = (OOC_INT32)uses;
  OOC_Auxiliary_ParseModule__ParseModule((OOC_Repository__Module)i0, 1u, 1u, 0u, 0u, (Object__String)i1, (OOC_SymbolTable_Uses__Uses)i2, (void*)(OOC_INT32)&ast, (void*)(OOC_INT32)&symTab, (void*)(OOC_INT32)&pragmaHistory, (void*)(OOC_INT32)&errList);
  i1 = (OOC_INT32)errList;
  i1 = OOC_Error__ListDesc_NoErrors((OOC_Error__List)i1);
  if (!i1) goto l12;
  i1 = writeAST;
  if (!i1) goto l5;
  i1 = (OOC_INT32)ast;
  i3 = (OOC_INT32)IO_StdChannels__stdout;
  OOC_AST_XML__Write((IO__ByteChannel)i3, (OOC_AST__Module)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5482)))), &_td_OOC_AST__ModuleDesc, 5482)));
l5:
  i1 = (OOC_INT32)ast;
  i3 = (OOC_INT32)symTab;
  i4 = (OOC_INT32)pragmaHistory;
  i5 = (OOC_INT32)errList;
  i6 = (OOC_INT32)OOC_IR_ConstFold__NewConstFold();
  i2 = (OOC_INT32)OOC_IR__NewBuilder((OOC_SymbolTable__Module)i3, (OOC_SymbolTable_Uses__Uses)i2, (OOC_Config_Pragmas__History)i4, (OOC_Error__List)i5, (OOC_IR__ConstFold)i6);
  i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR((OOC_AST__Module)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5548)))), &_td_OOC_AST__ModuleDesc, 5548)), (OOC_SymbolTable__Module)i3, (OOC_IR__Builder)i2);
  moduleIR = (OOC_IR__Module)i1;
  i2 = writeIR;
  if (!i2) goto l8;
  i2 = (OOC_INT32)IO_StdChannels__stdout;
  OOC_IR_XML__Write((IO__ByteChannel)i2, (OOC_IR__Module)i1);
l8:
  i2 = (OOC_INT32)symTab;
  i2 = (OOC_INT32)OOC_SymbolTable_Exports__GetExports((OOC_SymbolTable__Module)i2, 1u);
  exports = (ADT_Dictionary_AddressKey__Dictionary)i2;
  i2 = (OOC_INT32)errList;
  i2 = OOC_Error__ListDesc_NoErrors((OOC_Error__List)i2);
  if (!i2) goto l12;
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6099)))), OOC_Repository__ModuleDesc_GetOutputChannel)),OOC_Repository__ModuleDesc_GetOutputChannel)((OOC_Repository__Module)i0, 14, 1u);
  i2 = (OOC_INT32)OOC_IA32_Writer__NewWriter((IO__ByteChannel)i2);
  w = (OOC_IA32_Writer__Writer)i2;
  i3 = (OOC_INT32)translator;
  i4 = (OOC_INT32)symTab;
  OOC_Make_TranslateToIA32__WriteCodeFile((OOC_IA32_Writer__Writer)i2, (OOC_Repository__Module)i0, (OOC_SymbolTable__Module)i4, (OOC_IR__Module)i1, (OOC_Make_TranslateToIA32__Translator)i3);
  i1 = (OOC_INT32)symTab;
  i3 = (OOC_INT32)errList;
  OOC_Auxiliary_WriteSymbolFile__WriteSymbolFile((OOC_Repository__Module)i0, (OOC_SymbolTable__Module)i1, (OOC_Error__List)i3);
  OOC_Make_TranslateToIA32__Run_CloseFile((OOC_IA32_Writer__Writer)i2);
l12:
  i0 = (OOC_INT32)errList;
  return (OOC_Error__List)i0;
  ;
}

void OOC_OOC_Make_TranslateToIA32_init(void) {
  _c0 = Object__NewLatin1Region(".Ltext0", 8, 0, 7);
  _c1 = Object__NewLatin1Region(".Letext", 8, 0, 7);

  return;
  ;
}

/* --- */
