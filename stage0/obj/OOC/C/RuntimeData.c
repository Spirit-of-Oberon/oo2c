#include <OOC/C/RuntimeData.d>
#include <__oo2c.h>
#include <setjmp.h>

void OOC_C_RuntimeData__Write(OOC_C_DeclWriter__Writer declWriter, OOC_SymbolTable__Module symTab, OOC_C_Naming__QualTypeData qtdData, OOC_CHAR8 writeHeader) {
  register OOC_INT32 i0,i1;
  IO_TextRider__Writer w;
  ADT_ArrayList__ArrayList tdNames;
  auto void OOC_C_RuntimeData__Write_Nli(void);
  auto void OOC_C_RuntimeData__Write_CNli(void);
  auto void OOC_C_RuntimeData__Write_WriteFlags(OOC_SymbolTable__Type type);
  auto void OOC_C_RuntimeData__Write_WriteForm(const OOC_CHAR8 form__ref[], OOC_LEN form_0d);
  auto void OOC_C_RuntimeData__Write_WriteDescrVariable(OOC_SymbolTable__Type type);
  auto void OOC_C_RuntimeData__Write_WriteName(OOC_SymbolTable__Type type);
  auto void OOC_C_RuntimeData__Write_WriteTDRef(OOC_SymbolTable__Type type);
  auto void OOC_C_RuntimeData__Write_ArrayTypeDescr(OOC_SymbolTable__Array array);
  auto void OOC_C_RuntimeData__Write_TBProcs(OOC_SymbolTable__Record record, OOC_INT32 tbProcCount);
  auto void OOC_C_RuntimeData__Write_RecordTypeDescr(OOC_SymbolTable__Record record);
  auto void OOC_C_RuntimeData__Write_PointerTypeDescr(OOC_SymbolTable__Pointer pointer);
  auto void OOC_C_RuntimeData__Write_Traverse(OOC_SymbolTable__Item item, OOC_SymbolTable__ProcDecl proc);
  auto void OOC_C_RuntimeData__Write_QualTypeDescr(OOC_C_Naming__QualTypeData qtdData);
  auto void OOC_C_RuntimeData__Write_ModuleDescr(OOC_SymbolTable__Module module, ADT_ArrayList__ArrayList tdNames);
  auto void OOC_C_RuntimeData__Write_ModuleInit(OOC_SymbolTable__Module module);
    
    void OOC_C_RuntimeData__Write_Nli(void) {
      register OOC_INT32 i0;

      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1543)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i0, 32u);
      return;
      ;
    }

    
    void OOC_C_RuntimeData__Write_CNli(void) {
      register OOC_INT32 i0;

      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1734)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, ", ", 3);
      return;
      ;
    }

    
    void OOC_C_RuntimeData__Write_WriteFlags(OOC_SymbolTable__Type type) {
      register OOC_INT32 i0,i1;
      OOC_CHAR8 output;
      auto void OOC_C_RuntimeData__Write_WriteFlags_OutFlag(const OOC_CHAR8 name__ref[], OOC_LEN name_0d);
        
        void OOC_C_RuntimeData__Write_WriteFlags_OutFlag(const OOC_CHAR8 name__ref[], OOC_LEN name_0d) {
          register OOC_INT32 i0;
          OOC_ALLOCATE_VPAR(name,OOC_CHAR8 ,name_0d)

          OOC_INITIALIZE_VPAR(name__ref,name,OOC_CHAR8 ,name_0d)
          i0 = output;
          if (!i0) goto l4;
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2068)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "|", 2);
l4:
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2109)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "(1<<", 5);
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2140)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (void*)(OOC_INT32)name, name_0d);
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2169)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, ")", 2);
          output = 1u;
          return;
          ;
        }


      output = 0u;
      i0 = (OOC_INT32)type;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l22;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2310)))), &_td_OOC_SymbolTable__RecordDesc);
      if (i1) goto l11;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2632)))), &_td_OOC_SymbolTable__ArrayDesc);
      if (!i1) goto l22;
      i0 = *(OOC_UINT8*)((_check_pointer(i0, 2664))+60);
      if (!i0) goto l22;
      OOC_C_RuntimeData__Write_WriteFlags_OutFlag("RT0__flagAtomic", 16);
      goto l22;
l11:
      i0 = *(OOC_UINT8*)((_check_pointer(i0, 2343))+60);
      if (!i0) goto l14;
      OOC_C_RuntimeData__Write_WriteFlags_OutFlag("RT0__flagVTable", 16);
l14:
      i0 = (OOC_INT32)type;
      i0 = *(OOC_UINT8*)((_check_pointer(i0, 2435))+61);
      if (!i0) goto l17;
      OOC_C_RuntimeData__Write_WriteFlags_OutFlag("RT0__flagAtomic", 16);
