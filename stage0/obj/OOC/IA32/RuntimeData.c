#include <OOC/IA32/RuntimeData.d>
#include <__oo2c.h>
#include <setjmp.h>

void OOC_IA32_RuntimeData__Write(OOC_IA32_Writer__Writer w, OOC_SymbolTable__Module symTab) {
  register OOC_INT32 i0;
  auto void OOC_IA32_RuntimeData__Write_ModuleDescr(OOC_SymbolTable__Module module);
    
    void OOC_IA32_RuntimeData__Write_ModuleDescr(OOC_SymbolTable__Module module) {
      register OOC_INT32 i0,i1,i2;

      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1102)))), OOC_IA32_Writer__WriterDesc_Section)),OOC_IA32_Writer__WriterDesc_Section)((OOC_IA32_Writer__Writer)i0, ".data", 6);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1130)))), OOC_IA32_Writer__WriterDesc_Instr)),OOC_IA32_Writer__WriterDesc_Instr)((OOC_IA32_Writer__Writer)i0, ".align 4", 9);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1159)))), OOC_IA32_Writer__WriterDesc_Instr)),OOC_IA32_Writer__WriterDesc_Instr)((OOC_IA32_Writer__Writer)i0, ".type _mid,@object", 19);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1198)))), OOC_IA32_Writer__WriterDesc_Instr)),OOC_IA32_Writer__WriterDesc_Instr)((OOC_IA32_Writer__Writer)i0, ".size _mid,4", 13);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1231)))), OOC_IA32_Writer__WriterDesc_Label)),OOC_IA32_Writer__WriterDesc_Label)((OOC_IA32_Writer__Writer)i0, (Object__String)((OOC_INT32)_c0));
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1256)))), OOC_IA32_Writer__WriterDesc_Instr)),OOC_IA32_Writer__WriterDesc_Instr)((OOC_IA32_Writer__Writer)i0, ".long .LC0", 11);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1287)))), OOC_IA32_Writer__WriterDesc_Section)),OOC_IA32_Writer__WriterDesc_Section)((OOC_IA32_Writer__Writer)i0, ".section .rodata", 17);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1326)))), OOC_IA32_Writer__WriterDesc_Label)),OOC_IA32_Writer__WriterDesc_Label)((OOC_IA32_Writer__Writer)i0, (Object__String)((OOC_INT32)_c1));
      i0 = (OOC_INT32)w;
      i1 = (OOC_INT32)symTab;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 1374))+20);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 1380))+12);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 1374))+20);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 1380))+12);
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 1385)), 0);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1351)))), OOC_IA32_Writer__WriterDesc_StringLiteral)),OOC_IA32_Writer__WriterDesc_StringLiteral)((OOC_IA32_Writer__Writer)i0, (void*)(_check_pointer(i2, 1385)), i1);
      return;
      ;
    }


  i0 = (OOC_INT32)symTab;
  OOC_IA32_RuntimeData__Write_ModuleDescr((OOC_SymbolTable__Module)i0);
  return;
  ;
}

void OOC_OOC_IA32_RuntimeData_init(void) {
  _c0 = Object__NewLatin1Region("_mid", 5, 0, 4);
  _c1 = Object__NewLatin1Region(".LC0", 5, 0, 4);

  return;
  ;
}

/* --- */
