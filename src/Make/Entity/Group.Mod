MODULE Make:Entity:Group;

IMPORT
  Make, ADT:String;

TYPE
  Entity* = POINTER TO EntityDesc;
  EntityDesc* = RECORD
    (Make.EntityDesc)
  END;

PROCEDURE Init* (entity: Entity);
  BEGIN
    Make.InitEntity (entity)
  END Init;

PROCEDURE New* (): Entity;
  VAR
    entity: Entity;
  BEGIN
    NEW (entity);
    Init (entity);
    RETURN entity
  END New;


PROCEDURE (entity: Entity) Discover* (): Make.EntityState;
  BEGIN
    IF entity. HasInvalidAncestor() THEN
      RETURN Make.entityInvalid
    ELSE
      RETURN Make.entityValid
    END
  END Discover;

PROCEDURE (entity: Entity) Id* (): String.String;
  BEGIN
    RETURN String.New ("[Make:Entity:Group]")
  END Id;

END Make:Entity:Group.
