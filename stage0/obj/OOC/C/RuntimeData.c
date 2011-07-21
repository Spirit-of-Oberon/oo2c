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
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1535)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i0, 32u);
      return;
      ;
    }

    
    void OOC_C_RuntimeData__Write_CNli(void) {
      register OOC_INT32 i0;

      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1726)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, ", ", 3);
      return;
      ;
    }

    
    void OOC_C_RuntimeData__Write_WriteFlags(OOC_SymbolTable__Type type) {
      register OOC_INT32 i0,i1;
      OOC_CHAR8 output;
      auto OOC_SymbolTable__Name OOC_C_RuntimeData__Write_WriteFlags_GetName(const OOC_CHAR8 name__ref[], OOC_LEN name_0d);
      auto OOC_CHAR8 OOC_C_RuntimeData__Write_WriteFlags_ImplementsFinalize(OOC_SymbolTable__Record t);
      auto void OOC_C_RuntimeData__Write_WriteFlags_OutFlag(const OOC_CHAR8 name__ref[], OOC_LEN name_0d);
        
        OOC_SymbolTable__Name OOC_C_RuntimeData__Write_WriteFlags_GetName(const OOC_CHAR8 name__ref[], OOC_LEN name_0d) {
          register OOC_INT32 i0,i1,i2;
          OOC_ALLOCATE_VPAR(name,OOC_CHAR8 ,name_0d)
          OOC_SymbolTable__Name n;
          OOC_Scanner_InputBuffer__CharArray str;

          OOC_INITIALIZE_VPAR(name__ref,name,OOC_CHAR8 ,name_0d)
          i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SymbolTable__Name.baseTypes[0]);
          n = (OOC_SymbolTable__Name)i0;
          i1 = Strings__Length((void*)(OOC_INT32)name, name_0d);
          i1 = (OOC_INT32)RT0__NewObject(_td_OOC_Scanner_InputBuffer__CharArray.baseTypes[0], (i1+1));
          str = (OOC_Scanner_InputBuffer__CharArray)i1;
          i2 = OOC_ARRAY_LENGTH((_check_pointer(i1, 2331)), 0);
          _copy_8((const void*)(OOC_INT32)name,(void*)(_check_pointer(i1, 2331)),i2);
          OOC_SymbolTable__InitName((OOC_SymbolTable__Name)i0, (OOC_Scanner_InputBuffer__CharArray)i1, 0, 1, 0);
          return (OOC_SymbolTable__Name)i0;
          ;
        }

        
        OOC_CHAR8 OOC_C_RuntimeData__Write_WriteFlags_ImplementsFinalize(OOC_SymbolTable__Record t) {
          register OOC_INT32 i0,i1,i2,i3;
          OOC_SymbolTable__Declaration decl;
          OOC_SymbolTable__Type root;
          OOC_SymbolTable__Type impl;

          i0 = (OOC_INT32)t;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2892))+52);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2892))+52);
          i3 = (OOC_INT32)OOC_C_RuntimeData__Write_WriteFlags_GetName("Finalize", 9);
          i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2895)))), OOC_SymbolTable__NamespaceDesc_Identify)),OOC_SymbolTable__NamespaceDesc_Identify)((OOC_SymbolTable__Namespace)i2, (OOC_SymbolTable__Item)i0, (OOC_SymbolTable__Name)i3, 1u);
          decl = (OOC_SymbolTable__Declaration)i1;
          i2 = i1!=(OOC_INT32)0;
          if (i2) goto l3;
          i2=0u;
          goto l5;
l3:
          i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2962)))), &_td_OOC_SymbolTable__ProcDeclDesc);
          
l5:
          if (i2) goto l7;
          return 0u;
          goto l37;
l7:
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3127)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
          root = (OOC_SymbolTable__Type)i0;
          i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3161)))), &_td_OOC_SymbolTable__RecordDesc);
          if (i2) goto l10;
          i2=0u;
          goto l12;
l10:
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3188)))), &_td_OOC_SymbolTable__RecordDesc, 3188)), 3195))+40);
          i2 = i2!=(OOC_INT32)0;
          
l12:
          if (!i2) goto l24;
l15_loop:
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3244)))), &_td_OOC_SymbolTable__RecordDesc, 3244)), 3251))+40);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3244)))), &_td_OOC_SymbolTable__RecordDesc, 3244)), 3251))+40);
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 3260)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
          root = (OOC_SymbolTable__Type)i0;
          i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3161)))), &_td_OOC_SymbolTable__RecordDesc);
          if (i2) goto l18;
          i2=0u;
          goto l20;
