MODULE Language [OOC_EXTENSIONS];

(** This module implements a framework for primitive types and operators for
 * Oberon-2. It is intended to be used within language interpreters or
 * compilers as part of the intermediate representation of a program *)

IMPORT
  ADT:Object, ADT:String;

TYPE
  Type* = POINTER TO TypeDesc;
  TypeDesc* = RECORD [ABSTRACT] (Object.ObjectDesc)
    (** This is the base type for all Oberon-2 types. Sub-types of @otype{Type}
     * generally provide a function @otype{Value}, which converts a primitive
     * type to a @otype{Value}.  *) 
  END;

  Value* = POINTER TO ValueDesc;
  ValueDesc* = RECORD [ABSTRACT] (Object.ObjectDesc)
    (**This is the base type for all Oberon-2 values. Each value has an *
       associtated type (the @ofield{type} field). A @otype{Value} may be *
       converted to a @otype{String.String}, but otherwise its main function is
       to * expose a read-only field @ofield{type} via which expressions may do
       * their work.  *)

    type-: Type;            
    (** The type of this value. *)
  END;



PROCEDURE InitValue* (v: Value; type: Type);
  BEGIN
    Object.Init (v);
    v. type := type
  END InitValue;

PROCEDURE (v: Value) [ABSTRACT] Equals* (y: Object.Object): BOOLEAN;
  END Equals;
  
PROCEDURE (v : Value) [ABSTRACT] Compare* (y: Object.Object): LONGINT;
  END Compare;

PROCEDURE (v: Value) [ABSTRACT] HashCode* (): LONGINT;
  END HashCode;
  
PROCEDURE (v: Value) [ABSTRACT] ToString*() : String.String;
  END ToString;

PROCEDURE (v: Value) Store* (w: Object.Writer);
  BEGIN
    w. WriteObject (v. type)
  END Store;

PROCEDURE (v: Value) Load* (r: Object.Reader);
  VAR
    obj: Object.Object;
  BEGIN
    r. ReadObject (obj);
    v. type := obj(Type)
  END Load;


PROCEDURE InitType* (t: Type);
  BEGIN
    Object.Init (t)
  END InitType;

PROCEDURE (t: Type) [ABSTRACT] ToString*() : String.String;
END ToString;

PROCEDURE (t: Type) [ABSTRACT] ValueOf* (s : ARRAY OF CHAR): Value;
(** Return a value described by the string @oparam{s}. The result may be NIL if
 * the string has the wrong format (perhaps should return Status code to
 * indicate this) *)
END ValueOf;



END Language.

(* vim: ts=4 
*)
