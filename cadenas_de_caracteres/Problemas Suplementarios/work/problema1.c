#include <stdio.h>

// El programa imprime solo los caracteres impares de la cadena de caracteres digitada.

void main(void)
{
    char string[100];
    int i = 0;

    printf("Digite una cadena de caracteres: ");
    gets(string);
    fflush(stdin);

    printf("\n");

    while (string[i] != '\0')
    {
        putchar(string[i]);
        i += 2;
    }
    
    printf("\n");
}