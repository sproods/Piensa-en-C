#include <stdio.h>

/* Calentamiento luego de un largo descanso. */

void main(void)
{
    int i;
    char a, b;

    printf("Digite un caracter de su elección: ");
    a = getchar();
    fflush(stdin);

    printf("Digite otro caracter de su elección: ");
    scanf("%c", &b);
    fflush(stdin);

    for(i = 0; i < 7; i++)
    {
        putchar(a);
    }
}