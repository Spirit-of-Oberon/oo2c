/*	$Id: Files.c,v 1.10 2005/08/31 11:57:24 mva Exp $	*/
/*  Access to files and file attributes.
    Copyright (C) 1997-2000, 2002, 2005  Michael van Acken

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
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <limits.h>

#include <__oo2c.h>
#include <__config.h>

#if TIME_WITH_SYS_TIME
# include <sys/time.h>
# include <time.h>
#else
# if HAVE_SYS_TIME_H
#  include <sys/time.h>
# else
#  include <time.h>
# endif
#endif
#if HAVE_UNISTD_H
#include <unistd.h>
#elif HAVE_IO_H
#include <io.h>
#endif
#if HAVE_UTIME_H
#include <utime.h>
#else
#include <sys/utime.h>
#endif

#define _MODULE_libc_ /* don't pull in declaration from the `libc' module */
#include <Files.d>


/* this is the currently active umask of the process; it is used by procedure
   Register */
static mode_t active_umask;

/* if the system imposes no limit on the length of a file name, choose an 
   arbitrary large value instead */
#ifndef PATH_MAX
#define PATH_MAX 2048
#endif

#ifdef __MINGW32__
#define PERMISSIONS_REGISTER (S_IREAD | S_IWRITE)
#define PERMISSIONS_WRITE_ONLY S_IWRITE
#else
#define PERMISSIONS_REGISTER (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)
#define PERMISSIONS_WRITE_ONLY S_IWUSR
#endif
#define PERMISSIONS_READ_WRITE PERMISSIONS_REGISTER



/* this variable holds a list of open files; it is used to remove any temporary
   files on program exit */
static Files__File open_files = NULL;


/* function definitions */


void Files__ErrorContextDesc_GetTemplate (Files__ErrorContext context, 
  Msg__Msg msg, Msg__LString templ, int templ_0d) {
  char *str;
  OOC_INT32 res = msg->code;
  
  if (res == Files__channelClosed) {
    str = "File has been closed";
  } else if (res == Files__noReadAccess) {
    str = "No read permission for file";
  } else if (res == Files__noWriteAccess) {
    str = "No write permission for file";
  } else if (res == Files__closeError) {
    str = "Error while closing the file";
  } else if (res == Files__accessDenied) {
    str = "Failed to open file with requested access rights";
  } else if (res == Files__isDirectory) {
    str = "Can't get write access to directory file";
  } else if (res == Files__tooManyFiles) {
    str = "Too many open files at the moment";
  } else if (res == Files__noSuchFile) {
    str = "The named file does not exist";
  } else if (res == Files__directoryFull) {
    str = "Can't add new files to directory";
  } else if (res == Files__readOnlyFileSystem) {
    str = "File system is read-only";
  } else if (res == Files__invalidTime) {
    str = "Invalid modification time";
  } else if (res == Files__notOwner) {
    str = "Must be owner of file to change its modification time";
  } else if (res == Files__anonymousFile) {
    str = "Can't register anonymous file";
  } else if (res == Files__dirWriteDenied) {
    str = "Don't have write permission for directory";
  } else if (res == Files__fileError) {
    str = "Failed to open file";
  } else if (res == Files__nameTooLong) {
    str = "The file name or one of its components is too long";
  } else if (res == Files__notDirectory) {
    str = "A directory component of the file name exists, but isn't a directory";
  } else if (res == Files__linkLoop) {
    str = "Resolved too many symbolic links while looking up the file";
  } else {
    str = NULL;
  } 

  if (str) {
    _copy_8to16((OOC_CHAR8*)str, templ, templ_0d);
    if (msg->attribList) {
      Msg__Attribute attr;
      OOC_CHAR16 eol[2] = {(OOC_CHAR16)CharClass__eol, (OOC_CHAR16)0};
      OOC_CHAR16 str16[Msg__sizeAttrName+1];
      
      /*LongStrings__Append(eol, 2, templ, templ_0d);*/
      attr = msg->attribList;
      while (attr) {
	LongStrings__Append(eol, 2, templ, templ_0d);
	_copy_8to16((OOC_CHAR8*)attr->name, str16, strlen((char*)attr->name)+1);
	LongStrings__Append(str16, Msg__sizeAttrName+1, templ, templ_0d);
	_copy_8to16((OOC_CHAR8*)"=${", str16, Msg__sizeAttrName+1);
	LongStrings__Append(str16, Msg__sizeAttrName+1, templ, templ_0d);
	_copy_8to16((OOC_CHAR8*)attr->name, str16, Msg__sizeAttrName+1);
	LongStrings__Append(str16, Msg__sizeAttrName+1, templ, templ_0d);
	_copy_8to16((OOC_CHAR8*)"}", str16, Msg__sizeAttrName+1);
	LongStrings__Append(str16, Msg__sizeAttrName+1, templ, templ_0d);
	attr = attr->nextAttrib;
      }
    }
  } else {
    STATIC_TBCALL(PosixFileDescr,ErrorContextDesc,GetTemplate,context,
		  ((PosixFileDescr__ErrorContext)context,msg,templ,templ_0d));
  }
}

