<?xml version='1.0' encoding='ISO-8859-1' standalone='yes'?>
<module>
  <symbol id='module'>MODULE</symbol>
  <module_ident>
    <node_list>
      <symbol id='ident'>M</symbol>
    </node_list>
    <oberon-doc>
      <summary>This belongs <emph>not</emph> to the name of the imported module, but rather to the current module.</summary>
      <p pad-after='yes' no-indent='yes'>This belongs <emph>not</emph> to the name of the imported module, but rather to the current module.</p>
    </oberon-doc>
  </module_ident>
  <symbol id='semicolon'>;</symbol>
  <import_list>
    <symbol id='import'>IMPORT</symbol>
    <node_list>
      <import_decl>
        <symbol id='ident'>x</symbol>
        <symbol id='becomes'>:=</symbol>
        <module_ident>
          <node_list>
            <symbol id='ident'>X</symbol>
          </node_list>
        </module_ident>
      </import_decl>
    </node_list>
    <symbol id='semicolon'>;</symbol>
  </import_list>
  <body>
    <node_list/>
    <symbol id='end'>END</symbol>
    <module_ident>
      <node_list>
        <symbol id='ident'>M</symbol>
      </node_list>
    </module_ident>
  </body>
  <symbol id='period'>.</symbol>
</module>
