/*      $Id$        */
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

extern void* _ooc_top_vs;  /* top of value stack; defined in __oo2c.c */
extern void* _ooc_end_vs;  /* end of value stack; defined in __oo2c.c */

/* allocate value stack; defined in __oo2c.c */
extern void OOC_INIT_VPAR_STACK(int size);

#define OOC_PUSH_VPAR_STACK void* _ooc_old_top_vs = _ooc_top_vs;
#define OOC_POP_VPAR_STACK _ooc_top_vs = _ooc_old_top_vs;

/* when allocating space on the privately managed stack _ooc_top_vs, always
   allocate multiples of OOC_ALIGN+1 */
#define OOC_ALIGN 7

#define OOC_ALLOCATE_VPAR(_dest,_basetype,_size) \
  _dest = _ooc_top_vs; \
  _ooc_top_vs += ((_size)+OOC_ALIGN) & ~OOC_ALIGN;

#define OOC_INITIALIZE_VPAR(_source,_dest,_basetype,_size) \
  memcpy((_dest),(_source),(_size));


#endif  /* __dynvar__ */
