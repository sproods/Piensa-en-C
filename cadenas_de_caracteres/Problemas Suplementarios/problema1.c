#include <stdio.h>

/* Calentamiento luego de un largo descanso. */

void main(void)
{
    int i, j;
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
        for(j = 0; j < 3; j++)
            printf("%c", b);
        printf("\n");
    }
}