# CelleOS 2

Variant of Debian Linux for use in prison cells by prisoners without supervision. Focus is on security and education.

Features:
* Quick and easy install with USB stick and no internet, with minimal user interaction. Reason: Minimize work and minimize possible mistakes during installations.
* Blocking of all USB devices exept keyboard, mice and whitelisted USB sticks (mass storage). This is done with the USBGuard software.
* Blocking of all internet using firewall (iptables).
* Comes with software suited for educational purposes.

### Build instructions
The following steps describes how to build a ISO image for installing celleos. You need to be on a Debian system for this to work, as it is based on Debian Live Build. You need to be connected to the Internet for this to work.

First, install the required packages (as root):
```
apt update
apt install live-build git build-essential texlive texlive-plain-generic texlive-pictures libgtk-4-dev
```

Then, check out this repository from github:
```
git clone https://github.com/janpeder/celleos2
```

Now 'cd' into the directory you just cloned:
```
cd celleos2
```

Start the build process by typing (lb build must be run as root.):
```
lb config
lb build
```
This step may take some time - perhaps 10 - 30 minutes. This is because a lot of data packages will be downloaded and processed. If all goes well, a file named 'live-image-amd64.hybrid.iso' will be created.

The final step will be to write the file 'live-image-amd64.hybrid.iso' to a USB stick. I prefer to use the command 'dd' for this. Before we can write the image, we need to know the device file for the USB stick. One way to find the correct device file is by typing 'dmesg' in the terminal just after plugging the USB stick into the computer. To write the image to the stick, assuming the stick is /dev/sdb, type (as root):
```
dd if=live-image-amd64.hybrid.iso of=/dev/sdb bs=4M
```
Writing the image to the USB stick takes some time, so be patient. When it is done, type
```
sync
```
and remove the USB stick.

### Testing the image with Qemu

To test the image with Qemu, first install Qemu (as root):
```
apt update
apt install qemu-kvm qemu-utils
```
Then, create a virtaul disk to install Celleos on, e.g:
```
qemu-img create ~/disk.img 16G
```
To start installing Celleos on your virtual disk, run:
```
kvm -m 1G -cdrom live-image-amd64.hybrid.iso -drive file=~/disk.img
```
Good luck!
