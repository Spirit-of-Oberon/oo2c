#include <IO.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_IO__Channel = { (RT0__Struct[]){&_td_IO__ChannelDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"Channel", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_IO__SelectionKey = { (RT0__Struct[]){&_td_IO__SelectionKeyDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"SelectionKey", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_IO__2052 = { (RT0__Struct[]){&_td_IO__SelectionKey}, NULL, NULL, &_mid, NULL, 4, 1, 0, RT0__strOpenArray };
RT0__StructDesc _td_IO__SelectionKeyList = { (RT0__Struct[]){&_td_IO__2052}, NULL, NULL, &_mid, (OOC_CHAR8*)"SelectionKeyList", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_IO__ChannelDesc = { (RT0__Struct[]){&_td_IO__ChannelDesc}, (void*[]){(void*)IO__ChannelDesc_INIT,(void*)IO__ChannelDesc_FileDescriptor,(void*)IO__ChannelDesc_RegisterWithSelector,(void*)IO__ChannelDesc_KeyForSelector,(void*)IO__ChannelDesc_SetBlocking,(void*)IO__ChannelDesc_Close,(void*)IO__ChannelDesc_CloseAndRegister,(void*)IO__ChannelDesc_SetPos}, NULL, &_mid, (OOC_CHAR8*)"ChannelDesc", 8, 0, 0, RT0__strRecord };
RT0__StructDesc _td_IO__ByteChannel = { (RT0__Struct[]){&_td_IO__ByteChannelDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"ByteChannel", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_IO__ByteChannelDesc = { (RT0__Struct[]){&_td_IO__ChannelDesc,&_td_IO__ByteChannelDesc}, (void*[]){(void*)IO__ByteChannelDesc_INIT,(void*)IO__ChannelDesc_FileDescriptor,(void*)IO__ChannelDesc_RegisterWithSelector,(void*)IO__ChannelDesc_KeyForSelector,(void*)IO__ChannelDesc_SetBlocking,(void*)IO__ChannelDesc_Close,(void*)IO__ChannelDesc_CloseAndRegister,(void*)IO__ChannelDesc_SetPos,(void*)IO__ByteChannelDesc_Read,(void*)IO__ByteChannelDesc_Write,(void*)IO__ByteChannelDesc_Flush,(void*)IO__ByteChannelDesc_TransferTo}, NULL, &_mid, (OOC_CHAR8*)"ByteChannelDesc", 8, 1, 0, RT0__strRecord };
RT0__StructDesc _td_IO__Selector = { (RT0__Struct[]){&_td_IO__SelectorDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"Selector", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_IO__SelectorDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_IO__SelectorDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)IO__SelectorDesc_INIT,(void*)IO__SelectorDesc_Close,(void*)IO__SelectorDesc_Select,(void*)IO__SelectorDesc_NextKey,(void*)IO__SelectorDesc_AddSelectionKey,(void*)IO__SelectorDesc_RemoveSelectionKey,(void*)IO__SelectorDesc_RemoveCanceled}, NULL, &_mid, (OOC_CHAR8*)"SelectorDesc", 8, 2, 0, RT0__strRecord };
RT0__StructDesc _td_IO__SelectionKeyDesc = { (RT0__Struct[]){&_td_RT0__ObjectDesc,&_td_Object__ObjectDesc,&_td_IO__SelectionKeyDesc}, (void*[]){(void*)RT0__ObjectDesc_Finalize,(void*)Object__ObjectDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)IO__SelectionKeyDesc_INIT,(void*)IO__SelectionKeyDesc_Attach,(void*)IO__SelectionKeyDesc_Cancel,(void*)IO__SelectionKeyDesc_SetInterestOps}, NULL, &_mid, (OOC_CHAR8*)"SelectionKeyDesc", 28, 2, 0, RT0__strRecord };
RT0__StructDesc _td_IO__Error = { (RT0__Struct[]){&_td_IO__ErrorDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"Error", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_IO__ErrorDesc = { (RT0__Struct[]){&_td_Exception__ExceptionDesc,&_td_Exception__CheckedDesc,&_td_IO__ErrorDesc}, (void*[]){(void*)IO__ErrorDesc_INIT,(void*)Exception__ExceptionDesc_GetMessage,(void*)Exception__ExceptionDesc_WriteBacktrace,(void*)Exception__ExceptionDesc_Name}, NULL, &_mid, (OOC_CHAR8*)"ErrorDesc", 92, 2, 0, RT0__strRecord };
RT0__StructDesc _td_IO__FileNotFound = { (RT0__Struct[]){&_td_IO__FileNotFoundDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"FileNotFound", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_IO__FileNotFoundDesc = { (RT0__Struct[]){&_td_Exception__ExceptionDesc,&_td_Exception__CheckedDesc,&_td_IO__ErrorDesc,&_td_IO__FileNotFoundDesc}, (void*[]){(void*)IO__ErrorDesc_INIT,(void*)Exception__ExceptionDesc_GetMessage,(void*)Exception__ExceptionDesc_WriteBacktrace,(void*)Exception__ExceptionDesc_Name}, NULL, &_mid, (OOC_CHAR8*)"FileNotFoundDesc", 92, 3, 0, RT0__strRecord };
RT0__StructDesc _td_IO__AccessDenied = { (RT0__Struct[]){&_td_IO__AccessDeniedDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"AccessDenied", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_IO__AccessDeniedDesc = { (RT0__Struct[]){&_td_Exception__ExceptionDesc,&_td_Exception__CheckedDesc,&_td_IO__ErrorDesc,&_td_IO__AccessDeniedDesc}, (void*[]){(void*)IO__ErrorDesc_INIT,(void*)Exception__ExceptionDesc_GetMessage,(void*)Exception__ExceptionDesc_WriteBacktrace,(void*)Exception__ExceptionDesc_Name}, NULL, &_mid, (OOC_CHAR8*)"AccessDeniedDesc", 92, 3, 0, RT0__strRecord };
RT0__StructDesc _td_IO__FileExists = { (RT0__Struct[]){&_td_IO__FileExistsDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"FileExists", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_IO__FileExistsDesc = { (RT0__Struct[]){&_td_Exception__ExceptionDesc,&_td_Exception__CheckedDesc,&_td_IO__ErrorDesc,&_td_IO__FileExistsDesc}, (void*[]){(void*)IO__ErrorDesc_INIT,(void*)Exception__ExceptionDesc_GetMessage,(void*)Exception__ExceptionDesc_WriteBacktrace,(void*)Exception__ExceptionDesc_Name}, NULL, &_mid, (OOC_CHAR8*)"FileExistsDesc", 92, 3, 0, RT0__strRecord };
RT0__StructDesc _td_IO__FileBusy = { (RT0__Struct[]){&_td_IO__FileBusyDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"FileBusy", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_IO__FileBusyDesc = { (RT0__Struct[]){&_td_Exception__ExceptionDesc,&_td_Exception__CheckedDesc,&_td_IO__ErrorDesc,&_td_IO__FileBusyDesc}, (void*[]){(void*)IO__ErrorDesc_INIT,(void*)Exception__ExceptionDesc_GetMessage,(void*)Exception__ExceptionDesc_WriteBacktrace,(void*)Exception__ExceptionDesc_Name}, NULL, &_mid, (OOC_CHAR8*)"FileBusyDesc", 92, 3, 0, RT0__strRecord };
RT0__StructDesc _td_IO__InvalidArgument = { (RT0__Struct[]){&_td_IO__InvalidArgumentDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"InvalidArgument", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_IO__InvalidArgumentDesc = { (RT0__Struct[]){&_td_Exception__ExceptionDesc,&_td_Exception__CheckedDesc,&_td_IO__ErrorDesc,&_td_IO__InvalidArgumentDesc}, (void*[]){(void*)IO__ErrorDesc_INIT,(void*)Exception__ExceptionDesc_GetMessage,(void*)Exception__ExceptionDesc_WriteBacktrace,(void*)Exception__ExceptionDesc_Name}, NULL, &_mid, (OOC_CHAR8*)"InvalidArgumentDesc", 92, 3, 0, RT0__strRecord };
RT0__StructDesc _td_IO__OutOfRange = { (RT0__Struct[]){&_td_IO__OutOfRangeDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"OutOfRange", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_IO__OutOfRangeDesc = { (RT0__Struct[]){&_td_Exception__ExceptionDesc,&_td_Exception__CheckedDesc,&_td_IO__ErrorDesc,&_td_IO__OutOfRangeDesc}, (void*[]){(void*)IO__ErrorDesc_INIT,(void*)Exception__ExceptionDesc_GetMessage,(void*)Exception__ExceptionDesc_WriteBacktrace,(void*)Exception__ExceptionDesc_Name}, NULL, &_mid, (OOC_CHAR8*)"OutOfRangeDesc", 92, 3, 0, RT0__strRecord };
RT0__StructDesc _td_IO__NotImplemented = { (RT0__Struct[]){&_td_IO__NotImplementedDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"NotImplemented", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_IO__NotImplementedDesc = { (RT0__Struct[]){&_td_Exception__ExceptionDesc,&_td_Exception__CheckedDesc,&_td_IO__ErrorDesc,&_td_IO__NotImplementedDesc}, (void*[]){(void*)IO__ErrorDesc_INIT,(void*)Exception__ExceptionDesc_GetMessage,(void*)Exception__ExceptionDesc_WriteBacktrace,(void*)Exception__ExceptionDesc_Name}, NULL, &_mid, (OOC_CHAR8*)"NotImplementedDesc", 92, 3, 0, RT0__strRecord };
RT0__StructDesc _td_IO__FormatError = { (RT0__Struct[]){&_td_IO__FormatErrorDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"FormatError", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_IO__FormatErrorDesc = { (RT0__Struct[]){&_td_Exception__ExceptionDesc,&_td_Exception__CheckedDesc,&_td_IO__ErrorDesc,&_td_IO__FormatErrorDesc}, (void*[]){(void*)IO__ErrorDesc_INIT,(void*)Exception__ExceptionDesc_GetMessage,(void*)Exception__ExceptionDesc_WriteBacktrace,(void*)Exception__ExceptionDesc_Name}, NULL, &_mid, (OOC_CHAR8*)"FormatErrorDesc", 92, 3, 0, RT0__strRecord };
RT0__StructDesc _td_IO__ProtocolError = { (RT0__Struct[]){&_td_IO__ProtocolErrorDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"ProtocolError", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_IO__ProtocolErrorDesc = { (RT0__Struct[]){&_td_Exception__ExceptionDesc,&_td_Exception__CheckedDesc,&_td_IO__ErrorDesc,&_td_IO__ProtocolErrorDesc}, (void*[]){(void*)IO__ErrorDesc_INIT,(void*)Exception__ExceptionDesc_GetMessage,(void*)Exception__ExceptionDesc_WriteBacktrace,(void*)Exception__ExceptionDesc_Name}, NULL, &_mid, (OOC_CHAR8*)"ProtocolErrorDesc", 92, 3, 0, RT0__strRecord };
RT0__StructDesc _td_IO__ErrorResponse = { (RT0__Struct[]){&_td_IO__ErrorResponseDesc}, NULL, NULL, &_mid, (OOC_CHAR8*)"ErrorResponse", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_IO__ErrorResponseDesc = { (RT0__Struct[]){&_td_Exception__ExceptionDesc,&_td_Exception__CheckedDesc,&_td_IO__ErrorDesc,&_td_IO__ErrorResponseDesc}, (void*[]){(void*)IO__ErrorDesc_INIT,(void*)Exception__ExceptionDesc_GetMessage,(void*)Exception__ExceptionDesc_WriteBacktrace,(void*)Exception__ExceptionDesc_Name}, NULL, &_mid, (OOC_CHAR8*)"ErrorResponseDesc", 92, 3, 0, RT0__strRecord };
RT0__StructDesc _td_IO__15171 = { (RT0__Struct[]){&RT0__byte}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_IO__16499 = { (RT0__Struct[]){&RT0__byte}, NULL, NULL, &_mid, NULL, 1, 1, (1<<RT0__flagAtomic), RT0__strOpenArray };
RT0__StructDesc _td_IO__17851 = { (RT0__Struct[]){&RT0__byte}, NULL, NULL, &_mid, NULL, 8192, 8192, (1<<RT0__flagAtomic), RT0__strArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"IO", (RT0__Struct[]) { &_td_IO__Channel, &_td_IO__SelectionKey, &_td_IO__SelectionKeyList, &_td_IO__ChannelDesc, &_td_IO__ByteChannel, &_td_IO__ByteChannelDesc, &_td_IO__Selector, &_td_IO__SelectorDesc, &_td_IO__SelectionKeyDesc, &_td_IO__Error, &_td_IO__ErrorDesc, &_td_IO__FileNotFound, &_td_IO__FileNotFoundDesc, &_td_IO__AccessDenied, &_td_IO__AccessDeniedDesc, &_td_IO__FileExists, &_td_IO__FileExistsDesc, &_td_IO__FileBusy, &_td_IO__FileBusyDesc, &_td_IO__InvalidArgument, &_td_IO__InvalidArgumentDesc, &_td_IO__OutOfRange, &_td_IO__OutOfRangeDesc, &_td_IO__NotImplemented, &_td_IO__NotImplementedDesc, &_td_IO__FormatError, &_td_IO__FormatErrorDesc, &_td_IO__ProtocolError, &_td_IO__ProtocolErrorDesc, &_td_IO__ErrorResponse, &_td_IO__ErrorResponseDesc, NULL }, 0 };

extern void OOC_IO_open(RT0__Module client) {
  if (_mid.openCount == 0) {
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);
    OOC_RT0_open(&_mid);
    OOC_Object_open(&_mid);
    OOC_Exception_open(&_mid);

    RT0__RegisterModule(&_mid);
    OOC_IO_init();
  }
  _mid.openCount++;
}
extern void OOC_IO_close(RT0__Module client) {
  _mid.openCount--;
  if (_mid.openCount == 0) { 
    OOC_IO_destroy();
    RT0__UnregisterModule(&_mid);

    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
    OOC_RT0_close(&_mid);
    OOC_Object_close(&_mid);
    OOC_Exception_close(&_mid);
  }
}

/* --- */
