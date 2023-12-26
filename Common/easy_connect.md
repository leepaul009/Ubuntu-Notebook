下载easyconnect：
```
https://vpn.suda.edu.cn/portal/#!/login
```
启动 easyconnect,报错：
```
# EasyConnect 在 ubuntu 下安装在此位置
> /usr/share/sangfor/EasyConnect/EasyConnect 
# Gtk-Message: 09:14:06.503: Failed to load module "canberra-gtk-module"
# 段错误 (核心已转储)

# 查看系统日志
> sudo dmesg
#[ 3516.131473] process 'share/sangfor/EasyConnect/EasyConnect' started with executable stack
#[ 3517.382624] traps: EasyConnect[10762] general protection fault ip:7f3f8ab57b09 sp:7ffd328c0f00 error:0 in libharfbuzz.so.0.20704.0[7f3f8ab3a000+91000]
#[ 3651.575201] traps: EasyConnect[11225] general protection fault ip:7fe0b2757b09 sp:7ffe4b97a210 error:0 in libharfbuzz.so.0.20704.0[7fe0b273a000+91000]
#[ 3664.693538] traps: EasyConnect[11305] general protection fault ip:7f2fc0d57b09 sp:7ffe030fa890 error:0 in libharfbuzz.so.0.20704.0[7f2fc0d3a000+91000]
```
其主要的原因就是 libpango 这个包在 Ubuntu 22.04 版本太高了，需要进行降版本处理。
为了防止修改系统库带来的风险，直接将相关的 so 库文件解压到 easyconnect 同目录下即可，即 /usr/share/sangfor/EasyConnect/ 下。
```
http://kr.archive.ubuntu.com/ubuntu/pool/main/p/pango1.0/
下载内容：
libpangocairo-1.0-0_1.40.14-1_amd64.deb
libpangoft2-1.0-0_1.40.14-1_amd64.deb
libpango-1.0-0_1.40.14-1_amd64.deb
```
步骤五：解压下载下来三个 deb 包，并获取每个 deb 包中 xxx.deb/data.tar.xz/usr/lib/x86_64-linux-gnu 下的所有内容
合并三个 deb 包下的动态库，显示如下：
```
libpango-1.0.so.0  
libpango-1.0.so.0.4000.14  
libpangocairo-1.0.so.0  
libpangocairo-1.0.so.0.4000.14  
libpangoft2-1.0.so.0  
libpangoft2-1.0.so.0.4000.14
```
步骤六：拷贝文件到 EasyConnect 的安装目录
```
sudo cp * /usr/share/sangfor/EasyConnect/
```
