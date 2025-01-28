#!/bin/sh

INSTALLPATH=config/includes.chroot_after_packages/opt
LOGOINSTALLPATH=config/includes.chroot_after_packages/usr/share/pixmaps
DOWNLOADURL=https://download.geogebra.org/package/linux-port
LOGOURL=https://raw.githubusercontent.com/geogebra/images/refs/heads/main/ggb-logo-64x64-transparent.png

if ls $INSTALLPATH/geogebra; then
    echo "Geogebra already downloaded. Skipping."
else
    set -x
    # Download Geogebra:
    wget $DOWNLOADURL
    mkdir -p $INSTALLPATH
    tar xvfj linux-port -C $INSTALLPATH
    rm linux-port
    mv $INSTALLPATH/GeoGebra* $INSTALLPATH/geogebra
fi

if ls $LOGOINSTALLPATH/geogebra.png; then
    echo "Geogebra icon already downloaded. Skipping."
else
    set -x
    # Download Geogebra icon:
    wget $LOGOURL
    mkdir -p $LOGOINSTALLPATH
    mv ggb-logo-64x64-transparent.png $LOGOINSTALLPATH/geogebra.png
fi
