#include "RT0.d"

#include "__oo2c.c"
#include <stdarg.h>
#include <stdlib.h>


#define ROUND_SIZE(s) ((s+7) & ~((size_t)7))
OOC_PTR RT0__NewArray(RT0__Struct td, ...) {
  void* var;
  
  if (td->form == RT0__strArray) { /* fixed size array */
    int size = td->size;
    if (size == 0) size++;
    var = malloc(size);
  } else {			/* dynamic array */
    va_list ap;
    int i;
    size_t size, prefix;
    void* ptr;
    OOC_LEN *dim;
    
    /* calculate size of the block in bytes */
    size = td->base->size;
    va_start(ap, td);
    for (i=0; i != td->len; i++) {
      size *= va_arg(ap, OOC_LEN);
    }
    va_end(ap);
    if (size == 0) size++;
    
    /* calculate length of type tag prefix; round to maximum required alignment
       of any basic type */
    prefix = ROUND_SIZE(td->len*sizeof(OOC_LEN));
    
    ptr = malloc(prefix+size);
    /* FIXME... check that result is not NULL */
    var = (char*)ptr+prefix;
    
    /* set length of dimensions */
    dim = (OOC_LEN*)var;
    va_start(ap, td);
    for (i=0; i != td->len; i++) {
      *(--dim) = va_arg(ap, OOC_LEN);
    }
    va_end(ap);
  }
  
  return (OOC_PTR)var;
}

#define PS(_str,_form,_size) \
  _str.base = NULL; _str.size = _size; _str.len = -1; _str.form = _form

void RT0_init() {
  PS(RT0__boolean , RT0__strBoolean , sizeof(OOC_BOOLEAN));
  PS(RT0__char    , RT0__strChar    , sizeof(OOC_CHAR8));
  PS(RT0__shortint, RT0__strShortint, sizeof(OOC_INT8));
  PS(RT0__integer , RT0__strInteger , sizeof(OOC_INT16));
  PS(RT0__longint , RT0__strLongint , sizeof(OOC_INT32));
}
