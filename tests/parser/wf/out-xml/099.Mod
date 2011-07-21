<?xml version='1.0' encoding='ISO-8859-1' standalone='yes'?>
<module>
  <symbol id='module'>MODULE</symbol>
  <module_ident>
    <node_list>
      <symbol id='ident'>M</symbol>
    </node_list>
  </module_ident>
  <symbol id='semicolon'>;</symbol>
  <body>
    <node_list>
      <symbol id='var'>VAR</symbol>
      <var_decl>
        <node_list>
          <ident_def>
            <symbol id='ident'>buf</symbol>
          </ident_def>
        </node_list>
        <symbol id='colon'>:</symbol>
        <pointer_type>
          <symbol id='pointer'>POINTER</symbol>
          <symbol id='to'>TO</symbol>
          <array_type>
            <symbol id='array'>ARRAY</symbol>
            <flags>
              <symbol id='lBrak'>[</symbol>
              <node_list>
                <symbol id='ident'>NO_LENGTH_INFO</symbol>
                <symbol id='comma'>,</symbol>
                <symbol id='ident'>NO_DESCRIPTOR</symbol>
              </node_list>
              <symbol id='rBrak'>]</symbol>
            </flags>
            <node_list/>
            <symbol id='of'>OF</symbol>
            <symbol id='ident'>CHAR</symbol>
          </array_type>
        </pointer_type>
        <symbol id='semicolon'>;</symbol>
      </var_decl>
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
