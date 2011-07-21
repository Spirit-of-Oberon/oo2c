#include <OOC/X86/Register.oh>
#include <OOC/X86/Machine.oh>
#define OOC_X86_Register__gpRegisters 0
#define OOC_X86_Register__fpRegisters 1
typedef OOC_X86_Register__RegisterFile *OOC_X86_Register__RegisterFiles;
static void OOC_X86_Register__LogLiveData(OOC_X86_Register__RegisterFile rf, OOC_X86_Register__LiveData ld);
static OOC_X86_Register__RegisterFiles OOC_X86_Register__GetRegisterFiles(void);
static OOC_X86_Register__RegisterFiles OOC_X86_Register__IdentifyResults(OOC_X86_SSA__FunctionBlock b);
static OOC_X86_SSA__Instr OOC_X86_Register__SweepLiveSet(OOC_X86_Register__RegisterFile rf, OOC_X86_SSA__Block b, OOC_X86_SSA__Instr instr, OOC_SSA_IGraph__Vector live);
static OOC_INT32 OOC_X86_Register__CoalesceFixedLocations(OOC_X86_Register__RegisterFile rf, OOC_X86_SSA__FunctionBlock b);
static OOC_INT32 OOC_X86_Register__AssignRegisterFile(OOC_X86_Register__RegisterFile rf, OOC_X86_SSA__FunctionBlock b);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_X86_Register__RegisterFile = { (RT0__Struct[]){&_td_OOC_X86_Register__RegisterFileDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"RegisterFile", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_X86_Register__381 = { (RT0__Struct[]){&_td_OOC_X86_Register__RegisterFile}, NULL, NULL, &_mid, NULL, 4, 1, 0, RT0__strOpenArray };
RT0__StructDesc _td_OOC_X86_Register__RegisterFiles = { (RT0__Struct[]){&_td_OOC_X86_Register__381}, NULL, NULL, &_mid, (OOC_CHAR8*)"RegisterFiles", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_X86_Register__RegisterFileDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_OOC_X86_SSA__NodeDesc,&_td_OOC_X86_Register__RegisterFileDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)OOC_X86_Register__RegisterFileDesc_INIT}, NULL, &_mid, (OOC_CHAR8*)"RegisterFileDesc", 92, 3, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_X86_Register__597 = { (RT0__Struct[]){&_td_OOC_X86_SSA__Result}, NULL, NULL, &_mid, NULL, 72, 18, 0, RT0__strArray };
RT0__StructDesc _td_OOC_X86_Register__LiveData = { (RT0__Struct[]){&_td_OOC_X86_Register__LiveDataDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"LiveData", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_X86_Register__LiveDataDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_OOC_X86_Register__LiveDataDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)OOC_X86_Register__LiveDataDesc_INIT}, NULL, &_mid, (OOC_CHAR8*)"LiveDataDesc", 16, 2, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_X86_Register__12042 = { (RT0__Struct[]){&RT0__shortint}, NULL, NULL, &_mid, NULL, 18, 18, (1<<RT0__flagAtomic), RT0__strArray };
static RT0__StructDesc _td__qtd0 = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_ADT_Storable__ObjectDesc,&_td__qtd0}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)ADT_ArrayList__ArrayListDesc_Equals,(void*)ADT_ArrayList__ArrayListDesc_HashCode,(void*)ADT_ArrayList__ArrayListDesc_Store,(void*)ADT_ArrayList__ArrayListDesc_Load,(void*)ADT_ArrayList__ArrayListDesc_CreateArray,(void*)ADT_ArrayList__ArrayListDesc_INIT,(void*)ADT_ArrayList__ArrayListDesc_Destroy,(void*)ADT_ArrayList__ArrayListDesc_Copy,(void*)ADT_ArrayList__ArrayListDesc_EnsureCapacity,(void*)ADT_ArrayList__ArrayListDesc_Clear,(void*)ADT_ArrayList__ArrayListDesc_Append,(void*)ADT_ArrayList__ArrayListDesc_Insert,(void*)ADT_ArrayList__ArrayListDesc_Get,(void*)ADT_ArrayList__ArrayListDesc_Set,(void*)ADT_ArrayList__ArrayListDesc_RemoveRange,(void*)ADT_ArrayList__ArrayListDesc_Remove,(void*)ADT_ArrayList__ArrayListDesc_TrimToSize,(void*)ADT_ArrayList__ArrayListDesc_Size,(void*)ADT_ArrayList__ArrayListDesc_Contains,(void*)ADT_ArrayList__ArrayListDesc_IndexOf,(void*)ADT_ArrayList__ArrayListDesc_LastIndexOf,(void*)ADT_ArrayList__ArrayListDesc_IsEmpty,(void*)ADT_ArrayList__ArrayListDesc_Sort,(void*)ADT_ArrayList__ArrayListDesc_Elements,(void*)ADT_ArrayList__ArrayListDesc_IterElements}, (RT0__Struct[]){&_td_ADT_ArrayList__ArrayListDesc, &_td_OOC_X86_SSA__Result, NULL}, &_mid, (OOC_CHAR8*)"ADT:ArrayList.ArrayListDesc(OOC:X86:SSA.Result)", 8, 3, 0, RT0__strQualType };
static RT0__StructDesc _td__qtd1 = { (RT0__Struct[]){&_td__qtd0}, NULL, (RT0__Struct[]){&_td_ADT_ArrayList__ArrayList, &_td_OOC_X86_SSA__Result, NULL}, &_mid, (OOC_CHAR8*)"ADT:ArrayList.ArrayList(OOC:X86:SSA.Result)", 4, 0, 0, RT0__strQualType };
static RT0__StructDesc _td__qtd2 = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_ADT_Storable__ObjectDesc,&_td__qtd2}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)ADT_Dictionary__DictionaryDesc_Equals,(void*)ADT_Dictionary__DictionaryDesc_HashCode,(void*)ADT_Dictionary__DictionaryDesc_Store,(void*)ADT_Dictionary__DictionaryDesc_Load,(void*)ADT_Dictionary__DictionaryDesc_INIT,(void*)ADT_Dictionary__DictionaryDesc_Destroy,(void*)ADT_Dictionary__DictionaryDesc_InternalLookup,(void*)ADT_Dictionary__DictionaryDesc_Insert,(void*)ADT_Dictionary__DictionaryDesc_Resize,(void*)ADT_Dictionary__DictionaryDesc_HasKey,(void*)ADT_Dictionary__DictionaryDesc_Size,(void*)ADT_Dictionary__DictionaryDesc_Get,(void*)ADT_Dictionary__DictionaryDesc_Lookup,(void*)ADT_Dictionary__DictionaryDesc_Set,(void*)ADT_Dictionary__DictionaryDesc_Copy,(void*)ADT_Dictionary__DictionaryDesc_Delete,(void*)ADT_Dictionary__DictionaryDesc_Clear,(void*)ADT_Dictionary__DictionaryDesc_Keys,(void*)ADT_Dictionary__DictionaryDesc_Values,(void*)ADT_Dictionary__DictionaryDesc_Items,(void*)ADT_Dictionary__DictionaryDesc_IterKeys,(void*)ADT_Dictionary__DictionaryDesc_IterValues}, (RT0__Struct[]){&_td_ADT_Dictionary__DictionaryDesc, &_td_Object__Object, &_td_Object__Object, NULL}, &_mid, (OOC_CHAR8*)"ADT:Dictionary.DictionaryDesc(Object.Object,Object.Object)", 20, 3, 0, RT0__strQualType };
static RT0__StructDesc _td__qtd3 = { (RT0__Struct[]){&_td__qtd2}, NULL, (RT0__Struct[]){&_td_ADT_Dictionary__Dictionary, &_td_Object__Object, &_td_Object__Object, NULL}, &_mid, (OOC_CHAR8*)"ADT:Dictionary.Dictionary(Object.Object,Object.Object)", 4, 0, 0, RT0__strQualType };
static RT0__StructDesc _td__qtd4 = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_ADT_Storable__ObjectDesc,&_td__qtd4}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)ADT_ArrayList__ArrayListDesc_Equals,(void*)ADT_ArrayList__ArrayListDesc_HashCode,(void*)ADT_ArrayList__ArrayListDesc_Store,(void*)ADT_ArrayList__ArrayListDesc_Load,(void*)ADT_ArrayList__ArrayListDesc_CreateArray,(void*)ADT_ArrayList__ArrayListDesc_INIT,(void*)ADT_ArrayList__ArrayListDesc_Destroy,(void*)ADT_ArrayList__ArrayListDesc_Copy,(void*)ADT_ArrayList__ArrayListDesc_EnsureCapacity,(void*)ADT_ArrayList__ArrayListDesc_Clear,(void*)ADT_ArrayList__ArrayListDesc_Append,(void*)ADT_ArrayList__ArrayListDesc_Insert,(void*)ADT_ArrayList__ArrayListDesc_Get,(void*)ADT_ArrayList__ArrayListDesc_Set,(void*)ADT_ArrayList__ArrayListDesc_RemoveRange,(void*)ADT_ArrayList__ArrayListDesc_Remove,(void*)ADT_ArrayList__ArrayListDesc_TrimToSize,(void*)ADT_ArrayList__ArrayListDesc_Size,(void*)ADT_ArrayList__ArrayListDesc_Contains,(void*)ADT_ArrayList__ArrayListDesc_IndexOf,(void*)ADT_ArrayList__ArrayListDesc_LastIndexOf,(void*)ADT_ArrayList__ArrayListDesc_IsEmpty,(void*)ADT_ArrayList__ArrayListDesc_Sort,(void*)ADT_ArrayList__ArrayListDesc_Elements,(void*)ADT_ArrayList__ArrayListDesc_IterElements}, (RT0__Struct[]){&_td_ADT_ArrayList__ArrayListDesc, &_td_OOC_X86_Register__LiveData, NULL}, &_mid, (OOC_CHAR8*)"ADT:ArrayList.ArrayListDesc(OOC:X86:Register.LiveData)", 8, 3, 0, RT0__strQualType };
static RT0__StructDesc _td__qtd5 = { (RT0__Struct[]){&_td__qtd4}, NULL, (RT0__Struct[]){&_td_ADT_ArrayList__ArrayList, &_td_OOC_X86_Register__LiveData, NULL}, &_mid, (OOC_CHAR8*)"ADT:ArrayList.ArrayList(OOC:X86:Register.LiveData)", 4, 0, 0, RT0__strQualType };
static RT0__StructDesc _td__qtd6 = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_ADT_Storable__ObjectDesc,&_td__qtd6}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)ADT_Dictionary__DictionaryDesc_Equals,(void*)ADT_Dictionary__DictionaryDesc_HashCode,(void*)ADT_Dictionary__DictionaryDesc_Store,(void*)ADT_Dictionary__DictionaryDesc_Load,(void*)ADT_Dictionary__DictionaryDesc_INIT,(void*)ADT_Dictionary__DictionaryDesc_Destroy,(void*)ADT_Dictionary__DictionaryDesc_InternalLookup,(void*)ADT_Dictionary__DictionaryDesc_Insert,(void*)ADT_Dictionary__DictionaryDesc_Resize,(void*)ADT_Dictionary__DictionaryDesc_HasKey,(void*)ADT_Dictionary__DictionaryDesc_Size,(void*)ADT_Dictionary__DictionaryDesc_Get,(void*)ADT_Dictionary__DictionaryDesc_Lookup,(void*)ADT_Dictionary__DictionaryDesc_Set,(void*)ADT_Dictionary__DictionaryDesc_Copy,(void*)ADT_Dictionary__DictionaryDesc_Delete,(void*)ADT_Dictionary__DictionaryDesc_Clear,(void*)ADT_Dictionary__DictionaryDesc_Keys,(void*)ADT_Dictionary__DictionaryDesc_Values,(void*)ADT_Dictionary__DictionaryDesc_Items,(void*)ADT_Dictionary__DictionaryDesc_IterKeys,(void*)ADT_Dictionary__DictionaryDesc_IterValues}, (RT0__Struct[]){&_td_ADT_Dictionary__DictionaryDesc, &_td_OOC_X86_SSA__Block, &_td_OOC_X86_Register__LiveData, NULL}, &_mid, (OOC_CHAR8*)"ADT:Dictionary.DictionaryDesc(OOC:X86:SSA.Block,OOC:X86:Register.LiveData)", 20, 3, 0, RT0__strQualType };
static RT0__StructDesc _td__qtd7 = { (RT0__Struct[]){&_td__qtd6}, NULL, (RT0__Struct[]){&_td_ADT_Dictionary__Dictionary, &_td_OOC_X86_SSA__Block, &_td_OOC_X86_Register__LiveData, NULL}, &_mid, (OOC_CHAR8*)"ADT:Dictionary.Dictionary(OOC:X86:SSA.Block,OOC:X86:Register.LiveData)", 4, 0, 0, RT0__strQualType };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:X86:Register", (RT0__Struct[]) { &_td_OOC_X86_Register__RegisterFile, &_td_OOC_X86_Register__RegisterFiles, &_td_OOC_X86_Register__RegisterFileDesc, &_td_OOC_X86_Register__LiveData, &_td_OOC_X86_Register__LiveDataDesc, &_td__qtd0, &_td__qtd1, &_td__qtd2, &_td__qtd3, &_td__qtd4, &_td__qtd5, &_td__qtd6, &_td__qtd7, NULL }, 0 };

extern void OOC_OOC_X86_Register_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_Object_open(&_mid);
    OOC_ADT_ArrayList_open(&_mid);
    OOC_ADT_Dictionary_open(&_mid);
    OOC_OOC_X86_SSA_open(&_mid);
    OOC_OOC_X86_Machine_open(&_mid);
    OOC_OOC_SSA_IGraph_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OOC_X86_Register_init();
  }
  _mid.openCount++;
}
extern void OOC_OOC_X86_Register_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OOC_X86_Register_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_Object_close(&_mid);
    OOC_ADT_ArrayList_close(&_mid);
    OOC_ADT_Dictionary_close(&_mid);
    OOC_OOC_X86_SSA_close(&_mid);
    OOC_OOC_X86_Machine_close(&_mid);
    OOC_OOC_SSA_IGraph_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
