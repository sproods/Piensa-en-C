#include <stdio.h>
#include <string.h>

// Continución del estudio de las principales funciones de la librería <string.h>

void main(void)
{
    char cadena[50], string[50], *cadena1 = "Los caballos son las piezas más versátiles del tablero.";

    printf("Digite el texto de su conveniencia: ");
    gets(cadena);
    fflush(stdin);

    printf("Digite una palabra que desea hallar en la primera cadena digitada: ");
    gets(string);
    fflush(stdin);

    cadena1 = strstr(cadena1, string);

    puts(cadena1);
}