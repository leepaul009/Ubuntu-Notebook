How to use ddrescue:
https://www.technibble.com/forums/threads/guide-to-using-ddrescue.48269/#post-379926


ddrescue:
https://www.gnu.org/software/ddrescue/
```
# Download the lastest ddrescue
wget http://mirror.kumi.systems/gnu/ddrescue/ddrescue-1.25.tar.lz

# ex. use http://mirrors.aliyun.com/ubuntu to install lzip
sudo apt-get install lzip

lzip -cd ddrescue-1.25.tar.lz | tar -xf -
cd ddrescue-1.25
./configure
make
make check
(sudo) make install


lsblk -o name,label,size,fstype,model


# Rescue the most important part of the disc first.
(sudo) ddrescue -i0 -s50MiB /dev/sdc hdimage mapfile
(sudo) ddrescue -i0 -s1MiB -d -r3 /dev/sdc hdimage mapfile

# Then rescue some key disc areas.
(sudo) ddrescue -i30GiB -s10GiB /dev/sdc hdimage mapfile
(sudo) ddrescue -i230GiB -s5GiB /dev/sdc hdimage mapfile

# Now rescue the rest (does not recopy what is already done).
(sudo) ddrescue /dev/sdc hdimage mapfile
(sudo) ddrescue -d -r3 /dev/sdc hdimage mapfile
```

other:
https://developer.aliyun.com/article/469865
