MODULE Config:Source [OOC_EXTENSIONS];

IMPORT
  Channel, Msg, Config:Parser;


TYPE
  Source* = POINTER TO SourceDesc;
  SourceDesc* = RECORD [ABSTRACT]
    
  END;

PROCEDURE Init* (src: Source);
  BEGIN
    
  END Init;

PROCEDURE (source: Source) [ABSTRACT] Write* (ch: Channel.Channel;
                                              rootTag: Parser.String;
                                              VAR res: Msg.Msg);
  END Write;
  
END Config:Source.
