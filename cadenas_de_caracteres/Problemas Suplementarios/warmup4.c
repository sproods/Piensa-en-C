#include <stdio.h>
#include <ctype.h>

// Entendiendo el manejo de memoria de los caracteres en C.

void main(void)
{
    char letter;

    printf("Escriba, por favor, una frase de su elección: ");

    while((letter = getchar()) != '\n')
    {
        if(letter != ' ')
            putchar(toupper(letter));
        else
            printf("\n");
    }

    printf("\n");
}