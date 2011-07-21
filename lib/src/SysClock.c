/*	$Id: SysClock.c,v 1.3 2002/12/28 13:21:27 mva Exp $	*/
/*  SysClock - facilities for accessing a system clock that records the 
               date and time of day.
    Copyright (C) 1996-2000, 2002  Michael Griebling, Michael van Acken
 
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
*/
#include <errno.h>

#include <SysClock.d>
#include <__config.h>

#if TIME_WITH_SYS_TIME
# include <sys/time.h>
# include <time.h>
#else
# if HAVE_SYS_TIME_H
#  include <sys/time.h>
# else
#  include <time.h>
# endif
#endif
#if HAVE_UNISTD_H
#include <unistd.h>
#elif HAVE_IO_H
#include <io.h>
#endif


OOC_BOOLEAN SysClock__CanGetClock(void) {
#if HAVE_GETTIMEOFDAY
  struct timeval t;
  return (OOC_BOOLEAN)(gettimeofday(&t, NULL) == 0);
#else
  return 0;
#endif
}

OOC_BOOLEAN SysClock__CanSetClock(void) {
#if HAVE_SETTIMEOFDAY
  return (OOC_BOOLEAN)(geteuid() == 0);  /* root can set clock */
#else
  return 0;
#endif
}

static int is_leap_year (int year) {
  return ((year % 4) == 0) && ((year % 100 != 0) || (year % 400 == 0));
}

OOC_INT8 SysClock__DaysPerMonth(OOC_INT8 mon, OOC_INT16 year) {
  switch(mon) {
  case 2:
    if (is_leap_year(year)) {
      return 29;
    } else {
      return 28;
    }
  case 4:
  case 6: 
  case 9:
  case 11: 
    return 30;
  default: 
    return 31;
  }
}

OOC_BOOLEAN SysClock__IsValidDateTime(const SysClock__DateTime *d) {
  return 
    (d->month > 0) && (d->month <= 12) &&
    (d->day > 0) && (d->day <= SysClock__DaysPerMonth(d->month, d->year)) &&
    ((d->zone <= SysClock__unknownZone) || 
     ((d->zone >= SysClock__zoneMin) && (d->zone <= SysClock__zoneMax))) &&
    (d->hour >= 0) && (d->hour < 24) &&
    (d->minute >= 0) && (d->minute < 60) &&
    (d->second >= 0) && (d->second < 60) &&
    (d->fractions >= 0) && (d->fractions <= SysClock__maxSecondParts);
}

static OOC_INT16 calculate_zone (struct tm *local_time, time_t utc_time) {
  /* Determines the local time zone by calculating the difference in minutes 
     between the broken-down local time and broken-down UTC.
     side: The static broken-down time structure, which is shared by ctime(),
       gmtime(), and localtime(), might be overwritten.  */
  struct tm local, *utc;
  int offset_day;
  
  local = *local_time;  /* `*local_time' might be clobbered by gmtime() */
  utc = gmtime(&utc_time);
    
  offset_day = utc->tm_mday-local.tm_mday;
  if (offset_day < -1)
    offset_day = 1;
  else if (offset_day > 1) 
    offset_day = -1;
  return ((utc->tm_min + utc->tm_hour*60 + offset_day*24*60) -
	  (local.tm_min + local.tm_hour*60));
}

void SysClock__MakeLocalTime(SysClock__DateTime *c, RT0__Struct c__tag) {
  struct tm t;
  struct tm *lt;
  time_t tm;

  /* convert our date to the Posix format */
  t.tm_sec=c->second; t.tm_min=c->minute; t.tm_hour=c->hour;
  t.tm_mday=c->day; t.tm_mon=c->month-1; t.tm_year=c->year-1900;
  t.tm_wday=0; t.tm_yday=0; t.tm_isdst=-1;

  /* use Posix facilities to get DST */
  tm=mktime(&t);
  if ((errno == ERANGE) && (tm == (time_t)-1)) {
    /* `t' is out of the range of `time_t'; put `localTime' into `zone' to 
       signal that we don't know any better */
    c->summerTimeFlag=SysClock__unknown;
    c->zone=SysClock__localTime;
  } else {
    lt=localtime(&tm);
    c->summerTimeFlag=lt->tm_isdst;
    c->zone = calculate_zone(lt, tm);
  }
}

OOC_INT32 SysClock__GetTimeOfDay (OOC_INT32 *sec, OOC_INT32* usec) {
#if HAVE_GETTIMEOFDAY
  struct timeval tval;
  int res;
  
  res = gettimeofday(&tval, NULL);
  if (!res) {
    *sec = tval.tv_sec;
    *usec = tval.tv_usec;
    return 0;
  } else {
    *sec = 0;
    *usec = 0;
    return -1;
  }
#else
  *sec = time(NULL);
  if (*sec < 0) *sec = 0;
  *usec = 0;
  return -1;
#endif
}

void SysClock__GetClock(SysClock__DateTime *userData, RT0__Struct userData__tag) {
  time_t tsec;
  OOC_INT32 sec, usec;
  struct tm *tm;

  (void)SysClock__GetTimeOfDay(&sec, &usec);
  tsec = sec;
  
  tm = localtime(&tsec);
  userData->summerTimeFlag = tm->tm_isdst;
  userData->second = tm->tm_sec;
  userData->minute = tm->tm_min;
  userData->hour = tm->tm_hour;
  userData->day = tm->tm_mday;
  userData->month = tm->tm_mon+1;
  userData->year = tm->tm_year+1900;
  userData->fractions = usec / 1000;
  userData->zone = calculate_zone(tm, tsec);
}

void SysClock__SetClock(const SysClock__DateTime *userData) {
#if HAVE_SETTIMEOFDAY
  struct timeval tval;
  struct tm t;

  t.tm_sec=userData->second;
  t.tm_min=userData->minute;
  t.tm_hour=userData->hour;
  t.tm_mday=userData->day;
  t.tm_mon=userData->month-1;
  t.tm_year=userData->year-1900;
  t.tm_wday=0; t.tm_yday=0; t.tm_isdst=-1;

  tval.tv_sec = mktime(&t);
  tval.tv_usec = userData->fractions*1000;
  if ((tval.tv_sec != (time_t)-1) || (errno != ERANGE)) {
    (void)settimeofday(&tval, NULL);
  }
#endif
}

void OOC_SysClock_init(void) {
}
