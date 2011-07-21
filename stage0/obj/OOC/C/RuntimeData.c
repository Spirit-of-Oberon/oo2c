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
  auto void OOC_C_RuntimeData__Write_ModuleOpen(OOC_SymbolTable__Module module);
  auto void OOC_C_RuntimeData__Write_ModuleClose(OOC_SymbolTable__Module module);
    
    void OOC_C_RuntimeData__Write_Nli(void) {
      register OOC_INT32 i0;

      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1555)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i0, 32u);
      return;
      ;
    }

    
    void OOC_C_RuntimeData__Write_CNli(void) {
      register OOC_INT32 i0;

      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1746)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (OOC_CHAR8*)", ", 3);
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
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2080)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (OOC_CHAR8*)"|", 2);
l4:
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2121)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (OOC_CHAR8*)"(1<<", 5);
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2152)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (void*)(OOC_INT32)name, name_0d);
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2181)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (OOC_CHAR8*)")", 2);
          output = 1u;
          return;
          ;
        }


      output = 0u;
      i0 = (OOC_INT32)type;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l22;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2322)))), &_td_OOC_SymbolTable__RecordDesc);
      if (i1) goto l11;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2644)))), &_td_OOC_SymbolTable__ArrayDesc);
      if (!i1) goto l22;
      i0 = *(OOC_UINT8*)((_check_pointer(i0, 2676))+60);
      if (!i0) goto l22;
      OOC_C_RuntimeData__Write_WriteFlags_OutFlag((OOC_CHAR8*)"RT0__flagAtomic", 16);
      goto l22;
l11:
      i0 = *(OOC_UINT8*)((_check_pointer(i0, 2355))+60);
      if (!i0) goto l14;
      OOC_C_RuntimeData__Write_WriteFlags_OutFlag((OOC_CHAR8*)"RT0__flagVTable", 16);
l14:
      i0 = (OOC_INT32)type;
      i0 = *(OOC_UINT8*)((_check_pointer(i0, 2447))+61);
      if (!i0) goto l17;
      OOC_C_RuntimeData__Write_WriteFlags_OutFlag((OOC_CHAR8*)"RT0__flagAtomic", 16);
l17:
      i0 = (OOC_INT32)type;
      i0 = OOC_SymbolTable_Predef__ImplementsFinalize((OOC_SymbolTable__Record)i0);
      if (!i0) goto l22;
      OOC_C_RuntimeData__Write_WriteFlags_OutFlag((OOC_CHAR8*)"RT0__flagFinalize", 18);
l22:
      i0 = output;
      i0 = !i0;
      if (!i0) goto l25;
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2814)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (OOC_CHAR8*)"0", 2);
l25:
      return;
      ;
    }

    
    void OOC_C_RuntimeData__Write_WriteForm(const OOC_CHAR8 form__ref[], OOC_LEN form_0d) {
      register OOC_INT32 i0;
      OOC_ALLOCATE_VPAR(form,OOC_CHAR8 ,form_0d)

      OOC_INITIALIZE_VPAR(form__ref,form,OOC_CHAR8 ,form_0d)
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2928)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (OOC_CHAR8*)"RT0__", 6);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2978)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (void*)(OOC_INT32)form, form_0d);
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
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 3182)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i2);
      i2 = writeHeader;
      if (i2) goto l10;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3272))+24);
      i2 = i2!=(OOC_INT32)0;
      if (i2) goto l5;
      i1=0u;
      goto l7;
l5:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3311))+24);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3323))+4);
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3332)))), &_td_OOC_SymbolTable__ModuleDesc);
      
l7:
      if (!i1) goto l11;
      i1 = (OOC_INT32)tdNames;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3367)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i1, (Object__Object)i0);
      goto l11;
l10:
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3228)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, (OOC_CHAR8*)"extern ", 8);
l11:
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3401)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, (OOC_CHAR8*)"RT0__StructDesc", 16);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3440)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, (OOC_CHAR8*)" ", 2);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3468)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i1, (Object__Object)i0);
      i0 = writeHeader;
      if (i0) goto l14;
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3566)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (OOC_CHAR8*)" = {", 5);
      OOC_C_RuntimeData__Write_Nli();
      goto l15;
l14:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3525)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (OOC_CHAR8*)";", 2);
l15:
      return;
      ;
    }

    
    void OOC_C_RuntimeData__Write_WriteName(OOC_SymbolTable__Type type) {
      register OOC_INT32 i0,i1,i2;

      OOC_C_RuntimeData__Write_CNli();
      i0 = (OOC_INT32)type;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3719))+24);
      i1 = i1==(OOC_INT32)0;
      if (i1) goto l3;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3797)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, (OOC_CHAR8*)"(OOC_CHAR8*)\"", 14);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3858))+24);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3870))+20);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3876))+12);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3858))+24);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3870))+20);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3876))+12);
      i2 = (OOC_INT32)w;
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 3881)), 0);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 3839)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, (void*)(_check_pointer(i0, 3881)), i1);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3894)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i0, 34u);
      goto l4;
