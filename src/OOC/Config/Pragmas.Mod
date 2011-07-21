(* 	$Id: Pragmas.Mod,v 1.6 2003/05/17 18:52:16 mva Exp $	 *)
MODULE OOC:Config:Pragmas;
(*  Implements pragma variables.
    Copyright (C) 2001  Michael van Acken

    This file is part of OOC.

    OOC is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.  

    OOC is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
    License for more details. 

    You should have received a copy of the GNU General Public License
    along with OOC. If not, write to the Free Software Foundation, 59
    Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*)

IMPORT
  Config, Config:Parser, Config:Section:Options;


TYPE
  Pragma* = Options.Option;

TYPE
  Section* = POINTER TO SectionDesc;
  SectionDesc = RECORD
    (Options.SectionDesc)
  END;

TYPE
  CharPos* = LONGINT;
  Variable = POINTER TO VariableDesc;
  ValueArray = POINTER TO ARRAY OF Config.Variable;
  CharPosArray = POINTER TO ARRAY OF CharPos;
  VariableDesc = RECORD
    next: Variable;
    name: STRING;
    
    values: ValueArray;
    valuePos: CharPosArray;
    numValues: LONGINT;
  END;

TYPE
  History* = POINTER TO HistoryDesc;
  HistoryDesc = RECORD
    startVariables: Section;
    varList: Variable;
    lastCharPos: CharPos;
    
    pushes: CharPosArray;
    numPushes-: LONGINT;
  END;



PROCEDURE Init (s: Section; id: Parser.String; prototypeMap: Config.PrototypeMap);
  BEGIN
    Options.Init (s, id, prototypeMap)
  END Init;

PROCEDURE New*(): Section;
  CONST
    sectionName = "pragmas";
  VAR
    s: Section;
    prototypeMap: Config.PrototypeMap;
  BEGIN
    NEW(s);
    prototypeMap := NEW(Config.PrototypeMap);
    Config.SetPrototype(prototypeMap, "boolean", Config.NewBooleanVar(FALSE));
    Config.SetPrototype(prototypeMap, "integer", Config.NewIntegerVar(0));
    Config.SetPrototype(prototypeMap, "string", Config.NewStringVar(""));
    Init(s, sectionName, prototypeMap);
    RETURN s
  END New;


PROCEDURE (s: Section) Copy* (dest: Options.Section);
  BEGIN
    s. Copy^ (dest)
  END Copy;

PROCEDURE (s: Section) Clone* (): Section;
  VAR
    new: Section;
  BEGIN
    NEW (new);
    s. Copy (new);
    RETURN new
  END Clone;

(*------------------------------------------------------------------------*)

PROCEDURE InitHistory (h: History; startVariables: Section);
  BEGIN
    h. startVariables := startVariables;
    h. varList := NIL;
    h. lastCharPos := -1;
    h. pushes := NIL;
    h. numPushes := 0;
  END InitHistory;

PROCEDURE NewHistory* (startVariables: Section): History;
(* @precond
   The variables and values in @oparam{startVariables} are static.  That is,
   neither @oparam{startVariables} nor its contents are modified in any way
   during the lifetime of the created instance of @otype{History}.
   @end precond *)
  VAR
    h: History;
  BEGIN
    NEW (h);
    InitHistory (h, startVariables);
    RETURN h
  END NewHistory;

