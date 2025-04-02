#include <stdio.h>

int main(void)
{
    int m1[3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    int m2[3][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }};
    int m3[3][4] = { { 1, 2, 3 }, { 4, 5 }, { 6, 7, 8, 9 } };

    int i, j;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 4; j++) {
            printf("m1[%d] [%d] = %2d  ", i, j, m1[i][j]);
            printf("m2[%d] [%d] = %2d  ", i, j, m2[i][j]);
            printf("m3[%d] [%d] = %2d\n", i, j, m3[i][j]);
        }
    return 0;
}