l3:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3753)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (OOC_CHAR8*)"NULL", 5);
l4:
      return;
      ;
    }

    
    void OOC_C_RuntimeData__Write_WriteTDRef(OOC_SymbolTable__Type type) {
      register OOC_INT32 i0,i1;
      Object__String name;

      i0 = (OOC_INT32)type;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4040)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
      type = (OOC_SymbolTable__Type)i0;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4067)))), &_td_OOC_SymbolTable__TypeVarDesc);
      if (i1) goto l3;
      i1=0u;
      goto l5;
l3:
      i1 = *(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4095)))), &_td_OOC_SymbolTable__TypeVarDesc, 4095)), 4103))+48);
      i1 = i1<0;
      
l5:
      if (!i1) goto l8;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4154)))), &_td_OOC_SymbolTable__TypeVarDesc, 4154)), 4162))+40);
      type = (OOC_SymbolTable__Type)i0;
      
l8:
      i1 = *(OOC_UINT8*)((_check_pointer(i0, 4194))+38);
      if (i1) goto l11;
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4351)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (OOC_CHAR8*)"NULL", 5);
      goto l12;
l11:
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4223)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, (OOC_CHAR8*)"&", 2);
      i1 = (OOC_INT32)qtdData;
      i0 = (OOC_INT32)OOC_C_Naming__NameOfTypeDescriptor((OOC_SymbolTable__Type)i0, (OOC_C_Naming__QualTypeData)i1);
      name = (Object__String)i0;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4311)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i1, (Object__Object)i0);
l12:
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
      i1 = *(OOC_UINT8*)((_check_pointer(i0, 4571))+40);
      if (i1) goto l5;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5277)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, (OOC_CHAR8*)"(RT0__Struct[]){", 17);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5355))+44);
      OOC_C_RuntimeData__Write_WriteTDRef((OOC_SymbolTable__Type)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5381)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i1, 125u);
      OOC_C_RuntimeData__Write_CNli();
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5417)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, (OOC_CHAR8*)"NULL", 5);
      OOC_C_RuntimeData__Write_CNli();
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5472)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, (OOC_CHAR8*)"NULL", 5);
      OOC_C_RuntimeData__Write_CNli();
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5528)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, (OOC_CHAR8*)"&_mid", 6);
      OOC_C_RuntimeData__Write_WriteName((OOC_SymbolTable__Type)i0);
      OOC_C_RuntimeData__Write_CNli();
      i1 = (OOC_INT32)w;
      i2 = *(OOC_INT32*)((_check_pointer(i0, 5652))+32);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5635)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i1, i2, 0);
      OOC_C_RuntimeData__Write_CNli();
      i1 = (OOC_INT32)w;
      i2 = *(OOC_INT32*)((_check_pointer(i0, 5710))+52);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5692)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i1, i2, 0);
      OOC_C_RuntimeData__Write_CNli();
      OOC_C_RuntimeData__Write_WriteFlags((OOC_SymbolTable__Type)i0);
      OOC_C_RuntimeData__Write_CNli();
      OOC_C_RuntimeData__Write_WriteForm((OOC_CHAR8*)"strArray", 9);
      goto l6;
l5:
      i1 = (OOC_INT32)OOC_SymbolTable__ArrayDesc_GetNonOpenElementType((OOC_SymbolTable__Array)i0);
      base = (OOC_SymbolTable__Type)i1;
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 4651)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, (OOC_CHAR8*)"(RT0__Struct[]){", 17);
      OOC_C_RuntimeData__Write_WriteTDRef((OOC_SymbolTable__Type)i1);
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 4742)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i2, 125u);
      OOC_C_RuntimeData__Write_CNli();
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 4778)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, (OOC_CHAR8*)"NULL", 5);
      OOC_C_RuntimeData__Write_CNli();
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 4833)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, (OOC_CHAR8*)"NULL", 5);
      OOC_C_RuntimeData__Write_CNli();
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 4889)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, (OOC_CHAR8*)"&_mid", 6);
      OOC_C_RuntimeData__Write_WriteName((OOC_SymbolTable__Type)i0);
      i2 = *(OOC_INT32*)((_check_pointer(i1, 5000))+32);
      _assert((i2>=0), 127, 4989);
      OOC_C_RuntimeData__Write_CNli();
      i2 = (OOC_INT32)w;
      i1 = *(OOC_INT32*)((_check_pointer(i1, 5047))+32);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 5030)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i2, i1, 0);
      OOC_C_RuntimeData__Write_CNli();
      i1 = OOC_SymbolTable__ArrayDesc_GetOpenDimensions((OOC_SymbolTable__Array)i0);
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 5087)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i2, i1, 0);
      OOC_C_RuntimeData__Write_CNli();
      OOC_C_RuntimeData__Write_WriteFlags((OOC_SymbolTable__Type)i0);
      OOC_C_RuntimeData__Write_CNli();
      OOC_C_RuntimeData__Write_WriteForm((OOC_CHAR8*)"strOpenArray", 13);
