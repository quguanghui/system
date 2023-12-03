# Initial process that execs /init.
# This code runs in user space.

#include "syscall.h"

# exec(init, argv)
.globl start
start:
        la a0, init # 把 init 的字符串送入到a0 寄存器
        la a1, argv # 把 argv数据送入a1
        li a7, SYS_exec # 调用sys_exec
        ecall

# for(;;) exit();
exit:
        li a7, SYS_exit # 如果有返回的话，调用exit 系统调用
        ecall
        jal exit

# char init[] = "/init\0";
init:
  .string "/init\0"

# char *argv[] = { init, 0 };
.p2align 2
argv:
  .long init
  .long 0
