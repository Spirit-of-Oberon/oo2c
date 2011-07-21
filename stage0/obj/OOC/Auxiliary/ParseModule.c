#include <OOC/Auxiliary/ParseModule.d>
#include <__oo2c.h>
#include <setjmp.h>

void OOC_Auxiliary_ParseModule__ParseModule(OOC_Repository__Module m, OOC_CHAR8 checkModuleName, OOC_CHAR8 createNamespace, OOC_CHAR8 writeSymbolFile, OOC_CHAR8 abortAfterImport, Object__String libraryName, OOC_SymbolTable_Uses__Uses uses, OOC_AST__Node *ast, OOC_SymbolTable__Module *symTab, OOC_Config_Pragmas__History *pragmaHistory, OOC_Error__List *errList) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  OOC_Scanner_InputBuffer__Buffer inputBuffer;
  URI__URI uri;
  OOC_Scanner_SymList__Builder scannerBuilder;
  OOC_UINT32 scannerFlags;
  OOC_AST__Builder astBuilder;
  OOC_UINT32 parserFlags;
  OOC_SymbolTable_Builder__Builder stb;

  i0 = (OOC_INT32)m;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1808)))), OOC_Repository__ModuleDesc_GetInputBuffer)),OOC_Repository__ModuleDesc_GetInputBuffer)((OOC_Repository__Module)i0);
  inputBuffer = (OOC_Scanner_InputBuffer__Buffer)i1;
  i2 = i1==(OOC_INT32)0;
  if (i2) goto l34;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2071))+20);
  *errList = (OOC_Error__List)i2;
  i3 = (OOC_INT32)OOC_Scanner_SymList__New((OOC_Scanner_InputBuffer__Buffer)i1, 1u);
  scannerBuilder = (OOC_Scanner_SymList__Builder)i3;
  scannerFlags = 31u;
  i4 = abortAfterImport;
  if (i4) goto l5;
  i5=31u;
  goto l6;
l5:
  i5 = _set_bit(31u,5);
  scannerFlags = i5;
  
l6:
  i6 = (OOC_INT32)OOC_Config__pragmas;
  OOC_Scanner__ScanInput((OOC_Scanner_SymList__Builder)i3, (OOC_Config_Pragmas__Section)i6, i5);
  OOC_Scanner_InputBuffer__BufferDesc_Close((OOC_Scanner_InputBuffer__Buffer)i1);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 2414))+4);
  *pragmaHistory = (OOC_Config_Pragmas__History)i1;
  *ast = (OOC_AST__Node)(OOC_INT32)0;
  i1 = OOC_Error__ListDesc_NoErrors((OOC_Error__List)i2);
  if (i1) goto l9;
  i1=(OOC_INT32)0;
  goto l17;
l9:
  i1 = (OOC_INT32)OOC_AST__New();
  astBuilder = (OOC_AST__Builder)i1;
  i5 = checkModuleName;
  if (!i5) goto l12;
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2592))+4);
  i6 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2592))+4);
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 2598)), 0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2574)))), OOC_AST__BuilderDesc_SetModuleName)),OOC_AST__BuilderDesc_SetModuleName)((OOC_AST__Builder)i1, (void*)(_check_pointer(i6, 2598)), i5);
l12:
  parserFlags = (-33u);
  if (i4) goto l15;
  i4=(-33u);
  goto l16;
l15:
  i4 = _clear_bit((_set_bit((-33u),5)),3);
  parserFlags = i4;
  
l16:
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 2852))+8);
  i1 = (OOC_INT32)OOC_Parser__Module((OOC_Scanner_SymList__Symbol)i3, (OOC_AST__Builder)i1, (OOC_Error__List)i2, i4);
  *ast = (OOC_AST__Node)i1;
  
l17:
  *symTab = (OOC_SymbolTable__Module)(OOC_INT32)0;
  i3 = OOC_Error__ListDesc_NoErrors((OOC_Error__List)i2);
  if (!i3) goto l35;
  i3 = (OOC_INT32)OOC_SymbolTable_Builder__New();
  stb = (OOC_SymbolTable_Builder__Builder)i3;
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3159));
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 3167))+4);
  i5 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3101)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i0, 0, 0u);
  i6 = (OOC_INT32)libraryName;
  i1 = (OOC_INT32)OOC_AST_CreateSymTab__CreateSymTab((OOC_AST__Node)i1, (OOC_SymbolTable_Builder__Builder)i3, (Object__String)i6, (URI__HierarchicalURI)i5, (URI__HierarchicalURI)i4);
  *symTab = (OOC_SymbolTable__Module)i1;
  i3 = createNamespace;
  if (!i3) goto l35;
  i3 = OOC_Error__ListDesc_NoErrors((OOC_Error__List)i2);
  if (!i3) goto l24;
  i3 = (OOC_INT32)uses;
  OOC_SymbolTable_CreateNamespace__CreateNamespace((OOC_SymbolTable__Module)i1, (OOC_SymbolTable_Uses__Uses)i3, (OOC_Error__List)i2);
l24:
  i3 = OOC_Error__ListDesc_NoErrors((OOC_Error__List)i2);
  if (i3) goto l27;
  i3=0u;
  goto l29;
l27:
  i3 = writeSymbolFile;
  
l29:
  if (!i3) goto l35;
  OOC_Auxiliary_WriteSymbolFile__WriteSymbolFile((OOC_Repository__Module)i0, (OOC_SymbolTable__Module)i1, (OOC_Error__List)i2);
  goto l35;
l34:
  *ast = (OOC_AST__Node)(OOC_INT32)0;
  *symTab = (OOC_SymbolTable__Module)(OOC_INT32)0;
  *pragmaHistory = (OOC_Config_Pragmas__History)(OOC_INT32)0;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1941)))), OOC_Repository__ModuleDesc_GetURI)),OOC_Repository__ModuleDesc_GetURI)((OOC_Repository__Module)i0, 0, 1u);
  uri = (URI__URI)i0;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2020)))), URI__URIDesc_ToString)),URI__URIDesc_ToString)((URI__URI)i0);
  i0 = (OOC_INT32)OOC_Error__NewList((Object__String)i0);
  *errList = (OOC_Error__List)i0;
l35:
  return;
  ;
}

void OOC_OOC_Auxiliary_ParseModule_init(void) {

  return;
  ;
}

void OOC_OOC_Auxiliary_ParseModule_destroy(void) {
}

/* --- */
