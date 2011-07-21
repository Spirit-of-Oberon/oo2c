#include <OOC/Make/WriteMainFileC.oh>
#include <IO/TextRider.oh>
#include <OOC/Config.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_Make_WriteMainFileC__1200 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_Make_WriteMainFileC__1308 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_Make_WriteMainFileC__1343 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1024, 1024, (1<<RT0__flagAtomic), RT0__strArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:Make:WriteMainFileC", (RT0__Struct[]) { NULL }, 0 };

extern void OOC_OOC_Make_WriteMainFileC_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_IO_open(&_mid);
    OOC_IO_TextRider_open(&_mid);
    OOC_OOC_Config_open(&_mid);
    OOC_OOC_Repository_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OOC_Make_WriteMainFileC_init();
  }
  _mid.openCount++;
}
extern void OOC_OOC_Make_WriteMainFileC_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OOC_Make_WriteMainFileC_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_IO_close(&_mid);
    OOC_IO_TextRider_close(&_mid);
    OOC_OOC_Config_close(&_mid);
    OOC_OOC_Repository_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
