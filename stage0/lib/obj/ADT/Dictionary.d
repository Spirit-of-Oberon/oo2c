#include <ADT/Dictionary.oh>
typedef OOC_UINT32 ADT_Dictionary__HSet;
static ADT_Dictionary__Dummy ADT_Dictionary__dummy;
#define ADT_Dictionary__minSize 4
#define ADT_Dictionary__maxPoly 28
static OOC_INT32 ADT_Dictionary__polys[29];
static OOC_CHAR8 ADT_Dictionary__IsSet(Object__Object key);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_ADT_Dictionary__Entry = { (RT0__Struct[]){&_td_ADT_Dictionary__Entry}, (void*[]){}, NULL, &_mid, (OOC_CHAR8*)"Entry", 12, 0, 0, RT0__strRecord };
RT0__StructDesc _td_ADT_Dictionary__2645 = { (RT0__Struct[]){&_td_ADT_Dictionary__Entry}, NULL, NULL, &_mid, NULL, 12, 1, 0, RT0__strOpenArray };
RT0__StructDesc _td_ADT_Dictionary__Table = { (RT0__Struct[]){&_td_ADT_Dictionary__2645}, NULL, NULL, &_mid, (OOC_CHAR8*)"Table", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_ADT_Dictionary__Item = { (RT0__Struct[]){&_td_ADT_Dictionary__Item}, (void*[]){}, NULL, &_mid, (OOC_CHAR8*)"Item", 8, 0, 0, RT0__strRecord };
RT0__StructDesc _td_ADT_Dictionary__2784 = { (RT0__Struct[]){&_td_ADT_Dictionary__Item}, NULL, NULL, &_mid, NULL, 8, 1, 0, RT0__strOpenArray };
RT0__StructDesc _td_ADT_Dictionary__ItemArrayPtr = { (RT0__Struct[]){&_td_ADT_Dictionary__2784}, NULL, NULL, &_mid, (OOC_CHAR8*)"ItemArrayPtr", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_ADT_Dictionary__Dictionary = { (RT0__Struct[]){&_td_ADT_Dictionary__DictionaryDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"Dictionary", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_ADT_Dictionary__DictionaryDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_ADT_Storable__ObjectDesc,&_td_ADT_Dictionary__DictionaryDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)ADT_Dictionary__DictionaryDesc_Equals,(void*)ADT_Dictionary__DictionaryDesc_HashCode,(void*)ADT_Dictionary__DictionaryDesc_Store,(void*)ADT_Dictionary__DictionaryDesc_Load,(void*)ADT_Dictionary__DictionaryDesc_INIT,(void*)ADT_Dictionary__DictionaryDesc_Destroy,(void*)ADT_Dictionary__DictionaryDesc_InternalLookup,(void*)ADT_Dictionary__DictionaryDesc_Insert,(void*)ADT_Dictionary__DictionaryDesc_Resize,(void*)ADT_Dictionary__DictionaryDesc_HasKey,(void*)ADT_Dictionary__DictionaryDesc_Size,(void*)ADT_Dictionary__DictionaryDesc_Get,(void*)ADT_Dictionary__DictionaryDesc_Lookup,(void*)ADT_Dictionary__DictionaryDesc_Set,(void*)ADT_Dictionary__DictionaryDesc_Copy,(void*)ADT_Dictionary__DictionaryDesc_Delete,(void*)ADT_Dictionary__DictionaryDesc_Clear,(void*)ADT_Dictionary__DictionaryDesc_Keys,(void*)ADT_Dictionary__DictionaryDesc_Values,(void*)ADT_Dictionary__DictionaryDesc_Items,(void*)ADT_Dictionary__DictionaryDesc_IterKeys,(void*)ADT_Dictionary__DictionaryDesc_IterValues}, NULL, &_mid, (OOC_CHAR8*)"DictionaryDesc", 20, 3, 0, RT0__strRecord };
RT0__StructDesc _td_ADT_Dictionary__IterKeys = { (RT0__Struct[]){&_td_ADT_Dictionary__IterKeysDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"IterKeys", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_ADT_Dictionary__IterKeysDesc = { (RT0__Struct[]){&_td_ADT_Dictionary__IterKeysDesc}, (void*[]){(void*)ADT_Dictionary__IterKeysDesc_INIT,(void*)ADT_Dictionary__IterKeysDesc_Next}, NULL, &_mid, (OOC_CHAR8*)"IterKeysDesc", 8, 0, 0, RT0__strRecord };
RT0__StructDesc _td_ADT_Dictionary__IterValues = { (RT0__Struct[]){&_td_ADT_Dictionary__IterValuesDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"IterValues", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_ADT_Dictionary__IterValuesDesc = { (RT0__Struct[]){&_td_ADT_Dictionary__IterValuesDesc}, (void*[]){(void*)ADT_Dictionary__IterValuesDesc_INIT,(void*)ADT_Dictionary__IterValuesDesc_Next}, NULL, &_mid, (OOC_CHAR8*)"IterValuesDesc", 8, 0, 0, RT0__strRecord };
RT0__StructDesc _td_ADT_Dictionary__Dummy = { (RT0__Struct[]){&_td_ADT_Dictionary__DummyDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"Dummy", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_ADT_Dictionary__DummyDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_ADT_Dictionary__DummyDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)ADT_Dictionary__DummyDesc_Destroy}, NULL, &_mid, (OOC_CHAR8*)"DummyDesc", 0, 2, (1<<RT0__flagAtomic), RT0__strRecord };
RT0__StructDesc _td_ADT_Dictionary__4639 = { (RT0__Struct[]){&RT0__longint}, NULL, NULL, &_mid, NULL, 116, 29, (1<<RT0__flagAtomic), RT0__strArray };
static RT0__StructDesc _td__qtd0 = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_ADT_Storable__ObjectDesc,&_td__qtd0}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)ADT_Dictionary__DictionaryDesc_Equals,(void*)ADT_Dictionary__DictionaryDesc_HashCode,(void*)ADT_Dictionary__DictionaryDesc_Store,(void*)ADT_Dictionary__DictionaryDesc_Load,(void*)ADT_Dictionary__DictionaryDesc_INIT,(void*)ADT_Dictionary__DictionaryDesc_Destroy,(void*)ADT_Dictionary__DictionaryDesc_InternalLookup,(void*)ADT_Dictionary__DictionaryDesc_Insert,(void*)ADT_Dictionary__DictionaryDesc_Resize,(void*)ADT_Dictionary__DictionaryDesc_HasKey,(void*)ADT_Dictionary__DictionaryDesc_Size,(void*)ADT_Dictionary__DictionaryDesc_Get,(void*)ADT_Dictionary__DictionaryDesc_Lookup,(void*)ADT_Dictionary__DictionaryDesc_Set,(void*)ADT_Dictionary__DictionaryDesc_Copy,(void*)ADT_Dictionary__DictionaryDesc_Delete,(void*)ADT_Dictionary__DictionaryDesc_Clear,(void*)ADT_Dictionary__DictionaryDesc_Keys,(void*)ADT_Dictionary__DictionaryDesc_Values,(void*)ADT_Dictionary__DictionaryDesc_Items,(void*)ADT_Dictionary__DictionaryDesc_IterKeys,(void*)ADT_Dictionary__DictionaryDesc_IterValues}, (RT0__Struct[]){&_td_ADT_Dictionary__DictionaryDesc, &_td_Object__Object, &_td_Object__Object, NULL}, &_mid, (OOC_CHAR8*)"ADT:Dictionary.DictionaryDesc(Object.Object,Object.Object)", 20, 3, 0, RT0__strQualType };
static RT0__StructDesc _td__qtd1 = { (RT0__Struct[]){&_td__qtd0}, NULL, (RT0__Struct[]){&_td_ADT_Dictionary__Dictionary, &_td_Object__Object, &_td_Object__Object, NULL}, &_mid, (OOC_CHAR8*)"ADT:Dictionary.Dictionary(Object.Object,Object.Object)", 4, 0, 0, RT0__strQualType };
static RT0__StructDesc _td__qtd2 = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_ADT_Storable__ObjectDesc,&_td__qtd2}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)ADT_Dictionary__DictionaryDesc_Equals,(void*)ADT_Dictionary__DictionaryDesc_HashCode,(void*)ADT_Dictionary__DictionaryDesc_Store,(void*)ADT_Dictionary__DictionaryDesc_Load,(void*)ADT_Dictionary__DictionaryDesc_INIT,(void*)ADT_Dictionary__DictionaryDesc_Destroy,(void*)ADT_Dictionary__DictionaryDesc_InternalLookup,(void*)ADT_Dictionary__DictionaryDesc_Insert,(void*)ADT_Dictionary__DictionaryDesc_Resize,(void*)ADT_Dictionary__DictionaryDesc_HasKey,(void*)ADT_Dictionary__DictionaryDesc_Size,(void*)ADT_Dictionary__DictionaryDesc_Get,(void*)ADT_Dictionary__DictionaryDesc_Lookup,(void*)ADT_Dictionary__DictionaryDesc_Set,(void*)ADT_Dictionary__DictionaryDesc_Copy,(void*)ADT_Dictionary__DictionaryDesc_Delete,(void*)ADT_Dictionary__DictionaryDesc_Clear,(void*)ADT_Dictionary__DictionaryDesc_Keys,(void*)ADT_Dictionary__DictionaryDesc_Values,(void*)ADT_Dictionary__DictionaryDesc_Items,(void*)ADT_Dictionary__DictionaryDesc_IterKeys,(void*)ADT_Dictionary__DictionaryDesc_IterValues}, (RT0__Struct[]){&_td_ADT_Dictionary__DictionaryDesc, &_td_Object__Object, &_td_Object__Object, NULL}, &_mid, (OOC_CHAR8*)"ADT:Dictionary.DictionaryDesc(ADT:Dictionary.K,ADT:Dictionary.V)", 20, 3, 0, RT0__strQualType };
static RT0__StructDesc _td__qtd3 = { (RT0__Struct[]){&_td__qtd2}, NULL, (RT0__Struct[]){&_td_ADT_Dictionary__Dictionary, &_td_Object__Object, &_td_Object__Object, NULL}, &_mid, (OOC_CHAR8*)"ADT:Dictionary.Dictionary(ADT:Dictionary.K,ADT:Dictionary.V)", 4, 0, 0, RT0__strQualType };
static RT0__StructDesc _td__qtd4 = { (RT0__Struct[]){&_td__qtd4}, (void*[]){(void*)ADT_Dictionary__IterKeysDesc_INIT,(void*)ADT_Dictionary__IterKeysDesc_Next}, (RT0__Struct[]){&_td_ADT_Dictionary__IterKeysDesc, &_td_Object__Object, &_td_Object__Object, NULL}, &_mid, (OOC_CHAR8*)"ADT:Dictionary.IterKeysDesc(ADT:Dictionary.K,ADT:Dictionary.V)", 8, 0, 0, RT0__strQualType };
static RT0__StructDesc _td__qtd5 = { (RT0__Struct[]){&_td__qtd4}, NULL, (RT0__Struct[]){&_td_ADT_Dictionary__IterKeys, &_td_Object__Object, &_td_Object__Object, NULL}, &_mid, (OOC_CHAR8*)"ADT:Dictionary.IterKeys(ADT:Dictionary.K,ADT:Dictionary.V)", 4, 0, 0, RT0__strQualType };
static RT0__StructDesc _td__qtd6 = { (RT0__Struct[]){&_td__qtd6}, (void*[]){(void*)ADT_Dictionary__IterValuesDesc_INIT,(void*)ADT_Dictionary__IterValuesDesc_Next}, (RT0__Struct[]){&_td_ADT_Dictionary__IterValuesDesc, &_td_Object__Object, &_td_Object__Object, NULL}, &_mid, (OOC_CHAR8*)"ADT:Dictionary.IterValuesDesc(ADT:Dictionary.K,ADT:Dictionary.V)", 8, 0, 0, RT0__strQualType };
static RT0__StructDesc _td__qtd7 = { (RT0__Struct[]){&_td__qtd6}, NULL, (RT0__Struct[]){&_td_ADT_Dictionary__IterValues, &_td_Object__Object, &_td_Object__Object, NULL}, &_mid, (OOC_CHAR8*)"ADT:Dictionary.IterValues(ADT:Dictionary.K,ADT:Dictionary.V)", 4, 0, 0, RT0__strQualType };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"ADT:Dictionary", (RT0__Struct[]) { &_td_ADT_Dictionary__Entry, &_td_ADT_Dictionary__Table, &_td_ADT_Dictionary__Item, &_td_ADT_Dictionary__ItemArrayPtr, &_td_ADT_Dictionary__Dictionary, &_td_ADT_Dictionary__DictionaryDesc, &_td_ADT_Dictionary__IterKeys, &_td_ADT_Dictionary__IterKeysDesc, &_td_ADT_Dictionary__IterValues, &_td_ADT_Dictionary__IterValuesDesc, &_td_ADT_Dictionary__Dummy, &_td_ADT_Dictionary__DummyDesc, &_td__qtd0, &_td__qtd1, &_td__qtd2, &_td__qtd3, &_td__qtd4, &_td__qtd5, &_td__qtd6, &_td__qtd7, NULL }, 0 };

extern void OOC_ADT_Dictionary_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_ADT_Storable_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_IO_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_ADT_Dictionary_init();
  }
  _mid.openCount++;
}
extern void OOC_ADT_Dictionary_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_ADT_Dictionary_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_ADT_Storable_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_IO_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
