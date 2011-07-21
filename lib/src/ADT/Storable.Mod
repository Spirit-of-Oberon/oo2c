(*      $Id: Storable.Mod,v 1.11 2004/11/21 20:31:50 mva Exp $       *)
MODULE ADT:Storable [OOC_EXTENSIONS];
(*  Base definitions for a persistent object implementation.
    Copyright (C) 1999-2004  Michael van Acken

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
  Obj := Object, IO, IO:BinaryRider;


(**The module defines new binary rider classes, which are extensions of
   the ones defined in module @omodule{BinaryRider}.  Concrete
   implementations of these abstract classes (like module
   @omodule{*ADT:Object:Storage}) provide the mechanisms necessary to
   externalize and internalize arbitrary data structures.  The riders add some
   type-bound procedures to the interfaces inherited from
   @omodule{BinaryRider}, and rely on the type-bound procedures
   @oproc{Object.Store} and @oproc{Object.Load} to store and load an object's
   private data.  *)


TYPE
  Object* = POINTER TO ObjectDesc;
  ObjectDesc* = RECORD [ABSTRACT]
  (**This class defines a protocol for object persistence using with
     @oproc{Object.Store} and @oproc{Object.Load}).  *)
    (Obj.ObjectDesc)
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

TYPE
  TypeError* = POINTER TO TypeErrorDesc;
  TypeErrorDesc = RECORD
    (IO.ErrorDesc) 
  END;

PROCEDURE RaiseTypeError*(msg: STRING) RAISES TypeError;
  BEGIN
    RAISE(NEW(TypeError, msg));
  END RaiseTypeError;


(* Externalize/Internalize Methods
   ======================================================================== *)
   
PROCEDURE (obj: Object) [ABSTRACT] Store* (w: Writer) RAISES IO.Error;
(**Stores data of @oparam{obj} to @oparam{w}.  Nested record pointers are
   stored by calling the type-bound procedure @oproc{Writer.WriteObject}.  The
   procedure is not allowed to make any changes to the global state of the
   program, except for calling the @samp{Write} methods of the writer
   @oparam{w}.  Any redefinition of this procedure must include a super call,
   preferably as the first statement of the procedure body.

   @precond
   This procedure is either activated by a super call, or from the procedure
   @oproc{Writer.WriteObject}.
   @end precond  *)
  END Store;

PROCEDURE (obj: Object) [ABSTRACT] Load* (r: Reader) RAISES IO.Error;
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
  END Load;

(* Methods for extended BinaryRider
   ======================================================================== *)

PROCEDURE (w: Writer) INIT*(ch: IO.ByteChannel);
(**Initializes a new writer instance @oparam{w} for channel @oparam{ch}.
   Little endian byte ordering is used by the writer.  *)
  BEGIN
    w.INIT^(ch, BinaryRider.littleEndian);
  END INIT;

PROCEDURE (r: Reader) INIT*(ch: IO.ByteChannel);
(**Initializes a new reader instance @oparam{r} for channel @oparam{ch}.
   Little endian byte ordering is used by the reader.  *)
  BEGIN
    r.INIT^(ch, BinaryRider.littleEndian)
  END INIT;

PROCEDURE (w: Writer) [ABSTRACT] WriteObject* (obj: Obj.Object)
RAISES IO.Error;
(**Writes object to the channel underlying the writer @oparam{w}.  The
   externalization framework is provided by the concrete instance of writer
   @oparam{w}.  The object itself is required to provide the necessary
   type-bound procedure @oproc{Object.Store} to pass its own data to
   @oparam{w}.

   @precond
   @oparam{obj} is @code{NIL}, or it is an instance of @otype{Object}.
   @end precond  *)
  END WriteObject;
  
PROCEDURE (w: Writer) [ABSTRACT] Disconnect*;
(**Completes the data written to the channel of writer @oparam{w}, and cleans
   up the internal data structures.  Without calling @oproc{Writer.Disconnect}
   the externalized objects may be left in a invalid state, and no new
   externalization process can be started.  After @oproc{Writer.Disconnect},
   all operations on @oparam{w} are undefined.  *)
  END Disconnect;

PROCEDURE (r: Reader) [ABSTRACT] ReadObject* (VAR obj: Obj.Object)
RAISES IO.Error;
(**Reads an object reference from the channel underlying the reader @oparam{r}.
   The object @oparam{obj} itself is required to provide the necessary
   type-bound procedure @oproc{Object.Load} to restore its own data from
   @oparam{r}.  *)
  END ReadObject;
  
PROCEDURE (r: Reader) [ABSTRACT] Disconnect*;
(**Disconnects reader @oparam{r}, and cleans up the internal data structures.
   Any resources allocated by the reader are freed.  *)
  END Disconnect;

END ADT:Storable.
