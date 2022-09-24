#include <stdio.h>
#include <string.h>

// Combinación de palabras entre dos cadenas de caracteres.

void main(void)
{
    char texto1[50], texto2[50];
    int i = 0, j = 0;

    printf("Digite la primera cadena de caracteres: ");
    gets(texto1);
    fflush(stdin);

    printf("Digite la segunda cadena de caracteres: ");
    gets(texto2);
    fflush(stdin);

    printf("\n");

    while (texto1[i] != '\0' || texto2[j] != '\0')
    {
        while ((texto1[i] != ' ') && (texto1[i] != '\0'))
        {
            putchar(texto1[i]);
            i++;
        }
        fflush(stdin);

        printf(" ");

        while ((texto2[j] != ' ') && (texto2[j] != '\0'))
        {
            putchar(texto2[j]);
            j++;
        }
        fflush(stdin);

        printf(" ");

        i++;
        j++;
    }

    printf("\n");
}