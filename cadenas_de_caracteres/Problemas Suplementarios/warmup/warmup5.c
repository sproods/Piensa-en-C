#include <stdio.h>

// Contador de cadenas de caracteres.

void main(void)
{
    int i;
    char letter;

    printf("Escriba la frase de su elección: ");

    i = 0;

    while((letter = getchar()) != '\n')
        i++;

    printf("El número de letras de la frase es %d.\n", i);
}