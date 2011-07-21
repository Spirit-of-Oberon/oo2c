#include <OOC/SymbolTable/Predef.oh>
#include <Strings.oh>
#include <Object.oh>
#include <OOC/Config/Autoconf.oh>
static Object_Boxed__Object OOC_SymbolTable_Predef__minConst[19];
static Object_Boxed__Object OOC_SymbolTable_Predef__maxConst[19];
OOC_SymbolTable__Name OOC_SymbolTable_Predef__nameStringModule;
OOC_SymbolTable__Name OOC_SymbolTable_Predef__nameStringType;
static OOC_SymbolTable__PredefType OOC_SymbolTable_Predef__PredefType(OOC_SymbolTable_Builder__Builder stb, OOC_SymbolTable__Module module, OOC_INT16 id, const OOC_CHAR8 name__ref[], OOC_LEN name_0d, OOC_INT32 size, OOC_INT16 align, Object_Boxed__Object minValue, Object_Boxed__Object maxValue);
static OOC_SymbolTable__VarDecl OOC_SymbolTable_Predef__PredefVar(OOC_SymbolTable_Builder__Builder stb, OOC_SymbolTable__Module module, const OOC_CHAR8 name__ref[], OOC_LEN name_0d, OOC_SymbolTable__Type type);
static void OOC_SymbolTable_Predef__TypeAlias(OOC_SymbolTable_Builder__Builder stb, OOC_SymbolTable__Module module, const OOC_CHAR8 name__ref[], OOC_LEN name_0d, OOC_SymbolTable__PredefType baseType);
static void OOC_SymbolTable_Predef__PredefProc(OOC_SymbolTable_Builder__Builder stb, OOC_SymbolTable__Module module, OOC_INT16 id, const OOC_CHAR8 name__ref[], OOC_LEN name_0d, OOC_INT16 minArgs, OOC_INT16 maxArgs);
static void OOC_SymbolTable_Predef__Init(void);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_SymbolTable_Predef__3834 = { (RT0__Struct[]){&_td_Object_Boxed__Object}, NULL, NULL, &_mid, NULL, 76, 19, 0, RT0__strArray };
RT0__StructDesc _td_OOC_SymbolTable_Predef__5875 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_SymbolTable_Predef__6252 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_SymbolTable_Predef__6930 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_SymbolTable_Predef__7348 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_SymbolTable_Predef__7687 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_SymbolTable_Predef__8476 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_OOC_SymbolTable_Predef__15084 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:SymbolTable:Predef", (RT0__Struct[]) { NULL }, 0 };

extern void OOC_OOC_SymbolTable_Predef_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_Strings_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Object_Boxed_open(&_mid);
    OOC_Object_BigInt_open(&_mid);
    OOC_OOC_Config_Autoconf_open(&_mid);
    OOC_OOC_SymbolTable_open(&_mid);
    OOC_OOC_SymbolTable_Builder_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_OOC_SymbolTable_Predef_init();
  }
  _mid.openCount++;
}
extern void OOC_OOC_SymbolTable_Predef_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_OOC_SymbolTable_Predef_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_Strings_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Object_Boxed_close(&_mid);
    OOC_Object_BigInt_close(&_mid);
    OOC_OOC_Config_Autoconf_close(&_mid);
    OOC_OOC_SymbolTable_close(&_mid);
    OOC_OOC_SymbolTable_Builder_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
