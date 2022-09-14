#include <stdio.h>
#include <ctype.h>

// El programa repite tantas veces como lo indique el número antecesor al caracter.

void main(void)
{
    char string[50];
    int i = 0, rep, j;

    printf("Digite la cadena que debe constar de un número seguido de un caracter, (repita ese patrón tantas veces como desee): ");
    gets(string);

    while (string[i] != '\0')
    {
        if (isdigit(string[i]))
        {
            rep = string[i] - 48;
            i++;
            for (j = 0; j < rep; j++)
                putchar(string[i]);
            i++;
        }
    }
}