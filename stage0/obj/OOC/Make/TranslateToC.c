#include <OOC/Make/TranslateToC.d>
#include <__oo2c.h>
#include <setjmp.h>

void OOC_Make_TranslateToC__InitTranslator(OOC_Make_TranslateToC__Translator t) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)t;
  *(OOC_INT32*)(_check_pointer(i0, 2199)) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 2216))+4) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 2234))+8) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 2258))+12) = (-1);
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_C_Naming__QualTypeData.baseTypes[0]);
  OOC_C_Naming__QualTypeDataDesc_INIT((OOC_C_Naming__QualTypeData)i1);
  *(OOC_INT32*)((_check_pointer(i0, 2284))+16) = i1;
  return;
  ;
}

void OOC_Make_TranslateToC__TranslatorDesc_SetWriter(OOC_Make_TranslateToC__Translator t, OOC_C_DeclWriter__Writer w) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)t;
  i1 = (OOC_INT32)w;
  *(OOC_INT32*)(_check_pointer(i0, 2420)) = i1;
  return;
  ;
}

void OOC_Make_TranslateToC__TranslatorDesc_SetProcedureList(OOC_Make_TranslateToC__Translator t, OOC_IR__ProcedureList procList) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)t;
  i1 = (OOC_INT32)procList;
  *(OOC_INT32*)((_check_pointer(i0, 2535))+8) = i1;
  return;
  ;
}

void OOC_Make_TranslateToC__TranslatorDesc_SetDataWriter(OOC_Make_TranslateToC__Translator t, OOC_C_DeclWriter__Writer wd) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)t;
  i1 = (OOC_INT32)wd;
  *(OOC_INT32*)((_check_pointer(i0, 2663))+4) = i1;
  return;
  ;
}

void OOC_Make_TranslateToC__TranslatorDesc_WriteProcBody(OOC_Make_TranslateToC__Translator t, OOC_IR__Procedure proc) {

  return;
  ;
}

void OOC_Make_TranslateToC__TranslatorDesc_WriteProcedure(OOC_Make_TranslateToC__Translator t, OOC_INT32 procIndex) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 oldProcIndex;
  OOC_C_DeclWriter__Writer w;
  OOC_C_DeclWriter__Declaration d;

  i0 = (OOC_INT32)t;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 2975))+12);
  oldProcIndex = i1;
  i2 = procIndex;
  *(OOC_INT32*)((_check_pointer(i0, 2995))+12) = i2;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3109));
  w = (OOC_C_DeclWriter__Writer)i3;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3148))+8);
  i4 = _check_pointer(i4, 3158);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i2, i5, OOC_UINT32, 3158))*4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 3169))+4);
  i4 = (OOC_INT32)OOC_C_ConvertDecl__GetProc((OOC_C_DeclWriter__Writer)i3, (OOC_SymbolTable__ProcDecl)i4, 0u);
  d = (OOC_C_DeclWriter__Declaration)i4;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 3190)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i3);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 3206)))), OOC_C_DeclWriter__WriterDesc_WriteDeclaration)),OOC_C_DeclWriter__WriterDesc_WriteDeclaration)((OOC_C_DeclWriter__Writer)i3, (OOC_C_DeclWriter__Declaration)i4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 3235)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i3, " {", 3);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3280))+8);
  i4 = _check_pointer(i4, 3290);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i2, i5, OOC_UINT32, 3290))*4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3262)))), OOC_Make_TranslateToC__TranslatorDesc_WriteProcBody)),OOC_Make_TranslateToC__TranslatorDesc_WriteProcBody)((OOC_Make_TranslateToC__Translator)i0, (OOC_IR__Procedure)i2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 3309)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i3);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 3325)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i3, "}", 2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 3351)))), OOC_C_DeclWriter__WriterDesc_WriteLn)),OOC_C_DeclWriter__WriterDesc_WriteLn)((OOC_C_DeclWriter__Writer)i3);
  *(OOC_INT32*)((_check_pointer(i0, 3368))+12) = i1;
  return;
  ;
}

