#!/bin/sh

err=0
for i in not-wf/*.txt; do
  rm -f test-output/$i test-output/$i.err
  if $TEST_PROG $i >test-output/$i 2>test-output/$i.err; then
    err=1
    echo "failed: $i (exit code is zero)"
  else
    if $DIFF "`dirname $i`/out-err/`basename $i`.err" test-output/$i.err &&
       $DIFF "`dirname $i`/out-xml/`basename $i`" test-output/$i; then
      echo "ok: $i"
    else
      err=1
      echo "failed: $i"
    fi
  fi
done

exit $err
