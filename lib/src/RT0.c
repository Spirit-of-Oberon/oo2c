#include "RT0.d"

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#include "__oo2c.c"
#include "__config.h"

#if HAVE_BACKTRACE_SYMBOLS
#  include <execinfo.h>
#endif
#define MAX_BACKTRACE_LEVELS 20  /* max number of backtraced procedure calls */

#if defined(HAVE_LIBGC) && defined(HAVE_GC_GC_H)
#define USE_BOEHM_GC
#endif

#ifdef USE_BOEHM_GC
#include <gc/gc.h>
#else
#define GC_malloc malloc
#define GC_malloc_atomic malloc
#define GC_free free
#endif


static RT0__Module* modules = NULL;
static int moduleCount = 0, sizeModules = 32;


#define ROUND_SIZE(s) ((s+7) & ~((size_t)7))

#define PS(_str,_name,_form,_size) \
  _str.baseTypes = NULL; _str.tbProcs = NULL; \
  _str.module = &_mid; _str.name = (OOC_CHAR8*)_name; \
  _str.size = _size; _str.len = -1; _str.form = _form;
  

static void write_backtrace () {
#if HAVE_BACKTRACE_SYMBOLS
#define BACKTRACE_OFFSET 1
  void* farray[MAX_BACKTRACE_LEVELS+BACKTRACE_OFFSET];
  int i, size;
  char** names;
  
  size = backtrace(farray, MAX_BACKTRACE_LEVELS+BACKTRACE_OFFSET);
  names = backtrace_symbols(farray, size);
  for (i=0; i<size; i++) {
    (void)fprintf(stderr, "%d: %s\n", i, names[i]);
  }
#endif
}

#define PREFIX "## "
#define EXIT_CODE 127
void NORETURN _runtime_error(const char* msg, RT0__Module mid, OOC_INT32 pos) {
  (void)fprintf(stderr, "\n" PREFIX "\n" PREFIX
		"Runtime error in module %s at pos " OOC_INT32_FORMAT
		"\n" PREFIX "%s\n" PREFIX "\n",
		mid->name, pos, msg);
  write_backtrace();
  exit(EXIT_CODE);
}

static NORETURN void _out_of_memory(int size) {
  (void)fprintf(stderr, "\n" PREFIX "\n" PREFIX
		"Out of memory, failed to allocate %i bytes\n" PREFIX "\n",
		size);
  write_backtrace();
  exit(EXIT_CODE);
}

static NORETURN void _negative_length(OOC_LEN len) {
  (void)fprintf(stderr, "\n" PREFIX "\n" PREFIX
		"NewObject: Negative array length %i\n" PREFIX "\n",
		len);
  write_backtrace();
  exit(EXIT_CODE);
}


