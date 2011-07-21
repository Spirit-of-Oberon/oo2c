#!/bin/sh

count=0
err_count=0
for i in wf/*.txt not-wf/*.txt; do
  rm -f test-output/$i
  # results should be the same, regardless if the scanner reports any errors
  $TEST_PROG --identity $i >test-output/$i 2>/dev/null
  if $DIFF $i test-output/$i; then
    echo "ok: $i"
  else
    err_count=`expr $err_count + 1`
    echo "failed: $i"
  fi
done

test $err_count = "0"
exit $?
