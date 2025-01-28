#!/bin/sh

TEMPDEB=config/packages.chroot/tmp.deb
PACKAGENAME=ideamaker
DEBURL=https://download.raise3d.com/ideamaker/release/4.3.3/ideaMaker_4.3.3.6560-ubuntu_amd64.deb

if ls config/packages.chroot/$PACKAGENAME*.deb; then
    echo "$PACKAGENAME already downloaded. Skipping."
else
    set -x
    # Download IdeaMaker:
    wget -O $TEMPDEB $DEBURL
    dpkg-name $TEMPDEB
fi
