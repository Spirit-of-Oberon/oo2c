(* 	$Id: File.Mod,v 1.13 2004/04/03 14:43:17 mva Exp $	 *)
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
  OS:ProcessParameters, OS:HostPath, Object, Exception, ADT:StringBuffer,
  IO, IO:FileChannel, URI0 := URI, URI:CharClass, URI:String,
  URI:Scheme:Hierarchical, URI:Authority:ServerBased, URI:Parser;


TYPE
  URI* = POINTER TO URIDesc;
  URIDesc = RECORD
  (**This class implements the @samp{file:} URI scheme.  It uses
     @otype{ServerBased.Authority} for its authority component, and does
     not support a query part.  *)
    (Hierarchical.GenericDesc)
  END;


PROCEDURE Init* (file: URI; schemeId: STRING;
                 authority: URI0.Authority; query: URI0.Query);
  BEGIN
    Hierarchical.Init (file, schemeId, authority, query)
  END Init;

PROCEDURE New* (schemeId: STRING;
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
    RETURN ServerBased.New (NIL, "", -1, -1)
  END NewAuthority;

PROCEDURE (file: URI) AuthorityMandatory*(): BOOLEAN;
  BEGIN
    RETURN TRUE;
  END AuthorityMandatory;

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

PROCEDURE (file: URI) GetPath*(): Object.String8;
(**Returns the file path associated with the URI @oparam{file}.  On a Unix 
   system, this is identical to the URI's path component.  *)
  VAR
    segm: Hierarchical.Segment;
    sb: StringBuffer.StringBuffer;
    str: STRING;
  BEGIN
    sb := StringBuffer.New("");
    segm := file. pathList;
    WHILE (segm # NIL) DO
      IF (segm # file. pathList) OR file. absolutePath THEN
        sb.Append("/");
      END;
      sb.Append(segm.string);
      segm := segm. next
    END;
    
    str := HostPath.Denormalize(sb.ToString());
    RETURN str(Object.String8);
  END GetPath;

PROCEDURE (file: URI) GetChannel* (mode: URI0.ChannelMode): IO.ByteChannel
RAISES IO.Error;
  VAR
    s: STRING;
  BEGIN
    s := file.GetPath();
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
    RETURN New("file", NIL, NIL);
  END NewPrototype;

PROCEDURE GetCwd*(): URI;
(**Creates an absolute file URI for the current working directory.  If the
   current working directory cannot be determined, the value @code{NIL} is
   returned.

   @precond
   The URL scheme ``file'' must have been registered with
   @oproc{*URI.RegisterScheme}.
   @end precond  *)
  VAR
    uri: URI0.URI;
    uriString: StringBuffer.StringBuffer;
    cwd, str: STRING;
  BEGIN
    TRY
      cwd := HostPath.Normalize(ProcessParameters.GetCwd());
      uriString := StringBuffer.New("file://");
      String.AppendEscaped(cwd, CharClass.unreservedPChar+"/", uriString);
      IF (uriString.CharAt(uriString.length-1) # "/") THEN
        uriString.Append ("/");
      END;
      str := uriString.ToString();
      TRY
        uri := Parser.NewURI(str(Object.String8), NIL);
        RETURN uri(URI);
      CATCH Exception.ParseError:
        ASSERT(FALSE);
      END;
    CATCH IO.Error:
      RETURN NIL;
    END;
  END GetCwd;

PROCEDURE ToURI* (filePath: ARRAY OF CHAR): URI;
(**Constructs a @samp{file:} URI for a given file path.  Characters that
   are not valid within an URI are escaped.  *)
  VAR
    uri: URI0.URI;
    uriString: StringBuffer.StringBuffer;
    normPath: STRING;
    str: STRING;
  BEGIN
    TRY
      normPath := HostPath.Normalize(Object.NewLatin1(filePath));
      
      IF (normPath.CharAt(0) = "/") THEN
        uriString := StringBuffer.New("file://");
        String.AppendEscaped (normPath, CharClass.unreservedPChar+"/", uriString);
        str := uriString.ToString();
        uri := Parser.NewURI (str(Object.String8), NIL)
      ELSE
        uriString := StringBuffer.New("");
        String.AppendEscaped (normPath, CharClass.unreservedChar+"/", uriString);
        str := uriString.ToString();
        uri := Parser.NewURI (str(Object.String8), GetCwd())
      END;
      RETURN uri(URI);
    CATCH IO.Error:
      RETURN NIL;
    CATCH Exception.ParseError:
      RETURN NIL;
    END;
  END ToURI;

END URI:Scheme:File.