static void add_msg_attribute(Files__Result msg, const char* name, const char* value) {
  DYN_TBCALL(Msg,MsgDesc,SetStringAttrib,msg,
	     (msg, (const OOC_CHAR8*)name, strlen(name)+1,
              Msg__GetStringPtr((OOC_CHAR8*)value, strlen(value)+1)));
}

static Files__Result get_error(Msg__Code code, int use_errno, Files__File f) {
  Files__Result msg;
  
  msg = Msg__New((Msg__Context)Files__errorContext, code);
  if (use_errno) {
#if HAVE_STRERROR
    add_msg_attribute(msg, "errstr", strerror(errno));
#endif
    DYN_TBCALL(Msg,MsgDesc,SetIntAttrib,msg,
	       (msg, (const OOC_CHAR8*)"errno", 6, (OOC_INT32)errno));
  }
  if (f) {
    if (f->tmpName) {
      add_msg_attribute(msg, "file_name", (char*)f->tmpName);
    } else if (f->name) {
      add_msg_attribute(msg, "file_name", (char*)f->name);
    }
  }

  return msg;
}


static Files__Result file_error(const char *name, const char *new_name) {
  /* if new_name != NULL: rename operation */
  Msg__Code code;
  Files__Result msg;
  
  switch (errno) {
  case EACCES:
    code = Files__dirWriteDenied;
    break;
  case EISDIR:
    code = Files__isDirectory;
    break;
  case EMFILE:
  case ENFILE: 
    code = Files__tooManyFiles;
    break;
  case ENOENT:
    code = Files__noSuchFile;
    break;
  case ENOSPC:
    code = Files__directoryFull;
    break;
  case EROFS:
    code = Files__readOnlyFileSystem;
    break;
  case ENAMETOOLONG:
    code = Files__nameTooLong;
    break;
  case ENOTDIR:
    code = Files__notDirectory;
    break;
#ifdef ELOOP
  case ELOOP:
    code = Files__linkLoop;
    break;
#endif
  case EPERM:
    code = Files__notOwner;
    break;
  default:
    code = Files__fileError;
  }
  
  msg = get_error(code, 1, NULL);
  if (new_name) {
    add_msg_attribute(msg, "old_name", name);
    add_msg_attribute(msg, "new_name", new_name);
  } else if (name) {
    add_msg_attribute(msg, "file_name", name);
  }
  
  return msg;
}

static void free_tmp_name (Files__File f) {
/* pre: f->tmpName != NULL */
  RT0__FreeBlock(f->tmpName);
  f->tmpName = NULL;
  if(f->name) {
    RT0__FreeBlock(f->name);
    f->name = NULL;
  }
}

static int open_file(const OOC_CHAR8* name, int open_flags, int pflags) {
  int fd;

#ifdef O_BINARY  /* be kind to MS-DOG based systems */
  open_flags |= O_BINARY;
#endif

  do {
    fd = open((const char*)name, open_flags, pflags);
  } while ((fd == -1) && (errno == EINTR));
  return fd;
}
  
