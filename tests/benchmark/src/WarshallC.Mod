MODULE WarshallC [INTERFACE "C"; LINK FILE "WarshallC.c" END];

PROCEDURE Transclosure* (VAR path: ARRAY OF ARRAY OF BOOLEAN; max: LONGINT);

END WarshallC.