void OOC_Make_TranslateToC__TranslatorDesc_WriteNestedProcedures(OOC_Make_TranslateToC__Translator t) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_SymbolTable__ProcDecl currentDecl;
  OOC_INT32 i;

  i0 = (OOC_INT32)t;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 3920))+12);
  i1 = i1>=0;
  if (!i1) goto l14;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4013))+8);
  i1 = _check_pointer(i1, 4023);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i3 = *(OOC_INT32*)((_check_pointer(i0, 4025))+12);
  i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(i3, i2, OOC_UINT32, 4023))*4);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4039))+4);
  currentDecl = (OOC_SymbolTable__ProcDecl)i1;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 4059))+12);
  i2 = i2+1;
  i = i2;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4099))+8);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 4109)), 0);
  i3 = i2!=i3;
  if (!i3) goto l14;
l5_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4129))+8);
  i3 = _check_pointer(i3, 4139);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 4139))*4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 4142))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 4148))+4);
  i3 = i3==i1;
  if (!i3) goto l8;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4188));
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4188));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 4191)))), OOC_C_DeclWriter__WriterDesc_Indent)),OOC_C_DeclWriter__WriterDesc_Indent)((OOC_C_DeclWriter__Writer)i4, 1);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4216));
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4216));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 4219)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i4);
  OOC_Make_TranslateToC__TranslatorDesc_WriteProcedure((OOC_Make_TranslateToC__Translator)i0, i2);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4274));
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4274));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 4277)))), OOC_C_DeclWriter__WriterDesc_Indent)),OOC_C_DeclWriter__WriterDesc_Indent)((OOC_C_DeclWriter__Writer)i4, (-1));
l8:
  i2 = i2+1;
  i = i2;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4099))+8);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 4109)), 0);
  i3 = i2!=i3;
  if (i3) goto l5_loop;
l14:
  return;
  ;
}

static void OOC_Make_TranslateToC__WriteModuleName(OOC_C_DeclWriter__Writer w, const OOC_CHAR8 prefix__ref[], OOC_LEN prefix_0d, OOC_Repository__Module module, const OOC_CHAR8 suffix__ref[], OOC_LEN suffix_0d, OOC_CHAR8 newline) {
  register OOC_INT32 i0,i1;
  OOC_ALLOCATE_VPAR(prefix,OOC_CHAR8 ,prefix_0d)
  OOC_ALLOCATE_VPAR(suffix,OOC_CHAR8 ,suffix_0d)
  OOC_CHAR8 str[1024];
  OOC_INT32 i;

  OOC_INITIALIZE_VPAR(prefix__ref,prefix,OOC_CHAR8 ,prefix_0d)
  OOC_INITIALIZE_VPAR(suffix__ref,suffix,OOC_CHAR8 ,suffix_0d)
  i0 = (OOC_INT32)module;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4643))+4);
  _copy_8((const void*)(_check_pointer(i0, 4649)),(void*)(OOC_INT32)str,1024);
  i = 0;
  i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, 1024, OOC_UINT32, 4684)));
  i0 = i0!=0u;
  if (!i0) goto l11;
  i0=0;
l3_loop:
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, 1024, OOC_UINT32, 4710)));
  i1 = i1==58u;
  if (!i1) goto l6;
  *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, 1024, OOC_UINT32, 4729))) = 95u;
l6:
  i0 = i0+1;
  i = i0;
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, 1024, OOC_UINT32, 4684)));
  i1 = i1!=0u;
  if (i1) goto l3_loop;
l11:
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4773)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, (void*)(OOC_INT32)prefix, prefix_0d);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4802)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, (void*)(OOC_INT32)str, 1024);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4828)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, (void*)(OOC_INT32)suffix, suffix_0d);
  i1 = newline;
  if (!i1) goto l14;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4879)))), OOC_C_DeclWriter__WriterDesc_WriteLn)),OOC_C_DeclWriter__WriterDesc_WriteLn)((OOC_C_DeclWriter__Writer)i0);
l14:
  return;
  ;
}

