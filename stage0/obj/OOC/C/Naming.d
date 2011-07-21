static void* _c0;
static void* _c1;
static void* _c2;
static void* _c3;
static void* _c4;
static void* _c5;
static void* _c6;
static void* _c7;
#include <OOC/C/Naming.oh>
#include <IntStr.oh>
#include <Strings.oh>
#include <ADT/Dictionary.oh>
#include <OOC/Config.oh>
#include <OOC/SymbolTable/Predef.oh>
#include <OOC/SymbolTable/TypeRules.oh>
typedef OOC_CHAR8 OOC_C_Naming__Buffer[2048];
static ADT_Dictionary__Dictionary OOC_C_Naming__keywords;
static Object__String OOC_C_Naming__rwPrefix;
static Object__String OOC_C_Naming__tdPrefix;
static void OOC_C_Naming__Init(void);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_C_Naming__Buffer = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, "Buffer", 2048, 2048, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_C_Naming__QualTypeDescr = { (RT0__Struct[]){&_td_OOC_C_Naming__QualTypeDescrDesc}, NULL, NULL, &_mid, "QualTypeDescr", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_C_Naming__QualTypeDescrDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_OOC_C_Naming__QualTypeDescrDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)OOC_C_Naming__QualTypeDescrDesc_INIT}, NULL, &_mid, "QualTypeDescrDesc", 8, 2, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_C_Naming__QualTypeData = { (RT0__Struct[]){&_td_OOC_C_Naming__QualTypeDataDesc}, NULL, NULL, &_mid, "QualTypeData", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_C_Naming__QualTypeDataDesc = { (RT0__Struct[]){&_td_OOC_C_Naming__QualTypeDataDesc}, (void*[]){(void*)OOC_C_Naming__QualTypeDataDesc_INIT}, NULL, &_mid, "QualTypeDataDesc", 4, 0, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_C_Naming__1605 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 16, 16, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_C_Naming__2151 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_C_Naming__5494 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 16, 16, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_C_Naming__6490 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 32, 32, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_C_Naming__9576 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__StructDesc _td__qtd0 = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_ADT_Storable__ObjectDesc,&_td__qtd0}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)ADT_ArrayList__ArrayListDesc_Equals,(void*)ADT_ArrayList__ArrayListDesc_HashCode,(void*)ADT_ArrayList__ArrayListDesc_Store,(void*)ADT_ArrayList__ArrayListDesc_Load,(void*)ADT_ArrayList__ArrayListDesc_CreateArray,(void*)ADT_ArrayList__ArrayListDesc_INIT,(void*)ADT_ArrayList__ArrayListDesc_Destroy,(void*)ADT_ArrayList__ArrayListDesc_Copy,(void*)ADT_ArrayList__ArrayListDesc_EnsureCapacity,(void*)ADT_ArrayList__ArrayListDesc_Clear,(void*)ADT_ArrayList__ArrayListDesc_Append,(void*)ADT_ArrayList__ArrayListDesc_Insert,(void*)ADT_ArrayList__ArrayListDesc_Get,(void*)ADT_ArrayList__ArrayListDesc_Set,(void*)ADT_ArrayList__ArrayListDesc_RemoveRange,(void*)ADT_ArrayList__ArrayListDesc_Remove,(void*)ADT_ArrayList__ArrayListDesc_TrimToSize,(void*)ADT_ArrayList__ArrayListDesc_Size,(void*)ADT_ArrayList__ArrayListDesc_Contains,(void*)ADT_ArrayList__ArrayListDesc_IndexOf,(void*)ADT_ArrayList__ArrayListDesc_LastIndexOf,(void*)ADT_ArrayList__ArrayListDesc_IsEmpty,(void*)ADT_ArrayList__ArrayListDesc_Sort,(void*)ADT_ArrayList__ArrayListDesc_Elements}, (RT0__Struct[]){&_td_ADT_ArrayList__ArrayListDesc, &_td_OOC_C_Naming__QualTypeDescr, NULL}, &_mid, "ADT:ArrayList.ArrayListDesc(OOC:C:Naming.QualTypeDescr)", 8, 3, 0, RT0__strQualType };
static RT0__StructDesc _td__qtd1 = { (RT0__Struct[]){&_td__qtd0}, NULL, (RT0__Struct[]){&_td_ADT_ArrayList__ArrayList, &_td_OOC_C_Naming__QualTypeDescr, NULL}, &_mid, "ADT:ArrayList.ArrayList(OOC:C:Naming.QualTypeDescr)", 4, 0, 0, RT0__strQualType };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:C:Naming", (RT0__Struct[]) { &_td_OOC_C_Naming__Buffer, &_td_OOC_C_Naming__QualTypeDescr, &_td_OOC_C_Naming__QualTypeDescrDesc, &_td_OOC_C_Naming__QualTypeData, &_td_OOC_C_Naming__QualTypeDataDesc, &_td__qtd0, &_td__qtd1, NULL } };

extern void OOC_OOC_C_Naming_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_C_Naming_init();
}

/* --- */
