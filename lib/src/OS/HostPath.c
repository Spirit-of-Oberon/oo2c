/*
<* IF TARGET_OS="Win32" THEN *>

(* "Normalisation" of windows file paths:
 * - backslash is converted to forward slash
 * - drive identifier "C:" is converted to "/C$"
 * - drive-relative paths (eg. c:test) are converted to absolute paths
 *
 * The normalised path can be used within a URI, and obeys the unix convention
 * that a leading "/" indicates an absolute path. 
 * 
 * "Denormalisation" of windows paths:
 * - backslashes cause problems in many contexts. Windows usually treats
 *   forward and back slashes equivalently, so we retain only forward slashes.
 * - (HACK) OOC treats paths like "c:/.." as relative, erroneously applying 
 *   transformations on repository paths. For now, we treat all absolute paths
 *   as relative to the CURRENT drive.
 *)

PROCEDURE NormalisePath(VAR path : ARRAY OF CHAR; VAR res : Msg.Msg);
VAR
  drive : CHAR;
  pos, id : INTEGER;
  cwd : ARRAY 1024 * 4 OF CHAR;

  PROCEDURE EndsWithSeparator(VAR string : ARRAY OF CHAR) : BOOLEAN;
  VAR 
    lenString : INTEGER; ch : CHAR;
  BEGIN
    lenString := Strings.Length(string);
    IF lenString = 0 THEN RETURN FALSE END;
    ch := string[lenString-1];
    RETURN (ch = '\') OR (ch = '/');
  END EndsWithSeparator;

BEGIN
  res := ProcessParameters.done;
  IF CharClass.IsAlpha(path[0]) & (path[1] = ':') THEN
    (* leading drive identifier *)
    IF (path[2] # '\') & (path[2] # '/') THEN
      (* drive identifier with relative path. Use working directory on that
         drive.  *)
      drive := path[0];
      IF (drive >= 'A') & (drive <= 'Z') THEN
        id := ORD(drive) - ORD('A') + 1;
      ELSE
        id := ORD(drive) - ORD('a') + 1;
      END;
      ProcessParameters.getdcwd (id, cwd, res);
      IF (res # ProcessParameters.done) THEN RETURN END;
      IF ~EndsWithSeparator(cwd) THEN
        Strings.Append("/", cwd)
      END;
      Strings.Delete(path, 0, 2);
      Strings.Insert(cwd, 0, path);
    END;
    path[1] := '$';
    Strings.Insert("/", 0, path);
  END;
(* Replace '\' with '/' *)
  pos := 0;
  WHILE path[pos] # 0X DO
    IF path[pos] = '\' THEN
      path[pos] := '/';
    END;
    INC(pos)
  END;
END NormalisePath;

PROCEDURE DenormalisePath(VAR path : ARRAY OF CHAR);
VAR pos : INTEGER;
BEGIN
  IF (path[0] = '/') & CharClass.IsAlpha(path[1]) & (path[2] = '$') THEN
    path[2] := ':';
    (* Strings.Delete(path, 0, 1); *)
    (* HACK: OOC treats paths like "c:/.." as relative, erroneously applying 
       transformations on repository paths. For now, we treat all absolute
       paths as relative to the CURRENT drive. *)
    Strings.Delete(path, 0, 3);
  END;
END DenormalisePath;

<* ELSE *>

PROCEDURE NormalisePath(VAR path : ARRAY OF CHAR; VAR res : Msg.Msg);
BEGIN
  res := NIL;
END NormalisePath;

PROCEDURE DenormalisePath(VAR path : ARRAY OF CHAR);
BEGIN
END DenormalisePath;

<* END *>
*/

#ifdef WIN32
#include <io.h>
#include <direct.h>
#include <ctype.h>
#else
#include <unistd.h>
#endif
#include <errno.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include <__oo2c.h>
#include <__config.h>
#include <OS/HostPath.d>


