MODULE VTable4;

(* Declare an abstract interface. *)

TYPE
  T* = POINTER TO TDesc;
  TDesc* = RECORD [VTABLE, ABSTRACT]
  END;

PROCEDURE (t : T) [ABSTRACT] String* (str : ARRAY OF CHAR);
END String;

PROCEDURE (t : T) [ABSTRACT] Int* (i : LONGINT);
END Int;

PROCEDURE (t : T) [ABSTRACT] Ln*;
END Ln;

PROCEDURE (t : T) [ABSTRACT] Chain* (obj : T; i : LONGINT);
(**Recursively call between VTABLE objects @oparam{t} and @oparam{obj}. 
   Outputs the value of @oparam{i}. If @samp{i>0} calls 
   @samp{obj.Chain(t, i-1)}. *)
END Chain;

END VTable4.
