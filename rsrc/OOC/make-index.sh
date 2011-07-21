#!/bin/sh

f="index.html"

echo "<body bgcolor='white'>" >$f
old_package=""
files=`find */oocdoc/html -type f -name "*.html" | sort`
for i in $files; do
  package=`echo $i | sed -e "s:/.*$::g"`
  module=`echo $i | sed -e "s:^.*/oocdoc/html/::g" -e "s#/#:#g" -e "s:.html$::g"`
  if test "$package" != "$old_package"; then
    if test -n "$old_package"; then
      echo "</table>" >>$f
    fi
    echo "<h2>$package</h2>" >>$f
    echo "<table>" >>$f
    old_package="$package"
  fi
  echo "    <tr><td><a href='$i'>$module</a></td></tr>" >>$f
done
echo "</table>" >>$f
echo "</body>" >>$f
