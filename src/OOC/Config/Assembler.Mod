(* 	$Id: Assembler.Mod,v 1.10 2004/06/02 08:55:42 mva Exp $	 *)
MODULE OOC:Config:Assembler;
(*  Generates command lines for the assembler.
    Copyright (C) 2002  Michael van Acken

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
  ADT:StringBuffer, URI, URI:Scheme:File;


PROCEDURE AssembleFileCmd* (in, out: URI.URI): STRING;
  VAR
    sb: StringBuffer.StringBuffer;
  BEGIN
    sb := StringBuffer.New("as ");
    sb.Append(in(File.URI).GetPath());
    sb.Append(" -o ");
    sb.Append(out(File.URI).GetPath());
    RETURN sb.ToString();
  END AssembleFileCmd;

END OOC:Config:Assembler.
