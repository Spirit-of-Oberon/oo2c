<?xml version='1.0'?> 
<xsl:stylesheet version='1.0'
                xmlns:xsl='http://www.w3.org/1999/XSL/Transform'
		xmlns='http://www.w3.org/TR/xhtml1/strict'>

<!--<xsl:key name="decl" match="type-decl" use="@name" />-->


<!-- MACRO get-module-uri: Given an element with an attribute `module',
     produces the URI for the module's HTML document.  The attribute is
     taken as a module's alias name and resolved using the import declarations.
     Result is empty if no alias name is given.  -->
<xsl:template name="get-module-uri">
  <xsl:variable name="alias" select="@module"/>

  <xsl:if test="$alias != ''">
    <xsl:for-each select="/interface-description/import-decl[$alias=@name]">
      <xsl:variable name="module" select="@module"/>
      <xsl:value-of select="../module-ref[@name=$module]/
                                ref-target[@type='html']/@relative-uri"/>
    </xsl:for-each>
  </xsl:if>
</xsl:template>


<xsl:template match="text()|@*" mode="decl-anchor"/>
<xsl:template match="const-decl|type-decl|var-decl|procedure|field-decl|receiver-decl|parameter-decl" mode="decl-anchor">
  <xsl:param name='prefix'/>

  <a name="{concat($prefix,@id)}">
<!--    <xsl:text> [ANCHOR </xsl:text>
    <xsl:value-of select="@id"/>
    <xsl:text>] </xsl:text>-->
  </a>
</xsl:template>


<!-- MACRO decl-href: Given a declaration element, write an href anchor tag
     pointing to the declaration.  If the parameter `content' is defined,
     use its value as the anchor content.  Otherwise, use the attribute
     `name' of the declaration.  -->
<xsl:template match="const-decl|type-decl|var-decl|procedure|field-decl|receiver-decl|parameter-decl" mode="decl-href">
  <xsl:param name="content" select="@name"/>
  <xsl:param name='prefix' select="''"/>

  <b>
    <a href="#{concat($prefix, @id)}">
<!--      <xsl:text>[HREF #</xsl:text>
      <xsl:value-of select="@id"/>
      <xsl:text>] </xsl:text>-->
      <xsl:value-of select="$content"/>
    </a>
  </b>
</xsl:template>
<xsl:template match="text()|@*" mode="decl-href"/>



<!-- MACRO ext-ref-type: Given an element `type-name', emit a href to the
     type's declaration.  -->
<xsl:template match="type-name" mode="ext-ref-type">
  <a>
    <xsl:attribute name="href">
      <xsl:call-template name="get-module-uri"/>
      <xsl:text>#</xsl:text>
      <xsl:value-of select="@name"/>
    </xsl:attribute>
<!--    <xsl:text>[HREF </xsl:text>
    <xsl:value-of select="@module"/>
    <xsl:text>.</xsl:text>
    <xsl:value-of select="@name"/>
    <xsl:text>] </xsl:text>-->
    <xsl:value-of select="@name"/>
  </a>
</xsl:template>


<!-- MACRO ref-base-obj: Given a matching element, emit a href to the class or
     the indicated object.  -->
<xsl:template match="base-class|inherited-field|
                     inherited-method|redefined-method|
                     doc-inherited-from|known-extension"
              mode="ref-base-obj">
  <xsl:variable name="module-name" select="@module"/>

  <a>
    <xsl:attribute name="href">
      <xsl:variable name="fragment" select="substring-after(@href, '#')"/>
      <xsl:value-of select="concat(
        /interface-description/module-ref[@name=$module-name]/ref-target[@type='html']/@relative-uri,
        '#', $fragment)"/>
    </xsl:attribute>

    <xsl:choose>
      <xsl:when test="@name">
        <xsl:value-of select="@name"/>
      </xsl:when>

      <xsl:otherwise>
        <xsl:value-of select="concat(@module, '.')"/>
        <b><xsl:value-of select="@class"/></b>
      </xsl:otherwise>
    </xsl:choose>
  </a>
</xsl:template>


</xsl:stylesheet>