static void OOC_Make_TranslateToC__WriteHeaderFile(OOC_C_DeclWriter__Writer w, OOC_Repository__Module m, OOC_SymbolTable__Module symTab, ADT_Dictionary_AddressKey__Dictionary exports, OOC_C_Naming__QualTypeData qtdData) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)m;
  i1 = (OOC_INT32)w;
  OOC_Make_TranslateToC__WriteModuleName((OOC_C_DeclWriter__Writer)i1, "#ifndef _MODULE_", 17, (OOC_Repository__Module)i0, "_", 2, 1u);
  OOC_Make_TranslateToC__WriteModuleName((OOC_C_DeclWriter__Writer)i1, "#define _MODULE_", 17, (OOC_Repository__Module)i0, "_", 2, 1u);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5250)))), OOC_C_DeclWriter__WriterDesc_WriteLn)),OOC_C_DeclWriter__WriterDesc_WriteLn)((OOC_C_DeclWriter__Writer)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5370)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "#include <__typemap.h>", 23);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5417)))), OOC_C_DeclWriter__WriterDesc_WriteLn)),OOC_C_DeclWriter__WriterDesc_WriteLn)((OOC_C_DeclWriter__Writer)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5552)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i1, "#include <RT0.oh>", 18);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5636)))), OOC_C_DeclWriter__WriterDesc_WriteLn)),OOC_C_DeclWriter__WriterDesc_WriteLn)((OOC_C_DeclWriter__Writer)i1);
  i2 = (OOC_INT32)symTab;
  i3 = (OOC_INT32)exports;
  OOC_C_ConvertDecl__ConvertSymTab((OOC_C_DeclWriter__Writer)i1, (OOC_Repository__Module)i0, (OOC_SymbolTable__Module)i2, (ADT_Dictionary_AddressKey__Dictionary)i3, 1u);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5718)))), OOC_C_DeclWriter__WriterDesc_WriteDeclarationList)),OOC_C_DeclWriter__WriterDesc_WriteDeclarationList)((OOC_C_DeclWriter__Writer)i1);
  i3 = (OOC_INT32)qtdData;
  OOC_C_RuntimeData__Write((OOC_C_DeclWriter__Writer)i1, (OOC_SymbolTable__Module)i2, (OOC_C_Naming__QualTypeData)i3, 1u);
  OOC_Make_TranslateToC__WriteModuleName((OOC_C_DeclWriter__Writer)i1, "#endif /* _MODULE_", 19, (OOC_Repository__Module)i0, "_ */", 5, 1u);
  return;
  ;
}

static void OOC_Make_TranslateToC__WriteDeclFile(OOC_C_DeclWriter__Writer w, OOC_Repository__Module m, OOC_SymbolTable__Module symTab, ADT_Dictionary_AddressKey__Dictionary exports, OOC_C_Naming__QualTypeData qtdData) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)m;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6090)))), OOC_C_DeclWriter__WriterDesc_WriteModuleInclude)),OOC_C_DeclWriter__WriterDesc_WriteModuleInclude)((OOC_C_DeclWriter__Writer)i0, (OOC_Repository__Module)i1, 13);
  i2 = (OOC_INT32)symTab;
  i3 = (OOC_INT32)exports;
  OOC_C_ConvertDecl__ConvertSymTab((OOC_C_DeclWriter__Writer)i0, (OOC_Repository__Module)i1, (OOC_SymbolTable__Module)i2, (ADT_Dictionary_AddressKey__Dictionary)i3, 0u);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6213)))), OOC_C_DeclWriter__WriterDesc_WriteDeclarationList)),OOC_C_DeclWriter__WriterDesc_WriteDeclarationList)((OOC_C_DeclWriter__Writer)i0);
  i1 = (OOC_INT32)qtdData;
  OOC_C_RuntimeData__Write((OOC_C_DeclWriter__Writer)i0, (OOC_SymbolTable__Module)i2, (OOC_C_Naming__QualTypeData)i1, 0u);
  return;
  ;
}