l18:
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3188)))), &_td_OOC_SymbolTable__RecordDesc, 3188)), 3195))+40);
          i2 = i2!=(OOC_INT32)0;
          
l20:
          if (i2) goto l15_loop;
l24:
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3383)))), &_td_OOC_SymbolTable__ProcDeclDesc, 3383)), 3392))+64);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 3403))+40);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 3412))+48);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3383)))), &_td_OOC_SymbolTable__ProcDeclDesc, 3383)), 3392))+64);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3403))+40);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3412))+48);
          i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 3417)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i1);
          impl = (OOC_SymbolTable__Type)i1;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3456)))), &_td_OOC_SymbolTable__PointerDesc, 3456)), 3464))+40);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3456)))), &_td_OOC_SymbolTable__PointerDesc, 3456)), 3464))+40);
          i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 3473)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i1);
          impl = (OOC_SymbolTable__Type)i1;
          i1 = i1!=i0;
          if (i1) goto l27;
          i1=0u;
          goto l29;
l27:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3538))+24);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3549))+20);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3554))+12);
          i1 = (
          _cmp8((const void*)(_check_pointer(i1, 3558)),(const void*)"ObjectDesc"))==0;
          
l29:
          if (i1) goto l31;
          i1=0u;
          goto l33;
l31:
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3588))+24);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3599))+4);
          i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3607)))), &_td_OOC_SymbolTable__ModuleDesc);
          
l33:
          if (i1) goto l35;
          i0=0u;
          goto l36;
l35:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3641))+24);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3652))+4);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3664)))), &_td_OOC_SymbolTable__ModuleDesc, 3664)), 3671))+20);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3676))+12);
          i0 = (
          _cmp8((const void*)(_check_pointer(i0, 3680)),(const void*)"RT0"))==0;
          
l36:
          return i0;
l37:
          _failed_function(2430); return 0;
          ;
        }

        
        void OOC_C_RuntimeData__Write_WriteFlags_OutFlag(const OOC_CHAR8 name__ref[], OOC_LEN name_0d) {
          register OOC_INT32 i0;
          OOC_ALLOCATE_VPAR(name,OOC_CHAR8 ,name_0d)

          OOC_INITIALIZE_VPAR(name__ref,name,OOC_CHAR8 ,name_0d)
          i0 = output;
          if (!i0) goto l4;
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3867)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "|", 2);
l4:
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3908)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "(1<<", 5);
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3939)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (void*)(OOC_INT32)name, name_0d);
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3968)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, ")", 2);
          output = 1u;
          return;
          ;
        }


      output = 0u;
      i0 = (OOC_INT32)type;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l22;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4109)))), &_td_OOC_SymbolTable__RecordDesc);
      if (i1) goto l11;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4424)))), &_td_OOC_SymbolTable__ArrayDesc);
      if (!i1) goto l22;
      i0 = *(OOC_UINT8*)((_check_pointer(i0, 4456))+60);
      if (!i0) goto l22;
      OOC_C_RuntimeData__Write_WriteFlags_OutFlag("RT0__flagAtomic", 16);
      goto l22;
l11:
      i0 = *(OOC_UINT8*)((_check_pointer(i0, 4142))+60);
      if (!i0) goto l14;
      OOC_C_RuntimeData__Write_WriteFlags_OutFlag("RT0__flagVTable", 16);
l14:
      i0 = (OOC_INT32)type;
      i0 = *(OOC_UINT8*)((_check_pointer(i0, 4234))+61);
      if (!i0) goto l17;
      OOC_C_RuntimeData__Write_WriteFlags_OutFlag("RT0__flagAtomic", 16);
l17:
      i0 = (OOC_INT32)type;
      i0 = OOC_C_RuntimeData__Write_WriteFlags_ImplementsFinalize((OOC_SymbolTable__Record)i0);
      if (!i0) goto l22;
      OOC_C_RuntimeData__Write_WriteFlags_OutFlag("RT0__flagFinalize", 18);
