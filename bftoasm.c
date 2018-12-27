#include <stdio.h>

char start[] =
  "segment .bss\n"
  "mem resb 0x1000\n"
  "segment .text\n"
  "global _start\n"
  "_start:\n"
  "mov rsi, mem\n"
  "mov rdx, 1";

char in[] =
  "mov rax, 0\n"
  "mov rdi, 0\n"
  "syscall";

char out[] =
  "mov rax, 1\n"
  "mov rdi, 1\n"
  "syscall";

char finish[] =
  "mov rax, 60\n"
  "mov rdi, 0\n"
  "syscall";


int main (void)
{
  puts (start);

  char ch;
  int l_[0x1000],
      *p = l_,
      l = 0;
  while ((ch = getchar()) != EOF) {
    switch (ch) {
      case '<': puts ("dec rsi"); break;
      case '>': puts ("inc rsi"); break;
      case '-': puts ("dec byte [rsi]"); break;
      case '+': puts ("inc byte [rsi]"); break;
      case ',': puts (in); break;
      case '.': puts (out); break;
      case '[': printf (".L%d:\n", *p++ = l++); break;
      case ']': printf ("cmp byte [rsi], 0\n"
                        "jnz .L%d\n", *--p); break;
    }
  }

  puts (finish);
}
