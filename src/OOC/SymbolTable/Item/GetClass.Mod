MODULE OOC:SymbolTable:Item:GetClass;

IMPORT
  Strings, OOC:SymbolTable:Item;
  
PROCEDURE GetClass* (item: Item.Item): Item.Name;
(**Determines the class name for a given item.  Depending on the type of the
   item, it is calculated like this:

   @table @otype
   @item Item.Record
   The class name is @ofield{Item.Record.className}.

   @item Item.Pointer
   The class is the class of the pointer base type, @emph{if} the base type is
   defined in the same module as the pointer type.
   
   @item Item.TypeDecl
   The class of a type declaration is that of the declared type.
   
   @item Item.FieldDecl
   The class of a record field is that of the record.

   @item Item.ProcDecl
   Three cases are distinguished for procedure declarations

   @table @asis
   @item Type-bound Procedure
   The class is that of the receiver type.

   @item Function Procedure
   The class is the class of the result type, @emph{if} it is defined in the
   same module as the function.

   @item Non-function Procedure
   If the procedure name has the prefix @samp{Init}, and the type of the first
   parameter is defined in the same module, then the class is that of this
   type.
   @end table
   @end table

   In all other cases, the item does is not considered to be part of a class
   and the function's result is @code{NIL}.  *)

  PROCEDURE SameModule (a, b: Item.Item): BOOLEAN;
    BEGIN
      RETURN (a. Module() = b. Module())
    END SameModule;
  
  PROCEDURE InitProcClass (procDecl: Item.ProcDecl): Item.Name;
    VAR
      found: BOOLEAN;
      pos: INTEGER;
    BEGIN
      Strings.FindNext ("Init", procDecl. name. str^, 0, found, pos);
      IF found & (pos = 0) & 
         (LEN (procDecl. formalPars. params^) >= 1) &
         (procDecl. formalPars. resultType = NIL) &
         SameModule (procDecl, procDecl. formalPars. params[0]. type) THEN
        RETURN GetClass (procDecl. formalPars. params[0]. type)
      ELSE
        RETURN NIL
      END
    END InitProcClass;
  
  BEGIN
    WITH item: Item.Record DO
      RETURN item. className
      
    | item: Item.Pointer DO
      IF (item. baseType IS Item.Record) &
         SameModule (item, item. baseType) THEN
        RETURN item. baseType(Item.Record). className
      ELSE
        RETURN NIL
      END
    
    | item: Item.TypeDecl DO
      RETURN GetClass (item. type)
      
    | item: Item.FieldDecl DO
      RETURN item. parent(Item.Record). className
      
    | item: Item.ProcDecl DO
      IF item. isTypeBound THEN
        RETURN GetClass (item. formalPars. receiver. type)
      ELSIF (item. formalPars. resultType # NIL) &
            SameModule (item, item. formalPars. resultType) THEN
        RETURN GetClass (item. formalPars. resultType)
      ELSE
        RETURN InitProcClass (item)
      END
    
    ELSE
      RETURN NIL
    END
  END GetClass;


END OOC:SymbolTable:Item:GetClass.
