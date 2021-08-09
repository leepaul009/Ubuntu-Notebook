# auto mount disk
```
sudo fdisk -l

# find the UUID
sudo blkid

# create a mount point
sudo mkdir /data

# change the group ownership of that directory, so that users can access it
sudo groupadd data
sudo usermod -aG data USERNAME (Where USERNAME is the name of the user to be added)
sudo chown -R :data /data

# automount entry
sudo vim /etc/fstab
UUID=14D82C19D82BF81E /data    auto nosuid,nodev,nofail,x-gvfs-show 0 0
```
# Breaking that line down, we have:
UUID=14D82C19D82BF81E - is the UUID of the drive. You don't have to use the UUID here. You could just use /dev/sdj, but it's always safer to use the UUID as that will never change (whereas the device name could).
/data - is the mount point for the device.
auto - automatically mounts the partition at boot 
nosuid - specifies that the filesystem cannot contain set userid files. This prevents root escalation and other security issues.
nodev - specifies that the filesystem cannot contain special devices (to prevent access to random device hardware).
nofail - removes the errorcheck.
x-gvfs-show - show the mount option in the file manager. If this is on a GUI-less server, this option won't be necessary.
0 - determines which filesystems need to be dumped (0 is the default).
0 - determine the order in which filesystem checks are done at boot time (0 is the default).

```
# testing the entry 
sudo mount -a
# if you see no errors, the fstab entry is correct and you're safe to reboot
```


# format disk
https://www.howtogeek.com/442101/how-to-move-your-linux-home-directory-to-another-hard-drive/
```
# check partition
lsblk
# To display a list containing file system information, add the -f option:
lsblk -f
# The general syntax for formatting disk partitions in Linux is:
mkfs [options] [-t type fs-options] device [size]
sudo mkfs -t ext4 /dev/sdf

```