static void OOC_Make_TranslateToC__WriteCodeFile(OOC_C_DeclWriter__Writer w, OOC_C_DeclWriter__Writer wd, OOC_Repository__Module m, OOC_IR__Module moduleIR, OOC_Make_TranslateToC__Translator translator) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  OOC_INT32 i;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)m;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6489)))), OOC_C_DeclWriter__WriterDesc_WriteModuleInclude)),OOC_C_DeclWriter__WriterDesc_WriteModuleInclude)((OOC_C_DeclWriter__Writer)i0, (OOC_Repository__Module)i1, 12);
  i2 = (OOC_INT32)translator;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 6552)))), OOC_Make_TranslateToC__TranslatorDesc_SetWriter)),OOC_Make_TranslateToC__TranslatorDesc_SetWriter)((OOC_Make_TranslateToC__Translator)i2, (OOC_C_DeclWriter__Writer)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6768)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "#include <__oo2c.h>", 20);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6812)))), OOC_C_DeclWriter__WriterDesc_WriteLn)),OOC_C_DeclWriter__WriterDesc_WriteLn)((OOC_C_DeclWriter__Writer)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6828)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "#include <setjmp.h>", 20);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6872)))), OOC_C_DeclWriter__WriterDesc_WriteLn)),OOC_C_DeclWriter__WriterDesc_WriteLn)((OOC_C_DeclWriter__Writer)i0);
  i3 = (OOC_INT32)wd;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 6897)))), OOC_Make_TranslateToC__TranslatorDesc_SetDataWriter)),OOC_Make_TranslateToC__TranslatorDesc_SetDataWriter)((OOC_Make_TranslateToC__Translator)i2, (OOC_C_DeclWriter__Writer)i3);
  i3 = (OOC_INT32)moduleIR;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 6961))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 6933)))), OOC_Make_TranslateToC__TranslatorDesc_SetProcedureList)),OOC_Make_TranslateToC__TranslatorDesc_SetProcedureList)((OOC_Make_TranslateToC__Translator)i2, (OOC_IR__ProcedureList)i4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 7005))+8);
  i = 0;
  i4 = OOC_ARRAY_LENGTH((_check_pointer(i4, 7015)), 0);
  i5 = 0<i4;
  if (!i5) goto l11;
  i5=0;
l3_loop:
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 7041))+8);
  i6 = _check_pointer(i6, 7051);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i5, i7, OOC_UINT32, 7051))*4);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 7054))+4);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 7060))+4);
  i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 7069)))), &_td_OOC_SymbolTable__ModuleDesc);
  if (!i6) goto l6;
  OOC_Make_TranslateToC__TranslatorDesc_WriteProcedure((OOC_Make_TranslateToC__Translator)i2, i5);
l6:
  i5 = i5+1;
  i = i5;
  i6 = i5<i4;
  if (i6) goto l3_loop;
l11:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7159)))), OOC_C_DeclWriter__WriterDesc_WriteLn)),OOC_C_DeclWriter__WriterDesc_WriteLn)((OOC_C_DeclWriter__Writer)i0);
  OOC_Make_TranslateToC__WriteModuleName((OOC_C_DeclWriter__Writer)i0, "void OOC_", 10, (OOC_Repository__Module)i1, "_init(void) {", 14, 0u);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 7274))+12);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 7249)))), OOC_Make_TranslateToC__TranslatorDesc_WriteProcBody)),OOC_Make_TranslateToC__TranslatorDesc_WriteProcBody)((OOC_Make_TranslateToC__Translator)i2, (OOC_IR__Procedure)i3);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7294)))), OOC_C_DeclWriter__WriterDesc_WriteLn)),OOC_C_DeclWriter__WriterDesc_WriteLn)((OOC_C_DeclWriter__Writer)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7310)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "}", 2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7336)))), OOC_C_DeclWriter__WriterDesc_WriteLn)),OOC_C_DeclWriter__WriterDesc_WriteLn)((OOC_C_DeclWriter__Writer)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7353)))), OOC_C_DeclWriter__WriterDesc_WriteLn)),OOC_C_DeclWriter__WriterDesc_WriteLn)((OOC_C_DeclWriter__Writer)i0);
  OOC_Make_TranslateToC__WriteModuleName((OOC_C_DeclWriter__Writer)i0, "void OOC_", 10, (OOC_Repository__Module)i1, "_destroy(void) {", 17, 0u);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7495)))), OOC_C_DeclWriter__WriterDesc_WriteLn)),OOC_C_DeclWriter__WriterDesc_WriteLn)((OOC_C_DeclWriter__Writer)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7511)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "}", 2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7537)))), OOC_C_DeclWriter__WriterDesc_WriteLn)),OOC_C_DeclWriter__WriterDesc_WriteLn)((OOC_C_DeclWriter__Writer)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 7563)))), OOC_Make_TranslateToC__TranslatorDesc_SetProcedureList)),OOC_Make_TranslateToC__TranslatorDesc_SetProcedureList)((OOC_Make_TranslateToC__Translator)i2, (OOC_IR__ProcedureList)(OOC_INT32)0);
  return;
  ;
}