l6:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5861)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (OOC_CHAR8*)" };", 4);
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
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 6140)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i3, 44u);
l6:
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6194))+52);
      i3 = (OOC_INT32)OOC_SymbolTable_Namespace__ExtendedDesc_GetTBProcByIndex((OOC_SymbolTable_Namespace__Extended)(_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 6209)))), &_td_OOC_SymbolTable_Namespace__ExtendedDesc, 6209)), i2);
      proc = (OOC_SymbolTable__ProcDecl)i3;
      _assert((i3!=(OOC_INT32)0), 127, 6250);
      i4 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 6280)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i4, (OOC_CHAR8*)"(void*)", 8);
      i3 = (OOC_INT32)OOC_C_Naming__NameOfDeclaration((OOC_SymbolTable__Declaration)i3);
      name = (Object__String)i3;
      i4 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 6365)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i4, (Object__Object)i3);
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
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6687)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
          t = (OOC_SymbolTable__Type)i0;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6733)))), &_td_OOC_SymbolTable__RecordDesc, 6733)), 6740))+40);
          i1 = OOC_C_RuntimeData__Write_RecordTypeDescr_BaseTypes((OOC_SymbolTable__Type)i1);
          len = i1;
          i2 = (OOC_INT32)qtdData;
          i2 = (OOC_INT32)OOC_C_Naming__NameOfTypeDescriptor((OOC_SymbolTable__Type)i0, (OOC_C_Naming__QualTypeData)i2);
          name = (Object__String)i2;
          i3 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 6824)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i3, 38u);
          i3 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 6854)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i3, (Object__Object)i2);
          i2 = (OOC_INT32)record;
          i0 = i0!=i2;
          if (!i0) goto l5;
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6919)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i0, 44u);
l5:
          return (i1+1);
          goto l7;
l6:
          return (-1);
l7:
          _failed_function(6511); return 0;
          ;
        }


      i0 = (OOC_INT32)record;
      OOC_C_RuntimeData__Write_WriteDescrVariable((OOC_SymbolTable__Type)i0);
      i1 = writeHeader;
      i1 = !i1;
      if (!i1) goto l4;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7093)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, (OOC_CHAR8*)"(RT0__Struct[]){", 17);
      i0 = OOC_C_RuntimeData__Write_RecordTypeDescr_BaseTypes((OOC_SymbolTable__Type)i0);
      len = i0;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7189)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i1, 125u);
      OOC_C_RuntimeData__Write_CNli();
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7223)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, (OOC_CHAR8*)"(void*[]){", 11);
      i1 = (OOC_INT32)record;
      i2 = *(OOC_INT32*)((_check_pointer(i1, 7299))+48);
      OOC_C_RuntimeData__Write_TBProcs((OOC_SymbolTable__Record)i1, i2);
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 7323)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i2, 125u);
      OOC_C_RuntimeData__Write_CNli();
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 7357)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, (OOC_CHAR8*)"NULL", 5);
      OOC_C_RuntimeData__Write_CNli();
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 7413)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, (OOC_CHAR8*)"&_mid", 6);
      OOC_C_RuntimeData__Write_WriteName((OOC_SymbolTable__Type)i1);
      OOC_C_RuntimeData__Write_CNli();
      i2 = (OOC_INT32)w;
      i3 = *(OOC_INT32*)((_check_pointer(i1, 7538))+32);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 7519)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i2, i3, 0);
      OOC_C_RuntimeData__Write_CNli();
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 7576)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i2, i0, 0);
      OOC_C_RuntimeData__Write_CNli();
      OOC_C_RuntimeData__Write_WriteFlags((OOC_SymbolTable__Type)i1);
      OOC_C_RuntimeData__Write_CNli();
      OOC_C_RuntimeData__Write_WriteForm((OOC_CHAR8*)"strRecord", 10);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7727)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (OOC_CHAR8*)" };", 4);
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
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7924)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, (OOC_CHAR8*)"(RT0__Struct[]){", 17);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8002))+40);
      OOC_C_RuntimeData__Write_WriteTDRef((OOC_SymbolTable__Type)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8023)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i1, 125u);
      OOC_C_RuntimeData__Write_CNli();
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8057)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, (OOC_CHAR8*)"NULL", 5);
      OOC_C_RuntimeData__Write_CNli();
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8112)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, (OOC_CHAR8*)"NULL", 5);
      OOC_C_RuntimeData__Write_CNli();
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8168)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, (OOC_CHAR8*)"&_mid", 6);
      OOC_C_RuntimeData__Write_WriteName((OOC_SymbolTable__Type)i0);
      OOC_C_RuntimeData__Write_CNli();
      i1 = (OOC_INT32)w;
      i2 = *(OOC_INT32*)((_check_pointer(i0, 8294))+32);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8274)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i1, i2, 0);
      OOC_C_RuntimeData__Write_CNli();
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8332)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i1, (-1), 0);
      OOC_C_RuntimeData__Write_CNli();
      OOC_C_RuntimeData__Write_WriteFlags((OOC_SymbolTable__Type)i0);
      OOC_C_RuntimeData__Write_CNli();
      OOC_C_RuntimeData__Write_WriteForm((OOC_CHAR8*)"strPointer", 11);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8482)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (OOC_CHAR8*)" };", 4);
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
          i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8754)))), &_td_OOC_SymbolTable__VarDeclDesc);
          if (i2) goto l6;
          i2=0u;
          goto l7;