OOC_PTR RT0__NewObject(RT0__Struct td, ...) {
  void *var, *ptr;

  if (td->form == RT0__strRecord) { /* record */
    int prefix;
    int size = td->size;
    if (size == 0) size++;
    prefix = ROUND_SIZE(sizeof(RT0__Struct));
    
    ptr = GC_malloc(prefix+size);
    if (ptr == NULL) {
      _out_of_memory(prefix+size);
    }
    var = (char*)ptr+prefix;
    OOC_TYPE_TAG(var) = td;
    
  } else if (td->form == RT0__strArray) { /* fixed size array */
    int size = td->size;
    if (size == 0) size++;
    var = GC_malloc(size);
    if (var == NULL) {
      _out_of_memory(size);
    }
    
  } else {			/* dynamic array */
    va_list ap;
    int i;
    size_t size, prefix;
    void* ptr;
    OOC_LEN *dim;
    
    /* calculate size of the block in bytes */
    size = td->size;
    va_start(ap, td);
    for (i=0; i != td->len; i++) {
      OOC_LEN len = va_arg(ap, OOC_LEN);
      if (len < 0) {
	_negative_length(len);
      }
      size *= len;
    }
    va_end(ap);
    if (size == 0) size++;
    
    /* calculate length of type tag prefix; round to maximum required alignment
       of any basic type */
    prefix = ROUND_SIZE(td->len*sizeof(OOC_LEN));
    
    ptr = GC_malloc(prefix+size);
    if (ptr == NULL) {
      _out_of_memory(prefix+size);
    }
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

RT0__Struct RT0__TypeOf(OOC_PTR ptr) {
  return OOC_TYPE_TAG(ptr);
}

OOC_PTR RT0__NewBlock(OOC_INT32 bytes) {
  void *ptr;
  
  ptr = GC_malloc_atomic(bytes);
  if (ptr == NULL) {
    _out_of_memory(bytes);
  }
  return (OOC_PTR)ptr;
}

void RT0__FreeBlock(OOC_PTR ptr) {
  GC_free(ptr);			/* inverse to RT0__NewBlock */
}

void RT0__CollectGarbage() {
#ifdef USE_BOEHM_GC
  GC_gcollect();
#endif
}


void RT0__ErrorIndexOutOfRange (RT0__Module mid, OOC_CHARPOS pos,
				OOC_LEN index, OOC_LEN length) {
  char s[128];
  (void)sprintf(s, "Array index out of range, " OOC_LEN_FORMAT
		" not in 0 <= x < " OOC_LEN_FORMAT, index, length);
  _runtime_error(s, mid, pos);
}

void RT0__ErrorDerefOfNil (RT0__Module mid, OOC_CHARPOS pos) {
  _runtime_error("Dereference of NIL", mid, pos);
}

void RT0__ErrorFailedTypeGuard (RT0__Module mid, OOC_CHARPOS pos,
				RT0__Struct typeTag) {
  char s[1024];
  
  (void)sprintf(s, "Type guard failed, actual type is %s.%s",
		(const char*)typeTag->module->name,
		(const char*)typeTag->name);
  _runtime_error(s, mid, pos);
}

void RT0__ErrorFailedCase (RT0__Module mid, OOC_CHARPOS pos, OOC_INT32 select) {
  char s[128];
  (void)sprintf(s, "CASE error, `" OOC_INT32_FORMAT
		"' does not match any label", select);
  _runtime_error(s, mid, pos);
}

void RT0__ErrorFailedWith (RT0__Module mid, OOC_CHARPOS pos,
			   RT0__Struct typeTag) {
  char s[1024];
  
  (void)sprintf(s, "No WITH guard matches, last type is %s.%s",
		(const char*)typeTag->module->name,
		(const char*)typeTag->name);
  _runtime_error(s, mid, pos);
}

void RT0__ErrorFailedTypeAssert (RT0__Module mid, OOC_CHARPOS pos) {
  _runtime_error("Dynamic type differs from static type", mid, pos);
}

void RT0__ErrorFailedFunction (RT0__Module mid, OOC_CHARPOS pos) {
  _runtime_error("Control reaches end of function procedure", mid, pos);
}

void RT0__ErrorAssertionFailed (RT0__Module mid, OOC_CHARPOS pos,
				OOC_INT32 code) {
  char s[128];
  (void)sprintf(s, "Assertion failed, code " OOC_INT32_FORMAT, code);
  _runtime_error(s, mid, pos);
}

void RT0__Halt (OOC_INT32 code) {
  exit(code);
}



void RT0__RegisterModule(RT0__Module mid) {
  if (moduleCount == sizeModules) {
    RT0__Module* newModules;
    int i;
    
    sizeModules = sizeModules*2;
    newModules = RT0__NewBlock(sizeModules*sizeof(RT0__Module));
    for (i=0; i != moduleCount; i++) {
      newModules[i] = modules[i];
    }
    RT0__FreeBlock(modules);
    modules = newModules;
  }
  
  modules[moduleCount] = mid;
  moduleCount++;
}

RT0__Module RT0__ThisModule(const OOC_CHAR8 name__ref[], OOC_LEN name_0d) {
  int i=0;
  while ((i != moduleCount) && strcmp(name__ref, modules[i]->name)) {
    i++;
  }
  if (i == moduleCount) {
    return NULL;
  } else {
    return modules[i];
  }
}

RT0__Struct RT0__ThisType(RT0__Module mid, const OOC_CHAR8 name__ref[], OOC_LEN name_0d) {
  RT0__Struct* td;
  
  td = mid->typeDescriptors;
  while (*td && strcmp(name__ref, (*td)->name)) {
    td++;
  }
  return *td;
}



OOC_BOOLEAN RT0__GetEnv(const OOC_CHAR8 name[], OOC_LEN name_0d, OOC_CHAR8 value[], OOC_LEN value_0d) {
  char *ptr = getenv((const char*)name);
  if (ptr) {
    _copy_8(ptr,value,value_0d);
    return 1;
  } else {
    return 0;
  }
}



void OOC_RT0_init() {
#ifdef USE_BOEHM_GC
  GC_all_interior_pointers = 0;
  GC_INIT();
  /* tell GC to accept pointers with an offset of 8/16/24 as references to
     a given object; this is necessary if the GC is runnung with the
     ALL_INTERIOR_POINTERS option; the offsets cover records and open 
     arrays with upto 5 free dimensions on 32 bit architectures */
  GC_register_displacement(8);
  GC_register_displacement(16);
  GC_register_displacement(24);
#endif
  
  modules = RT0__NewBlock(sizeModules*sizeof(RT0__Module));
  
  PS(RT0__boolean , "BOOLEAN",  RT0__strBoolean , sizeof(OOC_BOOLEAN));
  PS(RT0__char    , "CHAR",     RT0__strChar    , sizeof(OOC_CHAR8));
  PS(RT0__longchar, "LONGCHAR", RT0__strLongchar, sizeof(OOC_CHAR16));
  PS(RT0__shortint, "SHORTINT", RT0__strShortint, sizeof(OOC_INT8));
  PS(RT0__integer , "INTEGER",  RT0__strInteger , sizeof(OOC_INT16));
  PS(RT0__longint , "LONGINT",  RT0__strLongint , sizeof(OOC_INT32));
  PS(RT0__real ,    "REAL",     RT0__strReal ,    sizeof(OOC_REAL32));
  PS(RT0__longreal, "LONGREAL", RT0__strLongreal, sizeof(OOC_REAL64));
  PS(RT0__set32   , "SET",      RT0__strSet32   , sizeof(OOC_UINT32));
  PS(RT0__byte    , "BYTE",     RT0__strByte    , sizeof(OOC_BYTE));
  PS(RT0__ptr     , "PTR",      RT0__strPtr     , sizeof(OOC_PTR));
}
