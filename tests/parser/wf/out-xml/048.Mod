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
    <node_list/>
    <symbol id='begin'>BEGIN</symbol>
    <node_list>
      <operator>
        <symbol id='ident'>x</symbol>
        <symbol id='becomes'>:=</symbol>
        <function_call>
          <symbol id='ident'>a</symbol>
          <symbol id='lParen'>(</symbol>
          <node_list>
            <symbol id='ident'>B</symbol>
          </node_list>
          <symbol id='rParen'>)</symbol>
        </function_call>
      </operator>
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
