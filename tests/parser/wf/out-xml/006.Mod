<?xml version='1.0' encoding='ISO-8859-1' standalone='yes'?>
<module>
  <symbol id='module'>MODULE</symbol>
  <module_ident>
    <node_list>
      <symbol id='ident'>Simple</symbol>
    </node_list>
  </module_ident>
  <symbol id='semicolon'>;</symbol>
  <import_list>
    <symbol id='import'>IMPORT</symbol>
    <node_list>
      <import_decl>
        <module_ident>
          <node_list>
            <symbol id='ident'>M1</symbol>
          </node_list>
        </module_ident>
      </import_decl>
      <symbol id='comma'>,</symbol>
      <import_decl>
        <symbol id='ident'>M2</symbol>
        <symbol id='becomes'>:=</symbol>
        <module_ident>
          <node_list>
            <symbol id='ident'>Module2</symbol>
          </node_list>
        </module_ident>
      </import_decl>
      <symbol id='comma'>,</symbol>
      <import_decl>
        <module_ident>
          <node_list>
            <symbol id='ident'>Foo</symbol>
            <symbol id='colon'>:</symbol>
            <symbol id='ident'>M3</symbol>
          </node_list>
        </module_ident>
      </import_decl>
      <symbol id='comma'>,</symbol>
      <import_decl>
        <symbol id='ident'>M3</symbol>
        <symbol id='becomes'>:=</symbol>
        <module_ident>
          <node_list>
            <symbol id='ident'>Foo</symbol>
            <symbol id='colon'>:</symbol>
            <symbol id='ident'>Bar</symbol>
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
        <symbol id='ident'>Simple</symbol>
      </node_list>
    </module_ident>
  </body>
  <symbol id='period'>.</symbol>
</module>
