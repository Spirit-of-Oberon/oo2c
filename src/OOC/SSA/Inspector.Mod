MODULE OOC:SSA:Inspector;

IMPORT
  Ascii, Channel, Files, IntStr, Log, Msg, Strings,
  ADT:Object, ADT:String, ADT:Dictionary,
  Language, Language:Boolean, Language:String8,
  Language:Integer, Language:Set,
  URI, URI:Scheme:File, XML:Writer, XML:UnicodeCodec:Latin1,
  OOC:Config:Repositories, OOC:IR, OOC:SSA, OOC:SSA:Schedule,
  OOC:SSA:Opcode, OOC:SSA:Result, OOC:SSA:Opnd,
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

PROCEDURE OmitInstr (instr: SSA.Instr): BOOLEAN;
  BEGIN
    WITH instr: SSA.DeclRef DO
      RETURN TRUE;
    | instr: SSA.Const DO
      RETURN TRUE;
    | instr: SSA.Address DO
      RETURN (instr. opcode # Opcode.copyParameter);
    ELSE
      RETURN FALSE;
    END;
  END OmitInstr;

PROCEDURE WriteBlock (s: Servlet; b: Schedule.Block);
  VAR
    w: Writer.Writer;
    id: Object.Object;
    count: LONGINT;

  PROCEDURE Ref (opnd: SSA.Opnd);
    VAR
      id: Object.Object;
      str: ARRAY 128 OF CHAR;
      arg: SSA.Result;
      
    PROCEDURE WriteConst (value: Language.Value);
      VAR
        str: String.String;
      BEGIN
        WITH value: Boolean.Value DO
          IF value. value THEN
            w. WriteLatin1("TRUE")
          ELSE
            w. WriteLatin1("FALSE")
          END
        | value: String8.Value DO
          w. Write ('"');
          w. WriteLatin1 (value. value. array^);
          w. Write ('"');
        | value: Integer.Value DO
          str := value.ToString();
          w. WriteLatin1(str.array^);
        | value: Set.Value DO
          (* FIXME *)
          w. WriteLatin1("{set const}");
        END
      END WriteConst;
    
    BEGIN
      w. StartTag ("span", TRUE);
      Opnd.GetName (opnd. class, str);
      w. AttrStringLatin1 ("title", str);
      
      arg := opnd. arg;
      WITH arg: SSA.DeclRef DO
        w. WriteLatin1 (arg. decl. name. str^);
      | arg: SSA.Const DO
        WriteConst (arg. value);
      | arg: SSA.Address DO
        w. Write ("&");
        w. WriteLatin1 (arg. decl. name. str^);
      ELSE
        w. StartTag ("a", TRUE);
        w. AttrString ("class", "resRef");
        id := s. resultNames. Get (arg);
        str := "#res_";
        Strings.Append (id(String.String). array^, str);
        w. AttrStringLatin1 ("href", str);
        
        w. AttrStringLatin1 ("onMouseover", 'hlInstr(getAttribute("href"))'); 
        w. AttrStringLatin1 ("onMouseout", 'nmInstr(getAttribute("href"))'); 
        
        w. Write ("(");
        w. WriteLatin1 (id(String.String). array^);
        w. Write (")");
        w. EndTag;  (* a *)
      END;

      w. EndTag;  (* span *)
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
      res: SSA.Result;
      str: ARRAY 128 OF CHAR;
      id: Object.Object;
      opnd: SSA.Opnd;

    BEGIN
      proxy := b. proxyList;
      WHILE (proxy # NIL) DO
        instr := proxy. instr;

        IF ~OmitInstr (instr) THEN
          w. StartTag ("tr", FALSE);
          WriteRowClass (count);
          w. StartTag ("td", TRUE);
          w. AttrStringLatin1 ("class", "ssaRes");

          res := instr;
          WHILE (res # NIL) DO
            IF (res # instr) THEN
              w. Write (", ");
            END;
            w. StartTag ("span", TRUE);
            Result.GetName (res. class, str);
            w. AttrStringLatin1 ("title", str);
            
            id := s. resultNames. Get (res);
            str := "res_";
            Strings.Append (id(String.String). array^, str);
            w. StartTag ("a", TRUE);
            w. AttrStringLatin1 ("id", str);
            w. Write ("(");
            w. WriteLatin1 (id(String.String). array^);
            w. Write (")");
            w. EndTag;  (* a *)
            
            w. EndTag;  (* span *)
            res := res. nextResult;
          END;
          w. EndTag;  (* td *)
          
          w. StartTag ("td", TRUE);
          w. AttrStringLatin1 ("class", "ssaInstr");
          w. CloseStartTag;
          w. Write8 (" &larr; ");
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
            Ref (opnd);
            opnd := opnd. nextOpnd
          END;
          w. EndTag;  (* td *)
          w. EndTag;  (* tr *)
          INC (count);
        END;
        proxy := proxy. nextProxy
      END;
    END WriteInstrList;

  PROCEDURE WriteTarget (dest: Schedule.Jump);
    VAR
      id: Object.Object;
      str: ARRAY 64 OF CHAR;
    BEGIN
      id := s. resultNames. Get (dest. dest);
      COPY (id(String.String). array^, str);
      Strings.Insert ("#", 0, str);
      w. StartTag ("a", TRUE);
      w. AttrStringLatin1 ("href", str);
      w. AttrStringLatin1 ("class", "blockRef");
      w. StartTag ("b", TRUE);
      w. WriteLatin1 (id(String.String). array^);
      w. EndTag;  (* b *)
      w. EndTag;  (* a *)
    END WriteTarget;
  
  BEGIN
    w := s. w;
    w. StartTag ("tr", FALSE);
    w. StartTag ("td", TRUE);
    w. AttrString ("class", "ssaBlockHead");
    w. AttrInt ("colspan", 2);
    id := s. resultNames. Get (b);
    w. StartTag ("a", TRUE);
    w. AttrStringLatin1 ("id", id(String.String). array^);
    w. StartTag ("b", TRUE);
    w. WriteLatin1 (id(String.String). array^);
    w. Write (":");
    w. EndTag;  (* b *)
    w. EndTag;  (* a *)
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
      Ref (b. predicate);
      w. Write (" then ");
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
  END WriteBlock;

PROCEDURE WriteBlockList (s: Servlet; b: Schedule.Block);
  PROCEDURE WriteBlocks (b: Schedule.Block);
    VAR
      child: Schedule.Block;
    BEGIN
      WriteBlock (s, b);
      child := b. domList;
      WHILE (child # NIL) DO
        WriteBlocks (child);
        child := child. nextDom
      END;
    END WriteBlocks;
  
  BEGIN
    s. w. StartTag ("table", FALSE);
    s. w. AttrString ("class", "ssaCode");
    WriteBlocks (b);
    s. w. EndTag;  (* table *)
  END WriteBlockList;

PROCEDURE WriteNestedBlocks (s: Servlet; b: Schedule.Block);
  VAR
    w: Writer.Writer;
    
  PROCEDURE WriteBlocks (b: Schedule.Block);
    VAR
      child: Schedule.Block;
    BEGIN
      w. StartTag ("table", FALSE);
      w. AttrString ("class", "ssaCode");
      WriteBlock (s, b);
      child := b. domList;
      WHILE (child # NIL) DO
        w. StartTag ("tr", FALSE);
        w. StartTag ("td", FALSE);
        w. AttrString ("class", "filler");
        w. Write ("");
        w. EndTag;  (* td *)
        w. StartTag ("td", FALSE);
        WriteBlocks (child);
        w. EndTag;  (* td *)
        w. EndTag;  (* tr *)
        child := child. nextDom
      END;
      w. EndTag;  (* table *)
    END WriteBlocks;
  
  BEGIN
    w := s. w;
    WriteBlocks (b);
  END WriteNestedBlocks;

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
      IF ~OmitInstr (proxy. instr) THEN
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
      END;
      
      proxy := proxy. nextProxy
    END;
    
    child := b. domList;
    WHILE (child # NIL) DO
      AssignNames (dict, child, count, blockCount);
      child := child. nextDom
    END;
  END AssignNames;

PROCEDURE ReturnFile (s: Servlet; resp: Server.Response;
                      package, fileName, contentType: ARRAY OF CHAR);
  CONST
    sizeBuffer = 8*1024;
  VAR
    path: ARRAY 1024 OF CHAR;
    buffer: ARRAY sizeBuffer OF CHAR;
    str: ARRAY 32 OF CHAR;
    f: Files.File;
    w: Channel.Writer;
    r: Files.Reader;
    uri: URI.URI;
    res: Msg.Msg;
  BEGIN
    resp. SetStatus (HTTP.scOk);
    resp. SetHeader (String.New ("Content-Type"), String.New (contentType));
    uri := s. repositories. GetResource (package, fileName);
    IF (uri = NIL) THEN
      (* if there is no such file, simply return an empty document *)
      resp. SetHeader (String.New ("Content-Length"), String.New ("0"));
    ELSE
      uri(File.URI). GetPath (path);
      f := Files.Old (path, {Files.read}, res);
      IntStr.IntToStr (f. Length(), str);
      resp. SetHeader (String.New ("Content-Length"), String.New (str));
      w := resp. GetWriter();
      r := f. NewReader();
      WHILE (r. res = Files.done) & (w. res = Files.done) DO
        r. ReadBytes (buffer, 0, sizeBuffer);
        w. WriteBytes (buffer, 0, r. bytesRead);
      END;
      (* ignore any errors *)
    END;
  END ReturnFile;

PROCEDURE (s: Servlet) DoGET* (req: Server.Request; resp: Server.Response);
  VAR
    w: Writer.Writer;
    uriString: ARRAY 256 OF CHAR;
    count, blockCount: LONGINT;
  BEGIN
    req. uri. GetString (uriString);
    Log.Msg (uriString);
    IF (uriString = "http:/inspector.css") THEN
      ReturnFile (s, resp, "OOC", "inspector.css", "text/css");
      RETURN;
    END;
    
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
    w. StartTag ("link", FALSE);
    w. AttrString ("rel", "stylesheet");
    w. AttrString ("type", "text/css");
    w. AttrString ("href", "/inspector.css");
    w. EndTag;
    w. StartTag ("script", TRUE);
    w. AttrString ("type", "text/javascript");

    (* highlight instruction given a "href" to one of its results *)
    w. Write ('function hlInstr(href) {document.getElementById(href.slice(1).split(".")[0]).parentNode.parentNode.parentNode.className = "highlight"}');
    w. Write ('function nmInstr(href) {with(document.getElementById(href.slice(1).split(".")[0]).parentNode.parentNode.parentNode) {className = getAttribute("myclass")}}');
    w. EndTag;  (* script *)

    w. StartTag ("title", TRUE);
    w. Write ("SSA Code Inspector");
    w. EndTag;  (* title *)
    w. EndTag;  (* head *)
    
    w. StartTag ("body", FALSE);
    IF (uriString = "http:/exit") THEN
      w. StartTag ("p", TRUE);
      w. WriteLatin1 ("Bye!");
      s. SetExitFlag;
      w. EndTag;  (* p *)
    ELSE
      IF (uriString = "http:/ssa-dom-tree") THEN
        WriteNestedBlocks (s, s. root);
      ELSIF (uriString = "http:/ssa-list") THEN
        WriteBlockList (s, s. root);
      ELSE
        w. WriteLatin1 (s. proc. decl. name. str^);
        w. Write (": ");
        w. StartTag ("a", TRUE);
        w. AttrString ("href", "ssa-list");
        w. Write ("Block List");
        w. EndTag;  (* a *)
        w. Write (" || ");
        w. StartTag ("a", TRUE);
        w. AttrString ("href", "ssa-dom-tree");
        w. Write ("Dominator Tree");
        w. EndTag;  (* a *)
        w. Write (" || ");
        w. StartTag ("a", TRUE);
        w. AttrString ("href", "exit");
        w. WriteLatin1 ("exit");
        w. EndTag;  (* a *)
      END;
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
