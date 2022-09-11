#include <stdio.h>
#include <string.h>

// EStudio de la función strchr de la librería <string.h>

void main(void)
{
    char cadena[50], *A, caracter;

    printf("Digite una cadena de texto: ");
    gets(cadena);

    A = strchr(cadena, 'm');
    caracter = *A;

    printf("La posición de la letra 'm', en la cadena de texto, es de %c.\n", caracter);
}