#!/bin/sh

SUFFIX=""

count=0
err_count=0
for i in not-wf/*.xml; do
  rm -f test-output/$i$SUFFIX test-output/$i$SUFFIX.err
  if $TEST_PROG $i 2>test-output/$i$SUFFIX.err; then
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
