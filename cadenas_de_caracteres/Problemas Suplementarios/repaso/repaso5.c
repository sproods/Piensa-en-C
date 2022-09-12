#include <stdio.h>

// Determinación de la longitud de una cadena de caracteres sin utilizar la función strlen.

void main(void)
{
    char string[70];
    int i = 0;

    printf("Digite la cadena de caracteres de su preferencia: ");
    gets(string);

    while (string[i] != '\0')
        i++;

    printf("\nLa longitud de la cadena de caracteres digitada es de %d letras\n", i);
}