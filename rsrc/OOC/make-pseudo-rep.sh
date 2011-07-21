#!/bin/sh

BASEDIR=/tmp/basedir
OOWHEREIS=Oowhereis

while true; do
    if [ "$1" = "--basedir" ]; then
	BASEDIR="$2"
	shift
    else
	break
    fi
    shift
done

if [ $# != 2 ]; then
    echo "usage: $0 [--basedir <base-dir>] <module-name> <repository-name>"
    exit 1
fi
MODULE="$1"
REPOSITORY="$2"
LINK_NAME="$BASEDIR/$REPOSITORY/src"

if [ -d "$LINK_NAME" ]; then
    : #echo "$0: $LINK_NAME exists"
else
    MODULE_PATH="`$OOWHEREIS $MODULE.Mod`"
    if echo "$MODULE_PATH" | grep '^/' >/dev/null; then
	ABS_MODULE_PATH="$MODULE_PATH"
    else
	ABS_MODULE_PATH="`pwd`/$MODULE_PATH"
    fi
    MODULE_DIR="`dirname "$ABS_MODULE_PATH"`"
    
    mkdir -p -m 755 "`dirname "$LINK_NAME"`"
    #echo "$0: linking $LINK_NAME -> $MODULE_DIR"
    ln -s "$MODULE_DIR" "$LINK_NAME"
fi
