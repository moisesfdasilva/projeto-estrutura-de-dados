#include <stdio.h>

int main(void)
{
    int v[7] = { 16, 22, 23, 1, 14, 29, 18 };
    int maior, i;
    maior = v[0];

    for (i = 1; i < 7; i++)
        if (maior < v[i])
            maior = v[i];

    printf("Maior: %d\n", maior);

    return 0;
}
