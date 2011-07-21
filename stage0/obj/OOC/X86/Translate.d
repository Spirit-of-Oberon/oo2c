static void* _c0;
static void* _c1;
static void* _c2;
static void* _c3;
static void* _c4;
static void* _c5;
static void* _c6;
static void* _c7;
static void* _c8;
static void* _c9;
static void* _c10;
#include <OOC/X86/Translate.oh>
#include <Object/Boxed.oh>
#include <ADT/ArrayList.oh>
#include <OOC/SymbolTable/Predef.oh>
#include <OOC/SymbolTable/TypeRules.oh>
#include <OOC/X86/SSA.oh>
#include <OOC/X86/Machine.oh>
#include <OOC/X86/Block.oh>
#include <OOC/X86/Register.oh>
#include <OOC/X86/Write.oh>
#include <OOC/X86/Destore.oh>
#include <OOC/X86/ConstProp.oh>
#include <OOC/X86/Algebraic.oh>
#include <OOC/X86/Debug.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_X86_Translate__9498 = { (RT0__Struct[]){&_td_OOC_X86_SSA__Result}, NULL, NULL, &_mid, NULL, 4, 1, 0, RT0__strOpenArray };
RT0__StructDesc _td_OOC_X86_Translate__9487 = { (RT0__Struct[]){&_td_OOC_X86_Translate__9498}, NULL, NULL, &_mid, NULL, 4, -1, 0, RT0__strPointer };
static RT0__StructDesc _td__qtd0 = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_ADT_Storable__ObjectDesc,&_td__qtd0}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)ADT_ArrayList__ArrayListDesc_Equals,(void*)ADT_ArrayList__ArrayListDesc_HashCode,(void*)ADT_ArrayList__ArrayListDesc_Store,(void*)ADT_ArrayList__ArrayListDesc_Load,(void*)ADT_ArrayList__ArrayListDesc_CreateArray,(void*)ADT_ArrayList__ArrayListDesc_INIT,(void*)ADT_ArrayList__ArrayListDesc_Destroy,(void*)ADT_ArrayList__ArrayListDesc_Copy,(void*)ADT_ArrayList__ArrayListDesc_EnsureCapacity,(void*)ADT_ArrayList__ArrayListDesc_Clear,(void*)ADT_ArrayList__ArrayListDesc_Append,(void*)ADT_ArrayList__ArrayListDesc_Insert,(void*)ADT_ArrayList__ArrayListDesc_Get,(void*)ADT_ArrayList__ArrayListDesc_Set,(void*)ADT_ArrayList__ArrayListDesc_RemoveRange,(void*)ADT_ArrayList__ArrayListDesc_Remove,(void*)ADT_ArrayList__ArrayListDesc_TrimToSize,(void*)ADT_ArrayList__ArrayListDesc_Size,(void*)ADT_ArrayList__ArrayListDesc_Contains,(void*)ADT_ArrayList__ArrayListDesc_IndexOf,(void*)ADT_ArrayList__ArrayListDesc_LastIndexOf,(void*)ADT_ArrayList__ArrayListDesc_IsEmpty,(void*)ADT_ArrayList__ArrayListDesc_Sort,(void*)ADT_ArrayList__ArrayListDesc_Elements,(void*)ADT_ArrayList__ArrayListDesc_IterElements}, (RT0__Struct[]){&_td_ADT_ArrayList__ArrayListDesc, &_td_OOC_X86_SSA__InstrDesc, NULL}, &_mid, (OOC_CHAR8*)"ADT:ArrayList.ArrayListDesc(OOC:X86:SSA.Instr)", 8, 3, 0, RT0__strQualType };
static RT0__StructDesc _td__qtd1 = { (RT0__Struct[]){&_td__qtd0}, NULL, (RT0__Struct[]){&_td_ADT_ArrayList__ArrayList, &_td_OOC_X86_SSA__InstrDesc, NULL}, &_mid, (OOC_CHAR8*)"ADT:ArrayList.ArrayList(OOC:X86:SSA.Instr)", 4, 0, 0, RT0__strQualType };
static RT0__StructDesc _td__qtd2 = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_ADT_Storable__ObjectDesc,&_td__qtd2}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)ADT_ArrayList__ArrayListDesc_Equals,(void*)ADT_ArrayList__ArrayListDesc_HashCode,(void*)ADT_ArrayList__ArrayListDesc_Store,(void*)ADT_ArrayList__ArrayListDesc_Load,(void*)ADT_ArrayList__ArrayListDesc_CreateArray,(void*)ADT_ArrayList__ArrayListDesc_INIT,(void*)ADT_ArrayList__ArrayListDesc_Destroy,(void*)ADT_ArrayList__ArrayListDesc_Copy,(void*)ADT_ArrayList__ArrayListDesc_EnsureCapacity,(void*)ADT_ArrayList__ArrayListDesc_Clear,(void*)ADT_ArrayList__ArrayListDesc_Append,(void*)ADT_ArrayList__ArrayListDesc_Insert,(void*)ADT_ArrayList__ArrayListDesc_Get,(void*)ADT_ArrayList__ArrayListDesc_Set,(void*)ADT_ArrayList__ArrayListDesc_RemoveRange,(void*)ADT_ArrayList__ArrayListDesc_Remove,(void*)ADT_ArrayList__ArrayListDesc_TrimToSize,(void*)ADT_ArrayList__ArrayListDesc_Size,(void*)ADT_ArrayList__ArrayListDesc_Contains,(void*)ADT_ArrayList__ArrayListDesc_IndexOf,(void*)ADT_ArrayList__ArrayListDesc_LastIndexOf,(void*)ADT_ArrayList__ArrayListDesc_IsEmpty,(void*)ADT_ArrayList__ArrayListDesc_Sort,(void*)ADT_ArrayList__ArrayListDesc_Elements,(void*)ADT_ArrayList__ArrayListDesc_IterElements}, (RT0__Struct[]){&_td_ADT_ArrayList__ArrayListDesc, &_td_OOC_X86_SSA__BlockDesc, NULL}, &_mid, (OOC_CHAR8*)"ADT:ArrayList.ArrayListDesc(OOC:X86:SSA.Block)", 8, 3, 0, RT0__strQualType };
static RT0__StructDesc _td__qtd3 = { (RT0__Struct[]){&_td__qtd2}, NULL, (RT0__Struct[]){&_td_ADT_ArrayList__ArrayList, &_td_OOC_X86_SSA__BlockDesc, NULL}, &_mid, (OOC_CHAR8*)"ADT:ArrayList.ArrayList(OOC:X86:SSA.Block)", 4, 0, 0, RT0__strQualType };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:X86:Translate", (RT0__Struct[]) { &_td__qtd0, &_td__qtd1, &_td__qtd2, &_td__qtd3, NULL }, 0 };

