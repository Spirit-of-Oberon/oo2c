(* 	$Id$	 *)
MODULE OOC:Config:Pragmas:StdPragmas;
(*  Creates standard pragma variables with default values.
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
  Config:Value:Boolean, Config:Value:Integer, OOC:Config:Pragmas;


CONST
  defaultWarnings = FALSE;
  defaultAssertions = TRUE;
  
  defaultIndexCheck = TRUE;
  defaultDerefCheck = TRUE;
  defaultOverflowCheck = FALSE;
  defaultCaseSelectCheck = TRUE;
  defaultFunctionResultCheck = TRUE;
  defaultTypeGuard = TRUE;
  defaultConformantMode = FALSE;

  (*defaultIndexCheck = FALSE;
  defaultDerefCheck = FALSE;
  defaultOverflowCheck = FALSE;
  defaultCaseSelectCheck = FALSE;
  defaultFunctionResultCheck = FALSE;
  defaultTypeGuard = FALSE;
  defaultConformantMode = FALSE;*)

  defaultCompilerMajor = 2;
  
  defaultTargetInteger = 32;
  defaultTargetAddress = 32;
  
VAR
  warnings-: Pragmas.Pragma;
  assertions-: Pragmas.Pragma;
  indexCheck-: Pragmas.Pragma;
  derefCheck-: Pragmas.Pragma;
  overflowCheck-: Pragmas.Pragma;
  caseSelectCheck-: Pragmas.Pragma;
  functionResultCheck-: Pragmas.Pragma;
  typeGuard-: Pragmas.Pragma;
  conformantMode-: Pragmas.Pragma;

  compilerMajor-: Pragmas.Pragma;
  
  targetInteger-: Pragmas.Pragma;
  targetAddress-: Pragmas.Pragma;


PROCEDURE CreateVariables* (s: Pragmas.Section);
  VAR
    dummy: Pragmas.Pragma;
  BEGIN
    warnings := s. Set ("Warnings", Boolean.New (defaultWarnings));
    assertions := s. Set ("Assertions", Boolean.New (defaultAssertions));
    indexCheck := s. Set ("IndexCheck", Boolean.New (defaultIndexCheck));
    derefCheck := s. Set ("DerefCheck", Boolean.New (defaultDerefCheck));
    overflowCheck := s. Set ("OverflowCheck", Boolean.New (defaultOverflowCheck));
    caseSelectCheck := s. Set ("CaseSelectCheck", Boolean.New (defaultCaseSelectCheck));
    functionResultCheck := s. Set ("FunctResult", Boolean.New (defaultFunctionResultCheck));
    typeGuard := s. Set ("TypeGuard", Boolean.New (defaultTypeGuard));
    conformantMode := s. Set ("ConformantMode", Boolean.New (defaultConformantMode));

    compilerMajor := s. Set ("COMPILER_MAJOR", Integer.New (defaultCompilerMajor));
    
    targetInteger := s. Set ("TARGET_INTEGER", Integer.New (defaultTargetInteger));
    targetAddress := s. Set ("TARGET_ADDRESS", Integer.New (defaultTargetAddress));
    

    (* FIXME badly... these have to go eventually *)
    dummy := s. Set ("LIB_HAVE_LIBIMLIB", Boolean.New (TRUE));
    dummy := s. Set ("LIB_HAVE_LIBM", Boolean.New (TRUE));
    dummy := s. Set ("LIB_HAVE_LIBZ", Boolean.New (TRUE));
    dummy := s. Set ("LIB_HAVE_LIBJPEG", Boolean.New (TRUE));
    dummy := s. Set ("LIB_HAVE_LIBTIFF", Boolean.New (TRUE));
    dummy := s. Set ("LIB_HAVE_LIBPNG", Boolean.New (TRUE));
    dummy := s. Set ("LIB_HAVE_LIBGIF", Boolean.New (TRUE));
    dummy := s. Set ("LIB_HAVE_LIBXNET", Boolean.New (FALSE));
  END CreateVariables;

END OOC:Config:Pragmas:StdPragmas.