l17:
      i0 = (OOC_INT32)type;
      i0 = OOC_SymbolTable_Predef__ImplementsFinalize((OOC_SymbolTable__Record)i0);
      if (!i0) goto l22;
      OOC_C_RuntimeData__Write_WriteFlags_OutFlag("RT0__flagFinalize", 18);
l22:
      i0 = output;
      i0 = !i0;
      if (!i0) goto l25;
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2802)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "0", 2);
l25:
      return;
      ;
    }

    
    void OOC_C_RuntimeData__Write_WriteForm(const OOC_CHAR8 form__ref[], OOC_LEN form_0d) {
      register OOC_INT32 i0;
      OOC_ALLOCATE_VPAR(form,OOC_CHAR8 ,form_0d)

      OOC_INITIALIZE_VPAR(form__ref,form,OOC_CHAR8 ,form_0d)
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2916)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "RT0__", 6);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2966)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (void*)(OOC_INT32)form, form_0d);
      return;
      ;
    }

    
    void OOC_C_RuntimeData__Write_WriteDescrVariable(OOC_SymbolTable__Type type) {
      register OOC_INT32 i0,i1,i2;
      Object__String name;

      i0 = (OOC_INT32)qtdData;
      i1 = (OOC_INT32)type;
      i0 = (OOC_INT32)OOC_C_Naming__NameOfTypeDescriptor((OOC_SymbolTable__Type)i1, (OOC_C_Naming__QualTypeData)i0);
      name = (Object__String)i0;
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 3170)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i2);
      i2 = writeHeader;
      if (i2) goto l10;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3260))+24);
      i2 = i2!=(OOC_INT32)0;
      if (i2) goto l5;
      i1=0u;
      goto l7;
l5:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3299))+24);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3311))+4);
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3320)))), &_td_OOC_SymbolTable__ModuleDesc);
      
l7:
      if (!i1) goto l11;
      i1 = (OOC_INT32)tdNames;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3355)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i1, (Object__Object)i0);
      goto l11;
l10:
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3216)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, "extern ", 8);
l11:
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3389)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, "RT0__StructDesc", 16);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3428)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, " ", 2);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3456)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i1, (Object__Object)i0);
      i0 = writeHeader;
      if (i0) goto l14;
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3554)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, " = {", 5);
      OOC_C_RuntimeData__Write_Nli();
      goto l15;
l14:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3513)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, ";", 2);
l15:
      return;
      ;
    }

    
    void OOC_C_RuntimeData__Write_WriteName(OOC_SymbolTable__Type type) {
      register OOC_INT32 i0,i1,i2;

      OOC_C_RuntimeData__Write_CNli();
      i0 = (OOC_INT32)type;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3707))+24);
      i1 = i1==(OOC_INT32)0;
      if (i1) goto l3;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3785)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i1, 34u);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3832))+24);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3844))+20);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3850))+12);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3832))+24);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3844))+20);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3850))+12);
      i2 = (OOC_INT32)w;
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 3855)), 0);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 3813)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, (void*)(_check_pointer(i0, 3855)), i1);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3868)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i0, 34u);
      goto l4;
l3:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3741)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "NULL", 5);
l4:
      return;
      ;
    }

    
    void OOC_C_RuntimeData__Write_WriteTDRef(OOC_SymbolTable__Type type) {
      register OOC_INT32 i0,i1;
      Object__String name;

      i0 = (OOC_INT32)type;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4014)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
      type = (OOC_SymbolTable__Type)i0;
      i1 = *(OOC_UINT8*)((_check_pointer(i0, 4039))+38);
      if (i1) goto l3;
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4196)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "NULL", 5);
      goto l4;
l3:
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4068)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, "&", 2);
      i1 = (OOC_INT32)qtdData;
      i0 = (OOC_INT32)OOC_C_Naming__NameOfTypeDescriptor((OOC_SymbolTable__Type)i0, (OOC_C_Naming__QualTypeData)i1);
      name = (Object__String)i0;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4156)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i1, (Object__Object)i0);
