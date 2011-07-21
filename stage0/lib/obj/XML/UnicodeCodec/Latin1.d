#include <XML/UnicodeCodec/Latin1.oh>
XML_UnicodeCodec_Latin1__Factory XML_UnicodeCodec_Latin1__factory;
static void XML_UnicodeCodec_Latin1__Init(XML_UnicodeCodec_Latin1__Codec codec, OOC_INT8 bom);
static XML_UnicodeCodec_Latin1__Codec XML_UnicodeCodec_Latin1__New(OOC_INT8 bom);
static void XML_UnicodeCodec_Latin1__InitFactory(XML_UnicodeCodec_Latin1__Factory f);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_XML_UnicodeCodec_Latin1__Codec = { (RT0__Struct[]){&_td_XML_UnicodeCodec_Latin1__CodecDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"Codec", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_XML_UnicodeCodec_Latin1__CodecDesc = { (RT0__Struct[]){&_td_XML_UnicodeCodec__CodecDesc,&_td_XML_UnicodeCodec_Latin1__CodecDesc}, (void*[]){(void*)XML_UnicodeCodec_Latin1__CodecDesc_Decode,(void*)XML_UnicodeCodec_Latin1__CodecDesc_Encode,(void*)XML_UnicodeCodec__CodecDesc_EncodeBOM}, NULL, &_mid, (OOC_CHAR8*)"CodecDesc", 8, 1, (1<<RT0__flagAtomic), RT0__strRecord };
RT0__StructDesc _td_XML_UnicodeCodec_Latin1__Factory = { (RT0__Struct[]){&_td_XML_UnicodeCodec_Latin1__FactoryDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"Factory", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_XML_UnicodeCodec_Latin1__FactoryDesc = { (RT0__Struct[]){&_td_XML_UnicodeCodec__FactoryDesc,&_td_XML_UnicodeCodec_Latin1__FactoryDesc}, (void*[]){(void*)XML_UnicodeCodec_Latin1__FactoryDesc_NewCodec,(void*)XML_UnicodeCodec_Latin1__FactoryDesc_NewCodecBOM,(void*)XML_UnicodeCodec_Latin1__FactoryDesc_GetEncodingName}, NULL, &_mid, (OOC_CHAR8*)"FactoryDesc", 1, 1, (1<<RT0__flagAtomic), RT0__strRecord };
RT0__StructDesc _td_XML_UnicodeCodec_Latin1__851 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_XML_UnicodeCodec_Latin1__977 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 2, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_XML_UnicodeCodec_Latin1__1512 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 2, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_XML_UnicodeCodec_Latin1__1642 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_XML_UnicodeCodec_Latin1__3487 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_XML_UnicodeCodec_Latin1__3770 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"XML:UnicodeCodec:Latin1", (RT0__Struct[]) { &_td_XML_UnicodeCodec_Latin1__Codec, &_td_XML_UnicodeCodec_Latin1__CodecDesc, &_td_XML_UnicodeCodec_Latin1__Factory, &_td_XML_UnicodeCodec_Latin1__FactoryDesc, NULL }, 0 };

extern void OOC_XML_UnicodeCodec_Latin1_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_XML_UnicodeCodec_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_XML_UnicodeCodec_Latin1_init();
  }
  _mid.openCount++;
}
extern void OOC_XML_UnicodeCodec_Latin1_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_XML_UnicodeCodec_Latin1_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_XML_UnicodeCodec_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
