#include <OOC/Make/WriteMainFileAssembler.oh>
#include <Ascii.oh>
#include <IO/TextRider.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_Make_WriteMainFileAssembler__1085 = { (RT0__Struct[]){&_td_OOC_Repository__Module}, NULL, NULL, &_mid, NULL, 4, 1, 0, RT0__strOpenArray };
RT0__StructDesc _td_OOC_Make_WriteMainFileAssembler__1278 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_Make_WriteMainFileAssembler__1386 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_Make_WriteMainFileAssembler__1421 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1024, 1024, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_OOC_Make_WriteMainFileAssembler__1821 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_Make_WriteMainFileAssembler__2095 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_Make_WriteMainFileAssembler__2213 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:Make:WriteMainFileAssembler", (RT0__Struct[]) { NULL }, 0 };

extern void OOC_OOC_Make_WriteMainFileAssembler_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_Ascii_open(&_mid);
    OOC_IO_open(&_mid);
    OOC_IO_TextRider_open(&_mid);
    OOC_OOC_Repository_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OOC_Make_WriteMainFileAssembler_init();
  }
  _mid.openCount++;
}
extern void OOC_OOC_Make_WriteMainFileAssembler_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OOC_Make_WriteMainFileAssembler_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_Ascii_close(&_mid);
    OOC_IO_close(&_mid);
    OOC_IO_TextRider_close(&_mid);
    OOC_OOC_Repository_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