l22:
      i0 = output;
      i0 = !i0;
      if (!i0) goto l25;
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4594)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "0", 2);
l25:
      return;
      ;
    }

    
    void OOC_C_RuntimeData__Write_WriteForm(const OOC_CHAR8 form__ref[], OOC_LEN form_0d) {
      register OOC_INT32 i0;
      OOC_ALLOCATE_VPAR(form,OOC_CHAR8 ,form_0d)

      OOC_INITIALIZE_VPAR(form__ref,form,OOC_CHAR8 ,form_0d)
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4708)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "RT0__", 6);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4758)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (void*)(OOC_INT32)form, form_0d);
      return;
      ;
    }

    
    void OOC_C_RuntimeData__Write_WriteDescrVariable(OOC_SymbolTable__Type type) {
      register OOC_INT32 i0,i1,i2;
      Object__String name;

      i0 = (OOC_INT32)type;
      i1 = (OOC_INT32)qtdData;
      i1 = (OOC_INT32)OOC_C_Naming__NameOfTypeDescriptor((OOC_SymbolTable__Type)i0, (OOC_C_Naming__QualTypeData)i1);
      name = (Object__String)i1;
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 4962)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i2);
      i2 = writeHeader;
      if (i2) goto l10;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5052))+24);
      i2 = i2!=(OOC_INT32)0;
      if (i2) goto l5;
      i0=0u;
      goto l7;
l5:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5091))+24);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5103))+4);
      i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5112)))), &_td_OOC_SymbolTable__ModuleDesc);
      
l7:
      if (!i0) goto l11;
      i0 = (OOC_INT32)tdNames;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5147)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i0, (Object__Object)i1);
      goto l11;
l10:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5008)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "extern ", 8);
l11:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5181)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "RT0__StructDesc", 16);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5220)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, " ", 2);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5248)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i0, (Object__Object)i1);
      i0 = writeHeader;
      if (i0) goto l14;
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5346)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, " = {", 5);
      OOC_C_RuntimeData__Write_Nli();
      goto l15;
l14:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5305)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, ";", 2);
l15:
      return;
      ;
    }

    
    void OOC_C_RuntimeData__Write_WriteName(OOC_SymbolTable__Type type) {
      register OOC_INT32 i0,i1,i2;

      OOC_C_RuntimeData__Write_CNli();
      i0 = (OOC_INT32)type;
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5499))+24);
      i1 = i1==(OOC_INT32)0;
      if (i1) goto l3;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5577)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i1, 34u);
      i1 = (OOC_INT32)w;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5624))+24);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 5636))+20);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 5642))+12);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5624))+24);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5636))+20);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5642))+12);
      i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 5647)), 0);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5605)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, (void*)(_check_pointer(i2, 5647)), i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5660)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i0, 34u);
      goto l4;
l3:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5533)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "NULL", 5);
l4:
      return;
      ;
    }

    
    void OOC_C_RuntimeData__Write_WriteTDRef(OOC_SymbolTable__Type type) {
      register OOC_INT32 i0,i1;
      Object__String name;

      i0 = (OOC_INT32)type;
      i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5806)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
      type = (OOC_SymbolTable__Type)i0;
      i1 = *(OOC_UINT8*)((_check_pointer(i0, 5831))+38);
      if (i1) goto l3;
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 5988)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "NULL", 5);
      goto l4;
l3:
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5860)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, "&", 2);
      i1 = (OOC_INT32)qtdData;
      i0 = (OOC_INT32)OOC_C_Naming__NameOfTypeDescriptor((OOC_SymbolTable__Type)i0, (OOC_C_Naming__QualTypeData)i1);
      name = (Object__String)i0;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5948)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i1, (Object__Object)i0);
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
      i1 = *(OOC_UINT8*)((_check_pointer(i0, 6208))+40);
      if (i1) goto l5;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6914)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, "(RT0__Struct[]){", 17);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6992))+44);
      OOC_C_RuntimeData__Write_WriteTDRef((OOC_SymbolTable__Type)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7018)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i1, 125u);
      OOC_C_RuntimeData__Write_CNli();
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7054)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, "NULL", 5);
      OOC_C_RuntimeData__Write_CNli();
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7109)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, "NULL", 5);
      OOC_C_RuntimeData__Write_CNli();
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7165)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, "&_mid", 6);
      OOC_C_RuntimeData__Write_WriteName((OOC_SymbolTable__Type)i0);
      OOC_C_RuntimeData__Write_CNli();
      i1 = (OOC_INT32)w;
      i2 = *(OOC_INT32*)((_check_pointer(i0, 7289))+32);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7272)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i1, i2, 0);
      OOC_C_RuntimeData__Write_CNli();
      i1 = (OOC_INT32)w;
      i2 = *(OOC_INT32*)((_check_pointer(i0, 7347))+52);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7329)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i1, i2, 0);
      OOC_C_RuntimeData__Write_CNli();
      OOC_C_RuntimeData__Write_WriteFlags((OOC_SymbolTable__Type)i0);
      OOC_C_RuntimeData__Write_CNli();
      OOC_C_RuntimeData__Write_WriteForm("strArray", 9);
      goto l6;
