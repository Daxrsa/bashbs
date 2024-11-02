#!/bin/bash

usage() {
  >&2 echo "Usage: $0 <project>"
  return 0
}

pname=$1
pdir="./${pname}"
tdir=
#tdir=/var/bash.bs/templates

if [ -z "$pname" ]; then
    usage
    exit 1
elif ! [ -d "$tdir" ]; then
    >&2 echo "Unable to find template dir: $tdir"
    exit 2
elif [ -d "$pdir" ]; then
    >&2 echo "Project dir already exists: $pdir"
    exit 3
fi

cur="$PWD"
cd $tdir
echo "Please select a template"
select x in *; do
    template="$x"
    break
done