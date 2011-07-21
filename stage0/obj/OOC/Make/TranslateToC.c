#include <OOC/Make/TranslateToC.d>
#include <__oo2c.h>
#include <setjmp.h>

void OOC_Make_TranslateToC__InitTranslator(OOC_Make_TranslateToC__Translator t) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)t;
  *(OOC_INT32*)(_check_pointer(i0, 2193)) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 2210))+4) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 2228))+8) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 2252))+12) = (-1);
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_C_Naming__QualTypeData.baseTypes[0]);
  OOC_C_Naming__QualTypeDataDesc_INIT((OOC_C_Naming__QualTypeData)i1);
  *(OOC_INT32*)((_check_pointer(i0, 2278))+16) = i1;
  return;
  ;
}

void OOC_Make_TranslateToC__TranslatorDesc_SetWriter(OOC_Make_TranslateToC__Translator t, OOC_C_DeclWriter__Writer w) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)t;
  i1 = (OOC_INT32)w;
  *(OOC_INT32*)(_check_pointer(i0, 2414)) = i1;
  return;
  ;
}

void OOC_Make_TranslateToC__TranslatorDesc_SetProcedureList(OOC_Make_TranslateToC__Translator t, OOC_IR__ProcedureList procList) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)t;
  i1 = (OOC_INT32)procList;
  *(OOC_INT32*)((_check_pointer(i0, 2529))+8) = i1;
  return;
  ;
}

void OOC_Make_TranslateToC__TranslatorDesc_SetDataWriter(OOC_Make_TranslateToC__Translator t, OOC_C_DeclWriter__Writer wd) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)t;
  i1 = (OOC_INT32)wd;
  *(OOC_INT32*)((_check_pointer(i0, 2657))+4) = i1;
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
  i1 = *(OOC_INT32*)((_check_pointer(i0, 2969))+12);
  oldProcIndex = i1;
  i2 = procIndex;
  *(OOC_INT32*)((_check_pointer(i0, 2989))+12) = i2;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3103));
  w = (OOC_C_DeclWriter__Writer)i3;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3142))+8);
  i4 = _check_pointer(i4, 3152);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i2, i5, OOC_UINT32, 3152))*4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 3163))+4);
  i4 = (OOC_INT32)OOC_C_ConvertDecl__GetProc((OOC_C_DeclWriter__Writer)i3, (OOC_SymbolTable__ProcDecl)i4, 0u);
  d = (OOC_C_DeclWriter__Declaration)i4;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 3184)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i3);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 3200)))), OOC_C_DeclWriter__WriterDesc_WriteDeclaration)),OOC_C_DeclWriter__WriterDesc_WriteDeclaration)((OOC_C_DeclWriter__Writer)i3, (OOC_C_DeclWriter__Declaration)i4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 3229)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i3, " {", 3);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3274))+8);
  i4 = _check_pointer(i4, 3284);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i2 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i2, i5, OOC_UINT32, 3284))*4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3256)))), OOC_Make_TranslateToC__TranslatorDesc_WriteProcBody)),OOC_Make_TranslateToC__TranslatorDesc_WriteProcBody)((OOC_Make_TranslateToC__Translator)i0, (OOC_IR__Procedure)i2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 3303)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i3);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 3319)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i3, "}", 2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 3345)))), OOC_C_DeclWriter__WriterDesc_WriteLn)),OOC_C_DeclWriter__WriterDesc_WriteLn)((OOC_C_DeclWriter__Writer)i3);
  *(OOC_INT32*)((_check_pointer(i0, 3362))+12) = i1;
  return;
  ;
}

void OOC_Make_TranslateToC__TranslatorDesc_WriteNestedProcedures(OOC_Make_TranslateToC__Translator t) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_SymbolTable__ProcDecl currentDecl;
  OOC_INT32 i;

  i0 = (OOC_INT32)t;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 3914))+12);
  i1 = i1>=0;
  if (!i1) goto l14;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4007))+8);
  i1 = _check_pointer(i1, 4017);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i3 = *(OOC_INT32*)((_check_pointer(i0, 4019))+12);
  i1 = (OOC_INT32)*(OOC_INT32*)(i1+(_check_index(i3, i2, OOC_UINT32, 4017))*4);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4033))+4);
  currentDecl = (OOC_SymbolTable__ProcDecl)i1;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 4053))+12);
  i2 = i2+1;
  i = i2;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4093))+8);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 4103)), 0);
  i3 = i2!=i3;
  if (!i3) goto l14;
