MODULE Generic82;

IMPORT
Object;

TYPE
Alp(T: Object.Object) = POINTER TO AlpDesc(T);
AlpDesc(T: Object.Object) = RECORD(Object.ObjectDesc)

END;

PROCEDURE (a: Alp(T, E)) DoSomething;
BEGIN

END DoSomething;

END Generic82.
