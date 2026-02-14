#!/bin/sh

TEMPDEB=config/packages.chroot/tmp.deb
PACKAGENAME=code
DEBURL="https://code.visualstudio.com/sha/download?build=stable&os=linux-deb-x64"

if ls config/packages.chroot/$PACKAGENAME*.deb; then
    echo "$PACKAGENAME already downloaded. Skipping."
else
    set -x
    wget -O $TEMPDEB $DEBURL
    dpkg-name $TEMPDEB
fi
