# bftoasm
low-level brainfuck compiler

Type `$ gcc -o bftoasm bftoasm.c` to build.

Type `$ ./bftoasm.sh prog` to compile and run "prog.bf".

The script converts brainfuck code from file "prog.bf" to assembly, saves the result in "prog.asm", assembles it with nasm and links with ld, disables per-line buffering and echoing of input in terminal, runs the executable "prog" and restores normal tty settings when terminated.

"prog" stands for whichever name you specify in first parameter after `./bftoasm.sh`
