(* 	$Id$	 *)
MODULE OOC:Make:WriteMainFileC;
(*  Generates the main file of a program.
    Copyright (C) 2001, 2002  Michael van Acken

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
  Channel, Files, TextRider, OOC:Error, OOC:Repository;

  
PROCEDURE WriteFile*(module: Repository.Module;
                     imports: ARRAY OF Repository.Module;
                     VAR res: Error.Msg);
  VAR
    ch: Channel.Channel;
    w: TextRider.Writer;
  
  PROCEDURE WriteModuleName (w: TextRider.Writer; 
                             prefix: ARRAY OF CHAR;
                             module: Repository.Module;
                             suffix: ARRAY OF CHAR);
    VAR
      str: ARRAY 1024 OF CHAR;
      i: LONGINT;
    BEGIN
      COPY (module. name^, str);
      i := 0;
      WHILE (str[i] # 0X) DO
        IF (str[i] = ":") THEN str[i] := "_" END;
        INC (i)
      END;
      w. WriteString (prefix);
      w. WriteString (str);
      w. WriteString (suffix);
      w. WriteLn;
    END WriteModuleName;
  
  PROCEDURE WriteModules (w: TextRider.Writer; prefix, suffix: ARRAY OF CHAR);
    VAR
      i: LONGINT;
    BEGIN
      FOR i := 0 TO LEN(imports)-1 DO
        IF ~imports[i].ifData.NoObjectFile() THEN
          WriteModuleName (w, prefix, imports[i], suffix);
        END;
      END;
    END WriteModules;
  
  BEGIN
    ch := module. GetOutputChannel (Repository.modMainFileC, TRUE, res);
    IF (res = Channel.done) THEN
      w := TextRider.ConnectWriter (ch);
      w. WriteString ('#include "RT0'+Repository.headerSuffix+'"');
      w. WriteLn;
      WriteModules (w, "extern void OOC_", "_init0(void);");
      w. WriteLn;
      
      w. WriteString ("int main (int argc, char *argv[]) {");
      w. WriteLn; w. WriteString ("  RT0__argc = (OOC_INT32)argc;");
      w. WriteLn; w. WriteString ("  RT0__argv = (OOC_CHAR8**)argv;");
      w. WriteLn;
      WriteModules (w, "  OOC_", "_init0();");
      w. WriteString ("  return 0;  /* _program_exit_code */");
      w. WriteLn;
      w. WriteString ("}");
      w. WriteLn;
      
      res := w. res;
      ch(Files.File). Register;
      IF (ch. res # NIL) & (res = NIL) THEN
        res := ch. res
      END
    END
  END WriteFile;

END OOC:Make:WriteMainFileC.