l6:
          i2 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8781)))), &_td_OOC_SymbolTable__VarDeclDesc, 8781)), 8789))+56);
          
l7:
          i2 = !i2;
          
l9:
          if (!i2) goto l25;
l12_loop:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8829))+4);
          item = (OOC_SymbolTable__Item)i0;
          i2 = i0!=i1;
          if (i2) goto l15;
          i2=0u;
          goto l21;
l15:
          i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8754)))), &_td_OOC_SymbolTable__VarDeclDesc);
          if (i2) goto l18;
          i2=0u;
          goto l19;
l18:
          i2 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8781)))), &_td_OOC_SymbolTable__VarDeclDesc, 8781)), 8789))+56);
          
l19:
          i2 = !i2;
          
l21:
          if (i2) goto l12_loop;
l25:
          return (i0!=i1);
          ;
        }


      i0 = (OOC_INT32)item;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8931)))), &_td_OOC_SymbolTable__ArrayDesc);
      if (i1) goto l20;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9062)))), &_td_OOC_SymbolTable__RecordDesc);
      if (i1) goto l15;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9181)))), &_td_OOC_SymbolTable__PointerDesc);
      if (i1) goto l10;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9302)))), &_td_OOC_SymbolTable__ProcDeclDesc);
      if (!i1) goto l28;
      proc = (OOC_SymbolTable__ProcDecl)i0;
      goto l28;
l10:
      i1 = *(OOC_UINT8*)((_check_pointer(i0, 9213))+38);
      if (!i1) goto l28;
      OOC_C_RuntimeData__Write_PointerTypeDescr((OOC_SymbolTable__Pointer)i0);
      goto l28;
l15:
      i1 = *(OOC_UINT8*)((_check_pointer(i0, 9093))+38);
      if (!i1) goto l28;
      OOC_C_RuntimeData__Write_RecordTypeDescr((OOC_SymbolTable__Record)i0);
      goto l28;
l20:
      i1 = *(OOC_UINT8*)((_check_pointer(i0, 8961))+38);
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
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9486))+8);
      nested = (OOC_SymbolTable__Item)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l36;
      i1 = (OOC_INT32)proc;
      
l31_loop:
      OOC_C_RuntimeData__Write_Traverse((OOC_SymbolTable__Item)i0, (OOC_SymbolTable__ProcDecl)i1);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9588));
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
          i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9939)))), &_td_OOC_SymbolTable__TypeClosureDesc);
          if (i2) goto l3;
          i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10288)))), OOC_SymbolTable__ItemDesc_Module)),OOC_SymbolTable__ItemDesc_Module)((OOC_SymbolTable__Item)i1);
          module = (OOC_SymbolTable__Module)i2;
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 10331))+20);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 10336))+12);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 10331))+20);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 10336))+12);
          i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 10340)), 0);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10311)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i0, (void*)(_check_pointer(i2, 10340)), i3);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10356)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c0));
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10397))+24);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 10408))+20);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 10413))+12);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10397))+24);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10408))+20);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10413))+12);
          i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 10417)), 0);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10382)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i0, (void*)(_check_pointer(i1, 10417)), i2);
          goto l15;
l3:
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 9994))+40);
          i2 = (OOC_INT32)OOC_C_RuntimeData__Write_QualTypeDescr_QualTypeName((OOC_SymbolTable__Type)i2);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9972)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i2);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10019)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c1));
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10062))+48);
          i = 0;
          i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 10072)), 0);
          i3 = 0<i2;
          if (!i3) goto l14;
          i3 = (OOC_INT32)_c2;
          i4=0;
