<?xml version='1.0'?> 
<xsl:stylesheet version='1.0'
                xmlns:xsl='http://www.w3.org/1999/XSL/Transform'
		xmlns='http://www.w3.org/TR/xhtml1/strict'>


<xsl:template match="text()|@*" mode='type-detail'></xsl:template>
<xsl:template match="text()|@*" mode='type-sig'></xsl:template>

<!--== type-name ===========================================================-->

<xsl:template match="type-name" mode="type-sig">
  <xsl:choose>
    <xsl:when test="@module = '#predef'">
      <xsl:value-of select="@name"/>
    </xsl:when>
    <xsl:otherwise>
      <xsl:apply-templates select="." mode="ext-ref-type"/>
    </xsl:otherwise>
  </xsl:choose>
</xsl:template>

<xsl:template match="type-name" mode="type-detail">
  <xsl:choose>
    <xsl:when test="@module = '#predef'">
      <xsl:value-of select="@name"/>
    </xsl:when>
    <xsl:otherwise>
      <xsl:apply-templates select="." mode="ext-ref-type"/>
    </xsl:otherwise>
  </xsl:choose>
</xsl:template>


<!--== formal-parameters ===================================================-->

<xsl:template match="formal-parameters" mode="type-sig">
  <xsl:text>(</xsl:text>
  <xsl:apply-templates select="parameter-decl" mode="decl-sig"/>
  <xsl:text>)</xsl:text>
  <xsl:apply-templates select="result-type" mode="type-sig"/>
</xsl:template>

<xsl:template match="formal-parameters" mode="type-detail">
  <xsl:param name="pprefix" select="''"/>

  <xsl:text>(</xsl:text>
  <xsl:apply-templates select="parameter-decl" mode="decl-detail">
     <xsl:with-param name="pprefix" select="concat($pprefix, ' ')"/>
  </xsl:apply-templates>
  <xsl:apply-templates select="result-type" mode="type-detail"/>
  <xsl:if test="not(result-type)">)</xsl:if>

  <xsl:if test="exceptions">
    <xsl:text>&#xA;  RAISES </xsl:text>
    <xsl:for-each select="exceptions/type-name">
	<xsl:apply-templates select="." mode="type-detail" />
        <xsl:if test="position() != last()">, </xsl:if>
    </xsl:for-each>
    <xsl:text>;</xsl:text>
  </xsl:if>
</xsl:template>


<!--== array ===============================================================-->

<xsl:template match="array" mode="type-sig">
  <font face="Arial,Helvetica">
    <xsl:text>ARRAY </xsl:text>
    <xsl:if test="length">n </xsl:if>
    <xsl:text>OF </xsl:text>
  </font>
  <xsl:apply-templates select="element-type" mode="type-sig"/>
</xsl:template>

<xsl:template match="array" mode="type-detail">
  <xsl:text>ARRAY </xsl:text>
  <xsl:if test="length">n </xsl:if>
  <xsl:text>OF </xsl:text>
  <xsl:apply-templates mode="type-detail"/>
</xsl:template>


<!--== result type =========================================================-->

<xsl:template match='result-type' mode='type-detail'>
  <xsl:text>): </xsl:text>
  <xsl:apply-templates mode='type-detail'/>
</xsl:template>

<xsl:template match='result-type' mode='type-sig'>
  <xsl:text>: </xsl:text>
  <xsl:apply-templates mode='type-detail'/>
</xsl:template>


<!--========================================================================-->




<xsl:template match='type|pointer-base' mode='type-sig'>
  <xsl:apply-templates mode='type-sig'/>
</xsl:template>
<xsl:template match='type|pointer-base' mode='type-detail'>
  <xsl:param name='pprefix'/>
  <xsl:apply-templates mode='type-detail'>
     <xsl:with-param name='pprefix' select='$pprefix'/>
  </xsl:apply-templates>
</xsl:template>


<xsl:template match="pointer" mode='type-sig'>
  <font face="Arial,Helvetica">POINTER TO </font><xsl:apply-templates mode='type-sig'/>
</xsl:template>
<xsl:template match="pointer" mode='type-detail'>
  <xsl:text>POINTER TO </xsl:text><xsl:apply-templates mode='type-detail'/>
</xsl:template>


