MODULE LRealMath [INTERFACE "C"; LINK FILE "LRealMath.c"; LIB "m" END];

CONST
  pi*   = 3.1415926535897932384626433832795028841972D0;
  exp1* = 2.7182818284590452353602874713526624977572D0;


PROCEDURE sqrt*(x: LONGREAL): LONGREAL;
(**Returns the positive square root of x where x >= 0.  *)

PROCEDURE exp*(x: LONGREAL): LONGREAL;
(**Returns the exponential of x for x < Ln(MAX(REAL).  *)

PROCEDURE ln*(x: LONGREAL): LONGREAL;
(**Returns the natural logarithm of x for x > 0.  *)

PROCEDURE sin* (x: LONGREAL): LONGREAL;

PROCEDURE cos* (x: LONGREAL): LONGREAL;
 
PROCEDURE tan*(x: LONGREAL): LONGREAL;
(**Returns the tangent of x where x cannot be an odd multiple of pi/2.  *)
 
PROCEDURE ["asin"] arcsin*(x: LONGREAL): LONGREAL;
(**Returns the arcsine of x, in the range [-pi/2, pi/2] where -1 <= x <= 1.  *)
 
PROCEDURE ["acos"] arccos*(x: LONGREAL): LONGREAL;
(**Returns the arccosine of x, in the range [0, pi] where -1 <= x <= 1.  *)

PROCEDURE ["atan"] arctan*(x: LONGREAL): LONGREAL;
(**Returns the arctangent of x, in the range [-pi/2, pi/2] for all x.  *)
 
PROCEDURE ["pow"] power*(base, exponent: LONGREAL): LONGREAL;
(**Returns the value of the number base raised to the power exponent 
     for base > 0.  *)

PROCEDURE ["lrint"] round*(x: LONGREAL): LONGINT;
(**Returns the value of x rounded to the nearest integer.  *)

PROCEDURE sincos* (x: LONGREAL; VAR sin, cos: LONGREAL);
(**More efficient sin/cos implementation if both values are needed.  *)

PROCEDURE ["atan2"] arctan2* (xn, xd: LONGREAL): LONGREAL;
(**arctan2(xn,xd) is the quadrant-correct arc tangent atan(xn/xd).  If the 
   denominator xd is zero, then the numerator xn must not be zero.  All
   arguments are legal except xn = xd = 0.  *)

PROCEDURE sinh* (x: LONGREAL): LONGREAL;
(**sinh(x) is the hyperbolic sine of x.  The argument x must not be so large 
   that exp(|x|) overflows.  *)

PROCEDURE cosh* (x: LONGREAL): LONGREAL;
(**cosh(x) is the hyperbolic cosine of x.  The argument x must not be so large
   that exp(|x|) overflows.  *)   

PROCEDURE tanh* (x: LONGREAL): LONGREAL;
(**tanh(x) is the hyperbolic tangent of x.  All arguments are legal.  *)

PROCEDURE ["asinh"] arcsinh* (x: LONGREAL): LONGREAL;
(**arcsinh(x) is the arc hyperbolic sine of x.  All arguments are legal.  *)

PROCEDURE ["acosh"] arccosh* (x: LONGREAL): LONGREAL;
(**arccosh(x) is the arc hyperbolic cosine of x.  All arguments greater than 
   or equal to 1 are legal.  *)
   
PROCEDURE ["tanh"] arctanh* (x: LONGREAL): LONGREAL;
(**arctanh(x) is the arc hyperbolic tangent of x.  |x| < 1 - sqrt(em), where 
   em is machine epsilon.  Note that |x| must not be so close to 1 that the 
   result is less accurate than half precision.  *)

END LRealMath.
