#!/bin/sh

# Make bin directory in case it doesn't exist
# Needed by steps below..
mkdir -p config/includes.chroot_after_packages/usr/bin

# Build user manual and place it on medium
make -C celleos_usbguard_generate_policy_hub_hid
cp celleos_usbguard_generate_policy_hub_hid/celleos_usbguard_generate_policy_hub_hid config/includes.chroot_after_packages/usr/bin/
