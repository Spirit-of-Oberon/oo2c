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
      <module_flags>
        <symbol id='ident'>FOREIGN</symbol>
        <symbol id='stringDouble'>"C"</symbol>
        <node_list/>
      </module_flags>
    </node_list>
    <symbol id='rBrak'>]</symbol>
  </flags>
  <symbol id='semicolon'>;</symbol>
  <body>
    <node_list>
      <symbol id='var'>VAR</symbol>
      <var_decl>
        <node_list>
          <ident_def>
            <symbol id='ident'>v</symbol>
          </ident_def>
          <flags>
            <symbol id='lBrak'>[</symbol>
            <node_list>
              <symbol id='stringDouble'>"call_me_al"</symbol>
            </node_list>
            <symbol id='rBrak'>]</symbol>
          </flags>
        </node_list>
        <symbol id='colon'>:</symbol>
        <symbol id='ident'>BOOLEAN</symbol>
        <symbol id='semicolon'>;</symbol>
      </var_decl>
      <symbol id='type'>TYPE</symbol>
      <type_decl>
        <ident_def>
          <symbol id='ident'>string</symbol>
          <symbol id='times'>*</symbol>
        </ident_def>
        <symbol id='eql'>=</symbol>
        <pointer_type>
          <symbol id='pointer'>POINTER</symbol>
          <flags>
            <symbol id='lBrak'>[</symbol>
            <node_list>
              <symbol id='ident'>CSTRING</symbol>
            </node_list>
            <symbol id='rBrak'>]</symbol>
          </flags>
          <symbol id='to'>TO</symbol>
          <array_type>
            <symbol id='array'>ARRAY</symbol>
            <node_list/>
            <symbol id='of'>OF</symbol>
            <symbol id='ident'>char</symbol>
          </array_type>
        </pointer_type>
        <symbol id='semicolon'>;</symbol>
      </type_decl>
      <proc_decl>
        <symbol id='procedure'>PROCEDURE</symbol>
        <flags>
          <symbol id='lBrak'>[</symbol>
          <node_list>
            <proc_id_flag>
              <symbol id='ident'>PROC_ID</symbol>
              <symbol id='eql'>=</symbol>
              <symbol id='number10'>123</symbol>
            </proc_id_flag>
          </node_list>
          <symbol id='rBrak'>]</symbol>
        </flags>
        <ident_def>
          <symbol id='ident'>P</symbol>
          <symbol id='times'>*</symbol>
        </ident_def>
        <formal_pars/>
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
