#include <__oo2c.h>
#include <__config.h>
#include <OS/Files.d>

#ifdef HAVE_READDIR_R
#define _POSIX_PTHREAD_SEMANTICS  /* for Solaris 5.x */
#endif

#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <limits.h>

#ifndef NAME_MAX
#define NAME_MAX PATH_MAX
#endif

#define BUFFER_SIZE 1024


static void extend_result(OS_Files__NameArray *result, int *result_len,
			  Object__String buffer[], int buffer_len) {
  int len=*result_len+buffer_len;
  char* ptr;
  int i;
  OS_Files__NameArray newResult;
  
  newResult = RT0__NewObject(OOC_PTRBASE_DESCR(OS_Files,NameArray), len);
  if (*result != NULL) {
    for(i = 0; i != *result_len; i++) {
      newResult[i] = *result[i];
    }
  }
  for(i = 0; i != buffer_len; i++) {
    newResult[i + *result_len] = buffer[i];
  }
  
  *result = newResult;
  *result_len += buffer_len;
}

#define DIRENT_BUFFER 1024
OS_Files__NameArray OS_Files__ListDir(Object__String path) {
  DIR* dir;
  char* fname = OS_Path__Encode(path);
  
  dir = opendir(fname);
  if (dir != NULL) {
    Object__String buffer[DIRENT_BUFFER];
    OS_Files__NameArray result = NULL;
    int result_len = 0;
    struct dirent *de;
    int len;
    char* ptr;
    int i = 0;
    
#if HAVE_READDIR_R
    union {
      struct dirent d;
      char b[offsetof (struct dirent, d_name) + NAME_MAX + 1];
    } u;
    
    while (readdir_r(dir, &u.d, &de) == 0) {
#else
    while (1) {
      de = readdir(dir);
#endif
      if (de == NULL) {  /* read all entries */
	break;
      } else if ((de->d_name[0] == '.') && 
	  ((de->d_name[1] == '\000') ||
	   ((de->d_name[1] == '.') && (de->d_name[2] == '\000')))) {
	/* omit "." and ".." */
      } else {
	if (i == DIRENT_BUFFER) {
	  extend_result(&result, &result_len, buffer, i);
	  i = 0;
	}
	buffer[i] = OS_Path__Decode(de->d_name, strlen(de->d_name)+1);
	i++;
      }
    }
    closedir(dir);

    extend_result(&result, &result_len, buffer, i);
    return result;
  } else {
    IO_StdChannels__IOError(path);
  }
}

void OS_Files__MkDir(Object__String path, OS_Files__Mode mode) {
  int rc;
  char* fname = OS_Path__Encode(path);

#ifdef __MINGW32__
  rc = mkdir(fname);
#else
  rc = mkdir(fname, mode);
#endif
  if (rc) {
    IO_StdChannels__IOError(path);
  }
}

void OS_Files__MakeDirs(Object__String path, OS_Files__Mode mode) {
  int rc;
  struct stat sbuf;
  char* fname = OS_Path__Encode(path);
  
  if (fname[0] == '\000') {	/* empty path --> no operation */
    return;
  }
  
  rc = stat(fname, &sbuf);
  if (rc) {			/* stat failure: file does not exist */
    OOC_CHAR8 ppath[BUFFER_SIZE];
    int i;
    int last = 0;
    
    for (i = 0; (i < BUFFER_SIZE) && (fname[i] != '\000'); i++) {
      ppath[i] = fname[i];
      if ((fname[i] == '/') && (i > 0) && (fname[i-1] != '/')) {
	last = i;
      }
    }
    ppath[last] = '\000';
    OS_Files__MakeDirs(OS_Path__Decode(ppath, BUFFER_SIZE), mode);
    OS_Files__MkDir(OS_Path__Decode(fname, OOC_ARRAY_LENGTH(fname,0)), mode);
    
  } else if (!S_ISDIR(sbuf.st_mode)) {
    /* path is not directory: let mkdir get the error message */
    OS_Files__MkDir(OS_Path__Decode(fname, OOC_ARRAY_LENGTH(fname,0)), mode);
  }
}

void OS_Files__Remove(Object__String path) {
  int rc;
  char* fname = OS_Path__Encode(path);

  rc = unlink(fname);
  if (rc) {
    IO_StdChannels__IOError(path);
  }
}

OOC_BOOLEAN OS_Files__Exists(Object__String path) {
  struct stat buf;
  
  return (stat(OS_Path__Encode(path), &buf) == 0);
}

OS_Files__Time OS_Files__MTime(Object__String path) {
  struct stat buf;
  int rc;
  
  rc = stat(OS_Path__Encode(path), &buf);
  if (rc) {
    IO_StdChannels__IOError(path);
  } else {
#if HAVE_STRUCT_STAT_USEC
    return (OS_Files__Time)buf.st_mtime + buf.st_mtime_usec/1.0E6;
#else
    return (OS_Files__Time)buf.st_mtime;
#endif
  }
}

void OOC_OS_Files_init(void) {
}
