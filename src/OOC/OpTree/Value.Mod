MODULE OOC:OpTree:Value;

IMPORT
  OOC:SymbolTable:Item;


TYPE
  Value* = POINTER TO ValueDesc;
  ValueDesc = RECORD
    (**An instance of type @otype{Value} holds @emph{all} the attributes
       that are associated with an expression.  This includes a wide range
       of different information: the type, any constant value, if it is a
       reference to a declared object, and also the intermediate code that
       is built from the expression.  The base type @otype{Value} holds all
       the attributes that are needed to perform semantic checks on the 
       input program, independent of the back-end.  Specializations of
       @otype{Value} add the fields that store the information for the
       intermediate representation.  *)
    type: Item.Type;
    
    (*const: ...;*)
    decl: Item.Declaration;
  END;


BEGIN
  
END OOC:OpTree:Value.