void OS_HostPath__ErrorContextDesc_GetTemplate(OS_HostPath__ErrorContext context, Msg__Msg msg, Msg__LString templ, OOC_LEN templ_0d) {
  char *str;
  OOC_INT32 res = msg->code;
  
  if (res == OS_HostPath__pathTooLong) {
    str = "Transformed path does not fit into buffer";
  } else {
    str = "Unknown error code";
  }

  _copy_8to16(str, templ, templ_0d);
  if (msg->attribList) {
    Msg__Attribute attr;
    OOC_CHAR16 eol[2] = {(OOC_CHAR16)CharClass__eol[0], (OOC_CHAR16)0};
    OOC_CHAR16 str16[Msg__sizeAttrName+1];
    
    attr = msg->attribList;
    while (attr) {
      LongStrings__Append(eol, 2, templ, templ_0d);
      _copy_8to16((char*)attr->name, str16, strlen((char*)attr->name)+1);
      LongStrings__Append(str16, Msg__sizeAttrName+1, templ, templ_0d);
      _copy_8to16("=${", str16, Msg__sizeAttrName+1);
      LongStrings__Append(str16, Msg__sizeAttrName+1, templ, templ_0d);
      _copy_8to16((char*)attr->name, str16, Msg__sizeAttrName+1);
      LongStrings__Append(str16, Msg__sizeAttrName+1, templ, templ_0d);
      _copy_8to16("}", str16, Msg__sizeAttrName+1);
      LongStrings__Append(str16, Msg__sizeAttrName+1, templ, templ_0d);
      attr = attr->nextAttrib;
    }
  }
}


static Msg__Msg get_error() {
  Msg__Msg msg;
  OOC_INT32 code;
  
  switch (errno) {
  case ERANGE: code = OS_HostPath__pathTooLong; break;
  default    : code = -1;
  }
  
  msg = Msg__New((Msg__Context)OS_HostPath__errorContext, code);
#if HAVE_STRERROR
  DYN_TBCALL(Msg,MsgDesc,SetStringAttrib,msg,
	     (msg, (const OOC_CHAR8*)"errstr", 7, (OOC_CHAR8*)strerror(errno)));
#endif
  DYN_TBCALL(Msg,MsgDesc,SetIntAttrib,msg,
	     (msg, (const OOC_CHAR8*)"errno", 6, (OOC_INT32)errno));
  return msg;
}

#ifdef WIN32
static int endsWithSeparator(char * path) {
  int len;

  len = strlen(path);
  return (path[len] == '/') || (path[len] == '\\');
}

void OS_HostPath__Normalize(OOC_CHAR8 path[], OOC_LEN path_0d, Msg__Msg *res) {
  char newpath [4096]; 
  int drive, pos;
  *res = NULL;
  if (isalpha(path[0]) && (path[1] == ':')) {
    /* leading drive identifier */
    if ((path[2] != '\\') && (path[2] != '/')) {
      /* drive identifier with relative path. */
      drive = tolower(path[0]) - 'a' + 1;
      if (_getdcwd(drive, newpath, sizeof(newpath))) {
        if (!endsWithSeparator(newpath)) {
          strcat(newpath, "/");
        }
        strcat(newpath, path+2);
        strcpy(path, newpath);
      } else {
        *res = get_error(); return;
      }
    }
    path[1] = '$';
    memmove(path+1, path, strlen(path)+1);
    path[0] = '/';
  }
  pos = 0;
  while (path[pos]) {
    if (path[pos] == '\\') {
      path[pos] = '/';
    }
    ++pos;
  }
}

void OS_HostPath__Denormalize(OOC_CHAR8 path[], OOC_LEN path_0d, Msg__Msg *res) {
  *res = NULL;
  if ( (path[0] == '/') && isalpha(path[1]) && (path[2] == '$')) {
    path[2] = ':';
    memmove(path, path+3, strlen(path));
  }
}

#else
void OS_HostPath__Normalize(OOC_CHAR8 path[], OOC_LEN path_0d, Msg__Msg *res) {
  *res = NULL;
}

void OS_HostPath__Denormalize(OOC_CHAR8 path[], OOC_LEN path_od, Msg__Msg *res) {
  *res = NULL;
}
#endif

void OOC_OS_HostPath_init(void) {
  OS_HostPath__errorContext =
    RT0__NewObject(OOC_TYPE_DESCR(OS_HostPath,ErrorContextDesc));
  Msg__InitContext((Msg__Context)OS_HostPath__errorContext, 
		   (const OOC_CHAR8*)"OS:HostPath", 12);
}
