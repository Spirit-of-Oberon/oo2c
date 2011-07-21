<?xml version="1.0"?> 
<!DOCTYPE xsl:stylesheet [
<!ENTITY nbsp "&#xA0;">
]>

<xsl:stylesheet version="1.0"
                xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
		xmlns="http://www.w3.org/TR/xhtml1/strict">
<xsl:output method='html' indent='yes'/>

<xsl:include href='oberon-doc-to-html.xsl'/>
<xsl:include href='interface-xref.xsl'/>
<xsl:include href='interface-types.xsl'/>
<xsl:include href='interface-decl.xsl'/>



<!-- document root: generate HTML document root, with head and
     body elements -->
<xsl:template match="/">
  <html>
    <head>
      <title>Module Interface <xsl:value-of select="/interface-description/@name"/></title>
    </head>
    <body bgcolor="white">
      <xsl:apply-templates/>
    </body>
  </html>
</xsl:template>

<!-- root element -->
<xsl:template match="interface-description">
  <table border="0" width="100%" cellpadding="1" cellspacing="0">
    <tr>
      <td valign="top" class="NavBarCell3">
        <font size="-2">SUMMARY: &nbsp;MODULE&nbsp;|&nbsp;<a href="#_summary_class">CLASS</a>&nbsp;|&nbsp;<a href="#_summary_type">TYPE</a>&nbsp;|&nbsp;<a href="#_summary_procedure">PROC</a>&nbsp;|&nbsp;<a href="#_summary_variable">VAR</a>&nbsp;|&nbsp;<a href="#_summary_constant">CONST</a></font>
      </td>
      <td valign="top" class="NavBarCell3">
        <font size="-2">DETAIL: &nbsp;<a href="#_detail_type">TYPE</a>&nbsp;|&nbsp;<a href="#_detail_procedure">PROC</a>&nbsp;|&nbsp;<a href="#_detail_variable">VAR</a>&nbsp;|&nbsp;<a href="#_detail_constant">CONST</a></font>
      </td>
    </tr>
  </table>
  <hr/>

  <h1><xsl:value-of select="@name"/></h1>
  <xsl:apply-templates select="oberon-doc"/>
  <xsl:call-template name='ImportList'/>

  <a name="_summary_class"></a>
  <xsl:call-template name="ClassList"/>
  <xsl:for-each select="class">
    <xsl:sort select="@name"/>
    <xsl:call-template name="ClassSummary"/>
    <xsl:call-template name="separator"/>
  </xsl:for-each>

  <a name="_summary_type"></a>
  <xsl:call-template name='SummarySection'>
    <xsl:with-param name='section_name'>Type Summary</xsl:with-param>
    <xsl:with-param name='decl_set' select='type-decl'/>
  </xsl:call-template>
    
  <a name="_summary_procedure"></a>
  <xsl:call-template name='SummarySection'>
    <xsl:with-param name='section_name'>Procedure Summary</xsl:with-param>
    <xsl:with-param name='decl_set' select='procedure'/>
  </xsl:call-template>
  
  <a name="_summary_variable"></a>
  <xsl:call-template name='SummarySection'>
    <xsl:with-param name='section_name'>Variable Summary</xsl:with-param>
    <xsl:with-param name='decl_set' select='var-decl'/>
  </xsl:call-template>
  
  <a name="_summary_constant"></a>
  <xsl:call-template name='SummarySection'>
    <xsl:with-param name='section_name'>Constant Summary</xsl:with-param>
    <xsl:with-param name='decl_set' select='const-decl'/>
  </xsl:call-template>

  <hr/><xsl:call-template name="separator"/>

  <xsl:for-each select="class">
    <xsl:sort select="@name"/>
    <xsl:call-template name="ClassDetail"/>
    <xsl:call-template name="separator"/>
  </xsl:for-each>

  <a name="_detail_type"></a>
  <xsl:call-template name='DetailSection'>
    <xsl:with-param name='section_name'>Type Detail</xsl:with-param>
    <xsl:with-param name='decl_set' select='type-decl'/>
  </xsl:call-template>
    
  <a name="_detail_procedure"></a>
  <xsl:call-template name='DetailSection'>
    <xsl:with-param name='section_name'>Procedure Detail</xsl:with-param>
    <xsl:with-param name='decl_set' select='procedure'/>
  </xsl:call-template>
  
  <a name="_detail_variable"></a>
  <xsl:call-template name='DetailSection'>
    <xsl:with-param name='section_name'>Variable Detail</xsl:with-param>
    <xsl:with-param name='decl_set' select='var-decl'/>
  </xsl:call-template>
  
  <a name="_detail_constant"></a>
  <xsl:call-template name='DetailSection'>
    <xsl:with-param name='section_name'>Constant Detail</xsl:with-param>
    <xsl:with-param name='decl_set' select='const-decl'/>
  </xsl:call-template>
