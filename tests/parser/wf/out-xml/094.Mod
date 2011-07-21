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
      <proc_decl>
        <symbol id='procedure'>PROCEDURE</symbol>
        <flags>
          <symbol id='lBrak'>[</symbol>
          <node_list>
            <symbol id='stringDouble'>"miss_sophie"</symbol>
            <symbol id='comma'>,</symbol>
            <symbol id='ident'>HAS_BODY</symbol>
          </node_list>
          <symbol id='rBrak'>]</symbol>
        </flags>
        <ident_def>
          <symbol id='ident'>P</symbol>
          <symbol id='times'>*</symbol>
        </ident_def>
        <formal_pars/>
        <symbol id='semicolon'>;</symbol>
        <body>
          <node_list/>
          <symbol id='end'>END</symbol>
          <module_ident>
            <node_list>
              <symbol id='ident'>P</symbol>
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
