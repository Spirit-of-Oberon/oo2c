MODULE Codec:TwofishC [INTERFACE "C"; LINK FILE "TwofishC.c" END];

(*The Twofish implementation's author is Niels Ferguson, and the C code has
  been downloaded as @file{TwofishClib-v0.2.zip} from
  @url{http://www.macfergus.com/niels/code/TwofishClib.html}.

  Changes to the original code to use it as an Oberon-2 library module:
  Concatenated @file{twofish.h} and @file{twofish.c} and renamed the result to
  @file{TwofishC.c}.  (@file{twofish.h} is not needed in this environment.)
  Placed an @code{#undef BIG_ENDIAN} before the @code{#define BIG_ENDIAN}, to
  avoid a name clash with glibc's @file{endian.h}.  *)

IMPORT
  SYSTEM;
  
TYPE
<*PUSH; Warnings:=FALSE*>
  Twofish_key* = RECORD
    s: ARRAY 4, 256 OF LONGINT;
    K: ARRAY 40 OF LONGINT;
  END;
<*POP*>
  
PROCEDURE Twofish_initialise*;

PROCEDURE Twofish_prepare_key*(key: ARRAY OF CHAR;
                               keyLen: LONGINT;
                               VAR xkey: Twofish_key);

PROCEDURE Twofish_encrypt*(xkey: Twofish_key;
                           p: SYSTEM.ADDRESS;
                           c: SYSTEM.ADDRESS);

PROCEDURE Twofish_decrypt*(xkey: Twofish_key;
                           c: SYSTEM.ADDRESS;
                           p: SYSTEM.ADDRESS);
                             
END Codec:TwofishC.
