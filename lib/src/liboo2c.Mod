MODULE liboo2c;
<* Warnings := FALSE *>

(* Modules marked with @samp{mgs} have mutable global state and therefore
   may pose a problem in a multi-threaded application.  Most of them are
   usually used in a not critical way.  Things are different for modules
   @omodule{Files} and @omodule{FileChannel}.  Both keep track of open files
   that should be removed on program termination, and these lists may be hosed
   by concurrent open and close operations.

   Note: Contrary to modules, @emph{no} object is multi-threading safe unless
   stated otherwise.  *)

IMPORT
  RT0,               (* mgs (RegisterModule) *)
  Out0,
  HashCode,
  Exception,         (* mt-safe if PThread is imported *)
  
  Ascii,
  BinaryRider,
  C,
  Channel,
  CharClass,
  ConvTypes,
  Err,               (* mgs (writer, SetWriter) *)
  Files,             (* mgs (New, Old, Tmp, Close) *)
  In,                (* mgs (reader, SetReader) *)
  IntConv,
  IntStr,
  LRealConv,
  LRealMath,
  LRealStr,
  Log,               (* mgs (writer, SetWriter) *)
  LongStrings,
  Msg,
  Out,               (* mgs (writer, SetWriter) *)
  PosixFileDescr,    (* mgs (Init) *)
  ProgramArgs,
  RandomNumbers,     (* mgs (seed) *)
  Real0,
  RealConv,
  RealMath,
  RealStr,
  StdChannels,
  StringSearch,
  Strings,
  SysClock,
  Termination,       (* mgs (proc_list, Register, Unregister) *)
  TextRider,
  Time,

  Object,
  Object:Boxed,
  Object:BigInt,
  ADT:Storable,
  ADT:StringBuffer,
  ADT:Dictionary,
  ADT:ArrayList,

  IO,
  IO:Address,
  IO:Socket,
  IO:FileChannel,    (* mgs (tmp_files, Open, OpenUnbuffered, Close) *)
  IO:SocketChannel,
  IO:Memory,
  IO:Buffer,
  IOStd := IO:StdChannels,
  IO:Select,
  IOTextRider := IO:TextRider,
  IOBinaryRider := IO:BinaryRider,

  (* optional stuff: *)
<*IF HAVE_LIB_PTHREAD THEN*>
  Thread:PThread,
<*END*>
  
  libc,
  libadt,
  libxml;            (* mgs -- unknown *)

END liboo2c.
