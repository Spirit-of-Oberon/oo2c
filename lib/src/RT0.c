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
    var = ptr+prefix;
    
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

#define PS(form,size) (RT0__StructDesc){NULL, size, -1, form}
void RT0_init() {
  RT0__boolean  = PS(RT0__strBoolean , sizeof(OOC_BOOLEAN));
  RT0__char     = PS(RT0__strChar    , sizeof(OOC_CHAR8));
  RT0__shortint = PS(RT0__strShortint, sizeof(OOC_INT8));
  RT0__integer  = PS(RT0__strInteger , sizeof(OOC_INT16));
  RT0__longint  = PS(RT0__strLongint , sizeof(OOC_INT32));
}
