MODULE LibUri;

IMPORT
  TextRider, Out, StdChannels, Strings,
  
  URI:Authority:RegistryBased,
  URI:Authority:ServerBased,
  AuthorityUnparsed := URI:Authority:Unparsed,
  URI:CharClass,
  URI:Error,
  URI:Parser,
  URI:String,
  FragmentUnparsed := URI:Fragment:Unparsed,
  QueryUnparsed := URI:Query:Unparsed,
  URI:Scheme:CurrentDoc,
  URI:Scheme:File,
  URI:Scheme:HTTP,
  URI:Scheme:Hierarchical,
  URI:Scheme:MailTo,
  URI:Scheme:Opaque,
  URI;

PROCEDURE RegisterSchemes;
  BEGIN
    URI.RegisterScheme (File.NewPrototype());
(*    URI.RegisterScheme (HTTP.NewPrototype());*)
    URI.RegisterScheme (MailTo.NewPrototype());
  END RegisterSchemes;

PROCEDURE WriteQuotedI (w: TextRider.Writer; str: ARRAY OF CHAR; s, e: LONGINT);
  VAR
    last: LONGINT;
  BEGIN
    WHILE (s # e) DO
      last := s;
      WHILE (s # e) &
            (str[s] # "&") & (str[s] # "<") & (str[s] # ">") & 
            (str[s] # 09X) & (str[s] # 0AX) & (str[s] # 0DX) DO
        INC (s)
      END;
      w. byteWriter. WriteBytes (str, last, s-last);
      IF (s # e) THEN
        CASE str[s] OF
        | "&": w. WriteString ("&amp;")
        | "<": w. WriteString ("&lt;")
        | ">": w. WriteString ("&gt;")
        | 09X: w. WriteString ("&#9;")
        | 0AX: w. WriteString ("&#10;")
        | 0DX: w. WriteString ("&#13;")
        END;
        INC (s)
      END
    END
  END WriteQuotedI;

PROCEDURE WriteQuoted (w: TextRider.Writer; str: ARRAY OF CHAR);
  BEGIN
    WriteQuotedI (w, str, 0, Strings.Length (str))
  END WriteQuoted;

PROCEDURE Write* (str: ARRAY OF CHAR);
  VAR
    res: Error.Msg;
    msgText: ARRAY 1024 OF CHAR;
    uri: URI.URI;
    ref: URI.Reference;
    w: TextRider.Writer;
  BEGIN
    uri := Parser.NewURI (str, NIL, res);
    IF (res = NIL) THEN
      w := TextRider.ConnectWriter (StdChannels.stdout);
      w. WriteString ("<test-parse-uri>");
      w. WriteString ("<uri-string>");
      uri. GetString (str);
      WriteQuoted (w, str);
      w. WriteString ("</uri-string>");
      w. WriteLn;
      uri. WriteXML (w);
      w. WriteLn;
      w. WriteString ("</test-parse-uri>");
      w. WriteLn
    ELSE
      res. GetText (msgText);
      Out.String ("Error: ");
      Out.String (msgText);
      Out.Ln;
    END
  END Write;

PROCEDURE Test* ();
  BEGIN
  END Test;

BEGIN
  RegisterSchemes;
END LibUri.
