MODULE IO:Port:Streaming [OOC_EXTENSIONS];
(*  Abstraction of a port for streaming data.
    Copyright (C) 2001  Michael van Acken

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
  SYSTEM, Msg, Port0 := IO:Port;


TYPE
  Port* = POINTER TO PortDesc;
  PortDesc* = RECORD [ABSTRACT]
    (Port0.PortDesc)
    
    outputBuffer-: Port0.Buffer;
    outputSize-: LONGINT;
    outputStart*, outputEnd*: LONGINT;
    (* if outputState = outputEnd --> buffer empty
       if outputStart < outputEnd:
         valid data in outputBuffer[outputStart, outputEnd[
       else
         value data in outputBuffer[outputStart, LEN(outputBuffer)[
                       outputBuffer[0, outputEnd[  *)
    alertLevel-: LONGINT;                (* maintained on behalf of transfer *)
    
    inputBuffer-: Port0.Buffer;
    inputSize-: LONGINT;
    inputStart*: LONGINT;
  END;

TYPE
  Transfer* = POINTER TO TransferDesc;
  TransferDesc* = RECORD [ABSTRACT]
  (**Transfers byte data to and from a port.  Instances of this class are
     intermediaries between ports and the application.  *)
    (Port0.TransferDesc)
    port-: Port;
    (**The port that is served by this transfer object.  This field may be
       @code{NIL} for unattached instances.  *)
  END;


PROCEDURE InitPort* (p: Port; group: Port0.Group);
  BEGIN
    Port0.InitPort (p, group);
    
    p. outputBuffer := NIL;
    p. outputSize := -1;
    p. outputStart := -1;
    p. outputEnd := -1;
    p. alertLevel := -1;
    
    p. inputBuffer := NIL;
    p. inputSize := -1;
    p. inputStart := -1;
  END InitPort;

PROCEDURE (p: Port) CanRead*(): BOOLEAN;
  BEGIN
    ASSERT (p. isOpen);
    RETURN (p. inputBuffer # NIL) & (p. inputStart # p. inputSize)
  END CanRead;

PROCEDURE (p: Port) CanWrite*(): BOOLEAN;
  BEGIN
    ASSERT (p. isOpen);
    RETURN (p. outputStart # p. outputEnd)
  END CanWrite;

PROCEDURE (p: Port) Open* (VAR res: Msg.Msg);
  BEGIN
    p. Open^ (res);
    p. outputStart := 0;
    p. outputEnd := 0;
  END Open;

PROCEDURE (p: Port) Close* (reason: Msg.Msg; VAR res: Msg.Msg);
  BEGIN
    p. Close^ (reason, res);
    p. inputStart := 0;
  END Close;
  
PROCEDURE (p: Port) UsedOutputCapacity*(): LONGINT;
  VAR
    used: LONGINT;
  BEGIN
    used := p. outputEnd-p. outputStart;
    IF (used < 0) THEN
      INC (used, LEN (p. outputBuffer^))
    END;
    RETURN used
  END UsedOutputCapacity;

PROCEDURE (p: Port) OutputCapacityLeft*(): LONGINT;
  BEGIN
    RETURN p. outputSize-p. UsedOutputCapacity()
  END OutputCapacityLeft;

PROCEDURE (p: Port) SetOutputBuffer* (size, alertLevel: LONGINT);
  VAR
    buffer: Port0.Buffer;
    len: LONGINT;
  BEGIN
    <* PUSH; IndexCheck := FALSE *>
    (* note: the following code may include MOVE operations with a length
       of zero that "start" at x[LEN(x)]; because these zero-MOVEs are in fact
       noops, they are in fact legal; nevertheless, they trigger an "index out
       of range" exception, unless the index checks are disabled by the above 
       pragma statement *)
       
    IF (size # -1) THEN
      ASSERT (size >= p. outputSize);

      NEW (buffer, size+8);
      IF (p. outputBuffer # NIL) THEN
        IF (p. outputStart <= p. outputEnd) THEN
          SYSTEM.MOVE (SYSTEM.ADR (p. outputBuffer[p. outputStart]),
                       SYSTEM.ADR (buffer^), p. outputEnd-p. outputStart);
        ELSE
          len := LEN (p. outputBuffer^)-p. outputStart;
          SYSTEM.MOVE (SYSTEM.ADR (p. outputBuffer[p. outputStart]),
                       SYSTEM.ADR (buffer^), len);
          SYSTEM.MOVE (SYSTEM.ADR (p. outputBuffer^),
                       SYSTEM.ADR (buffer[len]), p. outputEnd)
        END;
        p. outputEnd := p. UsedOutputCapacity(); p. outputStart := 0
      ELSE
        p. outputStart := 0; p. outputEnd := 0
      END;
      p. outputBuffer := buffer;
      p. outputSize := size;
    ELSE
      ASSERT (alertLevel < size)
    END;
    p. alertLevel := alertLevel
    <* POP *>
  END SetOutputBuffer;

PROCEDURE (p: Port) OutputData* (x[NO_COPY]: ARRAY OF CHAR; start, end: LONGINT);
  VAR
    len: LONGINT;
  BEGIN
    <* PUSH; IndexCheck := FALSE *>  (* see above for explanation *)
    len := end-start;
    IF (p. outputStart <= p. outputEnd) &
         (LEN (p. outputBuffer^)-p. outputEnd >= len) OR
       (p. outputStart > p. outputEnd) &
         (p. outputStart-p. outputEnd >= len) THEN
      (* the whole new data fits nicely at the end of the current data *)
      SYSTEM.MOVE (SYSTEM.ADR (x[start]),
                   SYSTEM.ADR (p. outputBuffer[p. outputEnd]), len);
      INC (p. outputEnd, len)
    ELSE
      (* split new data: attach part to end of buffer, part to beginning *)
      len := LEN (p. outputBuffer^)-p. outputEnd;
      SYSTEM.MOVE (SYSTEM.ADR (x[start]),
                   SYSTEM.ADR (p. outputBuffer[p. outputEnd]), len);
      INC (start, len);
      
      len := end-start;
      SYSTEM.MOVE (SYSTEM.ADR (x[start]), SYSTEM.ADR (p. outputBuffer^), len);
      p. outputEnd := len
    END;
    <* POP *>
  END OutputData;


PROCEDURE (p: Port) SetInputBuffer* (size: LONGINT; inputBuffer: Port0.Buffer; inputStart: LONGINT);
  BEGIN
    p. inputSize := size;
    p. inputBuffer := inputBuffer;
    p. inputStart := inputStart;
  END SetInputBuffer;




PROCEDURE InitTransfer* (t: Transfer);
  BEGIN
    Port0.InitTransfer (t);
    t. port := NIL;
  END InitTransfer;

PROCEDURE (t: Transfer) SetPort* (p: Port0.Port);
  BEGIN
    ASSERT (t. port = NIL);
    ASSERT (p. transfer = NIL);
    
    t. SetPort^ (p);
    IF (p = NIL) THEN
      IF (t. port # NIL) THEN
        t. port. SetOutputBuffer (-1, -1) (* clear alert *) 
      END;
      t. port := NIL
    ELSE
      t. port := p(Port)
    END
  END SetPort;

PROCEDURE (t: Transfer) [ABSTRACT] IncomingData* (b: Port0.Buffer; 
                               start, end: LONGINT; VAR res: Msg.Msg): LONGINT;
(**@precond
   @samp{0 <= start < end <= t.port.inputSize} and 
   @samp{res = Port.done}
   @end precond  *)
  END IncomingData;

PROCEDURE (t: Transfer) OutputNotification* (capacity: LONGINT);
  END OutputNotification;


END IO:Port:Streaming.
