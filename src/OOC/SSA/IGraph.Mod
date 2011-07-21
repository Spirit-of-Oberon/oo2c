(* 	$Id: IGraph.Mod,v 1.8 2004/07/01 19:12:57 mva Exp $	 *)
MODULE OOC:SSA:IGraph;
(*  Manipulation of interference graph of values' life ranges.
    Copyright (C) 2001-2004  Michael van Acken

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
  Log, Exception;
  
TYPE
  SetType = SET;
  BitMatrix = POINTER TO ARRAY OF ARRAY OF SetType;
  (*BitVector = POINTER TO ARRAY OF SetType;*)
  Color* = LONGINT;
  ColorArray* = POINTER TO ARRAY OF Color;
  Vector* = POINTER TO ARRAY OF SetType;
  
CONST
  bitsPerSet = SIZE(SetType)*8;
  (* number of bits in a @otype{SetType} *)
  emptySet = {};
  
TYPE
  Graph* = POINTER TO GraphDesc;
  GraphDesc = RECORD
    m-: BitMatrix;
    (**This matrix holds the interference matrix of live ranges of values in
       the current region.  If @var{i} and @var{j} are nodes in the graph, then
       @samp{(j MOD bitsPerSet) IN m[i, j DIV bitsPerSet]} indicates that there
       is an edge from node @var{i} to node @var{j}.  The graph is undirected;
       this means that the matrix is symmetric, and an entry for edge @var{i}
       --> @var{j} implies an edge @var{j} --> @var{i}.

       Within a graph, only values within one register set are considered; that
       is, life ranges of integer and floating point values do not intersect if
       they are kept in different register files, and are therefore handled in
       different graphs.  *)

    size-: LONGINT;
    (**Logically, the matrix @ofield{m} is @ofield{size}x@ofield{size}.  The
       size is the number of nodes of the graph, and also the number of columns
       and rows in the matrix.  It holds: @samp{LEN(@ofield{m},0) =
       @ofield{size}} and @samp{LEN(@ofield{m},1) =
       (@ofield{size}+bitsPerSet-1) DIV bitsPerSet}.  *)
  END;


PROCEDURE (g: Graph) Clear;
  VAR
    i, j: LONGINT;
  BEGIN
    FOR i := 0 TO LEN (g. m^, 0)-1 DO
      FOR j := 0 TO LEN (g. m^, 1)-1 DO
        g. m[i, j] := emptySet
      END;
    END;
  END Clear;

PROCEDURE InitGraph (g: Graph; size: LONGINT);
  BEGIN
    NEW (g. m, size, (size+bitsPerSet-1) DIV bitsPerSet);
    g. size := size;
    g. Clear;
  END InitGraph;

PROCEDURE NewGraph* (size: LONGINT): Graph;
  VAR
    g: Graph;
  BEGIN
    NEW (g);
    InitGraph (g, size);
    RETURN g
  END NewGraph;

PROCEDURE (g: Graph) NewVector*(): Vector;
(**Returns a new bit vector with a length equals to the size of the matrix
   of @oparam{g}.  The bit vector is empty. *)
  VAR
    v: Vector;
    i: LONGINT;
  BEGIN
    NEW (v, LEN (g. m^, 1));
    FOR i := 0 TO LEN (v^)-1 DO
      v[i] := emptySet
    END;
    RETURN v
  END NewVector;

PROCEDURE (g: Graph) CopyVector* (v: Vector): Vector;
(**Returns a new bit vector that is a copy of @oparam{v}.  *)
  VAR
    w: Vector;
    i: LONGINT;
  BEGIN
    ASSERT (LEN (v^) = LEN (g. m^, 1));
    NEW (w, LEN (g. m^, 1));
    FOR i := 0 TO LEN (w^)-1 DO
      w[i] := v[i]
    END;
    RETURN w
  END CopyVector;

PROCEDURE (g: Graph) Interfere* (res: LONGINT; live: Vector);
(**Make the live range denoted by @oparam{res} interfere with all ranges
   currently live.  In other word: add the bits in @oparam{live} to the ones in
   the matrix column @samp{g.m[res]}.  *)
  VAR
    m: BitMatrix;
    i: LONGINT;
  BEGIN
    m := g. m;
    FOR i := 0 TO LEN (m^, 1)-1 DO
      m[res, i] := m[res, i]+live[i]
    END;
  END Interfere;

PROCEDURE (g: Graph) MergeRowColumn*(source, target: LONGINT);
  VAR
    m: BitMatrix;
    i: LONGINT;
  BEGIN
    m := g. m;
    EXCL (m[source, source DIV bitsPerSet], source MOD bitsPerSet);
    FOR i := 0 TO LEN(m^, 1)-1 DO
      m[target, i] := m[target, i]+m[source, i];
      m[source, i] := emptySet;
    END;
    FOR i := 0 TO LEN(m^, 0)-1 DO
      IF (source MOD bitsPerSet) IN m[i, source DIV bitsPerSet] THEN
        INCL(m[i, target DIV bitsPerSet], target MOD bitsPerSet);
      END;
      EXCL(m[i, source DIV bitsPerSet], source MOD bitsPerSet);
    END;
  END MergeRowColumn;

PROCEDURE (g: Graph) AddToLive* (res: LONGINT; live: Vector);
(**Adds @oparam{res} to the current live vector of graph @oparam{g}.  Also
   makes this live range interfere with all ranges currently live.  *)
  BEGIN
    g. Interfere (res, live);
    INCL (live[res DIV bitsPerSet], res MOD bitsPerSet)
  END AddToLive;

PROCEDURE (g: Graph) RemoveFromLive* (res: LONGINT; live: Vector);
(**Removes @oparam{res} from the vector @oparam{live}.  *)
  BEGIN
    EXCL (live[res DIV bitsPerSet], res MOD bitsPerSet)
  END RemoveFromLive;

PROCEDURE (g: Graph) In* (res: LONGINT; live: Vector): BOOLEAN;
(**Returns @code{TRUE} if @oparam{res} is element of the vector @oparam{live}.
   *)
  BEGIN
    RETURN (res MOD bitsPerSet) IN live[res DIV bitsPerSet]
  END In;

PROCEDURE (g: Graph) Conflicts* (i, j: LONGINT): BOOLEAN;
(**Returns @code{TRUE} if @oparam{i} conflicts with @oparam{j}.  *)
  VAR
    m: BitMatrix;
  BEGIN
    m := g. m;
    RETURN (j MOD bitsPerSet IN m[i, j DIV bitsPerSet]);
  END Conflicts;

PROCEDURE (g: Graph) NumberOfConflicts* (i: LONGINT): LONGINT;
  VAR
    m: BitMatrix;
    j, c: LONGINT;
  BEGIN
    m := g.m;
    c := 0;
    FOR j := 0 TO g.size-1 DO
      IF g.Conflicts(i, j) THEN
        INC(c);
      END;
    END;
    RETURN c;
  END NumberOfConflicts;

PROCEDURE (g: Graph) MergeVector* (source, dest: Vector);
(**Stores the union of the elements in @oparam{source} and @oparam{dest}
   in @oparam{dest}.  *)
  VAR
    i: LONGINT;
  BEGIN
    ASSERT (LEN (source^) = LEN (dest^));
    FOR i := 0 TO g. size-1 DO
      IF g. In (i, source) THEN
        g. AddToLive (i, dest);
      END;
    END;
  END MergeVector;

PROCEDURE (g: Graph) SymmetricMatrix*;
(**Makes the bit matrix of @oparam{g} symmetric by mirroring elements at the
   matrix diagonal.  This is necessary because the algorithm creating the
   matrix does not ensure the property that @var{i} interfering with @var{j}
   implies @var{j} interfering with @var{i} (``m[i,j] implies m[j,i]'').  *)
  VAR
    x, y: LONGINT;
    m: BitMatrix;
  BEGIN
    m := g. m;
    FOR y := 0 TO LEN (m^)-1 DO
      FOR x := 0 TO LEN (m^)-1 DO
        IF (x MOD bitsPerSet IN m[y, x DIV bitsPerSet]) THEN
          INCL (m[x, y DIV bitsPerSet], y MOD bitsPerSet)
        ELSIF (y MOD bitsPerSet IN m[x, y DIV bitsPerSet]) THEN
          (* ... branch may be unnecessary? *)
          INCL (m[y, x DIV bitsPerSet], x MOD bitsPerSet)
        END
      END;
      (* clear diagonal *)
      EXCL (m[y, y DIV bitsPerSet], y MOD bitsPerSet)
    END
  END SymmetricMatrix;

PROCEDURE (g: Graph) AssertSymmetricMatrix();
  VAR
    x, y: LONGINT;
    m: BitMatrix;
  BEGIN
    m := g.m;
    FOR y := 0 TO LEN(m^)-1 DO
      FOR x := 0 TO LEN(m^)-1 DO
        IF (x MOD bitsPerSet IN m[y, x DIV bitsPerSet]) THEN
          ASSERT((y MOD bitsPerSet) IN m[x, y DIV bitsPerSet]);
        ELSE
          ASSERT(~((y MOD bitsPerSet) IN m[x, y DIV bitsPerSet]));
        END
      END;
    END;
  END AssertSymmetricMatrix;



PROCEDURE (g: Graph) ColorGraphTrivial*(): ColorArray;
(**The most basic graph colorizer: assign as many colors as there are nodes in
   the graph.

   Number of colors equals numbers of nodes.  *)
  VAR
    i: LONGINT;
    ca: ColorArray;
  BEGIN
    NEW (ca, g. size);
    FOR i := 0 TO g. size-1 DO
      ca[i] := i
    END;
    RETURN ca
  END ColorGraphTrivial;

PROCEDURE (g: Graph) ColorGraphSimple*(): ColorArray;
(**Another ridiculously simple graph colorizer: For every node, choose the
   smallest color id that is not already taken by a neighboring node.
   
   Number of colors is bounded by the maximum degree of the nodes of the graph.
   *)
  VAR
    i, j, color, clashes: LONGINT;
    ca: ColorArray;
    m: BitMatrix;
  BEGIN
    NEW (ca, g. size);
    m := g. m;
    FOR i := 0 TO g. size-1 DO
      color := 0;
      REPEAT
        clashes := 0;
        FOR j := 0 TO i-1 DO
          IF ((j MOD bitsPerSet) IN m[i, j DIV bitsPerSet]) &
             (ca[j] = color) THEN
            INC (color);
            INC (clashes)
          END;
        END;
      UNTIL (clashes = 0);
      ca[i] := color
    END;
    RETURN ca
  END ColorGraphSimple;

PROCEDURE (g: Graph) ColorGraphCombinatorial*(): ColorArray;
(**Also known as the combinatorial exploder---slow and limited, but thorough.
   Examines all possible combinations to produce a @var{k}-coloring with
   minimal @var{k}.

   @precond
   The number of non-coalesced life ranges does not exceed @code{MAX(set)}.
   @end precond  *)
  CONST
    sizeSet = MAX(SET)+1;
  VAR
    i, j, k, best, size: LONGINT;
    ca: ColorArray;
    colorAvailableFor: ARRAY sizeSet OF SET;
    p: POINTER TO ARRAY OF LONGINT;
    m: ARRAY sizeSet OF SET;
    done: BOOLEAN;
    
  PROCEDURE Try(index: LONGINT)
  RAISES Exception.Checked;
    VAR
      color, i: LONGINT;
      oldAvail: SET;
    BEGIN
      IF (index = size) THEN             (* all colored: success *)
        RAISE(NEW(Exception.Checked, ""));
      ELSE
        FOR color := 0 TO k-1 DO
          IF (index IN colorAvailableFor[color]) THEN
            ca[index] := color;
            FOR i := 0 TO index-1 DO
              IF (index IN m[i]) THEN
                ASSERT(ca[i] # color);
              END;
            END;
            oldAvail := colorAvailableFor[color];
            colorAvailableFor[color] := colorAvailableFor[color] - m[index];
            Try(index+1);
            colorAvailableFor[color] := oldAvail;
          END;
        END;
      END;
    END Try;

  PROCEDURE Swap(i, j: LONGINT);
    VAR
      x: LONGINT;
    BEGIN
      x := p[i]; p[i] := p[j]; p[j] := x;
    END Swap;

  PROCEDURE Invert(caInverted: ARRAY OF Color);
    VAR
      i: LONGINT;
    BEGIN
      FOR i := 0 TO g.size-1 DO
        ca[p[i]] := caInverted[i];
      END;
    END Invert;
  
  BEGIN
    (* create permutation that sorts live ranges by number of conflicts *)
    NEW(p, g.size);
    FOR i := 0 TO g.size-1 DO
      p[i] := i;
    END;
    FOR i := 0 TO g.size-1 DO
      best := i;
      FOR j := i+1 TO g.size-1 DO
        IF g.NumberOfConflicts(p[j]) > g.NumberOfConflicts(p[best]) THEN
          best := j;
        END;
      END;
      Swap(i, best);
    END;

    (* find out where the ranges with non-zero conflicts end *)
    size := 0;
    WHILE (size # g.size) & (g.NumberOfConflicts(p[size]) > 0) DO
      INC(size);
    END;

    (* create our own interference matrix based on the permutation *)
    g.AssertSymmetricMatrix();
    FOR i := 0 TO sizeSet-1 DO
      m[i] := {};
    END;
    FOR i := 0 TO size-1 DO
      FOR j := 0 TO size-1 DO
        IF g.Conflicts(p[i], p[j]) THEN
          INCL(m[j], i);
        END;
      END;
    END;

    Log.Int("### g.size", g.size);
    Log.Int("### size", size);
    ASSERT(size <= sizeSet);
    
    NEW (ca, g.size);
    IF (size # 0) THEN
      (* find a k-coloring for our reduced graph *)
      ca[0] := 0;            (* first life range has always color 0 *)
      k := 3;
      done := FALSE;
      REPEAT
        FOR i := 0 TO k-1 DO
          colorAvailableFor[i] := {0 .. size-1};
        END;
        colorAvailableFor[0] := colorAvailableFor[0] - m[0];
        
        TRY
          Try(1);
        CATCH Exception.Checked:
          done := TRUE;
        END;
        INC(k);                       (* try again with more colors *)
      UNTIL done;
    END;

    (* verify coloring on reduced matrix *)
    FOR i := 0 TO size-1 DO
      FOR j := 0 TO size-1 DO
        IF i IN m[j] THEN
          ASSERT(ca[i] # ca[j]);
        END;
      END;
    END;
    
    FOR i := size TO g.size-1 DO         (* map all coalesced ranges to 0 *)
      ca[i] := 0;
    END;
    Invert(ca^);

    (* verify coloring *)
    FOR i := 0 TO g.size-1 DO
      FOR j := 0 TO g.size-1 DO
        IF g.Conflicts(i, j) THEN
          ASSERT(ca[i] # ca[j]);
        END;
      END;
    END;
    
    RETURN ca;
  END ColorGraphCombinatorial;

END OOC:SSA:IGraph.
