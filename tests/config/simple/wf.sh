#!/bin/sh

err=0
for i in wf/*.sh; do
  rm -f test-output/$i
  if . $i >test-output/$i; then
    if $DIFF "`dirname $i`/out/`basename $i`" test-output/$i; then
      echo "ok: $i"
    else
      err=1
      echo "failed: $i"
    fi
  else
    err=1
    echo "failed: $i (exit code is non-zero)"
  fi
done

exit $err
