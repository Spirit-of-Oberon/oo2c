#!/bin/sh

count=0
err_count=0
for i in wf/*.h; do
  rm -f test-output/$i
  if $TEST_PROG --preprocess --text $i >test-output/$i; then
    if $DIFF "`dirname $i`/out-h/`basename $i`" test-output/$i; then
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