void Files__FileDesc_Register(Files__File f) {
  if (!f->open) {
    f->res = get_error(Files__channelClosed, 0, f);
  } else if (f->anonymous) {
    f->res= get_error(Files__anonymousFile, 0, f);
  } else {
    int res;
    
    /* flush file */
    DYN_TBCALL(Channel,ChannelDesc,Flush,f,((Channel__Channel)f));
    
    /* the temporary file has only write permissions for the user; now 
       add group and others permissions to the file as far as the umask 
       allows it */
    res = chmod((const char*)f->tmpName, 
		PERMISSIONS_REGISTER & ~active_umask);
    
    if (res != -1) {	/* rename file atomically */
#if defined(__MINGW32__) || defined(__CYGWIN32__)
    /* Windows file semantics do not allow open files to be renamed or files
       to be renamed over existing files. Hence the following ... [sg] */
    /* Note: This code should also be used under Cygwin for Win9X platforms.
       Cygwin emulation of unix semantics only seems to work under WinNT. [sg]*/

      res = close(f->fd);
      if (res != -1) {
        f->fd = -1;
        /* Remove the file if it already exists */
	if (access(f->name, 0)==0) {
          res = unlink(f->name);
        }
        /* Rename and then reopen the file */
        if (res != -1) {
          res = rename(f->tmpName, f->name);
          if (res != -1) {
            /* Hmmm. We should have stored the old mode & permissions to use
               again here. [sg] */
            res = open_file(f->name, O_RDWR, S_IREAD | S_IWRITE);
            f->fd = res;
          }
        }
      }
#else
       res = rename((const char*)f->tmpName, (const char*)f->name);
#endif
    }
    
    if (res == -1) {
      f->res = file_error((const char*)f->tmpName, (const char*)f->name);
    } else {
      free_tmp_name(f);
    }
  }
}

Files__Reader Files__FileDesc_NewReader(Files__File f) {
  Files__Reader r = NULL;

  if (!f->open) {
    f->res = get_error(Channel__channelClosed, 0, f);
  } else if (f->readable) {
    r = RT0__NewObject(OOC_TYPE_DESCR(Files,ReaderDesc));
    PosixFileDescr__InitReader ((PosixFileDescr__Reader)r, (PosixFileDescr__Channel)f);
  } else {
    f->res = get_error(Channel__noReadAccess, 0, f);
  }

  return r;
}

Files__Writer Files__FileDesc_NewWriter(Files__File f) {
  Files__Writer w = NULL;

  if (!f->open) {
    f->res = get_error(Channel__channelClosed, 0, f);
  } else if (f->writable) {
    w = RT0__NewObject(OOC_TYPE_DESCR(Files,WriterDesc));
    PosixFileDescr__InitWriter ((PosixFileDescr__Writer)w, (PosixFileDescr__Channel)f);
  } else {
    f->res = get_error(Channel__noWriteAccess, 0, f);
  }

  return w;
}

void Files__FileDesc_Close(Files__File f) {
  PosixFileDescr__ChannelDesc_Close ((PosixFileDescr__Channel)f);

  /* remove `f' from the list of open files */
  if (open_files == f) {
    open_files = f->next;
  } else {
    Files__File ptr = open_files;

    while (ptr->next != f) {
      ptr = ptr->next;
    }
    ptr->next = f->next;
  }

  /* delete temporary file and free its name */
  if (f->tmpName) {
    (void)unlink((const char*)f->tmpName);
    free_tmp_name(f);
  }
}

void Files__WriterDesc_Truncate(Files__Writer w, int newLength) {
  PosixFileDescr__Truncate ((PosixFileDescr__Writer)w, newLength);
}

#define NO_ERROR ((fd == -2) || ((fd == -1) && (errno == EACCES)))
#define RD_FLAGS ((1<<Files__read) | (1<<Files__tryRead))
#define WR_FLAGS ((1<<Files__write) | (1<<Files__tryWrite))
#define MODE_OLD 0
#define MODE_NEW 1
#define MODE_TMP 2
#define MODE_TMP_GEN_NAME 3

