MODULE LibOsPath;

IMPORT OS:Path;

PROCEDURE Test*;
  VAR
    s, root, ext: STRING;
  BEGIN
    (* dirname
       --------------------------------------------------------------------- *)
    s := Path.DirName("");
    ASSERT (s.Equals(""));

    s := Path.DirName("/");
    ASSERT (s.Equals("/"));

    s := Path.DirName("//");
    ASSERT (s.Equals("//"));

    s := Path.DirName("abc");
    ASSERT (s.Equals(""));

    s := Path.DirName("/abc");
    ASSERT (s.Equals("/"));

    s := Path.DirName("~");
    ASSERT (s.Equals(""));

    s := Path.DirName("~/");
    ASSERT (s.Equals("~"));

    s := Path.DirName("~foo/");
    ASSERT (s.Equals("~foo"));

    s := Path.DirName("abc/");
    ASSERT (s.Equals("abc"));

    s := Path.DirName("abc///");
    ASSERT (s.Equals("abc"));
    
    
    (* Path.basename
       --------------------------------------------------------------------- *)
    s := Path.BaseName("");
    ASSERT (s.Equals(""));
    
    s := Path.BaseName("/");
    ASSERT (s.Equals(""));
    
    s := Path.BaseName("abc/");
    ASSERT (s.Equals(""));
    
    s := Path.BaseName("abc");
    ASSERT (s.Equals("abc"));
    
    s := Path.BaseName("abc/x");
    ASSERT (s.Equals("x"));
    
    
    (* Path.splitext
       --------------------------------------------------------------------- *)
    Path.SplitExt("", root, ext);
    ASSERT (root.Equals("")); ASSERT (ext.Equals(""));
    
    Path.SplitExt("/", root, ext);
    ASSERT (root.Equals("/")); ASSERT (ext.Equals(""));
    
    Path.SplitExt(".", root, ext);
    ASSERT (root.Equals("")); ASSERT (ext.Equals("."));
    
    Path.SplitExt("/.", root, ext);
    ASSERT (root.Equals("/")); ASSERT (ext.Equals("."));
    
    Path.SplitExt("./", root, ext);
    ASSERT (root.Equals("./")); ASSERT (ext.Equals(""));
    
    Path.SplitExt("a.", root, ext);
    ASSERT (root.Equals("a")); ASSERT (ext.Equals("."));
    
    Path.SplitExt("a.b", root, ext);
    ASSERT (root.Equals("a")); ASSERT (ext.Equals(".b"));
    
    Path.SplitExt("a.b.c", root, ext);
    ASSERT (root.Equals("a.b")); ASSERT (ext.Equals(".c"));
    
  END Test;

END LibOsPath.
