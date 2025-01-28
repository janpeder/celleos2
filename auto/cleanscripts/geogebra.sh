#!/bin/sh

INSTALLPATH=config/includes.chroot_after_packages/opt
LOGOINSTALLPATH=config/includes.chroot_after_packages/usr/share/pixmaps

echo "Cleaning Geogebra"
set -x
rm -rf $INSTALLPATH/geogebra
rm -rf $LOGOINSTALLPATH/geogebra.png