<xsl:template match="record" mode='type-sig'><font face="Arial,Helvetica">RECORD ... END</font></xsl:template>
<xsl:template match="record" mode='type-detail'>
  <xsl:param name='pprefix' select='"YYYY"'/>RECORD<xsl:apply-templates mode='record-type'><xsl:with-param name='pprefix' select='$pprefix'/></xsl:apply-templates>
<xsl:value-of select='concat("&#10;", $pprefix, "END")'/>
</xsl:template>



<!--========================================================================-->
<!-- These templates generate the class hierarchy diagram. -->

<xsl:template match="base-class" mode="base-class-hierarchy">
  <xsl:variable name="base-string">
    <xsl:apply-templates select="base-class" mode="base-class-hierarchy"/>
  </xsl:variable>
  <xsl:variable name="prefix" select="substring-before($base-string, '?')"/>
  <xsl:variable name="text" select="substring-after($base-string, '?')"/>
  <xsl:variable name="module-name" select="@module"/>
  <xsl:variable name="class" select="@class"/>

  <xsl:value-of select="concat($prefix, '     ?', $text)"/>
  <xsl:if test="$text">
    <xsl:value-of select="concat($prefix, '  |&#xA;')"/>
  </xsl:if>

  <xsl:value-of select="concat($prefix, '  +---&lt;a href=&quot;')"/>
  <xsl:value-of select="concat(/interface-description/module-ref
         [@name=$module-name]/ref-target[@type='html']/@relative-uri, 
         '#', $class)"/>
  <xsl:value-of select="concat('&quot;>', @module, '.&lt;b>', 
                               $class, '&lt;/b>&lt;/a>')"/>

  <xsl:text>&#xA;</xsl:text>
</xsl:template>

<xsl:template match="class" mode="base-class-hierarchy">
  <pre>
    <xsl:variable name="base-string">
      <xsl:apply-templates select="base-class" mode="base-class-hierarchy"/>
    </xsl:variable>
    <xsl:variable name="prefix" select="substring-before($base-string, '?')"/>
    <xsl:variable name="text" select="substring-after($base-string, '?')"/>
    
    <xsl:value-of disable-output-escaping="yes" select="$text"/>
    <xsl:if test="$text">
      <xsl:value-of select="concat($prefix, '  |&#xA;')"/>
    </xsl:if>
    <xsl:value-of disable-output-escaping="yes" 
                  select="concat($prefix, '  +--',
                                 ../@name, '.&lt;b>',
                                 @name, '&lt;/b>')"/>
  </pre>
</xsl:template>

<xsl:template match="text()|@*" mode='base-class-hierarchy'/>


<!--========================================================================-->
<!-- This template generates the "Field inherited from" lists. -->

<xsl:template match="base-class" mode="inherited-fields">
  <xsl:apply-templates select="base-class" mode="inherited-fields"/>

  <xsl:if test="inherited-field">
    <p>
      <xsl:text>From </xsl:text>
      <xsl:apply-templates select="." mode="ref-base-obj"/>
      <xsl:text>: </xsl:text>
      <xsl:call-template name="BrAndIndent"/>
      <xsl:for-each select="inherited-field">
        <xsl:sort select="@name"/>
        <xsl:apply-templates select="." mode="ref-base-obj"/>
        <xsl:if test="position() != last()">, </xsl:if>
      </xsl:for-each>
    </p>
  </xsl:if>
</xsl:template>

<xsl:template match="text()|@*" mode='inherited-fields'></xsl:template>

<!--========================================================================-->
<!-- This template generates the "Method inherited from" lists. -->

<xsl:template match="base-class" mode="inherited-methods">
  <xsl:apply-templates select="base-class" mode="inherited-methods"/>

  <xsl:if test="inherited-method">
    <p>
      <xsl:text>From </xsl:text>
      <xsl:apply-templates select="." mode="ref-base-obj"/>
      <xsl:text>: </xsl:text>
      <xsl:call-template name="BrAndIndent"/>
      <xsl:for-each select="inherited-method">
        <xsl:sort select="@name"/>
        <xsl:apply-templates select="." mode="ref-base-obj"/>
        <xsl:if test="position() != last()">, </xsl:if>
      </xsl:for-each>
    </p>
  </xsl:if>
</xsl:template>

<xsl:template match="text()|@*" mode='inherited-methods'></xsl:template>

<!--========================================================================-->

</xsl:stylesheet>
