(* 	$Id$	 *)
MODULE OOC:SSA:Opcode;
(*  This modules defines opcodes for SSA instructions.
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


TYPE
  Class* = SHORTINT;
  Subclass* = SHORTINT;

CONST
  const* = 0;
  declRef* = 1;
  enter* = 2;
  exit* = 3;
  get* = 4;
  set* = 5;
  copy* = 6;
  assert* = 7;
  call* = 8;

CONST
  scNone* = 0;
  

PROCEDURE GetName* (opcode: Class; subclass: Subclass; VAR name: ARRAY OF CHAR);
(**Retrieves the symbolic name of an (opcode, subclass) pair.  *)
  BEGIN
    CASE opcode OF
    | const: COPY ("const", name)
    | declRef: COPY ("declref", name)

    | get: COPY ("get", name)
    | set: COPY ("set", name)
    | copy: COPY ("copy", name)
          
    | enter: COPY ("enter", name)
    | exit: COPY ("exit", name)
    | assert: COPY ("assert", name)
    | call: COPY ("call", name)
    END;
  END GetName;

END OOC:SSA:Opcode.
