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

#### compress/uncompress file: 
```
# compress:
tar cvfz target.tar.gz /source

# compress file with password
tar -czvf - ./files | openssl des3 -salt -k {password} -out files.tar.gz

# uncompress file with password
openssl des3 -d -k {password} -salt -in files.tar.gz | tar xzvf -
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
