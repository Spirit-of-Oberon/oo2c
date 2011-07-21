MODULE M [FOREIGN "C"];

VAR
  v["call_me_al"]: BOOLEAN;

TYPE  (* C string type, assignment compatible with character arrays and
         string constants *)
  string* = POINTER [CSTRING] TO ARRAY OF char;

PROCEDURE [PROC_ID=123] P*;
  
END M.
