#!/bin/sh
resource_rep="../../"

err_count=0
for i in wf/src/M*.Mod; do
  module=`basename $i .Mod`
  #echo $TEST_PROG -r wf -r "$resource_rep" "$module"
  if $TEST_PROG -r wf -r "$resource_rep" "$module"; then
    if $DIFF "wf/out-xml/$module.xml" "wf/oocdoc/xml/$module.xml"; then
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
