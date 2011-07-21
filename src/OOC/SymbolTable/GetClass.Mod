MODULE OOC:SymbolTable:GetClass;

IMPORT
  Strings, Sym := OOC:SymbolTable;
  
PROCEDURE GetClass* (item: Sym.Item): Sym.Name;
(**Determines the class name for a given item.  Depending on the type of the
   item, it is calculated like this:

   @table @otype
   @item Sym.Record
   The class name is @ofield{Sym.Record.className}.

   @item Sym.Pointer
   The class is the class of the pointer base type, @emph{if} the base type is
   defined in the same module as the pointer type.
   
   @item Sym.TypeDecl
   The class of a type declaration is that of the declared type, if the type
   on the right hand side is from the same module.
   
   @item Sym.FieldDecl
   The class of a record field is that of the record.

   @item Sym.ProcDecl
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

  PROCEDURE SameModule (a, b: Sym.Item): BOOLEAN;
    BEGIN
      RETURN (a. Module() = b. Module())
    END SameModule;
  
  PROCEDURE InitProcClass (procDecl: Sym.ProcDecl): Sym.Name;
    VAR
      found: BOOLEAN;
      pos: INTEGER;
    BEGIN
      Strings.FindNext ("Init", procDecl. name. str^, 0, found, pos);
      IF found & (pos = 0) &
         (procDecl. formalPars. params # NIL) & 
         (LEN (procDecl. formalPars. params^) >= 1) &
         (procDecl. formalPars. resultType = NIL) &
         SameModule (procDecl, procDecl. formalPars. params[0]. type) THEN
        RETURN GetClass (procDecl. formalPars. params[0]. type)
      ELSE
        RETURN NIL
      END
    END InitProcClass;
  
  BEGIN
    WITH item: Sym.Record DO
      RETURN item. className
      
    | item: Sym.Pointer DO
      IF (item. baseType IS Sym.Record) &
         SameModule (item, item. baseType) THEN
        RETURN item. baseType(Sym.Record). className
      ELSE
        RETURN NIL
      END
    
    | item: Sym.TypeDecl DO
      IF SameModule (item, item. type) THEN
        RETURN GetClass (item. type)
      ELSE  (* alias for a type from another module *)
        RETURN NIL
      END
      
    | item: Sym.FieldDecl DO
      RETURN item. parent(Sym.Record). className
      
    | item: Sym.ProcDecl DO
      IF item.IsTypeBound() THEN
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


END OOC:SymbolTable:GetClass.
