#include <Channel.d>
#include <__oo2c.h>
#include <setjmp.h>

static Msg__Msg Channel__GetError(OOC_INT32 code) {
  register OOC_INT32 i0,i1;

  i0 = code;
  i1 = (OOC_INT32)Channel__errorContext;
  i0 = (OOC_INT32)Msg__New((Msg__Context)i1, i0);
  return (Msg__Msg)i0;
  ;
}

void Channel__ErrorContextDesc_GetTemplate(Channel__ErrorContext context, Msg__Msg msg, Msg__LString templ, OOC_LEN templ_0d) {
  register OOC_INT32 i0;
  OOC_CHAR8 str[128];

  i0 = (OOC_INT32)msg;
  i0 = *(OOC_INT32*)((_check_pointer(i0, 12179))+8);
  switch (i0) {
  case 1:
    _copy_8((const void*)(OOC_CHAR8*)"Invalid channel descriptor",(void*)(OOC_INT32)str,128);
    goto l16;
  case 2:
    _copy_8((const void*)(OOC_CHAR8*)"Write error",(void*)(OOC_INT32)str,128);
    goto l16;
  case 3:
    _copy_8((const void*)(OOC_CHAR8*)"No space left on device",(void*)(OOC_INT32)str,128);
    goto l16;
  case 4:
    _copy_8((const void*)(OOC_CHAR8*)"Trying to set invalid position",(void*)(OOC_INT32)str,128);
    goto l16;
  case 5:
    _copy_8((const void*)(OOC_CHAR8*)"Trying to read past the end of the file",(void*)(OOC_INT32)str,128);
    goto l16;
  case 6:
    _copy_8((const void*)(OOC_CHAR8*)"Channel has been closed",(void*)(OOC_INT32)str,128);
    goto l16;
  case 7:
    _copy_8((const void*)(OOC_CHAR8*)"Read error",(void*)(OOC_INT32)str,128);
    goto l16;
  case 8:
    _copy_8((const void*)(OOC_CHAR8*)"Invalid token type in input stream",(void*)(OOC_INT32)str,128);
    goto l16;
  case 9:
    _copy_8((const void*)(OOC_CHAR8*)"No read permission for channel",(void*)(OOC_INT32)str,128);
    goto l16;
  case 10:
    _copy_8((const void*)(OOC_CHAR8*)"No write permission for channel",(void*)(OOC_INT32)str,128);
    goto l16;
  case 11:
    _copy_8((const void*)(OOC_CHAR8*)"Error while closing the channel",(void*)(OOC_INT32)str,128);
    goto l16;
  case 12:
    _copy_8((const void*)(OOC_CHAR8*)"No modification time available",(void*)(OOC_INT32)str,128);
    goto l16;
  case 13:
    _copy_8((const void*)(OOC_CHAR8*)"Failed to create unique name for temporary file",(void*)(OOC_INT32)str,128);
    goto l16;
  default:
    _copy_8((const void*)(OOC_CHAR8*)"[unknown error code]",(void*)(OOC_INT32)str,128);
    goto l16;
  }
l16:
  _copy_8to16((const void*)(OOC_INT32)str,(void*)(OOC_INT32)templ,templ_0d);
  return;
  ;
}

OOC_INT32 Channel__ReaderDesc_Pos(Channel__Reader r) {

  _failed_function(13210); return 0;
  ;
}

OOC_INT32 Channel__ReaderDesc_Available(Channel__Reader r) {

  _failed_function(13704); return 0;
  ;
}

void Channel__ReaderDesc_SetPos(Channel__Reader r, OOC_INT32 newPos) {

  return;
  ;
}

void Channel__ReaderDesc_ReadByte(Channel__Reader r, OOC_CHAR8 *x) {

  return;
  ;
}

void Channel__ReaderDesc_ReadBytes(Channel__Reader r, OOC_CHAR8 x[], OOC_LEN x_0d, OOC_INT32 start, OOC_INT32 n) {

  return;
  ;
}

void Channel__ReaderDesc_ClearError(Channel__Reader r) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)r;
  *(OOC_INT32*)((_check_pointer(i0, 18059))+4) = (OOC_INT32)0;
  return;
  ;
}

OOC_INT32 Channel__WriterDesc_Pos(Channel__Writer w) {

  _failed_function(18227); return 0;
  ;
}

void Channel__WriterDesc_SetPos(Channel__Writer w, OOC_INT32 newPos) {

  return;
  ;
}

void Channel__WriterDesc_WriteByte(Channel__Writer w, OOC_CHAR8 x) {

  return;
  ;
}

void Channel__WriterDesc_WriteBytes(Channel__Writer w, const OOC_CHAR8 x__ref[], OOC_LEN x_0d, OOC_INT32 start, OOC_INT32 n) {
  OOC_ALLOCATE_VPAR(x,OOC_CHAR8 ,x_0d)

  OOC_INITIALIZE_VPAR(x__ref,x,OOC_CHAR8 ,x_0d)
  return;
  ;
}

void Channel__WriterDesc_ClearError(Channel__Writer w) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)w;
  *(OOC_INT32*)((_check_pointer(i0, 21563))+4) = (OOC_INT32)0;
  return;
  ;
}

OOC_INT32 Channel__ChannelDesc_Length(Channel__Channel ch) {

  _failed_function(21741); return 0;
  ;
}

void Channel__ChannelDesc_GetModTime(Channel__Channel ch, struct Time__TimeStamp *mtime, RT0__Struct mtime__tag) {

  return;
  ;
}

Channel__Reader Channel__ChannelDesc_NewReader(Channel__Channel ch) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)ch;
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 23167))+6);
  if (i1) goto l3;
  i1 = (OOC_INT32)Channel__GetError(6);
  *(OOC_INT32*)(_check_pointer(i0, 23237)) = i1;
  goto l4;
l3:
  i1 = (OOC_INT32)Channel__GetError(9);
  *(OOC_INT32*)(_check_pointer(i0, 23187)) = i1;
l4:
  return (Channel__Reader)0;
  ;
}

Channel__Writer Channel__ChannelDesc_NewWriter(Channel__Channel ch) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)ch;
  i1 = *(OOC_UINT8*)((_check_pointer(i0, 24177))+6);
  if (i1) goto l3;
  i1 = (OOC_INT32)Channel__GetError(6);
  *(OOC_INT32*)(_check_pointer(i0, 24248)) = i1;
  goto l4;
l3:
  i1 = (OOC_INT32)Channel__GetError(10);
  *(OOC_INT32*)(_check_pointer(i0, 24197)) = i1;
l4:
  return (Channel__Writer)0;
  ;
}

void Channel__ChannelDesc_Flush(Channel__Channel ch) {

  return;
  ;
}

void Channel__ChannelDesc_Close(Channel__Channel ch) {

  return;
  ;
}

void Channel__ChannelDesc_ClearError(Channel__Channel ch) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)ch;
  *(OOC_INT32*)(_check_pointer(i0, 26041)) = 0;
  return;
  ;
}

void OOC_Channel_init(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)RT0__NewObject(_td_Channel__ErrorContext.baseTypes[0]);
  Channel__errorContext = (Channel__ErrorContext)i0;
  Msg__InitContext((Msg__Context)i0, (OOC_CHAR8*)"OOC:Core:Channel", 17);
  return;
  ;
}

void OOC_Channel_destroy(void) {
}

/* --- */
