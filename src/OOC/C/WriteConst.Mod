MODULE OOC:C:WriteConst;

IMPORT
  TextRider, Language, Language:Boolean;
  
PROCEDURE Write* (w: TextRider.Writer; value: Language.Value);
  BEGIN
    WITH value: Boolean.Value DO
      IF value. value THEN
        w. WriteString("OOC_TRUE")
      ELSE
        w. WriteString("OOC_FALSE")
      END
    END
  END Write;

END OOC:C:WriteConst.
