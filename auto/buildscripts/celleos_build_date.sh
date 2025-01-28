# Make includes.binary directory in case it doesn't exist
# Needed by steps below..
mkdir -p config/includes.binary

# Make note of build date and place in /root and on install medium
date > config/includes.chroot_after_packages/root/celleos_build_date
cp config/includes.chroot_after_packages/root/celleos_build_date config/includes.binary/
