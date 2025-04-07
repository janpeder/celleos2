#!/bin/sh

# Make includes.binary directory in case it doesn't exist
# Needed by steps below..
mkdir -p config/includes.binary

# Build user manual and place it on medium
make -C brukermanual
cp brukermanual/celleos2_brukermanual.pdf config/includes.binary/