</xsl:template>

<!-- disable default processing for text and attributes -->
<xsl:template match="text()|@*"></xsl:template>
<xsl:template match="text()|@*" mode='record-type'></xsl:template>


<!-- macro IdentDef: write identifier with export mark -->
<xsl:template name='IdentDef'>
  <xsl:choose>
    <xsl:when test='@export = "yes"'>
      <b>
        <xsl:call-template name="ident-def-content"/>
      </b>
    </xsl:when>
    <xsl:when test='@export = "no"'>
      <xsl:text>[</xsl:text>
      <xsl:call-template name="ident-def-content"/>
      <xsl:text>]</xsl:text>
    </xsl:when>
    <xsl:when test='@export = "read-only"'>
      <b>
        <xsl:call-template name="ident-def-content"/>
      </b>
      <xsl:text>-</xsl:text>
    </xsl:when>
  </xsl:choose>
</xsl:template>

<xsl:template name="ident-def-content">
  <xsl:value-of select="@name"/>
</xsl:template>


<!-- macro IdentDefHREF: write identifier with export mark within an href anchor -->
<xsl:template name='IdentDefHREF'>
  <xsl:apply-templates select="." mode="decl-href">
    <xsl:with-param name="content">
      <xsl:call-template name='IdentDef'/>
    </xsl:with-param>
  </xsl:apply-templates>
</xsl:template>

<!-- macro ParameterDef: write IdentDef, optionally prefixed by VAR keyword -->
<xsl:template name='ParameterDef'>
  <xsl:if test="@variable-parameter = 'yes'">VAR </xsl:if>
  <xsl:apply-templates select="." mode="anchor"/>
</xsl:template>

<xsl:template match="parameter-decl|receiver-decl" mode="anchor">
  <a name="{@id}">
<!--    <xsl:text>[ANCHOR: </xsl:text>
    <xsl:value-of select="@id"/>
    <xsl:text>] </xsl:text>-->
    <xsl:value-of select="@name"/>
  </a>
</xsl:template>


<!-- macro separator: insert some nbrk and a hr element -->
<xsl:template name="separator">
  <pre>


  </pre>
</xsl:template>



<!-- macro SectionHead: write head of section -->
<xsl:template name='SectionHead'>
  <xsl:param name='section_name' select='"no_section_name"'/>
  
  <table border="1" cellpadding="3" cellspacing="0" width="100%">
  <tr bgcolor="#CCCCFF" class="TableHeadingColor">
  <td colspan="1"><font size="+2"><b><xsl:value-of select='$section_name'/></b></font></td>
  </tr>
  </table>
</xsl:template>

<!-- macro SubSectionHead: write head of subsection -->
<xsl:template name='SubSectionHead'>
  <xsl:param name='subsection_name'/>
  
  <table border="1" cellpadding="3" cellspacing="0" width="100%">
  <tr bgcolor="#E0E0FF" class="TableSubHeadingColor">
  <td colspan="1"><font size="+2"><b><xsl:value-of select='$subsection_name'/></b></font></td>
  </tr>
  </table>
