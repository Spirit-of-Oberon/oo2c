#include "RT0.d"

#include "__oo2c.c"
#include <stdarg.h>
#include <stdlib.h>

#define ROUND_SIZE(s) ((s+7) & ~((size_t)7))

#define PS(_str,_form,_size) \
  _str.baseTypes = NULL; _str.tbProcs = NULL; \
  _str.size = _size; _str.len = -1; _str.form = _form


OOC_PTR RT0__NewObject(RT0__Struct td, ...) {
  void *var, *ptr;

  if (td->form == RT0__strRecord) { /* record */
    int prefix;
    int size = td->size;
    if (size == 0) size++;
    prefix = ROUND_SIZE(sizeof(RT0__Struct));
    
    ptr = malloc(prefix+size);
    /* FIXME... check that result is not NULL */
    var = (char*)ptr+prefix;
    OOC_TYPE_TAG(var) = td;
    
  } else if (td->form == RT0__strArray) { /* fixed size array */
    int size = td->size;
    if (size == 0) size++;
    var = malloc(size);
    /* FIXME... check that result is not NULL */
    
  } else {			/* dynamic array */
    va_list ap;
    int i;
    size_t size, prefix;
    void* ptr;
    OOC_LEN *dim;
    
    /* calculate size of the block in bytes */
    size = td->baseTypes[0]->size;
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

OOC_PTR RT0__NewBlock(OOC_INT32 bytes) {
  void *ptr;
  
  ptr = malloc(bytes);		/* GC_malloc_atomic */
  /* FIXME... check that result is not NULL */
  return (OOC_PTR)ptr;
}

void RT0__InitVParStack(OOC_INT32 bytes) {
  _ooc_top_vs = (void*)malloc(bytes); /* not GC_malloc_atomic!!! */
  _ooc_end_vs = (char*)_ooc_top_vs+(bytes);
}

void RT0_init() {
  PS(RT0__boolean , RT0__strBoolean , sizeof(OOC_BOOLEAN));
  PS(RT0__char    , RT0__strChar    , sizeof(OOC_CHAR8));
  PS(RT0__longchar, RT0__strLongchar, sizeof(OOC_CHAR16));
  PS(RT0__shortint, RT0__strShortint, sizeof(OOC_INT8));
  PS(RT0__integer , RT0__strInteger , sizeof(OOC_INT16));
  PS(RT0__longint , RT0__strLongint , sizeof(OOC_INT32));
  PS(RT0__byte    , RT0__strByte    , sizeof(OOC_BYTE));
  PS(RT0__ptr     , RT0__strPtr     , sizeof(OOC_PTR));
}