l5_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4123))+8);
  i3 = _check_pointer(i3, 4133);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 4133))*4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 4136))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 4142))+4);
  i3 = i3==i1;
  if (!i3) goto l8;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4182));
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4182));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 4185)))), OOC_C_DeclWriter__WriterDesc_Indent)),OOC_C_DeclWriter__WriterDesc_Indent)((OOC_C_DeclWriter__Writer)i4, 1);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4210));
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4210));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 4213)))), OOC_C_DeclWriter__WriterDesc_Newline)),OOC_C_DeclWriter__WriterDesc_Newline)((OOC_C_DeclWriter__Writer)i4);
  OOC_Make_TranslateToC__TranslatorDesc_WriteProcedure((OOC_Make_TranslateToC__Translator)i0, i2);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4268));
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4268));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 4271)))), OOC_C_DeclWriter__WriterDesc_Indent)),OOC_C_DeclWriter__WriterDesc_Indent)((OOC_C_DeclWriter__Writer)i4, (-1));
l8:
  i2 = i2+1;
  i = i2;
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4093))+8);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 4103)), 0);
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
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4637))+4);
  _copy_8((const void*)(_check_pointer(i0, 4643)),(void*)(OOC_INT32)str,1024);
  i = 0;
  i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, 1024, OOC_UINT32, 4678)));
  i0 = i0!=0u;
  if (!i0) goto l11;
  i0=0;
l3_loop:
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, 1024, OOC_UINT32, 4704)));
  i1 = i1==58u;
  if (!i1) goto l6;
  *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, 1024, OOC_UINT32, 4723))) = 95u;
l6:
  i0 = i0+1;
  i = i0;
  i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, 1024, OOC_UINT32, 4678)));
  i1 = i1!=0u;
  if (i1) goto l3_loop;
l11:
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4767)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, (void*)(OOC_INT32)prefix, prefix_0d);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4796)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, (void*)(OOC_INT32)str, 1024);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4822)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, (void*)(OOC_INT32)suffix, suffix_0d);
  i1 = newline;
  if (!i1) goto l14;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4873)))), OOC_C_DeclWriter__WriterDesc_WriteLn)),OOC_C_DeclWriter__WriterDesc_WriteLn)((OOC_C_DeclWriter__Writer)i0);
l14:
  return;
  ;
}

static void OOC_Make_TranslateToC__WriteHeaderFile(OOC_C_DeclWriter__Writer w, OOC_Repository__Module m, OOC_SymbolTable__Module symTab, ADT_Dictionary_AddressKey__Dictionary exports, OOC_C_Naming__QualTypeData qtdData) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)m;
  OOC_Make_TranslateToC__WriteModuleName((OOC_C_DeclWriter__Writer)i0, "#ifndef _MODULE_", 17, (OOC_Repository__Module)i1, "_", 2, 1u);
  OOC_Make_TranslateToC__WriteModuleName((OOC_C_DeclWriter__Writer)i0, "#define _MODULE_", 17, (OOC_Repository__Module)i1, "_", 2, 1u);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5244)))), OOC_C_DeclWriter__WriterDesc_WriteLn)),OOC_C_DeclWriter__WriterDesc_WriteLn)((OOC_C_DeclWriter__Writer)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5364)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "#include <__typemap.h>", 23);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5411)))), OOC_C_DeclWriter__WriterDesc_WriteLn)),OOC_C_DeclWriter__WriterDesc_WriteLn)((OOC_C_DeclWriter__Writer)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5546)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "#include <RT0.oh>", 18);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5630)))), OOC_C_DeclWriter__WriterDesc_WriteLn)),OOC_C_DeclWriter__WriterDesc_WriteLn)((OOC_C_DeclWriter__Writer)i0);
  i2 = (OOC_INT32)symTab;
  i3 = (OOC_INT32)exports;
  OOC_C_ConvertDecl__ConvertSymTab((OOC_C_DeclWriter__Writer)i0, (OOC_Repository__Module)i1, (OOC_SymbolTable__Module)i2, (ADT_Dictionary_AddressKey__Dictionary)i3, 1u);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5712)))), OOC_C_DeclWriter__WriterDesc_WriteDeclarationList)),OOC_C_DeclWriter__WriterDesc_WriteDeclarationList)((OOC_C_DeclWriter__Writer)i0);
  i3 = (OOC_INT32)qtdData;
  OOC_C_RuntimeData__Write((OOC_C_DeclWriter__Writer)i0, (OOC_SymbolTable__Module)i2, (OOC_C_Naming__QualTypeData)i3, 1u);
  OOC_Make_TranslateToC__WriteModuleName((OOC_C_DeclWriter__Writer)i0, "#endif /* _MODULE_", 19, (OOC_Repository__Module)i1, "_ */", 5, 1u);
  return;
  ;
}

