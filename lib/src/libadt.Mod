MODULE libadt;
<* Warnings := FALSE *>

(**Some words on the module hierarchy layout of ADT:

   @itemize
   @item
   All modules of this library implementing abstract data types use the prefix
   @samp{ADT:}.  Test modules are not considered part of the library.  They
   reside in the top-level namespace, have @samp{Test} as prefix, and are not
   installed together with the library modules.

   @item
   New datatypes are defined in @samp{ADT:*} modules.

   @item
   Extensions of datatypes or implementations of abstract types should also use
   @samp{ADT:*} names.  This avoids a deeply nested namespace for families of
   datatypes structured through inheritance.

   @item
   Specialized implementations of an existing datatype that do not add any
   relevant functionality use the name of the more general implementation as
   prefix.  Example:

   @table @asis
   @item ADT:Dictionary
   The general purpose implementation of a dictionary.  It maps objects to
   object references.

   @item ADT:Dictionary:IntValue 
   A version of a dictionary that maps objects to @code{LONGINT} values,
   instead of object references.  The same could be achieved using the
   @samp{ADT:Dictionary} implementation, at the cost of wrapping all integer
   values into objects.

   The user is encouraged to give such modules a more sensible name on import,
   for example @samp{IMPORT Dictionary := ADT:Dictionary:IntValue}.
   @end table

   The documentation of the general implementation should provide links to the
   specialized versions.

   @item
   Modules providing services or algorithms for data types, but do not define a
   new data type themselves, use the name of the base module as prefix.  For
   example, a serialization implementation is in module
   @omodule{*ADT:Object:Storage}, because it implements the abstract rider
   interface defined in @omodule{*ADT:Object}.
   @end itemize

   It is expected that the @samp{ADT:*} namespace will be quite flat and broad.  *)


IMPORT
  ADT:Object,
  ADT:String,
  ADT:StringBuffer,
  ADT:ArrayList,
  ADT:LinkedList,
  ADT:Dictionary,
  ADT:Dictionary:IntValue,
  ADT:Dictionary:AddressKey,
  Address2Int := ADT:Dictionary:AddressKey:IntValue,
  
  ADT:Object:Storage,
  ADT:Comparator,
  ADT:Arrays,
  
  StringSearch,
  StringSearch:SubstringBF,
  StringSearch:SubstringBM,
  StringSearch:RegexpParser,
  StringSearch:RegexpDFA,
  StringSearch:NoMatch;

END libadt.
