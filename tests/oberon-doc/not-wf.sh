#!/bin/sh

err=0
for i in not-wf/*.texi; do
  rm -f test-output/$i test-output/$i.err
  if $TEST_PROG $i >test-output/$i 2>test-output/$i.err; then
    err=1
    echo "failed: $i (exit code is zero)"
  else
    if $DIFF "`dirname $i`/out-err/`basename $i`.err" test-output/$i.err; then
      echo "ok: $i"
    else
      err=1
      echo "failed: $i"
    fi
  fi
done

exit $err
