#include <stdio.h>

int main(void)
{
    char str1[12] = {'L', 'i', 'n', 'g', 'u', 'a', 'g', 'e', 'm', ' ', 'C', '\0'};
    //char str1[14] = {'L', 'i', 'n', 'g', 'u', 'a', 'g', 'e', 'm', ' ', 'C', '\0'};
    char str2[12] = "Linguagem C";
    char str3[2][12] = {"Linguagem C", "Muito boa"};

    printf("%s \n", str1);
    printf("%s \n", str2);
    printf("%s \n", str3);

    //printf("%c \n", str1[13]);

    return 0;
}
