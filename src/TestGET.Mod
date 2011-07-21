MODULE TestGET;  <*Warnings:=FALSE*>

(**
This program takes a single argument, an "http" URI.  It tries to retrieve
the URI using a "GET" request.  On success, the retrieved entity's content
is written to stdout.  Otherwise, an error message is written to stderr.
*)

IMPORT
  Err, ProgramArgs, IO, IO:StdChannels, TextRider,
  URI, URI:Parser, URI:Scheme:HTTP;

TYPE
  Buffer = ARRAY 8*1024 OF CHAR;

VAR
  ch: IO.ByteChannel;
  argReader: TextRider.Reader;
  buffer: Buffer;
  uri: URI.URI;
  r, w: LONGINT;
BEGIN
  IF (ProgramArgs.args.ArgNumber() # 1) THEN
    Err.String("usage: ./TestGET <absolute-uri>"); Err.Ln; HALT(1);
  ELSE
    argReader := TextRider.ConnectReader(ProgramArgs.args);
    argReader.ReadLine (buffer);        (* skip command name *)
    argReader.ReadLine (buffer);        (* get argument *)

    URI.RegisterScheme(HTTP.NewPrototype());
    uri := Parser.NewURILatin1(buffer, NIL);  (* parse URI *)
    ch := uri.GetChannel(URI.channelOld); (* get channel for URI *)

    (* on success: copy channel to stdout *)
    r := ch.Read(buffer, 0, SIZE(Buffer));
    WHILE (r # -1) DO
      w := StdChannels.stdout.Write(buffer, 0, r);
      ASSERT(w = r);
      r := ch.Read(buffer, 0, SIZE(Buffer));
    END;
  END;
END TestGET.
