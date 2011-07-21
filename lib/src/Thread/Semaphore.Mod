(* 	$Id: Semaphore.Mod,v 1.1 2003/08/14 07:06:12 mva Exp $	 *)
MODULE Thread:Semaphore [FOREIGN "C";
  LINK
<*IF HAVE_LIB_POSIX4 THEN*>LIB "posix4";<*END*>  (* for Solaris 2.6 *)
<*IF HAVE_LIB_RT THEN*>LIB "rt";<*END*>          (* for Solaris 2.8 *)
    FILE "Semaphore.c";
  END ];
(*  Interface for ths POSIX threads library.
    Copyright (C) 2003  Michael van Acken

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
<*Warnings := FALSE*>

IMPORT
  SYSTEM, RT0, Object, Exception, Thread:PThread;

TYPE
  Semaphore* = POINTER TO SemaphoreDesc;
  SemaphoreDesc = RECORD
    sem: SYSTEM.PTR; 
  END;


PROCEDURE (s: Semaphore) INIT*(value: LONGINT);

PROCEDURE (s: Semaphore) Post*;

PROCEDURE (s: Semaphore) Wait*;

PROCEDURE (s: Semaphore) TryWait*(): BOOLEAN;

PROCEDURE (s: Semaphore) GetValue*(): LONGINT;

PROCEDURE (s: Semaphore) Destroy*;

END Thread:Semaphore.
