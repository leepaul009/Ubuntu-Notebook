### Ownership and access right:
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

#### compress file: 
```
tar cvfz target.tar.gz /source
```

#### symlink: create a "link" refer to original file or folder "source" 
```
ln -s /source /link
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

#### samba server
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
