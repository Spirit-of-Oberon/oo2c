#include <RT0.oh>
struct RT0__StructDesc RT0__boolean;
struct RT0__StructDesc RT0__char;
struct RT0__StructDesc RT0__longchar;
struct RT0__StructDesc RT0__ucs4char;
struct RT0__StructDesc RT0__shortint;
struct RT0__StructDesc RT0__integer;
struct RT0__StructDesc RT0__longint;
struct RT0__StructDesc RT0__real;
struct RT0__StructDesc RT0__longreal;
struct RT0__StructDesc RT0__set32;
struct RT0__StructDesc RT0__byte;
struct RT0__StructDesc RT0__ptr;
struct RT0__StructDesc RT0__procedure;
OOC_INT32 RT0__argc;
RT0__charPtr2d RT0__argv;
OOC_INT32 RT0__poisonHeap;

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_RT0__Object = { (RT0__Struct[]){&_td_RT0__ObjectDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"Object", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_RT0__ObjectDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize}, NULL, &_mid, (OOC_CHAR8*)"ObjectDesc", 0, 0, (1<<RT0__flagAtomic), RT0__strRecord };
RT0__StructDesc _td_RT0__Name = { (RT0__Struct[]){NULL}, NULL, NULL, &_mid, (OOC_CHAR8*)"Name", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_RT0__Module = { (RT0__Struct[]){&_td_RT0__ModuleDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"Module", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_RT0__Struct = { (RT0__Struct[]){NULL}, NULL, NULL, &_mid, (OOC_CHAR8*)"Struct", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_RT0__6868 = { (RT0__Struct[]){NULL}, NULL, NULL, &_mid, NULL, 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_RT0__7088 = { (RT0__Struct[]){NULL}, NULL, NULL, &_mid, NULL, 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_RT0__7282 = { (RT0__Struct[]){NULL}, NULL, NULL, &_mid, NULL, 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_RT0__ModuleDesc = { (RT0__Struct[]){&_td_RT0__ModuleDesc}, (void*[]){}, NULL, &_mid, (OOC_CHAR8*)"ModuleDesc", 12, 0, 0, RT0__strRecord };
RT0__StructDesc _td_RT0__9059 = { (RT0__Struct[]){NULL}, NULL, NULL, &_mid, NULL, 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_RT0__CaseRange = { (RT0__Struct[]){&_td_RT0__CaseRange}, (void*[]){}, NULL, &_mid, (OOC_CHAR8*)"CaseRange", 12, 0, 0, RT0__strRecord };
RT0__StructDesc _td_RT0__charPtr1d = { (RT0__Struct[]){NULL}, NULL, NULL, &_mid, (OOC_CHAR8*)"charPtr1d", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_RT0__charPtr2d = { (RT0__Struct[]){NULL}, NULL, NULL, &_mid, (OOC_CHAR8*)"charPtr2d", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_RT0__14981 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_RT0__15187 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_RT0__15533 = { (RT0__Struct[]){&_td_RT0__CaseRange}, NULL, NULL, &_mid, NULL, 12, 1, 0, RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"RT0", (RT0__Struct[]) { &_td_RT0__Object, &_td_RT0__ObjectDesc, &_td_RT0__Name, &_td_RT0__Module, &_td_RT0__Struct, &_td_RT0__ModuleDesc, &_td_RT0__CaseRange, &_td_RT0__charPtr1d, &_td_RT0__charPtr2d, NULL }, 0 };

extern void OOC_RT0_open(RT0__Module client) {
  if (_mid.openCount == 0) {

    OOC_RT0_init();
  }
  _mid.openCount++;
}
extern void OOC_RT0_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_RT0_destroy();

  }
}

/* --- */
