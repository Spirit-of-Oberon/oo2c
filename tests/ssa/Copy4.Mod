MODULE Copy4;

VAR
  y: RECORD a, b: INTEGER; END;
BEGIN
  COPY("abc", y);
END Copy4.
