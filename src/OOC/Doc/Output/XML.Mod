MODULE OOC:Doc:Output:XML;

IMPORT
  Channel, Strings, Object, ADT:Dictionary,
  XML:Writer, XML:UnicodeCodec:Latin1,
  OOC:Config:Repositories, OOC:Repository, OOC:Doc, Sym := OOC:SymbolTable;
  
PROCEDURE WriteOberonDoc* (w: Writer.Writer; document: Doc.Document;
                           localModule: Sym.Module;
                           rewriteMap: Dictionary.Dictionary;
                           repositories: Repositories.Section;
                           moduleDict: Dictionary.Dictionary);
(**Writes the description @oparam{document} to the writer @oparam{w}.
   References to objects whose defining module equals @oparam{localModule} are
   treated as local, and their @samp{href} attribute prefix is the empty
   string.

   If @oparam{rewriteMap} is not @code{NIL}, then all reference commands
   targeting a key of @oparam{rewriteMap} are rewritten to point to the
   corresponding dictionary value instead.  This is used to change references
   to parameters if a type-bound procedure inherits its description from one of
   its base types.

   If @oparam{moduleDict} is not @code{NIL}, then the instances of
   @otype{Repository.Module} appearing in the generated output are added as
   keys to the dictionary @oparam{moduleDict}.

   The module locations of reference commands are resolved using the
   configuration data in @oparam{repositories}.  If @oparam{repositories} is
   @code{NIL}, or if a module name can not be resolved, no entry is added to
   @oparam{moduleDict}, and any hyperlinks to this module will not work.  *)

  PROCEDURE AttrExternalHref (module, id: Sym.NameString);
    VAR
      str: ARRAY 2*1024 OF CHAR;
      repModule: Repository.Module;
    BEGIN
      IF (localModule # NIL) & (localModule. name. str^ = module^) THEN
        COPY ("", str)
      ELSE
        IF (moduleDict # NIL) & (repositories # NIL) THEN
          repModule := repositories. GetModule (module^);
          IF (repModule # NIL) THEN
            moduleDict. Set (repModule, NIL)
          END
        END;
        COPY (module^, str)
      END;
      Strings.Append ("#", str);
      Strings.Append (id^, str);
      w. AttrStringLatin1 ("href", str)
    END AttrExternalHref;
  
  PROCEDURE AttrHref (target: Sym.Declaration);
    VAR
      module: Sym.Module;
    BEGIN
      module := target. Module();
      AttrExternalHref (module. name. str, target. GetId())
    END AttrHref;
  
  PROCEDURE InlineList (inlineList: Doc.InlineElement);
    VAR
      inline: Doc.InlineElement;
      rewrittenTo: Object.Object;
      name: ARRAY 32 OF CHAR;
    
    PROCEDURE AsteriskPrefix (VAR str: ARRAY OF CHAR): LONGINT;
      VAR
        i: LONGINT;
      BEGIN
        i := 0;
        WHILE (str[i] # 0X) & (str[i] <= " ") DO
          INC (i)
        END;
        IF (str[i] = "*") THEN
          RETURN i+1
        ELSE
          RETURN -1
        END
      END AsteriskPrefix;
    
    BEGIN
      inline := inlineList;
      WHILE (inline # NIL) DO
        inline. NodeName (name);
        IF ~(inline IS Doc.Text) THEN
          w. StartTagLatin1 (name, TRUE)
        END;
        WITH inline: Doc.Glyph DO
          (* empty element *)
        
        | inline: Doc.OberonRef DO
          rewrittenTo := NIL;
          IF (inline. target # NIL) THEN
            IF (rewriteMap # NIL) & rewriteMap. HasKey (inline. target) THEN
              (* rewrite reference to another declaration *)
              rewrittenTo := rewriteMap. Get (inline. target);
              AttrHref (rewrittenTo(Sym.Declaration))
            ELSE
              AttrHref (inline. target(Sym.Declaration))
            END
          ELSIF (inline. externalModule # NIL) THEN
            AttrExternalHref (inline. externalModule, inline. externalId)
          END;
          
          IF (rewrittenTo # NIL) THEN
            w. WriteLatin1 (rewrittenTo(Sym.Declaration). name. str^)
          ELSIF (inline. inlineText # NIL) &
              (inline. inlineText IS Doc.Text) &
             (AsteriskPrefix (inline. inlineText(Doc.Text). string^) >= 0) THEN
            (* remove "*" and any whitespace before it from the output *)
            w. WriteLatin1I (inline. inlineText(Doc.Text). string^,
                        AsteriskPrefix (inline. inlineText(Doc.Text). string^),
                        Strings.Length (inline. inlineText(Doc.Text). string^))
          ELSE
            InlineList (inline. inlineText)
          END
        
        | inline: Doc.MarkedInline DO
          InlineList (inline. inlineText)

        | inline: Doc.Text DO
          w. WriteLatin1 (inline. string^)

        | inline: Doc.Uref DO
          w. StartTag ("uref-url", TRUE);
          InlineList (inline. url);
          w. EndTag;
          IF (inline. text # NIL) THEN
            w. StartTag ("uref-text", TRUE);
            InlineList (inline. text);
            w. EndTag
          END;
          IF (inline. replacement # NIL) THEN
            w. StartTag ("uref-replacement", TRUE);
            InlineList (inline. replacement);
            w. EndTag
          END
          
        | inline: Doc.Email DO
          w. StartTag ("email-address", TRUE);
          InlineList (inline. address);
          w. EndTag;
          IF (inline. displayed # NIL) THEN
            w. StartTag ("email-displayed-text", TRUE);
            InlineList (inline. displayed);
            w. EndTag
          END;
        END;
        IF ~(inline IS Doc.Text) THEN
          w. EndTag
        END;
        inline := inline. nextInline
      END
    END InlineList;

  PROCEDURE BlockList (blockList: Doc.BlockElement);
    VAR
      block: Doc.BlockElement;
      name: ARRAY 32 OF CHAR;
    BEGIN
      block := blockList;
      WHILE (block # NIL) DO
        block. NodeName (name);
        w. StartTagLatin1 (name, (block IS Doc.Paragraph) OR
                                 (block IS Doc.Example) OR
                                 (block IS Doc.FirstColumn));
        w. AttrBool ("pad-after", block. padAfter);
        WITH block: Doc.Paragraph DO
          w. AttrBool ("no-indent", block. noIndent);
          InlineList (block. inlineText)

        | block: Doc.Example DO
          InlineList (block. inlineText)

        | block: Doc.PreCond DO
          BlockList (block. blockList)

        | block: Doc.PostCond DO
          BlockList (block. blockList)

        | block: Doc.Item DO
          BlockList (block. blockList)

        | block: Doc.Itemize DO
          w. StartTag ("itemize-mark", TRUE);
          InlineList (block. mark);
          w. EndTag;
          IF (block. text # NIL) THEN
            w. StartTag ("itemize-text", FALSE);
            BlockList (block. text. blockList);
            w. EndTag
          END;
          BlockList (block. itemList)

        | block: Doc.FirstColumn DO
          InlineList (block. inlineText)

        | block: Doc.TableRow DO
          BlockList (block. firstColumnList);
          BlockList (block. item)

        | block: Doc.Table DO
          BlockList (block. rowList)
        END;
        w. EndTag;
        block := block. nextBlock
      END
    END BlockList;

  BEGIN
    w. StartTag ("oberon-doc", FALSE);
    IF (document. summary # NIL) THEN
      w. StartTag ("summary", TRUE);
      InlineList (document. summary);
      w. EndTag
    END;
    BlockList (document. blockList);
    w. EndTag
  END WriteOberonDoc;

PROCEDURE Write* (cw: Channel.Writer; document: Doc.Document;
                  localModule: Sym.Module;
                  rewriteMap: Dictionary.Dictionary;
                  repositories: Repositories.Section;
                  moduleDict: Dictionary.Dictionary);
  VAR
    w: Writer.Writer;
  BEGIN
    w := Writer.New (cw, Latin1.factory, TRUE, 2);
    w. WriteTextDecl ("1.0", "yes");
    WriteOberonDoc (w, document, localModule, rewriteMap,
                    repositories, moduleDict);
    w. EndOfText
  END Write;
  
END OOC:Doc:Output:XML.
