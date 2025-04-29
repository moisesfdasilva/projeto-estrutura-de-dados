#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int a = 20, b = 50, *m, *n;
    m = &a;

    printf("value = %d\n", *m);

    n = m;
    n = &b;

    printf("value = %d\n", *m);

    return 0;
}
