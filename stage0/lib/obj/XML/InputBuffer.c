#include <XML/InputBuffer.d>
#include <__oo2c.h>
#include <setjmp.h>

OOC_CHAR8 XML_InputBuffer__BufferDesc_NextBlock(XML_InputBuffer__Buffer b) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 len;
  XML_InputBuffer__CharArray nChars;
  OOC_INT32 d;

  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2725))+4);
  i1 = _check_pointer(i1, 2732);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 2734))+12);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_UINT8*)(i1+(_check_index(i2, i3, OOC_UINT32, 2732)));
  _assert((i1==0u), 127, 2716);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2776))+4);
  i1 = _check_pointer(i1, 2783);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 2785))+12);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_UINT8*)(i1+(_check_index(i2, i3, OOC_UINT32, 2783)));
  _assert((i1==0u), 127, 2767);
  i1 = *(OOC_INT32*)((_check_pointer(i0, 2823))+16);
  i1 = i1>=4096;
  if (!i1) goto l8;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 2918))+12);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 2935))+16);
  i1 = i1-i2;
  len = i1;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 2967))+16);
  i2 = i1<i2;
  if (!i2) goto l8;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3246))+4);
  i2 = _check_pointer(i2, 3253);
  i3 = *(OOC_INT32*)((_check_pointer(i0, 3255))+16);
  i4 = OOC_ARRAY_LENGTH(i2, 0);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3307))+4);
  _move_block((i2+(_check_index(i3, i4, OOC_UINT32, 3253))),(_check_pointer(i0, 3314)),(i1+1));
  i0 = (OOC_INT32)b;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 3361))+8);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 3380))+16);
  *(OOC_INT32*)((_check_pointer(i0, 3361))+8) = (i1+i2);
  i1 = len;
  *(OOC_INT32*)((_check_pointer(i0, 3405))+12) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 3436))+16) = 0;
  
l8:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3487))+4);
  i1 = _check_pointer(i1, 3494);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 3496))+12);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  i1 = *(OOC_UINT8*)(i1+(_check_index(i2, i3, OOC_UINT32, 3494)));
  _assert((i1==0u), 127, 3478);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3575))+4);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 3539))+12);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 3582)), 0);
  i1 = (i2+4096)>=i1;
  if (!i1) goto l17;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3702))+4);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 3709)), 0);
  
l12_loop:
  i1 = i1+4096;
  len = i1;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 3772))+12);
  i2 = (i2+4096)<i1;
  if (!i2) goto l12_loop;
l16:
  i1 = (OOC_INT32)RT0__NewObject(_td_XML_InputBuffer__CharArray.baseTypes[0], i1);
  nChars = (XML_InputBuffer__CharArray)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3864))+4);
  i0 = *(OOC_INT32*)((_check_pointer(i0, 3936))+12);
  _move_block((_check_pointer(i2, 3871)),(_check_pointer(i1, 3912)),(i0+1));
  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)nChars;
  *(OOC_INT32*)((_check_pointer(i0, 3961))+4) = i1;
  
l17:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4102))+4);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 4115))+12);
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 4109)), 0);
  i1 = (((i1-i2)-1)>>12)*4096;
  len = i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4204))+4);
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4192));
  i4 = *(OOC_INT32*)((_check_pointer(i0, 4215))+12);
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4192));
  i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 4195)))), IO__ByteChannelDesc_Read)),IO__ByteChannelDesc_Read)((IO__ByteChannel)i5, (void*)(_check_pointer(i2, 4211)), (-1), i4, i1);
  d = i1;
  i2 = i1==(-1);
  if (i2) goto l20;
  i2 = *(OOC_INT32*)((_check_pointer(i0, 4350))+12);
  *(OOC_INT32*)((_check_pointer(i0, 4350))+12) = (i2+i1);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4376))+4);
  i1 = _check_pointer(i1, 4383);
  i2 = *(OOC_INT32*)((_check_pointer(i0, 4385))+12);
  i3 = OOC_ARRAY_LENGTH(i1, 0);
  *(OOC_UINT8*)(i1+(_check_index(i2, i3, OOC_UINT32, 4383))) = 0u;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4429))+4);
  i1 = _check_pointer(i1, 4436);
  i0 = *(OOC_INT32*)((_check_pointer(i0, 4438))+12);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i0 = *(OOC_UINT8*)(i1+(_check_index(i0, i2, OOC_UINT32, 4436)));
  _assert((i0==0u), 127, 4420);
  return 1u;
  goto l21;
