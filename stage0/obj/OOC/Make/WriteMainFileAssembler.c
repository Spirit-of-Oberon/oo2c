#include <OOC/Make/WriteMainFileAssembler.d>
#include <__oo2c.h>
#include <setjmp.h>

void OOC_Make_WriteMainFileAssembler__WriteFile(OOC_Repository__Module module, const OOC_Repository__Module imports__ref[], OOC_LEN imports_0d) {
  register OOC_INT32 i0;
  OOC_ALLOCATE_VPAR(imports,OOC_Repository__Module ,imports_0d)
  IO__ByteChannel ch;
  IO_TextRider__Writer w;
  auto void OOC_Make_WriteMainFileAssembler__WriteFile_WriteModuleName(IO_TextRider__Writer w, const OOC_CHAR8 prefix__ref[], OOC_LEN prefix_0d, OOC_Repository__Module module, const OOC_CHAR8 suffix__ref[], OOC_LEN suffix_0d);
  auto void OOC_Make_WriteMainFileAssembler__WriteFile_WriteModules(IO_TextRider__Writer w, const OOC_CHAR8 prefix__ref[], OOC_LEN prefix_0d, const OOC_CHAR8 suffix__ref[], OOC_LEN suffix_0d);
  auto void OOC_Make_WriteMainFileAssembler__WriteFile_Directive(const OOC_CHAR8 cmd__ref[], OOC_LEN cmd_0d);
  auto void OOC_Make_WriteMainFileAssembler__WriteFile_Instr(const OOC_CHAR8 instr__ref[], OOC_LEN instr_0d);
    
    void OOC_Make_WriteMainFileAssembler__WriteFile_WriteModuleName(IO_TextRider__Writer w, const OOC_CHAR8 prefix__ref[], OOC_LEN prefix_0d, OOC_Repository__Module module, const OOC_CHAR8 suffix__ref[], OOC_LEN suffix_0d) {
      register OOC_INT32 i0,i1;
      OOC_ALLOCATE_VPAR(prefix,OOC_CHAR8 ,prefix_0d)
      OOC_ALLOCATE_VPAR(suffix,OOC_CHAR8 ,suffix_0d)
      OOC_CHAR8 str[1024];
      OOC_INT32 i;

      OOC_INITIALIZE_VPAR(prefix__ref,prefix,OOC_CHAR8 ,prefix_0d)
      OOC_INITIALIZE_VPAR(suffix__ref,suffix,OOC_CHAR8 ,suffix_0d)
      i0 = (OOC_INT32)module;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1487))+4);
      _copy_8((const void*)(_check_pointer(i0, 1493)),(void*)(OOC_INT32)str,1024);
      i = 0;
      i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, 1024, OOC_UINT32, 1532)));
      i0 = i0!=0u;
      if (!i0) goto l11;
      i0=0;
l3_loop:
      i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, 1024, OOC_UINT32, 1560)));
      i1 = i1==58u;
      if (!i1) goto l6;
      *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, 1024, OOC_UINT32, 1579))) = 95u;
l6:
      i0 = i0+1;
      i = i0;
      i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, 1024, OOC_UINT32, 1532)));
      i1 = i1!=0u;
      if (i1) goto l3_loop;
l11:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1629)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (void*)(OOC_INT32)prefix, prefix_0d);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1660)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (void*)(OOC_INT32)str, 1024);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1688)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (void*)(OOC_INT32)suffix, suffix_0d);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1719)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
      return;
      ;
    }

    
    void OOC_Make_WriteMainFileAssembler__WriteFile_WriteModules(IO_TextRider__Writer w, const OOC_CHAR8 prefix__ref[], OOC_LEN prefix_0d, const OOC_CHAR8 suffix__ref[], OOC_LEN suffix_0d) {
      register OOC_INT32 i0,i1,i2;
      OOC_ALLOCATE_VPAR(prefix,OOC_CHAR8 ,prefix_0d)
      OOC_ALLOCATE_VPAR(suffix,OOC_CHAR8 ,suffix_0d)
      OOC_INT32 i;

      OOC_INITIALIZE_VPAR(prefix__ref,prefix,OOC_CHAR8 ,prefix_0d)
      OOC_INITIALIZE_VPAR(suffix__ref,suffix,OOC_CHAR8 ,suffix_0d)
      i = 0;
      i0 = 0<imports_0d;
      if (!i0) goto l11;
      i0 = (OOC_INT32)w;
      i1=0;
l3_loop:
      i2 = (OOC_INT32)*(OOC_INT32*)((OOC_INT32)imports+(_check_index(i1, imports_0d, OOC_UINT32, 1930))*4);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 1933))+12);
      i2 = OOC_SymbolTable__ModuleDesc_NoObjectFile((OOC_SymbolTable__Module)i2);
      i2 = !i2;
      if (!i2) goto l6;
      i2 = (OOC_INT32)*(OOC_INT32*)((OOC_INT32)imports+(_check_index(i1, imports_0d, OOC_UINT32, 2006))*4);
      OOC_Make_WriteMainFileAssembler__WriteFile_WriteModuleName((IO_TextRider__Writer)i0, (void*)(OOC_INT32)prefix, prefix_0d, (OOC_Repository__Module)i2, (void*)(OOC_INT32)suffix, suffix_0d);
