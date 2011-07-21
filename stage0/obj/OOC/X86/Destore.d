#include <OOC/X86/Destore.oh>
#include <ADT/Dictionary.oh>
#include <OOC/SymbolTable.oh>
#include <OOC/X86/Aliasing.oh>
typedef struct OOC_X86_Destore__WorklistDesc *OOC_X86_Destore__Worklist;
typedef struct OOC_X86_Destore__WorklistDesc {
  OOC_X86_Destore__Worklist next;
  OOC_X86_SSA__Instr instr;
} OOC_X86_Destore__WorklistDesc;
#define OOC_X86_Destore__read 0

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_X86_Destore__Worklist = { (RT0__Struct[]){&_td_OOC_X86_Destore__WorklistDesc}, NULL, NULL, &_mid, "Worklist", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_X86_Destore__WorklistDesc = { (RT0__Struct[]){&_td_OOC_X86_Destore__WorklistDesc}, (void*[]){}, NULL, &_mid, "WorklistDesc", 8, 0, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_X86_Destore__MemAccess = { (RT0__Struct[]){&_td_OOC_X86_Destore__MemAccessDesc}, NULL, NULL, &_mid, "MemAccess", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_X86_Destore__MemAccessDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_OOC_X86_Destore__MemAccessDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)OOC_X86_Destore__MemAccessDesc_INIT}, NULL, &_mid, "MemAccessDesc", 12, 2, 0, RT0__strRecord };
static RT0__StructDesc _td__qtd0 = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_ADT_Storable__ObjectDesc,&_td__qtd0}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)ADT_Dictionary__DictionaryDesc_Equals,(void*)ADT_Dictionary__DictionaryDesc_HashCode,(void*)ADT_Dictionary__DictionaryDesc_Store,(void*)ADT_Dictionary__DictionaryDesc_Load,(void*)ADT_Dictionary__DictionaryDesc_INIT,(void*)ADT_Dictionary__DictionaryDesc_Destroy,(void*)ADT_Dictionary__DictionaryDesc_Lookup,(void*)ADT_Dictionary__DictionaryDesc_Insert,(void*)ADT_Dictionary__DictionaryDesc_Resize,(void*)ADT_Dictionary__DictionaryDesc_HasKey,(void*)ADT_Dictionary__DictionaryDesc_Size,(void*)ADT_Dictionary__DictionaryDesc_Get,(void*)ADT_Dictionary__DictionaryDesc_Set,(void*)ADT_Dictionary__DictionaryDesc_Copy,(void*)ADT_Dictionary__DictionaryDesc_Delete,(void*)ADT_Dictionary__DictionaryDesc_Clear,(void*)ADT_Dictionary__DictionaryDesc_Keys,(void*)ADT_Dictionary__DictionaryDesc_Values,(void*)ADT_Dictionary__DictionaryDesc_Items}, (RT0__Struct[]){&_td_ADT_Dictionary__DictionaryDesc, &_td_OOC_X86_SSA__GateInstr, &_td_OOC_X86_Destore__MemAccess, NULL}, &_mid, "ADT:Dictionary.DictionaryDesc(OOC:X86:SSA.GateInstr,OOC:X86:Destore.MemAccess)", 20, 3, 0, RT0__strQualType };
static RT0__StructDesc _td__qtd1 = { (RT0__Struct[]){&_td__qtd0}, NULL, (RT0__Struct[]){&_td_ADT_Dictionary__Dictionary, &_td_OOC_X86_SSA__GateInstr, &_td_OOC_X86_Destore__MemAccess, NULL}, &_mid, "ADT:Dictionary.Dictionary(OOC:X86:SSA.GateInstr,OOC:X86:Destore.MemAccess)", 4, 0, 0, RT0__strQualType };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:X86:Destore", (RT0__Struct[]) { &_td_OOC_X86_Destore__Worklist, &_td_OOC_X86_Destore__WorklistDesc, &_td_OOC_X86_Destore__MemAccess, &_td_OOC_X86_Destore__MemAccessDesc, &_td__qtd0, &_td__qtd1, NULL } };

extern void OOC_OOC_X86_Destore_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_X86_Destore_init();
}

/* --- */
