(*      $Id$       *)
MODULE ADT:Storable [OOC_EXTENSIONS];
(*  Base definitions for a persistent object implementation.
    Copyright (C) 1999-2002  Michael van Acken

    This module is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public License
    as published by the Free Software Foundation; either version 2 of
    the License, or (at your option) any later version.

    This module is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with OOC. If not, write to the Free Software Foundation,
    59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*)
 
IMPORT
  Channel, BinaryRider, Msg, Language:=LanguageNew;


(**This module defines the abstract type @otype{Object}, the root type of all
   classes that can be externalized.  Every object has an initialization
   function @oproc{Init}, and (optionally) a cleanup function
   @oproc{Object.Destroy}.  For persistence, it supports the type-bound
   procedures @oproc{Object.Store} and @oproc{Object.Load}.

   The module also defines new binary rider classes, which are extensions of
   the ones defined in module @omodule{BinaryRider}.  Concrete implementations
   of these abstract classes (like module @omodule{*ADT:Object:Storage})
   provide the mechanisms necessary to externalize and internalize arbitrary
   data structures.  The riders add some type-bound procedures to the
   interfaces inherited from @omodule{BinaryRider}, and rely on the type-bound
   procedures @oproc{Object.Store} and @oproc{Object.Load} to store and
   load an object's private data.  *)


TYPE
  Object* = POINTER TO ObjectDesc;
  ObjectArray* = ARRAY OF Object;  (* FIXME... eliminate type *)
  ObjectArrayPtr* = POINTER TO ObjectArray;  (* FIXME... eliminate type *)
  ObjectDesc* = RECORD [ABSTRACT]
  (**This class defines a protocol for object persistence using with
     @oproc{Object.Store} and @oproc{Object.Load}).  *)
    (Language.ObjectDesc)
  END;

TYPE  (* abstract types, used for persistence mechanism 
         (see Load/Store and Read/WriteObject) *)
  Reader* = POINTER TO ReaderDesc;
  ReaderDesc* = RECORD [ABSTRACT]
  (**@otype{Reader} defines the infrastructure for reading of serialized object
     data.  Its primary task is to add the method @oproc{Reader.ReadObject} to
     the class @otype{BinaryRider.Reader}.  Together with @oproc{Object.Load}
     it handles conversion of byte sequences back into living objects.

     This is an abstract class.  For a concrete implementation, see
     @otype{*ADT:Object:Storage.Reader}.  *)
    (BinaryRider.ReaderDesc)
  END;
  Writer* = POINTER TO WriterDesc;
  WriterDesc* = RECORD [ABSTRACT]
  (**@otype{Reader} defines writing of serialized object data.  It defines
     @oproc{Reader.ReadObject}, which together with @oproc{Object.Store}
     handles serialization of objects into byte streams.

     This is an abstract class.  For a concrete implementation, see
     @otype{*ADT:Object:Storage.Writer}.  *)
    (BinaryRider.WriterDesc)
  END;
  String* = POINTER TO StringDesc;
  StringDesc* = RECORD [ABSTRACT] 
    (**FIXME... get rid of this type.  @otype{String} defines an empty type,
       which other string types may extend.  Its main purpose here is to allow
       @oproc{Object.ToString} to return a value that is compatible with the
       string type defined in @omodule{*ADT:String}.  *)
    (ObjectDesc)
  END;