l20:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4272))+4);
  i1 = _check_pointer(i1, 4279);
  i0 = *(OOC_INT32*)((_check_pointer(i0, 4281))+12);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i0 = *(OOC_UINT8*)(i1+(_check_index(i0, i2, OOC_UINT32, 4279)));
  _assert((i0==0u), 127, 4263);
  return 0u;
l21:
  _failed_function(2022); return 0;
  ;
}

OOC_CHAR8 XML_InputBuffer__BufferDesc_EndOfBuffer(XML_InputBuffer__Buffer b, OOC_INT32 cpos) {
  register OOC_INT32 i0,i1,i2,i3;

  i0 = cpos;
  _assert((0<=i0), 127, 4834);
  i1 = (OOC_INT32)b;
  i2 = *(OOC_INT32*)((_check_pointer(i1, 4875))+12);
  _assert((i0<=i2), 127, 4858);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4904))+4);
  i2 = _check_pointer(i2, 4911);
  i3 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = *(OOC_UINT8*)(i2+(_check_index(i0, i3, OOC_UINT32, 4911)));
  _assert((i2==0u), 127, 4895);
  i1 = *(OOC_INT32*)((_check_pointer(i1, 4952))+12);
  return (i0==i1);
  ;
}

void XML_InputBuffer__BufferDesc_Close(XML_InputBuffer__Buffer b) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5233));
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5233));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5236)))), IO__ChannelDesc_Close)),IO__ChannelDesc_Close)((IO__Channel)i2);
  *(OOC_INT32*)(_check_pointer(i0, 5252)) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 5269))+4) = 0;
  return;
  ;
}

static void XML_InputBuffer__Init(XML_InputBuffer__Buffer b, OOC_CHAR8 _new, IO__ByteChannel reader, Msg__MsgList errList) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)b;
  i1 = (OOC_INT32)reader;
  *(OOC_INT32*)(_check_pointer(i0, 5458)) = i1;
  *(OOC_INT32*)((_check_pointer(i0, 5478))+16) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 5503))+8) = 0;
  *(OOC_INT32*)((_check_pointer(i0, 5531))+12) = 0;
  i1 = (OOC_INT32)errList;
  *(OOC_INT32*)((_check_pointer(i0, 5556))+20) = i1;
  i1 = _new;
  if (!i1) goto l3;
  *(OOC_INT32*)((_check_pointer(i0, 5606))+4) = ((OOC_INT32)RT0__NewObject(_td_XML_InputBuffer__CharArray.baseTypes[0], 16352));
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5643))+4);
  i1 = _check_pointer(i1, 5650);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  *(OOC_UINT8*)(i1+(_check_index(0, i2, OOC_UINT8, 5650))) = 0u;
  i0 = XML_InputBuffer__BufferDesc_NextBlock((XML_InputBuffer__Buffer)i0);
  return;
  ;
}

XML_InputBuffer__Buffer XML_InputBuffer__New(IO__ByteChannel reader, Msg__MsgList errList) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)RT0__NewObject(_td_XML_InputBuffer__Buffer.baseTypes[0]);
  i1 = (OOC_INT32)errList;
  i2 = (OOC_INT32)reader;
  XML_InputBuffer__Init((XML_InputBuffer__Buffer)i0, 1u, (IO__ByteChannel)i2, (Msg__MsgList)i1);
  return (XML_InputBuffer__Buffer)i0;
  ;
}

void OOC_XML_InputBuffer_init(void) {

  return;
  ;
}

void OOC_XML_InputBuffer_destroy(void) {
}

/* --- */
