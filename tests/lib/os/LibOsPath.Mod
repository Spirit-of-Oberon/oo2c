MODULE LibOsPath;

IMPORT OS:Path;

PROCEDURE Test*;
  VAR
    str, root, ext: ARRAY 1024 OF CHAR;
  BEGIN
    (* dirname
       --------------------------------------------------------------------- *)
    Path.dirname("", str);
    ASSERT (str = "");

    Path.dirname("/", str);
    ASSERT (str = "/");

    Path.dirname("//", str);
    ASSERT (str = "//");

    Path.dirname("abc", str);
    ASSERT (str = "");

    Path.dirname("/abc", str);
    ASSERT (str = "/");

    Path.dirname("~", str);
    ASSERT (str = "");

    Path.dirname("~/", str);
    ASSERT (str = "~");

    Path.dirname("~foo/", str);
    ASSERT (str = "~foo");

    Path.dirname("abc/", str);
    ASSERT (str = "abc");

    Path.dirname("abc///", str);
    ASSERT (str = "abc");
    
    
    (* Path.basename
       --------------------------------------------------------------------- *)
    Path.basename("", str);
    ASSERT (str = "");
    
    Path.basename("/", str);
    ASSERT (str = "");
    
    Path.basename("abc/", str);
    ASSERT (str = "");
    
    Path.basename("abc", str);
    ASSERT (str = "abc");
    
    Path.basename("abc/x", str);
    ASSERT (str = "x");
    
    
    (* Path.splitext
       --------------------------------------------------------------------- *)
    Path.splitext("", root, ext);
    ASSERT (root = ""); ASSERT (ext = "");
    
    Path.splitext("/", root, ext);
    ASSERT (root = "/"); ASSERT (ext = "");
    
    Path.splitext(".", root, ext);
    ASSERT (root = ""); ASSERT (ext = ".");
    
    Path.splitext("/.", root, ext);
    ASSERT (root = "/"); ASSERT (ext = ".");
    
    Path.splitext("./", root, ext);
    ASSERT (root = "./"); ASSERT (ext = "");
    
    Path.splitext("a.", root, ext);
    ASSERT (root = "a"); ASSERT (ext = ".");
    
    Path.splitext("a.b", root, ext);
    ASSERT (root = "a"); ASSERT (ext = ".b");
    
    Path.splitext("a.b.c", root, ext);
    ASSERT (root = "a.b"); ASSERT (ext = ".c");
    
  END Test;

END LibOsPath.
