MODULE TestWebServer;

IMPORT
  Log, ADT:String, XML:Writer, XML:UnicodeCodec:Latin1,
  OOC:Auxiliary:HTTPServer, Net:HTTP, Net:HTTP:Server;

TYPE
  Servlet* = POINTER TO ServletDesc;
  ServletDesc = RECORD
    (HTTPServer.ServletDesc)
  END;

PROCEDURE NewServlet (): Servlet;
  VAR
    s: Servlet;
  BEGIN
    NEW (s);
    HTTPServer.InitServlet (s);
    RETURN s
  END NewServlet;

PROCEDURE (servlet: Servlet) DoGET* (req: Server.Request; resp: Server.Response);
  VAR
    w: Writer.Writer;
    uriString: ARRAY 256 OF CHAR;
  BEGIN
    resp. SetStatus (HTTP.scOk);
    resp. SetHeader (String.New ("Content-Type"), String.New ("text/html"));
    w := Writer.New (resp. GetWriter(), Latin1.factory, FALSE, 2);
    w. StartTag ("html", FALSE);
    w. StartTag ("body", FALSE);

    w. StartTag ("p", TRUE);
    req. uri. GetString (uriString);
    Log.Msg (uriString);
    IF (uriString = "http:/exit") THEN
      w. WriteLatin1 ("Bye!");
      servlet. SetExitFlag
    ELSE
      w. WriteLatin1 ("a silly little HTML response of no importance [");
      w. StartTag ("a", TRUE);
      w. AttrString ("href", "/exit");
      w. WriteLatin1 ("exit");
      w. EndTag;  (* a *)
      w. WriteLatin1 ("]");
    END;
    w. EndTag;  (* p *)
    
    w. EndTag;  (* body *)
    w. EndTag;  (* html *)
    w. EndOfText
  END DoGET;

BEGIN
  HTTPServer.Run (NewServlet())
END TestWebServer.
