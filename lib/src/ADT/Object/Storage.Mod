(*	$Id$	*)
MODULE ADT:Object:Storage;
(*  Implements a framework for persistent objects.
    Copyright (C) 2000, 2001  Michael van Acken

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

(**Note: This module is a reduced version of the @samp{Storage} module from the
   old abandoned ADT library effort.  All references to @samp{alien} objects
   have been removed, otherwise the functionality is unchanged.

   Syntax of externalized objects:

   @example
   file = @{object@}.
   object = NUM(ref) [ objdescr ].
   objdescr = type data @{object data@}.
   type = NUM(tref) [ module_name type_name ].
   module_name = @{char@} 0X.
   type_name = @{char@} 0X.
   @end example

   @samp{ref} is a unique reference number assigned to an object when it is
   externalized.  The first occurrence of a reference number is followed by the
   object's qualified type name, and the object's value.  @samp{tref} is a type
   reference number; it is allocated in a similar way.

   @samp{data} is a sequence of bytes (possibly empty), produced by calling
   @oproc{Object.Object.Store} on a object.  The sequence does not contain any
   embedded objects, but it does contain @code{NIL} pointers.  *)

IMPORT
  SYSTEM, RT0, Strings, Channel, BinaryRider, Msg,
  ADT:Object, Dictionary := ADT:Dictionary:AddressKey:IntValue;

CONST
  done* = BinaryRider.done;

TYPE
  TypeRefMap = POINTER TO ARRAY OF RECORD
    module: RT0.Name;
    type: RT0.Name;
    ref: LONGINT;
  END;
  ObjectArray = POINTER TO ARRAY OF Object.Object;
  TypeArray = POINTER TO ARRAY OF RECORD
    type: RT0.Struct;
    moduleName: RT0.Name;
    typeName: RT0.Name;
  END;
  
  Reader* = POINTER TO ReaderDesc;
  ReaderDesc* = RECORD
  (**A reader for serialized object data.  *)
    (Object.ReaderDesc)
    objCounter: LONGINT;
    objTab: ObjectArray;
    typeCounter: LONGINT;
    typeTab: TypeArray;
    
    name: ARRAY 256 OF CHAR;  (* 256 should suffice, but ... *)
  END;
  
  Writer* = POINTER TO WriterDesc;
  WriterDesc* = RECORD
  (**A writer of serialized object data.  *)
    (Object.WriterDesc)
    objCounter: LONGINT;
    
    typeRefMap: TypeRefMap;
    (* used to map type names to reference numbers; unfortunately, Type is
       not an extension of Object, meaning that we cannot use a Dictionary
       here *)
    typeRefSize: LONGINT;
    objHash: Dictionary.Dictionary;
  END;

CONST
  pointerGap = 4;


TYPE
  ErrorContext = POINTER TO ErrorContextDesc;
  ErrorContextDesc* = RECORD
     (* this record is exported, so that extensions of Channel can access the
        error descriptions by extending `ErrorContextDesc' *)
    (Object.ErrorContextDesc)
  END;

VAR
  errorContext: ErrorContext;


PROCEDURE GetError (code: Msg.Code): Msg.Msg;
  BEGIN
    RETURN Msg.New (errorContext, code)
  END GetError;


PROCEDURE InitReader (r: Reader; ch: Channel.Channel);
  BEGIN
    Object.InitReader (r, ch);
    NEW (r. objTab, 128-pointerGap);
    r. objTab[0] := NIL;
    r. objCounter := 1;
    NEW (r. typeTab, 16-pointerGap);
    r. typeTab[0]. type := NIL;
    r. typeTab[0]. moduleName := NIL;
    r. typeTab[0]. typeName := NIL;
    r. typeCounter := 1;
  END InitReader;

PROCEDURE InitWriter (w: Writer; ch: Channel.Channel);
  BEGIN
    Object.InitWriter (w, ch);
    w. objCounter := 0;
    NEW (w. typeRefMap, 16-pointerGap);
    w. typeRefSize := 0;
    w. objHash := Dictionary.New();
  END InitWriter;


PROCEDURE ConnectReader* (ch: Channel.Channel): Reader;
(**Creates a new reader instance operating on channel @oparam{ch}.  *)
  VAR
    r: Reader;
  BEGIN
    NEW (r);
    InitReader (r, ch);
    IF (r. base = NIL) THEN  (* initialization of BinaryRider.Reader failed *)
      RETURN NIL
    ELSE
      RETURN r
    END
  END ConnectReader;
  
PROCEDURE ConnectWriter* (ch: Channel.Channel): Writer;
(**Creates a new writer instance operating on channel @oparam{ch}.  *)
  VAR
    w: Writer;
  BEGIN
    NEW (w);
    InitWriter (w, ch);
    IF (w. base = NIL) THEN  (* initialization of BinaryRider.Writer failed *)
      RETURN NIL
    ELSE
      RETURN w
    END
  END ConnectWriter;



PROCEDURE (r: Reader) ReadObject* (VAR obj: Object.Object);
  VAR
    ref, tref: LONGINT;
    module: RT0.Module;
  
  PROCEDURE ReadType(): LONGINT;
    VAR
      tref: LONGINT;
      tp: RT0.Struct;
      
    PROCEDURE ExtendTypeTab (VAR tab: TypeArray);
      VAR
        i: LONGINT;
        new: TypeArray;
      BEGIN
        NEW (new, LEN (tab^)*2+pointerGap);
        FOR i := 0 TO LEN (tab^)-1 DO
          new[i] := tab[i]
        END;
        tab := new
      END ExtendTypeTab;

    BEGIN
      r. ReadNum (tref);
      
      IF (tref < 0) THEN  (* back reference; return old index *)
        IF (-tref >= r. typeCounter) THEN
          r. res := GetError (BinaryRider.invalidFormat);
          RETURN 0
        ELSE
          RETURN -tref
        END
      
      ELSE  (* first occurence of this type *)
        IF (tref # r. typeCounter) THEN
          r. res := GetError (BinaryRider.invalidFormat)
        END;
        IF (tref = LEN (r. typeTab^)) THEN
          ExtendTypeTab (r. typeTab)
        END;
        INC (r. typeCounter);
        
        (* retrieve module and type name; create new entry for type table *)
        r. ReadString (r. name);
        module := RT0.modules;
        WHILE (module # NIL) & (module. name^ # r. name) DO
          module := module. next
        END;
        IF (module = NIL) THEN
          NEW (r. typeTab[tref]. moduleName, Strings.Length (r. name)+1);
          COPY (r. name, r. typeTab[tref]. moduleName^);
          r. ReadString (r. name);
          tp := NIL
        ELSE
          r. typeTab[tref]. moduleName := module. name;
          r. ReadString (r. name);
          tp := RT0.This (module, r. name);
        END;
        IF (tp = NIL) THEN
          NEW (r. typeTab[tref]. typeName, Strings.Length (r. name)+1);
          COPY (r. name, r. typeTab[tref]. typeName^)
        ELSE
          r. typeTab[tref]. typeName := tp. name
        END;
        r. typeTab[tref]. type := tp;
        RETURN tref
      END
    END ReadType;
    
  PROCEDURE ExtendObjTab (VAR tab: ObjectArray);
    VAR
      i: LONGINT;
      new: ObjectArray;
    BEGIN
      NEW (new, LEN (tab^)*2+pointerGap);
      FOR i := 0 TO LEN (tab^)-1 DO
        new[i] := tab[i]
      END;
      tab := new
    END ExtendObjTab;
  
  BEGIN
    r. ReadNum (ref);
    
    IF (r. res # BinaryRider.done) OR (ref = 0) THEN
      obj := NIL
      
    ELSE  (* reading object using "compact" format *)
      IF (ref < 0) THEN
        IF (-ref >= r. objCounter) THEN  (* invalid object index *)
          r. res := GetError (BinaryRider.invalidFormat)
        ELSE
          obj := r. objTab[-ref]
        END
      ELSE  (* first occurence of this object *)
        IF (ref # r. objCounter) THEN  (* invalid object index *)
          r. res := GetError (BinaryRider.invalidFormat)
        END;
        tref := ReadType();
        IF (r. typeTab[tref]. type = NIL) THEN
          r. res := GetError (Object.unknownType)
        ELSE  (* create new object of the requested type and load it *)
          obj := SYSTEM.VAL (Object.Object,
                             RT0.NewObject (r. typeTab[tref]. type));
          IF (ref = LEN (r. objTab^)) THEN
            ExtendObjTab (r. objTab)
          END;
          r. objTab[ref] := obj;
          INC (r. objCounter);
          obj. Load (r)
        END
      END
    END
  END ReadObject;

PROCEDURE (r: Reader) Disconnect*;
  VAR
    i: LONGINT;
  BEGIN  (* be nice to garbage collector *)
    FOR i := 0 TO LEN (r. objTab^)-1 DO
      r. objTab[i] := NIL
    END;
    FOR i := 0 TO LEN (r. typeTab^)-1 DO
      r. typeTab[i]. type := NIL;
      r. typeTab[i]. moduleName := NIL;
      r. typeTab[i]. typeName := NIL
    END;
    r. objCounter := 0;
    r. typeCounter := 0
  END Disconnect;




PROCEDURE (w: Writer) WriteObject* (obj: Object.Object);
  VAR
    tref: LONGINT;
    type: RT0.Struct;
    
  PROCEDURE LookupType (w: Writer; module, type: RT0.Name): LONGINT;
  (* The array based lookup table is slow for insertion.  Because the number of
     type descriptors in a file is much lower than the number of objects, the
     time for type descriptor insertion has little impact on the overall run 
     time.  *)
    VAR
      i, j, e: LONGINT;
      new: TypeRefMap;
    BEGIN
      i := -1; j := w. typeRefSize;
      WHILE (i+1 # j) DO
        e := (i+j) DIV 2;
        IF (w. typeRefMap[e]. module^ < module^) OR
           (w. typeRefMap[e]. module^ = module^) & 
             (w. typeRefMap[e]. type^ <= type^) THEN
          i := e
        ELSE
          j := e
        END
      END;
      IF (i < 0) OR 
         (w. typeRefMap[i]. module^ # module^) OR
         (w. typeRefMap[i]. type^ # type^) THEN
        (* insert new (name, ref) pair into list at index `j' *)
        IF (w. typeRefSize = LEN (w. typeRefMap^)) THEN
          NEW (new, w. typeRefSize*2+pointerGap);
          FOR i := 0 TO w. typeRefSize-1 DO
            new[i] := w. typeRefMap[i]
          END;
          w. typeRefMap := new
        END;
        FOR i := w. typeRefSize-1 TO j BY -1 DO
          w. typeRefMap[i+1] := w. typeRefMap[i]
        END;
        INC (w. typeRefSize);
        w. typeRefMap[j]. module := module;
        w. typeRefMap[j]. type := type;
        w. typeRefMap[j]. ref := w. typeRefSize;
        RETURN w. typeRefSize
      ELSE  (* return old reference id *)
        RETURN -w. typeRefMap[i]. ref
      END
    END LookupType;
  
  BEGIN
    IF (obj = NIL) OR (w. byteWriter. res # BinaryRider.done) THEN
      w. WriteNum (0)
    
    ELSE  (* writing object using "compact" format *)
      IF w. objHash. HasKey (obj) THEN  (* backward reference *)
        w. WriteNum (-w. objHash. Get (obj))
      ELSE  (* first occurence of this object *)
        INC (w. objCounter);
        w. objHash. Set (obj, w. objCounter);
        w. WriteNum (w. objCounter);
        
        (* write object type, followed by its data *)
        type := RT0.TypeOf (obj);
        tref := LookupType (w, type. module. name, type. name);
        w. WriteNum (tref);
        IF (tref > 0) THEN
          w. WriteString (type. module. name^);
          w. WriteString (type. name^)
        END;
        obj. Store (w)
      END
    END
  END WriteObject;
  
PROCEDURE (w: Writer) Disconnect*;
  VAR
    i: LONGINT;
  BEGIN  (* be nice to garbage collector *)
    FOR i := 0 TO LEN (w. typeRefMap^)-1 DO
      w. typeRefMap[i]. module := NIL;
      w. typeRefMap[i]. type := NIL;
      w. typeRefMap[i]. ref := 0
    END;
    w. typeRefMap := NIL;
    w. typeRefSize := 0;
    w. objHash. Destroy();
    w. objHash := NIL;
    w. objCounter := 0
  END Disconnect;

BEGIN
  NEW (errorContext);
  Msg.InitContext (errorContext, "ADT:Object:Storage");
END ADT:Object:Storage.