</xsl:template>

<xsl:template name='InsertSpace'>
  <xsl:text disable-output-escaping="yes"><![CDATA[&nbsp;]]></xsl:text>
</xsl:template>

<xsl:template name='BrAndIndent'>
  <br/><xsl:text disable-output-escaping="yes"><![CDATA[&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;]]></xsl:text>
</xsl:template>

<!-- macro SummarySection: Writes a summary table beginning with a 
     title row, followed by rows for every indicated declaration -->
<xsl:template name="SummarySection">
  <xsl:param name='section_name'/>
  <xsl:param name='decl_set'/>
  
  <xsl:if test='$decl_set'>
    <table border="1" cellpadding="3" cellspacing="0" width="100%">
    <tr bgcolor="#CCCCFF" class="TableHeadingColor">
    <td colspan="2"><font size="+2"><b><xsl:value-of select='$section_name'/></b></font></td>
    </tr>
      <xsl:for-each select='$decl_set'>
	<xsl:sort select="@name"/>
	<tr>
	  <td>
	    <xsl:apply-templates select="." mode='decl-sig'/>
	    <xsl:call-template name="BrAndIndent"/>
	    <xsl:apply-templates select="oberon-doc/summary"/>
	  </td>
	</tr>
      </xsl:for-each>
    </table>
    <xsl:call-template name="separator"/>
  </xsl:if>
</xsl:template>

<!-- macro DetailSection: Writes a detail section beginning with a 
     title row, followed by paragraphs for every indicated declaration -->
<xsl:template name="DetailSection">
  <xsl:param name='section_name'/>
  <xsl:param name='decl_set'/>
  
  <xsl:if test='$decl_set'>
    <xsl:call-template name='SectionHead'>
      <xsl:with-param name='section_name' select='$section_name'/>
    </xsl:call-template>

    <xsl:for-each select='$decl_set'>
      <xsl:sort select='@name'/>
      
      <xsl:if test='not(type/*/@class)'>
        <!-- omit anchor if this is a type declaration belonging
             to a class -->
        <xsl:apply-templates select="." mode="decl-anchor"/>
      </xsl:if>
      <h3><xsl:value-of select='@name'/></h3>
      <xsl:apply-templates select='.' mode='decl-detail'/>
      <blockquote>
        <xsl:apply-templates select='oberon-doc'/>
      </blockquote>
      <xsl:if test='position() != count($decl_set)'><hr/></xsl:if>
    </xsl:for-each>
    <xsl:call-template name="separator"/>
  </xsl:if>
</xsl:template>


<!--########################################################################
    CLASS DESCRIPTIONS
    ########################################################################-->

<!-- Import List -->
<xsl:template name="ImportList">
  <xsl:if test='module-ref'>
    <h3>Import List</h3>
    <pre>
      <xsl:text>&#xA;</xsl:text>
      <xsl:for-each select='import-decl'>
        <xsl:sort select="@module"/>
        <xsl:variable name="module" select="@module"/>
	<xsl:if test='../module-ref[@name=$module]'>
          <xsl:text>    </xsl:text>
          <a href="{../module-ref[@name=$module]/
                       ref-target[@type='html']/@relative-uri}">
            <xsl:value-of select="@module"/>
          </a>
          <xsl:text>&#xA;</xsl:text>
        </xsl:if>
      </xsl:for-each>
    </pre>
    <xsl:call-template name="InsertSpace"/>
  </xsl:if>
</xsl:template>

