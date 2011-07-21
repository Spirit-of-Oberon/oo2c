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
OOC_INT32 RT0__argc;
OOC_CHAR8 **RT0__argv;
OOC_INT32 RT0__poisonHeap;

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_RT0__Object = { (RT0__Struct[]){&_td_RT0__ObjectDesc}, NULL, NULL, &_mid, "Object", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_RT0__ObjectDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize}, NULL, &_mid, "ObjectDesc", 0, 0, (1<<RT0__flagAtomic), RT0__strRecord };
RT0__StructDesc _td_RT0__Name = { (RT0__Struct[]){NULL}, NULL, NULL, &_mid, "Name", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_RT0__Module = { (RT0__Struct[]){&_td_RT0__ModuleDesc}, NULL, NULL, &_mid, "Module", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_RT0__Struct = { (RT0__Struct[]){NULL}, NULL, NULL, &_mid, "Struct", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_RT0__6481 = { (RT0__Struct[]){NULL}, NULL, NULL, &_mid, NULL, 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_RT0__6701 = { (RT0__Struct[]){NULL}, NULL, NULL, &_mid, NULL, 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_RT0__6895 = { (RT0__Struct[]){NULL}, NULL, NULL, &_mid, NULL, 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_RT0__ModuleDesc = { (RT0__Struct[]){&_td_RT0__ModuleDesc}, (void*[]){}, NULL, &_mid, "ModuleDesc", 8, 0, 0, RT0__strRecord };
RT0__StructDesc _td_RT0__8672 = { (RT0__Struct[]){NULL}, NULL, NULL, &_mid, NULL, 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_RT0__9352 = { (RT0__Struct[]){NULL}, NULL, NULL, &_mid, NULL, 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_RT0__9278 = { (RT0__Struct[]){NULL}, NULL, NULL, &_mid, NULL, 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_RT0__13723 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_RT0__13929 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"RT0", (RT0__Struct[]) { &_td_RT0__Object, &_td_RT0__ObjectDesc, &_td_RT0__Name, &_td_RT0__Module, &_td_RT0__Struct, &_td_RT0__ModuleDesc, NULL } };

extern void OOC_RT0_init0() {
  OOC_RT0_init();
}

/* --- */
