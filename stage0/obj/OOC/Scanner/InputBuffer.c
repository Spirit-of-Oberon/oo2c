#include <OOC/Scanner/InputBuffer.d>
#include <__oo2c.h>
#include <setjmp.h>

OOC_CHAR8 OOC_Scanner_InputBuffer__BufferDesc_NextBlock(OOC_Scanner_InputBuffer__Buffer b) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 len;
  OOC_Scanner_InputBuffer__CharArray nChars;
  OOC_INT32 d;

  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3703))+4);
  i1 = _check_pointer(i1, 3710);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 3712))+12);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_UINT8*)(i1+(_check_index(i2, i3, OOC_UINT32, 3710)));
  _assert((i1==0u), 127, 3694);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3754))+4);
  i1 = _check_pointer(i1, 3761);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 3763))+12);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_UINT8*)(i1+(_check_index(i2, i3, OOC_UINT32, 3761)));
  _assert((i1==0u), 127, 3745);
  i1 = *(OOC_INT32*)((_check_pointer(i0, 3801))+16);
  i1 = i1>=4096;
  if (!i1) goto l8;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 3896))+12);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 3913))+16);
  i1 = i1-i2;
  len = i1;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 3945))+16);
  i2 = i1<i2;
  if (!i2) goto l8;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4224))+4);
  i2 = _check_pointer(i2, 4231);
  i3 = *(OOC_INT32*)((_check_pointer(i0, 4233))+16);
  i4 = OOC_ARRAY_LENGTH(i2, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4285))+4);
  _move_block((i2+(_check_index(i3, i4, OOC_UINT32, 4231))),(_check_pointer(i0, 4292)),(i1+1));
  i0 = (OOC_INT32)b;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 4339))+8);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 4358))+16);
  *(OOC_INT32*)((_check_pointer(i0, 4339))+8) = (i1+i2);
  i1 = len;
  *(OOC_INT32*)((_check_pointer(i0, 4383))+12) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 4414))+16) = 0;
  
l8:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4465))+4);
  i1 = _check_pointer(i1, 4472);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 4474))+12);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_UINT8*)(i1+(_check_index(i2, i3, OOC_UINT32, 4472)));
  _assert((i1==0u), 127, 4456);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4553))+4);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 4517))+12);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 4560)), 0);
  i1 = (i2+4096)>=i1;
  if (!i1) goto l17;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4680))+4);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 4687)), 0);
  
l12_loop:
  i1 = i1+4096;
  len = i1;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 4750))+12);
  i2 = (i2+4096)<i1;
  if (!i2) goto l12_loop;
l16:
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_Scanner_InputBuffer__CharArray.baseTypes[0], i1);
  nChars = (OOC_Scanner_InputBuffer__CharArray)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4842))+4);
  i0 = *(OOC_INT32*)((_check_pointer(i0, 4914))+12);
  _move_block((_check_pointer(i2, 4849)),(_check_pointer(i1, 4890)),(i0+1));
  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)nChars;
  *(OOC_INT32*)((_check_pointer(i0, 4939))+4) = i1;
  
l17:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5080))+4);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 5093))+12);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 5087)), 0);
  i1 = (((i1-i2)-1)>>12)*4096;
  len = i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5182))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5170));
  i4 = *(OOC_INT32*)((_check_pointer(i0, 5193))+12);
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5170));
  i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 5173)))), IO__ByteChannelDesc_Read)),IO__ByteChannelDesc_Read)((IO__ByteChannel)i5, (void*)(_check_pointer(i2, 5189)), (-1), i4, i1);
  d = i1;
  i2 = i1<=0;
  if (i2) goto l20;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 5328))+12);
  *(OOC_INT32*)((_check_pointer(i0, 5328))+12) = (i2+i1);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5354))+4);
  i1 = _check_pointer(i1, 5361);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 5363))+12);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  *(OOC_UINT8*)(i1+(_check_index(i2, i3, OOC_UINT32, 5361))) = 0u;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5407))+4);
  i1 = _check_pointer(i1, 5414);
  i0 = *(OOC_INT32*)((_check_pointer(i0, 5416))+12);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i0 = *(OOC_UINT8*)(i1+(_check_index(i0, i2, OOC_UINT32, 5414)));
  _assert((i0==0u), 127, 5398);
  return 1u;
  goto l21;
l20:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5250))+4);
  i1 = _check_pointer(i1, 5257);
  i0 = *(OOC_INT32*)((_check_pointer(i0, 5259))+12);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i0 = *(OOC_UINT8*)(i1+(_check_index(i0, i2, OOC_UINT32, 5257)));
  _assert((i0==0u), 127, 5241);
  return 0u;
l21:
  _failed_function(3000); return 0;
  ;
}

OOC_CHAR8 OOC_Scanner_InputBuffer__BufferDesc_EndOfBuffer(OOC_Scanner_InputBuffer__Buffer b, OOC_INT32 cpos) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = cpos;
  _assert((0<=i0), 127, 5813);
  i1 = (OOC_INT32)b;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 5854))+12);
  _assert((i0<=i2), 127, 5837);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 5883))+4);
  i2 = _check_pointer(i2, 5890);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = *(OOC_UINT8*)(i2+(_check_index(i0, i3, OOC_UINT32, 5890)));
  _assert((i2==0u), 127, 5874);
  i1 = *(OOC_INT32*)((_check_pointer(i1, 5931))+12);
  return (i0==i1);
  ;
}

void OOC_Scanner_InputBuffer__BufferDesc_Close(OOC_Scanner_InputBuffer__Buffer b) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6212));
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6212));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6215)))), IO__ChannelDesc_Close)),IO__ChannelDesc_Close)((IO__Channel)i2);
  *(OOC_INT32*)(_check_pointer(i0, 6229)) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 6246))+4) = 0;
  return;
  ;
}

OOC_Scanner_InputBuffer__Buffer OOC_Scanner_InputBuffer__New(IO__ByteChannel ch, OOC_Error__List errList) {
  register OOC_INT32 i0,i1,i2;
  OOC_Scanner_InputBuffer__Buffer b;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_Scanner_InputBuffer__Buffer.baseTypes[0]);
  b = (OOC_Scanner_InputBuffer__Buffer)i0;
  i1 = (OOC_INT32)ch;
  *(OOC_INT32*)(_check_pointer(i0, 6621)) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 6637))+16) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 6662))+8) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 6690))+12) = 0;
  i1 = (OOC_INT32)errList;
  *(OOC_INT32*)((_check_pointer(i0, 6715))+20) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 6747))+4) = ((OOC_INT32)RT0__NewObject(_td_OOC_Scanner_InputBuffer__CharArray.baseTypes[0], 16352));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6776))+4);
  i1 = _check_pointer(i1, 6783);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  *(OOC_UINT8*)(i1+(_check_index(0, i2, OOC_UINT8, 6783))) = 0u;
  return (OOC_Scanner_InputBuffer__Buffer)i0;
  ;
}

void OOC_OOC_Scanner_InputBuffer_init(void) {

  return;
  ;
}

void OOC_OOC_Scanner_InputBuffer_destroy(void) {
}

/* --- */
