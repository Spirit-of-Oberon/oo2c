#include <ADT/Comparator.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_ADT_Comparator__Comparator = { (RT0__Struct[]){&_td_ADT_Comparator__ComparatorDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"Comparator", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_ADT_Comparator__ComparatorDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_ADT_Comparator__ComparatorDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)ADT_Comparator__ComparatorDesc_Compare}, NULL, &_mid, (OOC_CHAR8*)"ComparatorDesc", 0, 2, (1<<RT0__flagAtomic), RT0__strRecord };
RT0__StructDesc _td_ADT_Comparator__String = { (RT0__Struct[]){&_td_ADT_Comparator__StringDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"String", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_ADT_Comparator__StringDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_ADT_Comparator__ComparatorDesc,&_td_ADT_Comparator__StringDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)ADT_Comparator__StringDesc_Compare}, NULL, &_mid, (OOC_CHAR8*)"StringDesc", 0, 3, (1<<RT0__flagAtomic), RT0__strRecord };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"ADT:Comparator", (RT0__Struct[]) { &_td_ADT_Comparator__Comparator, &_td_ADT_Comparator__ComparatorDesc, &_td_ADT_Comparator__String, &_td_ADT_Comparator__StringDesc, NULL }, 0 };

extern void OOC_ADT_Comparator_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_Object_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_ADT_Comparator_init();
  }
  _mid.openCount++;
}
extern void OOC_ADT_Comparator_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_ADT_Comparator_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_Object_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
