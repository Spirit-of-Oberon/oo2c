MODULE Config:Source [OOC_EXTENSIONS];

IMPORT
  IO, Config:Parser;


TYPE
  Source* = POINTER TO SourceDesc;
  SourceDesc* = RECORD [ABSTRACT]
    
  END;

PROCEDURE Init* (src: Source);
  BEGIN
    
  END Init;

PROCEDURE (source: Source) [ABSTRACT] Write* (ch: IO.ByteChannel;
                                              rootTag: Parser.String)
RAISES IO.Error;
  END Write;
  
END Config:Source.