l4:
      return;
      ;
    }

    
    void OOC_C_RuntimeData__Write_ArrayTypeDescr(OOC_SymbolTable__Array array) {
      register OOC_INT32 i0,i1,i2;
      OOC_SymbolTable__Type base;

      i0 = (OOC_INT32)array;
      OOC_C_RuntimeData__Write_WriteDescrVariable((OOC_SymbolTable__Type)i0);
      i1 = writeHeader;
      i1 = !i1;
      if (!i1) goto l7;
      i1 = *(OOC_UINT8*)((_check_pointer(i0, 4416))+40);
      if (i1) goto l5;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5122)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, "(RT0__Struct[]){", 17);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5200))+44);
      OOC_C_RuntimeData__Write_WriteTDRef((OOC_SymbolTable__Type)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5226)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i1, 125u);
      OOC_C_RuntimeData__Write_CNli();
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5262)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, "NULL", 5);
      OOC_C_RuntimeData__Write_CNli();
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5317)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, "NULL", 5);
      OOC_C_RuntimeData__Write_CNli();
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5373)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, "&_mid", 6);
      OOC_C_RuntimeData__Write_WriteName((OOC_SymbolTable__Type)i0);
      OOC_C_RuntimeData__Write_CNli();
      i1 = (OOC_INT32)w;
      i2 = *(OOC_INT32*)((_check_pointer(i0, 5497))+32);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5480)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i1, i2, 0);
      OOC_C_RuntimeData__Write_CNli();
      i1 = (OOC_INT32)w;
      i2 = *(OOC_INT32*)((_check_pointer(i0, 5555))+52);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5537)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i1, i2, 0);
      OOC_C_RuntimeData__Write_CNli();
      OOC_C_RuntimeData__Write_WriteFlags((OOC_SymbolTable__Type)i0);
      OOC_C_RuntimeData__Write_CNli();
      OOC_C_RuntimeData__Write_WriteForm("strArray", 9);
      goto l6;
l5:
      i1 = (OOC_INT32)OOC_SymbolTable__ArrayDesc_GetNonOpenElementType((OOC_SymbolTable__Array)i0);
      base = (OOC_SymbolTable__Type)i1;
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 4496)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, "(RT0__Struct[]){", 17);
      OOC_C_RuntimeData__Write_WriteTDRef((OOC_SymbolTable__Type)i1);
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 4587)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i2, 125u);
      OOC_C_RuntimeData__Write_CNli();
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 4623)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, "NULL", 5);
      OOC_C_RuntimeData__Write_CNli();
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 4678)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, "NULL", 5);
      OOC_C_RuntimeData__Write_CNli();
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 4734)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, "&_mid", 6);
      OOC_C_RuntimeData__Write_WriteName((OOC_SymbolTable__Type)i0);
      i2 = *(OOC_INT32*)((_check_pointer(i1, 4845))+32);
      _assert((i2>=0), 127, 4834);
      OOC_C_RuntimeData__Write_CNli();
      i2 = (OOC_INT32)w;
      i1 = *(OOC_INT32*)((_check_pointer(i1, 4892))+32);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 4875)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i2, i1, 0);
      OOC_C_RuntimeData__Write_CNli();
      i1 = OOC_SymbolTable__ArrayDesc_GetOpenDimensions((OOC_SymbolTable__Array)i0);
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 4932)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i2, i1, 0);
      OOC_C_RuntimeData__Write_CNli();
      OOC_C_RuntimeData__Write_WriteFlags((OOC_SymbolTable__Type)i0);
      OOC_C_RuntimeData__Write_CNli();
      OOC_C_RuntimeData__Write_WriteForm("strOpenArray", 13);
l6:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5706)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, " };", 4);
l7:
      return;
      ;
    }

    
    void OOC_C_RuntimeData__Write_TBProcs(OOC_SymbolTable__Record record, OOC_INT32 tbProcCount) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      OOC_INT32 i;
      OOC_SymbolTable__ProcDecl proc;
      Object__String name;

      i = 0;
      i0 = tbProcCount;
      i1 = 0<i0;
      if (!i1) goto l11;
      i1 = (OOC_INT32)record;
      i2=0;
l3_loop:
      i3 = i2!=0;
      if (!i3) goto l6;
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 5985)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i3, 44u);
l6:
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6039))+52);
      i3 = (OOC_INT32)OOC_SymbolTable_Namespace__ExtendedDesc_GetTBProcByIndex((OOC_SymbolTable_Namespace__Extended)(_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 6054)))), &_td_OOC_SymbolTable_Namespace__ExtendedDesc, 6054)), i2);
      proc = (OOC_SymbolTable__ProcDecl)i3;
      _assert((i3!=(OOC_INT32)0), 127, 6095);
      i4 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 6125)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i4, "(void*)", 8);
      i3 = (OOC_INT32)OOC_C_Naming__NameOfDeclaration((OOC_SymbolTable__Declaration)i3);
      name = (Object__String)i3;
      i4 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 6210)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i4, (Object__Object)i3);
      i2 = i2+1;
      i = i2;
      i3 = i2<i0;
      if (i3) goto l3_loop;
