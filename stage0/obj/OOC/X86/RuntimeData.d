static void* _c0;
static void* _c1;
static void* _c2;
static void* _c3;
static void* _c4;
static void* _c5;
static void* _c6;
static void* _c7;
static void* _c8;
static void* _c9;
static void* _c10;
static void* _c11;
static void* _c12;
static void* _c13;
static void* _c14;
static void* _c15;
static void* _c16;
static void* _c17;
static void* _c18;
static void* _c19;
static void* _c20;
static void* _c21;
static void* _c22;
static void* _c23;
static void* _c24;
static void* _c25;
static void* _c26;
static void* _c27;
static void* _c28;
static void* _c29;
static void* _c30;
static void* _c31;
#include <OOC/X86/RuntimeData.oh>
#include <Ascii.oh>
#include <RT0.oh>
#include <Object.oh>
#include <ADT/ArrayList.oh>
#include <OOC/SymbolTable/Predef.oh>
#include <OOC/C/Naming.oh>
#define OOC_X86_RuntimeData__nl (OOC_CHAR8)'\012'
#define OOC_X86_RuntimeData__tab (OOC_CHAR8)'\011'
#define OOC_X86_RuntimeData__nlTab "\012\011"
#define OOC_X86_RuntimeData__sizeAddress 4
#define OOC_X86_RuntimeData__sizeModuleDesc 8
#define OOC_X86_RuntimeData__sizeStructDesc 36
#define OOC_X86_RuntimeData__moduleDescriptor "_mid"
#define OOC_X86_RuntimeData__moduleName "_mid_name"
#define OOC_X86_RuntimeData__moduleTypeDescrList "_mid_tdlist"

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_X86_RuntimeData__DataWriter = { (RT0__Struct[]){&_td_OOC_X86_RuntimeData__DataWriterDesc}, NULL, NULL, &_mid, "DataWriter", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_OOC_X86_RuntimeData__DataWriterDesc = { (RT0__Struct[]){&_td_OOC_X86_RuntimeData__DataWriterDesc}, (void*[]){(void*)OOC_X86_RuntimeData__DataWriterDesc_INIT,(void*)OOC_X86_RuntimeData__DataWriterDesc_Align,(void*)OOC_X86_RuntimeData__DataWriterDesc_Object,(void*)OOC_X86_RuntimeData__DataWriterDesc_Pad,(void*)OOC_X86_RuntimeData__DataWriterDesc_PadTo,(void*)OOC_X86_RuntimeData__DataWriterDesc_FixAlign,(void*)OOC_X86_RuntimeData__DataWriterDesc_Adr,(void*)OOC_X86_RuntimeData__DataWriterDesc_Null,(void*)OOC_X86_RuntimeData__DataWriterDesc_LongInt,(void*)OOC_X86_RuntimeData__DataWriterDesc_ShortInt,(void*)OOC_X86_RuntimeData__DataWriterDesc_StringObject,(void*)OOC_X86_RuntimeData__DataWriterDesc_TypeFlags}, NULL, &_mid, "DataWriterDesc", 12, 0, 0, RT0__strRecord };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:X86:RuntimeData", (RT0__Struct[]) { &_td_OOC_X86_RuntimeData__DataWriter, &_td_OOC_X86_RuntimeData__DataWriterDesc, NULL }, 0 };

extern void OOC_OOC_X86_RuntimeData_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_Ascii_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_ADT_StringBuffer_open(&_mid);
    OOC_ADT_ArrayList_open(&_mid);
    OOC_OOC_SymbolTable_open(&_mid);
    OOC_OOC_SymbolTable_Predef_open(&_mid);
    OOC_OOC_C_Naming_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OOC_X86_RuntimeData_init();
  }
  _mid.openCount++;
}
extern void OOC_OOC_X86_RuntimeData_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OOC_X86_RuntimeData_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_Ascii_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_ADT_StringBuffer_close(&_mid);
    OOC_ADT_ArrayList_close(&_mid);
    OOC_OOC_SymbolTable_close(&_mid);
    OOC_OOC_SymbolTable_Predef_close(&_mid);
    OOC_OOC_C_Naming_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
