# Nvidia driver and cuda installation
```
Menu:
1. Preprocessing (nvidia driver&cuda install)
2. Installtion (nvidia driver&cuda install)
3. Ubuntu login loop (Bug fix)
4. Ubuntu login with black screen (Bug fix)
...
```
## 1. Preprocessing (nvidia driver&cuda install)
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
## 2. Installation (nvidia driver&cuda install)
### 2.1 Install nvidia driver
```
sudo chmod +x NVIDIA-Linux-x86_64-440.36.run
sudo service lightdm stop
# sudo ./NVIDIA-Linux-x86_64-440.36.run --dkms  -no-x-check -no-nouveau-check -no-opengl-files
sudo ./NVIDIA-Linux-x86_64-440.36.run  -no-x-check -no-nouveau-check -no-opengl-files
# if it is said there is already driver installed, we could still install (checked)
# for the option "nvidia-xconfig utility", you could select yes
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
__________________________________________________________________________
## 3. Ubuntu login loop (Bug fix)
### 3.1 solution for ubuntu 18.04 (not sure if it's available for ubuntu20)
#### Refer to https://forums.developer.nvidia.com/t/ubuntu-18-04-login-loop-after-installing-nvidia-driver/81280
```
$sudo prime-select nvidia

# Add “nogpumanager” kernal boot parameter, GRUB_CMDLINE_LINUX_DEFAULT=“nogpumanager quiet splash”
$sudo vim /etc/default/grub
$sudo update-grub

$lshw -c display | grep product
# Output:
       product: GP102 [GeForce GTX 1080 Ti]
       product: GP102 [GeForce GTX 1080 Ti]
       product: ASPEED Graphics Family
       product: GP102 [GeForce GTX 1080 Ti]
       product: GP102 [GeForce GTX 1080 Ti]
$lshw -c display | grep bus
# Output:
       bus info: pci@0000:02:00.0
       capabilities: vga_controller bus_master cap_list rom
       bus info: pci@0000:03:00.0
       capabilities: vga_controller bus_master cap_list rom
       bus info: pci@0000:06:00.0
       capabilities: vga_controller bus_master cap_list rom
       bus info: pci@0000:82:00.0
       capabilities: vga_controller bus_master cap_list rom
       bus info: pci@0000:83:00.0
       capabilities: vga_controller bus_master cap_list rom
$sudo vim /etc/X11/xorg.conf
# Wirte into following content that Identifier and BusID are refered to previous output  
        Section "Device"
            Identifier     "ASPEED"
            Driver         "modesetting"
            BusID          "PCI:6:0:0"
        EndSection
# Then reboot
```
### 3.2 Different solution for ubuntu 16.04 as that has a different GL library layout
```
# 1. Purge all nvidia driver packages so the internal Aspeed graphics works again
sudo apt purge nvidia*
sudo apt-get autoremove --purge cuda
# 2. Modify system file.
sudo vim /etc/modprobe.d/blacklist.conf
sudo vim /etc/default/grub
lsmod |grep nouveau
# 3. Download the .run installer driver https://http.download.nvidia.com/XFree86/Linux-x86_64/
# 4. Install nvidia dirvier with options, "--dkms --no-opengl-files"
sudo chmod +x NVIDIA-Linux-x86_64-440.36.run
sudo service lightdm stop
sudo ./NVIDIA-Linux-x86_64-440.36.run -no-x-check -no-nouveau-check -no-opengl-files
```
__________________________________________________________________________
## 4. Ubuntu login with black screen (Bug fix)
### or named "Ubuntu Freezing at Boot Screen"
### 4.1 Fix to login
```
Print 'e' in ubuntu advance option.
Add 'nomodeset' at the line that starts with 'Linux', ex. 'quiet splash $vt_handoff nomodeset'.
```
### 4.2 Update grub file for permanet fix:
```
# Add “nogpumanager” kernal boot parameter, GRUB_CMDLINE_LINUX_DEFAULT=“nogpumanager quiet splash”
$sudo vim /etc/default/grub
$sudo update-grub
```
## 5. cudnn install
```
$ tar -xzvf cudnn-x.x-linux-x64-v8.x.x.x.tgz
# Copy the following files into the CUDA Toolkit directory.
$ sudo cp cuda/include/cudnn*.h /usr/local/cuda/include 
$ sudo cp -P cuda/lib64/libcudnn* /usr/local/cuda/lib64 
$ sudo chmod a+r /usr/local/cuda/include/cudnn*.h /usr/local/cuda/lib64/libcudnn*
```
