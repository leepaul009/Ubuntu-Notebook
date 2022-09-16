### preparation

Ref: https://zhuanlan.zhihu.com/p/121588317

1. 我们可以通过查看 /proc/cpuinfo 的内容来确定 CPU 的某些信息：
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

2. NUMA 架构
这里需要涉及到一个概念叫 NUMA（Non-uniform memory access），即非统一内存访问架构。如果主机板上插有多块 CPU，那么就是 NUMA 架构。每块 CPU 独占一块面积，一般都有独立风扇。

一个 NUMA 节点包含了直连在该区域的 CPU、内存等硬件设备，通信总线一般是 PCI-E。由此也引入了 CPU 亲和性的概念，即 CPU 访问同一个 NUMA 节点上的内存的速度大于访问另一个节点的。

可以通过下面的命令查看本机的 NUMA 架构：
```
numactl --hardware
```
3. isolcpus
Linux 最重要的职责之一就是调度进程，而进程只是程序运行过程的一种抽象，它会执行一系列指令，计算机会按照这些指令来完成实际工作。从硬件的角度来看，真正执行这些指令的是中央处理单元，即 CPU。默认情况下，进程调度器可能会将进程调度到任何一个 CPU 核心上，因为它要根据负载来均衡计算资源的分配。

为了增加实验的明显效果，可以隔离某些逻辑核心，让系统默认情况下永远不会使用这些核心，除非我指定某些进程使用这些核心。要想做到这一点，就要使用到内核参数 isolcpus 了，例如：如果想让系统默认情况下不使用逻辑核心 2，3 和 4，可以将以下内容添加到内核参数列表中：
```
isolcpus=1,2,3
# Or
isolcpus=1-3
```
对于 CnetOS 7 来说，可以直接修改 /etc/default/grub：
```
$ cat /etc/default/grub

GRUB_TIMEOUT=5
GRUB_DISTRIBUTOR="$(sed 's, release .*$,,g' /etc/system-release)"
GRUB_DEFAULT=saved
GRUB_DISABLE_SUBMENU=true
GRUB_TERMINAL_OUTPUT="console"
GRUB_CMDLINE_LINUX="crashkernel=auto rd.lvm.lv=rhel/root rd.lvm.lv=rhel/swap rhgb quiet isolcpus=1,2,3"
GRUB_DISABLE_RECOVERY="true"
```


### How to use cgroup
Ref: https://www.lesbonscomptes.com/recoll/faqsandhowtos/cgroups_instructions.html












