/*      $Id: __dynvar.h,v 1.7 2002/12/06 01:49:28 mva Exp $        */
/*  Handling of dynamic variables and value parameters.
    Copyright (C) 2002  Michael van Acken

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
#ifndef __dynvar__
#define __dynvar__

#include "__typemap.h"

/* Note: all libc functions used here must be prototyped in __libc.h */

#define OOC_ALLOCATE_VPAR(_dest,_basetype,_len) _basetype _dest[_len];

#define OOC_INITIALIZE_VPAR(_source,_dest,_basetype,_size) \
  memcpy((_dest),(_source),(_size));

#endif  /* __dynvar__ */
