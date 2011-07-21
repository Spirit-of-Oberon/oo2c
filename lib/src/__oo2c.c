/*      $Id: __oo2c.c,v 1.16 2003/06/28 10:39:26 mva Exp $        */
/*  Run-time system for C back-ends of OOC2
    Copyright (C) 2001, 2002  Michael van Acken

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
*/

/* This file is #included into RT0.c, and therefore compiled into RT0.o */

#include <__oo2c.h>

/* --- string compare */
#ifndef HAVE_BUILTIN_STRCMP
OOC_INT32 _cmp8(const OOC_CHAR8* l, const OOC_CHAR8* r) {
  while ((*l == *r) && *l) { l++; r++; }
  return ((OOC_INT32)*l-(OOC_INT32)*r);
}
#endif

OOC_INT32 _cmp16(const OOC_CHAR16* l, const OOC_CHAR16* r) {
  while ((*l == *r) && *l) { l++; r++; }
  return ((OOC_INT32)*l-(OOC_INT32)*r);
}

OOC_INT32 _cmp32(const OOC_CHAR32* l, const OOC_CHAR32* r) {
  while ((*l == *r) && *l) { l++; r++; }
  return ((OOC_INT32)*l-(OOC_INT32)*r);
}

/* --- string copy */
void _copy_8(const OOC_CHAR8* src, OOC_CHAR8* dest, OOC_LEN max_len) {
  OOC_CHAR8* max=dest+max_len-1;
  while ((dest != max) && (*(dest++) = *(src++)));
  if (dest == max) *dest = '\000';
}

void _copy_8to16(const OOC_CHAR8* src, OOC_CHAR16* dest, OOC_LEN max_len) {
  OOC_CHAR16* max=dest+max_len-1;
  while ((dest != max) && (*(dest++) = *(src++)));
  if (dest == max) *dest = '\000';
}

void _copy_8to32(const OOC_CHAR8* src, OOC_CHAR32* dest, OOC_LEN max_len) {
  OOC_CHAR32* max=dest+max_len-1;
  while ((dest != max) && (*(dest++) = *(src++)));
  if (dest == max) *dest = '\000';
}

void _copy_16(const OOC_CHAR16* src, OOC_CHAR16* dest, OOC_LEN max_len) {
  OOC_CHAR16* max=dest+max_len-1;
  while ((dest != max) && (*(dest++) = *(src++)));
  if (dest == max) *dest = '\000';
}

void _copy_16to32(const OOC_CHAR16* src, OOC_CHAR32* dest, OOC_LEN max_len) {
  OOC_CHAR32* max=dest+max_len-1;
  while ((dest != max) && (*(dest++) = *(src++)));
  if (dest == max) *dest = '\000';
}

void _copy_32(const OOC_CHAR32* src, OOC_CHAR32* dest, OOC_LEN max_len) {
  OOC_CHAR32* max=dest+max_len-1;
  while ((dest != max) && (*(dest++) = *(src++)));
  if (dest == max) *dest = '\000';
}

#ifndef HAVE_LRINT
OOC_INT32 ooc_round_real32(OOC_REAL32 x) {
  if (x >= 0.0f) {
    return (OOC_INT32)(x+0.5f);
  } else {
    return (OOC_INT32)(x-0.5f);
  }
}
OOC_INT32 ooc_round_real64(OOC_REAL64 x) {
  if (x >= 0.0) {
    return (OOC_INT32)(x+0.5);
  } else {
    return (OOC_INT32)(x-0.5);
  }
}
#endif
