#include <stdio.h>

// Impresión de caracteres pares de una cadena de caracteres dada.

void main(void)
{
    char string[100];
    int i = 1;

    printf("Digite una cadena de caracteres de su elección: ");
    gets(string);

    printf("\n");

    while(string[i] != '\0')
    {
        putchar(string[i]);
        i += 2;
    }

    printf("\n");
}