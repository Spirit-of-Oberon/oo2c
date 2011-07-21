#include <ADT/Storable.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_ADT_Storable__Object = { (RT0__Struct[]){&_td_ADT_Storable__ObjectDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"Object", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_ADT_Storable__ObjectDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_ADT_Storable__ObjectDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)ADT_Storable__ObjectDesc_Store,(void*)ADT_Storable__ObjectDesc_Load}, NULL, &_mid, (OOC_CHAR8*)"ObjectDesc", 0, 2, (1<<RT0__flagAtomic), RT0__strRecord };
RT0__StructDesc _td_ADT_Storable__Reader = { (RT0__Struct[]){&_td_ADT_Storable__ReaderDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"Reader", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_ADT_Storable__ReaderDesc = { (RT0__Struct[]){&_td_IO_BinaryRider__ReaderDesc,&_td_ADT_Storable__ReaderDesc}, (void*[]){(void*)IO_BinaryRider__ReaderDesc_SetPos,(void*)IO_BinaryRider__ReaderDesc_ReadBytes,(void*)IO_BinaryRider__ReaderDesc_ReadBytesOrdered,(void*)IO_BinaryRider__ReaderDesc_ReadBool,(void*)IO_BinaryRider__ReaderDesc_ReadChar,(void*)IO_BinaryRider__ReaderDesc_ReadLChar,(void*)IO_BinaryRider__ReaderDesc_ReadString,(void*)IO_BinaryRider__ReaderDesc_ReadLString,(void*)IO_BinaryRider__ReaderDesc_ReadSInt,(void*)IO_BinaryRider__ReaderDesc_ReadInt,(void*)IO_BinaryRider__ReaderDesc_ReadLInt,(void*)IO_BinaryRider__ReaderDesc_ReadNum,(void*)IO_BinaryRider__ReaderDesc_ReadReal,(void*)IO_BinaryRider__ReaderDesc_ReadLReal,(void*)IO_BinaryRider__ReaderDesc_ReadSet,(void*)IO_BinaryRider__ReaderDesc_ReadStr,(void*)IO_BinaryRider__ReaderDesc_SetByteOrder,(void*)ADT_Storable__ReaderDesc_INIT,(void*)ADT_Storable__ReaderDesc_ReadObject,(void*)ADT_Storable__ReaderDesc_Disconnect}, NULL, &_mid, (OOC_CHAR8*)"ReaderDesc", 8, 1, 0, RT0__strRecord };
RT0__StructDesc _td_ADT_Storable__Writer = { (RT0__Struct[]){&_td_ADT_Storable__WriterDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"Writer", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_ADT_Storable__WriterDesc = { (RT0__Struct[]){&_td_IO_BinaryRider__WriterDesc,&_td_ADT_Storable__WriterDesc}, (void*[]){(void*)IO_BinaryRider__WriterDesc_SetPos,(void*)IO_BinaryRider__WriterDesc_WriteBytes,(void*)IO_BinaryRider__WriterDesc_WriteOrdered,(void*)IO_BinaryRider__WriterDesc_WriteChar,(void*)IO_BinaryRider__WriterDesc_WriteBool,(void*)IO_BinaryRider__WriterDesc_WriteLChar,(void*)IO_BinaryRider__WriterDesc_WriteString,(void*)IO_BinaryRider__WriterDesc_WriteLString,(void*)IO_BinaryRider__WriterDesc_WriteSInt,(void*)IO_BinaryRider__WriterDesc_WriteInt,(void*)IO_BinaryRider__WriterDesc_WriteLInt,(void*)IO_BinaryRider__WriterDesc_WriteNum,(void*)IO_BinaryRider__WriterDesc_WriteReal,(void*)IO_BinaryRider__WriterDesc_WriteLReal,(void*)IO_BinaryRider__WriterDesc_WriteSet,(void*)IO_BinaryRider__WriterDesc_WriteStr,(void*)IO_BinaryRider__WriterDesc_SetByteOrder,(void*)ADT_Storable__WriterDesc_INIT,(void*)ADT_Storable__WriterDesc_WriteObject,(void*)ADT_Storable__WriterDesc_Disconnect}, NULL, &_mid, (OOC_CHAR8*)"WriterDesc", 8, 1, 0, RT0__strRecord };
RT0__StructDesc _td_ADT_Storable__TypeError = { (RT0__Struct[]){&_td_ADT_Storable__TypeErrorDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"TypeError", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_ADT_Storable__TypeErrorDesc = { (RT0__Struct[]){&_td_Exception__ExceptionDesc,&_td_Exception__CheckedDesc,&_td_IO__ErrorDesc,&_td_ADT_Storable__TypeErrorDesc}, (void*[]){(void*)IO__ErrorDesc_INIT,(void*)Exception__ExceptionDesc_GetMessage,(void*)Exception__ExceptionDesc_WriteBacktrace,(void*)Exception__ExceptionDesc_Name}, NULL, &_mid, (OOC_CHAR8*)"TypeErrorDesc", 92, 3, 0, RT0__strRecord };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"ADT:Storable", (RT0__Struct[]) { &_td_ADT_Storable__Object, &_td_ADT_Storable__ObjectDesc, &_td_ADT_Storable__Reader, &_td_ADT_Storable__ReaderDesc, &_td_ADT_Storable__Writer, &_td_ADT_Storable__WriterDesc, &_td_ADT_Storable__TypeError, &_td_ADT_Storable__TypeErrorDesc, NULL }, 0 };

extern void OOC_ADT_Storable_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_Object_open(&_mid);
    OOC_IO_open(&_mid);
    OOC_IO_BinaryRider_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_ADT_Storable_init();
  }
  _mid.openCount++;
}
extern void OOC_ADT_Storable_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_ADT_Storable_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_Object_close(&_mid);
    OOC_IO_close(&_mid);
    OOC_IO_BinaryRider_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
