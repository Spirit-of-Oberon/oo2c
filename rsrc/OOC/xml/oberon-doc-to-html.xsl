<?xml version="1.0"?> 
<xsl:stylesheet version="1.0"
                xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
		xmlns="http://www.w3.org/TR/xhtml1/strict">
<xsl:output method='html' indent='yes'/>

<!-- root element of any oberon-doc document -->
<xsl:template match='oberon-doc'>
  <xsl:apply-templates select='*[name() != "summary"]'/>  
  <xsl:if test="../doc-inherited-from">
    <p>
      <xsl:text>[Description inherited from </xsl:text>
      <xsl:apply-templates select="../doc-inherited-from" mode="ref-base-obj"/>
      <xsl:text>]</xsl:text>
    </p>
  </xsl:if>
</xsl:template>


<!-- glyphs -->
<xsl:template match='bullet'>*</xsl:template>
<xsl:template match='dots'>...</xsl:template>
<xsl:template match='minus'>-</xsl:template>
<xsl:template match='em-dash'>--</xsl:template>
<xsl:template match='result'>==></xsl:template>
<xsl:template match='left-quote'>"</xsl:template>
<xsl:template match='right-quote'>"</xsl:template>


<!-- block elements -->
<xsl:template match='p'>
  <p><xsl:apply-templates/></p>
</xsl:template>

<xsl:template match='pre-cond/p[position()=1]'>
  <p>
    <strong>Pre-condition: </strong>
    <xsl:apply-templates/>
  </p>
</xsl:template>
<xsl:template match='pre-cond'><xsl:apply-templates/></xsl:template>

<xsl:template match='post-cond/p[position()=1]'>
  <p>
    <strong>Post-condition: </strong>
    <xsl:apply-templates/>
  </p>
</xsl:template>
<xsl:template match='post-cond'><xsl:apply-templates/></xsl:template>

<xsl:template match='summary'><xsl:apply-templates/></xsl:template>

<xsl:template match="example">
  <blockquote><pre><xsl:apply-templates/></pre></blockquote>
</xsl:template>


<xsl:template match="table">
  <table>
    <xsl:apply-templates/>
  </table>
</xsl:template>

<xsl:template match="table-row">
  <tr>
    <td valign="top" align="left">
      <xsl:for-each select="table-first-column">
        <xsl:apply-templates select="."/>
        <xsl:if test="position() != last()"><br/></xsl:if>
      </xsl:for-each>
    </td>
    <td><xsl:apply-templates select="item"/></td>
  </tr>
</xsl:template>

<xsl:template match="table-first-column">
  <xsl:apply-templates/>
</xsl:template>


<xsl:template match="itemize">
  <ul>
    <xsl:if test="itemize-text">
      <li><xsl:apply-templates select="itemize-text"/></li>
    </xsl:if>
    <xsl:for-each select="item">
      <li><xsl:apply-templates select="."/></li>
    </xsl:for-each>
  </ul>
</xsl:template>


<xsl:template match="enumerate">
  <ol>
    <xsl:if test="enumerate-text">
      <li><xsl:apply-templates select="enumerate-text"/></li>
    </xsl:if>
    <xsl:for-each select="item">
      <li><xsl:apply-templates select="."/></li>
    </xsl:for-each>
  </ol>
</xsl:template>



<!-- inline elements -->
<xsl:template match="p//text()"><xsl:value-of select="."/></xsl:template>
<xsl:template match="example//text()"><xsl:value-of select="."/></xsl:template>
<xsl:template match="summary//text()"><xsl:value-of select="."/></xsl:template>
<xsl:template match="table-first-column//text()"><xsl:value-of select="."/></xsl:template>


<xsl:template match="asis"><xsl:apply-templates/></xsl:template>

<xsl:template match="cite"><cite><xsl:apply-templates/></cite></xsl:template>

<xsl:template match='code|command'>
  <font face="Arial,Helvetica">
    <xsl:apply-templates/>
  </font>
</xsl:template>

<xsl:template match="dfn"><em><xsl:apply-templates/></em></xsl:template>

<xsl:template match="emph"><em><xsl:apply-templates/></em></xsl:template>

<xsl:template match="file"><tt>`<xsl:apply-templates/></tt>'</xsl:template>

<xsl:template match="kbd"><kbd><xsl:apply-templates/></kbd></xsl:template>

<xsl:template match="samp">`<samp><xsl:apply-templates/></samp>'</xsl:template>

<xsl:template match="strong"><strong><xsl:apply-templates/></strong></xsl:template>

<xsl:template match="url">
  <a href="{text()}">
    <xsl:apply-templates/>
  </a>
</xsl:template>

<xsl:template match="var"><var><xsl:apply-templates/></var></xsl:template>

<xsl:template match="email">
  <a href="{concat('mailto:', email-address)}">
    <xsl:choose>
      <xsl:when test="email-displayed-text">
        <xsl:apply-templates select="email-displayed-text"/>
      </xsl:when>

      <xsl:otherwise>
        <xsl:apply-templates select="email-address"/>
      </xsl:otherwise>
    </xsl:choose>
  </a>
</xsl:template>

<xsl:template match="uref">
  <a href="{uref-url}">
    <xsl:choose>
      <xsl:when test="uref-replacement">
        <xsl:apply-templates select="uref-replacement"/>
      </xsl:when>

      <xsl:when test="uref-text">
        <xsl:apply-templates select="uref-text"/>
      </xsl:when>

      <xsl:otherwise>
        <xsl:apply-templates select="uref-url"/>
      </xsl:otherwise>
    </xsl:choose>
  </a>
</xsl:template>



<xsl:template match='oberon-param'>
  <var>
    <xsl:call-template name="reference-content"/>
  </var>
</xsl:template>

<xsl:template match='oberon-module|oberon-const|oberon-field|
                     oberon-proc|oberon-type|oberon-var'>
  <xsl:call-template name="reference-content"/>
</xsl:template>

<xsl:template name="reference-content">
  <xsl:choose>
    <xsl:when test="@href">
      <xsl:variable name="module" select="substring-before(@href, '#')"/>
      <xsl:variable name="fragment" select="substring-after(@href, '#')"/>
      <a href="{concat(/interface-description/module-ref[@name=$module]
                           /ref-target[@type='html']/@relative-uri,
                       '#', $fragment)}">
<!--	<xsl:text>[HREF: </xsl:text>
	<xsl:value-of select="@href"/>
	<xsl:text>] </xsl:text>-->
        <xsl:apply-templates/>
      </a>
    </xsl:when>

    <xsl:otherwise>
      <xsl:apply-templates/>
    </xsl:otherwise>
  </xsl:choose>
</xsl:template>

</xsl:stylesheet>
