(*	$Id: SysClock.Mod,v 1.1 2002/05/26 16:27:10 mva Exp $	*)
MODULE SysClock [FOREIGN "C"; LINK FILE "SysClock.c" END]; 
(*  SysClock - facilities for accessing a system clock that records the 
               date and time of day.
    Copyright (C) 1996-1998  Michael Griebling
 
    This module is free software; you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as 
    published by the Free Software Foundation; either version 2 of the
    License, or (at your option) any later version.
 
    This module is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.
 
    You should have received a copy of the GNU Lesser General Public
    License along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*)
<* Warnings := FALSE *>
  
CONST
  maxSecondParts* = 999; (**Most systems have just millisecond accuracy.  *) 
  
  zoneMin* = -780;       (**Time zone minimum minutes.  *)
  zoneMax* =  720;       (**time zone maximum minutes.  *)

  localTime* = MIN(INTEGER);  (**Time zone is inactive and time is local.  *)
  unknownZone* = localTime+1; (**Time zone is unknown.  *)
 
  (* daylight savings mode values *)
  unknown* = -1;   (**Current daylight savings status is unknown.  *)
  inactive* = 0;   (**Daylight savings adjustments are not in effect.  *)
  active* = 1;     (**Daylight savings adjustments are being used.  *)
    
TYPE
  DateTime* =
    RECORD
      year*:           INTEGER;
      (** @ofield{year} > 0 *)
      month*:          SHORTINT;
      (** @ofield{month} = 1 .. 12 *)
      day*:            SHORTINT;
      (** @ofield{day} = 1 .. 31 *)
      hour*:           SHORTINT;
      (** @ofield{hour} = 0 .. 23 *)
      minute*:         SHORTINT;
      (** @ofield{minute} = 0 .. 59 *)
      second*:         SHORTINT;
      (** @ofield{second} = 0 .. 59 *)
      summerTimeFlag*: SHORTINT;
      (**Daylight savings mode.  One of @oconst{inactive}, @oconst{active},
         or @oconst{unknown}.  *)
      fractions*:      INTEGER;
      (**Parts of a second in milliseconds.  @ofield{fractions} = 1
         .. maxSecondParts  *)
      zone*:           INTEGER;
      (**Time zone differential factor which is the number of minutes to add to
         local time to obtain UTC or is set to @oconst{localTime} when time
         zones are inactive.  @ofield{zone} = -780 .. 720  *)
    END;

PROCEDURE CanGetClock*(): BOOLEAN;
(**Returns @code{TRUE} if a system clock can be read; @code{FALSE} otherwise.  *)
   
PROCEDURE CanSetClock*(): BOOLEAN;
(**Returns @code{TRUE} if a system clock can be set; @code{FALSE} otherwise.  *)

PROCEDURE IsValidDateTime* (d: DateTime): BOOLEAN;
(**Returns @code{TRUE} if the value of @oparam{d} represents a valid date and
   time; @code{FALSE} otherwise.  *)

PROCEDURE GetClock* (VAR userData: DateTime);
(**If possible, assigns system date and time of day to @oparam{userData}.  That
   is, the local time is returned.  Error returns @samp{1 Jan 1970}.  *)
   
PROCEDURE SetClock* (userData: DateTime);
(**If possible, sets the system clock to the values of @oparam{userData}.  *)

PROCEDURE MakeLocalTime * (VAR c: DateTime);
(**Fill in the daylight savings mode and time zone for calendar date
   @oparam{c}.  The fields @ofield{c.zone} and @ofield{c.summerTimeFlag} given
   in @oparam{c} are ignored, assuming that the rest of the record describes a
   local time.

   Note 1: On most Unix systems the time zone information is only available for
   dates falling within approximately @samp{1 Jan 1902} to @samp{31 Dec 2037}.
   Outside this range the field @ofield{c.zone} will be set to the unspecified
   @oconst{localTime} value, and @ofield{c.summerTimeFlag} will be set to
   @oconst{unknown}.

   Note 2: The time zone information might not be fully accurate for past (and
   future) years that apply different DST rules than the current year.  Usually
   the current set of rules is used for @emph{all} years between 1902 and 2037.

   Note 3: With DST there is one hour in the year that happens twice: the hour
   after which the clock is turned back for a full hour.  It is undefined which
   time zone will be selected for dates refering to this hour, that is, whether
   DST or normal time zone will be chosen.  *)

PROCEDURE GetTimeOfDay* (VAR sec, usec: LONGINT): LONGINT;
(**PRIVAT.  Don't use this.  Take Time.GetTime instead.  
   Equivalent to the C function `gettimeofday'.  The return value is `0' on 
   success and `-1' on failure; in the latter case `sec' and `usec' are set to
   zero.  *)
   
END SysClock.
