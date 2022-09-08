#include <stdio.h>
#include <stdlib.h>

// Estudio de las principales funciones de la libreria <stdlib.h>

void main(void)
{
    double A, sum;
    char texto[50];

    printf("Digite un texto: ");
    gets(texto);

    A = atof(texto);
    printf("El valor double del texto es: %.3f.", A);

    sum = 8.245 + A;
    printf("\nLa suma es: %.3f", sum);
}