l5:
      i1 = (OOC_INT32)OOC_SymbolTable__ArrayDesc_GetNonOpenElementType((OOC_SymbolTable__Array)i0);
      base = (OOC_SymbolTable__Type)i1;
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 6288)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, "(RT0__Struct[]){", 17);
      OOC_C_RuntimeData__Write_WriteTDRef((OOC_SymbolTable__Type)i1);
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 6379)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i2, 125u);
      OOC_C_RuntimeData__Write_CNli();
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 6415)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, "NULL", 5);
      OOC_C_RuntimeData__Write_CNli();
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 6470)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, "NULL", 5);
      OOC_C_RuntimeData__Write_CNli();
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 6526)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, "&_mid", 6);
      OOC_C_RuntimeData__Write_WriteName((OOC_SymbolTable__Type)i0);
      i2 = *(OOC_INT32*)((_check_pointer(i1, 6637))+32);
      _assert((i2>=0), 127, 6626);
      OOC_C_RuntimeData__Write_CNli();
      i2 = (OOC_INT32)w;
      i1 = *(OOC_INT32*)((_check_pointer(i1, 6684))+32);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 6667)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i2, i1, 0);
      OOC_C_RuntimeData__Write_CNli();
      i1 = (OOC_INT32)w;
      i2 = OOC_SymbolTable__ArrayDesc_GetOpenDimensions((OOC_SymbolTable__Array)i0);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6724)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i1, i2, 0);
      OOC_C_RuntimeData__Write_CNli();
      OOC_C_RuntimeData__Write_WriteFlags((OOC_SymbolTable__Type)i0);
      OOC_C_RuntimeData__Write_CNli();
      OOC_C_RuntimeData__Write_WriteForm("strOpenArray", 13);
l6:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7498)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, " };", 4);
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
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 7777)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i3, 44u);
l6:
      i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 7831))+52);
      i3 = (OOC_INT32)OOC_SymbolTable_Namespace__ExtendedDesc_GetTBProcByIndex((OOC_SymbolTable_Namespace__Extended)(_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 7846)))), &_td_OOC_SymbolTable_Namespace__ExtendedDesc, 7846)), i2);
      proc = (OOC_SymbolTable__ProcDecl)i3;
      _assert((i3!=(OOC_INT32)0), 127, 7887);
      i4 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 7917)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i4, "(void*)", 8);
      i3 = (OOC_INT32)OOC_C_Naming__NameOfDeclaration((OOC_SymbolTable__Declaration)i3);
      name = (Object__String)i3;
      i4 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 8002)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i4, (Object__Object)i3);
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
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8324)))), OOC_SymbolTable__TypeDesc_Deparam)),OOC_SymbolTable__TypeDesc_Deparam)((OOC_SymbolTable__Type)i0);
          t = (OOC_SymbolTable__Type)i0;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8370)))), &_td_OOC_SymbolTable__RecordDesc, 8370)), 8377))+40);
          i1 = OOC_C_RuntimeData__Write_RecordTypeDescr_BaseTypes((OOC_SymbolTable__Type)i1);
          len = i1;
          i2 = (OOC_INT32)qtdData;
          i2 = (OOC_INT32)OOC_C_Naming__NameOfTypeDescriptor((OOC_SymbolTable__Type)i0, (OOC_C_Naming__QualTypeData)i2);
          name = (Object__String)i2;
          i3 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 8461)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i3, 38u);
          i3 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 8491)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i3, (Object__Object)i2);
          i2 = (OOC_INT32)record;
          i0 = i0!=i2;
          if (!i0) goto l5;
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8556)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i0, 44u);
l5:
          return (i1+1);
          goto l7;
l6:
          return (-1);
