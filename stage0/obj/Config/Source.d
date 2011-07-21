#include <Config/Source.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_Config_Source__Source = { (RT0__Struct[]){&_td_Config_Source__SourceDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"Source", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Config_Source__SourceDesc = { (RT0__Struct[]){&_td_Config_Source__SourceDesc}, (void*[]){(void*)Config_Source__SourceDesc_Write}, NULL, &_mid, (OOC_CHAR8*)"SourceDesc", 0, 0, (1<<RT0__flagAtomic), RT0__strRecord };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"Config:Source", (RT0__Struct[]) { &_td_Config_Source__Source, &_td_Config_Source__SourceDesc, NULL }, 0 };

extern void OOC_Config_Source_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_IO_open(&_mid);
    OOC_Config_Parser_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_Config_Source_init();
  }
  _mid.openCount++;
}
extern void OOC_Config_Source_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_Config_Source_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_IO_close(&_mid);
    OOC_Config_Parser_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
