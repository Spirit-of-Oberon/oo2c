MODULE OOC:Auxiliary:HTTPServer;

IMPORT
  Log, Msg, IO:Port, IO:Port:ServerSocket, Net:HTTP:Server;

TYPE
  Servlet* = POINTER TO ServletDesc;
  ServletDesc* = RECORD
    (Server.ServletDesc)
    continueLoop: BOOLEAN;
  END;

PROCEDURE InitServlet* (s: Servlet);
  BEGIN
    Server.InitServlet (s);
    s. continueLoop := TRUE;
  END InitServlet;

PROCEDURE (servlet: Servlet) SetExitFlag*;
  BEGIN
    servlet. continueLoop := FALSE;
  END SetExitFlag;

PROCEDURE Run* (servlet: Servlet);
  CONST
    port = 54321;
    selectTimeout = 5;
  VAR
    group: Port.Group;
    serverSocket: ServerSocket.Port;
    res: Msg.Msg;
  BEGIN
    group := Port.NewGroup();
    serverSocket := ServerSocket.NewPort (group, port, TRUE, 5,
                                          Server.NewServerFactory (servlet));
    serverSocket. Open (res);
    IF (res = ServerSocket.done) THEN
      Log.LongInt ("HTTP server listening on port", port);
      WHILE servlet. continueLoop DO
        group. Select (selectTimeout, 0);
      END; 
      group. Select (selectTimeout, 0);  (* push out last response  *)
      serverSocket. Close (ServerSocket.done, res);
    ELSE
      Log.Msg ("failed to open HTTP server socket");
      serverSocket. Disband;
      serverSocket := NIL
    END;
  END Run;

END OOC:Auxiliary:HTTPServer.
