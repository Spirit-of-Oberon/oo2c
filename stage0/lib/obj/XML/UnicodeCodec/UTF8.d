#include <XML/UnicodeCodec/UTF8.oh>
XML_UnicodeCodec_UTF8__Factory XML_UnicodeCodec_UTF8__factory;
static void XML_UnicodeCodec_UTF8__Init(XML_UnicodeCodec_UTF8__Codec codec, OOC_INT8 bom);
static XML_UnicodeCodec_UTF8__Codec XML_UnicodeCodec_UTF8__New(OOC_INT8 bom);
static void XML_UnicodeCodec_UTF8__InitFactory(XML_UnicodeCodec_UTF8__Factory f);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_XML_UnicodeCodec_UTF8__Codec = { (RT0__Struct[]){&_td_XML_UnicodeCodec_UTF8__CodecDesc}, NULL, NULL, &_mid, "Codec", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_XML_UnicodeCodec_UTF8__CodecDesc = { (RT0__Struct[]){&_td_XML_UnicodeCodec__CodecDesc,&_td_XML_UnicodeCodec_UTF8__CodecDesc}, (void*[]){(void*)XML_UnicodeCodec_UTF8__CodecDesc_Decode,(void*)XML_UnicodeCodec_UTF8__CodecDesc_Encode,(void*)XML_UnicodeCodec__CodecDesc_EncodeBOM}, NULL, &_mid, "CodecDesc", 8, 1, (1<<RT0__flagAtomic), RT0__strRecord };
RT0__StructDesc _td_XML_UnicodeCodec_UTF8__Factory = { (RT0__Struct[]){&_td_XML_UnicodeCodec_UTF8__FactoryDesc}, NULL, NULL, &_mid, "Factory", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_XML_UnicodeCodec_UTF8__FactoryDesc = { (RT0__Struct[]){&_td_XML_UnicodeCodec__FactoryDesc,&_td_XML_UnicodeCodec_UTF8__FactoryDesc}, (void*[]){(void*)XML_UnicodeCodec_UTF8__FactoryDesc_NewCodec,(void*)XML_UnicodeCodec_UTF8__FactoryDesc_NewCodecBOM,(void*)XML_UnicodeCodec_UTF8__FactoryDesc_GetEncodingName}, NULL, &_mid, "FactoryDesc", 1, 1, (1<<RT0__flagAtomic), RT0__strRecord };
RT0__StructDesc _td_XML_UnicodeCodec_UTF8__793 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_XML_UnicodeCodec_UTF8__919 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 2, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_XML_UnicodeCodec_UTF8__6896 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 2, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_XML_UnicodeCodec_UTF8__7026 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_XML_UnicodeCodec_UTF8__10992 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_XML_UnicodeCodec_UTF8__11541 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"XML:UnicodeCodec:UTF8", (RT0__Struct[]) { &_td_XML_UnicodeCodec_UTF8__Codec, &_td_XML_UnicodeCodec_UTF8__CodecDesc, &_td_XML_UnicodeCodec_UTF8__Factory, &_td_XML_UnicodeCodec_UTF8__FactoryDesc, NULL } };

extern void OOC_XML_UnicodeCodec_UTF8_init0() {
  RT0__RegisterModule(&_mid);
  OOC_XML_UnicodeCodec_UTF8_init();
}

/* --- */
