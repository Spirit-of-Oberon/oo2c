(* 	$Id$	 *)
MODULE OOC:Config:CCompiler;
(*  Generates command lines for the C compiler and linker.
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
  Strings, ADT:String, URI, URI:Scheme:File,
  Config:Section:Options, OOC:Repository, OOC:Auxiliary:Config;

PROCEDURE CompileFileCmd* (config: Config.Config; in, out: URI.URI;
                           VAR cmd: ARRAY OF CHAR);
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
      m := config. repositories. GetModule (Config.runtimeModule);
      ASSERT (m # NIL);  (* ... if this fails, then we have no __oo2c.h *)
      uri := m. GetURI (Repository.modModuleSource);
      f := uri(File.URI);
      f. StripSegments (1);
      uri := f. MakeRelative (File.GetCwd());
      RETURN uri(File.URI)
    END GetURIofRT;
  
  BEGIN
    COPY ("gcc -Wall -W -Wno-unused -Wno-format -Werror -g -pipe", cmd);
    
    include := config. repositories. GetIncludePaths();
    FOR i := 0 TO LEN (include^)-1 DO
      Strings.Append (" -I", cmd);
      Strings.Append (include[i]. array^, cmd)
    END;
    
    (* add include path for the run-time header files; in theory, this include
       directory should have the highest priority, but _only_ for run-time
       headers, not for everything else that might be located there; for this
       reason, this particular include might be better searched last *)
    f := GetURIofRT();
    f. GetPath (str);
    Strings.Append (" -I", cmd);
    Strings.Append (str, cmd);
    
    Strings.Append (" -c ", cmd);
    in(File.URI). GetPath (str);
    Strings.Append (str, cmd);
    Strings.Append (" -o ", cmd);
    out(File.URI). GetPath (str);
    Strings.Append (str, cmd);
  END CompileFileCmd;

PROCEDURE LinkProgramCmd* (config:Config.Config; execFile: URI.URI;
                           VAR cmd: ARRAY OF CHAR);
  VAR
    str: ARRAY 1024 OF CHAR;
  BEGIN
    COPY ("gcc -g -pipe -o ", cmd);
    execFile(File.URI). GetPath (str);
    Strings.Append (str, cmd)
  END LinkProgramCmd;

END OOC:Config:CCompiler.
