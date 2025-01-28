#!/bin/sh

PACKAGENAME=ideamaker

echo "Cleaning $PACKAGENAME"
set -x
rm -f config/packages.chroot/$PACKAGENAME*
