MODULE M007;

CONST
  aConst* = 1;                           (** A constant.  *)
  bConst* = 2;                           (** Another constant.  *)

TYPE
  A* = LONGINT;                          (** A type alias. *)
  B* = ARRAY OF CHAR;                    (** An array type constructor. *)
  C* = RECORD (** A record definition.  *)
         f1, f2, f3: BOOLEAN;
       END;  

VAR
  x*: A;                                 (** A variable. *)
  y*: C;                                 (** And another variable. *)

PROCEDURE Proc1* (a, b, c: CHAR);
(**A procedure with multiple arguments.  *)
  END Proc1;

PROCEDURE Proc2* (): CHAR;
(**A function procedure.  *)
  END Proc2;
  
END M007.
