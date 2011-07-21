/*      $Id: __oo2c.h,v 1.46 2003/09/12 08:06:11 sgreenhill Exp $        */
/*  Run-time system for C back-ends of OOC2
    Copyright (C) 2001-2003  Michael van Acken

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

/* Testing for __builtin_strcmp is not as easy as expected, so we
   hardcode it here.  */
#define HAVE_BUILTIN_STRCMP 1

/* Use lrint() for round() in RealMath and LRealMath if it is available, 
   otherwise use our own definitions in __oo2c.c.  The prototype for lrint()
   is in __libc.h.  */
#ifdef HAVE_LRINT
#define ooc_round_real32(_x) (OOC_INT32)lrint(_x)
#define ooc_round_real64(_x) (OOC_INT32)lrint(_x)
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
#define _type_guard(adr,tag,guard,pos)                          \
  ({ if (!OOC_TYPE_TEST(tag,guard)) {                           \
       RT0__ErrorFailedTypeGuard(&_mid,pos,(RT0__Struct)tag);   \
     }                                                          \
     adr; })
#define _type_guard_q(adr,tag,guard,pos)                        \
  ({ if (!RT0__TypeTest((RT0__Struct)tag,(RT0__Struct)guard)) { \
       RT0__ErrorFailedTypeGuard(&_mid,pos,(RT0__Struct)tag);   \
     }                                                          \
     adr; })
#define _failed_case(select,pos) RT0__ErrorFailedCase(&_mid,pos,select)
#define _failed_with(type_tag,pos) RT0__ErrorFailedWith(&_mid,pos,(RT0__Struct)type_tag)
#define _failed_type_assert(pos) RT0__ErrorFailedTypeAssert(&_mid,pos)
#define _failed_function(pos) RT0__ErrorFailedFunction(&_mid,pos)


/* ASSERT(p), ASSERT(p,code), and HALT(code) */
#define _assert(p,code,pos) \
  if (!(p)) { RT0__ErrorAssertionFailed(&_mid,pos,code); }
#define _halt(code) RT0__Halt(code);

/* COPY(s,d) */
extern void _copy_8(const OOC_CHAR8* src, OOC_CHAR8* dest, OOC_LEN max_len);
extern void _copy_8to16(const OOC_CHAR8* src, OOC_CHAR16* dest, OOC_LEN max_len);
extern void _copy_8to32(const OOC_CHAR8* src, OOC_CHAR32* dest, OOC_LEN max_len);
extern void _copy_16(const OOC_CHAR16* src, OOC_CHAR16* dest, OOC_LEN max_len);
extern void _copy_16to32(const OOC_CHAR16* src, OOC_CHAR32* dest, OOC_LEN max_len);
extern void _copy_32(const OOC_CHAR32* src, OOC_CHAR32* dest, OOC_LEN max_len);

/* copy record or array value */
#define _copy_block(_src,_dest,_len) \
  memcpy((void*)_dest,(void*)_src,_len)

/* copy memory block (SYSTEM.MOVE) */
#define _move_block(_source,_dest,_size) \
  memcpy((void*)_dest,(void*)_source,_size)

/* string compare */
#ifdef HAVE_BUILTIN_STRCMP
#define _cmp8(a,b) ((OOC_INT32)__builtin_strcmp((a),(b)))
#else
extern OOC_INT32 _cmp8(const OOC_CHAR8* l, const OOC_CHAR8* r);
#endif
extern OOC_INT32 _cmp16(const OOC_CHAR16* l, const OOC_CHAR16* r);
extern OOC_INT32 _cmp32(const OOC_CHAR32* l, const OOC_CHAR32* r);

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
#define _lshl(_x,_n,_type) ((_type)(_x << _n))
#define _lshr(_x,_n,_type) ((_type)(_x >> _n))
#define _lsh(_type,_x,_n) ((_n >= 0) ? _lshl(_x,_n,_type) : _lshr(_x,- _n,_type))

/* SYSTEM.ROT(x,n) */
#define _rot(_type,_x,_n)                                                     \
  ({ int bits = sizeof(_type)*8;                                              \
     _type res;                                                               \
     if (_n % bits >= 0) {                                                    \
       res = ((_type)_x << _n % bits) | ((_type)_x >> (bits - _n % bits));    \
     } else {                                                                 \
       res = ((_type)_x >> -(_n % bits)) | ((_type)_x << (bits + _n % bits)); \
     }                                                                        \
     res; })

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

/* set difference */
#define _logical_subtr(_a,_b) (_a & ~(_b))

/* INCL, EXCL */
#define _set_bit(_s,_i) ((_s) | (((typeof(_s))1) << (_i)))
#define _clear_bit(_s,_i) ((_s) & ~(((typeof(_s))1) << (_i)))


/* SYSTEM.VAL */
#define _type_cast(_destType, _sourceType, _x) \
  ({ union {_sourceType s; _destType d;} _v; _v.s=_x; _v.d; })
#define _type_cast_fast(_destType, _sourceType, _x) \
  (_destType)(_sourceType)_x



/* run-time meta data: type tags, dynamic array length, type test */
#define OOC_ARRAY_LENGTH(_adr,_dim) (((OOC_LEN*)(_adr))[-(_dim)-1])

#define OOC_TYPE_DESCR(_module,_type_name) &_td_##_module##__##_type_name

#define OOC_PTRBASE_DESCR(_module,_type_name) \
  (_td_##_module##__##_type_name.baseTypes[0])

#define OOC_TYPE_TAG(_adr) (((RT0__Struct*)(_adr))[-1])

#define OOC_TYPE_TEST(_tag,_td) \
  ((((RT0__Struct)(_tag))->len >= (_td)->len) && \
   (((RT0__Struct)(_tag))->baseTypes[(_td)->len] == (_td)))

#define OOC_TBPROC_ADR(_tag,_name) (((RT0__Struct)(_tag))->tbProcs[_TBN_##_name])

#define OOC_VTABLEPROC_ADR(_adr,_name) (((OOC_PTR **) _adr)[0][_TBN_##_name])

#define OOC_TBCALL(_adr,_name) ((_TBP_##_name)(_adr))

#define OOC_METHOD(_obj,_name) \
  ((_TBP_##_name)OOC_TBPROC_ADR(OOC_TYPE_TAG(_obj),_name))


#define STATIC_TBCALL(_module,_type_name,_tb_proc_name,_receiver,_param_list) \
  _module##__##_type_name##_##_tb_proc_name _param_list
#define DYN_TBCALL(_module,_type_name,_tb_proc_name,_receiver,_param_list) \
  ((_TBP_##_module##__##_type_name##_##_tb_proc_name)((*((RT0__Struct*)(_receiver)-1))->tbProcs[_TBN_##_module##__##_type_name##_##_tb_proc_name]))_param_list


#endif /* __oo2c__ */