PROCEDURE GetValue (h: History; var: Variable;
                    charPos: CharPos): Config.Variable;
  VAR
    l, r, m: LONGINT;
  BEGIN
    ASSERT (var # NIL);
    IF (charPos < var. valuePos[0]) THEN
      (* if the given character position is before the very first assignment,
         then take the variable's value from the list inherited from the file's
         environment *)
      RETURN h. startVariables. GetValue (var. name)
    ELSE
      l := 0; r := var. numValues;
      WHILE (l+1 # r) DO
        (* invariant:
             for all 0<=i<=l: h.valuePos[i] <= charPos  _and_
             for all r<=i<h.numValues: h.valuePos[i] > charPos *)
        m := (l+r) DIV 2;
        IF (var. valuePos[m] <= charPos) THEN
          l := m
        ELSE
          r := m
        END
      END;
      RETURN var. values[l]
    END
  END GetValue;

PROCEDURE (h: History) GetValue* (name: STRING; charPos: CharPos): Config.Variable;
  VAR
    var: Variable;
  BEGIN
    var := h. varList;
    WHILE (var # NIL) & ~var.name.Equals(name) DO
      var := var. next
    END;
    IF (var = NIL) THEN
      RETURN h. startVariables. GetValue (name)
    ELSE
      RETURN GetValue (h, var, charPos)
    END
  END GetValue;

PROCEDURE LastCharPos (h: History; charPos: CharPos);
  BEGIN
    ASSERT (charPos > h. lastCharPos);
    h. lastCharPos := charPos
  END LastCharPos;

PROCEDURE SetValue (var: Variable;charPos: CharPos;
                    value: Config.Variable);
  CONST
    incrementSize = 4;
  
  PROCEDURE Extend (var: Variable; size: LONGINT);
    VAR
      i: LONGINT;
      newValues: ValueArray;
      newPos: CharPosArray;
    BEGIN
      NEW (newValues, size);
      NEW (newPos, size);
      
      FOR i := 0 TO LEN (var. values^)-1 DO
        newValues[i] := var. values[i];
        newPos[i] := var. valuePos[i]
      END;
      FOR i := LEN (var. values^) TO size-1 DO
        newValues[i] := NIL;
        newPos[i] := -1
      END;
      
      var. values := newValues;
      var. valuePos := newPos;
    END Extend;
  
  BEGIN
    IF (var. numValues = LEN (var. values^)) THEN (* oops, we are full *)
      Extend (var, var. numValues+incrementSize)
    END;
    
    var. values[var. numValues] := value;
    var. valuePos[var. numValues] := charPos;
    INC (var. numValues)
  END SetValue;

PROCEDURE (h: History) SetValue* (name: STRING;
                                  charPos: CharPos;
                                  value: Config.Variable);
(* @precond
   @oparam{charPos} is strict monotonically increasing.  That is, if first
   the value of variable @samp{A} is set, and then the value of variable
   @samp{B}, then the relation @samp{charPos(A) < charPos(B)} must hold.
   @end precond *)
  CONST
    initialSize = 4;
  VAR
    var: Variable;
  BEGIN
    LastCharPos (h, charPos);
    
    var := h. varList;
    WHILE (var # NIL) & ~var.name.Equals(name) DO
      var := var. next
    END;
    
    IF (var = NIL) THEN
      (* this variable has not been set yet; create new entry for it and
         initialize it *)
      NEW (var);
      var. next := h. varList;
      var. name := name;
      NEW (var. values, initialSize);
      NEW (var. valuePos, initialSize);
      var. numValues := 0;
      
      h. varList := var                  (* add to history list *)
    END;
    SetValue (var, charPos, value)
  END SetValue;

PROCEDURE (h: History) Push*;
  VAR
    new: CharPosArray;
    i: LONGINT;
  BEGIN
    IF (h. pushes = NIL) THEN
      NEW (h. pushes, 4)
    ELSIF (h. numPushes = LEN (h. pushes^)) THEN
      NEW (new, LEN (h. pushes^)*2);
      FOR i := 0 TO LEN (h. pushes^)-1 DO
        new[i] := h. pushes[i]
      END
    END;
    h. pushes[h. numPushes] := h. lastCharPos;
    INC (h. numPushes)
  END Push;

PROCEDURE (h: History) Pop* (charPos: CharPos);
  VAR
    pushPos: CharPos;
    var: Variable;
    oldValue: Config.Variable;
  BEGIN
    LastCharPos (h, charPos);
    
    pushPos := h. pushes[h. numPushes-1];
    var := h. varList;
    WHILE (var # NIL) DO
      IF (var. valuePos[var. numValues-1] > pushPos) THEN
        oldValue := GetValue (h, var, pushPos);
        IF (oldValue # NIL) THEN
          (* only restore old value if the variable existed before the
             PUSH operation *)
          SetValue (var, charPos, oldValue)
        END
      END;
      var := var. next
    END;
    
    DEC (h. numPushes)
  END Pop;

END OOC:Config:Pragmas.
