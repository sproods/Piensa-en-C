#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main(void)
{
    char cad[30], *str, *str2, num1[4], num2[4];
    int i, a, b;

    printf("Digite una cadena de caracteres: ");
    gets(cad);
    fflush(stdin);

    str = strstr(cad, "/");
    str2 = strstr(str + 1, "/");

    for (i = 1; i < 3; i++)
    {
        num1[i - 1] = str[i];
        num2[i - 1] = str2[i];
    }

    a = atoi(num1);
    b = atoi(num2);

    printf("la suma de num1: %s + %s es %d", num1, num2, a + b);
}