MODULE Language [OOC_EXTENSIONS];

(** This module implements a framework for primitive types and operators for
 * Oberon-2. It is intended to be used within language interpreters or
 * compilers as part of the intermediate representation of a program *)

IMPORT
  ADT:Storable, ADT:String, Object;

TYPE
  Value* = POINTER TO ValueDesc;
  ValueDesc* = RECORD [ABSTRACT] (Storable.ObjectDesc)
    (**This is the base type for all Oberon-2 values.  A @otype{Value} may be
       converted to a @otype{String.String}.  *)
  END;



PROCEDURE InitValue* (v: Value);
  BEGIN
    Storable.Init (v);
  END InitValue;

PROCEDURE (v: Value) [ABSTRACT] Equals* (y: Object.Object): BOOLEAN;
  END Equals;
  
PROCEDURE (v : Value) [ABSTRACT] Compare* (y: Storable.Object): LONGINT;
  END Compare;

PROCEDURE (v: Value) [ABSTRACT] HashCode* (): LONGINT;
  END HashCode;
  
PROCEDURE (v: Value) [ABSTRACT] ToString*() : String.String;
  END ToString;

PROCEDURE (v: Value) Store* (w: Storable.Writer);
  BEGIN
  END Store;

PROCEDURE (v: Value) Load* (r: Storable.Reader);
  BEGIN
  END Load;

END Language.

(* vim: ts=4 
*)
