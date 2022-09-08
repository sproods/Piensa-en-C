#include <stdio.h>
#include <stdlib.h>

// Estudio de las principales funciones de la libreria <stdlib.h>

void main(void)
{
    int A, sum;
    char texto[50];

    printf("Digite un texto: ");
    gets(texto);

    A = atoi(texto);
    printf("El valor entero del texto es: %d.", A);

    sum = 8 + A;
    printf("\nLa suma es: %d", sum);
}