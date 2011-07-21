static void* _c0;
static void* _c1;
static void* _c2;
static void* _c3;
static void* _c4;
static void* _c5;
static void* _c6;
static void* _c7;
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
RT0__StructDesc _td_OOC_X86_Translate__8708 = { (RT0__Struct[]){&_td_OOC_X86_SSA__Result}, NULL, NULL, &_mid, NULL, 4, 1, 0, RT0__strOpenArray };
RT0__StructDesc _td_OOC_X86_Translate__8697 = { (RT0__Struct[]){&_td_OOC_X86_Translate__8708}, NULL, NULL, &_mid, NULL, 4, -1, 0, RT0__strPointer };
static RT0__StructDesc _td__qtd0 = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_ADT_Storable__ObjectDesc,&_td__qtd0}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)ADT_ArrayList__ArrayListDesc_Equals,(void*)ADT_ArrayList__ArrayListDesc_HashCode,(void*)ADT_ArrayList__ArrayListDesc_Store,(void*)ADT_ArrayList__ArrayListDesc_Load,(void*)ADT_ArrayList__ArrayListDesc_CreateArray,(void*)ADT_ArrayList__ArrayListDesc_INIT,(void*)ADT_ArrayList__ArrayListDesc_Destroy,(void*)ADT_ArrayList__ArrayListDesc_Copy,(void*)ADT_ArrayList__ArrayListDesc_EnsureCapacity,(void*)ADT_ArrayList__ArrayListDesc_Clear,(void*)ADT_ArrayList__ArrayListDesc_Append,(void*)ADT_ArrayList__ArrayListDesc_Insert,(void*)ADT_ArrayList__ArrayListDesc_Get,(void*)ADT_ArrayList__ArrayListDesc_Set,(void*)ADT_ArrayList__ArrayListDesc_RemoveRange,(void*)ADT_ArrayList__ArrayListDesc_Remove,(void*)ADT_ArrayList__ArrayListDesc_TrimToSize,(void*)ADT_ArrayList__ArrayListDesc_Size,(void*)ADT_ArrayList__ArrayListDesc_Contains,(void*)ADT_ArrayList__ArrayListDesc_IndexOf,(void*)ADT_ArrayList__ArrayListDesc_LastIndexOf,(void*)ADT_ArrayList__ArrayListDesc_IsEmpty,(void*)ADT_ArrayList__ArrayListDesc_Sort,(void*)ADT_ArrayList__ArrayListDesc_Elements}, (RT0__Struct[]){&_td_ADT_ArrayList__ArrayListDesc, &_td_OOC_X86_SSA__Instr, NULL}, &_mid, "ADT:ArrayList.ArrayListDesc(OOC:X86:SSA.Instr)", 8, 3, 0, RT0__strQualType };
static RT0__StructDesc _td__qtd1 = { (RT0__Struct[]){&_td__qtd0}, NULL, (RT0__Struct[]){&_td_ADT_ArrayList__ArrayList, &_td_OOC_X86_SSA__Instr, NULL}, &_mid, "ADT:ArrayList.ArrayList(OOC:X86:SSA.Instr)", 4, 0, 0, RT0__strQualType };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:X86:Translate", (RT0__Struct[]) { &_td__qtd0, &_td__qtd1, NULL } };

extern void OOC_OOC_X86_Translate_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_X86_Translate_init();
}

/* --- */
