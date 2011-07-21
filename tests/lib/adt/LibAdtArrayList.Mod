MODULE LibAdtArrayList;

IMPORT
  ADT:ArrayList, Out;

PROCEDURE Test* ();
  VAR
    list: ArrayList.ArrayList(STRING);
    iter: ArrayList.IterElements(STRING);
    s: STRING;
  BEGIN
    list := NEW(ArrayList.ArrayList(STRING), 8);
    list.Append("a");
    list.Append("b");
    list.Append("c");

    (* long version *)
    iter := list.IterElements();
    WHILE iter.Next(s) DO
      Out.Object(s);
    END;
    Out.Ln;
    
    (* short version *)
    FOR s IN list.IterElements() DO
      Out.Object(s);
    END;
    Out.Ln;
  END Test;

END LibAdtArrayList.