l11:
      return;
      ;
    }

    
    void OOC_C_RuntimeData__Write_RecordTypeDescr(OOC_SymbolTable__Record record) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_INT32 len;
      auto OOC_INT32 OOC_C_RuntimeData__Write_RecordTypeDescr_BaseTypes(OOC_SymbolTable__Type t);
        
        OOC_INT32 OOC_C_RuntimeData__Write_RecordTypeDescr_BaseTypes(OOC_SymbolTable__Type t) {
          register OOC_INT32 i0,i1,i2,i3;
          OOC_INT32 len;
          Object__String name;

          i0 = (OOC_INT32)t;
          i1 = i0==(OOC_INT32)0;
          if (i1) goto l6;
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6532)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
          t = (OOC_SymbolTable__Type)i0;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6578)))), &_td_OOC_SymbolTable__RecordDesc, 6578)), 6585))+40);
          i1 = OOC_C_RuntimeData__Write_RecordTypeDescr_BaseTypes((OOC_SymbolTable__Type)i1);
          len = i1;
          i2 = (OOC_INT32)qtdData;
          i2 = (OOC_INT32)OOC_C_Naming__NameOfTypeDescriptor((OOC_SymbolTable__Type)i0, (OOC_C_Naming__QualTypeData)i2);
          name = (Object__String)i2;
          i3 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 6669)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i3, 38u);
          i3 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 6699)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i3, (Object__Object)i2);
          i2 = (OOC_INT32)record;
          i0 = i0!=i2;
          if (!i0) goto l5;
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6764)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i0, 44u);
l5:
          return (i1+1);
          goto l7;
l6:
          return (-1);
l7:
          _failed_function(6356); return 0;
          ;
        }


      i0 = (OOC_INT32)record;
      OOC_C_RuntimeData__Write_WriteDescrVariable((OOC_SymbolTable__Type)i0);
      i1 = writeHeader;
      i1 = !i1;
      if (!i1) goto l4;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6938)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, "(RT0__Struct[]){", 17);
      i0 = OOC_C_RuntimeData__Write_RecordTypeDescr_BaseTypes((OOC_SymbolTable__Type)i0);
      len = i0;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7034)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i1, 125u);
      OOC_C_RuntimeData__Write_CNli();
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7068)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, "(void*[]){", 11);
      i1 = (OOC_INT32)record;
      i2 = *(OOC_INT32*)((_check_pointer(i1, 7144))+48);
      OOC_C_RuntimeData__Write_TBProcs((OOC_SymbolTable__Record)i1, i2);
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 7168)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i2, 125u);
      OOC_C_RuntimeData__Write_CNli();
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 7202)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, "NULL", 5);
      OOC_C_RuntimeData__Write_CNli();
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 7258)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, "&_mid", 6);
      OOC_C_RuntimeData__Write_WriteName((OOC_SymbolTable__Type)i1);
      OOC_C_RuntimeData__Write_CNli();
      i2 = (OOC_INT32)w;
      i3 = *(OOC_INT32*)((_check_pointer(i1, 7383))+32);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 7364)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i2, i3, 0);
      OOC_C_RuntimeData__Write_CNli();
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 7421)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i2, i0, 0);
      OOC_C_RuntimeData__Write_CNli();
      OOC_C_RuntimeData__Write_WriteFlags((OOC_SymbolTable__Type)i1);
      OOC_C_RuntimeData__Write_CNli();
      OOC_C_RuntimeData__Write_WriteForm("strRecord", 10);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7572)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, " };", 4);
l4:
      return;
      ;
    }

    
    void OOC_C_RuntimeData__Write_PointerTypeDescr(OOC_SymbolTable__Pointer pointer) {
      register OOC_INT32 i0,i1,i2;

      i0 = (OOC_INT32)pointer;
      OOC_C_RuntimeData__Write_WriteDescrVariable((OOC_SymbolTable__Type)i0);
      i1 = writeHeader;
      i1 = !i1;
      if (!i1) goto l4;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7769)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, "(RT0__Struct[]){", 17);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7847))+40);
      OOC_C_RuntimeData__Write_WriteTDRef((OOC_SymbolTable__Type)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7868)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i1, 125u);
      OOC_C_RuntimeData__Write_CNli();
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7902)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, "NULL", 5);
      OOC_C_RuntimeData__Write_CNli();
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7957)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, "NULL", 5);
      OOC_C_RuntimeData__Write_CNli();
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8013)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, "&_mid", 6);
      OOC_C_RuntimeData__Write_WriteName((OOC_SymbolTable__Type)i0);
      OOC_C_RuntimeData__Write_CNli();
      i1 = (OOC_INT32)w;
      i2 = *(OOC_INT32*)((_check_pointer(i0, 8139))+32);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8119)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i1, i2, 0);
      OOC_C_RuntimeData__Write_CNli();
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8177)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i1, (-1), 0);
      OOC_C_RuntimeData__Write_CNli();
      OOC_C_RuntimeData__Write_WriteFlags((OOC_SymbolTable__Type)i0);
      OOC_C_RuntimeData__Write_CNli();
      OOC_C_RuntimeData__Write_WriteForm("strPointer", 11);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8327)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, " };", 4);
