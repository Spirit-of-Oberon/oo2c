#include <StdChannels.d>
#include <__oo2c.h>
#include <setjmp.h>

static Msg__Msg StdChannels__GetError(OOC_INT32 code) {
  register OOC_INT32 i0,i1;

  i0 = code;
  i1 = (OOC_INT32)StdChannels__errorContext;
  i0 = (OOC_INT32)Msg__New((Msg__Context)i1, i0);
  return (Msg__Msg)i0;
  ;
}

OOC_INT32 StdChannels__WriterDesc_Pos(StdChannels__Writer w) {

  return (-2);
  ;
}

void StdChannels__WriterDesc_SetPos(StdChannels__Writer w, OOC_INT32 newPos) {

  return;
  ;
}

void StdChannels__WriterDesc_WriteByte(StdChannels__Writer w, OOC_CHAR8 x) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)w;
  *(OOC_INT32*)((_check_pointer(i0, 2776))+8) = 1;
  return;
  ;
}

void StdChannels__WriterDesc_WriteBytes(StdChannels__Writer w, const OOC_CHAR8 x[], OOC_LEN x_0d, OOC_INT32 start, OOC_INT32 n) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)w;
  i1 = n;
  *(OOC_INT32*)((_check_pointer(i0, 2918))+8) = i1;
  return;
  ;
}

OOC_INT32 StdChannels__NullChannelDesc_Length(StdChannels__NullChannel ch) {

  return (-1);
  ;
}

void StdChannels__NullChannelDesc_GetModTime(StdChannels__NullChannel ch, struct Time__TimeStamp *mtime, RT0__Struct mtime__tag) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)ch;
  i1 = (OOC_INT32)StdChannels__GetError(12);
  *(OOC_INT32*)(_check_pointer(i0, 3240)) = i1;
  return;
  ;
}

Channel__Reader StdChannels__NullChannelDesc_NewReader(StdChannels__NullChannel ch) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)ch;
  i1 = (OOC_INT32)StdChannels__GetError(9);
  *(OOC_INT32*)(_check_pointer(i0, 3370)) = i1;
  return (Channel__Reader)0;
  ;
}

Channel__Writer StdChannels__NullChannelDesc_NewWriter(StdChannels__NullChannel ch) {
  register OOC_INT32 i0,i1;
  StdChannels__Writer w;

  i0 = (OOC_INT32)ch;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3540)))), Channel__ChannelDesc_ClearError)),Channel__ChannelDesc_ClearError)((Channel__Channel)i0);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3564))+8);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l3;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3765))+8);
  return (Channel__Writer)i0;
  goto l4;
l3:
  i1 = (OOC_INT32)RT0__NewObject(_td_StdChannels__Writer.baseTypes[0]);
  w = (StdChannels__Writer)i1;
  *(OOC_INT32*)(_check_pointer(i1, 3607)) = i0;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3628)))), Channel__WriterDesc_ClearError)),Channel__WriterDesc_ClearError)((Channel__Writer)i1);
  *(OOC_UINT8*)((_check_pointer(i1, 3649))+12) = 0u;
  *(OOC_INT32*)((_check_pointer(i1, 3681))+8) = (-1);
  *(OOC_INT32*)((_check_pointer(i0, 3711))+8) = i1;
  return (Channel__Writer)i1;
l4:
  _failed_function(3475); return 0;
  ;
}

void StdChannels__NullChannelDesc_Flush(StdChannels__NullChannel ch) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)ch;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3852)))), Channel__ChannelDesc_ClearError)),Channel__ChannelDesc_ClearError)((Channel__Channel)i0);
  return;
  ;
}

void StdChannels__NullChannelDesc_Close(StdChannels__NullChannel ch) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)ch;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3931)))), Channel__ChannelDesc_ClearError)),Channel__ChannelDesc_ClearError)((Channel__Channel)i0);
  return;
  ;
}

static void StdChannels__Flush(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)StdChannels__stdout;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3996)))), Channel__ChannelDesc_Flush)),Channel__ChannelDesc_Flush)((Channel__Channel)i0);
  i0 = (OOC_INT32)StdChannels__stderr;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4011)))), Channel__ChannelDesc_Flush)),Channel__ChannelDesc_Flush)((Channel__Channel)i0);
  return;
  ;
}

void OOC_StdChannels_init(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)RT0__NewObject(_td_StdChannels__ErrorContext.baseTypes[0]);
  StdChannels__errorContext = (StdChannels__ErrorContext)i0;
  Msg__InitContext((Msg__Context)i0, "OOC:Core:StdChannels", 21);
  i0 = (OOC_INT32)RT0__NewObject(_td_PosixFileDescr__Channel.baseTypes[0]);
  StdChannels__fd = (PosixFileDescr__Channel)i0;
  PosixFileDescr__Init((PosixFileDescr__Channel)i0, 0, 0);
  i0 = (OOC_INT32)StdChannels__fd;
  StdChannels__stdin = (Channel__Channel)i0;
  i0 = (OOC_INT32)RT0__NewObject(_td_PosixFileDescr__Channel.baseTypes[0]);
  StdChannels__fd = (PosixFileDescr__Channel)i0;
  PosixFileDescr__Init((PosixFileDescr__Channel)i0, 1, 1);
  i0 = (OOC_INT32)StdChannels__fd;
  StdChannels__stdout = (Channel__Channel)i0;
  i0 = (OOC_INT32)RT0__NewObject(_td_PosixFileDescr__Channel.baseTypes[0]);
  StdChannels__fd = (PosixFileDescr__Channel)i0;
  PosixFileDescr__Init((PosixFileDescr__Channel)i0, 2, 1);
  i0 = (OOC_INT32)StdChannels__fd;
  StdChannels__stderr = (Channel__Channel)i0;
  i0 = (OOC_INT32)RT0__NewObject(_td_StdChannels__NullChannel.baseTypes[0]);
  StdChannels__null = (StdChannels__NullChannel)i0;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4486)))), Channel__ChannelDesc_ClearError)),Channel__ChannelDesc_ClearError)((Channel__Channel)i0);
  i0 = (OOC_INT32)StdChannels__null;
  *(OOC_UINT8*)((_check_pointer(i0, 4506))+4) = 0u;
  *(OOC_UINT8*)((_check_pointer(i0, 4533))+5) = 1u;
  *(OOC_UINT8*)((_check_pointer(i0, 4559))+6) = 1u;
  Termination__RegisterProc((Termination__Proc)(OOC_INT32)&StdChannels__Flush);
  return;
  ;
}

/* --- */
