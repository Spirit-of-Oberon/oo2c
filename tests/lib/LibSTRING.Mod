MODULE LibSTRING;

IMPORT
  Out := Out0, String := Object;

(* This module checks that the predefined type STRING can be used as an
   alias for Object.String.  *)

PROCEDURE Write (s: STRING);
  VAR
    c: String.CharsLatin1;
  BEGIN
    c := s(String.String8).CharsLatin1();
    Out.String(c^); Out.Ln;
  END Write;

PROCEDURE Test*;
  VAR
    s, s2: STRING;  (* STRING in declaration: resolved in CreateNamespace *)
  BEGIN
    s := String.NewLatin1("abc");
    Write (s);

    (* check that STRING is resolved correctly in executable code by
       NewIdentRef: *)
    s2 := s(STRING);

    (* assignment of string constant to STRING variable *)
    s := "ABC1";
    Write (s);
    Write ("ABC2");

    (* assignment of character constant *)
    Write("A");
    Write(42X);
  END Test;
  
END LibSTRING.
