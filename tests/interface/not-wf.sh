#!/bin/sh
resource_rep="../../"

err=0
for i in not-wf/src/M*.Mod; do
  module=`basename $i .Mod`
  out_file="test-output/not-wf/$module.Mod"
  rm -f test-output/$i
  rm -f test-output/$i test-output/$i.err
  #echo "$TEST_PROG -r not-wf -r "$resource_rep" $module >$out_file 2>$out_file.err"
  if $TEST_PROG -r not-wf -r "$resource_rep" "$module" >$out_file 2>$out_file.err; then
    err=1
    echo "failed: $i (exit code is zero)"
  else
    if $DIFF "not-wf/out-err/`basename $i`.err" $out_file.err; then
      echo "ok: $i"
    else
      err=1
      echo "failed: $i"
    fi
  fi
done

exit $err
