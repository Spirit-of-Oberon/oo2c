MODULE LibSTRING;

IMPORT
  Out := Out0, String := Language:String0;

(* This module checks that the predefined type STRING can be used as an
   alias for Language:String0.String.  *)

PROCEDURE Test*;
  VAR
    s, s2: STRING;  (* STRING in declaration: resolved in CreateNamespace *)
    c: String.CharsLatin1;
  BEGIN
    s := String.NewLatin1("abc");
    c := s(String.String8).CharsLatin1();
    Out.String(c^); Out.Ln;

    (* check that STRING is resolved correctly in executable code by
       NewIdentRef: *)
    s2 := s(STRING);
  END Test;
  
END LibSTRING.
