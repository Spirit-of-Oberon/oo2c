#!/bin/sh

count=0
err_count=0
for i in log/*.log; do
  file=`basename $i .log`
  test_out=test-output/$file.out
  test_log=test-output/$file.log
  rm -f $test_log $test_out
  $TEST_PROG $file >$test_out 2>$test_log
  if $DIFF $i $test_log; then
    echo "ok: $i"
  else
    err_count=`expr $err_count + 1`
    echo "failed: $i"
  fi
done

test $err_count = "0"
exit $?
