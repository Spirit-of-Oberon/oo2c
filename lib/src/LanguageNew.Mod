MODULE LanguageNew;

(**This module provides the definitions for a basic object type used in most of
   the ADT library, as well as ``boxed'' versions of the language's basic
   types.

   Note: This module is a construction site.  New type definitions and features
   are added on demand.  If it is not used, it has no place here.  This module
   will be renamed to ``Language'' eventually, if it has been fleshed out
   enough to replace both @omodule{*ADT:Object}, @omodule{*Language} and
   friends (including @omodule{*Language:String0}), and the value objects of
   @omodule{*Config}.  *)

IMPORT
  S := SYSTEM;
  
TYPE
  Hash* = LONGINT;
  (**The integer type used to store hash values.  *)
  
  Object* = POINTER TO ObjectDesc;
  ObjectArray* = ARRAY OF Object;
  ObjectArrayPtr* = POINTER TO ObjectArray;
  ObjectDesc* = RECORD [ABSTRACT]
  (**This class is the common base type of (almost) all classes defined in this
     module and the ADT library.  It provides the methods @oproc{Object.Equals}
     and @oproc{Object.HashCode}.

     It is an abstract class without any state of its own.  As such, it has no
     initialization procedure or a cleanup method.  *)
  END;


(*PROCEDURE (x: Object) ToString*(): String;
(**Returns a string representation of the object.  Typically, the string is
   some form of ``natural'' representation of the value.  For complex objects,
   it should describe the type and essential attributes of the object.  The
   exact format of the returned value is intentionally left vague.  *)
  BEGIN
    RETURN NIL;
  END ToString;*)

PROCEDURE (x: Object) Equals*(y: Object): BOOLEAN;
(**Indicates whether some other object is "equal to" this one.

   The @oproc{Object.Equals} method implements an equivalence relation:

   @itemize @bullet
   @item
   It is reflexive: for any reference value @samp{x}, @samp{x.Equals(x)} should
   return @code{TRUE}.

   @item
   It is symmetric: for any reference values @samp{x} and @samp{y},
   @samp{x.Equals(y)} should return @code{TRUE} if and only if
   @samp{y.Equals(x)} returns @code{TRUE}.

   @item
   It is transitive: for any reference values @samp{x}, @samp{y}, and @samp{z},
   if @samp{x.Equals(y)} returns @code{TRUE} and @samp{y.Equals(z)} returns
   @code{TRUE}, then @samp{x.Equals(z)} should return @code{TRUE}.

   @item
   It is consistent: for any reference values @samp{x} and @samp{y}, multiple
   invocations of @samp{x.Equals(y)} consistently return @code{TRUE} or
   consistently return @code{FALSE}, provided no information used in equals
   comparisons on the object is modified.

   @item
   For any non-@code{NIL} reference value @samp{x}, @samp{x.Equals(NIL)} should
   return @code{FALSE}.
   @end itemize

   The @samp{Equals} method for class @otype{Object} implements the most
   discriminating possible equivalence relation on objects; that is, for any
   reference values @samp{x} and @samp{y}, this method returns @code{TRUE} if
   and only if @samp{x} and @samp{y} refer to the same object (@samp{x=y} has
   the value @code{TRUE}).  *)
  BEGIN
    RETURN (x = y)
  END Equals;

PROCEDURE (x: Object) HashCode*(): Hash;
(**Returns a hash code value for the object.  This method is supported for the
   benefit of dictionaries such as those provided by
   @omodule{*ADT:Dictionary}..

   The general contract of @oproc{Object.HashCode} is:

   @itemize
   @item
   Whenever it is invoked on the same object more than once during an execution
   of an application, the @oproc{Object.HashCode} method must consistently
   return the same integer, provided no information used in equals comparisons
   on the object is modified.  This integer need not remain consistent from one
   execution of an application to another execution of the same application.

   @item
   If two objects are equal according to the @oproc{Object.Equals} method, then
   calling the @oproc{Object.HashCode} method on each of the two objects must
   produce the same integer result.

   @item
   It is @emph{not} required that if two objects are unequal according to the
   @oproc{Object.Equals} method, then calling the @oproc{Object.HashCode}
   method on each of the two objects must produce distinct integer results.
   However, the programmer should be aware that producing distinct integer
   results for unequal objects may improve the performance of dictionaries.
   @end itemize

   As much as is reasonably practical, the @oproc{Object.HashCode} method
   defined by class @otype{Object} does return distinct integers for distinct
   objects.  (This is typically implemented by converting the internal address
   of the object into an integer, but this implementation technique is not
   required.)  *)
  BEGIN
<*IF TARGET_ADDRESS=64 THEN*>
    RETURN S.VAL(Hash,
                 S.VAL(SET, S.LSH(S.LSH(S.VAL(S.ADDRESS, x), 32), -32)) /
                 S.VAL(SET, S.LSH(S.VAL(S.ADDRESS, x), -32)))
<*ELSE*>
    RETURN S.VAL(Hash, x)
<*END*>
  END HashCode;

END LanguageNew.
