<?xml version='1.0' encoding='ISO-8859-1' standalone='yes'?>
<module>
  <symbol id='module'>MODULE</symbol>
  <module_ident>
    <node_list>
      <symbol id='ident'>M</symbol>
    </node_list>
  </module_ident>
  <flags>
    <symbol id='lBrak'>[</symbol>
    <node_list>
      <symbol id='ident'>OOC_EXTENSIONS</symbol>
    </node_list>
    <symbol id='rBrak'>]</symbol>
  </flags>
  <symbol id='semicolon'>;</symbol>
  <body>
    <node_list>
      <symbol id='type'>TYPE</symbol>
      <type_decl>
        <ident_def>
          <symbol id='ident'>R</symbol>
        </ident_def>
        <symbol id='eql'>=</symbol>
        <record_type>
          <symbol id='record'>RECORD</symbol>
          <flags>
            <symbol id='lBrak'>[</symbol>
            <node_list>
              <symbol id='ident'>ABSTRACT</symbol>
            </node_list>
            <symbol id='rBrak'>]</symbol>
          </flags>
          <node_list/>
          <symbol id='end'>END</symbol>
        </record_type>
        <symbol id='semicolon'>;</symbol>
      </type_decl>
      <proc_decl>
        <symbol id='procedure'>PROCEDURE</symbol>
        <receiver>
          <symbol id='lParen'>(</symbol>
          <symbol id='var'>VAR</symbol>
          <ident_def>
            <symbol id='ident'>r</symbol>
          </ident_def>
          <symbol id='colon'>:</symbol>
          <symbol id='ident'>R</symbol>
          <symbol id='rParen'>)</symbol>
        </receiver>
        <flags>
          <symbol id='lBrak'>[</symbol>
          <node_list>
            <symbol id='ident'>ABSTRACT</symbol>
          </node_list>
          <symbol id='rBrak'>]</symbol>
        </flags>
        <ident_def>
          <symbol id='ident'>Proc</symbol>
        </ident_def>
        <formal_pars/>
        <symbol id='semicolon'>;</symbol>
        <body>
          <node_list/>
          <symbol id='end'>END</symbol>
          <module_ident>
            <node_list>
              <symbol id='ident'>Proc</symbol>
            </node_list>
          </module_ident>
        </body>
        <symbol id='semicolon'>;</symbol>
      </proc_decl>
    </node_list>
    <symbol id='end'>END</symbol>
    <module_ident>
      <node_list>
        <symbol id='ident'>M</symbol>
      </node_list>
    </module_ident>
  </body>
  <symbol id='period'>.</symbol>
</module>
