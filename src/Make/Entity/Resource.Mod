MODULE Make:Entity:Resource [OOC_EXTENSIONS];

IMPORT
  Make, Time, URI;



TYPE
  Entity* = POINTER TO EntityDesc;
  EntityDesc* = RECORD [ABSTRACT]
  (**A specialisation of @otype{Make.Entity} that is associated with an Uniform
     Resource Identifier @otype{URI.URI} and a time stamp.  *)
    (Make.EntityDesc)
  END;

PROCEDURE Init* (entity: Entity);
  BEGIN
    Make.InitEntity (entity)
  END Init;

PROCEDURE (entity: Entity) [ABSTRACT] GetURI* (): URI.URI;
  END GetURI;

PROCEDURE (entity: Entity) [ABSTRACT] Exists* (): BOOLEAN;
  END Exists;

PROCEDURE (entity: Entity) [ABSTRACT] GetTimeStamp* (VAR ts: Time.TimeStamp);
(**Returns the time stamp of @oparam{entity}.  This can be the time stamp of
   the resource itself, the maximum time stamp of the resource and all its
   ancestors, or some variant between these two extremes.

   @precond
   All ancestors of @oparam{entity} are known to be ``valid''.
   @end precond  *)
  END GetTimeStamp;
  
END Make:Entity:Resource.
