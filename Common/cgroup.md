### preparation

Ref: https://zhuanlan.zhihu.com/p/121588317

我们可以通过查看 /proc/cpuinfo 的内容来确定 CPU 的某些信息：
```
$ cat /proc/cpuinfo
```
processor : 表示核心的编号，但这不是物理 CPU 的核心，更确切地可以称之为**逻辑核编号。
physical id : 表示当前逻辑核所在的物理 CPU 的核心，也是从 0 开始编号，这里表示这个逻辑核在第 7 个 物理 CPU 上。
core id : 如果这个值大于 0，你就要注意了，你的服务器可能开启了超线程。如果启用了超线程，每个物理 CPU 核心会模拟出 2 个线程，也叫逻辑核（和上面的逻辑核是两回事，只是名字相同而已）。如果你想确认服务器有没有开启超线程，可以通过下面的命令查看：
```
$ cat /proc/cpuinfo | grep -e "core id" -e "physical id"
```
如果 physical id 和 core id 皆相同的 processor 出现了两次，就可以断定开启了超线程。显然我的服务器没有开启。

NUMA 架构,  NUMA（Non-uniform memory access），即非统一内存访问架构
```
numactl --hardware
```

### How to use cgroup
Ref: https://www.lesbonscomptes.com/recoll/faqsandhowtos/cgroups_instructions.html