OOC_Error__List OOC_Make_TranslateToC__Run(OOC_Repository__Module m, Object__String libraryName, OOC_CHAR8 analysisOnly, OOC_SymbolTable_Uses__Uses uses, OOC_CHAR8 writeAST, OOC_CHAR8 writeIR, OOC_Make_TranslateToC__Translator translator) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_Error__List errList;
  OOC_Config_Pragmas__History pragmaHistory;
  OOC_SymbolTable__Module symTab;
  OOC_AST__Node ast;
  OOC_IR__Module module;
  ADT_Dictionary_AddressKey__Dictionary exports;
  OOC_C_DeclWriter__Writer wd;
  OOC_C_DeclWriter__Writer wh;
  OOC_C_DeclWriter__Writer wc;
  auto OOC_C_DeclWriter__Writer OOC_Make_TranslateToC__Run_WriteFile(OOC_INT8 fileId);
  auto void OOC_Make_TranslateToC__Run_CloseFile(OOC_C_DeclWriter__Writer w);
    
    OOC_C_DeclWriter__Writer OOC_Make_TranslateToC__Run_WriteFile(OOC_INT8 fileId) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      IO__ByteChannel ch;
      OOC_C_DeclWriter__Writer w;

      i0 = (OOC_INT32)m;
      i1 = fileId;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8290)))), OOC_Repository__ModuleDesc_GetOutputChannel)),OOC_Repository__ModuleDesc_GetOutputChannel)((OOC_Repository__Module)i0, i1, 1u);
      ch = (IO__ByteChannel)i0;
      i2 = (OOC_INT32)m;
      i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 8363)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i2, i1, 0u);
      i0 = (OOC_INT32)OOC_C_DeclWriter__NewWriter((IO__ByteChannel)i0, (URI__HierarchicalURI)i2);
      w = (OOC_C_DeclWriter__Writer)i0;
      switch (i1) {
      case 13:
        i1 = (OOC_INT32)translator;
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8504))+16);
        i2 = (OOC_INT32)symTab;
        i3 = (OOC_INT32)exports;
        i4 = (OOC_INT32)m;
        OOC_Make_TranslateToC__WriteHeaderFile((OOC_C_DeclWriter__Writer)i0, (OOC_Repository__Module)i4, (OOC_SymbolTable__Module)i2, (ADT_Dictionary_AddressKey__Dictionary)i3, (OOC_C_Naming__QualTypeData)i1);
        goto l6;
      case 12:
        goto l6;
      case 11:
        i1 = (OOC_INT32)wd;
        i2 = (OOC_INT32)module;
        i3 = (OOC_INT32)translator;
        i4 = (OOC_INT32)m;
        OOC_Make_TranslateToC__WriteCodeFile((OOC_C_DeclWriter__Writer)i0, (OOC_C_DeclWriter__Writer)i1, (OOC_Repository__Module)i4, (OOC_IR__Module)i2, (OOC_Make_TranslateToC__Translator)i3);
        goto l6;
      default:
        _failed_case(i1, 8396);
        goto l6;
      }
