# Nvidia driver and cuda installation
```
Menu:
1. Preprocessing (nvidia driver&cuda install)
2. Installtion (nvidia driver&cuda install)
3. Fix issue
```
## 1. Preprocessing (nvidia driver&cuda install)
### nvidia&CUDA
```
418.40.04+ (CUDA 10.1)	
440.33.01+ (CUDA 10.2)	
450.36.06+ (CUDA 11.0)	
450.80.02 (CUDA 11.1)	
460.27.04 (CUDA 11.2)	
465.19.01 (CUDA 11.3)	
470.42 (CUDA 11.4)
```
### 1.1 Uninstall nvidia and cuda
```
# approach 1: if installed with .deb files and "apt install"
$sudo apt purge nvidia*
$sudo apt-get autoremove --purge cuda

# approach 2: if installed with .run file:
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
# (dropped) sudo ./NVIDIA-Linux-x86_64-440.36.run --dkms  -no-x-check -no-nouveau-check -no-opengl-files
sudo ./NVIDIA-Linux-x86_64-XXX.XX.run
# for ubuntu 16.04:
    sudo ./NVIDIA-Linux-x86_64-440.36.run  -no-x-check -no-nouveau-check -no-opengl-files
# if it is said there is already driver installed, we could still install (checked)
# for the option "nvidia-xconfig utility", you could select yes
```
### 2.2 Install CUDA
#### 2.2.1 Approach 1: install from .deb
```
sudo dpkg -i cuda-repo-ubuntu1604-10-1-local-10.1.168-418.67_1.0-1_amd64.deb
sudo apt-key add /var/cuda-repo-10-1-local-10.1.168-418.67/7fa2af80.pub
sudo apt-get update
sudo apt-get install cuda
```
#### 2.2.2 Approach 2: install from .run
```
# in order to install nvidia driver
sudo service lightdm stop
sudo sh cuda_10.1.105_418.39_linux.run  --no-opengl-libs
```
#### 2.2.3 Update ~/.bashrc with following content (in case of cuda 10.1):
```
# set PATH for cuda 10.1 installation
if [ -d "/usr/local/cuda/bin/" ]; then
    export PATH=/usr/local/cuda/bin${PATH:+:${PATH}}
    export LD_LIBRARY_PATH=/usr/local/cuda/lib64${LD_LIBRARY_PATH:+:${LD_LIBRARY_PATH}}
fi
```

__________________________________________________________________________
## 3. Issue when installing nvidia driver

### 3.1 Ubuntu login loop (Bug fix)
Or other issue(after click "login" button, screen freezed)
#### 3.1.1 solution for ubuntu 18.04 (not sure if it's available for ubuntu20)
Even if you can not login in but you can access with ssh, and you will notice that GUI are using nvidia GPU. 
After fix this issue, OS doesn't use nvidia GPU for GUI any more.
Refer to https://forums.developer.nvidia.com/t/ubuntu-18-04-login-loop-after-installing-nvidia-driver/81280
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
# Update {Section "Device"} with following content. Identifier and BusID are refered to previous output  
        Section "Device"
            Identifier     "ASPEED"
            Driver         "modesetting"
            BusID          "PCI:6:0:0"
        EndSection
# Then reboot
```
#### 3.1.2 (Only for ubuntu 16.04) Different solution for ubuntu 16.04 as that has a different GL library layout
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

### 3.2 Ubuntu login with black screen (Bug fix)
or named "Ubuntu Freezing at Boot Screen"
#### 3.2.1 Fix to login
```
Print 'e' in ubuntu advance option.
Add 'nomodeset' at the line that starts with 'Linux', ex. 'quiet splash $vt_handoff nomodeset'.
```
#### 3.2.2 Update grub file for permanet fix:
```
# Add “nogpumanager” kernal boot parameter, GRUB_CMDLINE_LINUX_DEFAULT=“nogpumanager quiet splash”
$sudo vim /etc/default/grub
$sudo update-grub
```

### 3.3 Install nvidia driver with security boot
```
# create new MOK key 
    # approach 1 (recommended, work)
    sudo update-secureboot-policy --new-key
    # approach 2
    openssl req -config /usr/lib/shim/mok/openssl.cnf -subj "OSD MOK Signing Key" -new -x509 -newkey rsa:2048 -nodes -days 36500 -outform DER -keyout "MOK.priv" -out "MOK.der"
# then, files of "MOK key" will be generated on:
    /var/lib/shim-signed/mok/MOK.priv
    /var/lib/shim-signed/mok/MOK.der

# import MOK key
    # approach 1 (work)
    sudo mokutil --import /var/lib/shim-signed/mok/MOK.der
    # approach 2 (does not work: return a log of "No DKMS modules installed.")
    sudo update-secureboot-policy --enroll-key
# if use approach 1 to import MOK.der, it will let you input a "input password"(such as eya@@)

# Reboot and enroll the key in MokManager with the preset password during the import
    # when it was rebooting, a blue menu appeared asking to press any key, you should press. then a menu labbeled as "Perform MOK Management" appeared, there are the following 4 options:
        1. Continue boot
        2. Enroll Key
        3. Enroll Key from Disk
        4. Enroll Key from Hash
    # You should choose option 2, and input the "input password"(refer to previous step) and then continued to boot.
```


__________________________________________________________________________
## 6. cudnn install
```
$ tar -xzvf cudnn-x.x-linux-x64-v8.x.x.x.tgz
# Copy the following files into the CUDA Toolkit directory.
$ sudo cp cuda/include/cudnn*.h /usr/local/cuda/include 
$ sudo cp -P cuda/lib64/libcudnn* /usr/local/cuda/lib64 
$ sudo chmod a+r /usr/local/cuda/include/cudnn*.h /usr/local/cuda/lib64/libcudnn*
```