l4:
      return;
      ;
    }

    
    void OOC_C_RuntimeData__Write_Traverse(OOC_SymbolTable__Item item, OOC_SymbolTable__ProcDecl proc) {
      register OOC_INT32 i0,i1,i2;
      OOC_SymbolTable__Item nested;
      auto OOC_CHAR8 OOC_C_RuntimeData__Write_Traverse_IsParameter(OOC_SymbolTable__Item item);
        
        OOC_CHAR8 OOC_C_RuntimeData__Write_Traverse_IsParameter(OOC_SymbolTable__Item item) {
          register OOC_INT32 i0,i1,i2;

          i0 = (OOC_INT32)item;
          i1 = (OOC_INT32)proc;
          i2 = i0!=i1;
          if (i2) goto l3;
          i2=0u;
          goto l9;
l3:
          i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8599)))), &_td_OOC_SymbolTable__VarDeclDesc);
          if (i2) goto l6;
          i2=0u;
          goto l7;
l6:
          i2 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8626)))), &_td_OOC_SymbolTable__VarDeclDesc, 8626)), 8634))+56);
          
l7:
          i2 = !i2;
          
l9:
          if (!i2) goto l25;
l12_loop:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8674))+4);
          item = (OOC_SymbolTable__Item)i0;
          i2 = i0!=i1;
          if (i2) goto l15;
          i2=0u;
          goto l21;
l15:
          i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8599)))), &_td_OOC_SymbolTable__VarDeclDesc);
          if (i2) goto l18;
          i2=0u;
          goto l19;
l18:
          i2 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8626)))), &_td_OOC_SymbolTable__VarDeclDesc, 8626)), 8634))+56);
          
l19:
          i2 = !i2;
          
l21:
          if (i2) goto l12_loop;
l25:
          return (i0!=i1);
          ;
        }


      i0 = (OOC_INT32)item;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8776)))), &_td_OOC_SymbolTable__ArrayDesc);
      if (i1) goto l20;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8907)))), &_td_OOC_SymbolTable__RecordDesc);
      if (i1) goto l15;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9026)))), &_td_OOC_SymbolTable__PointerDesc);
      if (i1) goto l10;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9147)))), &_td_OOC_SymbolTable__ProcDeclDesc);
      if (!i1) goto l28;
      proc = (OOC_SymbolTable__ProcDecl)i0;
      goto l28;
l10:
      i1 = *(OOC_UINT8*)((_check_pointer(i0, 9058))+38);
      if (!i1) goto l28;
      OOC_C_RuntimeData__Write_PointerTypeDescr((OOC_SymbolTable__Pointer)i0);
      goto l28;
l15:
      i1 = *(OOC_UINT8*)((_check_pointer(i0, 8938))+38);
      if (!i1) goto l28;
      OOC_C_RuntimeData__Write_RecordTypeDescr((OOC_SymbolTable__Record)i0);
      goto l28;
l20:
      i1 = *(OOC_UINT8*)((_check_pointer(i0, 8806))+38);
      if (i1) goto l23;
      i1=0u;
      goto l25;
l23:
      i1 = OOC_C_RuntimeData__Write_Traverse_IsParameter((OOC_SymbolTable__Item)i0);
      i1 = !i1;
      
l25:
      if (!i1) goto l28;
      OOC_C_RuntimeData__Write_ArrayTypeDescr((OOC_SymbolTable__Array)i0);
l28:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9331))+8);
      nested = (OOC_SymbolTable__Item)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l36;
      i1 = (OOC_INT32)proc;
      
l31_loop:
      OOC_C_RuntimeData__Write_Traverse((OOC_SymbolTable__Item)i0, (OOC_SymbolTable__ProcDecl)i1);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9433));
      nested = (OOC_SymbolTable__Item)i0;
      i2 = i0!=(OOC_INT32)0;
      if (i2) goto l31_loop;
