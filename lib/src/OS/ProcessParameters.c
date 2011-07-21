/* 	$Id: ProcessParameters.c,v 1.10 2003/08/22 09:04:34 mva Exp $	 */
#ifdef WIN32
#include <io.h>
#include <direct.h>
#else
#include <unistd.h>
#endif
#include <errno.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include <__oo2c.h>
#include <__config.h>
#include <OS/ProcessParameters.d>


#define SIZE_BUFFER 1024
Object__String OS_ProcessParameters__GetCwd() {
  char buffer[SIZE_BUFFER];
  if (getcwd(buffer, SIZE_BUFFER)) {
    return OS_Path__Decode(buffer, SIZE_BUFFER);
  } else {
    IO_StdChannels__IOError(NULL);
  }
}

Object__String OS_ProcessParameters__GetEnv(Object__String name) {
  char *ptr = getenv(OS_Path__Encode(name));
  if (ptr) {
    return OS_Path__Decode(ptr, strlen(ptr)+1);
  } else {
    return NULL;
    return 0;
  }
}


void OOC_OS_ProcessParameters_init(void) {
}
