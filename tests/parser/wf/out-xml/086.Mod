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
      <with_statm>
        <node_list>
          <symbol id='with'>WITH</symbol>
          <operator>
            <symbol id='ident'>a</symbol>
            <symbol id='colon'>:</symbol>
            <symbol id='ident'>P1</symbol>
          </operator>
          <symbol id='do'>DO</symbol>
          <node_list>
            <operator>
              <symbol id='ident'>x</symbol>
              <symbol id='becomes'>:=</symbol>
              <symbol id='number10'>1</symbol>
            </operator>
          </node_list>
          <symbol id='bar'>|</symbol>
          <operator>
            <symbol id='ident'>b</symbol>
            <symbol id='colon'>:</symbol>
            <symbol id='ident'>P2</symbol>
          </operator>
          <symbol id='do'>DO</symbol>
          <node_list>
            <operator>
              <symbol id='ident'>x</symbol>
              <symbol id='becomes'>:=</symbol>
              <symbol id='number10'>2</symbol>
            </operator>
          </node_list>
        </node_list>
        <symbol id='end'>END</symbol>
      </with_statm>
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
