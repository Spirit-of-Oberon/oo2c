MODULE OOC:SSA:Inspector;

IMPORT
  IntStr, Log, Strings, ADT:Object, ADT:String, ADT:Dictionary,
  XML:Writer, XML:UnicodeCodec:Latin1,
  OOC:Config:Repositories, OOC:IR, OOC:SSA, OOC:SSA:Schedule,
  OOC:Auxiliary:HTTPServer, Net:HTTP, Net:HTTP:Server;

TYPE
  Servlet* = POINTER TO ServletDesc;
  ServletDesc = RECORD
    (HTTPServer.ServletDesc)
    proc: IR.Procedure;
    root: Schedule.Block;
    w: Writer.Writer;
    resultNames: Dictionary.Dictionary;
    repositories: Repositories.Section;
  END;

VAR
  repositories*: Repositories.Section;

  
PROCEDURE NewServlet (repositories: Repositories.Section;
                      proc: IR.Procedure; root: Schedule.Block): Servlet;
  VAR
    s: Servlet;
  BEGIN
    NEW (s);
    HTTPServer.InitServlet (s);
    s. proc := proc;
    s. root := root;
    s. repositories := repositories;
    RETURN s
  END NewServlet;

PROCEDURE WriteBlocks (s: Servlet; b: Schedule.Block);
  VAR
    w: Writer.Writer;
    child: Schedule.Block;

  PROCEDURE WriteInstrList (b: Schedule.Block);
    VAR
      proxy: Schedule.InstrProxy;
      instr: SSA.Instr;
      str: ARRAY 128 OF CHAR;
      id: Object.Object;
      opnd: SSA.Opnd;
      count: LONGINT;

    PROCEDURE Ref (res: SSA.Result);
      VAR
        id: Object.Object;
        str: ARRAY 128 OF CHAR;
      BEGIN
        id := s. resultNames. Get (res);
        str := "#res_";
        Strings.Append (id(String.String). array^, str);
        w. StartTag ("a", TRUE);
        w. AttrStringLatin1 ("href", str);

        w. AttrStringLatin1 ("onMouseover", 'hlInstr(getAttribute("href"))'); 
        w. AttrStringLatin1 ("onMouseout", 'nmInstr(getAttribute("href"))'); 

        w. Write ("(");
        w. WriteLatin1 (id(String.String). array^);
        w. Write (")");
        w. EndTag;  (* a *)
      END Ref;
    
    BEGIN
      count := 0;
      proxy := b. proxyList;
      WHILE (proxy # NIL) DO
        instr := proxy. instr;
        w. StartTag ("tr", FALSE);
        IF ODD (count) THEN
          w. AttrStringLatin1 ("class", "normal1");
          w. AttrStringLatin1 ("myclass", "normal1");
        ELSE
          w. AttrStringLatin1 ("class", "normal0");
          w. AttrStringLatin1 ("myclass", "normal0");
        END;
        w. StartTag ("td", TRUE);
        id := s. resultNames. Get (instr);
        str := "res_";
        Strings.Append (id(String.String). array^, str);
        w. StartTag ("a", TRUE);
        w. AttrStringLatin1 ("id", str);
        w. Write ("(");
        w. WriteLatin1 (id(String.String). array^);
        w. Write (")");
        w. EndTag;  (* a *)
        w. EndTag;  (* td *)
        
        w. StartTag ("td", TRUE);
        instr. GetOpcodeName (str);
        w. WriteLatin1 (str);
        w. Write (" ");
        opnd := instr. opndList;
        WHILE (opnd # NIL) DO
          IF (opnd # instr. opndList) THEN
            w. Write (", ");
          END;
          Ref (opnd. arg);
          opnd := opnd. nextOpnd
        END;
        w. EndTag;  (* td *)
        w. EndTag;  (* tr *)
        
        INC (count);
        proxy := proxy. nextProxy
      END;
    END WriteInstrList;
  
  BEGIN
    w := s. w;
    w. StartTag ("tr", FALSE);
    w. StartTag ("td", TRUE);
    w. Write ("block");
    w. EndTag;  (* td *)
    w. EndTag;  (* tr *)
    WriteInstrList (b);
    
    child := b. domList;
    WHILE (child # NIL) DO
      WriteBlocks (s, child);
      child := child. nextDom
    END;
  END WriteBlocks;

PROCEDURE AssignNames (dict: Dictionary.Dictionary; b: Schedule.Block;
                       count: LONGINT): LONGINT;
  VAR
    child: Schedule.Block;
    proxy: Schedule.InstrProxy;
    str, substr: ARRAY 64 OF CHAR;
    subcount: LONGINT;
    res: SSA.Result;
  BEGIN
    proxy := b. proxyList;
    WHILE (proxy # NIL) DO
      subcount := 0;
      res := proxy. instr;
      WHILE (res # NIL) DO
        IntStr.IntToStr (count, str);
        IF (subcount # 0) THEN
          IntStr.IntToStr (subcount, substr);
          Strings.Append (".", str);
          Strings.Append (substr, str);
        END;
        INC (subcount);
        dict. Set (res, String.New (str));
        res := res. nextResult
      END;
      
      INC (count);
      proxy := proxy. nextProxy
    END;
    
    child := b. domList;
    WHILE (child # NIL) DO
      count := AssignNames (dict, child, count);
      child := child. nextDom
    END;
    RETURN count
  END AssignNames;

PROCEDURE (s: Servlet) DoGET* (req: Server.Request; resp: Server.Response);
  VAR
    w: Writer.Writer;
    uriString: ARRAY 256 OF CHAR;
    count: LONGINT;
  BEGIN
    s. resultNames := Dictionary.New();
    count := AssignNames (s. resultNames, s. root, 1);
                        
    resp. SetStatus (HTTP.scOk);
    resp. SetHeader (String.New ("Content-Type"), String.New ("text/html"));
    w := Writer.New (resp. GetWriter(), Latin1.factory, FALSE, 2);
    s. w := w;

    w. SetEmptyElementHTML (TRUE);
    w. StartTag ("html", FALSE);
    w. StartTag ("head", FALSE);
    (* w. StartTag ("link", FALSE);
       w. AttrString ("rel", "stylesheet");
       w. AttrString ("type", "text/css");
       w. AttrString ("href", "/inspector.css");
       w. EndTag;*)
    w. StartTag ("style", TRUE);
    w. Write ("tr.normal0 { background-color:#DDDDDD }");
    w. Write ("tr.normal1 { background-color:#BBBBBB }");
    w. Write ("tr.highlight { background-color:#FF9999 }");
    w. EndTag;  (* style *)
    w. StartTag ("script", TRUE);
    w. AttrString ("type", "text/javascript");
    w. Write ('function hlInstr(href) {document.getElementById(href.slice(1).split(".")[0]).parentNode.parentNode.className = "highlight"}');
    w. Write ('function nmInstr(href) {with(document.getElementById(href.slice(1).split(".")[0]).parentNode.parentNode) {className = getAttribute("myclass")}}');
    w. EndTag;  (* script *)
    w. EndTag;  (* head *)
    
    w. StartTag ("body", FALSE);
    req. uri. GetString (uriString);
    Log.Msg (uriString);
    IF (uriString = "http:/exit") THEN
      w. StartTag ("p", TRUE);
      w. WriteLatin1 ("Bye!");
      s. SetExitFlag;
      w. EndTag;  (* p *)
    ELSE
      w. StartTag ("p", TRUE);
      w. WriteLatin1 (s. proc. decl. name. str^);
      w. WriteLatin1 (" [");
      w. StartTag ("a", TRUE);
      w. AttrString ("href", "/exit");
      w. WriteLatin1 ("exit");
      w. EndTag;  (* a *)
      w. WriteLatin1 ("]");
      w. EndTag;  (* p *)

      w. StartTag ("table", FALSE);
      WriteBlocks (s, s. root);
      w. EndTag;  (* table *)
    END;
    
    w. EndTag;  (* body *)
    w. EndTag;  (* html *)
    w. EndOfText
  END DoGET;

PROCEDURE Show* (proc: IR.Procedure; root: Schedule.Block);
  BEGIN
    HTTPServer.Run (NewServlet (repositories, proc, root))
  END Show;

BEGIN
  repositories := NIL;
END OOC:SSA:Inspector.
