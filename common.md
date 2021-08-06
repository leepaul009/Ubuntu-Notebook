### Ownership and access right:
#### access right:
```
sudo chmod -R 755 folder
```
#### make the current user ownership everything inside the folder (and the folder itself):
```
sudo chown -R $USER ~/folder
sudo chown -R <username>:<group> <directory>
# use the default group for that user
sudo chown -R $USER: ~/folder
# change only the group
chown :<group> <file>
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