l6_loop:
          i5 = i4!=0;
          if (!i5) goto l9;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10124)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i3);
l9:
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10191))+48);
          i5 = _check_pointer(i5, 10201);
          i6 = OOC_ARRAY_LENGTH(i5, 0);
          i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 10201))*8);
          i5 = (OOC_INT32)OOC_C_RuntimeData__Write_QualTypeDescr_QualTypeName((OOC_SymbolTable__Type)i5);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10169)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i5);
          i4 = i4+1;
          i = i4;
          i5 = i4<i2;
          if (i5) goto l6_loop;
l14:
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10240)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c3));
l15:
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10451)))), ADT_StringBuffer__StringBufferDesc_ToString)),ADT_StringBuffer__StringBufferDesc_ToString)((ADT_StringBuffer__StringBuffer)i0);
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
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 10814)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i4, 38u);
          i4 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 10844)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i4, (Object__Object)i3);
          i0 = i0!=i2;
          if (!i0) goto l5;
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10909)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i0, 44u);
l5:
          return (i1+1);
          goto l7;
l6:
          return (-1);
l7:
          _failed_function(10507); return 0;
          ;
        }

        
        void OOC_C_RuntimeData__Write_QualTypeDescr_WriteQualTypeDescr(OOC_C_Naming__QualTypeDescr qtd) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
          OOC_INT32 len;
          OOC_SymbolTable__Record record;
          Object__String name;
          OOC_INT32 i;
          OOC_SymbolTable__Type type;

          i0 = (OOC_INT32)qtd;
          i1 = (OOC_INT32)tdNames;
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 11210));
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11199)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i1, (Object__Object)i2);
          i1 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11265)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i1);
          i1 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11284)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, (OOC_CHAR8*)"static ", 8);
          i1 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11318)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, (OOC_CHAR8*)"RT0__StructDesc", 16);
          i1 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11357)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, (OOC_CHAR8*)" ", 2);
          i1 = (OOC_INT32)w;
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 11401));
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11385)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i1, (Object__Object)i2);
          i1 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11418)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, (OOC_CHAR8*)" = {", 5);
          OOC_C_RuntimeData__Write_Nli();
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11469))+4);
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11475)))), &_td_OOC_SymbolTable__TypeVarDesc);
          if (i1) goto l23;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12148))+4);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12148))+4);
          i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 12153)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i2);
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 12164)))), &_td_OOC_SymbolTable__RecordDesc);
          if (i1) goto l5;
          len = 0;
          i1 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 12631)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, (OOC_CHAR8*)"(RT0__Struct[]){", 17);
          i1 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 12696)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, (OOC_CHAR8*)"&", 2);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12785))+4);
          i2 = (OOC_INT32)qtdData;
          i1 = (OOC_INT32)OOC_SymbolTable_TypeRules__PointerBaseType((OOC_SymbolTable__Type)i1);
          i1 = (OOC_INT32)OOC_C_Naming__NameOfTypeDescriptor((OOC_SymbolTable__Type)i1, (OOC_C_Naming__QualTypeData)i2);
          name = (Object__String)i1;
          i2 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 12816)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i2, (Object__Object)i1);
          i1 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 12849)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i1, 125u);
          OOC_C_RuntimeData__Write_CNli();
          i1 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 12887)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, (OOC_CHAR8*)"NULL", 5);
          record = (OOC_SymbolTable__Record)0;
          i1=0;i2=0;
          goto l6;
l5:
          i1 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 12197)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, (OOC_CHAR8*)"(RT0__Struct[]){", 17);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12292))+4);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12282))+4);
          i1 = OOC_C_RuntimeData__Write_QualTypeDescr_BaseTypes((OOC_SymbolTable__Type)i2, (OOC_SymbolTable__Type)i1);
          len = i1;
          i2 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 12313)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i2, 125u);
          OOC_C_RuntimeData__Write_CNli();
          i2 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 12364)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, (OOC_CHAR8*)"(void*[]){", 11);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12433))+4);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 12443)))), &_td_OOC_SymbolTable__TypeClosureDesc, 12443)), 12455))+40);
          i2 = _type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 12469)))), &_td_OOC_SymbolTable__RecordDesc, 12469);
          record = (OOC_SymbolTable__Record)i2;
          i3 = *(OOC_INT32*)((_check_pointer(i2, 12512))+48);
          OOC_C_RuntimeData__Write_TBProcs((OOC_SymbolTable__Record)i2, i3);
          i3 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 12540)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i3, 125u);
          
