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
#ifndef __oo2c__
#define __oo2c__

#include "__config.h"
#include "__typemap.h"
#include "__libc.h"
#include "__dynvar.h"

/* Define attributes that mark functions that won't return.  These attributes
   are only used in __oo2c.h and __oo2c.c: */
#undef NORETURN
#undef NORETURN2
#if defined(__GNUC__) && (__GNUC__>2 || (__GNUC__==2 && __GNUC_MINOR__>=6))
#define NORETURN
#define NORETURN2 __attribute__ ((__noreturn__))
#else
#define NORETURN
#define NORETURN2
#endif


/* ASSERT(p) and ASSERT(p,code) */
extern void NORETURN _assertion_failed(OOC_INT32 code, OOC_CHARPOS pos) NORETURN2;
#define _assert(p,code,pos) \
  if (!(p)) { _assertion_failed(code, pos); }

#endif /* __oo2c__ */
