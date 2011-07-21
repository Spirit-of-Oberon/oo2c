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
      <symbol id='type'>TYPE</symbol>
      <type_decl>
        <ident_def>
          <symbol id='ident'>T</symbol>
        </ident_def>
        <symbol id='eql'>=</symbol>
        <record_type>
          <symbol id='record'>RECORD</symbol>
          <node_list>
            <field_list>
              <node_list>
                <ident_def>
                  <symbol id='ident'>a</symbol>
                </ident_def>
              </node_list>
              <symbol id='colon'>:</symbol>
              <symbol id='ident'>CHAR</symbol>
            </field_list>
          </node_list>
          <symbol id='end'>END</symbol>
        </record_type>
        <symbol id='semicolon'>;</symbol>
      </type_decl>
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
