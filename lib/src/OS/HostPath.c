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


#ifdef WIN32
static int endsWithSeparator(char * path) {
  int len;

  len = strlen(path);
  return (path[len] == '/') || (path[len] == '\\');
}

Object__CharsLatin1 StringToChars(Object__String str) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)str;
  i0 = (OOC_INT32)Object__String8Desc_CharsLatin1((Object__String8)(_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 118)))), &_td_Object__String8Desc, 118)));
  return (Object__CharsLatin1)i0;
  ;
}

Object__String CharsToString(Object__CharsLatin1 chars) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)chars;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 263)), 0);
  i0 = (OOC_INT32)Object__NewLatin1((void*)(_check_pointer(i0, 263)), i1);
  return (Object__String)i0;
  ;
}

Object__String OS_HostPath__Normalize(Object__String pathString) {
  char newpath [4096]; 
  int drive, pos;
  char * path;
  char * result;
  Object__String resultString;

  path = StringToChars(pathString);

  if (isalpha(path[0]) && (path[1] == ':')) {
    /* leading drive identifier */
    if ((path[2] != '\\') && (path[2] != '/')) {
      /* drive identifier with relative path. */
      drive = tolower(path[0]) - 'a' + 1;
      if (_getdcwd(drive, newpath, sizeof(newpath))) {
        result = (char *) malloc (strlen(newpath)+strlen(path)+3);
        if (!endsWithSeparator(newpath)) {
          strcat(result, "/");
        }
        strcat(result, path+2);
      } else {
	IO_StdChannels__IOError(NULL);
      }
    } else {
      /* drive identifier with absolute path */
      result = (char *) malloc(strlen(path)+3);
      strcpy(result, path);
    }
    result[1] = '$';
    memmove(result+1, result, strlen(result)+1);
    result[0] = '/';
  } else {
    result = (char *) malloc(strlen(path)+1);
    strcpy(result, path);
  }
  pos = 0;
  while (result[pos]) {
    if (result[pos] == '\\') {
      result[pos] = '/';
    }
    ++pos;
  }
  resultString = CharsToString((Object__CharsLatin1) result);
  free(result);
  return resultString;
}

Object__String OS_HostPath__Denormalize(Object__String pathString) {
  char * path;
  char * result;
  Object__String resultString;

  path = StringToChars(pathString);
  result = (char *) malloc (strlen(path)+1);

  if ( (path[0] == '/') && isalpha(path[1]) && (path[2] == '$')) {
    /* path[2] = ':'; */
    memmove(result, path+3, strlen(path+3)+1);
  } else {
    strcpy(result, path);
  }
  resultString = CharsToString((Object__CharsLatin1) result);
  free(result);
  return resultString;
}

#else
Object__String OS_HostPath__Normalize(Object__String path) {
  return path;
}

Object__String OS_HostPath__Denormalize(Object__String path) {
  return path;
}
#endif

void OOC_OS_HostPath_init(void) {
}
