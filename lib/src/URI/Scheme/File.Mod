(* 	$Id$	 *)
MODULE URI:Scheme:File;
(*  Implementation of the "file" URI scheme.
    Copyright (C) 2000, 2003  Michael van Acken

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
*)


IMPORT
  Msg, Strings, OS:ProcessParameters, Object, IO, IO:FileChannel,
  URI0 := URI, URI:CharClass, URI:String, 
  URI:Scheme:Hierarchical, URI:Authority:ServerBased, URI:Parser;


TYPE
  URI* = POINTER TO URIDesc;
  URIDesc = RECORD
  (**This class implements the @samp{file:} URI scheme.  It uses
     @otype{ServerBased.Authority} for its authority component, and does
     not support a query part.  *)
    (Hierarchical.GenericDesc)
  END;


PROCEDURE Init* (file: URI; schemeId: URI0.StringPtr;
                 authority: URI0.Authority; query: URI0.Query);
  BEGIN
    Hierarchical.Init (file, schemeId, authority, query)
  END Init;

PROCEDURE New* (schemeId: URI0.StringPtr;
                authority: URI0.Authority; query: URI0.Query): URI;
  VAR
    file: URI;
  BEGIN
    NEW (file);
    Init (file, schemeId, authority, query);
    RETURN file
  END New;

PROCEDURE (file: URI) NewAuthority* (): URI0.Authority;
  BEGIN
    RETURN ServerBased.New (NIL, String.Copy (""), -1, -1)
  END NewAuthority;

PROCEDURE (file: URI) NewQuery* (): URI0.Query;
  BEGIN
    RETURN NIL
  END NewQuery;

PROCEDURE (file: URI) Clone* (): URI;
  VAR
    copy: URI;
  BEGIN
    NEW (copy);
    file. Copy (copy);
    RETURN copy
  END Clone;

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
      IF (drive >= 'A') & (drive < 'Z') THEN
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

PROCEDURE (file: URI) GetPath* (VAR filePath: ARRAY OF CHAR);
(**Returns the file path associated with the URI @oparam{file}.  On a Unix 
   system, this is identical to the URI's path component.  *)
  VAR
    segm: Hierarchical.Segment;
  BEGIN
    COPY ("", filePath);
    segm := file. pathList;
    WHILE (segm # NIL) DO
      IF (segm # file. pathList) OR file. absolutePath THEN
        Strings.Append ("/", filePath)
      END;
      Strings.Append (segm. string^, filePath);
      segm := segm. next
    END;
    DenormalisePath(filePath);
  END GetPath;

PROCEDURE (file: URI) GetChannel* (mode: URI0.ChannelMode): IO.ByteChannel
RAISES IO.Error;
  VAR
    filePath: ARRAY 2*1024 OF CHAR;
    s: Object.String8;
  BEGIN
    file. GetPath (filePath);
    s := Object.NewLatin1(filePath);
    CASE mode OF
    | URI0.channelNew:
      RETURN FileChannel.Open(s,
                              {FileChannel.read, FileChannel.write,
                               FileChannel.create, FileChannel.truncate});
    | URI0.channelTmp:
      RETURN FileChannel.Open(s,
                              {FileChannel.read, FileChannel.write,
                               FileChannel.tmpFile});
    | URI0.channelOld:
      RETURN FileChannel.Open(s, {FileChannel.read});
    END
  END GetChannel;

PROCEDURE NewPrototype*(): URI;
  BEGIN
    RETURN New (String.Copy ("file"), NIL, NIL)
  END NewPrototype;

PROCEDURE GetCwd*(): URI;
(**Creates an absolute file URI for the current working directory.  If the
   current working directory cannot be determined, the value @code{NIL} is
   returned.  *)
  VAR
    uri: URI0.URI;
    path, uriString: ARRAY 4*1024 OF CHAR;
    res: Msg.Msg;
  BEGIN
    ProcessParameters.getcwd (path, res);
    IF (res = NIL) THEN 
      NormalisePath(path, res) 
    END;
    IF (res = NIL) THEN
      uriString := "file:";
      String.AppendEscaped (path, CharClass.unreservedPChar+"/", uriString);
      IF (uriString[Strings.Length (uriString)-1] # "/") THEN
        Strings.Append ("/", uriString)
      END;
      uri := Parser.NewURI (uriString, NIL, res);
      ASSERT (uri # NIL);
      RETURN uri(URI)
    END;
    RETURN NIL
  END GetCwd;

PROCEDURE ToURI* (filePath: ARRAY OF CHAR): URI;
(**Constructs a @samp{file:} URI for a given file path.  Characters that
   are not valid within an URI are escaped.  *)
  VAR
    uri: URI0.URI;
    uriString, normPath: ARRAY 4*1024 OF CHAR;
    res: Msg.Msg;
  BEGIN
    COPY(filePath, normPath);
    NormalisePath(normPath, res);
    IF res # NIL THEN RETURN NIL END;
    IF (normPath[0] = "/") THEN
      uriString := "file:";
      String.AppendEscaped (normPath, CharClass.unreservedPChar+"/", uriString);
      uri := Parser.NewURI (uriString, NIL, res)
    ELSE
      uriString := "";
      String.AppendEscaped (normPath, CharClass.unreservedChar+"/", uriString);
      uri := Parser.NewURI (uriString, GetCwd(), res)
    END;
    IF (uri = NIL) THEN
      RETURN NIL
    ELSE
      RETURN uri(URI)
    END
  END ToURI;

BEGIN
  URI0.RegisterScheme (NewPrototype())
END URI:Scheme:File.
