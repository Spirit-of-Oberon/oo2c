(* 	$Id$	 *)
MODULE OOC:IA32:RuntimeData;
(*  Writes assembler code for run-time data like type descriptors.
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
  TextRider, ADT:String, Sym := OOC:SymbolTable, OOC:SymbolTable:Namespace,
  OOC:Auxiliary:Config, OOC:C:Naming, OOC:IA32:Writer;

CONST
  structTypeDesc = Config.runtimeModule+"__StructDesc";
  
PROCEDURE Write* (w: Writer.Writer; symTab: Sym.Module);
  PROCEDURE ModuleDescr (module: Sym.Module);
    BEGIN
      w. Section (".data");
      w. Instr (".align 4");
      w. Instr (".type _mid,@object");
      w. Instr (".size _mid,4");
      w. Label ("_mid");
      w. Instr (".long .LC0");
      w. Section (".section .rodata");
      w. Label (".LC0");
      w. StringLiteral (symTab. name. str^);
    END ModuleDescr;
  
  BEGIN
    ModuleDescr (symTab);
  END Write;

END OOC:IA32:RuntimeData.
