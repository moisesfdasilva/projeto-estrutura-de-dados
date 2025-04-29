#include <stdio.h>
#include <stdlib.h>

void troca(float valueA, float valueB) {
    float valueC = valueA;
    valueA = valueB;
    valueB = valueC;

    printf("value a=%.2f\n", valueA);
    printf("value b=%.2f\n", valueB);
}

int main(void) {
    troca(10.5, 7.7);

    return 0;
}
