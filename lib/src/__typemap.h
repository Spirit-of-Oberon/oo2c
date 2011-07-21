/*      $Id: __typemap.h,v 1.9 2003/01/01 14:02:22 mva Exp $    */
/*  Mapping of basic types to C types.
    Copyright (C) 1997-2003  Michael van Acken

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
#ifndef __typemap__
#define __typemap__

#include "__config.h"

/* these types should be used when writing a C function whose header has to
   correspond to an Oberon-2 declaration */
typedef unsigned char OOC_BOOLEAN;
typedef unsigned char OOC_CHAR8;
typedef unsigned short int OOC_CHAR16;
typedef unsigned int OOC_CHAR32;
typedef signed char OOC_INT8;
typedef signed short int OOC_INT16;
typedef signed int OOC_INT32;
typedef OOC_INT64_T OOC_INT64;
typedef float OOC_REAL32;
typedef double OOC_REAL64;
typedef unsigned char OOC_UINT8;
typedef unsigned short int OOC_UINT16;
typedef unsigned int OOC_UINT32;
typedef unsigned OOC_INT64_T OOC_UINT64;
typedef unsigned char OOC_BYTE;
typedef void *OOC_PTR;

/* type used to store length of array types: */
typedef OOC_INT32 OOC_LEN;
typedef OOC_UINT32 OOC_ULEN;

/* type of character position in files: */
typedef OOC_INT32 OOC_CHARPOS;

/* standard constants: */
#ifndef NULL
#define NULL (void*)0
#endif
#define OOC_FALSE 0
#define OOC_TRUE 1

/* format string used by printf for OOC_INT32 (%i if it is equal to int,
   %li if it is long int), and OOC_LEN */
#define OOC_INT32_FORMAT "%i"
#define OOC_LEN_FORMAT "%i"



#undef NORETURN
#undef NORETURN2
#if __GNUC__>2 || (__GNUC__==2 && __GNUC_MINOR__>=6)
#define NORETURN
#define NORETURN2 __attribute__ ((__noreturn__))
#else
#define NORETURN
#define NORETURN2
#endif


#endif  /* __typemap__ */