l6:
          OOC_C_RuntimeData__Write_CNli();
          i3 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 12995)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i3, (OOC_CHAR8*)"(RT0__Struct[]){", 17);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13068))+4);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 13078)))), &_td_OOC_SymbolTable__TypeClosureDesc, 13078)), 13090))+40);
          OOC_C_RuntimeData__Write_WriteTDRef((OOC_SymbolTable__Type)i3);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13133))+4);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 13143)))), &_td_OOC_SymbolTable__TypeClosureDesc, 13143)), 13155))+48);
          i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 13165)), 0);
          i = 0;
          i4 = 0<i3;
          if (!i4) goto l22;
          i4=0;
l9_loop:
          OOC_C_RuntimeData__Write_CNli();
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13214))+4);
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i5, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 13224)))), &_td_OOC_SymbolTable__TypeClosureDesc, 13224)), 13236))+48);
          i5 = _check_pointer(i5, 13246);
          i6 = OOC_ARRAY_LENGTH(i5, 0);
          i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 13246))*8);
          type = (OOC_SymbolTable__Type)i5;
          i6 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 13278)))), &_td_OOC_SymbolTable__TypeVarDesc));
          if (i6) goto l12;
          i6=0u;
          goto l14;
l12:
          i6 = OOC_SymbolTable_TypeRules__IsPointer((OOC_SymbolTable__Type)i5);
          
l14:
          if (!i6) goto l17;
          i5 = (OOC_INT32)OOC_SymbolTable_TypeRules__PointerBaseType((OOC_SymbolTable__Type)i5);
          type = (OOC_SymbolTable__Type)i5;
          
l17:
          OOC_C_RuntimeData__Write_WriteTDRef((OOC_SymbolTable__Type)i5);
          i4 = i4+1;
          i = i4;
          i5 = i4<i3;
          if (i5) goto l9_loop;
l22:
          i3 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 13441)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i3, (OOC_CHAR8*)", NULL}", 8);
          OOC_C_RuntimeData__Write_CNli();
          i3 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 13494)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i3, (OOC_CHAR8*)"&_mid", 6);
          OOC_C_RuntimeData__Write_CNli();
          i3 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 13561)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i3, (OOC_CHAR8*)"(OOC_CHAR8*)\"", 14);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13643))+4);
          i3 = (OOC_INT32)OOC_C_RuntimeData__Write_QualTypeDescr_QualTypeName((OOC_SymbolTable__Type)i3);
          i4 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 13614)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i4, (Object__Object)i3);
          i3 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 13663)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i3, 34u);
          OOC_C_RuntimeData__Write_CNli();
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 13722))+4);
          i3 = (OOC_INT32)w;
          i0 = *(OOC_INT32*)((_check_pointer(i0, 13727))+32);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 13708)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i3, i0, 0);
          OOC_C_RuntimeData__Write_CNli();
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13766)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i0, i1, 0);
          OOC_C_RuntimeData__Write_CNli();
          OOC_C_RuntimeData__Write_WriteFlags((OOC_SymbolTable__Type)i2);
          OOC_C_RuntimeData__Write_CNli();
          OOC_C_RuntimeData__Write_WriteForm((OOC_CHAR8*)"strQualType", 12);
          goto l24;
l23:
          i1 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11507)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, (OOC_CHAR8*)"NULL", 5);
          OOC_C_RuntimeData__Write_CNli();
          i1 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11564)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, (OOC_CHAR8*)"NULL", 5);
          OOC_C_RuntimeData__Write_CNli();
          i1 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11619)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, (OOC_CHAR8*)"NULL", 5);
          OOC_C_RuntimeData__Write_CNli();
          i1 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11684)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, (OOC_CHAR8*)"&_mid", 6);
          OOC_C_RuntimeData__Write_CNli();
          i1 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11740)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, (OOC_CHAR8*)"(OOC_CHAR8*)\"", 14);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11822))+4);
          i1 = (OOC_INT32)OOC_C_RuntimeData__Write_QualTypeDescr_QualTypeName((OOC_SymbolTable__Type)i1);
          i2 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 11793)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i2, (Object__Object)i1);
          i1 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11842)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i1, 34u);
          OOC_C_RuntimeData__Write_CNli();
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11901))+4);
          i2 = (OOC_INT32)w;
          i1 = *(OOC_INT32*)((_check_pointer(i1, 11906))+32);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 11887)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i2, i1, 0);
          OOC_C_RuntimeData__Write_CNli();
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11959))+4);
          i2 = (OOC_INT32)w;
          i1 = *(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11969)))), &_td_OOC_SymbolTable__TypeVarDesc, 11969)), 11977))+48);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 11945)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i2, i1, 0);
          OOC_C_RuntimeData__Write_CNli();
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 12038))+4);
          OOC_C_RuntimeData__Write_WriteFlags((OOC_SymbolTable__Type)i0);
          OOC_C_RuntimeData__Write_CNli();
          OOC_C_RuntimeData__Write_WriteForm((OOC_CHAR8*)"strTypeVar", 11);