static int call_open (const OOC_CHAR8* name, OOC_UINT32 flags, int mode, int *access_mode) {
  /* create a new file or open one; try to open the file first with read and 
     write, permissions, then just read, then just write; if everything fails
     report `access denied'; for temporary files the permissions on the file
     system are set to zero, i.e. even the user has no read/write permissions,
     except through the current file descriptor */
  int fd, open_flags, permissions;

  if (mode == MODE_TMP_GEN_NAME) {
    open_flags = O_CREAT|O_EXCL;
  } else if (mode == MODE_NEW) {
    /* get rid of any previous file, since open will use the permissions of
       the previous file otherwise; this would break New() if we don't have 
       the requested permissions for the existing file */
    if (flags & (RD_FLAGS|WR_FLAGS)) {
      (void)unlink((const char*)name);
    }
    open_flags = O_CREAT|O_TRUNC;
  } else if (mode == MODE_TMP) {
    open_flags = O_CREAT|O_TRUNC;
  } else {  /* MODE_OLD */
    open_flags = 0;
  }
  if (mode == MODE_NEW) {
    permissions = PERMISSIONS_READ_WRITE;
  } else {
    permissions = PERMISSIONS_WRITE_ONLY;
  }

  fd = -2;
  if ((flags & RD_FLAGS) && (flags & WR_FLAGS)) {
    fd = open_file(name, open_flags|O_RDWR, permissions);
    if ((fd == -1) && (errno == EACCES) &&
	(flags & (1<<Files__read)) &&
	(flags & (1<<Files__write))) {
      return -3;
    }
    *access_mode = PosixFileDescr__readWrite;
  } 
  if (NO_ERROR && (flags & RD_FLAGS)) {
    fd = open_file(name, open_flags|O_RDONLY, permissions);
    if ((fd == -1) && (errno == EACCES) && (flags & (1<<Files__read))) {
      return -3;
    }
    *access_mode = PosixFileDescr__readOnly;
  }
  if (NO_ERROR && (flags & WR_FLAGS)) {
    fd = open_file(name, open_flags|O_WRONLY, permissions);
    if ((fd == -1) && (errno == EACCES) && (flags & (1<<Files__write))) {
      return -3;
    }
    *access_mode = PosixFileDescr__writeOnly;
  }
  if (NO_ERROR) {
    return -3;
  }

  return fd;
}

static OOC_CHAR8* local_strdup (const OOC_CHAR8* str) {
  /* strdup is a SVID function; it can't be used in this file */
  OOC_CHAR8 *new;
  new = (OOC_CHAR8*)RT0__NewBlock(strlen((const char*)str)+1);
  if (new) (void)strcpy((char*)new, (const char*)str);
  return new;
}

static Files__File create_file(const OOC_CHAR8* name, OOC_UINT32 flags,
			       int mode, Files__Result *res) {
/* Open the file `name' using the flags in `flags' that were initially passed 
   to New() or Tmp().  `mode' characterizes one of the four ways a file can
   be treated when opening it: old file, new file, temporary file, and 
   anonymous temporary file.  An error code is returned in `res'.  */
  int fd, access_mode;
  Files__File ch = NULL;
  char tname[PATH_MAX+16];
  
  if (strlen((const char*)name) > PATH_MAX) {
    *res = get_error(Files__nameTooLong, 0, NULL);
    add_msg_attribute(*res, "file_name", (const char*)name);
    return NULL;
  }

  if (mode == MODE_TMP_GEN_NAME) {
    /* lets try to find an unused name for our temporary file */
    int count = 0;
    
    do {
      /* repeat trying to open the file until an unused file is found, or
	 an error occured */
      if (count) {
	(void)sprintf(tname, "%s^%d", (const char*)name, count);
      } else {
	(void)sprintf(tname, "%s^", (const char*)name);
      }
      fd = call_open((const OOC_CHAR8*)tname, flags, mode, &access_mode);
      count++;
    } while ((fd == -1) && (errno == EEXIST));
  } else if (mode == MODE_TMP) {
    strcpy(tname, "tmp_XXXXXX");
#if HAVE_MKSTEMP
    fd = mkstemp(tname);
#else
    fd = call_open(mktemp(tname), flags, mode, &access_mode);
#endif
  } else {
    fd = call_open(name, flags, mode, &access_mode);
  }
  
  if (fd == -3) {
    /* couldn't get the requested access rights */
    *res = get_error(Files__accessDenied, 0, NULL);
    add_msg_attribute(*res, "file_name", (char*)name);
  } else if (fd == -1) {
    /* some other error */
    *res = file_error((char*)name, NULL);
  } else {
    /* file was opened with the requested access rights */
    ch = RT0__NewObject(OOC_TYPE_DESCR(Files,FileDesc));
    *res = Channel__done;
    PosixFileDescr__Init((PosixFileDescr__Channel)ch, fd, access_mode);
    ch->next = open_files;
    if ((mode == MODE_TMP_GEN_NAME) || (mode == MODE_TMP)) {
      ch->tmpName = local_strdup((const OOC_CHAR8*)tname);
    } else {
      ch->tmpName = NULL;
    }
    ch->name = NULL;
    ch->anonymous = 0;
    open_files = ch;
  }

  return ch;
}

