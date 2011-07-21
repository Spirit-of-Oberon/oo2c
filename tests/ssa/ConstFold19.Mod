MODULE ConstFold19;

   TYPE
      Test = POINTER TO TestDesc;
      TestDesc = RECORD n: INTEGER END;

   PROCEDURE (self: Test) Proc;
      VAR v: ARRAY self.n OF INTEGER;
   BEGIN
   END Proc;

   END ConstFold19.
