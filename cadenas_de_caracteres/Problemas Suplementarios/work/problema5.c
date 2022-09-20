#include <stdio.h>
#include <ctype.h>

// Mayusculización de primeros caractres de cada palabra de una cadena de caracteres.

void main(void)
{
    char texto[50];
    int i = 0;

    printf("Digite una cadena de caracteres: ");
    gets(texto);

    while (texto[i] != '\0')
    {
        if (isalpha(texto[0]))
        {
            texto[0] = toupper(texto[0]);
        }

        if (texto[i] == ' ')
        {
            texto[i + 1] = toupper(texto[i + 1]);
        }

        i++;
    }

    printf("\n");
    puts(texto);
}