(* 	$Id$	 *)
MODULE RealMath [INTERFACE "C"; LINK FILE "RealMath.c"; LIB "m" END];
(*  Math functions for REAL.
    Copyright (C) 2002  Michael van Acken

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

CONST
  pi*   = 3.1415926535897932384626433832795028841972E0;
  exp1* = 2.7182818284590452353602874713526624977572E0;


PROCEDURE ["sqrtf"] sqrt*(x: REAL): REAL;
(**Returns the positive square root of x where x >= 0.  *)

PROCEDURE ["expf"] exp*(x: REAL): REAL;
(**Returns the exponential of x for x < Ln(MAX(REAL).  *)

PROCEDURE ["lnf"] ln*(x: REAL): REAL;
(**Returns the natural logarithm of x for x > 0.  *)

PROCEDURE ["sinf"] sin* (x: REAL): REAL;

PROCEDURE ["cosf"] cos* (x: REAL): REAL;
 
PROCEDURE ["tanf"] tan*(x: REAL): REAL;
(**Returns the tangent of x where x cannot be an odd multiple of pi/2.  *)
 
PROCEDURE ["asinf"] arcsin*(x: REAL): REAL;
(**Returns the arcsine of x, in the range [-pi/2, pi/2] where -1 <= x <= 1.  *)
 
PROCEDURE ["acosf"] arccos*(x: REAL): REAL;
(**Returns the arccosine of x, in the range [0, pi] where -1 <= x <= 1.  *)

PROCEDURE ["atanf"] arctan*(x: REAL): REAL;
(**Returns the arctangent of x, in the range [-pi/2, pi/2] for all x.  *)
 
PROCEDURE ["powf"] power*(base, exponent: REAL): REAL;
(**Returns the value of the number base raised to the power exponent 
     for base > 0.  *)

PROCEDURE ["lrintf"] round*(x: REAL): LONGINT;
(**Returns the value of x rounded to the nearest integer.  *)

PROCEDURE ["sincosf"] sincos* (x: REAL; VAR sin, cos: REAL);
(**More efficient sin/cos implementation if both values are needed.  *)

PROCEDURE ["atan2f"] arctan2* (xn, xd: REAL): REAL;
(**arctan2(xn,xd) is the quadrant-correct arc tangent atan(xn/xd).  If the 
   denominator xd is zero, then the numerator xn must not be zero.  All
   arguments are legal except xn = xd = 0.  *)

PROCEDURE ["sinhf"] sinh* (x: REAL): REAL;
(**sinh(x) is the hyperbolic sine of x.  The argument x must not be so large 
   that exp(|x|) overflows.  *)

PROCEDURE ["coshf"] cosh* (x: REAL): REAL;
(**cosh(x) is the hyperbolic cosine of x.  The argument x must not be so large
   that exp(|x|) overflows.  *)   

PROCEDURE ["tanhf"] tanh* (x: REAL): REAL;
(**tanh(x) is the hyperbolic tangent of x.  All arguments are legal.  *)

PROCEDURE ["asinhf"] arcsinh* (x: REAL): REAL;
(**arcsinh(x) is the arc hyperbolic sine of x.  All arguments are legal.  *)

PROCEDURE ["acoshf"] arccosh* (x: REAL): REAL;
(**arccosh(x) is the arc hyperbolic cosine of x.  All arguments greater than 
   or equal to 1 are legal.  *)
   
PROCEDURE ["tanhf"] arctanh* (x: REAL): REAL;
(**arctanh(x) is the arc hyperbolic tangent of x.  |x| < 1 - sqrt(em), where 
   em is machine epsilon.  Note that |x| must not be so close to 1 that the 
   result is less accurate than half precision.  *)

END RealMath.
