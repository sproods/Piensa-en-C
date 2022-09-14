#include <stdio.h>

// Contador de palabras.

void main(void)
{
    char string[100];
    int i = 0, words = 0;

    printf("Digite una cadena de caracteres: ");
    gets(string);

    while (string[i] != '\0')
    {
        if (string[i] == ' ')
            words++;

        i++;
    }

    printf("El texto \"%s\" contiene %d palabras.", string, words + 1);
}