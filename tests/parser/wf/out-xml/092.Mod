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
        <symbol id='ident'>INTERFACE</symbol>
        <symbol id='stringDouble'>"C"</symbol>
        <node_list>
          <symbol id='comma'>,</symbol>
          <symbol id='ident'>CODE_FILE</symbol>
          <symbol id='comma'>,</symbol>
          <symbol id='ident'>INIT_FCT</symbol>
        </node_list>
        <symbol id='semicolon'>;</symbol>
        <symbol id='ident'>LINK</symbol>
        <node_list>
          <link_file_flag>
            <symbol id='ident'>FILE</symbol>
            <symbol id='stringDouble'>"f1"</symbol>
          </link_file_flag>
          <symbol id='semicolon'>;</symbol>
          <link_file_flag>
            <symbol id='ident'>FILE</symbol>
            <symbol id='stringDouble'>"f2"</symbol>
            <symbol id='ident'>ADD_OPTION</symbol>
            <symbol id='ident'>opt1</symbol>
          </link_file_flag>
          <symbol id='semicolon'>;</symbol>
          <link_file_flag>
            <symbol id='ident'>FILE</symbol>
            <symbol id='stringDouble'>"f3"</symbol>
            <symbol id='ident'>ADD_OPTION</symbol>
            <symbol id='ident'>opt2</symbol>
            <symbol id='comma'>,</symbol>
            <symbol id='ident'>op3</symbol>
          </link_file_flag>
          <symbol id='semicolon'>;</symbol>
          <link_obj_flag>
            <symbol id='ident'>OBJ</symbol>
            <symbol id='stringDouble'>"o1"</symbol>
          </link_obj_flag>
          <symbol id='semicolon'>;</symbol>
          <link_lib_flag>
            <symbol id='ident'>LIB</symbol>
            <symbol id='stringDouble'>"l1"</symbol>
          </link_lib_flag>
          <symbol id='semicolon'>;</symbol>
          <link_lib_flag>
            <symbol id='ident'>LIB</symbol>
            <symbol id='stringDouble'>"l2"</symbol>
            <symbol id='lParen'>(</symbol>
            <node_list>
              <symbol id='stringDouble'>"l1"</symbol>
              <symbol id='comma'>,</symbol>
              <symbol id='stringDouble'>"lx"</symbol>
            </node_list>
            <symbol id='rParen'>)</symbol>
          </link_lib_flag>
          <symbol id='semicolon'>;</symbol>
          <link_lib_flag>
            <symbol id='ident'>LIB</symbol>
            <symbol id='stringDouble'>"l3"</symbol>
            <symbol id='ident'>ADD_OPTION</symbol>
            <symbol id='ident'>lopt1</symbol>
            <symbol id='comma'>,</symbol>
            <symbol id='ident'>lopt2</symbol>
          </link_lib_flag>
        </node_list>
        <symbol id='end'>END</symbol>
      </module_flags>
    </node_list>
    <symbol id='rBrak'>]</symbol>
  </flags>
  <symbol id='semicolon'>;</symbol>
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
