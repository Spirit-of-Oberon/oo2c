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
          <symbol id='ident'>A</symbol>
        </ident_def>
        <symbol id='eql'>=</symbol>
        <symbol id='ident'>CHAR</symbol>
        <symbol id='semicolon'>;</symbol>
      </type_decl>
      <type_decl>
        <ident_def>
          <symbol id='ident'>B</symbol>
          <symbol id='times'>*</symbol>
        </ident_def>
        <symbol id='eql'>=</symbol>
        <symbol id='ident'>A</symbol>
        <symbol id='semicolon'>;</symbol>
      </type_decl>
      <type_decl>
        <ident_def>
          <symbol id='ident'>C</symbol>
          <symbol id='times'>*</symbol>
        </ident_def>
        <symbol id='eql'>=</symbol>
        <symbol id='ident'>INTEGER</symbol>
        <symbol id='semicolon'>;</symbol>
      </type_decl>
      <type_decl>
        <ident_def>
          <symbol id='ident'>D</symbol>
        </ident_def>
        <symbol id='eql'>=</symbol>
        <operator>
          <symbol id='ident'>M</symbol>
          <symbol id='period'>.</symbol>
          <symbol id='ident'>X</symbol>
        </operator>
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
