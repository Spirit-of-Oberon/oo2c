#include <ADT/Storable.d>
#include <__oo2c.h>
#include <setjmp.h>

void ADT_Storable__RaiseTypeError(Object__String msg) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)RT0__NewObject(_td_ADT_Storable__TypeError.baseTypes[0]);
  i1 = (OOC_INT32)msg;
  IO__ErrorDesc_INIT((IO__Error)i0, (Object__String)i1);
  Exception__Raise((void*)i0);
  
  ;
}

void ADT_Storable__ObjectDesc_Store(ADT_Storable__Object obj, ADT_Storable__Writer w) {

  return;
  ;
}

void ADT_Storable__ObjectDesc_Load(ADT_Storable__Object obj, ADT_Storable__Reader r) {

  return;
  ;
}

void ADT_Storable__WriterDesc_INIT(ADT_Storable__Writer w, IO__ByteChannel ch) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)ch;
  i1 = (OOC_INT32)w;
  IO_BinaryRider__WriterDesc_INIT((IO_BinaryRider__Writer)i1, (IO__ByteChannel)i0, 1);
  return;
  ;
}

void ADT_Storable__ReaderDesc_INIT(ADT_Storable__Reader r, IO__ByteChannel ch) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)ch;
  i1 = (OOC_INT32)r;
  IO_BinaryRider__ReaderDesc_INIT((IO_BinaryRider__Reader)i1, (IO__ByteChannel)i0, 1);
  return;
  ;
}

void ADT_Storable__WriterDesc_WriteObject(ADT_Storable__Writer w, Object__Object obj) {

  return;
  ;
}

void ADT_Storable__WriterDesc_Disconnect(ADT_Storable__Writer w) {

  return;
  ;
}

void ADT_Storable__ReaderDesc_ReadObject(ADT_Storable__Reader r, Object__Object *obj) {

  return;
  ;
}

void ADT_Storable__ReaderDesc_Disconnect(ADT_Storable__Reader r) {

  return;
  ;
}

void OOC_ADT_Storable_init(void) {

  return;
  ;
}

void OOC_ADT_Storable_destroy(void) {
}

/* --- */