<!-- Class List -->
<xsl:template name="ClassList">
  <xsl:if test='class'>
    <table border="1" cellpadding="3" cellspacing="0" width="100%">
      <tr bgcolor="#CCCCFF" class="TableHeadingColor">
        <td colspan="2"><font size="+2"><b>Class List</b></font></td>
      </tr>
      <xsl:for-each select='class'>
        <xsl:sort select="@name"/>
        <xsl:variable name="class-name" select="@name"/>
        <tr>
          <td align='left' valign='top'>
            <xsl:apply-templates select="type-decl[type/record]" mode="decl-href">
              <xsl:with-param name="content" select="$class-name"/>
            </xsl:apply-templates>
          </td>
          <td>
            <xsl:apply-templates select="type-decl[type/record]/oberon-doc/summary"/>
          </td>
        </tr>
      </xsl:for-each>
    </table>
    <xsl:call-template name="separator"/>
  </xsl:if>
</xsl:template>


<!-- Class Summary Section; Parameter: $section_name, $decl_set -->
<xsl:template name="ClassSummarySection">
  <xsl:param name='section_name'/>
  <xsl:param name='decl_set'/>
  
  <xsl:if test='$decl_set'>
    <tr bgcolor="#E0E0FF" class="TableSubHeadingColor">
      <td colspan="2"><font size="+1"><b><xsl:value-of select='$section_name'/></b></font></td>
    </tr>
    <xsl:for-each select='$decl_set'>
      <xsl:sort select="@name"/>
      <tr><td>
        <xsl:apply-templates select="." mode='decl-sig'/>
        <xsl:call-template name="BrAndIndent"/>
        <xsl:apply-templates select="oberon-doc/summary"/>
      </td></tr>
    </xsl:for-each>
  </xsl:if>
</xsl:template>

<!-- Class Summary; Parameter: $class_name -->
<xsl:template name="ClassSummary">
  <xsl:variable name="class_name" select="@name"/>
  
  <xsl:for-each select='type-decl'>
    <xsl:apply-templates select="." mode="decl-anchor"/>
  </xsl:for-each>
  <table border="1" cellpadding="3" cellspacing="0" width="100%">
  
  <tr bgcolor="#CCCCFF" class="TableHeadingColor">
    <td colspan="2">
      <font size="+2">
        <b>Class Summary: <xsl:value-of select="$class_name"/></b>
        <xsl:text> [</xsl:text>
        <xsl:apply-templates select="type-decl[type/record]" mode="decl-href">
          <xsl:with-param name="content" select="'Detail'"/>
          <xsl:with-param name="prefix" select="'_detail__'"/>
        </xsl:apply-templates>
        <xsl:text>]</xsl:text>
      </font>
    </td>
  </tr>

  <tr colspan="2">
    <td>
      <xsl:apply-templates select="." mode="base-class-hierarchy"/>

      <xsl:if test='type-decl[type/record]/oberon-doc'>
        <hr/>
        <xsl:apply-templates select='type-decl[type/record]/oberon-doc'/>
      </xsl:if>

      <xsl:if test="known-extension">
        <p>
          <b>Known extensions</b>
          <xsl:text>: </xsl:text>
          <xsl:for-each select="known-extension">
            <xsl:sort select="@module"/>
            <xsl:sort select="@class"/>
            <xsl:variable name="module-name" select="@module"/>
            <a href="{concat(/interface-description/
                               module-ref[@name=$module-name]/
                               ref-target[@type='html']/@relative-uri, 
                               '#', @class)}">
              <xsl:value-of select="concat(@module, '.')"/>
              <b><xsl:value-of select="@class"/></b>
            </a>
            <xsl:if test='position() != last()'>, </xsl:if>
          </xsl:for-each>
        </p>
      </xsl:if>
    </td>
  </tr>

  <xsl:call-template name="ClassSummarySection">
    <xsl:with-param name='section_name' select='"Field Summary"'/>
    <xsl:with-param name='decl_set' select='type-decl/type/record/field-decl'/>
  </xsl:call-template>
  
  <xsl:if test="base-class//inherited-field">
    <tr bgcolor="#E0E0FF" class="TableSubHeadingColor">
      <td colspan="2"><font size="+1"><b>Inherited Fields</b></font></td>
    </tr>
    <tr><td>
      <xsl:apply-templates select="." mode="inherited-fields"/>
    </td></tr>
  </xsl:if>

  <xsl:call-template name="ClassSummarySection">
    <xsl:with-param name='section_name' select='"Constructor Summary"'/>
    <xsl:with-param name='decl_set' select='procedure[not(formal-parameters/receiver-decl)]'/>
  </xsl:call-template>
  
  <xsl:call-template name="ClassSummarySection">
    <xsl:with-param name='section_name' select='"Method Summary"'/>
    <xsl:with-param name='decl_set' select='procedure[formal-parameters/receiver-decl]'/>
  </xsl:call-template>
    
  <xsl:if test="base-class//inherited-method">
    <tr bgcolor="#E0E0FF" class="TableSubHeadingColor">
      <td colspan="2"><font size="+1"><b>Inherited Methods</b></font></td>
    </tr>
    <tr><td>
      <xsl:apply-templates select="." mode="inherited-methods"/>
    </td></tr>
  </xsl:if>

  </table>
  <xsl:call-template name="InsertSpace"/>