l7:
          _failed_function(8148); return 0;
          ;
        }


      i0 = (OOC_INT32)record;
      OOC_C_RuntimeData__Write_WriteDescrVariable((OOC_SymbolTable__Type)i0);
      i1 = writeHeader;
      i1 = !i1;
      if (!i1) goto l4;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8730)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, "(RT0__Struct[]){", 17);
      i0 = OOC_C_RuntimeData__Write_RecordTypeDescr_BaseTypes((OOC_SymbolTable__Type)i0);
      len = i0;
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8826)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i1, 125u);
      OOC_C_RuntimeData__Write_CNli();
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8860)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, "(void*[]){", 11);
      i1 = (OOC_INT32)record;
      i2 = *(OOC_INT32*)((_check_pointer(i1, 8936))+48);
      OOC_C_RuntimeData__Write_TBProcs((OOC_SymbolTable__Record)i1, i2);
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 8960)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i2, 125u);
      OOC_C_RuntimeData__Write_CNli();
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 8994)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, "NULL", 5);
      OOC_C_RuntimeData__Write_CNli();
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 9050)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, "&_mid", 6);
      OOC_C_RuntimeData__Write_WriteName((OOC_SymbolTable__Type)i1);
      OOC_C_RuntimeData__Write_CNli();
      i2 = (OOC_INT32)w;
      i3 = *(OOC_INT32*)((_check_pointer(i1, 9175))+32);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 9156)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i2, i3, 0);
      OOC_C_RuntimeData__Write_CNli();
      i2 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 9213)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i2, i0, 0);
      OOC_C_RuntimeData__Write_CNli();
      OOC_C_RuntimeData__Write_WriteFlags((OOC_SymbolTable__Type)i1);
      OOC_C_RuntimeData__Write_CNli();
      OOC_C_RuntimeData__Write_WriteForm("strRecord", 10);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9364)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, " };", 4);
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
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9561)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, "(RT0__Struct[]){", 17);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 9639))+40);
      OOC_C_RuntimeData__Write_WriteTDRef((OOC_SymbolTable__Type)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9660)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i1, 125u);
      OOC_C_RuntimeData__Write_CNli();
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9694)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, "NULL", 5);
      OOC_C_RuntimeData__Write_CNli();
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9749)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, "NULL", 5);
      OOC_C_RuntimeData__Write_CNli();
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9805)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, "&_mid", 6);
      OOC_C_RuntimeData__Write_WriteName((OOC_SymbolTable__Type)i0);
      OOC_C_RuntimeData__Write_CNli();
      i1 = (OOC_INT32)w;
      i2 = *(OOC_INT32*)((_check_pointer(i0, 9931))+32);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9911)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i1, i2, 0);
      OOC_C_RuntimeData__Write_CNli();
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9969)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i1, (-1), 0);
      OOC_C_RuntimeData__Write_CNli();
      OOC_C_RuntimeData__Write_WriteFlags((OOC_SymbolTable__Type)i0);
      OOC_C_RuntimeData__Write_CNli();
      OOC_C_RuntimeData__Write_WriteForm("strPointer", 11);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10119)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, " };", 4);
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
          i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10391)))), &_td_OOC_SymbolTable__VarDeclDesc);
          if (i2) goto l6;
          i2=0u;
          goto l7;
l6:
          i2 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10418)))), &_td_OOC_SymbolTable__VarDeclDesc, 10418)), 10426))+56);
          
l7:
          i2 = !i2;
          
l9:
          if (!i2) goto l25;
l12_loop:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10466))+4);
          item = (OOC_SymbolTable__Item)i0;
          i2 = i0!=i1;
          if (i2) goto l15;
          i2=0u;
          goto l21;
l15:
          i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10391)))), &_td_OOC_SymbolTable__VarDeclDesc);
          if (i2) goto l18;
          i2=0u;
          goto l19;
l18:
          i2 = *(OOC_UINT8*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10418)))), &_td_OOC_SymbolTable__VarDeclDesc, 10418)), 10426))+56);
          
l19:
          i2 = !i2;
          
l21:
          if (i2) goto l12_loop;
l25:
          return (i0!=i1);
          ;
        }


      i0 = (OOC_INT32)item;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10568)))), &_td_OOC_SymbolTable__ArrayDesc);
      if (i1) goto l20;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10699)))), &_td_OOC_SymbolTable__RecordDesc);
      if (i1) goto l15;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10818)))), &_td_OOC_SymbolTable__PointerDesc);
      if (i1) goto l10;
      i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10939)))), &_td_OOC_SymbolTable__ProcDeclDesc);
      if (!i1) goto l28;
      proc = (OOC_SymbolTable__ProcDecl)i0;
      goto l28;
l10:
      i1 = *(OOC_UINT8*)((_check_pointer(i0, 10850))+38);
      if (!i1) goto l28;
      OOC_C_RuntimeData__Write_PointerTypeDescr((OOC_SymbolTable__Pointer)i0);
      goto l28;
l15:
      i1 = *(OOC_UINT8*)((_check_pointer(i0, 10730))+38);
      if (!i1) goto l28;
      OOC_C_RuntimeData__Write_RecordTypeDescr((OOC_SymbolTable__Record)i0);
      goto l28;
l20:
      i1 = *(OOC_UINT8*)((_check_pointer(i0, 10598))+38);
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
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11123))+8);
      nested = (OOC_SymbolTable__Item)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l36;
      i1 = (OOC_INT32)proc;
      
