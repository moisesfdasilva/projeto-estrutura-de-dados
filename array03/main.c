#include <stdio.h>

int main(void)
{
    int v[7] = { 16, 22, 23, 1, 14, 29, 18 };
    int soma, i;
    soma = 0;

    for( i = 0; i < 7; i++)
        soma = soma + v[i];

    printf("Soma: %d\n", soma);

    return 0;
}