</xsl:template>



<!-- Class Detail Section; Parameter: $section_name, $decl_set, $content_template -->
<xsl:template name="ClassDetailSection">
  <xsl:param name='subsection_name'/>
  <xsl:param name='decl_set'/>
  
  <xsl:if test='$decl_set'>
    <xsl:call-template name='SubSectionHead'>
      <xsl:with-param name='subsection_name'><xsl:value-of select='$subsection_name'/></xsl:with-param>
    </xsl:call-template>
        
    <xsl:for-each select='$decl_set'>
      <xsl:sort select='@name'/>
      
      <xsl:apply-templates select="." mode="decl-anchor"/>
      <h3><xsl:value-of select='@name'/></h3>
      <xsl:apply-templates select='.' mode='decl-detail'/>
      <blockquote>
        <xsl:choose>
          <xsl:when test="formal-parameters/receiver-decl">
            <xsl:apply-templates select="oberon-doc"/>
            <xsl:apply-templates select="." mode="redefined-procs"/>
          </xsl:when>

          <xsl:otherwise>
            <xsl:apply-templates select="oberon-doc"/>
          </xsl:otherwise>
        </xsl:choose>
      </blockquote>
      <xsl:if test='position() != count($decl_set)'><hr/></xsl:if>
    </xsl:for-each>
  </xsl:if>
</xsl:template>

<!-- Class Detail; Parameter: $class_name -->
<xsl:template name="ClassDetail">
  <xsl:variable name="class_name" select="@name"/>
  
  <xsl:for-each select='type-decl'>
    <xsl:apply-templates select="." mode="decl-anchor">
      <xsl:with-param name='prefix'>_detail__</xsl:with-param>
    </xsl:apply-templates>
  </xsl:for-each>

  <xsl:call-template name='SectionHead'>
    <xsl:with-param name='section_name'>Class Detail: <xsl:value-of select="$class_name"/></xsl:with-param>
  </xsl:call-template>
  
  <xsl:call-template name="ClassDetailSection">
    <xsl:with-param name='subsection_name' select='"Field Detail"'/>
    <xsl:with-param name='decl_set' select='type-decl/type/record/field-decl'/>
  </xsl:call-template>
  
  <xsl:call-template name="ClassDetailSection">
    <xsl:with-param name='subsection_name' select='"Constructor Detail"'/>
    <xsl:with-param name='decl_set' select='procedure[not(formal-parameters/receiver-decl)]'/>
  </xsl:call-template>
  
  <xsl:call-template name="ClassDetailSection">
    <xsl:with-param name='subsection_name' select='"Method Detail"'/>
    <xsl:with-param name='decl_set' select='procedure[formal-parameters/receiver-decl]'/>
  </xsl:call-template>
    
  <xsl:call-template name="InsertSpace"/>
</xsl:template>

</xsl:stylesheet>
