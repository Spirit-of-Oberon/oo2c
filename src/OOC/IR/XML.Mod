MODULE OOC:IR:XML;

IMPORT
  Channel, XML:Writer, XML:UnicodeCodec:Latin1, OOC:IR;



TYPE
  Visitor = POINTER TO VisitorDesc;
  VisitorDesc = RECORD
    (IR.VisitorDesc)
    w: Writer.Writer;
  END;


PROCEDURE InitVisitor (v: Visitor; w: Writer.Writer);
  BEGIN
    IR.InitVisitor (v);
    v. w := w;
  END InitVisitor;

PROCEDURE NewVisitor (w: Writer.Writer): Visitor;
  VAR
    v: Visitor;
  BEGIN
    NEW (v);
    InitVisitor (v, w);
    RETURN v
  END NewVisitor;

PROCEDURE (v: Visitor) VisitModule* (module: IR.Module);
  BEGIN
    v. w. StartTag ("module", FALSE);
    v. w. AttrStringLatin1 ("name", module. name^);
    v. w. EndTag;  (* module *)
  END VisitModule;


PROCEDURE Write* (cw: Channel.Writer; module: IR.Module);
  VAR
    w: Writer.Writer;
    v: Visitor;
  BEGIN
    w := Writer.New (cw, Latin1.factory, TRUE, 2);
    w. WriteTextDecl ("1.0", "yes");
    
    v := NewVisitor (w);
    module. Accept (v);
    
    w. EndOfText
  END Write;
  
END OOC:IR:XML.
