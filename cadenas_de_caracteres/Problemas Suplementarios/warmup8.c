#include <stdio.h>
#include <string.h>

// Estudio de las principales funciones de la biblioteca <string.h>

void main(void)
{
    char *texto = "La Luna, la Tierra y el Sol", cadena[50];
    
    printf("Primera cadena de texto: %s\n\n", texto);

    strcpy(cadena, texto);
    printf("La cadena copia del primer texto es: %s\n\n", cadena);

    strcpy(cadena, "Linus Torvals");
    printf("La siguiente copia es: %s", cadena);
}