l36:
      return;
      ;
    }

    
    void OOC_C_RuntimeData__Write_QualTypeDescr(OOC_C_Naming__QualTypeData qtdData) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_INT32 i;
      auto Object__String OOC_C_RuntimeData__Write_QualTypeDescr_QualTypeName(OOC_SymbolTable__Type t);
      auto OOC_INT32 OOC_C_RuntimeData__Write_QualTypeDescr_BaseTypes(OOC_SymbolTable__Type record, OOC_SymbolTable__Type t);
      auto void OOC_C_RuntimeData__Write_QualTypeDescr_WriteQualTypeDescr(OOC_C_Naming__QualTypeDescr qtd);
        
        Object__String OOC_C_RuntimeData__Write_QualTypeDescr_QualTypeName(OOC_SymbolTable__Type t) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
          ADT_StringBuffer__StringBuffer sb;
          OOC_INT32 i;
          OOC_SymbolTable__Module module;

          i0 = (OOC_INT32)RT0__NewObject(_td_ADT_StringBuffer__StringBuffer.baseTypes[0]);
          ADT_StringBuffer__StringBufferDesc_INIT((ADT_StringBuffer__StringBuffer)i0, 128);
          sb = (ADT_StringBuffer__StringBuffer)i0;
          i1 = (OOC_INT32)t;
          i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9784)))), &_td_OOC_SymbolTable__TypeClosureDesc);
          if (i2) goto l3;
          i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10133)))), OOC_SymbolTable__ItemDesc_Module)),OOC_SymbolTable__ItemDesc_Module)((OOC_SymbolTable__Item)i1);
          module = (OOC_SymbolTable__Module)i2;
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 10176))+20);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 10181))+12);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 10176))+20);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 10181))+12);
          i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 10185)), 0);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10156)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i0, (void*)(_check_pointer(i2, 10185)), i3);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10201)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c0));
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10242))+24);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 10253))+20);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 10258))+12);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10242))+24);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10253))+20);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10258))+12);
          i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 10262)), 0);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10227)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i0, (void*)(_check_pointer(i1, 10262)), i2);
          goto l15;
l3:
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 9839))+40);
          i2 = (OOC_INT32)OOC_C_RuntimeData__Write_QualTypeDescr_QualTypeName((OOC_SymbolTable__Type)i2);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9817)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i2);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9864)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c1));
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 9907))+48);
          i = 0;
          i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 9917)), 0);
          i3 = 0<i2;
          if (!i3) goto l14;
          i3 = (OOC_INT32)_c2;
          i4=0;
l6_loop:
          i5 = i4!=0;
          if (!i5) goto l9;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9969)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i3);
l9:
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10036))+48);
          i5 = _check_pointer(i5, 10046);
          i6 = OOC_ARRAY_LENGTH(i5, 0);
          i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 10046))*8);
          i5 = (OOC_INT32)OOC_C_RuntimeData__Write_QualTypeDescr_QualTypeName((OOC_SymbolTable__Type)i5);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10014)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i5);
          i4 = i4+1;
          i = i4;
          i5 = i4<i2;
          if (i5) goto l6_loop;
l14:
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10085)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c3));
l15:
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10296)))), ADT_StringBuffer__StringBufferDesc_ToString)),ADT_StringBuffer__StringBufferDesc_ToString)((ADT_StringBuffer__StringBuffer)i0);
          return (Object__String)i0;
          ;
        }

        
        OOC_INT32 OOC_C_RuntimeData__Write_QualTypeDescr_BaseTypes(OOC_SymbolTable__Type record, OOC_SymbolTable__Type t) {
          register OOC_INT32 i0,i1,i2,i3,i4;
          OOC_INT32 len;
          Object__String name;

          i0 = (OOC_INT32)t;
          i1 = i0==(OOC_INT32)0;
          if (i1) goto l6;
          i1 = (OOC_INT32)OOC_SymbolTable_TypeRules__RecordBaseType((OOC_SymbolTable__Type)i0);
          i2 = (OOC_INT32)record;
          i1 = OOC_C_RuntimeData__Write_QualTypeDescr_BaseTypes((OOC_SymbolTable__Type)i2, (OOC_SymbolTable__Type)i1);
          len = i1;
          i3 = (OOC_INT32)qtdData;
          i3 = (OOC_INT32)OOC_C_Naming__NameOfTypeDescriptor((OOC_SymbolTable__Type)i0, (OOC_C_Naming__QualTypeData)i3);
          name = (Object__String)i3;
          i4 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 10659)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i4, 38u);
          i4 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 10689)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i4, (Object__Object)i3);
          i0 = i0!=i2;
          if (!i0) goto l5;
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10754)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i0, 44u);
l5:
          return (i1+1);
          goto l7;
l6:
          return (-1);
