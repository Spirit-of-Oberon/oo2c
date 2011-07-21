/*	$Id: HashCode.c,v 1.3 2004/12/15 11:27:03 mva Exp $	*/
/*  Hash functions for basic types.
    Copyright (C) 2003  Michael van Acken

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

#include "HashCode.d"

#define SIZE_OF_HASH(x) (sizeof(x) == sizeof(HashCode__Hash))
#define AS_HASH(x) ((HashCode__Hash)(x))
#define COMBINE(x,y) ((x)^(y))

HashCode__Hash HashCode__Boolean(OOC_CHAR8 x) {
  return (x != 0)+1;
}

HashCode__Hash HashCode__Real(OOC_REAL32 x) {
  union {
    OOC_REAL32 real;
    HashCode__Hash hash;
  } p;
  
  p.real = x;
  return p.hash;
}

HashCode__Hash HashCode__LongReal(OOC_REAL64 x) {
  union {
    OOC_REAL64 real;
    HashCode__Hash hash[2];
  } p;
  
  p.real = x;
  return COMBINE(p.hash[0], p.hash[1]);
}

HashCode__Hash HashCode__Set(OOC_UINT32 x) {
  return AS_HASH(x);
}

HashCode__Hash HashCode__Ptr(void* x) {
  if (SIZE_OF_HASH(x)) {
    return AS_HASH(x);  /* this causes a warning on 64 bit systems */
  } else {
    union {
      void* ptr;
      HashCode__Hash hash[2];
    } p;
    
    p.ptr = x;
    return COMBINE(p.hash[0], p.hash[1]);
  }
}

HashCode__Hash HashCode__CharRegion(const OOC_CHAR8 *data, OOC_LEN data_0d,
				    OOC_INT32 start, OOC_INT32 end) {
  /* taken from Python's dist/src/Objects/stringobject.c */
  register OOC_CHAR8 *p, *s;
  register HashCode__Hash x;
  
  s = (OOC_CHAR8 *)(data+end);
  p = (OOC_CHAR8 *)(data+start);
  if (p == s) {
    return 0;
  } else {
    x = *p << 7;
    while (p != s)
      x = (1000003*x) ^ *p++;
    return x ^ (end-start);
  }
}

HashCode__Hash HashCode__LongCharRegion(const OOC_CHAR16 *data,OOC_LEN data_0d,
					OOC_INT32 start, OOC_INT32 end) {
  /* taken from Python's dist/src/Objects/stringobject.c */
  register OOC_CHAR16 *p, *s;
  register HashCode__Hash x;
  
  s = (OOC_CHAR16 *)(data+end);
  p = (OOC_CHAR16 *)(data+start);
  if (p == s) {
    return 0;
  } else {
    x = *p << 7;
    while (p != s)
      x = (1000003*x) ^ *p++;
    return x ^ (end-start);
  }
}

HashCode__Hash HashCode__UCS4CharRegion(const OOC_CHAR32 *data,OOC_LEN data_0d,
					OOC_INT32 start, OOC_INT32 end) {
  /* taken from Python's dist/src/Objects/stringobject.c */
  register OOC_CHAR32 *p, *s;
  register HashCode__Hash x;
  
  s = (OOC_CHAR32 *)(data+end);
  p = (OOC_CHAR32 *)(data+start);
  if (p == s) {
    return 0;
  } else {
    x = *p << 7;
    while (p != s)
      x = (1000003*x) ^ *p++;
    return x ^ (end-start);
  }
}

void HashCode__Append(HashCode__Hash x, HashCode__Hash *hash) {
  *hash ^= x;
}

void OOC_HashCode_init() {
}

void OOC_HashCode_destroy(void) {
}
