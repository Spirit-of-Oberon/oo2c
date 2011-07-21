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
      <proc_decl>
        <symbol id='procedure'>PROCEDURE</symbol>
        <ident_def>
          <symbol id='ident'>Furbie</symbol>
          <oberon-doc>
            <summary>Two comments.</summary>
            <p pad-after='yes' no-indent='yes'>Two comments.</p>
            <p pad-after='yes' no-indent='yes'>Both should be associated with the procedure name.</p>
          </oberon-doc>
        </ident_def>
        <formal_pars>
          <symbol id='lParen'>(</symbol>
          <node_list>
            <fp_section>
              <node_list>
                <ident_def>
                  <symbol id='ident'>a</symbol>
                </ident_def>
              </node_list>
              <symbol id='colon'>:</symbol>
              <symbol id='ident'>INTEGER</symbol>
            </fp_section>
          </node_list>
          <symbol id='rParen'>)</symbol>
        </formal_pars>
        <symbol id='semicolon'>;</symbol>
        <body>
          <node_list/>
          <symbol id='end'>END</symbol>
          <module_ident>
            <node_list>
              <symbol id='ident'>Furbie</symbol>
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