l31_loop:
      OOC_C_RuntimeData__Write_Traverse((OOC_SymbolTable__Item)i0, (OOC_SymbolTable__ProcDecl)i1);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 11225));
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
          i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11576)))), &_td_OOC_SymbolTable__TypeClosureDesc);
          if (i2) goto l3;
          i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11925)))), OOC_SymbolTable__ItemDesc_Module)),OOC_SymbolTable__ItemDesc_Module)((OOC_SymbolTable__Item)i1);
          module = (OOC_SymbolTable__Module)i2;
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 11968))+20);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 11973))+12);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 11968))+20);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 11973))+12);
          i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 11977)), 0);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11948)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i0, (void*)(_check_pointer(i3, 11977)), i2);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11993)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c0));
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12034))+24);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 12045))+20);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 12050))+12);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12034))+24);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12045))+20);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12050))+12);
          i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 12054)), 0);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12019)))), ADT_StringBuffer__StringBufferDesc_AppendLatin1)),ADT_StringBuffer__StringBufferDesc_AppendLatin1)((ADT_StringBuffer__StringBuffer)i0, (void*)(_check_pointer(i2, 12054)), i1);
          goto l15;
l3:
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11631))+40);
          i2 = (OOC_INT32)OOC_C_RuntimeData__Write_QualTypeDescr_QualTypeName((OOC_SymbolTable__Type)i2);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11609)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i2);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11656)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c1));
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11699))+48);
          i = 0;
          i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 11709)), 0);
          i3 = 0<i2;
          if (!i3) goto l14;
          i3 = (OOC_INT32)_c2;
          i4=0;
l6_loop:
          i5 = i4!=0;
          if (!i5) goto l9;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11761)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i3);
l9:
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11828))+48);
          i5 = _check_pointer(i5, 11838);
          i6 = OOC_ARRAY_LENGTH(i5, 0);
          i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 11838))*8);
          i5 = (OOC_INT32)OOC_C_RuntimeData__Write_QualTypeDescr_QualTypeName((OOC_SymbolTable__Type)i5);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11806)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)i5);
          i4 = i4+1;
          i = i4;
          i5 = i4<i2;
          if (i5) goto l6_loop;
l14:
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 11877)))), ADT_StringBuffer__StringBufferDesc_Append)),ADT_StringBuffer__StringBufferDesc_Append)((ADT_StringBuffer__StringBuffer)i0, (Object__Object)((OOC_INT32)_c3));
l15:
          i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12088)))), ADT_StringBuffer__StringBufferDesc_ToString)),ADT_StringBuffer__StringBufferDesc_ToString)((ADT_StringBuffer__StringBuffer)i0);
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
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 12451)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i4, 38u);
          i4 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 12481)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i4, (Object__Object)i3);
          i0 = i0!=i2;
          if (!i0) goto l5;
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12546)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i0, 44u);
l5:
          return (i1+1);
          goto l7;
l6:
          return (-1);
l7:
          _failed_function(12144); return 0;
          ;
        }

        
        void OOC_C_RuntimeData__Write_QualTypeDescr_WriteQualTypeDescr(OOC_C_Naming__QualTypeDescr qtd) {
          register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
          OOC_INT32 len;
          OOC_SymbolTable__Record record;
          Object__String name;
          OOC_INT32 i;

          i0 = (OOC_INT32)tdNames;
          i1 = (OOC_INT32)qtd;
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 12823));
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12812)))), ADT_ArrayList__ArrayListDesc_Append)),ADT_ArrayList__ArrayListDesc_Append)((ADT_ArrayList__ArrayList)i0, (Object__Object)i2);
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12886)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12905)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "static ", 8);
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12939)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "RT0__StructDesc", 16);
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12978)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, " ", 2);
          i0 = (OOC_INT32)w;
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 13022));
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13006)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i0, (Object__Object)i2);
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13039)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, " = {", 5);
          OOC_C_RuntimeData__Write_Nli();
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 13090))+4);
          i0 = (OOC_INT32)OOC_SymbolTable__TypeClosureDesc_Deparam((OOC_SymbolTable__TypeClosure)i0);
          i0 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13106)))), &_td_OOC_SymbolTable__RecordDesc);
          if (i0) goto l3;
          len = 0;
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13534)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "(RT0__Struct[]){", 17);
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13597)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "&", 2);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 13684))+4);
          i0 = (OOC_INT32)OOC_SymbolTable_TypeRules__PointerBaseType((OOC_SymbolTable__Type)i0);
          i2 = (OOC_INT32)qtdData;
          i0 = (OOC_INT32)OOC_C_Naming__NameOfTypeDescriptor((OOC_SymbolTable__Type)i0, (OOC_C_Naming__QualTypeData)i2);
          name = (Object__String)i0;
          i2 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 13759)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i2, (Object__Object)i0);
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13790)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i0, 125u);
          OOC_C_RuntimeData__Write_CNli();
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13826)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "NULL", 5);
          record = (OOC_SymbolTable__Record)0;
          i0=0;i2=0;
          goto l4;
