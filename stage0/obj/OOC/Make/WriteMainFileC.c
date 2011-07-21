#include <OOC/Make/WriteMainFileC.d>
#include <__oo2c.h>
#include <setjmp.h>

void OOC_Make_WriteMainFileC__WriteFile(OOC_Repository__Module module, const OOC_Repository__Module imports__ref[], OOC_LEN imports_0d) {
  register OOC_INT32 i0,i1;
  OOC_ALLOCATE_VPAR(imports,OOC_Repository__Module ,imports_0d)
  IO__ByteChannel ch;
  IO_TextRider__Writer w;
  auto void OOC_Make_WriteMainFileC__WriteFile_WriteModuleName(IO_TextRider__Writer w, const OOC_CHAR8 prefix__ref[], OOC_LEN prefix_0d, OOC_Repository__Module module, const OOC_CHAR8 suffix__ref[], OOC_LEN suffix_0d);
  auto void OOC_Make_WriteMainFileC__WriteFile_WriteModules(IO_TextRider__Writer w, const OOC_CHAR8 prefix__ref[], OOC_LEN prefix_0d, const OOC_CHAR8 suffix__ref[], OOC_LEN suffix_0d);
    
    void OOC_Make_WriteMainFileC__WriteFile_WriteModuleName(IO_TextRider__Writer w, const OOC_CHAR8 prefix__ref[], OOC_LEN prefix_0d, OOC_Repository__Module module, const OOC_CHAR8 suffix__ref[], OOC_LEN suffix_0d) {
      register OOC_INT32 i0,i1;
      OOC_ALLOCATE_VPAR(prefix,OOC_CHAR8 ,prefix_0d)
      OOC_ALLOCATE_VPAR(suffix,OOC_CHAR8 ,suffix_0d)
      OOC_CHAR8 str[1024];
      OOC_INT32 i;

      OOC_INITIALIZE_VPAR(prefix__ref,prefix,OOC_CHAR8 ,prefix_0d)
      OOC_INITIALIZE_VPAR(suffix__ref,suffix,OOC_CHAR8 ,suffix_0d)
      i0 = (OOC_INT32)module;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1461))+4);
      _copy_8((const void*)(_check_pointer(i0, 1467)),(void*)(OOC_INT32)str,1024);
      i = 0;
      i0 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, 1024, OOC_UINT32, 1506)));
      i0 = i0!=0u;
      if (!i0) goto l11;
      i0=0;
l3_loop:
      i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, 1024, OOC_UINT32, 1534)));
      i1 = i1==58u;
      if (!i1) goto l6;
      *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, 1024, OOC_UINT32, 1553))) = 95u;
l6:
      i0 = i0+1;
      i = i0;
      i1 = *(OOC_UINT8*)((OOC_INT32)str+(_check_index(i0, 1024, OOC_UINT32, 1506)));
      i1 = i1!=0u;
      if (i1) goto l3_loop;
l11:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1603)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (void*)(OOC_INT32)prefix, prefix_0d);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1634)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (void*)(OOC_INT32)str, 1024);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1662)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (void*)(OOC_INT32)suffix, suffix_0d);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1693)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
      return;
      ;
    }

    
    void OOC_Make_WriteMainFileC__WriteFile_WriteModules(IO_TextRider__Writer w, const OOC_CHAR8 prefix__ref[], OOC_LEN prefix_0d, const OOC_CHAR8 suffix__ref[], OOC_LEN suffix_0d) {
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
      i2 = (OOC_INT32)*(OOC_INT32*)((OOC_INT32)imports+(_check_index(i1, imports_0d, OOC_UINT32, 1904))*4);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 1907))+12);
      i2 = OOC_SymbolTable__ModuleDesc_NoObjectFile((OOC_SymbolTable__Module)i2);
      i2 = !i2;
      if (!i2) goto l6;
      i2 = (OOC_INT32)*(OOC_INT32*)((OOC_INT32)imports+(_check_index(i1, imports_0d, OOC_UINT32, 1980))*4);
      OOC_Make_WriteMainFileC__WriteFile_WriteModuleName((IO_TextRider__Writer)i0, (void*)(OOC_INT32)prefix, prefix_0d, (OOC_Repository__Module)i2, (void*)(OOC_INT32)suffix, suffix_0d);
l6:
      i1 = i1+1;
      i = i1;
      i2 = i1<imports_0d;
      if (i2) goto l3_loop;
l11:
      return;
      ;
    }


  OOC_INITIALIZE_VPAR(imports__ref,imports,OOC_Repository__Module ,(imports_0d*4))
  i0 = (OOC_INT32)module;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2067)))), OOC_Repository__ModuleDesc_GetOutputChannel)),OOC_Repository__ModuleDesc_GetOutputChannel)((OOC_Repository__Module)i0, 15, 1u);
  ch = (IO__ByteChannel)i0;
  i0 = (OOC_INT32)IO_TextRider__ConnectWriter((IO__ByteChannel)i0);
  w = (IO_TextRider__Writer)i0;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2163)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "#include <RT0.oh>", 18);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2268)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
  OOC_Make_WriteMainFileC__WriteFile_WriteModules((IO_TextRider__Writer)i0, "extern void OOC_", 17, "_init0(void);", 14);
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2343)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2364)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "int main (int argc, char *argv[]) {", 36);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2424)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2436)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "  RT0__argc = (OOC_INT32)argc;", 31);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2491)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2503)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "  RT0__argv = (OOC_CHAR8**)argv;", 33);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2560)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
  OOC_Make_WriteMainFileC__WriteFile_WriteModules((IO_TextRider__Writer)i0, "  OOC_", 7, "_init0();", 10);
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2621)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "  return 0;  /* _program_exit_code */", 38);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2683)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2699)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "}", 2);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2725)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2750))+4);
  i1 = i1!=(OOC_INT32)0;
  if (!i1) goto l4;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2782))+4);
  Exception__Raise((void*)i0);
l4:
  i0 = (OOC_INT32)ch;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2806)))), IO__ChannelDesc_CloseAndRegister)),IO__ChannelDesc_CloseAndRegister)((IO__Channel)i0);
  return;
  ;
}

void OOC_OOC_Make_WriteMainFileC_init(void) {

  return;
  ;
}

/* --- */
