MODULE TestServer;

IMPORT
  Out, Object,
  IO, IO:Address, IO:SocketChannel, IO:Select;
  
VAR
  s: SocketChannel.ServerChannel;
  c: SocketChannel.Channel;
  addr: Address.Socket;
  sel: Select.Selector;
  sk, k: IO.SelectionKey;
  count, clientCount, i, r, w: LONGINT;
  clients: ARRAY 16 OF SocketChannel.Channel;
  buffer: ARRAY 8*1024 OF CHAR;
  str: STRING;
  chars: Object.CharsLatin1;
BEGIN  <* Warnings := FALSE *>
  (* create server socket *)
  s := SocketChannel.OpenServer();
  s.socket.SetReuseAddress(TRUE);
  s.socket.SetBlocking(FALSE);
  s.socket.Bind(Address.GetSocketInet(Address.inet4Any, 5556), 5);

  (* create selector, populate it with server socket *)
  sel := Select.Open();
  sk := s.RegisterWithSelector(sel, {IO.opAccept}, NIL);
  clientCount := 0;
  
  LOOP
    Out.String("... calling select()"); Out.Ln;
    count := sel.Select(10, 0);
    Out.String("[select] count="); Out.LongInt(count,0); Out.Ln;
    IF (count = 0) THEN  (* timeout *)
      Out.String("[timeout] aborting program"); Out.Ln; HALT(1);
    ELSE
      LOOP
        k := sel.NextKey();
        IF (k = NIL) THEN
          Out.String("... NIL"); Out.Ln;
          EXIT;
        ELSIF (k.channel = s) THEN  (* server socket *)
          Out.String("... accept"); Out.Ln;
          LOOP
            c := s.Accept();
            IF (c = NIL) THEN            (* no more pending connects *)
              EXIT;
            ELSE
              addr := c(SocketChannel.Channel).socket.RemoteAddress();
              Out.String("[accept] "); Out.Object(addr); Out.Ln;
              
              c.SetBlocking(FALSE);
              sk := c.RegisterWithSelector(sel, {IO.opRead}, NIL);
              clients[clientCount] := c(SocketChannel.Channel);
              INC(clientCount);
            END;
          END;
        ELSE  (* client socket *)
          Out.String("... read"); Out.Ln;
          c := k.channel(SocketChannel.Channel);
          addr := c.socket.RemoteAddress();
          
          r := c.Read(buffer, 0, LEN(buffer));
          IF (r = -1) THEN               (* connection closed *)
            Out.String("[closed] "); Out.Object(addr); Out.Ln;
            IF (clientCount # 0) THEN
              i := 0;
              WHILE (clients[i] # c) DO
                INC(i);
              END;
              clients[i] := clients[clientCount-1];
            END;
            DEC(clientCount);
            c.Close();
          ELSE
            Out.String("... bytes="); Out.LongInt(r, 0); Out.Ln;
            str := "["+addr.ToString()+"] ";
            chars := str(Object.String8).CharsLatin1();
            FOR i := 0 TO clientCount-1 DO
              IF (clients[i] # c) THEN
                w := clients[i].Write(chars^, 0, str.length);
                ASSERT(w = str.length);
              END;
            END;
            REPEAT
              FOR i := 0 TO clientCount-1 DO
                IF (clients[i] # c) THEN
                  w := clients[i].Write(buffer, 0, r);
                  ASSERT(r = w);
                END;
              END;
              r := c.Read(buffer, 0, LEN(buffer));
              Out.String("... bytes="); Out.LongInt(r, 0); Out.Ln;
            UNTIL (r = 0);
          END;
        END;
      END;
    END;
  END;
END TestServer.
