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
      <case_statm>
        <symbol id='case'>CASE</symbol>
        <symbol id='ident'>x</symbol>
        <symbol id='of'>OF</symbol>
        <node_list>
          <node_list>
            <operator>
              <symbol id='number10'>10</symbol>
              <symbol id='upto'>..</symbol>
              <symbol id='number10'>20</symbol>
            </operator>
            <symbol id='comma'>,</symbol>
            <operator>
              <symbol id='number10'>30</symbol>
              <symbol id='upto'>..</symbol>
              <symbol id='number10'>40</symbol>
            </operator>
          </node_list>
          <symbol id='colon'>:</symbol>
          <node_list>
            <operator>
              <symbol id='ident'>y</symbol>
              <symbol id='becomes'>:=</symbol>
              <symbol id='number10'>1</symbol>
            </operator>
          </node_list>
        </node_list>
        <symbol id='end'>END</symbol>
      </case_statm>
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
