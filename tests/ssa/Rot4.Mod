MODULE Rot4;

IMPORT SYSTEM;

VAR
  r, s: SET;
BEGIN
  r := {4};
  s := SYSTEM.ROT(r, 1);
END Rot4.
