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

/* COPY(s,d) */
#define _copy(_src,_dest,_max_len) {            \
  char* _d=(char*)_dest;                        \
  const char* _s=(const char*)_src;             \
  char* _max=_d+_max_len-1;                     \
  while ((_d != _max) && (*(_d++) = *(_s++)));  \
  if (_d == _max) *_d = '\000';                 \
}



/* CAP(CHAR) and CAP(LONGCHAR) */
#define _cap(_c) ((96<_c && _c<123) || (224<=_c && _c<255 && _c!=247)) ? (_c-32) : _c
#define _capl(_c) _cap(_c)

/* DIV(integer, integer) -- note: macro uses gcc style expression statement */
/* def: sign(_x MOD _y)==sign(_y) */
/*#define _div(_x,_y) ({                               \
  typeof(_x) _quot = _x / _y, _rem = _x % _y;        \
  if (_rem && ((_rem > 0) != (_y > 0))) _quot--;     \
  _quot; })*/
/* def: _x MOD _y >= 0 for _y>0, and undefined otherwise */
#define _div(_x,_y) ({                               \
  typeof(_x) _quot = _x / _y;                        \
  if ((_x<0) && (_y>0) && (_quot*_y!=_x)) _quot--;   \
  _quot; })

/* MOD(integer, integer) -- note: macro uses gcc style expression statement */
/* def: sign(_x MOD _y)==sign(_y) */
/*#define _mod(_x,_y) ({                               \
  typeof(_x) _rem = _x % _y;                         \
  if (_rem && ((_rem > 0) != (_y > 0))) _rem += _y;  \
  _rem; })*/
/* def: _x MOD _y >= 0 for _y>0, and undefined otherwise */
#define _mod(_x,_y) ({                               \
  typeof(_x) _rem = _x % _y;                         \
  if ((_x<0) && (_y>0) && (_rem != 0)) _rem += _y;   \
  _rem; })


/* i IN s */
#define _in(_i,_s) (((_s)>>(_i))&1)

/* run-time meta data: type tags, dynamic array length, type test */
#define OOC_ARRAY_LENGTH(_adr,_dim) (((OOC_LEN*)(_adr))[-(_dim)-1])

#define OOC_TYPE_TAG(_adr) (((RT0__Struct*)(_adr))[-1])

#define OOC_TYPE_TEST(_tag,_td) \
  ((((RT0__Struct)(_tag))->len >= (_td)->len) && \
   (((RT0__Struct)(_tag))->baseTypes[(_td)->len] == (_td)))

#define OOC_TBPROC_ADR(_tag,_name) (((RT0__Struct)(_tag))->tbProcs[_TBN_##_name])

#define OOC_TBCALL(_adr,_name) ((_TBP_##_name)(_adr))

#endif /* __oo2c__ */
