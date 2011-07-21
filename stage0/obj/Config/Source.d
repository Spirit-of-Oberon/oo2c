#include <Config/Source.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_Config_Source__Source = { (RT0__Struct[]){&_td_Config_Source__SourceDesc}, NULL, NULL, &_mid, "Source", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Config_Source__SourceDesc = { (RT0__Struct[]){&_td_Config_Source__SourceDesc}, (void*[]){(void*)Config_Source__SourceDesc_Write}, NULL, &_mid, "SourceDesc", 0, 0, (1<<RT0__flagAtomic), RT0__strRecord };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"Config:Source", (RT0__Struct[]) { &_td_Config_Source__Source, &_td_Config_Source__SourceDesc, NULL } };

extern void OOC_Config_Source_init0() {
  RT0__RegisterModule(&_mid);
  OOC_Config_Source_init();
}

/* --- */
