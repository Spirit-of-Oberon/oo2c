#!/bin/sh
out=/tmp/module.html
java org.apache.xalan.xslt.Process -IN "$1" -XSL /home/ooc-devel/ooc2/misc/xml/module-interface-to-html.xsl -OUT "$out"
echo "output send to $out"
