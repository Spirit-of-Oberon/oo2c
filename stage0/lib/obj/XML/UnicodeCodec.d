#include <XML/UnicodeCodec.oh>
#include <Strings.oh>
typedef struct XML_UnicodeCodec__NodeDesc *XML_UnicodeCodec__Node;
typedef struct XML_UnicodeCodec__NodeDesc {
  XML_UnicodeCodec__Node next;
  OOC_CHAR8 *name;
  XML_UnicodeCodec__Factory factory;
} XML_UnicodeCodec__NodeDesc;
static XML_UnicodeCodec__Node XML_UnicodeCodec__factoryList;

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_XML_UnicodeCodec__Factory = { (RT0__Struct[]){&_td_XML_UnicodeCodec__FactoryDesc}, NULL, NULL, &_mid, "Factory", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_XML_UnicodeCodec__FactoryDesc = { (RT0__Struct[]){&_td_XML_UnicodeCodec__FactoryDesc}, (void*[]){(void*)XML_UnicodeCodec__FactoryDesc_NewCodec,(void*)XML_UnicodeCodec__FactoryDesc_NewCodecBOM,(void*)XML_UnicodeCodec__FactoryDesc_GetEncodingName}, NULL, &_mid, "FactoryDesc", 1, 0, (1<<RT0__flagAtomic), RT0__strRecord };
RT0__StructDesc _td_XML_UnicodeCodec__Codec = { (RT0__Struct[]){&_td_XML_UnicodeCodec__CodecDesc}, NULL, NULL, &_mid, "Codec", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_XML_UnicodeCodec__CodecDesc = { (RT0__Struct[]){&_td_XML_UnicodeCodec__CodecDesc}, (void*[]){(void*)XML_UnicodeCodec__CodecDesc_Decode,(void*)XML_UnicodeCodec__CodecDesc_Encode,(void*)XML_UnicodeCodec__CodecDesc_EncodeBOM}, NULL, &_mid, "CodecDesc", 8, 0, (1<<RT0__flagAtomic), RT0__strRecord };
RT0__StructDesc _td_XML_UnicodeCodec__Node = { (RT0__Struct[]){&_td_XML_UnicodeCodec__NodeDesc}, NULL, NULL, &_mid, "Node", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_XML_UnicodeCodec__NodeDesc = { (RT0__Struct[]){&_td_XML_UnicodeCodec__NodeDesc}, (void*[]){}, NULL, &_mid, "NodeDesc", 12, 0, 0, RT0__strRecord };
RT0__StructDesc _td_XML_UnicodeCodec__3150 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_XML_UnicodeCodec__3139 = { (RT0__Struct[]){&_td_XML_UnicodeCodec__3150}, NULL, NULL, &_mid, NULL, 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_XML_UnicodeCodec__3404 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_XML_UnicodeCodec__3552 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 2, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_XML_UnicodeCodec__7142 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 2, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_XML_UnicodeCodec__7294 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_XML_UnicodeCodec__10835 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_XML_UnicodeCodec__11666 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 4, 2, (1<<RT0__flagAtomic), RT0__strArray };
RT0__StructDesc _td_XML_UnicodeCodec__12512 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_XML_UnicodeCodec__14104 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_XML_UnicodeCodec__14239 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_XML_UnicodeCodec__14953 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_XML_UnicodeCodec__15477 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"XML:UnicodeCodec", (RT0__Struct[]) { &_td_XML_UnicodeCodec__Factory, &_td_XML_UnicodeCodec__FactoryDesc, &_td_XML_UnicodeCodec__Codec, &_td_XML_UnicodeCodec__CodecDesc, &_td_XML_UnicodeCodec__Node, &_td_XML_UnicodeCodec__NodeDesc, NULL } };

extern void OOC_XML_UnicodeCodec_init0() {
  RT0__RegisterModule(&_mid);
  OOC_XML_UnicodeCodec_init();
}

/* --- */