static void OOC_Make_TranslateToC__WriteDeclFile(OOC_C_DeclWriter__Writer w, OOC_Repository__Module m, OOC_SymbolTable__Module symTab, ADT_Dictionary_AddressKey__Dictionary exports, OOC_C_Naming__QualTypeData qtdData) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = (OOC_INT32)w;
  i1 = (OOC_INT32)m;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6084)))), OOC_C_DeclWriter__WriterDesc_WriteModuleInclude)),OOC_C_DeclWriter__WriterDesc_WriteModuleInclude)((OOC_C_DeclWriter__Writer)i0, (OOC_Repository__Module)i1, 13);
  i2 = (OOC_INT32)symTab;
  i3 = (OOC_INT32)exports;
  OOC_C_ConvertDecl__ConvertSymTab((OOC_C_DeclWriter__Writer)i0, (OOC_Repository__Module)i1, (OOC_SymbolTable__Module)i2, (ADT_Dictionary_AddressKey__Dictionary)i3, 0u);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6207)))), OOC_C_DeclWriter__WriterDesc_WriteDeclarationList)),OOC_C_DeclWriter__WriterDesc_WriteDeclarationList)((OOC_C_DeclWriter__Writer)i0);
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
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6483)))), OOC_C_DeclWriter__WriterDesc_WriteModuleInclude)),OOC_C_DeclWriter__WriterDesc_WriteModuleInclude)((OOC_C_DeclWriter__Writer)i0, (OOC_Repository__Module)i1, 12);
  i2 = (OOC_INT32)translator;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 6546)))), OOC_Make_TranslateToC__TranslatorDesc_SetWriter)),OOC_Make_TranslateToC__TranslatorDesc_SetWriter)((OOC_Make_TranslateToC__Translator)i2, (OOC_C_DeclWriter__Writer)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6762)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "#include <__oo2c.h>", 20);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6806)))), OOC_C_DeclWriter__WriterDesc_WriteLn)),OOC_C_DeclWriter__WriterDesc_WriteLn)((OOC_C_DeclWriter__Writer)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6822)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "#include <setjmp.h>", 20);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6866)))), OOC_C_DeclWriter__WriterDesc_WriteLn)),OOC_C_DeclWriter__WriterDesc_WriteLn)((OOC_C_DeclWriter__Writer)i0);
  i3 = (OOC_INT32)wd;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 6891)))), OOC_Make_TranslateToC__TranslatorDesc_SetDataWriter)),OOC_Make_TranslateToC__TranslatorDesc_SetDataWriter)((OOC_Make_TranslateToC__Translator)i2, (OOC_C_DeclWriter__Writer)i3);
  i3 = (OOC_INT32)moduleIR;
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 6955))+8);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 6927)))), OOC_Make_TranslateToC__TranslatorDesc_SetProcedureList)),OOC_Make_TranslateToC__TranslatorDesc_SetProcedureList)((OOC_Make_TranslateToC__Translator)i2, (OOC_IR__ProcedureList)i4);
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 6999))+8);
  i = 0;
  i4 = OOC_ARRAY_LENGTH((_check_pointer(i4, 7009)), 0);
  i5 = 0<i4;
  if (!i5) goto l11;
  i5=0;
l3_loop:
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 7035))+8);
  i6 = _check_pointer(i6, 7045);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = (OOC_INT32)*(OOC_INT32*)(i6+(_check_index(i5, i7, OOC_UINT32, 7045))*4);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 7048))+4);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i6, 7054))+4);
  i6 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i6, 7063)))), &_td_OOC_SymbolTable__ModuleDesc);
  if (!i6) goto l6;
  OOC_Make_TranslateToC__TranslatorDesc_WriteProcedure((OOC_Make_TranslateToC__Translator)i2, i5);
