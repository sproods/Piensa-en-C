#include <stdio.h>
#include <stdlib.h>

// Estudio de las principales funciones de la libreria <stdlib.h>

void main(void)
{
    double A;
    char cadena_1[50], *cadena;

    printf("Escriba el texto de su preferencia: ");
    gets(cadena_1);

    A = strtod(cadena_1, &cadena);

    printf("\nEl valor del caracter es %s\nmientras que el valor real del texto es %.3lf\n", cadena_1, A + 12);
    puts(cadena);

    printf("Digite otra cadena de caracteres: ");
    gets(cadena);
    puts(cadena);
}