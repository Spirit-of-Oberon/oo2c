(* 	$Id$	 *)
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
  Strings, ADT:String, URI, URI:Scheme:File,
  Config:Section:Options, OOC:Config, OOC:Repository;


PROCEDURE AssembleFileCmd* (in, out: URI.URI; VAR cmd: ARRAY OF CHAR);
  VAR
    str: ARRAY 2*1024 OF CHAR;
    include: String.StringArrayPtr;
    i: LONGINT;
    f: File.URI;
    
  PROCEDURE GetURIofRT(): File.URI;
    VAR
      m: Repository.Module;
      uri: URI.HierarchicalURI;
      f: File.URI;
    BEGIN
      m := Config.repositories. GetModule (Config.runtimeModule);
      ASSERT (m # NIL);  (* ... if this fails, then we have no __oo2c.h *)
      uri := m. GetURI (Repository.modModuleSource, TRUE);
      f := uri(File.URI);
      f. StripSegments (1);
      RETURN f;
    END GetURIofRT;
  
  BEGIN
    COPY ("as ", cmd);
    
    in(File.URI). GetPath (str);
    Strings.Append (str, cmd);
    Strings.Append (" -o ", cmd);
    out(File.URI). GetPath (str);
    Strings.Append (str, cmd);
  END AssembleFileCmd;

END OOC:Config:Assembler.
