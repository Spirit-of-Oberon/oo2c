#include <Object/Boxed.oh>
#include <IntStr.oh>
#include <RealStr.oh>
#include <LRealStr.oh>
#include <Strings.oh>
#include <HashCode.oh>
#include <ADT/StringBuffer.oh>
Object_Boxed__Boolean Object_Boxed__true;
Object_Boxed__Boolean Object_Boxed__false;
static Object__String Object_Boxed__trueString;
static Object__String Object_Boxed__falseString;
Object_Boxed__LongInt Object_Boxed__zeroLongInt;
Object_Boxed__LongInt Object_Boxed__oneLongInt;
Object_Boxed__LongReal Object_Boxed__zeroLongReal;
Object_Boxed__LongReal Object_Boxed__oneLongReal;
static Object_Boxed__String Object_Boxed__emptyString;

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_Object_Boxed__Object = { (RT0__Struct[]){&_td_Object_Boxed__ObjectDesc}, NULL, NULL, &_mid, "Object", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Object_Boxed__ObjectDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_ADT_Storable__ObjectDesc,&_td_Object_Boxed__ObjectDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object_Boxed__ObjectDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)ADT_Storable__ObjectDesc_Store,(void*)ADT_Storable__ObjectDesc_Load,(void*)Object_Boxed__ObjectDesc_Cmp}, NULL, &_mid, "ObjectDesc", 0, 3, (1<<RT0__flagAtomic), RT0__strRecord };
RT0__StructDesc _td_Object_Boxed__1726 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_Object_Boxed__Boolean = { (RT0__Struct[]){&_td_Object_Boxed__BooleanDesc}, NULL, NULL, &_mid, "Boolean", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Object_Boxed__BooleanDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_ADT_Storable__ObjectDesc,&_td_Object_Boxed__ObjectDesc,&_td_Object_Boxed__BooleanDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object_Boxed__BooleanDesc_ToString,(void*)Object_Boxed__BooleanDesc_Equals,(void*)Object_Boxed__BooleanDesc_HashCode,(void*)Object_Boxed__BooleanDesc_Store,(void*)Object_Boxed__BooleanDesc_Load,(void*)Object_Boxed__BooleanDesc_Cmp,(void*)Object_Boxed__BooleanDesc_INIT}, NULL, &_mid, "BooleanDesc", 1, 4, (1<<RT0__flagAtomic), RT0__strRecord };
RT0__StructDesc _td_Object_Boxed__LongInt = { (RT0__Struct[]){&_td_Object_Boxed__LongIntDesc}, NULL, NULL, &_mid, "LongInt", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Object_Boxed__LongIntDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_ADT_Storable__ObjectDesc,&_td_Object_Boxed__ObjectDesc,&_td_Object_Boxed__LongIntDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object_Boxed__LongIntDesc_ToString,(void*)Object_Boxed__LongIntDesc_Equals,(void*)Object_Boxed__LongIntDesc_HashCode,(void*)Object_Boxed__LongIntDesc_Store,(void*)Object_Boxed__LongIntDesc_Load,(void*)Object_Boxed__LongIntDesc_Cmp,(void*)Object_Boxed__LongIntDesc_INIT,(void*)Object_Boxed__LongIntDesc_Add,(void*)Object_Boxed__LongIntDesc_Sub,(void*)Object_Boxed__LongIntDesc_Mul,(void*)Object_Boxed__LongIntDesc_Div,(void*)Object_Boxed__LongIntDesc_Mod,(void*)Object_Boxed__LongIntDesc_Sign,(void*)Object_Boxed__LongIntDesc_Neg}, NULL, &_mid, "LongIntDesc", 4, 4, (1<<RT0__flagAtomic), RT0__strRecord };
RT0__StructDesc _td_Object_Boxed__LongReal = { (RT0__Struct[]){&_td_Object_Boxed__LongRealDesc}, NULL, NULL, &_mid, "LongReal", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Object_Boxed__LongRealDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_ADT_Storable__ObjectDesc,&_td_Object_Boxed__ObjectDesc,&_td_Object_Boxed__LongRealDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object_Boxed__LongRealDesc_ToString,(void*)Object_Boxed__LongRealDesc_Equals,(void*)Object_Boxed__LongRealDesc_HashCode,(void*)Object_Boxed__LongRealDesc_Store,(void*)Object_Boxed__LongRealDesc_Load,(void*)Object_Boxed__LongRealDesc_Cmp,(void*)Object_Boxed__LongRealDesc_INIT,(void*)Object_Boxed__LongRealDesc_ToLongReal,(void*)Object_Boxed__LongRealDesc_Add,(void*)Object_Boxed__LongRealDesc_Sub,(void*)Object_Boxed__LongRealDesc_Mul,(void*)Object_Boxed__LongRealDesc_Div,(void*)Object_Boxed__LongRealDesc_Sign,(void*)Object_Boxed__LongRealDesc_Neg}, NULL, &_mid, "LongRealDesc", 8, 4, (1<<RT0__flagAtomic), RT0__strRecord };
RT0__StructDesc _td_Object_Boxed__Set = { (RT0__Struct[]){&_td_Object_Boxed__SetDesc}, NULL, NULL, &_mid, "Set", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Object_Boxed__SetDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_ADT_Storable__ObjectDesc,&_td_Object_Boxed__ObjectDesc,&_td_Object_Boxed__SetDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object_Boxed__SetDesc_ToString,(void*)Object_Boxed__SetDesc_Equals,(void*)Object_Boxed__SetDesc_HashCode,(void*)Object_Boxed__SetDesc_Store,(void*)Object_Boxed__SetDesc_Load,(void*)Object_Boxed__SetDesc_Cmp,(void*)Object_Boxed__SetDesc_INIT,(void*)Object_Boxed__SetDesc_ToLongInt}, NULL, &_mid, "SetDesc", 4, 4, (1<<RT0__flagAtomic), RT0__strRecord };
RT0__StructDesc _td_Object_Boxed__String = { (RT0__Struct[]){&_td_Object_Boxed__StringDesc}, NULL, NULL, &_mid, "String", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Object_Boxed__StringDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_ADT_Storable__ObjectDesc,&_td_Object_Boxed__ObjectDesc,&_td_Object_Boxed__StringDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object_Boxed__StringDesc_ToString,(void*)Object_Boxed__StringDesc_Equals,(void*)Object_Boxed__StringDesc_HashCode,(void*)Object_Boxed__StringDesc_Store,(void*)Object_Boxed__StringDesc_Load,(void*)Object_Boxed__StringDesc_Cmp,(void*)Object_Boxed__StringDesc_INIT}, NULL, &_mid, "StringDesc", 4, 4, 0, RT0__strRecord };
RT0__StructDesc _td_Object_Boxed__3133 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_Object_Boxed__4835 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_Object_Boxed__5874 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 10, 10, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_Object_Boxed__7398 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_Object_Boxed__7981 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_Object_Boxed__9441 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 128, 128, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_Object_Boxed__11750 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 131, 131, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_Object_Boxed__11839 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 8, 8, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_Object_Boxed__13797 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 2, 2, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_Object_Boxed__14375 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"Object:Boxed", (RT0__Struct[]) { &_td_Object_Boxed__Object, &_td_Object_Boxed__ObjectDesc, &_td_Object_Boxed__Boolean, &_td_Object_Boxed__BooleanDesc, &_td_Object_Boxed__LongInt, &_td_Object_Boxed__LongIntDesc, &_td_Object_Boxed__LongReal, &_td_Object_Boxed__LongRealDesc, &_td_Object_Boxed__Set, &_td_Object_Boxed__SetDesc, &_td_Object_Boxed__String, &_td_Object_Boxed__StringDesc, NULL }, 0 };

extern void OOC_Object_Boxed_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_IntStr_open(&_mid);
    OOC_RealStr_open(&_mid);
    OOC_LRealStr_open(&_mid);
    OOC_Strings_open(&_mid);
    OOC_HashCode_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_IO_open(&_mid);
    OOC_ADT_Storable_open(&_mid);
    OOC_ADT_StringBuffer_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_Object_Boxed_init();
  }
  _mid.openCount++;
}
extern void OOC_Object_Boxed_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_Object_Boxed_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_IntStr_close(&_mid);
    OOC_RealStr_close(&_mid);
    OOC_LRealStr_close(&_mid);
    OOC_Strings_close(&_mid);
    OOC_HashCode_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_IO_close(&_mid);
    OOC_ADT_Storable_close(&_mid);
    OOC_ADT_StringBuffer_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
