#include <Object.oh>
#include <HashCode.oh>
Object__String Object__emptyString;
static Object__String8 Object__NewString8(OOC_INT32 source, OOC_INT32 length);
static Object__String16 Object__NewString16(OOC_INT32 source, OOC_INT32 length);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_Object__Object = { (RT0__Struct[]){&_td_Object__ObjectDesc}, NULL, NULL, &_mid, "Object", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Object__ObjectArray = { (RT0__Struct[]){&_td_Object__Object}, NULL, NULL, &_mid, "ObjectArray", 4, 1, 0, RT0__strOpenArray };
RT0__StructDesc _td_Object__ObjectArrayPtr = { (RT0__Struct[]){&_td_Object__ObjectArray}, NULL, NULL, &_mid, "ObjectArrayPtr", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Object__ObjectDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode}, NULL, &_mid, "ObjectDesc", 0, 1, (1<<RT0__flagAtomic), RT0__strRecord };
RT0__StructDesc _td_Object__String = { (RT0__Struct[]){&_td_Object__StringDesc}, NULL, NULL, &_mid, "String", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Object__StringArray = { (RT0__Struct[]){&_td_Object__String}, NULL, NULL, &_mid, "StringArray", 4, 1, 0, RT0__strOpenArray };
RT0__StructDesc _td_Object__StringArrayPtr = { (RT0__Struct[]){&_td_Object__StringArray}, NULL, NULL, &_mid, "StringArrayPtr", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Object__StringDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_Object__StringDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__StringDesc_ToString,(void*)Object__StringDesc_Equals,(void*)Object__StringDesc_HashCode,(void*)Object__StringDesc_Concat,(void*)Object__StringDesc_ToString8,(void*)Object__StringDesc_ToString16,(void*)Object__StringDesc_EqualsIgnoreCase,(void*)Object__StringDesc_Compare,(void*)Object__StringDesc_CharAt,(void*)Object__StringDesc_NextChar,(void*)Object__StringDesc_Substring,(void*)Object__StringDesc_Trim,(void*)Object__StringDesc_IndexOf,(void*)Object__StringDesc_LastIndexOf,(void*)Object__StringDesc_EndsWith,(void*)Object__StringDesc_StartsWith,(void*)Object__StringDesc_ToUppercaseLatin1}, NULL, &_mid, "StringDesc", 4, 2, (1<<RT0__flagAtomic), RT0__strRecord };
RT0__StructDesc _td_Object__4318 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_Object__CharsLatin1 = { (RT0__Struct[]){&_td_Object__4318}, NULL, NULL, &_mid, "CharsLatin1", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Object__4515 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 2, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_Object__CharsUTF16 = { (RT0__Struct[]){&_td_Object__4515}, NULL, NULL, &_mid, "CharsUTF16", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Object__String8 = { (RT0__Struct[]){&_td_Object__String8Desc}, NULL, NULL, &_mid, "String8", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Object__String8Desc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_Object__StringDesc,&_td_Object__String8Desc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__StringDesc_ToString,(void*)Object__String8Desc_Equals,(void*)Object__String8Desc_HashCode,(void*)Object__StringDesc_Concat,(void*)Object__String8Desc_ToString8,(void*)Object__String8Desc_ToString16,(void*)Object__String8Desc_EqualsIgnoreCase,(void*)Object__String8Desc_Compare,(void*)Object__String8Desc_CharAt,(void*)Object__String8Desc_NextChar,(void*)Object__String8Desc_Substring,(void*)Object__String8Desc_Trim,(void*)Object__String8Desc_IndexOf,(void*)Object__String8Desc_LastIndexOf,(void*)Object__StringDesc_EndsWith,(void*)Object__StringDesc_StartsWith,(void*)Object__String8Desc_ToUppercaseLatin1,(void*)Object__String8Desc_CharsLatin1}, NULL, &_mid, "String8Desc", 8, 3, 0, RT0__strRecord };
RT0__StructDesc _td_Object__String16 = { (RT0__Struct[]){&_td_Object__String16Desc}, NULL, NULL, &_mid, "String16", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Object__String16Desc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_Object__StringDesc,&_td_Object__String16Desc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__StringDesc_ToString,(void*)Object__String16Desc_Equals,(void*)Object__String16Desc_HashCode,(void*)Object__StringDesc_Concat,(void*)Object__String16Desc_ToString8,(void*)Object__String16Desc_ToString16,(void*)Object__String16Desc_EqualsIgnoreCase,(void*)Object__String16Desc_Compare,(void*)Object__String16Desc_CharAt,(void*)Object__String16Desc_NextChar,(void*)Object__String16Desc_Substring,(void*)Object__String16Desc_Trim,(void*)Object__String16Desc_IndexOf,(void*)Object__String16Desc_LastIndexOf,(void*)Object__StringDesc_EndsWith,(void*)Object__StringDesc_StartsWith,(void*)Object__String16Desc_ToUppercaseLatin1,(void*)Object__String16Desc_CharsUTF16}, NULL, &_mid, "String16Desc", 8, 3, 0, RT0__strRecord };
RT0__StructDesc _td_Object__5761 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_Object__6227 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 280, 280, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_Object__11232 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_Object__11605 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_Object__12271 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 2, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_Object__12823 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 2, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_Object__14591 = { (RT0__Struct[]){&RT0__ucs4char}, NULL, NULL, &_mid, NULL, 4, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_Object__15669 = { (RT0__Struct[]){&RT0__ucs4char}, NULL, NULL, &_mid, NULL, 4, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"Object", (RT0__Struct[]) { &_td_Object__Object, &_td_Object__ObjectArray, &_td_Object__ObjectArrayPtr, &_td_Object__ObjectDesc, &_td_Object__String, &_td_Object__StringArray, &_td_Object__StringArrayPtr, &_td_Object__StringDesc, &_td_Object__CharsLatin1, &_td_Object__CharsUTF16, &_td_Object__String8, &_td_Object__String8Desc, &_td_Object__String16, &_td_Object__String16Desc, NULL }, 0 };

extern void OOC_Object_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_RT0_open(&_mid);
    OOC_HashCode_open(&_mid);
    OOC_RT0_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_Object_init();
  }
  _mid.openCount++;
}
extern void OOC_Object_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_Object_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_RT0_close(&_mid);
    OOC_HashCode_close(&_mid);
    OOC_RT0_close(&_mid);
  }
}

/* --- */
