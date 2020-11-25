# Nvidia driver and cuda installation

### 1.1 Uninstall nvidia and cuda if installed with .deb files and "apt install"
```
$sudo apt purge nvidia*
$sudo apt-get autoremove --purge cuda
```
### or if installed with .run file:
```
$sudo /usr/local/cuda-11.1/bin/cuda-uninstaller
$sudo /usr/bin/nvidia-uninstall
```
### 1.2 Disabling Nouveau
```
# Create a file at /etc/modprobe.d/blacklist-nouveau.conf 
# or in /etc/modprobe.d/blacklist.conf with the following contents:
$blacklist nouveau
$options nouveau modeset=0
# Regenerate the kernel initramfs:
$sudo update-initramfs -u
# Reboot and check with the following cmd:
$lsmod |grep nouveau
```

### 1.3 Grub
```
sudo vim /etc/default/grub
```

### 2.1 Install nvidia driver
```
sudo chmod +x NVIDIA-Linux-x86_64-440.36.run
sudo service lightdm stop
# sudo ./NVIDIA-Linux-x86_64-440.36.run --dkms  -no-x-check -no-nouveau-check -no-opengl-files
sudo ./NVIDIA-Linux-x86_64-440.36.run  -no-x-check -no-nouveau-check -no-opengl-files
```
### 2.2 Install CUDA
#### 2.2.1 Option 1: install from .deb
```
sudo dpkg -i cuda-repo-ubuntu1604-10-1-local-10.1.168-418.67_1.0-1_amd64.deb
sudo apt-key add /var/cuda-repo-10-1-local-10.1.168-418.67/7fa2af80.pub
sudo apt-get update
sudo apt-get install cuda
```
#### 2.2.2 Option 2: install from .run
```
# in order to install nvidia driver
sudo service lightdm stop
sudo sh cuda_10.1.105_418.39_linux.run  --no-opengl-libs
```
#### 2.2.3 Update ~/.bashrc with following content (in case of cuda 10.1):
```
# set PATH for cuda 10.1 installation
if [ -d "/usr/local/cuda-10.1/bin/" ]; then
    export PATH=/usr/local/cuda-10.1/bin${PATH:+:${PATH}}
    export LD_LIBRARY_PATH=/usr/local/cuda-10.1/lib64${LD_LIBRARY_PATH:+:${LD_LIBRARY_PATH}}
fi
```
