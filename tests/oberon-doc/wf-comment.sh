#!/bin/sh

count=0
err_count=0
for i in wf-comment/*.texi; do
  rm -f test-output/$i
  if $TEST_PROG --xml --comment $i >test-output/$i.xml; then
    if $DIFF "`dirname $i`/out-xml/`basename $i`".xml test-output/$i.xml; then
      # XML output is fine; now check the plain text output
      if $TEST_PROG --text --comment $i >test-output/$i.txt; then
	if $DIFF "`dirname $i`/out-text/`basename $i`.txt" test-output/$i.txt; then
	  echo "ok: $i"
	else
	  err_count=`expr $err_count + 1`
	  echo "failed: $i"
	fi
      else
	err_count=`expr $err_count + 1`
	echo "failed: $i (conversion to text: exit code is non-zero)"
      fi
    else
      err_count=`expr $err_count + 1`
      echo "failed: $i"
    fi
  else
    err_count=`expr $err_count + 1`
    echo "failed: $i (conversion to XML: exit code is non-zero)"
  fi
done

test $err_count = "0"
exit $?