l24:
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13934)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (OOC_CHAR8*)" };", 4);
          return;
          ;
        }


      i0 = (OOC_INT32)qtdData;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14027));
      i = 0;
      i0 = *(OOC_INT32*)((_check_pointer(i0, 14032))+4);
      i1 = 0<i0;
      if (!i1) goto l8;
      i1=0;
l3_loop:
      i2 = (OOC_INT32)qtdData;
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 14077));
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 14082));
      i2 = _check_pointer(i2, 14088);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i1 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i1, i3, OOC_UINT32, 14088))*4);
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
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14250)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14268)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (OOC_CHAR8*)"static RT0__ModuleDesc _mid = {", 32);
      OOC_C_RuntimeData__Write_Nli();
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14337)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (OOC_CHAR8*)"(OOC_CHAR8*)\"", 14);
      i0 = (OOC_INT32)module;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14398))+20);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14404))+12);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14398))+20);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 14404))+12);
      i2 = (OOC_INT32)w;
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 14409)), 0);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 14377)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, (void*)(_check_pointer(i0, 14409)), i1);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14420)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (OOC_CHAR8*)"\"", 2);
      OOC_C_RuntimeData__Write_CNli();
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14460)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (OOC_CHAR8*)"(RT0__Struct[]) {", 18);
      OOC_C_RuntimeData__Write_Nli();
      i0 = (OOC_INT32)tdNames;
      i = 0;
      i1 = *(OOC_INT32*)((_check_pointer(i0, 14535))+4);
      i2 = 0<i1;
      if (!i2) goto l8;
      i2=0;
l3_loop:
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 14556)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i3, (OOC_CHAR8*)"&", 2);
      i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14608));
      i3 = _check_pointer(i3, 14615);
      i4 = OOC_ARRAY_LENGTH(i3, 0);
      i3 = (OOC_INT32)*(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 14615))*4);
      i4 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 14586)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i4, (Object__Object)(_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 14619)))), &_td_Object__StringDesc, 14619)));
      OOC_C_RuntimeData__Write_CNli();
      i2 = i2+1;
      i = i2;
      i3 = i2<i1;
      if (i3) goto l3_loop;
l8:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14661)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (OOC_CHAR8*)"NULL }, 0 };", 13);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14700)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
      return;
      ;
    }

    
    void OOC_C_RuntimeData__Write_ModuleOpen(OOC_SymbolTable__Module module) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      Object__String name0;
      Object__String name;
      OOC_SymbolTable__Item ptr;

      i0 = (OOC_INT32)module;
      i1 = (OOC_INT32)OOC_C_Naming__NameOfModuleInit((OOC_SymbolTable__Module)i0, 1u, 1u);
      name0 = (Object__String)i1;
      i2 = (OOC_INT32)OOC_C_Naming__NameOfModuleInit((OOC_SymbolTable__Module)i0, 1u, 0u);
      name = (Object__String)i2;
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 14973)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i3);
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 14991)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i3, (OOC_CHAR8*)"extern void ", 13);
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 15030)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i3, (Object__Object)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15060)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, (OOC_CHAR8*)"(RT0__Module client) {", 23);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15109)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15127)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, (OOC_CHAR8*)"  if (_mid.openCount == 0) {", 29);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15247))+8);
      ptr = (OOC_SymbolTable__Item)i1;
      i3 = i1!=(OOC_INT32)0;
      if (!i3) goto l14;
l3_loop:
      i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15304)))), &_td_OOC_SymbolTable__ImportDesc);
      if (!i3) goto l9;
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15337))+52);
      i3 = OOC_SymbolTable__ModuleDesc_NoObjectFile((OOC_SymbolTable__Module)i3);
      i3 = !i3;
      if (!i3) goto l9;
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 15386)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i3);
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 15409)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i3, (OOC_CHAR8*)"    ", 5);
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15487))+52);
      i3 = (OOC_INT32)OOC_C_Naming__NameOfModuleInit((OOC_SymbolTable__Module)i3, 1u, 1u);
      i4 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 15445)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i4, (Object__Object)i3);
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 15583)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i3, (OOC_CHAR8*)"(&_mid);", 9);
l9:
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 15669));
      ptr = (OOC_SymbolTable__Item)i1;
      i3 = i1!=(OOC_INT32)0;
      if (i3) goto l3_loop;
