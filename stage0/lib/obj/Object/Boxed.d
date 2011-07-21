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
Object_Boxed__LongReal Object_Boxed__zeroLongReal;
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
RT0__StructDesc _td_Object_Boxed__3083 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_Object_Boxed__4785 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_Object_Boxed__5824 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 10, 10, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_Object_Boxed__7348 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_Object_Boxed__7931 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_Object_Boxed__9391 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 128, 128, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_Object_Boxed__11700 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 131, 131, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_Object_Boxed__11789 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 8, 8, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_Object_Boxed__13747 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 2, 2, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_Object_Boxed__14325 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"Object:Boxed", (RT0__Struct[]) { &_td_Object_Boxed__Object, &_td_Object_Boxed__ObjectDesc, &_td_Object_Boxed__Boolean, &_td_Object_Boxed__BooleanDesc, &_td_Object_Boxed__LongInt, &_td_Object_Boxed__LongIntDesc, &_td_Object_Boxed__LongReal, &_td_Object_Boxed__LongRealDesc, &_td_Object_Boxed__Set, &_td_Object_Boxed__SetDesc, &_td_Object_Boxed__String, &_td_Object_Boxed__StringDesc, NULL } };

extern void OOC_Object_Boxed_init0() {
  RT0__RegisterModule(&_mid);
  OOC_Object_Boxed_init();
}

/* --- */