Files__File Files__New(const OOC_CHAR8* file__ref, int file_0d, unsigned int flags, Files__Result *res) {
  return create_file(file__ref, flags, MODE_NEW, res);
}

Files__File Files__Old(const OOC_CHAR8* file__ref, int file_0d, unsigned int flags, Files__Result *res) {
  return create_file(file__ref, flags, MODE_OLD, res);
}

Files__File Files__Tmp(const OOC_CHAR8* file__ref, int file_0d, unsigned int flags, Files__Result *res) {
  Files__File ch = NULL;
  char *tname;
  int anonymous;
  
  anonymous = (!file__ref[0]);

  if (anonymous) {
    tname = "";  /* let create_file find a name */
  } else {
    tname = (char*)file__ref;
  }

  /* create file with minimal permissions; the permissions are extended
     upon registration if the umask allows it */
  ch = create_file((const OOC_CHAR8*)tname, flags, 
		   anonymous?MODE_TMP:MODE_TMP_GEN_NAME, res);
  if (ch) {
    ch->anonymous = anonymous;
    if (!anonymous) {
      ch->name = local_strdup(file__ref);
    }
  }
  return ch;
}

/* define the day count of the Unix epoch (Jan 1 1970 00:00:00 GMT) for the
   Time.TimeStamp format */
#define days_to_epoch 40587
#define end_of_epoch 65442
#define secs_per_day 86400

void Files__SetModTime(const OOC_CHAR8* file__ref, int file_0d, const Time__TimeStamp *mtime__ref, Files__Result *fres) {
  if ((mtime__ref->days < days_to_epoch) || 
      (mtime__ref->days >= end_of_epoch) ||
      (mtime__ref->msecs < 0) ||
      (mtime__ref->msecs > secs_per_day*1000)) {
    *fres = get_error(Files__invalidTime, 0, NULL);
  } else {
    int res;
    int seconds = (mtime__ref->days - days_to_epoch) * secs_per_day +
                  (mtime__ref->msecs / 1000);
#if HAVE_UTIMES			/* we have microsecond resolution */
    struct timeval tpv[2];
    
    tpv[0].tv_sec = tpv[1].tv_sec = seconds;
    tpv[0].tv_usec = tpv[1].tv_usec = (mtime__ref->msecs % 1000) * 1000;
    res = utimes((char*)file__ref, tpv);
#else                           /* we only have second resolution */
    struct utimbuf times;
    
    times.actime = seconds;
    times.modtime = seconds;
    res = utime((const char*)file__ref, &times);
#endif

    if (res) {
      *fres = file_error((const char*)file__ref, NULL);
    } else {
      *fres = Files__done;
    }
  }
}

/* define the day count of the Unix epoch (Jan 1 1970 00:00:00 GMT) for the
   Time.TimeStamp format */
#define days_to_epoch 40587
#define secs_per_day 86400

void Files__GetModTime(const OOC_CHAR8* file__ref, int file_0d, Time__TimeStamp *mtime, RT0__Struct mtime__tag, Files__Result *fres) {
  int res;
  struct stat stat_buf;

  res = stat((const char*)file__ref, &stat_buf);
  if (res == -1) {
    *fres = file_error((const char*)file__ref, NULL);
  } else {
    mtime->days = days_to_epoch + stat_buf.st_mtime / secs_per_day;
    mtime->msecs = (stat_buf.st_mtime % secs_per_day) * 1000;
#if HAVE_ST_MTIME_USEC
    mtime->msecs += (stat_buf.st_mtime_usec / 1000);
#endif
    *fres = Channel__done;
  }
}

extern OOC_BOOLEAN Files__Exists(const OOC_CHAR8* file__ref, int file_0d) {
#ifndef F_OK
#define F_OK 0
#endif
  return (access((const char*)file__ref, F_OK) == 0);
}

static void close_all_files (void) {
  while (open_files) {
    Files__FileDesc_Close (open_files);
  }
}

void OOC_Files_init(void) {
  Files__errorContext = RT0__NewObject(OOC_TYPE_DESCR(Files,ErrorContextDesc));
  Msg__InitContext((Msg__Context)Files__errorContext, 
		   (const OOC_CHAR8*)"OOC:Core:Files", 15);
  
  active_umask = umask (0);
  umask (active_umask);
  /* make sure that all files are closed upon program termination */
  Termination__RegisterProc (&close_all_files);
}

void OOC_Files_destroy(void) {
  /* FIXME... if we ever to module unloading  */
}
