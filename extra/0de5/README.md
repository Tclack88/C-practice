# 0DE5 exercises
from [0de5.net](https://www.0de5.net/explore)
## Chapter 1 - memory and instructions
1. Introducing 0de5 

Welcome.c

Task: Write a C program that takes input. If input is "Q", then access is granted.

Open the compiled code and make it work for any input

code compiled using `gcc -O0 -g -o welcome welcome.c` (`-O` sets optimization level. I have it set to zero so that everything written gets more or less translated directly to the corresponding assembly).

looking at the compiled code using `objdump -d welcome`, we can see the instructions. Here's the assembly for main:

```
00000000000011a9 <main>:
    11a9:       f3 0f 1e fa             endbr64
    11ad:       55                      push   %rbp
    11ae:       48 89 e5                mov    %rsp,%rbp
    11b1:       48 83 ec 10             sub    $0x10,%rsp
    11b5:       64 48 8b 04 25 28 00    mov    %fs:0x28,%rax
    11bc:       00 00
    11be:       48 89 45 f8             mov    %rax,-0x8(%rbp)
    11c2:       31 c0                   xor    %eax,%eax
    11c4:       48 8d 05 3d 0e 00 00    lea    0xe3d(%rip),%rax        # 2008 <_IO_stdin_used+0x8>
    11cb:       48 89 c7                mov    %rax,%rdi
    11ce:       b8 00 00 00 00          mov    $0x0,%eax
    11d3:       e8 c8 fe ff ff          call   10a0 <printf@plt>
    11d8:       48 8d 45 f7             lea    -0x9(%rbp),%rax
    11dc:       48 89 c6                mov    %rax,%rsi
    11df:       48 8d 05 44 0e 00 00    lea    0xe44(%rip),%rax        # 202a <_IO_stdin_used+0x2a>
    11e6:       48 89 c7                mov    %rax,%rdi
    11e9:       b8 00 00 00 00          mov    $0x0,%eax
    11ee:       e8 bd fe ff ff          call   10b0 <__isoc99_scanf@plt>
    11f3:       0f b6 45 f7             movzbl -0x9(%rbp),%eax
    11f7:       3c 51                   cmp    $0x51,%al
    11f9:       75 0f                   jne    120a <main+0x61>
    11fb:       48 8d 05 2b 0e 00 00    lea    0xe2b(%rip),%rax        # 202d <_IO_stdin_used+0x2d>
    1202:       48 89 c7                mov    %rax,%rdi
    1205:       e8 76 fe ff ff          call   1080 <puts@plt>
    120a:       b8 00 00 00 00          mov    $0x0,%eax
    120f:       48 8b 55 f8             mov    -0x8(%rbp),%rdx
    1213:       64 48 2b 14 25 28 00    sub    %fs:0x28,%rdx
    121a:       00 00
    121c:       74 05                   je     1223 <main+0x7a>
    121e:       e8 6d fe ff ff          call   1090 <__stack_chk_fail@plt>
    1223:       c9                      leave
    1224:       c3                      ret
```

The relevant part is really just

`11f9:       75 0f                   jne    120a <main+0x61>`

a jump if not equal to a different address to continue instructions. What's equal? The previous instruction is sucessful (checking correct password. If they match, cmp returns 0.). `jne` in binary for x86 assembly is given by `75 0f`. We can actually change this to `74 0f` to make the instruction `je` (jump if equal). Which means a (likely) incorrect password will jump to the command specified (which just exits). Alternatively, we can just ignore this command by using `NOP` (no operation) which is given by hex code `90`. Regardless of the path. A classic/old school way to change this can be opening xxd through vim.

When in vim, everything looks like nonsense. But when we use `:%!xxd` (`:` starts command-line mode, `%` matches the whole file as a range, `!` begins executing the external command that follows which in this case is `xxd`). We can find the `75 0f` in this document, and change the `75 0f` to whichever, `90 90` is better because it works with all input. It's important to note that everything replaced must match in size, I couldn't for instance change `75 0f`/`jne` command to `48 8d 05 XX XX XX XX`/`lea` (load effective address at XX XX XX XX) because the extra 20 bytes.

After editing everything, using `:%!xxd -r` to "revert" the hexdump back to binary and save the document gives us the new, working binary. Checking again, the relevant part of the binary becomes:

```
00000000000011a9 <main>:
    11a9:       f3 0f 1e fa             endbr64
    11ad:       55                      push   %rbp
    11ae:       48 89 e5                mov    %rsp,%rbp
    11b1:       48 83 ec 10             sub    $0x10,%rsp
    11b5:       64 48 8b 04 25 28 00    mov    %fs:0x28,%rax
	.
	.
	.
    11f7:       3c 51                   cmp    $0x51,%al
    11f9:       90                      nop
    11fa:       90                      nop
    11fb:       48 8d 05 2b 0e 00 00    lea    0xe2b(%rip),%rax        # 202d <_IO_stdin_used+0x2d>
    1202:       48 89 c7                mov    %rax,%rdi
	.
	.
	.
    1223:       c9                      leave
    1224:       c3                      ret
```

What a cool (and super beginner level) exploit!
