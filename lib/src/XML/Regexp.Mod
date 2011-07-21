(*      $Id: Regexp.Mod,v 1.2 2003/04/20 12:43:24 mva Exp $   *)
MODULE XML:Regexp;
(*  Creates regular expression data structure from `children' content model.
    Copyright (C) 2001  Michael van Acken

    This module is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public License
    as published by the Free Software Foundation; either version 2 of
    the License, or (at your option) any later version.

    This module is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with OOC. If not, write to the Free Software Foundation,
    59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*)


IMPORT
  LongStrings, XML:DTD;


TYPE
  Regexp* = POINTER TO RegexpDesc;
  State = LONGINT;
  States = POINTER TO ARRAY OF RECORD
    elem: DTD.String;
    next1, next2: State;
  END;
  RegexpDesc = RECORD
    (DTD.RegexpInfoDesc)
    states: States;
    initialState: State;
    size: State;
  END;

TYPE
  Set = POINTER TO SetDesc;
  Members = POINTER TO ARRAY OF State;
  SetDesc = RECORD
    members: Members;
    size: LONGINT;
  END;

TYPE
  Matcher* = POINTER TO MatcherDesc;
  MatcherDesc = RECORD
    states: States;
    current: Set;
  END;

CONST
  endOfRegexp = -1;


(*PROCEDURE DumpRegexp (regexp: Regexp);
  VAR
    str: ARRAY 128 OF CHAR;
    i: LONGINT;
  BEGIN
    Out.String ("initial state: ");
    Out.LongInt (regexp. initialState, 0);
    Out.Ln;
    FOR i := 0 TO regexp. size-1 DO
      Out.LongInt (i, 0);
      Out.String (": name=");
      IF (regexp. states[i]. elem = NIL) THEN
        Out.String ("*EMPTY*")
      ELSE
        LongStrings.Short (regexp. states[i]. elem^, "?", str);
        Out.String (str)
      END;
      Out.String (", next1=");
      Out.LongInt (regexp. states[i]. next1, 0);
      Out.String (", next2=");
      Out.LongInt (regexp. states[i]. next2, 0);
      Out.Ln
    END
  END DumpRegexp;*)


PROCEDURE New* (contentModel: DTD.CP): Regexp;
(**@precond
   The @oparam{contentModel} is neither @code{EMPTY}, @code{ANY}, nor
   @samp{Mixed}.
   @end precond  *)

  VAR
    regexp: Regexp;
    
  PROCEDURE NewState (): State;
    VAR
      newState: State;
      new: States;
      i: LONGINT;
    BEGIN
      IF (regexp. size = LEN (regexp. states^)) THEN
        NEW (new, LEN (regexp. states^)*2);
        FOR i := 0 TO LEN (regexp. states^)-1 DO
          new[i] := regexp. states[i]
        END;
        FOR i := LEN (regexp. states^) TO LEN (new^)-1 DO
          new[i]. elem := NIL
        END;
        regexp. states := new
      END;
      newState := regexp. size;
      regexp. states[newState]. elem := NIL; (* empty node *)
      regexp. states[newState]. next1 := -2;
      regexp. states[newState]. next2 := -2;
      INC (regexp. size);
      RETURN newState
    END NewState;

  PROCEDURE Convert (cp: DTD.CP; start, end: State);
  (* Converts content particle `cp' into a regular expression machine.  The
     first state of the machine is placed into `start', overwriting the
     state data that is already in there.  All exists from the machine
     point to state `end'  .  *)
    VAR
      subStart: State;
    
    PROCEDURE ConvertCP (cp: DTD.CP; start, end: State);
      PROCEDURE ConvertChoiceList (ptr: DTD.CP; start, end: State);
        VAR
          first1, first2: State;
        BEGIN
          IF (ptr. next = NIL) THEN
            Convert (ptr, start, end)
          ELSE
            first1 := NewState();
            Convert (ptr, first1, end);
            first2 := NewState();
            ConvertChoiceList (ptr. next, first2, end);
            regexp. states[start]. next1 := first1;
            regexp. states[start]. next2 := first2
          END
        END ConvertChoiceList;

      PROCEDURE ConvertSeqList (ptr: DTD.CP; start, end: State);
        VAR
          first1: State;
        BEGIN
          IF (ptr. next = NIL) THEN
            Convert (ptr, start, end)
          ELSE
            first1 := NewState();
            Convert (ptr, start, first1);
            ConvertSeqList (ptr. next, first1, end)
          END
        END ConvertSeqList;

      BEGIN
        WITH cp: DTD.NameCP DO
          regexp. states[start]. elem := cp. name;
          regexp. states[start]. next1 := end;
          regexp. states[start]. next2 := end

        | cp: DTD.ChoiceCP DO
          ConvertChoiceList (cp. list, start, end)

        | cp: DTD.SeqCP DO
          ConvertSeqList (cp. list, start, end)
        END
      END ConvertCP;
      
    BEGIN
      CASE cp. cpMode OF
      | DTD.cpOnce:
        ConvertCP (cp, start, end)
      | DTD.cpOptional:
        subStart := NewState();
        ConvertCP (cp, subStart, end);
        regexp. states[start]. next1 := end;
        regexp. states[start]. next2 := subStart
      | DTD.cpRepeat0:
        subStart := NewState ();
        ConvertCP (cp, subStart, start);
        regexp. states[start]. next1 := end;
        regexp. states[start]. next2 := subStart
      | DTD.cpRepeat1:
        subStart := NewState ();
        ConvertCP (cp, start, subStart);
        regexp. states[subStart]. next1 := end;
        regexp. states[subStart]. next2 := start
      END
    END Convert;
  
  BEGIN
    NEW (regexp);
    NEW (regexp. states, 16);
    regexp. size := 0;
    regexp. initialState := NewState();
    Convert (contentModel, regexp. initialState, endOfRegexp);
    (*DumpRegexp (regexp);*)
    RETURN regexp
  END New;


PROCEDURE NewSet(): Set;
  VAR
    set: Set;
  BEGIN
    NEW (set);
    NEW (set. members, 8);
    set. size := 0;
    RETURN set
  END NewSet;

PROCEDURE Include (set: Set; element: State);
  VAR
    i, j: LONGINT;
    new: Members;
  BEGIN
    i := 0;
    WHILE (i # set. size) & (set. members[i] # element) DO
      INC (i)
    END;
    
    IF (i = set. size) THEN
      IF (i = LEN (set. members^)) THEN
        NEW (new, i*2);
        FOR j := 0 TO i-1 DO
          new[j] := set. members[j]
        END;
        set. members := new
      END;
      set. members[i] := element;
      INC (set. size)
    END
  END Include;

(*PROCEDURE IsMember (set: Set; element: State): BOOLEAN;
  VAR
    i: LONGINT;
  BEGIN
    i := 0;
    WHILE (i # set. size) & (set. members[i] # element) DO
      INC (i)
    END;
    RETURN (i # set. size)
  END IsMember;*)



PROCEDURE NewMatcher* (regexp: Regexp): Matcher;
  VAR
    m: Matcher;
  BEGIN
    NEW (m);
    m. states := regexp. states;
    m. current := NewSet();
    Include (m. current, regexp. initialState);
    RETURN m
  END NewMatcher;

PROCEDURE (m: Matcher) Matches* (name: DTD.String): BOOLEAN;
  VAR
    i: LONGINT;
    s: State;
    newSet: Set;
  BEGIN
    IF (m. current. size = 0) THEN
      (* a previous mismatch reduced the current set of states to the empty 
         set; no need to report further mismatches *)
      RETURN TRUE
    ELSE
      newSet := NewSet();
      i := 0;
      WHILE (i # m. current. size) DO
        s := m. current. members[i];
        IF (s = endOfRegexp) THEN
          (* this pseudo state does not match any element *)
        ELSIF (m. states[s]. elem = NIL) THEN
          Include (m. current, m. states[s]. next1);
          IF (m. states[s]. next1 # m. states[s]. next2) THEN
            Include (m. current, m. states[s]. next2)
          END
        ELSIF (m. states[s]. elem^ = name^) THEN
          Include (newSet, m. states[s]. next1)
        END;
        INC (i)
      END;

      IF (newSet. size # 0) THEN
        m. current := newSet;
        RETURN TRUE
      ELSE
        RETURN FALSE
      END
    END
  END Matches;

PROCEDURE (m: Matcher) EndOfRegexp* (): BOOLEAN;
  VAR
    i: LONGINT;
    s: State;
  BEGIN
    i := 0;
    WHILE (i # m. current. size) DO
      s := m. current. members[i];
      IF (s = endOfRegexp) THEN
        RETURN TRUE
      ELSIF (m. states[s]. elem = NIL) THEN
        Include (m. current, m. states[s]. next1);
        IF (m. states[s]. next1 # m. states[s]. next2) THEN
          Include (m. current, m. states[s]. next2)
        END
      END;
      INC (i)
    END;
    RETURN FALSE
  END EndOfRegexp;

PROCEDURE (m: Matcher) ExpectedTags* (currentElement: DTD.String): DTD.String;
(* pre: `Matches' reported FALSE *)
  VAR
    i, len: LONGINT;
    str: DTD.String;
  BEGIN
    IF (m. current. size = 0) THEN
      RETURN NIL
    ELSE
      (* sort set of element names before putting the string together?*)
      
      len := 0;
      i := 0;
      WHILE (i # m. current. size) DO
        IF (m. current. members[i] = endOfRegexp) THEN
          INC (len, LongStrings.Length (currentElement^)+2)
        ELSIF (m. states[m. current. members[i]]. elem # NIL) THEN
          INC (len, LongStrings.Length (m. states[m. current. members[i]]. elem^)+1)
        END;
        INC (i)
      END;
      
      NEW (str, len+1);
      COPY ("", str^);
      i := 0;
      WHILE (i # m. current. size) DO
        IF (m. current. members[i] = endOfRegexp) THEN
          LongStrings.Append (" /", str^);
          LongStrings.Append (currentElement^, str^)
        ELSIF (m. states[m. current. members[i]]. elem # NIL) THEN
          LongStrings.Append (" ", str^);
          LongStrings.Append (m. states[m. current. members[i]]. elem^, str^)
        END;
        INC (i)
      END;
      RETURN str
    END
  END ExpectedTags;

END XML:Regexp.
