MODULE VTable3 [FOREIGN "C"; LINK FILE "VTable3.cpp"; LIB "stdc++" END];

(*Implement an abstract VTABLE interface using a foreign "c++" object. 
  Note that only the constructor is exported. The object conforms to the
  binary interface specified by VTable4.T. *)

IMPORT VTable4;

PROCEDURE NewT* () : VTable4.T;

END VTable3.
