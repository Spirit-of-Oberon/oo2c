MODULE OOC:C:WriteConst;

IMPORT
  TextRider, Language, Language:Boolean, Language:String8;
  
PROCEDURE Write* (w: TextRider.Writer; value: Language.Value);
  CONST
    delim = '"';
    quotedDelim = '\"';
  VAR
    i, len: LONGINT;
  BEGIN
    WITH value: Boolean.Value DO
      IF value. value THEN
        w. WriteString("OOC_TRUE")
      ELSE
        w. WriteString("OOC_FALSE")
      END
      
    | value: String8.Value DO
      w. WriteChar (delim);
      i := 1; len := value. value. length-1;
      WHILE (i # len) DO
        IF (value. value. array[i] = delim) THEN
          w. WriteString (quotedDelim)
        ELSE  (* note: this is a tidbit slow for large strings *)
          w. WriteChar (value. value. array[i])
        END;
        INC (i)
      END;
      w. WriteChar (delim);
    END
  END Write;

END OOC:C:WriteConst.