l6:
  i5 = i5+1;
  i = i5;
  i6 = i5<i4;
  if (i6) goto l3_loop;
l11:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7148)))), OOC_C_DeclWriter__WriterDesc_WriteLn)),OOC_C_DeclWriter__WriterDesc_WriteLn)((OOC_C_DeclWriter__Writer)i0);
  OOC_Make_TranslateToC__WriteModuleName((OOC_C_DeclWriter__Writer)i0, "void OOC_", 10, (OOC_Repository__Module)i1, "_init(void) {", 14, 0u);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 7263))+12);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 7238)))), OOC_Make_TranslateToC__TranslatorDesc_WriteProcBody)),OOC_Make_TranslateToC__TranslatorDesc_WriteProcBody)((OOC_Make_TranslateToC__Translator)i2, (OOC_IR__Procedure)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7283)))), OOC_C_DeclWriter__WriterDesc_WriteLn)),OOC_C_DeclWriter__WriterDesc_WriteLn)((OOC_C_DeclWriter__Writer)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7299)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "}", 2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7325)))), OOC_C_DeclWriter__WriterDesc_WriteLn)),OOC_C_DeclWriter__WriterDesc_WriteLn)((OOC_C_DeclWriter__Writer)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 7351)))), OOC_Make_TranslateToC__TranslatorDesc_SetProcedureList)),OOC_Make_TranslateToC__TranslatorDesc_SetProcedureList)((OOC_Make_TranslateToC__Translator)i2, (OOC_IR__ProcedureList)(OOC_INT32)0);
  return;
  ;
}

OOC_Error__List OOC_Make_TranslateToC__Run(OOC_Repository__Module m, Object__String libraryName, OOC_CHAR8 analysisOnly, OOC_SymbolTable_Uses__Uses uses, OOC_CHAR8 writeAST, OOC_CHAR8 writeIR, OOC_Make_TranslateToC__Translator translator) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_AST__Node ast;
  OOC_SymbolTable__Module symTab;
  OOC_Config_Pragmas__History pragmaHistory;
  OOC_Error__List errList;
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
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8078)))), OOC_Repository__ModuleDesc_GetOutputChannel)),OOC_Repository__ModuleDesc_GetOutputChannel)((OOC_Repository__Module)i0, i1, 1u);
      ch = (IO__ByteChannel)i0;
      i2 = (OOC_INT32)m;
      i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 8151)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i2, i1, 0u);
      i0 = (OOC_INT32)OOC_C_DeclWriter__NewWriter((IO__ByteChannel)i0, (URI__HierarchicalURI)i2);
      w = (OOC_C_DeclWriter__Writer)i0;
      switch (i1) {
      case 13:
        i1 = (OOC_INT32)translator;
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8292))+16);
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
        _failed_case(i1, 8184);
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
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8574)))), OOC_C_DeclWriter__WriterDesc_WriteLn)),OOC_C_DeclWriter__WriterDesc_WriteLn)((OOC_C_DeclWriter__Writer)i0);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8594)))), OOC_C_DeclWriter__WriterDesc_WriteString)),OOC_C_DeclWriter__WriterDesc_WriteString)((OOC_C_DeclWriter__Writer)i0, "/* --- */", 10);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8632)))), OOC_C_DeclWriter__WriterDesc_WriteLn)),OOC_C_DeclWriter__WriterDesc_WriteLn)((OOC_C_DeclWriter__Writer)i0);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8656))+8);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8667))+4);
      i1 = i1!=(OOC_INT32)0;
      if (!i1) goto l5;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8703))+8);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8714))+4);
      Exception__Raise((void*)i1);
