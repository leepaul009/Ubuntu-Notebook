## copy link rather than copy the files linked
```
rsync --progress -avhe ssh /usr/local/  XXX.XXX.XXX.XXX:/BackUp/usr/local/
```

## compress file
```
tar cvfz target.tar.gz /source
```

## symlink 
```
ln -s /source /link
```

## samba server
```
vim /etc/samba/smb.conf

# write into
"
[my share]
path=/home/deeplearning
valid users=deeplearning
browseable=yes
writable=yes
"

sudo service smbd restart
```
