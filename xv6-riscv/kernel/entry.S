        # qemu -kernel loads the kernel at 0x80000000
        # and causes each hart (i.e. CPU) to jump there.
        # kernel.ld causes the following code to
        # be placed at 0x80000000.
.section .text
.global _entry
_entry:
        # set up a stack for C.
        # stack0 is declared in start.c,
        # with a 4096-byte stack per CPU.
        # sp = stack0 + (hartid * 4096) 每个cpu都有一个内核栈空间，大小为4k
        la sp, stack0  # stack0 地址加载到堆栈指针
        li a0, 1024*4 # 将立即数 4k 加载到a0
        csrr a1, mhartid # 读取控制状态寄存器 读取内核的 0-7
        addi a1, a1, 1 # 1-8
        mul a0, a0, a1 # a0 = a0 * a1  a0 = 4k * 处理器个数
        add sp, sp, a0 # stack point 到最顶端
        # jump to start() in start.c
        call start
spin:
        j spin
