MODULE Make:Command:Target;

IMPORT
  Channel, Make, ADT:String;


TYPE
  Target* = POINTER TO TargetDesc;
  TargetDesc* = RECORD
    (Make.CommandDesc)
  END;

(* Default Target
   ------------------------------------------------------------------------ *)

PROCEDURE Init* (target: Target);
  BEGIN
    Make.InitCommand (target);
  END Init;

PROCEDURE New* (): Target;
  VAR
    target: Target;
  BEGIN
    NEW (target);
    Init (target);
    RETURN target
  END New;

PROCEDURE (target: Target) Id* (): String.String;
  BEGIN
    RETURN String.New ("[target]")
  END Id;

PROCEDURE (target: Target) Discover*(): Make.CommandState;
  BEGIN
    IF target. HasInvalidAncestor() THEN
      RETURN Make.commandInvalid
    ELSE
      RETURN Make.commandSchedule
    END
  END Discover;

PROCEDURE (target: Target) Run*(): BOOLEAN;
  BEGIN
    RETURN TRUE
  END Run;

PROCEDURE (target: Target) ProduceOutput* (stdout, stderr: Channel.Channel);
  BEGIN
  END ProduceOutput;

END Make:Command:Target.