l6:
      i1 = i1+1;
      i = i1;
      i2 = i1<imports_0d;
      if (i2) goto l3_loop;
l11:
      return;
      ;
    }

    
    void OOC_Make_WriteMainFileAssembler__WriteFile_Directive(const OOC_CHAR8 cmd__ref[], OOC_LEN cmd_0d) {
      register OOC_INT32 i0;
      OOC_ALLOCATE_VPAR(cmd,OOC_CHAR8 ,cmd_0d)

      OOC_INITIALIZE_VPAR(cmd__ref,cmd,OOC_CHAR8 ,cmd_0d)
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2128)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (void*)(OOC_INT32)cmd, cmd_0d);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2156)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
      return;
      ;
    }

    
    void OOC_Make_WriteMainFileAssembler__WriteFile_Instr(const OOC_CHAR8 instr__ref[], OOC_LEN instr_0d) {
      register OOC_INT32 i0;
      OOC_ALLOCATE_VPAR(instr,OOC_CHAR8 ,instr_0d)

      OOC_INITIALIZE_VPAR(instr__ref,instr,OOC_CHAR8 ,instr_0d)
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2246)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i0, 9u);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2277)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (void*)(OOC_INT32)instr, instr_0d);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2307)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
      return;
      ;
    }


  OOC_INITIALIZE_VPAR(imports__ref,imports,OOC_Repository__Module ,(imports_0d*4))
  i0 = (OOC_INT32)module;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2360)))), OOC_Repository__ModuleDesc_GetOutputChannel)),OOC_Repository__ModuleDesc_GetOutputChannel)((OOC_Repository__Module)i0, 16, 1u);
  ch = (IO__ByteChannel)i0;
  i0 = (OOC_INT32)IO_TextRider__ConnectWriter((IO__ByteChannel)i0);
  w = (IO_TextRider__Writer)i0;
  OOC_Make_WriteMainFileAssembler__WriteFile_Directive(".text", 6);
  OOC_Make_WriteMainFileAssembler__WriteFile_Directive(".Ltext0:", 9);
  OOC_Make_WriteMainFileAssembler__WriteFile_Instr(".align 4", 9);
  OOC_Make_WriteMainFileAssembler__WriteFile_Directive(".globl main", 12);
  OOC_Make_WriteMainFileAssembler__WriteFile_Instr(".type \011 main,@function", 23);
  OOC_Make_WriteMainFileAssembler__WriteFile_Directive("main:", 6);
  OOC_Make_WriteMainFileAssembler__WriteFile_Instr("pushl %ebp", 11);
  OOC_Make_WriteMainFileAssembler__WriteFile_Instr("movl %esp,%ebp", 15);
  OOC_Make_WriteMainFileAssembler__WriteFile_Instr("subl $8,%esp", 13);
  OOC_Make_WriteMainFileAssembler__WriteFile_Instr("movl 8(%ebp),%eax", 18);
  OOC_Make_WriteMainFileAssembler__WriteFile_Instr("movl %eax,RT0__argc", 20);
  OOC_Make_WriteMainFileAssembler__WriteFile_Instr("movl 12(%ebp),%eax", 19);
  OOC_Make_WriteMainFileAssembler__WriteFile_Instr("movl %eax,RT0__argv", 20);
  i0 = (OOC_INT32)w;
  OOC_Make_WriteMainFileAssembler__WriteFile_WriteModules((IO_TextRider__Writer)i0, "\011call OOC_", 11, "_open", 6);
  OOC_Make_WriteMainFileAssembler__WriteFile_Instr("xorl %eax,%eax", 15);
  OOC_Make_WriteMainFileAssembler__WriteFile_Instr("leave", 6);
  OOC_Make_WriteMainFileAssembler__WriteFile_Instr("ret", 4);
  OOC_Make_WriteMainFileAssembler__WriteFile_Directive(".Lfe1:", 7);
  OOC_Make_WriteMainFileAssembler__WriteFile_Instr(".size\011 main,.Lfe1-main", 23);
  OOC_Make_WriteMainFileAssembler__WriteFile_Directive(".Lscope0:", 10);
  OOC_Make_WriteMainFileAssembler__WriteFile_Instr(".text", 6);
  OOC_Make_WriteMainFileAssembler__WriteFile_Directive("Letext:", 8);
  OOC_Make_WriteMainFileAssembler__WriteFile_Instr(".ident\011\"OOC: 0.1\"", 18);
  i0 = (OOC_INT32)ch;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3344)))), IO__ChannelDesc_CloseAndRegister)),IO__ChannelDesc_CloseAndRegister)((IO__Channel)i0);
  return;
  ;
}

void OOC_OOC_Make_WriteMainFileAssembler_init(void) {

  return;
  ;
}

void OOC_OOC_Make_WriteMainFileAssembler_destroy(void) {
}

/* --- */
