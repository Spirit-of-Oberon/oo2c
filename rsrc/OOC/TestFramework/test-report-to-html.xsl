<?xml version="1.0"?> 
<xsl:stylesheet version="1.0"
		xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
		xmlns="http://www.w3.org/TR/xhtml1/transitional">
  <xsl:output method='html' indent='yes' />

  <xsl:template match='/'>
    <html>
      <head>
	<title>Test Report</title>
      </head>
      <body bgcolor="white">
	<h2>Table of Contents</h2>
	<ul>
	  <li><a href="#_test_summary">Test Summary</a></li>
	  <li><a href="#_test_setup">Test Setup</a></li>
	  <li><a href="#_test_results">Test Results</a></li>
	</ul>
	<xsl:apply-templates/>
      </body>
    </html>
  </xsl:template>

  <xsl:template match='test-report'>
    <hr/>
    <a name="_test_summary" />
    <h2>Test Summary</h2>
    <p>Selected Language: <b><xsl:value-of select="test-setup/@lang"/></b></p>
    <table>
      <tr><th/><th>passed</th><th>failed</th><th>tolerated</th></tr>
      <tr>
	<th>standard</th>
	<td align="center"><xsl:value-of
	  select="count(test-results/test-result[test/@relevance='standard'
	                and outcome/@class='passed'])"/></td> 
	<td align="center"><xsl:value-of
	  select="count(test-results/test-result[test/@relevance='standard'
	                and outcome/@class='failed'])"/></td> 
	<td align="center"><xsl:value-of
	  select="count(test-results/test-result[test/@relevance='standard'
	                and outcome/@class='tolerated'])"/></td> 
      </tr>
      <tr>
	<th>informal</th>
	<td align="center"><xsl:value-of
	  select="count(test-results/test-result[test/@relevance='informal'
	                and outcome/@class='passed'])"/></td> 
	<td align="center"><xsl:value-of
	  select="count(test-results/test-result[test/@relevance='informal'
	                and outcome/@class='failed'])"/></td> 
	<td align="center"><xsl:value-of
	  select="count(test-results/test-result[test/@relevance='informal'
	                and outcome/@class='tolerated'])"/></td> 
      </tr>
    </table>
    
    <p><b>Standard Tests</b></p>
    <ul>
      <xsl:call-template name='href-list-li'>
	<xsl:with-param name='relevance' select='"standard"'/>
	<xsl:with-param name='class' select='"passed"'/>
      </xsl:call-template>
      <xsl:call-template name='href-list-li'>
	<xsl:with-param name='relevance' select='"standard"'/>
	<xsl:with-param name='class' select='"failed"'/>
      </xsl:call-template>
      <xsl:call-template name='href-list-li'>
	<xsl:with-param name='relevance' select='"standard"'/>
	<xsl:with-param name='class' select='"tolerated"'/>
      </xsl:call-template>
    </ul>
    <p><b>Informal Tests</b></p>
    <ul>
      <xsl:call-template name='href-list-li'>
	<xsl:with-param name='relevance' select='"informal"'/>
	<xsl:with-param name='class' select='"passed"'/>
      </xsl:call-template>
      <xsl:call-template name='href-list-li'>
	<xsl:with-param name='relevance' select='"informal"'/>
	<xsl:with-param name='class' select='"failed"'/>
      </xsl:call-template>
      <xsl:call-template name='href-list-li'>
	<xsl:with-param name='relevance' select='"informal"'/>
	<xsl:with-param name='class' select='"tolerated"'/>
      </xsl:call-template>
    </ul>
    
    <xsl:apply-templates/>
  </xsl:template>

  <xsl:template name='href-list-li'>
    <xsl:param name='relevance'/>
    <xsl:param name='class'/>
    <xsl:variable name='nodes'
      select="test-results/test-result[test/@relevance=$relevance
                                       and outcome/@class=$class]" />
    <xsl:if test="$nodes">
      <li>
	<xsl:value-of select="$class" />
	<xsl:text>: </xsl:text>
	<xsl:choose>
	  <xsl:when test="$relevance='standard' and $class='passed'">
	    ... (<xsl:value-of select="count($nodes)"/> tests)
	  </xsl:when>
	  <xsl:otherwise>
	    <xsl:for-each select="$nodes">
	      <xsl:text> </xsl:text>
	      <a href="#{test/@id}">
		<xsl:value-of select="test/@id" />
	      </a>
	    </xsl:for-each>
	  </xsl:otherwise>
	</xsl:choose>
      </li>
    </xsl:if>
  </xsl:template>
  
  <!-- -->
  
  <xsl:template match='test-setup'>
    <hr/>
    <a name="_test_setup" />
    <h2>Test Setup</h2>
    <xsl:apply-templates/>
    <p><b>date</b></p>
    <ul><li><xsl:value-of select="../@time"/></li></ul>
  </xsl:template>
  
  <xsl:template match='machine|operating-system|processor|test-suite'>
    <p><b><xsl:value-of select="name(.)"/></b></p>
    <ul>
      <xsl:for-each select="@*">
	<li>
	  <xsl:value-of select="name(.)"/>
	  <xsl:text>: </xsl:text>
	  <xsl:value-of select="string(.)"/>
	</li>
      </xsl:for-each>
      <xsl:apply-templates select="*"/>
    </ul>
  </xsl:template>
  
  <xsl:template match='os-component'>
    <li>
      <xsl:value-of select="@name"/>
      <xsl:text>: </xsl:text>
      <xsl:value-of select="text()"/>
    </li>
  </xsl:template>
  
  <xsl:template match='test-results'>
    <hr/>
    <a name="_test_results" />
    <h2>Test Results</h2>
    <xsl:apply-templates/>
  </xsl:template>
  
  <!-- -->
  
  <xsl:template match='test-result'>
    <a name="{test/@id}">
      <xsl:text disable-output-escaping="yes">&amp;nbsp;</xsl:text>      
    </a>
    <table border="1" cellpadding="3" cellspacing="0" width="100%">
      <xsl:apply-templates select="test"/>
      <tr>
	<td colspan="3">
	  <p><xsl:apply-templates select="outcome"/></p>
	  <ul>
	    <xsl:apply-templates select="compile-status|build-status|run-status"/>
	  </ul>
	</td>
      </tr>
    </table>
  </xsl:template>

  <xsl:template match='test'>
    <tr bgcolor="#CCCCFF">
      <td width="25%">
	<xsl:attribute name="bgcolor">
	  <xsl:choose>
	    <xsl:when test="../outcome/@class = 'failed' and @relevance='informal'">#FFAA00</xsl:when>
	    <xsl:when test="../outcome/@class = 'failed'">#FF0000</xsl:when>
	    <xsl:when test="../outcome/@class = 'passed'">#00FF00</xsl:when>
	    <xsl:when test="../outcome/@class = 'tolerated'">#FFFF00</xsl:when>
	    <xsl:when test="../outcome/@class = 'skipped'">#AAAAAA</xsl:when>
	  </xsl:choose>
	</xsl:attribute>
	<strong>ID</strong>
	<xsl:text>: </xsl:text>
	<xsl:value-of select="@id"/>
      </td>
      <td>
	<strong>Languages</strong>
	<xsl:text>: </xsl:text>
	<xsl:choose>
	  <xsl:when test="@lang">
	    <xsl:value-of select="@lang"/>
	  </xsl:when>
	  <xsl:otherwise>
	    <xsl:value-of select="../@default-lang"/>
	  </xsl:otherwise>
	</xsl:choose>
      </td>
      <td width="25%">
	<strong>Relevance</strong>
	<xsl:text>: </xsl:text>
	<xsl:choose>
	  <xsl:when test="@relevance">
	    <xsl:value-of select="@relevance"/>
	  </xsl:when>
	  <xsl:otherwise>standard</xsl:otherwise>
	</xsl:choose>
      </td>
    </tr>
    <tr>
      <td colspan="3">
	<em>Type: </em><xsl:value-of select="@type"/>
	<xsl:text> [</xsl:text>
	<a href="{@file}">Input</a>
	<xsl:text>]</xsl:text>
	
	<xsl:if test="@output">
	  <xsl:text> [</xsl:text>
	  <a href="{@output}">Output Reference</a>
	  <xsl:text>]</xsl:text>
	</xsl:if>
	<p><xsl:apply-templates/></p>
      </td>
    </tr>
  </xsl:template>

  <xsl:template match="compile-status|build-status|run-status">
    <xsl:if test="@*">
      <li>
	<xsl:value-of select="name(current())" />
	<xsl:text>:</xsl:text>
	<xsl:if test="@status > 0">
	  <xsl:text> status=</xsl:text>
	  <xsl:value-of select="@status"/>
	</xsl:if>
	<xsl:if test="@signal > 0">
	  <xsl:text> signal=</xsl:text>
	  <xsl:value-of select="@signal"/>
	</xsl:if>
	<xsl:if test="@stdout">
	  <xsl:text> [</xsl:text>
	  <a href="{@stdout}">stdout</a>
	  <xsl:text>]</xsl:text>
	</xsl:if>
	<xsl:if test="@stderr">
	  <xsl:text> [</xsl:text>
	  <a href="{@stderr}">stderr</a>
	  <xsl:text>]</xsl:text>
	</xsl:if>
	<xsl:if test="@filtered">
	  <xsl:text> [</xsl:text>
	  <a href="{@filtered}">filtered</a>
	  <xsl:text>]</xsl:text>
	</xsl:if>
	<xsl:if test="@diff">
	  <xsl:text> [</xsl:text>
	  <a href="{@diff}">diff</a>
	  <xsl:text>]</xsl:text>
	</xsl:if>
      </li>
    </xsl:if>
  </xsl:template>
  
  <xsl:template match="outcome">
    <em>Result</em><xsl:text>: </xsl:text>
    <xsl:value-of select="@result"/>
    <xsl:text> --> </xsl:text>
    <b><xsl:value-of select="@class"/></b>
  </xsl:template>

  <xsl:template match='em'>
    <em><xsl:apply-templates/></em>
  </xsl:template>

  <xsl:template match='b'>
    <b><xsl:apply-templates/></b>
  </xsl:template>

  <xsl:template match='code'>
    <code><xsl:apply-templates/></code>
  </xsl:template>
</xsl:stylesheet>
