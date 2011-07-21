MODULE OOC:SSA:Stats;

IMPORT
  Out, Strings, Object, ADT:ArrayList, ADT:Dictionary, OOC:SSA, OOC:SSA:Opcode;

CONST
  maxOpcode = Opcode.lastOpcode;
  subclassCount = Opcode.scReal64+1;
  variantCount = (maxOpcode+1)*subclassCount;
  
TYPE
  Stats = POINTER TO StatsDesc;
  StatsDesc = RECORD
    (Object.ObjectDesc)
    count: ARRAY variantCount OF LONGINT;
  END;
  
VAR
  stage: Dictionary.Dictionary;
  labels: ArrayList.ArrayList;
  
PROCEDURE NewStats(): Stats;
  VAR
    st: Stats;
    i: LONGINT;
  BEGIN
    NEW(st);
    FOR i := 0 TO variantCount-1 DO
      st.count[i] := 0;
    END;
    RETURN st;
  END NewStats;

PROCEDURE AddProcBlock*(label: STRING; pb: SSA.ProcBlock);
  VAR
    st: Stats;
    obj: Object.Object;
    instr: SSA.Instr;
    i: LONGINT;
  BEGIN
    IF stage.HasKey(label) THEN
      obj := stage.Get(label);
      st := obj(Stats);
    ELSE
      st := NewStats();
      stage.Set(label, st);
      labels.Append(label);
    END;

    instr := pb.instrList;
    WHILE (instr # NIL) DO
      i := LONG(LONG(instr.opcode))*subclassCount + instr.subclass;
      INC(st.count[i]);
      instr := instr.nextInstr;
    END;
  END AddProcBlock;

PROCEDURE Write*();
  CONST
    padFirst = 21;
    padRest = 9;
  VAR
    i, j, k: LONGINT;
    obj: Object.Object;
    str: ARRAY 64 OF CHAR;
    stList: POINTER TO ARRAY OF Stats;
    total: POINTER TO ARRAY OF LONGINT;
    o: ARRAY variantCount OF LONGINT;
    s, sub: STRING;
    
  PROCEDURE Pad(l, to: LONGINT);
    VAR
      i: LONGINT;
    BEGIN
      FOR i := l TO to DO
        Out.Char(" ");
      END;
    END Pad;

  PROCEDURE Sort();
    VAR
      i, j: LONGINT;

    PROCEDURE Best(start: LONGINT): LONGINT;
      VAR
        best: LONGINT;
        i: LONGINT;
        
      PROCEDURE Larger(a, b: LONGINT): BOOLEAN;
        VAR
          j: LONGINT;
        BEGIN
          j := LEN(stList^)-1;
          WHILE (j >= 0) DO
            IF (stList[j].count[a] > stList[j].count[b]) THEN
              RETURN TRUE;
            ELSIF (stList[j].count[a] < stList[j].count[b]) THEN
              RETURN FALSE;
            ELSE
              DEC(j);
            END;
          END;
          RETURN FALSE;
        END Larger;

      PROCEDURE AllZero(a: LONGINT): BOOLEAN;
        VAR
          j: LONGINT;
        BEGIN
          FOR j := 0 TO LEN(stList^)-1 DO
            IF (stList[j].count[a] # 0) THEN
              RETURN FALSE;
            END;
          END;
          RETURN TRUE;
        END AllZero;
      
      BEGIN
        best := start;
        FOR i := start+1 TO variantCount-1 DO
          IF Larger(o[i], o[best]) THEN
            best := i;
          END;
        END;
        IF (LEN(stList^) = 0) OR AllZero(o[best]) THEN
          RETURN -1;
        ELSE
          RETURN best;
        END;
      END Best;

    PROCEDURE Swap(VAR a, b: LONGINT);
      VAR
        t: LONGINT;
      BEGIN
        t := a; a := b; b := t;
      END Swap;
    
    BEGIN
      FOR i := 0 TO variantCount-1 DO
        o[i] := i;
      END;

      i := 0;
      LOOP
        IF (i = variantCount-1) THEN
          EXIT;
        ELSE
          j := Best(i);
          IF (j < 0) THEN
            EXIT;
          ELSE
            Swap(o[i], o[j]);
          END;
        END;
        INC(i);
      END;
      WHILE (i < variantCount) DO
        o[i] := -1;
        INC(i);
      END;
    END Sort;

  PROCEDURE Sep();
    VAR
      i: LONGINT;
    BEGIN
      FOR i := 0 TO padFirst+LEN(stList^)*(padRest+1) DO
        Out.Char("-");
      END;
      Out.Ln;
    END Sep;
  
  BEGIN
    NEW(stList, labels.size);
    NEW(total, labels.size);
    FOR i := 0 TO labels.size-1 DO
      obj := stage.Get(labels.array[i]);
      stList[i] := obj(Stats);
      total[i] := 0;
    END;
    
    Pad(6, padFirst);
    Out.String("Opcode");
    FOR i := 0 TO labels.size-1 DO
      s := labels.array[i](STRING);
      IF (s.length > 5) THEN
        sub := s.Substring(s.length-5, s.length);
        IF sub.Equals("-post") THEN
          s := s.Substring(0, s.length-5);
        END;
      END;
      Pad(s.length, padRest);
      Out.Object(s);
    END;
    Out.Ln;
    Sep;
    
    Sort();
    FOR k := 0 TO variantCount-1 DO
      j := o[k];
      IF (j >= 0) THEN
        Opcode.GetName(SHORT(SHORT(j DIV subclassCount)),
                       SHORT(SHORT(j MOD subclassCount)), str);
        Pad(Strings.Length(str), padFirst);
        Out.String(str);
        
        FOR i := 0 TO labels.size-1 DO
          Out.LongInt(stList[i].count[j], padRest+1);
          INC(total[i], stList[i].count[j]);
        END;
        Out.Ln;
      END;
    END;

    Sep;
    Pad(5, padFirst);
    Out.String("TOTAL");
    FOR i := 0 TO labels.size-1 DO
      Out.LongInt(total[i], padRest+1);
    END;
    Out.Ln;
  END Write;

BEGIN
  stage := Dictionary.New();
  labels := ArrayList.New(8);
END OOC:SSA:Stats.