l7:
          _failed_function(10352); return 0;
          ;
        }

        
        void OOC_C_RuntimeData__Write_QualTypeDescr_WriteQualTypeDescr(OOC_C_Naming__QualTypeDescr qtd) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
          OOC_INT32 len;
          OOC_SymbolTable__Record record;
          Object__String name;
          OOC_INT32 i;

          i0 = (OOC_INT32)qtd;
          i1 = (OOC_INT32)tdNames;
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 11031));
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11020)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i1, (Object__Object)i2);
          i1 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11094)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i1);
          i1 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11113)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, "static ", 8);
          i1 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11147)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, "RT0__StructDesc", 16);
          i1 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11186)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, " ", 2);
          i1 = (OOC_INT32)w;
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 11230));
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11214)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i1, (Object__Object)i2);
          i1 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11247)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, " = {", 5);
          OOC_C_RuntimeData__Write_Nli();
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11298))+4);
          i1 = (OOC_INT32)OOC_SymbolTable__TypeClosureDesc_Deparam((OOC_SymbolTable__TypeClosure)i1);
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11314)))), &_td_OOC_SymbolTable__RecordDesc);
          if (i1) goto l3;
          len = 0;
          i1 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11742)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, "(RT0__Struct[]){", 17);
          i1 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11805)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, "&", 2);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11892))+4);
          i2 = (OOC_INT32)qtdData;
          i1 = (OOC_INT32)OOC_SymbolTable_TypeRules__PointerBaseType((OOC_SymbolTable__Type)i1);
          i1 = (OOC_INT32)OOC_C_Naming__NameOfTypeDescriptor((OOC_SymbolTable__Type)i1, (OOC_C_Naming__QualTypeData)i2);
          name = (Object__String)i1;
          i2 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 11967)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i2, (Object__Object)i1);
          i1 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11998)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i1, 125u);
          OOC_C_RuntimeData__Write_CNli();
          i1 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 12034)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, "NULL", 5);
          record = (OOC_SymbolTable__Record)0;
          i1=0;i2=0;
          goto l4;
l3:
          i1 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11345)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, "(RT0__Struct[]){", 17);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11438))+4);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11428))+4);
          i1 = OOC_C_RuntimeData__Write_QualTypeDescr_BaseTypes((OOC_SymbolTable__Type)i2, (OOC_SymbolTable__Type)i1);
          len = i1;
          i2 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 11457)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i2, 125u);
          OOC_C_RuntimeData__Write_CNli();
          i2 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 11504)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, "(void*[]){", 11);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11571))+4);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 11576))+40);
          i2 = _type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 11590)))), &_td_OOC_SymbolTable__RecordDesc, 11590);
          record = (OOC_SymbolTable__Record)i2;
          i3 = *(OOC_INT32*)((_check_pointer(i2, 11631))+48);
          OOC_C_RuntimeData__Write_TBProcs((OOC_SymbolTable__Record)i2, i3);
          i3 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 11657)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i3, 125u);
          
l4:
          OOC_C_RuntimeData__Write_CNli();
          i3 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 12134)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i3, "(RT0__Struct[]){", 17);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12205))+4);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 12210))+40);
          OOC_C_RuntimeData__Write_WriteTDRef((OOC_SymbolTable__Type)i3);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12251))+4);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 12256))+48);
          i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 12266)), 0);
          i = 0;
          i4 = 0<i3;
          if (!i4) goto l12;
          i4=0;
l7_loop:
          OOC_C_RuntimeData__Write_CNli();
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12314))+4);
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 12319))+48);
          i5 = _check_pointer(i5, 12329);
          i6 = OOC_ARRAY_LENGTH(i5, 0);
          i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 12329))*8);
          OOC_C_RuntimeData__Write_WriteTDRef((OOC_SymbolTable__Type)i5);
          i4 = i4+1;
          i = i4;
          i5 = i4<i3;
          if (i5) goto l7_loop;
l12:
          i3 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 12362)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i3, ", NULL}", 8);
          OOC_C_RuntimeData__Write_CNli();
          i3 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 12411)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i3, "&_mid", 6);
          OOC_C_RuntimeData__Write_CNli();
          i3 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 12474)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i3, 34u);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12549))+4);
          i3 = (OOC_INT32)OOC_C_RuntimeData__Write_QualTypeDescr_QualTypeName((OOC_SymbolTable__Type)i3);
          i4 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 12520)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i4, (Object__Object)i3);
          i3 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 12567)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i3, 34u);
          OOC_C_RuntimeData__Write_CNli();
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12622))+4);
          i3 = (OOC_INT32)w;
          i0 = *(OOC_INT32*)((_check_pointer(i0, 12627))+32);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 12608)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i3, i0, 0);
          OOC_C_RuntimeData__Write_CNli();
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12664)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i0, i1, 0);
          OOC_C_RuntimeData__Write_CNli();
          OOC_C_RuntimeData__Write_WriteFlags((OOC_SymbolTable__Type)i2);
          OOC_C_RuntimeData__Write_CNli();
          OOC_C_RuntimeData__Write_WriteForm("strQualType", 12);
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12815)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, " };", 4);
          return;
          ;
        }


      i0 = (OOC_INT32)qtdData;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 12908));
      i = 0;
      i0 = *(OOC_INT32*)((_check_pointer(i0, 12913))+4);
      i1 = 0<i0;
      if (!i1) goto l8;
      i1=0;
l3_loop:
      i2 = (OOC_INT32)qtdData;
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 12958));
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 12963));
      i2 = _check_pointer(i2, 12969);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i1 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i1, i3, OOC_UINT32, 12969))*4);
      OOC_C_RuntimeData__Write_QualTypeDescr_WriteQualTypeDescr((OOC_C_Naming__QualTypeDescr)i1);
      i1 = i;
      i1 = i1+1;
      i = i1;
      i2 = i1<i0;
      if (i2) goto l3_loop;
