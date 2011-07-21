MODULE Category;

IMPORT Driver;

CONST
  nameLength = 16;

TYPE
  CategoryEntry* = POINTER TO CategoryEntryDesc;
  CategoryEntryDesc* = RECORD
    driver- : Driver.Driver;
    id- : LONGINT;
    next- : CategoryEntry;
  END;

  Category* = POINTER TO CategoryDesc;
  CategoryDesc* = RECORD
    name- : ARRAY nameLength OF CHAR;
    entries- : CategoryEntry;
    next- : Category;
  END;

VAR
  categories- : Category;

PROCEDURE FindCategory* (name : ARRAY OF CHAR; VAR category : Category) : BOOLEAN;
BEGIN
  category := categories;
  WHILE category # NIL DO
    IF category.name = name THEN
      RETURN TRUE;
    END;
    category := category.next;
  END;
  RETURN FALSE
END FindCategory;

PROCEDURE (c : Category) Append* (d : Driver.Driver; id : LONGINT);
VAR e : CategoryEntry;
BEGIN
  NEW(e);
  e.driver := d;
  e.id := id;
  e.next := c.entries;
  c.entries := e;
END Append;

PROCEDURE (c : Category) AddTest* (name : ARRAY OF CHAR);
VAR
  driver : Driver.Driver; id : LONGINT;
  result : BOOLEAN;
BEGIN
  result := Driver.FindTest(name, driver, id);
  ASSERT(result);
  c.Append(driver, id);
END AddTest;

PROCEDURE (c : Category) AddCategory* (name : ARRAY OF CHAR);
VAR
  cat : Category;
  e : CategoryEntry;
BEGIN
  IF FindCategory(name, cat) THEN
    e := cat.entries;
    WHILE e # NIL DO
      c.Append(e.driver, e.id);
      e := e.next;
    END;
  END;
END AddCategory;

PROCEDURE New*(name : ARRAY OF CHAR) : Category;
VAR c : Category;
BEGIN
  NEW(c);
  COPY(name, c.name);
  c.entries := NIL;
  RETURN c;
END New;

PROCEDURE Register* (c : Category);
BEGIN
  c.next := categories;
  categories := c;
END Register;

BEGIN
  categories := NIL;
END Category.
