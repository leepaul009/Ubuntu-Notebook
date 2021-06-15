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
make install
```

other:
https://developer.aliyun.com/article/469865
