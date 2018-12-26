./bftoasm <$1.bf >$1.asm
nasm -felf64 $1.asm
ld -o $1 $1.o
stty -icanon
stty -echo
./$1
stty echo
stty icanon
