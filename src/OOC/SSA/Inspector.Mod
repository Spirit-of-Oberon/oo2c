MODULE OOC:SSA:Inspector;

IMPORT
  Ascii, IntStr, Log, Strings, ADT:Object, ADT:String, ADT:Dictionary,
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
    id: Object.Object;
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
      
      w. AttrStringLatin1 ("onMouseover", 'hlInstr(getAttribute("href"));hlThis(this)'); 
      w. AttrStringLatin1 ("onMouseout", 'nmInstr(getAttribute("href"));nmThis(this)'); 
      
      w. Write ("(");
      w. WriteLatin1 (id(String.String). array^);
      w. Write (")");
      w. EndTag;  (* a *)
    END Ref;

  PROCEDURE WriteRowClass (count: LONGINT);
    BEGIN
      IF ODD (count) THEN
        w. AttrStringLatin1 ("class", "normal1");
        w. AttrStringLatin1 ("myclass", "normal1");
      ELSE
        w. AttrStringLatin1 ("class", "normal0");
        w. AttrStringLatin1 ("myclass", "normal0");
      END;
    END WriteRowClass;
  
  PROCEDURE WriteInstrList (b: Schedule.Block; VAR count: LONGINT);
    VAR
      proxy: Schedule.InstrProxy;
      instr: SSA.Instr;
      str: ARRAY 128 OF CHAR;
      id: Object.Object;
      opnd: SSA.Opnd;
    BEGIN
      proxy := b. proxyList;
      WHILE (proxy # NIL) DO
        instr := proxy. instr;
        w. StartTag ("tr", FALSE);
        WriteRowClass (count);
        w. StartTag ("td", TRUE);
        w. AttrStringLatin1 ("class", "ssaRes");
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
        w. AttrStringLatin1 ("class", "ssaInstr");
        w. StartTag ("b", TRUE);
        instr. GetOpcodeName (str);
        w. WriteLatin1 (str);
        w. EndTag;  (* b *)
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

  PROCEDURE WriteTarget (dest: Schedule.Jump);
    VAR
      id: Object.Object;
    BEGIN
      w. StartTag ("b", TRUE);
      id := s. resultNames. Get (dest. dest);
      w. WriteLatin1 (id(String.String). array^);
      w. EndTag;  (* b *)
    END WriteTarget;
  
  BEGIN
    w := s. w;
    IF (b # s. root) THEN
      w. EndTag;  (* preceding tbody *)
    END;
    w. StartTag ("tbody", FALSE);
    w. AttrString ("class", "ssaBlock");
    w. StartTag ("tr", FALSE);
    w. StartTag ("td", TRUE);
    w. AttrString ("class", "ssaBlockHead");
    w. AttrInt ("colspan", 2);
    w. StartTag ("b", TRUE);
    id := s. resultNames. Get (b);
    w. WriteLatin1 (id(String.String). array^);
    w. Write (":");
    w. EndTag;  (* b *)
    w. EndTag;  (* td *)
    w. EndTag;  (* tr *)
    count := 0;
    WriteInstrList (b, count);

    w. StartTag ("tr", FALSE);
    WriteRowClass (count);
    w. StartTag ("td", TRUE);
    w. AttrString ("class", "ssaRes");
    w. Write (" ");
    w. EndTag;  (* td *)
    w. StartTag ("td", TRUE);
    WITH b: Schedule.JumpBlock DO
      w. AttrString ("class", "ssaJump");
      w. Write ("goto ");
      WriteTarget (b. jump);
      
    | b: Schedule.BranchBlock DO
      w. AttrString ("class", "ssaBranch");
      w. Write ("if ");
      Ref (b. predicate. arg);
      w. Write (" ");
      IF b. branchOnTrue THEN
        WriteTarget (b. branchTo);
      ELSE
        WriteTarget (b. jump);
      END;
      w. Write (" else ");
      IF b. branchOnTrue THEN
        WriteTarget (b. jump);
      ELSE
        WriteTarget (b. branchTo);
      END;
      
    ELSE  (* ignore *)
    END;
    w. EndTag;  (* td *)
    w. EndTag;  (* tr *)
    
    child := b. domList;
    WHILE (child # NIL) DO
      WriteBlocks (s, child);
      child := child. nextDom
    END;
  END WriteBlocks;

PROCEDURE AssignNames (dict: Dictionary.Dictionary; b: Schedule.Block;
                       VAR count, blockCount: LONGINT);
  VAR
    child: Schedule.Block;
    proxy: Schedule.InstrProxy;
    str, substr: ARRAY 64 OF CHAR;
    subcount: LONGINT;
    res: SSA.Result;
  BEGIN
    IntStr.IntToStr (blockCount, str);
    Strings.Insert ("B", 0, str);
    IF b. isLoopHead THEN
      Strings.Insert ("LOOP_", 0, str);
    END;
    dict. Set (b, String.New (str));
    INC (blockCount);
    
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
      AssignNames (dict, child, count, blockCount);
      child := child. nextDom
    END;
  END AssignNames;

PROCEDURE (s: Servlet) DoGET* (req: Server.Request; resp: Server.Response);
  VAR
    w: Writer.Writer;
    uriString: ARRAY 256 OF CHAR;
    count, blockCount: LONGINT;
  BEGIN
    s. resultNames := Dictionary.New();
    count := 1; blockCount := 1;
    AssignNames (s. resultNames, s. root, count, blockCount);
                        
    resp. SetStatus (HTTP.scOk);
    resp. SetHeader (String.New ("Content-Type"), String.New ("text/html"));
    w := Writer.New (resp. GetWriter(), Latin1.factory, FALSE, 2);
    s. w := w;

    
    w. SetEmptyElementHTML (TRUE);
    w. Write8 ('<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Strict//EN">'+
               Ascii.lf);
    w. StartTag ("html", FALSE);
    w. StartTag ("head", FALSE);
    (* w. StartTag ("link", FALSE);
       w. AttrString ("rel", "stylesheet");
       w. AttrString ("type", "text/css");
       w. AttrString ("href", "/inspector.css");
       w. EndTag;*)
    w. StartTag ("style", TRUE);
    w. AttrString ("type", "text/css");
    w. Write ("body { background-color: white; font-family: sans-serif }");
    w. Write ("table.ssaCode { border-collapse: collapse; border-width: thin; border-style: solid; border-color: black }");
    w. Write (".ssaBlock { }");
    w. Write ("td.ssaBlockHead { border-style: solid; border-top-width: medium; border-bottom-width: medium }");
    w. Write ("td.ssaRes { text-align: right; }");
    w. Write ("td.ssaInstr { text-align: left; }");
    w. Write ("td.ssaJump { border-style: dashed; border-width: 0; border-top-width: thin; }");
    w. Write ("td.ssaBranch { border-style: dashed; border-width: 0; border-top-width: thin; }");
    w. Write ("tr.normal0 { background-color:#DDDDDD }");
    w. Write ("tr.normal1 { background-color:#BBBBFF }");
    w. Write (".highlight { background-color:#FF9999 }");
    w. EndTag;  (* style *)
    w. StartTag ("script", TRUE);
    w. AttrString ("type", "text/javascript");

    (* highlight instruction given a "href" to one of its results *)
    w. Write ('function hlInstr(href) {document.getElementById(href.slice(1).split(".")[0]).parentNode.parentNode.className = "highlight"}');
    w. Write ('function nmInstr(href) {with(document.getElementById(href.slice(1).split(".")[0]).parentNode.parentNode) {className = getAttribute("myclass")}}');
    (* highlight the current anchor *)
    w. Write ('function hlThis(e) {e.className = "highlight"}');
    w. Write ('function nmThis(e) {e.className = e.parentNode.className}');
    
    w. EndTag;  (* script *)

    w. StartTag ("title", TRUE);
    w. Write ("SSA Code Inspector");
    w. EndTag;  (* title *)
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
      w. AttrString ("class", "ssaCode");
      WriteBlocks (s, s. root);
      w. EndTag;  (* last tbody *)
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
