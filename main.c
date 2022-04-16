#include <stdio.h>

int *replace(int *v, int n, int x, int y){
  asm (".intel_syntax noprefix    \n\
        mov edx, edi              \n\
    ini:                          \n\
        jecxz fim                 \n\
        cmp eax, [edi]            \n\
        je achou                  \n\
        lea edi, [edi + 4]        \n\
        dec ecx                   \n\
        jmp ini                   \n\
    achou:                        \n\
        mov [edi], ebx            \n\
        jmp ini                   \n\
    fim:                          \n\
        mov eax, edx              \n\
        .att_syntax prefix        \n"
        :
        : "D" (v), "c" (n), "a" (x), "b" (y)
        :
    );
}

int main()
{
  int i, *z, n = 5;
  int v[] = {1, 2, 2, 4, 2};
  z = replace(v, n, 2, 7);
  for(i = 0; i < n; i++) printf("%d ", v[i]);
  return 0;
}
