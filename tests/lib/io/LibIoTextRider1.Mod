MODULE LibIoTextRider1;

IMPORT Ascii,IO,IO:Buffer,IO:FileChannel,IO:TextRider,Out:=Out0;

PROCEDURE Test*() RAISES IO.Error;

VAR
  file   : Buffer.Channel;
  reader : TextRider.Reader;
  buffer : ARRAY 1024 OF CHAR;
  small  : ARRAY 5 OF CHAR;
  int    : LONGINT;
  char   : CHAR;

BEGIN
  Out.String("Opening test file...");Out.Ln;
  file:=FileChannel.Open("io/LibIoTextRider1.data",{FileChannel.read});

  Out.String("Test file opened.");Out.Ln;

  reader:=TextRider.ConnectReader(file);

  reader.ReadIdentifier(buffer);
  ASSERT(buffer="Identifier");

  (* Simple number *)
  reader.ReadLInt(int);
  ASSERT(int=4711);

  (* Longer number *)
  reader.ReadLInt(int);
  ASSERT(int=47114711);

  (* And shorter number again (check for correct buffer fill/size *)
  reader.ReadLInt(int);
  ASSERT(int=4711);

  (* Positive number *)
  reader.ReadLInt(int);
  ASSERT(int=4711);

  (* Negative *)
  reader.ReadLInt(int);
  ASSERT(int=-4711);

  (* Consume line end *)
  reader.ReadLine(buffer); (* Read rest of line *)

  (* read full line with text *)
  reader.ReadLine(buffer);
  ASSERT(buffer="Smart little line");

  (* Read empty line *)
  reader.ReadLine(buffer);
  ASSERT(buffer="");

  (* Positive number and trailing text in same line *)
  reader.ReadLInt(int);
  reader.ReadLine(buffer);
  ASSERT(int=4711);
  ASSERT(buffer="I'm the trailing stuff");

  (* Read two empty lines followd by a text *)
  reader.ReadLine(buffer);
  ASSERT(buffer="");
  reader.ReadLine(buffer);
  ASSERT(buffer="");
  reader.ReadLine(buffer);
  ASSERT(buffer="Bla");

  (* List of integers over a number of lines *)
  reader.ReadLInt(int);
  ASSERT(int=12);
  reader.ReadLInt(int);
  ASSERT(int=13);
  reader.ReadLInt(int);
  ASSERT(int=14);
  reader.ReadLInt(int);
  ASSERT(int=15);

  (* Hex number testing *)
  reader.ReadHex(int);
  ASSERT(int=10);
  reader.ReadHex(int);
  ASSERT(int=255);
  reader.ReadHex(int);
  ASSERT(int=65535);
  reader.ReadHex(int);
  ASSERT(int=-2147483648);
  reader.ReadHex(int);
  ASSERT(int=-1);

  (* Reading a string *)
  reader.ReadString(buffer);
  ASSERT(buffer="Hallo!");

  (* Now trying to read a string where there is no one *)
  TRY
    reader.ReadString(buffer);
    ASSERT(FALSE);
  CATCH IO.FormatError:
  END;

  (* Now trying to read a hex where there is no one *)
  TRY
    reader.ReadHex(int);
    ASSERT(FALSE);
  CATCH IO.FormatError:
  END;

  (* Now trying to read a int where there is no one *)
  TRY
    reader.ReadLInt(int);
    ASSERT(FALSE);
  CATCH IO.FormatError:
  END;

  (* Read a character & sync with text *)
  reader.ReadChar(char);
  ASSERT(char="x");

  (* Now test ReadChar in general *)
  reader.ReadChar(char);
  ASSERT(char="y");

  reader.ReadChar(char);
  ASSERT(char="z");

  reader.ReadChar(char);
  ASSERT(char=Ascii.lf);

  reader.ReadChar(char);
  ASSERT(char="a");

  reader.ReadChar(char);
  ASSERT(char=Ascii.lf);

  reader.ReadChar(char);
  ASSERT(char=Ascii.lf);

  reader.ReadChar(char);
  ASSERT(char="b");

  (* Overflow exception while reading integer *)
  TRY
    reader.ReadLInt(int);
    ASSERT(FALSE);
  CATCH TextRider.OverflowError:
  END;

  (* Format exception while reading integer *)
  TRY
    reader.ReadLInt(int);
    ASSERT(FALSE);
  CATCH IO.FormatError:
  END;

  (* Overflow exception while reading big string *)
  TRY
    reader.ReadString(small);
    ASSERT(FALSE);
  CATCH TextRider.OverflowError:
  END;

  (* resync with text *)
  reader.ReadLn;

  (* Read correct string with alternate quoting *)
  reader.ReadString(buffer);
  ASSERT(buffer="Blub");

  (* Reading unterminated string *)
  TRY
    reader.ReadString(buffer);
    ASSERT(FALSE);
  CATCH IO.FormatError:
  END;

  (* Don't return Ascii.lf if line does not contain one *)
  TRY
    reader.ReadChar(char);
    ASSERT(FALSE);
  CATCH IO.ProtocolError:
  END;

  (* Do it again, because ReadLineBuffer is called and changes some parameter *)
  TRY
    reader.ReadChar(char);
    ASSERT(FALSE);
  CATCH IO.ProtocolError:
  END;

  (* Now try to read beyond file end *)
  TRY
    reader.ReadLInt(int);
    ASSERT(FALSE);
  CATCH IO.ProtocolError:
  END;

  Out.String("Closing test file...");Out.Ln;
  file.Close;
  Out.String("Closed.");Out.Ln;
END Test;
END LibIoTextRider1.