l6:
      return (OOC_C_DeclWriter__Writer)i0;
      ;
    }

    
    void OOC_Make_TranslateToC__Run_CloseFile(OOC_C_DeclWriter__Writer w) {
      register OOC_INT32 i0,i1;

      i0 = (OOC_INT32)w;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l6;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8786)))), OOC_C_DeclWriter__WriterDesc_WriteLn)),OOC_C_DeclWriter__WriterDesc_WriteLn)((OOC_C_DeclWriter__Writer)i0);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8806)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "/* --- */", 10);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8844)))), OOC_C_DeclWriter__WriterDesc_WriteLn)),OOC_C_DeclWriter__WriterDesc_WriteLn)((OOC_C_DeclWriter__Writer)i0);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8868))+8);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8879))+4);
      i1 = i1!=(OOC_INT32)0;
      if (!i1) goto l5;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8915))+8);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8926))+4);
      Exception__Raise((void*)i1);
l5:
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8957)))), OOC_C_DeclWriter__WriterDesc_Close)),OOC_C_DeclWriter__WriterDesc_Close)((OOC_C_DeclWriter__Writer)i0);
l6:
      return;
      ;
    }


  i0 = (OOC_INT32)uses;
  i1 = (OOC_INT32)libraryName;
  i2 = (OOC_INT32)m;
  OOC_Auxiliary_ParseModule__ParseModule((OOC_Repository__Module)i2, 1u, 1u, 0u, 0u, (Object__String)i1, (OOC_SymbolTable_Uses__Uses)i0, (void*)(OOC_INT32)&ast, (void*)(OOC_INT32)&symTab, (void*)(OOC_INT32)&pragmaHistory, (void*)(OOC_INT32)&errList);
  i1 = (OOC_INT32)errList;
  i1 = OOC_Error__ListDesc_NoErrors((OOC_Error__List)i1);
  if (!i1) goto l33;
  i1 = writeAST;
  if (!i1) goto l5;
  i1 = (OOC_INT32)ast;
  i3 = (OOC_INT32)IO_StdChannels__stdout;
  OOC_AST_XML__Write((IO__ByteChannel)i3, (OOC_AST__Module)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9485)))), &_td_OOC_AST__ModuleDesc, 9485)));
l5:
  i1 = (OOC_INT32)OOC_IR_ConstFold__NewConstFold();
  i3 = (OOC_INT32)symTab;
  i4 = (OOC_INT32)pragmaHistory;
  i5 = (OOC_INT32)errList;
  i0 = (OOC_INT32)OOC_IR__NewBuilder((OOC_SymbolTable__Module)i3, (OOC_SymbolTable_Uses__Uses)i0, (OOC_Config_Pragmas__History)i4, (OOC_Error__List)i5, (OOC_IR__ConstFold)i1);
  i1 = (OOC_INT32)ast;
  i3 = (OOC_INT32)symTab;
  i0 = (OOC_INT32)OOC_AST_CreateIR__CreateIR((OOC_AST__Module)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9549)))), &_td_OOC_AST__ModuleDesc, 9549)), (OOC_SymbolTable__Module)i3, (OOC_IR__Builder)i0);
  module = (OOC_IR__Module)i0;
  i1 = (OOC_INT32)errList;
  i3 = OOC_Error__ListDesc_NoErrors((OOC_Error__List)i1);
  if (!i3) goto l8;
  i3 = (OOC_INT32)pragmaHistory;
  i4 = (OOC_INT32)symTab;
  OOC_IR_CheckUses__CheckUses((OOC_IR__Module)i0, (OOC_SymbolTable__Module)i4, (OOC_Config_Pragmas__History)i3, (OOC_Error__List)i1);
l8:
  i1 = writeIR;
  if (!i1) goto l11;
  i1 = (OOC_INT32)IO_StdChannels__stdout;
  OOC_IR_XML__Write((IO__ByteChannel)i1, (OOC_IR__Module)i0);
