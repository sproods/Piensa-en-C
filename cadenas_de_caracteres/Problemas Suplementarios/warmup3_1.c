#include <stdio.h>

// Suplemento de los calentamientos.

void main(void)
{
    char A, *phrase;
    int i = 0;
    
    printf("Escriba su frase inspiradora de esta mañana: ");
    while((A = getchar()) != '\n')
        phrase[i++] = A;
    phrase[i] = '\0';

    printf("\n");
    puts(phrase);
    printf("\n");

    i = 0;
    while(phrase[i] != ' ')
        putchar(phrase[i++]);
}