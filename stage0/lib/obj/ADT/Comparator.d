#include <ADT/Comparator.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_ADT_Comparator__Comparator = { (RT0__Struct[]){&_td_ADT_Comparator__ComparatorDesc}, NULL, NULL, &_mid, "Comparator", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_ADT_Comparator__ComparatorDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_ADT_Comparator__ComparatorDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)ADT_Comparator__ComparatorDesc_Compare}, NULL, &_mid, "ComparatorDesc", 0, 2, (1<<RT0__flagAtomic), RT0__strRecord };
RT0__StructDesc _td_ADT_Comparator__String = { (RT0__Struct[]){&_td_ADT_Comparator__StringDesc}, NULL, NULL, &_mid, "String", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_ADT_Comparator__StringDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_ADT_Comparator__ComparatorDesc,&_td_ADT_Comparator__StringDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)ADT_Comparator__StringDesc_Compare}, NULL, &_mid, "StringDesc", 0, 3, (1<<RT0__flagAtomic), RT0__strRecord };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"ADT:Comparator", (RT0__Struct[]) { &_td_ADT_Comparator__Comparator, &_td_ADT_Comparator__ComparatorDesc, &_td_ADT_Comparator__String, &_td_ADT_Comparator__StringDesc, NULL } };

extern void OOC_ADT_Comparator_init0() {
  RT0__RegisterModule(&_mid);
  OOC_ADT_Comparator_init();
}

/* --- */
