MODULE Codec:zlib [INTERFACE "C"; LINK LIB "z" END];

(**Partial conversion of the declarations in the header file @file{zlib.h}
   from the @samp{zlib-1.1.4} library.  For documentation, please refer to
   the original header file.  *)

IMPORT
  SYSTEM, C;

CONST
  ZLIB_VERSION* = "1.1.4";

TYPE
  alloc_func* = PROCEDURE (opaque: SYSTEM.PTR; items: C.int; size: C.int): SYSTEM.PTR;
  free_func* = PROCEDURE (opaque: SYSTEM.PTR; address: SYSTEM.PTR);
  z_stream_s* = RECORD
    next_in*: SYSTEM.ADDRESS;
    avail_in*: C.int;
    total_in-: C.longint;
    
    next_out*: SYSTEM.ADDRESS;
    avail_out*: C.int;
    total_out-: C.longint;

    msg-: C.charPtr1d;
    internal_state-: SYSTEM.PTR;

    zalloc*: alloc_func;
    zfree*: free_func;
    opaque*: SYSTEM.PTR;

    data_type-: C.int;
    adler-: C.longint;
    reserved-: C.longint;
  END;
  z_streamp* = POINTER TO z_stream_s;

CONST
  Z_NO_FLUSH* = 0;
  Z_PARTIAL_FLUSH* = 1;
  Z_SYNC_FLUSH* = 2;
  Z_FULL_FLISH* = 3;
  Z_FINISH* = 4;

CONST
  Z_OK* = 0;
  Z_STREAM_END* = 1;
  Z_NEED_DICT* = 2;
  Z_ERRNO* = -1;
  Z_STREAM_ERROR* = -2;
  Z_DATA_ERROR* = -3;
  Z_MEM_ERROR* = -4;
  Z_BUF_ERROR* = -5;
  Z_VERSION_ERROR* = -6;

CONST
  Z_NO_COMPRESSION* = 0;
  Z_BEST_SPEED* = 1;
  Z_BEST_COMPRESSION* = 9;
  Z_DEFAULT_COMPRESSION*= -1;

CONST
  Z_FILTERED* = 1;
  Z_HUFFMAN_ONLY* = 2;
  Z_DEFAULT_STRATEGY* = 0;

CONST
  Z_BINARY* = 0;
  Z_ASCII* = 1;
  Z_UNKNOWN* = 2;

CONST
  Z_DEFLATED* = 8;

PROCEDURE deflateInit_* (VAR strm: z_stream_s; level: C.int;
                         version: ARRAY OF CHAR; stream_size: C.int): C.int;
PROCEDURE inflateInit_* (VAR strm: z_stream_s;
                         version: ARRAY OF CHAR; stream_size: C.int): C.int;
PROCEDURE deflate* (VAR strm: z_stream_s; flush: C.int): C.int;
PROCEDURE deflateEnd* (VAR strm: z_stream_s): C.int;
PROCEDURE deflateReset* (VAR strm: z_stream_s): C.int;
PROCEDURE inflate* (VAR strm: z_stream_s; flush: C.int): C.int;
PROCEDURE inflateEnd* (VAR strm: z_stream_s): C.int;
PROCEDURE inflateReset* (VAR strm: z_stream_s): C.int;
  
END Codec:zlib.
