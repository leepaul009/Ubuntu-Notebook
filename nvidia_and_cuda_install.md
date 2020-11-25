# uninstall nvidia and cuda if installed
$sudo apt purge nvidia*
$sudo apt-get autoremove --purge cuda
# or:
$sudo /usr/local/cuda-11.1/bin/cuda-uninstaller
$sudo /usr/bin/nvidia-uninstall

# Create a file at /etc/modprobe.d/blacklist-nouveau.conf with the following contents:
# Or in /etc/modprobe.d/blacklist.conf
$blacklist nouveau
$options nouveau modeset=0
# Regenerate the kernel initramfs:
$sudo update-initramfs -u



sudo vim /etc/default/grub

lsmod |grep nouveau

sudo chmod +x NVIDIA-Linux-x86_64-440.36.run
sudo service lightdm stop
# sudo ./NVIDIA-Linux-x86_64-440.36.run --dkms  -no-x-check -no-nouveau-check -no-opengl-files
sudo ./NVIDIA-Linux-x86_64-440.36.run  -no-x-check -no-nouveau-check -no-opengl-files

# Option 1: install from .deb
sudo dpkg -i cuda-repo-ubuntu1604-10-1-local-10.1.168-418.67_1.0-1_amd64.deb
sudo apt-key add /var/cuda-repo-10-1-local-10.1.168-418.67/7fa2af80.pub
sudo apt-get update
sudo apt-get install cuda

# Option 2: install from .run
sudo sh cuda_10.1.105_418.39_linux.run  --no-opengl-libs
