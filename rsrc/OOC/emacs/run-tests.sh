#!/bin/sh
FILES=tests/*.Mod

rm -f tests/*.indent
emacs -batch -q -l ./oberon2.el -l ./o2-indent.el -f ob2-indent-all-buffers $FILES
for i in $FILES; do
  diff -u $i `dirname $i`/`basename $i .Mod`.indent
done
