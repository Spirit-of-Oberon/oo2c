#include <OOC/Make/TranslateToX86.d>
#include <__oo2c.h>
#include <setjmp.h>

OOC_Error__List OOC_Make_TranslateToX86__Run(OOC_Repository__Module m, Object__String libraryName, OOC_CHAR8 analysisOnly, OOC_SymbolTable_Uses__Uses uses, OOC_CHAR8 writeAST, OOC_CHAR8 writeIR) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_Error__List errList;
  OOC_Config_Pragmas__History pragmaHistory;
  OOC_SymbolTable__Module symTab;
  OOC_AST__Node ast;
  OOC_IR__Module module;
  ADT_Dictionary_AddressKey__Dictionary exports;
  IO__ByteChannel ch;

  i0 = (OOC_INT32)uses;
  i1 = (OOC_INT32)libraryName;
  i2 = (OOC_INT32)m;
  OOC_Auxiliary_ParseModule__ParseModule((OOC_Repository__Module)i2, 1u, 1u, 0u, 0u, (Object__String)i1, (OOC_SymbolTable_Uses__Uses)i0, (void*)(OOC_INT32)&ast, (void*)(OOC_INT32)&symTab, (void*)(OOC_INT32)&pragmaHistory, (void*)(OOC_INT32)&errList);
  i1 = (OOC_INT32)errList;
  i1 = OOC_Error__ListDesc_NoErrors((OOC_Error__List)i1);
  if (!i1) goto l22;
  i1 = writeAST;
  if (!i1) goto l5;
  i1 = (OOC_INT32)ast;
  i3 = (OOC_INT32)IO_StdChannels__stdout;
  OOC_AST_XML__Write((IO__ByteChannel)i3, (OOC_AST__Module)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2221)))), &_td_OOC_AST__ModuleDesc, 2221)));
l5:
  i1 = (OOC_INT32)OOC_IR_ConstFold__NewConstFold();
  i3 = (OOC_INT32)symTab;
  i4 = (OOC_INT32)pragmaHistory;
  i5 = (OOC_INT32)errList;
  i0 = (OOC_INT32)OOC_IR__NewBuilder((OOC_SymbolTable__Module)i3, (OOC_SymbolTable_Uses__Uses)i0, (OOC_Config_Pragmas__History)i4, (OOC_Error__List)i5, (OOC_IR__ConstFold)i1);
  i1 = (OOC_INT32)ast;
  i3 = (OOC_INT32)symTab;
  i0 = (OOC_INT32)OOC_AST_CreateIR__CreateIR((OOC_AST__Module)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2285)))), &_td_OOC_AST__ModuleDesc, 2285)), (OOC_SymbolTable__Module)i3, (OOC_IR__Builder)i0);
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
  if (!i1) goto l21;
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 2935)))), OOC_Repository__ModuleDesc_GetOutputChannel)),OOC_Repository__ModuleDesc_GetOutputChannel)((OOC_Repository__Module)i2, 14, 1u);
  ch = (IO__ByteChannel)i1;
  i3 = (OOC_INT32)symTab;
  OOC_X86_Translate__Translate((OOC_Repository__Module)i2, (OOC_SymbolTable__Module)i3, (OOC_IR__Module)i0, (IO__ByteChannel)i1);
  i3 = (OOC_INT32)errList;
  i4 = OOC_Error__ListDesc_NoErrors((OOC_Error__List)i3);
  if (!i4) goto l20;
  i4 = (OOC_INT32)symTab;
  OOC_Auxiliary_WriteSymbolFile__WriteSymbolFile((OOC_Repository__Module)i2, (OOC_SymbolTable__Module)i4, (OOC_Error__List)i3);
l20:
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3166)))), IO__ChannelDesc_CloseAndRegister)),IO__ChannelDesc_CloseAndRegister)((IO__Channel)i1);
l21:
  OOC_IR__ModuleDesc_Destroy((OOC_IR__Module)i0);
l22:
  i0 = (OOC_INT32)errList;
  return (OOC_Error__List)i0;
  ;
}

void OOC_OOC_Make_TranslateToX86_init(void) {

  return;
  ;
}

/* --- */
