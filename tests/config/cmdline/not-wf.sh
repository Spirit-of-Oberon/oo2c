#!/bin/sh

SUFFIX=""

err=0
for i in not-wf/*.sh; do
  rm -f test-output/$i$SUFFIX.err
  if . $i >test-output/$i$SUFFIX.err; then
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
