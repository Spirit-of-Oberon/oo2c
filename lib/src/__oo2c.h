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



#define _check_index(index,length,utype,pos)              \
  ({ if ((utype)index >= (OOC_ULEN)length) {              \
       RT0__ErrorIndexOutOfRange(&_mid,pos,index,length); \
     }                                                    \
     index; })
#define _check_pointer(adr,pos)         \
  ({ if ((void*)adr == NULL) {          \
       RT0__ErrorDerefOfNil(&_mid,pos); \
     }                                  \
     adr; })
#define _failed_case(select,pos) RT0__ErrorFailedCase(&_mid,pos,select)
#define _failed_with(pos) RT0__ErrorFailedWith(&_mid,pos)
#define _failed_function(pos) RT0__ErrorFailedFunction(&_mid,pos)


/* ASSERT(p) and ASSERT(p,code) */
#define _assert(p,code,pos) \
  if (!(p)) { RT0__ErrorAssertionFailed(&_mid,pos,code); }

/* COPY(s,d) */
#define _copy_8(_src,_dest,_max_len) {          \
  char* _d=(char*)_dest;                        \
  const char* _s=(const char*)_src;             \
  char* _max=_d+_max_len-1;                     \
  while ((_d != _max) && (*(_d++) = *(_s++)));  \
  if (_d == _max) *_d = '\000';                 \
}
#define _copy_16(_src,_dest,_max_len) {         \
  OOC_CHAR16* _d=(OOC_CHAR16*)_dest;            \
  const OOC_CHAR16* _s=(const OOC_CHAR16*)_src; \
  OOC_CHAR16* _max=_d+_max_len-1;               \
  while ((_d != _max) && (*(_d++) = *(_s++)));  \
  if (_d == _max) *_d = '\000';                 \
}
#define _copy_8to16(_src,_dest,_max_len) {      \
  OOC_CHAR16* _d=(OOC_CHAR16*)_dest;            \
  const OOC_CHAR8* _s=(const OOC_CHAR8*)_src;   \
  OOC_CHAR16* _max=_d+_max_len-1;               \
  while ((_d != _max) && (*(_d++) = *(_s++)));  \
  if (_d == _max) *_d = '\000';                 \
}

/* copy record or array value */
#define _copy_block(_src,_dest,_len) {          \
  char* _d=(char*)_dest;                        \
  const char* _s=(const char*)_src;             \
  char* _max=_d+_len;                           \
  while (_d != _max) { *(_d++) = *(_s++); }     \
}

/* string compare */
extern OOC_INT32 _cmp8(const OOC_CHAR8* l, const OOC_CHAR8* r);
extern OOC_INT32 _cmp16(const OOC_CHAR8* l, const OOC_CHAR8* r);

/* range of set values */
#define _bit_range(_from,_to) (_from > _to) ? (OOC_UINT32)0 : \
  (((OOC_UINT32)1 << _to)*2-1) & ~(((OOC_UINT32)1 << _from)-1)

/* ABS(numeric) */
#define _abs(_x) (_x<0?-_x:_x)

/* ASH(x,n) */
#define _ashl(_x,_n) (_x << _n)
#define _ashr(_x,_n) (_x >> _n) | ((_x >= 0) ? 0 : ~(~(OOC_INT32)0 >> _n))
#define _ash(_x,_n) (_n >= 0) ? _ashl(_x,_n) : _ashr(_x,- _n)

/* SYSTEM.LSH(x,n) */
#define _lshl(_x,_n,_type) ((_type) _x << _n)
#define _lshr(_x,_n,_type) ((_type) _x >> _n)
#define _lsh(_type,_x,_n) ((_n >= 0) ? _lshl(_x,_n,_type) : _lshr(_x,- _n,_type))

/* CAP(CHAR) and CAP(LONGCHAR) */
#define _cap(_c) ((96<_c && _c<123) || (224<=_c && _c<255 && _c!=247)) ? (_c-32) : _c
#define _capl(_c) _cap(_c)

/* ENTIER(real) */
#define _entier(_r) ((OOC_INT32)floor(_r))

/* ODD(integer) */
#define _odd(_i) ((_i) & 1)

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

/* SYSTEM.VAL */
#define _type_cast(_destType, _sourceType, _x) \
  ({ _sourceType y = (_sourceType)_x; *(_destType*)&y; })



/* run-time meta data: type tags, dynamic array length, type test */
#define OOC_ARRAY_LENGTH(_adr,_dim) (((OOC_LEN*)(_adr))[-(_dim)-1])

#define OOC_TYPE_DESCR(_module,_type_name) &_td_##_module##__##_type_name

#define OOC_TYPE_TAG(_adr) (((RT0__Struct*)(_adr))[-1])

#define OOC_TYPE_TEST(_tag,_td) \
  ((((RT0__Struct)(_tag))->len >= (_td)->len) && \
   (((RT0__Struct)(_tag))->baseTypes[(_td)->len] == (_td)))

#define OOC_TBPROC_ADR(_tag,_name) (((RT0__Struct)(_tag))->tbProcs[_TBN_##_name])

#define OOC_TBCALL(_adr,_name) ((_TBP_##_name)(_adr))


#define STATIC_TBCALL(_module,_type_name,_tb_proc_name,_receiver,_param_list) \
  _module##__##_type_name##_##_tb_proc_name _param_list
#define DYN_TBCALL(_module,_type_name,_tb_proc_name,_receiver,_param_list) \
  ((_TBP_##_module##__##_type_name##_##_tb_proc_name)((*((RT0__Struct*)(_receiver)-1))->tbProcs[_TBN_##_module##__##_type_name##_##_tb_proc_name]))_param_list


#endif /* __oo2c__ */
