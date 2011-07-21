#include <OOC/Auxiliary/WriteSymbolFile.d>
#include <__oo2c.h>
#include <setjmp.h>

void OOC_Auxiliary_WriteSymbolFile__WriteSymbolFile(OOC_Repository__Module m, OOC_SymbolTable__Module symTab, OOC_Error__List errList) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9;
  IO_Memory__Channel mem;
  IO__ByteChannel chDoc;
  OOC_SymbolTable_Builder__Builder stb;
  OOC_INT32 fp;
  IO__ByteChannel ch;
  IO_BinaryRider__Writer w;
  OOC_INT32 i;
  OOC_SymbolTable__ModuleRef mr;
  OOC_INT32 len;
  OOC_INT32 d;

  i0 = (OOC_INT32)IO_Memory__Open();
  mem = (IO_Memory__Channel)i0;
  i1 = (OOC_INT32)m;
  i2 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 547)))), OOC_Repository__ModuleDesc_GetOutputChannel)),OOC_Repository__ModuleDesc_GetOutputChannel)((OOC_Repository__Module)i1, 20, 1u);
  chDoc = (IO__ByteChannel)i2;
  i3 = (OOC_INT32)symTab;
  i4 = (OOC_INT32)OOC_SymbolTable_Exports__GetExports((OOC_SymbolTable__Module)i3, 1u);
  OOC_SymbolTable__Prune((OOC_SymbolTable__Module)i3, (ADT_Dictionary_AddressKey__Dictionary)i4);
  i4 = (OOC_INT32)OOC_SymbolTable_Builder__New();
  stb = (OOC_SymbolTable_Builder__Builder)i4;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 693)))), OOC_SymbolTable_Builder__BuilderDesc_WriteSymbolTable)),OOC_SymbolTable_Builder__BuilderDesc_WriteSymbolTable)((OOC_SymbolTable_Builder__Builder)i4, (IO__ByteChannel)i0, (IO__ByteChannel)i2, (OOC_SymbolTable__Module)i3);
  i4 = *(OOC_INT32*)((_check_pointer(i0, 764))+12);
  IO_Memory__ChannelDesc_Fingerprint((IO_Memory__Channel)i0, (void*)(OOC_INT32)&fp, 4, 0, i4);
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 786)))), OOC_Repository__ModuleDesc_GetOutputChannel)),OOC_Repository__ModuleDesc_GetOutputChannel)((OOC_Repository__Module)i1, 1, 1u);
  ch = (IO__ByteChannel)i1;
  i4 = (OOC_INT32)IO_BinaryRider__ConnectWriter((IO__ByteChannel)i1);
  w = (IO_BinaryRider__Writer)i4;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 884)))), IO_BinaryRider__WriterDesc_WriteBytes)),IO_BinaryRider__WriterDesc_WriteBytes)((IO_BinaryRider__Writer)i4, (void*)(OOC_INT32)OOC_SymbolTable_Builder__magicNumber, 5, 0, 4);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 951)))), IO_BinaryRider__WriterDesc_WriteBytes)),IO_BinaryRider__WriterDesc_WriteBytes)((IO_BinaryRider__Writer)i4, (void*)(OOC_INT32)&fp, 4, 0, 4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 1279))+72);
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 1293)), 0);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 1259)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i4, i5);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 1326))+72);
  i = 0;
  i5 = OOC_ARRAY_LENGTH((_check_pointer(i5, 1340)), 0);
  i6 = 0<i5;
  if (!i6) goto l8;
  i6=0;
l3_loop:
  i7 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 1366))+72);
  i7 = _check_pointer(i7, 1380);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = (OOC_INT32)*(OOC_INT32*)(i7+(_check_index(i6, i8, OOC_UINT32, 1380))*4);
  mr = (OOC_SymbolTable__ModuleRef)i7;
  i8 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i7, 1415));
  i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i7, 1415));
  i9 = OOC_ARRAY_LENGTH((_check_pointer(i9, 1420)), 0);
  i8 = Strings__Length((void*)(_check_pointer(i8, 1420)), i9);
  len = i8;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 1431)))), IO_BinaryRider__WriterDesc_WriteNum)),IO_BinaryRider__WriterDesc_WriteNum)((IO_BinaryRider__Writer)i4, i8);
  i9 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i7, 1468));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 1454)))), IO_BinaryRider__WriterDesc_WriteBytes)),IO_BinaryRider__WriterDesc_WriteBytes)((IO_BinaryRider__Writer)i4, (void*)(_check_pointer(i9, 1473)), (-1), 0, i8);
  i7 = *(OOC_INT32*)((_check_pointer(i7, 1499))+4);
  fp = i7;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i4, 1520)))), IO_BinaryRider__WriterDesc_WriteBytes)),IO_BinaryRider__WriterDesc_WriteBytes)((IO_BinaryRider__Writer)i4, (void*)(OOC_INT32)&fp, 4, 0, 4);
  i6 = i6+1;
  i = i6;
  i7 = i6<i5;
  if (i7) goto l3_loop;
l8:
  IO_Memory__ChannelDesc_SetPos((IO_Memory__Channel)i0, 0);
  i3 = *(OOC_INT32*)((_check_pointer(i0, 1615))+12);
  i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1600)))), IO__ByteChannelDesc_TransferTo)),IO__ByteChannelDesc_TransferTo)((IO__ByteChannel)i0, i3, (IO__ByteChannel)i1);
  d = i0;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 1635)))), IO__ChannelDesc_CloseAndRegister)),IO__ChannelDesc_CloseAndRegister)((IO__Channel)i1);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 1665)))), IO__ChannelDesc_CloseAndRegister)),IO__ChannelDesc_CloseAndRegister)((IO__Channel)i2);
  return;
  ;
}

void OOC_OOC_Auxiliary_WriteSymbolFile_init(void) {

  return;
  ;
}

/* --- */
