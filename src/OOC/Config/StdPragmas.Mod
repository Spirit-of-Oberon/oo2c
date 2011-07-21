(* 	$Id: StdPragmas.Mod,v 1.2 2003/05/17 18:52:16 mva Exp $	 *)
MODULE OOC:Config:StdPragmas;
(*  Creates standard pragma variables with default values.
    Copyright (C) 2001, 2002, 2003  Michael van Acken

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
  Config, OOC:Config:Autoconf, OOC:Config:Pragmas;


CONST
  defaultWarnings = TRUE;
  defaultAssertions = TRUE;
  (*defaultInitialize = FALSE;   not supported in v2 *)
  defaultStackCheck = FALSE;  (* no effect for gcc back-end *)
  defaultConformantMode = FALSE;
  
  defaultIndexCheck = TRUE;
  defaultDerefCheck = TRUE;
  defaultOverflowCheck = FALSE;
  defaultCaseSelectCheck = TRUE;
  defaultFunctionResultCheck = TRUE;
  defaultTypeGuard = TRUE;
  defaultRangeCheck = FALSE;  (* currently unused *)

  defaultCompiler = "OOC";
  defaultCompilerVersion* = Autoconf.compilerVersion;
  defaultCompilerMajor = Autoconf.compilerMajor;
  defaultCompilerMinor = Autoconf.compilerMinor;

  defaultTargetOS = Autoconf.nameTargetOS;
  defaultTargetInteger = Autoconf.bitsTargetInteger;
  defaultTargetAddress = Autoconf.bitsTargetAddress;
  defaultTargetArch* = "gcc";
  defaultTargetArchMinor = "";
  
VAR
  warnings-: Pragmas.Pragma;
  assertions-: Pragmas.Pragma;
  (*initialize-: Pragmas.Pragma;*)
  stackCheck-: Pragmas.Pragma;
  conformantMode-: Pragmas.Pragma;

  indexCheck-: Pragmas.Pragma;
  derefCheck-: Pragmas.Pragma;
  overflowCheck-: Pragmas.Pragma;
  caseSelectCheck-: Pragmas.Pragma;
  functionResultCheck-: Pragmas.Pragma;
  typeGuard-: Pragmas.Pragma;
  rangeCheck-: Pragmas.Pragma;
  
  compiler-: Pragmas.Pragma;
  compilerVersion-: Pragmas.Pragma;
  compilerMajor-: Pragmas.Pragma;
  compilerMinor-: Pragmas.Pragma;
  
  targetOS-: Pragmas.Pragma;
  targetArch-: Pragmas.Pragma;
  targetArchMinor-: Pragmas.Pragma;
  targetInteger-: Pragmas.Pragma;
  targetAddress-: Pragmas.Pragma;
  targetByteOrder-: Pragmas.Pragma;


PROCEDURE CreateVariables* (s: Pragmas.Section);
  BEGIN
    warnings := s. Set ("Warnings", Config.NewBooleanVar(defaultWarnings));
    assertions := s. Set ("Assertions", Config.NewBooleanVar(defaultAssertions));
    (*initialize := s. Set ("Initialize", Config.NewBooleanVar(defaultInitialize));*)
    stackCheck := s. Set ("StackCheck", Config.NewBooleanVar(defaultStackCheck));
    conformantMode := s. Set ("ConformantMode", Config.NewBooleanVar(defaultConformantMode));
    
    indexCheck := s. Set ("IndexCheck", Config.NewBooleanVar(defaultIndexCheck));
    derefCheck := s. Set ("DerefCheck", Config.NewBooleanVar(defaultDerefCheck));
    overflowCheck := s. Set ("OverflowCheck", Config.NewBooleanVar(defaultOverflowCheck));
    caseSelectCheck := s. Set ("CaseSelectCheck", Config.NewBooleanVar(defaultCaseSelectCheck));
    functionResultCheck := s. Set ("FunctResult", Config.NewBooleanVar(defaultFunctionResultCheck));
    typeGuard := s. Set ("TypeGuard", Config.NewBooleanVar(defaultTypeGuard));
    rangeCheck := s. Set ("RangeCheck", Config.NewBooleanVar(defaultRangeCheck));
    
    compiler := s. Set ("COMPILER", Config.NewStringVar(defaultCompiler));
    compilerVersion := s. Set ("COMPILER_VERSION", Config.NewStringVar(defaultCompilerVersion));
    compilerMajor := s. Set ("COMPILER_MAJOR", Config.NewIntegerVar(defaultCompilerMajor));
    compilerMinor := s. Set ("COMPILER_MINOR", Config.NewIntegerVar(defaultCompilerMinor));
    
    targetOS := s. Set ("TARGET_OS", Config.NewStringVar(defaultTargetOS));
    targetArch := s. Set ("TARGET_ARCH", Config.NewStringVar(defaultTargetArch));
    targetArchMinor := s. Set ("TARGET_ARCH_MINOR", Config.NewStringVar(defaultTargetArchMinor));
    targetInteger := s. Set ("TARGET_INTEGER", Config.NewIntegerVar(defaultTargetInteger));
    targetAddress := s. Set ("TARGET_ADDRESS", Config.NewIntegerVar(defaultTargetAddress));
    targetByteOrder := s. Set ("TARGET_BYTE_ORDER", Config.NewStringVar("unknown"));
  END CreateVariables;

END OOC:Config:StdPragmas.
