MODULE FFTC [INTERFACE "C"; LINK FILE "FFTC.c"; LIB "m" END];

IMPORT 
  Type;

TYPE
  Complex = Type.Complex;

PROCEDURE FFT* (VAR a : ARRAY OF Complex; len : LONGINT; forward : BOOLEAN);

PROCEDURE FFT2* (VAR a : ARRAY OF Complex; len : LONGINT; forward : BOOLEAN);

END FFTC.
