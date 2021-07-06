
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
