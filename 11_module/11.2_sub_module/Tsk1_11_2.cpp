//
// Created by NandanRaj on 06-05-2026.
//
#include<iostream>

int main(int argc, char *argv[]) {
    int * ptr= nullptr;
    *ptr=10;// Deliberate null pointer dereference
    return 0;
}

/*
*PS C:\Users\NandanRaj\OneDrive - EPAM\CPP_LearnPath_codes\Modules_EPAM\11_module\11.2_sub_module> g++ -g -o Tsk1_11_2 Tsk1_11_2.cpp
PS C:\Users\NandanRaj\OneDrive - EPAM\CPP_LearnPath_codes\Modules_EPAM\11_module\11.2_sub_module> ./Tsk1_11_2
PS C:\Users\NandanRaj\OneDrive - EPAM\CPP_LearnPath_codes\Modules_EPAM\11_module\11.2_sub_module> gdb ./Tsk1_11_2

GNU gdb (GDB for MinGW-W64 x86_64, built by Brecht Sanders, r1) 16.3
Copyright (C) 2024 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-w64-mingw32".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<https://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
< q to quit, c to continue without paging--c
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from ./Tsk1_11_2...

(gdb) run
Starting program: C:\Users\NandanRaj\OneDrive - EPAM\CPP_LearnPath_codes\Modules_EPAM\11_module\11.2_sub_module\Tsk1_11_2.exe
[New Thread 40412.0x1e44]
[New Thread 40412.0xa53c]
[New Thread 40412.0x9d28]

Thread 1 received signal SIGSEGV, Segmentation fault.
0x00007ff67ef11730 in main (argc=1, argv=0x6b1620)
    at Tsk1_11_2.cpp:8
8           *ptr=10;// Deliberate null pointer dereference

(gdb) bt
#0  0x00007ff67ef11730 in main (argc=1, argv=0x6b1620)
    at Tsk1_11_2.cpp:8

(gdb) 1
Undefined command: "1".  Try "help".
(gdb) l
3       //
4       #include<iostream>
5
6       int main(int argc, char *argv[]) {
7           int * ptr= nullptr;
8           *ptr=10;// Deliberate null pointer dereference
9           return 0;
10      }
11
 */