l14:
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15707)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i1);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15734))+20);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15740))+12);
      i0 = (
      _cmp8((const void*)(_check_pointer(i0, 15745)),(const void*)(OOC_CHAR8*)"RT0"))!=0;
      if (!i0) goto l17;
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15860)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15880)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (OOC_CHAR8*)"    RT0__RegisterModule(&_mid);", 32);
l17:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15949)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15967)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (OOC_CHAR8*)"    ", 5);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15998)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i0, (Object__Object)i2);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16027)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (OOC_CHAR8*)"();", 4);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16057)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16075)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i0, (Object__Object)((OOC_INT32)_c4));
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16105)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16123)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (OOC_CHAR8*)"  _mid.openCount++;", 20);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16176)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16194)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (OOC_CHAR8*)"}", 2);
      return;
      ;
    }

    
    void OOC_C_RuntimeData__Write_ModuleClose(OOC_SymbolTable__Module module) {
      register OOC_INT32 i0,i1,i2,i3;
      Object__String name0;
      Object__String name;
      OOC_SymbolTable__Item ptr;

      i0 = (OOC_INT32)module;
      i1 = (OOC_INT32)OOC_C_Naming__NameOfModuleInit((OOC_SymbolTable__Module)i0, 0u, 1u);
      name0 = (Object__String)i1;
      i2 = (OOC_INT32)OOC_C_Naming__NameOfModuleInit((OOC_SymbolTable__Module)i0, 0u, 0u);
      name = (Object__String)i2;
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 16481)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i3);
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 16499)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i3, (OOC_CHAR8*)"extern void ", 13);
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 16538)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i3, (Object__Object)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16568)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, (OOC_CHAR8*)"(RT0__Module client) {", 23);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16618)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16636)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, (OOC_CHAR8*)"  _mid.openCount--;", 20);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16682)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16700)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, (OOC_CHAR8*)"  if (_mid.openCount == 0) { ", 30);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16756)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16774)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, (OOC_CHAR8*)"    ", 5);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16805)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i1, (Object__Object)i2);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16834)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, (OOC_CHAR8*)"();", 4);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16880))+20);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 16886))+12);
      i1 = (
      _cmp8((const void*)(_check_pointer(i1, 16891)),(const void*)(OOC_CHAR8*)"RT0"))!=0;
      if (!i1) goto l3;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17006)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17026)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, (OOC_CHAR8*)"    RT0__UnregisterModule(&_mid);", 34);
l3:
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17151)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i1);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17181))+8);
      ptr = (OOC_SymbolTable__Item)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l17;
l6_loop:
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17238)))), &_td_OOC_SymbolTable__ImportDesc);
      if (!i1) goto l12;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17271))+52);
      i1 = OOC_SymbolTable__ModuleDesc_NoObjectFile((OOC_SymbolTable__Module)i1);
      i1 = !i1;
      if (!i1) goto l12;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17320)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17343)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, (OOC_CHAR8*)"    ", 5);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17421))+52);
      i1 = (OOC_INT32)OOC_C_Naming__NameOfModuleInit((OOC_SymbolTable__Module)i1, 0u, 1u);
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 17379)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i2, (Object__Object)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17518)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, (OOC_CHAR8*)"(&_mid);", 9);
l12:
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 17604));
      ptr = (OOC_SymbolTable__Item)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l6_loop;
l17:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17642)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17660)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (OOC_CHAR8*)"  }", 4);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17690)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17708)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (OOC_CHAR8*)"}", 2);
      return;
      ;
    }


  i0 = (OOC_INT32)declWriter;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17780))+8);
  w = (IO_TextRider__Writer)i0;
  i1 = (OOC_INT32)ADT_ArrayList__New(16);
  tdNames = (ADT_ArrayList__ArrayList)i1;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17834)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17850)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (OOC_CHAR8*)"/* run-time meta data */", 25);
  i1 = writeHeader;
  i1 = !i1;
  if (!i1) goto l3;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17926)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 17944)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (OOC_CHAR8*)"static RT0__ModuleDesc _mid;", 29);
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
  OOC_C_RuntimeData__Write_ModuleOpen((OOC_SymbolTable__Module)i0);
  i0 = (OOC_INT32)symTab;
  OOC_C_RuntimeData__Write_ModuleClose((OOC_SymbolTable__Module)i0);
l6:
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 18234)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
  return;
  ;
}

void OOC_OOC_C_RuntimeData_init(void) {
  _c0 = Object__NewLatin1Char(46u);
  _c1 = Object__NewLatin1Char(40u);
  _c2 = Object__NewLatin1Char(44u);
  _c3 = Object__NewLatin1Char(41u);
  _c4 = Object__NewLatin1Region((OOC_CHAR8*)"  }", 4, 0, 3);

  return;
  ;
}

void OOC_OOC_C_RuntimeData_destroy(void) {
}

/* --- */
