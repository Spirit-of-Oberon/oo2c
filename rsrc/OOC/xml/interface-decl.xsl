<?xml version='1.0'?> 
<xsl:stylesheet version='1.0'
                xmlns:xsl='http://www.w3.org/1999/XSL/Transform'
                xmlns='http://www.w3.org/TR/xhtml1/strict'>

<!--DECLARATIONS: All declaration templates come in two flavors, 'decl-sig'
    and 'decl-detail'.  The former writes a text suitable for a <pre>...</pre>
    block that mirrors the essential information of the declaration in a
    compact format.  The name of the signature text should be a href to the
    detailed description.  The 'decl-detail' variant includes all information
    an is included in a <pre>...</pre> block at the beginning of a detailed
    declaration description.  -->

<xsl:template match="text()|@*" mode='decl-detail'></xsl:template>
<xsl:template match="text()|@*" mode='decl-sig'></xsl:template>

<!--== parameter-decl ======================================================-->

<xsl:template match="parameter-decl" mode='decl-detail'>
  <xsl:param name='pprefix'/>
  
  <xsl:call-template name='ParameterDef'/>
  <xsl:text>: </xsl:text>
  <xsl:apply-templates mode='type-detail'/>
  <xsl:if test='following-sibling::parameter-decl'>
    <xsl:text>; &#xA;</xsl:text>
    <xsl:value-of select='$pprefix'/>
  </xsl:if>
</xsl:template>

<xsl:template match='parameter-decl' mode='decl-sig'>
  <xsl:if test="@variable-parameter = 'yes'">
    <b><font face="Arial,Helvetica">VAR </font></b>
  </xsl:if>
  <xsl:apply-templates select="type" mode="type-sig"/>
  <xsl:if test='following-sibling::parameter-decl'>
    <xsl:text>, </xsl:text>
  </xsl:if>
</xsl:template>


<!--== receiver-decl =======================================================-->

<xsl:template match='receiver-decl' mode='decl-detail'>
  <xsl:text>(</xsl:text>
  <xsl:call-template name='ParameterDef'/>
  <xsl:text>: </xsl:text>
  <xsl:apply-templates mode='type-detail'/>
  <xsl:text>) </xsl:text>
</xsl:template>
  
<xsl:template match='receiver-decl' mode='decl-sig'>
  <xsl:value-of select='concat(@name, ".")'/>
</xsl:template>


<!--== procedure ===========================================================-->

<xsl:template match='procedure' mode='decl-detail'>
  <pre>
    <xsl:text>PROCEDURE </xsl:text>
    <xsl:apply-templates select='formal-parameters/receiver-decl'
                         mode='decl-detail'/>
    <xsl:call-template name='IdentDef'/>
    <xsl:apply-templates select='formal-parameters' mode='type-detail'>
      <xsl:with-param name='pprefix'
        select='translate(concat("PROCEDURE ", @name),
          "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_",
          "                                                               ")'/>
    </xsl:apply-templates>
  </pre>
</xsl:template>

<xsl:template match='procedure' mode='decl-sig'>
  <!-- <xsl:apply-templates select='formal-parameters/receiver-decl'
                       mode='decl-sig'/> -->
  <xsl:call-template name='IdentDefHREF'/>
  <xsl:apply-templates select='formal-parameters' mode='type-sig'/>
</xsl:template>


<!--== const-decl===========================================================-->

<xsl:template match="const-decl" mode='decl-detail'>
  <pre>
    <xsl:text>CONST </xsl:text>
    <xsl:call-template name='IdentDef'/>
    <xsl:call-template name='InsertSpace'/>
  </pre>
</xsl:template>

<xsl:template match='const-decl' mode='decl-sig'>
  <xsl:call-template name='IdentDefHREF'/>
</xsl:template>


<!--== type-decl ===========================================================-->

<xsl:template match='type-decl' mode='decl-detail'>
  <pre>
    <xsl:text>TYPE </xsl:text>
    <xsl:call-template name='IdentDef'/>
    <xsl:text> = </xsl:text>
    <xsl:apply-templates select='type' mode='type-detail'>
      <xsl:with-param name='pprefix'
        select='translate(concat("TYPE ", @name, "   "),
          "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_",
          "                                                               ")'/>
    </xsl:apply-templates>
  </pre>
</xsl:template>

<xsl:template match='type-decl' mode='decl-sig'>
  <xsl:call-template name='IdentDefHREF'/>
  <xsl:text> = </xsl:text>
  <xsl:apply-templates select='type' mode='type-sig'/>
</xsl:template>


<!--== var-decl ============================================================-->

<xsl:template match="var-decl" mode='decl-detail'>
  <pre>
    <xsl:text>VAR </xsl:text>
    <xsl:call-template name='IdentDef'/>
    <xsl:text>: </xsl:text>
    <xsl:apply-templates select='type' mode='type-detail'/>
  </pre>
</xsl:template>

<xsl:template match='var-decl' mode='decl-sig'>
  <xsl:call-template name='IdentDefHREF'/>
  <xsl:text>: </xsl:text>
  <xsl:apply-templates select='type' mode='type-sig'/>
</xsl:template>


<!--== field-decl ==========================================================-->
<!-- the 'record-type' mode is invoked from the record-type template -->

<xsl:template match='field-decl' mode='decl-detail'>
  <pre>
    <xsl:text>FIELD </xsl:text>
    <xsl:call-template name='IdentDef'/>
    <xsl:text>: </xsl:text>
    <xsl:apply-templates select='type' mode='type-detail'/>
  </pre>
</xsl:template>

<xsl:template match='field-decl' mode='decl-sig'>
  <xsl:call-template name='IdentDefHREF'/>
  <xsl:text>: </xsl:text>
  <xsl:apply-templates select='type' mode='type-detail'/>
</xsl:template>

<xsl:template match='field-decl' mode='record-type'>
  <xsl:param name='pprefix'/>
  
  <xsl:value-of select='concat("&#10;", $pprefix, "    ")'/>
  <xsl:call-template name='IdentDefHREF'/>
  <xsl:text>: </xsl:text>
  <xsl:apply-templates select='type' mode='type-detail'/>
  <xsl:text>;</xsl:text>
</xsl:template>



<!--========================================================================-->
<!-- This template produces the list of redefined procedures in a
     method detail entry -->

<xsl:template match='procedure' mode='redefined-procs'>
  <xsl:if test="redefined-method">
    <p>
      <b><xsl:text>Redefines</xsl:text></b><xsl:text>: </xsl:text>
      <xsl:for-each select='redefined-method'>
        <xsl:apply-templates select="." mode="ref-base-obj"/>
        <xsl:if test="position() != last()">, </xsl:if>
      </xsl:for-each>
    </p>
  </xsl:if>
</xsl:template>

</xsl:stylesheet>

