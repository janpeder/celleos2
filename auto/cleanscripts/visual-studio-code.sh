#!/bin/sh

PACKAGENAME=code

echo "Cleaning $PACKAGENAME"
set -x
rm -f config/packages.chroot/$PACKAGENAME*
