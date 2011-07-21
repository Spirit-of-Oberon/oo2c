#!/bin/sh

err_count=0
for i in wf/src/*.Mod; do
  module=`basename $i .Mod`
  rm -f "wf/oocdoc/xml/${module}_symtab.xml"
  #echo $TEST_PROG -r wf --names-only-xml "$module"
  if $TEST_PROG -r wf --names-only-xml "$module" >/dev/null; then
    if $DIFF "wf/out-xml/names-only/${module}_symtab.xml" "wf/oocdoc/xml/${module}_symtab.xml"; then
      echo "ok: $i"
    else
      err_count=`expr $err_count + 1`
      echo "failed: $i"
    fi
  else
    err_count=`expr $err_count + 1`
    echo "failed: $i (exit code is non-zero)"
  fi
done

test $err_count = "0"
exit $?