l5:
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8745)))), OOC_C_DeclWriter__WriterDesc_Close)),OOC_C_DeclWriter__WriterDesc_Close)((OOC_C_DeclWriter__Writer)i0);
l6:
      return;
      ;
    }


  i0 = (OOC_INT32)m;
  i1 = (OOC_INT32)libraryName;
  i2 = (OOC_INT32)uses;
  OOC_Auxiliary_ParseModule__ParseModule((OOC_Repository__Module)i0, 1u, 1u, 0u, 0u, (Object__String)i1, (OOC_SymbolTable_Uses__Uses)i2, (void*)(OOC_INT32)&ast, (void*)(OOC_INT32)&symTab, (void*)(OOC_INT32)&pragmaHistory, (void*)(OOC_INT32)&errList);
  i1 = (OOC_INT32)errList;
  i1 = OOC_Error__ListDesc_NoErrors((OOC_Error__List)i1);
  if (!i1) goto l33;
  i1 = writeAST;
  if (!i1) goto l5;
  i1 = (OOC_INT32)ast;
  i3 = (OOC_INT32)IO_StdChannels__stdout;
  OOC_AST_XML__Write((IO__ByteChannel)i3, (OOC_AST__Module)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9273)))), &_td_OOC_AST__ModuleDesc, 9273)));
l5:
  i1 = (OOC_INT32)ast;
  i3 = (OOC_INT32)symTab;
  i4 = (OOC_INT32)pragmaHistory;
  i5 = (OOC_INT32)errList;
  i6 = (OOC_INT32)OOC_IR_ConstFold__NewConstFold();
  i2 = (OOC_INT32)OOC_IR__NewBuilder((OOC_SymbolTable__Module)i3, (OOC_SymbolTable_Uses__Uses)i2, (OOC_Config_Pragmas__History)i4, (OOC_Error__List)i5, (OOC_IR__ConstFold)i6);
  i1 = (OOC_INT32)OOC_AST_CreateIR__CreateIR((OOC_AST__Module)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9337)))), &_td_OOC_AST__ModuleDesc, 9337)), (OOC_SymbolTable__Module)i3, (OOC_IR__Builder)i2);
  module = (OOC_IR__Module)i1;
  i2 = (OOC_INT32)errList;
  i3 = OOC_Error__ListDesc_NoErrors((OOC_Error__List)i2);
  if (!i3) goto l8;
  i3 = (OOC_INT32)pragmaHistory;
  i4 = (OOC_INT32)symTab;
  OOC_IR_CheckUses__CheckUses((OOC_IR__Module)i1, (OOC_SymbolTable__Module)i4, (OOC_Config_Pragmas__History)i3, (OOC_Error__List)i2);
l8:
  i2 = writeIR;
  if (!i2) goto l11;
  i2 = (OOC_INT32)IO_StdChannels__stdout;
  OOC_IR_XML__Write((IO__ByteChannel)i2, (OOC_IR__Module)i1);
l11:
  i1 = (OOC_INT32)symTab;
  i1 = (OOC_INT32)OOC_SymbolTable_Exports__GetExports((OOC_SymbolTable__Module)i1, 1u);
  exports = (ADT_Dictionary_AddressKey__Dictionary)i1;
  i1 = (OOC_INT32)errList;
  i1 = OOC_Error__ListDesc_NoErrors((OOC_Error__List)i1);
  if (i1) goto l14;
  i1=0u;
  goto l16;
l14:
  i1 = analysisOnly;
  i1 = !i1;
  
l16:
  if (!i1) goto l32;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10009)))), OOC_Repository__ModuleDesc_GetOutputChannel)),OOC_Repository__ModuleDesc_GetOutputChannel)((OOC_Repository__Module)i0, 12, 1u);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10095)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i0, 12, 0u);
  i0 = (OOC_INT32)OOC_C_DeclWriter__NewWriter((IO__ByteChannel)i1, (URI__HierarchicalURI)i0);
  wd = (OOC_C_DeclWriter__Writer)i0;
  i0 = (OOC_INT32)OOC_Make_TranslateToC__Run_WriteFile(13);
  wh = (OOC_C_DeclWriter__Writer)i0;
  i0 = (OOC_INT32)symTab;
  i0 = *(OOC_INT8*)((_check_pointer(i0, 10208))+52);
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
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10454))+16);
  i1 = (OOC_INT32)symTab;
  i2 = (OOC_INT32)exports;
  i3 = (OOC_INT32)m;
  i4 = (OOC_INT32)wd;
  OOC_Make_TranslateToC__WriteDeclFile((OOC_C_DeclWriter__Writer)i4, (OOC_Repository__Module)i3, (OOC_SymbolTable__Module)i1, (ADT_Dictionary_AddressKey__Dictionary)i2, (OOC_C_Naming__QualTypeData)i0);
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

/* --- */