l11:
  i0 = (OOC_INT32)symTab;
  i0 = (OOC_INT32)OOC_SymbolTable_Exports__GetExports((OOC_SymbolTable__Module)i0, 1u);
  exports = (ADT_Dictionary_AddressKey__Dictionary)i0;
  i0 = (OOC_INT32)errList;
  i0 = OOC_Error__ListDesc_NoErrors((OOC_Error__List)i0);
  if (i0) goto l14;
  i0=0u;
  goto l16;
l14:
  i0 = analysisOnly;
  i0 = !i0;
  
l16:
  if (!i0) goto l32;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 10307)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i2, 12, 0u);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 10221)))), OOC_Repository__ModuleDesc_GetOutputChannel)),OOC_Repository__ModuleDesc_GetOutputChannel)((OOC_Repository__Module)i2, 12, 1u);
  i0 = (OOC_INT32)OOC_C_DeclWriter__NewWriter((IO__ByteChannel)i1, (URI__HierarchicalURI)i0);
  wd = (OOC_C_DeclWriter__Writer)i0;
  i0 = (OOC_INT32)OOC_Make_TranslateToC__Run_WriteFile(13);
  wh = (OOC_C_DeclWriter__Writer)i0;
  i0 = (OOC_INT32)symTab;
  i0 = *(OOC_INT8*)((_check_pointer(i0, 10420))+52);
  i0 = i0==0;
  if (i0) goto l20;
  i0=0u;
  goto l22;
l20:
  i0 = (OOC_INT32)errList;
  i0 = OOC_Error__ListDesc_NoErrors((OOC_Error__List)i0);
  
l22:
  if (i0) goto l24;
  wc = (OOC_C_DeclWriter__Writer)(OOC_INT32)0;
  goto l25;
l24:
  i0 = (OOC_INT32)OOC_Make_TranslateToC__Run_WriteFile(11);
  wc = (OOC_C_DeclWriter__Writer)i0;
l25:
  i0 = (OOC_INT32)errList;
  i0 = OOC_Error__ListDesc_NoErrors((OOC_Error__List)i0);
  if (!i0) goto l28;
  i0 = (OOC_INT32)translator;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10666))+16);
  i1 = (OOC_INT32)exports;
  i2 = (OOC_INT32)symTab;
  i3 = (OOC_INT32)m;
  i4 = (OOC_INT32)wd;
  OOC_Make_TranslateToC__WriteDeclFile((OOC_C_DeclWriter__Writer)i4, (OOC_Repository__Module)i3, (OOC_SymbolTable__Module)i2, (ADT_Dictionary_AddressKey__Dictionary)i1, (OOC_C_Naming__QualTypeData)i0);
l28:
  i0 = (OOC_INT32)errList;
  i1 = OOC_Error__ListDesc_NoErrors((OOC_Error__List)i0);
  if (!i1) goto l31;
  i1 = (OOC_INT32)symTab;
  i2 = (OOC_INT32)m;
  OOC_Auxiliary_WriteSymbolFile__WriteSymbolFile((OOC_Repository__Module)i2, (OOC_SymbolTable__Module)i1, (OOC_Error__List)i0);
l31:
  i0 = (OOC_INT32)wh;
  OOC_Make_TranslateToC__Run_CloseFile((OOC_C_DeclWriter__Writer)i0);
  i0 = (OOC_INT32)wd;
  OOC_Make_TranslateToC__Run_CloseFile((OOC_C_DeclWriter__Writer)i0);
  i0 = (OOC_INT32)wc;
  OOC_Make_TranslateToC__Run_CloseFile((OOC_C_DeclWriter__Writer)i0);
l32:
  i0 = (OOC_INT32)module;
  OOC_IR__ModuleDesc_Destroy((OOC_IR__Module)i0);
l33:
  i0 = (OOC_INT32)errList;
  return (OOC_Error__List)i0;
  ;
}

void OOC_OOC_Make_TranslateToC_init(void) {

  return;
  ;
}

void OOC_OOC_Make_TranslateToC_destroy(void) {
}

/* --- */
