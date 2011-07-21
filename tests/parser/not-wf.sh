#!/bin/sh

count=0
err_count=0
for i in not-wf/*.Mod; do
  count=`expr $count + 1`
  
  rm -f test-output/$i test-output/$i.err
  if $TEST_PROG $i >test-output/$i 2>test-output/$i.err; then
    err_count=`expr $err_count + 1`
    echo "failed: $i (exit code is zero)"
  else
    if $DIFF "`dirname $i`/out-err/`basename $i`.err" test-output/$i.err; then
      echo "ok: $i"
    else
      err_count=`expr $err_count + 1`
      echo "failed: $i"
    fi
  fi
done

test $err_count = "0"
exit $?
