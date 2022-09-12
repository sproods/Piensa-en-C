#include <stdio.h>

/* Calentamiento luego de un largo descanso. */

void main(void)
{
    int i, j, n;
    char a, b;

    printf("Digite el tamaño de la figura: ");
    scanf("%d", &n);
    fflush(stdin);

    printf("Digite un caracter de su elección: ");
    a = getchar();
    fflush(stdin);

    printf("Digite otro caracter de su elección: ");
    scanf("%c", &b);
    fflush(stdin);

    for(i = 0; i <= n; i++)
    {
        for(j = i; j < n; j++)
        {
            printf("%c", a);
        }
        
        for(j = 0; j < i; j++)
            putchar(b);
        printf("\n");
    }
}