l3:
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13137)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "(RT0__Struct[]){", 17);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 13220))+4);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 13230))+4);
          i0 = OOC_C_RuntimeData__Write_QualTypeDescr_BaseTypes((OOC_SymbolTable__Type)i0, (OOC_SymbolTable__Type)i2);
          len = i0;
          i2 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 13249)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i2, 125u);
          OOC_C_RuntimeData__Write_CNli();
          i2 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 13296)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i2, "(void*[]){", 11);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 13363))+4);
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 13368))+40);
          i2 = _type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 13382)))), &_td_OOC_SymbolTable__RecordDesc, 13382);
          record = (OOC_SymbolTable__Record)i2;
          i3 = *(OOC_INT32*)((_check_pointer(i2, 13423))+48);
          OOC_C_RuntimeData__Write_TBProcs((OOC_SymbolTable__Record)i2, i3);
          i3 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 13449)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i3, 125u);
          
l4:
          OOC_C_RuntimeData__Write_CNli();
          i3 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 13926)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i3, "(RT0__Struct[]){", 17);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 13997))+4);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 14002))+40);
          OOC_C_RuntimeData__Write_WriteTDRef((OOC_SymbolTable__Type)i3);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14043))+4);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 14048))+48);
          i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 14058)), 0);
          i = 0;
          i4 = 0<i3;
          if (!i4) goto l12;
          i4=0;
l7_loop:
          OOC_C_RuntimeData__Write_CNli();
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14106))+4);
          i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i5, 14111))+48);
          i5 = _check_pointer(i5, 14121);
          i6 = OOC_ARRAY_LENGTH(i5, 0);
          i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i4, i6, OOC_UINT32, 14121))*8);
          OOC_C_RuntimeData__Write_WriteTDRef((OOC_SymbolTable__Type)i5);
          i4 = i4+1;
          i = i4;
          i5 = i4<i3;
          if (i5) goto l7_loop;
l12:
          i3 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 14154)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i3, ", NULL}", 8);
          OOC_C_RuntimeData__Write_CNli();
          i3 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 14203)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i3, "&_mid", 6);
          OOC_C_RuntimeData__Write_CNli();
          i3 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 14266)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i3, 34u);
          i3 = (OOC_INT32)w;
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14341))+4);
          i4 = (OOC_INT32)OOC_C_RuntimeData__Write_QualTypeDescr_QualTypeName((OOC_SymbolTable__Type)i4);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 14312)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i3, (Object__Object)i4);
          i3 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 14359)))), IO_TextRider__WriterDesc_WriteChar)),IO_TextRider__WriterDesc_WriteChar)((IO_TextRider__Writer)i3, 34u);
          OOC_C_RuntimeData__Write_CNli();
          i3 = (OOC_INT32)w;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 14414))+4);
          i1 = *(OOC_INT32*)((_check_pointer(i1, 14419))+32);
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 14400)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i3, i1, 0);
          OOC_C_RuntimeData__Write_CNli();
          i1 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14456)))), IO_TextRider__WriterDesc_WriteLInt)),IO_TextRider__WriterDesc_WriteLInt)((IO_TextRider__Writer)i1, i0, 0);
          OOC_C_RuntimeData__Write_CNli();
          OOC_C_RuntimeData__Write_WriteFlags((OOC_SymbolTable__Type)i2);
          OOC_C_RuntimeData__Write_CNli();
          OOC_C_RuntimeData__Write_WriteForm("strQualType", 12);
          i0 = (OOC_INT32)w;
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14607)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, " };", 4);
          return;
          ;
        }


      i0 = (OOC_INT32)qtdData;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14700));
      i = 0;
      i0 = *(OOC_INT32*)((_check_pointer(i0, 14705))+4);
      i1 = 0<i0;
      if (!i1) goto l8;
      i1=0;
