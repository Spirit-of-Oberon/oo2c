#!/bin/sh

err_count=0
for i in not-wf/src/*.Mod; do
  module=`basename $i .Mod`
  rm -f "wf/oocdoc/xml/${module}_symtab.xml" test-output/not-wf/$module.err
  #echo $TEST_PROG -r not-wf --resolve-names-xml "$module"
  if $TEST_PROG -r not-wf --resolve-names-xml "$module" >/dev/null 2>test-output/not-wf/$module.err; then
    err_count=`expr $err_count + 1`
    echo "failed: $i (exit code is zero)"
  else
    if $DIFF "not-wf/out-err/$module.err" test-output/not-wf/$module.err; then
      echo "ok: $i"
    else
      err_count=`expr $err_count + 1`
      echo "failed: $i"
    fi
  fi
done

test $err_count = "0"
exit $?