l8:
      return;
      ;
    }

    
    void OOC_C_RuntimeData__Write_ModuleDescr(OOC_SymbolTable__Module module, ADT_ArrayList__ArrayList tdNames) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      OOC_INT32 i;

      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13131)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13149)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "static RT0__ModuleDesc _mid = {", 32);
      OOC_C_RuntimeData__Write_Nli();
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13218)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "(OOC_CHAR8*)\"", 14);
      i0 = (OOC_INT32)module;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13279))+20);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 13285))+12);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13279))+20);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13285))+12);
      i2 = (OOC_INT32)w;
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 13290)), 0);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 13258)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, (void*)(_check_pointer(i0, 13290)), i1);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13301)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "\"", 2);
      OOC_C_RuntimeData__Write_CNli();
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13341)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "(RT0__Struct[]) {", 18);
      OOC_C_RuntimeData__Write_Nli();
      i0 = (OOC_INT32)tdNames;
      i = 0;
      i1 = *(OOC_INT32*)((_check_pointer(i0, 13416))+4);
      i2 = 0<i1;
      if (!i2) goto l8;
      i2=0;
l3_loop:
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 13437)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i3, "&", 2);
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13489));
      i3 = _check_pointer(i3, 13496);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 13496))*4);
      i4 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 13467)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i4, (Object__Object)(_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 13500)))), &_td_Object__StringDesc, 13500)));
      OOC_C_RuntimeData__Write_CNli();
      i2 = i2+1;
      i = i2;
      i3 = i2<i1;
      if (i3) goto l3_loop;
l8:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13542)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "NULL } };", 10);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13578)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
      return;
      ;
    }

    
    void OOC_C_RuntimeData__Write_ModuleInit(OOC_SymbolTable__Module module) {
      register OOC_INT32 i0,i1,i2,i3;
      Object__String name0;
      Object__String name;

      i0 = (OOC_INT32)module;
      i1 = (OOC_INT32)OOC_C_Naming__NameOfModuleInit((OOC_SymbolTable__Module)i0, 1u);
      name0 = (Object__String)i1;
      i2 = (OOC_INT32)OOC_C_Naming__NameOfModuleInit((OOC_SymbolTable__Module)i0, 0u);
      name = (Object__String)i2;
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 13818)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i3);
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 13836)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i3, "extern void ", 13);
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 13875)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i3, (Object__Object)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 13905)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, "() {", 5);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13945))+20);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13951))+12);
      i0 = (
      _cmp8((const void*)(_check_pointer(i0, 13956)),(const void*)"RT0"))!=0;
      if (!i0) goto l3;
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14071)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14091)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "  RT0__RegisterModule(&_mid);", 30);
l3:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14158)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14176)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "  ", 3);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14205)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i0, (Object__Object)i2);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14234)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "();", 4);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14264)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14282)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "}", 2);
      return;
      ;
    }


  i0 = (OOC_INT32)declWriter;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14353))+8);
  w = (IO_TextRider__Writer)i0;
  i1 = (OOC_INT32)ADT_ArrayList__New(16);
  tdNames = (ADT_ArrayList__ArrayList)i1;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14407)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14423)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "/* run-time meta data */", 25);
  i1 = writeHeader;
  i1 = !i1;
  if (!i1) goto l3;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14499)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14517)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "static RT0__ModuleDesc _mid;", 29);
l3:
  i0 = (OOC_INT32)symTab;
  OOC_C_RuntimeData__Write_Traverse((OOC_SymbolTable__Item)i0, (OOC_SymbolTable__ProcDecl)(OOC_INT32)0);
  i0 = writeHeader;
  i0 = !i0;
  if (!i0) goto l6;
  i0 = (OOC_INT32)qtdData;
  OOC_C_RuntimeData__Write_QualTypeDescr((OOC_C_Naming__QualTypeData)i0);
  i0 = (OOC_INT32)tdNames;
  i1 = (OOC_INT32)symTab;
  OOC_C_RuntimeData__Write_ModuleDescr((OOC_SymbolTable__Module)i1, (ADT_ArrayList__ArrayList)i0);
  i0 = (OOC_INT32)symTab;
  OOC_C_RuntimeData__Write_ModuleInit((OOC_SymbolTable__Module)i0);
l6:
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14779)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
  return;
  ;
}

void OOC_OOC_C_RuntimeData_init(void) {
  _c0 = Object__NewLatin1Char(46u);
  _c1 = Object__NewLatin1Char(40u);
  _c2 = Object__NewLatin1Char(44u);
  _c3 = Object__NewLatin1Char(41u);

  return;
  ;
}

/* --- */
