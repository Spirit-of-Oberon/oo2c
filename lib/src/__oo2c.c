/*      $Id$        */
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

#include "__oo2c.h"
#include <stdio.h>

/* --- stack for copies of array value parameters (see __dynvar.h): */
void* _ooc_top_vs;
void* _ooc_end_vs;

/* --- string compare */
OOC_INT32 _cmp8(const OOC_CHAR8* l, const OOC_CHAR8* r) {
  while ((*l == *r) && *l) { l++; r++; }
  return ((OOC_INT32)*l-(OOC_INT32)*r);
}

OOC_INT32 _cmp16(const OOC_CHAR8* l, const OOC_CHAR8* r) {
  while ((*l == *r) && *l) { l++; r++; }
  return ((OOC_INT32)*l-(OOC_INT32)*r);
}
