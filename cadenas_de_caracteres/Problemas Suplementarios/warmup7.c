#include <stdio.h>
#include <stdlib.h>

// Estudio de las principales funciones de la libreria <stdlib.h>

void main(void)
{
    long A, B;
    char cadena1[50], *cadena;

    printf("Digite una cadena de texto: ");
    gets(cadena1);

    A = atol(cadena1);

    printf("El valor de la cadena de caracteres ingresada es %s\nEl valor entero de la cadena es %ld\n\n", cadena1, A);

    printf("Digite otra cadena de texto: ");
    gets(cadena1);

    B = strtol(cadena1, &cadena, 0);

    printf("El valor de la cadena digitada es %s\nEl valor entero de la cadena es %ld\n\n", cadena1, B);
    puts(cadena);
}