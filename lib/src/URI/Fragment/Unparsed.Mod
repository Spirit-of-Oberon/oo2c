(* 	$Id: Unparsed.Mod,v 1.2 2003/05/19 22:55:38 mva Exp $	 *)
MODULE URI:Fragment:Unparsed;
(*  Implements class for unparsed fragment identifiers.
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
  TextRider, CC := CharClass, Object, Exception, ADT:StringBuffer,
  URI, URI:CharClass;

TYPE
  Fragment* = POINTER TO FragmentDesc;
  FragmentDesc = RECORD
  (**Unparsed fragment identifier of an URI reference.  A fragment identifier
     is the component in an URI reference following the crosshatch character
     @samp{#}.  The format of the fragment identifier is interpreted by the
     user agent after the URI document has been retrieved.  That it, it depends
     on the document, and @emph{not} on the URI scheme being used.  *)
    (URI.FragmentDesc)
    unparsed-: STRING;
    (**Holds the fragment identifier of a URI @emph{without} any modifications.
       In particular, escaped characters are @emph{not} replaced with their
       character value.  Interpretation of special characters and escaped
       characters is up to the user agent.  *)
  END;


PROCEDURE Init* (frag: Fragment; unparsed: STRING);
(**Initializes unparsed fragment identifier.

   @precond
   @oparam{unparsed} is not @code{NIL}.
   @end precond *)
  BEGIN
    ASSERT (unparsed # NIL);
    frag. unparsed := unparsed
  END Init;

PROCEDURE New* (unparsed: STRING): Fragment;
(**Creates new unparsed fragment identifier.

   @precond
   @oparam{unparsed} is not @code{NIL}.
   @end precond *)
  VAR
    frag: Fragment;
  BEGIN
    NEW (frag);
    Init (frag, unparsed);
    RETURN frag
  END New;

PROCEDURE (frag: Fragment) Clone* (): Fragment;
  VAR
    copy: Fragment;
  BEGIN
    NEW (copy);
    frag. Copy (copy);
    RETURN copy
  END Clone;

PROCEDURE (frag: Fragment) Copy* (dest: URI.Fragment);
  BEGIN
    (*frag. Copy^ (dest); procedure is abstract in super class *)
    WITH dest: Fragment DO
      dest. unparsed := frag. unparsed;
    END
  END Copy;

PROCEDURE (frag: Fragment) ParseFragment* (str: Object.CharsLatin1;
                                           offset: URI.Offset)
RAISES Exception.ParseError;
  VAR
    i: URI.Offset;
  BEGIN
    i := 0;
    WHILE CharClass.SkipURIC (str^, i) DO END;
    IF (str[i] # 0X) THEN
      RAISE(NEW(Exception.ParseError,
                "Illegal character in fragment component",
                i+offset));
    ELSE
      frag.unparsed := Object.NewLatin1(str^);
    END
  END ParseFragment;

PROCEDURE (frag: Fragment) WriteXML* (w: TextRider.Writer);
  BEGIN
    w. WriteString (CC.eol+"<fragment-unparsed>");
    w. WriteObject (frag. unparsed);
    w. WriteString ("</fragment-unparsed>")
  END WriteXML;

PROCEDURE (frag: Fragment) Append* (sb: StringBuffer.StringBuffer);
  BEGIN
    sb.Append("#");
    sb.Append(frag. unparsed);
  END Append;

END URI:Fragment:Unparsed.