extern void OOC_OOC_X86_Translate_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_Object_Boxed_open(&_mid);
    OOC_ADT_ArrayList_open(&_mid);
    OOC_IO_open(&_mid);
    OOC_OOC_Repository_open(&_mid);
    OOC_OOC_SymbolTable_open(&_mid);
    OOC_OOC_SymbolTable_Predef_open(&_mid);
    OOC_OOC_SymbolTable_TypeRules_open(&_mid);
    OOC_OOC_IR_open(&_mid);
    OOC_OOC_X86_SSA_open(&_mid);
    OOC_OOC_X86_Machine_open(&_mid);
    OOC_OOC_X86_Block_open(&_mid);
    OOC_OOC_X86_Register_open(&_mid);
    OOC_OOC_X86_Write_open(&_mid);
    OOC_OOC_X86_Destore_open(&_mid);
    OOC_OOC_X86_ConstProp_open(&_mid);
    OOC_OOC_X86_Algebraic_open(&_mid);
    OOC_OOC_X86_Debug_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OOC_X86_Translate_init();
  }
  _mid.openCount++;
}
extern void OOC_OOC_X86_Translate_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OOC_X86_Translate_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_Object_Boxed_close(&_mid);
    OOC_ADT_ArrayList_close(&_mid);
    OOC_IO_close(&_mid);
    OOC_OOC_Repository_close(&_mid);
    OOC_OOC_SymbolTable_close(&_mid);
    OOC_OOC_SymbolTable_Predef_close(&_mid);
    OOC_OOC_SymbolTable_TypeRules_close(&_mid);
    OOC_OOC_IR_close(&_mid);
    OOC_OOC_X86_SSA_close(&_mid);
    OOC_OOC_X86_Machine_close(&_mid);
    OOC_OOC_X86_Block_close(&_mid);
    OOC_OOC_X86_Register_close(&_mid);
    OOC_OOC_X86_Write_close(&_mid);
    OOC_OOC_X86_Destore_close(&_mid);
    OOC_OOC_X86_ConstProp_close(&_mid);
    OOC_OOC_X86_Algebraic_close(&_mid);
    OOC_OOC_X86_Debug_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
