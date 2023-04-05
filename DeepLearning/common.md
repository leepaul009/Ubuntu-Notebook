
### docker
```
# speed up docker images download
https://cr.console.aliyun.com/cn-hangzhou/instances/mirrors

# we could use image
sudo docker save -o /home/sammy/your_image.tar your_image_name
```

### nvidia container-toolkit
```
# https://docs.nvidia.com/datacenter/cloud-native/container-toolkit/install-guide.html#installing-on-ubuntu-and-debian
# 安装完nvidia-cuda之后，再创建容器时加上--gpus all，即可在容器内调用cuda
# issue: after apt update it emit error with "E: 软件源 https://nvidia.github.io/libnvidia-container/stable/ubuntu18.04/amd64/ / 的选项 Signed-By 中含有互相冲突的值：/usr/share/keyrings/nvidia-container-toolkit-keyring.gpg != E: 无法读取源列表":
# go to /etc/apt/sources.list.d and remove all, then apt update work
```
### basic
```
# start with bash
sudo docker run -it --runtime=nvidia --gpus all a7a1861d2150 /bin/bash
# start with a share folder
sudo docker run -it -v=/home/megvii/workspace/documents/ScanNet:/home/megvii/workspace/documents/ScanNet --runtime=nvidia --gpus all a7a1861d2150 /bin/bash
# check if nvidia-smi work
sudo docker run --rm --runtime=nvidia --gpus all a7a1861d2150 nvidia-smi
```






```
1. 查看所有镜像
docker images
2. 查找镜像
docker search XXXimage
3. 下载镜像
docker pull XXXimages:tag
4. 删除镜像
docker rmi XXXimages:ta
5. 启动容器
docker run -it image:tag /bin/bash
6. 退出容器
exit
7. 查看正在运行的容器
docker p
8. 进入正在运行的容器
docker attach container_ID
9. 查看已停止运行的容器
docker ps -a
10. 启动已停止的容器
docker start container_ID
11. 停止容器
docker stop container_ID
12. 重启已停止容器
docker restart container_I
13. 退出容器终端（但不停止）
docker exec
14. 更新镜像
先用镜像创建容器

docker run -it image:tag /bin/bash
在容器内操作

然后commit提交容器副本创建新的镜像

docker commit -m='description' -a='author' container_ID author/image:tag2 
```