l3_loop:
      i2 = (OOC_INT32)qtdData;
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 14750));
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 14755));
      i2 = _check_pointer(i2, 14761);
      i3 = OOC_ARRAY_LENGTH(i2, 0);
      i1 = (OOC_INT32)*(OOC_INT32*)(i2+(_check_index(i1, i3, OOC_UINT32, 14761))*4);
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
      register OOC_INT32 i0,i1,i2,i3,i4,i5;
      OOC_INT32 i;

      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14923)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14941)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "static RT0__ModuleDesc _mid = {", 32);
      OOC_C_RuntimeData__Write_Nli();
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15010)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "(OOC_CHAR8*)\"", 14);
      i0 = (OOC_INT32)w;
      i1 = (OOC_INT32)module;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15071))+20);
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 15077))+12);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15071))+20);
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 15077))+12);
      i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 15082)), 0);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15050)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, (void*)(_check_pointer(i2, 15082)), i1);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15093)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "\"", 2);
      OOC_C_RuntimeData__Write_CNli();
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15133)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "(RT0__Struct[]) {", 18);
      OOC_C_RuntimeData__Write_Nli();
      i0 = (OOC_INT32)tdNames;
      i = 0;
      i1 = *(OOC_INT32*)((_check_pointer(i0, 15208))+4);
      i2 = 0<i1;
      if (!i2) goto l8;
      i2=0;
l3_loop:
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 15229)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i3, "&", 2);
      i3 = (OOC_INT32)w;
      i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 15281));
      i4 = _check_pointer(i4, 15288);
      i5 = OOC_ARRAY_LENGTH(i4, 0);
      i4 = (OOC_INT32)*(OOC_INT32*)(i4+(_check_index(i2, i5, OOC_UINT32, 15288))*4);
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 15259)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i3, (Object__Object)(_type_guard(i4, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 15292)))), &_td_Object__StringDesc, 15292)));
      OOC_C_RuntimeData__Write_CNli();
      i2 = i2+1;
      i = i2;
      i3 = i2<i1;
      if (i3) goto l3_loop;
l8:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15334)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "NULL } };", 10);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15370)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
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
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 15610)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i3);
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 15628)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i3, "extern void ", 13);
      i3 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 15667)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i3, (Object__Object)i1);
      i1 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15697)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i1, "() {", 5);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15737))+20);
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15743))+12);
      i0 = (
      _cmp8((const void*)(_check_pointer(i0, 15748)),(const void*)"RT0"))!=0;
      if (!i0) goto l3;
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15863)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15883)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "  RT0__RegisterModule(&_mid);", 30);
l3:
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15950)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15968)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "  ", 3);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15997)))), IO_TextRider__WriterDesc_WriteObject)),IO_TextRider__WriterDesc_WriteObject)((IO_TextRider__Writer)i0, (Object__Object)i2);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16026)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "();", 4);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16056)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
      i0 = (OOC_INT32)w;
      OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16074)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "}", 2);
      return;
      ;
    }


  i0 = (OOC_INT32)declWriter;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16145))+8);
  w = (IO_TextRider__Writer)i0;
  i1 = (OOC_INT32)ADT_ArrayList__New(16);
  tdNames = (ADT_ArrayList__ArrayList)i1;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16199)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16215)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "/* run-time meta data */", 25);
  i1 = writeHeader;
  i1 = !i1;
  if (!i1) goto l3;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16291)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16309)))), IO_TextRider__WriterDesc_WriteString)),IO_TextRider__WriterDesc_WriteString)((IO_TextRider__Writer)i0, "static RT0__ModuleDesc _mid;", 29);
l3:
  i0 = (OOC_INT32)symTab;
  OOC_C_RuntimeData__Write_Traverse((OOC_SymbolTable__Item)i0, (OOC_SymbolTable__ProcDecl)(OOC_INT32)0);
  i0 = writeHeader;
  i0 = !i0;
  if (!i0) goto l6;
  i0 = (OOC_INT32)qtdData;
  OOC_C_RuntimeData__Write_QualTypeDescr((OOC_C_Naming__QualTypeData)i0);
  i0 = (OOC_INT32)symTab;
  i1 = (OOC_INT32)tdNames;
  OOC_C_RuntimeData__Write_ModuleDescr((OOC_SymbolTable__Module)i0, (ADT_ArrayList__ArrayList)i1);
  i0 = (OOC_INT32)symTab;
  OOC_C_RuntimeData__Write_ModuleInit((OOC_SymbolTable__Module)i0);
l6:
  i0 = (OOC_INT32)w;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 16571)))), IO_TextRider__WriterDesc_WriteLn)),IO_TextRider__WriterDesc_WriteLn)((IO_TextRider__Writer)i0);
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
