### Ownership and access right:

#### kill process
```
# kill all python process
ps -ef | grep "python" | awk '{print $2}' | xargs sudo kill
```

#### access right:
```
sudo chmod 755 folder
# add "-R" to influence all the folders or files
```
#### make the current user ownership everything inside the folder (and the folder itself):
```
sudo chown $USER ~/folder
sudo chown <username>:<group> <directory>
# use the default group for that user
sudo chown $USER: ~/folder
# change only the group
chown :<group> <file>
# add "-R" to influence all the folders or files
```

#### copy link rather than copy the files linked
```
rsync --progress -avhe ssh /usr/local/  XXX.XXX.XXX.XXX:/BackUp/usr/local/
```

#### compress/uncompress file: 
```
# compress:
tar cvfz target.tar.gz /source

# compress file with password
tar -czvf - ./files | openssl des3 -salt -k {password} -out files.tar.gz

# uncompress file with password
openssl des3 -d -k {password} -salt -in files.tar.gz | tar xzvf -

# compress with multi-core and big compress reate
tar --use-compress-program=pigz -cvf FILE_NAME.tar DIR_OR_NAME
```

#### symlink: create a "link" refer to original file or folder "source" 
```
ln -s /source /link
```

### install ohmyz https://ohmyz.sh/#install (auto-suggestion function for terminal)
```
# first, install zsh
sudo apt install zsh

# (need to install zsh before following steps) install:
sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"
# old:sh -c "$(curl -fsSL https://raw.github.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"

# install auto-suggestion function:
# details in https://github.com/zsh-users/zsh-autosuggestions/blob/master/INSTALL.md
git clone https://github.com/zsh-users/zsh-autosuggestions ${ZSH_CUSTOM:-~/.oh-my-zsh/custom}/plugins/zsh-autosuggestions
# plugins=(git zsh-autosuggestions)

# change theme by editing file ~/.zshrc
ZSH_THEME="ys"

# 转到zsh，服务器需重新ssh：
chsh -s $(which zsh)
# 恢复到正常的shell：
chsh -s /bin/bash

# Q&A
# 1) zsh: command not found: ???
vim ~/.zshrc
# type follwoing codes under "#User configuration"
source ~/.bash_profile
# or
source ~/.profile
```
### Ohmyz Manual Installation
```
# 1. Clone The Repository
git clone https://github.com/ohmyzsh/ohmyzsh.git ~/.oh-my-zsh
# 2. Optionally, Backup Your Existing ~/.zshrc File
cp ~/.zshrc ~/.zshrc.orig
# 3. Create A New Zsh Configuration File
# You can create a new zsh config file by copying the template that we have included for you.
cp ~/.oh-my-zsh/templates/zshrc.zsh-template ~/.zshrc
# 4. Change Your Default Shell
chsh -s $(which zsh)
```

### strongth SSH connection:
```
ssh -o ServerAliveInterval=30 {uid@ip}
```
### How to automate SSH login with password?
```
$ ssh-keygen -t rsa -b 2048
Generating public/private rsa key pair.
Enter file in which to save the key (/home/username/.ssh/id_rsa): 
Enter passphrase (empty for no passphrase): 
Enter same passphrase again: 
Your identification has been saved in /home/username/.ssh/id_rsa.
Your public key has been saved in /home/username/.ssh/id_rsa.pub.

$ ssh-copy-id id@server
id@server's password: 

$ ssh id@server
# check if ssh-rsa existed in .ssh/authorized_keys
```

### How to use ssh key to login remote server with vscode?
```
# Here is how I managed to connect to the remote VM:

# Access normally the remote VM from MobaXterm or other ssh client to verify it's working.
# Generate a ssh key:
ssh-keygen -t rsa
# Install the public key in the remote server:
ssh-copy-id -i $HOME/.ssh/id_rsa.pub <username>@<ipaddress>
# Make sure that you can access the VM from the command line using ssh.
# Install the Remote - SSH extension on VSCode.
# Press F1 > search and click Remote-SSH: connect to a host > click Add New SSH Host
# Write ssh <username>@<ipaddress> and press Enter.
# Choose the config file generated with the ssh key.
# You can now connect to the remote server.
# That should do it, so I am going to go ahead and close the thread.
```
### setup ssh in ubuntu
```
sudo apt install openssh-server
# if can not install openssh-server because of depencies we can run: sudo apt-get remove --purge openssh-client
sudo systemctl status ssh
 sudo ufw allow ssh
```

### samba server
```
# install with:
sudo apt update
sudo apt install samba
# check status:
sudo systemctl status smbd

sudo vim /etc/samba/smb.conf
# write into
  "
  [my share]
  path=/home/lqurszh
  valid users=lqurszh
  browseable=yes
  writable=yes
  "
# Add <user> (Windows login name) to Samba: 'sudo smbpasswd -a <user>'
sudo smbpasswd -a lqurszh

# sudo service smbd restart
sudo systemctl restart smbd.service nmbd.service
```

### 安装搜狗输入法
```
sudo apt update
# 安装输入法系统：
sudo apt-get install fcitx
# 设置
 # 设置减速输入法系统为 fcitx
 # 添加或删除语言：添加 中文简体，英文
 # 应用到整个系统，重启
# 设置fcitx开机自启动
sudo cp /usr/share/applications/fcitx.desktop /etc/xdg/autostart
# 卸载ibus输入法系统
sudo apt purge ibus
# 下载安装搜狗输入法
sudo dpkg -i sogoupinyin_4.2.1.145_amd64.deb
# 安装依赖
sudo apt install libqt5qml5 libqt5quick5 libqt5quickwidgets5 qml-module-qtquick2 libgsettings-qt1
# 重启
sudo reboot
# 右上角的语音button，进入pannel；点击左下角+号添加搜狗输入法；调整优先级
# 使用快捷键 Ctrl + Space 或 Shift 切换
```
