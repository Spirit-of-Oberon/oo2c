(* 	$Id$	 *)
MODULE OOC:Config:Pragmas:StdPragmas;
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
  Config:Value:Boolean, Config:Value:Integer, Config:Value:String,
  OOC:Config:Autoconf, OOC:Config:Pragmas;


CONST
  defaultWarnings = TRUE;
  defaultAssertions = TRUE;
  defaultInitialize = FALSE;  (* not supported in v2 *)
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
  defaultTargetArch = "gcc";
  defaultTargetArchMinor = "";
  
VAR
  warnings-: Pragmas.Pragma;
  assertions-: Pragmas.Pragma;
  initialize-: Pragmas.Pragma;
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
    warnings := s. Set ("Warnings", Boolean.New (defaultWarnings));
    assertions := s. Set ("Assertions", Boolean.New (defaultAssertions));
    initialize := s. Set ("Initialize", Boolean.New (defaultInitialize));
    stackCheck := s. Set ("StackCheck", Boolean.New (defaultStackCheck));
    conformantMode := s. Set ("ConformantMode", Boolean.New (defaultConformantMode));
    
    indexCheck := s. Set ("IndexCheck", Boolean.New (defaultIndexCheck));
    derefCheck := s. Set ("DerefCheck", Boolean.New (defaultDerefCheck));
    overflowCheck := s. Set ("OverflowCheck", Boolean.New (defaultOverflowCheck));
    caseSelectCheck := s. Set ("CaseSelectCheck", Boolean.New (defaultCaseSelectCheck));
    functionResultCheck := s. Set ("FunctResult", Boolean.New (defaultFunctionResultCheck));
    typeGuard := s. Set ("TypeGuard", Boolean.New (defaultTypeGuard));
    rangeCheck := s. Set ("RangeCheck", Boolean.New (defaultRangeCheck));
    
    compiler := s. Set ("COMPILER", String.New (defaultCompiler));
    compilerVersion := s. Set ("COMPILER_VERSION", String.New (defaultCompilerVersion));
    compilerMajor := s. Set ("COMPILER_MAJOR", Integer.New (defaultCompilerMajor));
    compilerMinor := s. Set ("COMPILER_MINOR", Integer.New (defaultCompilerMinor));
    
    targetOS := s. Set ("TARGET_OS", String.New (defaultTargetOS));
    targetArch := s. Set ("TARGET_ARCH", String.New (defaultTargetArch));
    targetArchMinor := s. Set ("TARGET_ARCH_MINOR", String.New (defaultTargetArchMinor));
    targetInteger := s. Set ("TARGET_INTEGER", Integer.New (defaultTargetInteger));
    targetAddress := s. Set ("TARGET_ADDRESS", Integer.New (defaultTargetAddress));
    targetByteOrder := s. Set ("TARGET_BYTE_ORDER", String.New ("unknown"));
  END CreateVariables;

END OOC:Config:Pragmas:StdPragmas.
