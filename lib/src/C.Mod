(* 	$Id: C.Mod,v 1.8 2005/08/31 06:49:48 mva Exp $	 *)
MODULE C [INTERFACE "C"];
(*  Basic data types for interfacing to C code.
    Copyright (C) 1997-1998, 2005  Michael van Acken

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
  SYSTEM, RT0;
  
(**The types from this module are intended to be equivalent to their C
   counterparts.  They may vary depending on your system, but as long as you
   stick to a 32 Bit Unix they should be fairly safe.  *)  

TYPE
  char* = CHAR;
  signedchar* = SHORTINT;                (* signed char *)
  shortint* = INTEGER;                   (* short int *)
  int* = LONGINT;
  set* = SET;                            (* unsigned int, used as set *)
  longint* = LONGINT;                    (* long int *)
  longset* = SET;                        (* unsigned long, used as set *)
  address* = SYSTEM.ADDRESS;
  float* = REAL;
  double* = LONGREAL;

  enum1* = int;
  enum2* = int;
  enum4* = int;
  
  (* if your C compiler uses short enumerations, you'll have to replace the
     declarations above with
  enum1* = SHORTINT;
  enum2* = INTEGER;
  enum4* = LONGINT;
  *)
  
  FILE* = address;  (* this is acually a replacement for `FILE*', i.e., for a pointer type *)
  size_t* = longint;
  uid_t* = int;
  gid_t* = int;


TYPE  (* some commonly used C array types *)
  charPtr1d* = RT0.charPtr1d;
  charPtr2d* = RT0.charPtr2d;
  intPtr1d* = POINTER TO ARRAY OF int;

TYPE  (* C string type, assignment compatible with character arrays and
         string constants *)
  string* = POINTER [CSTRING] TO ARRAY OF char;
  
TYPE
  Proc* = PROCEDURE;

END C.
