(* 	$Id: RealStr.Mod,v 1.3 2002/11/16 02:18:47 mva Exp $	 *)
MODULE RealStr;
(*  REAL to string conversion and vice versa.
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

IMPORT
  libc, ConvTypes, RealConv, Real0, Strings;
  
TYPE
  ConvResults* = ConvTypes.ConvResults;
  (**One of @oconst{strAllRight}, @oconst{strOutOfRange},
     @oconst{strWrongFormat}, or @oconst{strEmpty}.  *)

CONST
  strAllRight*=ConvTypes.strAllRight;
  (**The string format is correct for the corresponding conversion.  *)
  strOutOfRange*=ConvTypes.strOutOfRange;
  (**The string is well-formed but the value cannot be represented.  *)
  strWrongFormat*=ConvTypes.strWrongFormat;
  (**The string is in the wrong format for the conversion.  *)
  strEmpty*=ConvTypes.strEmpty;
  (**The given string is empty.  *)

CONST
  prec = 9;
  
PROCEDURE StrToReal*(str: ARRAY OF CHAR;
                     VAR real: REAL; VAR res: ConvResults);
  BEGIN
    res := RealConv.FormatReal (str);
    IF (res IN {strAllRight, strOutOfRange}) THEN
      real := RealConv.ValueReal (str);
    END;
  END StrToReal;

PROCEDURE RealToFloat* (real: REAL; sigFigs: INTEGER;
                        VAR str: ARRAY OF CHAR);
(**Assign to @oparam{str} the possibly truncated string corresponding to the
   value of @oparam{real} in floating-point form.  A sign is included only for
   negative values.  One significant digit is included in the whole number
   part.  The signed exponent part is included only if the exponent value is
   not 0.  If the value of @oparam{sigFigs} is greater than 0, that number of
   significant digits is included, otherwise an implementation-defined number
   of significant digits.  The decimal point shall is not included if there are
   no significant digits in the fractional part.

   For example:

   @example
   value:   3923009     39.23009     0.0003923009
   sigFigs
   1        4E+6        4E+1         4E-4 
   2        3.9E+6      3.9E+1       3.9E-4
   5        3.9230E+6   3.9230E+1    3.9230E-4
   @end example  *)
  VAR
    s: ARRAY 32 OF CHAR;
  BEGIN
    IF (sigFigs < 1) OR (sigFigs > prec) THEN sigFigs := prec; END;
    libc.sprintf(s, "%-+#.*E", sigFigs-1, real);
    Real0.NormalizeFloat (s);
    COPY (s, str);
  END RealToFloat;

PROCEDURE RealToEng* (real: REAL; sigFigs: INTEGER;
                      VAR str: ARRAY OF CHAR);
(**Converts the value of @oparam{real} to floating-point string form, with
   @oparam{sigFigs} significant figures, and copies the possibly truncated
   result to @oparam{str}.  The number is scaled with one to three digits in
   the whole number part and with an exponent that is a multiple of three.  For
   example:

   @example
   value:   3923009     39.23009   0.0003923009
   sigFigs
   1        4E+6        40         400E-6 
   2        3.9E+6      39         390E-6
   5        3.9230E+6   39.230     392.30E-6     
   @end example  *)
  VAR
    s: ARRAY 32 OF CHAR;
  BEGIN
    IF (sigFigs < 1) OR (sigFigs > prec) THEN sigFigs := prec; END;
    libc.sprintf(s, "%-+#.*E", sigFigs-1, real);
    Real0.FormatForEng(s);
    COPY(s, str);
  END RealToEng;

PROCEDURE RealToFixed* (real: REAL; place: INTEGER;
                        VAR str: ARRAY OF CHAR);
(**The call @samp{RealToFixed(real,place,str)} assigns to @oparam{str} the
   possibly truncated string corresponding to the value of @oparam{real} in
   fixed-point form.  A sign is included only for negative values.  At least
   one digit is included in the whole number part.  The value is rounded to the
   given value of @oparam{place} relative to the decimal point.  The decimal
   point is suppressed if @oparam{place} is less than @samp{0}.  For example:

   @example
   value:    3923009         3.923009   0.0003923009
   sigFigs
   -5        3920000         0          0 
   -2        3923010         0          0
   -1        3923009         4          0 
   0         3923009.        4.         0. 
   1         3923009.0       3.9        0.0
   4         3923009.0000    3.9230     0.0004       
   @end example  *)
  VAR
    s: ARRAY 38+32 OF CHAR;
    sigFigs: INTEGER;
  BEGIN
    IF (place < 0) THEN sigFigs := prec; ELSE sigFigs := place END;
    libc.sprintf(s, "%-+#.*f", sigFigs, real);
    Real0.FormatForFixed(s, place);
    COPY (s, str);
  END RealToFixed;

PROCEDURE RealToStr* (real: REAL;
                      VAR str: ARRAY OF CHAR);
(**If the sign and magnitude of @oparam{real} can be shown within the capacity
   of @oparam{str}, the call @samp{RealToStr(real,str)} behaves as the call
   @samp{RealToFixed(real,place,str)}, with a value of @samp{place} chosen to
   fill exactly the remainder of @oparam{str}.  Otherwise, the call behaves as
   the call @samp{RealToFloat(real,sigFigs,str)}, with a value of
   @samp{sigFigs} of at least one, but otherwise limited to the number of
   significant digits that can be included together with the sign and exponent
   part in @oparam{str}.  *)
  VAR
    s: ARRAY 38+32 OF CHAR;
    d: LONGINT;
  BEGIN
    (* use a trial and error approach; this may not be fast, nor unambiguous,
       but it should be correct *)
    RealToFixed(real, -1, s);
    d := LEN (str)-Strings.Length (s)-1;
    IF (d > 0) THEN
      RealToFixed(real, SHORT (d)-1, s);
    ELSIF (d < 0) THEN
      RealToFloat(real, 1, s);
      d := LEN (str)-Strings.Length (s)-1;
      IF (d > 1) THEN          (* room for "." and additional digit *)
        RealToFloat(real, SHORT (d), s);
        IF (Strings.Length(s) < LEN(str)-1) THEN
          (* exponent smaller than expected due to rounding *)
          RealToFloat(real, SHORT (d)+1, s);
        END;
      END;
    END;
    COPY (s, str);
  END RealToStr;

END RealStr.