CONST  (* additional error codes for the riders above: *)
  cancelled* = -1;
  (**@oproc{Reader.Cancel} creates an error for the reader using this code.  *)
  versionMismatch* = -2;
  (**Set by @oproc{Reader.ReadVersion} in case of a version mismatch.  *)
  unknownType* = -3;
  (**The file reader found a type name that could not be resolved.  Either the
     type's module or the type name are not known.  *)
  
TYPE
  ErrorContext = POINTER TO ErrorContextDesc;
  ErrorContextDesc* = RECORD
     (* this record is exported, so that extensions of Channel can access the
        error descriptions by extending `ErrorContextDesc' *)
    (Channel.ErrorContextDesc)
  END;

VAR
  errorContext: ErrorContext;

PROCEDURE GetError (code: Msg.Code): Msg.Msg;
  BEGIN
    RETURN Msg.New (errorContext, code)
  END GetError;

PROCEDURE (context: ErrorContext) GetTemplate* (msg: Msg.Msg; VAR templ: Msg.LString);
  VAR
    descr: ARRAY 64 OF CHAR;
  BEGIN
    IF (msg # NIL) THEN
      CASE msg. code OF
      | cancelled: COPY ("Reading was cancelled", descr)
      | versionMismatch: COPY ("Object version mismatch", descr)
      | unknownType: COPY ("Unknown type name", descr)
      ELSE
         COPY ("", descr)
      END
    ELSE
      COPY ("", descr)
    END;
    IF (descr # "") THEN
      COPY (descr, templ)
    ELSE
      context. GetTemplate^ (msg, templ)
    END
  END GetTemplate;


PROCEDURE Init* (obj: Object);
(**Initializes object @oparam{obj} to a valid state.  Extensions of class
   @otype{Object} are expected to provide their own initialization procedure
   @oproc{Init}, which calls its direct baseclass' @oproc{Init} in turn.  *)
  END Init;

PROCEDURE (obj: Object) ToString * () : String;
(**FIXME... get rid of this method.  Returns a string representation of the
   object. This is mainly for debugging purposes. The returned string should
   describe the type and essential attributes of the object. This procedure
   returns NIL because we have no implementation of string available here.  *)
BEGIN
  RETURN NIL;
END ToString;

PROCEDURE (obj: Object) Destroy* ;
(**Returns @oparam{obj} to an undefined state.  No operations on @oparam{obj}
   are allowed until @oparam{obj} is initialized again.  This procedure is only
   of use for systems with a conservative garbage collector.  It typically
   removes all external references from @oparam{obj}, reducing the chance that
   a misjudged reference into the data of @oparam{obj} keeps large parts of the
   data structure alive.  This can also serve as a crude tool to detect
   unwanted sharing of objects, if destroying an object breaks the state of
   another one.  @emph{Please note:} This procedure does not free any allocated
   memory by itself, even if memory is known to be private to @oparam{obj},
   because OOC has no facility to free memory blocks.  *)
  END Destroy;


(* Externalize/Internalize Methods
   ======================================================================== *)
   
PROCEDURE (obj: Object) Store* (w: Writer);
(**Stores data of @oparam{obj} to @oparam{w}.  Nested record pointers are
   stored by calling the type-bound procedure @oproc{Writer.WriteObject}.  The
   procedure is not allowed to make any changes to the global state of the
   program, except for calling the @samp{Write} methods of the writer
   @oparam{w}.  This implies, that changing the position of @oparam{w} by
   calling @oproc{Writer.SetPos} is not permitted.  Any redefinition of this
   procedure must include a super call, preferably as the first statement of
   the procedure body.

   @precond
   This procedure is either activated by a super call, or from the procedure
   @oproc{Writer.WriteObject}.
   @end precond  *)
  BEGIN
  END Store;

PROCEDURE (obj: Object) Load* (r: Reader);
(**Loads data of @oparam{obj} from @oparam{r}.  Nested record pointers are
   loaded by calling the type-bound procecdure @oproc{Reader.ReadObject}.  This
   procedure must be symmetric to @oproc{Object.Store}, or data internalization
   will break, causing undefined object state or program termination.

   Note: When internalizing a file with alien objects, it is possible that the
   type-bound procedure @oproc{Object.Load} is invoked more than once for a
   single object.  Except for the results of the last call, all duplicates are
   discarded.  Because of this, all changes by this procedure to any program
   state that is not part of the object @oparam{obj} are deprecated.

   @precond
   This procedure is either activated by a super call, or from the procedure
   @oproc{Reader.ReadObject}.
   @end precond  *)
  BEGIN
  END Load;

(* Methods for extended BinaryRider
   ======================================================================== *)

PROCEDURE InitWriter* (w: Writer; ch: Channel.Channel);
(**Initializes a new writer instance @oparam{w} for channel @oparam{ch}.
   Little endian byte ordering is used by the writer.  *)
  BEGIN
    BinaryRider.InitWriter (w, ch, BinaryRider.littleEndian);
  END InitWriter;

PROCEDURE InitReader* (r: Reader; ch: Channel.Channel);
(**Initializes a new reader instance @oparam{r} for channel @oparam{ch}.
   Little endian byte ordering is used by the reader.  *)
  BEGIN
    BinaryRider.InitReader (r, ch, BinaryRider.littleEndian)
  END InitReader;

PROCEDURE (w: Writer) [ABSTRACT] WriteObject* (obj: Object);
(**Writes object to the channel underlying the writer @oparam{w}.  The
   externalization framework is provided by the concrete instance of writer
   @oparam{w}.  The object itself is required to provide the necessary
   type-bound procedure @oproc{Object.Store} to pass its own data to
   @oparam{w}.  *)
  END WriteObject;
  
PROCEDURE (w: Writer) WriteVersion* (version: LONGINT);
(**Writes a version number to the channel underlying the writer @oparam{w}.  *)
  BEGIN
    w. WriteNum (version)
  END WriteVersion;

PROCEDURE (w: Writer) [ABSTRACT] Disconnect*;
(**Completes the data written to the channel of writer @oparam{w}, and cleans
   up the internal data structures.  Without calling @oproc{Writer.Disconnect}
   the externalized objects may be left in a invalid state, and no new
   externalization process can be started.  After @oproc{Writer.Disconnect},
   all operations on @oparam{w} are undefined.  The value of
   @ofield{BinaryRider.Writer.res} should be checked after disconnecting the
   writer.  *)
  END Disconnect;

PROCEDURE (r: Reader) [ABSTRACT] ReadObject* (VAR obj: Object);
(**Reads an object reference from the channel underlying the reader @oparam{r}.
   The object @oparam{obj} itself is required to provide the necessary
   type-bound procedure @oproc{Object.Load} to restore its own data from
   @oparam{r}.  *)
  END ReadObject;
  
PROCEDURE (r: Reader) ReadVersion* (min, max: LONGINT; VAR version: LONGINT);
(**Reads a version identifier and cancels the current load, if it is not
   between @oparam{min} and @oparam{max} (that is, if not @samp{@oparam{min} <=
   @oparam{version} <= @oparam{max}}.  *)
  BEGIN
    r. ReadNum (version);
    IF ((version < min) OR (max < version)) &
       (r. byteReader. res = BinaryRider.done) THEN
      r. byteReader. res := GetError (versionMismatch)
    END
  END ReadVersion;

PROCEDURE (r: Reader) Cancel*;
(**Cancels the current internalization process.  After cancellation, all
   invocations of @oproc{Reader.ReadObject} return @code{NIL}.  *)
  BEGIN
    IF (r. byteReader. res = BinaryRider.done) THEN
      r. byteReader. res := GetError (cancelled)
    END
  END Cancel;

PROCEDURE (r: Reader) [ABSTRACT] Disconnect*;
(**Disconnects reader @oparam{r}, and cleans up the internal data structures.
   Any resources allocated by the reader are freed.  *)
  END Disconnect;

BEGIN
  NEW (errorContext);
  Msg.InitContext (errorContext, "ADT:Storable");
END ADT:Storable.
